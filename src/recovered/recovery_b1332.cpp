#include "recovery_b1332.hpp"
#include "recovered/codec_b78.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::b1332 {
namespace {
using U=std::uint32_t;namespace d=ra2::recovered::numeric_b88::detail;
void need(bool okay,const char* why){if(!okay)throw std::domain_error(why);}
void mode(Memory&m){need(m.r32(0xade090u)==0u&&m.r32(0xade094u)==0u,
 "B1332 original non-depth raster mode");}
void queued(Memory&m){mode(m);need(m.r32(0xac8730u)==1u&&m.r32(0xacaa80u)==0u,
 "B1332 one genuine eight-corner request and no four-corner requests");}
std::array<U,3> center(Memory&m,const Inputs&i){
 std::array<U,3> out{};
 for(U k=0;k<3u;++k){i.fp.load32(m.r32(0xac84f0u+4u*k));
  i.fp.add32(m.r32(0xac8858u+4u*k));i.fp.multiply32(m.r32(0x788d80u));out[k]=i.fp.pop32();}
 return out;
}
void consume(Memory&m,const Inputs&i,const std::array<U,3>& midpoint,U list){
 queued(m);
 // The original count-1 test is zero. No comparison/sort FP instructions
 // execute for this explicitly bounded one-record contract.
 const U count=m.r32(0xac8730u);
 for(U k=0;k<count;++k)m.w32(list+4u*k,0xac8868u+136u*k);
 std::array<std::uint8_t,12> storage{};constexpr U local=0x7d810000u;
 leaf::Memory span(storage.data(),local,U(storage.size()));auto mm=m;mm.add(span);
 for(U k=0;k<3u;++k)mm.w32(local+4u*k,midpoint[k]);
 for(U k=0;k<m.r32(0xac8730u);++k){const U record=m.r32(list+4u*k);
  Inputs q{};q.cx=m.r32(record);q.arg[0]=record;q.arg[1]=local;q.fp=i.fp;
  (void)fun_0070e500(mm,q);i.fp=q.fp;
  // The provider's two overwritten arguments are private nested call slots.
 }
}
U extent(Memory&m,const Inputs&i,U axis){i.fp.load32(m.r32(0xac8858u+4u*axis));
 i.fp.subtract32(m.r32(0xac84f0u+4u*axis));return d::integer(m,i.fp);}
}

