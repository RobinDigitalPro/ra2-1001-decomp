#pragma once
#include "recovered/global_b26_memory.hpp"
#include "recovered/text_b96.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovery_b248_detail {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// Mirrors only the positive cache-hit path of VA 0x495050 -> 0x5924c0.
// The real 0x5928A0 hash/table helper supplies the output pointer; this draft
// does not synthesize a callback result or implement the cache miss/CRT stream path.
inline std::uint32_t cache_hit(Memory& m, const Inputs& seed,
                               std::uint32_t key, std::uint32_t out_cell,
                               std::uint32_t wrapper_flag_cell) {
    m.w8(wrapper_flag_cell, 0);
    Inputs args = seed;
    args.cx = key;
    args.dx = out_cell;
    args.arg = {};
    const auto found = ra2::recovered::text_b96::fun_005928a0(m, args);
    if (!found || !m.r32(out_cell))
        throw std::domain_error("Block248 is limited to actual 5928a0 cache hits");
    return m.r32(out_cell);
}

// VA 0x6e7080: original reads 256 packed RGB triples from the cache payload,
// shifts each byte left by two, and writes exactly 768 bytes to the 0x300 CRT
// allocation. The 0x300 allocation remains live on this cache-hit route.
template<class HeapLike>
inline void convert_palette_6bit(Memory& m, HeapLike& h, std::uint32_t source,
                                 std::uint32_t destination) {
    for (std::uint32_t k = 0; k != 0x300u; ++k) h.w8(destination + k, 0);
    for (std::uint32_t n = 0; n != 256u; ++n) {
        for (std::uint32_t lane = 0; lane != 3u; ++lane) {
            const auto value = static_cast<std::uint8_t>(m.r8(source + n * 3u + lane));
            h.w8(destination + n * 3u + lane,
                 static_cast<std::uint8_t>(static_cast<unsigned>(value) << 2u));
        }
    }
}
} // namespace ra2::recovery_b248_detail
