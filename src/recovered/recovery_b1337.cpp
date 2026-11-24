#include "recovery_b1337.hpp"
#include <stdexcept>
namespace ra2::recovered::b1337 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
bool valid(Memory&m,U map,int x,int y){
 // Actual547F40 signed-coordinate predicate, including all four comparisons.
 const int w=global_b26::s32(m.r32(map+0xf0u)),h=global_b26::s32(m.r32(map+0xf4u));
 return x+y>w&&x-y<w&&y-x<w&&x+y<=w+2*h;
}
U lookup(Memory&m,U map,int x,int y){
 const int index=512*y+x;need(index>=0&&index<0x40000,"1337 actual545500 in-range lookup");
 const U cell=m.r32(m.r32(map+0x138u)+4u*U(index));need(cell!=0u,"1337 all nine actual cells populated");return cell;
}
U dirty_current(Memory&m,U cell){
 // Caller-specific reached prefix of6A0410. No queue behavior is synthesized.
 need(m.r32(0x81a82cu)==0u,"1337 actual manager initial mode0");const U epoch=m.r32(0xa2896cu);
 need(m.r32(cell+0x5cu)==epoch,"1337 actual already-current epoch guard");return epoch;
}
void clear_neighborhood(Memory&m,U map,int x,int y){
 need(valid(m,map,x,y),"1337 child actual predicate");const U center=lookup(m,map,x,y);const U flags=m.r32(center+0x12cu);
 need((flags&8u)!=0u,"1337 child positive center bit8");m.w32(center+0x12cu,flags&~0x18u);(void)dirty_current(m,center);
 for(U k=0;k<8u;++k){const U packed=m.r32(0x839da0u+4u*k);
  const int nx=std::int16_t(U(x)+U(global_b26::sx16(packed))),ny=std::int16_t(U(y)+U(global_b26::sx16(packed>>16u)));
  const U cell=lookup(m,map,nx,ny);if(nx!=x||ny!=y){m.w32(cell+0x12cu,m.r32(cell+0x12cu)&~0x10u);(void)dirty_current(m,cell);}
 }
 // Actual49CCA0's overwritten argument is private to this root call frame.
}
}
std::uint32_t fun_0049c9c0(Memory&m,const Inputs&i){
 const U map=i.cx;need(map==0x81a820u&&m.r32(map+0xf0u)==1u&&m.r32(map+0xf4u)==1u,"1337 one-cell valid diamond");
 need(m.r32(map+0xcu)==0u,"1337 initial mode0");
 for(int y=0;y<512;++y)for(int x=0;x<512;++x)if(valid(m,map,x,y)){
  const U cell=lookup(m,map,x,y),flags=m.r32(cell+0x12cu);
  if((flags&0x10u)==0u&&(flags&8u)!=0u)m.w32(cell+0x140u,m.r32(cell+0x140u)|0x20u);
 }
 for(int y=0;y<512;++y)for(int x=0;x<512;++x)if(valid(m,map,x,y)){
  U cell=lookup(m,map,x,y);if((m.r8(cell+0x140u)&0x20u)!=0u){cell=lookup(m,map,x,y);m.w32(cell+0x140u,m.r32(cell+0x140u)&~0x20u);clear_neighborhood(m,map,x,y);}
 }
 need(m.r32(0x83a8e8u)==0u,"1337 actual49DE40 zero-count dependency route");
 const U v=m.r32(map);need(v==0x785954u&&m.r32(v+0x38u)==0x4e0030u,"1337 constructor-proven actual Map callback");
 const U manager=m.r32(0x821cacu);need(manager!=0u,"1337 valid borrowed manager");m.w8(manager+0xd7du,1u);
 if(m.r32(map+0xcu)!=2u)m.w32(map+0xcu,1u);m.w8(0x81a820u+0x1154u,m.r8(0x81a820u+0x1154u)+1u);
 return 1u; // Actual4E0030 EAX1;557AB0 INC leaves it unchanged.
}
}
