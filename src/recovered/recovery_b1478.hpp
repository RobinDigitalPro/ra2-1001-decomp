#pragma once

#include "recovered/floating_b61_memory.hpp"

#include <cstdint>

namespace ra2::recovered::b1478 {

using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;

// Finite positive loader route selected for RVA 0x2D9830 (VA 0x006D9830).
// This does not claim constructor/bootstrap or other stream-shape coverage.
std::uint32_t fun_006d9830(Memory& memory, const Inputs& inputs);

} // namespace ra2::recovered::b1478
