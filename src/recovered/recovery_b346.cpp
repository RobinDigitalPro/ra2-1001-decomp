#include "recovery_b346.hpp"
#include "platform/x87_extended_b40.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b346 {
namespace {
using namespace ra2::recovered;
using U=std::uint32_t;
namespace FP=ra2::platform::x87;

void fiadd32(FP::State& fp,U value) {
    fp.require_masked(); FP::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfiaddl %[value]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(fp.image.bytes):[value]"m"(value)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
floating_callers_b40::Function find_helper(U rva) {
    for(const auto& e:floating_callers_b40::entries_a()) if(e.rva==rva)return e.function;
    throw std::runtime_error("B346 missing accepted original helper");
}
void invoke_690460(Memory& m,State& s,Frame& caller,U continuation) {
    // The target body reaches the actual accepted 0x690460 entry. This nested
    // frame uses the private stack scratch in the original calling sequence.
    caller.push(m,continuation);
    Frame child; child.entry_sp=child.return_sp=child.sp=caller.sp;
    child.outer_return=continuation;
    find_helper(0x290460u)(m,s,child,{});
    caller.sp=child.sp;
}
void method_004e21c0(Memory& m,State& s,Frame& f) {
    const U entry=f.sp;
    const U private_arg=m.r32(entry+4u);
    if(private_arg!=m.r32(0x00a1e0e4u)+0x24u)
        throw std::domain_error("B346 private vcall argument is not constructor-owned subobject");
    f.push(m,s.cx); f.push(m,s.si);
    s.si=m.r32(f.sp+0x0cu); // original [ESP+0xc] = private argument
    const U descriptor=m.r32(s.si+0x10u);
    if(m.r32(descriptor+0x148u)!=0x3f800000u || m.r32(s.si+0x228u)!=1u)
        throw std::domain_error("B346 numeric method inputs outside finite contract");
    for(U n=0;n<4;++n) {
        if(m.r32(s.si+0x218u+n*4u)!=0x3f800000u ||
           m.r32(m.r32(0xaa863cu)+n*4u)==0)
            throw std::domain_error("B346 vector/table inputs outside finite contract");
        const U record=m.r32(m.r32(0xaa863cu)+n*4u);
        if(m.r32(record+0xb8u)!=1u)throw std::domain_error("B346 table integer outside finite contract");
    }
    s.cx=m.r32(descriptor+0x148u);
    m.w32(f.sp+4u,s.cx); // original scale scratch, saved-ECX slot
    s.cx=s.si+0x218u;
    invoke_690460(m,s,f,0x004e21deu);
    // 0x690460 returns EAX=last converted product, retained as the full DWORD.
    m.w32(f.sp+0x0cu,s.ax); // original overwrites private arg at [ESP+0xc]
    s.fp.load_integer32(s.ax);
    s.fp.multiply32(m.r32(f.sp+4u));
    fiadd32(s.fp,m.r32(s.si+0x228u));
    floating_callers_b40::invoke_closed(m,s,f,0x36aa50u,0x004e21f5u);
    const U result=s.ax;
    (void)private_arg;
    s.si=m.r32(f.sp); f.sp+=4u; // POP ESI
    s.cx=m.r32(f.sp); f.sp+=4u; // POP ECX restores scaled descriptor value
    s.ax=result;
    // Original target is RET 4: the private argument word is consumed.
    if(f.sp!=entry) throw std::runtime_error("B346 nested stack shape");
    if(m.r32(entry)!=0x004b57f1u)throw std::runtime_error("B346 virtual-call continuation differs");
    f.sp=entry+8u;
}
}

void fun_004b57c0(Memory& m,State& s,Frame& f,const Operations&) {
    U flags=s.arithmetic_flags;
    f.push(m,s.si); s.si=s.cx;
    U ecx=0,eax=0;
    s.dx=m.r32(0x00a255c0u);
    do {
        eax+=0x29u; ++ecx;
        const U byte=m.r8(s.dx+eax+0x120fu);
        m.w8(s.si+ecx-1u,byte);
    } while(eax<0x802u);

    U object=m.r32(0x00a1e0e4u)+0x24u;
    f.push(m,object); // vcall's private argument
    const U vptr=m.r32(object);
    if(vptr!=0x78dd74u || m.r32(vptr+0x18u)!=0x004e21c0u)
        throw std::domain_error("B346 vtable slot is outside constructor-proven target");
    s.cx=vptr; // original MOV ECX,[object] immediately before CALL [ECX+0x18]
    f.push(m,0x004b57f1u); // hardware CALL return address
    Frame target; target.entry_sp=target.return_sp=target.sp=f.sp;
    target.outer_return=0x004b57f1u;
    method_004e21c0(m,s,target);
    f.sp=target.sp;
    m.w32(s.si+0x34u,s.ax);

    const U global=m.r32(0x00a255c0u);
    U edx=m.r32(global+0x7c8u),out=m.r32(global+0x7d0u);
    if(edx!=0xffffffffu)throw std::domain_error("B346 selected sentinel branch only");
    flags=direct_b33::integer::sub(edx,0xffffffffu,32,flags);
    m.w32(s.si+0x38u,out);
    s.dx=m.r32(0x00a1e0e4u);
    s.ax=m.r32(s.dx+0xc8u);
    m.w32(s.si+0x3cu,s.ax);
    s.cx=m.r32(0x00a255c0u);
    s.dx=(s.dx&0xffff0000u)|m.r16(s.cx+0x2304u);
    m.w16(s.si+0x40u,s.dx);
    s.si=m.r32(f.sp); f.sp+=4u;
    s.arithmetic_flags=flags;
    floating_b39::finish(m,s,f,0u);
}

std::uint32_t fun_004b57c0_global(Memory& memory,const Inputs& i) {
    // The source translation needs guest stack bytes for its nested RET4 and
    // helper frames. Keep that modeled stack in a private span so its writes
    // cannot enter the externally observed 1 MiB fixture arena.
    constexpr U local_stack_base=0xf0000000u,local_stack_size=0x1000u;
    std::array<std::uint8_t,local_stack_size> stack_bytes{};
    ra2::recovered::leaf::Memory stack_span(stack_bytes.data(),local_stack_base,local_stack_size);
    Memory composed=memory;
    composed.add(stack_span);
    State s{};
    s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.bx=0x31415926u;s.bp=0x27182818u;
    s.si=0x16180339u;s.di=0x14142135u;s.arg=i.arg;s.arithmetic_flags=i.arithmetic_flags;s.fp=i.fp;
    Frame f;f.entry_sp=f.return_sp=f.sp=local_stack_base+0x800u;f.outer_return=0x7f00b346u;
    composed.w32(f.entry_sp,f.outer_return);
    for(unsigned n=0;n<i.arg.size();++n)composed.w32(f.entry_sp+4u+4u*n,i.arg[n]);
    fun_004b57c0(composed,s,f,{});
    i.arg=s.arg;
    i.fp=s.fp;
    return s.ax;
}
}
