#pragma once
#include "platform/x87_state.hpp"
namespace ra2::platform::map_adjust1044_fp {
// Elementary FIMUL with explicit guest state, preserving host numeric state.
// This is ordinary owned platform code, not an original helper invocation.
inline void multiply_integer32(x87::State&s,std::uint32_t value){s.require_masked();x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[value]\n\tfnsave %[guest]\n\tfrstor %[host]" : [host]"=m"(host.bytes),[guest]"+m"(s.image.bytes) : [value]"m"(value) : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
}
