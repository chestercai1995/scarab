extern "C" {
#include "globals/assert.h"
#include "globals/global_defs.h"
#include "globals/global_types.h"
#include "globals/global_vars.h"
#include "globals/utils.h"
#include "op_info.h"
#include "op.h"

#include "bp/bp.h"
#include "exec_ports.h"
#include "frontend/frontend.h"
#include "memory/memory.h"
#include "node_stage.h"
#include "thread.h"

#include "bp/bp.param.h"
#include "core.param.h"
#include "debug/debug.param.h"
#include "map.h"
#include "memory/memory.param.h"
#include "sim.h"
#include "statistics.h"
}

#include "bp/tagescl.h"
#include "br_stat.h"
#include <unordered_map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>


class per_branch_stat{
  public: 
  uns64 pc;
  uns64 times_taken;
  uns64 times_not_taken;
  uns64 early_mispred;
  uns64 late_mispred;
  std::unordered_map<Addr, uint64_t> following_brs_stat;
  
  per_branch_stat(){
    pc = 0;
    times_taken = 0;
    times_not_taken = 0;
    early_mispred = 0;
    late_mispred = 0;
  }

  bool operator < (const per_branch_stat& another) const
  {
      return (early_mispred > another.early_mispred);
  }
};

std::unordered_map<Addr, per_branch_stat> br_stats;
std::deque<Addr> last_N_brs;
//FILE *fp1 = fopen("warmup_stat.csv", "w");

void collect_br_stats(Op* op){
  Addr pc = op->inst_info->addr;
  auto curr_br = br_stats.find(pc);
  if(curr_br == br_stats.end()){
    per_branch_stat temp;
    temp.pc = pc;
    br_stats[pc] = temp; 
  }
  if(op->oracle_info.dir){
    br_stats[pc].times_taken++;
  }
  else{
    br_stats[pc].times_not_taken++;
  }
  if(op->oracle_info.l0_mispred){
    br_stats[pc].early_mispred++;
  }
  if(op->oracle_info.l1_mispred){
    br_stats[pc].late_mispred++;
  }
  //if(last_N_brs.size() == STALE_HISTORY_DISTANCE) {
  //  Addr lead_br_pc = last_N_brs.front();
  //  ASSERT(0, br_stats.find(lead_br_pc) != br_stats.end());
  //  if(br_stats[lead_br_pc].following_brs_stat.find(pc) == br_stats[lead_br_pc].following_brs_stat.end()){
  //    // need to create a new entry
  //    br_stats[lead_br_pc].following_brs_stat[pc] = 1;
  //  }
  //  else{
  //    br_stats[lead_br_pc].following_brs_stat[pc] += 1;
  //  }
  //  last_N_brs.pop_front();
  //}
  //last_N_brs.push_back(pc);
}

void final_br_stat_print(){
  int t_ratios[12];
  int num_unique_brs = 0;
  std::vector<per_branch_stat> final_stats;
  for(int i = 0; i < 12; i++){
    t_ratios[i] = 0;
  }
  for(auto curr = br_stats.begin(); curr != br_stats.end(); curr++){
    uns64 total = curr->second.times_taken + curr->second.times_not_taken;
    uns idx = curr->second.times_taken * 10 / total + 1;
    if (curr->second.times_not_taken == total){
      idx = 0;  
    }
    t_ratios[idx]++;
    num_unique_brs++;
    final_stats.push_back(curr->second);
  }

  printf("br taken ratios 0: %d\n", t_ratios[0]);
  for(int i = 0; i < 10; i++){
    printf("br taken ratios %d to %d: %d\n", i*10, i*10+10, t_ratios[i+1]);
  }
  printf("br taken ratios 100: %d\n", t_ratios[11]);
  printf("total branches %d\n", num_unique_brs);

  printf("top N early mispred branches\n");
  std::sort(final_stats.begin(), final_stats.end());
  for(uns i = 0; i < 20 && i < final_stats.size(); i++){
    printf("pc: %llx, num of early mispred %llu, times T %llu, times NT %llu, num late_mispred %llu\n", final_stats[i].pc, final_stats[i].early_mispred, final_stats[i].times_taken, final_stats[i].times_not_taken, final_stats[i].late_mispred);
  }

  FILE *fp = fopen("per_branch.csv", "w");
  for(auto item:br_stats){
    fprintf(fp, "%llx,", item.first);
    fprintf(fp, "%llu,%llu,%llu,%llu\n", item.second.times_taken, item.second.times_not_taken, item.second.early_mispred, item.second.late_mispred);
  }
  fclose(fp);

  //fp = fopen("br_N_after.csv", "w");
  //for(auto item:br_stats){
  //  fprintf(fp, "%llx,", item.first);
  //  fprintf(fp, "%lu,", item.second.following_brs_stat.size());
  //  for(auto br_pc:item.second.following_brs_stat){
  //    fprintf(fp, "%llx, %lu", br_pc.first, br_pc.second);
  //  }
  //  fprintf(fp, "\n");
  //}
  //fclose(fp);

  //fp = fopen("br_N_after_wo_pc.csv", "w");
  //for(auto item:br_stats){
  //  fprintf(fp, "%llx,", item.first);
  //  fprintf(fp, "%lu,", item.second.following_brs_stat.size());
  //  for(auto br_pc:item.second.following_brs_stat){
  //    fprintf(fp, "%lu", br_pc.second);
  //  }
  //  fprintf(fp, "\n");
  //}
  //fclose(fp);
}



void per_interval_print(){
//  fprintf(fp1, "%llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu\n", 
//                               cycle_count, global_stat_array[0][BP_ON_PATH_MISPREDICT].count,
//                                            global_stat_array[0][BP_ON_PATH_MISFETCH].count,
//                                            global_stat_array[0][BP_ON_PATH_CORRECT].count,
//                                            global_stat_array[0][BTB_ON_PATH_HIT].count,
//                                            global_stat_array[0][BTB_ON_PATH_MISS].count,
//                                            global_stat_array[0][ICACHE_MISS_ONPATH].count,
//                                            global_stat_array[0][DCACHE_MISS_ONPATH].count);
}
