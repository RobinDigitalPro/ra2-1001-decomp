#include "recovery_b504.hpp"
#include "numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b504 {
namespace {
using U=std::uint32_t;using namespace floating_b61;namespace d=numeric_b88::detail;
U nearest(Memory&m,const Inputs&i,U x,U y,U alternate,U excluded){
 U best=0,distance=0,p=m.r32(i.cx+(alternate?0xe8:0xe4));unsigned visits=0;
 auto&f=i.fp;
 for(;p;p=m.r32(p+0x30)){
  if(++visits>16)throw std::domain_error("504 bounded linked list");
  if(!(m.r8(p+0x14)&1)||p==excluded)continue;
  // Constructor FEB40's actual vptr and immutable slot48 identify 5CD4D0.
  if(m.r32(p)!=0x78e540||m.r32(0x78e588)!=0x5cd4d0)throw std::domain_error("504 authentic coordinate getter");
  const U dx=(m.r32(p+0x88)&255)-7*x,dy=(m.r32(p+0x8c)&255)-7*y;
  f.load_integer32(dy);f.load_integer32(dx);d::reg<0xd9c0>(f);d::reg<0xd8c9>(f);
  d::reg<0xd9c2>(f);d::reg<0xd8cb>(f);d::reg<0xdec1>(f);
  const auto squared=f.pop64();f.pop_st0();f.pop_st0();
  d::root(m,f,squared);const U v=d::integer(m,f);
  if(!best||s32(v)<s32(distance)){best=p;distance=v;}
 }
 return best;
}
}
std::uint32_t fun_00471260(Memory&m,const Inputs&i){
 return nearest(m,i,m.r32(i.arg[0]),m.r32(i.arg[0]+4),i.arg[1]&255,i.arg[2]);
}
std::uint32_t fun_00479e90(Memory&m,const Inputs&i){
 if((m.r8(0x838f70)&7)!=7||m.r8(i.cx+0x11c)||m.r8(0xa285a8))
  throw std::domain_error("504 warm flat-cell height with ordinary occupants");
 auto&f=i.fp;f.load_integer32(U(std::int32_t(std::int8_t(m.r8(i.cx+0x11b))))*m.r32(0x838f80));
 f.add64(read64(m,0x785728));const U height=d::integer(m,f);
 return height+(nearest(m,i,0,0,0,0)?85u:0u);
}
}
