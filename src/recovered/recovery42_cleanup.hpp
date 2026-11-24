#pragma once

#include "platform/ordinary_heap.hpp"
#include "platform/small_crt_heap_algorithm.hpp"
#include "recovered/global_b27_memory.hpp"

#include <array>
#include <cstdint>

// Finite-route models for the cleanup/CRT portion of frozen42. These
// interfaces model guest addresses and explicit heap effects; they make no
// claim about original C++ class names or host calling conventions.
namespace ra2::recovered::recovery42_cleanup {
using Memory = global_b27::Memory;
using State = global_b27::State;
using OrdinaryHeap = ra2::platform::ordinary_heap::Heap;

void fun_0059a2f0(Memory&, State&, OrdinaryHeap&); // 0x19a2f0
void fun_0040afa0(Memory&, State&, OrdinaryHeap&); // 0xafa0, selected array route
void fun_00429a90(Memory&, State&, OrdinaryHeap&); // 0x29a90
void fun_0047fdf0(Memory&, State&, OrdinaryHeap&); // 0x7fdf0
void fun_006de930(Memory&, State&, OrdinaryHeap&); // 0x2de930
void fun_006df3f0(Memory&, State&, OrdinaryHeap&); // 0x2df3f0
void fun_006defc0(Memory&, State&, OrdinaryHeap&); // 0x2defc0
void fun_00706850(Memory&, State&, OrdinaryHeap&); // 0x306850
void fun_00700250(Memory&, State&, OrdinaryHeap&); // 0x300250
void fun_004284e0(Memory&, State&, OrdinaryHeap&); // 0x284e0
void fun_006e9150(Memory&, State&, OrdinaryHeap&); // 0x2e9150

}
