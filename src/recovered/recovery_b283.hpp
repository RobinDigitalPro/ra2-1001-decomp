#pragma once

#include "recovered/global_b26_memory.hpp"

// Bounded positive-route draft for original RVA 0x2b850. These raw
// guest-memory inputs do not claim an original class name or source prototype.
namespace ra2::recovered::recovery_b283 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

std::uint32_t fun_0042b850(Memory&, const Inputs&);
} // namespace ra2::recovered::recovery_b283
