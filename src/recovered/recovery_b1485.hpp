#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1485 {
using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t configure_crt(Memory&,const Inputs&);
std::uint32_t fun_006d9520(Memory&,const Inputs&,Heap&);
}
