#include "palette_b81.hpp"

#include "floating_b61_a.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace ra2::recovered::palette_b81 {
namespace {
using ra2::platform::x87::State;
namespace fp_extra = ra2::platform::x87_b61;
namespace fp_extended = ra2::platform::x87_extended;

[[noreturn]] void outside(const char* reason) { throw std::domain_error(reason); }
void need(bool condition,const char* reason) { if(!condition) outside(reason); }
std::uint32_t shl32(std::uint32_t value,std::uint32_t count) { return value << (count & 31u); }
std::uint32_t shr32(std::uint32_t value,std::uint32_t count) { return value >> (count & 31u); }
std::uint32_t shl16(std::uint32_t value,std::uint32_t count) { return std::uint16_t(value) << (count & 31u); }
std::uint32_t shr16(std::uint32_t value,std::uint32_t count) { return std::uint16_t(value) >> (count & 31u); }
std::uint8_t lowbyte(std::uint32_t value) { return std::uint8_t(value); }

std::uint32_t pack_rgb(Memory& m,std::uint32_t rva_data) {
    const auto r=std::uint32_t(m.r8(rva_data));
    const auto gb=std::uint32_t(m.r16(rva_data+1u));
    const auto red_shift=lowbyte(m.r32(0x0083b2ecu));
    const auto green_right=lowbyte(m.r32(0x0083b2fcu));
    const auto blue_right=lowbyte(m.r32(0x0083b2f4u));
    auto result=shr32(r,red_shift);
    result=shl32(result,lowbyte(m.r32(0x0083b2e8u)));
    auto green=shr32(gb&255u,green_right);
    green=shl32(green,lowbyte(m.r32(0x0083b2f8u)));
    result|=green;
    auto blue=shr32((gb>>8u)&0xffu,blue_right);
    blue=shl32(blue,lowbyte(m.r32(0x0083b2f0u)));
    return result|blue;
}

std::uint32_t saturate_product(std::uint8_t channel,std::uint32_t coefficient) {
    const auto product=std::uint32_t(channel)*coefficient;
    return std::min(product>>16u,255u);
}

std::uint16_t convert_pixel(Memory& m,const Inputs& i,std::uint32_t src,
                            std::uint32_t mask,std::uint32_t index,bool r565) {
    const auto nonzero=m.r8(mask+index)!=0;
    const std::array<std::uint32_t,3> coefs={
        nonzero?i.arg[2]:i.arg[5], nonzero?i.arg[3]:i.arg[5], nonzero?i.arg[4]:i.arg[5]};
    const auto red=saturate_product(m.r8(src+index*3u),coefs[0]);
    const auto green=saturate_product(m.r8(src+index*3u+1u),coefs[1]);
    const auto blue=saturate_product(m.r8(src+index*3u+2u),coefs[2]);
    if(r565) return std::uint16_t(((red&0xf8u)<<8u)|((green&0xfcu)<<3u)|((blue&0xf8u)>>3u));
    return std::uint16_t(((red&0xfcu)<<8u)|((green&0xf8u)<<2u)|((blue&0xf8u)>>3u));
}

std::uint32_t float_scale(State& fp,std::uint8_t channel,std::uint32_t scale) {
    fp.load_integer32(channel);fp.multiply32(scale);return fp.pop32();
}

void make_default_tables(Memory& m,const Inputs& i) {
    const auto scale_a=m.r32(0x00792ae0u),scale_b=m.r32(0x007998dcu),offset_a=m.r32(0x007998d8u);
    const auto scale_c=m.r32(0x00792ae0u),offset_b=m.r32(0x00792ad8u);
    for(std::uint32_t n=0;n<16u;++n){
        i.fp.load_integer32(n);i.fp.multiply32(scale_a);i.fp.multiply32(scale_b);i.fp.add32(offset_a);
        m.w32(0x00ae0990u+n*4u,i.fp.pop32());
    }
    for(std::uint32_t n=0;n<16u;++n){
        i.fp.load_integer32(n);fp_extended::add_integer32(i.fp,n+16u);i.fp.multiply32(scale_c);i.fp.add32(offset_b);
        m.w32(0x00ae09d0u+n*4u,i.fp.pop32());
    }
}

// Same accepted310e10 algorithm with one host/guest x87 boundary per call.
// Its 255-candidate loop is integer C++; the numeric instruction sequence is
// the accepted helper's sequence, including stores to popped physical slots.
// This avoids saving/restoring108 bytes around every arithmetic instruction.
std::uint32_t nearest_palette(Memory&m,const Inputs&i){
    struct FpScope {const Inputs& in;ra2::platform::x87::Image host;
      explicit FpScope(const Inputs&x):in(x),host(ra2::platform::x87::capture_host()){
       x.fp.require_masked();ra2::platform::x87::restore_host(x.fp.image);}
      ~FpScope(){in.fp.image=ra2::platform::x87::capture_host();ra2::platform::x87::restore_host(host);}
    } scope(i);
    const auto object=i.cx,palette=m.r32(object+0x10),lower=m.r32(object),upper=m.r32(object+4);
    const bool mode=(i.arg[3]&255u)!=0;std::uint32_t chosen=mode?lower:1,best=0x47c35000u,eax=0;
    for(std::uint32_t n=1;n<256;++n){eax=lower;const bool inside=global_b26::s32(n)>=global_b26::s32(lower)&&global_b26::s32(n)<=global_b26::s32(upper);if(mode!=inside)continue;
     const auto pixel=palette+3*n;const std::uint32_t r=m.r8(pixel),g=m.r8(pixel+1),b=m.r8(pixel+2);std::uint16_t status;
     asm volatile("fildl %[r]\n\tfsubrs %[tr]\n\tfildl %[g]\n\tfsubrs %[tg]\n\tfildl %[b]\n\tfsubrs %[tb]\n\t"
      "fld %%st(0)\n\tfmul %%st(1),%%st\n\tfld %%st(2)\n\tfmul %%st(3),%%st\n\tfaddp\n\tfld %%st(3)\n\tfmul %%st(4),%%st\n\tfaddp\n\t"
      "fstp %%st(3)\n\tfstp %%st(0)\n\tfstp %%st(0)\n\tfcoms %[best]\n\tfnstsw %%ax"
      : "=a"(status):[r]"m"(r),[g]"m"(g),[b]"m"(b),[tr]"m"(i.arg[0]),[tg]"m"(i.arg[1]),[tb]"m"(i.arg[2]),[best]"m"(best):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
     eax=(pixel&0xffff0000u)|status;
     if(status&0x100){asm volatile("fstps %0":"=m"(best)::"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");chosen=n;}
     else asm volatile("fstp %%st(0)":::"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
    }
    return (eax&0xffffff00u)|(chosen&255u);
}

std::uint32_t palette_row(Memory& m,const Inputs& i,std::uint32_t receiver,
                          std::uint32_t table_float,std::uint32_t row_base,
                          std::uint32_t pixel_index,bool clamp_channels) {
    const auto palette=m.r32(receiver+0x10u);
    const auto rgb=palette+3u+(pixel_index-1u)*3u;
    std::array<std::uint32_t,3> target={
        float_scale(i.fp,m.r8(rgb),table_float),
        float_scale(i.fp,m.r8(rgb+1u),table_float),
        float_scale(i.fp,m.r8(rgb+2u),table_float)};
    if(clamp_channels){
        constexpr std::uint32_t f255=0x437f0000u;
        for(auto& channel:target){
            i.fp.load32(channel);i.fp.compare_pop32(f255);
            if((i.fp.status()&0x4100u)==0u) channel=f255;
        }
    }
    Inputs helper=i;helper.cx=receiver;
    helper.arg[0]=target[0];helper.arg[1]=target[1];helper.arg[2]=target[2];
    const auto inside=(pixel_index>=m.r32(receiver)&&pixel_index<=m.r32(receiver+4u));
    helper.arg[3]=inside?1u:0u;
    const auto result=nearest_palette(m,helper);
    i.fp=helper.fp;
    m.w8(m.r32(receiver+0x14u)+row_base+pixel_index,lowbyte(result));
    return result;
}
}

std::uint32_t fun_00611a60(Memory& m,const Inputs& i) {
    const auto first=pack_rgb(m,0x00a9e361u);
    if(!i.cx) return first;
    const auto alternate=pack_rgb(m,0x00a9e369u);
    const auto collection=m.r32(0x00a5e208u);
    if(collection){
        const auto count=m.r32(collection+0x10u);
        need(static_cast<std::int32_t>(count)>=0&&count<=32u,"palette collection count outside bounded route");
        if(!count) return first;
        const auto array=m.r32(collection+4u);
        for(std::uint32_t n=0;n<count;++n){
            const auto object=m.r32(array+n*4u);
            if(m.r32(object)==i.cx) return alternate;
        }
        return first;
    }
    return m.r8(i.cx+0x77u)?alternate:first;
}

std::uint32_t fun_00710ae0(Memory& m,const Inputs& i) {
    const auto receiver=i.cx;
    const auto palette=m.r32(receiver+0x10u),output=m.r32(receiver+0x14u);
    need(palette&&output,"palette rasterizer requires supplied palette and output spans");
    std::uint32_t table=i.arg[0];
    if(i.arg[0]&&i.arg[1]){
        need(i.arg[1]>=32u,"palette rasterizer table must contain 32 float entries");
        m.w32(receiver+8u,i.arg[1]);
    }else{
        make_default_tables(m,i);table=0x00ae0990u;m.w32(receiver+8u,0x20u);i.arg[1]=15u;
    }
    for(std::uint32_t row=0;row<32u;++row){
        const auto row_table=(row<16u?table:table+0x40u)+(row%16u)*4u;
        const auto coefficient=m.r32(row_table);
        for(std::uint32_t pixel=1;pixel<256u;++pixel){
            i.arg[1]=(i.arg[1]&0xffffff00u)|std::uint32_t(pixel>=m.r32(receiver)&&pixel<=m.r32(receiver+4u));
            palette_row(m,i,receiver,coefficient,row*0x100u,pixel,row>=16u);
        }
        i.arg[0]=row+1;
    }
    return 32u;
}

std::uint32_t fun_00716580(Memory& m,const Inputs& i) {
    const auto receiver=i.cx,x=i.arg[0],y=i.arg[1],table_group=i.arg[2],pixels=i.arg[3];
    const auto base_x=m.r32(receiver+0xb8u);
    const auto difference=std::int64_t(x)-std::int64_t(base_x)-std::int64_t(y);
    need(difference>=std::numeric_limits<std::int32_t>::min()&&difference<=std::numeric_limits<std::int32_t>::max(),"palette coordinate subtraction exceeds signed range");
    const auto signed_delta=static_cast<std::int32_t>(difference);
    need(signed_delta!=std::numeric_limits<std::int32_t>::min(),"palette coordinate delta overflows signed absolute value");
    const auto delta=std::uint32_t(signed_delta<0?-signed_delta:signed_delta);
    const auto wide_k=std::uint64_t(delta)+300ull*table_group;
    need(wide_k<64u,"palette first lookup index outside bounded table");
    const auto k=std::uint32_t(wide_k);
    const auto t=std::uint32_t(m.r16(0x00ae1098u+k*2u));
    const auto u=t+m.r32(receiver+0x11cu);
    need(u<64u,"palette second lookup index outside bounded table");
    const auto signed_v=static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(0x00ae0c60u+u*2u)));
    need(signed_v!=std::numeric_limits<std::int32_t>::min(),"palette channel index overflows signed absolute value");
    const auto v=std::uint32_t(signed_v<0?-signed_v:signed_v);
    need(v<8u,"palette channel index outside eight-entry table");
    const auto index=m.r32(receiver+0x1d0u+v*4u),factor=m.r32(0x00ae1050u+v*4u);
    need(index<32u&&factor<=256u,"palette pixel index or factor outside bounded route");
    const auto packed=m.r16(pixels+index*2u);
    const auto s0=lowbyte(m.r32(0x0083b2e8u)),s1=lowbyte(m.r32(0x0083b2ecu));
    const auto s2=lowbyte(m.r32(0x0083b2f8u)),s3=lowbyte(m.r32(0x0083b2fcu));
    const auto s4=lowbyte(m.r32(0x0083b2f0u)),s5=lowbyte(m.r32(0x0083b2f4u));
    const auto channel0=std::uint32_t(std::uint8_t(shl16(shr16(packed,s0),s1)));
    auto channel1=std::uint32_t(std::uint8_t(shl16(shr16(packed,s2),s3)));
    auto channel2=std::uint32_t(std::uint8_t(shl16(shr16(packed,s4),s5)));
    const auto product1=std::uint32_t(std::int32_t(channel1)*std::int32_t(factor));
    const auto product2=std::uint32_t(std::int32_t(channel2)*std::int32_t(factor));
    channel1=std::min(channel1+static_cast<std::uint32_t>(static_cast<std::int32_t>(product1)>>8),255u);
    channel2=std::min(channel2+static_cast<std::uint32_t>(static_cast<std::int32_t>(product2)>>8),255u);
    const auto out0=shl32(channel0>> (s1&31u),s0);
    const auto out1=shl32(channel1>> (s3&31u),s2);
    const auto out2=shl32(channel2>> (s5&31u),s4);
    const auto packed_output=std::uint16_t(out0|out1|out2);
    m.w16(pixels,packed_output);
    // EAX is left holding the third transformed component after its final shift.
    return shl32(channel2>>(s5&31u),s4);
}

