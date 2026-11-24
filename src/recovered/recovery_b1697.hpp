#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1697 {
using U=std::uint32_t;
using Memory=floating_b61::Memory;
using Inputs=floating_b61::Inputs;
// Only the genuine Unit sparse-list 117B clear domain. Read-only guards; no
// constructor/notification/117C path or arbitrary receiver is supported.
void preflight(Memory&,const Inputs&);
U run(Memory&,const Inputs&);
}
