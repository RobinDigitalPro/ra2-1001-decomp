#pragma once
#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b308 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
std::uint32_t rva_0022a5b0(Memory&, const Inputs&);
}
