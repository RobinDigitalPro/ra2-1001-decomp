#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/mixed_heap1279.hpp"

namespace ra2::recovered::b1303 {
using Memory=floating_b61::Memory;
using Inputs=floating_b61::Inputs;
using Heap=ra2::platform::mixed_heap1279::Heap;
std::uint32_t run(std::uint32_t rva,Memory&,const Inputs&,Heap&);
}
