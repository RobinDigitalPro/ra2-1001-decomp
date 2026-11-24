#include "recovered/recovery_b579.hpp"
#include "platform/observed_ticks152.hpp"
namespace ra2::recovered::recovery_b579{
std::uint32_t fun_005aa4c0(Memory&m,const Inputs&i){
 const auto o=i.cx,r=i.arg[3];m.w32(o+4,m.r32(r));m.w32(o+8,m.r32(r+4));m.w8(o+0xc,1);
 const auto ticks=ra2::platform::ticks152::Tick::get();m.w32(o+0x10,ticks>>4);
 m.w32(o+0x18,0);m.w32(o+0x1c,0);m.w32(o,0x791d10);m.w32(o+0x20,i.arg[1]);
 for(unsigned k=0;k<4;++k)m.w32(o+0x24+4*k,m.r32(r+4*k));m.w32(o+0x34,i.arg[2]);m.w8(o+0x38,i.arg[4]);m.w32(o,0x791db0);
 const auto text=m.r32(i.arg[0]);if(text&&m.r8(text))throw std::domain_error("579 nonempty caption needs child ownership contract");
 return o;
}}
