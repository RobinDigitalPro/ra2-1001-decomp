#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::global_b26 {
namespace {
bool signed_in_half_open(std::uint32_t value, std::uint32_t first, std::uint32_t span) {
    const std::uint32_t end = first + span;
    return s32(value) >= s32(first) && s32(value) < s32(end);
}
bool signed_in_either(std::uint32_t value, std::uint32_t a, std::uint32_t an,
                      std::uint32_t b, std::uint32_t bn) {
    return signed_in_half_open(value, a, an) || signed_in_half_open(value, b, bn);
}
std::uint32_t set_low_byte(std::uint32_t eax, std::uint32_t value) {
    return (eax & 0xffffff00u) | (value & 0xffu);
}
std::uint32_t signed_delta_remaining(std::uint32_t global, std::uint32_t cursor,
                                     std::uint32_t amount) {
    const std::uint32_t delta = global - cursor;
    return s32(delta) >= s32(amount) ? 0u : amount - delta;
}
}

std::uint32_t fun_00405110(Memory&m,const Inputs&i){auto gate=m.r32(0x008192f8u);return gate?m.r32(i.cx+0x50u):0u;}
std::uint32_t fun_00405140(Memory&m,const Inputs&i){auto gate=m.r32(0x008192f8u);return gate?m.r32(i.cx+0x14u):0u;}
std::uint32_t fun_00405150(Memory&m,const Inputs&i){if(m.r32(0x008192f8u)==0)return 0x007b7c64u;return i.cx+0x6cu;}
std::uint32_t fun_00406140(Memory&m,const Inputs&i){
    auto eax=m.r32(0x008192f8u);
    if(!eax || m.r32(i.cx+0x0cu)!=0x008192ecu)return 0u;
    eax=m.r32(i.cx);
    if(!eax)return 0u;
    if(m.r32(i.cx+8u)!=m.r32(eax+0x24u) || m.r32(i.cx+4u)!=m.r32(eax+0x138u)){
        m.w32(i.cx,0);return 0u;
    }
    return eax;
}
std::uint32_t fun_00406180(Memory&m,const Inputs&i){
    if(m.r32(0x008192f8u)==0 || m.r32(i.cx+0x0cu)!=0x008192ecu)return 0u;
    return m.r32(i.cx+8u);
}
std::uint32_t fun_00406f30(Memory&m,const Inputs&){return m.r32(0x00819778u)!=0?1u:0u;}
std::uint32_t fun_00417890(Memory&m,const Inputs&){auto p=m.r32(0x00821b88u);return m.r32(p+0x50u);}
std::uint32_t fun_00420d30(Memory&m,const Inputs&i){
    if(!i.cx)return i.ax;
    const auto count=m.r32(0x00a285c0u);
    if(s32(count)<=0)return count;
    auto base=m.r32(0x00a285b4u);
    std::uint32_t eax=count,n=0;
    do {
        const auto p=m.r32(base+n*4u);
        if(m.r32(p+0xb4u)==i.cx)m.w8(p+0x175u,0);
        ++n;
        eax=m.r32(0x00a285c0u);
    } while(s32(n)<s32(eax));
    return eax;
}
std::uint32_t fun_00428a90(Memory&m,const Inputs&i){
    const auto b=sx16(m.r16(i.cx+2u));const auto a=sx16(m.r16(i.cx));const auto scale=m.r32(0x0081a910u);
    auto x=(a-b)+scale-1u;auto y=(a-scale)+b-1u;
    y=static_cast<std::uint32_t>(static_cast<std::uint64_t>(y)*scale);
    return y+sar(x,1);
}
std::uint32_t fun_00428ac0(Memory&m,const Inputs&){auto eax=m.r32(0x0081a914u)+4u;eax=static_cast<std::uint32_t>(static_cast<std::uint64_t>(eax)*m.r32(0x0081a910u));return eax<<1;}
std::uint32_t fun_00432c50(Memory&m,const Inputs&i){
    auto eax=sar(i.arg[0],m.r32(0x0083b2f4u));eax<<=(m.r32(0x0083b2f0u)&31u);
    auto edx=sar(i.dx,m.r32(0x0083b2fcu));edx<<=(m.r32(0x0083b2f8u)&31u);
    auto esi=sar(i.cx,m.r32(0x0083b2ecu));esi<<=(m.r32(0x0083b2e8u)&31u);
    return eax|edx|esi;
}
std::uint32_t fun_00435ec0(Memory&m,const Inputs&i){
    if(m.r32(i.cx+0x30u)==1u)return 12u;
    auto p=m.r32(0x00821b88u);auto object_delta=m.r32(i.cx+0x34u);
    auto denominator=m.r32(p+0xc90u);auto scale=m.r32(p+0xc98u);auto global=m.r32(0x00a2896cu);
    const auto high=imul_high(0x2aaaaaabu,denominator);
    denominator=high+((high>>31)&1u);
    const auto first_q=idiv_quotient(global-object_delta,denominator);
    const auto second_divisor=scale+scale;
    const auto remainder=idiv_remainder(global,second_divisor);
    auto result=first_q<<1;
    if(s32(remainder)>=s32(scale))++result;
    return s32(result)<12?result:11u;
}
std::uint32_t fun_00435f30(Memory&m,const Inputs&i){
    auto eax=m.r32(i.cx+0x30u);
    if(eax)return eax&0xffffff00u;
    eax=m.r32(0x00a2896cu);
    if(s32(eax)<=s32(m.r32(i.cx+0x38u)))return eax&0xffffff00u;
    if(m.r8(i.cx+0x58u)!=0)return eax&0xffffff00u;
    return set_low_byte(eax,1u);
}
std::uint32_t fun_00453b30(Memory&m,const Inputs&i){
    const auto d=m.r32(i.cx);auto eax=m.r32(i.cx+8u);
    if(d==0xffffffffu)return eax;
    const auto delta=m.r32(0x00a2896cu)-d;
    return s32(delta)>=s32(eax)?0u:eax-delta;
}
std::uint32_t fun_004576d0(Memory&m,const Inputs&i){
    std::uint32_t index=0;std::uint32_t cursor=0x007babdcu;
    while(cursor<0x007bac0cu){
        if(m.r32(cursor)==i.cx)return m.r32(0x007babd8u+index*8u);
        cursor+=8u;++index;
    }
    return m.r32(0x007babd8u);
}
std::uint32_t fun_0045e9c0(Memory&m,const Inputs&i){
    const auto count=sx16(m.r16(i.cx+6u));const auto index=i.arg[1];const auto out=i.arg[0];
    if(index>=count){m.w32(out,m.r32(0x008370c8u));m.w32(out+4u,m.r32(0x008370ccu));m.w32(out+8u,m.r32(0x008370d0u));m.w32(out+12u,m.r32(0x008370d4u));return out;}
    const auto p=i.cx+8u+index*24u;
    if(p==0){m.w32(out,m.r32(0x008370c8u));m.w32(out+4u,m.r32(0x008370ccu));m.w32(out+8u,m.r32(0x008370d0u));m.w32(out+12u,m.r32(0x008370d4u));return out;}
    const auto a=sx16(m.r16(p));const auto b=sx16(m.r16(p+2u));const auto c=sx16(m.r16(p+4u));const auto d=sx16(m.r16(p+6u));
    m.w32(out,a);m.w32(out+4u,b);m.w32(out+8u,c);m.w32(out+12u,d);return out;
}
std::uint32_t fun_00463bb0(Memory&m,const Inputs&i){const auto arg=i.arg[0];const auto value=m.r32(0x00a2896cu);m.w32(i.cx,value);m.w32(i.cx+8u,arg);return i.cx;}
std::uint32_t fun_00465820(Memory&m,const Inputs&i){m.w32(i.cx,0x00788724u);m.w32(i.cx+4u,0);m.w32(0x00838850u,0);m.w32(0x007bc418u,0xffffffffu);return i.cx;}
std::uint32_t fun_00466e30(Memory&m,const Inputs&i){m.w32(i.cx,0x00788730u);m.w32(0x00838818u,0xffffffffu);m.w32(0x00838830u,0);m.w32(0x008387e4u,0);return i.cx;}
std::uint32_t fun_0046e0d0(Memory&m,const Inputs&i){const auto al=m.r8(0x00838b70u);m.w32(0x007bd078u,0xfffffffeu);if(al!=1u)m.w32(0x007bd078u,i.cx);return (i.ax&0xffffff00u)|al;}
std::uint32_t fun_0046fce0(Memory&m,const Inputs&i){const auto old=m.r32(0x00838be4u);m.w32(0x00838be4u,i.cx);m.w32(0x00838be8u,old);return old;}
std::uint32_t fun_004798c0(Memory&m,const Inputs&i){
    const auto n=sx16(m.r16(i.cx+0x116u));if(s32(n)<0)return 0;
    if(s32(n)>=s32(m.r32(0x0084e508u)))return 0;
    return m.r32(i.cx+0xecu)==10u?1u:0u;
}
std::uint32_t fun_00479d30(Memory&m,const Inputs&i){
    const auto n=sx16(m.r16(i.cx+0x116u));if(s32(n)<0 || s32(n)>=s32(m.r32(0x0084e508u)))return 0;
    const auto base=m.r32(0x0084e4fcu);return m.r32(base+n*4u);
}
std::uint32_t fun_00479e70(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return signed_in_half_open(v,m.r32(0x00a3a1b8u),0xeu)?1u:0u;}
std::uint32_t fun_0047b1b0(Memory&m,const Inputs&i){auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_either(v,m.r32(0x00a55c50u),0x14u,m.r32(0x00a3aae0u),0xcu)?1u:0u);}
std::uint32_t fun_0047b3c0(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a547acu),0x2au)?1u:0u);}
std::uint32_t fun_0047b3e0(Memory&m,const Inputs&i){
    const auto v=m.r32(i.cx+0x38u);
    const bool hit=signed_in_half_open(v,m.r32(0x00a547acu),0x2au) ||
                   signed_in_half_open(v,m.r32(0x00a3a1b8u),0xeu) ||
                   signed_in_half_open(v,m.r32(0x00a3a1bcu),4u) ||
                   signed_in_half_open(v,m.r32(0x00a54b90u),4u) ||
                   signed_in_half_open(v,m.r32(0x00a3aad8u),4u) ||
                   signed_in_half_open(v,m.r32(0x00a3ab28u),4u);
    return set_low_byte(v,hit?1u:0u);
}
std::uint32_t fun_0047b460(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a3ab2cu),0xeu)?1u:0u);}
std::uint32_t fun_0047b480(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a55d18u),0x10u)?1u:0u);}
std::uint32_t fun_0047b4e0(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a55944u),0xfu)?1u:0u);}
std::uint32_t fun_0047b500(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a55940u),4u)?1u:0u);}
std::uint32_t fun_0047b540(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a3a8a4u),0xeu)?1u:0u);}
std::uint32_t fun_0047b560(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a3a8b0u),0x10u)?1u:0u);}
std::uint32_t fun_0047b580(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a547a0u),0x10u)?1u:0u);}
std::uint32_t fun_0047b5a0(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);return set_low_byte(v,signed_in_half_open(v,m.r32(0x00a3a8acu),0x10u)?1u:0u);}
std::uint32_t fun_0047b5c0(Memory&m,const Inputs&i){auto v=m.r32(i.cx+0x38u);const bool hit=v==m.r32(0x00a3a898u)||signed_in_half_open(v,m.r32(0x00a3a1c8u),0x10u);return set_low_byte(v,hit?1u:0u);}
std::uint32_t fun_0047b710(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x38u);const auto g=m.r32(0x00a55d30u);return set_low_byte(v,(v==g || v==g+1u)?1u:0u);}
std::uint32_t fun_00496850(Memory&m,const Inputs&i){m.w32(i.cx+8u,m.r32(0x00a2896cu));m.w32(i.cx+0x10u,0);m.w32(i.cx+0x14u,0);m.w8(i.cx+0x18u,0);m.w8(i.cx+0x19u,0);return i.cx;}
std::uint32_t fun_004969f0(Memory&m,const Inputs&i){
    auto eax=set_low_byte(i.ax,m.r8(i.cx+0x18u));if(m.r8(i.cx+0x18u)==0)return eax;
    eax=m.r32(i.cx+0x10u);const auto ptr=m.r32(i.cx+8u);
    if(ptr!=0xffffffffu)eax=signed_delta_remaining(m.r32(0x00a2896cu),ptr,eax);
    auto edx=m.r32(i.cx+0x14u)-eax;m.w32(i.cx+0x10u,edx);
    auto al=m.r8(i.cx+0x19u);al=al==0?1u:0u;m.w8(i.cx+0x19u,al);return set_low_byte(eax,al);
}
std::uint32_t fun_004a4a30(Memory&m,const Inputs&i){const auto cursor=m.r32(i.cx);const auto amount=m.r32(i.cx+8u);if(cursor==0xffffffffu)return amount;return signed_delta_remaining(m.r32(0x00a2896cu),cursor,amount);}
std::uint32_t fun_004a6620(Memory&m,const Inputs&i){m.w32(i.cx,m.r32(0x00a2896cu));m.w32(i.cx+8u,0x7fffffffu);m.w8(i.cx+0xcu,0);m.w32(i.cx+0x10u,0);m.w32(i.cx+0x28u,0);return i.cx;}
std::uint32_t fun_004b5e80(Memory&m,const Inputs&i){
    const auto out=i.cx;const auto a0=i.arg[0];
    if(s32(a0)<0){m.w8(out+2u,0xff);m.w8(out,0);m.w32(out+3u,m.r32(0x00a2896cu));return out;}
    m.w8(out+2u,a0);m.w8(out,4);m.w8(out+0x1du,0);m.w32(out+7u,i.arg[1]);m.w8(out+0xbu,i.arg[2]);m.w8(out+0xcu,i.arg[3]);m.w32(out+0xeu,i.arg[4]);m.w8(out+0x12u,i.arg[5]);m.w32(out+0x13u,i.arg[6]);m.w8(out+0x17u,i.arg[7]);m.w32(out+0x18u,i.arg[8]);m.w8(out+0x1cu,i.arg[9]);m.w32(out+3u,m.r32(0x00a2896cu));return out;
}
std::uint32_t fun_004b8640(Memory&m,const Inputs&i){m.w16(i.cx,0);m.w16(i.cx+4u,0);const auto global=m.r32(0x00a2896cu);m.w32(i.cx+0x10u,0);m.w32(i.cx+8u,global);m.w16(i.cx+0x14u,0);return i.cx;}
std::uint32_t fun_004b8660(Memory&m,const Inputs&i){
    m.w16(i.cx,0);m.w16(i.cx+4u,0);const auto global=m.r32(0x00a2896cu);m.w32(i.cx+0x10u,0);m.w32(i.cx+8u,global);m.w16(i.cx+0x14u,0);
    auto value=i.arg[0];if(s32(value)>=0x7f)value=0x7f;const auto dx=(value&0xffu)<<8;m.w16(i.cx+0x14u,dx);return i.cx;
}
std::uint32_t fun_004b8900(Memory&m,const Inputs&i){
    if(s32(sx16(m.r16(i.cx+0x14u)))<=0)return 0;
    auto cursor=m.r32(i.cx+8u);auto amount=m.r32(i.cx+0x10u);
    if(cursor!=0xffffffffu){const auto delta=m.r32(0x00a2896cu)-cursor;if(s32(delta)>=s32(amount))return 0;amount-=delta;}
    return amount?1u:0u;
}
std::uint32_t fun_004b8930(Memory&m,const Inputs&i){
    auto eax=i.ax;if(s32(sx16(m.r16(i.cx+0x14u)))<=0)return set_low_byte(eax,0);
    auto cursor=m.r32(i.cx+8u);eax=m.r32(i.cx+0x10u);
    if(cursor!=0xffffffffu){const auto delta=m.r32(0x00a2896cu)-cursor;if(s32(delta)>=s32(eax))return set_low_byte(eax,0);eax-=delta;}
    if(eax==0)return set_low_byte(eax,0);
    const auto lhs=m.r16(i.cx);const auto rhs=m.r16(i.cx+4u);const auto diff=static_cast<std::uint16_t>(lhs-rhs);
    // TEST AX,AX resets OF after the wrapped SUB, so SETG tests the
    // signed wrapped result itself, not the original operand ordering.
    eax=(eax&0xffff0000u)|diff;return set_low_byte(eax,(diff!=0 && (diff&0x8000u)==0)?1u:0u);
}
std::uint32_t fun_004b8970(Memory&m,const Inputs&i){
    auto eax=i.ax;if(s32(sx16(m.r16(i.cx+0x14u)))<=0)return set_low_byte(eax,0);
    auto cursor=m.r32(i.cx+8u);eax=m.r32(i.cx+0x10u);
    if(cursor!=0xffffffffu){const auto delta=m.r32(0x00a2896cu)-cursor;if(s32(delta)>=s32(eax))return set_low_byte(eax,0);eax-=delta;}
    if(eax==0)return set_low_byte(eax,0);
    eax=0;const auto diff=static_cast<std::uint16_t>(m.r16(i.cx)-m.r16(i.cx+4u));return (diff&0x8000u)?1u:0u;
}
std::uint32_t fun_004b92a0(Memory&m,const Inputs&i){
    auto eax=set_low_byte(i.ax,m.r8(i.cx+0x6cu));if(m.r8(i.cx+0x6cu)!=0)return set_low_byte(eax,0);
    const auto argbyte=i.arg[0]&0xffu;m.w8(i.cx+0x6du,argbyte);m.w8(i.cx+0x6cu,1);
    auto temp=m.r32(0x00a2896cu);m.w32(i.cx+0x34u,0);m.w32(i.cx+0x28u,temp);m.w32(i.cx+0x2cu,i.stack_minus8);eax=set_low_byte(i.stack_minus8,1);m.w32(i.cx+0x30u,0);return eax;
}
std::uint32_t fun_004ce9d0(Memory&m,const Inputs&i){m.w32(i.cx,m.r32(0x00a2896cu));m.w32(i.cx+8u,0);m.w32(i.cx+0xcu,m.r32(0x00a2896cu));m.w32(i.cx+0x14u,0);m.w32(i.cx+0x18u,0);m.w32(i.cx+0x1cu,0);m.w32(i.cx+0x20u,0);m.w32(i.cx+0x24u,0);return i.cx;}
std::uint32_t fun_004cf1f0(Memory&m,const Inputs&i){if(m.r32(0x0084e328u)!=i.cx)return i.ax;auto eax=m.r32(i.cx+0x20u)&~0x100u;m.w32(i.cx+0x20u,eax);m.w32(0x0084e328u,0);return eax;}
std::uint32_t fun_004cf210(Memory&m,const Inputs&i){const auto v=m.r32(0x0084e328u);return i.cx==v?1u:0u;}
std::uint32_t fun_004e0750(Memory&m,const Inputs&i){
    if((m.r8(0x00a2896cu)&1u)!=0)return i.ax;
    auto eax=m.r32(i.cx+4u);if(eax!=0)m.w32(i.cx+4u,(s32(eax)<0?0xffffffffu:1u)-eax);
    eax=m.r32(i.cx+8u);if(eax!=0)m.w32(i.cx+8u,(s32(eax)<0?0xffffffffu:1u)-eax);
    return eax;
}
std::uint32_t fun_004e73d0(Memory&m,const Inputs&i){
    auto eax=set_low_byte(i.ax,m.r8(i.cx+0x13fu));
    if(m.r8(i.cx+0x13fu)!=0 || m.r8(i.cx+0x13eu)!=0 || m.r8(i.cx+0x140u)!=0){return set_low_byte(i.ax,m.r8(i.cx+0x13eu));}
    m.w8(i.cx+0x13eu,1);m.w32(i.cx+0x1e0u,m.r32(0x00a2896cu));m.w32(i.cx+0x1e4u,i.stack_minus8);eax=set_low_byte(i.stack_minus8,m.r8(i.cx+0x13eu));m.w32(i.cx+0x1e8u,0);return eax;
}
std::uint32_t fun_004ecc60(Memory&m,const Inputs&i){
    const auto count=m.r32(0x00a1a5d8u);if(s32(count)<=0)return 0;
    auto base=m.r32(0x00a1a5ccu);
    for(std::uint32_t n=0;n<count;++n){const auto p=m.r32(base+n*4u);const auto q=m.r32(p+0x34u);if(m.r32(q+0xb8u)==i.cx)return p;}
    return 0;
}
std::uint32_t fun_004f2620(Memory&m,const Inputs&i){
    const auto index=m.r32(i.cx+0x154u);if(s32(index)<0 || s32(index)>=12)return index&0xffffff00u;
    const auto p=m.r32(i.cx+0x158u+index*4u);const auto q=m.r32(0x00821b88u);
    if(s32(m.r32(p+0x38u))>=s32(m.r32(q+0x98u)) || m.r32(p+0x24u)!=0xffffffffu)return 0;
    return 1;
}

