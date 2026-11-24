#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b115 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Finite successful ordinary-heap routes; see analysis/block115_contracts.json for domains.
std::uint32_t fun_005fa080(Memory&, const Inputs&, Heap&);
std::uint32_t fun_00752f10(Memory&, const Inputs&, Heap&);
std::uint32_t fun_007542b0(Memory&, const Inputs&, Heap&);
} // namespace ra2::recovered::recovery_b115
