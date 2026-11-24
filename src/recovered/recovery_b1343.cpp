#include "recovered/recovery_b1343.hpp"
#include "recovered/floating_b61_b.hpp"
#include "recovered/leaf_b16_b.hpp"
#include "recovered/map_b79.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1343 {
namespace {
using U=std::uint32_t;namespace d=numeric_b88::detail;
void need(bool v,const char*why){if(!v)throw std::domain_error(why);}
// Nested70E7D0 only. Its original DWORD reads include unproduced high
// halves. This interface represents ONLY the produced low16 coordinate
// equivalence class. No standalone ABI or arbitrary high half is invented.
void render_four(Memory&m,const Inputs&i,U receiver,U record,U center){
 const U source=m.r32(receiver+20u)+164u*(m.r32(m.r32(receiver+16u)+12u*m.r32(record+4u))+m.r32(record+8u));
 const U width=m.r8(source+0xa0u),height=m.r8(source+0xa1u),cells=m.r32(source+4u);
 need(width==1u&&height==1u&&m.r32(record+0x3cu)==0u,"B1343 actual no-target one-cell four-corner provider");
 auto fixed_anchor=[&](U component){i.fp.load32(m.r32(record+0x24u+4u*component));i.fp.add32(m.r32(0x7998ccu));
  i.fp.subtract32(m.r32(center+4u*component));i.fp.multiply32(m.r32(0x7860acu));return std::uint16_t(d::integer(m,i.fp));};
 std::uint16_t x=fixed_anchor(0u),y=fixed_anchor(1u);
 i.fp.load_integer32(m.r32(record+0x40u));i.fp.add32(m.r32(center));m.w32(record+0x40u,d::integer(m,i.fp));
 i.fp.load_integer32(m.r32(record+0x44u));i.fp.add32(m.r32(center+4u));m.w32(record+0x44u,d::integer(m,i.fp));
 auto edge_register=[&](U point,U component){i.fp.load32(m.r32(record+point+4u*component));i.fp.subtract32(m.r32(record+0x24u+4u*component));
  d::reg<0xd8f1>(i.fp);i.fp.multiply32(m.r32(0x7860acu));return std::uint16_t(d::integer(m,i.fp));};
 auto edge_memory=[&](U point,U component,U divisor){i.fp.load32(m.r32(record+point+4u*component));i.fp.subtract32(m.r32(record+0x24u+4u*component));
  d::ext::divide32(i.fp,divisor);i.fp.multiply32(m.r32(0x7860acu));return std::uint16_t(d::integer(m,i.fp));};
 i.fp.load_integer32(width);const auto step_x=edge_register(0x18u,0u);
 i.fp.load_integer32(height);const U height_float=i.fp.pop32();
 const auto row_x=edge_memory(0x30u,0u,height_float),step_y=edge_register(0x18u,1u);i.fp.pop_st0();
 const auto row_y=edge_memory(0x30u,1u,height_float);
 U cell=0u;
 for(U row=0u;row<height;++row){const auto start_x=x,start_y=y;const U first_cell=cell;
  for(U column=0u;column<width;++column){
   if(m.r32(cells+4u*cell)!=0xffffffffu){const U offset=U(x>>8u)|(U(y)&0xff00u);m.w8(0xacae88u+offset,1u);m.w8(0xacae89u+offset,1u);}
   x=std::uint16_t(x+step_x);y=std::uint16_t(y+step_y);++cell;
  }
  x=std::uint16_t(start_x+row_x);y=std::uint16_t(start_y+row_y);cell=first_cell+width;
 }
 // Original finalEAX is decremented heightcounter0. Both overwritten
 // nested caller words are popped by RET8 and never read by70C4A0.
}
void bounds_four(Memory&m,const Inputs&i,U out,U midpoint){
 need(m.r32(0xacaa80u)==1u&&m.r32(0xac8730u)==0u&&m.r32(0xade090u)==0u,"B1343 genuine one four-corner queue and no eight-corner queue");
 for(U axis=0;axis<3u;++axis){i.fp.load32(m.r32(0xac84f0u+4u*axis));i.fp.add32(m.r32(0xac8858u+4u*axis));i.fp.multiply32(m.r32(0x788d80u));m.w32(midpoint+4u*axis,i.fp.pop32());}
 for(U k=0;k<m.r32(0xacaa80u);++k){const U record=0xadae88u+72u*k;render_four(m,i,m.r32(record),record,midpoint);}
 // Original70C4A0 has no pointer-list or sorting writes with AC8730=0.
 i.fp.load32(m.r32(0xac8858u));i.fp.subtract32(m.r32(0xac84f0u));const U dx=d::integer(m,i.fp);
 i.fp.load32(m.r32(0xac885cu));i.fp.subtract32(m.r32(0xac84f4u));const U dy=d::integer(m,i.fp);
 i.fp.load32(m.r32(midpoint));const U left=128u-d::half_toward_zero(dx)-4u,top=128u-d::half_toward_zero(dy)-4u,width=dx+8u,height=dy+8u;
 m.w32(0xacaa74u,top);m.w32(0xacaa70u,left);m.w32(0xacaa78u,width);m.w32(0xacaa7cu,height);
 const U x=d::integer(m,i.fp)-d::half_toward_zero(width);i.fp.load32(m.r32(midpoint+4u));const U y=d::integer(m,i.fp)-d::half_toward_zero(height);
 const U values[6]{x,y,left,top,width,height};for(U k=0;k<6u;++k)m.w32(out+4u*k,values[k]);
}
}
U fun_006c7d80(Memory&outer,const Inputs&i){
 const U actor=i.cx,out=i.arg[0],pair=i.arg[1],input=i.arg[2],index=i.arg[5];
 need((i.arg[7]&255u)!=0u&&i.arg[8]==0u&&i.arg[9]==0u&&i.arg[10]==0u&&index==0u,"B1343 finite positive bounds-only caller");
 need(i.fp.image.word(8)==0xffffu&&(i.fp.image.word(4)&0x3800u)==0u,"B1343 empty affine x87 entry");
 constexpr U base=0x7db00000u,T=base+0x8000u;std::array<std::uint8_t,0x10000> bytes{};leaf::Memory local(bytes.data(),base,U(bytes.size()));Memory m=outer;m.add(local);
 const U animation=m.r32(pair+4u),count=m.r32(animation+8u);need(count!=0u,"B1343 valid original animation DIV");
 const U remainder=0u%count,selected=m.r32(animation+12u)+48u*(remainder*m.r32(animation+4u)+index);
 for(U k=0;k<12u;++k)m.w32(T+0x28u+4u*k,m.r32(selected+4u*k));
 Inputs compose{};compose.cx=T+0xb8u;compose.dx=input;compose.arg[0]=T+0x28u;compose.fp=i.fp;
 floating_b61::fun_0058df80(m,compose);i.fp=compose.fp;
 for(U k=0;k<12u;++k)m.w32(T+0x88u+4u*k,m.r32(T+0xb8u+4u*k));
 leaf::Inputs identity{};identity.cx=T+0x58u;leaf::fun_0058ce60(local,identity);
 need(m.r32(actor)==0x78612cu&&m.r32(0x7861acu)==0x6b6910u&&m.r32(0x7861b0u)==0x41b600u,"B1343 actual actor80->84 type dispatch");
 const U type=m.r32(actor+0x5acu);need(m.r8(type+0xb46u)==0u,"B1343 actual type disables extra half-scale");
 Inputs reset{};map_b79::fun_0070bd90(m,reset);
 compose.cx=T+0xb8u;compose.dx=0x821db0u;compose.arg[0]=T+0x58u;compose.fp=i.fp;floating_b61::fun_0058df80(m,compose);i.fp=compose.fp;
 Inputs enqueue{};enqueue.cx=m.r32(pair);enqueue.dx=index;enqueue.arg[0]=0u;enqueue.arg[1]=T+0xb8u;enqueue.arg[2]=T+0x88u;enqueue.arg[3]=0x821da0u;
 enqueue.arg[4]=i.arg[8];enqueue.arg[5]=i.arg[9];enqueue.arg[6]=i.arg[10];enqueue.fp=i.fp;numeric_b88::fun_0070bf20(m,enqueue);i.fp=enqueue.fp;
 bounds_four(m,i,T+0x28u,T+0x120u);
 for(U k=0;k<6u;++k)m.w32(T+0x10u+4u*k,m.r32(T+0x28u+4u*k));
 // Original arg7 lowbyte selects6C7F17; final drawing calls are unreached.
 for(U k=0;k<6u;++k)m.w32(out+4u*k,m.r32(T+0x10u+4u*k));return out;
}
}
