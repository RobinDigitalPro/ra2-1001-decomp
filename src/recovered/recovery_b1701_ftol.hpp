#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::recovery_b1701 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
namespace helpers {
// Actual CALL/61-byte76AA50/RET0 against live State.fp and same caller Frame.
// No pushed arguments; this helper owns the continuation word and child frame.
void ftol(Memory&,State&,Frame& caller,U continuation);
}
}
