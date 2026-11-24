#pragma once
#include "global_b26_memory.hpp"
#include <array>
namespace ra2::recovered::recovery_b289 {
using global_b26::Memory;
struct Inputs {
    std::uint32_t ax{}, cx{}, dx{};
    std::array<std::uint32_t,16> arg{};
    std::uint32_t stack_minus8{}, arithmetic_flags{};
    
    std::array<std::uint8_t,112> raw_stack{}; // exact initial bytes copied by the native bridge
};
std::uint32_t fun_0061b190(Memory&, Inputs&);
std::uint32_t fun_006eb140(Memory&, Inputs&);
}

