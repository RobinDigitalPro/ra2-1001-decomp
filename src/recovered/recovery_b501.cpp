#include "recovery_b501.hpp"
#include "platform/observed_ticks152.hpp"
#include "recovered/floating_composed_b43_memory.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/indirect_b30_memory.hpp"
#include "recovered/leaf_b21_c.hpp"
#include "recovered/preallocated_b66.hpp"
#include "recovered/numeric_b105_machine.hpp"
#include <stdexcept>

namespace ra2::recovered::transform501 {
namespace {
namespace b39=ra2::recovered::floating_b39;
namespace b43=ra2::recovered::floating_composed_b43;
namespace b30=ra2::recovered::indirect_b30;
namespace leaf=ra2::recovered::leaf;
namespace tick=ra2::platform::ticks152;

void observed_time_call(b30::Memory&m,b30::State&s,const b30::Call&c,void*) {
    const auto expected=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&tick::Tick::get));
    if(c.target!=expected || m.r32(0x00785524u)!=expected || c.argument_words!=0u || c.cleanup!=0u)
        throw std::runtime_error("B501 clock path was not the bound real timeGetTime observer");
    // Tick::get calls the real WinMM import and records its actual DWORD.
    s.ax=tick::Tick::get();
}

b30::Function resolve_clock() {
    for(const auto&e:b30::entries_b()) if(e.rva==0x28fad0u) return e.function;
    throw std::logic_error("B501 accepted 0x28FAD0 clock helper missing");
}
b39::Function resolve_b39(std::uint32_t rva) {
    for(const auto&e:b39::entries_a()) if(e.rva==rva) return e.function;
    for(const auto&e:b39::entries_b()) if(e.rva==rva) return e.function;
    throw std::logic_error("B501 accepted floating helper missing");
}
void call_float(Memory&m,State&s,Frame&parent,std::uint32_t rva,std::uint32_t continuation) {
    parent.push(m,continuation);
    Frame child{};child.entry_sp=parent.sp;child.return_sp=parent.sp;child.sp=parent.sp;child.outer_return=continuation;
    resolve_b39(rva)(m,s,child,b39::Operations{});parent.sp=child.sp;
}
void call_composed_float(Memory&m,State&s,Frame&parent,std::uint32_t rva,std::uint32_t continuation) {
    parent.push(m,continuation);
    Frame child{};child.entry_sp=parent.sp;child.return_sp=parent.sp;child.sp=parent.sp;child.outer_return=continuation;
    b43::resolve(rva)(m,s,child,b39::Operations{});parent.sp=child.sp;
}
void call_clock(Memory&m,State&s,Frame&parent) {
    constexpr std::uint32_t continuation=0x00697c05u;
    parent.push(m,continuation);
    b30::State cs{};cs.ax=s.ax;cs.cx=s.cx;cs.dx=s.dx;cs.bx=s.bx;cs.bp=s.bp;cs.si=s.si;cs.di=s.di;
    cs.arithmetic_flags=s.arithmetic_flags;cs.arg=s.arg;
    b30::Frame child{};child.entry_sp=parent.sp;child.sp=parent.sp;
    child.outer_return=continuation;child.call_return=0x0068fad6u;
    child.argument_words=0;child.callback_cleanup=0;m.w32(child.entry_sp,continuation);
    b30::Operations op{observed_time_call,nullptr};resolve_clock()(m,cs,child,op);
    parent.sp=child.sp;s.ax=cs.ax;
}
void set_float_argument(Memory&m,State&s,Frame&f,std::uint64_t value) {
    s.fp.load64(value);f.push(m,s.cx);m.w32(f.sp,s.fp.pop32());
}
}

