#pragma once

#include "recovered/global_b26_memory.hpp"

#include <cstdint>

namespace ra2::recovered::heap754 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

// Platform boundary for the positive preinitialized-lock/ordinary-heap route.
// Implementations used by fixtures forward to real Win32 APIs and record the
// exact arguments/results; this interface does not supply synthetic results.
class Operations {
public:
    virtual ~Operations() = default;
    virtual void enter_critical_section(std::uint32_t address) = 0;
    virtual void leave_critical_section(std::uint32_t address) = 0;
    virtual std::uint32_t heap_realloc(std::uint32_t heap,
                                       std::uint32_t flags,
                                       std::uint32_t block,
                                       std::uint32_t bytes) = 0;
};

std::uint32_t rva_00374b05(Memory&, const Inputs&, Operations&);
}
