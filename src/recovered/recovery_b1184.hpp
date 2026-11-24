#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1184{
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using State=ra2::platform::x87::State;
unsigned run(unsigned,Memory&,const Inputs&,Heap&,State&);
unsigned cleanup(unsigned,Memory&,Heap&);
}
