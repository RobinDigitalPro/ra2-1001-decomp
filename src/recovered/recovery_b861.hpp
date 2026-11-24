#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b861 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

// Finite interface-compatible contract: 0x1fa230 resets the embedded vector,
// grows its empty 24-byte vector through the original ordinary-heap contract,
// and appends 1..4 records whose string-pointer fields are null. No nominal
// class identity is asserted. Nonempty string ownership is outside this route.
std::uint32_t fun_005fa230(Memory&, const Inputs&,
                           ra2::platform::ordinary_heap::Heap&);
}
