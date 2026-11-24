#pragma once

#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b200 {
std::uint32_t fun_006a5050(
    floating_b61::Memory&, const floating_b61::Inputs&,
    ra2::platform::small_crt_heap::Heap&);
}
