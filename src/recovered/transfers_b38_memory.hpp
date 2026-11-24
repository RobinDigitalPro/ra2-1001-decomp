#pragma once
#include "recovered/direct_b34_memory.hpp"
namespace ra2::recovered::transfers_b38 {
using direct_b34::Memory; using direct_b34::State; using direct_b34::Call;
using direct_b34::Operations; using direct_b34::Boundary; using direct_b34::Frame;
using direct_b34::finish; using direct_b34::s32; using direct_b34::sar;
using direct_b34::with_al; using direct_b34::with_ax; using direct_b34::arena_bytes;
namespace integer=direct_b33::integer;
inline void invoke(Memory& m,State& s,Frame& f,const Operations& op,unsigned site,std::uint32_t target) {
    if(f.boundary_count>f.boundaries.size()||site>=f.boundary_count||target!=f.boundaries[site].target)
        throw std::invalid_argument("T38 call target differs from controlled boundary");
    direct_b34::invoke(m,s,f,op,site);
}
inline void transfer(Memory& m,State& s,Frame& f,const Operations& op,unsigned site,std::uint32_t target) {
    if(!op.invoke||f.boundary_count>f.boundaries.size()||site>=f.boundary_count)
        throw std::invalid_argument("T38 missing tail boundary");
    const auto& b=f.boundaries[site];
    if(target!=b.target||f.sp!=f.entry_sp||b.continuation!=f.outer_return||m.r32(f.sp)!=f.outer_return||
       b.argument_words>32||b.cleanup>128||(b.cleanup&3u))
        throw std::invalid_argument("T38 tail target/stack/cleanup differs");
    // Unlike CALL, JMP does not push a continuation or write guest stack bytes.
    op.invoke(m,s,{target,f.sp,b.continuation,b.argument_words,b.cleanup},op.context);
    finish(m,s,f,b.cleanup);
}
using Function=void (*)(Memory&,State&,Frame&,const Operations&);
struct Entry {std::uint32_t rva;Function function;};
const std::array<Entry,44>& entries_a();
const std::array<Entry,43>& entries_b();
}
