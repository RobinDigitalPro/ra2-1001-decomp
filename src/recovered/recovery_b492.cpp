#include "recovered/recovery_b492.hpp"
#include "recovered/codec_b78.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b492 {
namespace {
using U=std::uint32_t;
U decode(Memory&m,const Inputs&i,bool packed){
 const U self=i.cx,raw=m.r32(self+20),out=m.r32(self+24);
 if(m.r32(self+12)!=1||m.r32(self+4)!=0)throw std::runtime_error("492 requires terminal decoding pipe");
 U source=i.arg[0],left=i.arg[1];i.arg[0]=0;
 auto copy=[&](U dest,U count){for(U k=0;k<count;++k)m.w8(dest+k,m.r8(source+k));source+=count;left-=count;};
 while(left){
  if(m.r16(self+36)==0xffff){
   const U held=m.r32(self+16),count=std::min(left,4-held);copy(raw+held,count);m.w32(self+16,held+count);
   if(held+count==4){m.w32(self+36,m.r32(raw));m.w32(self+16,0);}
  }
  if(!left)break;
  const U held=m.r32(self+16),compressed=m.r16(self+36),count=std::min(left,compressed-held);
  copy(raw+held,count);m.w32(self+16,held+count);
  if(held+count==compressed){
   Inputs nested{};nested.cx=raw;nested.dx=out;nested.arg[0]=0;
   if(packed){
    std::array<std::uint8_t,4> scratch{};leaf::Memory local(scratch.data(),0x7c200000u,4);Memory view=m;view.add(local);
    nested.dx=compressed;nested.arg[0]=out;nested.arg[1]=0x7c200000u;nested.arg[2]=0;
    i.arg[1]=4;codec_b78::fun_0053cb50(view,nested);i.arg[1]=view.r32(nested.arg[1]);
   }else codec_b78::fun_00532db0(m,nested);
   // Original terminal2066d0 returns the declared output count.
   i.arg[0]+=m.r16(self+38);m.w32(self+16,0);m.w16(self+36,0xffff);
  }
 }
 return i.arg[0];
}
}
std::uint32_t fun_005331f0(Memory&m,const Inputs&i){return decode(m,i,false);}
std::uint32_t fun_0053cdc0(Memory&m,const Inputs&i){return decode(m,i,true);}
}
