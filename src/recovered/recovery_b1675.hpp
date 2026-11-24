#pragma once

#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::b1675 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Finite positive source model for the selected 0x5b6f00 route.
std::uint32_t fun_005b6f00(Memory&, const Inputs&, Heap&);
}
