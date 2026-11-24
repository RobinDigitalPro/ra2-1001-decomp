#pragma once
#include "recovered/floating_b39_memory.hpp"
#include "platform/cpu_b48.hpp"
namespace ra2::recovered::cpu_b48 {
using floating_b39::Memory;using floating_b39::State;using floating_b39::Frame;
using floating_b39::finish;
namespace integer=direct_b33::integer;
using Operations=ra2::platform::cpu_b48::Operations;
void rva_36ab4f(Memory&,State&,Frame&,const Operations&);
void rva_36abb4(Memory&,State&,Frame&,const Operations&);
}
