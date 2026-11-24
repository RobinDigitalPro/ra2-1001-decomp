#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1262 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned list_reads=0,visited=0,hits=0,retains=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
