#include "recovery_b1246.hpp"
#include <stdexcept>
namespace ra2::recovered::b1246 {namespace {
void need(bool x){if(!x)throw std::domain_error("1246 genuine waypoint query and positive Team completion");}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,State&f,Observation&o){
 need(root==0x2b0740u&&m.r32(i.cx)==0x7977f8u&&m.r8(i.cx+0x80u)==0u&&m.r32(0xa283c4u)==0u&&(i.arg[1]&255u)==0u);
 const auto step=i.arg[0];need(m.r32(step)==16u&&m.r32(step+4u)==0u);
 // Genuine65A150 passes Scenario waypoint0 to545500's indexedCell lookup.
 const auto scenario=m.r32(0xa255c0u),coord=m.r32(scenario+0x632u);need(coord==0x00140014u);
 const auto table=m.r32(0x81a958u),cell=m.r32(table+4u*(20u+512u*20u));need(cell&&m.r32(cell)==0x788b04u&&m.r32(cell+0x24u)==coord);++o.waypoint_queries;i.arg[0]=cell;
 const auto target=m.r32(i.cx+0x40u);need(target&&m.r32(i.cx+0x3cu)==target);
 const auto rules=m.r32(0x821b88u);const unsigned long long rate=m.r32(rules+0xe28u)|(static_cast<unsigned long long>(m.r32(rules+0xe2cu))<<32u);need(rate==0x3f90624dd2f1a9fcull);
 // Actual FLD/FMUL/_ftol61: product is exact at PC64, then globalCW0E7F
 // and FISTP64 ->14. State platform preserves host FP at each operation.
 f.load64(rate);f.multiply64(0x408c200000000000ull);need(m.r32(0x7c3a04u)==0xe7fu);f.load_control(0xe7fu);need(f.pop_integer64()==14u);++o.period_conversions;
 const auto frame=m.r32(0xa2896cu);need(frame>=1u&&frame<=13u&&frame%14u!=0u);
 need((m.r8(target+0x14u)&2u)!=0u&&m.r32(target)==0x78e540u&&m.r32(0x78e56cu)==0x508c50u);++o.virtual_callbacks;
 // Exact reached6AF200 path. Non-Cell kind15 skips itsMap/position branch;
 // healthy loaded limbo members short-circuit before command-specific work.
 const auto script=m.r32(i.cx+0x28u),type=m.r32(script+0x24u);need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==0u&&m.r32(type)==0x794260u&&m.r32(type+0xa0u)==1u&&m.r32(type+0xa4u)==16u&&m.r32(type+0xa8u)==0u);++o.script_reads;
 auto member=m.r32(i.cx+0x54u);need(member);
 while(member){need(++o.members<=6u&&m.r32(member)==0x78e540u&&m.r32(member+0x4c4u)==i.cx);for(unsigned j=0;j<2u;++j){need(m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==1u);++o.limbo_checks;}member=m.r32(member+0x4c8u);}
 m.w8(i.cx+0x80u,1u);++o.completions;return 0u;
}
}
