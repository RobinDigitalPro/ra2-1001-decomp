#include "recovered/recovery_b1064.hpp"
#include "platform/observed_ticks1064.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1064 {
static void need(bool x){if(!x)throw std::domain_error("1064 outside populated ordinary event decoder contract");}
static constexpr unsigned char lengths[]{0,5,5,4,23,24,5,5,0,5,5,16,0,4,12,12,12,5,8,0,16,5,5,4,4,0,0,1,7,0,10,4,5,2,0,4,4,104,48,0,4,5,10,0,5,4};
std::uint32_t fun_0061fa40(Memory&m,const Inputs&i){
 need(i.dx>=14u&&m.r8(i.cx)==28u);
 std::array<unsigned char,111>row{};unsigned cursor=0u,remaining=i.dx,done=0u;
 while(remaining){
  const auto type=m.r8(i.cx+cursor);need(type<46u&&type!=4u&&type!=25u&&type!=31u&&lengths[type]>0u);
  if(type==28u){need(cursor==0u&&remaining>=14u);row[2]=m.r8(i.cx+2u);for(unsigned k=0;k<4u;++k)row[3u+k]=m.r8(i.cx+3u+k);cursor+=6u;remaining-=6u;}
  const unsigned count=lengths[type];need(remaining>=count+1u);row[0]=static_cast<unsigned char>(type);std::fill(row.begin()+7,row.end(),0u);
  const unsigned offset=type==27u?13u:7u;for(unsigned k=0;k<count;++k)row[offset+k]=m.r8(i.cx+cursor+1u+k);
  const auto tail=m.r32(0x84e5a8u);need(tail<16384u&&m.r32(0x84e5a0u)<16384u);
  for(unsigned k=0;k<111u;++k)m.w8(0x84e5acu+111u*tail+k,row[k]);
  m.w32(0xa0a5acu+4u*tail,ra2::platform::ticks1064::Tick::get());
  m.w32(0x84e5a8u,(tail+1u)&16383u);m.w32(0x84e5a0u,m.r32(0x84e5a0u)+1u);++done;cursor+=1u+count;remaining-=1u+count;
 }
 return done;
}
}
