#include "leaf_b57_b.hpp"
#include <algorithm>
#include <cstdint>
#include <initializer_list>
namespace ra2::recovered::leaf {
namespace {
inline std::int32_t signed16(std::uint32_t v){return s32(sx16(v));}
}

// RVA 0x36a900: four in/out integers are addressed through the first four
// stack words; the last two words are the exclusive right/bottom bounds.
std::uint32_t fun_0076a900(Memory&m,const Inputs&i){
    const auto px=i.arg[0],py=i.arg[1],pw=i.arg[2],ph=i.arg[3];
    auto x=m.r32(px),y=m.r32(py),w=m.r32(pw),h=m.r32(ph);
    auto right=x+w,bottom=y+h;
    std::uint32_t mx=0,my=0;
    auto shld1=[](std::uint32_t dst,std::uint32_t src){return (dst<<1)|(src>>31);};
    mx=shld1(mx,x); my=shld1(my,right);
    auto dx=x-i.arg[4],dr=right-i.arg[4]; --dx;--dr;
    mx=shld1(mx,dx);my=shld1(my,dr);
    mx=shld1(mx,y); my=shld1(my,bottom);
    auto dy=y-i.arg[5],db=bottom-i.arg[5];--dy;--db;
    mx=shld1(mx,dy);my=shld1(my,db);
    auto cl=(mx&0xffu)^5u,dl=(my&0xffu)^5u;
    if(cl&dl)return 0xffffffffu;
    if((cl|dl)==0)return 0;
    if(cl&8u){auto cx=m.r32(px);m.w32(px,0);m.w32(pw,m.r32(pw)+cx);}
    if(cl&2u){auto cy=m.r32(py);m.w32(py,0);m.w32(ph,m.r32(ph)+cy);}
    if(dl&4u){auto nw=i.arg[4]-m.r32(px);m.w32(pw,nw);if(s32(nw)<=0)return 0xffffffffu;}
    if(dl&1u){auto nh=i.arg[5]-m.r32(py);m.w32(ph,nh);if(s32(nh)<=0)return 0xffffffffu;}
    return 1;
}

// RVA 0x14d560: scan 16-byte records from the supplied starting index. Each
// record's first two dwords are packed signed endpoint pairs; +0xc is a skip tag.
std::uint32_t fun_0054d560(Memory&m,const Inputs&i){
    auto index=i.arg[2]; const auto count=m.r32(i.cx+0x5c);
    if(s32(index)>=s32(count))return 0xffffffffu;
    auto record=m.r32(i.cx+0x50)+index*16u;
    const auto p=i.arg[0];const auto px=signed16(m.r16(p)),py=signed16(m.r16(p+2));
    const auto tolerance=i.arg[1];
    for(;s32(index)<s32(count);++index,record+=16u){
        if(m.r32(record+0xc)!=0)continue;
        auto a=m.r32(record),b=m.r32(record+4);
        auto ax=signed16(a),ay=signed16(a>>16),bx=signed16(b),by=signed16(b>>16);
        if(ax==bx){
            if(py<ay||py>by)continue;
            auto dist=static_cast<std::uint32_t>(px-ax); if(dist&0x80000000u)dist=0u-dist;
            if(s32(dist)<=s32(tolerance))return index;
        }else{
            if(px>bx||px<ax)continue;
            auto dist=static_cast<std::uint32_t>(py-ay); if(dist&0x80000000u)dist=0u-dist;
            if(s32(dist)<=s32(tolerance))return index;
        }
    }
    return 0xffffffffu;
}

// RVA 0x2343f0: byte RGB input, output H/S/V-like packed triple. All
// divisions are guarded by the original zero-maximum / zero-span branches.
std::uint32_t fun_006343f0(Memory&m,const Inputs&i){
    const auto r=m.r8(i.cx),g=m.r8(i.cx+1),b=m.r8(i.cx+2);
    const auto hi=std::max({r,g,b}),lo=std::min({r,g,b}),span=hi-lo;
    std::uint32_t hue=0,sat=0;
    if(hi!=0&&span!=0){
        sat=(span*255u)/hi;
        if(sat!=0){
            const auto qr=((hi-r)*255u)/span,qg=((hi-g)*255u)/span,qb=((hi-b)*255u)/span;
            std::uint32_t sector;
            if(hi==r){ if(lo==g)sector=qb+0x500u; else sector=0x100u-qg; }
            else if(hi==g){ if(lo==b)sector=qr+0x100u; else sector=0x300u-qb; }
            else { if(lo==r)sector=qg+0x300u; else sector=0x500u-qr; }
            hue=sector/6u;
        }
    }
    const auto out=i.arg[0];m.w8(out,hue);m.w8(out+1,sat);m.w8(out+2,hi);
    return out;
}

// RVA 0x5f160: ordered field initialization and conditional nested lookup.
std::uint32_t fun_0045f160(Memory&m,const Inputs&i){
    const auto p=i.cx,src=i.arg[0],secondary=i.arg[2];
    m.w32(p+0xf4,i.arg[1]);m.w32(p+0xf8,i.arg[5]);m.w32(p+0x110,i.arg[4]);
    m.w8(p+0xcc,i.arg[6]);m.w32(p+0x6c,i.arg[3]);
    m.w32(p+0x98,src);m.w32(p+0x9c,secondary);
    m.w8(p+0x114,0);m.w8(p+0x115,m.r8(src+0x2c6));
    std::uint32_t result=src;
    if(m.r8(src+0x279)!=0&&secondary!=0){
        auto q=m.r32(secondary+0x1b4);result=m.r32(q+0x15f40);m.w32(p+0xfc,result);
    }else m.w32(p+0xfc,0xffffffffu);
    m.w32(p+0x138,0x100);m.w32(p+0x13c,0);m.w8(p+0x140,0);
    return result;
}

// RVA 0x137710: update the ring sample and age every one of its 32 slots.
std::uint32_t fun_00537710(Memory&m,const Inputs&i){
    const auto p=i.cx;
    auto sample=m.r32(p+4);
    auto idx=m.r32(p+0xc);
    if(sample!=0){
        const auto s=sample+0x88u, a=m.r32(s),b=m.r32(s+4),c=m.r32(s+8);
        auto slot=p+(idx+1u)*16u;
        if(m.r32(slot)!=a||m.r32(slot+4)!=b||m.r32(slot+8)!=c){
            idx-=1u;if(s32(idx)<0)idx=31u;
            m.w32(p+0xc,idx);slot=p+(idx+1u)*16u;
            m.w32(slot+0xc,0xffu);m.w32(slot,a);m.w32(slot+4,b);m.w32(slot+8,c);
        }
    }
    for(unsigned step=0;step<32;++step){
        auto n=(idx+step)&31u;auto agep=p+(n+1u)*16u+0xcu;
        auto age=m.r32(agep)-m.r32(p+8);
        m.w32(agep,s32(age)<0?0u:age);
    }
    return idx;
}

// RVA 0x7fea0: clear per-item state for each positive signed count, then
// clear the fixed scalar tail. The caller contract bounds counts to mapped arrays.
std::uint32_t fun_0047fea0(Memory&m,const Inputs&i){
    const auto p=i.cx;const auto zero=std::uint32_t{0};
    auto n=m.r32(p+4);std::uint32_t eax=n;std::uint32_t esi=0;
    for(auto off:{0x2cu,0x3cu,0x14u,0x18u,0x1cu,0x20u,0x28u,0x38u})m.w32(p+off,zero);
    if(s32(n)>0){
        eax=0;for(;;){
            auto base=m.r32(p+0x24),q=base+eax;auto f=m.r32(q);m.w32(q,f&~1u);
            base=m.r32(p+0x24);q=base+eax;f=m.r32(q);m.w32(q,f&~2u);
            base=m.r32(p+0x24);q=base+eax;f=m.r32(q);m.w32(q,f&~4u);
            ++esi;
            base=m.r32(p+0x24);m.w32(base+eax+4u,zero);
            base=m.r32(p+0x24);m.w32(base+eax+8u,zero);
            base=m.r32(p+0x24);m.w32(base+eax+0xcu,zero);
            base=m.r32(p+0x24);m.w32(base+eax+0x10u,zero);
            base=m.r32(p+0x24);m.w32(base+eax+0x18u,zero);
            auto external=m.r32(p+0x30);m.w32(external+esi*4u-4u,zero);
            eax+=0x20u;n=m.r32(p+4);if(s32(esi)>=s32(n))break;
        }
    }
    n=m.r32(p+8);eax=n;esi=0;
    if(s32(n)>0){
        eax=0;for(;;){
            auto base=m.r32(p+0x34),q=base+eax;auto f=m.r32(q);m.w32(q,f&~1u);
            base=m.r32(p+0x34);q=base+eax;f=m.r32(q);m.w32(q,f&~2u);
            base=m.r32(p+0x34);q=base+eax;f=m.r32(q);m.w32(q,f&~4u);
            ++esi;
            base=m.r32(p+0x34);m.w32(base+eax+4u,zero);
            base=m.r32(p+0x34);m.w32(base+eax+0xcu,zero);
            auto external=m.r32(p+0x40);m.w32(external+esi*4u-4u,zero);
            eax+=0x14u;n=m.r32(p+8);if(s32(esi)>=s32(n))break;
        }
    }
    for(auto off:{0x44u,0x48u,0x4cu,0x54u})m.w32(p+off,zero);
    return eax;
}
}
