#pragma once

#include "recovered/floating_b61_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::recovery_b356 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;

std::uint32_t fun_002a0410(Memory&, const Inputs&);
}
