#include "recovery_b1353.hpp"
#include "recovered/recovery_b453.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1353 {
namespace {using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void pump(Memory&m){need(m.r32(0x8197ac)==0&&m.r32(0x819778)==0&&m.r32(0xa255c8)==0,"B1353 exact disabled406EA0 andmodezero4821E0 prefixes");}
void fill(Memory&original,U wrapper,U color){
 constexpr U temp=0x7c200000;std::array<std::uint8_t,64> bytes{};leaf::Memory span(bytes.data(),temp,bytes.size());Memory m=original;m.add(span);
 const U surface=m.r32(wrapper+0x14),width=m.r32(wrapper+0x28),height=m.r32(wrapper+0x2c),vt=m.r32(surface);
 need(vt==0x785ef8&&m.r32(vt+0x14)==0x75fcd0&&m.r32(vt+0x78)==0x411290,"B1353 genuine wrapper->surface+14->rectangle+78 chain");
 need(width==32&&height==24&&m.r32(surface+4)==width&&m.r32(surface+8)==height&&m.r32(surface+16)==1,"B1353 compatible full32x24 indexed surface");
 // 761AA0/411050 produce origin fromwrapper dimensions;75FCD0 calls
 // genuine411290, which writes originzero andsurface4/8 into secondrect.
 m.w32(temp,0);m.w32(temp+4,0);m.w32(temp+8,width);m.w32(temp+12,height);
 m.w32(temp+16,0);m.w32(temp+20,0);m.w32(temp+24,m.r32(surface+4));m.w32(temp+28,m.r32(surface+8));
 surface_b453::Inputs child{};child.cx=surface;child.arg[0]=temp;child.arg[1]=temp+16;child.arg[2]=color&0xffff;
 (void)surface_b453::fun_0075fd00(m,child);
 // Child callerword changes remain in the actual private call frame.
}
}
U fun_00545750(Memory&m,const Inputs&i){
 const U self=i.cx;pump(m);fill(m,m.r32(0x821fac),0xffff);fill(m,m.r32(0x8198f4),0x7f);pump(m);
 m.w32(self+0xc,2);pump(m); // exact4E0010 store, both4068F0loggercalls areRET
 const U epoch=m.r32(0xa2896c),reload=m.r32(0xa56e5c);U eax=0;
 need(m.r32(self+0x1144)==0xffffffff,"B1353 lastinactive record pins full final EAX");
 for(U k=0;k<256;++k){const U p=self+0x154+16*k,start=m.r32(p);eax=reload;m.w32(p+12,reload);
  if(start!=0xffffffff){eax=m.r32(p+8);const U elapsed=epoch-start;
   eax=global_b26::s32(elapsed)>=global_b26::s32(eax)?0:eax-elapsed;m.w32(p+8,eax);m.w32(p,0xffffffff);}
 }
 m.w32(self+0x144,13);m.w8(self+0x1154,0);return eax;
}
}
