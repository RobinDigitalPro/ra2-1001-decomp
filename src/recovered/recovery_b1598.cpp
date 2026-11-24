#include "recovered/recovery_b1598.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_00545490(Memory&,const Inputs&);}
namespace ra2::recovered::b1598 {namespace{void need(bool v){if(!v)throw std::domain_error("B1598 genuineAir fallback mapquery");}}
U fun_004198b0(Memory&m,const Inputs&i){
 const U self=i.cx;need(self);const U type=m.r32(self+0x5ac),candidates=m.r32(0xa27fbcu),air=m.r32(candidates),table=m.r32(0x81a958u);
 need(global_b26::s32(m.r32(type+0x3bc))<=0&&m.r32(0xa27fc8u)==1);
 need(m.r32(self)==0x78612c&&m.r32(air)==0x78612c&&m.r32(0x78612c+0x2c)==0x41b580&&m.r8(air+0x76)!=0);
 const U x=m.r32(self+0x88),y=m.r32(self+0x8c),z=m.r32(self+0x90);need((x==768||x==1024)&&y==768&&z<=1023);
 const U index=1536u+x/256u;need(m.r32(0x81a95cu)==1541u);const U cell=m.r32(table+4u*index);need(cell);
 constexpr U private_xyz=0x7d020000u;struct Span{U at,size;};const std::array<Span,10>spans{{{self,0x5b0},{type,0x3c0},{candidates,4},{air,0x5b0},{table,1541u*4u},{cell,0x200},{0x786000,4096},{0x81a000,4096},{0xa27000,4096},{private_xyz,4096}}};
 for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.at&&std::uint64_t(a.at)+a.size<=0x100000000ull);if(j<9){(void)m.r8(a.at);(void)m.r8(a.at+a.size-1);}for(U k=0;k<j;++k)need(std::uint64_t(a.at)+a.size<=spans[k].at||std::uint64_t(spans[k].at)+spans[k].size<=a.at);}
 // GenuineDC20 invokes originalAir+2C full2 and returns the candidate. Its
 // public76 cull leaves best=-1. The root then produces all three XYZ words.
 std::array<std::uint8_t,4096>scratch{};leaf::Memory span(scratch.data(),private_xyz,U(scratch.size()));Memory local=m;local.add(span);
 local.w32(private_xyz,x);local.w32(private_xyz+4,y);local.w32(private_xyz+8,z);
 global_b26::Inputs child=i;child.cx=0x81a820u;child.arg[0]=private_xyz;
 // Reuse the unchanged accepted original-byte-bound lookup implementation.
 const U result=global_b26::fun_00545490(local,child);need(result==cell&&child.arg[0]==private_xyz);return result;
}
}
