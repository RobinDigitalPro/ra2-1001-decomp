#pragma once

#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b359 {
using global_b26::Inputs;
using global_b26::Memory;

// Finite positive projection for the staged original 0x97610 A-glyph route.
// The accepted domain is recorded beside the fixture; excluded inputs throw.
std::uint32_t fun_00497610(Memory&, const Inputs&);
}
