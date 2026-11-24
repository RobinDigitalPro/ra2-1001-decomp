#include "recovered/floating_b61_c.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::floating_b61 {
namespace {
inline void fmul_st4(const Inputs& i) { fp_extra::reg<0xd8cc>(i.fp); }
inline void fmul_st6(const Inputs& i) { fp_extra::reg<0xd8ce>(i.fp); }
inline void fmul_st7(const Inputs& i) { fp_extra::reg<0xd8cf>(i.fp); }
inline void fmul_st1(const Inputs& i) { fp_extra::reg<0xd8c9>(i.fp); }
inline void fmul_st3(const Inputs& i) { fp_extra::reg<0xd8cb>(i.fp); }
inline void fld_st0(const Inputs& i) { fp_extra::reg<0xd9c0>(i.fp); }
inline void fld_st1(const Inputs& i) { fp_extra::reg<0xd9c1>(i.fp); }
inline void fld_st2(const Inputs& i) { fp_extra::reg<0xd9c2>(i.fp); }
inline void fld_st3(const Inputs& i) { fp_extra::reg<0xd9c3>(i.fp); }
inline void fadd_st1(const Inputs& i) { fp_extra::reg<0xd8c1>(i.fp); }
inline void fadd_st0(const Inputs& i) { fp_extra::reg<0xdcc0>(i.fp); }
inline void fsub_st1(const Inputs& i) { fp_extra::reg<0xd8e1>(i.fp); }
inline void faddp(const Inputs& i) { fp_extra::reg<0xdec1>(i.fp); }
inline void fsubp(const Inputs& i) { fp_extra::reg<0xdee9>(i.fp); }
inline void fstp_st0(const Inputs& i) { fp_extra::reg<0xddd8>(i.fp); }
}


namespace {
inline void discard(const Inputs& i) { fp_extra::reg<0xddd8>(i.fp); }
inline void duplicate(const Inputs& i) { fp_extra::reg<0xd9c0>(i.fp); }
inline void add_top(const Inputs& i) { fp_extra::reg<0xd8c1>(i.fp); }
inline void double_top(const Inputs& i) { fp_extra::reg<0xdcc0>(i.fp); }
inline std::uint16_t compare_pop64(const Inputs& i, std::uint64_t v) {
    i.fp.compare_pop64(v); return i.fp.status();
}
inline std::uint64_t raw64(Memory& m,std::uint32_t p) {
    const auto lo=m.r32(p); const auto hi=m.r32(p+4u);
    return std::uint64_t(lo)|(std::uint64_t(hi)<<32);
}
inline void copy12(Memory& m,std::uint32_t dst,const std::array<std::uint32_t,12>& src) {
    // REP MOVSD's forward transfer order is observable when the destination aliases.
    for (unsigned n=0;n<12;++n) m.w32(dst+4u*n,src[n]);
}
}

std::uint32_t fun_0061aa40(Memory& m, const Inputs& i) {
    std::uint32_t s[18]{}; const auto obj=i.dx, out=i.cx;
    i.fp.load32(m.r32(obj+8u)); fld_st0(i); fp_extra::reg<0xdec9>(i.fp);
    i.fp.load32(m.r32(obj+4u)); fld_st0(i); fmul_st1(i);
    s[0x14/4]=i.fp.pop32(); fstp_st0(i);
    i.fp.load32(s[0x14/4]); fadd_st1(i); fadd_st0(i); fp_extra::reverse_subtract32(i.fp,m.r32(0x7867f8u)); s[0x18/4]=i.fp.pop32();
    i.fp.load32(m.r32(obj+4u)); i.fp.multiply32(m.r32(obj));
    i.fp.load32(m.r32(obj+0x0cu)); i.fp.multiply32(m.r32(obj+8u));
    fp_extra::reg<0xd9c1>(i.fp); fsub_st1(i); fadd_st0(i); s[0x1c/4]=i.fp.pop32();
    i.fp.load32(m.r32(obj+0x0cu)); i.fp.multiply32(m.r32(obj+4u)); s[0x0c/4]=i.fp.pop32();
    i.fp.load32(m.r32(obj)); i.fp.multiply32(m.r32(obj+8u)); s[0x08/4]=i.fp.store32();
    i.fp.add32(s[0x0c/4]); fadd_st0(i); s[0x20/4]=i.fp.pop32();
    fadd_st1(i); fadd_st0(i); s[0x28/4]=i.fp.pop32(); fstp_st0(i);
    i.fp.load32(m.r32(obj)); fld_st0(i); fmul_st1(i); s[0x10/4]=i.fp.pop32(); fstp_st0(i);
    i.fp.load32(s[0x10/4]); fadd_st1(i); fadd_st0(i); fp_extra::reverse_subtract32(i.fp,m.r32(0x7867f8u)); s[0x2c/4]=i.fp.pop32(); fstp_st0(i);
    i.fp.load32(m.r32(obj+4u)); i.fp.multiply32(m.r32(obj+8u));
    i.fp.load32(m.r32(obj+0x0cu)); i.fp.multiply32(m.r32(obj));
    fld_st1(i); fsub_st1(i); fadd_st0(i); s[0x30/4]=i.fp.pop32();
    i.fp.load32(s[0x08/4]); i.fp.subtract32(s[0x0c/4]); fadd_st0(i); s[0x38/4]=i.fp.pop32();
    fadd_st1(i); // 0x61aaf5, before the three original stack dword stores.
    s[0x44/4]=0; s[0x34/4]=0; s[0x24/4]=0;
    fadd_st0(i); s[0x3c/4]=i.fp.pop32(); fstp_st0(i);
    i.fp.load32(s[0x10/4]); i.fp.add32(s[0x14/4]); fadd_st0(i); fp_extra::reverse_subtract32(i.fp,m.r32(0x7867f8u)); s[0x40/4]=i.fp.pop32();
    for (unsigned n=0;n<12;++n) m.w32(out+4u*n,s[(0x18u+4u*n)/4u]);
    return out;
}

