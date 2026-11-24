#pragma once
#include "numeric_b97.hpp"
#include "numeric_b88_detail.hpp"
#include "direct_b33_integer.hpp"
#include "platform/x87_scalar_b46.hpp"
#include "platform/x87_b61.hpp"
#include <array>
namespace ra2::recovered::numeric_b97 {
using namespace floating_b61;
namespace integer=direct_b33::integer;
struct State {std::uint32_t ax{},cx{},dx{},bx{},bp{},si{},di{},arithmetic_flags{};ra2::platform::x87::State fp;};
struct Frame {std::uint32_t entry_sp,sp,outer_return;void push(Memory&m,std::uint32_t x){sp-=4;m.w32(sp,x);}std::uint32_t pop(Memory&m){auto x=m.r32(sp);sp+=4;return x;}};
struct Operations {};
inline void finish(Memory&m,State&,Frame&f,std::uint32_t cleanup){if(f.sp!=f.entry_sp||f.pop(m)!=f.outer_return)throw std::runtime_error("numeric97 private stack imbalance");f.sp+=cleanup;}
inline void reverse_divide64(ra2::platform::x87::State&f,std::uint64_t v){numeric_b88::detail::reverse_divide64(f,v);}
inline void reverse_divide32(ra2::platform::x87::State&f,std::uint32_t v){
 f.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfdivrs %[v]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
