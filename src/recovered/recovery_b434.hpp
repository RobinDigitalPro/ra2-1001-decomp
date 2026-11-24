#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b434 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::ordinary_heap::Heap;

// RVA 0x282ee0, VA 0x682ee0.  Finite positive route: initialized 512-bucket
// table, ordinary-heap-owned old buckets, authentic 0x6814e0 callback, and a
// 256-bucket successful shrink.  Original RET has no callee cleanup.
std::uint32_t fun_00682ee0(Memory&, const Inputs&, Heap&);
} // namespace ra2::recovered::recovery_b434
