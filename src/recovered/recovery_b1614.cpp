#include "recovered/recovery_b1614.hpp"
#include <stdexcept>
namespace ra2::recovered::b1614 {
namespace {
void need(bool b){if(!b)throw std::domain_error("B1614 finite one44B record and normal spare reference slot");}
bool disjoint(U a,U an,U b,U bn){return std::uint64_t(a)+an<=b||std::uint64_t(b)+bn<=a;}
void w16(Heap&h,U p,U x){h.w8(p,x&255u);h.w8(p+1u,(x>>8)&255u);}
// Actual7209C0 initialization. Bytes15/16/17/37 hexadecimal are not
// written here or by the decoder: their actual fresh allocation values survive.
void construct_record(Heap&h,U p){
 h.w32(p+4u,0u);h.w32(p,0x79a168u);h.w32(p+8u,0u);
 h.w8(p+0xeu,10u);h.w8(p+0xfu,10u);w16(h,p+0x10u,10000u);w16(h,p+0xcu,0u);
 for(U off:{0x1du,0x1eu,0x1fu,0x22u,0x25u,0x28u,0x2eu,0x31u,0x34u})h.w8(p+off,0u);
 for(U off:{0x20u,0x23u,0x26u,0x29u,0x2cu,0x2fu,0x32u,0x35u})h.w8(p+off,100u);
 h.w8(p+0x12u,1u);h.w8(p+0x13u,1u);h.w8(p+0x14u,2u);h.w8(p+0x1cu,1u);
 for(U off:{0x21u,0x24u,0x27u,0x2au,0x2du,0x30u,0x33u,0x36u})h.w8(p+off,50u);
 h.w8(p+0x2bu,1u);h.w32(p+0x38u,0xffffffffu);h.w32(p+0x3cu,0xffffffffu);
}
struct Reference{U tag,pointer;};
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 const U owner=i.cx,input=i.arg[0],vector=owner+0x2cu;
 need(root==0x321050u&&owner&&input&&i.arg[1]==44u);
 need(std::uint64_t(owner)+0x44u<=0x100000000ull&&std::uint64_t(input)+44u<=0x100000000ull);
 need(disjoint(owner,0x44u,input,44u));
 need(m.r32(owner+0x20u)==0u&&m.r32(vector)==0x79a1a8u);
 need(m.r32(vector+8u)==2u&&m.r8(vector+12u)==1u&&m.r8(vector+13u)==1u);
 need(m.r32(vector+16u)==0u&&m.r32(vector+20u)==10u);
 need(m.r32(0x79a170u)==0x630cc0u);
 const U data=m.r32(vector+4u);need(data>=4u);const U backing=data-4u;
 need(std::uint64_t(backing)+32u<=0x100000000ull&&heap.r32(backing)==2u);
 need(disjoint(backing,32u,owner,0x44u)&&disjoint(backing,32u,input,44u));
 for(U k=0;k<32u;++k)(void)heap.r8(backing+k); // Actual range only; padding has no value guard.
 for(U n=0;n<2u;++n)need(heap.r32(data+8u*n)==0x78f52cu&&heap.r32(data+8u*n+4u)==0u);
 for(U k=0;k<44u;++k)(void)m.r8(input+k);
 m.w32(owner+0x20u,0u); //721062 reset before parsing.
 const U record=heap.allocate(64u);need(record);
 need(std::uint64_t(record)+64u<=0x100000000ull&&disjoint(record,64u,backing,32u));
 need(disjoint(record,64u,owner,0x44u)&&disjoint(record,64u,input,44u));
 construct_record(heap,record);
 //721660 ->630A80 initializes the actual local reference, then630AD0
 // acquires the new record. No initial private frame word is consumed.
 Reference local{0x793cccu,0u};local.tag=0x78f52cu;
 heap.w32(record+4u,heap.r32(record+4u)+1u);local.pointer=record;
 heap.w32(record+8u,m.r32(owner+0x20u));
 U consumed=0u;
 const auto byte=[&](){return m.r8(input+consumed++);};
 const auto be16=[&](){const U high=byte(),low=byte();return (high<<8)|low;};
 const auto be32=[&](){U x=0u;for(unsigned k=0;k<4u;++k)x=(x<<8)|byte();return x;};
 w16(heap,record+0xcu,be16());
 heap.w8(record+0xeu,(byte()+0x80u)&255u);
 heap.w8(record+0xfu,(byte()+0x80u)&255u);
 w16(heap,record+0x10u,be16());
 const U nibbles=byte()-0x80u;
 heap.w8(record+0x1cu,nibbles&15u);heap.w8(record+0x1du,(nibbles>>4)&15u);
 heap.w8(record+0x1eu,(byte()+0x80u)&255u);
 heap.w8(record+0x12u,(byte()+0x80u)&255u);
 heap.w8(record+0x13u,(byte()+0x80u)&255u);
 heap.w8(record+0x14u,(byte()+0x80u)&255u);
 heap.w32(record+0x18u,byte()-0x80u);
 // Input12..35 each retain0..127, or subtract128 for128..255.
 // The destination permutation is the actual721199..721479 store order.
 constexpr U offsets[]{0x1fu,0x20u,0x21u,0x22u,0x23u,0x24u,0x25u,0x26u,0x27u,
  0x2bu,0x2cu,0x2du,0x2eu,0x2fu,0x30u,0x28u,0x29u,0x2au,
  0x31u,0x32u,0x33u,0x34u,0x35u,0x36u};
 for(U off:offsets){const U value=byte();heap.w8(record+off,value>127u?value-128u:value);}
 heap.w32(record+0x3cu,be32());heap.w32(record+0x38u,be32());need(consumed==44u);
 // Count0 < capacity2 excludes the original virtual reserve branch.
 const U count=m.r32(vector+16u);need(count<m.r32(vector+8u));
 const U slot=data+8u*count;need(heap.r32(slot+4u)==0u);
 m.w32(vector+16u,count+1u);
 // Actual630AD0: retain before replacing a normally constructed null slot.
 heap.w32(record+4u,heap.r32(record+4u)+1u);heap.w32(slot+4u,local.pointer);
 m.w32(owner+0x20u,m.r32(owner+0x20u)+1u);
 //630AB0 then real79A168+8/630CC0. Refcount2->1 avoids deleting calls.
 local.tag=0x78f52cu;const U referent=local.pointer;
 local.tag=0x793cccu;local.pointer=0u;
 need(heap.r32(referent)==0x79a168u);
 const U released=heap.r32(referent+4u)-1u;heap.w32(referent+4u,released);need(released==1u);
 // Source touches neither FP nor caller words. Actual final MOV AL,1 retains
 // the full upper EAX from the real release result; original outer RET is8.
 return (released&0xffffff00u)|1u;
}
}
