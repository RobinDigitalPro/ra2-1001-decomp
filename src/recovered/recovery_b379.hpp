#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b379 {
using floating_b61::Memory;
using floating_b61::Inputs;

// Draft finite route for original RVA 0x1cd290 (VA 0x5cd290).
// Scope: nonnull receiver/other, constructor-proven vptr 0x78612c on both,
// type getter slot +0x2c resolves to the pinned MOV EAX,2; RET at 0x41b580,
// positive coordinate deltas (3,4,0) or (192,256,0), x87 CW 0x0e7f.
// The optional type-6 extent route is deliberately outside this contract.
std::uint32_t fun_005cd290(Memory&, const Inputs&);
}