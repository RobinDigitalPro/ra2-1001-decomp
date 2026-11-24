#include "recovered/recovery_b1704.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1704 {
namespace ix=direct_b33::integer;
void execute_selected(Memory& m,State& s,Frame& f){
    // Caller-owned finite/ownership preflight is outside this observed Root.
    // 0x6c31b0: SUB ESP,0xb4 [81ecb4000000]
    f.sp=ix::sub(f.sp,0xb4u,32,s.arithmetic_flags);
    // 0x6c31b6: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x6c31b7: MOV EBX,dword ptr [ESP + 0xbc] [8b9c24bc000000]
    s.bx=m.r32(f.sp+0xbcu);
    // 0x6c31be: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x6c31bf: PUSH ESI [56]
    f.push(m,s.si);
    // 0x6c31c0: MOV EAX,dword ptr [EBX] [8b03]
    s.ax=m.r32(s.bx);
    // 0x6c31c2: MOV ESI,ECX [8bf1]
    s.si=s.cx;
    // 0x6c31c4: MOV CL,byte ptr [ESP + 0xd4] [8a8c24d4000000]
    s.cx=(s.cx&0xffffff00u)|m.r8(f.sp+0xd4u);
    // 0x6c31cb: MOV dword ptr [ESP + 0x10],EAX [89442410]
    m.w32(f.sp+0x10u,s.ax);
    // 0x6c31cf: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax,32,s.arithmetic_flags);
    // 0x6c31d1: SETL AL [0f9cc0]
    s.ax=(s.ax&0xffffff00u)|(ix::condition("JL",s.arithmetic_flags)?1u:0u);
    // 0x6c31d4: TEST CL,CL [84c9]
    (void)ix::logical(s.cx&0xffu,8,s.arithmetic_flags);
    // 0x6c31d6: PUSH EDI [57]
    f.push(m,s.di);
    // 0x6c31d7: MOV byte ptr [ESP + 0x13],AL [88442413]
    m.w8(f.sp+0x13u,s.ax&0xffu);
    // 0x6c31db: JNZ 0x006c32eb [0f850a010000]
    if(!ix::condition("JNZ",s.arithmetic_flags))throw std::domain_error("2C31B0 finite arg4 lowbyte nonzero at6C31DB");
    // 0x6c32eb: MOV EDX,dword ptr [ESI] [8b16]
    s.dx=m.r32(s.si);
    // 0x6c32ed: MOV ECX,ESI [8bce]
    s.cx=s.si;
    // 0x6c32ef: CALL dword ptr [EDX + 0x32c] [ff922c030000]
    calls::timer_41b390(m,s,f,0x6c32f5u,m.r32(s.dx+0x32cu));
    // 0x6c32f5: TEST AL,AL [84c0]
    (void)ix::logical(s.ax&0xffu,8,s.arithmetic_flags);
    // 0x6c32f7: JZ 0x006c3350 [7457]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("2C31B0 realtimer AL0 branch at6C32F7");
    // 0x6c3350: MOV EDX,dword ptr [ESI] [8b16]
    s.dx=m.r32(s.si);
    // 0x6c3352: MOV ECX,ESI [8bce]
    s.cx=s.si;
    // 0x6c3354: CALL dword ptr [EDX + 0x1bc] [ff92bc010000]
    calls::byte_6cc360(m,s,f,0x6c335au,m.r32(s.dx+0x1bcu));
    // 0x6c335a: TEST AL,AL [84c0]
    (void)ix::logical(s.ax&0xffu,8,s.arithmetic_flags);
    // 0x6c335c: JZ 0x006c3373 [7415]
    if(ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("2C31B0 realSelf204 nonzero branch at6C335C");
    // 0x6c335e: MOV dword ptr [EBX],0x0 [c70300000000]
    m.w32(s.bx,0u);
    // 0x6c3364: XOR EAX,EAX [33c0]
    s.ax=ix::logical(s.ax^s.ax,32,s.arithmetic_flags);
    // 0x6c3366: POP EDI [5f]
    s.di=f.pop(m);
    // 0x6c3367: POP ESI [5e]
    s.si=f.pop(m);
    // 0x6c3368: POP EBP [5d]
    s.bp=f.pop(m);
    // 0x6c3369: POP EBX [5b]
    s.bx=f.pop(m);
    // 0x6c336a: ADD ESP,0xb4 [81c4b4000000]
    f.sp=ix::add(f.sp,0xb4u,32,s.arithmetic_flags);
    // 0x6c3370: RET 0x18 [c21800]
    recovery_b566::finish(m,s,f,0x18u);return;
}
} // namespace ra2::recovered::recovery_b1704
