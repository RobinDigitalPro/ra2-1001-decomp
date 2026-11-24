#include "recovered/recovery_b1213.hpp"
#include <stdexcept>
namespace ra2::recovered::b1213{namespace{
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}using U=unsigned;
U atomic(Memory&m,U p,bool add){using Op=long(__attribute__((stdcall))*)(volatile long*);need(m.r32(p)==0x78963cu,"1213 true original ConnectionPoint vtable");const U g=m.r32(0xa56744u);m.w32(0xa56744u,add?g+1u:g-1u);const auto f=reinterpret_cast<Op>(std::uintptr_t(m.r32(add?0x7851bcu:0x7851c0u)));need(f!=nullptr,"1213 genuine original unchanged atomic import");const U value=U(f(reinterpret_cast<volatile long*>(std::uintptr_t(p+0x14u))));need(value==(add?2u:1u),"1213 bounded original reference1to2to1 full API result");return value;}
U clear(Memory&m,U v,Heap&h){need(m.r8(v+13u)==1u&&m.r32(v+8u)==10u,"1213 authentic owned capacity10 clear");const U data=m.r32(v+4u);m.w32(v+16u,0u);const U result=h.release(data);need(result!=0u,"1213 actual full HeapFree BOOL");m.w32(v+4u,0u);m.w8(v+13u,0u);m.w32(v+8u,0u);return result;}
}
unsigned run(unsigned r,Memory&m,const Inputs&i,Heap&h){need(r==0x92c00u,"1213 exact copy constructor");const U self=i.cx,source=i.arg[0],v=self+12u;need(v!=source&&m.r32(source)==0x7896a0u&&m.r32(source+8u)==10u&&m.r32(source+16u)==1u&&m.r32(source+20u)==10u,"1213 authentic source vector cap10/count1/grow10 nonalias");m.w32(self+4u,0u);m.w32(self+8u,0u);m.w32(v+4u,0u);m.w32(v+8u,0u);m.w8(v+12u,1u);m.w8(v+13u,0u);m.w32(v,0x789660u);
 // Real493310 sees zero pointer/capacity/owned flag and performs no free.
 m.w32(v+8u,10u);const U data=h.allocate(40u);need(data!=0u,"1213 successful exact original40to48 allocation");m.w32(v+4u,data);m.w8(v+13u,1u);const U src=m.r32(source+4u);for(U j=0;j<10u;++j)h.w32(data+4u*j,h.r32(src+4u*j));m.w32(v+16u,1u);m.w32(v+20u,10u);m.w32(v,0x7896a0u);m.w32(self,0x789680u);atomic(m,h.r32(data),true);return self;}
unsigned cleanup_destination(Memory&m,unsigned self,Heap&h){need(m.r32(self)==0x789680u&&m.r32(self+12u)==0x7896a0u&&m.r32(self+28u)==1u,"1213 authentic enumerator destructor positive count1");atomic(m,h.r32(m.r32(self+16u)),false);clear(m,self+12u,h);m.w32(self+12u,0x789660u);return 0u;}
unsigned cleanup_source(Memory&m,unsigned source,Heap&h){need(m.r32(source)==0x7896a0u,"1213 actual source492F00 input");return clear(m,source,h);}
}
