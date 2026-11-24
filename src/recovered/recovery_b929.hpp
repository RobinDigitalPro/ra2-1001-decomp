#pragma once
#include "recovered/recovery_b319.hpp"

namespace ra2::recovery_b929 {
using Memory=ra2::recovery_b319::Memory;
using MixedHeap=ra2::recovery_b319::MixedHeap;
using TickClock=ra2::recovery_b319::TickClock;
using EntryState=ra2::recovery_b319::EntryState;
// Bounded composite constructor route: original B319 prefix + exact literal
// table scans, fixed child reset, and accepted global publication behavior.
std::uint32_t fun_00295d30(Memory&,MixedHeap&,TickClock&,EntryState&);
}
