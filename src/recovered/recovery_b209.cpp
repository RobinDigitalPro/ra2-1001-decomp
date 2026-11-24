#include "recovered/recovery_b209_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b209 {
namespace {
void f_0014d560(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_0014cf40(Memory&,State&,Frame&,const Operations&);
void f_0007b560(Memory&,State&,Frame&,const Operations&);
void f_0007b580(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0014cc50(Memory&,State&,Frame&,const Operations&);
void f_00163d80(Memory&,State&,Frame&,const Operations&);
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
void f_0002add0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042add0: { // 0x42add0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0042add4: { // 0x42add4: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0042add7: { // 0x42add7: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0042addb: { // 0x42addb: 66034102 ADD AX,word ptr [ECX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+0x00000002u)),16,flags));
  }
  L0042addf: { // 0x42addf: 660311 ADD DX,word ptr [ECX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.cx)),16,flags));
  }
  L0042ade2: { // 0x42ade2: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L0042ade7: { // 0x42ade7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0042adeb: { // 0x42adeb: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L0042adf0: { // 0x42adf0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0042adf4: { // 0x42adf4: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042adf6: { // 0x42adf6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0014cf40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cf40: { // 0x54cf40: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L0054cf46: { // 0x54cf46: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L0054cf4c: { // 0x54cf4c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cf4d: { // 0x54cf4d: 8d441001 LEA EAX,[EAX + EDX*0x1 + 0x1]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0054cf51: { // 0x54cf51: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0054cf55: { // 0x54cf55: 0fbf7202 MOVSX ESI,word ptr [EDX + 0x2]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L0054cf59: { // 0x54cf59: 0fbf12 MOVSX EDX,word ptr [EDX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054cf5c: { // 0x54cf5c: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L0054cf5f: { // 0x54cf5f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054cf61: { // 0x54cf61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cf62: { // 0x54cf62: 7905 JNS 0x0054cf69
    if(integer::condition("JNS",flags)) goto L0054cf69;
  }
  L0054cf64: { // 0x54cf64: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054cf66: { // 0x54cf66: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0054cf69: { // 0x54cf69: 8b4968 MOV ECX,dword ptr [ECX + 0x68]
    s.cx = m.r32((s.cx+0x00000068u));
  }
  L0054cf6c: { // 0x54cf6c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0054cf6e: { // 0x54cf6e: 7c03 JL 0x0054cf73
    if(integer::condition("JL",flags)) goto L0054cf73;
  }
  L0054cf70: { // 0x54cf70: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L0054cf73: { // 0x54cf73: c20400 RET 0x4
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
void f_0014cc50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cc50: { // 0x54cc50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054cc51: { // 0x54cc51: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0054cc55: { // 0x54cc55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cc56: { // 0x54cc56: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cc57: { // 0x54cc57: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cc58: { // 0x54cc58: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0054cc5b: { // 0x54cc5b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054cc5c: { // 0x54cc5c: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0054cc60: { // 0x54cc60: 750a JNZ 0x0054cc6c
    if(integer::condition("JNZ",flags)) goto L0054cc6c;
  }
  L0054cc62: { // 0x54cc62: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cc63: { // 0x54cc63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cc64: { // 0x54cc64: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cc65: { // 0x54cc65: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054cc67: { // 0x54cc67: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cc68: { // 0x54cc68: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cc69: { // 0x54cc69: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L0054cc6c: { // 0x54cc6c: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0054cc70: { // 0x54cc70: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054cc72: { // 0x54cc72: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cc73: { // 0x54cc73: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0054cc78: { // 0x54cc78: e8d3a70000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5557373u); flags=s.arithmetic_flags;
  }
  L0054cc7d: { // 0x54cc7d: 0fbf0b MOVSX ECX,word ptr [EBX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0054cc80: { // 0x54cc80: 8b3510a98100 MOV ESI,dword ptr [0x0081a910]
    s.si = m.r32((0x0081a910u));
  }
  L0054cc86: { // 0x54cc86: 88442418 MOV byte ptr [ESP + 0x18],AL
    m.w8((f.sp+0x00000018u), (s.ax & 0xffu));
  }
  L0054cc8a: { // 0x54cc8a: 0fbf4302 MOVSX EAX,word ptr [EBX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0054cc8e: { // 0x54cc8e: 8d1408 LEA EDX,[EAX + ECX*0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u));
  }
  L0054cc91: { // 0x54cc91: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0054cc93: { // 0x54cc93: 7e1e JLE 0x0054ccb3
    if(integer::condition("JLE",flags)) goto L0054ccb3;
  }
  L0054cc95: { // 0x54cc95: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0054cc97: { // 0x54cc97: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0054cc99: { // 0x54cc99: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0054cc9b: { // 0x54cc9b: 7d16 JGE 0x0054ccb3
    if(integer::condition("JGE",flags)) goto L0054ccb3;
  }
  L0054cc9d: { // 0x54cc9d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054cc9f: { // 0x54cc9f: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0054cca1: { // 0x54cca1: 7d10 JGE 0x0054ccb3
    if(integer::condition("JGE",flags)) goto L0054ccb3;
  }
  L0054cca3: { // 0x54cca3: a114a98100 MOV EAX,[0x0081a914]
    s.ax = m.r32((0x0081a914u));
  }
  L0054cca8: { // 0x54cca8: 8d0c46 LEA ECX,[ESI + EAX*0x2]
    s.cx = (s.si+(s.ax * 0x00000002u));
  }
  L0054ccab: { // 0x54ccab: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0054ccad: { // 0x54ccad: 7f04 JG 0x0054ccb3
    if(integer::condition("JG",flags)) goto L0054ccb3;
  }
  L0054ccaf: { // 0x54ccaf: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054ccb1: { // 0x54ccb1: eb02 JMP 0x0054ccb5
    goto L0054ccb5;
  }
  L0054ccb3: { // 0x54ccb3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054ccb5: { // 0x54ccb5: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0054ccb9: { // 0x54ccb9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054ccbb: { // 0x54ccbb: 750e JNZ 0x0054cccb
    if(integer::condition("JNZ",flags)) goto L0054cccb;
  }
  L0054ccbd: { // 0x54ccbd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ccbf: { // 0x54ccbf: 740a JZ 0x0054cccb
    if(integer::condition("JZ",flags)) goto L0054cccb;
  }
  L0054ccc1: { // 0x54ccc1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054ccc2: { // 0x54ccc2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054ccc3: { // 0x54ccc3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054ccc4: { // 0x54ccc4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054ccc6: { // 0x54ccc6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054ccc7: { // 0x54ccc7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054ccc8: { // 0x54ccc8: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L0054cccb: { // 0x54cccb: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L0054cccf: { // 0x54cccf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054ccd1: { // 0x54ccd1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054ccd2: { // 0x54ccd2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0054ccd7: { // 0x54ccd7: e874a70000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5557468u); flags=s.arithmetic_flags;
  }
  L0054ccdc: { // 0x54ccdc: 0fbf16 MOVSX EDX,word ptr [ESI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054ccdf: { // 0x54ccdf: 0fbf4e02 MOVSX ECX,word ptr [ESI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cce3: { // 0x54cce3: 8b3d10a98100 MOV EDI,dword ptr [0x0081a910]
    s.di = m.r32((0x0081a910u));
  }
  L0054cce9: { // 0x54cce9: 8844241c MOV byte ptr [ESP + 0x1c],AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L0054cced: { // 0x54cced: 8d2c11 LEA EBP,[ECX + EDX*0x1]
    s.bp = (s.cx+(s.dx * 0x00000001u));
  }
  L0054ccf0: { // 0x54ccf0: 3bef CMP EBP,EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L0054ccf2: { // 0x54ccf2: 7e1f JLE 0x0054cd13
    if(integer::condition("JLE",flags)) goto L0054cd13;
  }
  L0054ccf4: { // 0x54ccf4: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0054ccf6: { // 0x54ccf6: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054ccf8: { // 0x54ccf8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0054ccfa: { // 0x54ccfa: 7d17 JGE 0x0054cd13
    if(integer::condition("JGE",flags)) goto L0054cd13;
  }
  L0054ccfc: { // 0x54ccfc: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0054ccfe: { // 0x54ccfe: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0054cd00: { // 0x54cd00: 7d11 JGE 0x0054cd13
    if(integer::condition("JGE",flags)) goto L0054cd13;
  }
  L0054cd02: { // 0x54cd02: 8b0d14a98100 MOV ECX,dword ptr [0x0081a914]
    s.cx = m.r32((0x0081a914u));
  }
  L0054cd08: { // 0x54cd08: 8d144f LEA EDX,[EDI + ECX*0x2]
    s.dx = (s.di+(s.cx * 0x00000002u));
  }
  L0054cd0b: { // 0x54cd0b: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0054cd0d: { // 0x54cd0d: 7f04 JG 0x0054cd13
    if(integer::condition("JG",flags)) goto L0054cd13;
  }
  L0054cd0f: { // 0x54cd0f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054cd11: { // 0x54cd11: eb02 JMP 0x0054cd15
    goto L0054cd15;
  }
  L0054cd13: { // 0x54cd13: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054cd15: { // 0x54cd15: 8a4c242c MOV CL,byte ptr [ESP + 0x2c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000002cu)));
  }
  L0054cd19: { // 0x54cd19: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054cd1b: { // 0x54cd1b: 741e JZ 0x0054cd3b
    if(integer::condition("JZ",flags)) goto L0054cd3b;
  }
  L0054cd1d: { // 0x54cd1d: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0054cd21: { // 0x54cd21: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054cd23: { // 0x54cd23: 7416 JZ 0x0054cd3b
    if(integer::condition("JZ",flags)) goto L0054cd3b;
  }
  L0054cd25: { // 0x54cd25: 8a4c241c MOV CL,byte ptr [ESP + 0x1c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000001cu)));
  }
  L0054cd29: { // 0x54cd29: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054cd2b: { // 0x54cd2b: 750e JNZ 0x0054cd3b
    if(integer::condition("JNZ",flags)) goto L0054cd3b;
  }
  L0054cd2d: { // 0x54cd2d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cd2f: { // 0x54cd2f: 740a JZ 0x0054cd3b
    if(integer::condition("JZ",flags)) goto L0054cd3b;
  }
  L0054cd31: { // 0x54cd31: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cd32: { // 0x54cd32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cd33: { // 0x54cd33: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cd34: { // 0x54cd34: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054cd36: { // 0x54cd36: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cd37: { // 0x54cd37: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cd38: { // 0x54cd38: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L0054cd3b: { // 0x54cd3b: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054cd3f: { // 0x54cd3f: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0054cd43: { // 0x54cd43: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0054cd47: { // 0x54cd47: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054cd48: { // 0x54cd48: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cd49: { // 0x54cd49: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cd4a: { // 0x54cd4a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054cd4c: { // 0x54cd4c: e82f000000 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,5557585u); flags=s.arithmetic_flags;
  }
  L0054cd51: { // 0x54cd51: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0054cd55: { // 0x54cd55: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0054cd57: { // 0x54cd57: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054cd58: { // 0x54cd58: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cd59: { // 0x54cd59: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cd5a: { // 0x54cd5a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054cd5c: { // 0x54cd5c: e81f000000 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,5557601u); flags=s.arithmetic_flags;
  }
  L0054cd61: { // 0x54cd61: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0054cd63: { // 0x54cd63: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0054cd65: { // 0x54cd65: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cd66: { // 0x54cd66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cd67: { // 0x54cd67: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0054cd6a: { // 0x54cd6a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cd6b: { // 0x54cd6b: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L0054cd6d: { // 0x54cd6d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cd6e: { // 0x54cd6e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cd6f: { // 0x54cd6f: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
}
void f_00163d80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00563d80: { // 0x563d80: 83ec50 SUB ESP,0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  L00563d83: { // 0x563d83: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00563d87: { // 0x563d87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00563d88: { // 0x563d88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00563d89: { // 0x563d89: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00563d8a: { // 0x563d8a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00563d8c: { // 0x563d8c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00563d8d: { // 0x563d8d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00563d8f: { // 0x563d8f: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00563d92: { // 0x563d92: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00563d96: { // 0x563d96: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00563d9a: { // 0x563d9a: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L00563d9f: { // 0x563d9f: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00563da2: { // 0x563da2: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00563da5: { // 0x563da5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00563da7: { // 0x563da7: 7818 JS 0x00563dc1
    if(integer::condition("JS",flags)) goto L00563dc1;
  }
  L00563da9: { // 0x563da9: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00563dae: { // 0x563dae: 7d11 JGE 0x00563dc1
    if(integer::condition("JGE",flags)) goto L00563dc1;
  }
  L00563db0: { // 0x563db0: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00563db6: { // 0x563db6: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00563db9: { // 0x563db9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00563dbb: { // 0x563dbb: 7404 JZ 0x00563dc1
    if(integer::condition("JZ",flags)) goto L00563dc1;
  }
  L00563dbd: { // 0x563dbd: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00563dbf: { // 0x563dbf: eb0b JMP 0x00563dcc
    goto L00563dcc;
  }
  L00563dc1: { // 0x563dc1: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L00563dc7: { // 0x563dc7: bf1076a500 MOV EDI,0xa57610
    s.di = 0x00a57610u;
  }
  L00563dcc: { // 0x563dcc: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L00563dd1: { // 0x563dd1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563dd3: { // 0x563dd3: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00563dd7: { // 0x563dd7: e88477f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5651932u); flags=s.arithmetic_flags;
  }
  L00563ddc: { // 0x563ddc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563dde: { // 0x563dde: 750f JNZ 0x00563def
    if(integer::condition("JNZ",flags)) goto L00563def;
  }
  L00563de0: { // 0x563de0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563de2: { // 0x563de2: e89977f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5651943u); flags=s.arithmetic_flags;
  }
  L00563de7: { // 0x563de7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563de9: { // 0x563de9: 0f8490000000 JZ 0x00563e7f
    if(integer::condition("JZ",flags)) goto L00563e7f;
  }
  L00563def: { // 0x563def: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563df1: { // 0x563df1: e86a77f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5651958u); flags=s.arithmetic_flags;
  }
  L00563df6: { // 0x563df6: 8b0db0a8a300 MOV ECX,dword ptr [0x00a3a8b0]
    s.cx = m.r32((0x00a3a8b0u));
  }
  L00563dfc: { // 0x563dfc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563dfe: { // 0x563dfe: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L00563e01: { // 0x563e01: 7506 JNZ 0x00563e09
    if(integer::condition("JNZ",flags)) goto L00563e09;
  }
  L00563e03: { // 0x563e03: 8b0da047a500 MOV ECX,dword ptr [0x00a547a0]
    s.cx = m.r32((0x00a547a0u));
  }
  L00563e09: { // 0x563e09: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00563e0b: { // 0x563e0b: 8d542464 LEA EDX,[ESP + 0x64]
    s.dx = (f.sp+0x00000064u);
  }
  L00563e0f: { // 0x563e0f: 8b3c852caf7c00 MOV EDI,dword ptr [EAX*0x4 + 0x7caf2c]
    s.di = m.r32(((s.ax * 0x00000004u)+0x007caf2cu));
  }
  L00563e16: { // 0x563e16: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563e18: { // 0x563e18: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L00563e1b: { // 0x563e1b: 8d1c8da09d8300 LEA EBX,[ECX*0x4 + 0x839da0]
    s.bx = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  L00563e22: { // 0x563e22: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00563e26: { // 0x563e26: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00563e27: { // 0x563e27: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563e28: { // 0x563e28: e8a36fecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5652013u); flags=s.arithmetic_flags;
  }
  L00563e2d: { // 0x563e2d: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563e2f: { // 0x563e2f: 83c7fc ADD EDI,-0x4
    s.di = integer::add(s.di,0xfffffffcu,32,flags);
  }
  L00563e32: { // 0x563e32: 83e707 AND EDI,0x7
    s.di = integer::logical((s.di)&(0x00000007u),32,flags);
  }
  L00563e35: { // 0x563e35: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00563e39: { // 0x563e39: 8d442464 LEA EAX,[ESP + 0x64]
    s.ax = (f.sp+0x00000064u);
  }
  L00563e3d: { // 0x563e3d: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00563e41: { // 0x563e41: 8d3cbda09d8300 LEA EDI,[EDI*0x4 + 0x839da0]
    s.di = ((s.di * 0x00000004u)+0x00839da0u);
  }
  L00563e48: { // 0x563e48: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00563e49: { // 0x563e49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563e4a: { // 0x563e4a: e8816fecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5652047u); flags=s.arithmetic_flags;
  }
  L00563e4f: { // 0x563e4f: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563e51: { // 0x563e51: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L00563e55: { // 0x563e55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00563e56: { // 0x563e56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563e57: { // 0x563e57: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00563e5b: { // 0x563e5b: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00563e5f: { // 0x563e5f: e86c6fecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5652068u); flags=s.arithmetic_flags;
  }
  L00563e64: { // 0x563e64: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563e66: { // 0x563e66: 8d542464 LEA EDX,[ESP + 0x64]
    s.dx = (f.sp+0x00000064u);
  }
  L00563e6a: { // 0x563e6a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00563e6b: { // 0x563e6b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563e6c: { // 0x563e6c: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00563e70: { // 0x563e70: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00563e74: { // 0x563e74: e8576fecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5652089u); flags=s.arithmetic_flags;
  }
  L00563e79: { // 0x563e79: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563e7b: { // 0x563e7b: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00563e7f: { // 0x563e7f: 8d868c000000 LEA EAX,[ESI + 0x8c]
    s.ax = (s.si+0x0000008cu);
  }
  L00563e85: { // 0x563e85: c644243400 MOV byte ptr [ESP + 0x34],0x0
    m.w8((f.sp+0x00000034u), 0x00000000u);
  }
  L00563e8a: { // 0x563e8a: c644243c00 MOV byte ptr [ESP + 0x3c],0x0
    m.w8((f.sp+0x0000003cu), 0x00000000u);
  }
  L00563e8f: { // 0x563e8f: c644244400 MOV byte ptr [ESP + 0x44],0x0
    m.w8((f.sp+0x00000044u), 0x00000000u);
  }
  L00563e94: { // 0x563e94: c644244c00 MOV byte ptr [ESP + 0x4c],0x0
    m.w8((f.sp+0x0000004cu), 0x00000000u);
  }
  L00563e99: { // 0x563e99: c644245400 MOV byte ptr [ESP + 0x54],0x0
    m.w8((f.sp+0x00000054u), 0x00000000u);
  }
  L00563e9e: { // 0x563e9e: c644245c00 MOV byte ptr [ESP + 0x5c],0x0
    m.w8((f.sp+0x0000005cu), 0x00000000u);
  }
  L00563ea3: { // 0x563ea3: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00563ea5: { // 0x563ea5: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00563ea9: { // 0x563ea9: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00563ead: { // 0x563ead: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563eae: { // 0x563eae: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563eb0: { // 0x563eb0: e88b90feff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5652149u); flags=s.arithmetic_flags;
  }
  L00563eb5: { // 0x563eb5: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L00563eb8: { // 0x563eb8: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00563ebb: { // 0x563ebb: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00563ebf: { // 0x563ebf: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00563ec2: { // 0x563ec2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563ec3: { // 0x563ec3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563ec5: { // 0x563ec5: 0fbf1c28 MOVSX EBX,word ptr [EAX + EBP*0x1]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bp * 0x00000001u))),16));
  }
  L00563ec9: { // 0x563ec9: e87290feff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5652174u); flags=s.arithmetic_flags;
  }
  L00563ece: { // 0x563ece: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L00563ed1: { // 0x563ed1: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00563ed4: { // 0x563ed4: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00563ed7: { // 0x563ed7: 8d14db LEA EDX,[EBX + EBX*0x8]
    s.dx = (s.bx+(s.bx * 0x00000008u));
  }
  L00563eda: { // 0x563eda: 0fbf0c28 MOVSX ECX,word ptr [EAX + EBP*0x1]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bp * 0x00000001u))),16));
  }
  L00563ede: { // 0x563ede: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00563ee2: { // 0x563ee2: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L00563ee6: { // 0x563ee6: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563ee8: { // 0x563ee8: 8d3c90 LEA EDI,[EAX + EDX*0x4]
    s.di = (s.ax+(s.dx * 0x00000004u));
  }
  L00563eeb: { // 0x563eeb: 8b449008 MOV EAX,dword ptr [EAX + EDX*0x4 + 0x8]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)+0x00000008u));
  }
  L00563eef: { // 0x563eef: 8b5710 MOV EDX,dword ptr [EDI + 0x10]
    s.dx = m.r32((s.di+0x00000010u));
  }
  L00563ef2: { // 0x563ef2: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00563ef4: { // 0x563ef4: 7c28 JL 0x00563f1e
    if(integer::condition("JL",flags)) goto L00563f1e;
  }
  L00563ef6: { // 0x563ef6: 8a570d MOV DL,byte ptr [EDI + 0xd]
    s.dx = with_al(s.dx, m.r8((s.di+0x0000000du)));
  }
  L00563ef9: { // 0x563ef9: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00563efb: { // 0x563efb: 7504 JNZ 0x00563f01
    if(integer::condition("JNZ",flags)) goto L00563f01;
  }
  L00563efd: { // 0x563efd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00563eff: { // 0x563eff: 7534 JNZ 0x00563f35
    if(integer::condition("JNZ",flags)) goto L00563f35;
  }
  L00563f01: { // 0x563f01: 8b5714 MOV EDX,dword ptr [EDI + 0x14]
    s.dx = m.r32((s.di+0x00000014u));
  }
  L00563f04: { // 0x563f04: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00563f06: { // 0x563f06: 7e2d JLE 0x00563f35
    if(integer::condition("JLE",flags)) goto L00563f35;
  }
  L00563f08: { // 0x563f08: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00563f0a: { // 0x563f0a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00563f0c: { // 0x563f0c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00563f0e: { // 0x563f0e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563f0f: { // 0x563f0f: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00563f11: { // 0x563f11: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563f13: { // 0x563f13: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5652246u); flags=s.arithmetic_flags;
  }
  L00563f16: { // 0x563f16: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00563f1a: { // 0x563f1a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563f1c: { // 0x563f1c: 7417 JZ 0x00563f35
    if(integer::condition("JZ",flags)) goto L00563f35;
  }
  L00563f1e: { // 0x563f1e: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L00563f21: { // 0x563f21: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L00563f24: { // 0x563f24: 895710 MOV dword ptr [EDI + 0x10],EDX
    m.w32((s.di+0x00000010u), s.dx);
  }
  L00563f27: { // 0x563f27: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00563f2a: { // 0x563f2a: 8b7c2434 MOV EDI,dword ptr [ESP + 0x34]
    s.di = m.r32((f.sp+0x00000034u));
  }
  L00563f2e: { // 0x563f2e: 890cc2 MOV dword ptr [EDX + EAX*0x8],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.cx);
  }
  L00563f31: { // 0x563f31: 897cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.di);
  }
  L00563f35: { // 0x563f35: 8d04c9 LEA EAX,[ECX + ECX*0x8]
    s.ax = (s.cx+(s.cx * 0x00000008u));
  }
  L00563f38: { // 0x563f38: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00563f3c: { // 0x563f3c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00563f3e: { // 0x563f3e: 8b4c8210 MOV ECX,dword ptr [EDX + EAX*0x4 + 0x10]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)+0x00000010u));
  }
  L00563f42: { // 0x563f42: 8d3c82 LEA EDI,[EDX + EAX*0x4]
    s.di = (s.dx+(s.ax * 0x00000004u));
  }
  L00563f45: { // 0x563f45: 8b448208 MOV EAX,dword ptr [EDX + EAX*0x4 + 0x8]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)+0x00000008u));
  }
  L00563f49: { // 0x563f49: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00563f4b: { // 0x563f4b: 7c22 JL 0x00563f6f
    if(integer::condition("JL",flags)) goto L00563f6f;
  }
  L00563f4d: { // 0x563f4d: 8a4f0d MOV CL,byte ptr [EDI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000000du)));
  }
  L00563f50: { // 0x563f50: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00563f52: { // 0x563f52: 7504 JNZ 0x00563f58
    if(integer::condition("JNZ",flags)) goto L00563f58;
  }
  L00563f54: { // 0x563f54: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00563f56: { // 0x563f56: 752e JNZ 0x00563f86
    if(integer::condition("JNZ",flags)) goto L00563f86;
  }
  L00563f58: { // 0x563f58: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00563f5b: { // 0x563f5b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00563f5d: { // 0x563f5d: 7e27 JLE 0x00563f86
    if(integer::condition("JLE",flags)) goto L00563f86;
  }
  L00563f5f: { // 0x563f5f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00563f61: { // 0x563f61: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00563f63: { // 0x563f63: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00563f65: { // 0x563f65: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563f66: { // 0x563f66: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563f68: { // 0x563f68: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5652331u); flags=s.arithmetic_flags;
  }
  L00563f6b: { // 0x563f6b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563f6d: { // 0x563f6d: 7417 JZ 0x00563f86
    if(integer::condition("JZ",flags)) goto L00563f86;
  }
  L00563f6f: { // 0x563f6f: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L00563f72: { // 0x563f72: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00563f75: { // 0x563f75: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00563f78: { // 0x563f78: 894f10 MOV dword ptr [EDI + 0x10],ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L00563f7b: { // 0x563f7b: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00563f7f: { // 0x563f7f: 891cc2 MOV dword ptr [EDX + EAX*0x8],EBX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.bx);
  }
  L00563f82: { // 0x563f82: 894cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.cx);
  }
  L00563f86: { // 0x563f86: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00563f8a: { // 0x563f8a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563f8c: { // 0x563f8c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563f8d: { // 0x563f8d: e8ae8ffeff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5652370u); flags=s.arithmetic_flags;
  }
  L00563f92: { // 0x563f92: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L00563f95: { // 0x563f95: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00563f98: { // 0x563f98: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L00563f9c: { // 0x563f9c: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L00563f9f: { // 0x563f9f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563fa0: { // 0x563fa0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563fa2: { // 0x563fa2: 0fbf1c28 MOVSX EBX,word ptr [EAX + EBP*0x1]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bp * 0x00000001u))),16));
  }
  L00563fa6: { // 0x563fa6: e8958ffeff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5652395u); flags=s.arithmetic_flags;
  }
  L00563fab: { // 0x563fab: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L00563fae: { // 0x563fae: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00563fb1: { // 0x563fb1: 8d14db LEA EDX,[EBX + EBX*0x8]
    s.dx = (s.bx+(s.bx * 0x00000008u));
  }
  L00563fb4: { // 0x563fb4: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L00563fb7: { // 0x563fb7: 0fbf0c28 MOVSX ECX,word ptr [EAX + EBP*0x1]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bp * 0x00000001u))),16));
  }
  L00563fbb: { // 0x563fbb: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00563fbf: { // 0x563fbf: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L00563fc3: { // 0x563fc3: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563fc5: { // 0x563fc5: 8d3c90 LEA EDI,[EAX + EDX*0x4]
    s.di = (s.ax+(s.dx * 0x00000004u));
  }
  L00563fc8: { // 0x563fc8: 8b449008 MOV EAX,dword ptr [EAX + EDX*0x4 + 0x8]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)+0x00000008u));
  }
  L00563fcc: { // 0x563fcc: 8b5710 MOV EDX,dword ptr [EDI + 0x10]
    s.dx = m.r32((s.di+0x00000010u));
  }
  L00563fcf: { // 0x563fcf: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00563fd1: { // 0x563fd1: 7c28 JL 0x00563ffb
    if(integer::condition("JL",flags)) goto L00563ffb;
  }
  L00563fd3: { // 0x563fd3: 8a570d MOV DL,byte ptr [EDI + 0xd]
    s.dx = with_al(s.dx, m.r8((s.di+0x0000000du)));
  }
  L00563fd6: { // 0x563fd6: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00563fd8: { // 0x563fd8: 7504 JNZ 0x00563fde
    if(integer::condition("JNZ",flags)) goto L00563fde;
  }
  L00563fda: { // 0x563fda: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00563fdc: { // 0x563fdc: 7534 JNZ 0x00564012
    if(integer::condition("JNZ",flags)) goto L00564012;
  }
  L00563fde: { // 0x563fde: 8b5714 MOV EDX,dword ptr [EDI + 0x14]
    s.dx = m.r32((s.di+0x00000014u));
  }
  L00563fe1: { // 0x563fe1: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00563fe3: { // 0x563fe3: 7e2d JLE 0x00564012
    if(integer::condition("JLE",flags)) goto L00564012;
  }
  L00563fe5: { // 0x563fe5: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00563fe7: { // 0x563fe7: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00563fe9: { // 0x563fe9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00563feb: { // 0x563feb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563fec: { // 0x563fec: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00563fee: { // 0x563fee: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563ff0: { // 0x563ff0: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5652467u); flags=s.arithmetic_flags;
  }
  L00563ff3: { // 0x563ff3: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00563ff7: { // 0x563ff7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563ff9: { // 0x563ff9: 7417 JZ 0x00564012
    if(integer::condition("JZ",flags)) goto L00564012;
  }
  L00563ffb: { // 0x563ffb: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L00563ffe: { // 0x563ffe: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L00564001: { // 0x564001: 895710 MOV dword ptr [EDI + 0x10],EDX
    m.w32((s.di+0x00000010u), s.dx);
  }
  L00564004: { // 0x564004: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00564007: { // 0x564007: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L0056400b: { // 0x56400b: 890cc2 MOV dword ptr [EDX + EAX*0x8],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.cx);
  }
  L0056400e: { // 0x56400e: 897cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.di);
  }
  L00564012: { // 0x564012: 8d04c9 LEA EAX,[ECX + ECX*0x8]
    s.ax = (s.cx+(s.cx * 0x00000008u));
  }
  L00564015: { // 0x564015: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00564019: { // 0x564019: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0056401b: { // 0x56401b: 8b4c8210 MOV ECX,dword ptr [EDX + EAX*0x4 + 0x10]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)+0x00000010u));
  }
  L0056401f: { // 0x56401f: 8d3c82 LEA EDI,[EDX + EAX*0x4]
    s.di = (s.dx+(s.ax * 0x00000004u));
  }
  L00564022: { // 0x564022: 8b448208 MOV EAX,dword ptr [EDX + EAX*0x4 + 0x8]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)+0x00000008u));
  }
  L00564026: { // 0x564026: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00564028: { // 0x564028: 7c22 JL 0x0056404c
    if(integer::condition("JL",flags)) goto L0056404c;
  }
  L0056402a: { // 0x56402a: 8a4f0d MOV CL,byte ptr [EDI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000000du)));
  }
  L0056402d: { // 0x56402d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056402f: { // 0x56402f: 7504 JNZ 0x00564035
    if(integer::condition("JNZ",flags)) goto L00564035;
  }
  L00564031: { // 0x564031: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00564033: { // 0x564033: 752e JNZ 0x00564063
    if(integer::condition("JNZ",flags)) goto L00564063;
  }
  L00564035: { // 0x564035: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00564038: { // 0x564038: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0056403a: { // 0x56403a: 7e27 JLE 0x00564063
    if(integer::condition("JLE",flags)) goto L00564063;
  }
  L0056403c: { // 0x56403c: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0056403e: { // 0x56403e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00564040: { // 0x564040: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00564042: { // 0x564042: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00564043: { // 0x564043: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00564045: { // 0x564045: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5652552u); flags=s.arithmetic_flags;
  }
  L00564048: { // 0x564048: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056404a: { // 0x56404a: 7417 JZ 0x00564063
    if(integer::condition("JZ",flags)) goto L00564063;
  }
  L0056404c: { // 0x56404c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0056404f: { // 0x56404f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00564052: { // 0x564052: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00564055: { // 0x564055: 894f10 MOV dword ptr [EDI + 0x10],ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L00564058: { // 0x564058: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0056405c: { // 0x56405c: 891cc2 MOV dword ptr [EDX + EAX*0x8],EBX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.bx);
  }
  L0056405f: { // 0x56405f: 894cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.cx);
  }
  L00564063: { // 0x564063: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L00564067: { // 0x564067: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00564069: { // 0x564069: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056406a: { // 0x56406a: e8d18efeff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5652591u); flags=s.arithmetic_flags;
  }
  L0056406f: { // 0x56406f: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L00564072: { // 0x564072: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00564075: { // 0x564075: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L00564079: { // 0x564079: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L0056407c: { // 0x56407c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056407d: { // 0x56407d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056407f: { // 0x56407f: 0fbf1c28 MOVSX EBX,word ptr [EAX + EBP*0x1]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bp * 0x00000001u))),16));
  }
  L00564083: { // 0x564083: e8b88efeff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5652616u); flags=s.arithmetic_flags;
  }
  L00564088: { // 0x564088: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L0056408b: { // 0x56408b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0056408e: { // 0x56408e: 8d14db LEA EDX,[EBX + EBX*0x8]
    s.dx = (s.bx+(s.bx * 0x00000008u));
  }
  L00564091: { // 0x564091: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L00564094: { // 0x564094: 0fbf0c28 MOVSX ECX,word ptr [EAX + EBP*0x1]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bp * 0x00000001u))),16));
  }
  L00564098: { // 0x564098: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0056409c: { // 0x56409c: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L005640a0: { // 0x5640a0: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005640a2: { // 0x5640a2: 8d3c90 LEA EDI,[EAX + EDX*0x4]
    s.di = (s.ax+(s.dx * 0x00000004u));
  }
  L005640a5: { // 0x5640a5: 8b449008 MOV EAX,dword ptr [EAX + EDX*0x4 + 0x8]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)+0x00000008u));
  }
  L005640a9: { // 0x5640a9: 8b5710 MOV EDX,dword ptr [EDI + 0x10]
    s.dx = m.r32((s.di+0x00000010u));
  }
  L005640ac: { // 0x5640ac: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L005640ae: { // 0x5640ae: 7c28 JL 0x005640d8
    if(integer::condition("JL",flags)) goto L005640d8;
  }
  L005640b0: { // 0x5640b0: 8a570d MOV DL,byte ptr [EDI + 0xd]
    s.dx = with_al(s.dx, m.r8((s.di+0x0000000du)));
  }
  L005640b3: { // 0x5640b3: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005640b5: { // 0x5640b5: 7504 JNZ 0x005640bb
    if(integer::condition("JNZ",flags)) goto L005640bb;
  }
  L005640b7: { // 0x5640b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005640b9: { // 0x5640b9: 7534 JNZ 0x005640ef
    if(integer::condition("JNZ",flags)) goto L005640ef;
  }
  L005640bb: { // 0x5640bb: 8b5714 MOV EDX,dword ptr [EDI + 0x14]
    s.dx = m.r32((s.di+0x00000014u));
  }
  L005640be: { // 0x5640be: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005640c0: { // 0x5640c0: 7e2d JLE 0x005640ef
    if(integer::condition("JLE",flags)) goto L005640ef;
  }
  L005640c2: { // 0x5640c2: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L005640c4: { // 0x5640c4: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005640c6: { // 0x5640c6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005640c8: { // 0x5640c8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005640c9: { // 0x5640c9: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005640cb: { // 0x5640cb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005640cd: { // 0x5640cd: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5652688u); flags=s.arithmetic_flags;
  }
  L005640d0: { // 0x5640d0: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L005640d4: { // 0x5640d4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005640d6: { // 0x5640d6: 7417 JZ 0x005640ef
    if(integer::condition("JZ",flags)) goto L005640ef;
  }
  L005640d8: { // 0x5640d8: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L005640db: { // 0x5640db: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L005640de: { // 0x5640de: 895710 MOV dword ptr [EDI + 0x10],EDX
    m.w32((s.di+0x00000010u), s.dx);
  }
  L005640e1: { // 0x5640e1: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L005640e4: { // 0x5640e4: 8b7c2454 MOV EDI,dword ptr [ESP + 0x54]
    s.di = m.r32((f.sp+0x00000054u));
  }
  L005640e8: { // 0x5640e8: 890cc2 MOV dword ptr [EDX + EAX*0x8],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.cx);
  }
  L005640eb: { // 0x5640eb: 897cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.di);
  }
  L005640ef: { // 0x5640ef: 8d04c9 LEA EAX,[ECX + ECX*0x8]
    s.ax = (s.cx+(s.cx * 0x00000008u));
  }
  L005640f2: { // 0x5640f2: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005640f6: { // 0x5640f6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005640f8: { // 0x5640f8: 8b4c8210 MOV ECX,dword ptr [EDX + EAX*0x4 + 0x10]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)+0x00000010u));
  }
  L005640fc: { // 0x5640fc: 8d3c82 LEA EDI,[EDX + EAX*0x4]
    s.di = (s.dx+(s.ax * 0x00000004u));
  }
  L005640ff: { // 0x5640ff: 8b448208 MOV EAX,dword ptr [EDX + EAX*0x4 + 0x8]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)+0x00000008u));
  }
  L00564103: { // 0x564103: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00564105: { // 0x564105: 7c22 JL 0x00564129
    if(integer::condition("JL",flags)) goto L00564129;
  }
  L00564107: { // 0x564107: 8a4f0d MOV CL,byte ptr [EDI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000000du)));
  }
  L0056410a: { // 0x56410a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0056410c: { // 0x56410c: 7504 JNZ 0x00564112
    if(integer::condition("JNZ",flags)) goto L00564112;
  }
  L0056410e: { // 0x56410e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00564110: { // 0x564110: 752e JNZ 0x00564140
    if(integer::condition("JNZ",flags)) goto L00564140;
  }
  L00564112: { // 0x564112: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00564115: { // 0x564115: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00564117: { // 0x564117: 7e27 JLE 0x00564140
    if(integer::condition("JLE",flags)) goto L00564140;
  }
  L00564119: { // 0x564119: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0056411b: { // 0x56411b: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0056411d: { // 0x56411d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0056411f: { // 0x56411f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00564120: { // 0x564120: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00564122: { // 0x564122: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5652773u); flags=s.arithmetic_flags;
  }
  L00564125: { // 0x564125: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00564127: { // 0x564127: 7417 JZ 0x00564140
    if(integer::condition("JZ",flags)) goto L00564140;
  }
  L00564129: { // 0x564129: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0056412c: { // 0x56412c: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L0056412f: { // 0x56412f: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00564132: { // 0x564132: 894f10 MOV dword ptr [EDI + 0x10],ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L00564135: { // 0x564135: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00564139: { // 0x564139: 891cc2 MOV dword ptr [EDX + EAX*0x8],EBX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.bx);
  }
  L0056413c: { // 0x56413c: 894cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.cx);
  }
  L00564140: { // 0x564140: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00564144: { // 0x564144: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  L00564147: { // 0x564147: 83c118 ADD ECX,0x18
    s.cx = integer::add(s.cx,0x00000018u,32,flags);
  }
  L0056414a: { // 0x56414a: 83fd06 CMP EBP,0x6
    (void)integer::sub(s.bp,0x00000006u,32,flags);
  }
  L0056414d: { // 0x56414d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00564151: { // 0x564151: 0f8c52fdffff JL 0x00563ea9
    if(integer::condition("JL",flags)) goto L00563ea9;
  }
  L00564157: { // 0x564157: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00564158: { // 0x564158: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00564159: { // 0x564159: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056415a: { // 0x56415a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056415b: { // 0x56415b: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  L0056415e: { // 0x56415e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5559648u:f_0014d560(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
case 5558080u:f_0014cf40(m,s,child,{});break;
case 4699488u:f_0007b560(m,s,child,{});break;
case 4699520u:f_0007b580(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5557328u:f_0014cc50(m,s,child,{});break;
case 5651840u:f_00163d80(m,s,child,{});break;
default:throw std::domain_error("recovery209 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0054d6c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 for(unsigned offset=0;offset<0x400u;offset+=4)m.w32(frame_entry+4-0x400u+offset,i.stack_minus8);
 State s{};s.bx=0x13579bdfu;s.si=0x2468ace0u;s.di=0x789abcdeu;s.bp=i.stack_minus8;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054d6c0: { // 0x54d6c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d6c1: { // 0x54d6c1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L0054d6c5: { // 0x54d6c5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054d6c6: { // 0x54d6c6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054d6c7: { // 0x54d6c7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d6c9: { // 0x54d6c9: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0054d6cb: { // 0x54d6cb: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0054d6cd: { // 0x54d6cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d6ce: { // 0x54d6ce: e88dfeffff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5560019u); flags=s.arithmetic_flags;
  }
  L0054d6d3: { // 0x54d6d3: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0054d6d5: { // 0x54d6d5: 83fdff CMP EBP,-0x1
    (void)integer::sub(s.bp,0xffffffffu,32,flags);
  }
  L0054d6d8: { // 0x54d6d8: 7522 JNZ 0x0054d6fc
    if(integer::condition("JNZ",flags)) goto L0054d6fc;
  }
  L0054d6da: { // 0x54d6da: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d6dc: { // 0x54d6dc: e84ffbffff CALL 0x0054d230
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d230u,5560033u); flags=s.arithmetic_flags;
  }
  L0054d6e1: { // 0x54d6e1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d6e3: { // 0x54d6e3: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0054d6e5: { // 0x54d6e5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d6e6: { // 0x54d6e6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d6e8: { // 0x54d6e8: e873feffff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5560045u); flags=s.arithmetic_flags;
  }
  L0054d6ed: { // 0x54d6ed: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0054d6ef: { // 0x54d6ef: 83fdff CMP EBP,-0x1
    (void)integer::sub(s.bp,0xffffffffu,32,flags);
  }
  L0054d6f2: { // 0x54d6f2: 7508 JNZ 0x0054d6fc
    if(integer::condition("JNZ",flags)) goto L0054d6fc;
  }
  L0054d6f4: { // 0x54d6f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d6f5: { // 0x54d6f5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d6f6: { // 0x54d6f6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054d6f8: { // 0x54d6f8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d6f9: { // 0x54d6f9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0054d6fc: { // 0x54d6fc: 83fdff CMP EBP,-0x1
    (void)integer::sub(s.bp,0xffffffffu,32,flags);
  }
  L0054d6ff: { // 0x54d6ff: c644241000 MOV byte ptr [ESP + 0x10],0x0
    m.w8((f.sp+0x00000010u), 0x00000000u);
  }
  L0054d704: { // 0x54d704: 745c JZ 0x0054d762
    if(integer::condition("JZ",flags)) goto L0054d762;
  }
  L0054d706: { // 0x54d706: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054d707: { // 0x54d707: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  L0054d70a: { // 0x54d70a: 8bfd MOV EDI,EBP
    s.di = s.bp;
  }
  L0054d70c: { // 0x54d70c: c1e704 SHL EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054d70f: { // 0x54d70f: 8a4c3808 MOV CL,byte ptr [EAX + EDI*0x1 + 0x8]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.di * 0x00000001u)+0x00000008u)));
  }
  L0054d713: { // 0x54d713: 8d443808 LEA EAX,[EAX + EDI*0x1 + 0x8]
    s.ax = (s.ax+(s.di * 0x00000001u)+0x00000008u);
  }
  L0054d717: { // 0x54d717: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054d719: { // 0x54d719: 7533 JNZ 0x0054d74e
    if(integer::condition("JNZ",flags)) goto L0054d74e;
  }
  L0054d71b: { // 0x54d71b: c60001 MOV byte ptr [EAX],0x1
    m.w8((s.ax), 0x00000001u);
  }
  L0054d71e: { // 0x54d71e: 8b4e50 MOV ECX,dword ptr [ESI + 0x50]
    s.cx = m.r32((s.si+0x00000050u));
  }
  L0054d721: { // 0x54d721: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L0054d723: { // 0x54d723: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054d724: { // 0x54d724: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d726: { // 0x54d726: e855660100 CALL 0x00563d80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00563d80u,5560107u); flags=s.arithmetic_flags;
  }
  L0054d72b: { // 0x54d72b: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  L0054d72e: { // 0x54d72e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d730: { // 0x54d730: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d732: { // 0x54d732: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d734: { // 0x54d734: 8d043a LEA EAX,[EDX + EDI*0x1]
    s.ax = (s.dx+(s.di * 0x00000001u));
  }
  L0054d737: { // 0x54d737: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d739: { // 0x54d739: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
  L0054d73c: { // 0x54d73c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054d73d: { // 0x54d73d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054d73e: { // 0x54d73e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d740: { // 0x54d740: e80bf5ffff CALL 0x0054cc50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cc50u,5560133u); flags=s.arithmetic_flags;
  }
  L0054d745: { // 0x54d745: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d747: { // 0x54d747: 7505 JNZ 0x0054d74e
    if(integer::condition("JNZ",flags)) goto L0054d74e;
  }
  L0054d749: { // 0x54d749: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  L0054d74e: { // 0x54d74e: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0054d74f: { // 0x54d74f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d751: { // 0x54d751: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054d752: { // 0x54d752: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0054d754: { // 0x54d754: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d755: { // 0x54d755: e806feffff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5560154u); flags=s.arithmetic_flags;
  }
  L0054d75a: { // 0x54d75a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0054d75c: { // 0x54d75c: 83fdff CMP EBP,-0x1
    (void)integer::sub(s.bp,0xffffffffu,32,flags);
  }
  L0054d75f: { // 0x54d75f: 75a6 JNZ 0x0054d707
    if(integer::condition("JNZ",flags)) goto L0054d707;
  }
  L0054d761: { // 0x54d761: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d762: { // 0x54d762: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  L0054d766: { // 0x54d766: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d767: { // 0x54d767: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d768: { // 0x54d768: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d769: { // 0x54d769: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
