#include "recovered/recovery_b1228.hpp"
#include <stdexcept>
namespace ra2::recovered::b1228 {namespace{
void need(bool x){if(!x)throw std::domain_error("1228 finite genuine positive House production-limit query");}
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&o){
 const unsigned house=base+0x4000u,type=base+0xb040u;
 need(root==0xe2cf0u&&i.cx==house&&i.arg[0]==type&&(i.arg[1]&255u)==1u&&i.arg[2]==1u);
 need(m.r32(type)==0x78ea78u&&m.r32(0x78eaa4u)==0x50a3b0u&&m.r32(0x78eab8u)==0x50a3d0u);
 ++o.limit_queries;++o.virtual_callbacks; // Actual Type+2C returns kind16; original dispatch selects current Infantry count.
 const unsigned limit=m.r32(type+0x388u);need(limit==0x7fffffffu); // Genuine positive constructor default excludes historical-limit branch.
 ++o.virtual_callbacks;const unsigned index=m.r32(type+0xb90u);need(index==1u); // Actual Type+40 getter.
 need(m.r32(house+0x5440u)==0x7895acu&&m.r32(house+0x5448u)==11u&&m.r8(house+0x544cu)==1u&&m.r8(house+0x544du)==1u);
 const unsigned current=h.r32(m.r32(house+0x5444u)+4u*index);++o.counter_lookups;
 need(current>=2u&&current<=6u&&m.r8(type+0xc14u)==0u&&current<limit);
 return 1u; // Original4E2F80 MOV EAX,1 gives complete DWORD, RET12. No writes or FP operations on this route.
}
}
