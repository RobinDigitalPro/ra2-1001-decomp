#include "recovery_b1184.hpp"
#include <stdexcept>
namespace ra2::recovered::b1184{
static void need(bool x){if(!x)throw std::domain_error("1184 actual cold602910 actor unpublication");}
static void four(Memory&m,unsigned p,const unsigned*v){for(unsigned k=0;k<4u;++k)m.w32(p+4u*k,v[k]);}
static void remove(Memory&m,Heap&h,unsigned g,unsigned value){const auto n=m.r32(g+16u),p=m.r32(g+4u);unsigned at=0u;for(;at<n&&h.r32(p+4u*at)!=value;++at){}if(at==n)return;m.w32(g+16u,n-1u);for(unsigned j=at+1u;j<n;++j)h.w32(p+4u*(j-1u),h.r32(p+4u*j));}
static void list(Memory&m,unsigned p){need(m.r32(p)==0u&&m.r32(p+4u)==0u&&m.r32(p+8u)==0u&&m.r32(p+12u)==0x8192ecu);m.w32(p+8u,0u);m.w32(p+12u,0u);}
static void notify(Memory&m,Heap&h,unsigned self){need((m.r8(self+20u)&2u)!=0u&&m.r32(0xa28960u)==0u&&m.r32(0x81b9c0u)==0u&&m.r32(0x81b9c4u)==0u&&m.r32(0x821cacu)==0u&&m.r32(0xaa8dc0u)==0u);const auto p=m.r32(0xaa886cu);need(m.r32(0xaa8878u)==4u);
 //Kind24 follows its actual6E1E97 global-identity test, then mandatoryObjectflagbit1 route.
 //Four real+28 calls reach604880:5CC260 + actual4D5DF0 empty vectorFind + null comparisons.
 for(unsigned j=0;j<4u;++j){const auto q=h.r32(p+4u*j);need(m.r32(q)==0x792f4cu&&m.r32(q+48u)==0u&&m.r32(q+52u)==0u&&m.r32(q+152u)==0u&&m.r32(q+204u)==0u&&m.r32(q+208u)==0u&&m.r32(q+168u)==0x78d2a4u&&m.r32(q+184u)==0u);}
 need(m.r32(0x81a620u)==0x7857bcu&&m.r32(0x81a630u)==0u&&m.r32(0x81a638u)==0x78579cu&&m.r32(0x81a648u)==0u&&m.r32(0xa56064u)==0x790394u&&m.r32(0xa56074u)==0u);
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&){need(root==0x202a60u);const auto self=i.cx;const unsigned derived[]{0x792f4cu,0x792f30u,0x792f28u,0x792f20u};four(m,self,derived);notify(m,h,self);need(m.r8(0xa285a8u)==0u); //5CBD90 cold original global branch, full body pinned.
 need(m.r32(self+184u)==0u); //Actual602910 completed empty child vector; no child callback route.
 m.w32(self+152u,0u);remove(m,h,0xa1a5b0u,self);remove(m,h,0xaa87b8u,self);remove(m,h,0xaa8868u,self);
 need(m.r32(self+172u)==0u&&m.r8(self+181u)==0u);m.w32(self+168u,0x78d2c4u);m.w8(self+181u,0u);m.w32(self+176u,0u);
 const unsigned middle[]{0x792458u,0x79243cu,0x792434u,0x79242cu},base[]{0x785dd8u,0x785dbcu,0x785db4u,0x785dacu};four(m,self,middle);for(auto g:{0xaa87e0u,0xa27fb8u,0xaa8868u,0xaa87b8u,0xaa8760u})remove(m,h,g,self);m.w32(self+48u,0u);m.w8(self+125u,0u);list(m,self+60u);list(m,self+80u);need(m.r32(self+148u)==0u);four(m,self,base);return self+80u;
}
unsigned cleanup(unsigned root,Memory&m,Heap&h){need(root==0x202a60u);unsigned result=0u;for(auto g:{0xa27fb8u,0xaa8868u,0xaa87b8u,0xaa8760u,0xa1a5b0u}){const auto p=m.r32(g+4u);need(p&&m.r8(g+13u)==1u);m.w32(g+16u,0u);result=h.release(p);need(result!=0u);m.w32(g+4u,0u);m.w8(g+13u,0u);m.w32(g+8u,0u);}return result;}
}
