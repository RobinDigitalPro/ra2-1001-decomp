#include "recovery_b369.hpp"
#include "recovered/recovery_b238.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b369 {

std::uint32_t fun_004751d0(Memory& m, const Inputs& root) {
    const std::uint32_t receiver = root.cx;
    const std::uint32_t index = m.r32(receiver + 0x38u);
    if (index == 0xffffu) throw std::domain_error("751d0 draft requires a selected-record index");

    const std::uint32_t table = m.r32(0x00a28914u);
    const std::uint32_t selected = m.r32(table + index * 4u);
    if (m.r32(selected + 0x2c0u) != 1u) throw std::domain_error("751d0 draft requires selected count one");
    if (m.r8(selected + 0x2b1u) == 0) throw std::domain_error("751d0 draft requires the selected flag");

    const std::int32_t height = static_cast<std::int8_t>(m.r8(receiver + 0x11bu));
    const std::uint32_t point = root.arg[0];
    const std::uint32_t rect = root.arg[1];
    const std::uint32_t x = m.r32(point);
    const std::uint32_t y = m.r32(point + 4u);
    const std::uint32_t scaled_height = static_cast<std::uint32_t>(height) * 15u;

    // 751d0's five pushes and 16-byte local rectangle become args 0..8
    // at 1299d0. The first pushed value is the computed 0x3a - 15*h word.
    Inputs child{};
    child.ax = y - scaled_height;
    child.cx = selected;
    child.dx = m.r32(0x00821c9cu);
    child.fp = root.fp;
    child.arithmetic_flags = root.arithmetic_flags;
    child.arg[0] = m.r8(receiver + 0x11au);
    child.arg[1] = m.r32(0x00821c9cu);
    child.arg[2] = x;
    child.arg[3] = y - scaled_height;
    child.arg[4] = m.r32(rect);
    child.arg[5] = m.r32(rect + 4u);
    child.arg[6] = m.r32(rect + 8u);
    child.arg[7] = m.r32(rect + 12u);
    child.arg[8] = 0x3au - scaled_height;

    const auto result = recovery_b238::fun_005299d0(m, child);
    // B238 models the same live x87 state and exposes its post-call image
    // through its mutable FP field. Its nested stack words belong to this
    // root's private call frame, so child.arg is intentionally not copied back.
    root.fp = child.fp;
    return result;
}

}
