#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/decimal_text.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b130 {
using global_b26::Memory;
using floating_b61::Inputs;
// Finite positive-route draft for original RVA 0x6c480. The receiver has one
// sorted section and that section has one sorted key; all names/text are valid.
// Args 0/1 are section/key pointers, args 2/3/4 are OUTPUT POINTERS.
// virtual_entry_esp is harness address-space metadata for the original entry
// ESP. The root has no corresponding register argument in the game.
std::uint32_t fun_0046c480(Memory&, const Inputs&, std::uint32_t virtual_entry_esp);
}
