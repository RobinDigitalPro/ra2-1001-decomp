#include "recovery_b704.hpp"
#include "platform/small_crt_heap_algorithm.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b704 {
namespace {
void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

// Exact positive 0x3739DC route: table count is below capacity, so the
// original allocates a zeroed 0x41c4 metadata block and reserves one 1 MiB
// arena. The count==capacity HeapReAlloc and all API-failure exits are excluded.
std::uint32_t fun_007739dc(Memory& m, Inputs& i, Heap& api) {
    const auto count = api.r32(0xb10e14u);
    const auto capacity = api.r32(0xb10e04u);
    require(count < capacity, "B704 3739DC requires spare region-table capacity");
    const auto result = ra2::platform::small_crt_heap::fun_007739dc_create_region(api, api);
    (void)i; // no caller stack arguments or argument words are touched by this body
    return result;
}

// Exact positive 0x373A8D route for the first available chunk in an existing
// region. The record must be a genuine table record initialized by 0x3739DC;
// one chunk is committed and the original returns index zero. Other bitmaps,
// failed VirtualAlloc, and later chunk selection are outside this contract.
std::uint32_t fun_00773a8d(Memory& m, Inputs& i, Heap& api) {
    const auto record = i.arg[0];
    require(record == api.r32(0xb10e18u), "B704 373A8D requires the first genuine region record");
    require(api.r32(record + 0x08u) == 0xffffffffu,
            "B704 373A8D requires the first-chunk availability bitmap");
    return ra2::platform::small_crt_heap::fun_00773a8d_commit_first_available_chunk(api, api, record);
}
}
