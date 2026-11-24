#pragma once
#include "recovered/recovery_b1041.hpp"
namespace ra2::recovered::b1045 {
using Memory=b1041::Memory;using Inputs=b1041::Inputs;
struct Observation{unsigned colors=0,find_calls=0,matched=0; b1041::Observation relation{};};
unsigned run(Memory&,const Inputs&,unsigned,Observation&);
}
