#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_b424.hpp"
#include <cstdint>

namespace ra2::recovery_b424 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::recovery_b424::Heap;

// Bounded positive allocation/copy path for original RVA 0x3252c0.
// ECX is the receiver, EDX points to a source wrapper, and arg[0] is the
// child-reference index. This does not claim a source class name or layout.
std::uint32_t fun_007252c0(Memory&, const Inputs&, Heap&);
}
