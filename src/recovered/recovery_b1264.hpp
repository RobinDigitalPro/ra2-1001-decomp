#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1264{using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;using State=platform::x87::State;unsigned run(unsigned,Memory&,const Inputs&,State&);}
