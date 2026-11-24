#pragma once

#include "recovered/global_b26_memory.hpp"

// Bounded positive-route draft for original RVA 0x13d230. The guest-memory
// parameter and raw entry fields are analysis interfaces, not source ABI or
// class declarations.
namespace ra2::recovered::recovery_b280 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

std::uint32_t fun_0053d230(Memory&, const Inputs&);
} // namespace ra2::recovered::recovery_b280
