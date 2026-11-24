#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b961 {
using ra2::recovered::global_b26::Memory;
using ra2::recovered::global_b26::Inputs;
using ra2::platform::ordinary_heap::Heap;
std::uint32_t fun_00491bf0(Memory&, const Inputs&, Heap&);
}
