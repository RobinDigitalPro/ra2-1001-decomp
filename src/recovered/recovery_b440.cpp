#include "recovery_b440.hpp"
#include <stdexcept>
namespace ra2::recovered::ui440 {
std::uint32_t fun_004cee70(Memory&m,const Inputs&i){
 std::uint32_t selected=0,area=m.r32(0x798c04)*m.r32(0x798c10);
 const auto x=std::int32_t(i.arg[0]),y=std::int32_t(i.arg[1]);
 unsigned visited=0;
 for(auto p=i.cx;p;p=m.r32(p+4)){
  if(++visited>4||m.r32(p)!=0x78b6a0)throw std::domain_error("440 requires bounded original control chain");
  const auto left=std::int32_t(m.r32(p+0xc)),top=std::int32_t(m.r32(p+0x10));
  const auto width=std::int32_t(m.r32(p+0x14)),height=std::int32_t(m.r32(p+0x18));
  if(!m.r8(p+0x1e)&&x>=left&&x<left+width&&y>=top&&y<top+height&&width*height<=std::int32_t(area)){
   selected=p;area=std::uint32_t(width*height);
  }
  // Original78b6a0+4 -> ced70 JMP137200 returns [ECX+4].
 }
 return selected;
}
std::uint32_t fun_00677600(Memory&m,const Inputs&i){
 //214da0 ->22c040 ->9e340 returns0 for this actual id>=1000.
 const auto id=std::int32_t(i.arg[0]);
 if(id<1000)throw std::domain_error("440 positive row-tooltip ids begin at1000");
 const auto mode=m.r8(m.r32(0xa255c0)+0x2239)!=0;
 const auto raw=m.r32(0x82196c)-m.r32(0xaa486c)-(mode?26u:18u)+m.r32(0x821964)-7u;
 const auto limit=std::int32_t(raw)/50*2;
 if(id>=1000+limit)return 0;
 const auto row=i.cx+0x1540+3684u*m.r32(i.cx+0x4ed8);
 const auto index=id-1000+2*std::int32_t(m.r32(row+0x40));
 const auto count=std::int32_t(m.r32(row+0x50));
 if(!m.r8(0xa285a8)||index>=count||count>=75)return 0;
 const auto record=row+48u*std::uint32_t(index);
 if(m.r32(record+0x58)!=31)throw std::domain_error("440 bounded positive tooltip requires type31");
 const auto table=m.r32(0xa27f8c);
 return m.r32(m.r32(table+4u*m.r32(record+0x54))+0x60);
}
}
