#include "recovered/rng_b70.hpp"
#include "platform/x87_b61.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::rng_b70 {
using global_b26::s32;using global_b26::sar;using global_b26::sx16;
using floating_b61::Inputs;
namespace fp_extra=ra2::platform::x87_b61;
namespace {
constexpr std::uint32_t kRngState821 = 0x00821558u;
constexpr std::uint32_t kRngLimit = 0x10000u;
constexpr std::uint32_t kRngOwnerA = 0x00a255c0u;

std::uint32_t range_rng(Memory& m, std::uint32_t state,
                        std::uint32_t low, std::uint32_t high) {
    Inputs call{};
    call.cx = state;
    call.arg[0] = low;
    call.arg[1] = high;
    return fun_0062fe40(m, call);
}

bool byte_is_nonzero(Memory& m, std::uint32_t p, std::uint32_t count) {
    for (std::uint32_t n = 0; n < count; ++n)
        if (m.r8(p + n) != 0) return true;
    return false;
}

// Local x87 semantics for the two accepted helpers called by this scoring
// route. The helper code is not invoked through its distinct B39 Memory ABI.
// These operations follow the accepted implementations in
// floating_b39_a.cpp:f_000ba080 and floating_b39_b.cpp:f_0036aa50.
void fixed_table_root(Memory& m,const Inputs& in,std::uint32_t scratch){
    constexpr std::uint32_t threshold=0x00785738u;
    in.fp.load64(floating_b61::read64(m,scratch));
    in.fp.compare32(m.r32(threshold));
    if((in.fp.status()&0x4000u)!=0){
        in.fp.pop_st0();
        in.fp.load32(m.r32(threshold));
        return;
    }
    in.fp.compare32(m.r32(threshold));
    if((in.fp.status()&0x4100u)!=0)
        in.fp.multiply64(floating_b61::read64(m,0x00788578u));
    const auto rounded_float=in.fp.pop32();
    m.w32(scratch+4u,rounded_float);
    auto ecx=rounded_float&0x007fffffu;
    auto eax=(rounded_float>>23)-0x7fu;
    if((eax&1u)!=0)ecx|=0x00800000u;
    const auto signed_half=s32(sar(sx16(eax),1u));
    ecx>>=10;
    eax=static_cast<std::uint32_t>(signed_half+0x7f);
    const auto table=m.r32(0x0080013cu+ecx*4u);
    const auto result=table+(eax<<23);
    m.w32(scratch+4u,result);
    in.fp.load32(m.r32(scratch+4u));
}
std::int32_t cached_control_integer(Memory& m,const Inputs& in,std::uint32_t scratch){
    const auto local=scratch+0x20u;
    const auto current=in.fp.control();
    m.w16(local,current);
    const auto output=local+4u;
    const auto cached=m.r16(0x007c3a04u);
    if(current!=cached){
        m.w32(local,m.r32(0x007c3a04u));
        in.fp.load_control(static_cast<std::uint16_t>(m.r32(local)));
    }
    floating_b61::write64(m,output,in.fp.pop_integer64());
    const auto converted=floating_b61::read64(m,output);
    return static_cast<std::int16_t>(static_cast<std::uint16_t>(converted));
}
std::int32_t distance_to_integer(Memory& m, const Inputs& in,
                                 std::uint32_t scratch,
                                 std::uint32_t y, std::uint32_t x){
    std::array<std::uint8_t,0x30> previous{};
    for(std::uint32_t n=0;n<previous.size();++n)previous[n]=m.r8(scratch+n);
    in.fp.load_integer32(y);
    in.fp.load_integer32(x);
    fp_extra::reg<0xd9c0>(in.fp); // FLD ST0
    fp_extra::reg<0xd8c9>(in.fp); // FMUL ST1
    fp_extra::reg<0xd9c2>(in.fp); // FLD ST2
    fp_extra::reg<0xd8cb>(in.fp); // FMUL ST3
    fp_extra::reg<0xdec1>(in.fp); // FADDP
    const auto sum=in.fp.pop64(); // FSTP double local scratch
    floating_b61::write64(m,scratch,sum);
    fp_extra::reg<0xddd8>(in.fp);
    fp_extra::reg<0xddd8>(in.fp);
    fixed_table_root(m,in,scratch);
    const auto converted=cached_control_integer(m,in,scratch);
    for(std::uint32_t n=0;n<previous.size();++n)m.w8(scratch+n,previous[n]);
    return converted;
}
}

