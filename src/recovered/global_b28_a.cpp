#include "recovered/global_b28_memory.hpp"

namespace ra2::recovered::global_b28 {

void fun_004084c0(Memory& m, State& s) {
    auto p=s.cx;
    for (unsigned i=0;i<8;++i) { m.w32(p,0); p+=4u; }
    s.cx=0;
    s.ax=0;
}

void fun_00409cb0(Memory& m, State& s) {
    const auto count_a=m.r32(s.arg[0]);
    const auto count_b=m.r32(s.arg[2]);
    auto n=(s32(count_a)>s32(count_b))?count_b:count_a;
    s.cx=count_b;
    if (!n) { s.ax=1; return; }
    auto src=s.arg[1], dst=s.dx;
    const auto initial=n;
    auto dwords=n/4u;
    while (dwords--) { auto v=m.r32(src); m.w32(dst,v); src+=4u; dst+=4u; }
    n=initial&3u;
    while (n--) { auto v=m.r8(src); m.w8(dst,v); ++src; ++dst; }
    m.w32(s.arg[0],initial);
    m.w32(s.arg[2],initial);
    s.ax=1; s.cx=0; s.dx=initial;
}

void fun_004b5780(Memory& m, State& s) {
    const auto p=s.cx;
    m.w32(p+0x34u,0); m.w32(p+0x38u,0); m.w32(p+0x3cu,1); m.w16(p+0x40u,0);
    auto d=p;
    for (unsigned i=0;i<12;++i) { m.w32(d,0); d+=4u; }
    m.w16(d,0);
    s.dx=p; s.ax=p; s.cx=0;
}

void fun_00530390(Memory& m, State& s) {
    const auto p=s.cx;
    m.w32(p,0); m.w32(p+4u,0); m.w32(p+0x0cu,0); m.w32(p+0x10u,0);
    m.w32(p+0x314u,0); m.w32(p+0x318u,0);
    auto d=p+0x14u;
    for (unsigned i=0;i<0x40u;++i) { m.w32(d,0); d+=4u; }
    s.dx=p; s.ax=p; s.cx=0;
}

void fun_005453c0(Memory& m, State& s) {
    const auto rect=s.arg[1];
    const auto bl=m.r32(s.cx+0xf0u);
    const auto ebp=m.r32(s.cx+0xf8u);
    const auto y=static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(rect+2u))));
    const auto x=static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(rect))));
    const auto origin=m.r32(s.cx+0xfcu);
    std::uint32_t width=x-y;
    if (bl&1u) width+=1u;
    auto height=y-bl;
    const auto signmask=0u-(bl>>31);
    const auto signed_half=sar(bl-signmask,1u);
    height+=x;
    width=sar(width,1u)+signed_half;
    width-=ebp;
    height-=origin;
    s.arg[1]=static_cast<std::uint16_t>(width) |
             (static_cast<std::uint32_t>(static_cast<std::uint16_t>(height))<<16);
    m.w32(s.arg[0],s.arg[1]);
    s.cx=s.arg[1];
    s.dx=0u-(bl>>31);
    s.ax=s.arg[0];
}

void fun_0058cc10(Memory& m, State& s) {
    auto src=s.arg[0], dst=s.cx;
    for (unsigned i=0;i<12;++i) { auto v=m.r32(src); m.w32(dst,v); src+=4u; dst+=4u; }
    s.ax=s.cx; s.cx=0;
}

void fun_00590ef0(Memory& m, State& s) {
    const auto input=static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(s.cx)));
    const auto divisor=s.arg[1];
    if (!divisor) throw std::domain_error("0x190ef0 IDIV by zero outside bounded domain");
    const auto signed_divisor=static_cast<std::int32_t>(divisor);
    const auto q=input/signed_divisor;
    const auto rem=input%signed_divisor;
    s.arg[1]=(s.arg[1]&0xffff0000u)|(static_cast<std::uint32_t>(q)&0xffffu);
    s.cx=s.arg[1];
    s.dx=static_cast<std::uint32_t>(rem);
    m.w32(s.arg[0],s.cx);
    s.ax=s.arg[0];
}

