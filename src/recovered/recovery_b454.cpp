#include "recovered/recovery_b454.hpp"
#include "recovered/construct_b101.hpp"
#include "recovered/heap_b29_memory.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::heap_b29 { void fun_00533530(Memory&, State&, const Operations&); }

namespace ra2::recovered::geometry_b454 {
namespace {
constexpr std::uint32_t arena_tmp = 0x00a55800u;
constexpr std::uint32_t cell_map_field = 0x138u;
constexpr std::uint32_t global_map_fallback = 0x00a57610u;

void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

struct AllocCtx { ra2::platform::ordinary_heap::Heap* heap; };
ra2::recovered::heap_b29::BoundaryResult invoke_heap(
        ra2::recovered::heap_b29::Memory&, std::uint32_t kind,
        std::uint32_t argument, std::uint32_t flag, void* context) {
    auto& heap = *static_cast<AllocCtx*>(context)->heap;
    if (kind == 1u) {
        need(flag == 1u && argument == 8257u,
             "B454 exact 0x133530 ordinary allocation is 65+8192 bytes");
        return {heap.allocate(argument), 0u};
    }
    need(kind == 0u && argument != 0u,
         "B454 only frees the one nonnull temporary buffer");
    return {heap.release(argument), 0u};
}

std::uint32_t make_temporary(Memory& m, ra2::platform::ordinary_heap::Heap& heap) {
    std::array<std::uint8_t, 0x40> before{};
    for (std::uint32_t n = 0; n < before.size(); ++n)
        before[n] = static_cast<std::uint8_t>(m.r8(arena_tmp + n));

    ra2::recovered::heap_b29::State s{};
    s.cx = arena_tmp;
    s.arg[0] = 1u;
    s.arg[1] = 0x2000u;
    AllocCtx ctx{&heap};
    const ra2::recovered::heap_b29::Operations op{invoke_heap, &ctx};
    ra2::recovered::heap_b29::fun_00533530(m, s, op);

    // Root calls 0x6906f0 with null source, so local +4 remains zero. In the
    // reached 0x1335e0 branch, 0x690740 loads that zero and returns zero;
    // the caller compares it with four and exits before any refill/data call.
    need(m.r32(arena_tmp + 4u) == 0u && m.r32(arena_tmp + 0x10u) == 0u &&
         m.r32(arena_tmp + 0x14u) != 0u,
         "B454 only models the observed null-owner, zero-available helper prefix");
    const auto allocated = m.r32(arena_tmp + 0x14u);
    for (std::uint32_t n = 0; n < before.size(); ++n)
        m.w8(arena_tmp + n, before[n]);
    return allocated;
}

void release_temporary(Memory& m, std::uint32_t buffer,
                       ra2::platform::ordinary_heap::Heap& heap) {
    need(buffer != 0u, "B454 excludes allocation failure");
    const auto result = heap.release(buffer);
    need(result != 0u, "B454 real HeapFree must succeed for temporary buffer");
    (void)m;
}

std::uint32_t cell_at(Memory& m, std::uint32_t receiver,
                      std::int32_t x, std::int32_t y) {
    const auto index = static_cast<std::uint32_t>(y) * 512u + static_cast<std::uint32_t>(x);
    if (x < 0 || y < 0 || index >= 0x40000u) return 0u;
    const auto table = m.r32(receiver + cell_map_field);
    need(table != 0u, "B454 requires an initialized 0x40000-entry cell table");
    return m.r32(table + index * 4u);
}

void apply_one(Memory& m, std::uint32_t receiver, std::int32_t x,
               std::int32_t y, std::uint32_t field, bool convert) {
    auto target = cell_at(m, receiver, x, y);
    if (!target) target = global_map_fallback;
    m.w32(target + field, 0xffffu);
    if (convert) {
        // Exact reached 0x1335e0 short-read leaves the preinitialized FFFF
        // value in place; accepted 0x5277b0 returns FFFF without table reads.
        const auto converted = 0xffffu;
        need(converted == m.r32(target + field),
             "B454 sentinel short-read prefix unexpectedly wrote data");
        m.w32(target + field, converted);
    }
}

void reset_fallback(Memory& m) {
    ra2::recovered::global_b26::Inputs reset{};
    reset.cx = global_map_fallback;
    (void)ra2::recovered::construct_b101::fun_00470b10(m, reset);
}
}

const Entry& entry_14b150() { static const Entry e{0x14b150u, 470u, 4u, 0xffffffffu}; return e; }
const Entry& entry_14b330() { static const Entry e{0x14b330u, 276u, 4u, 0xffffffffu}; return e; }

std::uint32_t fun_0054b150(Memory& m, Inputs& i,
                           ra2::platform::ordinary_heap::Heap& heap) {
    const auto receiver = i.cx;
    need(receiver != 0u && i.arg[0] == 0u,
         "B454 selects the null-source 0x6906f0 no-dispatch path");
    const auto buffer = make_temporary(m, heap);
    const auto table = m.r32(receiver + cell_map_field);
    need(table != 0u, "B454 requires an initialized 0x40000-entry cell table");
    std::uint32_t nonnull_cells = 0;
    for (std::int32_t n = 0; n < 0x4000; ++n) {
        const auto x = n & 0x7f;
        const auto y = n >> 7;
        const auto index = static_cast<std::uint32_t>(y * 512 + x);
        const auto cell = m.r32(table + index * 4u);
        if (cell) ++nonnull_cells;
        const auto target = cell ? cell : global_map_fallback;
        apply_one(m, receiver, x, y, 0x38u, true);
        need(target != 0u, "B454 fallback pointer is nonzero");
    }
    need(nonnull_cells > 0u, "B454 sweep must reach at least one initialized live map cell");
    // The remaining two sweeps call 0x1335e0 for one byte; its same proven
    // early-return prefix writes nothing. Null cells only select this global
    // fallback, which the actual final 0x70b10 call resets in full.
    reset_fallback(m);
    release_temporary(m, buffer, heap);
    // The original uses its first caller word as the stack coordinate pair;
    // the final sweep iteration leaves x=127 and y=127 there.
    i.arg[0] = 0x007f007fu;
    return 1u;
}

std::uint32_t fun_0054b330(Memory& m, Inputs& i,
                           ra2::platform::ordinary_heap::Heap& heap) {
    const auto receiver = i.cx;
    need(receiver != 0u && i.arg[0] == 0u,
         "B454 selects the null-source 0x6906f0 no-dispatch path");
    const auto buffer = make_temporary(m, heap);
    const auto gx = static_cast<std::int16_t>(m.r16(0x00a56e5cu));
    const auto gy = static_cast<std::int16_t>(m.r16(0x00a56e5eu));
    const auto x = static_cast<std::int16_t>(i.stack_minus8 & 0xffffu);
    const auto y = static_cast<std::int16_t>(i.stack_minus8 >> 16u);
    if (x != gx || y != gy) {
        auto target = cell_at(m, receiver, x, y);
        if (!target) {
            m.w32(0x00a57634u, static_cast<std::uint16_t>(x));
            target = global_map_fallback;
        }
        if (target != global_map_fallback) {
            apply_one(m, receiver, x, y, 0x38u, true);
            // Both one-byte 0x1335e0 calls are exact short reads; no payload
            // is decoded or copied to +0x11a/+0x11b.
        }
        // The common six-byte local read also short-returns. Root then stores
        // its global coordinate pair into the local output before the second
        // comparison, which exits on the next iteration.
    }
    reset_fallback(m);
    release_temporary(m, buffer, heap);
    return 1u;
}
}
