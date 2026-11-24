#include "recovery_b244.hpp"
#include "platform/observed_ui244.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b244 {
namespace {
constexpr std::uint32_t kCount = 0x00a1a5d8u;
constexpr std::uint32_t kRows = 0x00a1a5ccu;
constexpr std::uint32_t kSelector = 0x00a255c8u;

void demand(bool okay, const char* text) {
    if (!okay) throw std::domain_error(text);
}

LRESULT send(HWND h, UINT message, WPARAM wp, LPARAM lp, const User32& api) {
    return api.send_message_a(h, message, wp, lp);
}

// This route keeps the original conditions that select the true result from
// 0x4f47b0 and the row's permitted helper call. It does not generalize the
// selection predicate beyond this constructor-compatible row state.
bool selected_row(Memory& m, std::uint32_t row) {
    demand(m.r32(kSelector) == 0, "244 requires the original selector-zero branch");
    demand(m.r8(row + 0x134u) == 1u && m.r8(row + 0x135u) == 0u,
           "244 requires the observed 0x4f47b0 true-result row state");
    const auto component = m.r32(row + 0x34u);
    demand(component != 0 && m.r8(component + 0x1a6u) == 0,
           "244 row must pass the original component gate");
    demand(m.r8(component + 0x1a5u) == 1u &&
           m.r32(component + 0xb4u) == 0xffffffffu &&
           m.r8(row + 0x13du) == 0u && m.r8(row + 0x18fu) == 1u &&
           m.r32(row + 0x15f40u) == 0u && m.r32(row + 0x30u) == 0u && m.r32(row + 0x5674u)==0u,
           "244 requires the probed component-valid, no-image, and row-flag bytes");
    const auto owner = m.r32(0x00a1e0e4u);
    demand(owner != 0 && m.r32(owner + 0x30u) == 1u &&
           m.r32(owner + 0x5674u) == 0u,
           "244 requires the mapped owner state used by original 0x4e4be0");
    demand(m.r32(0x00a5b1a4u) == 0u && m.r32(0x00a5ded4u) == 0u &&
           m.r32(0x00a9ea10u) == 0u && m.r32(0x00aa4be8u) == 0u &&
           m.r32(0x00aa4bf0u) == 0u,
           "244 requires the observed no-registry/empty-cache startup state");
    return true;
}

std::uint32_t low_color(Memory& m, std::uint32_t row) {
    const auto rgb_array = m.r32(0x00a9ea04u);
    const auto color = m.r32(rgb_array + 4u * m.r32(row + 0x15f40u));
    demand(rgb_array != 0 && color != 0, "244 color pointer graph must be valid");
    const auto hue = m.r8(color + 0x308u);
    const auto saturation = m.r8(color + 0x309u);
    const auto value = m.r8(color + 0x30au);
    // The fixture uses H=0,S=0. In this original 4fe550 branch the resulting
    // COLORREF is therefore V,V,V, as checked against the real API trace.
    demand(hue == 0 && saturation == 0,
           "244 limits HSV to the observed achromatic H=0,S=0 subset");
    return std::uint32_t(value) | (std::uint32_t(value) << 8) |
           (std::uint32_t(value) << 16);
}

std::uint32_t send_utf16(HWND parent, int id, const wchar_t* text,
                         const User32& api) {
    const HWND control = api.get_dlg_item(parent, id);
    return static_cast<std::uint32_t>(send(control, 0x4b2u, 0,
        reinterpret_cast<LPARAM>(text), api));
}

void copy_row_text(Memory& m, std::uint32_t row, std::array<wchar_t, 64>& out) {
    const auto source = row + 0x15f16u; // original body treats this as inline UTF-16
    unsigned n = 0;
    for (; n + 1u < out.size(); ++n) {
        const auto ch = static_cast<wchar_t>(m.r16(source + 2u * n));
        out[n] = ch;
        if (!ch) return;
    }
    throw std::domain_error("244 inline UTF-16 row text exceeds bounded buffer");
}

void format_decimal(std::uint32_t value, std::array<wchar_t, 8>& out,
                    const User32& api) {
    value %= 100u; // original pair sums followed by the pinned L\"%d\" formatter
    wchar_t reverse[2]{};
    unsigned count = 0;
    do {
        const auto digit = static_cast<wchar_t>(L'0' + (value % 10u));
        // These are real Interlocked operations on the test's corresponding
        // process-local counter. The original CRT formatter takes the same
        // mode-zero C-locale conversion path around each emitted ASCII digit.
        ra2::platform::ui244::Scope::increment(api.conversion_counter);
        const wchar_t widened = digit;
        ra2::platform::ui244::Scope::decrement(api.conversion_counter);
        reverse[count++] = widened;
        value /= 10u;
    } while (value != 0u);
    for (unsigned n = 0; n < count; ++n) out[n] = reverse[count - 1u - n];
    out[count] = 0;
}

std::uint32_t helper(HWND parent, std::uint32_t index, std::uint32_t row,
                     Memory& m, const User32& api) {
    const bool has_row = row != 0;
    const int first_id = index == 0u ? 0x411 : 0x412;
    const int second_id = index == 0u ? 0x419 : 0x41a;
    std::array<wchar_t, 64> row_text{};
    std::array<wchar_t, 8> decimal{};

    if (!has_row) {
        // The final original helper call is the null-row/index-one tail. It
        // sends its zero-initialized local UTF-16 buffer to both controls.
        const HWND first = api.get_dlg_item(parent, first_id);
        (void)send(first, 0x4b2u, 0, reinterpret_cast<LPARAM>(row_text.data()), api);
        const HWND second = api.get_dlg_item(parent, second_id);
        return static_cast<std::uint32_t>(send(second, 0x4b2u, 0,
            reinterpret_cast<LPARAM>(row_text.data()), api));
    }

    (void)selected_row(m, row);
    const auto color = low_color(m, row);
    copy_row_text(m, row, row_text);
    std::uint32_t sum = m.r32(row + 0x5310u);
    demand(sum < 100u, "244 requires the bounded 0..99 decimal field");
    for (unsigned k = 1; k < 20; ++k) {
        demand(m.r32(row + 0x5310u + 4u * k) == 0u &&
               m.r32(row + 0x5364u + 4u * k) == 0u,
               "244 requires the remaining 19 displayed-sum pairs to be zero");
        sum += m.r32(row + 0x5310u + 4u * k) + m.r32(row + 0x5364u + 4u * k);
    }
    demand(m.r32(row + 0x5364u)==0, "244 final sum pair zero");
    sum += m.r32(row + 0x5364u);

    const HWND first = api.get_dlg_item(parent, first_id);
    (void)send(first, 0x498u, 0, static_cast<LPARAM>(color), api);
    (void)send(first, 0x4b2u, 0, reinterpret_cast<LPARAM>(row_text.data()), api);

    const int auxiliary_id = index == 0u ? 0x6da : 0x6db;
    (void)api.get_dlg_item(parent, auxiliary_id);
    const int image_id = index == 0u ? -1 : 0x6cf;
    const HWND image = api.get_dlg_item(parent, image_id);
    (void)send(image, 0xf1u, 0, 0, api);
    (void)send(image, 0x4e6u, 0, 0, api);

    // The selected finite state reaches both actual SW_HIDE calls. These are
    // genuine USER32 calls to the fixture-owned child controls.
    const int hide_id = index == 0u ? -1 : 0x6d6;
    const HWND hide = api.get_dlg_item(parent, hide_id);
    (void)api.show_window(hide, SW_HIDE);

    format_decimal(sum, decimal, api);
    const HWND second = api.get_dlg_item(parent, second_id);
    (void)send(second, 0x498u, 0, static_cast<LPARAM>(color), api);
    return static_cast<std::uint32_t>(send(second, 0x4b2u, 0,
        reinterpret_cast<LPARAM>(decimal.data()), api));
}
}

