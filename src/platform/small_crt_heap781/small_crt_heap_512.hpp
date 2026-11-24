#pragma once
#define NOMINMAX
#include "small_crt_heap_algorithm.hpp"

#include <windows.h>
#include <stdexcept>

namespace ra2::platform::small_crt_heap781::fresh512 {
namespace {
[[noreturn]] inline void unsupported(const char* why) { throw std::domain_error(why); }
inline void require(bool ok, const char* why) { if (!ok) unsupported(why); }
}

inline std::uint32_t allocate_fresh512_uppermask_class32(
    X86Memory& m, RealWin32Api& api, std::uint32_t request,
    std::uint32_t entry_esp) {
    constexpr std::uint32_t table_count = 0x00b10e14u;
    constexpr std::uint32_t table_cursor = 0x00b10e0cu;
    constexpr std::uint32_t table_base = 0x00b10e18u;
    constexpr std::uint32_t new_handler = 0x00b10558u;
    constexpr std::uint32_t threshold = 0x00817554u;

    require(request == 512u, "fresh512 protocol supports exactly request 512");
    require(m.r32(threshold) == 1016u, "small/large CRT threshold changed");
    require(m.r32(table_count) == 0u, "fresh empty region table required");
    const auto table = m.r32(table_base);
    require(table != 0u && m.r32(table_cursor) == table,
            "initialized CRT cursor must equal non-null region table");
    require(m.r32(new_handler) == 0u, "new-handler retries are excluded");
    require(m.r32(0x00b10e04u) != 0u, "region-table capacity must be nonzero");

    // VA 0x7736d3: rounded size is 0x210, class index 32. This is the
    // upper-mask arm (ESI=0, mask=0xffffffff), handled separately here.
    constexpr std::uint32_t rounded = 0x210u;
    const auto class_index = (rounded >> 4u) - 1u;
    require(class_index == 32u, "request must enter the upper-mask class-32 arm");

    // VA 0x773723..0x773826: fresh table scan, 0x7739dc region creation,
    // 0x773a8d first chunk commit, and cursor/metadata initialization.
    m.w32(entry_esp + 4u, table); // 0x77372c
    m.w32(entry_esp + 4u, table); // 0x773753
    m.w32(entry_esp + 4u, table); // 0x77378b
    const auto record = fun_007739dc_create_region(m, api);
    require(record == table, "fresh first region record must be table[0]");
    m.w32(entry_esp + 4u, record); // 0x7737a8
    require(fun_00773a8d_commit_first_available_chunk(m, api, record) == 0u,
            "fresh first committed chunk must be chunk zero");

    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    require(metadata != 0u && arena != 0u, "actual metadata/arena identities required");
    m.w32(metadata, 0u);                       // 0x7737b7: selected chunk index
    m.w32(table_cursor, record);               // 0x7737c8

    // VA 0x773826..0x77385f: upper-mask class search. The lower map is zero;
    // upper-map bit zero is the only available bit, so the scan reaches class
    // 63 after 31 shifts beginning at upper class 32.
    const auto upper_map = m.r32(metadata + 0xc4u);
    const auto lower_map = m.r32(metadata + 0x44u);
    require(upper_map == 1u && lower_map == 0u,
            "fresh class maps must select the sole upper-map class-63 extent");
    auto class_bits = upper_map;
    auto chosen_class = class_index;
    while ((class_bits & 0x80000000u) == 0u) {
        class_bits <<= 1u;
        ++chosen_class;
        require(chosen_class < 64u, "upper class bitmap has no available sign bit");
    }
    require(chosen_class == 63u, "fresh upper-map selection must resolve to class 63");
    const auto heads = metadata + 0x144u;
    const auto class63_head = heads + chosen_class * 8u;
    const auto node = m.r32(class63_head + 4u);
    require(node == arena + 0x0cu && m.r32(node) == 0x0ff0u,
            "first class-63 arena extent required");

    // VA 0x773861..0x773877: residual 0xde0 clamps to class 63. The
    // same-class branch skips unlink/relink, bitmap, and class-count edits.
    constexpr std::uint32_t residual = 0x0de0u;
    require(m.r32(node) - rounded == residual, "class-63 residual changed");
    const auto residual_class = (residual >> 4u) - 1u;
    const auto clamped_residual_class = residual_class > 63u ? 63u : residual_class;
    require(clamped_residual_class == chosen_class,
            "residual no longer clamps to class 63");

    // VA 0x77398a..0x7739a3 and 0x7739a7..0x7739d4: exact boundary tags,
    // first live counter, and chunk index. The write ordering follows the
    // original instructions; no pointer-valued field is fabricated here.
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated_block = node + residual;
    m.w32(allocated_block, rounded + 1u);
    m.w32(allocated_block + rounded - 4u, rounded + 1u);
    const auto head_count = m.r32(heads);
    require(head_count == 0u, "fresh first allocation counter must start at zero");
    m.w32(heads, 1u);
    m.w32(metadata, 0u);
    return allocated_block + 4u; // arena+0xdf0, 512-byte user area
}

} // namespace ra2::platform::small_crt_heap781::fresh512
