#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b576 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;
// Original RVA 0x282140, 213-byte RET 8 standalone root.
std::uint32_t fun_00682140(Memory&, Inputs&, Heap&);
} // namespace ra2::recovered::recovery_b576
