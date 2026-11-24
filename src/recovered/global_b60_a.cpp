#include "global_b60_a.hpp"
#include <array>
#include <algorithm>
#include <cstdlib>
#include <cstdint>

namespace ra2::recovered::global_b26 {
namespace {

constexpr std::uint32_t rol(std::uint32_t x,unsigned n){return (x<<n)|(x>>(32u-n));}
std::uint32_t lo8(std::uint32_t e,std::uint32_t v){return (e&0xffffff00u)|(v&255u);}
}

// RVA 0x87800: bounded item conversion. Original cursor wrap uses the two
// descriptor dwords at 0x821fac+1c/+20, including on the no-conversion path.
std::uint32_t fun_00487800(Memory& m,const Inputs& i){
    auto ecx=i.cx, edx=i.arg[2], eax=i.arg[4];
    auto table_state=m.r32(ecx+4u);ecx=m.r32(table_state);
    if(s32(edx)<=0)return eax;
    auto ebp=i.arg[3], edi=i.arg[1], dst=i.arg[0];
    auto remaining=edx; const auto desc=m.r32(0x00821facu);
    while(remaining){
        std::uint32_t bx=m.r16(eax);
        if(s32(ebp)>=s32(bx)){} else {
            const auto byte=m.r8(edi)&255u;
            if(byte){const auto idx=m.r8(byte+ecx);const auto lookup=m.r32(i.cx+8u);const auto si=m.r16(lookup+idx*2u);m.w16(dst,si);m.w16(eax,ebp);}
        }
        const auto end=m.r32(desc+0x1cu);eax+=2;edi+=1;dst+=2;
        if(eax>=end)eax-=m.r32(desc+0x20u);
        --remaining;
    }
    return eax;
}

// RVA 0x29570: reverse scan of a signed index through the caller's coordinate map.
// The low byte of arg1 is the original mutable flag indicating prior points.
std::uint32_t fun_00429570(Memory& m,const Inputs& i){
    std::int32_t index=s32(i.arg[1]);const std::int32_t lower=s32(i.arg[2]);
    const auto array=i.arg[0],out_index=i.arg[3],out_position=i.arg[4];
    std::uint32_t position=m.r32(out_position),cursor=array+std::uint32_t(index)*4u;
    std::uint16_t cx=0,bx=0;std::uint32_t best=0;bool flagged=false;
    i.arg[1]&=0xffffff00u;
    if(index<lower){m.w32(out_index,std::uint32_t(lower));m.w32(out_position,position);return out_index;}
    while(index>=lower){
        const auto value=m.r32(cursor);
        if(value==0xfffffffeu){--index;cursor-=4u;}
        else {
            const auto slot=(value-4u)&7u;const auto row=0x00839da0u+slot*4u;
            const auto rawx=std::uint16_t(m.r16(row)),rawy=std::uint16_t(m.r16(row+2u));
            const auto si=std::uint16_t(rawx+cx),nextcx=std::uint16_t(rawy+bx);
            const auto posx=std::uint16_t(rawx+std::uint16_t(position));
            const auto posy=std::uint16_t(rawy+std::uint16_t(position>>16));
            const auto new_position=std::uint32_t(posx)|(std::uint32_t(posy)<<16);
            const auto abs_y=std::abs(std::int32_t(std::int16_t(nextcx)));
            const auto abs_x=std::abs(std::int32_t(std::int16_t(si)));
            const auto magnitude=std::uint32_t(std::max(abs_x,abs_y));
            if(magnitude>best){
                if(flagged){const auto outslot=(slot-4u)&7u;const auto outrow=0x00839da0u+outslot*4u;
                    const auto outdx=std::uint16_t(m.r16(outrow)+posx);
                    const auto outax=std::uint16_t(m.r16(outrow+2u)+posy);
                    const auto out=std::uint32_t(outdx)|(std::uint32_t(outax)<<16);
                    m.w32(out_index,std::uint32_t(index+1));i.arg[2]=out;m.w32(out_position,out);
                    return 0x00830000u|outax;
                }
                best=magnitude;
            } else {flagged=true;i.arg[1]=(i.arg[1]&0xffffff00u)|1u;}
            cx=si;bx=nextcx;position=new_position;--index;cursor-=4u;
        }
    }
    m.w32(out_index,std::uint32_t(lower));m.w32(out_position,position);return out_index;
}
// RVA 0x1a46f0: shift an array of little-endian dwords in place.
std::uint32_t fun_005a46f0(Memory& m,const Inputs& i){
    const auto base=i.cx,shift=i.dx,count=i.arg[0];if(!shift)return i.ax;
    if(shift==32u){std::uint32_t carry=0;for(std::uint32_t k=0;k<count;++k){const auto old=m.r32(base+k*4u);m.w32(base+k*4u,carry);carry=old;}return carry;}
    if(s32(shift)<32){const auto bits=shift&31u,complement=(32u-shift)&31u,mask=~(0xffffffffu>>bits);std::uint32_t carry=0;
        if(!count)return 0xffffffffu;
        for(std::uint32_t k=0;k<count;++k){const auto old=m.r32(base+4u*k);m.w32(base+4u*k,(old<<bits)|(carry>>complement));carry=old&mask;--i.arg[0];}return 0;
    }
    const auto q=shift/32u,bits=shift&31u,other=(32u-bits)&31u;
    // The original masks the complement count too: multiples above 32 retain
    // the adjacent lower word through SHR-by-zero. Preserve this behavior.
    if(q<count){for(auto k=count-1u;k>q;--k)m.w32(base+k*4u,(m.r32(base+(k-q-1u)*4u)>>other)|(m.r32(base+(k-q)*4u)<<bits));m.w32(base+q*4u,m.r32(base)<<bits);}
    for(std::uint32_t k=0;k<std::min(q,count);++k)m.w32(base+k*4u,0);
    return q;
}

// RVA 0x381f84 selects a seeded token address or checks one seeded byte.
std::uint32_t fun_00781f84(Memory& m,const Inputs& i){
    const auto rec=i.arg[0], flags=m.r32(rec+0xcu);std::uint32_t eax=0;
    if(flags&0x100u){const auto key=m.r16(rec+8);unsigned n=0;std::uint32_t p=0x00818a98u;
        while(p<0x00818b10u&&m.r16(p)!=key){p+=10u;++n;}if(p==0x00818b10u)return 0;
        if(flags&3u)eax=0x00818aa0u+n*10u;else if(flags&0xcu)eax=0x00818a9eu+n*10u;else if(flags&0x10u)eax=0x00818a9cu+n*10u;else eax=0x00818a9au+n*10u;return eax;}
    if(flags&3u)eax=0x00818b16u+std::uint32_t(m.r16(rec+8))*8u;else if(flags&0xcu)eax=0x00818b14u+std::uint32_t(m.r16(rec+8))*8u;else if(flags&0x10u)eax=0x00818b12u+std::uint32_t(m.r16(rec+8))*8u;else eax=0x00818b10u+std::uint32_t(m.r16(rec+8))*8u;
    const auto c=m.r8(eax);return ((!c||c==0xe0u)&&m.r8(eax+1u)!=0)?eax:0u;
}

// RVA 0x26a7e0: SHA-1 compression; source words are byte-swapped before expansion.
std::uint32_t fun_0066a7e0(Memory& m,const Inputs& i){
    const auto block=i.arg[0],state=i.arg[1];std::array<std::uint32_t,80>w{};
    for(unsigned n=0;n<16;++n){const auto x=m.r32(block+4*n);w[n]=((x&0xffu)<<24)|((x&0xff00u)<<8)|((x>>8)&0xff00u)|(x>>24);}
    for(unsigned n=16;n<80;++n)w[n]=rol(w[n-3]^w[n-8]^w[n-14]^w[n-16],1);
    auto a=m.r32(state),b=m.r32(state+4),c=m.r32(state+8),d=m.r32(state+12),e=m.r32(state+16);
    for(unsigned n=0;n<80;++n){std::uint32_t f,k;if(n<20){f=(b&c)|(~b&d);k=0x5a827999u;}else if(n<40){f=b^c^d;k=0x6ed9eba1u;}else if(n<60){f=(b&c)|(b&d)|(c&d);k=0x8f1bbcdcu;}else{f=b^c^d;k=0xca62c1d6u;}const auto t=rol(a,5)+f+e+k+w[n];e=d;d=c;c=rol(b,30);b=a;a=t;}
    const auto na=m.r32(state)+a,nb=m.r32(state+4)+b,nc=m.r32(state+8)+c,nd=m.r32(state+12)+d,ne=m.r32(state+16)+e;
    m.w32(state,na);m.w32(state+4,nb);m.w32(state+8,nc);m.w32(state+12,nd);m.w32(state+16,ne);return ne;
}

// RVA 0x37e27e selects the saved calendar tables and updates clock fields.
std::uint32_t fun_0077e27e(Memory& m,const Inputs& i){
    const auto& a=i.arg;const std::uint32_t selector=a[2], dayIndex=a[3];
    std::uint32_t ecx=0,eax=0;
    const auto table=((selector&3u)==0u)?0x00818620u:0x00818654u;
    if(a[1]==1u){
        i.arg[2]=selector&3u;
        eax=m.r32(table+dayIndex*4u);ecx=eax+1u;
        const auto days=selector*0x16du+ecx+sar(selector-1u,2)-0x63dbu;
        const auto rem=std::uint32_t(std::int32_t(days)%7);
        eax=a[4];std::uint32_t adjust=eax*7u-rem+a[5];
        if(s32(rem)<s32(a[5]))ecx+=adjust-7u;else ecx+=adjust;
        if(a[4]==5u){const auto cap=m.r32(((selector&3u)==0u?0x00818624u:0x00818658u)+dayIndex*4u);if(s32(ecx)>s32(cap))ecx-=7u;}
    } else {ecx=m.r32(table+dayIndex*4u)+a[6];}
    if(a[0]==1u){m.w32(0x0081860cu,ecx);m.w32(0x00818608u,selector);eax=a[7]*60u+a[8];eax=eax*60u+a[9];eax=eax*1000u+a[10];m.w32(0x00818610u,eax);}
    else {m.w32(0x0081861cu,ecx);eax=a[7]*60u+a[8];eax=eax*60u+m.r32(0x00818578u)+a[9];eax=eax*1000u+a[10];m.w32(0x00818620u,eax);if(s32(eax)<0){eax+=0x05265c00u;--ecx;m.w32(0x00818620u,eax);}else if(eax>=0x05265c00u){eax-=0x05265c00u;++ecx;m.w32(0x00818620u,eax);}m.w32(0x0081861cu,ecx);m.w32(0x00818618u,selector);}
    return eax;
}
// RVA 0x7b1e0: ordered signed intervals. MOV AL/XOR AL preserve EAX's upper bytes.
std::uint32_t fun_0047b1e0(Memory& m,const Inputs& i){
    const auto p=i.cx;std::uint32_t eax=i.ax;
    struct R{std::uint32_t address,extent;std::uint8_t deny1,deny2;};
    constexpr R rs[]={{0x00a3aaa8u,0x28u,0,0},{0x00a3a1bcu,4u,0,4},{0x00a54b90u,4u,1,3},{0x00a3aad8u,4u,0,1},{0x00a3ab28u,4u,2,3},{0x00a55938u,0x14u,0,0},{0x00a547a8u,4u,0,0},{0x00a3a8b0u,0x10u,0,0},{0x00a547a0u,0x10u,0,0},{0x00a55d30u,2u,0,0}};
    for(unsigned n=0;n<10;++n){const auto&r=rs[n];const auto low=m.r32(r.address);if(low==0xffffffffu)continue;
        eax=m.r32(p+0x38u);const auto high=low+r.extent;
        if(s32(eax)<s32(low)||s32(eax)>=s32(high))continue;
        if(n>=1&&n<=4&&(eax==low||eax==low+3u)){
            const auto gate=m.r8(p+0x11au);if(gate==r.deny1||gate==r.deny2)return lo8(eax,0);
        }
        return lo8(eax,1);
    }
    eax=m.r32(0x00a3aaa4u);if(eax==0xffffffffu)return lo8(eax,0);
    const auto value=m.r32(p+0x38u);const auto high=eax+0x1cu;
    if(s32(value)<s32(eax))return lo8(eax,0);
    return lo8(high,s32(value)<s32(high)?1u:0u);
}
}











