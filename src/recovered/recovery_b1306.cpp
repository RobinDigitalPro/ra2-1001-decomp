#include "recovery_b1306.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include "platform/x87_extended_b40.hpp"
#include <stdexcept>

namespace ra2::recovered::b1306 {
namespace {
using U=std::uint32_t;
namespace fp_ext=ra2::platform::x87_extended;
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}

// Bounded positive route through the original virtual chain:
// 62E120(owner,15,candidate) -> 62DFF0 -> 40DC20(owner,15,A28820)
// -> candidate+17C/418840(action 15). Action is original stack arg1 at
// 418840, and its byte/jump tables select 418BDD.
bool eligible(Memory& m,U owner,U candidate) {
    const U owner_vptr=m.r32(owner);
    need(owner_vptr==0x0078612cu,"B1306 owner constructor-installed vptr");
    need(m.r32(owner_vptr+0x2cu)==0x0041b580u,"B1306 kind getter slot");
    need(m.r32(owner_vptr+0x258u)==0x0062e120u&&m.r32(owner_vptr+0x25cu)==0x0062dff0u,
         "B1306 original +258 wrapper and +25C target");
    const U kind=2u; // Original 41B580 returns literal 2.
    const U index=kind-1u;
    // Pinned original kind2 selector byte0 targets MOV EAX,ESI.
    const U selected=owner; // Original 40DC41: MOV EAX,ESI; RET.
    const U candidate_vptr=m.r32(candidate);
    need(candidate_vptr==0x0078612cu&&m.r32(candidate_vptr+0x17cu)==0x00418840u,
         "B1306 candidate original action-15 target");
    const U mode=m.r32(candidate+0x98u);
    if(mode==4u||(mode>25u&&mode<=27u))return false;
    constexpr U action=15u, selector=action-8u;
    // Pinned original action15 selector byte2 targets418BDD.
    const U type=m.r32(candidate+0x5acu);
    if(type==0u||selected==0u)return false;
    const U bound=m.r32(type+0x52cu);
    if(bound==0u)return false;
    need(m.r32(m.r32(selected)+0x3cu)==0x006bca10u,
         "B1306 original 4E4C20 target-argument +3C getter");
    if(m.r32(selected+0x1b4u)!=m.r32(candidate+0x1b4u))return false;
    return m.r32(candidate+0xf8u)<bound;
}

U metric(Memory& m,ra2::platform::x87::State& fp,U owner,U candidate) {
    const U dx=m.r32(candidate+0x88u)-m.r32(owner+0x88u);
    const U dy=m.r32(candidate+0x8cu)-m.r32(owner+0x8cu);
    const U dz=m.r32(candidate+0x90u)-m.r32(owner+0x90u);
    // Original FILD y,z,x; duplicate/multiply x; duplicate/multiply z;
    // add; duplicate/multiply y; add, then FSTP the double argument.
    fp.load_integer32(dy);fp.load_integer32(dz);fp.load_integer32(dx);
    fp.load_st0();fp_ext::multiply_st1(fp);
    fp.load_st2();fp_ext::multiply_st3(fp);fp.add_pop();
    fp_ext::load_st3(fp);fp_ext::multiply_st4(fp);fp.add_pop();
    const std::uint64_t square=fp.pop64();
    fp.pop_st0();fp.pop_st0();fp.pop_st0();
    // These are the separately accepted original 4BA080 table approximation
    // and 76AA50 control-word/FISTP helpers, not std::sqrt or host math.
    numeric_b88::detail::root(m,fp,square);
    return numeric_b88::detail::integer(m,fp);
}
}

U fun_00050c70(Memory& m,const Inputs& i) {
    constexpr U flag=0x00837090u,limit=0x00837030u;
    need(i.cx!=0u&&i.dx!=0u,"B1306 nonnull receiver and owner inputs");
    need((m.r8(flag)&1u)!=0u,"B1306 already-initialized threshold flag bit");
    const U count=m.r32(i.cx+0x90u);
    need(count==2u,"B1306 bounded two-candidate positive-selection fixture");
    const U array=m.r32(i.cx+0x84u);
    need(array!=0u,"B1306 nonnull candidate pointer array");
    U best=0u,best_metric=0x7fffffffu;
    for(U n=0;n<count;++n) {
        const U candidate=m.r32(array+4u*n);
        if(!eligible(m,i.dx,candidate))continue;
        const U score=metric(m,i.fp,i.dx,candidate);
        if(std::int32_t(score)<std::int32_t(best_metric)&&std::int32_t(score)<std::int32_t(m.r32(limit))) {best=candidate;best_metric=score;}
    }
    return best;
}
}
