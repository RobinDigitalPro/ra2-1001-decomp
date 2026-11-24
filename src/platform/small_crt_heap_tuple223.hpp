#pragma once

// Exact transitions for RVA1AE0A0 four one-character comma-separated tokens.
// Parent reviewed right-unlink-first and unchanged-class63 merge order.
#include "platform/small_crt_heap_algorithm.hpp"
#include <cstdint>
#include <vector>

namespace ra2::platform::small_crt_heap::tuple223 {
using ra2::platform::small_crt_heap::X86Memory;
inline const std::vector<unsigned>& requests(){static const std::vector<unsigned> r{1,9,2,2,2,7,2,2,5,2,2,3,2,2};return r;}

// Allocation #4 (request 2) consumes the sole class-1 span-0x20 suffix block,
// splits it into a class-0 span-0x10 remainder and an allocated high half.
inline std::uint32_t allocate_class1_span20_split10(X86Memory&, std::uint32_t request,
                                             std::uint32_t entry_esp,
                                             std::uint32_t expected_live);

// Allocations #5/#8/#11/#14 consume a sole exact-fit class-0 node (request 2).
inline std::uint32_t allocate_exact_class0_span10(X86Memory&, std::uint32_t request,
                                           std::uint32_t entry_esp,
                                           std::uint32_t expected_user_offset,
                                           std::uint32_t expected_live);

// Isolated free-list inserts for the exact class-1 suffix #2 and class-0
// destination/suffix blocks #1/#6/#9/#12.
inline void release_isolated_span(X86Memory&, std::uint32_t user,
                           std::uint32_t span, std::uint32_t expected_user_offset,
                           std::uint32_t expected_live);

// Free #3: right class-0 block is unlinked first, then the current 0x10 block
// coalesces with both it and the left class-63 extent; the class-63 node stays
// linked because its class is unchanged.
inline void release_span10_between_class63_and_class0(X86Memory&,
                                                std::uint32_t user,
                                                std::uint32_t expected_live);

// Scratch/token frees #7/#10/#13 and prior/final tokens #4/#8/#11/#14.
// Only the left class-63 extent merges; the right neighbor is live.
inline void release_left_class63_span10(X86Memory&, std::uint32_t user,
                                 std::uint32_t expected_left_span,
                                 std::uint32_t expected_live);

} // namespace ra2::platform::small_crt_heap::tuple223


#include <stdexcept>