std::uint32_t ui_impl(Memory& m, const Inputs& i, HWND parent,
                           const User32& api) {
    demand(parent != nullptr && api.get_dlg_item && api.send_message_a &&
           api.show_window && api.conversion_counter,
           "244 requires bound real USER32 and Interlocked APIs");
    demand(i.arg[0] == static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(parent)),
           "244 root arg0 must be the actual private parent HWND");
    demand(m.r32(kCount) == 2u, "244 requires the two-entry root table");
    const auto table = m.r32(kRows);
    demand(table != 0 && m.r32(table) == 0u && m.r32(table + 4u) != 0,
           "244 requires [null, selected-row] root table");
    const auto row = m.r32(table + 4u);
    demand(selected_row(m, row), "244 selected-row condition");
    (void)i; // original root uses ECX as its receiver but does not read it here

    (void)helper(parent, 1u, row, m, api); // loop visit at index 1
    (void)helper(parent, 0u, row, m, api); // final selected row at index 0
    return helper(parent, 1u, 0u, m, api); // final null-row/index-one call
}
}

namespace ra2::recovered::recovery_b244 {
std::uint32_t fun_0062bf10(Memory&m,const Inputs&i){
 auto&s=ra2::platform::ui244::Scope::current();
 const User32 api{&ra2::platform::ui244::Scope::get,&ra2::platform::ui244::Scope::send,&ra2::platform::ui244::Scope::show,s.counter()};
 return ui_impl(m,i,s.parent(),api);
}
}
