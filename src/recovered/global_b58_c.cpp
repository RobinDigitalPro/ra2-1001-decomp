#include "recovered/global_b58_c.hpp"

namespace ra2::recovered::global_b26 {
std::uint32_t fun_004ae5e0(Memory& m,const Inputs& i) {
    auto esi=(m.r8(i.cx)&255u)+i.dx;
    auto edx=(m.r8(i.cx+1)&255u)+i.arg[0];
    auto eax=(m.r8(i.cx+2)&255u)+i.arg[1];
    std::uint32_t ecx=0,edi=0;
    if(s32(esi)<255){}else{edi=1;ecx=esi-255u;}
    if(s32(edx)>=255){++edi;ecx+=edx-255u;}
    if(s32(eax)>=255){++edi;ecx+=eax-255u;}
    if(edi && s32(edi-3u)<0) {
        if(edi==1) ecx=sar(ecx,1);
        if(s32(esi)<255)esi+=ecx;
        if(s32(edx)<255)edx+=ecx;
        if(s32(eax)<255)eax+=ecx;
    }
    if(s32(eax)>255)eax=255;
    if(s32(edx)>255)edx=255;
    if(s32(esi)>255)esi=255;
    const auto rs=m.r32(0x83b2f4),rl=m.r32(0x83b2f0);
    const auto gs=m.r32(0x83b2fc),gl=m.r32(0x83b2f8);
    const auto bs=m.r32(0x83b2ec),bl=m.r32(0x83b2e8);
    return (sar(eax,rs)&0xffffffffu) << (rl&31u) |
           (sar(edx,gs)&0xffffffffu) << (gl&31u) |
           (sar(esi,bs)&0xffffffffu) << (bl&31u);
}

std::uint32_t fun_00557450(Memory& m,const Inputs& i) {
    auto eax=i.arg[1]&255u;
    auto ebx=i.arg[0];
    auto edx=sx16(m.r16(ebx+2));
    auto edi=sx16(m.r16(ebx));
    std::uint32_t esi=0,ebp=0;
    if(eax) {
        eax=(edx<<9)+edi;
        if(s32(eax)>=0 && eax<0x40000u) {
            esi=m.r32(0x81a958);
            eax=m.r32(esi+eax*4u);
            if(eax==0) {
                eax=m.r32(ebx);m.w32(0xa57634,eax);eax=0x00a57610;
            }
        } else {
            eax=m.r32(ebx);m.w32(0xa57634,eax);eax=0x00a57610;
        }
        ebx=(ebx&0xffffff00u)|(m.r8(eax+0x11c)&255u);
        esi=sx8(m.r8(eax+0x11b));
        if(ebx&255u) {
            eax=m.r32(i.cx+0xfc);ebx=m.r32(i.cx+0xf0);
            auto limit=ebx+eax*2u+4u;
            auto sum=edx+edi;
            limit+=esi;
            if(s32(sum)<s32(limit))++esi;
        }
    }
    ebx=m.r32(i.cx+0xfc);eax=m.r32(i.cx+0xf0);ebp=edx+edi;
    ebx=eax+ebx*2u;ebx+=esi;
    if(s32(ebp)<=s32(ebx)) {eax=(eax&0xffffff00u);return eax;}
    ebx=m.r32(i.cx+0x104);ebp=m.r32(i.cx+0xfc);ebx+=ebp;
    ebx=eax+ebx*2u+2u;ebx+=esi;esi=edx+edi;
    if(s32(esi)>s32(ebx)) {eax&=0xffffff00u;return eax;}
    esi=m.r32(i.cx+0xf8);auto ecx=m.r32(i.cx+0x100);ecx+=esi;
    ebx=edi;ecx<<=1;ecx-=eax;ebx-=edx;
    if(s32(ebx)>=s32(ecx)) {eax&=0xffffff00u;return eax;}
    ecx=esi+esi;edx-=edi;eax-=ecx;
    if(s32(edx)>=s32(eax)) {eax&=0xffffff00u;return eax;}
    return (eax&0xffffff00u)|1u;
}

std::uint32_t fun_004b86a0(Memory& m,const Inputs& i) {
    const auto obj=i.cx;
    const auto p2=i.arg[0];
    auto ax=m.r16(obj),bp=m.r16(obj+0x14);
    if(ax==m.r16(i.arg[0]))return 0;
    std::uint32_t oldx=m.r32(obj),newx=oldx;
    if(s32(sx16(bp))>0) {
        auto edi=m.r32(obj+8),edx=m.r32(obj+0x10),ebx=m.r32(0xa2896c);
        if(edi!=0xffffffffu) {
            auto delta=ebx-edi;
            if(s32(delta)>=s32(edx))goto stored;
            edx-=delta;
        }
        if(edx==0)goto stored;
        ax=static_cast<std::uint16_t>(ax-m.r16(obj+4));
        auto esi=sx16(ax);
        auto magnitude=s32(esi)<0?std::uint32_t(0u-esi):esi;
        auto q=idiv_quotient(magnitude,sx16(bp));
        newx=oldx;
        if(s32(sx16(q&0xffffu))>0) {
            edi=m.r32(obj+8);edx=m.r32(obj+0x10);
            if(edi!=0xffffffffu){
                ebx-=edi;edi=ebx;
                if(s32(edi)>=s32(edx))edi=0;
                else {edx-=edi;edi=edx;}
            } else edi=edx;
            auto step=idiv_quotient(std::uint32_t(esi),sx16(q&0xffffu));
            newx=(newx&0xffff0000u)|std::uint16_t(std::uint16_t(newx)-std::uint16_t(step*edi));
        }
    }
stored:
    m.w32(obj+4,newx);
    auto endpoint=m.r32(p2);
    m.w32(obj,endpoint);
    if(s32(sx16(bp))>0) {
        auto delta=std::uint16_t(endpoint-newx);
        auto magnitude=sx16(delta);if(s32(magnitude)<0)magnitude=0u-magnitude;
        auto divisor=sx16(bp);
        // The original signed IDIV faults for zero divisor; such states are excluded.
        auto quotient=std::uint32_t(magnitude/divisor);
        m.w32(obj+8,m.r32(0xa2896c));
        m.w32(obj+12,i.stack_minus8);
        m.w32(obj+16,quotient);
    }
    return 1;
}

std::uint32_t fun_005676f0(Memory& m,const Inputs& i) {
    std::uint32_t best_index=0xffffffffu,best_score=0,index=0,base=0x7cab9c;
    do {
        auto left=(i.dx<<5)+0x7cab9cu,right=(i.cx<<5)+0x7cab9cu;
        std::uint32_t allowed=1,score=0;
        for(unsigned k=0;k<8;++k) {
            auto a=m.r32(right+4*k),b=m.r32(left+4*k),candidate=m.r32(base+4*k);
            if((a==2 || b==2) && candidate==1)allowed=0;
            if(a==candidate && b==candidate && candidate==1)++score;
        }
        if(allowed && s32(score-best_score)>0){best_score=score;best_index=index;}
        ++index;base+=32;
    } while(s32(base-0x7cad1cu)<0);
    return best_index;
}

std::uint32_t fun_006dd700(Memory& m,const Inputs& i) {
    auto eax=i.arg[0];
    if(eax==0xfffffffdu||eax==0xfffffffeu)return 1;
    if(eax>=m.r32(i.cx+0x24))return 0;
    auto table=m.r32(i.cx+0x18);eax=m.r32(table+eax*4u);
    if(!m.r8(eax+0x28a)||!m.r8(eax+0x288))return 0;
    auto edx=m.r32(0xa1e0e4);
    if(edx) {
        auto ecx=m.r32(eax+0x28c);
        if(ecx!=0xffffffffu) {
            auto obj=m.r32(edx+0x34);auto val=m.r32(obj+0xbc);
            if(val!=ecx)return 0;
        }
    }
    if(m.r32(0xa255c8))return 1;
    auto obj=m.r32(0xa255c0);
    return s32(m.r32(obj+0x834))>=s32(m.r32(eax+0x280))?1u:0u;
}

std::uint32_t fun_004f4900(Memory& m,const Inputs& i) {
    const auto obj=i.cx;
    const auto arr=m.r32(0xa9ea04);
    auto entry=m.r32(arr+m.r32(obj+0x15f40)*4u);
    auto lookup=m.r32(entry+0x330),surface=m.r32(entry+0x30c);
    auto base=m.r32(surface+4),pixels=m.r32(surface+0x174);
    std::uint32_t eax;
    if(base==1)eax=m.r8(pixels+lookup);else eax=m.r16(pixels+lookup*2u);
    auto cx=m.r16(0x83b2e8);auto edx=eax;edx=(edx&0xffff0000u)|((edx&0xffffu)>>(cx&31u));
    auto ecx=m.r32(0x83b2ec);auto dl=((edx&255u)<<(ecx&31u))&255u;
    cx=m.r16(0x83b2f8);edx=eax;edx=(edx&0xffff0000u)|((edx&0xffffu)>>(cx&31u));
    ecx=m.r32(0x83b2fc);auto dh=((edx&255u)<<(ecx&31u))&255u;
    cx=m.r16(0x83b2f0);auto al=((eax&0xffffu)>>(cx&31u))&255u;
    ecx=m.r32(0x83b2f4);al=(al<<(ecx&31u))&255u;
    m.w8(obj+0x55e9,dl);m.w8(obj+0x55ea,dh);m.w8(obj+0x55eb,al);
    const auto shifted_ax=(eax&0xffffu)>>(cx&31u);
    return (shifted_ax&0xffffff00u)|al;
}
}
