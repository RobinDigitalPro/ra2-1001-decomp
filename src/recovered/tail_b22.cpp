#include "tail_b22.hpp"

namespace ra2::recovered::tail_b22 {
namespace detail {
constexpr std::uint32_t CF=1u<<0, PF=1u<<2, AF=1u<<4, ZF=1u<<6, SF=1u<<7, OF=1u<<11;
constexpr std::uint32_t LOGIC_FLAGS=CF|PF|ZF|SF|OF;
constexpr std::uint32_t ADD_FLAGS=LOGIC_FLAGS|AF;
inline bool even_parity(std::uint8_t v) {
    v ^= static_cast<std::uint8_t>(v >> 4); v &= 0x0fu;
    return ((0x6996u >> v) & 1u) == 0u;
}
inline std::uint32_t status(std::uint32_t old, std::uint32_t value, std::uint32_t mask) {
    std::uint32_t bits=0;
    if (value == 0u) bits |= ZF;
    if (value & 0x80000000u) bits |= SF;
    if (even_parity(static_cast<std::uint8_t>(value))) bits |= PF;
    return (old & ~mask) | (bits & mask);
}
inline std::uint32_t add32(Cpu32& c, std::uint32_t a, std::uint32_t b) {
    const std::uint32_t r = a + b;
    std::uint32_t bits=0;
    const std::uint64_t wide=std::uint64_t(a)+std::uint64_t(b);
    if (wide >> 32) bits |= CF;
    if (((a ^ b ^ r) & 0x10u) != 0u) bits |= AF;
    if (r == 0u) bits |= ZF;
    if (r & 0x80000000u) bits |= SF;
    if ((~(a ^ b) & (a ^ r) & 0x80000000u) != 0u) bits |= OF;
    if (even_parity(static_cast<std::uint8_t>(r))) bits |= PF;
    c.eflags=(c.eflags & ~ADD_FLAGS) | bits;
    return r;
}
inline std::uint32_t logic32(Cpu32& c, std::uint32_t r) {
    // x86 defines CF=OF=0 and SF/ZF/PF for logical ops. AF is undefined;
    // preserve its incoming bit and exclude it from the contract comparison.
    c.eflags &= ~(CF|OF);
    c.eflags=status(c.eflags,r,PF|ZF|SF);
    return r;
}
inline std::uint8_t logic8(Cpu32& c, std::uint8_t r) {
    c.eflags &= ~(CF|OF);
    const std::uint32_t defined=PF|ZF|SF;
    std::uint32_t bits=0;
    if (r==0u) bits|=ZF;
    if (r&0x80u) bits|=SF;
    if (even_parity(r)) bits|=PF;
    c.eflags=(c.eflags&~defined)|bits;
    return r;
}
}

void fun_004026a0(Memory& m, Cpu32& c) {
    c.eax = m.read32(c.ecx + 0xd4u);
    c.next_eip = m.read32(c.eax + 0x28u);
}

void fun_004026b0(Memory& m, Cpu32& c) {
    c.eax = m.read32(c.ecx + 0xd4u);
    c.next_eip = m.read32(c.eax + 0x2cu);
}

void fun_00403810(Memory& m, Cpu32& c) {
c.next_eip = m.read32(c.ecx + 0x10cu);
}

void fun_00406fa0(Memory& m, Cpu32& c) {
    c.edx = detail::logic32(c, c.edx ^ c.edx);
    c.next_eip = 0x004070a0u;
}

void fun_00407fe0(Memory& m, Cpu32& c) {
    c.ecx = m.read32(c.ecx + 0x14u);
    c.edx = detail::logic32(c, 0u);
    { const auto old = c.ecx; c.ecx = detail::add32(c, old, 0x10u); }
    c.next_eip = 0x004070a0u;
}

void fun_00408400(Memory& m, Cpu32& c) {
    c.eax = detail::logic32(c, 0u);
    m.write32(c.ecx, c.eax); m.write32(c.ecx + 4u, c.eax);
    m.write32(c.ecx + 0x14u, c.eax); m.write32(c.ecx + 0x18u, c.eax);
    { const auto old = c.ecx; c.ecx = detail::add32(c, old, 8u); }
    c.next_eip = 0x004071f0u;
}

void fun_00408440(Memory& m, Cpu32& c) {
    { const auto old = c.ecx; c.ecx = detail::add32(c, old, 8u); }
    c.next_eip = 0x004073a0u;
}

void fun_0046e0c0(Memory& m, Cpu32& c) {
c.edx = c.ecx; c.ecx = m.read32(0x00838be4u); c.next_eip = 0x004981c0u;
}

void fun_00479e20(Memory& m, Cpu32& c) {
c.ecx = m.read32(c.ecx + 0x44u); c.next_eip = 0x005d4730u;
}

void fun_00481170(Memory& m, Cpu32& c) {
    c.eax = detail::logic32(c, 0u);
    m.write32(c.ecx + 0x34u, c.eax); m.write32(c.ecx + 0x38u, c.eax);
    m.write32(c.ecx + 0x3cu, c.eax); m.write32(c.ecx + 0x40u, c.eax);
    m.write32(c.ecx + 8u, c.eax); m.write32(c.ecx + 0xcu, c.eax);
    m.write32(c.ecx + 0x10u, c.eax); m.write32(c.ecx + 0x14u, c.eax);
    m.write32(c.ecx + 0x18u, c.eax);
    c.eax = detail::logic32(c, c.eax | 0xffffffffu);
    m.write32(c.ecx + 0x44u, c.eax); m.write32(c.ecx + 0x48u, c.eax);
    c.ecx = m.read32(c.ecx + 4u);
    c.next_eip = 0x0047fea0u;
}

void fun_004c8890(Memory& m, Cpu32& c) {
    c.eax = m.read32(c.ecx + 0x49cu);
    { const auto old = c.ecx; c.ecx = detail::add32(c, old, 0x49cu); }
    c.next_eip = m.read32(c.eax + 0x0cu);
}

void fun_004c8970(Memory& m, Cpu32& c) {
c.next_eip = 0x00591450u;
}

void fun_004cca70(Memory& m, Cpu32& c) {
c.next_eip = 0x005cdaa0u;
}

void fun_004ced20(Memory& m, Cpu32& c) {
    c.eax = m.read32(c.ecx);
    m.write8(c.ecx + 0x1eu, 0u);
    m.write8(c.ecx + 0x1cu, 1u);
    c.next_eip = m.read32(c.eax + 0x54u);
}

void fun_004ced30(Memory& m, Cpu32& c) {
    c.eax = (c.eax & 0xffffff00u) | 1u;
    m.write8(c.ecx + 0x1eu, c.eax);
    m.write8(c.ecx + 0x1cu, c.eax);
    c.eax = m.read32(c.ecx);
    c.next_eip = m.read32(c.eax + 0x54u);
}

void fun_0051a280(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x00785658u); c.next_eip = 0x0042f250u;
}