std::uint32_t fun_00619f90(Memory& m, const Inputs& i) {
    std::uint32_t s[18]{}; const auto obj=i.dx, out=i.cx;
    i.fp.load32(m.r32(obj)); i.fp.load32(m.r32(obj+4u));
    const auto eax=i.arg[0];
    s[0x28/4]=i.fp.pop32();
    i.fp.load32(m.r32(obj+8u)); s[0x2c/4]=i.fp.pop32();
    i.fp.load32(m.r32(eax)); s[0x14/4]=i.fp.pop32();
    i.fp.load32(m.r32(eax+4u)); const auto esi=m.r32(eax+0x0cu); s[0x18/4]=i.fp.pop32();
    i.fp.load32(m.r32(eax+8u)); s[0x1c/4]=i.fp.pop32();
    i.arg[0]=esi; // MOV [ESP+0x48],ESI
    i.fp.multiply32(i.arg[0]);
    i.fp.load32(s[0x28/4]); i.fp.multiply32(i.arg[0]); s[0x28/4]=i.fp.pop32();
    i.fp.load32(s[0x2c/4]); i.fp.multiply32(i.arg[0]); s[0x2c/4]=i.fp.pop32();
    i.fp.load32(m.r32(obj+0x0cu)); fld_st0(i); i.fp.multiply32(s[0x14/4]); s[0x14/4]=i.fp.pop32();
    i.fp.load32(s[0x18/4]); fmul_st1(i); s[0x18/4]=i.fp.pop32();
    i.fp.load32(s[0x1c/4]); fmul_st1(i); s[0x1c/4]=i.fp.pop32(); fstp_st0(i);
    i.fp.load32(m.r32(obj+4u)); i.fp.multiply32(m.r32(eax+8u));
    i.fp.load32(m.r32(obj+8u)); i.fp.multiply32(m.r32(eax+4u)); fsubp(i);
    i.fp.load32(m.r32(obj+8u)); i.fp.multiply32(m.r32(eax));
    i.fp.load32(m.r32(eax+8u)); i.fp.multiply32(m.r32(obj)); fsubp(i); s[0x38/4]=i.fp.pop32();
    i.fp.load32(m.r32(eax+4u)); i.fp.multiply32(m.r32(obj));
    i.fp.load32(m.r32(obj+4u)); i.fp.multiply32(m.r32(eax)); fsubp(i); s[0x3c/4]=i.fp.pop32();

    i.fp.add32(s[0x14/4]); fadd_st1(i); s[0x04/4]=i.fp.pop32(); fstp_st0(i);
    i.fp.load32(s[0x28/4]); i.fp.add32(s[0x18/4]); i.fp.add32(s[0x38/4]); s[0x08/4]=i.fp.pop32();
    i.fp.load32(s[0x2c/4]); i.fp.add32(s[0x1c/4]); i.fp.add32(s[0x3c/4]); s[0x0c/4]=i.fp.pop32();
    i.fp.load32(m.r32(obj+0x0cu)); i.fp.multiply32(m.r32(eax+0x0cu));
    i.fp.load32(m.r32(obj+8u)); i.fp.multiply32(m.r32(eax+8u));
    i.fp.load32(m.r32(obj+4u)); i.fp.multiply32(m.r32(eax+4u));
    faddp(i); i.fp.load32(m.r32(obj)); i.fp.multiply32(m.r32(eax)); faddp(i); fsubp(i); s[0x04]=i.fp.pop32();
    i.fp.load32(s[3]); i.fp.multiply32(s[3]);
    i.fp.load32(s[2]); i.fp.multiply32(s[2]); faddp(i);
    i.fp.load32(s[4]); i.fp.multiply32(s[4]); faddp(i);
    i.fp.load32(s[1]); i.fp.multiply32(s[1]); faddp(i);
    i.fp.load32(m.r32(0x785738u)); fp_extra::reg<0xd8d9>(i.fp);
    const auto status=i.fp.status();
    if ((status&0x4000u)==0u) {
        i.fp.load32(s[1]); fp_extra::reg<0xd8f1>(i.fp); s[1]=i.fp.pop32();
        i.fp.load32(s[2]); fp_extra::reg<0xd8f1>(i.fp); s[2]=i.fp.pop32();
        i.fp.load32(s[3]); fp_extra::reg<0xd8f1>(i.fp); s[3]=i.fp.pop32();
        i.fp.load32(s[4]); fp_extra::reg<0xd8f1>(i.fp); s[4]=i.fp.pop32();
    }
    // POP ESI has raised ESP by four: these four output loads use the same
    // physical local slots as pre-pop displacements +4,+8,+0c,+10.
    const auto r1=s[2], r2=s[3], r3=s[4];
    const auto edx=s[1]; fstp_st0(i);
    m.w32(out,edx); m.w32(out+4u,r1); m.w32(out+8u,r2); m.w32(out+12u,r3);
    return out;
}

