#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::special_b63 {
using global_b26::Memory;using global_b26::s32;using global_b26::sar;using global_b26::sx16;using global_b26::sx8;
struct Inputs {std::uint32_t ax{},cx{},dx{};mutable std::array<std::uint32_t,64> arg{};std::uint32_t arithmetic_flags{};};
using Function=std::uint64_t(*)(Memory&,const Inputs&);
}
