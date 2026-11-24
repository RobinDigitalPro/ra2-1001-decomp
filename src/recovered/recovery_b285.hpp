#pragma once
#include "recovered/global_b26_memory.hpp"

// Finite construction draft for original RVA 0xeba00. These names describe
// guest-memory roles in the fixture, not recovered source types.
namespace ra2::recovered::recovery_b285 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
std::uint32_t fun_004eba00(Memory&, const Inputs&);
}
