#include "recovered/recovery_b171.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b171 {

// Finite positive branch of original RVA 0x131650. Fixtures require every
// slot's timestamp=-1 / remaining=0 / period>0, so the real timer-update
// branch is taken and the later manager virtual call is skipped by value<threshold.
std::uint32_t fun_00531650(Memory& m, const Inputs& i) {
    const auto count = m.r32(0x00a562d8u);
    if (count == 0 || count > 8) throw std::domain_error("Block171 count must be 1..8");
    const auto list = m.r32(0x00a562ccu);
    if (!list) throw std::domain_error("Block171 requires mapped registry list");
    const auto now = m.r32(0x00a2896cu);
    std::uint32_t eax = 0;
    for (std::uint32_t remaining = count; remaining != 0; --remaining) {
        const auto object = m.r32(list + (remaining - 1u) * 4u);
        if (!object) throw std::domain_error("Block171 requires nonnull records");
        if (m.r32(object + 4u) != 0xffffffffu || m.r32(object + 0x0cu) != 0)
            throw std::domain_error("Block171 takes the exact expired timer branch");
        const auto period = m.r32(object + 0x10u);
        if (!period) throw std::domain_error("Block171 timer update requires nonzero period");
        const auto value = m.r32(object) + m.r32(object + 0x14u);
        m.w32(object, value);
        m.w32(object + 4u, now);
        m.w32(object + 8u, i.stack_minus8);
        m.w32(object + 0x0cu, period);

        if (m.r8(object + 0x4cu)) {
            const auto toggle = m.r8(object + 0x4du);
            m.w8(object + 0x4du, toggle == 0u ? 1u : 0u);
        }
        const auto threshold = m.r32(object + 0x48u);
        if (ra2::recovered::global_b26::s32(value) >= ra2::recovered::global_b26::s32(threshold))
            throw std::domain_error("Block171 excludes the manager-dispatch threshold route");
        eax = threshold; // final index-zero CMP leaves EAX equal to this threshold
    }
    return eax;
}
}
