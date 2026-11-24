#include "recovery_b1297.hpp"
#include "recovery_b338.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b1297 {
std::uint32_t fun_0060ef20(Memory&m,const Inputs&i){
 auto need=[](bool q,const char*s){if(!q)throw std::domain_error(s);};
 const auto current=m.r32(0xa5e2e4u),previous=m.r32(0xa5e250u);
 need(m.r8(0xa5e2fcu)&&current&&current!=previous,"1297 changed active hover");
 std::array<std::uint8_t,64> bytes{};leaf::Memory locals(bytes.data(),0x7d200000u,64u);Memory view=m;view.add(locals);
 Inputs box=i;box.cx=current;box.arg[0]=0x7d200000u;(void)recovery_b338::fun_00608f40(view,box);i.fp=box.fp;
 //Exact60A150 positive delta4 route followed by6124C0 signed half-open test.
 const auto x=std::int32_t(locals.r32(0x7d200000u)-4u),y=std::int32_t(locals.r32(0x7d200004u)-4u);
 const auto width=std::int32_t(locals.r32(0x7d200008u)+8u),height=std::int32_t(locals.r32(0x7d20000cu)+8u);
 const auto px=std::int32_t(i.arg[0]),py=std::int32_t(i.arg[1]);
 need(px>=x&&px<x+width&&py>=y&&py<y+height,"1297 genuine point-inside route");
 need(m.r32(0x81a820u)==0x785954u&&m.r32(0x7859a0u)==0x59c040u,"1297 original Map slot");
 m.w32(0x81f754u,0u);
 need(m.r32(0x7cd5dcu)!=0xffffffffu&&m.r8(0xa58bbdu)&&m.r32(0xa58b7cu)&&m.r32(0x81f750u)==0u&&m.r8(0x81f74cu)==1u,"1297 real same-cursor cache");
 m.w32(0xa5e250u,current);i.arg[0]=current;return 1u;
}
}
