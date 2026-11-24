#include "recovered/recovery_b1523_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1523 {
namespace {
void f_000f42b0(Memory&,State&,Frame&,const Operations&);
void f_00052470(Memory&,State&,Frame&,const Operations&);
void f_00292390(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_000f42b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f42b0: { // 0x4f42b0: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004f42b3: { // 0x4f42b3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f42b4: { // 0x4f42b4: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L004f42b6: { // 0x4f42b6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f42b7: { // 0x4f42b7: 8a853d010000 MOV AL, byte ptr [EBP + 0x13d]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000013du)));
  }
  L004f42bd: { // 0x4f42bd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f42bf: { // 0x4f42bf: 0f855b010000 JNZ 0x4f4420
    if(integer::condition("JNZ",flags)) goto L004f4420;
  }
  L004f42c5: { // 0x4f42c5: 8b85ac010000 MOV EAX, dword ptr [EBP + 0x1ac]
    s.ax = m.r32((s.bp+0x000001acu));
  }
  L004f42cb: { // 0x4f42cb: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f42cd: { // 0x4f42cd: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f42cf: { // 0x4f42cf: 0f8e4b010000 JLE 0x4f4420
    if(integer::condition("JLE",flags)) goto L004f4420;
  }
  L004f42d5: { // 0x4f42d5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f42d6: { // 0x4f42d6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f42d7: { // 0x4f42d7: 8b85a0010000 MOV EAX, dword ptr [EBP + 0x1a0]
    s.ax = m.r32((s.bp+0x000001a0u));
  }
  L004f42dd: { // 0x4f42dd: 8b04b0 MOV EAX, dword ptr [EAX + ESI*4]
    s.ax = m.r32((s.ax+(s.si * 4u)));
  }
  L004f42e0: { // 0x4f42e0: 8a4855 MOV CL, byte ptr [EAX + 0x55]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000055u)));
  }
  L004f42e3: { // 0x4f42e3: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f42e5: { // 0x4f42e5: 7416 JZ 0x4f42fd
    if(integer::condition("JZ",flags)) goto L004f42fd;
  }
  L004f42e7: { // 0x4f42e7: 8a4856 MOV CL, byte ptr [EAX + 0x56]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000056u)));
  }
  L004f42ea: { // 0x4f42ea: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f42ec: { // 0x4f42ec: 0f841d010000 JZ 0x4f440f
    if(integer::condition("JZ",flags)) goto L004f440f;
  }
  L004f42f2: { // 0x4f42f2: 8a4855 MOV CL, byte ptr [EAX + 0x55]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000055u)));
  }
  L004f42f5: { // 0x4f42f5: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f42f7: { // 0x4f42f7: 0f8412010000 JZ 0x4f440f
    if(integer::condition("JZ",flags)) goto L004f440f;
  }
  L004f42fd: { // 0x4f42fd: 8b5d78 MOV EBX, dword ptr [EBP + 0x78]
    s.bx = m.r32((s.bp+0x00000078u));
  }
  L004f4300: { // 0x4f4300: c644241300 MOV byte ptr [ESP + 0x13], 0
    m.w8((f.sp+0x00000013u), 0u);
  }
  L004f4305: { // 0x4f4305: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L004f4306: { // 0x4f4306: 0f8803010000 JS 0x4f440f
    if(integer::condition("JS",flags)) goto L004f440f;
  }
  L004f430c: { // 0x4f430c: 8b4d6c MOV ECX, dword ptr [EBP + 0x6c]
    s.cx = m.r32((s.bp+0x0000006cu));
  }
  L004f430f: { // 0x4f430f: 8b3c99 MOV EDI, dword ptr [ECX + EBX*4]
    s.di = m.r32((s.cx+(s.bx * 4u)));
  }
  L004f4312: { // 0x4f4312: 8a477d MOV AL, byte ptr [EDI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000007du)));
  }
  L004f4315: { // 0x4f4315: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f4317: { // 0x4f4317: 7453 JZ 0x4f436c
    if(integer::condition("JZ",flags)) goto L004f436c;
  }
  L004f4319: { // 0x4f4319: 8a4776 MOV AL, byte ptr [EDI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000076u)));
  }
  L004f431c: { // 0x4f431c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f431e: { // 0x4f431e: 754c JNZ 0x4f436c
    if(integer::condition("JNZ",flags)) goto L004f436c;
  }
  L004f4320: { // 0x4f4320: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004f4322: { // 0x4f4322: 8d8fc0040000 LEA ECX, [EDI + 0x4c0]
    s.cx = (s.di+0x000004c0u);
  }
  L004f4328: { // 0x4f4328: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004f432a: { // 0x4f432a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f432c: { // 0x4f432c: 7410 JZ 0x4f433e
    if(integer::condition("JZ",flags)) goto L004f433e;
  }
  L004f432e: { // 0x4f432e: 39b074130000 CMP dword ptr [EAX + 0x1374], ESI
    (void)integer::sub(m.r32((s.ax+0x00001374u)),s.si,32,flags);
  }
  L004f4334: { // 0x4f4334: 7413 JZ 0x4f4349
    if(integer::condition("JZ",flags)) goto L004f4349;
  }
  L004f4336: { // 0x4f4336: 39b078130000 CMP dword ptr [EAX + 0x1378], ESI
    (void)integer::sub(m.r32((s.ax+0x00001378u)),s.si,32,flags);
  }
  L004f433c: { // 0x4f433c: 740b JZ 0x4f4349
    if(integer::condition("JZ",flags)) goto L004f4349;
  }
  L004f433e: { // 0x4f433e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004f433f: { // 0x4f433f: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L004f4342: { // 0x4f4342: 83fa03 CMP EDX, 3
    (void)integer::sub(s.dx,3u,32,flags);
  }
  L004f4345: { // 0x4f4345: 7ce1 JL 0x4f4328
    if(integer::condition("JL",flags)) goto L004f4328;
  }
  L004f4347: { // 0x4f4347: eb05 JMP 0x4f434e
    goto L004f434e;
  }
  L004f4349: { // 0x4f4349: c644241301 MOV byte ptr [ESP + 0x13], 1
    m.w8((f.sp+0x00000013u), 1u);
  }
  L004f434e: { // 0x4f434e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f4350: { // 0x4f4350: e81be1f5ff CALL 0x452470
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452470u,5194581u); flags=s.arithmetic_flags;
  }
  L004f4355: { // 0x4f4355: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004f4357: { // 0x4f4357: 741c JZ 0x4f4375
    if(integer::condition("JZ",flags)) goto L004f4375;
  }
  L004f4359: { // 0x4f4359: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f435b: { // 0x4f435b: e870e1f5ff CALL 0x4524d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004524d0u,5194592u); flags=s.arithmetic_flags;
  }
  L004f4360: { // 0x4f4360: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004f4362: { // 0x4f4362: 7411 JZ 0x4f4375
    if(integer::condition("JZ",flags)) goto L004f4375;
  }
  L004f4364: { // 0x4f4364: 8a442413 MOV AL, byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L004f4368: { // 0x4f4368: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f436a: { // 0x4f436a: 7509 JNZ 0x4f4375
    if(integer::condition("JNZ",flags)) goto L004f4375;
  }
  L004f436c: { // 0x4f436c: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L004f436d: { // 0x4f436d: 0f889c000000 JS 0x4f440f
    if(integer::condition("JS",flags)) goto L004f440f;
  }
  L004f4373: { // 0x4f4373: eb97 JMP 0x4f430c
    goto L004f430c;
  }
  L004f4375: { // 0x4f4375: 8b8dd0520000 MOV ECX, dword ptr [EBP + 0x52d0]
    s.cx = m.r32((s.bp+0x000052d0u));
  }
  L004f437b: { // 0x4f437b: 8b85d4520000 MOV EAX, dword ptr [EBP + 0x52d4]
    s.ax = m.r32((s.bp+0x000052d4u));
  }
  L004f4381: { // 0x4f4381: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f4383: { // 0x4f4383: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004f4387: { // 0x4f4387: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004f438b: { // 0x4f438b: 7d24 JGE 0x4f43b1
    if(integer::condition("JGE",flags)) goto L004f43b1;
  }
  L004f438d: { // 0x4f438d: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f438f: { // 0x4f438f: 7420 JZ 0x4f43b1
    if(integer::condition("JZ",flags)) goto L004f43b1;
  }
  L004f4391: { // 0x4f4391: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004f4393: { // 0x4f4393: 7415 JZ 0x4f43aa
    if(integer::condition("JZ",flags)) goto L004f43aa;
  }
  L004f4395: { // 0x4f4395: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L004f4399: { // 0x4f4399: da742418 FIDIV dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.divide_integer32(m.r32(address));
  }
  L004f439d: { // 0x4f439d: dc1d08577800 FCOMP qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004f43a3: { // 0x4f43a3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004f43a5: { // 0x4f43a5: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L004f43a8: { // 0x4f43a8: 7407 JZ 0x4f43b1
    if(integer::condition("JZ",flags)) goto L004f43b1;
  }
  L004f43aa: { // 0x4f43aa: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004f43af: { // 0x4f43af: eb02 JMP 0x4f43b3
    goto L004f43b3;
  }
  L004f43b1: { // 0x4f43b1: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f43b3: { // 0x4f43b3: 8b1de4e0a100 MOV EBX, dword ptr [0xa1e0e4]
    s.bx = m.r32((0x00a1e0e4u));
  }
  L004f43b9: { // 0x4f43b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f43ba: { // 0x4f43ba: 8b85a0010000 MOV EAX, dword ptr [EBP + 0x1a0]
    s.ax = m.r32((s.bp+0x000001a0u));
  }
  L004f43c0: { // 0x4f43c0: 3beb CMP EBP, EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L004f43c2: { // 0x4f43c2: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f43c5: { // 0x4f43c5: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L004f43c8: { // 0x4f43c8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004f43c9: { // 0x4f43c9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004f43cb: { // 0x4f43cb: e8c0df1900 CALL 0x692390
    s.arithmetic_flags=flags; invoke(m,s,f,0x00692390u,5194704u); flags=s.arithmetic_flags;
  }
  L004f43d0: { // 0x4f43d0: 3b2de4e0a100 CMP EBP, dword ptr [0xa1e0e4]
    (void)integer::sub(s.bp,m.r32((0x00a1e0e4u)),32,flags);
  }
  L004f43d6: { // 0x4f43d6: 7537 JNZ 0x4f440f
    if(integer::condition("JNZ",flags)) goto L004f440f;
  }
  L004f43d8: { // 0x4f43d8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f43d9: { // 0x4f43d9: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L004f43db: { // 0x4f43db: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004f43e0: { // 0x4f43e0: e8bbd91700 CALL 0x671da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00671da0u,5194725u); flags=s.arithmetic_flags;
  }
  L004f43e5: { // 0x4f43e5: 8b8da0010000 MOV ECX, dword ptr [EBP + 0x1a0]
    s.cx = m.r32((s.bp+0x000001a0u));
  }
  L004f43eb: { // 0x4f43eb: 8b14b1 MOV EDX, dword ptr [ECX + ESI*4]
    s.dx = m.r32((s.cx+(s.si * 4u)));
  }
  L004f43ee: { // 0x4f43ee: 8b4a24 MOV ECX, dword ptr [EDX + 0x24]
    s.cx = m.r32((s.dx+0x00000024u));
  }
  L004f43f1: { // 0x4f43f1: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004f43f3: { // 0x4f43f3: ff5040 CALL dword ptr [EAX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000040u)),5194742u); flags=s.arithmetic_flags;
  }
  L004f43f6: { // 0x4f43f6: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004f43f8: { // 0x4f43f8: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004f43fa: { // 0x4f43fa: b939000000 MOV ECX, 0x39
    s.cx = 0x00000039u;
  }
  L004f43ff: { // 0x4f43ff: e8fc2b1800 CALL 0x677000
    s.arithmetic_flags=flags; invoke(m,s,f,0x00677000u,5194756u); flags=s.arithmetic_flags;
  }
  L004f4404: { // 0x4f4404: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4405: { // 0x4f4405: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004f440a: { // 0x4f440a: e891d71700 CALL 0x671ba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00671ba0u,5194767u); flags=s.arithmetic_flags;
  }
  L004f440f: { // 0x4f440f: 8b85ac010000 MOV EAX, dword ptr [EBP + 0x1ac]
    s.ax = m.r32((s.bp+0x000001acu));
  }
  L004f4415: { // 0x4f4415: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004f4416: { // 0x4f4416: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004f4418: { // 0x4f4418: 0f8cb9feffff JL 0x4f42d7
    if(integer::condition("JL",flags)) goto L004f42d7;
  }
  L004f441e: { // 0x4f441e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f441f: { // 0x4f441f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f4420: { // 0x4f4420: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4421: { // 0x4f4421: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f4422: { // 0x4f4422: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004f4425: { // 0x4f4425: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00052470(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00452470: { // 0x452470: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00452471: { // 0x452471: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00452473: { // 0x452473: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00452479: { // 0x452479: 8b8074130000 MOV EAX, dword ptr [EAX + 0x1374]
    s.ax = m.r32((s.ax+0x00001374u));
  }
  L0045247f: { // 0x45247f: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00452482: { // 0x452482: 7437 JZ 0x4524bb
    if(integer::condition("JZ",flags)) goto L004524bb;
  }
  L00452484: { // 0x452484: 8b0d5ce0a100 MOV ECX, dword ptr [0xa1e05c]
    s.cx = m.r32((0x00a1e05cu));
  }
  L0045248a: { // 0x45248a: 8b1481 MOV EDX, dword ptr [ECX + EAX*4]
    s.dx = m.r32((s.cx+(s.ax * 4u)));
  }
  L0045248d: { // 0x45248d: 8b4224 MOV EAX, dword ptr [EDX + 0x24]
    s.ax = m.r32((s.dx+0x00000024u));
  }
  L00452490: { // 0x452490: 8b80c0000000 MOV EAX, dword ptr [EAX + 0xc0]
    s.ax = m.r32((s.ax+0x000000c0u));
  }
  L00452496: { // 0x452496: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00452498: { // 0x452498: 7421 JZ 0x4524bb
    if(integer::condition("JZ",flags)) goto L004524bb;
  }
  L0045249a: { // 0x45249a: 8b88900b0000 MOV ECX, dword ptr [EAX + 0xb90]
    s.cx = m.r32((s.ax+0x00000b90u));
  }
  L004524a0: { // 0x4524a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004524a1: { // 0x4524a1: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004524a7: { // 0x4524a7: 81c160540000 ADD ECX, 0x5460
    s.cx = integer::add(s.cx,0x00005460u,32,flags);
  }
  L004524ad: { // 0x4524ad: e83ef60300 CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,4531378u); flags=s.arithmetic_flags;
  }
  L004524b2: { // 0x4524b2: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004524b4: { // 0x4524b4: 7505 JNZ 0x4524bb
    if(integer::condition("JNZ",flags)) goto L004524bb;
  }
  L004524b6: { // 0x4524b6: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004524b9: { // 0x4524b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004524ba: { // 0x4524ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004524bb: { // 0x4524bb: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L004524c1: { // 0x4524c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004524c2: { // 0x4524c2: 8b8274130000 MOV EAX, dword ptr [EDX + 0x1374]
    s.ax = m.r32((s.dx+0x00001374u));
  }
  L004524c8: { // 0x4524c8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00292390(Memory& m,State& s,Frame& f,const Operations& op) { const auto item=s.cx,type=m.r32(item+0x24u);if(m.r32(item)!=0x7970b8u||m.r32(type)!=0x797160u||m.r8(item+0x55u)!=0u||m.r8(item+0x57u)!=1u||m.r8(item+0x58u)!=0u||m.r32(item+0x50u)!=0u||m.r8(item+0x54u)!=0u||m.r8(type+0xe8u)!=0u||m.r8(type+0xe9u)!=0u||m.r32(type+0x60u)!=0x82208cu||m.r32(f.sp+4u)!=0u||(m.r32(f.sp+8u)&0xffu)!=0u||m.r32(f.sp+12u)!=0u)throw std::domain_error("B1523 freshGrant exactcarrierdomain");
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00692390: { // 0x692390: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00692393: { // 0x692393: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00692394: { // 0x692394: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00692395: { // 0x692395: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00692397: { // 0x692397: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00692399: { // 0x692399: 385e55 CMP byte ptr [ESI + 0x55], BL
    (void)integer::sub(m.r8((s.si+0x00000055u)),(s.bx & 0xffu),8,flags);
  }
  L0069239c: { // 0x69239c: 0f8532020000 JNZ 0x6925d4
    if(integer::condition("JNZ",flags)) goto L006925d4;
  }
  L006923a2: { // 0x6923a2: 8a442418 MOV AL, byte ptr [ESP + 0x18]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000018u)));
  }
  L006923a6: { // 0x6923a6: 8b4e24 MOV ECX, dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L006923a9: { // 0x6923a9: c6465501 MOV byte ptr [ESI + 0x55], 1
    m.w8((s.si+0x00000055u), 1u);
  }
  L006923ad: { // 0x6923ad: 884656 MOV byte ptr [ESI + 0x56], AL
    m.w8((s.si+0x00000056u), (s.ax & 0xffu));
  }
  L006923b0: { // 0x6923b0: 885e3c MOV byte ptr [ESI + 0x3c], BL
    m.w8((s.si+0x0000003cu), (s.bx & 0xffu));
  }
  L006923b3: { // 0x6923b3: 8b5160 MOV EDX, dword ptr [ECX + 0x60]
    s.dx = m.r32((s.cx+0x00000060u));
  }
  L006923b6: { // 0x6923b6: 3ac3 CMP AL, BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L006923b8: { // 0x6923b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006923b9: { // 0x6923b9: 885c241c MOV byte ptr [ESP + 0x1c], BL
    m.w8((f.sp+0x0000001cu), (s.bx & 0xffu));
  }
  L006923bd: { // 0x6923bd: 895638 MOV dword ptr [ESI + 0x38], EDX
    m.w32((s.si+0x00000038u), s.dx);
  }
  L006923c0: { // 0x6923c0: 7540 JNZ 0x692402
    if(integer::condition("JNZ",flags)) goto L00692402;
  }
  L006923c2: { // 0x6923c2: 385e58 CMP byte ptr [ESI + 0x58], BL
    (void)integer::sub(m.r8((s.si+0x00000058u)),(s.bx & 0xffu),8,flags);
  }
  L006923c5: { // 0x6923c5: 743b JZ 0x692402
    if(integer::condition("JZ",flags)) goto L00692402;
  }
  L006923c7: { // 0x6923c7: 385e48 CMP byte ptr [ESI + 0x48], BL
    (void)integer::sub(m.r8((s.si+0x00000048u)),(s.bx & 0xffu),8,flags);
  }
  L006923ca: { // 0x6923ca: 7436 JZ 0x692402
    if(integer::condition("JZ",flags)) goto L00692402;
  }
  L006923cc: { // 0x6923cc: 3899e9000000 CMP byte ptr [ECX + 0xe9], BL
    (void)integer::sub(m.r8((s.cx+0x000000e9u)),(s.bx & 0xffu),8,flags);
  }
  L006923d2: { // 0x6923d2: 7510 JNZ 0x6923e4
    if(integer::condition("JNZ",flags)) goto L006923e4;
  }
  L006923d4: { // 0x6923d4: 837e2cff CMP dword ptr [ESI + 0x2c], -1
    (void)integer::sub(m.r32((s.si+0x0000002cu)),4294967295u,32,flags);
  }
  L006923d8: { // 0x6923d8: 7525 JNZ 0x6923ff
    if(integer::condition("JNZ",flags)) goto L006923ff;
  }
  L006923da: { // 0x6923da: a16c89a200 MOV EAX, dword ptr [0xa2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006923df: { // 0x6923df: 89462c MOV dword ptr [ESI + 0x2c], EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  L006923e2: { // 0x6923e2: eb1b JMP 0x6923ff
    goto L006923ff;
  }
  L006923e4: { // 0x6923e4: 8b462c MOV EAX, dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L006923e7: { // 0x6923e7: 8d7e2c LEA EDI, [ESI + 0x2c]
    s.di = (s.si+0x0000002cu);
  }
  L006923ea: { // 0x6923ea: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L006923ed: { // 0x6923ed: 7410 JZ 0x6923ff
    if(integer::condition("JZ",flags)) goto L006923ff;
  }
  L006923ef: { // 0x6923ef: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006923f1: { // 0x6923f1: e83a17dcff CALL 0x453b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453b30u,6890486u); flags=s.arithmetic_flags;
  }
  L006923f6: { // 0x6923f6: 894708 MOV dword ptr [EDI + 8], EAX
    m.w32((s.di+8u), s.ax);
  }
  L006923f9: { // 0x6923f9: c707ffffffff MOV dword ptr [EDI], 0xffffffff
    m.w32((s.di), 0xffffffffu);
  }
  L006923ff: { // 0x6923ff: 885e58 MOV byte ptr [ESI + 0x58], BL
    m.w8((s.si+0x00000058u), (s.bx & 0xffu));
  }
  L00692402: { // 0x692402: 8b4e24 MOV ECX, dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L00692405: { // 0x692405: 3899e8000000 CMP byte ptr [ECX + 0xe8], BL
    (void)integer::sub(m.r8((s.cx+0x000000e8u)),(s.bx & 0xffu),8,flags);
  }
  L0069240b: { // 0x69240b: 7461 JZ 0x69246e
    if(integer::condition("JZ",flags)) goto L0069246e;
  }
  L0069240d: { // 0x69240d: 8b5628 MOV EDX, dword ptr [ESI + 0x28]
    s.dx = m.r32((s.si+0x00000028u));
  }
  L00692410: { // 0x692410: 8b4234 MOV EAX, dword ptr [EDX + 0x34]
    s.ax = m.r32((s.dx+0x00000034u));
  }
  L00692413: { // 0x692413: 3898a6010000 CMP byte ptr [EAX + 0x1a6], BL
    (void)integer::sub(m.r8((s.ax+0x000001a6u)),(s.bx & 0xffu),8,flags);
  }
  L00692419: { // 0x692419: 7553 JNZ 0x69246e
    if(integer::condition("JNZ",flags)) goto L0069246e;
  }
  L0069241b: { // 0x69241b: a1f0e0a100 MOV EAX, dword ptr [0xa1e0f0]
    s.ax = m.r32((0x00a1e0f0u));
  }
  L00692420: { // 0x692420: 8b0df8e0a100 MOV ECX, dword ptr [0xa1e0f8]
    s.cx = m.r32((0x00a1e0f8u));
  }
  L00692426: { // 0x692426: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00692428: { // 0x692428: 7c2c JL 0x692456
    if(integer::condition("JL",flags)) goto L00692456;
  }
  L0069242a: { // 0x69242a: 381df5e0a100 CMP byte ptr [0xa1e0f5], BL
    (void)integer::sub(m.r8((0x00a1e0f5u)),(s.bx & 0xffu),8,flags);
  }
  L00692430: { // 0x692430: 7504 JNZ 0x692436
    if(integer::condition("JNZ",flags)) goto L00692436;
  }
  L00692432: { // 0x692432: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00692434: { // 0x692434: 7538 JNZ 0x69246e
    if(integer::condition("JNZ",flags)) goto L0069246e;
  }
  L00692436: { // 0x692436: 8b0dfce0a100 MOV ECX, dword ptr [0xa1e0fc]
    s.cx = m.r32((0x00a1e0fcu));
  }
  L0069243c: { // 0x69243c: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069243e: { // 0x69243e: 7e2e JLE 0x69246e
    if(integer::condition("JLE",flags)) goto L0069246e;
  }
  L00692440: { // 0x692440: 8b15e8e0a100 MOV EDX, dword ptr [0xa1e0e8]
    s.dx = m.r32((0x00a1e0e8u));
  }
  L00692446: { // 0x692446: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00692448: { // 0x692448: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00692449: { // 0x692449: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069244a: { // 0x69244a: b9e8e0a100 MOV ECX, 0xa1e0e8
    s.cx = 0x00a1e0e8u;
  }
  L0069244f: { // 0x69244f: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),6890578u); flags=s.arithmetic_flags;
  }
  L00692452: { // 0x692452: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00692454: { // 0x692454: 7418 JZ 0x69246e
    if(integer::condition("JZ",flags)) goto L0069246e;
  }
  L00692456: { // 0x692456: 8b0df8e0a100 MOV ECX, dword ptr [0xa1e0f8]
    s.cx = m.r32((0x00a1e0f8u));
  }
  L0069245c: { // 0x69245c: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0069245e: { // 0x69245e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0069245f: { // 0x69245f: 890df8e0a100 MOV dword ptr [0xa1e0f8], ECX
    m.w32((0x00a1e0f8u), s.cx);
  }
  L00692465: { // 0x692465: 8b0dece0a100 MOV ECX, dword ptr [0xa1e0ec]
    s.cx = m.r32((0x00a1e0ecu));
  }
  L0069246b: { // 0x69246b: 893481 MOV dword ptr [ECX + EAX*4], ESI
    m.w32((s.cx+(s.ax * 4u)), s.si);
  }
  L0069246e: { // 0x69246e: 8b4624 MOV EAX, dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  L00692471: { // 0x692471: 3898e9000000 CMP byte ptr [EAX + 0xe9], BL
    (void)integer::sub(m.r8((s.ax+0x000000e9u)),(s.bx & 0xffu),8,flags);
  }
  L00692477: { // 0x692477: 7463 JZ 0x6924dc
    if(integer::condition("JZ",flags)) goto L006924dc;
  }
  L00692479: { // 0x692479: c7465cffffffff MOV dword ptr [ESI + 0x5c], 0xffffffff
    m.w32((s.si+0x0000005cu), 0xffffffffu);
  }
  L00692480: { // 0x692480: 8b90b0000000 MOV EDX, dword ptr [EAX + 0xb0]
    s.dx = m.r32((s.ax+0x000000b0u));
  }
  L00692486: { // 0x692486: 8b0d6c89a200 MOV ECX, dword ptr [0xa2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L0069248c: { // 0x69248c: 8d462c LEA EAX, [ESI + 0x2c]
    s.ax = (s.si+0x0000002cu);
  }
  L0069248f: { // 0x69248f: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00692491: { // 0x692491: 890f MOV dword ptr [EDI], ECX
    m.w32((s.di), s.cx);
  }
  L00692493: { // 0x692493: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00692497: { // 0x692497: 894f04 MOV dword ptr [EDI + 4], ECX
    m.w32((s.di+4u), s.cx);
  }
  L0069249a: { // 0x69249a: 895708 MOV dword ptr [EDI + 8], EDX
    m.w32((s.di+8u), s.dx);
  }
  L0069249d: { // 0x69249d: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069249f: { // 0x69249f: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L006924a2: { // 0x6924a2: 0f84d2000000 JZ 0x69257a
    if(integer::condition("JZ",flags)) goto L0069257a;
  }
  L006924a8: { // 0x6924a8: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L006924ab: { // 0x6924ab: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L006924ae: { // 0x6924ae: 741e JZ 0x6924ce
    if(integer::condition("JZ",flags)) goto L006924ce;
  }
  L006924b0: { // 0x6924b0: 8b3d6c89a200 MOV EDI, dword ptr [0xa2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L006924b6: { // 0x6924b6: 2bf9 SUB EDI, ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006924b8: { // 0x6924b8: 3bfa CMP EDI, EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L006924ba: { // 0x6924ba: 7d10 JGE 0x6924cc
    if(integer::condition("JGE",flags)) goto L006924cc;
  }
  L006924bc: { // 0x6924bc: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L006924be: { // 0x6924be: c700ffffffff MOV dword ptr [EAX], 0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  L006924c4: { // 0x6924c4: 895008 MOV dword ptr [EAX + 8], EDX
    m.w32((s.ax+8u), s.dx);
  }
  L006924c7: { // 0x6924c7: e9ae000000 JMP 0x69257a
    goto L0069257a;
  }
  L006924cc: { // 0x6924cc: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006924ce: { // 0x6924ce: 895008 MOV dword ptr [EAX + 8], EDX
    m.w32((s.ax+8u), s.dx);
  }
  L006924d1: { // 0x6924d1: c700ffffffff MOV dword ptr [EAX], 0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  L006924d7: { // 0x6924d7: e99e000000 JMP 0x69257a
    goto L0069257a;
  }
  L006924dc: { // 0x6924dc: 8b4650 MOV EAX, dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  L006924df: { // 0x6924df: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006924e1: { // 0x6924e1: 741c JZ 0x6924ff
    if(integer::condition("JZ",flags)) goto L006924ff;
  }
  L006924e3: { // 0x6924e3: 8d54241c LEA EDX, [ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L006924e7: { // 0x6924e7: 889875010000 MOV byte ptr [EAX + 0x175], BL
    m.w8((s.ax+0x00000175u), (s.bx & 0xffu));
  }
  L006924ed: { // 0x6924ed: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006924ee: { // 0x6924ee: b90087aa00 MOV ECX, 0xaa8700
    s.cx = 0x00aa8700u;
  }
  L006924f3: { // 0x6924f3: 895e50 MOV dword ptr [ESI + 0x50], EBX
    m.w32((s.si+0x00000050u), s.bx);
  }
  L006924f6: { // 0x6924f6: 89742420 MOV dword ptr [ESP + 0x20], ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L006924fa: { // 0x6924fa: e8911e0000 CALL 0x694390
    s.arithmetic_flags=flags; invoke(m,s,f,0x00694390u,6890751u); flags=s.arithmetic_flags;
  }
  L006924ff: { // 0x6924ff: 385e54 CMP byte ptr [ESI + 0x54], BL
    (void)integer::sub(m.r8((s.si+0x00000054u)),(s.bx & 0xffu),8,flags);
  }
  L00692502: { // 0x692502: 7416 JZ 0x69251a
    if(integer::condition("JZ",flags)) goto L0069251a;
  }
  L00692504: { // 0x692504: 8d44241c LEA EAX, [ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00692508: { // 0x692508: b90087aa00 MOV ECX, 0xaa8700
    s.cx = 0x00aa8700u;
  }
  L0069250d: { // 0x69250d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069250e: { // 0x69250e: 89742420 MOV dword ptr [ESP + 0x20], ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L00692512: { // 0x692512: e8791e0000 CALL 0x694390
    s.arithmetic_flags=flags; invoke(m,s,f,0x00694390u,6890775u); flags=s.arithmetic_flags;
  }
  L00692517: { // 0x692517: 885e54 MOV byte ptr [ESI + 0x54], BL
    m.w8((s.si+0x00000054u), (s.bx & 0xffu));
  }
  L0069251a: { // 0x69251a: 385e55 CMP byte ptr [ESI + 0x55], BL
    (void)integer::sub(m.r8((s.si+0x00000055u)),(s.bx & 0xffu),8,flags);
  }
  L0069251d: { // 0x69251d: 7457 JZ 0x692576
    if(integer::condition("JZ",flags)) goto L00692576;
  }
  L0069251f: { // 0x69251f: 385e57 CMP byte ptr [ESI + 0x57], BL
    (void)integer::sub(m.r8((s.si+0x00000057u)),(s.bx & 0xffu),8,flags);
  }
  L00692522: { // 0x692522: 7552 JNZ 0x692576
    if(integer::condition("JNZ",flags)) goto L00692576;
  }
  L00692524: { // 0x692524: 385e58 CMP byte ptr [ESI + 0x58], BL
    (void)integer::sub(m.r8((s.si+0x00000058u)),(s.bx & 0xffu),8,flags);
  }
  L00692527: { // 0x692527: 754d JNZ 0x692576
    if(integer::condition("JNZ",flags)) goto L00692576;
  }
  L00692529: { // 0x692529: 8d7e2c LEA EDI, [ESI + 0x2c]
    s.di = (s.si+0x0000002cu);
  }
  L0069252c: { // 0x69252c: c7465cffffffff MOV dword ptr [ESI + 0x5c], 0xffffffff
    m.w32((s.si+0x0000005cu), 0xffffffffu);
  }
  L00692533: { // 0x692533: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00692535: { // 0x692535: e8461e0000 CALL 0x694380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00694380u,6890810u); flags=s.arithmetic_flags;
  }
  L0069253a: { // 0x69253a: 8b4e24 MOV ECX, dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L0069253d: { // 0x69253d: 8b91b0000000 MOV EDX, dword ptr [ECX + 0xb0]
    s.dx = m.r32((s.cx+0x000000b0u));
  }
  L00692543: { // 0x692543: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00692547: { // 0x692547: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00692548: { // 0x692548: e86316ddff CALL 0x463bb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00463bb0u,6890829u); flags=s.arithmetic_flags;
  }
  L0069254d: { // 0x69254d: 8b44240c MOV EAX, dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00692551: { // 0x692551: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00692555: { // 0x692555: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00692559: { // 0x692559: 8907 MOV dword ptr [EDI], EAX
    m.w32((s.di), s.ax);
  }
  L0069255b: { // 0x69255b: 8b4624 MOV EAX, dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  L0069255e: { // 0x69255e: 894f04 MOV dword ptr [EDI + 4], ECX
    m.w32((s.di+4u), s.cx);
  }
  L00692561: { // 0x692561: 895708 MOV dword ptr [EDI + 8], EDX
    m.w32((s.di+8u), s.dx);
  }
  L00692564: { // 0x692564: 3898dd000000 CMP byte ptr [EAX + 0xdd], BL
    (void)integer::sub(m.r8((s.ax+0x000000ddu)),(s.bx & 0xffu),8,flags);
  }
  L0069256a: { // 0x69256a: 7403 JZ 0x69256f
    if(integer::condition("JZ",flags)) goto L0069256f;
  }
  L0069256c: { // 0x69256c: 895e60 MOV dword ptr [ESI + 0x60], EBX
    m.w32((s.si+0x00000060u), s.bx);
  }
  L0069256f: { // 0x69256f: c644241c01 MOV byte ptr [ESP + 0x1c], 1
    m.w8((f.sp+0x0000001cu), 1u);
  }
  L00692574: { // 0x692574: eb04 JMP 0x69257a
    goto L0069257a;
  }
  L00692576: { // 0x692576: 885c241c MOV byte ptr [ESP + 0x1c], BL
    m.w8((f.sp+0x0000001cu), (s.bx & 0xffu));
  }
  L0069257a: { // 0x69257a: 385c2424 CMP byte ptr [ESP + 0x24], BL
    (void)integer::sub(m.r8((f.sp+0x00000024u)),(s.bx & 0xffu),8,flags);
  }
  L0069257e: { // 0x69257e: 7434 JZ 0x6925b4
    if(integer::condition("JZ",flags)) goto L006925b4;
  }
  L00692580: { // 0x692580: 385e55 CMP byte ptr [ESI + 0x55], BL
    (void)integer::sub(m.r8((s.si+0x00000055u)),(s.bx & 0xffu),8,flags);
  }
  L00692583: { // 0x692583: 742f JZ 0x6925b4
    if(integer::condition("JZ",flags)) goto L006925b4;
  }
  L00692585: { // 0x692585: 385e56 CMP byte ptr [ESI + 0x56], BL
    (void)integer::sub(m.r8((s.si+0x00000056u)),(s.bx & 0xffu),8,flags);
  }
  L00692588: { // 0x692588: 752a JNZ 0x6925b4
    if(integer::condition("JNZ",flags)) goto L006925b4;
  }
  L0069258a: { // 0x69258a: 807e5801 CMP byte ptr [ESI + 0x58], 1
    (void)integer::sub(m.r8((s.si+0x00000058u)),1u,8,flags);
  }
  L0069258e: { // 0x69258e: 7424 JZ 0x6925b4
    if(integer::condition("JZ",flags)) goto L006925b4;
  }
  L00692590: { // 0x692590: 385e48 CMP byte ptr [ESI + 0x48], BL
    (void)integer::sub(m.r8((s.si+0x00000048u)),(s.bx & 0xffu),8,flags);
  }
  L00692593: { // 0x692593: 741f JZ 0x6925b4
    if(integer::condition("JZ",flags)) goto L006925b4;
  }
  L00692595: { // 0x692595: 8b462c MOV EAX, dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L00692598: { // 0x692598: 8d7e2c LEA EDI, [ESI + 0x2c]
    s.di = (s.si+0x0000002cu);
  }
  L0069259b: { // 0x69259b: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L0069259e: { // 0x69259e: 7410 JZ 0x6925b0
    if(integer::condition("JZ",flags)) goto L006925b0;
  }
  L006925a0: { // 0x6925a0: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006925a2: { // 0x6925a2: e88915dcff CALL 0x453b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453b30u,6890919u); flags=s.arithmetic_flags;
  }
  L006925a7: { // 0x6925a7: 894708 MOV dword ptr [EDI + 8], EAX
    m.w32((s.di+8u), s.ax);
  }
  L006925aa: { // 0x6925aa: c707ffffffff MOV dword ptr [EDI], 0xffffffff
    m.w32((s.di), 0xffffffffu);
  }
  L006925b0: { // 0x6925b0: c6465801 MOV byte ptr [ESI + 0x58], 1
    m.w8((s.si+0x00000058u), 1u);
  }
  L006925b4: { // 0x6925b4: 8a4656 MOV AL, byte ptr [ESI + 0x56]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000056u)));
  }
  L006925b7: { // 0x6925b7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006925b8: { // 0x6925b8: 3ac3 CMP AL, BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L006925ba: { // 0x6925ba: 740c JZ 0x6925c8
    if(integer::condition("JZ",flags)) goto L006925c8;
  }
  L006925bc: { // 0x6925bc: 8b4c241c MOV ECX, dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006925c0: { // 0x6925c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006925c1: { // 0x6925c1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006925c3: { // 0x6925c3: e868070000 CALL 0x692d30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00692d30u,6890952u); flags=s.arithmetic_flags;
  }
  L006925c8: { // 0x6925c8: 8a442418 MOV AL, byte ptr [ESP + 0x18]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000018u)));
  }
  L006925cc: { // 0x6925cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006925cd: { // 0x6925cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006925ce: { // 0x6925ce: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006925d1: { // 0x6925d1: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006925d4: { // 0x6925d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006925d5: { // 0x6925d5: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006925d7: { // 0x6925d7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006925d8: { // 0x6925d8: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006925db: { // 0x6925db: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5194416u:f_000f42b0(m,s,child,{});break;
case 4531312u:f_00052470(m,s,child,{});break;
case 6890384u:f_00292390(m,s,child,{});break;
default:throw std::domain_error("recovery1523 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1523 no reviewed tail"); } }

std::uint32_t fun_004f42b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f42b0: { // 0x4f42b0: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004f42b3: { // 0x4f42b3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f42b4: { // 0x4f42b4: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L004f42b6: { // 0x4f42b6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f42b7: { // 0x4f42b7: 8a853d010000 MOV AL, byte ptr [EBP + 0x13d]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000013du)));
  }
  L004f42bd: { // 0x4f42bd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f42bf: { // 0x4f42bf: 0f855b010000 JNZ 0x4f4420
    if(integer::condition("JNZ",flags)) goto L004f4420;
  }
  L004f42c5: { // 0x4f42c5: 8b85ac010000 MOV EAX, dword ptr [EBP + 0x1ac]
    s.ax = m.r32((s.bp+0x000001acu));
  }
  L004f42cb: { // 0x4f42cb: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f42cd: { // 0x4f42cd: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f42cf: { // 0x4f42cf: 0f8e4b010000 JLE 0x4f4420
    if(integer::condition("JLE",flags)) goto L004f4420;
  }
  L004f42d5: { // 0x4f42d5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f42d6: { // 0x4f42d6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f42d7: { // 0x4f42d7: 8b85a0010000 MOV EAX, dword ptr [EBP + 0x1a0]
    s.ax = m.r32((s.bp+0x000001a0u));
  }
  L004f42dd: { // 0x4f42dd: 8b04b0 MOV EAX, dword ptr [EAX + ESI*4]
    s.ax = m.r32((s.ax+(s.si * 4u)));
  }
  L004f42e0: { // 0x4f42e0: 8a4855 MOV CL, byte ptr [EAX + 0x55]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000055u)));
  }
  L004f42e3: { // 0x4f42e3: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f42e5: { // 0x4f42e5: 7416 JZ 0x4f42fd
    if(integer::condition("JZ",flags)) goto L004f42fd;
  }
  L004f42e7: { // 0x4f42e7: 8a4856 MOV CL, byte ptr [EAX + 0x56]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000056u)));
  }
  L004f42ea: { // 0x4f42ea: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f42ec: { // 0x4f42ec: 0f841d010000 JZ 0x4f440f
    if(integer::condition("JZ",flags)) goto L004f440f;
  }
  L004f42f2: { // 0x4f42f2: 8a4855 MOV CL, byte ptr [EAX + 0x55]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000055u)));
  }
  L004f42f5: { // 0x4f42f5: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f42f7: { // 0x4f42f7: 0f8412010000 JZ 0x4f440f
    if(integer::condition("JZ",flags)) goto L004f440f;
  }
  L004f42fd: { // 0x4f42fd: 8b5d78 MOV EBX, dword ptr [EBP + 0x78]
    s.bx = m.r32((s.bp+0x00000078u));
  }
  L004f4300: { // 0x4f4300: c644241300 MOV byte ptr [ESP + 0x13], 0
    m.w8((f.sp+0x00000013u), 0u);
  }
  L004f4305: { // 0x4f4305: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L004f4306: { // 0x4f4306: 0f8803010000 JS 0x4f440f
    if(integer::condition("JS",flags)) goto L004f440f;
  }
  L004f430c: { // 0x4f430c: 8b4d6c MOV ECX, dword ptr [EBP + 0x6c]
    s.cx = m.r32((s.bp+0x0000006cu));
  }
  L004f430f: { // 0x4f430f: 8b3c99 MOV EDI, dword ptr [ECX + EBX*4]
    s.di = m.r32((s.cx+(s.bx * 4u)));
  }
  L004f4312: { // 0x4f4312: 8a477d MOV AL, byte ptr [EDI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000007du)));
  }
  L004f4315: { // 0x4f4315: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f4317: { // 0x4f4317: 7453 JZ 0x4f436c
    if(integer::condition("JZ",flags)) goto L004f436c;
  }
  L004f4319: { // 0x4f4319: 8a4776 MOV AL, byte ptr [EDI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000076u)));
  }
  L004f431c: { // 0x4f431c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f431e: { // 0x4f431e: 754c JNZ 0x4f436c
    if(integer::condition("JNZ",flags)) goto L004f436c;
  }
  L004f4320: { // 0x4f4320: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004f4322: { // 0x4f4322: 8d8fc0040000 LEA ECX, [EDI + 0x4c0]
    s.cx = (s.di+0x000004c0u);
  }
  L004f4328: { // 0x4f4328: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004f432a: { // 0x4f432a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f432c: { // 0x4f432c: 7410 JZ 0x4f433e
    if(integer::condition("JZ",flags)) goto L004f433e;
  }
  L004f432e: { // 0x4f432e: 39b074130000 CMP dword ptr [EAX + 0x1374], ESI
    (void)integer::sub(m.r32((s.ax+0x00001374u)),s.si,32,flags);
  }
  L004f4334: { // 0x4f4334: 7413 JZ 0x4f4349
    if(integer::condition("JZ",flags)) goto L004f4349;
  }
  L004f4336: { // 0x4f4336: 39b078130000 CMP dword ptr [EAX + 0x1378], ESI
    (void)integer::sub(m.r32((s.ax+0x00001378u)),s.si,32,flags);
  }
  L004f433c: { // 0x4f433c: 740b JZ 0x4f4349
    if(integer::condition("JZ",flags)) goto L004f4349;
  }
  L004f433e: { // 0x4f433e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004f433f: { // 0x4f433f: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L004f4342: { // 0x4f4342: 83fa03 CMP EDX, 3
    (void)integer::sub(s.dx,3u,32,flags);
  }
  L004f4345: { // 0x4f4345: 7ce1 JL 0x4f4328
    if(integer::condition("JL",flags)) goto L004f4328;
  }
  L004f4347: { // 0x4f4347: eb05 JMP 0x4f434e
    goto L004f434e;
  }
  L004f4349: { // 0x4f4349: c644241301 MOV byte ptr [ESP + 0x13], 1
    m.w8((f.sp+0x00000013u), 1u);
  }
  L004f434e: { // 0x4f434e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f4350: { // 0x4f4350: e81be1f5ff CALL 0x452470
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452470u,5194581u); flags=s.arithmetic_flags;
  }
  L004f4355: { // 0x4f4355: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004f4357: { // 0x4f4357: 741c JZ 0x4f4375
    if(integer::condition("JZ",flags)) goto L004f4375;
  }
  L004f4359: { // 0x4f4359: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f435b: { // 0x4f435b: e870e1f5ff CALL 0x4524d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004524d0u,5194592u); flags=s.arithmetic_flags;
  }
  L004f4360: { // 0x4f4360: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004f4362: { // 0x4f4362: 7411 JZ 0x4f4375
    if(integer::condition("JZ",flags)) goto L004f4375;
  }
  L004f4364: { // 0x4f4364: 8a442413 MOV AL, byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L004f4368: { // 0x4f4368: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f436a: { // 0x4f436a: 7509 JNZ 0x4f4375
    if(integer::condition("JNZ",flags)) goto L004f4375;
  }
  L004f436c: { // 0x4f436c: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L004f436d: { // 0x4f436d: 0f889c000000 JS 0x4f440f
    if(integer::condition("JS",flags)) goto L004f440f;
  }
  L004f4373: { // 0x4f4373: eb97 JMP 0x4f430c
    goto L004f430c;
  }
  L004f4375: { // 0x4f4375: 8b8dd0520000 MOV ECX, dword ptr [EBP + 0x52d0]
    s.cx = m.r32((s.bp+0x000052d0u));
  }
  L004f437b: { // 0x4f437b: 8b85d4520000 MOV EAX, dword ptr [EBP + 0x52d4]
    s.ax = m.r32((s.bp+0x000052d4u));
  }
  L004f4381: { // 0x4f4381: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f4383: { // 0x4f4383: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004f4387: { // 0x4f4387: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004f438b: { // 0x4f438b: 7d24 JGE 0x4f43b1
    if(integer::condition("JGE",flags)) goto L004f43b1;
  }
  L004f438d: { // 0x4f438d: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f438f: { // 0x4f438f: 7420 JZ 0x4f43b1
    if(integer::condition("JZ",flags)) goto L004f43b1;
  }
  L004f4391: { // 0x4f4391: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004f4393: { // 0x4f4393: 7415 JZ 0x4f43aa
    if(integer::condition("JZ",flags)) goto L004f43aa;
  }
  L004f4395: { // 0x4f4395: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L004f4399: { // 0x4f4399: da742418 FIDIV dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.divide_integer32(m.r32(address));
  }
  L004f439d: { // 0x4f439d: dc1d08577800 FCOMP qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004f43a3: { // 0x4f43a3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004f43a5: { // 0x4f43a5: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L004f43a8: { // 0x4f43a8: 7407 JZ 0x4f43b1
    if(integer::condition("JZ",flags)) goto L004f43b1;
  }
  L004f43aa: { // 0x4f43aa: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004f43af: { // 0x4f43af: eb02 JMP 0x4f43b3
    goto L004f43b3;
  }
  L004f43b1: { // 0x4f43b1: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f43b3: { // 0x4f43b3: 8b1de4e0a100 MOV EBX, dword ptr [0xa1e0e4]
    s.bx = m.r32((0x00a1e0e4u));
  }
  L004f43b9: { // 0x4f43b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f43ba: { // 0x4f43ba: 8b85a0010000 MOV EAX, dword ptr [EBP + 0x1a0]
    s.ax = m.r32((s.bp+0x000001a0u));
  }
  L004f43c0: { // 0x4f43c0: 3beb CMP EBP, EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L004f43c2: { // 0x4f43c2: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f43c5: { // 0x4f43c5: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L004f43c8: { // 0x4f43c8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004f43c9: { // 0x4f43c9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004f43cb: { // 0x4f43cb: e8c0df1900 CALL 0x692390
    s.arithmetic_flags=flags; invoke(m,s,f,0x00692390u,5194704u); flags=s.arithmetic_flags;
  }
  L004f43d0: { // 0x4f43d0: 3b2de4e0a100 CMP EBP, dword ptr [0xa1e0e4]
    (void)integer::sub(s.bp,m.r32((0x00a1e0e4u)),32,flags);
  }
  L004f43d6: { // 0x4f43d6: 7537 JNZ 0x4f440f
    if(integer::condition("JNZ",flags)) goto L004f440f;
  }
  L004f43d8: { // 0x4f43d8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f43d9: { // 0x4f43d9: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L004f43db: { // 0x4f43db: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004f43e0: { // 0x4f43e0: e8bbd91700 CALL 0x671da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00671da0u,5194725u); flags=s.arithmetic_flags;
  }
  L004f43e5: { // 0x4f43e5: 8b8da0010000 MOV ECX, dword ptr [EBP + 0x1a0]
    s.cx = m.r32((s.bp+0x000001a0u));
  }
  L004f43eb: { // 0x4f43eb: 8b14b1 MOV EDX, dword ptr [ECX + ESI*4]
    s.dx = m.r32((s.cx+(s.si * 4u)));
  }
  L004f43ee: { // 0x4f43ee: 8b4a24 MOV ECX, dword ptr [EDX + 0x24]
    s.cx = m.r32((s.dx+0x00000024u));
  }
  L004f43f1: { // 0x4f43f1: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004f43f3: { // 0x4f43f3: ff5040 CALL dword ptr [EAX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000040u)),5194742u); flags=s.arithmetic_flags;
  }
  L004f43f6: { // 0x4f43f6: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004f43f8: { // 0x4f43f8: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004f43fa: { // 0x4f43fa: b939000000 MOV ECX, 0x39
    s.cx = 0x00000039u;
  }
  L004f43ff: { // 0x4f43ff: e8fc2b1800 CALL 0x677000
    s.arithmetic_flags=flags; invoke(m,s,f,0x00677000u,5194756u); flags=s.arithmetic_flags;
  }
  L004f4404: { // 0x4f4404: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4405: { // 0x4f4405: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004f440a: { // 0x4f440a: e891d71700 CALL 0x671ba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00671ba0u,5194767u); flags=s.arithmetic_flags;
  }
  L004f440f: { // 0x4f440f: 8b85ac010000 MOV EAX, dword ptr [EBP + 0x1ac]
    s.ax = m.r32((s.bp+0x000001acu));
  }
  L004f4415: { // 0x4f4415: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004f4416: { // 0x4f4416: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004f4418: { // 0x4f4418: 0f8cb9feffff JL 0x4f42d7
    if(integer::condition("JL",flags)) goto L004f42d7;
  }
  L004f441e: { // 0x4f441e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f441f: { // 0x4f441f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f4420: { // 0x4f4420: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4421: { // 0x4f4421: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f4422: { // 0x4f4422: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004f4425: { // 0x4f4425: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
