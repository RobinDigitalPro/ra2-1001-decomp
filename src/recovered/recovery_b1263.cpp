#include "recovery_b1263.hpp"
#include <stdexcept>
namespace ra2::recovered::b1263 {
unsigned run(Memory&m,Inputs&i,Heap&h,Observation&o,unsigned root){
 const auto need=[](bool x){if(!x)throw std::domain_error("1263 true caller-compatible NoInit domain");};
 need(root==0x3043e0u&&m.r32(0x81a910u)==20u&&m.r32(0x81a914u)==20u&&m.r32(m.r32(0x821b88u)+0xd4u)==1000u&&m.r32(0xa2896cu)==0u&&m.r32(0xab8220u)!=0u);
 need(m.r32(0xab81c8u)==0x7995c4u&&m.r32(0xab81ccu)==0u&&m.r32(0xab81d0u)==0u&&m.r32(0xab81d8u)==0u&&m.r32(0xab81dcu)==10u&&m.r8(0xab81d4u)==1u&&m.r8(0xab81d5u)==0u);
 constexpr unsigned vt[]{0x799630u,0x799614u,0x79960cu,0x799604u};for(unsigned j=0;j<4u;++j)m.w32(i.cx+4u*j,vt[j]);m.w32(i.cx+0xacu,0u);m.w32(i.cx+0xa4u,m.r32(0xa2896cu));
 const auto alloc=[&](unsigned n){const unsigned p=h.allocate(n);need(p!=0u);++o.allocations;return p;};
 // Exact original7074F0 owned reserve10 return poststate, from genuine
 // static704340 cold header. No external buffer, old copy or free is reached.
 const unsigned registry=alloc(40u);++o.reserves;m.w32(0xab81ccu,registry);m.w32(0xab81d0u,10u);m.w8(0xab81d4u,1u);m.w8(0xab81d5u,1u);m.w32(0xab81d8u,1u);h.w32(registry,i.cx);++o.appends;
 const unsigned n=m.r32(m.r32(0x821b88u)+0xd4u),records=alloc(8u*n);i.arg[0]=n-1u;m.w32(i.cx+0xa0u,records);
 const unsigned queue=alloc(20u);h.w32(queue,0u);h.w32(queue+4u,n);h.w32(queue+12u,0u);h.w32(queue+16u,0xffffffffu);const unsigned slots=alloc(4u*n+4u);h.w32(queue+8u,slots);for(unsigned j=0;j<=n;++j){h.w32(slots+4u*j,0u);++o.queue_zero_writes;}m.w32(i.cx+0x9cu,queue);h.w32(slots,0u);++o.queue_zero_writes;h.w32(queue,0u);
 // Genuine caller already owns AB8220. The cold-global allocation branch
 // is deliberately excluded; this helper call occurs once for member B0.
 const unsigned bytes=2u*m.r32(0x81a910u)*(m.r32(0x81a914u)+4u);++o.map_size_calls;m.w32(i.cx+0xb0u,alloc(bytes));return i.cx;
}
}
