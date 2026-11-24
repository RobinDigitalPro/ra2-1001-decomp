#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b805 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Private finite-route proposal for original RVA 0x1c2bf0.
std::uint32_t run(Memory&, const Inputs&, Heap&);
}
