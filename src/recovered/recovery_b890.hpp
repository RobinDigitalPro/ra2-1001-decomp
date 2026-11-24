#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b890 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::ordinary_heap::Heap;

// Private candidate model for original RVA 0x124330. Contract: enabled
// receiver, successful 0xb4 allocation, and the exact nine-allocation
// positive 0x522f30 child-construction route.
std::uint32_t fun_00524330(Memory&, Inputs&, Heap&);
}
