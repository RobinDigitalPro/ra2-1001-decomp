#include "recovered/global_b59_c.hpp"

namespace ra2::recovered::global_b26 {
namespace {
struct PixelFormat { unsigned first_right,first_mask,second_right,second_mask,blue_left,first_down,first_left,second_down,second_left,blue_down; };

// Preserve the original byte-register saturation sequence: product/256,
// ADD low byte, SETNC, DEC low byte, OR low byte.
std::uint32_t blend_component(std::uint32_t component,std::uint32_t alpha) {
    auto product=(component*alpha)>>8;
    auto edx=component;
    const auto sum=(product&0xffffff00u)|std::uint8_t((product&255u)+(edx&255u));
    const bool carry=((product&255u)+(edx&255u))>255u;
    edx=(edx&0xffffff00u)|(carry?0u:1u); // SETNC DL
    edx=(edx&0xffffff00u)|std::uint8_t((edx-1u)&255u); // DEC DL
    return (sum&0xffffff00u)|((sum|edx)&255u); // OR BL/AL/CL
}

std::uint32_t blend_rows(Memory& m,const Inputs& i,const PixelFormat& f) {
    auto src_base=i.arg[0],dst_base=i.arg[1];
    auto remaining_rows=i.arg[5];
    const auto width=i.arg[4];
    const auto src_stride=i.arg[2],dst_stride=i.arg[3];
    std::uint32_t eax=0;
    while(remaining_rows!=0) {
        // The original reloads the width and XORs EAX at every row entry.
        eax=0;
        auto src=src_base,dst=dst_base;
        auto count=width;
        while(count!=0) {
            const auto alpha=m.r8(src);
            eax=(eax&0xffffff00u)|alpha; // MOV AL,[ESI], including zero-alpha skip
            if(alpha!=0) {
                const auto pixel=m.r16(dst);
                auto first=((pixel>>f.first_right)&f.first_mask);
                auto second=((pixel>>f.second_right)&f.second_mask);
                first=blend_component(first,alpha);
                second=blend_component(second,alpha);
                auto ebx=(first>>f.first_down)<<f.first_left;
                auto eax_channel=(second>>f.second_down)<<f.second_left;
                auto blue=((pixel<<f.blue_left)&255u);
                blue=blend_component(blue,alpha)>>f.blue_down;
                eax_channel|=ebx;
                eax_channel|=blue;
                eax=eax_channel;
                m.w16(dst,eax);
            }
            ++src;dst+=2u;--count;
        }
        src_base+=src_stride;dst_base+=dst_stride;--remaining_rows;
    }
    return eax;
}

std::uint32_t bitmap_format(Memory&m,const Inputs&i,unsigned which) {
    static constexpr PixelFormat formats[4]{
        {8,0xf8,3,0xfc,3,3,11,2,5,3},
        {8,0xfc,2,0xf8,3,2,10,3,5,3},
        {8,0xf8,3,0xf8,2,3,11,3,6,2},
        {7,0xf8,2,0xf8,3,3,10,3,5,3}
    };
    return blend_rows(m,i,formats[which]);
}
}

std::uint32_t fun_00783a3a(Memory&m,const Inputs&i){return bitmap_format(m,i,0);}
std::uint32_t fun_00783b17(Memory&m,const Inputs&i){return bitmap_format(m,i,1);}
std::uint32_t fun_00783bf4(Memory&m,const Inputs&i){return bitmap_format(m,i,2);}
std::uint32_t fun_00783cd1(Memory&m,const Inputs&i){return bitmap_format(m,i,3);}

std::uint32_t fun_0077ba62(Memory&m,const Inputs&i) {
    const auto base=i.arg[0];
    const auto bits=i.arg[1];
    const auto quotient=std::uint32_t(s32(bits)/32);
    const auto remainder=std::uint32_t(s32(bits)%32);
    i.arg[1]=0; // AND dword ptr [EBP+0xc],0; the stack scratch is observable
    auto mask=0xffffffffu<<(remainder&31u);
    mask=~mask;
    const auto across=32u-remainder;
    auto carry=0u;
    for(unsigned k=0;k<3;++k) {
        const auto value=m.r32(base+4u*k);
        const auto kept=value&mask;
        auto shifted=value>>(remainder&31u);
        shifted|=carry;
        m.w32(base+4u*k,shifted);
        carry=kept<<(across&31u);
        i.arg[1]=carry;
    }
    const auto shifted_words=quotient;
    const auto source_delta=shifted_words<<2;
    std::int32_t word_index=2;
    std::int32_t offset=8;
    std::uint32_t eax=0;
    while(offset>=0) {
        if(word_index<s32(shifted_words)) {
            m.w32(base+std::uint32_t(offset),0);
            eax=base;
        } else {
            eax=std::uint32_t(offset)-source_delta;
            eax=m.r32(base+eax);
            m.w32(base+std::uint32_t(offset),eax);
        }
        --word_index;offset-=4;
    }
    return eax;
}

std::uint32_t fun_0076ac10(Memory&m,const Inputs&i) {
    const auto obj=i.arg[0];
    auto flags=m.r32(obj+0x8c)|m.r32(obj+0x88);
    m.w32(obj+0x74,flags);
    std::uint8_t ch=0,cl=0;
    auto eax=m.r32(obj+0x54);m.w32(obj+0x6c,eax);
    const auto row_count=m.r8(obj+4),width=m.r8(obj);
    do {
        cl=0;
        auto esi=m.r32(obj+0x54);
        do {
            eax=(eax&0xffffff00u)|m.r8(esi);++esi;
            if((eax&255u)!=0) {
                auto edi=m.r32(obj+0x50),edx=m.r32(obj+0x40);
                auto ebx=m.r8(edi);ebx+=m.r32(obj+0x10);eax=0;
                if((ebx&0xffffu)<m.r16(edx)) {
                    m.w16(edx,ebx);
                    ebx=m.r32(obj+0x44);edx=m.r32(obj+0x4c);
                    eax=m.r16(ebx);
                    ebx=m.r32(obj+0x90);eax=(eax&0xffff0000u)|m.r16(ebx+eax*2u);
                    eax=(eax&0xffffff00u)|m.r8(edx);
                    edx=m.r32(obj+0x58);edi=m.r32(obj+0x48);
                    eax=(eax&0xffff0000u)|m.r16(edx+eax*2u);
                    m.w16(edi,eax);
                }
                // These two byte streams advance only on the nonzero-alpha path.
                auto p=m.r32(obj+0x50);m.w32(obj+0x50,p+1u);
                p=m.r32(obj+0x4c);m.w32(obj+0x4c,p+1u);
            }
            ++cl;
            auto p=m.r32(obj+0x48);m.w32(obj+0x48,p+2u);
            p=m.r32(obj+0x40);m.w32(obj+0x40,p+2u);
            p=m.r32(obj+0x44);m.w32(obj+0x44,p+2u);
        } while(s32(std::uint32_t(std::int8_t(cl)))<s32(std::uint32_t(std::int8_t(width))));

        eax=m.r32(obj+0x48)+m.r32(obj+0x1c);m.w32(obj+0x48,eax);
        auto p=m.r32(obj+0x40),stride=m.r32(obj+0x14);p+=stride;p+=stride;m.w32(obj+0x40,p);
        p=m.r32(obj+0x44);stride=m.r32(obj+0x18);p+=stride;p+=stride;m.w32(obj+0x44,p);
        eax=m.r32(obj+0x6c)+m.r32(obj);m.w32(obj+0x54,eax);m.w32(obj+0x6c,eax);
        if(m.r32(obj+0x74)!=0) {
            eax=std::uint32_t(ch)+m.r32(obj+0xc);eax<<=4;auto ebx=eax+eax*2u;ebx+=m.r32(obj+8);auto edx=ebx;
            if(m.r32(obj+0x8c)!=0) {
                auto table=m.r32(obj+0x60);ebx+=m.r32(obj);const auto adjustment=m.r32(table+ebx*4u);
                p=m.r32(obj+0x4c);m.w32(obj+0x4c,p+adjustment);
                p=m.r32(obj+0x50);m.w32(obj+0x50,p+adjustment);
                eax=adjustment;
            }
            if(m.r32(obj+0x88)!=0) {
                auto table=m.r32(obj+0x5c);edx+=m.r32(obj);const auto adjustment=m.r32(table+edx*4u);
                p=m.r32(obj+0x4c);m.w32(obj+0x4c,p+adjustment);
                p=m.r32(obj+0x50);m.w32(obj+0x50,p+adjustment);
                eax=adjustment;
            }
        }
        ++ch;
    } while(s32(std::uint32_t(std::int8_t(ch)))<s32(std::uint32_t(std::int8_t(row_count))));
    return eax;
}
}
