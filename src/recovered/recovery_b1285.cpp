#include "recovery_b1285.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1285 {
std::uint32_t fun_00470cd0(Memory&m,const Inputs&i){
 auto require=[](bool q,const char*s){if(!q)throw std::domain_error(s);};
 require(m.r8(0xa285a8u)!=0u&&m.r32(i.cx+0xe4u)==0u,"1285 empty real Cell object search");
 require((m.r32(i.cx+0x140u)&0x100u)==0u,"1285 ordinary tile color");
 const auto tile=m.r32(i.cx+0x38u);require(tile<4u,"1285 ordinary tile index");
 (void)m.r32(0xa3ab38u);const auto type=m.r32(m.r32(0xa28914u)+4u*tile);
 require(m.r32(type+0x2c0u)==1u&&m.r32(type+0xa4u)!=0u,"1285 singleton variant and loaded cache");
 const auto subtile=m.r8(i.cx+0x11au),height=m.r8(i.cx+0x11bu);
 require(subtile<8u&&height<8u,"1285 finite subtile and nonnegative height");
 m.w8(i.arg[0],0u);
 //527780(variant0) returns type.52C5F0 indexes the populated pointer rows.
 const auto row=m.r32(m.r32(type+0x278u)+4u*subtile),color=row+4u*height;
 return (unsigned(m.r16(color))<<16u)|unsigned(m.r16(color+2u));
}
}
