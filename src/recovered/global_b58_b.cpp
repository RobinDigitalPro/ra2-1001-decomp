#include "global_b58_b.hpp"
#include <algorithm>
#include <cstdint>
namespace ra2::recovered::global_b26 {
namespace {
inline std::uint32_t with_al(std::uint32_t eax,std::uint32_t value){return (eax&0xffffff00u)|(value&0xffu);}
inline std::uint32_t half_toward_zero(std::uint32_t value){return sar(value-(s32(value)<0?0xffffffffu:0u),1);}
inline std::uint32_t byte_shr(std::uint32_t value,std::uint32_t count){count&=31u;return count>=8u?0u:((value&0xffu)>>count);}
inline std::uint32_t signed_index_byte(std::uint32_t v){
    v&=0x800000ffu;
    if(s32(v)<0){--v;v|=0xffffff00u;++v;}
    return v;
}
}

// RVA 0x29e2c0. Clamp a mutable signed point to integer limits assembled from
// six numeric globals; preserve wrapped LEA arithmetic and y-before-x writes.
std::uint32_t fun_0069e2c0(Memory&m,const Inputs&i){
    const auto point=i.arg[0];
    const auto a=m.r32(0x0081a918u),c=m.r32(0x0081a910u);
    auto t=(a+a)-c;t=t*3u;t=t+t*4u;
    auto lower_x=half_toward_zero(m.r32(0x00821978u))+t*2u;
    auto upper_x=m.r32(0x0081a920u);upper_x=upper_x*3u;upper_x=upper_x+upper_x*4u;upper_x<<=2;
    upper_x-=m.r32(0x00821978u);upper_x+=lower_x;
    auto ybase=c+2u*m.r32(0x0081a91cu)-5u;ybase=ybase*3u;ybase=ybase+ybase*4u;
    const auto height=m.r32(0x0082197cu);
    auto lower_y=ybase+half_toward_zero(height);
    auto upper_y=m.r32(0x0081a924u);upper_y=upper_y*3u;upper_y=upper_y+upper_y*4u;upper_y=upper_y*4u+0x10eu;
    upper_y=half_toward_zero(upper_y)-height+lower_y;
    std::uint32_t changed=0;
    auto y=m.r32(point+4u);
    if(s32(y)<s32(lower_y)){changed=1;m.w32(point+4u,lower_y);}
    else if(s32(y)>s32(upper_y)){changed=1;m.w32(point+4u,upper_y);}
    auto x=m.r32(point);
    if(s32(x)<s32(lower_x)){m.w32(point,lower_x);return with_al(x,1);}
    if(s32(x)>s32(upper_x)){m.w32(point,upper_x);return with_al(x,1);}
    return with_al(x,changed);
}

// RVA 0x292300. Update the observed timer fields through its state branches.
std::uint32_t fun_00692300(Memory&m,const Inputs&i){
    const auto p=i.cx;auto eax=i.ax;const auto bl=i.arg[0]&0xffu;
    eax=with_al(eax,m.r8(p+0x55));
    if((eax&0xffu)==0)return with_al(eax,0);
    eax=with_al(eax,m.r8(p+0x56));
    if((eax&0xffu)!=0)return with_al(eax,0);
    eax=with_al(eax,m.r8(p+0x58));
    if((bl&0xffu)==(eax&0xffu))return with_al(eax,0);
    eax=with_al(eax,m.r8(p+0x48));
    if((eax&0xffu)==0)return with_al(eax,0);
    if(bl==0){
        eax=m.r32(p+0x24);const auto source=eax;
        if(m.r8(source+0xe9u)==0){
            if(m.r32(p+0x2cu)!=0xffffffffu){m.w8(p+0x58u,bl);return with_al(eax,1);}
            m.w32(p+0x2cu,m.r32(0x00a2896cu));m.w8(p+0x58u,bl);return with_al(eax,1);
        }
    }
    const auto started=m.r32(p+0x2cu);
    if(started==0xffffffffu){m.w8(p+0x58u,bl);return with_al(eax,1);}
    eax=m.r32(p+0x34u);
    auto elapsed=m.r32(0x00a2896cu)-started;
    if(s32(elapsed)<s32(eax))eax-=elapsed;else eax=0;
    m.w32(p+0x34u,eax);m.w32(p+0x2cu,0xffffffffu);m.w8(p+0x58u,bl);
    return with_al(eax,1);
}

// RVA 0x29fb50. Append an accepted point to the fixed-stride global samples.
std::uint32_t fun_0069fb50(Memory&m,const Inputs&i){
    const auto p=i.cx;auto eax=m.r32(p+0xdb0u);
    if(eax==0x1f4u)return with_al(eax,0);
    const auto x=i.arg[1],y=i.arg[2];
    if(s32(x)<-32)return with_al(eax,0);
    auto max_x=m.r32(0x00821978u)+32u;if(s32(x)>s32(max_x))return with_al(eax,0);
    if(s32(y)<-32)return with_al(eax,0);
    auto max_y=m.r32(0x0082197cu)+32u;if(s32(y)>s32(max_y))return with_al(eax,0);
    const auto idx=eax,base=0x00aa6100u+idx*12u;
    m.w32(base,i.arg[0]);
    const auto xbase=m.r32(p+0xb0u),ybase=m.r32(p+0xb4u);
    const auto px=xbase+x,py=ybase+y;
    eax=m.r32(p+0xdb0u);const auto second=0x00aa6100u+eax*12u;
    m.w32(second+4u,px);m.w32(second+8u,py);
    eax=m.r32(p+0xdb0u)+1u;m.w32(p+0xdb0u,eax);
    return with_al(eax,1);
}

// RVA 0x273e00. Initialize fixed records while reading the original globals
// afresh at each first-loop iteration.
std::uint32_t fun_00673e00(Memory&m,const Inputs&i){
    const auto p=i.cx;const auto zero=std::uint32_t{0};
    m.w32(p,zero);m.w32(p+4u,m.r32(0x00a2896cu));m.w32(p+0xcu,zero);m.w32(p+0x10u,zero);
    m.w32(p+0x14u,1);m.w32(p+0x1cu,zero);m.w32(p+0x20u,zero);
    for(unsigned k=0;k<4;++k)m.w32(p+0x24u+k*4u,m.r32(0x00aa1188u+k*4u));
    m.w32(p+0x34u,zero);m.w8(p+0x38u,1);m.w8(p+0x39u,0);m.w8(p+0x3au,0);m.w8(p+0x3bu,0);
    m.w32(p+0x3cu,0xffffffffu);
    for(auto off:{0x40u,0x44u,0x48u,0x4cu,0x50u})m.w32(p+off,zero);
    for(unsigned k=0;k<75;++k){auto row=p+0x68u+k*0x30u;
        m.w32(row,zero);m.w32(row+4u,m.r32(0x00a2896cu));m.w32(row+0xcu,zero);m.w32(row+0x10u,zero);m.w32(row+0x14u,1);
    }
    for(unsigned k=0;k<75;++k){auto row=p+0x54u+k*0x30u;m.w32(row,zero);m.w32(row+4u,zero);m.w32(row+8u,zero);m.w32(row+0xcu,zero);}
    return p;
}

// RVA 0xabf0. Apply the original signed step table, nibble-selected weighting,
// sample clamp and index clamp; table bytes are supplied by seeded original pages.
std::uint32_t fun_0040abf0(Memory&m,const Inputs&i){
    const auto state=i.dx,index=m.r32(i.dx+4u),token=i.cx&0xffu;
    const auto step=m.r32(0x007b7fb0u+index*4u);
    auto adjust=sar(step,3);
    if(token&1u)adjust+=sar(step,2);
    if(token&2u)adjust+=sar(step,1);
    if(token&4u)adjust+=step;
    if(token&8u)adjust=0u-adjust;
    auto sample=m.r32(state)+adjust;
    m.w32(state,s32(sample)>32767?32767u:s32(sample)<-32768?0xffff8000u:sample);
    const auto delta=m.r32(0x007b7f70u+token*4u);
    auto next=index+delta;m.w32(state+4u,next);
    if(s32(next)<0)m.w32(state+4u,0);
    else if(s32(next)>0x58)m.w32(state+4u,0x58);
    return (next&0xffff0000u)|(m.r32(state)&0xffffu);
}

// RVA 0x9e870. Pack eight table-derived triplets to words; table pages remain
// original data. The architectural return is the final output AX.
std::uint32_t fun_0049e870(Memory&m,const Inputs&i){
    std::uint32_t offset=0;
    const auto input=i.arg[0];
    if(input!=0xffffffffu){offset=static_cast<std::uint32_t>(idiv_remainder(input,12u))<<3;}
    const auto holder=m.r32(0x0081a708u),out=m.r32(holder+0x174u);
    std::uint32_t eax=0;
    for(std::uint32_t k=0;k<8;++k){
        auto index=signed_index_byte(k+offset);
        const auto table=0x0081fb50u+index*3u;
        eax=signed_index_byte(k+offset);
        eax=(eax&0xffff0000u)|(m.r16(table)&0xffffu);
        const auto saved_word=eax&0xffffu;
        auto al=byte_shr(m.r8(table+2u),m.r8(0x0083b2f4u));
        eax=(eax&0xffff0000u)|al;
        eax<<=(m.r32(0x0083b2f0u)&31u);
        auto bl=byte_shr(saved_word>>8,m.r8(0x0083b2fcu));
        auto ebx=(i.ax&0xffff0000u)|bl;
        ebx=(ebx&0xffff0000u)|bl;
        ebx<<=(m.r32(0x0083b2f8u)&31u);eax|=ebx;
        bl=byte_shr(saved_word,m.r8(0x0083b2ecu));
        ebx=(ebx&0xffff0000u)|bl;
        ebx<<=(m.r32(0x0083b2e8u)&31u);eax|=ebx;
        m.w16(out+2u+k*2u,eax&0xffffu);
    }
    return m.r16(out+16u);
}
}
