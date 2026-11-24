#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b208 {
std::uint32_t fun_00485df0(
    global_b26::Memory&, const global_b26::Inputs&,
    ra2::platform::small_crt_heap::Heap&);
}
