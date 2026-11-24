#include "recovery_b411.hpp"
#include "numeric_b105.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b411 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// Finite positive axis-aligned route through the authentic software-surface
// virtual graph. Original private points/rectangles have a separate C++ span.
U line(Memory&m,const Inputs&i,U surface,U clip,U x0,U y0,U x1,U y1,U color){
 const U w=m.r32(surface+4),h=m.r32(surface+8),fmt=m.r32(surface+16);
 need(m.r32(surface)==0x785ef8&&(fmt==1||fmt==2)&&w<=64&&h<=64,"411 software surface");
 need(m.r32(clip)==0&&m.r32(clip+4)==0&&m.r32(clip+8)==w&&m.r32(clip+12)==h,"411 full bounds clip");
 need(x0<w&&x1<w&&y0<h&&y1<h&&(x0==x1||y0==y1),"411 visible axis line");
 std::array<unsigned char,64> bytes{};constexpr U p=0xf2100000;
 leaf::Memory local(bytes.data(),p,bytes.size());Memory work=m;work.add(local);
 work.w32(p,x0);work.w32(p+4,y0);work.w32(p+8,x1);work.w32(p+12,y1);
 work.w32(p+16,0);work.w32(p+20,0);work.w32(p+24,w);work.w32(p+28,h);
 Inputs ci{};ci.cx=p;ci.dx=p+8;ci.arg[0]=p+16;ci.fp=i.fp;
 need((numeric_b105::fun_00760f60(work,ci)&255)==1,"411 accepted clipping dependency");i.fp=ci.fp;
 x0=work.r32(p);y0=work.r32(p+4);x1=work.r32(p+8);y1=work.r32(p+12);
 if(x0>x1){std::swap(x0,x1);std::swap(y0,y1);}
 const U old=m.r32(surface+12),buffer=m.r32(surface+20);m.w32(surface+12,old+1);
 auto pixel=[&](U x,U y){const U a=buffer+fmt*(y*w+x);if(fmt==1)m.w8(a,color);else m.w16(a,color);};
 if(y0==y1){for(U x=x0;x<=x1;++x)pixel(x,y0);}
 else{const int step=y0<y1?1:-1;for(int y=int(y0);;y+=step){pixel(x0,U(y));if(y==int(y1))break;}}
 m.w32(surface+12,m.r32(surface+12)-1);
 return (m.r32(surface+12)&0xffffff00u)|1u;
}
U outline(Memory&m,const Inputs&i,U s,U clip,U x,U y,U w,U h,U color){
 need(w>1&&h>1&&w<=32&&h<=32,"411 positive rectangle");
 line(m,i,s,clip,x,y,x+w-1,y,color);
 line(m,i,s,clip,x,y,x,y+h-1,color);
 line(m,i,s,clip,x+w-1,y,x+w-1,y+h-1,color);
 return line(m,i,s,clip,x,y+h-1,x+w-1,y+h-1,color);
}
}
U fun_0075f2c0(Memory&m,const Inputs&i){
 const U s=i.cx,p=i.arg[1],q=i.arg[2];
 const U result=line(m,i,s,i.arg[0],m.r32(p),m.r32(p+4),m.r32(q),m.r32(q+4),i.arg[3]);
 i.arg[1]=m.r32(s+16);return result;
}
U fun_0075fa70(Memory&m,const Inputs&i){const U r=i.arg[1];return outline(m,i,i.cx,i.arg[0],m.r32(r),m.r32(r+4),m.r32(r+8),m.r32(r+12),i.arg[2]);}
U fun_0069fdd0(Memory&m,const Inputs&i){
 U x=m.r32(i.cx+0xd90),y=m.r32(i.cx+0xd94),xx=m.r32(i.cx+0xd98),yy=m.r32(i.cx+0xd9c);
 need(x||y,"411 positive initialized selection");if(x>xx)std::swap(x,xx);if(y>yy)std::swap(y,yy);
 const U palette=m.r32(0x81a704),colors=m.r32(palette+0x174);
 const U color=m.r32(palette+4)==1?m.r8(colors+15):m.r16(colors+30);
 return outline(m,i,m.r32(0x821c9c),0x821970,x,y,xx-x+1,yy-y+1,color);
}
}
