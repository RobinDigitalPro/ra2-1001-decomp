#include "recovered/recovery_b763_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b763 {
namespace {
void f_003804e8(Memory&,State&,Frame&,const Operations&);
void f_00380c48(Memory&,State&,Frame&,const Operations&);
void f_00380a28(Memory&,State&,Frame&,const Operations&);
void f_0038040e(Memory&,State&,Frame&,const Operations&);
void f_0038048d(Memory&,State&,Frame&,const Operations&);
void f_003804bb(Memory&,State&,Frame&,const Operations&);
void f_0038042f(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_003804e8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007804e8: { // 0x7804e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007804e9: { // 0x7804e9: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L007804eb: { // 0x7804eb: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L007804ee: { // 0x7804ee: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L007804f1: { // 0x7804f1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007804f2: { // 0x7804f2: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L007804f5: { // 0x7804f5: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007804f7: { // 0x7804f7: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L007804f9: { // 0x7804f9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007804fa: { // 0x7804fa: c745fc4e400000 MOV dword ptr [EBP + -0x4],0x404e
    m.w32((s.bp-0x00000004u), 0x0000404eu);
  }
  L00780501: { // 0x780501: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L00780503: { // 0x780503: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00780506: { // 0x780506: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  L00780509: { // 0x780509: 7651 JBE 0x0078055c
    if(integer::condition("JBE",flags)) goto L0078055c;
  }
  L0078050b: { // 0x78050b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0078050c: { // 0x78050c: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0078050f: { // 0x78050f: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00780511: { // 0x780511: 8d7df0 LEA EDI,[EBP + -0x10]
    s.di = (s.bp-0x00000010u);
  }
  L00780514: { // 0x780514: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780515: { // 0x780515: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780516: { // 0x780516: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780517: { // 0x780517: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780518: { // 0x780518: e870ffffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865629u); flags=s.arithmetic_flags;
  }
  L0078051d: { // 0x78051d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0078051e: { // 0x78051e: e86affffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865635u); flags=s.arithmetic_flags;
  }
  L00780523: { // 0x780523: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780526: { // 0x780526: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780527: { // 0x780527: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780528: { // 0x780528: e802ffffff CALL 0x0078042f
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078042fu,7865645u); flags=s.arithmetic_flags;
  }
  L0078052d: { // 0x78052d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0078052e: { // 0x78052e: e85affffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865651u); flags=s.arithmetic_flags;
  }
  L00780533: { // 0x780533: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00780536: { // 0x780536: 8365f400 AND dword ptr [EBP + -0xc],0x0
    m.w32((s.bp-0x0000000cu), integer::logical((m.r32((s.bp-0x0000000cu)))&(0x00000000u),32,flags));
  }
  L0078053a: { // 0x78053a: 8365f800 AND dword ptr [EBP + -0x8],0x0
    m.w32((s.bp-0x00000008u), integer::logical((m.r32((s.bp-0x00000008u)))&(0x00000000u),32,flags));
  }
  L0078053e: { // 0x78053e: 0fbe00 MOVSX EAX,byte ptr [EAX]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax)),8));
  }
  L00780541: { // 0x780541: 8945f0 MOV dword ptr [EBP + -0x10],EAX
    m.w32((s.bp-0x00000010u), s.ax);
  }
  L00780544: { // 0x780544: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780547: { // 0x780547: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780548: { // 0x780548: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780549: { // 0x780549: e8e1feffff CALL 0x0078042f
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078042fu,7865678u); flags=s.arithmetic_flags;
  }
  L0078054e: { // 0x78054e: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00780551: { // 0x780551: ff4508 INC dword ptr [EBP + 0x8]
    m.w32((s.bp+0x00000008u), integer::increment(m.r32((s.bp+0x00000008u)),32,flags));
  }
  L00780554: { // 0x780554: ff4d10 DEC dword ptr [EBP + 0x10]
    m.w32((s.bp+0x00000010u), integer::decrement(m.r32((s.bp+0x00000010u)),32,flags));
  }
  L00780557: { // 0x780557: 75b6 JNZ 0x0078050f
    if(integer::condition("JNZ",flags)) goto L0078050f;
  }
  L00780559: { // 0x780559: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0078055b: { // 0x78055b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0078055c: { // 0x78055c: 395308 CMP dword ptr [EBX + 0x8],EDX
    (void)integer::sub(m.r32((s.bx+0x00000008u)),s.dx,32,flags);
  }
  L0078055f: { // 0x78055f: 7528 JNZ 0x00780589
    if(integer::condition("JNZ",flags)) goto L00780589;
  }
  L00780561: { // 0x780561: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00780564: { // 0x780564: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00780566: { // 0x780566: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  L00780569: { // 0x780569: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  L0078056c: { // 0x78056c: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0078056e: { // 0x78056e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00780570: { // 0x780570: c1ee10 SHR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::right);
  }
  L00780573: { // 0x780573: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00780576: { // 0x780576: 0bf1 OR ESI,ECX
    s.si = integer::logical((s.si)|(s.cx),32,flags);
  }
  L00780578: { // 0x780578: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0078057b: { // 0x78057b: 8145fcf0ff0000 ADD dword ptr [EBP + -0x4],0xfff0
    m.w32((s.bp-0x00000004u), integer::add(m.r32((s.bp-0x00000004u)),0x0000fff0u,32,flags));
  }
  L00780582: { // 0x780582: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L00780585: { // 0x780585: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L00780587: { // 0x780587: ebd3 JMP 0x0078055c
    goto L0078055c;
  }
  L00780589: { // 0x780589: be00800000 MOV ESI,0x8000
    s.si = 0x00008000u;
  }
  L0078058e: { // 0x78058e: 857308 TEST dword ptr [EBX + 0x8],ESI
    (void)integer::logical((m.r32((s.bx+0x00000008u)))&(s.si),32,flags);
  }
  L00780591: { // 0x780591: 7510 JNZ 0x007805a3
    if(integer::condition("JNZ",flags)) goto L007805a3;
  }
  L00780593: { // 0x780593: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780594: { // 0x780594: e8f4feffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865753u); flags=s.arithmetic_flags;
  }
  L00780599: { // 0x780599: 8145fcffff0000 ADD dword ptr [EBP + -0x4],0xffff
    m.w32((s.bp-0x00000004u), integer::add(m.r32((s.bp-0x00000004u)),0x0000ffffu,32,flags));
  }
  L007805a0: { // 0x7805a0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007805a1: { // 0x7805a1: ebeb JMP 0x0078058e
    goto L0078058e;
  }
  L007805a3: { // 0x7805a3: 668b45fc MOV AX,word ptr [EBP + -0x4]
    s.ax = with_ax(s.ax, m.r16((s.bp-0x00000004u)));
  }
  L007805a7: { // 0x7805a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007805a8: { // 0x7805a8: 6689430a MOV word ptr [EBX + 0xa],AX
    m.w16((s.bx+0x0000000au), (s.ax & 0xffffu));
  }
  L007805ac: { // 0x7805ac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007805ad: { // 0x7805ad: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L007805ae: { // 0x7805ae: c3 RET
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
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7865576u:f_003804e8(m,s,child,{});break;
case 7867464u:f_00380c48(m,s,child,{});break;
case 7866920u:f_00380a28(m,s,child,{});break;
case 7865358u:f_0038040e(m,s,child,{});break;
case 7865485u:f_0038048d(m,s,child,{});break;
case 7865531u:f_003804bb(m,s,child,{});break;
case 7865391u:f_0038042f(m,s,child,{});break;
default:throw std::domain_error("recovery763 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0077d6f8(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,48> table{98,215,119,0,177,215,119,0,8,216,119,0,50,216,119,0,141,216,119,0,4,217,119,0,58,217,119,0,132,217,119,0,99,217,119,0,232,217,119,0,210,217,119,0,158,217,119,0};leaf::Memory table_span(table.data(),0x77db99u,48);m.add(table_span);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077d6f8: { // 0x77d6f8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077d6f9: { // 0x77d6f9: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077d6fb: { // 0x77d6fb: 83ec5c SUB ESP,0x5c
    f.sp = integer::sub(f.sp,0x0000005cu,32,flags);
  }
  L0077d6fe: { // 0x77d6fe: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077d6ff: { // 0x77d6ff: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077d700: { // 0x77d700: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077d701: { // 0x77d701: 8b7d10 MOV EDI,dword ptr [EBP + 0x10]
    s.di = m.r32((s.bp+0x00000010u));
  }
  L0077d704: { // 0x77d704: 8d45a4 LEA EAX,[EBP + -0x5c]
    s.ax = (s.bp-0x0000005cu);
  }
  L0077d707: { // 0x77d707: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0077d709: { // 0x77d709: 8945f4 MOV dword ptr [EBP + -0xc],EAX
    m.w32((s.bp-0x0000000cu), s.ax);
  }
  L0077d70c: { // 0x77d70c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077d70e: { // 0x77d70e: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  L0077d70f: { // 0x77d70f: 8945d8 MOV dword ptr [EBP + -0x28],EAX
    m.w32((s.bp-0x00000028u), s.ax);
  }
  L0077d712: { // 0x77d712: 8955e8 MOV dword ptr [EBP + -0x18],EDX
    m.w32((s.bp-0x00000018u), s.dx);
  }
  L0077d715: { // 0x77d715: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  L0077d718: { // 0x77d718: 8945f0 MOV dword ptr [EBP + -0x10],EAX
    m.w32((s.bp-0x00000010u), s.ax);
  }
  L0077d71b: { // 0x77d71b: 8945dc MOV dword ptr [EBP + -0x24],EAX
    m.w32((s.bp-0x00000024u), s.ax);
  }
  L0077d71e: { // 0x77d71e: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  L0077d721: { // 0x77d721: 8945d4 MOV dword ptr [EBP + -0x2c],EAX
    m.w32((s.bp-0x0000002cu), s.ax);
  }
  L0077d724: { // 0x77d724: 8945d0 MOV dword ptr [EBP + -0x30],EAX
    m.w32((s.bp-0x00000030u), s.ax);
  }
  L0077d727: { // 0x77d727: 8945e4 MOV dword ptr [EBP + -0x1c],EAX
    m.w32((s.bp-0x0000001cu), s.ax);
  }
  L0077d72a: { // 0x77d72a: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  L0077d72d: { // 0x77d72d: 8945ec MOV dword ptr [EBP + -0x14],EAX
    m.w32((s.bp-0x00000014u), s.ax);
  }
  L0077d730: { // 0x77d730: 897d10 MOV dword ptr [EBP + 0x10],EDI
    m.w32((s.bp+0x00000010u), s.di);
  }
  L0077d733: { // 0x77d733: 8a0f MOV CL,byte ptr [EDI]
    s.cx = with_al(s.cx, m.r8((s.di)));
  }
  L0077d735: { // 0x77d735: 80f920 CMP CL,0x20
    (void)integer::sub((s.cx & 0xffu),0x00000020u,8,flags);
  }
  L0077d738: { // 0x77d738: 740f JZ 0x0077d749
    if(integer::condition("JZ",flags)) goto L0077d749;
  }
  L0077d73a: { // 0x77d73a: 80f909 CMP CL,0x9
    (void)integer::sub((s.cx & 0xffu),0x00000009u,8,flags);
  }
  L0077d73d: { // 0x77d73d: 740a JZ 0x0077d749
    if(integer::condition("JZ",flags)) goto L0077d749;
  }
  L0077d73f: { // 0x77d73f: 80f90a CMP CL,0xa
    (void)integer::sub((s.cx & 0xffu),0x0000000au,8,flags);
  }
  L0077d742: { // 0x77d742: 7405 JZ 0x0077d749
    if(integer::condition("JZ",flags)) goto L0077d749;
  }
  L0077d744: { // 0x77d744: 80f90d CMP CL,0xd
    (void)integer::sub((s.cx & 0xffu),0x0000000du,8,flags);
  }
  L0077d747: { // 0x77d747: 7503 JNZ 0x0077d74c
    if(integer::condition("JNZ",flags)) goto L0077d74c;
  }
  L0077d749: { // 0x77d749: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077d74a: { // 0x77d74a: ebe7 JMP 0x0077d733
    goto L0077d733;
  }
  L0077d74c: { // 0x77d74c: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0077d74e: { // 0x77d74e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077d74f: { // 0x77d74f: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0077d751: { // 0x77d751: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077d752: { // 0x77d752: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L0077d755: { // 0x77d755: 0f8777020000 JA 0x0077d9d2
    if(integer::condition("JA",flags)) goto L0077d9d2;
  }
  L0077d75b: { // 0x77d75b: ff248599db7700 JMP dword ptr [EAX*0x4 + 0x77db99]
    switch(m.r32(((s.ax * 0x00000004u)+0x0077db99u))){
    case 0x0077d6f8u: goto L0077d6f8;
    case 0x0077d6f9u: goto L0077d6f9;
    case 0x0077d6fbu: goto L0077d6fb;
    case 0x0077d6feu: goto L0077d6fe;
    case 0x0077d6ffu: goto L0077d6ff;
    case 0x0077d700u: goto L0077d700;
    case 0x0077d701u: goto L0077d701;
    case 0x0077d704u: goto L0077d704;
    case 0x0077d707u: goto L0077d707;
    case 0x0077d709u: goto L0077d709;
    case 0x0077d70cu: goto L0077d70c;
    case 0x0077d70eu: goto L0077d70e;
    case 0x0077d70fu: goto L0077d70f;
    case 0x0077d712u: goto L0077d712;
    case 0x0077d715u: goto L0077d715;
    case 0x0077d718u: goto L0077d718;
    case 0x0077d71bu: goto L0077d71b;
    case 0x0077d71eu: goto L0077d71e;
    case 0x0077d721u: goto L0077d721;
    case 0x0077d724u: goto L0077d724;
    case 0x0077d727u: goto L0077d727;
    case 0x0077d72au: goto L0077d72a;
    case 0x0077d72du: goto L0077d72d;
    case 0x0077d730u: goto L0077d730;
    case 0x0077d733u: goto L0077d733;
    case 0x0077d735u: goto L0077d735;
    case 0x0077d738u: goto L0077d738;
    case 0x0077d73au: goto L0077d73a;
    case 0x0077d73du: goto L0077d73d;
    case 0x0077d73fu: goto L0077d73f;
    case 0x0077d742u: goto L0077d742;
    case 0x0077d744u: goto L0077d744;
    case 0x0077d747u: goto L0077d747;
    case 0x0077d749u: goto L0077d749;
    case 0x0077d74au: goto L0077d74a;
    case 0x0077d74cu: goto L0077d74c;
    case 0x0077d74eu: goto L0077d74e;
    case 0x0077d74fu: goto L0077d74f;
    case 0x0077d751u: goto L0077d751;
    case 0x0077d752u: goto L0077d752;
    case 0x0077d755u: goto L0077d755;
    case 0x0077d75bu: goto L0077d75b;
    case 0x0077d762u: goto L0077d762;
    case 0x0077d765u: goto L0077d765;
    case 0x0077d767u: goto L0077d767;
    case 0x0077d76au: goto L0077d76a;
    case 0x0077d76cu: goto L0077d76c;
    case 0x0077d76eu: goto L0077d76e;
    case 0x0077d773u: goto L0077d773;
    case 0x0077d779u: goto L0077d779;
    case 0x0077d77bu: goto L0077d77b;
    case 0x0077d77du: goto L0077d77d;
    case 0x0077d782u: goto L0077d782;
    case 0x0077d785u: goto L0077d785;
    case 0x0077d788u: goto L0077d788;
    case 0x0077d78au: goto L0077d78a;
    case 0x0077d78bu: goto L0077d78b;
    case 0x0077d78cu: goto L0077d78c;
    case 0x0077d78eu: goto L0077d78e;
    case 0x0077d791u: goto L0077d791;
    case 0x0077d797u: goto L0077d797;
    case 0x0077d79cu: goto L0077d79c;
    case 0x0077d79eu: goto L0077d79e;
    case 0x0077d7a5u: goto L0077d7a5;
    case 0x0077d7a6u: goto L0077d7a6;
    case 0x0077d7a8u: goto L0077d7a8;
    case 0x0077d7acu: goto L0077d7ac;
    case 0x0077d7aeu: goto L0077d7ae;
    case 0x0077d7afu: goto L0077d7af;
    case 0x0077d7b1u: goto L0077d7b1;
    case 0x0077d7b4u: goto L0077d7b4;
    case 0x0077d7b7u: goto L0077d7b7;
    case 0x0077d7b9u: goto L0077d7b9;
    case 0x0077d7bcu: goto L0077d7bc;
    case 0x0077d7beu: goto L0077d7be;
    case 0x0077d7c4u: goto L0077d7c4;
    case 0x0077d7cau: goto L0077d7ca;
    case 0x0077d7cdu: goto L0077d7cd;
    case 0x0077d7cfu: goto L0077d7cf;
    case 0x0077d7d2u: goto L0077d7d2;
    case 0x0077d7d4u: goto L0077d7d4;
    case 0x0077d7d7u: goto L0077d7d7;
    case 0x0077d7d9u: goto L0077d7d9;
    case 0x0077d7dcu: goto L0077d7dc;
    case 0x0077d7e2u: goto L0077d7e2;
    case 0x0077d7e5u: goto L0077d7e5;
    case 0x0077d7e7u: goto L0077d7e7;
    case 0x0077d7eau: goto L0077d7ea;
    case 0x0077d7f0u: goto L0077d7f0;
    case 0x0077d7f3u: goto L0077d7f3;
    case 0x0077d7f9u: goto L0077d7f9;
    case 0x0077d7fbu: goto L0077d7fb;
    case 0x0077d800u: goto L0077d800;
    case 0x0077d801u: goto L0077d801;
    case 0x0077d803u: goto L0077d803;
    case 0x0077d808u: goto L0077d808;
    case 0x0077d80bu: goto L0077d80b;
    case 0x0077d80du: goto L0077d80d;
    case 0x0077d810u: goto L0077d810;
    case 0x0077d816u: goto L0077d816;
    case 0x0077d81cu: goto L0077d81c;
    case 0x0077d822u: goto L0077d822;
    case 0x0077d825u: goto L0077d825;
    case 0x0077d82bu: goto L0077d82b;
    case 0x0077d82du: goto L0077d82d;
    case 0x0077d832u: goto L0077d832;
    case 0x0077d835u: goto L0077d835;
    case 0x0077d83bu: goto L0077d83b;
    case 0x0077d83du: goto L0077d83d;
    case 0x0077d840u: goto L0077d840;
    case 0x0077d841u: goto L0077d841;
    case 0x0077d842u: goto L0077d842;
    case 0x0077d847u: goto L0077d847;
    case 0x0077d848u: goto L0077d848;
    case 0x0077d849u: goto L0077d849;
    case 0x0077d84bu: goto L0077d84b;
    case 0x0077d84cu: goto L0077d84c;
    case 0x0077d84eu: goto L0077d84e;
    case 0x0077d854u: goto L0077d854;
    case 0x0077d857u: goto L0077d857;
    case 0x0077d85au: goto L0077d85a;
    case 0x0077d85cu: goto L0077d85c;
    case 0x0077d85eu: goto L0077d85e;
    case 0x0077d860u: goto L0077d860;
    case 0x0077d864u: goto L0077d864;
    case 0x0077d866u: goto L0077d866;
    case 0x0077d869u: goto L0077d869;
    case 0x0077d86cu: goto L0077d86c;
    case 0x0077d86fu: goto L0077d86f;
    case 0x0077d872u: goto L0077d872;
    case 0x0077d874u: goto L0077d874;
    case 0x0077d876u: goto L0077d876;
    case 0x0077d879u: goto L0077d879;
    case 0x0077d87bu: goto L0077d87b;
    case 0x0077d87cu: goto L0077d87c;
    case 0x0077d87eu: goto L0077d87e;
    case 0x0077d884u: goto L0077d884;
    case 0x0077d886u: goto L0077d886;
    case 0x0077d888u: goto L0077d888;
    case 0x0077d88du: goto L0077d88d;
    case 0x0077d891u: goto L0077d891;
    case 0x0077d894u: goto L0077d894;
    case 0x0077d897u: goto L0077d897;
    case 0x0077d899u: goto L0077d899;
    case 0x0077d89cu: goto L0077d89c;
    case 0x0077d89eu: goto L0077d89e;
    case 0x0077d8a1u: goto L0077d8a1;
    case 0x0077d8a3u: goto L0077d8a3;
    case 0x0077d8a4u: goto L0077d8a4;
    case 0x0077d8a6u: goto L0077d8a6;
    case 0x0077d8acu: goto L0077d8ac;
    case 0x0077d8aeu: goto L0077d8ae;
    case 0x0077d8b1u: goto L0077d8b1;
    case 0x0077d8b2u: goto L0077d8b2;
    case 0x0077d8b3u: goto L0077d8b3;
    case 0x0077d8b8u: goto L0077d8b8;
    case 0x0077d8b9u: goto L0077d8b9;
    case 0x0077d8bau: goto L0077d8ba;
    case 0x0077d8bcu: goto L0077d8bc;
    case 0x0077d8bdu: goto L0077d8bd;
    case 0x0077d8bfu: goto L0077d8bf;
    case 0x0077d8c5u: goto L0077d8c5;
    case 0x0077d8c8u: goto L0077d8c8;
    case 0x0077d8cbu: goto L0077d8cb;
    case 0x0077d8cdu: goto L0077d8cd;
    case 0x0077d8cfu: goto L0077d8cf;
    case 0x0077d8d1u: goto L0077d8d1;
    case 0x0077d8d5u: goto L0077d8d5;
    case 0x0077d8d7u: goto L0077d8d7;
    case 0x0077d8dau: goto L0077d8da;
    case 0x0077d8ddu: goto L0077d8dd;
    case 0x0077d8e0u: goto L0077d8e0;
    case 0x0077d8e3u: goto L0077d8e3;
    case 0x0077d8e6u: goto L0077d8e6;
    case 0x0077d8e8u: goto L0077d8e8;
    case 0x0077d8eau: goto L0077d8ea;
    case 0x0077d8ebu: goto L0077d8eb;
    case 0x0077d8edu: goto L0077d8ed;
    case 0x0077d8f0u: goto L0077d8f0;
    case 0x0077d8f6u: goto L0077d8f6;
    case 0x0077d8f9u: goto L0077d8f9;
    case 0x0077d8ffu: goto L0077d8ff;
    case 0x0077d904u: goto L0077d904;
    case 0x0077d90au: goto L0077d90a;
    case 0x0077d90du: goto L0077d90d;
    case 0x0077d90fu: goto L0077d90f;
    case 0x0077d912u: goto L0077d912;
    case 0x0077d913u: goto L0077d913;
    case 0x0077d914u: goto L0077d914;
    case 0x0077d919u: goto L0077d919;
    case 0x0077d91au: goto L0077d91a;
    case 0x0077d91bu: goto L0077d91b;
    case 0x0077d91du: goto L0077d91d;
    case 0x0077d91eu: goto L0077d91e;
    case 0x0077d920u: goto L0077d920;
    case 0x0077d926u: goto L0077d926;
    case 0x0077d929u: goto L0077d929;
    case 0x0077d92cu: goto L0077d92c;
    case 0x0077d92eu: goto L0077d92e;
    case 0x0077d930u: goto L0077d930;
    case 0x0077d936u: goto L0077d936;
    case 0x0077d938u: goto L0077d938;
    case 0x0077d93au: goto L0077d93a;
    case 0x0077d93du: goto L0077d93d;
    case 0x0077d940u: goto L0077d940;
    case 0x0077d943u: goto L0077d943;
    case 0x0077d945u: goto L0077d945;
    case 0x0077d948u: goto L0077d948;
    case 0x0077d94au: goto L0077d94a;
    case 0x0077d94du: goto L0077d94d;
    case 0x0077d950u: goto L0077d950;
    case 0x0077d952u: goto L0077d952;
    case 0x0077d953u: goto L0077d953;
    case 0x0077d954u: goto L0077d954;
    case 0x0077d956u: goto L0077d956;
    case 0x0077d959u: goto L0077d959;
    case 0x0077d95fu: goto L0077d95f;
    case 0x0077d961u: goto L0077d961;
    case 0x0077d963u: goto L0077d963;
    case 0x0077d966u: goto L0077d966;
    case 0x0077d969u: goto L0077d969;
    case 0x0077d96bu: goto L0077d96b;
    case 0x0077d96du: goto L0077d96d;
    case 0x0077d96eu: goto L0077d96e;
    case 0x0077d970u: goto L0077d970;
    case 0x0077d973u: goto L0077d973;
    case 0x0077d979u: goto L0077d979;
    case 0x0077d97cu: goto L0077d97c;
    case 0x0077d982u: goto L0077d982;
    case 0x0077d984u: goto L0077d984;
    case 0x0077d987u: goto L0077d987;
    case 0x0077d989u: goto L0077d989;
    case 0x0077d98cu: goto L0077d98c;
    case 0x0077d98eu: goto L0077d98e;
    case 0x0077d990u: goto L0077d990;
    case 0x0077d991u: goto L0077d991;
    case 0x0077d992u: goto L0077d992;
    case 0x0077d997u: goto L0077d997;
    case 0x0077d99au: goto L0077d99a;
    case 0x0077d99cu: goto L0077d99c;
    case 0x0077d99eu: goto L0077d99e;
    case 0x0077d9a2u: goto L0077d9a2;
    case 0x0077d9a4u: goto L0077d9a4;
    case 0x0077d9a7u: goto L0077d9a7;
    case 0x0077d9aau: goto L0077d9aa;
    case 0x0077d9adu: goto L0077d9ad;
    case 0x0077d9b0u: goto L0077d9b0;
    case 0x0077d9b2u: goto L0077d9b2;
    case 0x0077d9b3u: goto L0077d9b3;
    case 0x0077d9b4u: goto L0077d9b4;
    case 0x0077d9bau: goto L0077d9ba;
    case 0x0077d9beu: goto L0077d9be;
    case 0x0077d9c0u: goto L0077d9c0;
    case 0x0077d9c1u: goto L0077d9c1;
    case 0x0077d9c6u: goto L0077d9c6;
    case 0x0077d9c8u: goto L0077d9c8;
    case 0x0077d9c9u: goto L0077d9c9;
    case 0x0077d9ceu: goto L0077d9ce;
    case 0x0077d9d0u: goto L0077d9d0;
    case 0x0077d9d1u: goto L0077d9d1;
    case 0x0077d9d2u: goto L0077d9d2;
    case 0x0077d9d5u: goto L0077d9d5;
    case 0x0077d9dbu: goto L0077d9db;
    case 0x0077d9e0u: goto L0077d9e0;
    case 0x0077d9e3u: goto L0077d9e3;
    case 0x0077d9e8u: goto L0077d9e8;
    case 0x0077d9efu: goto L0077d9ef;
    case 0x0077d9f1u: goto L0077d9f1;
    case 0x0077d9f8u: goto L0077d9f8;
    case 0x0077d9fau: goto L0077d9fa;
    case 0x0077d9fdu: goto L0077d9fd;
    case 0x0077d9ffu: goto L0077d9ff;
    case 0x0077da00u: goto L0077da00;
    case 0x0077da05u: goto L0077da05;
    case 0x0077da06u: goto L0077da06;
    case 0x0077da07u: goto L0077da07;
    case 0x0077da09u: goto L0077da09;
    case 0x0077da0fu: goto L0077da0f;
    case 0x0077da12u: goto L0077da12;
    case 0x0077da15u: goto L0077da15;
    case 0x0077da18u: goto L0077da18;
    case 0x0077da1au: goto L0077da1a;
    case 0x0077da1cu: goto L0077da1c;
    case 0x0077da1fu: goto L0077da1f;
    case 0x0077da22u: goto L0077da22;
    case 0x0077da26u: goto L0077da26;
    case 0x0077da2cu: goto L0077da2c;
    case 0x0077da2eu: goto L0077da2e;
    case 0x0077da30u: goto L0077da30;
    case 0x0077da31u: goto L0077da31;
    case 0x0077da33u: goto L0077da33;
    case 0x0077da38u: goto L0077da38;
    case 0x0077da3bu: goto L0077da3b;
    case 0x0077da42u: goto L0077da42;
    case 0x0077da44u: goto L0077da44;
    case 0x0077da47u: goto L0077da47;
    case 0x0077da49u: goto L0077da49;
    case 0x0077da4au: goto L0077da4a;
    case 0x0077da4fu: goto L0077da4f;
    case 0x0077da50u: goto L0077da50;
    case 0x0077da51u: goto L0077da51;
    case 0x0077da53u: goto L0077da53;
    case 0x0077da59u: goto L0077da59;
    case 0x0077da5cu: goto L0077da5c;
    case 0x0077da5fu: goto L0077da5f;
    case 0x0077da62u: goto L0077da62;
    case 0x0077da64u: goto L0077da64;
    case 0x0077da66u: goto L0077da66;
    case 0x0077da68u: goto L0077da68;
    case 0x0077da69u: goto L0077da69;
    case 0x0077da6bu: goto L0077da6b;
    case 0x0077da6cu: goto L0077da6c;
    case 0x0077da6eu: goto L0077da6e;
    case 0x0077da70u: goto L0077da70;
    case 0x0077da73u: goto L0077da73;
    case 0x0077da77u: goto L0077da77;
    case 0x0077da79u: goto L0077da79;
    case 0x0077da7fu: goto L0077da7f;
    case 0x0077da81u: goto L0077da81;
    case 0x0077da82u: goto L0077da82;
    case 0x0077da85u: goto L0077da85;
    case 0x0077da87u: goto L0077da87;
    case 0x0077da8bu: goto L0077da8b;
    case 0x0077da8du: goto L0077da8d;
    case 0x0077da90u: goto L0077da90;
    case 0x0077da93u: goto L0077da93;
    case 0x0077da96u: goto L0077da96;
    case 0x0077da97u: goto L0077da97;
    case 0x0077da9au: goto L0077da9a;
    case 0x0077da9cu: goto L0077da9c;
    case 0x0077da9fu: goto L0077da9f;
    case 0x0077daa3u: goto L0077daa3;
    case 0x0077daa9u: goto L0077daa9;
    case 0x0077daaau: goto L0077daaa;
    case 0x0077daadu: goto L0077daad;
    case 0x0077daafu: goto L0077daaf;
    case 0x0077dab2u: goto L0077dab2;
    case 0x0077dab5u: goto L0077dab5;
    case 0x0077dab7u: goto L0077dab7;
    case 0x0077dabau: goto L0077daba;
    case 0x0077dabbu: goto L0077dabb;
    case 0x0077dabeu: goto L0077dabe;
    case 0x0077dac1u: goto L0077dac1;
    case 0x0077dac2u: goto L0077dac2;
    case 0x0077dac7u: goto L0077dac7;
    case 0x0077dacau: goto L0077daca;
    case 0x0077daccu: goto L0077dacc;
    case 0x0077dacfu: goto L0077dacf;
    case 0x0077dad2u: goto L0077dad2;
    case 0x0077dad4u: goto L0077dad4;
    case 0x0077dad6u: goto L0077dad6;
    case 0x0077dad9u: goto L0077dad9;
    case 0x0077dadcu: goto L0077dadc;
    case 0x0077dadeu: goto L0077dade;
    case 0x0077dae1u: goto L0077dae1;
    case 0x0077dae4u: goto L0077dae4;
    case 0x0077dae6u: goto L0077dae6;
    case 0x0077dae9u: goto L0077dae9;
    case 0x0077daeeu: goto L0077daee;
    case 0x0077daf0u: goto L0077daf0;
    case 0x0077daf7u: goto L0077daf7;
    case 0x0077dafau: goto L0077dafa;
    case 0x0077dafdu: goto L0077dafd;
    case 0x0077db00u: goto L0077db00;
    case 0x0077db03u: goto L0077db03;
    case 0x0077db07u: goto L0077db07;
    case 0x0077db09u: goto L0077db09;
    case 0x0077db0bu: goto L0077db0b;
    case 0x0077db10u: goto L0077db10;
    case 0x0077db15u: goto L0077db15;
    case 0x0077db17u: goto L0077db17;
    case 0x0077db1eu: goto L0077db1e;
    case 0x0077db20u: goto L0077db20;
    case 0x0077db25u: goto L0077db25;
    case 0x0077db27u: goto L0077db27;
    case 0x0077db2eu: goto L0077db2e;
    case 0x0077db30u: goto L0077db30;
    case 0x0077db33u: goto L0077db33;
    case 0x0077db34u: goto L0077db34;
    case 0x0077db37u: goto L0077db37;
    case 0x0077db38u: goto L0077db38;
    case 0x0077db3du: goto L0077db3d;
    case 0x0077db40u: goto L0077db40;
    case 0x0077db43u: goto L0077db43;
    case 0x0077db46u: goto L0077db46;
    case 0x0077db49u: goto L0077db49;
    case 0x0077db4cu: goto L0077db4c;
    case 0x0077db4eu: goto L0077db4e;
    case 0x0077db50u: goto L0077db50;
    case 0x0077db52u: goto L0077db52;
    case 0x0077db54u: goto L0077db54;
    case 0x0077db56u: goto L0077db56;
    case 0x0077db58u: goto L0077db58;
    case 0x0077db5au: goto L0077db5a;
    case 0x0077db5cu: goto L0077db5c;
    case 0x0077db5eu: goto L0077db5e;
    case 0x0077db60u: goto L0077db60;
    case 0x0077db67u: goto L0077db67;
    case 0x0077db69u: goto L0077db69;
    case 0x0077db6du: goto L0077db6d;
    case 0x0077db6fu: goto L0077db6f;
    case 0x0077db71u: goto L0077db71;
    case 0x0077db73u: goto L0077db73;
    case 0x0077db75u: goto L0077db75;
    case 0x0077db77u: goto L0077db77;
    case 0x0077db7eu: goto L0077db7e;
    case 0x0077db81u: goto L0077db81;
    case 0x0077db84u: goto L0077db84;
    case 0x0077db85u: goto L0077db85;
    case 0x0077db88u: goto L0077db88;
    case 0x0077db8bu: goto L0077db8b;
    case 0x0077db8fu: goto L0077db8f;
    case 0x0077db92u: goto L0077db92;
    case 0x0077db93u: goto L0077db93;
    case 0x0077db96u: goto L0077db96;
    case 0x0077db97u: goto L0077db97;
    case 0x0077db98u: goto L0077db98;
    default:throw std::domain_error("recovery763 unsupported switch destination");}
  }
  L0077d762: { // 0x77d762: 80fb31 CMP BL,0x31
    (void)integer::sub((s.bx & 0xffu),0x00000031u,8,flags);
  }
  L0077d765: { // 0x77d765: 7c0c JL 0x0077d773
    if(integer::condition("JL",flags)) goto L0077d773;
  }
  L0077d767: { // 0x77d767: 80fb39 CMP BL,0x39
    (void)integer::sub((s.bx & 0xffu),0x00000039u,8,flags);
  }
  L0077d76a: { // 0x77d76a: 7f07 JG 0x0077d773
    if(integer::condition("JG",flags)) goto L0077d773;
  }
  L0077d76c: { // 0x77d76c: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0077d76e: { // 0x77d76e: e91d020000 JMP 0x0077d990
    goto L0077d990;
  }
  L0077d773: { // 0x77d773: 3a1d70778100 CMP BL,byte ptr [0x00817770]
    (void)integer::sub((s.bx & 0xffu),m.r8((0x00817770u)),8,flags);
  }
  L0077d779: { // 0x77d779: 7507 JNZ 0x0077d782
    if(integer::condition("JNZ",flags)) goto L0077d782;
  }
  L0077d77b: { // 0x77d77b: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0077d77d: { // 0x77d77d: e946020000 JMP 0x0077d9c8
    goto L0077d9c8;
  }
  L0077d782: { // 0x77d782: 0fbec3 MOVSX EAX,BL
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffu),8));
  }
  L0077d785: { // 0x77d785: 83e82b SUB EAX,0x2b
    s.ax = integer::sub(s.ax,0x0000002bu,32,flags);
  }
  L0077d788: { // 0x77d788: 741e JZ 0x0077d7a8
    if(integer::condition("JZ",flags)) goto L0077d7a8;
  }
  L0077d78a: { // 0x77d78a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077d78b: { // 0x77d78b: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077d78c: { // 0x77d78c: 740e JZ 0x0077d79c
    if(integer::condition("JZ",flags)) goto L0077d79c;
  }
  L0077d78e: { // 0x77d78e: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L0077d791: { // 0x77d791: 0f85d4020000 JNZ 0x0077da6b
    if(integer::condition("JNZ",flags)) goto L0077da6b;
  }
  L0077d797: { // 0x77d797: e98f000000 JMP 0x0077d82b
    goto L0077d82b;
  }
  L0077d79c: { // 0x77d79c: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0077d79e: { // 0x77d79e: c745d800800000 MOV dword ptr [EBP + -0x28],0x8000
    m.w32((s.bp-0x00000028u), 0x00008000u);
  }
  L0077d7a5: { // 0x77d7a5: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077d7a6: { // 0x77d7a6: eba7 JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d7a8: { // 0x77d7a8: 8365d800 AND dword ptr [EBP + -0x28],0x0
    m.w32((s.bp-0x00000028u), integer::logical((m.r32((s.bp-0x00000028u)))&(0x00000000u),32,flags));
  }
  L0077d7ac: { // 0x77d7ac: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0077d7ae: { // 0x77d7ae: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077d7af: { // 0x77d7af: eb9e JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d7b1: { // 0x77d7b1: 80fb31 CMP BL,0x31
    (void)integer::sub((s.bx & 0xffu),0x00000031u,8,flags);
  }
  L0077d7b4: { // 0x77d7b4: 8955f0 MOV dword ptr [EBP + -0x10],EDX
    m.w32((s.bp-0x00000010u), s.dx);
  }
  L0077d7b7: { // 0x77d7b7: 7c05 JL 0x0077d7be
    if(integer::condition("JL",flags)) goto L0077d7be;
  }
  L0077d7b9: { // 0x77d7b9: 80fb39 CMP BL,0x39
    (void)integer::sub((s.bx & 0xffu),0x00000039u,8,flags);
  }
  L0077d7bc: { // 0x77d7bc: 7eae JLE 0x0077d76c
    if(integer::condition("JLE",flags)) goto L0077d76c;
  }
  L0077d7be: { // 0x77d7be: 3a1d70778100 CMP BL,byte ptr [0x00817770]
    (void)integer::sub((s.bx & 0xffu),m.r8((0x00817770u)),8,flags);
  }
  L0077d7c4: { // 0x77d7c4: 0f84bc000000 JZ 0x0077d886
    if(integer::condition("JZ",flags)) goto L0077d886;
  }
  L0077d7ca: { // 0x77d7ca: 80fb2b CMP BL,0x2b
    (void)integer::sub((s.bx & 0xffu),0x0000002bu,8,flags);
  }
  L0077d7cd: { // 0x77d7cd: 7431 JZ 0x0077d800
    if(integer::condition("JZ",flags)) goto L0077d800;
  }
  L0077d7cf: { // 0x77d7cf: 80fb2d CMP BL,0x2d
    (void)integer::sub((s.bx & 0xffu),0x0000002du,8,flags);
  }
  L0077d7d2: { // 0x77d7d2: 742c JZ 0x0077d800
    if(integer::condition("JZ",flags)) goto L0077d800;
  }
  L0077d7d4: { // 0x77d7d4: 80fb30 CMP BL,0x30
    (void)integer::sub((s.bx & 0xffu),0x00000030u,8,flags);
  }
  L0077d7d7: { // 0x77d7d7: 7452 JZ 0x0077d82b
    if(integer::condition("JZ",flags)) goto L0077d82b;
  }
  L0077d7d9: { // 0x77d7d9: 80fb43 CMP BL,0x43
    (void)integer::sub((s.bx & 0xffu),0x00000043u,8,flags);
  }
  L0077d7dc: { // 0x77d7dc: 0f8e89020000 JLE 0x0077da6b
    if(integer::condition("JLE",flags)) goto L0077da6b;
  }
  L0077d7e2: { // 0x77d7e2: 80fb45 CMP BL,0x45
    (void)integer::sub((s.bx & 0xffu),0x00000045u,8,flags);
  }
  L0077d7e5: { // 0x77d7e5: 7e12 JLE 0x0077d7f9
    if(integer::condition("JLE",flags)) goto L0077d7f9;
  }
  L0077d7e7: { // 0x77d7e7: 80fb63 CMP BL,0x63
    (void)integer::sub((s.bx & 0xffu),0x00000063u,8,flags);
  }
  L0077d7ea: { // 0x77d7ea: 0f8e7b020000 JLE 0x0077da6b
    if(integer::condition("JLE",flags)) goto L0077da6b;
  }
  L0077d7f0: { // 0x77d7f0: 80fb65 CMP BL,0x65
    (void)integer::sub((s.bx & 0xffu),0x00000065u,8,flags);
  }
  L0077d7f3: { // 0x77d7f3: 0f8f72020000 JG 0x0077da6b
    if(integer::condition("JG",flags)) goto L0077da6b;
  }
  L0077d7f9: { // 0x77d7f9: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  L0077d7fb: { // 0x77d7fb: e9c8010000 JMP 0x0077d9c8
    goto L0077d9c8;
  }
  L0077d800: { // 0x77d800: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0077d801: { // 0x77d801: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  L0077d803: { // 0x77d803: e9c0010000 JMP 0x0077d9c8
    goto L0077d9c8;
  }
  L0077d808: { // 0x77d808: 80fb31 CMP BL,0x31
    (void)integer::sub((s.bx & 0xffu),0x00000031u,8,flags);
  }
  L0077d80b: { // 0x77d80b: 7c09 JL 0x0077d816
    if(integer::condition("JL",flags)) goto L0077d816;
  }
  L0077d80d: { // 0x77d80d: 80fb39 CMP BL,0x39
    (void)integer::sub((s.bx & 0xffu),0x00000039u,8,flags);
  }
  L0077d810: { // 0x77d810: 0f8e56ffffff JLE 0x0077d76c
    if(integer::condition("JLE",flags)) goto L0077d76c;
  }
  L0077d816: { // 0x77d816: 3a1d70778100 CMP BL,byte ptr [0x00817770]
    (void)integer::sub((s.bx & 0xffu),m.r8((0x00817770u)),8,flags);
  }
  L0077d81c: { // 0x77d81c: 0f8459ffffff JZ 0x0077d77b
    if(integer::condition("JZ",flags)) goto L0077d77b;
  }
  L0077d822: { // 0x77d822: 80fb30 CMP BL,0x30
    (void)integer::sub((s.bx & 0xffu),0x00000030u,8,flags);
  }
  L0077d825: { // 0x77d825: 0f85b5010000 JNZ 0x0077d9e0
    if(integer::condition("JNZ",flags)) goto L0077d9e0;
  }
  L0077d82b: { // 0x77d82b: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0077d82d: { // 0x77d82d: e91dffffff JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d832: { // 0x77d832: 8955f0 MOV dword ptr [EBP + -0x10],EDX
    m.w32((s.bp-0x00000010u), s.dx);
  }
  L0077d835: { // 0x77d835: 39156c778100 CMP dword ptr [0x0081776c],EDX
    (void)integer::sub(m.r32((0x0081776cu)),s.dx,32,flags);
  }
  L0077d83b: { // 0x77d83b: 7e11 JLE 0x0077d84e
    if(integer::condition("JLE",flags)) goto L0077d84e;
  }
  L0077d83d: { // 0x77d83d: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077d840: { // 0x77d840: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077d841: { // 0x77d841: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077d842: { // 0x77d842: e88a76ffff CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7854151u); flags=s.arithmetic_flags;
  }
  L0077d847: { // 0x77d847: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077d848: { // 0x77d848: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077d849: { // 0x77d849: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0077d84b: { // 0x77d84b: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  L0077d84c: { // 0x77d84c: eb0e JMP 0x0077d85c
    goto L0077d85c;
  }
  L0077d84e: { // 0x77d84e: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  L0077d854: { // 0x77d854: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077d857: { // 0x77d857: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  L0077d85a: { // 0x77d85a: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L0077d85c: { // 0x77d85c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077d85e: { // 0x77d85e: 741e JZ 0x0077d87e
    if(integer::condition("JZ",flags)) goto L0077d87e;
  }
  L0077d860: { // 0x77d860: 837dfc19 CMP dword ptr [EBP + -0x4],0x19
    (void)integer::sub(m.r32((s.bp-0x00000004u)),0x00000019u,32,flags);
  }
  L0077d864: { // 0x77d864: 7310 JNC 0x0077d876
    if(integer::condition("JNC",flags)) goto L0077d876;
  }
  L0077d866: { // 0x77d866: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L0077d869: { // 0x77d869: ff45fc INC dword ptr [EBP + -0x4]
    m.w32((s.bp-0x00000004u), integer::increment(m.r32((s.bp-0x00000004u)),32,flags));
  }
  L0077d86c: { // 0x77d86c: 80eb30 SUB BL,0x30
    s.bx = with_al(s.bx, integer::sub((s.bx & 0xffu),0x00000030u,8,flags));
  }
  L0077d86f: { // 0x77d86f: ff45f4 INC dword ptr [EBP + -0xc]
    m.w32((s.bp-0x0000000cu), integer::increment(m.r32((s.bp-0x0000000cu)),32,flags));
  }
  L0077d872: { // 0x77d872: 8818 MOV byte ptr [EAX],BL
    m.w8((s.ax), (s.bx & 0xffu));
  }
  L0077d874: { // 0x77d874: eb03 JMP 0x0077d879
    goto L0077d879;
  }
  L0077d876: { // 0x77d876: ff45f8 INC dword ptr [EBP + -0x8]
    m.w32((s.bp-0x00000008u), integer::increment(m.r32((s.bp-0x00000008u)),32,flags));
  }
  L0077d879: { // 0x77d879: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0077d87b: { // 0x77d87b: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077d87c: { // 0x77d87c: ebb7 JMP 0x0077d835
    goto L0077d835;
  }
  L0077d87e: { // 0x77d87e: 3a1d70778100 CMP BL,byte ptr [0x00817770]
    (void)integer::sub((s.bx & 0xffu),m.r8((0x00817770u)),8,flags);
  }
  L0077d884: { // 0x77d884: 7567 JNZ 0x0077d8ed
    if(integer::condition("JNZ",flags)) goto L0077d8ed;
  }
  L0077d886: { // 0x77d886: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0077d888: { // 0x77d888: e9c2feffff JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d88d: { // 0x77d88d: 837dfc00 CMP dword ptr [EBP + -0x4],0x0
    (void)integer::sub(m.r32((s.bp-0x00000004u)),0x00000000u,32,flags);
  }
  L0077d891: { // 0x77d891: 8955f0 MOV dword ptr [EBP + -0x10],EDX
    m.w32((s.bp-0x00000010u), s.dx);
  }
  L0077d894: { // 0x77d894: 8955dc MOV dword ptr [EBP + -0x24],EDX
    m.w32((s.bp-0x00000024u), s.dx);
  }
  L0077d897: { // 0x77d897: 750d JNZ 0x0077d8a6
    if(integer::condition("JNZ",flags)) goto L0077d8a6;
  }
  L0077d899: { // 0x77d899: 80fb30 CMP BL,0x30
    (void)integer::sub((s.bx & 0xffu),0x00000030u,8,flags);
  }
  L0077d89c: { // 0x77d89c: 7508 JNZ 0x0077d8a6
    if(integer::condition("JNZ",flags)) goto L0077d8a6;
  }
  L0077d89e: { // 0x77d89e: ff4df8 DEC dword ptr [EBP + -0x8]
    m.w32((s.bp-0x00000008u), integer::decrement(m.r32((s.bp-0x00000008u)),32,flags));
  }
  L0077d8a1: { // 0x77d8a1: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0077d8a3: { // 0x77d8a3: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077d8a4: { // 0x77d8a4: ebf3 JMP 0x0077d899
    goto L0077d899;
  }
  L0077d8a6: { // 0x77d8a6: 39156c778100 CMP dword ptr [0x0081776c],EDX
    (void)integer::sub(m.r32((0x0081776cu)),s.dx,32,flags);
  }
  L0077d8ac: { // 0x77d8ac: 7e11 JLE 0x0077d8bf
    if(integer::condition("JLE",flags)) goto L0077d8bf;
  }
  L0077d8ae: { // 0x77d8ae: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077d8b1: { // 0x77d8b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077d8b2: { // 0x77d8b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077d8b3: { // 0x77d8b3: e81976ffff CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7854264u); flags=s.arithmetic_flags;
  }
  L0077d8b8: { // 0x77d8b8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077d8b9: { // 0x77d8b9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077d8ba: { // 0x77d8ba: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0077d8bc: { // 0x77d8bc: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  L0077d8bd: { // 0x77d8bd: eb0e JMP 0x0077d8cd
    goto L0077d8cd;
  }
  L0077d8bf: { // 0x77d8bf: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  L0077d8c5: { // 0x77d8c5: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077d8c8: { // 0x77d8c8: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  L0077d8cb: { // 0x77d8cb: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L0077d8cd: { // 0x77d8cd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077d8cf: { // 0x77d8cf: 741c JZ 0x0077d8ed
    if(integer::condition("JZ",flags)) goto L0077d8ed;
  }
  L0077d8d1: { // 0x77d8d1: 837dfc19 CMP dword ptr [EBP + -0x4],0x19
    (void)integer::sub(m.r32((s.bp-0x00000004u)),0x00000019u,32,flags);
  }
  L0077d8d5: { // 0x77d8d5: 7311 JNC 0x0077d8e8
    if(integer::condition("JNC",flags)) goto L0077d8e8;
  }
  L0077d8d7: { // 0x77d8d7: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L0077d8da: { // 0x77d8da: ff45fc INC dword ptr [EBP + -0x4]
    m.w32((s.bp-0x00000004u), integer::increment(m.r32((s.bp-0x00000004u)),32,flags));
  }
  L0077d8dd: { // 0x77d8dd: 80eb30 SUB BL,0x30
    s.bx = with_al(s.bx, integer::sub((s.bx & 0xffu),0x00000030u,8,flags));
  }
  L0077d8e0: { // 0x77d8e0: ff45f4 INC dword ptr [EBP + -0xc]
    m.w32((s.bp-0x0000000cu), integer::increment(m.r32((s.bp-0x0000000cu)),32,flags));
  }
  L0077d8e3: { // 0x77d8e3: ff4df8 DEC dword ptr [EBP + -0x8]
    m.w32((s.bp-0x00000008u), integer::decrement(m.r32((s.bp-0x00000008u)),32,flags));
  }
  L0077d8e6: { // 0x77d8e6: 8818 MOV byte ptr [EAX],BL
    m.w8((s.ax), (s.bx & 0xffu));
  }
  L0077d8e8: { // 0x77d8e8: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0077d8ea: { // 0x77d8ea: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077d8eb: { // 0x77d8eb: ebb9 JMP 0x0077d8a6
    goto L0077d8a6;
  }
  L0077d8ed: { // 0x77d8ed: 80fb2b CMP BL,0x2b
    (void)integer::sub((s.bx & 0xffu),0x0000002bu,8,flags);
  }
  L0077d8f0: { // 0x77d8f0: 0f840affffff JZ 0x0077d800
    if(integer::condition("JZ",flags)) goto L0077d800;
  }
  L0077d8f6: { // 0x77d8f6: 80fb2d CMP BL,0x2d
    (void)integer::sub((s.bx & 0xffu),0x0000002du,8,flags);
  }
  L0077d8f9: { // 0x77d8f9: 0f8401ffffff JZ 0x0077d800
    if(integer::condition("JZ",flags)) goto L0077d800;
  }
  L0077d8ff: { // 0x77d8ff: e9d5feffff JMP 0x0077d7d9
    goto L0077d7d9;
  }
  L0077d904: { // 0x77d904: 39156c778100 CMP dword ptr [0x0081776c],EDX
    (void)integer::sub(m.r32((0x0081776cu)),s.dx,32,flags);
  }
  L0077d90a: { // 0x77d90a: 8955dc MOV dword ptr [EBP + -0x24],EDX
    m.w32((s.bp-0x00000024u), s.dx);
  }
  L0077d90d: { // 0x77d90d: 7e11 JLE 0x0077d920
    if(integer::condition("JLE",flags)) goto L0077d920;
  }
  L0077d90f: { // 0x77d90f: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077d912: { // 0x77d912: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077d913: { // 0x77d913: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077d914: { // 0x77d914: e8b875ffff CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7854361u); flags=s.arithmetic_flags;
  }
  L0077d919: { // 0x77d919: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077d91a: { // 0x77d91a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077d91b: { // 0x77d91b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0077d91d: { // 0x77d91d: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  L0077d91e: { // 0x77d91e: eb0e JMP 0x0077d92e
    goto L0077d92e;
  }
  L0077d920: { // 0x77d920: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  L0077d926: { // 0x77d926: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077d929: { // 0x77d929: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  L0077d92c: { // 0x77d92c: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L0077d92e: { // 0x77d92e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077d930: { // 0x77d930: 0f84aa000000 JZ 0x0077d9e0
    if(integer::condition("JZ",flags)) goto L0077d9e0;
  }
  L0077d936: { // 0x77d936: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0077d938: { // 0x77d938: eb57 JMP 0x0077d991
    goto L0077d991;
  }
  L0077d93a: { // 0x77d93a: 8d4ffe LEA ECX,[EDI + -0x2]
    s.cx = (s.di-0x00000002u);
  }
  L0077d93d: { // 0x77d93d: 80fb31 CMP BL,0x31
    (void)integer::sub((s.bx & 0xffu),0x00000031u,8,flags);
  }
  L0077d940: { // 0x77d940: 894d10 MOV dword ptr [EBP + 0x10],ECX
    m.w32((s.bp+0x00000010u), s.cx);
  }
  L0077d943: { // 0x77d943: 7c05 JL 0x0077d94a
    if(integer::condition("JL",flags)) goto L0077d94a;
  }
  L0077d945: { // 0x77d945: 80fb39 CMP BL,0x39
    (void)integer::sub((s.bx & 0xffu),0x00000039u,8,flags);
  }
  L0077d948: { // 0x77d948: 7e44 JLE 0x0077d98e
    if(integer::condition("JLE",flags)) goto L0077d98e;
  }
  L0077d94a: { // 0x77d94a: 0fbec3 MOVSX EAX,BL
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffu),8));
  }
  L0077d94d: { // 0x77d94d: 83e82b SUB EAX,0x2b
    s.ax = integer::sub(s.ax,0x0000002bu,32,flags);
  }
  L0077d950: { // 0x77d950: 7474 JZ 0x0077d9c6
    if(integer::condition("JZ",flags)) goto L0077d9c6;
  }
  L0077d952: { // 0x77d952: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077d953: { // 0x77d953: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077d954: { // 0x77d954: 7464 JZ 0x0077d9ba
    if(integer::condition("JZ",flags)) goto L0077d9ba;
  }
  L0077d956: { // 0x77d956: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L0077d959: { // 0x77d959: 0f850f010000 JNZ 0x0077da6e
    if(integer::condition("JNZ",flags)) goto L0077da6e;
  }
  L0077d95f: { // 0x77d95f: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0077d961: { // 0x77d961: eb65 JMP 0x0077d9c8
    goto L0077d9c8;
  }
  L0077d963: { // 0x77d963: 8955e0 MOV dword ptr [EBP + -0x20],EDX
    m.w32((s.bp-0x00000020u), s.dx);
  }
  L0077d966: { // 0x77d966: 80fb30 CMP BL,0x30
    (void)integer::sub((s.bx & 0xffu),0x00000030u,8,flags);
  }
  L0077d969: { // 0x77d969: 7505 JNZ 0x0077d970
    if(integer::condition("JNZ",flags)) goto L0077d970;
  }
  L0077d96b: { // 0x77d96b: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0077d96d: { // 0x77d96d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077d96e: { // 0x77d96e: ebf6 JMP 0x0077d966
    goto L0077d966;
  }
  L0077d970: { // 0x77d970: 80fb31 CMP BL,0x31
    (void)integer::sub((s.bx & 0xffu),0x00000031u,8,flags);
  }
  L0077d973: { // 0x77d973: 0f8cf2000000 JL 0x0077da6b
    if(integer::condition("JL",flags)) goto L0077da6b;
  }
  L0077d979: { // 0x77d979: 80fb39 CMP BL,0x39
    (void)integer::sub((s.bx & 0xffu),0x00000039u,8,flags);
  }
  L0077d97c: { // 0x77d97c: 0f8fe9000000 JG 0x0077da6b
    if(integer::condition("JG",flags)) goto L0077da6b;
  }
  L0077d982: { // 0x77d982: eb0a JMP 0x0077d98e
    goto L0077d98e;
  }
  L0077d984: { // 0x77d984: 80fb31 CMP BL,0x31
    (void)integer::sub((s.bx & 0xffu),0x00000031u,8,flags);
  }
  L0077d987: { // 0x77d987: 7c0e JL 0x0077d997
    if(integer::condition("JL",flags)) goto L0077d997;
  }
  L0077d989: { // 0x77d989: 80fb39 CMP BL,0x39
    (void)integer::sub((s.bx & 0xffu),0x00000039u,8,flags);
  }
  L0077d98c: { // 0x77d98c: 7f09 JG 0x0077d997
    if(integer::condition("JG",flags)) goto L0077d997;
  }
  L0077d98e: { // 0x77d98e: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  L0077d990: { // 0x77d990: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077d991: { // 0x77d991: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0077d992: { // 0x77d992: e9b8fdffff JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d997: { // 0x77d997: 80fb30 CMP BL,0x30
    (void)integer::sub((s.bx & 0xffu),0x00000030u,8,flags);
  }
  L0077d99a: { // 0x77d99a: 7544 JNZ 0x0077d9e0
    if(integer::condition("JNZ",flags)) goto L0077d9e0;
  }
  L0077d99c: { // 0x77d99c: ebc1 JMP 0x0077d95f
    goto L0077d95f;
  }
  L0077d99e: { // 0x77d99e: 837d2000 CMP dword ptr [EBP + 0x20],0x0
    (void)integer::sub(m.r32((s.bp+0x00000020u)),0x00000000u,32,flags);
  }
  L0077d9a2: { // 0x77d9a2: 742a JZ 0x0077d9ce
    if(integer::condition("JZ",flags)) goto L0077d9ce;
  }
  L0077d9a4: { // 0x77d9a4: 0fbec3 MOVSX EAX,BL
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffu),8));
  }
  L0077d9a7: { // 0x77d9a7: 8d4fff LEA ECX,[EDI + -0x1]
    s.cx = (s.di-0x00000001u);
  }
  L0077d9aa: { // 0x77d9aa: 83e82b SUB EAX,0x2b
    s.ax = integer::sub(s.ax,0x0000002bu,32,flags);
  }
  L0077d9ad: { // 0x77d9ad: 894d10 MOV dword ptr [EBP + 0x10],ECX
    m.w32((s.bp+0x00000010u), s.cx);
  }
  L0077d9b0: { // 0x77d9b0: 7414 JZ 0x0077d9c6
    if(integer::condition("JZ",flags)) goto L0077d9c6;
  }
  L0077d9b2: { // 0x77d9b2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077d9b3: { // 0x77d9b3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077d9b4: { // 0x77d9b4: 0f85b4000000 JNZ 0x0077da6e
    if(integer::condition("JNZ",flags)) goto L0077da6e;
  }
  L0077d9ba: { // 0x77d9ba: 834de8ff OR dword ptr [EBP + -0x18],0xffffffff
    m.w32((s.bp-0x00000018u), integer::logical((m.r32((s.bp-0x00000018u)))|(0xffffffffu),32,flags));
  }
  L0077d9be: { // 0x77d9be: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L0077d9c0: { // 0x77d9c0: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077d9c1: { // 0x77d9c1: e989fdffff JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d9c6: { // 0x77d9c6: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L0077d9c8: { // 0x77d9c8: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077d9c9: { // 0x77d9c9: e981fdffff JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d9ce: { // 0x77d9ce: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  L0077d9d0: { // 0x77d9d0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0077d9d1: { // 0x77d9d1: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077d9d2: { // 0x77d9d2: 83f80a CMP EAX,0xa
    (void)integer::sub(s.ax,0x0000000au,32,flags);
  }
  L0077d9d5: { // 0x77d9d5: 0f8495000000 JZ 0x0077da70
    if(integer::condition("JZ",flags)) goto L0077da70;
  }
  L0077d9db: { // 0x77d9db: e96ffdffff JMP 0x0077d74f
    goto L0077d74f;
  }
  L0077d9e0: { // 0x77d9e0: 8b7d10 MOV EDI,dword ptr [EBP + 0x10]
    s.di = m.r32((s.bp+0x00000010u));
  }
  L0077d9e3: { // 0x77d9e3: e988000000 JMP 0x0077da70
    goto L0077da70;
  }
  L0077d9e8: { // 0x77d9e8: c745e001000000 MOV dword ptr [EBP + -0x20],0x1
    m.w32((s.bp-0x00000020u), 0x00000001u);
  }
  L0077d9ef: { // 0x77d9ef: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0077d9f1: { // 0x77d9f1: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  L0077d9f8: { // 0x77d9f8: 7e0f JLE 0x0077da09
    if(integer::condition("JLE",flags)) goto L0077da09;
  }
  L0077d9fa: { // 0x77d9fa: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077d9fd: { // 0x77d9fd: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0077d9ff: { // 0x77d9ff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077da00: { // 0x77da00: e8cc74ffff CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7854597u); flags=s.arithmetic_flags;
  }
  L0077da05: { // 0x77da05: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077da06: { // 0x77da06: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077da07: { // 0x77da07: eb0f JMP 0x0077da18
    goto L0077da18;
  }
  L0077da09: { // 0x77da09: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  L0077da0f: { // 0x77da0f: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077da12: { // 0x77da12: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  L0077da15: { // 0x77da15: 83e004 AND EAX,0x4
    s.ax = integer::logical((s.ax)&(0x00000004u),32,flags);
  }
  L0077da18: { // 0x77da18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077da1a: { // 0x77da1a: 741c JZ 0x0077da38
    if(integer::condition("JZ",flags)) goto L0077da38;
  }
  L0077da1c: { // 0x77da1c: 0fbecb MOVSX ECX,BL
    s.cx = std::uint32_t(integer::sign_extend((s.bx & 0xffu),8));
  }
  L0077da1f: { // 0x77da1f: 8d04b6 LEA EAX,[ESI + ESI*0x4]
    s.ax = (s.si+(s.si * 0x00000004u));
  }
  L0077da22: { // 0x77da22: 8d7441d0 LEA ESI,[ECX + EAX*0x2 + -0x30]
    s.si = (s.cx+(s.ax * 0x00000002u)-0x00000030u);
  }
  L0077da26: { // 0x77da26: 81fe50140000 CMP ESI,0x1450
    (void)integer::sub(s.si,0x00001450u,32,flags);
  }
  L0077da2c: { // 0x77da2c: 7f05 JG 0x0077da33
    if(integer::condition("JG",flags)) goto L0077da33;
  }
  L0077da2e: { // 0x77da2e: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0077da30: { // 0x77da30: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077da31: { // 0x77da31: ebbe JMP 0x0077d9f1
    goto L0077d9f1;
  }
  L0077da33: { // 0x77da33: be51140000 MOV ESI,0x1451
    s.si = 0x00001451u;
  }
  L0077da38: { // 0x77da38: 8975e4 MOV dword ptr [EBP + -0x1c],ESI
    m.w32((s.bp-0x0000001cu), s.si);
  }
  L0077da3b: { // 0x77da3b: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  L0077da42: { // 0x77da42: 7e0f JLE 0x0077da53
    if(integer::condition("JLE",flags)) goto L0077da53;
  }
  L0077da44: { // 0x77da44: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077da47: { // 0x77da47: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0077da49: { // 0x77da49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077da4a: { // 0x77da4a: e88274ffff CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7854671u); flags=s.arithmetic_flags;
  }
  L0077da4f: { // 0x77da4f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077da50: { // 0x77da50: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077da51: { // 0x77da51: eb0f JMP 0x0077da62
    goto L0077da62;
  }
  L0077da53: { // 0x77da53: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  L0077da59: { // 0x77da59: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0077da5c: { // 0x77da5c: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  L0077da5f: { // 0x77da5f: 83e004 AND EAX,0x4
    s.ax = integer::logical((s.ax)&(0x00000004u),32,flags);
  }
  L0077da62: { // 0x77da62: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077da64: { // 0x77da64: 7405 JZ 0x0077da6b
    if(integer::condition("JZ",flags)) goto L0077da6b;
  }
  L0077da66: { // 0x77da66: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0077da68: { // 0x77da68: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0077da69: { // 0x77da69: ebd0 JMP 0x0077da3b
    goto L0077da3b;
  }
  L0077da6b: { // 0x77da6b: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0077da6c: { // 0x77da6c: eb02 JMP 0x0077da70
    goto L0077da70;
  }
  L0077da6e: { // 0x77da6e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0077da70: { // 0x77da70: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L0077da73: { // 0x77da73: 837df000 CMP dword ptr [EBP + -0x10],0x0
    (void)integer::sub(m.r32((s.bp-0x00000010u)),0x00000000u,32,flags);
  }
  L0077da77: { // 0x77da77: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L0077da79: { // 0x77da79: 0f84d9000000 JZ 0x0077db58
    if(integer::condition("JZ",flags)) goto L0077db58;
  }
  L0077da7f: { // 0x77da7f: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L0077da81: { // 0x77da81: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077da82: { // 0x77da82: 3945fc CMP dword ptr [EBP + -0x4],EAX
    (void)integer::sub(m.r32((s.bp-0x00000004u)),s.ax,32,flags);
  }
  L0077da85: { // 0x77da85: 7615 JBE 0x0077da9c
    if(integer::condition("JBE",flags)) goto L0077da9c;
  }
  L0077da87: { // 0x77da87: 807dbb05 CMP byte ptr [EBP + -0x45],0x5
    (void)integer::sub(m.r8((s.bp-0x00000045u)),0x00000005u,8,flags);
  }
  L0077da8b: { // 0x77da8b: 7c03 JL 0x0077da90
    if(integer::condition("JL",flags)) goto L0077da90;
  }
  L0077da8d: { // 0x77da8d: fe45bb INC byte ptr [EBP + -0x45]
    m.w8((s.bp-0x00000045u), integer::increment(m.r8((s.bp-0x00000045u)),8,flags));
  }
  L0077da90: { // 0x77da90: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  L0077da93: { // 0x77da93: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L0077da96: { // 0x77da96: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077da97: { // 0x77da97: ff45f8 INC dword ptr [EBP + -0x8]
    m.w32((s.bp-0x00000008u), integer::increment(m.r32((s.bp-0x00000008u)),32,flags));
  }
  L0077da9a: { // 0x77da9a: eb03 JMP 0x0077da9f
    goto L0077da9f;
  }
  L0077da9c: { // 0x77da9c: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L0077da9f: { // 0x77da9f: 837dfc00 CMP dword ptr [EBP + -0x4],0x0
    (void)integer::sub(m.r32((s.bp-0x00000004u)),0x00000000u,32,flags);
  }
  L0077daa3: { // 0x77daa3: 0f86a5000000 JBE 0x0077db4e
    if(integer::condition("JBE",flags)) goto L0077db4e;
  }
  L0077daa9: { // 0x77daa9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077daaa: { // 0x77daaa: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L0077daad: { // 0x77daad: 7508 JNZ 0x0077dab7
    if(integer::condition("JNZ",flags)) goto L0077dab7;
  }
  L0077daaf: { // 0x77daaf: ff4dfc DEC dword ptr [EBP + -0x4]
    m.w32((s.bp-0x00000004u), integer::decrement(m.r32((s.bp-0x00000004u)),32,flags));
  }
  L0077dab2: { // 0x77dab2: ff45f8 INC dword ptr [EBP + -0x8]
    m.w32((s.bp-0x00000008u), integer::increment(m.r32((s.bp-0x00000008u)),32,flags));
  }
  L0077dab5: { // 0x77dab5: ebf2 JMP 0x0077daa9
    goto L0077daa9;
  }
  L0077dab7: { // 0x77dab7: 8d45c0 LEA EAX,[EBP + -0x40]
    s.ax = (s.bp-0x00000040u);
  }
  L0077daba: { // 0x77daba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077dabb: { // 0x77dabb: 8d45a4 LEA EAX,[EBP + -0x5c]
    s.ax = (s.bp-0x0000005cu);
  }
  L0077dabe: { // 0x77dabe: ff75fc PUSH dword ptr [EBP + -0x4]
    f.push(m,m.r32((s.bp-0x00000004u)));
  }
  L0077dac1: { // 0x77dac1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077dac2: { // 0x77dac2: e8212a0000 CALL 0x007804e8
    s.arithmetic_flags=flags; invoke(m,s,f,0x007804e8u,7854791u); flags=s.arithmetic_flags;
  }
  L0077dac7: { // 0x77dac7: 8b45e4 MOV EAX,dword ptr [EBP + -0x1c]
    s.ax = m.r32((s.bp-0x0000001cu));
  }
  L0077daca: { // 0x77daca: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0077dacc: { // 0x77dacc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0077dacf: { // 0x77dacf: 394de8 CMP dword ptr [EBP + -0x18],ECX
    (void)integer::sub(m.r32((s.bp-0x00000018u)),s.cx,32,flags);
  }
  L0077dad2: { // 0x77dad2: 7d02 JGE 0x0077dad6
    if(integer::condition("JGE",flags)) goto L0077dad6;
  }
  L0077dad4: { // 0x77dad4: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0077dad6: { // 0x77dad6: 0345f8 ADD EAX,dword ptr [EBP + -0x8]
    s.ax = integer::add(s.ax,m.r32((s.bp-0x00000008u)),32,flags);
  }
  L0077dad9: { // 0x77dad9: 394de0 CMP dword ptr [EBP + -0x20],ECX
    (void)integer::sub(m.r32((s.bp-0x00000020u)),s.cx,32,flags);
  }
  L0077dadc: { // 0x77dadc: 7503 JNZ 0x0077dae1
    if(integer::condition("JNZ",flags)) goto L0077dae1;
  }
  L0077dade: { // 0x77dade: 034518 ADD EAX,dword ptr [EBP + 0x18]
    s.ax = integer::add(s.ax,m.r32((s.bp+0x00000018u)),32,flags);
  }
  L0077dae1: { // 0x77dae1: 394ddc CMP dword ptr [EBP + -0x24],ECX
    (void)integer::sub(m.r32((s.bp-0x00000024u)),s.cx,32,flags);
  }
  L0077dae4: { // 0x77dae4: 7503 JNZ 0x0077dae9
    if(integer::condition("JNZ",flags)) goto L0077dae9;
  }
  L0077dae6: { // 0x77dae6: 2b451c SUB EAX,dword ptr [EBP + 0x1c]
    s.ax = integer::sub(s.ax,m.r32((s.bp+0x0000001cu)),32,flags);
  }
  L0077dae9: { // 0x77dae9: 3d50140000 CMP EAX,0x1450
    (void)integer::sub(s.ax,0x00001450u,32,flags);
  }
  L0077daee: { // 0x77daee: 7e30 JLE 0x0077db20
    if(integer::condition("JLE",flags)) goto L0077db20;
  }
  L0077daf0: { // 0x77daf0: c745d401000000 MOV dword ptr [EBP + -0x2c],0x1
    m.w32((s.bp-0x0000002cu), 0x00000001u);
  }
  L0077daf7: { // 0x77daf7: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0077dafa: { // 0x77dafa: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  L0077dafd: { // 0x77dafd: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0077db00: { // 0x77db00: 8b5510 MOV EDX,dword ptr [EBP + 0x10]
    s.dx = m.r32((s.bp+0x00000010u));
  }
  L0077db03: { // 0x77db03: 837dd400 CMP dword ptr [EBP + -0x2c],0x0
    (void)integer::sub(m.r32((s.bp-0x0000002cu)),0x00000000u,32,flags);
  }
  L0077db07: { // 0x77db07: 7460 JZ 0x0077db69
    if(integer::condition("JZ",flags)) goto L0077db69;
  }
  L0077db09: { // 0x77db09: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077db0b: { // 0x77db0b: b8ff7f0000 MOV EAX,0x7fff
    s.ax = 0x00007fffu;
  }
  L0077db10: { // 0x77db10: be00000080 MOV ESI,0x80000000
    s.si = 0x80000000u;
  }
  L0077db15: { // 0x77db15: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0077db17: { // 0x77db17: c745ec02000000 MOV dword ptr [EBP + -0x14],0x2
    m.w32((s.bp-0x00000014u), 0x00000002u);
  }
  L0077db1e: { // 0x77db1e: eb5e JMP 0x0077db7e
    goto L0077db7e;
  }
  L0077db20: { // 0x77db20: 3db0ebffff CMP EAX,0xffffebb0
    (void)integer::sub(s.ax,0xffffebb0u,32,flags);
  }
  L0077db25: { // 0x77db25: 7d09 JGE 0x0077db30
    if(integer::condition("JGE",flags)) goto L0077db30;
  }
  L0077db27: { // 0x77db27: c745d001000000 MOV dword ptr [EBP + -0x30],0x1
    m.w32((s.bp-0x00000030u), 0x00000001u);
  }
  L0077db2e: { // 0x77db2e: ebc7 JMP 0x0077daf7
    goto L0077daf7;
  }
  L0077db30: { // 0x77db30: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  L0077db33: { // 0x77db33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077db34: { // 0x77db34: 8d45c0 LEA EAX,[EBP + -0x40]
    s.ax = (s.bp-0x00000040u);
  }
  L0077db37: { // 0x77db37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077db38: { // 0x77db38: e80b310000 CALL 0x00780c48
    s.arithmetic_flags=flags; invoke(m,s,f,0x00780c48u,7854909u); flags=s.arithmetic_flags;
  }
  L0077db3d: { // 0x77db3d: 8b55c0 MOV EDX,dword ptr [EBP + -0x40]
    s.dx = m.r32((s.bp-0x00000040u));
  }
  L0077db40: { // 0x77db40: 8b5dc2 MOV EBX,dword ptr [EBP + -0x3e]
    s.bx = m.r32((s.bp-0x0000003eu));
  }
  L0077db43: { // 0x77db43: 8b75c6 MOV ESI,dword ptr [EBP + -0x3a]
    s.si = m.r32((s.bp-0x0000003au));
  }
  L0077db46: { // 0x77db46: 8b45ca MOV EAX,dword ptr [EBP + -0x36]
    s.ax = m.r32((s.bp-0x00000036u));
  }
  L0077db49: { // 0x77db49: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0077db4c: { // 0x77db4c: ebb5 JMP 0x0077db03
    goto L0077db03;
  }
  L0077db4e: { // 0x77db4e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0077db50: { // 0x77db50: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077db52: { // 0x77db52: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0077db54: { // 0x77db54: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077db56: { // 0x77db56: ebab JMP 0x0077db03
    goto L0077db03;
  }
  L0077db58: { // 0x77db58: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0077db5a: { // 0x77db5a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077db5c: { // 0x77db5c: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0077db5e: { // 0x77db5e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077db60: { // 0x77db60: c745ec04000000 MOV dword ptr [EBP + -0x14],0x4
    m.w32((s.bp-0x00000014u), 0x00000004u);
  }
  L0077db67: { // 0x77db67: eb15 JMP 0x0077db7e
    goto L0077db7e;
  }
  L0077db69: { // 0x77db69: 837dd000 CMP dword ptr [EBP + -0x30],0x0
    (void)integer::sub(m.r32((s.bp-0x00000030u)),0x00000000u,32,flags);
  }
  L0077db6d: { // 0x77db6d: 740f JZ 0x0077db7e
    if(integer::condition("JZ",flags)) goto L0077db7e;
  }
  L0077db6f: { // 0x77db6f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0077db71: { // 0x77db71: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077db73: { // 0x77db73: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0077db75: { // 0x77db75: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077db77: { // 0x77db77: c745ec01000000 MOV dword ptr [EBP + -0x14],0x1
    m.w32((s.bp-0x00000014u), 0x00000001u);
  }
  L0077db7e: { // 0x77db7e: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0077db81: { // 0x77db81: 0b45d8 OR EAX,dword ptr [EBP + -0x28]
    s.ax = integer::logical((s.ax)|(m.r32((s.bp-0x00000028u))),32,flags);
  }
  L0077db84: { // 0x77db84: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077db85: { // 0x77db85: 897106 MOV dword ptr [ECX + 0x6],ESI
    m.w32((s.cx+0x00000006u), s.si);
  }
  L0077db88: { // 0x77db88: 895902 MOV dword ptr [ECX + 0x2],EBX
    m.w32((s.cx+0x00000002u), s.bx);
  }
  L0077db8b: { // 0x77db8b: 6689410a MOV word ptr [ECX + 0xa],AX
    m.w16((s.cx+0x0000000au), (s.ax & 0xffffu));
  }
  L0077db8f: { // 0x77db8f: 8b45ec MOV EAX,dword ptr [EBP + -0x14]
    s.ax = m.r32((s.bp-0x00000014u));
  }
  L0077db92: { // 0x77db92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077db93: { // 0x77db93: 668911 MOV word ptr [ECX],DX
    m.w16((s.cx), (s.dx & 0xffffu));
  }
  L0077db96: { // 0x77db96: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077db97: { // 0x77db97: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077db98: { // 0x77db98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
