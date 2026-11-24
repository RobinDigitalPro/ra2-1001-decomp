#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1260 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned allocations=0,resets=0,characters=0,attributes=0,guard_calls=0;};
unsigned run(Memory&,Inputs&,Heap&,Observation&,unsigned root);
unsigned cleanup(Memory&,Heap&);
}
