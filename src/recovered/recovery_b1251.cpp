#include "recovery_b1251.hpp"
#include <stdexcept>
namespace ra2::recovered::b1251 {namespace {void need(bool x){if(!x)throw std::domain_error("1251 positive activeInfantry arrival bookkeeping");}}
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 need((root==0x2b0f00u||root==0x2b1200u)&&m.r32(i.cx)==0x7977f8u&&m.r8(i.cx+0x80u)==0u&&m.r32(0xa283c4u)==0u&&m.r32(i.cx+0x34u)==0u);
 const unsigned command=root==0x2b0f00u?9u:11u,script=m.r32(i.cx+0x28u),type=m.r32(script+0x24u);need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==0u&&m.r32(type)==0x794260u&&m.r32(type+0xa0u)==1u&&m.r32(type+0xa4u)==command&&m.r32(type+0xa8u)==5u);
 if(root==0x2b1200u)need(m.r32(i.arg[0])==11u&&m.r32(i.arg[0]+4u)==5u);
 const unsigned rules=m.r32(0x821b88u);need(m.r32(rules+0x1384u)==512u&&m.r32(rules+0x1388u)==512u);
 unsigned member=m.r32(i.cx+0x54u),last_type=0u;need(member);
 while(member){need(++o.members<=6u&&m.r32(member)==0x78e540u&&m.r32(member+0x4c4u)==i.cx&&m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==0u&&m.r8(member+0x579u)==0u);
  // Actual65F820 supplies coherent command/value; trueTeam34NULL makes
  // actual5CD290 return0 before all FP and virtual coordinate work.
  ++o.script_reads;++o.null_distances;m.w8(member+0x579u,1u);++o.arrivals;
  if(root==0x2b0f00u){last_type=m.r32(member+0x5a8u);need(m.r32(0x78e56cu)==0x508c50u&&last_type&&m.r8(last_type+0xc16u)==0u);o.kind_callbacks+=3u;++o.predicate_reads;}
  else{need(m.r32(member+0x228u)==0u&&m.r32(member+0x494u)==0u&&m.r32(member+0x98u)==0xffffffffu&&m.r32(member+0xa0u)==5u&&m.r32(0x78e6acu)==0x591570u);++o.script_reads;++o.null_distances;++o.mission_reads;}
  member=m.r32(member+0x4c8u);
 }
 if(root==0x2b0f00u){m.w8(i.cx+0x80u,1u);++o.completions;return(last_type&0xffffff00u)|1u;}
 return 5u;
}
}
