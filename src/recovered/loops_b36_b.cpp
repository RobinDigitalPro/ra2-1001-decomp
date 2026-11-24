#include "recovered/loops_b36_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::loops_b36 {
namespace {
void f_00165440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x565440: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x565441: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x565443: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  { // 0x565449: c7860801000001000000 MOV dword ptr [ESI + 0x108],0x1
    m.w32((s.si+0x00000108u), 0x00000001u);
  }
  { // 0x565453: 89860c010000 MOV dword ptr [ESI + 0x10c],EAX
    m.w32((s.si+0x0000010cu), s.ax);
  }
  { // 0x565459: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  { // 0x56545c: 898e10010000 MOV dword ptr [ESI + 0x110],ECX
    m.w32((s.si+0x00000110u), s.cx);
  }
  { // 0x565462: 8b9638010000 MOV EDX,dword ptr [ESI + 0x138]
    s.dx = m.r32((s.si+0x00000138u));
  }
  { // 0x565468: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  { // 0x56546b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x56546d: 8d441004 LEA EAX,[EAX + EDX*0x1 + 0x4]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000004u);
  }
  { // 0x565471: 898614010000 MOV dword ptr [ESI + 0x114],EAX
    m.w32((s.si+0x00000114u), s.ax);
  }
  { // 0x565477: e8041effff CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x56547c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x56547e: 7412 JZ 0x00565492
    if(integer::condition("JZ",flags)) goto L00565492;
  }
  L00565480: { // 0x565480: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x565482: e87965f1ff CALL 0x0047ba00
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x565487: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x565489: e8f21dffff CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x56548e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x565490: 75ee JNZ 0x00565480
    if(integer::condition("JNZ",flags)) goto L00565480;
  }
  L00565492: { // 0x565492: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x565493: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0016b680(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x56b680: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x56b681: a14c6b8300 MOV EAX,[0x00836b4c]
    s.ax = m.r32((0x00836b4cu));
  }
  { // 0x56b686: 0fafc0 IMUL EAX,EAX
    s.ax = integer::imul(s.ax,s.ax,32,flags);
  }
  { // 0x56b689: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x56b68b: 7e6a JLE 0x0056b6f7
    if(integer::condition("JLE",flags)) goto L0056b6f7;
  }
  { // 0x56b68d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x56b68e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x56b68f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x56b691: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  { // 0x56b696: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x56b697: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0056b699: { // 0x56b699: 8b0406 MOV EAX,dword ptr [ESI + EAX*0x1]
    s.ax = m.r32((s.si+(s.ax * 0x00000001u)));
  }
  { // 0x56b69c: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x56b6a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x56b6a1: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x56b6a6: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x56b6aa: e8519efdff CALL 0x00545500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x56b6af: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x56b6b1: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  { // 0x56b6b6: 837c0638ff CMP dword ptr [ESI + EAX*0x1 + 0x38],-0x1
    (void)integer::sub(m.r32((s.si+(s.ax * 0x00000001u)+0x00000038u)),0xffffffffu,32,flags);
  }
  { // 0x56b6bb: 7531 JNZ 0x0056b6ee
    if(integer::condition("JNZ",flags)) goto L0056b6ee;
  }
  { // 0x56b6bd: 66833c0600 CMP word ptr [ESI + EAX*0x1],0x0
    (void)integer::sub(m.r16((s.si+(s.ax * 0x00000001u))),0x00000000u,16,flags);
  }
  { // 0x56b6c2: 7508 JNZ 0x0056b6cc
    if(integer::condition("JNZ",flags)) goto L0056b6cc;
  }
  { // 0x56b6c4: 66837c060200 CMP word ptr [ESI + EAX*0x1 + 0x2],0x0
    (void)integer::sub(m.r16((s.si+(s.ax * 0x00000001u)+0x00000002u)),0x00000000u,16,flags);
  }
  { // 0x56b6ca: 7422 JZ 0x0056b6ee
    if(integer::condition("JZ",flags)) goto L0056b6ee;
  }
  L0056b6cc: { // 0x56b6cc: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x56b6ce: e80dfdf0ff CALL 0x0047b3e0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x56b6d3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x56b6d5: 750b JNZ 0x0056b6e2
    if(integer::condition("JNZ",flags)) goto L0056b6e2;
  }
  { // 0x56b6d7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x56b6d9: e8e2fef0ff CALL 0x0047b5c0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x56b6de: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x56b6e0: 7407 JZ 0x0056b6e9
    if(integer::condition("JZ",flags)) goto L0056b6e9;
  }
  L0056b6e2: { // 0x56b6e2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x56b6e4: e807f8ffff CALL 0x0056aef0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0056b6e9: { // 0x56b6e9: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0056b6ee: { // 0x56b6ee: 83c650 ADD ESI,0x50
    s.si = integer::add(s.si,0x00000050u,32,flags);
  }
  { // 0x56b6f1: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x56b6f2: 75a5 JNZ 0x0056b699
    if(integer::condition("JNZ",flags)) goto L0056b699;
  }
  { // 0x56b6f4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x56b6f5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x56b6f6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056b6f7: { // 0x56b6f7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x56b6f8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0016b700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x56b700: a14c6b8300 MOV EAX,[0x00836b4c]
    s.ax = m.r32((0x00836b4cu));
  }
  { // 0x56b705: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x56b706: 0fafc0 IMUL EAX,EAX
    s.ax = integer::imul(s.ax,s.ax,32,flags);
  }
  { // 0x56b709: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x56b70b: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  { // 0x56b70d: 7e41 JLE 0x0056b750
    if(integer::condition("JLE",flags)) goto L0056b750;
  }
  { // 0x56b70f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x56b710: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x56b711: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x56b713: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0056b715: { // 0x56b715: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  { // 0x56b71a: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x56b71c: 837838ff CMP dword ptr [EAX + 0x38],-0x1
    (void)integer::sub(m.r32((s.ax+0x00000038u)),0xffffffffu,32,flags);
  }
  { // 0x56b720: 7526 JNZ 0x0056b748
    if(integer::condition("JNZ",flags)) goto L0056b748;
  }
  { // 0x56b722: 66833800 CMP word ptr [EAX],0x0
    (void)integer::sub(m.r16((s.ax)),0x00000000u,16,flags);
  }
  { // 0x56b726: 7507 JNZ 0x0056b72f
    if(integer::condition("JNZ",flags)) goto L0056b72f;
  }
  { // 0x56b728: 6683780200 CMP word ptr [EAX + 0x2],0x0
    (void)integer::sub(m.r16((s.ax+0x00000002u)),0x00000000u,16,flags);
  }
  { // 0x56b72d: 7419 JZ 0x0056b748
    if(integer::condition("JZ",flags)) goto L0056b748;
  }
  L0056b72f: { // 0x56b72f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x56b730: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x56b735: e8c69dfdff CALL 0x00545500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x56b73a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x56b73c: e8aff7ffff CALL 0x0056aef0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x56b741: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x56b743: 7403 JZ 0x0056b748
    if(integer::condition("JZ",flags)) goto L0056b748;
  }
  { // 0x56b745: 88581a MOV byte ptr [EAX + 0x1a],BL
    m.w8((s.ax+0x0000001au), (s.bx & 0xffu));
  }
  L0056b748: { // 0x56b748: 83c650 ADD ESI,0x50
    s.si = integer::add(s.si,0x00000050u,32,flags);
  }
  { // 0x56b74b: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x56b74c: 75c7 JNZ 0x0056b715
    if(integer::condition("JNZ",flags)) goto L0056b715;
  }
  { // 0x56b74e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x56b74f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056b750: { // 0x56b750: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x56b751: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00182040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x582040: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x582041: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x582043: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  { // 0x582046: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x582049: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x58204e: e8ed52fdff CALL 0x00557340
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x582053: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x582058: e82352fdff CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x58205d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x58205f: 7458 JZ 0x005820b9
    if(integer::condition("JZ",flags)) goto L005820b9;
  }
  L00582061: { // 0x582061: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  { // 0x582064: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  { // 0x58206a: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x58206e: 0fbf442406 MOVSX EAX,word ptr [ESP + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000006u)),16));
  }
  { // 0x582073: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  { // 0x58207a: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x58207d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x58207f: 8b0d0c0d7900 MOV ECX,dword ptr [0x00790d0c]
    s.cx = m.r32((0x00790d0cu));
  }
  { // 0x582085: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x582088: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x58208b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x58208d: 8b15080d7900 MOV EDX,dword ptr [0x00790d08]
    s.dx = m.r32((0x00790d08u));
  }
  { // 0x582093: 895028 MOV dword ptr [EAX + 0x28],EDX
    m.w32((s.ax+0x00000028u), s.dx);
  }
  { // 0x582096: 89482c MOV dword ptr [EAX + 0x2c],ECX
    m.w32((s.ax+0x0000002cu), s.cx);
  }
  { // 0x582099: 8b15100d7900 MOV EDX,dword ptr [0x00790d10]
    s.dx = m.r32((0x00790d10u));
  }
  { // 0x58209f: 8b0d140d7900 MOV ECX,dword ptr [0x00790d14]
    s.cx = m.r32((0x00790d14u));
  }
  { // 0x5820a5: 895020 MOV dword ptr [EAX + 0x20],EDX
    m.w32((s.ax+0x00000020u), s.dx);
  }
  { // 0x5820a8: 894824 MOV dword ptr [EAX + 0x24],ECX
    m.w32((s.ax+0x00000024u), s.cx);
  }
  { // 0x5820ab: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5820b0: e8cb51fdff CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5820b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5820b7: 75a8 JNZ 0x00582061
    if(integer::condition("JNZ",flags)) goto L00582061;
  }
  L005820b9: { // 0x5820b9: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  { // 0x5820bb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5820bc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00185180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x585180: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x585183: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  { // 0x585187: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  { // 0x58518a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58518b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x58518c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58518d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58518e: 8d5107 LEA EDX,[ECX + 0x7]
    s.dx = (s.cx+0x00000007u);
  }
  { // 0x585191: 8d79f9 LEA EDI,[ECX + -0x7]
    s.di = (s.cx-0x00000007u);
  }
  { // 0x585194: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  { // 0x585196: 8d68f9 LEA EBP,[EAX + -0x7]
    s.bp = (s.ax-0x00000007u);
  }
  { // 0x585199: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  { // 0x58519d: 8d5807 LEA EBX,[EAX + 0x7]
    s.bx = (s.ax+0x00000007u);
  }
  { // 0x5851a0: 7d38 JGE 0x005851da
    if(integer::condition("JGE",flags)) goto L005851da;
  }
  L005851a2: { // 0x5851a2: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  { // 0x5851a4: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  { // 0x5851a6: 7d2d JGE 0x005851d5
    if(integer::condition("JGE",flags)) goto L005851d5;
  }
  L005851a8: { // 0x5851a8: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x5851ac: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5851b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5851b2: 66897c2414 MOV word ptr [ESP + 0x14],DI
    m.w16((f.sp+0x00000014u), (s.di & 0xffffu));
  }
  { // 0x5851b7: 6689742416 MOV word ptr [ESP + 0x16],SI
    m.w16((f.sp+0x00000016u), (s.si & 0xffffu));
  }
  { // 0x5851bc: e83f03fcff CALL 0x00545500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5851c1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5851c3: e81860efff CALL 0x0047b1e0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5851c8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5851ca: 7518 JNZ 0x005851e4
    if(integer::condition("JNZ",flags)) goto L005851e4;
  }
  { // 0x5851cc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x5851cd: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x5851cf: 7cd7 JL 0x005851a8
    if(integer::condition("JL",flags)) goto L005851a8;
  }
  { // 0x5851d1: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005851d5: { // 0x5851d5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5851d6: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  { // 0x5851d8: 7cc8 JL 0x005851a2
    if(integer::condition("JL",flags)) goto L005851a2;
  }
  L005851da: { // 0x5851da: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5851db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5851dc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5851dd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5851df: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5851e0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5851e3: c3 RET
    finish(m,s,f,0u); return;
  }
  L005851e4: { // 0x5851e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5851e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5851e6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5851e7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5851e9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5851ea: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5851ed: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00191de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x591de0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x591de1: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x591de3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x591de4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x591de5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x591de7: 7423 JZ 0x00591e0c
    if(integer::condition("JZ",flags)) goto L00591e0c;
  }
  { // 0x591de9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x591deb: be04877b00 MOV ESI,0x7b8704
    s.si = 0x007b8704u;
  }
  L00591df0: { // 0x591df0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x591df2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x591df3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x591df4: e867ba1d00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x591df9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x591dfc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x591dfe: 7413 JZ 0x00591e13
    if(integer::condition("JZ",flags)) goto L00591e13;
  }
  { // 0x591e00: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x591e03: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x591e04: 81fe7c877b00 CMP ESI,0x7b877c
    (void)integer::sub(s.si,0x007b877cu,32,flags);
  }
  { // 0x591e0a: 7ce4 JL 0x00591df0
    if(integer::condition("JL",flags)) goto L00591df0;
  }
  L00591e0c: { // 0x591e0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x591e0d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x591e0e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x591e11: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x591e12: c3 RET
    finish(m,s,f,0u); return;
  }
  L00591e13: { // 0x591e13: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x591e15: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x591e16: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x591e17: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x591e18: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019a6f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59a6f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59a6f1: be588aa500 MOV ESI,0xa58a58
    s.si = 0x00a58a58u;
  }
  L0059a6f6: { // 0x59a6f6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x59a6f8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x59a6fa: 740f JZ 0x0059a70b
    if(integer::condition("JZ",flags)) goto L0059a70b;
  }
  { // 0x59a6fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59a6fd: e8792f1d00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x59a702: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x59a705: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L0059a70b: { // 0x59a70b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x59a70e: 81fe788aa500 CMP ESI,0xa58a78
    (void)integer::sub(s.si,0x00a58a78u,32,flags);
  }
  { // 0x59a714: 7ce0 JL 0x0059a6f6
    if(integer::condition("JL",flags)) goto L0059a6f6;
  }
  { // 0x59a716: a1288ba500 MOV EAX,[0x00a58b28]
    s.ax = m.r32((0x00a58b28u));
  }
  { // 0x59a71b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59a71c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x59a71e: 7438 JZ 0x0059a758
    if(integer::condition("JZ",flags)) goto L0059a758;
  }
  { // 0x59a720: a12c8ba500 MOV EAX,[0x00a58b2c]
    s.ax = m.r32((0x00a58b2cu));
  }
  { // 0x59a725: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59a726: ff1558507800 CALL dword ptr [0x00785058]
    const std::uint32_t call_target=m.r32((0x00785058u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x59a72c: 8b0d288ba500 MOV ECX,dword ptr [0x00a58b28]
    s.cx = m.r32((0x00a58b28u));
  }
  { // 0x59a732: e88979f8ff CALL 0x005220c0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x59a737: 8b0d288ba500 MOV ECX,dword ptr [0x00a58b28]
    s.cx = m.r32((0x00a58b28u));
  }
  { // 0x59a73d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x59a73e: ff15d4537800 CALL dword ptr [0x007853d4]
    const std::uint32_t call_target=m.r32((0x007853d4u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x59a744: c7052c8ba50000000000 MOV dword ptr [0x00a58b2c],0x0
    m.w32((0x00a58b2cu), 0x00000000u);
  }
  { // 0x59a74e: c705288ba50000000000 MOV dword ptr [0x00a58b28],0x0
    m.w32((0x00a58b28u), 0x00000000u);
  }
  L0059a758: { // 0x59a758: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019a8c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59a8c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x59a8c1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x59a8c2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59a8c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59a8c4: bb588aa500 MOV EBX,0xa58a58
    s.bx = 0x00a58a58u;
  }
  L0059a8c9: { // 0x59a8c9: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x59a8cb: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x59a8cd: 8da9d0070000 LEA EBP,[ECX + 0x7d0]
    s.bp = (s.cx+0x000007d0u);
  }
  L0059a8d3: { // 0x59a8d3: 8d140f LEA EDX,[EDI + ECX*0x1]
    s.dx = (s.di+(s.cx * 0x00000001u));
  }
  { // 0x59a8d6: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x59a8d8: be50000000 MOV ESI,0x50
    s.si = 0x00000050u;
  }
  L0059a8dd: { // 0x59a8dd: c60220 MOV byte ptr [EDX],0x20
    m.w8((s.dx), 0x00000020u);
  }
  { // 0x59a8e0: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  { // 0x59a8e6: 83c064 ADD EAX,0x64
    s.ax = integer::add(s.ax,0x00000064u,32,flags);
  }
  { // 0x59a8e9: 83c219 ADD EDX,0x19
    s.dx = integer::add(s.dx,0x00000019u,32,flags);
  }
  { // 0x59a8ec: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x59a8ed: 75ee JNZ 0x0059a8dd
    if(integer::condition("JNZ",flags)) goto L0059a8dd;
  }
  { // 0x59a8ef: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x59a8f0: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  { // 0x59a8f3: 83ff19 CMP EDI,0x19
    (void)integer::sub(s.di,0x00000019u,32,flags);
  }
  { // 0x59a8f6: 7cdb JL 0x0059a8d3
    if(integer::condition("JL",flags)) goto L0059a8d3;
  }
  { // 0x59a8f8: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x59a8fa: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  { // 0x59a8fc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x59a8fe: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x59a900: c6813427000001 MOV byte ptr [ECX + 0x2734],0x1
    m.w8((s.cx+0x00002734u), 0x00000001u);
  }
  { // 0x59a907: e8740f0000 CALL 0x0059b880
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x59a90c: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  { // 0x59a90f: 81fb788aa500 CMP EBX,0xa58a78
    (void)integer::sub(s.bx,0x00a58a78u,32,flags);
  }
  { // 0x59a915: 7cb2 JL 0x0059a8c9
    if(integer::condition("JL",flags)) goto L0059a8c9;
  }
  { // 0x59a917: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x59a918: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59a919: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x59a91a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x59a91b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a4070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a4070: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a4071: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a4073: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5a4074: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5a4076: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5a4079: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5a407b: 7e17 JLE 0x005a4094
    if(integer::condition("JLE",flags)) goto L005a4094;
  }
  L005a407d: { // 0x5a407d: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x5a4080: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x5a4083: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5a4084: e8f2951c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5a4089: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5a408c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5a408f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5a4090: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5a4092: 7ce9 JL 0x005a407d
    if(integer::condition("JL",flags)) goto L005a407d;
  }
  L005a4094: { // 0x5a4094: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5a4096: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5a4098: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5a409b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5a409c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a409d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001afb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5afb10: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5afb13: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5afb14: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5afb15: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5afb17: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5afb18: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x5afb1c: e8afff0d00 CALL 0x0068fad0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5afb21: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  { // 0x5afb25: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x5afb29: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  { // 0x5afb2d: 8d7e18 LEA EDI,[ESI + 0x18]
    s.di = (s.si+0x00000018u);
  }
  L005afb30: { // 0x5afb30: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x5afb32: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x5afb36: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5afb37: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5afb39: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5afb3c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5afb3f: 741e JZ 0x005afb5f
    if(integer::condition("JZ",flags)) goto L005afb5f;
  }
  { // 0x5afb41: 8b561c MOV EDX,dword ptr [ESI + 0x1c]
    s.dx = m.r32((s.si+0x0000001cu));
  }
  { // 0x5afb44: 8b0c82 MOV ECX,dword ptr [EDX + EAX*0x4]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x5afb47: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5afb49: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5afb4c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5afb4e: 750f JNZ 0x005afb5f
    if(integer::condition("JNZ",flags)) goto L005afb5f;
  }
  { // 0x5afb50: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x5afb52: 760b JBE 0x005afb5f
    if(integer::condition("JBE",flags)) goto L005afb5f;
  }
  { // 0x5afb54: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5afb56: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5afb58: e8d3050000 CALL 0x005b0130
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5afb5d: ebd1 JMP 0x005afb30
    goto L005afb30;
  }
  L005afb5f: { // 0x5afb5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5afb60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5afb61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5afb62: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5afb65: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001b2110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b2110: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b2111: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b2113: 8a4619 MOV AL,byte ptr [ESI + 0x19]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000019u)));
  }
  { // 0x5b2116: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b2118: 7451 JZ 0x005b216b
    if(integer::condition("JZ",flags)) goto L005b216b;
  }
  { // 0x5b211a: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x5b211d: c6461900 MOV byte ptr [ESI + 0x19],0x0
    m.w8((s.si+0x00000019u), 0x00000000u);
  }
  { // 0x5b2121: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5b2123: 7406 JZ 0x005b212b
    if(integer::condition("JZ",flags)) goto L005b212b;
  }
  { // 0x5b2125: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5b2127: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5b2129: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005b212b: { // 0x5b212b: e890ab1700 CALL 0x0072ccc0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b2130: 8a461a MOV AL,byte ptr [ESI + 0x1a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000001au)));
  }
  { // 0x5b2133: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b2135: 7434 JZ 0x005b216b
    if(integer::condition("JZ",flags)) goto L005b216b;
  }
  { // 0x5b2137: 8a4619 MOV AL,byte ptr [ESI + 0x19]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000019u)));
  }
  { // 0x5b213a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b213b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b213d: 740a JZ 0x005b2149
    if(integer::condition("JZ",flags)) goto L005b2149;
  }
  { // 0x5b213f: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  { // 0x5b2142: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5b2145: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  { // 0x5b2147: eb03 JMP 0x005b214c
    goto L005b214c;
  }
  L005b2149: { // 0x5b2149: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  L005b214c: { // 0x5b214c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5b214e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b2150: 7411 JZ 0x005b2163
    if(integer::condition("JZ",flags)) goto L005b2163;
  }
  L005b2152: { // 0x5b2152: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5b2154: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5b2156: 897810 MOV dword ptr [EAX + 0x10],EDI
    m.w32((s.ax+0x00000010u), s.di);
  }
  { // 0x5b2159: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5b215c: 037e14 ADD EDI,dword ptr [ESI + 0x14]
    s.di = integer::add(s.di,m.r32((s.si+0x00000014u)),32,flags);
  }
  { // 0x5b215f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b2161: 75ef JNZ 0x005b2152
    if(integer::condition("JNZ",flags)) goto L005b2152;
  }
  L005b2163: { // 0x5b2163: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x5b2166: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b2167: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5b2168: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L005b216b: { // 0x5b216b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b216c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b2770(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b2770: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b2771: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x5b2775: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b2776: 83ee08 SUB ESI,0x8
    s.si = integer::sub(s.si,0x00000008u,32,flags);
  }
  { // 0x5b2779: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5b277b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b277c: 6888087d00 PUSH 0x7d0888
    f.push(m,0x007d0888u);
  }
  { // 0x5b2781: 89b7c4020000 MOV dword ptr [EDI + 0x2c4],ESI
    m.w32((s.di+0x000002c4u), s.si);
  }
  { // 0x5b2787: e86441e5ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b278c: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x5b278e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5b2791: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b2793: 740e JZ 0x005b27a3
    if(integer::condition("JZ",flags)) goto L005b27a3;
  }
  L005b2795: { // 0x5b2795: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5b2797: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5b2799: 897038 MOV dword ptr [EAX + 0x38],ESI
    m.w32((s.ax+0x00000038u), s.si);
  }
  { // 0x5b279c: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b279f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b27a1: 75f2 JNZ 0x005b2795
    if(integer::condition("JNZ",flags)) goto L005b2795;
  }
  L005b27a3: { // 0x5b27a3: 8a4719 MOV AL,byte ptr [EDI + 0x19]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000019u)));
  }
  { // 0x5b27a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b27a8: 7406 JZ 0x005b27b0
    if(integer::condition("JZ",flags)) goto L005b27b0;
  }
  { // 0x5b27aa: 8b4724 MOV EAX,dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  { // 0x5b27ad: 897038 MOV dword ptr [EAX + 0x38],ESI
    m.w32((s.ax+0x00000038u), s.si);
  }
  L005b27b0: { // 0x5b27b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b27b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b27b2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b4150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b4150: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b4151: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b4153: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b4154: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x5b4157: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x5b415a: 7d34 JGE 0x005b4190
    if(integer::condition("JGE",flags)) goto L005b4190;
  }
  { // 0x5b415c: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5b415e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b4160: 7e18 JLE 0x005b417a
    if(integer::condition("JLE",flags)) goto L005b417a;
  }
  L005b4162: { // 0x5b4162: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x5b4165: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x5b4168: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5b416a: 7406 JZ 0x005b4172
    if(integer::condition("JZ",flags)) goto L005b4172;
  }
  { // 0x5b416c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5b416e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5b4170: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005b4172: { // 0x5b4172: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x5b4175: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5b4176: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5b4178: 7ce8 JL 0x005b4162
    if(integer::condition("JL",flags)) goto L005b4162;
  }
  L005b417a: { // 0x5b417a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5b417d: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x5b4180: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5b4182: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b4185: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5b4187: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b4188: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5b418a: ff92a0000000 CALL dword ptr [EDX + 0xa0]
    const std::uint32_t call_target=m.r32((s.dx+0x000000a0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005b4190: { // 0x5b4190: 8b5618 MOV EDX,dword ptr [ESI + 0x18]
    s.dx = m.r32((s.si+0x00000018u));
  }
  { // 0x5b4193: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5b4195: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x5b4197: 7e1a JLE 0x005b41b3
    if(integer::condition("JLE",flags)) goto L005b41b3;
  }
  { // 0x5b4199: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  { // 0x5b419c: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L005b41a0: { // 0x5b41a0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5b41a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b41a4: 7405 JZ 0x005b41ab
    if(integer::condition("JZ",flags)) goto L005b41ab;
  }
  { // 0x5b41a6: 397808 CMP dword ptr [EAX + 0x8],EDI
    (void)integer::sub(m.r32((s.ax+0x00000008u)),s.di,32,flags);
  }
  { // 0x5b41a9: 740a JZ 0x005b41b5
    if(integer::condition("JZ",flags)) goto L005b41b5;
  }
  L005b41ab: { // 0x5b41ab: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x5b41ac: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x5b41af: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x5b41b1: 7ced JL 0x005b41a0
    if(integer::condition("JL",flags)) goto L005b41a0;
  }
  L005b41b3: { // 0x5b41b3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005b41b5: { // 0x5b41b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b41b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b41b7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b4280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b4280: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b4281: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b4283: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b4284: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5b4286: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x5b4289: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b428b: 7e18 JLE 0x005b42a5
    if(integer::condition("JLE",flags)) goto L005b42a5;
  }
  L005b428d: { // 0x5b428d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x5b4290: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x5b4293: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5b4295: 7406 JZ 0x005b429d
    if(integer::condition("JZ",flags)) goto L005b429d;
  }
  { // 0x5b4297: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5b4299: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5b429b: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005b429d: { // 0x5b429d: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x5b42a0: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5b42a1: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5b42a3: 7ce8 JL 0x005b428d
    if(integer::condition("JL",flags)) goto L005b428d;
  }
  L005b42a5: { // 0x5b42a5: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5b42a8: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x5b42ab: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b42ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b42af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b42b0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b6c30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b6c30: 81eca4000000 SUB ESP,0xa4
    f.sp = integer::sub(f.sp,0x000000a4u,32,flags);
  }
  { // 0x5b6c36: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b6c37: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x5b6c3b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x5b6c3d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5b6c3e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b6c3f: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x5b6c43: e881831b00 CALL 0x0076efc9
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b6c48: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x5b6c4c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5b6c4d: e8d4bb1c00 CALL 0x00782826
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b6c52: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x5b6c56: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5b6c57: e8e9821b00 CALL 0x0076ef45
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5b6c5c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x5b6c5f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b6c61: 7635 JBE 0x005b6c98
    if(integer::condition("JBE",flags)) goto L005b6c98;
  }
  { // 0x5b6c63: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b6c64: 8d7c240c LEA EDI,[ESP + 0xc]
    s.di = (f.sp+0x0000000cu);
  }
  L005b6c68: { // 0x5b6c68: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5b6c6a: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x5b6c6e: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  { // 0x5b6c71: e8faae0600 CALL 0x00621b70
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5b6c76: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x5b6c7a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x5b6c7b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b6c7c: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  { // 0x5b6c7f: e8c1821b00 CALL 0x0076ef45
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5b6c84: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5b6c87: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x5b6c89: 72dd JC 0x005b6c68
    if(integer::condition("JC",flags)) goto L005b6c68;
  }
  { // 0x5b6c8b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5b6c8f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b6c90: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b6c91: 81c4a4000000 ADD ESP,0xa4
    f.sp = integer::add(f.sp,0x000000a4u,32,flags);
  }
  { // 0x5b6c97: c3 RET
    finish(m,s,f,0u); return;
  }
  L005b6c98: { // 0x5b6c98: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5b6c9c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b6c9d: 81c4a4000000 ADD ESP,0xa4
    f.sp = integer::add(f.sp,0x000000a4u,32,flags);
  }
  { // 0x5b6ca3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b6cb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b6cb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b6cb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b6cb3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5b6cb5: ff9094000000 CALL dword ptr [EAX + 0x94]
    const std::uint32_t call_target=m.r32((s.ax+0x00000094u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b6cbb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b6cbd: 7432 JZ 0x005b6cf1
    if(integer::condition("JZ",flags)) goto L005b6cf1;
  }
  { // 0x5b6cbf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005b6cc0: { // 0x5b6cc0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5b6cc2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b6cc4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5b6cc6: ff92a0000000 CALL dword ptr [EDX + 0xa0]
    const std::uint32_t call_target=m.r32((s.dx+0x000000a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b6ccc: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5b6cce: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5b6cd0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b6cd1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5b6cd3: ff90ac000000 CALL dword ptr [EAX + 0xac]
    const std::uint32_t call_target=m.r32((s.ax+0x000000acu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5b6cd9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b6cda: e89c691b00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5b6cdf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5b6ce1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5b6ce4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5b6ce6: ff9294000000 CALL dword ptr [EDX + 0x94]
    const std::uint32_t call_target=m.r32((s.dx+0x00000094u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5b6cec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b6cee: 75d0 JNZ 0x005b6cc0
    if(integer::condition("JNZ",flags)) goto L005b6cc0;
  }
  { // 0x5b6cf0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005b6cf1: { // 0x5b6cf1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5b6cf3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5b6cf5: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5b6cf8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b6cf9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001bd730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5bd730: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5bd731: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5bd732: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5bd733: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5bd735: e8a6c91900 CALL 0x0075a0e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5bd73a: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5bd73c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5bd73e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5bd740: e89bc91900 CALL 0x0075a0e0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5bd745: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5bd747: 7625 JBE 0x005bd76e
    if(integer::condition("JBE",flags)) goto L005bd76e;
  }
  L005bd749: { // 0x5bd749: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5bd74b: e8e0c81900 CALL 0x0075a030
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5bd750: 0fbe0438 MOVSX EAX,byte ptr [EAX + EDI*0x1]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+(s.di * 0x00000001u))),8));
  }
  { // 0x5bd754: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x5bd756: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x5bd758: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5bd75a: c1e918 SHR ECX,0x18
    s.cx = integer::shift(s.cx,0x00000018u,32,flags,integer::Shift::right);
  }
  { // 0x5bd75d: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x5bd760: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  { // 0x5bd762: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5bd764: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5bd765: e876c91900 CALL 0x0075a0e0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5bd76a: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5bd76c: 72db JC 0x005bd749
    if(integer::condition("JC",flags)) goto L005bd749;
  }
  L005bd76e: { // 0x5bd76e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5bd770: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5bd771: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5bd772: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5bd773: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001bd780(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5bd780: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5bd781: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5bd782: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5bd783: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5bd785: e856e61900 CALL 0x0075bde0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5bd78a: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5bd78c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5bd78e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5bd790: e84be61900 CALL 0x0075bde0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5bd795: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5bd797: 7627 JBE 0x005bd7c0
    if(integer::condition("JBE",flags)) goto L005bd7c0;
  }
  L005bd799: { // 0x5bd799: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5bd79b: e890e51900 CALL 0x0075bd30
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5bd7a0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5bd7a2: 668b0c78 MOV CX,word ptr [EAX + EDI*0x2]
    s.cx = with_ax(s.cx, m.r16((s.ax+(s.di * 0x00000002u))));
  }
  { // 0x5bd7a6: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  { // 0x5bd7a8: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  { // 0x5bd7aa: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5bd7ac: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x5bd7ae: c1ea18 SHR EDX,0x18
    s.dx = integer::shift(s.dx,0x00000018u,32,flags,integer::Shift::right);
  }
  { // 0x5bd7b1: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x5bd7b4: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  { // 0x5bd7b6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5bd7b7: e824e61900 CALL 0x0075bde0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5bd7bc: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5bd7be: 72d9 JC 0x005bd799
    if(integer::condition("JC",flags)) goto L005bd799;
  }
  L005bd7c0: { // 0x5bd7c0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5bd7c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5bd7c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5bd7c4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5bd7c5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c2a60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2a60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c2a61: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c2a62: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c2a63: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5c2a65: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5c2a67: bec47da200 MOV ESI,0xa27dc4
    s.si = 0x00a27dc4u;
  }
  L005c2a6c: { // 0x5c2a6c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5c2a6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c2a6f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c2a70: e8d3f11b00 CALL 0x00781c48
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c2a75: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5c2a78: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c2a7a: 7413 JZ 0x005c2a8f
    if(integer::condition("JZ",flags)) goto L005c2a8f;
  }
  { // 0x5c2a7c: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x5c2a7f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5c2a80: 81fee47da200 CMP ESI,0xa27de4
    (void)integer::sub(s.si,0x00a27de4u,32,flags);
  }
  { // 0x5c2a86: 7ce4 JL 0x005c2a6c
    if(integer::condition("JL",flags)) goto L005c2a6c;
  }
  { // 0x5c2a88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2a89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2a8a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5c2a8d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c2a8e: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c2a8f: { // 0x5c2a8f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5c2a91: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2a92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2a93: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c2a94: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c2aa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2aa0: a1b87da200 MOV EAX,[0x00a27db8]
    s.ax = m.r32((0x00a27db8u));
  }
  { // 0x5c2aa5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c2aa7: 7504 JNZ 0x005c2aad
    if(integer::condition("JNZ",flags)) goto L005c2aad;
  }
  { // 0x5c2aa9: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5c2aac: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c2aad: { // 0x5c2aad: a1ac7da200 MOV EAX,[0x00a27dac]
    s.ax = m.r32((0x00a27dacu));
  }
  { // 0x5c2ab2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c2ab3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c2ab4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c2ab5: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  { // 0x5c2ab7: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5c2ab9: bec47da200 MOV ESI,0xa27dc4
    s.si = 0x00a27dc4u;
  }
  L005c2abe: { // 0x5c2abe: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5c2ac0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c2ac1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c2ac2: e881f11b00 CALL 0x00781c48
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c2ac7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5c2aca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c2acc: 7413 JZ 0x005c2ae1
    if(integer::condition("JZ",flags)) goto L005c2ae1;
  }
  { // 0x5c2ace: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x5c2ad1: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5c2ad2: 81fee47da200 CMP ESI,0xa27de4
    (void)integer::sub(s.si,0x00a27de4u,32,flags);
  }
  { // 0x5c2ad8: 7ce4 JL 0x005c2abe
    if(integer::condition("JL",flags)) goto L005c2abe;
  }
  { // 0x5c2ada: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2adb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2adc: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5c2adf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c2ae0: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c2ae1: { // 0x5c2ae1: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5c2ae3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2ae4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2ae5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c2ae6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c2d20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2d20: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x5c2d25: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c2d26: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5c2d27: bd04000000 MOV EBP,0x4
    s.bp = 0x00000004u;
  }
  { // 0x5c2d2c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c2d2d: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x5c2d2f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c2d30: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5c2d32: 7519 JNZ 0x005c2d4d
    if(integer::condition("JNZ",flags)) goto L005c2d4d;
  }
  { // 0x5c2d34: e807e11600 CALL 0x00730e40
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c2d39: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c2d3b: 7415 JZ 0x005c2d52
    if(integer::condition("JZ",flags)) goto L005c2d52;
  }
  { // 0x5c2d3d: e82ee11600 CALL 0x00730e70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5c2d42: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c2d44: 750c JNZ 0x005c2d52
    if(integer::condition("JNZ",flags)) goto L005c2d52;
  }
  { // 0x5c2d46: bd02000000 MOV EBP,0x2
    s.bp = 0x00000002u;
  }
  { // 0x5c2d4b: eb05 JMP 0x005c2d52
    goto L005c2d52;
  }
  L005c2d4d: { // 0x5c2d4d: bd08000000 MOV EBP,0x8
    s.bp = 0x00000008u;
  }
  L005c2d52: { // 0x5c2d52: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5c2d54: bec47da200 MOV ESI,0xa27dc4
    s.si = 0x00a27dc4u;
  }
  L005c2d59: { // 0x5c2d59: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5c2d5b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c2d5c: 8d4828 LEA ECX,[EAX + 0x28]
    s.cx = (s.ax+0x00000028u);
  }
  { // 0x5c2d5f: e87cfdf5ff CALL 0x00522ae0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5c2d64: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c2d66: 7511 JNZ 0x005c2d79
    if(integer::condition("JNZ",flags)) goto L005c2d79;
  }
  { // 0x5c2d68: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x5c2d6b: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5c2d6c: 81fee47da200 CMP ESI,0xa27de4
    (void)integer::sub(s.si,0x00a27de4u,32,flags);
  }
  { // 0x5c2d72: 7ce5 JL 0x005c2d59
    if(integer::condition("JL",flags)) goto L005c2d59;
  }
  { // 0x5c2d74: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2d75: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2d76: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5c2d77: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c2d78: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c2d79: { // 0x5c2d79: a19ca8a500 MOV EAX,[0x00a5a89c]
    s.ax = m.r32((0x00a5a89cu));
  }
  { // 0x5c2d7e: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  { // 0x5c2d80: 7c05 JL 0x005c2d87
    if(integer::condition("JL",flags)) goto L005c2d87;
  }
  { // 0x5c2d82: a1a0a8a500 MOV EAX,[0x00a5a8a0]
    s.ax = m.r32((0x00a5a8a0u));
  }
  L005c2d87: { // 0x5c2d87: 8904bdc47da200 MOV dword ptr [EDI*0x4 + 0xa27dc4],EAX
    m.w32(((s.di * 0x00000004u)+0x00a27dc4u), s.ax);
  }
  { // 0x5c2d8e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2d8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2d90: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5c2d91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c2d92: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c2f10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2f10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c2f11: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c2f12: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5c2f14: 83fffe CMP EDI,-0x2
    (void)integer::sub(s.di,0xfffffffeu,32,flags);
  }
  { // 0x5c2f17: 7462 JZ 0x005c2f7b
    if(integer::condition("JZ",flags)) goto L005c2f7b;
  }
  { // 0x5c2f19: bec47da200 MOV ESI,0xa27dc4
    s.si = 0x00a27dc4u;
  }
  L005c2f1e: { // 0x5c2f1e: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x5c2f20: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5c2f22: 7439 JZ 0x005c2f5d
    if(integer::condition("JZ",flags)) goto L005c2f5d;
  }
  { // 0x5c2f24: 3b0d9ca8a500 CMP ECX,dword ptr [0x00a5a89c]
    (void)integer::sub(s.cx,m.r32((0x00a5a89cu)),32,flags);
  }
  { // 0x5c2f2a: 7431 JZ 0x005c2f5d
    if(integer::condition("JZ",flags)) goto L005c2f5d;
  }
  { // 0x5c2f2c: 3b0da0a8a500 CMP ECX,dword ptr [0x00a5a8a0]
    (void)integer::sub(s.cx,m.r32((0x00a5a8a0u)),32,flags);
  }
  { // 0x5c2f32: 7429 JZ 0x005c2f5d
    if(integer::condition("JZ",flags)) goto L005c2f5d;
  }
  { // 0x5c2f34: 3b0db0a8a500 CMP ECX,dword ptr [0x00a5a8b0]
    (void)integer::sub(s.cx,m.r32((0x00a5a8b0u)),32,flags);
  }
  { // 0x5c2f3a: 7421 JZ 0x005c2f5d
    if(integer::condition("JZ",flags)) goto L005c2f5d;
  }
  { // 0x5c2f3c: 3b0da4a8a500 CMP ECX,dword ptr [0x00a5a8a4]
    (void)integer::sub(s.cx,m.r32((0x00a5a8a4u)),32,flags);
  }
  { // 0x5c2f42: 7419 JZ 0x005c2f5d
    if(integer::condition("JZ",flags)) goto L005c2f5d;
  }
  { // 0x5c2f44: 3b0da8a8a500 CMP ECX,dword ptr [0x00a5a8a8]
    (void)integer::sub(s.cx,m.r32((0x00a5a8a8u)),32,flags);
  }
  { // 0x5c2f4a: 7411 JZ 0x005c2f5d
    if(integer::condition("JZ",flags)) goto L005c2f5d;
  }
  { // 0x5c2f4c: 3b0daca8a500 CMP ECX,dword ptr [0x00a5a8ac]
    (void)integer::sub(s.cx,m.r32((0x00a5a8acu)),32,flags);
  }
  { // 0x5c2f52: 7409 JZ 0x005c2f5d
    if(integer::condition("JZ",flags)) goto L005c2f5d;
  }
  { // 0x5c2f54: e8371f0a00 CALL 0x00664e90
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c2f59: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5c2f5b: 7423 JZ 0x005c2f80
    if(integer::condition("JZ",flags)) goto L005c2f80;
  }
  L005c2f5d: { // 0x5c2f5d: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x5c2f60: 81fee47da200 CMP ESI,0xa27de4
    (void)integer::sub(s.si,0x00a27de4u,32,flags);
  }
  { // 0x5c2f66: 7cb6 JL 0x005c2f1e
    if(integer::condition("JL",flags)) goto L005c2f1e;
  }
  { // 0x5c2f68: b84c56a200 MOV EAX,0xa2564c
    s.ax = 0x00a2564cu;
  }
  L005c2f6d: { // 0x5c2f6d: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  { // 0x5c2f6f: 740f JZ 0x005c2f80
    if(integer::condition("JZ",flags)) goto L005c2f80;
  }
  { // 0x5c2f71: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  { // 0x5c2f74: 3d6c56a200 CMP EAX,0xa2566c
    (void)integer::sub(s.ax,0x00a2566cu,32,flags);
  }
  { // 0x5c2f79: 7cf2 JL 0x005c2f6d
    if(integer::condition("JL",flags)) goto L005c2f6d;
  }
  L005c2f7b: { // 0x5c2f7b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2f7c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5c2f7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2f7f: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c2f80: { // 0x5c2f80: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c2f81: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5c2f83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c2f84: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c8fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c8fb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c8fb1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c8fb2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c8fb3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5c8fb5: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5c8fb7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x5c8fb9: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  { // 0x5c8fbc: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5c8fbf: 8b4128 MOV EAX,dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  { // 0x5c8fc2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c8fc4: 7e25 JLE 0x005c8feb
    if(integer::condition("JLE",flags)) goto L005c8feb;
  }
  L005c8fc6: { // 0x5c8fc6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c8fc7: e8f472ebff CALL 0x004802c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c8fcc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c8fce: 740f JZ 0x005c8fdf
    if(integer::condition("JZ",flags)) goto L005c8fdf;
  }
  { // 0x5c8fd0: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  { // 0x5c8fd3: 8a5102 MOV DL,byte ptr [ECX + 0x2]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000002u)));
  }
  { // 0x5c8fd6: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x5c8fd8: 7505 JNZ 0x005c8fdf
    if(integer::condition("JNZ",flags)) goto L005c8fdf;
  }
  { // 0x5c8fda: f60002 TEST byte ptr [EAX],0x2
    (void)integer::logical((m.r8((s.ax)))&(0x00000002u),8,flags);
  }
  { // 0x5c8fdd: 7412 JZ 0x005c8ff1
    if(integer::condition("JZ",flags)) goto L005c8ff1;
  }
  L005c8fdf: { // 0x5c8fdf: 8b5738 MOV EDX,dword ptr [EDI + 0x38]
    s.dx = m.r32((s.di+0x00000038u));
  }
  { // 0x5c8fe2: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x5c8fe3: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  { // 0x5c8fe6: 3b7128 CMP ESI,dword ptr [ECX + 0x28]
    (void)integer::sub(s.si,m.r32((s.cx+0x00000028u)),32,flags);
  }
  { // 0x5c8fe9: 7cdb JL 0x005c8fc6
    if(integer::condition("JL",flags)) goto L005c8fc6;
  }
  L005c8feb: { // 0x5c8feb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c8fec: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x5c8fee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c8fef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c8ff0: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c8ff1: { // 0x5c8ff1: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    s.ax = m.r32((s.ax+0x00000014u));
  }
  { // 0x5c8ff4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c8ff5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c8ff6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c8ff7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001d29e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d29e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5d29e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d29e2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5d29e4: ba201e5d00 MOV EDX,0x5d1e20
    s.dx = 0x005d1e20u;
  }
  { // 0x5d29e9: b9a3000000 MOV ECX,0xa3
    s.cx = 0x000000a3u;
  }
  { // 0x5d29ee: c7442408ffffffff MOV dword ptr [ESP + 0x8],0xffffffff
    m.w32((f.sp+0x00000008u), 0xffffffffu);
  }
  { // 0x5d29f6: e8d5480200 CALL 0x005f72d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5d29fb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5d29fd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5d29ff: 744d JZ 0x005d2a4e
    if(integer::condition("JZ",flags)) goto L005d2a4e;
  }
  { // 0x5d2a01: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x5d2a05: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d2a06: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x5d2a08: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d2a09: ff1588547800 CALL dword ptr [0x00785488]
    const std::uint32_t call_target=m.r32((0x00785488u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5d2a0f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5d2a11: e86a4a0200 CALL 0x005f7480
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5d2a16: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5d2a1a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2a1c: 7d29 JGE 0x005d2a47
    if(integer::condition("JGE",flags)) goto L005d2a47;
  }
  L005d2a1e: { // 0x5d2a1e: e84d530200 CALL 0x005f7d70
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5d2a23: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x5d2a25: 7508 JNZ 0x005d2a2f
    if(integer::condition("JNZ",flags)) goto L005d2a2f;
  }
  { // 0x5d2a27: c744240402000000 MOV dword ptr [ESP + 0x4],0x2
    m.w32((f.sp+0x00000004u), 0x00000002u);
  }
  L005d2a2f: { // 0x5d2a2f: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x5d2a34: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5d2a36: 7507 JNZ 0x005d2a3f
    if(integer::condition("JNZ",flags)) goto L005d2a3f;
  }
  { // 0x5d2a38: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  { // 0x5d2a3a: e8a13ef4ff CALL 0x005168e0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L005d2a3f: { // 0x5d2a3f: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5d2a43: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2a45: 7cd7 JL 0x005d2a1e
    if(integer::condition("JL",flags)) goto L005d2a1e;
  }
  L005d2a47: { // 0x5d2a47: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5d2a49: e852490200 CALL 0x005f73a0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L005d2a4e: { // 0x5d2a4e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5d2a50: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d2a51: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5d2a52: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001d2a70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d2a70: a160247d00 MOV EAX,[0x007d2460]
    s.ax = m.r32((0x007d2460u));
  }
  { // 0x5d2a75: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5d2a76: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5d2a77: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5d2a7b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d2a7c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5d2a7d: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5d2a7f: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5d2a81: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2a83: be60247d00 MOV ESI,0x7d2460
    s.si = 0x007d2460u;
  }
  { // 0x5d2a88: 741b JZ 0x005d2aa5
    if(integer::condition("JZ",flags)) goto L005d2aa5;
  }
  L005d2a8a: { // 0x5d2a8a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5d2a8c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d2a8d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5d2a8e: e8cdad1900 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5d2a93: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5d2a96: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2a98: 740e JZ 0x005d2aa8
    if(integer::condition("JZ",flags)) goto L005d2aa8;
  }
  { // 0x5d2a9a: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x5d2a9d: 83c60c ADD ESI,0xc
    s.si = integer::add(s.si,0x0000000cu,32,flags);
  }
  { // 0x5d2aa0: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5d2aa1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2aa3: 75e5 JNZ 0x005d2a8a
    if(integer::condition("JNZ",flags)) goto L005d2a8a;
  }
  L005d2aa5: { // 0x5d2aa5: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L005d2aa8: { // 0x5d2aa8: 3b7b40 CMP EDI,dword ptr [EBX + 0x40]
    (void)integer::sub(s.di,m.r32((s.bx+0x00000040u)),32,flags);
  }
  { // 0x5d2aab: 7e03 JLE 0x005d2ab0
    if(integer::condition("JLE",flags)) goto L005d2ab0;
  }
  { // 0x5d2aad: 897b40 MOV dword ptr [EBX + 0x40],EDI
    m.w32((s.bx+0x00000040u), s.di);
  }
  L005d2ab0: { // 0x5d2ab0: a1c0237d00 MOV EAX,[0x007d23c0]
    s.ax = m.r32((0x007d23c0u));
  }
  { // 0x5d2ab5: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5d2ab7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2ab9: bec0237d00 MOV ESI,0x7d23c0
    s.si = 0x007d23c0u;
  }
  { // 0x5d2abe: 741b JZ 0x005d2adb
    if(integer::condition("JZ",flags)) goto L005d2adb;
  }
  L005d2ac0: { // 0x5d2ac0: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x5d2ac2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5d2ac3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5d2ac4: e897ad1900 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5d2ac9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5d2acc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2ace: 740e JZ 0x005d2ade
    if(integer::condition("JZ",flags)) goto L005d2ade;
  }
  { // 0x5d2ad0: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x5d2ad3: 83c60c ADD ESI,0xc
    s.si = integer::add(s.si,0x0000000cu,32,flags);
  }
  { // 0x5d2ad6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5d2ad7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d2ad9: 75e5 JNZ 0x005d2ac0
    if(integer::condition("JNZ",flags)) goto L005d2ac0;
  }
  L005d2adb: { // 0x5d2adb: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L005d2ade: { // 0x5d2ade: 3b7b44 CMP EDI,dword ptr [EBX + 0x44]
    (void)integer::sub(s.di,m.r32((s.bx+0x00000044u)),32,flags);
  }
  { // 0x5d2ae1: 7e03 JLE 0x005d2ae6
    if(integer::condition("JLE",flags)) goto L005d2ae6;
  }
  { // 0x5d2ae3: 897b44 MOV dword ptr [EBX + 0x44],EDI
    m.w32((s.bx+0x00000044u), s.di);
  }
  L005d2ae6: { // 0x5d2ae6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5d2ae7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d2ae8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5d2ae9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5d2aea: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001d4e30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d4e30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d4e31: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5d4e32: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5d4e34: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5d4e36: 742e JZ 0x005d4e66
    if(integer::condition("JZ",flags)) goto L005d4e66;
  }
  { // 0x5d4e38: a128e1a100 MOV EAX,[0x00a1e128]
    s.ax = m.r32((0x00a1e128u));
  }
  { // 0x5d4e3d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x5d4e3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d4e41: 7e23 JLE 0x005d4e66
    if(integer::condition("JLE",flags)) goto L005d4e66;
  }
  L005d4e43: { // 0x5d4e43: a11ce1a100 MOV EAX,[0x00a1e11c]
    s.ax = m.r32((0x00a1e11cu));
  }
  { // 0x5d4e48: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5d4e49: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x5d4e4c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x5d4e4f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5d4e50: e80b8a1900 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5d4e55: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5d4e58: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d4e5a: 7410 JZ 0x005d4e6c
    if(integer::condition("JZ",flags)) goto L005d4e6c;
  }
  { // 0x5d4e5c: a128e1a100 MOV EAX,[0x00a1e128]
    s.ax = m.r32((0x00a1e128u));
  }
  { // 0x5d4e61: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x5d4e62: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x5d4e64: 7cdd JL 0x005d4e43
    if(integer::condition("JL",flags)) goto L005d4e43;
  }
  L005d4e66: { // 0x5d4e66: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5d4e67: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5d4e6a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d4e6b: c3 RET
    finish(m,s,f,0u); return;
  }
  L005d4e6c: { // 0x5d4e6c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5d4e6e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5d4e6f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d4e70: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001d61c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d61c0: a1d8aea500 MOV EAX,[0x00a5aed8]
    s.ax = m.r32((0x00a5aed8u));
  }
  { // 0x5d61c5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d61c7: 7413 JZ 0x005d61dc
    if(integer::condition("JZ",flags)) goto L005d61dc;
  }
  { // 0x5d61c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d61ca: e8ac741900 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5d61cf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5d61d2: c705d8aea50000000000 MOV dword ptr [0x00a5aed8],0x0
    m.w32((0x00a5aed8u), 0x00000000u);
  }
  L005d61dc: { // 0x5d61dc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d61dd: be40ada500 MOV ESI,0xa5ad40
    s.si = 0x00a5ad40u;
  }
  L005d61e2: { // 0x5d61e2: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x5d61e4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5d61e6: 7406 JZ 0x005d61ee
    if(integer::condition("JZ",flags)) goto L005d61ee;
  }
  { // 0x5d61e8: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5d61ea: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5d61ec: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005d61ee: { // 0x5d61ee: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x5d61f4: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x5d61f7: 81fe68aea500 CMP ESI,0xa5ae68
    (void)integer::sub(s.si,0x00a5ae68u,32,flags);
  }
  { // 0x5d61fd: 7ce3 JL 0x005d61e2
    if(integer::condition("JL",flags)) goto L005d61e2;
  }
  { // 0x5d61ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d6200: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001d6960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d6960: a130ada500 MOV EAX,[0x00a5ad30]
    s.ax = m.r32((0x00a5ad30u));
  }
  { // 0x5d6965: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d6966: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  { // 0x5d6969: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5d696b: 7c11 JL 0x005d697e
    if(integer::condition("JL",flags)) goto L005d697e;
  }
  L005d696d: { // 0x5d696d: 8b0d24ada500 MOV ECX,dword ptr [0x00a5ad24]
    s.cx = m.r32((0x00a5ad24u));
  }
  { // 0x5d6973: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x5d6976: e895f8ffff CALL 0x005d6210
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5d697b: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x5d697c: 79ef JNS 0x005d696d
    if(integer::condition("JNS",flags)) goto L005d696d;
  }
  L005d697e: { // 0x5d697e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d697f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f7ff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7ff0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7ff1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5f7ff3: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x5f7ff6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f7ff8: 7410 JZ 0x005f800a
    if(integer::condition("JZ",flags)) goto L005f800a;
  }
  { // 0x5f7ffa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f7ffb: e87b561700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8000: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8003: c7462800000000 MOV dword ptr [ESI + 0x28],0x0
    m.w32((s.si+0x00000028u), 0x00000000u);
  }
  L005f800a: { // 0x5f800a: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x5f800d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5f800f: 7439 JZ 0x005f804a
    if(integer::condition("JZ",flags)) goto L005f804a;
  }
  L005f8011: { // 0x5f8011: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x5f8013: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5f8015: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f8017: 742a JZ 0x005f8043
    if(integer::condition("JZ",flags)) goto L005f8043;
  }
  L005f8019: { // 0x5f8019: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x5f801b: 740a JZ 0x005f8027
    if(integer::condition("JZ",flags)) goto L005f8027;
  }
  { // 0x5f801d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x5f801f: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x5f8021: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f8023: 75f4 JNZ 0x005f8019
    if(integer::condition("JNZ",flags)) goto L005f8019;
  }
  { // 0x5f8025: eb1c JMP 0x005f8043
    goto L005f8043;
  }
  L005f8027: { // 0x5f8027: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f8029: 7418 JZ 0x005f8043
    if(integer::condition("JZ",flags)) goto L005f8043;
  }
  { // 0x5f802b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x5f802d: 7406 JZ 0x005f8035
    if(integer::condition("JZ",flags)) goto L005f8035;
  }
  { // 0x5f802f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x5f8031: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  { // 0x5f8033: eb05 JMP 0x005f803a
    goto L005f803a;
  }
  L005f8035: { // 0x5f8035: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5f8037: 895634 MOV dword ptr [ESI + 0x34],EDX
    m.w32((s.si+0x00000034u), s.dx);
  }
  L005f803a: { // 0x5f803a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f803b: e83b561700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f8040: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005f8043: { // 0x5f8043: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x5f8046: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5f8048: 75c7 JNZ 0x005f8011
    if(integer::condition("JNZ",flags)) goto L005f8011;
  }
  L005f804a: { // 0x5f804a: 8b763c MOV ESI,dword ptr [ESI + 0x3c]
    s.si = m.r32((s.si+0x0000003cu));
  }
  { // 0x5f804d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f804f: 7410 JZ 0x005f8061
    if(integer::condition("JZ",flags)) goto L005f8061;
  }
  { // 0x5f8051: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5f8053: e838331600 CALL 0x0075b390
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f8058: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8059: e81d561700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f805e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005f8061: { // 0x5f8061: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8062: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f8490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8490: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8491: 8b1da0547800 MOV EBX,dword ptr [0x007854a0]
    s.bx = m.r32((0x007854a0u));
  }
  { // 0x5f8497: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8498: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8499: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f849b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5f849d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f849f: 6846010000 PUSH 0x146
    f.push(m,0x00000146u);
  }
  { // 0x5f84a4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f84a5: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f84a7: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f84a9: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x5f84aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f84ac: 7412 JZ 0x005f84c0
    if(integer::condition("JZ",flags)) goto L005f84c0;
  }
  L005f84ae: { // 0x5f84ae: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f84b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f84b1: 6844010000 PUSH 0x144
    f.push(m,0x00000144u);
  }
  { // 0x5f84b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f84b7: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f84b9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5f84bb: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x5f84bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5f84be: 75ee JNZ 0x005f84ae
    if(integer::condition("JNZ",flags)) goto L005f84ae;
  }
  L005f84c0: { // 0x5f84c0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f84c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f84c2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5f84c4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f84c5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f8a50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8a50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8a51: 8b1da0547800 MOV EBX,dword ptr [0x007854a0]
    s.bx = m.r32((0x007854a0u));
  }
  { // 0x5f8a57: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8a58: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8a59: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8a5b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5f8a5d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8a5f: 688b010000 PUSH 0x18b
    f.push(m,0x0000018bu);
  }
  { // 0x5f8a64: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8a65: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8a67: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8a69: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x5f8a6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f8a6c: 7412 JZ 0x005f8a80
    if(integer::condition("JZ",flags)) goto L005f8a80;
  }
  L005f8a6e: { // 0x5f8a6e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8a70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8a71: 6882010000 PUSH 0x182
    f.push(m,0x00000182u);
  }
  { // 0x5f8a76: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8a77: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f8a79: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5f8a7b: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x5f8a7c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5f8a7e: 75ee JNZ 0x005f8a6e
    if(integer::condition("JNZ",flags)) goto L005f8a6e;
  }
  L005f8a80: { // 0x5f8a80: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8a81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8a82: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5f8a84: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8a85: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f9140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f9140: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f9141: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f9142: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5f9144: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5f9146: 833f00 CMP dword ptr [EDI],0x0
    (void)integer::sub(m.r32((s.di)),0x00000000u,32,flags);
  }
  { // 0x5f9149: 7e30 JLE 0x005f917b
    if(integer::condition("JLE",flags)) goto L005f917b;
  }
  { // 0x5f914b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f914c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f914d: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005f914f: { // 0x5f914f: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x5f9152: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  { // 0x5f9154: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x5f9156: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x5f9159: e832221600 CALL 0x0075b390
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f915e: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5f9161: e82a221600 CALL 0x0075b390
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f9166: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x5f9168: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x5f9169: 83c518 ADD EBP,0x18
    s.bp = integer::add(s.bp,0x00000018u,32,flags);
  }
  { // 0x5f916c: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x5f916e: 7cdf JL 0x005f914f
    if(integer::condition("JL",flags)) goto L005f914f;
  }
  { // 0x5f9170: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f9171: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  { // 0x5f9177: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f9178: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f9179: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f917a: c3 RET
    finish(m,s,f,0u); return;
  }
  L005f917b: { // 0x5f917b: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  { // 0x5f9181: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f9182: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f9183: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001fa640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fa640: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fa641: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x5fa644: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fa646: 741f JZ 0x005fa667
    if(integer::condition("JZ",flags)) goto L005fa667;
  }
  { // 0x5fa648: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005fa649: { // 0x5fa649: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  { // 0x5fa64c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fa64e: 7410 JZ 0x005fa660
    if(integer::condition("JZ",flags)) goto L005fa660;
  }
  { // 0x5fa650: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5fa652: e87906ecff CALL 0x004bacd0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fa657: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fa658: e81e301700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5fa65d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005fa660: { // 0x5fa660: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5fa662: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x5fa664: 75e3 JNZ 0x005fa649
    if(integer::condition("JNZ",flags)) goto L005fa649;
  }
  { // 0x5fa666: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005fa667: { // 0x5fa667: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fa668: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001fa940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fa940: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fa941: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x5fa944: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fa946: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fa947: 741b JZ 0x005fa964
    if(integer::condition("JZ",flags)) goto L005fa964;
  }
  { // 0x5fa949: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L005fa94d: { // 0x5fa94d: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x5fa94f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fa950: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fa951: e8fa471700 CALL 0x0076f150
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fa956: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5fa959: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fa95b: 7413 JZ 0x005fa970
    if(integer::condition("JZ",flags)) goto L005fa970;
  }
  { // 0x5fa95d: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  { // 0x5fa960: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fa962: 75e9 JNZ 0x005fa94d
    if(integer::condition("JNZ",flags)) goto L005fa94d;
  }
  L005fa964: { // 0x5fa964: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5fa966: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fa967: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fa969: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5fa96c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fa96d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L005fa970: { // 0x5fa970: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fa972: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5fa974: 740b JZ 0x005fa981
    if(integer::condition("JZ",flags)) goto L005fa981;
  }
  { // 0x5fa976: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x5fa979: 8a11 MOV DL,byte ptr [ECX]
    s.dx = with_al(s.dx, m.r8((s.cx)));
  }
  { // 0x5fa97b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5fa97f: 8811 MOV byte ptr [ECX],DL
    m.w8((s.cx), (s.dx & 0xffu));
  }
  L005fa981: { // 0x5fa981: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fa983: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fa984: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fa985: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5fa988: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001faaf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5faaf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5faaf1: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x5faaf4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5faaf6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5faaf7: 741b JZ 0x005fab14
    if(integer::condition("JZ",flags)) goto L005fab14;
  }
  { // 0x5faaf9: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L005faafd: { // 0x5faafd: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x5faaff: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fab00: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fab01: e84a461700 CALL 0x0076f150
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fab06: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5fab09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fab0b: 7413 JZ 0x005fab20
    if(integer::condition("JZ",flags)) goto L005fab20;
  }
  { // 0x5fab0d: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  { // 0x5fab10: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fab12: 75e9 JNZ 0x005faafd
    if(integer::condition("JNZ",flags)) goto L005faafd;
  }
  L005fab14: { // 0x5fab14: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5fab16: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fab17: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fab19: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5fab1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fab1d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L005fab20: { // 0x5fab20: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fab22: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5fab24: 740b JZ 0x005fab31
    if(integer::condition("JZ",flags)) goto L005fab31;
  }
  { // 0x5fab26: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x5fab29: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5fab2b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5fab2f: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L005fab31: { // 0x5fab31: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fab33: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fab34: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fab35: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5fab38: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001facb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5facb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5facb1: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5facb5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5facb6: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5facba: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5facbb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5facbc: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x5facbe: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L005facc0: { // 0x5facc0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5facc2: 25ff000080 AND EAX,0x800000ff
    s.ax = integer::logical((s.ax)&(0x800000ffu),32,flags);
  }
  { // 0x5facc7: 7907 JNS 0x005facd0
    if(integer::condition("JNS",flags)) goto L005facd0;
  }
  { // 0x5facc9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x5facca: 0d00ffffff OR EAX,0xffffff00
    s.ax = integer::logical((s.ax)|(0xffffff00u),32,flags);
  }
  { // 0x5faccf: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005facd0: { // 0x5facd0: 8d0c43 LEA ECX,[EBX + EAX*0x2]
    s.cx = (s.bx+(s.ax * 0x00000002u));
  }
  { // 0x5facd3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x5facd5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5facd7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5facd8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5facd9: e832960300 CALL 0x00634310
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5facde: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x5facdf: 83c703 ADD EDI,0x3
    s.di = integer::add(s.di,0x00000003u,32,flags);
  }
  { // 0x5face2: 81fe00010000 CMP ESI,0x100
    (void)integer::sub(s.si,0x00000100u,32,flags);
  }
  { // 0x5face8: 7cd6 JL 0x005facc0
    if(integer::condition("JL",flags)) goto L005facc0;
  }
  { // 0x5facea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5faceb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5facec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5faced: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5facee: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001fad90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fad90: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5fad91: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fad92: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5fad93: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  { // 0x5fad97: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fad98: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5fad9a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fad9b: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  { // 0x5fad9f: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  { // 0x5fada2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L005fada4: { // 0x5fada4: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5fada6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x5fada8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5fada9: 83c703 ADD EDI,0x3
    s.di = integer::add(s.di,0x00000003u,32,flags);
  }
  { // 0x5fadac: e8ef950300 CALL 0x006343a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fadb1: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  { // 0x5fadb4: 7404 JZ 0x005fadba
    if(integer::condition("JZ",flags)) goto L005fadba;
  }
  { // 0x5fadb6: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5fadb8: 7d06 JGE 0x005fadc0
    if(integer::condition("JGE",flags)) goto L005fadc0;
  }
  L005fadba: { // 0x5fadba: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5fadbc: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005fadc0: { // 0x5fadc0: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x5fadc1: 81fb00010000 CMP EBX,0x100
    (void)integer::sub(s.bx,0x00000100u,32,flags);
  }
  { // 0x5fadc7: 7cdb JL 0x005fada4
    if(integer::condition("JL",flags)) goto L005fada4;
  }
  { // 0x5fadc9: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x5fadcd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fadce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fadcf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fadd0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fadd1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5fadd2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001faf00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5faf00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5faf01: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5faf03: 8b8300010000 MOV EAX,dword ptr [EBX + 0x100]
    s.ax = m.r32((s.bx+0x00000100u));
  }
  { // 0x5faf09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5faf0b: 744e JZ 0x005faf5b
    if(integer::condition("JZ",flags)) goto L005faf5b;
  }
  { // 0x5faf0d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5faf0e: 8b6810 MOV EBP,dword ptr [EAX + 0x10]
    s.bp = m.r32((s.ax+0x00000010u));
  }
  { // 0x5faf11: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5faf12: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5faf14: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x5faf16: 7e27 JLE 0x005faf3f
    if(integer::condition("JLE",flags)) goto L005faf3f;
  }
  { // 0x5faf18: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005faf19: { // 0x5faf19: 8b8300010000 MOV EAX,dword ptr [EBX + 0x100]
    s.ax = m.r32((s.bx+0x00000100u));
  }
  { // 0x5faf1f: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5faf22: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  { // 0x5faf25: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5faf27: 7410 JZ 0x005faf39
    if(integer::condition("JZ",flags)) goto L005faf39;
  }
  { // 0x5faf29: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5faf2b: e830fc0500 CALL 0x0065ab60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5faf30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5faf31: e845271700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5faf36: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005faf39: { // 0x5faf39: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5faf3a: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  { // 0x5faf3c: 7cdb JL 0x005faf19
    if(integer::condition("JL",flags)) goto L005faf19;
  }
  { // 0x5faf3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005faf3f: { // 0x5faf3f: 8b8b00010000 MOV ECX,dword ptr [EBX + 0x100]
    s.cx = m.r32((s.bx+0x00000100u));
  }
  { // 0x5faf45: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5faf46: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5faf48: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5faf49: 7406 JZ 0x005faf51
    if(integer::condition("JZ",flags)) goto L005faf51;
  }
  { // 0x5faf4b: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5faf4d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5faf4f: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005faf51: { // 0x5faf51: c7830001000000000000 MOV dword ptr [EBX + 0x100],0x0
    m.w32((s.bx+0x00000100u), 0x00000000u);
  }
  L005faf5b: { // 0x5faf5b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5faf5c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001fcca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fcca0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fcca1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5fcca2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fcca3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5fcca5: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5fcca9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fccaa: ff5604 CALL dword ptr [ESI + 0x4]
    const std::uint32_t call_target=m.r32((s.si+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fccad: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x5fccae: f77e08 IDIV dword ptr [ESI + 0x8]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.si+0x00000008u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x5fccb1: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x5fccb3: 8d0452 LEA EAX,[EDX + EDX*0x2]
    s.ax = (s.dx+(s.dx * 0x00000002u));
  }
  { // 0x5fccb6: 8b7cc110 MOV EDI,dword ptr [ECX + EAX*0x8 + 0x10]
    s.di = m.r32((s.cx+(s.ax * 0x00000008u)+0x00000010u));
  }
  { // 0x5fccba: 8d2cc1 LEA EBP,[ECX + EAX*0x8]
    s.bp = (s.cx+(s.ax * 0x00000008u));
  }
  { // 0x5fccbd: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x5fccbe: 782a JS 0x005fccea
    if(integer::condition("JS",flags)) goto L005fccea;
  }
  { // 0x5fccc0: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  { // 0x5fccc2: c1e306 SHL EBX,0x6
    s.bx = integer::shift(s.bx,0x00000006u,32,flags,integer::Shift::left);
  }
  { // 0x5fccc5: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  { // 0x5fccc7: c1e302 SHL EBX,0x2
    s.bx = integer::shift(s.bx,0x00000002u,32,flags,integer::Shift::left);
  }
  L005fccca: { // 0x5fccca: 8b7504 MOV ESI,dword ptr [EBP + 0x4]
    s.si = m.r32((s.bp+0x00000004u));
  }
  { // 0x5fcccd: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5fccd1: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  { // 0x5fccd3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5fccd4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5fccd6: e8a53beeff CALL 0x004e0880
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5fccdb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fccdd: 7514 JNZ 0x005fccf3
    if(integer::condition("JNZ",flags)) goto L005fccf3;
  }
  { // 0x5fccdf: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x5fcce0: 81eb04010000 SUB EBX,0x104
    s.bx = integer::sub(s.bx,0x00000104u,32,flags);
  }
  { // 0x5fcce6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5fcce8: 7de0 JGE 0x005fccca
    if(integer::condition("JGE",flags)) goto L005fccca;
  }
  L005fccea: { // 0x5fccea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fcceb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fccec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fcced: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5fccef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fccf0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fccf3: { // 0x5fccf3: 8d8600010000 LEA EAX,[ESI + 0x100]
    s.ax = (s.si+0x00000100u);
  }
  { // 0x5fccf9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fccfa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fccfb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fccfc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fccfd: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fcd00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fcd00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fcd01: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5fcd02: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fcd03: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x5fcd07: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fcd08: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5fcd0a: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000008u)));
  }
  { // 0x5fcd0d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fcd0f: 755d JNZ 0x005fcd6e
    if(integer::condition("JNZ",flags)) goto L005fcd6e;
  }
  { // 0x5fcd11: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5fcd13: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  { // 0x5fcd16: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5fcd18: 7d50 JGE 0x005fcd6a
    if(integer::condition("JGE",flags)) goto L005fcd6a;
  }
  L005fcd1a: { // 0x5fcd1a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5fcd1c: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x5fcd1e: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x5fcd21: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x5fcd24: 8d3cca LEA EDI,[EDX + ECX*0x8]
    s.di = (s.dx+(s.cx * 0x00000008u));
  }
  { // 0x5fcd27: 8b4cca10 MOV ECX,dword ptr [EDX + ECX*0x8 + 0x10]
    s.cx = m.r32((s.dx+(s.cx * 0x00000008u)+0x00000010u));
  }
  { // 0x5fcd2b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5fcd2d: 7d26 JGE 0x005fcd55
    if(integer::condition("JGE",flags)) goto L005fcd55;
  }
  L005fcd2f: { // 0x5fcd2f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x5fcd32: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5fcd34: c1e106 SHL ECX,0x6
    s.cx = integer::shift(s.cx,0x00000006u,32,flags,integer::Shift::left);
  }
  { // 0x5fcd37: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x5fcd39: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5fcd3a: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x5fcd3d: 8d2c8a LEA EBP,[EDX + ECX*0x4]
    s.bp = (s.dx+(s.cx * 0x00000004u));
  }
  { // 0x5fcd40: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x5fcd42: e8f93aeeff CALL 0x004e0840
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fcd47: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fcd49: 742c JZ 0x005fcd77
    if(integer::condition("JZ",flags)) goto L005fcd77;
  }
  { // 0x5fcd4b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x5fcd4e: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  { // 0x5fcd51: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5fcd53: 7cda JL 0x005fcd2f
    if(integer::condition("JL",flags)) goto L005fcd2f;
  }
  L005fcd55: { // 0x5fcd55: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5fcd57: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x5fcd5e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x5fcd5f: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  { // 0x5fcd61: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  { // 0x5fcd64: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x5fcd66: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5fcd68: 7cb0 JL 0x005fcd1a
    if(integer::condition("JL",flags)) goto L005fcd1a;
  }
  L005fcd6a: { // 0x5fcd6a: c6460801 MOV byte ptr [ESI + 0x8],0x1
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L005fcd6e: { // 0x5fcd6e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fcd6f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fcd70: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fcd71: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5fcd73: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fcd74: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fcd77: { // 0x5fcd77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fcd78: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x5fcd7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fcd7b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fcd7c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fcd7d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fcfa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fcfa0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fcfa1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5fcfa2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fcfa3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5fcfa5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fcfa6: 8a460c MOV AL,byte ptr [ESI + 0xc]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000cu)));
  }
  { // 0x5fcfa9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fcfab: 7509 JNZ 0x005fcfb6
    if(integer::condition("JNZ",flags)) goto L005fcfb6;
  }
  { // 0x5fcfad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fcfae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fcfaf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fcfb0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5fcfb2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fcfb3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fcfb6: { // 0x5fcfb6: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5fcfb9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5fcfbb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fcfbd: 7e21 JLE 0x005fcfe0
    if(integer::condition("JLE",flags)) goto L005fcfe0;
  }
  { // 0x5fcfbf: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x5fcfc3: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005fcfc5: { // 0x5fcfc5: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x5fcfc8: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x5fcfca: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  { // 0x5fcfcc: e80f17f0ff CALL 0x004fe6e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fcfd1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fcfd3: 7515 JNZ 0x005fcfea
    if(integer::condition("JNZ",flags)) goto L005fcfea;
  }
  { // 0x5fcfd5: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5fcfd8: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5fcfd9: 83c303 ADD EBX,0x3
    s.bx = integer::add(s.bx,0x00000003u,32,flags);
  }
  { // 0x5fcfdc: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5fcfde: 7ce5 JL 0x005fcfc5
    if(integer::condition("JL",flags)) goto L005fcfc5;
  }
  L005fcfe0: { // 0x5fcfe0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fcfe1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fcfe2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fcfe3: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5fcfe6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fcfe7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fcfea: { // 0x5fcfea: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5fcfec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fcfed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fcfee: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fcfef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fcff0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fd130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fd130: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fd131: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5fd132: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fd133: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5fd135: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fd136: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5fd138: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5fd13b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fd13d: 7e21 JLE 0x005fd160
    if(integer::condition("JLE",flags)) goto L005fd160;
  }
  { // 0x5fd13f: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x5fd143: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005fd145: { // 0x5fd145: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x5fd148: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x5fd14a: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  { // 0x5fd14c: e88f15f0ff CALL 0x004fe6e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fd151: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fd153: 7515 JNZ 0x005fd16a
    if(integer::condition("JNZ",flags)) goto L005fd16a;
  }
  { // 0x5fd155: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5fd158: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5fd159: 83c303 ADD EBX,0x3
    s.bx = integer::add(s.bx,0x00000003u,32,flags);
  }
  { // 0x5fd15c: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5fd15e: 7ce5 JL 0x005fd145
    if(integer::condition("JL",flags)) goto L005fd145;
  }
  L005fd160: { // 0x5fd160: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd161: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd162: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fd163: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5fd166: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fd167: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fd16a: { // 0x5fd16a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5fd16c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd16d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd16e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fd16f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fd170: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fd600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fd600: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fd601: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5fd602: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fd603: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5fd605: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fd606: 8a460c MOV AL,byte ptr [ESI + 0xc]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000cu)));
  }
  { // 0x5fd609: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fd60b: 7509 JNZ 0x005fd616
    if(integer::condition("JNZ",flags)) goto L005fd616;
  }
  { // 0x5fd60d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd60e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd60f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fd610: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5fd612: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fd613: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fd616: { // 0x5fd616: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5fd619: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5fd61b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fd61d: 7e24 JLE 0x005fd643
    if(integer::condition("JLE",flags)) goto L005fd643;
  }
  { // 0x5fd61f: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x5fd623: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005fd625: { // 0x5fd625: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x5fd628: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x5fd62a: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  { // 0x5fd62c: e8ef32eeff CALL 0x004e0920
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fd631: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fd633: 7518 JNZ 0x005fd64d
    if(integer::condition("JNZ",flags)) goto L005fd64d;
  }
  { // 0x5fd635: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5fd638: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x5fd639: 81c704010000 ADD EDI,0x104
    s.di = integer::add(s.di,0x00000104u,32,flags);
  }
  { // 0x5fd63f: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x5fd641: 7ce2 JL 0x005fd625
    if(integer::condition("JL",flags)) goto L005fd625;
  }
  L005fd643: { // 0x5fd643: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd644: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd645: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fd646: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5fd649: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fd64a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fd64d: { // 0x5fd64d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd64e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd64f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x5fd651: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fd652: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fd653: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fd910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fd910: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fd911: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5fd912: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fd913: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5fd915: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5fd917: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fd918: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5fd91b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fd91d: 7e24 JLE 0x005fd943
    if(integer::condition("JLE",flags)) goto L005fd943;
  }
  { // 0x5fd91f: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x5fd923: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005fd925: { // 0x5fd925: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x5fd928: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x5fd92a: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  { // 0x5fd92c: e8ef2feeff CALL 0x004e0920
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fd931: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fd933: 7518 JNZ 0x005fd94d
    if(integer::condition("JNZ",flags)) goto L005fd94d;
  }
  { // 0x5fd935: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5fd938: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x5fd939: 81c704010000 ADD EDI,0x104
    s.di = integer::add(s.di,0x00000104u,32,flags);
  }
  { // 0x5fd93f: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x5fd941: 7ce2 JL 0x005fd925
    if(integer::condition("JL",flags)) goto L005fd925;
  }
  L005fd943: { // 0x5fd943: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd944: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd945: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fd946: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5fd949: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fd94a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fd94d: { // 0x5fd94d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd94e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd94f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x5fd951: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5fd952: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fd953: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00203040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x603040: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x603041: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x603042: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x603044: 8b9fb8000000 MOV EBX,dword ptr [EDI + 0xb8]
    s.bx = m.r32((s.di+0x000000b8u));
  }
  { // 0x60304a: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x60304b: 7865 JS 0x006030b2
    if(integer::condition("JS",flags)) goto L006030b2;
  }
  { // 0x60304d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060304e: { // 0x60304e: 3b9fb8000000 CMP EBX,dword ptr [EDI + 0xb8]
    (void)integer::sub(s.bx,m.r32((s.di+0x000000b8u)),32,flags);
  }
  { // 0x603054: 7d58 JGE 0x006030ae
    if(integer::condition("JGE",flags)) goto L006030ae;
  }
  { // 0x603056: 8b87ac000000 MOV EAX,dword ptr [EDI + 0xac]
    s.ax = m.r32((s.di+0x000000acu));
  }
  { // 0x60305c: 8d349d00000000 LEA ESI,[EBX*0x4 + 0x0]
    s.si = ((s.bx * 0x00000004u)+0x00000000u);
  }
  { // 0x603063: 8b0c30 MOV ECX,dword ptr [EAX + ESI*0x1]
    s.cx = m.r32((s.ax+(s.si * 0x00000001u)));
  }
  { // 0x603066: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x603068: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    const std::uint32_t call_target=m.r32((s.dx+0x000000f0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60306e: 8b87ac000000 MOV EAX,dword ptr [EDI + 0xac]
    s.ax = m.r32((s.di+0x000000acu));
  }
  { // 0x603074: 8b97a8000000 MOV EDX,dword ptr [EDI + 0xa8]
    s.dx = m.r32((s.di+0x000000a8u));
  }
  { // 0x60307a: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x60307c: 8db7a8000000 LEA ESI,[EDI + 0xa8]
    s.si = (s.di+0x000000a8u);
  }
  { // 0x603082: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x603083: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x603085: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x603088: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x60308b: 7421 JZ 0x006030ae
    if(integer::condition("JZ",flags)) goto L006030ae;
  }
  { // 0x60308d: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x603090: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x603092: 7d1a JGE 0x006030ae
    if(integer::condition("JGE",flags)) goto L006030ae;
  }
  { // 0x603094: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x603095: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x603097: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x60309a: 7d12 JGE 0x006030ae
    if(integer::condition("JGE",flags)) goto L006030ae;
  }
  L0060309c: { // 0x60309c: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x60309f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x6030a0: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x6030a3: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x6030a7: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x6030aa: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6030ac: 7cee JL 0x0060309c
    if(integer::condition("JL",flags)) goto L0060309c;
  }
  L006030ae: { // 0x6030ae: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x6030af: 799d JNS 0x0060304e
    if(integer::condition("JNS",flags)) goto L0060304e;
  }
  { // 0x6030b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006030b2: { // 0x6030b2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6030b3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6030b4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00205550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x605550: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x605551: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x605553: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x605555: bad0556000 MOV EDX,0x6055d0
    s.dx = 0x006055d0u;
  }
  { // 0x60555a: b9ee000000 MOV ECX,0xee
    s.cx = 0x000000eeu;
  }
  { // 0x60555f: e86c1dffff CALL 0x005f72d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x605564: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x605566: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x605568: 7458 JZ 0x006055c2
    if(integer::condition("JZ",flags)) goto L006055c2;
  }
  { // 0x60556a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60556b: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x60556d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x60556e: c6460800 MOV byte ptr [ESI + 0x8],0x0
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x605572: c74604ffffffff MOV dword ptr [ESI + 0x4],0xffffffff
    m.w32((s.si+0x00000004u), 0xffffffffu);
  }
  { // 0x605579: ff1588547800 CALL dword ptr [0x00785488]
    const std::uint32_t call_target=m.r32((0x00785488u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x60557f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x605581: e89a040000 CALL 0x00605a20
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x605586: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x605588: e8f31effff CALL 0x005f7480
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x60558d: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x605590: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x605592: 7d17 JGE 0x006055ab
    if(integer::condition("JGE",flags)) goto L006055ab;
  }
  L00605594: { // 0x605594: e8d727ffff CALL 0x005f7d70
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x605599: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x60559b: 740e JZ 0x006055ab
    if(integer::condition("JZ",flags)) goto L006055ab;
  }
  { // 0x60559d: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  { // 0x60559f: e83c13f1ff CALL 0x005168e0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x6055a4: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6055a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6055a9: 7ce9 JL 0x00605594
    if(integer::condition("JL",flags)) goto L00605594;
  }
  L006055ab: { // 0x6055ab: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x6055ad: e8ee1dffff CALL 0x005f73a0
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x6055b2: 807e0801 CMP byte ptr [ESI + 0x8],0x1
    (void)integer::sub(m.r8((s.si+0x00000008u)),0x00000001u,8,flags);
  }
  { // 0x6055b6: 750a JNZ 0x006055c2
    if(integer::condition("JNZ",flags)) goto L006055c2;
  }
  { // 0x6055b8: b9c855a200 MOV ECX,0xa255c8
    s.cx = 0x00a255c8u;
  }
  { // 0x6055bd: e8ae170600 CALL 0x00666d70
    const std::uint32_t call_target=f.boundaries[7u].target;
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  L006055c2: { // 0x6055c2: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6055c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6055c6: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6055c9: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x6055cc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002060a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6060a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6060a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6060a2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6060a6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6060a8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6060aa: 7507 JNZ 0x006060b3
    if(integer::condition("JNZ",flags)) goto L006060b3;
  }
  { // 0x6060ac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6060ad: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6060af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6060b0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006060b3: { // 0x6060b3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6060b5: ba20616000 MOV EDX,0x606120
    s.dx = 0x00606120u;
  }
  { // 0x6060ba: b9ef000000 MOV ECX,0xef
    s.cx = 0x000000efu;
  }
  { // 0x6060bf: e80c12ffff CALL 0x005f72d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6060c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6060c6: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x6060c8: 7447 JZ 0x00606111
    if(integer::condition("JZ",flags)) goto L00606111;
  }
  { // 0x6060ca: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6060cb: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x6060cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6060ce: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  { // 0x6060d1: c74604ffffffff MOV dword ptr [ESI + 0x4],0xffffffff
    m.w32((s.si+0x00000004u), 0xffffffffu);
  }
  { // 0x6060d8: ff1588547800 CALL dword ptr [0x00785488]
    const std::uint32_t call_target=m.r32((0x00785488u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6060de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6060e0: e8fb030000 CALL 0x006064e0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6060e5: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x6060e7: e89413ffff CALL 0x005f7480
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6060ec: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6060ef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6060f1: 7d17 JGE 0x0060610a
    if(integer::condition("JGE",flags)) goto L0060610a;
  }
  L006060f3: { // 0x6060f3: e8781cffff CALL 0x005f7d70
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6060f8: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x6060fa: 740e JZ 0x0060610a
    if(integer::condition("JZ",flags)) goto L0060610a;
  }
  { // 0x6060fc: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  { // 0x6060fe: e8dd07f1ff CALL 0x005168e0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x606103: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x606106: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x606108: 7ce9 JL 0x006060f3
    if(integer::condition("JL",flags)) goto L006060f3;
  }
  L0060610a: { // 0x60610a: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x60610c: e88f12ffff CALL 0x005f73a0
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  L00606111: { // 0x606111: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x606114: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x606115: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x606118: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x606119: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x60611c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00209310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x609310: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x609311: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x609312: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x609313: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x609315: e8a6070000 CALL 0x00609ac0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60931a: 8b5e10 MOV EBX,dword ptr [ESI + 0x10]
    s.bx = m.r32((s.si+0x00000010u));
  }
  { // 0x60931d: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x60931f: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x609321: 7e13 JLE 0x00609336
    if(integer::condition("JLE",flags)) goto L00609336;
  }
  L00609323: { // 0x609323: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x609326: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x609329: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x60932a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x60932c: e87f040000 CALL 0x006097b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x609331: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x609332: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x609334: 7ced JL 0x00609323
    if(integer::condition("JL",flags)) goto L00609323;
  }
  L00609336: { // 0x609336: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x609338: e813000000 CALL 0x00609350
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x60933d: c6461c00 MOV byte ptr [ESI + 0x1c],0x0
    m.w8((s.si+0x0000001cu), 0x00000000u);
  }
  { // 0x609341: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x609342: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x609343: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x609344: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00209ac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x609ac0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x609ac1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x609ac2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x609ac3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x609ac5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x609ac6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x609ac8: 8b6e30 MOV EBP,dword ptr [ESI + 0x30]
    s.bp = m.r32((s.si+0x00000030u));
  }
  { // 0x609acb: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x609acd: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  { // 0x609acf: 7e14 JLE 0x00609ae5
    if(integer::condition("JLE",flags)) goto L00609ae5;
  }
  L00609ad1: { // 0x609ad1: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x609ad4: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x609ad7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x609ad8: e89e3b1600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x609add: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x609ae0: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x609ae1: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  { // 0x609ae3: 7cec JL 0x00609ad1
    if(integer::condition("JL",flags)) goto L00609ad1;
  }
  L00609ae5: { // 0x609ae5: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  { // 0x609ae8: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  { // 0x609aeb: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x609aee: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  { // 0x609af1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x609af3: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  { // 0x609af5: 7e26 JLE 0x00609b1d
    if(integer::condition("JLE",flags)) goto L00609b1d;
  }
  { // 0x609af7: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L00609afa: { // 0x609afa: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x609afd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x609afe: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x609b00: 8b4c81fc MOV ECX,dword ptr [ECX + EAX*0x4 + -0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)-0x00000004u));
  }
  { // 0x609b04: 897908 MOV dword ptr [ECX + 0x8],EDI
    m.w32((s.cx+0x00000008u), s.di);
  }
  { // 0x609b07: 88590c MOV byte ptr [ECX + 0xc],BL
    m.w8((s.cx+0x0000000cu), (s.bx & 0xffu));
  }
  { // 0x609b0a: 7cee JL 0x00609afa
    if(integer::condition("JL",flags)) goto L00609afa;
  }
  { // 0x609b0c: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  { // 0x609b12: 89beb0000000 MOV dword ptr [ESI + 0xb0],EDI
    m.w32((s.si+0x000000b0u), s.di);
  }
  { // 0x609b18: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x609b19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x609b1a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x609b1b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x609b1c: c3 RET
    finish(m,s,f,0u); return;
  }
  L00609b1d: { // 0x609b1d: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  { // 0x609b23: c786b0000000ffffffff MOV dword ptr [ESI + 0xb0],0xffffffff
    m.w32((s.si+0x000000b0u), 0xffffffffu);
  }
  { // 0x609b2d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x609b2e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x609b2f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x609b30: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x609b31: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0020bed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60bed0: a1b8e1a500 MOV EAX,[0x00a5e1b8]
    s.ax = m.r32((0x00a5e1b8u));
  }
  { // 0x60bed5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60bed6: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  { // 0x60bed9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x60bedb: 7c4d JL 0x0060bf2a
    if(integer::condition("JL",flags)) goto L0060bf2a;
  }
  { // 0x60bedd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060bede: { // 0x60bede: 8b0dace1a500 MOV ECX,dword ptr [0x00a5e1ac]
    s.cx = m.r32((0x00a5e1acu));
  }
  { // 0x60bee4: 8b3cb1 MOV EDI,dword ptr [ECX + ESI*0x4]
    s.di = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x60bee7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x60bee9: e822a00100 CALL 0x00625f10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60beee: 8b0db8e1a500 MOV ECX,dword ptr [0x00a5e1b8]
    s.cx = m.r32((0x00a5e1b8u));
  }
  { // 0x60bef4: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x60bef6: 7d25 JGE 0x0060bf1d
    if(integer::condition("JGE",flags)) goto L0060bf1d;
  }
  { // 0x60bef8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x60bef9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x60befb: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x60befd: 890db8e1a500 MOV dword ptr [0x00a5e1b8],ECX
    m.w32((0x00a5e1b8u), s.cx);
  }
  { // 0x60bf03: 7d18 JGE 0x0060bf1d
    if(integer::condition("JGE",flags)) goto L0060bf1d;
  }
  L0060bf05: { // 0x60bf05: 8b0dace1a500 MOV ECX,dword ptr [0x00a5e1ac]
    s.cx = m.r32((0x00a5e1acu));
  }
  { // 0x60bf0b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x60bf0c: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x60bf0f: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x60bf13: 8b0db8e1a500 MOV ECX,dword ptr [0x00a5e1b8]
    s.cx = m.r32((0x00a5e1b8u));
  }
  { // 0x60bf19: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x60bf1b: 7ce8 JL 0x0060bf05
    if(integer::condition("JL",flags)) goto L0060bf05;
  }
  L0060bf1d: { // 0x60bf1d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x60bf1e: e858171600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x60bf23: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x60bf26: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x60bf27: 79b5 JNS 0x0060bede
    if(integer::condition("JNS",flags)) goto L0060bede;
  }
  { // 0x60bf29: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060bf2a: { // 0x60bf2a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60bf2b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0020c1c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60c1c0: a0fee2a500 MOV AL,[0x00a5e2fe]
    s.ax = with_al(s.ax, m.r8((0x00a5e2feu)));
  }
  { // 0x60c1c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60c1c7: 755b JNZ 0x0060c224
    if(integer::condition("JNZ",flags)) goto L0060c224;
  }
  { // 0x60c1c9: a0fce2a500 MOV AL,[0x00a5e2fc]
    s.ax = with_al(s.ax, m.r8((0x00a5e2fcu)));
  }
  { // 0x60c1ce: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x60c1cf: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60c1d0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x60c1d1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60c1d3: c605fee2a50001 MOV byte ptr [0x00a5e2fe],0x1
    m.w8((0x00a5e2feu), 0x00000001u);
  }
  { // 0x60c1da: 743e JZ 0x0060c21a
    if(integer::condition("JZ",flags)) goto L0060c21a;
  }
  { // 0x60c1dc: e8bfa70b00 CALL 0x006c69a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60c1e1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x60c1e3: 7435 JZ 0x0060c21a
    if(integer::condition("JZ",flags)) goto L0060c21a;
  }
  { // 0x60c1e5: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  { // 0x60c1e8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x60c1e9: 782f JS 0x0060c21a
    if(integer::condition("JS",flags)) goto L0060c21a;
  }
  { // 0x60c1eb: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  { // 0x60c1ee: 8b3c88 MOV EDI,dword ptr [EAX + ECX*0x4]
    s.di = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x60c1f1: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x60c1f3: 7425 JZ 0x0060c21a
    if(integer::condition("JZ",flags)) goto L0060c21a;
  }
  { // 0x60c1f5: 8b5f10 MOV EBX,dword ptr [EDI + 0x10]
    s.bx = m.r32((s.di+0x00000010u));
  }
  { // 0x60c1f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x60c1fa: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x60c1fc: 7e1c JLE 0x0060c21a
    if(integer::condition("JLE",flags)) goto L0060c21a;
  }
  L0060c1fe: { // 0x60c1fe: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x60c201: 8b14b1 MOV EDX,dword ptr [ECX + ESI*0x4]
    s.dx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x60c204: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  { // 0x60c206: 8a4177 MOV AL,byte ptr [ECX + 0x77]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000077u)));
  }
  { // 0x60c209: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60c20b: 7508 JNZ 0x0060c215
    if(integer::condition("JNZ",flags)) goto L0060c215;
  }
  { // 0x60c20d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x60c20f: ff9040010000 CALL dword ptr [EAX + 0x140]
    const std::uint32_t call_target=m.r32((s.ax+0x00000140u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0060c215: { // 0x60c215: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x60c216: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x60c218: 7ce4 JL 0x0060c1fe
    if(integer::condition("JL",flags)) goto L0060c1fe;
  }
  L0060c21a: { // 0x60c21a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x60c21b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60c21c: c605fee2a50000 MOV byte ptr [0x00a5e2fe],0x0
    m.w8((0x00a5e2feu), 0x00000000u);
  }
  { // 0x60c223: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060c224: { // 0x60c224: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00212280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x612280: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x612281: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x612283: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x612285: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x612286: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x612287: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x612289: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x61228a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x61228c: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x61228e: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x612290: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x612292: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x612293: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x612295: 7f26 JG 0x006122bd
    if(integer::condition("JG",flags)) goto L006122bd;
  }
  { // 0x612297: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x612298: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0061229c: { // 0x61229c: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x6122a0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6122a2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6122a3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6122a4: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  { // 0x6122a8: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  { // 0x6122aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6122ab: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  { // 0x6122af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6122b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6122b2: e8c9feffff CALL 0x00612180
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6122b7: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6122b8: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x6122ba: 7ee0 JLE 0x0061229c
    if(integer::condition("JLE",flags)) goto L0061229c;
  }
  { // 0x6122bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006122bd: { // 0x6122bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6122be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6122bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6122c0: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002122d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6122d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6122d1: 83c1fe ADD ECX,-0x2
    s.cx = integer::add(s.cx,0xfffffffeu,32,flags);
  }
  { // 0x6122d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6122d5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6122d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6122d8: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  { // 0x6122dc: 7f06 JG 0x006122e4
    if(integer::condition("JG",flags)) goto L006122e4;
  }
  { // 0x6122de: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6122e0: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6122e2: eb0e JMP 0x006122f2
    goto L006122f2;
  }
  L006122e4: { // 0x6122e4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6122e6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6122e7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6122e9: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x6122eb: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6122ed: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x6122ef: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x6122f1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006122f2: { // 0x6122f2: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x6122f4: 7f2a JG 0x00612320
    if(integer::condition("JG",flags)) goto L00612320;
  }
  { // 0x6122f6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6122f7: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  { // 0x6122fb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6122fc: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L00612300: { // 0x612300: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x612304: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x612308: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x61230a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x61230b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x61230c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x61230d: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x612311: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x612313: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x612314: e867feffff CALL 0x00612180
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x612319: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x61231a: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x61231c: 7ee2 JLE 0x00612300
    if(integer::condition("JLE",flags)) goto L00612300;
  }
  { // 0x61231e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x61231f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00612320: { // 0x612320: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x612321: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x612322: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x612323: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_00216db0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x616db0: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  { // 0x616db3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x616db4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x616db5: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x616db9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x616dba: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x616dbb: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  { // 0x616dbd: b946000000 MOV ECX,0x46
    s.cx = 0x00000046u;
  }
  { // 0x616dc2: e8690ae8ff CALL 0x00497830
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x616dc7: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x616dc9: 8d742414 LEA ESI,[ESP + 0x14]
    s.si = (f.sp+0x00000014u);
  }
  { // 0x616dcd: bf0f000000 MOV EDI,0xf
    s.di = 0x0000000fu;
  }
  L00616dd2: { // 0x616dd2: b994627c00 MOV ECX,0x7c6294
    s.cx = 0x007c6294u;
  }
  { // 0x616dd7: e844800d00 CALL 0x006eee20
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x616ddc: 668b00 MOV AX,word ptr [EAX]
    s.ax = with_ax(s.ax, m.r16((s.ax)));
  }
  { // 0x616ddf: 668906 MOV word ptr [ESI],AX
    m.w16((s.si), (s.ax & 0xffffu));
  }
  { // 0x616de2: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x616de5: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x616de6: 75ea JNZ 0x00616dd2
    if(integer::condition("JNZ",flags)) goto L00616dd2;
  }
  { // 0x616de8: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x616dec: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x616dee: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x616def: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x616df1: 66c744243a0000 MOV word ptr [ESP + 0x3a],0x0
    m.w16((f.sp+0x0000003au), 0x00000000u);
  }
  { // 0x616df8: e853a7e1ff CALL 0x00431550
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x616dfd: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x616e01: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x616e02: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x616e03: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x616e05: 8b431c MOV EAX,dword ptr [EBX + 0x1c]
    s.ax = m.r32((s.bx+0x0000001cu));
  }
  { // 0x616e08: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  { // 0x616e0b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x616e0c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x616e0d: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x616e10: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00218940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x618940: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x618941: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x618942: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x618943: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x618945: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x618947: bee45f7d00 MOV ESI,0x7d5fe4
    s.si = 0x007d5fe4u;
  }
  L0061894c: { // 0x61894c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x61894e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x61894f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x618950: e80b4f1500 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x618955: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x618958: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x61895a: 7413 JZ 0x0061896f
    if(integer::condition("JZ",flags)) goto L0061896f;
  }
  { // 0x61895c: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x61895f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x618960: 81fef85f7d00 CMP ESI,0x7d5ff8
    (void)integer::sub(s.si,0x007d5ff8u,32,flags);
  }
  { // 0x618966: 7ce4 JL 0x0061894c
    if(integer::condition("JL",flags)) goto L0061894c;
  }
  { // 0x618968: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x618969: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x61896a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x61896d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x61896e: c3 RET
    finish(m,s,f,0u); return;
  }
  L0061896f: { // 0x61896f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x618971: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x618972: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x618973: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x618974: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00219990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x619990: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x619991: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x619992: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x619993: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x619995: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x619997: bebc617d00 MOV ESI,0x7d61bc
    s.si = 0x007d61bcu;
  }
  L0061999c: { // 0x61999c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x61999e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x61999f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6199a0: e8bb3e1500 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6199a5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6199a8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6199aa: 7413 JZ 0x006199bf
    if(integer::condition("JZ",flags)) goto L006199bf;
  }
  { // 0x6199ac: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x6199af: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6199b0: 81fed0617d00 CMP ESI,0x7d61d0
    (void)integer::sub(s.si,0x007d61d0u,32,flags);
  }
  { // 0x6199b6: 7ce4 JL 0x0061999c
    if(integer::condition("JL",flags)) goto L0061999c;
  }
  { // 0x6199b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6199b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6199ba: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x6199bd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6199be: c3 RET
    finish(m,s,f,0u); return;
  }
  L006199bf: { // 0x6199bf: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6199c1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6199c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6199c3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6199c4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00219c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x619c20: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x619c21: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x619c22: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x619c23: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x619c25: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x619c27: bee0357900 MOV ESI,0x7935e0
    s.si = 0x007935e0u;
  }
  L00619c2c: { // 0x619c2c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x619c2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x619c2f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x619c30: e82b3c1500 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x619c35: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x619c38: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x619c3a: 7412 JZ 0x00619c4e
    if(integer::condition("JZ",flags)) goto L00619c4e;
  }
  { // 0x619c3c: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x619c3f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x619c40: 81fe10367900 CMP ESI,0x793610
    (void)integer::sub(s.si,0x00793610u,32,flags);
  }
  { // 0x619c46: 7ce4 JL 0x00619c2c
    if(integer::condition("JL",flags)) goto L00619c2c;
  }
  { // 0x619c48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x619c49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x619c4a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x619c4c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x619c4d: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619c4e: { // 0x619c4e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x619c50: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x619c51: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x619c52: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x619c53: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0022e190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62e190: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x62e191: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x62e195: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62e196: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62e197: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x62e199: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x62e19a: e8a13cf6ff CALL 0x00591e40
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x62e19f: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  { // 0x62e1a5: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x62e1a7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62e1a8: e8635be6ff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x62e1ad: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  { // 0x62e1b3: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x62e1b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62e1b7: 7e40 JLE 0x0062e1f9
    if(integer::condition("JLE",flags)) goto L0062e1f9;
  }
  L0062e1b9: { // 0x62e1b9: 8b8ecc000000 MOV ECX,dword ptr [ESI + 0xcc]
    s.cx = m.r32((s.si+0x000000ccu));
  }
  { // 0x62e1bf: 8b04b9 MOV EAX,dword ptr [ECX + EDI*0x4]
    s.ax = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  { // 0x62e1c2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62e1c4: 7428 JZ 0x0062e1ee
    if(integer::condition("JZ",flags)) goto L0062e1ee;
  }
  { // 0x62e1c6: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x62e1c9: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  { // 0x62e1cc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62e1cd: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x62e1d0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62e1d1: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x62e1d3: e8385be6ff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x62e1d8: 8b86cc000000 MOV EAX,dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  { // 0x62e1de: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x62e1e1: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x62e1e3: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x62e1e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62e1e7: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x62e1e9: e8225be6ff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L0062e1ee: { // 0x62e1ee: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  { // 0x62e1f4: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x62e1f5: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x62e1f7: 7cc0 JL 0x0062e1b9
    if(integer::condition("JL",flags)) goto L0062e1b9;
  }
  L0062e1f9: { // 0x62e1f9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x62e1fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62e1fb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x62e1fc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0022e2c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62e2c0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x62e2c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x62e2c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62e2c6: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x62e2ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62e2cb: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x62e2cf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62e2d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62e2d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62e2d2: e8e91ddeff CALL 0x004100c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x62e2d7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62e2d9: 7c4a JL 0x0062e325
    if(integer::condition("JL",flags)) goto L0062e325;
  }
  { // 0x62e2db: 8b8fd0000000 MOV ECX,dword ptr [EDI + 0xd0]
    s.cx = m.r32((s.di+0x000000d0u));
  }
  { // 0x62e2e1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x62e2e3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x62e2e5: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  { // 0x62e2e9: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x62e2eb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62e2ec: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62e2ed: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  { // 0x62e2f1: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x62e2f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62e2f6: 7c2d JL 0x0062e325
    if(integer::condition("JL",flags)) goto L0062e325;
  }
  { // 0x62e2f8: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x62e2fc: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x62e2fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62e300: 7e21 JLE 0x0062e323
    if(integer::condition("JLE",flags)) goto L0062e323;
  }
  L0062e302: { // 0x62e302: 8b97cc000000 MOV EDX,dword ptr [EDI + 0xcc]
    s.dx = m.r32((s.di+0x000000ccu));
  }
  { // 0x62e308: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x62e30a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x62e30c: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x62e30e: 8d049a LEA EAX,[EDX + EBX*0x4]
    s.ax = (s.dx+(s.bx * 0x00000004u));
  }
  { // 0x62e311: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62e312: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62e313: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x62e316: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62e318: 7c0b JL 0x0062e325
    if(integer::condition("JL",flags)) goto L0062e325;
  }
  { // 0x62e31a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x62e31e: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x62e31f: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x62e321: 7cdf JL 0x0062e302
    if(integer::condition("JL",flags)) goto L0062e302;
  }
  L0062e323: { // 0x62e323: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062e325: { // 0x62e325: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x62e326: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62e327: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x62e328: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00232e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x632e10: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x632e11: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  { // 0x632e16: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x632e17: 8d78ff LEA EDI,[EAX + -0x1]
    s.di = (s.ax-0x00000001u);
  }
  { // 0x632e1a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x632e1c: 7c63 JL 0x00632e81
    if(integer::condition("JL",flags)) goto L00632e81;
  }
  { // 0x632e1e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00632e1f: { // 0x632e1f: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  { // 0x632e25: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  { // 0x632e28: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x632e2a: 7451 JZ 0x00632e7d
    if(integer::condition("JZ",flags)) goto L00632e7d;
  }
  { // 0x632e2c: a108e3a900 MOV EAX,[0x00a9e308]
    s.ax = m.r32((0x00a9e308u));
  }
  { // 0x632e31: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x632e35: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x632e36: b908e3a900 MOV ECX,0xa9e308
    s.cx = 0x00a9e308u;
  }
  { // 0x632e3b: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x632e3f: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x632e42: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x632e45: 742d JZ 0x00632e74
    if(integer::condition("JZ",flags)) goto L00632e74;
  }
  { // 0x632e47: 8b0d18e3a900 MOV ECX,dword ptr [0x00a9e318]
    s.cx = m.r32((0x00a9e318u));
  }
  { // 0x632e4d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x632e4f: 7d23 JGE 0x00632e74
    if(integer::condition("JGE",flags)) goto L00632e74;
  }
  { // 0x632e51: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x632e52: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x632e54: 890d18e3a900 MOV dword ptr [0x00a9e318],ECX
    m.w32((0x00a9e318u), s.cx);
  }
  { // 0x632e5a: 7d18 JGE 0x00632e74
    if(integer::condition("JGE",flags)) goto L00632e74;
  }
  L00632e5c: { // 0x632e5c: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  { // 0x632e62: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x632e63: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x632e66: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x632e6a: 8b0d18e3a900 MOV ECX,dword ptr [0x00a9e318]
    s.cx = m.r32((0x00a9e318u));
  }
  { // 0x632e70: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x632e72: 7ce8 JL 0x00632e5c
    if(integer::condition("JL",flags)) goto L00632e5c;
  }
  L00632e74: { // 0x632e74: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x632e75: e801a81300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x632e7a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00632e7d: { // 0x632e7d: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x632e7e: 799f JNS 0x00632e1f
    if(integer::condition("JNS",flags)) goto L00632e1f;
  }
  { // 0x632e80: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00632e81: { // 0x632e81: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x632e82: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x632e83: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00232e90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x632e90: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  { // 0x632e95: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x632e96: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x632e98: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x632e9a: 7e17 JLE 0x00632eb3
    if(integer::condition("JLE",flags)) goto L00632eb3;
  }
  L00632e9c: { // 0x632e9c: a10ce3a900 MOV EAX,[0x00a9e30c]
    s.ax = m.r32((0x00a9e30cu));
  }
  { // 0x632ea1: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x632ea4: e817000000 CALL 0x00632ec0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x632ea9: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  { // 0x632eae: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x632eaf: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x632eb1: 7ce9 JL 0x00632e9c
    if(integer::condition("JL",flags)) goto L00632e9c;
  }
  L00632eb3: { // 0x632eb3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x632eb4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002330d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6330d0: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  { // 0x6330d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6330d6: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6330d8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6330da: 7e3d JLE 0x00633119
    if(integer::condition("JLE",flags)) goto L00633119;
  }
  { // 0x6330dc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006330dd: { // 0x6330dd: a10ce3a900 MOV EAX,[0x00a9e30c]
    s.ax = m.r32((0x00a9e30cu));
  }
  { // 0x6330e2: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6330e5: 8b7130 MOV ESI,dword ptr [ECX + 0x30]
    s.si = m.r32((s.cx+0x00000030u));
  }
  { // 0x6330e8: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x6330eb: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  { // 0x6330ee: 740e JZ 0x006330fe
    if(integer::condition("JZ",flags)) goto L006330fe;
  }
  { // 0x6330f0: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x6330f6: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x6330f8: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x6330fa: 7d06 JGE 0x00633102
    if(integer::condition("JGE",flags)) goto L00633102;
  }
  { // 0x6330fc: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006330fe: { // 0x6330fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x633100: 7f07 JG 0x00633109
    if(integer::condition("JG",flags)) goto L00633109;
  }
  L00633102: { // 0x633102: 8a413c MOV AL,byte ptr [ECX + 0x3c]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000003cu)));
  }
  { // 0x633105: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x633107: 7405 JZ 0x0063310e
    if(integer::condition("JZ",flags)) goto L0063310e;
  }
  L00633109: { // 0x633109: e812000000 CALL 0x00633120
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0063310e: { // 0x63310e: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  { // 0x633113: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x633114: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x633116: 7cc5 JL 0x006330dd
    if(integer::condition("JL",flags)) goto L006330dd;
  }
  { // 0x633118: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00633119: { // 0x633119: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63311a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00233b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x633b30: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x633b31: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  { // 0x633b36: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x633b37: 8d78ff LEA EDI,[EAX + -0x1]
    s.di = (s.ax-0x00000001u);
  }
  { // 0x633b3a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x633b3c: 7c63 JL 0x00633ba1
    if(integer::condition("JL",flags)) goto L00633ba1;
  }
  { // 0x633b3e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00633b3f: { // 0x633b3f: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  { // 0x633b45: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  { // 0x633b48: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x633b4a: 7451 JZ 0x00633b9d
    if(integer::condition("JZ",flags)) goto L00633b9d;
  }
  { // 0x633b4c: a108e3a900 MOV EAX,[0x00a9e308]
    s.ax = m.r32((0x00a9e308u));
  }
  { // 0x633b51: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x633b55: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x633b56: b908e3a900 MOV ECX,0xa9e308
    s.cx = 0x00a9e308u;
  }
  { // 0x633b5b: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x633b5f: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x633b62: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x633b65: 742d JZ 0x00633b94
    if(integer::condition("JZ",flags)) goto L00633b94;
  }
  { // 0x633b67: 8b0d18e3a900 MOV ECX,dword ptr [0x00a9e318]
    s.cx = m.r32((0x00a9e318u));
  }
  { // 0x633b6d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x633b6f: 7d23 JGE 0x00633b94
    if(integer::condition("JGE",flags)) goto L00633b94;
  }
  { // 0x633b71: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x633b72: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x633b74: 890d18e3a900 MOV dword ptr [0x00a9e318],ECX
    m.w32((0x00a9e318u), s.cx);
  }
  { // 0x633b7a: 7d18 JGE 0x00633b94
    if(integer::condition("JGE",flags)) goto L00633b94;
  }
  L00633b7c: { // 0x633b7c: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  { // 0x633b82: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x633b83: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x633b86: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x633b8a: 8b0d18e3a900 MOV ECX,dword ptr [0x00a9e318]
    s.cx = m.r32((0x00a9e318u));
  }
  { // 0x633b90: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x633b92: 7ce8 JL 0x00633b7c
    if(integer::condition("JL",flags)) goto L00633b7c;
  }
  L00633b94: { // 0x633b94: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x633b95: e8e19a1300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x633b9a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00633b9d: { // 0x633b9d: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x633b9e: 799f JNS 0x00633b3f
    if(integer::condition("JNS",flags)) goto L00633b3f;
  }
  { // 0x633ba0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00633ba1: { // 0x633ba1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x633ba2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x633ba3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00234c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x634c20: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x634c21: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x634c25: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x634c26: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x634c27: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x634c2b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x634c2d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x634c2f: 7438 JZ 0x00634c69
    if(integer::condition("JZ",flags)) goto L00634c69;
  }
  { // 0x634c31: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  { // 0x634c34: 7c33 JL 0x00634c69
    if(integer::condition("JL",flags)) goto L00634c69;
  }
  { // 0x634c36: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x634c38: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x634c3a: 7e36 JLE 0x00634c72
    if(integer::condition("JLE",flags)) goto L00634c72;
  }
  { // 0x634c3c: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00634c40: { // 0x634c40: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x634c43: 8d4cc614 LEA ECX,[ESI + EAX*0x8 + 0x14]
    s.cx = (s.si+(s.ax * 0x00000008u)+0x00000014u);
  }
  { // 0x634c47: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x634c48: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x634c4b: e8c0b2ffff CALL 0x0062ff10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x634c50: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  { // 0x634c52: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  { // 0x634c55: 83e21f AND EDX,0x1f
    s.dx = integer::logical((s.dx)&(0x0000001fu),32,flags);
  }
  { // 0x634c58: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x634c59: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x634c5a: 895610 MOV dword ptr [ESI + 0x10],EDX
    m.w32((s.si+0x00000010u), s.dx);
  }
  { // 0x634c5d: 75e1 JNZ 0x00634c40
    if(integer::condition("JNZ",flags)) goto L00634c40;
  }
  { // 0x634c5f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x634c63: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x634c64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x634c65: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x634c66: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00634c69: { // 0x634c69: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x634c6a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x634c6b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x634c6d: e8ceba0500 CALL 0x00690740
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00634c72: { // 0x634c72: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x634c73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x634c74: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x634c75: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00249ac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649ac0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649ac1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649ac2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649ac3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ac4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649ac8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649aca: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649acc: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649ace: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649ad2: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649ad5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649ad7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649ad8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ad9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649add: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649ae0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649ae4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649ae6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649ae8: 7e1a JLE 0x00649b04
    if(integer::condition("JLE",flags)) goto L00649b04;
  }
  L00649aea: { // 0x649aea: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649aed: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649aef: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649af1: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649af3: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649af6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649af7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649af8: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649afb: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649aff: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649b00: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649b02: 7ce6 JL 0x00649aea
    if(integer::condition("JL",flags)) goto L00649aea;
  }
  L00649b04: { // 0x649b04: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649b05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649b06: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649b07: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649b08: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649b40: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649b41: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649b42: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649b43: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649b44: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649b48: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649b4a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649b4c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649b4e: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649b52: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649b55: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649b57: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649b58: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649b59: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649b5d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649b60: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649b64: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649b66: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649b68: 7e1a JLE 0x00649b84
    if(integer::condition("JLE",flags)) goto L00649b84;
  }
  L00649b6a: { // 0x649b6a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649b6d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649b6f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649b71: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649b73: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649b76: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649b77: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649b78: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649b7b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649b7f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649b80: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649b82: 7ce6 JL 0x00649b6a
    if(integer::condition("JL",flags)) goto L00649b6a;
  }
  L00649b84: { // 0x649b84: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649b85: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649b86: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649b87: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649b88: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649c20: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649c21: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649c22: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649c23: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649c24: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649c28: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649c2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649c2c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649c2e: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649c32: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649c35: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649c37: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649c38: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649c39: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649c3d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649c40: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649c44: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649c46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649c48: 7e1a JLE 0x00649c64
    if(integer::condition("JLE",flags)) goto L00649c64;
  }
  L00649c4a: { // 0x649c4a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649c4d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649c4f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649c51: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649c53: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649c56: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649c57: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649c58: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649c5b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649c5f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649c60: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649c62: 7ce6 JL 0x00649c4a
    if(integer::condition("JL",flags)) goto L00649c4a;
  }
  L00649c64: { // 0x649c64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649c65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649c66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649c67: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649c68: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649ca0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649ca1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649ca2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649ca3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ca4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649ca8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649caa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649cac: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649cae: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649cb2: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649cb5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649cb7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649cb8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649cb9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649cbd: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649cc0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649cc4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649cc6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649cc8: 7e1a JLE 0x00649ce4
    if(integer::condition("JLE",flags)) goto L00649ce4;
  }
  L00649cca: { // 0x649cca: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649ccd: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649ccf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649cd1: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649cd3: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649cd6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649cd7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649cd8: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649cdb: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649cdf: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649ce0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649ce2: 7ce6 JL 0x00649cca
    if(integer::condition("JL",flags)) goto L00649cca;
  }
  L00649ce4: { // 0x649ce4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649ce5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649ce6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649ce7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649ce8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249d20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649d20: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649d21: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649d22: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649d23: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649d24: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649d28: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649d2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649d2c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649d2e: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649d32: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649d35: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649d37: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649d38: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649d39: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649d3d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649d40: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649d44: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649d46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649d48: 7e1a JLE 0x00649d64
    if(integer::condition("JLE",flags)) goto L00649d64;
  }
  L00649d4a: { // 0x649d4a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649d4d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649d4f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649d51: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649d53: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649d56: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649d57: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649d58: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649d5b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649d5f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649d60: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649d62: 7ce6 JL 0x00649d4a
    if(integer::condition("JL",flags)) goto L00649d4a;
  }
  L00649d64: { // 0x649d64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649d65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649d66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649d67: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649d68: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249e90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649e90: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649e91: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649e92: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649e93: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649e94: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649e98: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649e9a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649e9c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649e9e: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649ea2: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649ea5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649ea7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649ea8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ea9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649ead: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649eb0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649eb4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649eb6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649eb8: 7e1a JLE 0x00649ed4
    if(integer::condition("JLE",flags)) goto L00649ed4;
  }
  L00649eba: { // 0x649eba: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649ebd: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649ebf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649ec1: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649ec3: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649ec6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649ec7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ec8: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649ecb: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649ecf: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649ed0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649ed2: 7ce6 JL 0x00649eba
    if(integer::condition("JL",flags)) goto L00649eba;
  }
  L00649ed4: { // 0x649ed4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649ed5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649ed6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649ed7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649ed8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249ee0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649ee0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649ee1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649ee2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649ee3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ee4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649ee8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649eea: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649eec: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649eee: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649ef2: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649ef5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649ef7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649ef8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ef9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649efd: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649f00: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649f04: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649f06: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649f08: 7e1a JLE 0x00649f24
    if(integer::condition("JLE",flags)) goto L00649f24;
  }
  L00649f0a: { // 0x649f0a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649f0d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649f0f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649f11: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649f13: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649f16: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649f17: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649f18: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649f1b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649f1f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649f20: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649f22: 7ce6 JL 0x00649f0a
    if(integer::condition("JL",flags)) goto L00649f0a;
  }
  L00649f24: { // 0x649f24: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649f25: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649f26: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649f27: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649f28: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649f60: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649f61: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649f62: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649f63: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649f64: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649f68: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649f6a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649f6c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649f6e: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649f72: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649f75: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649f77: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649f78: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649f79: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649f7d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649f80: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649f84: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x649f86: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649f88: 7e1a JLE 0x00649fa4
    if(integer::condition("JLE",flags)) goto L00649fa4;
  }
  L00649f8a: { // 0x649f8a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x649f8d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x649f8f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649f91: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649f93: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x649f96: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649f97: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649f98: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649f9b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649f9f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x649fa0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x649fa2: 7ce6 JL 0x00649f8a
    if(integer::condition("JL",flags)) goto L00649f8a;
  }
  L00649fa4: { // 0x649fa4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649fa5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649fa6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x649fa7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x649fa8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649fe0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649fe1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x649fe2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649fe3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649fe4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x649fe8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x649fea: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x649fec: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x649fee: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x649ff2: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x649ff5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x649ff7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x649ff8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649ff9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x649ffd: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64a000: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64a004: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64a006: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a008: 7e1a JLE 0x0064a024
    if(integer::condition("JLE",flags)) goto L0064a024;
  }
  L0064a00a: { // 0x64a00a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x64a00d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x64a00f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64a011: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64a013: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x64a016: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64a017: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64a018: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64a01b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64a01f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64a020: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64a022: 7ce6 JL 0x0064a00a
    if(integer::condition("JL",flags)) goto L0064a00a;
  }
  L0064a024: { // 0x64a024: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a025: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a026: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64a027: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x64a028: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0024bce0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64bce0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64bce3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64bce4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64bce5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x64bce7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64bce8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64bcea: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x64bcee: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64bcf0: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64bcf2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x64bcf3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64bcf4: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64bcf7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64bcf9: 7c2c JL 0x0064bd27
    if(integer::condition("JL",flags)) goto L0064bd27;
  }
  { // 0x64bcfb: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64bcff: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x64bd01: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64bd03: 7e20 JLE 0x0064bd25
    if(integer::condition("JLE",flags)) goto L0064bd25;
  }
  { // 0x64bd05: 8b3dec557800 MOV EDI,dword ptr [0x007855ec]
    s.di = m.r32((0x007855ecu));
  }
  L0064bd0b: { // 0x64bd0b: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x64bd0f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64bd10: 68f8aa7900 PUSH 0x79aaf8
    f.push(m,0x0079aaf8u);
  }
  { // 0x64bd15: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64bd16: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64bd18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64bd1a: 7c0b JL 0x0064bd27
    if(integer::condition("JL",flags)) goto L0064bd27;
  }
  { // 0x64bd1c: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64bd20: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x64bd21: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x64bd23: 7ce6 JL 0x0064bd0b
    if(integer::condition("JL",flags)) goto L0064bd0b;
  }
  L0064bd25: { // 0x64bd25: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064bd27: { // 0x64bd27: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64bd28: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64bd29: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64bd2a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64bd2d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f150: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f153: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f154: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f155: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f156: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f158: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f15a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f15c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f15f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f163: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f165: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f167: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f168: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f169: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f16d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f170: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f172: 7c54 JL 0x0064f1c8
    if(integer::condition("JL",flags)) goto L0064f1c8;
  }
  { // 0x64f174: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f178: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f17a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f17c: 7e48 JLE 0x0064f1c6
    if(integer::condition("JLE",flags)) goto L0064f1c6;
  }
  L0064f17e: { // 0x64f17e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f181: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f189: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f18d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f190: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f191: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f196: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f197: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f199: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f19b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f19d: 7c29 JL 0x0064f1c8
    if(integer::condition("JL",flags)) goto L0064f1c8;
  }
  { // 0x64f19f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f1a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f1a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f1a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f1ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f1ad: 7c19 JL 0x0064f1c8
    if(integer::condition("JL",flags)) goto L0064f1c8;
  }
  { // 0x64f1af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f1b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f1b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f1b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f1b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f1bb: 7c0b JL 0x0064f1c8
    if(integer::condition("JL",flags)) goto L0064f1c8;
  }
  { // 0x64f1bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f1c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f1c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f1c4: 7cb8 JL 0x0064f17e
    if(integer::condition("JL",flags)) goto L0064f17e;
  }
  L0064f1c6: { // 0x64f1c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f1c8: { // 0x64f1c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f1c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f1ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f1cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f1ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f1d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f1d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f1d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f1d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f1d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f1d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f1d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f1da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f1dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f1df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f1e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f1e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f1e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f1e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f1e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f1ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f1f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f1f2: 7c54 JL 0x0064f248
    if(integer::condition("JL",flags)) goto L0064f248;
  }
  { // 0x64f1f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f1f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f1fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f1fc: 7e48 JLE 0x0064f246
    if(integer::condition("JLE",flags)) goto L0064f246;
  }
  L0064f1fe: { // 0x64f1fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f201: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f209: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f20d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f210: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f211: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f216: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f217: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f219: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f21b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f21d: 7c29 JL 0x0064f248
    if(integer::condition("JL",flags)) goto L0064f248;
  }
  { // 0x64f21f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f223: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f224: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f225: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f22b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f22d: 7c19 JL 0x0064f248
    if(integer::condition("JL",flags)) goto L0064f248;
  }
  { // 0x64f22f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f233: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f234: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f236: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f239: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f23b: 7c0b JL 0x0064f248
    if(integer::condition("JL",flags)) goto L0064f248;
  }
  { // 0x64f23d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f241: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f242: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f244: 7cb8 JL 0x0064f1fe
    if(integer::condition("JL",flags)) goto L0064f1fe;
  }
  L0064f246: { // 0x64f246: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f248: { // 0x64f248: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f249: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f24a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f24b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f24e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f250: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f253: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f254: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f255: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f256: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f258: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f25a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f25c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f25f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f263: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f265: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f267: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f268: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f269: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f26d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f270: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f272: 7c54 JL 0x0064f2c8
    if(integer::condition("JL",flags)) goto L0064f2c8;
  }
  { // 0x64f274: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f278: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f27a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f27c: 7e48 JLE 0x0064f2c6
    if(integer::condition("JLE",flags)) goto L0064f2c6;
  }
  L0064f27e: { // 0x64f27e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f281: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f289: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f28d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f290: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f291: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f296: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f297: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f299: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f29b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f29d: 7c29 JL 0x0064f2c8
    if(integer::condition("JL",flags)) goto L0064f2c8;
  }
  { // 0x64f29f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f2a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f2a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f2a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f2ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f2ad: 7c19 JL 0x0064f2c8
    if(integer::condition("JL",flags)) goto L0064f2c8;
  }
  { // 0x64f2af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f2b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f2b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f2b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f2b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f2bb: 7c0b JL 0x0064f2c8
    if(integer::condition("JL",flags)) goto L0064f2c8;
  }
  { // 0x64f2bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f2c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f2c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f2c4: 7cb8 JL 0x0064f27e
    if(integer::condition("JL",flags)) goto L0064f27e;
  }
  L0064f2c6: { // 0x64f2c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f2c8: { // 0x64f2c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f2c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f2ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f2cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f2ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f2d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f2d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f2d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f2d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f2d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f2d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f2d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f2da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f2dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f2df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f2e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f2e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f2e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f2e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f2e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f2ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f2f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f2f2: 7c54 JL 0x0064f348
    if(integer::condition("JL",flags)) goto L0064f348;
  }
  { // 0x64f2f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f2f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f2fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f2fc: 7e48 JLE 0x0064f346
    if(integer::condition("JLE",flags)) goto L0064f346;
  }
  L0064f2fe: { // 0x64f2fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f301: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f309: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f30d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f310: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f311: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f316: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f317: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f319: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f31b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f31d: 7c29 JL 0x0064f348
    if(integer::condition("JL",flags)) goto L0064f348;
  }
  { // 0x64f31f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f323: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f324: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f325: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f32b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f32d: 7c19 JL 0x0064f348
    if(integer::condition("JL",flags)) goto L0064f348;
  }
  { // 0x64f32f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f333: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f334: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f336: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f339: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f33b: 7c0b JL 0x0064f348
    if(integer::condition("JL",flags)) goto L0064f348;
  }
  { // 0x64f33d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f341: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f342: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f344: 7cb8 JL 0x0064f2fe
    if(integer::condition("JL",flags)) goto L0064f2fe;
  }
  L0064f346: { // 0x64f346: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f348: { // 0x64f348: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f349: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f34a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f34b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f34e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f350: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f353: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f354: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f355: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f356: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f358: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f35a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f35c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f35f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f363: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f365: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f367: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f368: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f369: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f36d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f370: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f372: 7c54 JL 0x0064f3c8
    if(integer::condition("JL",flags)) goto L0064f3c8;
  }
  { // 0x64f374: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f378: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f37a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f37c: 7e48 JLE 0x0064f3c6
    if(integer::condition("JLE",flags)) goto L0064f3c6;
  }
  L0064f37e: { // 0x64f37e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f381: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f389: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f38d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f390: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f391: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f396: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f397: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f399: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f39b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f39d: 7c29 JL 0x0064f3c8
    if(integer::condition("JL",flags)) goto L0064f3c8;
  }
  { // 0x64f39f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f3a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f3a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f3a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f3ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f3ad: 7c19 JL 0x0064f3c8
    if(integer::condition("JL",flags)) goto L0064f3c8;
  }
  { // 0x64f3af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f3b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f3b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f3b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f3b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f3bb: 7c0b JL 0x0064f3c8
    if(integer::condition("JL",flags)) goto L0064f3c8;
  }
  { // 0x64f3bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f3c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f3c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f3c4: 7cb8 JL 0x0064f37e
    if(integer::condition("JL",flags)) goto L0064f37e;
  }
  L0064f3c6: { // 0x64f3c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f3c8: { // 0x64f3c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f3c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f3ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f3cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f3ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f3d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f3d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f3d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f3d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f3d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f3d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f3d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f3da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f3dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f3df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f3e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f3e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f3e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f3e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f3e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f3ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f3f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f3f2: 7c54 JL 0x0064f448
    if(integer::condition("JL",flags)) goto L0064f448;
  }
  { // 0x64f3f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f3f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f3fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f3fc: 7e48 JLE 0x0064f446
    if(integer::condition("JLE",flags)) goto L0064f446;
  }
  L0064f3fe: { // 0x64f3fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f401: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f409: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f40d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f410: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f411: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f416: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f417: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f419: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f41b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f41d: 7c29 JL 0x0064f448
    if(integer::condition("JL",flags)) goto L0064f448;
  }
  { // 0x64f41f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f423: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f424: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f425: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f42b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f42d: 7c19 JL 0x0064f448
    if(integer::condition("JL",flags)) goto L0064f448;
  }
  { // 0x64f42f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f433: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f434: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f436: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f439: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f43b: 7c0b JL 0x0064f448
    if(integer::condition("JL",flags)) goto L0064f448;
  }
  { // 0x64f43d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f441: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f442: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f444: 7cb8 JL 0x0064f3fe
    if(integer::condition("JL",flags)) goto L0064f3fe;
  }
  L0064f446: { // 0x64f446: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f448: { // 0x64f448: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f449: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f44a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f44b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f44e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f450: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f453: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f454: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f455: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f456: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f458: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f45a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f45c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f45f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f463: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f465: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f467: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f468: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f469: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f46d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f470: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f472: 7c54 JL 0x0064f4c8
    if(integer::condition("JL",flags)) goto L0064f4c8;
  }
  { // 0x64f474: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f478: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f47a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f47c: 7e48 JLE 0x0064f4c6
    if(integer::condition("JLE",flags)) goto L0064f4c6;
  }
  L0064f47e: { // 0x64f47e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f481: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f489: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f48d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f490: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f491: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f496: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f497: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f499: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f49b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f49d: 7c29 JL 0x0064f4c8
    if(integer::condition("JL",flags)) goto L0064f4c8;
  }
  { // 0x64f49f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f4a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f4a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f4a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f4ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f4ad: 7c19 JL 0x0064f4c8
    if(integer::condition("JL",flags)) goto L0064f4c8;
  }
  { // 0x64f4af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f4b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f4b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f4b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f4b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f4bb: 7c0b JL 0x0064f4c8
    if(integer::condition("JL",flags)) goto L0064f4c8;
  }
  { // 0x64f4bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f4c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f4c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f4c4: 7cb8 JL 0x0064f47e
    if(integer::condition("JL",flags)) goto L0064f47e;
  }
  L0064f4c6: { // 0x64f4c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f4c8: { // 0x64f4c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f4c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f4ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f4cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f4ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f4d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f4d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f4d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f4d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f4d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f4d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f4da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f4dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f4df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f4e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f4e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f4e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f4e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f4e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f4ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f4f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f4f2: 7c54 JL 0x0064f548
    if(integer::condition("JL",flags)) goto L0064f548;
  }
  { // 0x64f4f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f4f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f4fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f4fc: 7e48 JLE 0x0064f546
    if(integer::condition("JLE",flags)) goto L0064f546;
  }
  L0064f4fe: { // 0x64f4fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f501: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f509: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f50d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f510: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f511: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f516: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f517: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f519: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f51b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f51d: 7c29 JL 0x0064f548
    if(integer::condition("JL",flags)) goto L0064f548;
  }
  { // 0x64f51f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f523: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f524: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f525: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f52b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f52d: 7c19 JL 0x0064f548
    if(integer::condition("JL",flags)) goto L0064f548;
  }
  { // 0x64f52f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f533: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f534: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f536: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f539: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f53b: 7c0b JL 0x0064f548
    if(integer::condition("JL",flags)) goto L0064f548;
  }
  { // 0x64f53d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f541: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f542: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f544: 7cb8 JL 0x0064f4fe
    if(integer::condition("JL",flags)) goto L0064f4fe;
  }
  L0064f546: { // 0x64f546: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f548: { // 0x64f548: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f549: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f54a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f54b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f54e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f550: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f553: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f554: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f555: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f556: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f558: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f55a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f55c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f55f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f563: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f565: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f567: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f568: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f569: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f56d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f570: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f572: 7c54 JL 0x0064f5c8
    if(integer::condition("JL",flags)) goto L0064f5c8;
  }
  { // 0x64f574: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f578: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f57a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f57c: 7e48 JLE 0x0064f5c6
    if(integer::condition("JLE",flags)) goto L0064f5c6;
  }
  L0064f57e: { // 0x64f57e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f581: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f589: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f58d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f590: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f591: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f596: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f597: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f599: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f59b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f59d: 7c29 JL 0x0064f5c8
    if(integer::condition("JL",flags)) goto L0064f5c8;
  }
  { // 0x64f59f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f5a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f5a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f5a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f5ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f5ad: 7c19 JL 0x0064f5c8
    if(integer::condition("JL",flags)) goto L0064f5c8;
  }
  { // 0x64f5af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f5b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f5b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f5b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f5b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f5bb: 7c0b JL 0x0064f5c8
    if(integer::condition("JL",flags)) goto L0064f5c8;
  }
  { // 0x64f5bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f5c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f5c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f5c4: 7cb8 JL 0x0064f57e
    if(integer::condition("JL",flags)) goto L0064f57e;
  }
  L0064f5c6: { // 0x64f5c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f5c8: { // 0x64f5c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f5c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f5ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f5cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f5ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f5d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f5d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f5d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f5d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f5d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f5d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f5d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f5da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f5dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f5df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f5e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f5e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f5e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f5e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f5e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f5ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f5f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f5f2: 7c54 JL 0x0064f648
    if(integer::condition("JL",flags)) goto L0064f648;
  }
  { // 0x64f5f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f5f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f5fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f5fc: 7e48 JLE 0x0064f646
    if(integer::condition("JLE",flags)) goto L0064f646;
  }
  L0064f5fe: { // 0x64f5fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f601: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f609: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f60d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f610: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f611: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f616: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f617: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f619: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f61b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f61d: 7c29 JL 0x0064f648
    if(integer::condition("JL",flags)) goto L0064f648;
  }
  { // 0x64f61f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f623: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f624: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f625: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f62b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f62d: 7c19 JL 0x0064f648
    if(integer::condition("JL",flags)) goto L0064f648;
  }
  { // 0x64f62f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f633: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f634: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f636: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f639: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f63b: 7c0b JL 0x0064f648
    if(integer::condition("JL",flags)) goto L0064f648;
  }
  { // 0x64f63d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f641: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f642: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f644: 7cb8 JL 0x0064f5fe
    if(integer::condition("JL",flags)) goto L0064f5fe;
  }
  L0064f646: { // 0x64f646: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f648: { // 0x64f648: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f649: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f64a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f64b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f64e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f650: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f653: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f654: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f655: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f656: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f658: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f65a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f65c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f65f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f663: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f665: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f667: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f668: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f669: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f66d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f670: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f672: 7c54 JL 0x0064f6c8
    if(integer::condition("JL",flags)) goto L0064f6c8;
  }
  { // 0x64f674: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f678: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f67a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f67c: 7e48 JLE 0x0064f6c6
    if(integer::condition("JLE",flags)) goto L0064f6c6;
  }
  L0064f67e: { // 0x64f67e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f681: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f689: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f68d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f690: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f691: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f696: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f697: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f699: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f69b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f69d: 7c29 JL 0x0064f6c8
    if(integer::condition("JL",flags)) goto L0064f6c8;
  }
  { // 0x64f69f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f6a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f6a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f6a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f6ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f6ad: 7c19 JL 0x0064f6c8
    if(integer::condition("JL",flags)) goto L0064f6c8;
  }
  { // 0x64f6af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f6b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f6b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f6b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f6b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f6bb: 7c0b JL 0x0064f6c8
    if(integer::condition("JL",flags)) goto L0064f6c8;
  }
  { // 0x64f6bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f6c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f6c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f6c4: 7cb8 JL 0x0064f67e
    if(integer::condition("JL",flags)) goto L0064f67e;
  }
  L0064f6c6: { // 0x64f6c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f6c8: { // 0x64f6c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f6c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f6ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f6cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f6ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f6d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f6d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f6d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f6d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f6d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f6d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f6d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f6da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f6dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f6df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f6e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f6e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f6e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f6e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f6e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f6ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f6f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f6f2: 7c54 JL 0x0064f748
    if(integer::condition("JL",flags)) goto L0064f748;
  }
  { // 0x64f6f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f6f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f6fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f6fc: 7e48 JLE 0x0064f746
    if(integer::condition("JLE",flags)) goto L0064f746;
  }
  L0064f6fe: { // 0x64f6fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f701: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f709: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f70d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f710: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f711: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f716: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f717: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f719: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f71b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f71d: 7c29 JL 0x0064f748
    if(integer::condition("JL",flags)) goto L0064f748;
  }
  { // 0x64f71f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f723: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f724: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f725: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f72b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f72d: 7c19 JL 0x0064f748
    if(integer::condition("JL",flags)) goto L0064f748;
  }
  { // 0x64f72f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f733: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f734: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f736: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f739: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f73b: 7c0b JL 0x0064f748
    if(integer::condition("JL",flags)) goto L0064f748;
  }
  { // 0x64f73d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f741: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f742: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f744: 7cb8 JL 0x0064f6fe
    if(integer::condition("JL",flags)) goto L0064f6fe;
  }
  L0064f746: { // 0x64f746: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f748: { // 0x64f748: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f749: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f74a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f74b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f74e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f750: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f753: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f754: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f755: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f756: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f758: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f75a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f75c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f75f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f763: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f765: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f767: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f768: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f769: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f76d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f770: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f772: 7c54 JL 0x0064f7c8
    if(integer::condition("JL",flags)) goto L0064f7c8;
  }
  { // 0x64f774: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f778: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f77a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f77c: 7e48 JLE 0x0064f7c6
    if(integer::condition("JLE",flags)) goto L0064f7c6;
  }
  L0064f77e: { // 0x64f77e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f781: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f789: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f78d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f790: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f791: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f796: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f797: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f799: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f79b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f79d: 7c29 JL 0x0064f7c8
    if(integer::condition("JL",flags)) goto L0064f7c8;
  }
  { // 0x64f79f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f7a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f7a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f7a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f7ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f7ad: 7c19 JL 0x0064f7c8
    if(integer::condition("JL",flags)) goto L0064f7c8;
  }
  { // 0x64f7af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f7b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f7b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f7b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f7b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f7bb: 7c0b JL 0x0064f7c8
    if(integer::condition("JL",flags)) goto L0064f7c8;
  }
  { // 0x64f7bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f7c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f7c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f7c4: 7cb8 JL 0x0064f77e
    if(integer::condition("JL",flags)) goto L0064f77e;
  }
  L0064f7c6: { // 0x64f7c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f7c8: { // 0x64f7c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f7c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f7ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f7cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f7ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f7d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f7d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f7d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f7d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f7d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f7d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f7da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f7dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f7df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f7e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f7e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f7e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f7e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f7e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f7ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f7f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f7f2: 7c54 JL 0x0064f848
    if(integer::condition("JL",flags)) goto L0064f848;
  }
  { // 0x64f7f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f7f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f7fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f7fc: 7e48 JLE 0x0064f846
    if(integer::condition("JLE",flags)) goto L0064f846;
  }
  L0064f7fe: { // 0x64f7fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f801: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f809: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f80d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f810: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f811: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f816: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f817: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f819: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f81b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f81d: 7c29 JL 0x0064f848
    if(integer::condition("JL",flags)) goto L0064f848;
  }
  { // 0x64f81f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f823: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f824: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f825: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f82b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f82d: 7c19 JL 0x0064f848
    if(integer::condition("JL",flags)) goto L0064f848;
  }
  { // 0x64f82f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f833: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f834: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f836: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f839: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f83b: 7c0b JL 0x0064f848
    if(integer::condition("JL",flags)) goto L0064f848;
  }
  { // 0x64f83d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f841: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f842: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f844: 7cb8 JL 0x0064f7fe
    if(integer::condition("JL",flags)) goto L0064f7fe;
  }
  L0064f846: { // 0x64f846: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f848: { // 0x64f848: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f849: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f84a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f84b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f84e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f850: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f853: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f854: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f855: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f856: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f858: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f85a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f85c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f85f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f863: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f865: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f867: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f868: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f869: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f86d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f870: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f872: 7c54 JL 0x0064f8c8
    if(integer::condition("JL",flags)) goto L0064f8c8;
  }
  { // 0x64f874: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f878: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f87a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f87c: 7e48 JLE 0x0064f8c6
    if(integer::condition("JLE",flags)) goto L0064f8c6;
  }
  L0064f87e: { // 0x64f87e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f881: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f889: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f88d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f890: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f891: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f896: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f897: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f899: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f89b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f89d: 7c29 JL 0x0064f8c8
    if(integer::condition("JL",flags)) goto L0064f8c8;
  }
  { // 0x64f89f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f8a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f8a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f8a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f8ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f8ad: 7c19 JL 0x0064f8c8
    if(integer::condition("JL",flags)) goto L0064f8c8;
  }
  { // 0x64f8af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f8b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f8b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f8b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f8b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f8bb: 7c0b JL 0x0064f8c8
    if(integer::condition("JL",flags)) goto L0064f8c8;
  }
  { // 0x64f8bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f8c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f8c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f8c4: 7cb8 JL 0x0064f87e
    if(integer::condition("JL",flags)) goto L0064f87e;
  }
  L0064f8c6: { // 0x64f8c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f8c8: { // 0x64f8c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f8c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f8ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f8cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f8ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f8d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f8d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f8d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f8d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f8d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f8d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f8d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f8da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f8dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f8df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f8e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f8e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f8e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f8e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f8e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f8ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f8f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f8f2: 7c54 JL 0x0064f948
    if(integer::condition("JL",flags)) goto L0064f948;
  }
  { // 0x64f8f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f8f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f8fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f8fc: 7e48 JLE 0x0064f946
    if(integer::condition("JLE",flags)) goto L0064f946;
  }
  L0064f8fe: { // 0x64f8fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f901: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f909: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f90d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f910: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f911: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f916: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f917: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f919: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f91b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f91d: 7c29 JL 0x0064f948
    if(integer::condition("JL",flags)) goto L0064f948;
  }
  { // 0x64f91f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f923: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f924: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f925: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f92b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f92d: 7c19 JL 0x0064f948
    if(integer::condition("JL",flags)) goto L0064f948;
  }
  { // 0x64f92f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f933: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f934: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f936: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f939: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f93b: 7c0b JL 0x0064f948
    if(integer::condition("JL",flags)) goto L0064f948;
  }
  { // 0x64f93d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f941: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f942: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f944: 7cb8 JL 0x0064f8fe
    if(integer::condition("JL",flags)) goto L0064f8fe;
  }
  L0064f946: { // 0x64f946: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f948: { // 0x64f948: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f949: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f94a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f94b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f94e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f950(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f950: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f953: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f954: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f955: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f956: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f958: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f95a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f95c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f95f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f963: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f965: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f967: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f968: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f969: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f96d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f970: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f972: 7c54 JL 0x0064f9c8
    if(integer::condition("JL",flags)) goto L0064f9c8;
  }
  { // 0x64f974: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f978: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f97a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f97c: 7e48 JLE 0x0064f9c6
    if(integer::condition("JLE",flags)) goto L0064f9c6;
  }
  L0064f97e: { // 0x64f97e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64f981: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64f989: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64f98d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64f990: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f991: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64f996: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f997: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f999: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64f99b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f99d: 7c29 JL 0x0064f9c8
    if(integer::condition("JL",flags)) goto L0064f9c8;
  }
  { // 0x64f99f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f9a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f9a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f9a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64f9ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f9ad: 7c19 JL 0x0064f9c8
    if(integer::condition("JL",flags)) goto L0064f9c8;
  }
  { // 0x64f9af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64f9b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64f9b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64f9b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64f9b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f9bb: 7c0b JL 0x0064f9c8
    if(integer::condition("JL",flags)) goto L0064f9c8;
  }
  { // 0x64f9bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f9c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64f9c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64f9c4: 7cb8 JL 0x0064f97e
    if(integer::condition("JL",flags)) goto L0064f97e;
  }
  L0064f9c6: { // 0x64f9c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064f9c8: { // 0x64f9c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64f9c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64f9ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64f9cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f9ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024f9d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64f9d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64f9d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f9d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64f9d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64f9d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64f9d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64f9da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64f9dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64f9df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64f9e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64f9e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64f9e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64f9e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64f9e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64f9ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64f9f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f9f2: 7c54 JL 0x0064fa48
    if(integer::condition("JL",flags)) goto L0064fa48;
  }
  { // 0x64f9f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64f9f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64f9fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64f9fc: 7e48 JLE 0x0064fa46
    if(integer::condition("JLE",flags)) goto L0064fa46;
  }
  L0064f9fe: { // 0x64f9fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fa01: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fa09: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fa0d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fa10: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fa11: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fa16: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fa17: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fa19: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fa1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fa1d: 7c29 JL 0x0064fa48
    if(integer::condition("JL",flags)) goto L0064fa48;
  }
  { // 0x64fa1f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fa23: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fa24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fa25: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fa2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fa2d: 7c19 JL 0x0064fa48
    if(integer::condition("JL",flags)) goto L0064fa48;
  }
  { // 0x64fa2f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fa33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fa34: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fa36: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fa39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fa3b: 7c0b JL 0x0064fa48
    if(integer::condition("JL",flags)) goto L0064fa48;
  }
  { // 0x64fa3d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fa41: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fa42: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fa44: 7cb8 JL 0x0064f9fe
    if(integer::condition("JL",flags)) goto L0064f9fe;
  }
  L0064fa46: { // 0x64fa46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fa48: { // 0x64fa48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fa49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fa4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fa4b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fa4e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fa50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fa53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fa54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fa55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fa56: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fa58: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fa5a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fa5c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fa5f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fa63: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fa65: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fa67: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fa68: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fa69: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fa6d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fa70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fa72: 7c54 JL 0x0064fac8
    if(integer::condition("JL",flags)) goto L0064fac8;
  }
  { // 0x64fa74: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fa78: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fa7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fa7c: 7e48 JLE 0x0064fac6
    if(integer::condition("JLE",flags)) goto L0064fac6;
  }
  L0064fa7e: { // 0x64fa7e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fa81: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fa89: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fa8d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fa90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fa91: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fa96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fa97: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fa99: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fa9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fa9d: 7c29 JL 0x0064fac8
    if(integer::condition("JL",flags)) goto L0064fac8;
  }
  { // 0x64fa9f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64faa3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64faa4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64faa5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64faab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64faad: 7c19 JL 0x0064fac8
    if(integer::condition("JL",flags)) goto L0064fac8;
  }
  { // 0x64faaf: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fab3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fab4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fab6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fab9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fabb: 7c0b JL 0x0064fac8
    if(integer::condition("JL",flags)) goto L0064fac8;
  }
  { // 0x64fabd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fac1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fac2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fac4: 7cb8 JL 0x0064fa7e
    if(integer::condition("JL",flags)) goto L0064fa7e;
  }
  L0064fac6: { // 0x64fac6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fac8: { // 0x64fac8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fac9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64faca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64facb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64face: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fad0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fad3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fad4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fad6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fad8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fada: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fadc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fadf: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fae3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fae5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fae7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fae8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fae9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64faed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64faf0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64faf2: 7c54 JL 0x0064fb48
    if(integer::condition("JL",flags)) goto L0064fb48;
  }
  { // 0x64faf4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64faf8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fafa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fafc: 7e48 JLE 0x0064fb46
    if(integer::condition("JLE",flags)) goto L0064fb46;
  }
  L0064fafe: { // 0x64fafe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fb01: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fb09: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fb0d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fb10: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fb11: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fb16: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fb17: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fb19: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fb1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fb1d: 7c29 JL 0x0064fb48
    if(integer::condition("JL",flags)) goto L0064fb48;
  }
  { // 0x64fb1f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fb23: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fb24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fb25: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fb2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fb2d: 7c19 JL 0x0064fb48
    if(integer::condition("JL",flags)) goto L0064fb48;
  }
  { // 0x64fb2f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fb33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fb34: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fb36: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fb39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fb3b: 7c0b JL 0x0064fb48
    if(integer::condition("JL",flags)) goto L0064fb48;
  }
  { // 0x64fb3d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fb41: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fb42: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fb44: 7cb8 JL 0x0064fafe
    if(integer::condition("JL",flags)) goto L0064fafe;
  }
  L0064fb46: { // 0x64fb46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fb48: { // 0x64fb48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fb49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fb4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fb4b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fb4e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fb50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fb50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fb53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fb54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fb55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fb56: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fb58: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fb5a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fb5c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fb5f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fb63: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fb65: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fb67: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fb68: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fb69: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fb6d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fb70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fb72: 7c54 JL 0x0064fbc8
    if(integer::condition("JL",flags)) goto L0064fbc8;
  }
  { // 0x64fb74: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fb78: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fb7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fb7c: 7e48 JLE 0x0064fbc6
    if(integer::condition("JLE",flags)) goto L0064fbc6;
  }
  L0064fb7e: { // 0x64fb7e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fb81: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fb89: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fb8d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fb90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fb91: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fb96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fb97: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fb99: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fb9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fb9d: 7c29 JL 0x0064fbc8
    if(integer::condition("JL",flags)) goto L0064fbc8;
  }
  { // 0x64fb9f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fba3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fba4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fba5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fbab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fbad: 7c19 JL 0x0064fbc8
    if(integer::condition("JL",flags)) goto L0064fbc8;
  }
  { // 0x64fbaf: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fbb3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fbb4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fbb6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fbb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fbbb: 7c0b JL 0x0064fbc8
    if(integer::condition("JL",flags)) goto L0064fbc8;
  }
  { // 0x64fbbd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fbc1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fbc2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fbc4: 7cb8 JL 0x0064fb7e
    if(integer::condition("JL",flags)) goto L0064fb7e;
  }
  L0064fbc6: { // 0x64fbc6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fbc8: { // 0x64fbc8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fbc9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fbca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fbcb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fbce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fbd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fbd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fbd3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fbd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fbd5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fbd6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fbd8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fbda: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fbdc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fbdf: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fbe3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fbe5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fbe7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fbe8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fbe9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fbed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fbf0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fbf2: 7c54 JL 0x0064fc48
    if(integer::condition("JL",flags)) goto L0064fc48;
  }
  { // 0x64fbf4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fbf8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fbfa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fbfc: 7e48 JLE 0x0064fc46
    if(integer::condition("JLE",flags)) goto L0064fc46;
  }
  L0064fbfe: { // 0x64fbfe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fc01: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fc09: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fc0d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fc10: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fc11: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fc16: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fc17: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fc19: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fc1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fc1d: 7c29 JL 0x0064fc48
    if(integer::condition("JL",flags)) goto L0064fc48;
  }
  { // 0x64fc1f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fc23: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fc24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fc25: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fc2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fc2d: 7c19 JL 0x0064fc48
    if(integer::condition("JL",flags)) goto L0064fc48;
  }
  { // 0x64fc2f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fc33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fc34: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fc36: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fc39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fc3b: 7c0b JL 0x0064fc48
    if(integer::condition("JL",flags)) goto L0064fc48;
  }
  { // 0x64fc3d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fc41: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fc42: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fc44: 7cb8 JL 0x0064fbfe
    if(integer::condition("JL",flags)) goto L0064fbfe;
  }
  L0064fc46: { // 0x64fc46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fc48: { // 0x64fc48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fc49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fc4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fc4b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fc4e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fc50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fc50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fc53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fc54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fc55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fc56: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fc58: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fc5a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fc5c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fc5f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fc63: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fc65: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fc67: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fc68: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fc69: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fc6d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fc70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fc72: 7c54 JL 0x0064fcc8
    if(integer::condition("JL",flags)) goto L0064fcc8;
  }
  { // 0x64fc74: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fc78: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fc7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fc7c: 7e48 JLE 0x0064fcc6
    if(integer::condition("JLE",flags)) goto L0064fcc6;
  }
  L0064fc7e: { // 0x64fc7e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fc81: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fc89: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fc8d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fc90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fc91: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fc96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fc97: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fc99: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fc9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fc9d: 7c29 JL 0x0064fcc8
    if(integer::condition("JL",flags)) goto L0064fcc8;
  }
  { // 0x64fc9f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fca3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fca4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fca5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fcab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fcad: 7c19 JL 0x0064fcc8
    if(integer::condition("JL",flags)) goto L0064fcc8;
  }
  { // 0x64fcaf: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fcb3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fcb4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fcb6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fcb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fcbb: 7c0b JL 0x0064fcc8
    if(integer::condition("JL",flags)) goto L0064fcc8;
  }
  { // 0x64fcbd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fcc1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fcc2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fcc4: 7cb8 JL 0x0064fc7e
    if(integer::condition("JL",flags)) goto L0064fc7e;
  }
  L0064fcc6: { // 0x64fcc6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fcc8: { // 0x64fcc8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fcc9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fcca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fccb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fcce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fcd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fcd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fcd3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fcd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fcd5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fcd6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fcd8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fcda: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fcdc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fcdf: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fce3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fce5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fce7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fce8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fce9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fced: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fcf0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fcf2: 7c54 JL 0x0064fd48
    if(integer::condition("JL",flags)) goto L0064fd48;
  }
  { // 0x64fcf4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fcf8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fcfa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fcfc: 7e48 JLE 0x0064fd46
    if(integer::condition("JLE",flags)) goto L0064fd46;
  }
  L0064fcfe: { // 0x64fcfe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fd01: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fd09: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fd0d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fd10: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fd11: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fd16: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fd17: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fd19: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fd1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fd1d: 7c29 JL 0x0064fd48
    if(integer::condition("JL",flags)) goto L0064fd48;
  }
  { // 0x64fd1f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fd23: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fd24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fd25: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fd2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fd2d: 7c19 JL 0x0064fd48
    if(integer::condition("JL",flags)) goto L0064fd48;
  }
  { // 0x64fd2f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fd33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fd34: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fd36: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fd39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fd3b: 7c0b JL 0x0064fd48
    if(integer::condition("JL",flags)) goto L0064fd48;
  }
  { // 0x64fd3d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fd41: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fd42: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fd44: 7cb8 JL 0x0064fcfe
    if(integer::condition("JL",flags)) goto L0064fcfe;
  }
  L0064fd46: { // 0x64fd46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fd48: { // 0x64fd48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fd49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fd4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fd4b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fd4e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fd50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fd50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fd53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fd54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fd55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fd56: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fd58: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fd5a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fd5c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fd5f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fd63: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fd65: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fd67: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fd68: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fd69: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fd6d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fd70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fd72: 7c54 JL 0x0064fdc8
    if(integer::condition("JL",flags)) goto L0064fdc8;
  }
  { // 0x64fd74: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fd78: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fd7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fd7c: 7e48 JLE 0x0064fdc6
    if(integer::condition("JLE",flags)) goto L0064fdc6;
  }
  L0064fd7e: { // 0x64fd7e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fd81: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fd89: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fd8d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fd90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fd91: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fd96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fd97: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fd99: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fd9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fd9d: 7c29 JL 0x0064fdc8
    if(integer::condition("JL",flags)) goto L0064fdc8;
  }
  { // 0x64fd9f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fda3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fda4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fda5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fdab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fdad: 7c19 JL 0x0064fdc8
    if(integer::condition("JL",flags)) goto L0064fdc8;
  }
  { // 0x64fdaf: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fdb3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fdb4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fdb6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fdb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fdbb: 7c0b JL 0x0064fdc8
    if(integer::condition("JL",flags)) goto L0064fdc8;
  }
  { // 0x64fdbd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fdc1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fdc2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fdc4: 7cb8 JL 0x0064fd7e
    if(integer::condition("JL",flags)) goto L0064fd7e;
  }
  L0064fdc6: { // 0x64fdc6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fdc8: { // 0x64fdc8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fdc9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fdca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fdcb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fdce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fdd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fdd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fdd3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fdd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fdd5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fdd6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fdd8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fdda: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fddc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fddf: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fde3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fde5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fde7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fde8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fde9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fded: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fdf0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fdf2: 7c54 JL 0x0064fe48
    if(integer::condition("JL",flags)) goto L0064fe48;
  }
  { // 0x64fdf4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fdf8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fdfa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fdfc: 7e48 JLE 0x0064fe46
    if(integer::condition("JLE",flags)) goto L0064fe46;
  }
  L0064fdfe: { // 0x64fdfe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fe01: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fe09: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fe0d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fe10: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fe11: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fe16: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fe17: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fe19: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fe1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fe1d: 7c29 JL 0x0064fe48
    if(integer::condition("JL",flags)) goto L0064fe48;
  }
  { // 0x64fe1f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fe23: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fe24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fe25: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64fe2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fe2d: 7c19 JL 0x0064fe48
    if(integer::condition("JL",flags)) goto L0064fe48;
  }
  { // 0x64fe2f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fe33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fe34: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fe36: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64fe39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fe3b: 7c0b JL 0x0064fe48
    if(integer::condition("JL",flags)) goto L0064fe48;
  }
  { // 0x64fe3d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fe41: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fe42: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fe44: 7cb8 JL 0x0064fdfe
    if(integer::condition("JL",flags)) goto L0064fdfe;
  }
  L0064fe46: { // 0x64fe46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fe48: { // 0x64fe48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fe49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64fe4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fe4b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fe4e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fe50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fe50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fe53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fe54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fe55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fe56: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fe58: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64fe5a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fe5c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fe5f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fe63: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fe65: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fe67: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fe68: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fe69: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64fe6d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fe70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fe72: 7c54 JL 0x0064fec8
    if(integer::condition("JL",flags)) goto L0064fec8;
  }
  { // 0x64fe74: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fe78: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fe7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fe7c: 7e48 JLE 0x0064fec6
    if(integer::condition("JLE",flags)) goto L0064fec6;
  }
  L0064fe7e: { // 0x64fe7e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64fe81: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64fe89: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64fe8d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64fe90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fe91: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64fe96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fe97: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64fe99: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64fe9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fe9d: 7c29 JL 0x0064fec8
    if(integer::condition("JL",flags)) goto L0064fec8;
  }
  { // 0x64fe9f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64fea3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fea4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64fea5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64feab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fead: 7c19 JL 0x0064fec8
    if(integer::condition("JL",flags)) goto L0064fec8;
  }
  { // 0x64feaf: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64feb3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64feb4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64feb6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64feb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64febb: 7c0b JL 0x0064fec8
    if(integer::condition("JL",flags)) goto L0064fec8;
  }
  { // 0x64febd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fec1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64fec2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64fec4: 7cb8 JL 0x0064fe7e
    if(integer::condition("JL",flags)) goto L0064fe7e;
  }
  L0064fec6: { // 0x64fec6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064fec8: { // 0x64fec8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64fec9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64feca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64fecb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fece: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024fed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64fed0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64fed3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fed4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64fed5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64fed6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64fed8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64feda: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64fedc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64fedf: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64fee3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64fee5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64fee7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64fee8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64fee9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64feed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fef0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fef2: 7c54 JL 0x0064ff48
    if(integer::condition("JL",flags)) goto L0064ff48;
  }
  { // 0x64fef4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fef8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fefa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fefc: 7e48 JLE 0x0064ff46
    if(integer::condition("JLE",flags)) goto L0064ff46;
  }
  L0064fefe: { // 0x64fefe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64ff01: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64ff09: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64ff0d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64ff10: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64ff11: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64ff16: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ff17: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64ff19: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64ff1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ff1d: 7c29 JL 0x0064ff48
    if(integer::condition("JL",flags)) goto L0064ff48;
  }
  { // 0x64ff1f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64ff23: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64ff24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ff25: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64ff2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ff2d: 7c19 JL 0x0064ff48
    if(integer::condition("JL",flags)) goto L0064ff48;
  }
  { // 0x64ff2f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64ff33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ff34: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64ff36: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64ff39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ff3b: 7c0b JL 0x0064ff48
    if(integer::condition("JL",flags)) goto L0064ff48;
  }
  { // 0x64ff3d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64ff41: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64ff42: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64ff44: 7cb8 JL 0x0064fefe
    if(integer::condition("JL",flags)) goto L0064fefe;
  }
  L0064ff46: { // 0x64ff46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064ff48: { // 0x64ff48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64ff49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64ff4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64ff4b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64ff4e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024ff50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64ff50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64ff53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64ff54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64ff55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64ff56: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64ff58: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64ff5a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64ff5c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64ff5f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64ff63: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64ff65: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64ff67: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64ff68: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64ff69: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64ff6d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64ff70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ff72: 7c54 JL 0x0064ffc8
    if(integer::condition("JL",flags)) goto L0064ffc8;
  }
  { // 0x64ff74: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64ff78: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64ff7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ff7c: 7e48 JLE 0x0064ffc6
    if(integer::condition("JLE",flags)) goto L0064ffc6;
  }
  L0064ff7e: { // 0x64ff7e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x64ff81: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x64ff89: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x64ff8d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x64ff90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64ff91: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x64ff96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ff97: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64ff99: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64ff9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ff9d: 7c29 JL 0x0064ffc8
    if(integer::condition("JL",flags)) goto L0064ffc8;
  }
  { // 0x64ff9f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64ffa3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64ffa4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ffa5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x64ffab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ffad: 7c19 JL 0x0064ffc8
    if(integer::condition("JL",flags)) goto L0064ffc8;
  }
  { // 0x64ffaf: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64ffb3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ffb4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x64ffb6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x64ffb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ffbb: 7c0b JL 0x0064ffc8
    if(integer::condition("JL",flags)) goto L0064ffc8;
  }
  { // 0x64ffbd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64ffc1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x64ffc2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x64ffc4: 7cb8 JL 0x0064ff7e
    if(integer::condition("JL",flags)) goto L0064ff7e;
  }
  L0064ffc6: { // 0x64ffc6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0064ffc8: { // 0x64ffc8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64ffc9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64ffca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64ffcb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x64ffce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64ffd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x64ffd3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64ffd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64ffd5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64ffd6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x64ffd8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x64ffda: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x64ffdc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x64ffdf: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x64ffe3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x64ffe5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x64ffe7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64ffe8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x64ffe9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x64ffed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64fff0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fff2: 7c54 JL 0x00650048
    if(integer::condition("JL",flags)) goto L00650048;
  }
  { // 0x64fff4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x64fff8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64fffa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64fffc: 7e48 JLE 0x00650046
    if(integer::condition("JLE",flags)) goto L00650046;
  }
  L0064fffe: { // 0x64fffe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x650001: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x650009: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x65000d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x650010: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650011: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x650016: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650017: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650019: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65001b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65001d: 7c29 JL 0x00650048
    if(integer::condition("JL",flags)) goto L00650048;
  }
  { // 0x65001f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x650023: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x650024: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650025: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x65002b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65002d: 7c19 JL 0x00650048
    if(integer::condition("JL",flags)) goto L00650048;
  }
  { // 0x65002f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x650033: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650034: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650036: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x650039: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65003b: 7c0b JL 0x00650048
    if(integer::condition("JL",flags)) goto L00650048;
  }
  { // 0x65003d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x650041: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x650042: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x650044: 7cb8 JL 0x0064fffe
    if(integer::condition("JL",flags)) goto L0064fffe;
  }
  L00650046: { // 0x650046: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00650048: { // 0x650048: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x650049: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65004a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65004b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65004e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00250050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x650050: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x650053: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x650054: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x650055: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x650056: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x650058: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x65005a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x65005c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x65005f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x650063: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x650065: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x650067: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650068: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x650069: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x65006d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x650070: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x650072: 7c54 JL 0x006500c8
    if(integer::condition("JL",flags)) goto L006500c8;
  }
  { // 0x650074: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x650078: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x65007a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65007c: 7e48 JLE 0x006500c6
    if(integer::condition("JLE",flags)) goto L006500c6;
  }
  L0065007e: { // 0x65007e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x650081: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x650089: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x65008d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x650090: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650091: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x650096: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650097: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650099: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65009b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65009d: 7c29 JL 0x006500c8
    if(integer::condition("JL",flags)) goto L006500c8;
  }
  { // 0x65009f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6500a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6500a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6500a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6500ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6500ad: 7c19 JL 0x006500c8
    if(integer::condition("JL",flags)) goto L006500c8;
  }
  { // 0x6500af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6500b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6500b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6500b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6500b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6500bb: 7c0b JL 0x006500c8
    if(integer::condition("JL",flags)) goto L006500c8;
  }
  { // 0x6500bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x6500c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6500c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6500c4: 7cb8 JL 0x0065007e
    if(integer::condition("JL",flags)) goto L0065007e;
  }
  L006500c6: { // 0x6500c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006500c8: { // 0x6500c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6500c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6500ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6500cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6500ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002500d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6500d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6500d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6500d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6500d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6500d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x6500d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6500da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6500dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x6500df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x6500e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x6500e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x6500e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6500e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6500e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x6500ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6500f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6500f2: 7c54 JL 0x00650148
    if(integer::condition("JL",flags)) goto L00650148;
  }
  { // 0x6500f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x6500f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6500fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6500fc: 7e48 JLE 0x00650146
    if(integer::condition("JLE",flags)) goto L00650146;
  }
  L006500fe: { // 0x6500fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x650101: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x650109: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x65010d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x650110: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650111: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x650116: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650117: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650119: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65011b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65011d: 7c29 JL 0x00650148
    if(integer::condition("JL",flags)) goto L00650148;
  }
  { // 0x65011f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x650123: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x650124: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650125: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x65012b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65012d: 7c19 JL 0x00650148
    if(integer::condition("JL",flags)) goto L00650148;
  }
  { // 0x65012f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x650133: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650134: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650136: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x650139: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65013b: 7c0b JL 0x00650148
    if(integer::condition("JL",flags)) goto L00650148;
  }
  { // 0x65013d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x650141: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x650142: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x650144: 7cb8 JL 0x006500fe
    if(integer::condition("JL",flags)) goto L006500fe;
  }
  L00650146: { // 0x650146: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00650148: { // 0x650148: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x650149: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65014a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65014b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65014e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00250150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x650150: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x650153: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x650154: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x650155: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x650156: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x650158: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x65015a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x65015c: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x65015f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x650163: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x650165: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x650167: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650168: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x650169: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x65016d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x650170: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x650172: 7c54 JL 0x006501c8
    if(integer::condition("JL",flags)) goto L006501c8;
  }
  { // 0x650174: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x650178: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x65017a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65017c: 7e48 JLE 0x006501c6
    if(integer::condition("JLE",flags)) goto L006501c6;
  }
  L0065017e: { // 0x65017e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x650181: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x650189: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x65018d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x650190: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650191: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x650196: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650197: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650199: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65019b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65019d: 7c29 JL 0x006501c8
    if(integer::condition("JL",flags)) goto L006501c8;
  }
  { // 0x65019f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6501a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6501a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6501a5: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6501ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6501ad: 7c19 JL 0x006501c8
    if(integer::condition("JL",flags)) goto L006501c8;
  }
  { // 0x6501af: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6501b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6501b4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6501b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6501b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6501bb: 7c0b JL 0x006501c8
    if(integer::condition("JL",flags)) goto L006501c8;
  }
  { // 0x6501bd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x6501c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6501c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6501c4: 7cb8 JL 0x0065017e
    if(integer::condition("JL",flags)) goto L0065017e;
  }
  L006501c6: { // 0x6501c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006501c8: { // 0x6501c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6501c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6501ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6501cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6501ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002501d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6501d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6501d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6501d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6501d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6501d6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x6501d8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6501da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6501dc: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x6501df: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x6501e3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x6501e5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x6501e7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6501e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6501e9: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x6501ed: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6501f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6501f2: 7c54 JL 0x00650248
    if(integer::condition("JL",flags)) goto L00650248;
  }
  { // 0x6501f4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x6501f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6501fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6501fc: 7e48 JLE 0x00650246
    if(integer::condition("JLE",flags)) goto L00650246;
  }
  L006501fe: { // 0x6501fe: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x650201: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x650209: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x65020d: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x650210: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650211: 68e8aa7900 PUSH 0x79aae8
    f.push(m,0x0079aae8u);
  }
  { // 0x650216: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650217: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650219: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65021b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65021d: 7c29 JL 0x00650248
    if(integer::condition("JL",flags)) goto L00650248;
  }
  { // 0x65021f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x650223: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x650224: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650225: ff15e8557800 CALL dword ptr [0x007855e8]
    const std::uint32_t call_target=m.r32((0x007855e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x65022b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65022d: 7c19 JL 0x00650248
    if(integer::condition("JL",flags)) goto L00650248;
  }
  { // 0x65022f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x650233: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650234: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650236: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x650239: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65023b: 7c0b JL 0x00650248
    if(integer::condition("JL",flags)) goto L00650248;
  }
  { // 0x65023d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x650241: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x650242: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x650244: 7cb8 JL 0x006501fe
    if(integer::condition("JL",flags)) goto L006501fe;
  }
  L00650246: { // 0x650246: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00650248: { // 0x650248: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x650249: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65024a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65024b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65024e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00253490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x653490: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x653495: 80b80623000001 CMP byte ptr [EAX + 0x2306],0x1
    (void)integer::sub(m.r8((s.ax+0x00002306u)),0x00000001u,8,flags);
  }
  { // 0x65349c: 7529 JNZ 0x006534c7
    if(integer::condition("JNZ",flags)) goto L006534c7;
  }
  { // 0x65349e: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x6534a4: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6534a6: ff5228 CALL dword ptr [EDX + 0x28]
    const std::uint32_t call_target=m.r32((s.dx+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6534a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6534ab: 741a JZ 0x006534c7
    if(integer::condition("JZ",flags)) goto L006534c7;
  }
  L006534ad: { // 0x6534ad: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x6534b3: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6534b5: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6534b8: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x6534be: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6534c0: ff5228 CALL dword ptr [EDX + 0x28]
    const std::uint32_t call_target=m.r32((s.dx+0x00000028u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6534c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6534c5: 75e6 JNZ 0x006534ad
    if(integer::condition("JNZ",flags)) goto L006534ad;
  }
  L006534c7: { // 0x6534c7: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x6534cc: c6800623000000 MOV byte ptr [EAX + 0x2306],0x0
    m.w8((s.ax+0x00002306u), 0x00000000u);
  }
  { // 0x6534d3: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x6534d9: c6058489a20000 MOV byte ptr [0x00a28984],0x0
    m.w8((0x00a28984u), 0x00000000u);
  }
  { // 0x6534e0: e86bd7edff CALL 0x00530c50
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6534e5: c7057c0caa0000000000 MOV dword ptr [0x00aa0c7c],0x0
    m.w32((0x00aa0c7cu), 0x00000000u);
  }
  { // 0x6534ef: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0025ace0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65ace0: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  { // 0x65ace5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x65ace6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65ace7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x65ace9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65acea: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x65acec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65acee: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x65acf0: 7e37 JLE 0x0065ad29
    if(integer::condition("JLE",flags)) goto L0065ad29;
  }
  { // 0x65acf2: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  L0065acf7: { // 0x65acf7: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x65acfa: 8b8804030000 MOV ECX,dword ptr [EAX + 0x304]
    s.cx = m.r32((s.ax+0x00000304u));
  }
  { // 0x65ad00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65ad01: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x65ad02: e8592b1100 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65ad07: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65ad0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65ad0c: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  { // 0x65ad11: 750b JNZ 0x0065ad1e
    if(integer::condition("JNZ",flags)) goto L0065ad1e;
  }
  { // 0x65ad13: 8b14b0 MOV EDX,dword ptr [EAX + ESI*0x4]
    s.dx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x65ad16: 39ba10030000 CMP dword ptr [EDX + 0x310],EDI
    (void)integer::sub(m.r32((s.dx+0x00000310u)),s.di,32,flags);
  }
  { // 0x65ad1c: 7411 JZ 0x0065ad2f
    if(integer::condition("JZ",flags)) goto L0065ad2f;
  }
  L0065ad1e: { // 0x65ad1e: 8b0d10eaa900 MOV ECX,dword ptr [0x00a9ea10]
    s.cx = m.r32((0x00a9ea10u));
  }
  { // 0x65ad24: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x65ad25: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x65ad27: 7cce JL 0x0065acf7
    if(integer::condition("JL",flags)) goto L0065acf7;
  }
  L0065ad29: { // 0x65ad29: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65ad2a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65ad2b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x65ad2d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65ad2e: c3 RET
    finish(m,s,f,0u); return;
  }
  L0065ad2f: { // 0x65ad2f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x65ad31: 7cf6 JL 0x0065ad29
    if(integer::condition("JL",flags)) goto L0065ad29;
  }
  { // 0x65ad33: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x65ad36: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65ad37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65ad38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65ad39: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0025ad40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65ad40: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  { // 0x65ad45: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x65ad46: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65ad47: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x65ad49: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65ad4a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x65ad4c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65ad4e: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x65ad50: 7e37 JLE 0x0065ad89
    if(integer::condition("JLE",flags)) goto L0065ad89;
  }
  { // 0x65ad52: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  L0065ad57: { // 0x65ad57: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x65ad5a: 8b8804030000 MOV ECX,dword ptr [EAX + 0x304]
    s.cx = m.r32((s.ax+0x00000304u));
  }
  { // 0x65ad60: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65ad61: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x65ad62: e8f92a1100 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65ad67: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65ad6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65ad6c: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  { // 0x65ad71: 750b JNZ 0x0065ad7e
    if(integer::condition("JNZ",flags)) goto L0065ad7e;
  }
  { // 0x65ad73: 8b14b0 MOV EDX,dword ptr [EAX + ESI*0x4]
    s.dx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x65ad76: 39ba10030000 CMP dword ptr [EDX + 0x310],EDI
    (void)integer::sub(m.r32((s.dx+0x00000310u)),s.di,32,flags);
  }
  { // 0x65ad7c: 7412 JZ 0x0065ad90
    if(integer::condition("JZ",flags)) goto L0065ad90;
  }
  L0065ad7e: { // 0x65ad7e: 8b0d10eaa900 MOV ECX,dword ptr [0x00a9ea10]
    s.cx = m.r32((0x00a9ea10u));
  }
  { // 0x65ad84: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x65ad85: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x65ad87: 7cce JL 0x0065ad57
    if(integer::condition("JL",flags)) goto L0065ad57;
  }
  L0065ad89: { // 0x65ad89: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65ad8a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65ad8b: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x65ad8e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65ad8f: c3 RET
    finish(m,s,f,0u); return;
  }
  L0065ad90: { // 0x65ad90: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x65ad92: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65ad93: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65ad94: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65ad95: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0025fe60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65fe60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65fe61: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65fe62: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x65fe64: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x65fe66: 7448 JZ 0x0065feb0
    if(integer::condition("JZ",flags)) goto L0065feb0;
  }
  { // 0x65fe68: a198e58400 MOV EAX,[0x0084e598]
    s.ax = m.r32((0x0084e598u));
  }
  { // 0x65fe6d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x65fe6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65fe71: 7e3d JLE 0x0065feb0
    if(integer::condition("JLE",flags)) goto L0065feb0;
  }
  L0065fe73: { // 0x65fe73: a18ce58400 MOV EAX,[0x0084e58c]
    s.ax = m.r32((0x0084e58cu));
  }
  { // 0x65fe78: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x65fe7b: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x65fe7e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65fe7f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65fe80: e8dbd91000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65fe85: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65fe88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65fe8a: 7429 JZ 0x0065feb5
    if(integer::condition("JZ",flags)) goto L0065feb5;
  }
  { // 0x65fe8c: 8b158ce58400 MOV EDX,dword ptr [0x0084e58c]
    s.dx = m.r32((0x0084e58cu));
  }
  { // 0x65fe92: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x65fe95: 83c064 ADD EAX,0x64
    s.ax = integer::add(s.ax,0x00000064u,32,flags);
  }
  { // 0x65fe98: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65fe99: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65fe9a: e8c1d91000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65fe9f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65fea2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65fea4: 740f JZ 0x0065feb5
    if(integer::condition("JZ",flags)) goto L0065feb5;
  }
  { // 0x65fea6: a198e58400 MOV EAX,[0x0084e598]
    s.ax = m.r32((0x0084e598u));
  }
  { // 0x65feab: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x65feac: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x65feae: 7cc3 JL 0x0065fe73
    if(integer::condition("JL",flags)) goto L0065fe73;
  }
  L0065feb0: { // 0x65feb0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65feb1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x65feb3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65feb4: c3 RET
    finish(m,s,f,0u); return;
  }
  L0065feb5: { // 0x65feb5: 8b0d8ce58400 MOV ECX,dword ptr [0x0084e58c]
    s.cx = m.r32((0x0084e58cu));
  }
  { // 0x65febb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65febc: 8b04b1 MOV EAX,dword ptr [ECX + ESI*0x4]
    s.ax = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x65febf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65fec0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0025fed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65fed0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65fed1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65fed2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x65fed4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x65fed6: 742e JZ 0x0065ff06
    if(integer::condition("JZ",flags)) goto L0065ff06;
  }
  { // 0x65fed8: a198e58400 MOV EAX,[0x0084e598]
    s.ax = m.r32((0x0084e598u));
  }
  { // 0x65fedd: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x65fedf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65fee1: 7e23 JLE 0x0065ff06
    if(integer::condition("JLE",flags)) goto L0065ff06;
  }
  L0065fee3: { // 0x65fee3: a18ce58400 MOV EAX,[0x0084e58c]
    s.ax = m.r32((0x0084e58cu));
  }
  { // 0x65fee8: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x65feeb: 83c164 ADD ECX,0x64
    s.cx = integer::add(s.cx,0x00000064u,32,flags);
  }
  { // 0x65feee: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65feef: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65fef0: e86bd91000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65fef5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x65fef8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65fefa: 740f JZ 0x0065ff0b
    if(integer::condition("JZ",flags)) goto L0065ff0b;
  }
  { // 0x65fefc: a198e58400 MOV EAX,[0x0084e598]
    s.ax = m.r32((0x0084e598u));
  }
  { // 0x65ff01: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x65ff02: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x65ff04: 7cdd JL 0x0065fee3
    if(integer::condition("JL",flags)) goto L0065fee3;
  }
  L0065ff06: { // 0x65ff06: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65ff07: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x65ff09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65ff0a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0065ff0b: { // 0x65ff0b: 8b158ce58400 MOV EDX,dword ptr [0x0084e58c]
    s.dx = m.r32((0x0084e58cu));
  }
  { // 0x65ff11: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65ff12: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x65ff15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65ff16: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002655b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6655b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6655b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6655b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6655b3: 8db1d0280000 LEA ESI,[ECX + 0x28d0]
    s.si = (s.cx+0x000028d0u);
  }
  { // 0x6655b9: bff8cc7d00 MOV EDI,0x7dccf8
    s.di = 0x007dccf8u;
  }
  L006655be: { // 0x6655be: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x6655c0: 68f8010000 PUSH 0x1f8
    f.push(m,0x000001f8u);
  }
  { // 0x6655c5: 68b4ce7d00 PUSH 0x7dceb4
    f.push(m,0x007dceb4u);
  }
  { // 0x6655ca: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6655cc: e88f950800 CALL 0x006eeb60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6655d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6655d2: e88cd31100 CALL 0x00782963
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6655d7: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x6655da: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x6655dc: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x6655df: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6655e2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x6655e4: 7c22 JL 0x00665608
    if(integer::condition("JL",flags)) goto L00665608;
  }
  { // 0x6655e6: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  { // 0x6655e9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6655eb: 7504 JNZ 0x006655f1
    if(integer::condition("JNZ",flags)) goto L006655f1;
  }
  { // 0x6655ed: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6655ef: 7526 JNZ 0x00665617
    if(integer::condition("JNZ",flags)) goto L00665617;
  }
  L006655f1: { // 0x6655f1: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x6655f4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6655f6: 7e1f JLE 0x00665617
    if(integer::condition("JLE",flags)) goto L00665617;
  }
  { // 0x6655f8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6655fa: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x6655fc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6655fe: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6655ff: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x665601: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x665604: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x665606: 740f JZ 0x00665617
    if(integer::condition("JZ",flags)) goto L00665617;
  }
  L00665608: { // 0x665608: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x66560b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x66560e: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x665611: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x665614: 891c82 MOV dword ptr [EDX + EAX*0x4],EBX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.bx);
  }
  L00665617: { // 0x665617: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  { // 0x66561a: 81ff08cd7d00 CMP EDI,0x7dcd08
    (void)integer::sub(s.di,0x007dcd08u,32,flags);
  }
  { // 0x665620: 7c9c JL 0x006655be
    if(integer::condition("JL",flags)) goto L006655be;
  }
  { // 0x665622: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x665623: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x665624: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x665625: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00268390(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x668390: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x668391: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668392: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x668393: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x668395: 8b87b4010000 MOV EAX,dword ptr [EDI + 0x1b4]
    s.ax = m.r32((s.di+0x000001b4u));
  }
  { // 0x66839b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x66839d: 7514 JNZ 0x006683b3
    if(integer::condition("JNZ",flags)) goto L006683b3;
  }
  { // 0x66839f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6683a3: 686cd57d00 PUSH 0x7dd56c
    f.push(m,0x007dd56cu);
  }
  { // 0x6683a8: e8930f0f00 CALL 0x00759340
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6683ad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6683ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6683af: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6683b0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006683b3: { // 0x6683b3: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6683b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6683b7: 7e24 JLE 0x006683dd
    if(integer::condition("JLE",flags)) goto L006683dd;
  }
  { // 0x6683b9: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L006683bd: { // 0x6683bd: 8b87a8010000 MOV EAX,dword ptr [EDI + 0x1a8]
    s.ax = m.r32((s.di+0x000001a8u));
  }
  { // 0x6683c3: 8d0cb0 LEA ECX,[EAX + ESI*0x4]
    s.cx = (s.ax+(s.si * 0x00000004u));
  }
  { // 0x6683c6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6683c7: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6683c9: e8e20f0f00 CALL 0x007593b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6683ce: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6683d0: 7513 JNZ 0x006683e5
    if(integer::condition("JNZ",flags)) goto L006683e5;
  }
  { // 0x6683d2: 8b87b4010000 MOV EAX,dword ptr [EDI + 0x1b4]
    s.ax = m.r32((s.di+0x000001b4u));
  }
  { // 0x6683d8: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6683d9: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6683db: 7ce0 JL 0x006683bd
    if(integer::condition("JL",flags)) goto L006683bd;
  }
  L006683dd: { // 0x6683dd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6683de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6683df: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6683e1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6683e2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006683e5: { // 0x6683e5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6683e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6683e7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6683e9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6683ea: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00268bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x668bf0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x668bf1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x668bf2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668bf3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x668bf4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x668bf6: bdfeffffff MOV EBP,0xfffffffe
    s.bp = 0xfffffffeu;
  }
  L00668bfb: { // 0x668bfb: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x668c00: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  { // 0x668c02: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x668c04: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  { // 0x668c0a: e83172fcff CALL 0x0062fe40
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x668c0f: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x668c11: 7447 JZ 0x00668c5a
    if(integer::condition("JZ",flags)) goto L00668c5a;
  }
  { // 0x668c13: 8bbbf0270000 MOV EDI,dword ptr [EBX + 0x27f0]
    s.di = m.r32((s.bx+0x000027f0u));
  }
  { // 0x668c19: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x668c1b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x668c1d: 7e26 JLE 0x00668c45
    if(integer::condition("JLE",flags)) goto L00668c45;
  }
  { // 0x668c1f: 8bb3e4270000 MOV ESI,dword ptr [EBX + 0x27e4]
    s.si = m.r32((s.bx+0x000027e4u));
  }
  L00668c25: { // 0x668c25: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x668c27: 396955 CMP dword ptr [ECX + 0x55],EBP
    (void)integer::sub(m.r32((s.cx+0x00000055u)),s.bp,32,flags);
  }
  { // 0x668c2a: 750a JNZ 0x00668c36
    if(integer::condition("JNZ",flags)) goto L00668c36;
  }
  { // 0x668c2c: 837951ff CMP dword ptr [ECX + 0x51],-0x1
    (void)integer::sub(m.r32((s.cx+0x00000051u)),0xffffffffu,32,flags);
  }
  { // 0x668c30: 7504 JNZ 0x00668c36
    if(integer::condition("JNZ",flags)) goto L00668c36;
  }
  { // 0x668c32: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x668c34: eb03 JMP 0x00668c39
    goto L00668c39;
  }
  L00668c36: { // 0x668c36: 8b4951 MOV ECX,dword ptr [ECX + 0x51]
    s.cx = m.r32((s.cx+0x00000051u));
  }
  L00668c39: { // 0x668c39: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x668c3b: 74be JZ 0x00668bfb
    if(integer::condition("JZ",flags)) goto L00668bfb;
  }
  { // 0x668c3d: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x668c3e: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x668c41: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x668c43: 7ce0 JL 0x00668c25
    if(integer::condition("JL",flags)) goto L00668c25;
  }
  L00668c45: { // 0x668c45: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x668c47: 8d9384000000 LEA EDX,[EBX + 0x84]
    s.dx = (s.bx+0x00000084u);
  }
  L00668c4d: { // 0x668c4d: 3902 CMP dword ptr [EDX],EAX
    (void)integer::sub(m.r32((s.dx)),s.ax,32,flags);
  }
  { // 0x668c4f: 74aa JZ 0x00668bfb
    if(integer::condition("JZ",flags)) goto L00668bfb;
  }
  { // 0x668c51: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x668c52: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  { // 0x668c55: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  { // 0x668c58: 7cf3 JL 0x00668c4d
    if(integer::condition("JL",flags)) goto L00668c4d;
  }
  L00668c5a: { // 0x668c5a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x668c5b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668c5c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x668c5d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x668c5e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002691b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6691b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6691b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6691b3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6691b5: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6691b8: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x6691bb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6691bd: 743b JZ 0x006691fa
    if(integer::condition("JZ",flags)) goto L006691fa;
  }
  { // 0x6691bf: 8a560d MOV DL,byte ptr [ESI + 0xd]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000000du)));
  }
  { // 0x6691c2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x6691c4: 7434 JZ 0x006691fa
    if(integer::condition("JZ",flags)) goto L006691fa;
  }
  { // 0x6691c6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6691c8: 742d JZ 0x006691f7
    if(integer::condition("JZ",flags)) goto L006691f7;
  }
  { // 0x6691ca: 8b48fc MOV ECX,dword ptr [EAX + -0x4]
    s.cx = m.r32((s.ax-0x00000004u));
  }
  { // 0x6691cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6691ce: 8d58fc LEA EBX,[EAX + -0x4]
    s.bx = (s.ax-0x00000004u);
  }
  { // 0x6691d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6691d2: 8d3c88 LEA EDI,[EAX + ECX*0x4]
    s.di = (s.ax+(s.cx * 0x00000004u));
  }
  { // 0x6691d5: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x6691d6: 7812 JS 0x006691ea
    if(integer::condition("JS",flags)) goto L006691ea;
  }
  { // 0x6691d8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6691d9: 8d6901 LEA EBP,[ECX + 0x1]
    s.bp = (s.cx+0x00000001u);
  }
  L006691dc: { // 0x6691dc: 83ef04 SUB EDI,0x4
    s.di = integer::sub(s.di,0x00000004u,32,flags);
  }
  { // 0x6691df: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6691e1: e83a010f00 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6691e6: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  { // 0x6691e7: 75f3 JNZ 0x006691dc
    if(integer::condition("JNZ",flags)) goto L006691dc;
  }
  { // 0x6691e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006691ea: { // 0x6691ea: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6691eb: e88b441000 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6691f0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6691f3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6691f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6691f6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006691f7: { // 0x6691f7: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L006691fa: { // 0x6691fa: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x6691fe: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x669201: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x669202: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00269620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x669620: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x669621: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x669625: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x669626: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x669627: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x669629: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  { // 0x66962c: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x66962f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x669631: 7531 JNZ 0x00669664
    if(integer::condition("JNZ",flags)) goto L00669664;
  }
  { // 0x669633: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x669635: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x669637: 7e23 JLE 0x0066965c
    if(integer::condition("JLE",flags)) goto L0066965c;
  }
  L00669639: { // 0x669639: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x66963c: 8d04b500000000 LEA EAX,[ESI*0x4 + 0x0]
    s.ax = ((s.si * 0x00000004u)+0x00000000u);
  }
  { // 0x669643: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x669645: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x669646: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x669649: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x66964b: e840fe0e00 CALL 0x00759490
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x669650: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x669652: 7510 JNZ 0x00669664
    if(integer::condition("JNZ",flags)) goto L00669664;
  }
  { // 0x669654: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x669657: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x669658: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x66965a: 7cdd JL 0x00669639
    if(integer::condition("JL",flags)) goto L00669639;
  }
  L0066965c: { // 0x66965c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x66965d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66965e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x669660: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x669661: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00669664: { // 0x669664: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x669665: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x669666: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x669668: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x669669: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
} // namespace
const std::array<Entry,118>& entries_b() {
  static const std::array<Entry,118> entries{{
    {0x165440u,f_00165440},
    {0x16b680u,f_0016b680},
    {0x16b700u,f_0016b700},
    {0x182040u,f_00182040},
    {0x185180u,f_00185180},
    {0x191de0u,f_00191de0},
    {0x19a6f0u,f_0019a6f0},
    {0x19a8c0u,f_0019a8c0},
    {0x1a4070u,f_001a4070},
    {0x1afb10u,f_001afb10},
    {0x1b2110u,f_001b2110},
    {0x1b2770u,f_001b2770},
    {0x1b4150u,f_001b4150},
    {0x1b4280u,f_001b4280},
    {0x1b6c30u,f_001b6c30},
    {0x1b6cb0u,f_001b6cb0},
    {0x1bd730u,f_001bd730},
    {0x1bd780u,f_001bd780},
    {0x1c2a60u,f_001c2a60},
    {0x1c2aa0u,f_001c2aa0},
    {0x1c2d20u,f_001c2d20},
    {0x1c2f10u,f_001c2f10},
    {0x1c8fb0u,f_001c8fb0},
    {0x1d29e0u,f_001d29e0},
    {0x1d2a70u,f_001d2a70},
    {0x1d4e30u,f_001d4e30},
    {0x1d61c0u,f_001d61c0},
    {0x1d6960u,f_001d6960},
    {0x1f7ff0u,f_001f7ff0},
    {0x1f8490u,f_001f8490},
    {0x1f8a50u,f_001f8a50},
    {0x1f9140u,f_001f9140},
    {0x1fa640u,f_001fa640},
    {0x1fa940u,f_001fa940},
    {0x1faaf0u,f_001faaf0},
    {0x1facb0u,f_001facb0},
    {0x1fad90u,f_001fad90},
    {0x1faf00u,f_001faf00},
    {0x1fcca0u,f_001fcca0},
    {0x1fcd00u,f_001fcd00},
    {0x1fcfa0u,f_001fcfa0},
    {0x1fd130u,f_001fd130},
    {0x1fd600u,f_001fd600},
    {0x1fd910u,f_001fd910},
    {0x203040u,f_00203040},
    {0x205550u,f_00205550},
    {0x2060a0u,f_002060a0},
    {0x209310u,f_00209310},
    {0x209ac0u,f_00209ac0},
    {0x20bed0u,f_0020bed0},
    {0x20c1c0u,f_0020c1c0},
    {0x212280u,f_00212280},
    {0x2122d0u,f_002122d0},
    {0x216db0u,f_00216db0},
    {0x218940u,f_00218940},
    {0x219990u,f_00219990},
    {0x219c20u,f_00219c20},
    {0x22e190u,f_0022e190},
    {0x22e2c0u,f_0022e2c0},
    {0x232e10u,f_00232e10},
    {0x232e90u,f_00232e90},
    {0x2330d0u,f_002330d0},
    {0x233b30u,f_00233b30},
    {0x234c20u,f_00234c20},
    {0x249ac0u,f_00249ac0},
    {0x249b40u,f_00249b40},
    {0x249c20u,f_00249c20},
    {0x249ca0u,f_00249ca0},
    {0x249d20u,f_00249d20},
    {0x249e90u,f_00249e90},
    {0x249ee0u,f_00249ee0},
    {0x249f60u,f_00249f60},
    {0x249fe0u,f_00249fe0},
    {0x24bce0u,f_0024bce0},
    {0x24f150u,f_0024f150},
    {0x24f1d0u,f_0024f1d0},
    {0x24f250u,f_0024f250},
    {0x24f2d0u,f_0024f2d0},
    {0x24f350u,f_0024f350},
    {0x24f3d0u,f_0024f3d0},
    {0x24f450u,f_0024f450},
    {0x24f4d0u,f_0024f4d0},
    {0x24f550u,f_0024f550},
    {0x24f5d0u,f_0024f5d0},
    {0x24f650u,f_0024f650},
    {0x24f6d0u,f_0024f6d0},
    {0x24f750u,f_0024f750},
    {0x24f7d0u,f_0024f7d0},
    {0x24f850u,f_0024f850},
    {0x24f8d0u,f_0024f8d0},
    {0x24f950u,f_0024f950},
    {0x24f9d0u,f_0024f9d0},
    {0x24fa50u,f_0024fa50},
    {0x24fad0u,f_0024fad0},
    {0x24fb50u,f_0024fb50},
    {0x24fbd0u,f_0024fbd0},
    {0x24fc50u,f_0024fc50},
    {0x24fcd0u,f_0024fcd0},
    {0x24fd50u,f_0024fd50},
    {0x24fdd0u,f_0024fdd0},
    {0x24fe50u,f_0024fe50},
    {0x24fed0u,f_0024fed0},
    {0x24ff50u,f_0024ff50},
    {0x24ffd0u,f_0024ffd0},
    {0x250050u,f_00250050},
    {0x2500d0u,f_002500d0},
    {0x250150u,f_00250150},
    {0x2501d0u,f_002501d0},
    {0x253490u,f_00253490},
    {0x25ace0u,f_0025ace0},
    {0x25ad40u,f_0025ad40},
    {0x25fe60u,f_0025fe60},
    {0x25fed0u,f_0025fed0},
    {0x2655b0u,f_002655b0},
    {0x268390u,f_00268390},
    {0x268bf0u,f_00268bf0},
    {0x2691b0u,f_002691b0},
    {0x269620u,f_00269620},
  }}; return entries;
}
} // namespace ra2::recovered::loops_b36
