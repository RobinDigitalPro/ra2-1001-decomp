#include "recovery_b129.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b129 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

// The five vtables resolve their +0xc slot to the corresponding original
// cleanup targets documented in copy129_closure.json. Those 39-byte bodies
// all have the same reached semantics. The entry has just zeroed this+4 and
// byte this+0xd, so each actual target skips its conditional free, clears
// byte this+0xd, and clears this+8.
void reached_empty_cleanup(Memory& m, const Inputs& i, Heap& heap,
                           std::uint32_t object) {
    const auto buffer = m.r32(object + 4u);
    if (buffer != 0u && m.r8(object + 0x0du) != 0u) {
        (void)heap.release(buffer);
        m.w32(object + 4u, 0u);
    }
    m.w8(object + 0x0du, 0u);
    m.w32(object + 8u, 0u);
    (void)i; // Entry-reachable target path has no stack arguments.
}

std::uint32_t assign_copy(Memory& m, const Inputs& i, Heap& heap,
                          std::uint32_t initial_vptr,
                          std::uint32_t final_vptr) {
    const auto destination = i.cx;
    const auto source = i.arg[0];
    require(destination != 0u && source != 0u,
            "copy129 requires nonnull destination and source");
    require(destination != source,
            "copy129 finite contract reaches original vtable target only for distinct objects");

    // Original prologue field writes and actual indirect target execution.
    m.w32(destination + 4u, 0u);
    m.w32(destination + 8u, 0u);
    m.w8(destination + 0x0cu, 1u);
    m.w8(destination + 0x0du, 0u);
    m.w32(destination, initial_vptr);
    reached_empty_cleanup(m, i, heap, destination);

    const auto count = m.r32(source + 8u);
    require(count >= 255u && count <= 287u,
            "copy129 finite contract requires positive count 255..287");
    const auto bytes = count * 4u;
    m.w32(destination + 8u, count);
    const auto allocation = heap.allocate(bytes); // original operator new 0x36d957
    if (!allocation)
        throw std::runtime_error("copy129 original success-only route requires nonnull operator-new result");
    m.w32(destination + 4u, allocation);
    m.w8(destination + 0x0du, 1u);

    const auto source_data = m.r32(source + 4u);
    require(source_data != 0u,
            "copy129 positive source count requires a valid source data pointer");
    for (std::uint32_t k = 0; k < count; ++k)
        heap.w32(allocation + 4u * k, m.r32(source_data + 4u * k));

    m.w32(destination + 0x10u, m.r32(source + 0x10u));
    m.w32(destination + 0x14u, m.r32(source + 0x14u));
    m.w32(destination, final_vptr);
    return destination; // POPs preserve EAX; original RET 4.
}
} // namespace

std::uint32_t fun_004f6430(Memory& m, const Inputs& i, Heap& h) {
    return assign_copy(m, i, h, 0x78dee4u, 0x78dfecu);
}
std::uint32_t fun_004faa30(Memory& m, const Inputs& i, Heap& h) {
    return assign_copy(m, i, h, 0x78e138u, 0x78e198u);
}
std::uint32_t fun_005a2ed0(Memory& m, const Inputs& i, Heap& h) {
    return assign_copy(m, i, h, 0x791898u, 0x7918b8u);
}
std::uint32_t fun_0064b730(Memory& m, const Inputs& i, Heap& h) {
    return assign_copy(m, i, h, 0x78e138u, 0x78e0d8u);
}
std::uint32_t fun_0064b8e0(Memory& m, const Inputs& i, Heap& h) {
    return assign_copy(m, i, h, 0x793fc0u, 0x79402cu);
}
} // namespace ra2::recovered::recovery_b129
