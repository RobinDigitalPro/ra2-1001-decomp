#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::strings415 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t fun_00759d20(Memory&,const Inputs&,Heap&);
}
