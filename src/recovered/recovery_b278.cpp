#include "recovery_b278.hpp"

#include <cstdint>
#include <limits>
#include <stdexcept>

namespace ra2::recovered::recovery_b278 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
std::uint32_t checked_add(std::uint32_t a, std::uint32_t b) {
    require(a <= std::numeric_limits<std::uint32_t>::max() - b,
            "B278 finite route excludes 32-bit address wrap");
    return a + b;
}
std::uint32_t guest_wide_length(Memory& m, std::uint32_t p) {
    require(p != 0, "B278 requires a nonnull UTF-16 source");
    for (std::uint32_t n = 0; n < 4096; ++n) {
        if (m.r16(checked_add(p, n * 2u)) == 0) return n;
    }
    throw std::domain_error("B278 UTF-16 source must terminate within 4096 units");
}
std::uint32_t heap_length(Heap& h, std::uint32_t p, std::uint32_t limit) {
    require(p != 0, "B278 requires a nonnull owned byte string");
    for (std::uint32_t n = 0; n < limit; ++n)
        if (h.r8(checked_add(p, n)) == 0) return n;
    throw std::domain_error("B278 owned byte source lacks a bounded terminator");
}
void copy_counted_heap(Heap& h, std::uint32_t dst, std::uint32_t src,
                       std::uint32_t count) {
    // Exact accepted 0x76dd10 bounded-copy effect: stop at source NUL and
    // zero-pad the remainder. The root's original call executes 0x76dd10.
    for (std::uint32_t n = 0; n < count; ++n) {
        const auto c = h.r8(checked_add(src, n));
        h.w8(checked_add(dst, n), c);
        if (c == 0) {
            for (++n; n < count; ++n) h.w8(checked_add(dst, n), 0);
            return;
        }
    }
}
void copy_nul_terminated(Heap& h, std::uint32_t dst, std::uint32_t src,
                         std::uint32_t bytes) {
    for (std::uint32_t n = 0; n < bytes; ++n)
        h.w8(checked_add(dst, n), h.r8(checked_add(src, n)));
}
}

std::uint32_t rva_0035cbc0(Memory& m, const Inputs& i, Heap& h) {
    const auto output_cell = i.cx; // original ECX saved and later returned
    const auto source_holder = i.dx; // original EDX points to a UTF-16 pointer
    require(output_cell && source_holder && output_cell != source_holder,
            "B278 finite UTF-16 route requires distinct output and source-holder cells");
    require((i.arithmetic_flags & 0x400u) == 0,
            "B278 string loops require original direction flag clear");
    const auto source = m.r32(source_holder);
    require(source != 0, "B278 finite route selects a nonnull UTF-16 source");
    const auto units = guest_wide_length(m, source);
    require(units >= 1017u && units <= 4096u,
            "B278 finite route requires a 1017..4096-unit UTF-16 source");
    const auto bytes = checked_add(units, 1u);
    require(bytes > 1016u, "B278 source conversion allocation must be ordinary-heap sized");

    auto converted = h.allocate(bytes);
    require(converted != 0, "B278 success-only route requires conversion allocation success");
    // Inline the accepted 0x6eed90 Memory effect: bounded low-byte copy from
    // UTF-16, followed by a byte NUL. The pinned original calls the real helper.
    for (std::uint32_t n = 0; n < units; ++n) {
        const auto low = m.r8(checked_add(source, n * 2u));
        require(low != 0,
                "B278 finite route excludes nonzero UTF-16 units whose low byte truncates to NUL");
        h.w8(checked_add(converted, n), low);
    }
    h.w8(checked_add(converted, units), 0);

    // Original scans the converted buffer including its NUL, allocates that
    // count, initializes byte zero, then copies the complete terminated string.
    const auto copied_bytes = checked_add(units, 1u);
    auto joined = h.allocate(copied_bytes);
    require(joined != 0 && joined != converted,
            "B278 success-only route requires a distinct joined allocation");
    h.w8(joined, 0);
    copy_nul_terminated(h, joined, converted, copied_bytes);
    require(h.release(converted) != 0, "B278 conversion temporary free must succeed");

    m.w32(output_cell, 0);
    auto published = h.allocate(copied_bytes);
    require(published != 0 && published != joined,
            "B278 success-only route requires a distinct result allocation");
    m.w32(output_cell, published); // original publishes before copying bytes
    copy_nul_terminated(h, published, joined, copied_bytes);
    require(h.release(joined) != 0, "B278 joined temporary free must succeed");
    return output_cell; // full original EAX is the saved ECX on this path
}

std::uint32_t rva_0035a9a0(Memory& m, const Inputs& i, Heap& h) {
    const auto object = i.cx;
    const auto count = i.arg[0]; // original stack argument; RET 4
    require(object != 0 && (i.arithmetic_flags & 0x400u) == 0,
            "B278 byte-string route requires object and direction flag clear");
    require(count >= 1017u && count <= 4096u,
            "B278 finite byte-string route requires count 1017..4096");
    const auto source = m.r32(object);
    require(source != 0, "B278 finite route excludes the original null-source fallback");
    const auto source_length = heap_length(h, source, 4097u);
    require(source_length == count,
            "B278 fixture domain requires source length exactly equal to strncpy count");
    const auto temp_bytes = checked_add(count, 1u);

    auto temp = h.allocate(temp_bytes);
    require(temp != 0, "B278 success-only route requires temporary allocation success");
    h.w8(temp, 0);
    copy_counted_heap(h, temp, source, count); // original invokes 0x76dd10 here
    h.w8(checked_add(temp, count), 0);

    // Original frees the old object string before clearing the cell and before
    // allocating/publishing the replacement. The source was copied to temp.
    require(h.release(source) != 0, "B278 old owned string free must succeed");
    m.w32(object, 0);
    const auto length = heap_length(h, temp, temp_bytes);
    const auto result_bytes = checked_add(length, 1u);
    require(result_bytes > 1016u,
            "B278 final allocation must remain above the accepted small-block boundary");
    auto result = h.allocate(result_bytes);
    require(result != 0 && result != temp,
            "B278 success-only route requires a distinct result allocation");
    m.w32(object, result); // original publishes before its REP copy
    copy_nul_terminated(h, result, temp, result_bytes);
    const auto free_result = h.release(temp);
    require(free_result != 0u,
            "B278 route requires successful actual HeapFree; retain high EAX bits before MOV AL,1");
    return (free_result & 0xffffff00u) | 1u; // final MOV AL,1
}
}
