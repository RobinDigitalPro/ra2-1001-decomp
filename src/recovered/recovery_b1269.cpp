#include "recovery_b1269.hpp"
#include <stdexcept>
namespace ra2::recovered::b1269 {
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 const auto need=[](bool x){if(!x)throw std::domain_error("1269 positive populated Infantry Team completion");};
 need(root==0x2b0c40u&&m.r32(i.cx)==0x7977f8u&&m.r8(i.cx+0x80u)==0u);
 const unsigned teamtype=m.r32(i.cx+0x24u),task=m.r32(teamtype+0xdcu);need(m.r32(teamtype)==0x797898u&&m.r32(task)==0x797748u&&m.r32(task+0x9cu)==1u);
 const unsigned item=m.r32(task+0xa8u);need(m.r32(item)==0x78ea78u&&m.r32(0x78ea78u+0x2cu)==0x50a3b0u);++o.taskforce_reads;
 // The exact original InfantryType virtual returns16, not aircraftkind3.
 unsigned member=m.r32(i.cx+0x54u),eax=0u;need(member!=0u);
 do {need(o.member_reads<6u&&m.r32(member)==0x78e540u&&m.r32(0x78e540u+0x80u)==0x6b6910u&&m.r32(0x78e540u+0x84u)==0x505da0u);eax=m.r32(member+0x5a8u);++o.type_calls;need(eax==item&&m.r32(eax+0x52cu)==0u);++o.member_reads;member=m.r32(member+0x4c8u);}while(member);
 m.w8(i.cx+0x80u,1u);++o.completion_marks;return eax;
}
}
