#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1093{using b979::Memory;using b979::Inputs;using b979::Heap;using Clock=DWORD(WINAPI*)();using ra2::platform::x87::State;
unsigned run(Memory&,const Inputs&,Heap&,Clock,State&,unsigned root);
}
