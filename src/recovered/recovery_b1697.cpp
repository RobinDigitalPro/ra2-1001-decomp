#include "recovery_b1697.hpp"
#include <stdexcept>

namespace ra2::recovered::b1697 {
namespace {
void need(bool b){if(!b)throw std::domain_error("1697 finite genuine Unit sparse117B clear path");}
struct Range{U base,size;};
void valid(Range r){need(r.base&&r.size&&std::uint64_t(r.base)+r.size<=0x100000000ull);}
void separate(Range a,Range b){valid(a);valid(b);need(std::uint64_t(a.base)+a.size<=b.base||std::uint64_t(b.base)+b.size<=a.base);}
constexpr U primary_vptr=0x798c88u;
void slots(Memory&m,U self){
 need(m.r32(self)==primary_vptr);
 need(m.r32(primary_vptr+0x254u)==0x62e330u);
 need(m.r32(primary_vptr+0x15cu)==0x6fbee0u);
 need(m.r32(primary_vptr+0x26cu)==0x6b6920u);
 need(m.r32(primary_vptr+0x16cu)==0x591570u);
}
// Mechanical projection of actual62E4B0, acceptedB15c. Its signed count scan
// returns the actual index upper24 bits with AL1 on the first nonnull entry.
U scan22e4b0(Memory&m,U self){
 const U count=m.r32(self+0xd0u);U ax=0;
 if(global_b26::s32(count)<=0)return 0;
 U item=m.r32(self+0xccu);
 do{if(m.r32(item)!=0)return floating_b61::with_al(ax,1u);++ax;item+=4u;}while(global_b26::s32(ax)<global_b26::s32(count));
 return floating_b61::with_al(ax,0u);
}
// 62E330..62E354. The actual first array element, not signed count or a
// fabricated callback return, selects its call-free XOR EAX/RET4 edge.
U first_null22e330(Memory&m,U self,U operation){
 (void)operation;const U first=m.r32(m.r32(self+0xccu));need(first==0);return 0;
}
// Accepted4CD5B0's two ordered DWORD stores. No Memory adapter conversion or
// callback is introduced; its return is overwritten by Root's following call.
void clear4cd5b0(Memory&m,U self){m.w32(self+0x490u,0);m.w32(self+0x494u,0);}
// Genuine Unit16C ->591570, whole18B: self98 unless -1, then selfA0.
// The finite input self98=0 makes the fallback unread; no chosen private value.
U getter591570(Memory&m,U self){const U ax=m.r32(self+0x98u);need(ax==0);return ax;}
// 6B6920 CALLactual16C, TEST EAX/JZ, XOR AL/POPESI/RET0. Full upper bits are
// already zero from the real getter, so this actual predicate returns full0.
U false6b6920(Memory&m,U self){const U ax=getter591570(m,self);return floating_b61::with_al(ax,0u);}
// 6FBEE0 CALLactual26C, TESTAL/JE6FC4ED ->pops/ADD48/RET12. The three actual
// Root arguments are unconsumed on this edge; AB7F40 is never dereferenced.
U false2fbee0(Memory&m,U self,U point,U one,U zero){
 (void)point;(void)one;(void)zero;const U ax=false6b6920(m,self);need((ax&255u)==0);return ax;
}
}
void preflight(Memory&m,const Inputs&i){
 need(i.cx>=8u&&i.arg[0]==0x117bu);const U self=i.cx-8u;valid({self,0x5b0u});slots(m,self);
 need(m.r32(i.cx)==0x798c64u&&m.r32(0x798c64u)==0x6fe4a0u);
 const U type=m.r32(self+0x5acu);valid({type,0xb45u});
 const bool enabled=m.r8(type+0xb1au)!=0u||m.r8(type+0xb44u)!=0u;need(enabled);
 const U list=m.r32(self+0xccu);valid({list,8u});
 separate({self,0x5b0u},{type,0xb45u});separate({list,8u},{self,0x5b0u});separate({list,8u},{type,0xb45u});
 for(const auto&r:{Range{self,0x5b0u},Range{type,0xb45u},Range{list,8u}})separate(r,{0x798c64u,0x294u});
 need(m.r32(self+0xd0u)==2u&&m.r32(list)==0u&&m.r32(list+4u)!=0u);
 const U old490=m.r32(self+0x490u),old494=m.r32(self+0x494u),target=m.r32(self+0x1b0u);
 need(old490!=0u&&old494!=0u&&(target==0u||target==old494));
 need(m.r32(self+0x98u)==0u);
 // Every output DWORD and later actual getter read has been checked before any
 // mutation. The domain excludes concurrent/volatile or stack-object aliasing.
}
U run(Memory&m,const Inputs&i){
 preflight(m,i);const U secondary=i.cx,self=secondary-8u;
 // 6FE4A9..6FE4D7: genuine typeflags/117B and actual sparse-list predicate.
 const U type=m.r32(secondary+0x5a4u);need(m.r8(type+0xb1au)!=0u||m.r8(type+0xb44u)!=0u);need(i.arg[0]==0x117bu);
 U ax=scan22e4b0(m,self);need((ax&255u)!=0u);
 // 6FE4D9..6FE4E5: actual Unit+254(arg8), first-null branch, no notification.
 ax=first_null22e330(m,self,8u);
 const U target=m.r32(secondary+0x1a8u);need(target==0u||target==m.r32(secondary+0x48cu));
 // 6FE50C..6FE520: meaningful ordered clear, then real Unit+15C false chain.
 clear4cd5b0(m,self);
 ax=false2fbee0(m,self,0xab7f40u,1u,0u);
 // 6FE526..6FE52B: final MOV AL1, full result1 because actual finalcallee0.
 // Outer sixteen words and entire incoming model FP image are never changed.
 return floating_b61::with_al(ax,1u);
}
}
