#include "recovered/global_b27_memory.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::global_b27 {
namespace {
std::int32_t idiv(std::uint32_t n,std::uint32_t d){if(!s32(d)||(n==0x80000000u&&d==0xffffffffu))throw std::domain_error("excluded original IDIV fault domain");return s32(n)/s32(d);}
}

void fun_00591e20(Memory&m,State&s){s.ax=s.cx==0xffffffffu?0x007b8e5cu:m.r32(0x007b8704u+s.cx*4u);}

void fun_0059bf60(Memory&m,State&s){auto eax=s.arg[0]*3u;auto ecx=0x007cd5d0u+eax*8u;auto al=s.arg[1]&0xffu;eax=(eax&0xffffff00u)|al;if(al){eax=m.r32(ecx+0x0cu);if(eax==0xffffffffu)eax=m.r32(ecx);}else eax=m.r32(ecx);s.ax=eax;s.cx=ecx;}
void fun_0059cd10(Memory&m,State&s){s.ax=m.r32(0x007cd5d0u+s.arg[0]*24u);}
void fun_0059cd30(Memory&m,State&s){s.ax=m.r32(0x007cd5d4u+s.arg[0]*24u);}

void fun_005a4180(Memory&m,State&s){
    auto cp=s.cx;auto out=s.dx;std::uint32_t eax=0,ecx=0,edx=cp;
    if(cp<=0x7fu){m.w8(out,cp);eax=1;s.ax=eax;s.dx=edx;return;}
    eax=4;ecx=24;
    for(;;){const auto v=edx>>ecx;if(v)break;ecx-=8u;--eax;if(ecx!=0xfffffff8u)continue;break;}
    eax=(eax&0xffffff00u)|((eax|0x80u)&0xffu);m.w8(out,eax);
    auto esi=4u;eax=1;ecx=24;
    for(;;){const auto v=edx>>ecx;if(v)break;ecx-=8u;--esi;if(ecx!=0xfffffff8u)continue;break;}
    if(esi){ecx=esi*8u-8u;auto ebx=edx;while(esi){ebx=edx>>ecx;++eax;ecx-=8u;--esi;m.w8(out+eax-1u,ebx);}}
    s.ax=eax;s.cx=ecx;s.dx=edx;
}

void fun_005c2af0(Memory&m,State&s){m.w32(0xa27dc4u+s.cx*4u,s.dx);}

void fun_005cd6a0(Memory&m,State&s){
    const auto out=s.cx,obj=s.dx,count=m.r32(s.dx+0x10u);const auto base=m.r32(s.dx+4u);
    if(!count)throw std::domain_error("original RVA 0x1cd6a0 divides by zero for count 0");
    std::uint32_t sx=0,sy=0,sz=0;
    for(std::uint32_t k=count;k>0;--k){const auto p=m.r32(base+(k-1u)*4u)+0x88u;sx+=m.r32(p);sy+=m.r32(p+4u);sz+=m.r32(p+8u);}
    const auto ax=idiv(sx,count),ay=idiv(sy,count),az=idiv(sz,count);
    m.w32(out,static_cast<std::uint32_t>(ax));m.w32(out+4u,static_cast<std::uint32_t>(ay));m.w32(out+8u,static_cast<std::uint32_t>(az));
    s.ax=out;s.dx=static_cast<std::uint32_t>(static_cast<std::int64_t>(s32(sz))%static_cast<std::int64_t>(s32(count)));
}

void fun_005d0260(Memory&m,State&s){
    if(s.dx==0xffffffffu)return;
    auto al=m.r8(s.cx),bl=m.r8(s.cx+1u);if(al>=0x41&&al<=0x5a)al+=0x20;if(bl>=0x41&&bl<=0x5a)bl+=0x20;
    auto eax=(s.ax&0xffffff00u)|al;auto edx=s.dx;
    if(al=='g'||al=='n'||al=='c')if(bl=='a'||bl=='t'){eax=s.dx*3u;edx=s.dx+eax*4u;eax=(eax&0xffffff00u)|m.r8(edx*8u+0x785bb4u);m.w8(s.cx+1u,eax);}
    // EBX is callee-saved by PUSH/POP; BL's temporary lowercase value is not
    // observable after the original POP EBX.
    s.ax=eax;s.dx=edx;
}

void fun_005d1de0(Memory&m,State&s){
    auto eax=s.arg[0],ecx=s.cx,edx=s.dx;
    if(eax){ecx=m.r32(ecx);if(eax<5u){edx=ecx+eax*8u;eax=m.r32(0x7d24dcu+edx*4u);}else{eax*=8u;edx=(s32(eax)<0)?0xffffffffu:0u;++ecx;const auto n=std::int64_t(s32(eax));const auto d=std::int64_t(s32(ecx));if(!d||(n==INT32_MIN&&d==-1))throw std::domain_error("original RVA 0x1d1de0 IDIV fault");eax=static_cast<std::uint32_t>(n/d);edx=static_cast<std::uint32_t>(n%d);}}
    s.ax=eax;s.cx=ecx;s.dx=edx;
}

