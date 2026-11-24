#pragma once
#include "recovery_b566_machine.hpp"
namespace ra2::recovered::recovery_b1709 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
void require_root_warm_basis(const Memory&,const State&,const Frame&);
void execute_selected(Memory&,State&,Frame&);
// UNRESOLVED PRIVATE DEPENDENCY. No implementation, stub, callback or accepted
// B1708 forwarding is supplied. Actual child entry has [V,P,L,2001h,3E8h]
// plus natural saved-NV/unwritten private words; caller has pushed 6C7843.
// A separately qualified implementation must use this same State/Frame, RET20,
// preserve actual caller words/NV and carry real FP/public/private effects.
void root_6c7f40(Memory&,State&,Frame&);
}
