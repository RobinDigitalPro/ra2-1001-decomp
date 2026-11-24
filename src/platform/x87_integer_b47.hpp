#pragma once
#include "platform/x87_state.hpp"
namespace ra2::platform::x87_integer_b47 {
using ra2::platform::x87::State;using ra2::platform::x87::Image;using ra2::platform::x87::Raw80;
#define B47_CLOBBERS "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"
inline void subtract_integer32(State& state,std::uint32_t operand){state.require_masked();Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfisubl %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes):[operand]"m"(operand):B47_CLOBBERS);
}
inline Raw80 pop80(State& state){state.require_masked();Image host;Raw80 output;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfstpt %[output]\n\tfnsave %[guest]\n\tfrstor %[host]"
        :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes),[output]"=m"(output.bytes)::B47_CLOBBERS);
    return output;
}
#undef B47_CLOBBERS
}
