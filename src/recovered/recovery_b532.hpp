#pragma once
#include "recovery_b459.hpp"
#include "platform/small_crt_heap_b532.hpp"
namespace ra2::recovered::recovery_b532 {
using recovery_b459::Memory;using recovery_b459::Inputs;
using Heap=ra2::recovery_b532::Heap;
std::uint32_t fun_006de7e0(Memory&,const Inputs&,Heap&);
std::uint32_t fun_006df2a0(Memory&,const Inputs&,Heap&);
}
