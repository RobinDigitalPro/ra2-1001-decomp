#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap735_win32.hpp"

namespace ra2::recovered::alloc735 {
using Inputs = global_b26::Inputs;
using Memory = global_b26::Memory;
using Heap = ra2::platform::small_crt_heap::Heap;
std::uint32_t fun_005fb640(Memory&, Inputs&, Heap&);
}
