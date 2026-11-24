#include "recovery_b245.hpp"
#include "platform/observed_receiver245.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b245 {
namespace {
using U=std::uint32_t;using Api=ra2::platform::receiver245::Scope;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
// 4811A0 -> 47FFF0, bounded two free records with disjoint payloads.
void append(Memory&m,U child){
 const U out=m.r32(child+0x20),q=m.r32(child+4),list=m.r32(q+0x24),count=m.r32(q+4),cursor=m.r32(q+0x28);
 need(m.r32(child+0x1c)>=111&&m.r32(q+0xc)>=119&&cursor<count&&count==2,"245 append capacities");
 m.w16(out,m.r16(child+0x24));m.w8(out+2,1);m.w32(out+4,m.r32(child+0x3c));
 need(m.r32(0xa255c8)!=4||!m.r8(0xa27ed4),"245 excluded extra header");
 m.w8(out+8,0x13);for(U k=1;k<111;++k)m.w8(out+8+k,0);
 U slot=0;while(slot<count&&(m.r8(list+slot*32)&1))++slot;need(slot<count,"245 append free record");
 const U r=list+slot*32;m.w32(r,m.r32(r)|1);m.w32(r,m.r32(r)&~2u);m.w32(r,m.r32(r)&~4u);
 m.w32(r+4,0);m.w32(r+8,0);m.w32(r+12,0);m.w32(r+16,119);
 const U dst=m.r32(r+20);for(U k=0;k<119;++k)m.w8(dst+k,m.r8(out+k));m.w32(r+24,0);
 m.w32(m.r32(q+0x30)+cursor*4,slot);m.w32(q+0x2c,m.r32(q+0x2c)+1);m.w32(q+0x28,cursor+1);m.w32(child+0x3c,m.r32(child+0x3c)+1);
}
U record(Memory&m,U q,U index){const U r=m.r32(q+0x24)+32*m.r32(m.r32(q+0x30)+4*index);need(m.r8(r)&1,"245 indexed live record");return r;}
void poll(Memory&m,U child,U base,U offset){
 const U receiver=m.r32(0xb0d628);
 need(!m.r8(receiver+0x50)&&m.r32(receiver+0x5c)==0xffffffffu&&m.r32(receiver+0x54)==m.r32(receiver+0x58),"245 idle receiver");
 Api::poll(receiver,m.r32(receiver+0x38));
 need(m.r32(0xa286c0)<11,"245 manager idle parse branch");
 // Authentic 792388+14 -> 4815C0 -> +1C 4815F0 and +20 4817A0.
 const U q=m.r32(child+4),count=m.r32(q+0x28);need(count==2,"245 maintenance count");
 for(U k=0;k<count;++k)need(!(m.r8(record(m,q,k))&2),"245 first pass excludes acknowledged records");
 for(U k=0;k<count;++k){const U r=record(m,q,k);need(!(m.r8(r)&2),"245 unacknowledged second pass");const U now=offset+(Api::clock(0x4816b1)>>4)-base;need(now-m.r32(r+8)<=m.r32(child+0x28),"245 retransmit outside finite idle contract");}
 need(m.r32(q+0x38)==0,"245 no received items to acknowledge");
}
}
std::uint32_t fun_005c7120(Memory&m,const Inputs&){
 need(!(m.r8(0xa27928)&2)&&m.r32(0xa286a4)==1,"245 enabled manager");const U child=m.r32(0xa286a0);
 need(m.r32(child)==0x792388&&m.r32(0x792390)==0x4811a0&&m.r32(0x79239c)==0x4815c0&&m.r32(0x7923a4)==0x4815f0&&m.r32(0x7923a8)==0x4817a0,"245 authentic child dispatch");
 append(m,child);append(m,child);
 const U base=m.r32(0x821cc0),offset=m.r32(0x821cc8);need(base!=0xffffffffu,"245 running shifted timer");
 const U first=offset+(Api::clock(0x5c718c)>>4)-base;
 for(;;){const U value=(Api::clock(0x5c71ae)>>4)-base;if(offset+value-first>=30)return value;poll(m,child,base,offset);}
}
}
