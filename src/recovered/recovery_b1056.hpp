#pragma once
#include "recovered/crt_b83.hpp"
namespace ra2::recovered::b1056 {
using Memory=crt_b83::Memory;using Inputs=crt_b83::Inputs;
struct Observation{unsigned global_fields_written=0,comparisons=0,cleared_active_bits=0;};
unsigned run(Memory&,const Inputs&,Observation&);
}
