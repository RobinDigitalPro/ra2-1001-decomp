#pragma once
#include "platform/x87_state.hpp"
#include "platform/x87_b61.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::b1621_fp {
using ra2::platform::x87::Image;
using ra2::platform::x87::State;

struct Result {
    std::array<std::uint64_t,3> first{}, second{};
    std::uint64_t sum2{};
    std::array<std::uint32_t,3> converted{};
};
struct SqrtTrace { std::uint32_t input_f32{}, index{}, output_f32{}; };

inline void fcom64_nopop(State& s, std::uint64_t operand_bits) {
    s.require_masked();
    Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfcoml %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host] "=m"(host.bytes), [guest] "+m"(s.image.bytes)
        : [operand] "m"(operand_bits)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}

inline std::uint32_t ba080_positive(State& s, std::uint64_t sum_bits,
                                    const std::uint32_t table[16384], SqrtTrace& trace) {
    s.load64(sum_bits);
    const std::uint32_t zero=0, negone=0xbf800000u;
    s.compare32(zero);
    const std::uint16_t sw=s.status();
    if (sw & 0x4000u) { s.pop_st0(); s.load32(zero); trace={zero,0,zero}; return zero; }
    s.compare32(zero);
    const std::uint16_t sw2=s.status();
    if (sw2 & 0x4100u) s.multiply32(negone);
    const std::uint32_t input=s.pop32();
    trace.input_f32=input;
    int exponent=int((input>>23)&0xffu)-127;
    std::uint32_t mantissa=input&0x7fffffu;
    if(exponent&1) mantissa|=0x800000u;
    const std::uint32_t index=mantissa>>10;
    trace.index=index;
    const std::int16_t half=static_cast<std::int16_t>(static_cast<std::int16_t>(exponent)>>1);
    const std::uint32_t e=static_cast<std::uint32_t>(static_cast<std::int32_t>(half)+0x7f);
    const std::uint32_t result=(e<<23)+table[index];
    trace.output_f32=result;
    s.load32(result);
    return result;
}

inline void root_normalize(State& s, std::uint64_t& r, std::uint64_t& g,
                           std::uint64_t& b, std::uint64_t scale240,
                           std::uint64_t max255, std::uint64_t lower96) {
    const std::uint64_t zero=0;
    fcom64_nopop(s,zero); (void)s.status();
    s.load64(r); s.multiply64(scale240); ra2::platform::x87_b61::reg<0xd8f1>(s); r=s.store64(); s.compare_pop64(max255); (void)s.status();
    s.load64(g); s.multiply64(scale240); ra2::platform::x87_b61::reg<0xd8f1>(s); g=s.store64(); s.compare_pop64(max255); (void)s.status();
    s.load64(b); s.multiply64(scale240); s.reverse_divide_pop(); (void)s.status(); fcom64_nopop(s,max255); b=s.store64(); (void)s.status();
    s.load64(r); s.compare_pop64(lower96); (void)s.status();
    s.load64(g); s.compare_pop64(lower96); (void)s.status();
    s.compare_pop64(lower96); (void)s.status();
}

inline std::uint64_t f4990_sum(State& s, std::uint64_t r, std::uint64_t g,
                               std::uint64_t b) {
    s.load64(g); s.load64(b); s.load64(r);
    ra2::platform::x87_b61::reg<0xd9c0>(s); ra2::platform::x87_b61::reg<0xd8c9>(s);
    ra2::platform::x87_b61::reg<0xd9c2>(s); ra2::platform::x87_b61::reg<0xd8cb>(s);
    ra2::platform::x87_b61::reg<0xdec1>(s);
    ra2::platform::x87_b61::reg<0xd9c3>(s); ra2::platform::x87_b61::reg<0xd8cc>(s);
    ra2::platform::x87_b61::reg<0xdec1>(s);
    const std::uint64_t sum=s.pop64();
    ra2::platform::x87_b61::reg<0xddd8>(s); ra2::platform::x87_b61::reg<0xddd8>(s); ra2::platform::x87_b61::reg<0xddd8>(s);
    return sum;
}

inline void f4990_normalize(State& s, std::uint64_t& r, std::uint64_t& g,
                            std::uint64_t& b, std::uint64_t scale240,
                            std::uint64_t max255, std::uint64_t lower_zero,
                            const std::uint32_t table[16384], SqrtTrace& trace,
                            std::uint64_t& sum_out) {
    sum_out=f4990_sum(s,r,g,b);
    (void)ba080_positive(s,sum_out,table,trace);
    fcom64_nopop(s,lower_zero); (void)s.status();
    s.load64(r); s.multiply64(scale240); ra2::platform::x87_b61::reg<0xd8f1>(s); r=s.store64(); s.compare_pop64(max255); (void)s.status();
    s.load64(g); s.multiply64(scale240); ra2::platform::x87_b61::reg<0xd8f1>(s); g=s.store64(); s.compare_pop64(max255); (void)s.status();
    s.load64(b); s.multiply64(scale240); s.reverse_divide_pop(); b=s.store64(); s.compare_pop64(max255); (void)s.status();
}

inline std::uint64_t convert76aa50(State& s, std::uint64_t bits) {
    constexpr std::uint16_t target=0x0e7f;
    s.load64(bits);
    if(s.control()!=target) s.load_control_masked(target);
    return s.pop_integer64();
}

inline Result run(State& s,const std::uint32_t* table) {
    constexpr std::uint64_t scale240=0x406e000000000000ull;
    constexpr std::uint64_t max255=0x406fe00000000000ull;
    constexpr std::uint64_t lower96=0x4058000000000000ull;
    constexpr std::uint32_t r8=24,g8=24,b8=28;
    Result out{};
    s.load_integer32(r8); out.first[0]=s.store64();
    s.load_integer32(g8); out.first[1]=s.store64();
    s.load_integer32(b8); out.first[2]=s.store64();
    ra2::platform::x87_b61::reg<0xd9c0>(s); ra2::platform::x87_b61::reg<0xd8c9>(s);
    ra2::platform::x87_b61::reg<0xd9c2>(s); ra2::platform::x87_b61::reg<0xd8cb>(s);
    ra2::platform::x87_b61::reg<0xdec1>(s);
    ra2::platform::x87_b61::reg<0xd9c3>(s); ra2::platform::x87_b61::reg<0xd8cc>(s);
    ra2::platform::x87_b61::reg<0xdec1>(s);
    const std::uint64_t root_sum=s.pop64();
    ra2::platform::x87_b61::reg<0xddd8>(s); ra2::platform::x87_b61::reg<0xddd8>(s); ra2::platform::x87_b61::reg<0xddd8>(s);
    SqrtTrace first_sqrt{}; (void)ba080_positive(s,root_sum,table,first_sqrt);
    root_normalize(s,out.first[0],out.first[1],out.first[2],scale240,max255,lower96);
    out.second=out.first;
    SqrtTrace second_sqrt{};
    f4990_normalize(s,out.second[0],out.second[1],out.second[2],scale240,max255,0,table,second_sqrt,out.sum2);
    out.converted[2]=static_cast<std::uint32_t>(convert76aa50(s,out.second[2]));
    out.converted[1]=static_cast<std::uint32_t>(convert76aa50(s,out.second[1]));
    out.converted[0]=static_cast<std::uint32_t>(convert76aa50(s,out.second[0]));
    return out;
}
}
