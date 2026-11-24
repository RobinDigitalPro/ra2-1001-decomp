#include "recovery_b488.hpp"
#include "global_b60_b.hpp"
#include "pixels_b72.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b488 {
std::uint32_t fun_0042b670(Memory&m,const Inputs&i){
 using U=std::uint32_t;U self=i.cx,source=i.arg[0],remain=i.arg[1],total=0;
 const bool decode=m.r32(self+12)!=0;const U unit=decode?4:3,outsize=decode?3:4,raw=self+(decode?20:24),output=self+(decode?24:20);
 if(!source||remain<unit||remain>64||m.r32(self+4)!=0||m.r32(self+16)>=unit)throw std::domain_error("488 bounded terminal Base64 pipe");
 i.arg[0]=outsize; // Root's [ESP+20] is caller argument0 after its saved registers.
 auto convert=[&](U from){
  Inputs child{};child.cx=from;child.dx=unit;child.arg[0]=output;child.arg[1]=outsize;
  U count=decode?pixels_b72::fun_0042d640(m,child):global_b26::fun_0042d520(m,child);
  // Exact2066d0 terminal pipe route returns the converted count unchanged.
  total+=count;
 };
 U held=m.r32(self+16);
 if(held){
  U copied=std::min(unit-held,remain);for(U k=0;k<copied;++k)m.w8(raw+held+k,m.r8(source+k));
  source+=copied;remain-=copied;held+=copied;m.w32(self+16,held);i.arg[1]=remain;
  if(held==unit){convert(raw);m.w32(self+16,0);}
 }
 while(remain>=unit){convert(source);source+=unit;remain-=unit;i.arg[1]=remain;}
 if(remain){for(U k=0;k<remain;++k)m.w8(raw+k,m.r8(source+k));m.w32(self+16,remain);}
 return total;
}
}
