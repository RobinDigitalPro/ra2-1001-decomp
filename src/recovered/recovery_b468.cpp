#include "recovery_b468.hpp"
#include "numeric_b105.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b468 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U valid(Memory&m,U h){
 need(h&&m.r32(0x8192f8)&&m.r32(h+12)==0x8192ec,"468 initialized live audio handle");
 const U s=m.r32(h);need(s&&m.r32(h+8)==m.r32(s+0x24)&&m.r32(h+4)==m.r32(s+0x138),"468 compatible current sample identity");return s;
}
U convert(Memory&m,platform::x87::State&fp){const auto cw=std::uint16_t(m.r32(0x7c3a04));if(fp.control()!=cw)fp.load_control(cw);return U(fp.pop_integer64());}
U attenuation(Memory&m,const Inputs&i,U coord,U spec,U&pan){
 std::array<std::uint8_t,16>scratch{};constexpr U base=0x5f400000;leaf::Memory span(scratch.data(),base,16);Memory scoped=m;scoped.add(span);
 Inputs c=i;c.cx=coord;c.dx=base;c.arg[0]=spec;
 (void)numeric_b105::fun_00708af0(scoped,c);i.fp=c.fp;pan=scoped.r32(base);return c.ax;
}
void update(Memory&m,U s,U h,U spec,U level,U pan){
 need(m.r32(s+0x1c)!=3&&level<=0x4000&&pan<=0x4000,"468 immediate controls, bounded volume/pan");
 const U volume=((m.r32(spec+0x1c)>>16)*level)>>14,p=s+0xb8;
 const U target=volume<<16;U flags=m.r32(p)|1;m.w32(p,flags);m.w32(p+8,target);
 if(m.r32(p+4)!=target){m.w32(p+4,target);m.w32(p,flags|2);}
 m.w32(s+0x108,m.r32(s+0x108)|1);m.w32(s+0x110,pan<<16);
 // Original6100 refreshes both sides of the live sample handle.
 m.w32(h,s);m.w32(h+8,spec);m.w32(h+4,m.r32(s+0x138));m.w32(s+0x278,h);
}
}
std::uint32_t fun_00404790(Memory&m,const Inputs&i){
 const U p=i.cx,o=m.r32(p+0x24);
 need(o&&m.r32(o+0x58)<0x21&&!(m.r8(p+0x18)&0x20)&&!(m.r32(o+0x10)&2)&&m.r32(p+0x1e0)>0,"468 positive sequential sample queue");
 const U next=m.r32(p+0xac)+1;need(next<8,"468 bounded queue index");
 m.w32(p+0xac,next);m.w32(p+0x1e0,m.r32(p+0x1e0)-1);
 return m.r32(p+0x28+4*next)+0x1c;
}
std::uint32_t fun_00708a20(Memory&m,const Inputs&i){
 need(s32(i.cx)>=0&&i.cx<m.r32(0xab82a8),"468 valid audio resource index");
 const U spec=m.r32(m.r32(m.r32(0xab829c)+4*i.cx)),h=i.arg[0],s=valid(m,h);
 need(spec&&m.r32(s+0x24)==spec,"468 resource matches current sample");
 U pan=0;(void)attenuation(m,i,i.dx,spec,pan);i.arg[0]=pan;
 i.fp.compare32(m.r32(0x785738));need(!(i.fp.status()&0x4100),"468 strictly positive attenuation");
 i.fp.multiply32(m.r32(0x79276c));U level=convert(m,i.fp);if(level>=0x4000)level=0x4000;
 update(m,s,h,spec,level,pan);return s;
}
std::uint32_t fun_00708d70(Memory&m,const Inputs&i){
 const U h=i.dx,s=valid(m,h),spec=m.r32(h+8);U pan=0;
 (void)attenuation(m,i,i.cx,spec,pan);const U attenuation_bits=i.fp.store32();
 i.fp.compare_pop32(m.r32(0x785738));need(!(i.fp.status()&0x4100),"468 positive attenuation refresh");
 i.fp.load32(attenuation_bits);i.fp.multiply32(m.r32(0x79276c));U level=convert(m,i.fp);if(level>=0x4000)level=0x4000;
 update(m,s,h,spec,level,pan);return s;
}
}
