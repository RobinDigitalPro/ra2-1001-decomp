#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b907 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
std::uint32_t fun_005cfcc0(Memory&, const Inputs&);
}
