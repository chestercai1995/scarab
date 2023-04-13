/* Copyright 2020 HPS/SAFARI Research Groups
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "ffp_mul_tage.h"

#include <iostream>
#include <unordered_map>
#include <memory>

#include "libs/cache_lib/cache.h"
extern "C" {
#include "bp.param.h"
#include "core.param.h"
#include "globals/assert.h"
#include "table_info.h"
}

#include "bp/template_lib/tagescl.h"

#define DEBUG(proc_id, args...) _DEBUG(proc_id, DEBUG_BP_DIR, ##args)

namespace {

struct l0_btb_entry {
    Addr pc;
    Addr target;
    int counter;
    Flag insert_by_ft; //only set to true when inserting from ft. unset if a regular update touches it
    Flag used;
};

struct delay_queue_entry{
  Flag future_tage_pred0;
  Flag future_tage_pred1;
  int64_t branch_id;
  uint64_t insert_cycle;
  Flag current_pred;
};

struct blacklist_entry{
  uint32_t counter;
};

struct Gshare_State {
  std::vector<uns8> pht;
};

std::vector<Gshare_State> gshare_state_all_cores;

uns32 get_pht_index(const Addr addr, const uns32 hist) {
  const uns32 cooked_hist = hist >> (32 - HIST_LENGTH);
  const uns32 cooked_addr = (addr >> 2) & N_BIT_MASK(HIST_LENGTH);
  return cooked_hist ^ cooked_addr;
}

int64_t last_full_bp_flush_id;
int64_t last_late_bp_flush_id;

std::vector<Cache_cpp<l0_btb_entry>> l0_across_all_cores;
// A vector of TAGE-SC-L tables. One table per core.
std::vector<std::unique_ptr<Tage_SC_L_Base>> future_tages0;
std::vector<std::unique_ptr<Tage_SC_L_Base>> future_tages1;

std::deque<delay_queue_entry> future_tage_response_delay_queue;

std::unordered_map<Addr, blacklist_entry> ffp_blacklist;
// Helper function for producing a Branch_Type struct.
Branch_Type get_branch_type(uns proc_id, Cf_Type cf_type) {
  Branch_Type br_type;
  switch(cf_type) {
    case CF_BR:
    case CF_CALL:
      br_type.is_conditional = false;
      br_type.is_indirect    = false;
      break;
    case CF_CBR:
      br_type.is_conditional = true;
      br_type.is_indirect    = false;
      break;
    case CF_IBR:
    case CF_ICALL:
    case CF_ICO:
    case CF_RET:
    case CF_SYS:
      br_type.is_conditional = false;
      br_type.is_indirect    = true;
      break;
    default:
      // Should never see non-control flow instructions or invalid CF
      // types in the branch predictor.
      ASSERT(proc_id, false);
      break;
  }
  return br_type;
}
uns get_recent_hist_hash(){
  uns res = 0;
  uns j = 0;
  for(int i = (int)future_tage_response_delay_queue.size() - 1; i >= 0; i--){
    if(j == STALE_HISTORY_DISTANCE){
      break;
    }
    j++;
    //printf("%u:%ld, ", future_tage_response_delay_queue[i].current_pred, future_tage_response_delay_queue[i].branch_id);
    res = res ^ future_tage_response_delay_queue[i].current_pred;
  }
  //printf("\nres is %u\n", res);
  return res;
}
uns get_recent_hist_hash_at_update(){
  uns res = 0;
  uns j = 0;
  for(unsigned int i = 0; i < future_tage_response_delay_queue.size(); i++){
    if(j == STALE_HISTORY_DISTANCE){
      break;
    }
    j++;
    //printf("%u:%ld, ", future_tage_response_delay_queue[i].current_pred, future_tage_response_delay_queue[i].branch_id);
    res = res ^ future_tage_response_delay_queue[i].current_pred;
  }
  //printf("\nres is %u\n", res);
  return res;
}
}  // end of anonymous namespace

void bp_ffp_mul_tage_init() {
  if(future_tages0.size() == 0) {
    future_tages0.reserve(NUM_CORES);
    future_tages1.reserve(NUM_CORES);
    for(uns i = 0; i < NUM_CORES; ++i) {
      if(FUTURE_TAGE_SIZE_KB == 641){
        future_tages0.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
        future_tages1.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      }
      else if (FUTURE_TAGE_SIZE_KB == 642) {
        future_tages0.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V2>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
        future_tages1.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V2>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      }
      else if (FUTURE_TAGE_SIZE_KB == 643) {
        future_tages0.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V3>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
        future_tages1.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V3>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      }
      else if (FUTURE_TAGE_SIZE_KB == 644) {
        future_tages0.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V4>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
        future_tages1.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V4>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      }
      else if (FUTURE_TAGE_SIZE_KB == 645) {
        future_tages0.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V5>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
        future_tages1.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_32KB_V5>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      }
      else{
        ASSERT(0, FALSE);
      }
      l0_across_all_cores.push_back(Cache_cpp<l0_btb_entry>("l0_btb", L0_BTB_SIZE, L0_BTB_ASSOC, 1, SRRIP_REPL));
    }
  }
  gshare_state_all_cores.resize(NUM_CORES);
  for(auto& gshare_state : gshare_state_all_cores) {
    gshare_state.pht.resize(1 << HIST_LENGTH, PHT_INIT_VALUE);
  }
  ASSERT(0, BP_UPDATE_AT_RETIRE);
  ASSERT(0, STALE_HISTORY_DISTANCE != 0);
  ASSERTM(0, future_tages0.size() == NUM_CORES,
          "future_tages not initialized correctly");
  ASSERTM(0, future_tages1.size() == NUM_CORES,
          "future_tages not initialized correctly");
}

void bp_ffp_mul_tage_timestamp(Op* op) { 
  uns proc_id = op->proc_id;
  int64_t old_id = future_tages0.at(proc_id)->get_old_branch_id(STALE_HISTORY_DISTANCE);
  int64_t new_id = future_tages0.at(proc_id)->get_new_branch_id(op->off_path);
  int64_t old_id_v1 = future_tages1.at(proc_id)->get_old_branch_id(STALE_HISTORY_DISTANCE);
  int64_t new_id_v1 = future_tages1.at(proc_id)->get_new_branch_id(op->off_path);
  ASSERT(0, old_id == old_id_v1);
  ASSERT(0, new_id == new_id_v1);
  op->recovery_info.future_tage_branch_id = new_id;
  op->recovery_info.future_tage_update_id = old_id;
  //fprintf(stderr, "timestamp, br received id %lu, update id %lu\n", new_id, old_id);
}

uns8 bp_ffp_mul_tage_pred(Op* op) {
  uns proc_id = op->proc_id;

  //printf("computing hash at pred for op %llu, br_id %lld: ", op->op_num, op->recovery_info.future_tage_branch_id);
  uns fft_picker = get_recent_hist_hash();
  op->ffp_recent_hist_hash = fft_picker;

  DEBUG(proc_id, "Predicting for op_num:%s addr:%s, p_dir:%d, t_dir:%d\n",
        unsstr64(op->op_num), hexstr64s(pc), hit, op->oracle_info.dir);


  Flag future_tage_res0 = future_tages0.at(proc_id)->get_prediction(
    op->recovery_info.future_tage_branch_id, op->inst_info->addr);
  Flag future_tage_res1 = future_tages1.at(proc_id)->get_prediction(
    op->recovery_info.future_tage_branch_id, op->inst_info->addr);
  
  DEBUG(op->proc_id, "future tage on op %llu, pc is %lx, pred is %d\n", op->op_num, future_tage_res.pc, future_tage_res.pred);

  delay_queue_entry temp_entry;
  temp_entry.future_tage_pred0 = future_tage_res0;
  temp_entry.future_tage_pred1 = future_tage_res1;
  temp_entry.insert_cycle = cycle_count;
  temp_entry.branch_id = op->recovery_info.future_tage_branch_id;

  future_tage_response_delay_queue.push_back(temp_entry);
  //fprintf(stderr, "pushing id %lld\n", op->recovery_info.future_tage_branch_id);
  //if(!op->off_path){
  //  printf("PUSH: currently at %llx, pred pc %lx, dir: %d, current id %lld\n", op->inst_info->addr, temp_entry.future_tage_pred.pc, temp_entry.future_tage_pred.pred, op->recovery_info.future_tage_branch_id);
  //}

  auto&       l0_btb      = l0_across_all_cores.at(op->proc_id);

  Addr        pc          = op->inst_info->addr;
  Cache_access_result<l0_btb_entry> res = l0_btb.probe(op->proc_id, pc);
  Flag hit = res.hit;
  Flag counter_taken = res.data.counter>1;
  Flag btb_prediction = USE_2_BIT_COUNTER_IN_L0 ? hit : hit && counter_taken;
  //if(!op->off_path){
  //  printf("L0BTB: pc %llx id %lld, pred is %d, true_dir %d\n", op->inst_info->addr, op->recovery_info.future_tage_branch_id, btb_prediction, op->oracle_info.dir);
  //}

  const auto& gshare_state = gshare_state_all_cores.at(proc_id);

  const Addr  addr      = op->oracle_info.pred_addr;
  const uns32 hist      = op->oracle_info.pred_global_hist;
  const uns32 pht_index = get_pht_index(addr, hist);
  const uns8  pht_entry = gshare_state.pht[pht_index];
  const uns8  gshare_pred = pht_entry >> (PHT_CTR_BITS - 1) & 0x1;

  DEBUG(proc_id, "Predicting with gshare for  op_num:%s  index:%d\n",
        unsstr64(op->op_num), pht_index);
  DEBUG(proc_id, "Predicting  addr:%s  pht:%u  pred:%d  dir:%d\n",
        hexstr64s(addr), pht_index, gshare_pred, op->oracle_info.dir);
  if(hit){
    if(op->table_info->cf_type == CF_BR || op->table_info->cf_type == CF_CALL){
      //if hit on btb, then take unconditional branches
      //no need to deal with indirects here, because that's being taken care of in bp.c
      return true;
    }
  }
  else{
    return false;
  }
  if(FFP_ENABLE_GSHARE_BASE){
    return gshare_pred;
  }


  Flag found_it = FALSE;

  for(auto& element : future_tage_response_delay_queue){
    if(element.branch_id == op->recovery_info.future_tage_update_id){
      found_it = true;
      Flag fft_final_pred =  fft_picker ? element.future_tage_pred1 : element.future_tage_pred0;
      if(cycle_count - element.insert_cycle >= FUTURE_TAGE_LATENCY){
        if(!op->off_path){
          if(fft_final_pred == op->oracle_info.dir){
            //correct pred
            INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_EXACTLY_RIGHT, 1);  
          }
          else{
            //wrong pred
            INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_EXACTLY_DIR_WRONG, 1);  
            if(op->recovery_info.future_tage_update_id != -1){
              if(op->recovery_info.future_tage_update_id <= last_full_bp_flush_id){
                INC_STAT_EVENT(op->proc_id, FFP_WRONG_UNDER_FULL_BP_FLUSH, 1);  
              }
              else if(op->recovery_info.future_tage_update_id <= last_late_bp_flush_id){
                INC_STAT_EVENT(op->proc_id, FFP_WRONG_UNDER_LATE_BP_FLUSH, 1);  
              }
            }
          }
        }
        return fft_final_pred;
      }
      else{
        //late
        INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_LATE, 1);  
      }
      break;
    }
  }  
  if(op->recovery_info.future_tage_update_id != -1){
    ASSERT(0, found_it);
  }
  return btb_prediction;
}

void bp_ffp_mul_tage_spec_update(Op* op) {
  uns proc_id = op->proc_id;
  
  future_tages0.at(proc_id)->update_speculative_state(
    op->recovery_info.branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.pred,
    op->oracle_info.target);
  future_tages1.at(proc_id)->update_speculative_state(
    op->recovery_info.branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.pred,
    op->oracle_info.target);
  if(future_tage_response_delay_queue.back().branch_id != op->recovery_info.future_tage_branch_id){
    printf("current id %lld, back of q id %ld, q has: ", op->recovery_info.future_tage_branch_id, future_tage_response_delay_queue.back().branch_id);
    for(auto& element : future_tage_response_delay_queue){
      printf("%ld, ", element.branch_id); 
    }
    printf("\n");
  }
  ASSERT(0, future_tage_response_delay_queue.back().branch_id == op->recovery_info.future_tage_branch_id);
  future_tage_response_delay_queue.back().current_pred = op->oracle_info.pred;
}

void bp_ffp_mul_tage_update(Op* op) {
  const uns   proc_id      = op->proc_id;
  auto cf_type = op->table_info->cf_type;
  ASSERT(0, !op->off_path);
  if(cf_type == CF_CBR){
    if(op->recovery_info.future_tage_update_id != -1){
      //printf("computing hash at update for op %llu, br_id %lld: ", op->op_num, op->recovery_info.future_tage_branch_id);
      ASSERT(0, get_recent_hist_hash_at_update() == op->ffp_recent_hist_hash);
      if(op->ffp_recent_hist_hash == 0){
        future_tages0.at(proc_id)->commit_state(
          op->recovery_info.future_tage_update_id, op->inst_info->addr,
          get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir, op->off_path);
          INC_STAT_EVENT(op->proc_id, FFP_HASH_DIST0, 1);  
      }
      else{
        future_tages1.at(proc_id)->commit_state(
          op->recovery_info.future_tage_update_id, op->inst_info->addr,
          get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir, op->off_path);
          INC_STAT_EVENT(op->proc_id, FFP_HASH_DIST1, 1);  
      }
    }

    auto&       gshare_state = gshare_state_all_cores.at(proc_id);
    const Addr  addr         = op->oracle_info.pred_addr;
    const uns32 hist         = op->oracle_info.pred_global_hist;
    const uns32 pht_index    = get_pht_index(addr, hist);
    const uns8  pht_entry    = gshare_state.pht[pht_index];

    DEBUG(proc_id, "Writing gshare PHT for  op_num:%s  index:%d  dir:%d\n",
          unsstr64(op->op_num), pht_index, op->oracle_info.dir);

    if(op->oracle_info.dir) {
      gshare_state.pht[pht_index] = SAT_INC(pht_entry, N_BIT_MASK(PHT_CTR_BITS));
    } else {
      gshare_state.pht[pht_index] = SAT_DEC(pht_entry, 0);
    }

    DEBUG(proc_id, "Updating addr:%s  pht:%u  ent:%u  dir:%d\n", hexstr64s(addr),
          pht_index, gshare_state.pht[pht_index], op->oracle_info.dir);
  }

  if(cf_type != CF_CBR && cf_type != CF_BR && cf_type != CF_CALL) {
    //only deal with direct branches, maybe can remove call later as well
    return;
  }

  auto&       l0_btb       = l0_across_all_cores.at(proc_id);
  const Addr  pc           = op->inst_info->addr;


  if(op->oracle_info.dir) {
    auto access_res = l0_btb.access(proc_id, pc);
    if(!access_res.hit){
        l0_btb_entry new_entry = {pc, op->oracle_info.target, 2, false, false};
        #if ENABLE_GLOBAL_DEBUG_PRINT
        auto insert_res = l0_btb.insert(proc_id, pc, /*is_prefetch =*/ FALSE, new_entry);
        DEBUG(proc_id, "write l0btb op %llu, pc=x%llx, repl: %d, replpc = %llx\n", op->op_num, pc, insert_res.hit, insert_res.line_addr);
        #else
        l0_btb.insert(proc_id, pc, /*is_prefetch =*/ FALSE, new_entry);
        #endif

    }
    else 
    {
      //int counter_val = access_res.data.counter;
      //if(counter_val<3) counter_val++;
      //l0_btb.data[access_res.cache_addr.set][access_res.cache_addr.way].counter = counter_val;
      if(access_res.data.counter < 3){
        access_res.data.counter++;
      }
      l0_btb.update(access_res);
    }
    DEBUG(proc_id, "Drop l0btb for l0btb hit op %llu\n", op->op_num);
  } 
  else{
    //DEBUG(proc_id, "Drop l0btb for NT op %llu\n", op->op_num);
    auto access_res = l0_btb.probe(proc_id, pc);
    if(access_res.hit)
    {
      if(access_res.data.counter > 0){
        access_res.data.counter--;
      }
      l0_btb.update(access_res);
    }
  }
  
}

