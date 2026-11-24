#include "floating_b61_b.hpp"
#include <array>
#include <cstdint>
namespace ra2::recovered::floating_b61 {
namespace {
inline void fmul_st4(const Inputs& i) { fp_extra::reg<0xd8cc>(i.fp); }
inline void fmul_st6(const Inputs& i) { fp_extra::reg<0xd8ce>(i.fp); }
inline void fmul_st7(const Inputs& i) { fp_extra::reg<0xd8cf>(i.fp); }
inline void fmul_st1(const Inputs& i) { fp_extra::reg<0xd8c9>(i.fp); }
inline void fmul_st3(const Inputs& i) { fp_extra::reg<0xd8cb>(i.fp); }
inline void fld_st0(const Inputs& i) { fp_extra::reg<0xd9c0>(i.fp); }
inline void fld_st1(const Inputs& i) { fp_extra::reg<0xd9c1>(i.fp); }
inline void fld_st2(const Inputs& i) { fp_extra::reg<0xd9c2>(i.fp); }
inline void fld_st3(const Inputs& i) { fp_extra::reg<0xd9c3>(i.fp); }
inline void fadd_st1(const Inputs& i) { fp_extra::reg<0xd8c1>(i.fp); }
inline void fadd_st0(const Inputs& i) { fp_extra::reg<0xdcc0>(i.fp); }
inline void fsub_st1(const Inputs& i) { fp_extra::reg<0xd8e1>(i.fp); }
inline void faddp(const Inputs& i) { fp_extra::reg<0xdec1>(i.fp); }
inline void fsubp(const Inputs& i) { fp_extra::reg<0xdee9>(i.fp); }
inline void fstp_st0(const Inputs& i) { fp_extra::reg<0xddd8>(i.fp); }
}


namespace {
inline std::uint16_t compare_float(Memory&m,const Inputs&i,std::uint32_t lhs,std::uint32_t rhs,std::uint32_t offset){
    i.fp.load32(m.r32(lhs+offset));i.fp.load32(m.r32(rhs+offset));fp_extra::reg<0xded9>(i.fp);return i.fp.status();
}
std::uint32_t sift_down(Memory&m,const Inputs&i,std::uint32_t offset){
    const auto object=i.cx;auto index=i.arg[0];auto eax=i.ax;
    for(;;){const auto count=m.r32(object);auto candidate=index;const auto left=index*2u;
        if(s32(left)<=s32(count)){auto array=m.r32(object+8u);const auto l=m.r32(array+left*4u),cur=m.r32(array+index*4u);const auto status=compare_float(m,i,l,cur,offset);eax=with_ax(cur,status);candidate=(status&0x4100u)?index:left;}
        const auto right=left+1u;if(s32(right)<=s32(count)){auto array=m.r32(object+8u);const auto r=m.r32(array+right*4u),cur=m.r32(array+candidate*4u);const auto status=compare_float(m,i,r,cur,offset);eax=with_ax(cur,status);if(!(status&0x4100u))candidate=right;}
        if(candidate==index)return eax;
        auto array=m.r32(object+8u);const auto b=m.r32(array+candidate*4u),a=m.r32(array+index*4u);m.w32(array+index*4u,b);array=m.r32(object+8u);m.w32(array+candidate*4u,a);eax=array;index=candidate;
    }
}
std::uint32_t remove_min(Memory&m,const Inputs&i){
    const auto object=i.cx;const auto count=m.r32(object);if(!count)return 0;auto array=m.r32(object+8u);const auto removed=m.r32(array+4u);const auto last=m.r32(array+count*4u);m.w32(array+4u,last);array=m.r32(object+8u);m.w32(array+count*4u,0u);const auto reduced=count-1u;m.w32(object,reduced);if(reduced<2u)return removed;
    std::uint32_t candidate=2u;array=m.r32(object+8u);const auto left=m.r32(array+8u),root=m.r32(array+4u);if(compare_float(m,i,left,root,4u)&0x4100u)candidate=1u;
    if(reduced>=3u){array=m.r32(object+8u);const auto right=m.r32(array+12u),current=m.r32(array+candidate*4u);if(!(compare_float(m,i,right,current,4u)&0x4100u))candidate=3u;}
    std::uint32_t current=1u;while(candidate!=current){array=m.r32(object+8u);const auto moving=m.r32(array+candidate*4u),parent=m.r32(array+current*4u);m.w32(array+current*4u,moving);array=m.r32(object+8u);m.w32(array+candidate*4u,parent);current=candidate;const auto now=m.r32(object),left_index=current*2u,right_index=left_index+1u;candidate=current;
        if(left_index<=now){array=m.r32(object+8u);const auto child=m.r32(array+left_index*4u),value=m.r32(array+current*4u);if(!(compare_float(m,i,child,value,4u)&0x4100u))candidate=left_index;}
        if(right_index<=now){array=m.r32(object+8u);const auto child=m.r32(array+right_index*4u),value=m.r32(array+candidate*4u);if(!(compare_float(m,i,child,value,4u)&0x4100u))candidate=right_index;}
    }
    return removed;
}
inline std::uint32_t affine_cell(const Inputs&i,std::uint32_t a0,std::uint32_t b0,std::uint32_t a1,std::uint32_t b1,std::uint32_t a2,std::uint32_t b2,bool add_translation,std::uint32_t translation){
    i.fp.load32(a1);i.fp.multiply32(b1);i.fp.load32(a2);i.fp.multiply32(b2);fp_extra::reg<0xdec1>(i.fp);i.fp.load32(a0);i.fp.multiply32(b0);fp_extra::reg<0xdec1>(i.fp);if(add_translation)i.fp.add32(translation);return i.fp.pop32();
}
}
std::uint32_t fun_0042b560(Memory&m,const Inputs&i){return sift_down(m,i,8u);}
std::uint32_t fun_0058be90(Memory&m,const Inputs&i){return sift_down(m,i,4u);}
std::uint32_t fun_0058afd0(Memory&m,const Inputs&i){return remove_min(m,i);}
std::uint32_t fun_0058df80(Memory& m, const Inputs& i) {
    std::uint32_t s[29]{};
    const std::uint32_t out = i.cx, obj = i.dx;
    std::uint32_t ecx = m.r32(obj + 0x10u);
    s[0x10/4] = ecx;
    ecx = m.r32(obj + 0x14u); s[0x0c/4] = ecx;
    ecx = m.r32(obj + 0x18u); i.fp.load32(m.r32(obj)); s[0x08/4] = ecx;
    ecx = m.r32(obj + 0x20u); i.fp.load32(m.r32(obj + 4u)); i.fp.load32(m.r32(obj + 8u)); s[0x1c/4] = ecx;
    ecx = m.r32(obj + 0x24u); s[0x18/4] = ecx;
    ecx = m.r32(obj + 0x28u); s[0x14/4] = ecx;

    ecx = i.arg[0]; i.fp.load32(m.r32(ecx)); i.fp.load32(m.r32(ecx + 0x10u)); i.fp.load32(m.r32(ecx + 0x20u));
    fld_st0(i); fmul_st4(i);
    fld_st2(i); fmul_st6(i);
    std::uint32_t esi = m.r32(ecx + 4u); s[0x24/4] = esi;
    esi = m.r32(ecx + 8u); faddp(i);
    fld_st3(i); fmul_st7(i);
    s[0x30/4] = esi;
    esi = m.r32(ecx + 0x0cu); s[0x3c/4] = esi;
    esi = m.r32(ecx + 0x14u); faddp(i); s[0x20/4] = esi;
    esi = m.r32(ecx + 0x18u); s[0x2c/4] = esi;
    esi = m.r32(ecx + 0x1cu); s[0x40/4] = i.fp.pop32(); s[0x38/4] = esi;
    esi = m.r32(ecx + 0x24u);

    fld_st0(i); i.fp.multiply32(s[0x08/4]);
    fld_st2(i); i.fp.multiply32(s[0x0c/4]);
    i.arg[0] = esi; // MOV [ESP+0x74],ESI, the original caller-stack rewrite.
    esi = m.r32(ecx + 0x28u); ecx = m.r32(ecx + 0x2cu); s[0x28/4] = esi;
    faddp(i); fld_st3(i); i.fp.multiply32(s[0x10/4]); s[0x34/4] = ecx; faddp(i);
    s[0x50/4] = i.fp.pop32();
    i.fp.multiply32(s[0x14/4]); fp_extra::reg<0xd9c9>(i.fp); i.fp.multiply32(s[0x18/4]); faddp(i);
    fp_extra::reg<0xd9c9>(i.fp); i.fp.multiply32(s[0x1c/4]); faddp(i); s[0x60/4] = i.fp.pop32();

    i.fp.load32(i.arg[0]); fmul_st1(i);
    i.fp.load32(s[0x20/4]); fmul_st3(i); faddp(i);
    i.fp.load32(s[0x24/4]); fmul_st4(i); faddp(i); s[0x44/4] = i.fp.pop32();
    i.fp.load32(i.arg[0]); i.fp.multiply32(s[0x08/4]);
    i.fp.load32(s[0x20/4]); i.fp.multiply32(s[0x0c/4]); faddp(i);
    i.fp.load32(s[0x24/4]); i.fp.multiply32(s[0x10/4]);
    std::uint32_t ecx_count = 0x0c; const std::uint32_t esi_src = 0x40;
    const std::uint32_t edi_dst = out;
    faddp(i); s[0x54/4] = i.fp.pop32();
    i.fp.load32(i.arg[0]); i.fp.multiply32(s[0x14/4]);
    i.fp.load32(s[0x20/4]); i.fp.multiply32(s[0x18/4]); faddp(i);
    i.fp.load32(s[0x24/4]); i.fp.multiply32(s[0x1c/4]); faddp(i); s[0x64/4] = i.fp.pop32();

    i.fp.load32(s[0x28/4]); fmul_st1(i);
    i.fp.load32(s[0x2c/4]); fmul_st3(i); faddp(i);
    i.fp.load32(s[0x30/4]); fmul_st4(i); faddp(i); s[0x48/4] = i.fp.pop32();
    i.fp.load32(s[0x28/4]); i.fp.multiply32(s[0x08/4]);
    i.fp.load32(s[0x2c/4]); i.fp.multiply32(s[0x0c/4]); faddp(i);
    i.fp.load32(s[0x30/4]); i.fp.multiply32(s[0x10/4]); faddp(i); s[0x58/4] = i.fp.pop32();
    i.fp.load32(s[0x28/4]); i.fp.multiply32(s[0x14/4]);
    i.fp.load32(s[0x2c/4]); i.fp.multiply32(s[0x18/4]); faddp(i);
    i.fp.load32(s[0x30/4]); i.fp.multiply32(s[0x1c/4]); faddp(i); s[0x68/4] = i.fp.pop32();

    i.fp.load32(s[0x34/4]); fmul_st1(i);
    i.fp.load32(s[0x38/4]); fmul_st3(i); faddp(i);
    i.fp.load32(s[0x3c/4]); fmul_st4(i); faddp(i); i.fp.add32(m.r32(obj + 0x0cu)); s[0x4c/4] = i.fp.pop32();
    fstp_st0(i); fstp_st0(i); fstp_st0(i);
    i.fp.load32(s[0x34/4]); i.fp.multiply32(s[0x08/4]);
    i.fp.load32(s[0x38/4]); i.fp.multiply32(s[0x0c/4]); faddp(i);
    i.fp.load32(s[0x3c/4]); i.fp.multiply32(s[0x10/4]); faddp(i); i.fp.add32(m.r32(obj + 0x1cu)); s[0x5c/4] = i.fp.pop32();
    i.fp.load32(s[0x34/4]); i.fp.multiply32(s[0x14/4]);
    i.fp.load32(s[0x38/4]); i.fp.multiply32(s[0x18/4]); faddp(i);
    i.fp.load32(s[0x3c/4]); i.fp.multiply32(s[0x1c/4]); faddp(i); i.fp.add32(m.r32(obj + 0x2cu)); s[0x6c/4] = i.fp.pop32();

    for (std::uint32_t n = 0; n < ecx_count; ++n) m.w32(edi_dst + 4u*n, s[(esi_src + 4u*n)/4u]);
    return out;
}
}
