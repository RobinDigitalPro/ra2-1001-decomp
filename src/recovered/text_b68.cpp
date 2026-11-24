#include "text_b68.hpp"

#include "global_b27_memory.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/text_scan.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::global_b26 {
namespace {

std::uint32_t move_bytes(Memory& m, std::uint32_t destination,
                        std::uint32_t source, std::uint32_t count) {
    const auto src_end = std::uint64_t(source) + count;
    const auto dst_end = std::uint64_t(destination) + count;
    if (src_end > 0x100000000ull || dst_end > 0x100000000ull)
        throw std::domain_error("Block68 memmove excludes wrapping spans");
    if (count > 0x100000u)
        throw std::domain_error("Block68 memmove fixture bound exceeded");
    if (count == 0u || destination == source) return destination;

    if (destination > source && std::uint64_t(destination) < src_end) {
        for (std::uint32_t n = count; n != 0u; --n)
            m.w8(destination + n - 1u, m.r8(source + n - 1u));
    } else {
        for (std::uint32_t n = 0; n < count; ++n)
            m.w8(destination + n, m.r8(source + n));
    }
    return destination;
}

std::vector<std::uint8_t> read_c_string(Memory& m, std::uint32_t p,
                                       std::uint32_t limit) {
    if (std::uint64_t(p) + limit > 0x100000000ull)
        throw std::domain_error("Block68 string bound wraps guest address space");
    std::vector<std::uint8_t> result;
    result.reserve(64);
    for (std::uint32_t n = 0; n < limit; ++n) {
        const auto byte = static_cast<std::uint8_t>(m.r8(p + n));
        result.push_back(byte);
        if (byte == 0u) return result;
    }
    throw std::domain_error("Block68 text input lacks a bounded NUL terminator");
}

const global_b27::Entry& helper_entry(std::uint32_t rva) {
    const auto& entries = global_b27::entries_c();
    const auto it = std::find_if(entries.begin(), entries.end(),
        [rva](const auto& entry) { return entry.rva == rva; });
    if (it == entries.end() || !it->function)
        throw std::logic_error("Block68 required accepted division helper is unavailable");
    return *it;
}

global_b27::State call_u64_helper(Memory& m, std::uint32_t rva,
                                  std::uint32_t low, std::uint32_t high,
                                  std::uint32_t base) {
    global_b27::State state{};
    state.arg[0] = low;
    state.arg[1] = high;
    state.arg[2] = base;
    state.arg[3] = 0u;
    helper_entry(rva).function(m, state);
    return state;
}

std::uint32_t classify_ascii(Memory& m, std::uint8_t byte) {
    const auto width = m.r32(0x0081776cu);
    if (s32(width) > 1)
        throw std::domain_error("Block68 excludes multibyte CRT classification state");
    const auto table_ptr = m.r32(0x00817560u);
    if (table_ptr < 2u || std::uint64_t(table_ptr) + std::uint64_t(byte) * 2u + 2u > 0x100000000ull)
        throw std::domain_error("Block68 CRT classification table span is invalid");

    // Copy the exact original per-byte table word into the accepted helper's
    // analysis adapter; the helper then applies the same 0x107 mask as the
    // original body. This keeps the classified value sourced from seeded PE
    // globals instead of inventing a callback result.
    std::array<std::uint16_t, 257> flags{};
    flags[std::uint32_t(byte) + 1u] = static_cast<std::uint16_t>(m.r16(table_ptr + std::uint32_t(byte) * 2u));
    const ra2::recovered::CrtClassification ops{
        static_cast<std::int32_t>(width), flags.data(), nullptr, nullptr};
    return ra2::recovered::fun_0076e571(static_cast<std::int32_t>(byte), ops);
}

} // namespace

// RVA 0x36ebd0: nonwrapping overlap-safe byte copy. The native body uses
// aligned REP MOVSD and clears DF after its backward REP loop; these byte
// loops preserve its final mapped-memory result and return destination.
std::uint32_t fun_0076ebd0(Memory& m, const Inputs& i) {
    return move_bytes(m, i.arg[0], i.arg[1], i.arg[2]);
}

// RVA 0x36eff0: two stack strings, including the original one-byte shared
// entry into the accepted 0x76fa70 character search.
std::uint32_t fun_0076eff0(Memory& m, const Inputs& i) {
    const auto haystack = i.arg[0];
    const auto pattern = i.arg[1];
    if (std::uint64_t(haystack) + 4096u > 0x100000000ull ||
        std::uint64_t(pattern) + 4096u > 0x100000000ull)
        throw std::domain_error("Block68 substring input bound wraps guest address space");
    const auto first = m.r8(pattern);
    if (first == 0u) return haystack;

    const auto needle = read_c_string(m, pattern, 4096u);
    if (needle.size() == 2u) {
        const auto text = read_c_string(m, haystack, 4096u);
        const auto found = ra2::recovered::fun_0076fa70(
            text.data(), static_cast<std::int32_t>(first));
        if (!found) return 0u;
        return haystack + static_cast<std::uint32_t>(found - text.data());
    }

    std::uint32_t candidate = haystack;
    for (std::uint32_t steps = 0; steps < 4096u; ++steps, ++candidate) {
        const auto c = m.r8(candidate);
        if (!c) return 0u;
        if (c != needle[0]) continue;

        std::size_t k = 1;
        for (;;) {
            if (k == needle.size() - 1u) return candidate;
            const auto h = m.r8(candidate + static_cast<std::uint32_t>(k));
            if (h == 0u || h != needle[k]) break;
            ++k;
        }
    }
    throw std::domain_error("Block68 substring scan exceeded its finite text bound");
}

