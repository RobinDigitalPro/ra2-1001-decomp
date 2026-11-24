#include "recovery_b226.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b226 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
// Original47FCE0, both positive count-one loops, then47FEA0 initialization.
unsigned construct_table(Heap&h,unsigned p,unsigned rows,unsigned cols,unsigned payload,unsigned extra){
 need(rows==1&&cols==1&&payload==12&&extra==10,"226 exact positive table dimensions");
 h.w32(p,0x788db4);h.w32(p+4,rows);h.w32(p+8,cols);h.w32(p+0xc,payload);h.w32(p+0x10,extra);
 h.w32(p+0x24,h.allocate(rows*32));h.w32(p+0x34,h.allocate(cols*20));h.w32(p+0x30,h.allocate(rows*4));h.w32(p+0x40,h.allocate(cols*4));
 for(unsigned n=0;n<rows;++n){auto q=h.allocate(payload);h.w32(h.r32(p+0x24)+32*n+0x14,q);q=h.allocate(extra);h.w32(h.r32(p+0x24)+32*n+0x1c,q);}
 for(unsigned n=0;n<cols;++n){auto q=h.allocate(payload);h.w32(h.r32(p+0x34)+20*n+8,q);q=h.allocate(extra);h.w32(h.r32(p+0x34)+20*n+0x10,q);}
 for(unsigned off:{0x2cu,0x3cu,0x14u,0x18u,0x1cu,0x20u,0x28u,0x38u})h.w32(p+off,0);
 for(unsigned n=0;n<rows;++n){const auto q=h.r32(p+0x24)+32*n;for(unsigned bit:{1u,2u,4u})h.w32(q,h.r32(q)&~bit);for(unsigned off:{4u,8u,12u,16u,24u})h.w32(q+off,0);h.w32(h.r32(p+0x30)+n*4,0);}
 for(unsigned n=0;n<cols;++n){const auto q=h.r32(p+0x34)+20*n;for(unsigned bit:{1u,2u,4u})h.w32(q,h.r32(q)&~bit);h.w32(q+4,0);h.w32(q+12,0);h.w32(h.r32(p+0x40)+n*4,0);}
 for(unsigned off:{0x44u,0x48u,0x4cu,0x54u})h.w32(p+off,0);
 return p;
}
}
unsigned fun_00523480(Memory&m,const Inputs&i,Heap&h){
 const auto s=i.cx;need(i.arg[0]==1&&i.arg[1]==1&&i.arg[2]==2,"226 finite1x1 constructor inputs");
 // 4810C0 receives [rows,cols,arg2+2,arg4,2,-1,60,10].
 const auto payload=i.arg[2]+10;
 m.w16(s+0x24,i.arg[4]);m.w32(s+0x28,2);m.w32(s,0x788dcc);m.w32(s+0x1c,payload);m.w32(s+0x2c,0xffffffff);m.w32(s+0x30,60);
 auto p=h.allocate(payload);m.w32(s+0x20,p);p=h.allocate(88);m.w32(s+4,construct_table(h,p,1,1,payload,10));
 // 122F30: actual122950 writes tenFF bytes; optional descriptor arg4=0.
 for(unsigned k=0;k<10;++k)m.w8(s+0x4c+k,255);m.w32(s,0x78f644);m.w32(s+0x60,0);
 // 36EFC9 copies WORDs, including the first zero, from the pinned PE literal.
 for(unsigned k=0;;k+=2){need(k==0,"226 pinned empty UTF16 literal bound");const auto v=m.r16(0x82208c+k);m.w16(s+0x64+k,v);if(!v)break;}
 // 122A60 copies DWORD0 into the temporary outgoing arg7 slot and the next
 // six bytes into caller locals. Only the six-byte result survives externally.
 const auto copy4=m.r32(s+0x50);const auto copy2=m.r16(s+0x54);m.w32(s+0x5c,0);m.w32(s+0x56,copy4);m.w16(s+0x5a,copy2);
 m.w32(s,0x78f684);m.w16(s+0xb4,i.arg[3]);m.w32(s+0xc0,0);m.w8(s+0xc4,1);m.w32(s+0xd0,1);
 p=h.allocate(4);m.w32(s+0xcc,p);const auto descriptors=h.allocate(10);for(unsigned k=0;k<10;++k)h.w8(descriptors+k,255);m.w32(s+0xc8,descriptors);
 h.w32(m.r32(s+0xcc),0xffffffff);m.w32(s+0xd4,0);return s;
}
}
