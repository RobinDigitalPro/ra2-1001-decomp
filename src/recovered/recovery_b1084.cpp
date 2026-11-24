#include "recovered/recovery_b1084.hpp"
#include "recovered/leaf_b21_b.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1084{
static void need(bool v){if(!v)throw std::domain_error("1084 positive bounded onebyte RLE surface to owned pool");}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&,unsigned root){need(root==0x28f870u||root==0x28f9a0u);const auto owner=i.cx,surface=i.arg[0],record=i.arg[1],rect=record+(root==0x28f870u?8u:0u),width=m.r32(rect+8u),height=m.r32(rect+12u),sx=m.r32(rect),sy=m.r32(rect+4u);need(width>=8u&&width<=31u&&height>=8u&&height<=11u&&sx+width<=256u&&sy+height<=256u);need(m.r32(surface)==0x785ef8u&&m.r32(surface+4u)==256u&&m.r32(surface+8u)==256u&&m.r32(surface+16u)==1u&&m.r32(surface+12u)==0u);need(m.r32(0x785f54u)==0x411370u&&m.r32(0x785f58u)==0x4112f0u&&m.r32(0x785f6cu)==0x4113c0u);const auto capacity=m.r32(owner),base=m.r32(owner+4u),start=m.r32(owner+8u);need(capacity>=512u&&capacity<=768u&&start==base);auto cursor=start+12u;need(cursor<=base+capacity);m.w32(owner+8u,cursor);const auto dx=root==0x28f870u?m.r32(record):i.arg[2],dy=root==0x28f870u?m.r32(record+4u):i.arg[3];auto word=[&](unsigned p,unsigned v){h.w8(p,v);h.w8(p+1u,v>>8u);};word(start,dx);word(start+2u,dy);word(start+4u,width);word(start+6u,height);h.w32(start+8u,cursor);const auto pitch=m.r32(surface+4u)*m.r32(surface+16u);auto pixels=m.r32(surface+20u)+sy*pitch+sx;m.w32(surface+12u,1u);
 for(unsigned row=0;row<height;++row){need(m.r8(pixels+width-1u)!=0u);std::array<unsigned char,1024>bytes{};leaf::Memory scratch(bytes.data(),0x10000u,unsigned(bytes.size()));for(unsigned k=0;k<width;++k)scratch.w8(0x10000u+k,m.r8(pixels+k));leaf::Inputs q{};q.arg[0]=0x10000u;q.arg[1]=0x10202u;q.arg[2]=width;const auto size=leaf::fun_00634540(scratch,q)+2u;need(cursor+size<=base+capacity);m.w8(0xaa5050u,size);m.w8(0xaa5051u,size>>8u);for(unsigned k=2u;k<size;++k)m.w8(0xaa5050u+k,scratch.r8(0x10200u+k));for(unsigned k=0;k<size;++k)h.w8(cursor+k,m.r8(0xaa5050u+k));cursor+=size;m.w32(owner+8u,cursor);pixels+=pitch;if(root==0x28f870u)i.arg[1]=pixels;else{i.arg[2]=pixels;i.arg[3]=row+1u;}}
 m.w32(surface+12u,0u);return start;
}
}
