#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1218 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Observation{unsigned allocations=0,frees=0,insertions=0,removals=0,sorts=0,ui_updates=0,key_copies=0,value_reads=0,theme_assignments=0,hash_callbacks=0,predicate_calls=0,virtual_callbacks=0,cost_calls=0,groupings=0;};
unsigned run(Memory&,Inputs&,Heap&,unsigned root,unsigned arena_base,Observation&);
}
