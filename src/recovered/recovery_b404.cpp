#include "recovery_b404.hpp"
#include "recovered/global_b27_memory.hpp"
#include "recovered/heap_b29_memory.hpp"
#include "recovered/indirect_b30_memory.hpp"
#include "recovered/leaf_b15_a.hpp"
#include "recovered/recovery_b397.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::indirect_b30 {
void fun_0068fad0(Memory&,State&,Frame&,const Operations&);
}

namespace ra2::recovered::constructors404 {
namespace {
using heap_b29::State;
using HeapFunction=heap_b29::Function;
HeapFunction heap_function(std::uint32_t rva){
    for(const auto&e:heap_b29::entries_c())if(e.rva==rva)return e.function;
    throw std::logic_error("constructors404 accepted heap helper is absent");
}
void empty_heap_vector(Memory&m,std::uint32_t receiver,std::uint32_t helper_rva){
    State s{};s.cx=receiver;s.arg[0]=0;s.arg[1]=0;
    heap_function(helper_rva)(m,s,heap_b29::Operations{nullptr,nullptr});
}
void heap_write32(const Operations&o,std::uint32_t a,std::uint32_t v){
    if(!o.heap_memory.write32)throw std::invalid_argument("constructors404 missing allocated-memory write32");
    o.heap_memory.write32(a,v,o.heap_memory.context);
}
void heap_write8(const Operations&o,std::uint32_t a,std::uint32_t v){
    if(!o.heap_memory.write8)throw std::invalid_argument("constructors404 missing allocated-memory write8");
    o.heap_memory.write8(a,v,o.heap_memory.context);
}
void original_clock(Memory&m,indirect_b30::State&s,const indirect_b30::Call&c,void*ctx){
    const auto*o=static_cast<const Operations*>(ctx);
    if(c.target!=m.r32(0x00785524u)||c.argument_words!=0u||c.cleanup!=0u)
        throw std::runtime_error("constructors404 expected original zero-argument timeGetTime import");
    s.ax=o->tick_result;
}
void read_clock(Memory&m,const Inputs&i,const Operations&o){
    using namespace indirect_b30;
    if(!o.stack_base)throw std::invalid_argument("constructors404 requires explicit local stack");
    State s{};s.cx=i.cx;s.dx=i.dx;s.ax=i.ax;
    for(unsigned k=0;k<s.arg.size();++k)s.arg[k]=i.arg[k];
    Frame f{};f.entry_sp=o.stack_base;f.sp=o.stack_base;f.outer_return=0x40400001u;f.call_return=0x40400002u;
    f.argument_words=0;f.callback_cleanup=0;m.w32(f.entry_sp,f.outer_return);
    indirect_b30::Operations clock_ops{original_clock,const_cast<Operations*>(&o)};
    fun_0068fad0(m,s,f,clock_ops);m.w32(i.cx+0x14fcu,s.ax);
}
void zero_22c6b0(const Operations&o,std::uint32_t r){
    // Original zero-count branch: initial fields, final vptr, +0x10 and caller's +0x14.
    heap_write32(o,r+4u,0u);heap_write32(o,r+8u,0u);
    heap_write8(o,r+0x0cu,1u);heap_write8(o,r+0x0du,0u);
    heap_write32(o,r,0x007937c4u);heap_write32(o,r+0x10u,0u);
}
void call_5bf0(Memory&m,std::uint32_t p){
    std::array<std::uint8_t,16> bytes{};
    for(std::uint32_t n=0;n<bytes.size();++n)bytes[n]=static_cast<std::uint8_t>(m.r8(p+n));
    leaf::Memory local(bytes.data(),p,static_cast<std::uint32_t>(bytes.size()));
    leaf::Inputs in{};in.cx=p;(void)leaf::fun_00405bf0(local,in);
    for(std::uint32_t n=0;n<bytes.size();++n)m.w8(p+n,bytes[n]);
}
}

std::uint32_t fun_00626470(Memory&m,const Inputs&i,const Operations&o){
    const auto p=i.cx;recovery_b397::fun_00498830(m,i);
    m.w32(p+0x11e4u,0);m.w32(p+0x11e8u,0);m.w32(p+0x11ecu,0);m.w32(p+0x11f0u,0);
    m.w32(p+0x11f4u,0);m.w32(p+0x11f8u,0);m.w32(p+0x11fcu,0);m.w32(p+0x1200u,0);
    auto v=p+0x1208u;m.w32(v,m.r32(0x00a9de68u));m.w32(v+4u,m.r32(0x00a9de6cu));
    m.w32(v+8u,m.r32(0x00a9de70u));m.w32(v+12u,m.r32(0x00a9de74u));
    m.w32(p+0x1218u,0u);m.w32(p+0x121cu,0u);
    empty_heap_vector(m,p+0x1220u,0x2d4a0u);
    m.w32(p+0x1220u,0x007875a0u);m.w32(p+0x1234u,10u);m.w32(p+0x1230u,0u);
    m.w32(p+0x1238u,0);m.w32(p+0x123cu,0);m.w32(p+0x1240u,0);m.w32(p+0x1244u,0);
    m.w32(p+0x1248u,0);m.w32(p+0x124cu,0);m.w32(p+0x1250u,0);m.w32(p+0x1254u,0);
    empty_heap_vector(m,p+0x1258u,0x22c630u);
    m.w32(p+0x1258u,0x00791f7cu);m.w32(p+0x126cu,0x1f4u);m.w32(p+0x1268u,0);
    m.w32(p+0x1270u,0u);
    for(unsigned n=0;n<22u;++n){const auto q=p+0x1274u+24u*n;empty_heap_vector(m,q,0x22c630u);m.w32(q,0x00791f7cu);m.w32(q+0x14u,10u);m.w32(q+0x10u,0);}
    m.w32(p+0x1484u,0);m.w32(p+0x1488u,1);m.w32(p+0x148cu,0);m.w32(p+0x1490u,0);m.w32(p+0x1494u,0);
    v=p+0x1498u;m.w32(v,m.r32(0x00a9de68u));m.w32(v+4u,m.r32(0x00a9de6cu));
    m.w32(v+8u,m.r32(0x00a9de70u));m.w32(v+12u,m.r32(0x00a9de74u));
    m.w32(p+0x14a8u,0u);m.w32(p+0x14acu,0u);m.w32(p+0x14b0u,0u);
    m.w8(p+0x14b8u,0);m.w8(p+0x14b9u,0);m.w32(p+0x14d0u,0xffffffffu);m.w8(p+0x14d4u,0);m.w8(p+0x14d5u,0);m.w8(p+0x14d6u,0);
    v=p+0x14d8u;m.w32(v,m.r32(0x00a9de68u));m.w32(v+4u,m.r32(0x00a9de6cu));m.w32(v+8u,m.r32(0x00a9de70u));m.w32(v+12u,m.r32(0x00a9de74u));
    m.w32(p+0x14f8u,0);read_clock(m,i,o);m.w32(p+0x1504u,0);

    const auto child=fun_0076d957(0x10u,o.heap);
    if(child){m.w32(p,0x007936dcu);heap_write32(o,child+4u,0x006292e0u);heap_write32(o,child+8u,0x100u);heap_write32(o,child+0xcu,10u);
        const auto ordinary=fun_0076d957(0x1804u,o.heap);
        if(ordinary){const auto rows=ordinary+4u;heap_write32(o,ordinary,0x100u);
            for(unsigned n=0;n<256u;++n){const auto q=rows+24u*n;zero_22c6b0(o,q);heap_write32(o,q+0x14u,10u);}
            heap_write32(o,child,rows);
            for(unsigned n=0;n<256u;++n)heap_write32(o,rows+24u*n+0x14u,10u);
        }else heap_write32(o,child,0u);
    }
    m.w32(p+0x1254u,child);m.w32(p+0x126cu,0x1f4u);call_5bf0(m,p+0x14bcu);return p;
}
}

