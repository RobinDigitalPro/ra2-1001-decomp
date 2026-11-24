#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <array>
#include <cstdint>
#include <vector>

namespace ra2::recovered::recovery_b974 {
using global_b26::Memory;
using global_b26::Inputs;
using ra2::platform::ordinary_heap::Heap;
struct Observation {
    std::uint32_t temporary=0, output=0;
    std::vector<std::uint32_t> selected;
    std::array<std::uint8_t,48> temporary_before_free{};
};
std::uint32_t run(Memory&,const Inputs&,Heap&,std::uint32_t root,Observation&);
}