// RVA 0x371650: unsigned-byte NUL-terminated comparison, returning exactly
// -1, 0, or +1 (the original computes the sign through SBB/SHL/INC).
std::uint32_t fun_00771650(Memory& m, const Inputs& i) {
    auto left = i.arg[0];
    auto right = i.arg[1];
    if (std::uint64_t(left) + 4096u > 0x100000000ull ||
        std::uint64_t(right) + 4096u > 0x100000000ull)
        throw std::domain_error("Block68 comparison input bound wraps guest address space");
    for (std::uint32_t n = 0; n < 4096u; ++n, ++left, ++right) {
        const auto a = m.r8(left);
        const auto b = m.r8(right);
        if (a != b) return a < b ? 0xffffffffu : 1u;
        if (a == 0u) return 0u;
    }
    throw std::domain_error("Block68 comparison exceeded its finite string bound");
}

// RVA 0x3745e0 is an instruction-identical second address for the same
// overlap-aware byte-copy implementation at 0x36ebd0.
std::uint32_t fun_007745e0(Memory& m, const Inputs& i) {
    return move_bytes(m, i.arg[0], i.arg[1], i.arg[2]);
}

// RVA 0x379556: signed-magnitude formatting of a 64-bit argument pair.
// Accepted helpers 0x37b880 and 0x36dec0 supply remainder and quotient limbs.
std::uint32_t fun_00779556(Memory& m, const Inputs& i) {
    auto low = i.arg[0];
    auto high = i.arg[1];
    const auto output = i.arg[2];
    const auto base = i.arg[3];
    const bool negative = i.arg[4] != 0u;
    if (base < 2u || base > 36u)
        throw std::domain_error("Block68 radix must be in 2..36");
    if (output == 0u || std::uint64_t(output) + 66u > 0x100000000ull)
        throw std::domain_error("Block68 radix output needs a nonwrapping 66-byte span");

    auto cursor = output;
    if (negative) {
        m.w8(cursor++, 0x2du);
        const auto borrow = low != 0u ? 1u : 0u;
        low = 0u - low;
        high = 0u - high - borrow;
    }
    const auto digit_start = cursor;
    i.arg[2] = digit_start;

    do {
        const auto remainder_state = call_u64_helper(m, 0x37b880u, low, high, base);
        const auto remainder = remainder_state.ax;
        i.arg[4] = remainder; // Original writes the helper result over stack arg4.
        const auto quotient_state = call_u64_helper(m, 0x36dec0u, low, high, base);
        const auto qlow = quotient_state.ax;
        const auto qhigh = quotient_state.dx;

        m.w8(cursor++, remainder <= 9u ? remainder + 0x30u : remainder + 0x57u);
        low = qlow;
        high = qhigh;
    } while (high != 0u || low != 0u);

    m.w8(cursor, 0u);
    auto last = cursor - 1u;
    auto first = digit_start;
    do {
        const auto cl = m.r8(last);
        const auto dl = m.r8(first);
        m.w8(last, dl);
        m.w8(first, cl);
        --last;
        ++first;
        i.arg[2] = first;
    } while (first < last);
    return first;
}

// RVA 0x8dca0: bounded ASCII escape conversion through the original shared
// scratch buffer. The finite table view invokes the accepted CRT classifier.
std::uint32_t fun_0048dca0(Memory& m, const Inputs& i) {
    constexpr std::uint32_t output = 0x008394a0u;
    constexpr std::uint32_t max_out = 0x3fdu;
    auto source = i.cx;
    std::uint32_t out = 0;
    if (std::uint64_t(source) + 0x400u > 0x100000000ull)
        throw std::domain_error("Block68 ASCII input bound wraps guest address space");

    if (m.r8(source) == 0u) {
        m.w8(output, 0u);
        return output;
    }

    while (out < max_out) {
        const auto byte = m.r8(source);
        if (byte > 0x7fu)
            throw std::domain_error("Block68 CRT fixture contract is limited to ASCII bytes");
        const auto classification = classify_ascii(m, static_cast<std::uint8_t>(byte));
        if (classification != 0u) {
            m.w8(output + out++, byte);
        } else {
            m.w8(output + out++, 0x3du);
            const auto high = byte >> 4u;
            m.w8(output + out++, high < 10u ? high + 0x30u : high + 0x37u);
            const auto low = byte & 0x0fu;
            m.w8(output + out++, low < 10u ? low + 0x30u : low + 0x37u);
        }
        const auto lookahead = m.r8(source + 1u);
        ++source;
        if (lookahead == 0u) break;
    }
    m.w8(output + out, 0u);
    return output;
}

} // namespace ra2::recovered::global_b26
