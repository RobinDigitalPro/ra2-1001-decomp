#pragma once
#include "recovery_b438.hpp"
#include <cstdint>

namespace ra2::recovered::gdi441 {
using Memory = ra2::recovered::gdi438::Memory;
using Inputs = ra2::recovered::gdi438::Inputs;
struct Ops {
    void* context{};
    std::uint32_t (*get_dc)(void*,std::uint32_t){};
    std::uint32_t (*set_bk_mode)(void*,std::uint32_t,std::uint32_t){};
    std::uint32_t (*select_object)(void*,std::uint32_t,std::uint32_t){};
    std::uint32_t (*set_bk_color)(void*,std::uint32_t,std::uint32_t){};
    std::uint32_t (*set_text_color)(void*,std::uint32_t,std::uint32_t){};
    std::uint32_t (*text_out_a)(void*,std::uint32_t,std::int32_t,std::int32_t,std::uint32_t,std::uint32_t){};
    std::uint32_t (*release_dc)(void*,std::uint32_t,std::uint32_t){};
    std::uint32_t nested_stack_address{};
};
std::uint32_t fun_0059b880(Memory&,const Inputs&,const Ops&);
std::uint32_t fun_0059b4c0(Memory&,const Inputs&,const Ops&);
}
