#include "recovery_b1272.hpp"
#include <stdexcept>
namespace ra2::recovered::b1272 {
unsigned run(unsigned root,Memory&m,Inputs&i,Observation&o){
 const auto need=[](bool x){if(!x)throw std::domain_error("1272 positive active populated Team arrival/completion");};
 need(root==0x2b2b00u&&m.r32(i.cx)==0x7977f8u&&m.r8(i.cx+0x80u)==0u&&m.r32(i.cx+0x34u)==0u&&m.r32(0xa283c4u)==0u);
 const unsigned head=m.r32(i.cx+0x54u),script=m.r32(i.cx+0x28u);need(head!=0u);
 unsigned member=head,count=0u;
 do {need(++count<=6u&&m.r32(member)==0x78e540u&&m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==0u&&m.r8(member+0x579u)==0u);const unsigned next=m.r32(member+0x4c8u);
  need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==0u);const unsigned st=m.r32(script+0x24u);need(m.r32(st)==0x794260u&&m.r32(st+0xa0u)==1u&&m.r32(st+0xa4u)==8u&&m.r32(st+0xa8u)==0u);++o.step_reads;
  const unsigned rules=m.r32(0x821b88u);need(m.r32(rules+0x1384u)==512u);++o.distance_calls;
  // Exact reached5CD290(NULL) returns0 before anyFP or virtual coordinates.
  m.w8(member+0x579u,1u);++o.arrival_marks;need(m.r32(member+0xfcu)==0u);member=next;
 }while(member);
 const unsigned teamtype=m.r32(i.cx+0x24u),task=m.r32(teamtype+0xdcu);need(m.r32(teamtype)==0x797898u&&m.r32(task)==0x797748u&&m.r32(task+0x9cu)==1u);
 need(m.r32(i.arg[0])==8u&&m.r32(i.arg[0]+4u)==0u);const unsigned item=m.r32(task+0xa8u);need(m.r32(item)==0x78ea78u&&m.r32(0x78ea78u+0x2cu)==0x50a3b0u);++o.taskforce_reads;
 i.arg[0]&=0xffffff00u;
 member=head;unsigned eax=0u;
 do {need(o.member_reads<count&&m.r32(0x78e540u+0x80u)==0x6b6910u&&m.r32(0x78e540u+0x84u)==0x505da0u);eax=m.r32(member+0x5a8u);++o.type_calls;need(eax==item&&m.r32(eax+0x52cu)==0u);++o.member_reads;member=m.r32(member+0x4c8u);}while(member);
 m.w8(i.cx+0x80u,1u);++o.completion_marks;return eax;
}
}
