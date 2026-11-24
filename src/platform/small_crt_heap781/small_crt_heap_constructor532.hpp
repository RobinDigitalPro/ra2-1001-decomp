#pragma once
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

// Exact first-region/page-zero allocation protocol used by resource B532.
// This is a private recipe fork; shared allocator sources remain unchanged.
namespace ra2::platform::small_crt_heap781::constructor532 {
inline const std::vector<unsigned>& requests() {
    static const std::vector<unsigned> r{288, 36, 20, 148};
    return r;
}
inline const std::vector<unsigned>& pointer_offsets() {
    // Queue +8 points to storage; +12/+16 point to records, and storage[1]
    // points to the records array after the positive insertion.
    static const std::vector<unsigned> p{0xe88, 0xe8c, 0xe90, 0xde4};
    return p;
}
[[noreturn]] inline void fail(const char* why) { throw std::domain_error(why); }
inline void need(bool ok, const char* why) { if (!ok) fail(why); }

inline std::uint32_t allocate_first(X86Memory& m, RealWin32Api& api,
                                    std::uint32_t request, std::uint32_t entry_esp,
                                    const std::vector<unsigned>& recipe) {
    need(recipe == requests() && request == 288u,
         "B532 exact first allocation request 288 required");
    need(m.r32(0x00b10e14u) == 0u,
         "B532 first request requires a fresh initialized CRT region table");
    const auto table = m.r32(0x00b10e18u);
    need(table != 0u && m.r32(0x00b10e0cu) == table,
         "B532 first request requires initialized table/cursor identity");
    need(m.r32(0x00b10558u) == 0u,
         "B532 excludes a nonnull CRT new-handler retry");

    const auto rounded = (request + 0x17u) & 0xfffffff0u;
    const auto request_class = (rounded >> 4u) - 1u;
    need(rounded == 0x130u && request_class == 18u && request_class < 32u,
         "B532 288-byte request must take original lower-mask class 18 path");

    // The body at 0x7736d3 writes the region-table cursor through [EBP+8]
    // before and after region creation. The successful fresh-table path is
    // the same setup used by the B519 translation.
    m.w32(entry_esp + 4u, table);                 // 0x77372c
    m.w32(entry_esp + 4u, table);                 // 0x773753
    m.w32(entry_esp + 4u, table);                 // 0x77378b
    const auto record = fun_007739dc_create_region(m, api);
    m.w32(entry_esp + 4u, record);                // 0x7737a8
    const auto chunk_index = fun_00773a8d_commit_first_available_chunk(m, api, record);
    const auto metadata = m.r32(record + 0x10u);
    m.w32(metadata, chunk_index);                 // 0x7737b4..0x7737b9
    m.w32(0x00b10e0cu, record);                   // 0x7737c8

    need(chunk_index == 0u && m.r32(metadata + 0xc4u) == 1u &&
         m.r32(metadata + 0x44u) == 0u,
         "B532 requires the original fresh chunk-zero class-63 extent");
    const auto chunk_heads = metadata + 0x144u;
    const auto class63_head = chunk_heads + 63u * 8u;
    const auto arena = m.r32(record + 0x0cu);
    const auto node = m.r32(class63_head + 4u);
    need(node == arena + 0x0cu && m.r32(node) == 0x0ff0u,
         "B532 fresh page-zero class-63 span must be 0xff0");

    // 0x773861..0x773877: 0x0ff0 - 0x130 = 0x0ec0;
    // ((0x0ec0 >> 4) - 1) = 235, capped to class 63 at 0x77386d..75.
    // The selected free-list class is also 63, so the original same-class
    // branch goes straight to 0x77398a with no free-list relink.
    const auto residual = m.r32(node) - rounded;
    const auto residual_class = (residual >> 4u) - 1u;
    need(residual == 0x0ec0u && residual_class == 235u &&
         std::min(residual_class, 63u) == 63u,
         "B532 first split must remain in class 63");
    m.w32(node, residual);                        // 0x77398e
    m.w32(node + residual - 4u, residual);        // 0x773990
    const auto allocated_header = rounded + 1u;
    const auto allocated = node + residual;
    m.w32(allocated, allocated_header);            // 0x7739a1
    m.w32(allocated + rounded - 4u, allocated_header); // 0x7739a3

    const auto live_count = m.r32(chunk_heads);
    m.w32(chunk_heads, live_count + 1u);          // 0x7739aa..b1
    if (live_count == 0u && record == m.r32(0x00b10e10u) &&
        chunk_index == m.r32(0x00b10e08u))
        m.w32(0x00b10e10u, 0u);                   // 0x7739b5..c8 conditional
    m.w32(metadata, chunk_index);                 // 0x7739cf..d2
    return allocated + 4u;                        // 0x7739d4
}

inline std::uint32_t allocate_existing(X86Memory& m, std::uint32_t request,
                                       std::uint32_t entry_esp, unsigned ordinal,
                                       const std::vector<unsigned>& recipe) {
    const auto& exact = requests();
    need(recipe == exact && ordinal >= 1u && ordinal < exact.size() &&
         request == exact[ordinal], "B532 exact subsequent request order required");
    const auto record = m.r32(0x00b10e18u);
    need(m.r32(0x00b10e14u) == 1u && m.r32(0x00b10e0cu) == record,
         "B532 subsequent request requires one initialized region/current cursor");
    need(m.r32(record) == 0u && m.r32(record + 4u) == 1u,
         "B532 region must retain the one page-zero chunk");
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    need(m.r32(metadata) == 0u && m.r32(metadata + 0x44u) == 0u &&
         m.r32(metadata + 0xc4u) == 1u &&
         m.r32(metadata + 0x144u) == ordinal,
         "B532 exact prior live-count and class-map state required");
    const auto node = m.r32(metadata + 0x340u);
    need(node == arena + 0x0cu, "B532 current class-63 page-zero residual required");
    const std::array<std::uint32_t, 4> expected_before{0xff0u, 0xec0u, 0xe90u, 0xe70u};
    const std::array<std::uint32_t, 4> expected_residual{0xec0u, 0xe90u, 0xe70u, 0xdd0u};
    const std::array<std::uint32_t, 4> expected_span{0x130u, 0x30u, 0x20u, 0xa0u};
    const auto rounded = (request + 0x17u) & 0xfffffff0u;
    need(rounded == expected_span[ordinal] && m.r32(node) == expected_before[ordinal],
         "B532 next allocation span differs from exact recipe");
    const auto residual = expected_before[ordinal] - rounded;
    const auto residual_class = (residual >> 4u) - 1u;
    need(residual == expected_residual[ordinal] && residual_class > 63u,
         "B532 residual must clamp to the existing class-63 list");

    // 0x77372c/0x7737c8 current-record writes, followed by the same-class
    // split at 0x773877 -> 0x77398a. The class-63 list links and class count
    // remain intact; only boundary tags, live count, and chunk index update.
    m.w32(entry_esp + 4u, record);
    m.w32(0x00b10e0cu, record);
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated = node + residual;
    const auto allocated_header = rounded + 1u;
    m.w32(allocated, allocated_header);
    m.w32(allocated + rounded - 4u, allocated_header);
    m.w32(metadata + 0x144u, ordinal + 1u);
    m.w32(metadata, 0u);
    return allocated + 4u;
}
}
