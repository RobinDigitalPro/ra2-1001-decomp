#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/decimal_text.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b132 {
using global_b26::Memory;
using floating_b61::Inputs;
// Finite positive-route draft for original RVA 0x6b460. The receiver has one
// sorted section and that section has one sorted key; all names/text are valid.
// Arg0 is output triple; args1/2 section/key; arg3 readable fallback triple.
// virtual_entry_esp is harness address-space metadata for the original entry
// ESP. The root has no corresponding register argument in the game.
std::uint32_t fun_0046b460(Memory&, const Inputs&, std::uint32_t virtual_entry_esp);
}
