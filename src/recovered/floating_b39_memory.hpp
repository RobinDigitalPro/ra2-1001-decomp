#pragma once
#include "recovered/direct_b34_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::floating_b39 {
using direct_b34::Memory;using direct_b34::Operations;
using direct_b34::s32;using direct_b34::sar;using direct_b34::with_al;using direct_b34::with_ax;
namespace integer=direct_b33::integer;
struct State:direct_b34::State {ra2::platform::x87::State fp;};
struct Frame:direct_b34::Frame {std::uint32_t return_sp{};};
inline void finish(Memory& m,State& s,Frame& f,std::uint32_t cleanup){
    if(f.sp!=f.return_sp || f.pop(m)!=f.outer_return)throw std::runtime_error("B39 return slot differs");
    f.sp+=cleanup;
    for(unsigned n=0;n<s.arg.size();++n)s.arg[n]=m.r32(f.entry_sp+4u+4u*n);
}
inline std::uint64_t read64(Memory& m,std::uint32_t address){
    const auto low=m.r32(address);const auto high=m.r32(address+4u);
    return std::uint64_t(low)|(std::uint64_t(high)<<32);
}
inline ra2::platform::x87::Raw80 read80(Memory& m,std::uint32_t address){
    ra2::platform::x87::Raw80 out;for(unsigned i=0;i<10;++i)out.bytes[i]=std::uint8_t(m.r8(address+i));return out;
}
inline void write64(Memory& m,std::uint32_t address,std::uint64_t value){
    m.w32(address,std::uint32_t(value));m.w32(address+4u,std::uint32_t(value>>32));
}
// Only the original literal 32-bit SHLD count 11 is used in this cohort.
// AF and multi-bit OF are undefined; preserve them without a comparison claim.
inline std::uint32_t shld11(std::uint32_t a,std::uint32_t b,std::uint32_t& flags){
    const auto result=(a<<11)|(b>>21);const auto old=flags;
    (void)integer::logical(result,32,flags);
    flags=(flags&~(integer::CF|integer::OF|integer::AF))|
        ((a>>21)&1u)|(old&(integer::OF|integer::AF));return result;
}
using Function=void(*)(Memory&,State&,Frame&,const Operations&);
struct Entry {std::uint32_t rva;Function function;};
const std::array<Entry,31>& entries_a();
const std::array<Entry,30>& entries_b();
}
