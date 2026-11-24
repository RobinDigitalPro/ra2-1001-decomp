#pragma once

#include "recovered/recovery_b305.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b309 {
using Memory = ra2::recovered::recovery_b305::Memory;
using Inputs = ra2::recovered::recovery_b305::Inputs;
using GuestHeap = ra2::recovered::recovery_b305::GuestHeap;

// Construction draft for RVA 0x10fa60's positive bounded time-string route.
// scratch_base is the mapped 0x20-byte local buffer corresponding to the
// original stack destination; it is bridge state, not an original argument.
std::uint32_t fun_0050fa60(Memory&, Inputs&, GuestHeap&,
                           std::uint32_t scratch_base);
} // namespace ra2::recovered::recovery_b309
