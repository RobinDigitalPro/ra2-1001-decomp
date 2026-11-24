#include "recovery_b546.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <stdexcept>

namespace ra2::recovery_b546 {
namespace {
std::uint32_t allocate(std::uint32_t size,std::uint32_t flag,void* context){
 if(flag!=1u)throw std::domain_error("B546 0x36d957 flag differs");
 return static_cast<Heap*>(context)->allocate(size);
}
std::uint16_t ntohs16(std::uint16_t x){return std::uint16_t((x>>8)|(x<<8));}
std::uint32_t ntohl32(std::uint32_t x){return (x>>24)|((x>>8)&0x0000ff00u)|((x<<8)&0x00ff0000u)|(x<<24);}
}

// One-record positive route for the exact network byte count=28 / payload-size=16
// fixture. The original import calls are represented by their WSOCK32 numeric
// conversions here; native binding remains a separate parent-owned check.
std::uint32_t fun_005fa680(Memory& m,const Inputs& in,Heap& heap){
 const auto receiver=in.cx;
 const auto source=in.arg[0];
 ra2::recovered::AllocationWrapperOperations op{allocate,nullptr,&heap};

 const auto count=ntohs16(static_cast<std::uint16_t>(m.r16(source)));
 m.w16(receiver,count);
 const auto payload_size=ntohs16(static_cast<std::uint16_t>(m.r16(source+2u)));
 m.w16(receiver+2u,payload_size);
 m.w32(receiver+4u,0u);
 if(count!=28u||payload_size!=16u)
  throw std::domain_error("B546 private model is limited to one positive 28/16 record");

 // Original loop entry begins with ESI=source+4 and requests a 16-byte node.
 const auto node=ra2::recovered::fun_0076d957(16u,op);
 if(!node)throw std::domain_error("B546 excludes allocation failure");
 heap.w32(node,m.r32(source+4u));
 heap.w32(node+4u,m.r32(source+8u));
 auto payload_cursor=source+12u;
 const auto length=ntohs16(static_cast<std::uint16_t>(heap.r32(node+6u)));
 if(length!=16u)throw std::domain_error("B546 node length changed from 16");
 in.arg[0]=source+12u; // 0x5fa6fc writes the advanced caller source pointer.
 const auto payload=ra2::recovered::fun_0076d957(length,op);
 if(!payload)throw std::domain_error("B546 excludes payload allocation failure");
 heap.w32(node+8u,payload);
 for(unsigned k=0;k<length;++k)heap.w8(payload+k,m.r8(payload_cursor+k));
 const auto pad=(0u-length)&3u;
 in.arg[0]+=length+pad; // final source+28 for this 16-byte route.

 // 0x4bad60: decode node length/type, then the selected type-5 case at
 // 0x4bada7 converts exactly the first payload dword through WSOCK32 ntohl.
 heap.w8(node+6u,std::uint8_t(length));heap.w8(node+7u,std::uint8_t(length>>8u));
 const auto type=ntohs16(static_cast<std::uint16_t>(heap.r32(node+4u)));
 heap.w8(node+4u,std::uint8_t(type));heap.w8(node+5u,std::uint8_t(type>>8u));
 if(type!=5u)throw std::domain_error("B546 guarded dispatch requires type 5");
 heap.w32(payload,ntohl32(heap.r32(payload)));

 heap.w32(node+12u,m.r32(receiver+4u));
 m.w32(receiver+4u,node);
 return receiver;
}
}
