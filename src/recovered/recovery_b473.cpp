#include "recovered/recovery_b473.hpp"
#include "recovered/numeric_b105.hpp"
#include "recovered/rng_b70.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/floating_b39_memory.hpp"
#include <array>
#include <iostream>
#include <stdexcept>

namespace ra2::recovered::recovery_b473 {
namespace {
namespace x87=ra2::platform::x87;
using State=ra2::recovered::floating_b39::State;
using Frame=ra2::recovered::floating_b39::Frame;
using namespace ra2::recovered::floating_b39;
std::uint64_t q64(Memory&m,std::uint32_t a){return std::uint64_t(m.r32(a))|(std::uint64_t(m.r32(a+4))<<32);}
void mul_pop(x87::State& f){f.require_masked();x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte 0xde,0xc9\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes)::"memory","st","st(1)");}
ra2::recovered::floating_b39::Function helper(std::uint32_t rva){
 for(const auto&e:ra2::recovered::floating_callers_b40::entries_a())if(e.rva==rva)return e.function;
 throw std::runtime_error("B473 reached x87 helper absent from pinned B40 source");
}
void call_x87(Memory&m,State&s,Frame&f,std::uint32_t rva){
 constexpr std::uint32_t continuation=0x4f000001u;f.push(m,continuation);
 Frame c{};c.entry_sp=f.sp;c.return_sp=f.sp;c.sp=f.sp;c.outer_return=continuation;
 helper(rva)(m,s,c,Operations{});f.sp=c.sp;
}
std::uint32_t draw(Memory&m){
 ra2::recovered::floating_b61::Inputs rng{};rng.cx=m.r32(0x00a255c0u)+0x218u;
 rng.arg[0]=0;rng.arg[1]=0x7ffffffeu;return ra2::recovered::rng_b70::fun_0062fe40(m,rng);
}
void rng_call(Memory&m,Frame&f,std::uint32_t& value){f.push(m,0x7ffffffeu);f.push(m,0);value=draw(m);f.sp+=8u;}
}

