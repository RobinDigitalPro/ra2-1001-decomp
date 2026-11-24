#include "recovered/recovery_b1057.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::b1057{
static void need(bool v){if(!v)throw std::domain_error("1057 outside positive three-surface creation");}
unsigned fun_0075d890(Memory&m,const Inputs&i,Heap&h){const auto p=i.cx,shape=m.r32(p+4u),source=m.r32(p+0x24u);need(shape&&source&&m.r32(source)==0x785ef8u);const auto width=global_b26::sx16(m.r16(shape+2u)),height=global_b26::sx16(m.r16(shape+4u)),bpp=m.r32(source+0x10u);need(width>=1u&&width<=19u&&height>=1u&&height<=17u&&(bpp==1u||bpp==2u||bpp==4u));const auto bytes=width*height*bpp;
 for(unsigned off:{0x44u,0x58u,0x6cu}){need(m.r32(p+off)==0u);const auto header=h.allocate(32u);need(header!=0u);h.w32(header+0x10u,bpp);h.w32(header+4u,width);h.w32(header+8u,height);h.w32(header+12u,0u);h.w32(header,0x785f8cu);const auto pixels=h.allocate(bytes);need(pixels!=0u);h.w32(header+0x14u,pixels);h.w32(header+0x18u,bytes);h.w8(header+0x1cu,1u);h.w32(header,0x785ef8u);m.w32(p+off,header);}return 1u;
}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&,unsigned root){need(root==0x35d890u);return fun_0075d890(m,i,h);}
}
