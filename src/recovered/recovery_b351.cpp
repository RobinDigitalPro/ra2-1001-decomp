#include "recovery_b351.hpp"

#include "recovered/map_b106.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b351 {
namespace {
void need(bool value, const char* message) {
    if (!value) throw std::domain_error(message);
}

std::uint32_t packed_neighbor(Memory& m, std::uint32_t cell, unsigned direction) {
    need(direction < 8u, "351 eight original directions only");
    const auto packed = m.r32(cell + 0x24u);
    const auto x = static_cast<std::uint16_t>(packed);
    const auto y = static_cast<std::uint16_t>(packed >> 16);
    const auto dx = static_cast<std::uint16_t>(m.r16(0x00839da0u + direction * 4u));
    const auto dy = static_cast<std::uint16_t>(m.r16(0x00839da2u + direction * 4u));
    return std::uint32_t(static_cast<std::uint16_t>(x + dx)) |
           (std::uint32_t(static_cast<std::uint16_t>(y + dy)) << 16);
}

std::uint32_t original_cell_lookup(Memory& m, std::uint32_t packed) {
    const auto x = static_cast<std::int16_t>(packed);
    const auto y = static_cast<std::int16_t>(packed >> 16);
    const auto index = std::int32_t(y) * 512 + std::int32_t(x);
    const auto table = m.r32(0x0081a820u + 0x138u);
    if (index >= 0 && index < 0x40000) {
        const auto cell = m.r32(table + std::uint32_t(index) * 4u);
        if (cell != 0u) return cell;
    }
    m.w32(0x00a57634u, packed);
    return 0x00a57610u;
}

std::uint32_t record_for(Memory& m, std::uint32_t cell) {
    const auto packed = m.r32(cell + 0x24u);
    const auto x = static_cast<std::int16_t>(packed);
    const auto y = static_cast<std::int16_t>(packed >> 16);
    const auto factor = m.r32(0x00836b4cu);
    const auto linear = std::uint32_t(std::int32_t(y) * std::int32_t(factor) + std::int32_t(x));
    return m.r32(0x00a5863cu) + linear * 80u;
}

std::uint32_t classify(Memory& m, const Inputs& root, std::uint32_t cell) {
    ra2::recovered::map_b106::Inputs nested{};
    nested.cx = root.cx;
    nested.arg[0] = cell;
    nested.arg[1] = 2u;
    nested.fp = root.fp;
    const auto result = ra2::recovered::map_b106::fun_0055a200(m, nested);
    root.fp = nested.fp;
    return result;
}
}

std::uint32_t fun_00559310(Memory& m, const Inputs& input) {
    const auto& i = input;
    const auto root = i.arg[0];
    const auto event_range = m.r32(0x00a3a1b8u);
    const auto event = m.r32(root + 0x38u);
    need(static_cast<std::int32_t>(event) >= static_cast<std::int32_t>(event_range) &&
             static_cast<std::int32_t>(event) < static_cast<std::int32_t>(event_range + 0x0cu),
         "351 root event tag must select original positive classification");

    const auto initial = classify(m, i, root);
    constexpr std::array<std::uint32_t, 8> accepted{
        0xc7u, 0x7cu, 0xf1u, 0x1fu, 0xc6u, 0x6cu, 0xb1u, 0x1bu};
    bool selected = false;
    for (const auto code : accepted) selected = selected || initial == code;
    need(selected, "351 root category must be one of the eight original accepted codes");

    m.w32(root + 0x38u, 0x0000ffffu);
    m.w8(root + 0x11au, 0u);
    if (static_cast<std::uint8_t>(i.arg[2]) != 0u)
        m.w32(record_for(m, root) + 0x38u, i.arg[1]);

    std::uint32_t eax = initial;
    const auto lower = m.r32(0x00a58634u);
    const auto upper = m.r32(0x00a58638u);
    std::array<std::uint32_t, 8> seen{};
    for (unsigned direction = 0; direction < 8u; ++direction) {
        const auto packed = packed_neighbor(m, root, direction);
        const auto cell = original_cell_lookup(m, packed);
        need(cell != 0x00a57610u && m.r32(cell + 0x24u) == packed,
             "351 each original direction must resolve to its distinct supplied map cell");
        for (unsigned prior = 0; prior < direction; ++prior)
            need(seen[prior] != cell, "351 eight neighbor cells must be distinct");
        seen[direction] = cell;

        const auto object_xy = m.r32(cell + 0x24u);
        i.arg[2] = object_xy; // original entryESP+0xc reused for packed neighbor
        const auto x = std::int32_t(static_cast<std::int16_t>(object_xy));
        const auto y = std::int32_t(static_cast<std::int16_t>(object_xy >> 16));
        const auto sum = std::uint32_t(x + y);
        const auto diff = std::uint32_t(x - y);
        need(std::int32_t(sum) > std::int32_t(lower) &&
                 std::int32_t(diff) < std::int32_t(lower) &&
                 std::int32_t(-diff) < std::int32_t(lower) &&
                 std::int32_t(sum) <= std::int32_t(upper),
             "351 neighbor must take original bounded record-update path");

        const auto record = record_for(m, cell);
        m.w32(record + 0x40u, 0xffffffffu);
        eax = classify(m, i, cell);
        m.w32(record + 0x40u, eax);
    }
    return eax;
}
}
