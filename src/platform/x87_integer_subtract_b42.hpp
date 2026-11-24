#pragma once
#include "platform/x87_state.hpp"
namespace ra2::platform::x87_integer_subtract {
inline void subtract_integer32(ra2::platform::x87::State& state,std::uint32_t operand){
    state.require_masked();ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfisubl %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes) : [operand]"m"(operand)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
