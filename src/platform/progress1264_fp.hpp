#pragma once
#include "platform/x87_state.hpp"
namespace ra2::platform::progress1264{inline void sum_over_count(x87::State&s){s.require_masked();x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte 0xd8,0xf9\n\tfnsave %[guest]\n\tfrstor %[host]":[host]"=m"(host.bytes),[guest]"+m"(s.image.bytes)::"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}}
