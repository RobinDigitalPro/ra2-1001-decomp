#pragma once

#include <array>
#include <cstdint>

namespace ra2::recovery_b306 {

// Portable guest-memory views for the bounded positive allocation route.
// They are not claims about an original source-level class or ABI.
class Memory {
public:
    virtual ~Memory() = default;
    virtual std::uint8_t r8(std::uint32_t address) const = 0;
    virtual std::uint32_t r32(std::uint32_t address) const = 0;
    virtual void w8(std::uint32_t address, std::uint8_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};

// One exact route-specific allocator/address-space bridge. The small result
// owns a class-1 block; the ordinary result owns its raw HeapAlloc base.
class MixedHeap {
public:
    virtual ~MixedHeap() = default;
    virtual std::uint32_t allocate(std::uint32_t request) = 0;
    virtual void w8(std::uint32_t address, std::uint8_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};

struct EntryState {
    std::uint32_t ax = 0, cx = 0, dx = 0;
    std::uint32_t bx = 0, bp = 0, si = 0, di = 0, eflags = 0;
    std::array<std::uint32_t, 16> caller_words{};
};

// Bounded success route for RVA 0x229300: two nonnull calls to the same
// allocator in order (0x10, then 0x1804). Returns the observed full EAX=0x100.
std::uint32_t fun_00629300(Memory&, MixedHeap&, EntryState&);

} // namespace ra2::recovery_b306
