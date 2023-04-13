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

#include "real_future_tage.h"

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
  Future_tage_pred future_tage_pred;
  int64_t branch_id;
  uint64_t insert_cycle;
};

struct blacklist_entry{
  uint32_t counter;
};

std::vector<Cache_cpp<l0_btb_entry>> l0_across_all_cores;
// A vector of TAGE-SC-L tables. One table per core.
std::vector<std::unique_ptr<Tage_SC_L_Base>> future_tages;

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
}  // end of anonymous namespace

void bp_real_future_tage_init() {
  if(future_tages.size() == 0) {
    future_tages.reserve(NUM_CORES);
    for(uns i = 0; i < NUM_CORES; ++i) {
      if(FUTURE_TAGE_SIZE_KB == 64){
        future_tages.push_back(
          std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_REAL_FUTURE_64KB>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      }
      //else if(FUTURE_TAGE_SIZE_KB == 48){
      //  future_tages.push_back(
      //    std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_REAL_FUTURE_48KB>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      //}
      //else if(FUTURE_TAGE_SIZE_KB == 32){
      //  future_tages.push_back(
      //    std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_REAL_FUTURE_32KB>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      //}
      //else if(FUTURE_TAGE_SIZE_KB == 16){
      //  future_tages.push_back(
      //    std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_REAL_FUTURE_16KB>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      //}
      //else if(FUTURE_TAGE_SIZE_KB == 8){
      //  future_tages.push_back(
      //    std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_REAL_FUTURE_8KB>>(NODE_TABLE_SIZE + STALE_HISTORY_DISTANCE));
      //}
      else {
        ASSERT(0, false);
      }
      l0_across_all_cores.push_back(Cache_cpp<l0_btb_entry>("l0_btb", L0_BTB_SIZE, L0_BTB_ASSOC, 1, SRRIP_REPL));
    }
  }
  ASSERT(0, STALE_HISTORY_DISTANCE != 0);
  ASSERTM(0, future_tages.size() == NUM_CORES,
          "future_tages not initialized correctly");
  ASSERT(0, (!FUTURE_TAGE_NO_UPDATE) || INSERT_FUTURE_TAGE_ON_TAKEN);
}

void bp_real_future_tage_timestamp(Op* op) { 
  uns proc_id = op->proc_id;
  int64_t old_id = future_tages.at(proc_id)->get_old_branch_id(STALE_HISTORY_DISTANCE);
  int64_t new_id = future_tages.at(proc_id)->get_new_branch_id(op->off_path);
  op->recovery_info.future_tage_branch_id = new_id;
  op->recovery_info.future_tage_update_id = old_id;
}

uns8 bp_real_future_tage_pred(Op* op) {
  uns proc_id = op->proc_id;

  auto&       l0_btb      = l0_across_all_cores.at(op->proc_id);

  Addr        pc          = op->inst_info->addr;
  Cache_access_result<l0_btb_entry> res = l0_btb.probe(op->proc_id, pc);
  Flag hit = res.hit;
  Flag counter_taken = res.data.counter>1;
  Flag btb_prediction = USE_2_BIT_COUNTER_IN_L0 ? hit : hit && counter_taken;
  if(!op->off_path){
    printf("L0BTB: pc %llx id %lld, pred is %d, true_dir %d\n", op->inst_info->addr, op->recovery_info.future_tage_branch_id, btb_prediction, op->oracle_info.dir);
  }

  DEBUG(proc_id, "Predicting for op_num:%s addr:%s, p_dir:%d, t_dir:%d\n",
        unsstr64(op->op_num), hexstr64s(pc), hit, op->oracle_info.dir);


  Future_tage_pred future_tage_res = future_tages.at(proc_id)->get_future_pred(
    op->recovery_info.future_tage_branch_id, op->inst_info->addr);
  
  DEBUG(op->proc_id, "future tage on op %llu, pc is %lx, pred is %d\n", op->op_num, future_tage_res.pc, future_tage_res.pred);

  delay_queue_entry temp_entry;
  temp_entry.future_tage_pred = future_tage_res;
  temp_entry.insert_cycle = cycle_count;
  temp_entry.branch_id = op->recovery_info.future_tage_branch_id;

  future_tage_response_delay_queue.push_back(temp_entry);
  if(!op->off_path){
    printf("PUSH: currently at %llx, pred pc %lx, dir: %d, current id %lld\n", op->inst_info->addr, temp_entry.future_tage_pred.pc, temp_entry.future_tage_pred.pred, op->recovery_info.future_tage_branch_id);
  }

  for(auto& element : future_tage_response_delay_queue){
    if(element.branch_id == op->recovery_info.future_tage_update_id){
      if(element.future_tage_pred.pc == op->inst_info->addr){
        if(cycle_count - element.insert_cycle > FUTURE_TAGE_LATENCY){
          if(element.future_tage_pred.pred == op->oracle_info.dir){
            //correct pred
            INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_EXACTLY_RIGHT, 1);  
          }
          else{
            //correct pc, incorrect pred
            INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_EXACTLY_DIR_WRONG, 1);  
          }
          op->ffp_wrong_btb_correct = FALSE;
          op->ffp_correct_btb_wrong = FALSE;
          op->ffp_both_correct = FALSE;

          if(FUTURE_TAGE_NO_UPDATE){
            if(element.future_tage_pred.pred != op->oracle_info.dir){
              //mispred
              if(op->oracle_info.dir == btb_prediction){
                op->ffp_wrong_btb_correct = TRUE;
              }
            }
            else{
              //correct_pred
              if(op->oracle_info.dir == btb_prediction){
                op->ffp_both_correct = TRUE;
              }
              else{
                op->ffp_correct_btb_wrong = TRUE;
              }
            }
            return element.future_tage_pred.pred;
          }
          else{
            //insert into L0BTB
            ASSERT(0, FALSE);
          }
        }
        else{
          //late
          INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_LATE, 1);  
        }
      }
      else {
        //entry wrong PC
        INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_EXACTLY_PC_WRONG, 1);  
      }
      break;
    }
  }  
  
  //if(FUTURE_TAGE_NO_UPDATE){
  //  for(uint32_t i = 0; i < future_tage_response_delay_queue.size(); i++){
  //    delay_queue_entry temp = future_tage_response_delay_queue[i];
  //    if(cycle_count - temp.insert_cycle >= FUTURE_TAGE_LATENCY){
  //      if(temp.branch_id == op->recovery_info.future_tage_update_id){
  //        if(temp.future_tage_pred.pc == op->inst_info->addr){
  //          if(!op->off_path){
  //            printf("USING: current pc %llx id %lld, pred pc %lx, dir %d, matching id %ld, true_dir %d\n", op->inst_info->addr, op->recovery_info.future_tage_branch_id, temp.future_tage_pred.pc, temp.future_tage_pred.pred, temp.branch_id, op->oracle_info.dir);
  //          }
  //          return temp.future_tage_pred.pred;
  //        }
  //        else{
  //          if(!op->off_path){
  //            printf("NOT MATCH: current pc %llx id %lld, pred pc %lx, dir %d, matching id %ld\n", op->inst_info->addr, op->recovery_info.future_tage_branch_id, temp.future_tage_pred.pc, temp.future_tage_pred.pred, temp.branch_id);
  //          }
  //          //this isn't the one, use the l0 btb for prediction
  //          break;
  //        }
  //      }
  //    }
  //    else{
  //      if(!op->off_path){
  //        printf("LATE: current pc %llx id %lld, pred pc %lx, dir %d, matching id %ld\n", op->inst_info->addr, op->recovery_info.future_tage_branch_id, temp.future_tage_pred.pc, temp.future_tage_pred.pred, temp.branch_id);
  //      }
  //      //seen enough, everything after are not ready yet since the queue is ordered
  //      break;
  //    }
  //  }
  //}
  //else{
  //  int nums_to_pop = 0;
  //  for(uint32_t i = 0; i < future_tage_response_delay_queue.size(); i++){
  //    delay_queue_entry temp = future_tage_response_delay_queue[i];
  //    if(cycle_count - temp.insert_cycle >= FUTURE_TAGE_LATENCY){
  //      if(FUTURE_TAGE_ORACLE_ORDERING){
  //        if(temp.branch_id > op->recovery_info.future_tage_update_id){
  //          continue;
  //        }
  //      }
  //      DEBUG(op->proc_id, "updating l0 btb\n");
  //      if(temp.future_tage_pred.pred){
  //        Cache_access_result<l0_btb_entry> car_res = l0_btb.probe(op->proc_id, temp.future_tage_pred.pc);
  //        if(!car_res.hit){
  //          l0_btb_entry new_entry = {temp.future_tage_pred.pc, op->oracle_info.target, 2, true, false};
  //          l0_btb.insert(proc_id, temp.future_tage_pred.pc, true, new_entry);
  //        }
  //        else{ //replaced an entry when inserting
  //          if(car_res.data.insert_by_ft && !car_res.data.used){
  //            INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_VICTIM_NO_TOUCH, 1);  
  //          }
  //        }
  //      }
  //      else{
  //        Cache_access_result<l0_btb_entry> car_res = l0_btb.probe(op->proc_id, temp.future_tage_pred.pc);
  //        if(car_res.hit){
  //          Cache_access_result<l0_btb_entry> inv_res = l0_btb.invalidate(proc_id, temp.future_tage_pred.pc);
  //          if(inv_res.hit && inv_res.data.insert_by_ft && inv_res.data.used){
  //            INC_STAT_EVENT(op->proc_id, FUTURE_TAGE_VICTIM_NO_TOUCH, 1);  
  //          }
  //        }
  //      }
  //      nums_to_pop++;  
  //    }
  //    else{
  //      break;
  //    }
  //  }
  //  for(int i  = 0; i < nums_to_pop; i++){
  //    future_tage_response_delay_queue.pop_front();
  //  }
  //}

  return btb_prediction;
}

