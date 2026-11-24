#include "recovered/recovery_b1702.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b1702::calls {
void fd4d0(Memory& m,State& s,Frame& caller,U continuation,U actual_target){
    if(continuation!=0x4fd5feu || actual_target!=0x4fd4d0u)
        throw std::domain_error("FD4D0 selected call binding");
    caller.push(m,continuation);
    Frame f{caller.sp,caller.sp,continuation};
    namespace integer=direct_b33::integer;
    // Each label is the authentic original instruction address. Only the
    // sample0 positive primary/type1/one-cell-distance path is represented.
L4fd4d0: // SUB ESP,18
    f.sp=integer::sub(f.sp,0x18u,32,s.arithmetic_flags);
L4fd4d3: // PUSH ESI
    f.push(m,s.si);
L4fd4d4: // MOV ESI,ECX
    s.si=s.cx;
L4fd4d6: // MOV ECX,[ESI+4]
    s.cx=m.r32(s.si+4u);
L4fd4d9: // LEA EAX,[ESI+4]
    s.ax=s.si+4u;
L4fd4dc: // PUSH EAX
    f.push(m,s.ax);
L4fd4dd: // CALL [ECX+10]; the actual interface pointer is the argument
    fbd80(m,s,f,0x4fd4e0u,m.r32(s.cx+0x10u));
L4fd4e0: // TEST AL,AL
    (void)integer::logical(s.ax&0xffu,8,s.arithmetic_flags);
L4fd4e2: // JZ 4FD5E4 -- excluded inactive branch
    if(integer::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("FD4D0 inactive branch outside sample0");
L4fd4e8: // MOV EAX,[ESI+C]
    s.ax=m.r32(s.si+0xcu);
L4fd4eb: // CMP DWORD[EAX+4D0],-1
    (void)integer::sub(m.r32(s.ax+0x4d0u),0xffffffffu,32,s.arithmetic_flags);
L4fd4f2: // JZ 4FD5E4
    if(integer::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("FD4D0 empty direction branch outside sample0");
L4fd4f8: // MOV ECX,[EAX+494]
    s.cx=m.r32(s.ax+0x494u);
L4fd4fe: // TEST ECX,ECX
    (void)integer::logical(s.cx,32,s.arithmetic_flags);
L4fd500: // JZ 4FD50C
    if(integer::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("FD4D0 null target branch outside sample0");
L4fd502: // MOV EDX,[ECX]
    s.dx=m.r32(s.cx);
L4fd504: // CALL [EDX+2C]
    type_6fee90(m,s,f,0x4fd507u,m.r32(s.dx+0x2cu));
L4fd507: // CMP EAX,1
    (void)integer::sub(s.ax,1u,32,s.arithmetic_flags);
L4fd50a: // JZ 4FD52B -- sample0 takes this actual branch
    if(!integer::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("FD4D0 non-type1 branch outside sample0");
L4fd52b: // MOV ECX,[ESI+C]
    s.cx=m.r32(s.si+0xcu);
L4fd52e: // LEA EDX,[ESP+10]
    s.dx=f.sp+0x10u;
L4fd532: // PUSH EDX
    f.push(m,s.dx);
L4fd533: // MOV EAX,[ECX]
    s.ax=m.r32(s.cx);
L4fd535: // CALL [EAX+48]
    xyz_5cd4d0(m,s,f,0x4fd538u,m.r32(s.ax+0x48u));
L4fd538: // MOV ECX,[EAX]
    s.cx=m.r32(s.ax);
L4fd53a: // MOV EDX,[ESI+18]
    s.dx=m.r32(s.si+0x18u);
L4fd53d: // SUB ECX,EDX
    s.cx=integer::sub(s.cx,s.dx,32,s.arithmetic_flags);
L4fd53f: // MOV EDX,[EAX+4]
    s.dx=m.r32(s.ax+4u);
L4fd542: // MOV EAX,[EAX+8]
    s.ax=m.r32(s.ax+8u);
L4fd545: // MOV [ESP+4],ECX
    m.w32(f.sp+4u,s.cx);
L4fd549: // MOV ECX,[ESI+1C]
    s.cx=m.r32(s.si+0x1cu);
L4fd54c: // SUB ESP,8
    f.sp=integer::sub(f.sp,8u,32,s.arithmetic_flags);
L4fd54f: // SUB EDX,ECX
    s.dx=integer::sub(s.dx,s.cx,32,s.arithmetic_flags);
L4fd551: // MOV ECX,[ESI+20]
    s.cx=m.r32(s.si+0x20u);
L4fd554: // SUB EAX,ECX
    s.ax=integer::sub(s.ax,s.cx,32,s.arithmetic_flags);
L4fd556: // MOV [ESP+10],EDX
    m.w32(f.sp+0x10u,s.dx);
L4fd55a: // MOV [ESP+14],EAX
    m.w32(f.sp+0x14u,s.ax);
L4fd55e: // FILD DWORD[ESP+14]
    s.fp.load_integer32(m.r32(f.sp+0x14u));
L4fd562: // FILD DWORD[ESP+10]
    s.fp.load_integer32(m.r32(f.sp+0x10u));
L4fd566: // FILD DWORD[ESP+C]
    s.fp.load_integer32(m.r32(f.sp+0xcu));
L4fd56a: // FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
L4fd56c: // FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
L4fd56e: // FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
L4fd570: // FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
L4fd572: // FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
L4fd574: // FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
L4fd576: // FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
L4fd578: // FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
L4fd57a: // FSTP QWORD[ESP] -- actual 8B outgoing argument production
    floating_b61::write64(m,f.sp,s.fp.pop64());
L4fd57d: // FSTP ST0
    s.fp.pop_st0();
L4fd57f: // FSTP ST0
    s.fp.pop_st0();
L4fd581: // FSTP ST0
    s.fp.pop_st0();
L4fd583: // CALL 4BA080; no callee cleanup of caller's 8B argument
    distance_4ba080(m,s,f,0x4fd588u,0x4ba080u);
L4fd588: // ADD ESP,8
    f.sp=integer::add(f.sp,8u,32,s.arithmetic_flags);
L4fd58b: // CALL 76AA50, continuous actual live FP state
    ftol_76aa50(m,s,f,0x4fd590u,0x76aa50u);
L4fd590: // CDQ
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
L4fd591: // AND EDX,FF
    s.dx=integer::logical(s.dx&0xffu,32,s.arithmetic_flags);
L4fd597: // ADD EAX,EDX
    s.ax=integer::add(s.ax,s.dx,32,s.arithmetic_flags);
L4fd599: // SAR EAX,8
    s.ax=integer::shift(s.ax,8u,32,s.arithmetic_flags,integer::Shift::arithmetic_right);
L4fd59c: // CMP EAX,18
    (void)integer::sub(s.ax,0x18u,32,s.arithmetic_flags);
L4fd59f: // JGE 4FD5B6
    if(integer::condition("JGE",s.arithmetic_flags))
        throw std::domain_error("FD4D0 long distance branch outside sample0");
    if(s.ax!=1u)
        throw std::domain_error("FD4D0 selected sample0 distance must be one cell");
L4fd5a1: // MOV ECX,[ESI+C]
    s.cx=m.r32(s.si+0xcu);
L4fd5a4: // POP ESI
    s.si=f.pop(m);
L4fd5a5: // MOV DWORD[ECX+EAX*4+4D0],FFFFFFFF
    m.w32(s.cx+s.ax*4u+0x4d0u,0xffffffffu);
L4fd5b0: // MOV AL,1
    s.ax=(s.ax&0xffffff00u)|1u;
L4fd5b2: // ADD ESP,18
    f.sp=integer::add(f.sp,0x18u,32,s.arithmetic_flags);
L4fd5b5: // RET0
    recovery_b566::finish(m,s,f,0u);
    caller.sp=f.sp;
}
}
