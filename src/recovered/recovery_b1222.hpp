#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1222 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned virtual_callbacks=0,script_reads=0,members=0,limbo_checks=0,completions=0;};
unsigned run(unsigned root,Memory&,const Inputs&,Observation&);
}
