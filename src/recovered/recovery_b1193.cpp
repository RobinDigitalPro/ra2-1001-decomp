#include "recovery_b1193.hpp"
#include <stdexcept>
namespace ra2::recovered::b1193{
static void need(bool x){if(!x)throw std::domain_error("1193 positive realDirectDraw route");}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&api,unsigned root,Observation&seen){
 if(root==0x95750u){need(m.r32(0x83a6fcu)==0u&&m.r8(0x839fe0u)==1u&&m.r32(0xb0de50u)==0u);const unsigned create=api.create_draw(0u,0x83a6fcu,0u);++seen.provider_calls;need(create==0u&&m.r32(0x83a6fcu)!=0u);const unsigned result=api.normal(m.r32(0x83a6fcu),m.r32(0xb0de50u),8u);++seen.provider_calls;need(result==0u);return result;}
 need(root==0xaa1b0u&&i.arg[0]==16u&&i.arg[1]==12u&&i.arg[2]==1u&&m.r8(0x83b307u)==0u&&m.r32(0x83a6fcu));const unsigned self=i.cx;m.w32(self+4u,i.arg[0]);m.w32(self+8u,i.arg[1]);for(unsigned o:{0xcu,0x10u,0x14u,0x1cu,0x20u})m.w32(self+o,0u);m.w8(self+0x18u,0u);m.w8(self+0x19u,0u);m.w32(self,0x78bbe4u);const unsigned desc=h.allocate(108u);++seen.allocations;need(desc);m.w32(self+0x20u,desc);for(unsigned k=0;k<108u;++k)h.w8(desc+k,0u);h.w32(desc,108u);h.w32(desc+4u,7u);h.w32(desc+8u,i.arg[1]);h.w32(desc+12u,i.arg[0]);h.w32(desc+0x68u,0x800u);const unsigned ch=api.create_surface(m.r32(0x83a6fcu),desc,self+0x1cu,0u);++seen.provider_calls;need(ch==0u&&m.r32(self+0x1cu));for(unsigned k=0;k<108u;++k)h.w8(desc+k,0u);h.w32(desc,108u);const unsigned dh=api.describe(m.r32(self+0x1cu),desc);++seen.provider_calls;need(dh==0u);m.w32(self+0x10u,(h.r32(desc+0x54u)+7u)>>3u);m.w8(self+0x19u,(h.r32(desc+0x68u)>>14u)&1u);return self;}
}
