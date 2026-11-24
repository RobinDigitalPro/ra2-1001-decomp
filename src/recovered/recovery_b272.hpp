#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b272 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::ordinary_heap::Heap;

// Finite reviewed route for original RVA 0x320f70 only.
std::uint32_t fun_00720f70(Memory&, const Inputs&, Heap&);
}
