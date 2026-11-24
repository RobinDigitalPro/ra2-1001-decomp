#include "recovered/recovery_b455.hpp"
#include "platform/current_crt_thread.hpp"
#include "recovered/global_b27_memory.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b455 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint32_t field(const Memory&m,std::uint32_t p,unsigned off){return m.r32(p+off);}
std::uint32_t append2(Memory&m,std::uint32_t out,std::uint32_t value){
  for(const auto&e:ra2::recovered::global_b27::entries_c())if(e.rva==0x3797a6u){
    ra2::recovered::global_b27::State s{};s.arg[0]=out;s.arg[1]=value;e.function(m,s);return s.ax;
  }
  throw std::domain_error("accepted 0x3797a6 decimal helper is unavailable");
}
}
std::uint32_t fun_003796dc(Memory&m,const Inputs&i){
  const auto record=i.arg[0];need(record!=0,"0x3796dc requires a nonnull time record");
  const auto state=ra2::platform::current_crt_thread(m.r32(0x817778u));
  const auto buffer=m.r32(state+0x38u);
  need(buffer!=0,"0x3796dc finite route requires a warmed TLS +0x38 output buffer");
  const auto second=field(m,record,0),minute=field(m,record,4),hour=field(m,record,8);
  const auto day=field(m,record,0x0c),month=field(m,record,0x10),year=field(m,record,0x14),weekday=field(m,record,0x18);
  need(second<60u&&minute<60u&&hour<24u&&day>=1u&&day<=31u&&month<12u&&year>=100u&&year<=199u&&weekday<7u,
       "0x3796dc finite route uses Gregorian-range fields and a four-digit positive year");

  auto cursor=buffer;
  const auto weekday_at=0x79d26cu+weekday*3u,month_at=0x79d283u+month*3u+1u;
  for(unsigned n=0;n<3;++n)m.w8(cursor++,m.r8(weekday_at+n));
  m.w8(cursor++,0x20u);
  for(unsigned n=0;n<3;++n)m.w8(cursor++,m.r8(month_at+n));
  m.w8(cursor++,0x20u);
  cursor=append2(m,cursor,day);m.w8(cursor++,0x20u);
  cursor=append2(m,cursor,hour);m.w8(cursor++,0x3au);
  cursor=append2(m,cursor,minute);m.w8(cursor++,0x3au);
  cursor=append2(m,cursor,second);m.w8(cursor++,0x20u);
  cursor=append2(m,cursor,year/100u+19u);
  cursor=append2(m,cursor,year%100u);
  m.w8(cursor++,0x0au);m.w8(cursor,0u);
  need(cursor==buffer+25u,"0x3796dc output cursor drift");
  return buffer;
}
}
