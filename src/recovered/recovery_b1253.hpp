#pragma once
#include "recovered/leaf_memory.hpp"
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1253 {
using Memory=leaf::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned visited=0,unlink_calls=0,insert_calls=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
