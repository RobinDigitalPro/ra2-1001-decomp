#include "recovered/recovery_b460.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 { std::uint32_t fun_00545500(Memory&,const Inputs&); }
namespace ra2::recovered::map_footprint_b460 {
namespace { using U=std::uint32_t; void need(bool v,const char*m){if(!v)throw std::domain_error(m);} }
U fun_005851f0(Memory&m,const Inputs&i){
 const U idx=i.cx, objects=m.r32(0x00a28914u), type=m.r32(objects+idx*4u), vptr=m.r32(type);
 need(vptr==0x797f28u && m.r32(vptr+0x9cu)==0x41c300u,"authentic TechnoTypeClass +9c callback slot");
 
 need(m.r32(0x00a5863cu)==0,"460 excludes secondary-array writes");
 const U tile=m.r32(type+0xa4u);
 need(tile!=0,"caller-owned tiledata from original +9c getter");
 const U h=m.r32(type+0x2b8u),w=m.r32(type+0x2b4u);
 need(h==1u&&w==1u,"finite positive 1x1 footprint");
 U yloop=0, xloop=0;
 const U coord=i.dx;
 const auto map_width=m.r32(0x00a58634u), map_limit=m.r32(0x00a58638u);
 const U mapmgr=0x0081a820u;
 for(;yloop<h;++yloop){
  for(;xloop<w;++xloop){
   const U x=std::uint16_t(m.r16(coord))+xloop;
   const U y=std::uint16_t(m.r16(coord+2u))+yloop;
   const U sum=x+y, y_minus_x=y-x, x_minus_y=x-y;
   if(std::int32_t(sum)<=std::int32_t(map_width)||std::int32_t(y_minus_x)>=std::int32_t(map_width)||
      std::int32_t(x_minus_y)>=std::int32_t(map_width)||std::int32_t(sum)>std::int32_t(map_limit)) continue;
   const U local=coord;
   ra2::recovered::global_b26::Inputs hi=i;hi.cx=mapmgr;hi.arg[0]=local;
   const U cell=ra2::recovered::global_b26::fun_00545500(m,hi);
   const U tile_index=yloop*w+xloop, entry=m.r32(tile+0x10u+tile_index*4u);
   if(!entry)continue;
   m.w8(cell+0x11au,xloop);
   m.w32(cell+0x38u,m.r32(type+0x264u));
   if(i.arg[1]!=0xffffffffu)m.w8(cell+0x11bu,m.r8(entry+0x28u)+i.arg[1]-4u);
   m.w8(cell+0x11cu,m.r8(entry+0x2au));
   if(m.r32(0x00a5863cu)){
    const U secondary=m.r32(0x00a5863cu),factor=m.r32(0x00836b4cu);
    const U off=((U(std::int16_t(y))*factor)+U(std::int16_t(x)))*80u;
    m.w32(secondary+off+0x38u,i.arg[0]);
   }
  }
  xloop=0;
 }
 return 1u;
}
}




