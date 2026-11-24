#include "recovery_b532.hpp"
#include "allocation_wrappers.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b532 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U allocate(U n,U flag,void*c){need(flag==1,"B532 actual new wrapper flag");return static_cast<Heap*>(c)->allocate(n);}
U run(Memory&m,const Inputs&i,Heap&h,U off,bool grow){
 const U owner=m.r32(m.r32(0xaa863c));
 need(m.r32(0xaa8648)==1,"B532 one owner");
 need(m.r32(owner+off+4)==0&&m.r32(owner+off+8)==0&&m.r32(owner+off+12)==0,"B532 fresh owned queues");
 const U cells=(m.r32(0x81a914)+4)*m.r32(0x81a910)*2;
 need(cells==36,"B532 bounded dimensions");
 const AllocationWrapperOperations op{allocate,nullptr,&h};
 m.w32(owner+off,0);
 const U records=fun_0076d957(cells*8,op);need(records!=0,"B532 records allocated");
 m.w32(owner+off+12,records);
 const U mask=fun_0076d957(cells,op);m.w32(owner+off+8,mask);
 const U queue=fun_0076d957(20,op);need(queue!=0,"B532 queue allocated");
 h.w32(queue+12,0);h.w32(queue+16,0xffffffff);h.w32(queue,0);h.w32(queue+4,cells);
 const U storage=fun_0076d957(cells*4+4,op);h.w32(queue+8,storage);
 for(U k=0;k<=cells;++k)h.w32(storage+4*k,0);
 m.w32(owner+off+4,queue);
 // The live owned allocations are real OS memory. Expose that exact region to
 // the already accepted resource insertion, retaining the original identities.
 const U region=records-0xed0;
 leaf::Memory backing(reinterpret_cast<std::uint8_t*>(std::uintptr_t(region)),region,0x8000);
 Memory child_memory=m;child_memory.add(backing);Inputs child=i;child.cx=owner;
 if(grow)recovery_b459::fun_006df940(child_memory,child);
 else recovery_b459::fun_006dee50(child_memory,child);
 i.fp=child.fp;
 return m.r32(0xaa8648);
}
}
std::uint32_t fun_006de7e0(Memory&m,const Inputs&i,Heap&h){return run(m,i,h,0xf0,false);}
std::uint32_t fun_006df2a0(Memory&m,const Inputs&i,Heap&h){return run(m,i,h,0x10c,true);}
}
