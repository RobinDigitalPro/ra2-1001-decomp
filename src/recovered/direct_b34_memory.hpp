#pragma once
#include "recovered/direct_b33_memory.hpp"
#include "recovered/direct_b33_integer.hpp"

namespace ra2::recovered::direct_b34 {
using direct_b33::Memory;
using direct_b33::State;
using direct_b33::Call;
using direct_b33::Operations;
using direct_b33::finish;
using direct_b33::s32;
using direct_b33::sar;
using direct_b33::with_al;
using direct_b33::with_ax;
using direct_b33::arena_bytes;
namespace integer = direct_b33::integer;

// Each slot corresponds to one original encoded E8 instruction in address
// order. Targets/continuations share the caller's relocation. Cleanup and
// observed words describe the controlled test boundary, not a recovered ABI.
struct Boundary {
    std::uint32_t target{}, continuation{}, cleanup{}, argument_words{};
};
struct Frame : direct_b33::Frame {
    std::array<Boundary,8> boundaries{};
    std::uint32_t boundary_count{};
};
inline void invoke(Memory& m,State& s,Frame& f,const Operations& op,unsigned site) {
    if(f.boundary_count>f.boundaries.size() || site>=f.boundary_count)
        throw std::invalid_argument("D34 missing encoded call boundary");
    const auto& b=f.boundaries[site];
    f.direct_target=b.target; f.call_return=b.continuation;
    f.callback_cleanup=b.cleanup; f.argument_words=b.argument_words;
    direct_b33::invoke(m,s,f,op,b.target);
}
using Function = void (*)(Memory&,State&,Frame&,const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,137>& entries_a();
const std::array<Entry,137>& entries_b();
const std::array<Entry,137>& entries_c();
} // namespace ra2::recovered::direct_b34
