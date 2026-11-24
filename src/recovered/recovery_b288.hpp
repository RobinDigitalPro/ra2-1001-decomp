#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

namespace ra2::recovered::recovery_b288 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::small_crt_heap::Heap;

// Static transcription draft for RVA 0x31def0 / VA 0x71def0.
// Heap dispatch is deliberately limited by the parent adapter to exact {1}.
std::uint32_t fun_0071def0(Memory& m, Inputs& i, Heap& heap);
}
