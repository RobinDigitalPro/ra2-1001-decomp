#include "recovered/preallocated_b66.hpp"
#include <algorithm>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
namespace {
constexpr std::uint32_t G=0xffffffffu;
void unsupported(const char* why){throw std::domain_error(why);}
void require_direct(std::uint32_t count,std::uint32_t capacity,const char* why){
    if(s32(count)<0 || s32(capacity)<0 || s32(count)>=s32(capacity)) unsupported(why);
}
// This is the accepted, byte-verified 0x40ff10 body composed over the shared
// address-space API. Stores stay in original instruction order.
std::uint32_t base_ff10(Memory& m,std::uint32_t c){
    m.w32(c+8,0x785e44);m.w32(c+0xc,0x785e3c);
    m.w32(c+0x18,0);m.w32(c+0x1c,0);m.w8(c+0x20,0);
    const auto flags=m.r8(c+0x14)&0xf8u;
    m.w32(c+0x10,G);m.w32(c,0x785dd8);m.w32(c+4,0x785dbc);
    m.w32(c+8,0x785db4);m.w32(c+0xc,0x785dac);m.w8(c+0x14,flags);
    return c;
}
void append_global(Memory& m,std::uint32_t count_address,std::uint32_t capacity_address,
                   std::uint32_t array_pointer_address,std::uint32_t object){
    const auto capacity=m.r32(capacity_address),old=m.r32(count_address);
    require_direct(old,capacity,"Block66 excluded registry growth/full route");
    // Every caller stores the incremented count before loading the array base
    // and writing the prior-count slot.
    m.w32(count_address,old+1u);
    const auto array=m.r32(array_pointer_address);
    m.w32(array+old*4u,object);
}
void init_plus_methods(Memory& m,std::uint32_t c,std::uint32_t a,std::uint32_t b,
                       std::uint32_t d,std::uint32_t e){
    m.w32(c,a);m.w32(c+4,b);m.w32(c+8,d);m.w32(c+0xc,e);
}
}

std::uint32_t fun_0040ff10_composed(Memory& m,std::uint32_t c){return base_ff10(m,c);}
std::uint32_t fun_0040ffd0_zero_global_composed(Memory& m,std::uint32_t argument){
    if(m.r32(0x00a255c0u)!=0) unsupported("Block66 0x40ffd0 nonzero-global call boundary excluded");
    m.w32(argument+0x0c,0);return 0;
}
std::uint32_t fun_004068f0_ret_composed() noexcept{return 0;}

// 0x228bf0: append a four-byte value if absent from the backward-scanned list.
std::uint32_t fun_00628bf0(Memory& m,const Inputs& i){
    const auto object=i.cx,arg=i.arg[0],initial_count=m.r32(i.cx+0x1230);
    if(s32(initial_count)<0) unsupported("Block66 0x228bf0 negative count excluded");
    if(initial_count){
        const auto data=m.r32(object+0x1224);
        for(std::uint32_t n=initial_count;n>0;){--n;const auto p=data+n*4u;
            if(m.r16(p)==m.r16(arg) && m.r16(p+2)==m.r16(arg+2)) return n;
        }
    }
    const auto capacity=m.r32(object+0x1228);
    if(s32(initial_count)>=s32(capacity)){
        const auto flag=m.r8(object+0x122d);
        if(flag==0 && capacity!=0){m.w8(object+0x14d5,1);return initial_count&0xffffff00u;}
        const auto growth=m.r32(object+0x1234);
        if(s32(growth)<=0){m.w8(object+0x14d5,1);return growth;}
        unsupported("Block66 0x228bf0 growth callback excluded");
    }
    require_direct(initial_count,capacity,"Block66 0x228bf0 full/growth route excluded");
    const auto old=m.r32(object+0x1230),slot=m.r32(object+0x1224);
    m.w32(object+0x1230,old+1u);m.w32(slot+old*4u,m.r32(arg));
    m.w8(object+0x14d5,1);return old;
}

