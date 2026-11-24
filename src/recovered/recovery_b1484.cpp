#include "recovered/recovery_b1484.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "platform/observed_ticks152.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1484 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;void need(bool x,const char*s){if(!x)throw std::domain_error(s);}}
U configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1484 explicit CRT setter0");m.w32(0x817554,0);return 1;}
U produce_node(Memory&m,const Inputs&i,Heap&h,U deadline){
 const U self=i.cx;need(m.r32(0x817554)==0&&!m.r32(self)&&m.r16(self+0x1480)==1&&deadline&&i.arg[0]<8,"1484 genuine fresh manager/setup deadline");
 const U owner=h.allocate(76);need(owner!=0,"1484 genuine successful setup owner");
 std::array<std::uint8_t,80>b{};for(U k=0;k<80;++k)b[k]=std::uint8_t(h.r8(owner+k));
 leaf::Memory v(b.data(),owner,80);leaf::Inputs c{};c.cx=owner;c.arg={{0,0,1,1,0,0,0,0}};need(leaf::fun_004cebc0(v,c)==owner,"1484 compatible actual base constructor");
 v.w32(owner,0x798b74);v.w32(owner+0x24,deadline);v.w32(owner+0x28,i.arg[0]);v.w32(owner+0x2c,0xc046);v.w32(owner+0x30,self+0x2c8);v.w32(owner+0x34,0);v.w32(owner+0x38,312);v.w32(owner+0x3c,0);v.w8(owner+0x40,0);v.w8(owner+0x41,0);v.w32(owner+0x44,0);v.w32(owner+0x48,0);
 for(U k=0;k<80;++k)h.w8(owner+k,b[k]);m.w16(self+0x1480,0);m.w32(self,owner);return owner;
}
U fun_005b21a0(Memory&m,const Inputs&i,Heap&h){
 const U self=i.cx,owner=m.r32(self);need(owner&&h.r32(owner)==0x798b74&&!h.r32(owner+4)&&!h.r32(owner+8),"1484 single actual ordinary message node");
 need(!m.r8(self+0x19)&&!m.r8(self+0x1a)&&!m.r32(self+0x24)&&!m.r32(0x84e320)&&!m.r32(0x84e324)&&!m.r32(0x84e328),"1484 nonfocused noninput ordinary message");
 need(m.r32(0x821cc0)!=0xffffffff&&!m.r32(0x821cc8)&&h.r32(owner+0x24)&&h.r32(owner+0x30)==self+0x2c8,"1484 actual running timer and produced slot");
 need(m.r32(0x785524)==U(reinterpret_cast<std::uintptr_t>(&platform::ticks152::Tick::get)),"1484 genuine observed WinMM binding");
 need(m.r32(0x798b78)==0x4ced70&&m.r32(0x798b98)==0x4ced50&&m.r32(0x798b74)==0x6e6aa0&&m.r32(0x798bc8)==0x4cf1f0&&m.r32(0x798b8c)==0x537220&&m.r32(0x798b90)==0x537250&&m.r32(0x78c8cc)==0x537220&&m.r32(0x78c8d0)==0x537250,"1484 authentic installed method tables");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  const U raw=platform::ticks152::Tick::get(),elapsed=(raw>>4)-m.r32(0x821cc0)+m.r32(0x821cc8);
  need(leaf::s32(elapsed)>leaf::s32(h.r32(owner+0x24)),"1484 independently observed actual expiration");
  // Actual +4 getter returns0; +24 detach invokes real +54 then both end
  // getters. On this concrete singleton both end getters return self.
  h.w32(owner+8,0);h.w32(owner+4,0);m.w32(self,0);
  for(U k=0;k<14;++k)if(h.r32(owner+0x30)==self+0x2c8+324*k)m.w16(self+0x1480+2*k,1);
  // Actual scalar deleting destructor: base and link vptrs, real free flag1.
  h.w32(owner,0x78c82c);h.w32(owner,0x78c8b4);h.w32(owner+8,0);h.w32(owner+4,0);
  (void)h.release(owner);i.fp.image=fp::capture_host();fp::restore_host(host);return 1;
 }catch(...){fp::restore_host(host);throw;}
}
}
