#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovery_b429 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
struct Rect { std::int32_t left{}, top{}, right{}, bottom{}; };
using Handle = std::uint32_t;

// Platform boundary: production wrappers can supply real USER32 calls, while
// the recovered routine itself remains independent of Windows headers/APIs.
struct WindowOps {
    virtual ~WindowOps() = default;
    virtual Handle get_parent(Handle) = 0;
    virtual bool get_window_rect(Handle, Rect&) = 0;
    virtual bool get_client_rect(Handle, Rect&) = 0;
    virtual bool move_window(Handle, std::int32_t, std::int32_t,
                             std::int32_t, std::int32_t, bool) = 0;
};

std::uint32_t fun_005e0ed0(Memory&, const Inputs&, WindowOps&);
std::uint32_t fun_005e14e0(Memory&, const Inputs&, WindowOps&);
}
