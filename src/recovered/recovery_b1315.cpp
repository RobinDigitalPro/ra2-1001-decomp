#include "recovery_b1315.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1315 {
namespace {
void need(bool ok,const char* message){if(!ok)throw std::domain_error(message);}
unsigned packed(int x,int y){return unsigned(std::uint16_t(x))|(unsigned(std::uint16_t(y))<<16u);}
unsigned lookup(Memory&m,unsigned coord){
 const auto x=std::int16_t(coord&65535u),y=std::int16_t(coord>>16u);
 const int index=int(y)*512+int(x);
 if(index>=0&&index<0x40000){
  const auto table=m.r32(0x81a958u);need(table!=0u,"1315 borrowed map grid");
  if(const auto cell=m.r32(table+4u*unsigned(index)))return cell;
 }
 m.w32(0xa57634u,coord);return 0xa57610u;
}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&heap){
 need(root==0x15def0u||root==0x15e130u,"1315 two original wrapper roots");
 // The original captures its pointer in ESI before using the caller's
 // argument DWORD as coordinate scratch: entry S, stable root SP=S-16.
 const auto coordinate_pointer=i.arg[0];
 need(coordinate_pointer&&m.r32(coordinate_pointer)==packed(1,1),"1315 accepted child center1,1");
 const auto cell=lookup(m,m.r32(coordinate_pointer));
 need(cell!=0xa57610u,"1315 positive original center lookup");
 const auto category=m.r32(cell+0x44u);
 const unsigned vertical_category=root==0x15def0u?0x4eu:0xd1u;
 const unsigned horizontal_category=root==0x15def0u?0x57u:0xdau;
 need(category==vertical_category||category==horizontal_category,"1315 finite positive categories");
 const bool vertical=category==vertical_category;
 const unsigned lower=root==0x15def0u?0x4au:0xcdu;
 const unsigned upper=root==0x15def0u?0x65u:0xe8u;
 i.arg[0]=vertical?packed(1,0):packed(0,1);
 const auto first=lookup(m,i.arg[0]);
 const int first_category=std::int32_t(m.r32(first+0x44u));
 need(first!=0xa57610u&&first_category>=int(lower)&&first_category<=int(upper),
      "1315 first original neighbor is in the same family");
 i.arg[0]=vertical?packed(1,-1):packed(-1,1);
 const auto second=lookup(m,i.arg[0]);
 need(second==0xa57610u&&m.r32(second+0x44u)==0u,
      "1315 second original neighbor takes genuine fallback outside family");
 const unsigned child=root==0x15def0u?(vertical?0x15e390u:0x15e870u):
                                      (vertical?0x15ed50u:0x15f240u);
 Inputs nested=i;nested.arg[0]=coordinate_pointer;
 const auto result=b1296::run(child,m,nested,heap);
 i.fp=nested.fp;
 return result; // Real final HeapFree BOOL; POP/ADD/RET4 preserve full EAX.
}
}
