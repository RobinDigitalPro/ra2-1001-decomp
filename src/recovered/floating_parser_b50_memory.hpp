#pragma once
#include "recovered/floating_b39_memory.hpp"
#include "platform/x87_extended_b40.hpp"
namespace ra2::recovered::floating_parser_b50 {
namespace dependency=ra2::recovered::floating_b39;
namespace extended=ra2::platform::x87_extended;
using dependency::Memory;using dependency::State;using dependency::Frame;
using dependency::s32;using dependency::sar;using dependency::with_al;using dependency::with_ax;
using dependency::read64;using dependency::read80;using dependency::write64;using dependency::finish;
namespace integer=dependency::integer;
using Call=direct_b34::Call;
struct Operations {void(*call)(Memory&,State&,const Call&,void*){};void* context{};};
using Function=void(*)(Memory&,State&,Frame&,const Operations&);
struct Entry {std::uint32_t rva;Function function;};
const std::array<Entry,1>& entries_a();
inline void invoke_external(Memory& m,State& s,Frame& f,const Operations& op,unsigned site,
                            std::uint32_t target,std::uint32_t continuation){
    if(f.boundary_count>f.boundaries.size()||site>=f.boundary_count||!op.call)
        throw std::invalid_argument("F50 missing finite callback contract");
    const auto& b=f.boundaries[site];
    if(target!=b.target||continuation!=b.continuation||b.argument_words>32||b.cleanup>128||(b.cleanup&3))
        throw std::invalid_argument("F50 target/continuation/shape differs");
    f.push(m,continuation);const auto before=f.sp;
    op.call(m,s,{target,before,continuation,b.argument_words,b.cleanup},op.context);
    s.fp.require_masked();
    if(f.pop(m)!=continuation)throw std::runtime_error("F50 callback return slot differs");
    f.sp+=b.cleanup;
}
}
