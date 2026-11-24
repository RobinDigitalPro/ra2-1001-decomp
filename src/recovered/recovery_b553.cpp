#include "recovery_b553.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <stdexcept>

namespace ra2::recovery_b553 {
namespace {
std::uint32_t allocate(std::uint32_t size,std::uint32_t flag,void* context){
 if(flag!=1u)throw std::domain_error("B546 0x36d957 flag differs");
 return static_cast<Heap*>(context)->allocate(size);
}
std::uint16_t ntohs16(std::uint16_t x){return std::uint16_t((x>>8)|(x<<8));}
std::uint32_t ntohl32(std::uint32_t x){return (x>>24)|((x>>8)&0x0000ff00u)|((x<<8)&0x00ff0000u)|(x<<24);}
}


namespace {
std::uint16_t swap16(std::uint16_t x){return std::uint16_t((x>>8)|(x<<8));}
std::uint32_t swap32(std::uint32_t x){return (x>>24)|((x>>8)&0x0000ff00u)|((x<<8)&0x00ff0000u)|(x<<24);}
void put16(Heap& h,std::uint32_t p,std::uint16_t x){h.w8(p,std::uint8_t(x));h.w8(p+1u,std::uint8_t(x>>8u));}
void put16(Memory& m,std::uint32_t p,std::uint16_t x){m.w8(p,std::uint8_t(x));m.w8(p+1u,std::uint8_t(x>>8u));}
std::uint16_t get16(const Heap& h,std::uint32_t p){return std::uint16_t(h.r32(p));}
}

// 0x1fa790 bounded one-record serializer. The supported incoming node is the
// host-order type-5 record produced by 0x1fa680; its source node is temporarily
// changed to network byte order by 0x4bacf0 and restored by 0x4bad60.
std::uint32_t fun_005fa790(Memory& m,const Inputs& in,Heap& heap){
 const auto receiver=in.cx;
 const auto size_pointer=in.arg[0];
 const auto first=m.r32(receiver+4u);
 if(!first)throw std::domain_error("B553 positive contract requires one populated record");
 if(heap.r32(first+12u)!=0u)throw std::domain_error("B553 model is limited to one list record");
 const auto type=get16(heap,first+4u);
 const auto length=get16(heap,first+6u);
 if(type!=5u||length!=16u)throw std::domain_error("B553 requires one host-order type-5 payload of 16 bytes");

 // Original sizing loop: four-byte result header plus node header, payload,
 // and DWORD alignment padding.
 const auto pad=(0u-length)&3u;
 const auto total=4u+8u+length+pad;
 m.w32(size_pointer,total);
 ra2::recovered::AllocationWrapperOperations op{allocate,nullptr,&heap};
 const auto output=ra2::recovered::fun_0076d957(total,op);
 if(!output)throw std::domain_error("B553 excludes output allocation failure");
 in.arg[0]=output; // MOV [ESP+0x18],EDI writes the caller's first argument slot.

 // 0x76d4ac is WSOCK32 ordinal 9 (htons reference name); 0x76d4b8 is
 // ordinal 15 (ntohs). On x86 these word conversions both byte-swap.
 put16(heap,output,swap16(std::uint16_t(total)));
 put16(heap,output+2u,swap16(std::uint16_t(m.r16(receiver+2u))));

 // 0x4bacf0 type-5 case uses ordinal 8 (htonl), then htons for type/length.
 const auto payload=heap.r32(first+8u);
 heap.w32(payload,swap32(heap.r32(payload)));
 put16(heap,first+4u,swap16(type));
 put16(heap,first+6u,swap16(length));

 // Serialize the transformed node header and its network-order payload.
 for(unsigned k=0;k<8u;++k)heap.w8(output+4u+k,heap.r8(first+k));
 const auto copied_length=swap16(get16(heap,first+6u));
 if(copied_length!=length)throw std::domain_error("B553 ntohs length differs from supported record");
 for(unsigned k=0;k<copied_length;++k)heap.w8(output+12u+k,heap.r8(payload+k));
 for(unsigned k=0;k<pad;++k)heap.w8(output+12u+copied_length+k,0u);

 // 0x4bad60 type-5 case reverses those conversions on the original linked node.
 put16(heap,first+6u,swap16(get16(heap,first+6u)));
 put16(heap,first+4u,swap16(get16(heap,first+4u)));
 heap.w32(payload,swap32(heap.r32(payload)));
 return in.arg[0]; // EAX reloads [ESP+0x14]; RET 4 cleans the replaced arg0.
}
}

