#include "recovered/recovery_b1217.hpp"
#include "platform/build_time1217_fp.hpp"
#include <stdexcept>
namespace ra2::recovered::b1217{namespace{void need(bool b,const char*s){if(!b)throw std::domain_error(s);}unsigned truncate(State&f){f.load_control_masked(0xe7fu);return unsigned(f.pop_integer64());}}
unsigned run(unsigned r,Memory&m,const Inputs&i,State&f){need(r==0x2b7910u&&m.r32(i.cx)==0x78e540u,"1217 exact root/genuine Infantry");const unsigned type=m.r32(i.cx+0x5a8u),house=m.r32(i.cx+0x1b4u),rules=m.r32(0x821b88u);need(m.r32(type)==0x78ea78u&&house&&rules,"1217 actual actor/type/House/Rules readset");const unsigned cost=m.r32(type+0x550u);need(cost>=10u&&cost<=1000u&&cost%10u==0u,"1217 genuine INI Cost multiple10 domain");need(m.r32(rules+0x13b0u)==0u&&m.r32(rules+0x13b4u)==0x3ff00000u,"1217 actual Rules constructor double1");
 // Actual6D0280 Type+88, including its tail76AA50 control change.
 f.load_integer32(cost);f.multiply64(0x3ff0000000000000ull);f.multiply64(0x3feccccccccccccdull);const unsigned base=truncate(f);
 // Actual actor+80 tails505DA0;4F4F70 dispatches true InfType kind16.
 const auto country=m.r32(house+0x34u);need(country&&m.r32(country+0x134u)==0x3f800000u,"1217 actual CountryType TimeInfantry1.0");f.load32(m.r32(country+0x134u));ra2::platform::build_time1217::integer_multiply(f,base);const unsigned raw=truncate(f);
 need(m.r32(house+0x52d0u)==0u&&m.r32(house+0x52d4u)==0u,"1217 genuine fresh House storage0/0");f.load64(0x3ff0000000000000ull);const auto ratio=f.pop32();
 need(m.r32(rules+0x490u)==0x3f000000u&&m.r32(rules+0x494u)==0x3f666666u&&m.r32(rules+0x498u)==0x3f800000u&&m.r32(rules+0x49cu)==0x3f800000u,"1217 actual Rules constructor modifiers");
 f.load32(0x3f800000u);f.subtract32(ratio);f.multiply32(m.r32(rules+0x498u));ra2::platform::build_time1217::reverse_subtract32(f,0x3f800000u);f.load32(m.r32(rules+0x490u));f.load_st1();f.compare_pop_twice();need((f.status()&0x4100u)==0u,"1217 genuine factor1 above min.5");f.load32(ratio);f.compare_pop32(0x3f800000u);need((f.status()&0x100u)==0u,"1217 actualratio1 comparison skipmax.9");f.compare32(0u);need((f.status()&0x4000u)==0u,"1217 nonzero positive factor");f.load_integer32(raw);ra2::platform::build_time1217::divide_st0_st1(f);const unsigned answer=truncate(f);f.pop_st0();
 const unsigned private_argument=ratio&0xffffff00u;need(private_argument==0x3f800000u,"1217 produced float argumentword upper24 preserved after lowbyteclear");need(m.r32(house+0x52bcu)==0u,"1217 actual4EAEA0 kind15 fresh Infantry factorycount0");f.load32(m.r32(rules+0x49cu));f.compare_pop32(0u);need((f.status()&0x4100u)==0u,"1217 positive parallel factor1; factorycount0 skips repeat");return answer;}
}
