#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
#include "platform/x87_extended_b40.hpp"
#include "platform/x87_b61.hpp"
namespace ra2::recovered::floating_b61 {
using global_b26::Memory;using global_b26::s32;using global_b26::sx16;using global_b26::sx8;using global_b26::sar;
namespace fp_extra=ra2::platform::x87_b61;
namespace fp_extended=ra2::platform::x87_extended;
struct Inputs:global_b26::Inputs {mutable ra2::platform::x87::State fp;};
using Function=std::uint32_t(*)(Memory&,const Inputs&);
inline std::uint32_t with_ax(std::uint32_t x,std::uint32_t v){return (x&0xffff0000u)|(v&65535u);}
inline std::uint32_t with_al(std::uint32_t x,std::uint32_t v){return (x&0xffffff00u)|(v&255u);}
inline std::uint64_t read64(Memory&m,std::uint32_t a){const auto low=m.r32(a);return std::uint64_t(low)|(std::uint64_t(m.r32(a+4))<<32);}
inline void write64(Memory&m,std::uint32_t a,std::uint64_t v){m.w32(a,std::uint32_t(v));m.w32(a+4,std::uint32_t(v>>32));}
}
