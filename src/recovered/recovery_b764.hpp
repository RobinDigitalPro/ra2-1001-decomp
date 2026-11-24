#pragma once
#include "global_b26_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::recovery_b764 {
using global_b26::Memory;
struct Inputs {
    std::uint32_t ax{}, cx{}, dx{};
    std::array<std::uint32_t, 16> arg{};
    std::uint32_t stack_minus8{}, arithmetic_flags{};
    std::array<std::uint8_t, 112> raw_stack{};
};

// Positive timed-ring route only. Calls the live OS clock through the
// already-established IAT observer installed in Memory at 0x785524.
std::uint32_t fun_0061b240(Memory&, Inputs&);
}
