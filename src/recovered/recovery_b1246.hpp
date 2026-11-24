#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1246 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;using State=ra2::platform::x87::State;
struct Observation{unsigned virtual_callbacks=0,script_reads=0,members=0,limbo_checks=0,completions=0,waypoint_queries=0,period_conversions=0;};
unsigned run(unsigned,Memory&,const Inputs&,State&,Observation&);
}
