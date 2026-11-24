#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b455 {
using Memory=ra2::recovered::floating_b61::Memory;
using Inputs=ra2::recovered::floating_b61::Inputs;

// Finite warm-TLS route for the original 0x3796dc formatter. Input A0 names
// the bounded tm-like record; the already-initialized thread-state +0x38
// points to a writable 26-byte buffer. OS TLS identity is supplied by the
// platform adapter and remains a real per-thread Windows TLS slot.
std::uint32_t fun_003796dc(Memory&,const Inputs&);
}
