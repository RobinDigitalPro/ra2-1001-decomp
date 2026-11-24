#pragma once
// Independent whole-storage oracle, literal prepared frame headers and clamp.
#include <algorithm>
#include <stdexcept>
namespace ra2::platform::frame_setter1092 {
namespace b=b1092_test;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
struct World {
 unsigned root,base;b::Case c;static constexpr unsigned arena_size=65536u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){}
 unsigned receiver()const{return base+0x1000u;}
 unsigned shp()const{return base+0x2000u;}
 unsigned requested()const{switch(c.mode){case 0:return 1u;case 1:return c.count;case 2:return 0xffffffffu;default:return 0x80000000u;}}
 unsigned stored()const{return c.mode?c.count-1u:1u;}
 unsigned result()const{return c.mode?c.count-1u:c.count;}
 unsigned payload_offset(unsigned frame)const{return((8u+24u*c.count+15u)&~15u)+128u*frame;}
 unsigned frame_width(unsigned frame)const{return c.mode&&frame==0u?0u:c.width;}
 unsigned frame_height(unsigned frame)const{return c.mode&&frame==0u?0u:c.height;}
 std::array<unsigned,4>rect()const{
  const auto x=static_cast<long long>(ra2::recovered::global_b26::s32(c.x))+(c.mode?0:c.frame_x)-(c.center?c.canvas_w/2u:0u);
  const auto y=static_cast<long long>(ra2::recovered::global_b26::s32(c.y))+(c.mode?0:c.frame_y)-(c.center?c.canvas_h/2u:0u);
  return{static_cast<unsigned>(x),static_cast<unsigned>(y),c.mode?0u:c.width,c.mode?0u:c.height};
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=receiver();i.dx=b::mix(c.seed+2u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);i.arg[0]=requested();return i;}
 void setup(b::Memory&m,unsigned char*a)const{
  need(root==0x1a9340u&&c.count>=3u&&c.count<=7u&&requested()!=0u&&stored()!=0u,"1092 useful distinct finalframe everycase");
  need(m.r32(0x791d50u)==0x5a98e0u,"1092 authenticctor-installedvptrslot");for(unsigned k=0;k<16u;++k)need(m.r8(0xa59420u+k)==0u,"1092 genuine allzero fallback retained");
  for(unsigned k=0;k<arena_size;++k)a[k]=static_cast<unsigned char>(b::mix(c.seed+131u*k));
  // Original-observed file prefix8 and headerstride24. Later header/payload
  // fields are opaque to the selected getter; no asset-decoding claim.
  m.w16(shp(),0u);m.w16(shp()+2u,c.canvas_w);m.w16(shp()+4u,c.canvas_h);m.w16(shp()+6u,c.count);
  for(unsigned j=0;j<c.count;++j){const auto p=shp()+8u+24u*j;for(unsigned k=0;k<24u;++k)m.w8(p+k,0u);const bool empty=c.mode&&j==0u;m.w16(p,empty?0u:c.frame_x);m.w16(p+2u,empty?0u:c.frame_y);m.w16(p+4u,frame_width(j));m.w16(p+6u,frame_height(j));m.w32(p+20u,empty?0u:payload_offset(j));for(unsigned k=0;k<frame_width(j)*frame_height(j);++k)m.w8(shp()+payload_offset(j)+k,1u+(c.seed+17u*j+13u*k)%255u);}
  // Root-read constructor projection: exact vptr/coordinates/borrowedSHP/
  // initialframe0/unsignedflags; unrelated timer fields are not claimed.
  m.w32(receiver(),0x791d38u);m.w32(receiver()+4u,c.x);m.w32(receiver()+8u,c.y);m.w8(receiver()+12u,1u);m.w32(receiver()+0x18u,0u);m.w32(receiver()+0x1cu,shp());m.w32(receiver()+0x28u,0u);m.w32(receiver()+0x2cu,0u);m.w32(receiver()+0x30u,c.count-1u);m.w32(receiver()+0x38u,(b::mix(c.seed)&~0x200u)|(c.center?0x200u:0u));m.w8(receiver()+0x3cu,0u);
  if(!c.mode)need(m.r8(shp()+payload_offset(0u))!=m.r8(shp()+payload_offset(1u)),"1092 distinct positiveframepayloads despite equalbounds");
 }
};
struct Observation{std::vector<unsigned char>image,arena;unsigned scalar;};
inline Observation verify(const World&w,unsigned eax,const ra2::platform::x87::Image&numeric,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){
 Observation o;o.image=bi;o.arena=ba;b::word(o.arena,w.receiver()-w.base+0x28u,w.stored());o.scalar=w.result();
 need(eax==o.scalar,"1092 fullEAXcountorcountminus1");need(std::equal(o.image.begin(),o.image.end(),image)&&std::equal(o.arena.begin(),o.arena.end(),arena),"1092 entireimage/arena onlyframeindexwrite;allSHPheaders/payload/padding unchanged");
 need(ra2::platform::x87::same_numeric(numeric,ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(w.c.control))),"1092 full numericx87 unchanged");return o;
}
inline void compare(const Observation&a,const Observation&d){need(a.image==d.image&&a.arena==d.arena&&a.scalar==d.scalar,"1092 paired everybyte/fullrawEAX");}
}
