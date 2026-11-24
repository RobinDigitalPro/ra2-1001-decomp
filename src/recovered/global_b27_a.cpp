#include "recovered/global_b27_memory.hpp"
#include <atomic>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::global_b27 {
namespace {
constexpr std::uint32_t g_table_a=0x007b7dd8u, g_table_b=0x007bac08u;
std::uint32_t arg_write16(std::uint32_t old,std::uint32_t v){return (old&0xffff0000u)|(v&0xffffu);}
std::uint32_t arg_write_high16(std::uint32_t old,std::uint32_t v){return (old&0x0000ffffu)|(v&0xffff0000u);}
[[noreturn]] void loop_a() { for(;;) std::atomic_signal_fence(std::memory_order_seq_cst); }
[[noreturn]] void loop_b() { for(;;) std::atomic_signal_fence(std::memory_order_seq_cst); }
}

void fun_004070d0(Memory&m,State&s){
    const auto saved_si=s.si, divisor=s.arg[0];
    auto eax=s.dx, edx=0u; eax<<=16;
    // The original unsigned DIV defines EDX:EAX quotient/remainder. Tests stay in
    // the no-divide-fault domain; its full dividend fits the host unsigned type.
    if(!divisor)throw std::domain_error("70d0 original DIV fault outside valid domain");
    const std::uint64_t n=(std::uint64_t(edx)<<32)|eax; s.ax=std::uint32_t(n/divisor); s.dx=std::uint32_t(n%divisor);
    s.si=saved_si;
    m.w32(s.cx+0x10u,divisor); m.w32(s.cx+0x0cu,s.ax); s.ax=s.arg[1]; m.w32(s.cx+0x14u,s.ax);
}
void fun_00408060(Memory&m,State&s){s.ax=m.r32(s.cx+0x20u);s.dx=m.r32(s.cx+0x24u);}
void fun_0040a820(Memory&m,State&s){
    auto eax=s.cx*100u; auto edx=(s32(eax)<0)?0xffffffffu:0u;
    edx&=0xffu; eax=(eax+edx); eax=sar(eax,8);
    if(s32(eax)>100)eax=100;
    else if(s32(eax)<0)eax=0;
    s.ax=m.r32(g_table_a+eax*4u);s.dx=edx;
}
void fun_0040db60(Memory&m,State&s){
    std::uint32_t eax=0x007b890cu,edx=0;
    while(s32(eax)<s32(0x007b8b44u)){
        if(m.r32(eax)==s.cx){s.ax=m.r32(0x007b8908u+edx*8u);s.dx=edx;return;}
        eax+=8u;++edx;
    }
    s.ax=0x007b8b40u;s.dx=edx;
}
void fun_004127a0(Memory&,State&s){
    const auto n=s.arg[0];const auto rem=s32(n)%20;
    const std::int64_t product=std::int64_t(0x66666667u)*std::int64_t(s32(n));
    const auto high=std::uint32_t(std::uint64_t(product)>>32);
    auto edx=sar(high,3); edx+=(high>>31);
    const auto input_y=s.arg[2];auto xraw=s.arg[1]+std::uint32_t(rem);std::uint32_t x;
    if(s32(xraw)<0)x=0;else if(s32(xraw)>19)x=19u;else x=xraw;
    auto y=input_y+edx;std::uint32_t mask=edx;
    if(s32(y)>19)y=19u;
    else {mask=s32(y)<0?0u:0xffffffffu;y&=mask;}
    s.cx=x;s.dx=mask;s.ax=y*20u+x;
}
void fun_004585b0(Memory&m,State&s){const auto index=m.r32(s.cx+0xc78u);s.ax=m.r32(g_table_b+index*4u);}
void fun_004585c0(Memory&m,State&s){
    const auto enable=s.arg[0]&0xffu;std::uint32_t eax,edx;
    const bool ready=enable!=0 && m.r8(s.cx+0x1214u)!=0;
    const auto index=m.r32(s.cx+0xc78u);
    if(ready){edx=1u;eax=m.r32(0x007bac60u+index*4u)+edx;}else{edx=0u;eax=m.r32(0x007bac60u+index*4u)+edx;}
    s.ax=eax;s.dx=edx;
}
void fun_00468ae0(Memory&m,State&s){s.ax=(s.cx<11u)?m.r32(0x007bc77cu+s.cx*8u):0x007b8e5cu;}
void fun_0047cbc0(Memory&m,State&s){
    const auto out=s.cx;auto ecx=s.arg[0]&7u;auto si=std::uint32_t(m.r16(0x00839da0u+ecx*4u)+m.r16(s.dx));
    const auto tbl=0x00839da0u+ecx*4u;auto cx=(m.r16(tbl+2u)+m.r16(s.dx+2u))&0xffffu;
    auto arg=s.arg[0];arg=arg_write16(arg,si); // [ESP+8] after PUSH ESI = arg0
    arg=arg_write_high16(arg,cx<<16); // [ESP+6] overlaps upper half of arg0
    s.arg[0]=arg; m.w32(out,s.arg[0]);s.ax=out;s.cx=(tbl&0xffff0000u)|(cx&0xffffu);s.dx=arg;
}
void fun_00480560(Memory&m,State&s){
    auto cap=m.r32(s.cx+0x18u),edx=0u;const auto oldsi=s.si,oldedi=s.di;
    auto edi=s.arg[0];std::uint32_t eax=0,esi=0;
    eax=cap;
    if(cap==0x100u){esi=m.r32(s.cx+0x1cu);auto delta=edi-esi;esi=m.r32(s.cx+0x14u)+delta;m.w32(s.cx+0x14u,esi);eax=esi;esi&=0xffu;if(esi>0x7fu)edx=1u;eax=(eax>>8)+edx;}
    else {esi=eax+1u;eax=m.r32(s.cx+0x14u)+edi;m.w32(s.cx+0x18u,esi);m.w32(s.cx+0x14u,eax);if(!esi)throw std::domain_error("80560 original DIV fault outside valid domain");edx=eax%esi;eax/=esi;}
    m.w32(s.cx+0x1cu,eax);cap=m.r32(s.cx+0x20u);if(edi>cap)m.w32(s.cx+0x20u,edi);s.si=oldsi;s.di=oldedi;s.ax=cap;s.dx=edx;
}
void fun_00481830(Memory&m,State&s){s.ax=s32(s.cx)<0||s32(s.cx)>=3?0u:m.r32(0x007be3d4u+s.cx*4u);}
void fun_00482bb0(Memory&m,State&s){
    auto ecx=s.cx,eax=s.ax,edx=s.dx;const auto oldsi=s.si,olddi=s.di;std::uint32_t si=0x7fffu;
    if(ecx){eax=s.arg[0];if(eax){if(s32(edx)>0){for(;;){auto edi=m.r32(ecx);m.w32(eax,edi);if((edi&0xffffu)==si && m.r16(eax+2u)==si)break;eax+=4;ecx+=4;--edx;if(s32(edx)<=0)break;}}
      if(s32(edx)<=0){auto a=s.arg[0];a=arg_write16(a,si);a=arg_write_high16(a,si<<16);s.arg[0]=a;ecx=s.arg[0];m.w32(eax-4u,ecx);}}}
    s.ax=eax;s.cx=ecx;s.dx=edx;s.si=oldsi;s.di=olddi;
}
void fun_00482ca0(Memory&m,State&s){s.ax=s.cx<12u?m.r32(0x007be9acu+s.cx*4u):0x007b8e5cu;}
void fun_00482d00(Memory&m,State&s){s.ax=s.cx<8u?m.r32(0x007be9dcu+s.cx*4u):0x007b8e5cu;}
void fun_00482d60(Memory&m,State&s){s.ax=s.cx<5u?m.r32(0x007be9fcu+s.cx*4u):0x007b8e5cu;}
void fun_00486080(Memory&m,State&s){
    const auto oldsi=s.si,olddi=s.di,oldbx=s.bx;auto count=s32(s.arg[2]);if(count<=0){s.si=oldsi;s.di=olddi;s.bx=oldbx;return;}
    auto src=s.arg[1],dst=s.arg[0];const auto object=s.cx;std::uint32_t ecx=0;
    for(std::int32_t k=0;k<count;++k){const auto ch=m.r8(src++);const auto table=m.r32(object+4u);s.arg[2]=(s.arg[2]&0xffffff00u)|ch;ecx=s.arg[2]&0xffu;const auto mapped=m.r8(ecx+table);ecx=(ecx&0xffffff00u)|mapped;m.w8(dst++,mapped);}
    s.ax=src;s.cx=ecx;s.dx=dst;s.si=oldsi;s.di=olddi;s.bx=oldbx;
}
void fun_004981c0(Memory&,State&s){s.ax=(s.di==1u)?1u:0u;}
void fun_004a4460(Memory&m,State&s){
    const auto oldbx=s.bx,oldbp=s.bp,oldsi=s.si,olddi=s.di;auto obj=s.arg[2],eax=m.r32(obj);auto flags=m.r32(s.cx+0x58u);auto ebx=m.r32(0x0078b188u+((flags*3u)*4u));auto pair=s.arg[1];auto edi=m.r32(pair),esi=m.r32(pair+4u),edx=0u;
    if(ebx&1u){edx=edi;edi=esi;esi=edx;edx=0xffffffc0u-eax;edx&=0xffu;eax=edx;}
    if(ebx&2u){eax=0u-eax;edi=0u-edi;eax&=0xffu;}
    if(ebx&4u){edx=0xffffff80u-eax;esi=0u-esi;edx&=0xffu;eax=edx;}
    m.w32(obj,eax);edx=m.r32(s.cx+0x40u)+edi;auto ecx=m.r32(s.cx+0x44u)+esi;const auto result=s.arg[0];m.w32(result,edx);m.w32(result+4u,ecx);
    s.ax=result;s.dx=edx;s.cx=ecx;s.bx=oldbx;s.bp=oldbp;s.si=oldsi;s.di=olddi;
}
[[noreturn]] void fun_004e0920_impl() {loop_a();}
void fun_004e5460(Memory&m,State&s){
    const auto oldbx=s.bx,oldbp=s.bp,oldsi=s.si,olddi=s.di;const auto ebp=s.cx;auto esi=s.arg[1],edi=std::uint32_t(s32(esi)<0?1u:0u),ebx=s.arg[0],edx=0u,eax=0u,ecx=0u;
    if(s32(esi)<0)esi=0u-esi;
    for(unsigned k=0;k<9;++k){const auto shift=m.r32(0x007c5064u+edx);eax=sar(esi,shift);ecx=m.r32(0x007c5040u+edx)+ebx;ecx=ebp+ecx*4u+0x56d0u;if(edi){auto v=m.r32(ecx)-eax;if(s32(v)<0)v=0;m.w32(ecx,v);}else{auto v=m.r32(ecx)+eax;if(s32(v)<0)v=0;m.w32(ecx,v);}edx+=4u;}
    s.arg[1]=0;s.ax=0;s.cx=ecx;s.dx=edx;s.bx=oldbx;s.bp=oldbp;s.si=oldsi;s.di=olddi;
}
void fun_004e7840(Memory&m,State&s){auto eax=s.arg[2];const auto edx=m.r32(s.cx+0x34u);m.w32(s.cx+0x124u,eax);m.w32(s.cx+0x24cu,eax);eax=s.arg[0];m.w32(edx+0xc0u,eax);m.w32(s.cx+0x15f40u,eax);s.ax=eax;s.dx=edx;}
[[noreturn]] void fun_004fe6e0_impl() {loop_b();}
void fun_00527780(Memory&m,State&s){
    const auto oldsi=s.si,olddi=s.di;auto eax=s.arg[0],edx=eax;auto divisor=m.r32(s.cx+0x2c0u);auto edi=divisor-1u;
    std::uint32_t rem=eax;if(s32(eax)>s32(edi)){if(!divisor || (s32(eax)==INT32_MIN&&s32(divisor)==-1))throw std::domain_error("127780 original signed IDIV fault outside valid domain");else rem=std::uint32_t(std::int64_t(s32(eax))%s32(divisor));}
    s.di=olddi;s.si=oldsi;eax=s.cx;while(rem){eax=m.r32(eax+0x28cu);--rem;}s.dx=0;s.ax=eax;
}
void fun_00591bb0(Memory&m,State&s){if(s.cx==0xffffffffu)s.ax=with_al(s.ax,1u);else{s.cx<<=5;s.ax=with_al(s.ax,m.r8(s.cx+0x00a28006u));}}

