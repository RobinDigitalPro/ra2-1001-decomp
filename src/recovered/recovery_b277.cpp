#include "recovery_b277.hpp"
namespace ra2::recovered::recovery_b277 {
namespace {
// Accepted 7080 writes target and sets bit0. This guarantees the immediate
// 70f0 update branch, so the original clock/animation branch is never reached.
std::uint32_t refresh(Memory&m,std::uint32_t p){
 if(m.r32(p+4)==m.r32(p+8))return 0;
 if(!(m.r8(p)&1u))throw std::domain_error("277 requires immediate third-state refresh mode");
 m.w32(p+4,m.r32(p+8));m.w32(p,m.r32(p)|2u);return 1;
}
std::uint32_t apply(Memory&m,std::uint32_t p,std::uint32_t v){m.w32(p,m.r32(p)|1u);m.w32(p+8,v<<16);return refresh(m,p);}
}
std::uint32_t fun_004010c0(Memory&m,const Inputs&i){
 const auto dst=i.cx,src=i.dx;
 const auto first=(m.r32(dst+4)>>16)*(m.r32(src+4)>>16);
 apply(m,dst,first>>14);
 const auto product=(m.r32(dst+0x2c)>>16)*(m.r32(src+0x2c)>>16);
 // Signed IMUL high word, SAR5 and sign correction are the original /100 recipe.
 const auto high=global_b26::imul_high(0x51eb851fu,product);
 auto q=global_b26::sar(high,5);q+=q>>31;
 apply(m,dst+0x28,q);
 auto value=(m.r32(src+0x54)>>16)-0x2000u;
 if(value==0)return refresh(m,dst+0x50);
 value+=m.r32(dst+0x54)>>16;
 if(global_b26::s32(value)<0)value=0;
 else if(value>0x4000u)value=0x4000u;
 return apply(m,dst+0x50,value);
}
}
