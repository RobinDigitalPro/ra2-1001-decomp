#include "recovery_b1171.hpp"
#include <stdexcept>
namespace ra2::recovered::b1171 {
unsigned run(unsigned root,Memory&m,const Inputs&,Heap&h,State&){
 if(root!=0x20fa20u||m.r32(0xa5e230u)!=0x7931dcu||m.r32(0xa5e238u)!=10u||m.r32(0xa5e240u)!=0u||m.r8(0xa5e23du)!=1u||m.r32(0xa5e198u)!=0u||m.r32(0xa28870u)!=0u)throw std::domain_error("1171 exact allocated-capacity cleanup domain");
 const unsigned old=m.r32(0xa5e234u);if(!old)throw std::domain_error("1171 positive owner required");
 m.w32(0xa5e240u,0u);const unsigned eax=h.release(old);if(!eax)throw std::domain_error("1171 actual free failed");m.w32(0xa5e234u,0u);
 m.w8(0xa5e23du,0u);m.w32(0xa5e238u,0u);return eax;
}
}
