#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
namespace ra2::recovered::heap660_draft {
using floating_b61::Memory;
using floating_b61::Inputs;
using Heap = platform::small_crt_heap::Heap;
std::uint32_t fun_006921d0(Memory&, Inputs&, Heap&);
}
