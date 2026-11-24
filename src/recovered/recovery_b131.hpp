#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b131 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// RVA 0x8890 / VA 0x408890. ECX points to the root in Memory; only its
// single caller-provided list node is an ordinary-heap allocation.
std::uint32_t fun_00408890(Memory&, const Inputs&, Heap&);
}
