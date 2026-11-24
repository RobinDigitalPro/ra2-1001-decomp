#pragma once

#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::surface_b503 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;

// Bounded route for the original 0x360cf0 rectangle/pixel-pointer operation.
// The receiver/field contract is recorded in the private B503 plan.
std::uint32_t fun_00760cf0(Memory&, const Inputs&);
}
