#include "map_b87.hpp"
#include <algorithm>
namespace ra2::recovered::map_b87 {
namespace {
using namespace floating_b61;
std::uint32_t projected_height(Memory&m,const Inputs&i,std::uint32_t z){
 auto&f=i.fp;f.load_integer32(z);f.multiply64(read64(m,0xaa5f90));ra2::platform::x87_extended::add_integer32(f,s32(z)>=728?1:0);f.add64(read64(m,0x785728));
 const auto c=m.r32(0x7c3a04);if(f.control()!=c)f.load_control(std::uint16_t(c));return std::uint32_t(f.pop_integer64());
}
std::uint32_t grid_score(Memory&m,std::uint32_t grid,std::uint32_t x,std::uint32_t y){
 const auto xx=s32(sx16(x))/4,yy=s32(sx16(y))/4;return m.r32(grid+0x58dc+4*(xx+130*yy));
}
}
std::uint32_t fun_00547d80(Memory&m,const Inputs&i){
 using namespace floating_b61;const auto p=i.arg[0],radius=i.arg[1],z=m.r32(p+8);
 auto correction=[](std::uint32_t h){auto q=sar(global_b26::imul_high(h,0x77777777)-h,4);return (q+(q>>31))<<8;};
 const auto ax=m.r32(p)+correction(projected_height(m,i,z)),ay=m.r32(p+4)+correction(projected_height(m,i,z));
 const auto x=s32(ax)/256,y=s32(ay)/256;const int r=int(radius);
 for(int dx=-2-r;dx<r+2;++dx)for(int dy=-2-r;dy<r+2;++dy){
  if(dx*dx+dy*dy>=(r+1)*(r+1))continue;
  const auto xx=std::uint16_t(x+dx),yy=std::uint16_t(y+dy);const auto packed=std::uint32_t(xx)|(std::uint32_t(yy)<<16);
  const auto index=sx16(xx)+(sx16(yy)<<9);std::uint32_t cell=0;
  if(s32(index)>=0&&index<0x40000)cell=m.r32(m.r32(0x81a958)+4*index);
  if(!cell){m.w32(0xa57634,packed);cell=0xa57610;}
  m.w32(cell+0x130,0);m.w32(cell+0x134,0);m.w32(cell+0x12c,m.r32(cell+0x12c)|0x18);
 }
 return radius+2;
}
std::uint32_t fun_00564b10(Memory&m,const Inputs&i){
 using namespace floating_b61;const auto grid=i.arg[0],table=m.r32(0x81a8dc);
 auto coords=[&](std::uint32_t index){const auto id=m.r32(table+36*index+0x20),col=std::uint32_t(s32(id-1)%130);auto h=sar(global_b26::imul_high(id-col,0x7e07e07f),6);h+=h>>31;return std::pair{col*4,h*4-4};};
 const auto [rawx1,rawy1]=coords(i.arg[2]);const auto [rawx2,rawy2]=coords(i.arg[3]);
 i.arg[2]=rawy1;i.arg[1]=rawx2;i.arg[3]=rawy2;
 auto adjust=[](std::uint32_t x){return x-((s32(x)/4)%2!=0?1:0);};
 const auto x1=adjust(rawx1),y1=adjust(rawy1),x2=adjust(rawx2),y2=adjust(rawy2);
 if(std::uint16_t(x1)==std::uint16_t(x2)&&std::uint16_t(y1)==std::uint16_t(y2))return sar(grid_score(m,grid,rawx2,rawy2)+grid_score(m,grid,rawx1,rawy1),1);
 const auto a=s32(sx16(x1)),b=s32(sx16(y1)),c=s32(sx16(x2)),d=s32(sx16(y2));unsigned direction;
 if(c>a)direction=d>b?3:d>=b?2:1;else if(c<a)direction=d>b?5:d<b?7:6;else direction=d<=b?0:4;
 i.arg[3]=direction;
 auto near=[&](std::uint32_t x,std::uint32_t y,std::uint32_t selector){const auto k=m.r32(selector),p=0xa56e38+4*k;const auto xx=std::uint16_t(x+m.r16(p)),yy=std::uint16_t(y+m.r16(p+2));return std::pair{grid_score(m,grid,xx,yy),std::uint32_t((s32(sx16(yy))/4)*65)};};
 const auto one=near(x1,y1,0x7caf6c+direction*8),two=near(x1,y1,0x7caf70+direction*8);
 i.arg[1]=one.first;i.arg[0]=s32(one.first)<s32(two.first)?one.first:two.first;
 const auto three=near(x2,y2,0x7cafac+direction*8),four=near(x2,y2,0x7cafb0+direction*8);i.arg[3]=three.second;
 return sar(i.arg[0]+(s32(three.first)<s32(four.first)?three.first:four.first),1);
}
}
