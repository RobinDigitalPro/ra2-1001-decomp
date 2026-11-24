#include "recovered/recovery_b1636.hpp"
#include <stdexcept>
namespace ra2::recovered::b1636 {
namespace {
void need(bool b){if(!b)throw std::domain_error("1636 actual BC early branch/unchanged1633 scope");}
// Whole72A500 finite backward registry search. No API/callback/substitution.
U find(Memory&m,U resource){U count=m.r32(0xb0d858);need(count==1);for(U at=count;at;){--at;if(m.r32(0xb0d634+8*at)==resource)return m.r32(0xb0d630+8*at);}return 0;}
}
U fun_00734590(Memory&m,const Inputs&i,b979::Heap&heap,b1633::Api&api,U outer_pre_call_S){
 need((i.dx&255u)==0&&api.parent&&std::uint64_t(outer_pre_call_S)>=0x600ull+36ull);
 const U parent=U(reinterpret_cast<std::uintptr_t>(api.parent));
 need(m.r32(0xb0d858)==1&&m.r32(0xb0d630)==parent&&m.r32(0xb0d634)==0xbcu);
 // Exact5BD7D0 priority; BC succeeds before BD and all late7345C0 code.
 U hwnd=find(m,0xc2);if(!hwnd)hwnd=find(m,0xc9);if(!hwnd)hwnd=find(m,0xbc);if(!hwnd)hwnd=find(m,0xbd);
 need(hwnd==parent&&hwnd!=0);
 Inputs child=i;child.ax=hwnd;child.cx=hwnd;
 // Successful one-row72A500 leaves EDX=B0D634. MOVDL,BL restores declared0.
 child.dx=0xb0d600u;
 // This is an abstract carrier copy, NOT a claim about Original child's
 // unproducedcallerwords F..F+3C. Neither reached child algorithm reads them.
 auto child_api=api;child_api.root_pre_call_S=outer_pre_call_S-0x600u;
 // Witness arithmetic only. Never map/write/read any Original private frame.
 const U eax=b1633::fun_005c3880(m,child,heap,child_api);
 i.fp.image=child.fp.image;return eax;
}
}
