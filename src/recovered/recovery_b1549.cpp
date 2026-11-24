#include "recovered/recovery_b1549_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1549 {
namespace {
void f_00316a70(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_002cdab0(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_0001b600(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_0007b710(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_00316a70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00716a70: { // 0x716a70: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00716a73: { // 0x716a73: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00716a74: { // 0x716a74: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L00716a76: { // 0x716a76: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00716a77: { // 0x716a77: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00716a78: { // 0x716a78: 8b859c010000 MOV EAX, dword ptr [EBP + 0x19c]
    s.ax = m.r32((s.bp+0x0000019cu));
  }
  L00716a7e: { // 0x716a7e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00716a80: { // 0x716a80: 0f8469010000 JZ 0x716bef
    if(integer::condition("JZ",flags)) goto L00716bef;
  }
  L00716a86: { // 0x716a86: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00716a8a: { // 0x716a8a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00716a8b: { // 0x716a8b: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00716a8d: { // 0x716a8d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00716a8e: { // 0x716a8e: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00716a94: { // 0x716a94: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00716a96: { // 0x716a96: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00716a99: { // 0x716a99: 668944241c MOV word ptr [ESP + 0x1c], AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L00716a9e: { // 0x716a9e: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00716aa1: { // 0x716aa1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00716aa2: { // 0x716aa2: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00716aa8: { // 0x716aa8: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00716aac: { // 0x716aac: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00716aae: { // 0x716aae: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00716aaf: { // 0x716aaf: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00716ab2: { // 0x716ab2: 6689442422 MOV word ptr [ESP + 0x22], AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L00716ab7: { // 0x716ab7: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00716abb: { // 0x716abb: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00716ac0: { // 0x716ac0: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00716ac4: { // 0x716ac4: e837eae2ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7432905u); flags=s.arithmetic_flags;
  }
  L00716ac9: { // 0x716ac9: 8b8d9c010000 MOV ECX, dword ptr [EBP + 0x19c]
    s.cx = m.r32((s.bp+0x0000019cu));
  }
  L00716acf: { // 0x716acf: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716ad1: { // 0x716ad1: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00716ad3: { // 0x716ad3: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00716ad5: { // 0x716ad5: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7432923u); flags=s.arithmetic_flags;
  }
  L00716adb: { // 0x716adb: 8b18 MOV EBX, dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00716add: { // 0x716add: 8b83ac000000 MOV EAX, dword ptr [EBX + 0xac]
    s.ax = m.r32((s.bx+0x000000acu));
  }
  L00716ae3: { // 0x716ae3: 8b8b98000000 MOV ECX, dword ptr [EBX + 0x98]
    s.cx = m.r32((s.bx+0x00000098u));
  }
  L00716ae9: { // 0x716ae9: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00716aed: { // 0x716aed: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00716af1: { // 0x716af1: 8b8740010000 MOV EAX, dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L00716af7: { // 0x716af7: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00716afa: { // 0x716afa: 7423 JZ 0x716b1f
    if(integer::condition("JZ",flags)) goto L00716b1f;
  }
  L00716afc: { // 0x716afc: 0fbe971b010000 MOVSX EDX, byte ptr [EDI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L00716b03: { // 0x716b03: 83c204 ADD EDX, 4
    s.dx = integer::add(s.dx,4u,32,flags);
  }
  L00716b06: { // 0x716b06: 8b85a8000000 MOV EAX, dword ptr [EBP + 0xa8]
    s.ax = m.r32((s.bp+0x000000a8u));
  }
  L00716b0c: { // 0x716b0c: 0faf15c8cfb000 IMUL EDX, dword ptr [0xb0cfc8]
    s.dx = integer::imul(s.dx,m.r32((0x00b0cfc8u)),32,flags);
  }
  L00716b13: { // 0x716b13: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00716b15: { // 0x716b15: 7c08 JL 0x716b1f
    if(integer::condition("JL",flags)) goto L00716b1f;
  }
  L00716b17: { // 0x716b17: 8bb7e8000000 MOV ESI, dword ptr [EDI + 0xe8]
    s.si = m.r32((s.di+0x000000e8u));
  }
  L00716b1d: { // 0x716b1d: eb06 JMP 0x716b25
    goto L00716b25;
  }
  L00716b1f: { // 0x716b1f: 8bb7e4000000 MOV ESI, dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L00716b25: { // 0x716b25: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00716b27: { // 0x716b27: 7448 JZ 0x716b71
    if(integer::condition("JZ",flags)) goto L00716b71;
  }
  L00716b29: { // 0x716b29: 8b859c010000 MOV EAX, dword ptr [EBP + 0x19c]
    s.ax = m.r32((s.bp+0x0000019cu));
  }
  L00716b2f: { // 0x716b2f: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00716b31: { // 0x716b31: 7437 JZ 0x716b6a
    if(integer::condition("JZ",flags)) goto L00716b6a;
  }
  L00716b33: { // 0x716b33: 8a4e7d MOV CL, byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L00716b36: { // 0x716b36: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00716b38: { // 0x716b38: 7430 JZ 0x716b6a
    if(integer::condition("JZ",flags)) goto L00716b6a;
  }
  L00716b3a: { // 0x716b3a: 8a4e74 MOV CL, byte ptr [ESI + 0x74]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000074u)));
  }
  L00716b3d: { // 0x716b3d: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00716b3f: { // 0x716b3f: 7429 JZ 0x716b6a
    if(integer::condition("JZ",flags)) goto L00716b6a;
  }
  L00716b41: { // 0x716b41: 8a4e76 MOV CL, byte ptr [ESI + 0x76]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000076u)));
  }
  L00716b44: { // 0x716b44: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00716b46: { // 0x716b46: 7522 JNZ 0x716b6a
    if(integer::condition("JNZ",flags)) goto L00716b6a;
  }
  L00716b48: { // 0x716b48: 8b4e6c MOV ECX, dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L00716b4b: { // 0x716b4b: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00716b4d: { // 0x716b4d: 7e1b JLE 0x716b6a
    if(integer::condition("JLE",flags)) goto L00716b6a;
  }
  L00716b4f: { // 0x716b4f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00716b51: { // 0x716b51: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716b53: { // 0x716b53: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716b55: { // 0x716b55: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00716b56: { // 0x716b56: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00716b5a: { // 0x716b5a: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00716b5e: { // 0x716b5e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00716b5f: { // 0x716b5f: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716b61: { // 0x716b61: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00716b62: { // 0x716b62: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00716b64: { // 0x716b64: ff9258010000 CALL dword ptr [EDX + 0x158]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000158u)),7433066u); flags=s.arithmetic_flags;
  }
  L00716b6a: { // 0x716b6a: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00716b6d: { // 0x716b6d: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00716b6f: { // 0x716b6f: 75b8 JNZ 0x716b29
    if(integer::condition("JNZ",flags)) goto L00716b29;
  }
  L00716b71: { // 0x716b71: 8b4744 MOV EAX, dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L00716b74: { // 0x716b74: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00716b77: { // 0x716b77: 743b JZ 0x716bb4
    if(integer::condition("JZ",flags)) goto L00716bb4;
  }
  L00716b79: { // 0x716b79: 8b151ce1a100 MOV EDX, dword ptr [0xa1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00716b7f: { // 0x716b7f: 8b3482 MOV ESI, dword ptr [EDX + EAX*4]
    s.si = m.r32((s.dx+(s.ax * 4u)));
  }
  L00716b82: { // 0x716b82: 8a8681020000 MOV AL, byte ptr [ESI + 0x281]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000281u)));
  }
  L00716b88: { // 0x716b88: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00716b8a: { // 0x716b8a: 7410 JZ 0x716b9c
    if(integer::condition("JZ",flags)) goto L00716b9c;
  }
  L00716b8c: { // 0x716b8c: 8b4724 MOV EAX, dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  L00716b8f: { // 0x716b8f: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00716b93: { // 0x716b93: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00716b97: { // 0x716b97: e81473d6ff CALL 0x47deb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047deb0u,7433116u); flags=s.arithmetic_flags;
  }
  L00716b9c: { // 0x716b9c: 8a8678020000 MOV AL, byte ptr [ESI + 0x278]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000278u)));
  }
  L00716ba2: { // 0x716ba2: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00716ba4: { // 0x716ba4: 740e JZ 0x716bb4
    if(integer::condition("JZ",flags)) goto L00716bb4;
  }
  L00716ba6: { // 0x716ba6: 8b8b98000000 MOV ECX, dword ptr [EBX + 0x98]
    s.cx = m.r32((s.bx+0x00000098u));
  }
  L00716bac: { // 0x716bac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00716bad: { // 0x716bad: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00716baf: { // 0x716baf: e82cf0d5ff CALL 0x475be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475be0u,7433140u); flags=s.arithmetic_flags;
  }
  L00716bb4: { // 0x716bb4: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00716bb6: { // 0x716bb6: e8554bd6ff CALL 0x47b710
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b710u,7433147u); flags=s.arithmetic_flags;
  }
  L00716bbb: { // 0x716bbb: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00716bbd: { // 0x716bbd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00716bbe: { // 0x716bbe: 742f JZ 0x716bef
    if(integer::condition("JZ",flags)) goto L00716bef;
  }
  L00716bc0: { // 0x716bc0: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00716bc5: { // 0x716bc5: 8b15881b8200 MOV EDX, dword ptr [0x821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L00716bcb: { // 0x716bcb: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  L00716bcd: { // 0x716bcd: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716bcf: { // 0x716bcf: 8bb20c140000 MOV ESI, dword ptr [EDX + 0x140c]
    s.si = m.r32((s.dx+0x0000140cu));
  }
  L00716bd5: { // 0x716bd5: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00716bdb: { // 0x716bdb: e86092f1ff CALL 0x62fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,7433184u); flags=s.arithmetic_flags;
  }
  L00716be0: { // 0x716be0: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00716be2: { // 0x716be2: 7d0b JGE 0x716bef
    if(integer::condition("JGE",flags)) goto L00716bef;
  }
  L00716be4: { // 0x716be4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00716be5: { // 0x716be5: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00716bea: { // 0x716bea: e85191e4ff CALL 0x55fd40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0055fd40u,7433199u); flags=s.arithmetic_flags;
  }
  L00716bef: { // 0x716bef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00716bf0: { // 0x716bf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00716bf1: { // 0x716bf1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00716bf2: { // 0x716bf2: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00716bf5: { // 0x716bf5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX, word ptr [EDX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+2u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI, word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX, dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002cdab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdab0: { // 0x6cdab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdab1: { // 0x6cdab1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdab2: { // 0x6cdab2: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006cdab6: { // 0x6cdab6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdab8: { // 0x6cdab8: 83ffff CMP EDI, -1
    (void)integer::sub(s.di,4294967295u,32,flags);
  }
  L006cdabb: { // 0x6cdabb: 7507 JNZ 0x6cdac4
    if(integer::condition("JNZ",flags)) goto L006cdac4;
  }
  L006cdabd: { // 0x6cdabd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdabe: { // 0x6cdabe: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdac0: { // 0x6cdac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdac1: { // 0x6cdac1: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006cdac4: { // 0x6cdac4: 8d8e18010000 LEA ECX, [ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L006cdaca: { // 0x6cdaca: e811a50300 CALL 0x707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7133903u); flags=s.arithmetic_flags;
  }
  L006cdacf: { // 0x6cdacf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdad1: { // 0x6cdad1: 741b JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdad3: { // 0x6cdad3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdad5: { // 0x6cdad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdad6: { // 0x6cdad6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdad8: { // 0x6cdad8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133918u); flags=s.arithmetic_flags;
  }
  L006cdade: { // 0x6cdade: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdae0: { // 0x6cdae0: e86b700000 CALL 0x6d4b50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b50u,7133925u); flags=s.arithmetic_flags;
  }
  L006cdae5: { // 0x6cdae5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cdae7: { // 0x6cdae7: 7405 JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdae9: { // 0x6cdae9: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L006cdaec: { // 0x6cdaec: 7512 JNZ 0x6cdb00
    if(integer::condition("JNZ",flags)) goto L006cdb00;
  }
  L006cdaee: { // 0x6cdaee: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdaf0: { // 0x6cdaf0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdaf1: { // 0x6cdaf1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdaf3: { // 0x6cdaf3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7133945u); flags=s.arithmetic_flags;
  }
  L006cdaf9: { // 0x6cdaf9: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdafb: { // 0x6cdafb: e830700000 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,7133952u); flags=s.arithmetic_flags;
  }
  L006cdb00: { // 0x6cdb00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdb01: { // 0x6cdb01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb02: { // 0x6cdb02: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // 0x6b6912: ffa084000000 JMP dword ptr [EAX + 0x84]
    switch(m.r32((s.ax+0x00000084u))){
    case 0x006b6910u: goto L006b6910;
    case 0x006b6912u: goto L006b6912;
    default:s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.ax+0x00000084u))); return;}
  }
}
void f_0001b600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b600: { // 0x41b600: 8b81ac050000 MOV EAX, dword ptr [ECX + 0x5ac]
    s.ax = m.r32((s.cx+0x000005acu));
  }
  L0041b606: { // 0x41b606: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX, [ECX + EDX*4 + 0x74c]
    s.ax = (s.cx+(s.dx * 4u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007b710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b710: { // 0x47b710: 8b4138 MOV EAX, dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b713: { // 0x47b713: 8b0d305da500 MOV ECX, dword ptr [0xa55d30]
    s.cx = m.r32((0x00a55d30u));
  }
  L0047b719: { // 0x47b719: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b71b: { // 0x47b71b: 7503 JNZ 0x47b720
    if(integer::condition("JNZ",flags)) goto L0047b720;
  }
  L0047b71d: { // 0x47b71d: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0047b71f: { // 0x47b71f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b720: { // 0x47b720: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0047b721: { // 0x47b721: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b723: { // 0x47b723: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0047b726: { // 0x47b726: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x62fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x62fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX, EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI, 0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX, 0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x62fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x62fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI, EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x62fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP, 0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP, CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX, [EDI + 1]
    s.ax = (s.di+1u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x62fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX], 0
    (void)integer::sub(m.r8((s.dx)),0u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x62fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x62fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI, dword ptr [EDX + ECX*4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 4u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX, [EDX + ECX*4 + 0xc]
    s.ax = (s.dx+(s.cx * 4u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX, dword ptr [EDX + ECX*4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 4u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI, ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX], ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX, dword ptr [EDX + 4]
    s.ax = m.r32((s.dx+4u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI, dword ptr [EDX + EAX*4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 4u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX, 0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 4], EAX
    m.w32((s.dx+4u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x62fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 4], 0
    m.w32((s.dx+4u), 0u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX, 0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x62fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 8], 0
    m.w32((s.dx+8u), 0u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX, EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x62fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7432816u:f_00316a70(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 7133872u:f_002cdab0(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4306432u:f_0001b600(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 4699920u:f_0007b710(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
default:throw std::domain_error("recovery1549 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ switch(target){case 0x41b600u:f_0001b600(m,s,f,{});return;default:throw std::domain_error("B1549 unreviewed tail");} } }

std::uint32_t fun_00716a70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00716a70: { // 0x716a70: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00716a73: { // 0x716a73: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00716a74: { // 0x716a74: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L00716a76: { // 0x716a76: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00716a77: { // 0x716a77: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00716a78: { // 0x716a78: 8b859c010000 MOV EAX, dword ptr [EBP + 0x19c]
    s.ax = m.r32((s.bp+0x0000019cu));
  }
  L00716a7e: { // 0x716a7e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00716a80: { // 0x716a80: 0f8469010000 JZ 0x716bef
    if(integer::condition("JZ",flags)) goto L00716bef;
  }
  L00716a86: { // 0x716a86: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00716a8a: { // 0x716a8a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00716a8b: { // 0x716a8b: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00716a8d: { // 0x716a8d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00716a8e: { // 0x716a8e: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00716a94: { // 0x716a94: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00716a96: { // 0x716a96: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00716a99: { // 0x716a99: 668944241c MOV word ptr [ESP + 0x1c], AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L00716a9e: { // 0x716a9e: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00716aa1: { // 0x716aa1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00716aa2: { // 0x716aa2: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00716aa8: { // 0x716aa8: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00716aac: { // 0x716aac: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00716aae: { // 0x716aae: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00716aaf: { // 0x716aaf: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00716ab2: { // 0x716ab2: 6689442422 MOV word ptr [ESP + 0x22], AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L00716ab7: { // 0x716ab7: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00716abb: { // 0x716abb: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00716ac0: { // 0x716ac0: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00716ac4: { // 0x716ac4: e837eae2ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7432905u); flags=s.arithmetic_flags;
  }
  L00716ac9: { // 0x716ac9: 8b8d9c010000 MOV ECX, dword ptr [EBP + 0x19c]
    s.cx = m.r32((s.bp+0x0000019cu));
  }
  L00716acf: { // 0x716acf: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716ad1: { // 0x716ad1: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00716ad3: { // 0x716ad3: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00716ad5: { // 0x716ad5: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7432923u); flags=s.arithmetic_flags;
  }
  L00716adb: { // 0x716adb: 8b18 MOV EBX, dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00716add: { // 0x716add: 8b83ac000000 MOV EAX, dword ptr [EBX + 0xac]
    s.ax = m.r32((s.bx+0x000000acu));
  }
  L00716ae3: { // 0x716ae3: 8b8b98000000 MOV ECX, dword ptr [EBX + 0x98]
    s.cx = m.r32((s.bx+0x00000098u));
  }
  L00716ae9: { // 0x716ae9: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00716aed: { // 0x716aed: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00716af1: { // 0x716af1: 8b8740010000 MOV EAX, dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L00716af7: { // 0x716af7: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00716afa: { // 0x716afa: 7423 JZ 0x716b1f
    if(integer::condition("JZ",flags)) goto L00716b1f;
  }
  L00716afc: { // 0x716afc: 0fbe971b010000 MOVSX EDX, byte ptr [EDI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L00716b03: { // 0x716b03: 83c204 ADD EDX, 4
    s.dx = integer::add(s.dx,4u,32,flags);
  }
  L00716b06: { // 0x716b06: 8b85a8000000 MOV EAX, dword ptr [EBP + 0xa8]
    s.ax = m.r32((s.bp+0x000000a8u));
  }
  L00716b0c: { // 0x716b0c: 0faf15c8cfb000 IMUL EDX, dword ptr [0xb0cfc8]
    s.dx = integer::imul(s.dx,m.r32((0x00b0cfc8u)),32,flags);
  }
  L00716b13: { // 0x716b13: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00716b15: { // 0x716b15: 7c08 JL 0x716b1f
    if(integer::condition("JL",flags)) goto L00716b1f;
  }
  L00716b17: { // 0x716b17: 8bb7e8000000 MOV ESI, dword ptr [EDI + 0xe8]
    s.si = m.r32((s.di+0x000000e8u));
  }
  L00716b1d: { // 0x716b1d: eb06 JMP 0x716b25
    goto L00716b25;
  }
  L00716b1f: { // 0x716b1f: 8bb7e4000000 MOV ESI, dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L00716b25: { // 0x716b25: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00716b27: { // 0x716b27: 7448 JZ 0x716b71
    if(integer::condition("JZ",flags)) goto L00716b71;
  }
  L00716b29: { // 0x716b29: 8b859c010000 MOV EAX, dword ptr [EBP + 0x19c]
    s.ax = m.r32((s.bp+0x0000019cu));
  }
  L00716b2f: { // 0x716b2f: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00716b31: { // 0x716b31: 7437 JZ 0x716b6a
    if(integer::condition("JZ",flags)) goto L00716b6a;
  }
  L00716b33: { // 0x716b33: 8a4e7d MOV CL, byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L00716b36: { // 0x716b36: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00716b38: { // 0x716b38: 7430 JZ 0x716b6a
    if(integer::condition("JZ",flags)) goto L00716b6a;
  }
  L00716b3a: { // 0x716b3a: 8a4e74 MOV CL, byte ptr [ESI + 0x74]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000074u)));
  }
  L00716b3d: { // 0x716b3d: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00716b3f: { // 0x716b3f: 7429 JZ 0x716b6a
    if(integer::condition("JZ",flags)) goto L00716b6a;
  }
  L00716b41: { // 0x716b41: 8a4e76 MOV CL, byte ptr [ESI + 0x76]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000076u)));
  }
  L00716b44: { // 0x716b44: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00716b46: { // 0x716b46: 7522 JNZ 0x716b6a
    if(integer::condition("JNZ",flags)) goto L00716b6a;
  }
  L00716b48: { // 0x716b48: 8b4e6c MOV ECX, dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L00716b4b: { // 0x716b4b: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00716b4d: { // 0x716b4d: 7e1b JLE 0x716b6a
    if(integer::condition("JLE",flags)) goto L00716b6a;
  }
  L00716b4f: { // 0x716b4f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00716b51: { // 0x716b51: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716b53: { // 0x716b53: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716b55: { // 0x716b55: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00716b56: { // 0x716b56: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00716b5a: { // 0x716b5a: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00716b5e: { // 0x716b5e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00716b5f: { // 0x716b5f: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716b61: { // 0x716b61: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00716b62: { // 0x716b62: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00716b64: { // 0x716b64: ff9258010000 CALL dword ptr [EDX + 0x158]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000158u)),7433066u); flags=s.arithmetic_flags;
  }
  L00716b6a: { // 0x716b6a: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00716b6d: { // 0x716b6d: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00716b6f: { // 0x716b6f: 75b8 JNZ 0x716b29
    if(integer::condition("JNZ",flags)) goto L00716b29;
  }
  L00716b71: { // 0x716b71: 8b4744 MOV EAX, dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L00716b74: { // 0x716b74: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00716b77: { // 0x716b77: 743b JZ 0x716bb4
    if(integer::condition("JZ",flags)) goto L00716bb4;
  }
  L00716b79: { // 0x716b79: 8b151ce1a100 MOV EDX, dword ptr [0xa1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00716b7f: { // 0x716b7f: 8b3482 MOV ESI, dword ptr [EDX + EAX*4]
    s.si = m.r32((s.dx+(s.ax * 4u)));
  }
  L00716b82: { // 0x716b82: 8a8681020000 MOV AL, byte ptr [ESI + 0x281]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000281u)));
  }
  L00716b88: { // 0x716b88: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00716b8a: { // 0x716b8a: 7410 JZ 0x716b9c
    if(integer::condition("JZ",flags)) goto L00716b9c;
  }
  L00716b8c: { // 0x716b8c: 8b4724 MOV EAX, dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  L00716b8f: { // 0x716b8f: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00716b93: { // 0x716b93: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00716b97: { // 0x716b97: e81473d6ff CALL 0x47deb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047deb0u,7433116u); flags=s.arithmetic_flags;
  }
  L00716b9c: { // 0x716b9c: 8a8678020000 MOV AL, byte ptr [ESI + 0x278]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000278u)));
  }
  L00716ba2: { // 0x716ba2: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00716ba4: { // 0x716ba4: 740e JZ 0x716bb4
    if(integer::condition("JZ",flags)) goto L00716bb4;
  }
  L00716ba6: { // 0x716ba6: 8b8b98000000 MOV ECX, dword ptr [EBX + 0x98]
    s.cx = m.r32((s.bx+0x00000098u));
  }
  L00716bac: { // 0x716bac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00716bad: { // 0x716bad: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00716baf: { // 0x716baf: e82cf0d5ff CALL 0x475be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475be0u,7433140u); flags=s.arithmetic_flags;
  }
  L00716bb4: { // 0x716bb4: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00716bb6: { // 0x716bb6: e8554bd6ff CALL 0x47b710
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b710u,7433147u); flags=s.arithmetic_flags;
  }
  L00716bbb: { // 0x716bbb: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00716bbd: { // 0x716bbd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00716bbe: { // 0x716bbe: 742f JZ 0x716bef
    if(integer::condition("JZ",flags)) goto L00716bef;
  }
  L00716bc0: { // 0x716bc0: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00716bc5: { // 0x716bc5: 8b15881b8200 MOV EDX, dword ptr [0x821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L00716bcb: { // 0x716bcb: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  L00716bcd: { // 0x716bcd: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00716bcf: { // 0x716bcf: 8bb20c140000 MOV ESI, dword ptr [EDX + 0x140c]
    s.si = m.r32((s.dx+0x0000140cu));
  }
  L00716bd5: { // 0x716bd5: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00716bdb: { // 0x716bdb: e86092f1ff CALL 0x62fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,7433184u); flags=s.arithmetic_flags;
  }
  L00716be0: { // 0x716be0: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00716be2: { // 0x716be2: 7d0b JGE 0x716bef
    if(integer::condition("JGE",flags)) goto L00716bef;
  }
  L00716be4: { // 0x716be4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00716be5: { // 0x716be5: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00716bea: { // 0x716bea: e85191e4ff CALL 0x55fd40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0055fd40u,7433199u); flags=s.arithmetic_flags;
  }
  L00716bef: { // 0x716bef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00716bf0: { // 0x716bf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00716bf1: { // 0x716bf1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00716bf2: { // 0x716bf2: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00716bf5: { // 0x716bf5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
