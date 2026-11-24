#include "recovered/lookup_b67.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::lookup_b67 {
namespace {
using global_b26::sar;
using global_b26::s32;
using global_b26::sx16;

constexpr std::uint32_t kMapPointer = 0x0081a958u;
constexpr std::uint32_t kFallbackObject = 0x00a57610u;
constexpr std::uint32_t kFallbackInput = 0x00a57634u;
constexpr std::uint32_t kMapCells = 0x40000u;

std::uint32_t tile_index(std::uint16_t x, std::uint16_t y) {
    return (sx16(y) << 9) + sx16(x);
}

std::uint32_t tile_object(Memory& m, std::uint32_t map,
                          std::uint16_t x, std::uint16_t y,
                          std::uint32_t coordinate_object) {
    (void)coordinate_object;
    const auto index = tile_index(x, y);
    if (s32(index) < 0 || s32(index) >= static_cast<std::int32_t>(kMapCells)) {
        m.w32(kFallbackInput, std::uint32_t(x)|(std::uint32_t(y)<<16));
        return kFallbackObject;
    }
    const auto object = m.r32(map + index * 4u);
    if (object != 0) return object;
    m.w32(kFallbackInput, std::uint32_t(x)|(std::uint32_t(y)<<16));
    return kFallbackObject;
}

std::uint32_t classify_tables(std::uint32_t first_type,
                              std::uint32_t first_base,
                              const std::uint8_t* first_selector,
                              std::uint32_t first_count,
                              std::uint32_t second_type,
                              std::uint32_t second_base,
                              const std::uint8_t* second_selector,
                              std::uint32_t second_count) {
    std::uint32_t result = 0;
    const auto first_index = first_type - first_base;
    if (first_index <= first_count) {
        const auto selected = first_selector[first_index];
        if (selected == 0) result = 1;
        else if (selected == 1) result = 2;
    }
    const auto second_index = second_type - second_base;
    if (second_index <= second_count) {
        const auto selected = second_selector[second_index];
        if (selected == 0) result |= 4;
        else if (selected == 1) result |= 8;
    }
    return result;
}

constexpr std::array<std::uint8_t, 23> kA860First{{
    0,2,0,1,0,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,1
}};
constexpr std::array<std::uint8_t, 22> kA860Second{{
    0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,1
}};
constexpr std::array<std::uint8_t, 15> kA980First{{
    0,2,0,1,0,2,2,2,2,2,0,2,2,2,1
}};
constexpr std::array<std::uint8_t, 14> kA980Second{{
    0,0,0,1,2,2,2,2,2,2,2,0,2,1
}};
constexpr std::array<std::uint8_t, 23> kB960First{{
    0,2,0,1,0,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,1
}};
constexpr std::array<std::uint8_t, 22> kB960Second{{
    0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,1
}};
constexpr std::array<std::uint8_t, 15> kBa90First{{
    0,2,0,1,0,2,2,2,2,2,0,2,2,2,1
}};
constexpr std::array<std::uint8_t, 14> kBa90Second{{
    0,0,0,1,2,2,2,2,2,2,2,0,2,1
}};

std::uint32_t elapsed_remaining(Memory& m, const Inputs& i) {
    auto remaining = m.r32(i.cx + 0x168u);
    const auto start = m.r32(i.cx + 0x160u);
    if (start != 0xffffffffu) {
        const auto now = m.r32(0x00a2896cu);
        const auto elapsed = now - start;
        if (s32(elapsed) >= s32(remaining)) remaining = 0;
        else remaining -= elapsed;
    }
    return remaining;
}

std::uint32_t sar_div(std::uint32_t value, unsigned shift) {
    const auto bias = s32(value) < 0 ? ((1u << shift) - 1u) : 0u;
    return sar(value + bias, shift);
}

std::uint32_t magic_div20(std::uint32_t value) {
    auto q = sar(global_b26::imul_high(0x66666667u, value), 3);
    q += static_cast<std::uint32_t>(s32(q) < 0);
    return q;
}

std::uint32_t magic_div6(std::uint32_t value) {
    auto q = global_b26::imul_high(0x2aaaaaabu, value);
    q += static_cast<std::uint32_t>(s32(q) < 0);
    return q;
}

std::uint32_t duration_formula(std::uint32_t format, std::uint32_t remaining,
                              std::uint32_t scale) {
    std::uint32_t raw = 0;
    switch (format) {
    case 1:
        // 0x6cdca7 jumps to the shared signed division by six at 0x6cdd22.
        raw = magic_div6((12u - remaining) << 8);
        break;
    case 2:
    case 8:
        raw = 0x200u;
        break;
    case 3: {
        const auto numerator = remaining * 461u + 1020u;
        raw = magic_div20(numerator);
        break;
    }
    case 4: {
        const auto numerator = 1024u - remaining * 77u;
        raw = sar_div(numerator, 3);
        break;
    }
    case 5: {
        const auto numerator = remaining * 77u + 0x330u;
        raw = sar_div(numerator, 4);
        break;
    }
    case 6:
        raw = 0x33u;
        break;
    case 7: {
        const auto numerator = 0xc00u - remaining * 461u;
        raw = magic_div6(numerator);
        break;
    }
    case 9: {
        const auto numerator = (remaining + 0x14u) << 8;
        raw = magic_div20(numerator);
        break;
    }
    default:
        return scale;
    }
    auto result = sar(raw * scale, 8);
    if (s32(result) > 0x7d0) result = 0x7d0;
    return result;
}
} // namespace

