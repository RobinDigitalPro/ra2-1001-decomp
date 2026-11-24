#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1655_formatter {
using U=std::uint32_t;using Memory=ra2::recovered::global_b26::Memory;namespace fp=ra2::platform::x87;
struct Api{virtual ~Api()=default;virtual U interlocked(bool increment,U logical_counter,fp::State&)=0;};
struct Result{U eax;};
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
// Newly proposed finite775D7E FILE/%d/zero boundary, not a general CRT parser.
// No terminator is written here: the genuine76F0A4 wrapper owns termination.
inline Result run(Memory&m,U file,U format,U va,U caller_entry,fp::State&guest,Api&api){
 need(std::uint64_t(file)==std::uint64_t(caller_entry)+0x14u&&std::uint64_t(va)==std::uint64_t(caller_entry)+0x44u,"exact wrapper FILE/VA alias layout");
 struct Span{U p,n;};const std::array<Span,6>spans{{{file,32},{format,6},{va,4},{caller_entry,16},{0xaa5fc8,4},{0xb10e24,4}}};
 for(U i=0;i<spans.size();++i){const auto a=spans[i];need(a.p&&std::uint64_t(a.p)+a.n<=0x100000000ull,"owned span arithmetic");for(U j=i+1;j<spans.size();++j){const auto b=spans[j];need(std::uint64_t(a.p)+a.n<=b.p||std::uint64_t(b.p)+b.n<=a.p,"disjoint boundary spans");}}
 need(m.r32(caller_entry+4)==file&&m.r32(caller_entry+8)==format&&m.r32(caller_entry+12)==va,"actual three parser argument copies");
 need(m.r32(file)==0xaa5fc8&&m.r32(file+4)==0x7fffffff&&m.r32(file+8)==0xaa5fc8&&m.r32(file+12)==0x42,"four produced FILE fields only");
 need(m.r16(format)==0x25&&m.r16(format+2)==0x64&&m.r16(format+4)==0&&m.r32(va)==0,"exact UTF16%d/zero integer");
 need(m.r32(0xb10530)==0&&m.r32(0xb10e20)==0&&m.r32(0xb10e24)==0&&m.r32(0x81776c)==1,"exclusive cold locale/counter domain");
 // Return plus three actual parser arguments (16B) are disjoint from FILE32.
 // FILE intentionally aliases caller16 tail: file=entry+14h, va=entry+44h.
 // Only four produced FILE fields are read; caller slots4/5 change with FILE.
 m.w32(caller_entry+8,format+4);m.w32(caller_entry+12,va+4);
 need(api.interlocked(true,0xb10e24,guest)==1&&m.r32(0xb10e24)==1,"actual increment0to1");
 const U converted=0x30; // exact signed0/base10/precision1 produced digit
 need(api.interlocked(false,0xb10e24,guest)==0&&m.r32(0xb10e24)==0,"actual decrement1to0");
 m.w32(file+4,0x7ffffffd);m.w16(0xaa5fc8,converted);m.w32(file,0xaa5fca);
 m.w32(caller_entry+8,format+6);
 // The boundary does not consume the unused caller tail or private FILE padding.
 // Its caller checks all public argument words after execution.
 return Result{1};
}
}
