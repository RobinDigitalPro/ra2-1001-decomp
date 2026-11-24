#pragma once
#include "recovered/floating_b39_memory.hpp"
#include "platform/x87_extended_b40.hpp"
#include "recovered/strings_b37_primitives.hpp"
namespace ra2::recovered::floating_bridges_b45 {
namespace dependency=ra2::recovered::floating_b39;
namespace extended=ra2::platform::x87_extended;
using dependency::Memory;using dependency::State;using dependency::Frame;
using dependency::s32;using dependency::sar;using dependency::with_al;using dependency::with_ax;
using dependency::read64;using dependency::read80;using dependency::write64;using dependency::finish;
namespace integer=dependency::integer;
using strings_b37::Kind;using strings_b37::Repeat;using strings_b37::string_instruction;
using Call=direct_b34::Call;
struct Operations {void(*call)(Memory&,State&,const Call&,void*){};void* context{};};
using Function=void(*)(Memory&,State&,Frame&,const Operations&);
struct Entry {std::uint32_t rva;Function function;};
const std::array<Entry,13>& entries_a();
const std::array<Entry,3>& entries_dependencies();
inline void invoke_external(Memory& m,State& s,Frame& f,const Operations& op,unsigned site,
                            std::uint32_t target,std::uint32_t continuation){
    if(f.boundary_count>f.boundaries.size()||site>=f.boundary_count||!op.call)
        throw std::invalid_argument("F45 missing finite callback contract");
    const auto& b=f.boundaries[site];
    if(target!=b.target||continuation!=b.continuation||b.argument_words>32||b.cleanup>128||(b.cleanup&3))
        throw std::invalid_argument("F45 target/continuation/shape differs");
    f.push(m,continuation);const auto before=f.sp;
    op.call(m,s,{target,before,continuation,b.argument_words,b.cleanup},op.context);
    s.fp.require_masked();
    if(f.pop(m)!=continuation)throw std::runtime_error("F45 callback return slot differs");
    f.sp+=b.cleanup;
}
inline void invoke_closed(Memory& m,State& s,Frame& parent,std::uint32_t rva,std::uint32_t continuation){
    if(rva!=0x68f0&&rva!=0x191ed0&&rva!=0x36aa50&&rva!=0x36da9e&&rva!=0x378dbe&&rva!=0x378f95)
        throw std::invalid_argument("F45 unreviewed closed dependency");
    parent.push(m,continuation);Frame frame;frame.entry_sp=frame.return_sp=frame.sp=parent.sp;frame.outer_return=continuation;
    if(rva==0x36aa50||rva==0x378dbe||rva==0x378f95){
        dependency::Function fn=nullptr;for(const auto& e:dependency::entries_b())if(e.rva==rva)fn=e.function;
        if(!fn)throw std::runtime_error("F45 accepted FP dependency absent");
        fn(m,s,frame,dependency::Operations{});
    }else{
        Function fn=nullptr;for(const auto& e:entries_dependencies())if(e.rva==rva)fn=e.function;
        if(!fn)throw std::runtime_error("F45 byte-traced integer dependency absent");
        fn(m,s,frame,Operations{});
    }
    parent.sp=frame.sp;
}
}
