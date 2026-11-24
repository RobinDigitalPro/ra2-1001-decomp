#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b357 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
struct Heap {
    virtual ~Heap() = default;
    virtual std::uint32_t allocate(std::uint32_t bytes) = 0;
    virtual void release(std::uint32_t pointer) = 0;
    virtual void write8(std::uint32_t address, std::uint8_t value) = 0;
};
struct Context {
    // Guest address returned by the real TlsGetValue forwarder from the
    // initialized CRT thread-data block. The selected empty-string route
    // writes the retired request-1 owner to PTD+0x18 before freeing it.
    std::uint32_t ptd{};
};
// Finite useful branch only: arg0=0, nonzero B11EE0, zero B7C0D84,
// empty cleanup list and empty B838BEC string. The production native adapter
// must route the single-byte CRT allocation/free through the real small heap.
std::uint32_t fun_004983a0(Memory&, const Inputs&, Heap&, const Context&);
}
