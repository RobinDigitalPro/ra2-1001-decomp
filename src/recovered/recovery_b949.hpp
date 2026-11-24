#pragma once
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>
#include <vector>

namespace b949_model {
using ra2::recovered::global_b26::Memory;
using ra2::recovered::global_b26::Inputs;
using ra2::recovered::global_b26::Function;
inline constexpr std::uint32_t kRva=0x3716d4u;
inline constexpr std::uint32_t kSize=582u;
inline constexpr std::uint32_t kReturnMask=0xffffffffu;
inline constexpr std::uint32_t kTable=0x817454u;
inline constexpr std::uint32_t kLockSlot=0x8172c4u;
inline constexpr std::uint32_t kCounter=0xb10e20u;
inline constexpr std::uint32_t kBackground=0xb10e24u;
std::uint32_t fun_007716d4(Memory& memory,const Inputs& inputs);
} // namespace b949_model
