#pragma once

#include "recovered/heap_b29_memory.hpp"

namespace ra2::recovered::recovery_b862 {
using Memory = ra2::recovered::heap_b29::Memory;
using State = ra2::recovered::heap_b29::State;
using Operations = ra2::recovered::heap_b29::Operations;

// Bounded translation of original RVA 0x271940's fixed global cleanup route.
// No UI class identity or ownership beyond the explicit per-flag pointer
// contract is asserted.
std::uint32_t fun_00671940(Memory&, const Operations&);
}
