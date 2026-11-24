#include "recovery_b1178.hpp"
#include <stdexcept>
namespace ra2::recovered::b1178{
static void need(bool x){if(!x)throw std::domain_error("1178 exact constructor-produced registry unpublication");}
static void four(Memory&m,unsigned self,const unsigned*v){for(unsigned k=0;k<4u;++k)m.w32(self+4u*k,v[k]);}
// Actual +10 Find leaves compare pointer DWORDs; removal shifts without clearing the stale tail.
static void remove(Memory&m,Heap&h,unsigned g,unsigned value){const auto n=m.r32(g+16u),p=m.r32(g+4u);unsigned at=0u;for(;at<n&&h.r32(p+4u*at)!=value;++at){}if(at==n)return;m.w32(g+16u,n-1u);for(unsigned j=at+1u;j<n;++j)h.w32(p+4u*(j-1u),h.r32(p+4u*j));}
static void list(Memory&m,unsigned p){need(m.r32(p)==0u&&m.r32(p+4u)==0u&&m.r32(p+8u)==0u&&m.r32(p+12u)==0x8192ecu);m.w32(p+8u,0u);m.w32(p+12u,0u);}
//6E1E50 mandatory flag14 bit1 route, including actual derived +28 notification targets.
//The reached5CC260/6D9A60 callbacks compare genuine constructor-null links. No callback substitute.
static void notify(Memory&m,Heap&h,unsigned self,unsigned root){need((m.r8(self+20u)&2u)!=0u&&m.r32(0x81b9c0u)==0u&&m.r32(0x81b9c4u)==0u&&m.r32(0x821cacu)==0u&&m.r32(0xaa8dc0u)==0u);const auto p=m.r32(0xaa886cu),n=m.r32(0xaa8878u);need(n==2u);for(unsigned j=0;j<n;++j){const auto q=h.r32(p+4u*j);need(m.r32(q)==(root==0x301a00u?0x7992b8u:0x798274u)&&m.r32(q+48u)==0u&&m.r32(q+52u)==0u);if(root==0x2d82c0u)need(m.r32(q+176u)==0u);}
 //436590 calls actual40B840/40BAA0 Find on two true initializer-empty registries.
 need(m.r32(0x81a620u)==0x7857bcu&&m.r32(0x81a630u)==0u&&m.r32(0x81a638u)==0x78579cu&&m.r32(0x81a648u)==0u);
 //52FAE0 count at A56074 is genuine52F7B0/530140 initializer zero.6EC7B0 nullglobal;
 //53C2F0 calls actual kind getter41/36 and returns because neither is44.
 need(m.r32(0xa56074u)==0u&&m.r32(0xa56064u)==0x790394u);
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&){need(root==0x301a00u||root==0x2d82c0u);const auto self=i.cx;const unsigned derived301[]{0x7992b8u,0x79929cu,0x799294u,0x79928cu},derived2d[]{0x798274u,0x798248u,0x79826cu,0x798264u};four(m,self,root==0x301a00u?derived301:derived2d);notify(m,h,self,root);remove(m,h,root==0x301a00u?0x821d10u:0xa28590u,self);need(m.r8(0xa285a8u)==0u);
 if(root==0x301a00u){need(m.r32(self+240u)==0u);list(m,self+252u);list(m,self+272u);remove(m,h,0xaa87b8u,self);m.w32(self+236u,0u);}
 else{need(m.r32(self+16u)==0xffffffffu&&m.r32(0xaa7a64u)==2u&&m.r8(0xaa7a6cu)==0u);const auto p=m.r32(0xaa7a60u);need(h.r32(p)==0xffffffffu&&h.r32(p+8u)==0xffffffffu&&h.r32(p+4u)==self);
  //76D686 count2,width8 ->76D7DA. Equal comparator41BA10 returns0, so max=row0;
  //76D828 byte-swaps row0,row1.508D30 mid1 then finds original row0 (this victim).
  for(unsigned k=0;k<8u;++k){const auto x=h.r8(p+k);h.w8(p+k,h.r8(p+8u+k));h.w8(p+8u+k,x);}m.w32(0xaa7a70u,0u);m.w8(0xaa7a6cu,1u);need(h.r32(p+12u)==self);m.w32(0xaa7a64u,1u);h.w32(p+8u,0u);h.w32(p+12u,0u);m.w32(0xaa7a70u,0u);
 }
 //5CABC0 actual Object base cleanup, then40FF90 final four-vptr publication.
 const unsigned middle[]{0x792458u,0x79243cu,0x792434u,0x79242cu},base[]{0x785dd8u,0x785dbcu,0x785db4u,0x785dacu};four(m,self,middle);for(auto g:{0xaa87e0u,0xa27fb8u,0xaa8868u,0xaa87b8u,0xaa8760u})remove(m,h,g,self);m.w32(self+48u,0u);m.w8(self+125u,0u);list(m,self+60u);list(m,self+80u);need(m.r32(self+148u)==0u);four(m,self,base);return self+80u;
}
unsigned cleanup(unsigned root,Memory&m,Heap&h){unsigned result=0u;for(auto g:{0xa27fb8u,0xaa8868u,0xaa87b8u,0xaa8760u,root==0x301a00u?0x821d10u:0xa28590u}){const auto p=m.r32(g+4u);need(p&&m.r8(g+13u)==1u);m.w32(g+16u,0u);result=h.release(p);need(result!=0u);m.w32(g+4u,0u);m.w8(g+13u,0u);m.w32(g+8u,0u);}if(root==0x2d82c0u){result=h.release(m.r32(0xaa7a60u));need(result!=0u);for(unsigned k=0;k<20u;++k)m.w8(0xaa7a60u+k,0u);}return result;}
}
