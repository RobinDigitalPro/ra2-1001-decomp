#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1241 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned addresses=0,records=0,vectors=0,virtual_callbacks=0,allocations=0;};
unsigned run(Memory&,const Inputs&,Heap&,Observation&,unsigned root);
}
