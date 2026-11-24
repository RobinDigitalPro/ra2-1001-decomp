#pragma once
#include "recovered/recovery_b566_machine.hpp"
// BEGIN mechanical component getter_header
namespace ra2::recovered::recovery_b1700 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
namespace getter_model {
// CALL model for the exact normal-primary798C88+48 ->5CD4D0.
// Caller already pushed its actual12B output pointer at RootR-10.
// This function pushes the actual continuation, models all33 bytes, and applies
// genuine RET4. No copied caller inputs, callbacks, allocation or FP recipe.
// ADD ECX,88 changes arithmetic flags; all later instructions preserve them.
void actual_primary48(Memory&,State&,Frame& caller,U continuation,U actual_target);
}
}
// END mechanical component getter_header
// BEGIN mechanical component root_header
namespace ra2::recovered::recovery_b1700 {
namespace helpers {
// External readonly finite borrowed-input guard, before first guest mutation.
// Mapping is not a physical ownership or whole-constructor history claim.
void require_selected_basis(const Memory&,const State&,const Frame&);
}
// One literal FF->0 propagation path only. Same actual RootFrame, real primary
// getter child CALL/RET4, eighteen actual slot reads, two public BYTE stores.
// Self75 and all16 callerwords remain exact. Final ADD ESP44 computes flags
// from the actual frame address. Other branches throw; no constant result,
// Context/TLS/callback or guest FP/LastError/flags normalization is introduced.
void execute_selected(Memory&,State&,Frame&);
}
// END mechanical component root_header
