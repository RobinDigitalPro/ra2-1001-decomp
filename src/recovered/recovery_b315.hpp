#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

namespace ra2::recovered::recovery_b315 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// Finite route: the original four comparisons are equal, equal, equal, then
// non-equal. The existing metadata pointer is allocation ordinal zero from the
// exact fresh request-32 class-2 recipe. The selected final unequal comparison
// returns it live, so the candidate performs no heap operation.
std::uint32_t fun_00771a35(Memory&, const Inputs&);
}