std::uint32_t fun_0055a860(Memory& m, const Inputs& i) {
    auto x = static_cast<std::uint16_t>(m.r16(i.cx));
    auto y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    const auto map = m.r32(kMapPointer);
    const auto first = tile_object(m, map, static_cast<std::uint16_t>(x - 1u), y, i.cx);
    const auto first_type = m.r32(first + 0x44u);
    x = static_cast<std::uint16_t>(m.r16(i.cx));
    y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    const auto second = tile_object(m, map, static_cast<std::uint16_t>(x + 1u), y, i.cx);
    const auto second_type = m.r32(second + 0x44u);
    return classify_tables(second_type, 0x4eu, kA860First.data(), 0x16u,
                           first_type, 0x4fu, kA860Second.data(), 0x15u);
}

std::uint32_t fun_0055a980(Memory& m, const Inputs& i) {
    auto y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    auto x = static_cast<std::uint16_t>(m.r16(i.cx));
    const auto map = m.r32(kMapPointer);
    const auto first = tile_object(m, map, x, static_cast<std::uint16_t>(y - 1u), i.cx);
    const auto first_type = m.r32(first + 0x44u);
    x = static_cast<std::uint16_t>(m.r16(i.cx));
    y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    const auto second = tile_object(m, map, x, static_cast<std::uint16_t>(y + 1u), i.cx);
    const auto second_type = m.r32(second + 0x44u);
    return classify_tables(first_type, 0x57u, kA980First.data(), 0xeu,
                           second_type, 0x58u, kA980Second.data(), 0xdu);
}

std::uint32_t fun_0055b960(Memory& m, const Inputs& i) {
    auto x = static_cast<std::uint16_t>(m.r16(i.cx));
    auto y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    const auto map = m.r32(kMapPointer);
    const auto first = tile_object(m, map, static_cast<std::uint16_t>(x - 1u), y, i.cx);
    const auto first_type = m.r32(first + 0x44u);
    x = static_cast<std::uint16_t>(m.r16(i.cx));
    y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    const auto second = tile_object(m, map, static_cast<std::uint16_t>(x + 1u), y, i.cx);
    const auto second_type = m.r32(second + 0x44u);
    return classify_tables(second_type, 0xd1u, kB960First.data(), 0x16u,
                           first_type, 0xd2u, kB960Second.data(), 0x15u);
}

std::uint32_t fun_0055ba90(Memory& m, const Inputs& i) {
    auto y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    auto x = static_cast<std::uint16_t>(m.r16(i.cx));
    const auto map = m.r32(kMapPointer);
    const auto first = tile_object(m, map, x, static_cast<std::uint16_t>(y - 1u), i.cx);
    const auto first_type = m.r32(first + 0x44u);
    x = static_cast<std::uint16_t>(m.r16(i.cx));
    y = static_cast<std::uint16_t>(m.r16(i.cx + 2u));
    const auto second = tile_object(m, map, x, static_cast<std::uint16_t>(y + 1u), i.cx);
    const auto second_type = m.r32(second + 0x44u);
    return classify_tables(first_type, 0xdau, kBa90First.data(), 0xeu,
                           second_type, 0xdbu, kBa90Second.data(), 0xdu);
}

std::uint32_t fun_006a8100(Memory&, const Inputs& i) {
    constexpr std::array<std::uint8_t, 117> selector{{
        0,0,0,1,1,0,1,2,0,3,4,5,0,0,31,31,2,2,6,7,8,5,31,31,9,9,9,10,10,11,31,31,
        12,12,13,0,0,0,9,14,15,16,17,9,31,31,31,18,31,31,31,19,5,5,20,21,21,22,2,
        31,31,31,2,2,2,2,31,31,31,23,24,24,9,0,0,9,9,9,9,25,31,31,31,9,11,11,11,
        26,2,2,31,31,31,2,2,2,31,6,27,3,2,2,4,28,1,29,25,30,2,9,31,2,0,9,29,2,3
    }};
    constexpr std::array<std::uint32_t, 32> value{{
        0x0d,0x0c,0x09,0x02,0x27,0x0b,0x03,0x01,0x04,0x0a,0x16,0x10,0x11,0x0f,0x15,0x17,
        0x18,0x1b,0x1e,0x19,0x1c,0x1d,0x1f,0x1a,0x21,0x22,0x23,0x26,0x28,0x2b,0x2c,0x00
    }};
    const auto index = i.cx - 1u;
    if (index > 0x74u) return 0;
    return value[selector[index]];
}

std::uint32_t fun_006cdc60(Memory& m, const Inputs& i) {
    const auto remaining = elapsed_remaining(m, i);
    const auto format = m.r32(i.cx + 0x16cu);
    return duration_formula(format, remaining, i.arg[0]);
}
} // namespace ra2::recovered::lookup_b67
