#pragma once

// Exact selector-two sequence from original838E0. Other allocator routes retain their bounds.
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"

#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::platform::small_crt_heap781::palette208 {
inline const std::vector<unsigned>& requests(){static const std::vector<unsigned> r{8,8,12,8,12,12,12,8,8,12,8,12,12,12,12,12,12,8,8,12,8,12,12,12,12,12,16,16,16,16,4,4,8,12,12,12,12,16,16,16,16,16,16,16,12,12,16,16,16,16,8,12,8,12,12,12,8,12,8,12,12,12,12,12,12,8,12,8,12,12,12,12,16,16,16,16,12,16,16,16,16,16,16,16,12,16,16,16,16};return r;}
[[noreturn]] inline void unsupported(const char* message) {
    throw std::domain_error(message);
}
inline void need(bool value, const char* message) {
    if (!value) unsupported(message);
}

// Called only for allocation ordinal 1..88 (ordinal 0 uses the existing first
// allocation implementation). Expected previous extents are calculated from
// the exact 89-entry recipe, never from a generalized range allowance.
inline std::uint32_t allocate_existing_first_chunk(
    X86Memory& m, std::uint32_t request, std::uint32_t entry_esp,
    unsigned ordinal, const std::vector<unsigned>& recipe) {
    constexpr unsigned required_count = 89;
    need(recipe == requests() && ordinal >= 1 && ordinal < required_count,
         "208 exact selector-two Heap ordinal/recipe required");
    need(request == recipe[ordinal], "208 original request order required");

    const auto record = m.r32(0xb10e18u);
    need(m.r32(0xb10e14u) == 1 && m.r32(0xb10e0cu) == record,
         "208 existing first region/cursor required");
    need(m.r32(record) == 0 && m.r32(record + 4u) == 1,
         "208 existing region must contain only class-63 free extents");
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    need(m.r32(metadata) == 0 && m.r32(metadata + 0x44u) == 0 &&
         m.r32(metadata + 0xc4u) == 1,
         "208 existing chunk zero with empty lower classes required");
    need(m.r32(metadata + 0x144u) == ordinal,
         "208 exact prior-allocation count required");

    std::uint32_t consumed = 0;
    for (unsigned n = 0; n < ordinal; ++n) {
        need(recipe[n] == 4 || recipe[n] == 8 || recipe[n] == 12 || recipe[n] == 16,
             "208 recipe contains only original 4/8/12/16-byte requests");
        consumed += (recipe[n] + 0x17u) & ~0x0fu;
    }
    const auto expected_previous = 0x0ff0u - consumed;
    const auto node = m.r32(metadata + 0x340u);
    need(node == arena + 0x0cu && m.r32(node) == expected_previous,
         "208 exact page-zero residual extent required");
    const auto rounded = (request + 0x17u) & ~0x0fu;
    const auto residual = expected_previous - rounded;
    need(residual == 0x0ff0u - consumed - rounded && residual >= 0x400u,
         "208 next exact residual must remain in the class-63 extent");

    // Same original first-chunk split stores as 0x7736d3. The current recipe
    // leaves every remaining extent in class 63; only list head 63 is edited.
    m.w32(entry_esp + 4u, record);
    m.w32(0xb10e0cu, record);
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated = node + residual;
    m.w32(allocated, rounded + 1u);
    m.w32(allocated + rounded - 4u, rounded + 1u);
    m.w32(metadata + 0x144u, ordinal + 1u);
    m.w32(metadata, 0);
    return allocated + 4u;
}
} // namespace ra2::platform::small_crt_heap781::palette208
