#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::recovery_b1706 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
// Driver-owned readonly finite/ownership preflight runs BEFORE observation.
// Supported borrowed public receiver: DWORD+30 nonzero, DWORD+54 zero,
// BYTE+80 initially1; selected execution genuinely clears BYTE+80 to0.
// Complete modeled private/caller span is [R-0x90,R+0x44). No private seeds.
// No constructor/history or compatibility with B1274's nonempty API is claimed.
void execute_selected(Memory&,State&,Frame&);
}