void fun_00697af0(Memory&m,State&s,Frame&f) {
    const auto receiver=s.cx;std::uint32_t flags=s.arithmetic_flags;
    f.push(m,s.bx);f.push(m,s.si);f.push(m,s.di);s.si=receiver;

    // Actual accepted 0x0040FF10 receiver initialization contract.
    f.push(m,0x00697afau);
    (void)ra2::recovered::global_b26::fun_0040ff10_composed(m,s.si);
    if(f.pop(m)!=0x00697afau)throw std::runtime_error("B501 0x40FF10 return slot changed");
    s.bx=0;flags=b39::integer::logical(s.bx^s.bx,32,flags);s.arithmetic_flags=flags;
    m.w32(s.si+0xa8u,0xffffffffu);m.w8(s.si+0xacu,0);m.w8(s.si+0xadu,0);
    m.w32(s.si+0xc0u,0);m.w32(s.si+0xb0u,0);m.w32(s.si+0xb4u,0);m.w32(s.si+0xb8u,0);m.w32(s.si+0xbcu,0);
    m.w32(s.si+0xc4u,0x3ff00000u);
    m.w32(s.si+0xc8u,m.r32(0x00aa6048u));m.w32(s.si+0xccu,m.r32(0x00aa604cu));
    m.w32(s.si+0xd0u,m.r32(0x00aa6048u));m.w32(s.si+0xd4u,m.r32(0x00aa604cu));
    m.w32(s.si+0xd8u,0);m.w32(s.si+0xdcu,0);m.w32(s.si+0xe0u,0);
    for(unsigned k=0;k<6;++k)m.w32(s.si+0xd64u+4u*k,0);
    m.w8(s.si+0xd7cu,1);m.w8(s.si+0xd7du,0);m.w8(s.si+0xd7eu,0);
    for(unsigned k=0;k<4;++k)m.w32(s.si+0xd80u+4u*k,m.r32(0x00aa5fa8u+4u*k));
    for(unsigned k=0;k<4;++k)m.w32(s.si+0xd90u+4u*k,0);
    m.w32(s.si+0xda0u,0);s.cx=s.si+0xda8u;call_clock(m,s,f);
    m.w32(s.si+0xda4u,s.ax);m.w32(s.si+0xdacu,0);m.w32(s.si+0xdb0u,0);

    const auto matrix=s.si+0xdb4u;
    for(unsigned k=0;k<0x320u;++k)m.w32(s.si+0xe4u+4u*k,0);
    m.w32(s.si,0x00797418u);m.w32(s.si+4u,0x007973fcu);
    m.w32(s.si+8u,0x007973f4u);m.w32(s.si+0x0cu,0x007973ecu);
    m.w16(s.si+0x24u,0);m.w32(s.si+0xa4u,0xffffffffu);
    // The direct child call's exact writes are reproduced from accepted 0x18CE60:
    // MOV EDX,1.0; XOR EAX,EAX; three diagonal stores and nine zero stores.
    f.push(m,0x00697c5cu);
    s.dx=0x3f800000u;s.ax=b39::integer::logical(s.ax^s.ax,32,flags);s.arithmetic_flags=flags;
    for(unsigned k=0;k<12;++k)m.w32(matrix+4u*k,(k==0u||k==5u||k==10u)?s.dx:s.ax);
    if(f.pop(m)!=0x00697c5cu)throw std::runtime_error("B501 0x58CE60 return slot changed");
    s.di=matrix;s.cx=matrix;
    s.cx=matrix;set_float_argument(m,s,f,b39::read64(m,0x00aa5fd0u));
    call_composed_float(m,s,f,0x18d560u,0x00697c6du);
    s.cx=matrix;set_float_argument(m,s,f,b39::read64(m,0x00aa60d8u));
    call_composed_float(m,s,f,0x18d7a0u,0x00697c7eu);
    s.cx=matrix;s.fp.load64(b39::read64(m,0x00aa5fc0u));
    ra2::recovered::numeric_b105::reverse_divide32(s.fp,m.r32(0x00793804u));
    f.push(m,s.cx);m.w32(f.sp,s.fp.pop32());
    call_float(m,s,f,0x18d010u,0x00697c95u);

    s.ax=0x410888ceu;
    m.w32(s.si+0xde4u,0x408888ceu);m.w32(s.si+0xde8u,s.ax);
    m.w32(s.si+0xdecu,0);m.w32(s.si+0xdf0u,0);
    m.w32(s.si+0xdf4u,0xc08888ceu);m.w32(s.si+0xdf8u,0x410888ceu);
    m.w32(s.si+0xdfcu,0);m.w32(s.si+0xe00u,0);m.w32(s.si+0xe04u,0);m.w32(s.si+0xe08u,0);
    m.w32(s.si+0xe0cu,0x3f800000u);m.w32(s.si+0xe10u,0);
    m.w32(0x00821cacu,s.si);s.ax=s.si;
    s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);
    b39::finish(m,s,f,0);
}
}

namespace ra2::recovered::transform501 {
std::uint32_t run(Memory&original,const floating_b61::Inputs&i){
 std::array<std::uint8_t,0x8000>stack{};
 constexpr unsigned base=0x7d000000,entry=base+0x6004,ret=0x76543210;
 ra2::recovered::leaf::Memory local(stack.data(),base,stack.size());
 Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;s.arg=i.arg;
 Frame f{};f.entry_sp=entry;f.return_sp=entry;f.sp=entry;f.outer_return=ret;f.argument_words=16;
 m.w32(entry,ret);for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,i.arg[k]);
 fun_00697af0(m,s,f);i.fp=s.fp;for(unsigned k=0;k<16;++k)i.arg[k]=m.r32(entry+4+4*k);
 return s.ax;
}
}
