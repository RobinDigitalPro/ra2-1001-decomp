#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b179 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
std::uint32_t fun_006446c0(Memory&, const Inputs&);
}
