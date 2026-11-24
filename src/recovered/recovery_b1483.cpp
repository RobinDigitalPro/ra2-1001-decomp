#include "recovered/recovery_b1483.hpp"
#include "recovered/leaf_b21_a.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1483 {
namespace {using U=std::uint32_t;void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
U wide_length(Memory&m,U p){U n=0;while(m.r16(p+2*n)){need(n<161,"1483 bounded original UTF16 input");++n;}return n;}
void construct_node(Heap&h,U owner,U text,U x,U y,U color,U flags){
 // Existing leaf Memory is a bounded byte view. Transfer every real owner byte
 // through Heap; the compatible public constructor preserves seeded padding.
 std::array<std::uint8_t,80>bytes{};for(U k=0;k<80;++k)bytes[k]=std::uint8_t(h.r8(owner+k));
 leaf::Memory view(bytes.data(),owner,80);leaf::Inputs call{};call.cx=owner;call.arg={{x,y,1,1,0,0,0,0}};
 need(leaf::fun_004cebc0(view,call)==owner,"1483 actual base constructor result");
 view.w32(owner+0x30,text);view.w32(owner+0x24,0);view.w32(owner+0x28,0);view.w32(owner+0x2c,flags);view.w32(owner+0x34,color);view.w32(owner+0x38,0xffffffff);view.w32(owner+0x3c,0);view.w8(owner+0x40,0);view.w8(owner+0x41,0);view.w32(owner+0x44,0);view.w32(owner+0x48,0);view.w32(owner,0x798b74);
 for(U k=0;k<80;++k)h.w8(owner+k,bytes[k]);
}
}
U configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1483 actual CRT setter argument");m.w32(0x817554,0);return 1;}
U fun_005b1fa0(Memory&m,const Inputs&i,Heap&h){
 const U self=i.cx;need(m.r32(0x817554)==0,"1483 produced ordinary CRT configuration");
 need(!m.r32(self)&&!m.r8(self+0x19)&&!m.r8(self+0x1a)&&!m.r32(self+0x24)&&!m.r32(0x84e328),"1483 inactive manager and no priorfocus");
 need(i.arg[2]&&i.arg[1]==0x4046&&(i.arg[3]&255)==0&&i.arg[4]==0xffffffff&&m.r32(self+0x2c4)==312,"1483 selected supplied text/flags/width route");
 need(m.r32(0x798bc4)==0x4cf1c0,"1483 genuine installed firstfocus slot");
 const U length=wide_length(m,i.arg[2]);need(length==5,"1483 finite positive five-unit text");
 m.w16(self+0x2b8,leaf::sx8(i.arg[3]));for(U k=0;k<324;k+=4)m.w32(self+0x28+k,0);
 for(U k=0;k<=length;++k)m.w16(self+0x28+2*k,m.r16(i.arg[2]+2*k));
 m.w16(self+0x16c,0);m.w32(self+0x2b4,length);m.w32(self+0x2b0,length);
 const U owner=h.allocate(76);need(owner,"1483 positive actual owner allocation");
 construct_node(h,owner,self+0x28,m.r32(self+0x1c),m.r32(self+0x20),i.arg[0],i.arg[1]|0x8000);
 m.w32(self+0x24,owner);h.w32(owner+0x38,m.r32(self+0x2c4));m.w8(self+0x19,1);
 // Exact 4CF1C0 branch for original NULL previousfocus; no substitute callback.
 h.w32(owner+0x20,h.r32(owner+0x20)|0x100);m.w32(0x84e328,owner);
 return m.r32(self+0x24);
}
}
