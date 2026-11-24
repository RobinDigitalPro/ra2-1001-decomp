#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1269 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned type_calls=0,taskforce_reads=0,member_reads=0,completion_marks=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
