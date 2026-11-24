#pragma once

// Bounded Block236 implementation. This is the exact final-live1->0,
// left-neighbour, same-class branch from original RVA 0x3733a8. It is not a
// general small-heap free implementation.
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::platform::small_crt_heap781::empty236 {
namespace detail {
inline void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

inline void release_last_class2(X86Memory& m, std::uint32_t user) {
    using detail::require;
    constexpr std::uint32_t tracker_table = 0x00b10e10u;
    constexpr std::uint32_t tracker_chunk = 0x00b10e08u;

    const auto expected_record = m.r32(0x00b10e0cu);
    require(expected_record != 0,
            "Block236 requires a nonnull current CRT region record");
    const auto expected_arena = m.r32(expected_record + 0x0cu);
    const auto expected_metadata = m.r32(expected_record + 0x10u);
    require(expected_arena != 0 && expected_metadata != 0,
            "Block236 requires the probed small-CRT allocation identities");
    require(m.r32(0x00b10e14u) == 1u &&
            m.r32(0x00b10e18u) == expected_record,
            "Block236 requires its only registered/current CRT region");
    require(m.r32(expected_record + 4u) == 1u &&
            m.r32(expected_record + 8u) == 0x7fffffffu &&
            m.r32(expected_record + 0x0cu) == expected_arena &&
            m.r32(expected_record + 0x10u) == expected_metadata &&
            m.r32(expected_metadata) == 0u,
            "Block236 region record/chunk-zero metadata differs from the probe");
    require(m.r32(tracker_table) == 0u && m.r32(tracker_chunk) == 0u,
            "Block236 final-free route requires the initially empty-chunk tracker");

    // Requests 32/40 round to span 0x30, allocated from the high edge of the
    // initial 0xff0 class-63 extent. RVA 0x3733a8 computes chunk 0 at VA
    // 0x7733c5, the class-63 index at 0x77346e..0x773477, and merges the
    // left footer at 0x77348b..0x7734a7. The old and merged spans are both
    // class 63, so VA 0x7734b9/0x773528 keeps the existing ring node in place.
    const auto node = expected_arena + 0x0cu;
    const auto class63_head = expected_metadata + 0x144u + 63u * 8u;
    require(m.r8(expected_metadata + 0x43u) == 1u &&
            m.r32(expected_metadata + 0xc4u) == 1u,
            "Block236 requires the one available class-63 extent in chunk zero");
    require(user == expected_arena + 0xfd0u &&
            m.r32(user - 4u) == 0x31u &&
            m.r32(user + 0x30u - 8u) == 0x31u &&
            m.r32(user + 0x30u - 4u) == 0xffffffffu,
            "Block236 requires the exact allocated span-0x30 payload and terminal sentinel");
    require(m.r32(node) == 0xfc0u && m.r32(node + 0xfc0u - 4u) == 0xfc0u &&
            m.r32(node + 4u) == expected_arena + 0x100cu &&
            m.r32(node + 8u) == class63_head &&
            m.r32(class63_head + 4u) == node &&
            m.r32(class63_head + 8u) == expected_arena + 0x700cu,
            "Block236 left class-63 free extent/ring differs from the probe state");
    require(m.r32(expected_metadata + 0x144u) == 1u,
            "Block236 requires exactly one live small allocation in chunk zero");

    // Original VA 0x7735c6 writes the merged header at the left block start;
    // 0x7735c8 writes the matching footer. VA 0x7735cc changes the live count
    // 1->0. Since B10e10 is still zero, VA 0x7735d4..0x7735db branches to
    // 0x7736c0 (no VirtualFree/HeapFree/decommit). VA 0x7736c3 and 0x7736c8
    // record the now-empty region/chunk. No class counts, bitmaps, ring links,
    // B10e0c cursor, B10e14 region count, or B10e18 cursor are changed.
    m.w32(node, 0x0ff0u);
    m.w32(node + 0x0ff0u - 4u, 0x0ff0u);
    m.w32(expected_metadata + 0x144u, 0u);
    m.w32(tracker_table, expected_record);
    m.w32(tracker_chunk, 0u);
}
} // namespace ra2::platform::small_crt_heap781::empty236
