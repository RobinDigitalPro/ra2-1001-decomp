#pragma once

#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b336 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

class Heap {
public:
    virtual ~Heap() = default;
    virtual std::uint32_t allocate(std::uint32_t bytes) = 0;
    virtual std::uint32_t release(std::uint32_t pointer) = 0;
    virtual void w8(std::uint32_t address,std::uint8_t value) = 0;
};

// Bounded root projection for RVA 0x14b550. Native assurance must execute
// the original root and exact helper closure; this portable projection does
// not claim allocator-internal equivalence.
std::uint32_t fun_0054b550(Memory&, const Inputs&, Heap&);
std::uint32_t fun_0054b670(Memory&, const Inputs&, Heap&);
}
