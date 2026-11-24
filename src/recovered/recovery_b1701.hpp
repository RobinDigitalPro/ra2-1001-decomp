#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::recovery_b1701 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
namespace helpers {
// Readonly exact joint-basis gate, before the first Root instruction/write.
// Separate definition required; logical coverage is not physical ownership.
void require_selected_basis(const Memory&,const State&,const Frame&);
// Caller has pushed actual outgoing arguments. Each helper models its real
// CALL return push, actual child Frame and original RET cleanup, sharing State.
void pick(Memory&,State&,Frame&,U continuation);
void map_cell(Memory&,State&,Frame&,U continuation);
void ftol(Memory&,State&,Frame&,U continuation);
// Exact accepted scalar/zero-field predicate paths under the same actual Frame.
void global_predicate(Memory&,State&,Frame&,U continuation);
void empty_predicate(Memory&,State&,Frame&,U continuation);
}
// Only the closed (0,12,3,94) rectangle/copy/real-predicate-exit route.
// Actual Frame/all16; continuous x87 State; no legacy private wrapper frames.
void execute_selected(Memory&,State&,Frame&);
}
