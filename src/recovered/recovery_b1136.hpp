#pragma once
#include "platform/ordinary_heap979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1136{using b979::Memory;using b979::Inputs;using b979::Heap;using State=ra2::platform::x87::State;unsigned run(unsigned,Memory&,const Inputs&,Heap&,State&);}
