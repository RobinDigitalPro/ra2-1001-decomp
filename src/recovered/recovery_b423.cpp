#include "recovery_b423.hpp"
#include "recovery_b420.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::registry423 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned release(Memory&m,unsigned token){
 need(m.r32(token)==0x793cd4&&m.r32(0x793cdc)==0x630cc0&&m.r32(token+4)>1,"423 actual reference decrement without deletion");
 auto n=m.r32(token+4)-1;m.w32(token+4,n);return n;
}
}
std::uint32_t fun_005759b0(Memory&m,const Inputs&i){
 need(m.r32(0xa255c8)==4&&m.r32(0xa255d4)==2,"423 positive registered configuration route");
 std::array<unsigned char,48>scratch{};leaf::Memory span(scratch.data(),0xf1000000,scratch.size());Memory nested=m;nested.add(span);
 Inputs child{};child.cx=0xf1000010;child.dx=m.r32(0xa255d0);
 iterator420::fun_00755830(nested,child);
 const auto token=nested.r32(child.cx+4);
 // The second temporary reference is copied, then the first is released.
 m.w32(token+4,m.r32(token+4)+1);release(m,token);
 const auto id=m.r16(token+12);need(id!=0,"423 excludes fallback ID assignment");m.w32(i.cx+0x74,id);
 constexpr unsigned direct_map[]{0,1,2,3},third_map[]{1,2,0,3};
 auto convert=[&](unsigned offset,const unsigned*map){auto x=m.r8(token+offset);return x<=3?map[x]:1u;};
 m.w32(i.cx+0x64,convert(0x12,direct_map));m.w32(i.cx+0x68,convert(0x13,direct_map));
 m.w32(i.cx+0x50,4);m.w32(i.cx+0x48,convert(0x1e,third_map));
 constexpr unsigned from[]{0x1c,0x1d,0x21,0x24,0x27,0x2a,0x2d,0x30,0x33,0x36};
 constexpr unsigned to[]{0x3c,0x38,0x70,0x6c,0x44,0x4c,0x54,0x58,0x5c,0x60};
 for(unsigned k=0;k<10;++k)m.w32(i.cx+to[k],m.r8(token+from[k]));
 m.w32(i.cx+0x40,m.r32(token+0x18));return release(m,token);
}
std::uint32_t fun_00725d70(Memory&m,const Inputs&i){
 const auto owner=i.dx,table=m.r32(owner+4),token=m.r32(table+4);
 need(m.r32(0x79a224)==0x724f50&&m.r32(owner+16)>0,"423 original iterator predicate positive");
 need(token&&m.r32(token+8)==i.arg[0],"423 first positive key hit");
 m.w32(i.cx+4,0);m.w32(i.cx,0x793ccc);m.w32(i.cx,0x79a10c);
 m.w32(token+4,m.r32(token+4)+1);m.w32(i.cx+4,token);return i.cx;
}
}
