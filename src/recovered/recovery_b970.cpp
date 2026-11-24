#include "recovery_b970.hpp"
#include "platform/observed_window970.hpp"
#include <stdexcept>
#include <cstdint>

namespace ra2::recovered::b970 {
static std::int32_t s32(std::uint32_t v) { return static_cast<std::int32_t>(v); }
std::uint32_t fun_005e12d0(Memory& m, const Inputs& i) {
    const HWND target=reinterpret_cast<HWND>(std::uintptr_t(i.cx));
    const HWND parent=ra2::platform::window_api_b970::get_parent(target);
    const std::uint32_t helper_byte=m.r8(0x00a27f64u);
    RECT pr{},tr{};
    ra2::platform::window_api_b970::get_window_rect(parent,&pr);
    ra2::platform::window_api_b970::get_window_rect(target,&tr);
    const std::int32_t width=pr.right-pr.left;
    std::int32_t x=0,y=0,cx=0,cy=0;
    if(helper_byte==0) {
        const std::int32_t delta=width-s32(m.r32(0x00798c00u));
        const std::int32_t padding=delta/2;
        x=width-(padding>0?padding:0)-0x9c;
        const std::uint32_t size_ptr=m.r32(0x00aa8b70u);
        cx=static_cast<std::int16_t>(m.r16(size_ptr+2));
        cy=static_cast<std::int16_t>(m.r16(size_ptr+4));
        const std::uint32_t top_ptr=m.r32(0x00aa8c58u);
        const std::int32_t t=s32(m.r32(top_ptr+4));
        const std::int32_t step=s32(m.r32(top_ptr+0x0c));
        const std::uint32_t bottom_ptr=m.r32(0x00aa8c5cu);
        const std::int32_t u=s32(m.r32(bottom_ptr+4));
        if(step<=0)throw std::domain_error("970 positive step required");
        y=t+((u-t)/step-1)*step;
    } else {
        x=width-0x93;
        const std::uint32_t size_ptr=m.r32(0x00aa8b00u);
        cx=static_cast<std::int16_t>(m.r16(size_ptr+2));
        cy=static_cast<std::int16_t>(m.r16(size_ptr+4));
        const std::uint32_t y_ptr=m.r32(0x00aa8c80u);
        y=s32(m.r32(y_ptr+4))-cy;
    }
    return static_cast<std::uint32_t>(ra2::platform::window_api_b970::move_window(target,x,y,cx,cy,FALSE));
}
}