namespace ra2::platform::small_crt_heap::tuple223 {
namespace {
[[noreturn]] void reject(const char* why) { throw std::domain_error(why); }
void require(bool ok, const char* why) { if (!ok) reject(why); }

struct Chunk {
    std::uint32_t record;
    std::uint32_t arena;
    std::uint32_t metadata;
};

Chunk require_chunk(X86Memory& m) {
    const auto record = m.r32(0x00b10e0cu);
    require(record && m.r32(0x00b10e14u) == 1u &&
            m.r32(0x00b10e18u) == record &&
            m.r32(record + 4u) == 1u &&
            m.r32(record + 8u) == 0x7fffffffu,
            "tuple route requires its one current region and consumed chunk zero");
    const auto arena = m.r32(record + 0x0cu);
    const auto metadata = m.r32(record + 0x10u);
    require(arena && metadata && m.r32(metadata) == 0u &&
            m.r8(metadata + 0x43u) == 1u && m.r32(metadata + 0xc4u) == 1u,
            "tuple route requires initialized chunk zero and its original page ring");
    const auto head63 = metadata + 0x33cu;
    require(m.r32(head63 + 4u) == arena + 0x0cu &&
            m.r32(head63 + 8u) == arena + 0x700cu,
            "tuple route requires the original eight-page class-63 ring");
    for (std::uint32_t p = 0; p != 8; ++p) {
        const auto node = arena + 0x0cu + p * 0x1000u;
        require(m.r32(node + 4u) == (p == 7 ? head63 : node + 0x1000u) &&
                m.r32(node + 8u) == (p == 0 ? head63 : node - 0x1000u),
                "tuple route class-63 page ring links differ from 0x373a8d");
    }
    return {record, arena, metadata};
}

std::uint32_t class_head(const Chunk& c, std::uint32_t index) {
    return c.metadata + 0x144u + index * 8u;
}
std::uint32_t class_bit(std::uint32_t index) {
    require(index < 32u, "tuple route only reaches low bitmap classes");
    return 0x80000000u >> index;
}
void require_live(X86Memory& m, const Chunk& c, std::uint32_t expected) {
    require(m.r32(class_head(c, 0)) == expected,
            "tuple route allocator live counter is at an unexpected ordinal");
}

// New class-1 selection path, followed by the original split/list operations.
// This implementation deliberately accepts only the sole request-9 suffix
// node at header arena+0xfcc and request 2 (rounded 0x10).
}

inline std::uint32_t allocate_class1_span20_split10(X86Memory& m,
                                             std::uint32_t request,
                                             std::uint32_t entry_esp,
                                             std::uint32_t expected_live) {
    const auto c = require_chunk(m);
    require(request == 2u && m.r32(entry_esp + 4u) == request,
            "only tuple allocation #4 request 2 reaches this class-1 split");
    require_live(m, c, expected_live);
    require(expected_live == 2u &&
            m.r32(c.metadata + 0x340u) == c.arena + 0x0cu &&
            m.r32(c.arena + 0x0cu) == 0xfb0u &&
            m.r32(c.arena + 0x0cu + 0xfb0u - 4u) == 0xfb0u,
            "split must follow the two-live-allocation request-9 suffix state");
    const auto head1 = class_head(c, 1u);
    const auto node = m.r32(head1 + 4u);
    constexpr std::uint32_t bit1 = 0x40000000u;
    require(node == c.arena + 0xfccu && m.r32(head1 + 8u) == node &&
            m.r32(node + 4u) == head1 && m.r32(node + 8u) == head1 &&
            m.r32(node) == 0x20u && m.r32(node + 0x1cu) == 0x20u,
            "sole class-1 request-9 suffix block must be a free span-0x20");
    require(m.r8(c.metadata + 5u) == 1u &&
            (m.r32(c.record) & bit1) != 0 &&
            (m.r32(c.metadata + 0x44u) & bit1) != 0,
            "class-1 count and region/chunk maps must advertise the suffix node");
    const auto head0 = class_head(c, 0u);
    require(m.r8(c.metadata + 4u) == 0u &&
            m.r32(head0 + 4u) == head0 && m.r32(head0 + 8u) == head0 &&
            (m.r32(c.record) & 0x80000000u) == 0 &&
            (m.r32(c.metadata + 0x44u) & 0x80000000u) == 0,
            "class zero must be empty before the class-1 split");

    // Original 0x77372c/0x7737c8: current record cursor and caller slot.
    m.w32(entry_esp + 4u, c.record);
    m.w32(0x00b10e0cu, c.record);

    // 0x77388a..0x7738ab: remove the singleton class-1 map/count entry.
    m.w32(c.metadata + 0x44u, m.r32(c.metadata + 0x44u) & ~bit1);
    m.w8(c.metadata + 5u, 0u);
    m.w32(c.record, m.r32(c.record) & ~bit1);
    // 0x7738e6..0x7738f9: unlink the selected suffix header.
    m.w32(head1 + 4u, head1);
    m.w32(head1 + 8u, head1);

    // Residual is 0x10/class 0. Reinsert the low block before the allocator
    // writes its residual tags and the high-half allocated tags.
    // 0x773902..0x773921 list splice; 0x773923..0x773956 class-0 count/maps.
    m.w32(node + 4u, m.r32(head0 + 4u));
    m.w32(node + 8u, head0);
    m.w32(head0 + 4u, node);
    m.w32(head0 + 8u, node);
    m.w8(c.metadata + 4u, 1u);
    m.w32(c.record, m.r32(c.record) | 0x80000000u);
    m.w32(c.metadata + 0x44u, m.r32(c.metadata + 0x44u) | 0x80000000u);

    // 0x77398e..0x7739a3: residual 0x10; allocate its high half.
    constexpr std::uint32_t residual = 0x10u;
    constexpr std::uint32_t allocated = 0x10u;
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated_header = node + residual;
    m.w32(allocated_header, allocated + 1u);
    m.w32(allocated_header + allocated - 4u, allocated + 1u);
    require_live(m, c, expected_live);
    m.w32(class_head(c, 0u), expected_live + 1u);
    m.w32(c.metadata, 0u);
    return allocated_header + 4u; // arena+0xfe0
}

inline std::uint32_t allocate_exact_class0_span10(X86Memory& m,
                                           std::uint32_t request,
                                           std::uint32_t entry_esp,
                                           std::uint32_t expected_user_offset,
                                           std::uint32_t expected_live) {
    const auto c = require_chunk(m);
    require(request == 2u && m.r32(entry_esp + 4u) == request &&
            (expected_user_offset == 0xff0u || expected_user_offset == 0xfe0u),
            "only tuple request-2 exact class-0 reuse is supported");
    require((expected_user_offset == 0xff0u && expected_live == 1u) ||
            (expected_user_offset == 0xfe0u && expected_live == 2u),
            "class-0 exact-fit allocation is at the wrong tuple live ordinal");
    require_live(m, c, expected_live);
    const auto head0 = class_head(c, 0u);
    const auto node = m.r32(head0 + 4u);
    constexpr std::uint32_t bit0 = 0x80000000u;
    require(node == c.arena + expected_user_offset - 4u &&
            m.r32(head0 + 8u) == node &&
            m.r32(node + 4u) == head0 && m.r32(node + 8u) == head0 &&
            m.r32(node) == 0x10u && m.r32(node + 0x0cu) == 0x10u,
            "sole class-0 node must be the current tuple suffix/name span-0x10");
    require(m.r8(c.metadata + 4u) == 1u &&
            (m.r32(c.record) & bit0) != 0 &&
            (m.r32(c.metadata + 0x44u) & bit0) != 0,
            "class-0 count and summary maps must advertise its exact-fit node");

    // 0x77372c/0x7737c8 cursor stores.
    m.w32(entry_esp + 4u, c.record);
    m.w32(0x00b10e0cu, c.record);
    // 0x77388a..0x7738ab: clear chunk bit, decrement byte count, clear region
    // bit because this exact node is the only class-0 member.
    m.w32(c.metadata + 0x44u, m.r32(c.metadata + 0x44u) & ~bit0);
    m.w8(c.metadata + 4u, 0u);
    m.w32(c.record, m.r32(c.record) & ~bit0);
    // 0x7738e6..0x7738f9 singleton unlink, then 0x773987..0x7739a3 exact fit.
    m.w32(head0 + 4u, head0);
    m.w32(head0 + 8u, head0);
    m.w32(node, 0x11u);
    m.w32(node + 0x0cu, 0x11u);
    m.w32(class_head(c, 0u), expected_live + 1u);
    m.w32(c.metadata, 0u);
    return node + 4u;
}

inline void release_isolated_span(X86Memory& m, std::uint32_t user,
                           std::uint32_t span,
                           std::uint32_t expected_user_offset,
                           std::uint32_t expected_live) {
    const auto c = require_chunk(m);
    require((span == 0x20u && expected_user_offset == 0xfd0u && expected_live == 3u) ||
            (span == 0x10u && expected_user_offset == 0xff0u && expected_live == 2u) ||
            (span == 0x10u && expected_user_offset == 0xfe0u && expected_live == 3u),
            "only the exact isolated tuple frees/live ordinals are supported");
    require(user == c.arena + expected_user_offset,
            "tuple isolated-free pointer ordinal mismatch");
    require_live(m, c, expected_live);
    const auto header = user - 4u;
    require(m.r32(header) == span + 1u &&
            (m.r32(header - 4u) & 1u) != 0 &&
            (m.r32(header + span) & 1u) != 0,
            "tuple isolated block must have allocated physical neighbors");
    const auto cls = (span >> 4u) - 1u;
    const auto head = class_head(c, cls);
    const auto bit = class_bit(cls);
    require(m.r8(c.metadata + 4u + cls) == 0u &&
            m.r32(head + 4u) == head && m.r32(head + 8u) == head &&
            (m.r32(c.record) & bit) == 0 &&
            (m.r32(c.metadata + 0x44u) & bit) == 0,
            "target tuple free-list class must be empty before isolated insertion");

    // 0x77353a..0x773558 insert the free header into an empty circular ring.
    m.w32(header + 4u, m.r32(head + 4u));
    m.w32(header + 8u, head);
    m.w32(head + 4u, header);
    m.w32(head + 8u, header);
    // 0x773560..0x773595 set member count and region/chunk summary maps.
    m.w8(c.metadata + 4u + cls, 1u);
    m.w32(c.record, m.r32(c.record) | bit);
    m.w32(c.metadata + 0x44u, m.r32(c.metadata + 0x44u) | bit);
    // 0x7735c3..0x7735ce boundary tags and live count.
    m.w32(header, span);
    m.w32(header + span - 4u, span);
    m.w32(class_head(c, 0u), expected_live - 1u);
}

inline void release_span10_between_class63_and_class0(X86Memory& m,
                                                std::uint32_t user,
                                                std::uint32_t expected_live) {
    const auto c = require_chunk(m);
    require(user == c.arena + 0xfc0u,
            "two-sided merge is only token-route scratch allocation #3");
    require_live(m, c, expected_live);
    const auto current = user - 4u;
    const auto right = current + 0x10u;
    const auto left_span = 0xfb0u;
    const auto left = current - left_span;
    require(expected_live == 3u && m.r32(current) == 0x11u &&
            m.r32(current + 0x0cu) == 0x11u &&
            m.r32(current - 4u) == left_span &&
            m.r32(left) == left_span && m.r32(left + left_span - 4u) == left_span,
            "two-sided route must have class-63 left span 0xfb0 and live current span 0x10");

    // Right-hand free span is the just-created class-0 remainder of #2.
    // 0x7733e4..0x77346b removes that right node before looking at the left.
    const auto head0 = class_head(c, 0u);
    constexpr std::uint32_t bit0 = 0x80000000u;
    require(m.r32(right) == 0x10u && m.r32(right + 0x0cu) == 0x10u &&
            m.r8(c.metadata + 4u) == 1u &&
            m.r32(head0 + 4u) == right && m.r32(head0 + 8u) == right &&
            m.r32(right + 4u) == head0 && m.r32(right + 8u) == head0 &&
            (m.r32(c.record) & bit0) != 0 &&
            (m.r32(c.metadata + 0x44u) & bit0) != 0,
            "right class-0 split remainder must be the sole linked free block");
    m.w32(c.metadata + 0x44u, m.r32(c.metadata + 0x44u) & ~bit0);
    m.w8(c.metadata + 4u, 0u);
    m.w32(c.record, m.r32(c.record) & ~bit0);
    // Original unlink writes sentinel neighbors; leave the removed node's
    // stale +4/+8 links untouched, as the machine code does.
    m.w32(head0 + 4u, head0);
    m.w32(head0 + 8u, head0);

    // 0x77346e..0x773558: merge right first (0x20 total), then the left
    // 0xfb0 class-63 extent. Previous and final classes are both 63, so no
    // class-63 ring/map operation occurs. Exact final span is 0xfd0.
    constexpr std::uint32_t merged = 0xfd0u;
    require(((merged >> 4u) - 1u) >= 63u,
            "two-sided merge must remain in class 63");
    m.w32(left, merged);
    m.w32(left + merged - 4u, merged);
    m.w32(class_head(c, 0u), expected_live - 1u);
}

inline void release_left_class63_span10(X86Memory& m, std::uint32_t user,
                                 std::uint32_t expected_left_span,
                                 std::uint32_t expected_live) {
    const auto c = require_chunk(m);
    require((user == c.arena + 0xfd0u && expected_left_span == 0xfc0u && expected_live == 3u) ||
            (user == c.arena + 0xfe0u && expected_left_span == 0xfd0u && expected_live == 2u),
            "only tuple scratch/token 0x10 left merges/live ordinals are supported");
    require_live(m, c, expected_live);
    const auto header = user - 4u;
    const auto left = header - expected_left_span;
    require(m.r32(header) == 0x11u && m.r32(header + 0x0cu) == 0x11u &&
            m.r32(header - 4u) == expected_left_span &&
            m.r32(left) == expected_left_span &&
            m.r32(left + expected_left_span - 4u) == expected_left_span &&
            (m.r32(header + 0x10u) & 1u) != 0,
            "tuple left merge requires free class-63 left and allocated right neighbors");
    const auto merged = expected_left_span + 0x10u;
    require(((merged >> 4u) - 1u) >= 63u,
            "tuple left merge must remain class 63");
    // 0x773485..0x773531 skips unlink/reinsert because both class indexes
    // are 63. 0x7735c3..0x7735ce updates only boundary tags and live count.
    m.w32(left, merged);
    m.w32(left + merged - 4u, merged);
    m.w32(class_head(c, 0u), expected_live - 1u);
}

} // namespace ra2::platform::small_crt_heap::tuple223
