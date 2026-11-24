#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1681 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
using Heap=platform::ordinary_heap::Heap;
struct Observation {unsigned frontier{},record{},label{},point{},processed{},count{};};
// Finite isolated classified-cell route with supplied public cold neighbor data.
unsigned run(Memory&,const Inputs&,Heap&,Observation&);
}
