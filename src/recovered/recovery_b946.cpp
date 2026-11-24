#include "recovery_b946.hpp"
#include "platform/observed_window946.hpp"
#include <windows.h>
namespace ra2::recovered::b946 {
std::uint32_t fun_0075d590(Memory& memory, const Inputs& input) {
    const std::uint32_t object = input.cx;
    const HWND hwnd = reinterpret_cast<HWND>(static_cast<std::uintptr_t>(memory.r32(object + 0x28u)));

    RECT client{};
    (void)ra2::platform::window_api_b946::get_client_rect(hwnd, &client);
    POINT origin{client.left, client.top};
    (void)ra2::platform::window_api_b946::client_to_screen(hwnd, &origin);
    POINT corner{client.right, client.bottom};
    (void)ra2::platform::window_api_b946::client_to_screen(hwnd, &corner);

    const std::uint32_t x = static_cast<std::uint32_t>(origin.x);
    const std::uint32_t y = static_cast<std::uint32_t>(origin.y);
    const std::uint32_t width = static_cast<std::uint32_t>(corner.x) - x;
    const std::uint32_t height = static_cast<std::uint32_t>(corner.y) - y;
    memory.w32(object + 0x2cu, x);
    memory.w32(object + 0x30u, y);
    memory.w32(object + 0x34u, width);
    memory.w32(object + 0x38u, height);

    // The original's final direct call at VA 0x4068f0 is a one-byte RET.
    // EAX therefore remains the width produced immediately before that call.
    return width;
}
}

