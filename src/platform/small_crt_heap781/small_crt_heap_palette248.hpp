#pragma once

// Exact first-allocation upper-mask route plus subsequent same-class splits
// for the pinned 0x6e7c30 constructor recipe. This is a private integration
// proposal; the general shared allocator remains unchanged.
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"

#include <array>
#include <vector>
#include <cstdint>
#include <stdexcept>

namespace ra2::platform::small_crt_heap781::palette248 {
inline constexpr std::array<std::uint32_t, 29> requests{{
    0x300, 0x188, 0x100, 0x100, 8, 8, 12, 8, 12, 12, 12, 8, 12, 8, 12,
    12, 12, 8, 12, 8, 12, 12, 12, 8, 12, 8, 12, 12, 12}};

inline void require(bool okay, const char* message) {
    if (!okay) throw std::domain_error(message);
}

// Ordinal zero is the only fresh-state path. It translates the actual
// >=32-class bitmap branch: request 0x300 rounds to 0x310/class 48, whose
// upper mask is 0x0000ffff. The only set upper bit is class 63 (bit zero),
// the freshly committed first-chunk extent. The existing original-derived
// region creation and commit helpers preserve their real Win32 calls.
inline std::uint32_t allocate_first(X86Memory& m, RealWin32Api& api,
                                    std::uint32_t request,
                                    std::uint32_t entry_esp,
                                    const std::array<std::uint32_t, 29>& recipe) {
    require(recipe == requests && request == 0x300,
            "248 first allocation requires the exact 29-request recipe");
    require(m.r32(0xb10e14u) == 0 && m.r32(0xb10e18u) != 0 &&
            m.r32(0xb10e0cu) == m.r32(0xb10e18u) &&
            m.r32(0xb10558u) == 0,
            "248 fresh CRT heap/table/cursor state required");

    const auto rounded = (request + 0x17u) & 0xfffffff0u;
    const auto class_index = (rounded >> 4u) - 1u;
    require(rounded == 0x310u && class_index == 48u,
            "248 exact class-48 request required");
    const std::uint32_t upper_mask = 0xffffffffu >> (class_index - 32u);
    require(upper_mask == 0x0000ffffu,
            "248 exact original high-bitmap mask required");

    // 0x773723..0x7737c8: scan empty table, create first region, commit
    // chunk zero, publish its class-63 free extent, and update the caller's
    // saved argument slot as the original instructions do.
    const auto table = m.r32(0xb10e18u);
    m.w32(entry_esp + 4u, table); // VA 0x77372c
    m.w32(entry_esp + 4u, table); // VA 0x773753
    m.w32(entry_esp + 4u, table); // VA 0x77378b
    const auto record = fun_007739dc_create_region(m, api);
    m.w32(entry_esp + 4u, record); // VA 0x7737a8
    const auto chunk = fun_00773a8d_commit_first_available_chunk(m, api, record);
    const auto metadata = m.r32(record + 0x10u);
    m.w32(metadata, chunk); // VA 0x7737b4
    m.w32(0xb10e0cu, record); // VA 0x7737c8

    const auto arena = m.r32(record + 0x0cu);
    require(chunk == 0 && m.r32(metadata + 0xc4u) == 1u &&
            m.r32(metadata + 0x44u) == 0,
            "248 committed chunk-zero upper bitmap state required");
    const auto node = m.r32(metadata + 0x340u);
    require(node == arena + 0x0cu && m.r32(node) == 0x0ff0u,
            "248 original class-63 source extent required");

    // The upper-mask scan selects the existing class-63 node. The original
    // same-class path leaves the residual linked and writes both boundary
    // tags for the residual and the allocated 0x310-byte block.
    const auto residual = 0x0ff0u - rounded;
    require(residual == 0x0ce0u && ((residual >> 4u) - 1u) >= 63u,
            "248 class-48 allocation must leave a class-63 residual");
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated = node + residual;
    const auto tag = rounded + 1u;
    m.w32(allocated, tag);
    m.w32(allocated + rounded - 4u, tag);
    const auto class_heads = metadata + 0x144u;
    m.w32(class_heads, m.r32(class_heads) + 1u); // VA 0x7739a7 path
    m.w32(metadata, chunk);
    return allocated + 4u;
}

// Ordinals 1..28 only. The original scan sees the existing class-63 extent,
// takes the same-class split, updates the exact caller argument slot, and
// preserves the empty lower-class maps. No release, growth, or fallback is
// generalized by this bounded adapter.
inline std::uint32_t allocate_existing(
    X86Memory& m, std::uint32_t request, std::uint32_t entry_esp,
    unsigned ordinal, const std::array<std::uint32_t, 29>& recipe) {
    require(recipe == requests && ordinal >= 1 && ordinal < requests.size() &&
            request == requests[ordinal],
            "248 exact subsequent allocation ordinal/recipe required");
    const auto record = m.r32(0xb10e18u);
    require(m.r32(0xb10e14u) == 1u && m.r32(0xb10e0cu) == record &&
            m.r32(record) == 0 && m.r32(record + 4u) == 1,
            "248 existing single-region state required");
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    const auto node = m.r32(metadata + 0x340u);
    require(m.r32(metadata) == 0 && m.r32(metadata + 0x44u) == 0 &&
            m.r32(metadata + 0xc4u) == 1u &&
            m.r32(metadata + 0x144u) == ordinal && node == arena + 0x0cu,
            "248 exact live count/class-63 residual required");

    std::uint32_t consumed = 0;
    for (unsigned n = 0; n < ordinal; ++n)
        consumed += (requests[n] + 0x17u) & 0xfffffff0u;
    const auto expected_previous = 0x0ff0u - consumed;
    const auto rounded = (request + 0x17u) & 0xfffffff0u;
    require(m.r32(node) == expected_previous && expected_previous >= rounded + 0x400u,
            "248 exact preceding residual/same-class branch required");

    m.w32(entry_esp + 4u, record); // VA 0x77372c
    m.w32(0xb10e0cu, record);      // VA 0x7737c8
    const auto residual = expected_previous - rounded;
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated = node + residual;
    const auto tag = rounded + 1u;
    m.w32(allocated, tag);
    m.w32(allocated + rounded - 4u, tag);
    m.w32(metadata + 0x144u, ordinal + 1u);
    m.w32(metadata, 0u);
    return allocated + 4u;
}
} // namespace ra2::platform::small_crt_heap781::palette248

namespace ra2::platform::small_crt_heap781::palette248 {inline const std::vector<unsigned>& request_vector(){static const std::vector<unsigned> v(requests.begin(),requests.end());return v;}inline const std::vector<unsigned>& pointer_offsets(){static const std::vector<unsigned> v{0x6b4,0x6b8,0x6d4,0x6d8,0x6f4,0x6f8,0x714,0x724,0x728,0x744,0x754,0x758,0x774,0x778,0x794,0x798,0x7b4,0x7c4,0x7c8,0x7e4,0x7f4,0x7f8,0x814,0x818,0x834,0x838,0x854,0x864,0x868,0x884,0x894,0x898,0x8b4,0x8b8,0x8d4,0x8d8,0x8f4,0x904,0x908,0x924,0x934,0xb68,0xb6c,0xb70,0xb74,0xb78,0xb7c,0xb80,0xc30,0xc34,0xc38,0xc3c,0xc40,0xc44,0xc48,0xc4c,0xc50,0xc54,0xc58,0xc5c,0xc6c,0xc70,0xc74,0xc78,0xc7c,0xc80,0xcd0,0xcd4,0xcd8};return v;}}
