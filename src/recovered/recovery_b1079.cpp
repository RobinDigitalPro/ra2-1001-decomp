#include "recovered/recovery_b1079.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::b1079 {
static void need(bool v){if(!v)throw std::domain_error("1079 outside populated visible radius scan");}
static unsigned project_height(Memory&m,const Inputs&i,unsigned height){
 i.fp.load_integer32(height);i.fp.multiply64(read64(m,0xaa5f90u));
 ra2::platform::x87_extended::add_integer32(i.fp,s32(height)>=728?1u:0u);
 i.fp.add64(read64(m,0x785728u));return numeric_b88::detail::integer(m,i.fp);
}
unsigned fun_005475a0(Memory&m,const Inputs&i){
 const auto owner=i.cx,point=i.arg[0],radius=i.arg[1],house=i.arg[2];
 need(owner==0x81a820u&&radius>=1u&&radius<=3u&&house!=0u&&house==m.r32(0xa1e0e4u));
 need((i.arg[3]&255u)==0u&&(i.arg[5]&255u)==1u&&(i.arg[6]&255u)==0u);
 const auto z=m.r32(point+8u);need(z==0u&&m.r32(0xa57848u)!=0u);
 const auto x=s32(numeric_b88::detail::div256(m.r32(point))),y=s32(numeric_b88::detail::div256(m.r32(point+4u)));
 need(project_height(m,i,z)==0u&&project_height(m,i,z)==0u);
 const auto width=s32(m.r32(owner+0xf0u)),height=s32(m.r32(owner+0xf4u));
 need(x+y>width&&x-y<width&&y-x<width&&x+y<=width+2*height);
 const auto count=m.r32(0x7908e8u+radius*4u);need(count==(radius==1u?9u:radius==2u?21u:37u));
 need(m.r32(0x821b88u)!=0u);(void)m.r8(m.r32(0x821b88u)+0x1432u);
 i.arg[0]=0xa56934u;
 for(unsigned j=0;j<count;++j){
  const auto a=0xa56e68u+4u*j;const auto dx=std::int32_t(std::int16_t(m.r16(a))),dy=std::int32_t(std::int16_t(m.r16(a+2u)));
  const auto xx=x+dx,yy=y+dy;i.arg[0]+=4u;
  need(xx+yy>width&&xx-yy<width&&yy-xx<width&&xx+yy<=width+2*height);
  need(dx>=-int(radius)&&dx<=int(radius));
  i.fp.load_integer32(unsigned(dy));i.fp.load_integer32(unsigned(dx));i.fp.load_st0();numeric_b88::detail::reg<0xd8c9>(i.fp);
  i.fp.load_st2();numeric_b88::detail::reg<0xd8cb>(i.fp);i.fp.add_pop();
  const auto square=i.fp.pop64();i.fp.pop_st0();i.fp.pop_st0();
  numeric_b88::detail::root(m,i.fp,square);const auto distance=std::int32_t(std::int16_t(numeric_b88::detail::integer(m,i.fp)));
  need(distance<=int(radius));const auto index=512*yy+xx;need(index>=0&&index<0x40000);
  const auto cell=m.r32(m.r32(owner+0x138u)+4u*unsigned(index));need(cell!=0u);
  const auto flags=m.r32(cell+0x140u);need((flags&3u)==2u&&(m.r8(cell+0x12cu)&8u)==0u);m.w32(cell+0x140u,flags&~0x40u);
 }
 return 0u;
}
}
