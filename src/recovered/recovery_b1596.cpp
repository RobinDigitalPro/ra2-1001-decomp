#include "recovered/recovery_b1596.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1596 {
namespace {void need(bool v){if(!v)throw std::domain_error("B1596 initialized one-particle countdown route");}}
U fun_00603c30(Memory&m,const Inputs&i){
 const U self=i.cx;need(self&&m.r8(self+0xe4)!=0&&m.r32(self+0xb8)==1);
 const U table=m.r32(self+0xac),particle=m.r32(table),type=m.r32(particle+0x98);
 struct Span{U at,size;};const std::array<Span,4>spans{{{self,0xe8},{table,4},{particle,0x128},{type,0x2e8}}};
 for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.at&&std::uint64_t(a.at)+a.size<=0x100000000ull);(void)m.r8(a.at);(void)m.r8(a.at+a.size-1);for(U k=0;k<j;++k)need(std::uint64_t(a.at)+a.size<=spans[k].at||std::uint64_t(spans[k].at)+spans[k].size<=a.at);}
 need(m.r32(type+0x2e4)>4&&m.r8(particle+0x121)==0);const U before=m.r16(particle+0x118);need(before>=2);
 // Actual601870 unsigned default arm performs the material public word decrement.
 // Its still-nonzero result preserves byte121, so the root performs no virtual cleanup.
 m.w16(particle+0x118,before-1u);
 // Root reloads list count1, then MOV AL,[particle+121]=0 before its final RET.
 return 0;
}
}
