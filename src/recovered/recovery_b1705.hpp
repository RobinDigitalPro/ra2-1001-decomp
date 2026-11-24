#pragma once
#include "recovered/recovery_b1704.hpp"
namespace ra2::recovered::recovery_b1705 {
using U=recovery_b1704::U;
using Memory=recovery_b1704::Memory;
using State=recovery_b1704::State;
using Frame=recovery_b1704::Frame;
// Driver-owned readonly finite/ownership preflight must run BEFORE observation.
// Supported parent arg2 is an actual owned readable30020000 span, byte14A=0;
// normal Self580=0, real owned nonzero *arg0, wholearg4=1 and B1704 fields/slots.
// This model does not invoke or impersonate B1704's standalone fixed-arg preflight.
void execute_selected(Memory&,State&,Frame&);
}
