#include "recovery_b268.hpp"
namespace ra2::recovered::recovery_b268 {
// Original RVA0x37295e; decimal separator placement in an already generated
// digit buffer. This is not a general floating-point-to-text conversion.
namespace {
void insert_bytes(Memory& m,std::uint32_t at,std::uint32_t count) {
    if(!count)return;
    // RVA0x372ae9 composes strlen0x375160 and overlap-safe move0x36ebd0.
    std::uint32_t length=0;while(m.r8(at+length))++length;
    for(std::uint32_t k=length+1;k;--k)m.w8(at+count+k-1,m.r8(at+k-1));
}
}
std::uint32_t fun_0077295e(Memory& m,const Inputs& i) {
    const auto out=i.arg[0],descriptor=i.arg[2];
    const auto position=m.r32(descriptor+4);
    const bool negative=m.r32(descriptor)==0x2d,alternate=(i.arg[3]&0xff)!=0;
    if(alternate && position-1==i.arg[1]) {
        const auto at=out+std::uint32_t(negative)+position-1;
        m.w8(at,'0');m.w8(at+1,0);
    }
    auto cursor=out;
    if(negative){m.w8(cursor,'-');++cursor;}
    if(s32(position)<=0){insert_bytes(m,cursor,1);m.w8(cursor,'0');++cursor;}
    else cursor+=position;
    if(s32(i.arg[1])>0) {
        insert_bytes(m,cursor,1);m.w8(cursor,m.r8(0x817770));++cursor;
        if(s32(position)<0) {
            const auto zeros=0u-position;
            if(alternate || s32(i.arg[1])>=s32(zeros))i.arg[1]=zeros;
            insert_bytes(m,cursor,i.arg[1]);
            for(std::uint32_t k=0;k<i.arg[1];++k)m.w8(cursor+k,'0');
        }
    }
    return out;
}

namespace {
// Direct bounded translation of accepted 0x37b8f5 semantics, retained here
// so no controlled callback result is substituted at the nested call.
std::uint32_t suffix_empty(Memory& m, std::uint32_t p, std::uint32_t index) {
    const auto word = index / 32u;
    const auto rem = index % 32u;
    const auto low_bits = ~(0xffffffffu << (31u - rem));
    if (m.r32(p + word * 4u) & low_bits) return 0;
    for (auto j = word + 1u; j < 3u; ++j)
        if (m.r32(p + j * 4u)) return 0;
    return 1;
}

// Composition of accepted 0x37b93e with its actual leaf 0x38040e route.
// 0x38040e stores old_word + addend and returns unsigned carry; the first
// addend is the shift-derived bit, later carry steps add one.
std::uint32_t increment_prefix(Memory& m, std::uint32_t p, std::uint32_t index) {
    const auto signed_index = global_b26::s32(index);
    auto word = static_cast<std::uint32_t>(signed_index / 32);
    const auto rem = signed_index % 32;
    const auto shift = static_cast<std::uint32_t>(31 - rem) & 31u;
    const auto first_addend = 1u << shift;
    auto ptr = p + word * 4u;
    const auto old = m.r32(ptr);
    auto sum = old + first_addend;
    m.w32(ptr, sum);
    auto carry = (sum < old || sum < first_addend) ? 1u : 0u;
    while (carry && word != 0u) {
        --word;
        ptr -= 4u;
        sum = m.r32(ptr) + 1u;
        m.w32(ptr, sum);
        carry = (sum == 0u) ? 1u : 0u;
    }
    return carry;
}
} // namespace

std::uint32_t fun_0077b994(Memory& m, const Inputs& in) {
    const auto p = in.arg[0];
    const auto index = in.arg[1];
    // Bounded contract excludes signed-IDIV faults and out-of-span indexing.
    const auto word = index / 32u;
    const auto rem = index % 32u;
    const auto bit = 1u << (31u - rem);
    // 0x77b9c9 writes the selected dword pointer over caller stack word 1.
    in.arg[1] = p + word * 4u;
    std::uint32_t saved = 0;
    if (m.r32(p + word * 4u) & bit) {
        if (!suffix_empty(m, p, index + 1u))
            saved = increment_prefix(m, p, index - 1u);
    }
    m.w32(p + word * 4u, m.r32(p + word * 4u) & (0xffffffffu << (31u - rem)));
    for (auto j = word + 1u; j < 3u; ++j) m.w32(p + j * 4u, 0u);
    return saved;
}


}
