#include "recovered/recovery_b240_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b240 {
namespace {
void f_00360840(Memory&,State&,Frame&,const Operations&);
void f_00360ad0(Memory&,State&,Frame&,const Operations&);
void f_000349a0(Memory&,State&,Frame&,const Operations&);
void f_00034a00(Memory&,State&,Frame&,const Operations&);
void f_00360cf0(Memory&,State&,Frame&,const Operations&);
void f_00035420(Memory&,State&,Frame&,const Operations&);
void f_00035400(Memory&,State&,Frame&,const Operations&);
void f_00361c80(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_00361440(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00360840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760840: { // 0x760840: 83ec40 SUB ESP,0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L00760843: { // 0x760843: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760844: { // 0x760844: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760845: { // 0x760845: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760846: { // 0x760846: 8b7c2454 MOV EDI,dword ptr [ESP + 0x54]
    s.di = m.r32((f.sp+0x00000054u));
  }
  L0076084a: { // 0x76084a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0076084c: { // 0x76084c: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0076084e: { // 0x76084e: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00760852: { // 0x760852: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760853: { // 0x760853: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00760855: { // 0x760855: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7735384u); flags=s.arithmetic_flags;
  }
  L00760858: { // 0x760858: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0076085a: { // 0x76085a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076085c: { // 0x76085c: 8d44243c LEA EAX,[ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  L00760860: { // 0x760860: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760862: { // 0x760862: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760863: { // 0x760863: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),7735398u); flags=s.arithmetic_flags;
  }
  L00760866: { // 0x760866: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L0076086a: { // 0x76086a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076086b: { // 0x76086b: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0076086d: { // 0x76086d: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00760871: { // 0x760871: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00760874: { // 0x760874: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00760878: { // 0x760878: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0076087b: { // 0x76087b: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0076087f: { // 0x76087f: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00760883: { // 0x760883: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00760886: { // 0x760886: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0076088a: { // 0x76088a: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0076088c: { // 0x76088c: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00760890: { // 0x760890: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00760893: { // 0x760893: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00760897: { // 0x760897: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0076089a: { // 0x76089a: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0076089e: { // 0x76089e: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L007608a2: { // 0x7608a2: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L007608a5: { // 0x7608a5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007608a6: { // 0x7608a6: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L007608aa: { // 0x7608aa: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L007608ac: { // 0x7608ac: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L007608b0: { // 0x7608b0: e81b020000 CALL 0x00760ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760ad0u,7735477u); flags=s.arithmetic_flags;
  }
  L007608b5: { // 0x7608b5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L007608b7: { // 0x7608b7: 0f84cb000000 JZ 0x00760988
    if(integer::condition("JZ",flags)) goto L00760988;
  }
  L007608bd: { // 0x7608bd: 8a44245c MOV AL,byte ptr [ESP + 0x5c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000005cu)));
  }
  L007608c1: { // 0x7608c1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L007608c3: { // 0x7608c3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L007608c5: { // 0x7608c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007608c7: { // 0x7608c7: 7453 JZ 0x0076091c
    if(integer::condition("JZ",flags)) goto L0076091c;
  }
  L007608c9: { // 0x7608c9: ff5270 CALL dword ptr [EDX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000070u)),7735500u); flags=s.arithmetic_flags;
  }
  L007608cc: { // 0x7608cc: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L007608cf: { // 0x7608cf: 7532 JNZ 0x00760903
    if(integer::condition("JNZ",flags)) goto L00760903;
  }
  L007608d1: { // 0x7608d1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007608d3: { // 0x7608d3: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L007608d8: { // 0x7608d8: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L007608da: { // 0x7608da: 8d442468 LEA EAX,[ESP + 0x68]
    s.ax = (f.sp+0x00000068u);
  }
  L007608de: { // 0x7608de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007608e0: { // 0x7608e0: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L007608e4: { // 0x7608e4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007608e5: { // 0x7608e5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007608e6: { // 0x7608e6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007608e7: { // 0x7608e7: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L007608eb: { // 0x7608eb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007608ed: { // 0x7608ed: c7442478ccaa7900 MOV dword ptr [ESP + 0x78],0x79aacc
    m.w32((f.sp+0x00000078u), 0x0079aaccu);
  }
  L007608f5: { // 0x7608f5: e8a640cdff CALL 0x004349a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004349a0u,7735546u); flags=s.arithmetic_flags;
  }
  L007608fa: { // 0x7608fa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007608fb: { // 0x7608fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007608fc: { // 0x7608fc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007608fd: { // 0x7608fd: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00760900: { // 0x760900: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00760903: { // 0x760903: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760905: { // 0x760905: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L0076090a: { // 0x76090a: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0076090c: { // 0x76090c: c7442460bcaa7900 MOV dword ptr [ESP + 0x60],0x79aabc
    m.w32((f.sp+0x00000060u), 0x0079aabcu);
  }
  L00760914: { // 0x760914: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760916: { // 0x760916: 8d542464 LEA EDX,[ESP + 0x64]
    s.dx = (f.sp+0x00000064u);
  }
  L0076091a: { // 0x76091a: eb51 JMP 0x0076096d
    goto L0076096d;
  }
  L0076091c: { // 0x76091c: ff5270 CALL dword ptr [EDX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000070u)),7735583u); flags=s.arithmetic_flags;
  }
  L0076091f: { // 0x76091f: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00760922: { // 0x760922: 7532 JNZ 0x00760956
    if(integer::condition("JNZ",flags)) goto L00760956;
  }
  L00760924: { // 0x760924: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760926: { // 0x760926: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L0076092b: { // 0x76092b: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0076092d: { // 0x76092d: 8d44245c LEA EAX,[ESP + 0x5c]
    s.ax = (f.sp+0x0000005cu);
  }
  L00760931: { // 0x760931: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760933: { // 0x760933: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00760937: { // 0x760937: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760938: { // 0x760938: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760939: { // 0x760939: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076093a: { // 0x76093a: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L0076093e: { // 0x76093e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760940: { // 0x760940: c744246cacaa7900 MOV dword ptr [ESP + 0x6c],0x79aaac
    m.w32((f.sp+0x0000006cu), 0x0079aaacu);
  }
  L00760948: { // 0x760948: e85340cdff CALL 0x004349a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004349a0u,7735629u); flags=s.arithmetic_flags;
  }
  L0076094d: { // 0x76094d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076094e: { // 0x76094e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076094f: { // 0x76094f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760950: { // 0x760950: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00760953: { // 0x760953: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00760956: { // 0x760956: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760958: { // 0x760958: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L0076095d: { // 0x76095d: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0076095f: { // 0x76095f: c74424649caa7900 MOV dword ptr [ESP + 0x64],0x79aa9c
    m.w32((f.sp+0x00000064u), 0x0079aa9cu);
  }
  L00760967: { // 0x760967: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760969: { // 0x760969: 8d542468 LEA EDX,[ESP + 0x68]
    s.dx = (f.sp+0x00000068u);
  }
  L0076096d: { // 0x76096d: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00760971: { // 0x760971: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760972: { // 0x760972: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760973: { // 0x760973: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760974: { // 0x760974: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L00760978: { // 0x760978: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0076097a: { // 0x76097a: e82140cdff CALL 0x004349a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004349a0u,7735679u); flags=s.arithmetic_flags;
  }
  L0076097f: { // 0x76097f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760980: { // 0x760980: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760981: { // 0x760981: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760982: { // 0x760982: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00760985: { // 0x760985: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00760988: { // 0x760988: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760989: { // 0x760989: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076098a: { // 0x76098a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0076098c: { // 0x76098c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076098d: { // 0x76098d: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00760990: { // 0x760990: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_00360ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760ad0: { // 0x760ad0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00760ad3: { // 0x760ad3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760ad4: { // 0x760ad4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760ad5: { // 0x760ad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760ad6: { // 0x760ad6: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00760ada: { // 0x760ada: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00760adc: { // 0x760adc: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760adf: { // 0x760adf: 394e08 CMP dword ptr [ESI + 0x8],ECX
    (void)integer::sub(m.r32((s.si+0x00000008u)),s.cx,32,flags);
  }
  L00760ae2: { // 0x760ae2: 0f852e010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760ae8: { // 0x760ae8: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760aeb: { // 0x760aeb: 8b5f0c MOV EBX,dword ptr [EDI + 0xc]
    s.bx = m.r32((s.di+0x0000000cu));
  }
  L00760aee: { // 0x760aee: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760af0: { // 0x760af0: 0f8520010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760af6: { // 0x760af6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760af8: { // 0x760af8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760afa: { // 0x760afa: 7d1d JGE 0x00760b19
    if(integer::condition("JGE",flags)) goto L00760b19;
  }
  L00760afc: { // 0x760afc: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760afe: { // 0x760afe: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b00: { // 0x760b00: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L00760b02: { // 0x760b02: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b04: { // 0x760b04: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b06: { // 0x760b06: 894708 MOV dword ptr [EDI + 0x8],EAX
    m.w32((s.di+0x00000008u), s.ax);
  }
  L00760b09: { // 0x760b09: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00760b0b: { // 0x760b0b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760b0e: { // 0x760b0e: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L00760b14: { // 0x760b14: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b16: { // 0x760b16: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00760b19: { // 0x760b19: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b1c: { // 0x760b1c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b1e: { // 0x760b1e: 7d25 JGE 0x00760b45
    if(integer::condition("JGE",flags)) goto L00760b45;
  }
  L00760b20: { // 0x760b20: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L00760b23: { // 0x760b23: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760b26: { // 0x760b26: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b28: { // 0x760b28: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00760b2b: { // 0x760b2b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b2e: { // 0x760b2e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760b30: { // 0x760b30: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760b33: { // 0x760b33: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00760b36: { // 0x760b36: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b39: { // 0x760b39: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00760b40: { // 0x760b40: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b42: { // 0x760b42: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00760b45: { // 0x760b45: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b47: { // 0x760b47: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L00760b4a: { // 0x760b4a: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L00760b4d: { // 0x760b4d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00760b4f: { // 0x760b4f: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760b51: { // 0x760b51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b53: { // 0x760b53: 7e10 JLE 0x00760b65
    if(integer::condition("JLE",flags)) goto L00760b65;
  }
  L00760b55: { // 0x760b55: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L00760b58: { // 0x760b58: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b5a: { // 0x760b5a: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L00760b5d: { // 0x760b5d: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b60: { // 0x760b60: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b62: { // 0x760b62: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760b65: { // 0x760b65: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b68: { // 0x760b68: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760b6b: { // 0x760b6b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00760b6e: { // 0x760b6e: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760b70: { // 0x760b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00760b72: { // 0x760b72: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b74: { // 0x760b74: 7e10 JLE 0x00760b86
    if(integer::condition("JLE",flags)) goto L00760b86;
  }
  L00760b76: { // 0x760b76: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760b79: { // 0x760b79: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00760b7b: { // 0x760b7b: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760b7e: { // 0x760b7e: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760b81: { // 0x760b81: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b83: { // 0x760b83: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760b86: { // 0x760b86: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b88: { // 0x760b88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b8a: { // 0x760b8a: 7d1e JGE 0x00760baa
    if(integer::condition("JGE",flags)) goto L00760baa;
  }
  L00760b8c: { // 0x760b8c: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L00760b8e: { // 0x760b8e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b90: { // 0x760b90: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L00760b92: { // 0x760b92: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b94: { // 0x760b94: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00760b97: { // 0x760b97: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760b99: { // 0x760b99: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00760b9c: { // 0x760b9c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b9f: { // 0x760b9f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760ba1: { // 0x760ba1: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760ba4: { // 0x760ba4: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L00760baa: { // 0x760baa: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bad: { // 0x760bad: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760baf: { // 0x760baf: 7d22 JGE 0x00760bd3
    if(integer::condition("JGE",flags)) goto L00760bd3;
  }
  L00760bb1: { // 0x760bb1: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L00760bb4: { // 0x760bb4: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760bb6: { // 0x760bb6: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00760bb9: { // 0x760bb9: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bbc: { // 0x760bbc: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760bbf: { // 0x760bbf: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760bc1: { // 0x760bc1: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760bc4: { // 0x760bc4: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760bc7: { // 0x760bc7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760bc9: { // 0x760bc9: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760bcc: { // 0x760bcc: c7470400000000 MOV dword ptr [EDI + 0x4],0x0
    m.w32((s.di+0x00000004u), 0x00000000u);
  }
  L00760bd3: { // 0x760bd3: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00760bd7: { // 0x760bd7: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760bda: { // 0x760bda: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00760bdc: { // 0x760bdc: 8b5a08 MOV EBX,dword ptr [EDX + 0x8]
    s.bx = m.r32((s.dx+0x00000008u));
  }
  L00760bdf: { // 0x760bdf: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760be1: { // 0x760be1: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760be3: { // 0x760be3: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760be5: { // 0x760be5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760be7: { // 0x760be7: 7e0d JLE 0x00760bf6
    if(integer::condition("JLE",flags)) goto L00760bf6;
  }
  L00760be9: { // 0x760be9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760beb: { // 0x760beb: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  L00760bee: { // 0x760bee: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760bf1: { // 0x760bf1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760bf3: { // 0x760bf3: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760bf6: { // 0x760bf6: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bf9: { // 0x760bf9: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760bfc: { // 0x760bfc: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760bff: { // 0x760bff: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760c01: { // 0x760c01: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760c03: { // 0x760c03: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c05: { // 0x760c05: 7e63 JLE 0x00760c6a
    if(integer::condition("JLE",flags)) goto L00760c6a;
  }
  L00760c07: { // 0x760c07: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c09: { // 0x760c09: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760c0c: { // 0x760c0c: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760c0f: { // 0x760c0f: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c11: { // 0x760c11: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760c14: { // 0x760c14: eb54 JMP 0x00760c6a
    goto L00760c6a;
  }
  L00760c16: { // 0x760c16: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c18: { // 0x760c18: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c1a: { // 0x760c1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760c1b: { // 0x760c1b: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c1d: { // 0x760c1d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c21: { // 0x760c21: e8caf1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736358u); flags=s.arithmetic_flags;
  }
  L00760c26: { // 0x760c26: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c28: { // 0x760c28: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c2a: { // 0x760c2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2c: { // 0x760c2c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2e: { // 0x760c2e: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c30: { // 0x760c30: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c33: { // 0x760c33: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c36: { // 0x760c36: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c39: { // 0x760c39: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c3c: { // 0x760c3c: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c3f: { // 0x760c3f: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00760c43: { // 0x760c43: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c46: { // 0x760c46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760c47: { // 0x760c47: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c49: { // 0x760c49: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c4d: { // 0x760c4d: e89ef1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736402u); flags=s.arithmetic_flags;
  }
  L00760c52: { // 0x760c52: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c54: { // 0x760c54: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c56: { // 0x760c56: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c58: { // 0x760c58: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c5b: { // 0x760c5b: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c5e: { // 0x760c5e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c61: { // 0x760c61: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c64: { // 0x760c64: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c67: { // 0x760c67: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c6a: { // 0x760c6a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760c6d: { // 0x760c6d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c6f: { // 0x760c6f: 7e23 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c71: { // 0x760c71: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760c74: { // 0x760c74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c76: { // 0x760c76: 7e1c JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c78: { // 0x760c78: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760c7b: { // 0x760c7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c7d: { // 0x760c7d: 7e15 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c7f: { // 0x760c7f: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760c82: { // 0x760c82: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c84: { // 0x760c84: 7e0e JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c86: { // 0x760c86: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c87: { // 0x760c87: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c88: { // 0x760c88: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00760c8d: { // 0x760c8d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c8e: { // 0x760c8e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c91: { // 0x760c91: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00760c94: { // 0x760c94: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c95: { // 0x760c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c96: { // 0x760c96: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00760c98: { // 0x760c98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c99: { // 0x760c99: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c9c: { // 0x760c9c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000349a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004349a0: { // 0x4349a0: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004349a4: { // 0x4349a4: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L004349a7: { // 0x4349a7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004349a8: { // 0x4349a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004349a9: { // 0x4349a9: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004349ab: { // 0x4349ab: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L004349ad: { // 0x4349ad: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L004349b1: { // 0x4349b1: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L004349b5: { // 0x4349b5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004349b6: { // 0x4349b6: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L004349ba: { // 0x4349ba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004349bb: { // 0x4349bb: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L004349bf: { // 0x4349bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004349c0: { // 0x4349c0: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L004349c4: { // 0x4349c4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004349c5: { // 0x4349c5: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L004349c9: { // 0x4349c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004349ca: { // 0x4349ca: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L004349cc: { // 0x4349cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004349cd: { // 0x4349cd: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004349d1: { // 0x4349d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004349d2: { // 0x4349d2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004349d3: { // 0x4349d3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004349d5: { // 0x4349d5: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4409816u); flags=s.arithmetic_flags;
  }
  L004349d8: { // 0x4349d8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004349da: { // 0x4349da: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004349dc: { // 0x4349dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004349dd: { // 0x4349dd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004349de: { // 0x4349de: 8d44243c LEA EAX,[ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  L004349e2: { // 0x4349e2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004349e3: { // 0x4349e3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004349e4: { // 0x4349e4: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),4409831u); flags=s.arithmetic_flags;
  }
  L004349e7: { // 0x4349e7: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004349e9: { // 0x4349e9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004349eb: { // 0x4349eb: e810000000 CALL 0x00434a00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434a00u,4409840u); flags=s.arithmetic_flags;
  }
  L004349f0: { // 0x4349f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004349f1: { // 0x4349f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004349f2: { // 0x4349f2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004349f3: { // 0x4349f3: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L004349f6: { // 0x4349f6: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}
void f_00034a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00434a00: { // 0x434a00: 83ec48 SUB ESP,0x48
    f.sp = integer::sub(f.sp,0x00000048u,32,flags);
  }
  L00434a03: { // 0x434a03: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00434a07: { // 0x434a07: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434a08: { // 0x434a08: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434a09: { // 0x434a09: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00434a0a: { // 0x434a0a: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00434a0c: { // 0x434a0c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434a0d: { // 0x434a0d: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00434a0f: { // 0x434a0f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00434a11: { // 0x434a11: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00434a15: { // 0x434a15: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434a17: { // 0x434a17: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00434a1a: { // 0x434a1a: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00434a1e: { // 0x434a1e: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00434a22: { // 0x434a22: c644246800 MOV byte ptr [ESP + 0x68],0x0
    m.w8((f.sp+0x00000068u), 0x00000000u);
  }
  L00434a27: { // 0x434a27: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00434a2a: { // 0x434a2a: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00434a2e: { // 0x434a2e: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L00434a32: { // 0x434a32: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00434a36: { // 0x434a36: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00434a39: { // 0x434a39: 897c245c MOV dword ptr [ESP + 0x5c],EDI
    m.w32((f.sp+0x0000005cu), s.di);
  }
  L00434a3d: { // 0x434a3d: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00434a41: { // 0x434a41: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00434a43: { // 0x434a43: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00434a47: { // 0x434a47: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00434a49: { // 0x434a49: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00434a4c: { // 0x434a4c: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00434a50: { // 0x434a50: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00434a54: { // 0x434a54: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L00434a58: { // 0x434a58: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00434a5b: { // 0x434a5b: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L00434a5f: { // 0x434a5f: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00434a63: { // 0x434a63: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00434a67: { // 0x434a67: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L00434a6a: { // 0x434a6a: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L00434a6e: { // 0x434a6e: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00434a71: { // 0x434a71: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L00434a75: { // 0x434a75: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L00434a79: { // 0x434a79: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L00434a7d: { // 0x434a7d: 8d14c5f8907b00 LEA EDX,[EAX*0x8 + 0x7b90f8]
    s.dx = ((s.ax * 0x00000008u)+0x007b90f8u);
  }
  L00434a84: { // 0x434a84: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00434a88: { // 0x434a88: 89542474 MOV dword ptr [ESP + 0x74],EDX
    m.w32((f.sp+0x00000074u), s.dx);
  }
  L00434a8c: { // 0x434a8c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434a8d: { // 0x434a8d: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L00434a91: { // 0x434a91: 8d44246c LEA EAX,[ESP + 0x6c]
    s.ax = (f.sp+0x0000006cu);
  }
  L00434a95: { // 0x434a95: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434a96: { // 0x434a96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434a97: { // 0x434a97: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00434a9b: { // 0x434a9b: 8d542454 LEA EDX,[ESP + 0x54]
    s.dx = (f.sp+0x00000054u);
  }
  L00434a9f: { // 0x434a9f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434aa0: { // 0x434aa0: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434aa4: { // 0x434aa4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434aa5: { // 0x434aa5: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L00434aa9: { // 0x434aa9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434aaa: { // 0x434aaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434aab: { // 0x434aab: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00434aad: { // 0x434aad: e83ec23200 CALL 0x00760cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760cf0u,4410034u); flags=s.arithmetic_flags;
  }
  L00434ab2: { // 0x434ab2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00434ab4: { // 0x434ab4: 750a JNZ 0x00434ac0
    if(integer::condition("JNZ",flags)) goto L00434ac0;
  }
  L00434ab6: { // 0x434ab6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00434ab7: { // 0x434ab7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00434ab8: { // 0x434ab8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00434ab9: { // 0x434ab9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00434aba: { // 0x434aba: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00434abd: { // 0x434abd: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
  L00434ac0: { // 0x434ac0: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00434ac6: { // 0x434ac6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434ac8: { // 0x434ac8: 7429 JZ 0x00434af3
    if(integer::condition("JZ",flags)) goto L00434af3;
  }
  L00434aca: { // 0x434aca: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434acc: { // 0x434acc: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L00434ad0: { // 0x434ad0: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00434ad4: { // 0x434ad4: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00434ad6: { // 0x434ad6: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00434ad9: { // 0x434ad9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434adb: { // 0x434adb: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00434ade: { // 0x434ade: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00434ae2: { // 0x434ae2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434ae4: { // 0x434ae4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434ae5: { // 0x434ae5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434ae6: { // 0x434ae6: e845c7fdff CALL 0x00411230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4410091u); flags=s.arithmetic_flags;
  }
  L00434aeb: { // 0x434aeb: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L00434aef: { // 0x434aef: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434af3: { // 0x434af3: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L00434af9: { // 0x434af9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434afb: { // 0x434afb: 0f84c6000000 JZ 0x00434bc7
    if(integer::condition("JZ",flags)) goto L00434bc7;
  }
  L00434b01: { // 0x434b01: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00434b05: { // 0x434b05: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L00434b08: { // 0x434b08: 8b6904 MOV EBP,dword ptr [ECX + 0x4]
    s.bp = m.r32((s.cx+0x00000004u));
  }
  L00434b0b: { // 0x434b0b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434b0d: { // 0x434b0d: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L00434b11: { // 0x434b11: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00434b13: { // 0x434b13: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00434b17: { // 0x434b17: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00434b19: { // 0x434b19: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L00434b1b: { // 0x434b1b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434b1c: { // 0x434b1c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434b1d: { // 0x434b1d: e85ed13200 CALL 0x00761c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761c80u,4410146u); flags=s.arithmetic_flags;
  }
  L00434b22: { // 0x434b22: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00434b24: { // 0x434b24: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434b26: { // 0x434b26: 8b7c2474 MOV EDI,dword ptr [ESP + 0x74]
    s.di = m.r32((f.sp+0x00000074u));
  }
  L00434b2a: { // 0x434b2a: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00434b2d: { // 0x434b2d: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00434b30: { // 0x434b30: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00434b34: { // 0x434b34: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00434b38: { // 0x434b38: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b39: { // 0x434b39: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434b3b: { // 0x434b3b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00434b3d: { // 0x434b3d: 8a4714 MOV AL,byte ptr [EDI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000014u)));
  }
  L00434b40: { // 0x434b40: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00434b42: { // 0x434b42: 7430 JZ 0x00434b74
    if(integer::condition("JZ",flags)) goto L00434b74;
  }
  L00434b44: { // 0x434b44: 8b15ac1f8200 MOV EDX,dword ptr [0x00821fac]
    s.dx = m.r32((0x00821facu));
  }
  L00434b4a: { // 0x434b4a: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00434b4d: { // 0x434b4d: 668b4224 MOV AX,word ptr [EDX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.dx+0x00000024u)));
  }
  L00434b51: { // 0x434b51: 66034204 ADD AX,word ptr [EDX + 0x4]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000004u)),16,flags));
  }
  L00434b55: { // 0x434b55: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00434b59: { // 0x434b59: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434b5b: { // 0x434b5b: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434b5f: { // 0x434b5f: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L00434b63: { // 0x434b63: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00434b68: { // 0x434b68: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434b6a: { // 0x434b6a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b6b: { // 0x434b6b: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434b6d: { // 0x434b6d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00434b6f: { // 0x434b6f: 0faff9 IMUL EDI,ECX
    s.di = integer::imul(s.di,s.cx,32,flags);
  }
  L00434b72: { // 0x434b72: eb53 JMP 0x00434bc7
    goto L00434bc7;
  }
  L00434b74: { // 0x434b74: 8b15ac1f8200 MOV EDX,dword ptr [0x00821fac]
    s.dx = m.r32((0x00821facu));
  }
  L00434b7a: { // 0x434b7a: 8b5c2444 MOV EBX,dword ptr [ESP + 0x44]
    s.bx = m.r32((f.sp+0x00000044u));
  }
  L00434b7e: { // 0x434b7e: 668b4224 MOV AX,word ptr [EDX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.dx+0x00000024u)));
  }
  L00434b82: { // 0x434b82: 66034204 ADD AX,word ptr [EDX + 0x4]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000004u)),16,flags));
  }
  L00434b86: { // 0x434b86: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00434b8a: { // 0x434b8a: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00434b8c: { // 0x434b8c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434b8e: { // 0x434b8e: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L00434b92: { // 0x434b92: 8b742470 MOV ESI,dword ptr [ESP + 0x70]
    s.si = m.r32((f.sp+0x00000070u));
  }
  L00434b96: { // 0x434b96: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00434b97: { // 0x434b97: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00434b9c: { // 0x434b9c: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00434b9e: { // 0x434b9e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b9f: { // 0x434b9f: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434ba1: { // 0x434ba1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00434ba3: { // 0x434ba3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00434ba5: { // 0x434ba5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434ba6: { // 0x434ba6: 0faff9 IMUL EDI,ECX
    s.di = integer::imul(s.di,s.cx,32,flags);
  }
  L00434ba9: { // 0x434ba9: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434bab: { // 0x434bab: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00434bad: { // 0x434bad: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00434baf: { // 0x434baf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434bb0: { // 0x434bb0: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434bb2: { // 0x434bb2: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434bb6: { // 0x434bb6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00434bb8: { // 0x434bb8: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00434bba: { // 0x434bba: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434bbc: { // 0x434bbc: 7509 JNZ 0x00434bc7
    if(integer::condition("JNZ",flags)) goto L00434bc7;
  }
  L00434bbe: { // 0x434bbe: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L00434bc2: { // 0x434bc2: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434bc4: { // 0x434bc4: 037910 ADD EDI,dword ptr [ECX + 0x10]
    s.di = integer::add(s.di,m.r32((s.cx+0x00000010u)),32,flags);
  }
  L00434bc7: { // 0x434bc7: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434bcb: { // 0x434bcb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bcd: { // 0x434bcd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434bcf: { // 0x434bcf: ff5270 CALL dword ptr [EDX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000070u)),4410322u); flags=s.arithmetic_flags;
  }
  L00434bd2: { // 0x434bd2: 0faf442440 IMUL EAX,dword ptr [ESP + 0x40]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000040u)),32,flags);
  }
  L00434bd7: { // 0x434bd7: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L00434bdb: { // 0x434bdb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434bdd: { // 0x434bdd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bdf: { // 0x434bdf: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410338u); flags=s.arithmetic_flags;
  }
  L00434be2: { // 0x434be2: 39442470 CMP dword ptr [ESP + 0x70],EAX
    (void)integer::sub(m.r32((f.sp+0x00000070u)),s.ax,32,flags);
  }
  L00434be6: { // 0x434be6: 757e JNZ 0x00434c66
    if(integer::condition("JNZ",flags)) goto L00434c66;
  }
  L00434be8: { // 0x434be8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434bea: { // 0x434bea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bec: { // 0x434bec: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410351u); flags=s.arithmetic_flags;
  }
  L00434bef: { // 0x434bef: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434bf3: { // 0x434bf3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00434bf5: { // 0x434bf5: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00434bf7: { // 0x434bf7: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410362u); flags=s.arithmetic_flags;
  }
  L00434bfa: { // 0x434bfa: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00434bfc: { // 0x434bfc: 7564 JNZ 0x00434c62
    if(integer::condition("JNZ",flags)) goto L00434c62;
  }
  L00434bfe: { // 0x434bfe: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00434c02: { // 0x434c02: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00434c06: { // 0x434c06: 0faf442454 IMUL EAX,dword ptr [ESP + 0x54]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000054u)),32,flags);
  }
  L00434c0b: { // 0x434c0b: 0faf4c2444 IMUL ECX,dword ptr [ESP + 0x44]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L00434c10: { // 0x434c10: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00434c12: { // 0x434c12: 7c02 JL 0x00434c16
    if(integer::condition("JL",flags)) goto L00434c16;
  }
  L00434c14: { // 0x434c14: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00434c16: { // 0x434c16: 8a4c2468 MOV CL,byte ptr [ESP + 0x68]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000068u)));
  }
  L00434c1a: { // 0x434c1a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00434c1c: { // 0x434c1c: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00434c20: { // 0x434c20: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434c22: { // 0x434c22: 741e JZ 0x00434c42
    if(integer::condition("JZ",flags)) goto L00434c42;
  }
  L00434c24: { // 0x434c24: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L00434c29: { // 0x434c29: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2b: { // 0x434c2b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2d: { // 0x434c2d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2f: { // 0x434c2f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c30: { // 0x434c30: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434c34: { // 0x434c34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c35: { // 0x434c35: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00434c39: { // 0x434c39: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c3a: { // 0x434c3a: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4410429u); flags=s.arithmetic_flags;
  }
  L00434c3d: { // 0x434c3d: e9b5020000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434c42: { // 0x434c42: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c44: { // 0x434c44: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L00434c49: { // 0x434c49: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4b: { // 0x434c4b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4d: { // 0x434c4d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4f: { // 0x434c4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c50: { // 0x434c50: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434c54: { // 0x434c54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c55: { // 0x434c55: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434c59: { // 0x434c59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c5a: { // 0x434c5a: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),4410461u); flags=s.arithmetic_flags;
  }
  L00434c5d: { // 0x434c5d: e995020000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434c62: { // 0x434c62: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434c66: { // 0x434c66: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434c6a: { // 0x434c6a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434c6c: { // 0x434c6c: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410479u); flags=s.arithmetic_flags;
  }
  L00434c6f: { // 0x434c6f: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L00434c73: { // 0x434c73: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434c75: { // 0x434c75: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434c77: { // 0x434c77: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410490u); flags=s.arithmetic_flags;
  }
  L00434c7a: { // 0x434c7a: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L00434c80: { // 0x434c80: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00434c84: { // 0x434c84: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434c86: { // 0x434c86: 7407 JZ 0x00434c8f
    if(integer::condition("JZ",flags)) goto L00434c8f;
  }
  L00434c88: { // 0x434c88: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  L00434c8b: { // 0x434c8b: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00434c8f: { // 0x434c8f: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00434c95: { // 0x434c95: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434c97: { // 0x434c97: 7407 JZ 0x00434ca0
    if(integer::condition("JZ",flags)) goto L00434ca0;
  }
  L00434c99: { // 0x434c99: 8b5128 MOV EDX,dword ptr [ECX + 0x28]
    s.dx = m.r32((s.cx+0x00000028u));
  }
  L00434c9c: { // 0x434c9c: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00434ca0: { // 0x434ca0: 8a4c2468 MOV CL,byte ptr [ESP + 0x68]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000068u)));
  }
  L00434ca4: { // 0x434ca4: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00434ca6: { // 0x434ca6: 0f84c4000000 JZ 0x00434d70
    if(integer::condition("JZ",flags)) goto L00434d70;
  }
  L00434cac: { // 0x434cac: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L00434cb0: { // 0x434cb0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434cb4: { // 0x434cb4: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L00434cb6: { // 0x434cb6: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00434cb8: { // 0x434cb8: 894c2470 MOV dword ptr [ESP + 0x70],ECX
    m.w32((f.sp+0x00000070u), s.cx);
  }
  L00434cbc: { // 0x434cbc: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434cc0: { // 0x434cc0: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00434cc4: { // 0x434cc4: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434cc8: { // 0x434cc8: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434cca: { // 0x434cca: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00434cce: { // 0x434cce: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434cd0: { // 0x434cd0: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00434cd2: { // 0x434cd2: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00434cd6: { // 0x434cd6: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410585u); flags=s.arithmetic_flags;
  }
  L00434cd9: { // 0x434cd9: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00434cdd: { // 0x434cdd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434cdf: { // 0x434cdf: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00434ce0: { // 0x434ce0: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00434ce3: { // 0x434ce3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00434ce7: { // 0x434ce7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434ce9: { // 0x434ce9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00434ced: { // 0x434ced: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434cef: { // 0x434cef: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410610u); flags=s.arithmetic_flags;
  }
  L00434cf2: { // 0x434cf2: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00434cf6: { // 0x434cf6: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00434cf7: { // 0x434cf7: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00434cfa: { // 0x434cfa: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434cfe: { // 0x434cfe: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434d00: { // 0x434d00: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434d05: { // 0x434d05: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d07: { // 0x434d07: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434d0b: { // 0x434d0b: 742d JZ 0x00434d3a
    if(integer::condition("JZ",flags)) goto L00434d3a;
  }
  L00434d0d: { // 0x434d0d: 8b4828 MOV ECX,dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L00434d10: { // 0x434d10: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00434d12: { // 0x434d12: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434d14: { // 0x434d14: c1e21f SHL EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::left);
  }
  L00434d17: { // 0x434d17: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00434d19: { // 0x434d19: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00434d1d: { // 0x434d1d: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00434d1f: { // 0x434d1f: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434d23: { // 0x434d23: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L00434d26: { // 0x434d26: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434d28: { // 0x434d28: 7203 JC 0x00434d2d
    if(integer::condition("JC",flags)) goto L00434d2d;
  }
  L00434d2a: { // 0x434d2a: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434d2d: { // 0x434d2d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00434d32: { // 0x434d32: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00434d34: { // 0x434d34: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434d38: { // 0x434d38: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00434d3a: { // 0x434d3a: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434d3f: { // 0x434d3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d41: { // 0x434d41: 7431 JZ 0x00434d74
    if(integer::condition("JZ",flags)) goto L00434d74;
  }
  L00434d43: { // 0x434d43: 8b4028 MOV EAX,dword ptr [EAX + 0x28]
    s.ax = m.r32((s.ax+0x00000028u));
  }
  L00434d46: { // 0x434d46: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00434d48: { // 0x434d48: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434d4a: { // 0x434d4a: c1e21f SHL EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::left);
  }
  L00434d4d: { // 0x434d4d: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00434d4f: { // 0x434d4f: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00434d53: { // 0x434d53: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00434d55: { // 0x434d55: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434d59: { // 0x434d59: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434d5c: { // 0x434d5c: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434d62: { // 0x434d62: 3b421c CMP EAX,dword ptr [EDX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000001cu)),32,flags);
  }
  L00434d65: { // 0x434d65: 7203 JC 0x00434d6a
    if(integer::condition("JC",flags)) goto L00434d6a;
  }
  L00434d67: { // 0x434d67: 2b4220 SUB EAX,dword ptr [EDX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434d6a: { // 0x434d6a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434d6e: { // 0x434d6e: eb04 JMP 0x00434d74
    goto L00434d74;
  }
  L00434d70: { // 0x434d70: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434d74: { // 0x434d74: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00434d78: { // 0x434d78: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00434d7c: { // 0x434d7c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00434d7e: { // 0x434d7e: 7c02 JL 0x00434d82
    if(integer::condition("JL",flags)) goto L00434d82;
  }
  L00434d80: { // 0x434d80: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00434d82: { // 0x434d82: 8a542468 MOV DL,byte ptr [ESP + 0x68]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000068u)));
  }
  L00434d86: { // 0x434d86: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00434d88: { // 0x434d88: 0f84b6000000 JZ 0x00434e44
    if(integer::condition("JZ",flags)) goto L00434e44;
  }
  L00434d8e: { // 0x434d8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d90: { // 0x434d90: 0f8e65010000 JLE 0x00434efb
    if(integer::condition("JLE",flags)) goto L00434efb;
  }
  L00434d96: { // 0x434d96: 8b74246c MOV ESI,dword ptr [ESP + 0x6c]
    s.si = m.r32((f.sp+0x0000006cu));
  }
  L00434d9a: { // 0x434d9a: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434d9e: { // 0x434d9e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434da2: { // 0x434da2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434da4: { // 0x434da4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434da5: { // 0x434da5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00434da9: { // 0x434da9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434daa: { // 0x434daa: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00434dae: { // 0x434dae: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434daf: { // 0x434daf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434db0: { // 0x434db0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434db1: { // 0x434db1: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434db5: { // 0x434db5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434db6: { // 0x434db6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00434db7: { // 0x434db7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434db9: { // 0x434db9: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4410812u); flags=s.arithmetic_flags;
  }
  L00434dbc: { // 0x434dbc: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434dc0: { // 0x434dc0: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L00434dc4: { // 0x434dc4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00434dc8: { // 0x434dc8: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00434dca: { // 0x434dca: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434dce: { // 0x434dce: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434dd2: { // 0x434dd2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434dd4: { // 0x434dd4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00434dd8: { // 0x434dd8: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434ddd: { // 0x434ddd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434ddf: { // 0x434ddf: 7429 JZ 0x00434e0a
    if(integer::condition("JZ",flags)) goto L00434e0a;
  }
  L00434de1: { // 0x434de1: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434de5: { // 0x434de5: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434de9: { // 0x434de9: 8b5018 MOV EDX,dword ptr [EAX + 0x18]
    s.dx = m.r32((s.ax+0x00000018u));
  }
  L00434dec: { // 0x434dec: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434dee: { // 0x434dee: 7303 JNC 0x00434df3
    if(integer::condition("JNC",flags)) goto L00434df3;
  }
  L00434df0: { // 0x434df0: 036820 ADD EBP,dword ptr [EAX + 0x20]
    s.bp = integer::add(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434df3: { // 0x434df3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00434df7: { // 0x434df7: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00434df9: { // 0x434df9: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434dfd: { // 0x434dfd: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434dff: { // 0x434dff: 7c09 JL 0x00434e0a
    if(integer::condition("JL",flags)) goto L00434e0a;
  }
  L00434e01: { // 0x434e01: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00434e05: { // 0x434e05: 037a10 ADD EDI,dword ptr [EDX + 0x10]
    s.di = integer::add(s.di,m.r32((s.dx+0x00000010u)),32,flags);
  }
  L00434e08: { // 0x434e08: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00434e0a: { // 0x434e0a: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434e0f: { // 0x434e0f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e11: { // 0x434e11: 741d JZ 0x00434e30
    if(integer::condition("JZ",flags)) goto L00434e30;
  }
  L00434e13: { // 0x434e13: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434e17: { // 0x434e17: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00434e1b: { // 0x434e1b: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434e1e: { // 0x434e1e: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434e24: { // 0x434e24: 3b4218 CMP EAX,dword ptr [EDX + 0x18]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000018u)),32,flags);
  }
  L00434e27: { // 0x434e27: 7303 JNC 0x00434e2c
    if(integer::condition("JNC",flags)) goto L00434e2c;
  }
  L00434e29: { // 0x434e29: 034220 ADD EAX,dword ptr [EDX + 0x20]
    s.ax = integer::add(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434e2c: { // 0x434e2c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434e30: { // 0x434e30: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00434e34: { // 0x434e34: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00434e35: { // 0x434e35: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434e39: { // 0x434e39: 0f855fffffff JNZ 0x00434d9e
    if(integer::condition("JNZ",flags)) goto L00434d9e;
  }
  L00434e3f: { // 0x434e3f: e9b3000000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434e44: { // 0x434e44: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e46: { // 0x434e46: 0f8eaf000000 JLE 0x00434efb
    if(integer::condition("JLE",flags)) goto L00434efb;
  }
  L00434e4c: { // 0x434e4c: 8b74246c MOV ESI,dword ptr [ESP + 0x6c]
    s.si = m.r32((f.sp+0x0000006cu));
  }
  L00434e50: { // 0x434e50: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434e54: { // 0x434e54: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L00434e58: { // 0x434e58: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434e5a: { // 0x434e5a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e5b: { // 0x434e5b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00434e5f: { // 0x434e5f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434e61: { // 0x434e61: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e62: { // 0x434e62: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00434e66: { // 0x434e66: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434e67: { // 0x434e67: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434e68: { // 0x434e68: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e69: { // 0x434e69: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00434e6d: { // 0x434e6d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e6e: { // 0x434e6e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00434e6f: { // 0x434e6f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434e71: { // 0x434e71: ff5004 CALL dword ptr [EAX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000004u)),4410996u); flags=s.arithmetic_flags;
  }
  L00434e74: { // 0x434e74: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434e78: { // 0x434e78: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L00434e7c: { // 0x434e7c: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00434e80: { // 0x434e80: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434e82: { // 0x434e82: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00434e86: { // 0x434e86: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434e8a: { // 0x434e8a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00434e8c: { // 0x434e8c: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434e91: { // 0x434e91: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e93: { // 0x434e93: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00434e97: { // 0x434e97: 7429 JZ 0x00434ec2
    if(integer::condition("JZ",flags)) goto L00434ec2;
  }
  L00434e99: { // 0x434e99: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434e9d: { // 0x434e9d: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434ea1: { // 0x434ea1: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L00434ea4: { // 0x434ea4: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434ea6: { // 0x434ea6: 7203 JC 0x00434eab
    if(integer::condition("JC",flags)) goto L00434eab;
  }
  L00434ea8: { // 0x434ea8: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434eab: { // 0x434eab: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00434eaf: { // 0x434eaf: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00434eb1: { // 0x434eb1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434eb5: { // 0x434eb5: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434eb7: { // 0x434eb7: 7c09 JL 0x00434ec2
    if(integer::condition("JL",flags)) goto L00434ec2;
  }
  L00434eb9: { // 0x434eb9: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00434ebd: { // 0x434ebd: 037a10 ADD EDI,dword ptr [EDX + 0x10]
    s.di = integer::add(s.di,m.r32((s.dx+0x00000010u)),32,flags);
  }
  L00434ec0: { // 0x434ec0: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00434ec2: { // 0x434ec2: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434ec7: { // 0x434ec7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434ec9: { // 0x434ec9: 741d JZ 0x00434ee8
    if(integer::condition("JZ",flags)) goto L00434ee8;
  }
  L00434ecb: { // 0x434ecb: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434ecf: { // 0x434ecf: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00434ed3: { // 0x434ed3: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434ed6: { // 0x434ed6: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434edc: { // 0x434edc: 3b421c CMP EAX,dword ptr [EDX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000001cu)),32,flags);
  }
  L00434edf: { // 0x434edf: 7203 JC 0x00434ee4
    if(integer::condition("JC",flags)) goto L00434ee4;
  }
  L00434ee1: { // 0x434ee1: 2b4220 SUB EAX,dword ptr [EDX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434ee4: { // 0x434ee4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434ee8: { // 0x434ee8: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00434eec: { // 0x434eec: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00434eed: { // 0x434eed: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434ef1: { // 0x434ef1: 0f855dffffff JNZ 0x00434e54
    if(integer::condition("JNZ",flags)) goto L00434e54;
  }
  L00434ef7: { // 0x434ef7: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434efb: { // 0x434efb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434efd: { // 0x434efd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434eff: { // 0x434eff: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4411138u); flags=s.arithmetic_flags;
  }
  L00434f02: { // 0x434f02: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434f06: { // 0x434f06: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434f08: { // 0x434f08: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4411147u); flags=s.arithmetic_flags;
  }
  L00434f0b: { // 0x434f0b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00434f0d: { // 0x434f0d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00434f0e: { // 0x434f0e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00434f0f: { // 0x434f0f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00434f10: { // 0x434f10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00434f11: { // 0x434f11: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00434f14: { // 0x434f14: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
}
void f_00360cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760cf0: { // 0x760cf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00760cf3: { // 0x760cf3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00760cf7: { // 0x760cf7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760cf8: { // 0x760cf8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760cf9: { // 0x760cf9: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00760cfb: { // 0x760cfb: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00760cff: { // 0x760cff: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00760d01: { // 0x760d01: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00760d05: { // 0x760d05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760d06: { // 0x760d06: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L00760d0a: { // 0x760d0a: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  L00760d0d: { // 0x760d0d: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L00760d13: { // 0x760d13: c70200000000 MOV dword ptr [EDX],0x0
    m.w32((s.dx), 0x00000000u);
  }
  L00760d19: { // 0x760d19: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760d1c: { // 0x760d1c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760d1d: { // 0x760d1d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d1f: { // 0x760d1f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00760d23: { // 0x760d23: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00760d27: { // 0x760d27: 0f8e53010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d2d: { // 0x760d2d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760d30: { // 0x760d30: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d32: { // 0x760d32: 0f8e48010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d38: { // 0x760d38: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00760d3b: { // 0x760d3b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d3d: { // 0x760d3d: 0f8e3d010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d43: { // 0x760d43: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00760d46: { // 0x760d46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d48: { // 0x760d48: 0f8e32010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d4e: { // 0x760d4e: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00760d52: { // 0x760d52: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760d55: { // 0x760d55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d57: { // 0x760d57: 0f8e23010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d5d: { // 0x760d5d: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760d60: { // 0x760d60: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d62: { // 0x760d62: 0f8e18010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d68: { // 0x760d68: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00760d6c: { // 0x760d6c: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760d6f: { // 0x760d6f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00760d71: { // 0x760d71: 0f8e09010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d77: { // 0x760d77: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00760d7a: { // 0x760d7a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00760d7c: { // 0x760d7c: 0f8efe000000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d82: { // 0x760d82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760d83: { // 0x760d83: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760d84: { // 0x760d84: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00760d86: { // 0x760d86: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760d88: { // 0x760d88: e843fdffff CALL 0x00760ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760ad0u,7736717u); flags=s.arithmetic_flags;
  }
  L00760d8d: { // 0x760d8d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00760d8f: { // 0x760d8f: 0f84eb000000 JZ 0x00760e80
    if(integer::condition("JZ",flags)) goto L00760e80;
  }
  L00760d95: { // 0x760d95: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00760d99: { // 0x760d99: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  L00760d9c: { // 0x760d9c: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00760da0: { // 0x760da0: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760da2: { // 0x760da2: 7547 JNZ 0x00760deb
    if(integer::condition("JNZ",flags)) goto L00760deb;
  }
  L00760da4: { // 0x760da4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00760da6: { // 0x760da6: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760da9: { // 0x760da9: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760dab: { // 0x760dab: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00760dad: { // 0x760dad: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00760daf: { // 0x760daf: 7d36 JGE 0x00760de7
    if(integer::condition("JGE",flags)) goto L00760de7;
  }
  L00760db1: { // 0x760db1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760db4: { // 0x760db4: 8b6e0c MOV EBP,dword ptr [ESI + 0xc]
    s.bp = m.r32((s.si+0x0000000cu));
  }
  L00760db7: { // 0x760db7: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00760dba: { // 0x760dba: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L00760dbc: { // 0x760dbc: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00760dbe: { // 0x760dbe: 7d23 JGE 0x00760de3
    if(integer::condition("JGE",flags)) goto L00760de3;
  }
  L00760dc0: { // 0x760dc0: 8beb MOV EBP,EBX
    s.bp = s.bx;
  }
  L00760dc2: { // 0x760dc2: 036f08 ADD EBP,dword ptr [EDI + 0x8]
    s.bp = integer::add(s.bp,m.r32((s.di+0x00000008u)),32,flags);
  }
  L00760dc5: { // 0x760dc5: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00760dc7: { // 0x760dc7: 7e1a JLE 0x00760de3
    if(integer::condition("JLE",flags)) goto L00760de3;
  }
  L00760dc9: { // 0x760dc9: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00760dcb: { // 0x760dcb: 036f0c ADD EBP,dword ptr [EDI + 0xc]
    s.bp = integer::add(s.bp,m.r32((s.di+0x0000000cu)),32,flags);
  }
  L00760dce: { // 0x760dce: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00760dd0: { // 0x760dd0: 7e11 JLE 0x00760de3
    if(integer::condition("JLE",flags)) goto L00760de3;
  }
  L00760dd2: { // 0x760dd2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00760dd4: { // 0x760dd4: 7c06 JL 0x00760ddc
    if(integer::condition("JL",flags)) goto L00760ddc;
  }
  L00760dd6: { // 0x760dd6: 750b JNZ 0x00760de3
    if(integer::condition("JNZ",flags)) goto L00760de3;
  }
  L00760dd8: { // 0x760dd8: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00760dda: { // 0x760dda: 7d07 JGE 0x00760de3
    if(integer::condition("JGE",flags)) goto L00760de3;
  }
  L00760ddc: { // 0x760ddc: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00760de0: { // 0x760de0: c60201 MOV byte ptr [EDX],0x1
    m.w8((s.dx), 0x00000001u);
  }
  L00760de3: { // 0x760de3: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00760de7: { // 0x760de7: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00760deb: { // 0x760deb: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00760def: { // 0x760def: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760df1: { // 0x760df1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760df2: { // 0x760df2: e82946cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736823u); flags=s.arithmetic_flags;
  }
  L00760df7: { // 0x760df7: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00760dfb: { // 0x760dfb: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00760dff: { // 0x760dff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e00: { // 0x760e00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760e01: { // 0x760e01: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760e02: { // 0x760e02: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00760e04: { // 0x760e04: e81746cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736841u); flags=s.arithmetic_flags;
  }
  L00760e09: { // 0x760e09: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00760e0b: { // 0x760e0b: e8f045cdff CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,7736848u); flags=s.arithmetic_flags;
  }
  L00760e10: { // 0x760e10: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00760e12: { // 0x760e12: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00760e15: { // 0x760e15: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00760e17: { // 0x760e17: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00760e19: { // 0x760e19: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00760e1c: { // 0x760e1c: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00760e1f: { // 0x760e1f: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00760e21: { // 0x760e21: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00760e23: { // 0x760e23: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7736870u); flags=s.arithmetic_flags;
  }
  L00760e26: { // 0x760e26: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760e28: { // 0x760e28: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00760e2c: { // 0x760e2c: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00760e2e: { // 0x760e2e: 7450 JZ 0x00760e80
    if(integer::condition("JZ",flags)) goto L00760e80;
  }
  L00760e30: { // 0x760e30: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00760e34: { // 0x760e34: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00760e36: { // 0x760e36: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760e37: { // 0x760e37: e8e445cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736892u); flags=s.arithmetic_flags;
  }
  L00760e3c: { // 0x760e3c: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00760e40: { // 0x760e40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e41: { // 0x760e41: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00760e45: { // 0x760e45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e46: { // 0x760e46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760e47: { // 0x760e47: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00760e4b: { // 0x760e4b: e8d045cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736912u); flags=s.arithmetic_flags;
  }
  L00760e50: { // 0x760e50: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00760e52: { // 0x760e52: e8a945cdff CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,7736919u); flags=s.arithmetic_flags;
  }
  L00760e57: { // 0x760e57: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00760e59: { // 0x760e59: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00760e5c: { // 0x760e5c: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00760e5e: { // 0x760e5e: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00760e60: { // 0x760e60: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00760e63: { // 0x760e63: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00760e66: { // 0x760e66: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00760e6a: { // 0x760e6a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00760e6c: { // 0x760e6c: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7736943u); flags=s.arithmetic_flags;
  }
  L00760e6f: { // 0x760e6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760e71: { // 0x760e71: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00760e75: { // 0x760e75: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00760e77: { // 0x760e77: 7513 JNZ 0x00760e8c
    if(integer::condition("JNZ",flags)) goto L00760e8c;
  }
  L00760e79: { // 0x760e79: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00760e7b: { // 0x760e7b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00760e7d: { // 0x760e7d: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7736960u); flags=s.arithmetic_flags;
  }
  L00760e80: { // 0x760e80: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00760e82: { // 0x760e82: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760e83: { // 0x760e83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760e84: { // 0x760e84: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00760e85: { // 0x760e85: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760e86: { // 0x760e86: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00760e89: { // 0x760e89: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L00760e8c: { // 0x760e8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760e8d: { // 0x760e8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760e8e: { // 0x760e8e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00760e8f: { // 0x760e8f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00760e91: { // 0x760e91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760e92: { // 0x760e92: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00760e95: { // 0x760e95: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}
void f_00035420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435420: { // 0x435420: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00435424: { // 0x435424: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00435426: { // 0x435426: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00435429: { // 0x435429: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0043542b: { // 0x43542b: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0043542e: { // 0x43542e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00035400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435400: { // 0x435400: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435404: { // 0x435404: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435405: { // 0x435405: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00435407: { // 0x435407: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00435409: { // 0x435409: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0043540b: { // 0x43540b: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0043540e: { // 0x43540e: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00435411: { // 0x435411: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00435413: { // 0x435413: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435417: { // 0x435417: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00435419: { // 0x435419: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L0043541c: { // 0x43541c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043541d: { // 0x43541d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00361c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761c80: { // 0x761c80: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00761c84: { // 0x761c84: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00761c85: { // 0x761c85: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00761c87: { // 0x761c87: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00761c88: { // 0x761c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c89: { // 0x761c89: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00761c8d: { // 0x761c8d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c90: { // 0x761c90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c91: { // 0x761c91: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c93: { // 0x761c93: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000005cu)),7740566u); flags=s.arithmetic_flags;
  }
  L00761c96: { // 0x761c96: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c99: { // 0x761c99: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00761c9b: { // 0x761c9b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c9d: { // 0x761c9d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),7740576u); flags=s.arithmetic_flags;
  }
  L00761ca0: { // 0x761ca0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00761ca3: { // 0x761ca3: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00761ca6: { // 0x761ca6: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00761ca8: { // 0x761ca8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00761caa: { // 0x761caa: 7203 JC 0x00761caf
    if(integer::condition("JC",flags)) goto L00761caf;
  }
  L00761cac: { // 0x761cac: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L00761caf: { // 0x761caf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761cb0: { // 0x761cb0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761cb1: { // 0x761cb1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000112f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112f0: { // 0x4112f0: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L004112f3: { // 0x4112f3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004112f4: { // 0x4112f4: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004112f7: { // 0x4112f7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004112f9: { // 0x4112f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00011290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411290: { // 0x411290: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00411294: { // 0x411294: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411295: { // 0x411295: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411296: { // 0x411296: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411297: { // 0x411297: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0041129a: { // 0x41129a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L0041129d: { // 0x41129d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0041129f: { // 0x41129f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004112a1: { // 0x4112a1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004112a3: { // 0x4112a3: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L004112a5: { // 0x4112a5: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L004112a8: { // 0x4112a8: 897b08 MOV dword ptr [EBX + 0x8],EDI
    m.w32((s.bx+0x00000008u), s.di);
  }
  L004112ab: { // 0x4112ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004112ac: { // 0x4112ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004112ad: { // 0x4112ad: 894b0c MOV dword ptr [EBX + 0xc],ECX
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L004112b0: { // 0x4112b0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004112b1: { // 0x4112b1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00361440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761440: { // 0x761440: 8b44240c MOV EAX, dword ptr [ESP + 0xC]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00761444: { // 0x761444: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00761446: { // 0x761446: 7e20 JLE 0x761468
    if(integer::condition("JLE",flags)) goto L00761468;
  }
  L00761448: { // 0x761448: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L0076144c: { // 0x76144c: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00761450: { // 0x761450: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00761451: { // 0x761451: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00761453: { // 0x761453: 668b01 MOV AX, word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L00761456: { // 0x761456: 83c102 ADD ECX, 2
    s.cx = integer::add(s.cx,2u,32,flags);
  }
  L00761459: { // 0x761459: 6685c0 TEST AX, AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L0076145c: { // 0x76145c: 7403 JZ 0x761461
    if(integer::condition("JZ",flags)) goto L00761461;
  }
  L0076145e: { // 0x76145e: 668902 MOV word ptr [EDX], AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  L00761461: { // 0x761461: 83c202 ADD EDX, 2
    s.dx = integer::add(s.dx,2u,32,flags);
  }
  L00761464: { // 0x761464: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00761465: { // 0x761465: 75ec JNZ 0x761453
    if(integer::condition("JNZ",flags)) goto L00761453;
  }
  L00761467: { // 0x761467: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761468: { // 0x761468: c22000 RET 0x20
    s.arithmetic_flags=flags; finish(m,s,f,32u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7735360u:f_00360840(m,s,child,{});break;
case 7736016u:f_00360ad0(m,s,child,{});break;
case 4409760u:f_000349a0(m,s,child,{});break;
case 4409856u:f_00034a00(m,s,child,{});break;
case 7736560u:f_00360cf0(m,s,child,{});break;
case 4412448u:f_00035420(m,s,child,{});break;
case 4412416u:f_00035400(m,s,child,{});break;
case 7740544u:f_00361c80(m,s,child,{});break;
case 4264816u:f_00011370(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264592u:f_00011290(m,s,child,{});break;
case 7738432u:f_00361440(m,s,child,{});break;
default:throw std::domain_error("recovery240 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004308f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004308f0: { // 0x4308f0: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L004308f3: { // 0x4308f3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004308f4: { // 0x4308f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004308f5: { // 0x4308f5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004308f7: { // 0x4308f7: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  L004308fa: { // 0x4308fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004308fc: { // 0x4308fc: 0f84a6000000 JZ 0x004309a8
    if(integer::condition("JZ",flags)) goto L004309a8;
  }
  L00430902: { // 0x430902: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L00430905: { // 0x430905: 0f849d000000 JZ 0x004309a8
    if(integer::condition("JZ",flags)) goto L004309a8;
  }
  L0043090b: { // 0x43090b: 8b481c MOV ECX,dword ptr [EAX + 0x1c]
    s.cx = m.r32((s.ax+0x0000001cu));
  }
  L0043090e: { // 0x43090e: 8d6814 LEA EBP,[EAX + 0x14]
    s.bp = (s.ax+0x00000014u);
  }
  L00430911: { // 0x430911: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00430913: { // 0x430913: 0f8e8f000000 JLE 0x004309a8
    if(integer::condition("JLE",flags)) goto L004309a8;
  }
  L00430919: { // 0x430919: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0043091c: { // 0x43091c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043091e: { // 0x43091e: 0f8e84000000 JLE 0x004309a8
    if(integer::condition("JLE",flags)) goto L004309a8;
  }
  L00430924: { // 0x430924: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00430925: { // 0x430925: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00430926: { // 0x430926: 8b7810 MOV EDI,dword ptr [EAX + 0x10]
    s.di = m.r32((s.ax+0x00000010u));
  }
  L00430929: { // 0x430929: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0043092d: { // 0x43092d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043092e: { // 0x43092e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00430930: { // 0x430930: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00430932: { // 0x430932: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4393269u); flags=s.arithmetic_flags;
  }
  L00430935: { // 0x430935: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00430937: { // 0x430937: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00430939: { // 0x430939: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0043093d: { // 0x43093d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0043093f: { // 0x43093f: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00430942: { // 0x430942: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00430943: { // 0x430943: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00430947: { // 0x430947: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00430948: { // 0x430948: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0043094b: { // 0x43094b: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0043094f: { // 0x43094f: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00430951: { // 0x430951: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00430954: { // 0x430954: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00430956: { // 0x430956: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0043095a: { // 0x43095a: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  L0043095d: { // 0x43095d: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00430960: { // 0x430960: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00430964: { // 0x430964: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L00430967: { // 0x430967: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L0043096a: { // 0x43096a: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0043096e: { // 0x43096e: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00430972: { // 0x430972: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00430974: { // 0x430974: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00430975: { // 0x430975: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00430977: { // 0x430977: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0043097b: { // 0x43097b: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043097d: { // 0x43097d: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0043097f: { // 0x43097f: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L00430982: { // 0x430982: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00430984: { // 0x430984: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  L00430987: { // 0x430987: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00430989: { // 0x430989: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L0043098b: { // 0x43098b: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L0043098e: { // 0x43098e: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00430992: { // 0x430992: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00430996: { // 0x430996: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00430998: { // 0x430998: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0043099c: { // 0x43099c: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L004309a0: { // 0x4309a0: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004309a2: { // 0x4309a2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004309a3: { // 0x4309a3: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4393382u); flags=s.arithmetic_flags;
  }
  L004309a6: { // 0x4309a6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004309a7: { // 0x4309a7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004309a8: { // 0x4309a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004309a9: { // 0x4309a9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004309aa: { // 0x4309aa: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004309ad: { // 0x4309ad: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
