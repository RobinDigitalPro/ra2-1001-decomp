#include "recovery_b420.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::iterator420 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
std::uint32_t fun_0071b2f0(Memory&m,const Inputs&i){
 const auto owner=i.cx+24,out=i.arg[0];
 need(m.r32(0x799ee8)==0x71b670&&m.r32(owner+16)>0,"420 actual iterator predicate and positive count");
 // Accepted71b670 index<count and71bfb0 resource token key, adapted to
 // numeric multi-span memory. The selected first element must be a hit.
 const auto array=m.r32(owner+4),resource=m.r32(array+4),token=m.r32(resource+12);
 need(token&&m.r32(token+8)==i.arg[1],"420 bounded first-record positive hit");
 m.w32(out+4,owner);m.w32(out+8,0);m.w32(out,0x799ee4);return out;
}
std::uint32_t fun_00755830(Memory&m,const Inputs&i){
 std::array<std::uint8_t,48>private_bytes{};leaf::Memory span(private_bytes.data(),0xf0000000,private_bytes.size());Memory extended=m;extended.add(span);
 Inputs child{};child.cx=m.r32(0xb10214);child.arg[0]=0xf0000010;child.arg[1]=i.dx;
 fun_0071b2f0(extended,child);
 const auto owner=extended.r32(0xf0000014),array=m.r32(owner+4),resource=m.r32(array+4),token=m.r32(resource+12);
 // Original630a80 construction, then630ad0 nonnull replacement of its
 // explicitly null child: increment shared reference count, publish child.
 m.w32(i.cx+4,0);m.w32(i.cx,0x793ccc);m.w32(i.cx,0x78f52c);
 need(token!=0,"420 positive referenced token");m.w32(token+4,m.r32(token+4)+1);m.w32(i.cx+4,token);return i.cx;
}
}
