#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b405 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Bounded positive all-flagged cleanup route at original RVA 0x2ea140.
std::uint32_t fun_006ea140(Memory&, const Inputs&, Heap&);
}
