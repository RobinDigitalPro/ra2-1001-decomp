#include "recovery_b518.hpp"
#include "recovery_b508.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b518 {
namespace {
using U=std::uint32_t;
U add(U a,U b){return (U(std::uint16_t((a>>16)+(b>>16)))<<16)|std::uint16_t(a+b);}
U scan(Memory&m,U start,U step,std::int32_t low,std::int32_t high){
 U point=start;
 for(unsigned k=0;k<16;++k){
  // 55B87A/55B883 and 55B8F4/55B8FD retain the new packed point.
  point=add(point,step);
  const auto index=std::int32_t(std::int16_t(point>>16))*512+std::int16_t(point);
  if(index<0||index>=0x40000)throw std::domain_error("B518 excludes invalid indices");
  const U cell=m.r32(m.r32(0x81a958)+U(index)*4);
  if(!cell)throw std::domain_error("B518 excludes fallback cells");
  const auto prop=std::int32_t(m.r32(cell+0x44));
  if(prop<low||prop>high)return point;
 }
 throw std::domain_error("B518 excludes longer scans");
}
U run(Memory&m,const Inputs&i,std::int32_t low,std::int32_t high){
 const U west=m.r32(0x839db8),east=m.r32(0x839da8);
 const U first=add(scan(m,i.arg[0],west,low,high),east);
 const U last=add(scan(m,i.arg[0],east,low,high),west);
 // The original pushes two packed values, not pointers to the outer argument.
 Inputs child=i;child.arg[0]=first;child.arg[1]=last;
 const U result=recovery_b508::fun_00555130(m,child);
 i.fp=child.fp;
 // 55B938/55B93D and 55CA80/55CA85 publish the second endpoint.
 i.arg[0]=last;
 return result;
}
}
std::uint32_t fun_0055b840(Memory&m,const Inputs&i){return run(m,i,0x4a,0x65);}
std::uint32_t fun_0055c980(Memory&m,const Inputs&i){return run(m,i,0xcd,0xe8);}
}
