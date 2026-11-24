#include "recovery_b437.hpp"
#include <stdexcept>
namespace ra2::recovered::controls437 {
namespace {
std::uint32_t change(Memory&m,std::uint32_t object,bool enabled){
 // Actual ced20/ced30 tails reach cf1f0 through constructor26a9a0's
 // original vtable78b6a0 slot54. Preserve its incidental full EAX.
 const auto table=m.r32(object);
 if(table!=0x78b6a0u)throw std::domain_error("437 constructor-proven control table required");
 m.w8(object+0x1e,enabled?0u:1u);m.w8(object+0x1c,1u);
 if(m.r32(0x84e328)!=object)return table;
 const auto value=m.r32(object+0x20)&0xfffffeffu;
 m.w32(object+0x20,value);m.w32(0x84e328,0);return value;
}
}
std::uint32_t fun_00672010(Memory&m,const Inputs&i){
 const auto mode=m.r8(m.r32(0xa255c0)+0x2239)!=0;
 const auto raw=m.r32(0x82196c)-m.r32(0xaa486c)-(mode?26u:18u)+m.r32(0x821964)-7u;
 const auto limit=static_cast<std::int32_t>(raw)/50*2;
 const auto index=m.r32(i.cx+0x4ed8);
 const auto count=static_cast<std::int32_t>(m.r32(i.cx+0x1590+3684u*index));
 const bool enable=count>limit;
 const bool first=m.r8(0xaa46f0+0x1e)==0;
 if(first!=enable)change(m,0xaa46f0,enable);
 const bool second=m.r8(0xaa47c8+0x1e)==0;
 if(second!=enable)return change(m,0xaa47c8,enable);
 return second?1u:0u;
}
}
