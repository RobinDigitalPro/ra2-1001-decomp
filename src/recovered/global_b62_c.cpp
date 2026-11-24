#include "recovered/global_b62_c.hpp"

namespace ra2::recovered::global_b26 {
namespace {

// The original 0x4068f0 target is a one-byte RET. A CALL followed by this RET
// preserves every register, including the complete EAX value. These recovered
// callers therefore leave the diagnostic call as an explicit no-op boundary;
// they must not use the separate C++ stub that returns zero.
inline void diagnostic_ret_boundary() noexcept {}

inline std::uint32_t rol1_plus(std::uint32_t value, std::uint32_t addend) {
    // Exact helper sequence at 0x621b70: (value << 1) + (value >> 31) + addend.
    return (value << 1u) + (value >> 31u) + addend;
}

} // namespace

std::uint32_t fun_004b5f00(Memory& m, const Inputs& i) {
    const auto object = i.cx;
    diagnostic_ret_boundary();

    const auto size = i.arg[0];
    if (s32(size) < 0) {
        m.w8(object + 0x02u, 0xffu);
        m.w8(object, 0u);
        const auto global = m.r32(0x00a2896cu);
        m.w32(object + 0x03u, global);
        return object;
    }

    m.w8(object + 0x02u, size);
    m.w8(object, 5u);
    m.w32(object + 0x07u, i.arg[1]);
    m.w8(object + 0x0bu, i.arg[2]);
    m.w8(object + 0x0cu, i.arg[3]);
    m.w32(object + 0x0du, i.arg[4]);
    m.w8(object + 0x11u, i.arg[5]);
    m.w32(object + 0x12u, i.arg[6]);
    m.w32(object + 0x1bu, i.arg[9]);
    m.w8(object + 0x16u, i.arg[7]);
    m.w32(object + 0x17u, i.arg[8]);
    const auto global = m.r32(0x00a2896cu);
    m.w32(object + 0x03u, global);
    return object;
}

std::uint32_t fun_0072a090(Memory& m, const Inputs& i) {
    const auto object = i.cx;
    const auto flags = i.arg[0]; // EBX after PUSH EBX; the RET helper preserves EAX.
    auto eax = i.ax;

    if (flags != 0u) {
        if ((flags & 0x08u) != 0u) {
            diagnostic_ret_boundary();
            eax = m.r32(object + 0x04u) + 1u;
            m.w32(object + 0x04u, eax);
        }
        if ((flags & 0x10u) != 0u) diagnostic_ret_boundary();
        if ((flags & 0x00000400u) != 0u) {
            diagnostic_ret_boundary();
            eax = m.r32(object + 0x08u) + 1u;
            m.w32(object + 0x08u, eax);
        }
        if ((flags & 0x02u) != 0u) {
            diagnostic_ret_boundary();
            eax = m.r32(object + 0x0cu) + 1u;
            m.w32(object + 0x0cu, eax);
        }
        if ((flags & 0x01u) != 0u) {
            diagnostic_ret_boundary();
            eax = m.r32(object + 0x10u) + 1u;
            m.w32(object + 0x10u, eax);
        }
        if ((flags & 0x04u) != 0u) {
            diagnostic_ret_boundary();
            eax = m.r32(object + 0x14u) + 1u;
            m.w32(object + 0x14u, eax);
        }
        if ((flags & 0x00000100u) != 0u) {
            diagnostic_ret_boundary();
            eax = m.r32(object + 0x18u) + 1u;
            m.w32(object + 0x18u, eax);
        }
    }

    // At 0x72a148 BL is reloaded from the low byte of the second stack word.
    // These final six branches only call the RET stub and therefore preserve EAX.
    const auto detail = i.arg[1] & 0xffu;
    if ((detail & 0x01u) != 0u) diagnostic_ret_boundary();
    if ((detail & 0x02u) != 0u) diagnostic_ret_boundary();
    if ((detail & 0x04u) != 0u) diagnostic_ret_boundary();
    if ((detail & 0x08u) != 0u) diagnostic_ret_boundary();
    if ((detail & 0x10u) != 0u) diagnostic_ret_boundary();
    if ((detail & 0x20u) != 0u) diagnostic_ret_boundary();
    if ((detail & 0x40u) != 0u) diagnostic_ret_boundary();
    return eax;
}

std::uint32_t fun_00756db0(Memory& m, const Inputs& i) {
    const auto object = i.cx;
    const auto zero = 0u;

    m.w32(object + 0x0cu, zero);
    m.w32(object + 0x10u, zero);
    m.w8(object + 0x14u, 1u);
    m.w8(object + 0x15u, zero);
    m.w32(object + 0x08u, 0x0079a914u);
    m.w32(object + 0x1cu, 0x0au);
    m.w32(object + 0x18u, zero);
    m.w32(object + 0x24u, zero);
    m.w32(object + 0x28u, zero);
    m.w8(object + 0x2cu, 1u);
    m.w8(object + 0x2du, zero);
    m.w32(object + 0x20u, 0x0079a914u);
    m.w32(object + 0x34u, 0x0au);
    m.w32(object + 0x30u, zero);
    m.w32(object + 0x4cu, 0x0au);
    m.w32(object + 0x3cu, zero);
    m.w32(object + 0x40u, zero);
    m.w8(object + 0x44u, 1u);
    m.w8(object + 0x45u, zero);
    m.w32(object + 0x38u, 0x0079a914u);
    m.w32(object + 0x48u, zero);
    m.w32(object + 0x4386cu, 0xffffffffu);
    m.w32(object + 0x43870u, 0xffffffffu);
    m.w32(object, 0x0079a8b4u);
    m.w8(object + 0x43868u, zero);

    // Preserve the original loop's interleaved write order and exact byte offsets.
    auto p = object + 0x96u;
    for (std::uint32_t n = 0; n != 0x80u; ++n) {
        m.w8(p - 1u, zero);
        m.w8(p, zero);
        m.w8(p + 0x167ffu, zero);
        m.w8(p + 0x16800u, zero);
        m.w8(p + 0x16801u, zero);
        m.w8(p + 0x16802u, zero);
        m.w8(p + 0x2cfffu, zero);
        m.w8(p + 0x2d000u, zero);
        m.w8(p + 0x2d001u, 1u);
        m.w8(p + 0x2d002u, zero);
        p += 0x2d0u;
    }

    m.w32(object + 0x4385cu, zero);
    m.w32(object + 0x43860u, zero);
    m.w32(object + 0x43864u, zero);
    m.w32(object + 0x43850u, zero);
    m.w32(object + 0x43854u, zero);
    m.w32(object + 0x04u, 0x240u);
    diagnostic_ret_boundary();
    return object;
}

std::uint32_t fun_00757430(Memory& m, const Inputs& i) {
    const auto object = i.arg[0];
    const auto length = m.r32(object + 0x40u);
    if (s32(length) >= 0x280) {
        // XOR AL,AL after EAX was loaded with length: upper 24 bits survive.
        return length & 0xffffff00u;
    }

    const auto signed_length = s32(length);
    const auto word_count = sar(std::uint32_t(signed_length + (signed_length < 0 ? 3 : 0)), 2u);
    auto accumulator = 0u;
    i.arg[0] = accumulator; // MOV [ESP+0x10],EDI overwrites the incoming stack argument.
    auto cursor = object + 0x50u;

    if (s32(word_count) > 0) {
        for (std::uint32_t n = 0; n < word_count; ++n) {
            const auto value = m.r32(cursor);
            cursor += 4u;
            accumulator = rol1_plus(accumulator, value);
            i.arg[0] = accumulator;
        }
    }

    const auto remainder = length & 3u;
    if (remainder != 0u) {
        const auto shift = 32u - (remainder << 3u);
        const auto mask = 0xffffffffu >> shift;
        const auto value = m.r32(cursor);
        const auto partial = value & mask;
        accumulator = rol1_plus(accumulator, partial);
        i.arg[0] = accumulator;
    }

    const auto expected = m.r32(object + 0x4cu);
    if (i.arg[0] == expected) {
        return (expected & 0xffffff00u) | 1u; // MOV AL,1 preserves the loaded checksum's upper bytes.
    }

    diagnostic_ret_boundary();
    return expected & 0xffffff00u; // XOR AL,AL preserves the loaded checksum's upper bytes.
}

std::uint32_t fun_00625d50(Memory& m, const Inputs& i) {
    const auto object = i.cx;
    diagnostic_ret_boundary();
    diagnostic_ret_boundary();

    const auto selector = m.r8(object);
    const auto selected = m.r32(0x007c16fcu + selector * 4u);
    diagnostic_ret_boundary();
    (void)selected;

    const auto field_dword = m.r32(object + 0x03u);
    diagnostic_ret_boundary();

    const auto signed_byte = m.r8(object + 0x02u);
    const auto sign_extended = (signed_byte & 0x80u) ? (signed_byte | 0xffffff00u) : signed_byte;
    diagnostic_ret_boundary();

    const auto global_1 = m.r32(0x00a25890u);
    (void)global_1;
    diagnostic_ret_boundary();
    const auto global_2 = m.r32(0x00a2896cu);
    (void)global_2;
    diagnostic_ret_boundary();
    const auto result = m.r32(0x00a25894u);
    diagnostic_ret_boundary();

    // Keep the loads explicit: the intervening diagnostics preserve EAX, while
    // the final caller-visible value is the last global dword loaded above.
    (void)field_dword;
    (void)sign_extended;
    (void)i;
    return result;
}

} // namespace ra2::recovered::global_b26
