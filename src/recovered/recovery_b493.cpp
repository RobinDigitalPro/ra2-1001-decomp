#include "recovered/recovery_b493.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b493 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::uint32_t length_guest(const Memory& m, std::uint32_t p) {
    need(p != 0u, "B493 requires a nonnull search string");
    for (std::uint32_t n = 0; n <= 0x10000u; ++n)
        if (m.r8(p + n) == 0u) return n;
    throw std::domain_error("B493 guest string exceeds bounded span");
}

std::uint32_t length_heap(const Heap& h, std::uint32_t p) {
    need(p != 0u, "B493 requires a nonnull candidate string");
    for (std::uint32_t n = 0; n <= 0x10000u; ++n)
        if (h.r8(p + n) == 0u) return n;
    throw std::domain_error("B493 heap string exceeds bounded span");
}

std::uint32_t duplicate_guest(Memory& m, Heap& h, std::uint32_t p, std::uint32_t n) {
    const auto copy = h.allocate(n + 1u);
    need(copy != 0u, "B493 excludes ordinary-heap allocation failure");
    for (std::uint32_t i = 0; i <= n; ++i) h.w8(copy + i, m.r8(p + i));
    return copy;
}

std::uint32_t duplicate_heap(Heap& h, std::uint32_t p, std::uint32_t n) {
    const auto copy = h.allocate(n + 1u);
    need(copy != 0u, "B493 excludes ordinary-heap allocation failure");
    for (std::uint32_t i = 0; i <= n; ++i) h.w8(copy + i, h.r8(p + i));
    return copy;
}

void lowercase_ascii(Heap& h, std::uint32_t p, std::uint32_t n) {
    // Selected 0x76fb34 branch: original global mode 0 and ASCII input.
    for (std::uint32_t i = 0; i < n; ++i) {
        auto c = h.r8(p + i);
        if (c >= 'A' && c <= 'Z') c += 0x20u;
        h.w8(p + i, c);
    }
}

bool equal_bytes(const Heap& h, std::uint32_t a, std::uint32_t b, std::uint32_t n) {
    for (std::uint32_t i = 0; i <= n; ++i)
        if (h.r8(a + i) != h.r8(b + i)) return false;
    return true;
}
}

std::uint32_t fun_005ad480(Memory& m, const Inputs& in, Heap& h) {
    const auto object = in.cx;
    const auto search_holder = in.arg[0];
    need(object != 0u, "B493 requires a nonnull container");
    need(search_holder != 0u, "B493 requires a nonnull pointer slot for the search string");
    need(m.r32(0xb10530u) == 0u,
         "B493 composes only the original locale mode-zero ASCII lowercase route");
    const auto search = m.r32(search_holder);
    const auto search_length = length_guest(m, search);
    need(search_length >= 1017u && search_length <= 1032u,
         "B493 requires the bounded >1016-byte ordinary-heap route");
    const auto count = m.r32(object + 0x10u);
    need(count == 2u, "B493 fixture uses exactly one miss followed by one match");
    const auto entries = m.r32(object + 4u);
    need(entries != 0u, "B493 requires a nonnull entry-pointer array");

    for (std::uint32_t index = 0; index < count; ++index) {
        const auto search_copy = duplicate_guest(m, h, search, search_length);
        lowercase_ascii(h, search_copy, search_length);

        const auto item = m.r32(entries + index * 4u);
        need(item != 0u, "B493 bounded list entries must be nonnull");
        const auto candidate = m.r32(item + 4u);
        const auto candidate_length = length_guest(m, candidate);
        need(candidate_length == search_length,
             "B493 bounded route uses equal-length candidate strings");
        const auto candidate_copy = duplicate_guest(m, h, candidate, candidate_length);
        lowercase_ascii(h, candidate_copy, candidate_length);

        const bool match = equal_bytes(h, search_copy, candidate_copy, search_length);
        const auto free_candidate = h.release(candidate_copy);
        const auto free_search = h.release(search_copy);
        need(free_candidate != 0u && free_search != 0u,
             "B493 selected route requires both real HeapFree operations to succeed");
        // The original passes this saved caller stack word as the output slot
        // for the second temporary; 0x359320 frees and clears that slot.
        in.arg[0] = 0u;
        if (match) return item;
    }
    return 0u;
}
}
