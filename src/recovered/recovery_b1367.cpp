#include "recovery_b1367.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1367 {
namespace {using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U original_406f30(Memory&m){return m.r32(0x819778u)!=0?1u:0u;}
U original_4068f0(U eax){return eax;} // Actual single C3, no memory read.
U original_668c80(Memory&m,U self){return m.r32(self+0x120u)==0xfffffffeu?0xfffffffeu:m.r32(self+0x11cu);}
U original_621b70(U& state,U unit){state=(state<<1u)+(state>>31u)+unit;return state;}
U original_5b6c30(Memory&m,U source){
 need(m.r32(0xb10530u)==0,"1367 actual uppercase CRT fast path");
 // Actual 76EFC9 produces the private UTF16 copy, including its terminator.
 std::array<std::uint16_t,80> local;U count=0;
 for(;;){need(count<32,"1367 bounded UTF16 source");local[count]=m.r16(source+2*count);if(local[count++]==0)break;}
 need(count>1,"1367 nonempty useful hash input");
 // Actual782826 mutates only ASCII lowercase units; other UTF16 units survive.
 for(U k=0;local[k]!=0;++k)if(local[k]>=0x61&&local[k]<=0x7a)local[k]=std::uint16_t(local[k]-0x20);
 auto original_76ef45=[&](){U n=0;while(local[n]!=0)++n;return n;};
 U state=0; // Actual5B6C3F initializes this DWORD before any hash read.
 for(U k=0;k<original_76ef45();++k)(void)original_621b70(state,local[k]);
 return state;
}
U original_6dd170_positive_null_provider(Memory&m,U self,U index){
 need(m.r8(0xa28858u)==1&&original_406f30(m)==1&&m.r8(0xa2894cu)==0&&m.r32(self+0x2cu)==0,"1367 active query with no attached provider");
 need(m.r32(self)!=0xffffffffu&&index<=3&&m.r32(self+0xcu)>index&&m.r8(self+0x10u)==1&&m.r8(0x838b70u)==1,"1367 ordinary positive queued index and explicit lookup bypass");
 // The second real406F30 gates cancellation; original logger consumes only
 // private arguments. No 407E60 call occurs because self2C is genuinely null.
 need(original_406f30(m)==1,"1367 second original query");
 (void)original_4068f0(m.r32(self+4));
 m.w32(self,0xffffffffu);m.w32(self+4,0xffffffffu);m.w32(self+8,0xffffffffu);m.w8(self+0x11,0);
 m.w32(self+4,index); // Positive EDI branch, then838B70 makes EAX0.
 m.w32(self,0xffffffffu); // Exact6DD2D0 null-provider branch.
 (void)original_4068f0(0x7e1c50u); // self10==1 skips record-array reads.
 m.w32(self+8,index);return m.r32(self);
}
}
U fun_005be8d0(Memory&m,const Inputs&i){
 need(m.r32(0xa5a874u)==0&&m.r32(0xa27db8u)==1,"1367 local-only metadata publication");
 // The actual root explicitly produces all0x1C7 packet bytes before copies.
 std::array<std::uint8_t,0x1c7> packet{};packet[0]=0x18;
 auto copy=[&](U src,U dst){for(U k=0;;++k){need(k<=12,"1367 bounded ANSI packet input");const auto v=m.r8(src+k);packet[dst+k]=v;if(v==0)break;}};
 copy(0xa256d0u,4);copy(i.dx,0x2f);
 m.w32(0xa27b25u,original_668c80(m,0xa255c8u));
 m.w32(0xa27b29u,original_5b6c30(m,0xa2793eu));
 return m.r32(0xa27db8u); // Count1 skips only the remote-peer loop.
}
U fun_006dcf90(Memory&m,const Inputs&i){
 need(original_406f30(m)==1&&m.r8(0xa2894cu)==0&&m.r8(0xa28858u)==1&&m.r32(0xa283c4u)==0,"1367 original queue processing guards");
 const U index=m.r32(i.cx+8);
 need(m.r32(i.cx+0xcu)>index&&index<=3&&m.r32(i.cx+0x2cu)==0,"1367 present nonnegative pending index");
 const U eax=original_6dd170_positive_null_provider(m,i.cx,index);
 m.w32(i.cx+8,0xfffffffeu);return eax;
}
U fun_00736460(Memory&m,const Inputs&){
 need(m.r8(0xb100a0u)==0&&m.r32(0xa255c8u)==3&&m.r32(0xa5a874u)==0,"1367 borrowed mode publication without optional object");
 m.w8(0xb100a0u,1);return m.r32(0xa5a874u);
}
}
