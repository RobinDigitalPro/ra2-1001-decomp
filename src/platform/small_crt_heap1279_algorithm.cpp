#define NOMINMAX
#include "small_crt_heap1279_algorithm.hpp"

#include <windows.h>
#include <cstdint>
#include <stdexcept>

namespace ra2::platform::small_crt_heap1279 {
namespace {
constexpr std::uint32_t kHeapHandle = 0x00b10e1cu;
constexpr std::uint32_t kRegionCount = 0x00b10e14u;
constexpr std::uint32_t kRegionCapacity = 0x00b10e04u;
constexpr std::uint32_t kRegionTable = 0x00b10e18u;

[[noreturn]] void unsupported(const char* message) {
    throw std::domain_error(message);
}
void require(bool value, const char* message) {
    if (!value) unsupported(message);
}
}

// 0x7739dc, success branch with an initialized table and spare record capacity.
// The count==capacity HeapReAlloc path is intentionally excluded.
std::uint32_t create_region(X86Memory& m, RealWin32Api& api) {
    const auto count = m.r32(kRegionCount);
    const auto capacity = m.r32(kRegionCapacity);
    const auto table = m.r32(kRegionTable);
    const auto heap = m.r32(kHeapHandle);
    require(table != 0 && heap != 0, "CRT heap/table globals are not initialized");
    require(count < capacity, "region-table growth/reallocation is outside this draft");

    const auto record = table + count * 0x14u;
    const auto metadata = api.heap_alloc(heap, 0x8u, 0x41c4u); // HeapAlloc(..., HEAP_ZERO_MEMORY, ...)
    require(metadata != 0, "original 0x3739dc HeapAlloc failure path is excluded");
    m.w32(record + 0x10u, metadata);

    const auto arena = api.virtual_alloc(0, 0x100000u, MEM_RESERVE, PAGE_READWRITE);
    require(arena != 0, "original 0x3739dc VirtualAlloc failure/HeapFree path is excluded");
    m.w32(record + 0x0cu, arena);
    m.w32(record + 0x08u, 0xffffffffu);
    m.w32(record + 0x00u, 0);
    m.w32(record + 0x04u, 0);
    m.w32(kRegionCount, count + 1u);
    m.w32(metadata, 0xffffffffu);
    return record;
}

// 0x773a8d, first available arena chunk, successful MEM_COMMIT branch.
std::uint32_t commit_first_chunk(X86Memory& m,
                                                        RealWin32Api& api,
                                                        std::uint32_t record) {
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    require(metadata != 0 && arena != 0, "region record lacks metadata/arena allocation");

    auto available = m.r32(record + 0x08u);
    require(available != 0, "no available chunk bit; chunk-search failure is excluded");
    std::uint32_t chunk_index = 0;
    while ((available & 0x80000000u) == 0) {
        available <<= 1;
        ++chunk_index;
        require(chunk_index < 32, "no sign-bit chunk in region availability map");
    }
    require(chunk_index == 0, "only first chunk in a fresh region is in this draft");

    // 0x773aba..0x773ac7: initialize all 63 circular list-head sentinels,
    // preserving original write order for [head+8] and [head+4].
    const auto heads = metadata + 0x144u;
    for (std::uint32_t n = 0; n != 0x3fu; ++n) {
        const auto head = heads + n * 8u;
        m.w32(head + 8u, head);
        m.w32(head + 4u, head);
    }

    const auto chunk = arena + (chunk_index << 15u);
    const auto committed = api.virtual_alloc(chunk, 0x8000u, MEM_COMMIT, PAGE_READWRITE);
    require(committed == chunk, "original 0x373a8d commit failure or relocated result is excluded");

    // 0x773af0..0x773b34: create the eight page-sized free extents and their
    // boundary tags/links in ascending page order.
    const auto end = chunk + 0x7000u;
    for (std::uint32_t page = 0; page != 8; ++page) {
        const auto first_payload = chunk + page * 0x1000u + 0x10u;
        m.w32(first_payload - 8u, 0xffffffffu);
        m.w32(first_payload + 0xfecu, 0xffffffffu);
        m.w32(first_payload - 4u, 0x0ff0u);
        m.w32(first_payload, first_payload + 0x0ffcu);
        m.w32(first_payload + 4u, first_payload + 0xffffeffcu);
        m.w32(first_payload + 0xfe8u, 0x0ff0u);
    }

    // 0x773b36..0x773b50: splice first and last page extents into class-63 ring.
    const auto class63_head = heads + 0x1f8u;
    const auto first_extent = chunk + 0x0cu;
    const auto last_extent = end + 0x0cu;
    m.w32(class63_head + 4u, first_extent);
    m.w32(first_extent + 8u, class63_head);
    m.w32(class63_head + 8u, last_extent);
    m.w32(last_extent + 4u, class63_head);

    // 0x773b53..0x773b7e: set first-chunk availability and consume its region bit.
    m.w32(metadata + 0x44u, 0);
    m.w32(metadata + 0xc4u, 1u);
    const auto class63_chunk_count = m.r8(metadata + 0x43u);
    m.w8(metadata + 0x43u, static_cast<std::uint8_t>(class63_chunk_count + 1u));
    if (class63_chunk_count == 0)
        m.w32(record + 4u, m.r32(record + 4u) | 1u);
    m.w32(record + 8u, m.r32(record + 8u) & 0x7fffffffu);
    return chunk_index;
}

// 0x7736d3 successful route from an initialized, empty CRT region table to
// the first allocation from the first committed chunk. Exact request 0 is
// preserved at entry and in the caller argument slot; its native span is 0x10.
// No table growth, later chunks, retries or failure routes are modeled.
std::uint32_t allocate_first_zero(X86Memory& m,
                                                      RealWin32Api& api,
                                                      std::uint32_t request,
                                                      std::uint32_t entry_esp) {
    require(request == 0u && m.r32(entry_esp + 4u) == 0u,
            "B1279 only the actual first zero request reaches this path");
    require(m.r32(kRegionCount) == 0,
            "only a fresh initialized CRT small heap with no regions is supported");
    const auto table = m.r32(kRegionTable);
    require(table != 0 && m.r32(0x00b10e0cu) == table,
            "fresh CRT region scan cursor/table state is not initialized");
    require(m.r32(0x00b10558u) == 0,
            "non-null CRT new-handler retry is excluded");

    const auto rounded = (request + 0x17u) & 0xfffffff0u;
    const auto class_index = (rounded >> 4u) - 1u;
    require(class_index < 32u, "requested class takes the unimplemented upper-mask branch");


    // 0x773723..0x7737c8 scans the empty table, creates the first region,
    // commits chunk zero, stores that index at metadata[0], and selects it.
    // The cursor is the table at entry (verified above); the first record has
    // just one available 32 KiB chunk.
    // With count zero, EDI is exactly the table base. Preserve the original's
    // successive writes to [EBP+8] (entry ESP+4): table at 0x77372c, table at
    // 0x773753, table at 0x77378b, and finally the new region at 0x7737a8.
    m.w32(entry_esp + 4u, table);                 // 0x77372c
    m.w32(entry_esp + 4u, table);                 // 0x773753
    m.w32(entry_esp + 4u, table);                 // 0x77378b
    const auto record = create_region(m, api);
    m.w32(entry_esp + 4u, record);                // 0x7737a8; argument slot now aliases record
    const auto chunk_index = commit_first_chunk(m, api, record);
    const auto metadata = m.r32(record + 0x10u);
    m.w32(metadata, chunk_index);                 // 0x7737b4..0x7737b9
    m.w32(0x00b10e0cu, record);                   // 0x7737c8

    const auto chunk_map = m.r32(metadata + 0xc4u + chunk_index * 4u);
    const auto small_map = m.r32(metadata + 0x44u + chunk_index * 4u);
    require((chunk_map & 0xffffffffu) != 0 && small_map == 0,
            "fresh-chunk bitmap state does not select the initial class-63 extent");

    // 0x773826..0x773875: the only present extent is size class 63. Its node
    // is the first 4 KiB page extent at arena+0x0c, and its payload span is
    // 0x0ff0. The residual stays in class 63 for every supported request.
    const auto class_heads = metadata + 0x144u;
    const auto class63_head = class_heads + 63u * 8u;
    const auto arena = m.r32(record + 0x0cu);
    const auto node = m.r32(class63_head + 4u);
    require(node == arena + 0x0cu,
            "first class-63 node is not the initialized arena page-zero extent");
    require(m.r32(node) == 0x0ff0u,
            "first class-63 extent does not have the initialized 0x0ff0 span");

    // 0x773861..0x773877 computes residual span and clamps its class to 63.
    // The same-class branch at 0x773877 skips unlink/relink/count updates.
    const auto residual = m.r32(node) - rounded;
    require(residual != 0 && ((residual >> 4u) - 1u) >= 63u,
            "request no longer leaves the same class-63 residual path");

    // 0x77398a..0x7739a3. ECX still carries the residual across the same-class
    // branch. The order is significant: write residual header/footer, advance
    // EDX by residual, then write allocated header/footer using rounded span.
    m.w32(node, residual);                        // [EDX] = ECX
    m.w32(node + residual - 4u, residual);        // [EDX+ECX-4] = ECX
    const auto allocated_header = rounded + 1u;   // LEA ECX,[ESI+1]
    const auto allocated_block = node + residual; // ADD EDX,ECX (residual)
    m.w32(allocated_block, allocated_header);     // [EDX] = rounded+1
    m.w32(allocated_block + rounded - 4u, allocated_header);

    // 0x7739a7..0x7739d4 increments the first chunk's per-head counter,
    // leaves B10E10 unchanged because the selected record is nonzero, stores
    // chunk index at metadata[0], then returns EDX+4.
    const auto selected_counter = m.r32(class_heads);
    m.w32(class_heads, selected_counter + 1u);
    if (selected_counter == 0 && record == m.r32(0x00b10e10u) &&
        chunk_index == m.r32(0x00b10e08u)) {
        m.w32(0x00b10e10u, 0);
    }
    m.w32(metadata, chunk_index);
    return allocated_block + 4u;
}

// RVA 0x3736d3, second literal request 0. No intermediate ordinary request
// touches the CRT arena. The original stores its selected record in the
// caller argument slot, then splits the same class-63 page-zero extent.
std::uint32_t allocate_second_zero(X86Memory& m, std::uint32_t request,
                                   std::uint32_t entry_esp) {
    require(request == 0u && m.r32(entry_esp + 4u) == 0u,
            "B1279 second CRT entry must carry the actual zero argument");
    const auto record = m.r32(kRegionTable);
    require(record != 0 && m.r32(kRegionCount) == 1u &&
            m.r32(0x00b10e0cu) == record && m.r32(record) == 0u &&
            m.r32(record + 4u) == 1u && m.r32(record + 8u) == 0x7fffffffu,
            "B1279 second zero needs the exact first region maps");
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    const auto node = arena + 0x0cu;
    const auto head63 = metadata + 0x33cu;
    require(m.r32(metadata) == 0u && m.r32(metadata + 0x44u) == 0u &&
            m.r32(metadata + 0xc4u) == 1u && m.r32(metadata + 0x144u) == 1u &&
            m.r32(head63 + 4u) == node && m.r32(node) == 0xfe0u &&
            m.r32(node + 0xfdcu) == 0xfe0u &&
            m.r32(arena + 0xfec) == 0x11u && m.r32(arena + 0xff8) == 0x11u,
            "B1279 first zero must leave one live high-edge span");
    m.w32(entry_esp + 4u, record); // RVA 0x37372c, argument-slot alias
    m.w32(0x00b10e0cu, record);
    m.w32(node, 0xfd0u);
    m.w32(node + 0xfd0u - 4u, 0xfd0u);
    m.w32(arena + 0xfdcu, 0x11u);
    m.w32(arena + 0xfe8u, 0x11u);
    m.w32(metadata + 0x144u, 2u);
    m.w32(metadata, 0u);
    return arena + 0xfe0u;
}

// RVA 0x3733a8: +0xff0 is freed first, with an allocated left neighbor
// and the page sentinel on the right. A singleton class-0 ring is created.
void release_first_zero(X86Memory& m, std::uint32_t user) {
    const auto record = m.r32(kRegionTable);
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    const auto head = metadata + 0x144u;
    const auto block = arena + 0xfecu;
    require(m.r32(kRegionCount) == 1u && user == arena + 0xff0u &&
            m.r32(metadata + 0x144u) == 2u && m.r32(block) == 0x11u &&
            m.r32(block + 0x0cu) == 0x11u &&
            m.r32(block - 4u) == 0x11u &&
            m.r32(block + 0x10u) == 0xffffffffu &&
            m.r8(metadata + 4u) == 0u && m.r32(record) == 0u &&
            m.r32(metadata + 0x44u) == 0u &&
            m.r32(head + 4u) == head && m.r32(head + 8u) == head,
            "B1279 first zero free requires two exact live class-0 slots");
    m.w32(block + 4u, head);
    m.w32(block + 8u, head);
    m.w32(head + 4u, block);
    m.w32(head + 8u, block);
    m.w8(metadata + 4u, 1u);
    m.w32(record, 0x80000000u);
    m.w32(metadata + 0x44u, 0x80000000u);
    m.w32(block, 0x10u);
    m.w32(block + 0x0cu, 0x10u);
    m.w32(metadata + 0x144u, 1u);
}

// RVA 0x3733a8: the remaining +0xfe0 allocation joins the right class-0
// node and the left class-63 extent. The now-empty chunk remains committed
// and is tracked by B10E10/B10E08 until explicit CRT teardown.
void release_second_zero(X86Memory& m, std::uint32_t user) {
    const auto record = m.r32(kRegionTable);
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    const auto node = arena + 0x0cu;
    const auto block = arena + 0xfdcu;
    const auto right = arena + 0xfecu;
    const auto head = metadata + 0x144u;
    require(m.r32(kRegionCount) == 1u && user == arena + 0xfe0u &&
            m.r32(metadata + 0x144u) == 1u && m.r32(block) == 0x11u &&
            m.r32(block + 0x0cu) == 0x11u &&
            m.r32(node) == 0xfd0u && m.r32(block - 4u) == 0xfd0u &&
            m.r32(right) == 0x10u && m.r32(right + 0x0cu) == 0x10u &&
            m.r8(metadata + 4u) == 1u &&
            m.r32(head + 4u) == right && m.r32(head + 8u) == right &&
            m.r32(right + 4u) == head && m.r32(right + 8u) == head &&
            m.r32(record) == 0x80000000u &&
            m.r32(metadata + 0x44u) == 0x80000000u &&
            m.r32(0x00b10e10u) == 0u,
            "B1279 second zero free requires singleton right node and left extent");
    m.w32(metadata + 0x44u, 0u);
    m.w8(metadata + 4u, 0u);
    m.w32(record, 0u);
    m.w32(head + 4u, head);
    m.w32(head + 8u, head);
    m.w32(node, 0x0ff0u);
    m.w32(node + 0x0ff0u - 4u, 0x0ff0u);
    m.w32(metadata + 0x144u, 0u);
    m.w32(0x00b10e10u, record);
    m.w32(0x00b10e08u, 0u);
}

} // namespace ra2::platform::small_crt_heap1279