void fun_0060b7e0(Memory&m,State&s){
    auto eax=s.arg[0],ecx=s.cx,edx=s.dx;const auto len=m.r32(ecx+0x14u);
    if(len){if(s32(eax)>=s32(len)){const auto start=m.r32(ecx+0x94u);if(s32(start)<0){s.ax=0;return;}eax-=start;const auto mod=m.r32(ecx+0x90u);if(!s32(mod))throw std::domain_error("original RVA 0x20b7e0 IDIV fault");const auto n=std::int64_t(s32(eax));const auto d=std::int64_t(s32(mod));edx=static_cast<std::uint32_t>(n%d)+start;eax=edx;}
        if(s32(eax)<0||s32(eax)>=s32(len)){s.ax=0;s.dx=edx;return;}ecx=m.r32(ecx+8u);eax=m.r32(ecx+eax*4u);s.cx=ecx;s.dx=edx;s.ax=eax;return;}
    s.ax=0;
}

void fun_0060e900(Memory&m,State&s){if(s32(s.cx)<0||s.cx>=8u)return;auto eax=m.r32(0xa5e1dcu+s.cx*4u)-1u;auto mask=(s32(eax)>=0)?0xffffffffu:0u;auto edx=mask&eax;m.w32(0xa5e1dcu+s.cx*4u,edx);s.ax=eax;s.dx=edx;}

void fun_0062eb70(Memory&m,State&s){auto d=m.r32(s.cx+0x6cu);if(s32(d)<=0){s.ax=0;return;}auto eax=m.r32(s.cx+0x70u)*m.r32(s.cx+0x4cu);const auto num=std::int64_t(s32(eax));const auto q=num/s32(d);const auto r=num%s32(d);s.ax=static_cast<std::uint32_t>(q);s.dx=static_cast<std::uint32_t>(r);}

void fun_0062ff10(Memory&m,State&s){
    auto eax=m.r32(s.cx+4u),edi=m.r32(s.cx),ebx=eax,ecx=s.cx,edx=s.dx,ebp=s.bp,esi=0u;
    m.w32(s.cx+4u,eax+1u);
    do{ecx=m.r32(0x7d8244u+esi);ebx=eax;ecx^=eax;esi+=4u;edx=ecx;ecx=sar(ecx,16);edx&=0xffffu;eax=ecx*ecx;ecx*=edx;ebp=edx*edx;eax=~eax;eax+=ebp;ebp=sar(eax,16);eax<<=16;ebp|=eax;eax=m.r32(0x7d8290u+esi);ebp^=eax;ebp+=ecx;ebp^=edi;eax=ebp;edi=ebx;}while(esi<0x10u);
    s.ax=eax;s.cx=ecx;s.dx=edx;
}

void fun_006522e0(Memory&m,State&s){std::uint32_t eax=0x7db828u,edx=0;while(eax<0x7db890u){if(m.r32(eax)==s.cx){s.ax=m.r32(0x7db82cu+edx*8u);s.dx=edx;return;}eax+=8u;++edx;}s.ax=0;s.dx=edx;}

void fun_00670010(Memory&m,State&s){
    const auto object=s.cx;auto edx=m.r32(object+0x58u)*3u;const auto flags=m.r32(0x795ca0u+edx*4u);const auto out=s.arg[0];auto eax=m.r32(s.arg[2]),ecx=object,edi=m.r32(s.arg[1]),esi=m.r32(s.arg[1]+4u);
    if(flags&1u){auto t=edi;edi=esi;esi=t;edx=0xffffffc0u-eax;edx&=0xffu;eax=edx;}
    if(flags&2u){eax=0u-eax;edi=0u-edi;eax&=0xffu;}
    if(flags&4u){edx=0xffffff80u-eax;esi=0u-esi;edx&=0xffu;eax=edx;}
    m.w32(s.arg[2],eax);edx=m.r32(object+0x40u)+edi;ecx=m.r32(object+0x44u)+esi;m.w32(out,edx);m.w32(out+4u,ecx);s.ax=out;s.cx=ecx;s.dx=edx;
}

void fun_00695c30(Memory&m,State&s){m.w32(0xaa5dd0u+s.cx*4u,s.dx);}
void fun_00695c50(Memory&m,State&s){auto eax=m.r32(0xaa5dd0u+s.cx*4u);s.ax=(s32(eax)<0||eax>=25u)?0u:0xaa5420u+eax*96u;}
void fun_006a1e10(Memory&m,State&s){auto x=s.arg[0]*3u;s.ax=m.r32(0xaa6100u+x*4u);}

