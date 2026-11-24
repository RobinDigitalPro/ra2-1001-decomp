#include "recovered/recovery_b1558_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1558 {
namespace {
void f_0016f060(Memory&,State&,Frame&,const Operations&);
void f_0016f6c0(Memory&,State&,Frame&,const Operations&);
void f_00180430(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_001721e0(Memory&,State&,Frame&,const Operations&);
void f_00172700(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0018a810(Memory&,State&,Frame&,const Operations&);
void f_0016b760(Memory&,State&,Frame&,const Operations&);
void f_00172ad0(Memory&,State&,Frame&,const Operations&);
void f_001851f0(Memory&,State&,Frame&,const Operations&);
void f_0001c300(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0016f060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056f060: { // 0x56f060: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0056f063: { // 0x56f063: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0056f067: { // 0x56f067: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056f068: { // 0x56f068: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056f069: { // 0x56f069: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056f06a: { // 0x56f06a: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0056f06e: { // 0x56f06e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f06f: { // 0x56f06f: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0056f073: { // 0x56f073: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0056f075: { // 0x56f075: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f076: { // 0x56f076: 8d4c2417 LEA ECX,[ESP + 0x17]
    s.cx = (f.sp+0x00000017u);
  }
  L0056f07a: { // 0x56f07a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f07b: { // 0x56f07b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f07c: { // 0x56f07c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056f07d: { // 0x56f07d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f07f: { // 0x56f07f: c644242301 MOV byte ptr [ESP + 0x23],0x1
    m.w8((f.sp+0x00000023u), 0x00000001u);
  }
  L0056f084: { // 0x56f084: e837060000 CALL 0x0056f6c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056f6c0u,5697673u); flags=s.arithmetic_flags;
  }
  L0056f089: { // 0x56f089: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0056f08b: { // 0x56f08b: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0056f08f: { // 0x56f08f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056f091: { // 0x56f091: 750c JNZ 0x0056f09f
    if(integer::condition("JNZ",flags)) goto L0056f09f;
  }
  L0056f093: { // 0x56f093: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f094: { // 0x56f094: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f095: { // 0x56f095: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f096: { // 0x56f096: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056f098: { // 0x56f098: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f099: { // 0x56f099: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0056f09c: { // 0x56f09c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0056f09f: { // 0x56f09f: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L0056f0a1: { // 0x56f0a1: 81fbff000000 CMP EBX,0xff
    (void)integer::sub(s.bx,0x000000ffu,32,flags);
  }
  L0056f0a7: { // 0x56f0a7: 750c JNZ 0x0056f0b5
    if(integer::condition("JNZ",flags)) goto L0056f0b5;
  }
  L0056f0a9: { // 0x56f0a9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f0aa: { // 0x56f0aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f0ab: { // 0x56f0ab: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f0ac: { // 0x56f0ac: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056f0ae: { // 0x56f0ae: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f0af: { // 0x56f0af: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0056f0b2: { // 0x56f0b2: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0056f0b5: { // 0x56f0b5: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f0b7: { // 0x56f0b7: 81e282000000 AND EDX,0x82
    s.dx = integer::logical((s.dx)&(0x00000082u),32,flags);
  }
  L0056f0bd: { // 0x56f0bd: 80fa82 CMP DL,0x82
    (void)integer::sub((s.dx & 0xffu),0x00000082u,8,flags);
  }
  L0056f0c0: { // 0x56f0c0: 755a JNZ 0x0056f11c
    if(integer::condition("JNZ",flags)) goto L0056f11c;
  }
  L0056f0c2: { // 0x56f0c2: f6c338 TEST BL,0x38
    (void)integer::logical(((s.bx & 0xffu))&(0x00000038u),8,flags);
  }
  L0056f0c5: { // 0x56f0c5: 7555 JNZ 0x0056f11c
    if(integer::condition("JNZ",flags)) goto L0056f11c;
  }
  L0056f0c7: { // 0x56f0c7: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f0ca: { // 0x56f0ca: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L0056f0cd: { // 0x56f0cd: 83c005 ADD EAX,0x5
    s.ax = integer::add(s.ax,0x00000005u,32,flags);
  }
  L0056f0d0: { // 0x56f0d0: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f0d5: { // 0x56f0d5: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f0d9: { // 0x56f0d9: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f0de: { // 0x56f0de: 8d51fb LEA EDX,[ECX + -0x5]
    s.dx = (s.cx-0x00000005u);
  }
  L0056f0e1: { // 0x56f0e1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0056f0e2: { // 0x56f0e2: f6c340 TEST BL,0x40
    (void)integer::logical(((s.bx & 0xffu))&(0x00000040u),8,flags);
  }
  L0056f0e5: { // 0x56f0e5: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f0ea: { // 0x56f0ea: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f0ef: { // 0x56f0ef: 7405 JZ 0x0056f0f6
    if(integer::condition("JZ",flags)) goto L0056f0f6;
  }
  L0056f0f1: { // 0x56f0f1: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f0f6: { // 0x56f0f6: f6c304 TEST BL,0x4
    (void)integer::logical(((s.bx & 0xffu))&(0x00000004u),8,flags);
  }
  L0056f0f9: { // 0x56f0f9: 7405 JZ 0x0056f100
    if(integer::condition("JZ",flags)) goto L0056f100;
  }
  L0056f0fb: { // 0x56f0fb: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f100: { // 0x56f100: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f104: { // 0x56f104: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f105: { // 0x56f105: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f109: { // 0x56f109: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f10a: { // 0x56f10a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f10b: { // 0x56f10b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f10d: { // 0x56f10d: e8ce300000 CALL 0x005721e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005721e0u,5697810u); flags=s.arithmetic_flags;
  }
  L0056f112: { // 0x56f112: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f114: { // 0x56f114: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f116: { // 0x56f116: 0f855f040000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f11c: { // 0x56f11c: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f11e: { // 0x56f11e: 83e20a AND EDX,0xa
    s.dx = integer::logical((s.dx)&(0x0000000au),32,flags);
  }
  L0056f121: { // 0x56f121: 80fa0a CMP DL,0xa
    (void)integer::sub((s.dx & 0xffu),0x0000000au,8,flags);
  }
  L0056f124: { // 0x56f124: 755a JNZ 0x0056f180
    if(integer::condition("JNZ",flags)) goto L0056f180;
  }
  L0056f126: { // 0x56f126: f6c311 TEST BL,0x11
    (void)integer::logical(((s.bx & 0xffu))&(0x00000011u),8,flags);
  }
  L0056f129: { // 0x56f129: 7555 JNZ 0x0056f180
    if(integer::condition("JNZ",flags)) goto L0056f180;
  }
  L0056f12b: { // 0x56f12b: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f12e: { // 0x56f12e: 8d4805 LEA ECX,[EAX + 0x5]
    s.cx = (s.ax+0x00000005u);
  }
  L0056f131: { // 0x56f131: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f132: { // 0x56f132: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f137: { // 0x56f137: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f13b: { // 0x56f13b: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f140: { // 0x56f140: 8d51ff LEA EDX,[ECX + -0x1]
    s.dx = (s.cx-0x00000001u);
  }
  L0056f143: { // 0x56f143: 83c105 ADD ECX,0x5
    s.cx = integer::add(s.cx,0x00000005u,32,flags);
  }
  L0056f146: { // 0x56f146: f6c310 TEST BL,0x10
    (void)integer::logical(((s.bx & 0xffu))&(0x00000010u),8,flags);
  }
  L0056f149: { // 0x56f149: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f14e: { // 0x56f14e: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f153: { // 0x56f153: 7405 JZ 0x0056f15a
    if(integer::condition("JZ",flags)) goto L0056f15a;
  }
  L0056f155: { // 0x56f155: 66ff4c2426 DEC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::decrement(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f15a: { // 0x56f15a: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L0056f15d: { // 0x56f15d: 7405 JZ 0x0056f164
    if(integer::condition("JZ",flags)) goto L0056f164;
  }
  L0056f15f: { // 0x56f15f: 66ff4c2414 DEC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::decrement(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f164: { // 0x56f164: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f168: { // 0x56f168: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f169: { // 0x56f169: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f16d: { // 0x56f16d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f16e: { // 0x56f16e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f16f: { // 0x56f16f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f171: { // 0x56f171: e8ca2a0000 CALL 0x00571c40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00571c40u,5697910u); flags=s.arithmetic_flags;
  }
  L0056f176: { // 0x56f176: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f178: { // 0x56f178: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f17a: { // 0x56f17a: 0f85fb030000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f180: { // 0x56f180: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f182: { // 0x56f182: 83e228 AND EDX,0x28
    s.dx = integer::logical((s.dx)&(0x00000028u),32,flags);
  }
  L0056f185: { // 0x56f185: 80fa28 CMP DL,0x28
    (void)integer::sub((s.dx & 0xffu),0x00000028u,8,flags);
  }
  L0056f188: { // 0x56f188: 755a JNZ 0x0056f1e4
    if(integer::condition("JNZ",flags)) goto L0056f1e4;
  }
  L0056f18a: { // 0x56f18a: f6c383 TEST BL,0x83
    (void)integer::logical(((s.bx & 0xffu))&(0x00000083u),8,flags);
  }
  L0056f18d: { // 0x56f18d: 7555 JNZ 0x0056f1e4
    if(integer::condition("JNZ",flags)) goto L0056f1e4;
  }
  L0056f18f: { // 0x56f18f: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f192: { // 0x56f192: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L0056f195: { // 0x56f195: 83c0fb ADD EAX,-0x5
    s.ax = integer::add(s.ax,0xfffffffbu,32,flags);
  }
  L0056f198: { // 0x56f198: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f19d: { // 0x56f19d: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f1a1: { // 0x56f1a1: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f1a6: { // 0x56f1a6: 8d5105 LEA EDX,[ECX + 0x5]
    s.dx = (s.cx+0x00000005u);
  }
  L0056f1a9: { // 0x56f1a9: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0056f1aa: { // 0x56f1aa: f6c340 TEST BL,0x40
    (void)integer::logical(((s.bx & 0xffu))&(0x00000040u),8,flags);
  }
  L0056f1ad: { // 0x56f1ad: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f1b2: { // 0x56f1b2: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f1b7: { // 0x56f1b7: 7405 JZ 0x0056f1be
    if(integer::condition("JZ",flags)) goto L0056f1be;
  }
  L0056f1b9: { // 0x56f1b9: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f1be: { // 0x56f1be: f6c304 TEST BL,0x4
    (void)integer::logical(((s.bx & 0xffu))&(0x00000004u),8,flags);
  }
  L0056f1c1: { // 0x56f1c1: 7405 JZ 0x0056f1c8
    if(integer::condition("JZ",flags)) goto L0056f1c8;
  }
  L0056f1c3: { // 0x56f1c3: 66ff4c2416 DEC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::decrement(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f1c8: { // 0x56f1c8: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f1cc: { // 0x56f1cc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f1cd: { // 0x56f1cd: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f1d1: { // 0x56f1d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f1d2: { // 0x56f1d2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f1d3: { // 0x56f1d3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f1d5: { // 0x56f1d5: e846250000 CALL 0x00571720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00571720u,5698010u); flags=s.arithmetic_flags;
  }
  L0056f1da: { // 0x56f1da: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f1dc: { // 0x56f1dc: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f1de: { // 0x56f1de: 0f8597030000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f1e4: { // 0x56f1e4: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f1e6: { // 0x56f1e6: 81e2a0000000 AND EDX,0xa0
    s.dx = integer::logical((s.dx)&(0x000000a0u),32,flags);
  }
  L0056f1ec: { // 0x56f1ec: 80faa0 CMP DL,0xa0
    (void)integer::sub((s.dx & 0xffu),0x000000a0u,8,flags);
  }
  L0056f1ef: { // 0x56f1ef: 755a JNZ 0x0056f24b
    if(integer::condition("JNZ",flags)) goto L0056f24b;
  }
  L0056f1f1: { // 0x56f1f1: f6c30e TEST BL,0xe
    (void)integer::logical(((s.bx & 0xffu))&(0x0000000eu),8,flags);
  }
  L0056f1f4: { // 0x56f1f4: 7555 JNZ 0x0056f24b
    if(integer::condition("JNZ",flags)) goto L0056f24b;
  }
  L0056f1f6: { // 0x56f1f6: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f1f9: { // 0x56f1f9: 8d48fb LEA ECX,[EAX + -0x5]
    s.cx = (s.ax-0x00000005u);
  }
  L0056f1fc: { // 0x56f1fc: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056f1fd: { // 0x56f1fd: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f202: { // 0x56f202: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f206: { // 0x56f206: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f20b: { // 0x56f20b: 8d5101 LEA EDX,[ECX + 0x1]
    s.dx = (s.cx+0x00000001u);
  }
  L0056f20e: { // 0x56f20e: 83c1fb ADD ECX,-0x5
    s.cx = integer::add(s.cx,0xfffffffbu,32,flags);
  }
  L0056f211: { // 0x56f211: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L0056f214: { // 0x56f214: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f219: { // 0x56f219: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f21e: { // 0x56f21e: 7405 JZ 0x0056f225
    if(integer::condition("JZ",flags)) goto L0056f225;
  }
  L0056f220: { // 0x56f220: 66ff442426 INC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::increment(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f225: { // 0x56f225: f6c310 TEST BL,0x10
    (void)integer::logical(((s.bx & 0xffu))&(0x00000010u),8,flags);
  }
  L0056f228: { // 0x56f228: 7405 JZ 0x0056f22f
    if(integer::condition("JZ",flags)) goto L0056f22f;
  }
  L0056f22a: { // 0x56f22a: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f22f: { // 0x56f22f: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f233: { // 0x56f233: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f234: { // 0x56f234: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f238: { // 0x56f238: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f239: { // 0x56f239: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f23a: { // 0x56f23a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f23c: { // 0x56f23c: e8df240000 CALL 0x00571720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00571720u,5698113u); flags=s.arithmetic_flags;
  }
  L0056f241: { // 0x56f241: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f243: { // 0x56f243: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f245: { // 0x56f245: 0f8530030000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f24b: { // 0x56f24b: f6c370 TEST BL,0x70
    (void)integer::logical(((s.bx & 0xffu))&(0x00000070u),8,flags);
  }
  L0056f24e: { // 0x56f24e: 0f85c4000000 JNZ 0x0056f318
    if(integer::condition("JNZ",flags)) goto L0056f318;
  }
  L0056f254: { // 0x56f254: f6c388 TEST BL,0x88
    (void)integer::logical(((s.bx & 0xffu))&(0x00000088u),8,flags);
  }
  L0056f257: { // 0x56f257: 0f84bb000000 JZ 0x0056f318
    if(integer::condition("JZ",flags)) goto L0056f318;
  }
  L0056f25d: { // 0x56f25d: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f261: { // 0x56f261: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f264: { // 0x56f264: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f266: { // 0x56f266: 8d51fc LEA EDX,[ECX + -0x4]
    s.dx = (s.cx-0x00000004u);
  }
  L0056f269: { // 0x56f269: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0056f26c: { // 0x56f26c: f6c380 TEST BL,0x80
    (void)integer::logical(((s.bx & 0xffu))&(0x00000080u),8,flags);
  }
  L0056f26f: { // 0x56f26f: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0056f274: { // 0x56f274: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f279: { // 0x56f279: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f27e: { // 0x56f27e: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f283: { // 0x56f283: 740a JZ 0x0056f28f
    if(integer::condition("JZ",flags)) goto L0056f28f;
  }
  L0056f285: { // 0x56f285: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f28a: { // 0x56f28a: 66ff442426 INC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::increment(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f28f: { // 0x56f28f: f6c308 TEST BL,0x8
    (void)integer::logical(((s.bx & 0xffu))&(0x00000008u),8,flags);
  }
  L0056f292: { // 0x56f292: 740a JZ 0x0056f29e
    if(integer::condition("JZ",flags)) goto L0056f29e;
  }
  L0056f294: { // 0x56f294: 66ff4c2426 DEC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::decrement(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f299: { // 0x56f299: 66ff4c2416 DEC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::decrement(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f29e: { // 0x56f29e: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f2a3: { // 0x56f2a3: e8380b0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698216u); flags=s.arithmetic_flags;
  }
  L0056f2a8: { // 0x56f2a8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f2ac: { // 0x56f2ac: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f2b4: { // 0x56f2b4: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f2b8: { // 0x56f2b8: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f2be: { // 0x56f2be: e88db71f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698243u); flags=s.arithmetic_flags;
  }
  L0056f2c3: { // 0x56f2c3: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f2c6: { // 0x56f2c6: 77d6 JA 0x0056f29e
    if(integer::condition("JA",flags)) goto L0056f29e;
  }
  L0056f2c8: { // 0x56f2c8: 6601442414 ADD word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), integer::add(m.r16((f.sp+0x00000014u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f2cd: { // 0x56f2cd: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f2d2: { // 0x56f2d2: e8090b0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698263u); flags=s.arithmetic_flags;
  }
  L0056f2d7: { // 0x56f2d7: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f2db: { // 0x56f2db: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f2e3: { // 0x56f2e3: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f2e7: { // 0x56f2e7: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f2ed: { // 0x56f2ed: e85eb71f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698290u); flags=s.arithmetic_flags;
  }
  L0056f2f2: { // 0x56f2f2: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f2f5: { // 0x56f2f5: 77d6 JA 0x0056f2cd
    if(integer::condition("JA",flags)) goto L0056f2cd;
  }
  L0056f2f7: { // 0x56f2f7: 6601442424 ADD word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), integer::add(m.r16((f.sp+0x00000024u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f2fc: { // 0x56f2fc: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f300: { // 0x56f300: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f301: { // 0x56f301: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f305: { // 0x56f305: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f306: { // 0x56f306: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f307: { // 0x56f307: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f309: { // 0x56f309: e822180000 CALL 0x00570b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570b30u,5698318u); flags=s.arithmetic_flags;
  }
  L0056f30e: { // 0x56f30e: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f310: { // 0x56f310: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f312: { // 0x56f312: 0f8563020000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f318: { // 0x56f318: f6c307 TEST BL,0x7
    (void)integer::logical(((s.bx & 0xffu))&(0x00000007u),8,flags);
  }
  L0056f31b: { // 0x56f31b: 0f85c6000000 JNZ 0x0056f3e7
    if(integer::condition("JNZ",flags)) goto L0056f3e7;
  }
  L0056f321: { // 0x56f321: f6c388 TEST BL,0x88
    (void)integer::logical(((s.bx & 0xffu))&(0x00000088u),8,flags);
  }
  L0056f324: { // 0x56f324: 0f84bd000000 JZ 0x0056f3e7
    if(integer::condition("JZ",flags)) goto L0056f3e7;
  }
  L0056f32a: { // 0x56f32a: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f32e: { // 0x56f32e: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f331: { // 0x56f331: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f333: { // 0x56f333: 8d5104 LEA EDX,[ECX + 0x4]
    s.dx = (s.cx+0x00000004u);
  }
  L0056f336: { // 0x56f336: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f339: { // 0x56f339: f6c380 TEST BL,0x80
    (void)integer::logical(((s.bx & 0xffu))&(0x00000080u),8,flags);
  }
  L0056f33c: { // 0x56f33c: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0056f341: { // 0x56f341: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f346: { // 0x56f346: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f34b: { // 0x56f34b: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f350: { // 0x56f350: 740a JZ 0x0056f35c
    if(integer::condition("JZ",flags)) goto L0056f35c;
  }
  L0056f352: { // 0x56f352: 66ff442426 INC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::increment(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f357: { // 0x56f357: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f35c: { // 0x56f35c: f6c308 TEST BL,0x8
    (void)integer::logical(((s.bx & 0xffu))&(0x00000008u),8,flags);
  }
  L0056f35f: { // 0x56f35f: 740a JZ 0x0056f36b
    if(integer::condition("JZ",flags)) goto L0056f36b;
  }
  L0056f361: { // 0x56f361: 66ff4c2416 DEC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::decrement(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f366: { // 0x56f366: 66ff4c2426 DEC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::decrement(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f36b: { // 0x56f36b: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f370: { // 0x56f370: e86b0a0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698421u); flags=s.arithmetic_flags;
  }
  L0056f375: { // 0x56f375: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f379: { // 0x56f379: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f381: { // 0x56f381: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f385: { // 0x56f385: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f38b: { // 0x56f38b: e8c0b61f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698448u); flags=s.arithmetic_flags;
  }
  L0056f390: { // 0x56f390: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f393: { // 0x56f393: 77d6 JA 0x0056f36b
    if(integer::condition("JA",flags)) goto L0056f36b;
  }
  L0056f395: { // 0x56f395: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f396: { // 0x56f396: 6601442414 ADD word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), integer::add(m.r16((f.sp+0x00000014u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f39b: { // 0x56f39b: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f3a0: { // 0x56f3a0: e83b0a0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698469u); flags=s.arithmetic_flags;
  }
  L0056f3a5: { // 0x56f3a5: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f3a9: { // 0x56f3a9: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f3b1: { // 0x56f3b1: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f3b5: { // 0x56f3b5: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f3bb: { // 0x56f3bb: e890b61f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698496u); flags=s.arithmetic_flags;
  }
  L0056f3c0: { // 0x56f3c0: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f3c3: { // 0x56f3c3: 77d6 JA 0x0056f39b
    if(integer::condition("JA",flags)) goto L0056f39b;
  }
  L0056f3c5: { // 0x56f3c5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f3c6: { // 0x56f3c6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f3c7: { // 0x56f3c7: 6601442428 ADD word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), integer::add(m.r16((f.sp+0x00000028u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f3cc: { // 0x56f3cc: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0056f3d0: { // 0x56f3d0: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f3d4: { // 0x56f3d4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f3d5: { // 0x56f3d5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f3d6: { // 0x56f3d6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f3d8: { // 0x56f3d8: e8530a0000 CALL 0x0056fe30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056fe30u,5698525u); flags=s.arithmetic_flags;
  }
  L0056f3dd: { // 0x56f3dd: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f3df: { // 0x56f3df: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f3e1: { // 0x56f3e1: 0f8594010000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f3e7: { // 0x56f3e7: f6c3c1 TEST BL,0xc1
    (void)integer::logical(((s.bx & 0xffu))&(0x000000c1u),8,flags);
  }
  L0056f3ea: { // 0x56f3ea: 0f85c4000000 JNZ 0x0056f4b4
    if(integer::condition("JNZ",flags)) goto L0056f4b4;
  }
  L0056f3f0: { // 0x56f3f0: f6c322 TEST BL,0x22
    (void)integer::logical(((s.bx & 0xffu))&(0x00000022u),8,flags);
  }
  L0056f3f3: { // 0x56f3f3: 0f84bb000000 JZ 0x0056f4b4
    if(integer::condition("JZ",flags)) goto L0056f4b4;
  }
  L0056f3f9: { // 0x56f3f9: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f3fc: { // 0x56f3fc: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f400: { // 0x56f400: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f402: { // 0x56f402: 8d5104 LEA EDX,[ECX + 0x4]
    s.dx = (s.cx+0x00000004u);
  }
  L0056f405: { // 0x56f405: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f408: { // 0x56f408: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  L0056f40b: { // 0x56f40b: 6689542414 MOV word ptr [ESP + 0x14],DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L0056f410: { // 0x56f410: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0056f415: { // 0x56f415: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L0056f41a: { // 0x56f41a: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f41f: { // 0x56f41f: 740a JZ 0x0056f42b
    if(integer::condition("JZ",flags)) goto L0056f42b;
  }
  L0056f421: { // 0x56f421: 66ff442424 INC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::increment(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f426: { // 0x56f426: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f42b: { // 0x56f42b: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L0056f42e: { // 0x56f42e: 740a JZ 0x0056f43a
    if(integer::condition("JZ",flags)) goto L0056f43a;
  }
  L0056f430: { // 0x56f430: 66ff4c2414 DEC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::decrement(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f435: { // 0x56f435: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f43a: { // 0x56f43a: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f43f: { // 0x56f43f: e89c090c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698628u); flags=s.arithmetic_flags;
  }
  L0056f444: { // 0x56f444: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f448: { // 0x56f448: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f450: { // 0x56f450: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f454: { // 0x56f454: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f45a: { // 0x56f45a: e8f1b51f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698655u); flags=s.arithmetic_flags;
  }
  L0056f45f: { // 0x56f45f: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f462: { // 0x56f462: 77d6 JA 0x0056f43a
    if(integer::condition("JA",flags)) goto L0056f43a;
  }
  L0056f464: { // 0x56f464: 6601442416 ADD word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), integer::add(m.r16((f.sp+0x00000016u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f469: { // 0x56f469: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f46e: { // 0x56f46e: e86d090c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698675u); flags=s.arithmetic_flags;
  }
  L0056f473: { // 0x56f473: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f477: { // 0x56f477: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f47f: { // 0x56f47f: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f483: { // 0x56f483: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f489: { // 0x56f489: e8c2b51f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698702u); flags=s.arithmetic_flags;
  }
  L0056f48e: { // 0x56f48e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f491: { // 0x56f491: 77d6 JA 0x0056f469
    if(integer::condition("JA",flags)) goto L0056f469;
  }
  L0056f493: { // 0x56f493: 6601442426 ADD word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), integer::add(m.r16((f.sp+0x00000026u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f498: { // 0x56f498: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f49c: { // 0x56f49c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f49d: { // 0x56f49d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f4a1: { // 0x56f4a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f4a2: { // 0x56f4a2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f4a3: { // 0x56f4a3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f4a5: { // 0x56f4a5: e8c60f0000 CALL 0x00570470
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570470u,5698730u); flags=s.arithmetic_flags;
  }
  L0056f4aa: { // 0x56f4aa: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f4ac: { // 0x56f4ac: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f4ae: { // 0x56f4ae: 0f85c7000000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f4b4: { // 0x56f4b4: f6c31c TEST BL,0x1c
    (void)integer::logical(((s.bx & 0xffu))&(0x0000001cu),8,flags);
  }
  L0056f4b7: { // 0x56f4b7: 0f85be000000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f4bd: { // 0x56f4bd: f6c322 TEST BL,0x22
    (void)integer::logical(((s.bx & 0xffu))&(0x00000022u),8,flags);
  }
  L0056f4c0: { // 0x56f4c0: 0f84b5000000 JZ 0x0056f57b
    if(integer::condition("JZ",flags)) goto L0056f57b;
  }
  L0056f4c6: { // 0x56f4c6: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f4c9: { // 0x56f4c9: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f4cd: { // 0x56f4cd: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f4cf: { // 0x56f4cf: 8d51fc LEA EDX,[ECX + -0x4]
    s.dx = (s.cx-0x00000004u);
  }
  L0056f4d2: { // 0x56f4d2: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0056f4d5: { // 0x56f4d5: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  L0056f4d8: { // 0x56f4d8: 6689542414 MOV word ptr [ESP + 0x14],DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L0056f4dd: { // 0x56f4dd: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0056f4e2: { // 0x56f4e2: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L0056f4e7: { // 0x56f4e7: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f4ec: { // 0x56f4ec: 740a JZ 0x0056f4f8
    if(integer::condition("JZ",flags)) goto L0056f4f8;
  }
  L0056f4ee: { // 0x56f4ee: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f4f3: { // 0x56f4f3: 66ff442424 INC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::increment(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f4f8: { // 0x56f4f8: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L0056f4fb: { // 0x56f4fb: 740a JZ 0x0056f507
    if(integer::condition("JZ",flags)) goto L0056f507;
  }
  L0056f4fd: { // 0x56f4fd: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f502: { // 0x56f502: 66ff4c2414 DEC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::decrement(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f507: { // 0x56f507: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f50c: { // 0x56f50c: e8cf080c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698833u); flags=s.arithmetic_flags;
  }
  L0056f511: { // 0x56f511: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f515: { // 0x56f515: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f51d: { // 0x56f51d: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f521: { // 0x56f521: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f527: { // 0x56f527: e824b51f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698860u); flags=s.arithmetic_flags;
  }
  L0056f52c: { // 0x56f52c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f52f: { // 0x56f52f: 77d6 JA 0x0056f507
    if(integer::condition("JA",flags)) goto L0056f507;
  }
  L0056f531: { // 0x56f531: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f532: { // 0x56f532: 6601442416 ADD word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), integer::add(m.r16((f.sp+0x00000016u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f537: { // 0x56f537: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f53c: { // 0x56f53c: e89f080c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698881u); flags=s.arithmetic_flags;
  }
  L0056f541: { // 0x56f541: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f545: { // 0x56f545: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f54d: { // 0x56f54d: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f551: { // 0x56f551: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f557: { // 0x56f557: e8f4b41f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698908u); flags=s.arithmetic_flags;
  }
  L0056f55c: { // 0x56f55c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f55f: { // 0x56f55f: 77d6 JA 0x0056f537
    if(integer::condition("JA",flags)) goto L0056f537;
  }
  L0056f561: { // 0x56f561: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f562: { // 0x56f562: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f563: { // 0x56f563: 660144242a ADD word ptr [ESP + 0x2a],AX
    m.w16((f.sp+0x0000002au), integer::add(m.r16((f.sp+0x0000002au)),(s.ax & 0xffffu),16,flags));
  }
  L0056f568: { // 0x56f568: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0056f56c: { // 0x56f56c: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f570: { // 0x56f570: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f571: { // 0x56f571: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f572: { // 0x56f572: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f574: { // 0x56f574: e867020000 CALL 0x0056f7e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056f7e0u,5698937u); flags=s.arithmetic_flags;
  }
  L0056f579: { // 0x56f579: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f57b: { // 0x56f57b: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0056f57f: { // 0x56f57f: d81d808d7800 FCOMP float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0056f585: { // 0x56f585: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0056f587: { // 0x56f587: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0056f58a: { // 0x56f58a: 0f851d010000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f590: { // 0x56f590: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f592: { // 0x56f592: 0f8515010000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f598: { // 0x56f598: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0056f59a: { // 0x56f59a: 83e708 AND EDI,0x8
    s.di = integer::logical((s.di)&(0x00000008u),32,flags);
  }
  L0056f59d: { // 0x56f59d: 7543 JNZ 0x0056f5e2
    if(integer::condition("JNZ",flags)) goto L0056f5e2;
  }
  L0056f59f: { // 0x56f59f: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f5a2: { // 0x56f5a2: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f5a6: { // 0x56f5a6: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f5a8: { // 0x56f5a8: 8d51fc LEA EDX,[ECX + -0x4]
    s.dx = (s.cx-0x00000004u);
  }
  L0056f5ab: { // 0x56f5ab: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0056f5ae: { // 0x56f5ae: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f5b3: { // 0x56f5b3: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L0056f5b8: { // 0x56f5b8: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0056f5bc: { // 0x56f5bc: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L0056f5c1: { // 0x56f5c1: 6689542424 MOV word ptr [ESP + 0x24],DX
    m.w16((f.sp+0x00000024u), (s.dx & 0xffffu));
  }
  L0056f5c6: { // 0x56f5c6: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0056f5ca: { // 0x56f5ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f5cb: { // 0x56f5cb: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L0056f5cf: { // 0x56f5cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f5d0: { // 0x56f5d0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f5d1: { // 0x56f5d1: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f5d3: { // 0x56f5d3: e808020000 CALL 0x0056f7e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056f7e0u,5699032u); flags=s.arithmetic_flags;
  }
  L0056f5d8: { // 0x56f5d8: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f5da: { // 0x56f5da: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f5dc: { // 0x56f5dc: 0f85cb000000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f5e2: { // 0x56f5e2: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L0056f5e5: { // 0x56f5e5: 7543 JNZ 0x0056f62a
    if(integer::condition("JNZ",flags)) goto L0056f62a;
  }
  L0056f5e7: { // 0x56f5e7: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f5eb: { // 0x56f5eb: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f5ee: { // 0x56f5ee: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f5f0: { // 0x56f5f0: 8d5104 LEA EDX,[ECX + 0x4]
    s.dx = (s.cx+0x00000004u);
  }
  L0056f5f3: { // 0x56f5f3: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f5f6: { // 0x56f5f6: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f5fb: { // 0x56f5fb: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L0056f600: { // 0x56f600: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0056f604: { // 0x56f604: 66894c242e MOV word ptr [ESP + 0x2e],CX
    m.w16((f.sp+0x0000002eu), (s.cx & 0xffffu));
  }
  L0056f609: { // 0x56f609: 6689542426 MOV word ptr [ESP + 0x26],DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L0056f60e: { // 0x56f60e: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0056f612: { // 0x56f612: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f613: { // 0x56f613: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L0056f617: { // 0x56f617: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f618: { // 0x56f618: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f619: { // 0x56f619: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f61b: { // 0x56f61b: e810080000 CALL 0x0056fe30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056fe30u,5699104u); flags=s.arithmetic_flags;
  }
  L0056f620: { // 0x56f620: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f622: { // 0x56f622: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f624: { // 0x56f624: 0f8583000000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f62a: { // 0x56f62a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0056f62c: { // 0x56f62c: 753f JNZ 0x0056f66d
    if(integer::condition("JNZ",flags)) goto L0056f66d;
  }
  L0056f62e: { // 0x56f62e: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f631: { // 0x56f631: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0056f635: { // 0x56f635: 8d4104 LEA EAX,[ECX + 0x4]
    s.ax = (s.cx+0x00000004u);
  }
  L0056f638: { // 0x56f638: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f63b: { // 0x56f63b: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f640: { // 0x56f640: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f644: { // 0x56f644: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f646: { // 0x56f646: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L0056f64b: { // 0x56f64b: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0056f64f: { // 0x56f64f: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f654: { // 0x56f654: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L0056f659: { // 0x56f659: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f65a: { // 0x56f65a: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0056f65e: { // 0x56f65e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f65f: { // 0x56f65f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f660: { // 0x56f660: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f662: { // 0x56f662: e8090e0000 CALL 0x00570470
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570470u,5699175u); flags=s.arithmetic_flags;
  }
  L0056f667: { // 0x56f667: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f669: { // 0x56f669: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f66b: { // 0x56f66b: 7540 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f66d: { // 0x56f66d: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  L0056f670: { // 0x56f670: 753b JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f672: { // 0x56f672: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f675: { // 0x56f675: 668b7602 MOV SI,word ptr [ESI + 0x2]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.si+0x00000002u))) & 0xffffu);
  }
  L0056f679: { // 0x56f679: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0056f67d: { // 0x56f67d: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f67f: { // 0x56f67f: 8d4efc LEA ECX,[ESI + -0x4]
    s.cx = (s.si-0x00000004u);
  }
  L0056f682: { // 0x56f682: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f687: { // 0x56f687: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L0056f68c: { // 0x56f68c: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f691: { // 0x56f691: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0056f695: { // 0x56f695: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f696: { // 0x56f696: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0056f69a: { // 0x56f69a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f69b: { // 0x56f69b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0056f69e: { // 0x56f69e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f69f: { // 0x56f69f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f6a1: { // 0x56f6a1: 668974243a MOV word ptr [ESP + 0x3a],SI
    m.w16((f.sp+0x0000003au), (s.si & 0xffffu));
  }
  L0056f6a6: { // 0x56f6a6: e885140000 CALL 0x00570b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570b30u,5699243u); flags=s.arithmetic_flags;
  }
  L0056f6ab: { // 0x56f6ab: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f6ad: { // 0x56f6ad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f6ae: { // 0x56f6ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f6af: { // 0x56f6af: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f6b0: { // 0x56f6b0: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L0056f6b2: { // 0x56f6b2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f6b3: { // 0x56f6b3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0056f6b6: { // 0x56f6b6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0016f6c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056f6c0: { // 0x56f6c0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0056f6c3: { // 0x56f6c3: dd05f80b7900 FLD double ptr [0x00790bf8]
    const auto address=(0x00790bf8u);
    s.fp.load64(read64(m,address));
  }
  L0056f6c9: { // 0x56f6c9: dc25f00b7900 FSUB double ptr [0x00790bf0]
    const auto address=(0x00790bf0u);
    s.fp.subtract64(read64(m,address));
  }
  L0056f6cf: { // 0x56f6cf: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
  L0056f6d5: { // 0x56f6d5: d8642428 FSUB float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract32(m.r32(address));
  }
  L0056f6d9: { // 0x56f6d9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056f6da: { // 0x56f6da: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056f6db: { // 0x56f6db: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L0056f6dd: { // 0x56f6dd: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0056f6df: { // 0x56f6df: dc05f00b7900 FADD double ptr [0x00790bf0]
    const auto address=(0x00790bf0u);
    s.fp.add64(read64(m,address));
  }
  L0056f6e5: { // 0x56f6e5: e866b31f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5699306u); flags=s.arithmetic_flags;
  }
  L0056f6ea: { // 0x56f6ea: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0056f6ee: { // 0x56f6ee: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0056f6f0: { // 0x56f6f0: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L0056f6f4: { // 0x56f6f4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f6f5: { // 0x56f6f5: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L0056f6f8: { // 0x56f6f8: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L0056f6fc: { // 0x56f6fc: 662d0200 SUB AX,0x2
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),0x00000002u,16,flags));
  }
  L0056f700: { // 0x56f700: 6683e902 SUB CX,0x2
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),0x00000002u,16,flags));
  }
  L0056f704: { // 0x56f704: 0fbfd8 MOVSX EBX,AX
    s.bx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056f707: { // 0x56f707: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0056f70a: { // 0x56f70a: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0056f70d: { // 0x56f70d: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L0056f711: { // 0x56f711: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f715: { // 0x56f715: b805000000 MOV EAX,0x5
    s.ax = 0x00000005u;
  }
  L0056f71a: { // 0x56f71a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0056f71e: { // 0x56f71e: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0056f722: { // 0x56f722: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0056f726: { // 0x56f726: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056f72a: { // 0x56f72a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f72b: { // 0x56f72b: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0056f72f: { // 0x56f72f: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0056f733: { // 0x56f733: e8f80c0100 CALL 0x00580430
    s.arithmetic_flags=flags; invoke(m,s,f,0x00580430u,5699384u); flags=s.arithmetic_flags;
  }
  L0056f738: { // 0x56f738: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056f73a: { // 0x56f73a: 7510 JNZ 0x0056f74c
    if(integer::condition("JNZ",flags)) goto L0056f74c;
  }
  L0056f73c: { // 0x56f73c: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0056f740: { // 0x56f740: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f741: { // 0x56f741: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f742: { // 0x56f742: 8801 MOV byte ptr [ECX],AL
    m.w8((s.cx), (s.ax & 0xffu));
  }
  L0056f744: { // 0x56f744: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056f746: { // 0x56f746: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0056f749: { // 0x56f749: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0056f74c: { // 0x56f74c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056f74d: { // 0x56f74d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0056f74f: { // 0x56f74f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f750: { // 0x56f750: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L0056f754: { // 0x56f754: eb04 JMP 0x0056f75a
    goto L0056f75a;
  }
  L0056f756: { // 0x56f756: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0056f75a: { // 0x56f75a: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0056f75c: { // 0x56f75c: 83c3fb ADD EBX,-0x5
    s.bx = integer::add(s.bx,0xfffffffbu,32,flags);
  }
  L0056f75f: { // 0x56f75f: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0056f762: { // 0x56f762: 7504 JNZ 0x0056f768
    if(integer::condition("JNZ",flags)) goto L0056f768;
  }
  L0056f764: { // 0x56f764: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0056f766: { // 0x56f766: 7452 JZ 0x0056f7ba
    if(integer::condition("JZ",flags)) goto L0056f7ba;
  }
  L0056f768: { // 0x56f768: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0056f76c: { // 0x56f76c: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0056f770: { // 0x56f770: 8d04b2 LEA EAX,[EDX + ESI*0x4]
    s.ax = (s.dx+(s.si * 0x00000004u));
  }
  L0056f773: { // 0x56f773: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0056f777: { // 0x56f777: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f778: { // 0x56f778: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0056f77b: { // 0x56f77b: 8d4c06fb LEA ECX,[ESI + EAX*0x1 + -0x5]
    s.cx = (s.si+(s.ax * 0x00000001u)-0x00000005u);
  }
  L0056f77f: { // 0x56f77f: b805000000 MOV EAX,0x5
    s.ax = 0x00000005u;
  }
  L0056f784: { // 0x56f784: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0056f788: { // 0x56f788: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0056f78c: { // 0x56f78c: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0056f790: { // 0x56f790: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0056f794: { // 0x56f794: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f795: { // 0x56f795: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0056f799: { // 0x56f799: e8920c0100 CALL 0x00580430
    s.arithmetic_flags=flags; invoke(m,s,f,0x00580430u,5699486u); flags=s.arithmetic_flags;
  }
  L0056f79e: { // 0x56f79e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056f7a0: { // 0x56f7a0: 7418 JZ 0x0056f7ba
    if(integer::condition("JZ",flags)) goto L0056f7ba;
  }
  L0056f7a2: { // 0x56f7a2: 8d0c77 LEA ECX,[EDI + ESI*0x2]
    s.cx = (s.di+(s.si * 0x00000002u));
  }
  L0056f7a5: { // 0x56f7a5: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0056f7a7: { // 0x56f7a7: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0056f7a9: { // 0x56f7a9: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0056f7ad: { // 0x56f7ad: 8b0495a0b47c00 MOV EAX,dword ptr [EDX*0x4 + 0x7cb4a0]
    s.ax = m.r32(((s.dx * 0x00000004u)+0x007cb4a0u));
  }
  L0056f7b4: { // 0x56f7b4: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  L0056f7b6: { // 0x56f7b6: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0056f7ba: { // 0x56f7ba: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0056f7bb: { // 0x56f7bb: 83c305 ADD EBX,0x5
    s.bx = integer::add(s.bx,0x00000005u,32,flags);
  }
  L0056f7be: { // 0x56f7be: 83ff03 CMP EDI,0x3
    (void)integer::sub(s.di,0x00000003u,32,flags);
  }
  L0056f7c1: { // 0x56f7c1: 7c9c JL 0x0056f75f
    if(integer::condition("JL",flags)) goto L0056f75f;
  }
  L0056f7c3: { // 0x56f7c3: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0056f7c4: { // 0x56f7c4: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L0056f7c7: { // 0x56f7c7: 7c8d JL 0x0056f756
    if(integer::condition("JL",flags)) goto L0056f756;
  }
  L0056f7c9: { // 0x56f7c9: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0056f7cd: { // 0x56f7cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f7ce: { // 0x56f7ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f7cf: { // 0x56f7cf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f7d0: { // 0x56f7d0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f7d1: { // 0x56f7d1: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0056f7d4: { // 0x56f7d4: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_00180430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00580430: { // 0x580430: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00580433: { // 0x580433: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L00580436: { // 0x580436: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L0058043a: { // 0x58043a: 668b5104 MOV DX,word ptr [ECX + 0x4]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x00000004u)));
  }
  L0058043e: { // 0x58043e: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L00580443: { // 0x580443: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L00580448: { // 0x580448: 8b510c MOV EDX,dword ptr [ECX + 0xc]
    s.dx = m.r32((s.cx+0x0000000cu));
  }
  L0058044b: { // 0x58044b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058044c: { // 0x58044c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0058044e: { // 0x58044e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058044f: { // 0x58044f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00580450: { // 0x580450: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00580452: { // 0x580452: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00580453: { // 0x580453: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00580457: { // 0x580457: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0058045b: { // 0x58045b: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0058045f: { // 0x58045f: 0f8ebc000000 JLE 0x00580521
    if(integer::condition("JLE",flags)) goto L00580521;
  }
  L00580465: { // 0x580465: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L00580468: { // 0x580468: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0058046c: { // 0x58046c: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0058046e: { // 0x58046e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00580470: { // 0x580470: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00580474: { // 0x580474: 0f8e9a000000 JLE 0x00580514
    if(integer::condition("JLE",flags)) goto L00580514;
  }
  L0058047a: { // 0x58047a: 8b4c242a MOV ECX,dword ptr [ESP + 0x2a]
    s.cx = m.r32((f.sp+0x0000002au));
  }
  L0058047e: { // 0x58047e: 8d1c01 LEA EBX,[ECX + EAX*0x1]
    s.bx = (s.cx+(s.ax * 0x00000001u));
  }
  L00580481: { // 0x580481: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00580485: { // 0x580485: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00580487: { // 0x580487: 8b153486a500 MOV EDX,dword ptr [0x00a58634]
    s.dx = m.r32((0x00a58634u));
  }
  L0058048d: { // 0x58048d: 0fbfce MOVSX ECX,SI
    s.cx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00580490: { // 0x580490: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00580493: { // 0x580493: 8d3c01 LEA EDI,[ECX + EAX*0x1]
    s.di = (s.cx+(s.ax * 0x00000001u));
  }
  L00580496: { // 0x580496: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00580498: { // 0x580498: 7e5d JLE 0x005804f7
    if(integer::condition("JLE",flags)) goto L005804f7;
  }
  L0058049a: { // 0x58049a: 8b2d3486a500 MOV EBP,dword ptr [0x00a58634]
    s.bp = m.r32((0x00a58634u));
  }
  L005804a0: { // 0x5804a0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005804a2: { // 0x5804a2: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L005804a4: { // 0x5804a4: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L005804a6: { // 0x5804a6: 7d4f JGE 0x005804f7
    if(integer::condition("JGE",flags)) goto L005804f7;
  }
  L005804a8: { // 0x5804a8: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005804aa: { // 0x5804aa: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005804ac: { // 0x5804ac: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005804ae: { // 0x5804ae: 7d47 JGE 0x005804f7
    if(integer::condition("JGE",flags)) goto L005804f7;
  }
  L005804b0: { // 0x5804b0: 3b3d3886a500 CMP EDI,dword ptr [0x00a58638]
    (void)integer::sub(s.di,m.r32((0x00a58638u)),32,flags);
  }
  L005804b6: { // 0x5804b6: 7f3f JG 0x005804f7
    if(integer::condition("JG",flags)) goto L005804f7;
  }
  L005804b8: { // 0x5804b8: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005804be: { // 0x5804be: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005804c0: { // 0x5804c0: 7505 JNZ 0x005804c7
    if(integer::condition("JNZ",flags)) goto L005804c7;
  }
  L005804c2: { // 0x5804c2: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005804c5: { // 0x5804c5: eb19 JMP 0x005804e0
    goto L005804e0;
  }
  L005804c7: { // 0x5804c7: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L005804ca: { // 0x5804ca: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L005804d1: { // 0x5804d1: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005804d4: { // 0x5804d4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005804d6: { // 0x5804d6: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L005804d9: { // 0x5804d9: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L005804dc: { // 0x5804dc: 8b440838 MOV EAX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.ax = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L005804e0: { // 0x5804e0: 3b44241c CMP EAX,dword ptr [ESP + 0x1c]
    (void)integer::sub(s.ax,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L005804e4: { // 0x5804e4: 7511 JNZ 0x005804f7
    if(integer::condition("JNZ",flags)) goto L005804f7;
  }
  L005804e6: { // 0x5804e6: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005804ea: { // 0x5804ea: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L005804ee: { // 0x5804ee: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005804ef: { // 0x5804ef: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005804f1: { // 0x5804f1: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005804f5: { // 0x5804f5: 7d36 JGE 0x0058052d
    if(integer::condition("JGE",flags)) goto L0058052d;
  }
  L005804f7: { // 0x5804f7: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005804fb: { // 0x5804fb: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005804ff: { // 0x5804ff: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00580500: { // 0x580500: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00580502: { // 0x580502: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00580506: { // 0x580506: 0f8c75ffffff JL 0x00580481
    if(integer::condition("JL",flags)) goto L00580481;
  }
  L0058050c: { // 0x58050c: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00580510: { // 0x580510: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00580514: { // 0x580514: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00580515: { // 0x580515: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00580517: { // 0x580517: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0058051b: { // 0x58051b: 0f8c4bffffff JL 0x0058046c
    if(integer::condition("JL",flags)) goto L0058046c;
  }
  L00580521: { // 0x580521: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00580522: { // 0x580522: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00580523: { // 0x580523: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00580524: { // 0x580524: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00580526: { // 0x580526: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00580527: { // 0x580527: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0058052a: { // 0x58052a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0058052d: { // 0x58052d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058052e: { // 0x58052e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058052f: { // 0x58052f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00580530: { // 0x580530: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00580532: { // 0x580532: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00580533: { // 0x580533: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00580536: { // 0x580536: c20800 RET 0x8
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
void f_001721e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005721e0: { // 0x5721e0: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L005721e3: { // 0x5721e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005721e4: { // 0x5721e4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005721e5: { // 0x5721e5: 8b6c2438 MOV EBP,dword ptr [ESP + 0x38]
    s.bp = m.r32((f.sp+0x00000038u));
  }
  L005721e9: { // 0x5721e9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005721ea: { // 0x5721ea: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005721eb: { // 0x5721eb: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L005721ef: { // 0x5721ef: 0fbf7500 MOVSX ESI,word ptr [EBP]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005721f3: { // 0x5721f3: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L005721f6: { // 0x5721f6: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L005721f8: { // 0x5721f8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L005721fa: { // 0x5721fa: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005721fd: { // 0x5721fd: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00572201: { // 0x572201: 0f8ce0040000 JL 0x005726e7
    if(integer::condition("JL",flags)) goto L005726e7;
  }
  L00572207: { // 0x572207: 0fbf5502 MOVSX EDX,word ptr [EBP + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0057220b: { // 0x57220b: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057220f: { // 0x57220f: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00572211: { // 0x572211: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00572214: { // 0x572214: 0f8ccd040000 JL 0x005726e7
    if(integer::condition("JL",flags)) goto L005726e7;
  }
  L0057221a: { // 0x57221a: 83c00a ADD EAX,0xa
    s.ax = integer::add(s.ax,0x0000000au,32,flags);
  }
  L0057221d: { // 0x57221d: 83c10a ADD ECX,0xa
    s.cx = integer::add(s.cx,0x0000000au,32,flags);
  }
  L00572220: { // 0x572220: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00572224: { // 0x572224: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00572228: { // 0x572228: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0057222c: { // 0x57222c: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00572230: { // 0x572230: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00572231: { // 0x572231: 83c6f9 ADD ESI,-0x7
    s.si = integer::add(s.si,0xfffffff9u,32,flags);
  }
  L00572234: { // 0x572234: 83c2fc ADD EDX,-0x4
    s.dx = integer::add(s.dx,0xfffffffcu,32,flags);
  }
  L00572237: { // 0x572237: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00572238: { // 0x572238: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057223a: { // 0x57223a: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0057223e: { // 0x57223e: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L00572242: { // 0x572242: e8b9040000 CALL 0x00572700
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,5710407u); flags=s.arithmetic_flags;
  }
  L00572247: { // 0x572247: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572249: { // 0x572249: 0f8498040000 JZ 0x005726e7
    if(integer::condition("JZ",flags)) goto L005726e7;
  }
  L0057224f: { // 0x57224f: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00572253: { // 0x572253: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00572257: { // 0x572257: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0057225b: { // 0x57225b: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0057225f: { // 0x57225f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00572261: { // 0x572261: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00572263: { // 0x572263: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00572265: { // 0x572265: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00572267: { // 0x572267: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0057226b: { // 0x57226b: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0057226f: { // 0x57226f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00572273: { // 0x572273: 7d7c JGE 0x005722f1
    if(integer::condition("JGE",flags)) goto L005722f1;
  }
  L00572275: { // 0x572275: 8d4207 LEA EAX,[EDX + 0x7]
    s.ax = (s.dx+0x00000007u);
  }
  L00572278: { // 0x572278: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0057227c: { // 0x57227c: 3b5c2444 CMP EBX,dword ptr [ESP + 0x44]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L00572280: { // 0x572280: 7d5c JGE 0x005722de
    if(integer::condition("JGE",flags)) goto L005722de;
  }
  L00572282: { // 0x572282: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00572286: { // 0x572286: 66895c2440 MOV word ptr [ESP + 0x40],BX
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L0057228b: { // 0x57228b: 6689742442 MOV word ptr [ESP + 0x42],SI
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L00572290: { // 0x572290: e87b850100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5710485u); flags=s.arithmetic_flags;
  }
  L00572295: { // 0x572295: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572297: { // 0x572297: 7434 JZ 0x005722cd
    if(integer::condition("JZ",flags)) goto L005722cd;
  }
  L00572299: { // 0x572299: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0057229d: { // 0x57229d: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L005722a1: { // 0x5722a1: e8ba94ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5710502u); flags=s.arithmetic_flags;
  }
  L005722a6: { // 0x5722a6: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L005722aa: { // 0x5722aa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005722ab: { // 0x5722ab: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005722b0: { // 0x5722b0: e84b32fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5710517u); flags=s.arithmetic_flags;
  }
  L005722b5: { // 0x5722b5: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L005722b9: { // 0x5722b9: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005722bb: { // 0x5722bb: e810080000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5710528u); flags=s.arithmetic_flags;
  }
  L005722c0: { // 0x5722c0: 8a5010 MOV DL,byte ptr [EAX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000010u)));
  }
  L005722c3: { // 0x5722c3: 88961b010000 MOV byte ptr [ESI + 0x11b],DL
    m.w8((s.si+0x0000011bu), (s.dx & 0xffu));
  }
  L005722c9: { // 0x5722c9: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005722cd: { // 0x5722cd: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005722d1: { // 0x5722d1: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005722d2: { // 0x5722d2: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005722d4: { // 0x5722d4: 7cac JL 0x00572282
    if(integer::condition("JL",flags)) goto L00572282;
  }
  L005722d6: { // 0x5722d6: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005722da: { // 0x5722da: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L005722de: { // 0x5722de: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L005722e2: { // 0x5722e2: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L005722e6: { // 0x5722e6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005722e7: { // 0x5722e7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005722e9: { // 0x5722e9: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005722eb: { // 0x5722eb: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L005722ef: { // 0x5722ef: 7c8b JL 0x0057227c
    if(integer::condition("JL",flags)) goto L0057227c;
  }
  L005722f1: { // 0x5722f1: 0fbf5f02 MOVSX EBX,word ptr [EDI + 0x2]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005722f5: { // 0x5722f5: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005722f6: { // 0x5722f6: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L005722f8: { // 0x5722f8: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L005722fc: { // 0x5722fc: 8d4307 LEA EAX,[EBX + 0x7]
    s.ax = (s.bx+0x00000007u);
  }
  L005722ff: { // 0x5722ff: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572301: { // 0x572301: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00572305: { // 0x572305: 7d73 JGE 0x0057237a
    if(integer::condition("JGE",flags)) goto L0057237a;
  }
  L00572307: { // 0x572307: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0057230b: { // 0x57230b: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057230d: { // 0x57230d: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00572311: { // 0x572311: 3b742444 CMP ESI,dword ptr [ESP + 0x44]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L00572315: { // 0x572315: 7d5e JGE 0x00572375
    if(integer::condition("JGE",flags)) goto L00572375;
  }
  L00572317: { // 0x572317: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L0057231b: { // 0x57231b: 6689742440 MOV word ptr [ESP + 0x40],SI
    m.w16((f.sp+0x00000040u), (s.si & 0xffffu));
  }
  L00572320: { // 0x572320: 66895c2442 MOV word ptr [ESP + 0x42],BX
    m.w16((f.sp+0x00000042u), (s.bx & 0xffffu));
  }
  L00572325: { // 0x572325: e8e6840100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5710634u); flags=s.arithmetic_flags;
  }
  L0057232a: { // 0x57232a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057232c: { // 0x57232c: 7436 JZ 0x00572364
    if(integer::condition("JZ",flags)) goto L00572364;
  }
  L0057232e: { // 0x57232e: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00572332: { // 0x572332: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00572336: { // 0x572336: e82594ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5710651u); flags=s.arithmetic_flags;
  }
  L0057233b: { // 0x57233b: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L0057233f: { // 0x57233f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572344: { // 0x572344: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00572345: { // 0x572345: e8b631fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5710666u); flags=s.arithmetic_flags;
  }
  L0057234a: { // 0x57234a: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0057234e: { // 0x57234e: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00572352: { // 0x572352: e879070000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5710679u); flags=s.arithmetic_flags;
  }
  L00572357: { // 0x572357: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057235b: { // 0x57235b: 8a4010 MOV AL,byte ptr [EAX + 0x10]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000010u)));
  }
  L0057235e: { // 0x57235e: 88811b010000 MOV byte ptr [ECX + 0x11b],AL
    m.w8((s.cx+0x0000011bu), (s.ax & 0xffu));
  }
  L00572364: { // 0x572364: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00572368: { // 0x572368: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00572369: { // 0x572369: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0057236b: { // 0x57236b: 7caa JL 0x00572317
    if(integer::condition("JL",flags)) goto L00572317;
  }
  L0057236d: { // 0x57236d: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00572371: { // 0x572371: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00572375: { // 0x572375: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00572376: { // 0x572376: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572378: { // 0x572378: 7c97 JL 0x00572311
    if(integer::condition("JL",flags)) goto L00572311;
  }
  L0057237a: { // 0x57237a: 0fbf4d02 MOVSX ECX,word ptr [EBP + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0057237e: { // 0x57237e: 0fbf7500 MOVSX ESI,word ptr [EBP]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00572382: { // 0x572382: 8d5101 LEA EDX,[ECX + 0x1]
    s.dx = (s.cx+0x00000001u);
  }
  L00572385: { // 0x572385: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00572389: { // 0x572389: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0057238b: { // 0x57238b: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0057238f: { // 0x57238f: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00572393: { // 0x572393: 7d65 JGE 0x005723fa
    if(integer::condition("JGE",flags)) goto L005723fa;
  }
  L00572395: { // 0x572395: 8d4602 LEA EAX,[ESI + 0x2]
    s.ax = (s.si+0x00000002u);
  }
  L00572398: { // 0x572398: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0057239a: { // 0x57239a: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0057239c: { // 0x57239c: 7d53 JGE 0x005723f1
    if(integer::condition("JGE",flags)) goto L005723f1;
  }
  L0057239e: { // 0x57239e: 66894c2442 MOV word ptr [ESP + 0x42],CX
    m.w16((f.sp+0x00000042u), (s.cx & 0xffffu));
  }
  L005723a3: { // 0x5723a3: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L005723a7: { // 0x5723a7: 66895c2440 MOV word ptr [ESP + 0x40],BX
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L005723ac: { // 0x5723ac: e85f840100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5710769u); flags=s.arithmetic_flags;
  }
  L005723b1: { // 0x5723b1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005723b3: { // 0x5723b3: 742c JZ 0x005723e1
    if(integer::condition("JZ",flags)) goto L005723e1;
  }
  L005723b5: { // 0x5723b5: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005723b9: { // 0x5723b9: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L005723bd: { // 0x5723bd: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005723c0: { // 0x5723c0: e89b93ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5710789u); flags=s.arithmetic_flags;
  }
  L005723c5: { // 0x5723c5: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L005723c9: { // 0x5723c9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005723ce: { // 0x5723ce: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005723cf: { // 0x5723cf: e82c31fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5710804u); flags=s.arithmetic_flags;
  }
  L005723d4: { // 0x5723d4: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L005723d7: { // 0x5723d7: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L005723db: { // 0x5723db: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005723e1: { // 0x5723e1: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L005723e5: { // 0x5723e5: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005723e6: { // 0x5723e6: 8d4602 LEA EAX,[ESI + 0x2]
    s.ax = (s.si+0x00000002u);
  }
  L005723e9: { // 0x5723e9: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005723eb: { // 0x5723eb: 7cb1 JL 0x0057239e
    if(integer::condition("JL",flags)) goto L0057239e;
  }
  L005723ed: { // 0x5723ed: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005723f1: { // 0x5723f1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005723f2: { // 0x5723f2: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005723f4: { // 0x5723f4: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L005723f8: { // 0x5723f8: 7c9e JL 0x00572398
    if(integer::condition("JL",flags)) goto L00572398;
  }
  L005723fa: { // 0x5723fa: 0fbf7702 MOVSX ESI,word ptr [EDI + 0x2]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005723fe: { // 0x5723fe: 0fbf1f MOVSX EBX,word ptr [EDI]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00572401: { // 0x572401: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00572402: { // 0x572402: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L00572406: { // 0x572406: 8d4e02 LEA ECX,[ESI + 0x2]
    s.cx = (s.si+0x00000002u);
  }
  L00572409: { // 0x572409: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0057240b: { // 0x57240b: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0057240f: { // 0x57240f: 7d61 JGE 0x00572472
    if(integer::condition("JGE",flags)) goto L00572472;
  }
  L00572411: { // 0x572411: 8d4301 LEA EAX,[EBX + 0x1]
    s.ax = (s.bx+0x00000001u);
  }
  L00572414: { // 0x572414: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572416: { // 0x572416: 7d55 JGE 0x0057246d
    if(integer::condition("JGE",flags)) goto L0057246d;
  }
  L00572418: { // 0x572418: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L0057241c: { // 0x57241c: 66895c2440 MOV word ptr [ESP + 0x40],BX
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L00572421: { // 0x572421: 6689742442 MOV word ptr [ESP + 0x42],SI
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L00572426: { // 0x572426: e8e5830100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5710891u); flags=s.arithmetic_flags;
  }
  L0057242b: { // 0x57242b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057242d: { // 0x57242d: 742c JZ 0x0057245b
    if(integer::condition("JZ",flags)) goto L0057245b;
  }
  L0057242f: { // 0x57242f: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00572433: { // 0x572433: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00572437: { // 0x572437: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0057243a: { // 0x57243a: e82193ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5710911u); flags=s.arithmetic_flags;
  }
  L0057243f: { // 0x57243f: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L00572443: { // 0x572443: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572448: { // 0x572448: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00572449: { // 0x572449: e8b230fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5710926u); flags=s.arithmetic_flags;
  }
  L0057244e: { // 0x57244e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00572452: { // 0x572452: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L00572455: { // 0x572455: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0057245b: { // 0x57245b: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0057245f: { // 0x57245f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00572460: { // 0x572460: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00572461: { // 0x572461: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572463: { // 0x572463: 7cb3 JL 0x00572418
    if(integer::condition("JL",flags)) goto L00572418;
  }
  L00572465: { // 0x572465: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00572469: { // 0x572469: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0057246d: { // 0x57246d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0057246e: { // 0x57246e: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00572470: { // 0x572470: 7c9f JL 0x00572411
    if(integer::condition("JL",flags)) goto L00572411;
  }
  L00572472: { // 0x572472: 0fbf4500 MOVSX EAX,word ptr [EBP]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00572476: { // 0x572476: 0fbf5d02 MOVSX EBX,word ptr [EBP + 0x2]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0057247a: { // 0x57247a: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L0057247d: { // 0x57247d: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00572481: { // 0x572481: 8d5301 LEA EDX,[EBX + 0x1]
    s.dx = (s.bx+0x00000001u);
  }
  L00572484: { // 0x572484: 0fbf0f MOVSX ECX,word ptr [EDI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00572487: { // 0x572487: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00572489: { // 0x572489: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0057248b: { // 0x57248b: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057248f: { // 0x57248f: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00572491: { // 0x572491: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00572492: { // 0x572492: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00572493: { // 0x572493: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00572497: { // 0x572497: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00572499: { // 0x572499: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0057249b: { // 0x57249b: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0057249f: { // 0x57249f: 7d6d JGE 0x0057250e
    if(integer::condition("JGE",flags)) goto L0057250e;
  }
  L005724a1: { // 0x5724a1: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L005724a5: { // 0x5724a5: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L005724a7: { // 0x5724a7: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L005724ab: { // 0x5724ab: 3b5c2444 CMP EBX,dword ptr [ESP + 0x44]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L005724af: { // 0x5724af: 7d54 JGE 0x00572505
    if(integer::condition("JGE",flags)) goto L00572505;
  }
  L005724b1: { // 0x5724b1: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L005724b5: { // 0x5724b5: 66895c2440 MOV word ptr [ESP + 0x40],BX
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L005724ba: { // 0x5724ba: 6689742442 MOV word ptr [ESP + 0x42],SI
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L005724bf: { // 0x5724bf: e84c830100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5711044u); flags=s.arithmetic_flags;
  }
  L005724c4: { // 0x5724c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005724c6: { // 0x5724c6: 742c JZ 0x005724f4
    if(integer::condition("JZ",flags)) goto L005724f4;
  }
  L005724c8: { // 0x5724c8: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005724cc: { // 0x5724cc: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L005724d0: { // 0x5724d0: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005724d3: { // 0x5724d3: e88892ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5711064u); flags=s.arithmetic_flags;
  }
  L005724d8: { // 0x5724d8: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L005724dc: { // 0x5724dc: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005724e1: { // 0x5724e1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005724e2: { // 0x5724e2: e81930fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5711079u); flags=s.arithmetic_flags;
  }
  L005724e7: { // 0x5724e7: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L005724ea: { // 0x5724ea: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005724ee: { // 0x5724ee: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005724f4: { // 0x5724f4: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005724f8: { // 0x5724f8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005724f9: { // 0x5724f9: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005724fb: { // 0x5724fb: 7cb4 JL 0x005724b1
    if(integer::condition("JL",flags)) goto L005724b1;
  }
  L005724fd: { // 0x5724fd: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00572501: { // 0x572501: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00572505: { // 0x572505: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00572506: { // 0x572506: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00572508: { // 0x572508: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0057250c: { // 0x57250c: 7c9d JL 0x005724ab
    if(integer::condition("JL",flags)) goto L005724ab;
  }
  L0057250e: { // 0x57250e: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L00572512: { // 0x572512: 668b4502 MOV AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L00572516: { // 0x572516: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0057251a: { // 0x57251a: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L0057251e: { // 0x57251e: 6683ea03 SUB DX,0x3
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L00572522: { // 0x572522: 6689442442 MOV word ptr [ESP + 0x42],AX
    m.w16((f.sp+0x00000042u), (s.ax & 0xffffu));
  }
  L00572527: { // 0x572527: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L0057252c: { // 0x57252c: 6689542440 MOV word ptr [ESP + 0x40],DX
    m.w16((f.sp+0x00000040u), (s.dx & 0xffffu));
  }
  L00572531: { // 0x572531: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00572535: { // 0x572535: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  L00572538: { // 0x572538: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0057253c: { // 0x57253c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0057253d: { // 0x57253d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0057253e: { // 0x57253e: 8d542448 LEA EDX,[ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L00572542: { // 0x572542: 8d4807 LEA ECX,[EAX + 0x7]
    s.cx = (s.ax+0x00000007u);
  }
  L00572545: { // 0x572545: e8a62c0100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5711178u); flags=s.arithmetic_flags;
  }
  L0057254a: { // 0x57254a: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L0057254d: { // 0x57254d: 668b5702 MOV DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L00572551: { // 0x572551: 6683e902 SUB CX,0x2
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),0x00000002u,16,flags));
  }
  L00572555: { // 0x572555: 668954244a MOV word ptr [ESP + 0x4a],DX
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L0057255a: { // 0x57255a: 66894c2448 MOV word ptr [ESP + 0x48],CX
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L0057255f: { // 0x57255f: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00572563: { // 0x572563: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00572566: { // 0x572566: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0057256a: { // 0x57256a: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L0057256f: { // 0x57256f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00572570: { // 0x572570: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00572571: { // 0x572571: 8d542450 LEA EDX,[ESP + 0x50]
    s.dx = (f.sp+0x00000050u);
  }
  L00572575: { // 0x572575: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00572578: { // 0x572578: e8732c0100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5711229u); flags=s.arithmetic_flags;
  }
  L0057257d: { // 0x57257d: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057257f: { // 0x57257f: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00572583: { // 0x572583: 668bd3 MOV DX,BX
    s.dx = with_ax(s.dx, (s.bx & 0xffffu));
  }
  L00572586: { // 0x572586: 66035702 ADD DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L0057258a: { // 0x57258a: 662bcb SUB CX,BX
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L0057258d: { // 0x57258d: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00572591: { // 0x572591: 66894c2448 MOV word ptr [ESP + 0x48],CX
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L00572596: { // 0x572596: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00572597: { // 0x572597: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057259c: { // 0x57259c: 668954244e MOV word ptr [ESP + 0x4e],DX
    m.w16((f.sp+0x0000004eu), (s.dx & 0xffffu));
  }
  L005725a1: { // 0x5725a1: e85a2ffdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5711270u); flags=s.arithmetic_flags;
  }
  L005725a6: { // 0x5725a6: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L005725a9: { // 0x5725a9: c6801c01000008 MOV byte ptr [EAX + 0x11c],0x8
    m.w8((s.ax+0x0000011cu), 0x00000008u);
  }
  L005725b0: { // 0x5725b0: 2acb SUB CL,BL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L005725b2: { // 0x5725b2: fec9 DEC CL
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L005725b4: { // 0x5725b4: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005725ba: { // 0x5725ba: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    s.dx = m.r32((0x00a55c50u));
  }
  L005725c0: { // 0x5725c0: 83c207 ADD EDX,0x7
    s.dx = integer::add(s.dx,0x00000007u,32,flags);
  }
  L005725c3: { // 0x5725c3: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005725c4: { // 0x5725c4: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L005725c7: { // 0x5725c7: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005725ca: { // 0x5725ca: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L005725d1: { // 0x5725d1: 7cac JL 0x0057257f
    if(integer::condition("JL",flags)) goto L0057257f;
  }
  L005725d3: { // 0x5725d3: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005725d5: { // 0x5725d5: 668b4502 MOV AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L005725d9: { // 0x5725d9: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005725db: { // 0x5725db: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005725df: { // 0x5725df: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005725e2: { // 0x5725e2: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005725e4: { // 0x5725e4: 8d4c1afd LEA ECX,[EDX + EBX*0x1 + -0x3]
    s.cx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L005725e8: { // 0x5725e8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005725ea: { // 0x5725ea: 7e62 JLE 0x0057264e
    if(integer::condition("JLE",flags)) goto L0057264e;
  }
  L005725ec: { // 0x5725ec: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L005725f0: { // 0x5725f0: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L005725f4: { // 0x5725f4: 662bd3 SUB DX,BX
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L005725f7: { // 0x5725f7: 8d443003 LEA EAX,[EAX + ESI*0x1 + 0x3]
    s.ax = (s.ax+(s.si * 0x00000001u)+0x00000003u);
  }
  L005725fb: { // 0x5725fb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005725fc: { // 0x5725fc: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572601: { // 0x572601: 668954244c MOV word ptr [ESP + 0x4c],DX
    m.w16((f.sp+0x0000004cu), (s.dx & 0xffffu));
  }
  L00572606: { // 0x572606: 668944244e MOV word ptr [ESP + 0x4e],AX
    m.w16((f.sp+0x0000004eu), (s.ax & 0xffffu));
  }
  L0057260b: { // 0x57260b: e8f02efdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5711376u); flags=s.arithmetic_flags;
  }
  L00572610: { // 0x572610: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00572614: { // 0x572614: 8a4a10 MOV CL,byte ptr [EDX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000010u)));
  }
  L00572617: { // 0x572617: c6801c01000001 MOV byte ptr [EAX + 0x11c],0x1
    m.w8((s.ax+0x0000011cu), 0x00000001u);
  }
  L0057261e: { // 0x57261e: 2acb SUB CL,BL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00572620: { // 0x572620: fec9 DEC CL
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L00572622: { // 0x572622: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00572623: { // 0x572623: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00572629: { // 0x572629: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    s.dx = m.r32((0x00a55c50u));
  }
  L0057262f: { // 0x57262f: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L00572632: { // 0x572632: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00572639: { // 0x572639: 668b4502 MOV AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L0057263d: { // 0x57263d: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00572641: { // 0x572641: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00572644: { // 0x572644: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00572646: { // 0x572646: 8d4c1afd LEA ECX,[EDX + EBX*0x1 + -0x3]
    s.cx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L0057264a: { // 0x57264a: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0057264c: { // 0x57264c: 7c9e JL 0x005725ec
    if(integer::condition("JL",flags)) goto L005725ec;
  }
  L0057264e: { // 0x57264e: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0057264f: { // 0x57264f: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00572652: { // 0x572652: 7c81 JL 0x005725d5
    if(integer::condition("JL",flags)) goto L005725d5;
  }
  L00572654: { // 0x572654: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00572656: { // 0x572656: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00572659: { // 0x572659: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057265b: { // 0x57265b: 0fbf4d00 MOVSX ECX,word ptr [EBP]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L0057265f: { // 0x57265f: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00572662: { // 0x572662: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00572664: { // 0x572664: 8d541afd LEA EDX,[EDX + EBX*0x1 + -0x3]
    s.dx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L00572668: { // 0x572668: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057266a: { // 0x57266a: 7e65 JLE 0x005726d1
    if(integer::condition("JLE",flags)) goto L005726d1;
  }
  L0057266c: { // 0x57266c: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0057266e: { // 0x57266e: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L00572672: { // 0x572672: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00572675: { // 0x572675: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00572676: { // 0x572676: 668944244c MOV word ptr [ESP + 0x4c],AX
    m.w16((f.sp+0x0000004cu), (s.ax & 0xffffu));
  }
  L0057267b: { // 0x57267b: 668bc3 MOV AX,BX
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0057267e: { // 0x57267e: 66034702 ADD AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00572682: { // 0x572682: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572687: { // 0x572687: 668944244e MOV word ptr [ESP + 0x4e],AX
    m.w16((f.sp+0x0000004eu), (s.ax & 0xffffu));
  }
  L0057268c: { // 0x57268c: e86f2efdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5711505u); flags=s.arithmetic_flags;
  }
  L00572691: { // 0x572691: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00572695: { // 0x572695: 8a4a10 MOV CL,byte ptr [EDX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000010u)));
  }
  L00572698: { // 0x572698: c6801c01000004 MOV byte ptr [EAX + 0x11c],0x4
    m.w8((s.ax+0x0000011cu), 0x00000004u);
  }
  L0057269f: { // 0x57269f: 2acb SUB CL,BL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L005726a1: { // 0x5726a1: fec9 DEC CL
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L005726a3: { // 0x5726a3: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005726a9: { // 0x5726a9: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    s.dx = m.r32((0x00a55c50u));
  }
  L005726af: { // 0x5726af: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L005726b2: { // 0x5726b2: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L005726b9: { // 0x5726b9: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005726bc: { // 0x5726bc: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L005726bf: { // 0x5726bf: 0fbf5500 MOVSX EDX,word ptr [EBP]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005726c3: { // 0x5726c3: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005726c6: { // 0x5726c6: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L005726c8: { // 0x5726c8: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005726c9: { // 0x5726c9: 8d4c19fd LEA ECX,[ECX + EBX*0x1 + -0x3]
    s.cx = (s.cx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L005726cd: { // 0x5726cd: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005726cf: { // 0x5726cf: 7c9b JL 0x0057266c
    if(integer::condition("JL",flags)) goto L0057266c;
  }
  L005726d1: { // 0x5726d1: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005726d2: { // 0x5726d2: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L005726d5: { // 0x5726d5: 0f8c7bffffff JL 0x00572656
    if(integer::condition("JL",flags)) goto L00572656;
  }
  L005726db: { // 0x5726db: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005726dc: { // 0x5726dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005726dd: { // 0x5726dd: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005726de: { // 0x5726de: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005726e0: { // 0x5726e0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005726e1: { // 0x5726e1: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005726e4: { // 0x5726e4: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005726e7: { // 0x5726e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005726e8: { // 0x5726e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005726e9: { // 0x5726e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005726ea: { // 0x5726ea: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005726ec: { // 0x5726ec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005726ed: { // 0x5726ed: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005726f0: { // 0x5726f0: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00172700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00572700: { // 0x572700: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00572701: { // 0x572701: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00572702: { // 0x572702: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00572703: { // 0x572703: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00572704: { // 0x572704: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00572705: { // 0x572705: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00572709: { // 0x572709: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0057270d: { // 0x57270d: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00572711: { // 0x572711: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00572713: { // 0x572713: 668b4f04 MOV CX,word ptr [EDI + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000004u)));
  }
  L00572717: { // 0x572717: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L0057271a: { // 0x57271a: 66894c241e MOV word ptr [ESP + 0x1e],CX
    m.w16((f.sp+0x0000001eu), (s.cx & 0xffffu));
  }
  L0057271f: { // 0x57271f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00572720: { // 0x572720: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572725: { // 0x572725: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0057272a: { // 0x57272a: e8214dfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711663u); flags=s.arithmetic_flags;
  }
  L0057272f: { // 0x57272f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572731: { // 0x572731: 0f8433010000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572737: { // 0x572737: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L0057273a: { // 0x57273a: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L0057273c: { // 0x57273c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057273e: { // 0x57273e: 8d5408ff LEA EDX,[EAX + ECX*0x1 + -0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u)-0x00000001u);
  }
  L00572742: { // 0x572742: 668b4704 MOV AX,word ptr [EDI + 0x4]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000004u)));
  }
  L00572746: { // 0x572746: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0057274a: { // 0x57274a: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L0057274f: { // 0x57274f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00572750: { // 0x572750: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572755: { // 0x572755: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L0057275a: { // 0x57275a: e8f14cfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711711u); flags=s.arithmetic_flags;
  }
  L0057275f: { // 0x57275f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572761: { // 0x572761: 0f8403010000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572767: { // 0x572767: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0057276a: { // 0x57276a: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0057276d: { // 0x57276d: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00572770: { // 0x572770: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L00572775: { // 0x572775: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00572777: { // 0x572777: 8d5408ff LEA EDX,[EAX + ECX*0x1 + -0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u)-0x00000001u);
  }
  L0057277b: { // 0x57277b: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0057277f: { // 0x57277f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00572780: { // 0x572780: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572785: { // 0x572785: 6689542422 MOV word ptr [ESP + 0x22],DX
    m.w16((f.sp+0x00000022u), (s.dx & 0xffffu));
  }
  L0057278a: { // 0x57278a: e8c14cfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711759u); flags=s.arithmetic_flags;
  }
  L0057278f: { // 0x57278f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572791: { // 0x572791: 0f84d3000000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572797: { // 0x572797: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L0057279a: { // 0x57279a: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0057279c: { // 0x57279c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057279e: { // 0x57279e: 8d4411ff LEA EAX,[ECX + EDX*0x1 + -0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L005727a2: { // 0x5727a2: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L005727a5: { // 0x5727a5: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L005727a8: { // 0x5727a8: 668944241c MOV word ptr [ESP + 0x1c],AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L005727ad: { // 0x5727ad: 8d4411ff LEA EAX,[ECX + EDX*0x1 + -0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L005727b1: { // 0x5727b1: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L005727b5: { // 0x5727b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005727b6: { // 0x5727b6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005727bb: { // 0x5727bb: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L005727c0: { // 0x5727c0: e88b4cfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711813u); flags=s.arithmetic_flags;
  }
  L005727c5: { // 0x5727c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005727c7: { // 0x5727c7: 0f849d000000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L005727cd: { // 0x5727cd: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L005727d0: { // 0x5727d0: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L005727d3: { // 0x5727d3: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L005727d5: { // 0x5727d5: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L005727d7: { // 0x5727d7: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L005727d9: { // 0x5727d9: 0f8d81000000 JGE 0x00572860
    if(integer::condition("JGE",flags)) goto L00572860;
  }
  L005727df: { // 0x5727df: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L005727e3: { // 0x5727e3: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L005727e5: { // 0x5727e5: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L005727e8: { // 0x5727e8: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005727ea: { // 0x5727ea: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005727ec: { // 0x5727ec: 7d65 JGE 0x00572853
    if(integer::condition("JGE",flags)) goto L00572853;
  }
  L005727ee: { // 0x5727ee: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005727f4: { // 0x5727f4: 6689742418 MOV word ptr [ESP + 0x18],SI
    m.w16((f.sp+0x00000018u), (s.si & 0xffffu));
  }
  L005727f9: { // 0x5727f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005727fb: { // 0x5727fb: 66895c241a MOV word ptr [ESP + 0x1a],BX
    m.w16((f.sp+0x0000001au), (s.bx & 0xffffu));
  }
  L00572800: { // 0x572800: 7505 JNZ 0x00572807
    if(integer::condition("JNZ",flags)) goto L00572807;
  }
  L00572802: { // 0x572802: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00572805: { // 0x572805: eb19 JMP 0x00572820
    goto L00572820;
  }
  L00572807: { // 0x572807: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L0057280a: { // 0x57280a: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00572811: { // 0x572811: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00572814: { // 0x572814: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00572816: { // 0x572816: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00572819: { // 0x572819: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057281c: { // 0x57281c: 8b440838 MOV EAX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.ax = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L00572820: { // 0x572820: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00572824: { // 0x572824: 3b4108 CMP EAX,dword ptr [ECX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000008u)),32,flags);
  }
  L00572827: { // 0x572827: 7404 JZ 0x0057282d
    if(integer::condition("JZ",flags)) goto L0057282d;
  }
  L00572829: { // 0x572829: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0057282b: { // 0x57282b: 753d JNZ 0x0057286a
    if(integer::condition("JNZ",flags)) goto L0057286a;
  }
  L0057282d: { // 0x57282d: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00572831: { // 0x572831: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572836: { // 0x572836: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00572837: { // 0x572837: e8c42cfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5711932u); flags=s.arithmetic_flags;
  }
  L0057283c: { // 0x57283c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057283e: { // 0x57283e: e84d89f0ff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5711939u); flags=s.arithmetic_flags;
  }
  L00572843: { // 0x572843: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572845: { // 0x572845: 7423 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572847: { // 0x572847: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L0057284a: { // 0x57284a: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0057284c: { // 0x57284c: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0057284d: { // 0x57284d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057284f: { // 0x57284f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00572851: { // 0x572851: 7c9b JL 0x005727ee
    if(integer::condition("JL",flags)) goto L005727ee;
  }
  L00572853: { // 0x572853: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00572856: { // 0x572856: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00572859: { // 0x572859: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0057285a: { // 0x57285a: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057285c: { // 0x57285c: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0057285e: { // 0x57285e: 7c83 JL 0x005727e3
    if(integer::condition("JL",flags)) goto L005727e3;
  }
  L00572860: { // 0x572860: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00572861: { // 0x572861: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00572862: { // 0x572862: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00572863: { // 0x572863: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00572865: { // 0x572865: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572866: { // 0x572866: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00572867: { // 0x572867: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0057286a: { // 0x57286a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057286b: { // 0x57286b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057286c: { // 0x57286c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057286d: { // 0x57286d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0057286f: { // 0x57286f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572870: { // 0x572870: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00572871: { // 0x572871: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00157450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557450: { // 0x557450: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L00557454: { // 0x557454: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557455: { // 0x557455: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00557459: { // 0x557459: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055745a: { // 0x55745a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055745b: { // 0x55745b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0055745d: { // 0x55745d: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00557461: { // 0x557461: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557462: { // 0x557462: 0fbf3b MOVSX EDI,word ptr [EBX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00557465: { // 0x557465: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557467: { // 0x557467: 7454 JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L00557469: { // 0x557469: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0055746b: { // 0x55746b: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055746e: { // 0x55746e: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00557470: { // 0x557470: 7814 JS 0x00557486
    if(integer::condition("JS",flags)) goto L00557486;
  }
  L00557472: { // 0x557472: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00557477: { // 0x557477: 7d0d JGE 0x00557486
    if(integer::condition("JGE",flags)) goto L00557486;
  }
  L00557479: { // 0x557479: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055747f: { // 0x55747f: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L00557482: { // 0x557482: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557484: { // 0x557484: 750c JNZ 0x00557492
    if(integer::condition("JNZ",flags)) goto L00557492;
  }
  L00557486: { // 0x557486: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00557488: { // 0x557488: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055748d: { // 0x55748d: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00557492: { // 0x557492: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L00557498: { // 0x557498: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0055749f: { // 0x55749f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005574a1: { // 0x5574a1: 741a JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L005574a3: { // 0x5574a3: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L005574a9: { // 0x5574a9: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L005574af: { // 0x5574af: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  L005574b3: { // 0x5574b3: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  L005574b6: { // 0x5574b6: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005574b8: { // 0x5574b8: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005574ba: { // 0x5574ba: 7d01 JGE 0x005574bd
    if(integer::condition("JGE",flags)) goto L005574bd;
  }
  L005574bc: { // 0x5574bc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005574bd: { // 0x5574bd: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  L005574c3: { // 0x5574c3: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L005574c9: { // 0x5574c9: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  L005574cc: { // 0x5574cc: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  L005574cf: { // 0x5574cf: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574d1: { // 0x5574d1: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L005574d3: { // 0x5574d3: 7e49 JLE 0x0055751e
    if(integer::condition("JLE",flags)) goto L0055751e;
  }
  L005574d5: { // 0x5574d5: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  L005574db: { // 0x5574db: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  L005574e1: { // 0x5574e1: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L005574e3: { // 0x5574e3: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  L005574e7: { // 0x5574e7: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574e9: { // 0x5574e9: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  L005574ec: { // 0x5574ec: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005574ee: { // 0x5574ee: 7f2e JG 0x0055751e
    if(integer::condition("JG",flags)) goto L0055751e;
  }
  L005574f0: { // 0x5574f0: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  L005574f6: { // 0x5574f6: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  L005574fc: { // 0x5574fc: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005574fe: { // 0x5574fe: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00557500: { // 0x557500: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00557502: { // 0x557502: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00557504: { // 0x557504: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00557506: { // 0x557506: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00557508: { // 0x557508: 7d14 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L0055750a: { // 0x55750a: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  L0055750d: { // 0x55750d: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0055750f: { // 0x55750f: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00557511: { // 0x557511: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00557513: { // 0x557513: 7d09 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L00557515: { // 0x557515: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557516: { // 0x557516: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557517: { // 0x557517: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557518: { // 0x557518: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0055751a: { // 0x55751a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055751b: { // 0x55751b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055751e: { // 0x55751e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055751f: { // 0x55751f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557520: { // 0x557520: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557521: { // 0x557521: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00557523: { // 0x557523: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557524: { // 0x557524: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_0018a810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058a810: { // 0x58a810: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0058a813: { // 0x58a813: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0058a817: { // 0x58a817: 8b0d3486a500 MOV ECX,dword ptr [0x00a58634]
    s.cx = m.r32((0x00a58634u));
  }
  L0058a81d: { // 0x58a81d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058a81e: { // 0x58a81e: 8d3410 LEA ESI,[EAX + EDX*0x1]
    s.si = (s.ax+(s.dx * 0x00000001u));
  }
  L0058a821: { // 0x58a821: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0058a823: { // 0x58a823: 7e1c JLE 0x0058a841
    if(integer::condition("JLE",flags)) goto L0058a841;
  }
  L0058a825: { // 0x58a825: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058a826: { // 0x58a826: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0058a828: { // 0x58a828: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0058a82a: { // 0x58a82a: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0058a82c: { // 0x58a82c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058a82d: { // 0x58a82d: 7d12 JGE 0x0058a841
    if(integer::condition("JGE",flags)) goto L0058a841;
  }
  L0058a82f: { // 0x58a82f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0058a831: { // 0x58a831: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0058a833: { // 0x58a833: 7d0c JGE 0x0058a841
    if(integer::condition("JGE",flags)) goto L0058a841;
  }
  L0058a835: { // 0x58a835: 3b353886a500 CMP ESI,dword ptr [0x00a58638]
    (void)integer::sub(s.si,m.r32((0x00a58638u)),32,flags);
  }
  L0058a83b: { // 0x58a83b: 7f04 JG 0x0058a841
    if(integer::condition("JG",flags)) goto L0058a841;
  }
  L0058a83d: { // 0x58a83d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0058a83f: { // 0x58a83f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058a840: { // 0x58a840: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0058a841: { // 0x58a841: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0058a843: { // 0x58a843: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058a844: { // 0x58a844: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0016b760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056b760: { // 0x56b760: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056b761: { // 0x56b761: 8b353c86a500 MOV ESI,dword ptr [0x00a5863c]
    s.si = m.r32((0x00a5863cu));
  }
  L0056b767: { // 0x56b767: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0056b769: { // 0x56b769: 741a JZ 0x0056b785
    if(integer::condition("JZ",flags)) goto L0056b785;
  }
  L0056b76b: { // 0x56b76b: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0056b76f: { // 0x56b76f: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0056b776: { // 0x56b776: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0056b779: { // 0x56b779: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056b77b: { // 0x56b77b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0056b77e: { // 0x56b77e: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0056b781: { // 0x56b781: 89543038 MOV dword ptr [EAX + ESI*0x1 + 0x38],EDX
    m.w32((s.ax+(s.si * 0x00000001u)+0x00000038u), s.dx);
  }
  L0056b785: { // 0x56b785: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056b786: { // 0x56b786: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00172ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00572ad0: { // 0x572ad0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00572ad1: { // 0x572ad1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00572ad2: { // 0x572ad2: 8b355079a500 MOV ESI,dword ptr [0x00a57950]
    s.si = m.r32((0x00a57950u));
  }
  L00572ad8: { // 0x572ad8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00572ada: { // 0x572ada: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00572adb: { // 0x572adb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00572add: { // 0x572add: 7e17 JLE 0x00572af6
    if(integer::condition("JLE",flags)) goto L00572af6;
  }
  L00572adf: { // 0x572adf: 8b3d4479a500 MOV EDI,dword ptr [0x00a57944]
    s.di = m.r32((0x00a57944u));
  }
  L00572ae5: { // 0x572ae5: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00572ae7: { // 0x572ae7: 8b1a MOV EBX,dword ptr [EDX]
    s.bx = m.r32((s.dx));
  }
  L00572ae9: { // 0x572ae9: 394b08 CMP dword ptr [EBX + 0x8],ECX
    (void)integer::sub(m.r32((s.bx+0x00000008u)),s.cx,32,flags);
  }
  L00572aec: { // 0x572aec: 740e JZ 0x00572afc
    if(integer::condition("JZ",flags)) goto L00572afc;
  }
  L00572aee: { // 0x572aee: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00572aef: { // 0x572aef: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00572af2: { // 0x572af2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00572af4: { // 0x572af4: 7cf1 JL 0x00572ae7
    if(integer::condition("JL",flags)) goto L00572ae7;
  }
  L00572af6: { // 0x572af6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00572af7: { // 0x572af7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00572af8: { // 0x572af8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00572afa: { // 0x572afa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572afb: { // 0x572afb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00572afc: { // 0x572afc: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00572aff: { // 0x572aff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00572b00: { // 0x572b00: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00572b01: { // 0x572b01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572b02: { // 0x572b02: c3 RET
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
case 5697632u:f_0016f060(m,s,child,{});break;
case 5699264u:f_0016f6c0(m,s,child,{});break;
case 5768240u:f_00180430(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5710304u:f_001721e0(m,s,child,{});break;
case 5711616u:f_00172700(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5810192u:f_0018a810(m,s,child,{});break;
case 5683040u:f_0016b760(m,s,child,{});break;
case 5712592u:f_00172ad0(m,s,child,{});break;
case 5788144u:f_001851f0(m,s,child,{});break;
case 4309760u:f_0001c300(m,s,child,{});break;
default:throw std::domain_error("recovery1558 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1558 unreviewed tail"); } }

std::uint32_t fun_0056f060(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056f060: { // 0x56f060: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0056f063: { // 0x56f063: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0056f067: { // 0x56f067: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056f068: { // 0x56f068: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056f069: { // 0x56f069: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056f06a: { // 0x56f06a: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0056f06e: { // 0x56f06e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f06f: { // 0x56f06f: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0056f073: { // 0x56f073: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0056f075: { // 0x56f075: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f076: { // 0x56f076: 8d4c2417 LEA ECX,[ESP + 0x17]
    s.cx = (f.sp+0x00000017u);
  }
  L0056f07a: { // 0x56f07a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f07b: { // 0x56f07b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f07c: { // 0x56f07c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056f07d: { // 0x56f07d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f07f: { // 0x56f07f: c644242301 MOV byte ptr [ESP + 0x23],0x1
    m.w8((f.sp+0x00000023u), 0x00000001u);
  }
  L0056f084: { // 0x56f084: e837060000 CALL 0x0056f6c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056f6c0u,5697673u); flags=s.arithmetic_flags;
  }
  L0056f089: { // 0x56f089: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0056f08b: { // 0x56f08b: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0056f08f: { // 0x56f08f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056f091: { // 0x56f091: 750c JNZ 0x0056f09f
    if(integer::condition("JNZ",flags)) goto L0056f09f;
  }
  L0056f093: { // 0x56f093: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f094: { // 0x56f094: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f095: { // 0x56f095: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f096: { // 0x56f096: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056f098: { // 0x56f098: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f099: { // 0x56f099: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0056f09c: { // 0x56f09c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056f09f: { // 0x56f09f: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L0056f0a1: { // 0x56f0a1: 81fbff000000 CMP EBX,0xff
    (void)integer::sub(s.bx,0x000000ffu,32,flags);
  }
  L0056f0a7: { // 0x56f0a7: 750c JNZ 0x0056f0b5
    if(integer::condition("JNZ",flags)) goto L0056f0b5;
  }
  L0056f0a9: { // 0x56f0a9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f0aa: { // 0x56f0aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f0ab: { // 0x56f0ab: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f0ac: { // 0x56f0ac: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056f0ae: { // 0x56f0ae: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f0af: { // 0x56f0af: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0056f0b2: { // 0x56f0b2: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056f0b5: { // 0x56f0b5: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f0b7: { // 0x56f0b7: 81e282000000 AND EDX,0x82
    s.dx = integer::logical((s.dx)&(0x00000082u),32,flags);
  }
  L0056f0bd: { // 0x56f0bd: 80fa82 CMP DL,0x82
    (void)integer::sub((s.dx & 0xffu),0x00000082u,8,flags);
  }
  L0056f0c0: { // 0x56f0c0: 755a JNZ 0x0056f11c
    if(integer::condition("JNZ",flags)) goto L0056f11c;
  }
  L0056f0c2: { // 0x56f0c2: f6c338 TEST BL,0x38
    (void)integer::logical(((s.bx & 0xffu))&(0x00000038u),8,flags);
  }
  L0056f0c5: { // 0x56f0c5: 7555 JNZ 0x0056f11c
    if(integer::condition("JNZ",flags)) goto L0056f11c;
  }
  L0056f0c7: { // 0x56f0c7: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f0ca: { // 0x56f0ca: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L0056f0cd: { // 0x56f0cd: 83c005 ADD EAX,0x5
    s.ax = integer::add(s.ax,0x00000005u,32,flags);
  }
  L0056f0d0: { // 0x56f0d0: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f0d5: { // 0x56f0d5: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f0d9: { // 0x56f0d9: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f0de: { // 0x56f0de: 8d51fb LEA EDX,[ECX + -0x5]
    s.dx = (s.cx-0x00000005u);
  }
  L0056f0e1: { // 0x56f0e1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0056f0e2: { // 0x56f0e2: f6c340 TEST BL,0x40
    (void)integer::logical(((s.bx & 0xffu))&(0x00000040u),8,flags);
  }
  L0056f0e5: { // 0x56f0e5: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f0ea: { // 0x56f0ea: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f0ef: { // 0x56f0ef: 7405 JZ 0x0056f0f6
    if(integer::condition("JZ",flags)) goto L0056f0f6;
  }
  L0056f0f1: { // 0x56f0f1: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f0f6: { // 0x56f0f6: f6c304 TEST BL,0x4
    (void)integer::logical(((s.bx & 0xffu))&(0x00000004u),8,flags);
  }
  L0056f0f9: { // 0x56f0f9: 7405 JZ 0x0056f100
    if(integer::condition("JZ",flags)) goto L0056f100;
  }
  L0056f0fb: { // 0x56f0fb: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f100: { // 0x56f100: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f104: { // 0x56f104: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f105: { // 0x56f105: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f109: { // 0x56f109: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f10a: { // 0x56f10a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f10b: { // 0x56f10b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f10d: { // 0x56f10d: e8ce300000 CALL 0x005721e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005721e0u,5697810u); flags=s.arithmetic_flags;
  }
  L0056f112: { // 0x56f112: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f114: { // 0x56f114: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f116: { // 0x56f116: 0f855f040000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f11c: { // 0x56f11c: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f11e: { // 0x56f11e: 83e20a AND EDX,0xa
    s.dx = integer::logical((s.dx)&(0x0000000au),32,flags);
  }
  L0056f121: { // 0x56f121: 80fa0a CMP DL,0xa
    (void)integer::sub((s.dx & 0xffu),0x0000000au,8,flags);
  }
  L0056f124: { // 0x56f124: 755a JNZ 0x0056f180
    if(integer::condition("JNZ",flags)) goto L0056f180;
  }
  L0056f126: { // 0x56f126: f6c311 TEST BL,0x11
    (void)integer::logical(((s.bx & 0xffu))&(0x00000011u),8,flags);
  }
  L0056f129: { // 0x56f129: 7555 JNZ 0x0056f180
    if(integer::condition("JNZ",flags)) goto L0056f180;
  }
  L0056f12b: { // 0x56f12b: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f12e: { // 0x56f12e: 8d4805 LEA ECX,[EAX + 0x5]
    s.cx = (s.ax+0x00000005u);
  }
  L0056f131: { // 0x56f131: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f132: { // 0x56f132: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f137: { // 0x56f137: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f13b: { // 0x56f13b: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f140: { // 0x56f140: 8d51ff LEA EDX,[ECX + -0x1]
    s.dx = (s.cx-0x00000001u);
  }
  L0056f143: { // 0x56f143: 83c105 ADD ECX,0x5
    s.cx = integer::add(s.cx,0x00000005u,32,flags);
  }
  L0056f146: { // 0x56f146: f6c310 TEST BL,0x10
    (void)integer::logical(((s.bx & 0xffu))&(0x00000010u),8,flags);
  }
  L0056f149: { // 0x56f149: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f14e: { // 0x56f14e: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f153: { // 0x56f153: 7405 JZ 0x0056f15a
    if(integer::condition("JZ",flags)) goto L0056f15a;
  }
  L0056f155: { // 0x56f155: 66ff4c2426 DEC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::decrement(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f15a: { // 0x56f15a: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L0056f15d: { // 0x56f15d: 7405 JZ 0x0056f164
    if(integer::condition("JZ",flags)) goto L0056f164;
  }
  L0056f15f: { // 0x56f15f: 66ff4c2414 DEC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::decrement(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f164: { // 0x56f164: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f168: { // 0x56f168: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f169: { // 0x56f169: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f16d: { // 0x56f16d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f16e: { // 0x56f16e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f16f: { // 0x56f16f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f171: { // 0x56f171: e8ca2a0000 CALL 0x00571c40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00571c40u,5697910u); flags=s.arithmetic_flags;
  }
  L0056f176: { // 0x56f176: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f178: { // 0x56f178: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f17a: { // 0x56f17a: 0f85fb030000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f180: { // 0x56f180: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f182: { // 0x56f182: 83e228 AND EDX,0x28
    s.dx = integer::logical((s.dx)&(0x00000028u),32,flags);
  }
  L0056f185: { // 0x56f185: 80fa28 CMP DL,0x28
    (void)integer::sub((s.dx & 0xffu),0x00000028u,8,flags);
  }
  L0056f188: { // 0x56f188: 755a JNZ 0x0056f1e4
    if(integer::condition("JNZ",flags)) goto L0056f1e4;
  }
  L0056f18a: { // 0x56f18a: f6c383 TEST BL,0x83
    (void)integer::logical(((s.bx & 0xffu))&(0x00000083u),8,flags);
  }
  L0056f18d: { // 0x56f18d: 7555 JNZ 0x0056f1e4
    if(integer::condition("JNZ",flags)) goto L0056f1e4;
  }
  L0056f18f: { // 0x56f18f: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f192: { // 0x56f192: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L0056f195: { // 0x56f195: 83c0fb ADD EAX,-0x5
    s.ax = integer::add(s.ax,0xfffffffbu,32,flags);
  }
  L0056f198: { // 0x56f198: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f19d: { // 0x56f19d: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f1a1: { // 0x56f1a1: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f1a6: { // 0x56f1a6: 8d5105 LEA EDX,[ECX + 0x5]
    s.dx = (s.cx+0x00000005u);
  }
  L0056f1a9: { // 0x56f1a9: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0056f1aa: { // 0x56f1aa: f6c340 TEST BL,0x40
    (void)integer::logical(((s.bx & 0xffu))&(0x00000040u),8,flags);
  }
  L0056f1ad: { // 0x56f1ad: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f1b2: { // 0x56f1b2: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f1b7: { // 0x56f1b7: 7405 JZ 0x0056f1be
    if(integer::condition("JZ",flags)) goto L0056f1be;
  }
  L0056f1b9: { // 0x56f1b9: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f1be: { // 0x56f1be: f6c304 TEST BL,0x4
    (void)integer::logical(((s.bx & 0xffu))&(0x00000004u),8,flags);
  }
  L0056f1c1: { // 0x56f1c1: 7405 JZ 0x0056f1c8
    if(integer::condition("JZ",flags)) goto L0056f1c8;
  }
  L0056f1c3: { // 0x56f1c3: 66ff4c2416 DEC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::decrement(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f1c8: { // 0x56f1c8: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f1cc: { // 0x56f1cc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f1cd: { // 0x56f1cd: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f1d1: { // 0x56f1d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f1d2: { // 0x56f1d2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f1d3: { // 0x56f1d3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f1d5: { // 0x56f1d5: e846250000 CALL 0x00571720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00571720u,5698010u); flags=s.arithmetic_flags;
  }
  L0056f1da: { // 0x56f1da: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f1dc: { // 0x56f1dc: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f1de: { // 0x56f1de: 0f8597030000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f1e4: { // 0x56f1e4: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0056f1e6: { // 0x56f1e6: 81e2a0000000 AND EDX,0xa0
    s.dx = integer::logical((s.dx)&(0x000000a0u),32,flags);
  }
  L0056f1ec: { // 0x56f1ec: 80faa0 CMP DL,0xa0
    (void)integer::sub((s.dx & 0xffu),0x000000a0u,8,flags);
  }
  L0056f1ef: { // 0x56f1ef: 755a JNZ 0x0056f24b
    if(integer::condition("JNZ",flags)) goto L0056f24b;
  }
  L0056f1f1: { // 0x56f1f1: f6c30e TEST BL,0xe
    (void)integer::logical(((s.bx & 0xffu))&(0x0000000eu),8,flags);
  }
  L0056f1f4: { // 0x56f1f4: 7555 JNZ 0x0056f24b
    if(integer::condition("JNZ",flags)) goto L0056f24b;
  }
  L0056f1f6: { // 0x56f1f6: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f1f9: { // 0x56f1f9: 8d48fb LEA ECX,[EAX + -0x5]
    s.cx = (s.ax-0x00000005u);
  }
  L0056f1fc: { // 0x56f1fc: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056f1fd: { // 0x56f1fd: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L0056f202: { // 0x56f202: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f206: { // 0x56f206: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f20b: { // 0x56f20b: 8d5101 LEA EDX,[ECX + 0x1]
    s.dx = (s.cx+0x00000001u);
  }
  L0056f20e: { // 0x56f20e: 83c1fb ADD ECX,-0x5
    s.cx = integer::add(s.cx,0xfffffffbu,32,flags);
  }
  L0056f211: { // 0x56f211: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L0056f214: { // 0x56f214: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f219: { // 0x56f219: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f21e: { // 0x56f21e: 7405 JZ 0x0056f225
    if(integer::condition("JZ",flags)) goto L0056f225;
  }
  L0056f220: { // 0x56f220: 66ff442426 INC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::increment(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f225: { // 0x56f225: f6c310 TEST BL,0x10
    (void)integer::logical(((s.bx & 0xffu))&(0x00000010u),8,flags);
  }
  L0056f228: { // 0x56f228: 7405 JZ 0x0056f22f
    if(integer::condition("JZ",flags)) goto L0056f22f;
  }
  L0056f22a: { // 0x56f22a: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f22f: { // 0x56f22f: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f233: { // 0x56f233: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f234: { // 0x56f234: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f238: { // 0x56f238: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f239: { // 0x56f239: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f23a: { // 0x56f23a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f23c: { // 0x56f23c: e8df240000 CALL 0x00571720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00571720u,5698113u); flags=s.arithmetic_flags;
  }
  L0056f241: { // 0x56f241: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f243: { // 0x56f243: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f245: { // 0x56f245: 0f8530030000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f24b: { // 0x56f24b: f6c370 TEST BL,0x70
    (void)integer::logical(((s.bx & 0xffu))&(0x00000070u),8,flags);
  }
  L0056f24e: { // 0x56f24e: 0f85c4000000 JNZ 0x0056f318
    if(integer::condition("JNZ",flags)) goto L0056f318;
  }
  L0056f254: { // 0x56f254: f6c388 TEST BL,0x88
    (void)integer::logical(((s.bx & 0xffu))&(0x00000088u),8,flags);
  }
  L0056f257: { // 0x56f257: 0f84bb000000 JZ 0x0056f318
    if(integer::condition("JZ",flags)) goto L0056f318;
  }
  L0056f25d: { // 0x56f25d: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f261: { // 0x56f261: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f264: { // 0x56f264: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f266: { // 0x56f266: 8d51fc LEA EDX,[ECX + -0x4]
    s.dx = (s.cx-0x00000004u);
  }
  L0056f269: { // 0x56f269: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0056f26c: { // 0x56f26c: f6c380 TEST BL,0x80
    (void)integer::logical(((s.bx & 0xffu))&(0x00000080u),8,flags);
  }
  L0056f26f: { // 0x56f26f: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0056f274: { // 0x56f274: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f279: { // 0x56f279: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f27e: { // 0x56f27e: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f283: { // 0x56f283: 740a JZ 0x0056f28f
    if(integer::condition("JZ",flags)) goto L0056f28f;
  }
  L0056f285: { // 0x56f285: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f28a: { // 0x56f28a: 66ff442426 INC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::increment(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f28f: { // 0x56f28f: f6c308 TEST BL,0x8
    (void)integer::logical(((s.bx & 0xffu))&(0x00000008u),8,flags);
  }
  L0056f292: { // 0x56f292: 740a JZ 0x0056f29e
    if(integer::condition("JZ",flags)) goto L0056f29e;
  }
  L0056f294: { // 0x56f294: 66ff4c2426 DEC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::decrement(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f299: { // 0x56f299: 66ff4c2416 DEC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::decrement(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f29e: { // 0x56f29e: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f2a3: { // 0x56f2a3: e8380b0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698216u); flags=s.arithmetic_flags;
  }
  L0056f2a8: { // 0x56f2a8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f2ac: { // 0x56f2ac: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f2b4: { // 0x56f2b4: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f2b8: { // 0x56f2b8: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f2be: { // 0x56f2be: e88db71f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698243u); flags=s.arithmetic_flags;
  }
  L0056f2c3: { // 0x56f2c3: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f2c6: { // 0x56f2c6: 77d6 JA 0x0056f29e
    if(integer::condition("JA",flags)) goto L0056f29e;
  }
  L0056f2c8: { // 0x56f2c8: 6601442414 ADD word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), integer::add(m.r16((f.sp+0x00000014u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f2cd: { // 0x56f2cd: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f2d2: { // 0x56f2d2: e8090b0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698263u); flags=s.arithmetic_flags;
  }
  L0056f2d7: { // 0x56f2d7: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f2db: { // 0x56f2db: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f2e3: { // 0x56f2e3: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f2e7: { // 0x56f2e7: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f2ed: { // 0x56f2ed: e85eb71f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698290u); flags=s.arithmetic_flags;
  }
  L0056f2f2: { // 0x56f2f2: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f2f5: { // 0x56f2f5: 77d6 JA 0x0056f2cd
    if(integer::condition("JA",flags)) goto L0056f2cd;
  }
  L0056f2f7: { // 0x56f2f7: 6601442424 ADD word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), integer::add(m.r16((f.sp+0x00000024u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f2fc: { // 0x56f2fc: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f300: { // 0x56f300: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f301: { // 0x56f301: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f305: { // 0x56f305: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f306: { // 0x56f306: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f307: { // 0x56f307: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f309: { // 0x56f309: e822180000 CALL 0x00570b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570b30u,5698318u); flags=s.arithmetic_flags;
  }
  L0056f30e: { // 0x56f30e: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f310: { // 0x56f310: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f312: { // 0x56f312: 0f8563020000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f318: { // 0x56f318: f6c307 TEST BL,0x7
    (void)integer::logical(((s.bx & 0xffu))&(0x00000007u),8,flags);
  }
  L0056f31b: { // 0x56f31b: 0f85c6000000 JNZ 0x0056f3e7
    if(integer::condition("JNZ",flags)) goto L0056f3e7;
  }
  L0056f321: { // 0x56f321: f6c388 TEST BL,0x88
    (void)integer::logical(((s.bx & 0xffu))&(0x00000088u),8,flags);
  }
  L0056f324: { // 0x56f324: 0f84bd000000 JZ 0x0056f3e7
    if(integer::condition("JZ",flags)) goto L0056f3e7;
  }
  L0056f32a: { // 0x56f32a: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f32e: { // 0x56f32e: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f331: { // 0x56f331: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f333: { // 0x56f333: 8d5104 LEA EDX,[ECX + 0x4]
    s.dx = (s.cx+0x00000004u);
  }
  L0056f336: { // 0x56f336: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f339: { // 0x56f339: f6c380 TEST BL,0x80
    (void)integer::logical(((s.bx & 0xffu))&(0x00000080u),8,flags);
  }
  L0056f33c: { // 0x56f33c: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0056f341: { // 0x56f341: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f346: { // 0x56f346: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f34b: { // 0x56f34b: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f350: { // 0x56f350: 740a JZ 0x0056f35c
    if(integer::condition("JZ",flags)) goto L0056f35c;
  }
  L0056f352: { // 0x56f352: 66ff442426 INC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::increment(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f357: { // 0x56f357: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f35c: { // 0x56f35c: f6c308 TEST BL,0x8
    (void)integer::logical(((s.bx & 0xffu))&(0x00000008u),8,flags);
  }
  L0056f35f: { // 0x56f35f: 740a JZ 0x0056f36b
    if(integer::condition("JZ",flags)) goto L0056f36b;
  }
  L0056f361: { // 0x56f361: 66ff4c2416 DEC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::decrement(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0056f366: { // 0x56f366: 66ff4c2426 DEC word ptr [ESP + 0x26]
    m.w16((f.sp+0x00000026u), integer::decrement(m.r16((f.sp+0x00000026u)),16,flags));
  }
  L0056f36b: { // 0x56f36b: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f370: { // 0x56f370: e86b0a0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698421u); flags=s.arithmetic_flags;
  }
  L0056f375: { // 0x56f375: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f379: { // 0x56f379: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f381: { // 0x56f381: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f385: { // 0x56f385: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f38b: { // 0x56f38b: e8c0b61f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698448u); flags=s.arithmetic_flags;
  }
  L0056f390: { // 0x56f390: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f393: { // 0x56f393: 77d6 JA 0x0056f36b
    if(integer::condition("JA",flags)) goto L0056f36b;
  }
  L0056f395: { // 0x56f395: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f396: { // 0x56f396: 6601442414 ADD word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), integer::add(m.r16((f.sp+0x00000014u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f39b: { // 0x56f39b: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f3a0: { // 0x56f3a0: e83b0a0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698469u); flags=s.arithmetic_flags;
  }
  L0056f3a5: { // 0x56f3a5: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f3a9: { // 0x56f3a9: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f3b1: { // 0x56f3b1: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f3b5: { // 0x56f3b5: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f3bb: { // 0x56f3bb: e890b61f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698496u); flags=s.arithmetic_flags;
  }
  L0056f3c0: { // 0x56f3c0: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f3c3: { // 0x56f3c3: 77d6 JA 0x0056f39b
    if(integer::condition("JA",flags)) goto L0056f39b;
  }
  L0056f3c5: { // 0x56f3c5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f3c6: { // 0x56f3c6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f3c7: { // 0x56f3c7: 6601442428 ADD word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), integer::add(m.r16((f.sp+0x00000028u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f3cc: { // 0x56f3cc: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0056f3d0: { // 0x56f3d0: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f3d4: { // 0x56f3d4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f3d5: { // 0x56f3d5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f3d6: { // 0x56f3d6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f3d8: { // 0x56f3d8: e8530a0000 CALL 0x0056fe30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056fe30u,5698525u); flags=s.arithmetic_flags;
  }
  L0056f3dd: { // 0x56f3dd: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f3df: { // 0x56f3df: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f3e1: { // 0x56f3e1: 0f8594010000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f3e7: { // 0x56f3e7: f6c3c1 TEST BL,0xc1
    (void)integer::logical(((s.bx & 0xffu))&(0x000000c1u),8,flags);
  }
  L0056f3ea: { // 0x56f3ea: 0f85c4000000 JNZ 0x0056f4b4
    if(integer::condition("JNZ",flags)) goto L0056f4b4;
  }
  L0056f3f0: { // 0x56f3f0: f6c322 TEST BL,0x22
    (void)integer::logical(((s.bx & 0xffu))&(0x00000022u),8,flags);
  }
  L0056f3f3: { // 0x56f3f3: 0f84bb000000 JZ 0x0056f4b4
    if(integer::condition("JZ",flags)) goto L0056f4b4;
  }
  L0056f3f9: { // 0x56f3f9: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f3fc: { // 0x56f3fc: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f400: { // 0x56f400: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f402: { // 0x56f402: 8d5104 LEA EDX,[ECX + 0x4]
    s.dx = (s.cx+0x00000004u);
  }
  L0056f405: { // 0x56f405: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f408: { // 0x56f408: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  L0056f40b: { // 0x56f40b: 6689542414 MOV word ptr [ESP + 0x14],DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L0056f410: { // 0x56f410: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0056f415: { // 0x56f415: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L0056f41a: { // 0x56f41a: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f41f: { // 0x56f41f: 740a JZ 0x0056f42b
    if(integer::condition("JZ",flags)) goto L0056f42b;
  }
  L0056f421: { // 0x56f421: 66ff442424 INC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::increment(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f426: { // 0x56f426: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f42b: { // 0x56f42b: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L0056f42e: { // 0x56f42e: 740a JZ 0x0056f43a
    if(integer::condition("JZ",flags)) goto L0056f43a;
  }
  L0056f430: { // 0x56f430: 66ff4c2414 DEC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::decrement(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f435: { // 0x56f435: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f43a: { // 0x56f43a: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f43f: { // 0x56f43f: e89c090c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698628u); flags=s.arithmetic_flags;
  }
  L0056f444: { // 0x56f444: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f448: { // 0x56f448: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f450: { // 0x56f450: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f454: { // 0x56f454: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f45a: { // 0x56f45a: e8f1b51f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698655u); flags=s.arithmetic_flags;
  }
  L0056f45f: { // 0x56f45f: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f462: { // 0x56f462: 77d6 JA 0x0056f43a
    if(integer::condition("JA",flags)) goto L0056f43a;
  }
  L0056f464: { // 0x56f464: 6601442416 ADD word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), integer::add(m.r16((f.sp+0x00000016u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f469: { // 0x56f469: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f46e: { // 0x56f46e: e86d090c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698675u); flags=s.arithmetic_flags;
  }
  L0056f473: { // 0x56f473: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f477: { // 0x56f477: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f47f: { // 0x56f47f: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f483: { // 0x56f483: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f489: { // 0x56f489: e8c2b51f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698702u); flags=s.arithmetic_flags;
  }
  L0056f48e: { // 0x56f48e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f491: { // 0x56f491: 77d6 JA 0x0056f469
    if(integer::condition("JA",flags)) goto L0056f469;
  }
  L0056f493: { // 0x56f493: 6601442426 ADD word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), integer::add(m.r16((f.sp+0x00000026u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f498: { // 0x56f498: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0056f49c: { // 0x56f49c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f49d: { // 0x56f49d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f4a1: { // 0x56f4a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f4a2: { // 0x56f4a2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f4a3: { // 0x56f4a3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f4a5: { // 0x56f4a5: e8c60f0000 CALL 0x00570470
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570470u,5698730u); flags=s.arithmetic_flags;
  }
  L0056f4aa: { // 0x56f4aa: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f4ac: { // 0x56f4ac: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f4ae: { // 0x56f4ae: 0f85c7000000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f4b4: { // 0x56f4b4: f6c31c TEST BL,0x1c
    (void)integer::logical(((s.bx & 0xffu))&(0x0000001cu),8,flags);
  }
  L0056f4b7: { // 0x56f4b7: 0f85be000000 JNZ 0x0056f57b
    if(integer::condition("JNZ",flags)) goto L0056f57b;
  }
  L0056f4bd: { // 0x56f4bd: f6c322 TEST BL,0x22
    (void)integer::logical(((s.bx & 0xffu))&(0x00000022u),8,flags);
  }
  L0056f4c0: { // 0x56f4c0: 0f84b5000000 JZ 0x0056f57b
    if(integer::condition("JZ",flags)) goto L0056f57b;
  }
  L0056f4c6: { // 0x56f4c6: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f4c9: { // 0x56f4c9: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f4cd: { // 0x56f4cd: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f4cf: { // 0x56f4cf: 8d51fc LEA EDX,[ECX + -0x4]
    s.dx = (s.cx-0x00000004u);
  }
  L0056f4d2: { // 0x56f4d2: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0056f4d5: { // 0x56f4d5: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  L0056f4d8: { // 0x56f4d8: 6689542414 MOV word ptr [ESP + 0x14],DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L0056f4dd: { // 0x56f4dd: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0056f4e2: { // 0x56f4e2: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L0056f4e7: { // 0x56f4e7: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f4ec: { // 0x56f4ec: 740a JZ 0x0056f4f8
    if(integer::condition("JZ",flags)) goto L0056f4f8;
  }
  L0056f4ee: { // 0x56f4ee: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f4f3: { // 0x56f4f3: 66ff442424 INC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::increment(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f4f8: { // 0x56f4f8: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L0056f4fb: { // 0x56f4fb: 740a JZ 0x0056f507
    if(integer::condition("JZ",flags)) goto L0056f507;
  }
  L0056f4fd: { // 0x56f4fd: 66ff4c2424 DEC word ptr [ESP + 0x24]
    m.w16((f.sp+0x00000024u), integer::decrement(m.r16((f.sp+0x00000024u)),16,flags));
  }
  L0056f502: { // 0x56f502: 66ff4c2414 DEC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::decrement(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056f507: { // 0x56f507: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f50c: { // 0x56f50c: e8cf080c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698833u); flags=s.arithmetic_flags;
  }
  L0056f511: { // 0x56f511: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f515: { // 0x56f515: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f51d: { // 0x56f51d: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f521: { // 0x56f521: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f527: { // 0x56f527: e824b51f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698860u); flags=s.arithmetic_flags;
  }
  L0056f52c: { // 0x56f52c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f52f: { // 0x56f52f: 77d6 JA 0x0056f507
    if(integer::condition("JA",flags)) goto L0056f507;
  }
  L0056f531: { // 0x56f531: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f532: { // 0x56f532: 6601442416 ADD word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), integer::add(m.r16((f.sp+0x00000016u)),(s.ax & 0xffffu),16,flags));
  }
  L0056f537: { // 0x56f537: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056f53c: { // 0x56f53c: e89f080c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5698881u); flags=s.arithmetic_flags;
  }
  L0056f541: { // 0x56f541: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f545: { // 0x56f545: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0056f54d: { // 0x56f54d: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056f551: { // 0x56f551: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056f557: { // 0x56f557: e8f4b41f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5698908u); flags=s.arithmetic_flags;
  }
  L0056f55c: { // 0x56f55c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0056f55f: { // 0x56f55f: 77d6 JA 0x0056f537
    if(integer::condition("JA",flags)) goto L0056f537;
  }
  L0056f561: { // 0x56f561: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056f562: { // 0x56f562: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f563: { // 0x56f563: 660144242a ADD word ptr [ESP + 0x2a],AX
    m.w16((f.sp+0x0000002au), integer::add(m.r16((f.sp+0x0000002au)),(s.ax & 0xffffu),16,flags));
  }
  L0056f568: { // 0x56f568: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0056f56c: { // 0x56f56c: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0056f570: { // 0x56f570: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f571: { // 0x56f571: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f572: { // 0x56f572: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f574: { // 0x56f574: e867020000 CALL 0x0056f7e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056f7e0u,5698937u); flags=s.arithmetic_flags;
  }
  L0056f579: { // 0x56f579: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f57b: { // 0x56f57b: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0056f57f: { // 0x56f57f: d81d808d7800 FCOMP float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0056f585: { // 0x56f585: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0056f587: { // 0x56f587: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0056f58a: { // 0x56f58a: 0f851d010000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f590: { // 0x56f590: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f592: { // 0x56f592: 0f8515010000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f598: { // 0x56f598: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0056f59a: { // 0x56f59a: 83e708 AND EDI,0x8
    s.di = integer::logical((s.di)&(0x00000008u),32,flags);
  }
  L0056f59d: { // 0x56f59d: 7543 JNZ 0x0056f5e2
    if(integer::condition("JNZ",flags)) goto L0056f5e2;
  }
  L0056f59f: { // 0x56f59f: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f5a2: { // 0x56f5a2: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f5a6: { // 0x56f5a6: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f5a8: { // 0x56f5a8: 8d51fc LEA EDX,[ECX + -0x4]
    s.dx = (s.cx-0x00000004u);
  }
  L0056f5ab: { // 0x56f5ab: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0056f5ae: { // 0x56f5ae: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f5b3: { // 0x56f5b3: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L0056f5b8: { // 0x56f5b8: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0056f5bc: { // 0x56f5bc: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L0056f5c1: { // 0x56f5c1: 6689542424 MOV word ptr [ESP + 0x24],DX
    m.w16((f.sp+0x00000024u), (s.dx & 0xffffu));
  }
  L0056f5c6: { // 0x56f5c6: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0056f5ca: { // 0x56f5ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f5cb: { // 0x56f5cb: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L0056f5cf: { // 0x56f5cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f5d0: { // 0x56f5d0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f5d1: { // 0x56f5d1: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f5d3: { // 0x56f5d3: e808020000 CALL 0x0056f7e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056f7e0u,5699032u); flags=s.arithmetic_flags;
  }
  L0056f5d8: { // 0x56f5d8: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f5da: { // 0x56f5da: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f5dc: { // 0x56f5dc: 0f85cb000000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f5e2: { // 0x56f5e2: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L0056f5e5: { // 0x56f5e5: 7543 JNZ 0x0056f62a
    if(integer::condition("JNZ",flags)) goto L0056f62a;
  }
  L0056f5e7: { // 0x56f5e7: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0056f5eb: { // 0x56f5eb: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f5ee: { // 0x56f5ee: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0056f5f0: { // 0x56f5f0: 8d5104 LEA EDX,[ECX + 0x4]
    s.dx = (s.cx+0x00000004u);
  }
  L0056f5f3: { // 0x56f5f3: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f5f6: { // 0x56f5f6: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f5fb: { // 0x56f5fb: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L0056f600: { // 0x56f600: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0056f604: { // 0x56f604: 66894c242e MOV word ptr [ESP + 0x2e],CX
    m.w16((f.sp+0x0000002eu), (s.cx & 0xffffu));
  }
  L0056f609: { // 0x56f609: 6689542426 MOV word ptr [ESP + 0x26],DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L0056f60e: { // 0x56f60e: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0056f612: { // 0x56f612: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f613: { // 0x56f613: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L0056f617: { // 0x56f617: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f618: { // 0x56f618: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f619: { // 0x56f619: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f61b: { // 0x56f61b: e810080000 CALL 0x0056fe30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056fe30u,5699104u); flags=s.arithmetic_flags;
  }
  L0056f620: { // 0x56f620: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f622: { // 0x56f622: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f624: { // 0x56f624: 0f8583000000 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f62a: { // 0x56f62a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0056f62c: { // 0x56f62c: 753f JNZ 0x0056f66d
    if(integer::condition("JNZ",flags)) goto L0056f66d;
  }
  L0056f62e: { // 0x56f62e: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0056f631: { // 0x56f631: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0056f635: { // 0x56f635: 8d4104 LEA EAX,[ECX + 0x4]
    s.ax = (s.cx+0x00000004u);
  }
  L0056f638: { // 0x56f638: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L0056f63b: { // 0x56f63b: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f640: { // 0x56f640: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0056f644: { // 0x56f644: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f646: { // 0x56f646: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L0056f64b: { // 0x56f64b: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0056f64f: { // 0x56f64f: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056f654: { // 0x56f654: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L0056f659: { // 0x56f659: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f65a: { // 0x56f65a: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0056f65e: { // 0x56f65e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f65f: { // 0x56f65f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f660: { // 0x56f660: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f662: { // 0x56f662: e8090e0000 CALL 0x00570470
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570470u,5699175u); flags=s.arithmetic_flags;
  }
  L0056f667: { // 0x56f667: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f669: { // 0x56f669: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056f66b: { // 0x56f66b: 7540 JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f66d: { // 0x56f66d: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  L0056f670: { // 0x56f670: 753b JNZ 0x0056f6ad
    if(integer::condition("JNZ",flags)) goto L0056f6ad;
  }
  L0056f672: { // 0x56f672: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0056f675: { // 0x56f675: 668b7602 MOV SI,word ptr [ESI + 0x2]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.si+0x00000002u))) & 0xffffu);
  }
  L0056f679: { // 0x56f679: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0056f67d: { // 0x56f67d: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0056f67f: { // 0x56f67f: 8d4efc LEA ECX,[ESI + -0x4]
    s.cx = (s.si-0x00000004u);
  }
  L0056f682: { // 0x56f682: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056f687: { // 0x56f687: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L0056f68c: { // 0x56f68c: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L0056f691: { // 0x56f691: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0056f695: { // 0x56f695: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f696: { // 0x56f696: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0056f69a: { // 0x56f69a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f69b: { // 0x56f69b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0056f69e: { // 0x56f69e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f69f: { // 0x56f69f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0056f6a1: { // 0x56f6a1: 668974243a MOV word ptr [ESP + 0x3a],SI
    m.w16((f.sp+0x0000003au), (s.si & 0xffffu));
  }
  L0056f6a6: { // 0x56f6a6: e885140000 CALL 0x00570b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00570b30u,5699243u); flags=s.arithmetic_flags;
  }
  L0056f6ab: { // 0x56f6ab: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0056f6ad: { // 0x56f6ad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f6ae: { // 0x56f6ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f6af: { // 0x56f6af: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f6b0: { // 0x56f6b0: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L0056f6b2: { // 0x56f6b2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f6b3: { // 0x56f6b3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0056f6b6: { // 0x56f6b6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
