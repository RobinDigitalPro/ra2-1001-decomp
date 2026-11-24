#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

namespace ra2::recovered::recovery_b223 {
using global_b26::Inputs;
using global_b26::Memory;
using Heap = platform::small_crt_heap::Heap;

// RVA 0x1ae0a0, finite full-tuple route documented in contract.md.
std::uint32_t fun_005ae0a0(Memory&, const Inputs&, Heap&);
}
