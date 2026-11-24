#pragma once
// Prospective elementary operations; same masked numeric-state boundary as B39.
#include "platform/x87_state.hpp"
namespace ra2::platform::x87_scalar_b46 {
using ra2::platform::x87::State;using ra2::platform::x87::Image;
#define B46_CLOBBERS "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"
#define B46_INPUT(NAME,OP) \
inline void NAME(State& state,std::uint64_t operand){state.require_masked();Image host; \
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t" OP " %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" \
        :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes):[operand]"m"(operand):B46_CLOBBERS);}
B46_INPUT(load_integer64,"fildll")
B46_INPUT(reverse_divide64,"fdivrl")
#undef B46_INPUT
inline void multiply_pop(State& state){state.require_masked();Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte 0xde,0xc9\n\tfnsave %[guest]\n\tfrstor %[host]"
        :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)::B46_CLOBBERS);
}
#undef B46_CLOBBERS
}
