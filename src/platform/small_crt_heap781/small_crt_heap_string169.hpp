#pragma once
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"
// Finite inline branches keep existing Heap users link-complete.

#include <stdexcept>

namespace ra2::platform::small_crt_heap781::string169 {
namespace {
using platform::small_crt_heap781::X86Memory;

[[noreturn]] void unsupported(const char* why) {
    throw std::domain_error(why);
}
void require(bool ok, const char* why) {
    if (!ok) unsupported(why);
}

struct CurrentChunk {
    std::uint32_t record;
    std::uint32_t arena;
    std::uint32_t metadata;
};

void require_initial_class63_ring(X86Memory& m, std::uint32_t arena,
                                  std::uint32_t metadata) {
    const auto head = metadata + 0x33cu;
    // This byte counts usable chunks, not the eight linked extents. The
    // initializer increments it once after the eight-page loop.
    require(m.r8(metadata + 0x43u) == 1u &&
            m.r32(metadata + 0xc4u) == 1u &&
            m.r32(head + 4u) == arena + 0x0cu &&
            m.r32(head + 8u) == arena + 0x700cu,
            "expected eight registered class-63 page extents");
    for (std::uint32_t page = 0; page != 8u; ++page) {
        const auto node = arena + 0x0cu + page * 0x1000u;
        const auto expected_next = page == 7u ? head : node + 0x1000u;
        const auto expected_previous = page == 0u ? head : node - 0x1000u;
        require(m.r32(node + 4u) == expected_next &&
                m.r32(node + 8u) == expected_previous,
                "class-63 extent ring link differs from 0x373a8d layout");
    }
}

CurrentChunk require_current_chunk_zero(X86Memory& m) {
    const auto record = m.r32(0x00b10e0cu);
    require(record != 0 && m.r32(0x00b10e14u) == 1u,
            "326a20 extension requires the current single registered region");
    require(m.r32(0x00b10e18u) == record &&
            m.r32(record + 4u) == 1u &&
            m.r32(record + 8u) == 0x7fffffffu,
            "326a20 extension requires current region with chunk zero consumed");
    const auto arena = m.r32(record + 0x0cu);
    const auto metadata = m.r32(record + 0x10u);
    require(arena != 0 && metadata != 0 && m.r32(metadata) == 0u,
            "326a20 extension requires live arena and chunk-zero metadata");
    // 0x373a8d links all eight page extents into this ring. Allocation from
    // page zero changes its boundary tags but does not unlink the node.
    require_initial_class63_ring(m, arena, metadata);
    return {record, arena, metadata};
}

std::uint32_t class_for_span(std::uint32_t span) {
    require(span >= 0x10u && (span & 0x0fu) == 0,
            "invalid CRT span");
    const auto raw = (span >> 4u) - 1u;
    return raw < 63u ? raw : 63u;
}
} // namespace

inline std::uint32_t allocate_class63_request13_for_concat(X86Memory& m,
                                                   std::uint32_t entry_esp) {
    // 0x773723..0x773875 searches for class >= 1. For this exact route every
    // low class is empty; the first extent in the eight-node class-63 ring
    // is the selected page-zero node. Request 13 rounds to 0x20 by 0x7736f3; splitting leaves 0xf80,
    // still class 63, so 0x773877 jumps directly to the same-class path.
    const auto c = require_current_chunk_zero(m);
    constexpr std::uint32_t request = 13u;
    constexpr std::uint32_t rounded = 0x20u;
    constexpr std::uint32_t cls = 63u;
    require(((request + 0x17u) & 0xfffffff0u) == rounded &&
            m.r32(entry_esp + 4u) == request,
            "request 13 no longer matches the pinned CRT round-up");
    require(m.r32(c.record) == 0u && m.r32(c.metadata + 0x44u) == 0u &&
            m.r32(c.metadata + 0xc4u) == 1u,
            "request-13 concat allocation requires empty lower classes and class-63 availability");
    const auto heads = c.metadata + 0x144u;
    const auto head = heads + cls * 8u;
    const auto node = m.r32(head + 4u);
    require(node == c.arena + 0x0cu &&
            m.r32(head + 4u) == node &&
            m.r32(head + 8u) == c.arena + 0x700cu &&
            m.r32(node + 4u) == c.arena + 0x100cu &&
            m.r32(node + 8u) == head,
            "class-63 ring must retain all eight page extents");
    require(m.r32(node) == 0xfa0u && m.r32(node + 0xfa0u - 4u) == 0xfa0u,
            "concat allocation requires the exact post-A/B residual span");
    require(m.r32(heads) == 3u,
            "concat allocation requires three prior live blocks F/A/B");

    // The existing region has its class-63 bit set, so the original writes
    // the current cursor through [EBP+8] at 0x77372c, then branches directly
    // to 0x7737c8. Later table/chunk search stores are not reached.
    m.w32(entry_esp + 4u, c.record);

    const auto residual = m.r32(node) - rounded; // 0xf80
    require(class_for_span(residual) == cls,
            "request-13 residual must stay in class 63");

    // 0x77398e..0x7739a3, taken for nonzero same-class residual: preserve the
    // original node/list links, write its new tags, then allocate from its
    // high edge. The sequence is the original store order.
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated_header = node + residual;
    const auto allocated_tag = rounded + 1u;
    m.w32(allocated_header, allocated_tag);
    m.w32(allocated_header + rounded - 4u, allocated_tag);

    // 0x7739a7..0x7739d4 increments the live counter and writes chunk index 0.
    m.w32(heads, 4u);
    m.w32(c.metadata, 0u);
    return allocated_header + 4u;
}

inline std::uint32_t allocate_exact_class1_20(X86Memory& m,
                                       std::uint32_t entry_esp) {
    // 0x773723..0x773875 has already selected the first fitting free class.
    // In the route's state the class-1 bit is set and class-1 contains exactly
    // the one span-0x20 node. 0x773861..0x773877 computes zero residual, so
    // 0x77387d..0x773921 unlinks without leaving a split remainder.
    const auto c = require_current_chunk_zero(m);
    constexpr std::uint32_t cls = 1u;
    constexpr std::uint32_t span = 0x20u;
    constexpr std::uint32_t bit = 0x40000000u;
    const auto head = c.metadata + 0x144u + cls * 8u;
    const auto header = m.r32(head + 4u);
    require(header != head && m.r32(head + 8u) == header,
            "class-1 node is not the sole linked free extent");
    require(m.r32(header + 4u) == head && m.r32(header + 8u) == head,
            "class-1 free node does not form the expected one-node ring");
    require(m.r32(header) == span && m.r32(header + span - 4u) == span,
            "class-1 free node must be an exact span-0x20 fit");
    require((header + 4u == c.arena + 0xfb0u) ||
            (header + 4u == c.arena + 0xfd0u),
            "only the route's reused B/A pointer identities are supported");
    require(m.r32(entry_esp + 4u) == 13u,
            "class-1 exact reuse is only used for request 13 in this route");
    require(class_for_span(span) == cls && m.r8(c.metadata + 4u + cls) == 1u,
            "class-1 count does not describe exactly one reusable block");
    require((m.r32(c.record) & bit) != 0 &&
            (m.r32(c.metadata + 0x44u) & bit) != 0,
            "class-1 summaries do not advertise the reusable node");
    require_initial_class63_ring(m, c.arena, c.metadata);

    // The existing region has the class-1 bit set, so the original writes
    // the current cursor through [EBP+8] at 0x77372c, then branches directly
    // to 0x7737c8 before selecting this free list.
    m.w32(entry_esp + 4u, c.record);

    // 0x77388a..0x7738ab: because this is the sole class-1 node, clear the
    // chunk map bit, decrement count, then clear the region map bit.
    m.w32(c.metadata + 0x44u, m.r32(c.metadata + 0x44u) & ~bit);
    m.w8(c.metadata + 4u + cls,
         static_cast<std::uint8_t>(m.r8(c.metadata + 4u + cls) - 1u));
    m.w32(c.record, m.r32(c.record) & ~bit);

    // 0x7738e6..0x7738f9 unlink the node by reconnecting its sentinel.
    const auto next = m.r32(header + 4u);
    const auto previous = m.r32(header + 8u);
    m.w32(previous + 4u, next);
    m.w32(next + 8u, previous);

    // 0x773987..0x7739a3: zero residual skips a second list insertion; write
    // the allocated header/footer in the same order as the original.
    const auto allocated_tag = span + 1u;
    m.w32(header, allocated_tag);
    m.w32(header + span - 4u, allocated_tag);

    // 0x7739a7..0x7739d4: increment chunk live count and retain chunk index 0.
    const auto live = m.r32(c.metadata + 0x144u);
    const auto expected_live = header + 4u == c.arena + 0xfb0u ? 3u : 2u;
    require(live == expected_live,
            "class-1 pointer identity does not match its D/E allocation ordinal");
    m.w32(c.metadata + 0x144u, live + 1u);
    m.w32(c.metadata, 0u);
    return header + 4u;
}

inline void release_empty_class0_or_class1(X86Memory& m,
                                    std::uint32_t user,
                                    std::uint32_t expected_span) {
    const auto c = require_current_chunk_zero(m);
    require(expected_span == 0x10u || expected_span == 0x20u,
            "only the route's class-0 and class-1 inserts are implemented");
    const auto cls = class_for_span(expected_span);
    require(cls <= 1u && class_for_span(expected_span) == cls,
            "unexpected free-list class");
    require(user >= c.arena + 4u &&
            user + expected_span - 4u < c.arena + 0x8000u,
            "pointer is outside the committed chunk-zero address range");
    require((expected_span == 0x20u &&
             (user == c.arena + 0xfb0u || user == c.arena + 0xfd0u)) ||
            (expected_span == 0x10u && user == c.arena + 0xff0u),
            "only the route's B/A/F freed pointer identities are supported");
    const auto header = user - 4u;
    require(m.r32(header) == expected_span + 1u,
            "pointer does not have the expected allocated boundary tag");

    // 0x7733e4..0x773408: low-bit-set left footer and right tag bypass both
    // coalescing branches. This admits only the actual B, A, and F geometries.
    const auto left_footer = m.r32(header - 4u);
    const auto right_tag = m.r32(header + expected_span);
    require((left_footer & 1u) != 0 && (right_tag & 1u) != 0,
            "free geometry is not no-neighbor on both sides");
    const auto bit = 0x80000000u >> cls;
    const auto head = c.metadata + 0x144u + cls * 8u;
    require(m.r32(head + 4u) == head && m.r32(head + 8u) == head,
            "route expects the target class list to be empty before insertion");
    require(m.r8(c.metadata + 4u + cls) == 0u &&
            (m.r32(c.record) & bit) == 0u &&
            (m.r32(c.metadata + 0x44u) & bit) == 0u,
            "route expects target class count and summaries to be empty");
    const auto live = m.r32(c.metadata + 0x144u);
    const auto expected_live = user == c.arena + 0xfb0u ? 4u :
                               user == c.arena + 0xfd0u ? 3u : 2u;
    require(live == expected_live,
            "class-0/1 pointer identity does not match B/A/F release order");

    // 0x77353a..0x773558 inserts the block header into the circular list.
    // (The head's +0 dword also stores live allocation count for class 0.)
    const auto next = m.r32(head + 4u);
    m.w32(header + 4u, next);
    m.w32(header + 8u, head);
    m.w32(head + 4u, header);
    m.w32(next + 8u, header);

    // 0x773560..0x773595: first member sets region and chunk class maps;
    // classes 0/1 use the low bitmap words at record+0 and metadata+0x44.
    m.w8(c.metadata + 4u + cls, 1u);
    m.w32(c.record, m.r32(c.record) | bit);
    m.w32(c.metadata + 0x44u, m.r32(c.metadata + 0x44u) | bit);

    // 0x7735c3..0x7735ce writes free boundary tags and decrements live count.
    m.w32(header, expected_span);
    m.w32(header + expected_span - 4u, expected_span);
    m.w32(c.metadata + 0x144u, live - 1u);
}

inline void release_left_class63_same_class(X86Memory& m,
                                     std::uint32_t user,
                                     std::uint32_t expected_left_span) {
    const auto c = require_current_chunk_zero(m);
    require(user >= c.arena + 0x10u && user < c.arena + 0x8000u,
            "freed pointer is outside committed chunk zero");
    const auto header = user - 4u;
    require(m.r32(header) == 0x21u && expected_left_span >= 0x10u &&
            (expected_left_span & 0x0fu) == 0,
            "route requires the allocated class-1 span-0x20 block");
    require((user == c.arena + 0xf90u && expected_left_span == 0xf80u) ||
            (user == c.arena + 0xfb0u && expected_left_span == 0xfa0u),
            "only the route's C/D left-merge geometries are supported");
    const auto previous_footer = m.r32(header - 4u);
    require(previous_footer == expected_left_span && (previous_footer & 1u) == 0,
            "left class-63 footer does not match the actual route geometry");
    const auto left_header = header - expected_left_span;
    require(m.r32(left_header) == expected_left_span &&
            class_for_span(expected_left_span) == 63u,
            "left neighbor must be a class-63 extent with matching header");
    const auto merged_span = expected_left_span + 0x20u;
    require(class_for_span(merged_span) == 63u,
            "merged span would leave the same-class-63 original branch");
    const auto right_tag = m.r32(header + 0x20u);
    require((right_tag & 1u) != 0,
            "right neighbor is free; right-neighbor coalescing is excluded");
    const auto live = m.r32(c.metadata + 0x144u);
    const auto expected_live = user == c.arena + 0xf90u ? 4u : 3u;
    require(live == expected_live,
            "C/D pointer identity does not match the left-merge release order");

    // 0x773485..0x7734bb detects the left free node; previous and merged
    // class are both 63, so 0x7734b9 jumps past unlinking. The current class
    // differs, but 0x773531 compares previous class to merged class and skips
    // insertion too. Therefore no list/count/bitmap word changes here.
    // 0x7735c3..0x7735ce only replaces merged boundary tags and live count.
    m.w32(left_header, merged_span);
    m.w32(left_header + merged_span - 4u, merged_span);
    m.w32(c.metadata + 0x144u, live - 1u);
}

} // namespace ra2::platform::small_crt_heap781::string169
