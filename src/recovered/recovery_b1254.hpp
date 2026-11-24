#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1254 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned cell_queries=0,zero_cell_stores=0,kind_callbacks=0,rtti_strings=0,find_comparisons=0,registry_removals=0,shifts=0,base_vptr_writes=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
