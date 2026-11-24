#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1451 {
using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t configure_crt(Memory&,const Inputs&);
std::uint32_t producer(unsigned,Memory&,const Inputs&,Heap&);
std::uint32_t fun_00521e70(Memory&,const Inputs&,Heap&);
}
