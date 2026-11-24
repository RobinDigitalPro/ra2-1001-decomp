#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1275 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned label_bytes=0,atomic_pairs=0,provider_buffer=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
