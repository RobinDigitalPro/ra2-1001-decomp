#include "recovered/recovery_b145.hpp"

#include "recovered/recovery_b145_lookup.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b145 {
using namespace global_b26;

namespace {
std::uint32_t lookup_two_row(Memory& memory, std::uint32_t key) {
    // Caller-bounded table-present/count-two version of 0x6eeb60 ->
    // 0x76d965 -> 0x76d860. The first row is the first midpoint; if it is
    // greater than the query, the original search misses. Otherwise it checks
    // row 1. This only returns real table values on a hit.
    const auto table = memory.r32(0x00ab7ec0u);
    if (table == 0u || memory.r32(0x00ab7eb8u) != 2u)
        throw std::domain_error("321db0 fixture requires the actual two-row text table");
    Inputs compare{};
    compare.arg[0] = key;
    compare.arg[1] = table;
    auto row = table;
    auto relation = global_b26::s32(lookup::fun_0076d860(memory, compare));
    if (relation != 0) {
        if (relation < 0)
            throw std::domain_error("321db0 query is outside the positive two-row hit path");
        compare.arg[1] = table + 0x28u;
        row += 0x28u;
        relation = global_b26::s32(lookup::fun_0076d860(memory, compare));
        if (relation != 0)
            throw std::domain_error("321db0 query is outside the positive two-row hit path");
    }
    const auto index = memory.r32(row + 0x24u);
    if (index > 1u)
        throw std::domain_error("321db0 text-table index outside selected 0..1 range");
    return memory.r32(memory.r32(0x00ab7ec4u) + index * 4u);
}

std::uint32_t clone_wide(Memory& memory, Heap& heap, std::uint32_t output_cell,
                         std::uint32_t source) {
    // This is the reached non-null-source path from original VA 0x75b300:
    // wcslen, operator new((length+1)*2), publish, then copy through the NUL.
    memory.w32(output_cell, 0);
    std::uint32_t length = 0;
    while (memory.r16(source + length * 2u) != 0u) ++length;
    const auto bytes = (length + 1u) * 2u;
    const auto destination = heap.allocate(bytes);
    memory.w32(output_cell, destination);
    heap.w8(destination, 0u);
    heap.w8(destination + 1u, 0u);
    for (std::uint32_t n = 0; n <= length; ++n) {
        const auto unit = memory.r16(source + n * 2u);
        heap.w8(destination + n * 2u, static_cast<std::uint8_t>(unit));
        heap.w8(destination + n * 2u + 1u, static_cast<std::uint8_t>(unit >> 8));
    }
    return output_cell;
}
}

std::uint32_t fun_00721db0(Memory& memory, const Inputs& input, Heap& heap) {
    const auto receiver = input.cx;
    const auto member = memory.r32(input.arg[0] + 4u);
    const auto child = receiver + 8u;

    memory.w32(receiver + 4u, 0u);
    memory.w32(receiver, 0x00793cd4u);
    memory.w32(child + 4u, 0u);
    memory.w32(child, 0x00793cccu);

    // The original stores this vptr before the accepted setter. Its old child
    // is zero from the constructor, so the setter performs only the real +4
    // refcount increment and pointer store; it reaches no virtual release.
    memory.w32(child, 0x0079a034u);
    if (member != 0u) memory.w32(member + 4u, memory.r32(member + 4u) + 1u);
    memory.w32(child + 4u, member);

    const auto first_text = lookup_two_row(memory, memory.r32(member + 8u));
    (void)clone_wide(memory, heap, receiver + 0x10u, first_text);

    const auto second_text = lookup_two_row(memory, memory.r32(member + 0x0cu));
    (void)clone_wide(memory, heap, receiver + 0x14u, second_text);

    memory.w32(receiver, 0x0079a1dcu);
    return receiver;
}
}
