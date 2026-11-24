#include "recovery_b735.hpp"
#include <stdexcept>

namespace ra2::recovered::alloc735 {
std::uint32_t fun_005fb640(Memory& m, Inputs& i, Heap& heap) {
    const auto wrapper = m.r32(0x00a5df68u);
    if (wrapper == 0) throw std::domain_error("B735 contract requires the root's warm wrapper state");
    const auto object = heap.allocate(0x100u);
    if (object == 0) throw std::domain_error("B735 positive route excludes allocation failure");
    const auto source = i.cx;
    const auto triple = i.dx;
    std::uint32_t length = 0;
    while (length < 0x100u && m.r8(source + length) != 0) ++length;
    if (length == 0x100u) throw std::domain_error("B735 fixture string must terminate within request size");
    for (std::uint32_t k = 0; k <= length; ++k) heap.w8(object + k, m.r8(source + k));

    const auto first = m.r32(wrapper + 4u);
    const auto first_capacity = m.r32(first + 8u), first_count = m.r32(first + 0x10u);
    if (!first || first_count >= first_capacity) throw std::domain_error("B735 first list requires spare capacity");
    m.w32(first + 0x10u, first_count + 1u);
    m.w32(m.r32(first + 4u) + first_count * 4u, object);

    const auto second = m.r32(wrapper + 8u);
    const auto second_capacity = m.r32(second + 8u), second_count = m.r32(second + 0x10u);
    if (!second || second_count >= second_capacity) throw std::domain_error("B735 second list requires spare capacity");
    const auto out = m.r32(second + 4u) + second_count * 3u;
    m.w32(second + 0x10u, second_count + 1u);
    m.w8(out, m.r8(triple)); m.w8(out + 1u, m.r8(triple + 1u)); m.w8(out + 2u, m.r8(triple + 2u));
    const auto eax = (triple & 0xffffff00u) | m.r8(triple + 2u);
    i.ax = eax;
    return eax;
}
}