// 0x124160: fixed no-op diagnostics, child propagation, and optional child.
std::uint32_t fun_00524160(Memory& m,const Inputs& i){
    const auto c=i.cx,a0=i.arg[0],a1=i.arg[1],a2=i.arg[2];
    m.w32(c+0x58,a0);m.w32(c+0x5c,a1);m.w32(c+0x60,a2);
    (void)fun_004068f0_ret_composed();(void)m.r32(0x00a25890u);(void)fun_004068f0_ret_composed();
    if((i.arg[3]&0xffu)!=0) unsupported("Block66 0x124160 virtual dispatch branch excluded");
    const auto count=m.r32(c+0x44);
    if(s32(count)>0){
        if(count>32u) unsupported("Block66 0x124160 child count exceeds bounded fixture");
        for(std::uint32_t n=0;n<count;++n){const auto child=m.r32(c+0x28+n*4u);
            m.w32(child+0x28,a0);m.w32(child+0x2c,a1);m.w32(child+0x30,a2);}
    }
    const auto optional=m.r32(c+0x50);
    if(!optional)return 0;
    m.w32(optional+0x28,a0);m.w32(optional+0x2c,a1);m.w32(optional+0x30,a2);return a1;
}

// 0x131370: initializer with the byte/word overlaps preserved in order.
std::uint32_t fun_00531370(Memory& m,const Inputs& i){
    const auto c=i.cx;std::uint32_t eax=0,edx=1;
    m.w32(c,eax);m.w32(c+0xc,eax);m.w32(c+4,m.r32(0x00a2896cu));m.w32(c+0x10,eax);
    m.w32(c+0x20,i.arg[0]);m.w32(c+0x14,edx);m.w32(c+0x18,edx);m.w32(c+0x24,i.arg[1]);
    m.w8(c+0x1c,0);m.w8(c+0x1d,0);m.w32(c+0x28,i.arg[2]);
    m.w32(c+0x2c,i.arg[3]);m.w32(c+0x30,i.arg[4]);m.w32(c+0x34,i.arg[5]);m.w32(c+0x38,i.arg[6]);
    m.w8(c+0x3c,i.arg[7]);
    for(std::uint32_t o=0x3d;o<=0x45;++o)m.w8(c+o,0);
    m.w32(c+0x48,i.arg[11]);m.w8(c+0x4d,0);m.w8(c+0x4c,i.arg[12]);m.w8(c+0x4e,i.arg[13]);
    m.w32(c+0x50,i.arg[14]);m.w32(c+0x54,i.arg[15]);
    m.w32(c,0);m.w32(c+0x10,1);m.w32(c+4,m.r32(0x00a2896cu));m.w32(c+8,i.arg[1]);m.w32(c+0xc,1);
    m.w16(c+0x3d,i.arg[8]);m.w8(c+0x3f,i.arg[8]>>16);m.w16(c+0x40,i.arg[9]);
    m.w8(c+0x42,i.arg[9]>>16);m.w16(c+0x43,i.arg[10]);m.w8(c+0x45,i.arg[10]>>16);
    append_global(m,0x00a562d8u,0x00a562d0u,0x00a562ccu,c);return c;
}

// 0x2e4490: accepted initializer helpers plus the zero-global helper branch.
std::uint32_t fun_006e4490(Memory& m,const Inputs& i){
    const auto c=i.cx,arg0=i.arg[0],arg1=i.arg[1];base_ff10(m,c);
    const auto first=m.r32(arg0);
    m.w32(c+0x24,first);m.w32(c+0x28,first);m.w32(c+0x2c,arg1);m.w32(c+0x1c0,0);
    m.w32(c,0x7989e0);m.w32(c+4,0x7989c4);m.w32(c+8,0x7989bc);m.w32(c+0xc,0x7989b4);
    (void)fun_0040ffd0_zero_global_composed(m,c+4);
    for(std::uint32_t n=0;n<100;++n)m.w32(c+0x30+n*4u,G);
    append_global(m,0x0084e508u,0x0084e500u,0x0084e4fcu,c);
    if(m.r16(arg0)!=0 || m.r16(arg0+2)!=0) unsupported("Block66 0x2e4490 identifier lookup branch excluded");
    return c;
}

// 0x1e3e0: bounded cache-hit/refcount path only; misses allocate and are excluded.
std::uint32_t fun_0041e3e0(Memory& m,const Inputs& i){
    const auto count=m.r32(0x00824930u);if(s32(count)<=0||count>32u)unsupported("Block66 0x1e3e0 bounded cache count required");
    const auto table=m.r32(0x00824924u),key=i.arg[0];
    for(std::uint32_t n=0;n<count;++n){const auto p=m.r32(table+n*4u);if(m.r32(p+0x20000)==key){const auto refs=m.r32(p+0x20004);m.w32(p+0x20004,refs+1u);return p;}}
    unsupported("Block66 0x1e3e0 cache miss/allocation route excluded");
}

