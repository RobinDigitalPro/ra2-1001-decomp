#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b141 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using Heap=ra2::platform::small_crt_heap::Heap;
// Bounded selector/string assignment route for original RVA 0x1c59d0.
// Caller-provided global selector state is explicit; no gameplay class or
// selector-enum identity is inferred.
std::uint32_t fun_005c59d0(Memory&,const Inputs&,Heap&);
}
