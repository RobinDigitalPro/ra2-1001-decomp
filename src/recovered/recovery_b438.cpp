#include "recovered/recovery_b438.hpp"
#include <stdexcept>
namespace ra2::recovered::gdi438 {
std::uint32_t fun_0059b7c0(Memory& m, const Inputs& in, std::uint32_t caller_arg1_address, const Ops& ops) {
    if (!ops.set_bk_color || !ops.set_text_color || !ops.text_out_a)
        throw std::domain_error("B438 requires the observed GDI operations");
    const auto hdc = in.arg[0];
    const auto index = in.arg[1];
    const auto offset = in.arg[2];
    const auto state_address = in.cx + 0x7d0u + index * 100u + offset * 4u;
    const auto glyph_state = m.r32(state_address);
    const auto cached_state = m.r32(in.cx + 0x2714u);
    if (glyph_state != cached_state) {
        const auto color_a = m.r32(0xa58a00u);
        const auto color_b = m.r32(0xa58a18u);
        if (glyph_state == 1u) {
            (void)ops.set_bk_color(ops.context, hdc, color_a);
            (void)ops.set_text_color(ops.context, hdc, color_b);
        } else {
            (void)ops.set_bk_color(ops.context, hdc, color_b);
            (void)ops.set_text_color(ops.context, hdc, color_a);
        }
        m.w32(in.cx + 0x2714u, glyph_state);
    }
    const auto glyph_address = in.cx + offset + index * 25u;
    const auto glyph = m.r8(glyph_address);
    m.w8(caller_arg1_address, glyph);
    const auto x = 10u + m.r32(0xa58ad0u) * index;
    const auto y = 10u + (m.r32(0xa58ab8u) + m.r32(0xa58ac8u)) * offset;
    return ops.text_out_a(ops.context, hdc, static_cast<std::int32_t>(x),
                          static_cast<std::int32_t>(y), caller_arg1_address, 1u);
}
} // namespace ra2::recovered::gdi438
