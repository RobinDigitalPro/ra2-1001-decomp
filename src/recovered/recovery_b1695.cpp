#include "recovered/recovery_b1695.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b1695 {
namespace {
void need(bool value){if(!value)throw std::domain_error("FB4C0 finite early positive speed domain");}
U secondary(const RootInputs&i){need(i.arg[0]>=4u);return i.arg[0];}
// Actual FBD80 stack-argument algorithm. This reads the authentic sentinel and
// the supplied secondary's six real fields; it is neither a vtable callback
// nor a supplied Boolean. Full EAX is 0 or 1, and actual RET4 balances its copy.
U destination_present(Memory&m,U argument){
 const U x=m.r32(0xa28cc0u);
 if(m.r32(argument+0x14u)!=x)return 1u;
 const U y=m.r32(0xa28cc4u);
 if(m.r32(argument+0x18u)!=y)return 1u;
 const U z=m.r32(0xa28cc8u);
 if(m.r32(argument+0x1cu)!=z)return 1u;
 if(m.r32(argument+0x20u)!=x)return 1u;
 if(m.r32(argument+0x24u)!=y)return 1u;
 if(m.r32(argument+0x28u)!=z)return 1u;
 return 0u;
}
RootInputs child_inputs(const RootInputs&i,U self){
 // FCFF0 consumes ECX and FP/public state, but none of AX/DX or arg[0..15].
 // Retaining the Root logical array satisfies its opaque-input API; it does
 // not identify, read or seed the uninitialized physical child caller slots.
 RootInputs child=i;child.cx=self;return child;
}
}

void preflight(Memory&m,const RootInputs&i){
 const U argument=secondary(i),self=argument-4u;
 auto child=child_inputs(i,self);
 recovery_b1694::preflight(m,child); // Exact accepted incoming numeric86/all80.
 need(m.r32(argument)==0x78e1ecu&&m.r32(0x78e1fcu)==0x4fbd80u);
 const U owner=m.r32(argument+8u);
 need(owner==m.r32(self+0xcu)&&m.r8(owner+0x7du)==0u);
 need(destination_present(m,argument)==1u);
}

U run(Memory&m,const RootInputs&i,const RootFrameContext&frame){
 static_assert(sizeof(void*)==4,"FB4C0 requires its actual own Win32 nested frame");
 preflight(m,i);
 need(frame.entry_esp>0x100u&&!(frame.entry_esp&3u));
 need(frame.aligned_base==((frame.entry_esp-4u)&~7u));
 need(frame.child.entry_esp==frame.aligned_base-0x5cu);
 need(frame.child.frame_base==frame.aligned_base-0x98u);
 need(frame.child.angle_argument==frame.aligned_base-0x7cu);
 const auto caller=i.arg;
 const U esi=secondary(i);
 need(m.r32(esi)==0x78e1ecu&&m.r32(0x78e1fcu)==0x4fbd80u);
 U eax=destination_present(m,esi); // 4FB4D2: real first stack argument.
 need((eax&255u)!=0u); // Other Root branches are outside the finite domain.
 const U edi=esi-4u;
 need(m.r32(edi+4u)==0x78e1ecu&&m.r32(0x78e1fcu)==0x4fbd80u);
 eax=destination_present(m,edi+4u); // 4FB4E7: distinct actual second call.
 need((eax&255u)!=0u);
 auto child=child_inputs(i,edi); // 4FB4F2 MOV ECX,EDI.
 eax=recovery_b1694::run(m,child,frame.child); // Own live child K, full EAX.
 i.fp=child.fp; // Publish only the connected production-computed FP state.
 const U owner=m.r32(esi+8u); // 4FB4F9 reads the actual postchild owner link.
 eax=floating_b61::with_al(eax,m.r8(owner+0x7du)); // 4FB4FC MOV AL,[ECX+7D].
 need((eax&255u)==0u); // Explicit finite early exit; no later route opened.
 eax=floating_b61::with_al(eax,0u); // 4FB503 XOR AL,AL; upper24 unchanged.
 need(i.arg==caller);
 return eax; // Actual ABI bridge performs RET4 and returns all32 unchanged.
}
}
