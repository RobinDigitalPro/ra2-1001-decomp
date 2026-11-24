#pragma once
#include "recovered/recovery_b566_machine.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::recovery_b1703 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
using Heap=ra2::platform::ordinary_heap::Heap;
namespace calls {
void length_76ef45(Memory&,State&,Frame& caller,U continuation,U actual_target);
void manager_5243c0(Memory&,State&,Frame& caller,U continuation,U actual_target,Heap&);
void house_4e73d0(Memory&,State&,Frame& caller,U continuation,U actual_target);
}
namespace helpers {
// Fixture/setup preflight: run before the observed Root boundary on the actual
// HeapAdapter. It may obtain ownership metadata by value; it is not guest code.
void require_selected_basis(const Memory&,const State&,const Frame&,Heap&);
}
// Private finite mode2/frame0 positive ordinary-owned removal. Not promoted.
// Caller must establish helpers::require_selected_basis before observation.
void execute_selected(Memory&,State&,Frame&,Heap&);
}
