#include "recovered/recovery_b1475.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/floating_b61_c.hpp"
#include "recovered/recovery_b456.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1475 {
namespace {
using U=std::uint32_t;using FP=platform::x87::State;
using floating_b61::read64;using floating_b61::write64;using floating_b61::s32;
void need(bool value,const char*why){if(!value)throw std::domain_error(why);}
// Exact76AA50: conversion changes the guest CW to the original global word.
U integer(Memory&m,FP&fp){const auto cw=std::uint16_t(m.r32(0x7c3a04u));if(fp.control()!=cw)fp.load_control(cw);return U(fp.pop_integer64());}
// Live branch545490. The original fallback rewrites its own caller argument;
// this finite map has an actual allocated table and a nonnull referenced cell.
U cell(Memory&m,U point){
 const auto x=s32(m.r32(point))/256,y=s32(m.r32(point+4u))/256;const auto index=y*512+x;
 need(index>=0&&index<s32(m.r32(0x81a95cu)),"1475 live map index");
 const U result=m.r32(m.r32(0x81a958u)+4u*U(index));need(result!=0,"1475 live map cell");return result;
}
//557070 copies the supplied XY, resolves the same table, then4702C0's actual
// warm flat branch executes FILD/FADD/FISTP, including precision status.
U height(Memory&m,FP&fp,U point){
 const U p=cell(m,point);
 need((m.r8(0x838f70u)&7u)==7u&&m.r8(p+0x11cu)==0u,"1475 warm flat height");
 fp.load_integer32(floating_b61::sx8(m.r8(p+0x11bu))*m.r32(0x838f80u));
 fp.add64(read64(m,0x785728u));return integer(m,fp);
}
// These two existing B39 entry points are call-free bodies. The span is the
// caller's private frame, disjoint from B456's5F200000 span. No private input
// from the outer caller is supplied. Unused frame bookkeeping is not a target
// input; every semantically consumed argument is stored by this callsite.
U b39(Memory&m,FP&fp,U rva,U cx,U sp,U continuation,U arg0,U arg1=0){
 m.w32(sp,continuation);m.w32(sp+4u,arg0);if(rva==0x219de0u)m.w32(sp+8u,arg1);
 floating_b39::State state{};state.cx=cx;state.fp=fp;
 floating_b39::Frame frame{};frame.entry_sp=frame.sp=frame.return_sp=sp;frame.outer_return=continuation;
 const auto&entries=floating_b39::entries_a();const auto at=std::find_if(entries.begin(),entries.end(),[&](const auto&e){return e.rva==rva;});
 need(at!=entries.end(),"1475 unchanged B39 entry");at->function(m,state,frame,{});fp=state.fp;return state.ax;
}
// Actual4346E0/25B copies three produced integers and RET12.
void coordinates(Memory&m,U out,U x,U y,U z){m.w32(out,x);m.w32(out+4u,y);m.w32(out+8u,z);}
}
std::uint32_t fun_00436f60(Memory&m,const Inputs&i){
 const U self=i.cx;auto&fp=i.fp;
 need(read64(m,self+8u)==0x3ff0000000000000ull&&read64(m,self+0x10u)==0u,"1475 gravity1/unlimited speed");
 need(m.r32(self+0x18u)==0x44a00000u&&m.r32(self+0x1cu)==0x44a00000u&&m.r32(self+0x24u)==0x3f800000u&&m.r32(self+0x28u)==0x40000000u&&m.r32(self+0x2cu)==0x40800000u,"1475 positive bounded point/velocity");
 need(m.r32(self+0x20u)>=0x44800000u&&m.r32(self+0x20u)<=0x4550c000u,"1475 high finite Z");
 for(U q:{self+0x30u,self+0x40u})need(m.r32(q)==0u&&m.r32(q+4u)==0u&&m.r32(q+8u)==0u&&m.r32(q+12u)==0x3f800000u,"1475 constructor identity quaternions");
 Memory local=m;std::array<std::uint8_t,2048>bytes{};leaf::Memory scratch(bytes.data(),0x7d300000u,bytes.size());local.add(scratch);
 constexpr U u=0x7d300500u; // Actual root U=S-140; only relative private addresses matter.
 local.w32(u+0x24u,self);local.w32(u+0x14u,0u); // Original[T+20], [T+10].
 fp.load64(read64(local,self+0x10u));write64(local,u+0x18u,fp.store64());
 for(U k=0;k<3u;++k)local.w32(u+0x30u+4u*k,local.r32(self+0x18u+4u*k));
 fp.load32(local.r32(self+0x2cu));fp.subtract64(read64(local,self+8u));
 for(U k=0;k<3u;++k)local.w32(u+0x3cu+4u*k,local.r32(self+0x24u+4u*k));
 write64(local,u+0x64u,read64(local,self));local.w32(self+0x2cu,fp.pop32());
 fp.compare_pop64(read64(local,0x786610u));need((fp.status()&0x4100u)!=0u,"1475 skip finite speed clamp");
 fp.load32(local.r32(self+0x20u));const U oz=integer(local,fp);
 fp.load32(local.r32(self+0x1cu));const U oy=integer(local,fp);
 fp.load32(local.r32(self+0x18u));const U ox=integer(local,fp);
 coordinates(local,u+0x54u,ox,oy,oz);
 (void)b39(local,fp,0x37560u,self+0x18u,u-8u,0x437025u,self+0x24u);
 fp.load32(local.r32(self+0x20u));const U nz=integer(local,fp);
 fp.load32(local.r32(self+0x1cu));const U ny=integer(local,fp);
 fp.load32(local.r32(self+0x18u));const U nx=integer(local,fp);
 coordinates(local,u+0x48u,nx,ny,nz);
 const U ground=height(local,fp,u+0x48u);local.w32(u+0x2cu,ground);local.w32(u+0x28u,ground+local.r32(0x836fb0u));
 const U current=cell(local,u+0x48u);local.w8(u+0x13u,0u);local.w8(u+0x12u,0u);
 need((local.r32(current+0x140u)&0x100u)==0u,"1475 current cell has no bridge");
 const U old=cell(local,u+0x54u);need((local.r32(old+0x140u)&0x100u)==0u,"1475 old cell has no bridge");
 local.w8(u+0x11u,0u);
 fp.load_integer32(ground);fp.compare32(local.r32(self+0x20u));need((fp.status()&0x4100u)!=0u,"1475 point above terrain");
 fp.load32(local.r32(self+0x20u));fp.subtract32(local.r32(0x787aa8u));fp.compare_pop_st1();const U terrain_status=fp.status();fp.pop_st0();
 need((terrain_status&0x100u)==0u,"1475 high terrain margin excludes actors");
 fp.load_integer32(ground);local.w32(u+0x18u,fp.pop32());fp.load32(local.r32(self+0x20u));fp.compare_pop32(local.r32(u+0x18u));
 need((fp.status()&0x100u)==0u&&local.r8(u+0x13u)==0u&&local.r8(u+0x12u)==0u&&local.r8(u+0x11u)==0u,"1475 noncollision branch");
 const U result_flag=local.r32(u+0x14u); // Produced entry zero, not stale/private padding.
 Inputs nested=i;nested.cx=u+0x70u;nested.dx=self+0x30u;nested.arg[0]=self+0x40u;nested.fp=fp;
 local.w32(u-4u,nested.arg[0]);const U product=floating_b61::fun_00619f90(local,nested);fp=nested.fp;local.w32(u-4u,nested.arg[0]);
 (void)b39(local,fp,0x219de0u,self+0x30u,u-12u,0x4374e2u,u+0x54u,product);
 nested.cx=self;nested.fp=fp;(void)recovery_b456::fun_00436e70(local,nested);fp=nested.fp;
 fp.compare_pop64(read64(local,0x787a78u));return (fp.status()&0x100u)?2u:result_flag;
}
}
