#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b143 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// Private bounded draft only: ECX receiver; args are section, key, and
// category-bit mask; original RET 0xc. Caller must seed the documented
// one-section/one-prior-key graph and one matching category row.
std::uint32_t fun_0046a3c0(Memory&, const Inputs&, Heap&);
}
