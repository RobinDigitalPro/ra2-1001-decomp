#include "recovered/recovery_b1658.hpp"
namespace ra2::recovered::b1658 {
using namespace floating_b61;
using Frame=recovery_b566::Frame;
using recovery_b566::finish;using recovery_b566::string_instruction;using recovery_b566::Kind;using recovery_b566::Repeat;using recovery_b566::reverse_divide32;using recovery_b566::reverse_divide64;
namespace integer=direct_b33::integer;namespace floating_b61=ra2::recovered::floating_b61;namespace numeric_b88=ra2::recovered::numeric_b88;
namespace {
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_002c9970(Memory&,State&,Frame&,const Operations&);
void f_000ce770(Memory&,State&,Frame&,const Operations&);
void f_000cdd40(Memory&,State&,Frame&,const Operations&);
void f_0006cc20(Memory&,State&,Frame&,const Operations&);
void f_0006ce50(Memory&,State&,Frame&,const Operations&);
void f_00101930(Memory&,State&,Frame&,const Operations&);
void f_002bf0c0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);

void f_002c9970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c9970: { // 0x6c9970: 83ec38 SUB ESP,0x38
    f.sp = integer::sub(f.sp,0x00000038u,32,flags);
  }
  L006c9973: { // 0x6c9973: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c9974: { // 0x6c9974: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c9975: { // 0x6c9975: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006c9977: { // 0x6c9977: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006c9979: { // 0x6c9979: 399fb8030000 CMP dword ptr [EDI + 0x3b8],EBX
    (void)integer::sub(m.r32((s.di+0x000003b8u)),s.bx,32,flags);
  }
  L006c997f: { // 0x6c997f: 7515 JNZ 0x006c9996
    if(integer::condition("JNZ",flags)) goto L006c9996;
  }
  L006c9981: { // 0x6c9981: 8b87c0030000 MOV EAX,dword ptr [EDI + 0x3c0]
    s.ax = m.r32((s.di+0x000003c0u));
  }
  L006c9987: { // 0x6c9987: 8d8fc0030000 LEA ECX,[EDI + 0x3c0]
    s.cx = (s.di+0x000003c0u);
  }
  L006c998d: { // 0x6c998d: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),7117200u,op); flags=s.arithmetic_flags;
  }
  L006c9990: { // 0x6c9990: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c9991: { // 0x6c9991: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c9992: { // 0x6c9992: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  L006c9995: { // 0x6c9995: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c9996: { // 0x6c9996: 8b97d0030000 MOV EDX,dword ptr [EDI + 0x3d0]
    s.dx = m.r32((s.di+0x000003d0u));
  }
  L006c999c: { // 0x6c999c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c999d: { // 0x6c999d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006c999e: { // 0x6c999e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c999f: { // 0x6c999f: 785b JS 0x006c99fc
    if(integer::condition("JS",flags)) goto L006c99fc;
  }
  L006c99a1: { // 0x6c99a1: 8b8fc4030000 MOV ECX,dword ptr [EDI + 0x3c4]
    s.cx = m.r32((s.di+0x000003c4u));
  }
  L006c99a7: { // 0x6c99a7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c99a9: { // 0x6c99a9: 8b2c91 MOV EBP,dword ptr [ECX + EDX*0x4]
    s.bp = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L006c99ac: { // 0x6c99ac: 8b8fb8030000 MOV ECX,dword ptr [EDI + 0x3b8]
    s.cx = m.r32((s.di+0x000003b8u));
  }
  L006c99b2: { // 0x6c99b2: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006c99b4: { // 0x6c99b4: 7e12 JLE 0x006c99c8
    if(integer::condition("JLE",flags)) goto L006c99c8;
  }
  L006c99b6: { // 0x6c99b6: 8bb7ac030000 MOV ESI,dword ptr [EDI + 0x3ac]
    s.si = m.r32((s.di+0x000003acu));
  }
  L006c99bc: { // 0x6c99bc: 3b2e CMP EBP,dword ptr [ESI]
    (void)integer::sub(s.bp,m.r32((s.si)),32,flags);
  }
  L006c99be: { // 0x6c99be: 7439 JZ 0x006c99f9
    if(integer::condition("JZ",flags)) goto L006c99f9;
  }
  L006c99c0: { // 0x6c99c0: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006c99c1: { // 0x6c99c1: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L006c99c4: { // 0x6c99c4: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006c99c6: { // 0x6c99c6: 7cf4 JL 0x006c99bc
    if(integer::condition("JL",flags)) goto L006c99bc;
  }
  L006c99c8: { // 0x6c99c8: 8b87d0030000 MOV EAX,dword ptr [EDI + 0x3d0]
    s.ax = m.r32((s.di+0x000003d0u));
  }
  L006c99ce: { // 0x6c99ce: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006c99d0: { // 0x6c99d0: 7d27 JGE 0x006c99f9
    if(integer::condition("JGE",flags)) goto L006c99f9;
  }
  L006c99d2: { // 0x6c99d2: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L006c99d5: { // 0x6c99d5: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006c99d7: { // 0x6c99d7: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L006c99d9: { // 0x6c99d9: 898fd0030000 MOV dword ptr [EDI + 0x3d0],ECX
    m.w32((s.di+0x000003d0u), s.cx);
  }
  L006c99df: { // 0x6c99df: 7d18 JGE 0x006c99f9
    if(integer::condition("JGE",flags)) goto L006c99f9;
  }
  L006c99e1: { // 0x6c99e1: 8b8fc4030000 MOV ECX,dword ptr [EDI + 0x3c4]
    s.cx = m.r32((s.di+0x000003c4u));
  }
  L006c99e7: { // 0x6c99e7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006c99e8: { // 0x6c99e8: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006c99eb: { // 0x6c99eb: 897481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.si);
  }
  L006c99ef: { // 0x6c99ef: 8b8fd0030000 MOV ECX,dword ptr [EDI + 0x3d0]
    s.cx = m.r32((s.di+0x000003d0u));
  }
  L006c99f5: { // 0x6c99f5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006c99f7: { // 0x6c99f7: 7ce8 JL 0x006c99e1
    if(integer::condition("JL",flags)) goto L006c99e1;
  }
  L006c99f9: { // 0x6c99f9: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006c99fa: { // 0x6c99fa: 79a5 JNS 0x006c99a1
    if(integer::condition("JNS",flags)) goto L006c99a1;
  }
  L006c99fc: { // 0x6c99fc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c99fd: { // 0x6c99fd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c99fe: { // 0x6c99fe: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L006c9a02: { // 0x6c9a02: e8694de0ff CALL 0x004ce770
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ce770u,7117319u,op); flags=s.arithmetic_flags;
  }
  L006c9a07: { // 0x6c9a07: be0a000000 MOV ESI,0xa
    s.si = 0x0000000au;
  }
  L006c9a0c: { // 0x6c9a0c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c9a0d: { // 0x6c9a0d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c9a0e: { // 0x6c9a0e: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006c9a12: { // 0x6c9a12: c74424387cc77800 MOV dword ptr [ESP + 0x38],0x78c77c
    m.w32((f.sp+0x00000038u), 0x0078c77cu);
  }
  L006c9a1a: { // 0x6c9a1a: 8974244c MOV dword ptr [ESP + 0x4c],ESI
    m.w32((f.sp+0x0000004cu), s.si);
  }
  L006c9a1e: { // 0x6c9a1e: 895c2448 MOV dword ptr [ESP + 0x48],EBX
    m.w32((f.sp+0x00000048u), s.bx);
  }
  L006c9a22: { // 0x6c9a22: e8f931daff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7117351u,op); flags=s.arithmetic_flags;
  }
  L006c9a27: { // 0x6c9a27: 8bafd0030000 MOV EBP,dword ptr [EDI + 0x3d0]
    s.bp = m.r32((s.di+0x000003d0u));
  }
  L006c9a2d: { // 0x6c9a2d: c7442418948a7800 MOV dword ptr [ESP + 0x18],0x788a94
    m.w32((f.sp+0x00000018u), 0x00788a94u);
  }
  L006c9a35: { // 0x6c9a35: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L006c9a37: { // 0x6c9a37: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L006c9a3b: { // 0x6c9a3b: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L006c9a3f: { // 0x6c9a3f: 0f8eef000000 JLE 0x006c9b34
    if(integer::condition("JLE",flags)) goto L006c9b34;
  }
  L006c9a45: { // 0x6c9a45: 8b8fb8030000 MOV ECX,dword ptr [EDI + 0x3b8]
    s.cx = m.r32((s.di+0x000003b8u));
  }
  L006c9a4b: { // 0x6c9a4b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c9a4d: { // 0x6c9a4d: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006c9a4f: { // 0x6c9a4f: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006c9a53: { // 0x6c9a53: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006c9a57: { // 0x6c9a57: 0f8ed7000000 JLE 0x006c9b34
    if(integer::condition("JLE",flags)) goto L006c9b34;
  }
  L006c9a5d: { // 0x6c9a5d: 8b97ac030000 MOV EDX,dword ptr [EDI + 0x3ac]
    s.dx = m.r32((s.di+0x000003acu));
  }
  L006c9a63: { // 0x6c9a63: 8d1c8500000000 LEA EBX,[EAX*0x4 + 0x0]
    s.bx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  L006c9a6a: { // 0x6c9a6a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c9a6c: { // 0x6c9a6c: 8b341a MOV ESI,dword ptr [EDX + EBX*0x1]
    s.si = m.r32((s.dx+(s.bx * 0x00000001u)));
  }
  L006c9a6f: { // 0x6c9a6f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006c9a71: { // 0x6c9a71: 7e16 JLE 0x006c9a89
    if(integer::condition("JLE",flags)) goto L006c9a89;
  }
  L006c9a73: { // 0x6c9a73: 8b8fc4030000 MOV ECX,dword ptr [EDI + 0x3c4]
    s.cx = m.r32((s.di+0x000003c4u));
  }
  L006c9a79: { // 0x6c9a79: 3b31 CMP ESI,dword ptr [ECX]
    (void)integer::sub(s.si,m.r32((s.cx)),32,flags);
  }
  L006c9a7b: { // 0x6c9a7b: 0f849e000000 JZ 0x006c9b1f
    if(integer::condition("JZ",flags)) goto L006c9b1f;
  }
  L006c9a81: { // 0x6c9a81: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006c9a82: { // 0x6c9a82: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L006c9a85: { // 0x6c9a85: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006c9a87: { // 0x6c9a87: 7cf0 JL 0x006c9a79
    if(integer::condition("JL",flags)) goto L006c9a79;
  }
  L006c9a89: { // 0x6c9a89: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L006c9a8d: { // 0x6c9a8d: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L006c9a91: { // 0x6c9a91: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006c9a93: { // 0x6c9a93: 7c28 JL 0x006c9abd
    if(integer::condition("JL",flags)) goto L006c9abd;
  }
  L006c9a95: { // 0x6c9a95: 8a4c243d MOV CL,byte ptr [ESP + 0x3d]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000003du)));
  }
  L006c9a99: { // 0x6c9a99: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9a9b: { // 0x6c9a9b: 7504 JNZ 0x006c9aa1
    if(integer::condition("JNZ",flags)) goto L006c9aa1;
  }
  L006c9a9d: { // 0x6c9a9d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9a9f: { // 0x6c9a9f: 752e JNZ 0x006c9acf
    if(integer::condition("JNZ",flags)) goto L006c9acf;
  }
  L006c9aa1: { // 0x6c9aa1: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L006c9aa5: { // 0x6c9aa5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c9aa7: { // 0x6c9aa7: 7e26 JLE 0x006c9acf
    if(integer::condition("JLE",flags)) goto L006c9acf;
  }
  L006c9aa9: { // 0x6c9aa9: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006c9aab: { // 0x6c9aab: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c9aad: { // 0x6c9aad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c9aae: { // 0x6c9aae: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L006c9ab2: { // 0x6c9ab2: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L006c9ab6: { // 0x6c9ab6: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),7117497u,op); flags=s.arithmetic_flags;
  }
  L006c9ab9: { // 0x6c9ab9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c9abb: { // 0x6c9abb: 7412 JZ 0x006c9acf
    if(integer::condition("JZ",flags)) goto L006c9acf;
  }
  L006c9abd: { // 0x6c9abd: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L006c9ac1: { // 0x6c9ac1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006c9ac3: { // 0x6c9ac3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006c9ac4: { // 0x6c9ac4: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006c9ac8: { // 0x6c9ac8: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L006c9acc: { // 0x6c9acc: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006c9acf: { // 0x6c9acf: 8bb794030000 MOV ESI,dword ptr [EDI + 0x394]
    s.si = m.r32((s.di+0x00000394u));
  }
  L006c9ad5: { // 0x6c9ad5: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006c9ad9: { // 0x6c9ad9: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006c9add: { // 0x6c9add: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L006c9adf: { // 0x6c9adf: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006c9ae1: { // 0x6c9ae1: 7c28 JL 0x006c9b0b
    if(integer::condition("JL",flags)) goto L006c9b0b;
  }
  L006c9ae3: { // 0x6c9ae3: 8a4c2425 MOV CL,byte ptr [ESP + 0x25]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000025u)));
  }
  L006c9ae7: { // 0x6c9ae7: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9ae9: { // 0x6c9ae9: 7504 JNZ 0x006c9aef
    if(integer::condition("JNZ",flags)) goto L006c9aef;
  }
  L006c9aeb: { // 0x6c9aeb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9aed: { // 0x6c9aed: 7530 JNZ 0x006c9b1f
    if(integer::condition("JNZ",flags)) goto L006c9b1f;
  }
  L006c9aef: { // 0x6c9aef: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006c9af3: { // 0x6c9af3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c9af5: { // 0x6c9af5: 7e28 JLE 0x006c9b1f
    if(integer::condition("JLE",flags)) goto L006c9b1f;
  }
  L006c9af7: { // 0x6c9af7: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L006c9afb: { // 0x6c9afb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006c9afd: { // 0x6c9afd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c9aff: { // 0x6c9aff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c9b00: { // 0x6c9b00: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006c9b04: { // 0x6c9b04: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7117575u,op); flags=s.arithmetic_flags;
  }
  L006c9b07: { // 0x6c9b07: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c9b09: { // 0x6c9b09: 7414 JZ 0x006c9b1f
    if(integer::condition("JZ",flags)) goto L006c9b1f;
  }
  L006c9b0b: { // 0x6c9b0b: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006c9b0f: { // 0x6c9b0f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L006c9b13: { // 0x6c9b13: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006c9b15: { // 0x6c9b15: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006c9b16: { // 0x6c9b16: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L006c9b1a: { // 0x6c9b1a: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L006c9b1c: { // 0x6c9b1c: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L006c9b1f: { // 0x6c9b1f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006c9b23: { // 0x6c9b23: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006c9b27: { // 0x6c9b27: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006c9b28: { // 0x6c9b28: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006c9b2a: { // 0x6c9b2a: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006c9b2e: { // 0x6c9b2e: 0f8c29ffffff JL 0x006c9a5d
    if(integer::condition("JL",flags)) goto L006c9a5d;
  }
  L006c9b34: { // 0x6c9b34: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L006c9b38: { // 0x6c9b38: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c9b3a: { // 0x6c9b3a: 7549 JNZ 0x006c9b85
    if(integer::condition("JNZ",flags)) goto L006c9b85;
  }
  L006c9b3c: { // 0x6c9b3c: 8b87c0030000 MOV EAX,dword ptr [EDI + 0x3c0]
    s.ax = m.r32((s.di+0x000003c0u));
  }
  L006c9b42: { // 0x6c9b42: 8d8fc0030000 LEA ECX,[EDI + 0x3c0]
    s.cx = (s.di+0x000003c0u);
  }
  L006c9b48: { // 0x6c9b48: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),7117643u,op); flags=s.arithmetic_flags;
  }
  L006c9b4b: { // 0x6c9b4b: 8bafb8030000 MOV EBP,dword ptr [EDI + 0x3b8]
    s.bp = m.r32((s.di+0x000003b8u));
  }
  L006c9b51: { // 0x6c9b51: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006c9b53: { // 0x6c9b53: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006c9b55: { // 0x6c9b55: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c9b57: { // 0x6c9b57: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006c9b59: { // 0x6c9b59: 7e1d JLE 0x006c9b78
    if(integer::condition("JLE",flags)) goto L006c9b78;
  }
  L006c9b5b: { // 0x6c9b5b: 8b9f94030000 MOV EBX,dword ptr [EDI + 0x394]
    s.bx = m.r32((s.di+0x00000394u));
  }
  L006c9b61: { // 0x6c9b61: 8b0c83 MOV ECX,dword ptr [EBX + EAX*0x4]
    s.cx = m.r32((s.bx+(s.ax * 0x00000004u)));
  }
  L006c9b64: { // 0x6c9b64: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006c9b66: { // 0x6c9b66: 7e0b JLE 0x006c9b73
    if(integer::condition("JLE",flags)) goto L006c9b73;
  }
  L006c9b68: { // 0x6c9b68: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006c9b6a: { // 0x6c9b6a: 8b8fac030000 MOV ECX,dword ptr [EDI + 0x3ac]
    s.cx = m.r32((s.di+0x000003acu));
  }
  L006c9b70: { // 0x6c9b70: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006c9b73: { // 0x6c9b73: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006c9b74: { // 0x6c9b74: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006c9b76: { // 0x6c9b76: 7ce9 JL 0x006c9b61
    if(integer::condition("JL",flags)) goto L006c9b61;
  }
  L006c9b78: { // 0x6c9b78: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006c9b7a: { // 0x6c9b7a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c9b7b: { // 0x6c9b7b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c9b7d: { // 0x6c9b7d: ff9270030000 CALL dword ptr [EDX + 0x370]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000370u)),7117699u,op); flags=s.arithmetic_flags;
  }
  L006c9b83: { // 0x6c9b83: eb33 JMP 0x006c9bb8
    goto L006c9bb8;
  }
  L006c9b85: { // 0x6c9b85: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006c9b87: { // 0x6c9b87: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006c9b89: { // 0x6c9b89: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c9b8b: { // 0x6c9b8b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c9b8d: { // 0x6c9b8d: 7e1e JLE 0x006c9bad
    if(integer::condition("JLE",flags)) goto L006c9bad;
  }
  L006c9b8f: { // 0x6c9b8f: 8b6c2434 MOV EBP,dword ptr [ESP + 0x34]
    s.bp = m.r32((f.sp+0x00000034u));
  }
  L006c9b93: { // 0x6c9b93: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L006c9b97: { // 0x6c9b97: 8b0c83 MOV ECX,dword ptr [EBX + EAX*0x4]
    s.cx = m.r32((s.bx+(s.ax * 0x00000004u)));
  }
  L006c9b9a: { // 0x6c9b9a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006c9b9c: { // 0x6c9b9c: 7e06 JLE 0x006c9ba4
    if(integer::condition("JLE",flags)) goto L006c9ba4;
  }
  L006c9b9e: { // 0x6c9b9e: 8b748500 MOV ESI,dword ptr [EBP + EAX*0x4]
    s.si = m.r32((s.bp+(s.ax * 0x00000004u)));
  }
  L006c9ba2: { // 0x6c9ba2: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006c9ba4: { // 0x6c9ba4: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L006c9ba8: { // 0x6c9ba8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006c9ba9: { // 0x6c9ba9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006c9bab: { // 0x6c9bab: 7cea JL 0x006c9b97
    if(integer::condition("JL",flags)) goto L006c9b97;
  }
  L006c9bad: { // 0x6c9bad: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006c9baf: { // 0x6c9baf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c9bb0: { // 0x6c9bb0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c9bb2: { // 0x6c9bb2: ff9070030000 CALL dword ptr [EAX + 0x370]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000370u)),7117752u,op); flags=s.arithmetic_flags;
  }
  L006c9bb8: { // 0x6c9bb8: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006c9bbc: { // 0x6c9bbc: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006c9bbe: { // 0x6c9bbe: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L006c9bc0: { // 0x6c9bc0: c7442418d4897800 MOV dword ptr [ESP + 0x18],0x7889d4
    m.w32((f.sp+0x00000018u), 0x007889d4u);
  }
  L006c9bc8: { // 0x6c9bc8: 7415 JZ 0x006c9bdf
    if(integer::condition("JZ",flags)) goto L006c9bdf;
  }
  L006c9bca: { // 0x6c9bca: 8a4c2425 MOV CL,byte ptr [ESP + 0x25]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000025u)));
  }
  L006c9bce: { // 0x6c9bce: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9bd0: { // 0x6c9bd0: 740d JZ 0x006c9bdf
    if(integer::condition("JZ",flags)) goto L006c9bdf;
  }
  L006c9bd2: { // 0x6c9bd2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c9bd3: { // 0x6c9bd3: e8a33a0a00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7117784u,op); flags=s.arithmetic_flags;
  }
  L006c9bd8: { // 0x6c9bd8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006c9bdb: { // 0x6c9bdb: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L006c9bdf: { // 0x6c9bdf: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L006c9be3: { // 0x6c9be3: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L006c9be7: { // 0x6c9be7: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L006c9be9: { // 0x6c9be9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c9bea: { // 0x6c9bea: c644242100 MOV byte ptr [ESP + 0x21],0x0
    m.w8((f.sp+0x00000021u), 0x00000000u);
  }
  L006c9bef: { // 0x6c9bef: c744242c9cc77800 MOV dword ptr [ESP + 0x2c],0x78c79c
    m.w32((f.sp+0x0000002cu), 0x0078c79cu);
  }
  L006c9bf7: { // 0x6c9bf7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c9bf8: { // 0x6c9bf8: 7411 JZ 0x006c9c0b
    if(integer::condition("JZ",flags)) goto L006c9c0b;
  }
  L006c9bfa: { // 0x6c9bfa: 8a4c2435 MOV CL,byte ptr [ESP + 0x35]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000035u)));
  }
  L006c9bfe: { // 0x6c9bfe: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9c00: { // 0x6c9c00: 7409 JZ 0x006c9c0b
    if(integer::condition("JZ",flags)) goto L006c9c0b;
  }
  L006c9c02: { // 0x6c9c02: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c9c03: { // 0x6c9c03: e8733a0a00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7117832u,op); flags=s.arithmetic_flags;
  }
  L006c9c08: { // 0x6c9c08: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006c9c0b: { // 0x6c9c0b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c9c0c: { // 0x6c9c0c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c9c0d: { // 0x6c9c0d: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  L006c9c10: { // 0x6c9c10: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000ce770(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ce770: { // 0x4ce770: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004ce774: { // 0x4ce774: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ce775: { // 0x4ce775: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004ce777: { // 0x4ce777: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004ce779: { // 0x4ce779: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004ce77b: { // 0x4ce77b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004ce77e: { // 0x4ce77e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004ce781: { // 0x4ce781: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L004ce785: { // 0x4ce785: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L004ce788: { // 0x4ce788: c7069cc77800 MOV dword ptr [ESI],0x78c79c
    m.w32((s.si), 0x0078c79cu);
  }
  L004ce78e: { // 0x4ce78e: 7424 JZ 0x004ce7b4
    if(integer::condition("JZ",flags)) goto L004ce7b4;
  }
  L004ce790: { // 0x4ce790: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004ce794: { // 0x4ce794: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004ce796: { // 0x4ce796: 7409 JZ 0x004ce7a1
    if(integer::condition("JZ",flags)) goto L004ce7a1;
  }
  L004ce798: { // 0x4ce798: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004ce79b: { // 0x4ce79b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ce79d: { // 0x4ce79d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ce79e: { // 0x4ce79e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004ce7a1: { // 0x4ce7a1: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L004ce7a4: { // 0x4ce7a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ce7a5: { // 0x4ce7a5: e8adf12900 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5040042u,op); flags=s.arithmetic_flags;
  }
  L004ce7aa: { // 0x4ce7aa: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004ce7ad: { // 0x4ce7ad: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004ce7b0: { // 0x4ce7b0: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L004ce7b4: { // 0x4ce7b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ce7b6: { // 0x4ce7b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ce7b7: { // 0x4ce7b7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000cdd40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cdd40: { // 0x4cdd40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004cdd41: { // 0x4cdd41: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004cdd42: { // 0x4cdd42: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L004cdd46: { // 0x4cdd46: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004cdd47: { // 0x4cdd47: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004cdd49: { // 0x4cdd49: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004cdd4a: { // 0x4cdd4a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004cdd4c: { // 0x4cdd4c: 747c JZ 0x004cddca
    if(integer::condition("JZ",flags)) goto L004cddca;
  }
  L004cdd4e: { // 0x4cdd4e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L004cdd52: { // 0x4cdd52: c6460c00 MOV byte ptr [ESI + 0xc],0x0
    m.w8((s.si+0x0000000cu), 0x00000000u);
  }
  L004cdd56: { // 0x4cdd56: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004cdd58: { // 0x4cdd58: 7514 JNZ 0x004cdd6e
    if(integer::condition("JNZ",flags)) goto L004cdd6e;
  }
  L004cdd5a: { // 0x4cdd5a: 8d04ad00000000 LEA EAX,[EBP*0x4 + 0x0]
    s.ax = ((s.bp * 0x00000004u)+0x00000000u);
  }
  L004cdd61: { // 0x4cdd61: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004cdd62: { // 0x4cdd62: e8f0fb2900 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5037415u,op); flags=s.arithmetic_flags;
  }
  L004cdd67: { // 0x4cdd67: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004cdd6a: { // 0x4cdd6a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004cdd6c: { // 0x4cdd6c: eb02 JMP 0x004cdd70
    goto L004cdd70;
  }
  L004cdd6e: { // 0x4cdd6e: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L004cdd70: { // 0x4cdd70: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004cdd72: { // 0x4cdd72: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L004cdd76: { // 0x4cdd76: 746f JZ 0x004cdde7
    if(integer::condition("JZ",flags)) goto L004cdde7;
  }
  L004cdd78: { // 0x4cdd78: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L004cdd7b: { // 0x4cdd7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004cdd7d: { // 0x4cdd7d: 7439 JZ 0x004cddb8
    if(integer::condition("JZ",flags)) goto L004cddb8;
  }
  L004cdd7f: { // 0x4cdd7f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L004cdd82: { // 0x4cdd82: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L004cdd84: { // 0x4cdd84: 7d02 JGE 0x004cdd88
    if(integer::condition("JGE",flags)) goto L004cdd88;
  }
  L004cdd86: { // 0x4cdd86: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004cdd88: { // 0x4cdd88: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004cdd8a: { // 0x4cdd8a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004cdd8c: { // 0x4cdd8c: 7e10 JLE 0x004cdd9e
    if(integer::condition("JLE",flags)) goto L004cdd9e;
  }
  L004cdd8e: { // 0x4cdd8e: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L004cdd91: { // 0x4cdd91: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004cdd92: { // 0x4cdd92: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004cdd94: { // 0x4cdd94: 8b5482fc MOV EDX,dword ptr [EDX + EAX*0x4 + -0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)-0x00000004u));
  }
  L004cdd98: { // 0x4cdd98: 895487fc MOV dword ptr [EDI + EAX*0x4 + -0x4],EDX
    m.w32((s.di+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L004cdd9c: { // 0x4cdd9c: 7cf0 JL 0x004cdd8e
    if(integer::condition("JL",flags)) goto L004cdd8e;
  }
  L004cdd9e: { // 0x4cdd9e: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L004cdda1: { // 0x4cdda1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004cdda3: { // 0x4cdda3: 7413 JZ 0x004cddb8
    if(integer::condition("JZ",flags)) goto L004cddb8;
  }
  L004cdda5: { // 0x4cdda5: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L004cdda8: { // 0x4cdda8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004cdda9: { // 0x4cdda9: e8cdf82900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5037486u,op); flags=s.arithmetic_flags;
  }
  L004cddae: { // 0x4cddae: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004cddb1: { // 0x4cddb1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L004cddb8: { // 0x4cddb8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004cddba: { // 0x4cddba: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L004cddbd: { // 0x4cddbd: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004cddbf: { // 0x4cddbf: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004cddc2: { // 0x4cddc2: 896e08 MOV dword ptr [ESI + 0x8],EBP
    m.w32((s.si+0x00000008u), s.bp);
  }
  L004cddc5: { // 0x4cddc5: 88460d MOV byte ptr [ESI + 0xd],AL
    m.w8((s.si+0x0000000du), (s.ax & 0xffu));
  }
  L004cddc8: { // 0x4cddc8: eb07 JMP 0x004cddd1
    goto L004cddd1;
  }
  L004cddca: { // 0x4cddca: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004cddcc: { // 0x4cddcc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004cddce: { // 0x4cddce: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),5037521u,op); flags=s.arithmetic_flags;
  }
  L004cddd1: { // 0x4cddd1: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L004cddd4: { // 0x4cddd4: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004cddd7: { // 0x4cddd7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004cddd9: { // 0x4cddd9: 7d03 JGE 0x004cddde
    if(integer::condition("JGE",flags)) goto L004cddde;
  }
  L004cdddb: { // 0x4cdddb: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L004cddde: { // 0x4cddde: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004cdddf: { // 0x4cdddf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cdde0: { // 0x4cdde0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004cdde1: { // 0x4cdde1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004cdde3: { // 0x4cdde3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004cdde4: { // 0x4cdde4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004cdde7: { // 0x4cdde7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004cdde8: { // 0x4cdde8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cdde9: { // 0x4cdde9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004cddea: { // 0x4cddea: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004cddec: { // 0x4cddec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004cdded: { // 0x4cdded: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_0006cc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046cc20: { // 0x46cc20: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0046cc24: { // 0x46cc24: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046cc25: { // 0x46cc25: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046cc27: { // 0x46cc27: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0046cc29: { // 0x46cc29: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0046cc2b: { // 0x46cc2b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L0046cc2e: { // 0x46cc2e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0046cc31: { // 0x46cc31: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0046cc35: { // 0x46cc35: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L0046cc38: { // 0x46cc38: c706d4897800 MOV dword ptr [ESI],0x7889d4
    m.w32((s.si), 0x007889d4u);
  }
  L0046cc3e: { // 0x46cc3e: 7424 JZ 0x0046cc64
    if(integer::condition("JZ",flags)) goto L0046cc64;
  }
  L0046cc40: { // 0x46cc40: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0046cc44: { // 0x46cc44: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0046cc46: { // 0x46cc46: 7409 JZ 0x0046cc51
    if(integer::condition("JZ",flags)) goto L0046cc51;
  }
  L0046cc48: { // 0x46cc48: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L0046cc4b: { // 0x46cc4b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0046cc4d: { // 0x46cc4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cc4e: { // 0x46cc4e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0046cc51: { // 0x46cc51: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0046cc54: { // 0x46cc54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046cc55: { // 0x46cc55: e8fd0c3000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4639834u,op); flags=s.arithmetic_flags;
  }
  L0046cc5a: { // 0x46cc5a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046cc5d: { // 0x46cc5d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0046cc60: { // 0x46cc60: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0046cc64: { // 0x46cc64: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0046cc66: { // 0x46cc66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cc67: { // 0x46cc67: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_0006ce50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046ce50: { // 0x46ce50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0046ce51: { // 0x46ce51: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0046ce52: { // 0x46ce52: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L0046ce56: { // 0x46ce56: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046ce57: { // 0x46ce57: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0046ce59: { // 0x46ce59: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0046ce5a: { // 0x46ce5a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046ce5c: { // 0x46ce5c: 747c JZ 0x0046ceda
    if(integer::condition("JZ",flags)) goto L0046ceda;
  }
  L0046ce5e: { // 0x46ce5e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0046ce62: { // 0x46ce62: c6460c00 MOV byte ptr [ESI + 0xc],0x0
    m.w8((s.si+0x0000000cu), 0x00000000u);
  }
  L0046ce66: { // 0x46ce66: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0046ce68: { // 0x46ce68: 7514 JNZ 0x0046ce7e
    if(integer::condition("JNZ",flags)) goto L0046ce7e;
  }
  L0046ce6a: { // 0x46ce6a: 8d04ad00000000 LEA EAX,[EBP*0x4 + 0x0]
    s.ax = ((s.bp * 0x00000004u)+0x00000000u);
  }
  L0046ce71: { // 0x46ce71: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046ce72: { // 0x46ce72: e8e00a3000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4640375u,op); flags=s.arithmetic_flags;
  }
  L0046ce77: { // 0x46ce77: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046ce7a: { // 0x46ce7a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0046ce7c: { // 0x46ce7c: eb02 JMP 0x0046ce80
    goto L0046ce80;
  }
  L0046ce7e: { // 0x46ce7e: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0046ce80: { // 0x46ce80: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0046ce82: { // 0x46ce82: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0046ce86: { // 0x46ce86: 746f JZ 0x0046cef7
    if(integer::condition("JZ",flags)) goto L0046cef7;
  }
  L0046ce88: { // 0x46ce88: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0046ce8b: { // 0x46ce8b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0046ce8d: { // 0x46ce8d: 7439 JZ 0x0046cec8
    if(integer::condition("JZ",flags)) goto L0046cec8;
  }
  L0046ce8f: { // 0x46ce8f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0046ce92: { // 0x46ce92: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L0046ce94: { // 0x46ce94: 7d02 JGE 0x0046ce98
    if(integer::condition("JGE",flags)) goto L0046ce98;
  }
  L0046ce96: { // 0x46ce96: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0046ce98: { // 0x46ce98: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0046ce9a: { // 0x46ce9a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0046ce9c: { // 0x46ce9c: 7e10 JLE 0x0046ceae
    if(integer::condition("JLE",flags)) goto L0046ceae;
  }
  L0046ce9e: { // 0x46ce9e: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0046cea1: { // 0x46cea1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0046cea2: { // 0x46cea2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0046cea4: { // 0x46cea4: 8b5482fc MOV EDX,dword ptr [EDX + EAX*0x4 + -0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)-0x00000004u));
  }
  L0046cea8: { // 0x46cea8: 895487fc MOV dword ptr [EDI + EAX*0x4 + -0x4],EDX
    m.w32((s.di+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0046ceac: { // 0x46ceac: 7cf0 JL 0x0046ce9e
    if(integer::condition("JL",flags)) goto L0046ce9e;
  }
  L0046ceae: { // 0x46ceae: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L0046ceb1: { // 0x46ceb1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0046ceb3: { // 0x46ceb3: 7413 JZ 0x0046cec8
    if(integer::condition("JZ",flags)) goto L0046cec8;
  }
  L0046ceb5: { // 0x46ceb5: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0046ceb8: { // 0x46ceb8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046ceb9: { // 0x46ceb9: e8bd073000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4640446u,op); flags=s.arithmetic_flags;
  }
  L0046cebe: { // 0x46cebe: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046cec1: { // 0x46cec1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0046cec8: { // 0x46cec8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0046ceca: { // 0x46ceca: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L0046cecd: { // 0x46cecd: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0046cecf: { // 0x46cecf: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0046ced2: { // 0x46ced2: 896e08 MOV dword ptr [ESI + 0x8],EBP
    m.w32((s.si+0x00000008u), s.bp);
  }
  L0046ced5: { // 0x46ced5: 88460d MOV byte ptr [ESI + 0xd],AL
    m.w8((s.si+0x0000000du), (s.ax & 0xffu));
  }
  L0046ced8: { // 0x46ced8: eb07 JMP 0x0046cee1
    goto L0046cee1;
  }
  L0046ceda: { // 0x46ceda: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0046cedc: { // 0x46cedc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0046cede: { // 0x46cede: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),4640481u,op); flags=s.arithmetic_flags;
  }
  L0046cee1: { // 0x46cee1: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0046cee4: { // 0x46cee4: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0046cee7: { // 0x46cee7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0046cee9: { // 0x46cee9: 7d03 JGE 0x0046ceee
    if(integer::condition("JGE",flags)) goto L0046ceee;
  }
  L0046ceeb: { // 0x46ceeb: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0046ceee: { // 0x46ceee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046ceef: { // 0x46ceef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cef0: { // 0x46cef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0046cef1: { // 0x46cef1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0046cef3: { // 0x46cef3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046cef4: { // 0x46cef4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0046cef7: { // 0x46cef7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046cef8: { // 0x46cef8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cef9: { // 0x46cef9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0046cefa: { // 0x46cefa: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0046cefc: { // 0x46cefc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046cefd: { // 0x46cefd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00101930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00501930: { // 0x501930: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00501931: { // 0x501931: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00501933: { // 0x501933: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00501934: { // 0x501934: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00501938: { // 0x501938: 3bbe28020000 CMP EDI,dword ptr [ESI + 0x228]
    (void)integer::sub(s.di,m.r32((s.si+0x00000228u)),32,flags);
  }
  L0050193e: { // 0x50193e: 745e JZ 0x0050199e
    if(integer::condition("JZ",flags)) goto L0050199e;
  }
  L00501940: { // 0x501940: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00501943: { // 0x501943: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00501945: { // 0x501945: 7e57 JLE 0x0050199e
    if(integer::condition("JLE",flags)) goto L0050199e;
  }
  L00501947: { // 0x501947: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L0050194d: { // 0x50194d: c6867d05000000 MOV byte ptr [ESI + 0x57d],0x0
    m.w8((s.si+0x0000057du), 0x00000000u);
  }
  L00501954: { // 0x501954: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  L00501957: { // 0x501957: 740f JZ 0x00501968
    if(integer::condition("JZ",flags)) goto L00501968;
  }
  L00501959: { // 0x501959: 83f81c CMP EAX,0x1c
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  L0050195c: { // 0x50195c: 740a JZ 0x00501968
    if(integer::condition("JZ",flags)) goto L00501968;
  }
  L0050195e: { // 0x50195e: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L00501961: { // 0x501961: 7405 JZ 0x00501968
    if(integer::condition("JZ",flags)) goto L00501968;
  }
  L00501963: { // 0x501963: 83f81e CMP EAX,0x1e
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  L00501966: { // 0x501966: 750a JNZ 0x00501972
    if(integer::condition("JNZ",flags)) goto L00501972;
  }
  L00501968: { // 0x501968: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0050196a: { // 0x50196a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0050196c: { // 0x50196c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0050196e: { // 0x50196e: 6a1c PUSH 0x1c
    f.push(m,0x0000001cu);
  }
  L00501970: { // 0x501970: eb24 JMP 0x00501996
    goto L00501996;
  }
  L00501972: { // 0x501972: 8a86c3050000 MOV AL,byte ptr [ESI + 0x5c3]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005c3u)));
  }
  L00501978: { // 0x501978: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050197a: { // 0x50197a: 7412 JZ 0x0050198e
    if(integer::condition("JZ",flags)) goto L0050198e;
  }
  L0050197c: { // 0x50197c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0050197e: { // 0x50197e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501980: { // 0x501980: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501982: { // 0x501982: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00501984: { // 0x501984: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501986: { // 0x501986: ff92dc040000 CALL dword ptr [EDX + 0x4dc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000004dcu)),5249420u,op); flags=s.arithmetic_flags;
  }
  L0050198c: { // 0x50198c: eb10 JMP 0x0050199e
    goto L0050199e;
  }
  L0050198e: { // 0x50198e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00501990: { // 0x501990: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501992: { // 0x501992: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501994: { // 0x501994: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501996: { // 0x501996: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501998: { // 0x501998: ff90dc040000 CALL dword ptr [EAX + 0x4dc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000004dcu)),5249438u,op); flags=s.arithmetic_flags;
  }
  L0050199e: { // 0x50199e: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L005019a4: { // 0x5019a4: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  L005019a7: { // 0x5019a7: 740f JZ 0x005019b8
    if(integer::condition("JZ",flags)) goto L005019b8;
  }
  L005019a9: { // 0x5019a9: 83f81c CMP EAX,0x1c
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  L005019ac: { // 0x5019ac: 740a JZ 0x005019b8
    if(integer::condition("JZ",flags)) goto L005019b8;
  }
  L005019ae: { // 0x5019ae: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L005019b1: { // 0x5019b1: 7405 JZ 0x005019b8
    if(integer::condition("JZ",flags)) goto L005019b8;
  }
  L005019b3: { // 0x5019b3: 83f81e CMP EAX,0x1e
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  L005019b6: { // 0x5019b6: 7514 JNZ 0x005019cc
    if(integer::condition("JNZ",flags)) goto L005019cc;
  }
  L005019b8: { // 0x5019b8: 8b8ea8050000 MOV ECX,dword ptr [ESI + 0x5a8]
    s.cx = m.r32((s.si+0x000005a8u));
  }
  L005019be: { // 0x5019be: 8a81cc050000 MOV AL,byte ptr [ECX + 0x5cc]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000005ccu)));
  }
  L005019c4: { // 0x5019c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005019c6: { // 0x5019c6: 0f84ad000000 JZ 0x00501a79
    if(integer::condition("JZ",flags)) goto L00501a79;
  }
  L005019cc: { // 0x5019cc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005019cd: { // 0x5019cd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005019cf: { // 0x5019cf: c786d0040000ffffffff MOV dword ptr [ESI + 0x4d0],0xffffffff
    m.w32((s.si+0x000004d0u), 0xffffffffu);
  }
  L005019d9: { // 0x5019d9: e8e2d61b00 CALL 0x006bf0c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006bf0c0u,5249502u,op); flags=s.arithmetic_flags;
  }
  L005019de: { // 0x5019de: 8b8694040000 MOV EAX,dword ptr [ESI + 0x494]
    s.ax = m.r32((s.si+0x00000494u));
  }
  L005019e4: { // 0x5019e4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005019e6: { // 0x5019e6: 0f8586000000 JNZ 0x00501a72
    if(integer::condition("JNZ",flags)) goto L00501a72;
  }
  L005019ec: { // 0x5019ec: 8b96a8050000 MOV EDX,dword ptr [ESI + 0x5a8]
    s.dx = m.r32((s.si+0x000005a8u));
  }
  L005019f2: { // 0x5019f2: 8a820c0c0000 MOV AL,byte ptr [EDX + 0xc0c]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000c0cu)));
  }
  L005019f8: { // 0x5019f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005019fa: { // 0x5019fa: 7476 JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L005019fc: { // 0x5019fc: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005019fe: { // 0x5019fe: 7410 JZ 0x00501a10
    if(integer::condition("JZ",flags)) goto L00501a10;
  }
  L00501a00: { // 0x501a00: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00501a02: { // 0x501a02: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00501a04: { // 0x501a04: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5249543u,op); flags=s.arithmetic_flags;
  }
  L00501a07: { // 0x501a07: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L00501a0a: { // 0x501a0a: 7504 JNZ 0x00501a10
    if(integer::condition("JNZ",flags)) goto L00501a10;
  }
  L00501a0c: { // 0x501a0c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00501a0e: { // 0x501a0e: eb02 JMP 0x00501a12
    goto L00501a12;
  }
  L00501a10: { // 0x501a10: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00501a12: { // 0x501a12: 8b8ea8050000 MOV ECX,dword ptr [ESI + 0x5a8]
    s.cx = m.r32((s.si+0x000005a8u));
  }
  L00501a18: { // 0x501a18: 8a89120c0000 MOV CL,byte ptr [ECX + 0xc12]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000c12u)));
  }
  L00501a1e: { // 0x501a1e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00501a20: { // 0x501a20: 752f JNZ 0x00501a51
    if(integer::condition("JNZ",flags)) goto L00501a51;
  }
  L00501a22: { // 0x501a22: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00501a24: { // 0x501a24: 7427 JZ 0x00501a4d
    if(integer::condition("JZ",flags)) goto L00501a4d;
  }
  L00501a26: { // 0x501a26: 8b9018040000 MOV EDX,dword ptr [EAX + 0x418]
    s.dx = m.r32((s.ax+0x00000418u));
  }
  L00501a2c: { // 0x501a2c: 388a16120000 CMP byte ptr [EDX + 0x1216],CL
    (void)integer::sub(m.r8((s.dx+0x00001216u)),(s.cx & 0xffu),8,flags);
  }
  L00501a32: { // 0x501a32: 7419 JZ 0x00501a4d
    if(integer::condition("JZ",flags)) goto L00501a4d;
  }
  L00501a34: { // 0x501a34: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00501a36: { // 0x501a36: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00501a38: { // 0x501a38: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00501a39: { // 0x501a39: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501a3b: { // 0x501a3b: ff9010040000 CALL dword ptr [EAX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000410u)),5249601u,op); flags=s.arithmetic_flags;
  }
  L00501a41: { // 0x501a41: c6867e05000000 MOV byte ptr [ESI + 0x57e],0x0
    m.w8((s.si+0x0000057eu), 0x00000000u);
  }
  L00501a48: { // 0x501a48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00501a49: { // 0x501a49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00501a4a: { // 0x501a4a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00501a4d: { // 0x501a4d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00501a4f: { // 0x501a4f: 7421 JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L00501a51: { // 0x501a51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00501a53: { // 0x501a53: 741d JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L00501a55: { // 0x501a55: 8b8818040000 MOV ECX,dword ptr [EAX + 0x418]
    s.cx = m.r32((s.ax+0x00000418u));
  }
  L00501a5b: { // 0x501a5b: 8a8119120000 MOV AL,byte ptr [ECX + 0x1219]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001219u)));
  }
  L00501a61: { // 0x501a61: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00501a63: { // 0x501a63: 740d JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L00501a65: { // 0x501a65: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00501a67: { // 0x501a67: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00501a69: { // 0x501a69: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00501a6a: { // 0x501a6a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501a6c: { // 0x501a6c: ff9210040000 CALL dword ptr [EDX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000410u)),5249650u,op); flags=s.arithmetic_flags;
  }
  L00501a72: { // 0x501a72: c6867e05000000 MOV byte ptr [ESI + 0x57e],0x0
    m.w8((s.si+0x0000057eu), 0x00000000u);
  }
  L00501a79: { // 0x501a79: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00501a7a: { // 0x501a7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00501a7b: { // 0x501a7b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_002bf0c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006bf0c0: { // 0x6bf0c0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006bf0c3: { // 0x6bf0c3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf0c4: { // 0x6bf0c4: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L006bf0c8: { // 0x6bf0c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006bf0c9: { // 0x6bf0c9: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006bf0cb: { // 0x6bf0cb: 8b8728020000 MOV EAX,dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L006bf0d1: { // 0x6bf0d1: c6870404000000 MOV byte ptr [EDI + 0x404],0x0
    m.w8((s.di+0x00000404u), 0x00000000u);
  }
  L006bf0d8: { // 0x6bf0d8: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006bf0da: { // 0x6bf0da: 0f84e2000000 JZ 0x006bf1c2
    if(integer::condition("JZ",flags)) goto L006bf1c2;
  }
  L006bf0e0: { // 0x6bf0e0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006bf0e2: { // 0x6bf0e2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006bf0e3: { // 0x6bf0e3: 747b JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf0e5: { // 0x6bf0e5: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L006bf0e7: { // 0x6bf0e7: 7531 JNZ 0x006bf11a
    if(integer::condition("JNZ",flags)) goto L006bf11a;
  }
  L006bf0e9: { // 0x6bf0e9: 8d8788000000 LEA EAX,[EDI + 0x88]
    s.ax = (s.di+0x00000088u);
  }
  L006bf0ef: { // 0x6bf0ef: 8b8f88000000 MOV ECX,dword ptr [EDI + 0x88]
    s.cx = m.r32((s.di+0x00000088u));
  }
  L006bf0f5: { // 0x6bf0f5: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006bf0f9: { // 0x6bf0f9: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006bf0fd: { // 0x6bf0fd: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006bf100: { // 0x6bf100: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006bf101: { // 0x6bf101: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006bf106: { // 0x6bf106: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006bf10a: { // 0x6bf10a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006bf10d: { // 0x6bf10d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006bf111: { // 0x6bf111: e87a63e8ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,7074070u,op); flags=s.arithmetic_flags;
  }
  L006bf116: { // 0x6bf116: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006bf118: { // 0x6bf118: eb48 JMP 0x006bf162
    goto L006bf162;
  }
  L006bf11a: { // 0x6bf11a: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L006bf11d: { // 0x6bf11d: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L006bf11f: { // 0x6bf11f: 7441 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf121: { // 0x6bf121: 8a4e7d MOV CL,byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L006bf124: { // 0x6bf124: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006bf126: { // 0x6bf126: 7438 JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf128: { // 0x6bf128: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L006bf12b: { // 0x6bf12b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006bf12d: { // 0x6bf12d: 7431 JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf12f: { // 0x6bf12f: c0e802 SHR AL,0x2
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L006bf132: { // 0x6bf132: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L006bf134: { // 0x6bf134: 8844241c MOV byte ptr [ESP + 0x1c],AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L006bf138: { // 0x6bf138: 7428 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf13a: { // 0x6bf13a: 8a8625030000 MOV AL,byte ptr [ESI + 0x325]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000325u)));
  }
  L006bf140: { // 0x6bf140: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L006bf142: { // 0x6bf142: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf144: { // 0x6bf144: 7402 JZ 0x006bf148
    if(integer::condition("JZ",flags)) goto L006bf148;
  }
  L006bf146: { // 0x6bf146: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006bf148: { // 0x6bf148: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L006bf14b: { // 0x6bf14b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bf14d: { // 0x6bf14d: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7074128u,op); flags=s.arithmetic_flags;
  }
  L006bf150: { // 0x6bf150: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L006bf153: { // 0x6bf153: 750d JNZ 0x006bf162
    if(integer::condition("JNZ",flags)) goto L006bf162;
  }
  L006bf155: { // 0x6bf155: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bf157: { // 0x6bf157: e8549ae4ff CALL 0x00508bb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00508bb0u,7074140u,op); flags=s.arithmetic_flags;
  }
  L006bf15c: { // 0x6bf15c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf15e: { // 0x6bf15e: 7402 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf160: { // 0x6bf160: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006bf162: { // 0x6bf162: 8b8f38020000 MOV ECX,dword ptr [EDI + 0x238]
    s.cx = m.r32((s.di+0x00000238u));
  }
  L006bf168: { // 0x6bf168: 89b728020000 MOV dword ptr [EDI + 0x228],ESI
    m.w32((s.di+0x00000228u), s.si);
  }
  L006bf16e: { // 0x6bf16e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006bf170: { // 0x6bf170: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bf171: { // 0x6bf171: 740a JZ 0x006bf17d
    if(integer::condition("JZ",flags)) goto L006bf17d;
  }
  L006bf173: { // 0x6bf173: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006bf175: { // 0x6bf175: 7506 JNZ 0x006bf17d
    if(integer::condition("JNZ",flags)) goto L006bf17d;
  }
  L006bf177: { // 0x6bf177: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf178: { // 0x6bf178: e8130afcff CALL 0x0067fb90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0067fb90u,7074173u,op); flags=s.arithmetic_flags;
  }
  L006bf17d: { // 0x6bf17d: 8b8728020000 MOV EAX,dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L006bf183: { // 0x6bf183: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf185: { // 0x6bf185: 750a JNZ 0x006bf191
    if(integer::condition("JNZ",flags)) goto L006bf191;
  }
  L006bf187: { // 0x6bf187: c7871003000000000000 MOV dword ptr [EDI + 0x310],0x0
    m.w32((s.di+0x00000310u), 0x00000000u);
  }
  L006bf191: { // 0x6bf191: 8b875c020000 MOV EAX,dword ptr [EDI + 0x25c]
    s.ax = m.r32((s.di+0x0000025cu));
  }
  L006bf197: { // 0x6bf197: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf199: { // 0x6bf199: 7427 JZ 0x006bf1c2
    if(integer::condition("JZ",flags)) goto L006bf1c2;
  }
  L006bf19b: { // 0x6bf19b: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006bf19d: { // 0x6bf19d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf19e: { // 0x6bf19e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bf1a0: { // 0x6bf1a0: ff9054030000 CALL dword ptr [EAX + 0x354]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000354u)),7074214u,op); flags=s.arithmetic_flags;
  }
  L006bf1a6: { // 0x6bf1a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf1a8: { // 0x6bf1a8: 7518 JNZ 0x006bf1c2
    if(integer::condition("JNZ",flags)) goto L006bf1c2;
  }
  L006bf1aa: { // 0x6bf1aa: 8b8f5c020000 MOV ECX,dword ptr [EDI + 0x25c]
    s.cx = m.r32((s.di+0x0000025cu));
  }
  L006bf1b0: { // 0x6bf1b0: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006bf1b2: { // 0x6bf1b2: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),7074232u,op); flags=s.arithmetic_flags;
  }
  L006bf1b8: { // 0x6bf1b8: c7875c02000000000000 MOV dword ptr [EDI + 0x25c],0x0
    m.w32((s.di+0x0000025cu), 0x00000000u);
  }
  L006bf1c2: { // 0x6bf1c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf1c3: { // 0x6bf1c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf1c4: { // 0x6bf1c4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006bf1c7: { // 0x6bf1c7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 if(target==0x76d957u){if(!op.allocate)throw std::domain_error("genuine ordinary allocator callback required");const unsigned actual=op.allocate(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);s.ax=actual;finish(m,s,child,0);f.sp=child.sp;return;}
 if(target==0x76d67bu){if(!op.release)throw std::domain_error("genuine ordinary release callback required");const unsigned actual=op.release(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);s.ax=actual;finish(m,s,child,0);f.sp=child.sp;return;}
 switch(target){
case 0x6c9970u:f_002c9970(m,s,child,op);break;
case 0x4ce770u:f_000ce770(m,s,child,op);break;
case 0x4cdd40u:f_000cdd40(m,s,child,op);break;
case 0x46cc20u:f_0006cc20(m,s,child,op);break;
case 0x46ce50u:f_0006ce50(m,s,child,op);break;
case 0x501930u:f_00101930(m,s,child,op);break;
case 0x6bf0c0u:f_002bf0c0(m,s,child,op);break;
case 0x453890u:f_00053890(m,s,child,op);break;
default:throw std::domain_error("private_selection unresolved authentic target");}f.sp=child.sp;
}

} // anonymous namespace
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 need(entry>=0x8000&&size>=0x8000+68&&std::uint64_t(entry)+68<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000==entry,"actual owned32KB Source frame and caller extent");
 need(op.heap_context&&op.allocate&&op.release,"nonnull actual Source ordinary-provider callbacks/context");
 leaf::Memory local(storage,entry-0x8000,size);Memory m=world;m.add(local);
 std::array<unsigned,16>before{};for(unsigned k=0;k<16;++k)before[k]=m.r32(entry+4+4*k);
 // Borrowed normal addresspoints and bounded public records; no wholeclass lifecycle claim.
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw=false;for(auto v:controls)if(incoming.word(0)==v)cw=true;need(cw&&incoming.word(8)==0xffff&&(incoming.word(4)&~0x3800u)==0&&!(in.flags&0x400),"finite12CW/all8TOP emptytags/DFclear");
 struct PublicSpan{unsigned p,n;};std::array<PublicSpan,11>spans{};unsigned used=0;
 const auto span=[&](unsigned p,unsigned n){need(p&&n&&std::uint64_t(p)+n<=0x100000000ull&&(std::uint64_t(p)+n<=entry-0x8000||std::uint64_t(p)>=std::uint64_t(entry)+68),"bounded public span outside private frame");for(unsigned k=0;k<used;++k)need(std::uint64_t(p)+n<=spans[k].p||std::uint64_t(spans[k].p)+spans[k].n<=p,"disjoint borrowed public records/backings");need(used<spans.size(),"finite public record count");spans[used++]={p,n};for(unsigned k=0;k<n;++k)(void)m.r8(p+k);};
 const unsigned self=in.cx;span(self,0x5c4);need(m.r32(self)==0x78e540,"borrowed normal primaryaddresspoint");
 const auto vector=[&](unsigned h,unsigned table,unsigned count){need(m.r32(h)==table&&m.r32(h+8)==10&&m.r8(h+12)==1&&m.r8(h+13)==0&&m.r32(h+16)==count&&m.r32(h+20)==10,"normal borrowed vector capacity/status/ownership/count/growth");unsigned data=m.r32(h+4);span(data,40);return data;};
 const unsigned scores=vector(self+0x390,0x788a94,3),available=vector(self+0x3a8,0x78c77c,3),selected=vector(self+0x3c0,0x78c77c,2);
 const unsigned A=m.r32(available),B=m.r32(available+4),C=m.r32(available+8),D=m.r32(selected+4);need(m.r32(selected)==A&&A!=B&&A!=C&&A!=D&&B!=C&&B!=D&&C!=D,"available3[A,B,C]/selected2[A,D] distinct valid targets");
 span(A,4);span(B,0x41c);span(C,0x41c);span(D,4);
 const unsigned sb=m.r32(scores+4),sc=m.r32(scores+8);need(std::int32_t(sb)>0&&std::int32_t(sc)>0&&sb!=sc,"strictlypositive unequal signed candidate scores");const unsigned winner=std::int32_t(sb)>std::int32_t(sc)?B:C;
 const unsigned typeB=m.r32(B+0x418),typeC=m.r32(C+0x418);span(typeB,0x1217);span(typeC,0x1217);need(m.r32(B)==0x787bbc&&m.r32(C)==0x787bbc&&m.r8(typeB+0x1216)==0&&m.r8(typeC+0x1216)==0,"normal Building addresspoints and finite type bits");
 const unsigned control=m.r32(self+0x5a8);span(control,0xc13);need(m.r32(self+0x228)==winner&&m.r32(self+0x5ac)==0x20&&m.r32(self+0x494)==0&&m.r8(self+0x5c3)==0&&m.r8(control+0xc0c)==1&&m.r8(control+0xc12)==0,"same-currenttarget ordinary refresh/noalternatecallbacks");
 need(m.r32(0x78c784)==0x4cdd40&&m.r32(0x788a9c)==0x46ce50&&m.r32(0x78e8b0)==0x501930&&m.r32(0x787be8)==0x453890,"four authentic vptr slot bindings");
 State state{};state.ax=in.ax;state.cx=in.cx;state.dx=in.dx;state.bx=in.bx;state.bp=in.bp;state.si=in.si;state.di=in.di;state.arithmetic_flags=in.flags;state.fp.image=incoming;
 Frame frame{entry,entry,m.r32(entry)};f_002c9970(m,state,frame,op);
 need(frame.sp==entry+4&&state.bx==in.bx&&state.bp==in.bp&&state.si==in.si&&state.di==in.di&&!(state.arithmetic_flags&0x400),"actual RET0/nonvolDF");
 need(fp::same_numeric(state.fp.image,incoming),"actual numeric86/all80 FPidentity withoutnormalization");
 Result result{state.ax,state,{}};for(unsigned k=0;k<16;++k){result.words[k]=m.r32(entry+4+4*k);need(result.words[k]==before[k],"actual all16 unchanged caller poststate");}return result;
}
}
