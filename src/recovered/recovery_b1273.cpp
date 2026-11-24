#include "recovery_b1273.hpp"
#include <stdexcept>
namespace ra2::recovered::b1273 {namespace {
void need(bool x){if(!x)throw std::domain_error("1273 nonempty genuine Team/Super inventory completion");}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 need((root==0x2b3810u||root==0x2b3a90u)&&m.r32(i.cx)==0x7977f8u&&m.r8(i.cx+0x80u)==0u&&m.r32(0xa283c4u)==0u);
 unsigned member=m.r32(i.cx+0x54u);const auto first=member;need(first!=0u);
 while(member){need(++o.members<=6u&&m.r32(member)==0x78e540u&&m.r32(member+0x4c4u)==i.cx);
  // Exact original+80 is6B6910, whose actual+84 target505DA0 reads5A8.
  need(m.r32(0x78e5c0u)==0x6b6910u&&m.r32(0x78e5c4u)==0x505da0u);o.type_callbacks+=2u;
  const auto type=m.r32(member+0x5a8u);need(m.r32(type)==0x78ea78u&&m.r32(type+0x544u)==5u);
  // True6B33D0: healthy7D1/member761/loading0 returnsfalse. Initial
  // selectedactor remainsfirst; no actor+579/kind2 ranking callback is reached.
  need(m.r8(member+0x7du)==1u&&m.r32(member+0x6cu)>0u&&m.r8(member+0x76u)==1u);++o.limbo_checks;
  member=m.r32(member+0x4c8u);
 }
 const auto house=m.r32(first+0x1b4u);need(house&&m.r32(house)==0x78dde0u&&m.r32(house+0x19cu)==0x78da24u);
 const auto n=m.r32(house+0x1acu),items=m.r32(house+0x1a0u);need(items&&n>=1u&&n<=6u&&m.r32(house+0x1a4u)==10u);
 unsigned k=0u;for(;k<n;++k){const auto object=m.r32(items+4u*k);need(object&&m.r32(object)==0x7970b8u&&m.r32(object+0x28u)==house);const auto type=m.r32(object+0x24u);need(type&&m.r32(type)==0x797160u&&m.r32(type+0xb4u)==0xffffffffu);++o.inventory_visits;}
 m.w8(i.cx+0x80u,1u);++o.completions;
 return root==0x2b3810u?i.cx:m.r32(items+4u*(n-1u)); // Actual6B3A73 reloadsTeam;6B3B18 retainslastSuperthrough6B3CD2.
}
}
