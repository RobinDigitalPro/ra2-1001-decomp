#pragma once

#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b706 {
using ra2::recovered::global_b26::Inputs;
using ra2::recovered::global_b26::Memory;

// Bounded one-glyph routes corresponding to original RVAs 0x317A0 and 0x31B80.
// See README.md for the explicit positive input contract.
std::uint32_t fun_004317a0(Memory&, const Inputs&);
std::uint32_t fun_00431b80(Memory&, const Inputs&);
}
