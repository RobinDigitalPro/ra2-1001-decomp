#include "recovered/recovery_b910.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <array>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b910 {
namespace {
using U=std::uint32_t;
constexpr U root_size=0x400u;
constexpr std::array<const char*,6> names={"OldCycle","History","Status","Territory","Game","Evacuate"};
constexpr std::array<U,6> name_offsets={0x04u,0x98u,0x12cu,0x1c0u,0x254u,0x2e8u};
constexpr U u8(const char*s,U at){return U(static_cast<unsigned char>(s[at]));}
U length(const char*s){U n=0;while(s[n])++n;return n;}
U allocate(U n,U flag,void*p){if(flag!=1u)throw std::domain_error("B910 allocation flag");return static_cast<Heap*>(p)->allocate(n);}
U deallocate(U p,void*h){return static_cast<Heap*>(h)->release(p);}
U alloc(Heap&h,U n){ra2::recovered::AllocationWrapperOperations op{allocate,deallocate,&h};const U p=ra2::recovered::fun_0076d957(n,op);if(!p)throw std::domain_error("B910 excludes allocation failure");return p;}
void release(Heap&h,U p){ra2::recovered::AllocationWrapperOperations op{allocate,deallocate,&h};if(!p||ra2::recovered::fun_0076d67b(p,op)!=1u)throw std::domain_error("B910 requires successful real HeapFree");}
U string_copy(Heap&h,const char*s){const U n=length(s),p=alloc(h,n+1u);for(U i=0;i<n;++i)h.w8(p+i,u8(s,i));h.w8(p+n,0);return p;}
void set8(Memory&m,U a,U x){m.w8(a,x);}
void init_child(Memory&m,U p){
 m.w32(p,0x7874dcu);m.w32(p+4u,0);m.w32(p+8u,0);set8(m,p+0x0cu,1);set8(m,p+0x0du,0);m.w32(p+0x10u,0);m.w32(p+0x14u,0xau);
}
void init_vector(Memory&m,U p){
 m.w32(p+4u,0);m.w32(p+8u,0);set8(m,p+0x0cu,1);set8(m,p+0x0du,0);
 m.w32(p,0x7874fcu);m.w32(p+0x14u,0xau);m.w32(p+0x10u,0);
}
}
U fun_00726080(Memory&m,const Inputs&in,Heap&h,U observed_tick){
 const U self=in.cx;
 if(!self||std::uint64_t(self)+root_size>0x100000000ull)throw std::domain_error("B910 requires nonnull 0x400-byte owner span");
 // The constructor reads caller arg0 before clobbering the caller's stack word.
 m.w32(self,in.arg[0]);

 // Six actual 0x18-byte child constructor results (0x7277F0).
 for(U group=0;group<6u;++group){
  const U base=self+4u+group*0x94u;
  for(U child=0;child<6u;++child)init_child(m,base+4u+child*0x18u);
  // The empty source literal is copied into the group's real heap string.
  m.w32(base,string_copy(h,""));
 }

 // Both original zero-argument vector initializers take their allocation-free
 // branch; later root stores reproduce their explicit vptr/size fields.
 init_vector(m,self+0x37cu);init_vector(m,self+0x394u);m.w32(self+0x37cu,0x7874dcu);m.w32(self+0x394u,0x7874dcu);

 // 0x68FAD0 calls timeGetTime and SHR EAX,4. The value is observed from the
 // genuine API in native differential execution and passed in unchanged here.
 m.w32(self+0x3acu,observed_tick>>4u);
 m.w32(self+0x3b4u,0);set8(m,self+0x3b8u,1);m.w32(self+0x3bcu,0);
 // 0x66A470 zero-argument setup, followed by the root's explicit stores.
 init_vector(m,self+0x3c0u);
 m.w32(self+0x3c0u,0x79450cu);m.w32(self+0x3c0u+0x14u,0xau);m.w32(self+0x3c0u+0x10u,0);
 m.w32(self+0x3d8u,0);
 (void)m.r32(0x819778u); // original 0x406F40 read; EAX is discarded.

 // The stack temporary at ESP+0x14 aliases entry caller arg0 (S+4) after four
 // saves. Each exact original name is copied, assigned, then its temp freed.
 for(U i=0;i<6u;++i){
  const U dst=self+name_offsets[i];
  const U temporary=string_copy(h,names[i]);
  const U old=m.r32(dst);if(old)release(h,old);m.w32(dst,0);
  const U assigned=string_copy(h,names[i]);m.w32(dst,assigned);
  release(h,temporary);
 }
 in.arg[0]=0; // actual 0x759320 temp destruction clears [ESP+0x14] == S+4.
 return self; // original full EAX is ECX/self; RET 4.
}
}
