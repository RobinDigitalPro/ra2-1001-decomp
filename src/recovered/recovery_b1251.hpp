#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1251 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned members=0,script_reads=0,null_distances=0,kind_callbacks=0,predicate_reads=0,mission_reads=0,arrivals=0,completions=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
