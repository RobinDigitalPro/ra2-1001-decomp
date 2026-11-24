#include "recovered/recovery_b1447.hpp"
#include <stdexcept>
namespace ra2::recovered::b1447 {
namespace {using U=std::uint32_t;void need(bool v,const char*s){if(!v)throw std::domain_error(s);}}
std::uint32_t configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1447 actual CRTsetter argument");m.w32(0x817554,0);return 1;}
std::uint32_t fun_0042e340(Memory&m,const Inputs&i,Heap&h){
 const U self=i.cx,index=i.arg[0];need(self==0x836c18&&index<8&&i.arg[4]==0xffffffffu,"1447 actualowner/group/firstempty entry");
 need(m.r32(self+0x60)==0&&m.r32(0xa255c8)==0&&m.r32(0x817554)==0,"1447 freshowner andproduced ordinaryCRT config");
 for(U k=0;k<24;++k)need(m.r32(self+4*k)==0,"1447 exact24NULL constructor-compatible slots");
 need(m.r32(0x836c98)==0&&m.r32(0x836c9c)==0&&m.r32(0x836ca0)==0,"1447 originaldefaultXYZ");
 need(i.arg[1]>=384&&i.arg[1]<=8064&&(i.arg[1]&255)==128&&i.arg[2]>=384&&i.arg[2]<=8064&&(i.arg[2]&255)==128&&i.arg[3]==0,"1447 declaredcaller cellcenterXYZ");
 const U group=self+12*index;U slot=0;while(slot<3&&m.r32(group+4*slot))++slot;need(slot<3,"1447 actualfree slot");
 const U owner=h.allocate(0x114);need(owner!=0,"1447 genuinepositive allocation");
 h.w32(owner,m.r32(0x836c98));h.w32(owner+4,m.r32(0x836c9c));h.w32(owner+8,m.r32(0x836ca0));h.w8(owner+0xc,h.r8(owner+0xc)&0xfcu);
 for(U k=0;k<64;++k)h.w32(owner + 0xe + 4*k,0); // Actual unaligned REP STOSD, exactly256bytes.
 slot=0;while(slot<3&&m.r32(group+4*slot))++slot;need(slot<3,"1447 free slot unchanged acrossactual allocation");i.arg[4]=slot;m.w32(group+4*slot,owner);
 if(i.arg[1]!=m.r32(0x836c98)||i.arg[2]!=m.r32(0x836c9c)||i.arg[3]!=m.r32(0x836ca0)){h.w32(owner,i.arg[1]);h.w32(owner+4,i.arg[2]);h.w32(owner+8,i.arg[3]);}
 h.w32(owner+0x110,index);h.w8(owner+0xc,h.r8(owner+0xc)|1u);m.w32(self+0x60,m.r32(self+0x60)+1);return m.r32(0xa255c8);
}
}
