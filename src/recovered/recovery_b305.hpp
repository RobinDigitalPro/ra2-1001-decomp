#pragma once

#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b305 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

// The bridge combines declared guest Memory with an allocator and guest
// address-space overlay for small-CRT user blocks. Native use must forward
// allocation/free to the accepted small-CRT protocol; this interface does not
// supply answers for any original callback or virtual dispatch.
class GuestHeap {
public:
    virtual ~GuestHeap() = default;
    virtual std::uint32_t allocate(std::uint32_t bytes) = 0;
    virtual std::uint32_t release(std::uint32_t pointer) = 0;
    virtual std::uint8_t r8(std::uint32_t address) const = 0;
    virtual std::uint32_t r32(std::uint32_t address) const = 0;
    virtual void w8(std::uint32_t address, std::uint32_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};

// Finite route: empty initialized root list/index, nonnull distinct
// section/key/value buffers, and all seven small-CRT allocations succeed.
// Inserts one new section and one new key/value record. Returns exact EAX=1.
std::uint32_t fun_0010da40(Memory&, Inputs&, GuestHeap&);
} // namespace ra2::recovered::recovery_b305
