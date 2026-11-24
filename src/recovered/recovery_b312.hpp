#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b312 {
using Memory = global_b26::Memory;
using Heap = platform::ordinary_heap::Heap;

// Bounded, successful cleanup route for the exact root at RVA 0x2eea30.
// This records its pointer graph and release sequence; it makes no class claim.
std::uint32_t rva_002eea30(Memory&, Heap&);
}
