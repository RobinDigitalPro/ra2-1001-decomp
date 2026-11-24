#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1048 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::ordinary_heap::Heap;using ra2::platform::x87::State;
std::uint32_t run(Memory&,const Inputs&,Heap&,State&,unsigned);
std::uint32_t fun_0052f900(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0052fae0(Memory&,const Inputs&,Heap&);
std::uint32_t fun_0067f180(Memory&,const Inputs&,Heap&);
std::uint32_t fun_006b72a0(Memory&,const Inputs&,State&);
}
