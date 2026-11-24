#include "recovered/recovery_b1528.hpp"
#include "platform/observed_timer1528.hpp"
#include <stdexcept>
namespace ra2::recovered::b1528 {
std::uint32_t fun_006e07a0(Memory& m,const Inputs& i){
    auto need=[](bool v){if(!v)throw std::runtime_error("B1528 outside frozen ownedtimer clear domain");};
    need(m.r8(i.cx+0xcu)==1u && m.r32(i.cx)==0x007987dcu && m.r32(0x007987e4u)==0x006e1050u && m.r32(i.cx+4u)!=0u);
    auto message=m.r32(i.arg[0]+4u);need(message==0x201u||message==0x202u||message==0x204u||message==0x205u||message==0x207u||message==0x208u);
    need(m.r32(0x007854c4u)==platform::timer1528::address());
    const auto hwnd=m.r32(i.cx+8u);need(hwnd);
    need(platform::timer1528::guest_kill(hwnd,i.fp.image)!=FALSE);
    // Actual authenticated7987DC+8 -> 6E1050: all20 bytes, orderedstores.
    m.w32(i.cx+0x18u,0u);m.w32(i.cx+0x1cu,0u);m.w32(i.cx+0x20u,0u);m.w32(i.cx+0x24u,0u);m.w32(i.cx+4u,0u);return 0u;
}
}
