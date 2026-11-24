#include "recovery_b1706.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1706 {
namespace ix=direct_b33::integer;
namespace {
void empty_child_006af7f0(Memory& m,State& s,Frame& f){
    // 0x6af7f0: SUB ESP,0x38 [83ec38]
    f.sp=ix::sub(f.sp,0x38u,32,s.arithmetic_flags);
    // 0x6af7f3: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x6af7f4: MOV EBP,ECX [8be9]
    s.bp=s.cx;
    // 0x6af7f6: PUSH ESI [56]
    f.push(m,s.si);
    // 0x6af7f7: MOV byte ptr [ESP + 0xa],0x1 [c644240a01]
    m.w8(f.sp+0xau,1u);
    // 0x6af7fc: MOV ESI,dword ptr [EBP + 0x54] [8b7554]
    s.si=m.r32(s.bp+0x54u);
    // 0x6af7ff: MOV byte ptr [ESP + 0xb],0x0 [c644240b00]
    m.w8(f.sp+0xbu,0u);
    // 0x6af804: TEST ESI,ESI [85f6]
    (void)ix::logical(s.si,32,s.arithmetic_flags);
    // 0x6af806: JZ 0x006afc43 [0f8437040000]
    if(!ix::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("2B2200 actual empty-child member branch");
    // 0x6afc43: POP ESI [5e]
    s.si=f.pop(m);
    // 0x6afc44: POP EBP [5d]
    s.bp=f.pop(m);
    // 0x6afc45: ADD ESP,0x38 [83c438]
    f.sp=ix::add(f.sp,0x38u,32,s.arithmetic_flags);
    // 0x6afc48: RET [c3]
    recovery_b566::finish(m,s,f,0u);
}
}
void execute_selected(Memory& m,State& s,Frame& f){
    // Outside-observation finite owner/bounds/nonalias preflight is caller-owned.
    // 0x6b2200: SUB ESP,0x3c [83ec3c]
    f.sp=ix::sub(f.sp,0x3cu,32,s.arithmetic_flags);
    // 0x6b2203: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x6b2204: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x6b2205: PUSH ESI [56]
    f.push(m,s.si);
    // 0x6b2206: PUSH EDI [57]
    f.push(m,s.di);
    // 0x6b2207: MOV EDI,ECX [8bf9]
    s.di=s.cx;
    // 0x6b2209: MOV byte ptr [ESP + 0x13],0x1 [c644241301]
    m.w8(f.sp+0x13u,1u);
    // 0x6b220e: MOV dword ptr [ESP + 0x14],EDI [897c2414]
    m.w32(f.sp+0x14u,s.di);
    // 0x6b2212: MOV EAX,dword ptr [EDI + 0x30] [8b4730]
    s.ax=m.r32(s.di+0x30u);
    // 0x6b2215: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax,32,s.arithmetic_flags);
    // 0x6b2217: JNZ 0x006b24ee [0f85d1020000]
    if(!ix::condition("JNZ",s.arithmetic_flags))
        throw std::domain_error("2B2200 actual nonzero public field30 branch");
    // 0x6b24ee: MOV ESI,dword ptr [EDI + 0x54] [8b7754]
    s.si=m.r32(s.di+0x54u);
    // 0x6b24f1: OR EBP,0xffffffff [83cdff]
    s.bp=ix::logical(s.bp|0xffffffffu,32,s.arithmetic_flags);
    // 0x6b24f4: TEST ESI,ESI [85f6]
    (void)ix::logical(s.si,32,s.arithmetic_flags);
    // 0x6b24f6: MOV EBX,ESI [8bde]
    s.bx=s.si;
    // 0x6b24f8: JZ 0x006b2558 [745e]
    if(!ix::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("2B2200 actual empty Root member branch");
    // 0x6b2558: TEST EBX,EBX [85db]
    (void)ix::logical(s.bx,32,s.arithmetic_flags);
    // 0x6b255a: JZ 0x006b2586 [742a]
    if(!ix::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("2B2200 actual zero member candidate branch");
    // 0x6b2586: MOV ECX,EDI [8bcf]
    s.cx=s.di;
    // 0x6b2588: CALL 0x006af7f0 [e863d2ffff]
    {
        f.push(m,0x6b258du);
        Frame child{f.sp,f.sp,0x6b258du};
        const U child_entry=child.entry_sp;
        empty_child_006af7f0(m,s,child);
        if(child.entry_sp!=child_entry||child.outer_return!=0x6b258du||
           child.sp!=child_entry+4u)
            throw std::runtime_error("2B2200 genuine child CALL/RET0 frame imbalance");
        f.sp=child.sp;
    }
    // 0x6b258d: MOV AL,byte ptr [ESP + 0x13] [8a442413]
    s.ax=(s.ax&0xffffff00u)|m.r8(f.sp+0x13u);
    // 0x6b2591: TEST AL,AL [84c0]
    (void)ix::logical(s.ax&0xffu,8,s.arithmetic_flags);
    // 0x6b2593: JZ 0x006b25a6 [7411]
    if(ix::condition("JZ",s.arithmetic_flags))
        throw std::domain_error("2B2200 naturally produced Root flag is nonzero");
    // 0x6b2595: MOV byte ptr [EDI + 0x80],0x0 [c6878000000000]
    m.w8(s.di+0x80u,0u);
    // 0x6b259c: POP EDI [5f]
    s.di=f.pop(m);
    // 0x6b259d: POP ESI [5e]
    s.si=f.pop(m);
    // 0x6b259e: POP EBP [5d]
    s.bp=f.pop(m);
    // 0x6b259f: POP EBX [5b]
    s.bx=f.pop(m);
    // 0x6b25a0: ADD ESP,0x3c [83c43c]
    f.sp=ix::add(f.sp,0x3cu,32,s.arithmetic_flags);
    // 0x6b25a3: RET 0x8 [c20800]
    recovery_b566::finish(m,s,f,8u);
}
} // namespace ra2::recovered::recovery_b1706
