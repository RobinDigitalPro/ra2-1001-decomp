#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b374 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;

// Finite positive route: A255DC != 2, owner mode != 4, one active peer,
// and an available queue slot with a 14-byte payload.
std::uint32_t fun_0061de70(Memory&, const Inputs&);
}
