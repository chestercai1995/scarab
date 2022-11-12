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

#include "future_tage.h"

#include <iostream>
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
};

Counter last_flush_cycle = 0;

std::vector<Cache_cpp<l0_btb_entry>> l0_across_all_cores;
// A vector of TAGE-SC-L tables. One table per core.
std::vector<std::unique_ptr<Tage_SC_L_Base>> future_tages;

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

void bp_future_tage_init() {
  if(future_tages.size() == 0) {
    future_tages.reserve(NUM_CORES);
    for(uns i = 0; i < NUM_CORES; ++i) {
      future_tages.push_back(
        std::make_unique<Tage_SC_L<TAGE_SC_L_CONFIG_FUTURE>>(NODE_TABLE_SIZE));
      l0_across_all_cores.push_back(Cache_cpp<l0_btb_entry>("l0_btb", L0_BTB_SIZE, L0_BTB_ASSOC, 1, SRRIP_REPL));
    }
  }
  ASSERTM(0, future_tages.size() == NUM_CORES,
          "future_tages not initialized correctly");
}

void bp_future_tage_timestamp(Op* op) {
  uns proc_id = op->proc_id;
  op->recovery_info.branch_id =
    future_tages.at(proc_id)->get_new_branch_id();
}

uns8 bp_future_tage_pred(Op* op) {
  uns proc_id = op->proc_id;
  future_tages.at(proc_id)->get_prediction(
    op->recovery_info.branch_id, op->inst_info->addr);
  
  if(cycle_count > last_flush_cycle + LATE_BP_LATENCY + 1){
    //TODO: ADD THIS TO TABLE
  }

  Addr        pc          = op->inst_info->addr;
  auto&       l0_btb      = l0_across_all_cores.at(op->proc_id);
  Cache_access_result<l0_btb_entry> res = l0_btb.probe(op->proc_id, pc);
  Flag hit = res.hit;
  Flag counter_taken = res.data.counter>1;
  
  DEBUG(op->proc_id, "Predicting for op_num:%s addr:%s, p_dir:%d, t_dir:%d\n",
        unsstr64(op->op_num), hexstr64s(pc), pred, op->oracle_info.dir);
  if(USE_2_BIT_COUNTER_IN_L0) return hit && counter_taken; 
  else return hit;
}

void bp_future_tage_spec_update(Op* op) {
  uns proc_id = op->proc_id;
  future_tages.at(proc_id)->update_speculative_state(
    op->recovery_info.branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.pred,
    op->oracle_info.target);
}

void bp_future_tage_update(Op* op) {
  const uns   proc_id      = op->proc_id;
  future_tages.at(proc_id)->commit_state(
    op->recovery_info.branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir);

  auto cf_type = op->table_info->cf_type;
  if(cf_type != CF_CBR && cf_type != CF_BR && cf_type != CF_CALL) {
    //only deal with direct branches, maybe can remove call later as well
    return;
  }

  auto&       l0_btb       = l0_across_all_cores.at(proc_id);
  const Addr  pc           = op->inst_info->addr;


  if(op->oracle_info.dir) {
    auto access_res = l0_btb.access(proc_id, pc);
    if(!access_res.hit){
        l0_btb_entry new_entry = {pc, op->oracle_info.target, 2};
        auto insert_res = l0_btb.insert(proc_id, pc, /*is_prefetch =*/ FALSE, new_entry);
        if(!insert_res.hit){
          printf("nothing replaced\n");
        }
        DEBUG(proc_id, "write l0btb op %llu, pc=x%llx, repl: %d, replpc = %llx\n", op->op_num, pc, insert_res.hit, insert_res.line_addr);
    }
    else 
    {
      int counter_val = access_res.data.counter;
      if(counter_val<3) counter_val++;
      l0_btb.data[access_res.cache_addr.set][access_res.cache_addr.way].counter = counter_val;
    }
    DEBUG(proc_id, "Drop l0btb for l0btb hit op %llu\n", op->op_num);
  } 
  else{
    //DEBUG(proc_id, "Drop l0btb for NT op %llu\n", op->op_num);
    auto access_res = l0_btb.probe(proc_id, pc);
    if(access_res.hit)
    {
      int counter_val = access_res.data.counter;
      if(counter_val>0) counter_val--;
      l0_btb.data[access_res.cache_addr.set][access_res.cache_addr.way].counter = counter_val;
    }
  }
}

void bp_future_tage_retire(Op* op) {
  uns proc_id = op->proc_id;
  future_tages.at(proc_id)->commit_state_at_retire(
    op->recovery_info.branch_id, op->inst_info->addr,
    get_branch_type(proc_id, op->table_info->cf_type), op->oracle_info.dir,
    op->oracle_info.target);
}

void bp_future_tage_recover(Recovery_Info* recovery_info) {
  uns proc_id = recovery_info->proc_id;
  future_tages.at(proc_id)->flush_branch_and_repair_state(
    recovery_info->branch_id, recovery_info->PC,
    get_branch_type(proc_id, recovery_info->cf_type), recovery_info->new_dir,
    recovery_info->branchTarget);
  last_flush_cycle = cycle_count;
}
