#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovery_b432 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

// Bounded present-row route for original RVA 0x37b4d1. The locale identifier
// must match one of the 27 pinned rows; type must be one of the seven table
// fields handled inline/by a pinned string pointer; capacity is 1..32 and the
// destination must be a disjoint writable arena span. Missing rows, unknown
// types, and zero capacity enter the unmodeled GetLocaleInfoA fallback.
std::uint32_t fun_0077b4d1(Memory&, const Inputs&);
}
