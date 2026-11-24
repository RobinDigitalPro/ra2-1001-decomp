#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b133 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// RVA 0x1b900 / VA 0x41b900. Bounded empty-header reserve route.
std::uint32_t fun_0041b900(Memory&, const Inputs&, Heap&);
}