void fun_00539370(Memory& m, Cpu32& c) {
m.write32(c.ecx + 4u, 1u); m.write32(c.ecx + 0xcu, 0u); c.next_eip = 0x00539950u;
}

void fun_005393c0(Memory& m, Cpu32& c) {
m.write32(c.ecx + 4u, 3u); m.write32(c.ecx + 0xcu, 0u); c.next_eip = 0x00539950u;
}

void fun_0059a2e0(Memory& m, Cpu32& c) {
c.next_eip = 0x0059a2f0u;
}

void fun_005ae2a0(Memory& m, Cpu32& c) {
c.next_eip = 0x00759320u;
}

void fun_005b3530(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785524u);
}

void fun_005b63e0(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x007922e4u);
    { const auto old = c.ecx; c.ecx = detail::add32(c, old, 4u); }
    c.next_eip = 0x0075b390u;
}

void fun_005b6fa0(Memory& m, Cpu32& c) {
c.ecx = (c.ecx & 0xffffff00u) | detail::logic8(c, static_cast<std::uint8_t>(c.ecx ^ c.ecx)); c.next_eip = 0x005b6fb0u;
}

void fun_0060ba20(Memory& m, Cpu32& c) {
c.next_eip = 0x0060ba30u;
}

void fun_00614130(Memory& m, Cpu32& c) {
c.next_eip = 0x00626800u;
}

void fun_006497b0(Memory& m, Cpu32& c) {
c.ecx = 0x00821b30u; c.next_eip = 0x0046bdc0u;
}

void fun_006497c0(Memory& m, Cpu32& c) {
c.ecx = 0x00821ae0u; c.next_eip = 0x0046bdc0u;
}

void fun_00696170(Memory& m, Cpu32& c) {
c.next_eip = 0x00671210u;
}

void fun_006a93e0(Memory& m, Cpu32& c) {
c.ecx = m.read32(c.ecx + 0x24u); c.next_eip = 0x006aa2e0u;
}

void fun_006a93f0(Memory& m, Cpu32& c) {
c.ecx = m.read32(c.ecx + 0x24u); c.next_eip = 0x006aa2b0u;
}

void fun_006a9400(Memory& m, Cpu32& c) {
c.ecx = m.read32(c.ecx + 0x24u); c.next_eip = 0x006aa310u;
}

void fun_006c69e0(Memory& m, Cpu32& c) {
c.next_eip = 0x0060cf40u;
}

void fun_006e0420(Memory& m, Cpu32& c) {
    c.eax = m.read32(c.ecx);
    m.write8(c.ecx + 0x2du, 1u);
    c.next_eip = m.read32(c.eax + 0x48u);
}

