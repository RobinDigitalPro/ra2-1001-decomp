#include "recovered/recovery_b759_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b759 {
namespace {
void f_00041de0(Memory&,State&,Frame&,const Operations&);
void f_002b9af0(Memory&,State&,Frame&,const Operations&);
void f_0022e100(Memory&,State&,Frame&,const Operations&);
void f_001cbd90(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00041de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00441de0: { // 0x441de0: 83ec30 SUB ESP, 0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L00441de3: { // 0x441de3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00441de4: { // 0x441de4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00441de5: { // 0x441de5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00441de6: { // 0x441de6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00441de8: { // 0x441de8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00441de9: { // 0x441de9: c644241300 MOV byte ptr [ESP + 0x13], 0
    m.w8((f.sp+0x00000013u), 0u);
  }
  L00441dee: { // 0x441dee: 8d8688000000 LEA EAX, [ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L00441df4: { // 0x441df4: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00441df6: { // 0x441df6: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00441df8: { // 0x441df8: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L00441dfb: { // 0x441dfb: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L00441dfe: { // 0x441dfe: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00441e02: { // 0x441e02: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00441e03: { // 0x441e03: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00441e09: { // 0x441e09: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00441e0b: { // 0x441e0b: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00441e0e: { // 0x441e0e: 6689442420 MOV word ptr [ESP + 0x20], AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L00441e13: { // 0x441e13: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00441e15: { // 0x441e15: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00441e16: { // 0x441e16: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00441e1c: { // 0x441e1c: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00441e1e: { // 0x441e1e: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L00441e20: { // 0x441e20: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L00441e23: { // 0x441e23: c1fb08 SAR EBX, 8
    s.bx = integer::shift(s.bx,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00441e26: { // 0x441e26: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441e28: { // 0x441e28: 66895c2422 MOV word ptr [ESP + 0x22], BX
    m.w16((f.sp+0x00000022u), (s.bx & 0xffffu));
  }
  L00441e2d: { // 0x441e2d: 0f8572040000 JNZ 0x4422a5
    if(integer::condition("JNZ",flags)) goto L004422a5;
  }
  L00441e33: { // 0x441e33: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00441e39: { // 0x441e39: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00441e3b: { // 0x441e3b: 0f8464040000 JZ 0x4422a5
    if(integer::condition("JZ",flags)) goto L004422a5;
  }
  L00441e41: { // 0x441e41: 8dbe9c040000 LEA EDI, [ESI + 0x49c]
    s.di = (s.si+0x0000049cu);
  }
  L00441e47: { // 0x441e47: bd08000000 MOV EBP, 8
    s.bp = 8u;
  }
  L00441e4c: { // 0x441e4c: 8b0f MOV ECX, dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00441e4e: { // 0x441e4e: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00441e50: { // 0x441e50: 740e JZ 0x441e60
    if(integer::condition("JZ",flags)) goto L00441e60;
  }
  L00441e52: { // 0x441e52: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00441e54: { // 0x441e54: ff90f0000000 CALL dword ptr [EAX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000f0u)),4464218u); flags=s.arithmetic_flags;
  }
  L00441e5a: { // 0x441e5a: c70700000000 MOV dword ptr [EDI], 0
    m.w32((s.di), 0u);
  }
  L00441e60: { // 0x441e60: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L00441e63: { // 0x441e63: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L00441e64: { // 0x441e64: 75e6 JNZ 0x441e4c
    if(integer::condition("JNZ",flags)) goto L00441e4c;
  }
  L00441e66: { // 0x441e66: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00441e6c: { // 0x441e6c: 8a8166130000 MOV AL, byte ptr [ECX + 0x1366]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001366u)));
  }
  L00441e72: { // 0x441e72: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441e74: { // 0x441e74: 7437 JZ 0x441ead
    if(integer::condition("JZ",flags)) goto L00441ead;
  }
  L00441e76: { // 0x441e76: 8a86b4050000 MOV AL, byte ptr [ESI + 0x5b4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005b4u)));
  }
  L00441e7c: { // 0x441e7c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441e7e: { // 0x441e7e: 742d JZ 0x441ead
    if(integer::condition("JZ",flags)) goto L00441ead;
  }
  L00441e80: { // 0x441e80: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00441e86: { // 0x441e86: 8b90cc520000 MOV EDX, dword ptr [EAX + 0x52cc]
    s.dx = m.r32((s.ax+0x000052ccu));
  }
  L00441e8c: { // 0x441e8c: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00441e8d: { // 0x441e8d: 8990cc520000 MOV dword ptr [EAX + 0x52cc], EDX
    m.w32((s.ax+0x000052ccu), s.dx);
  }
  L00441e93: { // 0x441e93: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00441e99: { // 0x441e99: 8b88cc520000 MOV ECX, dword ptr [EAX + 0x52cc]
    s.cx = m.r32((s.ax+0x000052ccu));
  }
  L00441e9f: { // 0x441e9f: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00441ea1: { // 0x441ea1: 7d0a JGE 0x441ead
    if(integer::condition("JGE",flags)) goto L00441ead;
  }
  L00441ea3: { // 0x441ea3: c780cc52000000000000 MOV dword ptr [EAX + 0x52cc], 0
    m.w32((s.ax+0x000052ccu), 0u);
  }
  L00441ead: { // 0x441ead: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00441eb3: { // 0x441eb3: 8a8165130000 MOV AL, byte ptr [ECX + 0x1365]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001365u)));
  }
  L00441eb9: { // 0x441eb9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441ebb: { // 0x441ebb: 743e JZ 0x441efb
    if(integer::condition("JZ",flags)) goto L00441efb;
  }
  L00441ebd: { // 0x441ebd: 8a86b4050000 MOV AL, byte ptr [ESI + 0x5b4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005b4u)));
  }
  L00441ec3: { // 0x441ec3: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441ec5: { // 0x441ec5: 7434 JZ 0x441efb
    if(integer::condition("JZ",flags)) goto L00441efb;
  }
  L00441ec7: { // 0x441ec7: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00441ecd: { // 0x441ecd: 8b9100140000 MOV EDX, dword ptr [ECX + 0x1400]
    s.dx = m.r32((s.cx+0x00001400u));
  }
  L00441ed3: { // 0x441ed3: 8bb818020000 MOV EDI, dword ptr [EAX + 0x218]
    s.di = m.r32((s.ax+0x00000218u));
  }
  L00441ed9: { // 0x441ed9: 2bfa SUB EDI, EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L00441edb: { // 0x441edb: 89b818020000 MOV dword ptr [EAX + 0x218], EDI
    m.w32((s.ax+0x00000218u), s.di);
  }
  L00441ee1: { // 0x441ee1: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00441ee7: { // 0x441ee7: 8b8818020000 MOV ECX, dword ptr [EAX + 0x218]
    s.cx = m.r32((s.ax+0x00000218u));
  }
  L00441eed: { // 0x441eed: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00441eef: { // 0x441eef: 7d0a JGE 0x441efb
    if(integer::condition("JGE",flags)) goto L00441efb;
  }
  L00441ef1: { // 0x441ef1: c7801802000000000000 MOV dword ptr [EAX + 0x218], 0
    m.w32((s.ax+0x00000218u), 0u);
  }
  L00441efb: { // 0x441efb: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00441f01: { // 0x441f01: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L00441f07: { // 0x441f07: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00441f09: { // 0x441f09: 7409 JZ 0x441f14
    if(integer::condition("JZ",flags)) goto L00441f14;
  }
  L00441f0b: { // 0x441f0b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00441f0d: { // 0x441f0d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00441f0f: { // 0x441f0f: e81cba0000 CALL 0x44d930
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044d930u,4464404u); flags=s.arithmetic_flags;
  }
  L00441f14: { // 0x441f14: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L00441f19: { // 0x441f19: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00441f1b: { // 0x441f1b: 7552 JNZ 0x441f6f
    if(integer::condition("JNZ",flags)) goto L00441f6f;
  }
  L00441f1d: { // 0x441f1d: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00441f23: { // 0x441f23: 8a8162130000 MOV AL, byte ptr [ECX + 0x1362]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001362u)));
  }
  L00441f29: { // 0x441f29: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441f2b: { // 0x441f2b: 7410 JZ 0x441f3d
    if(integer::condition("JZ",flags)) goto L00441f3d;
  }
  L00441f2d: { // 0x441f2d: a15c708300 MOV EAX, dword ptr [0x83705c]
    s.ax = m.r32((0x0083705cu));
  }
  L00441f32: { // 0x441f32: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00441f34: { // 0x441f34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00441f35: { // 0x441f35: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00441f37: { // 0x441f37: ff9284040000 CALL dword ptr [EDX + 0x484]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000484u)),4464445u); flags=s.arithmetic_flags;
  }
  L00441f3d: { // 0x441f3d: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00441f43: { // 0x441f43: 8a81f90a0000 MOV AL, byte ptr [ECX + 0xaf9]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000af9u)));
  }
  L00441f49: { // 0x441f49: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441f4b: { // 0x441f4b: 7410 JZ 0x441f5d
    if(integer::condition("JZ",flags)) goto L00441f5d;
  }
  L00441f4d: { // 0x441f4d: a15c708300 MOV EAX, dword ptr [0x83705c]
    s.ax = m.r32((0x0083705cu));
  }
  L00441f52: { // 0x441f52: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00441f54: { // 0x441f54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00441f55: { // 0x441f55: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00441f57: { // 0x441f57: ff928c040000 CALL dword ptr [EDX + 0x48c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000048cu)),4464477u); flags=s.arithmetic_flags;
  }
  L00441f5d: { // 0x441f5d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00441f5f: { // 0x441f5f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00441f61: { // 0x441f61: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4464484u); flags=s.arithmetic_flags;
  }
  L00441f64: { // 0x441f64: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441f66: { // 0x441f66: 7507 JNZ 0x441f6f
    if(integer::condition("JNZ",flags)) goto L00441f6f;
  }
  L00441f68: { // 0x441f68: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00441f6a: { // 0x441f6a: e821f10000 CALL 0x451090
    s.arithmetic_flags=flags; invoke(m,s,f,0x00451090u,4464495u); flags=s.arithmetic_flags;
  }
  L00441f6f: { // 0x441f6f: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00441f71: { // 0x441f71: 8d8ec0040000 LEA ECX, [ESI + 0x4c0]
    s.cx = (s.si+0x000004c0u);
  }
  L00441f77: { // 0x441f77: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00441f79: { // 0x441f79: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00441f7b: { // 0x441f7b: 7409 JZ 0x441f86
    if(integer::condition("JZ",flags)) goto L00441f86;
  }
  L00441f7d: { // 0x441f7d: 80b8e313000000 CMP byte ptr [EAX + 0x13e3], 0
    (void)integer::sub(m.r8((s.ax+0x000013e3u)),0u,8,flags);
  }
  L00441f84: { // 0x441f84: 750b JNZ 0x441f91
    if(integer::condition("JNZ",flags)) goto L00441f91;
  }
  L00441f86: { // 0x441f86: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00441f87: { // 0x441f87: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L00441f8a: { // 0x441f8a: 83fa03 CMP EDX, 3
    (void)integer::sub(s.dx,3u,32,flags);
  }
  L00441f8d: { // 0x441f8d: 7ce8 JL 0x441f77
    if(integer::condition("JL",flags)) goto L00441f77;
  }
  L00441f8f: { // 0x441f8f: eb05 JMP 0x441f96
    goto L00441f96;
  }
  L00441f91: { // 0x441f91: c644241301 MOV byte ptr [ESP + 0x13], 1
    m.w8((f.sp+0x00000013u), 1u);
  }
  L00441f96: { // 0x441f96: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L00441f9b: { // 0x441f9b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00441f9d: { // 0x441f9d: 7507 JNZ 0x441fa6
    if(integer::condition("JNZ",flags)) goto L00441fa6;
  }
  L00441f9f: { // 0x441f9f: b301 MOV BL, 1
    s.bx = with_al(s.bx, 1u);
  }
  L00441fa1: { // 0x441fa1: e940030000 JMP 0x4422e6
    goto L004422e6;
  }
  L00441fa6: { // 0x441fa6: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00441fab: { // 0x441fab: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00441fb1: { // 0x441fb1: 3b888c070000 CMP ECX, dword ptr [EAX + 0x78c]
    (void)integer::sub(s.cx,m.r32((s.ax+0x0000078cu)),32,flags);
  }
  L00441fb7: { // 0x441fb7: 0f858f000000 JNZ 0x44204c
    if(integer::condition("JNZ",flags)) goto L0044204c;
  }
  L00441fbd: { // 0x441fbd: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00441fbf: { // 0x441fbf: 8bd5 MOV EDX, EBP
    s.dx = s.bp;
  }
  L00441fc1: { // 0x441fc1: 83e207 AND EDX, 7
    s.dx = integer::logical((s.dx)&(7u),32,flags);
  }
  L00441fc4: { // 0x441fc4: 668b0c95a09d8300 MOV CX, word ptr [EDX*4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 4u)+0x00839da0u)));
  }
  L00441fcc: { // 0x441fcc: 8d0495a09d8300 LEA EAX, [EDX*4 + 0x839da0]
    s.ax = ((s.dx * 4u)+0x00839da0u);
  }
  L00441fd3: { // 0x441fd3: 66034c2420 ADD CX, word ptr [ESP + 0x20]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000020u)),16,flags));
  }
  L00441fd8: { // 0x441fd8: 668b5002 MOV DX, word ptr [EAX + 2]
    s.dx = with_ax(s.dx, m.r16((s.ax+2u)));
  }
  L00441fdc: { // 0x441fdc: 66894c2414 MOV word ptr [ESP + 0x14], CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L00441fe1: { // 0x441fe1: 6603d3 ADD DX, BX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00441fe4: { // 0x441fe4: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00441fe8: { // 0x441fe8: 6689542416 MOV word ptr [ESP + 0x16], DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L00441fed: { // 0x441fed: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00441ff1: { // 0x441ff1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00441ff2: { // 0x441ff2: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00441ff7: { // 0x441ff7: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00441ffb: { // 0x441ffb: e800351000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4464640u); flags=s.arithmetic_flags;
  }
  L00442000: { // 0x442000: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00442002: { // 0x442002: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00442004: { // 0x442004: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00442006: { // 0x442006: e855350300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4464651u); flags=s.arithmetic_flags;
  }
  L0044200b: { // 0x44200b: 8b4744 MOV EAX, dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L0044200e: { // 0x44200e: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00442011: { // 0x442011: 7428 JZ 0x44203b
    if(integer::condition("JZ",flags)) goto L0044203b;
  }
  L00442013: { // 0x442013: 8b151ce1a100 MOV EDX, dword ptr [0xa1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00442019: { // 0x442019: 8b0482 MOV EAX, dword ptr [EDX + EAX*4]
    s.ax = m.r32((s.dx+(s.ax * 4u)));
  }
  L0044201c: { // 0x44201c: 8a8878020000 MOV CL, byte ptr [EAX + 0x278]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000278u)));
  }
  L00442022: { // 0x442022: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00442024: { // 0x442024: 7415 JZ 0x44203b
    if(integer::condition("JZ",flags)) goto L0044203b;
  }
  L00442026: { // 0x442026: 80bf1e01000010 CMP byte ptr [EDI + 0x11e], 0x10
    (void)integer::sub(m.r8((s.di+0x0000011eu)),0x00000010u,8,flags);
  }
  L0044202d: { // 0x44202d: 730c JNC 0x44203b
    if(integer::condition("JNC",flags)) goto L0044203b;
  }
  L0044202f: { // 0x44202f: 68c8000000 PUSH 0xc8
    f.push(m,0x000000c8u);
  }
  L00442034: { // 0x442034: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00442036: { // 0x442036: e8a53b0300 CALL 0x475be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475be0u,4464699u); flags=s.arithmetic_flags;
  }
  L0044203b: { // 0x44203b: 83c502 ADD EBP, 2
    s.bp = integer::add(s.bp,2u,32,flags);
  }
  L0044203e: { // 0x44203e: 83fd08 CMP EBP, 8
    (void)integer::sub(s.bp,8u,32,flags);
  }
  L00442041: { // 0x442041: 0f8c78ffffff JL 0x441fbf
    if(integer::condition("JL",flags)) goto L00441fbf;
  }
  L00442047: { // 0x442047: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0044204c: { // 0x44204c: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00442052: { // 0x442052: 8b907c070000 MOV EDX, dword ptr [EAX + 0x77c]
    s.dx = m.r32((s.ax+0x0000077cu));
  }
  L00442058: { // 0x442058: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0044205a: { // 0x44205a: 7408 JZ 0x442064
    if(integer::condition("JZ",flags)) goto L00442064;
  }
  L0044205c: { // 0x44205c: 3b8884070000 CMP ECX, dword ptr [EAX + 0x784]
    (void)integer::sub(s.cx,m.r32((s.ax+0x00000784u)),32,flags);
  }
  L00442062: { // 0x442062: 7563 JNZ 0x4420c7
    if(integer::condition("JNZ",flags)) goto L004420c7;
  }
  L00442064: { // 0x442064: 8b7c2420 MOV EDI, dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00442068: { // 0x442068: 66895c2416 MOV word ptr [ESP + 0x16], BX
    m.w16((f.sp+0x00000016u), (s.bx & 0xffffu));
  }
  L0044206d: { // 0x44206d: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00442071: { // 0x442071: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00442073: { // 0x442073: 8d4fff LEA ECX, [EDI - 1]
    s.cx = (s.di-1u);
  }
  L00442076: { // 0x442076: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00442077: { // 0x442077: 66894c241c MOV word ptr [ESP + 0x1c], CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L0044207c: { // 0x44207c: 8b54241c MOV EDX, dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00442080: { // 0x442080: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00442085: { // 0x442085: 89542420 MOV dword ptr [ESP + 0x20], EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00442089: { // 0x442089: e872341000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4464782u); flags=s.arithmetic_flags;
  }
  L0044208e: { // 0x44208e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00442090: { // 0x442090: e8cb340300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4464789u); flags=s.arithmetic_flags;
  }
  L00442095: { // 0x442095: 83c703 ADD EDI, 3
    s.di = integer::add(s.di,3u,32,flags);
  }
  L00442098: { // 0x442098: 66895c2416 MOV word ptr [ESP + 0x16], BX
    m.w16((f.sp+0x00000016u), (s.bx & 0xffffu));
  }
  L0044209d: { // 0x44209d: 66897c2414 MOV word ptr [ESP + 0x14], DI
    m.w16((f.sp+0x00000014u), (s.di & 0xffffu));
  }
  L004420a2: { // 0x4420a2: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004420a6: { // 0x4420a6: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004420aa: { // 0x4420aa: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004420ae: { // 0x4420ae: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004420b0: { // 0x4420b0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004420b1: { // 0x4420b1: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004420b6: { // 0x4420b6: e845341000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4464827u); flags=s.arithmetic_flags;
  }
  L004420bb: { // 0x4420bb: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004420bd: { // 0x4420bd: e89e340300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4464834u); flags=s.arithmetic_flags;
  }
  L004420c2: { // 0x4420c2: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004420c7: { // 0x4420c7: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L004420cd: { // 0x4420cd: 8b9080070000 MOV EDX, dword ptr [EAX + 0x780]
    s.dx = m.r32((s.ax+0x00000780u));
  }
  L004420d3: { // 0x4420d3: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004420d5: { // 0x4420d5: 7408 JZ 0x4420df
    if(integer::condition("JZ",flags)) goto L004420df;
  }
  L004420d7: { // 0x4420d7: 3b8888070000 CMP ECX, dword ptr [EAX + 0x788]
    (void)integer::sub(s.cx,m.r32((s.ax+0x00000788u)),32,flags);
  }
  L004420dd: { // 0x4420dd: 7563 JNZ 0x442142
    if(integer::condition("JNZ",flags)) goto L00442142;
  }
  L004420df: { // 0x4420df: 8b7c2422 MOV EDI, dword ptr [ESP + 0x22]
    s.di = m.r32((f.sp+0x00000022u));
  }
  L004420e3: { // 0x4420e3: 668b5c2420 MOV BX, word ptr [ESP + 0x20]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x00000020u)));
  }
  L004420e8: { // 0x4420e8: 66895c2414 MOV word ptr [ESP + 0x14], BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L004420ed: { // 0x4420ed: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004420f1: { // 0x4420f1: 8d47ff LEA EAX, [EDI - 1]
    s.ax = (s.di-1u);
  }
  L004420f4: { // 0x4420f4: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004420f6: { // 0x4420f6: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L004420fb: { // 0x4420fb: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004420ff: { // 0x4420ff: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00442103: { // 0x442103: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00442104: { // 0x442104: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00442109: { // 0x442109: e8f2331000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4464910u); flags=s.arithmetic_flags;
  }
  L0044210e: { // 0x44210e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00442110: { // 0x442110: e84b340300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4464917u); flags=s.arithmetic_flags;
  }
  L00442115: { // 0x442115: 83c703 ADD EDI, 3
    s.di = integer::add(s.di,3u,32,flags);
  }
  L00442118: { // 0x442118: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0044211c: { // 0x44211c: 66895c2414 MOV word ptr [ESP + 0x14], BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L00442121: { // 0x442121: 66897c2416 MOV word ptr [ESP + 0x16], DI
    m.w16((f.sp+0x00000016u), (s.di & 0xffffu));
  }
  L00442126: { // 0x442126: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0044212a: { // 0x44212a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044212c: { // 0x44212c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044212d: { // 0x44212d: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00442132: { // 0x442132: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00442136: { // 0x442136: e8c5331000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4464955u); flags=s.arithmetic_flags;
  }
  L0044213b: { // 0x44213b: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044213d: { // 0x44213d: e81e340300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4464962u); flags=s.arithmetic_flags;
  }
  L00442142: { // 0x442142: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00442148: { // 0x442148: 8b81f00b0000 MOV EAX, dword ptr [ECX + 0xbf0]
    s.ax = m.r32((s.cx+0x00000bf0u));
  }
  L0044214e: { // 0x44214e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00442150: { // 0x442150: 0f85ab000000 JNZ 0x442201
    if(integer::condition("JNZ",flags)) goto L00442201;
  }
  L00442156: { // 0x442156: e855640100 CALL 0x4585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4464987u); flags=s.arithmetic_flags;
  }
  L0044215b: { // 0x44215b: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00442161: { // 0x442161: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00442163: { // 0x442163: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L00442165: { // 0x442165: e856640100 CALL 0x4585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4465002u); flags=s.arithmetic_flags;
  }
  L0044216a: { // 0x44216a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044216c: { // 0x44216c: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0044216e: { // 0x44216e: 8d442420 LEA EAX, [ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00442172: { // 0x442172: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00442174: { // 0x442174: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00442175: { // 0x442175: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4465019u); flags=s.arithmetic_flags;
  }
  L0044217b: { // 0x44217b: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0044217d: { // 0x44217d: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0044217f: { // 0x44217f: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00442183: { // 0x442183: 8d4f02 LEA ECX, [EDI + 2]
    s.cx = (s.di+2u);
  }
  L00442186: { // 0x442186: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00442188: { // 0x442188: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0044218c: { // 0x44218c: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00442190: { // 0x442190: 7e6f JLE 0x442201
    if(integer::condition("JLE",flags)) goto L00442201;
  }
  L00442192: { // 0x442192: 83c502 ADD EBP, 2
    s.bp = integer::add(s.bp,2u,32,flags);
  }
  L00442195: { // 0x442195: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00442197: { // 0x442197: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00442199: { // 0x442199: 7e5d JLE 0x4421f8
    if(integer::condition("JLE",flags)) goto L004421f8;
  }
  L0044219b: { // 0x44219b: 8b542430 MOV EDX, dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0044219f: { // 0x44219f: 8b4c2432 MOV ECX, dword ptr [ESP + 0x32]
    s.cx = m.r32((f.sp+0x00000032u));
  }
  L004421a3: { // 0x4421a3: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004421a4: { // 0x4421a4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004421a5: { // 0x4421a5: 6689542428 MOV word ptr [ESP + 0x28], DX
    m.w16((f.sp+0x00000028u), (s.dx & 0xffffu));
  }
  L004421aa: { // 0x4421aa: 66894c242a MOV word ptr [ESP + 0x2a], CX
    m.w16((f.sp+0x0000002au), (s.cx & 0xffffu));
  }
  L004421af: { // 0x4421af: 8b54242a MOV EDX, dword ptr [ESP + 0x2a]
    s.dx = m.r32((f.sp+0x0000002au));
  }
  L004421b3: { // 0x4421b3: 8b5c2428 MOV EBX, dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L004421b7: { // 0x4421b7: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004421b9: { // 0x4421b9: 6689542416 MOV word ptr [ESP + 0x16], DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L004421be: { // 0x4421be: 8d043b LEA EAX, [EBX + EDI]
    s.ax = (s.bx+s.di);
  }
  L004421c1: { // 0x4421c1: 8d54241c LEA EDX, [ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L004421c5: { // 0x4421c5: 6689442414 MOV word ptr [ESP + 0x14], AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L004421ca: { // 0x4421ca: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004421ce: { // 0x4421ce: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L004421d2: { // 0x4421d2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004421d3: { // 0x4421d3: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004421d8: { // 0x4421d8: e823331000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4465117u); flags=s.arithmetic_flags;
  }
  L004421dd: { // 0x4421dd: 8a9022010000 MOV DL, byte ptr [EAX + 0x122]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000122u)));
  }
  L004421e3: { // 0x4421e3: feca DEC DL
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L004421e5: { // 0x4421e5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004421e6: { // 0x4421e6: 3bfd CMP EDI, EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L004421e8: { // 0x4421e8: 889022010000 MOV byte ptr [EAX + 0x122], DL
    m.w8((s.ax+0x00000122u), (s.dx & 0xffu));
  }
  L004421ee: { // 0x4421ee: 7cce JL 0x4421be
    if(integer::condition("JL",flags)) goto L004421be;
  }
  L004421f0: { // 0x4421f0: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004421f4: { // 0x4421f4: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004421f8: { // 0x4421f8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004421f9: { // 0x4421f9: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004421fb: { // 0x4421fb: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004421ff: { // 0x4421ff: 7c94 JL 0x442195
    if(integer::condition("JL",flags)) goto L00442195;
  }
  L00442201: { // 0x442201: a1ac1c8200 MOV EAX, dword ptr [0x821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L00442206: { // 0x442206: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00442208: { // 0x442208: 7437 JZ 0x442241
    if(integer::condition("JZ",flags)) goto L00442241;
  }
  L0044220a: { // 0x44220a: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044220c: { // 0x44220c: 8d4c2430 LEA ECX, [ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00442210: { // 0x442210: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00442212: { // 0x442212: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00442213: { // 0x442213: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00442215: { // 0x442215: ff9024010000 CALL dword ptr [EAX + 0x124]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000124u)),4465179u); flags=s.arithmetic_flags;
  }
  L0044221b: { // 0x44221b: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0044221d: { // 0x44221d: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00442220: { // 0x442220: 8bd4 MOV EDX, ESP
    s.dx = f.sp;
  }
  L00442222: { // 0x442222: 890a MOV dword ptr [EDX], ECX
    m.w32((s.dx), s.cx);
  }
  L00442224: { // 0x442224: 8b4804 MOV ECX, dword ptr [EAX + 4]
    s.cx = m.r32((s.ax+4u));
  }
  L00442227: { // 0x442227: 894a04 MOV dword ptr [EDX + 4], ECX
    m.w32((s.dx+4u), s.cx);
  }
  L0044222a: { // 0x44222a: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L0044222d: { // 0x44222d: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00442230: { // 0x442230: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L00442233: { // 0x442233: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00442239: { // 0x442239: 89420c MOV dword ptr [EDX + 0xc], EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0044223c: { // 0x44223c: e81f642500 CALL 0x698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,4465217u); flags=s.arithmetic_flags;
  }
  L00442241: { // 0x442241: 8b8ed4040000 MOV ECX, dword ptr [ESI + 0x4d4]
    s.cx = m.r32((s.si+0x000004d4u));
  }
  L00442247: { // 0x442247: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00442249: { // 0x442249: 7408 JZ 0x442253
    if(integer::condition("JZ",flags)) goto L00442253;
  }
  L0044224b: { // 0x44224b: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0044224d: { // 0x44224d: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),4465235u); flags=s.arithmetic_flags;
  }
  L00442253: { // 0x442253: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L00442259: { // 0x442259: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044225a: { // 0x44225a: e8617e0a00 CALL 0x4ea0c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ea0c0u,4465247u); flags=s.arithmetic_flags;
  }
  L0044225f: { // 0x44225f: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00442265: { // 0x442265: c6804401000001 MOV byte ptr [EAX + 0x144], 1
    m.w8((s.ax+0x00000144u), 1u);
  }
  L0044226c: { // 0x44226c: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L00442272: { // 0x442272: e809590a00 CALL 0x4e7b80
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e7b80u,4465271u); flags=s.arithmetic_flags;
  }
  L00442277: { // 0x442277: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044227d: { // 0x44227d: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00442282: { // 0x442282: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00442284: { // 0x442284: 7513 JNZ 0x442299
    if(integer::condition("JNZ",flags)) goto L00442299;
  }
  L00442286: { // 0x442286: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00442288: { // 0x442288: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044228d: { // 0x44228d: c60528bd810001 MOV byte ptr [0x81bd28], 1
    m.w8((0x0081bd28u), 1u);
  }
  L00442294: { // 0x442294: e897dd0900 CALL 0x4e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,4465305u); flags=s.arithmetic_flags;
  }
  L00442299: { // 0x442299: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044229f: { // 0x44229f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004422a0: { // 0x4422a0: e89b110b00 CALL 0x4f3440
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f3440u,4465317u); flags=s.arithmetic_flags;
  }
  L004422a5: { // 0x4422a5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004422a7: { // 0x4422a7: e844782700 CALL 0x6b9af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b9af0u,4465324u); flags=s.arithmetic_flags;
  }
  L004422ac: { // 0x4422ac: 8ad8 MOV BL, AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L004422ae: { // 0x4422ae: 8a442413 MOV AL, byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L004422b2: { // 0x4422b2: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004422b4: { // 0x4422b4: 740b JZ 0x4422c1
    if(integer::condition("JZ",flags)) goto L004422c1;
  }
  L004422b6: { // 0x4422b6: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004422bc: { // 0x4422bc: e89f030b00 CALL 0x4f2660
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2660u,4465345u); flags=s.arithmetic_flags;
  }
  L004422c1: { // 0x4422c1: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004422c7: { // 0x4422c7: 8b88440c0000 MOV ECX, dword ptr [EAX + 0xc44]
    s.cx = m.r32((s.ax+0x00000c44u));
  }
  L004422cd: { // 0x4422cd: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004422cf: { // 0x4422cf: 7415 JZ 0x4422e6
    if(integer::condition("JZ",flags)) goto L004422e6;
  }
  L004422d1: { // 0x4422d1: 8a90da0a0000 MOV DL, byte ptr [EAX + 0xada]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000adau)));
  }
  L004422d7: { // 0x4422d7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004422d9: { // 0x4422d9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004422da: { // 0x4422da: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004422db: { // 0x4422db: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004422e1: { // 0x4422e1: e88a030b00 CALL 0x4f2670
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2670u,4465382u); flags=s.arithmetic_flags;
  }
  L004422e6: { // 0x4422e6: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004422ec: { // 0x4422ec: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L004422f2: { // 0x4422f2: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004422f4: { // 0x4422f4: 7413 JZ 0x442309
    if(integer::condition("JZ",flags)) goto L00442309;
  }
  L004422f6: { // 0x4422f6: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004422fb: { // 0x4422fb: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004422fd: { // 0x4422fd: 750a JNZ 0x442309
    if(integer::condition("JNZ",flags)) goto L00442309;
  }
  L004422ff: { // 0x4422ff: c786ec04000000000000 MOV dword ptr [ESI + 0x4ec], 0
    m.w32((s.si+0x000004ecu), 0u);
  }
  L00442309: { // 0x442309: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044230a: { // 0x44230a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044230b: { // 0x44230b: 8ac3 MOV AL, BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0044230d: { // 0x44230d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044230e: { // 0x44230e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044230f: { // 0x44230f: 83c430 ADD ESP, 0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00442312: { // 0x442312: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b9af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b9af0: { // 0x6b9af0: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006b9af3: { // 0x6b9af3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b9af4: { // 0x6b9af4: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006b9af6: { // 0x6b9af6: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L006b9af9: { // 0x6b9af9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b9afb: { // 0x6b9afb: 0f855c010000 JNZ 0x6b9c5d
    if(integer::condition("JNZ",flags)) goto L006b9c5d;
  }
  L006b9b01: { // 0x6b9b01: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9b03: { // 0x6b9b03: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7052041u); flags=s.arithmetic_flags;
  }
  L006b9b09: { // 0x6b9b09: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b9b0b: { // 0x6b9b0b: 0f844c010000 JZ 0x6b9c5d
    if(integer::condition("JZ",flags)) goto L006b9c5d;
  }
  L006b9b11: { // 0x6b9b11: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9b13: { // 0x6b9b13: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9b15: { // 0x6b9b15: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7052059u); flags=s.arithmetic_flags;
  }
  L006b9b1b: { // 0x6b9b1b: 8a8834050000 MOV CL, byte ptr [EAX + 0x534]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000534u)));
  }
  L006b9b21: { // 0x6b9b21: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b9b23: { // 0x6b9b23: 7419 JZ 0x6b9b3e
    if(integer::condition("JZ",flags)) goto L006b9b3e;
  }
  L006b9b25: { // 0x6b9b25: 8b0de4e0a100 MOV ECX, dword ptr [0xa1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006b9b2b: { // 0x6b9b2b: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9b2d: { // 0x6b9b2d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b9b2e: { // 0x6b9b2e: 6a01 PUSH 1
    f.push(m,1u);
  }
  L006b9b30: { // 0x6b9b30: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9b32: { // 0x6b9b32: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9b34: { // 0x6b9b34: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9b36: { // 0x6b9b36: ff901c040000 CALL dword ptr [EAX + 0x41c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000041cu)),7052092u); flags=s.arithmetic_flags;
  }
  L006b9b3c: { // 0x6b9b3c: eb12 JMP 0x6b9b50
    goto L006b9b50;
  }
  L006b9b3e: { // 0x6b9b3e: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9b40: { // 0x6b9b40: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9b42: { // 0x6b9b42: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9b44: { // 0x6b9b44: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9b46: { // 0x6b9b46: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9b48: { // 0x6b9b48: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9b4a: { // 0x6b9b4a: ff921c040000 CALL dword ptr [EDX + 0x41c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000041cu)),7052112u); flags=s.arithmetic_flags;
  }
  L006b9b50: { // 0x6b9b50: 8d8688000000 LEA EAX, [ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L006b9b56: { // 0x6b9b56: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9b58: { // 0x6b9b58: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b9b5a: { // 0x6b9b5a: 894c2408 MOV dword ptr [ESP + 8], ECX
    m.w32((f.sp+8u), s.cx);
  }
  L006b9b5e: { // 0x6b9b5e: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L006b9b61: { // 0x6b9b61: 8954240c MOV dword ptr [ESP + 0xc], EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L006b9b65: { // 0x6b9b65: 8d542408 LEA EDX, [ESP + 8]
    s.dx = (f.sp+8u);
  }
  L006b9b69: { // 0x6b9b69: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L006b9b6c: { // 0x6b9b6c: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006b9b70: { // 0x6b9b70: 8b86f4010000 MOV EAX, dword ptr [ESI + 0x1f4]
    s.ax = m.r32((s.si+0x000001f4u));
  }
  L006b9b76: { // 0x6b9b76: 8d4803 LEA ECX, [EAX + 3]
    s.cx = (s.ax+3u);
  }
  L006b9b79: { // 0x6b9b79: 83c0fd ADD EAX, -3
    s.ax = integer::add(s.ax,4294967293u,32,flags);
  }
  L006b9b7c: { // 0x6b9b7c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b9b7d: { // 0x6b9b7d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9b7e: { // 0x6b9b7e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006b9b7f: { // 0x6b9b7f: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006b9b84: { // 0x6b9b84: e857dee8ff CALL 0x5479e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005479e0u,7052169u); flags=s.arithmetic_flags;
  }
  L006b9b89: { // 0x6b9b89: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9b8b: { // 0x6b9b8b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9b8d: { // 0x6b9b8d: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7052179u); flags=s.arithmetic_flags;
  }
  L006b9b93: { // 0x6b9b93: 8a88dd0a0000 MOV CL, byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L006b9b99: { // 0x6b9b99: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b9b9b: { // 0x6b9b9b: 740a JZ 0x6b9ba7
    if(integer::condition("JZ",flags)) goto L006b9ba7;
  }
  L006b9b9d: { // 0x6b9b9d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9b9f: { // 0x6b9b9f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9ba1: { // 0x6b9ba1: ff92b0030000 CALL dword ptr [EDX + 0x3b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003b0u)),7052199u); flags=s.arithmetic_flags;
  }
  L006b9ba7: { // 0x6b9ba7: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006b9bad: { // 0x6b9bad: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b9bae: { // 0x6b9bae: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b9bb0: { // 0x6b9bb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b9bb1: { // 0x6b9bb1: e88a2de3ff CALL 0x4ec940
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ec940u,7052214u); flags=s.arithmetic_flags;
  }
  L006b9bb6: { // 0x6b9bb6: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9bb8: { // 0x6b9bb8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9bba: { // 0x6b9bba: ff90a0020000 CALL dword ptr [EAX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000002a0u)),7052224u); flags=s.arithmetic_flags;
  }
  L006b9bc0: { // 0x6b9bc0: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b9bc2: { // 0x6b9bc2: 7e65 JLE 0x6b9c29
    if(integer::condition("JLE",flags)) goto L006b9c29;
  }
  L006b9bc4: { // 0x6b9bc4: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b9bc6: { // 0x6b9bc6: 742f JZ 0x6b9bf7
    if(integer::condition("JZ",flags)) goto L006b9bf7;
  }
  L006b9bc8: { // 0x6b9bc8: f6461404 TEST byte ptr [ESI + 0x14], 4
    (void)integer::logical((m.r8((s.si+0x00000014u)))&(4u),8,flags);
  }
  L006b9bcc: { // 0x6b9bcc: 7429 JZ 0x6b9bf7
    if(integer::condition("JZ",flags)) goto L006b9bf7;
  }
  L006b9bce: { // 0x6b9bce: 8d8e54040000 LEA ECX, [ESI + 0x454]
    s.cx = (s.si+0x00000454u);
  }
  L006b9bd4: { // 0x6b9bd4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b9bd5: { // 0x6b9bd5: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006b9bda: { // 0x6b9bda: e821b9e8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7052255u); flags=s.arithmetic_flags;
  }
  L006b9bdf: { // 0x6b9bdf: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L006b9be1: { // 0x6b9be1: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b9be3: { // 0x6b9be3: 7444 JZ 0x6b9c29
    if(integer::condition("JZ",flags)) goto L006b9c29;
  }
  L006b9be5: { // 0x6b9be5: 8b9600040000 MOV EDX, dword ptr [ESI + 0x400]
    s.dx = m.r32((s.si+0x00000400u));
  }
  L006b9beb: { // 0x6b9beb: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9bed: { // 0x6b9bed: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L006b9bef: { // 0x6b9bef: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006b9bf0: { // 0x6b9bf0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9bf2: { // 0x6b9bf2: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),7052277u); flags=s.arithmetic_flags;
  }
  L006b9bf5: { // 0x6b9bf5: eb20 JMP 0x6b9c17
    goto L006b9c17;
  }
  L006b9bf7: { // 0x6b9bf7: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9bf9: { // 0x6b9bf9: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9bfb: { // 0x6b9bfb: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),7052289u); flags=s.arithmetic_flags;
  }
  L006b9c01: { // 0x6b9c01: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L006b9c03: { // 0x6b9c03: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b9c05: { // 0x6b9c05: 7422 JZ 0x6b9c29
    if(integer::condition("JZ",flags)) goto L006b9c29;
  }
  L006b9c07: { // 0x6b9c07: 8b8600040000 MOV EAX, dword ptr [ESI + 0x400]
    s.ax = m.r32((s.si+0x00000400u));
  }
  L006b9c0d: { // 0x6b9c0d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9c0f: { // 0x6b9c0f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006b9c11: { // 0x6b9c11: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9c12: { // 0x6b9c12: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9c14: { // 0x6b9c14: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),7052311u); flags=s.arithmetic_flags;
  }
  L006b9c17: { // 0x6b9c17: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9c18: { // 0x6b9c18: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b9c1a: { // 0x6b9c1a: e801cbdbff CALL 0x476720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00476720u,7052319u); flags=s.arithmetic_flags;
  }
  L006b9c1f: { // 0x6b9c1f: c7860004000000000000 MOV dword ptr [ESI + 0x400], 0
    m.w32((s.si+0x00000400u), 0u);
  }
  L006b9c29: { // 0x6b9c29: 8a867b030000 MOV AL, byte ptr [ESI + 0x37b]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000037bu)));
  }
  L006b9c2f: { // 0x6b9c2f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b9c30: { // 0x6b9c30: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b9c32: { // 0x6b9c32: 740a JZ 0x6b9c3e
    if(integer::condition("JZ",flags)) goto L006b9c3e;
  }
  L006b9c34: { // 0x6b9c34: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9c36: { // 0x6b9c36: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9c38: { // 0x6b9c38: ff9024040000 CALL dword ptr [EAX + 0x424]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000424u)),7052350u); flags=s.arithmetic_flags;
  }
  L006b9c3e: { // 0x6b9c3e: 8d8ed8030000 LEA ECX, [ESI + 0x3d8]
    s.cx = (s.si+0x000003d8u);
  }
  L006b9c44: { // 0x6b9c44: e827c4d4ff CALL 0x406070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00406070u,7052361u); flags=s.arithmetic_flags;
  }
  L006b9c49: { // 0x6b9c49: c786ec03000001000000 MOV dword ptr [ESI + 0x3ec], 1
    m.w32((s.si+0x000003ecu), 1u);
  }
  L006b9c53: { // 0x6b9c53: c786f003000000000000 MOV dword ptr [ESI + 0x3f0], 0
    m.w32((s.si+0x000003f0u), 0u);
  }
  L006b9c5d: { // 0x6b9c5d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b9c5f: { // 0x6b9c5f: e89c44f7ff CALL 0x62e100
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e100u,7052388u); flags=s.arithmetic_flags;
  }
  L006b9c64: { // 0x6b9c64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b9c65: { // 0x6b9c65: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006b9c68: { // 0x6b9c68: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022e100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062e100: { // 0x62e100: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062e101: { // 0x62e101: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0062e103: { // 0x62e103: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L0062e106: { // 0x62e106: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062e108: { // 0x62e108: 750a JNZ 0x62e114
    if(integer::condition("JNZ",flags)) goto L0062e114;
  }
  L0062e10a: { // 0x62e10a: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0062e10c: { // 0x62e10c: 6a03 PUSH 3
    f.push(m,3u);
  }
  L0062e10e: { // 0x62e10e: ff9060020000 CALL dword ptr [EAX + 0x260]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000260u)),6480148u); flags=s.arithmetic_flags;
  }
  L0062e114: { // 0x62e114: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0062e116: { // 0x62e116: e875dcf9ff CALL 0x5cbd90
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbd90u,6480155u); flags=s.arithmetic_flags;
  }
  L0062e11b: { // 0x62e11b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062e11c: { // 0x62e11c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001cbd90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cbd90: { // 0x5cbd90: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L005cbd95: { // 0x5cbd95: 83ec20 SUB ESP, 0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L005cbd98: { // 0x5cbd98: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbd9a: { // 0x5cbd9a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cbd9b: { // 0x5cbd9b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cbd9c: { // 0x5cbd9c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbd9d: { // 0x5cbd9d: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005cbd9f: { // 0x5cbd9f: 0f8467010000 JZ 0x5cbf0c
    if(integer::condition("JZ",flags)) goto L005cbf0c;
  }
  L005cbda5: { // 0x5cbda5: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cbda8: { // 0x5cbda8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbdaa: { // 0x5cbdaa: 0f855c010000 JNZ 0x5cbf0c
    if(integer::condition("JNZ",flags)) goto L005cbf0c;
  }
  L005cbdb0: { // 0x5cbdb0: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbdb2: { // 0x5cbdb2: ff9044010000 CALL dword ptr [EAX + 0x144]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000144u)),6077880u); flags=s.arithmetic_flags;
  }
  L005cbdb8: { // 0x5cbdb8: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbdba: { // 0x5cbdba: 6a01 PUSH 1
    f.push(m,1u);
  }
  L005cbdbc: { // 0x5cbdbc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbdbe: { // 0x5cbdbe: ff92d8000000 CALL dword ptr [EDX + 0xd8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d8u)),6077892u); flags=s.arithmetic_flags;
  }
  L005cbdc4: { // 0x5cbdc4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbdc6: { // 0x5cbdc6: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005cbdc8: { // 0x5cbdc8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbdca: { // 0x5cbdca: ff901c010000 CALL dword ptr [EAX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000011cu)),6077904u); flags=s.arithmetic_flags;
  }
  L005cbdd0: { // 0x5cbdd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cbdd1: { // 0x5cbdd1: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005cbdd6: { // 0x5cbdd6: e895daecff CALL 0x499870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499870u,6077915u); flags=s.arithmetic_flags;
  }
  L005cbddb: { // 0x5cbddb: 8d4e3c LEA ECX, [ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  L005cbdde: { // 0x5cbdde: e86d9fe3ff CALL 0x405d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405d50u,6077923u); flags=s.arithmetic_flags;
  }
  L005cbde3: { // 0x5cbde3: 8d4e50 LEA ECX, [ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  L005cbde6: { // 0x5cbde6: e8f5a1e3ff CALL 0x405fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405fe0u,6077931u); flags=s.arithmetic_flags;
  }
  L005cbdeb: { // 0x5cbdeb: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbded: { // 0x5cbded: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbdef: { // 0x5cbdef: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6077941u); flags=s.arithmetic_flags;
  }
  L005cbdf5: { // 0x5cbdf5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbdf7: { // 0x5cbdf7: 743c JZ 0x5cbe35
    if(integer::condition("JZ",flags)) goto L005cbe35;
  }
  L005cbdf9: { // 0x5cbdf9: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbdfb: { // 0x5cbdfb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbdfd: { // 0x5cbdfd: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6077955u); flags=s.arithmetic_flags;
  }
  L005cbe03: { // 0x5cbe03: 8a8804020000 MOV CL, byte ptr [EAX + 0x204]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000204u)));
  }
  L005cbe09: { // 0x5cbe09: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cbe0b: { // 0x5cbe0b: 7428 JZ 0x5cbe35
    if(integer::condition("JZ",flags)) goto L005cbe35;
  }
  L005cbe0d: { // 0x5cbe0d: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L005cbe12: { // 0x5cbe12: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbe14: { // 0x5cbe14: 7414 JZ 0x5cbe2a
    if(integer::condition("JZ",flags)) goto L005cbe2a;
  }
  L005cbe16: { // 0x5cbe16: 83f805 CMP EAX, 5
    (void)integer::sub(s.ax,5u,32,flags);
  }
  L005cbe19: { // 0x5cbe19: 740f JZ 0x5cbe2a
    if(integer::condition("JZ",flags)) goto L005cbe2a;
  }
  L005cbe1b: { // 0x5cbe1b: 8b4e04 MOV ECX, dword ptr [ESI + 4]
    s.cx = m.r32((s.si+4u));
  }
  L005cbe1e: { // 0x5cbe1e: 8d4604 LEA EAX, [ESI + 4]
    s.ax = (s.si+4u);
  }
  L005cbe21: { // 0x5cbe21: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbe22: { // 0x5cbe22: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6077989u); flags=s.arithmetic_flags;
  }
  L005cbe25: { // 0x5cbe25: 83f8fe CMP EAX, -2
    (void)integer::sub(s.ax,4294967294u,32,flags);
  }
  L005cbe28: { // 0x5cbe28: 740b JZ 0x5cbe35
    if(integer::condition("JZ",flags)) goto L005cbe35;
  }
  L005cbe2a: { // 0x5cbe2a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cbe2b: { // 0x5cbe2b: b9b0a78100 MOV ECX, 0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  L005cbe30: { // 0x5cbe30: e81b07f7ff CALL 0x53c550
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053c550u,6078005u); flags=s.arithmetic_flags;
  }
  L005cbe35: { // 0x5cbe35: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbe37: { // 0x5cbe37: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbe39: { // 0x5cbe39: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6078015u); flags=s.arithmetic_flags;
  }
  L005cbe3f: { // 0x5cbe3f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbe41: { // 0x5cbe41: 0f84aa000000 JZ 0x5cbef1
    if(integer::condition("JZ",flags)) goto L005cbef1;
  }
  L005cbe47: { // 0x5cbe47: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbe49: { // 0x5cbe49: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbe4b: { // 0x5cbe4b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078033u); flags=s.arithmetic_flags;
  }
  L005cbe51: { // 0x5cbe51: 8b88ac000000 MOV ECX, dword ptr [EAX + 0xac]
    s.cx = m.r32((s.ax+0x000000acu));
  }
  L005cbe57: { // 0x5cbe57: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cbe59: { // 0x5cbe59: 0f8492000000 JZ 0x5cbef1
    if(integer::condition("JZ",flags)) goto L005cbef1;
  }
  L005cbe5f: { // 0x5cbe5f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbe61: { // 0x5cbe61: 8d442420 LEA EAX, [ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L005cbe65: { // 0x5cbe65: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbe66: { // 0x5cbe66: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbe68: { // 0x5cbe68: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6078059u); flags=s.arithmetic_flags;
  }
  L005cbe6b: { // 0x5cbe6b: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cbe6d: { // 0x5cbe6d: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005cbe71: { // 0x5cbe71: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L005cbe75: { // 0x5cbe75: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L005cbe78: { // 0x5cbe78: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cbe79: { // 0x5cbe79: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cbe7f: { // 0x5cbe7f: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L005cbe83: { // 0x5cbe83: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L005cbe86: { // 0x5cbe86: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L005cbe8a: { // 0x5cbe8a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cbe8b: { // 0x5cbe8b: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005cbe8f: { // 0x5cbe8f: e87cc10c00 CALL 0x698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6078100u); flags=s.arithmetic_flags;
  }
  L005cbe94: { // 0x5cbe94: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbe96: { // 0x5cbe96: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbe98: { // 0x5cbe98: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078110u); flags=s.arithmetic_flags;
  }
  L005cbe9e: { // 0x5cbe9e: 8b88ac000000 MOV ECX, dword ptr [EAX + 0xac]
    s.cx = m.r32((s.ax+0x000000acu));
  }
  L005cbea4: { // 0x5cbea4: 6a01 PUSH 1
    f.push(m,1u);
  }
  L005cbea6: { // 0x5cbea6: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L005cbea9: { // 0x5cbea9: 0fbf4102 MOVSX EAX, word ptr [ECX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+2u)),16));
  }
  L005cbead: { // 0x5cbead: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cbeae: { // 0x5cbeae: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cbeb0: { // 0x5cbeb0: 8bdc MOV EBX, ESP
    s.bx = f.sp;
  }
  L005cbeb2: { // 0x5cbeb2: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L005cbeb4: { // 0x5cbeb4: 0fbf4104 MOVSX EAX, word ptr [ECX + 4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+4u)),16));
  }
  L005cbeb8: { // 0x5cbeb8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cbeb9: { // 0x5cbeb9: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cbebb: { // 0x5cbebb: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005cbebf: { // 0x5cbebf: d1ff SAR EDI, 1
    s.di = integer::shift(s.di,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cbec1: { // 0x5cbec1: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L005cbec3: { // 0x5cbec3: 8b7c2424 MOV EDI, dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L005cbec7: { // 0x5cbec7: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cbec9: { // 0x5cbec9: 2bf8 SUB EDI, EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L005cbecb: { // 0x5cbecb: 8913 MOV dword ptr [EBX], EDX
    m.w32((s.bx), s.dx);
  }
  L005cbecd: { // 0x5cbecd: 89542420 MOV dword ptr [ESP + 0x20], EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L005cbed1: { // 0x5cbed1: 897c2424 MOV dword ptr [ESP + 0x24], EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L005cbed5: { // 0x5cbed5: 0fbf4102 MOVSX EAX, word ptr [ECX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+2u)),16));
  }
  L005cbed9: { // 0x5cbed9: 0fbf4904 MOVSX ECX, word ptr [ECX + 4]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx+4u)),16));
  }
  L005cbedd: { // 0x5cbedd: 897b04 MOV dword ptr [EBX + 4], EDI
    m.w32((s.bx+4u), s.di);
  }
  L005cbee0: { // 0x5cbee0: 894308 MOV dword ptr [EBX + 8], EAX
    m.w32((s.bx+8u), s.ax);
  }
  L005cbee3: { // 0x5cbee3: 894b0c MOV dword ptr [EBX + 0xc], ECX
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L005cbee6: { // 0x5cbee6: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cbeec: { // 0x5cbeec: e86fc70c00 CALL 0x698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,6078193u); flags=s.arithmetic_flags;
  }
  L005cbef1: { // 0x5cbef1: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbef3: { // 0x5cbef3: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005cbef5: { // 0x5cbef5: ff9214010000 CALL dword ptr [EDX + 0x114]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000114u)),6078203u); flags=s.arithmetic_flags;
  }
  L005cbefb: { // 0x5cbefb: c6467601 MOV byte ptr [ESI + 0x76], 1
    m.w8((s.si+0x00000076u), 1u);
  }
  L005cbeff: { // 0x5cbeff: c6467500 MOV byte ptr [ESI + 0x75], 0
    m.w8((s.si+0x00000075u), 0u);
  }
  L005cbf03: { // 0x5cbf03: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L005cbf05: { // 0x5cbf05: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cbf06: { // 0x5cbf06: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cbf07: { // 0x5cbf07: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cbf08: { // 0x5cbf08: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L005cbf0b: { // 0x5cbf0b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cbf0c: { // 0x5cbf0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cbf0d: { // 0x5cbf0d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cbf0e: { // 0x5cbf0e: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cbf10: { // 0x5cbf10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cbf11: { // 0x5cbf11: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L005cbf14: { // 0x5cbf14: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4464096u:f_00041de0(m,s,child,{});break;
case 7052016u:f_002b9af0(m,s,child,{});break;
case 6480128u:f_0022e100(m,s,child,{});break;
case 6077840u:f_001cbd90(m,s,child,{});break;
default:throw std::domain_error("recovery759 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00468580(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00468580: { // 0x468580: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00468581: { // 0x468581: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00468585: { // 0x468585: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00468586: { // 0x468586: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00468588: { // 0x468588: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0046858a: { // 0x46858a: 747e JZ 0x0046860a
    if(integer::condition("JZ",flags)) goto L0046860a;
  }
  L0046858c: { // 0x46858c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0046858e: { // 0x46858e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00468590: { // 0x468590: ff90d0000000 CALL dword ptr [EAX + 0xd0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000d0u)),4621718u); flags=s.arithmetic_flags;
  }
  L00468596: { // 0x468596: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L00468599: { // 0x468599: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0046859b: { // 0x46859b: 743d JZ 0x004685da
    if(integer::condition("JZ",flags)) goto L004685da;
  }
  L0046859d: { // 0x46859d: 8a4814 MOV CL,byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L004685a0: { // 0x4685a0: c0e902 SHR CL,0x2
    s.cx = with_al(s.cx, integer::shift((s.cx & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L004685a3: { // 0x4685a3: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004685a6: { // 0x4685a6: 884c240c MOV byte ptr [ESP + 0xc],CL
    m.w8((f.sp+0x0000000cu), (s.cx & 0xffu));
  }
  L004685aa: { // 0x4685aa: 742e JZ 0x004685da
    if(integer::condition("JZ",flags)) goto L004685da;
  }
  L004685ac: { // 0x4685ac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004685ae: { // 0x4685ae: 742a JZ 0x004685da
    if(integer::condition("JZ",flags)) goto L004685da;
  }
  L004685b0: { // 0x4685b0: 8b4830 MOV ECX,dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L004685b3: { // 0x4685b3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004685b5: { // 0x4685b5: 7417 JZ 0x004685ce
    if(integer::condition("JZ",flags)) goto L004685ce;
  }
  L004685b7: { // 0x4685b7: 8a5114 MOV DL,byte ptr [ECX + 0x14]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000014u)));
  }
  L004685ba: { // 0x4685ba: c0ea02 SHR DL,0x2
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L004685bd: { // 0x4685bd: 80e201 AND DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags));
  }
  L004685c0: { // 0x4685c0: 8854240c MOV byte ptr [ESP + 0xc],DL
    m.w8((f.sp+0x0000000cu), (s.dx & 0xffu));
  }
  L004685c4: { // 0x4685c4: 7414 JZ 0x004685da
    if(integer::condition("JZ",flags)) goto L004685da;
  }
  L004685c6: { // 0x4685c6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004685c8: { // 0x4685c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004685ca: { // 0x4685ca: 740e JZ 0x004685da
    if(integer::condition("JZ",flags)) goto L004685da;
  }
  L004685cc: { // 0x4685cc: ebe2 JMP 0x004685b0
    goto L004685b0;
  }
  L004685ce: { // 0x4685ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004685d0: { // 0x4685d0: 7408 JZ 0x004685da
    if(integer::condition("JZ",flags)) goto L004685da;
  }
  L004685d2: { // 0x4685d2: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L004685d5: { // 0x4685d5: 894830 MOV dword ptr [EAX + 0x30],ECX
    m.w32((s.ax+0x00000030u), s.cx);
  }
  L004685d8: { // 0x4685d8: eb06 JMP 0x004685e0
    goto L004685e0;
  }
  L004685da: { // 0x4685da: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L004685dd: { // 0x4685dd: 895630 MOV dword ptr [ESI + 0x30],EDX
    m.w32((s.si+0x00000030u), s.dx);
  }
  L004685e0: { // 0x4685e0: 897704 MOV dword ptr [EDI + 0x4],ESI
    m.w32((s.di+0x00000004u), s.si);
  }
  L004685e3: { // 0x4685e3: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L004685e9: { // 0x4685e9: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004685eb: { // 0x4685eb: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004685ec: { // 0x4685ec: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L004685ee: { // 0x4685ee: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004685f1: { // 0x4685f1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004685f3: { // 0x4685f3: 7415 JZ 0x0046860a
    if(integer::condition("JZ",flags)) goto L0046860a;
  }
  L004685f5: { // 0x4685f5: 8a4814 MOV CL,byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L004685f8: { // 0x4685f8: c0e902 SHR CL,0x2
    s.cx = with_al(s.cx, integer::shift((s.cx & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L004685fb: { // 0x4685fb: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004685fe: { // 0x4685fe: 884c240c MOV byte ptr [ESP + 0xc],CL
    m.w8((f.sp+0x0000000cu), (s.cx & 0xffu));
  }
  L00468602: { // 0x468602: 7406 JZ 0x0046860a
    if(integer::condition("JZ",flags)) goto L0046860a;
  }
  L00468604: { // 0x468604: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00468606: { // 0x468606: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00468608: { // 0x468608: 75df JNZ 0x004685e9
    if(integer::condition("JNZ",flags)) goto L004685e9;
  }
  L0046860a: { // 0x46860a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046860b: { // 0x46860b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046860c: { // 0x46860c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
