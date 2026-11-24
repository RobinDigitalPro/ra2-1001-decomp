#pragma once

#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b365 {
using Inputs = global_b26::Inputs;
using Memory = global_b26::Memory;

// Finite literal-A routes through the original 0x97840 and 0x97920 wrappers.
std::uint32_t fun_00497840(Memory&, const Inputs&);
std::uint32_t fun_00497920(Memory&, const Inputs&);
}
