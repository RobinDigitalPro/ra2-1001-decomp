#pragma once

#include "recovered/floating_b61_memory.hpp"
#include <windows.h>

namespace ra2::recovered::recovery_b244 {
using floating_b61::Inputs;
using floating_b61::Memory;

// These are real OS calls on the bounded comparison route. The adapter carries
// no mock return values; the test binds the original and translated executions
// to owned STATIC controls and forwards to USER32.
struct User32 {
    HWND (WINAPI* get_dlg_item)(HWND, int);
    LRESULT (WINAPI* send_message_a)(HWND, UINT, WPARAM, LPARAM);
    BOOL (WINAPI* show_window)(HWND, int);
    volatile LONG* conversion_counter;
};

std::uint32_t fun_0062bf10(Memory&, const Inputs&);
}
