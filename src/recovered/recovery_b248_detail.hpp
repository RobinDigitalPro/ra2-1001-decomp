#pragma once

#include "recovery_b248_cache.hpp"
#include "recovery_b248_descriptors.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/leaf_b57_b.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovery_b248_detail {
inline std::uint32_t nearest_palette_entry(ra2::recovered::leaf::Memory& m,
                                           std::uint32_t palette,
                                           std::uint32_t target) {
    std::uint32_t best = 0xffffffffu, index = 0;
    for (std::uint32_t n = 0; n < 256; ++n) {
        ra2::recovered::leaf::Inputs in{};
        in.cx = target;
        in.arg[0] = palette + n * 3u;
        const auto distance = ra2::recovered::leaf::fun_006343a0(m, in);
        if (n == 0 || static_cast<std::int32_t>(distance) <
                      static_cast<std::int32_t>(best)) {
            best = distance;
            index = n;
        }
    }
    return index;
}

template<class HeapLike>
inline void initialize_format_one(Memory& m, HeapLike& heap,
                                  std::uint32_t object,
                                  std::uint32_t palette,
                                  std::uint32_t surface) {
    heap.w32(object + 4u, m.r32(surface + 0x10u));
    for (std::uint32_t off = 8; off <= 0x168; off += 4)
        heap.w32(object + off, 0);
    heap.w32(object + 0x16cu, 1u);
    heap.w32(object, 0x00788f70u);
    if (heap.r32(object + 4u) != 1u)
        throw std::domain_error("248 selected surface does not choose format one");

    const auto first = heap.allocate(0x100u);
    heap.w32(object + 0x178u, first);
    heap.w8(first, 0);

    // These are stack-local helper buffers in the original wrapper. A private
    // scratch leaf span preserves that lifetime without placing temporaries
    // in the persistent CRT heap. Palette bytes are read through Heap because
    // the shared bridge need not add the arena to global Memory's span list.
    constexpr std::uint32_t scratch_base = 0x7e700000u;
    constexpr std::uint32_t scratch_size = 0x2000u;
    constexpr std::uint32_t hsv = scratch_base + 0x1000u;
    constexpr std::uint32_t converted = scratch_base + 0x1010u;
    std::array<std::uint8_t, scratch_size> scratch{};
    for (std::uint32_t k = 0; k < 0x300u; ++k)
        scratch[k] = heap.r8(palette + k);
    ra2::recovered::leaf::Memory palette_view(scratch.data(), scratch_base,
                                               scratch_size);
    for (std::uint32_t n = 1; n < 256; ++n) {
        ra2::recovered::leaf::Inputs to_hsv{};
        to_hsv.cx = scratch_base + n * 3u;
        to_hsv.arg[0] = hsv;
        (void)ra2::recovered::leaf::fun_006343f0(palette_view, to_hsv);
        palette_view.w8(hsv + 2u, palette_view.r8(hsv + 2u) >> 1u);
        ra2::recovered::leaf::Inputs to_rgb{};
        to_rgb.cx = hsv;
        to_rgb.arg[0] = converted;
        (void)ra2::recovered::leaf::fun_004fe550(palette_view, to_rgb);
        heap.w8(first + n, static_cast<std::uint8_t>(
            nearest_palette_entry(palette_view, scratch_base, converted)));
    }

    const auto second = heap.allocate(0x100u);
    heap.w32(object + 0x170u, second);
    const auto shifted = (heap.r32(object + 0x16cu) - 1u) >> 1u;
    heap.w32(object + 0x174u, second + (shifted << 8u));
    heap.w8(second, 0);
    for (std::uint32_t n = 1; n < 256; ++n)
        heap.w8(second + n, static_cast<std::uint8_t>(nearest_palette_entry(
            palette_view, scratch_base, scratch_base + n * 3u)));

    heap.w32(object + 0x180u, static_cast<std::uint32_t>(m.r16(0x83b300u)));
    heap.w32(object + 0x184u, static_cast<std::uint32_t>(m.r16(0x83b302u)));
    initialize_selector_one(heap, object);
}

// Recovered positive cache-hit/selector-one route for RVA 0x2e7c30. Heap
// writes remain in Heap's full committed arena; Memory carries globals and
// the authentic surface input. No arena-span patch to Memory is required.
template<class HeapLike>
inline std::uint32_t fun_002e7c30(Memory& m, const Inputs& in,
                                  HeapLike& heap) {
    (void)in;
    if (m.r32(0x83a710u) == 0x280u)
        throw std::domain_error("248 excludes the 0x280 alternate name branch");
    constexpr std::array<std::uint32_t, 4> name_cells{{
        0x7e1ff8u, 0x7e2000u, 0x7e2008u, 0x7e2010u}};
    constexpr std::array<std::uint32_t, 4> output_cells{{
        0xaa8bb4u, 0xaa8b28u, 0xaa8ba0u, 0xaa8b44u}};
    constexpr std::array<std::uint32_t, 4> flag_cells{{
        0xaa8cb8u, 0xaa8cb9u, 0xaa8cbau, 0xaa8cbbu}};
    for (unsigned n = 0; n < name_cells.size(); ++n) {
        const auto p = cache_hit(m, Inputs{}, m.r32(name_cells[n]),
                                 output_cells[n], flag_cells[n]);
        m.w32(output_cells[n], p);
    }
    const auto palette = cache_hit(m, Inputs{}, m.r32(0x7e1f7cu),
                                   0xaa8c08u, 0xaa8cb8u);
    const auto converted = heap.allocate(0x300u);
    m.w32(0xaa8c08u, converted);
    convert_palette_6bit(m, heap, palette, converted);
    const auto object = heap.allocate(0x188u);
    const auto surface = m.r32(0x821c98u);
    if (!surface) throw std::domain_error("248 requires the bounded surface input");
    initialize_format_one(m, heap, object, converted, surface);
    // 0x483873..0x4838C3 reaches the direct append arm when count < capacity.
    // The private fixture supplies count 0/capacity 4, so no growth callback
    // or arbitrary virtual result is involved.
    const auto capacity=m.r32(0x00839488u),count=m.r32(0x00839490u);
    if(count>=capacity) throw std::domain_error("Block248 requires spare original registry capacity");
    const auto registry=m.r32(0x00839484u);
    m.w32(0x00839490u,count+1u);
    m.w32(registry+count*4u,object);
    m.w32(0xaa8c0cu, object);
    return object;
}
} // namespace ra2::recovery_b248_detail