// Original RVA 0x22fe40. The selected finite contract uses signed endpoint
// spans from 1 through 0x7ffffffe and caller-prepared states that terminate.
std::uint32_t fun_0062fe40(Memory& m, const Inputs& in) {
    auto low = in.arg[0];
    auto high = in.arg[1];
    if (s32(low) > s32(high)) { const auto t = low; low = high; high = t; }
    if (low == high) return low;

    const auto span = high - low;
    if (span == 0 || span >= 0x7fffffffu)
        throw std::domain_error("Block70 RNG endpoint span outside finite contract");

    // This mirrors the original descending TEST/SHL scan and uses the x86
    // count range explicitly; the maximum accepted shift here is 31.
    unsigned bits = 0;
    for (unsigned bit = 32; bit-- != 0;) {
        if ((span & (std::uint32_t(1) << bit)) != 0) { bits = bit + 1; break; }
    }
    const std::uint32_t mask = (std::uint32_t(1) << bits) - 1u;
    std::uint32_t result = 0;
    for (std::uint32_t attempts = 0; attempts < kRngLimit; ++attempts) {
        if (m.r8(in.cx) != 0) {
            result = 0;
        } else {
            auto index_a = m.r32(in.cx + 4u);
            auto index_b = m.r32(in.cx + 8u);
            if (index_a >= 250u || index_b >= 250u)
                throw std::domain_error("Block70 RNG state index outside 250-word table");
            const auto a = in.cx + 0x0cu + 4u * index_a;
            const auto b = in.cx + 0x0cu + 4u * index_b;
            const auto x = m.r32(a) ^ m.r32(b);
            m.w32(a, x);

            const auto old_a = m.r32(in.cx + 4u);
            const auto old_b = m.r32(in.cx + 8u);
            index_a = old_a + 1u;
            index_b = old_b + 1u;
            m.w32(in.cx + 4u, index_a);
            m.w32(in.cx + 8u, index_b);
            if (s32(index_a - 250u) < 0) { /* original JL after CMP */ }
            else { index_a = 0; m.w32(in.cx + 4u, 0); }
            if (s32(index_b - 250u) < 0) { /* original JL after CMP */ }
            else { index_b = 0; m.w32(in.cx + 8u, 0); }
            result = m.r32(a) & mask;
        }
        if (s32(result) <= s32(span)) return low + result;
    }
    throw std::domain_error("Block70 RNG fixture exceeded finite rejection bound");
}

// Original RVA 0x4b90. Reproduces the existing nonempty, remove-a-random-slot
// queue route. The route is bounded to 2..8 live entries and an enabled random
// selection state; the other queue-rebuild paths are outside this entry scope.
std::uint32_t fun_00404b90(Memory& m, const Inputs& in) {
    const auto self = in.cx;
    const auto system = m.r32(self + 0x24u);
    const auto flags = m.r32(system + 0x10u);
    const auto count = m.r32(self + 0x268u);
    const auto cursor = m.r32(self + 0x270u);
    if ((flags & 2u) == 0 || (m.r8(self + 0x18u) & 8u) != 0 ||
        count < 2 || count > 8 || cursor == 0 || cursor >= count ||
        m.r32(system + 0x138u) == 0)
        throw std::domain_error("Block70 queue call outside bounded random-removal route");

    const auto chosen = range_rng(m, kRngState821, 1, count - 1u);
    auto result = m.r32(self + 0x1e8u + chosen * 4u);
    for (auto n = chosen; n + 1u < count; ++n)
        m.w32(self + 0x1e8u + n * 4u, m.r32(self + 0x1e8u + (n + 1u) * 4u));
    m.w32(self + 0x268u, count - 1u);
    return result;
}

