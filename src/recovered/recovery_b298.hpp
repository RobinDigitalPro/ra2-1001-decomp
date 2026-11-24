#pragma once

#include "platform/ordinary_heap.hpp"
#include "recovered/global_b26_memory.hpp"

#include <cstdint>

// Finite owned-storage cleanup models for pinned original RVAs 0x10fc10,
// 0x10adf0 and 0x10ad20. These are instruction-derived memory effects, not
// source-level class or destructor claims.
namespace ra2::recovered::recovery_b298 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using OrdinaryHeap = ra2::platform::ordinary_heap::Heap;

std::uint32_t fun_0010fc10(Memory&, const Inputs&, OrdinaryHeap&);
std::uint32_t fun_0010adf0(Memory&, const Inputs&, OrdinaryHeap&);
std::uint32_t fun_0010ad20(Memory&, const Inputs&, OrdinaryHeap&);
} // namespace ra2::recovered::recovery_b298
