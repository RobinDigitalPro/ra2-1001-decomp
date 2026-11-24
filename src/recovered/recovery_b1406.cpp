#include "recovery_b1406.hpp"
#include "recovered/preallocated_b66.hpp"
#include "recovered/leaf_b15_a.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1406 {
using U=std::uint32_t;
void need(bool b,const char* message){if(!b)throw std::domain_error(message);}
namespace {
void append(Memory& m,U count_at,U capacity_at,U table_at,U self){const U n=m.r32(count_at);need(global_b26::s32(n)>=0&&global_b26::s32(n)<global_b26::s32(m.r32(capacity_at)),"B1406 actual signed capacity-room append");m.w32(count_at,n+1u);m.w32(m.r32(table_at)+4u*n,self);}
void init16(Memory& m,U c){
 std::array<std::uint8_t,16> bytes{};for(U k=0;k<16u;++k)bytes[k]=std::uint8_t(m.r8(c+k));
 leaf::Memory local(bytes.data(),c,16u);leaf::Inputs in{};in.cx=c;(void)leaf::fun_00405bf0(local,in);
 for(U k=0;k<16u;++k)m.w8(c+k,bytes[k]);
}
//Exact finite5CA970 adapter, as B1385/B1387; no broad unrelated constructor TU.
void base(Memory&m,U c){
 (void)global_b26::fun_0040ff10_composed(m,c);
 m.w32(c+0x24u,0);m.w32(c+0x28u,0);m.w32(c+0x2cu,0);m.w32(c+0x6cu,255u);m.w32(c+0x70u,255u);
 m.w8(c+0x76u,1);m.w8(c+0x7du,1);m.w8(c+0x85u,1);m.w32(c+0x30u,0);m.w32(c+0x34u,0);m.w32(c+0x38u,0);m.w32(c+0x64u,0xffffffffu);
 for(U o:{0x68u,0x74u,0x75u,0x77u,0x78u,0x79u,0x7au,0x7bu,0x7cu})m.w8(c+o,0);
 m.w32(c+0x80u,0xffffffffu);m.w8(c+0x84u,0);
 const U x=m.r32(0xa5aa68u);m.w32(c+0x88u,x);m.w32(c+0x8cu,m.r32(0xa5aa6cu));const U z=m.r32(0xa5aa70u);
 m.w32(c+0x94u,0);m.w32(c,0x792458u);m.w32(c+0x90u,z);m.w32(c+4u,0x79243cu);m.w32(c+8u,0x792434u);m.w32(c+12u,0x79242cu);
 init16(m,c+0x3cu);init16(m,c+0x50u);
 append(m,0xa27fc8u,0xa27fc0u,0xa27fbcu,c);append(m,0xaa8878u,0xaa8870u,0xaa886cu,c);
 append(m,0xaa87c8u,0xaa87c0u,0xaa87bcu,c);append(m,0xaa8770u,0xaa8768u,0xaa8764u,c);
 m.w8(c+0x14u,m.r8(c+0x14u)|2u);
}
}
U configure_crt(Memory& m,const Inputs& i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
U fun_00716290(Memory& m,const Inputs& i,Heap& heap){
 need(m.r8(0xb0cfccu)==1u,"B1406 exact produced warm LUT prestate");
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"B1406 actual configured ordinary CRT");
 const U self=i.cx;base(m,self);
 m.w32(self+0x120u,0u);m.w32(self+0x128u,0u);m.w32(self+0x98u,0u);
 m.w8(self+0x118u,1u);m.w8(self+0x119u,0u);m.w32(self+0x11cu,100u);
 for(U off:{0x124u,0x12cu,0x130u,0x134u,0x168u,0x16cu,0x170u,0x198u,0x19cu})m.w32(self+off,0u);
 //Actual4B8640: partial WORD writes deliberately preserve adjacent bytes.
 const U timer=self+0x1a0u;m.w16(timer,0u);m.w16(timer+4u,0u);
 const U epoch=m.r32(0xa2896cu);m.w32(timer+0x10u,0u);m.w32(timer+8u,epoch);m.w16(timer+0x14u,0u);
 m.w32(self+0x1bcu,0u);m.w32(self+0x1c0u,5u);m.w8(self+0x1c4u,1u);m.w8(self+0x1c5u,0u);m.w32(self+0x1b8u,0x790998u);
 const U storage=heap.allocate(20u);need(storage!=0u,"B1406 genuine allocation success");
 m.w32(self+0x1bcu,storage);m.w8(self+0x1c5u,1u);m.w32(self+0x1b8u,0x790ee4u);m.w32(self+0x1ccu,10u);m.w32(self+0x1c8u,0u);
 m.w32(self,0x799b60u);m.w32(self+4u,0x799b44u);m.w32(self+8u,0x799b3cu);m.w32(self+12u,0x799b34u);
 const U count=m.r32(0xa28838u),capacity=m.r32(0xa28830u);
 need(global_b26::s32(count)>=0&&global_b26::s32(count)<global_b26::s32(capacity),"B1406 fifth actual signed capacity-room append");
 m.w32(0xa28838u,count+1u);m.w32(m.r32(0xa2882cu)+4u*count,self);
 //Original warm branch skips the pinned cold producer; fixture establishes all tables.
 return self;
}
}
