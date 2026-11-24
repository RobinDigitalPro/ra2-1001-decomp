#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_b546.hpp"
#include <cstdint>

namespace ra2::recovery_b546 {
using Memory=ra2::recovered::floating_b61::Memory;
using Inputs=ra2::recovered::floating_b61::Inputs;
std::uint32_t fun_005fa680(Memory&,const Inputs&,Heap&);
}
