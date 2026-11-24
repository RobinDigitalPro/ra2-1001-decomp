#pragma once
#include "recovered/global_b26_memory.hpp"
#include "recovered/direct_b34_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b447 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

class Heap {
public:
    virtual ~Heap() = default;
    virtual std::uint32_t allocate(direct_b34::Memory&,std::uint32_t request) = 0;
};

// Finite 0x10c320 route: one initialized sorted section-index hit, ordinal
// zero into a one-node section list, empty output string, and a successful
// exact small-CRT allocation by accepted string helper 0x359260.
std::uint32_t fun_0010c320(Memory&, Inputs&, Heap&);
} // namespace ra2::recovered::recovery_b447