// Original RVA 0x1a0cc0. Pairwise distances retain the original x87 sequence
// and call the accepted fixed-table root/conversion helpers.
std::uint32_t fun_005a0cc0(Memory& m, const Inputs& in) {
    const auto out = in.arg[0];
    const auto object = in.arg[2];
    const auto bitmap = in.arg[3];
    const auto count = m.r32(object + 0x10u);
    if (s32(count) <= 0 || count > 64u)
        throw std::domain_error("Block70 point count outside finite scoring contract");
    in.fp.require_masked();
    if (in.fp.image.word(8u) != 0xffffu || in.fp.control() != 0x037fu)
        throw std::domain_error("Block70 scorer requires empty x87 stack and masked round-to-nearest");
    std::uint32_t active_count=0;
    for(std::uint32_t n=0;n<count;++n)if(m.r8(bitmap+n)!=0)++active_count;
    const auto points=m.r32(object+4u);
    std::uint32_t best=0;
    if(active_count==0){
        best=range_rng(m,m.r32(0x00a255c0u)+0x218u,0,count-1u);
    }else{
        const bool single=active_count==1u;
        bool found=false;std::uint32_t best_score=0xffffffffu;
        const auto pair_stack=in.arg[4];
        for(std::uint32_t candidate=0;candidate<count;++candidate){
            if(m.r8(bitmap+candidate)!=0)continue;
            std::uint32_t score=0;
            for(std::uint32_t point=0;point<count;++point){
                if(m.r8(bitmap+point)==0)continue;
                const auto cx=std::uint16_t(m.r16(points+4u*candidate)-m.r16(points+4u*point));
                const auto cy=std::uint16_t(m.r16(points+4u*candidate+2u)-m.r16(points+4u*point+2u));
                const auto converted=distance_to_integer(m,in,pair_stack,sx16(cy),sx16(cx));
                score+=static_cast<std::uint32_t>(converted);
            }
            if(!found || (single ? s32(score)<s32(best_score) : s32(score)>s32(best_score))){
                best=candidate;best_score=score;found=true;
            }
        }
        if(!found)throw std::domain_error("Block70 scorer requires at least one inactive candidate");
    }
    m.w8(bitmap+best,1);
    const auto value=m.r32(points+best*4u);
    m.w32(out,value);
    return out;
}

