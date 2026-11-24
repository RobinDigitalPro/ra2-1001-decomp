#pragma once
#include "recovered/direct_b34_memory.hpp"
namespace ra2::recovered::strings_b37 {
using direct_b34::Memory; using direct_b34::State; using direct_b34::Call;
using direct_b34::Operations; using direct_b34::Boundary; using direct_b34::Frame;
using direct_b34::finish; using direct_b34::s32; using direct_b34::sar;
using direct_b34::with_al; using direct_b34::with_ax; using direct_b34::arena_bytes;
namespace integer=direct_b33::integer;
// The caller computes its target before PUSH. Repeated sites retain this
// target/cleanup contract, while each dynamic boundary has a separate result.
inline void invoke(Memory& m,State& s,Frame& f,const Operations& op,unsigned site,std::uint32_t target) {
    if(f.boundary_count>f.boundaries.size()||site>=f.boundary_count||target!=f.boundaries[site].target)
        throw std::invalid_argument("S37 computed target differs from controlled boundary");
    direct_b34::invoke(m,s,f,op,site);
}
using Function=void (*)(Memory&,State&,Frame&,const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,38>& entries_a();
const std::array<Entry,37>& entries_b();
} // namespace ra2::recovered::strings_b37
