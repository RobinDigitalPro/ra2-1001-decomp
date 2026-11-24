#include "recovered/recovery_b451.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b451 {
namespace {
using U=std::uint32_t;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
std::uint64_t read64(Memory&m,U a){return std::uint64_t(m.r32(a))|(std::uint64_t(m.r32(a+4))<<32);}
U convert(Memory&m,ra2::platform::x87::State&fp){
 const auto cw=m.r32(0x7c3a04);
 if(fp.control()!=cw)fp.load_control(std::uint16_t(cw));
 return U(fp.pop_integer64());
}
U volume(Memory&m,const Inputs&i,bool secondary){
 need((i.arg[1]&255u)==0,"B451 no immediate playback requested");
 auto&fp=i.fp;fp.load32(i.arg[0]);fp.compare_pop64(read64(m,0x785708));
 if(fp.status()&0x100u)fp.load32(i.arg[0]);else fp.load64(read64(m,0x785708));
 const auto field=i.cx+(secondary?0x30u:0x34u);
 m.w32(field,fp.store32());
 if(secondary){
  fp.multiply64(read64(m,0x78df50));const auto level=convert(m,fp);
  m.w32(0x7e3438,std::int32_t(level)<255?level:255u);
  fp.load32(m.r32(field));
 }
 fp.multiply32(m.r32(0x79276c));const auto scaled=convert(m,fp);
 const auto control=m.r32(secondary?0x819790u:0x819794u);
 need(control!=0,"B451 initialized volume-control object");
 const auto flags=m.r32(control)|1u;
 m.w32(control,flags);m.w32(control+8,scaled<<16);
 // MOV AL,[arg1] follows the original control helper. The log helper is RET.
 const auto result=flags&0xffffff00u;
 fp.load32(m.r32(field));(void)fp.pop64();
 return result;
}
}
std::uint32_t fun_005d1010(Memory&m,const Inputs&i){return volume(m,i,false);}
std::uint32_t fun_005d1120(Memory&m,const Inputs&i){return volume(m,i,true);}
std::uint32_t fun_006dd0e0(Memory&m,const Inputs&i){
 need(m.r8(0xa28858)!=0&&m.r32(0x819778)!=0&&m.r8(0xa2894c)==0,"B451 enabled initialized playback control");
 const auto requested=i.arg[0];need(requested!=0xffffffffu&&requested!=0xfffffffeu&&requested!=m.r32(i.cx+4),"B451 changed valid selection");
 m.w32(i.cx+8,requested);
 const auto control=m.r32(i.cx+0x2c);need(control!=0,"B451 nonnull control");
 need((m.r32(control+0xc)&1u)!=0,"B451 active control flag");
 const auto inner=m.r32(control+0x14);need(inner!=0,"B451 initialized inner control");
 need(m.r32(inner+0x14)!=m.r32(inner+0x18),"B451 existing transition avoids timer restart and stop calls");
 const auto result=m.r32(inner+0x18);
 m.w32(inner+0x10,m.r32(inner+0x10)&~1u);m.w32(inner+0x18,0);
 m.w8(i.cx+0x11,1);
 return result;
}
}
