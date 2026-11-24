#include "recovered/recovery_b854.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b854 {
using U=std::uint32_t;
static void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
static U draw(Memory&m,U self,int x0,int y0,int x1,int y1,U color){
 need(m.r32(self)==0x785ef8&&m.r32(self+16)==1&&m.r32(self+4)==32&&m.r32(self+8)==24,"854 initialized8bit32x24BSurface");need(m.r32(0x785f54)==0x411370&&m.r32(0x785f58)==0x4112f0&&m.r32(0x785f68)==0x4113b0&&m.r32(0x785f6c)==0x4113c0&&m.r32(0x785f74)==0x4112c0,"854 originalvirtualslots");need(x0>=0&&x0<32&&x1>=0&&x1<32&&y0>=0&&y0<24&&y1>=0&&y1<24,"854 containedline");if(x0>x1){std::swap(x0,x1);std::swap(y0,y1);}U pixels=m.r32(self+20),lock=m.r32(self+12);need(pixels&&m.r32(self+24)>=768,"854 fullsoftwarebuffer");m.w32(self+12,lock+1);auto put=[&](int x,int y){m.w8(pixels+U(y*32+x),color);};int dx=x1-x0,dy=std::abs(y1-y0),sy=y1<y0?-1:1;
 if(y0==y1){for(int x=x0;x<=x1;++x)put(x,y0);}else if(x0==x1){for(int k=0;k<=dy;++k)put(x0,y0+sy*k);}else if(dx>dy){int err=2*dy-dx,y=y0;for(int k=0;k<dx;++k){put(x0+k,y);if(err>0){y+=sy;err-=2*dx;}err+=2*dy;}}else{int err=2*dx-dy,x=x0;for(int k=0;k<dy;++k){put(x,y0+sy*k);if(err>0){++x;err-=2*dy;}err+=2*dx;}}
 m.w32(self+12,m.r32(self+12)-1);return (m.r32(self+12)&0xffffff00u)|1;
}
U fun_005f4f70(Memory&m,const Inputs&i){return draw(m,i.cx,int(m.r32(i.dx)),int(m.r32(i.dx+4)),int(m.r32(i.arg[0])),int(m.r32(i.arg[0]+4)),i.arg[1]);}
U fun_005f54f0(Memory&m,const Inputs&i){int x=int(m.r32(i.dx)),y=int(m.r32(i.dx+4)),w=int(m.r32(i.dx+8)),h=int(m.r32(i.dx+12)),depth=int(i.arg[1]);need(depth>=1&&depth<=3&&w>=2*depth+2&&h>=2*depth+2,"854 nondegeneratebevel");U top=i.arg[0]?0xffffu:0,bottom=i.arg[0]?0:0xffffu,got=0;for(int k=0;k<depth;++k){draw(m,i.cx,x+k,y+k,x+w-k-2,y+k,top);draw(m,i.cx,x+k,y+h-k-1,x+w-k-1,y+h-k-1,bottom);draw(m,i.cx,x+k,y+k+1,x+k,y+h-k-1,top);got=draw(m,i.cx,x+w-k-1,y+k,x+w-k-1,y+h-k-2,bottom);}return got;}
}
