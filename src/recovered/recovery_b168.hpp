#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b168 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t fun_005697a0(Memory&,const Inputs&,Heap&);
}
