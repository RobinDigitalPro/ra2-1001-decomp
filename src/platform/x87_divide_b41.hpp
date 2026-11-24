#pragma once
// Prospective elementary operation only; independent primitive proof remains required.
#include "platform/x87_state.hpp"
namespace ra2::platform::x87_divide {
inline void divide_st0_st1(ra2::platform::x87::State& state){
    state.require_masked();ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte 0xd8,0xf1\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes) :
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
