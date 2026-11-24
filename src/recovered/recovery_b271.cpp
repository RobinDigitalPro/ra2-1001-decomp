// RVA0x6d260: reviewed finite positive three-byte copy; see Block271 contract.
#include "recovery_b271.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b271 {
namespace {
void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

std::uint32_t fun_0046d260(Memory& m, const Inputs& in, Heap& heap) {
    const auto dst = in.cx;
    const auto src = in.arg[0];
    require(dst && src && dst != src,
            "B271 requires distinct nonnull destination and source records");
    const auto destination_end = std::uint64_t(dst) + 0x10u;
    const auto source_record_end = std::uint64_t(src) + 0x0cu;
    require(destination_end <= src || source_record_end <= dst,
            "B271 excludes source-record/destination overlap");

    // 0x46d26e..0x46d281: initial clearing, valid byte, and original vptr.
    m.w32(dst + 4u, 0u);
    m.w32(dst + 8u, 0u);
    m.w8(dst + 0x0cu, 1u);
    m.w8(dst + 0x0du, 0u);
    m.w32(dst, 0x00788a54u);

    // The exact .rdata slot is 0x788a60 -> 0x46d480. Accepted helper
    // 0x46d480 is the release-normal case for data +4, owner +0xd, size +8.
    // Because this caller cleared pointer and owner immediately before dispatch,
    // the actual reached helper path performs no release and leaves these
    // fields zero. No return value is synthesized for an indirect callback.
    require(m.r32(0x00788a60u) == 0x0046d480u,
            "B271 requires the original fixed clear-slot target");
    require(m.r32(dst + 4u) == 0u && m.r8(dst + 0x0du) == 0u,
            "B271 reaches 0x46d480 only after clearing pointer and owner");
    m.w8(dst + 0x0du, 0u);
    m.w32(dst + 8u, 0u);

    const auto count = m.r32(src + 8u);
    require(count >= 340u && count <= 403u,
            "B271 requires positive signed count 340..403");
    const auto source = m.r32(src + 4u);
    require(source != 0u, "B271 requires a readable source triple array");
    const auto source_data_end = std::uint64_t(source) + std::uint64_t(count) * 3u;
    require(destination_end <= source || source_data_end <= dst,
            "B271 excludes source-data/destination overlap");
    require(source_record_end <= source || source_data_end <= src,
            "B271 excludes source-data/source-record overlap");

    // Requests 1020..1209 all exceed the pinned 1016-byte CRT threshold.
    // Heap::allocate composes the accepted 0x36d957 wrapper with the real
    // ordinary-heap fixture adapter; allocation failure is outside this route.
    m.w32(dst + 8u, count);
    const auto bytes = count * 3u;
    const auto allocation = heap.allocate(bytes);
    require(allocation != 0u, "B271 excludes ordinary-heap allocation failure");
    m.w32(dst + 4u, allocation);

    // 0x46d2b2..0x46d2c0 zero-fills each 3-byte record before copying.
    for (std::uint32_t index = 0; index < count; ++index) {
        const auto offset = index * 3u;
        heap.w8(allocation + offset, 0u);
        heap.w8(allocation + offset + 1u, 0u);
        heap.w8(allocation + offset + 2u, 0u);
    }
    // 0x46d2da..0x46d2fb copies word then byte for every triple.
    for (std::uint32_t index = 0; index < count; ++index) {
        const auto offset = index * 3u;
        heap.w8(allocation + offset, m.r8(source + offset));
        heap.w8(allocation + offset + 1u, m.r8(source + offset + 1u));
        heap.w8(allocation + offset + 2u, m.r8(source + offset + 2u));
    }
    m.w8(dst + 0x0du, 1u);
    return dst; // Original MOV EAX,ESI; RET 4.
}
} // namespace ra2::recovered::recovery_b271
