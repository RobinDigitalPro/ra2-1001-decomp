// Bounded structural recovery. Exact target body is at RVA 0x31d80 / VA 0x431d80.
#include "recovery_b279.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::recovery_b279 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
}
std::uint32_t rva_0031d80(Memory& m,const Inputs& in,Heap& heap){
 const auto self=in.cx; need(self!=0,"receiver must be nonnull");
 const auto d=m.r32(self+4u); need(d!=0,"positive route requires nonnull descriptor");
 const auto width=m.r32(d+4u),height=m.r32(d+8u);
 const std::uint64_t n64=std::uint64_t(width)*height;
 need(width!=0&&height!=0&&n64<=0xffffffe0ull-2u,"positive finite dimensions required");
 const auto n=static_cast<std::uint32_t>(n64),request=n+2u;
 need(request>1016u,"route requires original ordinary HeapAlloc branch");
 const auto metadata=m.r32(d+0x18u);
 need(metadata!=0,"metadata pointer must be nonnull");
 const auto count=m.r16(metadata+0xb0u);
 need(count!=0,"positive route requires nonzero metadata word count");
 const auto stride=m.r32(d+0x14u),base=m.r32(d+0x1cu);
 const std::uint64_t src64=std::uint64_t(base)+std::uint64_t(stride)*(count-1u);
 need(src64!=0&&src64+n<=0xffffffffull,"contiguous source N+1 span must not wrap");
 const auto src=static_cast<std::uint32_t>(src64);
 const std::uint64_t src_end=src64+n+1u;
 const std::uint64_t receiver_slot=std::uint64_t(self)+8u;
 const std::uint64_t receiver_end=std::uint64_t(self)+12u;
 need(receiver_end<=src64||src_end<=receiver_slot,
      "source span must not alias the receiver pointer publication at +8");
 need(receiver_end<=d||std::uint64_t(d)+0x20u<=receiver_slot,
      "receiver pointer publication must not overlap descriptor fields read later");
 const auto out=heap.allocate(request);
 need(out!=0,"ordinary allocation failure excluded");
 m.w32(self+8u,out); // 0x431da0 publishes before payload writes.
 heap.w8(out,m.r8(src));
 std::uint32_t e=out+1u; // INC EAX at 0x431dd5.
 for(std::uint32_t row=0;row<height;++row){
   for(std::uint32_t col=0;col<width;++col){
     ++e;
     heap.w8(e-1u,~m.r8(src+1u+row*width+col));
   }
 }
 // Target EAX is output+N+1; receiver+8 retains output base.
 return e;
}
}