// RVA 0x1dfb0. Positive duration advances the double-precision clock using
// its source sequence; both boundary clamps use the original x87 status tests.
std::uint32_t fun_0041dfb0(Memory& m,const Inputs& i) {
    const auto object=i.cx;
    std::uint32_t edx=m.r32(object+0x108u);
    i.fp.load64(raw64(m,0x786610u));
    std::uint32_t stack_duration=edx;
    if (s32(edx)>0) {
        discard(i); i.fp.load_integer32(stack_duration); i.fp.load_integer32(m.r32(object+0x104u));
        fp_extra::reg<0xd8f1>(i.fp); i.fp.subtract64(raw64(m,0x785728u)); fp_extra::reg<0xdec9>(i.fp);
        fp_extended::compare64(i.fp,raw64(m,0x786610u));
        if (i.fp.status()&0x0100u) { discard(i); i.fp.load64(raw64(m,0x786610u)); }
    }
    const auto global=m.r32(0x821b88u);
    i.fp.load64(raw64(m,global+0xb8u)); i.fp.add64(raw64(m,object+0xb8u));
    fp_extra::reg<0xdec1>(i.fp); write64(m,object+0xb8u,i.fp.store64());
    if (compare_pop64(i,raw64(m,object+0xc0u))&0x0100u) {
        const auto lo=m.r32(object+0xc0u),hi=m.r32(object+0xc4u);m.w32(object+0xb8u,lo);m.w32(object+0xbcu,hi);
    }
    i.fp.load64(raw64(m,object+0xb8u));
    const auto upper_status=compare_pop64(i,raw64(m,object+0xc8u));
    if ((upper_status&0x4100u)==0) {
        const auto lo=m.r32(object+0xc8u),hi=m.r32(object+0xccu);m.w32(object+0xb8u,lo);m.w32(object+0xbcu,hi);
    }
    const auto eax=m.r32(object+0x104u)+1u;
    edx+=1u;m.w32(object+0x104u,eax);m.w32(object+0x108u,edx);
    return eax;
}

// RVA 0x1e070. The incremented substep is deliberately stored only after the
// lower and upper clamps; FNSTSW AX leaves incoming high EAX bits on unclamped paths.
std::uint32_t fun_0041e070(Memory& m,const Inputs& i) {
    const auto object=i.cx;
    std::uint32_t edx=m.r32(object+0x108u), eax=i.ax;
    i.fp.load64(raw64(m,0x786610u));
    const auto global=m.r32(0x821b88u);
    const auto step=edx;
    if (s32(edx)>0) {
        discard(i);i.fp.load_integer32(step);i.fp.load_integer32(m.r32(object+0x104u));
        fp_extra::reg<0xd8f1>(i.fp);i.fp.subtract64(raw64(m,0x785728u));i.fp.multiply64(raw64(m,global+0xc8u));
        fp_extra::reg<0xdec9>(i.fp);fp_extended::compare64(i.fp,raw64(m,0x786610u));
        auto sw=i.fp.status();eax=(eax&0xffff0000u)|(sw&0xffffu);
        if ((sw&0x4100u)==0) { discard(i);i.fp.load64(raw64(m,0x786610u)); }
    }
    i.fp.load64(raw64(m,global+0xc0u));i.fp.add64(raw64(m,object+0xb8u));fp_extra::reg<0xdec1>(i.fp);
    write64(m,object+0xb8u,i.fp.store64());
    auto sw=compare_pop64(i,raw64(m,object+0xc0u));eax=(eax&0xffff0000u)|(sw&0xffffu);
    if (sw&0x0100u) { eax=m.r32(object+0xc0u);m.w32(object+0xb8u,eax);eax=m.r32(object+0xc4u);m.w32(object+0xbcu,eax); }
    i.fp.load64(raw64(m,object+0xb8u));sw=compare_pop64(i,raw64(m,object+0xc8u));eax=(eax&0xffff0000u)|(sw&0xffffu);
    if ((sw&0x4100u)==0) { eax=m.r32(object+0xc8u);m.w32(object+0xb8u,eax);eax=m.r32(object+0xccu);m.w32(object+0xbcu,eax); }
    edx+=1u;m.w32(object+0x108u,edx);
    (void)global;
    return eax;
}
}
