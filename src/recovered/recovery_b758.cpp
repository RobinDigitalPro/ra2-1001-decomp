#include "recovery_b758.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b758 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
}

// Positive one-record cache cleanup route from 0x5d4fe0. The surrounding
// formatter and replacement branches remain outside this finite projection.
std::uint32_t fun_005d4fe0(Memory& m, const Inputs&, ra2::platform::ordinary_heap::Heap& heap) {
    const auto count = m.r32(0x00a1e128u);
    require(count == 1u, "B758 scope is one original cache record");
    const auto entries = m.r32(0x00a1e11cu);
    require(entries != 0u, "B758 needs the original cache-entry table");
    const auto record = m.r32(entries);
    require(record != 0u, "B758 cache slot zero must be populated");

    // 5d4ffd..5005 selects the record. 27f!=0 takes the branch at 5013 to
    // 50d4; 1fc==0 and 207!=0 then reach the owned-buffer cleanup at 50e0.
    require(m.r8(record + 0x27fu) != 0u, "B758 requires 0x5d5013 branch");
    require(m.r8(record + 0x1fcu) == 0u, "B758 excludes the formatter branch");
    require(m.r8(record + 0x207u) != 0u, "B758 requires cleanup-enable byte");
    const auto owned = m.r32(record + 0xa4u);
    require(owned != 0u && m.r8(record + 0xa8u) != 0u,
            "B758 requires a live owned cache buffer");

    // Original call 0x5d50f3 -> accepted 0x36d67b/HeapFree. The helper result
    // is overwritten at 0x5d5107 by the one-entry count before RET.
    (void)heap.release(owned);
    m.w32(record + 0xa4u, 0u);
    m.w8(record + 0xa8u, 0u);
    return m.r32(0x00a1e128u);
}
}
