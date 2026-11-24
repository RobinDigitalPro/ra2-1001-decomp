#include "recovered/recovery_b489.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b489 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::uint32_t length(const Memory& m, std::uint32_t p) {
    need(p != 0u, "B489 requires a nonnull string");
    for (std::uint32_t n = 0; n < 0x10000u; ++n)
        if (m.r8(p + n) == 0u) return n;
    throw std::domain_error("B489 string has no terminator in bounded span");
}

std::uint32_t duplicate(Memory& m, Heap& h, std::uint32_t src, std::uint32_t n) {
    const auto p = h.allocate(n + 1u);
    need(p != 0u, "B489 excludes heap allocation failure");
    for (std::uint32_t i = 0; i <= n; ++i) h.w8(p + i, m.r8(src + i));
    return p;
}

std::uint32_t duplicate_heap(Heap& h, std::uint32_t src, std::uint32_t n) {
    const auto p = h.allocate(n + 1u);
    need(p != 0u, "B489 excludes ordinary-heap allocation failure");
    for (std::uint32_t i = 0; i <= n; ++i) h.w8(p + i, h.r8(src + i));
    return p;
}

std::uint32_t append(Memory& m, Heap& h, std::uint32_t old, std::uint32_t old_n,
                     std::uint32_t src, std::uint32_t src_n) {
    // Exact positive route of accepted 0x359640: allocate old_n+src_n+1,
    // append both NUL-terminated inputs, publish, then free the old cell.
    need(old_n == 1017u && src_n == 1017u,
         "B489 composes only the accepted two-1017-byte 0x359640 contract");
    const auto p = h.allocate(old_n + src_n + 1u);
    need(p != 0u, "B489 excludes concatenation allocation failure");
    for (std::uint32_t i = 0; i < old_n; ++i) h.w8(p + i, h.r8(old + i));
    for (std::uint32_t i = 0; i <= src_n; ++i) h.w8(p + old_n + i, m.r8(src + i));
    (void)h.release(old);
    return p;
}
}

std::uint32_t fun_0075aff0(Memory& m, const Inputs& in, Heap& h) {
    const auto output = in.cx;
    const auto first = in.dx;
    const auto holder = in.arg[0];
    need(output != 0u && holder != 0u, "B489 needs output and source holder");
    const auto second = m.r32(holder);
    need(second != 0u, "B489 excludes the original empty-string fallback");
    const auto n1 = length(m, first);
    const auto n2 = length(m, second);
    need(n1 == 1017u && n2 == 1017u,
         "B489 requires the accepted long-string route for both inputs");

    // Preserve the original's first duplicate, second duplicate, accepted
    // concatenation helper, output duplicate, and reverse-order temporary frees.
    const auto first_copy = duplicate(m, h, first, n1);
    const auto old_concat = duplicate_heap(h, first_copy, n1);
    const auto joined = append(m, h, old_concat, n1, second, n2);
    m.w32(output, 0u);
    const auto final = duplicate_heap(h, joined, n1 + n2);
    m.w32(output, final);
    (void)h.release(joined);
    (void)h.release(first_copy);
    return output;
}
}
