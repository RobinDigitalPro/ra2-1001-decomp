#include "recovery_b1364.hpp"
#include <stdexcept>
namespace ra2::recovered::b1364 {
namespace {using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
U fun_005b76d0(Memory&m,const Inputs&){
 need(m.r32(0xa27da0u)==1&&m.r32(0x821cc0u)==0xffffffffu,"1364 local-only first registry and paused clock");
 const U count=m.r32(0xa27d88u),now=m.r32(0x821cc8u),list=m.r32(0xa27d7cu);
 need(count>=2&&count<=4&&now>=1&&now<=0x7fffffffu,"1364 nonempty pending suffix and positive timestamp");
 for(U index=1;index<count;++index){
  const U record=m.r32(list+4*index);need(m.r32(record+0x32u)==0,"1364 genuinely unstamped pending record");
  m.w32(record+0x32u,now);
  // Both following original age calculations read the just-produced stamp;
  // now-stamp is0, so release/notification thresholds are not reached.
 }
 return m.r32(0xa27d88u);
}
U fun_0053e7b0(Memory&m,const Inputs&){
 need(m.r32(0x821cd0u)==0xffffffffu&&m.r32(0x821cd8u)>=1&&m.r32(0x821cd8u)<=0x7fffffffu,"1364 paused positive countdown");
 need(m.r32(0xa255c8u)==1&&m.r32(0x821cb0u)==0xffffffffu&&m.r32(0x821cb8u)==0,"1364 selected session mode and completed independent wait timer");
 need((m.r8(0xa56761u)&1u)!=0&&m.r32(0xa56790u)==0xffffffffu&&m.r32(0xa56798u)==1,"1364 initialized unexpired statistics timer");
 m.w32(0xa27f68u,m.r32(0xa27f68u)+m.r32(0x821cd8u));
 // Original loads the7851E4 import pointer, but its completed wait timer
 // branches past every call. No import or fabricated time provider executes.
 (void)m.r32(0x7851e4u);return m.r32(0xa56790u);
}
U fun_006db310(Memory&m,const Inputs&i){
 need(m.r32(i.cx+0x2cu)==1&&m.r32(i.cx+0x34u)==0xffffffffu&&i.arg[0]==1&&i.arg[2]!=0,"1364 matching mode1 event with explicit wildcard and present borrowed actor");
 // Unsigned(mode-0D)>26 goes directly to the default comparison chain.
 // Wildcard-1 bypasses the owner lookup and actor vcall; successful matching
 // publishes the output byte. The output pointer supplies physical EAX high24.
 m.w8(i.arg[4],1);return (i.arg[4]&0xffffff00u)|1u;
}
}
