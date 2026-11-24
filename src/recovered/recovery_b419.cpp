#include "recovery_b419.hpp"
#include "allocation_wrappers.hpp"
#include <stdexcept>
namespace ra2::recovered::lifecycle419 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned release(unsigned p,void*x){return static_cast<Heap*>(x)->release(p);}
unsigned clear(Memory&m,Heap&h,unsigned at,bool empty_parent=false){
 const auto p=m.r32(at);need(p!=0,"419 owned block required");
 if(empty_parent)need(h.r32(p)==0,"419 nested virtual child must be null");
 AllocationWrapperOperations ops{nullptr,release,&h};auto r=fun_0076d67b(p,ops);need(r==1,"419 actual successful HeapFree required");m.w32(at,0);return r;
}
unsigned vector(Memory&m,Heap&h,unsigned at,unsigned vptr){
 need(m.r8(at+13)!=0,"419 owned vector flag required");m.w32(at,vptr);
 auto r=clear(m,h,at+4);m.w8(at+13,0);m.w32(at+8,0);return r;
}
}
unsigned fun_006294c0(Memory&m,const Inputs&i,Heap&h){
 const auto s=i.cx;need(m.r32(s+0x1218)==0&&m.r32(s+0x121c)==0&&m.r32(s+0x1254)==0,"419 virtual resource pointers must be null");
 clear(m,h,s+0x1238);return clear(m,h,s+0x1270);
}
unsigned fun_00545020(Memory&m,const Inputs&i,Heap&h){
 const auto s=i.cx;m.w32(s,0x79091c);
 // Actual global-vector helper705710, zero elements but positive owned backing.
 need(m.r32(0xab81d8)==0&&m.r8(0xab81d5)!=0,"419 empty owned global vector");
 m.w32(0xab81d8,0);clear(m,h,0xab81cc);m.w8(0xab81d5,0);m.w32(0xab81d0,0);
 // Actual706830 frees its nonnull global allocation.
 clear(m,h,0xab8220);
 // Both reached collection cleanup helpers read this pinned zero count.
 need(m.r32(0xaa8648)==0,"419 excludes collection callback ownership graph");
 clear(m,h,s+0x64);clear(m,h,s+0x14,true);clear(m,h,s+0x6c);
 for(unsigned off:{0x7cu,0x80u,0x84u})clear(m,h,s+off,true);
 vector(m,h,s+0x1158,0x7875e0);vector(m,h,s+0x134,0x790998);vector(m,h,s+0xd0,0x7875e0);
 for(unsigned off:{0xb8u,0xa0u,0x88u}){
  need(m.r32(s+off+4)==0,"419 nested virtual vector must have no buffer");
  m.w32(s+off,0x790a18);m.w8(s+off+13,0);m.w32(s+off+8,0);
 }
 auto r=vector(m,h,s+0x4c,0x7909f8);m.w32(s,0x78dc3c);return r;
}
unsigned fun_00626710(Memory&m,const Inputs&i,Heap&h){
 const auto s=i.cx;m.w32(s,0x7936dc);
 need(m.r32(0x8192f8)==0,"419 excludes registered resource release");
 // The exact405c10 helper clears its two tail fields on this pinned-zero route.
 m.w32(s+0x14c4,0);m.w32(s+0x14c8,0);
 fun_006294c0(m,i,h);
 for(unsigned k=0;k<22;++k)vector(m,h,s+0x146c-24*k,0x791f9c);
 vector(m,h,s+0x1258,0x791f9c);vector(m,h,s+0x1220,0x7875e0);
 return fun_00545020(m,i,h);
}
unsigned fun_0062c070(Memory&m,const Inputs&i,Heap&h){
 need((i.arg[0]&1)==0,"419 excludes destruction of root receiver allocation");
 fun_00626710(m,i,h);return i.cx;
}
}
