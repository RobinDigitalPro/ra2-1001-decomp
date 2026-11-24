#pragma once
#include "recovered/recovery_b979.hpp"
#include <array>
namespace ra2::recovered::b1125 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned allocations=0,frees=0,insertions=0,removals=0,sorts=0,ui_updates=0;};
unsigned run(Memory&,Inputs&,Heap&,unsigned root,unsigned arena_base,Observation&);
}
