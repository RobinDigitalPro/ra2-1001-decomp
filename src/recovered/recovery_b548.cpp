#include "recovered/recovery_b548_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b548 {
namespace {
void f_00185c20(Memory&,State&,Frame&,const Operations&);
void f_00185360(Memory&,State&,Frame&,const Operations&);
void f_00185650(Memory&,State&,Frame&,const Operations&);
void f_00185830(Memory&,State&,Frame&,const Operations&);
void f_00185cc0(Memory&,State&,Frame&,const Operations&);
void f_001851f0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b540(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0007b4e0(Memory&,State&,Frame&,const Operations&);
void f_0007b500(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_0007b460(Memory&,State&,Frame&,const Operations&);
void f_0007b480(Memory&,State&,Frame&,const Operations&);
void f_0001c300(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00185c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00585c20: { // 0x585c20: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00585c23: { // 0x585c23: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  L00585c26: { // 0x585c26: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00585c27: { // 0x585c27: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00585c28: { // 0x585c28: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00585c29: { // 0x585c29: 8b7210 MOV ESI,dword ptr [EDX + 0x10]
    s.si = m.r32((s.dx+0x00000010u));
  }
  L00585c2c: { // 0x585c2c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585c2d: { // 0x585c2d: 66bfe703 MOV DI,0x3e7
    s.di = (s.di & 0xffff0000u) | ((0x000003e7u) & 0xffffu);
  }
  L00585c31: { // 0x585c31: 6633ed XOR BP,BP
    s.bp = (s.bp & 0xffff0000u) | ((integer::logical(((s.bp & 0xffffu))^((s.bp & 0xffffu)),16,flags)) & 0xffffu);
  }
  L00585c34: { // 0x585c34: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00585c35: { // 0x585c35: 668bdf MOV BX,DI
    s.bx = with_ax(s.bx, (s.di & 0xffffu));
  }
  L00585c38: { // 0x585c38: 7854 JS 0x00585c8e
    if(integer::condition("JS",flags)) goto L00585c8e;
  }
  L00585c3a: { // 0x585c3a: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L00585c3d: { // 0x585c3d: 8d14b2 LEA EDX,[EDX + ESI*0x4]
    s.dx = (s.dx+(s.si * 0x00000004u));
  }
  L00585c40: { // 0x585c40: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00585c41: { // 0x585c41: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00585c45: { // 0x585c45: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00585c49: { // 0x585c49: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00585c4d: { // 0x585c4d: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L00585c4f: { // 0x585c4f: 663bd7 CMP DX,DI
    (void)integer::sub((s.dx & 0xffffu),(s.di & 0xffffu),16,flags);
  }
  L00585c52: { // 0x585c52: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00585c56: { // 0x585c56: 7d03 JGE 0x00585c5b
    if(integer::condition("JGE",flags)) goto L00585c5b;
  }
  L00585c58: { // 0x585c58: 668bfa MOV DI,DX
    s.di = (s.di & 0xffff0000u) | (((s.dx & 0xffffu)) & 0xffffu);
  }
  L00585c5b: { // 0x585c5b: 668b74241a MOV SI,word ptr [ESP + 0x1a]
    s.si = (s.si & 0xffff0000u) | ((m.r16((f.sp+0x0000001au))) & 0xffffu);
  }
  L00585c60: { // 0x585c60: 663bf3 CMP SI,BX
    (void)integer::sub((s.si & 0xffffu),(s.bx & 0xffffu),16,flags);
  }
  L00585c63: { // 0x585c63: 7d03 JGE 0x00585c68
    if(integer::condition("JGE",flags)) goto L00585c68;
  }
  L00585c65: { // 0x585c65: 668bde MOV BX,SI
    s.bx = with_ax(s.bx, (s.si & 0xffffu));
  }
  L00585c68: { // 0x585c68: 663bd0 CMP DX,AX
    (void)integer::sub((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L00585c6b: { // 0x585c6b: 7e03 JLE 0x00585c70
    if(integer::condition("JLE",flags)) goto L00585c70;
  }
  L00585c6d: { // 0x585c6d: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L00585c70: { // 0x585c70: 663bf5 CMP SI,BP
    (void)integer::sub((s.si & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L00585c73: { // 0x585c73: 7e03 JLE 0x00585c78
    if(integer::condition("JLE",flags)) goto L00585c78;
  }
  L00585c75: { // 0x585c75: 668bee MOV BP,SI
    s.bp = (s.bp & 0xffff0000u) | (((s.si & 0xffffu)) & 0xffffu);
  }
  L00585c78: { // 0x585c78: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00585c7c: { // 0x585c7c: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00585c80: { // 0x585c80: 83ee04 SUB ESI,0x4
    s.si = integer::sub(s.si,0x00000004u,32,flags);
  }
  L00585c83: { // 0x585c83: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00585c84: { // 0x585c84: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L00585c88: { // 0x585c88: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00585c8c: { // 0x585c8c: 75bb JNZ 0x00585c49
    if(integer::condition("JNZ",flags)) goto L00585c49;
  }
  L00585c8e: { // 0x585c8e: 0fbfff MOVSX EDI,DI
    s.di = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L00585c91: { // 0x585c91: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00585c94: { // 0x585c94: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00585c96: { // 0x585c96: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L00585c98: { // 0x585c98: 0fbfdb MOVSX EBX,BX
    s.bx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00585c9b: { // 0x585c9b: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L00585c9d: { // 0x585c9d: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00585c9e: { // 0x585c9e: 0fbff5 MOVSX ESI,BP
    s.si = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00585ca1: { // 0x585ca1: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L00585ca4: { // 0x585ca4: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L00585ca6: { // 0x585ca6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00585ca7: { // 0x585ca7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585ca8: { // 0x585ca8: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00585cab: { // 0x585cab: 89700c MOV dword ptr [EAX + 0xc],ESI
    m.w32((s.ax+0x0000000cu), s.si);
  }
  L00585cae: { // 0x585cae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585caf: { // 0x585caf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585cb0: { // 0x585cb0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585cb1: { // 0x585cb1: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00585cb4: { // 0x585cb4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00185360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00585360: { // 0x585360: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00585363: { // 0x585363: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00585367: { // 0x585367: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0058536b: { // 0x58536b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058536c: { // 0x58536c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058536d: { // 0x58536d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0058536f: { // 0x58536f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00585371: { // 0x585371: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00585373: { // 0x585373: 83fa04 CMP EDX,0x4
    (void)integer::sub(s.dx,0x00000004u,32,flags);
  }
  L00585376: { // 0x585376: 0f94442418 SETZ byte ptr [ESP + 0x18]
    m.w8((f.sp+0x00000018u), (integer::condition("SETZ",flags)?1u:0u));
  }
  L0058537b: { // 0x58537b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058537c: { // 0x58537c: 83fa02 CMP EDX,0x2
    (void)integer::sub(s.dx,0x00000002u,32,flags);
  }
  L0058537f: { // 0x58537f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585380: { // 0x585380: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00585384: { // 0x585384: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00585388: { // 0x585388: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0058538c: { // 0x58538c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00585390: { // 0x585390: 752a JNZ 0x005853bc
    if(integer::condition("JNZ",flags)) goto L005853bc;
  }
  L00585392: { // 0x585392: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00585394: { // 0x585394: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00585399: { // 0x585399: be03000000 MOV ESI,0x3
    s.si = 0x00000003u;
  }
  L0058539e: { // 0x58539e: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005853a2: { // 0x5853a2: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L005853a6: { // 0x5853a6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005853a8: { // 0x5853a8: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L005853aa: { // 0x5853aa: c744241cfdffffff MOV dword ptr [ESP + 0x1c],0xfffffffd
    m.w32((f.sp+0x0000001cu), 0xfffffffdu);
  }
  L005853b2: { // 0x5853b2: c744241806000000 MOV dword ptr [ESP + 0x18],0x6
    m.w32((f.sp+0x00000018u), 0x00000006u);
  }
  L005853ba: { // 0x5853ba: eb25 JMP 0x005853e1
    goto L005853e1;
  }
  L005853bc: { // 0x5853bc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005853be: { // 0x5853be: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L005853c3: { // 0x5853c3: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  L005853c8: { // 0x5853c8: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005853cc: { // 0x5853cc: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L005853d0: { // 0x5853d0: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005853d2: { // 0x5853d2: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L005853d4: { // 0x5853d4: bdfdffffff MOV EBP,0xfffffffd
    s.bp = 0xfffffffdu;
  }
  L005853d9: { // 0x5853d9: c744241406000000 MOV dword ptr [ESP + 0x14],0x6
    m.w32((f.sp+0x00000014u), 0x00000006u);
  }
  L005853e1: { // 0x5853e1: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L005853e5: { // 0x5853e5: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005853e8: { // 0x5853e8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005853ea: { // 0x5853ea: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005853ec: { // 0x5853ec: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L005853f1: { // 0x5853f1: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L005853f3: { // 0x5853f3: 7d64 JGE 0x00585459
    if(integer::condition("JGE",flags)) goto L00585459;
  }
  L005853f5: { // 0x5853f5: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L005853f8: { // 0x5853f8: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L005853fb: { // 0x5853fb: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L005853fd: { // 0x5853fd: 0fbf542412 MOVSX EDX,word ptr [ESP + 0x12]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00585402: { // 0x585402: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00585404: { // 0x585404: 7d53 JGE 0x00585459
    if(integer::condition("JGE",flags)) goto L00585459;
  }
  L00585406: { // 0x585406: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0058540a: { // 0x58540a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0058540f: { // 0x58540f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00585410: { // 0x585410: e8eb00fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5788693u); flags=s.arithmetic_flags;
  }
  L00585415: { // 0x585415: 8b4838 MOV ECX,dword ptr [EAX + 0x38]
    s.cx = m.r32((s.ax+0x00000038u));
  }
  L00585418: { // 0x585418: a1185da500 MOV EAX,[0x00a55d18]
    s.ax = m.r32((0x00a55d18u));
  }
  L0058541d: { // 0x58541d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0058541f: { // 0x58541f: 7458 JZ 0x00585479
    if(integer::condition("JZ",flags)) goto L00585479;
  }
  L00585421: { // 0x585421: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00585425: { // 0x585425: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00585428: { // 0x585428: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L00585430: { // 0x585430: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L00585437: { // 0x585437: 66034c2410 ADD CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  L0058543c: { // 0x58543c: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L00585440: { // 0x585440: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L00585445: { // 0x585445: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L0058544a: { // 0x58544a: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L0058544f: { // 0x58544f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00585453: { // 0x585453: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00585457: { // 0x585457: eb8c JMP 0x005853e5
    goto L005853e5;
  }
  L00585459: { // 0x585459: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0058545b: { // 0x58545b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058545c: { // 0x58545c: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L00585461: { // 0x585461: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00585466: { // 0x585466: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0058546a: { // 0x58546a: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0058546e: { // 0x58546e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058546f: { // 0x58546f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585470: { // 0x585470: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00585472: { // 0x585472: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585473: { // 0x585473: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00585476: { // 0x585476: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00585479: { // 0x585479: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0058547d: { // 0x58547d: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L00585480: { // 0x585480: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00585482: { // 0x585482: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00585485: { // 0x585485: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00585487: { // 0x585487: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00585489: { // 0x585489: 0f8d86000000 JGE 0x00585515
    if(integer::condition("JGE",flags)) goto L00585515;
  }
  L0058548f: { // 0x58548f: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L00585492: { // 0x585492: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00585497: { // 0x585497: 035604 ADD EDX,dword ptr [ESI + 0x4]
    s.dx = integer::add(s.dx,m.r32((s.si+0x00000004u)),32,flags);
  }
  L0058549a: { // 0x58549a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0058549c: { // 0x58549c: 7d77 JGE 0x00585515
    if(integer::condition("JGE",flags)) goto L00585515;
  }
  L0058549e: { // 0x58549e: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L005854a0: { // 0x5854a0: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005854a4: { // 0x5854a4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005854a8: { // 0x5854a8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005854aa: { // 0x5854aa: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005854ae: { // 0x5854ae: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L005854b2: { // 0x5854b2: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005854b6: { // 0x5854b6: 8d140f LEA EDX,[EDI + ECX*0x1]
    s.dx = (s.di+(s.cx * 0x00000001u));
  }
  L005854b9: { // 0x5854b9: 8d0c03 LEA ECX,[EBX + EAX*0x1]
    s.cx = (s.bx+(s.ax * 0x00000001u));
  }
  L005854bc: { // 0x5854bc: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L005854c0: { // 0x5854c0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005854c4: { // 0x5854c4: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L005854c8: { // 0x5854c8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005854c9: { // 0x5854c9: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L005854cd: { // 0x5854cd: e85e030000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5788882u); flags=s.arithmetic_flags;
  }
  L005854d2: { // 0x5854d2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005854d4: { // 0x5854d4: 755f JNZ 0x00585535
    if(integer::condition("JNZ",flags)) goto L00585535;
  }
  L005854d6: { // 0x5854d6: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L005854da: { // 0x5854da: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L005854dd: { // 0x5854dd: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L005854e5: { // 0x5854e5: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L005854ed: { // 0x5854ed: 66034c2410 ADD CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  L005854f2: { // 0x5854f2: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L005854f7: { // 0x5854f7: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L005854fe: { // 0x5854fe: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00585503: { // 0x585503: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L00585508: { // 0x585508: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0058550c: { // 0x58550c: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00585510: { // 0x585510: e968ffffff JMP 0x0058547d
    goto L0058547d;
  }
  L00585515: { // 0x585515: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00585517: { // 0x585517: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585518: { // 0x585518: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L0058551d: { // 0x58551d: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00585522: { // 0x585522: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00585526: { // 0x585526: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0058552a: { // 0x58552a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058552b: { // 0x58552b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058552c: { // 0x58552c: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0058552e: { // 0x58552e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058552f: { // 0x58552f: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00585532: { // 0x585532: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00585535: { // 0x585535: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00585539: { // 0x585539: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0058553e: { // 0x58553e: 0fbf5102 MOVSX EDX,word ptr [ECX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L00585542: { // 0x585542: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00585544: { // 0x585544: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L00585547: { // 0x585547: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0058554b: { // 0x58554b: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058554e: { // 0x58554e: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L00585550: { // 0x585550: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00585552: { // 0x585552: 7e02 JLE 0x00585556
    if(integer::condition("JLE",flags)) goto L00585556;
  }
  L00585554: { // 0x585554: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00585556: { // 0x585556: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00585558: { // 0x585558: 0f8ee2000000 JLE 0x00585640
    if(integer::condition("JLE",flags)) goto L00585640;
  }
  L0058555e: { // 0x58555e: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  L00585561: { // 0x585561: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L00585569: { // 0x585569: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0058556d: { // 0x58556d: df6c2420 FILD qword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00585571: { // 0x585571: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00585575: { // 0x585575: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0058557a: { // 0x58557a: e861a80a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5789055u); flags=s.arithmetic_flags;
  }
  L0058557f: { // 0x58557f: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00585583: { // 0x585583: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0058558b: { // 0x58558b: df6c2420 FILD qword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0058558f: { // 0x58558f: dc4c2428 FMUL double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply64(read64(m,address));
  }
  L00585593: { // 0x585593: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L00585599: { // 0x585599: e8b2541e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5789086u); flags=s.arithmetic_flags;
  }
  L0058559e: { // 0x58559e: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L005855a0: { // 0x5855a0: 77d3 JA 0x00585575
    if(integer::condition("JA",flags)) goto L00585575;
  }
  L005855a2: { // 0x5855a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005855a4: { // 0x5855a4: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L005855a8: { // 0x5855a8: 0f8e8e000000 JLE 0x0058563c
    if(integer::condition("JLE",flags)) goto L0058563c;
  }
  L005855ae: { // 0x5855ae: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L005855b2: { // 0x5855b2: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005855b6: { // 0x5855b6: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005855ba: { // 0x5855ba: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L005855bd: { // 0x5855bd: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L005855c0: { // 0x5855c0: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L005855c2: { // 0x5855c2: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L005855c4: { // 0x5855c4: 8d348da09d8300 LEA ESI,[ECX*0x4 + 0x839da0]
    s.si = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  L005855cb: { // 0x5855cb: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005855cf: { // 0x5855cf: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L005855d2: { // 0x5855d2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005855d4: { // 0x5855d4: 6603c1 ADD AX,CX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L005855d7: { // 0x5855d7: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L005855db: { // 0x5855db: 66034c2416 ADD CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L005855e0: { // 0x5855e0: 668944244c MOV word ptr [ESP + 0x4c],AX
    m.w16((f.sp+0x0000004cu), (s.ax & 0xffffu));
  }
  L005855e5: { // 0x5855e5: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005855e8: { // 0x5855e8: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005855eb: { // 0x5855eb: 66894c244e MOV word ptr [ESP + 0x4e],CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  L005855f0: { // 0x5855f0: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005855f4: { // 0x5855f4: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L005855f6: { // 0x5855f6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005855f8: { // 0x5855f8: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005855fc: { // 0x5855fc: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L005855fe: { // 0x5855fe: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00585602: { // 0x585602: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00585606: { // 0x585606: 897c2434 MOV dword ptr [ESP + 0x34],EDI
    m.w32((f.sp+0x00000034u), s.di);
  }
  L0058560a: { // 0x58560a: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L0058560e: { // 0x58560e: e81d020000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5789203u); flags=s.arithmetic_flags;
  }
  L00585613: { // 0x585613: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00585615: { // 0x585615: 7425 JZ 0x0058563c
    if(integer::condition("JZ",flags)) goto L0058563c;
  }
  L00585617: { // 0x585617: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L0058561b: { // 0x58561b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0058561f: { // 0x58561f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00585620: { // 0x585620: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00585624: { // 0x585624: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00585626: { // 0x585626: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0058562a: { // 0x58562a: 7fa3 JG 0x005855cf
    if(integer::condition("JG",flags)) goto L005855cf;
  }
  L0058562c: { // 0x58562c: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00585630: { // 0x585630: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585631: { // 0x585631: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585632: { // 0x585632: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585633: { // 0x585633: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00585635: { // 0x585635: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585636: { // 0x585636: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00585639: { // 0x585639: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0058563c: { // 0x58563c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00585640: { // 0x585640: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00585644: { // 0x585644: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585645: { // 0x585645: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585646: { // 0x585646: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585647: { // 0x585647: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00585649: { // 0x585649: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058564a: { // 0x58564a: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L0058564d: { // 0x58564d: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_00185650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00585650: { // 0x585650: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00585653: { // 0x585653: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00585657: { // 0x585657: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0058565b: { // 0x58565b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058565c: { // 0x58565c: 83fa04 CMP EDX,0x4
    (void)integer::sub(s.dx,0x00000004u,32,flags);
  }
  L0058565f: { // 0x58565f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00585660: { // 0x585660: 8b28 MOV EBP,dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  L00585662: { // 0x585662: 0f94442418 SETZ byte ptr [ESP + 0x18]
    m.w8((f.sp+0x00000018u), (integer::condition("SETZ",flags)?1u:0u));
  }
  L00585667: { // 0x585667: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00585669: { // 0x585669: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058566a: { // 0x58566a: 83fa02 CMP EDX,0x2
    (void)integer::sub(s.dx,0x00000002u,32,flags);
  }
  L0058566d: { // 0x58566d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058566e: { // 0x58566e: 896c242c MOV dword ptr [ESP + 0x2c],EBP
    m.w32((f.sp+0x0000002cu), s.bp);
  }
  L00585672: { // 0x585672: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00585676: { // 0x585676: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0058567a: { // 0x58567a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0058567e: { // 0x58567e: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00585682: { // 0x585682: 7526 JNZ 0x005856aa
    if(integer::condition("JNZ",flags)) goto L005856aa;
  }
  L00585684: { // 0x585684: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00585686: { // 0x585686: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  L0058568b: { // 0x58568b: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L00585690: { // 0x585690: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00585694: { // 0x585694: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L00585698: { // 0x585698: c7442414fdffffff MOV dword ptr [ESP + 0x14],0xfffffffd
    m.w32((f.sp+0x00000014u), 0xfffffffdu);
  }
  L005856a0: { // 0x5856a0: c744241c06000000 MOV dword ptr [ESP + 0x1c],0x6
    m.w32((f.sp+0x0000001cu), 0x00000006u);
  }
  L005856a8: { // 0x5856a8: eb24 JMP 0x005856ce
    goto L005856ce;
  }
  L005856aa: { // 0x5856aa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005856ac: { // 0x5856ac: be03000000 MOV ESI,0x3
    s.si = 0x00000003u;
  }
  L005856b1: { // 0x5856b1: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L005856b6: { // 0x5856b6: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L005856ba: { // 0x5856ba: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L005856be: { // 0x5856be: c7442410fdffffff MOV dword ptr [ESP + 0x10],0xfffffffd
    m.w32((f.sp+0x00000010u), 0xfffffffdu);
  }
  L005856c6: { // 0x5856c6: c744241806000000 MOV dword ptr [ESP + 0x18],0x6
    m.w32((f.sp+0x00000018u), 0x00000006u);
  }
  L005856ce: { // 0x5856ce: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L005856d2: { // 0x5856d2: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L005856d5: { // 0x5856d5: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L005856d8: { // 0x5856d8: 8b1a MOV EBX,dword ptr [EDX]
    s.bx = m.r32((s.dx));
  }
  L005856da: { // 0x5856da: 8d4c1901 LEA ECX,[ECX + EBX*0x1 + 0x1]
    s.cx = (s.cx+(s.bx * 0x00000001u)+0x00000001u);
  }
  L005856de: { // 0x5856de: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005856e0: { // 0x5856e0: 0f8d8c000000 JGE 0x00585772
    if(integer::condition("JGE",flags)) goto L00585772;
  }
  L005856e6: { // 0x5856e6: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L005856e9: { // 0x5856e9: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L005856ec: { // 0x5856ec: 0fbf4c242e MOVSX ECX,word ptr [ESP + 0x2e]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002eu)),16));
  }
  L005856f1: { // 0x5856f1: 8d541301 LEA EDX,[EBX + EDX*0x1 + 0x1]
    s.dx = (s.bx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L005856f5: { // 0x5856f5: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005856f7: { // 0x5856f7: 7d79 JGE 0x00585772
    if(integer::condition("JGE",flags)) goto L00585772;
  }
  L005856f9: { // 0x5856f9: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005856fd: { // 0x5856fd: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005856ff: { // 0x5856ff: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00585703: { // 0x585703: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00585707: { // 0x585707: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00585709: { // 0x585709: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0058570d: { // 0x58570d: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L00585711: { // 0x585711: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00585715: { // 0x585715: 8d140e LEA EDX,[ESI + ECX*0x1]
    s.dx = (s.si+(s.cx * 0x00000001u));
  }
  L00585718: { // 0x585718: 8d0c07 LEA ECX,[EDI + EAX*0x1]
    s.cx = (s.di+(s.ax * 0x00000001u));
  }
  L0058571b: { // 0x58571b: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0058571f: { // 0x58571f: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00585723: { // 0x585723: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00585727: { // 0x585727: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00585728: { // 0x585728: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L0058572c: { // 0x58572c: e8ff000000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5789489u); flags=s.arithmetic_flags;
  }
  L00585731: { // 0x585731: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00585733: { // 0x585733: 743d JZ 0x00585772
    if(integer::condition("JZ",flags)) goto L00585772;
  }
  L00585735: { // 0x585735: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00585739: { // 0x585739: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L0058573c: { // 0x58573c: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L00585744: { // 0x585744: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L0058574c: { // 0x58574c: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00585753: { // 0x585753: 6603cd ADD CX,BP
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00585756: { // 0x585756: 660354242e ADD DX,word ptr [ESP + 0x2e]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x0000002eu)),16,flags));
  }
  L0058575b: { // 0x58575b: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L00585760: { // 0x585760: 6689542426 MOV word ptr [ESP + 0x26],DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L00585765: { // 0x585765: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L00585769: { // 0x585769: 896c242c MOV dword ptr [ESP + 0x2c],EBP
    m.w32((f.sp+0x0000002cu), s.bp);
  }
  L0058576d: { // 0x58576d: e95cffffff JMP 0x005856ce
    goto L005856ce;
  }
  L00585772: { // 0x585772: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00585776: { // 0x585776: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L0058577a: { // 0x58577a: 83c0fc ADD EAX,-0x4
    s.ax = integer::add(s.ax,0xfffffffcu,32,flags);
  }
  L0058577d: { // 0x58577d: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L00585780: { // 0x585780: 0fbf5a02 MOVSX EBX,word ptr [EDX + 0x2]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00585784: { // 0x585784: 668b0c85a29d8300 MOV CX,word ptr [EAX*0x4 + 0x839da2]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L0058578c: { // 0x58578c: 8d3485a09d8300 LEA ESI,[EAX*0x4 + 0x839da0]
    s.si = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00585793: { // 0x585793: 66034c242e ADD CX,word ptr [ESP + 0x2e]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000002eu)),16,flags));
  }
  L00585798: { // 0x585798: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0058579b: { // 0x58579b: 0fbf12 MOVSX EDX,word ptr [EDX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0058579e: { // 0x58579e: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L005857a1: { // 0x5857a1: 66894c2456 MOV word ptr [ESP + 0x56],CX
    m.w16((f.sp+0x00000056u), (s.cx & 0xffffu));
  }
  L005857a6: { // 0x5857a6: 6689442454 MOV word ptr [ESP + 0x54],AX
    m.w16((f.sp+0x00000054u), (s.ax & 0xffffu));
  }
  L005857ab: { // 0x5857ab: 8b7c2454 MOV EDI,dword ptr [ESP + 0x54]
    s.di = m.r32((f.sp+0x00000054u));
  }
  L005857af: { // 0x5857af: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005857b2: { // 0x5857b2: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005857b5: { // 0x5857b5: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L005857b7: { // 0x5857b7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005857b9: { // 0x5857b9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005857bb: { // 0x5857bb: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L005857bf: { // 0x5857bf: 7f02 JG 0x005857c3
    if(integer::condition("JG",flags)) goto L005857c3;
  }
  L005857c1: { // 0x5857c1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005857c3: { // 0x5857c3: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L005857c6: { // 0x5857c6: 7e51 JLE 0x00585819
    if(integer::condition("JLE",flags)) goto L00585819;
  }
  L005857c8: { // 0x5857c8: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005857ca: { // 0x5857ca: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L005857cf: { // 0x5857cf: e80ca60a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5789652u); flags=s.arithmetic_flags;
  }
  L005857d4: { // 0x5857d4: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005857d8: { // 0x5857d8: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L005857dc: { // 0x5857dc: df6c2424 FILD qword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005857e0: { // 0x5857e0: dc0d600f7900 FMUL double ptr [0x00790f60]
    const auto address=(0x00790f60u);
    s.fp.multiply64(read64(m,address));
  }
  L005857e6: { // 0x5857e6: e865521e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5789675u); flags=s.arithmetic_flags;
  }
  L005857eb: { // 0x5857eb: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005857ee: { // 0x5857ee: 77da JA 0x005857ca
    if(integer::condition("JA",flags)) goto L005857ca;
  }
  L005857f0: { // 0x5857f0: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005857f2: { // 0x5857f2: 7e25 JLE 0x00585819
    if(integer::condition("JLE",flags)) goto L00585819;
  }
  L005857f4: { // 0x5857f4: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L005857f7: { // 0x5857f7: 668b7602 MOV SI,word ptr [ESI + 0x2]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.si+0x00000002u))) & 0xffffu);
  }
  L005857fb: { // 0x5857fb: 8d1439 LEA EDX,[ECX + EDI*0x1]
    s.dx = (s.cx+(s.di * 0x00000001u));
  }
  L005857fe: { // 0x5857fe: 6689542454 MOV word ptr [ESP + 0x54],DX
    m.w16((f.sp+0x00000054u), (s.dx & 0xffffu));
  }
  L00585803: { // 0x585803: 8b54242e MOV EDX,dword ptr [ESP + 0x2e]
    s.dx = m.r32((f.sp+0x0000002eu));
  }
  L00585807: { // 0x585807: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00585809: { // 0x585809: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0058580a: { // 0x58580a: 6689542456 MOV word ptr [ESP + 0x56],DX
    m.w16((f.sp+0x00000056u), (s.dx & 0xffffu));
  }
  L0058580f: { // 0x58580f: 8b7c2454 MOV EDI,dword ptr [ESP + 0x54]
    s.di = m.r32((f.sp+0x00000054u));
  }
  L00585813: { // 0x585813: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L00585817: { // 0x585817: 75e2 JNZ 0x005857fb
    if(integer::condition("JNZ",flags)) goto L005857fb;
  }
  L00585819: { // 0x585819: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0058581d: { // 0x58581d: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L0058581f: { // 0x58581f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585820: { // 0x585820: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585821: { // 0x585821: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585822: { // 0x585822: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585823: { // 0x585823: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L00585826: { // 0x585826: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_00185830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00585830: { // 0x585830: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00585833: { // 0x585833: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00585834: { // 0x585834: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00585835: { // 0x585835: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00585837: { // 0x585837: 8854240b MOV byte ptr [ESP + 0xb],DL
    m.w8((f.sp+0x0000000bu), (s.dx & 0xffu));
  }
  L0058583b: { // 0x58583b: 8b0d3486a500 MOV ECX,dword ptr [0x00a58634]
    s.cx = m.r32((0x00a58634u));
  }
  L00585841: { // 0x585841: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00585842: { // 0x585842: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00585845: { // 0x585845: 8b5d04 MOV EBX,dword ptr [EBP + 0x4]
    s.bx = m.r32((s.bp+0x00000004u));
  }
  L00585848: { // 0x585848: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058584b: { // 0x58584b: 0fbfd3 MOVSX EDX,BX
    s.dx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L0058584e: { // 0x58584e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058584f: { // 0x58584f: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00585853: { // 0x585853: 8d3c32 LEA EDI,[EDX + ESI*0x1]
    s.di = (s.dx+(s.si * 0x00000001u));
  }
  L00585856: { // 0x585856: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00585858: { // 0x585858: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0058585c: { // 0x58585c: 0f8ea8010000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  L00585862: { // 0x585862: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L00585864: { // 0x585864: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L00585866: { // 0x585866: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00585868: { // 0x585868: 0f8d9c010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L0058586e: { // 0x58586e: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L00585870: { // 0x585870: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00585872: { // 0x585872: 0f8d92010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L00585878: { // 0x585878: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0058587c: { // 0x58587c: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  L00585882: { // 0x585882: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00585884: { // 0x585884: 0f8f80010000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  L0058588a: { // 0x58588a: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0058588d: { // 0x58588d: 8d7410ff LEA ESI,[EAX + EDX*0x1 + -0x1]
    s.si = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  L00585891: { // 0x585891: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00585894: { // 0x585894: 0fbff3 MOVSX ESI,BX
    s.si = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00585897: { // 0x585897: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  L0058589a: { // 0x58589a: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0058589c: { // 0x58589c: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L005858a0: { // 0x5858a0: 0f8e64010000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  L005858a6: { // 0x5858a6: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L005858a8: { // 0x5858a8: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L005858aa: { // 0x5858aa: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005858ac: { // 0x5858ac: 0f8d58010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L005858b2: { // 0x5858b2: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L005858b4: { // 0x5858b4: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005858b6: { // 0x5858b6: 0f8d4e010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L005858bc: { // 0x5858bc: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  L005858c2: { // 0x5858c2: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L005858c6: { // 0x5858c6: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L005858c8: { // 0x5858c8: 0f8f3c010000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  L005858ce: { // 0x5858ce: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L005858d1: { // 0x5858d1: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L005858d5: { // 0x5858d5: 8d743eff LEA ESI,[ESI + EDI*0x1 + -0x1]
    s.si = (s.si+(s.di * 0x00000001u)-0x00000001u);
  }
  L005858d9: { // 0x5858d9: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L005858dd: { // 0x5858dd: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005858e0: { // 0x5858e0: 0fbff6 MOVSX ESI,SI
    s.si = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005858e3: { // 0x5858e3: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  L005858e6: { // 0x5858e6: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005858e8: { // 0x5858e8: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L005858ec: { // 0x5858ec: 0f8e18010000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  L005858f2: { // 0x5858f2: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L005858f4: { // 0x5858f4: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L005858f6: { // 0x5858f6: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005858f8: { // 0x5858f8: 0f8d0c010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L005858fe: { // 0x5858fe: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L00585900: { // 0x585900: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00585902: { // 0x585902: 0f8d02010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L00585908: { // 0x585908: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0058590c: { // 0x58590c: 8b3d3886a500 MOV EDI,dword ptr [0x00a58638]
    s.di = m.r32((0x00a58638u));
  }
  L00585912: { // 0x585912: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00585914: { // 0x585914: 0f8ff0000000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  L0058591a: { // 0x58591a: 8d7410ff LEA ESI,[EAX + EDX*0x1 + -0x1]
    s.si = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  L0058591e: { // 0x58591e: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00585921: { // 0x585921: 0fbf74241c MOVSX ESI,word ptr [ESP + 0x1c]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001cu)),16));
  }
  L00585926: { // 0x585926: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  L00585929: { // 0x585929: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0058592b: { // 0x58592b: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0058592f: { // 0x58592f: 0f8ed5000000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  L00585935: { // 0x585935: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00585937: { // 0x585937: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L00585939: { // 0x585939: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0058593b: { // 0x58593b: 0f8dc9000000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L00585941: { // 0x585941: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L00585943: { // 0x585943: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00585945: { // 0x585945: 0f8dbf000000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  L0058594b: { // 0x58594b: 8b0d3886a500 MOV ECX,dword ptr [0x00a58638]
    s.cx = m.r32((0x00a58638u));
  }
  L00585951: { // 0x585951: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00585955: { // 0x585955: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00585957: { // 0x585957: 0f8fad000000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  L0058595d: { // 0x58595d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00585961: { // 0x585961: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00585964: { // 0x585964: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00585966: { // 0x585966: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00585968: { // 0x585968: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0058596a: { // 0x58596a: 0f8d8e000000 JGE 0x005859fe
    if(integer::condition("JGE",flags)) goto L005859fe;
  }
  L00585970: { // 0x585970: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00585972: { // 0x585972: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L00585975: { // 0x585975: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00585977: { // 0x585977: 7d74 JGE 0x005859ed
    if(integer::condition("JGE",flags)) goto L005859ed;
  }
  L00585979: { // 0x585979: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0058597d: { // 0x58597d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00585982: { // 0x585982: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00585983: { // 0x585983: 66897c2418 MOV word ptr [ESP + 0x18],DI
    m.w16((f.sp+0x00000018u), (s.di & 0xffffu));
  }
  L00585988: { // 0x585988: 66895c241a MOV word ptr [ESP + 0x1a],BX
    m.w16((f.sp+0x0000001au), (s.bx & 0xffffu));
  }
  L0058598d: { // 0x58598d: e86efbfbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5790098u); flags=s.arithmetic_flags;
  }
  L00585992: { // 0x585992: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00585994: { // 0x585994: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00585996: { // 0x585996: e8455befff CALL 0x0047b4e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b4e0u,5790107u); flags=s.arithmetic_flags;
  }
  L0058599b: { // 0x58599b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058599d: { // 0x58599d: 740a JZ 0x005859a9
    if(integer::condition("JZ",flags)) goto L005859a9;
  }
  L0058599f: { // 0x58599f: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L005859a3: { // 0x5859a3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005859a5: { // 0x5859a5: 7463 JZ 0x00585a0a
    if(integer::condition("JZ",flags)) goto L00585a0a;
  }
  L005859a7: { // 0x5859a7: eb36 JMP 0x005859df
    goto L005859df;
  }
  L005859a9: { // 0x5859a9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005859ab: { // 0x5859ab: e8505befff CALL 0x0047b500
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b500u,5790128u); flags=s.arithmetic_flags;
  }
  L005859b0: { // 0x5859b0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005859b2: { // 0x5859b2: 740a JZ 0x005859be
    if(integer::condition("JZ",flags)) goto L005859be;
  }
  L005859b4: { // 0x5859b4: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L005859b8: { // 0x5859b8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005859ba: { // 0x5859ba: 744e JZ 0x00585a0a
    if(integer::condition("JZ",flags)) goto L00585a0a;
  }
  L005859bc: { // 0x5859bc: eb21 JMP 0x005859df
    goto L005859df;
  }
  L005859be: { // 0x5859be: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005859c0: { // 0x5859c0: e8cb57efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5790149u); flags=s.arithmetic_flags;
  }
  L005859c5: { // 0x5859c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005859c7: { // 0x5859c7: 7516 JNZ 0x005859df
    if(integer::condition("JNZ",flags)) goto L005859df;
  }
  L005859c9: { // 0x5859c9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005859cb: { // 0x5859cb: e8905aefff CALL 0x0047b460
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b460u,5790160u); flags=s.arithmetic_flags;
  }
  L005859d0: { // 0x5859d0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005859d2: { // 0x5859d2: 750b JNZ 0x005859df
    if(integer::condition("JNZ",flags)) goto L005859df;
  }
  L005859d4: { // 0x5859d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005859d6: { // 0x5859d6: e8a55aefff CALL 0x0047b480
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b480u,5790171u); flags=s.arithmetic_flags;
  }
  L005859db: { // 0x5859db: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005859dd: { // 0x5859dd: 742b JZ 0x00585a0a
    if(integer::condition("JZ",flags)) goto L00585a0a;
  }
  L005859df: { // 0x5859df: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L005859e2: { // 0x5859e2: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005859e5: { // 0x5859e5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005859e6: { // 0x5859e6: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L005859e9: { // 0x5859e9: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L005859eb: { // 0x5859eb: 7c8c JL 0x00585979
    if(integer::condition("JL",flags)) goto L00585979;
  }
  L005859ed: { // 0x5859ed: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    s.cx = m.r32((s.bp+0x00000004u));
  }
  L005859f0: { // 0x5859f0: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  L005859f3: { // 0x5859f3: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005859f4: { // 0x5859f4: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L005859f6: { // 0x5859f6: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005859f8: { // 0x5859f8: 0f8c72ffffff JL 0x00585970
    if(integer::condition("JL",flags)) goto L00585970;
  }
  L005859fe: { // 0x5859fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005859ff: { // 0x5859ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585a00: { // 0x585a00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585a01: { // 0x585a01: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00585a03: { // 0x585a03: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585a04: { // 0x585a04: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00585a07: { // 0x585a07: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00585a0a: { // 0x585a0a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585a0b: { // 0x585a0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585a0c: { // 0x585a0c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585a0d: { // 0x585a0d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00585a0f: { // 0x585a0f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585a10: { // 0x585a10: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00585a13: { // 0x585a13: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00185cc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00585cc0: { // 0x585cc0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00585cc3: { // 0x585cc3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00585cc4: { // 0x585cc4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00585cc5: { // 0x585cc5: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00585cc7: { // 0x585cc7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00585cc8: { // 0x585cc8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585cc9: { // 0x585cc9: a13486a500 MOV EAX,[0x00a58634]
    s.ax = m.r32((0x00a58634u));
  }
  L00585cce: { // 0x585cce: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00585cd0: { // 0x585cd0: 8b7b04 MOV EDI,dword ptr [EBX + 0x4]
    s.di = m.r32((s.bx+0x00000004u));
  }
  L00585cd3: { // 0x585cd3: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00585cd6: { // 0x585cd6: 0fbfd7 MOVSX EDX,DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L00585cd9: { // 0x585cd9: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  L00585cdc: { // 0x585cdc: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585cde: { // 0x585cde: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00585ce2: { // 0x585ce2: 0f8eb2010000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  L00585ce8: { // 0x585ce8: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L00585cea: { // 0x585cea: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00585cec: { // 0x585cec: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585cee: { // 0x585cee: 0f8da6010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585cf4: { // 0x585cf4: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L00585cf6: { // 0x585cf6: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00585cf8: { // 0x585cf8: 0f8d9c010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585cfe: { // 0x585cfe: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00585d02: { // 0x585d02: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  L00585d08: { // 0x585d08: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00585d0a: { // 0x585d0a: 0f8f8a010000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  L00585d10: { // 0x585d10: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L00585d13: { // 0x585d13: 8d540aff LEA EDX,[EDX + ECX*0x1 + -0x1]
    s.dx = (s.dx+(s.cx * 0x00000001u)-0x00000001u);
  }
  L00585d17: { // 0x585d17: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00585d1b: { // 0x585d1b: 0fbff2 MOVSX ESI,DX
    s.si = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00585d1e: { // 0x585d1e: 0fbfd7 MOVSX EDX,DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L00585d21: { // 0x585d21: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  L00585d24: { // 0x585d24: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585d26: { // 0x585d26: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00585d2a: { // 0x585d2a: 0f8e6a010000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  L00585d30: { // 0x585d30: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L00585d32: { // 0x585d32: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00585d34: { // 0x585d34: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585d36: { // 0x585d36: 0f8d5e010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585d3c: { // 0x585d3c: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L00585d3e: { // 0x585d3e: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00585d40: { // 0x585d40: 0f8d54010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585d46: { // 0x585d46: 8b153886a500 MOV EDX,dword ptr [0x00a58638]
    s.dx = m.r32((0x00a58638u));
  }
  L00585d4c: { // 0x585d4c: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00585d50: { // 0x585d50: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00585d52: { // 0x585d52: 0f8f42010000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  L00585d58: { // 0x585d58: 8b530c MOV EDX,dword ptr [EBX + 0xc]
    s.dx = m.r32((s.bx+0x0000000cu));
  }
  L00585d5b: { // 0x585d5b: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00585d5e: { // 0x585d5e: 8d543aff LEA EDX,[EDX + EDI*0x1 + -0x1]
    s.dx = (s.dx+(s.di * 0x00000001u)-0x00000001u);
  }
  L00585d62: { // 0x585d62: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00585d66: { // 0x585d66: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00585d69: { // 0x585d69: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  L00585d6c: { // 0x585d6c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585d6e: { // 0x585d6e: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00585d72: { // 0x585d72: 0f8e22010000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  L00585d78: { // 0x585d78: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L00585d7a: { // 0x585d7a: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00585d7c: { // 0x585d7c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585d7e: { // 0x585d7e: 0f8d16010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585d84: { // 0x585d84: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L00585d86: { // 0x585d86: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00585d88: { // 0x585d88: 0f8d0c010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585d8e: { // 0x585d8e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00585d92: { // 0x585d92: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  L00585d98: { // 0x585d98: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00585d9a: { // 0x585d9a: 0f8ffa000000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  L00585da0: { // 0x585da0: 0fbf742414 MOVSX ESI,word ptr [ESP + 0x14]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L00585da5: { // 0x585da5: 0fbf542418 MOVSX EDX,word ptr [ESP + 0x18]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  L00585daa: { // 0x585daa: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  L00585dad: { // 0x585dad: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585daf: { // 0x585daf: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00585db3: { // 0x585db3: 0f8ee1000000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  L00585db9: { // 0x585db9: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L00585dbb: { // 0x585dbb: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00585dbd: { // 0x585dbd: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00585dbf: { // 0x585dbf: 0f8dd5000000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585dc5: { // 0x585dc5: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L00585dc7: { // 0x585dc7: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00585dc9: { // 0x585dc9: 0f8dcb000000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  L00585dcf: { // 0x585dcf: a13886a500 MOV EAX,[0x00a58638]
    s.ax = m.r32((0x00a58638u));
  }
  L00585dd4: { // 0x585dd4: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00585dd8: { // 0x585dd8: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00585dda: { // 0x585dda: 0f8fba000000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  L00585de0: { // 0x585de0: 8d5703 LEA EDX,[EDI + 0x3]
    s.dx = (s.di+0x00000003u);
  }
  L00585de3: { // 0x585de3: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00585de5: { // 0x585de5: 7d54 JGE 0x00585e3b
    if(integer::condition("JGE",flags)) goto L00585e3b;
  }
  L00585de7: { // 0x585de7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00585de9: { // 0x585de9: 8d4103 LEA EAX,[ECX + 0x3]
    s.ax = (s.cx+0x00000003u);
  }
  L00585dec: { // 0x585dec: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00585dee: { // 0x585dee: 7d40 JGE 0x00585e30
    if(integer::condition("JGE",flags)) goto L00585e30;
  }
  L00585df0: { // 0x585df0: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00585df4: { // 0x585df4: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L00585df9: { // 0x585df9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00585dfa: { // 0x585dfa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00585dff: { // 0x585dff: 66897c2416 MOV word ptr [ESP + 0x16],DI
    m.w16((f.sp+0x00000016u), (s.di & 0xffffu));
  }
  L00585e04: { // 0x585e04: e8f7f6fbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5791241u); flags=s.arithmetic_flags;
  }
  L00585e09: { // 0x585e09: 8b5038 MOV EDX,dword ptr [EAX + 0x38]
    s.dx = m.r32((s.ax+0x00000038u));
  }
  L00585e0c: { // 0x585e0c: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  L00585e12: { // 0x585e12: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00585e14: { // 0x585e14: 7c05 JL 0x00585e1b
    if(integer::condition("JL",flags)) goto L00585e1b;
  }
  L00585e16: { // 0x585e16: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00585e17: { // 0x585e17: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00585e19: { // 0x585e19: 7e0b JLE 0x00585e26
    if(integer::condition("JLE",flags)) goto L00585e26;
  }
  L00585e1b: { // 0x585e1b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00585e1d: { // 0x585e1d: e81e57efff CALL 0x0047b540
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b540u,5791266u); flags=s.arithmetic_flags;
  }
  L00585e22: { // 0x585e22: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00585e24: { // 0x585e24: 7474 JZ 0x00585e9a
    if(integer::condition("JZ",flags)) goto L00585e9a;
  }
  L00585e26: { // 0x585e26: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00585e28: { // 0x585e28: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00585e29: { // 0x585e29: 8d5103 LEA EDX,[ECX + 0x3]
    s.dx = (s.cx+0x00000003u);
  }
  L00585e2c: { // 0x585e2c: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00585e2e: { // 0x585e2e: 7cc0 JL 0x00585df0
    if(integer::condition("JL",flags)) goto L00585df0;
  }
  L00585e30: { // 0x585e30: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00585e33: { // 0x585e33: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00585e34: { // 0x585e34: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  L00585e37: { // 0x585e37: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00585e39: { // 0x585e39: 7cac JL 0x00585de7
    if(integer::condition("JL",flags)) goto L00585de7;
  }
  L00585e3b: { // 0x585e3b: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L00585e3d: { // 0x585e3d: 8d4e03 LEA ECX,[ESI + 0x3]
    s.cx = (s.si+0x00000003u);
  }
  L00585e40: { // 0x585e40: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00585e42: { // 0x585e42: 7d4c JGE 0x00585e90
    if(integer::condition("JGE",flags)) goto L00585e90;
  }
  L00585e44: { // 0x585e44: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L00585e47: { // 0x585e47: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00585e4b: { // 0x585e4b: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L00585e4e: { // 0x585e4e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00585e4f: { // 0x585e4f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00585e54: { // 0x585e54: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L00585e59: { // 0x585e59: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L00585e5e: { // 0x585e5e: e89df6fbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5791331u); flags=s.arithmetic_flags;
  }
  L00585e63: { // 0x585e63: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00585e65: { // 0x585e65: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00585e67: { // 0x585e67: e81456efff CALL 0x0047b480
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b480u,5791340u); flags=s.arithmetic_flags;
  }
  L00585e6c: { // 0x585e6c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00585e6e: { // 0x585e6e: 7516 JNZ 0x00585e86
    if(integer::condition("JNZ",flags)) goto L00585e86;
  }
  L00585e70: { // 0x585e70: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00585e72: { // 0x585e72: e81953efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5791351u); flags=s.arithmetic_flags;
  }
  L00585e77: { // 0x585e77: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00585e79: { // 0x585e79: 750b JNZ 0x00585e86
    if(integer::condition("JNZ",flags)) goto L00585e86;
  }
  L00585e7b: { // 0x585e7b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00585e7d: { // 0x585e7d: e8de55efff CALL 0x0047b460
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b460u,5791362u); flags=s.arithmetic_flags;
  }
  L00585e82: { // 0x585e82: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00585e84: { // 0x585e84: 7414 JZ 0x00585e9a
    if(integer::condition("JZ",flags)) goto L00585e9a;
  }
  L00585e86: { // 0x585e86: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00585e88: { // 0x585e88: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00585e89: { // 0x585e89: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L00585e8c: { // 0x585e8c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00585e8e: { // 0x585e8e: 7cb4 JL 0x00585e44
    if(integer::condition("JL",flags)) goto L00585e44;
  }
  L00585e90: { // 0x585e90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585e91: { // 0x585e91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585e92: { // 0x585e92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585e93: { // 0x585e93: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00585e95: { // 0x585e95: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585e96: { // 0x585e96: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00585e99: { // 0x585e99: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00585e9a: { // 0x585e9a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00585e9b: { // 0x585e9b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00585e9c: { // 0x585e9c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00585e9d: { // 0x585e9d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00585e9f: { // 0x585e9f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585ea0: { // 0x585ea0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00585ea3: { // 0x585ea3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001851f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005851f0: { // 0x5851f0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005851f3: { // 0x5851f3: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  L005851f8: { // 0x5851f8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005851f9: { // 0x5851f9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005851fa: { // 0x5851fa: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005851fe: { // 0x5851fe: 8b2c88 MOV EBP,dword ptr [EAX + ECX*0x4]
    s.bp = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00585201: { // 0x585201: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00585203: { // 0x585203: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00585206: { // 0x585206: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5788172u); flags=s.arithmetic_flags;
  }
  L0058520c: { // 0x58520c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058520e: { // 0x58520e: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00585212: { // 0x585212: 0f8436010000 JZ 0x0058534e
    if(integer::condition("JZ",flags)) goto L0058534e;
  }
  L00585218: { // 0x585218: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058521e: { // 0x58521e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00585220: { // 0x585220: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00585222: { // 0x585222: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00585226: { // 0x585226: 0f8e22010000 JLE 0x0058534e
    if(integer::condition("JLE",flags)) goto L0058534e;
  }
  L0058522c: { // 0x58522c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058522d: { // 0x58522d: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585233: { // 0x585233: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585234: { // 0x585234: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L0058523a: { // 0x58523a: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0058523c: { // 0x58523c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058523e: { // 0x58523e: 0f8ef5000000 JLE 0x00585339
    if(integer::condition("JLE",flags)) goto L00585339;
  }
  L00585244: { // 0x585244: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00585248: { // 0x585248: 668bcb MOV CX,BX
    s.cx = with_ax(s.cx, (s.bx & 0xffffu));
  }
  L0058524b: { // 0x58524b: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L0058524e: { // 0x58524e: 66034a02 ADD CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L00585252: { // 0x585252: 6603c7 ADD AX,DI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L00585255: { // 0x585255: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0058525a: { // 0x58525a: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0058525f: { // 0x58525f: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00585263: { // 0x585263: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00585267: { // 0x585267: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058526a: { // 0x58526a: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058526d: { // 0x58526d: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L00585270: { // 0x585270: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00585272: { // 0x585272: 0f8eb2000000 JLE 0x0058532a
    if(integer::condition("JLE",flags)) goto L0058532a;
  }
  L00585278: { // 0x585278: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0058527a: { // 0x58527a: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0058527c: { // 0x58527c: 3bde CMP EBX,ESI
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L0058527e: { // 0x58527e: 0f8da2000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L00585284: { // 0x585284: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00585286: { // 0x585286: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00585288: { // 0x585288: 0f8d98000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L0058528e: { // 0x58528e: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00585294: { // 0x585294: 0f8f8c000000 JG 0x00585326
    if(integer::condition("JG",flags)) goto L00585326;
  }
  L0058529a: { // 0x58529a: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0058529e: { // 0x58529e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005852a3: { // 0x5852a3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005852a4: { // 0x5852a4: e85702fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5788329u); flags=s.arithmetic_flags;
  }
  L005852a9: { // 0x5852a9: 8b8db4020000 MOV ECX,dword ptr [EBP + 0x2b4]
    s.cx = m.r32((s.bp+0x000002b4u));
  }
  L005852af: { // 0x5852af: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L005852b3: { // 0x5852b3: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005852b7: { // 0x5852b7: 0fafcb IMUL ECX,EBX
    s.cx = integer::imul(s.cx,s.bx,32,flags);
  }
  L005852ba: { // 0x5852ba: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L005852bc: { // 0x5852bc: 8b748a10 MOV ESI,dword ptr [EDX + ECX*0x4 + 0x10]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x00000010u));
  }
  L005852c0: { // 0x5852c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005852c2: { // 0x5852c2: 745a JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852c4: { // 0x5852c4: 8b9564020000 MOV EDX,dword ptr [EBP + 0x264]
    s.dx = m.r32((s.bp+0x00000264u));
  }
  L005852ca: { // 0x5852ca: 88881a010000 MOV byte ptr [EAX + 0x11a],CL
    m.w8((s.ax+0x0000011au), (s.cx & 0xffu));
  }
  L005852d0: { // 0x5852d0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005852d4: { // 0x5852d4: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005852d7: { // 0x5852d7: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L005852da: { // 0x5852da: 740e JZ 0x005852ea
    if(integer::condition("JZ",flags)) goto L005852ea;
  }
  L005852dc: { // 0x5852dc: 8a5628 MOV DL,byte ptr [ESI + 0x28]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000028u)));
  }
  L005852df: { // 0x5852df: 02d1 ADD DL,CL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L005852e1: { // 0x5852e1: 80ea04 SUB DL,0x4
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),0x00000004u,8,flags));
  }
  L005852e4: { // 0x5852e4: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L005852ea: { // 0x5852ea: 8a4e2a MOV CL,byte ptr [ESI + 0x2a]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000002au)));
  }
  L005852ed: { // 0x5852ed: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L005852f3: { // 0x5852f3: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005852f9: { // 0x5852f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005852fb: { // 0x5852fb: 7421 JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852fd: { // 0x5852fd: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00585302: { // 0x585302: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00585309: { // 0x585309: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0058530e: { // 0x58530e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00585310: { // 0x585310: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00585314: { // 0x585314: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00585317: { // 0x585317: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0058531a: { // 0x58531a: 89540838 MOV dword ptr [EAX + ECX*0x1 + 0x38],EDX
    m.w32((s.ax+(s.cx * 0x00000001u)+0x00000038u), s.dx);
  }
  L0058531e: { // 0x58531e: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585324: { // 0x585324: eb04 JMP 0x0058532a
    goto L0058532a;
  }
  L00585326: { // 0x585326: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0058532a: { // 0x58532a: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L00585330: { // 0x585330: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00585331: { // 0x585331: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00585333: { // 0x585333: 0f8c0bffffff JL 0x00585244
    if(integer::condition("JL",flags)) goto L00585244;
  }
  L00585339: { // 0x585339: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058533f: { // 0x58533f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00585340: { // 0x585340: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00585342: { // 0x585342: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00585346: { // 0x585346: 0f8ce8feffff JL 0x00585234
    if(integer::condition("JL",flags)) goto L00585234;
  }
  L0058534c: { // 0x58534c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058534d: { // 0x58534d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058534e: { // 0x58534e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058534f: { // 0x58534f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585350: { // 0x585350: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00585353: { // 0x585353: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007b540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b540: { // 0x47b540: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b543: { // 0x47b543: 8b0da4a8a300 MOV ECX,dword ptr [0x00a3a8a4]
    s.cx = m.r32((0x00a3a8a4u));
  }
  L0047b549: { // 0x47b549: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b54b: { // 0x47b54b: 7c0a JL 0x0047b557
    if(integer::condition("JL",flags)) goto L0047b557;
  }
  L0047b54d: { // 0x47b54d: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  L0047b550: { // 0x47b550: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b552: { // 0x47b552: 7d03 JGE 0x0047b557
    if(integer::condition("JGE",flags)) goto L0047b557;
  }
  L0047b554: { // 0x47b554: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b556: { // 0x47b556: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b557: { // 0x47b557: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b559: { // 0x47b559: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000766c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004766c0: { // 0x004766c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004766c1: { // 0x004766c1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L004766c5: { // 0x004766c5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004766c7: { // 0x004766c7: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  L004766ca: { // 0x004766ca: 7346 JNC 0x00476712
    if(integer::condition("JNC",flags)) goto L00476712;
  }
  L004766cc: { // 0x004766cc: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L004766cf: { // 0x004766cf: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L004766d2: { // 0x004766d2: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L004766d6: { // 0x004766d6: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L004766dd: { // 0x004766dd: 668b1495a09d8300 MOV DX,word ptr [EDX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L004766e5: { // 0x004766e5: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L004766e9: { // 0x004766e9: 6603442402 ADD AX,word ptr [ESP + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000002u)),16,flags));
  }
  L004766ee: { // 0x004766ee: 6603d1 ADD DX,CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L004766f1: { // 0x004766f1: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L004766f6: { // 0x004766f6: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L004766fa: { // 0x004766fa: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L004766ff: { // 0x004766ff: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00476703: { // 0x00476703: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L00476707: { // 0x00476707: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00476708: { // 0x00476708: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047670d: { // 0x0047670d: e8eeed0c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4679442u); flags=s.arithmetic_flags;
  }
  L00476712: { // 0x00476712: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00476713: { // 0x00476713: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b4e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b4e0: { // 0x47b4e0: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b4e3: { // 0x47b4e3: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  L0047b4e9: { // 0x47b4e9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b4eb: { // 0x47b4eb: 7c0a JL 0x0047b4f7
    if(integer::condition("JL",flags)) goto L0047b4f7;
  }
  L0047b4ed: { // 0x47b4ed: 83c10f ADD ECX,0xf
    s.cx = integer::add(s.cx,0x0000000fu,32,flags);
  }
  L0047b4f0: { // 0x47b4f0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b4f2: { // 0x47b4f2: 7d03 JGE 0x0047b4f7
    if(integer::condition("JGE",flags)) goto L0047b4f7;
  }
  L0047b4f4: { // 0x47b4f4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b4f6: { // 0x47b4f6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b4f7: { // 0x47b4f7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b4f9: { // 0x47b4f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b500: { // 0x47b500: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b503: { // 0x47b503: 8b0d4059a500 MOV ECX,dword ptr [0x00a55940]
    s.cx = m.r32((0x00a55940u));
  }
  L0047b509: { // 0x47b509: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b50b: { // 0x47b50b: 7c0a JL 0x0047b517
    if(integer::condition("JL",flags)) goto L0047b517;
  }
  L0047b50d: { // 0x47b50d: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0047b510: { // 0x47b510: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b512: { // 0x47b512: 7d03 JGE 0x0047b517
    if(integer::condition("JGE",flags)) goto L0047b517;
  }
  L0047b514: { // 0x47b514: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b516: { // 0x47b516: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b517: { // 0x47b517: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b519: { // 0x47b519: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { // 0x47b190: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { // 0x47b193: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { // 0x47b198: 7407 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { // 0x47b19a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { // 0x47b19c: 7403 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { // 0x47b19e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1a3: { // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b460: { // 0x47b460: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b463: { // 0x47b463: 8b0d2caba300 MOV ECX,dword ptr [0x00a3ab2c]
    s.cx = m.r32((0x00a3ab2cu));
  }
  L0047b469: { // 0x47b469: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b46b: { // 0x47b46b: 7c0a JL 0x0047b477
    if(integer::condition("JL",flags)) goto L0047b477;
  }
  L0047b46d: { // 0x47b46d: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  L0047b470: { // 0x47b470: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b472: { // 0x47b472: 7d03 JGE 0x0047b477
    if(integer::condition("JGE",flags)) goto L0047b477;
  }
  L0047b474: { // 0x47b474: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b476: { // 0x47b476: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b477: { // 0x47b477: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b479: { // 0x47b479: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b480: { // 0x47b480: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b483: { // 0x47b483: 8b0d185da500 MOV ECX,dword ptr [0x00a55d18]
    s.cx = m.r32((0x00a55d18u));
  }
  L0047b489: { // 0x47b489: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b48b: { // 0x47b48b: 7c0a JL 0x0047b497
    if(integer::condition("JL",flags)) goto L0047b497;
  }
  L0047b48d: { // 0x47b48d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b490: { // 0x47b490: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b492: { // 0x47b492: 7d03 JGE 0x0047b497
    if(integer::condition("JGE",flags)) goto L0047b497;
  }
  L0047b494: { // 0x47b494: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b496: { // 0x47b496: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b497: { // 0x47b497: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b499: { // 0x47b499: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001c300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041c300: { // 0x41c300: 8b81a4000000 MOV EAX,dword ptr [ECX + 0xa4]
    s.ax = m.r32((s.cx+0x000000a4u));
  }
  L0041c306: { // 0x41c306: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5790752u:f_00185c20(m,s,child,{});break;
case 5788512u:f_00185360(m,s,child,{});break;
case 5789264u:f_00185650(m,s,child,{});break;
case 5789744u:f_00185830(m,s,child,{});break;
case 5790912u:f_00185cc0(m,s,child,{});break;
case 5788144u:f_001851f0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4699456u:f_0007b540(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4699360u:f_0007b4e0(m,s,child,{});break;
case 4699392u:f_0007b500(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
case 4699232u:f_0007b460(m,s,child,{});break;
case 4699264u:f_0007b480(m,s,child,{});break;
case 4309760u:f_0001c300(m,s,child,{});break;
default:throw std::domain_error("recovery548 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00584130(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00584130: { // 0x584130: 81ec18010000 SUB ESP,0x118
    f.sp = integer::sub(f.sp,0x00000118u,32,flags);
  }
  L00584136: { // 0x584136: 8b94241c010000 MOV EDX,dword ptr [ESP + 0x11c]
    s.dx = m.r32((f.sp+0x0000011cu));
  }
  L0058413d: { // 0x58413d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058413e: { // 0x58413e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058413f: { // 0x58413f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00584140: { // 0x584140: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00584142: { // 0x584142: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00584143: { // 0x584143: 8d8c2494000000 LEA ECX,[ESP + 0x94]
    s.cx = (f.sp+0x00000094u);
  }
  L0058414a: { // 0x58414a: 89742444 MOV dword ptr [ESP + 0x44],ESI
    m.w32((f.sp+0x00000044u), s.si);
  }
  L0058414e: { // 0x58414e: e8cd1a0000 CALL 0x00585c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585c20u,5783891u); flags=s.arithmetic_flags;
  }
  L00584153: { // 0x584153: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00584155: { // 0x584155: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L00584159: { // 0x584159: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0058415c: { // 0x58415c: 8954245c MOV dword ptr [ESP + 0x5c],EDX
    m.w32((f.sp+0x0000005cu), s.dx);
  }
  L00584160: { // 0x584160: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00584163: { // 0x584163: 897c2460 MOV dword ptr [ESP + 0x60],EDI
    m.w32((f.sp+0x00000060u), s.di);
  }
  L00584167: { // 0x584167: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0058416a: { // 0x58416a: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L0058416d: { // 0x58416d: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00584171: { // 0x584171: 0f8e67020000 JLE 0x005843de
    if(integer::condition("JLE",flags)) goto L005843de;
  }
  L00584177: { // 0x584177: 8d7a02 LEA EDI,[EDX + 0x2]
    s.di = (s.dx+0x00000002u);
  }
  L0058417a: { // 0x58417a: 8d58fe LEA EBX,[EAX + -0x2]
    s.bx = (s.ax-0x00000002u);
  }
  L0058417d: { // 0x58417d: 66897c2422 MOV word ptr [ESP + 0x22],DI
    m.w16((f.sp+0x00000022u), (s.di & 0xffffu));
  }
  L00584182: { // 0x584182: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L00584187: { // 0x584187: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00584189: { // 0x584189: 66894c2420 MOV word ptr [ESP + 0x20],CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L0058418e: { // 0x58418e: 0f8e4f020000 JLE 0x005843e3
    if(integer::condition("JLE",flags)) goto L005843e3;
  }
  L00584194: { // 0x584194: eb04 JMP 0x0058419a
    goto L0058419a;
  }
  L00584196: { // 0x584196: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L0058419a: { // 0x58419a: 8d442458 LEA EAX,[ESP + 0x58]
    s.ax = (f.sp+0x00000058u);
  }
  L0058419e: { // 0x58419e: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L005841a0: { // 0x5841a0: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L005841a4: { // 0x5841a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005841a5: { // 0x5841a5: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005841a9: { // 0x5841a9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005841aa: { // 0x5841aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005841ab: { // 0x5841ab: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005841ad: { // 0x5841ad: e8ae110000 CALL 0x00585360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585360u,5783986u); flags=s.arithmetic_flags;
  }
  L005841b2: { // 0x5841b2: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005841b4: { // 0x5841b4: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L005841b8: { // 0x5841b8: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005841bc: { // 0x5841bc: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L005841be: { // 0x5841be: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L005841c2: { // 0x5841c2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005841c3: { // 0x5841c3: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L005841c7: { // 0x5841c7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005841c8: { // 0x5841c8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005841c9: { // 0x5841c9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005841cb: { // 0x5841cb: e880140000 CALL 0x00585650
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585650u,5784016u); flags=s.arithmetic_flags;
  }
  L005841d0: { // 0x5841d0: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005841d2: { // 0x5841d2: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005841d4: { // 0x5841d4: 663bc5 CMP AX,BP
    (void)integer::sub((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L005841d7: { // 0x5841d7: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L005841db: { // 0x5841db: 750b JNZ 0x005841e8
    if(integer::condition("JNZ",flags)) goto L005841e8;
  }
  L005841dd: { // 0x5841dd: 66396c242e CMP word ptr [ESP + 0x2e],BP
    (void)integer::sub(m.r16((f.sp+0x0000002eu)),(s.bp & 0xffffu),16,flags);
  }
  L005841e2: { // 0x5841e2: 0f84d3010000 JZ 0x005843bb
    if(integer::condition("JZ",flags)) goto L005843bb;
  }
  L005841e8: { // 0x5841e8: 668b4c2420 MOV CX,word ptr [ESP + 0x20]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000020u)));
  }
  L005841ed: { // 0x5841ed: 663bcd CMP CX,BP
    (void)integer::sub((s.cx & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L005841f0: { // 0x5841f0: 750b JNZ 0x005841fd
    if(integer::condition("JNZ",flags)) goto L005841fd;
  }
  L005841f2: { // 0x5841f2: 66396c2422 CMP word ptr [ESP + 0x22],BP
    (void)integer::sub(m.r16((f.sp+0x00000022u)),(s.bp & 0xffffu),16,flags);
  }
  L005841f7: { // 0x5841f7: 0f84be010000 JZ 0x005843bb
    if(integer::condition("JZ",flags)) goto L005843bb;
  }
  L005841fd: { // 0x5841fd: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00584200: { // 0x584200: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00584203: { // 0x584203: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00584205: { // 0x584205: 83fa06 CMP EDX,0x6
    (void)integer::sub(s.dx,0x00000006u,32,flags);
  }
  L00584208: { // 0x584208: 0f8cad010000 JL 0x005843bb
    if(integer::condition("JL",flags)) goto L005843bb;
  }
  L0058420e: { // 0x58420e: 0fbf442428 MOVSX EAX,word ptr [ESP + 0x28]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000028u)),16));
  }
  L00584213: { // 0x584213: 0fbf4c242a MOVSX ECX,word ptr [ESP + 0x2a]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002au)),16));
  }
  L00584218: { // 0x584218: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L0058421b: { // 0x58421b: 898c2480000000 MOV dword ptr [ESP + 0x80],ECX
    m.w32((f.sp+0x00000080u), s.cx);
  }
  L00584222: { // 0x584222: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00584223: { // 0x584223: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00584225: { // 0x584225: 8d8c2480000000 LEA ECX,[ESP + 0x80]
    s.cx = (f.sp+0x00000080u);
  }
  L0058422c: { // 0x58422c: 89842480000000 MOV dword ptr [ESP + 0x80],EAX
    m.w32((f.sp+0x00000080u), s.ax);
  }
  L00584233: { // 0x584233: c784248800000004000000 MOV dword ptr [ESP + 0x88],0x4
    m.w32((f.sp+0x00000088u), 0x00000004u);
  }
  L0058423e: { // 0x58423e: 89bc248c000000 MOV dword ptr [ESP + 0x8c],EDI
    m.w32((f.sp+0x0000008cu), s.di);
  }
  L00584245: { // 0x584245: e8e6150000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5784138u); flags=s.arithmetic_flags;
  }
  L0058424a: { // 0x58424a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058424c: { // 0x58424c: 745a JZ 0x005842a8
    if(integer::condition("JZ",flags)) goto L005842a8;
  }
  L0058424e: { // 0x58424e: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00584253: { // 0x584253: e888bb0a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5784152u); flags=s.arithmetic_flags;
  }
  L00584258: { // 0x584258: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0058425c: { // 0x58425c: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00584260: { // 0x584260: df6c2410 FILD qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00584264: { // 0x584264: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0058426a: { // 0x58426a: e8e1671e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5784175u); flags=s.arithmetic_flags;
  }
  L0058426f: { // 0x58426f: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00584272: { // 0x584272: 77da JA 0x0058424e
    if(integer::condition("JA",flags)) goto L0058424e;
  }
  L00584274: { // 0x584274: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00584276: { // 0x584276: 7430 JZ 0x005842a8
    if(integer::condition("JZ",flags)) goto L005842a8;
  }
  L00584278: { // 0x584278: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0058427c: { // 0x58427c: 668b44242a MOV AX,word ptr [ESP + 0x2a]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002au)));
  }
  L00584281: { // 0x584281: 83c2fd ADD EDX,-0x3
    s.dx = integer::add(s.dx,0xfffffffdu,32,flags);
  }
  L00584284: { // 0x584284: 668944243a MOV word ptr [ESP + 0x3a],AX
    m.w16((f.sp+0x0000003au), (s.ax & 0xffffu));
  }
  L00584289: { // 0x584289: a14459a500 MOV EAX,[0x00a55944]
    s.ax = m.r32((0x00a55944u));
  }
  L0058428e: { // 0x58428e: 6689542438 MOV word ptr [ESP + 0x38],DX
    m.w16((f.sp+0x00000038u), (s.dx & 0xffffu));
  }
  L00584293: { // 0x584293: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00584297: { // 0x584297: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584299: { // 0x584299: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0058429d: { // 0x58429d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058429f: { // 0x58429f: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L005842a3: { // 0x5842a3: 8d4809 LEA ECX,[EAX + 0x9]
    s.cx = (s.ax+0x00000009u);
  }
  L005842a6: { // 0x5842a6: eb11 JMP 0x005842b9
    goto L005842b9;
  }
  L005842a8: { // 0x5842a8: 8b0d4059a500 MOV ECX,dword ptr [0x00a55940]
    s.cx = m.r32((0x00a55940u));
  }
  L005842ae: { // 0x5842ae: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005842b0: { // 0x5842b0: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005842b2: { // 0x5842b2: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L005842b6: { // 0x5842b6: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005842b9: { // 0x5842b9: e8320f0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5784254u); flags=s.arithmetic_flags;
  }
  L005842be: { // 0x5842be: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005842c2: { // 0x5842c2: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005842c6: { // 0x5842c6: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005842c9: { // 0x5842c9: 0fbff9 MOVSX EDI,CX
    s.di = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005842cc: { // 0x5842cc: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L005842ce: { // 0x5842ce: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005842d0: { // 0x5842d0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005842d1: { // 0x5842d1: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005842d3: { // 0x5842d3: 7e4e JLE 0x00584323
    if(integer::condition("JLE",flags)) goto L00584323;
  }
  L005842d5: { // 0x5842d5: 8d4e01 LEA ECX,[ESI + 0x1]
    s.cx = (s.si+0x00000001u);
  }
  L005842d8: { // 0x5842d8: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005842da: { // 0x5842da: 66894c2440 MOV word ptr [ESP + 0x40],CX
    m.w16((f.sp+0x00000040u), (s.cx & 0xffffu));
  }
  L005842df: { // 0x5842df: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L005842e3: { // 0x5842e3: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005842e5: { // 0x5842e5: 668b44242e MOV AX,word ptr [ESP + 0x2e]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002eu)));
  }
  L005842ea: { // 0x5842ea: 6689542438 MOV word ptr [ESP + 0x38],DX
    m.w16((f.sp+0x00000038u), (s.dx & 0xffffu));
  }
  L005842ef: { // 0x5842ef: 668944243a MOV word ptr [ESP + 0x3a],AX
    m.w16((f.sp+0x0000003au), (s.ax & 0xffffu));
  }
  L005842f4: { // 0x5842f4: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L005842f8: { // 0x5842f8: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005842fa: { // 0x5842fa: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L005842fe: { // 0x5842fe: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  L00584304: { // 0x584304: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L00584308: { // 0x584308: e8e30e0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5784333u); flags=s.arithmetic_flags;
  }
  L0058430d: { // 0x58430d: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00584311: { // 0x584311: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00584315: { // 0x584315: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00584318: { // 0x584318: 0fbff9 MOVSX EDI,CX
    s.di = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058431b: { // 0x58431b: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0058431d: { // 0x58431d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0058431e: { // 0x58431e: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0058431f: { // 0x58431f: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00584321: { // 0x584321: 7cb2 JL 0x005842d5
    if(integer::condition("JL",flags)) goto L005842d5;
  }
  L00584323: { // 0x584323: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00584326: { // 0x584326: 0fbf4c242e MOVSX ECX,word ptr [ESP + 0x2e]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002eu)),16));
  }
  L0058432b: { // 0x58432b: 894c2470 MOV dword ptr [ESP + 0x70],ECX
    m.w32((f.sp+0x00000070u), s.cx);
  }
  L0058432f: { // 0x58432f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00584330: { // 0x584330: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00584332: { // 0x584332: 8d4c2470 LEA ECX,[ESP + 0x70]
    s.cx = (f.sp+0x00000070u);
  }
  L00584336: { // 0x584336: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L0058433a: { // 0x58433a: c744247804000000 MOV dword ptr [ESP + 0x78],0x4
    m.w32((f.sp+0x00000078u), 0x00000004u);
  }
  L00584342: { // 0x584342: c744247c03000000 MOV dword ptr [ESP + 0x7c],0x3
    m.w32((f.sp+0x0000007cu), 0x00000003u);
  }
  L0058434a: { // 0x58434a: e8e1140000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5784399u); flags=s.arithmetic_flags;
  }
  L0058434f: { // 0x58434f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00584351: { // 0x584351: 7445 JZ 0x00584398
    if(integer::condition("JZ",flags)) goto L00584398;
  }
  L00584353: { // 0x584353: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00584358: { // 0x584358: e883ba0a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5784413u); flags=s.arithmetic_flags;
  }
  L0058435d: { // 0x58435d: 8984248c000000 MOV dword ptr [ESP + 0x8c],EAX
    m.w32((f.sp+0x0000008cu), s.ax);
  }
  L00584364: { // 0x584364: 89ac2490000000 MOV dword ptr [ESP + 0x90],EBP
    m.w32((f.sp+0x00000090u), s.bp);
  }
  L0058436b: { // 0x58436b: dfac248c000000 FILD qword ptr [ESP + 0x8c]
    const auto address=(f.sp+0x0000008cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00584372: { // 0x584372: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L00584378: { // 0x584378: e8d3661e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5784445u); flags=s.arithmetic_flags;
  }
  L0058437d: { // 0x58437d: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00584380: { // 0x584380: 77d1 JA 0x00584353
    if(integer::condition("JA",flags)) goto L00584353;
  }
  L00584382: { // 0x584382: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00584384: { // 0x584384: 7412 JZ 0x00584398
    if(integer::condition("JZ",flags)) goto L00584398;
  }
  L00584386: { // 0x584386: a14459a500 MOV EAX,[0x00a55944]
    s.ax = m.r32((0x00a55944u));
  }
  L0058438b: { // 0x58438b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058438d: { // 0x58438d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058438f: { // 0x58438f: 8d542434 LEA EDX,[ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L00584393: { // 0x584393: 8d480a LEA ECX,[EAX + 0xa]
    s.cx = (s.ax+0x0000000au);
  }
  L00584396: { // 0x584396: eb0e JMP 0x005843a6
    goto L005843a6;
  }
  L00584398: { // 0x584398: 8b0d4059a500 MOV ECX,dword ptr [0x00a55940]
    s.cx = m.r32((0x00a55940u));
  }
  L0058439e: { // 0x58439e: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005843a0: { // 0x5843a0: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005843a2: { // 0x5843a2: 8d542434 LEA EDX,[ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L005843a6: { // 0x5843a6: e8450e0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5784491u); flags=s.arithmetic_flags;
  }
  L005843ab: { // 0x5843ab: 83eb0a SUB EBX,0xa
    s.bx = integer::sub(s.bx,0x0000000au,32,flags);
  }
  L005843ae: { // 0x5843ae: 66834424220a ADD word ptr [ESP + 0x22],0xa
    m.w16((f.sp+0x00000022u), integer::add(m.r16((f.sp+0x00000022u)),0x0000000au,16,flags));
  }
  L005843b4: { // 0x5843b4: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L005843b9: { // 0x5843b9: eb09 JMP 0x005843c4
    goto L005843c4;
  }
  L005843bb: { // 0x5843bb: 668344242202 ADD word ptr [ESP + 0x22],0x2
    m.w16((f.sp+0x00000022u), integer::add(m.r16((f.sp+0x00000022u)),0x00000002u,16,flags));
  }
  L005843c1: { // 0x5843c1: 83eb02 SUB EBX,0x2
    s.bx = integer::sub(s.bx,0x00000002u,32,flags);
  }
  L005843c4: { // 0x5843c4: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L005843c6: { // 0x5843c6: 0f8fcafdffff JG 0x00584196
    if(integer::condition("JG",flags)) goto L00584196;
  }
  L005843cc: { // 0x5843cc: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L005843d0: { // 0x5843d0: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L005843d4: { // 0x5843d4: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L005843d8: { // 0x5843d8: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L005843dc: { // 0x5843dc: eb07 JMP 0x005843e5
    goto L005843e5;
  }
  L005843de: { // 0x5843de: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L005843e3: { // 0x5843e3: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005843e5: { // 0x5843e5: 837c246008 CMP dword ptr [ESP + 0x60],0x8
    (void)integer::sub(m.r32((f.sp+0x00000060u)),0x00000008u,32,flags);
  }
  L005843ea: { // 0x5843ea: 0f8ee5060000 JLE 0x00584ad5
    if(integer::condition("JLE",flags)) goto L00584ad5;
  }
  L005843f0: { // 0x5843f0: 8d58fb LEA EBX,[EAX + -0x5]
    s.bx = (s.ax-0x00000005u);
  }
  L005843f3: { // 0x5843f3: 83c105 ADD ECX,0x5
    s.cx = integer::add(s.cx,0x00000005u,32,flags);
  }
  L005843f6: { // 0x5843f6: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L005843f8: { // 0x5843f8: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L005843fc: { // 0x5843fc: 66894c2420 MOV word ptr [ESP + 0x20],CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L00584401: { // 0x584401: 6689542422 MOV word ptr [ESP + 0x22],DX
    m.w16((f.sp+0x00000022u), (s.dx & 0xffffu));
  }
  L00584406: { // 0x584406: 0f8ec9060000 JLE 0x00584ad5
    if(integer::condition("JLE",flags)) goto L00584ad5;
  }
  L0058440c: { // 0x58440c: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L00584410: { // 0x584410: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00584412: { // 0x584412: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00584416: { // 0x584416: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00584417: { // 0x584417: 8d84242c010000 LEA EAX,[ESP + 0x12c]
    s.ax = (f.sp+0x0000012cu);
  }
  L0058441e: { // 0x58441e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0058441f: { // 0x58441f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00584420: { // 0x584420: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00584422: { // 0x584422: e8390f0000 CALL 0x00585360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585360u,5784615u); flags=s.arithmetic_flags;
  }
  L00584427: { // 0x584427: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00584429: { // 0x584429: 8d542458 LEA EDX,[ESP + 0x58]
    s.dx = (f.sp+0x00000058u);
  }
  L0058442d: { // 0x58442d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00584431: { // 0x584431: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00584433: { // 0x584433: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00584437: { // 0x584437: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00584438: { // 0x584438: 8d8c2494000000 LEA ECX,[ESP + 0x94]
    s.cx = (f.sp+0x00000094u);
  }
  L0058443f: { // 0x58443f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00584440: { // 0x584440: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00584441: { // 0x584441: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00584443: { // 0x584443: e808120000 CALL 0x00585650
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585650u,5784648u); flags=s.arithmetic_flags;
  }
  L00584448: { // 0x584448: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0058444a: { // 0x58444a: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0058444e: { // 0x58444e: 668b54242e MOV DX,word ptr [ESP + 0x2e]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000002eu)));
  }
  L00584453: { // 0x584453: 663bc5 CMP AX,BP
    (void)integer::sub((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L00584456: { // 0x584456: 7509 JNZ 0x00584461
    if(integer::condition("JNZ",flags)) goto L00584461;
  }
  L00584458: { // 0x584458: 663bd5 CMP DX,BP
    (void)integer::sub((s.dx & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L0058445b: { // 0x58445b: 0f845f060000 JZ 0x00584ac0
    if(integer::condition("JZ",flags)) goto L00584ac0;
  }
  L00584461: { // 0x584461: 66396c2420 CMP word ptr [ESP + 0x20],BP
    (void)integer::sub(m.r16((f.sp+0x00000020u)),(s.bp & 0xffffu),16,flags);
  }
  L00584466: { // 0x584466: 668b442422 MOV AX,word ptr [ESP + 0x22]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000022u)));
  }
  L0058446b: { // 0x58446b: 7509 JNZ 0x00584476
    if(integer::condition("JNZ",flags)) goto L00584476;
  }
  L0058446d: { // 0x58446d: 663bc5 CMP AX,BP
    (void)integer::sub((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L00584470: { // 0x584470: 0f844a060000 JZ 0x00584ac0
    if(integer::condition("JZ",flags)) goto L00584ac0;
  }
  L00584476: { // 0x584476: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00584479: { // 0x584479: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058447c: { // 0x58447c: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0058447e: { // 0x58447e: 83f906 CMP ECX,0x6
    (void)integer::sub(s.cx,0x00000006u,32,flags);
  }
  L00584481: { // 0x584481: 0f8c39060000 JL 0x00584ac0
    if(integer::condition("JL",flags)) goto L00584ac0;
  }
  L00584487: { // 0x584487: 668b442412 MOV AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000012u)));
  }
  L0058448c: { // 0x58448c: c644241b00 MOV byte ptr [ESP + 0x1b],0x0
    m.w8((f.sp+0x0000001bu), 0x00000000u);
  }
  L00584491: { // 0x584491: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L00584494: { // 0x584494: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L00584496: { // 0x584496: c644241a00 MOV byte ptr [ESP + 0x1a],0x0
    m.w8((f.sp+0x0000001au), 0x00000000u);
  }
  L0058449b: { // 0x58449b: c644242700 MOV byte ptr [ESP + 0x27],0x0
    m.w8((f.sp+0x00000027u), 0x00000000u);
  }
  L005844a0: { // 0x5844a0: 0f8d65050000 JGE 0x00584a0b
    if(integer::condition("JGE",flags)) goto L00584a0b;
  }
  L005844a6: { // 0x5844a6: 8a4c241b MOV CL,byte ptr [ESP + 0x1b]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000001bu)));
  }
  L005844aa: { // 0x5844aa: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005844ac: { // 0x5844ac: 0fbf4c2410 MOVSX ECX,word ptr [ESP + 0x10]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L005844b1: { // 0x5844b1: 0f85a4010000 JNZ 0x0058465b
    if(integer::condition("JNZ",flags)) goto L0058465b;
  }
  L005844b7: { // 0x5844b7: be02000000 MOV ESI,0x2
    s.si = 0x00000002u;
  }
  L005844bc: { // 0x5844bc: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L005844be: { // 0x5844be: 89b424b0000000 MOV dword ptr [ESP + 0xb0],ESI
    m.w32((f.sp+0x000000b0u), s.si);
  }
  L005844c5: { // 0x5844c5: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L005844c7: { // 0x5844c7: 89b4240c010000 MOV dword ptr [ESP + 0x10c],ESI
    m.w32((f.sp+0x0000010cu), s.si);
  }
  L005844ce: { // 0x5844ce: 899424ac000000 MOV dword ptr [ESP + 0xac],EDX
    m.w32((f.sp+0x000000acu), s.dx);
  }
  L005844d5: { // 0x5844d5: 0fbf74242e MOVSX ESI,word ptr [ESP + 0x2e]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002eu)),16));
  }
  L005844da: { // 0x5844da: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005844dd: { // 0x5844dd: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L005844df: { // 0x5844df: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L005844e4: { // 0x5844e4: 8d50fd LEA EDX,[EAX + -0x3]
    s.dx = (s.ax-0x00000003u);
  }
  L005844e7: { // 0x5844e7: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  L005844ea: { // 0x5844ea: 898c24a4000000 MOV dword ptr [ESP + 0xa4],ECX
    m.w32((f.sp+0x000000a4u), s.cx);
  }
  L005844f1: { // 0x5844f1: 898424a8000000 MOV dword ptr [ESP + 0xa8],EAX
    m.w32((f.sp+0x000000a8u), s.ax);
  }
  L005844f8: { // 0x5844f8: 898c2404010000 MOV dword ptr [ESP + 0x104],ECX
    m.w32((f.sp+0x00000104u), s.cx);
  }
  L005844ff: { // 0x5844ff: 89942408010000 MOV dword ptr [ESP + 0x108],EDX
    m.w32((f.sp+0x00000108u), s.dx);
  }
  L00584506: { // 0x584506: 89bc2410010000 MOV dword ptr [ESP + 0x110],EDI
    m.w32((f.sp+0x00000110u), s.di);
  }
  L0058450d: { // 0x58450d: 0f8c91050000 JL 0x00584aa4
    if(integer::condition("JL",flags)) goto L00584aa4;
  }
  L00584513: { // 0x584513: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00584515: { // 0x584515: 0f84bd000000 JZ 0x005845d8
    if(integer::condition("JZ",flags)) goto L005845d8;
  }
  L0058451b: { // 0x58451b: 898c24e4000000 MOV dword ptr [ESP + 0xe4],ECX
    m.w32((f.sp+0x000000e4u), s.cx);
  }
  L00584522: { // 0x584522: 899424e8000000 MOV dword ptr [ESP + 0xe8],EDX
    m.w32((f.sp+0x000000e8u), s.dx);
  }
  L00584529: { // 0x584529: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058452a: { // 0x58452a: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L0058452c: { // 0x58452c: 8d8c24e8000000 LEA ECX,[ESP + 0xe8]
    s.cx = (f.sp+0x000000e8u);
  }
  L00584533: { // 0x584533: c78424f000000003000000 MOV dword ptr [ESP + 0xf0],0x3
    m.w32((f.sp+0x000000f0u), 0x00000003u);
  }
  L0058453e: { // 0x58453e: 89bc24f4000000 MOV dword ptr [ESP + 0xf4],EDI
    m.w32((f.sp+0x000000f4u), s.di);
  }
  L00584545: { // 0x584545: e8e6120000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5784906u); flags=s.arithmetic_flags;
  }
  L0058454a: { // 0x58454a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058454c: { // 0x58454c: 0f8486000000 JZ 0x005845d8
    if(integer::condition("JZ",flags)) goto L005845d8;
  }
  L00584552: { // 0x584552: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00584557: { // 0x584557: e884b80a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5784924u); flags=s.arithmetic_flags;
  }
  L0058455c: { // 0x58455c: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L00584560: { // 0x584560: 896c2470 MOV dword ptr [ESP + 0x70],EBP
    m.w32((f.sp+0x00000070u), s.bp);
  }
  L00584564: { // 0x584564: df6c246c FILD qword ptr [ESP + 0x6c]
    const auto address=(f.sp+0x0000006cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00584568: { // 0x584568: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0058456e: { // 0x58456e: e8dd641e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5784947u); flags=s.arithmetic_flags;
  }
  L00584573: { // 0x584573: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00584576: { // 0x584576: 77da JA 0x00584552
    if(integer::condition("JA",flags)) goto L00584552;
  }
  L00584578: { // 0x584578: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0058457a: { // 0x58457a: 745c JZ 0x005845d8
    if(integer::condition("JZ",flags)) goto L005845d8;
  }
  L0058457c: { // 0x58457c: 8b542412 MOV EDX,dword ptr [ESP + 0x12]
    s.dx = m.r32((f.sp+0x00000012u));
  }
  L00584580: { // 0x584580: 668b4c2410 MOV CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000010u)));
  }
  L00584585: { // 0x584585: 83c2fd ADD EDX,-0x3
    s.dx = integer::add(s.dx,0xfffffffdu,32,flags);
  }
  L00584588: { // 0x584588: 66894c2434 MOV word ptr [ESP + 0x34],CX
    m.w16((f.sp+0x00000034u), (s.cx & 0xffffu));
  }
  L0058458d: { // 0x58458d: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  L00584593: { // 0x584593: 6689542436 MOV word ptr [ESP + 0x36],DX
    m.w16((f.sp+0x00000036u), (s.dx & 0xffffu));
  }
  L00584598: { // 0x584598: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0058459c: { // 0x58459c: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058459e: { // 0x58459e: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005845a2: { // 0x5845a2: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005845a4: { // 0x5845a4: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005845a8: { // 0x5845a8: 83c10d ADD ECX,0xd
    s.cx = integer::add(s.cx,0x0000000du,32,flags);
  }
  L005845ab: { // 0x5845ab: e8400c0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785008u); flags=s.arithmetic_flags;
  }
  L005845b0: { // 0x5845b0: c644241b01 MOV byte ptr [ESP + 0x1b],0x1
    m.w8((f.sp+0x0000001bu), 0x00000001u);
  }
  L005845b5: { // 0x5845b5: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L005845ba: { // 0x5845ba: 668b442412 MOV AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000012u)));
  }
  L005845bf: { // 0x5845bf: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L005845c1: { // 0x5845c1: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L005845c3: { // 0x5845c3: 663b44242e CMP AX,word ptr [ESP + 0x2e]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000002eu)),16,flags);
  }
  L005845c8: { // 0x5845c8: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L005845cd: { // 0x5845cd: 0f8cd3feffff JL 0x005844a6
    if(integer::condition("JL",flags)) goto L005844a6;
  }
  L005845d3: { // 0x5845d3: e9f9030000 JMP 0x005849d1
    goto L005849d1;
  }
  L005845d8: { // 0x5845d8: 8d8c2404010000 LEA ECX,[ESP + 0x104]
    s.cx = (f.sp+0x00000104u);
  }
  L005845df: { // 0x5845df: e8dc160000 CALL 0x00585cc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585cc0u,5785060u); flags=s.arithmetic_flags;
  }
  L005845e4: { // 0x5845e4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005845e6: { // 0x5845e6: 7447 JZ 0x0058462f
    if(integer::condition("JZ",flags)) goto L0058462f;
  }
  L005845e8: { // 0x5845e8: 8b442412 MOV EAX,dword ptr [ESP + 0x12]
    s.ax = m.r32((f.sp+0x00000012u));
  }
  L005845ec: { // 0x5845ec: 668b542410 MOV DX,word ptr [ESP + 0x10]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000010u)));
  }
  L005845f1: { // 0x5845f1: 83c0fd ADD EAX,-0x3
    s.ax = integer::add(s.ax,0xfffffffdu,32,flags);
  }
  L005845f4: { // 0x5845f4: 6689542438 MOV word ptr [ESP + 0x38],DX
    m.w16((f.sp+0x00000038u), (s.dx & 0xffffu));
  }
  L005845f9: { // 0x5845f9: 668944243a MOV word ptr [ESP + 0x3a],AX
    m.w16((f.sp+0x0000003au), (s.ax & 0xffffu));
  }
  L005845fe: { // 0x5845fe: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00584602: { // 0x584602: a14459a500 MOV EAX,[0x00a55944]
    s.ax = m.r32((0x00a55944u));
  }
  L00584607: { // 0x584607: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0058460b: { // 0x58460b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058460d: { // 0x58460d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058460f: { // 0x58460f: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00584613: { // 0x584613: 8d4805 LEA ECX,[EAX + 0x5]
    s.cx = (s.ax+0x00000005u);
  }
  L00584616: { // 0x584616: e8d50b0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785115u); flags=s.arithmetic_flags;
  }
  L0058461b: { // 0x58461b: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  L00584621: { // 0x584621: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584623: { // 0x584623: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584625: { // 0x584625: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00584629: { // 0x584629: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0058462a: { // 0x58462a: e97cffffff JMP 0x005845ab
    goto L005845ab;
  }
  L0058462f: { // 0x58462f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00584630: { // 0x584630: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00584632: { // 0x584632: 8d8c24a8000000 LEA ECX,[ESP + 0xa8]
    s.cx = (f.sp+0x000000a8u);
  }
  L00584639: { // 0x584639: e8f2110000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5785150u); flags=s.arithmetic_flags;
  }
  L0058463e: { // 0x58463e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00584640: { // 0x584640: 0f846fffffff JZ 0x005845b5
    if(integer::condition("JZ",flags)) goto L005845b5;
  }
  L00584646: { // 0x584646: a14059a500 MOV EAX,[0x00a55940]
    s.ax = m.r32((0x00a55940u));
  }
  L0058464b: { // 0x58464b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058464d: { // 0x58464d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058464f: { // 0x58464f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00584653: { // 0x584653: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00584656: { // 0x584656: e950ffffff JMP 0x005845ab
    goto L005845ab;
  }
  L0058465b: { // 0x58465b: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058465e: { // 0x58465e: 898c24d4000000 MOV dword ptr [ESP + 0xd4],ECX
    m.w32((f.sp+0x000000d4u), s.cx);
  }
  L00584665: { // 0x584665: 899424d8000000 MOV dword ptr [ESP + 0xd8],EDX
    m.w32((f.sp+0x000000d8u), s.dx);
  }
  L0058466c: { // 0x58466c: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  L00584671: { // 0x584671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00584672: { // 0x584672: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00584674: { // 0x584674: 8d8c24d8000000 LEA ECX,[ESP + 0xd8]
    s.cx = (f.sp+0x000000d8u);
  }
  L0058467b: { // 0x58467b: 89bc24e0000000 MOV dword ptr [ESP + 0xe0],EDI
    m.w32((f.sp+0x000000e0u), s.di);
  }
  L00584682: { // 0x584682: 89b424e4000000 MOV dword ptr [ESP + 0xe4],ESI
    m.w32((f.sp+0x000000e4u), s.si);
  }
  L00584689: { // 0x584689: e8a2110000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5785230u); flags=s.arithmetic_flags;
  }
  L0058468e: { // 0x58468e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00584690: { // 0x584690: 0f849b000000 JZ 0x00584731
    if(integer::condition("JZ",flags)) goto L00584731;
  }
  L00584696: { // 0x584696: a14459a500 MOV EAX,[0x00a55944]
    s.ax = m.r32((0x00a55944u));
  }
  L0058469b: { // 0x58469b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058469d: { // 0x58469d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058469f: { // 0x58469f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L005846a3: { // 0x5846a3: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L005846a6: { // 0x5846a6: e8450b0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785259u); flags=s.arithmetic_flags;
  }
  L005846ab: { // 0x5846ab: 8a44241a MOV AL,byte ptr [ESP + 0x1a]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000001au)));
  }
  L005846af: { // 0x5846af: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005846b1: { // 0x5846b1: 0f8403ffffff JZ 0x005845ba
    if(integer::condition("JZ",flags)) goto L005845ba;
  }
  L005846b7: { // 0x5846b7: 8a442427 MOV AL,byte ptr [ESP + 0x27]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000027u)));
  }
  L005846bb: { // 0x5846bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005846bd: { // 0x5846bd: 743c JZ 0x005846fb
    if(integer::condition("JZ",flags)) goto L005846fb;
  }
  L005846bf: { // 0x5846bf: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005846c3: { // 0x5846c3: 668b542412 MOV DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000012u)));
  }
  L005846c8: { // 0x5846c8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005846c9: { // 0x5846c9: 6689542456 MOV word ptr [ESP + 0x56],DX
    m.w16((f.sp+0x00000056u), (s.dx & 0xffffu));
  }
  L005846ce: { // 0x5846ce: 66894c2454 MOV word ptr [ESP + 0x54],CX
    m.w16((f.sp+0x00000054u), (s.cx & 0xffffu));
  }
  L005846d3: { // 0x5846d3: 8b0da4a8a300 MOV ECX,dword ptr [0x00a3a8a4]
    s.cx = m.r32((0x00a3a8a4u));
  }
  L005846d9: { // 0x5846d9: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L005846dd: { // 0x5846dd: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005846df: { // 0x5846df: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005846e1: { // 0x5846e1: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005846e5: { // 0x5846e5: 83c105 ADD ECX,0x5
    s.cx = integer::add(s.cx,0x00000005u,32,flags);
  }
  L005846e8: { // 0x5846e8: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005846ec: { // 0x5846ec: e8ff0a0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785329u); flags=s.arithmetic_flags;
  }
  L005846f1: { // 0x5846f1: c644242700 MOV byte ptr [ESP + 0x27],0x0
    m.w8((f.sp+0x00000027u), 0x00000000u);
  }
  L005846f6: { // 0x5846f6: e9bffeffff JMP 0x005845ba
    goto L005845ba;
  }
  L005846fb: { // 0x5846fb: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005846ff: { // 0x5846ff: 668b442412 MOV AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000012u)));
  }
  L00584704: { // 0x584704: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00584705: { // 0x584705: 668944246a MOV word ptr [ESP + 0x6a],AX
    m.w16((f.sp+0x0000006au), (s.ax & 0xffffu));
  }
  L0058470a: { // 0x58470a: a1a4a8a300 MOV EAX,[0x00a3a8a4]
    s.ax = m.r32((0x00a3a8a4u));
  }
  L0058470f: { // 0x58470f: 6689542468 MOV word ptr [ESP + 0x68],DX
    m.w16((f.sp+0x00000068u), (s.dx & 0xffffu));
  }
  L00584714: { // 0x584714: 8b4c2468 MOV ECX,dword ptr [ESP + 0x68]
    s.cx = m.r32((f.sp+0x00000068u));
  }
  L00584718: { // 0x584718: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058471a: { // 0x58471a: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0058471e: { // 0x58471e: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584720: { // 0x584720: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00584724: { // 0x584724: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
  L00584727: { // 0x584727: e8c40a0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785388u); flags=s.arithmetic_flags;
  }
  L0058472c: { // 0x58472c: e989feffff JMP 0x005845ba
    goto L005845ba;
  }
  L00584731: { // 0x584731: 0fbf4c2410 MOVSX ECX,word ptr [ESP + 0x10]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L00584736: { // 0x584736: 0fbf542412 MOVSX EDX,word ptr [ESP + 0x12]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0058473b: { // 0x58473b: 8a44241a MOV AL,byte ptr [ESP + 0x1a]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000001au)));
  }
  L0058473f: { // 0x58473f: 898c24b4000000 MOV dword ptr [ESP + 0xb4],ECX
    m.w32((f.sp+0x000000b4u), s.cx);
  }
  L00584746: { // 0x584746: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00584748: { // 0x584748: 899424b8000000 MOV dword ptr [ESP + 0xb8],EDX
    m.w32((f.sp+0x000000b8u), s.dx);
  }
  L0058474f: { // 0x58474f: 89bc24bc000000 MOV dword ptr [ESP + 0xbc],EDI
    m.w32((f.sp+0x000000bcu), s.di);
  }
  L00584756: { // 0x584756: c78424c000000004000000 MOV dword ptr [ESP + 0xc0],0x4
    m.w32((f.sp+0x000000c0u), 0x00000004u);
  }
  L00584761: { // 0x584761: 7436 JZ 0x00584799
    if(integer::condition("JZ",flags)) goto L00584799;
  }
  L00584763: { // 0x584763: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00584767: { // 0x584767: 8b4c2412 MOV ECX,dword ptr [ESP + 0x12]
    s.cx = m.r32((f.sp+0x00000012u));
  }
  L0058476b: { // 0x58476b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0058476c: { // 0x58476c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0058476d: { // 0x58476d: 6689442450 MOV word ptr [ESP + 0x50],AX
    m.w16((f.sp+0x00000050u), (s.ax & 0xffffu));
  }
  L00584772: { // 0x584772: a1a4a8a300 MOV EAX,[0x00a3a8a4]
    s.ax = m.r32((0x00a3a8a4u));
  }
  L00584777: { // 0x584777: 66894c2452 MOV word ptr [ESP + 0x52],CX
    m.w16((f.sp+0x00000052u), (s.cx & 0xffffu));
  }
  L0058477c: { // 0x58477c: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L00584780: { // 0x584780: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00584784: { // 0x584784: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584786: { // 0x584786: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584788: { // 0x584788: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0058478c: { // 0x58478c: 8d4803 LEA ECX,[EAX + 0x3]
    s.cx = (s.ax+0x00000003u);
  }
  L0058478f: { // 0x58478f: e85c0a0000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785492u); flags=s.arithmetic_flags;
  }
  L00584794: { // 0x584794: c644241a00 MOV byte ptr [ESP + 0x1a],0x0
    m.w8((f.sp+0x0000001au), 0x00000000u);
  }
  L00584799: { // 0x584799: 8d8c24b4000000 LEA ECX,[ESP + 0xb4]
    s.cx = (f.sp+0x000000b4u);
  }
  L005847a0: { // 0x5847a0: e81b150000 CALL 0x00585cc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585cc0u,5785509u); flags=s.arithmetic_flags;
  }
  L005847a5: { // 0x5847a5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005847a7: { // 0x5847a7: 0f8464010000 JZ 0x00584911
    if(integer::condition("JZ",flags)) goto L00584911;
  }
  L005847ad: { // 0x5847ad: 0fbf5c242e MOVSX EBX,word ptr [ESP + 0x2e]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002eu)),16));
  }
  L005847b2: { // 0x5847b2: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L005847b7: { // 0x5847b7: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005847b9: { // 0x5847b9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005847bb: { // 0x5847bb: 83f904 CMP ECX,0x4
    (void)integer::sub(s.cx,0x00000004u,32,flags);
  }
  L005847be: { // 0x5847be: 0f8cf3010000 JL 0x005849b7
    if(integer::condition("JL",flags)) goto L005849b7;
  }
  L005847c4: { // 0x5847c4: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L005847c9: { // 0x5847c9: 899424c4000000 MOV dword ptr [ESP + 0xc4],EDX
    m.w32((f.sp+0x000000c4u), s.dx);
  }
  L005847d0: { // 0x5847d0: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  L005847d3: { // 0x5847d3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005847d4: { // 0x5847d4: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L005847d6: { // 0x5847d6: 8d8c24c8000000 LEA ECX,[ESP + 0xc8]
    s.cx = (f.sp+0x000000c8u);
  }
  L005847dd: { // 0x5847dd: 898424cc000000 MOV dword ptr [ESP + 0xcc],EAX
    m.w32((f.sp+0x000000ccu), s.ax);
  }
  L005847e4: { // 0x5847e4: 89bc24d0000000 MOV dword ptr [ESP + 0xd0],EDI
    m.w32((f.sp+0x000000d0u), s.di);
  }
  L005847eb: { // 0x5847eb: c78424d400000002000000 MOV dword ptr [ESP + 0xd4],0x2
    m.w32((f.sp+0x000000d4u), 0x00000002u);
  }
  L005847f6: { // 0x5847f6: e835100000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5785595u); flags=s.arithmetic_flags;
  }
  L005847fb: { // 0x5847fb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005847fd: { // 0x5847fd: 7416 JZ 0x00584815
    if(integer::condition("JZ",flags)) goto L00584815;
  }
  L005847ff: { // 0x5847ff: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00584804: { // 0x584804: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00584806: { // 0x584806: 83fb05 CMP EBX,0x5
    (void)integer::sub(s.bx,0x00000005u,32,flags);
  }
  L00584809: { // 0x584809: 7e0a JLE 0x00584815
    if(integer::condition("JLE",flags)) goto L00584815;
  }
  L0058480b: { // 0x58480b: c644241a01 MOV byte ptr [ESP + 0x1a],0x1
    m.w8((f.sp+0x0000001au), 0x00000001u);
  }
  L00584810: { // 0x584810: c644242701 MOV byte ptr [ESP + 0x27],0x1
    m.w8((f.sp+0x00000027u), 0x00000001u);
  }
  L00584815: { // 0x584815: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  L0058481b: { // 0x58481b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058481d: { // 0x58481d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0058481f: { // 0x58481f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00584823: { // 0x584823: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L00584826: { // 0x584826: e8c5090000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785643u); flags=s.arithmetic_flags;
  }
  L0058482b: { // 0x58482b: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L00584830: { // 0x584830: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00584835: { // 0x584835: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00584836: { // 0x584836: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00584837: { // 0x584837: 899424f8000000 MOV dword ptr [ESP + 0xf8],EDX
    m.w32((f.sp+0x000000f8u), s.dx);
  }
  L0058483e: { // 0x58483e: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  L00584840: { // 0x584840: 8d8c24f8000000 LEA ECX,[ESP + 0xf8]
    s.cx = (f.sp+0x000000f8u);
  }
  L00584847: { // 0x584847: 898424fc000000 MOV dword ptr [ESP + 0xfc],EAX
    m.w32((f.sp+0x000000fcu), s.ax);
  }
  L0058484e: { // 0x58484e: 89b42400010000 MOV dword ptr [ESP + 0x100],ESI
    m.w32((f.sp+0x00000100u), s.si);
  }
  L00584855: { // 0x584855: 89bc2404010000 MOV dword ptr [ESP + 0x104],EDI
    m.w32((f.sp+0x00000104u), s.di);
  }
  L0058485c: { // 0x58485c: e8cf0f0000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5785697u); flags=s.arithmetic_flags;
  }
  L00584861: { // 0x584861: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00584863: { // 0x584863: 7432 JZ 0x00584897
    if(integer::condition("JZ",flags)) goto L00584897;
  }
  L00584865: { // 0x584865: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00584869: { // 0x584869: 668b542412 MOV DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000012u)));
  }
  L0058486e: { // 0x58486e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0058486f: { // 0x58486f: 668954244e MOV word ptr [ESP + 0x4e],DX
    m.w16((f.sp+0x0000004eu), (s.dx & 0xffffu));
  }
  L00584874: { // 0x584874: 66894c244c MOV word ptr [ESP + 0x4c],CX
    m.w16((f.sp+0x0000004cu), (s.cx & 0xffffu));
  }
  L00584879: { // 0x584879: 8b0da4a8a300 MOV ECX,dword ptr [0x00a3a8a4]
    s.cx = m.r32((0x00a3a8a4u));
  }
  L0058487f: { // 0x58487f: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00584883: { // 0x584883: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584885: { // 0x584885: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584887: { // 0x584887: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0058488b: { // 0x58488b: 83c10c ADD ECX,0xc
    s.cx = integer::add(s.cx,0x0000000cu,32,flags);
  }
  L0058488e: { // 0x58488e: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00584892: { // 0x584892: e859090000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785751u); flags=s.arithmetic_flags;
  }
  L00584897: { // 0x584897: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0058489c: { // 0x58489c: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L005848a1: { // 0x5848a1: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L005848a3: { // 0x5848a3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005848a4: { // 0x5848a4: 89942418010000 MOV dword ptr [ESP + 0x118],EDX
    m.w32((f.sp+0x00000118u), s.dx);
  }
  L005848ab: { // 0x5848ab: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  L005848ad: { // 0x5848ad: 8d8c2418010000 LEA ECX,[ESP + 0x118]
    s.cx = (f.sp+0x00000118u);
  }
  L005848b4: { // 0x5848b4: 8984241c010000 MOV dword ptr [ESP + 0x11c],EAX
    m.w32((f.sp+0x0000011cu), s.ax);
  }
  L005848bb: { // 0x5848bb: 89b42420010000 MOV dword ptr [ESP + 0x120],ESI
    m.w32((f.sp+0x00000120u), s.si);
  }
  L005848c2: { // 0x5848c2: 89bc2424010000 MOV dword ptr [ESP + 0x124],EDI
    m.w32((f.sp+0x00000124u), s.di);
  }
  L005848c9: { // 0x5848c9: e8620f0000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5785806u); flags=s.arithmetic_flags;
  }
  L005848ce: { // 0x5848ce: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005848d0: { // 0x5848d0: 7434 JZ 0x00584906
    if(integer::condition("JZ",flags)) goto L00584906;
  }
  L005848d2: { // 0x5848d2: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005848d6: { // 0x5848d6: 668b542412 MOV DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000012u)));
  }
  L005848db: { // 0x5848db: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L005848de: { // 0x5848de: 668954244a MOV word ptr [ESP + 0x4a],DX
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L005848e3: { // 0x5848e3: 66894c2448 MOV word ptr [ESP + 0x48],CX
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L005848e8: { // 0x5848e8: 8b0da4a8a300 MOV ECX,dword ptr [0x00a3a8a4]
    s.cx = m.r32((0x00a3a8a4u));
  }
  L005848ee: { // 0x5848ee: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L005848f2: { // 0x5848f2: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005848f4: { // 0x5848f4: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005848f6: { // 0x5848f6: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005848fa: { // 0x5848fa: 83c10c ADD ECX,0xc
    s.cx = integer::add(s.cx,0x0000000cu,32,flags);
  }
  L005848fd: { // 0x5848fd: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00584901: { // 0x584901: e8ea080000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785862u); flags=s.arithmetic_flags;
  }
  L00584906: { // 0x584906: 668344241202 ADD word ptr [ESP + 0x12],0x2
    m.w16((f.sp+0x00000012u), integer::add(m.r16((f.sp+0x00000012u)),0x00000002u,16,flags));
  }
  L0058490c: { // 0x58490c: e9a9fcffff JMP 0x005845ba
    goto L005845ba;
  }
  L00584911: { // 0x584911: 8b442412 MOV EAX,dword ptr [ESP + 0x12]
    s.ax = m.r32((f.sp+0x00000012u));
  }
  L00584915: { // 0x584915: 668b542410 MOV DX,word ptr [ESP + 0x10]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000010u)));
  }
  L0058491a: { // 0x58491a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0058491b: { // 0x58491b: 6689542440 MOV word ptr [ESP + 0x40],DX
    m.w16((f.sp+0x00000040u), (s.dx & 0xffffu));
  }
  L00584920: { // 0x584920: 6689442442 MOV word ptr [ESP + 0x42],AX
    m.w16((f.sp+0x00000042u), (s.ax & 0xffffu));
  }
  L00584925: { // 0x584925: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00584929: { // 0x584929: a14059a500 MOV EAX,[0x00a55940]
    s.ax = m.r32((0x00a55940u));
  }
  L0058492e: { // 0x58492e: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00584932: { // 0x584932: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584934: { // 0x584934: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584936: { // 0x584936: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0058493a: { // 0x58493a: 8d4803 LEA ECX,[EAX + 0x3]
    s.cx = (s.ax+0x00000003u);
  }
  L0058493d: { // 0x58493d: e8ae080000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5785922u); flags=s.arithmetic_flags;
  }
  L00584942: { // 0x584942: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00584946: { // 0x584946: 8b542412 MOV EDX,dword ptr [ESP + 0x12]
    s.dx = m.r32((f.sp+0x00000012u));
  }
  L0058494a: { // 0x58494a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0058494b: { // 0x58494b: 83c2fe ADD EDX,-0x2
    s.dx = integer::add(s.dx,0xfffffffeu,32,flags);
  }
  L0058494e: { // 0x58494e: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  L00584953: { // 0x584953: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00584957: { // 0x584957: 668954243e MOV word ptr [ESP + 0x3e],DX
    m.w16((f.sp+0x0000003eu), (s.dx & 0xffffu));
  }
  L0058495c: { // 0x58495c: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00584960: { // 0x584960: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00584961: { // 0x584961: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00584966: { // 0x584966: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0058496a: { // 0x58496a: e8910bfcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5785967u); flags=s.arithmetic_flags;
  }
  L0058496f: { // 0x58496f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00584971: { // 0x584971: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00584973: { // 0x584973: e8c86befff CALL 0x0047b540
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b540u,5785976u); flags=s.arithmetic_flags;
  }
  L00584978: { // 0x584978: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058497a: { // 0x58497a: 7431 JZ 0x005849ad
    if(integer::condition("JZ",flags)) goto L005849ad;
  }
  L0058497c: { // 0x58497c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0058497e: { // 0x58497e: e8bd6befff CALL 0x0047b540
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b540u,5785987u); flags=s.arithmetic_flags;
  }
  L00584983: { // 0x584983: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00584985: { // 0x584985: 7426 JZ 0x005849ad
    if(integer::condition("JZ",flags)) goto L005849ad;
  }
  L00584987: { // 0x584987: 8b154459a500 MOV EDX,dword ptr [0x00a55944]
    s.dx = m.r32((0x00a55944u));
  }
  L0058498d: { // 0x58498d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058498e: { // 0x58498e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0058498f: { // 0x58498f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00584991: { // 0x584991: 895638 MOV dword ptr [ESI + 0x38],EDX
    m.w32((s.si+0x00000038u), s.dx);
  }
  L00584994: { // 0x584994: c6861a01000001 MOV byte ptr [ESI + 0x11a],0x1
    m.w8((s.si+0x0000011au), 0x00000001u);
  }
  L0058499b: { // 0x58499b: e8201defff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5786016u); flags=s.arithmetic_flags;
  }
  L005849a0: { // 0x5849a0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005849a2: { // 0x5849a2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005849a4: { // 0x5849a4: e8976befff CALL 0x0047b540
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b540u,5786025u); flags=s.arithmetic_flags;
  }
  L005849a9: { // 0x5849a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005849ab: { // 0x5849ab: 75da JNZ 0x00584987
    if(integer::condition("JNZ",flags)) goto L00584987;
  }
  L005849ad: { // 0x5849ad: c644241b00 MOV byte ptr [ESP + 0x1b],0x0
    m.w8((f.sp+0x0000001bu), 0x00000000u);
  }
  L005849b2: { // 0x5849b2: e903fcffff JMP 0x005845ba
    goto L005845ba;
  }
  L005849b7: { // 0x5849b7: a14459a500 MOV EAX,[0x00a55944]
    s.ax = m.r32((0x00a55944u));
  }
  L005849bc: { // 0x5849bc: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005849be: { // 0x5849be: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005849c0: { // 0x5849c0: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L005849c4: { // 0x5849c4: 8d4807 LEA ECX,[EAX + 0x7]
    s.cx = (s.ax+0x00000007u);
  }
  L005849c7: { // 0x5849c7: e824080000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5786060u); flags=s.arithmetic_flags;
  }
  L005849cc: { // 0x5849cc: e9d8000000 JMP 0x00584aa9
    goto L00584aa9;
  }
  L005849d1: { // 0x5849d1: 8a44241a MOV AL,byte ptr [ESP + 0x1a]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000001au)));
  }
  L005849d5: { // 0x5849d5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005849d7: { // 0x5849d7: 7432 JZ 0x00584a0b
    if(integer::condition("JZ",flags)) goto L00584a0b;
  }
  L005849d9: { // 0x5849d9: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005849dd: { // 0x5849dd: 8b542412 MOV EDX,dword ptr [ESP + 0x12]
    s.dx = m.r32((f.sp+0x00000012u));
  }
  L005849e1: { // 0x5849e1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005849e2: { // 0x5849e2: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005849e3: { // 0x5849e3: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L005849e8: { // 0x5849e8: 8b0da4a8a300 MOV ECX,dword ptr [0x00a3a8a4]
    s.cx = m.r32((0x00a3a8a4u));
  }
  L005849ee: { // 0x5849ee: 6689542432 MOV word ptr [ESP + 0x32],DX
    m.w16((f.sp+0x00000032u), (s.dx & 0xffffu));
  }
  L005849f3: { // 0x5849f3: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L005849f7: { // 0x5849f7: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005849f9: { // 0x5849f9: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005849fb: { // 0x5849fb: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005849ff: { // 0x5849ff: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L00584a02: { // 0x584a02: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00584a06: { // 0x584a06: e8e5070000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5786123u); flags=s.arithmetic_flags;
  }
  L00584a0b: { // 0x584a0b: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L00584a10: { // 0x584a10: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00584a15: { // 0x584a15: 89942494000000 MOV dword ptr [ESP + 0x94],EDX
    m.w32((f.sp+0x00000094u), s.dx);
  }
  L00584a1c: { // 0x584a1c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00584a1d: { // 0x584a1d: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00584a1f: { // 0x584a1f: 8d8c2498000000 LEA ECX,[ESP + 0x98]
    s.cx = (f.sp+0x00000098u);
  }
  L00584a26: { // 0x584a26: 8984249c000000 MOV dword ptr [ESP + 0x9c],EAX
    m.w32((f.sp+0x0000009cu), s.ax);
  }
  L00584a2d: { // 0x584a2d: 89bc24a0000000 MOV dword ptr [ESP + 0xa0],EDI
    m.w32((f.sp+0x000000a0u), s.di);
  }
  L00584a34: { // 0x584a34: c78424a400000004000000 MOV dword ptr [ESP + 0xa4],0x4
    m.w32((f.sp+0x000000a4u), 0x00000004u);
  }
  L00584a3f: { // 0x584a3f: e8ec0d0000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5786180u); flags=s.arithmetic_flags;
  }
  L00584a44: { // 0x584a44: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00584a46: { // 0x584a46: 7445 JZ 0x00584a8d
    if(integer::condition("JZ",flags)) goto L00584a8d;
  }
  L00584a48: { // 0x584a48: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00584a4d: { // 0x584a4d: e88eb30a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5786194u); flags=s.arithmetic_flags;
  }
  L00584a52: { // 0x584a52: 8944247c MOV dword ptr [ESP + 0x7c],EAX
    m.w32((f.sp+0x0000007cu), s.ax);
  }
  L00584a56: { // 0x584a56: 89ac2480000000 MOV dword ptr [ESP + 0x80],EBP
    m.w32((f.sp+0x00000080u), s.bp);
  }
  L00584a5d: { // 0x584a5d: df6c247c FILD qword ptr [ESP + 0x7c]
    const auto address=(f.sp+0x0000007cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00584a61: { // 0x584a61: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L00584a67: { // 0x584a67: e8e45f1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5786220u); flags=s.arithmetic_flags;
  }
  L00584a6c: { // 0x584a6c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00584a6f: { // 0x584a6f: 77d7 JA 0x00584a48
    if(integer::condition("JA",flags)) goto L00584a48;
  }
  L00584a71: { // 0x584a71: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00584a73: { // 0x584a73: 7418 JZ 0x00584a8d
    if(integer::condition("JZ",flags)) goto L00584a8d;
  }
  L00584a75: { // 0x584a75: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  L00584a7b: { // 0x584a7b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584a7d: { // 0x584a7d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584a7f: { // 0x584a7f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00584a83: { // 0x584a83: 83c10c ADD ECX,0xc
    s.cx = integer::add(s.cx,0x0000000cu,32,flags);
  }
  L00584a86: { // 0x584a86: e865070000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5786251u); flags=s.arithmetic_flags;
  }
  L00584a8b: { // 0x584a8b: eb1c JMP 0x00584aa9
    goto L00584aa9;
  }
  L00584a8d: { // 0x584a8d: a14059a500 MOV EAX,[0x00a55940]
    s.ax = m.r32((0x00a55940u));
  }
  L00584a92: { // 0x584a92: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584a94: { // 0x584a94: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00584a96: { // 0x584a96: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00584a9a: { // 0x584a9a: 8d4803 LEA ECX,[EAX + 0x3]
    s.cx = (s.ax+0x00000003u);
  }
  L00584a9d: { // 0x584a9d: e84e070000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5786274u); flags=s.arithmetic_flags;
  }
  L00584aa2: { // 0x584aa2: eb05 JMP 0x00584aa9
    goto L00584aa9;
  }
  L00584aa4: { // 0x584aa4: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L00584aa9: { // 0x584aa9: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L00584aad: { // 0x584aad: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L00584ab1: { // 0x584ab1: 83eb0a SUB EBX,0xa
    s.bx = integer::sub(s.bx,0x0000000au,32,flags);
  }
  L00584ab4: { // 0x584ab4: 66834424200a ADD word ptr [ESP + 0x20],0xa
    m.w16((f.sp+0x00000020u), integer::add(m.r16((f.sp+0x00000020u)),0x0000000au,16,flags));
  }
  L00584aba: { // 0x584aba: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00584abe: { // 0x584abe: eb0d JMP 0x00584acd
    goto L00584acd;
  }
  L00584ac0: { // 0x584ac0: 668344242002 ADD word ptr [ESP + 0x20],0x2
    m.w16((f.sp+0x00000020u), integer::add(m.r16((f.sp+0x00000020u)),0x00000002u,16,flags));
  }
  L00584ac6: { // 0x584ac6: 83eb02 SUB EBX,0x2
    s.bx = integer::sub(s.bx,0x00000002u,32,flags);
  }
  L00584ac9: { // 0x584ac9: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00584acd: { // 0x584acd: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00584acf: { // 0x584acf: 0f8f37f9ffff JG 0x0058440c
    if(integer::condition("JG",flags)) goto L0058440c;
  }
  L00584ad5: { // 0x584ad5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00584ad6: { // 0x584ad6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00584ad7: { // 0x584ad7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00584ad8: { // 0x584ad8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00584ad9: { // 0x584ad9: 81c418010000 ADD ESP,0x118
    f.sp = integer::add(f.sp,0x00000118u,32,flags);
  }
  L00584adf: { // 0x584adf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
