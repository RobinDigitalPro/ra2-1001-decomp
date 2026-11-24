#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::recovery_b418 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;
// Bounded positive route for the original eight-slot owned cleanup at RVA 0x2e80e0.
std::uint32_t fun_006e92c0(Memory&,const Inputs&,Heap&);
std::uint32_t fun_006e80e0(Memory&, const Inputs&, Heap&);
}
