#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1158 {
using Memory=global_b26::Memory; using Inputs=global_b26::Inputs; using Heap=ra2::platform::ordinary_heap::Heap;
// Numeric projection of authentic initialized INI/list/index producers. No ABI
// reinterpretation of the reordered portable IniSection/IniIndex host views.
unsigned run(unsigned root,Memory&,const Inputs&,Heap&,ra2::platform::x87::State&);
void cleanup(Memory&,unsigned ini,Heap&);
}
