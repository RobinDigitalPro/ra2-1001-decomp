#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1031 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::ordinary_heap::Heap;
std::uint32_t run(Memory&,const Inputs&,Heap&,unsigned);
std::uint32_t fun_0056bb00(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0056ccc0(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0057ece0(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0056d7b0(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0056d0a0(Memory&,const Inputs&,Heap&);
}
