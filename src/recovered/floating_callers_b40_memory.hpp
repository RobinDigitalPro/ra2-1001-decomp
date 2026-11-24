#pragma once
#include "recovered/floating_b39_memory.hpp"
#include "platform/x87_extended_b40.hpp"
namespace ra2::recovered::floating_callers_b40 {
namespace dependency=ra2::recovered::floating_b39;
namespace extended=ra2::platform::x87_extended;
using dependency::Memory;using dependency::State;using dependency::Frame;
using dependency::Operations;using dependency::s32;using dependency::sar;
using dependency::with_al;using dependency::with_ax;
using dependency::read64;using dependency::read80;using dependency::write64;
using dependency::finish;using dependency::Function;
namespace integer=dependency::integer;
struct Entry {std::uint32_t rva;Function function;};
const std::array<Entry,26>& entries_a();
inline void invoke_closed(Memory& m,State& s,Frame& parent,
                          std::uint32_t target_rva,std::uint32_t continuation){
    if(target_rva!=0xba080u && target_rva!=0x36aa50u && target_rva!=0x18e180u)
        throw std::invalid_argument("unreviewed closed x87 dependency");
    Function callee=nullptr;
    for(const auto& e:dependency::entries_a())if(e.rva==target_rva)callee=e.function;
    for(const auto& e:dependency::entries_b())if(e.rva==target_rva)callee=e.function;
    if(!callee)throw std::runtime_error("missing prospective x87 dependency");
    parent.push(m,continuation);
    Frame frame;frame.entry_sp=parent.sp;frame.return_sp=parent.sp;
    frame.sp=parent.sp;frame.outer_return=continuation;
    callee(m,s,frame,Operations{});
    parent.sp=frame.sp;
}
inline void invoke_closed_tail(Memory& m,State& s,Frame& parent,std::uint32_t target_rva){
    if(target_rva!=0x36aa50u)throw std::invalid_argument("unreviewed closed x87 tail");
    Function callee=nullptr;
    for(const auto& e:dependency::entries_b())if(e.rva==target_rva)callee=e.function;
    if(!callee)throw std::runtime_error("missing prospective x87 tail dependency");
    Frame frame;frame.entry_sp=parent.sp;frame.return_sp=parent.sp;
    frame.sp=parent.sp;frame.outer_return=parent.outer_return;
    callee(m,s,frame,Operations{});
    parent.sp=frame.sp;
    for(unsigned i=0;i<s.arg.size();++i)s.arg[i]=m.r32(parent.entry_sp+4u+4u*i);
}
}