std::uint32_t fun_004679e0(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c,0x7887b8);m.w32(c+4,0x78879c);m.w32(c+8,0x788794);m.w32(c+0xc,0x78878c);
    m.w32(c+0x24,0);m.w32(c+0x28,0);m.w32(c+0x2c,i.arg[0]);
    append_global(m,0x008388f8u,0x008388f0u,0x008388ecu,c);return c;
}
std::uint32_t fun_0065f6e0(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c+0x28,0);m.w32(c+0x24,i.arg[0]);m.w32(c+0x2c,G);
    init_plus_methods(m,c,0x7941d0,0x7941b4,0x7941ac,0x7941a4);
    append_global(m,0x00821c50u,0x00821c48u,0x00821c44u,c);return c;
}

// 0x4cde0: 18 entries; mode 0x0f invokes an excluded virtual method.
std::uint32_t fun_0044cde0(Memory& m,const Inputs& i){
    const auto c=i.cx,arg0=i.arg[0],arg1=i.arg[1];
    for(std::uint32_t n=0;n<18;++n){const auto child=m.r32(c+0x454+n*4u);if(!child)continue;
        const auto sub=m.r32(child+0xb0);if(sub&&m.r8(sub+0x318)){m.w32(child+0xbc,arg0);m.w32(child+0xe4,arg1);}}
    const auto raw=m.r8(c+0x5bd);const auto mode=sx8(raw);
    if(mode==15)unsupported("Block66 0x4cde0 virtual mode dispatch excluded");
    for(std::uint32_t n=0;n<18;++n){const auto child=m.r32(c+0x454+n*4u);if(child)m.w8(child+0x158,mode);}
    return 0;
}

std::uint32_t fun_00535420(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);
    m.w32(c+0x28,i.arg[5]);m.w32(c+0x24,i.arg[4]);m.w32(c+0x2c,i.arg[6]);m.w32(c+0x30,i.arg[7]);m.w32(c+0x34,2);
    m.w32(c+0x38,i.arg[0]);m.w8(c+0x48,0);m.w32(c,0x790540);m.w32(c+0x3c,i.arg[1]);m.w32(c+0x44,i.arg[3]);
    m.w32(c+4,0x790524);m.w32(c+0x40,i.arg[2]);m.w32(c+8,0x79051c);m.w32(c+0xc,0x790514);
    append_global(m,0x00a56458u,0x00a56450u,0x00a5644cu,c);return c;
}
std::uint32_t fun_0062e840(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c+0x24,0);m.w32(c+0x28,m.r32(0x00a2896cu));m.w32(c+0x30,0);
    m.w32(c+0x3c,0);m.w32(c+0x34,m.r32(0x00a2896cu));m.w16(c+0x40,0);m.w16(c+0x42,0);
    for(std::uint32_t o=0x44;o<=0x54;o+=4)m.w32(c+o,0);for(std::uint32_t o=0x64;o<=0x70;o+=4)m.w32(c+o,0);
    init_plus_methods(m,c,0x793b90,0x793b74,0x793b6c,0x793b64);
    append_global(m,0x00a9e178u,0x00a9e170u,0x00a9e16cu,c);return c;
}
std::uint32_t fun_005375c0(Memory& m,const Inputs& i){
    const auto c=i.cx;m.w8(c,0x80);m.w8(c+1,0x80);m.w8(c+2,0x80);m.w32(c+4,0);m.w32(c+8,0x10);m.w32(c+0xc,0);
    for(std::uint32_t n=0;n<32;++n){const auto p=c+0x10+n*0x10u;m.w32(p,m.r32(0x00a56578u));m.w32(p+4,m.r32(0x00a5657cu));m.w32(p+8,m.r32(0x00a56580u));m.w32(p+0xc,0);}
    append_global(m,0x00a565b0u,0x00a565a8u,0x00a565a4u,c);return c;
}
std::uint32_t fun_006d73d0(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);const auto tick=m.r32(0x00a2896cu),stack=i.stack_minus8;
    m.w32(c+0x2c,tick);m.w32(c+0x34,0);init_plus_methods(m,c,0x7981c8,0x7981ac,0x7981a4,0x79819c);
    m.w32(c+0x24,i.arg[0]);m.w32(c+0x28,0);m.w32(c+0x2c,tick);m.w32(c+0x30,stack);m.w32(c+0x34,0);m.w32(c+0x40,0);m.w32(c+0x44,0);
    append_global(m,0x00aa7df8u,0x00aa7df0u,0x00aa7decu,c);m.w32(c+0x48,0);m.w32(c+0x4c,0);m.w32(c+0x38,0);m.w32(c+0x3c,0);return c;
}

