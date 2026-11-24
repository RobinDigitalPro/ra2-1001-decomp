#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b704 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;
std::uint32_t fun_007739dc(Memory&, Inputs&, Heap&);
std::uint32_t fun_00773a8d(Memory&, Inputs&, Heap&);
}
