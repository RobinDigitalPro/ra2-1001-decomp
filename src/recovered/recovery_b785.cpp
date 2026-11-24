#include "recovery_b785.hpp"
#include "recovery_b514.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b785 {
std::uint32_t fun_00474430(Memory&m,const Inputs&i){
 auto need=[](bool v,const char*w){if(!v)throw std::domain_error(w);};
 const auto owner=i.cx,type=m.r32(m.r32(0xa1e11c)+4*m.r32(owner+0x44)),source=m.r32(type+0xa4);
 need(m.r32(type)==0x7929c8&&source&&m.r32(owner+0x34),"785 original type and cached renderer required");
 need(m.r8(type+0x279)==0&&m.r8(type+0x278)==0&&m.r8(type+0x27a)==1&&m.r32(type+0x268)!=9&&m.r32(owner+0x44)==0&&(m.r8(owner+0x140)&0x80)==0,"785 bounded ordinary cell/type offsets");
 const auto height=static_cast<std::int8_t>(m.r8(owner+0x11b));need(height>=-8&&height<=-1&&m.r16(source+6)==1,"785 positive depth/frame0 domain");
 const auto point=i.arg[0],clip=i.arg[1];std::array<std::uint8_t,8>local{};leaf::Memory rect(local.data(),0x35000000u,8);Memory env=m;env.add(rect);
 env.w32(0x35000000u,m.r32(point)+30-m.r32(clip));env.w32(0x35000004u,m.r32(point+4)+m.r32(0x821974)+3-15*height-m.r32(clip+4));
 i.arg[0]&=0xffffff00u;Inputs child{};child.cx=m.r32(0x821c9c);child.dx=m.r32(owner+0x34);child.arg={source,0,0x35000000u,clip,0x4601,0,std::uint32_t(-2-15*height),0,1000,0,0,0,0,0,0,0};child.fp=i.fp;
 const auto result=recovery_b514::fun_0049ebd0(env,child);i.fp=child.fp;return result;
}
}