void bp_real_future_tage_spec_update(Op* op) {
  uns proc_id = op->proc_id;
  
  future_tages.at(proc_id)->update_speculative_state(
    op->recovery_info.branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.pred,
    op->oracle_info.target);
}

void bp_real_future_tage_update(Op* op) {
  const uns   proc_id      = op->proc_id;
  Flag skip = false;
  if(op->recovery_info.future_tage_update_id != -1){
    if(ffp_blacklist.find(op->inst_info->addr) != ffp_blacklist.end()){
      if(ffp_blacklist[op->inst_info->addr].counter > FFP_COUNTER_THRESHOLD){
        skip = true; 
      }
    }
    if(!skip){
      future_tages.at(proc_id)->commit_state(
        op->recovery_info.future_tage_update_id, op->inst_info->addr,
        get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir, op->off_path);
    }
  }

  auto cf_type = op->table_info->cf_type;
  if(cf_type != CF_CBR && cf_type != CF_BR && cf_type != CF_CALL) {
    //only deal with direct branches, maybe can remove call later as well
    return;
  }

  auto&       l0_btb       = l0_across_all_cores.at(proc_id);
  const Addr  pc           = op->inst_info->addr;


  if(INSERT_FUTURE_TAGE_ON_TAKEN){
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
}

void bp_real_future_tage_retire(Op* op) {
  uns proc_id = op->proc_id;
  if(FUTURE_TAGE_NO_UPDATE){
    if(op->recovery_info.future_tage_update_id != -1){
      if(future_tage_response_delay_queue.front().branch_id != op->recovery_info.future_tage_update_id){
        fprintf(stderr, "queue front id is %ld, trying to retire %lld\n", future_tage_response_delay_queue.front().branch_id, op->recovery_info.future_tage_update_id);
      }
      ASSERT(0, future_tage_response_delay_queue.front().branch_id == op->recovery_info.future_tage_update_id);
      future_tage_response_delay_queue.pop_front();
    }
  }
  if(FUTURE_TAGE_BLACKLIST){
    if(op->ffp_wrong_btb_correct){
      auto this_br = ffp_blacklist.find(op->inst_info->addr);
      if(this_br == ffp_blacklist.end()){
        blacklist_entry new_entry;
        new_entry.counter = 1;
        ffp_blacklist[op->inst_info->addr] = new_entry;
      }
      else{
        ffp_blacklist[op->inst_info->addr].counter += 2;
      }
    } 
    else if(op->ffp_both_correct){
      auto this_br = ffp_blacklist.find(op->inst_info->addr);
      if(this_br != ffp_blacklist.end()){
        ffp_blacklist[op->inst_info->addr].counter += 1;
      }
    }
    else if(op->ffp_correct_btb_wrong){
      auto this_br = ffp_blacklist.find(op->inst_info->addr);
      if(this_br != ffp_blacklist.end()){
        ffp_blacklist[op->inst_info->addr].counter -= 1;
      }
    }
  }
  future_tages.at(proc_id)->commit_state_at_retire_real_stale(
    op->recovery_info.future_tage_branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir,
    op->oracle_info.target, op->recovery_info.future_tage_update_id);
}

void bp_real_future_tage_recover(Recovery_Info* recovery_info) {
  uns proc_id = recovery_info->proc_id;
  auto mispred_id = recovery_info->future_tage_branch_id;
  int nums_to_pop = 0;
  if(FUTURE_TAGE_NO_UPDATE){
    for(uint32_t i = future_tage_response_delay_queue.size() - 1; i >= 0 ; i--){
      delay_queue_entry temp = future_tage_response_delay_queue[i];
      if(temp.branch_id > mispred_id){
        nums_to_pop++;
      }
      else{
        break;
      }
    }
    for(int i = 0; i < nums_to_pop; i++){
      future_tage_response_delay_queue.pop_back();
    }
  }
  future_tages.at(proc_id)->flush_branch_and_repair_state(
    recovery_info->future_tage_branch_id, recovery_info->PC,
    get_branch_type(proc_id, recovery_info->cf_type), recovery_info->new_dir,
    recovery_info->branchTarget);
}
