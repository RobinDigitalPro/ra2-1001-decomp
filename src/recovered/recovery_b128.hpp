#pragma once
#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::recovery_b128 {
using floating_b61::Memory;
using floating_b61::Inputs;

// Finite positive contract described in route.json. The original's no-throw
// FS/SEH setup is a platform-adapter concern and is excluded from this draft.
std::uint32_t fun_006aae60(Memory&, const Inputs&);
}
