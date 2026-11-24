#pragma once
#include "recovery_b747.hpp"
#include "numeric_b88_detail.hpp"
#include "direct_b33_integer.hpp"
#include "platform/x87_scalar_b46.hpp"
#include "platform/x87_b61.hpp"
#include <array>
#include "recovered/strings_b37_primitives.hpp"
namespace ra2::recovered::recovery_b747 {
using namespace floating_b61;
namespace integer=direct_b33::integer;
struct State {std::uint32_t ax{},cx{},dx{},bx{},bp{},si{},di{},arithmetic_flags{};ra2::platform::x87::State fp;};
struct Frame {std::uint32_t entry_sp,sp,outer_return;void push(Memory&m,std::uint32_t x){sp-=4;m.w32(sp,x);}std::uint32_t pop(Memory&m){auto x=m.r32(sp);sp+=4;return x;}};
struct Operations {};
using strings_b37::string_detail::Kind;using strings_b37::string_detail::Repeat;
inline void string_instruction(Memory&m,State&s,std::uint32_t&flags,Kind kind,unsigned width,Repeat repeat){strings_b37::StringMemoryView view{m};strings_b37::string_detail::string_instruction(view,s,flags,kind,width,repeat);}
inline void finish(Memory&m,State&,Frame&f,std::uint32_t cleanup){if(f.sp!=f.entry_sp||f.pop(m)!=f.outer_return)throw std::runtime_error("recovery747 private stack imbalance");f.sp+=cleanup;}
inline void reverse_divide64(ra2::platform::x87::State&f,std::uint64_t v){numeric_b88::detail::reverse_divide64(f,v);}
inline void reverse_divide32(ra2::platform::x87::State&f,std::uint32_t v){
 f.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfdivrs %[v]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
