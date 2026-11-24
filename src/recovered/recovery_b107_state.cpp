#include "recovered/recovery_b107.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b107 {

std::uint32_t fun_00451610(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    const auto cfg = m.r32(receiver + 0x418u);
    const auto gate = m.r32(cfg + 0x1390u);
    if (floating_b61::s32(gate) > 0) return gate;

    if (m.r8(cfg + 0x0addu) != 0) {
        const auto selected = m.r8(receiver + 0x1fcu) != 0
            ? cfg + 0x0adfu : cfg + 0x0adeu;
        return floating_b61::sx8(m.r8(selected));
    }

    if (m.r8(cfg + 0x1362u) != 0 || m.r8(cfg + 0x1361u) != 0)
        return floating_b61::sx8(m.r8(cfg + 0x138bu));

    throw std::domain_error("Block107 0x51610 helper-dispatch route is outside the bounded contract");
}

std::uint32_t fun_00564f30(Memory& m, const Inputs& i) {
    const auto point = i.arg[0];
    const auto divisor = m.r32(0x00a57848u);
    if (floating_b61::s32(divisor) <= 0) throw std::domain_error("Block107 0x164f30 requires a positive signed divisor");
    const auto z = floating_b61::s32(m.r32(point + 8u));
    const auto quotient = z / floating_b61::s32(divisor);
    if (quotient < 0 || quotient > 10 || (quotient & 1) != 0)
        throw std::domain_error("Block107 0x164f30 quotient is outside the even bounded route");

    const auto x = floating_b61::s32(m.r32(point));
    const auto y = floating_b61::s32(m.r32(point + 4u));
    if (x < 0 || y < 0) throw std::domain_error("Block107 0x164f30 negative coordinates are outside the bounded route");

    // The original adds the sign correction before SAR 8, matching signed
    // division by 256 truncated toward zero for the bounded signed inputs.
    const auto x_cell = (x / 256) - (quotient / 2);
    const auto y_cell = (y / 256) - (quotient / 2);
    if (x_cell < -32768 || x_cell > 32767 || y_cell < -32768 || y_cell > 32767)
        throw std::domain_error("Block107 0x164f30 cell coordinate does not fit the observed WORD fields");

    const auto index = std::int64_t(y_cell) * 512 + x_cell;
    if (index < 0 || index >= 0x40000)
        throw std::domain_error("Block107 0x164f30 cell index is outside the observed table bounds");

    const auto cell = m.r32(m.r32(0x81a958u) + std::uint32_t(index) * 4u);
    if (!cell) throw std::domain_error("Block107 0x164f30 null-cell fallback route is outside the bounded contract");

    // MOV WORD [S+4],DX and MOV WORD [S+6],AX replace the caller's pointer
    // argument with the two signed cell coordinates.
    i.arg[0] = std::uint32_t(std::uint16_t(x_cell)) |
               (std::uint32_t(std::uint16_t(y_cell)) << 16);
    const auto flag = m.r8(cell + 0x12cu);
    return (cell & 0xffffff00u) | ((flag & 8u) == 0 ? 1u : 0u);
}

std::uint32_t fun_00692d30(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    if (m.r8(receiver + 0x55u) == 0)
        throw std::domain_error("Block107 0x292d30 inactive receiver route is outside the bounded contract");
    if ((i.arg[0] & 0xffu) != 0)
        throw std::domain_error("Block107 0x292d30 nonzero event dispatch route is outside the bounded contract");

    const auto tick = m.r32(0x00a2896cu);
    m.w8(receiver + 0x57u, 1u);
    m.w32(receiver + 0x2cu, tick);
    m.w32(receiver + 0x30u, i.stack_minus8);
    m.w32(receiver + 0x34u, 0u);

    const auto object = m.r32(receiver + 0x24u);
    const auto byte = m.r8(object + 0xddu);
    if (byte != 0) m.w32(receiver + 0x60u, 1u);
    return (tick & 0xffffff00u) | byte;
}

} // namespace ra2::recovered::recovery_b107
