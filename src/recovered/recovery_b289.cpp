#include "recovery_b289.hpp"
#include "platform/observed_ticks152.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b289 {
namespace {
void require(bool ok, const char* message) { if (!ok) throw std::domain_error(message); }
void local_w32(Inputs& i, unsigned off, std::uint32_t v) { for (unsigned k=0;k<4;++k) i.raw_stack[off+k]=std::uint8_t(v>>(8*k)); }
void format_21b190(Memory& m, Inputs& i, std::uint32_t object) {
    // Exact b5ce0 instruction effects for root-supplied args (object+0x30, 0x22).
    // The original table value is read, pushed with 0x7c19c0, then exact RVA
    // 0x68f0 executes RET, preserving EAX and all memory/registers.
    require(m.r32(object+0x30u)<=0x7fffffffu,"B289 excludes negative formatter object ID");
    (void)m.r32(0x7c16fcu + 0x22u * 4u);
    (void)0x7c19c0u;
    i.raw_stack[2]=std::uint8_t(m.r32(object+0x30u));
    i.raw_stack[0]=0x22u;
    local_w32(i,3u,m.r32(0xa2896cu));
}
void format_2eb140(Memory& m, Inputs& i, std::uint32_t object) {
    // Exact b5d40 instruction effects for root-supplied args (object+0x30,
    // 3, original root ECX). Its table/string arguments reach exact 0x68f0 RET.
    require(m.r32(object+0x30u)<=0x7fffffffu,"B289 excludes negative formatter object ID");
    (void)m.r32(0x7c16fcu + 3u * 4u);
    (void)0x7c19c0u;
    i.raw_stack[2]=std::uint8_t(m.r32(object+0x30u));
    i.raw_stack[0]=3u;
    local_w32(i,7u,i.cx);
    local_w32(i,3u,m.r32(0xa2896cu));
}
void copy111(Memory& m, const Inputs& i, std::uint32_t destination) { for (unsigned k=0;k<111;++k) m.w8(destination+k,i.raw_stack[k]); }
}
std::uint32_t fun_0061b190(Memory& m, Inputs& i) {
    const auto object = m.r32(0xa1e0e4u);
    require(object && !m.r8(object+0x13eu) && !m.r8(object+0x13fu) && !m.r8(object+0x140u), "outside positive 21b190 gate");
    require(m.r32(0xa1a668u) < 0x80u, "outside unsaturated 21b190 ring");
    format_21b190(m, i, object);
    const auto cursor = m.r32(0xa1a670u);
    require(cursor < 0x80u, "outside 21b190 cursor range");
    copy111(m, i, 0xa1a674u + 111u*cursor);
    m.w32(0xa1ddf4u + 4u*cursor, ra2::platform::ticks152::Tick::get());
    const auto count = m.r32(0xa1a668u) + 1u;
    m.w32(0xa1a668u, count);
    m.w32(0xa1a670u, (cursor+1u)&0x7fu);
    // Original INC EAX followed by MOV AL,1. In the fixture count+1 is 1..128,
    // so the resulting full EAX is exactly 1.
    return (count & 0xffffff00u) | 1u;
}
std::uint32_t fun_006eb140(Memory& m, Inputs& i) {
    require(m.r32(0xa255c8u) != 0, "outside positive 2eb140 enable gate");
    const auto state = m.r32(0xa255c0u);
    require(state && (m.r32(state) & 0x00000400u) == 0, "outside positive 2eb140 state gate");
    const auto other = m.r32(0x821b88u);
    require(other && m.r8(other+0x111du) != 0, "outside positive 2eb140 object gate");
    require(m.r32(0xa1a668u) < 0x80u, "outside unsaturated 2eb140 ring");
    const auto object = m.r32(0xa1e0e4u);
    require(object != 0, "missing 2eb140 formatter object");
    format_2eb140(m, i, object);
    const auto cursor = m.r32(0xa1a670u);
    require(cursor < 0x80u, "outside 2eb140 cursor range");
    copy111(m, i, 0xa1a674u + 111u*cursor);
    m.w32(0xa1ddf4u + 4u*cursor, ra2::platform::ticks152::Tick::get());
    const auto count = m.r32(0xa1a668u) + 1u;
    m.w32(0xa1a670u, (cursor+1u)&0x7fu);
    m.w32(0xa1a668u, count);
    return count;
}
}


