#include "recovery_b1352.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::b1352 {
namespace {
using U=std::uint32_t;
using namespace numeric_b88::detail;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void reverse_subtract32(fp::State&f,U value){
    f.require_masked();fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfsubrs %[value]\n\tfnsave %[guest]\n\tfrstor %[host]"
      :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[value]"m"(value)
      :"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
std::uint64_t square_sum3(fp::State&f){
    reg<0xd9c0>(f);reg<0xd8c9>(f);reg<0xd9c2>(f);reg<0xd8cb>(f);f.add_pop();
    reg<0xd9c3>(f);reg<0xd8cc>(f);f.add_pop();const auto result=f.pop64();f.pop_st0();f.pop_st0();f.pop_st0();return result;
}
}
U fun_006cb4b0(Memory&m,const Inputs&i){
    using namespace numeric_b88::detail;const U actor=i.cx,vt=m.r32(actor),type=m.r32(actor+0x5acu),point=i.arg[0];
    need(vt==0x78612cu&&m.r32(vt+0x80u)==0x6b6910u&&m.r32(vt+0x84u)==0x41b600u,"1352 actual chained type provider");
    const U flag=m.r32(type+0xb0u);need(flag&&m.r8(flag)==0u,"1352 nonnull actual typeB0 gate");
    need(i.arg[1]==0x40000000u&&read64(m,type+0x340u)==0x3ff0000000000000ull,"1352 scale2 and divisor1");
    const U dx=m.r32(actor+0x88u)-m.r32(point),dy=m.r32(point+4u)-m.r32(actor+0x8cu),dz=m.r32(actor+0x90u)-m.r32(point+8u);
    need(dx==4u&&dy==0u&&dz==0u,"1352 finite nonzero vector(4,0,0)");
    need(s32(sx16(m.r16(actor+0x2f4u)))<=0&&m.r16(actor+0x2e0u)==0x3fffu,"1352 actual4B8850 ratezero heading3FFF");
    auto&f=i.fp;need(f.image.word(8)==0xffffu&&((f.image.word(4)>>11)&7u)==0u,"1352 emptyTOP0 numeric entry");
    f.load_integer32(dx);const U x=f.pop32();f.load_integer32(dy);const U y=f.pop32();f.load_integer32(dz);const U z=f.pop32();
    // Actual4B8850 rate<=0 copies the full headingDWORD into produced private
    // output; root consumes its signed lowWORD. No helper FP operation occurs.
    const U heading=m.r32(actor+0x2e0u);
    f.load_integer32(sx16(heading)-0x3fffu);f.multiply64(read64(m,0x786620u));const auto angle=f.pop64();
    (void)trig(m,f,angle,false);const U sine=f.pop32();(void)trig(m,f,angle,true);const U cosine=f.pop32();
    need(sine==0u&&cosine==0x3f800000u,"1352 original trig table0/1");
    f.load32(z);f.load32(y);f.load32(x);root(m,f,square_sum3(f));
    const U distance=f.store32();f.multiply32(m.r32(0x797eb0u));reverse_subtract32(f,m.r32(0x797eacu));f.multiply32(i.arg[1]);const auto scaled=f.pop64();
    f.load64(scaled);f.divide64(read64(m,type+0x340u));U coefficient=f.pop32();
    f.load32(distance);reg<0xd9e1>(f);f.compare_pop64(read64(m,0x78f628u));need((f.status()&0x100u)==0u,"1352 positive distance gate");
    f.load32(coefficient);f.compare_pop32(m.r32(0x797e88u));need((f.status()&0x100u)==0u,"1352 positive coefficient gate");
    f.load32(coefficient);f.compare_pop32(m.r32(0x797ea8u));if((f.status()&0x4100u)==0u)coefficient=0x3d4ccccdu;
    need(coefficient==0x3d4ccccdu,"1352 actual upper clamp");
    f.load32(y);f.multiply32(y);f.load32(x);f.multiply32(x);f.add_pop();root(m,f,f.pop64());
    ext::compare64(f,read64(m,0x786610u));need((f.status()&0x4000u)==0u,"1352 actual nonzero horizontal norm");
    f.load32(x);reg<0xd8f1>(f);const U nx=f.pop32();f.load32(y);reg<0xd8f1>(f);const U ny=f.pop32();
    reverse_divide64(f,read64(m,0x786610u));const U nz=f.pop32();U eax=nz;
    f.load32(nx);f.multiply32(cosine);f.load32(ny);f.multiply32(sine);f.add_pop();const U projection=f.pop32();
    f.load32(nz);f.multiply32(sine);f.change_sign();const U crossx=f.pop32();
    f.load32(nz);f.multiply32(cosine);const U crossy=f.pop32();
    f.load32(nx);f.multiply32(sine);f.load32(ny);f.multiply32(cosine);reg<0xdee9>(f);
    f.load32(crossy);f.load32(crossx);root(m,f,square_sum3(f));
    f.load32(cosine);f.multiply32(projection);f.load32(sine);reg<0xd8ca>(f);reg<0xdee9>(f);f.subtract32(nx);reg<0xd9e1>(f);f.compare_pop64(read64(m,0x78f620u));
    eax=(eax&0xffff0000u)|f.status();
    if((eax&0x4100u)!=0u){
        f.load32(cosine);reg<0xd8c9>(f);f.load32(sine);f.multiply32(projection);f.add_pop();f.subtract32(ny);reg<0xd9e1>(f);f.compare_pop64(read64(m,0x78f620u));
        eax=(eax&0xffff0000u)|f.status();if((eax&0x4100u)==0u)f.change_sign();
    }else f.change_sign();
    f.load32(projection);f.multiply32(coefficient);f.multiply32(m.r32(0x788d80u));m.w32(actor+0x28cu,f.pop32());
    f.multiply32(coefficient);f.change_sign();m.w32(actor+0x288u,f.pop32());return eax;
}
}
