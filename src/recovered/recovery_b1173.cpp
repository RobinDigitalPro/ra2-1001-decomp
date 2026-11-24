#include "recovery_b1173.hpp"
#include <stdexcept>
namespace ra2::recovered::b1173{
static void need(bool v){if(!v)throw std::domain_error("1173 actual fresh Map table initialization");}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){const auto self=i.cx;need(root==0x145860u&&(self==base+0x1000u||self==base+0x4000u)&&m.r32(self+0x134u)==0x790998u&&m.r32(self+0x138u)==0u&&m.r32(self+0x13cu)==0u&&m.r8(self+0x140u)==1u&&m.r8(self+0x141u)==0u&&m.r32(0x7909a0u)==0x5688b0u);
 // Empty current table is the exact544DF0 constructor poststate. The root
 // still performs a positive1MiB owned allocation and fills every DWORD.
 // Mandatory527970 is original XOR AL,AL;RET. Later EAX is fully overwritten.
 // Real790998+8=5688B0 RET8 receives(capacity40000,externalNULL).
 ++z.virtual_callbacks;m.w8(self+0x140u,0u);const auto table=h.allocate(0x100000u);++z.allocations;m.w8(self+0x140u,1u);need(table!=0u);m.w32(self+0x138u,table);m.w32(self+0x13cu,0x40000u);m.w8(self+0x141u,1u);
 for(unsigned n=0;n<0x40000u;++n)h.w32(table+4u*n,0u);return 0x40000u;
}
unsigned cleanup(Memory&m,unsigned self,Heap&h){need(m.r32(self+0x134u)==0x790998u&&m.r32(0x7909a4u)==0x568960u&&m.r32(self+0x13cu)==0x40000u&&m.r8(self+0x141u)==1u);const auto result=h.release(m.r32(self+0x138u));need(result!=0u);m.w32(self+0x138u,0u);m.w8(self+0x141u,0u);m.w32(self+0x13cu,0u);return result;}
}
