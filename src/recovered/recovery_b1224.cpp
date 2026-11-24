#include "recovered/recovery_b1224.hpp"
#include <stdexcept>
namespace ra2::recovered::b1224 {namespace{
void need(bool x){if(!x)throw std::domain_error("1224 finite genuine populated Factory queue");}
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&o){
 need(root==0xb90b0u||root==0xe5b90u);const unsigned house=base+0x4000u,factory=base+0x3000u,type=base+0xb040u;
 need(m.r32(factory)==0x78bee0u&&m.r32(factory+0x3cu)==0x78bf44u&&m.r32(house+0x52dcu)==factory&&m.r32(type)==0x78ea78u&&m.r32(type+0xb90u)==1u&&m.r32(0x78eaa4u)==0x50a3b0u&&m.r32(0x78eab8u)==0x50a3d0u);
 const unsigned count=m.r32(factory+0x4cu),back=m.r32(factory+0x40u);need(count>=1u&&count<=4u&&m.r32(factory+0x44u)==10u&&m.r8(factory+0x48u)==1u&&m.r8(factory+0x49u)==1u&&m.r32(factory+0x54u)==0u&&m.r32(factory+0x68u)==house);
 if(root==0xb90b0u){need(i.cx==factory&&i.arg[0]==type&&i.arg[1]==house&&(i.arg[2]&255u)==0u&&m.r32(factory+0x34u)==0u&&m.r32(0x821b88u)==base+0xd000u&&m.r32(base+0xd0e8u)==5u);o.virtual_callbacks+=2u; // Two actual Type kind16 calls exclude B9430 and timer path.
  need(m.r8(type+0xadau)==0u&&m.r8(type+0xc14u)==0u&&m.r32(type+0x388u)==0x7fffffffu);o.virtual_callbacks+=2u;++o.limit_queries; // F4430 Typekind twice.
  unsigned queued=0u;for(unsigned k=0;k<count;++k){queued+=h.r32(back+4u*k)==type;++o.queue_visits;}
  need(m.r32(house+0x5440u)==0x7895acu&&m.r32(house+0x5448u)==11u);const unsigned current=h.r32(m.r32(house+0x5444u)+4u);need(current>=2u&&current<=6u);++o.counter_lookups;++o.virtual_callbacks; // Genuine Type+40 -> index1.
  need(current+queued<0x7fffffffu);h.w32(back+4u*count,type);m.w32(factory+0x4cu,count+1u);++o.insertions;return(count&0xffffff00u)|1u;
 }
 need(i.cx==house&&i.arg[0]==16u&&i.arg[1]==1u);const unsigned registry=m.r32(0xa27fa4u);need(h.r32(registry+4u)==type);o.catalog_lookups=2u; // Original4829A0 executes twice before the positive removal.
 i.arg[1]=0u;i.arg[0]=15u;
 unsigned found=0u;for(;found<count&&h.r32(back+4u*found)!=type;++found)++o.queue_visits;need(found<count);++o.queue_visits;++o.virtual_callbacks; // True78BF44+10 -> linear Find4B9F60.
 m.w32(factory+0x4cu,count-1u);for(unsigned k=found;k+1u<count;++k)h.w32(back+4u*k,h.r32(back+4u*k+4u));++o.removals;
 need(m.r32(0x81a820u+0x4ed8u)==2u&&m.r32(0x821cacu)==base+0x1000u);m.w8(0x81a820u+0x4ee2u,1u);m.w8(0x81a820u+0x3240u,1u);m.w8(base+0x1d7du,1u);o.ui_updates=3u; // Real677000 returns2;671BA0 ->4E0030(0), no Map virtual dispatch.
 return 0u;
}
}
