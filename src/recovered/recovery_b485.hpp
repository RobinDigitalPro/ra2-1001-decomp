#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b485 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::ordinary_heap::Heap;
std::uint32_t fun_0042f100(Memory&, const Inputs&, Heap&);
std::uint32_t fun_0042f550(Memory&, const Inputs&, Heap&);
}
