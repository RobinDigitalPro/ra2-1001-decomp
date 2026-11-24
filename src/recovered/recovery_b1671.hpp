#pragma once
#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b1671 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
// Finite normal-provider, already queued case33; no external transport.
unsigned fun_00482440(Memory&,const Inputs&);
}