std::uint32_t fun_007631c0(Memory& m,const Inputs& i) {
    const auto p=i.cx;
    const auto width=m.r16(p+0xeeu),height=m.r16(p+0xf0u);
    const auto xdiv=m.r8(p+0xf2u),ydiv=m.r8(p+0xf3u);
    need(xdiv&&ydiv,"palette receiver divisor is zero");
    const auto qx=std::uint32_t(width/xdiv),qy=std::uint32_t(height/ydiv);
    m.w32(p+0x6c4u,qx);m.w32(p+0x6c8u,qy);m.w32(p+0x6ccu,qx*qy);
    const auto mode=m.r8(p+0x80u),format=m.r8(p+0x108u),flags=m.r8(p+0xeau);
    m.w32(p+0x784u,0x00763d70u);m.w32(p+0x788u,0x00763d70u);m.w32(p+0x780u,0x00763d80u);
    if((mode&1u)==0u){m.w32(p+0x77cu,0x00763590u);m.w32(p+0x780u,0x00763c00u);}
    else {m.w32(p+0x77cu,0x00763c90u);m.w32(p+0x780u,0x00763ce0u);}
    const auto divisor_word=(std::uint32_t(xdiv)<<8u)|ydiv;
    if(divisor_word==0x0402u){
        if(format==4u){m.w32(p+0x784u,0x00768db0u);m.w32(p+0x788u,0x00768ef0u);}
        else if(format==0u){
            m.w32(p+0x784u,0x0076b890u);
            if(flags&4u){
                if(mode&0x80u)m.w32(p+0x788u,0x0076a320u);
                else m.w32(p+0x788u,0x00769ef0u);
            }
        }
    }else if(divisor_word==0x0404u){
        if(format==0u){
            m.w32(p+0x784u,0x0076b926u);
            if(flags&4u){
                if(mode&0x80u)m.w32(p+0x788u,0x007696d0u);
                else if(mode&0x40u)m.w32(p+0x788u,0x00769ae0u);
                else m.w32(p+0x788u,0x00769280u);
            }
            else if(mode&0x40u)m.w32(p+0x784u,0x0076b9e4u);
        }else if(format==1u){m.w32(p+0x784u,0x0076bb18u);m.w32(p+0x788u,0x00768510u);}
        else if(format==4u){m.w32(p+0x784u,0x007688b0u);m.w32(p+0x788u,0x00768a00u);}
    }
    return 0xffffffffu;
}

std::uint32_t fun_00782d40(Memory& m,const Inputs& i) {
    need(m.r8(0x007e98e2u)==0u&&m.r8(0x007e98e0u)==0u,"RGB converter selector outside scalar route");
    const auto source=i.arg[0],destination=i.arg[1],mask=i.arg[6];
    m.w16(destination,0u);std::uint32_t eax=0u;
    for(std::uint32_t n=0;n<255u;++n){
        eax=convert_pixel(m,i,source,mask,n+1u,true);
        m.w16(destination+2u+(n*2u),std::uint16_t(eax));
    }
    return eax;
}

std::uint32_t fun_007836fa(Memory& m,const Inputs& i) {
    need(m.r8(0x007e98e2u)==0u&&m.r8(0x007e98e0u)==0u,"RGB converter selector outside scalar route");
    const auto source=i.arg[0],destination=i.arg[1],mask=i.arg[6];
    m.w16(destination,0u);std::uint32_t eax=0u;
    for(std::uint32_t n=0;n<255u;++n){
        eax=convert_pixel(m,i,source,mask,n+1u,false);
        m.w16(destination+2u+(n*2u),std::uint16_t(eax));
    }
    return eax;
}
}
