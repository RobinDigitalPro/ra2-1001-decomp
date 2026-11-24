#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::recovery_b311 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t rva_0035d010(Memory&,const Inputs&,Heap&);
}
