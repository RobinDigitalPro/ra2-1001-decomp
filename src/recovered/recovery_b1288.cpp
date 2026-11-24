#include "recovery_b1288.hpp"
#include "recovered/numeric_b71.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1288 {
std::uint32_t fun_00470ec0(Memory& m,const Inputs& i){
 const auto cell=i.cx,out0=i.arg[0],out1=i.arg[1];
 auto need=[](bool q,const char*s){if(!q)throw std::domain_error(s);};
 auto disjoint=[](std::uint32_t a,std::uint32_t an,std::uint32_t b,std::uint32_t bn){
  const auto ae=std::uint64_t(a)+an,be=std::uint64_t(b)+bn;
  return ae<=b||be<=a;
 };
 need(out0&&out1&&std::uint64_t(out0)+3u<=0x100000000ull&&std::uint64_t(out1)+3u<=0x100000000ull&&disjoint(out0,3u,out1,3u),"1288 distinct 3-byte outputs");
 // Original 0x471360 returns zero: object-search gate is enabled, Cell+E4 is null.
 need(m.r8(0xa285a8u)!=0u&&m.r32(cell+0xe4u)==0u,"1288 empty Cell object search");
 need((m.r32(cell+0x140u)&0x100u)==0u,"1288 ordinary tile color");
 const auto tile=m.r32(cell+0x38u);need(tile<4u,"1288 finite ordinary tile index");
 const auto table=m.r32(0xa28914u);need(table!=0u,"1288 tile Type table");
 const auto type=m.r32(table+tile*4u);
 need(type!=0u&&m.r32(type+0x2c0u)==1u&&m.r32(type+0xa4u)!=0u,"1288 singleton loaded tile cache");
 // This exact sentinel branch bypasses the [0xa1e11c] lookup, helper 0x5d5680,
 // BL+0x279 test, and indirect call through the resulting object's vtable+0x9c.
 need(m.r32(cell+0x44u)==0xffffffffu,"1288 direct cached-variant route");
 const auto descriptor=m.r32(type+0xa4u);
 const auto subtile=m.r8(cell+0x11au);need(subtile<8u,"1288 finite subtile");
 const auto color=m.r32(descriptor+0x10u+4u*subtile);
 need(color!=0u,"1288 populated cached RGB triple");
 need(disjoint(out0,3u,cell,0x11bu)&&disjoint(out1,3u,cell,0x11bu)&&
      disjoint(out0,3u,type,0x2c4u)&&disjoint(out1,3u,type,0x2c4u)&&
      disjoint(out0,3u,descriptor+0x10u+4u*subtile,4u)&&disjoint(out1,3u,descriptor+0x10u+4u*subtile,4u)&&
      disjoint(out0,3u,color+0x2bu,3u)&&disjoint(out1,3u,color+0x2bu,3u)&&
      disjoint(out0,3u,0x785738u,4u)&&disjoint(out1,3u,0x785738u,4u)&&
      disjoint(out0,3u,0x7860a8u,4u)&&disjoint(out1,3u,0x7860a8u,4u)&&
      disjoint(out0,3u,0x7c3a04u,4u)&&disjoint(out1,3u,0x7c3a04u,4u),"1288 disjoint borrowed read sets");
 const auto scene=m.r32(0xa255c0u);need(scene!=0u,"1288 borrowed palette scene");
 need(m.r32(scene+0x838u)==0u,"1288 original palette row zero");
 const auto scale=m.r32(0x785bb8u);need(scale==0x3f800000u,"1288 original row-zero scale is 1.0");
 // Original 0x6341e0 scales three cached bytes through x87. Use the second
 // output as its temporary destination; the original stack temporary is
 // unobservable, and this buffer is overwritten with the final output below.
 Inputs convert=i;convert.cx=out1;convert.arg[0]=color+0x2bu;convert.arg[1]=scale;
 (void)numeric_b71::fun_006341e0(m,convert);i.fp=convert.fp;
 const auto r=std::uint8_t(m.r8(out1)>>1u),g=std::uint8_t(m.r8(out1+1u)>>1u),b=std::uint8_t(m.r8(out1+2u)>>1u);
 for(unsigned k=0;k<2u;++k){const auto dst=k?out1:out0;m.w8(dst,r);m.w8(dst+1u,g);m.w8(dst+2u,b);}
 //471200/471208 write the low two bytes of the first caller word.
 i.arg[0]=(out0&0xffff0000u)|unsigned(r)|(unsigned(g)<<8u);
 // The last original EAX load is the second output pointer at 0x471204.
 return out1;
}
}
