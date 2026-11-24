#include "recovered/recovery_b1703.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1703 {
namespace ix=direct_b33::integer;
void execute_selected(Memory& m,State& s,Frame& f,Heap& heap){
    // 0x5b6760: SUB ESP,0x124 [81ec24010000]
    f.sp=ix::sub(f.sp,0x124u,32,s.arithmetic_flags);
    // 0x5b6766: MOV EAX,[0x00a1a5cc] [a1cca5a100]
    s.ax=m.r32(0xa1a5ccu);
    // 0x5b676b: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x5b676c: PUSH ESI [56]
    f.push(m,s.si);
    // 0x5b676d: PUSH EDI [57]
    f.push(m,s.di);
    // 0x5b676e: MOV EDI,ECX [8bf9]
    s.di=s.cx;
    // 0x5b6770: MOV ESI,EDX [8bf2]
    s.si=s.dx;
    // 0x5b6772: MOV dword ptr [ESP + 0x10],EDI [897c2410]
    m.w32(f.sp+0x10u,s.di);
    // 0x5b6776: MOV EBX,dword ptr [EAX + EDI*0x4] [8b1cb8]
    s.bx=m.r32(s.ax+s.di*4u);
    // 0x5b6779: MOV AL,[0x00a2895c] [a05c89a200]
    s.ax=(s.ax&0xffffff00u)|m.r8(0xa2895cu);
    // 0x5b677e: TEST AL,AL [84c0]
    (void)ix::logical(s.ax&0xffu,8,s.arithmetic_flags);
    // 0x5b6780: MOV dword ptr [ESP + 0xc],EBX [895c240c]
    m.w32(f.sp+0xcu,s.bx);
    // 0x5b6784: JZ 0x005b679b [7415]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("1B6760 finite debug0 branch at5B6784");
    // 0x5b679b: TEST EBX,EBX [85db]
    (void)ix::logical(s.bx,32,s.arithmetic_flags);
    // 0x5b679d: JZ 0x005b6b97 [0f84f4030000]
    if(ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("1B6760 finite nonnullHouse at5B679D");
    // 0x5b67a3: MOV AL,byte ptr [EBX + 0x134] [8a8334010000]
    s.ax=(s.ax&0xffffff00u)|m.r8(s.bx+0x134u);
    // 0x5b67a9: TEST AL,AL [84c0]
    (void)ix::logical(s.ax&0xffu,8,s.arithmetic_flags);
    // 0x5b67ab: JZ 0x005b6b97 [0f84e6030000]
    if(ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("1B6760 finite activeHouse at5B67AB");
    // 0x5b67b1: CMP ESI,0x1 [83fe01]
    (void)ix::sub(s.si,1u,32,s.arithmetic_flags);
    // 0x5b67b4: MOV word ptr [ESP + 0x20],0x0 [66c74424200000]
    m.w16(f.sp+0x20u,0u);
    // 0x5b67bb: JNZ 0x005b67e2 [7525]
    if(!ix::condition("JNZ",s.arithmetic_flags))throw std::domain_error("1B6760 finite mode2 skipsmode1 at5B67BB");
    // 0x5b67e2: TEST ESI,ESI [85f6]
    (void)ix::logical(s.si,32,s.arithmetic_flags);
    // 0x5b67e4: JNZ 0x005b6811 [752b]
    if(!ix::condition("JNZ",s.arithmetic_flags))throw std::domain_error("1B6760 finite mode2 skipsmode0 at5B67E4");
    // 0x5b6811: LEA EAX,[ESP + 0x20] [8d442420]
    s.ax=f.sp+0x20u;
    // 0x5b6815: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x5b6816: CALL 0x0076ef45 [e82a871b00]
    calls::length_76ef45(m,s,f,0x5b681bu,0x76ef45u);
    // 0x5b681b: ADD ESP,0x4 [83c404]
    f.sp=ix::add(f.sp,4u,32,s.arithmetic_flags);
    // 0x5b681e: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax,32,s.arithmetic_flags);
    // 0x5b6820: JZ 0x005b686a [7448]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("1B6760 producedemptyUTF16 required at5B6820");
    // 0x5b686a: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x5b686b: PUSH EDI [57]
    f.push(m,s.di);
    // 0x5b686c: MOV ECX,0xa285c8 [b9c885a200]
    s.cx=0xa285c8u;
    // 0x5b6871: CALL 0x005243c0 [e84adbf6ff]
    calls::manager_5243c0(m,s,f,0x5b6876u,0x5243c0u,heap);
    // 0x5b6876: TEST ESI,ESI [85f6]
    (void)ix::logical(s.si,32,s.arithmetic_flags);
    // 0x5b6878: MOV EBP,0x4 [bd04000000]
    s.bp=4u;
    // 0x5b687d: JZ 0x005b6914 [0f8491000000]
    if(ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("1B6760 selectedmode2 aftermanager at5B687D");
    // 0x5b6883: MOV EAX,[0x00a2896c] [a16c89a200]
    s.ax=m.r32(0xa2896cu);
    // 0x5b6888: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax,32,s.arithmetic_flags);
    // 0x5b688a: JNZ 0x005b6898 [750c]
    if(ix::condition("JNZ",s.arithmetic_flags))throw std::domain_error("1B6760 actualpostmanager frame0 at5B688A");
    // 0x5b688c: MOV ECX,EBX [8bcb]
    s.cx=s.bx;
    // 0x5b688e: CALL 0x004e73d0 [e83d0bf3ff]
    calls::house_4e73d0(m,s,f,0x5b6893u,0x4e73d0u);
    // 0x5b6893: JMP 0x005b6954 [e9bc000000]
    // The selected unconditional jump continues at5B6954.
    // 0x5b6954: CMP dword ptr [0x00a255c8],EBP [392dc855a200]
    (void)ix::sub(m.r32(0xa255c8u),s.bp,32,s.arithmetic_flags);
    // 0x5b695a: JNZ 0x005b6a62 [0f8502010000]
    if(!ix::condition("JNZ",s.arithmetic_flags))throw std::domain_error("1B6760 finite session!=4 at5B695A");
    // 0x5b6a62: MOV ECX,dword ptr [0x00a27db8] [8b0db87da200]
    s.cx=m.r32(0xa27db8u);
    // 0x5b6a68: XOR ESI,ESI [33f6]
    s.si=ix::logical(s.si^s.si,32,s.arithmetic_flags);
    // 0x5b6a6a: TEST ECX,ECX [85c9]
    (void)ix::logical(s.cx,32,s.arithmetic_flags);
    // 0x5b6a6c: JLE 0x005b6afe [0f8e8c000000]
    if(s.cx!=0u||!ix::condition("JLE",s.arithmetic_flags))throw std::domain_error("1B6760 finite actualeventcount0 at5B6A6C");
    // 0x5b6afe: MOV EAX,[0x00a2588c] [a18c58a200]
    s.ax=m.r32(0xa2588cu);
    if(s.ax!=3u)throw std::domain_error("1B6760 finite actualcounter3 at5B6AFE");
    // 0x5b6b03: POP EBP [5d]
    s.bp=f.pop(m);
    // 0x5b6b04: DEC EAX [48]
    s.ax=ix::decrement(s.ax,32,s.arithmetic_flags);
    // 0x5b6b05: CMP EAX,0x1 [83f801]
    (void)ix::sub(s.ax,1u,32,s.arithmetic_flags);
    // 0x5b6b08: MOV [0x00a2588c],EAX [a38c58a200]
    m.w32(0xa2588cu,s.ax);
    // 0x5b6b0d: JNZ 0x005b6b97 [0f8584000000]
    if(!ix::condition("JNZ",s.arithmetic_flags))throw std::domain_error("1B6760 finite counter3to2 exit at5B6B0D");
    // 0x5b6b97: POP EDI [5f]
    s.di=f.pop(m);
    // 0x5b6b98: POP ESI [5e]
    s.si=f.pop(m);
    // 0x5b6b99: POP EBX [5b]
    s.bx=f.pop(m);
    // 0x5b6b9a: ADD ESP,0x124 [81c424010000]
    f.sp=ix::add(f.sp,0x124u,32,s.arithmetic_flags);
    // 0x5b6ba0: RET [c3]
    recovery_b566::finish(m,s,f,0u);return;
}
} // namespace ra2::recovered::recovery_b1703
