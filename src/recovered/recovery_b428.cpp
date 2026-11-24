#include "recovery_b428.hpp"
#include "crt_b83.hpp"
#include <stdexcept>
namespace ra2::recovered::selection428 {
namespace {
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
bool equal(Memory&m,unsigned a,unsigned b){Inputs p{};p.arg[0]=a;p.arg[1]=b;return crt_b83::fun_0076d860(m,p)==0;}
}
std::uint32_t fun_004f0330(Memory&m,const Inputs&i){
 const auto spec=i.arg[1],out=i.arg[0],types=m.r32(0xa1e00c),nt=m.r32(0xa1e018);
 need(nt>=1&&nt<=8&&m.r32(0xb10530)==0,"428 bounded C-locale type registry");
 need(m.r32(spec+0x1380)==0xffffffffu,"428 automatic least-grade selection mode");
 unsigned type=0;
 for(unsigned k=0;k<nt;++k){const auto t=m.r32(types+4*k);if(equal(m,t+0x24,spec+0xc20)){type=t;break;}}
 need(type!=0,"428 known positive type");
 const auto total=m.r32(0xa28748),table=m.r32(0xa2873c);need(total>=1&&total<=8,"428 bounded candidate list");
 auto best=global_b26::s32(m.r32(type+0x119c))+10;unsigned selected=0;
 for(unsigned k=0;k<total;++k){const auto c=m.r32(table+4*k);
  if(m.r32(c+0x1b4)!=i.cx||m.r32(c+0x418)!=type)continue;
  // Actual 44d5f0: owner equality, C-locale name equality, then automatic
  // mode compares signed grade with the type threshold (or permits zero).
  if(!equal(m,spec+0xc20,type+0x24))continue;
  const auto grade=static_cast<std::int8_t>(m.r8(c+0x5c6));
  const bool permitted=grade<global_b26::s32(m.r32(type+0x119c))||grade==0;
  if(permitted&&grade<best){best=grade;selected=c;}
 }
 need(selected!=0,"428 positive selected candidate");
 const auto x=global_b26::s32(m.r32(selected+0x88))/256;
 const auto y=global_b26::s32(m.r32(selected+0x8c))/256;
 const auto packed=unsigned(static_cast<std::uint16_t>(x))|(unsigned(static_cast<std::uint16_t>(y))<<16);
 m.w32(out,packed);i.arg[1]=packed;return out;
}
std::uint32_t fun_00763970(Memory&m,const Inputs&i){
 const auto owner=i.cx,info=i.dx,packet=i.arg[0],next=i.arg[1];
 const auto rate=m.r32(info+0x30);need(rate>=1&&rate<=120,"428 finite positive rate");
 need((m.r32(owner+0x150)&0x80)==0&&(m.r32(info+0x40)&4)!=0,"428 ordinary bounded clamp mode");
 need((m.r8(owner+0xea)&1)==0,"428 selected active accumulator adjustment");
 const auto limit=m.r32(next+0x1c);need(limit<1000&&i.arg[2]<1000,"428 bounded times");
 unsigned position=(rate*i.arg[2])/60u;if(m.r8(packet+4)&2)--position;
 i.arg[1]=m.r32(owner+0x12c);
 if(global_b26::s32(position)>global_b26::s32(limit)){
  const auto delta=(global_b26::s32(limit)-global_b26::s32(position))*60/static_cast<int>(rate);
  // Actual 7684a0 adds EDX to this+148, then root clamps and marks bit11.
  m.w32(owner+0x148,m.r32(owner+0x148)+unsigned(delta));
  m.w32(owner+0x150,m.r32(owner+0x150)|0x800u);return limit;
 }
 m.w32(owner+0x150,m.r32(owner+0x150)&~0x800u);return position;
}
}
