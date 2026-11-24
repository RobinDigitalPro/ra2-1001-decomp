#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

namespace ra2::recovered::allocation671 {
using global_b26::Inputs;
using global_b26::Memory;
using Heap = platform::small_crt_heap::Heap;
std::uint32_t fun_0060d400(Memory&, Inputs&, Heap&);
}
