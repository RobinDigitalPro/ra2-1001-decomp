#include "recovered/recovery_b833_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b833 {
namespace {
void f_00367dc0(Memory&,State&,Frame&,const Operations&);
void f_00363ef0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00367dc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00767dc0: { // 0x767dc0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00767dc1: { // 0x767dc1: 8b8180000000 MOV EAX,dword ptr [ECX + 0x80]
    s.ax = m.r32((s.cx+0x00000080u));
  }
  L00767dc7: { // 0x767dc7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00767dc8: { // 0x767dc8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00767dc9: { // 0x767dc9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00767dca: { // 0x767dca: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00767dce: { // 0x767dce: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00767dcf: { // 0x767dcf: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00767dd1: { // 0x767dd1: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00767dd5: { // 0x767dd5: 83e730 AND EDI,0x30
    s.di = integer::logical((s.di)&(0x00000030u),32,flags);
  }
  L00767dd8: { // 0x767dd8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00767dda: { // 0x767dda: 7507 JNZ 0x00767de3
    if(integer::condition("JNZ",flags)) goto L00767de3;
  }
  L00767ddc: { // 0x767ddc: 668bb1ee000000 MOV SI,word ptr [ECX + 0xee]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.cx+0x000000eeu))) & 0xffffu);
  }
  L00767de3: { // 0x767de3: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00767de7: { // 0x767de7: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00767de9: { // 0x767de9: 750b JNZ 0x00767df6
    if(integer::condition("JNZ",flags)) goto L00767df6;
  }
  L00767deb: { // 0x767deb: 668b91f0000000 MOV DX,word ptr [ECX + 0xf0]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x000000f0u)));
  }
  L00767df2: { // 0x767df2: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00767df6: { // 0x767df6: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L00767dfa: { // 0x767dfa: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L00767dfe: { // 0x767dfe: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00767e00: { // 0x767e00: 0f8dae000000 JGE 0x00767eb4
    if(integer::condition("JGE",flags)) goto L00767eb4;
  }
  L00767e06: { // 0x767e06: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00767e08: { // 0x767e08: 0f8da6000000 JGE 0x00767eb4
    if(integer::condition("JGE",flags)) goto L00767eb4;
  }
  L00767e0e: { // 0x767e0e: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00767e10: { // 0x767e10: 7442 JZ 0x00767e54
    if(integer::condition("JZ",flags)) goto L00767e54;
  }
  L00767e12: { // 0x767e12: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00767e14: { // 0x767e14: 7421 JZ 0x00767e37
    if(integer::condition("JZ",flags)) goto L00767e37;
  }
  L00767e16: { // 0x767e16: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e18: { // 0x767e18: 668b81fa000000 MOV AX,word ptr [ECX + 0xfa]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000fau)));
  }
  L00767e1f: { // 0x767e1f: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767e21: { // 0x767e21: 8981b4010000 MOV dword ptr [ECX + 0x1b4],EAX
    m.w32((s.cx+0x000001b4u), s.ax);
  }
  L00767e27: { // 0x767e27: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e29: { // 0x767e29: 668b81fc000000 MOV AX,word ptr [ECX + 0xfc]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000fcu)));
  }
  L00767e30: { // 0x767e30: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767e32: { // 0x767e32: e9bd000000 JMP 0x00767ef4
    goto L00767ef4;
  }
  L00767e37: { // 0x767e37: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e39: { // 0x767e39: 668b81fa000000 MOV AX,word ptr [ECX + 0xfa]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000fau)));
  }
  L00767e40: { // 0x767e40: 8981b4010000 MOV dword ptr [ECX + 0x1b4],EAX
    m.w32((s.cx+0x000001b4u), s.ax);
  }
  L00767e46: { // 0x767e46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e48: { // 0x767e48: 668b81fc000000 MOV AX,word ptr [ECX + 0xfc]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000fcu)));
  }
  L00767e4f: { // 0x767e4f: e9a0000000 JMP 0x00767ef4
    goto L00767ef4;
  }
  L00767e54: { // 0x767e54: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00767e56: { // 0x767e56: 7430 JZ 0x00767e88
    if(integer::condition("JZ",flags)) goto L00767e88;
  }
  L00767e58: { // 0x767e58: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e5a: { // 0x767e5a: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L00767e5c: { // 0x767e5c: 668b81ee000000 MOV AX,word ptr [ECX + 0xee]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000eeu)));
  }
  L00767e63: { // 0x767e63: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767e65: { // 0x767e65: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00767e67: { // 0x767e67: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e69: { // 0x767e69: d1ef SHR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767e6b: { // 0x767e6b: 89b9b4010000 MOV dword ptr [ECX + 0x1b4],EDI
    m.w32((s.cx+0x000001b4u), s.di);
  }
  L00767e71: { // 0x767e71: 668b81f0000000 MOV AX,word ptr [ECX + 0xf0]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000f0u)));
  }
  L00767e78: { // 0x767e78: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767e7a: { // 0x767e7a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00767e7c: { // 0x767e7c: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00767e7e: { // 0x767e7e: d1ef SHR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767e80: { // 0x767e80: 89b9b8010000 MOV dword ptr [ECX + 0x1b8],EDI
    m.w32((s.cx+0x000001b8u), s.di);
  }
  L00767e86: { // 0x767e86: eb72 JMP 0x00767efa
    goto L00767efa;
  }
  L00767e88: { // 0x767e88: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e8a: { // 0x767e8a: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L00767e8c: { // 0x767e8c: 668b81ee000000 MOV AX,word ptr [ECX + 0xee]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000eeu)));
  }
  L00767e93: { // 0x767e93: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00767e95: { // 0x767e95: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00767e97: { // 0x767e97: d1ef SHR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767e99: { // 0x767e99: 89b9b4010000 MOV dword ptr [ECX + 0x1b4],EDI
    m.w32((s.cx+0x000001b4u), s.di);
  }
  L00767e9f: { // 0x767e9f: 668b81f0000000 MOV AX,word ptr [ECX + 0xf0]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x000000f0u)));
  }
  L00767ea6: { // 0x767ea6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00767ea8: { // 0x767ea8: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00767eaa: { // 0x767eaa: d1ef SHR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::right);
  }
  L00767eac: { // 0x767eac: 89b9b8010000 MOV dword ptr [ECX + 0x1b8],EDI
    m.w32((s.cx+0x000001b8u), s.di);
  }
  L00767eb2: { // 0x767eb2: eb46 JMP 0x00767efa
    goto L00767efa;
  }
  L00767eb4: { // 0x767eb4: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00767eb6: { // 0x767eb6: 7416 JZ 0x00767ece
    if(integer::condition("JZ",flags)) goto L00767ece;
  }
  L00767eb8: { // 0x767eb8: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00767eba: { // 0x767eba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00767ebb: { // 0x767ebb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00767ebd: { // 0x767ebd: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00767ebf: { // 0x767ebf: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00767ec1: { // 0x767ec1: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00767ec3: { // 0x767ec3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00767ec4: { // 0x767ec4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00767ec6: { // 0x767ec6: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00767eca: { // 0x767eca: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00767ecc: { // 0x767ecc: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00767ece: { // 0x767ece: 83ff20 CMP EDI,0x20
    (void)integer::sub(s.di,0x00000020u,32,flags);
  }
  L00767ed1: { // 0x767ed1: 7413 JZ 0x00767ee6
    if(integer::condition("JZ",flags)) goto L00767ee6;
  }
  L00767ed3: { // 0x767ed3: 83ff30 CMP EDI,0x30
    (void)integer::sub(s.di,0x00000030u,32,flags);
  }
  L00767ed6: { // 0x767ed6: 8999b4010000 MOV dword ptr [ECX + 0x1b4],EBX
    m.w32((s.cx+0x000001b4u), s.bx);
  }
  L00767edc: { // 0x767edc: 7412 JZ 0x00767ef0
    if(integer::condition("JZ",flags)) goto L00767ef0;
  }
  L00767ede: { // 0x767ede: 89a9b8010000 MOV dword ptr [ECX + 0x1b8],EBP
    m.w32((s.cx+0x000001b8u), s.bp);
  }
  L00767ee4: { // 0x767ee4: eb14 JMP 0x00767efa
    goto L00767efa;
  }
  L00767ee6: { // 0x767ee6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00767ee8: { // 0x767ee8: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00767eea: { // 0x767eea: 8981b4010000 MOV dword ptr [ECX + 0x1b4],EAX
    m.w32((s.cx+0x000001b4u), s.ax);
  }
  L00767ef0: { // 0x767ef0: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00767ef2: { // 0x767ef2: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00767ef4: { // 0x767ef4: 8981b8010000 MOV dword ptr [ECX + 0x1b8],EAX
    m.w32((s.cx+0x000001b8u), s.ax);
  }
  L00767efa: { // 0x767efa: 8bb9b4010000 MOV EDI,dword ptr [ECX + 0x1b4]
    s.di = m.r32((s.cx+0x000001b4u));
  }
  L00767f00: { // 0x767f00: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00767f02: { // 0x767f02: 7c67 JL 0x00767f6b
    if(integer::condition("JL",flags)) goto L00767f6b;
  }
  L00767f04: { // 0x767f04: 8b81b8010000 MOV EAX,dword ptr [ECX + 0x1b8]
    s.ax = m.r32((s.cx+0x000001b8u));
  }
  L00767f0a: { // 0x767f0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00767f0c: { // 0x767f0c: 7c5d JL 0x00767f6b
    if(integer::condition("JL",flags)) goto L00767f6b;
  }
  L00767f0e: { // 0x767f0e: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00767f10: { // 0x767f10: 7359 JNC 0x00767f6b
    if(integer::condition("JNC",flags)) goto L00767f6b;
  }
  L00767f12: { // 0x767f12: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00767f14: { // 0x767f14: 7355 JNC 0x00767f6b
    if(integer::condition("JNC",flags)) goto L00767f6b;
  }
  L00767f16: { // 0x767f16: 8a9908010000 MOV BL,byte ptr [ECX + 0x108]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000108u)));
  }
  L00767f1c: { // 0x767f1c: 80fb01 CMP BL,0x1
    (void)integer::sub((s.bx & 0xffu),0x00000001u,8,flags);
  }
  L00767f1f: { // 0x767f1f: 7405 JZ 0x00767f26
    if(integer::condition("JZ",flags)) goto L00767f26;
  }
  L00767f21: { // 0x767f21: 80fb04 CMP BL,0x4
    (void)integer::sub((s.bx & 0xffu),0x00000004u,8,flags);
  }
  L00767f24: { // 0x767f24: 7504 JNZ 0x00767f2a
    if(integer::condition("JNZ",flags)) goto L00767f2a;
  }
  L00767f26: { // 0x767f26: 03ff ADD EDI,EDI
    s.di = integer::add(s.di,s.di,32,flags);
  }
  L00767f28: { // 0x767f28: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  L00767f2a: { // 0x767f2a: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00767f2d: { // 0x767f2d: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00767f2f: { // 0x767f2f: 89b1ac010000 MOV dword ptr [ECX + 0x1ac],ESI
    m.w32((s.cx+0x000001acu), s.si);
  }
  L00767f35: { // 0x767f35: 8981bc010000 MOV dword ptr [ECX + 0x1bc],EAX
    m.w32((s.cx+0x000001bcu), s.ax);
  }
  L00767f3b: { // 0x767f3b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00767f3f: { // 0x767f3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00767f41: { // 0x767f41: 8991b0010000 MOV dword ptr [ECX + 0x1b0],EDX
    m.w32((s.cx+0x000001b0u), s.dx);
  }
  L00767f47: { // 0x767f47: 7409 JZ 0x00767f52
    if(integer::condition("JZ",flags)) goto L00767f52;
  }
  L00767f49: { // 0x767f49: 8981a8010000 MOV dword ptr [ECX + 0x1a8],EAX
    m.w32((s.cx+0x000001a8u), s.ax);
  }
  L00767f4f: { // 0x767f4f: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00767f52: { // 0x767f52: 8b8150010000 MOV EAX,dword ptr [ECX + 0x150]
    s.ax = m.r32((s.cx+0x00000150u));
  }
  L00767f58: { // 0x767f58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00767f59: { // 0x767f59: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00767f5b: { // 0x767f5b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00767f5c: { // 0x767f5c: 898150010000 MOV dword ptr [ECX + 0x150],EAX
    m.w32((s.cx+0x00000150u), s.ax);
  }
  L00767f62: { // 0x767f62: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00767f63: { // 0x767f63: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00767f66: { // 0x767f66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00767f67: { // 0x767f67: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00767f68: { // 0x767f68: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00767f6b: { // 0x767f6b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00767f6c: { // 0x767f6c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00767f6d: { // 0x767f6d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00767f6e: { // 0x767f6e: b8e8ffffff MOV EAX,0xffffffe8
    s.ax = 0xffffffe8u;
  }
  L00767f73: { // 0x767f73: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00767f74: { // 0x767f74: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00767f75: { // 0x767f75: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00363ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763ef0: { // 0x763ef0: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L00763ef4: { // 0x763ef4: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00763ef8: { // 0x763ef8: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763efa: { // 0x763efa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00763efb: { // 0x763efb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763efc: { // 0x763efc: 83f908 CMP ECX, 8
    (void)integer::sub(s.cx,8u,32,flags);
  }
  L00763eff: { // 0x763eff: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763f00: { // 0x763f00: 0f8790000000 JA 0x763f96
    if(integer::condition("JA",flags)) goto L00763f96;
  }
  L00763f06: { // 0x763f06: ff248d9c3f7600 JMP dword ptr [ECX*4 + 0x763f9c]
    switch((std::array<std::uint32_t,9>{0x763f73u,0x763f73u,0x763f73u,0x763f73u,0x763f0du,0x763f91u,0x763f55u,0x763f55u,0x763f73u}[s.cx])){
    case 0x00763ef0u: goto L00763ef0;
    case 0x00763ef4u: goto L00763ef4;
    case 0x00763ef8u: goto L00763ef8;
    case 0x00763efau: goto L00763efa;
    case 0x00763efbu: goto L00763efb;
    case 0x00763efcu: goto L00763efc;
    case 0x00763effu: goto L00763eff;
    case 0x00763f00u: goto L00763f00;
    case 0x00763f06u: goto L00763f06;
    case 0x00763f0du: goto L00763f0d;
    case 0x00763f13u: goto L00763f13;
    case 0x00763f17u: goto L00763f17;
    case 0x00763f1du: goto L00763f1d;
    case 0x00763f20u: goto L00763f20;
    case 0x00763f22u: goto L00763f22;
    case 0x00763f24u: goto L00763f24;
    case 0x00763f2au: goto L00763f2a;
    case 0x00763f2cu: goto L00763f2c;
    case 0x00763f2du: goto L00763f2d;
    case 0x00763f2fu: goto L00763f2f;
    case 0x00763f31u: goto L00763f31;
    case 0x00763f35u: goto L00763f35;
    case 0x00763f38u: goto L00763f38;
    case 0x00763f3au: goto L00763f3a;
    case 0x00763f3cu: goto L00763f3c;
    case 0x00763f3du: goto L00763f3d;
    case 0x00763f40u: goto L00763f40;
    case 0x00763f42u: goto L00763f42;
    case 0x00763f48u: goto L00763f48;
    case 0x00763f49u: goto L00763f49;
    case 0x00763f4bu: goto L00763f4b;
    case 0x00763f4du: goto L00763f4d;
    case 0x00763f53u: goto L00763f53;
    case 0x00763f54u: goto L00763f54;
    case 0x00763f55u: goto L00763f55;
    case 0x00763f59u: goto L00763f59;
    case 0x00763f5cu: goto L00763f5c;
    case 0x00763f5eu: goto L00763f5e;
    case 0x00763f5fu: goto L00763f5f;
    case 0x00763f61u: goto L00763f61;
    case 0x00763f65u: goto L00763f65;
    case 0x00763f6bu: goto L00763f6b;
    case 0x00763f6du: goto L00763f6d;
    case 0x00763f73u: goto L00763f73;
    case 0x00763f74u: goto L00763f74;
    case 0x00763f76u: goto L00763f76;
    case 0x00763f77u: goto L00763f77;
    case 0x00763f78u: goto L00763f78;
    case 0x00763f7eu: goto L00763f7e;
    case 0x00763f82u: goto L00763f82;
    case 0x00763f84u: goto L00763f84;
    case 0x00763f86u: goto L00763f86;
    case 0x00763f88u: goto L00763f88;
    case 0x00763f89u: goto L00763f89;
    case 0x00763f8fu: goto L00763f8f;
    case 0x00763f90u: goto L00763f90;
    case 0x00763f91u: goto L00763f91;
    case 0x00763f96u: goto L00763f96;
    case 0x00763f97u: goto L00763f97;
    case 0x00763f98u: goto L00763f98;
    default:throw std::domain_error("recovery833 unsupported switch destination");}
  }
  L00763f0d: { // 0x763f0d: 8bba04070000 MOV EDI, dword ptr [EDX + 0x704]
    s.di = m.r32((s.dx+0x00000704u));
  }
  L00763f13: { // 0x763f13: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00763f17: { // 0x763f17: 8bb200070000 MOV ESI, dword ptr [EDX + 0x700]
    s.si = m.r32((s.dx+0x00000700u));
  }
  L00763f1d: { // 0x763f1d: 8d0c07 LEA ECX, [EDI + EAX]
    s.cx = (s.di+s.ax);
  }
  L00763f20: { // 0x763f20: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00763f22: { // 0x763f22: 7f6d JG 0x763f91
    if(integer::condition("JG",flags)) goto L00763f91;
  }
  L00763f24: { // 0x763f24: 8bb2f4060000 MOV ESI, dword ptr [EDX + 0x6f4]
    s.si = m.r32((s.dx+0x000006f4u));
  }
  L00763f2a: { // 0x763f2a: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00763f2c: { // 0x763f2c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763f2d: { // 0x763f2d: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L00763f2f: { // 0x763f2f: 03f7 ADD ESI, EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00763f31: { // 0x763f31: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00763f35: { // 0x763f35: c1e902 SHR ECX, 2
    s.cx = integer::shift(s.cx,2u,32,flags,integer::Shift::right);
  }
  L00763f38: { // 0x763f38: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00763f3a: { // 0x763f3a: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L00763f3c: { // 0x763f3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763f3d: { // 0x763f3d: 83e103 AND ECX, 3
    s.cx = integer::logical((s.cx)&(3u),32,flags);
  }
  L00763f40: { // 0x763f40: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00763f42: { // 0x763f42: 8b8a04070000 MOV ECX, dword ptr [EDX + 0x704]
    s.cx = m.r32((s.dx+0x00000704u));
  }
  L00763f48: { // 0x763f48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f49: { // 0x763f49: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00763f4b: { // 0x763f4b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763f4d: { // 0x763f4d: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f53: { // 0x763f53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f54: { // 0x763f54: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f55: { // 0x763f55: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00763f59: { // 0x763f59: 83e900 SUB ECX, 0
    s.cx = integer::sub(s.cx,0u,32,flags);
  }
  L00763f5c: { // 0x763f5c: 741a JZ 0x763f78
    if(integer::condition("JZ",flags)) goto L00763f78;
  }
  L00763f5e: { // 0x763f5e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00763f5f: { // 0x763f5f: 7530 JNZ 0x763f91
    if(integer::condition("JNZ",flags)) goto L00763f91;
  }
  L00763f61: { // 0x763f61: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00763f65: { // 0x763f65: 8b8a04070000 MOV ECX, dword ptr [EDX + 0x704]
    s.cx = m.r32((s.dx+0x00000704u));
  }
  L00763f6b: { // 0x763f6b: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00763f6d: { // 0x763f6d: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f73: { // 0x763f73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f74: { // 0x763f74: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763f76: { // 0x763f76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f77: { // 0x763f77: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f78: { // 0x763f78: 8bb2fc060000 MOV ESI, dword ptr [EDX + 0x6fc]
    s.si = m.r32((s.dx+0x000006fcu));
  }
  L00763f7e: { // 0x763f7e: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00763f82: { // 0x763f82: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00763f84: { // 0x763f84: 7c0b JL 0x763f91
    if(integer::condition("JL",flags)) goto L00763f91;
  }
  L00763f86: { // 0x763f86: 2bce SUB ECX, ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L00763f88: { // 0x763f88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f89: { // 0x763f89: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f8f: { // 0x763f8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f90: { // 0x763f90: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f91: { // 0x763f91: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00763f96: { // 0x763f96: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f97: { // 0x763f97: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f98: { // 0x763f98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}


} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7765440u:f_00367dc0(m,s,child,{});break;
case 7749360u:f_00363ef0(m,s,child,{});break;
default:throw std::domain_error("recovery833 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00762ff0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00762ff0: { // 0x762ff0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00762ff1: { // 0x762ff1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00762ff2: { // 0x762ff2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00762ff3: { // 0x762ff3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00762ff4: { // 0x762ff4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00762ff6: { // 0x762ff6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00762ff7: { // 0x762ff7: 8b6e60 MOV EBP,dword ptr [ESI + 0x60]
    s.bp = m.r32((s.si+0x00000060u));
  }
  L00762ffa: { // 0x762ffa: 83fdff CMP EBP,-0x1
    (void)integer::sub(s.bp,0xffffffffu,32,flags);
  }
  L00762ffd: { // 0x762ffd: 7408 JZ 0x00763007
    if(integer::condition("JZ",flags)) goto L00763007;
  }
  L00762fff: { // 0x762fff: 8b4664 MOV EAX,dword ptr [ESI + 0x64]
    s.ax = m.r32((s.si+0x00000064u));
  }
  L00763002: { // 0x763002: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00763005: { // 0x763005: 753a JNZ 0x00763041
    if(integer::condition("JNZ",flags)) goto L00763041;
  }
  L00763007: { // 0x763007: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763009: { // 0x763009: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0076300b: { // 0x76300b: 668b86f0000000 MOV AX,word ptr [ESI + 0xf0]
    s.ax = with_ax(s.ax, m.r16((s.si+0x000000f0u)));
  }
  L00763012: { // 0x763012: 668baeee000000 MOV BP,word ptr [ESI + 0xee]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.si+0x000000eeu))) & 0xffffu);
  }
  L00763019: { // 0x763019: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076301d: { // 0x76301d: 8a8680000000 MOV AL,byte ptr [ESI + 0x80]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000080u)));
  }
  L00763023: { // 0x763023: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00763025: { // 0x763025: 741e JZ 0x00763045
    if(integer::condition("JZ",flags)) goto L00763045;
  }
  L00763027: { // 0x763027: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763029: { // 0x763029: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076302b: { // 0x76302b: 668b86fa000000 MOV AX,word ptr [ESI + 0xfa]
    s.ax = with_ax(s.ax, m.r16((s.si+0x000000fau)));
  }
  L00763032: { // 0x763032: 668b8efc000000 MOV CX,word ptr [ESI + 0xfc]
    s.cx = with_ax(s.cx, m.r16((s.si+0x000000fcu)));
  }
  L00763039: { // 0x763039: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L0076303b: { // 0x76303b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076303f: { // 0x76303f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00763041: { // 0x763041: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00763045: { // 0x763045: 8a8680000000 MOV AL,byte ptr [ESI + 0x80]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000080u)));
  }
  L0076304b: { // 0x76304b: 8b5e5c MOV EBX,dword ptr [ESI + 0x5c]
    s.bx = m.r32((s.si+0x0000005cu));
  }
  L0076304e: { // 0x76304e: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00763050: { // 0x763050: 0f8489000000 JZ 0x007630df
    if(integer::condition("JZ",flags)) goto L007630df;
  }
  L00763056: { // 0x763056: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00763058: { // 0x763058: 0f8585000000 JNZ 0x007630e3
    if(integer::condition("JNZ",flags)) goto L007630e3;
  }
  L0076305e: { // 0x76305e: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00763062: { // 0x763062: 8a8608010000 MOV AL,byte ptr [ESI + 0x108]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000108u)));
  }
  L00763068: { // 0x763068: 0faffd IMUL EDI,EBP
    s.di = integer::imul(s.di,s.bp,32,flags);
  }
  L0076306b: { // 0x76306b: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L0076306d: { // 0x76306d: 7404 JZ 0x00763073
    if(integer::condition("JZ",flags)) goto L00763073;
  }
  L0076306f: { // 0x76306f: 3c04 CMP AL,0x4
    (void)integer::sub((s.ax & 0xffu),0x00000004u,8,flags);
  }
  L00763071: { // 0x763071: 7502 JNZ 0x00763075
    if(integer::condition("JNZ",flags)) goto L00763075;
  }
  L00763073: { // 0x763073: 03ff ADD EDI,EDI
    s.di = integer::add(s.di,s.di,32,flags);
  }
  L00763075: { // 0x763075: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763076: { // 0x763076: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00763078: { // 0x763078: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0076307a: { // 0x76307a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076307b: { // 0x76307b: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7745662u); flags=s.arithmetic_flags;
  }
  L0076307e: { // 0x76307e: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00763080: { // 0x763080: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00763083: { // 0x763083: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00763085: { // 0x763085: 750b JNZ 0x00763092
    if(integer::condition("JNZ",flags)) goto L00763092;
  }
  L00763087: { // 0x763087: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763088: { // 0x763088: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763089: { // 0x763089: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076308a: { // 0x76308a: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L0076308f: { // 0x76308f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763090: { // 0x763090: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00763091: { // 0x763091: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763092: { // 0x763092: 8b5630 MOV EDX,dword ptr [ESI + 0x30]
    s.dx = m.r32((s.si+0x00000030u));
  }
  L00763095: { // 0x763095: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763096: { // 0x763096: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763097: { // 0x763097: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L00763099: { // 0x763099: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0076309b: { // 0x76309b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076309c: { // 0x76309c: 895630 MOV dword ptr [ESI + 0x30],EDX
    m.w32((s.si+0x00000030u), s.dx);
  }
  L0076309f: { // 0x76309f: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7745698u); flags=s.arithmetic_flags;
  }
  L007630a2: { // 0x7630a2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L007630a4: { // 0x7630a4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007630a6: { // 0x7630a6: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007630a8: { // 0x7630a8: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L007630aa: { // 0x7630aa: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L007630ad: { // 0x7630ad: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L007630af: { // 0x7630af: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L007630b1: { // 0x7630b1: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007630b4: { // 0x7630b4: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L007630b7: { // 0x7630b7: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L007630b9: { // 0x7630b9: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L007630bd: { // 0x7630bd: 899e58010000 MOV dword ptr [ESI + 0x158],EBX
    m.w32((s.si+0x00000158u), s.bx);
  }
  L007630c3: { // 0x7630c3: 898660010000 MOV dword ptr [ESI + 0x160],EAX
    m.w32((s.si+0x00000160u), s.ax);
  }
  L007630c9: { // 0x7630c9: 8b8650010000 MOV EAX,dword ptr [ESI + 0x150]
    s.ax = m.r32((s.si+0x00000150u));
  }
  L007630cf: { // 0x7630cf: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  L007630d1: { // 0x7630d1: 89ae5c010000 MOV dword ptr [ESI + 0x15c],EBP
    m.w32((s.si+0x0000015cu), s.bp);
  }
  L007630d7: { // 0x7630d7: 898650010000 MOV dword ptr [ESI + 0x150],EAX
    m.w32((s.si+0x00000150u), s.ax);
  }
  L007630dd: { // 0x7630dd: eb04 JMP 0x007630e3
    goto L007630e3;
  }
  L007630df: { // 0x7630df: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L007630e1: { // 0x7630e1: 742e JZ 0x00763111
    if(integer::condition("JZ",flags)) goto L00763111;
  }
  L007630e3: { // 0x7630e3: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L007630e6: { // 0x7630e6: 8b5668 MOV EDX,dword ptr [ESI + 0x68]
    s.dx = m.r32((s.si+0x00000068u));
  }
  L007630e9: { // 0x7630e9: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L007630ed: { // 0x7630ed: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007630ee: { // 0x7630ee: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007630ef: { // 0x7630ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007630f0: { // 0x7630f0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007630f1: { // 0x7630f1: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L007630f3: { // 0x7630f3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007630f5: { // 0x7630f5: e8c64c0000 CALL 0x00767dc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00767dc0u,7745786u); flags=s.arithmetic_flags;
  }
  L007630fa: { // 0x7630fa: 8b8650010000 MOV EAX,dword ptr [ESI + 0x150]
    s.ax = m.r32((s.si+0x00000150u));
  }
  L00763100: { // 0x763100: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00763102: { // 0x763102: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763103: { // 0x763103: 898650010000 MOV dword ptr [ESI + 0x150],EAX
    m.w32((s.si+0x00000150u), s.ax);
  }
  L00763109: { // 0x763109: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076310a: { // 0x76310a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076310b: { // 0x76310b: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076310e: { // 0x76310e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076310f: { // 0x76310f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00763110: { // 0x763110: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763111: { // 0x763111: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763112: { // 0x763112: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763113: { // 0x763113: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00763114: { // 0x763114: b8f7ffffff MOV EAX,0xfffffff7
    s.ax = 0xfffffff7u;
  }
  L00763119: { // 0x763119: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076311a: { // 0x76311a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076311b: { // 0x76311b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00765ca0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00765ca0: { // 0x765ca0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00765ca3: { // 0x765ca3: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L00765ca7: { // 0x765ca7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765ca8: { // 0x765ca8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765ca9: { // 0x765ca9: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00765cab: { // 0x765cab: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00765cad: { // 0x765cad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765cae: { // 0x765cae: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765cb0: { // 0x765cb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765cb1: { // 0x765cb1: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7756980u); flags=s.arithmetic_flags;
  }
  L00765cb4: { // 0x765cb4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765cb7: { // 0x765cb7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765cb9: { // 0x765cb9: 740b JZ 0x00765cc6
    if(integer::condition("JZ",flags)) goto L00765cc6;
  }
  L00765cbb: { // 0x765cbb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765cbc: { // 0x765cbc: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00765cc1: { // 0x765cc1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765cc2: { // 0x765cc2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765cc5: { // 0x765cc5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765cc6: { // 0x765cc6: 817c24084c494e48 CMP dword ptr [ESP + 0x8],0x484e494c
    (void)integer::sub(m.r32((f.sp+0x00000008u)),0x484e494cu,32,flags);
  }
  L00765cce: { // 0x765cce: 740b JZ 0x00765cdb
    if(integer::condition("JZ",flags)) goto L00765cdb;
  }
  L00765cd0: { // 0x765cd0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765cd1: { // 0x765cd1: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765cd6: { // 0x765cd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765cd7: { // 0x765cd7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765cda: { // 0x765cda: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765cdb: { // 0x765cdb: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00765cdf: { // 0x765cdf: 8dbe14070000 LEA EDI,[ESI + 0x714]
    s.di = (s.si+0x00000714u);
  }
  L00765ce5: { // 0x765ce5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00765ce7: { // 0x765ce7: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765ce9: { // 0x765ce9: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L00765cee: { // 0x765cee: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00765cf1: { // 0x765cf1: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765cf3: { // 0x765cf3: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765cf5: { // 0x765cf5: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L00765cfb: { // 0x765cfb: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00765cfe: { // 0x765cfe: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L00765d00: { // 0x765d00: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00765d03: { // 0x765d03: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00765d06: { // 0x765d06: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765d08: { // 0x765d08: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00765d09: { // 0x765d09: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765d0b: { // 0x765d0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765d0c: { // 0x765d0c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765d0d: { // 0x765d0d: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765d0f: { // 0x765d0f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765d10: { // 0x765d10: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757075u); flags=s.arithmetic_flags;
  }
  L00765d13: { // 0x765d13: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765d16: { // 0x765d16: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765d18: { // 0x765d18: 740b JZ 0x00765d25
    if(integer::condition("JZ",flags)) goto L00765d25;
  }
  L00765d1a: { // 0x765d1a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765d1b: { // 0x765d1b: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765d20: { // 0x765d20: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765d21: { // 0x765d21: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765d24: { // 0x765d24: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765d25: { // 0x765d25: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00765d28: { // 0x765d28: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L00765d2b: { // 0x765d2b: 0f86b9000000 JBE 0x00765dea
    if(integer::condition("JBE",flags)) goto L00765dea;
  }
  L00765d31: { // 0x765d31: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00765d36: { // 0x765d36: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00765d39: { // 0x765d39: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00765d3b: { // 0x765d3b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765d3c: { // 0x765d3c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00765d3e: { // 0x765d3e: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00765d40: { // 0x765d40: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765d41: { // 0x765d41: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757124u); flags=s.arithmetic_flags;
  }
  L00765d44: { // 0x765d44: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765d47: { // 0x765d47: 89861c070000 MOV dword ptr [ESI + 0x71c],EAX
    m.w32((s.si+0x0000071cu), s.ax);
  }
  L00765d4d: { // 0x765d4d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765d4f: { // 0x765d4f: 750b JNZ 0x00765d5c
    if(integer::condition("JNZ",flags)) goto L00765d5c;
  }
  L00765d51: { // 0x765d51: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765d52: { // 0x765d52: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L00765d57: { // 0x765d57: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765d58: { // 0x765d58: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765d5b: { // 0x765d5b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765d5c: { // 0x765d5c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765d5d: { // 0x765d5d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765d5e: { // 0x765d5e: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00765d60: { // 0x765d60: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765d61: { // 0x765d61: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757156u); flags=s.arithmetic_flags;
  }
  L00765d64: { // 0x765d64: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L00765d67: { // 0x765d67: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00765d69: { // 0x765d69: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00765d6b: { // 0x765d6b: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L00765d6e: { // 0x765d6e: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00765d72: { // 0x765d72: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765d73: { // 0x765d73: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765d75: { // 0x765d75: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765d76: { // 0x765d76: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757177u); flags=s.arithmetic_flags;
  }
  L00765d79: { // 0x765d79: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00765d7c: { // 0x765d7c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765d7e: { // 0x765d7e: 740b JZ 0x00765d8b
    if(integer::condition("JZ",flags)) goto L00765d8b;
  }
  L00765d80: { // 0x765d80: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765d81: { // 0x765d81: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00765d86: { // 0x765d86: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765d87: { // 0x765d87: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765d8a: { // 0x765d8a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765d8b: { // 0x765d8b: 817c24084c494e44 CMP dword ptr [ESP + 0x8],0x444e494c
    (void)integer::sub(m.r32((f.sp+0x00000008u)),0x444e494cu,32,flags);
  }
  L00765d93: { // 0x765d93: 740b JZ 0x00765da0
    if(integer::condition("JZ",flags)) goto L00765da0;
  }
  L00765d95: { // 0x765d95: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765d96: { // 0x765d96: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765d9b: { // 0x765d9b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765d9c: { // 0x765d9c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765d9f: { // 0x765d9f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765da0: { // 0x765da0: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00765da4: { // 0x765da4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00765da6: { // 0x765da6: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765da8: { // 0x765da8: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L00765dad: { // 0x765dad: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00765db0: { // 0x765db0: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765db2: { // 0x765db2: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765db4: { // 0x765db4: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L00765dba: { // 0x765dba: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00765dbd: { // 0x765dbd: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L00765dbf: { // 0x765dbf: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00765dc2: { // 0x765dc2: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00765dc5: { // 0x765dc5: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765dc7: { // 0x765dc7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00765dc8: { // 0x765dc8: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765dca: { // 0x765dca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765dcb: { // 0x765dcb: 8b861c070000 MOV EAX,dword ptr [ESI + 0x71c]
    s.ax = m.r32((s.si+0x0000071cu));
  }
  L00765dd1: { // 0x765dd1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765dd2: { // 0x765dd2: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765dd4: { // 0x765dd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765dd5: { // 0x765dd5: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757272u); flags=s.arithmetic_flags;
  }
  L00765dd8: { // 0x765dd8: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765ddb: { // 0x765ddb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765ddd: { // 0x765ddd: 740b JZ 0x00765dea
    if(integer::condition("JZ",flags)) goto L00765dea;
  }
  L00765ddf: { // 0x765ddf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765de0: { // 0x765de0: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765de5: { // 0x765de5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765de6: { // 0x765de6: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765de9: { // 0x765de9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765dea: { // 0x765dea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765deb: { // 0x765deb: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00765dee: { // 0x765dee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765def: { // 0x765def: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00765df2: { // 0x765df2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_007665c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007665c0: { // 0x7665c0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L007665c3: { // 0x7665c3: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L007665c7: { // 0x7665c7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007665c8: { // 0x7665c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007665c9: { // 0x7665c9: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L007665cb: { // 0x7665cb: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L007665cd: { // 0x7665cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007665ce: { // 0x7665ce: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007665d0: { // 0x7665d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007665d1: { // 0x7665d1: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759316u); flags=s.arithmetic_flags;
  }
  L007665d4: { // 0x7665d4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007665d7: { // 0x7665d7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007665d9: { // 0x7665d9: 740b JZ 0x007665e6
    if(integer::condition("JZ",flags)) goto L007665e6;
  }
  L007665db: { // 0x7665db: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007665dc: { // 0x7665dc: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L007665e1: { // 0x7665e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007665e2: { // 0x7665e2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007665e5: { // 0x7665e5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007665e6: { // 0x7665e6: 817c240843494e48 CMP dword ptr [ESP + 0x8],0x484e4943
    (void)integer::sub(m.r32((f.sp+0x00000008u)),0x484e4943u,32,flags);
  }
  L007665ee: { // 0x7665ee: 740b JZ 0x007665fb
    if(integer::condition("JZ",flags)) goto L007665fb;
  }
  L007665f0: { // 0x7665f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007665f1: { // 0x7665f1: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007665f6: { // 0x7665f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007665f7: { // 0x7665f7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007665fa: { // 0x7665fa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007665fb: { // 0x7665fb: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L007665ff: { // 0x7665ff: 8dbe4c070000 LEA EDI,[ESI + 0x74c]
    s.di = (s.si+0x0000074cu);
  }
  L00766605: { // 0x766605: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00766607: { // 0x766607: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766609: { // 0x766609: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L0076660e: { // 0x76660e: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00766611: { // 0x766611: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00766613: { // 0x766613: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766615: { // 0x766615: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L0076661b: { // 0x76661b: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L0076661e: { // 0x76661e: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L00766620: { // 0x766620: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00766623: { // 0x766623: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00766626: { // 0x766626: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00766628: { // 0x766628: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00766629: { // 0x766629: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L0076662b: { // 0x76662b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076662c: { // 0x76662c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076662d: { // 0x76662d: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0076662f: { // 0x76662f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766630: { // 0x766630: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759411u); flags=s.arithmetic_flags;
  }
  L00766633: { // 0x766633: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766636: { // 0x766636: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766638: { // 0x766638: 740b JZ 0x00766645
    if(integer::condition("JZ",flags)) goto L00766645;
  }
  L0076663a: { // 0x76663a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076663b: { // 0x76663b: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766640: { // 0x766640: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766641: { // 0x766641: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766644: { // 0x766644: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766645: { // 0x766645: 8a86f5000000 MOV AL,byte ptr [ESI + 0xf5]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000f5u)));
  }
  L0076664b: { // 0x76664b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076664d: { // 0x76664d: 0f85c5000000 JNZ 0x00766718
    if(integer::condition("JNZ",flags)) goto L00766718;
  }
  L00766653: { // 0x766653: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00766656: { // 0x766656: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L00766659: { // 0x766659: 0f86b9000000 JBE 0x00766718
    if(integer::condition("JBE",flags)) goto L00766718;
  }
  L0076665f: { // 0x76665f: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00766664: { // 0x766664: 8d3c40 LEA EDI,[EAX + EAX*0x2]
    s.di = (s.ax+(s.ax * 0x00000002u));
  }
  L00766667: { // 0x766667: d1e7 SHL EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::left);
  }
  L00766669: { // 0x766669: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076666a: { // 0x76666a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0076666c: { // 0x76666c: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0076666e: { // 0x76666e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076666f: { // 0x76666f: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7759474u); flags=s.arithmetic_flags;
  }
  L00766672: { // 0x766672: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766675: { // 0x766675: 898654070000 MOV dword ptr [ESI + 0x754],EAX
    m.w32((s.si+0x00000754u), s.ax);
  }
  L0076667b: { // 0x76667b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076667d: { // 0x76667d: 750b JNZ 0x0076668a
    if(integer::condition("JNZ",flags)) goto L0076668a;
  }
  L0076667f: { // 0x76667f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766680: { // 0x766680: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L00766685: { // 0x766685: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766686: { // 0x766686: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766689: { // 0x766689: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076668a: { // 0x76668a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076668b: { // 0x76668b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076668c: { // 0x76668c: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0076668e: { // 0x76668e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076668f: { // 0x76668f: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7759506u); flags=s.arithmetic_flags;
  }
  L00766692: { // 0x766692: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L00766695: { // 0x766695: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00766697: { // 0x766697: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00766699: { // 0x766699: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L0076669c: { // 0x76669c: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L007666a0: { // 0x7666a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007666a1: { // 0x7666a1: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007666a3: { // 0x7666a3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007666a4: { // 0x7666a4: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759527u); flags=s.arithmetic_flags;
  }
  L007666a7: { // 0x7666a7: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007666aa: { // 0x7666aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007666ac: { // 0x7666ac: 740b JZ 0x007666b9
    if(integer::condition("JZ",flags)) goto L007666b9;
  }
  L007666ae: { // 0x7666ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007666af: { // 0x7666af: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L007666b4: { // 0x7666b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007666b5: { // 0x7666b5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007666b8: { // 0x7666b8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007666b9: { // 0x7666b9: 817c240843494e44 CMP dword ptr [ESP + 0x8],0x444e4943
    (void)integer::sub(m.r32((f.sp+0x00000008u)),0x444e4943u,32,flags);
  }
  L007666c1: { // 0x7666c1: 740b JZ 0x007666ce
    if(integer::condition("JZ",flags)) goto L007666ce;
  }
  L007666c3: { // 0x7666c3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007666c4: { // 0x7666c4: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007666c9: { // 0x7666c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007666ca: { // 0x7666ca: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007666cd: { // 0x7666cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007666ce: { // 0x7666ce: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L007666d2: { // 0x7666d2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L007666d4: { // 0x7666d4: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007666d6: { // 0x7666d6: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L007666db: { // 0x7666db: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L007666de: { // 0x7666de: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L007666e0: { // 0x7666e0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007666e2: { // 0x7666e2: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L007666e8: { // 0x7666e8: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L007666eb: { // 0x7666eb: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L007666ed: { // 0x7666ed: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L007666f0: { // 0x7666f0: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L007666f3: { // 0x7666f3: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L007666f5: { // 0x7666f5: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L007666f6: { // 0x7666f6: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007666f8: { // 0x7666f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007666f9: { // 0x7666f9: 8b8654070000 MOV EAX,dword ptr [ESI + 0x754]
    s.ax = m.r32((s.si+0x00000754u));
  }
  L007666ff: { // 0x7666ff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766700: { // 0x766700: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766702: { // 0x766702: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766703: { // 0x766703: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759622u); flags=s.arithmetic_flags;
  }
  L00766706: { // 0x766706: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766709: { // 0x766709: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076670b: { // 0x76670b: 740b JZ 0x00766718
    if(integer::condition("JZ",flags)) goto L00766718;
  }
  L0076670d: { // 0x76670d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076670e: { // 0x76670e: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766713: { // 0x766713: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766714: { // 0x766714: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766717: { // 0x766717: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766718: { // 0x766718: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766719: { // 0x766719: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076671c: { // 0x76671c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076671d: { // 0x76671d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766720: { // 0x766720: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00766730(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766730: { // 0x766730: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00766733: { // 0x766733: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L00766737: { // 0x766737: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766738: { // 0x766738: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766739: { // 0x766739: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0076673b: { // 0x76673b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0076673d: { // 0x76673d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076673e: { // 0x76673e: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766740: { // 0x766740: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766741: { // 0x766741: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759684u); flags=s.arithmetic_flags;
  }
  L00766744: { // 0x766744: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766747: { // 0x766747: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766749: { // 0x766749: 740b JZ 0x00766756
    if(integer::condition("JZ",flags)) goto L00766756;
  }
  L0076674b: { // 0x76674b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076674c: { // 0x76674c: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00766751: { // 0x766751: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766752: { // 0x766752: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766755: { // 0x766755: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766756: { // 0x766756: 817c240850494e48 CMP dword ptr [ESP + 0x8],0x484e4950
    (void)integer::sub(m.r32((f.sp+0x00000008u)),0x484e4950u,32,flags);
  }
  L0076675e: { // 0x76675e: 740b JZ 0x0076676b
    if(integer::condition("JZ",flags)) goto L0076676b;
  }
  L00766760: { // 0x766760: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766761: { // 0x766761: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766766: { // 0x766766: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766767: { // 0x766767: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0076676a: { // 0x76676a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076676b: { // 0x76676b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0076676f: { // 0x76676f: 8dbe58070000 LEA EDI,[ESI + 0x758]
    s.di = (s.si+0x00000758u);
  }
  L00766775: { // 0x766775: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00766777: { // 0x766777: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766779: { // 0x766779: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L0076677e: { // 0x76677e: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00766781: { // 0x766781: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00766783: { // 0x766783: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766785: { // 0x766785: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L0076678b: { // 0x76678b: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L0076678e: { // 0x76678e: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L00766790: { // 0x766790: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00766793: { // 0x766793: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00766796: { // 0x766796: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00766798: { // 0x766798: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00766799: { // 0x766799: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L0076679b: { // 0x76679b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076679c: { // 0x76679c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076679d: { // 0x76679d: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0076679f: { // 0x76679f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007667a0: { // 0x7667a0: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759779u); flags=s.arithmetic_flags;
  }
  L007667a3: { // 0x7667a3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007667a6: { // 0x7667a6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007667a8: { // 0x7667a8: 740b JZ 0x007667b5
    if(integer::condition("JZ",flags)) goto L007667b5;
  }
  L007667aa: { // 0x7667aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007667ab: { // 0x7667ab: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007667b0: { // 0x7667b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007667b1: { // 0x7667b1: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007667b4: { // 0x7667b4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007667b5: { // 0x7667b5: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L007667b8: { // 0x7667b8: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L007667bb: { // 0x7667bb: 0f86b8000000 JBE 0x00766879
    if(integer::condition("JBE",flags)) goto L00766879;
  }
  L007667c1: { // 0x7667c1: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L007667c6: { // 0x7667c6: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L007667c8: { // 0x7667c8: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L007667ca: { // 0x7667ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007667cb: { // 0x7667cb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007667cd: { // 0x7667cd: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L007667cf: { // 0x7667cf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007667d0: { // 0x7667d0: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7759827u); flags=s.arithmetic_flags;
  }
  L007667d3: { // 0x7667d3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007667d6: { // 0x7667d6: 898660070000 MOV dword ptr [ESI + 0x760],EAX
    m.w32((s.si+0x00000760u), s.ax);
  }
  L007667dc: { // 0x7667dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007667de: { // 0x7667de: 750b JNZ 0x007667eb
    if(integer::condition("JNZ",flags)) goto L007667eb;
  }
  L007667e0: { // 0x7667e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007667e1: { // 0x7667e1: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L007667e6: { // 0x7667e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007667e7: { // 0x7667e7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007667ea: { // 0x7667ea: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007667eb: { // 0x7667eb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007667ec: { // 0x7667ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007667ed: { // 0x7667ed: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L007667ef: { // 0x7667ef: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007667f0: { // 0x7667f0: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7759859u); flags=s.arithmetic_flags;
  }
  L007667f3: { // 0x7667f3: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L007667f6: { // 0x7667f6: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L007667f8: { // 0x7667f8: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L007667fa: { // 0x7667fa: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L007667fd: { // 0x7667fd: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00766801: { // 0x766801: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766802: { // 0x766802: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766804: { // 0x766804: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766805: { // 0x766805: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759880u); flags=s.arithmetic_flags;
  }
  L00766808: { // 0x766808: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0076680b: { // 0x76680b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076680d: { // 0x76680d: 740b JZ 0x0076681a
    if(integer::condition("JZ",flags)) goto L0076681a;
  }
  L0076680f: { // 0x76680f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766810: { // 0x766810: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00766815: { // 0x766815: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766816: { // 0x766816: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766819: { // 0x766819: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076681a: { // 0x76681a: 817c240850494e44 CMP dword ptr [ESP + 0x8],0x444e4950
    (void)integer::sub(m.r32((f.sp+0x00000008u)),0x444e4950u,32,flags);
  }
  L00766822: { // 0x766822: 740b JZ 0x0076682f
    if(integer::condition("JZ",flags)) goto L0076682f;
  }
  L00766824: { // 0x766824: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766825: { // 0x766825: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L0076682a: { // 0x76682a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076682b: { // 0x76682b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0076682e: { // 0x76682e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076682f: { // 0x76682f: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00766833: { // 0x766833: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00766835: { // 0x766835: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766837: { // 0x766837: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L0076683c: { // 0x76683c: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L0076683f: { // 0x76683f: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00766841: { // 0x766841: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766843: { // 0x766843: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L00766849: { // 0x766849: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L0076684c: { // 0x76684c: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L0076684e: { // 0x76684e: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00766851: { // 0x766851: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00766854: { // 0x766854: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00766856: { // 0x766856: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00766857: { // 0x766857: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00766859: { // 0x766859: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076685a: { // 0x76685a: 8b8660070000 MOV EAX,dword ptr [ESI + 0x760]
    s.ax = m.r32((s.si+0x00000760u));
  }
  L00766860: { // 0x766860: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766861: { // 0x766861: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766863: { // 0x766863: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766864: { // 0x766864: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7759975u); flags=s.arithmetic_flags;
  }
  L00766867: { // 0x766867: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076686a: { // 0x76686a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076686c: { // 0x76686c: 740b JZ 0x00766879
    if(integer::condition("JZ",flags)) goto L00766879;
  }
  L0076686e: { // 0x76686e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076686f: { // 0x76686f: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766874: { // 0x766874: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766875: { // 0x766875: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766878: { // 0x766878: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766879: { // 0x766879: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076687a: { // 0x76687a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076687d: { // 0x76687d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076687e: { // 0x76687e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00766881: { // 0x766881: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
