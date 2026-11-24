#pragma once
#include "recovery_b1110.hpp"
#include "numeric_b88_detail.hpp"
#include "direct_b33_integer.hpp"
#include "platform/x87_scalar_b46.hpp"
#include "platform/x87_b61.hpp"
#include <array>
#include "recovered/strings_b37_primitives.hpp"
namespace ra2::recovered::recovery_b1110 {
using namespace floating_b61;
namespace integer=direct_b33::integer;
inline void reviewed1110(Memory&m,const Inputs&i,unsigned root){unsigned cw=root==0x3786b5u?i.arg[6]:(root==0x37874du?i.arg[8]:m.r16(i.arg[2]));if((cw&0x3fu)!=0x3fu||i.fp.image.word(0)!=(root==0x37ccabu?0x27fu:0x137fu)||(root==0x3786b5u&&(i.arg[0]!=4u||i.arg[1]!=0x25u))||(root==0x37874du&&(i.arg[0]!=0x11u||i.arg[1]!=0x19u))||(root==0x37ccabu&&m.r32(i.arg[1])!=3u)||(root!=0x3786b5u&&cw!=0xe7fu&&cw!=0xf7fu))throw std::domain_error("1110 only genuine masked logbzero/overflow packets");}
struct State {std::uint32_t ax{},cx{},dx{},bx{},bp{},si{},di{},arithmetic_flags{};ra2::platform::x87::State fp;ThreadAPI*os=nullptr;};
struct Frame {std::uint32_t entry_sp,sp,outer_return;void push(Memory&m,std::uint32_t x){sp-=4;m.w32(sp,x);}std::uint32_t pop(Memory&m){auto x=m.r32(sp);sp+=4;return x;}};
struct Operations {};
using strings_b37::string_detail::Kind;using strings_b37::string_detail::Repeat;
inline void string_instruction(Memory&m,State&s,std::uint32_t&flags,Kind kind,unsigned width,Repeat repeat){strings_b37::StringMemoryView view{m};strings_b37::string_detail::string_instruction(view,s,flags,kind,width,repeat);}
inline void finish(Memory&m,State&,Frame&f,std::uint32_t cleanup){if(f.sp!=f.entry_sp||f.pop(m)!=f.outer_return)throw std::runtime_error("recovery1110 private stack imbalance");f.sp+=cleanup;}
inline void reverse_divide64(ra2::platform::x87::State&f,std::uint64_t v){numeric_b88::detail::reverse_divide64(f,v);}
inline void reverse_divide32(ra2::platform::x87::State&f,std::uint32_t v){
 f.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfdivrs %[v]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
