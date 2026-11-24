#pragma once
#include "recovered/floating_callers_b40_memory.hpp"
namespace ra2::recovered::floating_composed_b43 {
namespace dependency=ra2::recovered::floating_b39;
namespace callers40=ra2::recovered::floating_callers_b40;
namespace extended=ra2::platform::x87_extended;
using dependency::Memory;using dependency::State;using dependency::Frame;
using dependency::Operations;using dependency::s32;using dependency::sar;
using dependency::with_al;using dependency::with_ax;
using dependency::read64;using dependency::read80;using dependency::write64;
using dependency::finish;using dependency::Function;
namespace integer=dependency::integer;
struct Entry {std::uint32_t rva;Function function;};
const std::array<Entry,6>& entries_a();
inline Function resolve(std::uint32_t rva){
    switch(rva){case 0xba0f0:case 0xba140:case 0x18d560:case 0x18d7a0:case 0x36aa50:case 0x37098a:case 0x370a1c:break;
    default:throw std::invalid_argument("unreviewed closed chain dependency");}
    for(const auto& e:dependency::entries_a())if(e.rva==rva)return e.function;
    for(const auto& e:dependency::entries_b())if(e.rva==rva)return e.function;
    for(const auto& e:callers40::entries_a())if(e.rva==rva)return e.function;
    for(const auto& e:entries_a())if(e.rva==rva)return e.function;
    throw std::runtime_error("missing prospective closed chain dependency");
}
inline void invoke_closed(Memory& m,State& s,Frame& parent,std::uint32_t rva,std::uint32_t continuation){
    const auto callee=resolve(rva);parent.push(m,continuation);
    Frame frame;frame.entry_sp=parent.sp;frame.return_sp=parent.sp;frame.sp=parent.sp;frame.outer_return=continuation;
    callee(m,s,frame,Operations{});parent.sp=frame.sp;
}
inline void invoke_closed_tail(Memory& m,State& s,Frame& parent,std::uint32_t rva){
    if(rva!=0x36aa50)throw std::invalid_argument("unreviewed closed chain tail");
    Frame frame;frame.entry_sp=parent.sp;frame.return_sp=parent.sp;frame.sp=parent.sp;frame.outer_return=parent.outer_return;
    resolve(rva)(m,s,frame,Operations{});parent.sp=frame.sp;
    for(unsigned i=0;i<s.arg.size();++i)s.arg[i]=m.r32(parent.entry_sp+4u+4u*i);
}
}
