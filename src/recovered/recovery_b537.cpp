#include "recovered/recovery_b537_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b537 {
namespace {
void f_0014d560(Memory&,State&,Frame&,const Operations&);
void f_001621b0(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b560(Memory&,State&,Frame&,const Operations&);
void f_0007b580(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0014d560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054d560: { // 0x54d560: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0054d563: { // 0x54d563: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0054d567: { // 0x54d567: 8b515c MOV EDX,dword ptr [ECX + 0x5c]
    s.dx = m.r32((s.cx+0x0000005cu));
  }
  L0054d56a: { // 0x54d56a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d56b: { // 0x54d56b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054d56c: { // 0x54d56c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054d56d: { // 0x54d56d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d56f: { // 0x54d56f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054d570: { // 0x54d570: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0054d574: { // 0x54d574: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0054d578: { // 0x54d578: 0f8d8b000000 JGE 0x0054d609
    if(integer::condition("JGE",flags)) goto L0054d609;
  }
  L0054d57e: { // 0x54d57e: 8b4950 MOV ECX,dword ptr [ECX + 0x50]
    s.cx = m.r32((s.cx+0x00000050u));
  }
  L0054d581: { // 0x54d581: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0054d585: { // 0x54d585: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054d588: { // 0x54d588: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0054d58a: { // 0x54d58a: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0054d58d: { // 0x54d58d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054d58f: { // 0x54d58f: 7564 JNZ 0x0054d5f5
    if(integer::condition("JNZ",flags)) goto L0054d5f5;
  }
  L0054d591: { // 0x54d591: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L0054d593: { // 0x54d593: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0054d596: { // 0x54d596: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0054d599: { // 0x54d599: 0fbfd8 MOVSX EBX,AX
    s.bx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054d59c: { // 0x54d59c: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L0054d59e: { // 0x54d59e: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0054d5a2: { // 0x54d5a2: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0054d5a4: { // 0x54d5a4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0054d5a8: { // 0x54d5a8: 7526 JNZ 0x0054d5d0
    if(integer::condition("JNZ",flags)) goto L0054d5d0;
  }
  L0054d5aa: { // 0x54d5aa: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L0054d5ae: { // 0x54d5ae: 663b44241e CMP AX,word ptr [ESP + 0x1e]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags);
  }
  L0054d5b3: { // 0x54d5b3: 7c40 JL 0x0054d5f5
    if(integer::condition("JL",flags)) goto L0054d5f5;
  }
  L0054d5b5: { // 0x54d5b5: 663b442412 CMP AX,word ptr [ESP + 0x12]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags);
  }
  L0054d5ba: { // 0x54d5ba: 7f39 JG 0x0054d5f5
    if(integer::condition("JG",flags)) goto L0054d5f5;
  }
  L0054d5bc: { // 0x54d5bc: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0054d5bf: { // 0x54d5bf: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5c1: { // 0x54d5c1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054d5c2: { // 0x54d5c2: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054d5c4: { // 0x54d5c4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5c6: { // 0x54d5c6: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0054d5ca: { // 0x54d5ca: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5cc: { // 0x54d5cc: 7e48 JLE 0x0054d616
    if(integer::condition("JLE",flags)) goto L0054d616;
  }
  L0054d5ce: { // 0x54d5ce: eb25 JMP 0x0054d5f5
    goto L0054d5f5;
  }
  L0054d5d0: { // 0x54d5d0: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0054d5d3: { // 0x54d5d3: 663bd0 CMP DX,AX
    (void)integer::sub((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0054d5d6: { // 0x54d5d6: 7f1d JG 0x0054d5f5
    if(integer::condition("JG",flags)) goto L0054d5f5;
  }
  L0054d5d8: { // 0x54d5d8: 663bd6 CMP DX,SI
    (void)integer::sub((s.dx & 0xffffu),(s.si & 0xffffu),16,flags);
  }
  L0054d5db: { // 0x54d5db: 7c18 JL 0x0054d5f5
    if(integer::condition("JL",flags)) goto L0054d5f5;
  }
  L0054d5dd: { // 0x54d5dd: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0054d5e1: { // 0x54d5e1: 0fbf54241e MOVSX EDX,word ptr [ESP + 0x1e]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001eu)),16));
  }
  L0054d5e6: { // 0x54d5e6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5e8: { // 0x54d5e8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054d5e9: { // 0x54d5e9: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054d5eb: { // 0x54d5eb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5ed: { // 0x54d5ed: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0054d5f1: { // 0x54d5f1: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5f3: { // 0x54d5f3: 7e21 JLE 0x0054d616
    if(integer::condition("JLE",flags)) goto L0054d616;
  }
  L0054d5f5: { // 0x54d5f5: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054d5f9: { // 0x54d5f9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0054d5fd: { // 0x54d5fd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0054d5fe: { // 0x54d5fe: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0054d601: { // 0x54d601: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d603: { // 0x54d603: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0054d607: { // 0x54d607: 7c81 JL 0x0054d58a
    if(integer::condition("JL",flags)) goto L0054d58a;
  }
  L0054d609: { // 0x54d609: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d60a: { // 0x54d60a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d60b: { // 0x54d60b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d60c: { // 0x54d60c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0054d60f: { // 0x54d60f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d610: { // 0x54d610: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054d613: { // 0x54d613: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0054d616: { // 0x54d616: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054d61a: { // 0x54d61a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d61b: { // 0x54d61b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d61c: { // 0x54d61c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d61d: { // 0x54d61d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d61e: { // 0x54d61e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054d621: { // 0x54d621: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_001621b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005621b0: { // 0x5621b0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005621b4: { // 0x5621b4: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005621b7: { // 0x5621b7: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L005621bb: { // 0x5621bb: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L005621be: { // 0x5621be: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005621c1: { // 0x5621c1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005621c3: { // 0x5621c3: 7818 JS 0x005621dd
    if(integer::condition("JS",flags)) goto L005621dd;
  }
  L005621c5: { // 0x5621c5: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005621ca: { // 0x5621ca: 7d11 JGE 0x005621dd
    if(integer::condition("JGE",flags)) goto L005621dd;
  }
  L005621cc: { // 0x5621cc: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005621d2: { // 0x5621d2: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005621d5: { // 0x5621d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005621d7: { // 0x5621d7: 7404 JZ 0x005621dd
    if(integer::condition("JZ",flags)) goto L005621dd;
  }
  L005621d9: { // 0x5621d9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005621db: { // 0x5621db: eb0c JMP 0x005621e9
    goto L005621e9;
  }
  L005621dd: { // 0x5621dd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005621df: { // 0x5621df: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L005621e4: { // 0x5621e4: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005621e9: { // 0x5621e9: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L005621ef: { // 0x5621ef: 8d9140010000 LEA EDX,[ECX + 0x140]
    s.dx = (s.cx+0x00000140u);
  }
  L005621f5: { // 0x5621f5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005621f8: { // 0x5621f8: 750f JNZ 0x00562209
    if(integer::condition("JNZ",flags)) goto L00562209;
  }
  L005621fa: { // 0x5621fa: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005621fe: { // 0x5621fe: 8b4924 MOV ECX,dword ptr [ECX + 0x24]
    s.cx = m.r32((s.cx+0x00000024u));
  }
  L00562201: { // 0x562201: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00562203: { // 0x562203: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00562206: { // 0x562206: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00562209: { // 0x562209: 2500080000 AND EAX,0x800
    s.ax = integer::logical((s.ax)&(0x00000800u),32,flags);
  }
  L0056220e: { // 0x56220e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056220f: { // 0x56220f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00562211: { // 0x562211: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00562213: { // 0x562213: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00562214: { // 0x562214: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00562216: { // 0x562216: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00562217: { // 0x562217: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0056221a: { // 0x56221a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056221b: { // 0x56221b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0056221d: { // 0x56221d: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00562221: { // 0x562221: 8d70fc LEA ESI,[EAX + -0x4]
    s.si = (s.ax-0x00000004u);
  }
  L00562224: { // 0x562224: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00562226: { // 0x562226: 83e607 AND ESI,0x7
    s.si = integer::logical((s.si)&(0x00000007u),32,flags);
  }
  L00562229: { // 0x562229: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0056222b: { // 0x56222b: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0056222f: { // 0x56222f: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00562231: { // 0x562231: 8b0d5c6ea500 MOV ECX,dword ptr [0x00a56e5c]
    s.cx = m.r32((0x00a56e5cu));
  }
  L00562237: { // 0x562237: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056223b: { // 0x56223b: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0056223f: { // 0x56223f: eb04 JMP 0x00562245
    goto L00562245;
  }
  L00562241: { // 0x562241: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00562245: { // 0x562245: 8b4d00 MOV ECX,dword ptr [EBP]
    s.cx = m.r32((s.bp));
  }
  L00562248: { // 0x562248: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0056224b: { // 0x56224b: 7441 JZ 0x0056228e
    if(integer::condition("JZ",flags)) goto L0056228e;
  }
  L0056224d: { // 0x56224d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056224e: { // 0x56224e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00562250: { // 0x562250: e86b44f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5644885u); flags=s.arithmetic_flags;
  }
  L00562255: { // 0x562255: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00562257: { // 0x562257: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0056225d: { // 0x56225d: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00562260: { // 0x562260: 8daf40010000 LEA EBP,[EDI + 0x140]
    s.bp = (s.di+0x00000140u);
  }
  L00562266: { // 0x562266: 7526 JNZ 0x0056228e
    if(integer::condition("JNZ",flags)) goto L0056228e;
  }
  L00562268: { // 0x562268: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0056226a: { // 0x56226a: e8f192f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5644911u); flags=s.arithmetic_flags;
  }
  L0056226f: { // 0x56226f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00562271: { // 0x562271: 750b JNZ 0x0056227e
    if(integer::condition("JNZ",flags)) goto L0056227e;
  }
  L00562273: { // 0x562273: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00562275: { // 0x562275: e80693f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5644922u); flags=s.arithmetic_flags;
  }
  L0056227a: { // 0x56227a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056227c: { // 0x56227c: 7410 JZ 0x0056228e
    if(integer::condition("JZ",flags)) goto L0056228e;
  }
  L0056227e: { // 0x56227e: 83bfec00000003 CMP dword ptr [EDI + 0xec],0x3
    (void)integer::sub(m.r32((s.di+0x000000ecu)),0x00000003u,32,flags);
  }
  L00562285: { // 0x562285: 7407 JZ 0x0056228e
    if(integer::condition("JZ",flags)) goto L0056228e;
  }
  L00562287: { // 0x562287: 8b5724 MOV EDX,dword ptr [EDI + 0x24]
    s.dx = m.r32((s.di+0x00000024u));
  }
  L0056228a: { // 0x56228a: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0056228e: { // 0x56228e: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00562290: { // 0x562290: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00562293: { // 0x562293: 7450 JZ 0x005622e5
    if(integer::condition("JZ",flags)) goto L005622e5;
  }
  L00562295: { // 0x562295: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00562299: { // 0x562299: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056229b: { // 0x56229b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056229c: { // 0x56229c: e81f44f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5644961u); flags=s.arithmetic_flags;
  }
  L005622a1: { // 0x5622a1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005622a3: { // 0x5622a3: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L005622a9: { // 0x5622a9: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005622ac: { // 0x5622ac: 8d9e40010000 LEA EBX,[ESI + 0x140]
    s.bx = (s.si+0x00000140u);
  }
  L005622b2: { // 0x5622b2: 758d JNZ 0x00562241
    if(integer::condition("JNZ",flags)) goto L00562241;
  }
  L005622b4: { // 0x5622b4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005622b6: { // 0x5622b6: e8a592f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5644987u); flags=s.arithmetic_flags;
  }
  L005622bb: { // 0x5622bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005622bd: { // 0x5622bd: 750b JNZ 0x005622ca
    if(integer::condition("JNZ",flags)) goto L005622ca;
  }
  L005622bf: { // 0x5622bf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005622c1: { // 0x5622c1: e8ba92f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5644998u); flags=s.arithmetic_flags;
  }
  L005622c6: { // 0x5622c6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005622c8: { // 0x5622c8: 7410 JZ 0x005622da
    if(integer::condition("JZ",flags)) goto L005622da;
  }
  L005622ca: { // 0x5622ca: 83beec00000003 CMP dword ptr [ESI + 0xec],0x3
    (void)integer::sub(m.r32((s.si+0x000000ecu)),0x00000003u,32,flags);
  }
  L005622d1: { // 0x5622d1: 7407 JZ 0x005622da
    if(integer::condition("JZ",flags)) goto L005622da;
  }
  L005622d3: { // 0x5622d3: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L005622d6: { // 0x5622d6: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005622da: { // 0x5622da: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L005622dc: { // 0x5622dc: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005622df: { // 0x5622df: 0f855cffffff JNZ 0x00562241
    if(integer::condition("JNZ",flags)) goto L00562241;
  }
  L005622e5: { // 0x5622e5: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005622e8: { // 0x5622e8: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005622eb: { // 0x5622eb: 0f8550ffffff JNZ 0x00562241
    if(integer::condition("JNZ",flags)) goto L00562241;
  }
  L005622f1: { // 0x5622f1: 8b1d5c6ea500 MOV EBX,dword ptr [0x00a56e5c]
    s.bx = m.r32((0x00a56e5cu));
  }
  L005622f7: { // 0x5622f7: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005622fb: { // 0x5622fb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005622fd: { // 0x5622fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005622fe: { // 0x5622fe: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00562303: { // 0x562303: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L00562307: { // 0x562307: e84451ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5645068u); flags=s.arithmetic_flags;
  }
  L0056230c: { // 0x56230c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056230e: { // 0x56230e: 7408 JZ 0x00562318
    if(integer::condition("JZ",flags)) goto L00562318;
  }
  L00562310: { // 0x562310: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L00562314: { // 0x562314: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00562318: { // 0x562318: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0056231c: { // 0x56231c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0056231e: { // 0x56231e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056231f: { // 0x56231f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00562324: { // 0x562324: e82751ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5645097u); flags=s.arithmetic_flags;
  }
  L00562329: { // 0x562329: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056232b: { // 0x56232b: 0f84b4000000 JZ 0x005623e5
    if(integer::condition("JZ",flags)) goto L005623e5;
  }
  L00562331: { // 0x562331: 663b1d5c6ea500 CMP BX,word ptr [0x00a56e5c]
    (void)integer::sub((s.bx & 0xffffu),m.r16((0x00a56e5cu)),16,flags);
  }
  L00562338: { // 0x562338: 7512 JNZ 0x0056234c
    if(integer::condition("JNZ",flags)) goto L0056234c;
  }
  L0056233a: { // 0x56233a: 668b4c2416 MOV CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000016u)));
  }
  L0056233f: { // 0x56233f: 663b0d5e6ea500 CMP CX,word ptr [0x00a56e5e]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a56e5eu)),16,flags);
  }
  L00562346: { // 0x562346: 0f8495000000 JZ 0x005623e1
    if(integer::condition("JZ",flags)) goto L005623e1;
  }
  L0056234c: { // 0x56234c: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L00562350: { // 0x562350: 668b4c2412 MOV CX,word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000012u)));
  }
  L00562355: { // 0x562355: 668b442410 MOV AX,word ptr [ESP + 0x10]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000010u)));
  }
  L0056235a: { // 0x56235a: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0056235d: { // 0x56235d: 662b4e02 SUB CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L00562361: { // 0x562361: 662b06 SUB AX,word ptr [ESI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00562364: { // 0x562364: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00562367: { // 0x562367: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056236a: { // 0x56236a: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0056236e: { // 0x56236e: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L00562372: { // 0x562372: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00562376: { // 0x562376: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L0056237a: { // 0x56237a: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0056237c: { // 0x56237c: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0056237e: { // 0x56237e: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00562380: { // 0x562380: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00562382: { // 0x562382: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00562384: { // 0x562384: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00562387: { // 0x562387: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00562389: { // 0x562389: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0056238b: { // 0x56238b: e8f07cf5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5645200u); flags=s.arithmetic_flags;
  }
  L00562390: { // 0x562390: e8bb862000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5645205u); flags=s.arithmetic_flags;
  }
  L00562395: { // 0x562395: 668b4c242e MOV CX,word ptr [ESP + 0x2e]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000002eu)));
  }
  L0056239a: { // 0x56239a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0056239c: { // 0x56239c: 662b4e02 SUB CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L005623a0: { // 0x5623a0: 668b44242c MOV AX,word ptr [ESP + 0x2c]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002cu)));
  }
  L005623a5: { // 0x5623a5: 662b06 SUB AX,word ptr [ESI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags));
  }
  L005623a8: { // 0x5623a8: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005623ab: { // 0x5623ab: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005623ae: { // 0x5623ae: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L005623b2: { // 0x5623b2: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L005623b6: { // 0x5623b6: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L005623ba: { // 0x5623ba: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L005623be: { // 0x5623be: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L005623c0: { // 0x5623c0: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L005623c2: { // 0x5623c2: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L005623c4: { // 0x5623c4: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L005623c6: { // 0x5623c6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L005623c8: { // 0x5623c8: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005623cb: { // 0x5623cb: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005623cd: { // 0x5623cd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005623cf: { // 0x5623cf: e8ac7cf5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5645268u); flags=s.arithmetic_flags;
  }
  L005623d4: { // 0x5623d4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005623d7: { // 0x5623d7: e874862000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5645276u); flags=s.arithmetic_flags;
  }
  L005623dc: { // 0x5623dc: 663bf8 CMP DI,AX
    (void)integer::sub((s.di & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L005623df: { // 0x5623df: 7d04 JGE 0x005623e5
    if(integer::condition("JGE",flags)) goto L005623e5;
  }
  L005623e1: { // 0x5623e1: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L005623e5: { // 0x5623e5: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L005623e9: { // 0x5623e9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005623ea: { // 0x5623ea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005623eb: { // 0x5623eb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005623ec: { // 0x5623ec: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005623ee: { // 0x5623ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005623ef: { // 0x5623ef: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005623f2: { // 0x5623f2: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
void f_0007b560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b560: { // 0x47b560: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b563: { // 0x47b563: 8b0db0a8a300 MOV ECX,dword ptr [0x00a3a8b0]
    s.cx = m.r32((0x00a3a8b0u));
  }
  L0047b569: { // 0x47b569: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b56b: { // 0x47b56b: 7c0a JL 0x0047b577
    if(integer::condition("JL",flags)) goto L0047b577;
  }
  L0047b56d: { // 0x47b56d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b570: { // 0x47b570: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b572: { // 0x47b572: 7d03 JGE 0x0047b577
    if(integer::condition("JGE",flags)) goto L0047b577;
  }
  L0047b574: { // 0x47b574: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b576: { // 0x47b576: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b577: { // 0x47b577: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b579: { // 0x47b579: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b580: { // 0x47b580: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b583: { // 0x47b583: 8b0da047a500 MOV ECX,dword ptr [0x00a547a0]
    s.cx = m.r32((0x00a547a0u));
  }
  L0047b589: { // 0x47b589: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b58b: { // 0x47b58b: 7c0a JL 0x0047b597
    if(integer::condition("JL",flags)) goto L0047b597;
  }
  L0047b58d: { // 0x47b58d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b590: { // 0x47b590: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b592: { // 0x47b592: 7d03 JGE 0x0047b597
    if(integer::condition("JGE",flags)) goto L0047b597;
  }
  L0047b594: { // 0x47b594: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b596: { // 0x47b596: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b597: { // 0x47b597: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b599: { // 0x47b599: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5559648u:f_0014d560(m,s,child,{});break;
case 5644720u:f_001621b0(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4699488u:f_0007b560(m,s,child,{});break;
case 4699520u:f_0007b580(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery537 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00561d60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00561d60: { // 0x561d60: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  L00561d64: { // 0x561d64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00561d65: { // 0x561d65: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L00561d69: { // 0x561d69: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00561d6a: { // 0x561d6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00561d6b: { // 0x561d6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561d6c: { // 0x561d6c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00561d6e: { // 0x561d6e: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00561d70: { // 0x561d70: 0f8446020000 JZ 0x00561fbc
    if(integer::condition("JZ",flags)) goto L00561fbc;
  }
  L00561d76: { // 0x561d76: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00561d7c: { // 0x561d7c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00561d7f: { // 0x561d7f: 0f8437020000 JZ 0x00561fbc
    if(integer::condition("JZ",flags)) goto L00561fbc;
  }
  L00561d85: { // 0x561d85: 8d7b24 LEA EDI,[EBX + 0x24]
    s.di = (s.bx+0x00000024u);
  }
  L00561d88: { // 0x561d88: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00561d8a: { // 0x561d8a: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00561d8c: { // 0x561d8c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561d8d: { // 0x561d8d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00561d92: { // 0x561d92: e8c9b7feff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5643671u); flags=s.arithmetic_flags;
  }
  L00561d97: { // 0x561d97: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00561d99: { // 0x561d99: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L00561d9c: { // 0x561d9c: 753a JNZ 0x00561dd8
    if(integer::condition("JNZ",flags)) goto L00561dd8;
  }
  L00561d9e: { // 0x561d9e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561d9f: { // 0x561d9f: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00561da3: { // 0x561da3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561da4: { // 0x561da4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00561da5: { // 0x561da5: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00561da7: { // 0x561da7: e804040000 CALL 0x005621b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005621b0u,5643692u); flags=s.arithmetic_flags;
  }
  L00561dac: { // 0x561dac: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00561dae: { // 0x561dae: 663b055c6ea500 CMP AX,word ptr [0x00a56e5c]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a56e5cu)),16,flags);
  }
  L00561db5: { // 0x561db5: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00561db9: { // 0x561db9: 750e JNZ 0x00561dc9
    if(integer::condition("JNZ",flags)) goto L00561dc9;
  }
  L00561dbb: { // 0x561dbb: 668b4c241e MOV CX,word ptr [ESP + 0x1e]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000001eu)));
  }
  L00561dc0: { // 0x561dc0: 663b0d5e6ea500 CMP CX,word ptr [0x00a56e5e]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a56e5eu)),16,flags);
  }
  L00561dc7: { // 0x561dc7: 740f JZ 0x00561dd8
    if(integer::condition("JZ",flags)) goto L00561dd8;
  }
  L00561dc9: { // 0x561dc9: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00561dcd: { // 0x561dcd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561dce: { // 0x561dce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561dcf: { // 0x561dcf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561dd0: { // 0x561dd0: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00561dd2: { // 0x561dd2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00561dd4: { // 0x561dd4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561dd5: { // 0x561dd5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00561dd8: { // 0x561dd8: 8b1570a88100 MOV EDX,dword ptr [0x0081a870]
    s.dx = m.r32((0x0081a870u));
  }
  L00561dde: { // 0x561dde: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00561de4: { // 0x561de4: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  L00561de7: { // 0x561de7: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00561de9: { // 0x561de9: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00561dec: { // 0x561dec: 741a JZ 0x00561e08
    if(integer::condition("JZ",flags)) goto L00561e08;
  }
  L00561dee: { // 0x561dee: 668b5326 MOV DX,word ptr [EBX + 0x26]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000026u)));
  }
  L00561df2: { // 0x561df2: 66c744241c0000 MOV word ptr [ESP + 0x1c],0x0
    m.w16((f.sp+0x0000001cu), 0x00000000u);
  }
  L00561df9: { // 0x561df9: 662b5602 SUB DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L00561dfd: { // 0x561dfd: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00561e02: { // 0x561e02: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L00561e06: { // 0x561e06: eb16 JMP 0x00561e1e
    goto L00561e1e;
  }
  L00561e08: { // 0x561e08: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L00561e0b: { // 0x561e0b: 66c744241e0000 MOV word ptr [ESP + 0x1e],0x0
    m.w16((f.sp+0x0000001eu), 0x00000000u);
  }
  L00561e12: { // 0x561e12: 662b0e SUB CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00561e15: { // 0x561e15: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00561e1a: { // 0x561e1a: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L00561e1e: { // 0x561e1e: 8a4e08 MOV CL,byte ptr [ESI + 0x8]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000008u)));
  }
  L00561e21: { // 0x561e21: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00561e25: { // 0x561e25: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00561e27: { // 0x561e27: 0f84ef000000 JZ 0x00561f1c
    if(integer::condition("JZ",flags)) goto L00561f1c;
  }
  L00561e2d: { // 0x561e2d: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L00561e31: { // 0x561e31: 668b5c241e MOV BX,word ptr [ESP + 0x1e]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x0000001eu)));
  }
  L00561e36: { // 0x561e36: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L00561e39: { // 0x561e39: 6603cb ADD CX,BX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561e3c: { // 0x561e3c: 662b4f02 SUB CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00561e40: { // 0x561e40: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561e43: { // 0x561e43: 662b07 SUB AX,word ptr [EDI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.di)),16,flags));
  }
  L00561e46: { // 0x561e46: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00561e49: { // 0x561e49: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00561e4c: { // 0x561e4c: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00561e4f: { // 0x561e4f: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00561e53: { // 0x561e53: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561e57: { // 0x561e57: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00561e5b: { // 0x561e5b: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561e5f: { // 0x561e5f: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00561e61: { // 0x561e61: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00561e63: { // 0x561e63: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00561e65: { // 0x561e65: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00561e67: { // 0x561e67: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00561e69: { // 0x561e69: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00561e6c: { // 0x561e6c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561e6e: { // 0x561e6e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561e70: { // 0x561e70: e80b82f5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5643893u); flags=s.arithmetic_flags;
  }
  L00561e75: { // 0x561e75: e8d68b2000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5643898u); flags=s.arithmetic_flags;
  }
  L00561e7a: { // 0x561e7a: 668b4e06 MOV CX,word ptr [ESI + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000006u)));
  }
  L00561e7e: { // 0x561e7e: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00561e82: { // 0x561e82: 668b4604 MOV AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000004u)));
  }
  L00561e86: { // 0x561e86: 6603cb ADD CX,BX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561e89: { // 0x561e89: 662b4f02 SUB CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00561e8d: { // 0x561e8d: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561e90: { // 0x561e90: 662b07 SUB AX,word ptr [EDI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.di)),16,flags));
  }
  L00561e93: { // 0x561e93: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00561e96: { // 0x561e96: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00561e99: { // 0x561e99: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00561e9d: { // 0x561e9d: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561ea1: { // 0x561ea1: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00561ea5: { // 0x561ea5: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561ea9: { // 0x561ea9: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00561eab: { // 0x561eab: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00561ead: { // 0x561ead: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00561eaf: { // 0x561eaf: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00561eb1: { // 0x561eb1: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00561eb3: { // 0x561eb3: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00561eb6: { // 0x561eb6: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561eb8: { // 0x561eb8: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561eba: { // 0x561eba: e8c181f5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5643967u); flags=s.arithmetic_flags;
  }
  L00561ebf: { // 0x561ebf: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00561ec2: { // 0x561ec2: e8898b2000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5643975u); flags=s.arithmetic_flags;
  }
  L00561ec7: { // 0x561ec7: 6639442418 CMP word ptr [ESP + 0x18],AX
    (void)integer::sub(m.r16((f.sp+0x00000018u)),(s.ax & 0xffffu),16,flags);
  }
  L00561ecc: { // 0x561ecc: 7d28 JGE 0x00561ef6
    if(integer::condition("JGE",flags)) goto L00561ef6;
  }
  L00561ece: { // 0x561ece: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L00561ed1: { // 0x561ed1: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L00561ed5: { // 0x561ed5: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561ed8: { // 0x561ed8: 6603cb ADD CX,BX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561edb: { // 0x561edb: 668944241c MOV word ptr [ESP + 0x1c],AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L00561ee0: { // 0x561ee0: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00561ee4: { // 0x561ee4: 66894c241e MOV word ptr [ESP + 0x1e],CX
    m.w16((f.sp+0x0000001eu), (s.cx & 0xffffu));
  }
  L00561ee9: { // 0x561ee9: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00561eed: { // 0x561eed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561eee: { // 0x561eee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561eef: { // 0x561eef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561ef0: { // 0x561ef0: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00561ef2: { // 0x561ef2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561ef3: { // 0x561ef3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00561ef6: { // 0x561ef6: 668b4606 MOV AX,word ptr [ESI + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000006u)));
  }
  L00561efa: { // 0x561efa: 66036e04 ADD BP,word ptr [ESI + 0x4]
    s.bp = (s.bp & 0xffff0000u) | ((integer::add((s.bp & 0xffffu),m.r16((s.si+0x00000004u)),16,flags)) & 0xffffu);
  }
  L00561efe: { // 0x561efe: 6603c3 ADD AX,BX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561f01: { // 0x561f01: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561f02: { // 0x561f02: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L00561f07: { // 0x561f07: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00561f0b: { // 0x561f0b: 66896c2418 MOV word ptr [ESP + 0x18],BP
    m.w16((f.sp+0x00000018u), (s.bp & 0xffffu));
  }
  L00561f10: { // 0x561f10: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00561f14: { // 0x561f14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561f15: { // 0x561f15: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561f16: { // 0x561f16: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00561f18: { // 0x561f18: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561f19: { // 0x561f19: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00561f1c: { // 0x561f1c: 668b3e MOV DI,word ptr [ESI]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.si))) & 0xffffu);
  }
  L00561f1f: { // 0x561f1f: 662b7e04 SUB DI,word ptr [ESI + 0x4]
    s.di = (s.di & 0xffff0000u) | ((integer::sub((s.di & 0xffffu),m.r16((s.si+0x00000004u)),16,flags)) & 0xffffu);
  }
  L00561f23: { // 0x561f23: 66f7df NEG DI
    s.di = (s.di & 0xffff0000u) | ((integer::sub(0u,(s.di & 0xffffu),16,flags)) & 0xffffu);
  }
  L00561f26: { // 0x561f26: 1bff SBB EDI,EDI
    s.di = integer::sub(s.di,s.di,32,flags,flags&integer::CF);
  }
  L00561f28: { // 0x561f28: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L00561f2b: { // 0x561f2b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00561f2e: { // 0x561f2e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00561f31: { // 0x561f31: 7415 JZ 0x00561f48
    if(integer::condition("JZ",flags)) goto L00561f48;
  }
  L00561f33: { // 0x561f33: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561f34: { // 0x561f34: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00561f36: { // 0x561f36: e88547f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5644091u); flags=s.arithmetic_flags;
  }
  L00561f3b: { // 0x561f3b: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00561f3d: { // 0x561f3d: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00561f43: { // 0x561f43: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00561f46: { // 0x561f46: 75eb JNZ 0x00561f33
    if(integer::condition("JNZ",flags)) goto L00561f33;
  }
  L00561f48: { // 0x561f48: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00561f4a: { // 0x561f4a: e81196f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5644111u); flags=s.arithmetic_flags;
  }
  L00561f4f: { // 0x561f4f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00561f51: { // 0x561f51: 750b JNZ 0x00561f5e
    if(integer::condition("JNZ",flags)) goto L00561f5e;
  }
  L00561f53: { // 0x561f53: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00561f55: { // 0x561f55: e82696f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5644122u); flags=s.arithmetic_flags;
  }
  L00561f5a: { // 0x561f5a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00561f5c: { // 0x561f5c: 7434 JZ 0x00561f92
    if(integer::condition("JZ",flags)) goto L00561f92;
  }
  L00561f5e: { // 0x561f5e: 83bbec00000003 CMP dword ptr [EBX + 0xec],0x3
    (void)integer::sub(m.r32((s.bx+0x000000ecu)),0x00000003u,32,flags);
  }
  L00561f65: { // 0x561f65: 742b JZ 0x00561f92
    if(integer::condition("JZ",flags)) goto L00561f92;
  }
  L00561f67: { // 0x561f67: 668b5604 MOV DX,word ptr [ESI + 0x4]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000004u)));
  }
  L00561f6b: { // 0x561f6b: 668b4606 MOV AX,word ptr [ESI + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000006u)));
  }
  L00561f6f: { // 0x561f6f: 6603d5 ADD DX,BP
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561f72: { // 0x561f72: 660344241e ADD AX,word ptr [ESP + 0x1e]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags));
  }
  L00561f77: { // 0x561f77: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L00561f7c: { // 0x561f7c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561f7d: { // 0x561f7d: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L00561f82: { // 0x561f82: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00561f86: { // 0x561f86: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00561f8a: { // 0x561f8a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561f8b: { // 0x561f8b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561f8c: { // 0x561f8c: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00561f8e: { // 0x561f8e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561f8f: { // 0x561f8f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00561f92: { // 0x561f92: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L00561f95: { // 0x561f95: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L00561f99: { // 0x561f99: 6603d5 ADD DX,BP
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561f9c: { // 0x561f9c: 660344241e ADD AX,word ptr [ESP + 0x1e]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags));
  }
  L00561fa1: { // 0x561fa1: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L00561fa6: { // 0x561fa6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561fa7: { // 0x561fa7: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L00561fac: { // 0x561fac: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00561fb0: { // 0x561fb0: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00561fb4: { // 0x561fb4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561fb5: { // 0x561fb5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561fb6: { // 0x561fb6: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00561fb8: { // 0x561fb8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561fb9: { // 0x561fb9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00561fbc: { // 0x561fbc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00561fc0: { // 0x561fc0: 8b5324 MOV EDX,dword ptr [EBX + 0x24]
    s.dx = m.r32((s.bx+0x00000024u));
  }
  L00561fc3: { // 0x561fc3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561fc4: { // 0x561fc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561fc5: { // 0x561fc5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561fc6: { // 0x561fc6: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00561fc8: { // 0x561fc8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561fc9: { // 0x561fc9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00561fd0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00561fd0: { // 0x561fd0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00561fd1: { // 0x561fd1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00561fd2: { // 0x561fd2: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00561fd6: { // 0x561fd6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00561fd7: { // 0x561fd7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561fd8: { // 0x561fd8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00561fda: { // 0x561fda: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00561fdc: { // 0x561fdc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00561fde: { // 0x561fde: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00561fdf: { // 0x561fdf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00561fe4: { // 0x561fe4: e877b5feff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5644265u); flags=s.arithmetic_flags;
  }
  L00561fe9: { // 0x561fe9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00561fec: { // 0x561fec: 0f846c010000 JZ 0x0056215e
    if(integer::condition("JZ",flags)) goto L0056215e;
  }
  L00561ff2: { // 0x561ff2: 8b0d70a88100 MOV ECX,dword ptr [0x0081a870]
    s.cx = m.r32((0x0081a870u));
  }
  L00561ff8: { // 0x561ff8: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00561ffb: { // 0x561ffb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00561ffd: { // 0x561ffd: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00561fff: { // 0x561fff: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000008u)));
  }
  L00562002: { // 0x562002: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00562004: { // 0x562004: 0f84af000000 JZ 0x005620b9
    if(integer::condition("JZ",flags)) goto L005620b9;
  }
  L0056200a: { // 0x56200a: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0056200e: { // 0x56200e: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00562011: { // 0x562011: 668b4f02 MOV CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000002u)));
  }
  L00562015: { // 0x562015: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00562018: { // 0x562018: 662b4e02 SUB CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L0056201c: { // 0x56201c: 662b06 SUB AX,word ptr [ESI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags));
  }
  L0056201f: { // 0x56201f: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00562022: { // 0x562022: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00562025: { // 0x562025: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00562029: { // 0x562029: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0056202d: { // 0x56202d: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00562031: { // 0x562031: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00562035: { // 0x562035: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00562037: { // 0x562037: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00562039: { // 0x562039: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0056203b: { // 0x56203b: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0056203d: { // 0x56203d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0056203f: { // 0x56203f: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00562042: { // 0x562042: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00562044: { // 0x562044: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00562046: { // 0x562046: e83580f5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5644363u); flags=s.arithmetic_flags;
  }
  L0056204b: { // 0x56204b: e8008a2000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5644368u); flags=s.arithmetic_flags;
  }
  L00562050: { // 0x562050: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00562052: { // 0x562052: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00562055: { // 0x562055: 668b7f02 MOV DI,word ptr [EDI + 0x2]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.di+0x00000002u))) & 0xffffu);
  }
  L00562059: { // 0x562059: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L0056205d: { // 0x56205d: 662b7e06 SUB DI,word ptr [ESI + 0x6]
    s.di = (s.di & 0xffff0000u) | ((integer::sub((s.di & 0xffffu),m.r16((s.si+0x00000006u)),16,flags)) & 0xffffu);
  }
  L00562061: { // 0x562061: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00562064: { // 0x562064: 0fbfcf MOVSX ECX,DI
    s.cx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L00562067: { // 0x562067: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056206b: { // 0x56206b: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0056206f: { // 0x56206f: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00562073: { // 0x562073: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00562077: { // 0x562077: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00562079: { // 0x562079: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0056207b: { // 0x56207b: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0056207d: { // 0x56207d: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0056207f: { // 0x56207f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00562081: { // 0x562081: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00562084: { // 0x562084: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00562086: { // 0x562086: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00562088: { // 0x562088: e8f37ff5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5644429u); flags=s.arithmetic_flags;
  }
  L0056208d: { // 0x56208d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00562090: { // 0x562090: e8bb892000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5644437u); flags=s.arithmetic_flags;
  }
  L00562095: { // 0x562095: 663bd8 CMP BX,AX
    (void)integer::sub((s.bx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L00562098: { // 0x562098: 7d0f JGE 0x005620a9
    if(integer::condition("JGE",flags)) goto L005620a9;
  }
  L0056209a: { // 0x56209a: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0056209c: { // 0x56209c: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005620a0: { // 0x5620a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005620a1: { // 0x5620a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005620a2: { // 0x5620a2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005620a3: { // 0x5620a3: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005620a5: { // 0x5620a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005620a6: { // 0x5620a6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005620a9: { // 0x5620a9: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L005620ac: { // 0x5620ac: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005620b0: { // 0x5620b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005620b1: { // 0x5620b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005620b2: { // 0x5620b2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005620b3: { // 0x5620b3: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L005620b5: { // 0x5620b5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005620b6: { // 0x5620b6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005620b9: { // 0x5620b9: 668b3e MOV DI,word ptr [ESI]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.si))) & 0xffffu);
  }
  L005620bc: { // 0x5620bc: 662b7e04 SUB DI,word ptr [ESI + 0x4]
    s.di = (s.di & 0xffff0000u) | ((integer::sub((s.di & 0xffffu),m.r16((s.si+0x00000004u)),16,flags)) & 0xffffu);
  }
  L005620c0: { // 0x5620c0: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L005620c4: { // 0x5620c4: 0fbf4d00 MOVSX ECX,word ptr [EBP]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005620c8: { // 0x5620c8: 66f7df NEG DI
    s.di = (s.di & 0xffff0000u) | ((integer::sub(0u,(s.di & 0xffffu),16,flags)) & 0xffffu);
  }
  L005620cb: { // 0x5620cb: 1bff SBB EDI,EDI
    s.di = integer::sub(s.di,s.di,32,flags,flags&integer::CF);
  }
  L005620cd: { // 0x5620cd: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L005620d0: { // 0x5620d0: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005620d3: { // 0x5620d3: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L005620d6: { // 0x5620d6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005620d8: { // 0x5620d8: 7818 JS 0x005620f2
    if(integer::condition("JS",flags)) goto L005620f2;
  }
  L005620da: { // 0x5620da: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005620df: { // 0x5620df: 7d11 JGE 0x005620f2
    if(integer::condition("JGE",flags)) goto L005620f2;
  }
  L005620e1: { // 0x5620e1: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005620e7: { // 0x5620e7: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005620ea: { // 0x5620ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005620ec: { // 0x5620ec: 7404 JZ 0x005620f2
    if(integer::condition("JZ",flags)) goto L005620f2;
  }
  L005620ee: { // 0x5620ee: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005620f0: { // 0x5620f0: eb0d JMP 0x005620ff
    goto L005620ff;
  }
  L005620f2: { // 0x5620f2: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005620f5: { // 0x5620f5: bb1076a500 MOV EBX,0xa57610
    s.bx = 0x00a57610u;
  }
  L005620fa: { // 0x5620fa: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005620ff: { // 0x5620ff: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00562105: { // 0x562105: bd00010000 MOV EBP,0x100
    s.bp = 0x00000100u;
  }
  L0056210a: { // 0x56210a: 85c5 TEST EBP,EAX
    (void)integer::logical((s.bp)&(s.ax),32,flags);
  }
  L0056210c: { // 0x56210c: 7412 JZ 0x00562120
    if(integer::condition("JZ",flags)) goto L00562120;
  }
  L0056210e: { // 0x56210e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056210f: { // 0x56210f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00562111: { // 0x562111: e8aa45f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5644566u); flags=s.arithmetic_flags;
  }
  L00562116: { // 0x562116: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00562118: { // 0x562118: 85ab40010000 TEST dword ptr [EBX + 0x140],EBP
    (void)integer::logical((m.r32((s.bx+0x00000140u)))&(s.bp),32,flags);
  }
  L0056211e: { // 0x56211e: 75ee JNZ 0x0056210e
    if(integer::condition("JNZ",flags)) goto L0056210e;
  }
  L00562120: { // 0x562120: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00562122: { // 0x562122: e83994f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5644583u); flags=s.arithmetic_flags;
  }
  L00562127: { // 0x562127: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00562129: { // 0x562129: 750b JNZ 0x00562136
    if(integer::condition("JNZ",flags)) goto L00562136;
  }
  L0056212b: { // 0x56212b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0056212d: { // 0x56212d: e84e94f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5644594u); flags=s.arithmetic_flags;
  }
  L00562132: { // 0x562132: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00562134: { // 0x562134: 7419 JZ 0x0056214f
    if(integer::condition("JZ",flags)) goto L0056214f;
  }
  L00562136: { // 0x562136: 83bbec00000003 CMP dword ptr [EBX + 0xec],0x3
    (void)integer::sub(m.r32((s.bx+0x000000ecu)),0x00000003u,32,flags);
  }
  L0056213d: { // 0x56213d: 7410 JZ 0x0056214f
    if(integer::condition("JZ",flags)) goto L0056214f;
  }
  L0056213f: { // 0x56213f: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00562142: { // 0x562142: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00562146: { // 0x562146: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00562147: { // 0x562147: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00562148: { // 0x562148: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00562149: { // 0x562149: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0056214b: { // 0x56214b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056214c: { // 0x56214c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056214f: { // 0x56214f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00562151: { // 0x562151: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00562155: { // 0x562155: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00562156: { // 0x562156: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00562157: { // 0x562157: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00562158: { // 0x562158: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0056215a: { // 0x56215a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056215b: { // 0x56215b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056215e: { // 0x56215e: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00562162: { // 0x562162: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00562166: { // 0x562166: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00562167: { // 0x562167: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00562168: { // 0x562168: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00562169: { // 0x562169: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056216b: { // 0x56216b: e840000000 CALL 0x005621b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005621b0u,5644656u); flags=s.arithmetic_flags;
  }
  L00562170: { // 0x562170: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00562172: { // 0x562172: 663b055c6ea500 CMP AX,word ptr [0x00a56e5c]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a56e5cu)),16,flags);
  }
  L00562179: { // 0x562179: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0056217d: { // 0x56217d: 750e JNZ 0x0056218d
    if(integer::condition("JNZ",flags)) goto L0056218d;
  }
  L0056217f: { // 0x56217f: 668b54241e MOV DX,word ptr [ESP + 0x1e]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000001eu)));
  }
  L00562184: { // 0x562184: 663b155e6ea500 CMP DX,word ptr [0x00a56e5e]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a56e5eu)),16,flags);
  }
  L0056218b: { // 0x56218b: 740f JZ 0x0056219c
    if(integer::condition("JZ",flags)) goto L0056219c;
  }
  L0056218d: { // 0x56218d: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00562191: { // 0x562191: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00562192: { // 0x562192: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00562193: { // 0x562193: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00562194: { // 0x562194: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00562196: { // 0x562196: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00562198: { // 0x562198: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00562199: { // 0x562199: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056219c: { // 0x56219c: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005621a0: { // 0x5621a0: 8b4d00 MOV ECX,dword ptr [EBP]
    s.cx = m.r32((s.bp));
  }
  L005621a3: { // 0x5621a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005621a4: { // 0x5621a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005621a5: { // 0x5621a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005621a6: { // 0x5621a6: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005621a8: { // 0x5621a8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005621a9: { // 0x5621a9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
