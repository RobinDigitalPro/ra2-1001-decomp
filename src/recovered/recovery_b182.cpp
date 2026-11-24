#include "recovery_b182.hpp"
// Block182: documented finite constructor/registration route.
#include "recovered/construct_b101.hpp"
#include "recovered/global_b26_memory.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b182 {
using global_b26::Inputs;
using global_b26::Memory;

namespace {
void append_spare(Memory& m, std::uint32_t count_cell,
                  std::uint32_t capacity_cell, std::uint32_t table_cell,
                  std::uint32_t object) {
    const auto capacity = m.r32(capacity_cell);
    const auto count = m.r32(count_cell);
    // The selected original branch is the direct spare-capacity branch.  It
    // increments the global count before loading and writing the old slot.
    if (global_b26::s32(count) < 0 || global_b26::s32(capacity) < 0 ||
        global_b26::s32(count) >= global_b26::s32(capacity))
        throw std::domain_error("Block182 only models original spare-capacity append");
    m.w32(count_cell, count + 1u);
    const auto table = m.r32(table_cell);
    m.w32(table + count * 4u, object);
}

void call_authentic_clear_slot(Memory& m, std::uint32_t subobject) {
    // The constructor installs this authentic vptr immediately before the
    // original CALL [EAX+0x0c].  Pin the dispatch rather than injecting a
    // fixture callback.  Entry +4 and +0x0d are zero, so RVA 0xd4250 takes its
    // original no-release branch and only clears +0x10, +0x0d, and +8.
    const auto vtable = m.r32(subobject);
    if (vtable != 0x0078d2a4u || m.r32(vtable + 0x0cu) != 0x004d4250u)
        throw std::domain_error("Block182 vtable/no-owned-pointer precondition");
    const auto owned_pointer = m.r32(subobject + 4u);
    m.w32(subobject + 0x10u, 0);
    if (owned_pointer != 0)
        throw std::domain_error("Block182 target 0xd4250 release branch excluded");
    m.w8(subobject + 0x0du, 0);
    m.w32(subobject + 8u, 0);
}
} // namespace

std::uint32_t fun_00602910(Memory& m, const Inputs& i) {
    const auto c = i.cx;
    Inputs base{};
    base.cx = c;
    (void)ra2::recovered::construct_b101::fun_005ca970(m, base);

    m.w32(c + 0x98u, 0);
    const auto child = c + 0xa8u;
    m.w32(child + 4u, 0);
    m.w32(child + 8u, 0);
    m.w8(child + 0x0cu, 1);
    m.w8(child + 0x0du, 0);
    m.w32(child, 0x0078d2a4u);
    m.w32(child + 0x14u, 10);
    m.w32(child + 0x10u, 0);

    m.w32(c + 0xc0u, m.r32(0x00a5e0c0u));
    m.w32(c + 0xc4u, m.r32(0x00a5e0c4u));
    const auto copied_c8 = m.r32(0x00a5e0c8u);
    m.w32(c + 0xccu, 0);
    m.w32(c + 0xd0u, 0);
    m.w32(c + 0xc8u, copied_c8);
    m.w32(c + 0xd4u, 0);
    m.w32(c + 0xd8u, 0);
    m.w32(c + 0xdcu, 0);
    m.w32(c + 0xe0u, 0);
    m.w8(c + 0xe4u, 0);
    m.w8(c + 0xe5u, 0);

    m.w32(c, 0x00792f4cu);
    m.w32(c + 4u, 0x00792f30u);
    m.w32(c + 8u, 0x00792f28u);
    m.w32(c + 0x0cu, 0x00792f20u);
    call_authentic_clear_slot(m, child);

    append_spare(m, 0x00a1a5c0u, 0x00a1a5b8u, 0x00a1a5b4u, c);
    append_spare(m, 0x00aa8878u, 0x00aa8870u, 0x00aa886cu, c);
    return c;
}
} // namespace ra2::recovered::recovery_b182
