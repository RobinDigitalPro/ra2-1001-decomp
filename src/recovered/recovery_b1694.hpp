#pragma once
#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::recovery_b1694 {
using U=std::uint32_t;
using Memory=floating_b61::Memory;
using Inputs=floating_b61::Inputs;
// Populated only by the Source's own aligned-frame ABI entry. No GAME address.
struct SourceFrameContext {U entry_esp{},frame_base{},angle_argument{};};
// Read-only exact supplied-domain/input checks. No guest FP operation.
void preflight(Memory&,const Inputs&);
// Finite positive ledger only. The final modeled FP image remains in i.fp.
// angle_argument is a real writable DWORD in this Source entry's private frame.
U run(Memory&,const Inputs&,const SourceFrameContext&);
}
