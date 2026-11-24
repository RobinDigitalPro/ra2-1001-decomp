#include "recovery_b515.hpp"
#include "allocation_wrappers.hpp"
#include <stdexcept>
namespace ra2::recovery_b515 {
namespace {
unsigned allocate(unsigned n,unsigned flag,void* context){
 if(flag!=1)throw std::domain_error("515 original new wrapper flag");
 return static_cast<Heap*>(context)->allocate(n);
}
}
unsigned fun_0047fce0(Memory&m,const Inputs&i,Heap&h){
 if(i.arg[0]!=1||i.arg[1]!=1||i.arg[2]!=8||i.arg[3]!=0)
  throw std::domain_error("515 positive one-row constructor contract");
 const auto self=i.cx;const ra2::recovered::AllocationWrapperOperations op{allocate,nullptr,&h};
 m.w32(self,0x788db4);for(unsigned k=0;k<4;++k)m.w32(self+4+4*k,i.arg[k]);
 auto alloc=[&](unsigned n){auto p=ra2::recovered::fun_0076d957(n,op);if(!p)throw std::domain_error("515 successful allocation required");return p;};
 const auto rows32=alloc(32);m.w32(self+0x24,rows32);
 const auto rows20=alloc(20);m.w32(self+0x34,rows20);
 const auto ptrs32=alloc(4);m.w32(self+0x30,ptrs32);
 const auto ptrs20=alloc(4);m.w32(self+0x40,ptrs20);
 const auto payload32=alloc(8);h.w32(rows32+0x14,payload32);h.w32(rows32+0x1c,0);
 const auto payload20=alloc(8);h.w32(rows20+8,payload20);h.w32(rows20+0x10,0);
 // Exact positive one-row 0x47fea0 reset: owned buffers survive.
 for(unsigned off:{0x2cu,0x3cu,0x14u,0x18u,0x1cu,0x20u,0x28u,0x38u})m.w32(self+off,0);
 h.w32(rows32,h.r32(rows32)&~1u);h.w32(rows32,h.r32(rows32)&~2u);h.w32(rows32,h.r32(rows32)&~4u);
 for(unsigned off:{4u,8u,12u,16u,24u})h.w32(rows32+off,0);
 h.w32(ptrs32,0);
 h.w32(rows20,h.r32(rows20)&~1u);h.w32(rows20,h.r32(rows20)&~2u);h.w32(rows20,h.r32(rows20)&~4u);
 h.w32(rows20+4,0);h.w32(rows20+12,0);h.w32(ptrs20,0);
 for(unsigned off:{0x44u,0x48u,0x4cu,0x54u})m.w32(self+off,0);
 return self;
}
}