void fun_006e0430(Memory& m, Cpu32& c) {
    c.eax = m.read32(c.ecx);
    m.write8(c.ecx + 0x2du, 0u);
    c.next_eip = m.read32(c.eax + 0x48u);
}

void fun_006e2e20(Memory& m, Cpu32& c) {
m.write8(c.ecx + 0x40u, 1u); c.next_eip = 0x006e2940u;
}

void fun_0071c840(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x00799f6cu); c.next_eip = 0x00630ab0u;
}

void fun_0071c850(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x00799f5cu); c.next_eip = 0x00630ab0u;
}

void fun_0071c860(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x00799f88u); c.next_eip = 0x00630ab0u;
}

void fun_0071d230(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x00799fa8u); c.next_eip = 0x00630cb0u;
}

void fun_00724ed0(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x0079a10cu); c.next_eip = 0x00630ab0u;
}

void fun_00727600(Memory& m, Cpu32& c) {
c.next_eip = 0x0070a9e0u;
}

void fun_00730ba0(Memory& m, Cpu32& c) {
m.write32(c.ecx, 0x0079a584u); c.next_eip = 0x005f8d90u;
}

void fun_007359a0(Memory& m, Cpu32& c) {
c.edx = (c.edx & 0xffffff00u) | detail::logic8(c, static_cast<std::uint8_t>(c.edx ^ c.edx));
    c.ecx = detail::logic32(c, c.ecx ^ c.ecx);
    c.next_eip = 0x00734590u;
}

void fun_0076d4a6(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785544u);
}

void fun_0076d4ac(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x0078553cu);
}

void fun_0076d4b2(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785538u);
}

void fun_0076d4b8(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785550u);
}

void fun_0076d4be(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785568u);
}

void fun_0076d4c4(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x0078557cu);
}

void fun_0076d4ca(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x0078556cu);
}

void fun_0076d4d0(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785534u);
}

void fun_0076d4d6(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785578u);
}

void fun_0076d4dc(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785574u);
}

void fun_0076d4e2(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785570u);
}

void fun_0076d4e8(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785548u);
}

void fun_0076d4ee(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785540u);
}

void fun_0076d4f4(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x0078554cu);
}

void fun_0076d4fa(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785564u);
}

void fun_0076d500(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785560u);
}

void fun_0076d506(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x0078555cu);
}

void fun_0076d50c(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785558u);
}

void fun_0076d512(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785554u);
}

void fun_0076d518(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785048u);
}

void fun_0076d51e(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785050u);
}

void fun_0076d524(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x0078550cu);
}

void fun_0076d52a(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785514u);
}

void fun_0076d530(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785510u);
}

void fun_0076d560(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x007850b8u);
}

void fun_0076d566(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x007850b4u);
}

void fun_0076d572(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x007850bcu);
}

void fun_0076f4ef(Memory& m, Cpu32& c) {
c.next_eip = 0x00776b01u;
}

void fun_0076f540(Memory& m, Cpu32& c) {
c.next_eip = 0x00776b01u;
}

void fun_0076f76f(Memory& m, Cpu32& c) {
c.next_eip = 0x00776b01u;
}

void fun_00772ef0(Memory& m, Cpu32& c) {
    c.esp -= 4u; m.write32(c.esp, c.ebp);
    c.ebp = c.esp;
    { const auto old = c.esp; c.esp = detail::add32(c, old, 0xffffffe0u); }
    m.write32(c.ebp - 0x20u, c.eax);
    c.eax = m.read32(c.ebp + 0x18u);
    m.write32(c.ebp - 0x10u, c.eax);
    c.eax = m.read32(c.ebp + 0x1cu);
    m.write32(c.ebp - 0x0cu, c.eax);
    c.next_eip = 0x00772f10u;
}

void fun_00779010(Memory& m, Cpu32& c) {
c.esp -= 4u; m.write32(c.esp, c.edi); c.edi = m.read32(c.esp + 8u); c.next_eip = 0x00779081u;
}

void fun_007795f7(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x007852e0u);
}

void fun_007819ca(Memory& m, Cpu32& c) {
c.next_eip = m.read32(0x00785280u);
}

