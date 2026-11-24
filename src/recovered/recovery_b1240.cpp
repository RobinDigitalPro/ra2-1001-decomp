#include "recovery_b1240.hpp"
#include <stdexcept>
namespace ra2::recovered::b1240 {namespace {
void need(bool x){if(!x)throw std::domain_error("1240 direct positive coherent Team completion");}
unsigned kind(Memory&m,unsigned actor,Observation&o){need(actor&&m.r32(actor)==0x78e540u&&m.r32(0x78e56cu)==0x508c50u);++o.virtual_callbacks;return 15u;}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 need(root==0x2af200u&&m.r32(i.cx)==0x7977f8u&&m.r32(0xa283c4u)==0u&&m.r8(i.cx+0x80u)==0u);
 const unsigned target=m.r32(i.cx+0x40u);need(target&&m.r32(i.cx+0x3cu)==target);need(kind(m,target,o)!=11u);
 const unsigned script=m.r32(i.cx+0x28u),type=m.r32(script+0x24u);
 need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==0u&&m.r32(type)==0x794260u&&m.r32(type+0xa0u)==1u&&m.r32(type+0xa4u)==0u&&m.r32(type+0xa8u)==0u);++o.script_reads;
 // Original65F820 fully produces its private8B output; initialized6AF342 ALflag
 // needs no caller arg or pre-entry stack seed. Team+76 is unconstrained.
 unsigned member=m.r32(i.cx+0x54u);need(member);
 while(member){need(++o.members<=6u&&m.r32(member)==0x78e540u&&m.r32(member+0x4c4u)==i.cx);
  need(m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==1u);++o.limbo_checks;
  need(m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==1u);++o.limbo_checks;
  member=m.r32(member+0x4c8u);
 }
 m.w8(i.cx+0x80u,1u);++o.completions;return 0u;
}
}
