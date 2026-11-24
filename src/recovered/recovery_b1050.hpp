#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1050 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned allocations=0,frees=0,triplets=0,appends=0,removed=0,candidates=0,registry_removals=0;};
unsigned run(Memory&,const Inputs&,Heap&,unsigned root,unsigned arena_base,Observation&);
}
