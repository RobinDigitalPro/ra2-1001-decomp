#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1230{using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;struct Observation{unsigned virtual_callbacks=0,script_reads=0,null_slots=0,eligibilities=0,joins=0;};unsigned run(unsigned,Memory&,const Inputs&,Observation&);}
