#include "recovered/cpu_b48.hpp"
namespace ra2::recovered::cpu_b48 {
// Original RVA36ab4f, 101 bytes. CPUID leaf1 is a platform input, not a fixed
// feature value or an inferred historical machine specification.
void rva_36ab4f(Memory& m,State& s,Frame& f,const Operations& op){
    f.push(m,s.bx);                          // 76ab4f PUSH EBX
    f.push(m,s.cx);                          // 76ab50 PUSH ECX
    (void)integer::sub(m.r8(0x7e98e3),5,8,s.arithmetic_flags);
    if(s.arithmetic_flags&integer::CF)goto clear; // 76ab58 JC
    s.ax=1;                                 // 76ab5a MOV EAX,1
    if(!op.cpuid)throw std::invalid_argument("B48 CPUID boundary absent");
    {
        const auto observed=op.cpuid(s.ax,s.cx,op.context); // 76ab5f CPUID
        s.ax=observed.ax;s.bx=observed.bx;s.cx=observed.cx;s.dx=observed.dx;
    }
    (void)integer::logical(s.dx&0x8000u,32,s.arithmetic_flags); // 76ab61 TEST
    if(s.arithmetic_flags&integer::ZF)goto clear;
    (void)integer::sub(m.r8(0x7e98e3),5,8,s.arithmetic_flags); // 76ab69 reread
    if(s.arithmetic_flags&(integer::CF|integer::ZF)){
        m.w8(0x7e98e0,0);m.w8(0x7e98e1,1);s.ax=1; // 76ab88..76ab96
    }else{
        m.w8(0x7e98e0,1);m.w8(0x7e98e1,1);s.ax=1; // 76ab72..76ab80
    }
    s.cx=f.pop(m);s.bx=f.pop(m);finish(m,s,f,0);return;
clear:
    m.w8(0x7e98e0,0);m.w8(0x7e98e1,0);s.ax=0; // 76ab9e..76abac
    s.cx=f.pop(m);s.bx=f.pop(m);finish(m,s,f,0);
}
// Original RVA36abb4, 14 bytes. A single sample is split and the high dword is
// stored through caller word0. Independent executions need not sample equally.
void rva_36abb4(Memory& m,State& s,Frame& f,const Operations& op){
    f.push(m,s.bp);s.bp=f.sp;f.push(m,s.si); // PUSH EBP;MOV EBP,ESP;PUSH ESI
    if(!op.rdtsc)throw std::invalid_argument("B48 timestamp boundary absent");
    const auto sample=op.rdtsc(op.context); // 76abb8 RDTSC
    s.ax=std::uint32_t(sample);s.dx=std::uint32_t(sample>>32);
    s.si=m.r32(s.bp+8);m.w32(s.si,s.dx);    // 76abba..76abbd
    s.si=f.pop(m);f.sp=s.bp;s.bp=f.pop(m);  // POP ESI;LEAVE
    finish(m,s,f,0);                       // 76abc1 RET
}
}
