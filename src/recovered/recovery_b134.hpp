#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b134 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;
// RVA 0x2eb930 / VA 0x6eb930. Bounded zero-global-count route only.
std::uint32_t fun_006eb930(Memory&, const Inputs&, Heap&);
}