void fun_00590f40(Memory& m, State& s) {
    auto bp=m.r16(s.arg[1]);
    auto di=m.r16(s.arg[0]);
    auto si=m.r16(s.cx);
    auto abs16=[](std::uint32_t v) { auto sx=static_cast<std::int32_t>(static_cast<std::int16_t>(v)); return sx<0?0u-static_cast<std::uint32_t>(sx):static_cast<std::uint32_t>(sx); };
    auto dx_abs=abs16(static_cast<std::uint32_t>(static_cast<std::int16_t>(bp)));
    s.arg[0]=dx_abs; // MOV [entry ESP+4],EAX after loading all three input words
    auto xdiff=abs16(static_cast<std::uint32_t>(static_cast<std::int16_t>(si-di)));
    auto eax=xdiff;
    if (static_cast<std::int32_t>(dx_abs)>=static_cast<std::int32_t>(xdiff)) {
        m.w16(s.cx,di); s.ax=with_al(eax,1u); s.dx=dx_abs; return;
    }
    di=static_cast<std::uint16_t>(di-si);
    if (static_cast<std::int16_t>(di)>=0) {
        bp=static_cast<std::uint16_t>(bp+si);
        m.w16(s.cx,bp);
    } else {
        si=static_cast<std::uint16_t>(si-bp);
        m.w16(s.cx,si);
    }
    s.ax=with_al(eax,0u); s.dx=dx_abs;
}

void fun_005a4890(Memory& m, State& s) {
    auto dst=s.cx;
    auto n=s.arg[0];
    while (n--) { m.w32(dst,0); dst+=4u; }
    m.w32(s.cx,s.dx);
    s.ax=0; s.cx=0;
}

void fun_005a4910(Memory& m, State& s) {
    auto src=s.dx, dst=s.cx;
    auto n=s.arg[0];
    while (n--) { auto v=m.r32(src); m.w32(dst,v); src+=4u; dst+=4u; }
    s.cx=0;
}

void fun_005a7610(Memory& m, State& s) {
    const auto p=s.cx;
    m.w32(0x00a5929cu,0);
    auto d=0x00a59208u;
    for (unsigned i=0;i<8;++i) { m.w32(d,0); d+=4u; }
    m.w32(0x00a592a0u,0);
    s.dx=p; s.ax=p; s.cx=0;
}

void fun_005b17b0(Memory& m, State& s) {
    const auto p=s.cx;
    for (unsigned off=0;off<=0x14u;off+=4u) m.w32(p+off,0);
    m.w8(p+0x18u,0); m.w8(p+0x19u,0); m.w8(p+0x1au,0);
    m.w32(p+0x1cu,0); m.w32(p+0x20u,0); m.w32(p+0x24u,0);
    m.w32(p+0x2b0u,0); m.w32(p+0x2b4u,0); m.w16(p+0x2b8u,0);
    m.w32(p+0x2bcu,0); m.w32(p+0x2c0u,0); m.w32(p+0x2c4u,0);
    m.w16(p+0x28u,0); m.w16(p+0x16cu,0);
    auto d=p+0x1480u;
    for (unsigned i=0;i<7;++i) { m.w32(d,0x10001u); d+=4u; }
    s.dx=p; s.ax=p; s.cx=0;
}

void fun_005fac60(Memory& m, State& s) {
    const auto src=s.arg[0], dst=s.cx;
    if (dst!=src) {
        auto a=src,b=dst;
        for (unsigned i=0;i<0xc0u;++i) { auto v=m.r32(a); m.w32(b,v); a+=4u; b+=4u; }
        s.cx=0;
    }
    s.ax=dst;
}

const std::array<Entry,13>& entries_a(){static const std::array<Entry,13> v{{
    {0x84c0,fun_004084c0},{0x9cb0,fun_00409cb0},{0xb5780,fun_004b5780},
    {0x130390,fun_00530390},{0x1453c0,fun_005453c0},{0x18cc10,fun_0058cc10},
    {0x190ef0,fun_00590ef0},{0x190f40,fun_00590f40},{0x1a4890,fun_005a4890},
    {0x1a4910,fun_005a4910},{0x1a7610,fun_005a7610},{0x1b17b0,fun_005b17b0},
    {0x1fac60,fun_005fac60}
}};return v;}

} // namespace ra2::recovered::global_b28
