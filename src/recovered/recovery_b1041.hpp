#pragma once
#include "recovered/recovery_b338.hpp"
namespace ra2::recovered::b1041 {
using Memory=floating_b61::Memory;using Inputs=floating_b61::Inputs;
struct Observation{unsigned relations=0,marked=0,triplet_calls=0,find_index=0,previous=0,matched=0;};
unsigned run(Memory&,const Inputs&,unsigned root,Observation&);
}
