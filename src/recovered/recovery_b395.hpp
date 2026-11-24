#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b395 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::ordinary_heap::Heap;

// RVA 0x282f90, VA 0x682f90.  Finite positive route: initialized 256-bucket
// table, ordinary-heap-owned old buckets, authentic 0x6814e0 callback, and a
// 512-bucket successful growth.  Original RET has no callee cleanup.
std::uint32_t fun_00682f90(Memory&, const Inputs&, Heap&);
} // namespace ra2::recovered::recovery_b395
