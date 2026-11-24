#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b889 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::ordinary_heap::Heap;

// Private candidate model for original RVA 0x124280. The bounded contract is
// a successful positive child creation with the exact nested 0x122f30 recipe.
std::uint32_t fun_00524280(Memory&, Inputs&, Heap&);
}
