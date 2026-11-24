#pragma once

#include "recovered/global_b26_memory.hpp"

#include <cstdint>

namespace ra2::recovered::alloc753 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

class HeapApi {
public:
    virtual ~HeapApi() = default;
    virtual std::uint32_t heap_alloc(std::uint32_t heap,
                                    std::uint32_t flags,
                                    std::uint32_t bytes) = 0;
};

std::uint32_t rva_00376f34(Memory&, const Inputs&, HeapApi&);
}
