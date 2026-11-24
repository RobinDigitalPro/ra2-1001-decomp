#pragma once
#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::recovery_b480 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;

// B480 draft: bounded exact translation of GAME.EXE RVA 0x3167b0.
// The function has no explicit arguments and returns RET 0.
std::uint32_t fun_007167b0(Memory&, const Inputs&);
}
