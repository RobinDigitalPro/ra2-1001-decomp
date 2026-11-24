#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b135 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// RVA 0x20bf30 / VA 0x60bf30. Bounded copy plus (optionally) spare-capacity
// append. This makes no claim about the source-level class or game setup.
std::uint32_t fun_0060bf30(Memory&, const Inputs&, Heap&);
}
