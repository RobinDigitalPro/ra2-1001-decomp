#pragma once

#include "recovered/floating_b61_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b361 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;

// Finite route draft for RVA 0x9cca0: one center cell plus its eight distinct
// original direction-table neighbors. This is not an unrestricted contract.
std::uint32_t fun_0009cca0(Memory&, const Inputs&);
}
