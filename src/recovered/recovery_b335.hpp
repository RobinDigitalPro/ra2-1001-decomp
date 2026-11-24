#pragma once

#include "recovered/global_b26_memory.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b335 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;

// Bounded useful lookup route of RVA 0x2c3d0: a two-entry raw collection,
// query matches entry 1, and its exact nested guard returns false before any
// indirect/helper call. Full EAX is the matching index (1), RET cleanup 4.
std::uint32_t fun_0042c3d0(Memory&, const Inputs&);
}
