#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b199 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;
std::uint32_t fun_004d0b50(Memory&, const Inputs&, Heap&);
} // namespace ra2::recovered::recovery_b199