std::uint32_t fun_005689f0(Memory& m,const Inputs& i){
    const auto root=m.r32(i.cx),cat=i.arg[0];if(cat>2u)unsupported("Block66 0x1689f0 category outside three mapped records");
    const auto rec=root+cat*0x18u,items=m.r32(rec+4),count=m.r32(rec+0x10),key=m.r32(i.arg[1]);
    if(s32(count)<0||count>64u)unsupported("Block66 0x1689f0 bounded count required");
    for(std::uint32_t n=0;n<count;++n){if(m.r32(items+n*12u)==key)return (count-1u-n)&0xffffff00u;}
    const auto cap=m.r32(rec+8);require_direct(count,cap,"Block66 0x1689f0 full/growth route excluded");
    m.w32(rec+0x10,count+1u);const auto dst=items+count*12u;
    m.w32(dst,key);m.w32(dst+4,m.r32(i.arg[1]+4));m.w32(dst+8,m.r32(i.arg[1]+8));
    return (m.r32(i.arg[1]+4)&0xffffff00u)|1u;
}

std::uint32_t fun_005fde20(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);const auto tick=m.r32(0x00a2896cu),scratch=i.stack_minus8;
    m.w32(c+0x2c,tick);m.w32(c+0x34,0);m.w32(c+0x38,m.r32(0x00a2896cu));m.w32(c+0x40,0);
    init_plus_methods(m,c,0x792c58,0x792c3c,0x792c34,0x792c2c);
    m.w32(c+0x24,i.arg[0]);m.w32(c+0x28,0);m.w32(c+0x38,m.r32(0x00a2896cu));m.w32(c+0x3c,scratch);m.w32(c+0x40,0);
    m.w8(c+0x54,0);m.w32(c+0x2c,m.r32(0x00a2896cu));m.w32(c+0x30,scratch);m.w32(c+0x34,0);
    m.w32(c+0x4c,0);m.w32(c+0x50,0);m.w32(c+0x44,0);m.w32(c+0x48,0);
    append_global(m,0x00a5df98u,0x00a5df90u,0x00a5df8cu,c);return c;
}
std::uint32_t fun_006d7340(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c+0x34,0);m.w32(c+0x2c,m.r32(0x00a2896cu));
    init_plus_methods(m,c,0x7981c8,0x7981ac,0x7981a4,0x79819c);
    append_global(m,0x00aa7df8u,0x00aa7df0u,0x00aa7decu,c);return c;
}
std::uint32_t fun_00467a70(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c,0x7887b8);m.w32(c+4,0x78879c);m.w32(c+8,0x788794);m.w32(c+0xc,0x78878c);
    m.w32(c+0x24,0);m.w32(c+0x28,0);m.w32(c+0x2c,0);
    append_global(m,0x008388f8u,0x008388f0u,0x008388ecu,c);return c;
}
std::uint32_t fun_005fdd80(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);const auto tick=m.r32(0x00a2896cu);
    m.w32(c+0x2c,tick);m.w32(c+0x34,0);m.w32(c+0x40,0);m.w32(c+0x38,tick);
    init_plus_methods(m,c,0x792c58,0x792c3c,0x792c34,0x792c2c);
    append_global(m,0x00a5df98u,0x00a5df90u,0x00a5df8cu,c);return c;
}

std::uint32_t fun_006a9690(Memory& m,const Inputs& i){
    const auto c=i.cx,target=i.arg[0];
    if(m.r32(c+0x24)==target)m.w32(c+0x24,0);
    auto link=m.r32(c+0x28);if(link==target){if(!link)unsupported("Block66 0x2a9690 null target-link dereference excluded");link=m.r32(link+0x28);m.w32(c+0x28,link);}
    if(m.r32(c+0x24)!=0)return m.r32(c+0x24);
    m.w8(c+0x34,1);
    const auto count=m.r32(0x00aa87f0u),cap=m.r32(0x00aa87e8u);
    require_direct(count,cap,"Block66 0x2a9690 empty-list full/growth route excluded");
    m.w32(0x00aa87f0u,count+1u);const auto array=m.r32(0x00aa87e4u);m.w32(array+count*4u,c);return count;
}

