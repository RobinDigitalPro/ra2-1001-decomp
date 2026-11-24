#pragma once
#include "recovery_b566_machine.hpp"

namespace ra2::recovered::recovery_b1708 {
using U = std::uint32_t;
using Memory = recovery_b566::Memory;
using State = recovery_b566::State;
using Frame = recovery_b566::Frame;

// Private source projections only. All calls share live memory, registers,
// flags, FP and the actual parent stack. No synthetic public-wrapper stacks.
void execute_score(Memory&, State&, Frame&);       // Actual unindexed 4C9530.
void execute_surface(Memory&, State&, Frame&);     // Actual 434F80, selected row.
void execute_renderer(Memory&, State&, Frame&);    // Actual unindexed 4862D0.
void execute_selected(Memory&, State&, Frame&);    // Indexed Root 6C7F40.
void require_selected_basis(const Memory&, const State&, const Frame&);
}
