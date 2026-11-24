#include "recovered/recovery_b1053.hpp"
#include <stdexcept>
namespace ra2::recovered::b1053 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
std::uint32_t fun_006fe9d0(Memory&m,const Inputs&i,State&fp,Observation&o){
 b1048::fun_006b72a0(m,i,fp);++o.base_calls;
 const unsigned receiver=i.cx,type=m.r32(receiver+0x5acu),house=m.r32(receiver+0x1b4u);
 need(type&&house&&m.r8(house+0x207u)==0u&&m.r8(type+0x701u)==0u,"1053 genuine bounded nonnull type/house and original constructor defaults");
 const unsigned record=m.r32(house+0x34u),vec=record+0x168u,n=m.r32(vec+0x10u),a=m.r32(vec+4u);
 need(record&&m.r32(vec)==0x78e0d8u&&n>=2u&&n<=7u&&n<=m.r32(vec+8u),"1053 authentic constructor/config-produced populated type list");
 bool found=false;for(unsigned j=0;j<n;++j){++o.membership_comparisons;if(m.r32(a+j*4u)==type){found=true;break;}}
 need(found,"1053 positive actual type membership");
 // Exact accepted7080E0(true) is two integer stores of IEEE binary64 one;
 // it does not execute x87 or alter the preceding GetWeapon status.
 m.w32(receiver+0x118u,0u);m.w32(receiver+0x11cu,0x3ff00000u);++o.boolean_stores;
 return type;
}
}
