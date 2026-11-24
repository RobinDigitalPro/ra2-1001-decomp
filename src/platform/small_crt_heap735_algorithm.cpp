#define NOMINMAX
#include "small_crt_heap_algorithm.hpp"

#include <windows.h>
#include <cstdint>
#include <stdexcept>

namespace ra2::platform::small_crt_heap {
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
std::uint32_t require_address(const void* pointer, const char* message) {
    const auto raw = reinterpret_cast<std::uintptr_t>(pointer);
    require(raw != 0 && raw <= 0xffffffffu, message);
    return static_cast<std::uint32_t>(raw);
}
}

std::uint32_t Kernel32RealApi::heap_alloc(std::uint32_t heap, std::uint32_t flags,
                                         std::uint32_t bytes) {
    static_assert(sizeof(void*) == 4, "small CRT heap adapter requires x86 Windows");
    auto* result = ::HeapAlloc(reinterpret_cast<HANDLE>(static_cast<std::uintptr_t>(heap)),
                               flags, bytes);
    return result ? require_address(result, "HeapAlloc returned a non-x86 pointer") : 0;
}

std::uint32_t Kernel32RealApi::virtual_alloc(std::uint32_t address, std::uint32_t bytes,
                                             std::uint32_t allocation_type,
                                             std::uint32_t protection) {
    static_assert(sizeof(void*) == 4, "small CRT heap adapter requires x86 Windows");
    auto* result = ::VirtualAlloc(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)),
                                  bytes, allocation_type, protection);
    return result ? require_address(result, "VirtualAlloc returned a non-x86 pointer") : 0;
}

// 0x7739dc, success branch with an initialized table and spare record capacity.
// The count==capacity HeapReAlloc path is intentionally excluded.
std::uint32_t fun_007739dc_create_region(X86Memory& m, RealWin32Api& api) {
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
std::uint32_t fun_00773a8d_commit_first_available_chunk(X86Memory& m,
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
// the first allocation from the first committed chunk. The request is bounded
// to 1..111 bytes (request1 is restricted to the exact tuple223 recipe), exact 156-byte Block250, 212-byte Block177 232-byte Block200 and 424-byte Block231 requests;
// table growth, later chunks/regions, retries and failure
// routes are intentionally excluded.
std::uint32_t fun_007736d3_allocate_first_small_block(X86Memory& m,
                                                      RealWin32Api& api,
                                                      std::uint32_t request,
                                                      std::uint32_t entry_esp) {
    require((request >= 1u && request <= 111u) || request == 156u || request == 212u || request == 232u || request == 256u || request == 424u,
            "B735 private fork adds only request256 to the reviewed CRT allocation domain");
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
    const auto record = fun_007739dc_create_region(m, api);
    m.w32(entry_esp + 4u, record);                // 0x7737a8; argument slot now aliases record
    const auto chunk_index = fun_00773a8d_commit_first_available_chunk(m, api, record);
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

std::uint32_t fun_007736d3_allocate_existing_first_chunk(X86Memory& m,
                                                       std::uint32_t request,
                                                       std::uint32_t entry_esp) {
    require((request>=2 && request<=12)||request==40,"bounded subsequent string/node request");
    const auto record=m.r32(kRegionTable);
    require(m.r32(kRegionCount)==1 && m.r32(0xb10e0c)==record,
            "existing first region/cursor required");
    require(m.r32(record)==0 && m.r32(record+4)==1,
            "existing region must contain only class-63 free extents");
    const auto metadata=m.r32(record+0x10),arena=m.r32(record+0x0c);
    require(m.r32(metadata)==0 && m.r32(metadata+0x44)==0 && m.r32(metadata+0xc4)==1,
            "existing chunk zero with empty lower classes required");
    const auto count=m.r32(metadata+0x144);
    require(count>=1 && count<=3,"only second through fourth live small allocation supported");
    // 77372c writes the region cursor into the caller's argument slot. Its
    // class-63 bitmap is nonzero, so 77373d/77374d jump directly to7737c8.
    m.w32(entry_esp+4,record);
    m.w32(0xb10e0c,record);
    // Current chunk is zero and has class63, taking7737ed ->773826.
    const auto node=m.r32(metadata+0x340);
    require(node==arena+0x0c,"page-zero residual extent required");
    const auto rounded=(request+0x17)&~15u;
    const auto previous=m.r32(node);
    require(previous>=0xf80 && previous<=0xfe0,"bounded preceding live slots required");
    const auto residual=previous-rounded;
    require(((residual>>4)-1)>=63,"same class-63 split required");
    // Same-class jump773877 ->77398a preserves the residual in ECX.
    m.w32(node,residual);m.w32(node+residual-4,residual);
    const auto allocated=node+residual;
    m.w32(allocated,rounded+1);m.w32(allocated+rounded-4,rounded+1);
    m.w32(metadata+0x144,count+1);
    // The prior counter is nonzero, so the empty-chunk cleanup globals are
    // skipped by7739ac. Only the current chunk index is stored again.
    m.w32(metadata,0);
    return allocated+4;
}

void fun_007733a8_release_class1_temporary(X86Memory& m, std::uint32_t user) {
    const auto record=m.r32(kRegionTable),metadata=m.r32(record+0x10),arena=m.r32(record+0xc);
    const auto header=user-4,head=metadata+0x14c;
    require(m.r32(kRegionCount)==1&&m.r32(0xb10e0c)==record&&m.r32(metadata)==0,
            "class1 release requires the current first region/chunk");
    require(user==arena+0xfe0&&m.r32(header)==0x21&&m.r32(header+0x1c)==0x21,
            "release requires the exact request9 allocated tags");
    require(m.r32(user-8)==0x31&&m.r32(header+0x20)==0xffffffff,
            "release requires allocated left neighbor and right page sentinel");
    require(m.r32(arena+0xc)==0xf80&&m.r32(metadata+0x144)==4,
            "release requires all four allocated slots and unchanged residual");
    require(m.r32(record)==0&&m.r32(record+4)==1&&m.r32(metadata+0x44)==0&&
            m.r8(metadata+5)==0&&m.r32(head+4)==head&&m.r32(head+8)==head,
            "class1 free list must be empty before insertion");
    // 77353a..773558: links name the free block HEADER, not its user address.
    const auto next=m.r32(head+4);
    m.w32(header+4,next);m.w32(header+8,head);m.w32(head+4,header);m.w32(next+8,header);
    // 773560..773595, class1 previously absent from chunk and region maps.
    m.w8(metadata+5,1);m.w32(record,m.r32(record)|0x40000000u);
    m.w32(metadata+0x44,m.r32(metadata+0x44)|0x40000000u);
    // 7735c0..7735ce: write free tags, decrease live count; nonzero skips decommit.
    m.w32(header,0x20);m.w32(header+0x1c,0x20);m.w32(metadata+0x144,3);
}

} // namespace ra2::platform::small_crt_heap
