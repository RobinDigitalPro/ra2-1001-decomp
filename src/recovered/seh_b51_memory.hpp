#pragma once
#include "recovered/floating_b39_memory.hpp"
#include "platform/x87_extended_b40.hpp"
namespace ra2::recovered::seh_b51 {
namespace dependency=ra2::recovered::floating_b39;
namespace extended=ra2::platform::x87_extended;
using dependency::Memory;using dependency::Frame;
// Explicit thread-local FS:[0] state; no original C++ type or exception ABI is inferred.
struct State:dependency::State {std::uint32_t fs0{};};
using dependency::s32;using dependency::sar;using dependency::with_al;using dependency::with_ax;
using dependency::read64;using dependency::read80;using dependency::write64;using dependency::finish;
namespace integer=dependency::integer;
using Call=direct_b34::Call;
struct Operations {void(*call)(Memory&,State&,const Call&,void*){};void* context{};};
using Function=void(*)(Memory&,State&,Frame&,const Operations&);
struct Entry {std::uint32_t rva;Function function;};
const std::array<Entry,2>& entries_a();
inline void invoke_closed(Memory& m,State& s,Frame& parent,const Operations& op,
                          Function fn,std::uint32_t continuation,unsigned cleanup){
    parent.push(m,continuation);const auto start=parent.sp;
    Frame child=parent;child.entry_sp=child.return_sp=start;child.outer_return=continuation;
    fn(m,s,child,op);
    if(child.sp!=start+4u+cleanup)throw std::runtime_error("S51 closed helper cleanup differs");
    parent.sp=child.sp;
}

inline void invoke_external(Memory& m,State& s,Frame& f,const Operations& op,unsigned site,
                            std::uint32_t target,std::uint32_t continuation){
    if(f.boundary_count>f.boundaries.size()||site>=f.boundary_count||!op.call)
        throw std::invalid_argument("S51 missing finite callback contract");
    const auto& b=f.boundaries[site];
    if(target!=b.target||continuation!=b.continuation||b.argument_words>32||b.cleanup>128||(b.cleanup&3))
        throw std::invalid_argument("S51 target/continuation/shape differs");
    f.push(m,continuation);const auto before=f.sp;
    op.call(m,s,{target,before,continuation,b.argument_words,b.cleanup},op.context);
    s.fp.require_masked();
    if(f.pop(m)!=continuation)throw std::runtime_error("S51 callback return slot differs");
    f.sp+=b.cleanup;
}
}