void bp_ffp_mul_tage_retire(Op* op) {
  uns proc_id = op->proc_id;
  if(op->recovery_info.future_tage_update_id != -1){
    //if(future_tage_response_delay_queue.front().branch_id != op->recovery_info.future_tage_update_id){
    //  fprintf(stderr, "queue front id is %ld, trying to retire %lld\n", future_tage_response_delay_queue.front().branch_id, op->recovery_info.future_tage_update_id);
    //}
    ASSERT(0, future_tage_response_delay_queue.front().branch_id == op->recovery_info.future_tage_update_id);
    //fprintf(stderr, "queue front id is %ld, trying to br with update id %lld\n", future_tage_response_delay_queue.front().branch_id, op->recovery_info.future_tage_update_id);
    future_tage_response_delay_queue.pop_front();
  }
  //else{
  //  fprintf(stderr, "retire br with update id -1, br id %lld\n", op->recovery_info.future_tage_branch_id);
  //}
  future_tages0.at(proc_id)->commit_state_at_retire_real_stale(
    op->recovery_info.future_tage_branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir,
    op->oracle_info.target, op->recovery_info.future_tage_update_id);
  future_tages1.at(proc_id)->commit_state_at_retire_real_stale(
    op->recovery_info.future_tage_branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir,
    op->oracle_info.target, op->recovery_info.future_tage_update_id);
}

