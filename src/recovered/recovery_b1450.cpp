#include "recovered/recovery_b1450.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
namespace ra2::recovered::b1450 {
namespace {
using U=std::uint32_t;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
// Exact selected50BE00 branch. Original initializes12B, not the adjacent
// completion byte. Neither fixedname reaches the completion-byte write.
U empty_section(Memory&m,U self,const std::uint8_t*text,std::int32_t length){
 NameHashState state;state.accumulator=0;state.pending=0;state.scratch.fill(0);
 const U hash=fun_00493da0(state,text,length);(void)hash;
 need(m.r32(self+0x24)==0,"1450 actual emptyINI count");return 0;
}
}
U configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1450 actual CRTsetter argument");m.w32(0x817554,0);return 1;}
U fun_00709100(Memory&m,const Inputs&i,Heap&h){
 const U p=i.cx;need(m.r32(0x817554)==0,"1450 produced ordinaryCRT config");
 need(m.r32(p)==0x78db34&&m.r32(p+4)==0x785aec&&m.r32(p+8)==0x785afc&&m.r32(p+0xc)==p+0x14&&m.r32(p+0x10)==0&&m.r32(p+0x14)==0x785afc&&m.r32(p+0x18)==0&&m.r32(p+0x1c)==p+8,"1450 actual51A2C0 receiver/sentinels");
 need(m.r32(p+0x20)==0&&m.r32(p+0x24)==0&&m.r32(p+0x28)==0&&m.r8(p+0x2c)==0&&m.r32(p+0x30)==0&&m.r32(p+0x34)==0,"1450 constructor-compatible emptyINI");
 for(U at:{0xab8250u,0xab8254u,0xab8258u,0xab82c4u,0xab82c8u,0xab82ccu})need(m.r32(at)==0,"1450 firststart exactoriginal globals");
 //4071F0 and407400: one genuine owner, never borrowed allocator memory.
 m.w32(0xab8250,0xab8250);m.w32(0xab8254,0xab8250);m.w32(0xab8258,0xab8250);
 const U owner=h.allocate(100u*(60u+8u)+8u);need(owner!=0,"1450 real positiveallocation");
 U node=owner+8;h.w32(owner,node);for(U left=99;left;--left){const U next=node+68;h.w32(node,next);node=next;}h.w32(node,0);
 m.w32(0xab82c4,owner);m.w32(0xab82c8,0);m.w32(0xab82cc,0);
 static constexpr std::uint8_t defaults[]{'D','e','f','a','u','l','t','s',0};
 static constexpr std::uint8_t sounds[]{'S','o','u','n','d','L','i','s','t',0};
 need(empty_section(m,p,defaults,8)==0,"1450 absentDefaults");return empty_section(m,p,sounds,9);
}
}
