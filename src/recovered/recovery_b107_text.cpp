#include "recovered/recovery_b107.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/leaf_b16_b.hpp"
#include "recovered/leaf_text_rng.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_006eedc0(Memory&, const Inputs&);
std::uint32_t fun_006eee20(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b107 {
namespace {
constexpr std::uint32_t mode = 0x00b10530u;
constexpr std::uint32_t local_base = 0x34000000u;

std::uint32_t bounded_colon_search(Memory& source, std::uint32_t input) {
    std::array<std::uint8_t, 64> bytes{};
    leaf::Memory local(bytes.data(), local_base, static_cast<std::uint32_t>(bytes.size()));
    std::uint32_t units = 0;
    for (; units < 32u; ++units) {
        const auto value = source.r16(input + units * 2u);
        local.w16(local_base + units * 2u, value);
        if (value == 0u) break;
    }
    if (units == 32u)
        throw std::domain_error("Block107 alignment input exceeds bounded UTF-16 span");
    leaf::Inputs search{};
    search.arg[0] = local_base;
    search.arg[1] = ':';
    return leaf::fun_0076f406(local, search);
}

std::uint32_t bounded_wide_compare(Memory& source, std::uint32_t left, std::uint32_t right) {
    std::array<std::uint8_t, 128> bytes{};
    leaf::Memory local(bytes.data(), local_base, static_cast<std::uint32_t>(bytes.size()));
    auto copy = [&](std::uint32_t destination, std::uint32_t origin) {
        std::uint32_t units = 0;
        for (; units < 32u; ++units) {
            const auto value = source.r16(origin + units * 2u);
            local.w16(destination + units * 2u, value);
            if (value == 0u) return;
        }
        throw std::domain_error("Block107 UTF-16 compare string exceeds bounded span");
    };
    const auto local_left = local_base;
    const auto local_right = local_base + 0x40u;
    copy(local_left, left);
    copy(local_right, right);
    leaf::Inputs compare{};
    compare.arg[0] = local_left;
    compare.arg[1] = local_right;
    return leaf::fun_0076f113(local, compare);
}

void require_zero_mode(const Memory& m) {
    if (m.r32(mode) != 0u)
        throw std::domain_error("Block107 text routes require original mode zero");
}
}

// RVA 0x291500: the selected colon-free route scans the original fixed table,
// compares its UTF-16 keys, and stores the matching enum at output+0x10.
std::uint32_t fun_00691500(Memory& m, const Inputs& i) {
    require_zero_mode(m);
    const auto output = i.dx;
    const auto colon = bounded_colon_search(m, i.cx);
    if (colon != 0u)
        throw std::domain_error("Block107 0x291500 colon route is outside its finite contract");

    auto entry = 0x007dfbb0u;
    std::uint32_t ordinal = 0;
    auto key = m.r32(entry);
    while (key != 0u) {
        Inputs compare{};
        compare.arg[0] = key;
        compare.arg[1] = i.cx;
        const auto result = crt_b83::fun_00781c48(m, compare);
        if (result == 0u) {
            const auto value = m.r32(entry + 4u);
            m.w32(output + 0x10u, value);
            return 0u;
        }
        ++ordinal;
        entry += 8u;
        key = m.r32(entry);
    }
    (void)ordinal;
    m.w32(output + 0x10u, 2u);
    return 2u;
}

// RVA 0x1bea40: widen the query into its original rotating ring, perform the
// separate exact UTF-16 global comparison, then narrow each record name into
// its byte ring and ASCII-fold compare. A nonzero match status exits before
// the unresolved formatter/logger route.
std::uint32_t fun_005bea40(Memory& m, const Inputs& i) {
    require_zero_mode(m);
    const auto query = i.cx;
    std::uint32_t status = i.dx;
    if (query == 0u)
        throw std::domain_error("Block107 0x1bea40 requires a nonnull query");
    if (status == 0u)
        throw std::domain_error("Block107 0x1bea40 requires a nonzero status");

    Inputs widen{};
    widen.cx = query;
    const auto wide_query = global_b26::fun_006eee20(m, widen);
    if (bounded_wide_compare(m, wide_query, 0x00a2793eu) == 0u)
        status = 1u;

    const auto count = m.r32(0x00a27db8u);
    if (count == 0u || count > 4u)
        throw std::domain_error("Block107 record count must be in 1..4");
    const auto records = m.r32(0x00a27dacu);
    std::uint32_t matched = 0;
    for (std::uint32_t n = 0; n < count; ++n) {
        const auto record = m.r32(records + n * 4u);
        const auto old_selector = m.r32(0x00ab7edcu);
        Inputs narrow{};
        narrow.cx = record;
        (void)global_b26::fun_006eedc0(m, narrow);
        const auto bytes = 0x00aa8decu + old_selector * 0x400u;
        Inputs compare{};
        compare.arg[0] = bytes;
        compare.arg[1] = query;
        if (crt_b83::fun_0076d860(m, compare) == 0u) {
            // Preserve the original unaligned DWORD write across +0x6d..+0x70.
            m.w32(record + 0x6du, status);
            matched = 1u;
            break;
        }
    }
    if (matched == 0u)
        throw std::domain_error("Block107 selected record-match route was absent");
    return 0u;
}

} // namespace ra2::recovered::recovery_b107
