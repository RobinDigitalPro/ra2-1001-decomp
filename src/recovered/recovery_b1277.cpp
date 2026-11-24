#include "recovery_b1277.hpp"
#include <stdexcept>
namespace ra2::recovered::b1277{
static void need(bool x){if(!x)throw std::domain_error("1277 genuine Wave unlimbo finite route");}
static void append(Memory&m,Heap&h,unsigned header,unsigned vt,unsigned actor,Observation&o){
 need(m.r32(header)==vt&&m.r32(vt+8u)==0x40cd40u&&m.r32(header+4u)==0u&&m.r32(header+8u)==0u&&m.r8(header+12u)==1u&&m.r8(header+13u)==0u&&m.r32(header+16u)==0u&&m.r32(header+20u)==10u);
 // Actual40CD40 publicreserve(10,NULL): ordinarymalloc40; no oldowner/copy/free.
 m.w8(header+12u,0u);const unsigned p=h.allocate(40u);++o.allocations;m.w8(header+12u,1u);need(p!=0u);m.w32(header+4u,p);m.w32(header+8u,10u);m.w8(header+13u,1u);m.w32(header+16u,1u);h.w32(p,actor);++o.appends;
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,Observation&o){
 need(root==0x316fd0u&&m.r32(i.cx)==0x799b60u&&m.r8(0xa285a8u)==1u&&m.r32(0xa283c4u)==0u&&m.r8(i.cx+0x76u)==1u&&m.r8(i.cx+0x74u)==0u&&m.r8(i.cx+0x75u)==0u&&m.r8(i.cx+0x7du)==1u&&m.r32(i.cx+0x80u)==0xffffffffu&&m.r8(i.cx+0x84u)==0u);
 need(i.arg[0]==i.cx+0xa0u&&i.arg[1]==0u);const unsigned p=i.arg[0],x=m.r32(p)/256u,y=m.r32(p+4u)/256u;need(x>=1u&&x<=8u&&y==20u);const unsigned index=x+512u*y;need(index<m.r32(0x81a95cu));const auto cell=m.r32(m.r32(0x81a958u)+4u*index);need(cell!=0u);++o.map_queries;
 need(m.r32(0x799cf4u)==0x423e00u);++o.passability; // Actualvirtual ignores validcell/args, returnsfull0 RET20.
 m.w8(i.cx+0x76u,0u);m.w8(i.cx+0x75u,0u);need(m.r32(0x799cfcu)==0x5cd850u);for(unsigned k=0;k<3u;++k)m.w32(i.cx+0x88u+4u*k,m.r32(p+4u*k));++o.coordinate_calls;
 need(m.r32(0x799c7cu)==0x5cc7f0u&&m.r32(0x799b8cu)==0x7191b0u); // Real43 misses40DC20 kind1..15 identity range.
 m.w8(i.cx+0x74u,1u);need(m.r32(0x799c8cu)==0x5cbd70u);m.w8(i.cx+0x75u,1u);const unsigned tactical=m.r32(0x821cacu);need(tactical!=0u);m.w8(tactical+0xd7du,1u);++o.marks;
 need(m.r32(0x799bd4u)==0x716fb0u);append(m,h,0x83a8f0u,0x789868u,i.cx,o);m.w32(i.cx+0x80u,3u);append(m,h,0x81a7b0u,0x7858ecu,i.cx,o);m.w8(i.cx+0x84u,1u);
 return 1u;
}
}
