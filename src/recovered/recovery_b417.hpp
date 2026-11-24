#pragma once
#include "recovered/recovery_b406.hpp"
#include <cstdint>

namespace ra2::recovery_b417 {
using ra2::recovery_b406::Memory;using ra2::recovery_b406::Heap;
std::uint32_t fun_006e9c80(Memory&, const ra2::recovered::global_b26::Inputs&, Heap&);
std::uint32_t fun_006e83a0(Memory&, const ra2::recovered::global_b26::Inputs&, Heap&);
}
