#pragma once

#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b184 {
using global_b26::Inputs;
using global_b26::Memory;

// Bounded finite contract for original RVA 0x1afcf0.  ECX is the mutable
// collection address; caller arg0 initially points to a four-DWORD candidate.
// The original RET 4 is represented by the standard root bridge's cleanup.
std::uint32_t fun_005afcf0(Memory&, const Inputs&);
}
