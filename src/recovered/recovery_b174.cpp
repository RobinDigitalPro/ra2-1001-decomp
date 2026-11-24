#include "recovered/recovery_b174.hpp"
#include "recovered/text_bytes.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b174 {
namespace {
constexpr std::uint32_t kRootPointer=0x00a255c0u;
constexpr std::uint32_t kGlobalItem=0x0081a820u;
constexpr std::uint32_t kOptional=0x00821cacu;
constexpr std::uint32_t kLookupRoot=0x00ab7ec0u;
constexpr std::uint32_t kVtable=0x00785954u;
constexpr std::uint32_t kSlot38=0x0078598cu;
constexpr std::uint32_t kTarget=0x004e0030u;
constexpr std::uint32_t kFallback=0x007e2708u;

void require(bool ok,const char* message) { if(!ok) throw std::domain_error(message); }

void original_strncpy31(Memory& m,std::array<std::uint8_t,32>& dst,std::uint32_t src) {
    std::array<std::uint8_t,31> staged_source{};
    for(std::uint32_t n=0;n<31u;++n) staged_source[n]=static_cast<std::uint8_t>(m.r8(src+n));
    // Existing portable helper is the accepted effect model for original RVA0x36dd10.
    ra2::recovered::fun_0076dd10(dst.data(),staged_source.data(),31u);
    dst[31]=0u; // explicit root store at VA 0x6a62ed, making all32 local bytes defined
}

std::uint32_t original_2eeb60_nullroot(Memory& m) {
    // Root enters 0x2eeb60 with ECX=original source string, EDX=0, and stack args
    // 0x7e0460,0x802. EDX==0 then the PE-zero BSS [0xab7ec0] returns early.
    require(m.r32(kLookupRoot)==0u,"Block174 covers original null lookup-root only");
    return kFallback; // VA 0x6eeb79; callee RET 8 at 0x6eeb80
}

void original_296df0_and_slot38(Memory& m) {
    require(m.r32(kGlobalItem)==kVtable,"Block174 requires constructor-proven global vptr 0x785954");
    require(m.r32(kSlot38)==kTarget,"Block174 requires original .rdata slot+0x38 target 0x4e0030");
    m.w8(kGlobalItem+0x4f15u,1u); // RVA 0x296df4, before indirect call

    // Real target VA 0x4e0030: read [0x821cac], conditionally write +0xd7d,
    // then read staged [ESP+4]=0 and take JE 0x4e005b / RET 4.
    const auto optional=m.r32(kOptional);
    require(optional==0u,"Block174 follows the PE-zero optional receiver branch");
    constexpr std::uint32_t staged=0u;          // PUSH 0 at VA 0x696df2
    require(staged==0u,"Block174 follows the real target's zero-argument branch");
    // Target leaves EAX=0; helper returns without an EAX write.
}
}

// Finite source route for the original RVA 0x2a62a0.
std::uint32_t fun_006a62a0(Memory& m,const Inputs& i) {
    require(i.cx!=0u,"Block174 requires a valid input object");
    const auto source=i.cx+0x54u;
    require(m.r8(source)!=0u,"Block174 scopes nonempty ASCII input only");
    bool nul_within31=false;
    for(std::uint32_t k=1;k<=31u;++k) if(m.r8(source+k)==0u) { nul_within31=true; break; }
    require(nul_within31,"Block174 input length must be1..31");
    const auto destination=m.r32(kRootPointer);
    require(destination!=0u && std::uint64_t(destination)+0x7f8u<=0xffffffffull,
            "Block174 requires a nonwrapping synthetic output object at [0xa255c0]");
    const auto src_end=std::uint64_t(source)+31u;
    const auto out_begin=std::uint64_t(destination)+0x7d4u;
    const auto out_end=std::uint64_t(destination)+0x7f8u;
    require(src_end<=out_begin || out_end<=source,
            "Block174 excludes overlapping source and destination byte ranges");

    std::array<std::uint8_t,32> local{};
    original_strncpy31(m,local,source); // reached real helper RVA 0x36dd10, count31, then NUL at byte31
    const auto lookup_result=original_2eeb60_nullroot(m);
    m.w32(destination+0x7d4u,lookup_result); // root VA 0x6a6306
    for(std::uint32_t n=0;n<8u;++n) {       // root REP MOVSD at VA 0x6a6360
        const auto b=n*4u;
        const auto word=std::uint32_t(local[b]) |
                        (std::uint32_t(local[b+1u])<<8) |
                        (std::uint32_t(local[b+2u])<<16) |
                        (std::uint32_t(local[b+3u])<<24);
        m.w32(destination+0x7d8u+b,word);
    }
    original_296df0_and_slot38(m);
    // 0xe0030 reads staged zero into EAX and RET 4. Root then MOV AL,1;
    // the resulting full EAX is exactly 1 (not an AL-only claim).
    return 1u;
}
}



