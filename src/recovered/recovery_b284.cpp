#include "recovery_b284.hpp"

#include <algorithm>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace ra2::recovered::recovery_b284 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
std::uint32_t add(std::uint32_t a, std::uint32_t b) {
    require(a <= std::numeric_limits<std::uint32_t>::max() - b,
            "B284 finite route excludes 32-bit address wrap");
    return a + b;
}
std::uint16_t heap_wide(Heap& h, std::uint32_t p) {
    return static_cast<std::uint16_t>(h.r8(p) | (std::uint16_t(h.r8(add(p, 1u))) << 8));
}
void put_wide(Heap& h, std::uint32_t p, std::uint16_t value) {
    h.w8(p, static_cast<std::uint8_t>(value));
    h.w8(add(p, 1u), static_cast<std::uint8_t>(value >> 8));
}
std::uint32_t wide_length(Heap& h, std::uint32_t p, std::uint32_t limit) {
    require(p != 0, "B284 requires a nonnull owned UTF-16 string");
    for (std::uint32_t n = 0; n < limit; ++n)
        if (heap_wide(h, add(p, n * 2u)) == 0) return n;
    throw std::domain_error("B284 owned UTF-16 string lacks a bounded terminator");
}
void copy_through_nul(Heap& h, std::uint32_t dst, std::uint32_t src,
                      std::uint32_t unit_limit) {
    // Exact accepted 0x36efc9 effect: UTF-16 copy through and including NUL.
    for (std::uint32_t n = 0; n < unit_limit; ++n) {
        const auto value = heap_wide(h, add(src, n * 2u));
        put_wide(h, add(dst, n * 2u), value);
        if (value == 0) return;
    }
    throw std::domain_error("B284 NUL copy exceeded its finite output bound");
}
void append_unit(Heap& h, std::uint32_t dst, std::uint32_t dst_units, std::uint16_t value) {
    const auto length = wide_length(h, dst, dst_units);
    require(length + 1u < dst_units, "B284 insertion exceeds the bounded result");
    put_wide(h, add(dst, length * 2u), value);
    put_wide(h, add(dst, (length + 1u) * 2u), 0);
}
void append_through_nul(Heap& h, std::uint32_t dst, std::uint32_t src,
                        std::uint32_t dst_units, std::uint32_t src_units) {
    // Exact accepted 0x36ef9f effect: append a NUL-terminated UTF-16 source.
    std::uint32_t length = 0;
    while (length < dst_units && heap_wide(h, add(dst, length * 2u)) != 0) ++length;
    require(length < dst_units, "B284 append destination lacks a bounded NUL");
    for (std::uint32_t n = 0; n < src_units; ++n) {
        const auto value = heap_wide(h, add(src, n * 2u));
        put_wide(h, add(dst, (length + n) * 2u), value);
        if (value == 0) return;
    }
    throw std::domain_error("B284 append source exceeded its finite NUL bound");
}
}

std::uint32_t rva_0035bf20(Memory& m, const Inputs& i, Heap& h) {
    const auto object = i.cx;
    require(object != 0 && (i.arithmetic_flags & 0x400u) == 0,
            "B284 route requires an object cell and direction flag clear");
    const auto old = m.r32(object);
    require(old != 0, "B284 selects the original nonnull-current branch");
    const auto length = wide_length(h, old, 4097u);
    require(length >= 1017u && length <= 1032u,
            "B284 finite route requires a 1017..1032-unit owned source");
    const auto position = (std::min)(i.arg[1], length);
    const auto inserted = static_cast<std::uint16_t>(i.arg[0]);
    require(inserted != 0, "B284 route excludes an inserted UTF-16 NUL");
    const auto bytes = add(length * 2u, 4u);
    require(bytes > 1016u, "B284 result must use the accepted ordinary-heap route");

    auto result = h.allocate(bytes);
    require(result != 0 && result != old,
            "B284 success-only route requires a distinct result allocation");

    // The original truncates old at position while copying the prefix, then
    // restores the saved source unit. These are its exact inline REP/copy effects.
    const auto split = add(old, position * 2u);
    const auto saved = heap_wide(h, split);
    put_wide(h, split, 0);
    copy_through_nul(h, result, old, length + 1u);
    put_wide(h, split, saved);

    // Inline the accepted 0x36ef9f effect for the original stack-local one-unit string.
    append_unit(h, result, length + 2u, inserted);
    append_through_nul(h, result, split, length + 2u, length - position + 1u);

    const auto free_result = h.release(old);
    require(free_result != 0u,
            "B284 success-only route requires successful original HeapFree");
    m.w32(object, result); // native publishes after freeing the old allocation
    return (free_result & 0xffffff00u) | 1u; // final MOV AL,1 in the original
}
}






