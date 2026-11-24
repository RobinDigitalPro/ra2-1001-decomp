#pragma once
#include "recovered/recovery_b1647.hpp"
#include "recovered/recovery_b566_machine.hpp"

// BEGIN original fragment: root_source_v2/source.hpp
namespace ra2::recovered::b1698 {
using U=std::uint32_t; using Memory=recovery_b566::Memory;
using State=recovery_b566::State; using Frame=recovery_b566::Frame;
// Prepared outside the observed boundary; the caller owns Api lifetime.
// No TLS, lazy provider initialization, or hidden provider lookup.
struct Context { b1647::Api& api; U main; };
// Required concrete bindings, deliberately not callbacks or successful stubs.
// Each performs CALL (push continuation), executes the named authentic model,
// consumes its own return/arguments and updates the SAME State/Frame/FP.
namespace helpers {
void project_00698010(Context&,Memory&,State&,Frame&,U continuation);
void point_00435400(Context&,Memory&,State&,Frame&,U continuation);
void rectangle_00453ab0(Context&,Memory&,State&,Frame&,U continuation);
void intersect_0041fdf0(Context&,Memory&,State&,Frame&,U continuation);
void actual_main_slot14(Context&,Memory&,State&,Frame&,U continuation,U actual_target);
void reject_00760f60(Context&,Memory&,State&,Frame&,U continuation);
// Must validate the complete frozen finite basis and all mapped stack/output
// extents BEFORE execute_selected; this declaration is an unresolved link gate.
void require_selected_basis(Context&,const Memory&,const State&,const Frame&);
}
// Existing frame has entry_sp==sp pointing to its real modeled return word.
// The callee reserves its own 0x80 locals, saves EBX/ESI/EDI, RET 0x24.
void execute_selected(Context&,Memory&,State&,Frame&);
}

// END original fragment

// BEGIN original fragment: numeric_source_bridge_plan/source_bridge.hpp
namespace ra2::recovered::b1698::numeric_core {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
// SDK-free concrete models. Frame.sp points at the caller's top outgoing arg.
// Each pushes/validates its real continuation and consumes its own RET cleanup.
void project(Memory&,State&,Frame&,U continuation);
void reject(Memory&,State&,Frame&,U continuation);
}

// END original fragment

