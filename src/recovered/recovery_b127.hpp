#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b127 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// RVA 0x8760 / VA 0x408760. The one-node/null-descriptor contract is recorded
// in the private fixture and review notes alongside this draft.
std::uint32_t fun_00408760(Memory&, const Inputs&, Heap&);
}
