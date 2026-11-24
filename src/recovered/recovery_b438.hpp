#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>
namespace ra2::recovered::gdi438 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
struct Ops {
    void* context{};
    std::uint32_t (*set_bk_color)(void*,std::uint32_t,std::uint32_t){};
    std::uint32_t (*set_text_color)(void*,std::uint32_t,std::uint32_t){};
    std::uint32_t (*text_out_a)(void*,std::uint32_t,std::int32_t,std::int32_t,std::uint32_t,std::uint32_t){};
};
// RVA 0x19b7c0 / VA 0x59b7c0. Exact positive one-byte glyph route, RET12.
std::uint32_t fun_0059b7c0(Memory&, const Inputs&, std::uint32_t caller_arg1_address, const Ops&);
}
