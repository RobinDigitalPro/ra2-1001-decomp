#include "recovery_b1409.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_004f47b0(Memory&,const Inputs&);
}
namespace ra2::recovered::b1409 {
std::uint32_t fun_006c1b80(Memory& m,const Inputs& i){
 const auto self=i.cx,target=i.arg[0],owner=m.r32(self+0x1b4u);
 if(self==0||target!=self||m.r32(self)!=0x78612cu||m.r32(0x7862e8u)!=0x6cc360u||
    m.r8(self+0x204u)!=0||m.r32(self+0x38u)!=0||m.r32(0xa288b0u)!=1||
    m.r32(m.r32(0xa288a4u))!=self||m.r8(self+0x77u)!=1||
    (i.arg[1]&255u)!=1||m.r32(0xa255c8u)==0||owner==0||m.r32(0xa1e0e4u)!=owner)
  throw std::domain_error("B1409 same selected receiver and current owner contract");
 // Actual6CC360 reads204, so the original takes6C1C1A. EDI captured
 // the target before these two byte stores into the physical outer frame.
 i.arg[0]&=0xffffff00u;i.arg[1]&=0xffffff00u;
 global_b26::Inputs context{};context.cx=owner;
 if(global_b26::fun_004f47b0(m,context)!=1)
  throw std::domain_error("B1409 original current-owner predicate");
 return 4u;
}
}
