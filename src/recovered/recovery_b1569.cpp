#include "recovered/recovery_b1569.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1569 {namespace {using U=std::uint32_t;void need(bool x){if(!x)throw std::domain_error("1569 finitegenuineAirTypeindex0/nogrowth");}U type(Memory&m,const Inputs&i){const U air=i.arg[0];need(air&&m.r32(air)==0x78612cu&&m.r32(0x786158u)==0x41b580u&&m.r32(0x7861acu)==0x6b6910u&&m.r32(0x7861b0u)==0x41b600u);const U t=m.r32(air+0x5acu);need(t&&m.r32(t)==0x786678u&&m.r32(0x7866b8u)==0x41c330u&&m.r32(t+0xb90u)==0);return t;}U inc(Memory&m,U p){need(m.r32(p+8u)==1);const U data=m.r32(p+4u);need(data&&m.r32(data)==37u);m.w32(data,38u);return 38u;}}
std::uint32_t run_ecb10(Memory&m,const Inputs&i){(void)type(m,i);return inc(m,i.cx+0x5490u);}
std::uint32_t run_e6520(Memory&m,const Inputs&i){m.w8(i.cx+0x18du,1);const U t=type(m,i);m.w32(i.cx+0x1c0u,0);const U result=inc(m,i.cx+0x54d0u);const U cfg=m.r32(0x821b88u);need(cfg&&m.r32(cfg+0x178u)==0xffffffffu&&m.r32(t+0x4b8u)==0xffffffffu);m.w8(i.cx+0x144u,1);return result;}
}