const std::array<Entry,55>& entries_a(){
    static const std::array<Entry,55> e{{
        {0x5110u,&fun_00405110},{0x5140u,&fun_00405140},{0x5150u,&fun_00405150},{0x6140u,&fun_00406140},{0x6180u,&fun_00406180},
        {0x6f30u,&fun_00406f30},{0x17890u,&fun_00417890},{0x20d30u,&fun_00420d30},{0x28a90u,&fun_00428a90},{0x28ac0u,&fun_00428ac0},
        {0x32c50u,&fun_00432c50},{0x35ec0u,&fun_00435ec0},{0x35f30u,&fun_00435f30},{0x53b30u,&fun_00453b30},{0x576d0u,&fun_004576d0},
        {0x5e9c0u,&fun_0045e9c0},{0x63bb0u,&fun_00463bb0},{0x65820u,&fun_00465820},{0x66e30u,&fun_00466e30},{0x6e0d0u,&fun_0046e0d0},
        {0x6fce0u,&fun_0046fce0},{0x798c0u,&fun_004798c0},{0x79d30u,&fun_00479d30},{0x79e70u,&fun_00479e70},{0x7b1b0u,&fun_0047b1b0},
        {0x7b3c0u,&fun_0047b3c0},{0x7b3e0u,&fun_0047b3e0},{0x7b460u,&fun_0047b460},{0x7b480u,&fun_0047b480},{0x7b4e0u,&fun_0047b4e0},
        {0x7b500u,&fun_0047b500},{0x7b540u,&fun_0047b540},{0x7b560u,&fun_0047b560},{0x7b580u,&fun_0047b580},{0x7b5a0u,&fun_0047b5a0},
        {0x7b5c0u,&fun_0047b5c0},{0x7b710u,&fun_0047b710},{0x96850u,&fun_00496850},{0x969f0u,&fun_004969f0},{0xa4a30u,&fun_004a4a30},
        {0xa6620u,&fun_004a6620},{0xb5e80u,&fun_004b5e80},{0xb8640u,&fun_004b8640},{0xb8660u,&fun_004b8660},{0xb8900u,&fun_004b8900},
        {0xb8930u,&fun_004b8930},{0xb8970u,&fun_004b8970},{0xb92a0u,&fun_004b92a0},{0xce9d0u,&fun_004ce9d0},{0xcf1f0u,&fun_004cf1f0},
        {0xcf210u,&fun_004cf210},{0xe0750u,&fun_004e0750},{0xe73d0u,&fun_004e73d0},{0xecc60u,&fun_004ecc60},{0xf2620u,&fun_004f2620},
    }};
    return e;
}
} // namespace ra2::recovered::global_b26
