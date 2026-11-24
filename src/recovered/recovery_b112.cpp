#include "recovered/recovery_b112_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b112 {
namespace {
void f_00297fb0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0029e380(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_002a0410(Memory&,State&,Frame&,const Operations&);
void f_00276f30(Memory&,State&,Frame&,const Operations&);
void f_0026ac80(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697fb0: { // 0x697fb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00697fb3: { // 0x697fb3: 81f9d8020000 CMP ECX,0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  L00697fb9: { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L00697fbd: { // 0x697fbd: c744240000000000 MOV dword ptr [ESP],0x0
    m.w32((f.sp), 0x00000000u);
  }
  L00697fc5: { // 0x697fc5: 7c08 JL 0x00697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  L00697fc7: { // 0x697fc7: c744240001000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00697fd3: { // 0x697fd3: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697fd9: { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697fdd: { // 0x697fdd: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697fe3: { // 0x697fe3: e8682a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914024u); flags=s.arithmetic_flags;
  }
  L00697fe8: { // 0x697fe8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00697feb: { // 0x697feb: c3 RET
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
void f_0029e380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e380: { // 0x69e380: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069e381: { // 0x69e381: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069e382: { // 0x69e382: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e383: { // 0x69e383: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0069e387: { // 0x69e387: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e388: { // 0x69e388: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e389: { // 0x69e389: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e38e: { // 0x69e38e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0069e390: { // 0x69e390: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L0069e393: { // 0x69e393: e86871eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939544u); flags=s.arithmetic_flags;
  }
  L0069e398: { // 0x69e398: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0069e39c: { // 0x69e39c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e39e: { // 0x69e39e: 0f84d0010000 JZ 0x0069e574
    if(integer::condition("JZ",flags)) goto L0069e574;
  }
  L0069e3a4: { // 0x69e3a4: 8b8040010000 MOV EAX,dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0069e3aa: { // 0x69e3aa: a803 TEST AL,0x3
    (void)integer::logical(((s.ax & 0xffu))&(0x00000003u),8,flags);
  }
  L0069e3ac: { // 0x69e3ac: 7505 JNZ 0x0069e3b3
    if(integer::condition("JNZ",flags)) goto L0069e3b3;
  }
  L0069e3ae: { // 0x69e3ae: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e3b3: { // 0x69e3b3: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L0069e3b8: { // 0x69e3b8: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e3ba: { // 0x69e3ba: 0f8494030000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e3c0: { // 0x69e3c0: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e3c3: { // 0x69e3c3: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e3c7: { // 0x69e3c7: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e3c9: { // 0x69e3c9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e3cb: { // 0x69e3cb: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e3d0: { // 0x69e3d0: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e3d5: { // 0x69e3d5: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e3d9: { // 0x69e3d9: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e3dd: { // 0x69e3dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e3de: { // 0x69e3de: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e3e3: { // 0x69e3e3: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e3e7: { // 0x69e3e7: e81471eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939628u); flags=s.arithmetic_flags;
  }
  L0069e3ec: { // 0x69e3ec: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e3f2: { // 0x69e3f2: 7505 JNZ 0x0069e3f9
    if(integer::condition("JNZ",flags)) goto L0069e3f9;
  }
  L0069e3f4: { // 0x69e3f4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e3f9: { // 0x69e3f9: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e3fc: { // 0x69e3fc: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e400: { // 0x69e400: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e405: { // 0x69e405: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e407: { // 0x69e407: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e40b: { // 0x69e40b: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e410: { // 0x69e410: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e414: { // 0x69e414: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e415: { // 0x69e415: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e41a: { // 0x69e41a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e41e: { // 0x69e41e: e8dd70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939683u); flags=s.arithmetic_flags;
  }
  L0069e423: { // 0x69e423: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e429: { // 0x69e429: 7506 JNZ 0x0069e431
    if(integer::condition("JNZ",flags)) goto L0069e431;
  }
  L0069e42b: { // 0x69e42b: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e431: { // 0x69e431: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e434: { // 0x69e434: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e438: { // 0x69e438: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e43a: { // 0x69e43a: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e43c: { // 0x69e43c: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e441: { // 0x69e441: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e446: { // 0x69e446: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e44a: { // 0x69e44a: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e44e: { // 0x69e44e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e452: { // 0x69e452: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e453: { // 0x69e453: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e458: { // 0x69e458: e8a370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939741u); flags=s.arithmetic_flags;
  }
  L0069e45d: { // 0x69e45d: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e463: { // 0x69e463: 7503 JNZ 0x0069e468
    if(integer::condition("JNZ",flags)) goto L0069e468;
  }
  L0069e465: { // 0x69e465: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e468: { // 0x69e468: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e46b: { // 0x69e46b: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e46f: { // 0x69e46f: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e471: { // 0x69e471: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e476: { // 0x69e476: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e47b: { // 0x69e47b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e47f: { // 0x69e47f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e483: { // 0x69e483: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e488: { // 0x69e488: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e489: { // 0x69e489: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e48d: { // 0x69e48d: e86e70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939794u); flags=s.arithmetic_flags;
  }
  L0069e492: { // 0x69e492: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e498: { // 0x69e498: 7503 JNZ 0x0069e49d
    if(integer::condition("JNZ",flags)) goto L0069e49d;
  }
  L0069e49a: { // 0x69e49a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e49d: { // 0x69e49d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e4a0: { // 0x69e4a0: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e4a4: { // 0x69e4a4: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e4a6: { // 0x69e4a6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e4ab: { // 0x69e4ab: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e4b0: { // 0x69e4b0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e4b4: { // 0x69e4b4: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e4b8: { // 0x69e4b8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069e4bc: { // 0x69e4bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e4bd: { // 0x69e4bd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4c2: { // 0x69e4c2: e83970eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939847u); flags=s.arithmetic_flags;
  }
  L0069e4c7: { // 0x69e4c7: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e4cd: { // 0x69e4cd: 7502 JNZ 0x0069e4d1
    if(integer::condition("JNZ",flags)) goto L0069e4d1;
  }
  L0069e4cf: { // 0x69e4cf: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e4d1: { // 0x69e4d1: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e4d4: { // 0x69e4d4: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e4d8: { // 0x69e4d8: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e4da: { // 0x69e4da: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e4dc: { // 0x69e4dc: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e4e1: { // 0x69e4e1: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e4e6: { // 0x69e4e6: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e4ea: { // 0x69e4ea: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e4ee: { // 0x69e4ee: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e4f2: { // 0x69e4f2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e4f3: { // 0x69e4f3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4f8: { // 0x69e4f8: e80370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939901u); flags=s.arithmetic_flags;
  }
  L0069e4fd: { // 0x69e4fd: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e503: { // 0x69e503: 7503 JNZ 0x0069e508
    if(integer::condition("JNZ",flags)) goto L0069e508;
  }
  L0069e505: { // 0x69e505: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e508: { // 0x69e508: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e50c: { // 0x69e50c: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e50f: { // 0x69e50f: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e511: { // 0x69e511: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e516: { // 0x69e516: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e51b: { // 0x69e51b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e51f: { // 0x69e51f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e523: { // 0x69e523: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e528: { // 0x69e528: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e529: { // 0x69e529: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e52d: { // 0x69e52d: e8ce6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939954u); flags=s.arithmetic_flags;
  }
  L0069e532: { // 0x69e532: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e538: { // 0x69e538: 7503 JNZ 0x0069e53d
    if(integer::condition("JNZ",flags)) goto L0069e53d;
  }
  L0069e53a: { // 0x69e53a: 83cd08 OR EBP,0x8
    s.bp = integer::logical((s.bp)|(0x00000008u),32,flags);
  }
  L0069e53d: { // 0x69e53d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e540: { // 0x69e540: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e544: { // 0x69e544: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e546: { // 0x69e546: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e548: { // 0x69e548: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e54d: { // 0x69e54d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e551: { // 0x69e551: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e556: { // 0x69e556: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e55a: { // 0x69e55a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e55b: { // 0x69e55b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e560: { // 0x69e560: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e564: { // 0x69e564: e8976feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940009u); flags=s.arithmetic_flags;
  }
  L0069e569: { // 0x69e569: 8a8840010000 MOV CL,byte ptr [EAX + 0x140]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000140u)));
  }
  L0069e56f: { // 0x69e56f: e9cb010000 JMP 0x0069e73f
    goto L0069e73f;
  }
  L0069e574: { // 0x69e574: 8b802c010000 MOV EAX,dword ptr [EAX + 0x12c]
    s.ax = m.r32((s.ax+0x0000012cu));
  }
  L0069e57a: { // 0x69e57a: a818 TEST AL,0x18
    (void)integer::logical(((s.ax & 0xffu))&(0x00000018u),8,flags);
  }
  L0069e57c: { // 0x69e57c: 7505 JNZ 0x0069e583
    if(integer::condition("JNZ",flags)) goto L0069e583;
  }
  L0069e57e: { // 0x69e57e: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e583: { // 0x69e583: bb08000000 MOV EBX,0x8
    s.bx = 0x00000008u;
  }
  L0069e588: { // 0x69e588: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e58a: { // 0x69e58a: 0f84c4010000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e590: { // 0x69e590: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e593: { // 0x69e593: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e597: { // 0x69e597: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e599: { // 0x69e599: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e59b: { // 0x69e59b: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e5a0: { // 0x69e5a0: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e5a5: { // 0x69e5a5: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e5a9: { // 0x69e5a9: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e5ad: { // 0x69e5ad: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e5b1: { // 0x69e5b1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e5b2: { // 0x69e5b2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5b7: { // 0x69e5b7: e8446feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940092u); flags=s.arithmetic_flags;
  }
  L0069e5bc: { // 0x69e5bc: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5c2: { // 0x69e5c2: 7505 JNZ 0x0069e5c9
    if(integer::condition("JNZ",flags)) goto L0069e5c9;
  }
  L0069e5c4: { // 0x69e5c4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e5c9: { // 0x69e5c9: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e5cd: { // 0x69e5cd: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e5d0: { // 0x69e5d0: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e5d2: { // 0x69e5d2: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e5d7: { // 0x69e5d7: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e5dc: { // 0x69e5dc: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e5e0: { // 0x69e5e0: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e5e4: { // 0x69e5e4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5e9: { // 0x69e5e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e5ea: { // 0x69e5ea: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e5ee: { // 0x69e5ee: e80d6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940147u); flags=s.arithmetic_flags;
  }
  L0069e5f3: { // 0x69e5f3: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5f9: { // 0x69e5f9: 7506 JNZ 0x0069e601
    if(integer::condition("JNZ",flags)) goto L0069e601;
  }
  L0069e5fb: { // 0x69e5fb: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e601: { // 0x69e601: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e604: { // 0x69e604: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e608: { // 0x69e608: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e60a: { // 0x69e60a: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e60c: { // 0x69e60c: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e611: { // 0x69e611: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e615: { // 0x69e615: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e61a: { // 0x69e61a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e61e: { // 0x69e61e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e61f: { // 0x69e61f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e624: { // 0x69e624: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e628: { // 0x69e628: e8d36eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940205u); flags=s.arithmetic_flags;
  }
  L0069e62d: { // 0x69e62d: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e633: { // 0x69e633: 7503 JNZ 0x0069e638
    if(integer::condition("JNZ",flags)) goto L0069e638;
  }
  L0069e635: { // 0x69e635: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e638: { // 0x69e638: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e63b: { // 0x69e63b: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e63f: { // 0x69e63f: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e641: { // 0x69e641: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e646: { // 0x69e646: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e64b: { // 0x69e64b: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e64f: { // 0x69e64f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e653: { // 0x69e653: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e657: { // 0x69e657: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e658: { // 0x69e658: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e65d: { // 0x69e65d: e89e6eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940258u); flags=s.arithmetic_flags;
  }
  L0069e662: { // 0x69e662: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e668: { // 0x69e668: 7503 JNZ 0x0069e66d
    if(integer::condition("JNZ",flags)) goto L0069e66d;
  }
  L0069e66a: { // 0x69e66a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e66d: { // 0x69e66d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e670: { // 0x69e670: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e674: { // 0x69e674: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e676: { // 0x69e676: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e67b: { // 0x69e67b: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e680: { // 0x69e680: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e684: { // 0x69e684: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e688: { // 0x69e688: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e68d: { // 0x69e68d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e68e: { // 0x69e68e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e692: { // 0x69e692: e8696eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940311u); flags=s.arithmetic_flags;
  }
  L0069e697: { // 0x69e697: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e69d: { // 0x69e69d: 7503 JNZ 0x0069e6a2
    if(integer::condition("JNZ",flags)) goto L0069e6a2;
  }
  L0069e69f: { // 0x69e69f: 83cd02 OR EBP,0x2
    s.bp = integer::logical((s.bp)|(0x00000002u),32,flags);
  }
  L0069e6a2: { // 0x69e6a2: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e6a5: { // 0x69e6a5: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e6a9: { // 0x69e6a9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e6ab: { // 0x69e6ab: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e6ad: { // 0x69e6ad: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e6b2: { // 0x69e6b2: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e6b6: { // 0x69e6b6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e6bb: { // 0x69e6bb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e6bf: { // 0x69e6bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e6c0: { // 0x69e6c0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6c5: { // 0x69e6c5: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e6c9: { // 0x69e6c9: e8326eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940366u); flags=s.arithmetic_flags;
  }
  L0069e6ce: { // 0x69e6ce: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e6d4: { // 0x69e6d4: 7503 JNZ 0x0069e6d9
    if(integer::condition("JNZ",flags)) goto L0069e6d9;
  }
  L0069e6d6: { // 0x69e6d6: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e6d9: { // 0x69e6d9: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e6dd: { // 0x69e6dd: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e6e0: { // 0x69e6e0: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e6e2: { // 0x69e6e2: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e6e7: { // 0x69e6e7: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e6ec: { // 0x69e6ec: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e6f0: { // 0x69e6f0: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e6f4: { // 0x69e6f4: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e6f8: { // 0x69e6f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e6f9: { // 0x69e6f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6fe: { // 0x69e6fe: e8fd6deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940419u); flags=s.arithmetic_flags;
  }
  L0069e703: { // 0x69e703: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e709: { // 0x69e709: 7502 JNZ 0x0069e70d
    if(integer::condition("JNZ",flags)) goto L0069e70d;
  }
  L0069e70b: { // 0x69e70b: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e70d: { // 0x69e70d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e710: { // 0x69e710: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e714: { // 0x69e714: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e716: { // 0x69e716: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e718: { // 0x69e718: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e71d: { // 0x69e71d: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e722: { // 0x69e722: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e726: { // 0x69e726: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e72a: { // 0x69e72a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e72b: { // 0x69e72b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e730: { // 0x69e730: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e734: { // 0x69e734: e8c76deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940473u); flags=s.arithmetic_flags;
  }
  L0069e739: { // 0x69e739: 8a882c010000 MOV CL,byte ptr [EAX + 0x12c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000012cu)));
  }
  L0069e73f: { // 0x69e73f: 84cb TEST BL,CL
    (void)integer::logical(((s.bx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e741: { // 0x69e741: 7503 JNZ 0x0069e746
    if(integer::condition("JNZ",flags)) goto L0069e746;
  }
  L0069e743: { // 0x69e743: 83cd04 OR EBP,0x4
    s.bp = integer::logical((s.bp)|(0x00000004u),32,flags);
  }
  L0069e746: { // 0x69e746: 0fbe8564727900 MOVSX EAX,byte ptr [EBP + 0x797264]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x00797264u)),8));
  }
  L0069e74d: { // 0x69e74d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e74e: { // 0x69e74e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e74f: { // 0x69e74f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e750: { // 0x69e750: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e751: { // 0x69e751: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069e754: { // 0x69e754: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e756: { // 0x69e756: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e757: { // 0x69e757: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e758: { // 0x69e758: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e759: { // 0x69e759: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e75a: { // 0x69e75a: c20800 RET 0x8
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
void f_002a0410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a0410: { // 0x6a0410: a12ca88100 MOV EAX,[0x0081a82c]
    s.ax = m.r32((0x0081a82cu));
  }
  L006a0415: { // 0x6a0415: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006a0418: { // 0x6a0418: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a041a: { // 0x6a041a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a041b: { // 0x6a041b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a041c: { // 0x6a041c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a041d: { // 0x6a041d: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006a041f: { // 0x6a041f: 0f858a010000 JNZ 0x006a05af
    if(integer::condition("JNZ",flags)) goto L006a05af;
  }
  L006a0425: { // 0x6a0425: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L006a0429: { // 0x6a0429: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006a042e: { // 0x6a042e: 39475c CMP dword ptr [EDI + 0x5c],EAX
    (void)integer::sub(m.r32((s.di+0x0000005cu)),s.ax,32,flags);
  }
  L006a0431: { // 0x6a0431: 0f8478010000 JZ 0x006a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a0437: { // 0x6a0437: f6872c01000008 TEST byte ptr [EDI + 0x12c],0x8
    (void)integer::logical((m.r8((s.di+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L006a043e: { // 0x6a043e: 750e JNZ 0x006a044e
    if(integer::condition("JNZ",flags)) goto L006a044e;
  }
  L006a0440: { // 0x6a0440: 8a8f38010000 MOV CL,byte ptr [EDI + 0x138]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000138u)));
  }
  L006a0446: { // 0x6a0446: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0448: { // 0x6a0448: 0f8461010000 JZ 0x006a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a044e: { // 0x6a044e: 89475c MOV dword ptr [EDI + 0x5c],EAX
    m.w32((s.di+0x0000005cu), s.ax);
  }
  L006a0451: { // 0x6a0451: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L006a0455: { // 0x6a0455: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006a0456: { // 0x6a0456: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a0457: { // 0x6a0457: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006a0459: { // 0x6a0459: e80255ddff CALL 0x00475960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475960u,6947934u); flags=s.arithmetic_flags;
  }
  L006a045e: { // 0x6a045e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006a0460: { // 0x6a0460: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006a0463: { // 0x6a0463: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006a0466: { // 0x6a0466: 8b872c010000 MOV EAX,dword ptr [EDI + 0x12c]
    s.ax = m.r32((s.di+0x0000012cu));
  }
  L006a046c: { // 0x6a046c: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L006a046e: { // 0x6a046e: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006a0472: { // 0x6a0472: 744b JZ 0x006a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0474: { // 0x6a0474: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L006a0476: { // 0x6a0476: 7447 JZ 0x006a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0478: { // 0x6a0478: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a047b: { // 0x6a047b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a047e: { // 0x6a047e: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a0481: { // 0x6a0481: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0482: { // 0x6a0482: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0484: { // 0x6a0484: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006a0486: { // 0x6a0486: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a0489: { // 0x6a0489: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a048b: { // 0x6a048b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a048e: { // 0x6a048e: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a0490: { // 0x6a0490: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0491: { // 0x6a0491: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0493: { // 0x6a0493: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a0495: { // 0x6a0495: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a0497: { // 0x6a0497: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006a049a: { // 0x6a049a: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a049c: { // 0x6a049c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a049e: { // 0x6a049e: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04a1: { // 0x6a04a1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04a2: { // 0x6a04a2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04a4: { // 0x6a04a4: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04a6: { // 0x6a04a6: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04a8: { // 0x6a04a8: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L006a04ab: { // 0x6a04ab: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ad: { // 0x6a04ad: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04b0: { // 0x6a04b0: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04b4: { // 0x6a04b4: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04b6: { // 0x6a04b6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04b7: { // 0x6a04b7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04b9: { // 0x6a04b9: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04bb: { // 0x6a04bb: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a04bd: { // 0x6a04bd: eb45 JMP 0x006a0504
    goto L006a0504;
  }
  L006a04bf: { // 0x6a04bf: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a04c2: { // 0x6a04c2: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04c5: { // 0x6a04c5: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04c8: { // 0x6a04c8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04c9: { // 0x6a04c9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04cb: { // 0x6a04cb: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006a04cd: { // 0x6a04cd: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a04d0: { // 0x6a04d0: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04d2: { // 0x6a04d2: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04d5: { // 0x6a04d5: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04d7: { // 0x6a04d7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04d8: { // 0x6a04d8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04da: { // 0x6a04da: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a04dc: { // 0x6a04dc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a04de: { // 0x6a04de: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006a04e1: { // 0x6a04e1: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a04e3: { // 0x6a04e3: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a04e5: { // 0x6a04e5: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04e8: { // 0x6a04e8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04e9: { // 0x6a04e9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04eb: { // 0x6a04eb: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ed: { // 0x6a04ed: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04ef: { // 0x6a04ef: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L006a04f2: { // 0x6a04f2: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04f4: { // 0x6a04f4: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04f7: { // 0x6a04f7: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04fb: { // 0x6a04fb: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04fd: { // 0x6a04fd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04fe: { // 0x6a04fe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0500: { // 0x6a0500: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0502: { // 0x6a0502: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a0504: { // 0x6a0504: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006a0506: { // 0x6a0506: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006a0508: { // 0x6a0508: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0509: { // 0x6a0509: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a050f: { // 0x6a050f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006a0511: { // 0x6a0511: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a0513: { // 0x6a0513: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006a0515: { // 0x6a0515: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0518: { // 0x6a0518: e8937affff CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6948125u); flags=s.arithmetic_flags;
  }
  L006a051d: { // 0x6a051d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a051f: { // 0x6a051f: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L006a0521: { // 0x6a0521: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0522: { // 0x6a0522: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a0528: { // 0x6a0528: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006a052c: { // 0x6a052c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a052e: { // 0x6a052e: 8b93b4000000 MOV EDX,dword ptr [EBX + 0xb4]
    s.dx = m.r32((s.bx+0x000000b4u));
  }
  L006a0534: { // 0x6a0534: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0537: { // 0x6a0537: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006a0539: { // 0x6a0539: 8b8bb0000000 MOV ECX,dword ptr [EBX + 0xb0]
    s.cx = m.r32((s.bx+0x000000b0u));
  }
  L006a053f: { // 0x6a053f: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L006a0541: { // 0x6a0541: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L006a0547: { // 0x6a0547: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0549: { // 0x6a0549: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006a054a: { // 0x6a054a: 8d51e2 LEA EDX,[ECX + -0x1e]
    s.dx = (s.cx-0x0000001eu);
  }
  L006a054d: { // 0x6a054d: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L006a054f: { // 0x6a054f: 7c5e JL 0x006a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0551: { // 0x6a0551: 83f8e2 CMP EAX,-0x1e
    (void)integer::sub(s.ax,0xffffffe2u,32,flags);
  }
  L006a0554: { // 0x6a0554: 7c59 JL 0x006a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0556: { // 0x6a0556: 8b1578198200 MOV EDX,dword ptr [0x00821978]
    s.dx = m.r32((0x00821978u));
  }
  L006a055c: { // 0x6a055c: 8d4c0a1e LEA ECX,[EDX + ECX*0x1 + 0x1e]
    s.cx = (s.dx+(s.cx * 0x00000001u)+0x0000001eu);
  }
  L006a0560: { // 0x6a0560: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L006a0562: { // 0x6a0562: 7f4b JG 0x006a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0564: { // 0x6a0564: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L006a056a: { // 0x6a056a: 8b0d7c198200 MOV ECX,dword ptr [0x0082197c]
    s.cx = m.r32((0x0082197cu));
  }
  L006a0570: { // 0x6a0570: 8d54110f LEA EDX,[ECX + EDX*0x1 + 0xf]
    s.dx = (s.cx+(s.dx * 0x00000001u)+0x0000000fu);
  }
  L006a0574: { // 0x6a0574: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0576: { // 0x6a0576: 7f37 JG 0x006a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0578: { // 0x6a0578: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a057e: { // 0x6a057e: 3d1f030000 CMP EAX,0x31f
    (void)integer::sub(s.ax,0x0000031fu,32,flags);
  }
  L006a0583: { // 0x6a0583: 7d18 JGE 0x006a059d
    if(integer::condition("JGE",flags)) goto L006a059d;
  }
  L006a0585: { // 0x6a0585: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006a0589: { // 0x6a0589: 898c83e4000000 MOV dword ptr [EBX + EAX*0x4 + 0xe4],ECX
    m.w32((s.bx+(s.ax * 0x00000004u)+0x000000e4u), s.cx);
  }
  L006a0590: { // 0x6a0590: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a0596: { // 0x6a0596: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006a0597: { // 0x6a0597: 8983e0000000 MOV dword ptr [EBX + 0xe0],EAX
    m.w32((s.bx+0x000000e0u), s.ax);
  }
  L006a059d: { // 0x6a059d: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L006a05a1: { // 0x6a05a1: c6823801000000 MOV byte ptr [EDX + 0x138],0x0
    m.w8((s.dx+0x00000138u), 0x00000000u);
  }
  L006a05a8: { // 0x6a05a8: c6837d0d000001 MOV byte ptr [EBX + 0xd7d],0x1
    m.w8((s.bx+0x00000d7du), 0x00000001u);
  }
  L006a05af: { // 0x6a05af: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a05b0: { // 0x6a05b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a05b1: { // 0x6a05b1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a05b2: { // 0x6a05b2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006a05b5: { // 0x6a05b5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00276f30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00676f30: { // 0x676f30: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00676f31: { // 0x676f31: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00676f32: { // 0x676f32: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00676f33: { // 0x676f33: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00676f34: { // 0x676f34: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00676f36: { // 0x676f36: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L00676f38: { // 0x676f38: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00676f3a: { // 0x676f3a: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L00676f3d: { // 0x676f3d: c644240f01 MOV byte ptr [ESP + 0xf],0x1
    m.w8((f.sp+0x0000000fu), 0x00000001u);
  }
  L00676f42: { // 0x676f42: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00676f44: { // 0x676f44: 7e70 JLE 0x00676fb6
    if(integer::condition("JLE",flags)) goto L00676fb6;
  }
  L00676f46: { // 0x676f46: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00676f47: { // 0x676f47: 8d7760 LEA ESI,[EDI + 0x60]
    s.si = (s.di+0x00000060u);
  }
  L00676f4a: { // 0x676f4a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00676f4c: { // 0x676f4c: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00676f50: { // 0x676f50: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00676f52: { // 0x676f52: 7516 JNZ 0x00676f6a
    if(integer::condition("JNZ",flags)) goto L00676f6a;
  }
  L00676f54: { // 0x676f54: e8d724e4ff CALL 0x004b9430
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b9430u,6778713u); flags=s.arithmetic_flags;
  }
  L00676f59: { // 0x676f59: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L00676f5f: { // 0x676f5f: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L00676f61: { // 0x676f61: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00676f68: { // 0x676f68: eb09 JMP 0x00676f73
    goto L00676f73;
  }
  L00676f6a: { // 0x676f6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00676f6c: { // 0x676f6c: 7405 JZ 0x00676f73
    if(integer::condition("JZ",flags)) goto L00676f73;
  }
  L00676f6e: { // 0x676f6e: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00676f73: { // 0x676f73: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L00676f76: { // 0x676f76: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00676f77: { // 0x676f77: 83c630 ADD ESI,0x30
    s.si = integer::add(s.si,0x00000030u,32,flags);
  }
  L00676f7a: { // 0x676f7a: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00676f7c: { // 0x676f7c: 7ccc JL 0x00676f4a
    if(integer::condition("JL",flags)) goto L00676f4a;
  }
  L00676f7e: { // 0x676f7e: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00676f80: { // 0x676f80: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00676f81: { // 0x676f81: 742b JZ 0x00676fae
    if(integer::condition("JZ",flags)) goto L00676fae;
  }
  L00676f83: { // 0x676f83: 8b4734 MOV EAX,dword ptr [EDI + 0x34]
    s.ax = m.r32((s.di+0x00000034u));
  }
  L00676f86: { // 0x676f86: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00676f89: { // 0x676f89: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L00676f8c: { // 0x676f8c: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00676f92: { // 0x676f92: e8e93cffff CALL 0x0066ac80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0066ac80u,6778775u); flags=s.arithmetic_flags;
  }
  L00676f97: { // 0x676f97: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00676f99: { // 0x676f99: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00676f9e: { // 0x676f9e: c6473801 MOV byte ptr [EDI + 0x38],0x1
    m.w8((s.di+0x00000038u), 0x00000001u);
  }
  L00676fa2: { // 0x676fa2: e88990e6ff CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,6778791u); flags=s.arithmetic_flags;
  }
  L00676fa7: { // 0x676fa7: c60503f7810001 MOV byte ptr [0x0081f703],0x1
    m.w8((0x0081f703u), 0x00000001u);
  }
  L00676fae: { // 0x676fae: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L00676fb2: { // 0x676fb2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00676fb4: { // 0x676fb4: 7418 JZ 0x00676fce
    if(integer::condition("JZ",flags)) goto L00676fce;
  }
  L00676fb6: { // 0x676fb6: 8b4734 MOV EAX,dword ptr [EDI + 0x34]
    s.ax = m.r32((s.di+0x00000034u));
  }
  L00676fb9: { // 0x676fb9: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00676fbc: { // 0x676fbc: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L00676fbf: { // 0x676fbf: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00676fc5: { // 0x676fc5: e8b63cffff CALL 0x0066ac80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0066ac80u,6778826u); flags=s.arithmetic_flags;
  }
  L00676fca: { // 0x676fca: c6473900 MOV byte ptr [EDI + 0x39],0x0
    m.w8((s.di+0x00000039u), 0x00000000u);
  }
  L00676fce: { // 0x676fce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00676fcf: { // 0x676fcf: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L00676fd1: { // 0x676fd1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00676fd2: { // 0x676fd2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00676fd3: { // 0x676fd3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00676fd4: { // 0x676fd4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0026ac80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0066ac80: { // 0x66ac80: 8b5138 MOV EDX,dword ptr [ECX + 0x38]
    s.dx = m.r32((s.cx+0x00000038u));
  }
  L0066ac83: { // 0x66ac83: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0066ac85: { // 0x66ac85: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0066ac87: { // 0x66ac87: 740c JZ 0x0066ac95
    if(integer::condition("JZ",flags)) goto L0066ac95;
  }
  L0066ac89: { // 0x66ac89: 884134 MOV byte ptr [ECX + 0x34],AL
    m.w8((s.cx+0x00000034u), (s.ax & 0xffu));
  }
  L0066ac8c: { // 0x66ac8c: 89413c MOV dword ptr [ECX + 0x3c],EAX
    m.w32((s.cx+0x0000003cu), s.ax);
  }
  L0066ac8f: { // 0x66ac8f: 894138 MOV dword ptr [ECX + 0x38],EAX
    m.w32((s.cx+0x00000038u), s.ax);
  }
  L0066ac92: { // 0x66ac92: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0066ac94: { // 0x66ac94: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0066ac95: { // 0x66ac95: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0066ac97: { // 0x66ac97: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6913968u:f_00297fb0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6939520u:f_0029e380(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 6947856u:f_002a0410(m,s,child,{});break;
case 6778672u:f_00276f30(m,s,child,{});break;
case 6728832u:f_0026ac80(m,s,child,{});break;
default:throw std::domain_error("recovery112 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005479e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005479e0: { // 0x5479e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005479e1: { // 0x5479e1: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005479e5: { // 0x5479e5: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L005479e9: { // 0x5479e9: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L005479ec: { // 0x5479ec: 7e07 JLE 0x005479f5
    if(integer::condition("JLE",flags)) goto L005479f5;
  }
  L005479ee: { // 0x5479ee: b80b000000 MOV EAX,0xb
    s.ax = 0x0000000bu;
  }
  L005479f3: { // 0x5479f3: eb0a JMP 0x005479ff
    goto L005479ff;
  }
  L005479f5: { // 0x5479f5: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005479f8: { // 0x5479f8: 7d05 JGE 0x005479ff
    if(integer::condition("JGE",flags)) goto L005479ff;
  }
  L005479fa: { // 0x5479fa: b803000000 MOV EAX,0x3
    s.ax = 0x00000003u;
  }
  L005479ff: { // 0x5479ff: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00547a03: { // 0x547a03: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00547a05: { // 0x547a05: 7d11 JGE 0x00547a18
    if(integer::condition("JGE",flags)) goto L00547a18;
  }
  L00547a07: { // 0x547a07: 8b0485e8087900 MOV EAX,dword ptr [EAX*0x4 + 0x7908e8]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007908e8u));
  }
  L00547a0e: { // 0x547a0e: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L00547a16: { // 0x547a16: eb25 JMP 0x00547a3d
    goto L00547a3d;
  }
  L00547a18: { // 0x547a18: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L00547a1b: { // 0x547a1b: 0f8e1a010000 JLE 0x00547b3b
    if(integer::condition("JLE",flags)) goto L00547b3b;
  }
  L00547a21: { // 0x547a21: c744240c08000000 MOV dword ptr [ESP + 0xc],0x8
    m.w32((f.sp+0x0000000cu), 0x00000008u);
  }
  L00547a29: { // 0x547a29: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00547a2d: { // 0x547a2d: 8b0485e8087900 MOV EAX,dword ptr [EAX*0x4 + 0x7908e8]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007908e8u));
  }
  L00547a34: { // 0x547a34: 8b148de4087900 MOV EDX,dword ptr [ECX*0x4 + 0x7908e4]
    s.dx = m.r32(((s.cx * 0x00000004u)+0x007908e4u));
  }
  L00547a3b: { // 0x547a3b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00547a3d: { // 0x547a3d: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00547a41: { // 0x547a41: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00547a45: { // 0x547a45: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547a46: { // 0x547a46: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00547a47: { // 0x547a47: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547a48: { // 0x547a48: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547a49: { // 0x547a49: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547a4b: { // 0x547a4b: 0f854b010000 JNZ 0x00547b9c
    if(integer::condition("JNZ",flags)) goto L00547b9c;
  }
  L00547a51: { // 0x547a51: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00547a55: { // 0x547a55: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00547a57: { // 0x547a57: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L00547a5a: { // 0x547a5a: 8b5908 MOV EBX,dword ptr [ECX + 0x8]
    s.bx = m.r32((s.cx+0x00000008u));
  }
  L00547a5d: { // 0x547a5d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00547a5f: { // 0x547a5f: e84c051500 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5536356u); flags=s.arithmetic_flags;
  }
  L00547a64: { // 0x547a64: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00547a66: { // 0x547a66: b877777777 MOV EAX,0x77777777
    s.ax = 0x77777777u;
  }
  L00547a6b: { // 0x547a6b: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00547a6d: { // 0x547a6d: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00547a6f: { // 0x547a6f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00547a71: { // 0x547a71: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547a74: { // 0x547a74: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00547a76: { // 0x547a76: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00547a79: { // 0x547a79: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00547a7b: { // 0x547a7b: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00547a7e: { // 0x547a7e: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00547a80: { // 0x547a80: e82b051500 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5536389u); flags=s.arithmetic_flags;
  }
  L00547a85: { // 0x547a85: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00547a87: { // 0x547a87: b877777777 MOV EAX,0x77777777
    s.ax = 0x77777777u;
  }
  L00547a8c: { // 0x547a8c: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00547a8e: { // 0x547a8e: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00547a90: { // 0x547a90: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00547a92: { // 0x547a92: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547a95: { // 0x547a95: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00547a97: { // 0x547a97: bd686ea500 MOV EBP,0xa56e68
    s.bp = 0x00a56e68u;
  }
  L00547a9c: { // 0x547a9c: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00547a9f: { // 0x547a9f: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00547aa1: { // 0x547aa1: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00547aa4: { // 0x547aa4: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00547aa6: { // 0x547aa6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547aa7: { // 0x547aa7: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547aad: { // 0x547aad: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547aaf: { // 0x547aaf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00547ab1: { // 0x547ab1: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00547ab3: { // 0x547ab3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547ab4: { // 0x547ab4: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547aba: { // 0x547aba: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547abc: { // 0x547abc: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00547abe: { // 0x547abe: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00547ac2: { // 0x547ac2: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547ac5: { // 0x547ac5: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547ac8: { // 0x547ac8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547aca: { // 0x547aca: 740e JZ 0x00547ada
    if(integer::condition("JZ",flags)) goto L00547ada;
  }
  L00547acc: { // 0x547acc: 8b1485e4087900 MOV EDX,dword ptr [EAX*0x4 + 0x7908e4]
    s.dx = m.r32(((s.ax * 0x00000004u)+0x007908e4u));
  }
  L00547ad3: { // 0x547ad3: 8d2c95686ea500 LEA EBP,[EDX*0x4 + 0xa56e68]
    s.bp = ((s.dx * 0x00000004u)+0x00a56e68u);
  }
  L00547ada: { // 0x547ada: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00547ade: { // 0x547ade: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00547ae0: { // 0x547ae0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00547ae1: { // 0x547ae1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00547ae3: { // 0x547ae3: 0f84b3000000 JZ 0x00547b9c
    if(integer::condition("JZ",flags)) goto L00547b9c;
  }
  L00547ae9: { // 0x547ae9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00547aea: { // 0x547aea: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00547aee: { // 0x547aee: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00547af0: { // 0x547af0: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L00547af3: { // 0x547af3: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L00547af6: { // 0x547af6: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L00547afa: { // 0x547afa: 6603c7 ADD AX,DI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L00547afd: { // 0x547afd: 6603ce ADD CX,SI
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L00547b00: { // 0x547b00: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L00547b05: { // 0x547b05: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00547b0a: { // 0x547b0a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00547b0e: { // 0x547b0e: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00547b11: { // 0x547b11: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00547b14: { // 0x547b14: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00547b17: { // 0x547b17: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00547b19: { // 0x547b19: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00547b1d: { // 0x547b1d: 7830 JS 0x00547b4f
    if(integer::condition("JS",flags)) goto L00547b4f;
  }
  L00547b1f: { // 0x547b1f: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00547b24: { // 0x547b24: 7d29 JGE 0x00547b4f
    if(integer::condition("JGE",flags)) goto L00547b4f;
  }
  L00547b26: { // 0x547b26: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00547b2a: { // 0x547b2a: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00547b30: { // 0x547b30: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00547b33: { // 0x547b33: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547b35: { // 0x547b35: 7418 JZ 0x00547b4f
    if(integer::condition("JZ",flags)) goto L00547b4f;
  }
  L00547b37: { // 0x547b37: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00547b39: { // 0x547b39: eb1f JMP 0x00547b5a
    goto L00547b5a;
  }
  L00547b3b: { // 0x547b3b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00547b3d: { // 0x547b3d: 0f85eafeffff JNZ 0x00547a2d
    if(integer::condition("JNZ",flags)) goto L00547a2d;
  }
  L00547b43: { // 0x547b43: 8b0485e8087900 MOV EAX,dword ptr [EAX*0x4 + 0x7908e8]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007908e8u));
  }
  L00547b4a: { // 0x547b4a: e9eefeffff JMP 0x00547a3d
    goto L00547a3d;
  }
  L00547b4f: { // 0x547b4f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00547b55: { // 0x547b55: bb1076a500 MOV EBX,0xa57610
    s.bx = 0x00a57610u;
  }
  L00547b5a: { // 0x547b5a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00547b60: { // 0x547b60: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00547b64: { // 0x547b64: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00547b66: { // 0x547b66: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00547b67: { // 0x547b67: e814681500 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,5536620u); flags=s.arithmetic_flags;
  }
  L00547b6c: { // 0x547b6c: 3a8320010000 CMP AL,byte ptr [EBX + 0x120]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.bx+0x00000120u)),8,flags);
  }
  L00547b72: { // 0x547b72: 7419 JZ 0x00547b8d
    if(integer::condition("JZ",flags)) goto L00547b8d;
  }
  L00547b74: { // 0x547b74: 888320010000 MOV byte ptr [EBX + 0x120],AL
    m.w8((s.bx+0x00000120u), (s.ax & 0xffu));
  }
  L00547b7a: { // 0x547b7a: c6833801000001 MOV byte ptr [EBX + 0x138],0x1
    m.w8((s.bx+0x00000138u), 0x00000001u);
  }
  L00547b81: { // 0x547b81: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00547b87: { // 0x547b87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547b88: { // 0x547b88: e883881500 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,5536653u); flags=s.arithmetic_flags;
  }
  L00547b8d: { // 0x547b8d: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00547b91: { // 0x547b91: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00547b92: { // 0x547b92: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00547b96: { // 0x547b96: 0f8552ffffff JNZ 0x00547aee
    if(integer::condition("JNZ",flags)) goto L00547aee;
  }
  L00547b9c: { // 0x547b9c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547b9d: { // 0x547b9d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547b9e: { // 0x547b9e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00547b9f: { // 0x547b9f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547ba0: { // 0x547ba0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00547ba1: { // 0x547ba1: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00676ea0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00676ea0: { // 0x676ea0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00676ea1: { // 0x676ea1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00676ea3: { // 0x676ea3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00676ea7: { // 0x676ea7: 83f90f CMP ECX,0xf
    (void)integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L00676eaa: { // 0x676eaa: 7458 JZ 0x00676f04
    if(integer::condition("JZ",flags)) goto L00676f04;
  }
  L00676eac: { // 0x676eac: 83f910 CMP ECX,0x10
    (void)integer::sub(s.cx,0x00000010u,32,flags);
  }
  L00676eaf: { // 0x676eaf: 7453 JZ 0x00676f04
    if(integer::condition("JZ",flags)) goto L00676f04;
  }
  L00676eb1: { // 0x676eb1: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00676eb4: { // 0x676eb4: 7447 JZ 0x00676efd
    if(integer::condition("JZ",flags)) goto L00676efd;
  }
  L00676eb6: { // 0x676eb6: 83f928 CMP ECX,0x28
    (void)integer::sub(s.cx,0x00000028u,32,flags);
  }
  L00676eb9: { // 0x676eb9: 7442 JZ 0x00676efd
    if(integer::condition("JZ",flags)) goto L00676efd;
  }
  L00676ebb: { // 0x676ebb: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00676ebe: { // 0x676ebe: 743d JZ 0x00676efd
    if(integer::condition("JZ",flags)) goto L00676efd;
  }
  L00676ec0: { // 0x676ec0: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00676ec3: { // 0x676ec3: 7438 JZ 0x00676efd
    if(integer::condition("JZ",flags)) goto L00676efd;
  }
  L00676ec5: { // 0x676ec5: 83f906 CMP ECX,0x6
    (void)integer::sub(s.cx,0x00000006u,32,flags);
  }
  L00676ec8: { // 0x676ec8: 7420 JZ 0x00676eea
    if(integer::condition("JZ",flags)) goto L00676eea;
  }
  L00676eca: { // 0x676eca: 83f907 CMP ECX,0x7
    (void)integer::sub(s.cx,0x00000007u,32,flags);
  }
  L00676ecd: { // 0x676ecd: 741b JZ 0x00676eea
    if(integer::condition("JZ",flags)) goto L00676eea;
  }
  L00676ecf: { // 0x676ecf: 83f939 CMP ECX,0x39
    (void)integer::sub(s.cx,0x00000039u,32,flags);
  }
  L00676ed2: { // 0x676ed2: 740f JZ 0x00676ee3
    if(integer::condition("JZ",flags)) goto L00676ee3;
  }
  L00676ed4: { // 0x676ed4: 83f920 CMP ECX,0x20
    (void)integer::sub(s.cx,0x00000020u,32,flags);
  }
  L00676ed7: { // 0x676ed7: 740a JZ 0x00676ee3
    if(integer::condition("JZ",flags)) goto L00676ee3;
  }
  L00676ed9: { // 0x676ed9: 83f91f CMP ECX,0x1f
    (void)integer::sub(s.cx,0x0000001fu,32,flags);
  }
  L00676edc: { // 0x676edc: 7405 JZ 0x00676ee3
    if(integer::condition("JZ",flags)) goto L00676ee3;
  }
  L00676ede: { // 0x676ede: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L00676ee1: { // 0x676ee1: eb26 JMP 0x00676f09
    goto L00676f09;
  }
  L00676ee3: { // 0x676ee3: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00676ee8: { // 0x676ee8: eb1f JMP 0x00676f09
    goto L00676f09;
  }
  L00676eea: { // 0x676eea: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00676eee: { // 0x676eee: e87d3be7ff CALL 0x004eaa70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eaa70u,6778611u); flags=s.arithmetic_flags;
  }
  L00676ef3: { // 0x676ef3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00676ef5: { // 0x676ef5: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00676ef8: { // 0x676ef8: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00676efb: { // 0x676efb: eb0c JMP 0x00676f09
    goto L00676f09;
  }
  L00676efd: { // 0x676efd: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L00676f02: { // 0x676f02: eb05 JMP 0x00676f09
    goto L00676f09;
  }
  L00676f04: { // 0x676f04: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L00676f09: { // 0x676f09: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00676f0d: { // 0x676f0d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00676f0e: { // 0x676f0e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00676f10: { // 0x676f10: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00676f13: { // 0x676f13: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00676f15: { // 0x676f15: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L00676f18: { // 0x676f18: 8d0451 LEA EAX,[ECX + EDX*0x2]
    s.ax = (s.cx+(s.dx * 0x00000002u));
  }
  L00676f1b: { // 0x676f1b: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00676f1e: { // 0x676f1e: 8d8c8640150000 LEA ECX,[ESI + EAX*0x4 + 0x1540]
    s.cx = (s.si+(s.ax * 0x00000004u)+0x00001540u);
  }
  L00676f25: { // 0x676f25: e806000000 CALL 0x00676f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00676f30u,6778666u); flags=s.arithmetic_flags;
  }
  L00676f2a: { // 0x676f2a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00676f2b: { // 0x676f2b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
