#pragma once

#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::recovery_b375 {
using Memory = global_b26::Memory;
using U = std::uint32_t;

// Root registers/arguments plus a symbolic entry ESP used only for its
// observed private-frame result pointer. Native validation checks and
// normalizes the real stack identity at the bridge boundary.
struct Inputs {
    global_b26::Inputs regs{};
    U entry_esp = 0;
};

U fun_00617710(Memory&, const Inputs&);
}
