#pragma once
#include <cstdint>
#include <stdexcept>
#include <string_view>

namespace ra2::recovered::direct_b33::integer {
// Local arithmetic state for instruction-derived control flow. This is distinct
// from State::arithmetic_flags, which remains the adapter's immutable input.
inline constexpr std::uint32_t CF=1, PF=4, AF=0x10, ZF=0x40, SF=0x80, OF=0x800;
inline constexpr std::uint32_t arithmetic_mask=CF|PF|AF|ZF|SF|OF;
inline std::uint32_t mask(unsigned width) {
    if(width!=8&&width!=16&&width!=32)throw std::invalid_argument("D33 integer width");
    return width==32?0xffffffffu:(1u<<width)-1u;
}
inline std::int64_t sign_extend(std::uint32_t value,unsigned width) {
    const auto sign=std::uint32_t(1)<<(width-1);
    return std::int64_t(value&(sign-1))-std::int64_t(value&sign);
}
inline void szp(std::uint32_t value,unsigned width,std::uint32_t& flags) {
    const auto result=value&mask(width);
    auto byte=result&255u;byte^=byte>>4;byte^=byte>>2;byte^=byte>>1;
    flags=(flags&~(SF|ZF|PF))|(result==0?ZF:0)|
        ((result&(1u<<(width-1)))?SF:0)|((byte&1u)?0:PF);
}
inline bool outside_signed(std::int64_t value,unsigned width) {
    const auto limit=std::int64_t(1)<<(width-1);
    return value < -limit || value >= limit;
}
inline std::uint32_t add(std::uint32_t a,std::uint32_t b,unsigned width,
                         std::uint32_t& flags,std::uint32_t carry=0) {
    const auto m=mask(width);a&=m;b&=m;carry&=1;
    const auto wide=std::uint64_t(a)+b+carry;
    const auto result=std::uint32_t(wide)&m;
    const auto signed_wide=sign_extend(a,width)+sign_extend(b,width)+carry;
    flags=(flags&~arithmetic_mask)|(wide>m?CF:0)|(((a^b^result)&16u)?AF:0)|
        (outside_signed(signed_wide,width)?OF:0);
    szp(result,width,flags);return result;
}
inline std::uint32_t sub(std::uint32_t a,std::uint32_t b,unsigned width,
                         std::uint32_t& flags,std::uint32_t borrow=0) {
    const auto m=mask(width);a&=m;b&=m;borrow&=1;
    const auto right=std::uint64_t(b)+borrow;
    const auto result=std::uint32_t(std::uint64_t(a)-right)&m;
    const auto signed_wide=sign_extend(a,width)-sign_extend(b,width)-borrow;
    flags=(flags&~arithmetic_mask)|(std::uint64_t(a)<right?CF:0)|
        (((a^b^result)&16u)?AF:0)|(outside_signed(signed_wide,width)?OF:0);
    szp(result,width,flags);return result;
}
inline std::uint32_t logical(std::uint32_t result,unsigned width,std::uint32_t& flags) {
    result&=mask(width);flags&=~(CF|OF);szp(result,width,flags);return result;
}
inline std::uint32_t increment(std::uint32_t a,unsigned width,std::uint32_t& flags) {
    const auto carry=flags&CF;const auto result=add(a,1,width,flags);
    flags=(flags&~CF)|carry;return result;
}
inline std::uint32_t decrement(std::uint32_t a,unsigned width,std::uint32_t& flags) {
    const auto carry=flags&CF;const auto result=sub(a,1,width,flags);
    flags=(flags&~CF)|carry;return result;
}
inline std::uint32_t imul(std::uint32_t a,std::uint32_t b,unsigned width,std::uint32_t& flags) {
    const auto product=sign_extend(a,width)*sign_extend(b,width);
    flags=(flags&~(CF|OF))|(outside_signed(product,width)?CF|OF:0);
    return std::uint32_t(product)&mask(width);
}
enum class Shift {left,right,arithmetic_right};
inline std::uint32_t shift(std::uint32_t a,std::uint32_t count,unsigned width,
                           std::uint32_t& flags,Shift kind) {
    a&=mask(width);count&=31;
    if(!count)return a;
    const bool negative=(a&(1u<<(width-1)))!=0;
    std::uint32_t result=0,carry=0;
    if(kind==Shift::left){
        result=std::uint32_t(std::uint64_t(a)<<count)&mask(width);
        if(count<=width)carry=(a>>(width-count))&1;
    }else{
        if(count<=width)carry=(a>>(count-1))&1;
        if(kind==Shift::right)result=count<width?a>>count:0;
        else if(count>=width){result=negative?mask(width):0;carry=negative?1u:0u;}
        else {result=a>>count;if(negative)result|=mask(width)^(mask(width)>>count);}
    }
    flags=(flags&~CF)|carry;
    if(count==1){
        const auto overflow=kind==Shift::left?((result>>(width-1))^carry)&1u:
                            kind==Shift::right?std::uint32_t(negative):0u;
        flags=(flags&~OF)|(overflow?OF:0);
    }
    // OF for counts >1, and CF when the architecture leaves it undefined,
    // are not a portable contract. Callers that consume them need review.
    szp(result,width,flags);return result;
}
inline bool condition(std::string_view name,std::uint32_t flags) {
    const bool zero=(flags&ZF)!=0,carry=(flags&CF)!=0,sign=(flags&SF)!=0,overflow=(flags&OF)!=0;
    if(name=="JZ"||name=="SETZ")return zero;
    if(name=="JNZ"||name=="SETNZ")return !zero;
    if(name=="JC")return carry;
    if(name=="JNC")return !carry;
    if(name=="JA")return !carry&&!zero;
    if(name=="JBE")return carry||zero;
    if(name=="JS"||name=="SETS")return sign;
    if(name=="JNS")return !sign;
    if(name=="JL")return sign!=overflow;
    if(name=="JGE")return sign==overflow;
    if(name=="JLE"||name=="SETLE")return zero||(sign!=overflow);
    if(name=="JG")return !zero&&(sign==overflow);
    throw std::invalid_argument("D33 integer condition");
}
} // namespace ra2::recovered::direct_b33::integer
