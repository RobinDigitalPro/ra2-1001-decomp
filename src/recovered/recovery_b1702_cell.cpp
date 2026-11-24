#include "recovered/recovery_b1702.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b1702::calls {
namespace ix=direct_b33::integer;

void cell_41b320(Memory&m,State&s,Frame&caller,U continuation,U actual_target) {
    if(actual_target!=0x0041b320u)
        throw std::domain_error("fd5f0 cell getter target outside selected domain");

    // The caller has pushed its actual argument. CALL stores the actual return
    // word below it; the callee's PUSH ECX is a real, subsequently overwritten
    // four-byte private word, not a saved receiver restored at return.
    caller.push(m,continuation);
    Frame f{caller.sp,caller.sp,continuation};

    // 0041b320 51: PUSH ECX
    f.push(m,s.cx);
    // 0041b321 8b8188000000: MOV EAX,[ECX+88]
    s.ax=m.r32(s.cx+0x88u);
    // 0041b327 99: CDQ
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
    // 0041b328 81e2ff000000: AND EDX,FF
    s.dx=ix::logical(s.dx&0xffu,32,s.arithmetic_flags);
    // 0041b32e 03c2: ADD EAX,EDX
    s.ax=ix::add(s.ax,s.dx,32,s.arithmetic_flags);
    // 0041b330 c1f808: SAR EAX,8
    s.ax=ix::shift(s.ax,8u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
    // 0041b333 6689442400: MOV [ESP],AX
    m.w16(f.sp,s.ax&0xffffu);
    // 0041b338 8b818c000000: MOV EAX,[ECX+8C]
    s.ax=m.r32(s.cx+0x8cu);
    // 0041b33e 99: CDQ
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
    // 0041b33f 81e2ff000000: AND EDX,FF
    s.dx=ix::logical(s.dx&0xffu,32,s.arithmetic_flags);
    // 0041b345 03c2: ADD EAX,EDX
    s.ax=ix::add(s.ax,s.dx,32,s.arithmetic_flags);
    // 0041b347 c1f808: SAR EAX,8
    s.ax=ix::shift(s.ax,8u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
    // 0041b34a 6689442402: MOV [ESP+2],AX
    m.w16(f.sp+2u,s.ax&0xffffu);
    // 0041b34f 8b442408: MOV EAX,[ESP+8]
    s.ax=m.r32(f.sp+8u);
    // 0041b353 8b4c2400: MOV ECX,[ESP]
    s.cx=m.r32(f.sp);
    // 0041b357 8908: MOV [EAX],ECX
    m.w32(s.ax,s.cx);
    // 0041b359 59: POP ECX
    s.cx=f.pop(m);
    // 0041b35a c20400: RET 4
    recovery_b566::finish(m,s,f,4u);
    caller.sp=f.sp;
}
}
