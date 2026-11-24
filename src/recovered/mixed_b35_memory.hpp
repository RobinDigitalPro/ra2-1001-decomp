#pragma once
#include "recovered/direct_b34_memory.hpp"

namespace ra2::recovered::mixed_b35 {
using direct_b34::Memory;
using direct_b34::State;
using direct_b34::Call;
using direct_b34::Operations;
using direct_b34::Boundary;
struct Frame : direct_b34::Frame {
    // Only RVA 0x2eece0 composes the previously recovered page-probing helper.
    // Eight is outside the encoded-site domain and means no such dependency.
    unsigned original_probe_site{8};
};
using direct_b34::finish;
using direct_b34::s32;
using direct_b34::sar;
using direct_b34::with_al;
using direct_b34::with_ax;
using direct_b34::arena_bytes;
namespace integer = direct_b33::integer;

// Computed operands are evaluated by the translated caller before this entry.
// The controlled boundary checks that actual value; it never replaces the
// caller's computed target with an unrelated fixture address.
inline void invoke(Memory& m,State& s,Frame& f,const Operations& op,unsigned site,
                   std::uint32_t actual_target) {
    if(f.boundary_count>f.boundaries.size() || site>=f.boundary_count)
        throw std::invalid_argument("M35 missing call boundary");
    if(actual_target!=f.boundaries[site].target)
        throw std::invalid_argument("M35 computed target differs from controlled boundary");
    if(site==f.original_probe_site) {
        const auto& b=f.boundaries[site];
        if(!op.invoke||b.cleanup!=0||s.ax!=0x1c00u||b.argument_words!=32)
            throw std::invalid_argument("M35 invalid original stack-probe dependency");
        const auto input=s;
        f.push(m,b.continuation);
        op.invoke(m,s,{b.target,f.sp,b.continuation,b.argument_words,0},op.context);
        // The seam observes input only. The existing recovered helper determines
        // output registers, memory probes, copied continuation and stack movement.
        s=input;
        global_b27::StackContext context{f.sp,b.continuation,0,0};
        bool found=false;
        for(const auto& entry:global_b27::entries_c())if(entry.rva==0x36f190u&&entry.stack_function) {
            entry.stack_function(m,s,context);found=true;break;
        }
        if(!found||context.next_ip!=b.continuation)
            throw std::runtime_error("M35 missing/invalid recovered stack probe");
        f.sp=context.exit_sp;
    } else direct_b34::invoke(m,s,f,op,site);
}
using Function = void (*)(Memory&,State&,Frame&,const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,161>& entries_a();
const std::array<Entry,161>& entries_b();
const std::array<Entry,160>& entries_c();
} // namespace ra2::recovered::mixed_b35
