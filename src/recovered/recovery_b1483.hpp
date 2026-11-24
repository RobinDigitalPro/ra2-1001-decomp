#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1483 {
using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t configure_crt(Memory&,const Inputs&);
std::uint32_t fun_005b1fa0(Memory&,const Inputs&,Heap&);
}
