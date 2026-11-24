#pragma once

#include "recovered/recovery_b305.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b314 {
using Memory = ra2::recovered::recovery_b305::Memory;
using Inputs = ra2::recovered::recovery_b305::Inputs;
using GuestHeap = ra2::recovered::recovery_b305::GuestHeap;

// One-row route for RVA 0x6b730. The collection is outer arg2; ECX is the
// independent initialized root. The joined two-byte row text is private local
// stack storage supplied at a symbolic bridge address.
std::uint32_t fun_0046b730(Memory&, Inputs&, GuestHeap&, std::uint32_t scratch_base);
}
