#include "recovered/recovery_b841.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b841 {
using U=std::uint32_t;
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void object(Memory&m,U item){need(item&&m.r32(item)==0x787bbc,"841 original object table");need(m.r32(0x787d5c)==0x41b320&&m.r32(0x787e84)==0x4537d0&&m.r32(0x787e88)==0x4537e0,"841 original coordinate slots");}
U bucket(Memory&m,U tracker,U packed){const U dx=m.r32(0x81a948),dy=m.r32(0x81a94c);
 need(dx>=20&&dx<=480&&dy>=20&&dy<=480&&dx%20==0&&dy%20==0,"841 dimension bounds");
 const auto x=std::max(0,int(std::int16_t(packed&65535))),y=std::max(0,int(std::int16_t(packed>>16)));
 return tracker+24*(std::min(19,x/int(dx/20))+20*std::min(19,y/int(dy/20)));}
}
U fun_004131e0(Memory&m,const Inputs&i){const U item=i.arg[0];object(m,item);
 const auto x=std::int32_t(m.r32(item+0x88))/256,y=std::int32_t(m.r32(item+0x8c))/256;
 const U packed=std::uint16_t(x)|(U(std::uint16_t(y))<<16);i.arg[0]=packed;
 // Authentic setter4537E0 is RET4; its input packedcoordinate has no other effects.
 const U b=bucket(m,i.cx,packed),count=m.r32(b+0x10),cap=m.r32(b+8),data=m.r32(b+4);
 need(data&&count<cap&&count<=9,"841 spare bucket capacity required");
 m.w32(b+0x10,count+1);m.w32(data+4*count,item);return count;
}
U fun_00413310(Memory&m,const Inputs&i){const U item=i.arg[0];object(m,item);
 const U packed=m.r32(0x83705c);(void)m.r32(0x8221a8); // Passed to genuine RET4 setter.
 const U b=bucket(m,i.cx,packed),count=m.r32(b+0x10),data=m.r32(b+4);
 need(m.r32(b)==0x797fec&&m.r32(0x797ffc)==0x453d80&&count>=1&&count<=10,"841 authentic bounded vector lookup");
 U at=0;while(at<count&&m.r32(data+4*at)!=item)++at;need(at<count,"841 positive unique item hit");
 m.w32(b+0x10,count-1);for(U k=at;k+1<count;++k)m.w32(data+4*k,m.r32(data+4*k+4));return count-1;
}
}
