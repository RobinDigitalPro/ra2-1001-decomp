#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/cpu382.hpp"

namespace ra2::recovered::recovery_b382 {
using Memory=ra2::recovered::global_b26::Memory;
struct Inputs : ra2::recovered::global_b26::Inputs {
    // Explicit modeled guest ID/AC output. Native platform probing restores the
    // host EFLAGS; the differential bridge compares this field to original.
    mutable std::uint32_t flags_out{};
};
using Operations=ra2::platform::cpu382::Operations;
std::uint32_t fun_0076aa8d(Memory&,const Inputs&);
std::uint32_t fun_004d2130(Memory&,const Inputs&);
}
