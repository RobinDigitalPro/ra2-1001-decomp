#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

namespace ra2::recovered::heap703_draft {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;
std::uint32_t fun_007736d3(Memory&, Inputs&, Heap&);
}
