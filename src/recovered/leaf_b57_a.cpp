#include "leaf_b57_a.hpp"

namespace ra2::recovered::leaf {

// RVA 0x157280. Cursor fields are raw 32-bit values; arithmetic wraps as x86.
// The saved pointer is deliberately read before returning in either branch.
std::uint32_t fun_00557280(Memory& m, const Inputs& i) {
    const std::uint32_t p = i.cx;
    const std::uint32_t count = m.r32(p + 0x110u);
    const std::uint32_t old_data = m.r32(p + 0x114u);
    if (count != 0) {
        const std::uint32_t begin = m.r32(p + 0x108u) + 1u;
        const std::uint32_t end = m.r32(p + 0x10cu) - 1u;
        m.w32(p + 0x108u, begin);
        m.w32(p + 0x110u, count - 1u);
        m.w32(p + 0x10cu, end);
        m.w32(p + 0x114u, old_data - 0x7fcu);
        return m.r32(old_data);
    }

    std::uint32_t end = m.r32(p + 0x10cu);
    std::uint32_t begin = m.r32(p + 0x108u);
    std::uint32_t row = m.r32(p + 0xf0u);
    m.w32(p + 0x108u, end);
    m.w32(p + 0x10cu, begin);
    std::uint32_t span = end - row;
    std::uint32_t parity = span + begin - 1u;
    if (parity & 1u) {
        ++begin;
        --row;
        m.w32(p + 0x10cu, begin);
    } else {
        ++end;
        row -= 2u;
        m.w32(p + 0x108u, end);
    }
    m.w32(p + 0x110u, row);
    const std::uint32_t cell = (m.r32(p + 0x10cu) << 9) + m.r32(p + 0x108u);
    const std::uint32_t next = m.r32(p + 0x138u) + (cell << 2);
    m.w32(p + 0x114u, next);
    return m.r32(old_data);
}

static std::uint32_t floor_fixed_8(std::uint32_t v) {
    const std::uint32_t sign = (v & 0x80000000u) ? 0xffffffffu : 0u;
    return sar(v + (sign & 0xffu), 8);
}

// RVA 0x3199f0. Return is observed only in AL; a match writes +0x24.
std::uint32_t fun_007199f0(Memory& m, const Inputs& i) {
    const std::uint32_t object = i.cx;
    const std::int32_t count = s32(m.r32(object + 0x38u));
    if (count <= 0) return 0;
    const std::uint32_t points = m.r32(object + 0x2cu);
    const std::uint32_t wanted_x = floor_fixed_8(m.r32(i.arg[0]));
    const std::uint32_t wanted_y = floor_fixed_8(m.r32(i.arg[0] + 4u));
    for (std::int32_t n = 0; n < count; ++n) {
        const std::uint32_t entry = points + static_cast<std::uint32_t>(n) * 12u;
        const std::uint32_t x = floor_fixed_8(m.r32(entry));
        const std::uint32_t y = floor_fixed_8(m.r32(entry + 4u));
        if ((x & 0xffffu) == (wanted_x & 0xffffu) &&
            (y & 0xffffu) == (wanted_y & 0xffffu)) {
            m.w32(object + 0x24u, static_cast<std::uint32_t>(n));
            return 1u;
        }
    }
    return 0;
}

// RVA 0x365200. Output stores occur in order; the second lookup observes any
// aliasing write performed through the first output pointer.
std::uint32_t fun_00765200(Memory& m, const Inputs& i) {
    const std::uint32_t object = i.cx;
    const std::uint32_t table = m.r32(object + 0x760u);
    const std::uint32_t count = m.r16(object + 0x758u);
    std::uint32_t index = 0;
    if (count <= 1u) {
        index = count - 1u;
    } else {
        std::uint32_t interval = 1u;
        while (interval < count) {
            const std::uint32_t lower = m.r16(table + (interval - 1u) * 2u);
            if (s32(i.dx) < static_cast<std::int32_t>(lower)) {
                ++index;
                ++interval;
                continue;
            }
            const std::uint32_t upper = m.r16(table + interval * 2u);
            if (s32(i.dx) < static_cast<std::int32_t>(upper)) break;
            ++index;
            ++interval;
        }
        if (interval == count) index = count - 1u;
    }

    if (i.arg[0] != 0) m.w32(i.arg[0], m.r16(table + index * 2u));
    if (i.arg[1] != 0) {
        if (s32(index) < s32(count - 1u))
            m.w32(i.arg[1], m.r16(table + (index + 1u) * 2u) - 1u);
        else
            m.w32(i.arg[1], m.r32(object + 0x10u));
    }
    return index;
}

// RVA 0x3683b0. Table entries are masked/doubled; the positive-EDX special
// endpoint supplies EDX itself as the upper operand, without doubling it.
std::uint32_t fun_007683b0(Memory& m, const Inputs& i) {
    const std::uint32_t object = i.cx;
    const std::uint32_t count = m.r16(object + 0x714u);
    if (s32(count) <= 0) return 0;
    const std::uint32_t records = m.r32(object + 0x71cu);
    const std::uint32_t dimension = m.r32(object + 0x10u);
    const std::uint32_t table = m.r32(object + 0x764u);
    std::uint32_t maximum = 0;
    for (std::uint32_t n = 0; n < count; ++n) {
        const std::uint32_t record = records + n * 4u;
        const std::uint32_t left = m.r16(record);
        const std::uint32_t right = m.r16(record + 2u);
        std::uint32_t da, db;
        if (right == dimension - 1u && s32(i.dx) > 0) {
            db = (m.r32(table + left * 4u) & 0x0fffffffu) << 1;
            da = i.dx;
        } else {
            const std::uint32_t right_index = right + ((right == dimension - 1u) ? 0u : 1u);
            da = (m.r32(table + right_index * 4u) & 0x0fffffffu) << 1;
            db = (m.r32(table + left * 4u) & 0x0fffffffu) << 1;
        }
        const std::uint32_t difference = da - db;
        if (s32(difference) > s32(maximum)) maximum = difference;
    }
    return maximum;
}

// RVA 0x121600. abs(INT_MIN) remains 0x80000000 under the x86 sign-mask
// transform; comparisons and branch selection are signed.
std::uint32_t fun_00521600(Memory&, const Inputs& i) {
    const std::uint32_t a = i.arg[0], b = i.arg[1];
    if (a == 0 && b == 0) return 0;
    const std::uint32_t sign_a = (a & 0x80000000u) ? 0xffffffffu : 0u;
    const std::uint32_t sign_b = (b & 0x80000000u) ? 0xffffffffu : 0u;
    const std::uint32_t aa = (a ^ sign_a) - sign_a;
    const std::uint32_t bb = (b ^ sign_b) - sign_b;
    std::uint32_t magnitude = s32(aa) >= s32(bb) ? aa : bb;
    std::uint32_t result = 1u;
    for (std::uint32_t n = 1u; s32(n) < s32(magnitude); ++n)
        result += n * 8u;
    if (s32(a) == s32(magnitude)) return result + b + magnitude;
    if (s32(b) == s32(magnitude)) return result + magnitude * 3u - a;
    if (a == 0u - magnitude) return result + magnitude * 5u - b;
    return result + magnitude * 7u + a;
}

// RVA 0x379020. The first argument is the destination string and the second
// is the source. Original word scans require readable padding past the NUL.
std::uint32_t fun_00779020(Memory& m, const Inputs& i) {
    const std::uint32_t destination = i.arg[0];
    const std::uint32_t source = i.arg[1];
    std::uint32_t end = destination;
    while (m.r8(end) != 0) ++end;
    std::uint32_t read = source;
    for (;;) {
        const std::uint32_t byte = m.r8(read++);
        m.w8(end++, byte);
        if (byte == 0) break;
    }
    return destination;
}

}
