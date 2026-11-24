#include "recovered/recovery_b453.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::surface_b453 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
}

U fun_0075fd00(Memory&m,const Inputs&i){
 const U surface=i.cx,origin=i.arg[0],shape=i.arg[1],color=i.arg[2];
 const U width=m.r32(surface+4),height=m.r32(surface+8),format=m.r32(surface+16),pixels=m.r32(surface+20);
 need(m.r32(surface)==0x785ef8u&&m.r32(0x785ef8u+0x74)==0x4113c0u&&
      m.r32(0x785ef8u+0x78)==0x411290u&&m.r32(0x785ef8u+0x5c)==0x411370u&&
      m.r32(0x785ef8u+0x60)==0x4112f0u&&m.r32(0x785ef8u+0x70)==0x4113b0u,
      "B453 authentic BSurface method slots");
 need(width==32&&height==24&&(format==1||format==2)&&pixels!=0&&(format!=2||(color&0xffff0000u)==0),
      "B453 finite owned BSurface pixel contract");
 need(m.r32(origin)==0&&m.r32(origin+4)==0&&m.r32(origin+8)==width&&m.r32(origin+12)==height&&
      m.r32(shape)==0&&m.r32(shape+4)==0&&m.r32(shape+8)==width&&m.r32(shape+12)==height,
      "B453 full-surface positive rectangle route");

 // The two reached 0x41fdf0 helper calls intersect an already-full caller
 // rectangle with the +0x78 BSurface bounds. Under this pinned input both
 // original operations are identity copies of the same positive rectangle.
 const U left=m.r32(origin),top=m.r32(origin+4),right=left+m.r32(origin+8),bottom=top+m.r32(origin+12);
 need(left==0&&top==0&&right==width&&bottom==height,"B453 helper 0x1fdf0 identity intersection");

 // BSurface +0x5c increments the lock depth and returns the original pixel
 // pointer at (0,0); +0x70 reports one or two bytes per pixel, and +0x74 is
 // the row stride. The original loop replicates the chosen low byte/word.
 const U lock=m.r32(surface+12);m.w32(surface+12,lock+1);
 const U stride=width*format;
 need(stride==m.r32(surface+4)*m.r32(surface+16),"B453 original row stride");
 if(format==1){
  const U dword=(color&0xffu)*0x01010101u;
  for(U y=0;y<height;++y){U x=0;for(;x+4<=width;x+=4)m.w32(pixels+y*stride+x,dword);
   for(;x<width;++x)m.w8(pixels+y*stride+x,U(color));}
 }else{
  for(U y=0;y<height;++y)for(U x=0;x<width;++x)m.w16(pixels+y*stride+2*x,U(color));
 }
 m.w32(surface+12,m.r32(surface+12)-1);
 i.arg[0]=height;i.arg[1]=stride;
 if(format==2)i.arg[2]=0;
 return (lock&0xffffff00u)|1u;
}

U write_rows(Memory&m,const Inputs&i,U value){
 const U image=i.cx,surface=m.r32(image+0x14),x=i.arg[0],y=i.arg[1],width=i.arg[2],rows=i.arg[3];
 const U pixels=m.r32(image+0x18),end=m.r32(image+0x1c),size=m.r32(image+0x20),stride=m.r32(image+0x28);
 const U sw=m.r32(surface+4),sh=m.r32(surface+8),lock=m.r32(surface+12),sp=m.r32(surface+20);
 need(m.r32(surface)==0x785ef8u&&m.r32(0x785ef8u+0x5c)==0x411370u&&
      m.r32(0x785ef8u+0x60)==0x4112f0u&&m.r32(0x785ef8u+0x70)==0x4113b0u&&
      m.r32(0x785ef8u+0x74)==0x4113c0u,"B453 authentic nested BSurface callbacks");
 need(sw==32&&sh==24&&m.r32(surface+16)==2&&sp==pixels&&stride==sw&&size==sw*sh*2&&
      end==pixels+size&&pixels==image+0x1000&&x<sw&&(x%2u)==0&&y<sh&&width>=2&&width<=16&&rows>0&&rows<=5&&
      x+width<=sw&&y+rows<=sh,"B453 bounded owned word-surface ring layout");
 m.w32(surface+12,lock+1);
 U cursor=pixels+y*sw*2+x*2;
 m.w32(surface+12,m.r32(surface+12)-1);
 cursor+=m.r32(image+0x10);
 if(cursor>=end)cursor-=size;
 for(U row=0;row<rows;++row){
  for(U col=0;col<width;++col){U at=cursor+2*col;if(at>=end)at-=size;m.w16(at,value);}
  cursor+=stride*2;if(cursor>=end)cursor-=size;
 }
 return end;
}
U fun_00761b00(Memory&m,const Inputs&i){return write_rows(m,i,0xffffu);}
U fun_004110b0(Memory&m,const Inputs&i){return write_rows(m,i,0x007fu);}
}
