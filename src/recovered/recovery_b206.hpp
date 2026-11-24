#pragma once
#include "global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
namespace ra2::recovered::recovery_b206 {
using global_b26::Memory;using global_b26::Inputs;using Heap=ra2::platform::small_crt_heap::Heap;
std::uint32_t fun_007802d0(Memory&,const Inputs&,Heap&);
}
