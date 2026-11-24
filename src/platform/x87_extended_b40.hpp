#pragma once
// Elementary x87 operations. Host numeric state is restored after each guest operation.
#include "platform/x87_state.hpp"
namespace ra2::platform::x87_extended {
using ra2::platform::x87::State;using ra2::platform::x87::Image;
#define B40_CLOBBERS "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"
#define B40_REGISTER(NAME,OP) \
inline void NAME(State& state){state.require_masked();Image host; \
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t" OP "\n\tfnsave %[guest]\n\tfrstor %[host]" \
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes) : : B40_CLOBBERS);}
B40_REGISTER(multiply_st1,".byte 0xd8,0xc9")
B40_REGISTER(multiply_st2,".byte 0xd8,0xca")
B40_REGISTER(multiply_st3,".byte 0xd8,0xcb")
B40_REGISTER(multiply_st4,".byte 0xd8,0xcc")
B40_REGISTER(load_st3,".byte 0xd9,0xc3")
#undef B40_REGISTER
#define B40_INPUT(NAME,TYPE,OP) \
inline void NAME(State& state,TYPE operand){state.require_masked();Image host; \
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t" OP " %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" \
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes) : [operand]"m"(operand) : B40_CLOBBERS);}
B40_INPUT(divide32,std::uint32_t,"fdivs")
B40_INPUT(add_integer32,std::uint32_t,"fiaddl")
B40_INPUT(compare64,std::uint64_t,"fcoml")
#undef B40_INPUT
#undef B40_CLOBBERS
}
