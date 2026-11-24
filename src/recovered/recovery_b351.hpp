#pragma once

#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::recovery_b351 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;

// Finite positive route for original RVA 0x159310. The fixture supplies an
// interior event cell and a fully populated 5x5 map neighborhood.
std::uint32_t fun_00559310(Memory&, const Inputs&);
}
