#pragma once

#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::numeric_b71 {
using Memory = global_b26::Memory;
using Inputs = floating_b61::Inputs;

// Original VA 0x0053b210. Bounded composition contract is in
// analysis/block71_matrix_contracts.json.
std::uint32_t fun_0053b210(Memory&, const Inputs&);

// Original VA 0x0053b2b0. Bounded composition contract is in
// analysis/block71_matrix_contracts.json.
std::uint32_t fun_0053b2b0(Memory&, const Inputs&);
}
