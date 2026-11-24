#pragma once

// Exact one-row/one-column constructor sequence from original123480/122F30/810C0/7FCE0. Other allocator routes retain their bounds.
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"

#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::platform::small_crt_heap781::constructor226 {
inline const std::vector<unsigned>& requests(){static const std::vector<unsigned> r{12,88,32,20,4,4,12,10,12,10,4,10};return r;}
[[noreturn]] inline void unsupported(const char* message) {
    throw std::domain_error(message);
}
inline void need(bool value, const char* message) {
    if (!value) unsupported(message);
}

// Called only for allocation ordinal 1..11 (ordinal 0 uses the existing first
// allocation implementation). Expected previous extents are calculated from
// the exact 12-entry recipe, never from a generalized range allowance.
inline std::uint32_t allocate_existing_first_chunk(
    X86Memory& m, std::uint32_t request, std::uint32_t entry_esp,
    unsigned ordinal, const std::vector<unsigned>& recipe) {
    constexpr unsigned required_count = 12;
    need(recipe == requests() && ordinal >= 1 && ordinal < required_count,
         "226 exact one-row/one-column constructor Heap ordinal/recipe required");
    need(request == recipe[ordinal], "226 original request order required");

    const auto record = m.r32(0xb10e18u);
    need(m.r32(0xb10e14u) == 1 && m.r32(0xb10e0cu) == record,
         "226 existing first region/cursor required");
    need(m.r32(record) == 0 && m.r32(record + 4u) == 1,
         "226 existing region must contain only class-63 free extents");
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    need(m.r32(metadata) == 0 && m.r32(metadata + 0x44u) == 0 &&
         m.r32(metadata + 0xc4u) == 1,
         "226 existing chunk zero with empty lower classes required");
    need(m.r32(metadata + 0x144u) == ordinal,
         "226 exact prior-allocation count required");

    std::uint32_t consumed = 0;
    for (unsigned n = 0; n < ordinal; ++n) {
        need(recipe == requests(),
             "226 exact original constructor request vector");
        consumed += (recipe[n] + 0x17u) & ~0x0fu;
    }
    const auto expected_previous = 0x0ff0u - consumed;
    const auto node = m.r32(metadata + 0x340u);
    need(node == arena + 0x0cu && m.r32(node) == expected_previous,
         "226 exact page-zero residual extent required");
    const auto rounded = (request + 0x17u) & ~0x0fu;
    const auto residual = expected_previous - rounded;
    need(residual == 0x0ff0u - consumed - rounded && residual >= 0x400u,
         "226 next exact residual must remain in the class-63 extent");

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
} // namespace ra2::platform::small_crt_heap781::constructor226
