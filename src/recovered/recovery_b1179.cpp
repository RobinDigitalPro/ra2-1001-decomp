#include "recovered/recovery_b1179.hpp"
#include <stdexcept>
namespace ra2::recovered::b1179 {
unsigned run(unsigned root,Memory&m,const Inputs&,Heap&h,State&){
 if(root!=0x12650u)throw std::domain_error("1179 root");
 unsigned owned=0u;
 for(unsigned j=0;j<401u;++j){const unsigned p=0x8221e0u+24u*j,n=m.r32(p+8u);if(m.r32(p)!=0x78579cu||m.r32(p+16u)||m.r32(p+20u)!=10u||m.r8(p+12u)!=1u||(n!=0u&&n!=10u)||bool(m.r32(p+4u))!=bool(n)||m.r8(p+13u)!=unsigned(bool(n)))throw std::domain_error("1179 original cold/reserved vector");owned+=bool(n);}
 if(owned!=1u)throw std::domain_error("1179 exactly one positive owner");
 for(unsigned j=0;j<401u;++j){const unsigned p=0x8221e0u+24u*j,n=m.r32(p+8u),old=m.r32(p+4u);m.w32(p+16u,0u);if(old){if(!h.release(old))throw std::domain_error("1179 clear free");m.w32(p+4u,0u);}m.w8(p+13u,0u);m.w32(p+8u,0u);
  if(n){m.w8(p+12u,0u);const unsigned q=h.allocate(n*4u);m.w8(p+12u,1u);if(!q)throw std::domain_error("1179 reserve");m.w32(p+4u,q);m.w32(p+8u,n);m.w8(p+13u,1u);}
 }
 unsigned eax=0u;for(unsigned k=401u;k>0u;--k){const unsigned p=0x8221e0u+24u*(k-1u);eax=m.r32(p+4u);m.w32(p,0x7857fcu);if(eax){eax=h.release(eax);if(!eax)throw std::domain_error("1179 final free");m.w32(p+4u,0u);}m.w8(p+13u,0u);m.w32(p+8u,0u);}return eax;
}}
