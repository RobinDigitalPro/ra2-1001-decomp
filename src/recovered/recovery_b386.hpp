#pragma once
#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::recovery_b386 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
std::uint32_t fun_00498cf0(Memory&, const Inputs&);
std::uint32_t fun_00498e50(Memory&, const Inputs&);
}
