#pragma once
#include "recovered/recovery_b1253.hpp"
namespace ra2::recovered::b1256 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned cache_calls=0,retain_calls=0; b1253::Observation hit;};
unsigned run(unsigned,Memory&,leaf::Memory&,const Inputs&,Observation&);
}
