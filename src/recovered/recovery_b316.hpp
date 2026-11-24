#pragma once

#include "recovered/recovery_b305.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b316 {
using Memory = ra2::recovered::recovery_b305::Memory;
using Inputs = ra2::recovered::recovery_b305::Inputs;
using GuestHeap = ra2::recovered::recovery_b305::GuestHeap;
std::uint32_t fun_0046af70(Memory&, Inputs&, GuestHeap&, std::uint32_t frame_base);
}
