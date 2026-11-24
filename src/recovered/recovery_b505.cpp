#include "recovery_b505.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b505 {
std::uint32_t fun_005f6840(Memory&m,const Inputs&i){
 using U=std::uint32_t;const U rect=i.cx,surface=i.dx;
 if(m.r32(surface)!=0x785ef8||m.r32(0x785f54)!=0x411370||m.r32(0x785f58)!=0x4112f0||
    m.r32(0x785f6c)!=0x4113c0||m.r32(surface+16)!=2)
  throw std::domain_error("505 original word-surface methods");
 const U x=m.r32(rect),y=m.r32(rect+4),w=m.r32(rect+8),h=m.r32(rect+12);
 const U width=m.r32(surface+4),height=m.r32(surface+8),pixels=m.r32(surface+20),lock=m.r32(surface+12);
 if(!pixels||!w||!h||x>=width||y>=height||w>width-x||h>height-y)
  throw std::domain_error("505 positive interior rectangle");
 m.w32(surface+12,lock+1);
 const U color=i.arg[0]&65535,a=i.arg[1]&255,b=255-a;
 for(U yy=y;yy<y+h;++yy)for(U xx=x;xx<x+w;++xx){
  const U at=pixels+2*(yy*width+xx),old=m.r16(at),r=m.r16(0xa5df30),g=m.r16(0xa5df32),blue=m.r16(0xa5df34);
  m.w32(0xb10ab8,b);
  const U red=(((old&r)*b+(color&r)*a)>>8)&r;
  const U green=(((old&g)*b+(color&g)*a)>>8)&g;
  m.w32(0xb10ab4,a);
  const U last=((old&blue)*b+(color&blue)*a)>>8;
  m.w16(at,red|green|last);
 }
 m.w32(surface+12,m.r32(surface+12)-1);
 return (lock&0xffffff00u)|1u;
}
}
