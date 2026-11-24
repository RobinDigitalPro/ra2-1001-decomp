#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1205 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned allocations=0,frees=0,insertions=0,removals=0,sorts=0,ui_updates=0,positive_transitions=0,limbo_calls=0,type_queries=0,virtual_dispatches=0;};
unsigned run(Memory&,Inputs&,Heap&,unsigned,unsigned,Observation&);
}
