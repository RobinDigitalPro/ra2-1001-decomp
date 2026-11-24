#pragma once
#include "recovery_b566_machine.hpp"

namespace ra2::recovered::recovery_b1709 {
using U = std::uint32_t;
using Memory = recovery_b566::Memory;
using State = recovery_b566::State;
using Frame = recovery_b566::Frame;

// Actual 4866C0/RET40, positive one-pixel/skip0/token1 projection only.
// Caller supplies its actual CALL return in the same live Memory/Frame.
void execute_renderer(Memory&, State&, Frame&);
}
