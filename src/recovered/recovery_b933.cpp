#include "recovered/recovery_b933.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <stdexcept>
#include <initializer_list>

namespace ra2::recovered::recovery_b933 {
std::uint32_t fun_00443AF0(Memory& m, const Inputs& i) {
    const std::uint32_t owner = i.cx;
    const std::uint32_t index = i.arg[0];
    const std::uint32_t vtable = m.r32(owner);
    const std::uint32_t type = m.r32(owner + 0x418u);
    const std::uint32_t config = m.r32(0x821b88u);
    if (vtable != 0x787bbcu || m.r32(vtable + 0x84u) != 0x4538b0u || !type || !config)
        throw std::domain_error("B933 authentic getter/config route required");
    if (index > 4u || m.r32(owner + 0x42cu) != 0xffffffffu || m.r32(0x00a283c4u) == 0)
        throw std::domain_error("B933 bounded index/sentinel/global route required");
    const std::uint32_t denominator = m.r32(type + 0xa0u);
    const std::uint32_t numerator = m.r32(owner + 0x6cu);
    if (!denominator || denominator > 0x7fffffffu || !numerator || numerator > 0x7fffffffu)
        throw std::domain_error("B933 finite positive integer ratio required");
    if (m.r8(type + 0xaeeu) != 0)
        throw std::domain_error("B933 optional release callback excluded");
    const std::uint32_t record = type + 0xc8cu + index * 12u;
    const bool owner_positive = static_cast<std::int32_t>(m.r32(owner + 0x564u)) > 0;
    for (const std::uint32_t off : {0x1158u, 0x1168u, 0x1178u,
                                    0x0da0u, 0x0db0u, 0x0dc0u,
                                    0x0de4u, 0x0df4u, 0x0e04u,
                                    0x0e28u, 0x0e38u, 0x0e48u,
                                    0x0e6cu, 0x0e7cu, 0x0e8cu}) {
        if (m.r8(type + off) != 0)
            throw std::domain_error("B933 presentation callback names must be empty");
    }

    const std::uint64_t threshold = std::uint64_t(m.r32(config + 0x1368u)) |
                                    (std::uint64_t(m.r32(config + 0x136cu)) << 32u);
    for (unsigned n = 0; n < 5; ++n) {
        i.fp.load_integer32(numerator);
        const std::uint64_t dividend = i.fp.pop64();
        i.fp.load_integer32(denominator);
        ra2::platform::x87_scalar_b46::reverse_divide64(i.fp, dividend);
        i.fp.compare_pop64(threshold);
        const auto status = i.fp.status();
        // The original tests FNSTSW AX followed by TEST AH,0x41 (C0|C3).
        const bool less_or_equal = (status & 0x4100u) != 0;
        (void)less_or_equal; // Selects among the three verified empty label slots.
        i.arg[0] = (i.arg[0] & 0xffffff00u) | (owner_positive ? 1u : 0u);
    }

    // Each block stores SETG(owner+0x564) into the low byte of the caller's
    // first stack word. The same location was overwritten five times above.
    const std::uint32_t record_first = m.r32(record);
    const std::uint32_t result = m.r32(record + 8u);
    m.w32(owner + 0x430u, 0xffffffffu);
    m.w32(owner + 0x42cu, index);
    m.w32(owner + 0xf0u, result);
    m.w32(owner + 0xe4u, m.r32(0x00a2896cu));
    m.w32(owner + 0xe8u, i.stack_minus8);
    m.w32(owner + 0xecu, result);
    m.w32(owner + 0xe0u, record_first);
    return result;
}
}
