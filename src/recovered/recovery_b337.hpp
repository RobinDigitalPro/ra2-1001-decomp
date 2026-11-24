#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b337 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// Static finite route for one row, three absent keys, and an existing
// one-section INI receiver with an empty capacity-32 key index.
std::uint32_t fun_002c5d0(Memory&, const Inputs&, Heap&);
}