const std::array<Entry, 77>& entries() {
    static const std::array<Entry, 77> value{{
        Entry{0x26a0u, 9u, &fun_004026a0},
        Entry{0x26b0u, 9u, &fun_004026b0},
        Entry{0x3810u, 6u, &fun_00403810},
        Entry{0x6fa0u, 7u, &fun_00406fa0},
        Entry{0x7fe0u, 13u, &fun_00407fe0},
        Entry{0x8400u, 21u, &fun_00408400},
        Entry{0x8440u, 8u, &fun_00408440},
        Entry{0x6e0c0u, 13u, &fun_0046e0c0},
        Entry{0x79e20u, 8u, &fun_00479e20},
        Entry{0x81170u, 46u, &fun_00481170},
        Entry{0xc8890u, 15u, &fun_004c8890},
        Entry{0xc8970u, 5u, &fun_004c8970},
        Entry{0xcca70u, 5u, &fun_004cca70},
        Entry{0xced20u, 13u, &fun_004ced20},
        Entry{0xced30u, 13u, &fun_004ced30},
        Entry{0x11a280u, 11u, &fun_0051a280},
        Entry{0x139370u, 19u, &fun_00539370},
        Entry{0x1393c0u, 19u, &fun_005393c0},
        Entry{0x19a2e0u, 5u, &fun_0059a2e0},
        Entry{0x1ae2a0u, 5u, &fun_005ae2a0},
        Entry{0x1b3530u, 6u, &fun_005b3530},
        Entry{0x1b63e0u, 14u, &fun_005b63e0},
        Entry{0x1b6fa0u, 7u, &fun_005b6fa0},
        Entry{0x20ba20u, 5u, &fun_0060ba20},
        Entry{0x214130u, 5u, &fun_00614130},
        Entry{0x2497b0u, 10u, &fun_006497b0},
        Entry{0x2497c0u, 10u, &fun_006497c0},
        Entry{0x296170u, 5u, &fun_00696170},
        Entry{0x2a93e0u, 8u, &fun_006a93e0},
        Entry{0x2a93f0u, 8u, &fun_006a93f0},
        Entry{0x2a9400u, 8u, &fun_006a9400},
        Entry{0x2c69e0u, 5u, &fun_006c69e0},
        Entry{0x2e0420u, 9u, &fun_006e0420},
        Entry{0x2e0430u, 9u, &fun_006e0430},
        Entry{0x2e2e20u, 9u, &fun_006e2e20},
        Entry{0x31c840u, 11u, &fun_0071c840},
        Entry{0x31c850u, 11u, &fun_0071c850},
        Entry{0x31c860u, 11u, &fun_0071c860},
        Entry{0x31d230u, 11u, &fun_0071d230},
        Entry{0x324ed0u, 11u, &fun_00724ed0},
        Entry{0x327600u, 5u, &fun_00727600},
        Entry{0x330ba0u, 11u, &fun_00730ba0},
        Entry{0x3359a0u, 9u, &fun_007359a0},
        Entry{0x36d4a6u, 6u, &fun_0076d4a6},
        Entry{0x36d4acu, 6u, &fun_0076d4ac},
        Entry{0x36d4b2u, 6u, &fun_0076d4b2},
        Entry{0x36d4b8u, 6u, &fun_0076d4b8},
        Entry{0x36d4beu, 6u, &fun_0076d4be},
        Entry{0x36d4c4u, 6u, &fun_0076d4c4},
        Entry{0x36d4cau, 6u, &fun_0076d4ca},
        Entry{0x36d4d0u, 6u, &fun_0076d4d0},
        Entry{0x36d4d6u, 6u, &fun_0076d4d6},
        Entry{0x36d4dcu, 6u, &fun_0076d4dc},
        Entry{0x36d4e2u, 6u, &fun_0076d4e2},
        Entry{0x36d4e8u, 6u, &fun_0076d4e8},
        Entry{0x36d4eeu, 6u, &fun_0076d4ee},
        Entry{0x36d4f4u, 6u, &fun_0076d4f4},
        Entry{0x36d4fau, 6u, &fun_0076d4fa},
        Entry{0x36d500u, 6u, &fun_0076d500},
        Entry{0x36d506u, 6u, &fun_0076d506},
        Entry{0x36d50cu, 6u, &fun_0076d50c},
        Entry{0x36d512u, 6u, &fun_0076d512},
        Entry{0x36d518u, 6u, &fun_0076d518},
        Entry{0x36d51eu, 6u, &fun_0076d51e},
        Entry{0x36d524u, 6u, &fun_0076d524},
        Entry{0x36d52au, 6u, &fun_0076d52a},
        Entry{0x36d530u, 6u, &fun_0076d530},
        Entry{0x36d560u, 6u, &fun_0076d560},
        Entry{0x36d566u, 6u, &fun_0076d566},
        Entry{0x36d572u, 6u, &fun_0076d572},
        Entry{0x36f4efu, 5u, &fun_0076f4ef},
        Entry{0x36f540u, 5u, &fun_0076f540},
        Entry{0x36f76fu, 5u, &fun_0076f76f},
        Entry{0x372ef0u, 23u, &fun_00772ef0},
        Entry{0x379010u, 7u, &fun_00779010},
        Entry{0x3795f7u, 6u, &fun_007795f7},
        Entry{0x3819cau, 6u, &fun_007819ca},
    }};
    return value;
}
}
