#pragma once

#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b469 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
class Allocator {
public:
    virtual ~Allocator() = default;
    virtual std::uint32_t allocate(std::uint32_t bytes) = 0;
};

std::uint32_t fun_005af7c0(Memory&, Inputs&, Allocator&);
}
