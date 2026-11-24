#include "recovery_b1216.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
namespace ra2::recovered::b1216{
namespace fp=ra2::platform::x87;
static void need(bool b){if(!b)throw std::domain_error("1216 genuine single-cell Infantry footprint Map insert/unlink");}
static unsigned kind(Memory&m,unsigned a){need(m.r32(a)==0x78e540u&&m.r32(0x78e56cu)==0x508c50u);return 15u;}
static void cache(Memory&m,Heap&h,unsigned cell){
 need(m.r32(cell+0x44u)==0xffffffffu&&m.r32(cell+0x38u)==0xffffu&&m.r8(m.r32(0x821b88u)+0x584u)==0u);
 m.w32(cell+0xecu,0u);m.w8(cell+0x11cu,0u);
 // Actual557450 isometric membership with flat0 height and positive table lookup.
 const auto p=m.r32(cell+0x24u);const int x=static_cast<short>(p),y=static_cast<short>(p>>16u);const int width=int(m.r32(0x81a910u));need(m.r32(m.r32(0x81a958u)+4u*unsigned(x+512*y))==cell&&m.r8(cell+0x11bu)==0u);
 need(x+y>width+2*int(m.r32(0x81a91cu))&&x+y<=width+2*int(m.r32(0x81a91cu)+m.r32(0x81a924u))+2&&x-y<2*int(m.r32(0x81a918u)+m.r32(0x81a920u))-width&&y-x<width-2*int(m.r32(0x81a918u)));
 need(m.r32(0x8391d8u)==0x3f800000u);fp::State f;f.image=fp::capture_host();f.load32(m.r32(0x8391d8u));f.compare_pop64(0x3f847ae147ae147bull);need((f.status()&0x4100u)==0u);fp::restore_host(f.image);
 // New positive-list extension of478B40. Every reached realRTTI15 node
 // misses Building6 andTerrain36 branches, then follows actualmember30.
 unsigned a=m.r32(cell+0xe4u),steps=0u;while(a){need(++steps<=4u&&kind(m,a)==15u);a=m.r32(a+0x30u);}m.w32(cell+0x4cu,0u);
 const unsigned index=unsigned(x)+(m.r32(0x81a910u)+m.r32(0x81a914u)+1u)*unsigned(y);need(index==821u&&index<m.r32(0x81a888u));const auto v4=m.r32(0x81a884u)+4u*index,v10=m.r32(0x81a88cu)+10u*index;h.w8(v4+1u,m.r8(cell+0x11bu));h.w8(v4,m.r8(cell+0x4cu));h.w8(v10+8u,m.r8(cell+0x11bu));
}
unsigned run(unsigned r,Memory&m,const Inputs&i,Heap&h){
 need((r==0x148000u||r==0x148400u)&&i.cx==0x81a820u);const unsigned actor=i.arg[1];need(kind(m,actor)==15u&&m.r8(actor+0x79u)==0u&&m.r32(0x78e5c4u)==0x505da0u);const auto type=m.r32(actor+0x5a8u);need(m.r32(type)==0x78ea78u&&m.r8(type+0x205u)==1u);for(unsigned k=0;k<4u;++k)need(m.r32(type+0x31cu+4u*k)==m.r32(0x78cfa0u+4u*k));
 // Real4C9D30 standard forwarding to Walk799968+74->714660 RET4.
 const auto walk=m.r32(actor+0x564u);need(m.r32(walk)==0x799968u&&m.r32(0x7999dcu)==0x714660u);
 // Real5CCB00 getter->Type509450 and482BB0 private two-row copy.
 need((m.r8(0xa5aa84u)&1u)&&(m.r8(0xa28d90u)&1u)&&m.r32(0xa5aa80u)==0x7fff7fffu&&m.r32(0x78e640u)==0x5ccb00u&&m.r32(0x78eb08u)==0x509450u&&m.r32(0xa28dbcu)==0u&&m.r32(0xa28dc0u)==0x7fff7fffu);
 const unsigned packed=m.r32(i.arg[0]);need(packed==0x00140001u&&m.r32(actor+0x88u)==256u&&m.r32(actor+0x8cu)==5120u&&m.r32(actor+0x90u)==0u);const auto cell=m.r32(m.r32(0x81a958u)+4u*10241u);need(cell&&m.r32(cell+0x24u)==packed);
 if(r==0x148000u){const auto head=m.r32(cell+0xe4u);need(head&&m.r32(actor+0x30u)==0u&&head!=actor&&m.r32(head+0x30u)!=actor);m.w32(actor+0x30u,head);m.w32(cell+0xe4u,actor);
  // Reuse1200 actualflat702C0->76AA50, then real564F30 positiveMap.
  need(m.r8(cell+0x11bu)==0u&&m.r8(cell+0x11cu)==0u&&m.r8(0x838f70u)==7u&&m.r32(0x838f80u)==104u&&m.r32(0xa57848u)==104u&&(m.r8(cell+0x12cu)&8u)==0u&&m.r32(0xa255c8u)==0u);fp::State f;f.image=fp::capture_host();f.load_integer32(0u);f.add64(0x3fe0000000000000ull);f.load_control(static_cast<unsigned short>(m.r32(0x7c3a04u)));need(f.pop_integer64()==0u);fp::restore_host(f.image);
 }else{const auto head=m.r32(cell+0xe4u);need(head);if(head==actor)m.w32(cell+0xe4u,m.r32(actor+0x30u));else{unsigned at=head,n=0u;while(m.r32(at+0x30u)!=actor){need(++n<=4u);at=m.r32(at+0x30u);need(at&&kind(m,at)==15u);}m.w32(at+0x30u,m.r32(actor+0x30u));}m.w32(actor+0x30u,0u);}
 cache(m,h,cell);return kind(m,actor);
}
}
