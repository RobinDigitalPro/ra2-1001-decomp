#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1263 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned allocations=0,reserves=0,appends=0,queue_zero_writes=0,map_size_calls=0;};
unsigned run(Memory&,Inputs&,Heap&,Observation&,unsigned root);
}
