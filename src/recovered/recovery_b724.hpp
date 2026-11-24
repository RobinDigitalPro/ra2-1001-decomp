#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
namespace ra2::recovered::recovery_b724 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::floating_b61::Inputs;
using Heap=ra2::platform::small_crt_heap::Heap;
std::uint32_t fun_007733a8(Memory&,Inputs&,Heap&);
}
