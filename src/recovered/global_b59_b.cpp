#include "global_b59_b.hpp"
#include <cstdint>
namespace ra2::recovered::global_b26 {
namespace {
inline std::uint32_t repeat_word(std::uint32_t word){word&=0xffffu;return (word<<16)|word;}

// RVA 0x36bc14: paired-byte, four-word lookup path with the BH high-bit fill mode.
std::uint32_t decode_bc14(Memory&m,const Inputs&i){
    const auto table=i.arg[0],src=i.arg[1];auto dst=i.arg[2];const auto width=i.arg[3],height=i.arg[4];
    i.arg[5]<<=1;const auto stride=i.arg[5];const auto product=width*height,end=src+product;
    auto source=src;std::uint32_t eax=0;
    do{
        auto edi=dst;std::uint32_t ecx=width;
        do{
            eax=product;std::uint32_t ebx=0;
            ebx|=m.r8(eax+source)<<8;ebx|=m.r8(source);++source;
            if(ebx&0x8000u){
                const auto bx=ebx&0x7fffu;eax=repeat_word(bx);
                m.w32(edi,eax);m.w32(edi+4u,eax);
                m.w32(stride+edi,eax);m.w32(stride+edi+4u,eax);
            }else{
                const auto entry=table+(ebx<<4);const auto a=m.r32(entry),b=m.r32(entry+4u);
                m.w32(edi,a);m.w32(edi+4u,b);
                const auto c=m.r32(entry+8u),d=m.r32(entry+12u);
                m.w32(stride+edi,c);m.w32(stride+edi+4u,d);eax=c;
            }
            edi+=8u;--ecx;
        }while(ecx!=0);
        dst+=stride*2u;
    }while(source<end);
    return eax;
}

// RVA 0x36bdba: four interleaved table planes and the FF duplicate-byte mode.
std::uint32_t decode_bdba(Memory&m,const Inputs&i){
    const auto table=i.arg[0],src=i.arg[1];auto dst=i.arg[2];const auto width=i.arg[3],height=i.arg[4],pitch=i.arg[5];
    const auto stride=pitch<<2,product=width*height,end=src+product;auto source=src;std::uint32_t eax=0;
    do{
        auto edi=dst;std::uint32_t ecx=width;
        do{
            eax=product;std::uint32_t ebx=m.r8(source);ebx|=m.r8(eax+source)<<8;++source;
            if((ebx>>8)==0xffu){
                const auto bx=((ebx&0xffu)<<8)|(ebx&0xffu);eax=repeat_word(bx);
                m.w32(edi,eax);m.w32(edi+4u,eax);
                m.w32(pitch+edi,eax);m.w32(pitch+edi+4u,eax);
                m.w32(pitch*2u+edi,eax);m.w32(pitch*2u+edi+4u,eax);
                m.w32(pitch*3u+edi,eax);m.w32(pitch*3u+edi+4u,eax);
            }else{
                const auto entry=table+(ebx<<5);eax=m.r32(entry);m.w32(edi,eax);
                eax=m.r32(entry+4u);m.w32(edi+4u,eax);
                eax=m.r32(entry+8u);m.w32(pitch+edi,eax);
                eax=m.r32(entry+12u);m.w32(pitch+edi+4u,eax);
                eax=m.r32(entry+16u);m.w32(pitch*2u+edi,eax);
                eax=m.r32(entry+20u);m.w32(pitch*2u+edi+4u,eax);
                eax=m.r32(entry+24u);m.w32(pitch*3u+edi,eax);
                eax=m.r32(entry+28u);m.w32(pitch*3u+edi+4u,eax);
            }
            edi+=8u;--ecx;
        }while(ecx!=0);
        dst+=stride;
    }while(source<end);
    return eax;
}

// RVA 0x36bcc4: eight byte-wide output planes and the FF duplicate-byte mode.
std::uint32_t decode_bcc4(Memory&m,const Inputs&i){
    const auto table=i.arg[0],src=i.arg[1];auto dst=i.arg[2];const auto width=i.arg[3],height=i.arg[4],pitch=i.arg[5];
    const auto stride=pitch<<3,product=width*height,end=src+product;auto source=src;std::uint32_t eax=0;
    do{
        auto edi=dst;std::uint32_t ecx=width;
        do{
            eax=product;std::uint32_t ebx=m.r8(source);ebx|=m.r8(eax+source)<<8;++source;
            if((ebx>>8)==0xffu){
                const auto bx=((ebx&0xffu)<<8)|(ebx&0xffu);eax=repeat_word(bx);
                for(unsigned plane=0;plane<8;++plane)m.w32(edi+pitch*plane,eax);
            }else{
                const auto entry=table+(ebx<<5);eax=m.r32(entry);m.w32(edi,eax);
                auto offset=pitch;eax=m.r32(entry+4u);m.w32(edi+offset,eax);
                offset<<=1;eax=m.r32(entry+8u);m.w32(edi+offset,eax);
                offset+=pitch;eax=m.r32(entry+12u);m.w32(edi+offset,eax);
                offset+=pitch;eax=m.r32(entry+16u);m.w32(edi+offset,eax);
                offset+=pitch;eax=m.r32(entry+20u);m.w32(edi+offset,eax);
                offset+=pitch;eax=m.r32(entry+24u);m.w32(edi+offset,eax);
                offset+=pitch;eax=m.r32(entry+28u);m.w32(edi+offset,eax);
            }
            edi+=4u;--ecx;
        }while(ecx!=0);
        dst+=stride;
    }while(source<end);
    return eax;
}

std::uint32_t decode_commands(Memory&m,const Inputs&i,bool wide_table){
    const auto table=i.arg[0],src=i.arg[1];auto out=i.arg[2];const auto width=i.arg[3],height=i.arg[4],pitch=i.arg[5];
    const auto ebp=pitch*2u;
    const auto total_bytes=wide_table?(height*ebp*2u):(height*ebp*4u);
    const auto output_end=out+total_bytes;std::uint32_t eax=output_end;
    if(out>=output_end)return eax;
    const auto row_stride=wide_table?ebp*2u:ebp*4u;
    auto row_base=out,row_end=out+width*8u;
    // These bodies overwrite stack parameters with their row cursors before decoding.
    i.arg[5]=row_base;i.arg[4]=row_end;
    auto source=src;std::uint32_t edx=out;
    for(;;){
        if(edx>=output_end)break;
        std::uint32_t esi=source;
        const auto command=m.r16(esi);esi+=2u;i.arg[2]=esi;source=esi;
        const auto index=command&0x1fffu,control=command&0xe000u;eax=index;
        if(control==0){
            eax=table+(index<<(wide_table?4u:5u));
            if(wide_table){
                std::uint32_t counter=2;
                do{
                    std::uint32_t ecx=m.r16(eax+2u),ebx=m.r16(eax);ecx<<=16;ecx|=ebx;eax+=4u;m.w32(edx,ecx);
                    ecx=m.r16(eax+2u);ebx=m.r16(eax);ecx<<=16;ecx|=ebx;eax+=4u;m.w32(edx+4u,ecx);
                    edx+=ebp;--counter;
                }while(counter!=0);
                eax=ebp*2u;edx+=8u-eax;
            }else{
                const auto lane=ebp*2u;std::uint32_t counter=2;
                do{
                    std::uint32_t ecx=m.r16(eax+2u),ebx=m.r16(eax);ecx<<=16;ecx|=ebx;eax+=4u;m.w32(edx,ecx);
                    ecx=m.r16(eax+2u);ebx=m.r16(eax);ecx<<=16;ecx|=ebx;eax+=12u;m.w32(edx+4u,ecx);
                    edx+=lane;--counter;
                }while(counter!=0);
                eax=ebp*4u;edx+=8u-eax;
            }
        }else if(control==0x2000u){
            eax=table+(index<<(wide_table?4u:5u));
            if(wide_table){
                for(unsigned group=0;group<2;++group){auto cursor=edx;for(unsigned k=0;k<4;++k){const auto v=m.r16(eax);if(v!=0x8000u)m.w16(cursor,v);cursor+=2u;eax+=2u;}edx+=ebp;}
                eax=ebp*2u;edx+=8u-eax;
            }else{
                for(unsigned group=0;group<2;++group){auto cursor=edx;for(unsigned k=0;k<4;++k){const auto v=m.r16(eax);if((v&0x8000u)==0)m.w16(cursor,v);cursor+=2u;eax+=2u;}eax+=8u;edx+=ebp*2u;}
                eax=ebp*4u;edx+=8u-eax;
            }
        }else if(control==0x4000u){
            edx+=8u;
        }
        // Other control values consume their word but do not advance output.
        if(edx==row_end){
            row_base+=row_stride;edx=row_base;
            eax=width;row_end=row_base+width*8u;
            i.arg[5]=row_base;i.arg[4]=row_end;
        }
        if(edx>=output_end)break;
        source=esi;
    }
    return eax;
}
}

std::uint32_t fun_0076bc14(Memory&m,const Inputs&i){return decode_bc14(m,i);}
std::uint32_t fun_0076bdba(Memory&m,const Inputs&i){return decode_bdba(m,i);}
std::uint32_t fun_0076bcc4(Memory&m,const Inputs&i){return decode_bcc4(m,i);}
std::uint32_t fun_00768db0(Memory&m,const Inputs&i){return decode_commands(m,i,true);}
std::uint32_t fun_00700b20(Memory&m,const Inputs&i){return decode_commands(m,i,false);}

// RVA 0x36ad1f: bounded row walker with threshold, remap and color lookup writes.
std::uint32_t fun_0076ad1f(Memory&m,const Inputs&i){
    const auto p=i.arg[0];const auto width=m.r8(p),height=m.r8(p+4u);
    auto source=m.r32(p+0x4cu);
    std::uint32_t eax=0;
    for(std::uint32_t row=0;row<height;++row){
        for(std::uint32_t col=0;col<width;++col){
            eax=m.r8(source);++source;
            if((eax&0xffu)!=0){
                const auto candidate=m.r8(m.r32(p+0x50u));auto ebx=candidate+m.r32(p+0x10u);eax&=0xffu;
                const auto threshold=m.r32(p+0x40u),old=m.r16(threshold);
                if((ebx&0xffffu)<old){
                    m.w16(threshold,ebx);
                    const auto map_cursor=m.r32(p+0x44u),out_ptr=m.r32(p+0x48u);
                    auto edx=m.r16(map_cursor);const auto remap=m.r32(p+0x90u);
                    edx=m.r16(remap+edx*2u);edx=(edx&0xff00u)|(eax&0xffu);
                    const auto colors=m.r32(p+0x58u);eax=m.r16(colors+edx*2u);m.w16(out_ptr,eax);
                }
            }
            m.w32(p+0x50u,m.r32(p+0x50u)+1u);
            m.w32(p+0x48u,m.r32(p+0x48u)+2u);
            m.w32(p+0x40u,m.r32(p+0x40u)+2u);
            m.w32(p+0x44u,m.r32(p+0x44u)+2u);
        }
        m.w32(p+0x48u,m.r32(p+0x48u)+m.r32(p+0x1cu));
        eax=m.r32(p+0x14u);m.w32(p+0x40u,m.r32(p+0x40u)+eax);m.w32(p+0x40u,m.r32(p+0x40u)+eax);
        eax=m.r32(p+0x18u);m.w32(p+0x44u,m.r32(p+0x44u)+eax);m.w32(p+0x44u,m.r32(p+0x44u)+eax);
        const auto source_step=m.r32(p+0x20u);source+=source_step;
        m.w32(p+0x50u,m.r32(p+0x50u)+source_step);
        eax=source_step;
    }
    return eax;
}
}
