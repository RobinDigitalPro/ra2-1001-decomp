#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b139 {

using Memory=ra2::recovered::global_b26::Memory;using Inputs=ra2::recovered::global_b26::Inputs;using Heap=ra2::platform::small_crt_heap::Heap;
// Bounded success path for original RVA 0x35aec0. Inputs.cx is the receiver;
// Inputs.dx is the complete signed-int bit pattern supplied to literal "%d".
// The caller argument stack is unchanged and the original function has RET 0.
std::uint32_t fun_0075aec0(
    ra2::recovered::global_b26::Memory& memory,
    const ra2::recovered::global_b26::Inputs& inputs,
    ra2::platform::small_crt_heap::Heap& heap);

} // namespace ra2::recovered::recovery_b139
