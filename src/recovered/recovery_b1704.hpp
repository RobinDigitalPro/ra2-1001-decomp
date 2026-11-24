#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::recovery_b1704 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
namespace calls {
void timer_41b390(Memory&,State&,Frame& caller,U continuation,U actual_target);
void byte_6cc360(Memory&,State&,Frame& caller,U continuation,U actual_target);
}
namespace helpers {
// Driver-owned readonly finite/ownership preflight BEFORE observed execute_selected.
// This declaration is intentionally not a successful placeholder implementation.
void require_selected_basis(const Memory&,const State&,const Frame&);
}
// Only direct normal-Unit quantity-clear: arg4 byte nonzero, timer sentinel/zero,
// Self204=1, genuine caller-owned nonzero arg0 DWORD disjoint from Self/stack.
// Caller must complete helpers::require_selected_basis outside observation.
void execute_selected(Memory&,State&,Frame&);
}
