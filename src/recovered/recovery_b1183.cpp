#include "recovery_b1183.hpp"
#include <stdexcept>
namespace ra2::recovered::b1183{
namespace fp=platform::x87;static void need(bool x){if(!x)throw std::domain_error("1183 original locomotion start");}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned a,Observation&z){need((root==0xbed40u||root==0x12df00u)&&i.cx==a+0x2000u);const unsigned loco=i.cx,actor=m.r32(loco+12u),desc=m.r32(actor+0x5a8u),grid=0x8221e0u+24u*399u;need(actor==a+0x1000u&&m.r32(actor)==0x78e540u&&m.r32(actor+0x458u)==0u&&m.r32(actor+0x88u)==5120u&&m.r32(actor+0x8cu)==5120u&&m.r32(actor+0x90u)==0u&&desc==a+0x2400u&&m.r32(desc)==0x78ea78u&&m.r32(desc+0x4b0u)==0xffffffffu&&m.r32(desc+0x558u)==0xffffffffu&&m.r32(0x821b88u)==a+0x3c00u&&m.r32(a+0x42dcu)==500u&&m.r32(0xa2896cu)==0u);fp::State f;f.image=fp::capture_host();
 if(root==0xbed40u){need(m.r32(loco)==0x78c0ccu&&m.r32(actor+0x3fcu)==0u&&m.r32(actor+0x594u)==0u&&m.r8(actor+0x204u)==0u&&m.r8(actor+0x205u)==0u);m.w8(loco+0x51u,0u);m.w8(loco+0x50u,1u);z.virtual_callbacks=13u;}
 else{need(m.r32(loco)==0x79034cu&&m.r32(loco+4u)==0x790284u&&m.r8(loco+0x48u)==1u&&m.r32(loco+0x28u)==500u);f.load64(0x3ff0000000000000ull);f.compare_pop64(0x3ff0000000000000ull);m.w32(actor+0x468u,0u);m.w32(actor+0x46cu,0x3ff00000u);m.w32(loco+0x50u,0u);m.w32(loco+0x54u,0u);m.w32(loco+0x58u,0u);m.w32(loco+0x5cu,0u);m.w32(loco+0x60u,0u);for(unsigned p:{0x68u,0x6cu,0x70u,0x74u})m.w32(loco+p,0u);m.w32(loco+0x78u,500u);z.virtual_callbacks=5u;}
 // True4131E0 atCell20,20, dimensions39 =>clampedbucket399; preownedcap10.
 const unsigned n=m.r32(grid+16u),data=m.r32(grid+4u);need(n==1u&&m.r32(grid)==0x78579cu&&m.r32(grid+8u)==10u&&data);m.w32(actor+0x458u,0x140014u);m.w32(grid+16u,n+1u);h.w32(data+4u*n,actor);z.insertions=1u;
 unsigned eax=n;if(root==0xbed40u){m.w32(loco+0x38u,500u);
 // Flat0/shape0 actual4702C0: genuinewarm104cache. _ftol leavesglobalCW.
 need(m.r8(a+0x91bu)==0u&&m.r8(a+0x91cu)==0u&&m.r32(0x838f80u)==104u&&m.r8(0x838f70u)==7u);f.load_integer32(0u);f.add64(0x3fe0000000000000ull);f.load_control(static_cast<unsigned short>(m.r32(0x7c3a04u)));need(f.pop_integer64()==0u);
 // 5CCEA0 priorlocalworldX is theactual4B8780 entryS-8 writer.
 m.w32(actor+0x2e8u,0u);m.w32(actor+0x2ecu,5120u);m.w32(actor+0x2f0u,0u);eax=0u;
 }else m.w32(loco+0x4cu,1u);
 fp::restore_host(f.image);return eax;}
unsigned cleanup(Memory&m,unsigned self,Heap&h){need(self==0x8221e0u+24u*399u&&m.r8(self+13u)==1u);m.w32(self+16u,0u);const unsigned q=m.r32(self+4u),result=h.release(q);need(result);m.w32(self+4u,0u);m.w32(self+8u,0u);m.w8(self+13u,0u);return result;}
}
