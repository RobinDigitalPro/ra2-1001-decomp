#include "recovery_b208.hpp"

#include "recovered/preallocated_b66.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b208 {
namespace {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

void require(bool okay, const char* message) {
    if (!okay) throw std::domain_error(message);
}

enum class Source : std::uint8_t {
    Immediate,
    OuterDword,
    OuterWord,
    OuterAddress,
    Zero,
    CacheResult,
};
struct ValueSpec {
    Source source;
    std::uint32_t value;
};
struct StoreSpec {
    std::uint8_t offset;
    std::uint8_t width;
    ValueSpec value;
};
struct ChildSpec {
    std::uint8_t request;
    std::uint16_t outer_offset;
    std::array<StoreSpec, 5> stores;
};

// Store offsets, widths, source operands, allocator requests, and publication
// offsets were decoded from the 89 call sites in VA 0x483d44..0x4850c8.
// See selector2_inventory.json and recovery_b208_specs.inc for per-VA evidence.
constexpr ChildSpec children[] = {
#include "recovery_b208_specs.inc"
};

std::uint8_t shift_low8(std::uint16_t word, std::uint32_t right,
                        std::uint32_t left) {
    const auto ax = static_cast<std::uint16_t>(word >> (right & 31u));
    const auto al = static_cast<std::uint8_t>(ax);
    return static_cast<std::uint8_t>(static_cast<std::uint32_t>(al) << (left & 31u));
}

void transform_palette(Memory& m, const Inputs& i, std::uint32_t palette) {
    for (unsigned n = 0; n != 256; ++n) {
        const auto word = m.r16(palette + n * 2u);

        // Original VA 0x485e33..0x485e8b: AX takes EDX>> then the saved
        // entry ECX from [entry ESP-8]<<;
        // DL takes arg1>> then arg0<<; BL takes arg3>> then arg2<<.
        // Keep these register lanes distinct; the PE globals apply in the
        // corresponding instruction order shown below.
        auto al = shift_low8(word, i.dx, i.cx);
        auto dl = shift_low8(word, i.arg[1], i.arg[0]);
        auto bl = shift_low8(word, i.arg[3], i.arg[2]);

        al = static_cast<std::uint8_t>(al >> (m.r8(0x0083b2ecu) & 31u));
        const auto eax_lane = static_cast<std::uint32_t>(al) <<
                              (m.r32(0x0083b2e8u) & 31u);
        bl = static_cast<std::uint8_t>(bl >> (m.r8(0x0083b2f4u) & 31u));
        const auto ebx_lane = static_cast<std::uint32_t>(bl) <<
                              (m.r32(0x0083b2f0u) & 31u);
        dl = static_cast<std::uint8_t>(dl >> (m.r8(0x0083b2fcu) & 31u));
        const auto edx_lane = static_cast<std::uint32_t>(dl) <<
                              (m.r32(0x0083b2f8u) & 31u);

        m.w16(palette + n * 2u,
              static_cast<std::uint16_t>(eax_lane | ebx_lane | edx_lane));
    }
}

void clear_original_null_children(Memory& m, std::uint32_t outer) {
    // Exact useful path through 0x85180: all 89 pointers are null, so each
    // null test skips the indirect destructor and the original slot clear
    // writes the same zero back. No callback or release is fabricated.
    for (std::uint32_t offset = 8; offset <= 0x168; offset += 4u) {
        require(m.r32(outer + offset) == 0,
                "Block208 requires null old-child slots for 0x85180");
        m.w32(outer + offset, 0);
    }
}

std::uint32_t source_value(Memory& m, const Inputs& i, std::uint32_t outer,
                           const StoreSpec& store, bool& cache_called) {
    switch (store.value.source) {
    case Source::Immediate:
        return store.value.value;
    case Source::OuterDword:
        return m.r32(outer + store.value.value);
    case Source::OuterWord:
        return m.r16(outer + store.value.value);
    case Source::OuterAddress:
        return outer + store.value.value;
    case Source::Zero:
        return 0;
    case Source::CacheResult: {
        require(!cache_called, "one cache call is expected per child");
        Inputs args = i;
        args.cx = 0x008198f8u;
        args.arg[0] = m.r32(outer + 0x16cu);
        cache_called = true;
        const auto result = global_b26::fun_0041e3e0(m, args);
        require(result != 0, "Block208 cache-hit result must be an actual entry");
        return result;
    }
    }
    throw std::domain_error("unknown Block208 store source");
}

void write_heap_word(Heap& heap, std::uint32_t address, std::uint16_t value) {
    // The source instruction is a 16-bit MOV. The bridge exposes byte writes
    // for owned CRT spans, so preserve the same little-endian two-byte result.
    heap.w8(address, static_cast<std::uint8_t>(value));
    heap.w8(address + 1u, static_cast<std::uint8_t>(value >> 8u));
}

std::uint32_t initialize_selector_two(Memory& m, const Inputs& i,
                                     std::uint32_t outer, Heap& heap) {
    require(m.r32(outer + 4u) == 2u,
            "Block208 only implements the original selector-two arm");
    unsigned cache_calls = 0;
    for (const auto& child : children) {
        const auto address = heap.allocate(child.request);
        require(address != 0, "Block208 excludes original allocation failure");
        bool cache_called = false;
        for (const auto& store : child.stores) {
            if (store.width == 0) continue;
            const auto value = source_value(m, i, outer, store, cache_called);
            const auto target = address + store.offset;
            if (store.width == 4) {
                heap.w32(target, value);
            } else if (store.width == 2) {
                write_heap_word(heap, target, static_cast<std::uint16_t>(value));
            } else {
                throw std::domain_error("unexpected Block208 constructor store width");
            }
        }
        cache_calls += cache_called ? 1u : 0u;
        m.w32(outer + child.outer_offset, address);
    }
    require(cache_calls == 39u,
            "Block208 selector-two branch must reach exactly 39 real cache hits");
    return cache_calls;
}
} // namespace

std::uint32_t fun_00485df0(Memory& m, const Inputs& i, Heap& heap) {
    require(m.r32(0x00839490u) == 1u,
            "Block208 finite contract is one original palette record");
    const auto table = m.r32(0x00839484u);
    require(table != 0, "Block208 requires the original nonnull record table");
    const auto outer = m.r32(table);
    require(outer != 0 && m.r32(outer + 4u) == 2u,
            "Block208 requires [outer+4] == 2");
    const auto palette = m.r32(outer + 0x170u);
    require(palette != 0, "Block208 palette pointer must be valid");
    require(m.r32(0x00824930u) == 1u,
            "Block208 cache fixture uses one original entry");
    const auto cache_table = m.r32(0x00824924u);
    require(cache_table != 0 && m.r32(cache_table) != 0,
            "Block208 cache table/entry must be valid");
    require(m.r32(m.r32(cache_table) + 0x20000u) ==
                m.r32(outer + 0x16cu),
            "Block208 requires the actual cache-hit key");

    transform_palette(m, i, palette);
    // 0x485eb0..0x485ec7 zero-extend the two original global WORD reads.
    m.w32(outer + 0x180u, m.r16(0x0083b300u));
    m.w32(outer + 0x184u, m.r16(0x0083b302u));
    clear_original_null_children(m, outer);
    const auto cache_calls = initialize_selector_two(m, i, outer, heap);
    require(cache_calls == 39u, "Block208 cache-call count mismatch");
    return 1u;
}
} // namespace ra2::recovered::recovery_b208
