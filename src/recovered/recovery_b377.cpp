#include "recovery_b377.hpp"
#include "recovery_b277.hpp"
#include "platform/audio377.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b377 {
namespace {
using U=std::uint32_t;
void require(bool b,const char*s){if(!b)throw std::domain_error(s);}
void target(Memory&m,U p,U value){m.w32(p,m.r32(p)|1u);m.w32(p+8,value<<16);}
void refresh(Memory&m,U p){
 if(m.r32(p+4)==m.r32(p+8))return;
 require(m.r8(p)&1u,"B377 immediate vector update");m.w32(p+4,m.r32(p+8));m.w32(p,m.r32(p)|2u);
}
void initialize_vectors(Memory&m,U base){
 // Original401000 ->407030/4070F0 and4070D0, with null clock819898.
 const U values[]={0x4000,100,0x2000},rates[]={0x4000,10,0x4000};
 for(U j=0;j<3;++j){const U p=base+40*j;
  m.w32(p,1);m.w32(p+24,0);m.w32(p+28,0);m.w32(p+16,1000);
  m.w32(p+8,values[j]<<16);m.w32(p+12,0x10624d);m.w32(p+20,0);refresh(m,p);
  m.w32(p+16,1000);m.w32(p+12,(rates[j]<<16)/1000);m.w32(p+20,0);
 }target(m,base,0x4000);
}
void compose(Memory&m,U dst,U src){Inputs c{};c.cx=dst;c.dx=src;(void)recovery_b277::fun_004010c0(m,c);}
}
std::uint32_t fun_004054b0(Memory&m,const Inputs&i){
 const U r=i.cx,g=m.r32(r+0xb0),c=m.r32(g+0x158),owner=m.r32(g+0xac),source=m.r32(r+0x148);
 const U format=m.r32(source+20),bytes=8192,buffer=m.r32(c+100),data=m.r32(source);
 require(m.r32(g+0xc0)==r&&(m.r32(g+0xa4)&5u)==0&&m.r32(g+0xd4)==0x7b7d80,"B377 authentic positive manager dispatch");
 require(m.r32(c)==g&&buffer&&m.r32(c+104)==bytes&&m.r32(c+108)==2048,"B377 initialized real buffer geometry");
 require(m.r32(source+4)==bytes&&m.r32(source+8)==0&&m.r32(format+4)==0&&m.r32(format+8)==8000&&m.r32(format+12)==1&&m.r32(format+16)==1,"B377 finite PCM8 mono source/count");
 require(m.r32(c+80)==1&&m.r32(c+76)==8000&&m.r32(c+84)==1&&m.r32(0x819898)==0,"B377 reused format and null clock");
 for(U off:{0x90u,0x94u,0x98u,0x9cu})require(m.r32(g+off)==0,"B377 excludes extra control vectors");
 require(m.r32(owner+0xe8)==0&&global_b26::s32(m.r32(c+0x88))>=0&&global_b26::s32(m.r32(c+0x9c))>=0,"B377 no extra composition or CRT capacities");
 auto&h=ra2::platform::audio377::host();h.enter();
 m.w32(r+24,m.r32(r+24)|8);m.w32(g+0x168,source);m.w32(g+0x16c,0);
 m.w32(g+0x170,data);m.w32(g+0x174,bytes);m.w32(g+0x178,bytes);
 target(m,g+0x38,m.r32(r+0x14c));
 const U percent=m.r32(r+0x150);U volume=0x4000;
 if(global_b26::s32(percent)>0)volume-=U((std::uint64_t(percent<<14)*0x51eb851full)>>37);
 target(m,g+16,volume);m.w32(r+28,3);m.w32(r+24,m.r32(r+24)|2);m.w32(r+0x148,0);
 for(U off:{16u,56u,96u})refresh(m,g+off);
 initialize_vectors(m,g+0xd8);compose(m,g+0xd8,g+16);
 for(U off:{16u,56u,96u})m.w32(g+off,m.r32(g+off)&~2u);
 compose(m,g+0xd8,owner+0x68);
 h.enter();
 bool same=true;for(U k=0;k<32;++k)same&=m.r8(g+0x17c+k)==m.r8(format+k);
 m.w32(g+0x19c,same?0:1);if(!same)for(U k=0;k<32;++k)m.w8(g+0x17c+k,m.r8(format+k));
 m.w32(g+0x1a0,0);m.w32(c+44,0);m.w32(c+8,0);m.w32(c+60,8192);
 h.position_zero(buffer);U play=0,write=0;h.cursors(buffer,play,write);
 require(play==0,"B377 stopped buffer play cursor must be actual zero");m.w32(c+52,write);m.w32(c+12,0);
 m.w32(c+16,0);m.w32(c+20,0);m.w32(c+64,bytes);h.cursors(buffer,play,write);
 require(play==0,"B377 second actual stopped play cursor");m.w32(c+48,play);m.w32(c+52,write);m.w32(c+56,bytes);
 for(U off:{0xd0u,0xd4u,0xd8u,0xdcu})m.w32(c+off,0);
 for(U off:{0x98u,0x84u,0x80u,0x8cu,0xa0u,0xa8u})m.w32(c+off,0);
 m.w32(c+0x74,3);m.w32(c+0xa4,1);m.w32(c+0x70,0x409cb0);m.w32(c+0xcc,0);
 m.w32(c+40,data);m.w32(c+32,data);m.w32(c+36,bytes);m.w32(c+44,bytes);
 //4097A0 accepts only a single contiguous locked region. The original rejects
 // split locks; do not silently extend this route to a different helper path.
 const auto region=h.lock(buffer,bytes);
 require(region.first&&region.first_size==bytes&&!region.second&&!region.second_size,"B377 original contiguous lock contract");
 for(U k=0;k<bytes;++k)static_cast<std::uint8_t*>(region.first)[k]=std::uint8_t(m.r8(data+k));
 m.w32(c+40,data+bytes);m.w32(c+44,0);m.w32(c+8,bytes);m.w32(c+48,bytes);m.w32(c+56,0);
 h.unlock(buffer,region);
 const U vi=(((m.r32(g+0xdc)>>16)*100u)>>14);
 require(vi<=100,"B377 original volume table bounds");h.volume(buffer,global_b26::s32(m.r32(0x7b7dd8+4*vi)));
 const U pi=(((m.r32(g+0x12c)>>16)*200u)>>14)-100u;
 const U table=global_b26::s32(pi)<0?0x7b7f68+4*pi:0x7b7f68-4*pi;
 U pan=m.r32(table);if(global_b26::s32(pi)>=0)pan=0u-pan;h.pan(buffer,global_b26::s32(pan));
 const U product=(m.r32(g+0x104)>>16)*m.r32(g+0x184);
 U frequency=global_b26::sar(global_b26::imul_high(0x51eb851fu,product),5);frequency+=frequency>>31;
 h.frequency(buffer,frequency);h.play(buffer);h.leave();m.w32(g+0xa4,m.r32(g+0xa4)|1);h.leave();return 1;
}
}
