#pragma once

#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b322 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

// Exact useful slice for one populated record at registry index zero, mode 1,
// with both observed CRT critical-section slots already initialized.
struct Locks { virtual ~Locks()=default; virtual void enter(unsigned)=0; virtual void leave(unsigned)=0; };
std::uint32_t fun_0076fd9e(Memory&, const Inputs&, Locks&);
}
