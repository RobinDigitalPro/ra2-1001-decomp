#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1040 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::ordinary_heap::Heap;
std::uint32_t run(Memory&,const Inputs&,Heap&,unsigned);
std::uint32_t fun_0067ad30(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0067bd40(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0067c120(Memory&,const Inputs&,Heap&);
}
