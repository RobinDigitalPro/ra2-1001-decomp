#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b904 {
using global_b26::Inputs;
using global_b26::Memory;
using platform::ordinary_heap::Heap;
std::uint32_t fun_007486b0(Memory&, const Inputs&, Heap&);
}
