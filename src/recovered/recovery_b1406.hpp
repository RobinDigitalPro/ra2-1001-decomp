#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1406 {
using floating_b61::Memory;using floating_b61::Inputs;using platform::ordinary_heap::Heap;
std::uint32_t configure_crt(Memory&,const Inputs&);
std::uint32_t fun_00716290(Memory&,const Inputs&,Heap&);
}
