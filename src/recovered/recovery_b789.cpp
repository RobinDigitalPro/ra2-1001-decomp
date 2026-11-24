#include "recovered/recovery_b789_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b789 {
namespace {
void f_000759b0(Memory&,State&,Frame&,const Operations&);
void f_00074d00(Memory&,State&,Frame&,const Operations&);
void f_0001b630(Memory&,State&,Frame&,const Operations&);
void f_00298010(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00075040(Memory&,State&,Frame&,const Operations&);
void f_001d46d0(Memory&,State&,Frame&,const Operations&);
void f_001d57d0(Memory&,State&,Frame&,const Operations&);
void f_00074ab0(Memory&,State&,Frame&,const Operations&);
void f_001d4730(Memory&,State&,Frame&,const Operations&);
void f_00298660(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_0005ec50(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_000759b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004759b0: { // 0x4759b0: 83ec3c SUB ESP, 0x3c
    f.sp = integer::sub(f.sp,0x0000003cu,32,flags);
  }
  L004759b3: { // 0x4759b3: 8d44241c LEA EAX, [ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L004759b7: { // 0x4759b7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004759b8: { // 0x4759b8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004759b9: { // 0x4759b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004759ba: { // 0x4759ba: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004759bb: { // 0x4759bb: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004759bd: { // 0x4759bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004759be: { // 0x4759be: e83df3ffff CALL 0x474d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474d00u,4676035u); flags=s.arithmetic_flags;
  }
  L004759c3: { // 0x4759c3: 8d4c243c LEA ECX, [ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L004759c7: { // 0x4759c7: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004759c9: { // 0x4759c9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004759ca: { // 0x4759ca: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004759cc: { // 0x4759cc: e8dff0ffff CALL 0x474ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474ab0u,4676049u); flags=s.arithmetic_flags;
  }
  L004759d1: { // 0x4759d1: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L004759d4: { // 0x4759d4: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759d6: { // 0x4759d6: 0f8e98000000 JLE 0x475a74
    if(integer::condition("JLE",flags)) goto L00475a74;
  }
  L004759dc: { // 0x4759dc: 8b480c MOV ECX, dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L004759df: { // 0x4759df: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759e1: { // 0x4759e1: 0f8e8d000000 JLE 0x475a74
    if(integer::condition("JLE",flags)) goto L00475a74;
  }
  L004759e7: { // 0x4759e7: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L004759ea: { // 0x4759ea: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759ec: { // 0x4759ec: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004759f0: { // 0x4759f0: 7e75 JLE 0x475a67
    if(integer::condition("JLE",flags)) goto L00475a67;
  }
  L004759f2: { // 0x4759f2: 8b4f0c MOV ECX, dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L004759f5: { // 0x4759f5: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759f7: { // 0x4759f7: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004759fb: { // 0x4759fb: 7e6a JLE 0x475a67
    if(integer::condition("JLE",flags)) goto L00475a67;
  }
  L004759fd: { // 0x4759fd: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004759ff: { // 0x4759ff: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00475a01: { // 0x475a01: 8b6808 MOV EBP, dword ptr [EAX + 8]
    s.bp = m.r32((s.ax+8u));
  }
  L00475a04: { // 0x475a04: 8b5804 MOV EBX, dword ptr [EAX + 4]
    s.bx = m.r32((s.ax+4u));
  }
  L00475a07: { // 0x475a07: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00475a0a: { // 0x475a0a: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00475a0c: { // 0x475a0c: 896c2424 MOV dword ptr [ESP + 0x24], EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L00475a10: { // 0x475a10: 7e0a JLE 0x475a1c
    if(integer::condition("JLE",flags)) goto L00475a1c;
  }
  L00475a12: { // 0x475a12: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00475a14: { // 0x475a14: 03e9 ADD EBP, ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00475a16: { // 0x475a16: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00475a18: { // 0x475a18: 896c2424 MOV dword ptr [ESP + 0x24], EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L00475a1c: { // 0x475a1c: 8b7f04 MOV EDI, dword ptr [EDI + 4]
    s.di = m.r32((s.di+4u));
  }
  L00475a1f: { // 0x475a1f: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00475a21: { // 0x475a21: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00475a25: { // 0x475a25: 7e06 JLE 0x475a2d
    if(integer::condition("JLE",flags)) goto L00475a2d;
  }
  L00475a27: { // 0x475a27: 2bdf SUB EBX, EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  L00475a29: { // 0x475a29: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00475a2b: { // 0x475a2b: 8bdf MOV EBX, EDI
    s.bx = s.di;
  }
  L00475a2d: { // 0x475a2d: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00475a31: { // 0x475a31: 03e9 ADD EBP, ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00475a33: { // 0x475a33: 03fa ADD EDI, EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00475a35: { // 0x475a35: 3bef CMP EBP, EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L00475a37: { // 0x475a37: 7d0c JGE 0x475a45
    if(integer::condition("JGE",flags)) goto L00475a45;
  }
  L00475a39: { // 0x475a39: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00475a3d: { // 0x475a3d: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00475a3f: { // 0x475a3f: 8d7c3a01 LEA EDI, [EDX + EDI + 1]
    s.di = (s.dx+s.di+1u);
  }
  L00475a43: { // 0x475a43: eb04 JMP 0x475a49
    goto L00475a49;
  }
  L00475a45: { // 0x475a45: 8b7c2424 MOV EDI, dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L00475a49: { // 0x475a49: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00475a4d: { // 0x475a4d: 8b6c2418 MOV EBP, dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00475a51: { // 0x475a51: 03d5 ADD EDX, EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L00475a53: { // 0x475a53: 8d2c18 LEA EBP, [EAX + EBX]
    s.bp = (s.ax+s.bx);
  }
  L00475a56: { // 0x475a56: 3bea CMP EBP, EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00475a58: { // 0x475a58: 7d05 JGE 0x475a5f
    if(integer::condition("JGE",flags)) goto L00475a5f;
  }
  L00475a5a: { // 0x475a5a: 2bd3 SUB EDX, EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00475a5c: { // 0x475a5c: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00475a5d: { // 0x475a5d: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L00475a5f: { // 0x475a5f: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L00475a61: { // 0x475a61: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L00475a63: { // 0x475a63: 8bdf MOV EBX, EDI
    s.bx = s.di;
  }
  L00475a65: { // 0x475a65: eb18 JMP 0x475a7f
    goto L00475a7f;
  }
  L00475a67: { // 0x475a67: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00475a69: { // 0x475a69: 8b4804 MOV ECX, dword ptr [EAX + 4]
    s.cx = m.r32((s.ax+4u));
  }
  L00475a6c: { // 0x475a6c: 8b5808 MOV EBX, dword ptr [EAX + 8]
    s.bx = m.r32((s.ax+8u));
  }
  L00475a6f: { // 0x475a6f: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00475a72: { // 0x475a72: eb0b JMP 0x475a7f
    goto L00475a7f;
  }
  L00475a74: { // 0x475a74: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00475a76: { // 0x475a76: 8b4f04 MOV ECX, dword ptr [EDI + 4]
    s.cx = m.r32((s.di+4u));
  }
  L00475a79: { // 0x475a79: 8b5f08 MOV EBX, dword ptr [EDI + 8]
    s.bx = m.r32((s.di+8u));
  }
  L00475a7c: { // 0x475a7c: 8b470c MOV EAX, dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00475a7f: { // 0x475a7f: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00475a83: { // 0x475a83: 8b1574198200 MOV EDX, dword ptr [0x821974]
    s.dx = m.r32((0x00821974u));
  }
  L00475a89: { // 0x475a89: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00475a8d: { // 0x475a8d: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00475a8f: { // 0x475a8f: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00475a93: { // 0x475a93: 8b4e44 MOV ECX, dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  L00475a96: { // 0x475a96: 895c2424 MOV dword ptr [ESP + 0x24], EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00475a9a: { // 0x475a9a: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00475a9e: { // 0x475a9e: e88dec1500 CALL 0x5d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4676259u); flags=s.arithmetic_flags;
  }
  L00475aa3: { // 0x475aa3: 8b5c2450 MOV EBX, dword ptr [ESP + 0x50]
    s.bx = m.r32((f.sp+0x00000050u));
  }
  L00475aa7: { // 0x475aa7: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00475aa9: { // 0x475aa9: 0f8e21010000 JLE 0x475bd0
    if(integer::condition("JLE",flags)) goto L00475bd0;
  }
  L00475aaf: { // 0x475aaf: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00475ab2: { // 0x475ab2: 0f8418010000 JZ 0x475bd0
    if(integer::condition("JZ",flags)) goto L00475bd0;
  }
  L00475ab8: { // 0x475ab8: 8b0d3c86aa00 MOV ECX, dword ptr [0xaa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L00475abe: { // 0x475abe: 8b2c81 MOV EBP, dword ptr [ECX + EAX*4]
    s.bp = m.r32((s.cx+(s.ax * 4u)));
  }
  L00475ac1: { // 0x475ac1: 8a861e010000 MOV AL, byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00475ac7: { // 0x475ac7: 3c0b CMP AL, 0xb
    (void)integer::sub((s.ax & 0xffu),0x0000000bu,8,flags);
  }
  L00475ac9: { // 0x475ac9: 750b JNZ 0x475ad6
    if(integer::condition("JNZ",flags)) goto L00475ad6;
  }
  L00475acb: { // 0x475acb: 8d5624 LEA EDX, [ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  L00475ace: { // 0x475ace: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00475ad0: { // 0x475ad0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00475ad1: { // 0x475ad1: e86aa02600 CALL 0x6dfb40
    s.arithmetic_flags=flags; invoke(m,s,f,0x006dfb40u,4676310u); flags=s.arithmetic_flags;
  }
  L00475ad6: { // 0x475ad6: 8a861e010000 MOV AL, byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00475adc: { // 0x475adc: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00475ade: { // 0x475ade: 81e1ff000000 AND ECX, 0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00475ae4: { // 0x475ae4: 8d5101 LEA EDX, [ECX + 1]
    s.dx = (s.cx+1u);
  }
  L00475ae7: { // 0x475ae7: 3bd3 CMP EDX, EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L00475ae9: { // 0x475ae9: 7e0d JLE 0x475af8
    if(integer::condition("JLE",flags)) goto L00475af8;
  }
  L00475aeb: { // 0x475aeb: 2ac3 SUB AL, BL
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00475aed: { // 0x475aed: 88861e010000 MOV byte ptr [ESI + 0x11e], AL
    m.w8((s.si+0x0000011eu), (s.ax & 0xffu));
  }
  L00475af3: { // 0x475af3: e99f000000 JMP 0x475b97
    goto L00475b97;
  }
  L00475af8: { // 0x475af8: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L00475afa: { // 0x475afa: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L00475afc: { // 0x475afc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00475afe: { // 0x475afe: c74644ffffffff MOV dword ptr [ESI + 0x44], 0xffffffff
    m.w32((s.si+0x00000044u), 0xffffffffu);
  }
  L00475b05: { // 0x475b05: c6861e01000000 MOV byte ptr [ESI + 0x11e], 0
    m.w8((s.si+0x0000011eu), 0u);
  }
  L00475b0c: { // 0x475b0c: e82fc6ffff CALL 0x472140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00472140u,4676369u); flags=s.arithmetic_flags;
  }
  L00475b11: { // 0x475b11: 83c624 ADD ESI, 0x24
    s.si = integer::add(s.si,0x00000024u,32,flags);
  }
  L00475b14: { // 0x475b14: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00475b19: { // 0x475b19: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00475b1a: { // 0x475b1a: e8d1301b00 CALL 0x628bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00628bf0u,4676383u); flags=s.arithmetic_flags;
  }
  L00475b1f: { // 0x475b1f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00475b21: { // 0x475b21: e82a952600 CALL 0x6df050
    s.arithmetic_flags=flags; invoke(m,s,f,0x006df050u,4676390u); flags=s.arithmetic_flags;
  }
  L00475b26: { // 0x475b26: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00475b28: { // 0x475b28: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00475b2a: { // 0x475b2a: 83e007 AND EAX, 7
    s.ax = integer::logical((s.ax)&(7u),32,flags);
  }
  L00475b2d: { // 0x475b2d: 668b0c85a09d8300 MOV CX, word ptr [EAX*4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 4u)+0x00839da0u)));
  }
  L00475b35: { // 0x475b35: 668b1485a29d8300 MOV DX, word ptr [EAX*4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 4u)+0x00839da2u)));
  }
  L00475b3d: { // 0x475b3d: 66030e ADD CX, word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00475b40: { // 0x475b40: 66035602 ADD DX, word ptr [ESI + 2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.si+2u)),16,flags));
  }
  L00475b44: { // 0x475b44: 8d0485a09d8300 LEA EAX, [EAX*4 + 0x839da0]
    s.ax = ((s.ax * 4u)+0x00839da0u);
  }
  L00475b4b: { // 0x475b4b: 66894c2410 MOV word ptr [ESP + 0x10], CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00475b50: { // 0x475b50: 8d4c2450 LEA ECX, [ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00475b54: { // 0x475b54: 6689542412 MOV word ptr [ESP + 0x12], DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L00475b59: { // 0x475b59: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00475b5d: { // 0x475b5d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00475b5e: { // 0x475b5e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00475b63: { // 0x475b63: 89442454 MOV dword ptr [ESP + 0x54], EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00475b67: { // 0x475b67: e8d4230d00 CALL 0x547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,4676460u); flags=s.arithmetic_flags;
  }
  L00475b6c: { // 0x475b6c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00475b6e: { // 0x475b6e: 7421 JZ 0x475b91
    if(integer::condition("JZ",flags)) goto L00475b91;
  }
  L00475b70: { // 0x475b70: 8d4c2450 LEA ECX, [ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00475b74: { // 0x475b74: e8172ffbff CALL 0x428a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428a90u,4676473u); flags=s.arithmetic_flags;
  }
  L00475b79: { // 0x475b79: 8b95f8000000 MOV EDX, dword ptr [EBP + 0xf8]
    s.dx = m.r32((s.bp+0x000000f8u));
  }
  L00475b7f: { // 0x475b7f: 803c1000 CMP byte ptr [EAX + EDX], 0
    (void)integer::sub(m.r8((s.ax+s.dx)),0u,8,flags);
  }
  L00475b83: { // 0x475b83: 750c JNZ 0x475b91
    if(integer::condition("JNZ",flags)) goto L00475b91;
  }
  L00475b85: { // 0x475b85: 8d442450 LEA EAX, [ESP + 0x50]
    s.ax = (f.sp+0x00000050u);
  }
  L00475b89: { // 0x475b89: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00475b8b: { // 0x475b8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00475b8c: { // 0x475b8c: e8ff942600 CALL 0x6df090
    s.arithmetic_flags=flags; invoke(m,s,f,0x006df090u,4676497u); flags=s.arithmetic_flags;
  }
  L00475b91: { // 0x475b91: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00475b92: { // 0x475b92: 83ff08 CMP EDI, 8
    (void)integer::sub(s.di,8u,32,flags);
  }
  L00475b95: { // 0x475b95: 7c91 JL 0x475b28
    if(integer::condition("JL",flags)) goto L00475b28;
  }
  L00475b97: { // 0x475b97: 8b54241c MOV EDX, dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00475b9b: { // 0x475b9b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00475b9d: { // 0x475b9d: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00475ba1: { // 0x475ba1: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00475ba4: { // 0x475ba4: 8bcc MOV ECX, ESP
    s.cx = f.sp;
  }
  L00475ba6: { // 0x475ba6: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L00475ba8: { // 0x475ba8: 8b542438 MOV EDX, dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00475bac: { // 0x475bac: 894104 MOV dword ptr [ECX + 4], EAX
    m.w32((s.cx+4u), s.ax);
  }
  L00475baf: { // 0x475baf: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00475bb3: { // 0x475bb3: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L00475bb6: { // 0x475bb6: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L00475bb9: { // 0x475bb9: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00475bbf: { // 0x475bbf: e89c2a2200 CALL 0x698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,4676548u); flags=s.arithmetic_flags;
  }
  L00475bc4: { // 0x475bc4: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L00475bc6: { // 0x475bc6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00475bc7: { // 0x475bc7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00475bc8: { // 0x475bc8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00475bc9: { // 0x475bc9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00475bca: { // 0x475bca: 83c43c ADD ESP, 0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L00475bcd: { // 0x475bcd: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00475bd0: { // 0x475bd0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00475bd1: { // 0x475bd1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00475bd2: { // 0x475bd2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00475bd3: { // 0x475bd3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00475bd5: { // 0x475bd5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00475bd6: { // 0x475bd6: 83c43c ADD ESP, 0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L00475bd9: { // 0x475bd9: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00074d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00474d00: { // 0x474d00: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00474d03: { // 0x474d03: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00474d04: { // 0x474d04: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00474d05: { // 0x474d05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00474d06: { // 0x474d06: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00474d07: { // 0x474d07: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00474d09: { // 0x474d09: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L00474d0c: { // 0x474d0c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00474d0f: { // 0x474d0f: 750d JNZ 0x00474d1e
    if(integer::condition("JNZ",flags)) goto L00474d1e;
  }
  L00474d11: { // 0x474d11: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474d13: { // 0x474d13: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474d15: { // 0x474d15: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474d17: { // 0x474d17: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474d19: { // 0x474d19: e974010000 JMP 0x00474e92
    goto L00474e92;
  }
  L00474d1e: { // 0x474d1e: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00474d24: { // 0x474d24: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00474d27: { // 0x474d27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00474d29: { // 0x474d29: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00474d2b: { // 0x474d2b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4672817u); flags=s.arithmetic_flags;
  }
  L00474d31: { // 0x474d31: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00474d33: { // 0x474d33: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00474d35: { // 0x474d35: 750d JNZ 0x00474d44
    if(integer::condition("JNZ",flags)) goto L00474d44;
  }
  L00474d37: { // 0x474d37: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474d39: { // 0x474d39: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474d3b: { // 0x474d3b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474d3d: { // 0x474d3d: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474d3f: { // 0x474d3f: e94e010000 JMP 0x00474e92
    goto L00474e92;
  }
  L00474d44: { // 0x474d44: 8a871e010000 MOV AL,byte ptr [EDI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011eu)));
  }
  L00474d4a: { // 0x474d4a: 88442410 MOV byte ptr [ESP + 0x10],AL
    m.w8((f.sp+0x00000010u), (s.ax & 0xffu));
  }
  L00474d4e: { // 0x474d4e: 8a867a020000 MOV AL,byte ptr [ESI + 0x27a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000027au)));
  }
  L00474d54: { // 0x474d54: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00474d56: { // 0x474d56: 7405 JZ 0x00474d5d
    if(integer::condition("JZ",flags)) goto L00474d5d;
  }
  L00474d58: { // 0x474d58: c644241000 MOV byte ptr [ESP + 0x10],0x0
    m.w8((f.sp+0x00000010u), 0x00000000u);
  }
  L00474d5d: { // 0x474d5d: 0fbf4506 MOVSX EAX,word ptr [EBP + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000006u)),16));
  }
  L00474d61: { // 0x474d61: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474d62: { // 0x474d62: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474d64: { // 0x474d64: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00474d68: { // 0x474d68: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00474d6a: { // 0x474d6a: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00474d70: { // 0x474d70: 0fbf4726 MOVSX EAX,word ptr [EDI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000026u)),16));
  }
  L00474d74: { // 0x474d74: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d77: { // 0x474d77: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00474d7c: { // 0x474d7c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00474d7e: { // 0x474d7e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474d7f: { // 0x474d7f: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474d81: { // 0x474d81: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00474d83: { // 0x474d83: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474d89: { // 0x474d89: 0fbf4f24 MOVSX ECX,word ptr [EDI + 0x24]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000024u)),16));
  }
  L00474d8d: { // 0x474d8d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474d8f: { // 0x474d8f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474d92: { // 0x474d92: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d95: { // 0x474d95: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d98: { // 0x474d98: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00474d9e: { // 0x474d9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474d9f: { // 0x474d9f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00474da1: { // 0x474da1: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00474da5: { // 0x474da5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474da6: { // 0x474da6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474dac: { // 0x474dac: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474dae: { // 0x474dae: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474db1: { // 0x474db1: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474db4: { // 0x474db4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474db5: { // 0x474db5: e87668faff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,4672954u); flags=s.arithmetic_flags;
  }
  L00474dba: { // 0x474dba: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00474dbe: { // 0x474dbe: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00474dc2: { // 0x474dc2: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00474dc6: { // 0x474dc6: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00474dca: { // 0x474dca: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00474dce: { // 0x474dce: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L00474dd2: { // 0x474dd2: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L00474dd6: { // 0x474dd6: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00474dda: { // 0x474dda: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00474de0: { // 0x474de0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474de1: { // 0x474de1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474de2: { // 0x474de2: e829322200 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,4672999u); flags=s.arithmetic_flags;
  }
  L00474de7: { // 0x474de7: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00474deb: { // 0x474deb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00474dec: { // 0x474dec: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00474dee: { // 0x474dee: e84d020000 CALL 0x00475040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475040u,4673011u); flags=s.arithmetic_flags;
  }
  L00474df3: { // 0x474df3: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00474df7: { // 0x474df7: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00474df9: { // 0x474df9: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00474dfb: { // 0x474dfb: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L00474dff: { // 0x474dff: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e03: { // 0x474e03: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00474e06: { // 0x474e06: 8a8740010000 MOV AL,byte ptr [EDI + 0x140]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000140u)));
  }
  L00474e0c: { // 0x474e0c: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00474e0e: { // 0x474e0e: 83e91e SUB ECX,0x1e
    s.cx = integer::sub(s.cx,0x0000001eu,32,flags);
  }
  L00474e11: { // 0x474e11: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00474e15: { // 0x474e15: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  L00474e17: { // 0x474e17: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e1b: { // 0x474e1b: 741c JZ 0x00474e39
    if(integer::condition("JZ",flags)) goto L00474e39;
  }
  L00474e1d: { // 0x474e1d: 8a871e010000 MOV AL,byte ptr [EDI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011eu)));
  }
  L00474e23: { // 0x474e23: 3c09 CMP AL,0x9
    (void)integer::sub((s.ax & 0xffu),0x00000009u,8,flags);
  }
  L00474e25: { // 0x474e25: 7212 JC 0x00474e39
    if(integer::condition("JC",flags)) goto L00474e39;
  }
  L00474e27: { // 0x474e27: 3c11 CMP AL,0x11
    (void)integer::sub((s.ax & 0xffu),0x00000011u,8,flags);
  }
  L00474e29: { // 0x474e29: 770e JA 0x00474e39
    if(integer::condition("JA",flags)) goto L00474e39;
  }
  L00474e2b: { // 0x474e2b: 83e90f SUB ECX,0xf
    s.cx = integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L00474e2e: { // 0x474e2e: 83c307 ADD EBX,0x7
    s.bx = integer::add(s.bx,0x00000007u,32,flags);
  }
  L00474e31: { // 0x474e31: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e35: { // 0x474e35: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00474e39: { // 0x474e39: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00474e3d: { // 0x474e3d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474e3e: { // 0x474e3e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474e40: { // 0x474e40: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474e42: { // 0x474e42: 0fbf4504 MOVSX EAX,word ptr [EBP + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000004u)),16));
  }
  L00474e46: { // 0x474e46: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474e47: { // 0x474e47: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474e49: { // 0x474e49: 0fbf5506 MOVSX EDX,word ptr [EBP + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000006u)),16));
  }
  L00474e4d: { // 0x474e4d: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474e4f: { // 0x474e4f: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474e51: { // 0x474e51: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00474e53: { // 0x474e53: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00474e55: { // 0x474e55: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00474e57: { // 0x474e57: 731e JNC 0x00474e77
    if(integer::condition("JNC",flags)) goto L00474e77;
  }
  L00474e59: { // 0x474e59: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00474e5c: { // 0x474e5c: 8d44c508 LEA EAX,[EBP + EAX*0x8 + 0x8]
    s.ax = (s.bp+(s.ax * 0x00000008u)+0x00000008u);
  }
  L00474e60: { // 0x474e60: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474e62: { // 0x474e62: 7413 JZ 0x00474e77
    if(integer::condition("JZ",flags)) goto L00474e77;
  }
  L00474e64: { // 0x474e64: 0fbf28 MOVSX EBP,word ptr [EAX]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00474e67: { // 0x474e67: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00474e6b: { // 0x474e6b: 0fbf7004 MOVSX ESI,word ptr [EAX + 0x4]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L00474e6f: { // 0x474e6f: 0fbf7806 MOVSX EDI,word ptr [EAX + 0x6]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L00474e73: { // 0x474e73: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00474e75: { // 0x474e75: eb17 JMP 0x00474e8e
    goto L00474e8e;
  }
  L00474e77: { // 0x474e77: a1008f8300 MOV EAX,[0x00838f00]
    s.ax = m.r32((0x00838f00u));
  }
  L00474e7c: { // 0x474e7c: 8b15048f8300 MOV EDX,dword ptr [0x00838f04]
    s.dx = m.r32((0x00838f04u));
  }
  L00474e82: { // 0x474e82: 8b35088f8300 MOV ESI,dword ptr [0x00838f08]
    s.si = m.r32((0x00838f08u));
  }
  L00474e88: { // 0x474e88: 8b3d0c8f8300 MOV EDI,dword ptr [0x00838f0c]
    s.di = m.r32((0x00838f0cu));
  }
  L00474e8e: { // 0x474e8e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00474e90: { // 0x474e90: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L00474e92: { // 0x474e92: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00474e96: { // 0x474e96: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474e98: { // 0x474e98: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L00474e9a: { // 0x474e9a: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00474e9d: { // 0x474e9d: 897308 MOV dword ptr [EBX + 0x8],ESI
    m.w32((s.bx+0x00000008u), s.si);
  }
  L00474ea0: { // 0x474ea0: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L00474ea3: { // 0x474ea3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474ea4: { // 0x474ea4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474ea5: { // 0x474ea5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474ea6: { // 0x474ea6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474ea7: { // 0x474ea7: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00474eaa: { // 0x474eaa: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0001b630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b630: { // 0x41b630: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0041b634: { // 0x41b634: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041b636: { // 0x41b636: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0041b63a: { // 0x41b63a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b63c: { // 0x41b63c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0041b640: { // 0x41b640: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0041b643: { // 0x41b643: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0041b646: { // 0x41b646: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00298010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698010: { // 0x698010: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00698013: { // 0x698013: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00698014: { // 0x698014: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00698018: { // 0x698018: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00698019: { // 0x698019: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069801a: { // 0x69801a: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L0069801c: { // 0x69801c: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L0069801f: { // 0x69801f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00698023: { // 0x698023: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00698025: { // 0x698025: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698028: { // 0x698028: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698029: { // 0x698029: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0069802d: { // 0x69802d: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00698030: { // 0x698030: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698033: { // 0x698033: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069803b: { // 0x69803b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069803e: { // 0x69803e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069803f: { // 0x69803f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698041: { // 0x698041: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698043: { // 0x698043: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698046: { // 0x698046: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698048: { // 0x698048: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069804b: { // 0x69804b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069804d: { // 0x69804d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069804e: { // 0x69804e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698050: { // 0x698050: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698052: { // 0x698052: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698054: { // 0x698054: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00698057: { // 0x698057: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00698059: { // 0x698059: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069805b: { // 0x69805b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069805e: { // 0x69805e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069805f: { // 0x69805f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698061: { // 0x698061: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698063: { // 0x698063: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00698065: { // 0x698065: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00698068: { // 0x698068: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069806a: { // 0x69806a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069806d: { // 0x69806d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00698071: { // 0x698071: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00698073: { // 0x698073: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698074: { // 0x698074: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698076: { // 0x698076: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0069807a: { // 0x69807a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069807c: { // 0x69807c: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069807e: { // 0x69807e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698080: { // 0x698080: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698081: { // 0x698081: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698087: { // 0x698087: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698089: { // 0x698089: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069808b: { // 0x69808b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069808d: { // 0x69808d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069808e: { // 0x69808e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698094: { // 0x698094: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698096: { // 0x698096: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698098: { // 0x698098: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809b: { // 0x69809b: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809e: { // 0x69809e: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L006980a4: { // 0x6980a4: 7c08 JL 0x006980ae
    if(integer::condition("JL",flags)) goto L006980ae;
  }
  L006980a6: { // 0x6980a6: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L006980ae: { // 0x6980ae: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006980b2: { // 0x6980b2: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L006980b8: { // 0x6980b8: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006980bc: { // 0x6980bc: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L006980c2: { // 0x6980c2: e889290d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914247u); flags=s.arithmetic_flags;
  }
  L006980c7: { // 0x6980c7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006980c9: { // 0x6980c9: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006980cd: { // 0x6980cd: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980cf: { // 0x6980cf: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980d2: { // 0x6980d2: 8b8db0000000 MOV ECX,dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L006980d8: { // 0x6980d8: 8badb4000000 MOV EBP,dword ptr [EBP + 0xb4]
    s.bp = m.r32((s.bp+0x000000b4u));
  }
  L006980de: { // 0x6980de: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L006980e0: { // 0x6980e0: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006980e3: { // 0x6980e3: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006980e5: { // 0x6980e5: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L006980e7: { // 0x6980e7: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980e9: { // 0x6980e9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006980eb: { // 0x6980eb: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980ee: { // 0x6980ee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006980f0: { // 0x6980f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006980f1: { // 0x6980f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006980f2: { // 0x6980f2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006980f3: { // 0x6980f3: 81f998feffff CMP ECX,0xfffffe98
    (void)integer::sub(s.cx,0xfffffe98u,32,flags);
  }
  L006980f9: { // 0x6980f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006980fa: { // 0x6980fa: 7d08 JGE 0x00698104
    if(integer::condition("JGE",flags)) goto L00698104;
  }
  L006980fc: { // 0x6980fc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006980fe: { // 0x6980fe: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698101: { // 0x698101: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00698104: { // 0x698104: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
  L0069810a: { // 0x69810a: 81c268010000 ADD EDX,0x168
    s.dx = integer::add(s.dx,0x00000168u,32,flags);
  }
  L00698110: { // 0x698110: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00698112: { // 0x698112: 7e08 JLE 0x0069811c
    if(integer::condition("JLE",flags)) goto L0069811c;
  }
  L00698114: { // 0x698114: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698116: { // 0x698116: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698119: { // 0x698119: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069811c: { // 0x69811c: 3d4cffffff CMP EAX,0xffffff4c
    (void)integer::sub(s.ax,0xffffff4cu,32,flags);
  }
  L00698121: { // 0x698121: 7d08 JGE 0x0069812b
    if(integer::condition("JGE",flags)) goto L0069812b;
  }
  L00698123: { // 0x698123: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698125: { // 0x698125: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698128: { // 0x698128: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069812b: { // 0x69812b: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L00698131: { // 0x698131: 81c1b4000000 ADD ECX,0xb4
    s.cx = integer::add(s.cx,0x000000b4u,32,flags);
  }
  L00698137: { // 0x698137: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00698139: { // 0x698139: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0069813c: { // 0x69813c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069813f: { // 0x69813f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00075040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00475040: { // 0x00475040: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00475043: { // 0x00475043: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00475044: { // 0x00475044: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00475046: { // 0x00475046: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L0047504a: { // 0x0047504a: 8b5644 MOV EDX,dword ptr [ESI + 0x44]
    s.dx = m.r32((s.si+0x00000044u));
  }
  L0047504d: { // 0x0047504d: e87ef61500 CALL 0x005d46d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d46d0u,4673618u); flags=s.arithmetic_flags;
  }
  L00475052: { // 0x00475052: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00475054: { // 0x00475054: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00475057: { // 0x00475057: 8a8640010000 MOV AL,byte ptr [ESI + 0x140]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000140u)));
  }
  L0047505d: { // 0x0047505d: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  L0047505f: { // 0x0047505f: 7413 JZ 0x00475074
    if(integer::condition("JZ",flags)) goto L00475074;
  }
  L00475061: { // 0x00475061: 8a861e010000 MOV AL,byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00475067: { // 0x00475067: 83e910 SUB ECX,0x10
    s.cx = integer::sub(s.cx,0x00000010u,32,flags);
  }
  L0047506a: { // 0x0047506a: 3c09 CMP AL,0x9
    (void)integer::sub((s.ax & 0xffu),0x00000009u,8,flags);
  }
  L0047506c: { // 0x0047506c: 7212 JC 0x00475080
    if(integer::condition("JC",flags)) goto L00475080;
  }
  L0047506e: { // 0x0047506e: 3c11 CMP AL,0x11
    (void)integer::sub((s.ax & 0xffu),0x00000011u,8,flags);
  }
  L00475070: { // 0x00475070: 770e JA 0x00475080
    if(integer::condition("JA",flags)) goto L00475080;
  }
  L00475072: { // 0x00475072: eb09 JMP 0x0047507d
    goto L0047507d;
  }
  L00475074: { // 0x00475074: 817e44ef000000 CMP dword ptr [ESI + 0x44],0xef
    (void)integer::sub(m.r32((s.si+0x00000044u)),0x000000efu,32,flags);
  }
  L0047507b: { // 0x0047507b: 7503 JNZ 0x00475080
    if(integer::condition("JNZ",flags)) goto L00475080;
  }
  L0047507d: { // 0x0047507d: 83e90f SUB ECX,0xf
    s.cx = integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L00475080: { // 0x00475080: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L00475087: { // 0x00475087: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  L0047508d: { // 0x0047508d: 83c21e ADD EDX,0x1e
    s.dx = integer::add(s.dx,0x0000001eu,32,flags);
  }
  L00475090: { // 0x00475090: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00475093: { // 0x00475093: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00475096: { // 0x00475096: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00475098: { // 0x00475098: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0047509c: { // 0x0047509c: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0047509e: { // 0x0047509e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047509f: { // 0x0047509f: 83c10f ADD ECX,0xf
    s.cx = integer::add(s.cx,0x0000000fu,32,flags);
  }
  L004750a2: { // 0x004750a2: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004750a4: { // 0x004750a4: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L004750a7: { // 0x004750a7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004750aa: { // 0x004750aa: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001d46d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d46d0: { // 0x5d46d0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005d46d2: { // 0x5d46d2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d46d3: { // 0x5d46d3: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L005d46d9: { // 0x5d46d9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d46da: { // 0x5d46da: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d46db: { // 0x5d46db: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005d46dd: { // 0x5d46dd: 8b3491 MOV ESI,dword ptr [ECX + EDX*0x4]
    s.si = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L005d46e0: { // 0x5d46e0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005d46e2: { // 0x5d46e2: 8a9e79020000 MOV BL,byte ptr [ESI + 0x279]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000279u)));
  }
  L005d46e8: { // 0x5d46e8: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005d46ea: { // 0x5d46ea: 751d JNZ 0x005d4709
    if(integer::condition("JNZ",flags)) goto L005d4709;
  }
  L005d46ec: { // 0x5d46ec: 8a9e78020000 MOV BL,byte ptr [ESI + 0x278]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000278u)));
  }
  L005d46f2: { // 0x5d46f2: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005d46f4: { // 0x5d46f4: 7513 JNZ 0x005d4709
    if(integer::condition("JNZ",flags)) goto L005d4709;
  }
  L005d46f6: { // 0x5d46f6: 83be640200007e CMP dword ptr [ESI + 0x264],0x7e
    (void)integer::sub(m.r32((s.si+0x00000264u)),0x0000007eu,32,flags);
  }
  L005d46fd: { // 0x5d46fd: 740a JZ 0x005d4709
    if(integer::condition("JZ",flags)) goto L005d4709;
  }
  L005d46ff: { // 0x5d46ff: 8a9e7a020000 MOV BL,byte ptr [ESI + 0x27a]
    s.bx = with_al(s.bx, m.r8((s.si+0x0000027au)));
  }
  L005d4705: { // 0x5d4705: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005d4707: { // 0x5d4707: 7405 JZ 0x005d470e
    if(integer::condition("JZ",flags)) goto L005d470e;
  }
  L005d4709: { // 0x5d4709: b9f4ffffff MOV ECX,0xfffffff4
    s.cx = 0xfffffff4u;
  }
  L005d470e: { // 0x5d470e: 83be6802000009 CMP dword ptr [ESI + 0x268],0x9
    (void)integer::sub(m.r32((s.si+0x00000268u)),0x00000009u,32,flags);
  }
  L005d4715: { // 0x5d4715: 7501 JNZ 0x005d4718
    if(integer::condition("JNZ",flags)) goto L005d4718;
  }
  L005d4717: { // 0x5d4717: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005d4718: { // 0x5d4718: 83fa7e CMP EDX,0x7e
    (void)integer::sub(s.dx,0x0000007eu,32,flags);
  }
  L005d471b: { // 0x5d471b: 7501 JNZ 0x005d471e
    if(integer::condition("JNZ",flags)) goto L005d471e;
  }
  L005d471d: { // 0x5d471d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005d471e: { // 0x5d471e: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L005d4720: { // 0x5d4720: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d4721: { // 0x5d4721: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d4722: { // 0x5d4722: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L005d4725: { // 0x5d4725: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d4726: { // 0x5d4726: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001d57d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d57d0: { // 0x5d57d0: 81ec64020000 SUB ESP, 0x264
    f.sp = integer::sub(f.sp,0x00000264u,32,flags);
  }
  L005d57d6: { // 0x5d57d6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d57d7: { // 0x5d57d7: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005d57d9: { // 0x5d57d9: 8b86a4000000 MOV EAX, dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L005d57df: { // 0x5d57df: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d57e1: { // 0x5d57e1: 0f85f0000000 JNZ 0x5d58d7
    if(integer::condition("JNZ",flags)) goto L005d58d7;
  }
  L005d57e7: { // 0x5d57e7: 8a8e7f020000 MOV CL, byte ptr [ESI + 0x27f]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000027fu)));
  }
  L005d57ed: { // 0x5d57ed: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005d57ef: { // 0x5d57ef: 0f84e2000000 JZ 0x5d58d7
    if(integer::condition("JZ",flags)) goto L005d58d7;
  }
  L005d57f5: { // 0x5d57f5: 8d4664 LEA EAX, [ESI + 0x64]
    s.ax = (s.si+0x00000064u);
  }
  L005d57f8: { // 0x5d57f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d57f9: { // 0x5d57f9: 68a49f7b00 PUSH 0x7b9fa4
    f.push(m,0x007b9fa4u);
  }
  L005d57fe: { // 0x5d57fe: e8ed10e3ff CALL 0x4068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,6117379u); flags=s.arithmetic_flags;
  }
  L005d5803: { // 0x5d5803: 8a86fc010000 MOV AL, byte ptr [ESI + 0x1fc]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fcu)));
  }
  L005d5809: { // 0x5d5809: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005d580c: { // 0x5d580c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d580e: { // 0x5d580e: 7434 JZ 0x5d5844
    if(integer::condition("JZ",flags)) goto L005d5844;
  }
  L005d5810: { // 0x5d5810: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L005d5816: { // 0x5d5816: 8b8138080000 MOV EAX, dword ptr [ECX + 0x838]
    s.ax = m.r32((s.cx+0x00000838u));
  }
  L005d581c: { // 0x5d581c: 8d1440 LEA EDX, [EAX + EAX*2]
    s.dx = (s.ax+(s.ax * 2u));
  }
  L005d581f: { // 0x5d581f: 8d0490 LEA EAX, [EAX + EDX*4]
    s.ax = (s.ax+(s.dx * 4u));
  }
  L005d5822: { // 0x5d5822: 8d96c8010000 LEA EDX, [ESI + 0x1c8]
    s.dx = (s.si+0x000001c8u);
  }
  L005d5828: { // 0x5d5828: 8d0cc5ac5b7800 LEA ECX, [EAX*8 + 0x785bac]
    s.cx = ((s.ax * 8u)+0x00785bacu);
  }
  L005d582f: { // 0x5d582f: 8d442468 LEA EAX, [ESP + 0x68]
    s.ax = (f.sp+0x00000068u);
  }
  L005d5833: { // 0x5d5833: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5834: { // 0x5d5834: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d5835: { // 0x5d5835: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5837: { // 0x5d5837: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5839: { // 0x5d5839: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d583a: { // 0x5d583a: e8f1921900 CALL 0x76eb30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076eb30u,6117439u); flags=s.arithmetic_flags;
  }
  L005d583f: { // 0x5d583f: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005d5842: { // 0x5d5842: eb3b JMP 0x5d587f
    goto L005d587f;
  }
  L005d5844: { // 0x5d5844: 8a8607020000 MOV AL, byte ptr [ESI + 0x207]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000207u)));
  }
  L005d584a: { // 0x5d584a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d584c: { // 0x5d584c: 7431 JZ 0x5d587f
    if(integer::condition("JZ",flags)) goto L005d587f;
  }
  L005d584e: { // 0x5d584e: 8d8ec8010000 LEA ECX, [ESI + 0x1c8]
    s.cx = (s.si+0x000001c8u);
  }
  L005d5854: { // 0x5d5854: 68a49c7b00 PUSH 0x7b9ca4
    f.push(m,0x007b9ca4u);
  }
  L005d5859: { // 0x5d5859: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d585a: { // 0x5d585a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d585c: { // 0x5d585c: 8d542474 LEA EDX, [ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L005d5860: { // 0x5d5860: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5862: { // 0x5d5862: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d5863: { // 0x5d5863: e8c8921900 CALL 0x76eb30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076eb30u,6117480u); flags=s.arithmetic_flags;
  }
  L005d5868: { // 0x5d5868: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L005d586d: { // 0x5d586d: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005d5870: { // 0x5d5870: 8d4c2468 LEA ECX, [ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L005d5874: { // 0x5d5874: 8b9038080000 MOV EDX, dword ptr [EAX + 0x838]
    s.dx = m.r32((s.ax+0x00000838u));
  }
  L005d587a: { // 0x5d587a: e8e1a9ffff CALL 0x5d0260
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d0260u,6117503u); flags=s.arithmetic_flags;
  }
  L005d587f: { // 0x5d587f: 8d4c2468 LEA ECX, [ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L005d5883: { // 0x5d5883: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d5884: { // 0x5d5884: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5885: { // 0x5d5885: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L005d5889: { // 0x5d5889: e8e232e9ff CALL 0x468b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468b70u,6117518u); flags=s.arithmetic_flags;
  }
  L005d588e: { // 0x5d588e: 8d4c2408 LEA ECX, [ESP + 8]
    s.cx = (f.sp+8u);
  }
  L005d5892: { // 0x5d5892: e879f7ebff CALL 0x495010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00495010u,6117527u); flags=s.arithmetic_flags;
  }
  L005d5897: { // 0x5d5897: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L005d5899: { // 0x5d5899: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005d589b: { // 0x5d589b: 89bea4000000 MOV dword ptr [ESI + 0xa4], EDI
    m.w32((s.si+0x000000a4u), s.di);
  }
  L005d58a1: { // 0x5d58a1: 7407 JZ 0x5d58aa
    if(integer::condition("JZ",flags)) goto L005d58aa;
  }
  L005d58a3: { // 0x5d58a3: c686a800000001 MOV byte ptr [ESI + 0xa8], 1
    m.w8((s.si+0x000000a8u), 1u);
  }
  L005d58aa: { // 0x5d58aa: 8d4c245c LEA ECX, [ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L005d58ae: { // 0x5d58ae: c7442408a0567800 MOV dword ptr [ESP + 8], 0x7856a0
    m.w32((f.sp+8u), 0x007856a0u);
  }
  L005d58b6: { // 0x5d58b6: c744246800000000 MOV dword ptr [ESP + 0x68], 0
    m.w32((f.sp+0x00000068u), 0u);
  }
  L005d58be: { // 0x5d58be: e8cd29e6ff CALL 0x438290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,6117571u); flags=s.arithmetic_flags;
  }
  L005d58c3: { // 0x5d58c3: 8d4c2408 LEA ECX, [ESP + 8]
    s.cx = (f.sp+8u);
  }
  L005d58c7: { // 0x5d58c7: c744240858567800 MOV dword ptr [ESP + 8], 0x785658
    m.w32((f.sp+8u), 0x00785658u);
  }
  L005d58cf: { // 0x5d58cf: e87c99e5ff CALL 0x42f250
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042f250u,6117588u); flags=s.arithmetic_flags;
  }
  L005d58d4: { // 0x5d58d4: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L005d58d6: { // 0x5d58d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d58d7: { // 0x5d58d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d58d8: { // 0x5d58d8: 81c464020000 ADD ESP, 0x264
    f.sp = integer::add(f.sp,0x00000264u,32,flags);
  }
  L005d58de: { // 0x5d58de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00074ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00474ab0: { // 0x474ab0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00474ab3: { // 0x474ab3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00474ab4: { // 0x474ab4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00474ab5: { // 0x474ab5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00474ab6: { // 0x474ab6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00474ab8: { // 0x474ab8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00474ab9: { // 0x474ab9: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  L00474abc: { // 0x474abc: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L00474abf: { // 0x474abf: 0f8485010000 JZ 0x00474c4a
    if(integer::condition("JZ",flags)) goto L00474c4a;
  }
  L00474ac5: { // 0x474ac5: 8b151ce1a100 MOV EDX,dword ptr [0x00a1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00474acb: { // 0x474acb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00474acd: { // 0x474acd: 8a861e010000 MOV AL,byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00474ad3: { // 0x474ad3: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00474ad7: { // 0x474ad7: 8b2c8a MOV EBP,dword ptr [EDX + ECX*0x4]
    s.bp = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L00474ada: { // 0x474ada: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00474adc: { // 0x474adc: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474ae0: { // 0x474ae0: 8a9579020000 MOV DL,byte ptr [EBP + 0x279]
    s.dx = with_al(s.dx, m.r8((s.bp+0x00000279u)));
  }
  L00474ae6: { // 0x474ae6: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00474ae8: { // 0x474ae8: 0f8495000000 JZ 0x00474b83
    if(integer::condition("JZ",flags)) goto L00474b83;
  }
  L00474aee: { // 0x474aee: e83dfc1500 CALL 0x005d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4672243u); flags=s.arithmetic_flags;
  }
  L00474af3: { // 0x474af3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00474af6: { // 0x474af6: 0f84bc000000 JZ 0x00474bb8
    if(integer::condition("JZ",flags)) goto L00474bb8;
  }
  L00474afc: { // 0x474afc: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L00474b02: { // 0x474b02: 8b3c81 MOV EDI,dword ptr [ECX + EAX*0x4]
    s.di = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00474b05: { // 0x474b05: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L00474b0b: { // 0x474b0b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00474b0d: { // 0x474b0d: 7443 JZ 0x00474b52
    if(integer::condition("JZ",flags)) goto L00474b52;
  }
  L00474b0f: { // 0x474b0f: 8b87ec000000 MOV EAX,dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  L00474b15: { // 0x474b15: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00474b1b: { // 0x474b1b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b1c: { // 0x474b1c: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L00474b1f: { // 0x474b1f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474b21: { // 0x474b21: 0fbf5624 MOVSX EDX,word ptr [ESI + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474b25: { // 0x474b25: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474b27: { // 0x474b27: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474b2b: { // 0x474b2b: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00474b2e: { // 0x474b2e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b2f: { // 0x474b2f: c1fb02 SAR EBX,0x2
    s.bx = integer::shift(s.bx,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474b32: { // 0x474b32: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00474b34: { // 0x474b34: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00474b35: { // 0x474b35: 8b87e0000000 MOV EAX,dword ptr [EDI + 0xe0]
    s.ax = m.r32((s.di+0x000000e0u));
  }
  L00474b3b: { // 0x474b3b: 0fafcb IMUL ECX,EBX
    s.cx = integer::imul(s.cx,s.bx,32,flags);
  }
  L00474b3e: { // 0x474b3e: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00474b40: { // 0x474b40: 8b8864020000 MOV ECX,dword ptr [EAX + 0x264]
    s.cx = m.r32((s.ax+0x00000264u));
  }
  L00474b46: { // 0x474b46: 8b87e8000000 MOV EAX,dword ptr [EDI + 0xe8]
    s.ax = m.r32((s.di+0x000000e8u));
  }
  L00474b4c: { // 0x474b4c: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00474b4e: { // 0x474b4e: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00474b50: { // 0x474b50: eb1e JMP 0x00474b70
    goto L00474b70;
  }
  L00474b52: { // 0x474b52: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474b56: { // 0x474b56: 0fbf4e24 MOVSX ECX,word ptr [ESI + 0x24]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474b5a: { // 0x474b5a: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00474b5d: { // 0x474b5d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b5e: { // 0x474b5e: f7bfe8000000 IDIV dword ptr [EDI + 0xe8]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.di+0x000000e8u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00474b64: { // 0x474b64: 8b87e0000000 MOV EAX,dword ptr [EDI + 0xe0]
    s.ax = m.r32((s.di+0x000000e0u));
  }
  L00474b6a: { // 0x474b6a: 039064020000 ADD EDX,dword ptr [EAX + 0x264]
    s.dx = integer::add(s.dx,m.r32((s.ax+0x00000264u)),32,flags);
  }
  L00474b70: { // 0x474b70: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00474b76: { // 0x474b76: 8b0c91 MOV ECX,dword ptr [ECX + EDX*0x4]
    s.cx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L00474b79: { // 0x474b79: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00474b7b: { // 0x474b7b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4672385u); flags=s.arithmetic_flags;
  }
  L00474b81: { // 0x474b81: eb31 JMP 0x00474bb4
    goto L00474bb4;
  }
  L00474b83: { // 0x474b83: 8a8d84020000 MOV CL,byte ptr [EBP + 0x284]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000284u)));
  }
  L00474b89: { // 0x474b89: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00474b8b: { // 0x474b8b: 741c JZ 0x00474ba9
    if(integer::condition("JZ",flags)) goto L00474ba9;
  }
  L00474b8d: { // 0x474b8d: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  L00474b90: { // 0x474b90: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474b94: { // 0x474b94: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00474b96: { // 0x474b96: 7420 JZ 0x00474bb8
    if(integer::condition("JZ",flags)) goto L00474bb8;
  }
  L00474b98: { // 0x474b98: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00474b9c: { // 0x474b9c: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L00474ba0: { // 0x474ba0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474ba1: { // 0x474ba1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474ba2: { // 0x474ba2: e8d93efeff CALL 0x00458a80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00458a80u,4672423u); flags=s.arithmetic_flags;
  }
  L00474ba7: { // 0x474ba7: eb0f JMP 0x00474bb8
    goto L00474bb8;
  }
  L00474ba9: { // 0x474ba9: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00474bac: { // 0x474bac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00474bae: { // 0x474bae: ff909c000000 CALL dword ptr [EAX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000009cu)),4672436u); flags=s.arithmetic_flags;
  }
  L00474bb4: { // 0x474bb4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474bb8: { // 0x474bb8: 0fbf4624 MOVSX EAX,word ptr [ESI + 0x24]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474bbc: { // 0x474bbc: 0fbf4e26 MOVSX ECX,word ptr [ESI + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474bc0: { // 0x474bc0: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bc3: { // 0x474bc3: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00474bc8: { // 0x474bc8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474bc9: { // 0x474bc9: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474bcf: { // 0x474bcf: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bd2: { // 0x474bd2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474bd4: { // 0x474bd4: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00474bda: { // 0x474bda: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474bdc: { // 0x474bdc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00474bde: { // 0x474bde: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474bdf: { // 0x474bdf: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474be5: { // 0x474be5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474be7: { // 0x474be7: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474be9: { // 0x474be9: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00474bed: { // 0x474bed: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474bf0: { // 0x474bf0: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474bf3: { // 0x474bf3: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00474bf7: { // 0x474bf7: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00474bfb: { // 0x474bfb: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bfe: { // 0x474bfe: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474c01: { // 0x474c01: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00474c02: { // 0x474c02: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00474c08: { // 0x474c08: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474c09: { // 0x474c09: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L00474c0d: { // 0x474c0d: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00474c11: { // 0x474c11: e8fa332200 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,4672534u); flags=s.arithmetic_flags;
  }
  L00474c16: { // 0x474c16: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00474c1a: { // 0x474c1a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00474c1c: { // 0x474c1c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474c1d: { // 0x474c1d: e81e040000 CALL 0x00475040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475040u,4672546u); flags=s.arithmetic_flags;
  }
  L00474c22: { // 0x474c22: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00474c26: { // 0x474c26: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00474c28: { // 0x474c28: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00474c2c: { // 0x474c2c: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00474c2e: { // 0x474c2e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00474c32: { // 0x474c32: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00474c35: { // 0x474c35: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00474c37: { // 0x474c37: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00474c3b: { // 0x474c3b: 83e91e SUB ECX,0x1e
    s.cx = integer::sub(s.cx,0x0000001eu,32,flags);
  }
  L00474c3e: { // 0x474c3e: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L00474c42: { // 0x474c42: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00474c44: { // 0x474c44: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00474c48: { // 0x474c48: 7523 JNZ 0x00474c6d
    if(integer::condition("JNZ",flags)) goto L00474c6d;
  }
  L00474c4a: { // 0x474c4a: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00474c4e: { // 0x474c4e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474c50: { // 0x474c50: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474c52: { // 0x474c52: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474c54: { // 0x474c54: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474c56: { // 0x474c56: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474c58: { // 0x474c58: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L00474c5a: { // 0x474c5a: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00474c5d: { // 0x474c5d: 897308 MOV dword ptr [EBX + 0x8],ESI
    m.w32((s.bx+0x00000008u), s.si);
  }
  L00474c60: { // 0x474c60: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L00474c63: { // 0x474c63: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474c64: { // 0x474c64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474c65: { // 0x474c65: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474c66: { // 0x474c66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474c67: { // 0x474c67: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00474c6a: { // 0x474c6a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00474c6d: { // 0x474c6d: 8a857a020000 MOV AL,byte ptr [EBP + 0x27a]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000027au)));
  }
  L00474c73: { // 0x474c73: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00474c75: { // 0x474c75: 7408 JZ 0x00474c7f
    if(integer::condition("JZ",flags)) goto L00474c7f;
  }
  L00474c77: { // 0x474c77: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00474c79: { // 0x474c79: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00474c7d: { // 0x474c7d: eb04 JMP 0x00474c83
    goto L00474c83;
  }
  L00474c7f: { // 0x474c7f: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00474c83: { // 0x474c83: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00474c87: { // 0x474c87: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474c88: { // 0x474c88: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474c8a: { // 0x474c8a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474c8c: { // 0x474c8c: 0fbf4704 MOVSX EAX,word ptr [EDI + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L00474c90: { // 0x474c90: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474c91: { // 0x474c91: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474c93: { // 0x474c93: 0fbf5706 MOVSX EDX,word ptr [EDI + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000006u)),16));
  }
  L00474c97: { // 0x474c97: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474c99: { // 0x474c99: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474c9b: { // 0x474c9b: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00474c9d: { // 0x474c9d: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00474c9f: { // 0x474c9f: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00474ca1: { // 0x474ca1: 731f JNC 0x00474cc2
    if(integer::condition("JNC",flags)) goto L00474cc2;
  }
  L00474ca3: { // 0x474ca3: 8d446d00 LEA EAX,[EBP + EBP*0x2]
    s.ax = (s.bp+(s.bp * 0x00000002u));
  }
  L00474ca7: { // 0x474ca7: 8d44c708 LEA EAX,[EDI + EAX*0x8 + 0x8]
    s.ax = (s.di+(s.ax * 0x00000008u)+0x00000008u);
  }
  L00474cab: { // 0x474cab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474cad: { // 0x474cad: 7413 JZ 0x00474cc2
    if(integer::condition("JZ",flags)) goto L00474cc2;
  }
  L00474caf: { // 0x474caf: 0fbf28 MOVSX EBP,word ptr [EAX]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00474cb2: { // 0x474cb2: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00474cb6: { // 0x474cb6: 0fbf7804 MOVSX EDI,word ptr [EAX + 0x4]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L00474cba: { // 0x474cba: 0fbf5806 MOVSX EBX,word ptr [EAX + 0x6]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L00474cbe: { // 0x474cbe: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00474cc0: { // 0x474cc0: eb17 JMP 0x00474cd9
    goto L00474cd9;
  }
  L00474cc2: { // 0x474cc2: a1008f8300 MOV EAX,[0x00838f00]
    s.ax = m.r32((0x00838f00u));
  }
  L00474cc7: { // 0x474cc7: 8b15048f8300 MOV EDX,dword ptr [0x00838f04]
    s.dx = m.r32((0x00838f04u));
  }
  L00474ccd: { // 0x474ccd: 8b3d088f8300 MOV EDI,dword ptr [0x00838f08]
    s.di = m.r32((0x00838f08u));
  }
  L00474cd3: { // 0x474cd3: 8b1d0c8f8300 MOV EBX,dword ptr [0x00838f0c]
    s.bx = m.r32((0x00838f0cu));
  }
  L00474cd9: { // 0x474cd9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00474cdb: { // 0x474cdb: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00474cdf: { // 0x474cdf: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00474ce1: { // 0x474ce1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00474ce3: { // 0x474ce3: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L00474ce5: { // 0x474ce5: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L00474ce8: { // 0x474ce8: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00474ceb: { // 0x474ceb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474cec: { // 0x474cec: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  L00474cef: { // 0x474cef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474cf0: { // 0x474cf0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474cf1: { // 0x474cf1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474cf2: { // 0x474cf2: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00474cf5: { // 0x474cf5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001d4730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d4730: { // 0x5d4730: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d4731: { // 0x5d4731: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d4732: { // 0x5d4732: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005d4733: { // 0x5d4733: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d4734: { // 0x5d4734: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L005d4737: { // 0x5d4737: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d4738: { // 0x5d4738: 0f84a7000000 JZ 0x005d47e5
    if(integer::condition("JZ",flags)) goto L005d47e5;
  }
  L005d473e: { // 0x5d473e: a11ce1a100 MOV EAX,[0x00a1e11c]
    s.ax = m.r32((0x00a1e11cu));
  }
  L005d4743: { // 0x5d4743: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L005d4746: { // 0x5d4746: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005d474a: { // 0x5d474a: 8a9079020000 MOV DL,byte ptr [EAX + 0x279]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000279u)));
  }
  L005d4750: { // 0x5d4750: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005d4752: { // 0x5d4752: 0f848d000000 JZ 0x005d47e5
    if(integer::condition("JZ",flags)) goto L005d47e5;
  }
  L005d4758: { // 0x5d4758: 8b154886aa00 MOV EDX,dword ptr [0x00aa8648]
    s.dx = m.r32((0x00aa8648u));
  }
  L005d475e: { // 0x5d475e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005d4760: { // 0x5d4760: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005d4762: { // 0x5d4762: 7e50 JLE 0x005d47b4
    if(integer::condition("JLE",flags)) goto L005d47b4;
  }
  L005d4764: { // 0x5d4764: 8b3d3c86aa00 MOV EDI,dword ptr [0x00aa863c]
    s.di = m.r32((0x00aa863cu));
  }
  L005d476a: { // 0x5d476a: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005d476c: { // 0x5d476c: 8b90e0000000 MOV EDX,dword ptr [EAX + 0xe0]
    s.dx = m.r32((s.ax+0x000000e0u));
  }
  L005d4772: { // 0x5d4772: 8b9264020000 MOV EDX,dword ptr [EDX + 0x264]
    s.dx = m.r32((s.dx+0x00000264u));
  }
  L005d4778: { // 0x5d4778: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005d477a: { // 0x5d477a: 7c0c JL 0x005d4788
    if(integer::condition("JL",flags)) goto L005d4788;
  }
  L005d477c: { // 0x5d477c: 8bb0e8000000 MOV ESI,dword ptr [EAX + 0xe8]
    s.si = m.r32((s.ax+0x000000e8u));
  }
  L005d4782: { // 0x5d4782: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L005d4784: { // 0x5d4784: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L005d4786: { // 0x5d4786: 7c51 JL 0x005d47d9
    if(integer::condition("JL",flags)) goto L005d47d9;
  }
  L005d4788: { // 0x5d4788: 8bb0e8000000 MOV ESI,dword ptr [EAX + 0xe8]
    s.si = m.r32((s.ax+0x000000e8u));
  }
  L005d478e: { // 0x5d478e: 8d2c16 LEA EBP,[ESI + EDX*0x1]
    s.bp = (s.si+(s.dx * 0x00000001u));
  }
  L005d4791: { // 0x5d4791: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L005d4793: { // 0x5d4793: 7c0e JL 0x005d47a3
    if(integer::condition("JL",flags)) goto L005d47a3;
  }
  L005d4795: { // 0x5d4795: 8ba8ec000000 MOV EBP,dword ptr [EAX + 0xec]
    s.bp = m.r32((s.ax+0x000000ecu));
  }
  L005d479b: { // 0x5d479b: 03ee ADD EBP,ESI
    s.bp = integer::add(s.bp,s.si,32,flags);
  }
  L005d479d: { // 0x5d479d: 03ea ADD EBP,EDX
    s.bp = integer::add(s.bp,s.dx,32,flags);
  }
  L005d479f: { // 0x5d479f: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L005d47a1: { // 0x5d47a1: 7c36 JL 0x005d47d9
    if(integer::condition("JL",flags)) goto L005d47d9;
  }
  L005d47a3: { // 0x5d47a3: a14886aa00 MOV EAX,[0x00aa8648]
    s.ax = m.r32((0x00aa8648u));
  }
  L005d47a8: { // 0x5d47a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005d47a9: { // 0x5d47a9: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L005d47ac: { // 0x5d47ac: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005d47ae: { // 0x5d47ae: 7cba JL 0x005d476a
    if(integer::condition("JL",flags)) goto L005d476a;
  }
  L005d47b0: { // 0x5d47b0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005d47b4: { // 0x5d47b4: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L005d47b7: { // 0x5d47b7: 8d7064 LEA ESI,[EAX + 0x64]
    s.si = (s.ax+0x00000064u);
  }
  L005d47ba: { // 0x5d47ba: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L005d47bf: { // 0x5d47bf: 8bfc MOV EDI,ESP
    s.di = f.sp;
  }
  L005d47c1: { // 0x5d47c1: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005d47c3: { // 0x5d47c3: 68c82c7d00 PUSH 0x7d2cc8
    f.push(m,0x007d2cc8u);
  }
  L005d47c8: { // 0x5d47c8: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005d47c9: { // 0x5d47c9: e82221e3ff CALL 0x004068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,6113230u); flags=s.arithmetic_flags;
  }
  L005d47ce: { // 0x5d47ce: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  L005d47d1: { // 0x5d47d1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005d47d3: { // 0x5d47d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d47d4: { // 0x5d47d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d47d5: { // 0x5d47d5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005d47d6: { // 0x5d47d6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d47d7: { // 0x5d47d7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d47d8: { // 0x5d47d8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005d47d9: { // 0x5d47d9: 8b8098000000 MOV EAX,dword ptr [EAX + 0x98]
    s.ax = m.r32((s.ax+0x00000098u));
  }
  L005d47df: { // 0x5d47df: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d47e0: { // 0x5d47e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d47e1: { // 0x5d47e1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005d47e2: { // 0x5d47e2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d47e3: { // 0x5d47e3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d47e4: { // 0x5d47e4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005d47e5: { // 0x5d47e5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d47e6: { // 0x5d47e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d47e7: { // 0x5d47e7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005d47e8: { // 0x5d47e8: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005d47eb: { // 0x5d47eb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d47ec: { // 0x5d47ec: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d47ed: { // 0x5d47ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00298660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698660: { // 0x698660: 83ec58 SUB ESP,0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L00698663: { // 0x698663: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L00698669: { // 0x698669: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069866a: { // 0x69866a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069866c: { // 0x69866c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069866d: { // 0x69866d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069866e: { // 0x69866e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00698670: { // 0x698670: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698671: { // 0x698671: c7442418ffffffff MOV dword ptr [ESP + 0x18],0xffffffff
    m.w32((f.sp+0x00000018u), 0xffffffffu);
  }
  L00698679: { // 0x698679: c744241cffffff7f MOV dword ptr [ESP + 0x1c],0x7fffffff
    m.w32((f.sp+0x0000001cu), 0x7fffffffu);
  }
  L00698681: { // 0x698681: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00698685: { // 0x698685: 0f8e6d020000 JLE 0x006988f8
    if(integer::condition("JLE",flags)) goto L006988f8;
  }
  L0069868b: { // 0x69868b: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0069868f: { // 0x69868f: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L00698694: { // 0x698694: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00698698: { // 0x698698: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069869a: { // 0x69869a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069869c: { // 0x69869c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069869e: { // 0x69869e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006986a0: { // 0x6986a0: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L006986a4: { // 0x6986a4: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006986a7: { // 0x6986a7: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L006986ab: { // 0x6986ab: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006986ae: { // 0x6986ae: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L006986b2: { // 0x6986b2: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L006986b6: { // 0x6986b6: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L006986b9: { // 0x6986b9: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L006986bd: { // 0x6986bd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006986be: { // 0x6986be: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L006986c2: { // 0x6986c2: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L006986c6: { // 0x6986c6: e82577d8ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6915787u); flags=s.arithmetic_flags;
  }
  L006986cb: { // 0x6986cb: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006986cd: { // 0x6986cd: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L006986d1: { // 0x6986d1: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L006986d5: { // 0x6986d5: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L006986d9: { // 0x6986d9: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L006986dc: { // 0x6986dc: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006986e0: { // 0x6986e0: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L006986e4: { // 0x6986e4: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006986e7: { // 0x6986e7: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L006986eb: { // 0x6986eb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L006986ef: { // 0x6986ef: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L006986f2: { // 0x6986f2: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006986f4: { // 0x6986f4: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L006986f8: { // 0x6986f8: 0f8e92000000 JLE 0x00698790
    if(integer::condition("JLE",flags)) goto L00698790;
  }
  L006986fe: { // 0x6986fe: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00698700: { // 0x698700: 0f8e8a000000 JLE 0x00698790
    if(integer::condition("JLE",flags)) goto L00698790;
  }
  L00698706: { // 0x698706: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L0069870a: { // 0x69870a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0069870c: { // 0x69870c: 7e74 JLE 0x00698782
    if(integer::condition("JLE",flags)) goto L00698782;
  }
  L0069870e: { // 0x69870e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00698712: { // 0x698712: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698714: { // 0x698714: 7e6c JLE 0x00698782
    if(integer::condition("JLE",flags)) goto L00698782;
  }
  L00698716: { // 0x698716: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L00698718: { // 0x698718: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    s.bp = m.r32((f.sp+0x0000006cu));
  }
  L0069871c: { // 0x69871c: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L0069871e: { // 0x69871e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698720: { // 0x698720: 7e06 JLE 0x00698728
    if(integer::condition("JLE",flags)) goto L00698728;
  }
  L00698722: { // 0x698722: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00698724: { // 0x698724: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698726: { // 0x698726: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00698728: { // 0x698728: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L0069872c: { // 0x69872c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069872e: { // 0x69872e: 7e06 JLE 0x00698736
    if(integer::condition("JLE",flags)) goto L00698736;
  }
  L00698730: { // 0x698730: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00698732: { // 0x698732: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00698734: { // 0x698734: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00698736: { // 0x698736: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0069873a: { // 0x69873a: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069873c: { // 0x69873c: 8d2c10 LEA EBP,[EAX + EDX*0x1]
    s.bp = (s.ax+(s.dx * 0x00000001u));
  }
  L0069873f: { // 0x69873f: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00698741: { // 0x698741: 7d0e JGE 0x00698751
    if(integer::condition("JGE",flags)) goto L00698751;
  }
  L00698743: { // 0x698743: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00698747: { // 0x698747: 8b5c246c MOV EBX,dword ptr [ESP + 0x6c]
    s.bx = m.r32((f.sp+0x0000006cu));
  }
  L0069874b: { // 0x69874b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069874d: { // 0x69874d: 8d441801 LEA EAX,[EAX + EBX*0x1 + 0x1]
    s.ax = (s.ax+(s.bx * 0x00000001u)+0x00000001u);
  }
  L00698751: { // 0x698751: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L00698755: { // 0x698755: 8b6c2478 MOV EBP,dword ptr [ESP + 0x78]
    s.bp = m.r32((f.sp+0x00000078u));
  }
  L00698759: { // 0x698759: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069875b: { // 0x69875b: 8d2c0e LEA EBP,[ESI + ECX*0x1]
    s.bp = (s.si+(s.cx * 0x00000001u));
  }
  L0069875e: { // 0x69875e: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00698760: { // 0x698760: 7d0e JGE 0x00698770
    if(integer::condition("JGE",flags)) goto L00698770;
  }
  L00698762: { // 0x698762: 8b742470 MOV ESI,dword ptr [ESP + 0x70]
    s.si = m.r32((f.sp+0x00000070u));
  }
  L00698766: { // 0x698766: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L0069876a: { // 0x69876a: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0069876c: { // 0x69876c: 8d741e01 LEA ESI,[ESI + EBX*0x1 + 0x1]
    s.si = (s.si+(s.bx * 0x00000001u)+0x00000001u);
  }
  L00698770: { // 0x698770: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L00698774: { // 0x698774: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00698778: { // 0x698778: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069877c: { // 0x69877c: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00698780: { // 0x698780: eb26 JMP 0x006987a8
    goto L006987a8;
  }
  L00698782: { // 0x698782: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00698786: { // 0x698786: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0069878a: { // 0x69878a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069878c: { // 0x69878c: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0069878e: { // 0x69878e: eb18 JMP 0x006987a8
    goto L006987a8;
  }
  L00698790: { // 0x698790: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00698794: { // 0x698794: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00698798: { // 0x698798: 8b742478 MOV ESI,dword ptr [ESP + 0x78]
    s.si = m.r32((f.sp+0x00000078u));
  }
  L0069879c: { // 0x69879c: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L006987a0: { // 0x6987a0: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L006987a4: { // 0x6987a4: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006987a8: { // 0x6987a8: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006987ac: { // 0x6987ac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006987ae: { // 0x6987ae: 0f8e15010000 JLE 0x006988c9
    if(integer::condition("JLE",flags)) goto L006988c9;
  }
  L006987b4: { // 0x6987b4: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006987b8: { // 0x6987b8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006987ba: { // 0x6987ba: 0f8e09010000 JLE 0x006988c9
    if(integer::condition("JLE",flags)) goto L006988c9;
  }
  L006987c0: { // 0x6987c0: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L006987c4: { // 0x6987c4: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L006987c8: { // 0x6987c8: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L006987ca: { // 0x6987ca: 754b JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987cc: { // 0x6987cc: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L006987d0: { // 0x6987d0: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L006987d4: { // 0x6987d4: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987d6: { // 0x6987d6: 753f JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987d8: { // 0x6987d8: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006987dc: { // 0x6987dc: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L006987e0: { // 0x6987e0: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987e2: { // 0x6987e2: 7533 JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987e4: { // 0x6987e4: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006987e8: { // 0x6987e8: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L006987ec: { // 0x6987ec: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987ee: { // 0x6987ee: 7527 JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987f0: { // 0x6987f0: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L006987f4: { // 0x6987f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006987f6: { // 0x6987f6: 0f840c020000 JZ 0x00698a08
    if(integer::condition("JZ",flags)) goto L00698a08;
  }
  L006987fc: { // 0x6987fc: 8b15bc60aa00 MOV EDX,dword ptr [0x00aa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00698802: { // 0x698802: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698806: { // 0x698806: 8a4c1010 MOV CL,byte ptr [EAX + EDX*0x1 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000001u)+0x00000010u)));
  }
  L0069880a: { // 0x69880a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069880c: { // 0x69880c: 0f85f6010000 JNZ 0x00698a08
    if(integer::condition("JNZ",flags)) goto L00698a08;
  }
  L00698812: { // 0x698812: e9b2000000 JMP 0x006988c9
    goto L006988c9;
  }
  L00698817: { // 0x698817: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  L0069881b: { // 0x69881b: 0f8581000000 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698821: { // 0x698821: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00698825: { // 0x698825: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00698829: { // 0x698829: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0069882b: { // 0x69882b: 7575 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L0069882d: { // 0x69882d: 397c2428 CMP dword ptr [ESP + 0x28],EDI
    (void)integer::sub(m.r32((f.sp+0x00000028u)),s.di,32,flags);
  }
  L00698831: { // 0x698831: 756f JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698833: { // 0x698833: 396c242c CMP dword ptr [ESP + 0x2c],EBP
    (void)integer::sub(m.r32((f.sp+0x0000002cu)),s.bp,32,flags);
  }
  L00698837: { // 0x698837: 7569 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698839: { // 0x698839: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L0069883d: { // 0x69883d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069883f: { // 0x69883f: 7512 JNZ 0x00698853
    if(integer::condition("JNZ",flags)) goto L00698853;
  }
  L00698841: { // 0x698841: 8b15bc60aa00 MOV EDX,dword ptr [0x00aa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00698847: { // 0x698847: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0069884b: { // 0x69884b: 8a4c1010 MOV CL,byte ptr [EAX + EDX*0x1 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000001u)+0x00000010u)));
  }
  L0069884f: { // 0x69884f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00698851: { // 0x698851: 7576 JNZ 0x006988c9
    if(integer::condition("JNZ",flags)) goto L006988c9;
  }
  L00698853: { // 0x698853: a1c860aa00 MOV EAX,[0x00aa60c8]
    s.ax = m.r32((0x00aa60c8u));
  }
  L00698858: { // 0x698858: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069885c: { // 0x69885c: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0069885e: { // 0x69885e: 7d30 JGE 0x00698890
    if(integer::condition("JGE",flags)) goto L00698890;
  }
  L00698860: { // 0x698860: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00698861: { // 0x698861: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00698863: { // 0x698863: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00698865: { // 0x698865: a3c860aa00 MOV [0x00aa60c8],EAX
    m.w32((0x00aa60c8u), s.ax);
  }
  L0069886a: { // 0x69886a: 7d24 JGE 0x00698890
    if(integer::condition("JGE",flags)) goto L00698890;
  }
  L0069886c: { // 0x69886c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698870: { // 0x698870: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L00698876: { // 0x698876: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00698877: { // 0x698877: 8d740814 LEA ESI,[EAX + ECX*0x1 + 0x14]
    s.si = (s.ax+(s.cx * 0x00000001u)+0x00000014u);
  }
  L0069887b: { // 0x69887b: 8d3c08 LEA EDI,[EAX + ECX*0x1]
    s.di = (s.ax+(s.cx * 0x00000001u));
  }
  L0069887e: { // 0x69887e: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L00698883: { // 0x698883: 83c014 ADD EAX,0x14
    s.ax = integer::add(s.ax,0x00000014u,32,flags);
  }
  L00698886: { // 0x698886: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00698888: { // 0x698888: 3b15c860aa00 CMP EDX,dword ptr [0x00aa60c8]
    (void)integer::sub(s.dx,m.r32((0x00aa60c8u)),32,flags);
  }
  L0069888e: { // 0x69888e: 7ce0 JL 0x00698870
    if(integer::condition("JL",flags)) goto L00698870;
  }
  L00698890: { // 0x698890: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698894: { // 0x698894: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00698895: { // 0x698895: 83e814 SUB EAX,0x14
    s.ax = integer::sub(s.ax,0x00000014u,32,flags);
  }
  L00698898: { // 0x698898: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0069889c: { // 0x69889c: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006988a0: { // 0x6988a0: eb27 JMP 0x006988c9
    goto L006988c9;
  }
  L006988a2: { // 0x6988a2: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L006988a6: { // 0x6988a6: 0fafef IMUL EBP,EDI
    s.bp = integer::imul(s.bp,s.di,32,flags);
  }
  L006988a9: { // 0x6988a9: 0faf4c2474 IMUL ECX,dword ptr [ESP + 0x74]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x00000074u)),32,flags);
  }
  L006988ae: { // 0x6988ae: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L006988b1: { // 0x6988b1: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L006988b3: { // 0x6988b3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006988b5: { // 0x6988b5: 7d12 JGE 0x006988c9
    if(integer::condition("JGE",flags)) goto L006988c9;
  }
  L006988b7: { // 0x6988b7: 3b44241c CMP EAX,dword ptr [ESP + 0x1c]
    (void)integer::sub(s.ax,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L006988bb: { // 0x6988bb: 7d0c JGE 0x006988c9
    if(integer::condition("JGE",flags)) goto L006988c9;
  }
  L006988bd: { // 0x6988bd: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L006988c1: { // 0x6988c1: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006988c5: { // 0x6988c5: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006988c9: { // 0x6988c9: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006988cd: { // 0x6988cd: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L006988d1: { // 0x6988d1: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L006988d7: { // 0x6988d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006988d8: { // 0x6988d8: 83c614 ADD ESI,0x14
    s.si = integer::add(s.si,0x00000014u,32,flags);
  }
  L006988db: { // 0x6988db: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006988dd: { // 0x6988dd: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006988e1: { // 0x6988e1: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006988e5: { // 0x6988e5: 0f8ca4fdffff JL 0x0069868f
    if(integer::condition("JL",flags)) goto L0069868f;
  }
  L006988eb: { // 0x6988eb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006988ef: { // 0x6988ef: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006988f2: { // 0x6988f2: 0f859c000000 JNZ 0x00698994
    if(integer::condition("JNZ",flags)) goto L00698994;
  }
  L006988f8: { // 0x6988f8: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    s.ax = m.r32((f.sp+0x0000006cu));
  }
  L006988fc: { // 0x6988fc: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00698900: { // 0x698900: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00698904: { // 0x698904: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00698908: { // 0x698908: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0069890c: { // 0x69890c: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L00698910: { // 0x698910: 88442464 MOV byte ptr [ESP + 0x64],AL
    m.w8((f.sp+0x00000064u), (s.ax & 0xffu));
  }
  L00698914: { // 0x698914: a1c060aa00 MOV EAX,[0x00aa60c0]
    s.ax = m.r32((0x00aa60c0u));
  }
  L00698919: { // 0x698919: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0069891d: { // 0x69891d: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L00698921: { // 0x698921: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00698923: { // 0x698923: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00698927: { // 0x698927: 7c3b JL 0x00698964
    if(integer::condition("JL",flags)) goto L00698964;
  }
  L00698929: { // 0x698929: 8a0dc560aa00 MOV CL,byte ptr [0x00aa60c5]
    s.cx = with_al(s.cx, m.r8((0x00aa60c5u)));
  }
  L0069892f: { // 0x69892f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00698931: { // 0x698931: 7508 JNZ 0x0069893b
    if(integer::condition("JNZ",flags)) goto L0069893b;
  }
  L00698933: { // 0x698933: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698935: { // 0x698935: 0f85cd000000 JNZ 0x00698a08
    if(integer::condition("JNZ",flags)) goto L00698a08;
  }
  L0069893b: { // 0x69893b: 8b0dcc60aa00 MOV ECX,dword ptr [0x00aa60cc]
    s.cx = m.r32((0x00aa60ccu));
  }
  L00698941: { // 0x698941: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00698943: { // 0x698943: 0f8ebf000000 JLE 0x00698a08
    if(integer::condition("JLE",flags)) goto L00698a08;
  }
  L00698949: { // 0x698949: 8b15b860aa00 MOV EDX,dword ptr [0x00aa60b8]
    s.dx = m.r32((0x00aa60b8u));
  }
  L0069894f: { // 0x69894f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00698951: { // 0x698951: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00698953: { // 0x698953: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698954: { // 0x698954: b9b860aa00 MOV ECX,0xaa60b8
    s.cx = 0x00aa60b8u;
  }
  L00698959: { // 0x698959: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6916444u); flags=s.arithmetic_flags;
  }
  L0069895c: { // 0x69895c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069895e: { // 0x69895e: 0f84a4000000 JZ 0x00698a08
    if(integer::condition("JZ",flags)) goto L00698a08;
  }
  L00698964: { // 0x698964: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L0069896a: { // 0x69896a: 8d742454 LEA ESI,[ESP + 0x54]
    s.si = (f.sp+0x00000054u);
  }
  L0069896e: { // 0x69896e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698970: { // 0x698970: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00698971: { // 0x698971: 890dc860aa00 MOV dword ptr [0x00aa60c8],ECX
    m.w32((0x00aa60c8u), s.cx);
  }
  L00698977: { // 0x698977: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L0069897d: { // 0x69897d: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698980: { // 0x698980: 8d3c81 LEA EDI,[ECX + EAX*0x4]
    s.di = (s.cx+(s.ax * 0x00000004u));
  }
  L00698983: { // 0x698983: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L00698988: { // 0x698988: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0069898a: { // 0x69898a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069898b: { // 0x69898b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069898c: { // 0x69898c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069898d: { // 0x69898d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069898e: { // 0x69898e: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00698991: { // 0x698991: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00698994: { // 0x698994: 8a4c247c MOV CL,byte ptr [ESP + 0x7c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000007cu)));
  }
  L00698998: { // 0x698998: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069899a: { // 0x69899a: 7514 JNZ 0x006989b0
    if(integer::condition("JNZ",flags)) goto L006989b0;
  }
  L0069899c: { // 0x69899c: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0069899f: { // 0x69899f: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L006989a4: { // 0x6989a4: 8a4c9010 MOV CL,byte ptr [EAX + EDX*0x4 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000004u)+0x00000010u)));
  }
  L006989a8: { // 0x6989a8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006989aa: { // 0x6989aa: 7504 JNZ 0x006989b0
    if(integer::condition("JNZ",flags)) goto L006989b0;
  }
  L006989ac: { // 0x6989ac: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006989ae: { // 0x6989ae: eb05 JMP 0x006989b5
    goto L006989b5;
  }
  L006989b0: { // 0x6989b0: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006989b5: { // 0x6989b5: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L006989b9: { // 0x6989b9: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L006989bf: { // 0x6989bf: 8d34b6 LEA ESI,[ESI + ESI*0x4]
    s.si = (s.si+(s.si * 0x00000004u));
  }
  L006989c2: { // 0x6989c2: c1e602 SHL ESI,0x2
    s.si = integer::shift(s.si,0x00000002u,32,flags,integer::Shift::left);
  }
  L006989c5: { // 0x6989c5: 8d140e LEA EDX,[ESI + ECX*0x1]
    s.dx = (s.si+(s.cx * 0x00000001u));
  }
  L006989c8: { // 0x6989c8: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L006989cc: { // 0x6989cc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006989cd: { // 0x6989cd: 8d542470 LEA EDX,[ESP + 0x70]
    s.dx = (f.sp+0x00000070u);
  }
  L006989d1: { // 0x6989d1: e87a62dcff CALL 0x0045ec50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0045ec50u,6916566u); flags=s.arithmetic_flags;
  }
  L006989d6: { // 0x6989d6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006989d8: { // 0x6989d8: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006989db: { // 0x6989db: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006989df: { // 0x6989df: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006989e2: { // 0x6989e2: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L006989e6: { // 0x6989e6: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006989e9: { // 0x6989e9: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L006989ee: { // 0x6989ee: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L006989f2: { // 0x6989f2: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L006989f7: { // 0x6989f7: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L006989fb: { // 0x6989fb: 8d3c06 LEA EDI,[ESI + EAX*0x1]
    s.di = (s.si+(s.ax * 0x00000001u));
  }
  L006989fe: { // 0x6989fe: 8d742440 LEA ESI,[ESP + 0x40]
    s.si = (f.sp+0x00000040u);
  }
  L00698a02: { // 0x698a02: 885c2450 MOV byte ptr [ESP + 0x50],BL
    m.w8((f.sp+0x00000050u), (s.bx & 0xffu));
  }
  L00698a06: { // 0x698a06: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00698a08: { // 0x698a08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00698a09: { // 0x698a09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00698a0a: { // 0x698a0a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00698a0b: { // 0x698a0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00698a0c: { // 0x698a0c: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00698a0f: { // 0x698a0f: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_0001fdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041fdf0: { // 0x41fdf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0041fdf3: { // 0x41fdf3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041fdf5: { // 0x41fdf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041fdf6: { // 0x41fdf6: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fdfa: { // 0x41fdfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041fdfb: { // 0x41fdfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041fdfc: { // 0x41fdfc: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041fdfe: { // 0x41fdfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041fdff: { // 0x41fdff: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L0041fe01: { // 0x41fe01: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0041fe04: { // 0x41fe04: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L0041fe07: { // 0x41fe07: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe0b: { // 0x41fe0b: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  L0041fe0e: { // 0x41fe0e: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0041fe12: { // 0x41fe12: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0041fe15: { // 0x41fe15: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041fe17: { // 0x41fe17: 0f8edb000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe1d: { // 0x41fe1d: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0041fe20: { // 0x41fe20: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe22: { // 0x41fe22: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0041fe26: { // 0x41fe26: 0f8ecc000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe2c: { // 0x41fe2c: 8b6908 MOV EBP,dword ptr [ECX + 0x8]
    s.bp = m.r32((s.cx+0x00000008u));
  }
  L0041fe2f: { // 0x41fe2f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe31: { // 0x41fe31: 0f8ec1000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe37: { // 0x41fe37: 8b690c MOV EBP,dword ptr [ECX + 0xc]
    s.bp = m.r32((s.cx+0x0000000cu));
  }
  L0041fe3a: { // 0x41fe3a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe3c: { // 0x41fe3c: 0f8eb6000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe42: { // 0x41fe42: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0041fe44: { // 0x41fe44: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe46: { // 0x41fe46: 7d0e JGE 0x0041fe56
    if(integer::condition("JGE",flags)) goto L0041fe56;
  }
  L0041fe48: { // 0x41fe48: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe4c: { // 0x41fe4c: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe4e: { // 0x41fe4e: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe50: { // 0x41fe50: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0041fe52: { // 0x41fe52: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe56: { // 0x41fe56: 837c242001 CMP dword ptr [ESP + 0x20],0x1
    (void)integer::sub(m.r32((f.sp+0x00000020u)),0x00000001u,32,flags);
  }
  L0041fe5b: { // 0x41fe5b: 0f8c97000000 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe61: { // 0x41fe61: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L0041fe64: { // 0x41fe64: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe66: { // 0x41fe66: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0041fe6a: { // 0x41fe6a: 7d0e JGE 0x0041fe7a
    if(integer::condition("JGE",flags)) goto L0041fe7a;
  }
  L0041fe6c: { // 0x41fe6c: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0041fe70: { // 0x41fe70: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe72: { // 0x41fe72: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041fe74: { // 0x41fe74: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0041fe76: { // 0x41fe76: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0041fe7a: { // 0x41fe7a: 837c242401 CMP dword ptr [ESP + 0x24],0x1
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x00000001u,32,flags);
  }
  L0041fe7f: { // 0x41fe7f: 7c77 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe81: { // 0x41fe81: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe85: { // 0x41fe85: 8d1431 LEA EDX,[ECX + ESI*0x1]
    s.dx = (s.cx+(s.si * 0x00000001u));
  }
  L0041fe88: { // 0x41fe88: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe8a: { // 0x41fe8a: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041fe8c: { // 0x41fe8c: 7e06 JLE 0x0041fe94
    if(integer::condition("JLE",flags)) goto L0041fe94;
  }
  L0041fe8e: { // 0x41fe8e: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0041fe90: { // 0x41fe90: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041fe92: { // 0x41fe92: eb04 JMP 0x0041fe98
    goto L0041fe98;
  }
  L0041fe94: { // 0x41fe94: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fe98: { // 0x41fe98: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0041fe9b: { // 0x41fe9b: 7c5b JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe9d: { // 0x41fe9d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041fea1: { // 0x41fea1: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0041fea5: { // 0x41fea5: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041fea7: { // 0x41fea7: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041feab: { // 0x41feab: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  L0041feae: { // 0x41feae: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041feb0: { // 0x41feb0: 7e04 JLE 0x0041feb6
    if(integer::condition("JLE",flags)) goto L0041feb6;
  }
  L0041feb2: { // 0x41feb2: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0041feb4: { // 0x41feb4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0041feb6: { // 0x41feb6: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0041feb9: { // 0x41feb9: 7c3d JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041febb: { // 0x41febb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0041febf: { // 0x41febf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fec1: { // 0x41fec1: 740b JZ 0x0041fece
    if(integer::condition("JZ",flags)) goto L0041fece;
  }
  L0041fec3: { // 0x41fec3: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041fec7: { // 0x41fec7: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L0041feca: { // 0x41feca: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0041fecc: { // 0x41fecc: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fece: { // 0x41fece: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0041fed2: { // 0x41fed2: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fed4: { // 0x41fed4: 740b JZ 0x0041fee1
    if(integer::condition("JZ",flags)) goto L0041fee1;
  }
  L0041fed6: { // 0x41fed6: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041feda: { // 0x41feda: 8b6d04 MOV EBP,dword ptr [EBP + 0x4]
    s.bp = m.r32((s.bp+0x00000004u));
  }
  L0041fedd: { // 0x41fedd: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0041fedf: { // 0x41fedf: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fee1: { // 0x41fee1: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fee3: { // 0x41fee3: 891a MOV dword ptr [EDX],EBX
    m.w32((s.dx), s.bx);
  }
  L0041fee5: { // 0x41fee5: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0041fee8: { // 0x41fee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fee9: { // 0x41fee9: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041feec: { // 0x41feec: 89720c MOV dword ptr [EDX + 0xc],ESI
    m.w32((s.dx+0x0000000cu), s.si);
  }
  L0041feef: { // 0x41feef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fef0: { // 0x41fef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041fef1: { // 0x41fef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041fef2: { // 0x41fef2: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041fef5: { // 0x41fef5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041fef8: { // 0x41fef8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fefa: { // 0x41fefa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041fefc: { // 0x41fefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fefd: { // 0x41fefd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fefe: { // 0x41fefe: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0041ff00: { // 0x41ff00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ff01: { // 0x41ff01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ff02: { // 0x41ff02: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0041ff05: { // 0x41ff05: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041ff08: { // 0x41ff08: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L0041ff0b: { // 0x41ff0b: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041ff0e: { // 0x41ff0e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0005ec50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045ec50: { // 0x45ec50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0045ec53: { // 0x45ec53: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L0045ec56: { // 0x45ec56: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0045ec57: { // 0x45ec57: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0045ec58: { // 0x45ec58: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0045ec5a: { // 0x45ec5a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045ec5c: { // 0x45ec5c: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0045ec60: { // 0x45ec60: 0f8eb4000000 JLE 0x0045ed1a
    if(integer::condition("JLE",flags)) goto L0045ed1a;
  }
  L0045ec66: { // 0x45ec66: 8b420c MOV EAX,dword ptr [EDX + 0xc]
    s.ax = m.r32((s.dx+0x0000000cu));
  }
  L0045ec69: { // 0x45ec69: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045ec6b: { // 0x45ec6b: 0f8ea9000000 JLE 0x0045ed1a
    if(integer::condition("JLE",flags)) goto L0045ed1a;
  }
  L0045ec71: { // 0x45ec71: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0045ec75: { // 0x45ec75: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0045ec78: { // 0x45ec78: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045ec7a: { // 0x45ec7a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0045ec7e: { // 0x45ec7e: 7e7a JLE 0x0045ecfa
    if(integer::condition("JLE",flags)) goto L0045ecfa;
  }
  L0045ec80: { // 0x45ec80: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  L0045ec83: { // 0x45ec83: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0045ec85: { // 0x45ec85: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0045ec89: { // 0x45ec89: 7e6f JLE 0x0045ecfa
    if(integer::condition("JLE",flags)) goto L0045ecfa;
  }
  L0045ec8b: { // 0x45ec8b: 8b3a MOV EDI,dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
  L0045ec8d: { // 0x45ec8d: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L0045ec8f: { // 0x45ec8f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0045ec90: { // 0x45ec90: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  L0045ec93: { // 0x45ec93: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0045ec94: { // 0x45ec94: 8b6a08 MOV EBP,dword ptr [EDX + 0x8]
    s.bp = m.r32((s.dx+0x00000008u));
  }
  L0045ec97: { // 0x45ec97: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L0045ec9a: { // 0x45ec9a: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0045ec9c: { // 0x45ec9c: 7e06 JLE 0x0045eca4
    if(integer::condition("JLE",flags)) goto L0045eca4;
  }
  L0045ec9e: { // 0x45ec9e: 2bfe SUB EDI,ESI
    s.di = integer::sub(s.di,s.si,32,flags);
  }
  L0045eca0: { // 0x45eca0: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0045eca2: { // 0x45eca2: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0045eca4: { // 0x45eca4: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0045eca7: { // 0x45eca7: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0045eca9: { // 0x45eca9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0045ecad: { // 0x45ecad: 7e06 JLE 0x0045ecb5
    if(integer::condition("JLE",flags)) goto L0045ecb5;
  }
  L0045ecaf: { // 0x45ecaf: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0045ecb1: { // 0x45ecb1: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L0045ecb3: { // 0x45ecb3: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0045ecb5: { // 0x45ecb5: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0045ecb7: { // 0x45ecb7: 8d0c2f LEA ECX,[EDI + EBP*0x1]
    s.cx = (s.di+(s.bp * 0x00000001u));
  }
  L0045ecba: { // 0x45ecba: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0045ecbc: { // 0x45ecbc: 7d0a JGE 0x0045ecc8
    if(integer::condition("JGE",flags)) goto L0045ecc8;
  }
  L0045ecbe: { // 0x45ecbe: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0045ecc2: { // 0x45ecc2: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L0045ecc4: { // 0x45ecc4: 8d6c0601 LEA EBP,[ESI + EAX*0x1 + 0x1]
    s.bp = (s.si+(s.ax * 0x00000001u)+0x00000001u);
  }
  L0045ecc8: { // 0x45ecc8: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0045eccc: { // 0x45eccc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0045ecd0: { // 0x45ecd0: 8d3401 LEA ESI,[ECX + EAX*0x1]
    s.si = (s.cx+(s.ax * 0x00000001u));
  }
  L0045ecd3: { // 0x45ecd3: 8d0c1a LEA ECX,[EDX + EBX*0x1]
    s.cx = (s.dx+(s.bx * 0x00000001u));
  }
  L0045ecd6: { // 0x45ecd6: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L0045ecd8: { // 0x45ecd8: 7d05 JGE 0x0045ecdf
    if(integer::condition("JGE",flags)) goto L0045ecdf;
  }
  L0045ecda: { // 0x45ecda: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L0045ecdc: { // 0x45ecdc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0045ecdd: { // 0x45ecdd: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0045ecdf: { // 0x45ecdf: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0045ece3: { // 0x45ece3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0045ece5: { // 0x45ece5: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L0045ece7: { // 0x45ece7: 895904 MOV dword ptr [ECX + 0x4],EBX
    m.w32((s.cx+0x00000004u), s.bx);
  }
  L0045ecea: { // 0x45ecea: 896908 MOV dword ptr [ECX + 0x8],EBP
    m.w32((s.cx+0x00000008u), s.bp);
  }
  L0045eced: { // 0x45eced: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0045ecee: { // 0x45ecee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0045ecef: { // 0x45ecef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045ecf0: { // 0x45ecf0: 89510c MOV dword ptr [ECX + 0xc],EDX
    m.w32((s.cx+0x0000000cu), s.dx);
  }
  L0045ecf3: { // 0x45ecf3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045ecf4: { // 0x45ecf4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0045ecf7: { // 0x45ecf7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0045ecfa: { // 0x45ecfa: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0045ecfc: { // 0x45ecfc: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0045ecfe: { // 0x45ecfe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045ecff: { // 0x45ecff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045ed00: { // 0x45ed00: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0045ed02: { // 0x45ed02: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0045ed05: { // 0x45ed05: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0045ed08: { // 0x45ed08: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0045ed0b: { // 0x45ed0b: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0045ed0e: { // 0x45ed0e: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L0045ed11: { // 0x45ed11: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0045ed14: { // 0x45ed14: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0045ed17: { // 0x45ed17: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0045ed1a: { // 0x45ed1a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0045ed1e: { // 0x45ed1e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0045ed20: { // 0x45ed20: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0045ed22: { // 0x45ed22: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0045ed24: { // 0x45ed24: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0045ed27: { // 0x45ed27: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0045ed2a: { // 0x45ed2a: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0045ed2d: { // 0x45ed2d: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0045ed30: { // 0x45ed30: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0045ed33: { // 0x45ed33: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0045ed36: { // 0x45ed36: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0045ed38: { // 0x45ed38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045ed39: { // 0x45ed39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045ed3a: { // 0x45ed3a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0045ed3d: { // 0x45ed3d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4676016u:f_000759b0(m,s,child,{});break;
case 4672768u:f_00074d00(m,s,child,{});break;
case 4306480u:f_0001b630(m,s,child,{});break;
case 6914064u:f_00298010(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4673600u:f_00075040(m,s,child,{});break;
case 6112976u:f_001d46d0(m,s,child,{});break;
case 6117328u:f_001d57d0(m,s,child,{});break;
case 4672176u:f_00074ab0(m,s,child,{});break;
case 6113072u:f_001d4730(m,s,child,{});break;
case 6915680u:f_00298660(m,s,child,{});break;
case 4324848u:f_0001fdf0(m,s,child,{});break;
case 4582480u:f_0005ec50(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
default:throw std::domain_error("recovery789 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004759b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004759b0: { // 0x4759b0: 83ec3c SUB ESP, 0x3c
    f.sp = integer::sub(f.sp,0x0000003cu,32,flags);
  }
  L004759b3: { // 0x4759b3: 8d44241c LEA EAX, [ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L004759b7: { // 0x4759b7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004759b8: { // 0x4759b8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004759b9: { // 0x4759b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004759ba: { // 0x4759ba: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004759bb: { // 0x4759bb: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004759bd: { // 0x4759bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004759be: { // 0x4759be: e83df3ffff CALL 0x474d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474d00u,4676035u); flags=s.arithmetic_flags;
  }
  L004759c3: { // 0x4759c3: 8d4c243c LEA ECX, [ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L004759c7: { // 0x4759c7: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004759c9: { // 0x4759c9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004759ca: { // 0x4759ca: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004759cc: { // 0x4759cc: e8dff0ffff CALL 0x474ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474ab0u,4676049u); flags=s.arithmetic_flags;
  }
  L004759d1: { // 0x4759d1: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L004759d4: { // 0x4759d4: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759d6: { // 0x4759d6: 0f8e98000000 JLE 0x475a74
    if(integer::condition("JLE",flags)) goto L00475a74;
  }
  L004759dc: { // 0x4759dc: 8b480c MOV ECX, dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L004759df: { // 0x4759df: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759e1: { // 0x4759e1: 0f8e8d000000 JLE 0x475a74
    if(integer::condition("JLE",flags)) goto L00475a74;
  }
  L004759e7: { // 0x4759e7: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L004759ea: { // 0x4759ea: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759ec: { // 0x4759ec: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004759f0: { // 0x4759f0: 7e75 JLE 0x475a67
    if(integer::condition("JLE",flags)) goto L00475a67;
  }
  L004759f2: { // 0x4759f2: 8b4f0c MOV ECX, dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L004759f5: { // 0x4759f5: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004759f7: { // 0x4759f7: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004759fb: { // 0x4759fb: 7e6a JLE 0x475a67
    if(integer::condition("JLE",flags)) goto L00475a67;
  }
  L004759fd: { // 0x4759fd: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004759ff: { // 0x4759ff: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00475a01: { // 0x475a01: 8b6808 MOV EBP, dword ptr [EAX + 8]
    s.bp = m.r32((s.ax+8u));
  }
  L00475a04: { // 0x475a04: 8b5804 MOV EBX, dword ptr [EAX + 4]
    s.bx = m.r32((s.ax+4u));
  }
  L00475a07: { // 0x475a07: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00475a0a: { // 0x475a0a: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00475a0c: { // 0x475a0c: 896c2424 MOV dword ptr [ESP + 0x24], EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L00475a10: { // 0x475a10: 7e0a JLE 0x475a1c
    if(integer::condition("JLE",flags)) goto L00475a1c;
  }
  L00475a12: { // 0x475a12: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00475a14: { // 0x475a14: 03e9 ADD EBP, ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00475a16: { // 0x475a16: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00475a18: { // 0x475a18: 896c2424 MOV dword ptr [ESP + 0x24], EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L00475a1c: { // 0x475a1c: 8b7f04 MOV EDI, dword ptr [EDI + 4]
    s.di = m.r32((s.di+4u));
  }
  L00475a1f: { // 0x475a1f: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00475a21: { // 0x475a21: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00475a25: { // 0x475a25: 7e06 JLE 0x475a2d
    if(integer::condition("JLE",flags)) goto L00475a2d;
  }
  L00475a27: { // 0x475a27: 2bdf SUB EBX, EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  L00475a29: { // 0x475a29: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00475a2b: { // 0x475a2b: 8bdf MOV EBX, EDI
    s.bx = s.di;
  }
  L00475a2d: { // 0x475a2d: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00475a31: { // 0x475a31: 03e9 ADD EBP, ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00475a33: { // 0x475a33: 03fa ADD EDI, EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00475a35: { // 0x475a35: 3bef CMP EBP, EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L00475a37: { // 0x475a37: 7d0c JGE 0x475a45
    if(integer::condition("JGE",flags)) goto L00475a45;
  }
  L00475a39: { // 0x475a39: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00475a3d: { // 0x475a3d: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00475a3f: { // 0x475a3f: 8d7c3a01 LEA EDI, [EDX + EDI + 1]
    s.di = (s.dx+s.di+1u);
  }
  L00475a43: { // 0x475a43: eb04 JMP 0x475a49
    goto L00475a49;
  }
  L00475a45: { // 0x475a45: 8b7c2424 MOV EDI, dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L00475a49: { // 0x475a49: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00475a4d: { // 0x475a4d: 8b6c2418 MOV EBP, dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00475a51: { // 0x475a51: 03d5 ADD EDX, EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L00475a53: { // 0x475a53: 8d2c18 LEA EBP, [EAX + EBX]
    s.bp = (s.ax+s.bx);
  }
  L00475a56: { // 0x475a56: 3bea CMP EBP, EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00475a58: { // 0x475a58: 7d05 JGE 0x475a5f
    if(integer::condition("JGE",flags)) goto L00475a5f;
  }
  L00475a5a: { // 0x475a5a: 2bd3 SUB EDX, EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00475a5c: { // 0x475a5c: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00475a5d: { // 0x475a5d: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L00475a5f: { // 0x475a5f: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L00475a61: { // 0x475a61: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L00475a63: { // 0x475a63: 8bdf MOV EBX, EDI
    s.bx = s.di;
  }
  L00475a65: { // 0x475a65: eb18 JMP 0x475a7f
    goto L00475a7f;
  }
  L00475a67: { // 0x475a67: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00475a69: { // 0x475a69: 8b4804 MOV ECX, dword ptr [EAX + 4]
    s.cx = m.r32((s.ax+4u));
  }
  L00475a6c: { // 0x475a6c: 8b5808 MOV EBX, dword ptr [EAX + 8]
    s.bx = m.r32((s.ax+8u));
  }
  L00475a6f: { // 0x475a6f: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00475a72: { // 0x475a72: eb0b JMP 0x475a7f
    goto L00475a7f;
  }
  L00475a74: { // 0x475a74: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00475a76: { // 0x475a76: 8b4f04 MOV ECX, dword ptr [EDI + 4]
    s.cx = m.r32((s.di+4u));
  }
  L00475a79: { // 0x475a79: 8b5f08 MOV EBX, dword ptr [EDI + 8]
    s.bx = m.r32((s.di+8u));
  }
  L00475a7c: { // 0x475a7c: 8b470c MOV EAX, dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00475a7f: { // 0x475a7f: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00475a83: { // 0x475a83: 8b1574198200 MOV EDX, dword ptr [0x821974]
    s.dx = m.r32((0x00821974u));
  }
  L00475a89: { // 0x475a89: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00475a8d: { // 0x475a8d: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00475a8f: { // 0x475a8f: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00475a93: { // 0x475a93: 8b4e44 MOV ECX, dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  L00475a96: { // 0x475a96: 895c2424 MOV dword ptr [ESP + 0x24], EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00475a9a: { // 0x475a9a: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00475a9e: { // 0x475a9e: e88dec1500 CALL 0x5d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4676259u); flags=s.arithmetic_flags;
  }
  L00475aa3: { // 0x475aa3: 8b5c2450 MOV EBX, dword ptr [ESP + 0x50]
    s.bx = m.r32((f.sp+0x00000050u));
  }
  L00475aa7: { // 0x475aa7: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00475aa9: { // 0x475aa9: 0f8e21010000 JLE 0x475bd0
    if(integer::condition("JLE",flags)) goto L00475bd0;
  }
  L00475aaf: { // 0x475aaf: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00475ab2: { // 0x475ab2: 0f8418010000 JZ 0x475bd0
    if(integer::condition("JZ",flags)) goto L00475bd0;
  }
  L00475ab8: { // 0x475ab8: 8b0d3c86aa00 MOV ECX, dword ptr [0xaa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L00475abe: { // 0x475abe: 8b2c81 MOV EBP, dword ptr [ECX + EAX*4]
    s.bp = m.r32((s.cx+(s.ax * 4u)));
  }
  L00475ac1: { // 0x475ac1: 8a861e010000 MOV AL, byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00475ac7: { // 0x475ac7: 3c0b CMP AL, 0xb
    (void)integer::sub((s.ax & 0xffu),0x0000000bu,8,flags);
  }
  L00475ac9: { // 0x475ac9: 750b JNZ 0x475ad6
    if(integer::condition("JNZ",flags)) goto L00475ad6;
  }
  L00475acb: { // 0x475acb: 8d5624 LEA EDX, [ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  L00475ace: { // 0x475ace: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00475ad0: { // 0x475ad0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00475ad1: { // 0x475ad1: e86aa02600 CALL 0x6dfb40
    s.arithmetic_flags=flags; invoke(m,s,f,0x006dfb40u,4676310u); flags=s.arithmetic_flags;
  }
  L00475ad6: { // 0x475ad6: 8a861e010000 MOV AL, byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00475adc: { // 0x475adc: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00475ade: { // 0x475ade: 81e1ff000000 AND ECX, 0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00475ae4: { // 0x475ae4: 8d5101 LEA EDX, [ECX + 1]
    s.dx = (s.cx+1u);
  }
  L00475ae7: { // 0x475ae7: 3bd3 CMP EDX, EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L00475ae9: { // 0x475ae9: 7e0d JLE 0x475af8
    if(integer::condition("JLE",flags)) goto L00475af8;
  }
  L00475aeb: { // 0x475aeb: 2ac3 SUB AL, BL
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00475aed: { // 0x475aed: 88861e010000 MOV byte ptr [ESI + 0x11e], AL
    m.w8((s.si+0x0000011eu), (s.ax & 0xffu));
  }
  L00475af3: { // 0x475af3: e99f000000 JMP 0x475b97
    goto L00475b97;
  }
  L00475af8: { // 0x475af8: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L00475afa: { // 0x475afa: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L00475afc: { // 0x475afc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00475afe: { // 0x475afe: c74644ffffffff MOV dword ptr [ESI + 0x44], 0xffffffff
    m.w32((s.si+0x00000044u), 0xffffffffu);
  }
  L00475b05: { // 0x475b05: c6861e01000000 MOV byte ptr [ESI + 0x11e], 0
    m.w8((s.si+0x0000011eu), 0u);
  }
  L00475b0c: { // 0x475b0c: e82fc6ffff CALL 0x472140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00472140u,4676369u); flags=s.arithmetic_flags;
  }
  L00475b11: { // 0x475b11: 83c624 ADD ESI, 0x24
    s.si = integer::add(s.si,0x00000024u,32,flags);
  }
  L00475b14: { // 0x475b14: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00475b19: { // 0x475b19: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00475b1a: { // 0x475b1a: e8d1301b00 CALL 0x628bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00628bf0u,4676383u); flags=s.arithmetic_flags;
  }
  L00475b1f: { // 0x475b1f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00475b21: { // 0x475b21: e82a952600 CALL 0x6df050
    s.arithmetic_flags=flags; invoke(m,s,f,0x006df050u,4676390u); flags=s.arithmetic_flags;
  }
  L00475b26: { // 0x475b26: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00475b28: { // 0x475b28: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00475b2a: { // 0x475b2a: 83e007 AND EAX, 7
    s.ax = integer::logical((s.ax)&(7u),32,flags);
  }
  L00475b2d: { // 0x475b2d: 668b0c85a09d8300 MOV CX, word ptr [EAX*4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 4u)+0x00839da0u)));
  }
  L00475b35: { // 0x475b35: 668b1485a29d8300 MOV DX, word ptr [EAX*4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 4u)+0x00839da2u)));
  }
  L00475b3d: { // 0x475b3d: 66030e ADD CX, word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00475b40: { // 0x475b40: 66035602 ADD DX, word ptr [ESI + 2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.si+2u)),16,flags));
  }
  L00475b44: { // 0x475b44: 8d0485a09d8300 LEA EAX, [EAX*4 + 0x839da0]
    s.ax = ((s.ax * 4u)+0x00839da0u);
  }
  L00475b4b: { // 0x475b4b: 66894c2410 MOV word ptr [ESP + 0x10], CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00475b50: { // 0x475b50: 8d4c2450 LEA ECX, [ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00475b54: { // 0x475b54: 6689542412 MOV word ptr [ESP + 0x12], DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L00475b59: { // 0x475b59: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00475b5d: { // 0x475b5d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00475b5e: { // 0x475b5e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00475b63: { // 0x475b63: 89442454 MOV dword ptr [ESP + 0x54], EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00475b67: { // 0x475b67: e8d4230d00 CALL 0x547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,4676460u); flags=s.arithmetic_flags;
  }
  L00475b6c: { // 0x475b6c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00475b6e: { // 0x475b6e: 7421 JZ 0x475b91
    if(integer::condition("JZ",flags)) goto L00475b91;
  }
  L00475b70: { // 0x475b70: 8d4c2450 LEA ECX, [ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00475b74: { // 0x475b74: e8172ffbff CALL 0x428a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428a90u,4676473u); flags=s.arithmetic_flags;
  }
  L00475b79: { // 0x475b79: 8b95f8000000 MOV EDX, dword ptr [EBP + 0xf8]
    s.dx = m.r32((s.bp+0x000000f8u));
  }
  L00475b7f: { // 0x475b7f: 803c1000 CMP byte ptr [EAX + EDX], 0
    (void)integer::sub(m.r8((s.ax+s.dx)),0u,8,flags);
  }
  L00475b83: { // 0x475b83: 750c JNZ 0x475b91
    if(integer::condition("JNZ",flags)) goto L00475b91;
  }
  L00475b85: { // 0x475b85: 8d442450 LEA EAX, [ESP + 0x50]
    s.ax = (f.sp+0x00000050u);
  }
  L00475b89: { // 0x475b89: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00475b8b: { // 0x475b8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00475b8c: { // 0x475b8c: e8ff942600 CALL 0x6df090
    s.arithmetic_flags=flags; invoke(m,s,f,0x006df090u,4676497u); flags=s.arithmetic_flags;
  }
  L00475b91: { // 0x475b91: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00475b92: { // 0x475b92: 83ff08 CMP EDI, 8
    (void)integer::sub(s.di,8u,32,flags);
  }
  L00475b95: { // 0x475b95: 7c91 JL 0x475b28
    if(integer::condition("JL",flags)) goto L00475b28;
  }
  L00475b97: { // 0x475b97: 8b54241c MOV EDX, dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00475b9b: { // 0x475b9b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00475b9d: { // 0x475b9d: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00475ba1: { // 0x475ba1: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00475ba4: { // 0x475ba4: 8bcc MOV ECX, ESP
    s.cx = f.sp;
  }
  L00475ba6: { // 0x475ba6: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L00475ba8: { // 0x475ba8: 8b542438 MOV EDX, dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00475bac: { // 0x475bac: 894104 MOV dword ptr [ECX + 4], EAX
    m.w32((s.cx+4u), s.ax);
  }
  L00475baf: { // 0x475baf: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00475bb3: { // 0x475bb3: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L00475bb6: { // 0x475bb6: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L00475bb9: { // 0x475bb9: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00475bbf: { // 0x475bbf: e89c2a2200 CALL 0x698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,4676548u); flags=s.arithmetic_flags;
  }
  L00475bc4: { // 0x475bc4: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L00475bc6: { // 0x475bc6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00475bc7: { // 0x475bc7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00475bc8: { // 0x475bc8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00475bc9: { // 0x475bc9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00475bca: { // 0x475bca: 83c43c ADD ESP, 0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L00475bcd: { // 0x475bcd: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00475bd0: { // 0x475bd0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00475bd1: { // 0x475bd1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00475bd2: { // 0x475bd2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00475bd3: { // 0x475bd3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00475bd5: { // 0x475bd5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00475bd6: { // 0x475bd6: 83c43c ADD ESP, 0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L00475bd9: { // 0x475bd9: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0055a780(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0055a780: { // 0x55a780: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055a781: { // 0x55a781: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0055a783: { // 0x55a783: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0055a786: { // 0x55a786: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0055a789: { // 0x55a789: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0055a78a: { // 0x55a78a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055a78b: { // 0x55a78b: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L0055a78e: { // 0x55a78e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0055a78f: { // 0x55a78f: bbfbffffff MOV EBX,0xfffffffb
    s.bx = 0xfffffffbu;
  }
  L0055a794: { // 0x55a794: bffbffffff MOV EDI,0xfffffffb
    s.di = 0xfffffffbu;
  }
  L0055a799: { // 0x55a799: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0055a79c: { // 0x55a79c: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0055a79f: { // 0x55a79f: 8d0c18 LEA ECX,[EAX + EBX*0x1]
    s.cx = (s.ax+(s.bx * 0x00000001u));
  }
  L0055a7a2: { // 0x55a7a2: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0055a7a7: { // 0x55a7a7: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0055a7ab: { // 0x55a7ab: 8d1439 LEA EDX,[ECX + EDI*0x1]
    s.dx = (s.cx+(s.di * 0x00000001u));
  }
  L0055a7ae: { // 0x55a7ae: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0055a7b3: { // 0x55a7b3: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0055a7b7: { // 0x55a7b7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0055a7b9: { // 0x55a7b9: 8b54241a MOV EDX,dword ptr [ESP + 0x1a]
    s.dx = m.r32((f.sp+0x0000001au));
  }
  L0055a7bd: { // 0x55a7bd: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0055a7bf: { // 0x55a7bf: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0055a7c2: { // 0x55a7c2: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0055a7c5: { // 0x55a7c5: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055a7c9: { // 0x55a7c9: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L0055a7cd: { // 0x55a7cd: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0055a7d1: { // 0x55a7d1: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L0055a7d5: { // 0x55a7d5: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0055a7d7: { // 0x55a7d7: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0055a7d9: { // 0x55a7d9: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0055a7db: { // 0x55a7db: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0055a7dd: { // 0x55a7dd: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0055a7df: { // 0x55a7df: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0055a7e2: { // 0x55a7e2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0055a7e4: { // 0x55a7e4: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0055a7e6: { // 0x55a7e6: e895f8f5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5613547u); flags=s.arithmetic_flags;
  }
  L0055a7eb: { // 0x55a7eb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0055a7ee: { // 0x55a7ee: e85d022100 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5613555u); flags=s.arithmetic_flags;
  }
  L0055a7f3: { // 0x55a7f3: 663d0500 CMP AX,0x5
    (void)integer::sub((s.ax & 0xffffu),0x00000005u,16,flags);
  }
  L0055a7f7: { // 0x55a7f7: 7f3d JG 0x0055a836
    if(integer::condition("JG",flags)) goto L0055a836;
  }
  L0055a7f9: { // 0x55a7f9: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0055a7fd: { // 0x55a7fd: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0055a800: { // 0x55a800: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055a803: { // 0x55a803: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0055a805: { // 0x55a805: 7818 JS 0x0055a81f
    if(integer::condition("JS",flags)) goto L0055a81f;
  }
  L0055a807: { // 0x55a807: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055a80c: { // 0x55a80c: 7d11 JGE 0x0055a81f
    if(integer::condition("JGE",flags)) goto L0055a81f;
  }
  L0055a80e: { // 0x55a80e: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0055a814: { // 0x55a814: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0055a817: { // 0x55a817: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055a819: { // 0x55a819: 7404 JZ 0x0055a81f
    if(integer::condition("JZ",flags)) goto L0055a81f;
  }
  L0055a81b: { // 0x55a81b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055a81d: { // 0x55a81d: eb0c JMP 0x0055a82b
    goto L0055a82b;
  }
  L0055a81f: { // 0x55a81f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0055a821: { // 0x55a821: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L0055a826: { // 0x55a826: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055a82b: { // 0x55a82b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a82d: { // 0x55a82d: 7407 JZ 0x0055a836
    if(integer::condition("JZ",flags)) goto L0055a836;
  }
  L0055a82f: { // 0x55a82f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055a831: { // 0x55a831: e87ab1f1ff CALL 0x004759b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004759b0u,5613622u); flags=s.arithmetic_flags;
  }
  L0055a836: { // 0x55a836: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0055a837: { // 0x55a837: 83ff05 CMP EDI,0x5
    (void)integer::sub(s.di,0x00000005u,32,flags);
  }
  L0055a83a: { // 0x55a83a: 0f8e59ffffff JLE 0x0055a799
    if(integer::condition("JLE",flags)) goto L0055a799;
  }
  L0055a840: { // 0x55a840: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0055a841: { // 0x55a841: 83fb05 CMP EBX,0x5
    (void)integer::sub(s.bx,0x00000005u,32,flags);
  }
  L0055a844: { // 0x55a844: 0f8e4affffff JLE 0x0055a794
    if(integer::condition("JLE",flags)) goto L0055a794;
  }
  L0055a84a: { // 0x55a84a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055a84b: { // 0x55a84b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055a84c: { // 0x55a84c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055a84d: { // 0x55a84d: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0055a84f: { // 0x55a84f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055a850: { // 0x55a850: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
