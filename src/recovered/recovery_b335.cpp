#include "recovery_b335.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b335 {
std::uint32_t fun_0042c3d0(Memory& memory, const Inputs& input) {
    const auto collection = input.cx;
    const auto query = input.arg[0];
    if (collection == 0u || query == 0xffffffffu ||
        memory.r32(collection + 0x14u) != 2u)
        throw std::domain_error("B335 requires a two-entry positive search");

    const auto entries = memory.r32(collection + 0x08u);
    const auto first = entries;
    const auto second = entries + 0x10u;
    if (memory.r32(first) == query || memory.r32(second) != query ||
        memory.r32(second + 4u) != 0u)
        throw std::domain_error("B335 requires one skipped entry and the guarded match at index 1");

    const auto object_table = memory.r32(0x00a1e00cu);
    if (object_table == 0u)
        throw std::domain_error("B335 requires the mapped original object-table pointer");
    if (query >= 0x100u)
        throw std::domain_error("B335 lookup index exceeds the bounded object table");
    const auto object = memory.r32(object_table + query * 4u);
    if (object == 0u || memory.r8(object + 0x1215u) != 0u)
        throw std::domain_error("B335 requires the original 0x2c000 false-guard path");

    // Exact original nested path:
    // 0x42c3d0 calls 0x42c000 at index 1; 0x42c000 calls 0x42c0a0;
    // 0x42c0a0 sees row+4 == 0 and returns EAX=0 before its indirect call.
    // 0x42c000 then sees object+0x1215 == 0 and returns AL=0 before 0x713b0.
    // The outer search consequently returns the matching index, full EAX=1.
    return 1u;
}
}