void fun_006cece0(Memory&m,State&s){
    const auto divisor=s.arg[1],out=s.arg[0];if(!divisor){m.w32(out,0);m.w32(out+4u,0);m.w32(out+8u,0);s.ax=out;s.cx=0;s.dx=0;return;}
    const auto x=m.r32(s.cx),y=m.r32(s.cx+4u),z=m.r32(s.cx+8u);const auto ax=static_cast<std::uint32_t>(idiv(x,divisor)),ay=static_cast<std::uint32_t>(idiv(y,divisor)),az=static_cast<std::uint32_t>(idiv(z,divisor));m.w32(out,ax);m.w32(out+4u,ay);m.w32(out+8u,az);s.ax=out;s.cx=out;s.dx=out;
}

void fun_0070bb80(Memory&m,State&s){
    auto edi=s.dx;std::uint32_t esi=0xac84fcu,eax=0xacaa89u,edx=s.cx,ecx=0,ebp=s.bp,ebx=s.bx;
    do{auto bl=m.r8(eax-1u);ecx=edx&0xffu;bl=static_cast<std::uint8_t>(bl>>(ecx&31u));ecx=edi;eax+=3u;esi+=2u;ebp=(ebp&0xffff0000u)|bl;ebp<<=(ecx&31u);
        bl=static_cast<std::uint8_t>(m.r8(eax-2u)>>(s.arg[2]&31u));ecx=s.arg[3];ebx=(ebx&0xffff0000u)|bl;ebx<<=(ecx&31u);ecx=s.arg[0];ebp|=ebx;
        bl=static_cast<std::uint8_t>(m.r8(eax-3u)>>(ecx&31u));ecx=s.arg[1];ebx=(ebx&0xffff0000u)|bl;ebx<<=(ecx&31u);ebp|=ebx;m.w16(esi-2u,ebp);}
    while(eax<0xacad89u);
    s.ax=eax;s.cx=ecx;s.dx=edx;
}

void fun_00712720(Memory&m,State&s){auto eax=s.cx;auto ecx=eax&7u,dl=1u<<(ecx&31u);eax=sar(eax,3);m.w8(eax+0xae0aa0u,m.r8(eax+0xae0aa0u)|dl);s.ax=eax;s.cx=ecx;s.dx=(s.dx&0xffffff00u)|dl;}
void fun_00712760(Memory&m,State&s){auto eax=s.cx,edx=s.dx,ecx=eax&7u;auto dl=1u<<(ecx&31u);eax=sar(eax,3);const auto bit=(m.r8(eax+0xae0aa0u)&dl)!=0;s.ax=(eax&0xffffff00u)|(bit?1u:0u);s.cx=ecx;s.dx=(edx&0xffffff00u)|dl;}

void fun_00730e40(Memory&m,State&s){
    if(m.r32(0xa255c8u)!=4u){s.ax=with_al(s.ax,0);return;}
    auto eax=m.r32(0xb0eeb4u);if(eax){s.ax=with_al(eax,1);return;}
    eax=m.r32(0xb0eec0u)>>8;const auto al=eax&1u;s.cx=(s.cx&0x00ffffffu)|(al<<24);s.ax=with_al(eax,al);
}

void fun_0076a9ce(Memory&m,State&s){
    auto eax=0u;auto update=[&](std::uint32_t ptr,std::uint32_t add,std::uint32_t sub){auto old=m.r32(ptr);auto esi=0u-old;auto edi=add+old-sub-1u;if((edi&esi)&0x80000000u)return;eax=1;if(s32(esi)<0){++edi;m.w32(ptr,old-edi);}else m.w32(ptr,0);};
    update(s.arg[0],s.arg[2],s.arg[4]);update(s.arg[1],s.arg[3],s.arg[5]);s.ax=eax;
}

const std::array<Entry,24>& entries_b(){static const std::array<Entry,24> e{{
{0x191e20,fun_00591e20},{0x19bf60,fun_0059bf60},{0x19cd10,fun_0059cd10},{0x19cd30,fun_0059cd30},{0x1a4180,fun_005a4180},{0x1c2af0,fun_005c2af0},{0x1cd6a0,fun_005cd6a0},{0x1d0260,fun_005d0260},{0x1d1de0,fun_005d1de0},{0x20b7e0,fun_0060b7e0},{0x20e900,fun_0060e900},{0x22eb70,fun_0062eb70},{0x22ff10,fun_0062ff10},{0x2522e0,fun_006522e0},{0x270010,fun_00670010},{0x295c30,fun_00695c30},{0x295c50,fun_00695c50},{0x2a1e10,fun_006a1e10},{0x2cece0,fun_006cece0},{0x30bb80,fun_0070bb80},{0x312720,fun_00712720},{0x312760,fun_00712760},{0x330e40,fun_00730e40},{0x36a9ce,fun_0076a9ce}}};return e;}
} // namespace ra2::recovered::global_b27
