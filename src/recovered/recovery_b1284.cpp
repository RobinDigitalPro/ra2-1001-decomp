#include "recovery_b1284.hpp"
#include "preallocated_b66.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1284 {
std::uint32_t fun_0054e530(Memory&m,const Inputs&i){
 auto need=[](bool q,const char*s){if(!q)throw std::domain_error(s);};
 const auto coordinate=i.arg[0],old=i.arg[2],table=m.r32(0x81a958u);
 need((i.arg[4]&255u)==1u&&i.arg[1]==0xffffu&&i.arg[3]==0xffffffffu,"1284 recursive tile replacement inputs");
 need(m.r32(coordinate)==0x00140001u,"1284 exact borrowed map coordinate");
 const auto cell=m.r32(table+4u*10241u);
 need(cell!=0u&&cell!=0xa57610u&&m.r32(cell)==0x788b04u,"1284 genuine Cell read set");
 need(old>=0x4300u&&old<0x4340u&&m.r32(cell+0x38u)==old,"1284 bounded changed tile");
 need(m.r32(cell+0x24u)==0x00140001u&&m.r32(cell+0x44u)==0xffffffffu&&m.r8(cell+0x11bu)==0u&&m.r32(cell+0xe4u)==0u,"1284 flat empty-actor cache prestate");
 need(m.r32(0x81a910u)==20u&&m.r32(0x81a914u)==20u&&m.r32(0x81a918u)==0u&&m.r32(0x81a91cu)==0u&&m.r32(0x81a920u)==20u&&m.r32(0x81a924u)==20u&&m.r32(0x81a888u)==1681u,"1284 accepted map membership/index domain");
 need(m.r8(m.r32(0x821b88u)+0x584u)==0u&&m.r32(0x8391d8u)==0x3f800000u&&m.r32(0x787518u)==0x47ae147bu&&m.r32(0x78751cu)==0x3f847ae1u,"1284 warm Clear speed and Rules domain");
 // Original72140 calls54CF40 twice: signed index1+41*20=821 is in range.
 const auto cache4=m.r32(0x81a884u)+4u*821u,cache10=m.r32(0x81a88cu)+10u*821u;
 m.w32(cell+0x38u,0xffffu);(void)m.r32(0xa28920u);
 m.w32(cell+0xecu,0u);m.w8(cell+0x11cu,0u);
 // Exact reached478B40 numeric operations from accepted1211, shared x87 state.
 i.fp.load32(m.r32(0x8391d8u));i.fp.compare_pop64(0x3f847ae147ae147bull);
 need((i.fp.status()&0x4100u)==0u,"1284 Clear speed is above .01");
 m.w32(cell+0x4cu,0u);m.w8(cache4+1u,0u);m.w8(cache4,0u);m.w8(cache10+8u,0u);
 global_b26::Inputs append;append.cx=0x81a820u;append.arg[0]=cell+0x24u;
 (void)global_b26::fun_00628bf0(m,append);
 for(unsigned k=0;k<8u;++k){
  const auto x=std::uint16_t(1u+m.r16(0x839da0u+4u*k)),y=std::uint16_t(20u+m.r16(0x839da2u+4u*k));
  const auto xy=unsigned(x)|(unsigned(y)<<16u);
  const int index=int(static_cast<short>(x))+512*int(static_cast<short>(y));
  need(index>=0&&index<0x40000,"1284 mapped neighbor index");
  const auto neighbor=m.r32(table+4u*unsigned(index));
  need(neighbor!=0u&&m.r32(neighbor+0x38u)!=old,"1284 nonmatching mapped neighbor");
  i.arg[0]=xy;i.arg[4]=xy;i.arg[1]=7u-k;
 }
 return 0u;
}
}
