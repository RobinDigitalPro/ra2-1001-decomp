#pragma once
#include "global_b26_memory.hpp"
#include "platform/small_crt_heap_b510.hpp"
namespace ra2::recovery_b510 {
using Inputs=ra2::recovered::global_b26::Inputs;
std::uint32_t fun_005fbd00(Memory&,const Inputs&,Heap&);
}
