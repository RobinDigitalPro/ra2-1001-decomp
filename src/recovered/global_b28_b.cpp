#include "recovered/global_b28_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::global_b28 {
namespace {
void copy_words_forward(Memory& m, std::uint32_t dst, std::uint32_t src, std::uint32_t words) {
    for (std::uint32_t i = 0; i < words; ++i) m.w32(dst + i * 4u, m.r32(src + i * 4u));
}
}

void fun_00608c80(Memory& m, State& s) {
    const auto table = m.r32(s.cx + 4u);
    const auto index = s.arg[1];
    const auto record = m.r32(table + index * 4u);
    const auto src = m.r32(record + 4u);
    const auto dst = s.arg[0];
    copy_words_forward(m, dst, src, 0x1bu);
    const auto tail = src + 0x6cu;
    const auto out_tail = dst + 0x6cu;
    m.w16(out_tail, m.r16(tail));
    m.w8(out_tail + 2u, m.r8(tail + 2u));
    s.ax = dst;
    s.cx = 0;
    s.dx = record;
}

void fun_00608cb0(Memory& m, State& s) {
    auto count = m.r32(s.cx + 0x10u);
    std::uint32_t eax = 0;
    if (s32(count) > 0) {
        const auto table = m.r32(s.cx + 4u);
        const auto key = s.arg[1];
        for (std::uint32_t i = 0; s32(i) < s32(count); ++i) {
            const auto node = m.r32(table + i * 4u);
            if (m.r32(node) == key) {
                eax = node;
                break;
            }
        }
    }
    // The unchanged original dereferences EAX+4 even when EAX is zero. The
    // bounded fixture domain supplies a matching, valid node before this point.
    const auto src = m.r32(eax + 4u);
    const auto dst = s.arg[0];
    copy_words_forward(m, dst, src, 0x1bu);
    m.w16(dst + 0x6cu, m.r16(src + 0x6cu));
    m.w8(dst + 0x6eu, m.r8(src + 0x6eu));
    s.ax = dst;
    s.cx = 0;
    s.dx = count;
}

void fun_006168e0(Memory& m, State& s) {
    const auto object = s.cx;
    m.w32(object + 0x48u, 0); m.w32(object + 0x4cu, 0);
    m.w32(object + 0x50u, 0); m.w32(object + 0x54u, 0);
    m.w8(object + 0x58u, 0); m.w32(object + 0x5cu, 0);
    m.w8(object + 0x60u, 0); m.w8(object + 0x61u, 0); m.w8(object + 0x62u, 0);
    m.w32(object + 0x64u, 0); m.w32(object + 0x68u, 0); m.w32(object + 0x6cu, 0);
    m.w32(object + 0x78u, 0xffffffffu); m.w32(object + 0x80u, 0xffffffffu);
    m.w8(object + 0x70u, 0); m.w32(object + 0x7cu, 0);
    m.w32(object, 0x007933fcu);
    for (std::uint32_t i = 0; i < 0x10u; ++i) m.w32(object + 8u + 4u * i, 0);
    s.ax = object;
    s.cx = 0;
    s.dx = object;
}

void fun_00667a20(Memory& m, State& s) {
    auto eax = s.arg[0];
    if (eax == 0xfffffffeu) eax = 8u;
    else if (eax >= 9u) { s.ax = eax; return; }
    const auto value = m.r8(0x007dcd08u + eax);
    s.ax = static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(value)));
}

void fun_006a05c0(Memory& m, State& s) {
    auto ecx = m.r32(0x00aa60c8u);
    if (s32(ecx) <= 0) { s.cx = ecx; return; }
    auto eax = s.ax;
    bool eax_written = false;
    for (;;) {
        --ecx;
        auto edx = 0u;
        m.w32(0x00aa60c8u, ecx);
        if (s32(ecx) <= 0) { if (eax_written) s.ax = eax; s.cx = ecx; s.dx = edx; return; }
        eax = 0;
        eax_written = true;
        for (;;) {
            ++edx;
            const auto base = m.r32(0x00aa60bcu);
            const auto src = base + eax + 0x14u;
            const auto dst = base + eax;
            copy_words_forward(m, dst, src, 5u);
            eax += 0x14u;
            ecx = m.r32(0x00aa60c8u);
            if (s32(edx) >= s32(ecx)) break;
        }
        if (s32(ecx) <= 0) { s.ax = eax; s.cx = ecx; s.dx = edx; return; }
        // Original JG returns to the decrement at 0x6a05ce. EDX is reset on
        // that pass; EAX is reset only after the new positive-count check.
    }
}

