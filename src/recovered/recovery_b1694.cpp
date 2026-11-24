#include "recovered/recovery_b1694.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b1694 {
namespace {
namespace math=numeric_b88::detail;
namespace fp=ra2::platform::x87;
using Point=std::array<U,3>;
// Immutable incoming numeric-domain INPUT contract; no target/poststate data.
constexpr std::array<std::uint8_t,108> immutable_incoming_fp_input_contract108{{
 0x7fu,0x03u,0xffu,0xffu,0x00u,0x00u,0xffu,0xffu,0xffu,0xffu,0xffu,0xffu,
 0x6eu,0x6eu,0x49u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,
 0x00u,0x00u,0xffu,0xffu,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x80u,
 0xffu,0x3fu,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,
 0xacu,0x79u,0xcfu,0xd1u,0xf7u,0x17u,0x72u,0xb1u,0xfeu,0x3fu,0x99u,0xf7u,
 0xcfu,0xfbu,0x84u,0x9au,0x20u,0x9au,0xfdu,0x3fu,0x35u,0xc2u,0x68u,0x21u,
 0xa2u,0xdau,0x0fu,0xc9u,0x00u,0x40u,0xbcu,0xf0u,0x17u,0x5cu,0x29u,0x3bu,
 0xaau,0xb8u,0xffu,0x3fu,0xfeu,0x8au,0x1bu,0xcdu,0x4bu,0x78u,0x9au,0xd4u,
 0x00u,0x40u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x80u,0xffu,0x3fu,
}};
void need(bool value){if(!value)throw std::domain_error("FCFF0 finite positive speed/direction domain");}
Point point(Memory&m,U address){return {m.r32(address),m.r32(address+4u),m.r32(address+8u)};}
Point owner_copy(Memory&m,U owner){
 // Closed actual798C88+48=>5CD4D0 algorithm: three real public DWORD loads.
 need(m.r32(owner)==0x798c88u&&m.r32(0x798cd0u)==0x5cd4d0u);
 return point(m,owner+0x88u);
}
void compare64(fp::State&f,std::uint64_t value){
 // Root4FD28F FCOMm64, without popping. Same explicit-State backend pattern.
 f.require_masked();fp::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfcoml %[value]\n\tfnsave %[guest]\n\tfrstor %[host]"
  :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[value]"m"(value)
  :"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
U direction_angle(Memory&m,fp::State&f,const Point&owner,const Point&target){
 // Exact Root FILD/FISUB/FSTPdouble order and actual4BA270 numeric algorithm.
 f.load_integer32(target[0]);math::sub::subtract_integer32(f,owner[0]);
 const auto horizontal=f.pop64();
 f.load_integer32(owner[1]);math::sub::subtract_integer32(f,target[1]);
 const auto vertical=f.pop64();
 math::angle(m,f,vertical,horizontal);
 f.subtract64(floating_b61::read64(m,0x786630u));
 f.multiply64(floating_b61::read64(m,0x786628u));
 return math::integer(m,f); // Actual FTOL/guestCW algorithm, not an oracle value.
}
void matching_direction(Memory&m,U descriptor,U argument_low){
 // Selected4B86A0 reads these WORDs before matching. The dead first private
 // upper16 are neither created nor read/copied by this finite adaptation.
 const auto current=m.r16(descriptor);
 need(current==(argument_low&0xffffu));
}
}

void preflight(Memory&m,const Inputs&i){
 const U self=i.cx,owner=m.r32(self+0xcu);
 need(self&&owner&&std::uint64_t(self)+0x74u<=0x100000000ull&&std::uint64_t(owner)+0x568u<=0x100000000ull);
 need(std::uint64_t(self)+0x74u<=owner||std::uint64_t(owner)+0x568u<=self);
 need(m.r32(self)==0x78e2b4u&&m.r32(self+4u)==0x78e1ecu);
 need(m.r32(self+8u)==owner&&m.r32(owner+0x564u)==self+4u);
 need(m.r32(0x78e1fcu)==0x4fbd80u&&m.r32(0x78e24cu)==0x4fdd80u);
 need(m.r8(self+0x10u)==1u&&m.r8(self+0x11u)==1u);
 need(m.r32(owner)==0x798c88u&&m.r32(0x798cd0u)==0x5cd4d0u);
 need(point(m,owner+0x88u)==Point{1024u,2049u,64u});
 const auto first=point(m,self+0x18u),second=point(m,self+0x24u),sentinel=point(m,0xa28cc0u);
 need(first==Point{768u,2049u,64u}&&second==Point{1024u,2048u,64u});
 need(first!=sentinel&&second!=sentinel); // Actual two-triple predicate is true.
 need(m.r8(self+0x70u)==0u&&m.r32(self+0x30u)==0u&&m.r16(self+0x44u)==0u);
 need(m.r32(owner+0x4d0u)==0xffffffffu&&m.r16(owner+0x2e0u)==0u);
 need(floating_b61::read64(m,self+0x48u)==0u);
 need(floating_b61::read64(m,self+0x50u)==0x3ff0000000000000ull&&floating_b61::read64(m,self+0x58u)==0x3ff0000000000000ull);
 need(floating_b61::read64(m,0x785708u)==0x3ff0000000000000ull&&floating_b61::read64(m,0x786610u)==0u);
 need(m.r32(0x7c3a04u)==0x0e7fu);
 fp::Image expected;expected.bytes=immutable_incoming_fp_input_contract108;
 need(fp::same_numeric(i.fp.image,expected)); // Frozen incoming INPUT only, all80 retained.
}

U run(Memory&m,const Inputs&i,const SourceFrameContext&frame){
 static_assert(sizeof(void*)==4,"FCFF0 Source frame is actual Win32 stack memory");
 preflight(m,i);
 need(frame.entry_esp>0x80u&&!(frame.entry_esp&3u));
 need(frame.frame_base==((frame.entry_esp-4u)&~7u)-0x38u);
 need(frame.angle_argument==frame.frame_base+0x1cu&&!(frame.angle_argument&3u));
 const auto caller=i.arg;const U self=i.cx,owner=m.r32(self+0xcu);
 auto&f=i.fp;
 // Actual4FBD80 positive two-triple result, then first owner getter/BF7D0.
 const auto destination=point(m,self+0x24u),first_owner=owner_copy(m,owner);
 (void)(first_owner[0]==destination[0]&&first_owner[1]==destination[1]);
 const U first_angle=direction_angle(m,f,first_owner,destination);
 need(first_angle==0u);matching_direction(m,self+0x30u,first_angle);
 // NormalFDD80=>53B410 reads actual self10; its full pointer-residue result.
 const U predicate=((self+4u)&0xffffff00u)|m.r8(self+0x10u);need((predicate&255u)!=0u);
 // Exact selectedB8850 count0 algorithm: defined full current DWORD to localout.
 need(static_cast<std::int16_t>(m.r16(self+0x44u))==0);
 const U current_direction=m.r32(self+0x30u);
 const auto delta=static_cast<std::int16_t>(std::uint16_t(current_direction)-std::uint16_t(first_angle));
 const std::int32_t magnitude=delta<0?-std::int32_t(delta):std::int32_t(delta);need(magnitude<=0x2000);
 const auto distance_owner=owner_copy(m,owner),first=point(m,self+0x18u);
 const U dx=distance_owner[0]-first[0],dy=distance_owner[1]-first[1],dz=distance_owner[2]-first[2];
 // Root order is dy,z,dx. Do not substitute a different sqrt/FP recipe.
 f.load_integer32(dy);f.load_integer32(dz);f.load_integer32(dx);
 math::reg<0xd9c0>(f);math::reg<0xd8c9>(f);math::reg<0xd9c2>(f);math::reg<0xd8cb>(f);math::reg<0xdec1>(f);
 math::reg<0xd9c3>(f);math::reg<0xd8cc>(f);math::reg<0xdec1>(f);
 const auto squared=f.pop64();f.pop_st0();f.pop_st0();f.pop_st0();
 math::root(m,f,squared);const U distance=math::integer(m,f);need(distance==256u);
 m.w32(self+0x48u,0u);m.w32(self+0x4cu,0x3ff00000u); // Useful desired speed0=>1.
 f.load64(floating_b61::read64(m,self+0x48u));f.compare_pop64(floating_b61::read64(m,0x786610u));need(!(f.status()&0x4100u));
 m.w32(self+0x58u,0u);m.w32(self+0x5cu,0x3ff00000u);
 need(m.r32(owner+0x4d0u)==0xffffffffu); // Actual branch excludes Rules factor.
 f.load64(floating_b61::read64(m,self+0x58u));f.multiply64(floating_b61::read64(m,self+0x48u));
 f.load64(floating_b61::read64(m,0x785708u));f.compare_pop_st1();need(!(f.status()&0x100u));
 compare64(f,floating_b61::read64(m,self+0x50u));need((f.status()&0x4100u)!=0u);
 f.compare_pop64(floating_b61::read64(m,self+0x50u));need(!(f.status()&0x100u));
 f.load64(floating_b61::read64(m,self+0x48u));f.compare_pop64(floating_b61::read64(m,0x786610u));need(!(f.status()&0x4100u));
 need(m.r8(self+0x70u)==0u&&m.r32(owner+0x4d0u)==0xffffffffu);
 const auto final_owner=owner_copy(m,owner);
 const U last_angle=direction_angle(m,f,final_owner,destination);need(last_angle==0u);
 // Root4FD380 defines upper16 with actual ownerX;4FD3B5 writes FTOL low16.
 const U final_word=(final_owner[0]&0xffff0000u)|(last_angle&0xffffu);
 auto*const argument=reinterpret_cast<volatile U*>(std::uintptr_t(frame.angle_argument));
 *argument=final_word; // Real own-Source K, exact fully-defined4FD3C9 publication.
 const U actual_argument=*argument;matching_direction(m,owner+0x2e0u,actual_argument);
 // Actual B58 matching MOVAX/current then XORAL0; bridge never masks this return.
 U eax=floating_b61::with_ax(frame.angle_argument,m.r16(owner+0x2e0u));
 eax=floating_b61::with_al(eax,0u);
 need(i.arg==caller);return eax;
}
}
