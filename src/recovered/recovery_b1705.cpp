#include "recovered/recovery_b1705.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1705 {
namespace ix=direct_b33::integer;
void execute_selected(Memory& m,State& s,Frame& f){
    // Outside-observation finite owner/bounds/nonalias preflight is caller-owned.
    // 0x4c5c60: SUB ESP,0xc [83ec0c]
    f.sp=ix::sub(f.sp,0xcu,32,s.arithmetic_flags);
    // 0x4c5c63: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x4c5c64: MOV EBX,dword ptr [ESP + 0x20] [8b5c2420]
    s.bx=m.r32(f.sp+0x20u);
    // 0x4c5c68: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x4c5c69: MOV EBP,dword ptr [ESP + 0x20] [8b6c2420]
    s.bp=m.r32(f.sp+0x20u);
    if(s.bp!=0x30020000u)throw std::domain_error("C5C60 finite real arg2 address");
    // 0x4c5c6d: PUSH ESI [56]
    f.push(m,s.si);
    // 0x4c5c6e: PUSH EDI [57]
    f.push(m,s.di);
    // 0x4c5c6f: MOV AL,byte ptr [EBP + 0x14a] [8a854a010000]
    s.ax=(s.ax&0xffffff00u)|m.r8(s.bp+0x14au);
    // 0x4c5c75: MOV ESI,ECX [8bf1]
    s.si=s.cx;
    // 0x4c5c77: TEST AL,AL [84c0]
    (void)ix::logical(s.ax&0xffu,8,s.arithmetic_flags);
    // 0x4c5c79: JZ 0x004c5ca0 [7425]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("C5C60 actual arg2+14A zero branch");
    // 0x4c5ca0: MOV ECX,dword ptr [ESI + 0x580] [8b8e80050000]
    s.cx=m.r32(s.si+0x580u);
    // 0x4c5ca6: MOV EDI,dword ptr [ESP + 0x20] [8b7c2420]
    s.di=m.r32(f.sp+0x20u);
    // 0x4c5caa: TEST ECX,ECX [85c9]
    (void)ix::logical(s.cx,32,s.arithmetic_flags);
    // 0x4c5cac: JZ 0x004c5d00 [7452]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("C5C60 finite actualSelf580 zero prefix");
    // 0x4c5d00: MOV EDX,dword ptr [ESI + 0x580] [8b9680050000]
    s.dx=m.r32(s.si+0x580u);
    // 0x4c5d06: TEST EDX,EDX [85d2]
    (void)ix::logical(s.dx,32,s.arithmetic_flags);
    // 0x4c5d08: JZ 0x004c5d3f [7435]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("C5C60 finite actualSelf580 zero second read");
    // 0x4c5d3f: MOV EDX,dword ptr [ESP + 0x34] [8b542434]
    s.dx=m.r32(f.sp+0x34u);
    // 0x4c5d43: MOV EAX,dword ptr [ESP + 0x30] [8b442430]
    s.ax=m.r32(f.sp+0x30u);
    if(s.ax!=1u)throw std::domain_error("C5C60 finite whole arg4 equals1");
    // 0x4c5d47: MOV ECX,dword ptr [ESP + 0x24] [8b4c2424]
    s.cx=m.r32(f.sp+0x24u);
    // 0x4c5d4b: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x4c5d4c: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x4c5d4d: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x4c5d4e: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x4c5d4f: PUSH ECX [51]
    f.push(m,s.cx);
    // 0x4c5d50: PUSH EDI [57]
    f.push(m,s.di);
    // 0x4c5d51: MOV ECX,ESI [8bce]
    s.cx=s.si;
    // 0x4c5d53: CALL 0x006c31b0 [e858d41f00]
    {
        // Encoded CALL writes the actual model continuation; accepted child
        // owns its complete modeled instructions, predicates and RET24.
        f.push(m,0x4c5d58u);
        Frame child{f.sp,f.sp,0x4c5d58u};
        const U child_entry=child.entry_sp;
        recovery_b1704::execute_selected(m,s,child);
        if(child.entry_sp!=child_entry||child.outer_return!=0x4c5d58u||
           child.sp!=child_entry+0x1cu)
            throw std::runtime_error("C5C60 genuine child CALL/RET24 frame imbalance");
        f.sp=child.sp;
    }
    // 0x4c5d58: MOV EDI,EAX [8bf8]
    s.di=s.ax;
    // 0x4c5d5a: CMP EDI,0x5 [83ff05]
    (void)ix::sub(s.di,5u,32,s.arithmetic_flags);
    // 0x4c5d5d: JNZ 0x004c5d69 [750a]
    if(!ix::condition("JNZ",s.arithmetic_flags))throw std::domain_error("C5C60 finite childzero skipsreturn5");
    // 0x4c5d69: TEST EDI,EDI [85ff]
    (void)ix::logical(s.di,32,s.arithmetic_flags);
    // 0x4c5d6b: JZ 0x004c5d8b [741e]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("C5C60 actual childzero tail");
    // 0x4c5d8b: CMP EDI,0x4 [83ff04]
    (void)ix::sub(s.di,4u,32,s.arithmetic_flags);
    // 0x4c5d8e: JZ 0x004c5df4 [7464]
    if(ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("C5C60 finite childzero skipsreturn4");
    // 0x4c5d90: TEST EDI,EDI [85ff]
    (void)ix::logical(s.di,32,s.arithmetic_flags);
    // 0x4c5d92: JZ 0x004c5df4 [7460]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("C5C60 finite actual childzero exit");
    // 0x4c5df4: MOV EAX,EDI [8bc7]
    s.ax=s.di;
    // 0x4c5df6: POP EDI [5f]
    s.di=f.pop(m);
    // 0x4c5df7: POP ESI [5e]
    s.si=f.pop(m);
    // 0x4c5df8: POP EBP [5d]
    s.bp=f.pop(m);
    // 0x4c5df9: POP EBX [5b]
    s.bx=f.pop(m);
    // 0x4c5dfa: ADD ESP,0xc [83c40c]
    f.sp=ix::add(f.sp,0xcu,32,s.arithmetic_flags);
    // 0x4c5dfd: RET 0x18 [c21800]
    recovery_b566::finish(m,s,f,0x18u);return;
}
} // namespace ra2::recovered::recovery_b1705
