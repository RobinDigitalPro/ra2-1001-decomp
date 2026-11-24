#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b795 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Bounded positive route for the original RVA 0x1adfb0. Only the exact
// 1-digit/1-digit/1-digit/"On" input fixture is in this draft's domain.
std::uint32_t run(Memory&, const Inputs&, Heap&);
}
