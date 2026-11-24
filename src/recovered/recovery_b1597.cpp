#include "recovered/recovery_b1597.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1597 {
namespace{void need(bool v){if(!v)throw std::domain_error("B1597 existingcountdown plus genuineAir classifier route");}}
U fun_006043a0(Memory&m,const Inputs&i){
 const U self=i.cx;need(self&&m.r8(self+0xe4)!=0&&m.r32(self+0xb8)==1);
 const U table=m.r32(self+0xac),p=m.r32(table),t=m.r32(p+0x98),air=m.r32(self+0xcc);
 struct Span{U at,size;};const std::array<Span,6>spans{{{self,0xe8},{table,4},{p,0x128},{t,0x2e8},{air,0x5b0},{0x786000,4096}}};
 for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.at&&std::uint64_t(a.at)+a.size<=0x100000000ull);(void)m.r8(a.at);(void)m.r8(a.at+a.size-1);for(U k=0;k<j;++k)need(std::uint64_t(a.at)+a.size<=spans[k].at||std::uint64_t(spans[k].at)+spans[k].size<=a.at);}
 need(m.r32(t+0x2e4)>4&&m.r8(p+0x121)==0);const U before=m.r16(p+0x118);need(before>=2);
 need(m.r32(air)==0x78612c&&m.r32(0x78612c+0x2c)==0x41b580&&m.r8(air+0x7d)!=0&&m.r32(air+0x228)==0);
 // Actual201870 default countdown has the same byte-bound public effect as B1596.
 m.w16(p+0x118,before-1u);
 // Actual202000 kinds>4 reaches its original default epilogue without x87 or stores.
 // ActualDC20 invokes authentic Air+2C=41B580 full2; table byte[40DC55]=0
 // chooses40DC41 and returns Air. No synthesized virtual callback is used.
 // Air7D/228 and public initializedE4 select the remaining original epilogue.
 return m.r8(self+0xe4);
}
}
