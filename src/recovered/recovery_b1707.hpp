#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::recovery_b1707 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
// Readonly finite-domain/mapping preflight; driver calls before observation.
// Mapping checks do not establish OS ownership, writability or constructor history.
void require_selected_basis(const Memory&,const State&,const Frame&);
// Actual selected 104-PC Root plus real CALL/RET helper/private effects.
// The caller supplies the actual entry Frame and unchanged sixteen caller words.
// Complete modeled stack [R-0x88,R+0x44); RET0. No physical ABI/FP qualification here.
void execute_selected(Memory&,State&,Frame&);
}
