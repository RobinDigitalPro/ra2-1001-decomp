#pragma once
#include "recovered/global_b26_memory.hpp"
#include "recovered/floating_b61_memory.hpp"
#include "recovered/floating_callers_b40_memory.hpp"

namespace ra2::recovered::recovery_b346 {
using Memory = ra2::recovered::floating_callers_b40::Memory;
using State = ra2::recovered::floating_callers_b40::State;
using Frame = ra2::recovered::floating_callers_b40::Frame;
using Operations = ra2::recovered::floating_callers_b40::Operations;
using Inputs = ra2::recovered::floating_b61::Inputs;
void fun_004b57c0(Memory&, State&, Frame&, const Operations& = {});
std::uint32_t fun_004b57c0_global(Memory&, const Inputs&);
}
