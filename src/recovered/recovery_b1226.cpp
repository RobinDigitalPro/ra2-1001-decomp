#include "recovery_b1226.hpp"
#include <stdexcept>
namespace ra2::recovered::b1226{
static void need(bool x){if(!x)throw std::domain_error("1226 genuine Map grid initialization/owned cleanup");}
static unsigned allocate(Heap&h,unsigned n){const unsigned p=h.allocate(n);need(p!=0u);return p;}
static void clear_empty(Memory&m,unsigned v){need(m.r32(v)==0x7909b8u&&m.r32(0x7909c4u)==0x567930u&&m.r32(v+4u)==0u&&m.r32(v+8u)==0u&&m.r32(v+0x10u)==0u&&m.r8(v+0xcu)==1u&&m.r8(v+0xdu)==0u);m.w32(v+0x10u,0u);m.w8(v+0xdu,0u);m.w32(v+8u,0u);}
static unsigned group(Heap&h,bool connection){const unsigned header=allocate(h,16u);h.w32(header+4u,0x54c6d0u);h.w32(header+8u,256u);h.w32(header+12u,20u);const unsigned cookie=allocate(h,6148u);h.w32(cookie,256u);for(unsigned j=0;j<256u;++j){const unsigned v=cookie+4u+24u*j;h.w32(v,connection?0x790a38u:0x790a58u);h.w32(v+4u,0u);h.w32(v+8u,0u);h.w8(v+12u,1u);h.w8(v+13u,0u);h.w32(v+16u,0u);h.w32(v+20u,20u);}h.w32(header,cookie+4u);return header;}
static void destroy_group(Heap&h,unsigned header,bool connection){need(h.r32(header+4u)==0x54c6d0u&&h.r32(header+8u)==256u&&h.r32(header+12u)==20u);const unsigned p=h.r32(header);need(p>=4u&&h.r32(p-4u)==256u);for(unsigned k=256u;k;--k){const unsigned v=p+24u*(k-1u);need(h.r32(v)==(connection?0x790a38u:0x790a58u)&&h.r32(v+4u)==0u&&h.r32(v+8u)==0u&&h.r8(v+12u)==1u&&h.r8(v+13u)==0u&&h.r32(v+16u)==0u&&h.r32(v+20u)==20u);h.w32(v,connection?0x790af8u:0x790ad8u);h.w8(v+13u,0u);h.w32(v+8u,0u);}h.release(p-4u);h.release(header);}
static void cold_services(Memory&m){
 // Actual705710: cold registry has count0/backingNULL/capacity0/owned0.
 need(m.r32(0xab81d8u)==0u&&m.r32(0xab81ccu)==0u&&m.r32(0xab81d0u)==0u&&m.r8(0xab81d5u)==0u);m.w32(0xab81d8u,0u);m.w8(0xab81d5u,0u);m.w32(0xab81d0u,0u);
 // Actual706830 has no allocation when its originalBSS pointer isNULL.
 need(m.r32(0xab8220u)==0u);
 // Actual6DE930 and tail6DF3F0 both read the same genuine cold registry count atAA8648.
 need(m.r32(0xaa8648u)==0u);need(m.r32(0xaa8648u)==0u);
}
unsigned run(unsigned r,Memory&m,const Inputs&i,Heap&h){const unsigned self=i.cx;need((r==0x145560u||r==0x15fc90u)&&m.r32(self)==0x79091cu&&m.r32(0x790930u)==0x545560u);
 if(r==0x145560u){need(m.r32(self+0x14u)==0u&&m.r32(self+0x7cu)==0u&&m.r32(self+0x80u)==0u&&m.r32(self+0x84u)==0u);m.w32(0xa28b34u,0u);m.w32(self+0x148u,512u);m.w32(self+0x14cu,512u);m.w32(self+0x150u,262144u);need(m.r32(0x790974u)==0x545800u&&m.r32(0x7909a0u)==0x5688b0u);
  const unsigned v=self+0x134u;m.w32(v+4u,0u);m.w32(v+8u,0u);m.w8(v+12u,1u);m.w8(v+13u,0u);m.w32(v,0x790998u);m.w8(v+12u,0u);const unsigned table=allocate(h,1048576u);m.w8(v+12u,1u);m.w32(v+4u,table);m.w32(v+8u,262144u);m.w8(v+13u,1u);for(unsigned j=0;j<262144u;++j)h.w32(table+4u*j,0u);
  m.w32(self+0x14u,group(h,false));for(unsigned level=0;level<3u;++level){clear_empty(m,self+0x88u+24u*level);m.w32(self+0x7cu+4u*level,group(h,true));}for(unsigned k=0;k<12u;++k)m.w32(self+0x18u+4u*k,0u);return 0u;
 }
 for(unsigned k=0;k<12u;++k)need(m.r32(self+0x18u+4u*k)==0u);const unsigned first=m.r32(self+0x14u);need(first!=0u&&m.r32(0x790a58u)==0x569200u&&m.r32(0x790a38u)==0x569410u);destroy_group(h,first,false);m.w32(self+0x14u,0u);for(unsigned level=0;level<3u;++level){clear_empty(m,self+0x88u+24u*level);const unsigned head=m.r32(self+0x7cu+4u*level);need(head!=0u);destroy_group(h,head,true);m.w32(self+0x7cu+4u*level,0u);}cold_services(m);return 0u;
}
}
