#pragma once

#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b273 {
using global_b26::Inputs;
using global_b26::Memory;

// Draft bounded structural projection for original RVA 0x6bef0. Entry inputs
// follow observed register/stack use only: ECX in cx, section at arg[0], key at
// arg[1]. This interface does not name an original class or source prototype.
std::uint32_t fun_0046bef0(Memory&, const Inputs&);
}
