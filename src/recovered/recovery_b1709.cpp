#include "recovery_b1709.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b1709 {
namespace ix=direct_b33::integer;
namespace {
void outside(){throw std::domain_error("2C7750 outside selected direct warm-hit domain");}
void need(bool ok){if(!ok)outside();}
struct Range{U base,size;};
bool separate(Range a,Range b){return std::uint64_t(a.base)+a.size<=b.base||std::uint64_t(b.base)+b.size<=a.base;}
void readable(const Memory&m,Range r){need(r.size&&std::uint64_t(r.base)+r.size<=0x100000000ull);for(U k=0;k<r.size;++k)(void)m.r8(r.base+k);}
void unit80_6b6910(Memory&m,State&s,Frame&f){
    // 0x006b6910 / RVA 0x2b6910: MOV EAX,[ECX] [8b01]
    s.ax=m.r32(s.cx);
    // 0x006b6912 / RVA 0x2b6912: JMP DWORD[EAX+84h] [ffa084000000]
    if(m.r32(s.ax+0x84u)!=0x6f9c70u)outside();
    // Tail jump uses the SAME actual CALL word/Frame, no extra PUSH or cleanup.
    // 0x006f9c70 / RVA 0x2f9c70: MOV EAX,[ECX+5AC] [8b81ac050000]
    s.ax=m.r32(s.cx+0x5acu);
    // 0x006f9c76 / RVA 0x2f9c76: RET [c3]
    recovery_b566::finish(m,s,f,0u);
}
}
void require_root_warm_basis(const Memory&m,const State&s,const Frame&f){
    // Readonly Root-prefix admission only; NOT new-child/physical ownership GO.
    need(f.sp==f.entry_sp&&f.entry_sp>=0x64u&&f.entry_sp<=0xffffffbbu);
    need(m.r32(f.entry_sp)==f.outer_return&&(s.arithmetic_flags&0x400u)==0u);
    const Range stack{f.entry_sp-0x64u,0xa8u};readable(m,stack);
    const U self=s.cx;readable(m,{self,0x5ccu});need(m.r32(self)==0x798c88u&&m.r32(self+0x1b8u)==0u);
    need(m.r32(0x798d08u)==0x6b6910u&&m.r32(0x798d0cu)==0x6f9c70u);
    const U type=m.r32(self+0x5acu);need(type!=0u);readable(m,{type,0xba8u});
    need(m.r8(type+0xb48u)==0u&&m.r8(type+0xb5bu)==0u);
    const U d=m.r32(f.entry_sp+4u),key=m.r32(f.entry_sp+0xcu),cache=m.r32(f.entry_sp+0x10u);
    need(d&&cache&&key!=0xffffffffu);readable(m,{d,4u});readable(m,{cache,0x14u});
    const U h=m.r32(d);need(h!=0u);readable(m,{h,1u});need(m.r8(h)==0u);
    const U a=m.r32(cache),count=m.r32(cache+4u),capacity=m.r32(cache+8u);
    need(a&&count==1u&&capacity==1u&&m.r32(cache+0x10u)==a&&m.r32(cache+0xcu)==0u);
    need((a&3u)==0u);readable(m,{a,8u});need(m.r32(a)==key);
    const U value=m.r32(a+4u),clip=m.r32(f.entry_sp+0x14u),translation=m.r32(f.entry_sp+0x18u);
    need(value&&clip&&translation);readable(m,{value,12u});readable(m,{clip,16u});readable(m,{translation,8u});
    // Genuine positive render inputs are forwarded, never replaced with outputs.
    need(m.r32(translation)==0u&&m.r32(translation+4u)==0u);
    need(m.r32(clip)==0u&&m.r32(clip+4u)==0u&&m.r32(clip+8u)==1u&&m.r32(clip+0xcu)==1u);
    need(m.r16(value)==0u&&m.r16(value+2u)==0u&&m.r16(value+4u)==1u&&m.r16(value+6u)==1u);
    const Range public_spans[]={{self,0x5ccu},{type,0xba8u},{d,4u},{h,1u},{cache,0x14u},{a,8u},{value,12u},{clip,16u},{translation,8u},{0x798c88u,0x88u}};
    for(U i=0;i<10u;++i){need(separate(public_spans[i],stack));for(U j=0;j<i;++j)need(separate(public_spans[i],public_spans[j]));}
    // Cache capacity backing and complete child source/renderer/depth domains,
    // deeper private extent, lifetime and whole public-world guards are pending.
    // No unwritten private word is tested against a fabricated value; no FP reset.
}
void execute_selected(Memory&m,State&s,Frame&f){
    require_root_warm_basis(m,s,f);
    // 0x006c7750 / RVA 0x2c7750: SUB ESP, 0x3c [83ec3c]
    f.sp = ix::sub(f.sp,0x3cu,32u,s.arithmetic_flags);
    // 0x006c7753 / RVA 0x2c7753: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c7754 / RVA 0x2c7754: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x006c7755 / RVA 0x2c7755: PUSH ESI [56]
    f.push(m,s.si);
    // 0x006c7756 / RVA 0x2c7756: MOV ESI, ECX [8bf1]
    s.si = s.cx;
    // 0x006c7758 / RVA 0x2c7758: PUSH EDI [57]
    f.push(m,s.di);
    // 0x006c7759 / RVA 0x2c7759: MOV dword ptr [ESP + 0x10], ESI [89742410]
    m.w32((f.sp + 0x10u), s.si);
    // 0x006c775d / RVA 0x2c775d: MOV EAX, dword ptr [ESI + 0x1b8] [8b86b8010000]
    s.ax = m.r32((s.si + 0x1b8u));
    // 0x006c7763 / RVA 0x2c7763: TEST EAX, EAX [85c0]
    (void)ix::logical(s.ax & s.ax,32u,s.arithmetic_flags);
    // 0x006c7765 / RVA 0x2c7765: JNZ 0x6c7a42 [0f85d7020000]
    if (ix::condition("JNZ",s.arithmetic_flags)) outside();
    // 0x006c776b / RVA 0x2c776b: MOV EAX, dword ptr [ESI] [8b06]
    s.ax = m.r32((s.si));
    // 0x006c776d / RVA 0x2c776d: CALL dword ptr [EAX + 0x80] [ff9080000000]
    if (m.r32((s.ax + 0x80u)) != 0x6b6910u) outside();
    { f.push(m,0x6c7773u); Frame child{f.sp,f.sp,0x6c7773u}; unit80_6b6910(m,s,child); f.sp=child.sp; }
    // 0x006c7773 / RVA 0x2c7773: MOV CL, byte ptr [EAX + 0xb48] [8a88480b0000]
    s.cx = (s.cx & 0xffffff00u) | ((m.r8((s.ax + 0xb48u))) & 0xffu);
    // 0x006c7779 / RVA 0x2c7779: TEST CL, CL [84c9]
    (void)ix::logical(((s.cx >> 0u) & 0xffu) & ((s.cx >> 0u) & 0xffu),8u,s.arithmetic_flags);
    // 0x006c777b / RVA 0x2c777b: JNZ 0x6c7a42 [0f85c1020000]
    if (ix::condition("JNZ",s.arithmetic_flags)) outside();
    // 0x006c7781 / RVA 0x2c7781: MOV EDI, dword ptr [ESP + 0x50] [8b7c2450]
    s.di = m.r32((f.sp + 0x50u));
    // 0x006c7785 / RVA 0x2c7785: MOV ECX, dword ptr [EDI] [8b0f]
    s.cx = m.r32((s.di));
    // 0x006c7787 / RVA 0x2c7787: CMP byte ptr [ECX], 0 [803900]
    (void)ix::sub(m.r8((s.cx)),0x0u,8u,s.arithmetic_flags);
    // 0x006c778a / RVA 0x2c778a: JNZ 0x6c7a42 [0f85b2020000]
    if (ix::condition("JNZ",s.arithmetic_flags)) outside();
    // 0x006c7790 / RVA 0x2c7790: MOV EBX, dword ptr [ESP + 0x58] [8b5c2458]
    s.bx = m.r32((f.sp + 0x58u));
    // 0x006c7794 / RVA 0x2c7794: MOV EBP, dword ptr [ESP + 0x5c] [8b6c245c]
    s.bp = m.r32((f.sp + 0x5cu));
    // 0x006c7798 / RVA 0x2c7798: CMP EBX, -1 [83fbff]
    (void)ix::sub(s.bx,0xffffffffu,32u,s.arithmetic_flags);
    // 0x006c779b / RVA 0x2c779b: JZ 0x6c786b [0f84ca000000]
    if (ix::condition("JZ",s.arithmetic_flags)) outside();
    // 0x006c77a1 / RVA 0x2c77a1: TEST EBP, EBP [85ed]
    (void)ix::logical(s.bp & s.bp,32u,s.arithmetic_flags);
    // 0x006c77a3 / RVA 0x2c77a3: JZ 0x6c785f [0f84b6000000]
    if (ix::condition("JZ",s.arithmetic_flags)) outside();
    // 0x006c77a9 / RVA 0x2c77a9: MOV EDX, dword ptr [ESI] [8b16]
    s.dx = m.r32((s.si));
    // 0x006c77ab / RVA 0x2c77ab: MOV ECX, ESI [8bce]
    s.cx = s.si;
    // 0x006c77ad / RVA 0x2c77ad: CALL dword ptr [EDX + 0x80] [ff9280000000]
    if (m.r32((s.dx + 0x80u)) != 0x6b6910u) outside();
    { f.push(m,0x6c77b3u); Frame child{f.sp,f.sp,0x6c77b3u}; unit80_6b6910(m,s,child); f.sp=child.sp; }
    // 0x006c77b3 / RVA 0x2c77b3: MOV CL, byte ptr [EAX + 0xb5b] [8a885b0b0000]
    s.cx = (s.cx & 0xffffff00u) | ((m.r8((s.ax + 0xb5bu))) & 0xffu);
    // 0x006c77b9 / RVA 0x2c77b9: TEST CL, CL [84c9]
    (void)ix::logical(((s.cx >> 0u) & 0xffu) & ((s.cx >> 0u) & 0xffu),8u,s.arithmetic_flags);
    // 0x006c77bb / RVA 0x2c77bb: JNZ 0x6c785f [0f859e000000]
    if (ix::condition("JNZ",s.arithmetic_flags)) outside();
    // 0x006c77c1 / RVA 0x2c77c1: MOV ECX, dword ptr [EBP + 4] [8b4d04]
    s.cx = m.r32((s.bp + 0x4u));
    // 0x006c77c4 / RVA 0x2c77c4: TEST ECX, ECX [85c9]
    (void)ix::logical(s.cx & s.cx,32u,s.arithmetic_flags);
    // 0x006c77c6 / RVA 0x2c77c6: JZ 0x6c781c [7454]
    if (ix::condition("JZ",s.arithmetic_flags)) outside();
    // 0x006c77c8 / RVA 0x2c77c8: MOV EAX, dword ptr [EBP + 0x10] [8b4510]
    s.ax = m.r32((s.bp + 0x10u));
    // 0x006c77cb / RVA 0x2c77cb: TEST EAX, EAX [85c0]
    (void)ix::logical(s.ax & s.ax,32u,s.arithmetic_flags);
    // 0x006c77cd / RVA 0x2c77cd: JZ 0x6c77d3 [7404]
    if (ix::condition("JZ",s.arithmetic_flags)) outside();
    // 0x006c77cf / RVA 0x2c77cf: CMP dword ptr [EAX], EBX [3918]
    (void)ix::sub(m.r32((s.ax)),s.bx,32u,s.arithmetic_flags);
    // 0x006c77d1 / RVA 0x2c77d1: JZ 0x6c7814 [7441]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside();
    // 0x006c7814 / RVA 0x2c7814: MOV EAX, dword ptr [EBP + 0x10] [8b4510]
    s.ax = m.r32((s.bp + 0x10u));
    // 0x006c7817 / RVA 0x2c7817: ADD EAX, 4 [83c004]
    s.ax = ix::add(s.ax,0x4u,32u,s.arithmetic_flags);
    // 0x006c781a / RVA 0x2c781a: JMP 0x6c7821 [eb05]
    // Selected unconditional jump to 0x6c7821.
    // 0x006c7821 / RVA 0x2c7821: MOV EAX, dword ptr [EAX] [8b00]
    s.ax = m.r32((s.ax));
    // 0x006c7823 / RVA 0x2c7823: TEST EAX, EAX [85c0]
    (void)ix::logical(s.ax & s.ax,32u,s.arithmetic_flags);
    // 0x006c7825 / RVA 0x2c7825: JZ 0x6c784d [7426]
    if (ix::condition("JZ",s.arithmetic_flags)) outside();
    // 0x006c7827 / RVA 0x2c7827: MOV EDX, dword ptr [ESP + 0x60] [8b542460]
    s.dx = m.r32((f.sp + 0x60u));
    // 0x006c782b / RVA 0x2c782b: MOV ECX, dword ptr [ESP + 0x64] [8b4c2464]
    s.cx = m.r32((f.sp + 0x64u));
    // 0x006c782f / RVA 0x2c782f: PUSH 0x3e8 [68e8030000]
    f.push(m,0x3e8u);
    // 0x006c7834 / RVA 0x2c7834: PUSH 0x2001 [6801200000]
    f.push(m,0x2001u);
    // 0x006c7839 / RVA 0x2c7839: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x006c783a / RVA 0x2c783a: PUSH ECX [51]
    f.push(m,s.cx);
    // 0x006c783b / RVA 0x2c783b: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x006c783c / RVA 0x2c783c: MOV ECX, ESI [8bce]
    s.cx = s.si;
    // 0x006c783e / RVA 0x2c783e: CALL 0x6c7f40 [e8fd060000]
    // DECLARED ONLY: new flags0x2001/scalar0x3e8 F0/Depth child domain.
    { f.push(m,0x6c7843u); Frame child{f.sp,f.sp,0x6c7843u}; root_6c7f40(m,s,child); f.sp=child.sp; }
    if(f.sp!=f.entry_sp-0x4cu) outside(); // Required real child RET20.
    // 0x006c7843 / RVA 0x2c7843: POP EDI [5f]
    s.di = f.pop(m);
    // 0x006c7844 / RVA 0x2c7844: POP ESI [5e]
    s.si = f.pop(m);
    // 0x006c7845 / RVA 0x2c7845: POP EBP [5d]
    s.bp = f.pop(m);
    // 0x006c7846 / RVA 0x2c7846: POP EBX [5b]
    s.bx = f.pop(m);
    // 0x006c7847 / RVA 0x2c7847: ADD ESP, 0x3c [83c43c]
    f.sp = ix::add(f.sp,0x3cu,32u,s.arithmetic_flags);
    // 0x006c784a / RVA 0x2c784a: RET 0x2c [c22c00]
    recovery_b566::finish(m,s,f,0x2cu);
}
} // namespace ra2::recovered::recovery_b1709
