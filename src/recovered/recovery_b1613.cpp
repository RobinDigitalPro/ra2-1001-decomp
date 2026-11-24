#include "recovered/recovery_b1613.hpp"
#include <stdexcept>
namespace ra2::recovered::b1613 {
namespace {
void need(bool b){if(!b)throw std::domain_error("B1613 finite loaded one-cell integer placement");}
bool disjoint(U a,U an,U b,U bn){return std::uint64_t(a)+an<=b||std::uint64_t(b)+bn<=a;}
// Authentic57E6A0 ignores ECX. Its cold optional-grid branch returns full
// FFFFFFFF; the root flag branch subsequently discards this actual result.
U query(Memory&m,U packed){
 const U base=m.r32(0xa5863cu);if(!base)return 0xffffffffu;
 const U x=U(std::int32_t(std::int16_t(packed))),y=U(std::int32_t(std::int16_t(packed>>16)));
 return m.r32(base+80u*(x+y*m.r32(0x836b4cu))+0x38u);
}
// Exact47B190 full return, including upper EAX rather than its older AL mask.
U cell_predicate(Memory&m,U cell){
 const U value=m.r32(cell+0x38u);
 return (value&0xffffff00u)|((value==0u||value==0xffffu)?1u:0u);
}
U input_byte(U off){
 // Existing B1122 case0 binary record: one row/column and one52B entry.
 // The pointer DWORD at16 is checked separately after genuine relocation.
 if(off<16u)return off==0u||off==4u?1u:0u;
 const U k=off-20u;
 return k>=0x2bu&&k<0x31u?((k-0x2bu)*47u)&255u:(k*37u)&255u;
}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 need(root==0x15a430u&&i.arg[0]==0u&&i.arg[1]==0u&&(i.arg[5]&255u)==1u);
 const U type=m.r32(0x81b9c4u),types=m.r32(0xa28914u);
 need(type&&types&&m.r32(types+4u)==type);
 need(m.r32(type)==0x790188u&&m.r32(type+0x264u)==1u);
 need(m.r32(type+0x2b4u)==1u&&m.r32(type+0x2b8u)==1u&&m.r8(type+0xa8u)==1u);
 need(m.r32(0x7901b4u)==0x52c8e0u&&m.r32(0x790224u)==0x527630u);
 need(m.r32(0x7cae84u)==4u&&m.r32(0x7cae88u)==4u);
 need(m.r32(0xa547acu)==0u&&m.r32(0xa5863cu)==0u);
 need(m.r32(0x81a910u)==7u&&m.r32(0x81a914u)==11u&&m.r32(0x81b990u)==0x00070005u);
 const U blob=m.r32(type+0xa4u);need(blob&&std::uint64_t(blob)+80u<=0x100000000ull);
 for(U k=0;k<80u;++k)(void)heap.r8(blob+k); // Ownership/range only; padding values are unrestricted.
 need(heap.r32(blob+16u)==blob+20u);
 for(U k=0;k<72u;++k)if(k<16u||k>=20u)need(heap.r8(blob+k)==input_byte(k));
 const U table=m.r32(0x81a958u);need(table);const U cell=m.r32(table+4u*(5u+512u*7u));
 need(cell&&m.r32(cell+0x24u)==0x00070005u&&m.r32(cell+0x38u)==0u);
 need(i.arg[4]&&m.r8(i.arg[4])==0xa5u);
 need(disjoint(type,0x2dcu,cell,0x11cu)&&disjoint(type,0x2dcu,i.arg[4],1u)&&disjoint(cell,0x11cu,i.arg[4],1u));
 need(disjoint(blob,80u,type,0x2dcu)&&disjoint(blob,80u,cell,0x11cu)&&disjoint(blob,80u,i.arg[4],1u));
 // 790188+2C is the authentic constant-kind method52C8E0. The normal
 // primary addresspoint and exact slot are guarded above, not substituted callbacks.
 // Its full EAX=0x12 satisfies the kind gate on this authenticated table.
 if(i.arg[5]&255u)i.arg[3]=0u; //55A453 writes outer caller word3, not a private copy.
 //527630's genuine nonnull-A4 route has no loader call, stores or FP work.
 const U cached=m.r32(type+0xa4u);need(cached);
 U row=0u;
 for(;std::int32_t(row)<std::int32_t(m.r32(type+0x2b8u));++row){
  for(U col=0u;std::int32_t(col)<std::int32_t(m.r32(type+0x2b4u));++col){
   const U origin=m.r32(0x81b990u);
   const int x=int(std::int16_t(U(origin+col))),y=int(std::int16_t(U((origin>>16)+row)));
   const int width=int(m.r32(0x81a910u)),height=int(m.r32(0x81a914u));
   if(x+y<=width||x-y>=width||y-x>=width||x+y>width+2*height)continue;
   const U packed=U(std::uint16_t(x))|(U(std::uint16_t(y))<<16);
   const U index=U(x)+512u*U(y);need(index<0x40000u);
   const U target=m.r32(m.r32(0x81a958u)+4u*index);need(target==cell);
   const U linear=m.r32(type+0x2b4u)*row+col;
   const U entry=heap.r32(cached+16u+4u*linear);need(entry==blob+20u);
   U observed=query(m,packed);
   //55A566..576: flag1 XOR EAX discards the genuine full query return.
   if(i.arg[5]&255u)observed=0u;
   need(observed==i.arg[3]);
   const U old=m.r32(target+0x38u)-m.r32(0xa547acu),next=m.r32(type+0x264u)-m.r32(0xa547acu);
   need(old<=0x29u&&next<=0x29u);
   const int delta=int(m.r32(0x7cae84u+4u*old))-int(m.r32(0x7cae84u+4u*next));
   const unsigned distance=unsigned(delta<0?-delta:delta);need(distance<3u);
   need((cell_predicate(m,target)&255u)==1u);
   // Positive55A640..65C writes; every value comes from the real graph.
   m.w32(target+0x38u,m.r32(type+0x264u));
   m.w8(target+0x11au,linear&255u);
   m.w8(target+0x11bu,(heap.r8(entry+0x28u)+(i.arg[2]&255u))&255u);
  }
 }
 // Loop row is full1 before the final MOV AL,1. No x87 operation or image
 // assignment occurs anywhere: all86 numeric bytes, including raw80, remain input.
 return (row&0xffffff00u)|1u;
}
}