std::uint32_t fun_00436af0(Memory& original,const Inputs& input){
 // The original function has an aligned private x86 frame. Its scratch stack is
 // kept outside every declared guest arena/global span.
 std::array<std::uint8_t,0x10000> stack{};constexpr std::uint32_t stack_base=0x7c000000u,entry=stack_base+0x6004u;
 ra2::recovered::leaf::Memory local(stack.data(),stack_base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 m.w32(entry,0x4f000000u);for(unsigned k=0;k<input.arg.size();++k)m.w32(entry+4+4*k,input.arg[k]);
 State s{};s.ax=input.ax;s.cx=input.cx;s.dx=input.dx;s.arithmetic_flags=input.arithmetic_flags;s.fp=input.fp;
 Frame f{};f.entry_sp=entry;f.return_sp=entry;f.sp=entry;f.outer_return=0x4f000000u;
 f.push(m,s.bp);s.bp=f.sp;f.sp&=~7u;f.sp-=0x2cu;f.push(m,s.bx);f.push(m,s.si);f.push(m,s.di);s.bx=s.cx;

 // Three exact calls to 62fe40 (the fourth-looking RNG sample is the value
 // drawn at the top of each subsequent interpolation stage).
 std::uint32_t r0=0,r1=0,r2=0;
 rng_call(m,f,r0);m.w32(f.sp+0x10u,r0);
 s.fp.load_integer32(m.r32(f.sp+0x10u));f.push(m,0x7ffffffeu);f.push(m,0);
 s.fp.multiply64(q64(m,0x00787280u));s.fp.load64(q64(m,entry+4+7*4));s.fp.subtract64(q64(m,entry+4+5*4));mul_pop(s.fp);
 s.fp.add64(q64(m,entry+4+5*4));s.fp.multiply64(q64(m,0x00787a88u));
 {auto v=s.fp.pop64();write64(m,f.sp+0x28u,v);}r1=draw(m);f.sp+=8u;m.w32(f.sp+0x10u,r1);
 s.dx=m.r32(0x00a255c0u);s.fp.load_integer32(m.r32(f.sp+0x10u));f.push(m,0x7ffffffeu);f.push(m,0);
 s.fp.multiply64(q64(m,0x00787280u));s.fp.multiply64(q64(m,0x007879b8u));{auto v=s.fp.pop64();write64(m,f.sp+0x20u,v);}
 r2=draw(m);f.sp+=8u;m.w32(f.sp+0x10u,r2);
 s.fp.load_integer32(m.r32(f.sp+0x10u));s.fp.multiply64(q64(m,0x00787280u));s.fp.add64(q64(m,0x00785708u));s.fp.multiply64(q64(m,0x00787a80u));{auto v=s.fp.pop64();write64(m,f.sp+0x10u,v);}

 s.si=m.r32(f.sp+0x14u);s.di=m.r32(f.sp+0x10u);f.push(m,s.si);f.push(m,s.di);call_x87(m,s,f,0xba140u);
 s.ax=m.r32(f.sp+0x24u);s.cx=m.r32(f.sp+0x20u);{auto v=s.fp.pop64();write64(m,f.sp+0x18u,v);}f.push(m,s.ax);f.push(m,s.cx);call_x87(m,s,f,0xba140u);
 s.fp.multiply64(q64(m,f.sp+0x20u));f.push(m,s.si);f.push(m,s.di);s.fp.multiply64(q64(m,f.sp+0x38u));m.w32(f.sp+0x44u,s.fp.pop32());call_x87(m,s,f,0xba140u);
 s.dx=m.r32(f.sp+0x34u);s.ax=m.r32(f.sp+0x30u);{auto v=s.fp.pop64();write64(m,f.sp+0x28u,v);}f.push(m,s.dx);f.push(m,s.ax);call_x87(m,s,f,0xba0f0u);
 s.fp.multiply64(q64(m,f.sp+0x30u));f.push(m,s.si);f.push(m,s.di);s.fp.multiply64(q64(m,f.sp+0x48u));m.w32(f.sp+0x58u,s.fp.pop32());call_x87(m,s,f,0xba0f0u);
 s.fp.multiply64(q64(m,f.sp+0x48u));f.sp+=0x28u;

 const auto out=f.sp+0x2cu;f.push(m,0);f.push(m,0);m.w32(f.sp+0x3cu,s.fp.pop32());f.push(m,out);f.push(m,0);
 s.dx=m.r32(entry+4+2*4);s.ax=m.r32(entry+4+1*4);s.cx=m.r32(entry+4+0*4);f.push(m,0);f.push(m,0x40080000u);f.push(m,0);f.push(m,s.dx);f.push(m,s.ax);f.push(m,s.cx);s.cx=s.bx;
 const auto call_sp=f.sp;const auto helper_entry=call_sp-4u;
 ra2::recovered::floating_b61::Inputs nested{};nested.ax=s.ax;nested.cx=s.cx;nested.dx=s.dx;nested.arithmetic_flags=s.arithmetic_flags;nested.fp=s.fp;
 // 36c40 receives ten caller words and writes the three-word result at the
 // output pointer prepared in this original frame.
 for(unsigned k=0;k<10;++k)nested.arg[k]=m.r32(call_sp+4u*k); nested.stack_minus8=m.r32(call_sp-8u); const std::array<std::uint32_t,10> expected_nested{input.arg[0],input.arg[1],input.arg[2],0u,0x40080000u,0u,0u,out,0u,0u}; for(unsigned k=0;k<10;++k) if(nested.arg[k]!=expected_nested[k]) throw std::runtime_error("B473 nested argument stack differs at index "+std::to_string(k));
 const auto nested_eax=ra2::recovered::numeric_b105::fun_00436c40(m,nested); s.fp=nested.fp;
 const auto eax=helper_entry+(nested_eax-0x7d006004u);
 s.di=m.r32(f.sp);s.si=m.r32(f.sp+4);s.bx=m.r32(f.sp+8);input.fp=s.fp;
 return eax;
}
}