std::uint32_t fun_007196d0(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c+0x24,G);m.w32(c+0x2c,0);m.w32(c+0x30,0);
    m.w8(c+0x34,1);m.w8(c+0x35,0);m.w32(c+0x28,0x799e1c);m.w32(c+0x3c,10);m.w32(c+0x38,0);
    init_plus_methods(m,c,0x799db8,0x799d9c,0x799d94,0x799d8c);
    append_global(m,0x00b0d018u,0x00b0d010u,0x00b0d00cu,c);return c;
}

std::uint32_t fun_004d2010(Memory& m,const Inputs& i){
    const auto c=i.cx;
    (void)m.r32(0x007c38d4u);(void)m.r32(0x0078524cu);
    m.w32(c+0x68,0);m.w32(c+0x6c,0);(void)fun_004068f0_ret_composed();
    for(std::uint32_t n=0;n<6;++n)m.w32(c+n*4u,G);m.w16(c+0x18,0xffffu);
    const auto count=m.r32(c+0x68);m.w32(c+count*4u,2u);m.w32(c+0x68,count+1u);
    (void)fun_004068f0_ret_composed();return c;
}

std::uint32_t fun_0065a8e0(Memory& m,const Inputs& i){
    const auto c=i.cx;for(std::uint32_t k=0;k<256;++k){m.w8(c+4+k*3u,0);m.w8(c+5+k*3u,0);m.w8(c+6+k*3u,0);}
    m.w32(c+0x304,0);m.w8(c+0x308,0);m.w8(c+0x309,0);m.w8(c+0x30a,0);m.w32(c+0x30c,0);m.w32(c+0x310,1);
    const auto count=m.r32(0x00a9ea10u),cap=m.r32(0x00a9ea08u),flag=m.r8(0x00a9ea0du);
    if(s32(count)<s32(cap)){
        require_direct(count,cap,"Block66 0x25a8e0 invalid spare-capacity registry count");
        m.w32(0x00a9ea10u,count+1u);const auto array=m.r32(0x00a9ea04u);m.w32(array+count*4u,c);
        m.w32(c,count+1u);return c;
    }
    // Selected no-growth/no-append branch: flag==0 and positive capacity skips
    // the virtual growth method and leaves the global count unchanged.
    if(flag!=0 || cap==0)unsupported("Block66 0x25a8e0 callback/zero-capacity branch excluded");
    m.w32(c,count);return c;
}

std::uint32_t fun_004bfc90(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c+0x24,G);
    for(std::uint32_t o=0x28;o<=0x4c;o+=4)m.w32(c+o,0);
    m.w32(c+0x54,G);m.w32(c+0x50,0);m.w32(c+0x58,0);m.w32(c+0x60,0);m.w32(c+0x64,0);m.w8(c+0x68,1);m.w8(c+0x69,0);
    m.w32(c+0x5c,0x78c1b0);m.w32(c+0x70,10);m.w32(c+0x6c,0);m.w8(c+0x74,1);
    init_plus_methods(m,c,0x78c148,0x78c12c,0x78c124,0x78c11c);
    const auto count=m.r32(0x0084e1d0u),capacity=m.r32(0x0084e1c8u);
    if(s32(count)<s32(capacity))append_global(m,0x0084e1d0u,0x0084e1c8u,0x0084e1c4u,c);
    else if(!((m.r8(0x0084e1cdu)==0 && capacity!=0)||s32(m.r32(0x0084e1d4u))<=0))
        unsupported("Block66 0xbfc90 growth callback excluded");
    return c;
}
std::uint32_t fun_00437790(Memory& m,const Inputs& i){
    const auto c=i.cx;base_ff10(m,c);m.w32(c+0x24,0);m.w32(c+0x28,0);m.w32(c+0x2c,0);m.w32(c+0x30,m.r32(0x00a2896cu));
    init_plus_methods(m,c,0x787af0,0x787ad4,0x787acc,0x787ac4);
    append_global(m,0x00aa8730u,0x00aa8728u,0x00aa8724u,c);
    append_global(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c);return c;
}
}
