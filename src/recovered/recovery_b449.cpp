#include "recovered/recovery_b449.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::surface_b449 {
namespace {
using U=std::uint32_t;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
struct Scratch {
 std::array<unsigned char,128> bytes{};
 static constexpr U base=0xf2400000u;
 ra2::recovered::leaf::Memory span{bytes.data(),base,bytes.size()};
};
void line(Memory&m,const Inputs&i,U surface,U clip,U x0,U y0,U x1,U y1,U color){
 Scratch s;Memory work=m;constexpr U points=Scratch::base+0x1000u;
 // The nested line argument structs have a separate private guest span from
 // the four-word clip object prepared by the outer raster.
 ra2::recovered::leaf::Memory point_span(s.bytes.data(),points,s.bytes.size());work.add(point_span);
 work.w32(points+32,x0);work.w32(points+36,y0);work.w32(points+40,x1);work.w32(points+44,y1);
 Inputs c{};c.cx=surface;c.arg[0]=clip;c.arg[1]=points+32;c.arg[2]=points+40;c.arg[3]=color;c.fp=i.fp;
 (void)recovery_b411::fun_0075f2c0(work,c);
 i.fp=c.fp;
}
}

U fun_007605d0(Memory&m,const Inputs&i){
 const U surface=i.cx,cx=i.arg[0],cy=i.arg[1],radius=i.arg[2];
 const U left=i.arg[3],top=i.arg[4],right=i.arg[5],bottom=i.arg[6],color=i.arg[7];
 need(m.r32(surface)==0x785ef8u&&m.r32(0x785ef8u+0x2cu)==0x75f2c0u,"449 authentic BSurface vtable path");
 need(radius>=1&&radius<=8&&left==0&&top==0&&right==m.r32(surface+4)&&bottom==m.r32(surface+8),"449 bounded positive circle");
 const U width=m.r32(surface+4),height=m.r32(surface+8),format=m.r32(surface+16);
 need(width<=64&&height<=64&&(format==1||format==2)&&cx>radius&&cy>radius&&cx+radius<width&&cy+radius<height,"449 visible owned pixel surface");
 const U clip=0xf2400000u;
 Scratch local;Memory work=m;work.add(local.span);
 work.w32(clip,left);work.w32(clip+4,top);work.w32(clip+8,right);work.w32(clip+12,bottom);
 int x=0,y=int(radius),decision=3-2*int(radius);
 while(x<=y){
  const U ux=U(x),uy=U(y);
  // The first callback passes pointers into the original caller argument pair;
  // those two words retain the final (+y,+x) endpoint written by the body.
  i.arg[0]=cx+uy;i.arg[1]=cy+ux;
  line(work,i,surface,clip,cx-uy,cy+ux,cx+uy,cy+ux,color);
  line(work,i,surface,clip,cx-ux,cy+uy,cx+ux,cy+uy,color);
  line(work,i,surface,clip,cx-uy,cy-ux,cx+uy,cy-ux,color);
  line(work,i,surface,clip,cx-ux,cy-uy,cx+ux,cy-uy,color);
  if(decision<0)decision+=4*x+6;
  else{decision+=4*(x-y)+10;--y;}
  ++x;
 }
 // The machine body keeps the signed negative Y midpoint in the radius slot.
 i.arg[2]=U(-y);
 return U(x);
}
}
