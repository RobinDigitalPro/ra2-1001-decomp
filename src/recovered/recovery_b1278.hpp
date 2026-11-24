#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1278 {
using Memory=global_b26::Memory;
struct Inputs:global_b26::Inputs{mutable platform::x87::State fp;};
struct Observation{unsigned members=0,arrivals=0,script_reads=0,null_distances=0,zero_distances=0,height_queries=0,fp_conversions=0,mission_reads=0,kind_callbacks=0,type_reads=0,completions=0,centroids=0,passability=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
