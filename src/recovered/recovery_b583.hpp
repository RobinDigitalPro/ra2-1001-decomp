#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

namespace ra2::recovered::recovery_b583 {
using global_b26::Memory;
using global_b26::Inputs;
using Heap = platform::small_crt_heap::Heap;

// Private finite draft for original RVA 0x326af0 only.
std::uint32_t fun_00726af0(Memory&, const Inputs&, Heap&);
}