// Original RVA 0x268ca0. The sentinel-enabled route draws until the selected
// original table entry is active and not marked as unavailable.
std::uint32_t fun_00668ca0(Memory& m, const Inputs& in) {
    const auto self = in.cx;
    auto value = in.arg[0];
    if (value == 0xfffffffeu) {
        if ((in.arg[1] & 0xffu) == 0) {
            m.w32(self + 0x134u, 0);
            m.w32(self + 0x138u, 0xfffffffeu);
        } else {
            const auto max = m.r32(0x00a1e048u);
            if (max == 0 || max > 32u)
                throw std::domain_error("Block70 selector table outside finite route");
            const auto entries = m.r32(0x00a1e03cu);
            bool found = false;
            for (unsigned tries = 0; tries < kRngLimit; ++tries) {
                value = range_rng(m, m.r32(kRngOwnerA) + 0x218u, 0, max - 1u);
                const auto item = m.r32(entries + value * 4u);
                if (m.r8(item + 0x1a5u) != 0 && m.r8(item + 0x1a6u) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found) throw std::domain_error("Block70 selector fixture did not terminate");
            m.w32(self + 0x134u, value);
            m.w32(self + 0x138u, 0xfffffffeu);
        }
    } else {
        m.w32(self + 0x134u, value);
        m.w32(self + 0x138u, 0xffffffffu);
    }
    const auto result = m.r32(self + 0x134u);
    m.w32(self + 0x124u, result);
    m.w32(self + 0x128u, m.r32(self + 0x138u));
    return result;
}

// Original RVA 0x268d50. Sentinel selection excludes each matching list node
// and the eight fallback words, then publishes the accepted value.
std::uint32_t fun_00668d50(Memory& m, const Inputs& in) {
    const auto self = in.cx;
    auto value = in.arg[0];
    constexpr auto sentinel = 0xfffffffeu;
    if (value == sentinel) {
        if ((in.arg[1] & 0xffu) == 0) {
            m.w32(self + 0x12c, 0);
            m.w32(self + 0x130, sentinel);
        } else {
            bool found = false;
            for (unsigned tries = 0; tries < kRngLimit; ++tries) {
                value = range_rng(m, m.r32(kRngOwnerA) + 0x218u, 0, 7);
                bool used = false;
                const auto count = m.r32(self + 0x27f0u);
                if (count > 16u)
                    throw std::domain_error("Block70 sentinel list exceeds finite fixture bound");
                if (s32(count) > 0) {
                    auto list = m.r32(self + 0x27e4u);
                    for (std::uint32_t n = 0; n < count; ++n, list += 4u) {
                        const auto entry = m.r32(list);
                        auto candidate = m.r32(entry + 0x51u);
                        if (m.r32(entry + 0x55u) == sentinel && candidate == 0xffffffffu)
                            candidate = sentinel;
                        if (candidate == value) { used = true; break; }
                    }
                }
                for (unsigned n = 0; !used && n < 8; ++n)
                    if (m.r32(self + 0x84u + n * 4u) == value) used = true;
                if (!used) { found = true; break; }
            }
            if (!found) throw std::domain_error("Block70 sentinel fixture did not terminate");
            m.w32(self + 0x12c, value);
            m.w32(self + 0x130, sentinel);
        }
    } else {
        m.w32(self + 0x12c, value);
        m.w32(self + 0x130, 0xffffffffu);
    }
    const auto result = m.r32(self + 0x12c);
    m.w32(self + 0x11c, result);
    m.w32(self + 0x120, m.r32(self + 0x130));
    // The disabled sentinel branch only clears AL; ECX carries the copied zero.
    return in.arg[0]==sentinel && (in.arg[1]&0xffu)==0 ? 0xffffff00u : result;
}

// Original RVA 0x2e2940. Traverses the finite acyclic +0x28 chain, applies
// type-0x0d or type-0x33 tuple updates in instruction order, and clears the
// corresponding ordinal bit. The caller-stack scratch is modeled explicitly.
std::uint32_t fun_006e2940(Memory& m, const Inputs& in) {
    const auto self = in.cx;
    const auto owner = m.r32(self + 0x24u);
    auto node = m.r32(owner + 0xacu);
    std::uint32_t ordinal = 0;
    std::uint32_t eax = owner;
    for (unsigned n = 0; node != 0 && n < 16; ++n) {
        const auto type = m.r32(node + 0x2cu);
        if (type == 0x0du) {
            const auto scale = m.r32(node + 0x34u) * 15u;
            m.w32(self + 0x30u, m.r32(0x00a2896cu));
            m.w32(self + 0x34u, in.stack_minus8);
            m.w32(self + 0x38u, scale);
            m.w32(self + 0x3cu, m.r32(self + 0x3cu) & ~(1u << ordinal));
            eax = m.r32(self + 0x3cu);
        }
        if (type == 0x33u) {
            const auto value = m.r32(node + 0x34u);
            const auto random = range_rng(m, m.r32(kRngOwnerA) + 0x218u, 0, value);
            const auto half = std::uint32_t(s32(value) / 2);
            const auto scaled = (random + half) * 15u;
            m.w32(self + 0x30u, m.r32(0x00a2896cu));
            m.w32(self + 0x34u, in.stack_minus8);
            m.w32(self + 0x38u, scaled);
            const auto clear_mask = ~(1u << ordinal);
            eax = clear_mask;
            m.w32(self + 0x3cu, m.r32(self + 0x3cu) & clear_mask);
        }
        node = m.r32(node + 0x28u);
        ++ordinal;
    }
    if (node != 0) throw std::domain_error("Block70 node chain exceeded 16-node contract");
    return eax;
}
}
