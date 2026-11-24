#include "recovery_b1346.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_004b8900(Memory&,const Inputs&);
}
namespace ra2::recovered::b1346 {
namespace {
using U=std::uint32_t;
void need(bool yes,const char* why){if(!yes)throw std::domain_error(why);}
}
U fun_006f0520(Memory& m,const Inputs& i){
    const U actor=i.cx;
    need(m.r32(actor)==0x0078612cu,"B1346 requires the original borrowed actor layout");
    need(m.r32(actor+0x228u)==0u,"B1346 target-free direction timer route");
    const U type=m.r32(actor+0x5acu);
    need(m.r8(type+0xaedu)==0u&&m.r8(type+0xaabu)==1u,"B1346 selected direction-status type flags");
    // 6F066A publishes zero before the two real active-timer predicates.
    m.w8(actor+0x599u,0u);
    global_b26::Inputs child{};child.cx=actor+0x2f8u;
    need(global_b26::fun_004b8900(m,child)==1u,"B1346 requires a positive active direction timer");
    need(m.r8(m.r32(actor+0x5acu)+0xaedu)==0u,"B1346 stable type flag");
    const U active=global_b26::fun_004b8900(m,child);
    m.w8(actor+0x599u,std::uint8_t(active));
    need(m.r8(m.r32(actor+0x5acu)+0xaabu)==1u,"B1346 stable final type flag");
    const U eax=global_b26::fun_004b8900(m,child)&0xffu;
    m.w32(actor+0x3f0u,eax);
    return eax;
}
}
