#include "recovery_b1421.hpp"
#include "recovered/rng_b70.hpp"
#include "recovered/numeric_b105.hpp"
#include "recovered/global_b58_c.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1421 {
// RVA EBF50: mode zero, enabled constructor-seeded RNG, and a valid produced
// map cell. The other modes and map-repair fallback are outside this contract.
std::uint32_t fun_004ebf50(Memory& original,const Inputs& in){
 if(in.arg[1]!=0u)throw std::domain_error("B1421 requires mode zero");
 const auto self=in.cx,out=in.arg[0];
 auto radius_limit=global_b26::s32(original.r32(self+0x53c8u));
 if(radius_limit<0x300)radius_limit=0x300;
 if(radius_limit>=0x800)radius_limit=0x800;
 // Separate from B105's 7D000000 private frame. Every exposed local below is
// produced before use; zero-filled storage is not a contract for old stack.
 std::array<std::uint8_t,0x100> bytes{};
 constexpr std::uint32_t base=0x7da00000u,xyz=base+0x34u,cell=base+0x0cu;
 leaf::Memory local(bytes.data(),base,std::uint32_t(bytes.size()));Memory m=original;m.add(local);
 Inputs call=in;call.cx=m.r32(0xa255c0u)+0x218u;call.arg[0]=0u;call.arg[1]=std::uint32_t(radius_limit);
 const auto radius=rng_b70::fun_0062fe40(m,call);
 call=in;call.cx=xyz;call.dx=self+0x53bcu;call.arg[0]=radius;call.arg[1]=1u;
 const auto result=numeric_b105::fun_00491530(m,call);in.fp=call.fp;
 const auto x=m.r32(result),y=m.r32(result+4u),z=m.r32(result+8u);
 if(x==m.r32(0xa28b90u)&&y==m.r32(0xa28b94u)&&z==m.r32(0xa28b98u)){
  m.w16(cell,std::uint16_t(global_b26::s32(m.r32(self+0x53bcu))/256));
  m.w16(cell+2u,std::uint16_t(global_b26::s32(m.r32(self+0x53c0u))/256));
 }else{
  // Actual 42AD30 writes the low WORD of each divided coordinate and RET8.
  m.w16(cell,std::uint16_t(global_b26::s32(x)/256));
  m.w16(cell+2u,std::uint16_t(global_b26::s32(y)/256));
 }
 global_b26::Inputs map=in;map.cx=0x81a820u;map.arg[0]=cell;map.arg[1]=1u;
 if((global_b26::fun_00557450(m,map)&255u)==0u)
  throw std::domain_error("B1421 excludes map-repair fallback");
 m.w32(out,m.r32(cell));return out;
}
}
