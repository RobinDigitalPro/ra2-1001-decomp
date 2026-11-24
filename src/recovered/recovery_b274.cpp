#include "recovered/recovery_b274.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b274 {
namespace {
void require(bool condition,const char* why){if(!condition)throw std::domain_error(why);}
constexpr std::array<std::int32_t,13> month_offsets={365,-1,30,58,89,119,150,180,211,242,272,303,333};
}
// RVA376572: calendar fields to wrapping 32-bit seconds, with supplied already
// initialized CRT timezone state. This does not perform OS timezone discovery.
std::uint32_t fun_00776572(Memory& m,const Inputs& i){
 const auto year=i.arg[0];
 require(year>=1969u&&year<=2039u,"274 finite reviewed year range");
 if(year<1970u||year>2038u)return 0xffffffffu;
 const auto month=i.arg[1],day=i.arg[2],hour=i.arg[3],minute=i.arg[4],second=i.arg[5],dst=i.arg[6];
 require(month>=1&&month<=12&&hour<24&&minute<60&&second<60&&dst<=1,"274 valid calendar/time fields and explicit DST only");
 constexpr unsigned lengths[]={31,28,31,30,31,30,31,31,30,31,30,31};
 require(day>=1&&day<=lengths[month-1]+(month==2&&year%4==0?1u:0u),"274 valid day within month");
 // Actual37dde6 sees the supplied nonzero initialization flag and returns at
//77de13; its OS/locking initialization path is excluded from this contract.
 require(m.r32(0xb107d0)==1,"274 supplied initialized timezone state");
 require(m.r32(0x818570)==28800&&m.r32(0x818574)==1&&m.r32(0x818578)==std::uint32_t(-3600),"274 original fixed timezone values");
 for(unsigned k=0;k<month_offsets.size();++k)require(m.r32(0x818654+4*k)==std::uint32_t(month_offsets[k]),"274 original month table");
 const auto years=year-1900u;
 auto days=std::int64_t(years)*365+(years-1)/4+month_offsets[month]+day;
 if(years%4==0&&month>2)++days;
 const auto before_dst=std::uint32_t((((days*24+hour)*60+minute)*60+second)+28800-2208988800LL);
 // Original7765ff overwrites caller argument0 BEFORE the optional DST add.
 i.arg[0]=before_dst;
 return before_dst+(dst?std::uint32_t(-3600):0u);
}
}
