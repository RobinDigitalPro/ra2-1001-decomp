#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <memory>
#include <vector>

namespace ra2::recovered::recovery_b920 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
std::uint32_t fun_006b42d0(Memory&, const Inputs&, ra2::platform::ordinary_heap::Heap&,
                           std::vector<std::unique_ptr<leaf::Memory>>& live_spans);
}
