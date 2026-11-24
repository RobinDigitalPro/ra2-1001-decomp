#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b234 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// Bounded structural route: one valid cached existing section,
// capacity-32 empty key index, all 17 fixed root keys absent, real Heap.
std::uint32_t fun_00666c60(Memory&, const Inputs&, Heap&);
}