void bp_ffp_mul_tage_recover(Recovery_Info* recovery_info) {
  uns proc_id = recovery_info->proc_id;
  auto mispred_id = recovery_info->future_tage_branch_id;
  int nums_to_pop = 0;
  for(uint32_t i = future_tage_response_delay_queue.size() - 1; i >= 0 ; i--){
    delay_queue_entry temp = future_tage_response_delay_queue[i];
    if(temp.branch_id > mispred_id){
      nums_to_pop++;
    }
    else{
      break;
    }
  }
  //fprintf(stderr, "mispred id: %lld, ", mispred_id);
  for(int i = 0; i < nums_to_pop; i++){
    //fprintf(stderr, "popping id %ld", future_tage_response_delay_queue.back().branch_id);
    future_tage_response_delay_queue.pop_back();
  }
  ASSERT(0, future_tage_response_delay_queue.back().branch_id == mispred_id);
  future_tage_response_delay_queue.back().current_pred = !future_tage_response_delay_queue.back().current_pred;
  //fprintf(stderr, "\n");
  future_tages0.at(proc_id)->flush_branch_and_repair_state(
    recovery_info->future_tage_branch_id, recovery_info->PC,
    get_branch_type(proc_id, recovery_info->cf_type), recovery_info->new_dir,
    recovery_info->branchTarget);
  future_tages1.at(proc_id)->flush_branch_and_repair_state(
    recovery_info->future_tage_branch_id, recovery_info->PC,
    get_branch_type(proc_id, recovery_info->cf_type), recovery_info->new_dir,
    recovery_info->branchTarget);
  if(recovery_info->late_bp_recovery){
    last_late_bp_flush_id = mispred_id;
  }
  else{
    last_full_bp_flush_id = mispred_id;
  }
}
