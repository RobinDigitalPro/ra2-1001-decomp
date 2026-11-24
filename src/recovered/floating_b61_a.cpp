#include "floating_b61_a.hpp"
#include <cstdint>
#include <initializer_list>

namespace ra2::recovered::floating_b61 {
namespace {
void store_pop32(Memory& m,std::uint32_t address,const Inputs& i){m.w32(address,i.fp.pop32());}
void dot3_negative(const Inputs& i,std::uint32_t a,
                   std::uint32_t b,std::uint32_t c,
                   std::uint32_t k0,std::uint32_t k1,std::uint32_t k2,
                   std::uint32_t& result){
    i.fp.load32(a);i.fp.multiply32(k0);
    i.fp.load32(c);i.fp.multiply32(k2);fp_extra::reg<0xdec1>(i.fp);
    i.fp.load32(b);i.fp.multiply32(k1);fp_extra::reg<0xdec1>(i.fp);
    fp_extra::reg<0xd9e0>(i.fp);result=i.fp.pop32();
}
}

// RVA 0x19bb20: scale each of the three fields in a row-major array of 48-byte records.
std::uint32_t fun_0059bb20(Memory& m,const Inputs& i){
    const auto object=i.cx;std::uint32_t rows=m.r32(object+8u),eax=rows;
    std::uint32_t row=0;
    if(rows){const auto columns=m.r32(object+4u);if(columns){const auto records=m.r32(object+0xcu);std::uint32_t col=0;
        do {const auto index=row*columns+col;const auto record=records+index*48u;
            for(const std::uint32_t off:{0x0cu,0x1cu,0x2cu}){i.fp.load32(i.arg[0]);i.fp.multiply32(m.r32(record+off));store_pop32(m,record+off,i);}
            ++col;if(col<columns)continue;col=0;++row;eax=m.r32(object+8u);
        } while(row<eax);
    } else {eax=rows;}}
    return eax;
}

// RVA 0x18cef0: in-place 3-vector affine update, retaining the x87 instruction order.
std::uint32_t fun_0058cef0(Memory& m,const Inputs& i){
    const auto object=i.cx,vector=i.arg[0];const auto x=m.r32(vector);
    i.fp.load32(x);fp_extra::reg<0xd9c0>(i.fp);i.fp.multiply32(m.r32(object));i.fp.add32(m.r32(object+0xcu));
    i.arg[0]=i.fp.store32();store_pop32(m,object+0xcu,i);
    fp_extra::reg<0xd9c0>(i.fp);i.fp.multiply32(m.r32(object+0x10u));i.fp.add32(m.r32(object+0x1cu));
    std::uint32_t local_y=i.fp.store32();store_pop32(m,object+0x1cu,i);
    i.fp.multiply32(m.r32(object+0x20u));i.fp.add32(m.r32(object+0x2cu));m.w32(object+0x2cu,i.fp.store32());

    i.fp.load32(m.r32(vector+4u));fp_extra::reg<0xd9c0>(i.fp);i.fp.multiply32(m.r32(object+4u));i.fp.add32(i.arg[0]);
    i.arg[0]=i.fp.store32();store_pop32(m,object+0xcu,i);
    fp_extra::reg<0xd9c0>(i.fp);i.fp.multiply32(m.r32(object+0x14u));i.fp.add32(local_y);
    local_y=i.fp.store32();store_pop32(m,object+0x1cu,i);
    i.fp.multiply32(m.r32(object+0x24u));fp_extra::reg<0xdec1>(i.fp);m.w32(object+0x2cu,i.fp.store32());

    i.fp.load32(m.r32(vector+8u));fp_extra::reg<0xd9c0>(i.fp);i.fp.multiply32(m.r32(object+8u));i.fp.add32(i.arg[0]);store_pop32(m,object+0xcu,i);
    fp_extra::reg<0xd9c0>(i.fp);i.fp.multiply32(m.r32(object+0x18u));i.fp.add32(local_y);store_pop32(m,object+0x1cu,i);
    i.fp.multiply32(m.r32(object+0x28u));fp_extra::reg<0xd8c1>(i.fp);store_pop32(m,object+0x2cu,i);
    fp_extra::reg<0xddd8>(i.fp);
    return vector;
}

// RVA 0x18e220: transform three packed vectors and negate each result before a raw copy.
std::uint32_t fun_0058e220(Memory& m,const Inputs& i){
    const auto destination=i.cx,source=i.dx;std::uint32_t input[12],result[12];
    for(unsigned n=0;n<12;++n)input[n]=m.r32(source+4u*n);
    for(unsigned row=0;row<3;++row){
        result[row*4u]=input[row];result[row*4u+1u]=input[4u+row];result[row*4u+2u]=input[8u+row];
    }
    dot3_negative(i,input[0],input[4],input[8],input[3],input[7],input[11],result[3]);
    dot3_negative(i,input[1],input[5],input[9],input[3],input[7],input[11],result[7]);
    dot3_negative(i,input[2],input[6],input[10],input[3],input[7],input[11],result[11]);
    for(unsigned n=0;n<12;++n)m.w32(destination+4u*n,result[n]);
    return destination;
}

// RVA 0x310e10: bounded palette nearest-color search using original FILD/FSUBR/FMUL/FADD x87 operations.
std::uint32_t fun_00710e10(Memory& m,const Inputs& i){
    const auto record=i.cx;const std::uint8_t mode=std::uint8_t(i.arg[3]);
    std::uint32_t ecx=mode?m.r32(record):1u;std::uint32_t best_bits=0x47c35000u;
    std::uint32_t eax=0,edi=3;std::uint32_t edx=1;
    const auto palette=m.r32(record+0x10u);
    for(;edi<0x300u;edi+=3u,++edx){
        eax=m.r32(record);
        const auto lower=m.r32(record),upper=m.r32(record+4u);
        const bool inside=s32(edx)>=s32(lower)&&s32(edx)<=s32(upper);
        if((mode&&!inside)||(!mode&&inside))continue;
        const auto pixel=palette+edi;
        std::uint32_t byte=m.r8(pixel);i.fp.load_integer32(byte);fp_extra::reverse_subtract32(i.fp,i.arg[0]);
        byte=m.r8(pixel+1u);i.fp.load_integer32(byte);fp_extra::reverse_subtract32(i.fp,i.arg[1]);
        byte=m.r8(pixel+2u);i.fp.load_integer32(byte);fp_extra::reverse_subtract32(i.fp,i.arg[2]);
        fp_extra::reg<0xd9c0>(i.fp);fp_extra::reg<0xd8c9>(i.fp);
        fp_extra::reg<0xd9c2>(i.fp);fp_extra::reg<0xd8cb>(i.fp);fp_extra::reg<0xdec1>(i.fp);
        fp_extra::reg<0xd9c3>(i.fp);fp_extra::reg<0xd8cc>(i.fp);fp_extra::reg<0xdec1>(i.fp);
        fp_extra::reg<0xdddb>(i.fp);fp_extra::reg<0xddd8>(i.fp);fp_extra::reg<0xddd8>(i.fp);
        i.fp.compare32(best_bits);const auto status=i.fp.status();eax=(pixel&0xffff0000u)|status;
        if(status&0x0100u){best_bits=i.fp.pop32();ecx=edx;}else fp_extra::reg<0xddd8>(i.fp);
    }
    return (eax&0xffffff00u)|(ecx&255u);
}
}
