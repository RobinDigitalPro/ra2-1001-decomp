#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap781/small_crt_heap_win32.hpp"
namespace ra2::recovered::recovery_b781 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using Heap=ra2::platform::small_crt_heap781::Heap;
std::uint32_t fun_007339b0(Memory&,const Inputs&,Heap&);
}