U fun_0070e500(Memory&m,const Inputs&i){
 mode(m);const U request=i.arg[0],midpoint=i.arg[1];
 need(request==0xac8868u&&m.r32(request)==i.cx&&m.r32(request+4u)==0u&&
  m.r32(request+8u)==0u&&m.r32(request+12u)==0u,"B1332 original record zero/minimum corner zero");
 const U offsets=m.r32(i.cx+0x10u),records=m.r32(i.cx+0x14u);
 const U source=records+164u*(m.r32(offsets+12u*m.r32(request+4u))+m.r32(request+8u));
 const U dimensions[3]{m.r8(source+0xa0u),m.r8(source+0xa1u),m.r8(source+0xa2u)};
 need(dimensions[0]==1u&&dimensions[1]==1u&&dimensions[2]==1u&&m.r8(source+0xa3u)!=0u,
  "B1332 finite real one-pixel resource");
 const U table=0x7e36c8u+36u*m.r32(request+12u);
 const auto corner=[&](U at){return request+0x28u+12u*m.r32(table+at);};
 const U anchor=corner(4u),width=corner(8u),height=corner(12u),depth=corner(16u);
 // Original stable T=S-54h. T+58/T+5C are callerarg0/arg1.
 i.arg[0]=height;
 std::array<std::uint8_t,0x34> bytes{};constexpr U descriptor=0x7d800000u;
 leaf::Memory local(bytes.data(),descriptor,U(bytes.size()));auto mm=m;mm.add(local);
 for(U k=0;k<3u;++k)mm.w32(descriptor+4u*k,m.r32(source+4u*k));
 mm.w32(descriptor+12u,m.r32(table+24u)*(dimensions[1]-1u)*dimensions[0]+
  m.r32(table+20u)*(dimensions[0]-1u));
 mm.w32(descriptor+16u,m.r32(table+28u));
 mm.w32(descriptor+20u,m.r32(table+32u)*dimensions[0]);
 for(U k=0;k<3u;++k){i.fp.load32(m.r32(anchor+4u*k));i.fp.add32(m.r32(0x7998ccu));
  i.fp.subtract32(m.r32(midpoint+4u*k));i.fp.multiply32(m.r32(0x7860acu));
  mm.w16(descriptor+24u+2u*k,d::integer(m,i.fp));}
 auto edge_register=[&](U point,U component,U offset){
  i.fp.load32(m.r32(point+4u*component));i.fp.subtract32(m.r32(anchor+4u*component));
  d::reg<0xd8f1>(i.fp); // FDIV ST0,ST1: persistent integer width below ST0.
  i.fp.multiply32(m.r32(0x7860acu));mm.w16(descriptor+offset,d::integer(m,i.fp));
 };
 auto edge_memory=[&](U point,U component,U divisor,U offset){
  i.fp.load32(m.r32(point+4u*component));i.fp.subtract32(m.r32(anchor+4u*component));
  d::ext::divide32(i.fp,divisor);i.fp.multiply32(m.r32(0x7860acu));
  mm.w16(descriptor+offset,d::integer(m,i.fp));
 };
 i.fp.load_integer32(dimensions[0]);edge_register(width,0u,0x1eu);
 i.fp.load_integer32(dimensions[1]);const U height_float=i.fp.pop32();i.arg[1]=height_float;
 edge_memory(height,0u,height_float,0x24u);
 i.fp.load_integer32(dimensions[2]);const U depth_float=i.fp.pop32();
 edge_memory(depth,0u,depth_float,0x2au);
 edge_register(width,1u,0x20u);edge_memory(height,1u,height_float,0x26u);
 edge_memory(depth,1u,depth_float,0x2cu);i.fp.pop_st0();
 // ADE090==0 skips the three Z-step stores. The actual selected kernel
 // never reads descriptor22/28/2E/33; no value is invented for those bytes.
 for(U k=0;k<3u;++k)mm.w8(descriptor+0x30u+k,dimensions[k]);
 const U flags=m.r32(table);
 need(flags==0u&&m.r32(0x7e3648u+4u*flags)==0x784300u,"B1332 actual kernel table slot0");
 global_b26::Inputs q{};q.arg[0]=descriptor;
 return codec_b78::fun_00784300(mm,q);
}

U fun_0070c4a0(Memory&m,const Inputs&i){
 queued(m);const U out=i.cx;const auto midpoint=center(m,i);consume(m,i,midpoint,0xac8734u);
 const U dx=extent(m,i,0u),dy=extent(m,i,1u);
 i.fp.load32(midpoint[0]);
 const U left=128u-d::half_toward_zero(dx)-4u,top=128u-d::half_toward_zero(dy)-4u;
 const U width=dx+8u,height=dy+8u;
 m.w32(0xacaa74u,top);m.w32(0xacaa70u,left);m.w32(0xacaa78u,width);m.w32(0xacaa7cu,height);
 const U x=d::integer(m,i.fp)-d::half_toward_zero(width);
 i.fp.load32(midpoint[1]);const U y=d::integer(m,i.fp)-d::half_toward_zero(height);
 const U result[6]{x,y,left,top,width,height};for(U k=0;k<6u;++k)m.w32(out+4u*k,result[k]);
 return out;
}

U fun_0070c280(Memory&m,const Inputs&i){
 queued(m);const U rectangle=i.cx,outx=i.dx,outy=i.arg[0];const auto midpoint=center(m,i);
 consume(m,i,midpoint,0xacad88u);
 m.w32(rectangle+8u,extent(m,i,0u));m.w32(rectangle+12u,extent(m,i,1u));
 const U dx=m.r32(rectangle+8u),dy=m.r32(rectangle+12u);i.fp.load32(midpoint[0]);
 m.w32(rectangle,128u-d::half_toward_zero(dx));m.w32(rectangle+12u,dy+8u);
 m.w32(rectangle+4u,128u-d::half_toward_zero(dy));m.w32(rectangle+8u,dx+8u);
 m.w32(rectangle,m.r32(rectangle)-4u);m.w32(rectangle+4u,m.r32(rectangle+4u)-4u);
 for(U k=0;k<4u;++k)m.w32(0xacaa70u+4u*k,m.r32(rectangle+4u*k));
 m.w32(outx,d::integer(m,i.fp)-d::half_toward_zero(m.r32(rectangle+8u)));
 i.fp.load32(midpoint[1]);const U y=d::integer(m,i.fp)-d::half_toward_zero(m.r32(rectangle+12u));
 m.w32(outy,y);return y;
}
}
