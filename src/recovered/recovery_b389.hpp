#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b389 {
using global_b26::Inputs;
using global_b26::Memory;

// Bounded positive one-A projection of the pinned original 0x97ac0 root.
// Exact accepted first-glyph composition is documented in text389/plan.json.
std::uint32_t fun_00497ac0(Memory&,const Inputs&);
}
