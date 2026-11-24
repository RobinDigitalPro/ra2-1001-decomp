#include "recovery_b328.hpp"

#include <initializer_list>
#include <stdexcept>

namespace ra2::recovered::recovery_b328 {
using namespace global_b26;
namespace {
constexpr std::uint32_t callback = 0x00819898u;
void update(Memory& m, std::uint32_t p) {
    const auto end=m.r32(p+8u), cur=m.r32(p+4u);
    if (end!=cur && (m.r8(p)&1u)!=0u) {
        m.w32(p+4u,end);
        m.w32(p,m.r32(p)|2u);
    }
}
void init_control(Memory& m, std::uint32_t p, std::uint32_t scale) {
    if (m.r32(callback)!=0u)
        throw std::domain_error("0x24a0 draft only models the null 0x4092d0 callback route");
    m.w32(p,0u);             // 0x7030 clears the control flags before the callback
    m.w32(p+0x18u,0u);       // null callback returns EAX=0
    m.w32(p,m.r32(p)|1u);
    m.w32(p+0x10u,1000u);
    m.w32(p+8u,scale<<16);
    m.w32(p+0x1cu,0u);       // null callback returns EDX=0
    m.w32(p+0x0cu,0x0010624du);
    m.w32(p+0x14u,0u);
    update(m,p);             // tail route through 0x4070f0
}
void set_rate(Memory& m,std::uint32_t p,std::uint32_t rate) {
    m.w32(p+0x10u,1000u);
    m.w32(p+0x0cu,(rate<<16)/1000u);
    m.w32(p+0x14u,0u);
}
void set_position(Memory& m,std::uint32_t p,std::uint32_t hi) {
    m.w32(p,m.r32(p)|1u);
    m.w32(p+8u,hi<<16);
}
std::uint32_t controls_init(Memory& m,std::uint32_t p) {
    init_control(m,p,0x4000u);
    init_control(m,p+0x28u,0x64u);
    init_control(m,p+0x50u,0x2000u);
    set_rate(m,p+0x28u,0xau);
    set_rate(m,p,0x4000u);
    set_rate(m,p+0x50u,0x4000u);
    set_position(m,p,0x4000u);
    return m.r32(p);
}
}

// 0x4024a0: only the bit-8 active branch is admitted by this finite draft.
std::uint32_t fun_004024a0(Memory& m,const Inputs& i) {
    const auto p=i.cx;
    if ((m.r8(p+0xa4u)&8u)==0u) throw std::domain_error("0x24a0 inactive branch excluded");
    m.w32(p+0xa4u,m.r32(p+0xa4u)&~8u);
    m.w32(p+0x15cu,0x004022c0u);m.w32(p+0x160u,0x00402330u);m.w32(p+0x164u,0x004023f0u);
    for (auto o:{0xb0u,0xb4u,0xb8u,0xbcu,0xc0u}) m.w32(p+o,0u);
    m.w32(p+0x0cu,1u);m.w32(p+0xa8u,0u);m.w32(p+0xa4u,0u);m.w32(p+0xa0u,0u);
    const auto global=m.r32(0x00818e90u);
    m.w32(p+0x90u,0u);m.w32(p+0x94u,global);m.w32(p+0x98u,0u);m.w32(p+0x9cu,0u);
    const auto eax=controls_init(m,p+0x10u);
    m.w32(p+0x168u,0u);
    return eax;
}
}
