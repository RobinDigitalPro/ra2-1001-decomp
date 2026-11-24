#include "recovery_b272.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b272 {
namespace {
constexpr std::uint32_t kWidth = 1017u;
constexpr std::uint32_t kHeight = 255u;
constexpr std::uint32_t kPixels = kWidth * kHeight;
constexpr std::uint32_t kPackedBytes = ((kWidth + 3u) / 4u) * kHeight;

void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
}

// Structural contract: positive packed two-bit expansion only, with
// all requests inside the accepted real ordinary-heap adapter's 1017+ byte
// domain. The existing 0x36d957 wrapper is forwarding evidence only; callers
// must supply the real ordinary-heap implementation and preserve live blocks.
std::uint32_t fun_00720f70(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver = i.cx;
    require(receiver != 0u, "Block272 requires a mapped receiver span");
    require(m.r32(receiver + 0x20u) == kWidth &&
                m.r32(receiver + 0x24u) == kHeight,
            "Block272 covers width 1017 and height 255 only");
    require(i.arg[0] != 0u,
            "Block272 requires a nonnull packed source at entry ESP+4");
    require(i.arg[1] == kPackedBytes,
            "Block272 requires 65025 packed bytes at entry ESP+8");

    const auto row_table = heap.allocate(kHeight * 4u);
    require(row_table != 0u,
            "Block272 is success-only for the 1020-byte row-table allocation");
    m.w32(receiver + 0x44u, row_table);

    // Original allocates all rows first, then decodes each byte-aligned row.
    for (std::uint32_t y=0;y<kHeight;++y) {
        const auto row=heap.allocate(kWidth);
        require(row!=0u,"Block272 excludes per-row allocation failure");
        heap.w32(row_table+y*4u,row);
    }
    // [ESP+0x10] before PUSH EBX/EBP, and [ESP+0x18] afterward,
    // are the second caller argument. It becomes the within-byte cursor.
    i.arg[1]=0u;
    for (std::uint32_t y=0;y<kHeight;++y) {
        const auto row=heap.r32(row_table+y*4u);
        for(std::uint32_t x=0;x<kWidth;++x) {
            const auto packed=m.r8(i.arg[0]+y*((kWidth+3u)/4u)+x/4u);
            heap.w8(row+x,(packed>>((x&3u)*2u))&3u);
        }
        // 72102c..721037 discards unused pairs and advances to the next byte.
    }

    // Original 0x721037 leaves EAX=height before MOV AL,1 at 0x721042.
    return (kHeight & 0xffffff00u) | 1u;
}
}
