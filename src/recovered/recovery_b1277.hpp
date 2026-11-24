#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1277{using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;struct Observation{unsigned allocations=0,appends=0,marks=0,map_queries=0,passability=0,coordinate_calls=0;};unsigned run(unsigned,Memory&,const Inputs&,Heap&,Observation&);}
