#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1248 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned headers=0,allocations=0,records=0;};
unsigned run(Memory&,const Inputs&,Heap&,Observation&,unsigned root);
}
