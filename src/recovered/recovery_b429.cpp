#include "recovery_b429.hpp"
#include <cstdint>

namespace ra2::recovery_b429 {
namespace {
std::int32_t positive_half_only(std::int32_t extent, std::int32_t screen) {
    const auto difference = std::int64_t(extent) - screen;
    return difference > 0 ? static_cast<std::int32_t>(difference / 2) : 0;
}
bool center_mode(Memory& memory) { return memory.r8(0xa27f64u) != 0; }
}

// Original RVA 0x1e0ed0: EDX points to four signed words (x, y, width,
// height); ECX is the child window handle.
std::uint32_t fun_005e0ed0(Memory& m, const Inputs& i, WindowOps& ops) {
    const Handle window = i.cx;
    const Handle parent = ops.get_parent(window);
    Rect outer{};
    if (!ops.get_window_rect(parent, outer)) return 0;
    std::int32_t dx = 0, dy = 0;
    if (!center_mode(m)) {
        dx = positive_half_only(outer.right - outer.left,
                                static_cast<std::int32_t>(m.r32(0x798c00u)));
        dy = positive_half_only(outer.bottom - outer.top,
                                static_cast<std::int32_t>(m.r32(0x798c0cu)));
    }
    const auto p = i.dx;
    const auto x = static_cast<std::int32_t>(m.r32(p)) + dx;
    const auto y = static_cast<std::int32_t>(m.r32(p + 4u)) + dy;
    const auto width = static_cast<std::int32_t>(m.r32(p + 8u));
    const auto height = static_cast<std::int32_t>(m.r32(p + 12u));
    return ops.move_window(window, x, y, width, height, false) ? 1u : 0u;
}

// Original RVA 0x1e14e0: center a child in the parent's client area, retain
// the original +10 x bias, and bottom-align using the original y expression.
std::uint32_t fun_005e14e0(Memory& m, const Inputs& i, WindowOps& ops) {
    const Handle window = i.cx;
    const Handle parent = ops.get_parent(window);
    Rect client{}, outer{};
    if (!ops.get_client_rect(parent, client) ||
        !ops.get_window_rect(window, outer)) return 0;
    std::int32_t dx = 0, dy = 0;
    if (!center_mode(m)) {
        dx = positive_half_only(client.right - client.left,
                                static_cast<std::int32_t>(m.r32(0x798c00u)));
        dy = positive_half_only(client.bottom - client.top,
                                static_cast<std::int32_t>(m.r32(0x798c0cu)));
    }
    const auto width = outer.right - outer.left;
    const auto height = outer.bottom - outer.top;
    const auto x = dx + client.left + 10;
    const auto y = client.bottom - height - dy - 1;
    return ops.move_window(window, x, y, width, height, false) ? 1u : 0u;
}
}
