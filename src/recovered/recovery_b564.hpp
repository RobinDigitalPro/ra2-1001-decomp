#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b564 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::ordinary_heap::Heap;
using Function = std::uint32_t (*)(Memory&, const Inputs&, Heap&);

// Finite positive resize routes. Each preserves the exact root ABI (ECX table,
// RET 0); its actual EAX is the original HeapFree BOOL.
std::uint32_t fun_005f9840(Memory&, const Inputs&, Heap&);
std::uint32_t fun_005f9f50(Memory&, const Inputs&, Heap&);
std::uint32_t fun_005f9c20(Memory&, const Inputs&, Heap&);
std::uint32_t fun_005fa3c0(Memory&, const Inputs&, Heap&);
std::uint32_t fun_005fa470(Memory&, const Inputs&, Heap&);
}
