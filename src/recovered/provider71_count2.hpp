#pragma once
#include "recovered/global_b26_memory.hpp"
#include <stdexcept>
namespace count2 {
using U=unsigned;using Memory=ra2::recovered::global_b26::Memory;using Inputs=ra2::recovered::global_b26::Inputs;
struct Operations{void*context;U(*allocate)(void*,Memory&,U);};
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
inline U construct(Memory&m,const Inputs&i,const Operations&op){
 need(i.cx&&i.arg[0]==1&&i.arg[1]==2&&i.arg[2]==61,"finite constructor1,2,61");
 const auto s=i.cx;auto allocate=[&](U n){return op.allocate(op.context,m,n);};
 // Existing B226 translation, independently bounded to this new input domain.
 m.w16(s+0x24,i.arg[4]);m.w32(s+0x28,2);m.w32(s,0x788dcc);m.w32(s+0x1c,71);m.w32(s+0x2c,0xffffffff);m.w32(s+0x30,60);
 auto p=allocate(71);m.w32(s+0x20,p);p=allocate(88);
 m.w32(p,0x788db4);m.w32(p+4,1);m.w32(p+8,2);m.w32(p+12,71);m.w32(p+16,10);
 m.w32(p+0x24,allocate(32));m.w32(p+0x34,allocate(40));m.w32(p+0x30,allocate(4));m.w32(p+0x40,allocate(8));
 for(U n=0;n<1;++n){m.w32(m.r32(p+0x24)+32*n+0x14,allocate(71));m.w32(m.r32(p+0x24)+32*n+0x1c,allocate(10));}
 for(U n=0;n<2;++n){m.w32(m.r32(p+0x34)+20*n+8,allocate(71));m.w32(m.r32(p+0x34)+20*n+16,allocate(10));}
 for(U o:{0x2cu,0x3cu,0x14u,0x18u,0x1cu,0x20u,0x28u,0x38u})m.w32(p+o,0);
 for(U n=0;n<1;++n){auto q=m.r32(p+0x24)+32*n;for(U b:{1u,2u,4u})m.w32(q,m.r32(q)&~b);for(U o:{4u,8u,12u,16u,24u})m.w32(q+o,0);m.w32(m.r32(p+0x30)+4*n,0);}
 for(U n=0;n<2;++n){auto q=m.r32(p+0x34)+20*n;for(U b:{1u,2u,4u})m.w32(q,m.r32(q)&~b);m.w32(q+4,0);m.w32(q+12,0);m.w32(m.r32(p+0x40)+4*n,0);}
 for(U o:{0x44u,0x48u,0x4cu,0x54u})m.w32(p+o,0);m.w32(s+4,p);
 for(U k=0;k<10;++k)m.w8(s+0x4c+k,255);m.w32(s,0x78f644);m.w32(s+0x60,0);
 need(m.r16(0x82208c)==0,"authenticated empty UTF16 literal");m.w16(s+0x64,m.r16(0x82208c));
 // Actual522A60 next six bytes; its first DWORD writes only a private outgoing
 // argument copy. This high-level translation makes no x86 frame-trace claim.
 auto copy4=m.r32(s+0x50);auto copy2=m.r16(s+0x54);m.w32(s+0x5c,0);m.w32(s+0x56,copy4);m.w16(s+0x5a,copy2);
 m.w32(s,0x78f684);m.w16(s+0xb4,i.arg[3]);m.w32(s+0xc0,0);m.w8(s+0xc4,1);m.w32(s+0xd0,2);
 p=allocate(8);m.w32(s+0xcc,p);auto descriptors=allocate(20);for(U k=0;k<20;++k)m.w8(descriptors+k,255);m.w32(s+0xc8,descriptors);
 for(U n=0;n<2;++n)m.w32(m.r32(s+0xcc)+4*n,0xffffffff);m.w32(s+0xd4,0);return s;
}
}
