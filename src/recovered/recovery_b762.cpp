#include "recovered/recovery_b762_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b762 {
namespace {
void f_0037be00(Memory&,State&,Frame&,const Operations&);
void f_0037be5c(Memory&,State&,Frame&,const Operations&);
void f_0037bd89(Memory&,State&,Frame&,const Operations&);
void f_0037295e(Memory&,State&,Frame&,const Operations&);
void f_00372847(Memory&,State&,Frame&,const Operations&);
void f_00372ae9(Memory&,State&,Frame&,const Operations&);
void f_00379010(Memory&,State&,Frame&,const Operations&);
void f_00375160(Memory&,State&,Frame&,const Operations&);
void f_0036ebd0(Memory&,State&,Frame&,const Operations&);
void f_0037b620(Memory&,State&,Frame&,const Operations&);
void f_00380c48(Memory&,State&,Frame&,const Operations&);
void f_00380a28(Memory&,State&,Frame&,const Operations&);
void f_0038040e(Memory&,State&,Frame&,const Operations&);
void f_0038048d(Memory&,State&,Frame&,const Operations&);
void f_003804bb(Memory&,State&,Frame&,const Operations&);
void f_0038042f(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_003805af(Memory&,State&,Frame&,const Operations&);

void f_0037be00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077be00: { // 0x77be00: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077be01: { // 0x77be01: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077be03: { // 0x77be03: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L0077be06: { // 0x77be06: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077be07: { // 0x77be07: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  L0077be0a: { // 0x77be0a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077be0b: { // 0x77be0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077be0c: { // 0x77be0c: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  L0077be0f: { // 0x77be0f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077be10: { // 0x77be10: e847000000 CALL 0x0077be5c
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077be5cu,7847445u); flags=s.arithmetic_flags;
  }
  L0077be15: { // 0x77be15: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077be16: { // 0x77be16: 8d45d8 LEA EAX,[EBP + -0x28]
    s.ax = (s.bp-0x00000028u);
  }
  L0077be19: { // 0x77be19: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077be1a: { // 0x77be1a: 8d75f4 LEA ESI,[EBP + -0xc]
    s.si = (s.bp-0x0000000cu);
  }
  L0077be1d: { // 0x77be1d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077be1e: { // 0x77be1e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0077be20: { // 0x77be20: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  L0077be22: { // 0x77be22: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0077be25: { // 0x77be25: 8bfc MOV EDI,ESP
    s.di = f.sp;
  }
  L0077be27: { // 0x77be27: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L0077be28: { // 0x77be28: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L0077be29: { // 0x77be29: 66a5 MOVSW ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,16u,Repeat::single);
  }
  L0077be2b: { // 0x77be2b: e87f470000 CALL 0x007805af
    s.arithmetic_flags=flags; invoke(m,s,f,0x007805afu,7847472u); flags=s.arithmetic_flags;
  }
  L0077be30: { // 0x77be30: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  L0077be33: { // 0x77be33: 8b7d14 MOV EDI,dword ptr [EBP + 0x14]
    s.di = m.r32((s.bp+0x00000014u));
  }
  L0077be36: { // 0x77be36: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0077be39: { // 0x77be39: 0fbe45da MOVSX EAX,byte ptr [EBP + -0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp-0x00000026u)),8));
  }
  L0077be3d: { // 0x77be3d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0077be3f: { // 0x77be3f: 0fbf45d8 MOVSX EAX,word ptr [EBP + -0x28]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp-0x00000028u)),16));
  }
  L0077be43: { // 0x77be43: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0077be46: { // 0x77be46: 8d45dc LEA EAX,[EBP + -0x24]
    s.ax = (s.bp-0x00000024u);
  }
  L0077be49: { // 0x77be49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077be4a: { // 0x77be4a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077be4b: { // 0x77be4b: e8c0d1ffff CALL 0x00779010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00779010u,7847504u); flags=s.arithmetic_flags;
  }
  L0077be50: { // 0x77be50: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0077be53: { // 0x77be53: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0077be56: { // 0x77be56: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0077be58: { // 0x77be58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077be59: { // 0x77be59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077be5a: { // 0x77be5a: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077be5b: { // 0x77be5b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037be5c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077be5c: { // 0x77be5c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077be5d: { // 0x77be5d: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077be5f: { // 0x77be5f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077be60: { // 0x77be60: 8b550c MOV EDX,dword ptr [EBP + 0xc]
    s.dx = m.r32((s.bp+0x0000000cu));
  }
  L0077be63: { // 0x77be63: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077be64: { // 0x77be64: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077be65: { // 0x77be65: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077be66: { // 0x77be66: 668b4206 MOV AX,word ptr [EDX + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.dx+0x00000006u)));
  }
  L0077be6a: { // 0x77be6a: bfff070000 MOV EDI,0x7ff
    s.di = 0x000007ffu;
  }
  L0077be6f: { // 0x77be6f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0077be71: { // 0x77be71: 2500800000 AND EAX,0x8000
    s.ax = integer::logical((s.ax)&(0x00008000u),32,flags);
  }
  L0077be76: { // 0x77be76: c1e904 SHR ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::right);
  }
  L0077be79: { // 0x77be79: 23cf AND ECX,EDI
    s.cx = integer::logical((s.cx)&(s.di),32,flags);
  }
  L0077be7b: { // 0x77be7b: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L0077be7e: { // 0x77be7e: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0077be81: { // 0x77be81: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0077be83: { // 0x77be83: 0fb7d9 MOVZX EBX,CX
    s.bx = ((s.cx & 0xffffu)&integer::mask(16));
  }
  L0077be86: { // 0x77be86: be00000080 MOV ESI,0x80000000
    s.si = 0x80000000u;
  }
  L0077be8b: { // 0x77be8b: 25ffff0f00 AND EAX,0xfffff
    s.ax = integer::logical((s.ax)&(0x000fffffu),32,flags);
  }
  L0077be90: { // 0x77be90: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0077be92: { // 0x77be92: 8975fc MOV dword ptr [EBP + -0x4],ESI
    m.w32((s.bp-0x00000004u), s.si);
  }
  L0077be95: { // 0x77be95: 7413 JZ 0x0077beaa
    if(integer::condition("JZ",flags)) goto L0077beaa;
  }
  L0077be97: { // 0x77be97: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0077be99: { // 0x77be99: 7408 JZ 0x0077bea3
    if(integer::condition("JZ",flags)) goto L0077bea3;
  }
  L0077be9b: { // 0x77be9b: 8db9003c0000 LEA EDI,[ECX + 0x3c00]
    s.di = (s.cx+0x00003c00u);
  }
  L0077bea1: { // 0x77bea1: eb28 JMP 0x0077becb
    goto L0077becb;
  }
  L0077bea3: { // 0x77bea3: bfff7f0000 MOV EDI,0x7fff
    s.di = 0x00007fffu;
  }
  L0077bea8: { // 0x77bea8: eb21 JMP 0x0077becb
    goto L0077becb;
  }
  L0077beaa: { // 0x77beaa: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077beac: { // 0x77beac: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0077beae: { // 0x77beae: 7512 JNZ 0x0077bec2
    if(integer::condition("JNZ",flags)) goto L0077bec2;
  }
  L0077beb0: { // 0x77beb0: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0077beb2: { // 0x77beb2: 750e JNZ 0x0077bec2
    if(integer::condition("JNZ",flags)) goto L0077bec2;
  }
  L0077beb4: { // 0x77beb4: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0077beb7: { // 0x77beb7: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L0077beba: { // 0x77beba: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L0077bebc: { // 0x77bebc: 66895808 MOV word ptr [EAX + 0x8],BX
    m.w16((s.ax+0x00000008u), (s.bx & 0xffffu));
  }
  L0077bec0: { // 0x77bec0: eb4b JMP 0x0077bf0d
    goto L0077bf0d;
  }
  L0077bec2: { // 0x77bec2: 8db9013c0000 LEA EDI,[ECX + 0x3c01]
    s.di = (s.cx+0x00003c01u);
  }
  L0077bec8: { // 0x77bec8: 895dfc MOV dword ptr [EBP + -0x4],EBX
    m.w32((s.bp-0x00000004u), s.bx);
  }
  L0077becb: { // 0x77becb: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0077becd: { // 0x77becd: c1e915 SHR ECX,0x15
    s.cx = integer::shift(s.cx,0x00000015u,32,flags,integer::Shift::right);
  }
  L0077bed0: { // 0x77bed0: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  L0077bed3: { // 0x77bed3: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  L0077bed5: { // 0x77bed5: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0077bed8: { // 0x77bed8: 0b4dfc OR ECX,dword ptr [EBP + -0x4]
    s.cx = integer::logical((s.cx)|(m.r32((s.bp-0x00000004u))),32,flags);
  }
  L0077bedb: { // 0x77bedb: c1e20b SHL EDX,0xb
    s.dx = integer::shift(s.dx,0x0000000bu,32,flags,integer::Shift::left);
  }
  L0077bede: { // 0x77bede: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0077bee1: { // 0x77bee1: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0077bee3: { // 0x77bee3: 85ce TEST ESI,ECX
    (void)integer::logical((s.si)&(s.cx),32,flags);
  }
  L0077bee5: { // 0x77bee5: 751d JNZ 0x0077bf04
    if(integer::condition("JNZ",flags)) goto L0077bf04;
  }
  L0077bee7: { // 0x77bee7: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0077bee9: { // 0x77bee9: 03c9 ADD ECX,ECX
    s.cx = integer::add(s.cx,s.cx,32,flags);
  }
  L0077beeb: { // 0x77beeb: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0077beed: { // 0x77beed: c1eb1f SHR EBX,0x1f
    s.bx = integer::shift(s.bx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0077bef0: { // 0x77bef0: 0bd9 OR EBX,ECX
    s.bx = integer::logical((s.bx)|(s.cx),32,flags);
  }
  L0077bef2: { // 0x77bef2: 8d0c12 LEA ECX,[EDX + EDX*0x1]
    s.cx = (s.dx+(s.dx * 0x00000001u));
  }
  L0077bef5: { // 0x77bef5: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0077bef7: { // 0x77bef7: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L0077befa: { // 0x77befa: 81c7ffff0000 ADD EDI,0xffff
    s.di = integer::add(s.di,0x0000ffffu,32,flags);
  }
  L0077bf00: { // 0x77bf00: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0077bf02: { // 0x77bf02: ebdf JMP 0x0077bee3
    goto L0077bee3;
  }
  L0077bf04: { // 0x77bf04: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0077bf07: { // 0x77bf07: 0bcf OR ECX,EDI
    s.cx = integer::logical((s.cx)|(s.di),32,flags);
  }
  L0077bf09: { // 0x77bf09: 66894808 MOV word ptr [EAX + 0x8],CX
    m.w16((s.ax+0x00000008u), (s.cx & 0xffffu));
  }
  L0077bf0d: { // 0x77bf0d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077bf0e: { // 0x77bf0e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077bf0f: { // 0x77bf0f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077bf10: { // 0x77bf10: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077bf11: { // 0x77bf11: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037bd89(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077bd89: { // 0x77bd89: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077bd8a: { // 0x77bd8a: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077bd8c: { // 0x77bd8c: 8b5510 MOV EDX,dword ptr [EBP + 0x10]
    s.dx = m.r32((s.bp+0x00000010u));
  }
  L0077bd8f: { // 0x77bd8f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077bd90: { // 0x77bd90: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L0077bd93: { // 0x77bd93: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077bd94: { // 0x77bd94: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L0077bd97: { // 0x77bd97: 8b4a0c MOV ECX,dword ptr [EDX + 0xc]
    s.cx = m.r32((s.dx+0x0000000cu));
  }
  L0077bd9a: { // 0x77bd9a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077bd9b: { // 0x77bd9b: 8d7e01 LEA EDI,[ESI + 0x1]
    s.di = (s.si+0x00000001u);
  }
  L0077bd9e: { // 0x77bd9e: c60630 MOV byte ptr [ESI],0x30
    m.w8((s.si), 0x00000030u);
  }
  L0077bda1: { // 0x77bda1: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0077bda3: { // 0x77bda3: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0077bda5: { // 0x77bda5: 7e1f JLE 0x0077bdc6
    if(integer::condition("JLE",flags)) goto L0077bdc6;
  }
  L0077bda7: { // 0x77bda7: 895d08 MOV dword ptr [EBP + 0x8],EBX
    m.w32((s.bp+0x00000008u), s.bx);
  }
  L0077bdaa: { // 0x77bdaa: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077bdac: { // 0x77bdac: 8a11 MOV DL,byte ptr [ECX]
    s.dx = with_al(s.dx, m.r8((s.cx)));
  }
  L0077bdae: { // 0x77bdae: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0077bdb0: { // 0x77bdb0: 7406 JZ 0x0077bdb8
    if(integer::condition("JZ",flags)) goto L0077bdb8;
  }
  L0077bdb2: { // 0x77bdb2: 0fbed2 MOVSX EDX,DL
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffu),8));
  }
  L0077bdb5: { // 0x77bdb5: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0077bdb6: { // 0x77bdb6: eb03 JMP 0x0077bdbb
    goto L0077bdbb;
  }
  L0077bdb8: { // 0x77bdb8: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L0077bdba: { // 0x77bdba: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  L0077bdbb: { // 0x77bdbb: 8810 MOV byte ptr [EAX],DL
    m.w8((s.ax), (s.dx & 0xffu));
  }
  L0077bdbd: { // 0x77bdbd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0077bdbe: { // 0x77bdbe: ff4d08 DEC dword ptr [EBP + 0x8]
    m.w32((s.bp+0x00000008u), integer::decrement(m.r32((s.bp+0x00000008u)),32,flags));
  }
  L0077bdc1: { // 0x77bdc1: 75e9 JNZ 0x0077bdac
    if(integer::condition("JNZ",flags)) goto L0077bdac;
  }
  L0077bdc3: { // 0x77bdc3: 8b5510 MOV EDX,dword ptr [EBP + 0x10]
    s.dx = m.r32((s.bp+0x00000010u));
  }
  L0077bdc6: { // 0x77bdc6: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  L0077bdc9: { // 0x77bdc9: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0077bdcb: { // 0x77bdcb: 7c12 JL 0x0077bddf
    if(integer::condition("JL",flags)) goto L0077bddf;
  }
  L0077bdcd: { // 0x77bdcd: 803935 CMP byte ptr [ECX],0x35
    (void)integer::sub(m.r8((s.cx)),0x00000035u,8,flags);
  }
  L0077bdd0: { // 0x77bdd0: 7c0d JL 0x0077bddf
    if(integer::condition("JL",flags)) goto L0077bddf;
  }
  L0077bdd2: { // 0x77bdd2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077bdd3: { // 0x77bdd3: 803839 CMP byte ptr [EAX],0x39
    (void)integer::sub(m.r8((s.ax)),0x00000039u,8,flags);
  }
  L0077bdd6: { // 0x77bdd6: 7505 JNZ 0x0077bddd
    if(integer::condition("JNZ",flags)) goto L0077bddd;
  }
  L0077bdd8: { // 0x77bdd8: c60030 MOV byte ptr [EAX],0x30
    m.w8((s.ax), 0x00000030u);
  }
  L0077bddb: { // 0x77bddb: ebf5 JMP 0x0077bdd2
    goto L0077bdd2;
  }
  L0077bddd: { // 0x77bddd: fe00 INC byte ptr [EAX]
    m.w8((s.ax), integer::increment(m.r8((s.ax)),8,flags));
  }
  L0077bddf: { // 0x77bddf: 803e31 CMP byte ptr [ESI],0x31
    (void)integer::sub(m.r8((s.si)),0x00000031u,8,flags);
  }
  L0077bde2: { // 0x77bde2: 7505 JNZ 0x0077bde9
    if(integer::condition("JNZ",flags)) goto L0077bde9;
  }
  L0077bde4: { // 0x77bde4: ff4204 INC dword ptr [EDX + 0x4]
    m.w32((s.dx+0x00000004u), integer::increment(m.r32((s.dx+0x00000004u)),32,flags));
  }
  L0077bde7: { // 0x77bde7: eb12 JMP 0x0077bdfb
    goto L0077bdfb;
  }
  L0077bde9: { // 0x77bde9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077bdea: { // 0x77bdea: e87193ffff CALL 0x00775160
    s.arithmetic_flags=flags; invoke(m,s,f,0x00775160u,7847407u); flags=s.arithmetic_flags;
  }
  L0077bdef: { // 0x77bdef: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0077bdf0: { // 0x77bdf0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077bdf1: { // 0x77bdf1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077bdf2: { // 0x77bdf2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077bdf3: { // 0x77bdf3: e8d82dffff CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,7847416u); flags=s.arithmetic_flags;
  }
  L0077bdf8: { // 0x77bdf8: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0077bdfb: { // 0x77bdfb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077bdfc: { // 0x77bdfc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077bdfd: { // 0x77bdfd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077bdfe: { // 0x77bdfe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0077bdff: { // 0x77bdff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037295e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077295e: { // 0x77295e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077295f: { // 0x77295f: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00772961: { // 0x772961: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00772962: { // 0x772962: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00772963: { // 0x772963: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  L00772966: { // 0x772966: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L00772969: { // 0x772969: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077296a: { // 0x77296a: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0077296d: { // 0x77296d: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077296e: { // 0x77296e: 807d1400 CMP byte ptr [EBP + 0x14],0x0
    (void)integer::sub(m.r8((s.bp+0x00000014u)),0x00000000u,8,flags);
  }
  L00772972: { // 0x772972: 741a JZ 0x0077298e
    if(integer::condition("JZ",flags)) goto L0077298e;
  }
  L00772974: { // 0x772974: 3b450c CMP EAX,dword ptr [EBP + 0xc]
    (void)integer::sub(s.ax,m.r32((s.bp+0x0000000cu)),32,flags);
  }
  L00772977: { // 0x772977: 7515 JNZ 0x0077298e
    if(integer::condition("JNZ",flags)) goto L0077298e;
  }
  L00772979: { // 0x772979: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0077297b: { // 0x77297b: 833e2d CMP dword ptr [ESI],0x2d
    (void)integer::sub(m.r32((s.si)),0x0000002du,32,flags);
  }
  L0077297e: { // 0x77297e: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00772981: { // 0x772981: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00772983: { // 0x772983: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00772985: { // 0x772985: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00772987: { // 0x772987: c60030 MOV byte ptr [EAX],0x30
    m.w8((s.ax), 0x00000030u);
  }
  L0077298a: { // 0x77298a: 80600100 AND byte ptr [EAX + 0x1],0x0
    m.w8((s.ax+0x00000001u), integer::logical((m.r8((s.ax+0x00000001u)))&(0x00000000u),8,flags));
  }
  L0077298e: { // 0x77298e: 833e2d CMP dword ptr [ESI],0x2d
    (void)integer::sub(m.r32((s.si)),0x0000002du,32,flags);
  }
  L00772991: { // 0x772991: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L00772993: { // 0x772993: 7506 JNZ 0x0077299b
    if(integer::condition("JNZ",flags)) goto L0077299b;
  }
  L00772995: { // 0x772995: c6032d MOV byte ptr [EBX],0x2d
    m.w8((s.bx), 0x0000002du);
  }
  L00772998: { // 0x772998: 8d7b01 LEA EDI,[EBX + 0x1]
    s.di = (s.bx+0x00000001u);
  }
  L0077299b: { // 0x77299b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0077299e: { // 0x77299e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007729a0: { // 0x7729a0: 7f10 JG 0x007729b2
    if(integer::condition("JG",flags)) goto L007729b2;
  }
  L007729a2: { // 0x7729a2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L007729a4: { // 0x7729a4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007729a5: { // 0x7729a5: e83f010000 CALL 0x00772ae9
    s.arithmetic_flags=flags; invoke(m,s,f,0x00772ae9u,7809450u); flags=s.arithmetic_flags;
  }
  L007729aa: { // 0x7729aa: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007729ab: { // 0x7729ab: c60730 MOV byte ptr [EDI],0x30
    m.w8((s.di), 0x00000030u);
  }
  L007729ae: { // 0x7729ae: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007729af: { // 0x7729af: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L007729b0: { // 0x7729b0: eb02 JMP 0x007729b4
    goto L007729b4;
  }
  L007729b2: { // 0x7729b2: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L007729b4: { // 0x7729b4: 837d0c00 CMP dword ptr [EBP + 0xc],0x0
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),0x00000000u,32,flags);
  }
  L007729b8: { // 0x7729b8: 7e44 JLE 0x007729fe
    if(integer::condition("JLE",flags)) goto L007729fe;
  }
  L007729ba: { // 0x7729ba: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L007729bc: { // 0x7729bc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007729bd: { // 0x7729bd: e827010000 CALL 0x00772ae9
    s.arithmetic_flags=flags; invoke(m,s,f,0x00772ae9u,7809474u); flags=s.arithmetic_flags;
  }
  L007729c2: { // 0x7729c2: a070778100 MOV AL,[0x00817770]
    s.ax = with_al(s.ax, m.r8((0x00817770u)));
  }
  L007729c7: { // 0x7729c7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007729c8: { // 0x7729c8: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L007729ca: { // 0x7729ca: 8b7604 MOV ESI,dword ptr [ESI + 0x4]
    s.si = m.r32((s.si+0x00000004u));
  }
  L007729cd: { // 0x7729cd: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L007729ce: { // 0x7729ce: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007729cf: { // 0x7729cf: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L007729d1: { // 0x7729d1: 7d2b JGE 0x007729fe
    if(integer::condition("JGE",flags)) goto L007729fe;
  }
  L007729d3: { // 0x7729d3: 807d1400 CMP byte ptr [EBP + 0x14],0x0
    (void)integer::sub(m.r8((s.bp+0x00000014u)),0x00000000u,8,flags);
  }
  L007729d7: { // 0x7729d7: 7404 JZ 0x007729dd
    if(integer::condition("JZ",flags)) goto L007729dd;
  }
  L007729d9: { // 0x7729d9: f7de NEG ESI
    s.si = integer::sub(0u,s.si,32,flags);
  }
  L007729db: { // 0x7729db: eb07 JMP 0x007729e4
    goto L007729e4;
  }
  L007729dd: { // 0x7729dd: f7de NEG ESI
    s.si = integer::sub(0u,s.si,32,flags);
  }
  L007729df: { // 0x7729df: 39750c CMP dword ptr [EBP + 0xc],ESI
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.si,32,flags);
  }
  L007729e2: { // 0x7729e2: 7c03 JL 0x007729e7
    if(integer::condition("JL",flags)) goto L007729e7;
  }
  L007729e4: { // 0x7729e4: 89750c MOV dword ptr [EBP + 0xc],ESI
    m.w32((s.bp+0x0000000cu), s.si);
  }
  L007729e7: { // 0x7729e7: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L007729ea: { // 0x7729ea: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007729eb: { // 0x7729eb: e8f9000000 CALL 0x00772ae9
    s.arithmetic_flags=flags; invoke(m,s,f,0x00772ae9u,7809520u); flags=s.arithmetic_flags;
  }
  L007729f0: { // 0x7729f0: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L007729f3: { // 0x7729f3: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L007729f5: { // 0x7729f5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007729f6: { // 0x7729f6: e8258c0000 CALL 0x0077b620
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077b620u,7809531u); flags=s.arithmetic_flags;
  }
  L007729fb: { // 0x7729fb: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L007729fe: { // 0x7729fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007729ff: { // 0x7729ff: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00772a01: { // 0x772a01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00772a02: { // 0x772a02: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00772a03: { // 0x772a03: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00772a04: { // 0x772a04: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372847(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00772847: { // 0x772847: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00772848: { // 0x772848: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077284a: { // 0x77284a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077284b: { // 0x77284b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077284d: { // 0x77284d: 385d18 CMP byte ptr [EBP + 0x18],BL
    (void)integer::sub(m.r8((s.bp+0x00000018u)),(s.bx & 0xffu),8,flags);
  }
  L00772850: { // 0x772850: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00772851: { // 0x772851: 8b7514 MOV ESI,dword ptr [EBP + 0x14]
    s.si = m.r32((s.bp+0x00000014u));
  }
  L00772854: { // 0x772854: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00772855: { // 0x772855: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L00772858: { // 0x772858: 741b JZ 0x00772875
    if(integer::condition("JZ",flags)) goto L00772875;
  }
  L0077285a: { // 0x77285a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077285c: { // 0x77285c: 395d0c CMP dword ptr [EBP + 0xc],EBX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.bx,32,flags);
  }
  L0077285f: { // 0x77285f: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L00772862: { // 0x772862: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00772863: { // 0x772863: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00772865: { // 0x772865: 833e2d CMP dword ptr [ESI],0x2d
    (void)integer::sub(m.r32((s.si)),0x0000002du,32,flags);
  }
  L00772868: { // 0x772868: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0077286b: { // 0x77286b: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0077286d: { // 0x77286d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077286e: { // 0x77286e: e876020000 CALL 0x00772ae9
    s.arithmetic_flags=flags; invoke(m,s,f,0x00772ae9u,7809139u); flags=s.arithmetic_flags;
  }
  L00772873: { // 0x772873: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00772874: { // 0x772874: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00772875: { // 0x772875: 833e2d CMP dword ptr [ESI],0x2d
    (void)integer::sub(m.r32((s.si)),0x0000002du,32,flags);
  }
  L00772878: { // 0x772878: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0077287a: { // 0x77287a: 7506 JNZ 0x00772882
    if(integer::condition("JNZ",flags)) goto L00772882;
  }
  L0077287c: { // 0x77287c: c6072d MOV byte ptr [EDI],0x2d
    m.w8((s.di), 0x0000002du);
  }
  L0077287f: { // 0x77287f: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L00772882: { // 0x772882: 395d0c CMP dword ptr [EBP + 0xc],EBX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.bx,32,flags);
  }
  L00772885: { // 0x772885: 7e12 JLE 0x00772899
    if(integer::condition("JLE",flags)) goto L00772899;
  }
  L00772887: { // 0x772887: 8a5001 MOV DL,byte ptr [EAX + 0x1]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000001u)));
  }
  L0077288a: { // 0x77288a: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L0077288d: { // 0x77288d: 8810 MOV byte ptr [EAX],DL
    m.w8((s.ax), (s.dx & 0xffu));
  }
  L0077288f: { // 0x77288f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00772891: { // 0x772891: 8a0d70778100 MOV CL,byte ptr [0x00817770]
    s.cx = with_al(s.cx, m.r8((0x00817770u)));
  }
  L00772897: { // 0x772897: 8808 MOV byte ptr [EAX],CL
    m.w8((s.ax), (s.cx & 0xffu));
  }
  L00772899: { // 0x772899: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0077289b: { // 0x77289b: 385d18 CMP byte ptr [EBP + 0x18],BL
    (void)integer::sub(m.r8((s.bp+0x00000018u)),(s.bx & 0xffu),8,flags);
  }
  L0077289e: { // 0x77289e: 68a0c77900 PUSH 0x79c7a0
    f.push(m,0x0079c7a0u);
  }
  L007728a3: { // 0x7728a3: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L007728a6: { // 0x7728a6: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L007728a8: { // 0x7728a8: 034d0c ADD ECX,dword ptr [EBP + 0xc]
    s.cx = integer::add(s.cx,m.r32((s.bp+0x0000000cu)),32,flags);
  }
  L007728ab: { // 0x7728ab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007728ac: { // 0x7728ac: e85f670000 CALL 0x00779010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00779010u,7809201u); flags=s.arithmetic_flags;
  }
  L007728b1: { // 0x7728b1: 395d10 CMP dword ptr [EBP + 0x10],EBX
    (void)integer::sub(m.r32((s.bp+0x00000010u)),s.bx,32,flags);
  }
  L007728b4: { // 0x7728b4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007728b5: { // 0x7728b5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007728b6: { // 0x7728b6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007728b8: { // 0x7728b8: 7403 JZ 0x007728bd
    if(integer::condition("JZ",flags)) goto L007728bd;
  }
  L007728ba: { // 0x7728ba: c60145 MOV byte ptr [ECX],0x45
    m.w8((s.cx), 0x00000045u);
  }
  L007728bd: { // 0x7728bd: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L007728c0: { // 0x7728c0: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007728c1: { // 0x7728c1: 803830 CMP byte ptr [EAX],0x30
    (void)integer::sub(m.r8((s.ax)),0x00000030u,8,flags);
  }
  L007728c4: { // 0x7728c4: 743c JZ 0x00772902
    if(integer::condition("JZ",flags)) goto L00772902;
  }
  L007728c6: { // 0x7728c6: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L007728c9: { // 0x7728c9: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L007728ca: { // 0x7728ca: 7905 JNS 0x007728d1
    if(integer::condition("JNS",flags)) goto L007728d1;
  }
  L007728cc: { // 0x7728cc: f7db NEG EBX
    s.bx = integer::sub(0u,s.bx,32,flags);
  }
  L007728ce: { // 0x7728ce: c6012d MOV byte ptr [ECX],0x2d
    m.w8((s.cx), 0x0000002du);
  }
  L007728d1: { // 0x7728d1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007728d2: { // 0x7728d2: 83fb64 CMP EBX,0x64
    (void)integer::sub(s.bx,0x00000064u,32,flags);
  }
  L007728d5: { // 0x7728d5: 7c11 JL 0x007728e8
    if(integer::condition("JL",flags)) goto L007728e8;
  }
  L007728d7: { // 0x7728d7: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L007728d9: { // 0x7728d9: 6a64 PUSH 0x64
    f.push(m,0x00000064u);
  }
  L007728db: { // 0x7728db: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007728dc: { // 0x7728dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007728dd: { // 0x7728dd: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L007728df: { // 0x7728df: 0001 ADD byte ptr [ECX],AL
    m.w8((s.cx), integer::add(m.r8((s.cx)),(s.ax & 0xffu),8,flags));
  }
  L007728e1: { // 0x7728e1: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L007728e3: { // 0x7728e3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007728e4: { // 0x7728e4: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L007728e6: { // 0x7728e6: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L007728e8: { // 0x7728e8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007728e9: { // 0x7728e9: 83fb0a CMP EBX,0xa
    (void)integer::sub(s.bx,0x0000000au,32,flags);
  }
  L007728ec: { // 0x7728ec: 7c11 JL 0x007728ff
    if(integer::condition("JL",flags)) goto L007728ff;
  }
  L007728ee: { // 0x7728ee: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L007728f0: { // 0x7728f0: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  L007728f2: { // 0x7728f2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007728f3: { // 0x7728f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007728f4: { // 0x7728f4: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L007728f6: { // 0x7728f6: 0001 ADD byte ptr [ECX],AL
    m.w8((s.cx), integer::add(m.r8((s.cx)),(s.ax & 0xffu),8,flags));
  }
  L007728f8: { // 0x7728f8: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L007728fa: { // 0x7728fa: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007728fb: { // 0x7728fb: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L007728fd: { // 0x7728fd: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L007728ff: { // 0x7728ff: 005901 ADD byte ptr [ECX + 0x1],BL
    m.w8((s.cx+0x00000001u), integer::add(m.r8((s.cx+0x00000001u)),(s.bx & 0xffu),8,flags));
  }
  L00772902: { // 0x772902: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00772904: { // 0x772904: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00772905: { // 0x772905: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00772906: { // 0x772906: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00772907: { // 0x772907: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00772908: { // 0x772908: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372ae9(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00772ae9: { // 0x772ae9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00772aea: { // 0x772aea: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00772aee: { // 0x772aee: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00772af0: { // 0x772af0: 741a JZ 0x00772b0c
    if(integer::condition("JZ",flags)) goto L00772b0c;
  }
  L00772af2: { // 0x772af2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00772af3: { // 0x772af3: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L00772af7: { // 0x772af7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00772af8: { // 0x772af8: e863260000 CALL 0x00775160
    s.arithmetic_flags=flags; invoke(m,s,f,0x00775160u,7809789u); flags=s.arithmetic_flags;
  }
  L00772afd: { // 0x772afd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00772afe: { // 0x772afe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00772aff: { // 0x772aff: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00772b00: { // 0x772b00: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00772b02: { // 0x772b02: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00772b03: { // 0x772b03: e8c8c0ffff CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,7809800u); flags=s.arithmetic_flags;
  }
  L00772b08: { // 0x772b08: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00772b0b: { // 0x772b0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00772b0c: { // 0x772b0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00772b0d: { // 0x772b0d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00379010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00779010: { // 0x779010: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00779011: { // 0x779011: 8b7c2408 MOV EDI, dword ptr [ESP + 8]
    s.di = m.r32((f.sp+8u));
  }
  L00779015: { // 0x779015: eb6a JMP 0x779081
    goto L00779081;
  }
  L00779081: { // 0x779081: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00779085: { // 0x779085: f7c103000000 TEST ECX, 3
    (void)integer::logical((s.cx)&(3u),32,flags);
  }
  L0077908b: { // 0x77908b: 7419 JZ 0x7790a6
    if(integer::condition("JZ",flags)) goto L007790a6;
  }
  L0077908d: { // 0x77908d: 8a11 MOV DL, byte ptr [ECX]
    s.dx = with_al(s.dx, m.r8((s.cx)));
  }
  L0077908f: { // 0x77908f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00779090: { // 0x779090: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00779092: { // 0x779092: 7464 JZ 0x7790f8
    if(integer::condition("JZ",flags)) goto L007790f8;
  }
  L00779094: { // 0x779094: 8817 MOV byte ptr [EDI], DL
    m.w8((s.di), (s.dx & 0xffu));
  }
  L00779096: { // 0x779096: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00779097: { // 0x779097: f7c103000000 TEST ECX, 3
    (void)integer::logical((s.cx)&(3u),32,flags);
  }
  L0077909d: { // 0x77909d: 75ee JNZ 0x77908d
    if(integer::condition("JNZ",flags)) goto L0077908d;
  }
  L0077909f: { // 0x77909f: eb05 JMP 0x7790a6
    goto L007790a6;
  }
  L007790a1: { // 0x7790a1: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L007790a3: { // 0x7790a3: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L007790a6: { // 0x7790a6: bafffefe7e MOV EDX, 0x7efefeff
    s.dx = 0x7efefeffu;
  }
  L007790ab: { // 0x7790ab: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L007790ad: { // 0x7790ad: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L007790af: { // 0x7790af: 83f0ff XOR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)^(0xffffffffu),32,flags);
  }
  L007790b2: { // 0x7790b2: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L007790b4: { // 0x7790b4: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L007790b6: { // 0x7790b6: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L007790b9: { // 0x7790b9: a900010181 TEST EAX, 0x81010100
    (void)integer::logical((s.ax)&(0x81010100u),32,flags);
  }
  L007790be: { // 0x7790be: 74e1 JZ 0x7790a1
    if(integer::condition("JZ",flags)) goto L007790a1;
  }
  L007790c0: { // 0x7790c0: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L007790c2: { // 0x7790c2: 7434 JZ 0x7790f8
    if(integer::condition("JZ",flags)) goto L007790f8;
  }
  L007790c4: { // 0x7790c4: 84f6 TEST DH, DH
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(((s.dx >> 8) & 0xffu)),8,flags);
  }
  L007790c6: { // 0x7790c6: 7427 JZ 0x7790ef
    if(integer::condition("JZ",flags)) goto L007790ef;
  }
  L007790c8: { // 0x7790c8: f7c20000ff00 TEST EDX, 0xff0000
    (void)integer::logical((s.dx)&(0x00ff0000u),32,flags);
  }
  L007790ce: { // 0x7790ce: 7412 JZ 0x7790e2
    if(integer::condition("JZ",flags)) goto L007790e2;
  }
  L007790d0: { // 0x7790d0: f7c2000000ff TEST EDX, 0xff000000
    (void)integer::logical((s.dx)&(0xff000000u),32,flags);
  }
  L007790d6: { // 0x7790d6: 7402 JZ 0x7790da
    if(integer::condition("JZ",flags)) goto L007790da;
  }
  L007790d8: { // 0x7790d8: ebc7 JMP 0x7790a1
    goto L007790a1;
  }
  L007790da: { // 0x7790da: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L007790dc: { // 0x7790dc: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L007790e0: { // 0x7790e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007790e1: { // 0x7790e1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007790e2: { // 0x7790e2: 668917 MOV word ptr [EDI], DX
    m.w16((s.di), (s.dx & 0xffffu));
  }
  L007790e5: { // 0x7790e5: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L007790e9: { // 0x7790e9: c6470200 MOV byte ptr [EDI + 2], 0
    m.w8((s.di+2u), 0u);
  }
  L007790ed: { // 0x7790ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007790ee: { // 0x7790ee: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007790ef: { // 0x7790ef: 668917 MOV word ptr [EDI], DX
    m.w16((s.di), (s.dx & 0xffffu));
  }
  L007790f2: { // 0x7790f2: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L007790f6: { // 0x7790f6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007790f7: { // 0x7790f7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007790f8: { // 0x7790f8: 8817 MOV byte ptr [EDI], DL
    m.w8((s.di), (s.dx & 0xffu));
  }
  L007790fa: { // 0x7790fa: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L007790fe: { // 0x7790fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007790ff: { // 0x7790ff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00375160(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00775160: { // 0x775160: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L00775164: { // 0x775164: f7c103000000 TEST ECX,0x3
    (void)integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0077516a: { // 0x77516a: 7414 JZ 0x00775180
    if(integer::condition("JZ",flags)) goto L00775180;
  }
  L0077516c: { // 0x77516c: 8a01 MOV AL,byte ptr [ECX]
    s.ax = with_al(s.ax, m.r8((s.cx)));
  }
  L0077516e: { // 0x77516e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0077516f: { // 0x77516f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00775171: { // 0x775171: 7440 JZ 0x007751b3
    if(integer::condition("JZ",flags)) goto L007751b3;
  }
  L00775173: { // 0x775173: f7c103000000 TEST ECX,0x3
    (void)integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L00775179: { // 0x775179: 75f1 JNZ 0x0077516c
    if(integer::condition("JNZ",flags)) goto L0077516c;
  }
  L0077517b: { // 0x77517b: 0500000000 ADD EAX,0x0
    s.ax = integer::add(s.ax,0x00000000u,32,flags);
  }
  L00775180: { // 0x775180: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00775182: { // 0x775182: bafffefe7e MOV EDX,0x7efefeff
    s.dx = 0x7efefeffu;
  }
  L00775187: { // 0x775187: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00775189: { // 0x775189: 83f0ff XOR EAX,0xffffffff
    s.ax = integer::logical((s.ax)^(0xffffffffu),32,flags);
  }
  L0077518c: { // 0x77518c: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0077518e: { // 0x77518e: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L00775191: { // 0x775191: a900010181 TEST EAX,0x81010100
    (void)integer::logical((s.ax)&(0x81010100u),32,flags);
  }
  L00775196: { // 0x775196: 74e8 JZ 0x00775180
    if(integer::condition("JZ",flags)) goto L00775180;
  }
  L00775198: { // 0x775198: 8b41fc MOV EAX,dword ptr [ECX + -0x4]
    s.ax = m.r32((s.cx-0x00000004u));
  }
  L0077519b: { // 0x77519b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0077519d: { // 0x77519d: 7432 JZ 0x007751d1
    if(integer::condition("JZ",flags)) goto L007751d1;
  }
  L0077519f: { // 0x77519f: 84e4 TEST AH,AH
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(((s.ax >> 8) & 0xffu)),8,flags);
  }
  L007751a1: { // 0x7751a1: 7424 JZ 0x007751c7
    if(integer::condition("JZ",flags)) goto L007751c7;
  }
  L007751a3: { // 0x7751a3: a90000ff00 TEST EAX,0xff0000
    (void)integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L007751a8: { // 0x7751a8: 7413 JZ 0x007751bd
    if(integer::condition("JZ",flags)) goto L007751bd;
  }
  L007751aa: { // 0x7751aa: a9000000ff TEST EAX,0xff000000
    (void)integer::logical((s.ax)&(0xff000000u),32,flags);
  }
  L007751af: { // 0x7751af: 7402 JZ 0x007751b3
    if(integer::condition("JZ",flags)) goto L007751b3;
  }
  L007751b1: { // 0x7751b1: ebcd JMP 0x00775180
    goto L00775180;
  }
  L007751b3: { // 0x7751b3: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L007751b6: { // 0x7751b6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L007751ba: { // 0x7751ba: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L007751bc: { // 0x7751bc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007751bd: { // 0x7751bd: 8d41fe LEA EAX,[ECX + -0x2]
    s.ax = (s.cx-0x00000002u);
  }
  L007751c0: { // 0x7751c0: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L007751c4: { // 0x7751c4: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L007751c6: { // 0x7751c6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007751c7: { // 0x7751c7: 8d41fd LEA EAX,[ECX + -0x3]
    s.ax = (s.cx-0x00000003u);
  }
  L007751ca: { // 0x7751ca: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L007751ce: { // 0x7751ce: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L007751d0: { // 0x7751d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007751d1: { // 0x7751d1: 8d41fc LEA EAX,[ECX + -0x4]
    s.ax = (s.cx-0x00000004u);
  }
  L007751d4: { // 0x7751d4: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L007751d8: { // 0x7751d8: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L007751da: { // 0x7751da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036ebd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076ebd0: { // 0x76ebd0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076ebd1: { // 0x76ebd1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076ebd3: { // 0x76ebd3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076ebd4: { // 0x76ebd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076ebd5: { // 0x76ebd5: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076ebd8: { // 0x76ebd8: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L0076ebdb: { // 0x76ebdb: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0076ebde: { // 0x76ebde: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076ebe0: { // 0x76ebe0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0076ebe2: { // 0x76ebe2: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0076ebe4: { // 0x76ebe4: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0076ebe6: { // 0x76ebe6: 7608 JBE 0x0076ebf0
    if(integer::condition("JBE",flags)) goto L0076ebf0;
  }
  L0076ebe8: { // 0x76ebe8: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0076ebea: { // 0x76ebea: 0f8278010000 JC 0x0076ed68
    if(integer::condition("JC",flags)) goto L0076ed68;
  }
  L0076ebf0: { // 0x76ebf0: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076ebf6: { // 0x76ebf6: 7514 JNZ 0x0076ec0c
    if(integer::condition("JNZ",flags)) goto L0076ec0c;
  }
  L0076ebf8: { // 0x76ebf8: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ebfb: { // 0x76ebfb: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0076ebfe: { // 0x76ebfe: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec01: { // 0x76ec01: 7229 JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec03: { // 0x76ec03: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec05: { // 0x76ec05: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ec0c: { // 0x76ec0c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0076ec0e: { // 0x76ec0e: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L0076ec13: { // 0x76ec13: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0076ec16: { // 0x76ec16: 720c JC 0x0076ec24
    if(integer::condition("JC",flags)) goto L0076ec24;
  }
  L0076ec18: { // 0x76ec18: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0076ec1b: { // 0x76ec1b: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0076ec1d: { // 0x76ec1d: ff248530ec7600 JMP dword ptr [EAX*0x4 + 0x76ec30]
    switch(m.r32(((s.ax * 0x00000004u)+0x0076ec30u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ec24: { // 0x76ec24: ff248d28ed7600 JMP dword ptr [ECX*0x4 + 0x76ed28]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ed28u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ec2c: { // 0x76ec2c: ff248dacec7600 JMP dword ptr [ECX*0x4 + 0x76ecac]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ecacu))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ec40: { // 0x76ec40: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec42: { // 0x76ec42: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec44: { // 0x76ec44: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec46: { // 0x76ec46: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ec49: { // 0x76ec49: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ec4c: { // 0x76ec4c: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ec4f: { // 0x76ec4f: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec52: { // 0x76ec52: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ec55: { // 0x76ec55: 83c603 ADD ESI,0x3
    s.si = integer::add(s.si,0x00000003u,32,flags);
  }
  L0076ec58: { // 0x76ec58: 83c703 ADD EDI,0x3
    s.di = integer::add(s.di,0x00000003u,32,flags);
  }
  L0076ec5b: { // 0x76ec5b: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec5e: { // 0x76ec5e: 72cc JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec60: { // 0x76ec60: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec62: { // 0x76ec62: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ec6c: { // 0x76ec6c: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec6e: { // 0x76ec6e: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec70: { // 0x76ec70: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec72: { // 0x76ec72: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ec75: { // 0x76ec75: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec78: { // 0x76ec78: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ec7b: { // 0x76ec7b: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0076ec7e: { // 0x76ec7e: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L0076ec81: { // 0x76ec81: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec84: { // 0x76ec84: 72a6 JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec86: { // 0x76ec86: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec88: { // 0x76ec88: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ec90: { // 0x76ec90: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec92: { // 0x76ec92: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec94: { // 0x76ec94: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec96: { // 0x76ec96: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076ec97: { // 0x76ec97: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec9a: { // 0x76ec9a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076ec9b: { // 0x76ec9b: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec9e: { // 0x76ec9e: 728c JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076eca0: { // 0x76eca0: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076eca2: { // 0x76eca2: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076eccc: { // 0x76eccc: 8b448ee4 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x1c]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x0000001cu));
  }
  L0076ecd0: { // 0x76ecd0: 89448fe4 MOV dword ptr [EDI + ECX*0x4 + -0x1c],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x0000001cu), s.ax);
  }
  L0076ecd4: { // 0x76ecd4: 8b448ee8 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x18]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000018u));
  }
  L0076ecd8: { // 0x76ecd8: 89448fe8 MOV dword ptr [EDI + ECX*0x4 + -0x18],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000018u), s.ax);
  }
  L0076ecdc: { // 0x76ecdc: 8b448eec MOV EAX,dword ptr [ESI + ECX*0x4 + -0x14]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000014u));
  }
  L0076ece0: { // 0x76ece0: 89448fec MOV dword ptr [EDI + ECX*0x4 + -0x14],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000014u), s.ax);
  }
  L0076ece4: { // 0x76ece4: 8b448ef0 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x10]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000010u));
  }
  L0076ece8: { // 0x76ece8: 89448ff0 MOV dword ptr [EDI + ECX*0x4 + -0x10],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000010u), s.ax);
  }
  L0076ecec: { // 0x76ecec: 8b448ef4 MOV EAX,dword ptr [ESI + ECX*0x4 + -0xc]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x0000000cu));
  }
  L0076ecf0: { // 0x76ecf0: 89448ff4 MOV dword ptr [EDI + ECX*0x4 + -0xc],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x0000000cu), s.ax);
  }
  L0076ecf4: { // 0x76ecf4: 8b448ef8 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x8]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000008u));
  }
  L0076ecf8: { // 0x76ecf8: 89448ff8 MOV dword ptr [EDI + ECX*0x4 + -0x8],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000008u), s.ax);
  }
  L0076ecfc: { // 0x76ecfc: 8b448efc MOV EAX,dword ptr [ESI + ECX*0x4 + -0x4]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000004u));
  }
  L0076ed00: { // 0x76ed00: 89448ffc MOV dword ptr [EDI + ECX*0x4 + -0x4],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000004u), s.ax);
  }
  L0076ed04: { // 0x76ed04: 8d048d00000000 LEA EAX,[ECX*0x4 + 0x0]
    s.ax = ((s.cx * 0x00000004u)+0x00000000u);
  }
  L0076ed0b: { // 0x76ed0b: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0076ed0d: { // 0x76ed0d: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0076ed0f: { // 0x76ed0f: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ed28: { // 0x76ed28: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed2b: { // 0x76ed2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed2c: { // 0x76ed2c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed2d: { // 0x76ed2d: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed2e: { // 0x76ed2e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed30: { // 0x76ed30: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed32: { // 0x76ed32: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed34: { // 0x76ed34: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed37: { // 0x76ed37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed38: { // 0x76ed38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed39: { // 0x76ed39: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed3a: { // 0x76ed3a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed3c: { // 0x76ed3c: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed3e: { // 0x76ed3e: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed40: { // 0x76ed40: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ed43: { // 0x76ed43: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ed46: { // 0x76ed46: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed49: { // 0x76ed49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed4a: { // 0x76ed4a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed4b: { // 0x76ed4b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed4c: { // 0x76ed4c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed50: { // 0x76ed50: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed52: { // 0x76ed52: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed54: { // 0x76ed54: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ed57: { // 0x76ed57: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ed5a: { // 0x76ed5a: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ed5d: { // 0x76ed5d: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ed60: { // 0x76ed60: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed63: { // 0x76ed63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed64: { // 0x76ed64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed65: { // 0x76ed65: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed66: { // 0x76ed66: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed68: { // 0x76ed68: 8d7431fc LEA ESI,[ECX + ESI*0x1 + -0x4]
    s.si = (s.cx+(s.si * 0x00000001u)-0x00000004u);
  }
  L0076ed6c: { // 0x76ed6c: 8d7c39fc LEA EDI,[ECX + EDI*0x1 + -0x4]
    s.di = (s.cx+(s.di * 0x00000001u)-0x00000004u);
  }
  L0076ed70: { // 0x76ed70: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076ed76: { // 0x76ed76: 7524 JNZ 0x0076ed9c
    if(integer::condition("JNZ",flags)) goto L0076ed9c;
  }
  L0076ed78: { // 0x76ed78: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ed7b: { // 0x76ed7b: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0076ed7e: { // 0x76ed7e: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ed81: { // 0x76ed81: 720d JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ed83: { // 0x76ed83: fd STD
    flags|=0x400u;
  }
  L0076ed84: { // 0x76ed84: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ed86: { // 0x76ed86: fc CLD
    flags&=~0x400u;
  }
  L0076ed87: { // 0x76ed87: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ed90: { // 0x76ed90: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0076ed92: { // 0x76ed92: ff248d60ee7600 JMP dword ptr [ECX*0x4 + 0x76ee60]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ee60u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ed9c: { // 0x76ed9c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0076ed9e: { // 0x76ed9e: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L0076eda3: { // 0x76eda3: 83f904 CMP ECX,0x4
    (void)integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0076eda6: { // 0x76eda6: 720c JC 0x0076edb4
    if(integer::condition("JC",flags)) goto L0076edb4;
  }
  L0076eda8: { // 0x76eda8: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0076edab: { // 0x76edab: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0076edad: { // 0x76edad: ff2485b8ed7600 JMP dword ptr [EAX*0x4 + 0x76edb8]
    switch(m.r32(((s.ax * 0x00000004u)+0x0076edb8u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076edb4: { // 0x76edb4: ff248db0ee7600 JMP dword ptr [ECX*0x4 + 0x76eeb0]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076edc8: { // 0x76edc8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076edcb: { // 0x76edcb: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076edcd: { // 0x76edcd: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076edd0: { // 0x76edd0: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0076edd1: { // 0x76edd1: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076edd4: { // 0x76edd4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0076edd5: { // 0x76edd5: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076edd8: { // 0x76edd8: 72b6 JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076edda: { // 0x76edda: fd STD
    flags|=0x400u;
  }
  L0076eddb: { // 0x76eddb: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076eddd: { // 0x76eddd: fc CLD
    flags&=~0x400u;
  }
  L0076edde: { // 0x76edde: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ede8: { // 0x76ede8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076edeb: { // 0x76edeb: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076eded: { // 0x76eded: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076edf0: { // 0x76edf0: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076edf3: { // 0x76edf3: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076edf6: { // 0x76edf6: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076edf9: { // 0x76edf9: 83ee02 SUB ESI,0x2
    s.si = integer::sub(s.si,0x00000002u,32,flags);
  }
  L0076edfc: { // 0x76edfc: 83ef02 SUB EDI,0x2
    s.di = integer::sub(s.di,0x00000002u,32,flags);
  }
  L0076edff: { // 0x76edff: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ee02: { // 0x76ee02: 728c JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ee04: { // 0x76ee04: fd STD
    flags|=0x400u;
  }
  L0076ee05: { // 0x76ee05: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ee07: { // 0x76ee07: fc CLD
    flags&=~0x400u;
  }
  L0076ee08: { // 0x76ee08: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ee10: { // 0x76ee10: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076ee13: { // 0x76ee13: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ee15: { // 0x76ee15: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076ee18: { // 0x76ee18: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ee1b: { // 0x76ee1b: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ee1e: { // 0x76ee1e: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ee21: { // 0x76ee21: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ee24: { // 0x76ee24: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ee27: { // 0x76ee27: 83ee03 SUB ESI,0x3
    s.si = integer::sub(s.si,0x00000003u,32,flags);
  }
  L0076ee2a: { // 0x76ee2a: 83ef03 SUB EDI,0x3
    s.di = integer::sub(s.di,0x00000003u,32,flags);
  }
  L0076ee2d: { // 0x76ee2d: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ee30: { // 0x76ee30: 0f825affffff JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ee36: { // 0x76ee36: fd STD
    flags|=0x400u;
  }
  L0076ee37: { // 0x76ee37: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ee39: { // 0x76ee39: fc CLD
    flags&=~0x400u;
  }
  L0076ee3a: { // 0x76ee3a: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076ee64: { // 0x76ee64: 8b448e1c MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1c]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x0000001cu));
  }
  L0076ee68: { // 0x76ee68: 89448f1c MOV dword ptr [EDI + ECX*0x4 + 0x1c],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x0000001cu), s.ax);
  }
  L0076ee6c: { // 0x76ee6c: 8b448e18 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x18]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000018u));
  }
  L0076ee70: { // 0x76ee70: 89448f18 MOV dword ptr [EDI + ECX*0x4 + 0x18],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000018u), s.ax);
  }
  L0076ee74: { // 0x76ee74: 8b448e14 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x14]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000014u));
  }
  L0076ee78: { // 0x76ee78: 89448f14 MOV dword ptr [EDI + ECX*0x4 + 0x14],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000014u), s.ax);
  }
  L0076ee7c: { // 0x76ee7c: 8b448e10 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x10]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000010u));
  }
  L0076ee80: { // 0x76ee80: 89448f10 MOV dword ptr [EDI + ECX*0x4 + 0x10],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000010u), s.ax);
  }
  L0076ee84: { // 0x76ee84: 8b448e0c MOV EAX,dword ptr [ESI + ECX*0x4 + 0xc]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0076ee88: { // 0x76ee88: 89448f0c MOV dword ptr [EDI + ECX*0x4 + 0xc],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x0000000cu), s.ax);
  }
  L0076ee8c: { // 0x76ee8c: 8b448e08 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x8]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000008u));
  }
  L0076ee90: { // 0x76ee90: 89448f08 MOV dword ptr [EDI + ECX*0x4 + 0x8],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000008u), s.ax);
  }
  L0076ee94: { // 0x76ee94: 8b448e04 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x4]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000004u));
  }
  L0076ee98: { // 0x76ee98: 89448f04 MOV dword ptr [EDI + ECX*0x4 + 0x4],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000004u), s.ax);
  }
  L0076ee9c: { // 0x76ee9c: 8d048d00000000 LEA EAX,[ECX*0x4 + 0x0]
    s.ax = ((s.cx * 0x00000004u)+0x00000000u);
  }
  L0076eea3: { // 0x76eea3: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0076eea5: { // 0x76eea5: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0076eea7: { // 0x76eea7: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery762 unsupported switch destination");}
  }
  L0076eec0: { // 0x76eec0: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eec3: { // 0x76eec3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eec4: { // 0x76eec4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eec5: { // 0x76eec5: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eec6: { // 0x76eec6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eec8: { // 0x76eec8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eecb: { // 0x76eecb: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eece: { // 0x76eece: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eed1: { // 0x76eed1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eed2: { // 0x76eed2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eed3: { // 0x76eed3: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eed4: { // 0x76eed4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eed8: { // 0x76eed8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eedb: { // 0x76eedb: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eede: { // 0x76eede: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076eee1: { // 0x76eee1: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076eee4: { // 0x76eee4: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eee7: { // 0x76eee7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eee8: { // 0x76eee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eee9: { // 0x76eee9: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eeea: { // 0x76eeea: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eeec: { // 0x76eeec: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eeef: { // 0x76eeef: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eef2: { // 0x76eef2: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076eef5: { // 0x76eef5: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076eef8: { // 0x76eef8: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076eefb: { // 0x76eefb: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076eefe: { // 0x76eefe: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ef01: { // 0x76ef01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ef02: { // 0x76ef02: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ef03: { // 0x76ef03: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ef04: { // 0x76ef04: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037b620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077b620: { // 0x77b620: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L0077b624: { // 0x77b624: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0077b628: { // 0x77b628: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0077b62a: { // 0x77b62a: 7447 JZ 0x0077b673
    if(integer::condition("JZ",flags)) goto L0077b673;
  }
  L0077b62c: { // 0x77b62c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077b62e: { // 0x77b62e: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L0077b632: { // 0x77b632: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077b633: { // 0x77b633: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0077b635: { // 0x77b635: 83fa04 CMP EDX,0x4
    (void)integer::sub(s.dx,0x00000004u,32,flags);
  }
  L0077b638: { // 0x77b638: 722d JC 0x0077b667
    if(integer::condition("JC",flags)) goto L0077b667;
  }
  L0077b63a: { // 0x77b63a: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0077b63c: { // 0x77b63c: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0077b63f: { // 0x77b63f: 7408 JZ 0x0077b649
    if(integer::condition("JZ",flags)) goto L0077b649;
  }
  L0077b641: { // 0x77b641: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L0077b643: { // 0x77b643: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0077b645: { // 0x77b645: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077b646: { // 0x77b646: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0077b647: { // 0x77b647: 75fa JNZ 0x0077b643
    if(integer::condition("JNZ",flags)) goto L0077b643;
  }
  L0077b649: { // 0x77b649: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0077b64b: { // 0x77b64b: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0077b64e: { // 0x77b64e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0077b650: { // 0x77b650: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0077b652: { // 0x77b652: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0077b655: { // 0x77b655: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0077b657: { // 0x77b657: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0077b659: { // 0x77b659: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0077b65c: { // 0x77b65c: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0077b65f: { // 0x77b65f: 7406 JZ 0x0077b667
    if(integer::condition("JZ",flags)) goto L0077b667;
  }
  L0077b661: { // 0x77b661: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0077b663: { // 0x77b663: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0077b665: { // 0x77b665: 7406 JZ 0x0077b66d
    if(integer::condition("JZ",flags)) goto L0077b66d;
  }
  L0077b667: { // 0x77b667: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0077b669: { // 0x77b669: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077b66a: { // 0x77b66a: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0077b66b: { // 0x77b66b: 75fa JNZ 0x0077b667
    if(integer::condition("JNZ",flags)) goto L0077b667;
  }
  L0077b66d: { // 0x77b66d: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0077b671: { // 0x77b671: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077b672: { // 0x77b672: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0077b673: { // 0x77b673: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0077b677: { // 0x77b677: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00380c48(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00780c48: { // 0x780c48: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00780c49: { // 0x780c49: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00780c4b: { // 0x780c4b: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00780c4e: { // 0x780c4e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780c4f: { // 0x780c4f: bb88878100 MOV EBX,0x818788
    s.bx = 0x00818788u;
  }
  L00780c54: { // 0x780c54: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00780c56: { // 0x780c56: 83eb60 SUB EBX,0x60
    s.bx = integer::sub(s.bx,0x00000060u,32,flags);
  }
  L00780c59: { // 0x780c59: 394d0c CMP dword ptr [EBP + 0xc],ECX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.cx,32,flags);
  }
  L00780c5c: { // 0x780c5c: 7463 JZ 0x00780cc1
    if(integer::condition("JZ",flags)) goto L00780cc1;
  }
  L00780c5e: { // 0x780c5e: 7d10 JGE 0x00780c70
    if(integer::condition("JGE",flags)) goto L00780c70;
  }
  L00780c60: { // 0x780c60: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00780c63: { // 0x780c63: bbe8888100 MOV EBX,0x8188e8
    s.bx = 0x008188e8u;
  }
  L00780c68: { // 0x780c68: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00780c6a: { // 0x780c6a: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L00780c6d: { // 0x780c6d: 83eb60 SUB EBX,0x60
    s.bx = integer::sub(s.bx,0x00000060u,32,flags);
  }
  L00780c70: { // 0x780c70: 394d10 CMP dword ptr [EBP + 0x10],ECX
    (void)integer::sub(m.r32((s.bp+0x00000010u)),s.cx,32,flags);
  }
  L00780c73: { // 0x780c73: 7506 JNZ 0x00780c7b
    if(integer::condition("JNZ",flags)) goto L00780c7b;
  }
  L00780c75: { // 0x780c75: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00780c78: { // 0x780c78: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L00780c7b: { // 0x780c7b: 394d0c CMP dword ptr [EBP + 0xc],ECX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.cx,32,flags);
  }
  L00780c7e: { // 0x780c7e: 7441 JZ 0x00780cc1
    if(integer::condition("JZ",flags)) goto L00780cc1;
  }
  L00780c80: { // 0x780c80: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780c81: { // 0x780c81: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00780c82: { // 0x780c82: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00780c85: { // 0x780c85: 83c354 ADD EBX,0x54
    s.bx = integer::add(s.bx,0x00000054u,32,flags);
  }
  L00780c88: { // 0x780c88: c17d0c03 SAR dword ptr [EBP + 0xc],0x3
    m.w32((s.bp+0x0000000cu), integer::shift(m.r32((s.bp+0x0000000cu)),0x00000003u,32,flags,integer::Shift::arithmetic_right));
  }
  L00780c8c: { // 0x780c8c: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L00780c8f: { // 0x780c8f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00780c91: { // 0x780c91: 7427 JZ 0x00780cba
    if(integer::condition("JZ",flags)) goto L00780cba;
  }
  L00780c93: { // 0x780c93: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00780c96: { // 0x780c96: 66813c830080 CMP word ptr [EBX + EAX*0x4],0x8000
    (void)integer::sub(m.r16((s.bx+(s.ax * 0x00000004u))),0x00008000u,16,flags);
  }
  L00780c9c: { // 0x780c9c: 8d3483 LEA ESI,[EBX + EAX*0x4]
    s.si = (s.bx+(s.ax * 0x00000004u));
  }
  L00780c9f: { // 0x780c9f: 720c JC 0x00780cad
    if(integer::condition("JC",flags)) goto L00780cad;
  }
  L00780ca1: { // 0x780ca1: 8d7df4 LEA EDI,[EBP + -0xc]
    s.di = (s.bp-0x0000000cu);
  }
  L00780ca4: { // 0x780ca4: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780ca5: { // 0x780ca5: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780ca6: { // 0x780ca6: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780ca7: { // 0x780ca7: ff4df6 DEC dword ptr [EBP + -0xa]
    m.w32((s.bp-0x0000000au), integer::decrement(m.r32((s.bp-0x0000000au)),32,flags));
  }
  L00780caa: { // 0x780caa: 8d75f4 LEA ESI,[EBP + -0xc]
    s.si = (s.bp-0x0000000cu);
  }
  L00780cad: { // 0x780cad: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780cae: { // 0x780cae: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  L00780cb1: { // 0x780cb1: e872fdffff CALL 0x00780a28
    s.arithmetic_flags=flags; invoke(m,s,f,0x00780a28u,7867574u); flags=s.arithmetic_flags;
  }
  L00780cb6: { // 0x780cb6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780cb7: { // 0x780cb7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780cb8: { // 0x780cb8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00780cba: { // 0x780cba: 394d0c CMP dword ptr [EBP + 0xc],ECX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.cx,32,flags);
  }
  L00780cbd: { // 0x780cbd: 75c3 JNZ 0x00780c82
    if(integer::condition("JNZ",flags)) goto L00780c82;
  }
  L00780cbf: { // 0x780cbf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00780cc0: { // 0x780cc0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00780cc1: { // 0x780cc1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00780cc2: { // 0x780cc2: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00780cc3: { // 0x780cc3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00380a28(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00780a28: { // 0x780a28: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00780a29: { // 0x780a29: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00780a2b: { // 0x780a2b: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L00780a2e: { // 0x780a2e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780a2f: { // 0x780a2f: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L00780a32: { // 0x780a32: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780a33: { // 0x780a33: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L00780a36: { // 0x780a36: 668b4b0a MOV CX,word ptr [EBX + 0xa]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x0000000au)));
  }
  L00780a3a: { // 0x780a3a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00780a3c: { // 0x780a3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00780a3d: { // 0x780a3d: 8945ec MOV dword ptr [EBP + -0x14],EAX
    m.w32((s.bp-0x00000014u), s.ax);
  }
  L00780a40: { // 0x780a40: 8945dc MOV dword ptr [EBP + -0x24],EAX
    m.w32((s.bp-0x00000024u), s.ax);
  }
  L00780a43: { // 0x780a43: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  L00780a46: { // 0x780a46: 8945e4 MOV dword ptr [EBP + -0x1c],EAX
    m.w32((s.bp-0x0000001cu), s.ax);
  }
  L00780a49: { // 0x780a49: 668b460a MOV AX,word ptr [ESI + 0xa]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000000au)));
  }
  L00780a4d: { // 0x780a4d: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00780a4f: { // 0x780a4f: baff7f0000 MOV EDX,0x7fff
    s.dx = 0x00007fffu;
  }
  L00780a54: { // 0x780a54: 33f8 XOR EDI,EAX
    s.di = integer::logical((s.di)^(s.ax),32,flags);
  }
  L00780a56: { // 0x780a56: 23c2 AND EAX,EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  L00780a58: { // 0x780a58: 23ca AND ECX,EDX
    s.cx = integer::logical((s.cx)&(s.dx),32,flags);
  }
  L00780a5a: { // 0x780a5a: 81e700800000 AND EDI,0x8000
    s.di = integer::logical((s.di)&(0x00008000u),32,flags);
  }
  L00780a60: { // 0x780a60: 663dff7f CMP AX,0x7fff
    (void)integer::sub((s.ax & 0xffffu),0x00007fffu,16,flags);
  }
  L00780a64: { // 0x780a64: 8d1401 LEA EDX,[ECX + EAX*0x1]
    s.dx = (s.cx+(s.ax * 0x00000001u));
  }
  L00780a67: { // 0x780a67: 895508 MOV dword ptr [EBP + 0x8],EDX
    m.w32((s.bp+0x00000008u), s.dx);
  }
  L00780a6a: { // 0x780a6a: 0f83b8010000 JNC 0x00780c28
    if(integer::condition("JNC",flags)) goto L00780c28;
  }
  L00780a70: { // 0x780a70: 6681f9ff7f CMP CX,0x7fff
    (void)integer::sub((s.cx & 0xffffu),0x00007fffu,16,flags);
  }
  L00780a75: { // 0x780a75: 0f83ad010000 JNC 0x00780c28
    if(integer::condition("JNC",flags)) goto L00780c28;
  }
  L00780a7b: { // 0x780a7b: 6681fafdbf CMP DX,0xbffd
    (void)integer::sub((s.dx & 0xffffu),0x0000bffdu,16,flags);
  }
  L00780a80: { // 0x780a80: 0f87a2010000 JA 0x00780c28
    if(integer::condition("JA",flags)) goto L00780c28;
  }
  L00780a86: { // 0x780a86: 6681fabf3f CMP DX,0x3fbf
    (void)integer::sub((s.dx & 0xffffu),0x00003fbfu,16,flags);
  }
  L00780a8b: { // 0x780a8b: 7704 JA 0x00780a91
    if(integer::condition("JA",flags)) goto L00780a91;
  }
  L00780a8d: { // 0x780a8d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00780a8f: { // 0x780a8f: eb3a JMP 0x00780acb
    goto L00780acb;
  }
  L00780a91: { // 0x780a91: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L00780a94: { // 0x780a94: baffffff7f MOV EDX,0x7fffffff
    s.dx = 0x7fffffffu;
  }
  L00780a99: { // 0x780a99: 7518 JNZ 0x00780ab3
    if(integer::condition("JNZ",flags)) goto L00780ab3;
  }
  L00780a9b: { // 0x780a9b: ff4508 INC dword ptr [EBP + 0x8]
    m.w32((s.bp+0x00000008u), integer::increment(m.r32((s.bp+0x00000008u)),32,flags));
  }
  L00780a9e: { // 0x780a9e: 855608 TEST dword ptr [ESI + 0x8],EDX
    (void)integer::logical((m.r32((s.si+0x00000008u)))&(s.dx),32,flags);
  }
  L00780aa1: { // 0x780aa1: 7510 JNZ 0x00780ab3
    if(integer::condition("JNZ",flags)) goto L00780ab3;
  }
  L00780aa3: { // 0x780aa3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00780aa5: { // 0x780aa5: 394604 CMP dword ptr [ESI + 0x4],EAX
    (void)integer::sub(m.r32((s.si+0x00000004u)),s.ax,32,flags);
  }
  L00780aa8: { // 0x780aa8: 750b JNZ 0x00780ab5
    if(integer::condition("JNZ",flags)) goto L00780ab5;
  }
  L00780aaa: { // 0x780aaa: 3906 CMP dword ptr [ESI],EAX
    (void)integer::sub(m.r32((s.si)),s.ax,32,flags);
  }
  L00780aac: { // 0x780aac: 7507 JNZ 0x00780ab5
    if(integer::condition("JNZ",flags)) goto L00780ab5;
  }
  L00780aae: { // 0x780aae: e96f010000 JMP 0x00780c22
    goto L00780c22;
  }
  L00780ab3: { // 0x780ab3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00780ab5: { // 0x780ab5: 663bc8 CMP CX,AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L00780ab8: { // 0x780ab8: 751e JNZ 0x00780ad8
    if(integer::condition("JNZ",flags)) goto L00780ad8;
  }
  L00780aba: { // 0x780aba: ff4508 INC dword ptr [EBP + 0x8]
    m.w32((s.bp+0x00000008u), integer::increment(m.r32((s.bp+0x00000008u)),32,flags));
  }
  L00780abd: { // 0x780abd: 855308 TEST dword ptr [EBX + 0x8],EDX
    (void)integer::logical((m.r32((s.bx+0x00000008u)))&(s.dx),32,flags);
  }
  L00780ac0: { // 0x780ac0: 7516 JNZ 0x00780ad8
    if(integer::condition("JNZ",flags)) goto L00780ad8;
  }
  L00780ac2: { // 0x780ac2: 394304 CMP dword ptr [EBX + 0x4],EAX
    (void)integer::sub(m.r32((s.bx+0x00000004u)),s.ax,32,flags);
  }
  L00780ac5: { // 0x780ac5: 7511 JNZ 0x00780ad8
    if(integer::condition("JNZ",flags)) goto L00780ad8;
  }
  L00780ac7: { // 0x780ac7: 3903 CMP dword ptr [EBX],EAX
    (void)integer::sub(m.r32((s.bx)),s.ax,32,flags);
  }
  L00780ac9: { // 0x780ac9: 750d JNZ 0x00780ad8
    if(integer::condition("JNZ",flags)) goto L00780ad8;
  }
  L00780acb: { // 0x780acb: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00780ace: { // 0x780ace: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L00780ad1: { // 0x780ad1: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00780ad3: { // 0x780ad3: e96b010000 JMP 0x00780c43
    goto L00780c43;
  }
  L00780ad8: { // 0x780ad8: 8945f0 MOV dword ptr [EBP + -0x10],EAX
    m.w32((s.bp-0x00000010u), s.ax);
  }
  L00780adb: { // 0x780adb: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  L00780ade: { // 0x780ade: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  L00780ae1: { // 0x780ae1: c7450c05000000 MOV dword ptr [EBP + 0xc],0x5
    m.w32((s.bp+0x0000000cu), 0x00000005u);
  }
  L00780ae8: { // 0x780ae8: 8b45f0 MOV EAX,dword ptr [EBP + -0x10]
    s.ax = m.r32((s.bp-0x00000010u));
  }
  L00780aeb: { // 0x780aeb: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  L00780aed: { // 0x780aed: 837d0c00 CMP dword ptr [EBP + 0xc],0x0
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),0x00000000u,32,flags);
  }
  L00780af1: { // 0x780af1: 7e49 JLE 0x00780b3c
    if(integer::condition("JLE",flags)) goto L00780b3c;
  }
  L00780af3: { // 0x780af3: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00780af5: { // 0x780af5: 8d4b08 LEA ECX,[EBX + 0x8]
    s.cx = (s.bx+0x00000008u);
  }
  L00780af8: { // 0x780af8: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  L00780afb: { // 0x780afb: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00780afe: { // 0x780afe: 894df4 MOV dword ptr [EBP + -0xc],ECX
    m.w32((s.bp-0x0000000cu), s.cx);
  }
  L00780b01: { // 0x780b01: 8945e8 MOV dword ptr [EBP + -0x18],EAX
    m.w32((s.bp-0x00000018u), s.ax);
  }
  L00780b04: { // 0x780b04: 8b45f8 MOV EAX,dword ptr [EBP + -0x8]
    s.ax = m.r32((s.bp-0x00000008u));
  }
  L00780b07: { // 0x780b07: 8b4df4 MOV ECX,dword ptr [EBP + -0xc]
    s.cx = m.r32((s.bp-0x0000000cu));
  }
  L00780b0a: { // 0x780b0a: 0fb700 MOVZX EAX,word ptr [EAX]
    s.ax = (m.r16((s.ax))&integer::mask(16));
  }
  L00780b0d: { // 0x780b0d: 0fb709 MOVZX ECX,word ptr [ECX]
    s.cx = (m.r16((s.cx))&integer::mask(16));
  }
  L00780b10: { // 0x780b10: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00780b13: { // 0x780b13: 8b4dfc MOV ECX,dword ptr [EBP + -0x4]
    s.cx = m.r32((s.bp-0x00000004u));
  }
  L00780b16: { // 0x780b16: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  L00780b19: { // 0x780b19: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00780b1a: { // 0x780b1a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780b1b: { // 0x780b1b: ff31 PUSH dword ptr [ECX]
    f.push(m,m.r32((s.cx)));
  }
  L00780b1d: { // 0x780b1d: e8ecf8ffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7867170u); flags=s.arithmetic_flags;
  }
  L00780b22: { // 0x780b22: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00780b25: { // 0x780b25: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00780b27: { // 0x780b27: 7406 JZ 0x00780b2f
    if(integer::condition("JZ",flags)) goto L00780b2f;
  }
  L00780b29: { // 0x780b29: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  L00780b2c: { // 0x780b2c: 66ff00 INC word ptr [EAX]
    m.w16((s.ax), integer::increment(m.r16((s.ax)),16,flags));
  }
  L00780b2f: { // 0x780b2f: 8345f802 ADD dword ptr [EBP + -0x8],0x2
    m.w32((s.bp-0x00000008u), integer::add(m.r32((s.bp-0x00000008u)),0x00000002u,32,flags));
  }
  L00780b33: { // 0x780b33: 836df402 SUB dword ptr [EBP + -0xc],0x2
    m.w32((s.bp-0x0000000cu), integer::sub(m.r32((s.bp-0x0000000cu)),0x00000002u,32,flags));
  }
  L00780b37: { // 0x780b37: ff4de8 DEC dword ptr [EBP + -0x18]
    m.w32((s.bp-0x00000018u), integer::decrement(m.r32((s.bp-0x00000018u)),32,flags));
  }
  L00780b3a: { // 0x780b3a: 75c8 JNZ 0x00780b04
    if(integer::condition("JNZ",flags)) goto L00780b04;
  }
  L00780b3c: { // 0x780b3c: 8345fc02 ADD dword ptr [EBP + -0x4],0x2
    m.w32((s.bp-0x00000004u), integer::add(m.r32((s.bp-0x00000004u)),0x00000002u,32,flags));
  }
  L00780b40: { // 0x780b40: ff45f0 INC dword ptr [EBP + -0x10]
    m.w32((s.bp-0x00000010u), integer::increment(m.r32((s.bp-0x00000010u)),32,flags));
  }
  L00780b43: { // 0x780b43: ff4d0c DEC dword ptr [EBP + 0xc]
    m.w32((s.bp+0x0000000cu), integer::decrement(m.r32((s.bp+0x0000000cu)),32,flags));
  }
  L00780b46: { // 0x780b46: 837d0c00 CMP dword ptr [EBP + 0xc],0x0
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),0x00000000u,32,flags);
  }
  L00780b4a: { // 0x780b4a: 7f9c JG 0x00780ae8
    if(integer::condition("JG",flags)) goto L00780ae8;
  }
  L00780b4c: { // 0x780b4c: 81450802c00000 ADD dword ptr [EBP + 0x8],0xc002
    m.w32((s.bp+0x00000008u), integer::add(m.r32((s.bp+0x00000008u)),0x0000c002u,32,flags));
  }
  L00780b53: { // 0x780b53: 66837d0800 CMP word ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r16((s.bp+0x00000008u)),0x00000000u,16,flags);
  }
  L00780b58: { // 0x780b58: 7e25 JLE 0x00780b7f
    if(integer::condition("JLE",flags)) goto L00780b7f;
  }
  L00780b5a: { // 0x780b5a: f645e780 TEST byte ptr [EBP + -0x19],0x80
    (void)integer::logical((m.r8((s.bp-0x00000019u)))&(0x00000080u),8,flags);
  }
  L00780b5e: { // 0x780b5e: 7518 JNZ 0x00780b78
    if(integer::condition("JNZ",flags)) goto L00780b78;
  }
  L00780b60: { // 0x780b60: 8d45dc LEA EAX,[EBP + -0x24]
    s.ax = (s.bp-0x00000024u);
  }
  L00780b63: { // 0x780b63: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780b64: { // 0x780b64: e824f9ffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7867241u); flags=s.arithmetic_flags;
  }
  L00780b69: { // 0x780b69: 814508ffff0000 ADD dword ptr [EBP + 0x8],0xffff
    m.w32((s.bp+0x00000008u), integer::add(m.r32((s.bp+0x00000008u)),0x0000ffffu,32,flags));
  }
  L00780b70: { // 0x780b70: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780b71: { // 0x780b71: 66837d0800 CMP word ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r16((s.bp+0x00000008u)),0x00000000u,16,flags);
  }
  L00780b76: { // 0x780b76: 7fe2 JG 0x00780b5a
    if(integer::condition("JG",flags)) goto L00780b5a;
  }
  L00780b78: { // 0x780b78: 66837d0800 CMP word ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r16((s.bp+0x00000008u)),0x00000000u,16,flags);
  }
  L00780b7d: { // 0x780b7d: 7f39 JG 0x00780bb8
    if(integer::condition("JG",flags)) goto L00780bb8;
  }
  L00780b7f: { // 0x780b7f: 814508ffff0000 ADD dword ptr [EBP + 0x8],0xffff
    m.w32((s.bp+0x00000008u), integer::add(m.r32((s.bp+0x00000008u)),0x0000ffffu,32,flags));
  }
  L00780b86: { // 0x780b86: 66837d0800 CMP word ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r16((s.bp+0x00000008u)),0x00000000u,16,flags);
  }
  L00780b8b: { // 0x780b8b: 7d2b JGE 0x00780bb8
    if(integer::condition("JGE",flags)) goto L00780bb8;
  }
  L00780b8d: { // 0x780b8d: 0fbf4508 MOVSX EAX,word ptr [EBP + 0x8]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000008u)),16));
  }
  L00780b91: { // 0x780b91: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00780b93: { // 0x780b93: 014508 ADD dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), integer::add(m.r32((s.bp+0x00000008u)),s.ax,32,flags));
  }
  L00780b96: { // 0x780b96: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00780b98: { // 0x780b98: f645dc01 TEST byte ptr [EBP + -0x24],0x1
    (void)integer::logical((m.r8((s.bp-0x00000024u)))&(0x00000001u),8,flags);
  }
  L00780b9c: { // 0x780b9c: 7403 JZ 0x00780ba1
    if(integer::condition("JZ",flags)) goto L00780ba1;
  }
  L00780b9e: { // 0x780b9e: ff45ec INC dword ptr [EBP + -0x14]
    m.w32((s.bp-0x00000014u), integer::increment(m.r32((s.bp-0x00000014u)),32,flags));
  }
  L00780ba1: { // 0x780ba1: 8d45dc LEA EAX,[EBP + -0x24]
    s.ax = (s.bp-0x00000024u);
  }
  L00780ba4: { // 0x780ba4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780ba5: { // 0x780ba5: e811f9ffff CALL 0x007804bb
    s.arithmetic_flags=flags; invoke(m,s,f,0x007804bbu,7867306u); flags=s.arithmetic_flags;
  }
  L00780baa: { // 0x780baa: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00780bab: { // 0x780bab: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780bac: { // 0x780bac: 75ea JNZ 0x00780b98
    if(integer::condition("JNZ",flags)) goto L00780b98;
  }
  L00780bae: { // 0x780bae: 837dec00 CMP dword ptr [EBP + -0x14],0x0
    (void)integer::sub(m.r32((s.bp-0x00000014u)),0x00000000u,32,flags);
  }
  L00780bb2: { // 0x780bb2: 7404 JZ 0x00780bb8
    if(integer::condition("JZ",flags)) goto L00780bb8;
  }
  L00780bb4: { // 0x780bb4: 804ddc01 OR byte ptr [EBP + -0x24],0x1
    m.w8((s.bp-0x00000024u), integer::logical((m.r8((s.bp-0x00000024u)))|(0x00000001u),8,flags));
  }
  L00780bb8: { // 0x780bb8: 66817ddc0080 CMP word ptr [EBP + -0x24],0x8000
    (void)integer::sub(m.r16((s.bp-0x00000024u)),0x00008000u,16,flags);
  }
  L00780bbe: { // 0x780bbe: 770f JA 0x00780bcf
    if(integer::condition("JA",flags)) goto L00780bcf;
  }
  L00780bc0: { // 0x780bc0: 8b45dc MOV EAX,dword ptr [EBP + -0x24]
    s.ax = m.r32((s.bp-0x00000024u));
  }
  L00780bc3: { // 0x780bc3: 25ffff0100 AND EAX,0x1ffff
    s.ax = integer::logical((s.ax)&(0x0001ffffu),32,flags);
  }
  L00780bc8: { // 0x780bc8: 3d00800100 CMP EAX,0x18000
    (void)integer::sub(s.ax,0x00018000u,32,flags);
  }
  L00780bcd: { // 0x780bcd: 7535 JNZ 0x00780c04
    if(integer::condition("JNZ",flags)) goto L00780c04;
  }
  L00780bcf: { // 0x780bcf: 837ddeff CMP dword ptr [EBP + -0x22],-0x1
    (void)integer::sub(m.r32((s.bp-0x00000022u)),0xffffffffu,32,flags);
  }
  L00780bd3: { // 0x780bd3: 752c JNZ 0x00780c01
    if(integer::condition("JNZ",flags)) goto L00780c01;
  }
  L00780bd5: { // 0x780bd5: 8365de00 AND dword ptr [EBP + -0x22],0x0
    m.w32((s.bp-0x00000022u), integer::logical((m.r32((s.bp-0x00000022u)))&(0x00000000u),32,flags));
  }
  L00780bd9: { // 0x780bd9: 837de2ff CMP dword ptr [EBP + -0x1e],-0x1
    (void)integer::sub(m.r32((s.bp-0x0000001eu)),0xffffffffu,32,flags);
  }
  L00780bdd: { // 0x780bdd: 751d JNZ 0x00780bfc
    if(integer::condition("JNZ",flags)) goto L00780bfc;
  }
  L00780bdf: { // 0x780bdf: 8365e200 AND dword ptr [EBP + -0x1e],0x0
    m.w32((s.bp-0x0000001eu), integer::logical((m.r32((s.bp-0x0000001eu)))&(0x00000000u),32,flags));
  }
  L00780be3: { // 0x780be3: 66817de6ffff CMP word ptr [EBP + -0x1a],0xffff
    (void)integer::sub(m.r16((s.bp-0x0000001au)),0x0000ffffu,16,flags);
  }
  L00780be9: { // 0x780be9: 750b JNZ 0x00780bf6
    if(integer::condition("JNZ",flags)) goto L00780bf6;
  }
  L00780beb: { // 0x780beb: ff4508 INC dword ptr [EBP + 0x8]
    m.w32((s.bp+0x00000008u), integer::increment(m.r32((s.bp+0x00000008u)),32,flags));
  }
  L00780bee: { // 0x780bee: 66c745e60080 MOV word ptr [EBP + -0x1a],0x8000
    m.w16((s.bp-0x0000001au), 0x00008000u);
  }
  L00780bf4: { // 0x780bf4: eb0e JMP 0x00780c04
    goto L00780c04;
  }
  L00780bf6: { // 0x780bf6: 66ff45e6 INC word ptr [EBP + -0x1a]
    m.w16((s.bp-0x0000001au), integer::increment(m.r16((s.bp-0x0000001au)),16,flags));
  }
  L00780bfa: { // 0x780bfa: eb08 JMP 0x00780c04
    goto L00780c04;
  }
  L00780bfc: { // 0x780bfc: ff45e2 INC dword ptr [EBP + -0x1e]
    m.w32((s.bp-0x0000001eu), integer::increment(m.r32((s.bp-0x0000001eu)),32,flags));
  }
  L00780bff: { // 0x780bff: eb03 JMP 0x00780c04
    goto L00780c04;
  }
  L00780c01: { // 0x780c01: ff45de INC dword ptr [EBP + -0x22]
    m.w32((s.bp-0x00000022u), integer::increment(m.r32((s.bp-0x00000022u)),32,flags));
  }
  L00780c04: { // 0x780c04: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00780c07: { // 0x780c07: 663dff7f CMP AX,0x7fff
    (void)integer::sub((s.ax & 0xffffu),0x00007fffu,16,flags);
  }
  L00780c0b: { // 0x780c0b: 731b JNC 0x00780c28
    if(integer::condition("JNC",flags)) goto L00780c28;
  }
  L00780c0d: { // 0x780c0d: 668b4dde MOV CX,word ptr [EBP + -0x22]
    s.cx = with_ax(s.cx, m.r16((s.bp-0x00000022u)));
  }
  L00780c11: { // 0x780c11: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  L00780c13: { // 0x780c13: 66890e MOV word ptr [ESI],CX
    m.w16((s.si), (s.cx & 0xffffu));
  }
  L00780c16: { // 0x780c16: 8b4de0 MOV ECX,dword ptr [EBP + -0x20]
    s.cx = m.r32((s.bp-0x00000020u));
  }
  L00780c19: { // 0x780c19: 894e02 MOV dword ptr [ESI + 0x2],ECX
    m.w32((s.si+0x00000002u), s.cx);
  }
  L00780c1c: { // 0x780c1c: 8b4de4 MOV ECX,dword ptr [EBP + -0x1c]
    s.cx = m.r32((s.bp-0x0000001cu));
  }
  L00780c1f: { // 0x780c1f: 894e06 MOV dword ptr [ESI + 0x6],ECX
    m.w32((s.si+0x00000006u), s.cx);
  }
  L00780c22: { // 0x780c22: 6689460a MOV word ptr [ESI + 0xa],AX
    m.w16((s.si+0x0000000au), (s.ax & 0xffffu));
  }
  L00780c26: { // 0x780c26: eb1b JMP 0x00780c43
    goto L00780c43;
  }
  L00780c28: { // 0x780c28: 66f7df NEG DI
    s.di = (s.di & 0xffff0000u) | ((integer::sub(0u,(s.di & 0xffffu),16,flags)) & 0xffffu);
  }
  L00780c2b: { // 0x780c2b: 1bff SBB EDI,EDI
    s.di = integer::sub(s.di,s.di,32,flags,flags&integer::CF);
  }
  L00780c2d: { // 0x780c2d: 83660400 AND dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), integer::logical((m.r32((s.si+0x00000004u)))&(0x00000000u),32,flags));
  }
  L00780c31: { // 0x780c31: 81e700000080 AND EDI,0x80000000
    s.di = integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L00780c37: { // 0x780c37: 81c70080ff7f ADD EDI,0x7fff8000
    s.di = integer::add(s.di,0x7fff8000u,32,flags);
  }
  L00780c3d: { // 0x780c3d: 832600 AND dword ptr [ESI],0x0
    m.w32((s.si), integer::logical((m.r32((s.si)))&(0x00000000u),32,flags));
  }
  L00780c40: { // 0x780c40: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00780c43: { // 0x780c43: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00780c44: { // 0x780c44: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00780c45: { // 0x780c45: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00780c46: { // 0x780c46: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00780c47: { // 0x780c47: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0038040e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0078040e: { // 0x78040e: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00780412: { // 0x780412: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780413: { // 0x780413: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L00780417: { // 0x780417: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00780419: { // 0x780419: 8d0c32 LEA ECX,[EDX + ESI*0x1]
    s.cx = (s.dx+(s.si * 0x00000001u));
  }
  L0078041c: { // 0x78041c: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0078041e: { // 0x78041e: 7204 JC 0x00780424
    if(integer::condition("JC",flags)) goto L00780424;
  }
  L00780420: { // 0x780420: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00780422: { // 0x780422: 7303 JNC 0x00780427
    if(integer::condition("JNC",flags)) goto L00780427;
  }
  L00780424: { // 0x780424: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00780426: { // 0x780426: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L00780427: { // 0x780427: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0078042b: { // 0x78042b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0078042c: { // 0x78042c: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0078042e: { // 0x78042e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0038048d(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0078048d: { // 0x78048d: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00780491: { // 0x780491: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780492: { // 0x780492: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00780493: { // 0x780493: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00780495: { // 0x780495: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00780498: { // 0x780498: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0078049a: { // 0x78049a: 03f6 ADD ESI,ESI
    s.si = integer::add(s.si,s.si,32,flags);
  }
  L0078049c: { // 0x78049c: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0078049e: { // 0x78049e: 8d343f LEA ESI,[EDI + EDI*0x1]
    s.si = (s.di+(s.di * 0x00000001u));
  }
  L007804a1: { // 0x7804a1: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L007804a4: { // 0x7804a4: 0bf1 OR ESI,ECX
    s.si = integer::logical((s.si)|(s.cx),32,flags);
  }
  L007804a6: { // 0x7804a6: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L007804a9: { // 0x7804a9: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L007804ab: { // 0x7804ab: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L007804ae: { // 0x7804ae: c1ea1f SHR EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L007804b1: { // 0x7804b1: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L007804b3: { // 0x7804b3: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L007804b5: { // 0x7804b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007804b6: { // 0x7804b6: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L007804b9: { // 0x7804b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007804ba: { // 0x7804ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_003804bb(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007804bb: { // 0x7804bb: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L007804bf: { // 0x7804bf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007804c0: { // 0x7804c0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007804c1: { // 0x7804c1: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L007804c4: { // 0x7804c4: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L007804c7: { // 0x7804c7: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L007804c9: { // 0x7804c9: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L007804cb: { // 0x7804cb: c1e61f SHL ESI,0x1f
    s.si = integer::shift(s.si,0x0000001fu,32,flags,integer::Shift::left);
  }
  L007804ce: { // 0x7804ce: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L007804d0: { // 0x7804d0: 0bce OR ECX,ESI
    s.cx = integer::logical((s.cx)|(s.si),32,flags);
  }
  L007804d2: { // 0x7804d2: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L007804d5: { // 0x7804d5: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L007804d7: { // 0x7804d7: c1e71f SHL EDI,0x1f
    s.di = integer::shift(s.di,0x0000001fu,32,flags,integer::Shift::left);
  }
  L007804da: { // 0x7804da: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L007804dc: { // 0x7804dc: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L007804de: { // 0x7804de: 0bcf OR ECX,EDI
    s.cx = integer::logical((s.cx)|(s.di),32,flags);
  }
  L007804e0: { // 0x7804e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007804e1: { // 0x7804e1: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L007804e4: { // 0x7804e4: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L007804e6: { // 0x7804e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007804e7: { // 0x7804e7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0038042f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0078042f: { // 0x78042f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780430: { // 0x780430: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00780434: { // 0x780434: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00780435: { // 0x780435: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00780439: { // 0x780439: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0078043a: { // 0x78043a: ff37 PUSH dword ptr [EDI]
    f.push(m,m.r32((s.di)));
  }
  L0078043c: { // 0x78043c: ff36 PUSH dword ptr [ESI]
    f.push(m,m.r32((s.si)));
  }
  L0078043e: { // 0x78043e: e8cbffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865411u); flags=s.arithmetic_flags;
  }
  L00780443: { // 0x780443: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00780446: { // 0x780446: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00780448: { // 0x780448: 7417 JZ 0x00780461
    if(integer::condition("JZ",flags)) goto L00780461;
  }
  L0078044a: { // 0x78044a: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0078044d: { // 0x78044d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078044e: { // 0x78044e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00780450: { // 0x780450: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  L00780452: { // 0x780452: e8b7ffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865431u); flags=s.arithmetic_flags;
  }
  L00780457: { // 0x780457: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0078045a: { // 0x78045a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0078045c: { // 0x78045c: 7403 JZ 0x00780461
    if(integer::condition("JZ",flags)) goto L00780461;
  }
  L0078045e: { // 0x78045e: ff4608 INC dword ptr [ESI + 0x8]
    m.w32((s.si+0x00000008u), integer::increment(m.r32((s.si+0x00000008u)),32,flags));
  }
  L00780461: { // 0x780461: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L00780464: { // 0x780464: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780465: { // 0x780465: ff7704 PUSH dword ptr [EDI + 0x4]
    f.push(m,m.r32((s.di+0x00000004u)));
  }
  L00780468: { // 0x780468: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  L0078046a: { // 0x78046a: e89fffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865455u); flags=s.arithmetic_flags;
  }
  L0078046f: { // 0x78046f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00780472: { // 0x780472: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00780474: { // 0x780474: 7403 JZ 0x00780479
    if(integer::condition("JZ",flags)) goto L00780479;
  }
  L00780476: { // 0x780476: ff4608 INC dword ptr [ESI + 0x8]
    m.w32((s.si+0x00000008u), integer::increment(m.r32((s.si+0x00000008u)),32,flags));
  }
  L00780479: { // 0x780479: 8d4608 LEA EAX,[ESI + 0x8]
    s.ax = (s.si+0x00000008u);
  }
  L0078047c: { // 0x78047c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078047d: { // 0x78047d: ff7708 PUSH dword ptr [EDI + 0x8]
    f.push(m,m.r32((s.di+0x00000008u)));
  }
  L00780480: { // 0x780480: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  L00780482: { // 0x780482: e887ffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865479u); flags=s.arithmetic_flags;
  }
  L00780487: { // 0x780487: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0078048a: { // 0x78048a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0078048b: { // 0x78048b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0078048c: { // 0x78048c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void f_003805af(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007805af: { // 0x7805af: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007805b0: { // 0x7805b0: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L007805b2: { // 0x7805b2: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L007805b5: { // 0x7805b5: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L007805b8: { // 0x7805b8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007805b9: { // 0x7805b9: 8b5d1c MOV EBX,dword ptr [EBP + 0x1c]
    s.bx = m.r32((s.bp+0x0000001cu));
  }
  L007805bc: { // 0x7805bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007805bd: { // 0x7805bd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007805bf: { // 0x7805bf: beff7f0000 MOV ESI,0x7fff
    s.si = 0x00007fffu;
  }
  L007805c4: { // 0x7805c4: 81e100800000 AND ECX,0x8000
    s.cx = integer::logical((s.cx)&(0x00008000u),32,flags);
  }
  L007805ca: { // 0x7805ca: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L007805cc: { // 0x7805cc: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L007805cf: { // 0x7805cf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007805d0: { // 0x7805d0: c645e4cc MOV byte ptr [EBP + -0x1c],0xcc
    m.w8((s.bp-0x0000001cu), 0x000000ccu);
  }
  L007805d4: { // 0x7805d4: c645e5cc MOV byte ptr [EBP + -0x1b],0xcc
    m.w8((s.bp-0x0000001bu), 0x000000ccu);
  }
  L007805d8: { // 0x7805d8: c645e6cc MOV byte ptr [EBP + -0x1a],0xcc
    m.w8((s.bp-0x0000001au), 0x000000ccu);
  }
  L007805dc: { // 0x7805dc: c645e7cc MOV byte ptr [EBP + -0x19],0xcc
    m.w8((s.bp-0x00000019u), 0x000000ccu);
  }
  L007805e0: { // 0x7805e0: c645e8cc MOV byte ptr [EBP + -0x18],0xcc
    m.w8((s.bp-0x00000018u), 0x000000ccu);
  }
  L007805e4: { // 0x7805e4: c645e9cc MOV byte ptr [EBP + -0x17],0xcc
    m.w8((s.bp-0x00000017u), 0x000000ccu);
  }
  L007805e8: { // 0x7805e8: c645eacc MOV byte ptr [EBP + -0x16],0xcc
    m.w8((s.bp-0x00000016u), 0x000000ccu);
  }
  L007805ec: { // 0x7805ec: c645ebcc MOV byte ptr [EBP + -0x15],0xcc
    m.w8((s.bp-0x00000015u), 0x000000ccu);
  }
  L007805f0: { // 0x7805f0: c645eccc MOV byte ptr [EBP + -0x14],0xcc
    m.w8((s.bp-0x00000014u), 0x000000ccu);
  }
  L007805f4: { // 0x7805f4: c645edcc MOV byte ptr [EBP + -0x13],0xcc
    m.w8((s.bp-0x00000013u), 0x000000ccu);
  }
  L007805f8: { // 0x7805f8: c645eefb MOV byte ptr [EBP + -0x12],0xfb
    m.w8((s.bp-0x00000012u), 0x000000fbu);
  }
  L007805fc: { // 0x7805fc: c645ef3f MOV byte ptr [EBP + -0x11],0x3f
    m.w8((s.bp-0x00000011u), 0x0000003fu);
  }
  L00780600: { // 0x780600: c745fc01000000 MOV dword ptr [EBP + -0x4],0x1
    m.w32((s.bp-0x00000004u), 0x00000001u);
  }
  L00780607: { // 0x780607: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00780609: { // 0x780609: 7406 JZ 0x00780611
    if(integer::condition("JZ",flags)) goto L00780611;
  }
  L0078060b: { // 0x78060b: c643022d MOV byte ptr [EBX + 0x2],0x2d
    m.w8((s.bx+0x00000002u), 0x0000002du);
  }
  L0078060f: { // 0x78060f: eb04 JMP 0x00780615
    goto L00780615;
  }
  L00780611: { // 0x780611: c6430220 MOV byte ptr [EBX + 0x2],0x20
    m.w8((s.bx+0x00000002u), 0x00000020u);
  }
  L00780615: { // 0x780615: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  L00780618: { // 0x780618: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L0078061b: { // 0x78061b: 751e JNZ 0x0078063b
    if(integer::condition("JNZ",flags)) goto L0078063b;
  }
  L0078061d: { // 0x78061d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0078061f: { // 0x78061f: 751a JNZ 0x0078063b
    if(integer::condition("JNZ",flags)) goto L0078063b;
  }
  L00780621: { // 0x780621: 397d08 CMP dword ptr [EBP + 0x8],EDI
    (void)integer::sub(m.r32((s.bp+0x00000008u)),s.di,32,flags);
  }
  L00780624: { // 0x780624: 7515 JNZ 0x0078063b
    if(integer::condition("JNZ",flags)) goto L0078063b;
  }
  L00780626: { // 0x780626: 66832300 AND word ptr [EBX],0x0
    m.w16((s.bx), integer::logical((m.r16((s.bx)))&(0x00000000u),16,flags));
  }
  L0078062a: { // 0x78062a: c6430220 MOV byte ptr [EBX + 0x2],0x20
    m.w8((s.bx+0x00000002u), 0x00000020u);
  }
  L0078062e: { // 0x78062e: c6430301 MOV byte ptr [EBX + 0x3],0x1
    m.w8((s.bx+0x00000003u), 0x00000001u);
  }
  L00780632: { // 0x780632: c6430430 MOV byte ptr [EBX + 0x4],0x30
    m.w8((s.bx+0x00000004u), 0x00000030u);
  }
  L00780636: { // 0x780636: e9fe010000 JMP 0x00780839
    goto L00780839;
  }
  L0078063b: { // 0x78063b: 663bd6 CMP DX,SI
    (void)integer::sub((s.dx & 0xffffu),(s.si & 0xffffu),16,flags);
  }
  L0078063e: { // 0x78063e: 757a JNZ 0x007806ba
    if(integer::condition("JNZ",flags)) goto L007806ba;
  }
  L00780640: { // 0x780640: b800000080 MOV EAX,0x80000000
    s.ax = 0x80000000u;
  }
  L00780645: { // 0x780645: 66c7030100 MOV word ptr [EBX],0x1
    m.w16((s.bx), 0x00000001u);
  }
  L0078064a: { // 0x78064a: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0078064c: { // 0x78064c: 7506 JNZ 0x00780654
    if(integer::condition("JNZ",flags)) goto L00780654;
  }
  L0078064e: { // 0x78064e: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  L00780652: { // 0x780652: 740f JZ 0x00780663
    if(integer::condition("JZ",flags)) goto L00780663;
  }
  L00780654: { // 0x780654: f7c700000040 TEST EDI,0x40000000
    (void)integer::logical((s.di)&(0x40000000u),32,flags);
  }
  L0078065a: { // 0x78065a: 7507 JNZ 0x00780663
    if(integer::condition("JNZ",flags)) goto L00780663;
  }
  L0078065c: { // 0x78065c: 687cd47900 PUSH 0x79d47c
    f.push(m,0x0079d47cu);
  }
  L00780661: { // 0x780661: eb46 JMP 0x007806a9
    goto L007806a9;
  }
  L00780663: { // 0x780663: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L00780666: { // 0x780666: 7415 JZ 0x0078067d
    if(integer::condition("JZ",flags)) goto L0078067d;
  }
  L00780668: { // 0x780668: 81ff000000c0 CMP EDI,0xc0000000
    (void)integer::sub(s.di,0xc0000000u,32,flags);
  }
  L0078066e: { // 0x78066e: 750d JNZ 0x0078067d
    if(integer::condition("JNZ",flags)) goto L0078067d;
  }
  L00780670: { // 0x780670: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  L00780674: { // 0x780674: 752e JNZ 0x007806a4
    if(integer::condition("JNZ",flags)) goto L007806a4;
  }
  L00780676: { // 0x780676: 6874d47900 PUSH 0x79d474
    f.push(m,0x0079d474u);
  }
  L0078067b: { // 0x78067b: eb0f JMP 0x0078068c
    goto L0078068c;
  }
  L0078067d: { // 0x78067d: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0078067f: { // 0x78067f: 7523 JNZ 0x007806a4
    if(integer::condition("JNZ",flags)) goto L007806a4;
  }
  L00780681: { // 0x780681: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  L00780685: { // 0x780685: 751d JNZ 0x007806a4
    if(integer::condition("JNZ",flags)) goto L007806a4;
  }
  L00780687: { // 0x780687: 686cd47900 PUSH 0x79d46c
    f.push(m,0x0079d46cu);
  }
  L0078068c: { // 0x78068c: 8d4304 LEA EAX,[EBX + 0x4]
    s.ax = (s.bx+0x00000004u);
  }
  L0078068f: { // 0x78068f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780690: { // 0x780690: e87b89ffff CALL 0x00779010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00779010u,7866005u); flags=s.arithmetic_flags;
  }
  L00780695: { // 0x780695: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780696: { // 0x780696: c6430305 MOV byte ptr [EBX + 0x3],0x5
    m.w8((s.bx+0x00000003u), 0x00000005u);
  }
  L0078069a: { // 0x78069a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078069b: { // 0x78069b: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  L0078069f: { // 0x78069f: e96e010000 JMP 0x00780812
    goto L00780812;
  }
  L007806a4: { // 0x7806a4: 6864d47900 PUSH 0x79d464
    f.push(m,0x0079d464u);
  }
  L007806a9: { // 0x7806a9: 8d4304 LEA EAX,[EBX + 0x4]
    s.ax = (s.bx+0x00000004u);
  }
  L007806ac: { // 0x7806ac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007806ad: { // 0x7806ad: e85e89ffff CALL 0x00779010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00779010u,7866034u); flags=s.arithmetic_flags;
  }
  L007806b2: { // 0x7806b2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007806b3: { // 0x7806b3: c6430306 MOV byte ptr [EBX + 0x3],0x6
    m.w8((s.bx+0x00000003u), 0x00000006u);
  }
  L007806b7: { // 0x7806b7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007806b8: { // 0x7806b8: ebe1 JMP 0x0078069b
    goto L0078069b;
  }
  L007806ba: { // 0x7806ba: 0fb7c2 MOVZX EAX,DX
    s.ax = ((s.dx & 0xffffu)&integer::mask(16));
  }
  L007806bd: { // 0x7806bd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L007806bf: { // 0x7806bf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L007806c1: { // 0x7806c1: c1e918 SHR ECX,0x18
    s.cx = integer::shift(s.cx,0x00000018u,32,flags,integer::Shift::right);
  }
  L007806c4: { // 0x7806c4: 69c0104d0000 IMUL EAX,EAX,0x4d10
    s.ax = integer::imul(s.ax,0x00004d10u,32,flags);
  }
  L007806ca: { // 0x7806ca: c1ee08 SHR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::right);
  }
  L007806cd: { // 0x7806cd: 668365f000 AND word ptr [EBP + -0x10],0x0
    m.w16((s.bp-0x00000010u), integer::logical((m.r16((s.bp-0x00000010u)))&(0x00000000u),16,flags));
  }
  L007806d2: { // 0x7806d2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L007806d4: { // 0x7806d4: 8d0c4e LEA ECX,[ESI + ECX*0x2]
    s.cx = (s.si+(s.cx * 0x00000002u));
  }
  L007806d7: { // 0x7806d7: 668955fa MOV word ptr [EBP + -0x6],DX
    m.w16((s.bp-0x00000006u), (s.dx & 0xffffu));
  }
  L007806db: { // 0x7806db: 6bc94d IMUL ECX,ECX,0x4d
    s.cx = integer::imul(s.cx,0x0000004du,32,flags);
  }
  L007806de: { // 0x7806de: 897df6 MOV dword ptr [EBP + -0xa],EDI
    m.w32((s.bp-0x0000000au), s.di);
  }
  L007806e1: { // 0x7806e1: 8db4010cedbcec LEA ESI,[ECX + EAX*0x1 + 0xecbced0c]
    s.si = (s.cx+(s.ax * 0x00000001u)+0xecbced0cu);
  }
  L007806e8: { // 0x7806e8: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L007806eb: { // 0x7806eb: c1fe10 SAR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
  L007806ee: { // 0x7806ee: 8945f2 MOV dword ptr [EBP + -0xe],EAX
    m.w32((s.bp-0x0000000eu), s.ax);
  }
  L007806f1: { // 0x7806f1: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L007806f4: { // 0x7806f4: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L007806f6: { // 0x7806f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007806f7: { // 0x7806f7: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007806fa: { // 0x7806fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007806fb: { // 0x7806fb: e848050000 CALL 0x00780c48
    s.arithmetic_flags=flags; invoke(m,s,f,0x00780c48u,7866112u); flags=s.arithmetic_flags;
  }
  L00780700: { // 0x780700: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00780703: { // 0x780703: 66817dfaff3f CMP word ptr [EBP + -0x6],0x3fff
    (void)integer::sub(m.r16((s.bp-0x00000006u)),0x00003fffu,16,flags);
  }
  L00780709: { // 0x780709: 7210 JC 0x0078071b
    if(integer::condition("JC",flags)) goto L0078071b;
  }
  L0078070b: { // 0x78070b: 8d45e4 LEA EAX,[EBP + -0x1c]
    s.ax = (s.bp-0x0000001cu);
  }
  L0078070e: { // 0x78070e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0078070f: { // 0x78070f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780710: { // 0x780710: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780713: { // 0x780713: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780714: { // 0x780714: e80f030000 CALL 0x00780a28
    s.arithmetic_flags=flags; invoke(m,s,f,0x00780a28u,7866137u); flags=s.arithmetic_flags;
  }
  L00780719: { // 0x780719: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078071a: { // 0x78071a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078071b: { // 0x78071b: f6451801 TEST byte ptr [EBP + 0x18],0x1
    (void)integer::logical((m.r8((s.bp+0x00000018u)))&(0x00000001u),8,flags);
  }
  L0078071f: { // 0x78071f: 668933 MOV word ptr [EBX],SI
    m.w16((s.bx), (s.si & 0xffffu));
  }
  L00780722: { // 0x780722: 7411 JZ 0x00780735
    if(integer::condition("JZ",flags)) goto L00780735;
  }
  L00780724: { // 0x780724: 8b7d14 MOV EDI,dword ptr [EBP + 0x14]
    s.di = m.r32((s.bp+0x00000014u));
  }
  L00780727: { // 0x780727: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0078072a: { // 0x78072a: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0078072c: { // 0x78072c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0078072e: { // 0x78072e: 7f08 JG 0x00780738
    if(integer::condition("JG",flags)) goto L00780738;
  }
  L00780730: { // 0x780730: e9f1feffff JMP 0x00780626
    goto L00780626;
  }
  L00780735: { // 0x780735: 8b7d14 MOV EDI,dword ptr [EBP + 0x14]
    s.di = m.r32((s.bp+0x00000014u));
  }
  L00780738: { // 0x780738: 83ff15 CMP EDI,0x15
    (void)integer::sub(s.di,0x00000015u,32,flags);
  }
  L0078073b: { // 0x78073b: 7e03 JLE 0x00780740
    if(integer::condition("JLE",flags)) goto L00780740;
  }
  L0078073d: { // 0x78073d: 6a15 PUSH 0x15
    f.push(m,0x00000015u);
  }
  L0078073f: { // 0x78073f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00780740: { // 0x780740: 0fb775fa MOVZX ESI,word ptr [EBP + -0x6]
    s.si = (m.r16((s.bp-0x00000006u))&integer::mask(16));
  }
  L00780744: { // 0x780744: 81eefe3f0000 SUB ESI,0x3ffe
    s.si = integer::sub(s.si,0x00003ffeu,32,flags);
  }
  L0078074a: { // 0x78074a: 668365fa00 AND word ptr [EBP + -0x6],0x0
    m.w16((s.bp-0x00000006u), integer::logical((m.r16((s.bp-0x00000006u)))&(0x00000000u),16,flags));
  }
  L0078074f: { // 0x78074f: c7451c08000000 MOV dword ptr [EBP + 0x1c],0x8
    m.w32((s.bp+0x0000001cu), 0x00000008u);
  }
  L00780756: { // 0x780756: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780759: { // 0x780759: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078075a: { // 0x78075a: e82efdffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866207u); flags=s.arithmetic_flags;
  }
  L0078075f: { // 0x78075f: ff4d1c DEC dword ptr [EBP + 0x1c]
    m.w32((s.bp+0x0000001cu), integer::decrement(m.r32((s.bp+0x0000001cu)),32,flags));
  }
  L00780762: { // 0x780762: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780763: { // 0x780763: 75f1 JNZ 0x00780756
    if(integer::condition("JNZ",flags)) goto L00780756;
  }
  L00780765: { // 0x780765: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00780767: { // 0x780767: 7d17 JGE 0x00780780
    if(integer::condition("JGE",flags)) goto L00780780;
  }
  L00780769: { // 0x780769: f7de NEG ESI
    s.si = integer::sub(0u,s.si,32,flags);
  }
  L0078076b: { // 0x78076b: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L00780771: { // 0x780771: 7e0d JLE 0x00780780
    if(integer::condition("JLE",flags)) goto L00780780;
  }
  L00780773: { // 0x780773: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780776: { // 0x780776: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780777: { // 0x780777: e83ffdffff CALL 0x007804bb
    s.arithmetic_flags=flags; invoke(m,s,f,0x007804bbu,7866236u); flags=s.arithmetic_flags;
  }
  L0078077c: { // 0x78077c: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0078077d: { // 0x78077d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078077e: { // 0x78077e: 75f3 JNZ 0x00780773
    if(integer::condition("JNZ",flags)) goto L00780773;
  }
  L00780780: { // 0x780780: 8d4f01 LEA ECX,[EDI + 0x1]
    s.cx = (s.di+0x00000001u);
  }
  L00780783: { // 0x780783: 8d4304 LEA EAX,[EBX + 0x4]
    s.ax = (s.bx+0x00000004u);
  }
  L00780786: { // 0x780786: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00780788: { // 0x780788: 89451c MOV dword ptr [EBP + 0x1c],EAX
    m.w32((s.bp+0x0000001cu), s.ax);
  }
  L0078078b: { // 0x78078b: 7e50 JLE 0x007807dd
    if(integer::condition("JLE",flags)) goto L007807dd;
  }
  L0078078d: { // 0x78078d: 894d14 MOV dword ptr [EBP + 0x14],ECX
    m.w32((s.bp+0x00000014u), s.cx);
  }
  L00780790: { // 0x780790: 8d75f0 LEA ESI,[EBP + -0x10]
    s.si = (s.bp-0x00000010u);
  }
  L00780793: { // 0x780793: 8d7d08 LEA EDI,[EBP + 0x8]
    s.di = (s.bp+0x00000008u);
  }
  L00780796: { // 0x780796: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780797: { // 0x780797: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780798: { // 0x780798: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L0078079b: { // 0x78079b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078079c: { // 0x78079c: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L0078079d: { // 0x78079d: e8ebfcffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866274u); flags=s.arithmetic_flags;
  }
  L007807a2: { // 0x7807a2: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007807a5: { // 0x7807a5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807a6: { // 0x7807a6: e8e2fcffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866283u); flags=s.arithmetic_flags;
  }
  L007807ab: { // 0x7807ab: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  L007807ae: { // 0x7807ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807af: { // 0x7807af: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007807b2: { // 0x7807b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807b3: { // 0x7807b3: e877fcffff CALL 0x0078042f
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078042fu,7866296u); flags=s.arithmetic_flags;
  }
  L007807b8: { // 0x7807b8: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007807bb: { // 0x7807bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807bc: { // 0x7807bc: e8ccfcffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866305u); flags=s.arithmetic_flags;
  }
  L007807c1: { // 0x7807c1: 8a45fb MOV AL,byte ptr [EBP + -0x5]
    s.ax = with_al(s.ax, m.r8((s.bp-0x00000005u)));
  }
  L007807c4: { // 0x7807c4: 8b4d1c MOV ECX,dword ptr [EBP + 0x1c]
    s.cx = m.r32((s.bp+0x0000001cu));
  }
  L007807c7: { // 0x7807c7: 8065fb00 AND byte ptr [EBP + -0x5],0x0
    m.w8((s.bp-0x00000005u), integer::logical((m.r8((s.bp-0x00000005u)))&(0x00000000u),8,flags));
  }
  L007807cb: { // 0x7807cb: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L007807ce: { // 0x7807ce: 0430 ADD AL,0x30
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000030u,8,flags));
  }
  L007807d0: { // 0x7807d0: ff451c INC dword ptr [EBP + 0x1c]
    m.w32((s.bp+0x0000001cu), integer::increment(m.r32((s.bp+0x0000001cu)),32,flags));
  }
  L007807d3: { // 0x7807d3: ff4d14 DEC dword ptr [EBP + 0x14]
    m.w32((s.bp+0x00000014u), integer::decrement(m.r32((s.bp+0x00000014u)),32,flags));
  }
  L007807d6: { // 0x7807d6: 8801 MOV byte ptr [ECX],AL
    m.w8((s.cx), (s.ax & 0xffu));
  }
  L007807d8: { // 0x7807d8: 75b6 JNZ 0x00780790
    if(integer::condition("JNZ",flags)) goto L00780790;
  }
  L007807da: { // 0x7807da: 8b451c MOV EAX,dword ptr [EBP + 0x1c]
    s.ax = m.r32((s.bp+0x0000001cu));
  }
  L007807dd: { // 0x7807dd: 8a48ff MOV CL,byte ptr [EAX + -0x1]
    s.cx = with_al(s.cx, m.r8((s.ax-0x00000001u)));
  }
  L007807e0: { // 0x7807e0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007807e1: { // 0x7807e1: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007807e2: { // 0x7807e2: 80f935 CMP CL,0x35
    (void)integer::sub((s.cx & 0xffu),0x00000035u,8,flags);
  }
  L007807e5: { // 0x7807e5: 8d4b04 LEA ECX,[EBX + 0x4]
    s.cx = (s.bx+0x00000004u);
  }
  L007807e8: { // 0x7807e8: 7c30 JL 0x0078081a
    if(integer::condition("JL",flags)) goto L0078081a;
  }
  L007807ea: { // 0x7807ea: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L007807ec: { // 0x7807ec: 720f JC 0x007807fd
    if(integer::condition("JC",flags)) goto L007807fd;
  }
  L007807ee: { // 0x7807ee: 803839 CMP byte ptr [EAX],0x39
    (void)integer::sub(m.r8((s.ax)),0x00000039u,8,flags);
  }
  L007807f1: { // 0x7807f1: 7506 JNZ 0x007807f9
    if(integer::condition("JNZ",flags)) goto L007807f9;
  }
  L007807f3: { // 0x7807f3: c60030 MOV byte ptr [EAX],0x30
    m.w8((s.ax), 0x00000030u);
  }
  L007807f6: { // 0x7807f6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007807f7: { // 0x7807f7: ebf1 JMP 0x007807ea
    goto L007807ea;
  }
  L007807f9: { // 0x7807f9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L007807fb: { // 0x7807fb: 7304 JNC 0x00780801
    if(integer::condition("JNC",flags)) goto L00780801;
  }
  L007807fd: { // 0x7807fd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L007807fe: { // 0x7807fe: 66ff03 INC word ptr [EBX]
    m.w16((s.bx), integer::increment(m.r16((s.bx)),16,flags));
  }
  L00780801: { // 0x780801: fe00 INC byte ptr [EAX]
    m.w8((s.ax), integer::increment(m.r8((s.ax)),8,flags));
  }
  L00780803: { // 0x780803: 2ac3 SUB AL,BL
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00780805: { // 0x780805: 2c03 SUB AL,0x3
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000003u,8,flags));
  }
  L00780807: { // 0x780807: 884303 MOV byte ptr [EBX + 0x3],AL
    m.w8((s.bx+0x00000003u), (s.ax & 0xffu));
  }
  L0078080a: { // 0x78080a: 0fbec0 MOVSX EAX,AL
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffu),8));
  }
  L0078080d: { // 0x78080d: 8064180400 AND byte ptr [EAX + EBX*0x1 + 0x4],0x0
    m.w8((s.ax+(s.bx * 0x00000001u)+0x00000004u), integer::logical((m.r8((s.ax+(s.bx * 0x00000001u)+0x00000004u)))&(0x00000000u),8,flags));
  }
  L00780812: { // 0x780812: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  L00780815: { // 0x780815: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00780816: { // 0x780816: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00780817: { // 0x780817: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00780818: { // 0x780818: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00780819: { // 0x780819: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0078081a: { // 0x78081a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0078081c: { // 0x78081c: 720c JC 0x0078082a
    if(integer::condition("JC",flags)) goto L0078082a;
  }
  L0078081e: { // 0x78081e: 803830 CMP byte ptr [EAX],0x30
    (void)integer::sub(m.r8((s.ax)),0x00000030u,8,flags);
  }
  L00780821: { // 0x780821: 7503 JNZ 0x00780826
    if(integer::condition("JNZ",flags)) goto L00780826;
  }
  L00780823: { // 0x780823: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00780824: { // 0x780824: ebf4 JMP 0x0078081a
    goto L0078081a;
  }
  L00780826: { // 0x780826: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00780828: { // 0x780828: 73d9 JNC 0x00780803
    if(integer::condition("JNC",flags)) goto L00780803;
  }
  L0078082a: { // 0x78082a: 66832300 AND word ptr [EBX],0x0
    m.w16((s.bx), integer::logical((m.r16((s.bx)))&(0x00000000u),16,flags));
  }
  L0078082e: { // 0x78082e: c6430220 MOV byte ptr [EBX + 0x2],0x20
    m.w8((s.bx+0x00000002u), 0x00000020u);
  }
  L00780832: { // 0x780832: c6430301 MOV byte ptr [EBX + 0x3],0x1
    m.w8((s.bx+0x00000003u), 0x00000001u);
  }
  L00780836: { // 0x780836: c60130 MOV byte ptr [ECX],0x30
    m.w8((s.cx), 0x00000030u);
  }
  L00780839: { // 0x780839: 80630500 AND byte ptr [EBX + 0x5],0x0
    m.w8((s.bx+0x00000005u), integer::logical((m.r8((s.bx+0x00000005u)))&(0x00000000u),8,flags));
  }
  L0078083d: { // 0x78083d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0078083f: { // 0x78083f: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L00780840: { // 0x780840: ebd3 JMP 0x00780815
    goto L00780815;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x7805afu:f_003805af(m,s,child,{});break;
case 7847424u:f_0037be00(m,s,child,{});break;
case 7847516u:f_0037be5c(m,s,child,{});break;
case 7847305u:f_0037bd89(m,s,child,{});break;
case 7809374u:f_0037295e(m,s,child,{});break;
case 7809095u:f_00372847(m,s,child,{});break;
case 7809769u:f_00372ae9(m,s,child,{});break;
case 7835664u:f_00379010(m,s,child,{});break;
case 7819616u:f_00375160(m,s,child,{});break;
case 7793616u:f_0036ebd0(m,s,child,{});break;
case 7845408u:f_0037b620(m,s,child,{});break;
case 7867464u:f_00380c48(m,s,child,{});break;
case 7866920u:f_00380a28(m,s,child,{});break;
case 7865358u:f_0038040e(m,s,child,{});break;
case 7865485u:f_0038048d(m,s,child,{});break;
case 7865531u:f_003804bb(m,s,child,{});break;
case 7865391u:f_0038042f(m,s,child,{});break;
default:throw std::domain_error("recovery762 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00772a05(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,16> table0{236,118,0,144,64,236,118,0,108,236,118,0,144,236,118,0};leaf::Memory span0(table0.data(),0x76ec30u,16u);m.add(span0);
 std::array<std::uint8_t,32> table1{15,237,118,0,252,236,118,0,244,236,118,0,236,236,118,0,228,236,118,0,220,236,118,0,212,236,118,0,204,236,118,0};leaf::Memory span1(table1.data(),0x76ecacu,32u);m.add(span1);
 std::array<std::uint8_t,16> table2{40,237,118,0,48,237,118,0,60,237,118,0,80,237,118,0};leaf::Memory span2(table2.data(),0x76ed18u,16u);m.add(span2);
 std::array<std::uint8_t,16> table3{238,118,0,144,200,237,118,0,232,237,118,0,16,238,118,0};leaf::Memory span3(table3.data(),0x76edb8u,16u);m.add(span3);
 std::array<std::uint8_t,32> table4{100,238,118,0,108,238,118,0,116,238,118,0,124,238,118,0,132,238,118,0,140,238,118,0,148,238,118,0,167,238,118,0};leaf::Memory span4(table4.data(),0x76ee44u,32u);m.add(span4);
 std::array<std::uint8_t,16> table5{192,238,118,0,200,238,118,0,216,238,118,0,236,238,118,0};leaf::Memory span5(table5.data(),0x76eeb0u,16u);m.add(span5);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00772a05: { // 0x772a05: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00772a06: { // 0x772a06: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00772a08: { // 0x772a08: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00772a0b: { // 0x772a0b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00772a0c: { // 0x772a0c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00772a0d: { // 0x772a0d: 8d45d8 LEA EAX,[EBP + -0x28]
    s.ax = (s.bp-0x00000028u);
  }
  L00772a10: { // 0x772a10: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00772a11: { // 0x772a11: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00772a12: { // 0x772a12: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00772a15: { // 0x772a15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00772a16: { // 0x772a16: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00772a19: { // 0x772a19: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00772a1a: { // 0x772a1a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00772a1b: { // 0x772a1b: dd00 FLD double ptr [EAX]
    const auto address=(s.ax);
    s.fp.load64(read64(m,address));
  }
  L00772a1d: { // 0x772a1d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00772a20: { // 0x772a20: e8db930000 CALL 0x0077be00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077be00u,7809573u); flags=s.arithmetic_flags;
  }
  L00772a25: { // 0x772a25: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L00772a28: { // 0x772a28: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L00772a2b: { // 0x772a2b: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  L00772a2e: { // 0x772a2e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00772a30: { // 0x772a30: 837df02d CMP dword ptr [EBP + -0x10],0x2d
    (void)integer::sub(m.r32((s.bp-0x00000010u)),0x0000002du,32,flags);
  }
  L00772a34: { // 0x772a34: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00772a37: { // 0x772a37: 03450c ADD EAX,dword ptr [EBP + 0xc]
    s.ax = integer::add(s.ax,m.r32((s.bp+0x0000000cu)),32,flags);
  }
  L00772a3a: { // 0x772a3a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00772a3c: { // 0x772a3c: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00772a3f: { // 0x772a3f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00772a40: { // 0x772a40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00772a41: { // 0x772a41: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00772a42: { // 0x772a42: e842930000 CALL 0x0077bd89
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077bd89u,7809607u); flags=s.arithmetic_flags;
  }
  L00772a47: { // 0x772a47: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L00772a4a: { // 0x772a4a: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00772a4d: { // 0x772a4d: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00772a4e: { // 0x772a4e: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00772a50: { // 0x772a50: 0f9cc1 SETL CL
    s.cx = with_al(s.cx, (integer::condition("JL",flags)?1u:0u));
  }
  L00772a53: { // 0x772a53: 83f8fc CMP EAX,-0x4
    (void)integer::sub(s.ax,0xfffffffcu,32,flags);
  }
  L00772a56: { // 0x772a56: 7c26 JL 0x00772a7e
    if(integer::condition("JL",flags)) goto L00772a7e;
  }
  L00772a58: { // 0x772a58: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00772a5a: { // 0x772a5a: 7d22 JGE 0x00772a7e
    if(integer::condition("JGE",flags)) goto L00772a7e;
  }
  L00772a5c: { // 0x772a5c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00772a5e: { // 0x772a5e: 740a JZ 0x00772a6a
    if(integer::condition("JZ",flags)) goto L00772a6a;
  }
  L00772a60: { // 0x772a60: 8a07 MOV AL,byte ptr [EDI]
    s.ax = with_al(s.ax, m.r8((s.di)));
  }
  L00772a62: { // 0x772a62: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00772a63: { // 0x772a63: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00772a65: { // 0x772a65: 75f9 JNZ 0x00772a60
    if(integer::condition("JNZ",flags)) goto L00772a60;
  }
  L00772a67: { // 0x772a67: 2047fe AND byte ptr [EDI + -0x2],AL
    m.w8((s.di-0x00000002u), integer::logical((m.r8((s.di-0x00000002u)))&((s.ax & 0xffu)),8,flags));
  }
  L00772a6a: { // 0x772a6a: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00772a6d: { // 0x772a6d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00772a6f: { // 0x772a6f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00772a70: { // 0x772a70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00772a71: { // 0x772a71: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L00772a74: { // 0x772a74: e8e5feffff CALL 0x0077295e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077295eu,7809657u); flags=s.arithmetic_flags;
  }
  L00772a79: { // 0x772a79: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00772a7c: { // 0x772a7c: eb15 JMP 0x00772a93
    goto L00772a93;
  }
  L00772a7e: { // 0x772a7e: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00772a81: { // 0x772a81: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00772a83: { // 0x772a83: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00772a84: { // 0x772a84: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  L00772a87: { // 0x772a87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00772a88: { // 0x772a88: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L00772a8b: { // 0x772a8b: e8b7fdffff CALL 0x00772847
    s.arithmetic_flags=flags; invoke(m,s,f,0x00772847u,7809680u); flags=s.arithmetic_flags;
  }
  L00772a90: { // 0x772a90: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00772a93: { // 0x772a93: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00772a94: { // 0x772a94: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00772a95: { // 0x772a95: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00772a96: { // 0x772a96: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00772a97: { // 0x772a97: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_007805af(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,16> table0{236,118,0,144,64,236,118,0,108,236,118,0,144,236,118,0};leaf::Memory span0(table0.data(),0x76ec30u,16u);m.add(span0);
 std::array<std::uint8_t,32> table1{15,237,118,0,252,236,118,0,244,236,118,0,236,236,118,0,228,236,118,0,220,236,118,0,212,236,118,0,204,236,118,0};leaf::Memory span1(table1.data(),0x76ecacu,32u);m.add(span1);
 std::array<std::uint8_t,16> table2{40,237,118,0,48,237,118,0,60,237,118,0,80,237,118,0};leaf::Memory span2(table2.data(),0x76ed18u,16u);m.add(span2);
 std::array<std::uint8_t,16> table3{238,118,0,144,200,237,118,0,232,237,118,0,16,238,118,0};leaf::Memory span3(table3.data(),0x76edb8u,16u);m.add(span3);
 std::array<std::uint8_t,32> table4{100,238,118,0,108,238,118,0,116,238,118,0,124,238,118,0,132,238,118,0,140,238,118,0,148,238,118,0,167,238,118,0};leaf::Memory span4(table4.data(),0x76ee44u,32u);m.add(span4);
 std::array<std::uint8_t,16> table5{192,238,118,0,200,238,118,0,216,238,118,0,236,238,118,0};leaf::Memory span5(table5.data(),0x76eeb0u,16u);m.add(span5);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007805af: { // 0x7805af: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007805b0: { // 0x7805b0: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L007805b2: { // 0x7805b2: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L007805b5: { // 0x7805b5: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L007805b8: { // 0x7805b8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007805b9: { // 0x7805b9: 8b5d1c MOV EBX,dword ptr [EBP + 0x1c]
    s.bx = m.r32((s.bp+0x0000001cu));
  }
  L007805bc: { // 0x7805bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007805bd: { // 0x7805bd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007805bf: { // 0x7805bf: beff7f0000 MOV ESI,0x7fff
    s.si = 0x00007fffu;
  }
  L007805c4: { // 0x7805c4: 81e100800000 AND ECX,0x8000
    s.cx = integer::logical((s.cx)&(0x00008000u),32,flags);
  }
  L007805ca: { // 0x7805ca: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L007805cc: { // 0x7805cc: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L007805cf: { // 0x7805cf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007805d0: { // 0x7805d0: c645e4cc MOV byte ptr [EBP + -0x1c],0xcc
    m.w8((s.bp-0x0000001cu), 0x000000ccu);
  }
  L007805d4: { // 0x7805d4: c645e5cc MOV byte ptr [EBP + -0x1b],0xcc
    m.w8((s.bp-0x0000001bu), 0x000000ccu);
  }
  L007805d8: { // 0x7805d8: c645e6cc MOV byte ptr [EBP + -0x1a],0xcc
    m.w8((s.bp-0x0000001au), 0x000000ccu);
  }
  L007805dc: { // 0x7805dc: c645e7cc MOV byte ptr [EBP + -0x19],0xcc
    m.w8((s.bp-0x00000019u), 0x000000ccu);
  }
  L007805e0: { // 0x7805e0: c645e8cc MOV byte ptr [EBP + -0x18],0xcc
    m.w8((s.bp-0x00000018u), 0x000000ccu);
  }
  L007805e4: { // 0x7805e4: c645e9cc MOV byte ptr [EBP + -0x17],0xcc
    m.w8((s.bp-0x00000017u), 0x000000ccu);
  }
  L007805e8: { // 0x7805e8: c645eacc MOV byte ptr [EBP + -0x16],0xcc
    m.w8((s.bp-0x00000016u), 0x000000ccu);
  }
  L007805ec: { // 0x7805ec: c645ebcc MOV byte ptr [EBP + -0x15],0xcc
    m.w8((s.bp-0x00000015u), 0x000000ccu);
  }
  L007805f0: { // 0x7805f0: c645eccc MOV byte ptr [EBP + -0x14],0xcc
    m.w8((s.bp-0x00000014u), 0x000000ccu);
  }
  L007805f4: { // 0x7805f4: c645edcc MOV byte ptr [EBP + -0x13],0xcc
    m.w8((s.bp-0x00000013u), 0x000000ccu);
  }
  L007805f8: { // 0x7805f8: c645eefb MOV byte ptr [EBP + -0x12],0xfb
    m.w8((s.bp-0x00000012u), 0x000000fbu);
  }
  L007805fc: { // 0x7805fc: c645ef3f MOV byte ptr [EBP + -0x11],0x3f
    m.w8((s.bp-0x00000011u), 0x0000003fu);
  }
  L00780600: { // 0x780600: c745fc01000000 MOV dword ptr [EBP + -0x4],0x1
    m.w32((s.bp-0x00000004u), 0x00000001u);
  }
  L00780607: { // 0x780607: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00780609: { // 0x780609: 7406 JZ 0x00780611
    if(integer::condition("JZ",flags)) goto L00780611;
  }
  L0078060b: { // 0x78060b: c643022d MOV byte ptr [EBX + 0x2],0x2d
    m.w8((s.bx+0x00000002u), 0x0000002du);
  }
  L0078060f: { // 0x78060f: eb04 JMP 0x00780615
    goto L00780615;
  }
  L00780611: { // 0x780611: c6430220 MOV byte ptr [EBX + 0x2],0x20
    m.w8((s.bx+0x00000002u), 0x00000020u);
  }
  L00780615: { // 0x780615: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  L00780618: { // 0x780618: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L0078061b: { // 0x78061b: 751e JNZ 0x0078063b
    if(integer::condition("JNZ",flags)) goto L0078063b;
  }
  L0078061d: { // 0x78061d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0078061f: { // 0x78061f: 751a JNZ 0x0078063b
    if(integer::condition("JNZ",flags)) goto L0078063b;
  }
  L00780621: { // 0x780621: 397d08 CMP dword ptr [EBP + 0x8],EDI
    (void)integer::sub(m.r32((s.bp+0x00000008u)),s.di,32,flags);
  }
  L00780624: { // 0x780624: 7515 JNZ 0x0078063b
    if(integer::condition("JNZ",flags)) goto L0078063b;
  }
  L00780626: { // 0x780626: 66832300 AND word ptr [EBX],0x0
    m.w16((s.bx), integer::logical((m.r16((s.bx)))&(0x00000000u),16,flags));
  }
  L0078062a: { // 0x78062a: c6430220 MOV byte ptr [EBX + 0x2],0x20
    m.w8((s.bx+0x00000002u), 0x00000020u);
  }
  L0078062e: { // 0x78062e: c6430301 MOV byte ptr [EBX + 0x3],0x1
    m.w8((s.bx+0x00000003u), 0x00000001u);
  }
  L00780632: { // 0x780632: c6430430 MOV byte ptr [EBX + 0x4],0x30
    m.w8((s.bx+0x00000004u), 0x00000030u);
  }
  L00780636: { // 0x780636: e9fe010000 JMP 0x00780839
    goto L00780839;
  }
  L0078063b: { // 0x78063b: 663bd6 CMP DX,SI
    (void)integer::sub((s.dx & 0xffffu),(s.si & 0xffffu),16,flags);
  }
  L0078063e: { // 0x78063e: 757a JNZ 0x007806ba
    if(integer::condition("JNZ",flags)) goto L007806ba;
  }
  L00780640: { // 0x780640: b800000080 MOV EAX,0x80000000
    s.ax = 0x80000000u;
  }
  L00780645: { // 0x780645: 66c7030100 MOV word ptr [EBX],0x1
    m.w16((s.bx), 0x00000001u);
  }
  L0078064a: { // 0x78064a: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0078064c: { // 0x78064c: 7506 JNZ 0x00780654
    if(integer::condition("JNZ",flags)) goto L00780654;
  }
  L0078064e: { // 0x78064e: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  L00780652: { // 0x780652: 740f JZ 0x00780663
    if(integer::condition("JZ",flags)) goto L00780663;
  }
  L00780654: { // 0x780654: f7c700000040 TEST EDI,0x40000000
    (void)integer::logical((s.di)&(0x40000000u),32,flags);
  }
  L0078065a: { // 0x78065a: 7507 JNZ 0x00780663
    if(integer::condition("JNZ",flags)) goto L00780663;
  }
  L0078065c: { // 0x78065c: 687cd47900 PUSH 0x79d47c
    f.push(m,0x0079d47cu);
  }
  L00780661: { // 0x780661: eb46 JMP 0x007806a9
    goto L007806a9;
  }
  L00780663: { // 0x780663: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L00780666: { // 0x780666: 7415 JZ 0x0078067d
    if(integer::condition("JZ",flags)) goto L0078067d;
  }
  L00780668: { // 0x780668: 81ff000000c0 CMP EDI,0xc0000000
    (void)integer::sub(s.di,0xc0000000u,32,flags);
  }
  L0078066e: { // 0x78066e: 750d JNZ 0x0078067d
    if(integer::condition("JNZ",flags)) goto L0078067d;
  }
  L00780670: { // 0x780670: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  L00780674: { // 0x780674: 752e JNZ 0x007806a4
    if(integer::condition("JNZ",flags)) goto L007806a4;
  }
  L00780676: { // 0x780676: 6874d47900 PUSH 0x79d474
    f.push(m,0x0079d474u);
  }
  L0078067b: { // 0x78067b: eb0f JMP 0x0078068c
    goto L0078068c;
  }
  L0078067d: { // 0x78067d: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0078067f: { // 0x78067f: 7523 JNZ 0x007806a4
    if(integer::condition("JNZ",flags)) goto L007806a4;
  }
  L00780681: { // 0x780681: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  L00780685: { // 0x780685: 751d JNZ 0x007806a4
    if(integer::condition("JNZ",flags)) goto L007806a4;
  }
  L00780687: { // 0x780687: 686cd47900 PUSH 0x79d46c
    f.push(m,0x0079d46cu);
  }
  L0078068c: { // 0x78068c: 8d4304 LEA EAX,[EBX + 0x4]
    s.ax = (s.bx+0x00000004u);
  }
  L0078068f: { // 0x78068f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780690: { // 0x780690: e87b89ffff CALL 0x00779010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00779010u,7866005u); flags=s.arithmetic_flags;
  }
  L00780695: { // 0x780695: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780696: { // 0x780696: c6430305 MOV byte ptr [EBX + 0x3],0x5
    m.w8((s.bx+0x00000003u), 0x00000005u);
  }
  L0078069a: { // 0x78069a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078069b: { // 0x78069b: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  L0078069f: { // 0x78069f: e96e010000 JMP 0x00780812
    goto L00780812;
  }
  L007806a4: { // 0x7806a4: 6864d47900 PUSH 0x79d464
    f.push(m,0x0079d464u);
  }
  L007806a9: { // 0x7806a9: 8d4304 LEA EAX,[EBX + 0x4]
    s.ax = (s.bx+0x00000004u);
  }
  L007806ac: { // 0x7806ac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007806ad: { // 0x7806ad: e85e89ffff CALL 0x00779010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00779010u,7866034u); flags=s.arithmetic_flags;
  }
  L007806b2: { // 0x7806b2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007806b3: { // 0x7806b3: c6430306 MOV byte ptr [EBX + 0x3],0x6
    m.w8((s.bx+0x00000003u), 0x00000006u);
  }
  L007806b7: { // 0x7806b7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007806b8: { // 0x7806b8: ebe1 JMP 0x0078069b
    goto L0078069b;
  }
  L007806ba: { // 0x7806ba: 0fb7c2 MOVZX EAX,DX
    s.ax = ((s.dx & 0xffffu)&integer::mask(16));
  }
  L007806bd: { // 0x7806bd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L007806bf: { // 0x7806bf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L007806c1: { // 0x7806c1: c1e918 SHR ECX,0x18
    s.cx = integer::shift(s.cx,0x00000018u,32,flags,integer::Shift::right);
  }
  L007806c4: { // 0x7806c4: 69c0104d0000 IMUL EAX,EAX,0x4d10
    s.ax = integer::imul(s.ax,0x00004d10u,32,flags);
  }
  L007806ca: { // 0x7806ca: c1ee08 SHR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::right);
  }
  L007806cd: { // 0x7806cd: 668365f000 AND word ptr [EBP + -0x10],0x0
    m.w16((s.bp-0x00000010u), integer::logical((m.r16((s.bp-0x00000010u)))&(0x00000000u),16,flags));
  }
  L007806d2: { // 0x7806d2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L007806d4: { // 0x7806d4: 8d0c4e LEA ECX,[ESI + ECX*0x2]
    s.cx = (s.si+(s.cx * 0x00000002u));
  }
  L007806d7: { // 0x7806d7: 668955fa MOV word ptr [EBP + -0x6],DX
    m.w16((s.bp-0x00000006u), (s.dx & 0xffffu));
  }
  L007806db: { // 0x7806db: 6bc94d IMUL ECX,ECX,0x4d
    s.cx = integer::imul(s.cx,0x0000004du,32,flags);
  }
  L007806de: { // 0x7806de: 897df6 MOV dword ptr [EBP + -0xa],EDI
    m.w32((s.bp-0x0000000au), s.di);
  }
  L007806e1: { // 0x7806e1: 8db4010cedbcec LEA ESI,[ECX + EAX*0x1 + 0xecbced0c]
    s.si = (s.cx+(s.ax * 0x00000001u)+0xecbced0cu);
  }
  L007806e8: { // 0x7806e8: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L007806eb: { // 0x7806eb: c1fe10 SAR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
  L007806ee: { // 0x7806ee: 8945f2 MOV dword ptr [EBP + -0xe],EAX
    m.w32((s.bp-0x0000000eu), s.ax);
  }
  L007806f1: { // 0x7806f1: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L007806f4: { // 0x7806f4: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L007806f6: { // 0x7806f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007806f7: { // 0x7806f7: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007806fa: { // 0x7806fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007806fb: { // 0x7806fb: e848050000 CALL 0x00780c48
    s.arithmetic_flags=flags; invoke(m,s,f,0x00780c48u,7866112u); flags=s.arithmetic_flags;
  }
  L00780700: { // 0x780700: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00780703: { // 0x780703: 66817dfaff3f CMP word ptr [EBP + -0x6],0x3fff
    (void)integer::sub(m.r16((s.bp-0x00000006u)),0x00003fffu,16,flags);
  }
  L00780709: { // 0x780709: 7210 JC 0x0078071b
    if(integer::condition("JC",flags)) goto L0078071b;
  }
  L0078070b: { // 0x78070b: 8d45e4 LEA EAX,[EBP + -0x1c]
    s.ax = (s.bp-0x0000001cu);
  }
  L0078070e: { // 0x78070e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0078070f: { // 0x78070f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780710: { // 0x780710: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780713: { // 0x780713: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780714: { // 0x780714: e80f030000 CALL 0x00780a28
    s.arithmetic_flags=flags; invoke(m,s,f,0x00780a28u,7866137u); flags=s.arithmetic_flags;
  }
  L00780719: { // 0x780719: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078071a: { // 0x78071a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078071b: { // 0x78071b: f6451801 TEST byte ptr [EBP + 0x18],0x1
    (void)integer::logical((m.r8((s.bp+0x00000018u)))&(0x00000001u),8,flags);
  }
  L0078071f: { // 0x78071f: 668933 MOV word ptr [EBX],SI
    m.w16((s.bx), (s.si & 0xffffu));
  }
  L00780722: { // 0x780722: 7411 JZ 0x00780735
    if(integer::condition("JZ",flags)) goto L00780735;
  }
  L00780724: { // 0x780724: 8b7d14 MOV EDI,dword ptr [EBP + 0x14]
    s.di = m.r32((s.bp+0x00000014u));
  }
  L00780727: { // 0x780727: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0078072a: { // 0x78072a: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0078072c: { // 0x78072c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0078072e: { // 0x78072e: 7f08 JG 0x00780738
    if(integer::condition("JG",flags)) goto L00780738;
  }
  L00780730: { // 0x780730: e9f1feffff JMP 0x00780626
    goto L00780626;
  }
  L00780735: { // 0x780735: 8b7d14 MOV EDI,dword ptr [EBP + 0x14]
    s.di = m.r32((s.bp+0x00000014u));
  }
  L00780738: { // 0x780738: 83ff15 CMP EDI,0x15
    (void)integer::sub(s.di,0x00000015u,32,flags);
  }
  L0078073b: { // 0x78073b: 7e03 JLE 0x00780740
    if(integer::condition("JLE",flags)) goto L00780740;
  }
  L0078073d: { // 0x78073d: 6a15 PUSH 0x15
    f.push(m,0x00000015u);
  }
  L0078073f: { // 0x78073f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00780740: { // 0x780740: 0fb775fa MOVZX ESI,word ptr [EBP + -0x6]
    s.si = (m.r16((s.bp-0x00000006u))&integer::mask(16));
  }
  L00780744: { // 0x780744: 81eefe3f0000 SUB ESI,0x3ffe
    s.si = integer::sub(s.si,0x00003ffeu,32,flags);
  }
  L0078074a: { // 0x78074a: 668365fa00 AND word ptr [EBP + -0x6],0x0
    m.w16((s.bp-0x00000006u), integer::logical((m.r16((s.bp-0x00000006u)))&(0x00000000u),16,flags));
  }
  L0078074f: { // 0x78074f: c7451c08000000 MOV dword ptr [EBP + 0x1c],0x8
    m.w32((s.bp+0x0000001cu), 0x00000008u);
  }
  L00780756: { // 0x780756: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780759: { // 0x780759: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078075a: { // 0x78075a: e82efdffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866207u); flags=s.arithmetic_flags;
  }
  L0078075f: { // 0x78075f: ff4d1c DEC dword ptr [EBP + 0x1c]
    m.w32((s.bp+0x0000001cu), integer::decrement(m.r32((s.bp+0x0000001cu)),32,flags));
  }
  L00780762: { // 0x780762: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00780763: { // 0x780763: 75f1 JNZ 0x00780756
    if(integer::condition("JNZ",flags)) goto L00780756;
  }
  L00780765: { // 0x780765: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00780767: { // 0x780767: 7d17 JGE 0x00780780
    if(integer::condition("JGE",flags)) goto L00780780;
  }
  L00780769: { // 0x780769: f7de NEG ESI
    s.si = integer::sub(0u,s.si,32,flags);
  }
  L0078076b: { // 0x78076b: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L00780771: { // 0x780771: 7e0d JLE 0x00780780
    if(integer::condition("JLE",flags)) goto L00780780;
  }
  L00780773: { // 0x780773: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780776: { // 0x780776: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780777: { // 0x780777: e83ffdffff CALL 0x007804bb
    s.arithmetic_flags=flags; invoke(m,s,f,0x007804bbu,7866236u); flags=s.arithmetic_flags;
  }
  L0078077c: { // 0x78077c: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0078077d: { // 0x78077d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0078077e: { // 0x78077e: 75f3 JNZ 0x00780773
    if(integer::condition("JNZ",flags)) goto L00780773;
  }
  L00780780: { // 0x780780: 8d4f01 LEA ECX,[EDI + 0x1]
    s.cx = (s.di+0x00000001u);
  }
  L00780783: { // 0x780783: 8d4304 LEA EAX,[EBX + 0x4]
    s.ax = (s.bx+0x00000004u);
  }
  L00780786: { // 0x780786: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00780788: { // 0x780788: 89451c MOV dword ptr [EBP + 0x1c],EAX
    m.w32((s.bp+0x0000001cu), s.ax);
  }
  L0078078b: { // 0x78078b: 7e50 JLE 0x007807dd
    if(integer::condition("JLE",flags)) goto L007807dd;
  }
  L0078078d: { // 0x78078d: 894d14 MOV dword ptr [EBP + 0x14],ECX
    m.w32((s.bp+0x00000014u), s.cx);
  }
  L00780790: { // 0x780790: 8d75f0 LEA ESI,[EBP + -0x10]
    s.si = (s.bp-0x00000010u);
  }
  L00780793: { // 0x780793: 8d7d08 LEA EDI,[EBP + 0x8]
    s.di = (s.bp+0x00000008u);
  }
  L00780796: { // 0x780796: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780797: { // 0x780797: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780798: { // 0x780798: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L0078079b: { // 0x78079b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078079c: { // 0x78079c: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L0078079d: { // 0x78079d: e8ebfcffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866274u); flags=s.arithmetic_flags;
  }
  L007807a2: { // 0x7807a2: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007807a5: { // 0x7807a5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807a6: { // 0x7807a6: e8e2fcffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866283u); flags=s.arithmetic_flags;
  }
  L007807ab: { // 0x7807ab: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  L007807ae: { // 0x7807ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807af: { // 0x7807af: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007807b2: { // 0x7807b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807b3: { // 0x7807b3: e877fcffff CALL 0x0078042f
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078042fu,7866296u); flags=s.arithmetic_flags;
  }
  L007807b8: { // 0x7807b8: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L007807bb: { // 0x7807bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007807bc: { // 0x7807bc: e8ccfcffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7866305u); flags=s.arithmetic_flags;
  }
  L007807c1: { // 0x7807c1: 8a45fb MOV AL,byte ptr [EBP + -0x5]
    s.ax = with_al(s.ax, m.r8((s.bp-0x00000005u)));
  }
  L007807c4: { // 0x7807c4: 8b4d1c MOV ECX,dword ptr [EBP + 0x1c]
    s.cx = m.r32((s.bp+0x0000001cu));
  }
  L007807c7: { // 0x7807c7: 8065fb00 AND byte ptr [EBP + -0x5],0x0
    m.w8((s.bp-0x00000005u), integer::logical((m.r8((s.bp-0x00000005u)))&(0x00000000u),8,flags));
  }
  L007807cb: { // 0x7807cb: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L007807ce: { // 0x7807ce: 0430 ADD AL,0x30
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000030u,8,flags));
  }
  L007807d0: { // 0x7807d0: ff451c INC dword ptr [EBP + 0x1c]
    m.w32((s.bp+0x0000001cu), integer::increment(m.r32((s.bp+0x0000001cu)),32,flags));
  }
  L007807d3: { // 0x7807d3: ff4d14 DEC dword ptr [EBP + 0x14]
    m.w32((s.bp+0x00000014u), integer::decrement(m.r32((s.bp+0x00000014u)),32,flags));
  }
  L007807d6: { // 0x7807d6: 8801 MOV byte ptr [ECX],AL
    m.w8((s.cx), (s.ax & 0xffu));
  }
  L007807d8: { // 0x7807d8: 75b6 JNZ 0x00780790
    if(integer::condition("JNZ",flags)) goto L00780790;
  }
  L007807da: { // 0x7807da: 8b451c MOV EAX,dword ptr [EBP + 0x1c]
    s.ax = m.r32((s.bp+0x0000001cu));
  }
  L007807dd: { // 0x7807dd: 8a48ff MOV CL,byte ptr [EAX + -0x1]
    s.cx = with_al(s.cx, m.r8((s.ax-0x00000001u)));
  }
  L007807e0: { // 0x7807e0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007807e1: { // 0x7807e1: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007807e2: { // 0x7807e2: 80f935 CMP CL,0x35
    (void)integer::sub((s.cx & 0xffu),0x00000035u,8,flags);
  }
  L007807e5: { // 0x7807e5: 8d4b04 LEA ECX,[EBX + 0x4]
    s.cx = (s.bx+0x00000004u);
  }
  L007807e8: { // 0x7807e8: 7c30 JL 0x0078081a
    if(integer::condition("JL",flags)) goto L0078081a;
  }
  L007807ea: { // 0x7807ea: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L007807ec: { // 0x7807ec: 720f JC 0x007807fd
    if(integer::condition("JC",flags)) goto L007807fd;
  }
  L007807ee: { // 0x7807ee: 803839 CMP byte ptr [EAX],0x39
    (void)integer::sub(m.r8((s.ax)),0x00000039u,8,flags);
  }
  L007807f1: { // 0x7807f1: 7506 JNZ 0x007807f9
    if(integer::condition("JNZ",flags)) goto L007807f9;
  }
  L007807f3: { // 0x7807f3: c60030 MOV byte ptr [EAX],0x30
    m.w8((s.ax), 0x00000030u);
  }
  L007807f6: { // 0x7807f6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007807f7: { // 0x7807f7: ebf1 JMP 0x007807ea
    goto L007807ea;
  }
  L007807f9: { // 0x7807f9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L007807fb: { // 0x7807fb: 7304 JNC 0x00780801
    if(integer::condition("JNC",flags)) goto L00780801;
  }
  L007807fd: { // 0x7807fd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L007807fe: { // 0x7807fe: 66ff03 INC word ptr [EBX]
    m.w16((s.bx), integer::increment(m.r16((s.bx)),16,flags));
  }
  L00780801: { // 0x780801: fe00 INC byte ptr [EAX]
    m.w8((s.ax), integer::increment(m.r8((s.ax)),8,flags));
  }
  L00780803: { // 0x780803: 2ac3 SUB AL,BL
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00780805: { // 0x780805: 2c03 SUB AL,0x3
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000003u,8,flags));
  }
  L00780807: { // 0x780807: 884303 MOV byte ptr [EBX + 0x3],AL
    m.w8((s.bx+0x00000003u), (s.ax & 0xffu));
  }
  L0078080a: { // 0x78080a: 0fbec0 MOVSX EAX,AL
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffu),8));
  }
  L0078080d: { // 0x78080d: 8064180400 AND byte ptr [EAX + EBX*0x1 + 0x4],0x0
    m.w8((s.ax+(s.bx * 0x00000001u)+0x00000004u), integer::logical((m.r8((s.ax+(s.bx * 0x00000001u)+0x00000004u)))&(0x00000000u),8,flags));
  }
  L00780812: { // 0x780812: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  L00780815: { // 0x780815: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00780816: { // 0x780816: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00780817: { // 0x780817: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00780818: { // 0x780818: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00780819: { // 0x780819: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0078081a: { // 0x78081a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0078081c: { // 0x78081c: 720c JC 0x0078082a
    if(integer::condition("JC",flags)) goto L0078082a;
  }
  L0078081e: { // 0x78081e: 803830 CMP byte ptr [EAX],0x30
    (void)integer::sub(m.r8((s.ax)),0x00000030u,8,flags);
  }
  L00780821: { // 0x780821: 7503 JNZ 0x00780826
    if(integer::condition("JNZ",flags)) goto L00780826;
  }
  L00780823: { // 0x780823: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00780824: { // 0x780824: ebf4 JMP 0x0078081a
    goto L0078081a;
  }
  L00780826: { // 0x780826: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00780828: { // 0x780828: 73d9 JNC 0x00780803
    if(integer::condition("JNC",flags)) goto L00780803;
  }
  L0078082a: { // 0x78082a: 66832300 AND word ptr [EBX],0x0
    m.w16((s.bx), integer::logical((m.r16((s.bx)))&(0x00000000u),16,flags));
  }
  L0078082e: { // 0x78082e: c6430220 MOV byte ptr [EBX + 0x2],0x20
    m.w8((s.bx+0x00000002u), 0x00000020u);
  }
  L00780832: { // 0x780832: c6430301 MOV byte ptr [EBX + 0x3],0x1
    m.w8((s.bx+0x00000003u), 0x00000001u);
  }
  L00780836: { // 0x780836: c60130 MOV byte ptr [ECX],0x30
    m.w8((s.cx), 0x00000030u);
  }
  L00780839: { // 0x780839: 80630500 AND byte ptr [EBX + 0x5],0x0
    m.w8((s.bx+0x00000005u), integer::logical((m.r8((s.bx+0x00000005u)))&(0x00000000u),8,flags));
  }
  L0078083d: { // 0x78083d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0078083f: { // 0x78083f: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L00780840: { // 0x780840: ebd3 JMP 0x00780815
    goto L00780815;
  }

}
}
