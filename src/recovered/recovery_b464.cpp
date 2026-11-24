#include "recovered/recovery_b464.hpp"
#include "recovered/direct_b33_memory.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_scalar_b46.hpp"
#include "recovered/recovery_b460.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::global_b26 { std::uint32_t fun_00545500(Memory&,const Inputs&); }
namespace ra2::recovered::map_footprint_b460 { std::uint32_t fun_005851f0(Memory&,const Inputs&); }

namespace ra2::recovered::footprint_b464 {
namespace {
using U=std::uint32_t;
using XState=ra2::recovered::floating_b39::State;
using XFrame=ra2::recovered::floating_b39::Frame;

U rng(Memory& m,U p) {
    if(m.r8(p)) return 0;
    U a=m.r32(p+4),b=m.r32(p+8);
    m.w32(p+12+4*a,m.r32(p+12+4*a)^m.r32(p+12+4*b));
    a=m.r32(p+4);b=m.r32(p+8);const U value=m.r32(p+12+4*a);
    ++a;++b;m.w32(p+4,a);m.w32(p+8,b);
    if(static_cast<std::int32_t>(a)>=250)m.w32(p+4,0);
    if(static_cast<std::int32_t>(b)>=250)m.w32(p+8,0);
    return value;
}

U conversion(Memory& m,XState& s,U arena,unsigned n) {
    XFrame parent{};
    parent.entry_sp=parent.sp=arena+0x7e00u;
    parent.outer_return=n?0x57ad10u:0x57ace1u;
    ra2::recovered::floating_callers_b40::invoke_closed(
        m,s,parent,0x36aa50u,parent.outer_return);
    return s.ax;
}

void map_call(Memory& m,XState& s,U arena,U cell,U direction,U sequence) {
    using namespace ra2::recovered::direct_b33;
    Function target=nullptr;
    for(const auto& e:entries_a())if(e.rva==0x766c0u)target=e.function;
    for(const auto& e:entries_b())if(e.rva==0x766c0u)target=e.function;
    if(!target)throw std::runtime_error("missing accepted 0x4766c0 helper");
    Frame f{};const U sp=arena+0x7d00u+sequence*0x40u,continuation=0x57ac5du+sequence*7u;
    f.entry_sp=f.sp=sp;f.outer_return=continuation;f.call_return=continuation;
    f.callback_cleanup=4;f.argument_words=1;f.direct_target=0x545500u;
    s.cx=cell;
    m.w32(sp,continuation);m.w32(sp+4,direction);
    Operations op{};
    op.invoke=[](Memory& mm,State& st,const Call& call,void*) {
        if(call.target!=0x545500u||call.argument_words!=1u||call.cleanup!=4u)
            throw std::domain_error("unreviewed 0x4766c0 map lookup shape");
        ra2::recovered::global_b26::Inputs in{};in.cx=0x81a820u;
        in.arg[0]=mm.r32(call.sp+4u);
        st.ax=ra2::recovered::global_b26::fun_00545500(mm,in);
    };
    target(m,s,f,op);
    if(f.sp!=sp+8u)throw std::domain_error("0x4766c0 RET cleanup differs");
    (void)cell;
}

void iterator_reset(Memory& m,U manager) {
    const U count=m.r32(manager+0xf0u),data=m.r32(manager+0x138u);
    m.w32(manager+0x108u,1);m.w32(manager+0x10cu,count);
    m.w32(manager+0x110u,count-1u);m.w32(manager+0x114u,(count<<11)+data+4u);
}
U iterator_next(Memory& m,U manager) {
    const U count=m.r32(manager+0x110u),old=m.r32(manager+0x114u);
    if(count){m.w32(manager+0x108u,m.r32(manager+0x108u)+1u);
        m.w32(manager+0x110u,count-1u);m.w32(manager+0x10cu,m.r32(manager+0x10cu)-1u);
        m.w32(manager+0x114u,old-0x7fcu);return m.r32(old);}
    U end=m.r32(manager+0x10cu),begin=m.r32(manager+0x108u),row=m.r32(manager+0xf0u);
    m.w32(manager+0x108u,end);m.w32(manager+0x10cu,begin);
    U span=end-row,parity=span+begin-1u;
    if(parity&1u){++begin;--row;m.w32(manager+0x10cu,begin);}
    else{++end;row-=2u;m.w32(manager+0x108u,end);}
    m.w32(manager+0x110u,row);
    const U index=(m.r32(manager+0x10cu)<<9)+m.r32(manager+0x108u);
    const U next=m.r32(manager+0x138u)+(index<<2);
    m.w32(manager+0x114u,next);return m.r32(old);
}
}

U fun_0057ac10(Memory& m,const Inputs& i) {
    constexpr U manager=0x81a820u,rng_state=0xa581d8u;
    const U arena=i.cx-0x100u;
    // Original stack scratch is outside the caller's declared arena. Preserve
    // the private model scratch window so it contributes no false memory delta.
    const U scratch_base=arena+0x7c00u;
    std::array<std::uint8_t,0x400> scratch{};
    for(unsigned k=0;k<scratch.size();++k)scratch[k]=std::uint8_t(m.r8(scratch_base+k));
    XState s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.bx=i.arg[0];s.bp=i.arg[1];
    s.si=0;s.di=0;s.arg=i.arg;s.arithmetic_flags=i.arithmetic_flags;s.fp=i.fp;

    iterator_reset(m,manager);
    U cell=iterator_next(m,manager);
    if(cell){
        const U required=m.r32(0xa3a1b8u);
        auto eligible=[&](U p){return p&&m.r32(p+0x38u)==required&&m.r8(p+0x11au)==0;};
        if(eligible(cell)){
            const U coords=cell+0x24u;
            const U x=m.r16(coords),y=m.r16(coords+2u);
            const std::array<U,3> dirs{2u,4u,3u};
            std::array<U,3> neighbor{};
            for(unsigned k=0;k<dirs.size();++k){map_call(m,s,arena,cell,dirs[k],k);const U delta=m.r16(0x839da0u+4u*dirs[k]);
                const U delta_y=m.r16(0x839da2u+4u*dirs[k]);
                const U nx=std::uint16_t(x+std::int16_t(delta)),ny=std::uint16_t(y+std::int16_t(delta_y));
                neighbor[k]=m.r32(m.r32(manager+0x138u)+(((ny<<9)+nx)<<2));}
            if(eligible(neighbor[0])&&eligible(neighbor[1])&&eligible(neighbor[2])){
                U first=0;
                for(unsigned attempt=0;attempt<4;++attempt){
                    m.w32(arena+0x7d10u,rng(m,rng_state));m.w32(arena+0x7d14u,0);
                    ra2::platform::x87_scalar_b46::load_integer64(s.fp,ra2::recovered::floating_b39::read64(m,arena+0x7d10u));
                    s.fp.multiply64(ra2::recovered::floating_b39::read64(m,0x790f10u));
                    s.fp.add64(ra2::recovered::floating_b39::read64(m,0x785708u));
                    first=conversion(m,s,arena,0);
                    if(first<=10u)break;
                    if(attempt==3)throw std::domain_error("bounded first RNG route did not converge");
                }
                if(first!=1u){
                    U second=0;
                    for(unsigned attempt=0;attempt<4;++attempt){
                        m.w32(arena+0x7d18u,rng(m,rng_state));m.w32(arena+0x7d1cu,0);
                        ra2::platform::x87_scalar_b46::load_integer64(s.fp,ra2::recovered::floating_b39::read64(m,arena+0x7d18u));
                        s.fp.multiply64(ra2::recovered::floating_b39::read64(m,0x790f08u));
                        second=conversion(m,s,arena,1);
                        if(second<=241u)break;
                        if(attempt==3)throw std::domain_error("bounded second RNG route did not converge");
                    }
                    U edi;
                    if(second>=240u)edi=247u-second;
                    else{
                        // Original IMUL 0x66666667 / SAR 4 sequence is signed
                        // truncation by 40 for this nonnegative bounded value.
                        const auto product=std::int64_t(0x66666667u)*std::int64_t(std::int32_t(second));
                        auto quotient=std::int32_t(product>>32)>>4;
                        if(quotient<0)++quotient;
                        edi=std::uint32_t(quotient);
                    }
                    if(!m.r32(0xa5863cu)){
                        const U objects=m.r32(0xa28914u),obj=m.r32(objects+(required+edi)*4u);
                        (void)obj;
                    }
                    ra2::recovered::floating_b61::Inputs root{};root.cx=required+edi;root.dx=coords;
                    root.arg[0]=0xffffffffu;root.arg[1]=0xffffffffu;
                    (void)ra2::recovered::map_footprint_b460::fun_005851f0(m,root);
                }
            }
        }
        (void)iterator_next(m,manager);
    }
    i.fp=s.fp;
    for(unsigned k=0;k<scratch.size();++k)m.w8(scratch_base+k,scratch[k]);
    return 0u;
}
}