void fun_006a8880(Memory& m, State& s) {
    const auto first_dst = s.cx;
    const auto source = s.arg[1];
    if (source != first_dst) copy_words_forward(m, first_dst, source, 8u);
    const auto second_dst = s.arg[0];
    copy_words_forward(m, second_dst, first_dst, 8u);
    s.ax = second_dst;
    s.cx = 0;
}

void fun_0070cb50(Memory& m, State& s) {
    const auto dst = s.cx;
    copy_words_forward(m, dst, 0x00adf228u, 0x0cu);
    s.ax = dst;
    s.cx = 0;
}

void fun_0070d920(Memory& m, State& s) {
    const auto dst = s.cx;
    const auto src = 0x00ae0088u + s.dx * 0x30u;
    copy_words_forward(m, dst, src, 0x0cu);
    s.ax = dst;
    s.cx = 0;
}

void fun_0070dbd0(Memory& m, State& s) {
    auto index = s.dx;
    if (s32(index) >= 4) index -= 4u;
    const auto src = 0x00adffb8u + (index * 3u << 4u);
    copy_words_forward(m, s.cx, src, 0x0cu);
    s.ax = s.cx;
    s.cx = 0;
    s.dx = index;
}

void fun_0073f170(Memory& m, State& s) {
    const auto count = m.r32(0x00b0fc00u);
    std::uint32_t eax = 0;
    auto edx = s.dx;
    auto ecx = s.cx;
    if (s32(count) > 0) {
        edx = m.r32(0x00b0fc08u);
        for (std::uint32_t i = 0; s32(i) < s32(count); ++i) {
            copy_words_forward(m, 0x00b0fb30u, edx, 0x1bu);
            ecx = 0;
            if ((m.r8(0x00b0fb30u) & 1u) != 0) {
                eax = 0x00b0fb30u;
                s.ax = eax; s.cx = ecx; s.dx = edx; return;
            }
            eax = i + 1u;
            edx += 0x6cu;
        }
        eax = 0;
    }
    s.ax = eax; s.cx = ecx; s.dx = edx;
}

void fun_007422a0(Memory& m, State& s) {
    for (std::uint32_t i = 0; i < 0x43u; ++i) m.w32(0x00b0eea0u + i * 4u, 0);
    for (std::uint32_t i = 0; i < 0x43u; ++i) m.w32(0x00b0e4a0u + i * 4u, 0);
    m.w32(0x00b0e5c8u, 0); m.w32(0x00b0ee70u, 0);
    m.w32(0x00b0fc00u, 0); m.w32(0x00b100b0u, 0);
    s.ax = 0; s.cx = 0; s.dx = 0;
}

void fun_00763190(Memory& m, State& s) {
    copy_words_forward(m, s.cx, 0x007e97b0u, 0x22u);
    s.cx = 0;
}

void fun_0077726c(Memory& m, State& s) {
    for (std::uint32_t i = 0; i < 0x40u; ++i) m.w32(0x00b10be0u + i * 4u, 0);
    m.w8(0x00b10ce0u, 0);
    m.w32(0x00b10ac8u, 0); m.w32(0x00b10adcu, 0); m.w32(0x00b10ce4u, 0);
    m.w32(0x00b10ad0u, 0); m.w32(0x00b10ad4u, 0); m.w32(0x00b10ad8u, 0);
    s.ax = 0; s.cx = 0;
}

const std::array<Entry, 13>& entries_b() {
    static const std::array<Entry, 13> entries{{
        {0x208c80, fun_00608c80}, {0x208cb0, fun_00608cb0}, {0x2168e0, fun_006168e0},
        {0x267a20, fun_00667a20}, {0x2a05c0, fun_006a05c0}, {0x2a8880, fun_006a8880},
        {0x30cb50, fun_0070cb50}, {0x30d920, fun_0070d920}, {0x30dbd0, fun_0070dbd0},
        {0x33f170, fun_0073f170}, {0x3422a0, fun_007422a0}, {0x363190, fun_00763190},
        {0x37726c, fun_0077726c}
    }};
    return entries;
}
} // namespace ra2::recovered::global_b28
