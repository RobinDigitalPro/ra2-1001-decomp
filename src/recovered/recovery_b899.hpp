#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b899 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Bounded model for the ordinary, non-excluded pointer route through RVA 0x1c2b20.
// entry_esp is captured before the original CALL; EAX is the last HeapFree result.
std::uint32_t fun_005c2b20(Memory&, const Inputs&, Heap&, std::uint32_t entry_esp);
}
