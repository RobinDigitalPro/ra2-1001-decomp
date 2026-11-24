#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1268 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned map_calls=0,visited_cells=0,overlay_clears=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
