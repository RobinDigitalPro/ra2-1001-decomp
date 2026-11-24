#include "recovered/loops_b36_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::loops_b36 {
namespace {
void f_002697b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6697b0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6697b1: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6697b3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6697b5: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x6697b8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6697ba: 743b JZ 0x006697f7
    if(integer::condition("JZ",flags)) goto L006697f7;
  }
  { // 0x6697bc: 8a570d MOV DL,byte ptr [EDI + 0xd]
    s.dx = with_al(s.dx, m.r8((s.di+0x0000000du)));
  }
  { // 0x6697bf: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x6697c1: 7434 JZ 0x006697f7
    if(integer::condition("JZ",flags)) goto L006697f7;
  }
  { // 0x6697c3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6697c5: 742d JZ 0x006697f4
    if(integer::condition("JZ",flags)) goto L006697f4;
  }
  { // 0x6697c7: 8b48fc MOV ECX,dword ptr [EAX + -0x4]
    s.cx = m.r32((s.ax-0x00000004u));
  }
  { // 0x6697ca: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6697cb: 8d58fc LEA EBX,[EAX + -0x4]
    s.bx = (s.ax-0x00000004u);
  }
  { // 0x6697ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6697cf: 8d3488 LEA ESI,[EAX + ECX*0x4]
    s.si = (s.ax+(s.cx * 0x00000004u));
  }
  { // 0x6697d2: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x6697d3: 7812 JS 0x006697e7
    if(integer::condition("JS",flags)) goto L006697e7;
  }
  { // 0x6697d5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6697d6: 8d6901 LEA EBP,[ECX + 0x1]
    s.bp = (s.cx+0x00000001u);
  }
  L006697d9: { // 0x6697d9: 83ee04 SUB ESI,0x4
    s.si = integer::sub(s.si,0x00000004u,32,flags);
  }
  { // 0x6697dc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6697de: e83dfb0e00 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6697e3: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  { // 0x6697e4: 75f3 JNZ 0x006697d9
    if(integer::condition("JNZ",flags)) goto L006697d9;
  }
  { // 0x6697e6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006697e7: { // 0x6697e7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6697e8: e88e3e1000 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6697ed: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6697f0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6697f2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6697f3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006697f4: { // 0x6697f4: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
  L006697f7: { // 0x6697f7: c6470d00 MOV byte ptr [EDI + 0xd],0x0
    m.w8((s.di+0x0000000du), 0x00000000u);
  }
  { // 0x6697fb: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  { // 0x6697fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6697ff: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00269800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x669800: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x669801: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x669802: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x669803: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x669805: 8a470c MOV AL,byte ptr [EDI + 0xc]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000000cu)));
  }
  { // 0x669808: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x66980a: 7508 JNZ 0x00669814
    if(integer::condition("JNZ",flags)) goto L00669814;
  }
  { // 0x66980c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x66980d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66980e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x669810: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x669811: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00669814: { // 0x669814: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x669817: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x669819: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x66981b: 7e1c JLE 0x00669839
    if(integer::condition("JLE",flags)) goto L00669839;
  }
  { // 0x66981d: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00669821: { // 0x669821: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x669824: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x669825: 8d0cb0 LEA ECX,[EAX + ESI*0x4]
    s.cx = (s.ax+(s.si * 0x00000004u));
  }
  { // 0x669828: e883fb0e00 CALL 0x007593b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x66982d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x66982f: 7511 JNZ 0x00669842
    if(integer::condition("JNZ",flags)) goto L00669842;
  }
  { // 0x669831: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x669834: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x669835: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x669837: 7ce8 JL 0x00669821
    if(integer::condition("JL",flags)) goto L00669821;
  }
  L00669839: { // 0x669839: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x66983a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66983b: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x66983e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x66983f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00669842: { // 0x669842: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x669844: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x669845: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x669846: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x669847: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002699b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6699b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6699b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6699b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6699b3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6699b5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6699b7: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x6699ba: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6699bc: 7e1c JLE 0x006699da
    if(integer::condition("JLE",flags)) goto L006699da;
  }
  { // 0x6699be: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L006699c2: { // 0x6699c2: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x6699c5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6699c6: 8d0cb0 LEA ECX,[EAX + ESI*0x4]
    s.cx = (s.ax+(s.si * 0x00000004u));
  }
  { // 0x6699c9: e8e2f90e00 CALL 0x007593b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6699ce: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6699d0: 7511 JNZ 0x006699e3
    if(integer::condition("JNZ",flags)) goto L006699e3;
  }
  { // 0x6699d2: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x6699d5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6699d6: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6699d8: 7ce8 JL 0x006699c2
    if(integer::condition("JL",flags)) goto L006699c2;
  }
  L006699da: { // 0x6699da: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6699db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6699dc: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x6699df: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6699e0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006699e3: { // 0x6699e3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6699e5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6699e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6699e7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6699e8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0026a610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66a610: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66a611: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x66a613: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x66a617: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x66a61b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66a61c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x66a61d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x66a61f: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x66a622: e849ffffff CALL 0x0066a570
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x66a627: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x66a62b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x66a62d: 7456 JZ 0x0066a685
    if(integer::condition("JZ",flags)) goto L0066a685;
  }
  { // 0x66a62f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x66a630: 83e23f AND EDX,0x3f
    s.dx = integer::logical((s.dx)&(0x0000003fu),32,flags);
  }
  { // 0x66a633: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66a634: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x66a638: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x66a63a: c1f806 SAR EAX,0x6
    s.ax = integer::shift(s.ax,0x00000006u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x66a63d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x66a63f: 7e2e JLE 0x0066a66f
    if(integer::condition("JLE",flags)) goto L0066a66f;
  }
  { // 0x66a641: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66a642: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x66a643: 8d6e18 LEA EBP,[ESI + 0x18]
    s.bp = (s.si+0x00000018u);
  }
  { // 0x66a646: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0066a648: { // 0x66a648: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x66a649: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66a64a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x66a64c: e88f010000 CALL 0x0066a7e0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x66a651: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x66a654: b840000000 MOV EAX,0x40
    s.ax = 0x00000040u;
  }
  { // 0x66a659: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x66a65b: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  { // 0x66a65d: 894e2c MOV dword ptr [ESI + 0x2c],ECX
    m.w32((s.si+0x0000002cu), s.cx);
  }
  { // 0x66a660: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x66a664: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x66a666: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x66a667: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  { // 0x66a66b: 75db JNZ 0x0066a648
    if(integer::condition("JNZ",flags)) goto L0066a648;
  }
  { // 0x66a66d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x66a66e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0066a66f: { // 0x66a66f: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x66a673: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x66a677: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x66a678: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66a679: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x66a67b: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  { // 0x66a67f: e8ecfeffff CALL 0x0066a570
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x66a684: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0066a685: { // 0x66a685: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66a686: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00270910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x670910: a1f0e48400 MOV EAX,[0x0084e4f0]
    s.ax = m.r32((0x0084e4f0u));
  }
  { // 0x670915: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x670916: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x670918: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x670919: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x67091b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x67091d: 7e23 JLE 0x00670942
    if(integer::condition("JLE",flags)) goto L00670942;
  }
  L0067091f: { // 0x67091f: a1e4e48400 MOV EAX,[0x0084e4e4]
    s.ax = m.r32((0x0084e4e4u));
  }
  { // 0x670924: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x670925: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x670928: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x67092b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x67092c: e82fcf0f00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x670931: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x670934: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x670936: 7410 JZ 0x00670948
    if(integer::condition("JZ",flags)) goto L00670948;
  }
  { // 0x670938: a1f0e48400 MOV EAX,[0x0084e4f0]
    s.ax = m.r32((0x0084e4f0u));
  }
  { // 0x67093d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x67093e: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x670940: 7cdd JL 0x0067091f
    if(integer::condition("JL",flags)) goto L0067091f;
  }
  L00670942: { // 0x670942: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x670943: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x670946: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x670947: c3 RET
    finish(m,s,f,0u); return;
  }
  L00670948: { // 0x670948: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x67094a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x67094b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67094c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00270fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x670fe0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x670fe1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x670fe2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x670fe3: be4012aa00 MOV ESI,0xaa1240
    s.si = 0x00aa1240u;
  }
  { // 0x670fe8: bbf0000000 MOV EBX,0xf0
    s.bx = 0x000000f0u;
  }
  { // 0x670fed: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00670fef: { // 0x670fef: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x670ff0: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x670ff2: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  { // 0x670ff4: 6a3c PUSH 0x3c
    f.push(m,0x0000003cu);
  }
  { // 0x670ff6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x670ff7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x670ff8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x670ff9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x670ffb: e81022e1ff CALL 0x00483210
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x671000: 897e2c MOV dword ptr [ESI + 0x2c],EDI
    m.w32((s.si+0x0000002cu), s.di);
  }
  { // 0x671003: 897e30 MOV dword ptr [ESI + 0x30],EDI
    m.w32((s.si+0x00000030u), s.di);
  }
  { // 0x671006: c70624627900 MOV dword ptr [ESI],0x796224
    m.w32((s.si), 0x00796224u);
  }
  { // 0x67100c: 83c638 ADD ESI,0x38
    s.si = integer::add(s.si,0x00000038u,32,flags);
  }
  { // 0x67100f: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x671010: 75dd JNZ 0x00670fef
    if(integer::condition("JNZ",flags)) goto L00670fef;
  }
  { // 0x671012: 6830106700 PUSH 0x671030
    f.push(m,0x00671030u);
  }
  { // 0x671017: e8aed20f00 CALL 0x0076e2ca
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x67101c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x67101f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x671020: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x671021: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x671022: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00271210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x671210: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x671211: e81a2ffaff CALL 0x00614130
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x671216: be04000000 MOV ESI,0x4
    s.si = 0x00000004u;
  }
  L0067121b: { // 0x67121b: b944d67d00 MOV ECX,0x7dd644
    s.cx = 0x007dd644u;
  }
  { // 0x671220: e89b12f2ff CALL 0x005924c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x671225: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x671226: a3800faa00 MOV [0x00aa0f80],EAX
    m.w32((0x00aa0f80u), s.ax);
  }
  { // 0x67122b: 75ee JNZ 0x0067121b
    if(integer::condition("JNZ",flags)) goto L0067121b;
  }
  { // 0x67122d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67122e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00271230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x671230: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x671231: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x671232: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x671233: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x671234: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x671236: e8752efaff CALL 0x006140b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x67123b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x67123d: c686e24e000001 MOV byte ptr [ESI + 0x4ee2],0x1
    m.w8((s.si+0x00004ee2u), 0x00000001u);
  }
  { // 0x671244: 889ee64e0000 MOV byte ptr [ESI + 0x4ee6],BL
    m.w8((s.si+0x00004ee6u), (s.bx & 0xffu));
  }
  { // 0x67124a: 889ee54e0000 MOV byte ptr [ESI + 0x4ee5],BL
    m.w8((s.si+0x00004ee5u), (s.bx & 0xffu));
  }
  { // 0x671250: 8dbe40150000 LEA EDI,[ESI + 0x1540]
    s.di = (s.si+0x00001540u);
  }
  { // 0x671256: bd04000000 MOV EBP,0x4
    s.bp = 0x00000004u;
  }
  L0067125b: { // 0x67125b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x67125d: e8ae2c0000 CALL 0x00673f10
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x671262: 81c7640e0000 ADD EDI,0xe64
    s.di = integer::add(s.di,0x00000e64u,32,flags);
  }
  { // 0x671268: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  { // 0x671269: 75f0 JNZ 0x0067125b
    if(integer::condition("JNZ",flags)) goto L0067125b;
  }
  { // 0x67126b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x67126d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x67126e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x671270: 899ed84e0000 MOV dword ptr [ESI + 0x4ed8],EBX
    m.w32((s.si+0x00004ed8u), s.bx);
  }
  { // 0x671276: 899edc4e0000 MOV dword ptr [ESI + 0x4edc],EBX
    m.w32((s.si+0x00004edcu), s.bx);
  }
  { // 0x67127c: ff90d8000000 CALL dword ptr [EAX + 0xd8]
    const std::uint32_t call_target=m.r32((s.ax+0x000000d8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x671282: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x671283: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x671284: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x671285: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x671286: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0027d690(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x67d690: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x67d691: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x67d692: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x67d694: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x67d696: 742e JZ 0x0067d6c6
    if(integer::condition("JZ",flags)) goto L0067d6c6;
  }
  { // 0x67d698: a11888a200 MOV EAX,[0x00a28818]
    s.ax = m.r32((0x00a28818u));
  }
  { // 0x67d69d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x67d69f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x67d6a1: 7e23 JLE 0x0067d6c6
    if(integer::condition("JLE",flags)) goto L0067d6c6;
  }
  L0067d6a3: { // 0x67d6a3: a10c88a200 MOV EAX,[0x00a2880c]
    s.ax = m.r32((0x00a2880cu));
  }
  { // 0x67d6a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x67d6a9: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x67d6ac: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x67d6af: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x67d6b0: e8ab010f00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x67d6b5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x67d6b8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x67d6ba: 7410 JZ 0x0067d6cc
    if(integer::condition("JZ",flags)) goto L0067d6cc;
  }
  { // 0x67d6bc: a11888a200 MOV EAX,[0x00a28818]
    s.ax = m.r32((0x00a28818u));
  }
  { // 0x67d6c1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x67d6c2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x67d6c4: 7cdd JL 0x0067d6a3
    if(integer::condition("JL",flags)) goto L0067d6a3;
  }
  L0067d6c6: { // 0x67d6c6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x67d6c7: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x67d6ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67d6cb: c3 RET
    finish(m,s,f,0u); return;
  }
  L0067d6cc: { // 0x67d6cc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x67d6ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x67d6cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67d6d0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0027d6e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x67d6e0: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  { // 0x67d6e5: 81ec00020000 SUB ESP,0x200
    f.sp = integer::sub(f.sp,0x00000200u,32,flags);
  }
  { // 0x67d6eb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x67d6ed: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x67d6ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x67d6ef: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x67d6f1: 7508 JNZ 0x0067d6fb
    if(integer::condition("JNZ",flags)) goto L0067d6fb;
  }
  { // 0x67d6f3: 3b3d7c397c00 CMP EDI,dword ptr [0x007c397c]
    (void)integer::sub(s.di,m.r32((0x007c397cu)),32,flags);
  }
  { // 0x67d6f9: 745b JZ 0x0067d756
    if(integer::condition("JZ",flags)) goto L0067d756;
  }
  L0067d6fb: { // 0x67d6fb: a11888a200 MOV EAX,[0x00a28818]
    s.ax = m.r32((0x00a28818u));
  }
  { // 0x67d700: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x67d702: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x67d704: 7e50 JLE 0x0067d756
    if(integer::condition("JLE",flags)) goto L0067d756;
  }
  { // 0x67d706: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0067d707: { // 0x67d707: a10c88a200 MOV EAX,[0x00a2880c]
    s.ax = m.r32((0x00a2880cu));
  }
  { // 0x67d70c: 8b3498 MOV ESI,dword ptr [EAX + EBX*0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  { // 0x67d70f: 8a86fc010000 MOV AL,byte ptr [ESI + 0x1fc]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fcu)));
  }
  { // 0x67d715: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x67d717: 7432 JZ 0x0067d74b
    if(integer::condition("JZ",flags)) goto L0067d74b;
  }
  { // 0x67d719: 8d0c7f LEA ECX,[EDI + EDI*0x2]
    s.cx = (s.di+(s.di * 0x00000002u));
  }
  { // 0x67d71c: 8d148f LEA EDX,[EDI + ECX*0x4]
    s.dx = (s.di+(s.cx * 0x00000004u));
  }
  { // 0x67d71f: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  { // 0x67d722: 8d04d5ac5b7800 LEA EAX,[EDX*0x8 + 0x785bac]
    s.ax = ((s.dx * 0x00000008u)+0x00785bacu);
  }
  { // 0x67d729: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x67d72d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x67d72e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x67d72f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x67d731: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x67d733: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x67d734: e8f7130f00 CALL 0x0076eb30
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x67d739: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x67d73c: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x67d740: e87b4df1ff CALL 0x005924c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x67d745: 8986a4000000 MOV dword ptr [ESI + 0xa4],EAX
    m.w32((s.si+0x000000a4u), s.ax);
  }
  L0067d74b: { // 0x67d74b: a11888a200 MOV EAX,[0x00a28818]
    s.ax = m.r32((0x00a28818u));
  }
  { // 0x67d750: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x67d751: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x67d753: 7cb2 JL 0x0067d707
    if(integer::condition("JL",flags)) goto L0067d707;
  }
  { // 0x67d755: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067d756: { // 0x67d756: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x67d757: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x67d758: 81c400020000 ADD ESP,0x200
    f.sp = integer::add(f.sp,0x00000200u,32,flags);
  }
  { // 0x67d75e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002814e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6814e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6814e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6814e2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6814e3: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6814e5: e8f68b0d00 CALL 0x0075a0e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6814ea: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6814ec: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x6814ee: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6814f0: e8eb8b0d00 CALL 0x0075a0e0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6814f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6814f7: 7625 JBE 0x0068151e
    if(integer::condition("JBE",flags)) goto L0068151e;
  }
  L006814f9: { // 0x6814f9: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6814fb: e8308b0d00 CALL 0x0075a030
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x681500: 0fbe0438 MOVSX EAX,byte ptr [EAX + EDI*0x1]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+(s.di * 0x00000001u))),8));
  }
  { // 0x681504: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x681506: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x681508: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x68150a: c1e918 SHR ECX,0x18
    s.cx = integer::shift(s.cx,0x00000018u,32,flags,integer::Shift::right);
  }
  { // 0x68150d: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x681510: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  { // 0x681512: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x681514: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x681515: e8c68b0d00 CALL 0x0075a0e0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x68151a: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x68151c: 72db JC 0x006814f9
    if(integer::condition("JC",flags)) goto L006814f9;
  }
  L0068151e: { // 0x68151e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x681520: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x681521: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x681522: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x681523: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00290940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x690940: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x690941: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x690943: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x690945: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x690947: 743b JZ 0x00690984
    if(integer::condition("JZ",flags)) goto L00690984;
  }
  { // 0x690949: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  { // 0x69094c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x69094d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x69094f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x690951: 7e24 JLE 0x00690977
    if(integer::condition("JLE",flags)) goto L00690977;
  }
  { // 0x690953: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00690954: { // 0x690954: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x690957: 8b3cb0 MOV EDI,dword ptr [EAX + ESI*0x4]
    s.di = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x69095a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x69095c: 7410 JZ 0x0069096e
    if(integer::condition("JZ",flags)) goto L0069096e;
  }
  { // 0x69095e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x690960: e82bfeffff CALL 0x00690790
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x690965: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x690966: e810cd0d00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x69096b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0069096e: { // 0x69096e: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x690970: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x690971: 3b7010 CMP ESI,dword ptr [EAX + 0x10]
    (void)integer::sub(s.si,m.r32((s.ax+0x00000010u)),32,flags);
  }
  { // 0x690974: 7cde JL 0x00690954
    if(integer::condition("JL",flags)) goto L00690954;
  }
  { // 0x690976: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00690977: { // 0x690977: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x690979: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x69097a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x69097c: 7406 JZ 0x00690984
    if(integer::condition("JZ",flags)) goto L00690984;
  }
  { // 0x69097e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x690980: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x690982: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00690984: { // 0x690984: 8b4b10 MOV ECX,dword ptr [EBX + 0x10]
    s.cx = m.r32((s.bx+0x00000010u));
  }
  { // 0x690987: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x690988: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x69098a: 7406 JZ 0x00690992
    if(integer::condition("JZ",flags)) goto L00690992;
  }
  { // 0x69098c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x69098e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x690990: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00690992: { // 0x690992: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00294610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x694610: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x694611: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x694612: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x694613: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x694615: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x694617: bed8fe7d00 MOV ESI,0x7dfed8
    s.si = 0x007dfed8u;
  }
  L0069461c: { // 0x69461c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x69461e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x69461f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x694620: e83b920d00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x694625: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x694628: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x69462a: 7413 JZ 0x0069463f
    if(integer::condition("JZ",flags)) goto L0069463f;
  }
  { // 0x69462c: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x69462f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x694630: 81fef4fe7d00 CMP ESI,0x7dfef4
    (void)integer::sub(s.si,0x007dfef4u,32,flags);
  }
  { // 0x694636: 7ce4 JL 0x0069461c
    if(integer::condition("JL",flags)) goto L0069461c;
  }
  { // 0x694638: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x694639: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x69463a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x69463d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x69463e: c3 RET
    finish(m,s,f,0u); return;
  }
  L0069463f: { // 0x69463f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x694641: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x694642: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x694643: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x694644: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00294de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x694de0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x694de1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x694de2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x694de4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x694de6: 742e JZ 0x00694e16
    if(integer::condition("JZ",flags)) goto L00694e16;
  }
  { // 0x694de8: a1987fa200 MOV EAX,[0x00a27f98]
    s.ax = m.r32((0x00a27f98u));
  }
  { // 0x694ded: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x694def: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x694df1: 7e23 JLE 0x00694e16
    if(integer::condition("JLE",flags)) goto L00694e16;
  }
  L00694df3: { // 0x694df3: a18c7fa200 MOV EAX,[0x00a27f8c]
    s.ax = m.r32((0x00a27f8cu));
  }
  { // 0x694df8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x694df9: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x694dfc: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x694dff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x694e00: e85b8a0d00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x694e05: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x694e08: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x694e0a: 7410 JZ 0x00694e1c
    if(integer::condition("JZ",flags)) goto L00694e1c;
  }
  { // 0x694e0c: a1987fa200 MOV EAX,[0x00a27f98]
    s.ax = m.r32((0x00a27f98u));
  }
  { // 0x694e11: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x694e12: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x694e14: 7cdd JL 0x00694df3
    if(integer::condition("JL",flags)) goto L00694df3;
  }
  L00694e16: { // 0x694e16: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x694e17: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x694e1a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x694e1b: c3 RET
    finish(m,s,f,0u); return;
  }
  L00694e1c: { // 0x694e1c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x694e1e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x694e1f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x694e20: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00296180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x696180: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x696181: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x696182: e8b9b7fdff CALL 0x00671940
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x696187: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x696189: bea853aa00 MOV ESI,0xaa53a8
    s.si = 0x00aa53a8u;
  }
  L0069618e: { // 0x69618e: 8a87345eaa00 MOV AL,byte ptr [EDI + 0xaa5e34]
    s.ax = with_al(s.ax, m.r8((s.di+0x00aa5e34u)));
  }
  { // 0x696194: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x696196: 7412 JZ 0x006961aa
    if(integer::condition("JZ",flags)) goto L006961aa;
  }
  { // 0x696198: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x69619a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69619b: e8db740d00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6961a0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6961a3: c687345eaa0000 MOV byte ptr [EDI + 0xaa5e34],0x0
    m.w8((s.di+0x00aa5e34u), 0x00000000u);
  }
  L006961aa: { // 0x6961aa: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x6961b0: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x6961b3: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6961b4: 81fe0c54aa00 CMP ESI,0xaa540c
    (void)integer::sub(s.si,0x00aa540cu,32,flags);
  }
  { // 0x6961ba: 7cd2 JL 0x0069618e
    if(integer::condition("JL",flags)) goto L0069618e;
  }
  { // 0x6961bc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6961bd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6961be: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002963a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6963a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6963a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6963a2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6963a4: be2054aa00 MOV ESI,0xaa5420
    s.si = 0x00aa5420u;
  }
  L006963a9: { // 0x6963a9: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6963ab: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6963ad: ff5020 CALL dword ptr [EAX + 0x20]
    const std::uint32_t call_target=m.r32((s.ax+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6963b0: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x6963b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6963b3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6963b5: ff5230 CALL dword ptr [EDX + 0x30]
    const std::uint32_t call_target=m.r32((s.dx+0x00000030u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6963b8: 83c660 ADD ESI,0x60
    s.si = integer::add(s.si,0x00000060u,32,flags);
  }
  { // 0x6963bb: 81fe805daa00 CMP ESI,0xaa5d80
    (void)integer::sub(s.si,0x00aa5d80u,32,flags);
  }
  { // 0x6963c1: 7ce6 JL 0x006963a9
    if(integer::condition("JL",flags)) goto L006963a9;
  }
  { // 0x6963c3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6963c4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6963c5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002973e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6973e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6973e1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6973e2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6973e4: be2054aa00 MOV ESI,0xaa5420
    s.si = 0x00aa5420u;
  }
  L006973e9: { // 0x6973e9: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x6973eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6973ec: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6973ee: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6973f1: 83c660 ADD ESI,0x60
    s.si = integer::add(s.si,0x00000060u,32,flags);
  }
  { // 0x6973f4: 81fe805daa00 CMP ESI,0xaa5d80
    (void)integer::sub(s.si,0x00aa5d80u,32,flags);
  }
  { // 0x6973fa: 7ced JL 0x006973e9
    if(integer::condition("JL",flags)) goto L006973e9;
  }
  { // 0x6973fc: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x6973fe: 68085faa00 PUSH 0xaa5f08
    f.push(m,0x00aa5f08u);
  }
  { // 0x697403: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x697405: ff5234 CALL dword ptr [EDX + 0x34]
    const std::uint32_t call_target=m.r32((s.dx+0x00000034u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x697408: bed05daa00 MOV ESI,0xaa5dd0
    s.si = 0x00aa5dd0u;
  }
  L0069740d: { // 0x69740d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x69740f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x697411: 7c23 JL 0x00697436
    if(integer::condition("JL",flags)) goto L00697436;
  }
  { // 0x697413: 83f819 CMP EAX,0x19
    (void)integer::sub(s.ax,0x00000019u,32,flags);
  }
  { // 0x697416: 7d1e JGE 0x00697436
    if(integer::condition("JGE",flags)) goto L00697436;
  }
  { // 0x697418: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x69741b: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  { // 0x69741e: 052054aa00 ADD EAX,0xaa5420
    s.ax = integer::add(s.ax,0x00aa5420u,32,flags);
  }
  { // 0x697423: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x697425: 740f JZ 0x00697436
    if(integer::condition("JZ",flags)) goto L00697436;
  }
  { // 0x697427: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  { // 0x69742a: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x697430: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x697431: e89a980400 CALL 0x006e0cd0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00697436: { // 0x697436: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x697439: 81fe345eaa00 CMP ESI,0xaa5e34
    (void)integer::sub(s.si,0x00aa5e34u,32,flags);
  }
  { // 0x69743f: 7ccc JL 0x0069740d
    if(integer::condition("JL",flags)) goto L0069740d;
  }
  { // 0x697441: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x697447: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x69744c: e87f980400 CALL 0x006e0cd0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x697451: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x697452: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x697453: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002a4fd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a4fd0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a4fd1: 8b4144 MOV EAX,dword ptr [ECX + 0x44]
    s.ax = m.r32((s.cx+0x00000044u));
  }
  { // 0x6a4fd4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6a4fd5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a4fd6: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x6a4fda: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a4fdb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a4fdc: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x6a4fe2: e84951fbff CALL 0x0065a130
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6a4fe7: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  { // 0x6a4fe9: a1c0a5a100 MOV EAX,[0x00a1a5c0]
    s.ax = m.r32((0x00a1a5c0u));
  }
  { // 0x6a4fee: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6a4ff0: 895c2408 MOV dword ptr [ESP + 0x8],EBX
    m.w32((f.sp+0x00000008u), s.bx);
  }
  { // 0x6a4ff4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a4ff6: 7e4f JLE 0x006a5047
    if(integer::condition("JLE",flags)) goto L006a5047;
  }
  { // 0x6a4ff8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6a4ff9: 668b6c240e MOV BP,word ptr [ESP + 0xe]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((f.sp+0x0000000eu))) & 0xffffu);
  }
  { // 0x6a4ffe: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a4fff: { // 0x6a4fff: 8b15b4a5a100 MOV EDX,dword ptr [0x00a1a5b4]
    s.dx = m.r32((0x00a1a5b4u));
  }
  { // 0x6a5005: 8b34ba MOV ESI,dword ptr [EDX + EDI*0x4]
    s.si = m.r32((s.dx+(s.di * 0x00000004u)));
  }
  { // 0x6a5008: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  { // 0x6a500b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6a500d: 7424 JZ 0x006a5033
    if(integer::condition("JZ",flags)) goto L006a5033;
  }
  { // 0x6a500f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6a5011: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x6a5015: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a5016: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a5018: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    const std::uint32_t call_target=m.r32((s.ax+0x000001a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6a501e: 663918 CMP word ptr [EAX],BX
    (void)integer::sub(m.r16((s.ax)),(s.bx & 0xffffu),16,flags);
  }
  { // 0x6a5021: 7510 JNZ 0x006a5033
    if(integer::condition("JNZ",flags)) goto L006a5033;
  }
  { // 0x6a5023: 66396802 CMP word ptr [EAX + 0x2],BP
    (void)integer::sub(m.r16((s.ax+0x00000002u)),(s.bp & 0xffffu),16,flags);
  }
  { // 0x6a5027: 750a JNZ 0x006a5033
    if(integer::condition("JNZ",flags)) goto L006a5033;
  }
  { // 0x6a5029: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6a502b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a502d: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    const std::uint32_t call_target=m.r32((s.dx+0x000000f0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006a5033: { // 0x6a5033: a1c0a5a100 MOV EAX,[0x00a1a5c0]
    s.ax = m.r32((0x00a1a5c0u));
  }
  { // 0x6a5038: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6a5039: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x6a503b: 7cc2 JL 0x006a4fff
    if(integer::condition("JL",flags)) goto L006a4fff;
  }
  { // 0x6a503d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a503e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6a503f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a5040: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a5042: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6a5043: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6a5044: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a5047: { // 0x6a5047: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a5048: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a504a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6a504b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6a504c: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a7510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a7510: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a7511: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a7512: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6a7514: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  { // 0x6a7517: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a7519: 7434 JZ 0x006a754f
    if(integer::condition("JZ",flags)) goto L006a754f;
  }
  { // 0x6a751b: a1f086a200 MOV EAX,[0x00a286f0]
    s.ax = m.r32((0x00a286f0u));
  }
  { // 0x6a7520: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6a7522: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a7524: 7e29 JLE 0x006a754f
    if(integer::condition("JLE",flags)) goto L006a754f;
  }
  L006a7526: { // 0x6a7526: a1e486a200 MOV EAX,[0x00a286e4]
    s.ax = m.r32((0x00a286e4u));
  }
  { // 0x6a752b: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6a752e: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  { // 0x6a7531: 8b5124 MOV EDX,dword ptr [ECX + 0x24]
    s.dx = m.r32((s.cx+0x00000024u));
  }
  { // 0x6a7534: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x6a7536: 750d JNZ 0x006a7545
    if(integer::condition("JNZ",flags)) goto L006a7545;
  }
  { // 0x6a7538: a1b878aa00 MOV EAX,[0x00aa78b8]
    s.ax = m.r32((0x00aa78b8u));
  }
  { // 0x6a753d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a753e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6a7540: e8abb50300 CALL 0x006e2af0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006a7545: { // 0x6a7545: a1f086a200 MOV EAX,[0x00a286f0]
    s.ax = m.r32((0x00a286f0u));
  }
  { // 0x6a754a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6a754b: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6a754d: 7cd7 JL 0x006a7526
    if(integer::condition("JL",flags)) goto L006a7526;
  }
  L006a754f: { // 0x6a754f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a7550: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a7552: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a7553: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a7560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a7560: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a7561: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a7562: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6a7564: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  { // 0x6a7567: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a7569: 746d JZ 0x006a75d8
    if(integer::condition("JZ",flags)) goto L006a75d8;
  }
  { // 0x6a756b: a1f086a200 MOV EAX,[0x00a286f0]
    s.ax = m.r32((0x00a286f0u));
  }
  { // 0x6a7570: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6a7572: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a7574: 7e62 JLE 0x006a75d8
    if(integer::condition("JLE",flags)) goto L006a75d8;
  }
  { // 0x6a7576: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a7577: { // 0x6a7577: a1e486a200 MOV EAX,[0x00a286e4]
    s.ax = m.r32((0x00a286e4u));
  }
  { // 0x6a757c: 8b5750 MOV EDX,dword ptr [EDI + 0x50]
    s.dx = m.r32((s.di+0x00000050u));
  }
  { // 0x6a757f: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6a7582: 8b4124 MOV EAX,dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  { // 0x6a7585: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6a7587: 753d JNZ 0x006a75c6
    if(integer::condition("JNZ",flags)) goto L006a75c6;
  }
  { // 0x6a7589: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  { // 0x6a758f: 8b920c060000 MOV EDX,dword ptr [EDX + 0x60c]
    s.dx = m.r32((s.dx+0x0000060cu));
  }
  { // 0x6a7595: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x6a7597: 750a JNZ 0x006a75a3
    if(integer::condition("JNZ",flags)) goto L006a75a3;
  }
  { // 0x6a7599: 8a989c000000 MOV BL,byte ptr [EAX + 0x9c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000009cu)));
  }
  { // 0x6a759f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x6a75a1: 7423 JZ 0x006a75c6
    if(integer::condition("JZ",flags)) goto L006a75c6;
  }
  L006a75a3: { // 0x6a75a3: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  { // 0x6a75a6: 750a JNZ 0x006a75b2
    if(integer::condition("JNZ",flags)) goto L006a75b2;
  }
  { // 0x6a75a8: 8a989d000000 MOV BL,byte ptr [EAX + 0x9d]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000009du)));
  }
  { // 0x6a75ae: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x6a75b0: 7414 JZ 0x006a75c6
    if(integer::condition("JZ",flags)) goto L006a75c6;
  }
  L006a75b2: { // 0x6a75b2: 83fa02 CMP EDX,0x2
    (void)integer::sub(s.dx,0x00000002u,32,flags);
  }
  { // 0x6a75b5: 750a JNZ 0x006a75c1
    if(integer::condition("JNZ",flags)) goto L006a75c1;
  }
  { // 0x6a75b7: 8a909e000000 MOV DL,byte ptr [EAX + 0x9e]
    s.dx = with_al(s.dx, m.r8((s.ax+0x0000009eu)));
  }
  { // 0x6a75bd: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x6a75bf: 7405 JZ 0x006a75c6
    if(integer::condition("JZ",flags)) goto L006a75c6;
  }
  L006a75c1: { // 0x6a75c1: e85ab80300 CALL 0x006e2e20
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006a75c6: { // 0x6a75c6: a1f086a200 MOV EAX,[0x00a286f0]
    s.ax = m.r32((0x00a286f0u));
  }
  { // 0x6a75cb: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6a75cc: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6a75ce: 7ca7 JL 0x006a7577
    if(integer::condition("JL",flags)) goto L006a7577;
  }
  { // 0x6a75d0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6a75d1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a75d2: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a75d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a75d5: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a75d8: { // 0x6a75d8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a75d9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a75db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a75dc: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a75e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a75e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a75e1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a75e2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6a75e4: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  { // 0x6a75e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a75e9: 742c JZ 0x006a7617
    if(integer::condition("JZ",flags)) goto L006a7617;
  }
  { // 0x6a75eb: a1f086a200 MOV EAX,[0x00a286f0]
    s.ax = m.r32((0x00a286f0u));
  }
  { // 0x6a75f0: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6a75f2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a75f4: 7e21 JLE 0x006a7617
    if(integer::condition("JLE",flags)) goto L006a7617;
  }
  L006a75f6: { // 0x6a75f6: a1e486a200 MOV EAX,[0x00a286e4]
    s.ax = m.r32((0x00a286e4u));
  }
  { // 0x6a75fb: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6a75fe: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  { // 0x6a7601: 8b5124 MOV EDX,dword ptr [ECX + 0x24]
    s.dx = m.r32((s.cx+0x00000024u));
  }
  { // 0x6a7604: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x6a7606: 7505 JNZ 0x006a760d
    if(integer::condition("JNZ",flags)) goto L006a760d;
  }
  { // 0x6a7608: e823b80300 CALL 0x006e2e30
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006a760d: { // 0x6a760d: a1f086a200 MOV EAX,[0x00a286f0]
    s.ax = m.r32((0x00a286f0u));
  }
  { // 0x6a7612: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6a7613: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6a7615: 7cdf JL 0x006a75f6
    if(integer::condition("JL",flags)) goto L006a75f6;
  }
  L006a7617: { // 0x6a7617: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a7618: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a761a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a761b: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a85f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a85f0: a14887a200 MOV EAX,[0x00a28748]
    s.ax = m.r32((0x00a28748u));
  }
  { // 0x6a85f5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6a85f6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6a85f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a85f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a85f9: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  { // 0x6a85fb: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6a85fd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a85ff: 7e3c JLE 0x006a863d
    if(integer::condition("JLE",flags)) goto L006a863d;
  }
  { // 0x6a8601: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L006a8605: { // 0x6a8605: a13c87a200 MOV EAX,[0x00a2873c]
    s.ax = m.r32((0x00a2873cu));
  }
  { // 0x6a860a: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6a860d: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  { // 0x6a8610: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6a8612: 741f JZ 0x006a8633
    if(integer::condition("JZ",flags)) goto L006a8633;
  }
  { // 0x6a8614: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  { // 0x6a8617: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6a8619: 7418 JZ 0x006a8633
    if(integer::condition("JZ",flags)) goto L006a8633;
  }
  { // 0x6a861b: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x6a861e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6a8620: 7511 JNZ 0x006a8633
    if(integer::condition("JNZ",flags)) goto L006a8633;
  }
  { // 0x6a8622: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x6a8625: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6a8627: 740a JZ 0x006a8633
    if(integer::condition("JZ",flags)) goto L006a8633;
  }
  { // 0x6a8629: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6a862a: e8f10d0000 CALL 0x006a9420
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6a862f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6a8631: 7513 JNZ 0x006a8646
    if(integer::condition("JNZ",flags)) goto L006a8646;
  }
  L006a8633: { // 0x6a8633: a14887a200 MOV EAX,[0x00a28748]
    s.ax = m.r32((0x00a28748u));
  }
  { // 0x6a8638: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6a8639: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x6a863b: 7cc8 JL 0x006a8605
    if(integer::condition("JL",flags)) goto L006a8605;
  }
  L006a863d: { // 0x6a863d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a863e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a863f: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  { // 0x6a8641: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6a8642: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6a8643: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a8646: { // 0x6a8646: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6a8648: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a864a: e871a5daff CALL 0x00452bc0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6a864f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a8650: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a8651: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6a8652: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a8654: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6a8655: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a9870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a9870: a16079aa00 MOV EAX,[0x00aa7960]
    s.ax = m.r32((0x00aa7960u));
  }
  { // 0x6a9875: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a9876: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6a9878: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a9879: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a987b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6a987d: 7e1b JLE 0x006a989a
    if(integer::condition("JLE",flags)) goto L006a989a;
  }
  L006a987f: { // 0x6a987f: a15479aa00 MOV EAX,[0x00aa7954]
    s.ax = m.r32((0x00aa7954u));
  }
  { // 0x6a9884: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a9885: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6a9888: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  { // 0x6a988b: e850900300 CALL 0x006e28e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6a9890: a16079aa00 MOV EAX,[0x00aa7960]
    s.ax = m.r32((0x00aa7960u));
  }
  { // 0x6a9895: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6a9896: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6a9898: 7ce5 JL 0x006a987f
    if(integer::condition("JL",flags)) goto L006a987f;
  }
  L006a989a: { // 0x6a989a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a989b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a989c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002a98a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a98a0: a16079aa00 MOV EAX,[0x00aa7960]
    s.ax = m.r32((0x00aa7960u));
  }
  { // 0x6a98a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a98a6: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6a98a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a98a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a98ab: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6a98ad: 7e1b JLE 0x006a98ca
    if(integer::condition("JLE",flags)) goto L006a98ca;
  }
  L006a98af: { // 0x6a98af: a15479aa00 MOV EAX,[0x00aa7954]
    s.ax = m.r32((0x00aa7954u));
  }
  { // 0x6a98b4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a98b5: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6a98b8: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  { // 0x6a98bb: e850900300 CALL 0x006e2910
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6a98c0: a16079aa00 MOV EAX,[0x00aa7960]
    s.ax = m.r32((0x00aa7960u));
  }
  { // 0x6a98c5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6a98c6: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6a98c8: 7ce5 JL 0x006a98af
    if(integer::condition("JL",flags)) goto L006a98af;
  }
  L006a98ca: { // 0x6a98ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a98cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a98cc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002a9ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a9ed0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6a9ed1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a9ed2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a9ed3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6a9ed5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6a9ed7: 743f JZ 0x006a9f18
    if(integer::condition("JZ",flags)) goto L006a9f18;
  }
  { // 0x6a9ed9: a1b879aa00 MOV EAX,[0x00aa79b8]
    s.ax = m.r32((0x00aa79b8u));
  }
  { // 0x6a9ede: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x6a9ee0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a9ee2: 7e34 JLE 0x006a9f18
    if(integer::condition("JLE",flags)) goto L006a9f18;
  }
  L006a9ee4: { // 0x6a9ee4: a1ac79aa00 MOV EAX,[0x00aa79ac]
    s.ax = m.r32((0x00aa79acu));
  }
  { // 0x6a9ee9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a9eea: 8b3498 MOV ESI,dword ptr [EAX + EBX*0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  { // 0x6a9eed: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  { // 0x6a9ef0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a9ef1: e86a390c00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6a9ef6: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6a9ef9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a9efb: 7421 JZ 0x006a9f1e
    if(integer::condition("JZ",flags)) goto L006a9f1e;
  }
  { // 0x6a9efd: 8d5664 LEA EDX,[ESI + 0x64]
    s.dx = (s.si+0x00000064u);
  }
  { // 0x6a9f00: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a9f01: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6a9f02: e859390c00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6a9f07: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6a9f0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a9f0c: 7410 JZ 0x006a9f1e
    if(integer::condition("JZ",flags)) goto L006a9f1e;
  }
  { // 0x6a9f0e: a1b879aa00 MOV EAX,[0x00aa79b8]
    s.ax = m.r32((0x00aa79b8u));
  }
  { // 0x6a9f13: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x6a9f14: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x6a9f16: 7ccc JL 0x006a9ee4
    if(integer::condition("JL",flags)) goto L006a9ee4;
  }
  L006a9f18: { // 0x6a9f18: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a9f19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a9f1a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6a9f1c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6a9f1d: c3 RET
    finish(m,s,f,0u); return;
  }
  L006a9f1e: { // 0x6a9f1e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6a9f20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a9f21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a9f22: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6a9f23: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002aa250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6aa250: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6aa251: 8bb1a0000000 MOV ESI,dword ptr [ECX + 0xa0]
    s.si = m.r32((s.cx+0x000000a0u));
  }
  { // 0x6aa257: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6aa258: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6aa25a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa25c: 7413 JZ 0x006aa271
    if(integer::condition("JZ",flags)) goto L006aa271;
  }
  L006aa25e: { // 0x6aa25e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6aa260: e86b940300 CALL 0x006e36d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6aa265: 8bb6a8000000 MOV ESI,dword ptr [ESI + 0xa8]
    s.si = m.r32((s.si+0x000000a8u));
  }
  { // 0x6aa26b: 0bf8 OR EDI,EAX
    s.di = integer::logical((s.di)|(s.ax),32,flags);
  }
  { // 0x6aa26d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa26f: 75ed JNZ 0x006aa25e
    if(integer::condition("JNZ",flags)) goto L006aa25e;
  }
  L006aa271: { // 0x6aa271: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6aa273: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6aa274: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa275: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002aa280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6aa280: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6aa281: 8bb1a0000000 MOV ESI,dword ptr [ECX + 0xa0]
    s.si = m.r32((s.cx+0x000000a0u));
  }
  { // 0x6aa287: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa289: 7415 JZ 0x006aa2a0
    if(integer::condition("JZ",flags)) goto L006aa2a0;
  }
  L006aa28b: { // 0x6aa28b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6aa28d: e83e920300 CALL 0x006e34d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6aa292: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6aa294: 750e JNZ 0x006aa2a4
    if(integer::condition("JNZ",flags)) goto L006aa2a4;
  }
  { // 0x6aa296: 8bb6a8000000 MOV ESI,dword ptr [ESI + 0xa8]
    s.si = m.r32((s.si+0x000000a8u));
  }
  { // 0x6aa29c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa29e: 75eb JNZ 0x006aa28b
    if(integer::condition("JNZ",flags)) goto L006aa28b;
  }
  L006aa2a0: { // 0x6aa2a0: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6aa2a2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa2a3: c3 RET
    finish(m,s,f,0u); return;
  }
  L006aa2a4: { // 0x6aa2a4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6aa2a6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa2a7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002aa2b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6aa2b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6aa2b1: 8bb1a0000000 MOV ESI,dword ptr [ECX + 0xa0]
    s.si = m.r32((s.cx+0x000000a0u));
  }
  { // 0x6aa2b7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa2b9: 7415 JZ 0x006aa2d0
    if(integer::condition("JZ",flags)) goto L006aa2d0;
  }
  L006aa2bb: { // 0x6aa2bb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6aa2bd: e8ae910300 CALL 0x006e3470
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6aa2c2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6aa2c4: 750e JNZ 0x006aa2d4
    if(integer::condition("JNZ",flags)) goto L006aa2d4;
  }
  { // 0x6aa2c6: 8bb6a8000000 MOV ESI,dword ptr [ESI + 0xa8]
    s.si = m.r32((s.si+0x000000a8u));
  }
  { // 0x6aa2cc: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa2ce: 75eb JNZ 0x006aa2bb
    if(integer::condition("JNZ",flags)) goto L006aa2bb;
  }
  L006aa2d0: { // 0x6aa2d0: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6aa2d2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa2d3: c3 RET
    finish(m,s,f,0u); return;
  }
  L006aa2d4: { // 0x6aa2d4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6aa2d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa2d7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002aa2e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6aa2e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6aa2e1: 8bb1a0000000 MOV ESI,dword ptr [ECX + 0xa0]
    s.si = m.r32((s.cx+0x000000a0u));
  }
  { // 0x6aa2e7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa2e9: 7415 JZ 0x006aa300
    if(integer::condition("JZ",flags)) goto L006aa300;
  }
  L006aa2eb: { // 0x6aa2eb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6aa2ed: e84e910300 CALL 0x006e3440
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6aa2f2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6aa2f4: 750e JNZ 0x006aa304
    if(integer::condition("JNZ",flags)) goto L006aa304;
  }
  { // 0x6aa2f6: 8bb6a8000000 MOV ESI,dword ptr [ESI + 0xa8]
    s.si = m.r32((s.si+0x000000a8u));
  }
  { // 0x6aa2fc: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa2fe: 75eb JNZ 0x006aa2eb
    if(integer::condition("JNZ",flags)) goto L006aa2eb;
  }
  L006aa300: { // 0x6aa300: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6aa302: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa303: c3 RET
    finish(m,s,f,0u); return;
  }
  L006aa304: { // 0x6aa304: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6aa306: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa307: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002aa310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6aa310: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6aa311: 8bb1a0000000 MOV ESI,dword ptr [ECX + 0xa0]
    s.si = m.r32((s.cx+0x000000a0u));
  }
  { // 0x6aa317: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa319: 7415 JZ 0x006aa330
    if(integer::condition("JZ",flags)) goto L006aa330;
  }
  L006aa31b: { // 0x6aa31b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6aa31d: e87e910300 CALL 0x006e34a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6aa322: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6aa324: 750e JNZ 0x006aa334
    if(integer::condition("JNZ",flags)) goto L006aa334;
  }
  { // 0x6aa326: 8bb6a8000000 MOV ESI,dword ptr [ESI + 0xa8]
    s.si = m.r32((s.si+0x000000a8u));
  }
  { // 0x6aa32c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6aa32e: 75eb JNZ 0x006aa31b
    if(integer::condition("JNZ",flags)) goto L006aa31b;
  }
  L006aa330: { // 0x6aa330: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6aa332: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa333: c3 RET
    finish(m,s,f,0u); return;
  }
  L006aa334: { // 0x6aa334: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6aa336: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aa337: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ac1a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ac1a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ac1a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ac1a2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6ac1a4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6ac1a6: 742e JZ 0x006ac1d6
    if(integer::condition("JZ",flags)) goto L006ac1d6;
  }
  { // 0x6ac1a8: a1f084a200 MOV EAX,[0x00a284f0]
    s.ax = m.r32((0x00a284f0u));
  }
  { // 0x6ac1ad: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6ac1af: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ac1b1: 7e23 JLE 0x006ac1d6
    if(integer::condition("JLE",flags)) goto L006ac1d6;
  }
  L006ac1b3: { // 0x6ac1b3: a1e484a200 MOV EAX,[0x00a284e4]
    s.ax = m.r32((0x00a284e4u));
  }
  { // 0x6ac1b8: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6ac1bb: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x6ac1be: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ac1bf: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ac1c0: e89b160c00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ac1c5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6ac1c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ac1ca: 740f JZ 0x006ac1db
    if(integer::condition("JZ",flags)) goto L006ac1db;
  }
  { // 0x6ac1cc: a1f084a200 MOV EAX,[0x00a284f0]
    s.ax = m.r32((0x00a284f0u));
  }
  { // 0x6ac1d1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6ac1d2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6ac1d4: 7cdd JL 0x006ac1b3
    if(integer::condition("JL",flags)) goto L006ac1b3;
  }
  L006ac1d6: { // 0x6ac1d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ac1d7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6ac1d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ac1da: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ac1db: { // 0x6ac1db: 8b15e484a200 MOV EDX,dword ptr [0x00a284e4]
    s.dx = m.r32((0x00a284e4u));
  }
  { // 0x6ac1e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ac1e2: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x6ac1e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ac1e6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ac1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ac1f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ac1f1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ac1f2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6ac1f4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6ac1f6: 742e JZ 0x006ac226
    if(integer::condition("JZ",flags)) goto L006ac226;
  }
  { // 0x6ac1f8: a1f084a200 MOV EAX,[0x00a284f0]
    s.ax = m.r32((0x00a284f0u));
  }
  { // 0x6ac1fd: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6ac1ff: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ac201: 7e23 JLE 0x006ac226
    if(integer::condition("JLE",flags)) goto L006ac226;
  }
  L006ac203: { // 0x6ac203: a1e484a200 MOV EAX,[0x00a284e4]
    s.ax = m.r32((0x00a284e4u));
  }
  { // 0x6ac208: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6ac20b: 83c164 ADD ECX,0x64
    s.cx = integer::add(s.cx,0x00000064u,32,flags);
  }
  { // 0x6ac20e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ac20f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ac210: e84b160c00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ac215: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6ac218: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ac21a: 740f JZ 0x006ac22b
    if(integer::condition("JZ",flags)) goto L006ac22b;
  }
  { // 0x6ac21c: a1f084a200 MOV EAX,[0x00a284f0]
    s.ax = m.r32((0x00a284f0u));
  }
  { // 0x6ac221: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6ac222: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6ac224: 7cdd JL 0x006ac203
    if(integer::condition("JL",flags)) goto L006ac203;
  }
  L006ac226: { // 0x6ac226: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ac227: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6ac229: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ac22a: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ac22b: { // 0x6ac22b: 8b15e484a200 MOV EDX,dword ptr [0x00a284e4]
    s.dx = m.r32((0x00a284e4u));
  }
  { // 0x6ac231: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ac232: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x6ac235: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ac236: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b0080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b0080: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b0081: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b0083: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6b0085: e8a6cfffff CALL 0x006ad030
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b008a: 8b7654 MOV ESI,dword ptr [ESI + 0x54]
    s.si = m.r32((s.si+0x00000054u));
  }
  { // 0x6b008d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b008f: 741d JZ 0x006b00ae
    if(integer::condition("JZ",flags)) goto L006b00ae;
  }
  L006b0091: { // 0x6b0091: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b0093: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6b0095: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b0097: ff9070030000 CALL dword ptr [EAX + 0x370]
    const std::uint32_t call_target=m.r32((s.ax+0x00000370u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b009d: c6867805000001 MOV byte ptr [ESI + 0x578],0x1
    m.w8((s.si+0x00000578u), 0x00000001u);
  }
  { // 0x6b00a4: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  { // 0x6b00aa: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b00ac: 75e3 JNZ 0x006b0091
    if(integer::condition("JNZ",flags)) goto L006b0091;
  }
  L006b00ae: { // 0x6b00ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b00af: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b00b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b00b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6b00b1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6b00b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b00b3: 8b7154 MOV ESI,dword ptr [ECX + 0x54]
    s.si = m.r32((s.cx+0x00000054u));
  }
  { // 0x6b00b6: 83cbff OR EBX,0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  { // 0x6b00b9: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x6b00bb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b00bd: 7462 JZ 0x006b0121
    if(integer::condition("JZ",flags)) goto L006b0121;
  }
  { // 0x6b00bf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b00c0: { // 0x6b00c0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b00c2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b00c4: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b00ca: 8bb844050000 MOV EDI,dword ptr [EAX + 0x544]
    s.di = m.r32((s.ax+0x00000544u));
  }
  { // 0x6b00d0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b00d2: 743c JZ 0x006b0110
    if(integer::condition("JZ",flags)) goto L006b0110;
  }
  { // 0x6b00d4: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  { // 0x6b00d7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b00d9: 7435 JZ 0x006b0110
    if(integer::condition("JZ",flags)) goto L006b0110;
  }
  { // 0x6b00db: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  { // 0x6b00de: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b00e0: 742e JZ 0x006b0110
    if(integer::condition("JZ",flags)) goto L006b0110;
  }
  { // 0x6b00e2: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  { // 0x6b00e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b00e9: 7507 JNZ 0x006b00f2
    if(integer::condition("JNZ",flags)) goto L006b00f2;
  }
  { // 0x6b00eb: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x6b00ee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b00f0: 751e JNZ 0x006b0110
    if(integer::condition("JNZ",flags)) goto L006b0110;
  }
  L006b00f2: { // 0x6b00f2: 8a8679050000 MOV AL,byte ptr [ESI + 0x579]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000579u)));
  }
  { // 0x6b00f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b00fa: 750c JNZ 0x006b0108
    if(integer::condition("JNZ",flags)) goto L006b0108;
  }
  { // 0x6b00fc: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6b00fe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b0100: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b0103: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x6b0106: 7508 JNZ 0x006b0110
    if(integer::condition("JNZ",flags)) goto L006b0110;
  }
  L006b0108: { // 0x6b0108: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x6b010a: 7e04 JLE 0x006b0110
    if(integer::condition("JLE",flags)) goto L006b0110;
  }
  { // 0x6b010c: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x6b010e: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L006b0110: { // 0x6b0110: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  { // 0x6b0116: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b0118: 75a6 JNZ 0x006b00c0
    if(integer::condition("JNZ",flags)) goto L006b00c0;
  }
  { // 0x6b011a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b011b: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x6b011d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b011e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6b011f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6b0120: c3 RET
    finish(m,s,f,0u); return;
  }
  L006b0121: { // 0x6b0121: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x6b0123: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b0124: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6b0125: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6b0126: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b0a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b0a00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6b0a01: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b0a02: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b0a03: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6b0a05: 689c000000 PUSH 0x9c
    f.push(m,0x0000009cu);
  }
  { // 0x6b0a0a: e848cf0b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b0a0f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6b0a12: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b0a14: 7422 JZ 0x006b0a38
    if(integer::condition("JZ",flags)) goto L006b0a38;
  }
  { // 0x6b0a16: 8b4f2c MOV ECX,dword ptr [EDI + 0x2c]
    s.cx = m.r32((s.di+0x0000002cu));
  }
  { // 0x6b0a19: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6b0a1d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6b0a1f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b0a20: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  { // 0x6b0a23: 8b158c88a200 MOV EDX,dword ptr [0x00a2888c]
    s.dx = m.r32((0x00a2888cu));
  }
  { // 0x6b0a29: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  { // 0x6b0a2c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b0a2d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6b0a2f: e84cc0ffff CALL 0x006aca80
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b0a34: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x6b0a36: eb02 JMP 0x006b0a3a
    goto L006b0a3a;
  }
  L006b0a38: { // 0x6b0a38: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006b0a3a: { // 0x6b0a3a: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  { // 0x6b0a3d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b0a3f: 741b JZ 0x006b0a5c
    if(integer::condition("JZ",flags)) goto L006b0a5c;
  }
  L006b0a41: { // 0x6b0a41: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6b0a43: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6b0a45: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b0a46: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6b0a48: e8b3dbffff CALL 0x006ae600
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6b0a4d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b0a4e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6b0a50: e8bbd8ffff CALL 0x006ae310
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6b0a55: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  { // 0x6b0a58: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b0a5a: 75e5 JNZ 0x006b0a41
    if(integer::condition("JNZ",flags)) goto L006b0a41;
  }
  L006b0a5c: { // 0x6b0a5c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6b0a5e: 7409 JZ 0x006b0a69
    if(integer::condition("JZ",flags)) goto L006b0a69;
  }
  { // 0x6b0a60: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x6b0a62: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6b0a64: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6b0a66: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L006b0a69: { // 0x6b0a69: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b0a6a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b0a6b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6b0a6c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b1930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1930: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  { // 0x6b1933: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1934: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b1935: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6b1937: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  { // 0x6b193a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b193c: 7456 JZ 0x006b1994
    if(integer::condition("JZ",flags)) goto L006b1994;
  }
  L006b193e: { // 0x6b193e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b1940: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x6b1944: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b1945: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b1947: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b194a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6b194c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6b194e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6b194f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x6b1955: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x6b1957: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6b195a: 6689442408 MOV word ptr [ESP + 0x8],AX
    m.w16((f.sp+0x00000008u), (s.ax & 0xffffu));
  }
  { // 0x6b195f: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x6b1962: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6b1963: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x6b1969: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6b196e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x6b1970: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6b1973: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  { // 0x6b1978: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6b197c: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x6b1980: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  { // 0x6b1984: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b1985: e8f68deaff CALL 0x0055a780
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b198a: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  { // 0x6b1990: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b1992: 75aa JNZ 0x006b193e
    if(integer::condition("JNZ",flags)) goto L006b193e;
  }
  L006b1994: { // 0x6b1994: c6878000000001 MOV byte ptr [EDI + 0x80],0x1
    m.w8((s.di+0x00000080u), 0x00000001u);
  }
  { // 0x6b199b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b199c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b199d: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x6b19a0: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b1c40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1c40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1c41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b1c42: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6b1c44: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  { // 0x6b1c47: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b1c49: 7451 JZ 0x006b1c9c
    if(integer::condition("JZ",flags)) goto L006b1c9c;
  }
  L006b1c4b: { // 0x6b1c4b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b1c4d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b1c4f: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b1c52: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6b1c55: 753b JNZ 0x006b1c92
    if(integer::condition("JNZ",flags)) goto L006b1c92;
  }
  { // 0x6b1c57: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6b1c59: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b1c5b: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b1c61: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  { // 0x6b1c64: 684c067e00 PUSH 0x7e064c
    f.push(m,0x007e064cu);
  }
  { // 0x6b1c69: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b1c6a: e8f1bb0b00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6b1c6f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b1c72: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b1c74: 751c JNZ 0x006b1c92
    if(integer::condition("JNZ",flags)) goto L006b1c92;
  }
  { // 0x6b1c76: b944067e00 MOV ECX,0x7e0644
    s.cx = 0x007e0644u;
  }
  { // 0x6b1c7b: e8d0d70400 CALL 0x006ff450
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6b1c80: 8b0d7ce0a100 MOV ECX,dword ptr [0x00a1e07c]
    s.cx = m.r32((0x00a1e07cu));
  }
  { // 0x6b1c86: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x6b1c89: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  { // 0x6b1c8c: 8996ac050000 MOV dword ptr [ESI + 0x5ac],EDX
    m.w32((s.si+0x000005acu), s.dx);
  }
  L006b1c92: { // 0x6b1c92: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  { // 0x6b1c98: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b1c9a: 75af JNZ 0x006b1c4b
    if(integer::condition("JNZ",flags)) goto L006b1c4b;
  }
  L006b1c9c: { // 0x6b1c9c: c6878000000001 MOV byte ptr [EDI + 0x80],0x1
    m.w8((s.di+0x00000080u), 0x00000001u);
  }
  { // 0x6b1ca3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b1ca4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1ca5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b1cb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1cb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1cb1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b1cb2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6b1cb4: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  { // 0x6b1cb7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b1cb9: 7451 JZ 0x006b1d0c
    if(integer::condition("JZ",flags)) goto L006b1d0c;
  }
  L006b1cbb: { // 0x6b1cbb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b1cbd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b1cbf: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b1cc2: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6b1cc5: 753b JNZ 0x006b1d02
    if(integer::condition("JNZ",flags)) goto L006b1d02;
  }
  { // 0x6b1cc7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6b1cc9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b1ccb: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b1cd1: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  { // 0x6b1cd4: 6844067e00 PUSH 0x7e0644
    f.push(m,0x007e0644u);
  }
  { // 0x6b1cd9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b1cda: e881bb0b00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6b1cdf: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b1ce2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b1ce4: 751c JNZ 0x006b1d02
    if(integer::condition("JNZ",flags)) goto L006b1d02;
  }
  { // 0x6b1ce6: b94c067e00 MOV ECX,0x7e064c
    s.cx = 0x007e064cu;
  }
  { // 0x6b1ceb: e860d70400 CALL 0x006ff450
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6b1cf0: 8b0d7ce0a100 MOV ECX,dword ptr [0x00a1e07c]
    s.cx = m.r32((0x00a1e07cu));
  }
  { // 0x6b1cf6: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x6b1cf9: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  { // 0x6b1cfc: 8996ac050000 MOV dword ptr [ESI + 0x5ac],EDX
    m.w32((s.si+0x000005acu), s.dx);
  }
  L006b1d02: { // 0x6b1d02: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  { // 0x6b1d08: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6b1d0a: 75af JNZ 0x006b1cbb
    if(integer::condition("JNZ",flags)) goto L006b1cbb;
  }
  L006b1d0c: { // 0x6b1d0c: c6878000000001 MOV byte ptr [EDI + 0x80],0x1
    m.w8((s.di+0x00000080u), 0x00000001u);
  }
  { // 0x6b1d13: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b1d14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1d15: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b3fa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b3fa0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b3fa1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b3fa2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6b3fa4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6b3fa6: 0fbe07 MOVSX EAX,byte ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di)),8));
  }
  { // 0x6b3fa9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b3faa: e845a50b00 CALL 0x0076e4f4
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b3faf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6b3fb2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b3fb4: 743e JZ 0x006b3ff4
    if(integer::condition("JZ",flags)) goto L006b3ff4;
  }
  L006b3fb6: { // 0x6b3fb6: 0fbe0f MOVSX ECX,byte ptr [EDI]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di)),8));
  }
  { // 0x6b3fb9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b3fba: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x6b3fbd: e80aa50b00 CALL 0x0076e4cc
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b3fc2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6b3fc5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b3fc7: 7409 JZ 0x006b3fd2
    if(integer::condition("JZ",flags)) goto L006b3fd2;
  }
  { // 0x6b3fc9: 0fbe17 MOVSX EDX,byte ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.di)),8));
  }
  { // 0x6b3fcc: 8d7416d0 LEA ESI,[ESI + EDX*0x1 + -0x30]
    s.si = (s.si+(s.dx * 0x00000001u)-0x00000030u);
  }
  { // 0x6b3fd0: eb10 JMP 0x006b3fe2
    goto L006b3fe2;
  }
  L006b3fd2: { // 0x6b3fd2: 0fbe07 MOVSX EAX,byte ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di)),8));
  }
  { // 0x6b3fd5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b3fd6: e838a30b00 CALL 0x0076e313
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6b3fdb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6b3fde: 8d7406c9 LEA ESI,[ESI + EAX*0x1 + -0x37]
    s.si = (s.si+(s.ax * 0x00000001u)-0x00000037u);
  }
  L006b3fe2: { // 0x6b3fe2: 0fbe4f01 MOVSX ECX,byte ptr [EDI + 0x1]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x00000001u)),8));
  }
  { // 0x6b3fe6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6b3fe7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b3fe8: e807a50b00 CALL 0x0076e4f4
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6b3fed: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6b3ff0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b3ff2: 75c2 JNZ 0x006b3fb6
    if(integer::condition("JNZ",flags)) goto L006b3fb6;
  }
  L006b3ff4: { // 0x6b3ff4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6b3ff6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b3ff7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b3ff8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b48b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b48b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b48b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b48b2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6b48b4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6b48b6: 7448 JZ 0x006b4900
    if(integer::condition("JZ",flags)) goto L006b4900;
  }
  { // 0x6b48b8: a19888a200 MOV EAX,[0x00a28898]
    s.ax = m.r32((0x00a28898u));
  }
  { // 0x6b48bd: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6b48bf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b48c1: 7e3d JLE 0x006b4900
    if(integer::condition("JLE",flags)) goto L006b4900;
  }
  L006b48c3: { // 0x6b48c3: a18c88a200 MOV EAX,[0x00a2888c]
    s.ax = m.r32((0x00a2888cu));
  }
  { // 0x6b48c8: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6b48cb: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x6b48ce: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b48cf: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b48d0: e88b8f0b00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b48d5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b48d8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b48da: 7429 JZ 0x006b4905
    if(integer::condition("JZ",flags)) goto L006b4905;
  }
  { // 0x6b48dc: 8b158c88a200 MOV EDX,dword ptr [0x00a2888c]
    s.dx = m.r32((0x00a2888cu));
  }
  { // 0x6b48e2: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x6b48e5: 83c064 ADD EAX,0x64
    s.ax = integer::add(s.ax,0x00000064u,32,flags);
  }
  { // 0x6b48e8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b48e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b48ea: e8718f0b00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b48ef: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b48f2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b48f4: 740f JZ 0x006b4905
    if(integer::condition("JZ",flags)) goto L006b4905;
  }
  { // 0x6b48f6: a19888a200 MOV EAX,[0x00a28898]
    s.ax = m.r32((0x00a28898u));
  }
  { // 0x6b48fb: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6b48fc: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6b48fe: 7cc3 JL 0x006b48c3
    if(integer::condition("JL",flags)) goto L006b48c3;
  }
  L006b4900: { // 0x6b4900: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b4901: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6b4903: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b4904: c3 RET
    finish(m,s,f,0u); return;
  }
  L006b4905: { // 0x6b4905: 8b0d8c88a200 MOV ECX,dword ptr [0x00a2888c]
    s.cx = m.r32((0x00a2888cu));
  }
  { // 0x6b490b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b490c: 8b04b1 MOV EAX,dword ptr [ECX + ESI*0x4]
    s.ax = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x6b490f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b4910: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b5760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b5760: a1b8e48400 MOV EAX,[0x0084e4b8]
    s.ax = m.r32((0x0084e4b8u));
  }
  { // 0x6b5765: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b5766: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6b5768: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6b5769: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b576b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6b576d: 7e23 JLE 0x006b5792
    if(integer::condition("JLE",flags)) goto L006b5792;
  }
  { // 0x6b576f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6b5770: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L006b5774: { // 0x6b5774: a1ace48400 MOV EAX,[0x0084e4ac]
    s.ax = m.r32((0x0084e4acu));
  }
  { // 0x6b5779: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6b577c: 397924 CMP dword ptr [ECX + 0x24],EDI
    (void)integer::sub(m.r32((s.cx+0x00000024u)),s.di,32,flags);
  }
  { // 0x6b577f: 7506 JNZ 0x006b5787
    if(integer::condition("JNZ",flags)) goto L006b5787;
  }
  { // 0x6b5781: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6b5782: e859d8ffff CALL 0x006b2fe0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006b5787: { // 0x6b5787: a1b8e48400 MOV EAX,[0x0084e4b8]
    s.ax = m.r32((0x0084e4b8u));
  }
  { // 0x6b578c: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6b578d: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6b578f: 7ce3 JL 0x006b5774
    if(integer::condition("JL",flags)) goto L006b5774;
  }
  { // 0x6b5791: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b5792: { // 0x6b5792: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6b5793: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b5794: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002b5870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b5870: a19888a200 MOV EAX,[0x00a28898]
    s.ax = m.r32((0x00a28898u));
  }
  { // 0x6b5875: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b5876: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6b5878: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b587a: 7e17 JLE 0x006b5893
    if(integer::condition("JLE",flags)) goto L006b5893;
  }
  L006b587c: { // 0x6b587c: a18c88a200 MOV EAX,[0x00a2888c]
    s.ax = m.r32((0x00a2888cu));
  }
  { // 0x6b5881: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6b5884: e847ffffff CALL 0x006b57d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b5889: a19888a200 MOV EAX,[0x00a28898]
    s.ax = m.r32((0x00a28898u));
  }
  { // 0x6b588e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6b588f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6b5891: 7ce9 JL 0x006b587c
    if(integer::condition("JL",flags)) goto L006b587c;
  }
  L006b5893: { // 0x6b5893: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b5894: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c85b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c85b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6c85b1: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6c85b3: 8b83fc000000 MOV EAX,dword ptr [EBX + 0xfc]
    s.ax = m.r32((s.bx+0x000000fcu));
  }
  { // 0x6c85b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6c85bb: 7456 JZ 0x006c8613
    if(integer::condition("JZ",flags)) goto L006c8613;
  }
  { // 0x6c85bd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6c85be: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6c85c2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c85c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6c85c4: 8dbbf8000000 LEA EDI,[EBX + 0xf8]
    s.di = (s.bx+0x000000f8u);
  }
  L006c85ca: { // 0x6c85ca: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6c85cc: e85f00daff CALL 0x00468630
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c85d1: 8b88c4040000 MOV ECX,dword ptr [EAX + 0x4c4]
    s.cx = m.r32((s.ax+0x000004c4u));
  }
  { // 0x6c85d7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6c85d9: 740a JZ 0x006c85e5
    if(integer::condition("JZ",flags)) goto L006c85e5;
  }
  { // 0x6c85db: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6c85dd: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6c85df: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6c85e0: e81b60feff CALL 0x006ae600
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006c85e5: { // 0x6c85e5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6c85e7: e82400daff CALL 0x00468610
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6c85ec: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x6c85ee: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6c85f0: 7414 JZ 0x006c8606
    if(integer::condition("JZ",flags)) goto L006c8606;
  }
  { // 0x6c85f2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c85f4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6c85f5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c85f7: ff90dc000000 CALL dword ptr [EAX + 0xdc]
    const std::uint32_t call_target=m.r32((s.ax+0x000000dcu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6c85fd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c85ff: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6c8601: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c8603: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L006c8606: { // 0x6c8606: 8b83fc000000 MOV EAX,dword ptr [EBX + 0xfc]
    s.ax = m.r32((s.bx+0x000000fcu));
  }
  { // 0x6c860c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6c860e: 75ba JNZ 0x006c85ca
    if(integer::condition("JNZ",flags)) goto L006c85ca;
  }
  { // 0x6c8610: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6c8611: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c8612: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c8613: { // 0x6c8613: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6c8614: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002d4bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d4bb0: a10887a200 MOV EAX,[0x00a28708]
    s.ax = m.r32((0x00a28708u));
  }
  { // 0x6d4bb5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d4bb6: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6d4bb8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6d4bba: 7e2f JLE 0x006d4beb
    if(integer::condition("JLE",flags)) goto L006d4beb;
  }
  { // 0x6d4bbc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d4bbd: { // 0x6d4bbd: a1fc86a200 MOV EAX,[0x00a286fc]
    s.ax = m.r32((0x00a286fcu));
  }
  { // 0x6d4bc2: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6d4bc5: 8a866c0b0000 MOV AL,byte ptr [ESI + 0xb6c]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000b6cu)));
  }
  { // 0x6d4bcb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6d4bcd: 8d8e6c0b0000 LEA ECX,[ESI + 0xb6c]
    s.cx = (s.si+0x00000b6cu);
  }
  { // 0x6d4bd3: 740b JZ 0x006d4be0
    if(integer::condition("JZ",flags)) goto L006d4be0;
  }
  { // 0x6d4bd5: e88663f2ff CALL 0x005faf60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6d4bda: 89868c0b0000 MOV dword ptr [ESI + 0xb8c],EAX
    m.w32((s.si+0x00000b8cu), s.ax);
  }
  L006d4be0: { // 0x6d4be0: a10887a200 MOV EAX,[0x00a28708]
    s.ax = m.r32((0x00a28708u));
  }
  { // 0x6d4be5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6d4be6: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x6d4be8: 7cd3 JL 0x006d4bbd
    if(integer::condition("JL",flags)) goto L006d4bbd;
  }
  { // 0x6d4bea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d4beb: { // 0x6d4beb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d4bec: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002d4d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d4d60: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6d4d61: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6d4d62: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d4d63: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d4d64: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x6d4d68: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6d4d6a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6d4d6c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x6d4d6e: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x6d4d72: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x6d4d75: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x6d4d77: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6d4d78: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d4d79: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x6d4d7d: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6d4d80: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6d4d84: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6d4d86: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6d4d88: 7e1a JLE 0x006d4da4
    if(integer::condition("JLE",flags)) goto L006d4da4;
  }
  L006d4d8a: { // 0x6d4d8a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x6d4d8d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x6d4d8f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6d4d91: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x6d4d93: 8d14b1 LEA EDX,[ECX + ESI*0x4]
    s.dx = (s.cx+(s.si * 0x00000004u));
  }
  { // 0x6d4d96: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6d4d97: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d4d98: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6d4d9b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6d4d9f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6d4da0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6d4da2: 7ce6 JL 0x006d4d8a
    if(integer::condition("JL",flags)) goto L006d4d8a;
  }
  L006d4da4: { // 0x6d4da4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d4da5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d4da6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6d4da7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6d4da8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002da7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6da7d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6da7d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6da7d2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6da7d4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6da7d6: 742e JZ 0x006da806
    if(integer::condition("JZ",flags)) goto L006da806;
  }
  { // 0x6da7d8: a1807fa200 MOV EAX,[0x00a27f80]
    s.ax = m.r32((0x00a27f80u));
  }
  { // 0x6da7dd: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6da7df: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6da7e1: 7e23 JLE 0x006da806
    if(integer::condition("JLE",flags)) goto L006da806;
  }
  L006da7e3: { // 0x6da7e3: a1747fa200 MOV EAX,[0x00a27f74]
    s.ax = m.r32((0x00a27f74u));
  }
  { // 0x6da7e8: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6da7eb: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x6da7ee: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6da7ef: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6da7f0: e86b300900 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6da7f5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6da7f8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6da7fa: 7410 JZ 0x006da80c
    if(integer::condition("JZ",flags)) goto L006da80c;
  }
  { // 0x6da7fc: a1807fa200 MOV EAX,[0x00a27f80]
    s.ax = m.r32((0x00a27f80u));
  }
  { // 0x6da801: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6da802: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6da804: 7cdd JL 0x006da7e3
    if(integer::condition("JL",flags)) goto L006da7e3;
  }
  L006da806: { // 0x6da806: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6da807: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x6da80a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6da80b: c3 RET
    finish(m,s,f,0u); return;
  }
  L006da80c: { // 0x6da80c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6da80e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6da80f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6da810: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002dcd30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dcd30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dcd31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6dcd33: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x6dcd36: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dcd38: 7e3a JLE 0x006dcd74
    if(integer::condition("JLE",flags)) goto L006dcd74;
  }
  L006dcd3a: { // 0x6dcd3a: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x6dcd3d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6dcd3f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6dcd40: e836090900 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6dcd45: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x6dcd48: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6dcd4b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dcd4d: 7e1e JLE 0x006dcd6d
    if(integer::condition("JLE",flags)) goto L006dcd6d;
  }
  { // 0x6dcd4f: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  { // 0x6dcd52: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6dcd54: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6dcd56: 894e24 MOV dword ptr [ESI + 0x24],ECX
    m.w32((s.si+0x00000024u), s.cx);
  }
  { // 0x6dcd59: 7e12 JLE 0x006dcd6d
    if(integer::condition("JLE",flags)) goto L006dcd6d;
  }
  L006dcd5b: { // 0x6dcd5b: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x6dcd5e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x6dcd5f: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x6dcd62: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x6dcd66: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6dcd69: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6dcd6b: 7cee JL 0x006dcd5b
    if(integer::condition("JL",flags)) goto L006dcd5b;
  }
  L006dcd6d: { // 0x6dcd6d: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x6dcd70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dcd72: 7fc6 JG 0x006dcd3a
    if(integer::condition("JG",flags)) goto L006dcd3a;
  }
  L006dcd74: { // 0x6dcd74: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dcd77: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6dcd79: 7424 JZ 0x006dcd9f
    if(integer::condition("JZ",flags)) goto L006dcd9f;
  }
  { // 0x6dcd7b: e860b2d2ff CALL 0x00407fe0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6dcd80: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dcd83: e888b2d2ff CALL 0x00408010
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6dcd88: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dcd8b: e8d0b0d2ff CALL 0x00407e60
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6dcd90: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dcd93: e828acd2ff CALL 0x004079c0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6dcd98: c7462c00000000 MOV dword ptr [ESI + 0x2c],0x0
    m.w32((s.si+0x0000002cu), 0x00000000u);
  }
  L006dcd9f: { // 0x6dcd9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dcda0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e28e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e28e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e28e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e28e3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e28e5: 7421 JZ 0x006e2908
    if(integer::condition("JZ",flags)) goto L006e2908;
  }
  { // 0x6e28e7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e28e8: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006e28ec: { // 0x6e28ec: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e28ef: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e28f0: e80b0c0000 CALL 0x006e3500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e28f5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e28f7: 7407 JZ 0x006e2900
    if(integer::condition("JZ",flags)) goto L006e2900;
  }
  { // 0x6e28f9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e28fb: e840000000 CALL 0x006e2940
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006e2900: { // 0x6e2900: 8b7628 MOV ESI,dword ptr [ESI + 0x28]
    s.si = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2903: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e2905: 75e5 JNZ 0x006e28ec
    if(integer::condition("JNZ",flags)) goto L006e28ec;
  }
  { // 0x6e2907: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e2908: { // 0x6e2908: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2909: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e2910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e2910: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2911: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e2913: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e2915: 7421 JZ 0x006e2938
    if(integer::condition("JZ",flags)) goto L006e2938;
  }
  { // 0x6e2917: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e2918: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006e291c: { // 0x6e291c: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e291f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e2920: e81b0c0000 CALL 0x006e3540
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e2925: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2927: 7407 JZ 0x006e2930
    if(integer::condition("JZ",flags)) goto L006e2930;
  }
  { // 0x6e2929: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e292b: e810000000 CALL 0x006e2940
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006e2930: { // 0x6e2930: 8b7628 MOV ESI,dword ptr [ESI + 0x28]
    s.si = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2933: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e2935: 75e5 JNZ 0x006e291c
    if(integer::condition("JNZ",flags)) goto L006e291c;
  }
  { // 0x6e2937: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e2938: { // 0x6e2938: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2939: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e2af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e2af0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e2af1: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6e2af3: 8a4740 MOV AL,byte ptr [EDI + 0x40]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000040u)));
  }
  { // 0x6e2af6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2af8: 7456 JZ 0x006e2b50
    if(integer::condition("JZ",flags)) goto L006e2b50;
  }
  { // 0x6e2afa: 8a472c MOV AL,byte ptr [EDI + 0x2c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000002cu)));
  }
  { // 0x6e2afd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2aff: 754f JNZ 0x006e2b50
    if(integer::condition("JNZ",flags)) goto L006e2b50;
  }
  { // 0x6e2b01: 8b4724 MOV EAX,dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  { // 0x6e2b04: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e2b05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2b06: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  { // 0x6e2b08: 8bb0b0000000 MOV ESI,dword ptr [EAX + 0xb0]
    s.si = m.r32((s.ax+0x000000b0u));
  }
  { // 0x6e2b0e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e2b10: 7436 JZ 0x006e2b48
    if(integer::condition("JZ",flags)) goto L006e2b48;
  }
  { // 0x6e2b12: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6e2b13: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L006e2b17: { // 0x6e2b17: 8b5724 MOV EDX,dword ptr [EDI + 0x24]
    s.dx = m.r32((s.di+0x00000024u));
  }
  { // 0x6e2b1a: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  { // 0x6e2b1e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e2b1f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e2b20: 8b82a4000000 MOV EAX,dword ptr [EDX + 0xa4]
    s.ax = m.r32((s.dx+0x000000a4u));
  }
  { // 0x6e2b26: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6e2b27: 8b88b4000000 MOV ECX,dword ptr [EAX + 0xb4]
    s.cx = m.r32((s.ax+0x000000b4u));
  }
  { // 0x6e2b2d: e82ea1e0ff CALL 0x004ecc60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e2b32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e2b33: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e2b35: e8f605fcff CALL 0x006a3130
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6e2b3a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2b3c: 7402 JZ 0x006e2b40
    if(integer::condition("JZ",flags)) goto L006e2b40;
  }
  { // 0x6e2b3e: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006e2b40: { // 0x6e2b40: 8b7628 MOV ESI,dword ptr [ESI + 0x28]
    s.si = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2b43: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e2b45: 75d0 JNZ 0x006e2b17
    if(integer::condition("JNZ",flags)) goto L006e2b17;
  }
  { // 0x6e2b47: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e2b48: { // 0x6e2b48: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  { // 0x6e2b4a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2b4b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e2b4c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e2b4d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L006e2b50: { // 0x6e2b50: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6e2b52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e2b53: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002e3610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e3610: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e3611: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e3612: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6e3614: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6e3616: 7448 JZ 0x006e3660
    if(integer::condition("JZ",flags)) goto L006e3660;
  }
  { // 0x6e3618: a148e58400 MOV EAX,[0x0084e548]
    s.ax = m.r32((0x0084e548u));
  }
  { // 0x6e361d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6e361f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e3621: 7e3d JLE 0x006e3660
    if(integer::condition("JLE",flags)) goto L006e3660;
  }
  L006e3623: { // 0x6e3623: a13ce58400 MOV EAX,[0x0084e53c]
    s.ax = m.r32((0x0084e53cu));
  }
  { // 0x6e3628: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e3629: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6e362c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x6e362f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e3630: e82ba20800 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e3635: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e3638: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e363a: 7429 JZ 0x006e3665
    if(integer::condition("JZ",flags)) goto L006e3665;
  }
  { // 0x6e363c: 8b153ce58400 MOV EDX,dword ptr [0x0084e53c]
    s.dx = m.r32((0x0084e53cu));
  }
  { // 0x6e3642: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e3643: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x6e3646: 83c064 ADD EAX,0x64
    s.ax = integer::add(s.ax,0x00000064u,32,flags);
  }
  { // 0x6e3649: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e364a: e811a20800 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6e364f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e3652: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e3654: 740f JZ 0x006e3665
    if(integer::condition("JZ",flags)) goto L006e3665;
  }
  { // 0x6e3656: a148e58400 MOV EAX,[0x0084e548]
    s.ax = m.r32((0x0084e548u));
  }
  { // 0x6e365b: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6e365c: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6e365e: 7cc3 JL 0x006e3623
    if(integer::condition("JL",flags)) goto L006e3623;
  }
  L006e3660: { // 0x6e3660: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e3661: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e3663: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e3664: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e3665: { // 0x6e3665: 8b0d3ce58400 MOV ECX,dword ptr [0x0084e53c]
    s.cx = m.r32((0x0084e53cu));
  }
  { // 0x6e366b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e366c: 8b04b1 MOV EAX,dword ptr [ECX + ESI*0x4]
    s.ax = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x6e366f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e3670: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e3680(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e3680: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e3681: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e3682: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e3683: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6e3685: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6e3687: be381e7e00 MOV ESI,0x7e1e38
    s.si = 0x007e1e38u;
  }
  L006e368c: { // 0x6e368c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6e368e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e368f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e3690: e8cba10800 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e3695: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e3698: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e369a: 7412 JZ 0x006e36ae
    if(integer::condition("JZ",flags)) goto L006e36ae;
  }
  { // 0x6e369c: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x6e369f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6e36a0: 81fe441e7e00 CMP ESI,0x7e1e44
    (void)integer::sub(s.si,0x007e1e44u,32,flags);
  }
  { // 0x6e36a6: 7ce4 JL 0x006e368c
    if(integer::condition("JL",flags)) goto L006e368c;
  }
  { // 0x6e36a8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e36a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e36aa: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e36ac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e36ad: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e36ae: { // 0x6e36ae: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6e36b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e36b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e36b2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e36b3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e4af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e4af0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e4af1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6e4af2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e4af3: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x6e4af7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e4af8: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6e4afa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e4afb: e8b0b6d2ff CALL 0x004101b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e4b00: 668b4724 MOV AX,word ptr [EDI + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000024u)));
  }
  { // 0x6e4b04: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e4b06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e4b07: e8e4f1daff CALL 0x00493cf0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6e4b0c: 668b4f26 MOV CX,word ptr [EDI + 0x26]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000026u)));
  }
  { // 0x6e4b10: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e4b11: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e4b13: e8d8f1daff CALL 0x00493cf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6e4b18: 668b5728 MOV DX,word ptr [EDI + 0x28]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000028u)));
  }
  { // 0x6e4b1c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e4b1e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e4b1f: e8ccf1daff CALL 0x00493cf0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6e4b24: 668b472a MOV AX,word ptr [EDI + 0x2a]
    s.ax = with_ax(s.ax, m.r16((s.di+0x0000002au)));
  }
  { // 0x6e4b28: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e4b2a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e4b2b: e8c0f1daff CALL 0x00493cf0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6e4b30: 8b4f2c MOV ECX,dword ptr [EDI + 0x2c]
    s.cx = m.r32((s.di+0x0000002cu));
  }
  { // 0x6e4b33: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e4b34: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e4b36: e8d5f1daff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x6e4b3b: 8d5f30 LEA EBX,[EDI + 0x30]
    s.bx = (s.di+0x00000030u);
  }
  { // 0x6e4b3e: bd64000000 MOV EBP,0x64
    s.bp = 0x00000064u;
  }
  L006e4b43: { // 0x6e4b43: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x6e4b45: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e4b47: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e4b48: e8c3f1daff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x6e4b4d: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  { // 0x6e4b50: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  { // 0x6e4b51: 75f0 JNZ 0x006e4b43
    if(integer::condition("JNZ",flags)) goto L006e4b43;
  }
  { // 0x6e4b53: 8b87c0010000 MOV EAX,dword ptr [EDI + 0x1c0]
    s.ax = m.r32((s.di+0x000001c0u));
  }
  { // 0x6e4b59: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e4b5b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e4b5c: e8aff1daff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[7u].target;
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  { // 0x6e4b61: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e4b62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e4b63: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6e4b64: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e4b65: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002ea7f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ea7f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6ea7f1: 8b1d7088a200 MOV EBX,dword ptr [0x00a28870]
    s.bx = m.r32((0x00a28870u));
  }
  { // 0x6ea7f7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6ea7f8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ea7f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ea7fa: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6ea7fc: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6ea7fe: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x6ea800: 7e4c JLE 0x006ea84e
    if(integer::condition("JLE",flags)) goto L006ea84e;
  }
  L006ea802: { // 0x6ea802: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  { // 0x6ea807: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6ea80a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6ea80c: 743b JZ 0x006ea849
    if(integer::condition("JZ",flags)) goto L006ea849;
  }
  { // 0x6ea80e: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x6ea811: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ea813: 7534 JNZ 0x006ea849
    if(integer::condition("JNZ",flags)) goto L006ea849;
  }
  { // 0x6ea815: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6ea81a: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6ea820: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ea822: 7508 JNZ 0x006ea82c
    if(integer::condition("JNZ",flags)) goto L006ea82c;
  }
  { // 0x6ea824: 8a8135010000 MOV AL,byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  { // 0x6ea82a: eb05 JMP 0x006ea831
    goto L006ea831;
  }
  L006ea82c: { // 0x6ea82c: e87f9fe0ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006ea831: { // 0x6ea831: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ea833: 7414 JZ 0x006ea849
    if(integer::condition("JZ",flags)) goto L006ea849;
  }
  { // 0x6ea835: 8a4677 MOV AL,byte ptr [ESI + 0x77]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000077u)));
  }
  { // 0x6ea838: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ea83a: 750d JNZ 0x006ea849
    if(integer::condition("JNZ",flags)) goto L006ea849;
  }
  { // 0x6ea83c: 8b86ac010000 MOV EAX,dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  { // 0x6ea842: 8d55ff LEA EDX,[EBP + -0x1]
    s.dx = (s.bp-0x00000001u);
  }
  { // 0x6ea845: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6ea847: 740c JZ 0x006ea855
    if(integer::condition("JZ",flags)) goto L006ea855;
  }
  L006ea849: { // 0x6ea849: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6ea84a: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x6ea84c: 7cb4 JL 0x006ea802
    if(integer::condition("JL",flags)) goto L006ea802;
  }
  L006ea84e: { // 0x6ea84e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ea84f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ea850: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6ea851: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6ea853: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ea854: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ea855: { // 0x6ea855: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ea856: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ea857: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6ea858: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6ea85a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ea85b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ea860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ea860: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ea861: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6ea862: 8b1d7088a200 MOV EBX,dword ptr [0x00a28870]
    s.bx = m.r32((0x00a28870u));
  }
  { // 0x6ea868: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6ea869: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ea86a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x6ea86c: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6ea86e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6ea870: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  { // 0x6ea874: 7e51 JLE 0x006ea8c7
    if(integer::condition("JLE",flags)) goto L006ea8c7;
  }
  { // 0x6ea876: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ea877: { // 0x6ea877: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  { // 0x6ea87c: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6ea87f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6ea881: 7437 JZ 0x006ea8ba
    if(integer::condition("JZ",flags)) goto L006ea8ba;
  }
  { // 0x6ea883: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x6ea886: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ea888: 7530 JNZ 0x006ea8ba
    if(integer::condition("JNZ",flags)) goto L006ea8ba;
  }
  { // 0x6ea88a: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6ea88f: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6ea895: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ea897: 7508 JNZ 0x006ea8a1
    if(integer::condition("JNZ",flags)) goto L006ea8a1;
  }
  { // 0x6ea899: 8a8135010000 MOV AL,byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  { // 0x6ea89f: eb05 JMP 0x006ea8a6
    goto L006ea8a6;
  }
  L006ea8a1: { // 0x6ea8a1: e80a9fe0ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006ea8a6: { // 0x6ea8a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ea8a8: 7410 JZ 0x006ea8ba
    if(integer::condition("JZ",flags)) goto L006ea8ba;
  }
  { // 0x6ea8aa: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6ea8ae: 8b86ac010000 MOV EAX,dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  { // 0x6ea8b4: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x6ea8b5: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6ea8b7: 7501 JNZ 0x006ea8ba
    if(integer::condition("JNZ",flags)) goto L006ea8ba;
  }
  { // 0x6ea8b9: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L006ea8ba: { // 0x6ea8ba: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6ea8bb: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x6ea8bd: 7cb8 JL 0x006ea877
    if(integer::condition("JL",flags)) goto L006ea877;
  }
  { // 0x6ea8bf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ea8c0: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x6ea8c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ea8c3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6ea8c4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ea8c5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6ea8c6: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ea8c7: { // 0x6ea8c7: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x6ea8c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ea8ca: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6ea8cb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ea8cc: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6ea8cd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eacf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eacf0: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  { // 0x6eacf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6eacf6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6eacf7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eacf8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6eacfa: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6eacfb: 7e62 JLE 0x006ead5f
    if(integer::condition("JLE",flags)) goto L006ead5f;
  }
  { // 0x6eacfd: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x6eacff: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6ead01: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x6ead03: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  { // 0x6ead05: 7e3b JLE 0x006ead42
    if(integer::condition("JLE",flags)) goto L006ead42;
  }
  L006ead07: { // 0x6ead07: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  { // 0x6ead0c: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6ead0f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6ead11: 7426 JZ 0x006ead39
    if(integer::condition("JZ",flags)) goto L006ead39;
  }
  { // 0x6ead13: f6461401 TEST byte ptr [ESI + 0x14],0x1
    (void)integer::logical((m.r8((s.si+0x00000014u)))&(0x00000001u),8,flags);
  }
  { // 0x6ead17: 7420 JZ 0x006ead39
    if(integer::condition("JZ",flags)) goto L006ead39;
  }
  { // 0x6ead19: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6ead1b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ead1d: ff929c000000 CALL dword ptr [EDX + 0x9c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000009cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ead23: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ead25: 7412 JZ 0x006ead39
    if(integer::condition("JZ",flags)) goto L006ead39;
  }
  { // 0x6ead27: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6ead29: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  { // 0x6ead2b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ead2d: ff901c030000 CALL dword ptr [EAX + 0x31c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000031cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ead33: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  { // 0x6ead35: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x6ead37: 7426 JZ 0x006ead5f
    if(integer::condition("JZ",flags)) goto L006ead5f;
  }
  L006ead39: { // 0x6ead39: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6ead3a: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  { // 0x6ead3c: 7cc9 JL 0x006ead07
    if(integer::condition("JL",flags)) goto L006ead07;
  }
  { // 0x6ead3e: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x6ead40: 741d JZ 0x006ead5f
    if(integer::condition("JZ",flags)) goto L006ead5f;
  }
  L006ead42: { // 0x6ead42: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x6ead48: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6ead4a: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x6ead4f: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  { // 0x6ead54: 8b8948060000 MOV ECX,dword ptr [ECX + 0x648]
    s.cx = m.r32((s.cx+0x00000648u));
  }
  { // 0x6ead5a: e811dc0100 CALL 0x00708970
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006ead5f: { // 0x6ead5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ead60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ead61: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6ead62: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ead63: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ead70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ead70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6ead71: 8b1d7088a200 MOV EBX,dword ptr [0x00a28870]
    s.bx = m.r32((0x00a28870u));
  }
  { // 0x6ead77: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6ead78: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ead79: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6ead7b: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x6ead7d: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6ead7f: 7e5e JLE 0x006eaddf
    if(integer::condition("JLE",flags)) goto L006eaddf;
  }
  { // 0x6ead81: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ead82: { // 0x6ead82: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  { // 0x6ead87: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6ead8a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6ead8c: 744b JZ 0x006eadd9
    if(integer::condition("JZ",flags)) goto L006eadd9;
  }
  { // 0x6ead8e: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x6ead91: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ead93: 7544 JNZ 0x006eadd9
    if(integer::condition("JNZ",flags)) goto L006eadd9;
  }
  { // 0x6ead95: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6ead9a: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6eada0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6eada2: 7508 JNZ 0x006eadac
    if(integer::condition("JNZ",flags)) goto L006eadac;
  }
  { // 0x6eada4: 8a8135010000 MOV AL,byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  { // 0x6eadaa: eb05 JMP 0x006eadb1
    goto L006eadb1;
  }
  L006eadac: { // 0x6eadac: e8ff99e0ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006eadb1: { // 0x6eadb1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6eadb3: 7424 JZ 0x006eadd9
    if(integer::condition("JZ",flags)) goto L006eadd9;
  }
  { // 0x6eadb5: 8b8eac010000 MOV ECX,dword ptr [ESI + 0x1ac]
    s.cx = m.r32((s.si+0x000001acu));
  }
  { // 0x6eadbb: 8d45ff LEA EAX,[EBP + -0x1]
    s.ax = (s.bp-0x00000001u);
  }
  { // 0x6eadbe: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x6eadc0: 750a JNZ 0x006eadcc
    if(integer::condition("JNZ",flags)) goto L006eadcc;
  }
  { // 0x6eadc2: c786ac010000ffffffff MOV dword ptr [ESI + 0x1ac],0xffffffff
    m.w32((s.si+0x000001acu), 0xffffffffu);
  }
  L006eadcc: { // 0x6eadcc: 8a4e77 MOV CL,byte ptr [ESI + 0x77]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000077u)));
  }
  { // 0x6eadcf: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6eadd1: 7406 JZ 0x006eadd9
    if(integer::condition("JZ",flags)) goto L006eadd9;
  }
  { // 0x6eadd3: 8986ac010000 MOV dword ptr [ESI + 0x1ac],EAX
    m.w32((s.si+0x000001acu), s.ax);
  }
  L006eadd9: { // 0x6eadd9: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6eadda: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x6eaddc: 7ca4 JL 0x006ead82
    if(integer::condition("JL",flags)) goto L006ead82;
  }
  { // 0x6eadde: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eaddf: { // 0x6eaddf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6eade0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6eade1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6eade2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eadf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eadf0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6eadf1: 8b1d7088a200 MOV EBX,dword ptr [0x00a28870]
    s.bx = m.r32((0x00a28870u));
  }
  { // 0x6eadf7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6eadf8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6eadf9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6eadfb: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x6eadfd: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6eadff: 7e51 JLE 0x006eae52
    if(integer::condition("JLE",flags)) goto L006eae52;
  }
  { // 0x6eae01: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006eae02: { // 0x6eae02: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  { // 0x6eae07: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x6eae0a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6eae0c: 743e JZ 0x006eae4c
    if(integer::condition("JZ",flags)) goto L006eae4c;
  }
  { // 0x6eae0e: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x6eae11: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6eae13: 7537 JNZ 0x006eae4c
    if(integer::condition("JNZ",flags)) goto L006eae4c;
  }
  { // 0x6eae15: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6eae1a: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6eae20: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6eae22: 7508 JNZ 0x006eae2c
    if(integer::condition("JNZ",flags)) goto L006eae2c;
  }
  { // 0x6eae24: 8a8135010000 MOV AL,byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  { // 0x6eae2a: eb05 JMP 0x006eae31
    goto L006eae31;
  }
  L006eae2c: { // 0x6eae2c: e87f99e0ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006eae31: { // 0x6eae31: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6eae33: 7417 JZ 0x006eae4c
    if(integer::condition("JZ",flags)) goto L006eae4c;
  }
  { // 0x6eae35: 8b86ac010000 MOV EAX,dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  { // 0x6eae3b: 8d55ff LEA EDX,[EBP + -0x1]
    s.dx = (s.bp-0x00000001u);
  }
  { // 0x6eae3e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6eae40: 750a JNZ 0x006eae4c
    if(integer::condition("JNZ",flags)) goto L006eae4c;
  }
  { // 0x6eae42: c786ac010000ffffffff MOV dword ptr [ESI + 0x1ac],0xffffffff
    m.w32((s.si+0x000001acu), 0xffffffffu);
  }
  L006eae4c: { // 0x6eae4c: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6eae4d: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x6eae4f: 7cb1 JL 0x006eae02
    if(integer::condition("JL",flags)) goto L006eae02;
  }
  { // 0x6eae51: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eae52: { // 0x6eae52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6eae53: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6eae54: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6eae55: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ec450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ec450: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6ec451: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6ec452: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ec453: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ec454: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x6ec456: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6ec458: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6ec45a: 8b6f10 MOV EBP,dword ptr [EDI + 0x10]
    s.bp = m.r32((s.di+0x00000010u));
  }
  { // 0x6ec45d: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x6ec45f: 7e17 JLE 0x006ec478
    if(integer::condition("JLE",flags)) goto L006ec478;
  }
  L006ec461: { // 0x6ec461: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x6ec464: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6ec466: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6ec469: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ec46a: e8f1e9edff CALL 0x005cae60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ec46f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ec471: 750c JNZ 0x006ec47f
    if(integer::condition("JNZ",flags)) goto L006ec47f;
  }
  { // 0x6ec473: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6ec474: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x6ec476: 7ce9 JL 0x006ec461
    if(integer::condition("JL",flags)) goto L006ec461;
  }
  L006ec478: { // 0x6ec478: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ec479: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ec47a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6ec47b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6ec47d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ec47e: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ec47f: { // 0x6ec47f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ec480: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ec481: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6ec482: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6ec484: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ec485: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ff450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ff450: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ff451: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ff452: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6ff454: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6ff456: 742e JZ 0x006ff486
    if(integer::condition("JZ",flags)) goto L006ff486;
  }
  { // 0x6ff458: a188e0a100 MOV EAX,[0x00a1e088]
    s.ax = m.r32((0x00a1e088u));
  }
  { // 0x6ff45d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6ff45f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ff461: 7e23 JLE 0x006ff486
    if(integer::condition("JLE",flags)) goto L006ff486;
  }
  L006ff463: { // 0x6ff463: a17ce0a100 MOV EAX,[0x00a1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  { // 0x6ff468: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ff469: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6ff46c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x6ff46f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ff470: e8ebe30600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ff475: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6ff478: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ff47a: 7410 JZ 0x006ff48c
    if(integer::condition("JZ",flags)) goto L006ff48c;
  }
  { // 0x6ff47c: a188e0a100 MOV EAX,[0x00a1e088]
    s.ax = m.r32((0x00a1e088u));
  }
  { // 0x6ff481: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6ff482: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6ff484: 7cdd JL 0x006ff463
    if(integer::condition("JL",flags)) goto L006ff463;
  }
  L006ff486: { // 0x6ff486: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ff487: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x6ff48a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ff48b: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ff48c: { // 0x6ff48c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6ff48e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ff48f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ff490: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00301130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x701130: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x701131: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x701132: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x701134: 8b8704080000 MOV EAX,dword ptr [EDI + 0x804]
    s.ax = m.r32((s.di+0x00000804u));
  }
  { // 0x70113a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70113c: 7535 JNZ 0x00701173
    if(integer::condition("JNZ",flags)) goto L00701173;
  }
  { // 0x70113e: 8b8700080000 MOV EAX,dword ptr [EDI + 0x800]
    s.ax = m.r32((s.di+0x00000800u));
  }
  { // 0x701144: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x701146: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x701148: 7e29 JLE 0x00701173
    if(integer::condition("JLE",flags)) goto L00701173;
  }
  { // 0x70114a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70114b: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0070114d: { // 0x70114d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x70114f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x701150: e851c30600 CALL 0x0076d4a6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x701155: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x701157: 8b8700080000 MOV EAX,dword ptr [EDI + 0x800]
    s.ax = m.r32((s.di+0x00000800u));
  }
  { // 0x70115d: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x70115e: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x701161: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x701163: 7ce8 JL 0x0070114d
    if(integer::condition("JL",flags)) goto L0070114d;
  }
  { // 0x701165: c7870408000001000000 MOV dword ptr [EDI + 0x804],0x1
    m.w32((s.di+0x00000804u), 0x00000001u);
  }
  { // 0x70116f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x701170: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x701171: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x701172: c3 RET
    finish(m,s,f,0u); return;
  }
  L00701173: { // 0x701173: c7870408000001000000 MOV dword ptr [EDI + 0x804],0x1
    m.w32((s.di+0x00000804u), 0x00000001u);
  }
  { // 0x70117d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70117e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70117f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00301180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x701180: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x701181: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x701182: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x701183: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x701185: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x701187: 39af04080000 CMP dword ptr [EDI + 0x804],EBP
    (void)integer::sub(m.r32((s.di+0x00000804u)),s.bp,32,flags);
  }
  { // 0x70118d: 7432 JZ 0x007011c1
    if(integer::condition("JZ",flags)) goto L007011c1;
  }
  { // 0x70118f: 8b8700080000 MOV EAX,dword ptr [EDI + 0x800]
    s.ax = m.r32((s.di+0x00000800u));
  }
  { // 0x701195: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x701197: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x701199: 7e26 JLE 0x007011c1
    if(integer::condition("JLE",flags)) goto L007011c1;
  }
  { // 0x70119b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70119c: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0070119e: { // 0x70119e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x7011a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7011a1: e80cc30600 CALL 0x0076d4b2
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7011a6: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x7011a8: 8b8700080000 MOV EAX,dword ptr [EDI + 0x800]
    s.ax = m.r32((s.di+0x00000800u));
  }
  { // 0x7011ae: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x7011af: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x7011b2: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x7011b4: 7ce8 JL 0x0070119e
    if(integer::condition("JL",flags)) goto L0070119e;
  }
  { // 0x7011b6: 89af04080000 MOV dword ptr [EDI + 0x804],EBP
    m.w32((s.di+0x00000804u), s.bp);
  }
  { // 0x7011bc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7011bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7011be: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7011bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x7011c0: c3 RET
    finish(m,s,f,0u); return;
  }
  L007011c1: { // 0x7011c1: 89af04080000 MOV dword ptr [EDI + 0x804],EBP
    m.w32((s.di+0x00000804u), s.bp);
  }
  { // 0x7011c7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7011c8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7011c9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x7011ca: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00303620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x703620: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x703621: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x703622: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x703624: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x703626: 742e JZ 0x00703656
    if(integer::condition("JZ",flags)) goto L00703656;
  }
  { // 0x703628: a13087a200 MOV EAX,[0x00a28730]
    s.ax = m.r32((0x00a28730u));
  }
  { // 0x70362d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x70362f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x703631: 7e23 JLE 0x00703656
    if(integer::condition("JLE",flags)) goto L00703656;
  }
  L00703633: { // 0x703633: a12487a200 MOV EAX,[0x00a28724]
    s.ax = m.r32((0x00a28724u));
  }
  { // 0x703638: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x703639: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x70363c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x70363f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x703640: e81ba20600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x703645: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x703648: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70364a: 7410 JZ 0x0070365c
    if(integer::condition("JZ",flags)) goto L0070365c;
  }
  { // 0x70364c: a13087a200 MOV EAX,[0x00a28730]
    s.ax = m.r32((0x00a28730u));
  }
  { // 0x703651: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x703652: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x703654: 7cdd JL 0x00703633
    if(integer::condition("JL",flags)) goto L00703633;
  }
  L00703656: { // 0x703656: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x703657: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x70365a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70365b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0070365c: { // 0x70365c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x70365e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70365f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703660: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00303b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x703b00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x703b01: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x703b02: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x703b04: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x703b05: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x703b06: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x703b08: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x703b0d: e84e9d0600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x703b12: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x703b15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x703b17: 7461 JZ 0x00703b7a
    if(integer::condition("JZ",flags)) goto L00703b7a;
  }
  { // 0x703b19: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x703b1a: 687c907b00 PUSH 0x7b907c
    f.push(m,0x007b907cu);
  }
  { // 0x703b1f: e83c9d0600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x703b24: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x703b27: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x703b29: 744f JZ 0x00703b7a
    if(integer::condition("JZ",flags)) goto L00703b7a;
  }
  { // 0x703b2b: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x703b2e: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x703b30: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x703b32: 7e1f JLE 0x00703b53
    if(integer::condition("JLE",flags)) goto L00703b53;
  }
  L00703b34: { // 0x703b34: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x703b37: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x703b38: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x703b3b: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x703b3e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x703b3f: e81c9d0600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x703b44: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x703b47: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x703b49: 7425 JZ 0x00703b70
    if(integer::condition("JZ",flags)) goto L00703b70;
  }
  { // 0x703b4b: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x703b4e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x703b4f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x703b51: 7ce1 JL 0x00703b34
    if(integer::condition("JL",flags)) goto L00703b34;
  }
  L00703b53: { // 0x703b53: 68d8020000 PUSH 0x2d8
    f.push(m,0x000002d8u);
  }
  { // 0x703b58: e8fa9d0600 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x703b5d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x703b60: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x703b62: 7416 JZ 0x00703b7a
    if(integer::condition("JZ",flags)) goto L00703b7a;
  }
  { // 0x703b64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x703b65: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x703b67: e8f4f1ffff CALL 0x00702d60
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x703b6c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x703b6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703b6e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x703b6f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00703b70: { // 0x703b70: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x703b73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x703b74: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x703b77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703b78: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x703b79: c3 RET
    finish(m,s,f,0u); return;
  }
  L00703b7a: { // 0x703b7a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x703b7b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703b7c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x703b7e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x703b7f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00304d70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x704d70: a1d881ab00 MOV EAX,[0x00ab81d8]
    s.ax = m.r32((0x00ab81d8u));
  }
  { // 0x704d75: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x704d76: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x704d77: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  { // 0x704d7a: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x704d7c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x704d7e: 7c20 JL 0x00704da0
    if(integer::condition("JL",flags)) goto L00704da0;
  }
  L00704d80: { // 0x704d80: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x704d82: e8093dd2ff CALL 0x00428a90
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x704d87: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x704d89: a1cc81ab00 MOV EAX,[0x00ab81cc]
    s.ax = m.r32((0x00ab81ccu));
  }
  { // 0x704d8e: 8b14b0 MOV EDX,dword ptr [EAX + ESI*0x4]
    s.dx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x704d91: 8b92b0000000 MOV EDX,dword ptr [EDX + 0xb0]
    s.dx = m.r32((s.dx+0x000000b0u));
  }
  { // 0x704d97: 803c1100 CMP byte ptr [ECX + EDX*0x1],0x0
    (void)integer::sub(m.r8((s.cx+(s.dx * 0x00000001u))),0x00000000u,8,flags);
  }
  { // 0x704d9b: 7508 JNZ 0x00704da5
    if(integer::condition("JNZ",flags)) goto L00704da5;
  }
  { // 0x704d9d: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x704d9e: 79e0 JNS 0x00704d80
    if(integer::condition("JNS",flags)) goto L00704d80;
  }
  L00704da0: { // 0x704da0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x704da1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x704da2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x704da4: c3 RET
    finish(m,s,f,0u); return;
  }
  L00704da5: { // 0x704da5: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x704da8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x704da9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x704daa: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003053e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7053e0: a1d881ab00 MOV EAX,[0x00ab81d8]
    s.ax = m.r32((0x00ab81d8u));
  }
  { // 0x7053e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7053e6: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  { // 0x7053e9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7053eb: 7c11 JL 0x007053fe
    if(integer::condition("JL",flags)) goto L007053fe;
  }
  L007053ed: { // 0x7053ed: 8b0dcc81ab00 MOV ECX,dword ptr [0x00ab81cc]
    s.cx = m.r32((0x00ab81ccu));
  }
  { // 0x7053f3: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x7053f6: e845000000 CALL 0x00705440
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7053fb: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x7053fc: 79ef JNS 0x007053ed
    if(integer::condition("JNS",flags)) goto L007053ed;
  }
  L007053fe: { // 0x7053fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7053ff: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00305710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x705710: a1d881ab00 MOV EAX,[0x00ab81d8]
    s.ax = m.r32((0x00ab81d8u));
  }
  { // 0x705715: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x705716: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x705717: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x705719: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  { // 0x70571c: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x70571e: 7c17 JL 0x00705737
    if(integer::condition("JL",flags)) goto L00705737;
  }
  L00705720: { // 0x705720: 8b0dcc81ab00 MOV ECX,dword ptr [0x00ab81cc]
    s.cx = m.r32((0x00ab81ccu));
  }
  { // 0x705726: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x705729: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x70572b: 7407 JZ 0x00705734
    if(integer::condition("JZ",flags)) goto L00705734;
  }
  { // 0x70572d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x70572f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x705731: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00705734: { // 0x705734: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x705735: 79e9 JNS 0x00705720
    if(integer::condition("JNS",flags)) goto L00705720;
  }
  L00705737: { // 0x705737: a1cc81ab00 MOV EAX,[0x00ab81cc]
    s.ax = m.r32((0x00ab81ccu));
  }
  { // 0x70573c: 891dd881ab00 MOV dword ptr [0x00ab81d8],EBX
    m.w32((0x00ab81d8u), s.bx);
  }
  { // 0x705742: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x705744: 7417 JZ 0x0070575d
    if(integer::condition("JZ",flags)) goto L0070575d;
  }
  { // 0x705746: 381dd581ab00 CMP byte ptr [0x00ab81d5],BL
    (void)integer::sub(m.r8((0x00ab81d5u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x70574c: 740f JZ 0x0070575d
    if(integer::condition("JZ",flags)) goto L0070575d;
  }
  { // 0x70574e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70574f: e8277f0600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x705754: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x705757: 891dcc81ab00 MOV dword ptr [0x00ab81cc],EBX
    m.w32((0x00ab81ccu), s.bx);
  }
  L0070575d: { // 0x70575d: 881dd581ab00 MOV byte ptr [0x00ab81d5],BL
    m.w8((0x00ab81d5u), (s.bx & 0xffu));
  }
  { // 0x705763: 891dd081ab00 MOV dword ptr [0x00ab81d0],EBX
    m.w32((0x00ab81d0u), s.bx);
  }
  { // 0x705769: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70576a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70576b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00307ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x707ec0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x707ec1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x707ec2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x707ec3: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x707ec5: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x707ec7: bee0317e00 MOV ESI,0x7e31e0
    s.si = 0x007e31e0u;
  }
  L00707ecc: { // 0x707ecc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x707ece: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x707ecf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x707ed0: e88b590600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x707ed5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x707ed8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x707eda: 7413 JZ 0x00707eef
    if(integer::condition("JZ",flags)) goto L00707eef;
  }
  { // 0x707edc: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x707edf: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x707ee0: 81fe28327e00 CMP ESI,0x7e3228
    (void)integer::sub(s.si,0x007e3228u,32,flags);
  }
  { // 0x707ee6: 7ce4 JL 0x00707ecc
    if(integer::condition("JL",flags)) goto L00707ecc;
  }
  { // 0x707ee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x707ee9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x707eea: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x707eed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x707eee: c3 RET
    finish(m,s,f,0u); return;
  }
  L00707eef: { // 0x707eef: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x707ef1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x707ef2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x707ef3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x707ef4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00308ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x708ef0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x708ef1: b95082ab00 MOV ECX,0xab8250
    s.cx = 0x00ab8250u;
  }
  { // 0x708ef6: e8f5e3cfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x708efb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x708efd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x708eff: 7463 JZ 0x00708f64
    if(integer::condition("JZ",flags)) goto L00708f64;
  }
  { // 0x708f01: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x708f02: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00708f03: { // 0x708f03: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x708f05: e806e4cfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x708f0a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x708f0c: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x708f0f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x708f11: 750b JNZ 0x00708f1e
    if(integer::condition("JNZ",flags)) goto L00708f1e;
  }
  { // 0x708f13: 8d560c LEA EDX,[ESI + 0xc]
    s.dx = (s.si+0x0000000cu);
  }
  { // 0x708f16: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  { // 0x708f19: e852feffff CALL 0x00708d70
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00708f1e: { // 0x708f1e: 8d7e0c LEA EDI,[ESI + 0xc]
    s.di = (s.si+0x0000000cu);
  }
  { // 0x708f21: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x708f23: e818d2cfff CALL 0x00406140
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x708f28: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x708f2a: 7530 JNZ 0x00708f5c
    if(integer::condition("JNZ",flags)) goto L00708f5c;
  }
  { // 0x708f2c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x708f2e: e84dd2cfff CALL 0x00406180
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x708f33: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x708f35: 740b JZ 0x00708f42
    if(integer::condition("JZ",flags)) goto L00708f42;
  }
  { // 0x708f37: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x708f39: e822d7cfff CALL 0x00406660
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x708f3e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x708f40: 751a JNZ 0x00708f5c
    if(integer::condition("JNZ",flags)) goto L00708f5c;
  }
  L00708f42: { // 0x708f42: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x708f44: e837e4cfff CALL 0x00407380
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x708f49: 8b0dc482ab00 MOV ECX,dword ptr [0x00ab82c4]
    s.cx = m.r32((0x00ab82c4u));
  }
  { // 0x708f4f: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x708f51: e80ae5cfff CALL 0x00407460
    const std::uint32_t call_target=f.boundaries[7u].target;
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  { // 0x708f56: ff0dc882ab00 DEC dword ptr [0x00ab82c8]
    m.w32((0x00ab82c8u), integer::decrement(m.r32((0x00ab82c8u)),32,flags));
  }
  L00708f5c: { // 0x708f5c: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x708f5e: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  { // 0x708f60: 75a1 JNZ 0x00708f03
    if(integer::condition("JNZ",flags)) goto L00708f03;
  }
  { // 0x708f62: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x708f63: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00708f64: { // 0x708f64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x708f65: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00308f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x708f70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x708f71: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x708f72: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x708f73: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x708f75: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x708f77: b95082ab00 MOV ECX,0xab8250
    s.cx = 0x00ab8250u;
  }
  { // 0x708f7c: e86fe3cfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x708f81: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x708f83: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x708f85: 7437 JZ 0x00708fbe
    if(integer::condition("JZ",flags)) goto L00708fbe;
  }
  L00708f87: { // 0x708f87: 855e2c TEST dword ptr [ESI + 0x2c],EBX
    (void)integer::logical((m.r32((s.si+0x0000002cu)))&(s.bx),32,flags);
  }
  { // 0x708f8a: 7425 JZ 0x00708fb1
    if(integer::condition("JZ",flags)) goto L00708fb1;
  }
  { // 0x708f8c: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x708f8f: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x708f91: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x708f93: 751c JNZ 0x00708fb1
    if(integer::condition("JNZ",flags)) goto L00708fb1;
  }
  { // 0x708f95: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x708f98: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x708f9b: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x708f9d: 7512 JNZ 0x00708fb1
    if(integer::condition("JNZ",flags)) goto L00708fb1;
  }
  { // 0x708f9f: 8b5628 MOV EDX,dword ptr [ESI + 0x28]
    s.dx = m.r32((s.si+0x00000028u));
  }
  { // 0x708fa2: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x708fa5: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x708fa7: 7508 JNZ 0x00708fb1
    if(integer::condition("JNZ",flags)) goto L00708fb1;
  }
  { // 0x708fa9: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x708fac: e82fd0cfff CALL 0x00405fe0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00708fb1: { // 0x708fb1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x708fb3: e858e3cfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x708fb8: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x708fba: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x708fbc: 75c9 JNZ 0x00708f87
    if(integer::condition("JNZ",flags)) goto L00708f87;
  }
  L00708fbe: { // 0x708fbe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x708fbf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x708fc0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x708fc1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00308fd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x708fd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x708fd1: b95082ab00 MOV ECX,0xab8250
    s.cx = 0x00ab8250u;
  }
  { // 0x708fd6: e815e3cfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x708fdb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x708fdd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x708fdf: 743a JZ 0x0070901b
    if(integer::condition("JZ",flags)) goto L0070901b;
  }
  { // 0x708fe1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00708fe2: { // 0x708fe2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x708fe4: e827e3cfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x708fe9: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x708fec: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x708fee: e85dcdcfff CALL 0x00405d50
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x708ff3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x708ff5: e886e3cfff CALL 0x00407380
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x708ffa: 8b0dc482ab00 MOV ECX,dword ptr [0x00ab82c4]
    s.cx = m.r32((0x00ab82c4u));
  }
  { // 0x709000: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x709002: e859e4cfff CALL 0x00407460
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x709007: 8b0dc882ab00 MOV ECX,dword ptr [0x00ab82c8]
    s.cx = m.r32((0x00ab82c8u));
  }
  { // 0x70900d: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x70900f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x709010: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x709012: 890dc882ab00 MOV dword ptr [0x00ab82c8],ECX
    m.w32((0x00ab82c8u), s.cx);
  }
  { // 0x709018: 75c8 JNZ 0x00708fe2
    if(integer::condition("JNZ",flags)) goto L00708fe2;
  }
  { // 0x70901a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0070901b: { // 0x70901b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70901c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00309070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x709070: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x709071: b95082ab00 MOV ECX,0xab8250
    s.cx = 0x00ab8250u;
  }
  { // 0x709076: e875e2cfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70907b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x70907d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x70907f: 7427 JZ 0x007090a8
    if(integer::condition("JZ",flags)) goto L007090a8;
  }
  L00709081: { // 0x709081: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x709084: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x709085: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x709088: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x70908b: e8b0d0cfff CALL 0x00406140
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x709090: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x709092: 7407 JZ 0x0070909b
    if(integer::condition("JZ",flags)) goto L0070909b;
  }
  { // 0x709094: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x709096: e855c3cfff CALL 0x004053f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0070909b: { // 0x70909b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x70909d: e86ee2cfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x7090a2: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x7090a4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7090a6: 75d9 JNZ 0x00709081
    if(integer::condition("JNZ",flags)) goto L00709081;
  }
  L007090a8: { // 0x7090a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7090a9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003090b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7090b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7090b1: b95082ab00 MOV ECX,0xab8250
    s.cx = 0x00ab8250u;
  }
  { // 0x7090b6: e835e2cfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7090bb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x7090bd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7090bf: 7439 JZ 0x007090fa
    if(integer::condition("JZ",flags)) goto L007090fa;
  }
  L007090c1: { // 0x7090c1: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x7090c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7090c6: 7425 JZ 0x007090ed
    if(integer::condition("JZ",flags)) goto L007090ed;
  }
  { // 0x7090c8: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x7090cb: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x7090cc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7090ce: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x7090d1: 7d07 JGE 0x007090da
    if(integer::condition("JGE",flags)) goto L007090da;
  }
  { // 0x7090d3: c7463000000000 MOV dword ptr [ESI + 0x30],0x0
    m.w32((s.si+0x00000030u), 0x00000000u);
  }
  L007090da: { // 0x7090da: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x7090dd: e85ed0cfff CALL 0x00406140
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7090e2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7090e4: 7407 JZ 0x007090ed
    if(integer::condition("JZ",flags)) goto L007090ed;
  }
  { // 0x7090e6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x7090e8: e853c3cfff CALL 0x00405440
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L007090ed: { // 0x7090ed: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7090ef: e81ce2cfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x7090f4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x7090f6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7090f8: 75c7 JNZ 0x007090c1
    if(integer::condition("JNZ",flags)) goto L007090c1;
  }
  L007090fa: { // 0x7090fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7090fb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00309500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x709500: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x709501: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x709502: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x709504: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x709506: 743d JZ 0x00709545
    if(integer::condition("JZ",flags)) goto L00709545;
  }
  { // 0x709508: a1a882ab00 MOV EAX,[0x00ab82a8]
    s.ax = m.r32((0x00ab82a8u));
  }
  { // 0x70950d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x70950f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x709511: 7e32 JLE 0x00709545
    if(integer::condition("JLE",flags)) goto L00709545;
  }
  L00709513: { // 0x709513: a19c82ab00 MOV EAX,[0x00ab829c]
    s.ax = m.r32((0x00ab829cu));
  }
  { // 0x709518: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x70951b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x70951d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70951f: 7407 JZ 0x00709528
    if(integer::condition("JZ",flags)) goto L00709528;
  }
  { // 0x709521: e82abccfff CALL 0x00405150
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x709526: eb05 JMP 0x0070952d
    goto L0070952d;
  }
  L00709528: { // 0x709528: b8a4337e00 MOV EAX,0x7e33a4
    s.ax = 0x007e33a4u;
  }
  L0070952d: { // 0x70952d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70952e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70952f: e82c430600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x709534: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x709537: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x709539: 7410 JZ 0x0070954b
    if(integer::condition("JZ",flags)) goto L0070954b;
  }
  { // 0x70953b: a1a882ab00 MOV EAX,[0x00ab82a8]
    s.ax = m.r32((0x00ab82a8u));
  }
  { // 0x709540: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x709541: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x709543: 7cce JL 0x00709513
    if(integer::condition("JL",flags)) goto L00709513;
  }
  L00709545: { // 0x709545: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x709546: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x709549: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70954a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0070954b: { // 0x70954b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x70954d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70954e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70954f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00309550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x709550: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x709551: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x709552: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x709554: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x709556: 744f JZ 0x007095a7
    if(integer::condition("JZ",flags)) goto L007095a7;
  }
  { // 0x709558: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x70955d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70955e: e8fd420600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x709563: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x709566: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x709568: 743d JZ 0x007095a7
    if(integer::condition("JZ",flags)) goto L007095a7;
  }
  { // 0x70956a: a1a882ab00 MOV EAX,[0x00ab82a8]
    s.ax = m.r32((0x00ab82a8u));
  }
  { // 0x70956f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x709571: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x709573: 7e32 JLE 0x007095a7
    if(integer::condition("JLE",flags)) goto L007095a7;
  }
  L00709575: { // 0x709575: a19c82ab00 MOV EAX,[0x00ab829c]
    s.ax = m.r32((0x00ab829cu));
  }
  { // 0x70957a: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x70957d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x70957f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x709581: 7407 JZ 0x0070958a
    if(integer::condition("JZ",flags)) goto L0070958a;
  }
  { // 0x709583: e8c8bbcfff CALL 0x00405150
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x709588: eb05 JMP 0x0070958f
    goto L0070958f;
  }
  L0070958a: { // 0x70958a: b8a4337e00 MOV EAX,0x7e33a4
    s.ax = 0x007e33a4u;
  }
  L0070958f: { // 0x70958f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x709590: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x709591: e8ca420600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x709596: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x709599: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70959b: 740f JZ 0x007095ac
    if(integer::condition("JZ",flags)) goto L007095ac;
  }
  { // 0x70959d: a1a882ab00 MOV EAX,[0x00ab82a8]
    s.ax = m.r32((0x00ab82a8u));
  }
  { // 0x7095a2: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x7095a3: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x7095a5: 7cce JL 0x00709575
    if(integer::condition("JL",flags)) goto L00709575;
  }
  L007095a7: { // 0x7095a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7095a8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7095aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7095ab: c3 RET
    finish(m,s,f,0u); return;
  }
  L007095ac: { // 0x7095ac: 8b0d9c82ab00 MOV ECX,dword ptr [0x00ab829c]
    s.cx = m.r32((0x00ab829cu));
  }
  { // 0x7095b2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7095b3: 8b04b1 MOV EAX,dword ptr [ECX + ESI*0x4]
    s.ax = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x7095b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7095b7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030a680(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70a680: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70a681: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70a682: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x70a684: b91083ab00 MOV ECX,0xab8310
    s.cx = 0x00ab8310u;
  }
  { // 0x70a689: e862cccfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70a68e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a690: 7410 JZ 0x0070a6a2
    if(integer::condition("JZ",flags)) goto L0070a6a2;
  }
  L0070a692: { // 0x70a692: 39780c CMP dword ptr [EAX + 0xc],EDI
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),s.di,32,flags);
  }
  { // 0x70a695: 7464 JZ 0x0070a6fb
    if(integer::condition("JZ",flags)) goto L0070a6fb;
  }
  { // 0x70a697: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x70a699: e872cccfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x70a69e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a6a0: 75f0 JNZ 0x0070a692
    if(integer::condition("JNZ",flags)) goto L0070a692;
  }
  L0070a6a2: { // 0x70a6a2: a1c883ab00 MOV EAX,[0x00ab83c8]
    s.ax = m.r32((0x00ab83c8u));
  }
  { // 0x70a6a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a6a9: 7405 JZ 0x0070a6b0
    if(integer::condition("JZ",flags)) goto L0070a6b0;
  }
  { // 0x70a6ab: 39780c CMP dword ptr [EAX + 0xc],EDI
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),s.di,32,flags);
  }
  { // 0x70a6ae: 744b JZ 0x0070a6fb
    if(integer::condition("JZ",flags)) goto L0070a6fb;
  }
  L0070a6b0: { // 0x70a6b0: be8483ab00 MOV ESI,0xab8384
    s.si = 0x00ab8384u;
  }
  L0070a6b5: { // 0x70a6b5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x70a6b7: e834cccfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x70a6bc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a6be: 7410 JZ 0x0070a6d0
    if(integer::condition("JZ",flags)) goto L0070a6d0;
  }
  L0070a6c0: { // 0x70a6c0: 39780c CMP dword ptr [EAX + 0xc],EDI
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),s.di,32,flags);
  }
  { // 0x70a6c3: 7436 JZ 0x0070a6fb
    if(integer::condition("JZ",flags)) goto L0070a6fb;
  }
  { // 0x70a6c5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x70a6c7: e844cccfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x70a6cc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a6ce: 75f0 JNZ 0x0070a6c0
    if(integer::condition("JNZ",flags)) goto L0070a6c0;
  }
  L0070a6d0: { // 0x70a6d0: 83ee0c SUB ESI,0xc
    s.si = integer::sub(s.si,0x0000000cu,32,flags);
  }
  { // 0x70a6d3: 81fe6083ab00 CMP ESI,0xab8360
    (void)integer::sub(s.si,0x00ab8360u,32,flags);
  }
  { // 0x70a6d9: 7dda JGE 0x0070a6b5
    if(integer::condition("JGE",flags)) goto L0070a6b5;
  }
  { // 0x70a6db: b9e882ab00 MOV ECX,0xab82e8
    s.cx = 0x00ab82e8u;
  }
  { // 0x70a6e0: e80bcccfff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x70a6e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a6e7: 7410 JZ 0x0070a6f9
    if(integer::condition("JZ",flags)) goto L0070a6f9;
  }
  L0070a6e9: { // 0x70a6e9: 39780c CMP dword ptr [EAX + 0xc],EDI
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),s.di,32,flags);
  }
  { // 0x70a6ec: 740d JZ 0x0070a6fb
    if(integer::condition("JZ",flags)) goto L0070a6fb;
  }
  { // 0x70a6ee: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x70a6f0: e81bcccfff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x70a6f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a6f7: 75f0 JNZ 0x0070a6e9
    if(integer::condition("JNZ",flags)) goto L0070a6e9;
  }
  L0070a6f9: { // 0x70a6f9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0070a6fb: { // 0x70a6fb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70a6fc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70a6fd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030a700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70a700: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x70a701: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70a702: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x70a704: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x70a706: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x70a708: 743c JZ 0x0070a746
    if(integer::condition("JZ",flags)) goto L0070a746;
  }
  { // 0x70a70a: a1c083ab00 MOV EAX,[0x00ab83c0]
    s.ax = m.r32((0x00ab83c0u));
  }
  { // 0x70a70f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70a710: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x70a712: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a714: 7e20 JLE 0x0070a736
    if(integer::condition("JLE",flags)) goto L0070a736;
  }
  L0070a716: { // 0x70a716: a1b483ab00 MOV EAX,[0x00ab83b4]
    s.ax = m.r32((0x00ab83b4u));
  }
  { // 0x70a71b: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x70a71e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70a71f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70a720: e83b310600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70a725: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x70a728: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a72a: 741f JZ 0x0070a74b
    if(integer::condition("JZ",flags)) goto L0070a74b;
  }
  { // 0x70a72c: a1c083ab00 MOV EAX,[0x00ab83c0]
    s.ax = m.r32((0x00ab83c0u));
  }
  { // 0x70a731: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x70a732: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x70a734: 7ce0 JL 0x0070a716
    if(integer::condition("JL",flags)) goto L0070a716;
  }
  L0070a736: { // 0x70a736: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x70a73a: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x70a73d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x70a73e: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  { // 0x70a740: e83bfdffff CALL 0x0070a480
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x70a745: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0070a746: { // 0x70a746: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70a747: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70a748: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0070a74b: { // 0x70a74b: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x70a74f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x70a751: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x70a752: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  { // 0x70a754: e827fdffff CALL 0x0070a480
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x70a759: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70a75a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70a75b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70a75c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0030aa40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70aa40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70aa41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70aa42: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x70aa44: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x70aa46: 7c60 JL 0x0070aaa8
    if(integer::condition("JL",flags)) goto L0070aaa8;
  }
  { // 0x70aa48: 3b3dc083ab00 CMP EDI,dword ptr [0x00ab83c0]
    (void)integer::sub(s.di,m.r32((0x00ab83c0u)),32,flags);
  }
  { // 0x70aa4e: 7d58 JGE 0x0070aaa8
    if(integer::condition("JGE",flags)) goto L0070aaa8;
  }
  { // 0x70aa50: a1b483ab00 MOV EAX,[0x00ab83b4]
    s.ax = m.r32((0x00ab83b4u));
  }
  { // 0x70aa55: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x70aa58: e823fcffff CALL 0x0070a680
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70aa5d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x70aa5f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x70aa61: 7445 JZ 0x0070aaa8
    if(integer::condition("JZ",flags)) goto L0070aaa8;
  }
  L0070aa63: { // 0x70aa63: 397604 CMP dword ptr [ESI + 0x4],ESI
    (void)integer::sub(m.r32((s.si+0x00000004u)),s.si,32,flags);
  }
  { // 0x70aa66: 7407 JZ 0x0070aa6f
    if(integer::condition("JZ",flags)) goto L0070aa6f;
  }
  { // 0x70aa68: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x70aa6a: e811c9cfff CALL 0x00407380
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0070aa6f: { // 0x70aa6f: 3b35c883ab00 CMP ESI,dword ptr [0x00ab83c8]
    (void)integer::sub(s.si,m.r32((0x00ab83c8u)),32,flags);
  }
  { // 0x70aa75: 750a JNZ 0x0070aa81
    if(integer::condition("JNZ",flags)) goto L0070aa81;
  }
  { // 0x70aa77: c705c883ab0000000000 MOV dword ptr [0x00ab83c8],0x0
    m.w32((0x00ab83c8u), 0x00000000u);
  }
  L0070aa81: { // 0x70aa81: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x70aa84: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70aa85: c7414802000000 MOV dword ptr [ECX + 0x48],0x2
    m.w32((s.cx+0x00000048u), 0x00000002u);
  }
  { // 0x70aa8c: e8ea2b0600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x70aa91: 8b15b483ab00 MOV EDX,dword ptr [0x00ab83b4]
    s.dx = m.r32((0x00ab83b4u));
  }
  { // 0x70aa97: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x70aa9a: 8b0cba MOV ECX,dword ptr [EDX + EDI*0x4]
    s.cx = m.r32((s.dx+(s.di * 0x00000004u)));
  }
  { // 0x70aa9d: e8defbffff CALL 0x0070a680
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x70aaa2: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x70aaa4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x70aaa6: 75bb JNZ 0x0070aa63
    if(integer::condition("JNZ",flags)) goto L0070aa63;
  }
  L0070aaa8: { // 0x70aaa8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70aaa9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70aaaa: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030b200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b200: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70b201: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x70b203: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x70b205: 7505 JNZ 0x0070b20c
    if(integer::condition("JNZ",flags)) goto L0070b20c;
  }
  { // 0x70b207: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x70b20a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70b20b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0070b20c: { // 0x70b20c: a1c083ab00 MOV EAX,[0x00ab83c0]
    s.ax = m.r32((0x00ab83c0u));
  }
  { // 0x70b211: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70b212: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x70b214: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b216: 7e20 JLE 0x0070b238
    if(integer::condition("JLE",flags)) goto L0070b238;
  }
  L0070b218: { // 0x70b218: a1b483ab00 MOV EAX,[0x00ab83b4]
    s.ax = m.r32((0x00ab83b4u));
  }
  { // 0x70b21d: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x70b220: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70b221: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70b222: e839260600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70b227: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x70b22a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b22c: 7410 JZ 0x0070b23e
    if(integer::condition("JZ",flags)) goto L0070b23e;
  }
  { // 0x70b22e: a1c083ab00 MOV EAX,[0x00ab83c0]
    s.ax = m.r32((0x00ab83c0u));
  }
  { // 0x70b233: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x70b234: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x70b236: 7ce0 JL 0x0070b218
    if(integer::condition("JL",flags)) goto L0070b218;
  }
  L0070b238: { // 0x70b238: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70b239: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x70b23c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70b23d: c3 RET
    finish(m,s,f,0u); return;
  }
  L0070b23e: { // 0x70b23e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x70b240: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70b241: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70b242: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030b280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b280: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70b281: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70b282: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x70b284: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x70b286: 743d JZ 0x0070b2c5
    if(integer::condition("JZ",flags)) goto L0070b2c5;
  }
  { // 0x70b288: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x70b28d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70b28e: e8cd250600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70b293: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x70b296: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b298: 742b JZ 0x0070b2c5
    if(integer::condition("JZ",flags)) goto L0070b2c5;
  }
  { // 0x70b29a: a1c083ab00 MOV EAX,[0x00ab83c0]
    s.ax = m.r32((0x00ab83c0u));
  }
  { // 0x70b29f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x70b2a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b2a3: 7e20 JLE 0x0070b2c5
    if(integer::condition("JLE",flags)) goto L0070b2c5;
  }
  L0070b2a5: { // 0x70b2a5: a1b483ab00 MOV EAX,[0x00ab83b4]
    s.ax = m.r32((0x00ab83b4u));
  }
  { // 0x70b2aa: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x70b2ad: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70b2ae: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70b2af: e8ac250600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x70b2b4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x70b2b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b2b9: 740f JZ 0x0070b2ca
    if(integer::condition("JZ",flags)) goto L0070b2ca;
  }
  { // 0x70b2bb: a1c083ab00 MOV EAX,[0x00ab83c0]
    s.ax = m.r32((0x00ab83c0u));
  }
  { // 0x70b2c0: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x70b2c1: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x70b2c3: 7ce0 JL 0x0070b2a5
    if(integer::condition("JL",flags)) goto L0070b2a5;
  }
  L0070b2c5: { // 0x70b2c5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70b2c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x70b2c8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70b2c9: c3 RET
    finish(m,s,f,0u); return;
  }
  L0070b2ca: { // 0x70b2ca: 8b15b483ab00 MOV EDX,dword ptr [0x00ab83b4]
    s.dx = m.r32((0x00ab83b4u));
  }
  { // 0x70b2d0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70b2d1: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x70b2d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70b2d5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00315be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x715be0: a1501e8200 MOV EAX,[0x00821e50]
    s.ax = m.r32((0x00821e50u));
  }
  { // 0x715be5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x715be6: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x715be8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x715be9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x715beb: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x715bed: 7e23 JLE 0x00715c12
    if(integer::condition("JLE",flags)) goto L00715c12;
  }
  L00715bef: { // 0x715bef: a1441e8200 MOV EAX,[0x00821e44]
    s.ax = m.r32((0x00821e44u));
  }
  { // 0x715bf4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x715bf5: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x715bf8: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x715bfb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x715bfc: e85f7c0500 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x715c01: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x715c04: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x715c06: 740f JZ 0x00715c17
    if(integer::condition("JZ",flags)) goto L00715c17;
  }
  { // 0x715c08: a1501e8200 MOV EAX,[0x00821e50]
    s.ax = m.r32((0x00821e50u));
  }
  { // 0x715c0d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x715c0e: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x715c10: 7cdd JL 0x00715bef
    if(integer::condition("JL",flags)) goto L00715bef;
  }
  L00715c12: { // 0x715c12: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x715c13: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x715c15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x715c16: c3 RET
    finish(m,s,f,0u); return;
  }
  L00715c17: { // 0x715c17: 8b15441e8200 MOV EDX,dword ptr [0x00821e44]
    s.dx = m.r32((0x00821e44u));
  }
  { // 0x715c1d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x715c1e: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x715c21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x715c22: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00324840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x724840: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x724841: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x724843: e808bae8ff CALL 0x005b0250
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x724848: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x72484e: e8ddbce0ff CALL 0x00530530
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x724853: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  { // 0x724856: 7428 JZ 0x00724880
    if(integer::condition("JZ",flags)) goto L00724880;
  }
  L00724858: { // 0x724858: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x72485e: e81dbde0ff CALL 0x00530580
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x724863: 663d1b00 CMP AX,0x1b
    (void)integer::sub((s.ax & 0xffffu),0x0000001bu,16,flags);
  }
  { // 0x724867: 7507 JNZ 0x00724870
    if(integer::condition("JNZ",flags)) goto L00724870;
  }
  { // 0x724869: c6864404000001 MOV byte ptr [ESI + 0x444],0x1
    m.w8((s.si+0x00000444u), 0x00000001u);
  }
  L00724870: { // 0x724870: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x724876: e8b5bce0ff CALL 0x00530530
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x72487b: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  { // 0x72487e: 75d8 JNZ 0x00724858
    if(integer::condition("JNZ",flags)) goto L00724858;
  }
  L00724880: { // 0x724880: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x724881: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003285e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7285e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7285e1: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x7285e3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7285e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7285e5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x7285e7: 7423 JZ 0x0072860c
    if(integer::condition("JZ",flags)) goto L0072860c;
  }
  { // 0x7285e9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x7285eb: be288e7800 MOV ESI,0x788e28
    s.si = 0x00788e28u;
  }
  L007285f0: { // 0x7285f0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x7285f2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7285f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7285f4: e867520400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7285f9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x7285fc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7285fe: 7412 JZ 0x00728612
    if(integer::condition("JZ",flags)) goto L00728612;
  }
  { // 0x728600: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x728603: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x728604: 81fe548e7800 CMP ESI,0x788e54
    (void)integer::sub(s.si,0x00788e54u,32,flags);
  }
  { // 0x72860a: 7ce4 JL 0x007285f0
    if(integer::condition("JL",flags)) goto L007285f0;
  }
  L0072860c: { // 0x72860c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72860d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72860e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x728610: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x728611: c3 RET
    finish(m,s,f,0u); return;
  }
  L00728612: { // 0x728612: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x728614: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x728615: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x728616: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x728617: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00328af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x728af0: a1e01e8200 MOV EAX,[0x00821ee0]
    s.ax = m.r32((0x00821ee0u));
  }
  { // 0x728af5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x728af6: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x728af8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x728af9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x728afb: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x728afd: 7e23 JLE 0x00728b22
    if(integer::condition("JLE",flags)) goto L00728b22;
  }
  L00728aff: { // 0x728aff: a1d41e8200 MOV EAX,[0x00821ed4]
    s.ax = m.r32((0x00821ed4u));
  }
  { // 0x728b04: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x728b05: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x728b08: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x728b0b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x728b0c: e84f4d0400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x728b11: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x728b14: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x728b16: 7410 JZ 0x00728b28
    if(integer::condition("JZ",flags)) goto L00728b28;
  }
  { // 0x728b18: a1e01e8200 MOV EAX,[0x00821ee0]
    s.ax = m.r32((0x00821ee0u));
  }
  { // 0x728b1d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x728b1e: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x728b20: 7cdd JL 0x00728aff
    if(integer::condition("JL",flags)) goto L00728aff;
  }
  L00728b22: { // 0x728b22: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x728b23: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x728b26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x728b27: c3 RET
    finish(m,s,f,0u); return;
  }
  L00728b28: { // 0x728b28: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x728b2a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x728b2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x728b2c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032b9d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72b9d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72b9d1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x72b9d2: 8b1da0547800 MOV EBX,dword ptr [0x007854a0]
    s.bx = m.r32((0x007854a0u));
  }
  { // 0x72b9d8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x72b9d9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b9da: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72b9db: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x72b9dd: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x72b9df: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x72b9e1: 6846010000 PUSH 0x146
    f.push(m,0x00000146u);
  }
  { // 0x72b9e6: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x72b9e8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72b9e9: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72b9eb: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x72b9ed: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x72b9f1: 7d1c JGE 0x0072ba0f
    if(integer::condition("JGE",flags)) goto L0072ba0f;
  }
  { // 0x72b9f3: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L0072b9f7: { // 0x72b9f7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x72b9f9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b9fa: 6850010000 PUSH 0x150
    f.push(m,0x00000150u);
  }
  { // 0x72b9ff: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72ba00: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72ba02: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x72ba04: 7414 JZ 0x0072ba1a
    if(integer::condition("JZ",flags)) goto L0072ba1a;
  }
  { // 0x72ba06: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x72ba0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x72ba0b: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x72ba0d: 7ce8 JL 0x0072b9f7
    if(integer::condition("JL",flags)) goto L0072b9f7;
  }
  L0072ba0f: { // 0x72ba0f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72ba10: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72ba11: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x72ba12: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x72ba15: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x72ba16: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x72ba17: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0072ba1a: { // 0x72ba1a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72ba1c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72ba1d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72ba1e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x72ba1f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x72ba20: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x72ba21: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003373f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7373f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7373f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7373f2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7373f3: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x7373f5: e8e62c0200 CALL 0x0075a0e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7373fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7373fc: 745a JZ 0x00737458
    if(integer::condition("JZ",flags)) goto L00737458;
  }
  { // 0x7373fe: 8b0dd8fbb000 MOV ECX,dword ptr [0x00b0fbd8]
    s.cx = m.r32((0x00b0fbd8u));
  }
  { // 0x737404: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  { // 0x737409: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x73740b: 7e4b JLE 0x00737458
    if(integer::condition("JLE",flags)) goto L00737458;
  }
  { // 0x73740d: bef8000000 MOV ESI,0xf8
    s.si = 0x000000f8u;
  }
  L00737412: { // 0x737412: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x737414: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x737416: 7c0b JL 0x00737423
    if(integer::condition("JL",flags)) goto L00737423;
  }
  { // 0x737418: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x73741a: 7d07 JGE 0x00737423
    if(integer::condition("JGE",flags)) goto L00737423;
  }
  { // 0x73741c: a1e0fbb000 MOV EAX,[0x00b0fbe0]
    s.ax = m.r32((0x00b0fbe0u));
  }
  { // 0x737421: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00737423: { // 0x737423: 83c018 ADD EAX,0x18
    s.ax = integer::add(s.ax,0x00000018u,32,flags);
  }
  { // 0x737426: 6a3a PUSH 0x3a
    f.push(m,0x0000003au);
  }
  { // 0x737428: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x737429: e842860300 CALL 0x0076fa70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x73742e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x737431: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x737433: 7412 JZ 0x00737447
    if(integer::condition("JZ",flags)) goto L00737447;
  }
  { // 0x737435: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  { // 0x737438: 740d JZ 0x00737447
    if(integer::condition("JZ",flags)) goto L00737447;
  }
  { // 0x73743a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x73743b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x73743d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x73743e: e8fd1e0200 CALL 0x00759340
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x737443: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x737445: 7518 JNZ 0x0073745f
    if(integer::condition("JNZ",flags)) goto L0073745f;
  }
  L00737447: { // 0x737447: 8b0dd8fbb000 MOV ECX,dword ptr [0x00b0fbd8]
    s.cx = m.r32((0x00b0fbd8u));
  }
  { // 0x73744d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x73744e: 81c6f8000000 ADD ESI,0xf8
    s.si = integer::add(s.si,0x000000f8u,32,flags);
  }
  { // 0x737454: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x737456: 7cba JL 0x00737412
    if(integer::condition("JL",flags)) goto L00737412;
  }
  L00737458: { // 0x737458: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x737459: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x73745a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x73745d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x73745e: c3 RET
    finish(m,s,f,0u); return;
  }
  L0073745f: { // 0x73745f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x737461: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x737462: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x737463: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x737464: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00340fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x740fc0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x740fc1: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x740fc5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x740fc6: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x740fca: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x740fcc: 7e11 JLE 0x00740fdf
    if(integer::condition("JLE",flags)) goto L00740fdf;
  }
  { // 0x740fce: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x740fcf: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00740fd1: { // 0x740fd1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x740fd3: e848830100 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x740fd8: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x740fdb: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x740fdc: 75f3 JNZ 0x00740fd1
    if(integer::condition("JNZ",flags)) goto L00740fd1;
  }
  { // 0x740fde: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00740fdf: { // 0x740fdf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x740fe0: e896c60200 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x740fe5: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x740fe8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x740fe9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x740fea: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_003422e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7422e0: e8eb83feff CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7422e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7422e7: 7412 JZ 0x007422fb
    if(integer::condition("JZ",flags)) goto L007422fb;
  }
  L007422e9: { // 0x7422e9: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x7422eb: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x7422ed: e8ae80feff CALL 0x0072a3a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7422f2: e8d983feff CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x7422f7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7422f9: 75ee JNZ 0x007422e9
    if(integer::condition("JNZ",flags)) goto L007422e9;
  }
  L007422fb: { // 0x7422fb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00352630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x752630: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x752631: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x752633: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x752634: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x752636: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  { // 0x752639: 7e12 JLE 0x0075264d
    if(integer::condition("JLE",flags)) goto L0075264d;
  }
  L0075263b: { // 0x75263b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x75263e: 8d0cb8 LEA ECX,[EAX + EDI*0x4]
    s.cx = (s.ax+(s.di * 0x00000004u));
  }
  { // 0x752641: e8da6c0000 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x752646: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x752648: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x752649: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x75264b: 7cee JL 0x0075263b
    if(integer::condition("JL",flags)) goto L0075263b;
  }
  L0075264d: { // 0x75264d: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x752653: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x752654: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x752655: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003531b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7531b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7531b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7531b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7531b4: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x7531b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7531b9: 7507 JNZ 0x007531c2
    if(integer::condition("JNZ",flags)) goto L007531c2;
  }
  { // 0x7531bb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7531bc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x7531be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7531bf: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L007531c2: { // 0x7531c2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x7531c6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x7531c8: ff5618 CALL dword ptr [ESI + 0x18]
    const std::uint32_t call_target=m.r32((s.si+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7531cb: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x7531ce: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x7531d3: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x7531d5: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x7531d6: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x7531d8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x7531da: 8b3490 MOV ESI,dword ptr [EAX + EDX*0x4]
    s.si = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x7531dd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7531df: 7507 JNZ 0x007531e8
    if(integer::condition("JNZ",flags)) goto L007531e8;
  }
  { // 0x7531e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7531e2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x7531e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7531e5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L007531e8: { // 0x7531e8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7531e9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7531eb: e8c0610000 CALL 0x007593b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7531f0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x7531f2: 750c JNZ 0x00753200
    if(integer::condition("JNZ",flags)) goto L00753200;
  }
  { // 0x7531f4: 8b7670 MOV ESI,dword ptr [ESI + 0x70]
    s.si = m.r32((s.si+0x00000070u));
  }
  { // 0x7531f7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7531f9: 75ed JNZ 0x007531e8
    if(integer::condition("JNZ",flags)) goto L007531e8;
  }
  { // 0x7531fb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7531fc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7531fd: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753200: { // 0x753200: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753202: 7507 JNZ 0x0075320b
    if(integer::condition("JNZ",flags)) goto L0075320b;
  }
  { // 0x753204: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753205: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753207: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753208: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0075320b: { // 0x75320b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x75320f: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x753212: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753213: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x753215: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x753217: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753218: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00353610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x753610: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x753611: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x753613: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x753614: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x753617: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x753619: 7507 JNZ 0x00753622
    if(integer::condition("JNZ",flags)) goto L00753622;
  }
  { // 0x75361b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75361c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x75361e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75361f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753622: { // 0x753622: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x753626: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x753628: ff5618 CALL dword ptr [ESI + 0x18]
    const std::uint32_t call_target=m.r32((s.si+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75362b: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75362e: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x753633: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x753635: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x753636: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x753638: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75363a: 8b3490 MOV ESI,dword ptr [EAX + EDX*0x4]
    s.si = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x75363d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75363f: 7507 JNZ 0x00753648
    if(integer::condition("JNZ",flags)) goto L00753648;
  }
  { // 0x753641: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753642: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753644: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753645: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753648: { // 0x753648: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x753649: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75364b: e8605d0000 CALL 0x007593b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x753650: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x753652: 750c JNZ 0x00753660
    if(integer::condition("JNZ",flags)) goto L00753660;
  }
  { // 0x753654: 8b7608 MOV ESI,dword ptr [ESI + 0x8]
    s.si = m.r32((s.si+0x00000008u));
  }
  { // 0x753657: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753659: 75ed JNZ 0x00753648
    if(integer::condition("JNZ",flags)) goto L00753648;
  }
  { // 0x75365b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75365c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75365d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753660: { // 0x753660: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753662: 7507 JNZ 0x0075366b
    if(integer::condition("JNZ",flags)) goto L0075366b;
  }
  { // 0x753664: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753665: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753667: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753668: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0075366b: { // 0x75366b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x75366f: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x753672: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753673: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x753675: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x753677: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753678: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00353c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x753c50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x753c51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x753c53: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x753c54: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x753c57: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x753c59: 7507 JNZ 0x00753c62
    if(integer::condition("JNZ",flags)) goto L00753c62;
  }
  { // 0x753c5b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753c5c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753c5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753c5f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753c62: { // 0x753c62: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x753c66: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x753c68: ff5618 CALL dword ptr [ESI + 0x18]
    const std::uint32_t call_target=m.r32((s.si+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x753c6b: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x753c6e: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x753c73: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x753c75: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x753c76: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x753c78: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x753c7a: 8b3490 MOV ESI,dword ptr [EAX + EDX*0x4]
    s.si = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x753c7d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753c7f: 7507 JNZ 0x00753c88
    if(integer::condition("JNZ",flags)) goto L00753c88;
  }
  { // 0x753c81: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753c82: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753c84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753c85: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753c88: { // 0x753c88: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x753c89: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x753c8b: e820570000 CALL 0x007593b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x753c90: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x753c92: 750c JNZ 0x00753ca0
    if(integer::condition("JNZ",flags)) goto L00753ca0;
  }
  { // 0x753c94: 8b7608 MOV ESI,dword ptr [ESI + 0x8]
    s.si = m.r32((s.si+0x00000008u));
  }
  { // 0x753c97: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753c99: 75ed JNZ 0x00753c88
    if(integer::condition("JNZ",flags)) goto L00753c88;
  }
  { // 0x753c9b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753c9c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753c9d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753ca0: { // 0x753ca0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753ca2: 7507 JNZ 0x00753cab
    if(integer::condition("JNZ",flags)) goto L00753cab;
  }
  { // 0x753ca4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753ca5: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753ca7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753ca8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753cab: { // 0x753cab: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x753caf: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x753cb2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753cb3: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x753cb5: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x753cb7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753cb8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00353e30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x753e30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x753e31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x753e33: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x753e34: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x753e37: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x753e39: 7507 JNZ 0x00753e42
    if(integer::condition("JNZ",flags)) goto L00753e42;
  }
  { // 0x753e3b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753e3c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753e3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753e3f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753e42: { // 0x753e42: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x753e46: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x753e48: ff5618 CALL dword ptr [ESI + 0x18]
    const std::uint32_t call_target=m.r32((s.si+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x753e4b: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x753e4e: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x753e53: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x753e55: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x753e56: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x753e58: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x753e5a: 8b3490 MOV ESI,dword ptr [EAX + EDX*0x4]
    s.si = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x753e5d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753e5f: 7507 JNZ 0x00753e68
    if(integer::condition("JNZ",flags)) goto L00753e68;
  }
  { // 0x753e61: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753e62: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753e64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753e65: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753e68: { // 0x753e68: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x753e69: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x753e6b: e840550000 CALL 0x007593b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x753e70: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x753e72: 750f JNZ 0x00753e83
    if(integer::condition("JNZ",flags)) goto L00753e83;
  }
  { // 0x753e74: 8bb610010000 MOV ESI,dword ptr [ESI + 0x110]
    s.si = m.r32((s.si+0x00000110u));
  }
  { // 0x753e7a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753e7c: 75ea JNZ 0x00753e68
    if(integer::condition("JNZ",flags)) goto L00753e68;
  }
  { // 0x753e7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753e7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753e80: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753e83: { // 0x753e83: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x753e85: 7507 JNZ 0x00753e8e
    if(integer::condition("JNZ",flags)) goto L00753e8e;
  }
  { // 0x753e87: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753e88: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x753e8a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753e8b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00753e8e: { // 0x753e8e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x753e92: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x753e95: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x753e96: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x753e98: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x753e9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x753e9b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_003573b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7573b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7573b1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7573b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7573b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7573b4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x7573b8: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x7573ba: 8b4740 MOV EAX,dword ptr [EDI + 0x40]
    s.ax = m.r32((s.di+0x00000040u));
  }
  { // 0x7573bd: 8d6f4c LEA EBP,[EDI + 0x4c]
    s.bp = (s.di+0x0000004cu);
  }
  { // 0x7573c0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x7573c1: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  { // 0x7573c4: c7450000000000 MOV dword ptr [EBP],0x0
    m.w32((s.bp), 0x00000000u);
  }
  { // 0x7573cb: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x7573cd: 8d7750 LEA ESI,[EDI + 0x50]
    s.si = (s.di+0x00000050u);
  }
  { // 0x7573d0: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x7573d3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7573d5: 7e1d JLE 0x007573f4
    if(integer::condition("JLE",flags)) goto L007573f4;
  }
  L007573d7: { // 0x7573d7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x7573d9: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x7573db: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x7573de: e88da7ecff CALL 0x00621b70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7573e3: 8b4740 MOV EAX,dword ptr [EDI + 0x40]
    s.ax = m.r32((s.di+0x00000040u));
  }
  { // 0x7573e6: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x7573e7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x7573e8: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  { // 0x7573eb: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x7573ed: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x7573f0: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x7573f2: 7ce3 JL 0x007573d7
    if(integer::condition("JL",flags)) goto L007573d7;
  }
  L007573f4: { // 0x7573f4: 8b7f40 MOV EDI,dword ptr [EDI + 0x40]
    s.di = m.r32((s.di+0x00000040u));
  }
  { // 0x7573f7: 83e703 AND EDI,0x3
    s.di = integer::logical((s.di)&(0x00000003u),32,flags);
  }
  { // 0x7573fa: 741e JZ 0x0075741a
    if(integer::condition("JZ",flags)) goto L0075741a;
  }
  { // 0x7573fc: 8d04fd00000000 LEA EAX,[EDI*0x8 + 0x0]
    s.ax = ((s.di * 0x00000008u)+0x00000000u);
  }
  { // 0x757403: b920000000 MOV ECX,0x20
    s.cx = 0x00000020u;
  }
  { // 0x757408: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75740a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75740c: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  { // 0x75740f: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x757411: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x757413: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x757415: e856a7ecff CALL 0x00621b70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0075741a: { // 0x75741a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75741b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75741c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x75741d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75741e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035c320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75c320: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75c321: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75c322: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x75c324: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0075c326: { // 0x75c326: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x75c328: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75c32a: 7436 JZ 0x0075c362
    if(integer::condition("JZ",flags)) goto L0075c362;
  }
  { // 0x75c32c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c32d: e8132c0100 CALL 0x0076ef45
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75c332: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c335: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x75c337: 7329 JNC 0x0075c362
    if(integer::condition("JNC",flags)) goto L0075c362;
  }
  { // 0x75c339: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x75c33b: 668b0470 MOV AX,word ptr [EAX + ESI*0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+(s.si * 0x00000002u))));
  }
  { // 0x75c33f: 663d4100 CMP AX,0x41
    (void)integer::sub((s.ax & 0xffffu),0x00000041u,16,flags);
  }
  { // 0x75c343: 721a JC 0x0075c35f
    if(integer::condition("JC",flags)) goto L0075c35f;
  }
  { // 0x75c345: 663d5a00 CMP AX,0x5a
    (void)integer::sub((s.ax & 0xffffu),0x0000005au,16,flags);
  }
  { // 0x75c349: 7714 JA 0x0075c35f
    if(integer::condition("JA",flags)) goto L0075c35f;
  }
  { // 0x75c34b: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x75c350: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c351: e8de370100 CALL 0x0076fb34
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75c356: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x75c358: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c35b: 66890471 MOV word ptr [ECX + ESI*0x2],AX
    m.w16((s.cx+(s.si * 0x00000002u)), (s.ax & 0xffffu));
  }
  L0075c35f: { // 0x75c35f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x75c360: ebc4 JMP 0x0075c326
    goto L0075c326;
  }
  L0075c362: { // 0x75c362: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75c363: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c364: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035c410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75c410: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75c411: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75c412: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x75c414: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0075c416: { // 0x75c416: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x75c418: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75c41a: 7436 JZ 0x0075c452
    if(integer::condition("JZ",flags)) goto L0075c452;
  }
  { // 0x75c41c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c41d: e8232b0100 CALL 0x0076ef45
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75c422: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c425: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x75c427: 7329 JNC 0x0075c452
    if(integer::condition("JNC",flags)) goto L0075c452;
  }
  { // 0x75c429: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x75c42b: 668b0470 MOV AX,word ptr [EAX + ESI*0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+(s.si * 0x00000002u))));
  }
  { // 0x75c42f: 663d6100 CMP AX,0x61
    (void)integer::sub((s.ax & 0xffffu),0x00000061u,16,flags);
  }
  { // 0x75c433: 721a JC 0x0075c44f
    if(integer::condition("JC",flags)) goto L0075c44f;
  }
  { // 0x75c435: 663d7a00 CMP AX,0x7a
    (void)integer::sub((s.ax & 0xffffu),0x0000007au,16,flags);
  }
  { // 0x75c439: 7714 JA 0x0075c44f
    if(integer::condition("JA",flags)) goto L0075c44f;
  }
  { // 0x75c43b: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x75c440: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c441: e8cd1e0100 CALL 0x0076e313
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75c446: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x75c448: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c44b: 66890471 MOV word ptr [ECX + ESI*0x2],AX
    m.w16((s.cx+(s.si * 0x00000002u)), (s.ax & 0xffffu));
  }
  L0075c44f: { // 0x75c44f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x75c450: ebc4 JMP 0x0075c416
    goto L0075c416;
  }
  L0075c452: { // 0x75c452: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75c453: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c454: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035d2e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75d2e0: a1fc03b100 MOV EAX,[0x00b103fc]
    s.ax = m.r32((0x00b103fcu));
  }
  { // 0x75d2e5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75d2e6: 8b1dd4517800 MOV EBX,dword ptr [0x007851d4]
    s.bx = m.r32((0x007851d4u));
  }
  { // 0x75d2ec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75d2ee: 744c JZ 0x0075d33c
    if(integer::condition("JZ",flags)) goto L0075d33c;
  }
  { // 0x75d2f0: c705c803b10001000000 MOV dword ptr [0x00b103c8],0x1
    m.w32((0x00b103c8u), 0x00000001u);
  }
  { // 0x75d2fa: a1d003b100 MOV EAX,[0x00b103d0]
    s.ax = m.r32((0x00b103d0u));
  }
  { // 0x75d2ff: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75d301: 7515 JNZ 0x0075d318
    if(integer::condition("JNZ",flags)) goto L0075d318;
  }
  { // 0x75d303: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75d304: 8b35e4517800 MOV ESI,dword ptr [0x007851e4]
    s.si = m.r32((0x007851e4u));
  }
  L0075d30a: { // 0x75d30a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x75d30c: ffd6 CALL ESI
    const std::uint32_t call_target=s.si;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75d30e: a1d003b100 MOV EAX,[0x00b103d0]
    s.ax = m.r32((0x00b103d0u));
  }
  { // 0x75d313: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75d315: 74f3 JZ 0x0075d30a
    if(integer::condition("JZ",flags)) goto L0075d30a;
  }
  { // 0x75d317: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075d318: { // 0x75d318: a1e403b100 MOV EAX,[0x00b103e4]
    s.ax = m.r32((0x00b103e4u));
  }
  { // 0x75d31d: 6888130000 PUSH 0x1388
    f.push(m,0x00001388u);
  }
  { // 0x75d322: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75d323: ff15d0517800 CALL dword ptr [0x007851d0]
    const std::uint32_t call_target=m.r32((0x007851d0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75d329: 8b0de403b100 MOV ECX,dword ptr [0x00b103e4]
    s.cx = m.r32((0x00b103e4u));
  }
  { // 0x75d32f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75d330: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x75d332: c705fc03b10000000000 MOV dword ptr [0x00b103fc],0x0
    m.w32((0x00b103fcu), 0x00000000u);
  }
  L0075d33c: { // 0x75d33c: a1f803b100 MOV EAX,[0x00b103f8]
    s.ax = m.r32((0x00b103f8u));
  }
  { // 0x75d341: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75d343: 740d JZ 0x0075d352
    if(integer::condition("JZ",flags)) goto L0075d352;
  }
  { // 0x75d345: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75d346: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x75d348: c705f803b10000000000 MOV dword ptr [0x00b103f8],0x0
    m.w32((0x00b103f8u), 0x00000000u);
  }
  L0075d352: { // 0x75d352: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75d353: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00364fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x764fe0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x764fe1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x764fe3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x764fe4: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x764fe6: 8b8688000000 MOV EAX,dword ptr [ESI + 0x88]
    s.ax = m.r32((s.si+0x00000088u));
  }
  { // 0x764fec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x764fee: 7e2b JLE 0x0076501b
    if(integer::condition("JLE",flags)) goto L0076501b;
  }
  L00764ff0: { // 0x764ff0: ba20000000 MOV EDX,0x20
    s.dx = 0x00000020u;
  }
  { // 0x764ff5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x764ff7: e8c4efffff CALL 0x00763fc0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x764ffc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x764fff: 7505 JNZ 0x00765006
    if(integer::condition("JNZ",flags)) goto L00765006;
  }
  { // 0x765001: ff4614 INC dword ptr [ESI + 0x14]
    m.w32((s.si+0x00000014u), integer::increment(m.r32((s.si+0x00000014u)),32,flags));
  }
  { // 0x765004: eb0a JMP 0x00765010
    goto L00765010;
  }
  L00765006: { // 0x765006: 83f8f7 CMP EAX,-0x9
    (void)integer::sub(s.ax,0xfffffff7u,32,flags);
  }
  { // 0x765009: 7405 JZ 0x00765010
    if(integer::condition("JZ",flags)) goto L00765010;
  }
  { // 0x76500b: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  { // 0x76500e: 750e JNZ 0x0076501e
    if(integer::condition("JNZ",flags)) goto L0076501e;
  }
  L00765010: { // 0x765010: 8b8688000000 MOV EAX,dword ptr [ESI + 0x88]
    s.ax = m.r32((s.si+0x00000088u));
  }
  { // 0x765016: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x765017: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x765019: 7cd5 JL 0x00764ff0
    if(integer::condition("JL",flags)) goto L00764ff0;
  }
  L0076501b: { // 0x76501b: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076501e: { // 0x76501e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76501f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x765020: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036d7da(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76d7da: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76d7db: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76d7dd: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x76d7e0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76d7e1: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  { // 0x76d7e4: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x76d7e6: 763d JBE 0x0076d825
    if(integer::condition("JBE",flags)) goto L0076d825;
  }
  { // 0x76d7e8: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  { // 0x76d7eb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76d7ec: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x76d7ee: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76d7ef: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L0076d7f2: { // 0x76d7f2: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  { // 0x76d7f5: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076d7f8: { // 0x76d7f8: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x76d7fa: 7712 JA 0x0076d80e
    if(integer::condition("JA",flags)) goto L0076d80e;
  }
  { // 0x76d7fc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76d7fd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76d7fe: ff5514 CALL dword ptr [EBP + 0x14]
    const std::uint32_t call_target=m.r32((s.bp+0x00000014u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76d801: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76d802: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76d804: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76d805: 7e02 JLE 0x0076d809
    if(integer::condition("JLE",flags)) goto L0076d809;
  }
  { // 0x76d807: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0076d809: { // 0x76d809: 037510 ADD ESI,dword ptr [EBP + 0x10]
    s.si = integer::add(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  { // 0x76d80c: ebea JMP 0x0076d7f8
    goto L0076d7f8;
  }
  L0076d80e: { // 0x76d80e: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x76d811: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76d812: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76d813: e810000000 CALL 0x0076d828
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76d818: 2b7d10 SUB EDI,dword ptr [EBP + 0x10]
    s.di = integer::sub(s.di,m.r32((s.bp+0x00000010u)),32,flags);
  }
  { // 0x76d81b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76d81e: 3b7d08 CMP EDI,dword ptr [EBP + 0x8]
    (void)integer::sub(s.di,m.r32((s.bp+0x00000008u)),32,flags);
  }
  { // 0x76d821: 77cf JA 0x0076d7f2
    if(integer::condition("JA",flags)) goto L0076d7f2;
  }
  { // 0x76d823: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76d824: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076d825: { // 0x76d825: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76d826: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x76d827: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036df82(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76df82: 837c2404e0 CMP dword ptr [ESP + 0x4],-0x20
    (void)integer::sub(m.r32((f.sp+0x00000004u)),0xffffffe0u,32,flags);
  }
  { // 0x76df87: 7722 JA 0x0076dfab
    if(integer::condition("JA",flags)) goto L0076dfab;
  }
  L0076df89: { // 0x76df89: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x76df8d: e81c000000 CALL 0x0076dfae
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76df92: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76df94: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76df95: 7516 JNZ 0x0076dfad
    if(integer::condition("JNZ",flags)) goto L0076dfad;
  }
  { // 0x76df97: 39442408 CMP dword ptr [ESP + 0x8],EAX
    (void)integer::sub(m.r32((f.sp+0x00000008u)),s.ax,32,flags);
  }
  { // 0x76df9b: 7410 JZ 0x0076dfad
    if(integer::condition("JZ",flags)) goto L0076dfad;
  }
  { // 0x76df9d: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x76dfa1: e802630000 CALL 0x007742a8
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76dfa6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76dfa8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76dfa9: 75de JNZ 0x0076df89
    if(integer::condition("JNZ",flags)) goto L0076df89;
  }
  L0076dfab: { // 0x76dfab: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076dfad: { // 0x76dfad: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036fc6e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76fc6e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76fc6f: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76fc71: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x76fc72: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76fc73: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fc74: bef06f8100 MOV ESI,0x816ff0
    s.si = 0x00816ff0u;
  }
  { // 0x76fc79: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76fc7a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fc7b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x76fc7d: bbffff0000 MOV EBX,0xffff
    s.bx = 0x0000ffffu;
  }
  { // 0x76fc82: e8e1020000 CALL 0x0076ff68
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76fc87: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fc88: e8b26a0000 CALL 0x0077673f
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76fc8d: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  { // 0x76fc90: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76fc93: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  L0076fc96: { // 0x76fc96: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  { // 0x76fc99: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  { // 0x76fc9c: 7412 JZ 0x0076fcb0
    if(integer::condition("JZ",flags)) goto L0076fcb0;
  }
  { // 0x76fc9e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x76fc9f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fca0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76fca1: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x76fca2: e8e16e0000 CALL 0x00776b88
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x76fca7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fca8: 663bc3 CMP AX,BX
    (void)integer::sub((s.ax & 0xffffu),(s.bx & 0xffffu),16,flags);
  }
  { // 0x76fcab: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fcac: 7413 JZ 0x0076fcc1
    if(integer::condition("JZ",flags)) goto L0076fcc1;
  }
  { // 0x76fcae: ebe6 JMP 0x0076fc96
    goto L0076fc96;
  }
  L0076fcb0: { // 0x76fcb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fcb1: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  { // 0x76fcb3: e8d06e0000 CALL 0x00776b88
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x76fcb8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fcb9: 663bc3 CMP AX,BX
    (void)integer::sub((s.ax & 0xffffu),(s.bx & 0xffffu),16,flags);
  }
  { // 0x76fcbc: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fcbd: 7402 JZ 0x0076fcc1
    if(integer::condition("JZ",flags)) goto L0076fcc1;
  }
  { // 0x76fcbf: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0076fcc1: { // 0x76fcc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fcc2: ff75fc PUSH dword ptr [EBP + -0x4]
    f.push(m,m.r32((s.bp-0x00000004u)));
  }
  { // 0x76fcc5: e8026b0000 CALL 0x007767cc
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x76fcca: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fccb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x76fccd: e8e8020000 CALL 0x0076ffba
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x76fcd2: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x76fcd5: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x76fcd7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76fcd8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76fcd9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76fcda: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76fcdb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370732(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770732: 833d2c0eb10000 CMP dword ptr [0x00b10e2c],0x0
    (void)integer::sub(m.r32((0x00b10e2cu)),0x00000000u,32,flags);
  }
  { // 0x770739: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77073a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77073b: 8b357404b100 MOV ESI,dword ptr [0x00b10474]
    s.si = m.r32((0x00b10474u));
  }
  { // 0x770741: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770742: 7465 JZ 0x007707a9
    if(integer::condition("JZ",flags)) goto L007707a9;
  }
  { // 0x770744: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x770746: 751b JNZ 0x00770763
    if(integer::condition("JNZ",flags)) goto L00770763;
  }
  { // 0x770748: 39357c04b100 CMP dword ptr [0x00b1047c],ESI
    (void)integer::sub(m.r32((0x00b1047cu)),s.si,32,flags);
  }
  { // 0x77074e: 7459 JZ 0x007707a9
    if(integer::condition("JZ",flags)) goto L007707a9;
  }
  { // 0x770750: e8897a0000 CALL 0x007781de
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x770755: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x770757: 7550 JNZ 0x007707a9
    if(integer::condition("JNZ",flags)) goto L007707a9;
  }
  { // 0x770759: 8b357404b100 MOV ESI,dword ptr [0x00b10474]
    s.si = m.r32((0x00b10474u));
  }
  { // 0x77075f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x770761: 7446 JZ 0x007707a9
    if(integer::condition("JZ",flags)) goto L007707a9;
  }
  L00770763: { // 0x770763: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x770767: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x770769: 743e JZ 0x007707a9
    if(integer::condition("JZ",flags)) goto L007707a9;
  }
  { // 0x77076b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77076c: e8ef490000 CALL 0x00775160
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x770771: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770772: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00770774: { // 0x770774: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x770776: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x770778: 742f JZ 0x007707a9
    if(integer::condition("JZ",flags)) goto L007707a9;
  }
  { // 0x77077a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77077b: e8e0490000 CALL 0x00775160
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x770780: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x770782: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770783: 7617 JBE 0x0077079c
    if(integer::condition("JBE",flags)) goto L0077079c;
  }
  { // 0x770785: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x770787: 803c383d CMP byte ptr [EAX + EDI*0x1],0x3d
    (void)integer::sub(m.r8((s.ax+(s.di * 0x00000001u))),0x0000003du,8,flags);
  }
  { // 0x77078b: 750f JNZ 0x0077079c
    if(integer::condition("JNZ",flags)) goto L0077079c;
  }
  { // 0x77078d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77078e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77078f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770790: e80a7a0000 CALL 0x0077819f
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x770795: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x770798: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77079a: 7405 JZ 0x007707a1
    if(integer::condition("JZ",flags)) goto L007707a1;
  }
  L0077079c: { // 0x77079c: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x77079f: ebd3 JMP 0x00770774
    goto L00770774;
  }
  L007707a1: { // 0x7707a1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x7707a3: 8d443801 LEA EAX,[EAX + EDI*0x1 + 0x1]
    s.ax = (s.ax+(s.di * 0x00000001u)+0x00000001u);
  }
  { // 0x7707a7: eb02 JMP 0x007707ab
    goto L007707ab;
  }
  L007707a9: { // 0x7707a9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007707ab: { // 0x7707ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7707ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7707ad: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x7707ae: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370e47(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770e47: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770e48: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x770e4a: 837d0c00 CMP dword ptr [EBP + 0xc],0x0
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),0x00000000u,32,flags);
  }
  { // 0x770e4e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770e4f: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  { // 0x770e52: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770e53: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x770e55: 7f04 JG 0x00770e5b
    if(integer::condition("JG",flags)) goto L00770e5b;
  }
  { // 0x770e57: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x770e59: eb4a JMP 0x00770ea5
    goto L00770ea5;
  }
  L00770e5b: { // 0x770e5b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770e5c: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  { // 0x770e5f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770e60: e8d4f0ffff CALL 0x0076ff39
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x770e65: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770e66: { // 0x770e66: ff4d0c DEC dword ptr [EBP + 0xc]
    m.w32((s.bp+0x0000000cu), integer::decrement(m.r32((s.bp+0x0000000cu)),32,flags));
  }
  { // 0x770e69: 742d JZ 0x00770e98
    if(integer::condition("JZ",flags)) goto L00770e98;
  }
  { // 0x770e6b: ff4e04 DEC dword ptr [ESI + 0x4]
    m.w32((s.si+0x00000004u), integer::decrement(m.r32((s.si+0x00000004u)),32,flags));
  }
  { // 0x770e6e: 780a JS 0x00770e7a
    if(integer::condition("JS",flags)) goto L00770e7a;
  }
  { // 0x770e70: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x770e72: 0fb601 MOVZX EAX,byte ptr [ECX]
    s.ax = (m.r8((s.cx))&integer::mask(8));
  }
  { // 0x770e75: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x770e76: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  { // 0x770e78: eb07 JMP 0x00770e81
    goto L00770e81;
  }
  L00770e7a: { // 0x770e7a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770e7b: e843340000 CALL 0x007742c3
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x770e80: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770e81: { // 0x770e81: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x770e84: 7409 JZ 0x00770e8f
    if(integer::condition("JZ",flags)) goto L00770e8f;
  }
  { // 0x770e86: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  { // 0x770e88: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x770e89: 3c0a CMP AL,0xa
    (void)integer::sub((s.ax & 0xffu),0x0000000au,8,flags);
  }
  { // 0x770e8b: 740b JZ 0x00770e98
    if(integer::condition("JZ",flags)) goto L00770e98;
  }
  { // 0x770e8d: ebd7 JMP 0x00770e66
    goto L00770e66;
  }
  L00770e8f: { // 0x770e8f: 3b7d08 CMP EDI,dword ptr [EBP + 0x8]
    (void)integer::sub(s.di,m.r32((s.bp+0x00000008u)),32,flags);
  }
  { // 0x770e92: 7504 JNZ 0x00770e98
    if(integer::condition("JNZ",flags)) goto L00770e98;
  }
  { // 0x770e94: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x770e96: eb03 JMP 0x00770e9b
    goto L00770e9b;
  }
  L00770e98: { // 0x770e98: 802700 AND byte ptr [EDI],0x0
    m.w8((s.di), integer::logical((m.r8((s.di)))&(0x00000000u),8,flags));
  }
  L00770e9b: { // 0x770e9b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770e9c: e8eaf0ffff CALL 0x0076ff8b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x770ea1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770ea2: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x770ea4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00770ea5: { // 0x770ea5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x770ea6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x770ea7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x770ea8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370fad(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770fad: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770fae: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770faf: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770fb0: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x770fb2: e8ff050000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x770fb7: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x770fb9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770fba: 381d9804b100 CMP byte ptr [0x00b10498],BL
    (void)integer::sub(m.r8((0x00b10498u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x770fc0: be9804b100 MOV ESI,0xb10498
    s.si = 0x00b10498u;
  }
  { // 0x770fc5: 7514 JNZ 0x00770fdb
    if(integer::condition("JNZ",flags)) goto L00770fdb;
  }
  { // 0x770fc7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770fc8: e834010000 CALL 0x00771101
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x770fcd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770fce: { // 0x770fce: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770fcf: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770fd0: e82b810000 CALL 0x00779100
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x770fd5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770fd6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x770fd8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770fd9: 750f JNZ 0x00770fea
    if(integer::condition("JNZ",flags)) goto L00770fea;
  }
  L00770fdb: { // 0x770fdb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770fdc: e881010000 CALL 0x00771162
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x770fe1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x770fe3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770fe4: 74e8 JZ 0x00770fce
    if(integer::condition("JZ",flags)) goto L00770fce;
  }
  { // 0x770fe6: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x770fe8: eb33 JMP 0x0077101d
    goto L0077101d;
  }
  L00770fea: { // 0x770fea: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x770fee: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x770ff0: 7522 JNZ 0x00771014
    if(integer::condition("JNZ",flags)) goto L00771014;
  }
  { // 0x770ff2: e8d43f0000 CALL 0x00774fcb
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x770ff7: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x770ff9: 395f28 CMP dword ptr [EDI + 0x28],EBX
    (void)integer::sub(m.r32((s.di+0x00000028u)),s.bx,32,flags);
  }
  { // 0x770ffc: 7513 JNZ 0x00771011
    if(integer::condition("JNZ",flags)) goto L00771011;
  }
  { // 0x770ffe: 6a0e PUSH 0xe
    f.push(m,0x0000000eu);
  }
  { // 0x771000: e86bcfffff CALL 0x0076df70
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x771005: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x771007: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771008: 894728 MOV dword ptr [EDI + 0x28],EAX
    m.w32((s.di+0x00000028u), s.ax);
  }
  { // 0x77100b: 7504 JNZ 0x00771011
    if(integer::condition("JNZ",flags)) goto L00771011;
  }
  { // 0x77100d: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x77100f: eb0c JMP 0x0077101d
    goto L0077101d;
  }
  L00771011: { // 0x771011: 8b7f28 MOV EDI,dword ptr [EDI + 0x28]
    s.di = m.r32((s.di+0x00000028u));
  }
  L00771014: { // 0x771014: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771015: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x771016: e8f57f0000 CALL 0x00779010
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x77101b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77101c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077101d: { // 0x77101d: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x77101f: e8f3050000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[7u].target;
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  { // 0x771024: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771025: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x771027: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x771028: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x771029: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77102a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00371c09(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x771c09: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x771c0a: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x771c0e: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x771c10: 7e1a JLE 0x00771c2c
    if(integer::condition("JLE",flags)) goto L00771c2c;
  }
  { // 0x771c12: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771c13: 8d742410 LEA ESI,[ESP + 0x10]
    s.si = (f.sp+0x00000010u);
  }
  L00771c17: { // 0x771c17: ff7604 PUSH dword ptr [ESI + 0x4]
    f.push(m,m.r32((s.si+0x00000004u)));
  }
  { // 0x771c1a: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x771c1d: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x771c21: e8fa730000 CALL 0x00779020
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x771c26: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771c27: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x771c28: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771c29: 75ec JNZ 0x00771c17
    if(integer::condition("JNZ",flags)) goto L00771c17;
  }
  { // 0x771c2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00771c2c: { // 0x771c2c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x771c2d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003725db(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7725db: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7725dc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7725dd: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x7725e1: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x7725e3: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x7725e4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7725e6: 7e21 JLE 0x00772609
    if(integer::condition("JLE",flags)) goto L00772609;
  }
  { // 0x7725e8: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L007725ec: { // 0x7725ec: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7725ed: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x7725f1: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x7725f5: e8acffffff CALL 0x007725a6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7725fa: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x7725fd: 833eff CMP dword ptr [ESI],-0x1
    (void)integer::sub(m.r32((s.si)),0xffffffffu,32,flags);
  }
  { // 0x772600: 7407 JZ 0x00772609
    if(integer::condition("JZ",flags)) goto L00772609;
  }
  { // 0x772602: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x772604: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x772605: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x772607: 7fe3 JG 0x007725ec
    if(integer::condition("JG",flags)) goto L007725ec;
  }
  L00772609: { // 0x772609: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77260a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77260b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037260c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77260c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77260d: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x772611: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x772613: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x772614: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x772615: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x772616: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x772618: 7e26 JLE 0x00772640
    if(integer::condition("JLE",flags)) goto L00772640;
  }
  { // 0x77261a: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  { // 0x77261e: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00772622: { // 0x772622: 0fbe06 MOVSX EAX,byte ptr [ESI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si)),8));
  }
  { // 0x772625: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x772626: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x772627: ff74241c PUSH dword ptr [ESP + 0x1c]
    f.push(m,m.r32((f.sp+0x0000001cu)));
  }
  { // 0x77262b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77262c: e875ffffff CALL 0x007725a6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x772631: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x772634: 833fff CMP dword ptr [EDI],-0x1
    (void)integer::sub(m.r32((s.di)),0xffffffffu,32,flags);
  }
  { // 0x772637: 7407 JZ 0x00772640
    if(integer::condition("JZ",flags)) goto L00772640;
  }
  { // 0x772639: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x77263b: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x77263c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77263e: 7fe2 JG 0x00772622
    if(integer::condition("JG",flags)) goto L00772622;
  }
  L00772640: { // 0x772640: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x772641: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x772642: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x772643: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003726e8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7726e8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7726e9: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x7726ed: 0fbe06 MOVSX EAX,byte ptr [ESI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si)),8));
  }
  { // 0x7726f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7726f1: e83ed4ffff CALL 0x0076fb34
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7726f6: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  { // 0x7726f9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7726fa: 742c JZ 0x00772728
    if(integer::condition("JZ",flags)) goto L00772728;
  }
  L007726fc: { // 0x7726fc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x7726fd: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  { // 0x772704: 7e0f JLE 0x00772715
    if(integer::condition("JLE",flags)) goto L00772715;
  }
  { // 0x772706: 0fbe06 MOVSX EAX,byte ptr [ESI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si)),8));
  }
  { // 0x772709: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x77270b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77270c: e8c0270000 CALL 0x00774ed1
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x772711: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x772712: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x772713: eb0f JMP 0x00772724
    goto L00772724;
  }
  L00772715: { // 0x772715: 0fbe06 MOVSX EAX,byte ptr [ESI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si)),8));
  }
  { // 0x772718: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  { // 0x77271e: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  { // 0x772721: 83e004 AND EAX,0x4
    s.ax = integer::logical((s.ax)&(0x00000004u),32,flags);
  }
  L00772724: { // 0x772724: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x772726: 75d4 JNZ 0x007726fc
    if(integer::condition("JNZ",flags)) goto L007726fc;
  }
  L00772728: { // 0x772728: 8a0d70778100 MOV CL,byte ptr [0x00817770]
    s.cx = with_al(s.cx, m.r8((0x00817770u)));
  }
  { // 0x77272e: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  { // 0x772730: 880e MOV byte ptr [ESI],CL
    m.w8((s.si), (s.cx & 0xffu));
  }
  { // 0x772732: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00772733: { // 0x772733: 8a0e MOV CL,byte ptr [ESI]
    s.cx = with_al(s.cx, m.r8((s.si)));
  }
  { // 0x772735: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x772737: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x772739: 8a0e MOV CL,byte ptr [ESI]
    s.cx = with_al(s.cx, m.r8((s.si)));
  }
  { // 0x77273b: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x77273c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x77273e: 75f3 JNZ 0x00772733
    if(integer::condition("JNZ",flags)) goto L00772733;
  }
  { // 0x772740: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x772741: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003764eb(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7764eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7764ec: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7764ed: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x7764f1: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x7764f3: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x7764f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7764f6: 7e21 JLE 0x00776519
    if(integer::condition("JLE",flags)) goto L00776519;
  }
  { // 0x7764f8: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L007764fc: { // 0x7764fc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7764fd: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x776501: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x776505: e8c1ffffff CALL 0x007764cb
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77650a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77650d: 833eff CMP dword ptr [ESI],-0x1
    (void)integer::sub(m.r32((s.si)),0xffffffffu,32,flags);
  }
  { // 0x776510: 7407 JZ 0x00776519
    if(integer::condition("JZ",flags)) goto L00776519;
  }
  { // 0x776512: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x776514: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x776515: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x776517: 7fe3 JG 0x007764fc
    if(integer::condition("JG",flags)) goto L007764fc;
  }
  L00776519: { // 0x776519: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77651a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77651b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037651c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77651c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77651d: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x776521: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x776523: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x776524: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776525: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x776526: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x776528: 7e27 JLE 0x00776551
    if(integer::condition("JLE",flags)) goto L00776551;
  }
  { // 0x77652a: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  { // 0x77652e: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00776532: { // 0x776532: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  { // 0x776535: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x776536: ff74241c PUSH dword ptr [ESP + 0x1c]
    f.push(m,m.r32((f.sp+0x0000001cu)));
  }
  { // 0x77653a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x77653b: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x77653c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77653d: e889ffffff CALL 0x007764cb
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x776542: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x776545: 833fff CMP dword ptr [EDI],-0x1
    (void)integer::sub(m.r32((s.di)),0xffffffffu,32,flags);
  }
  { // 0x776548: 7407 JZ 0x00776551
    if(integer::condition("JZ",flags)) goto L00776551;
  }
  { // 0x77654a: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x77654c: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x77654d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77654f: 7fe1 JG 0x00776532
    if(integer::condition("JG",flags)) goto L00776532;
  }
  L00776551: { // 0x776551: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x776552: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776553: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x776554: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00376ee0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776ee0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x776ee1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776ee2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x776ee3: be000db100 MOV ESI,0xb10d00
    s.si = 0x00b10d00u;
  }
  L00776ee8: { // 0x776ee8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x776eea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x776eec: 7437 JZ 0x00776f25
    if(integer::condition("JZ",flags)) goto L00776f25;
  }
  { // 0x776eee: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x776ef0: 0580040000 ADD EAX,0x480
    s.ax = integer::add(s.ax,0x00000480u,32,flags);
  }
  { // 0x776ef5: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x776ef7: 7321 JNC 0x00776f1a
    if(integer::condition("JNC",flags)) goto L00776f1a;
  }
  { // 0x776ef9: 8d5f0c LEA EBX,[EDI + 0xc]
    s.bx = (s.di+0x0000000cu);
  }
  L00776efc: { // 0x776efc: 837bfc00 CMP dword ptr [EBX + -0x4],0x0
    (void)integer::sub(m.r32((s.bx-0x00000004u)),0x00000000u,32,flags);
  }
  { // 0x776f00: 7407 JZ 0x00776f09
    if(integer::condition("JZ",flags)) goto L00776f09;
  }
  { // 0x776f02: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x776f03: ff15d8517800 CALL dword ptr [0x007851d8]
    const std::uint32_t call_target=m.r32((0x007851d8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00776f09: { // 0x776f09: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x776f0b: 83c724 ADD EDI,0x24
    s.di = integer::add(s.di,0x00000024u,32,flags);
  }
  { // 0x776f0e: 0580040000 ADD EAX,0x480
    s.ax = integer::add(s.ax,0x00000480u,32,flags);
  }
  { // 0x776f13: 83c324 ADD EBX,0x24
    s.bx = integer::add(s.bx,0x00000024u,32,flags);
  }
  { // 0x776f16: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x776f18: 72e2 JC 0x00776efc
    if(integer::condition("JC",flags)) goto L00776efc;
  }
  L00776f1a: { // 0x776f1a: ff36 PUSH dword ptr [ESI]
    f.push(m,m.r32((s.si)));
  }
  { // 0x776f1c: e80770ffff CALL 0x0076df28
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x776f21: 832600 AND dword ptr [ESI],0x0
    m.w32((s.si), integer::logical((m.r32((s.si)))&(0x00000000u),32,flags));
  }
  { // 0x776f24: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00776f25: { // 0x776f25: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x776f28: 81fe000eb100 CMP ESI,0xb10e00
    (void)integer::sub(s.si,0x00b10e00u,32,flags);
  }
  { // 0x776f2e: 7cb8 JL 0x00776ee8
    if(integer::condition("JL",flags)) goto L00776ee8;
  }
  { // 0x776f30: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x776f31: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776f32: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x776f33: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037817a(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77817a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77817b: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77817f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00778180: { // 0x778180: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x778184: ff06 INC dword ptr [ESI]
    m.w32((s.si), integer::increment(m.r32((s.si)),32,flags));
  }
  { // 0x778186: e8cbffffff CALL 0x00778156
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77818b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x77818d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77818e: e81582ffff CALL 0x007703a8
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x778193: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778194: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x778196: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778197: 75e7 JNZ 0x00778180
    if(integer::condition("JNZ",flags)) goto L00778180;
  }
  { // 0x778199: 668bc7 MOV AX,DI
    s.ax = with_ax(s.ax, (s.di & 0xffffu));
  }
  { // 0x77819c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77819d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77819e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00379aa6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x779aa6: 833d300eb10000 CMP dword ptr [0x00b10e30],0x0
    (void)integer::sub(m.r32((0x00b10e30u)),0x00000000u,32,flags);
  }
  { // 0x779aad: 7505 JNZ 0x00779ab4
    if(integer::condition("JNZ",flags)) goto L00779ab4;
  }
  { // 0x779aaf: e876d9ffff CALL 0x0077742a
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00779ab4: { // 0x779ab4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x779ab5: 8b35280eb100 MOV ESI,dword ptr [0x00b10e28]
    s.si = m.r32((0x00b10e28u));
  }
  { // 0x779abb: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  { // 0x779abd: 3c22 CMP AL,0x22
    (void)integer::sub((s.ax & 0xffu),0x00000022u,8,flags);
  }
  { // 0x779abf: 7525 JNZ 0x00779ae6
    if(integer::condition("JNZ",flags)) goto L00779ae6;
  }
  L00779ac1: { // 0x779ac1: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  { // 0x779ac4: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x779ac5: 3c22 CMP AL,0x22
    (void)integer::sub((s.ax & 0xffu),0x00000022u,8,flags);
  }
  { // 0x779ac7: 7415 JZ 0x00779ade
    if(integer::condition("JZ",flags)) goto L00779ade;
  }
  { // 0x779ac9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x779acb: 7411 JZ 0x00779ade
    if(integer::condition("JZ",flags)) goto L00779ade;
  }
  { // 0x779acd: 0fb6c0 MOVZX EAX,AL
    s.ax = ((s.ax & 0xffu)&integer::mask(8));
  }
  { // 0x779ad0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x779ad1: e8ef5a0000 CALL 0x0077f5c5
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x779ad6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x779ad8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x779ad9: 74e6 JZ 0x00779ac1
    if(integer::condition("JZ",flags)) goto L00779ac1;
  }
  { // 0x779adb: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x779adc: ebe3 JMP 0x00779ac1
    goto L00779ac1;
  }
  L00779ade: { // 0x779ade: 803e22 CMP byte ptr [ESI],0x22
    (void)integer::sub(m.r8((s.si)),0x00000022u,8,flags);
  }
  { // 0x779ae1: 750d JNZ 0x00779af0
    if(integer::condition("JNZ",flags)) goto L00779af0;
  }
  L00779ae3: { // 0x779ae3: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x779ae4: eb0a JMP 0x00779af0
    goto L00779af0;
  }
  L00779ae6: { // 0x779ae6: 3c20 CMP AL,0x20
    (void)integer::sub((s.ax & 0xffu),0x00000020u,8,flags);
  }
  { // 0x779ae8: 7606 JBE 0x00779af0
    if(integer::condition("JBE",flags)) goto L00779af0;
  }
  L00779aea: { // 0x779aea: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x779aeb: 803e20 CMP byte ptr [ESI],0x20
    (void)integer::sub(m.r8((s.si)),0x00000020u,8,flags);
  }
  { // 0x779aee: 77fa JA 0x00779aea
    if(integer::condition("JA",flags)) goto L00779aea;
  }
  L00779af0: { // 0x779af0: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  { // 0x779af2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x779af4: 7404 JZ 0x00779afa
    if(integer::condition("JZ",flags)) goto L00779afa;
  }
  { // 0x779af6: 3c20 CMP AL,0x20
    (void)integer::sub((s.ax & 0xffu),0x00000020u,8,flags);
  }
  { // 0x779af8: 76e9 JBE 0x00779ae3
    if(integer::condition("JBE",flags)) goto L00779ae3;
  }
  L00779afa: { // 0x779afa: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x779afc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x779afd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037aee7(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77aee7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77aee8: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77aeea: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77aeeb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77aeec: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77aeed: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x77aeef: 395d0c CMP dword ptr [EBP + 0xc],EBX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.bx,32,flags);
  }
  { // 0x77aef2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77aef4: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x77aef5: 7c43 JL 0x0077af3a
    if(integer::condition("JL",flags)) goto L0077af3a;
  }
  L0077aef7: { // 0x77aef7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77aef9: 743f JZ 0x0077af3a
    if(integer::condition("JZ",flags)) goto L0077af3a;
  }
  { // 0x77aefb: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77aefe: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  { // 0x77af00: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x77af01: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x77af03: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x77af05: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77af08: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77af0a: ff34f0 PUSH dword ptr [EAX + ESI*0x8]
    f.push(m,m.r32((s.ax+(s.si * 0x00000008u))));
  }
  { // 0x77af0d: 8d3cf0 LEA EDI,[EAX + ESI*0x8]
    s.di = (s.ax+(s.si * 0x00000008u));
  }
  { // 0x77af10: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x77af13: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  { // 0x77af15: e84629ffff CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77af1a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77af1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77af1d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77af1e: 750a JNZ 0x0077af2a
    if(integer::condition("JNZ",flags)) goto L0077af2a;
  }
  { // 0x77af20: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  { // 0x77af23: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  { // 0x77af26: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  { // 0x77af28: eb0b JMP 0x0077af35
    goto L0077af35;
  }
  L0077af2a: { // 0x77af2a: 7d06 JGE 0x0077af32
    if(integer::condition("JGE",flags)) goto L0077af32;
  }
  { // 0x77af2c: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x77af2d: 89750c MOV dword ptr [EBP + 0xc],ESI
    m.w32((s.bp+0x0000000cu), s.si);
  }
  { // 0x77af30: eb03 JMP 0x0077af35
    goto L0077af35;
  }
  L0077af32: { // 0x77af32: 8d5e01 LEA EBX,[ESI + 0x1]
    s.bx = (s.si+0x00000001u);
  }
  L0077af35: { // 0x77af35: 3b5d0c CMP EBX,dword ptr [EBP + 0xc]
    (void)integer::sub(s.bx,m.r32((s.bp+0x0000000cu)),32,flags);
  }
  { // 0x77af38: 7ebd JLE 0x0077aef7
    if(integer::condition("JLE",flags)) goto L0077aef7;
  }
  L0077af3a: { // 0x77af3a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77af3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77af3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77af3d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77af3e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b93e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b93e: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x77b942: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77b943: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b944: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77b945: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x77b947: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x77b94b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x77b94c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b94d: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x77b94f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x77b951: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x77b955: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x77b956: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x77b958: 8d3cb3 LEA EDI,[EBX + ESI*0x4]
    s.di = (s.bx+(s.si * 0x00000004u));
  }
  { // 0x77b95b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77b95c: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  { // 0x77b95e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b95f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b961: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x77b962: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x77b964: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x77b966: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b967: ff37 PUSH dword ptr [EDI]
    f.push(m,m.r32((s.di)));
  }
  { // 0x77b969: e8a04a0000 CALL 0x0078040e
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b96e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77b971: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x77b972: 781c JS 0x0077b990
    if(integer::condition("JS",flags)) goto L0077b990;
  }
  { // 0x77b974: 8d3cb3 LEA EDI,[EBX + ESI*0x4]
    s.di = (s.bx+(s.si * 0x00000004u));
  }
  L0077b977: { // 0x77b977: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b979: 7415 JZ 0x0077b990
    if(integer::condition("JZ",flags)) goto L0077b990;
  }
  { // 0x77b97b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77b97c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b97e: ff37 PUSH dword ptr [EDI]
    f.push(m,m.r32((s.di)));
  }
  { // 0x77b980: e8894a0000 CALL 0x0078040e
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b985: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77b988: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x77b989: 83ef04 SUB EDI,0x4
    s.di = integer::sub(s.di,0x00000004u,32,flags);
  }
  { // 0x77b98c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x77b98e: 7de7 JGE 0x0077b977
    if(integer::condition("JGE",flags)) goto L0077b977;
  }
  L0077b990: { // 0x77b990: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77b991: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77b992: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77b993: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037f23f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77f23f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77f240: 8b7c2408 MOV EDI,dword ptr [ESP + 0x8]
    s.di = m.r32((f.sp+0x00000008u));
  }
  { // 0x77f244: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x77f246: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x77f248: 7504 JNZ 0x0077f24e
    if(integer::condition("JNZ",flags)) goto L0077f24e;
  }
  { // 0x77f24a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77f24c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77f24d: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077f24e: { // 0x77f24e: 833f00 CMP dword ptr [EDI],0x0
    (void)integer::sub(m.r32((s.di)),0x00000000u,32,flags);
  }
  { // 0x77f251: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  { // 0x77f254: 740a JZ 0x0077f260
    if(integer::condition("JZ",flags)) goto L0077f260;
  }
  L0077f256: { // 0x77f256: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x77f258: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x77f259: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  { // 0x77f25c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x77f25e: 75f6 JNZ 0x0077f256
    if(integer::condition("JNZ",flags)) goto L0077f256;
  }
  L0077f260: { // 0x77f260: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77f261: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77f262: 8d048d04000000 LEA EAX,[ECX*0x4 + 0x4]
    s.ax = ((s.cx * 0x00000004u)+0x00000004u);
  }
  { // 0x77f269: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77f26a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77f26b: e800edfeff CALL 0x0076df70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77f270: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x77f272: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77f273: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x77f275: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x77f277: 7508 JNZ 0x0077f281
    if(integer::condition("JNZ",flags)) goto L0077f281;
  }
  { // 0x77f279: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x77f27b: e85822ffff CALL 0x007714d8
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77f280: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077f281: { // 0x77f281: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x77f283: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L0077f285: { // 0x77f285: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77f287: 7413 JZ 0x0077f29c
    if(integer::condition("JZ",flags)) goto L0077f29c;
  }
  { // 0x77f289: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77f28a: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  { // 0x77f28d: e8b49effff CALL 0x00779146
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77f292: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x77f294: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x77f296: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77f297: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x77f29a: ebe9 JMP 0x0077f285
    goto L0077f285;
  }
  L0077f29c: { // 0x77f29c: 832600 AND dword ptr [ESI],0x0
    m.w32((s.si), integer::logical((m.r32((s.si)))&(0x00000000u),32,flags));
  }
  { // 0x77f29f: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x77f2a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77f2a2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77f2a3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77f2a4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77f2a5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0038279c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x78279c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x78279d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x78279e: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x7827a2: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x7827a4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x7827a5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7827a7: 7e1c JLE 0x007827c5
    if(integer::condition("JLE",flags)) goto L007827c5;
  }
  { // 0x7827a9: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007827ad: { // 0x7827ad: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7827ae: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x7827b2: e8cbffffff CALL 0x00782782
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7827b7: 833eff CMP dword ptr [ESI],-0x1
    (void)integer::sub(m.r32((s.si)),0xffffffffu,32,flags);
  }
  { // 0x7827ba: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7827bb: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7827bc: 7407 JZ 0x007827c5
    if(integer::condition("JZ",flags)) goto L007827c5;
  }
  { // 0x7827be: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x7827c0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x7827c1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7827c3: 7fe8 JG 0x007827ad
    if(integer::condition("JG",flags)) goto L007827ad;
  }
  L007827c5: { // 0x7827c5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7827c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7827c7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003827c8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7827c8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7827c9: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x7827cd: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x7827cf: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x7827d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7827d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7827d2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7827d4: 7e21 JLE 0x007827f7
    if(integer::condition("JLE",flags)) goto L007827f7;
  }
  { // 0x7827d6: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x7827da: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L007827de: { // 0x7827de: 0fbe06 MOVSX EAX,byte ptr [ESI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si)),8));
  }
  { // 0x7827e1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7827e2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7827e3: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x7827e4: e899ffffff CALL 0x00782782
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7827e9: 833fff CMP dword ptr [EDI],-0x1
    (void)integer::sub(m.r32((s.di)),0xffffffffu,32,flags);
  }
  { // 0x7827ec: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7827ed: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7827ee: 7407 JZ 0x007827f7
    if(integer::condition("JZ",flags)) goto L007827f7;
  }
  { // 0x7827f0: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x7827f2: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x7827f3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7827f5: 7fe7 JG 0x007827de
    if(integer::condition("JG",flags)) goto L007827de;
  }
  L007827f7: { // 0x7827f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7827f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7827f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x7827fa: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,118>& entries_c() {
  static const std::array<Entry,118> entries{{
    {0x2697b0u,f_002697b0},
    {0x269800u,f_00269800},
    {0x2699b0u,f_002699b0},
    {0x26a610u,f_0026a610},
    {0x270910u,f_00270910},
    {0x270fe0u,f_00270fe0},
    {0x271210u,f_00271210},
    {0x271230u,f_00271230},
    {0x27d690u,f_0027d690},
    {0x27d6e0u,f_0027d6e0},
    {0x2814e0u,f_002814e0},
    {0x290940u,f_00290940},
    {0x294610u,f_00294610},
    {0x294de0u,f_00294de0},
    {0x296180u,f_00296180},
    {0x2963a0u,f_002963a0},
    {0x2973e0u,f_002973e0},
    {0x2a4fd0u,f_002a4fd0},
    {0x2a7510u,f_002a7510},
    {0x2a7560u,f_002a7560},
    {0x2a75e0u,f_002a75e0},
    {0x2a85f0u,f_002a85f0},
    {0x2a9870u,f_002a9870},
    {0x2a98a0u,f_002a98a0},
    {0x2a9ed0u,f_002a9ed0},
    {0x2aa250u,f_002aa250},
    {0x2aa280u,f_002aa280},
    {0x2aa2b0u,f_002aa2b0},
    {0x2aa2e0u,f_002aa2e0},
    {0x2aa310u,f_002aa310},
    {0x2ac1a0u,f_002ac1a0},
    {0x2ac1f0u,f_002ac1f0},
    {0x2b0080u,f_002b0080},
    {0x2b00b0u,f_002b00b0},
    {0x2b0a00u,f_002b0a00},
    {0x2b1930u,f_002b1930},
    {0x2b1c40u,f_002b1c40},
    {0x2b1cb0u,f_002b1cb0},
    {0x2b3fa0u,f_002b3fa0},
    {0x2b48b0u,f_002b48b0},
    {0x2b5760u,f_002b5760},
    {0x2b5870u,f_002b5870},
    {0x2c85b0u,f_002c85b0},
    {0x2d4bb0u,f_002d4bb0},
    {0x2d4d60u,f_002d4d60},
    {0x2da7d0u,f_002da7d0},
    {0x2dcd30u,f_002dcd30},
    {0x2e28e0u,f_002e28e0},
    {0x2e2910u,f_002e2910},
    {0x2e2af0u,f_002e2af0},
    {0x2e3610u,f_002e3610},
    {0x2e3680u,f_002e3680},
    {0x2e4af0u,f_002e4af0},
    {0x2ea7f0u,f_002ea7f0},
    {0x2ea860u,f_002ea860},
    {0x2eacf0u,f_002eacf0},
    {0x2ead70u,f_002ead70},
    {0x2eadf0u,f_002eadf0},
    {0x2ec450u,f_002ec450},
    {0x2ff450u,f_002ff450},
    {0x301130u,f_00301130},
    {0x301180u,f_00301180},
    {0x303620u,f_00303620},
    {0x303b00u,f_00303b00},
    {0x304d70u,f_00304d70},
    {0x3053e0u,f_003053e0},
    {0x305710u,f_00305710},
    {0x307ec0u,f_00307ec0},
    {0x308ef0u,f_00308ef0},
    {0x308f70u,f_00308f70},
    {0x308fd0u,f_00308fd0},
    {0x309070u,f_00309070},
    {0x3090b0u,f_003090b0},
    {0x309500u,f_00309500},
    {0x309550u,f_00309550},
    {0x30a680u,f_0030a680},
    {0x30a700u,f_0030a700},
    {0x30aa40u,f_0030aa40},
    {0x30b200u,f_0030b200},
    {0x30b280u,f_0030b280},
    {0x315be0u,f_00315be0},
    {0x324840u,f_00324840},
    {0x3285e0u,f_003285e0},
    {0x328af0u,f_00328af0},
    {0x32b9d0u,f_0032b9d0},
    {0x3373f0u,f_003373f0},
    {0x340fc0u,f_00340fc0},
    {0x3422e0u,f_003422e0},
    {0x352630u,f_00352630},
    {0x3531b0u,f_003531b0},
    {0x353610u,f_00353610},
    {0x353c50u,f_00353c50},
    {0x353e30u,f_00353e30},
    {0x3573b0u,f_003573b0},
    {0x35c320u,f_0035c320},
    {0x35c410u,f_0035c410},
    {0x35d2e0u,f_0035d2e0},
    {0x364fe0u,f_00364fe0},
    {0x36d7dau,f_0036d7da},
    {0x36df82u,f_0036df82},
    {0x36fc6eu,f_0036fc6e},
    {0x370732u,f_00370732},
    {0x370e47u,f_00370e47},
    {0x370fadu,f_00370fad},
    {0x371c09u,f_00371c09},
    {0x3725dbu,f_003725db},
    {0x37260cu,f_0037260c},
    {0x3726e8u,f_003726e8},
    {0x3764ebu,f_003764eb},
    {0x37651cu,f_0037651c},
    {0x376ee0u,f_00376ee0},
    {0x37817au,f_0037817a},
    {0x379aa6u,f_00379aa6},
    {0x37aee7u,f_0037aee7},
    {0x37b93eu,f_0037b93e},
    {0x37f23fu,f_0037f23f},
    {0x38279cu,f_0038279c},
    {0x3827c8u,f_003827c8},
  }}; return entries;
}
} // namespace ra2::recovered::loops_b36
