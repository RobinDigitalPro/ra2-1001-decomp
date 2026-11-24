#include "recovery_b339.hpp"
#include <stdexcept>
#include <cstdint>
namespace ra2::recovered::recovery_b339 {
static void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned fun_004f59c0(Memory&m,const Inputs&i){
 need(m.r32(0xa255c8)!=0,"339 active object guard");const auto id=m.r32(i.arg[0]);
 need(std::int32_t(id)>=0&&std::int32_t(id)<std::int32_t(m.r32(0xa1e018)),"339 valid index");
 const auto item=m.r32(m.r32(0xa1e00c)+4*id);need(item!=0,"339 valid item");
 const auto indexed=item+0x74c; // actual6d4b30(selector0) address result
 if(m.r32(indexed))return (indexed&0xffffff00)|1;
 need(m.r8(item+0x1215)==0,"339 no neighboring-object path");
 const auto amount=m.r32(item+0xc68);if(std::int32_t(amount)>0)return (amount&0xffffff00)|1;
 const auto total=m.r32(i.cx+0x5408)+m.r32(m.r32(0x821b88)+0xbe4),limit=m.r32(0xa2896c);
 return (limit&0xffffff00)|unsigned(std::int32_t(total)<=std::int32_t(limit));
}
unsigned fun_005651b0(Memory&m,const Inputs&i){
 need(m.r32(0xa255c8)==0,"339 ordinary map predicate mode");const auto point=i.arg[0];
 const auto divisor=std::int32_t(m.r32(0xa57848));need(divisor>0,"339 positive height scale");
 const auto q=std::int32_t(m.r32(point+8))/divisor;need(q>=0&&q<=6&&(q&1)==0,"339 even bounded height quotient");
 const auto x=std::int32_t(m.r32(point))/256-q/2,y=std::int32_t(m.r32(point+4))/256-q/2;
 need(x>=1&&x<=31&&y>=1&&y<=31,"339 valid bounded map coordinate");
 i.arg[0]=unsigned(x)|(unsigned(y)<<16);
 const auto cell=m.r32(m.r32(0x81a958)+4*(unsigned(y)*512+unsigned(x)));need(cell!=0,"339 valid supplied cell");
 return (cell&0xffffff00)|unsigned((m.r8(cell+0x140)&2)==0);
}
}
