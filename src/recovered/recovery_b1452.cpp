#include "recovered/recovery_b1452.hpp"
#include "recovered/text_bytes.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_004f47f0(Memory&,const Inputs&);
std::uint32_t fun_006eedc0(Memory&,const Inputs&);
}
namespace ra2::recovered::b1452 {
namespace {using U=std::uint32_t;void need(bool v,const char*s){if(!v)throw std::domain_error(s);}}
U configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1452 actual CRTsetter argument");m.w32(0x817554,0);return 1;}
U fun_00636690(Memory&m,const Inputs&i,Heap&h){
 const U self=i.cx;
 need(m.r32(0x817554)==0,"1452 produced ordinary CRT configuration");
 need(self==0xa9e820&&m.r32(self)==0x793e94&&m.r32(self+4)&&m.r32(self+8)>=1&&m.r32(self+8)<=10&&m.r8(self+0xc)==1&&m.r8(self+0xd)==0&&m.r32(self+0x10)==0&&m.r32(self+0x14)==10,"1452 genuine fresh nonowning reserved vector");
 need(m.r32(0xa1a5d8)==1&&m.r32(0xa1a5cc)&&m.r32(0xa255c8)==0&&m.r32(0xa27db8)==0&&m.r32(0xa27f14)==0xffffffff&&m.r32(0xab7edc)==0,"1452 configured mode0 one-house empty-peer projection");
 const U house=m.r32(m.r32(0xa1a5cc));
 need(m.r32(house)==0x78dde0&&m.r32(house+0x30)==0&&m.r8(house+0x134)==0&&m.r8(house+0x135)==1&&m.r8(house+0x13e)==0,"1452 concrete configured firsthouse");
 static constexpr std::array<U,6> name{{'H','o','u','s','e',0}};
 for(U k=0;k<name.size();++k)need(m.r16(house+0x15f16+2*k)==name[k],"1452 genuine bounded type-name copy");
 global_b26::Inputs call=i;call.cx=house;
 need((global_b26::fun_004f47f0(m,call)&255u)!=0,"1452 actual PlayerControl predicate");
 const U owner=h.allocate(40);need(owner!=0,"1452 positive actual allocation");h.w8(owner,0);
 call.cx=house+0x15f16;const U converted=global_b26::fun_006eedc0(m,call);
 std::array<std::uint8_t,20> input{},output{};for(U k=0;k<20;++k)input[k]=std::uint8_t(m.r8(converted+k));
 ra2::recovered::fun_0076dd10(output.data(),input.data(),20);for(U k=0;k<20;++k)h.w8(owner+1+k,output[k]);
 // Peer count0 leaves every byte15..24 untouched, including private-query output21..24.
 h.w8(owner+0x27,1);h.w8(owner+0x25,m.r32(0xa27f14)==m.r32(house+0x30));h.w8(owner+0x26,1);
 const U count=m.r32(self+0x10),table=m.r32(self+4);m.w32(self+0x10,count+1);m.w32(table+4*count,owner);
 return m.r32(0xa1a5d8); // Original finalMOV EAX replaces all helper residues.
}
}
