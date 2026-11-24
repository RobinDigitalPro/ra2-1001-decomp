#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b812 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Bounded route for original RVA 0x1C25A0: all six destination globals are
// null, and all six source globals name nonnull, terminated UTF-16 strings.
std::uint32_t run(Memory&, const Inputs&, Heap&);
}
