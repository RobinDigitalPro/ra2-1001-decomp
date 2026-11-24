#pragma once

#include <cstdint>
#include <array>

namespace ra2::recovery_b319 {

class Memory {
public:
    virtual ~Memory() = default;
    virtual std::uint8_t r8(std::uint32_t address) const = 0;
    virtual std::uint32_t r32(std::uint32_t address) const = 0;
    virtual void w8(std::uint32_t address, std::uint8_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};

// The native adapter must route these two exact requests through the existing
// real small-CRT/ordinary-heap bridge, preserving allocation identity.
class MixedHeap {
public:
    virtual ~MixedHeap() = default;
    virtual std::uint32_t allocate(std::uint32_t request) = 0;
};

// Each call forwards to the original timeGetTime IAT and records the raw DWORD.
class TickClock {
public:
    virtual ~TickClock() = default;
    virtual std::uint32_t time_get_time() = 0;
};

struct EntryState {
    std::uint32_t eax=0,ecx=0,edx=0,ebx=0,ebp=0,esi=0,edi=0,eflags=0;
    std::array<std::uint32_t,16> caller_words{};
};

// Finite constructor route: a mapped nonzero receiver, successful 0x10 and
// 0x1804 allocations, and all original global input pages mapped. Returns the
// receiver in full EAX; the caller stack has no arguments (RET 0).
std::uint32_t fun_00671080(Memory&, MixedHeap&, TickClock&, EntryState&);

} // namespace ra2::recovery_b319
