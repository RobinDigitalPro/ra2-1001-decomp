#include "recovery_b1711.hpp"
#include "recovery_b1711_methods.hpp"
#include <cstdint>

namespace ra2::delivery::query51090 {
using namespace detail;

void preflight(Memory&m,unsigned self){
    const U type=m.r32(self+0x418u),owner=m.r32(self+0x1b4u);
    const U rules=m.r32(0x821b88u),table=m.r32(0x81a958u);
    need(m.r32(self)==0x787bbcu&&m.r32(type)==0x7881f8u&&m.r32(owner)==0x78dde0u);
    need(m.r32(self+0x88u)==0xf00u&&m.r32(self+0x8cu)==0xf00u);
    (void)m.r32(self+0x90u);
    need(m.r32(type+0xc78u)==0&&m.r32(0x7bac08u)==1&&m.r32(0x7bac60u)==1);
    need(m.r32(rules+0x10c8u)==0&&m.r32(owner+0x30u)<=31u);
    const U v=owner+0x5610u,mask=1u<<m.r32(owner+0x30u);
    need(m.r32(v)==0x7875a0u&&m.r32(0x7875b0u)==0x42d120u);
    need(m.r32(v+4u)==0&&m.r32(v+8u)==0&&m.r32(v+0x10u)==0);
    need(m.r8(v+0xcu)==1&&m.r8(v+0xdu)==0&&m.r32(v+0x14u)==10);
    need(m.r32(0x81a95cu)==0x40000u);
    struct Span{std::uint64_t begin,end;};
    std::array<Span,25> spans{};
    spans[0]={self,std::uint64_t(self)+0x41cu};
    spans[1]={type,std::uint64_t(type)+0x1400u};
    spans[2]={owner,std::uint64_t(owner)+0x5668u};
    spans[3]={rules,std::uint64_t(rules)+0x10ccu};
    spans[4]={table,std::uint64_t(table)+0x100000u};
    spans[5]={0x81a820u,0x81a960u};
    spans[6]={0x7bac08u,0x7bac0cu};spans[7]={0x7bac60u,0x7bac64u};
    spans[8]={0x7875b0u,0x7875b4u};
    unsigned k=9;
    for(U x=14;x<18;++x)for(U y=14;y<18;++y){
        const U cell=m.r32(table+4u*(x+512u*y));
        need(cell!=0&&m.r32(cell)==0x788b04u&&m.r32(cell+0xe4u)==0);
        need(m.r32(cell+0x24u)==(x|(y<<16)));
        need((m.r32(cell+0xdcu)&mask)==((x==15&&y==15)?mask:0u));
        spans[k++]={cell,std::uint64_t(cell)+0x180u};
    }
    for(unsigned i=0;i<spans.size();++i){
        need(spans[i].begin!=0&&spans[i].end<=0x100000000ull);
        for(unsigned j=0;j<i;++j)need(spans[i].end<=spans[j].begin||spans[j].end<=spans[i].begin);
    }
    // Caller additionally binds actual backing/lifetimes/permissions, complete
    // public preimages and the disjoint actual native stack before observation.
}

static U selected_root(Memory&m,State&s,Frame&f,U flags){
    f.sp=integer::sub(f.sp,0x30u,32,flags);                  // 451090
    s.ax=m.r32(0x821b88u);f.push(m,s.bx);f.push(m,s.bp);
    f.push(m,s.si);f.push(m,s.di);
    s.di=m.r32(s.ax+0x10c8u);s.si=s.cx;m.w32(f.sp+0x14u,s.si);
    s.bx=s.di+s.di;s.cx=m.r32(s.si+0x418u);
    f.push(m,0x4510b6u);width(m,s,f,0x4510b6u);
    s.cx=m.r32(s.si+0x418u);s.bp=s.ax;f.push(m,0);
    s.bp=integer::add(s.bp,s.bx,32,flags);
    f.push(m,0x4510c7u);height0(m,s,f,flags,0x4510c7u);
    s.cx=m.r32(s.si+0x1b4u);s.ax=integer::add(s.ax,s.bx,32,flags);
    m.w32(f.sp+0x10u,s.ax);s.ax=1;s.cx=m.r32(s.cx+0x30u);s.dx=s.si+0x88u;
    s.ax=integer::shift(s.ax,s.cx,32,flags,integer::Shift::left);m.w32(f.sp+0x2cu,s.ax);
    s.ax=m.r32(s.dx);s.cx=m.r32(s.dx+4u);s.dx=m.r32(s.dx+8u);m.w32(f.sp+0x3cu,s.dx);
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0;
    s.dx=integer::logical(s.dx&255u,32,flags);s.ax=integer::add(s.ax,s.dx,32,flags);
    s.ax=integer::shift(s.ax,8,32,flags,integer::Shift::arithmetic_right);m.w16(f.sp+0x34u,s.ax);
    s.ax=s.cx;s.dx=(s.ax&0x80000000u)?0xffffffffu:0;
    s.dx=integer::logical(s.dx&255u,32,flags);s.ax=integer::add(s.ax,s.dx,32,flags);
    s.ax=integer::shift(s.ax,8,32,flags,integer::Shift::arithmetic_right);m.w16(f.sp+0x36u,s.ax);
    s.ax=m.r32(f.sp+0x34u);
    // 45111B's upper WORD is unproduced and provably dead. Load only CX;
    // do not seed, overwrite or exclude B38..39 from full byte comparison.
    s.cx=m.r16(f.sp+0x36u);
    s.ax=integer::sub(s.ax,s.di,32,flags);s.ax=sx16(s.ax);s.bx=s.ax;
    s.cx=integer::sub(s.cx,s.di,32,flags);s.dx=s.ax+s.bp;
    m.w16(f.sp+0x26u,s.cx);(void)integer::sub(s.bx,s.dx,32,flags);
    m.w32(f.sp+0x20u,s.ax);m.w32(f.sp+0x28u,s.dx);
    while(integer::condition("JL",flags)){
        s.si=m.r32(f.sp+0x10u);s.dx=sx16(s.cx);s.dx=integer::add(s.dx,s.si,32,flags);
        m.w32(f.sp+0x1cu,s.dx);s.dx=m.r32(f.sp+0x1cu);s.si=sx16(s.cx);
        (void)integer::sub(s.si,s.dx,32,flags);
        if(integer::condition("JL",flags)){
            s.ax=m.r32(f.sp+0x2cu);s.ax=~s.ax;m.w32(f.sp+0x30u,s.ax);
            do{
                s.ax=f.sp+0x18u;s.cx=0x81a820u;f.push(m,s.ax);
                m.w16(f.sp+0x1cu,s.bx);m.w16(f.sp+0x1eu,s.si);
                f.push(m,0x451177u);map_cell(m,s,f,flags,0x451177u);
                s.cx=m.r32(f.sp+0x30u);s.dx=m.r32(s.ax+0xdcu);
                s.ax=integer::add(s.ax,0xdcu,32,flags);
                s.dx=integer::logical(s.dx&s.cx,32,flags);s.si=integer::increment(s.si,32,flags);
                m.w32(s.ax,s.dx);s.ax=m.r32(f.sp+0x1cu);
                (void)integer::sub(s.si,s.ax,32,flags);
            }while(integer::condition("JL",flags));
            s.ax=m.r32(f.sp+0x20u);s.cx=(s.cx&0xffff0000u)|m.r16(f.sp+0x26u);
        }
        s.dx=m.r32(f.sp+0x28u);s.bx=integer::increment(s.bx,32,flags);
        (void)integer::sub(s.bx,s.dx,32,flags);
    }
    s.si=m.r32(f.sp+0x14u);s.dx=s.di+s.di;s.bx=s.ax;m.w32(f.sp+0x30u,s.dx);
    s.dx=integer::add(s.dx,s.ax,32,flags);s.bx=integer::sub(s.bx,s.di,32,flags);
    s.bp=integer::add(s.bp,s.dx,32,flags);(void)integer::sub(s.bx,s.bp,32,flags);
    m.w32(f.sp+0x34u,s.bp);
    while(integer::condition("JL",flags)){
        s.dx=sx16(s.cx);s.bp=s.dx;s.bp=integer::sub(s.bp,s.di,32,flags);
        s.di=m.r32(f.sp+0x30u);s.dx=integer::add(s.dx,s.di,32,flags);
        s.di=m.r32(f.sp+0x10u);m.w32(f.sp+0x18u,s.bp);s.bp=s.dx+s.di;
        s.di=m.r32(f.sp+0x18u);(void)integer::sub(s.di,s.bp,32,flags);
        while(integer::condition("JL",flags)){
            s.ax=f.sp+0x1cu;s.cx=0x81a820u;f.push(m,s.ax);
            m.w16(f.sp+0x20u,s.bx);m.w16(f.sp+0x22u,s.di);
            f.push(m,0x4511f9u);map_cell(m,s,f,flags,0x4511f9u);
            s.cx=s.ax;f.push(m,0x451200u);empty_occupant(m,s,f,flags,0x451200u);
            (void)integer::logical(s.ax,32,flags);need(s.ax==0); // real null, excludes 450DB0
            s.di=integer::increment(s.di,32,flags);(void)integer::sub(s.di,s.bp,32,flags);
        }
        s.ax=m.r32(f.sp+0x20u);s.cx=(s.cx&0xffff0000u)|m.r16(f.sp+0x26u);
        s.dx=m.r32(f.sp+0x34u);s.bx=integer::increment(s.bx,32,flags);
        (void)integer::sub(s.bx,s.dx,32,flags);
    }
    s.dx=m.r32(f.sp+0x28u);s.bp=s.ax-1u;s.dx=integer::add(s.dx,2,32,flags);
    (void)integer::sub(s.bp,s.dx,32,flags);m.w32(f.sp+0x30u,s.dx);
    if(integer::condition("JL",flags)){
        s.ax=sx16(s.cx);s.cx=s.ax-1u;m.w32(f.sp+0x34u,s.cx);
        s.cx=m.r32(f.sp+0x10u);s.bx=s.ax+s.cx+2u;
        do{
            s.di=m.r32(f.sp+0x34u);(void)integer::sub(s.di,s.bx,32,flags);
            while(integer::condition("JL",flags)){
                m.w16(f.sp+0x28u,s.bp);s.ax=m.r32(s.si+0x1b4u);m.w16(f.sp+0x2au,s.di);
                s.dx=m.r32(f.sp+0x28u);m.w32(f.sp+0x10u,s.dx);s.cx=m.r32(s.ax+0x30u);
                s.dx=f.sp+0x10u;f.push(m,s.cx);f.push(m,s.dx);s.cx=0x81a820u;
                f.push(m,0x451287u);map_cell(m,s,f,flags,0x451287u);
                s.cx=s.ax;f.push(m,0x45128eu);disabled_occupancy(m,s,f,flags,0x45128eu);
                (void)integer::sub(s.ax,255u,32,flags);need(s.ax!=255u);
                (void)integer::logical(s.ax,32,flags);need(integer::condition("JLE",flags));
                s.si=m.r32(s.si+0x1b4u);s.ax=f.sp+0x10u;s.si=integer::add(s.si,0x5610u,32,flags);
                f.push(m,s.ax);s.cx=s.si;s.dx=m.r32(s.si);need(m.r32(s.dx+0x10u)==0x42d120u);
                f.push(m,0x451378u);empty_search(m,s,f,flags,0x451378u);
                (void)integer::sub(s.ax,0xffffffffu,32,flags);need(s.ax==0xffffffffu);
                s.ax=f.sp+0x10u;s.cx=0x81a820u;f.push(m,s.ax);
                f.push(m,0x4513adu);map_cell(m,s,f,flags,0x4513adu);
                s.cx=m.r32(f.sp+0x2cu);s.dx=m.r32(s.ax+0xdcu);
                s.ax=integer::add(s.ax,0xdcu,32,flags);s.cx=~s.cx;
                s.dx=integer::logical(s.dx&s.cx,32,flags);m.w32(s.ax,s.dx);
                s.si=m.r32(f.sp+0x14u);s.di=integer::increment(s.di,32,flags);
                (void)integer::sub(s.di,s.bx,32,flags);
            }
            s.dx=m.r32(f.sp+0x30u);s.bp=integer::increment(s.bp,32,flags);
            (void)integer::sub(s.bp,s.dx,32,flags);
        }while(integer::condition("JL",flags));
    }
    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.bx=f.pop(m);
    f.sp=integer::add(f.sp,0x30u,32,flags);
    need(f.sp==f.entry_sp&&f.pop(m)==f.outer_return);return flags;
}

Result run(Memory&m,unsigned entry,unsigned char*storage,unsigned size,
           const NativeState&i,const fp::Image&incoming){
    need(entry>=0x1b0u&&entry<=0xffffffbbu&&size==500u);
    need(reinterpret_cast<std::uintptr_t>(storage)==std::uintptr_t(entry-0x1b0u));
    State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.bx=i.bx;s.bp=i.bp;s.si=i.si;s.di=i.di;
    s.arithmetic_flags=i.flags;s.fp.image=incoming;
    Frame f{entry,entry,m.r32(entry)};
    s.arithmetic_flags=selected_root(m,s,f,i.flags);
    Result r{s.ax,s,{}};for(unsigned k=0;k<16;++k)r.words[k]=m.r32(entry+4u+4u*k);
    return r;
}
}
