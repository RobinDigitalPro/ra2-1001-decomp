#include "recovered/recovery_b1702.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1702 {
namespace ix=direct_b33::integer;
void execute_selected(Memory& m,State& s,Frame& f){
    helpers::require_selected_basis(m,s,f); // readonly, before first guest instruction/write
L4fd5f0: // SUB ESP,0x28 [83ec28]
    f.sp=ix::sub(f.sp,0x28u,32,s.arithmetic_flags);
L4fd5f3: // PUSH EBX [53]
    f.push(m,s.bx);
L4fd5f4: // PUSH EBP [55]
    f.push(m,s.bp);
L4fd5f5: // PUSH ESI [56]
    f.push(m,s.si);
L4fd5f6: // PUSH EDI [57]
    f.push(m,s.di);
L4fd5f7: // MOV ESI,ECX [8bf1]
    s.si=s.cx;
L4fd5f9: // CALL 0x004fd4d0 [e8d2feffff]
    calls::fd4d0(m,s,f,0x4fd5feu,0x4fd4d0u);
L4fd5fe: // MOV ECX,dword ptr [ESI + 0xc] [8b4e0c]
    s.cx=m.r32(s.si+0xcu);
L4fd601: // MOV EDX,dword ptr [ESI + 0x18] [8b5618]
    s.dx=m.r32(s.si+0x18u);
L4fd604: // LEA EDI,[ESI + 0x18] [8d7e18]
    s.di=s.si+0x18u;
L4fd607: // MOV EAX,dword ptr [ECX + 0x4d0] [8b81d0040000]
    s.ax=m.r32(s.cx+0x4d0u);
L4fd60d: // MOV dword ptr [ESP + 0x10],EAX [89442410]
    m.w32(f.sp+0x10u,s.ax);
L4fd611: // MOV EAX,[0x00a28cc0] [a1c08ca200]
    s.ax=m.r32(0xa28cc0u);
L4fd616: // CMP EDX,EAX [3bd0]
    (void)ix::sub(s.dx,s.ax,32,s.arithmetic_flags);
L4fd618: // JNZ 0x004fd633 [7519]
    if(ix::condition("JNZ",s.arithmetic_flags))goto L4fd633;
    throw std::domain_error("FD5F0 selected primary-X branch required at4FD618");
L4fd633: // MOV EAX,dword ptr [EDI] [8b07]
    s.ax=m.r32(s.di);
L4fd635: // CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
L4fd636: // AND EDX,0xff [81e2ff000000]
    s.dx=ix::logical(s.dx&0xffu,32,s.arithmetic_flags);
L4fd63c: // ADD EAX,EDX [03c2]
    s.ax=ix::add(s.ax,s.dx,32,s.arithmetic_flags);
L4fd63e: // MOV EBP,EAX [8be8]
    s.bp=s.ax;
L4fd640: // MOV EAX,dword ptr [EDI + 0x4] [8b4704]
    s.ax=m.r32(s.di+4u);
L4fd643: // CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
L4fd644: // AND EDX,0xff [81e2ff000000]
    s.dx=ix::logical(s.dx&0xffu,32,s.arithmetic_flags);
L4fd64a: // ADD EAX,EDX [03c2]
    s.ax=ix::add(s.ax,s.dx,32,s.arithmetic_flags);
L4fd64c: // LEA EDX,[ESP + 0x14] [8d542414]
    s.dx=f.sp+0x14u;
L4fd650: // MOV EBX,EAX [8bd8]
    s.bx=s.ax;
L4fd652: // MOV EAX,dword ptr [ECX] [8b01]
    s.ax=m.r32(s.cx);
L4fd654: // PUSH EDX [52]
    f.push(m,s.dx);
L4fd655: // SAR EBP,0x8 [c1fd08]
    s.bp=ix::shift(s.bp,8u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
L4fd658: // SAR EBX,0x8 [c1fb08]
    s.bx=ix::shift(s.bx,8u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
L4fd65b: // CALL dword ptr [EAX + 0x1a0] [ff90a0010000]
    {
        const U actual_target=m.r32(s.ax+0x1a0u);
        calls::cell_41b320(m,s,f,0x4fd661u,actual_target);
    }
L4fd661: // CMP word ptr [EAX],BP [663928]
    (void)ix::sub(m.r16(s.ax),s.bp&0xffffu,16,s.arithmetic_flags);
L4fd664: // JNZ 0x004fd6a4 [753e]
    if(ix::condition("JNZ",s.arithmetic_flags))goto L4fd6a4;
    throw std::domain_error("FD5F0 selected genuine cell-X mismatch required at4FD664");
L4fd6a4: // CMP dword ptr [ESP + 0x10],-0x1 [837c2410ff]
    (void)ix::sub(m.r32(f.sp+0x10u),0xffffffffu,32,s.arithmetic_flags);
L4fd6a9: // JNZ 0x004fdcf1 [0f8542060000]
    if(ix::condition("JNZ",s.arithmetic_flags))goto L4fdcf1;
    throw std::domain_error("FD5F0 selected nonempty base-path exit required at4FD6A9");
L4fdcf1: // POP EDI [5f]
    s.di=f.pop(m);
L4fdcf2: // POP ESI [5e]
    s.si=f.pop(m);
L4fdcf3: // POP EBP [5d]
    s.bp=f.pop(m);
L4fdcf4: // POP EBX [5b]
    s.bx=f.pop(m);
L4fdcf5: // ADD ESP,0x28 [83c428]
    f.sp=ix::add(f.sp,0x28u,32,s.arithmetic_flags);
L4fdcf8: // RET 0x4 [c20400]
    recovery_b566::finish(m,s,f,4u);return;
}
} // namespace ra2::recovered::recovery_b1702
