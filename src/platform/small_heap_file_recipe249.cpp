#include "platform/small_heap_file_recipe249.hpp"

#include <stdexcept>

namespace ra2::platform::file_heap249 {
namespace {
constexpr std::uint32_t kRegionCount = 0x00b10e14u;
constexpr std::uint32_t kRegionTable = 0x00b10e18u;
constexpr std::uint32_t kCurrentRecord = 0x00b10e10u;
constexpr std::uint32_t kCurrentChunk = 0x00b10e08u;

void require(bool ok, const char* message) {
    if (!ok) throw std::runtime_error(message);
}

std::uint32_t clamp_class(std::uint32_t span) {
    require(span >= 0x10u && (span & 0x0fu) == 0,
            "CRT block span must be a positive 16-byte multiple");
    const auto raw = (span >> 4u) - 1u;
    return raw > 63u ? 63u : raw;
}

std::uint32_t chunk_base(std::uint32_t metadata, std::uint32_t chunk) {
    return metadata + 0x144u + chunk * 0x204u;
}

std::uint32_t list_head(std::uint32_t metadata,
                        std::uint32_t chunk,
                        std::uint32_t class_index) {
    return chunk_base(metadata, chunk) + class_index * 8u;
}

void clear_empty_class(Memory& m, std::uint32_t record,
                       std::uint32_t metadata, std::uint32_t chunk,
                       std::uint32_t class_index) {
    const auto head = list_head(metadata, chunk, class_index);
    require(m.r32(head + 4u) == head && m.r32(head + 8u) == head,
            "class ring is not empty after unlink");
    const auto count_address = metadata + 4u + class_index;
    const auto count = m.r8(count_address);
    require(count != 0, "free-class chunk count underflow");
    const auto next_count = static_cast<std::uint8_t>(count - 1u);
    m.w8(count_address, next_count);

    if (class_index < 32u) {
        const auto mask = 0x80000000u >> class_index;
        const auto map_address = metadata + 0x44u + chunk * 4u;
        m.w32(map_address, m.r32(map_address) & ~mask);
        if (next_count == 0)
            m.w32(record, m.r32(record) & ~mask);
    } else {
        const auto local = class_index - 32u;
        const auto mask = 0x80000000u >> local;
        const auto map_address = metadata + 0xc4u + chunk * 4u;
        m.w32(map_address, m.r32(map_address) & ~mask);
        if (next_count == 0)
            m.w32(record + 4u, m.r32(record + 4u) & ~mask);
    }
}

void unlink_free_neighbor(Memory& m, std::uint32_t record,
                          std::uint32_t metadata, std::uint32_t chunk,
                          std::uint32_t header, std::uint32_t span) {
    const auto class_index = clamp_class(span);
    const auto next = m.r32(header + 8u);
    const auto previous = m.r32(header + 4u);
    require(next != 0 && previous != 0,
            "free neighbor has incomplete circular-list links");
    const auto head = list_head(metadata, chunk, class_index);
    require(m.r32(head + 4u) != head || m.r32(head + 8u) != head,
            "free neighbor class ring unexpectedly empty");

    // Original 773452..773468 splice order: next->prev, then prev->next.
    m.w32(next + 4u, previous);
    m.w32(previous + 8u, next);
    if (m.r32(head + 4u) == head && m.r32(head + 8u) == head)
        clear_empty_class(m, record, metadata, chunk, class_index);
}

void insert_merged_free_block(Memory& m, std::uint32_t record,
                              std::uint32_t metadata, std::uint32_t chunk,
                              std::uint32_t header, std::uint32_t span) {
    const auto class_index = clamp_class(span);
    const auto head = list_head(metadata, chunk, class_index);
    const auto old_first = m.r32(head + 4u);
    require(old_first != 0, "free-class sentinel is not initialized");
    const bool was_empty = old_first == head;

    // Original 77353A..773555 insertion order.
    m.w32(header + 4u, old_first);
    m.w32(header + 8u, head);
    m.w32(old_first + 8u, header);
    m.w32(head + 4u, header);

    if (!was_empty) return;
    const auto count_address = metadata + 4u + class_index;
    const auto count = m.r8(count_address);
    m.w8(count_address, static_cast<std::uint8_t>(count + 1u));

    if (class_index < 32u) {
        const auto mask = 0x80000000u >> class_index;
        if (count == 0) m.w32(record, m.r32(record) | mask);
        const auto map_address = metadata + 0x44u + chunk * 4u;
        m.w32(map_address, m.r32(map_address) | mask);
    } else {
        const auto local = class_index - 32u;
        const auto mask = 0x80000000u >> local;
        if (count == 0) m.w32(record + 4u, m.r32(record + 4u) | mask);
        const auto map_address = metadata + 0xc4u + chunk * 4u;
        m.w32(map_address, m.r32(map_address) | mask);
    }
}
}

std::uint32_t allocate_class63_split(Memory& m, std::uint32_t record,
                                     std::uint32_t request) {
    require(record == m.r32(kRegionTable) && m.r32(kRegionCount) == 1,
            "file route requires the sole first CRT region");
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    require(metadata != 0 && arena != 0 && m.r32(metadata) == 0,
            "file route requires committed first chunk zero");
    const auto class63 = list_head(metadata, 0, 63);
    const auto node = m.r32(class63 + 4u);
    require(node == arena + 0x0cu && m.r32(node + 8u) != 0,
            "first class-63 extent is not page-zero residual node");
    const auto old_span = m.r32(node);
    require((old_span & 1u) == 0 && old_span >= 0x100u,
            "file route class-63 free extent is not large enough");
    const auto rounded = (request + 0x17u) & 0xfffffff0u;
    require(rounded >= 0x10u && rounded < old_span,
            "file route request does not leave a class-63 residual");
    const auto residual = old_span - rounded;
    require(clamp_class(residual) == 63u,
            "file route split would leave class 63");

    // Same-class branch 773877â†’77398A: retain the existing ring node and
    // write residual tags before allocated tags.
    m.w32(node, residual);
    m.w32(node + residual - 4u, residual);
    const auto allocated = node + residual;
    const auto allocated_tag = rounded + 1u;
    m.w32(allocated, allocated_tag);
    m.w32(allocated + rounded - 4u, allocated_tag);
    const auto live = m.r32(chunk_base(metadata, 0));
    m.w32(chunk_base(metadata, 0), live + 1u);
    if (live == 0 && record == m.r32(kCurrentRecord) &&
        m.r32(kCurrentChunk) == 0)
        m.w32(kCurrentRecord, 0);
    m.w32(metadata, 0);
    return allocated + 4u;
}

void release_file_small_block(Memory& m, std::uint32_t record,
                              std::uint32_t user) {
    require(record == m.r32(kRegionTable) && m.r32(kRegionCount) == 1,
            "file route free requires the first CRT region");
    const auto metadata = m.r32(record + 0x10u);
    const auto arena = m.r32(record + 0x0cu);
    require(metadata != 0 && arena != 0 && user >= arena + 0x10u &&
            user < arena + 0x1000u,
            "file route free pointer is outside committed page zero");
    const auto chunk = (user - arena) >> 15u;
    require(chunk == 0 && m.r32(metadata) == 0,
            "only chunk-zero small frees are in this route");

    auto header = user - 4u;
    const auto allocated_tag = m.r32(header);
    require((allocated_tag & 1u) != 0,
            "file route free requires a live allocated block");
    auto span = allocated_tag - 1u;
    require(span >= 0x10u && (span & 0x0fu) == 0 &&
            m.r32(header + span - 4u) == allocated_tag,
            "allocated block boundary tags do not match");

    // 7733E4..77346B: merge the following free block first.
    const auto next_header = header + span;
    const auto next_tag = m.r32(next_header);
    if ((next_tag & 1u) == 0) {
        const auto next_span = next_tag;
        require(next_span >= 0x10u && (next_span & 0x0fu) == 0,
                "following free block has an invalid span");
        unlink_free_neighbor(m, record, metadata, chunk, next_header, next_span);
        span += next_span;
    }

    // 77347C..773528: merge the preceding free block second.
    const auto previous_footer = m.r32(header - 4u);
    if ((previous_footer & 1u) == 0) {
        const auto previous_span = previous_footer;
        require(previous_span >= 0x10u && (previous_span & 0x0fu) == 0 &&
                previous_span <= header - (arena + 0x0cu),
                "preceding free footer is outside page-zero arena");
        const auto previous_header = header - previous_span;
        require(m.r32(previous_header) == previous_span,
                "preceding free header/footer mismatch");
        unlink_free_neighbor(m, record, metadata, chunk,
                            previous_header, previous_span);
        header = previous_header;
        span += previous_span;
    }

    // 77352B..7735CE: insert merged span, publish its tags, and decrement the
    // chunk's live-allocation count. This recipe's 63 class remains populated
    // by the seven other page extents, so decommit/region-free paths are out.
    insert_merged_free_block(m, record, metadata, chunk, header, span);
    m.w32(header, span);
    m.w32(header + span - 4u, span);
    const auto live_address = chunk_base(metadata, chunk);
    const auto live = m.r32(live_address);
    require(live != 0, "chunk live-allocation count underflow");
    m.w32(live_address, live - 1u);
    if (live != 1u) return;

    // On this exact route B10E10 is initially zero. The original 7735D4..C8
    // path then selects the supplied region record and stores chunk index 0.
    require(m.r32(kCurrentRecord) == 0,
            "nonempty-current-region cleanup/decommit path is excluded");
    m.w32(kCurrentRecord, record);
    m.w32(kCurrentChunk, chunk);
}

} // namespace ra2::platform::file_heap249