const std::array<Entry,24>& entries_a(){static const std::array<Entry,24> v{{
 {0x70d0,&fun_004070d0,nullptr},{0x8060,&fun_00408060,nullptr},{0xa820,&fun_0040a820,nullptr},{0xdb60,&fun_0040db60,nullptr},
 {0x127a0,&fun_004127a0,nullptr},{0x585b0,&fun_004585b0,nullptr},{0x585c0,&fun_004585c0,nullptr},{0x68ae0,&fun_00468ae0,nullptr},
 {0x7cbc0,&fun_0047cbc0,nullptr},{0x80560,&fun_00480560,nullptr},{0x81830,&fun_00481830,nullptr},{0x82bb0,&fun_00482bb0,nullptr},
 {0x82ca0,&fun_00482ca0,nullptr},{0x82d00,&fun_00482d00,nullptr},{0x82d60,&fun_00482d60,nullptr},{0x86080,&fun_00486080,nullptr},
 {0x981c0,&fun_004981c0,nullptr},{0xa4460,&fun_004a4460,nullptr},{0xe0920,nullptr,&fun_004e0920_impl},{0xe5460,&fun_004e5460,nullptr},
 {0xe7840,&fun_004e7840,nullptr},{0xfe6e0,nullptr,&fun_004fe6e0_impl},{0x127780,&fun_00527780,nullptr},{0x191bb0,&fun_00591bb0,nullptr}
}};return v;}
} // namespace ra2::recovered::global_b27
