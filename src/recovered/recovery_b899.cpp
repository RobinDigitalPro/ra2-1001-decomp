#include "recovered/recovery_b899.hpp"

#include <array>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b899 {
namespace {
using U = std::uint32_t;
constexpr std::array<U, 8> string_globals{
    0x00a27dc4u, 0x00a27dc8u, 0x00a27dccu, 0x00a27dd0u,
    0x00a27dd4u, 0x00a27dd8u, 0x00a27ddcu, 0x00a27de0u};
constexpr std::array<U, 6> excluded_globals{
    0x00a5a89cu, 0x00a5a8a0u, 0x00a5a8a4u,
    0x00a5a8a8u, 0x00a5a8acu, 0x00a5a8b0u};

std::vector<std::uint16_t> read_input(Memory& m, U p) {
    if (!p) throw std::domain_error("B899 null pointer is outside ordinary route");
    std::vector<std::uint16_t> s;
    for (U n = 0; n < 7u; ++n) {
        const auto c = static_cast<std::uint16_t>(m.r16(p + 2u * n));
        if (!c) {
            if (s.empty()) throw std::domain_error("B899 empty input is outside fixture grammar");
            return s;
        }
        s.push_back(c);
    }
    throw std::domain_error("B899 input exceeds six code units");
}

void append_heap_string(Heap& h, Memory& m, U& cursor, U p) {
    for (U n = 0; n < 7u; ++n) {
        const U c = h.r8(p + n * 2u) | (h.r8(p + n * 2u + 1u) << 8u);
        if (!c) {
            m.w8(cursor++, 0u);
            m.w8(cursor++, 0u);
            // The NUL is the next append position: do not advance over it.
            cursor -= 2u;
            return;
        }
        m.w8(cursor++, c);
        m.w8(cursor++, c >> 8u);
    }
    throw std::domain_error("B899 temporary is not terminated within contract");
}

void append_comma(Memory& m, U& cursor) {
    m.w16(cursor, 0x002cu);
    cursor += 2u;
    m.w16(cursor, 0u);
    // cursor remains on the terminator; the next append replaces it.
}
}

U fun_005c2b20(Memory& m, const Inputs& i, Heap& h, U entry_esp) {
    if (!i.cx || entry_esp < 12u) throw std::domain_error("B899 invalid output or entry ESP");
    // 0x75B2F0 and 0x75B390 manipulate an actual target-stack local. Keep
    // its pointer value in this C++ local; never map/write the native stack
    // address through the guest Memory abstraction.
    U local_string = 0u;
    U out = i.cx;
    m.w16(out, 0u);

    for (U slot = 0; slot < string_globals.size(); ++slot) {
        const U source = m.r32(string_globals[slot]);
        if (!source) throw std::domain_error("B899 null-entry special route excluded");
        for (U sentinel_global : excluded_globals)
            if (source == m.r32(sentinel_global))
                throw std::domain_error("B899 sentinel-identity route excluded");
        const auto text = read_input(m, source);
        const U request = 2u * (static_cast<U>(text.size()) + 1u);
        local_string = h.allocate(request); // original 0x75B4B0 -> 0x76D957.
        if (!local_string) throw std::domain_error("B899 allocation failure outside fixture contract");
        for (U n = 0; n < text.size(); ++n) {
            h.w8(local_string + 2u * n, text[n]);
            h.w8(local_string + 2u * n + 1u, text[n] >> 8u);
        }
        h.w8(local_string + 2u * static_cast<U>(text.size()), 0u);
        h.w8(local_string + 2u * static_cast<U>(text.size()) + 1u, 0u);

        append_heap_string(h, m, out, local_string); // 0x76EF9F appends through its NUL.
        append_comma(m, out);                        // 0x7D06DC is WCHAR U+002C, NUL.
        if (!h.release(local_string)) throw std::domain_error("B899 ordinary heap release failed");
        local_string = 0u; // 0x75B390 clears the actual local pointer cell.
    }
    // 75B390 preserves the actual successful HeapFree return in EAX.
    return 1u;
}
}
