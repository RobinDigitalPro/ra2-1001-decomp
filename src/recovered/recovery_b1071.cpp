#include "recovered/recovery_b1071.hpp"
#include <stdexcept>
namespace ra2::recovered::b1071 {
static void need(bool v){if(!v)throw std::domain_error("1071 outside positive bounded software surface contract");}
static unsigned construct(Memory&m,const Inputs&i,Heap&h,unsigned color){
 const auto p=i.cx,x=i.arg[0],y=i.arg[1],w=i.arg[2],height=i.arg[3];
 need(w>=4u&&w<=31u&&height>=4u&&height<=23u);const auto bytes=2u*w*height;
 m.w32(p,x);m.w32(p+4u,y);m.w32(p+8u,w);m.w32(p+12u,height);m.w32(p+0x28u,w);m.w32(p+0x2cu,height);m.w32(p+0x20u,bytes);
 const auto surface=h.allocate(32u);need(surface!=0u);h.w32(surface,0x785f8cu);h.w32(surface+4u,w);h.w32(surface+8u,height);h.w32(surface+12u,0u);h.w32(surface+0x10u,2u);
 const auto pixels=h.allocate(bytes);need(pixels!=0u);h.w32(surface+0x14u,pixels);h.w32(surface+0x18u,bytes);h.w8(surface+0x1cu,1u);h.w32(surface,0x785ef8u);m.w32(p+0x14u,surface);
 // The original virtual fill uses the real software-surface rectangle, pitch,
 // lock and unlock methods. On this full-rectangle route their net lock count
 // is unchanged and every logical16-bit pixel receives the constant color.
 for(unsigned k=0;k<bytes;++k)h.w8(pixels+k,color>>(8u*(k&1u)));
 i.arg[0]=0u;i.arg[1]=0u;
 m.w32(p+0x18u,pixels);m.w32(p+0x10u,0u);m.w32(p+0x24u,0x8000u);m.w32(p+0x1cu,pixels+bytes);return p;
}
unsigned fun_00410a60(Memory&m,const Inputs&i,Heap&h){return construct(m,i,h,0x7fu);}
unsigned fun_007614c0(Memory&m,const Inputs&i,Heap&h){return construct(m,i,h,0xffffu);}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&,unsigned r){switch(r){case 0x10a60u:return fun_00410a60(m,i,h);case 0x3614c0u:return fun_007614c0(m,i,h);default:throw std::domain_error("1071 root");}}
}
