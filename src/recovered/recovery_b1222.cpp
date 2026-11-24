#include "recovery_b1222.hpp"
#include <stdexcept>
namespace ra2::recovered::b1222 {namespace {
void need(bool x){if(!x)throw std::domain_error("1222 finite coherent public Team method composition");}
unsigned kind(Memory&m,unsigned actor,Observation&o){need(actor&&m.r32(actor)==0x78e540u&&m.r32(0x78e56cu)==0x508c50u);++o.virtual_callbacks;return 15u;}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 need((root==0x2b08b0u||root==0x2b0ad0u)&&m.r32(i.cx)==0x7977f8u&&m.r32(0xa283c4u)==0u&&m.r8(i.cx+0x80u)==0u&&i.arg[1]==0u);
 const unsigned target=m.r32(i.cx+0x3cu);need(target&&m.r32(i.cx+0x40u)==target);
 const unsigned script=m.r32(i.cx+0x28u),type=m.r32(script+0x24u),command=root==0x2b08b0u?15u:0u;
 need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==0u&&m.r32(type)==0x794260u&&m.r32(type+0xa0u)==1u&&m.r32(type+0xa4u)==command&&m.r32(type+0xa8u)==0u&&m.r32(i.arg[0])==command&&m.r32(i.arg[0]+4u)==0u);
 if(root==0x2b08b0u){need(kind(m,target,o)!=11u);} // Original false arg1 excludes a new waypoint; non-Cell target enters shared helper.
 else {const unsigned first=m.r32(i.cx+0x54u);need(first&&m.r32(first)==0x78e540u&&m.r32(0x78e5c0u)==0x6b6910u&&m.r32(0x78e5c4u)==0x505da0u);o.virtual_callbacks+=2u;const unsigned inf_type=m.r32(first+0x5a8u);need(m.r32(inf_type)==0x78ea78u&&m.r32(inf_type+0x5acu)==0xffffffffu);}
 // Exact reached 6AF200 path: nonnull target of kind15 bypasses all Cell/Map work.
 need(kind(m,target,o)!=11u);++o.script_reads; // 65F820 copies the coherent current public step to private output only.
 unsigned member=m.r32(i.cx+0x54u);need(member);
 while(member){need(++o.members<=6u&&m.r32(member)==0x78e540u&&m.r32(member+0x4c4u)==i.cx);
  need(m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==1u);++o.limbo_checks;
  need(m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==1u);++o.limbo_checks;
  member=m.r32(member+0x4c8u);
 }
 m.w8(i.cx+0x80u,1u);++o.completions;
 return 0u; // 6AF576 loads initialized private AL=0 after EAX=1 from last limbo check; 6AF57E does not change EAX.
}
}
