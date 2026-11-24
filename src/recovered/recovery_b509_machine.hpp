#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include "recovered/direct_b33_integer.hpp"
#include "platform/x87_scalar_b46.hpp"
#include "platform/x87_b61.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::matrix509 {
using namespace floating_b61;
namespace integer=direct_b33::integer;
struct State {
 std::uint32_t ax{},cx{},dx{},bx{},bp{},si{},di{},arithmetic_flags{};
 ra2::platform::x87::State fp;
};
struct Frame {
 std::uint32_t entry_sp,sp,outer_return;
 void push(Memory&m,std::uint32_t x){sp-=4;m.w32(sp,x);}
 std::uint32_t pop(Memory&m){const auto x=m.r32(sp);sp+=4;return x;}
};
struct Operations {};
inline void finish(Memory&m,State&,Frame&f,std::uint32_t cleanup){
 if(f.sp!=f.entry_sp||f.pop(m)!=f.outer_return)throw std::runtime_error("B509 draft stack imbalance");
 f.sp+=cleanup;
}
inline std::uint64_t read64(Memory&m,std::uint32_t p){return std::uint64_t(m.r32(p))|(std::uint64_t(m.r32(p+4))<<32);}
inline void write64(Memory&m,std::uint32_t p,std::uint64_t v){m.w32(p,std::uint32_t(v));m.w32(p+4,std::uint32_t(v>>32));}
inline void reverse_divide64(ra2::platform::x87::State&f,std::uint64_t v){numeric_b88::detail::reverse_divide64(f,v);}
inline void reverse_divide32(ra2::platform::x87::State&f,std::uint32_t v){
 f.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfdivrs %[v]\n\tfnsave %[guest]\n\tfrstor %[host]"
  :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
