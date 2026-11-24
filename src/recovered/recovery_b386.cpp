#include "recovery_b386.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b386 {
namespace {
using global_b26::s32; using global_b26::sx16; using global_b26::sar;
constexpr std::uint32_t arena_only_init_flag = 1u;

std::uint32_t pair(std::uint32_t x,std::uint32_t y) {
    return (x&0xffffu)|((y&0xffffu)<<16);
}

bool inside(Memory& m,std::uint32_t receiver,std::uint32_t xy) {
    const auto x=sx16(xy),y=sx16(xy>>16),d=m.r32(receiver+0xf0u);
    return s32(x+y)>s32(d) && s32(x-y)<s32(d) && s32(y-x)<s32(d) &&
           s32(x+y)<=s32(d+m.r32(receiver+0xf4u)*2u);
}

std::uint32_t cell_for(Memory& m,std::uint32_t receiver,std::uint32_t xy) {
    const auto k=(sx16(xy>>16)<<9)+sx16(xy);
    if(s32(k)>=0 && k<0x40000u) {
        const auto p=m.r32(m.r32(receiver+0x138u)+k*4u);
        if(p)return p;
    }
    m.w32(0xa57634u,xy);
    return 0xa57610u;
}

// Inlined value form of 0x996a0/0x99750. The native callees receive a pointer
// to a stack-local pair; their persistent effects are exactly this scan.
void walk_at(Memory& m,std::uint32_t receiver,std::uint32_t xy,
             std::uint32_t list,std::uint32_t bit,std::uint32_t enable) {
    if((xy&0xffffu)==(m.r32(0x83a940u)&0xffffu) &&
       (xy>>16)==(m.r32(0x83a942u)&0xffffu))return;
    for(auto p=list;;p+=4u) {
        const auto delta=m.r32(p);
        if((delta&0xffffu)==0x7fffu && (delta>>16)==0x7fffu)break;
        const auto out=pair((xy&0xffffu)+(delta&0xffffu),
                            (xy>>16)+(delta>>16));
        if(inside(m,receiver,out)) {
            const auto cell=cell_for(m,receiver,out),flags=m.r32(cell+0x12cu);
            m.w32(cell+0x12cu,enable?flags|bit:flags&~bit);
        }
    }
}

// Exact 0x995f0 sentinel and +/-512 extrema behavior, with its discarded
// stack-local output represented as a C++ value rather than guest memory.
std::uint32_t bounds(Memory& m,std::uint32_t list) {
    std::int32_t maxx=-512,minx=512,maxy=-512,miny=512;
    for(auto p=list;;p+=4u) {
        const auto ux=m.r16(p),uy=m.r16(p+2u);
        if(ux==0x7fffu && uy==0x7fffu)break;
        const auto x=static_cast<std::int32_t>(sx16(ux));
        const auto y=static_cast<std::int32_t>(sx16(uy));
        if(maxx<x)maxx=x;if(minx>x)minx=x;
        if(maxy<y)maxy=y;if(miny>y)miny=y;
    }
    const auto width=std::uint32_t((maxx-minx+1)<1?1:(maxx-minx+1))&0xffffu;
    const auto height=std::uint32_t((maxy-miny+1)<1?1:(maxy-miny+1))&0xffffu;
    return width|(height<<16);
}

std::int32_t center(std::uint32_t dimension) {
    const auto dec=std::uint16_t(dimension-1u);
    const auto neg=static_cast<std::int32_t>(static_cast<std::int16_t>(std::uint16_t(0u-dec)));
    return s32(sar(std::uint32_t(neg+(neg<0?1:0)),1));
}

std::uint32_t run(Memory& m,const Inputs& i,bool second) {
    const auto list_off=second?0x1188u:0x1178u;
    const auto x_off=second?0x117eu:0x1170u;
    const auto y_off=second?0x1180u:0x1172u;
    const auto x_field=second?0x1182u:0x1174u;
    const auto y_field=second?0x1184u:0x1176u;
    const auto dst=second?0x83a7e0u:0x83a964u;
    const auto dwords=second?50u:120u;
    const auto flag=second?0x83ab60u:0x83ac64u;
    const auto bit=second?4u:2u;
    const auto receiver=i.cx;

    if(m.r32(receiver+list_off)) {
        const auto first=pair(m.r16(receiver+x_field)+m.r16(receiver+x_off),
                              m.r16(receiver+y_field)+m.r16(receiver+y_off));
        walk_at(m,receiver,first,m.r32(receiver+list_off),bit,0);
    }
    const auto source=i.arg[0];
    m.w32(receiver+x_field,m.r32(0x83a940u));
    if(!source) {m.w32(receiver+list_off,0);return 0;}
    // Positive route is explicitly the already-initialized object state; the
    // unmodeled registration seam 0x76e2ca is not entered on this route.
    if(!(m.r8(flag)&arena_only_init_flag))
        throw std::domain_error("B386 model excludes the one-time 0x76e2ca registration path");

    for(std::uint32_t n=0;n<dwords;++n)m.w32(dst+n*4u,m.r32(source+n*4u));
    m.w32(receiver+list_off,dst);
    const auto packed_bounds=bounds(m,dst);
    const auto cx=center(packed_bounds),cy=center(packed_bounds>>16);
    m.w32(receiver+x_field,pair(std::uint32_t(cx),std::uint32_t(cy)));
    const auto final_xy=pair(m.r16(receiver+x_off)+std::uint16_t(cx),
                             m.r16(receiver+y_off)+m.r16(receiver+y_field));
    // ESP+0x1c at this point is entryESP+4: the original overwrites arg0.
    i.arg[0]=final_xy;
    walk_at(m,receiver,final_xy,dst,bit,1);
    return 0;
}
}

std::uint32_t fun_00498cf0(Memory& m,const Inputs& i){return run(m,i,false);}
std::uint32_t fun_00498e50(Memory& m,const Inputs& i){return run(m,i,true);}
}
