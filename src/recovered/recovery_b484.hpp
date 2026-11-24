#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::recovery_b484 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
using Heap=platform::ordinary_heap::Heap;
std::uint32_t fun_00752760(Memory&,const Inputs&,Heap&);
}
