#pragma once
// PRIVATE PROVISIONAL (unallocated batch): API-compatible with the B1711 carrier bridge (preflight/run, 500B private window).
#include "recovery_b1712_methods.hpp"
namespace ra2::delivery::query1cbf20 {
using Memory=ra2::recovered::recovery_b705::Memory;
using State=ra2::recovered::recovery_b705::State;
using Frame=ra2::recovered::recovery_b705::Frame;
namespace fp=ra2::platform::x87;
using ra2::delivery::query51090::NativeState;
using ra2::delivery::query51090::Result;
// Domain D1 preflight on the produced object graph (outside the guest boundary).
void preflight(Memory&,unsigned self);
// Caller pre-registers actual owned stack [R-1B0,R+44); no stack initialization.
Result run(Memory&,unsigned entry,unsigned char*storage,unsigned size,const NativeState&,const fp::Image&);
}
