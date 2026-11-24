#pragma once
#include "platform/x87_state.hpp"
namespace ra2::platform::build_time1217{
#define FP1217_CLOBBERS "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"
inline void integer_multiply(x87::State&s,std::uint32_t value){s.require_masked();x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[value]\n\tfnsave %[guest]\n\tfrstor %[host]":[host]"=m"(host.bytes),[guest]"+m"(s.image.bytes):[value]"m"(value):FP1217_CLOBBERS);}
inline void divide_st0_st1(x87::State&s){s.require_masked();x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte 0xd8,0xf1\n\tfnsave %[guest]\n\tfrstor %[host]":[host]"=m"(host.bytes),[guest]"+m"(s.image.bytes)::FP1217_CLOBBERS);}
inline void reverse_subtract32(x87::State&s,std::uint32_t value){s.require_masked();x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfsubrs %[value]\n\tfnsave %[guest]\n\tfrstor %[host]":[host]"=m"(host.bytes),[guest]"+m"(s.image.bytes):[value]"m"(value):FP1217_CLOBBERS);}
#undef FP1217_CLOBBERS
}
