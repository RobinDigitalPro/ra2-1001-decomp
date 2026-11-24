#pragma once

#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::numeric_b71 {
using Memory = global_b26::Memory;
using Inputs = floating_b61::Inputs;

// Original VA 0x007318a0. The function composes five accepted integer INI
// reads against the bounded guest graph described in block71_ini_contract.json.
std::uint32_t fun_007318a0(Memory&, const Inputs&);
}
