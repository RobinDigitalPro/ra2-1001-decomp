#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1699 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
namespace helpers {
// Declaration-only external finite borrowed-input/owned-buffer contract gate.
// Must validate mapped nonaliasing actual frame/caller16/object/buffer, authentic
// table+14 and fresh +2C/+14/+25 zero state BEFORE first Root write. It must not
// assume an unproved full constructor history or old B483 file-receiver domain.
void require_selected_basis(const Memory&,const State&,const Frame&);
// Exact real42F5E0 ->630240 zero-prefix, actual CALL/RET4 at each level.
void actual_slot14(Memory&,State&,Frame&,U continuation,U actual_target);
}
// Selected literal Root path only: arg0 signed >=0x400, arg1 owned nonnull
// caller buffer, Self+2C=0/+14=0/+25=0, authentic78773C/+14=42F5E0.
// Same actual caller Frame; save4nonvolatiles; RET8. No copied private args,
// no allocator/slot28/SDK/filework. Buffer POINTER is written into Self+2C;
// this selected path never dereferences or writes the buffer's bytes.
// Actual full EAX emerges from the literal stores/branches/MOV AL,1.
void execute_selected(Memory&,State&,Frame&);
}

// This TU defines only the existing helpers::require_selected_basis declaration.
// Fixed logical addresses are finite fixture inputs, not OS ownership evidence.
// The driver owns backing storage and verifies its writable extent and lifetime
// outside the Root. No installed declaration, callbacks, TLS or hidden setup.
