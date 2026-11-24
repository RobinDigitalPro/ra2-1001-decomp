#pragma once
#include "recovered/recovery_b338.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1043 {
using Memory=floating_b61::Memory;using Inputs=floating_b61::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned allocations=0,frees=0,triplets=0,appends=0,removed=0;};
unsigned run(Memory&,const Inputs&,Heap&,unsigned root,Observation&);
}
