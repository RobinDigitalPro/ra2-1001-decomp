#include "recovered/recovery_b855.hpp"
#include "recovered/recovery_b411.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b855 {
using U=std::uint32_t;
U fun_005f5800(Memory&m,const Inputs&i){int d=int(i.arg[0]),x=int(m.r32(i.dx)),y=int(m.r32(i.dx+4)),w=int(m.r32(i.dx+8)),h=int(m.r32(i.dx+12));if(d<1||d>3||w<2||h<2||x<d||y<d||x+w+d>32||y+h+d>24||m.r32(i.cx)!=0x785ef8||m.r32(0x785f28)!=0x75f290)throw std::domain_error("855 positivecontainedoriginalsurfaceoutline");U color=i.arg[1];if(color==0xffffffffu){U packed=m.r32(0xa5dcac);if(packed!=0xffffffffu){U a=(packed&255)>>(m.r32(0x83b2ec)&31),b=((packed>>8)&255)>>(m.r32(0x83b2fc)&31),c=((packed>>16)&255)>>(m.r32(0x83b2f4)&31);color=(a<<(m.r32(0x83b2e8)&31))|(b<<(m.r32(0x83b2f8)&31))|(c<<(m.r32(0x83b2f0)&31));}i.arg[1]=color;}
 std::array<std::uint8_t,64>raw{};constexpr U p=0xf2200000;ra2::recovered::leaf::Memory local(raw.data(),p,64);Memory work=m;work.add(local);work.w32(p,0);work.w32(p+4,0);work.w32(p+8,32);work.w32(p+12,24);auto line=[&](int x0,int y0,int x1,int y1){work.w32(p+16,x0);work.w32(p+20,y0);work.w32(p+24,x1);work.w32(p+28,y1);Inputs c{};c.cx=i.cx;c.arg[0]=p;c.arg[1]=p+16;c.arg[2]=p+24;c.arg[3]=color;c.fp=i.fp;ra2::recovered::recovery_b411::fun_0075f2c0(work,c);i.fp=c.fp;};
 int l=x-d,t=y-d,r=x+w+d-1,b=y+h+d-1;for(int k=0;k<d;++k){line(l+k,t+k,r-k-1,t+k);line(l+k,b-k,r-k,b-k);line(l+k,t+k+1,l+k,b-k);line(r-k,t+k,r-k,b-k-1);}return U(d);}
}
