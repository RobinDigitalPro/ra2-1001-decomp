#pragma once
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::recovery_b165 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Scratch = std::array<std::uint8_t, 112>;

// Scratch represents the caller-provided bytes at native entry S-0x70 .. S-1.
// The original copies bytes S-0x70 .. S-2 (111 bytes) into the queue. The final
// byte at S-1 is not copied. No initialization is implied for untouched bytes.
std::uint32_t fun_0061af30(Memory& m, const Inputs& i, const Scratch& scratch);
}
