#include "recovered/indirect_b32_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::indirect_b32 {
namespace {
inline void call(Memory& m, State& s, Frame& f, const Operations& op, std::uint32_t target) {
    indirect_b31::invoke(m,s,f,op,target);
}
inline void done(Memory& m, State& s, Frame& f, std::uint32_t clean) { indirect_b31::finish(m,s,f,clean); }
inline bool nonpos(std::uint32_t x) { return s32(x)<=0; }

void f_aed0(Memory& m,State& s,Frame& f,const Operations& op) {
    auto count=m.r32(f.entry_sp+12u); --count;
    s.ax=count;
    if(s32(count)<0) { done(m,s,f,16); return; }
    f.push(m,s.bx); s.bx=m.r32(f.sp+20u);
    f.push(m,s.bp); s.bp=m.r32(f.sp+16u);
    f.push(m,s.si); s.si=m.r32(f.sp+16u);
    f.push(m,s.di); s.di=count+1u;
    do { s.cx=s.si; call(m,s,f,op,s.bx); s.si+=s.bp; --s.di; } while(s.di!=0);
    s.di=f.pop(m); s.si=f.pop(m); s.bp=f.pop(m); s.bx=f.pop(m);
    done(m,s,f,16);
}
void f_af00(Memory& m,State& s,Frame& f,const Operations& op) {
    std::uint32_t n=m.r32(f.entry_sp+12u);
    f.push(m,s.bx); s.bx=m.r32(f.sp+12u);
    f.push(m,s.si); s.si=m.r32(f.sp+12u);
    s.cx=s.bx*n; s.si+=s.cx; --n; s.ax=n;
    if(s32(n)<0) { s.si=f.pop(m); s.bx=f.pop(m); done(m,s,f,16); return; }
    f.push(m,s.bp); s.bp=m.r32(f.sp+28u);
    f.push(m,s.di); s.di=n+1u;
    do { s.si-=s.bx; s.cx=s.si; call(m,s,f,op,s.bp); --s.di; } while(s.di!=0);
    s.di=f.pop(m); s.bp=f.pop(m); s.si=f.pop(m); s.bx=f.pop(m); done(m,s,f,16);
}
void f_1b03e0(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.si); f.push(m,s.di); s.di=s.cx; s.si=0;
    auto n=m.r32(s.di+0x28u); s.ax=n; if(nonpos(n)){s.di=f.pop(m);s.si=f.pop(m);done(m,s,f,4);return;}
    f.push(m,s.bx); s.bx=m.r32(f.sp+16u);
    do {
        s.ax=m.r32(s.di+0x1cu); f.push(m,s.bx); s.cx=m.r32(s.ax+s.si*4u); s.dx=m.r32(s.cx);
        call(m,s,f,op,m.r32(s.dx+0x20u));
        n=m.r32(s.di+0x28u); s.ax=n; ++s.si;
    } while(s32(s.si)<s32(n));
    s.bx=f.pop(m); s.di=f.pop(m); s.si=f.pop(m); done(m,s,f,4);
}
void f_209c70(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.bx); f.push(m,s.si); f.push(m,s.di); s.di=s.cx; s.si=0; s.bx=m.r32(s.di+0x10u);
    if(nonpos(s.bx)){s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);done(m,s,f,0);return;}
    do {
        auto arr=m.r32(s.di+4u); s.ax=arr; s.cx=m.r32(arr+s.si*4u); s.cx=m.r32(s.cx);
        s.ax=with_al(s.ax,m.r8(s.cx+0x77u));
        if((s.ax&0xffu)==0){s.dx=m.r32(s.cx);call(m,s,f,op,m.r32(s.dx+0x140u));}
        ++s.si;
    } while(s32(s.si)<s32(s.bx));
    s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);done(m,s,f,0);
}
void f_209ca0(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.bx); f.push(m,s.si); f.push(m,s.di); s.di=s.cx; s.si=0; s.bx=m.r32(s.di+0x10u);
    if(nonpos(s.bx)){s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);done(m,s,f,0);return;}
    do {
        auto arr=m.r32(s.di+4u); s.ax=arr; s.cx=m.r32(arr+s.si*4u); s.cx=m.r32(s.cx);
        s.ax=with_al(s.ax,m.r8(s.cx+0x77u));
        if((s.ax&0xffu)!=0){s.dx=m.r32(s.cx);call(m,s,f,op,m.r32(s.dx+0x144u));}
        ++s.si;
    } while(s32(s.si)<s32(s.bx));
    s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);done(m,s,f,0);
}
void f_22e360(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.si); s.si=s.cx; f.push(m,s.di); s.di=0;
    auto n=m.r32(s.si+0xd0u); s.ax=n; if(nonpos(n)){s.di=f.pop(m);s.si=f.pop(m);done(m,s,f,4);return;}
    f.push(m,s.bx);s.bx=m.r32(f.sp+16u);
    do {
        auto arr=m.r32(s.si+0xccu); s.ax=m.r32(arr+s.di*4u);
        if(s.ax){s.dx=m.r32(s.si);f.push(m,s.ax);f.push(m,0x00a28820u);f.push(m,s.bx);s.cx=s.si;call(m,s,f,op,m.r32(s.dx+0x25cu));}
        n=m.r32(s.si+0xd0u); s.ax=n; ++s.di;
    } while(s32(s.di)<s32(n));
    s.bx=f.pop(m);s.di=f.pop(m);s.si=f.pop(m);done(m,s,f,4);
}
void f_25ea10(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.bx);f.push(m,s.si);f.push(m,s.di);s.di=m.r32(f.sp+16u);s.si=0;s.bx=s.cx;
    s.ax=with_ax(s.ax,m.r16(s.di));
    while((s.ax&0xffffu)!=0) {
        s.dx=m.r32(s.bx);f.push(m,s.ax);s.cx=s.bx;s.di+=2u;call(m,s,f,op,m.r32(s.dx+4u));
        s.si+=s.ax+1u;s.ax=with_ax(s.ax,m.r16(s.di));
    }
    s.ax=s.si;s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);done(m,s,f,4);
}
void f_2917a0(Memory& m,State& s,Frame& f,const Operations& op) {
    f.sp-=8u;
    auto count=m.r32(f.sp+12u);s.ax=count;f.push(m,s.bx);f.push(m,s.bp);f.push(m,s.si);f.push(m,s.di);
    s.di=s.dx;s.bx=with_al(s.bx,0);s.si=0;m.w32(f.sp+20u,s.cx);m.w16(s.di,0);
    if(s32(count)<=0) {m.w16(s.di+s.si*2u,0);s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=(s.ax&0xffffff00u)|std::uint8_t(s.bx);s.bx=f.pop(m);f.sp+=8u;done(m,s,f,4);return;}
    s.bp=s.di;
    for(;;) {
        s.cx=m.r32(f.sp+20u);s.ax=m.r32(s.cx);s.dx=f.sp+0x12u;f.push(m,2);f.push(m,s.dx);call(m,s,f,op,m.r32(s.ax+8u));
        if(s.ax!=2u) {m.w16(s.di+s.si*2u,0);s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=(s.ax&0xffffff00u)|1u;s.bx=f.pop(m);f.sp+=8u;done(m,s,f,4);return;}
        auto ch=m.r16(f.sp+0x12u);s.ax=with_ax(s.ax,ch);if(ch==0x0au){m.w16(s.di+s.si*2u,0);break;}
        if(ch!=0x0du){m.w16(s.bp,ch);++s.si;s.bp+=2u;}
        if(s32(s.si)>=s32(m.r32(f.entry_sp+4u))){m.w16(s.di+s.si*2u,0);break;}
    }
    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=(s.ax&0xffffff00u)|std::uint8_t(s.bx);s.bx=f.pop(m);f.sp+=8u;done(m,s,f,4);
}
void f_2963d0(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.si);f.push(m,s.di);s.di=s.cx;s.si=0x00aa5420u;s.ax=m.r32(s.di);f.push(m,s.si);s.cx=s.di;call(m,s,f,op,m.r32(s.ax+0x34u));
    do { s.si+=0x60u; if(s32(s.si)>=s32(0x00aa5d80u))break; s.ax=m.r32(s.di);f.push(m,s.si);s.cx=s.di;call(m,s,f,op,m.r32(s.ax+0x34u)); } while(true);
    s.di=f.pop(m);s.si=f.pop(m);done(m,s,f,0);
}
void f_2eb9f0(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.bx);f.push(m,s.bp);f.push(m,s.si);f.push(m,s.di);s.di=s.cx;s.bp=s.dx;s.si=0;s.bx=m.r32(s.di+0x10u);
    if(nonpos(s.bx)){s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.bx=f.pop(m);done(m,s,f,4);return;}
    do {auto arr=m.r32(s.di+4u);s.ax=arr;s.dx=m.r32(f.entry_sp+4u);s.cx=m.r32(arr+s.si*4u);call(m,s,f,op,s.bp);++s.si;}while(s32(s.si)<s32(s.bx));
    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.bx=f.pop(m);done(m,s,f,4);
}
void f_2eba70(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.bx);f.push(m,s.bp);f.push(m,s.si);f.push(m,s.di);s.di=s.cx;s.si=0;s.bx=s.dx;s.bp=m.r32(s.di+0x10u);
    if(s32(s.bp)<=0){s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=(s.ax&0xffffff00u)|1u;s.bx=f.pop(m);done(m,s,f,4);return;}
    do {s.ax=m.r32(s.di+4u);s.dx=m.r32(f.entry_sp+4u);s.cx=m.r32(s.ax+s.si*4u);call(m,s,f,op,s.bx);if((s.ax&0xffu)==0)break;++s.si;}while(s32(s.si)<s32(s.bp));
    bool stopped=(s.ax&0xffu)==0;
    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=(s.ax&0xffffff00u)|(stopped?0u:1u);s.bx=f.pop(m);done(m,s,f,4);
}
void f_2ebab0(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.bx);f.push(m,s.bp);f.push(m,s.si);f.push(m,s.di);s.di=s.cx;s.si=0;s.bx=s.dx;s.bp=m.r32(s.di+0x10u);
    if(s32(s.bp)<=0){s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=s.ax&0xffffff00u;s.bx=f.pop(m);done(m,s,f,4);return;}
    do {s.ax=m.r32(s.di+4u);s.dx=m.r32(f.entry_sp+4u);s.cx=m.r32(s.ax+s.si*4u);call(m,s,f,op,s.bx);if((s.ax&0xffu)!=0)break;++s.si;}while(s32(s.si)<s32(s.bp));
    bool stopped=(s.ax&0xffu)!=0;
    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=(s.ax&0xffffff00u)|(stopped?1u:0u);s.bx=f.pop(m);done(m,s,f,4);
}
void f_3708d3(Memory& m,State& s,Frame& f,const Operations& op) {
    f.push(m,s.si);s.si=m.r32(f.sp+8u);
    while(s.si<m.r32(f.sp+12u)){s.ax=m.r32(s.si);if(s.ax)call(m,s,f,op,s.ax);s.si+=4u;}
    s.si=f.pop(m);done(m,s,f,0);
}
}

const std::array<Entry,13>& entries_a(){static const std::array<Entry,13> a{{
 {0x0000aed0u,f_aed0},{0x0000af00u,f_af00},{0x001b03e0u,f_1b03e0},
 {0x00209c70u,f_209c70},{0x00209ca0u,f_209ca0},{0x0022e360u,f_22e360},
 {0x0025ea10u,f_25ea10},{0x002917a0u,f_2917a0},{0x002963d0u,f_2963d0},
 {0x002eb9f0u,f_2eb9f0},{0x002eba70u,f_2eba70},{0x002ebab0u,f_2ebab0},{0x003708d3u,f_3708d3}}};return a;}
} // namespace ra2::recovered::indirect_b32
