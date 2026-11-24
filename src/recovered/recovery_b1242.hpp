#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1242 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Observation{unsigned members=0,type_callbacks=0,limbo_checks=0,inventory_visits=0,completions=0;};
unsigned run(unsigned,Memory&,const Inputs&,Observation&);
}
