#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>

namespace ra2::recovered::format_b761 {
using Memory = global_b26::Memory;
using Inputs = floating_b61::Inputs;

// Bounded positive type-0x2b serializer route only.
std::uint32_t fun_006a2c90(Memory&, const Inputs&);
}
