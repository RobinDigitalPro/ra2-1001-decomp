#pragma once
#include "platform/x87_state.hpp"
#include <cstdint>
#include <cstring>
#include <stdexcept>

// Restricted to frozen A39A30=A39A58=0, empty tags, frames0..79.
// These are real arithmetic operands; no expected FP image is installed.
namespace surface120fd0_fp {
namespace fp = ra2::platform::x87;
#define SURFACE120FD0_FP_CLOBBERS "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"
inline std::uint64_t initial_bounds(fp::State& state) {
    state.require_masked();
    if(state.image.word(8)!=0xffffu || (state.image.word(4)&~0x3800u)!=0)
        throw std::invalid_argument("surface120fd0 zero-domain initial FP state");
    // GAME78F5A0=0,78F5A8=57; third element receives the genuine FSTP.
    std::uint64_t operands[3]={0x0000000000000000ull,0x404c800000000000ull,0};
    fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t"
        "fldl 0(%[p])\n\tfsubl 8(%[p])\n\tfstpl 16(%[p])\n\t"
        "fnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [p]"r"(operands) : SURFACE120FD0_FP_CLOBBERS);
    return operands[2];
}
inline unsigned begin_center(fp::State& state,unsigned frame) {
    state.require_masked();
    if(frame>=80u || state.image.word(8)!=0xffffu)
        throw std::invalid_argument("surface120fd0 zero-domain center input");
    // DWORD frame@48, authentic sine scale float4522F983@52,
    // FTOL's actual cachedCW0E7F@56, arithmetic spills@64/72.
    std::uint64_t operands[10]={0,0x4043000000000000ull,0x3fbc28f5c28f5c29ull,0,0,0,
        (std::uint64_t(0x4522f983u)<<32)|frame,0x0e7full,0,0};
    fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t"
        "fildl 48(%[p])\n\tfmull 0(%[p])\n\tfsubrl 0(%[p])\n\t"
        "faddl 8(%[p])\n\tfmull 16(%[p])\n\tfstpl 64(%[p])\n\t"
        "fldl 64(%[p])\n\tfmuls 52(%[p])\n\tfldcw 56(%[p])\n\tfistpll 72(%[p])\n\t"
        "fnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [p]"r"(operands) : SURFACE120FD0_FP_CLOBBERS);
    std::int64_t converted{};std::memcpy(&converted,operands+9,8);
    if(converted!=10899)throw std::runtime_error("surface120fd0 sine conversion outside frozen domain");
    // Original positive CDQ/SUB/SAR/mask branch, then odd-value ceil.
    const unsigned converted32=static_cast<unsigned>(converted);
    unsigned index=(converted32>>1)&0x1fffu;
    if((converted32&1u) && index<0x1fffu)++index;
    return index;
}
inline std::int64_t finish_center_and_bounds(fp::State& state,unsigned sine_bits) {
    state.require_masked();
    if(state.image.word(8)!=0xffffu || sine_bits!=0xbf5c94dcu)
        throw std::invalid_argument("surface120fd0 frozen sine input");
    // Caller reads the actual frozen table DWORD at7EA104+computedIndex*4.
    // 0:sine,8:3.5,16:3,24:zero,32:25,40:1,48:.5,
    // 56:128,64:zero-global,72:1.2,80:min=-57,88:max=0,96:FISTP.
    std::uint64_t operands[13]={sine_bits,0x400c000000000000ull,0x4008000000000000ull,0,
        0x4039000000000000ull,0x3ff0000000000000ull,0x3fe0000000000000ull,
        0x4060000000000000ull,0,0x3ff3333333333333ull,0xc04c800000000000ull,0,0};
    fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t"
        "flds 0(%[p])\n\tfmull 8(%[p])\n\tfaddl 16(%[p])\n\t"
        "fldl 24(%[p])\n\tfdivl 32(%[p])\n\tfaddl 40(%[p])\n\t"
        ".byte 0xde,0xf9\n\tfaddl 48(%[p])\n\tfistpll 96(%[p])\n\t"
        "fldl 56(%[p])\n\tfsubl 64(%[p])\n\tfcompl 88(%[p])\n\t"
        "fldl 64(%[p])\n\tfaddl 88(%[p])\n\tfstpl 88(%[p])\n\t"
        "fldl 64(%[p])\n\tfmull 72(%[p])\n\tfaddl 80(%[p])\n\t"
        "fstl 80(%[p])\n\tfcompl 88(%[p])\n\t"
        "fnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [p]"r"(operands) : SURFACE120FD0_FP_CLOBBERS);
    std::int64_t intensity{};std::memcpy(&intensity,operands+12,8);
    return intensity;
}
#undef SURFACE120FD0_FP_CLOBBERS
}
