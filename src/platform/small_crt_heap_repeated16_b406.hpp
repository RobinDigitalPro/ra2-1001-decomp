#pragma once
#include "platform/small_crt_heap_algorithm.hpp"
#include <cstdint>
#include <stdexcept>
#include <vector>

// Private B406-only extension: the verified fresh-region request-16 sequence.
// Caller owns the real CRT critical-section enter/leave around each invocation.
namespace ra2::recovery_b406 {
inline void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
inline std::uint32_t allocate16(ra2::platform::small_crt_heap::X86Memory& m,
                                ra2::platform::small_crt_heap::RealWin32Api& api,
                                std::uint32_t entry_esp, unsigned ordinal,
                                unsigned total) {
    using namespace ra2::platform::small_crt_heap;
    require((total == 8u || total == 16u) && ordinal < total,
            "B406 accepts only the exact eight/sixteen request-16 recipes");
    require(m.r32(0x00b10558u) == 0u,
            "B406 excludes a nonnull CRT new-handler retry");
    if (ordinal == 0u) {
        const auto p = fun_007736d3_allocate_first_small_block(m, api, 16u, entry_esp);
        require(p != 0u, "B406 excludes first small-allocation failure");
        return p;
    }
    const auto record = m.r32(0x00b10e18u);
    require(m.r32(0x00b10e14u) == 1u && m.r32(0x00b10e0cu) == record,
            "B406 requires the initialized first CRT region/current cursor");
    require(m.r32(record) == 0u && m.r32(record + 4u) == 1u,
            "B406 requires one region containing the class-63 residual");
    const auto metadata = m.r32(record + 0x10u), arena = m.r32(record + 0x0cu);
    require(m.r32(metadata) == 0u && m.r32(metadata + 0x44u) == 0u &&
            m.r32(metadata + 0xc4u) == 1u,
            "B406 requires only first committed chunk and no lower free classes");
    require(m.r32(metadata + 0x144u) == ordinal,
            "B406 allocation ordinal must match live-allocation count");
    const auto head = metadata + 0x33cu;
    const auto node = m.r32(head + 4u);
    require(node == arena + 0x0cu && m.r32(head + 8u) == arena + 0x700cu,
            "B406 requires unchanged class-63 list endpoints");
    const auto consumed = ordinal * 0x20u;
    const auto before = 0x0ff0u - consumed;
    require(m.r32(node) == before && before >= 0x410u,
            "B406 requires the exact preceding request-16 residual");
    const auto after = before - 0x20u;
    require(((after >> 4u) - 1u) >= 63u,
            "B406 split must remain in the original class-63 branch");
    // Original 0x77398a same-class split; no list relink or free-counter update.
    m.w32(entry_esp + 4u, record);
    m.w32(0x00b10e0cu, record);
    m.w32(node, after);
    m.w32(node + after - 4u, after);
    const auto allocated = node + after;
    m.w32(allocated, 0x21u);
    m.w32(allocated + 0x1cu, 0x21u);
    m.w32(metadata + 0x144u, ordinal + 1u);
    m.w32(metadata, 0u);
    return allocated + 4u;
}
} // namespace ra2::recovery_b406
