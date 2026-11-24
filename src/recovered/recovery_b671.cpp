#include "recovery_b671.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <stdexcept>

namespace ra2::recovered::allocation671 {
std::uint32_t fun_0060d400(Memory& m, Inputs& i, Heap& heap) {
    constexpr std::uint32_t request = 0x9cu;
    const auto receiver = i.cx;
    const auto object = heap.allocate(request);
    if (!object) throw std::domain_error("B671 excludes the original allocation-failure branch");

    // The returned first-block bytes are zero from the actual VirtualAlloc
    // commit; preserve untouched object bytes and execute the root's stores in
    // original order.
    heap.w32(object + 0x08u, 0u);
    heap.w32(object + 0x0cu, 0u);
    heap.w8(object + 0x10u, 1u);
    heap.w8(object + 0x11u, 0u);
    heap.w32(object + 0x04u, 0x007931dcu);
    heap.w32(object + 0x18u, 0x0au);
    heap.w32(object + 0x14u, 0u);
    heap.w8(object + 0x1cu, 0u);
    heap.w8(object + 0x1du, 0u);
    heap.w32(object + 0x8cu, 0xffffffffu);
    heap.w32(object + 0x90u, 0xffffffffu);
    heap.w32(object + 0x94u, 0xffffffffu);
    heap.w8(object + 0x98u, 0u);
    heap.w8(object + 0x99u, 0u);
    heap.w32(object, receiver);

    const auto capacity = m.r32(0x00a5e298u);
    const auto old_count = m.r32(0x00a5e2a0u);
    if (global_b26::s32(old_count) < 0 || global_b26::s32(capacity) < 0 ||
        global_b26::s32(old_count) >= global_b26::s32(capacity))
        throw std::domain_error("B671 bounded route requires spare A5E2 table capacity");
    const auto table = m.r32(0x00a5e294u);
    if (!table) throw std::domain_error("B671 positive route requires initialized table storage");

    auto flags = i.arithmetic_flags;
    flags = direct_b33::integer::logical(0u, 32u, flags); // XOR ECX,ECX
    (void)direct_b33::integer::sub(old_count, capacity, 32u, flags); // CMP EDX,EAX
    const auto new_count = direct_b33::integer::increment(old_count, 32u, flags); // INC ECX
    m.w32(0x00a5e2a0u, new_count);
    m.w32(table + old_count * 4u, object);

    // Exact accepted 0x2C6990 body, inlined at its verified boundary:
    // MOV EAX,[ESP+4]; MOV [ECX+408],EAX; RET 4.
    m.w32(receiver + 0x408u, object);

    i.ax = object;
    i.cx = receiver;
    i.dx = old_count;
    i.arithmetic_flags = flags;
    return object;
}
}
