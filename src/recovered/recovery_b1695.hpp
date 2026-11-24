#pragma once
#include "recovered/recovery_b1694.hpp"

namespace ra2::recovered::recovery_b1695 {
using U=std::uint32_t;
using Memory=floating_b61::Memory;
using RootInputs=floating_b61::Inputs;
// Actual own-Source Root entry R, aligned A, and the live nested child frame.
struct RootFrameContext {
 U entry_esp{},aligned_base{};
 recovery_b1694::SourceFrameContext child;
};
// Exact finite early-positive domain. No guest FP operation or memory write.
void preflight(Memory&,const RootInputs&);
// Root arg0 is the normal secondary self+4; incoming Root ECX is unconsumed.
// All sixteen Root caller DWORDs remain unchanged. Child K must remain live.
U run(Memory&,const RootInputs&,const RootFrameContext&);
}
