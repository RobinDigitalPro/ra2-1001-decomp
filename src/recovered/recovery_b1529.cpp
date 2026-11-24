#include "recovered/recovery_b1529.hpp"
#include "platform/x87_extended_b40.hpp"
#include <stdexcept>
namespace ra2::recovered::b1529 {
using U=std::uint32_t;
U project(Memory&m,const Inputs&i,U point){
 const U z=m.r32(point+8u);i.fp.load_integer32(z);i.fp.multiply64(floating_b61::read64(m,0xaa5f90u));ra2::platform::x87_extended::add_integer32(i.fp,z>=728u?1u:0u);i.fp.add64(floating_b61::read64(m,0x785728u));
 const U cw=m.r32(0x7c3a04u);if(i.fp.control()!=cw)i.fp.load_control(std::uint16_t(cw));const U height=U(i.fp.pop_integer64());
 const auto x=static_cast<std::int32_t>(m.r32(point)),y=static_cast<std::int32_t>(m.r32(point+4u));return U((15*x+15*y)/256)-height;
}
U fun_006bf790(Memory&outer,const Inputs&i,Heap&h){
 const U self=i.cx,target=i.arg[0];if(outer.r32(self)!=0x78612cu||outer.r32(target)!=0x78612cu||(outer.r8(target+0x14u)&2u)==0u||outer.r32(0xa9e038u)!=0u||outer.r32(0xa9e030u)!=1u)throw std::domain_error("1529 reviewed exactactor/nonfullregistry domain");
 const U obj=h.allocate(184u);if(!obj)throw std::domain_error("1529 positive allocation required");
 // Literal95B62CC50: onlyarg0 selector1 andECX destination are inputs.
 h.w32(obj+0x10u,0u);h.w8(obj,0u);h.w8(obj+1u,1u);h.w32(obj+4u,0u);h.w32(obj+8u,1u);h.w32(obj+0x14u,0u);
 for(U off:{0x18u,0x19u,0x1au})h.w8(obj+off,0u);
 for(U off:{0x1cu,0x20u,0x24u,0x28u,0x2cu,0x30u,0x38u,0x40u,0x34u,0x3cu,0x44u,0x48u,0x6cu})h.w32(obj+off,0u);
 for(U off:{0xb0u,0xb1u,0xb2u})h.w8(obj+off,0u);
 outer.w32(0xa9e038u,1u);outer.w32(outer.r32(0xa9e02cu),obj);
 i.fp.load_integer32(10u);const auto ten=i.fp.pop64();h.w32(obj+0x10u,U(ten));h.w32(obj+0x14u,U(ten>>32u));
 std::array<std::uint8_t,64>local{};leaf::Memory stack(local.data(),0x7c000000u,64u);Memory m=outer;m.add(stack);
 Inputs child=i;child.arg[0]=0x7c000000u;child.arg[1]=0u;const auto got=b1319::fun_006b6e80(m,child);if(got!=child.arg[0])throw std::domain_error("1529 genuinecoordinate output identity");i.fp=child.fp;
 for(U k=0;k<3u;++k)m.w32(0x7c000010u+4u*k,m.r32(self+0x88u+4u*k));
 if(m.r32(0x7c000004u)==m.r32(self+0x8cu))throw std::domain_error("1529 bothactualprojections mustexecute");
 const U projected_start=project(m,i,0x7c000000u);const U projected_base=project(m,i,0x7c000010u);const U delta=projected_start-projected_base;
 for(U k=0;k<3u;++k){h.w32(obj+0x1cu+4u*k,m.r32(0x7c000000u+4u*k));h.w32(obj+0x28u+4u*k,m.r32(target+0x88u+4u*k));}
 h.w32(obj+0x34u,15u);h.w32(obj+0x38u,0u);h.w32(obj+0x3cu,0x40440000u);
 const U rgb=m.r32(0x821b88u)+(i.arg[1]==1u?0x14aeu:0x1478u);const U rg=m.r16(rgb);h.w8(obj+0x18u,std::uint8_t(rg));h.w8(obj+0x19u,std::uint8_t(rg>>8u));h.w8(obj+0x1au,m.r8(rgb+2u));h.w32(obj+4u,delta);return delta;
}
}
