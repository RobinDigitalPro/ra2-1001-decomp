#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1243 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned reads=0,ungets=0,assignments=0,whitespace=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
