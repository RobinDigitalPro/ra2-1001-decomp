#include "recovered/recovery_b1652.hpp"
#include <limits>
namespace ra2::recovered::b1652 {
using namespace floating_b61;
using Frame=recovery_b566::Frame;
using recovery_b566::finish;using recovery_b566::string_instruction;using recovery_b566::Kind;using recovery_b566::Repeat;using recovery_b566::reverse_divide32;using recovery_b566::reverse_divide64;
namespace integer=direct_b33::integer;namespace floating_b61=ra2::recovered::floating_b61;namespace numeric_b88=ra2::recovered::numeric_b88;
namespace {inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
struct Operations{Api*api;unsigned frame_low,frame_high;};
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_00097920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00497920: { // 0x497920: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00497924: { // 0x497924: 81ec0c040000 SUB ESP,0x40c
    f.sp = integer::sub(f.sp,0x0000040cu,32,flags);
  }
  L0049792a: { // 0x49792a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049792c: { // 0x49792c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049792d: { // 0x49792d: 0f84c5000000 JZ 0x004979f8
    if(integer::condition("JZ",flags)) goto L004979f8;
  }
  L00497933: { // 0x497933: 8d8c2434040000 LEA ECX,[ESP + 0x434]
    s.cx = (f.sp+0x00000434u);
  }
  L0049793a: { // 0x49793a: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0049793e: { // 0x49793e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049793f: { // 0x49793f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497940: { // 0x497940: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00497941: { // 0x497941: e8527a2d00 CALL 0x0076f398
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f398u,4815174u,op); flags=s.arithmetic_flags;
  }
  L00497946: { // 0x497946: 8b8c2434040000 MOV ECX,dword ptr [ESP + 0x434]
    s.cx = m.r32((f.sp+0x00000434u));
  }
  L0049794d: { // 0x49794d: 8bb4243c040000 MOV ESI,dword ptr [ESP + 0x43c]
    s.si = m.r32((f.sp+0x0000043cu));
  }
  L00497954: { // 0x497954: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00497957: { // 0x497957: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L0049795b: { // 0x49795b: 81c108030000 ADD ECX,0x308
    s.cx = integer::add(s.cx,0x00000308u,32,flags);
  }
  L00497961: { // 0x497961: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497962: { // 0x497962: e8e96b0600 CALL 0x004fe550
    s.arithmetic_flags=flags; invoke(m,s,f,0x004fe550u,4815207u,op); flags=s.arithmetic_flags;
  }
  L00497967: { // 0x497967: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0049796a: { // 0x49796a: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00497970: { // 0x497970: 6689542404 MOV word ptr [ESP + 0x4],DX
    m.w16((f.sp+0x00000004u), (s.dx & 0xffffu));
  }
  L00497975: { // 0x497975: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00497977: { // 0x497977: 8a4002 MOV AL,byte ptr [EAX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000002u)));
  }
  L0049797a: { // 0x49797a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049797b: { // 0x49797b: 8844240e MOV byte ptr [ESP + 0xe],AL
    m.w8((f.sp+0x0000000eu), (s.ax & 0xffu));
  }
  L0049797f: { // 0x49797f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00497983: { // 0x497983: 8b54240e MOV EDX,dword ptr [ESP + 0xe]
    s.dx = m.r32((f.sp+0x0000000eu));
  }
  L00497987: { // 0x497987: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L0049798c: { // 0x49798c: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L0049798e: { // 0x49798e: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00497994: { // 0x497994: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0049799a: { // 0x49799a: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0049799c: { // 0x49799c: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L004979a2: { // 0x4979a2: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L004979a4: { // 0x4979a4: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L004979aa: { // 0x4979aa: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004979ac: { // 0x4979ac: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L004979b2: { // 0x4979b2: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L004979b4: { // 0x4979b4: 8b54240d MOV EDX,dword ptr [ESP + 0xd]
    s.dx = m.r32((f.sp+0x0000000du));
  }
  L004979b8: { // 0x4979b8: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004979be: { // 0x4979be: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L004979c0: { // 0x4979c0: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L004979c6: { // 0x4979c6: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004979c8: { // 0x4979c8: 8b8c2434040000 MOV ECX,dword ptr [ESP + 0x434]
    s.cx = m.r32((f.sp+0x00000434u));
  }
  L004979cf: { // 0x4979cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004979d0: { // 0x4979d0: 8b8c2428040000 MOV ECX,dword ptr [ESP + 0x428]
    s.cx = m.r32((f.sp+0x00000428u));
  }
  L004979d7: { // 0x4979d7: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L004979d9: { // 0x4979d9: 8b942430040000 MOV EDX,dword ptr [ESP + 0x430]
    s.dx = m.r32((f.sp+0x00000430u));
  }
  L004979e0: { // 0x4979e0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004979e1: { // 0x4979e1: 8b842430040000 MOV EAX,dword ptr [ESP + 0x430]
    s.ax = m.r32((f.sp+0x00000430u));
  }
  L004979e8: { // 0x4979e8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004979e9: { // 0x4979e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004979ea: { // 0x4979ea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004979eb: { // 0x4979eb: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L004979ef: { // 0x4979ef: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004979f3: { // 0x4979f3: e9a8000000 JMP 0x00497aa0
    goto L00497aa0;
  }
  L004979f8: { // 0x4979f8: 8b8c2428040000 MOV ECX,dword ptr [ESP + 0x428]
    s.cx = m.r32((f.sp+0x00000428u));
  }
  L004979ff: { // 0x4979ff: 8bb42430040000 MOV ESI,dword ptr [ESP + 0x430]
    s.si = m.r32((f.sp+0x00000430u));
  }
  L00497a06: { // 0x497a06: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L00497a0a: { // 0x497a0a: 81c108030000 ADD ECX,0x308
    s.cx = integer::add(s.cx,0x00000308u,32,flags);
  }
  L00497a10: { // 0x497a10: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497a11: { // 0x497a11: e83a6b0600 CALL 0x004fe550
    s.arithmetic_flags=flags; invoke(m,s,f,0x004fe550u,4815382u,op); flags=s.arithmetic_flags;
  }
  L00497a16: { // 0x497a16: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L00497a19: { // 0x497a19: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00497a1f: { // 0x497a1f: 6689542404 MOV word ptr [ESP + 0x4],DX
    m.w16((f.sp+0x00000004u), (s.dx & 0xffffu));
  }
  L00497a24: { // 0x497a24: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00497a26: { // 0x497a26: 8a4002 MOV AL,byte ptr [EAX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000002u)));
  }
  L00497a29: { // 0x497a29: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00497a2a: { // 0x497a2a: 8844240e MOV byte ptr [ESP + 0xe],AL
    m.w8((f.sp+0x0000000eu), (s.ax & 0xffu));
  }
  L00497a2e: { // 0x497a2e: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00497a32: { // 0x497a32: 8b54240e MOV EDX,dword ptr [ESP + 0xe]
    s.dx = m.r32((f.sp+0x0000000eu));
  }
  L00497a36: { // 0x497a36: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00497a3b: { // 0x497a3b: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00497a3d: { // 0x497a3d: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00497a43: { // 0x497a43: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00497a49: { // 0x497a49: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00497a4b: { // 0x497a4b: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L00497a51: { // 0x497a51: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00497a53: { // 0x497a53: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L00497a59: { // 0x497a59: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00497a5b: { // 0x497a5b: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L00497a61: { // 0x497a61: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00497a63: { // 0x497a63: 8b54240d MOV EDX,dword ptr [ESP + 0xd]
    s.dx = m.r32((f.sp+0x0000000du));
  }
  L00497a67: { // 0x497a67: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00497a6d: { // 0x497a6d: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00497a6f: { // 0x497a6f: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L00497a75: { // 0x497a75: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00497a77: { // 0x497a77: 8b8c2434040000 MOV ECX,dword ptr [ESP + 0x434]
    s.cx = m.r32((f.sp+0x00000434u));
  }
  L00497a7e: { // 0x497a7e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00497a7f: { // 0x497a7f: 8b8c2428040000 MOV ECX,dword ptr [ESP + 0x428]
    s.cx = m.r32((f.sp+0x00000428u));
  }
  L00497a86: { // 0x497a86: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00497a88: { // 0x497a88: 8b942430040000 MOV EDX,dword ptr [ESP + 0x430]
    s.dx = m.r32((f.sp+0x00000430u));
  }
  L00497a8f: { // 0x497a8f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497a90: { // 0x497a90: 8b842430040000 MOV EAX,dword ptr [ESP + 0x430]
    s.ax = m.r32((f.sp+0x00000430u));
  }
  L00497a97: { // 0x497a97: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00497a98: { // 0x497a98: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497a99: { // 0x497a99: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00497a9a: { // 0x497a9a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00497a9c: { // 0x497a9c: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00497aa0: { // 0x497aa0: e86bfbffff CALL 0x00497610
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497610u,4815525u,op); flags=s.arithmetic_flags;
  }
  L00497aa5: { // 0x497aa5: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00497aa7: { // 0x497aa7: 8b842414040000 MOV EAX,dword ptr [ESP + 0x414]
    s.ax = m.r32((f.sp+0x00000414u));
  }
  L00497aae: { // 0x497aae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00497aaf: { // 0x497aaf: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00497ab1: { // 0x497ab1: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00497ab3: { // 0x497ab3: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L00497ab6: { // 0x497ab6: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00497ab9: { // 0x497ab9: 81c40c040000 ADD ESP,0x40c
    f.sp = integer::add(f.sp,0x0000040cu,32,flags);
  }
  L00497abf: { // 0x497abf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00097610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00497610: { // 0x497610: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00497613: { // 0x497613: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00497617: { // 0x497617: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00497618: { // 0x497618: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00497619: { // 0x497619: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049761a: { // 0x49761a: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L0049761d: { // 0x49761d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049761e: { // 0x49761e: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L00497622: { // 0x497622: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00497626: { // 0x497626: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00497628: { // 0x497628: 8b1d306d8300 MOV EBX,dword ptr [0x00836d30]
    s.bx = m.r32((0x00836d30u));
  }
  L0049762e: { // 0x49762e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00497631: { // 0x497631: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L00497633: { // 0x497633: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L00497635: { // 0x497635: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00497638: { // 0x497638: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0049763a: { // 0x49763a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049763b: { // 0x49763b: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L0049763f: { // 0x49763f: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00497643: { // 0x497643: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00497644: { // 0x497644: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497645: { // 0x497645: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00497646: { // 0x497646: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497648: { // 0x497648: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0049764c: { // 0x49764c: e81f9df9ff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,4814417u,op); flags=s.arithmetic_flags;
  }
  L00497651: { // 0x497651: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00497655: { // 0x497655: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00497659: { // 0x497659: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0049765c: { // 0x49765c: 7411 JZ 0x0049766f
    if(integer::condition("JZ",flags)) goto L0049766f;
  }
  L0049765e: { // 0x49765e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00497660: { // 0x497660: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00497661: { // 0x497661: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00497663: { // 0x497663: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00497665: { // 0x497665: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00497667: { // 0x497667: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00497669: { // 0x497669: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L0049766d: { // 0x49766d: eb07 JMP 0x00497676
    goto L00497676;
  }
  L0049766f: { // 0x49766f: f6c402 TEST AH,0x2
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  L00497672: { // 0x497672: 7402 JZ 0x00497676
    if(integer::condition("JZ",flags)) goto L00497676;
  }
  L00497674: { // 0x497674: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L00497676: { // 0x497676: f6c480 TEST AH,0x80
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000080u),8,flags);
  }
  L00497679: { // 0x497679: 7446 JZ 0x004976c1
    if(integer::condition("JZ",flags)) goto L004976c1;
  }
  L0049767b: { // 0x49767b: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0049767e: { // 0x49767e: 8d45ff LEA EAX,[EBP + -0x1]
    s.ax = (s.bp-0x00000001u);
  }
  L00497681: { // 0x497681: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00497685: { // 0x497685: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00497689: { // 0x497689: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0049768c: { // 0x49768c: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00497690: { // 0x497690: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00497694: { // 0x497694: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00497698: { // 0x497698: 8d442450 LEA EAX,[ESP + 0x50]
    s.ax = (f.sp+0x00000050u);
  }
  L0049769c: { // 0x49769c: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L0049769f: { // 0x49769f: 6a3c PUSH 0x3c
    f.push(m,0x0000003cu);
  }
  L004976a1: { // 0x4976a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004976a2: { // 0x4976a2: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L004976a6: { // 0x4976a6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004976a8: { // 0x4976a8: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L004976ac: { // 0x4976ac: c644245800 MOV byte ptr [ESP + 0x58],0x0
    m.w8((f.sp+0x00000058u), 0x00000000u);
  }
  L004976b1: { // 0x4976b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004976b2: { // 0x4976b2: c644245d00 MOV byte ptr [ESP + 0x5d],0x0
    m.w8((f.sp+0x0000005du), 0x00000000u);
  }
  L004976b7: { // 0x4976b7: c644245e00 MOV byte ptr [ESP + 0x5e],0x0
    m.w8((f.sp+0x0000005eu), 0x00000000u);
  }
  L004976bc: { // 0x4976bc: ff521c CALL dword ptr [EDX + 0x1c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000001cu)),4814527u,op); flags=s.arithmetic_flags;
  }
  L004976bf: { // 0x4976bf: eb35 JMP 0x004976f6
    goto L004976f6;
  }
  L004976c1: { // 0x4976c1: f6c404 TEST AH,0x4
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  L004976c4: { // 0x4976c4: 7430 JZ 0x004976f6
    if(integer::condition("JZ",flags)) goto L004976f6;
  }
  L004976c6: { // 0x4976c6: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004976c9: { // 0x4976c9: 8d45ff LEA EAX,[EBP + -0x1]
    s.ax = (s.bp-0x00000001u);
  }
  L004976cc: { // 0x4976cc: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L004976d0: { // 0x4976d0: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L004976d4: { // 0x4976d4: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004976d7: { // 0x4976d7: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L004976da: { // 0x4976da: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004976de: { // 0x4976de: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004976e2: { // 0x4976e2: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004976e6: { // 0x4976e6: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004976ea: { // 0x4976ea: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004976ec: { // 0x4976ec: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L004976f0: { // 0x4976f0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004976f2: { // 0x4976f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004976f3: { // 0x4976f3: ff5214 CALL dword ptr [EDX + 0x14]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000014u)),4814582u,op); flags=s.arithmetic_flags;
  }
  L004976f6: { // 0x4976f6: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L004976f8: { // 0x4976f8: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L004976fb: { // 0x4976fb: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L004976fe: { // 0x4976fe: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00497702: { // 0x497702: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00497704: { // 0x497704: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00497707: { // 0x497707: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0049770b: { // 0x49770b: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0049770d: { // 0x49770d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049770f: { // 0x49770f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497711: { // 0x497711: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00497715: { // 0x497715: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00497719: { // 0x497719: e8f29bf9ff CALL 0x00431310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431310u,4814622u,op); flags=s.arithmetic_flags;
  }
  L0049771e: { // 0x49771e: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00497722: { // 0x497722: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497724: { // 0x497724: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497725: { // 0x497725: e8f69bf9ff CALL 0x00431320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431320u,4814634u,op); flags=s.arithmetic_flags;
  }
  L0049772a: { // 0x49772a: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0049772e: { // 0x49772e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049772f: { // 0x49772f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497731: { // 0x497731: e8ba9bf9ff CALL 0x004312f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004312f0u,4814646u,op); flags=s.arithmetic_flags;
  }
  L00497736: { // 0x497736: 8b0d186d8300 MOV ECX,dword ptr [0x00836d18]
    s.cx = m.r32((0x00836d18u));
  }
  L0049773c: { // 0x49773c: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00497740: { // 0x497740: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00497744: { // 0x497744: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00497746: { // 0x497746: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00497748: { // 0x497748: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00497749: { // 0x497749: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049774a: { // 0x49774a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049774b: { // 0x49774b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049774c: { // 0x49774c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049774d: { // 0x49774d: e8beaaf9ff CALL 0x00432210
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432210u,4814674u,op); flags=s.arithmetic_flags;
  }
  L00497752: { // 0x497752: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00497756: { // 0x497756: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00497757: { // 0x497757: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L00497759: { // 0x497759: 896804 MOV dword ptr [EAX + 0x4],EBP
    m.w32((s.ax+0x00000004u), s.bp);
  }
  L0049775c: { // 0x49775c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049775d: { // 0x49775d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049775e: { // 0x49775e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049775f: { // 0x49775f: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00497762: { // 0x497762: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000112d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112d0: { // 0x4112d0: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004112d3: { // 0x4112d3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000112f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112f0: { // 0x4112f0: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L004112f3: { // 0x4112f3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004112f4: { // 0x4112f4: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004112f7: { // 0x4112f7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004112f9: { // 0x4112f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u,op); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u,op); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u,op); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000312f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004312f0: { // 0x4312f0: 668b542404 MOV DX,word ptr [ESP + 0x4]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000004u)));
  }
  L004312f5: { // 0x4312f5: 668b4124 MOV AX,word ptr [ECX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x00000024u)));
  }
  L004312f9: { // 0x4312f9: 66895124 MOV word ptr [ECX + 0x24],DX
    m.w16((s.cx+0x00000024u), (s.dx & 0xffffu));
  }
  L004312fd: { // 0x4312fd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431310: { // 0x431310: 8a542404 MOV DL,byte ptr [ESP + 0x4]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000004u)));
  }
  L00431314: { // 0x431314: 8a4141 MOV AL,byte ptr [ECX + 0x41]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000041u)));
  }
  L00431317: { // 0x431317: 885141 MOV byte ptr [ECX + 0x41],DL
    m.w8((s.cx+0x00000041u), (s.dx & 0xffu));
  }
  L0043131a: { // 0x43131a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431320: { // 0x431320: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00431324: { // 0x431324: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431326: { // 0x431326: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00431328: { // 0x431328: 741a JZ 0x00431344
    if(integer::condition("JZ",flags)) goto L00431344;
  }
  L0043132a: { // 0x43132a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0043132c: { // 0x43132c: 895130 MOV dword ptr [ECX + 0x30],EDX
    m.w32((s.cx+0x00000030u), s.dx);
  }
  L0043132f: { // 0x43132f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00431332: { // 0x431332: 895134 MOV dword ptr [ECX + 0x34],EDX
    m.w32((s.cx+0x00000034u), s.dx);
  }
  L00431335: { // 0x431335: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00431338: { // 0x431338: 895138 MOV dword ptr [ECX + 0x38],EDX
    m.w32((s.cx+0x00000038u), s.dx);
  }
  L0043133b: { // 0x43133b: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0043133e: { // 0x43133e: 89413c MOV dword ptr [ECX + 0x3c],EAX
    m.w32((s.cx+0x0000003cu), s.ax);
  }
  L00431341: { // 0x431341: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00431344: { // 0x431344: 89513c MOV dword ptr [ECX + 0x3c],EDX
    m.w32((s.cx+0x0000003cu), s.dx);
  }
  L00431347: { // 0x431347: 895138 MOV dword ptr [ECX + 0x38],EDX
    m.w32((s.cx+0x00000038u), s.dx);
  }
  L0043134a: { // 0x43134a: 895134 MOV dword ptr [ECX + 0x34],EDX
    m.w32((s.cx+0x00000034u), s.dx);
  }
  L0043134d: { // 0x43134d: 895130 MOV dword ptr [ECX + 0x30],EDX
    m.w32((s.cx+0x00000030u), s.dx);
  }
  L00431350: { // 0x431350: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431370: { // 0x431370: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00431373: { // 0x431373: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00431376: { // 0x431376: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431378: { // 0x431378: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043137a: { // 0x43137a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0043137b: { // 0x43137b: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L0043137f: { // 0x43137f: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00431383: { // 0x431383: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431387: { // 0x431387: 0f847b010000 JZ 0x00431508
    if(integer::condition("JZ",flags)) goto L00431508;
  }
  L0043138d: { // 0x43138d: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L00431391: { // 0x431391: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00431393: { // 0x431393: 0f846f010000 JZ 0x00431508
    if(integer::condition("JZ",flags)) goto L00431508;
  }
  L00431399: { // 0x431399: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  L0043139c: { // 0x43139c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043139d: { // 0x43139d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043139e: { // 0x43139e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043139f: { // 0x43139f: 668b3b MOV DI,word ptr [EBX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L004313a2: { // 0x4313a2: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004313a4: { // 0x4313a4: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004313a6: { // 0x4313a6: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L004313a9: { // 0x4313a9: 6685ff TEST DI,DI
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L004313ac: { // 0x4313ac: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004313b0: { // 0x4313b0: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004313b4: { // 0x4313b4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004313b8: { // 0x4313b8: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004313bc: { // 0x4313bc: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004313c0: { // 0x4313c0: 0f841a010000 JZ 0x004314e0
    if(integer::condition("JZ",flags)) goto L004314e0;
  }
  L004313c6: { // 0x4313c6: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L004313cc: { // 0x4313cc: 8d47f7 LEA EAX,[EDI + -0x9]
    s.ax = (s.di-0x00000009u);
  }
  L004313cf: { // 0x4313cf: 83f817 CMP EAX,0x17
    (void)integer::sub(s.ax,0x00000017u,32,flags);
  }
  L004313d2: { // 0x4313d2: 7751 JA 0x00431425
    if(integer::condition("JA",flags)) goto L00431425;
  }
  L004313d4: { // 0x4313d4: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004313d6: { // 0x4313d6: 8a8838154300 MOV CL,byte ptr [EAX + 0x431538]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00431538u)));
  }
  L004313dc: { // 0x4313dc: ff248d28154300 JMP dword ptr [ECX*0x4 + 0x431528]
    switch(m.r32(((s.cx * 0x00000004u)+0x00431528u))){
    case 0x00431370u: goto L00431370;
    case 0x00431373u: goto L00431373;
    case 0x00431376u: goto L00431376;
    case 0x00431378u: goto L00431378;
    case 0x0043137au: goto L0043137a;
    case 0x0043137bu: goto L0043137b;
    case 0x0043137fu: goto L0043137f;
    case 0x00431383u: goto L00431383;
    case 0x00431387u: goto L00431387;
    case 0x0043138du: goto L0043138d;
    case 0x00431391u: goto L00431391;
    case 0x00431393u: goto L00431393;
    case 0x00431399u: goto L00431399;
    case 0x0043139cu: goto L0043139c;
    case 0x0043139du: goto L0043139d;
    case 0x0043139eu: goto L0043139e;
    case 0x0043139fu: goto L0043139f;
    case 0x004313a2u: goto L004313a2;
    case 0x004313a4u: goto L004313a4;
    case 0x004313a6u: goto L004313a6;
    case 0x004313a9u: goto L004313a9;
    case 0x004313acu: goto L004313ac;
    case 0x004313b0u: goto L004313b0;
    case 0x004313b4u: goto L004313b4;
    case 0x004313b8u: goto L004313b8;
    case 0x004313bcu: goto L004313bc;
    case 0x004313c0u: goto L004313c0;
    case 0x004313c6u: goto L004313c6;
    case 0x004313ccu: goto L004313cc;
    case 0x004313cfu: goto L004313cf;
    case 0x004313d2u: goto L004313d2;
    case 0x004313d4u: goto L004313d4;
    case 0x004313d6u: goto L004313d6;
    case 0x004313dcu: goto L004313dc;
    case 0x004313e3u: goto L004313e3;
    case 0x004313e7u: goto L004313e7;
    case 0x004313edu: goto L004313ed;
    case 0x004313f1u: goto L004313f1;
    case 0x004313f5u: goto L004313f5;
    case 0x004313f7u: goto L004313f7;
    case 0x004313f9u: goto L004313f9;
    case 0x004313fbu: goto L004313fb;
    case 0x004313ffu: goto L004313ff;
    case 0x00431404u: goto L00431404;
    case 0x00431408u: goto L00431408;
    case 0x0043140bu: goto L0043140b;
    case 0x0043140du: goto L0043140d;
    case 0x0043140fu: goto L0043140f;
    case 0x00431410u: goto L00431410;
    case 0x00431412u: goto L00431412;
    case 0x00431414u: goto L00431414;
    case 0x00431419u: goto L00431419;
    case 0x0043141du: goto L0043141d;
    case 0x00431421u: goto L00431421;
    case 0x00431425u: goto L00431425;
    case 0x00431429u: goto L00431429;
    case 0x0043142bu: goto L0043142b;
    case 0x0043142du: goto L0043142d;
    case 0x0043142fu: goto L0043142f;
    case 0x00431432u: goto L00431432;
    case 0x00431434u: goto L00431434;
    case 0x00431438u: goto L00431438;
    case 0x0043143au: goto L0043143a;
    case 0x0043143cu: goto L0043143c;
    case 0x00431440u: goto L00431440;
    case 0x00431441u: goto L00431441;
    case 0x00431444u: goto L00431444;
    case 0x00431447u: goto L00431447;
    case 0x0043144au: goto L0043144a;
    case 0x0043144cu: goto L0043144c;
    case 0x0043144eu: goto L0043144e;
    case 0x00431452u: goto L00431452;
    case 0x00431455u: goto L00431455;
    case 0x00431457u: goto L00431457;
    case 0x00431459u: goto L00431459;
    case 0x0043145du: goto L0043145d;
    case 0x0043145fu: goto L0043145f;
    case 0x00431461u: goto L00431461;
    case 0x00431462u: goto L00431462;
    case 0x00431465u: goto L00431465;
    case 0x00431467u: goto L00431467;
    case 0x0043146au: goto L0043146a;
    case 0x0043146cu: goto L0043146c;
    case 0x00431470u: goto L00431470;
    case 0x00431472u: goto L00431472;
    case 0x00431474u: goto L00431474;
    case 0x00431476u: goto L00431476;
    case 0x00431478u: goto L00431478;
    case 0x0043147cu: goto L0043147c;
    case 0x0043147eu: goto L0043147e;
    case 0x00431480u: goto L00431480;
    case 0x00431483u: goto L00431483;
    case 0x00431485u: goto L00431485;
    case 0x00431489u: goto L00431489;
    case 0x0043148bu: goto L0043148b;
    case 0x0043148fu: goto L0043148f;
    case 0x00431491u: goto L00431491;
    case 0x00431494u: goto L00431494;
    case 0x00431496u: goto L00431496;
    case 0x00431498u: goto L00431498;
    case 0x0043149au: goto L0043149a;
    case 0x0043149du: goto L0043149d;
    case 0x004314a1u: goto L004314a1;
    case 0x004314a3u: goto L004314a3;
    case 0x004314a7u: goto L004314a7;
    case 0x004314abu: goto L004314ab;
    case 0x004314afu: goto L004314af;
    case 0x004314b1u: goto L004314b1;
    case 0x004314b3u: goto L004314b3;
    case 0x004314b5u: goto L004314b5;
    case 0x004314b9u: goto L004314b9;
    case 0x004314bdu: goto L004314bd;
    case 0x004314bfu: goto L004314bf;
    case 0x004314c3u: goto L004314c3;
    case 0x004314c5u: goto L004314c5;
    case 0x004314c9u: goto L004314c9;
    case 0x004314ccu: goto L004314cc;
    case 0x004314d0u: goto L004314d0;
    case 0x004314d3u: goto L004314d3;
    case 0x004314d7u: goto L004314d7;
    case 0x004314dau: goto L004314da;
    case 0x004314e0u: goto L004314e0;
    case 0x004314e4u: goto L004314e4;
    case 0x004314e5u: goto L004314e5;
    case 0x004314e6u: goto L004314e6;
    case 0x004314e7u: goto L004314e7;
    case 0x004314e9u: goto L004314e9;
    case 0x004314ebu: goto L004314eb;
    case 0x004314efu: goto L004314ef;
    case 0x004314f1u: goto L004314f1;
    case 0x004314f5u: goto L004314f5;
    case 0x004314f7u: goto L004314f7;
    case 0x004314f9u: goto L004314f9;
    case 0x004314fdu: goto L004314fd;
    case 0x004314ffu: goto L004314ff;
    case 0x00431501u: goto L00431501;
    case 0x00431502u: goto L00431502;
    case 0x00431505u: goto L00431505;
    case 0x00431508u: goto L00431508;
    case 0x0043150cu: goto L0043150c;
    case 0x0043150eu: goto L0043150e;
    case 0x00431510u: goto L00431510;
    case 0x00431512u: goto L00431512;
    case 0x00431516u: goto L00431516;
    case 0x00431518u: goto L00431518;
    case 0x0043151au: goto L0043151a;
    case 0x0043151cu: goto L0043151c;
    case 0x0043151eu: goto L0043151e;
    case 0x0043151fu: goto L0043151f;
    case 0x00431522u: goto L00431522;
    default:throw std::domain_error("recovery107 unsupported switch destination");}
  }
  L004313e3: { // 0x4313e3: 6683fa0d CMP DX,0xd
    (void)integer::sub((s.dx & 0xffffu),0x0000000du,16,flags);
  }
  L004313e7: { // 0x4313e7: 0f84dc000000 JZ 0x004314c9
    if(integer::condition("JZ",flags)) goto L004314c9;
  }
  L004313ed: { // 0x4313ed: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004313f1: { // 0x4313f1: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004313f5: { // 0x4313f5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004313f7: { // 0x4313f7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004313f9: { // 0x4313f9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004313fb: { // 0x4313fb: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004313ff: { // 0x4313ff: e9c5000000 JMP 0x004314c9
    goto L004314c9;
  }
  L00431404: { // 0x431404: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00431408: { // 0x431408: 8b7828 MOV EDI,dword ptr [EAX + 0x28]
    s.di = m.r32((s.ax+0x00000028u));
  }
  L0043140b: { // 0x43140b: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0043140d: { // 0x43140d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0043140f: { // 0x43140f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00431410: { // 0x431410: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00431412: { // 0x431412: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L00431414: { // 0x431414: e9b0000000 JMP 0x004314c9
    goto L004314c9;
  }
  L00431419: { // 0x431419: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0043141d: { // 0x43141d: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00431421: { // 0x431421: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00431425: { // 0x431425: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00431429: { // 0x431429: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043142b: { // 0x43142b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043142d: { // 0x43142d: 741b JZ 0x0043144a
    if(integer::condition("JZ",flags)) goto L0043144a;
  }
  L0043142f: { // 0x43142f: 8b4918 MOV ECX,dword ptr [ECX + 0x18]
    s.cx = m.r32((s.cx+0x00000018u));
  }
  L00431432: { // 0x431432: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431434: { // 0x431434: 668b1479 MOV DX,word ptr [ECX + EDI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+(s.di * 0x00000002u))));
  }
  L00431438: { // 0x431438: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043143a: { // 0x43143a: 740e JZ 0x0043144a
    if(integer::condition("JZ",flags)) goto L0043144a;
  }
  L0043143c: { // 0x43143c: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00431440: { // 0x431440: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00431441: { // 0x431441: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L00431444: { // 0x431444: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00431447: { // 0x431447: 03411c ADD EAX,dword ptr [ECX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L0043144a: { // 0x43144a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043144c: { // 0x43144c: 750b JNZ 0x00431459
    if(integer::condition("JNZ",flags)) goto L00431459;
  }
  L0043144e: { // 0x43144e: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00431452: { // 0x431452: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00431455: { // 0x431455: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431457: { // 0x431457: 7470 JZ 0x004314c9
    if(integer::condition("JZ",flags)) goto L004314c9;
  }
  L00431459: { // 0x431459: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0043145d: { // 0x43145d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0043145f: { // 0x43145f: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  L00431461: { // 0x431461: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00431462: { // 0x431462: 8b522c MOV EDX,dword ptr [EDX + 0x2c]
    s.dx = m.r32((s.dx+0x0000002cu));
  }
  L00431465: { // 0x431465: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00431467: { // 0x431467: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L0043146a: { // 0x43146a: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0043146c: { // 0x43146c: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00431470: { // 0x431470: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431472: { // 0x431472: 744b JZ 0x004314bf
    if(integer::condition("JZ",flags)) goto L004314bf;
  }
  L00431474: { // 0x431474: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431476: { // 0x431476: 7e47 JLE 0x004314bf
    if(integer::condition("JLE",flags)) goto L004314bf;
  }
  L00431478: { // 0x431478: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043147c: { // 0x43147c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043147e: { // 0x43147e: 7411 JZ 0x00431491
    if(integer::condition("JZ",flags)) goto L00431491;
  }
  L00431480: { // 0x431480: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00431483: { // 0x431483: 7e22 JLE 0x004314a7
    if(integer::condition("JLE",flags)) goto L004314a7;
  }
  L00431485: { // 0x431485: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00431489: { // 0x431489: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0043148b: { // 0x43148b: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0043148f: { // 0x43148f: eb16 JMP 0x004314a7
    goto L004314a7;
  }
  L00431491: { // 0x431491: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00431494: { // 0x431494: 7e07 JLE 0x0043149d
    if(integer::condition("JLE",flags)) goto L0043149d;
  }
  L00431496: { // 0x431496: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00431498: { // 0x431498: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0043149a: { // 0x43149a: 83eb02 SUB EBX,0x2
    s.bx = integer::sub(s.bx,0x00000002u,32,flags);
  }
  L0043149d: { // 0x43149d: 3b742430 CMP ESI,dword ptr [ESP + 0x30]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004314a1: { // 0x4314a1: 7e04 JLE 0x004314a7
    if(integer::condition("JLE",flags)) goto L004314a7;
  }
  L004314a3: { // 0x4314a3: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L004314a7: { // 0x4314a7: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L004314ab: { // 0x4314ab: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004314af: { // 0x4314af: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004314b1: { // 0x4314b1: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004314b3: { // 0x4314b3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004314b5: { // 0x4314b5: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L004314b9: { // 0x4314b9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004314bd: { // 0x4314bd: eb0a JMP 0x004314c9
    goto L004314c9;
  }
  L004314bf: { // 0x4314bf: 3b742430 CMP ESI,dword ptr [ESP + 0x30]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004314c3: { // 0x4314c3: 7e04 JLE 0x004314c9
    if(integer::condition("JLE",flags)) goto L004314c9;
  }
  L004314c5: { // 0x4314c5: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L004314c9: { // 0x4314c9: 668b3b MOV DI,word ptr [EBX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L004314cc: { // 0x4314cc: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L004314d0: { // 0x4314d0: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L004314d3: { // 0x4314d3: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004314d7: { // 0x4314d7: 6685ff TEST DI,DI
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L004314da: { // 0x4314da: 0f85e6feffff JNZ 0x004313c6
    if(integer::condition("JNZ",flags)) goto L004313c6;
  }
  L004314e0: { // 0x4314e0: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L004314e4: { // 0x4314e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004314e5: { // 0x4314e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004314e6: { // 0x4314e6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004314e7: { // 0x4314e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004314e9: { // 0x4314e9: 7406 JZ 0x004314f1
    if(integer::condition("JZ",flags)) goto L004314f1;
  }
  L004314eb: { // 0x4314eb: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004314ef: { // 0x4314ef: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004314f1: { // 0x4314f1: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L004314f5: { // 0x4314f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004314f7: { // 0x4314f7: 7406 JZ 0x004314ff
    if(integer::condition("JZ",flags)) goto L004314ff;
  }
  L004314f9: { // 0x4314f9: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L004314fd: { // 0x4314fd: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004314ff: { // 0x4314ff: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00431501: { // 0x431501: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431502: { // 0x431502: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00431505: { // 0x431505: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00431508: { // 0x431508: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0043150c: { // 0x43150c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043150e: { // 0x43150e: 7402 JZ 0x00431512
    if(integer::condition("JZ",flags)) goto L00431512;
  }
  L00431510: { // 0x431510: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00431512: { // 0x431512: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00431516: { // 0x431516: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00431518: { // 0x431518: 7402 JZ 0x0043151c
    if(integer::condition("JZ",flags)) goto L0043151c;
  }
  L0043151a: { // 0x43151a: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0043151c: { // 0x43151c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043151e: { // 0x43151e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043151f: { // 0x43151f: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00431522: { // 0x431522: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00031790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431790: { // 0x431790: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00431794: { // 0x431794: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L00431797: { // 0x431797: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000317a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004317a0: { // 0x4317a0: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L004317a3: { // 0x4317a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004317a4: { // 0x4317a4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004317a5: { // 0x4317a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004317a6: { // 0x4317a6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004317a7: { // 0x4317a7: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L004317ab: { // 0x4317ab: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004317ad: { // 0x4317ad: 6683ff09 CMP DI,0x9
    (void)integer::sub((s.di & 0xffffu),0x00000009u,16,flags);
  }
  L004317b1: { // 0x4317b1: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004317b5: { // 0x4317b5: 7521 JNZ 0x004317d8
    if(integer::condition("JNZ",flags)) goto L004317d8;
  }
  L004317b7: { // 0x4317b7: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L004317ba: { // 0x4317ba: 8b7c2448 MOV EDI,dword ptr [ESP + 0x48]
    s.di = m.r32((f.sp+0x00000048u));
  }
  L004317be: { // 0x4317be: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  L004317c1: { // 0x4317c1: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L004317c3: { // 0x4317c3: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004317c5: { // 0x4317c5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004317c7: { // 0x4317c7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004317c8: { // 0x4317c8: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004317ca: { // 0x4317ca: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004317cc: { // 0x4317cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004317cd: { // 0x4317cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004317ce: { // 0x4317ce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004317cf: { // 0x4317cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004317d0: { // 0x4317d0: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004317d2: { // 0x4317d2: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004317d5: { // 0x4317d5: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004317d8: { // 0x4317d8: 668b4624 MOV AX,word ptr [ESI + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000024u)));
  }
  L004317dc: { // 0x4317dc: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L004317e1: { // 0x4317e1: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L004317e5: { // 0x4317e5: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004317e8: { // 0x4317e8: 7404 JZ 0x004317ee
    if(integer::condition("JZ",flags)) goto L004317ee;
  }
  L004317ea: { // 0x4317ea: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L004317ee: { // 0x4317ee: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L004317f1: { // 0x4317f1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004317f3: { // 0x4317f3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004317f5: { // 0x4317f5: 741d JZ 0x00431814
    if(integer::condition("JZ",flags)) goto L00431814;
  }
  L004317f7: { // 0x4317f7: 8b5918 MOV EBX,dword ptr [ECX + 0x18]
    s.bx = m.r32((s.cx+0x00000018u));
  }
  L004317fa: { // 0x4317fa: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L00431800: { // 0x431800: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431802: { // 0x431802: 668b147b MOV DX,word ptr [EBX + EDI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+(s.di * 0x00000002u))));
  }
  L00431806: { // 0x431806: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431808: { // 0x431808: 740a JZ 0x00431814
    if(integer::condition("JZ",flags)) goto L00431814;
  }
  L0043180a: { // 0x43180a: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L0043180d: { // 0x43180d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0043180e: { // 0x43180e: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00431811: { // 0x431811: 03411c ADD EAX,dword ptr [ECX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L00431814: { // 0x431814: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431816: { // 0x431816: 7525 JNZ 0x0043183d
    if(integer::condition("JNZ",flags)) goto L0043183d;
  }
  L00431818: { // 0x431818: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0043181c: { // 0x43181c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043181e: { // 0x43181e: 7408 JZ 0x00431828
    if(integer::condition("JZ",flags)) goto L00431828;
  }
  L00431820: { // 0x431820: 8174244455550000 XOR dword ptr [ESP + 0x44],0x5555
    m.w32((f.sp+0x00000044u), integer::logical((m.r32((f.sp+0x00000044u)))^(0x00005555u),32,flags));
  }
  L00431828: { // 0x431828: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0043182b: { // 0x43182b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043182d: { // 0x43182d: 750e JNZ 0x0043183d
    if(integer::condition("JNZ",flags)) goto L0043183d;
  }
  L0043182f: { // 0x43182f: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431833: { // 0x431833: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431834: { // 0x431834: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431835: { // 0x431835: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431836: { // 0x431836: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431837: { // 0x431837: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0043183a: { // 0x43183a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0043183d: { // 0x43183d: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L00431840: { // 0x431840: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431842: { // 0x431842: 750e JNZ 0x00431852
    if(integer::condition("JNZ",flags)) goto L00431852;
  }
  L00431844: { // 0x431844: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431848: { // 0x431848: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431849: { // 0x431849: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043184a: { // 0x43184a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043184b: { // 0x43184b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043184c: { // 0x43184c: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0043184f: { // 0x43184f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00431852: { // 0x431852: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L00431855: { // 0x431855: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00431858: { // 0x431858: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0043185c: { // 0x43185c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043185e: { // 0x43185e: 8a10 MOV DL,byte ptr [EAX]
    s.dx = with_al(s.dx, m.r8((s.ax)));
  }
  L00431860: { // 0x431860: 8a4641 MOV AL,byte ptr [ESI + 0x41]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000041u)));
  }
  L00431863: { // 0x431863: 8b74244c MOV ESI,dword ptr [ESP + 0x4c]
    s.si = m.r32((f.sp+0x0000004cu));
  }
  L00431867: { // 0x431867: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0043186b: { // 0x43186b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043186d: { // 0x43186d: 0f8405020000 JZ 0x00431a78
    if(integer::condition("JZ",flags)) goto L00431a78;
  }
  L00431873: { // 0x431873: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L00431877: { // 0x431877: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00431879: { // 0x431879: 8d4437ff LEA EAX,[EDI + ESI*0x1 + -0x1]
    s.ax = (s.di+(s.si * 0x00000001u)-0x00000001u);
  }
  L0043187d: { // 0x43187d: 8d5419ff LEA EDX,[ECX + EBX*0x1 + -0x1]
    s.dx = (s.cx+(s.bx * 0x00000001u)-0x00000001u);
  }
  L00431881: { // 0x431881: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431882: { // 0x431882: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00431883: { // 0x431883: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431884: { // 0x431884: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L00431888: { // 0x431888: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00431889: { // 0x431889: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043188a: { // 0x43188a: ff15a8547800 CALL dword ptr [0x007854a8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007854a8u)),4397200u,op); flags=s.arithmetic_flags;
  }
  L00431890: { // 0x431890: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00431894: { // 0x431894: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00431898: { // 0x431898: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0043189c: { // 0x43189c: 8d4d30 LEA ECX,[EBP + 0x30]
    s.cx = (s.bp+0x00000030u);
  }
  L0043189f: { // 0x43189f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004318a0: { // 0x4318a0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004318a1: { // 0x4318a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004318a2: { // 0x4318a2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004318a4: { // 0x4318a4: e817060000 CALL 0x00431ec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431ec0u,4397225u,op); flags=s.arithmetic_flags;
  }
  L004318a9: { // 0x4318a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004318ab: { // 0x4318ab: 7515 JNZ 0x004318c2
    if(integer::condition("JNZ",flags)) goto L004318c2;
  }
  L004318ad: { // 0x4318ad: 8b452c MOV EAX,dword ptr [EBP + 0x2c]
    s.ax = m.r32((s.bp+0x0000002cu));
  }
  L004318b0: { // 0x4318b0: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004318b4: { // 0x4318b4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004318b6: { // 0x4318b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004318b7: { // 0x4318b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004318b8: { // 0x4318b8: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004318ba: { // 0x4318ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004318bb: { // 0x4318bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004318bc: { // 0x4318bc: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004318bf: { // 0x4318bf: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004318c2: { // 0x4318c2: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L004318c6: { // 0x4318c6: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004318ca: { // 0x4318ca: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L004318ce: { // 0x4318ce: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004318d2: { // 0x4318d2: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L004318d6: { // 0x4318d6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004318d8: { // 0x4318d8: 7c18 JL 0x004318f2
    if(integer::condition("JL",flags)) goto L004318f2;
  }
  L004318da: { // 0x4318da: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004318de: { // 0x4318de: 3b442438 CMP EAX,dword ptr [ESP + 0x38]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000038u)),32,flags);
  }
  L004318e2: { // 0x4318e2: 7f0e JG 0x004318f2
    if(integer::condition("JG",flags)) goto L004318f2;
  }
  L004318e4: { // 0x4318e4: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L004318e6: { // 0x4318e6: 7c0a JL 0x004318f2
    if(integer::condition("JL",flags)) goto L004318f2;
  }
  L004318e8: { // 0x4318e8: 394c242c CMP dword ptr [ESP + 0x2c],ECX
    (void)integer::sub(m.r32((f.sp+0x0000002cu)),s.cx,32,flags);
  }
  L004318ec: { // 0x4318ec: 0f8e86010000 JLE 0x00431a78
    if(integer::condition("JLE",flags)) goto L00431a78;
  }
  L004318f2: { // 0x4318f2: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004318f4: { // 0x4318f4: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004318f6: { // 0x4318f6: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004318fa: { // 0x4318fa: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L004318fc: { // 0x4318fc: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L004318fe: { // 0x4318fe: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00431902: { // 0x431902: 8b7a18 MOV EDI,dword ptr [EDX + 0x18]
    s.di = m.r32((s.dx+0x00000018u));
  }
  L00431905: { // 0x431905: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00431906: { // 0x431906: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
  L00431909: { // 0x431909: 8b4210 MOV EAX,dword ptr [EDX + 0x10]
    s.ax = m.r32((s.dx+0x00000010u));
  }
  L0043190c: { // 0x43190c: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0043190e: { // 0x43190e: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00431911: { // 0x431911: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00431915: { // 0x431915: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00431919: { // 0x431919: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0043191b: { // 0x43191b: 8b720c MOV ESI,dword ptr [EDX + 0xc]
    s.si = m.r32((s.dx+0x0000000cu));
  }
  L0043191e: { // 0x43191e: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00431922: { // 0x431922: 8d3446 LEA ESI,[ESI + EAX*0x2]
    s.si = (s.si+(s.ax * 0x00000002u));
  }
  L00431925: { // 0x431925: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00431927: { // 0x431927: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431928: { // 0x431928: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0043192c: { // 0x43192c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043192e: { // 0x43192e: 0f8430020000 JZ 0x00431b64
    if(integer::condition("JZ",flags)) goto L00431b64;
  }
  L00431934: { // 0x431934: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00431935: { // 0x431935: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00431939: { // 0x431939: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L0043193d: { // 0x43193d: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431941: { // 0x431941: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00431945: { // 0x431945: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L00431949: { // 0x431949: 8a5500 MOV DL,byte ptr [EBP]
    s.dx = with_al(s.dx, m.r8((s.bp)));
  }
  L0043194c: { // 0x43194c: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0043194d: { // 0x43194d: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0043194f: { // 0x43194f: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00431953: { // 0x431953: 750e JNZ 0x00431963
    if(integer::condition("JNZ",flags)) goto L00431963;
  }
  L00431955: { // 0x431955: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L00431958: { // 0x431958: 83e908 SUB ECX,0x8
    s.cx = integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0043195b: { // 0x43195b: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L0043195e: { // 0x43195e: e9da000000 JMP 0x00431a3d
    goto L00431a3d;
  }
  L00431963: { // 0x431963: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431965: { // 0x431965: 7c12 JL 0x00431979
    if(integer::condition("JL",flags)) goto L00431979;
  }
  L00431967: { // 0x431967: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431969: { // 0x431969: 7f0e JG 0x00431979
    if(integer::condition("JG",flags)) goto L00431979;
  }
  L0043196b: { // 0x43196b: f6c280 TEST DL,0x80
    (void)integer::logical(((s.dx & 0xffu))&(0x00000080u),8,flags);
  }
  L0043196e: { // 0x43196e: 7409 JZ 0x00431979
    if(integer::condition("JZ",flags)) goto L00431979;
  }
  L00431970: { // 0x431970: 8b6c2444 MOV EBP,dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00431974: { // 0x431974: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431977: { // 0x431977: eb04 JMP 0x0043197d
    goto L0043197d;
  }
  L00431979: { // 0x431979: 8b6c2444 MOV EBP,dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L0043197d: { // 0x43197d: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431980: { // 0x431980: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431981: { // 0x431981: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431982: { // 0x431982: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431984: { // 0x431984: 0f8ebb000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L0043198a: { // 0x43198a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0043198c: { // 0x43198c: 7c0c JL 0x0043199a
    if(integer::condition("JL",flags)) goto L0043199a;
  }
  L0043198e: { // 0x43198e: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431990: { // 0x431990: 7f08 JG 0x0043199a
    if(integer::condition("JG",flags)) goto L0043199a;
  }
  L00431992: { // 0x431992: f6c240 TEST DL,0x40
    (void)integer::logical(((s.dx & 0xffu))&(0x00000040u),8,flags);
  }
  L00431995: { // 0x431995: 7403 JZ 0x0043199a
    if(integer::condition("JZ",flags)) goto L0043199a;
  }
  L00431997: { // 0x431997: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L0043199a: { // 0x43199a: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0043199d: { // 0x43199d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0043199e: { // 0x43199e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0043199f: { // 0x43199f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319a1: { // 0x4319a1: 0f8e9e000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319a7: { // 0x4319a7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319a9: { // 0x4319a9: 7c0c JL 0x004319b7
    if(integer::condition("JL",flags)) goto L004319b7;
  }
  L004319ab: { // 0x4319ab: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319ad: { // 0x4319ad: 7f08 JG 0x004319b7
    if(integer::condition("JG",flags)) goto L004319b7;
  }
  L004319af: { // 0x4319af: f6c220 TEST DL,0x20
    (void)integer::logical(((s.dx & 0xffu))&(0x00000020u),8,flags);
  }
  L004319b2: { // 0x4319b2: 7403 JZ 0x004319b7
    if(integer::condition("JZ",flags)) goto L004319b7;
  }
  L004319b4: { // 0x4319b4: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319b7: { // 0x4319b7: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319ba: { // 0x4319ba: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319bb: { // 0x4319bb: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319bc: { // 0x4319bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319be: { // 0x4319be: 0f8e81000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319c4: { // 0x4319c4: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319c6: { // 0x4319c6: 7c0c JL 0x004319d4
    if(integer::condition("JL",flags)) goto L004319d4;
  }
  L004319c8: { // 0x4319c8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319ca: { // 0x4319ca: 7f08 JG 0x004319d4
    if(integer::condition("JG",flags)) goto L004319d4;
  }
  L004319cc: { // 0x4319cc: f6c210 TEST DL,0x10
    (void)integer::logical(((s.dx & 0xffu))&(0x00000010u),8,flags);
  }
  L004319cf: { // 0x4319cf: 7403 JZ 0x004319d4
    if(integer::condition("JZ",flags)) goto L004319d4;
  }
  L004319d1: { // 0x4319d1: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319d4: { // 0x4319d4: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319d7: { // 0x4319d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319d8: { // 0x4319d8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319d9: { // 0x4319d9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319db: { // 0x4319db: 7e68 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319dd: { // 0x4319dd: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319df: { // 0x4319df: 7c0c JL 0x004319ed
    if(integer::condition("JL",flags)) goto L004319ed;
  }
  L004319e1: { // 0x4319e1: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319e3: { // 0x4319e3: 7f08 JG 0x004319ed
    if(integer::condition("JG",flags)) goto L004319ed;
  }
  L004319e5: { // 0x4319e5: f6c208 TEST DL,0x8
    (void)integer::logical(((s.dx & 0xffu))&(0x00000008u),8,flags);
  }
  L004319e8: { // 0x4319e8: 7403 JZ 0x004319ed
    if(integer::condition("JZ",flags)) goto L004319ed;
  }
  L004319ea: { // 0x4319ea: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319ed: { // 0x4319ed: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319f0: { // 0x4319f0: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319f1: { // 0x4319f1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319f2: { // 0x4319f2: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319f4: { // 0x4319f4: 7e4f JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319f6: { // 0x4319f6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319f8: { // 0x4319f8: 7c0c JL 0x00431a06
    if(integer::condition("JL",flags)) goto L00431a06;
  }
  L004319fa: { // 0x4319fa: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319fc: { // 0x4319fc: 7f08 JG 0x00431a06
    if(integer::condition("JG",flags)) goto L00431a06;
  }
  L004319fe: { // 0x4319fe: f6c204 TEST DL,0x4
    (void)integer::logical(((s.dx & 0xffu))&(0x00000004u),8,flags);
  }
  L00431a01: { // 0x431a01: 7403 JZ 0x00431a06
    if(integer::condition("JZ",flags)) goto L00431a06;
  }
  L00431a03: { // 0x431a03: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a06: { // 0x431a06: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a09: { // 0x431a09: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a0a: { // 0x431a0a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a0b: { // 0x431a0b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a0d: { // 0x431a0d: 7e36 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L00431a0f: { // 0x431a0f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431a11: { // 0x431a11: 7c0c JL 0x00431a1f
    if(integer::condition("JL",flags)) goto L00431a1f;
  }
  L00431a13: { // 0x431a13: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431a15: { // 0x431a15: 7f08 JG 0x00431a1f
    if(integer::condition("JG",flags)) goto L00431a1f;
  }
  L00431a17: { // 0x431a17: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  L00431a1a: { // 0x431a1a: 7403 JZ 0x00431a1f
    if(integer::condition("JZ",flags)) goto L00431a1f;
  }
  L00431a1c: { // 0x431a1c: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a1f: { // 0x431a1f: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a22: { // 0x431a22: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a23: { // 0x431a23: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a24: { // 0x431a24: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a26: { // 0x431a26: 7e1d JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L00431a28: { // 0x431a28: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431a2a: { // 0x431a2a: 7c0c JL 0x00431a38
    if(integer::condition("JL",flags)) goto L00431a38;
  }
  L00431a2c: { // 0x431a2c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431a2e: { // 0x431a2e: 7f08 JG 0x00431a38
    if(integer::condition("JG",flags)) goto L00431a38;
  }
  L00431a30: { // 0x431a30: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L00431a33: { // 0x431a33: 7403 JZ 0x00431a38
    if(integer::condition("JZ",flags)) goto L00431a38;
  }
  L00431a35: { // 0x431a35: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a38: { // 0x431a38: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a3b: { // 0x431a3b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a3c: { // 0x431a3c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a3d: { // 0x431a3d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a3f: { // 0x431a3f: 0f8f00ffffff JG 0x00431945
    if(integer::condition("JG",flags)) goto L00431945;
  }
  L00431a45: { // 0x431a45: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431a49: { // 0x431a49: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00431a4d: { // 0x431a4d: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00431a51: { // 0x431a51: 8b4a18 MOV ECX,dword ptr [EDX + 0x18]
    s.cx = m.r32((s.dx+0x00000018u));
  }
  L00431a54: { // 0x431a54: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00431a56: { // 0x431a56: 8b4a10 MOV ECX,dword ptr [EDX + 0x10]
    s.cx = m.r32((s.dx+0x00000010u));
  }
  L00431a59: { // 0x431a59: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00431a5d: { // 0x431a5d: 8d3448 LEA ESI,[EAX + ECX*0x2]
    s.si = (s.ax+(s.cx * 0x00000002u));
  }
  L00431a60: { // 0x431a60: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00431a64: { // 0x431a64: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431a65: { // 0x431a65: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00431a69: { // 0x431a69: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431a6d: { // 0x431a6d: 0f85c6feffff JNZ 0x00431939
    if(integer::condition("JNZ",flags)) goto L00431939;
  }
  L00431a73: { // 0x431a73: e9ec000000 JMP 0x00431b64
    goto L00431b64;
  }
  L00431a78: { // 0x431a78: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00431a7c: { // 0x431a7c: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00431a7f: { // 0x431a7f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00431a82: { // 0x431a82: 0fafce IMUL ECX,ESI
    s.cx = integer::imul(s.cx,s.si,32,flags);
  }
  L00431a85: { // 0x431a85: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00431a89: { // 0x431a89: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00431a8b: { // 0x431a8b: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00431a8d: { // 0x431a8d: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00431a8e: { // 0x431a8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431a90: { // 0x431a90: 8d2c4a LEA EBP,[EDX + ECX*0x2]
    s.bp = (s.dx+(s.cx * 0x00000002u));
  }
  L00431a93: { // 0x431a93: 0f84c7000000 JZ 0x00431b60
    if(integer::condition("JZ",flags)) goto L00431b60;
  }
  L00431a99: { // 0x431a99: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L00431a9d: { // 0x431a9d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00431a9e: { // 0x431a9e: 897c244c MOV dword ptr [ESP + 0x4c],EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L00431aa2: { // 0x431aa2: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00431aa6: { // 0x431aa6: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00431aaa: { // 0x431aaa: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00431aac: { // 0x431aac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00431aae: { // 0x431aae: 8a13 MOV DL,byte ptr [EBX]
    s.dx = with_al(s.dx, m.r8((s.bx)));
  }
  L00431ab0: { // 0x431ab0: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00431ab1: { // 0x431ab1: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00431ab3: { // 0x431ab3: 7508 JNZ 0x00431abd
    if(integer::condition("JNZ",flags)) goto L00431abd;
  }
  L00431ab5: { // 0x431ab5: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L00431ab8: { // 0x431ab8: 83e808 SUB EAX,0x8
    s.ax = integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00431abb: { // 0x431abb: eb7c JMP 0x00431b39
    goto L00431b39;
  }
  L00431abd: { // 0x431abd: f6c280 TEST DL,0x80
    (void)integer::logical(((s.dx & 0xffu))&(0x00000080u),8,flags);
  }
  L00431ac0: { // 0x431ac0: 7403 JZ 0x00431ac5
    if(integer::condition("JZ",flags)) goto L00431ac5;
  }
  L00431ac2: { // 0x431ac2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ac5: { // 0x431ac5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ac8: { // 0x431ac8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ac9: { // 0x431ac9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431acb: { // 0x431acb: 7e74 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431acd: { // 0x431acd: f6c240 TEST DL,0x40
    (void)integer::logical(((s.dx & 0xffu))&(0x00000040u),8,flags);
  }
  L00431ad0: { // 0x431ad0: 7403 JZ 0x00431ad5
    if(integer::condition("JZ",flags)) goto L00431ad5;
  }
  L00431ad2: { // 0x431ad2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ad5: { // 0x431ad5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ad8: { // 0x431ad8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ad9: { // 0x431ad9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431adb: { // 0x431adb: 7e64 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431add: { // 0x431add: f6c220 TEST DL,0x20
    (void)integer::logical(((s.dx & 0xffu))&(0x00000020u),8,flags);
  }
  L00431ae0: { // 0x431ae0: 7403 JZ 0x00431ae5
    if(integer::condition("JZ",flags)) goto L00431ae5;
  }
  L00431ae2: { // 0x431ae2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ae5: { // 0x431ae5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ae8: { // 0x431ae8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ae9: { // 0x431ae9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431aeb: { // 0x431aeb: 7e54 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431aed: { // 0x431aed: f6c210 TEST DL,0x10
    (void)integer::logical(((s.dx & 0xffu))&(0x00000010u),8,flags);
  }
  L00431af0: { // 0x431af0: 7403 JZ 0x00431af5
    if(integer::condition("JZ",flags)) goto L00431af5;
  }
  L00431af2: { // 0x431af2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431af5: { // 0x431af5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431af8: { // 0x431af8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431af9: { // 0x431af9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431afb: { // 0x431afb: 7e44 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431afd: { // 0x431afd: f6c208 TEST DL,0x8
    (void)integer::logical(((s.dx & 0xffu))&(0x00000008u),8,flags);
  }
  L00431b00: { // 0x431b00: 7403 JZ 0x00431b05
    if(integer::condition("JZ",flags)) goto L00431b05;
  }
  L00431b02: { // 0x431b02: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b05: { // 0x431b05: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b08: { // 0x431b08: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b09: { // 0x431b09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b0b: { // 0x431b0b: 7e34 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b0d: { // 0x431b0d: f6c204 TEST DL,0x4
    (void)integer::logical(((s.dx & 0xffu))&(0x00000004u),8,flags);
  }
  L00431b10: { // 0x431b10: 7403 JZ 0x00431b15
    if(integer::condition("JZ",flags)) goto L00431b15;
  }
  L00431b12: { // 0x431b12: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b15: { // 0x431b15: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b18: { // 0x431b18: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b19: { // 0x431b19: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b1b: { // 0x431b1b: 7e24 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b1d: { // 0x431b1d: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  L00431b20: { // 0x431b20: 7403 JZ 0x00431b25
    if(integer::condition("JZ",flags)) goto L00431b25;
  }
  L00431b22: { // 0x431b22: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b25: { // 0x431b25: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b28: { // 0x431b28: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b29: { // 0x431b29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b2b: { // 0x431b2b: 7e14 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b2d: { // 0x431b2d: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L00431b30: { // 0x431b30: 7403 JZ 0x00431b35
    if(integer::condition("JZ",flags)) goto L00431b35;
  }
  L00431b32: { // 0x431b32: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b35: { // 0x431b35: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b38: { // 0x431b38: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b39: { // 0x431b39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b3b: { // 0x431b3b: 0f8f6dffffff JG 0x00431aae
    if(integer::condition("JG",flags)) goto L00431aae;
  }
  L00431b41: { // 0x431b41: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00431b45: { // 0x431b45: 8b4818 MOV ECX,dword ptr [EAX + 0x18]
    s.cx = m.r32((s.ax+0x00000018u));
  }
  L00431b48: { // 0x431b48: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L00431b4a: { // 0x431b4a: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00431b4d: { // 0x431b4d: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00431b51: { // 0x431b51: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b52: { // 0x431b52: 8d6c4d00 LEA EBP,[EBP + ECX*0x2]
    s.bp = (s.bp+(s.cx * 0x00000002u));
  }
  L00431b56: { // 0x431b56: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00431b5a: { // 0x431b5a: 0f8546ffffff JNZ 0x00431aa6
    if(integer::condition("JNZ",flags)) goto L00431aa6;
  }
  L00431b60: { // 0x431b60: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431b64: { // 0x431b64: 8b422c MOV EAX,dword ptr [EDX + 0x2c]
    s.ax = m.r32((s.dx+0x0000002cu));
  }
  L00431b67: { // 0x431b67: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L00431b6b: { // 0x431b6b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00431b6f: { // 0x431b6f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431b70: { // 0x431b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00431b72: { // 0x431b72: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431b73: { // 0x431b73: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431b74: { // 0x431b74: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00431b76: { // 0x431b76: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431b77: { // 0x431b77: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00431b7a: { // 0x431b7a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00031b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431b80: { // 0x431b80: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00431b83: { // 0x431b83: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00431b87: { // 0x431b87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00431b88: { // 0x431b88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00431b89: { // 0x431b89: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431b8a: { // 0x431b8a: 668b32 MOV SI,word ptr [EDX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00431b8d: { // 0x431b8d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431b8e: { // 0x431b8e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00431b90: { // 0x431b90: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L00431b93: { // 0x431b93: 6685f6 TEST SI,SI
    (void)integer::logical(((s.si & 0xffffu))&((s.si & 0xffffu)),16,flags);
  }
  L00431b96: { // 0x431b96: 668b5f24 MOV BX,word ptr [EDI + 0x24]
    s.bx = with_ax(s.bx, m.r16((s.di+0x00000024u)));
  }
  L00431b9a: { // 0x431b9a: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00431ba2: { // 0x431ba2: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00431ba6: { // 0x431ba6: 0f844f010000 JZ 0x00431cfb
    if(integer::condition("JZ",flags)) goto L00431cfb;
  }
  L00431bac: { // 0x431bac: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431bb0: { // 0x431bb0: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L00431bb3: { // 0x431bb3: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431bb7: { // 0x431bb7: b809000000 MOV EAX,0x9
    s.ax = 0x00000009u;
  }
  L00431bbc: { // 0x431bbc: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00431bbe: { // 0x431bbe: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00431bc0: { // 0x431bc0: c1e505 SHL EBP,0x5
    s.bp = integer::shift(s.bp,0x00000005u,32,flags,integer::Shift::left);
  }
  L00431bc3: { // 0x431bc3: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L00431bc5: { // 0x431bc5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431bc7: { // 0x431bc7: 0f84e0000000 JZ 0x00431cad
    if(integer::condition("JZ",flags)) goto L00431cad;
  }
  L00431bcd: { // 0x431bcd: 394c2418 CMP dword ptr [ESP + 0x18],ECX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.cx,32,flags);
  }
  L00431bd1: { // 0x431bd1: 0f8d36010000 JGE 0x00431d0d
    if(integer::condition("JGE",flags)) goto L00431d0d;
  }
  L00431bd7: { // 0x431bd7: 837c241c08 CMP dword ptr [ESP + 0x1c],0x8
    (void)integer::sub(m.r32((f.sp+0x0000001cu)),0x00000008u,32,flags);
  }
  L00431bdc: { // 0x431bdc: 0f8db6000000 JGE 0x00431c98
    if(integer::condition("JGE",flags)) goto L00431c98;
  }
  L00431be2: { // 0x431be2: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L00431be9: { // 0x431be9: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00431beb: { // 0x431beb: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431bee: { // 0x431bee: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L00431bf4: { // 0x431bf4: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00431bf6: { // 0x431bf6: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  L00431bfb: { // 0x431bfb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00431bfc: { // 0x431bfc: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431bfe: { // 0x431bfe: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L00431c05: { // 0x431c05: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431c08: { // 0x431c08: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L00431c0e: { // 0x431c0e: 88542418 MOV byte ptr [ESP + 0x18],DL
    m.w8((f.sp+0x00000018u), (s.dx & 0xffu));
  }
  L00431c12: { // 0x431c12: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431c14: { // 0x431c14: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L00431c1b: { // 0x431c1b: 88442419 MOV byte ptr [ESP + 0x19],AL
    m.w8((f.sp+0x00000019u), (s.ax & 0xffu));
  }
  L00431c1f: { // 0x431c1f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00431c21: { // 0x431c21: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431c24: { // 0x431c24: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L00431c2a: { // 0x431c2a: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431c2c: { // 0x431c2c: 668b4c2418 MOV CX,word ptr [ESP + 0x18]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000018u)));
  }
  L00431c31: { // 0x431c31: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00431c36: { // 0x431c36: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00431c3a: { // 0x431c3a: 8844241e MOV byte ptr [ESP + 0x1e],AL
    m.w8((f.sp+0x0000001eu), (s.ax & 0xffu));
  }
  L00431c3e: { // 0x431c3e: e8cd262000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,4398147u,op); flags=s.arithmetic_flags;
  }
  L00431c43: { // 0x431c43: 8a542415 MOV DL,byte ptr [ESP + 0x15]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000015u)));
  }
  L00431c47: { // 0x431c47: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L00431c4d: { // 0x431c4d: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c4f: { // 0x431c4f: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L00431c55: { // 0x431c55: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  L00431c58: { // 0x431c58: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L00431c5a: { // 0x431c5a: 8a542416 MOV DL,byte ptr [ESP + 0x16]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000016u)));
  }
  L00431c5e: { // 0x431c5e: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c60: { // 0x431c60: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L00431c66: { // 0x431c66: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c68: { // 0x431c68: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L00431c6e: { // 0x431c6e: 660fb6d2 MOVZX DX,DL
    s.dx = with_ax(s.dx, ((s.dx & 0xffu)&integer::mask(8)));
  }
  L00431c72: { // 0x431c72: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c74: { // 0x431c74: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00431c7a: { // 0x431c7a: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00431c7c: { // 0x431c7c: 8a542414 MOV DL,byte ptr [ESP + 0x14]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000014u)));
  }
  L00431c80: { // 0x431c80: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c82: { // 0x431c82: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00431c88: { // 0x431c88: 660fb6d2 MOVZX DX,DL
    s.dx = with_ax(s.dx, ((s.dx & 0xffu)&integer::mask(8)));
  }
  L00431c8c: { // 0x431c8c: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c8e: { // 0x431c8e: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431c92: { // 0x431c92: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00431c94: { // 0x431c94: 66894724 MOV word ptr [EDI + 0x24],AX
    m.w16((s.di+0x00000024u), (s.ax & 0xffffu));
  }
  L00431c98: { // 0x431c98: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00431c9c: { // 0x431c9c: 83c51f ADD EBP,0x1f
    s.bp = integer::add(s.bp,0x0000001fu,32,flags);
  }
  L00431c9f: { // 0x431c9f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431ca0: { // 0x431ca0: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00431ca4: { // 0x431ca4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00431ca8: { // 0x431ca8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ca9: { // 0x431ca9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431cad: { // 0x431cad: 6683fe0d CMP SI,0xd
    (void)integer::sub((s.si & 0xffffu),0x0000000du,16,flags);
  }
  L00431cb1: { // 0x431cb1: 7422 JZ 0x00431cd5
    if(integer::condition("JZ",flags)) goto L00431cd5;
  }
  L00431cb3: { // 0x431cb3: 6683fe0a CMP SI,0xa
    (void)integer::sub((s.si & 0xffffu),0x0000000au,16,flags);
  }
  L00431cb7: { // 0x431cb7: 741c JZ 0x00431cd5
    if(integer::condition("JZ",flags)) goto L00431cd5;
  }
  L00431cb9: { // 0x431cb9: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00431cbd: { // 0x431cbd: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00431cc1: { // 0x431cc1: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00431cc3: { // 0x431cc3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431cc4: { // 0x431cc4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431cc5: { // 0x431cc5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431cc6: { // 0x431cc6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431cc8: { // 0x431cc8: e8d3faffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,4398285u,op); flags=s.arithmetic_flags;
  }
  L00431ccd: { // 0x431ccd: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431cd1: { // 0x431cd1: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00431cd5: { // 0x431cd5: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00431cd9: { // 0x431cd9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431cdb: { // 0x431cdb: 7407 JZ 0x00431ce4
    if(integer::condition("JZ",flags)) goto L00431ce4;
  }
  L00431cdd: { // 0x431cdd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431cde: { // 0x431cde: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00431ce2: { // 0x431ce2: 7417 JZ 0x00431cfb
    if(integer::condition("JZ",flags)) goto L00431cfb;
  }
  L00431ce4: { // 0x431ce4: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00431ce8: { // 0x431ce8: 668b32 MOV SI,word ptr [EDX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00431ceb: { // 0x431ceb: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L00431cee: { // 0x431cee: 6685f6 TEST SI,SI
    (void)integer::logical(((s.si & 0xffffu))&((s.si & 0xffffu)),16,flags);
  }
  L00431cf1: { // 0x431cf1: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00431cf5: { // 0x431cf5: 0f85cafeffff JNZ 0x00431bc5
    if(integer::condition("JNZ",flags)) goto L00431bc5;
  }
  L00431cfb: { // 0x431cfb: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00431cff: { // 0x431cff: 66895f24 MOV word ptr [EDI + 0x24],BX
    m.w16((s.di+0x00000024u), (s.bx & 0xffffu));
  }
  L00431d03: { // 0x431d03: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431d04: { // 0x431d04: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431d05: { // 0x431d05: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431d06: { // 0x431d06: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431d07: { // 0x431d07: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431d0a: { // 0x431d0a: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00431d0d: { // 0x431d0d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00431d0f: { // 0x431d0f: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00431d13: { // 0x431d13: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00431d15: { // 0x431d15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431d16: { // 0x431d16: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00431d17: { // 0x431d17: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431d19: { // 0x431d19: 66895f24 MOV word ptr [EDI + 0x24],BX
    m.w16((s.di+0x00000024u), (s.bx & 0xffffu));
  }
  L00431d1d: { // 0x431d1d: e84ef6ffff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,4398370u,op); flags=s.arithmetic_flags;
  }
  L00431d22: { // 0x431d22: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00431d26: { // 0x431d26: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00431d2a: { // 0x431d2a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431d2b: { // 0x431d2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431d2c: { // 0x431d2c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431d2d: { // 0x431d2d: 8d0411 LEA EAX,[ECX + EDX*0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u));
  }
  L00431d30: { // 0x431d30: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431d31: { // 0x431d31: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431d34: { // 0x431d34: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}

void f_00031ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431ec0: { // 0x431ec0: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00431ec4: { // 0x431ec4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00431ec8: { // 0x431ec8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431ec9: { // 0x431ec9: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00431ecc: { // 0x431ecc: 8b720c MOV ESI,dword ptr [EDX + 0xc]
    s.si = m.r32((s.dx+0x0000000cu));
  }
  L00431ecf: { // 0x431ecf: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ed1: { // 0x431ed1: 7f6f JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ed3: { // 0x431ed3: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00431ed6: { // 0x431ed6: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  L00431ed9: { // 0x431ed9: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431edb: { // 0x431edb: 7f65 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431edd: { // 0x431edd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00431edf: { // 0x431edf: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L00431ee2: { // 0x431ee2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ee4: { // 0x431ee4: 7f5c JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ee6: { // 0x431ee6: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00431ee8: { // 0x431ee8: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00431eeb: { // 0x431eeb: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431eed: { // 0x431eed: 7f53 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431eef: { // 0x431eef: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431ef3: { // 0x431ef3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431ef4: { // 0x431ef4: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431ef6: { // 0x431ef6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00431ef8: { // 0x431ef8: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L00431efa: { // 0x431efa: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L00431efd: { // 0x431efd: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L00431f00: { // 0x431f00: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00431f03: { // 0x431f03: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00431f06: { // 0x431f06: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00431f09: { // 0x431f09: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431f0a: { // 0x431f0a: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00431f0d: { // 0x431f0d: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00431f10: { // 0x431f10: 394804 CMP dword ptr [EAX + 0x4],ECX
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.cx,32,flags);
  }
  L00431f13: { // 0x431f13: 7d03 JGE 0x00431f18
    if(integer::condition("JGE",flags)) goto L00431f18;
  }
  L00431f15: { // 0x431f15: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00431f18: { // 0x431f18: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00431f1a: { // 0x431f1a: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00431f1c: { // 0x431f1c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f1e: { // 0x431f1e: 7d02 JGE 0x00431f22
    if(integer::condition("JGE",flags)) goto L00431f22;
  }
  L00431f20: { // 0x431f20: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00431f22: { // 0x431f22: 8b4a0c MOV ECX,dword ptr [EDX + 0xc]
    s.cx = m.r32((s.dx+0x0000000cu));
  }
  L00431f25: { // 0x431f25: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  L00431f28: { // 0x431f28: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f2a: { // 0x431f2a: 7e03 JLE 0x00431f2f
    if(integer::condition("JLE",flags)) goto L00431f2f;
  }
  L00431f2c: { // 0x431f2c: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f2f: { // 0x431f2f: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L00431f32: { // 0x431f32: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00431f35: { // 0x431f35: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00431f37: { // 0x431f37: 7e03 JLE 0x00431f3c
    if(integer::condition("JLE",flags)) goto L00431f3c;
  }
  L00431f39: { // 0x431f39: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00431f3c: { // 0x431f3c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00431f3e: { // 0x431f3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f3f: { // 0x431f3f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00431f42: { // 0x431f42: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431f46: { // 0x431f46: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L00431f49: { // 0x431f49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f4a: { // 0x431f4a: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00431f50: { // 0x431f50: c7400400000000 MOV dword ptr [EAX + 0x4],0x0
    m.w32((s.ax+0x00000004u), 0x00000000u);
  }
  L00431f57: { // 0x431f57: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00431f5a: { // 0x431f5a: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f5d: { // 0x431f5d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00431f5f: { // 0x431f5f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_00031f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431f70: { // 0x431f70: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00431f73: { // 0x431f73: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431f74: { // 0x431f74: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431f75: { // 0x431f75: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L00431f79: { // 0x431f79: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00431f7b: { // 0x431f7b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00431f7d: { // 0x431f7d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00431f7f: { // 0x431f7f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f81: { // 0x431f81: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431f82: { // 0x431f82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431f83: { // 0x431f83: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f85: { // 0x431f85: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4398984u,op); flags=s.arithmetic_flags;
  }
  L00431f88: { // 0x431f88: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00431f8b: { // 0x431f8b: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431f8d: { // 0x431f8d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f8f: { // 0x431f8f: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4398994u,op); flags=s.arithmetic_flags;
  }
  L00431f92: { // 0x431f92: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00431f94: { // 0x431f94: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00431f97: { // 0x431f97: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f99: { // 0x431f99: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f9b: { // 0x431f9b: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L00431fa3: { // 0x431fa3: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L00431fab: { // 0x431fab: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4399022u,op); flags=s.arithmetic_flags;
  }
  L00431fae: { // 0x431fae: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431faf: { // 0x431faf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431fb1: { // 0x431fb1: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431fb5: { // 0x431fb5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431fb7: { // 0x431fb7: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4399037u,op); flags=s.arithmetic_flags;
  }
  L00431fbd: { // 0x431fbd: 8b5638 MOV EDX,dword ptr [ESI + 0x38]
    s.dx = m.r32((s.si+0x00000038u));
  }
  L00431fc0: { // 0x431fc0: 8b7e3c MOV EDI,dword ptr [ESI + 0x3c]
    s.di = m.r32((s.si+0x0000003cu));
  }
  L00431fc3: { // 0x431fc3: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fc5: { // 0x431fc5: 8b7e34 MOV EDI,dword ptr [ESI + 0x34]
    s.di = m.r32((s.si+0x00000034u));
  }
  L00431fc8: { // 0x431fc8: 8d4e30 LEA ECX,[ESI + 0x30]
    s.cx = (s.si+0x00000030u);
  }
  L00431fcb: { // 0x431fcb: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fcd: { // 0x431fcd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431fce: { // 0x431fce: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431fd0: { // 0x431fd0: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00431fd4: { // 0x431fd4: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fd6: { // 0x431fd6: 751f JNZ 0x00431ff7
    if(integer::condition("JNZ",flags)) goto L00431ff7;
  }
  L00431fd8: { // 0x431fd8: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00431fdc: { // 0x431fdc: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  L00431fdf: { // 0x431fdf: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00431fe1: { // 0x431fe1: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00431fe5: { // 0x431fe5: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431fe9: { // 0x431fe9: 894e34 MOV dword ptr [ESI + 0x34],ECX
    m.w32((s.si+0x00000034u), s.cx);
  }
  L00431fec: { // 0x431fec: 895638 MOV dword ptr [ESI + 0x38],EDX
    m.w32((s.si+0x00000038u), s.dx);
  }
  L00431fef: { // 0x431fef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431ff0: { // 0x431ff0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431ff1: { // 0x431ff1: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431ff4: { // 0x431ff4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00431ff7: { // 0x431ff7: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L00431ffb: { // 0x431ffb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431ffc: { // 0x431ffc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffd: { // 0x431ffd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffe: { // 0x431ffe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432000: { // 0x432000: e8bbfeffff CALL 0x00431ec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431ec0u,4399109u,op); flags=s.arithmetic_flags;
  }
  L00432005: { // 0x432005: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432006: { // 0x432006: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432007: { // 0x432007: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0043200a: { // 0x43200a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00032010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00432010: { // 0x00432010: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00432011: { // 0x00432011: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00432013: { // 0x00432013: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00432017: { // 0x00432017: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00432019: { // 0x00432019: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4399132u,op); flags=s.arithmetic_flags;
  }
  L0043201c: { // 0x0043201c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043201e: { // 0x0043201e: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00432021: { // 0x00432021: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00432024: { // 0x00432024: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432025: { // 0x00432025: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00032210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00432210: { // 0x432210: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00432211: { // 0x432211: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00432215: { // 0x432215: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00432216: { // 0x432216: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L0043221a: { // 0x43221a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0043221c: { // 0x43221c: 7443 JZ 0x00432261
    if(integer::condition("JZ",flags)) goto L00432261;
  }
  L0043221e: { // 0x43221e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0043221f: { // 0x43221f: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00432223: { // 0x432223: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00432224: { // 0x432224: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432226: { // 0x432226: e845fdffff CALL 0x00431f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431f70u,4399659u,op); flags=s.arithmetic_flags;
  }
  L0043222b: { // 0x43222b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043222c: { // 0x43222c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043222e: { // 0x43222e: e85df5ffff CALL 0x00431790
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431790u,4399667u,op); flags=s.arithmetic_flags;
  }
  L00432233: { // 0x432233: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00432237: { // 0x432237: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0043223b: { // 0x43223b: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0043223f: { // 0x43223f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432240: { // 0x432240: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00432244: { // 0x432244: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00432245: { // 0x432245: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00432246: { // 0x432246: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00432247: { // 0x432247: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432248: { // 0x432248: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043224a: { // 0x43224a: e831f9ffff CALL 0x00431b80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431b80u,4399695u,op); flags=s.arithmetic_flags;
  }
  L0043224f: { // 0x43224f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00432250: { // 0x432250: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432252: { // 0x432252: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00432254: { // 0x432254: e8b7fdffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,4399705u,op); flags=s.arithmetic_flags;
  }
  L00432259: { // 0x432259: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0043225b: { // 0x43225b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043225c: { // 0x43225c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043225d: { // 0x43225d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043225e: { // 0x43225e: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L00432261: { // 0x432261: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00432263: { // 0x432263: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432264: { // 0x432264: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432265: { // 0x432265: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00097830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00497830: { // 0x497830: a1306d8300 MOV EAX,[0x00836d30]
    s.ax = m.r32((0x00836d30u));
  }
  L00497835: { // 0x497835: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0025ace0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065ace0: { // 0x65ace0: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  L0065ace5: { // 0x65ace5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0065ace6: { // 0x65ace6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0065ace7: { // 0x65ace7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0065ace9: { // 0x65ace9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0065acea: { // 0x65acea: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0065acec: { // 0x65acec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0065acee: { // 0x65acee: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0065acf0: { // 0x65acf0: 7e37 JLE 0x0065ad29
    if(integer::condition("JLE",flags)) goto L0065ad29;
  }
  L0065acf2: { // 0x65acf2: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  L0065acf7: { // 0x65acf7: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0065acfa: { // 0x65acfa: 8b8804030000 MOV ECX,dword ptr [EAX + 0x304]
    s.cx = m.r32((s.ax+0x00000304u));
  }
  L0065ad00: { // 0x65ad00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065ad01: { // 0x65ad01: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0065ad02: { // 0x65ad02: e8592b1100 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,6663431u,op); flags=s.arithmetic_flags;
  }
  L0065ad07: { // 0x65ad07: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0065ad0a: { // 0x65ad0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0065ad0c: { // 0x65ad0c: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  L0065ad11: { // 0x65ad11: 750b JNZ 0x0065ad1e
    if(integer::condition("JNZ",flags)) goto L0065ad1e;
  }
  L0065ad13: { // 0x65ad13: 8b14b0 MOV EDX,dword ptr [EAX + ESI*0x4]
    s.dx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0065ad16: { // 0x65ad16: 39ba10030000 CMP dword ptr [EDX + 0x310],EDI
    (void)integer::sub(m.r32((s.dx+0x00000310u)),s.di,32,flags);
  }
  L0065ad1c: { // 0x65ad1c: 7411 JZ 0x0065ad2f
    if(integer::condition("JZ",flags)) goto L0065ad2f;
  }
  L0065ad1e: { // 0x65ad1e: 8b0d10eaa900 MOV ECX,dword ptr [0x00a9ea10]
    s.cx = m.r32((0x00a9ea10u));
  }
  L0065ad24: { // 0x65ad24: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0065ad25: { // 0x65ad25: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0065ad27: { // 0x65ad27: 7cce JL 0x0065acf7
    if(integer::condition("JL",flags)) goto L0065acf7;
  }
  L0065ad29: { // 0x65ad29: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065ad2a: { // 0x65ad2a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065ad2b: { // 0x65ad2b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0065ad2d: { // 0x65ad2d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0065ad2e: { // 0x65ad2e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0065ad2f: { // 0x65ad2f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0065ad31: { // 0x65ad31: 7cf6 JL 0x0065ad29
    if(integer::condition("JL",flags)) goto L0065ad29;
  }
  L0065ad33: { // 0x65ad33: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0065ad36: { // 0x65ad36: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065ad37: { // 0x65ad37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065ad38: { // 0x65ad38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0065ad39: { // 0x65ad39: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000fe550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004fe550: { // 0x4fe550: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L004fe553: { // 0x4fe553: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004fe555: { // 0x4fe555: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004fe556: { // 0x4fe556: 8a4102 MOV AL,byte ptr [ECX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000002u)));
  }
  L004fe559: { // 0x4fe559: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004fe55a: { // 0x4fe55a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004fe55b: { // 0x4fe55b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004fe55d: { // 0x4fe55d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004fe55f: { // 0x4fe55f: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004fe561: { // 0x4fe561: 8a01 MOV AL,byte ptr [ECX]
    s.ax = with_al(s.ax, m.r8((s.cx)));
  }
  L004fe563: { // 0x4fe563: 8a5901 MOV BL,byte ptr [ECX + 0x1]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000001u)));
  }
  L004fe566: { // 0x4fe566: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004fe567: { // 0x4fe567: bfff000000 MOV EDI,0xff
    s.di = 0x000000ffu;
  }
  L004fe56c: { // 0x4fe56c: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L004fe56f: { // 0x4fe56f: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L004fe573: { // 0x4fe573: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L004fe575: { // 0x4fe575: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004fe577: { // 0x4fe577: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L004fe57b: { // 0x4fe57b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004fe57c: { // 0x4fe57c: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004fe57e: { // 0x4fe57e: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe583: { // 0x4fe583: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L004fe585: { // 0x4fe585: 0fafd3 IMUL EDX,EBX
    s.dx = integer::imul(s.dx,s.bx,32,flags);
  }
  L004fe588: { // 0x4fe588: f7e2 MUL EDX
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.dx);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe58a: { // 0x4fe58a: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe58d: { // 0x4fe58d: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L004fe58f: { // 0x4fe58f: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe594: { // 0x4fe594: 0faffe IMUL EDI,ESI
    s.di = integer::imul(s.di,s.si,32,flags);
  }
  L004fe597: { // 0x4fe597: f7e7 MUL EDI
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.di);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe599: { // 0x4fe599: bfff000000 MOV EDI,0xff
    s.di = 0x000000ffu;
  }
  L004fe59e: { // 0x4fe59e: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5a3: { // 0x4fe5a3: 2bfb SUB EDI,EBX
    s.di = integer::sub(s.di,s.bx,32,flags);
  }
  L004fe5a5: { // 0x4fe5a5: 0faffe IMUL EDI,ESI
    s.di = integer::imul(s.di,s.si,32,flags);
  }
  L004fe5a8: { // 0x4fe5a8: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe5ab: { // 0x4fe5ab: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L004fe5af: { // 0x4fe5af: f7ef IMUL EDI
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.di,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L004fe5b1: { // 0x4fe5b1: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L004fe5b3: { // 0x4fe5b3: bfff000000 MOV EDI,0xff
    s.di = 0x000000ffu;
  }
  L004fe5b8: { // 0x4fe5b8: c1fa07 SAR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004fe5bb: { // 0x4fe5bb: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004fe5bd: { // 0x4fe5bd: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L004fe5c0: { // 0x4fe5c0: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004fe5c2: { // 0x4fe5c2: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5c7: { // 0x4fe5c7: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L004fe5cb: { // 0x4fe5cb: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L004fe5cf: { // 0x4fe5cf: baff000000 MOV EDX,0xff
    s.dx = 0x000000ffu;
  }
  L004fe5d4: { // 0x4fe5d4: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L004fe5d6: { // 0x4fe5d6: 0fafd3 IMUL EDX,EBX
    s.dx = integer::imul(s.dx,s.bx,32,flags);
  }
  L004fe5d9: { // 0x4fe5d9: f7e2 MUL EDX
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.dx);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe5db: { // 0x4fe5db: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe5de: { // 0x4fe5de: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L004fe5e0: { // 0x4fe5e0: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5e5: { // 0x4fe5e5: 0faffe IMUL EDI,ESI
    s.di = integer::imul(s.di,s.si,32,flags);
  }
  L004fe5e8: { // 0x4fe5e8: f7e7 MUL EDI
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.di);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe5ea: { // 0x4fe5ea: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe5ed: { // 0x4fe5ed: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5f2: { // 0x4fe5f2: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L004fe5f6: { // 0x4fe5f6: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L004fe5f8: { // 0x4fe5f8: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004fe5fa: { // 0x4fe5fa: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  L004fe5ff: { // 0x4fe5ff: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004fe601: { // 0x4fe601: c1f807 SAR EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004fe604: { // 0x4fe604: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004fe606: { // 0x4fe606: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L004fe609: { // 0x4fe609: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004fe60b: { // 0x4fe60b: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004fe60d: { // 0x4fe60d: 1bc9 SBB ECX,ECX
    s.cx = integer::sub(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  L004fe60f: { // 0x4fe60f: 83e1fa AND ECX,0xfffffffa
    s.cx = integer::logical((s.cx)&(0xfffffffau),32,flags);
  }
  L004fe612: { // 0x4fe612: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004fe615: { // 0x4fe615: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004fe617: { // 0x4fe617: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004fe619: { // 0x4fe619: 8b4c8414 MOV ECX,dword ptr [ESP + EAX*0x4 + 0x14]
    s.cx = m.r32((f.sp+(s.ax * 0x00000004u)+0x00000014u));
  }
  L004fe61d: { // 0x4fe61d: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L004fe61f: { // 0x4fe61f: 884c2410 MOV byte ptr [ESP + 0x10],CL
    m.w8((f.sp+0x00000010u), (s.cx & 0xffu));
  }
  L004fe623: { // 0x4fe623: 83e2fa AND EDX,0xfffffffa
    s.dx = integer::logical((s.dx)&(0xfffffffau),32,flags);
  }
  L004fe626: { // 0x4fe626: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004fe62b: { // 0x4fe62b: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L004fe62e: { // 0x4fe62e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004fe630: { // 0x4fe630: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004fe632: { // 0x4fe632: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L004fe634: { // 0x4fe634: 83e2fa AND EDX,0xfffffffa
    s.dx = integer::logical((s.dx)&(0xfffffffau),32,flags);
  }
  L004fe637: { // 0x4fe637: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L004fe63a: { // 0x4fe63a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004fe63c: { // 0x4fe63c: 8a448414 MOV AL,byte ptr [ESP + EAX*0x4 + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+(s.ax * 0x00000004u)+0x00000014u)));
  }
  L004fe640: { // 0x4fe640: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004fe641: { // 0x4fe641: 8a4c9410 MOV CL,byte ptr [ESP + EDX*0x4 + 0x10]
    s.cx = with_al(s.cx, m.r8((f.sp+(s.dx * 0x00000004u)+0x00000010u)));
  }
  L004fe645: { // 0x4fe645: 884c240d MOV byte ptr [ESP + 0xd],CL
    m.w8((f.sp+0x0000000du), (s.cx & 0xffu));
  }
  L004fe649: { // 0x4fe649: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L004fe64d: { // 0x4fe64d: 668b74240c MOV SI,word ptr [ESP + 0xc]
    s.si = (s.si & 0xffff0000u) | ((m.r16((f.sp+0x0000000cu))) & 0xffffu);
  }
  L004fe652: { // 0x4fe652: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L004fe654: { // 0x4fe654: 668932 MOV word ptr [EDX],SI
    m.w16((s.dx), (s.si & 0xffffu));
  }
  L004fe657: { // 0x4fe657: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004fe658: { // 0x4fe658: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004fe659: { // 0x4fe659: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004fe65a: { // 0x4fe65a: 884202 MOV byte ptr [EDX + 0x2],AL
    m.w8((s.dx+0x00000002u), (s.ax & 0xffu));
  }
  L004fe65d: { // 0x4fe65d: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004fe65f: { // 0x4fe65f: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L004fe662: { // 0x4fe662: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00360ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760ad0: { // 0x760ad0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00760ad3: { // 0x760ad3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760ad4: { // 0x760ad4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760ad5: { // 0x760ad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760ad6: { // 0x760ad6: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00760ada: { // 0x760ada: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00760adc: { // 0x760adc: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760adf: { // 0x760adf: 394e08 CMP dword ptr [ESI + 0x8],ECX
    (void)integer::sub(m.r32((s.si+0x00000008u)),s.cx,32,flags);
  }
  L00760ae2: { // 0x760ae2: 0f852e010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760ae8: { // 0x760ae8: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760aeb: { // 0x760aeb: 8b5f0c MOV EBX,dword ptr [EDI + 0xc]
    s.bx = m.r32((s.di+0x0000000cu));
  }
  L00760aee: { // 0x760aee: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760af0: { // 0x760af0: 0f8520010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760af6: { // 0x760af6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760af8: { // 0x760af8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760afa: { // 0x760afa: 7d1d JGE 0x00760b19
    if(integer::condition("JGE",flags)) goto L00760b19;
  }
  L00760afc: { // 0x760afc: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760afe: { // 0x760afe: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b00: { // 0x760b00: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L00760b02: { // 0x760b02: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b04: { // 0x760b04: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b06: { // 0x760b06: 894708 MOV dword ptr [EDI + 0x8],EAX
    m.w32((s.di+0x00000008u), s.ax);
  }
  L00760b09: { // 0x760b09: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00760b0b: { // 0x760b0b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760b0e: { // 0x760b0e: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L00760b14: { // 0x760b14: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b16: { // 0x760b16: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00760b19: { // 0x760b19: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b1c: { // 0x760b1c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b1e: { // 0x760b1e: 7d25 JGE 0x00760b45
    if(integer::condition("JGE",flags)) goto L00760b45;
  }
  L00760b20: { // 0x760b20: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L00760b23: { // 0x760b23: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760b26: { // 0x760b26: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b28: { // 0x760b28: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00760b2b: { // 0x760b2b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b2e: { // 0x760b2e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760b30: { // 0x760b30: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760b33: { // 0x760b33: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00760b36: { // 0x760b36: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b39: { // 0x760b39: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00760b40: { // 0x760b40: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b42: { // 0x760b42: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00760b45: { // 0x760b45: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b47: { // 0x760b47: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L00760b4a: { // 0x760b4a: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L00760b4d: { // 0x760b4d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00760b4f: { // 0x760b4f: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760b51: { // 0x760b51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b53: { // 0x760b53: 7e10 JLE 0x00760b65
    if(integer::condition("JLE",flags)) goto L00760b65;
  }
  L00760b55: { // 0x760b55: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L00760b58: { // 0x760b58: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b5a: { // 0x760b5a: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L00760b5d: { // 0x760b5d: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b60: { // 0x760b60: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b62: { // 0x760b62: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760b65: { // 0x760b65: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b68: { // 0x760b68: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760b6b: { // 0x760b6b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00760b6e: { // 0x760b6e: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760b70: { // 0x760b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00760b72: { // 0x760b72: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b74: { // 0x760b74: 7e10 JLE 0x00760b86
    if(integer::condition("JLE",flags)) goto L00760b86;
  }
  L00760b76: { // 0x760b76: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760b79: { // 0x760b79: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00760b7b: { // 0x760b7b: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760b7e: { // 0x760b7e: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760b81: { // 0x760b81: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b83: { // 0x760b83: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760b86: { // 0x760b86: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b88: { // 0x760b88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b8a: { // 0x760b8a: 7d1e JGE 0x00760baa
    if(integer::condition("JGE",flags)) goto L00760baa;
  }
  L00760b8c: { // 0x760b8c: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L00760b8e: { // 0x760b8e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b90: { // 0x760b90: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L00760b92: { // 0x760b92: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b94: { // 0x760b94: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00760b97: { // 0x760b97: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760b99: { // 0x760b99: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00760b9c: { // 0x760b9c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b9f: { // 0x760b9f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760ba1: { // 0x760ba1: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760ba4: { // 0x760ba4: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L00760baa: { // 0x760baa: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bad: { // 0x760bad: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760baf: { // 0x760baf: 7d22 JGE 0x00760bd3
    if(integer::condition("JGE",flags)) goto L00760bd3;
  }
  L00760bb1: { // 0x760bb1: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L00760bb4: { // 0x760bb4: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760bb6: { // 0x760bb6: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00760bb9: { // 0x760bb9: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bbc: { // 0x760bbc: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760bbf: { // 0x760bbf: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760bc1: { // 0x760bc1: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760bc4: { // 0x760bc4: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760bc7: { // 0x760bc7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760bc9: { // 0x760bc9: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760bcc: { // 0x760bcc: c7470400000000 MOV dword ptr [EDI + 0x4],0x0
    m.w32((s.di+0x00000004u), 0x00000000u);
  }
  L00760bd3: { // 0x760bd3: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00760bd7: { // 0x760bd7: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760bda: { // 0x760bda: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00760bdc: { // 0x760bdc: 8b5a08 MOV EBX,dword ptr [EDX + 0x8]
    s.bx = m.r32((s.dx+0x00000008u));
  }
  L00760bdf: { // 0x760bdf: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760be1: { // 0x760be1: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760be3: { // 0x760be3: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760be5: { // 0x760be5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760be7: { // 0x760be7: 7e0d JLE 0x00760bf6
    if(integer::condition("JLE",flags)) goto L00760bf6;
  }
  L00760be9: { // 0x760be9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760beb: { // 0x760beb: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  L00760bee: { // 0x760bee: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760bf1: { // 0x760bf1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760bf3: { // 0x760bf3: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760bf6: { // 0x760bf6: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bf9: { // 0x760bf9: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760bfc: { // 0x760bfc: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760bff: { // 0x760bff: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760c01: { // 0x760c01: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760c03: { // 0x760c03: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c05: { // 0x760c05: 7e63 JLE 0x00760c6a
    if(integer::condition("JLE",flags)) goto L00760c6a;
  }
  L00760c07: { // 0x760c07: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c09: { // 0x760c09: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760c0c: { // 0x760c0c: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760c0f: { // 0x760c0f: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c11: { // 0x760c11: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760c14: { // 0x760c14: eb54 JMP 0x00760c6a
    goto L00760c6a;
  }
  L00760c16: { // 0x760c16: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c18: { // 0x760c18: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c1a: { // 0x760c1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760c1b: { // 0x760c1b: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c1d: { // 0x760c1d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c21: { // 0x760c21: e8caf1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736358u,op); flags=s.arithmetic_flags;
  }
  L00760c26: { // 0x760c26: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c28: { // 0x760c28: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c2a: { // 0x760c2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2c: { // 0x760c2c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2e: { // 0x760c2e: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c30: { // 0x760c30: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c33: { // 0x760c33: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c36: { // 0x760c36: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c39: { // 0x760c39: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c3c: { // 0x760c3c: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c3f: { // 0x760c3f: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00760c43: { // 0x760c43: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c46: { // 0x760c46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760c47: { // 0x760c47: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c49: { // 0x760c49: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c4d: { // 0x760c4d: e89ef1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736402u,op); flags=s.arithmetic_flags;
  }
  L00760c52: { // 0x760c52: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c54: { // 0x760c54: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c56: { // 0x760c56: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c58: { // 0x760c58: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c5b: { // 0x760c5b: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c5e: { // 0x760c5e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c61: { // 0x760c61: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c64: { // 0x760c64: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c67: { // 0x760c67: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c6a: { // 0x760c6a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760c6d: { // 0x760c6d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c6f: { // 0x760c6f: 7e23 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c71: { // 0x760c71: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760c74: { // 0x760c74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c76: { // 0x760c76: 7e1c JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c78: { // 0x760c78: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760c7b: { // 0x760c7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c7d: { // 0x760c7d: 7e15 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c7f: { // 0x760c7f: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760c82: { // 0x760c82: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c84: { // 0x760c84: 7e0e JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c86: { // 0x760c86: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c87: { // 0x760c87: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c88: { // 0x760c88: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00760c8d: { // 0x760c8d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c8e: { // 0x760c8e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c91: { // 0x760c91: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00760c94: { // 0x760c94: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c95: { // 0x760c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c96: { // 0x760c96: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00760c98: { // 0x760c98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c99: { // 0x760c99: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c9c: { // 0x760c9c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00035420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435420: { // 0x435420: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00435424: { // 0x435424: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00435426: { // 0x435426: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00435429: { // 0x435429: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0043542b: { // 0x43542b: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0043542e: { // 0x43542e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00035400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435400: { // 0x435400: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435404: { // 0x435404: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435405: { // 0x435405: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00435407: { // 0x435407: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00435409: { // 0x435409: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0043540b: { // 0x43540b: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0043540e: { // 0x43540e: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00435411: { // 0x435411: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00435413: { // 0x435413: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435417: { // 0x435417: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00435419: { // 0x435419: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L0043541c: { // 0x43541c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043541d: { // 0x43541d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00011290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411290: { // 0x411290: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00411294: { // 0x411294: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411295: { // 0x411295: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411296: { // 0x411296: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411297: { // 0x411297: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0041129a: { // 0x41129a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L0041129d: { // 0x41129d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0041129f: { // 0x41129f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004112a1: { // 0x4112a1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004112a3: { // 0x4112a3: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L004112a5: { // 0x4112a5: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L004112a8: { // 0x4112a8: 897b08 MOV dword ptr [EBX + 0x8],EDI
    m.w32((s.bx+0x00000008u), s.di);
  }
  L004112ab: { // 0x4112ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004112ac: { // 0x4112ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004112ad: { // 0x4112ad: 894b0c MOV dword ptr [EBX + 0xc],ECX
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L004112b0: { // 0x4112b0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004112b1: { // 0x4112b1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0001fdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041fdf0: { // 0x41fdf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0041fdf3: { // 0x41fdf3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041fdf5: { // 0x41fdf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041fdf6: { // 0x41fdf6: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fdfa: { // 0x41fdfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041fdfb: { // 0x41fdfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041fdfc: { // 0x41fdfc: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041fdfe: { // 0x41fdfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041fdff: { // 0x41fdff: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L0041fe01: { // 0x41fe01: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0041fe04: { // 0x41fe04: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L0041fe07: { // 0x41fe07: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe0b: { // 0x41fe0b: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  L0041fe0e: { // 0x41fe0e: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0041fe12: { // 0x41fe12: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0041fe15: { // 0x41fe15: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041fe17: { // 0x41fe17: 0f8edb000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe1d: { // 0x41fe1d: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0041fe20: { // 0x41fe20: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe22: { // 0x41fe22: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0041fe26: { // 0x41fe26: 0f8ecc000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe2c: { // 0x41fe2c: 8b6908 MOV EBP,dword ptr [ECX + 0x8]
    s.bp = m.r32((s.cx+0x00000008u));
  }
  L0041fe2f: { // 0x41fe2f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe31: { // 0x41fe31: 0f8ec1000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe37: { // 0x41fe37: 8b690c MOV EBP,dword ptr [ECX + 0xc]
    s.bp = m.r32((s.cx+0x0000000cu));
  }
  L0041fe3a: { // 0x41fe3a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe3c: { // 0x41fe3c: 0f8eb6000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe42: { // 0x41fe42: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0041fe44: { // 0x41fe44: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe46: { // 0x41fe46: 7d0e JGE 0x0041fe56
    if(integer::condition("JGE",flags)) goto L0041fe56;
  }
  L0041fe48: { // 0x41fe48: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe4c: { // 0x41fe4c: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe4e: { // 0x41fe4e: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe50: { // 0x41fe50: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0041fe52: { // 0x41fe52: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe56: { // 0x41fe56: 837c242001 CMP dword ptr [ESP + 0x20],0x1
    (void)integer::sub(m.r32((f.sp+0x00000020u)),0x00000001u,32,flags);
  }
  L0041fe5b: { // 0x41fe5b: 0f8c97000000 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe61: { // 0x41fe61: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L0041fe64: { // 0x41fe64: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe66: { // 0x41fe66: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0041fe6a: { // 0x41fe6a: 7d0e JGE 0x0041fe7a
    if(integer::condition("JGE",flags)) goto L0041fe7a;
  }
  L0041fe6c: { // 0x41fe6c: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0041fe70: { // 0x41fe70: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe72: { // 0x41fe72: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041fe74: { // 0x41fe74: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0041fe76: { // 0x41fe76: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0041fe7a: { // 0x41fe7a: 837c242401 CMP dword ptr [ESP + 0x24],0x1
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x00000001u,32,flags);
  }
  L0041fe7f: { // 0x41fe7f: 7c77 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe81: { // 0x41fe81: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe85: { // 0x41fe85: 8d1431 LEA EDX,[ECX + ESI*0x1]
    s.dx = (s.cx+(s.si * 0x00000001u));
  }
  L0041fe88: { // 0x41fe88: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe8a: { // 0x41fe8a: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041fe8c: { // 0x41fe8c: 7e06 JLE 0x0041fe94
    if(integer::condition("JLE",flags)) goto L0041fe94;
  }
  L0041fe8e: { // 0x41fe8e: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0041fe90: { // 0x41fe90: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041fe92: { // 0x41fe92: eb04 JMP 0x0041fe98
    goto L0041fe98;
  }
  L0041fe94: { // 0x41fe94: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fe98: { // 0x41fe98: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0041fe9b: { // 0x41fe9b: 7c5b JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe9d: { // 0x41fe9d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041fea1: { // 0x41fea1: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0041fea5: { // 0x41fea5: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041fea7: { // 0x41fea7: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041feab: { // 0x41feab: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  L0041feae: { // 0x41feae: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041feb0: { // 0x41feb0: 7e04 JLE 0x0041feb6
    if(integer::condition("JLE",flags)) goto L0041feb6;
  }
  L0041feb2: { // 0x41feb2: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0041feb4: { // 0x41feb4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0041feb6: { // 0x41feb6: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0041feb9: { // 0x41feb9: 7c3d JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041febb: { // 0x41febb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0041febf: { // 0x41febf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fec1: { // 0x41fec1: 740b JZ 0x0041fece
    if(integer::condition("JZ",flags)) goto L0041fece;
  }
  L0041fec3: { // 0x41fec3: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041fec7: { // 0x41fec7: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L0041feca: { // 0x41feca: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0041fecc: { // 0x41fecc: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fece: { // 0x41fece: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0041fed2: { // 0x41fed2: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fed4: { // 0x41fed4: 740b JZ 0x0041fee1
    if(integer::condition("JZ",flags)) goto L0041fee1;
  }
  L0041fed6: { // 0x41fed6: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041feda: { // 0x41feda: 8b6d04 MOV EBP,dword ptr [EBP + 0x4]
    s.bp = m.r32((s.bp+0x00000004u));
  }
  L0041fedd: { // 0x41fedd: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0041fedf: { // 0x41fedf: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fee1: { // 0x41fee1: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fee3: { // 0x41fee3: 891a MOV dword ptr [EDX],EBX
    m.w32((s.dx), s.bx);
  }
  L0041fee5: { // 0x41fee5: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0041fee8: { // 0x41fee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fee9: { // 0x41fee9: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041feec: { // 0x41feec: 89720c MOV dword ptr [EDX + 0xc],ESI
    m.w32((s.dx+0x0000000cu), s.si);
  }
  L0041feef: { // 0x41feef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fef0: { // 0x41fef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041fef1: { // 0x41fef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041fef2: { // 0x41fef2: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041fef5: { // 0x41fef5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041fef8: { // 0x41fef8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fefa: { // 0x41fefa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041fefc: { // 0x41fefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fefd: { // 0x41fefd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fefe: { // 0x41fefe: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0041ff00: { // 0x41ff00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ff01: { // 0x41ff01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ff02: { // 0x41ff02: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0041ff05: { // 0x41ff05: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041ff08: { // 0x41ff08: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L0041ff0b: { // 0x41ff0b: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041ff0e: { // 0x41ff0e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_00360f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760f60: { // 0x760f60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760f61: { // 0x760f61: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00760f63: { // 0x760f63: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00760f66: { // 0x760f66: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L00760f69: { // 0x760f69: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760f6a: { // 0x760f6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760f6b: { // 0x760f6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760f6c: { // 0x760f6c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00760f6e: { // 0x760f6e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00760f70: { // 0x760f70: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00760f73: { // 0x760f73: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00760f77: { // 0x760f77: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00760f79: { // 0x760f79: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L00760f7c: { // 0x760f7c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00760f80: { // 0x760f80: 8b5908 MOV EBX,dword ptr [ECX + 0x8]
    s.bx = m.r32((s.cx+0x00000008u));
  }
  L00760f83: { // 0x760f83: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f87: { // 0x760f87: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00760f8b: { // 0x760f8b: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00760f8d: { // 0x760f8d: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760f91: { // 0x760f91: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f95: { // 0x760f95: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00760f99: { // 0x760f99: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00760f9b: { // 0x760f9b: db02 FILD dword ptr [EDX]
    const auto address=(s.dx);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f9d: { // 0x760f9d: dd5c2438 FSTP double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fa1: { // 0x760fa1: db4204 FILD dword ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fa4: { // 0x760fa4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00760fa6: { // 0x760fa6: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760faa: { // 0x760faa: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fac: { // 0x760fac: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760fb0: { // 0x760fb0: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fb3: { // 0x760fb3: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fb7: { // 0x760fb7: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L00760fbb: { // 0x760fbb: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fbd: { // 0x760fbd: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00760fbf: { // 0x760fbf: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00760fc3: { // 0x760fc3: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L00760fc7: { // 0x760fc7: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fc9: { // 0x760fc9: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fcb: { // 0x760fcb: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fcf: { // 0x760fcf: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fd1: { // 0x760fd1: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fd5: { // 0x760fd5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fd7: { // 0x760fd7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fdb: { // 0x760fdb: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fdf: { // 0x760fdf: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00760fe3: { // 0x760fe3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760fe5: { // 0x760fe5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760fe8: { // 0x760fe8: 7509 JNZ 0x00760ff3
    if(integer::condition("JNZ",flags)) goto L00760ff3;
  }
  L00760fea: { // 0x760fea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fec: { // 0x760fec: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00760ff1: { // 0x760ff1: eb0e JMP 0x00761001
    goto L00761001;
  }
  L00760ff3: { // 0x760ff3: d8dc FCOMP ST4
    numeric_b88::detail::reg<0xd8dc>(s.fp);
  }
  L00760ff5: { // 0x760ff5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760ff7: { // 0x760ff7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760ffa: { // 0x760ffa: 7405 JZ 0x00761001
    if(integer::condition("JZ",flags)) goto L00761001;
  }
  L00760ffc: { // 0x760ffc: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00761001: { // 0x761001: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00761004: { // 0x761004: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00761006: { // 0x761006: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076100a: { // 0x76100a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0076100e: { // 0x76100e: dd5c2450 FSTP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761012: { // 0x761012: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L00761016: { // 0x761016: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0076101a: { // 0x76101a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076101c: { // 0x76101c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076101f: { // 0x76101f: 7505 JNZ 0x00761026
    if(integer::condition("JNZ",flags)) goto L00761026;
  }
  L00761021: { // 0x761021: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L00761024: { // 0x761024: eb10 JMP 0x00761036
    goto L00761036;
  }
  L00761026: { // 0x761026: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0076102a: { // 0x76102a: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076102c: { // 0x76102c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076102e: { // 0x76102e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761031: { // 0x761031: 7403 JZ 0x00761036
    if(integer::condition("JZ",flags)) goto L00761036;
  }
  L00761033: { // 0x761033: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761036: { // 0x761036: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0076103a: { // 0x76103a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076103c: { // 0x76103c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076103e: { // 0x76103e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761041: { // 0x761041: 7509 JNZ 0x0076104c
    if(integer::condition("JNZ",flags)) goto L0076104c;
  }
  L00761043: { // 0x761043: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761045: { // 0x761045: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0076104a: { // 0x76104a: eb0e JMP 0x0076105a
    goto L0076105a;
  }
  L0076104c: { // 0x76104c: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076104e: { // 0x76104e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761050: { // 0x761050: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761053: { // 0x761053: 7405 JZ 0x0076105a
    if(integer::condition("JZ",flags)) goto L0076105a;
  }
  L00761055: { // 0x761055: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0076105a: { // 0x76105a: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L0076105e: { // 0x76105e: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00761062: { // 0x761062: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761064: { // 0x761064: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761067: { // 0x761067: 7505 JNZ 0x0076106e
    if(integer::condition("JNZ",flags)) goto L0076106e;
  }
  L00761069: { // 0x761069: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L0076106c: { // 0x76106c: eb10 JMP 0x0076107e
    goto L0076107e;
  }
  L0076106e: { // 0x76106e: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761072: { // 0x761072: d8da FCOMP ST2
    numeric_b88::detail::reg<0xd8da>(s.fp);
  }
  L00761074: { // 0x761074: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761076: { // 0x761076: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761079: { // 0x761079: 7403 JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076107b: { // 0x76107b: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  L0076107e: { // 0x76107e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761080: { // 0x761080: 7508 JNZ 0x0076108a
    if(integer::condition("JNZ",flags)) goto L0076108a;
  }
  L00761082: { // 0x761082: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00761084: { // 0x761084: 0f844f010000 JZ 0x007611d9
    if(integer::condition("JZ",flags)) goto L007611d9;
  }
  L0076108a: { // 0x76108a: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076108c: { // 0x76108c: 0f858a010000 JNZ 0x0076121c
    if(integer::condition("JNZ",flags)) goto L0076121c;
  }
  L00761092: { // 0x761092: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761094: { // 0x761094: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00761096: { // 0x761096: 7502 JNZ 0x0076109a
    if(integer::condition("JNZ",flags)) goto L0076109a;
  }
  L00761098: { // 0x761098: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076109a: { // 0x76109a: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0076109c: { // 0x76109c: 7418 JZ 0x007610b6
    if(integer::condition("JZ",flags)) goto L007610b6;
  }
  L0076109e: { // 0x76109e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610a0: { // 0x7610a0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610a2: { // 0x7610a2: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610a6: { // 0x7610a6: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610aa: { // 0x7610aa: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610ae: { // 0x7610ae: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007610b2: { // 0x7610b2: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610b4: { // 0x7610b4: eb72 JMP 0x00761128
    goto L00761128;
  }
  L007610b6: { // 0x7610b6: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L007610b8: { // 0x7610b8: 741f JZ 0x007610d9
    if(integer::condition("JZ",flags)) goto L007610d9;
  }
  L007610ba: { // 0x7610ba: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L007610be: { // 0x7610be: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610bf: { // 0x7610bf: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610c1: { // 0x7610c1: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610c5: { // 0x7610c5: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610c9: { // 0x7610c9: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610cb: { // 0x7610cb: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610cf: { // 0x7610cf: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610d3: { // 0x7610d3: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610d7: { // 0x7610d7: eb4b JMP 0x00761124
    goto L00761124;
  }
  L007610d9: { // 0x7610d9: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L007610db: { // 0x7610db: 7431 JZ 0x0076110e
    if(integer::condition("JZ",flags)) goto L0076110e;
  }
  L007610dd: { // 0x7610dd: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007610e1: { // 0x7610e1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610e2: { // 0x7610e2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610e4: { // 0x7610e4: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610e8: { // 0x7610e8: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610ec: { // 0x7610ec: dd542418 FST double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L007610f0: { // 0x7610f0: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L007610f4: { // 0x7610f4: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L007610f8: { // 0x7610f8: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007610fc: { // 0x7610fc: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L00761100: { // 0x761100: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L00761104: { // 0x761104: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L00761108: { // 0x761108: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L0076110c: { // 0x76110c: eb1a JMP 0x00761128
    goto L00761128;
  }
  L0076110e: { // 0x76110e: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00761110: { // 0x761110: 7416 JZ 0x00761128
    if(integer::condition("JZ",flags)) goto L00761128;
  }
  L00761112: { // 0x761112: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761114: { // 0x761114: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761116: { // 0x761116: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L0076111a: { // 0x76111a: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L0076111e: { // 0x76111e: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L00761122: { // 0x761122: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00761124: { // 0x761124: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761128: { // 0x761128: dd442430 FLD double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L0076112c: { // 0x76112c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0076112e: { // 0x76112e: 7556 JNZ 0x00761186
    if(integer::condition("JNZ",flags)) goto L00761186;
  }
  L00761130: { // 0x761130: dd542438 FST double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00761134: { // 0x761134: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761136: { // 0x761136: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00761138: { // 0x761138: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0076113c: { // 0x76113c: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761140: { // 0x761140: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761142: { // 0x761142: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761145: { // 0x761145: 7509 JNZ 0x00761150
    if(integer::condition("JNZ",flags)) goto L00761150;
  }
  L00761147: { // 0x761147: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761149: { // 0x761149: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0076114e: { // 0x76114e: eb0e JMP 0x0076115e
    goto L0076115e;
  }
  L00761150: { // 0x761150: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L00761152: { // 0x761152: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761154: { // 0x761154: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761157: { // 0x761157: 7405 JZ 0x0076115e
    if(integer::condition("JZ",flags)) goto L0076115e;
  }
  L00761159: { // 0x761159: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0076115e: { // 0x76115e: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761162: { // 0x761162: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761164: { // 0x761164: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761167: { // 0x761167: 7508 JNZ 0x00761171
    if(integer::condition("JNZ",flags)) goto L00761171;
  }
  L00761169: { // 0x761169: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L0076116c: { // 0x76116c: e90dffffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761171: { // 0x761171: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L00761173: { // 0x761173: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761175: { // 0x761175: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761178: { // 0x761178: 0f8400ffffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076117e: { // 0x76117e: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761181: { // 0x761181: e9f8feffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761186: { // 0x761186: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0076118a: { // 0x76118a: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0076118c: { // 0x76118c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076118e: { // 0x76118e: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761192: { // 0x761192: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761196: { // 0x761196: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761198: { // 0x761198: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076119b: { // 0x76119b: 7509 JNZ 0x007611a6
    if(integer::condition("JNZ",flags)) goto L007611a6;
  }
  L0076119d: { // 0x76119d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076119f: { // 0x76119f: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L007611a4: { // 0x7611a4: eb0e JMP 0x007611b4
    goto L007611b4;
  }
  L007611a6: { // 0x7611a6: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L007611a8: { // 0x7611a8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611aa: { // 0x7611aa: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ad: { // 0x7611ad: 7405 JZ 0x007611b4
    if(integer::condition("JZ",flags)) goto L007611b4;
  }
  L007611af: { // 0x7611af: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L007611b4: { // 0x7611b4: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L007611b8: { // 0x7611b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611ba: { // 0x7611ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611bd: { // 0x7611bd: 7508 JNZ 0x007611c7
    if(integer::condition("JNZ",flags)) goto L007611c7;
  }
  L007611bf: { // 0x7611bf: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L007611c2: { // 0x7611c2: e9b7feffff JMP 0x0076107e
    goto L0076107e;
  }
  L007611c7: { // 0x7611c7: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L007611c9: { // 0x7611c9: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611cb: { // 0x7611cb: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ce: { // 0x7611ce: 0f84aafeffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L007611d4: { // 0x7611d4: e9a2feffff JMP 0x0076107b
    goto L0076107b;
  }
  L007611d9: { // 0x7611d9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611db: { // 0x7611db: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611dd: { // 0x7611dd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611df: { // 0x7611df: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L007611e3: { // 0x7611e3: e868980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737832u,op); flags=s.arithmetic_flags;
  }
  L007611e8: { // 0x7611e8: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L007611ec: { // 0x7611ec: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L007611f0: { // 0x7611f0: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L007611f2: { // 0x7611f2: e859980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737847u,op); flags=s.arithmetic_flags;
  }
  L007611f7: { // 0x7611f7: dd442468 FLD double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.load64(read64(m,address));
  }
  L007611fb: { // 0x7611fb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L007611fe: { // 0x7611fe: e84d980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737859u,op); flags=s.arithmetic_flags;
  }
  L00761203: { // 0x761203: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761207: { // 0x761207: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L00761209: { // 0x761209: e842980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737870u,op); flags=s.arithmetic_flags;
  }
  L0076120e: { // 0x76120e: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00761211: { // 0x761211: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00761213: { // 0x761213: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761214: { // 0x761214: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761215: { // 0x761215: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761216: { // 0x761216: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761218: { // 0x761218: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00761219: { // 0x761219: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0076121c: { // 0x76121c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076121e: { // 0x76121e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761220: { // 0x761220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761221: { // 0x761221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761222: { // 0x761222: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761224: { // 0x761224: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00761226: { // 0x761226: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761227: { // 0x761227: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761229: { // 0x761229: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076122a: { // 0x76122a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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

void f_0035f2c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f2c0: { // 0x75f2c0: 83ec44 SUB ESP,0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L0075f2c3: { // 0x75f2c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075f2c4: { // 0x75f2c4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0075f2c6: { // 0x75f2c6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0075f2c7: { // 0x75f2c7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075f2c8: { // 0x75f2c8: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f2ca: { // 0x75f2ca: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0075f2ce: { // 0x75f2ce: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075f2cf: { // 0x75f2cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2d0: { // 0x75f2d0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f2d2: { // 0x75f2d2: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7729877u,op); flags=s.arithmetic_flags;
  }
  L0075f2d5: { // 0x75f2d5: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L0075f2d9: { // 0x75f2d9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075f2db: { // 0x75f2db: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075f2dd: { // 0x75f2dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2de: { // 0x75f2de: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0075f2e2: { // 0x75f2e2: e8090bccff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7729895u,op); flags=s.arithmetic_flags;
  }
  L0075f2e7: { // 0x75f2e7: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0075f2e9: { // 0x75f2e9: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0075f2ed: { // 0x75f2ed: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0075f2f0: { // 0x75f2f0: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0075f2f4: { // 0x75f2f4: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0075f2f7: { // 0x75f2f7: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0075f2fb: { // 0x75f2fb: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L0075f2ff: { // 0x75f2ff: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075f302: { // 0x75f302: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0075f306: { // 0x75f306: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0075f308: { // 0x75f308: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0075f30b: { // 0x75f30b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0075f30d: { // 0x75f30d: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f30f: { // 0x75f30f: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0075f313: { // 0x75f313: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0075f317: { // 0x75f317: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L0075f31b: { // 0x75f31b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0075f31d: { // 0x75f31d: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0075f320: { // 0x75f320: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f322: { // 0x75f322: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0075f324: { // 0x75f324: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0075f328: { // 0x75f328: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0075f32c: { // 0x75f32c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f32d: { // 0x75f32d: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0075f331: { // 0x75f331: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0075f335: { // 0x75f335: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0075f339: { // 0x75f339: e8221c0000 CALL 0x00760f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760f60u,7729982u,op); flags=s.arithmetic_flags;
  }
  L0075f33e: { // 0x75f33e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0075f340: { // 0x75f340: 0f841b020000 JZ 0x0075f561
    if(integer::condition("JZ",flags)) goto L0075f561;
  }
  L0075f346: { // 0x75f346: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0075f34a: { // 0x75f34a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0075f34e: { // 0x75f34e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f350: { // 0x75f350: 7e18 JLE 0x0075f36a
    if(integer::condition("JLE",flags)) goto L0075f36a;
  }
  L0075f352: { // 0x75f352: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0075f356: { // 0x75f356: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0075f35a: { // 0x75f35a: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0075f35e: { // 0x75f35e: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0075f362: { // 0x75f362: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0075f366: { // 0x75f366: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0075f36a: { // 0x75f36a: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f36c: { // 0x75f36c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f36e: { // 0x75f36e: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),7730033u,op); flags=s.arithmetic_flags;
  }
  L0075f371: { // 0x75f371: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0075f375: { // 0x75f375: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f377: { // 0x75f377: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0075f379: { // 0x75f379: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0075f37d: { // 0x75f37d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f37e: { // 0x75f37e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f37f: { // 0x75f37f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f381: { // 0x75f381: 896c2464 MOV dword ptr [ESP + 0x64],EBP
    m.w32((f.sp+0x00000064u), s.bp);
  }
  L0075f385: { // 0x75f385: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7730056u,op); flags=s.arithmetic_flags;
  }
  L0075f388: { // 0x75f388: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0075f38a: { // 0x75f38a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0075f38c: { // 0x75f38c: 0f84cf010000 JZ 0x0075f561
    if(integer::condition("JZ",flags)) goto L0075f561;
  }
  L0075f392: { // 0x75f392: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0075f396: { // 0x75f396: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0075f39a: { // 0x75f39a: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0075f39c: { // 0x75f39c: 757f JNZ 0x0075f41d
    if(integer::condition("JNZ",flags)) goto L0075f41d;
  }
  L0075f39e: { // 0x75f39e: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L0075f3a1: { // 0x75f3a1: 753c JNZ 0x0075f3df
    if(integer::condition("JNZ",flags)) goto L0075f3df;
  }
  L0075f3a3: { // 0x75f3a3: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3a7: { // 0x75f3a7: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f3ab: { // 0x75f3ab: 8a442464 MOV AL,byte ptr [ESP + 0x64]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000064u)));
  }
  L0075f3af: { // 0x75f3af: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0075f3b1: { // 0x75f3b1: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0075f3b3: { // 0x75f3b3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0075f3b4: { // 0x75f3b4: 8af2 MOV DH,DL
    s.dx = (s.dx & 0xffff00ffu) | ((((s.dx & 0xffu)) & 0xffu) << 8);
  }
  L0075f3b6: { // 0x75f3b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0075f3b8: { // 0x75f3b8: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0075f3ba: { // 0x75f3ba: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075f3bd: { // 0x75f3bd: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L0075f3c0: { // 0x75f3c0: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0075f3c3: { // 0x75f3c3: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075f3c5: { // 0x75f3c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075f3c7: { // 0x75f3c7: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0075f3ca: { // 0x75f3ca: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L0075f3cc: { // 0x75f3cc: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f3ce: { // 0x75f3ce: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f3d0: { // 0x75f3d0: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730131u,op); flags=s.arithmetic_flags;
  }
  L0075f3d3: { // 0x75f3d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f3d4: { // 0x75f3d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f3d5: { // 0x75f3d5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f3d6: { // 0x75f3d6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f3d8: { // 0x75f3d8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f3d9: { // 0x75f3d9: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f3dc: { // 0x75f3dc: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f3df: { // 0x75f3df: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3e3: { // 0x75f3e3: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f3e7: { // 0x75f3e7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0075f3e9: { // 0x75f3e9: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0075f3eb: { // 0x75f3eb: 0f885d010000 JS 0x0075f54e
    if(integer::condition("JS",flags)) goto L0075f54e;
  }
  L0075f3f1: { // 0x75f3f1: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0075f3f5: { // 0x75f3f5: 66890f MOV word ptr [EDI],CX
    m.w16((s.di), (s.cx & 0xffffu));
  }
  L0075f3f8: { // 0x75f3f8: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3fc: { // 0x75f3fc: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0075f400: { // 0x75f400: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0075f401: { // 0x75f401: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L0075f403: { // 0x75f403: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L0075f406: { // 0x75f406: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f408: { // 0x75f408: 7eeb JLE 0x0075f3f5
    if(integer::condition("JLE",flags)) goto L0075f3f5;
  }
  L0075f40a: { // 0x75f40a: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f40c: { // 0x75f40c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f40e: { // 0x75f40e: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730193u,op); flags=s.arithmetic_flags;
  }
  L0075f411: { // 0x75f411: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f412: { // 0x75f412: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f413: { // 0x75f413: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f414: { // 0x75f414: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f416: { // 0x75f416: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f417: { // 0x75f417: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f41a: { // 0x75f41a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f41d: { // 0x75f41d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0075f421: { // 0x75f421: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f425: { // 0x75f425: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0075f427: { // 0x75f427: 755a JNZ 0x0075f483
    if(integer::condition("JNZ",flags)) goto L0075f483;
  }
  L0075f429: { // 0x75f429: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0075f42b: { // 0x75f42b: 7e0d JLE 0x0075f43a
    if(integer::condition("JLE",flags)) goto L0075f43a;
  }
  L0075f42d: { // 0x75f42d: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f42f: { // 0x75f42f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f431: { // 0x75f431: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730228u,op); flags=s.arithmetic_flags;
  }
  L0075f434: { // 0x75f434: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0075f436: { // 0x75f436: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0075f438: { // 0x75f438: eb09 JMP 0x0075f443
    goto L0075f443;
  }
  L0075f43a: { // 0x75f43a: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f43c: { // 0x75f43c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f43e: { // 0x75f43e: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),7730241u,op); flags=s.arithmetic_flags;
  }
  L0075f441: { // 0x75f441: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0075f443: { // 0x75f443: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0075f447: { // 0x75f447: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0075f44b: { // 0x75f44b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f44d: { // 0x75f44d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0075f44e: { // 0x75f44e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0075f450: { // 0x75f450: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f452: { // 0x75f452: 0f88f6000000 JS 0x0075f54e
    if(integer::condition("JS",flags)) goto L0075f54e;
  }
  L0075f458: { // 0x75f458: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L0075f45b: { // 0x75f45b: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f45f: { // 0x75f45f: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L0075f462: { // 0x75f462: 7504 JNZ 0x0075f468
    if(integer::condition("JNZ",flags)) goto L0075f468;
  }
  L0075f464: { // 0x75f464: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0075f466: { // 0x75f466: eb03 JMP 0x0075f46b
    goto L0075f46b;
  }
  L0075f468: { // 0x75f468: 668907 MOV word ptr [EDI],AX
    m.w16((s.di), (s.ax & 0xffffu));
  }
  L0075f46b: { // 0x75f46b: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0075f46d: { // 0x75f46d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0075f46e: { // 0x75f46e: 75ef JNZ 0x0075f45f
    if(integer::condition("JNZ",flags)) goto L0075f45f;
  }
  L0075f470: { // 0x75f470: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f472: { // 0x75f472: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f474: { // 0x75f474: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730295u,op); flags=s.arithmetic_flags;
  }
  L0075f477: { // 0x75f477: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f478: { // 0x75f478: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f479: { // 0x75f479: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f47a: { // 0x75f47a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f47c: { // 0x75f47c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f47d: { // 0x75f47d: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f480: { // 0x75f480: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f483: { // 0x75f483: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f485: { // 0x75f485: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0075f487: { // 0x75f487: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0075f489: { // 0x75f489: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f48b: { // 0x75f48b: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0075f48d: { // 0x75f48d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f48f: { // 0x75f48f: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730322u,op); flags=s.arithmetic_flags;
  }
  L0075f492: { // 0x75f492: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0075f494: { // 0x75f494: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0075f498: { // 0x75f498: 7d06 JGE 0x0075f4a0
    if(integer::condition("JGE",flags)) goto L0075f4a0;
  }
  L0075f49a: { // 0x75f49a: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0075f49c: { // 0x75f49c: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0075f4a0: { // 0x75f4a0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0075f4a2: { // 0x75f4a2: 8d742d00 LEA ESI,[EBP + EBP*0x1]
    s.si = (s.bp+(s.bp * 0x00000001u));
  }
  L0075f4a6: { // 0x75f4a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0075f4a7: { // 0x75f4a7: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0075f4a9: { // 0x75f4a9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f4ab: { // 0x75f4ab: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0075f4ad: { // 0x75f4ad: 8d0c00 LEA ECX,[EAX + EAX*0x1]
    s.cx = (s.ax+(s.ax * 0x00000001u));
  }
  L0075f4b0: { // 0x75f4b0: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0075f4b4: { // 0x75f4b4: 7e54 JLE 0x0075f50a
    if(integer::condition("JLE",flags)) goto L0075f50a;
  }
  L0075f4b6: { // 0x75f4b6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0075f4b8: { // 0x75f4b8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0075f4ba: { // 0x75f4ba: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0075f4bc: { // 0x75f4bc: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0075f4be: { // 0x75f4be: 0f8e8a000000 JLE 0x0075f54e
    if(integer::condition("JLE",flags)) goto L0075f54e;
  }
  L0075f4c4: { // 0x75f4c4: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0075f4c8: { // 0x75f4c8: 837c245c01 CMP dword ptr [ESP + 0x5c],0x1
    (void)integer::sub(m.r32((f.sp+0x0000005cu)),0x00000001u,32,flags);
  }
  L0075f4cd: { // 0x75f4cd: 7505 JNZ 0x0075f4d4
    if(integer::condition("JNZ",flags)) goto L0075f4d4;
  }
  L0075f4cf: { // 0x75f4cf: 881439 MOV byte ptr [ECX + EDI*0x1],DL
    m.w8((s.cx+(s.di * 0x00000001u)), (s.dx & 0xffu));
  }
  L0075f4d2: { // 0x75f4d2: eb08 JMP 0x0075f4dc
    goto L0075f4dc;
  }
  L0075f4d4: { // 0x75f4d4: 6689144f MOV word ptr [EDI + ECX*0x2],DX
    m.w16((s.di+(s.cx * 0x00000002u)), (s.dx & 0xffffu));
  }
  L0075f4d8: { // 0x75f4d8: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0075f4dc: { // 0x75f4dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075f4de: { // 0x75f4de: 7e0c JLE 0x0075f4ec
    if(integer::condition("JLE",flags)) goto L0075f4ec;
  }
  L0075f4e0: { // 0x75f4e0: 8b742458 MOV ESI,dword ptr [ESP + 0x58]
    s.si = m.r32((f.sp+0x00000058u));
  }
  L0075f4e4: { // 0x75f4e4: 03fe ADD EDI,ESI
    s.di = integer::add(s.di,s.si,32,flags);
  }
  L0075f4e6: { // 0x75f4e6: 8d742d00 LEA ESI,[EBP + EBP*0x1]
    s.si = (s.bp+(s.bp * 0x00000001u));
  }
  L0075f4ea: { // 0x75f4ea: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0075f4ec: { // 0x75f4ec: 8b742460 MOV ESI,dword ptr [ESP + 0x60]
    s.si = m.r32((f.sp+0x00000060u));
  }
  L0075f4f0: { // 0x75f4f0: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0075f4f2: { // 0x75f4f2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0075f4f3: { // 0x75f4f3: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L0075f4f5: { // 0x75f4f5: 7cd1 JL 0x0075f4c8
    if(integer::condition("JL",flags)) goto L0075f4c8;
  }
  L0075f4f7: { // 0x75f4f7: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f4f9: { // 0x75f4f9: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f4fb: { // 0x75f4fb: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730430u,op); flags=s.arithmetic_flags;
  }
  L0075f4fe: { // 0x75f4fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f4ff: { // 0x75f4ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f500: { // 0x75f500: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f501: { // 0x75f501: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f503: { // 0x75f503: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f504: { // 0x75f504: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f507: { // 0x75f507: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f50a: { // 0x75f50a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075f50c: { // 0x75f50c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0075f50e: { // 0x75f50e: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0075f510: { // 0x75f510: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075f512: { // 0x75f512: 7e3a JLE 0x0075f54e
    if(integer::condition("JLE",flags)) goto L0075f54e;
  }
  L0075f514: { // 0x75f514: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0075f518: { // 0x75f518: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f51c: { // 0x75f51c: 837c245c01 CMP dword ptr [ESP + 0x5c],0x1
    (void)integer::sub(m.r32((f.sp+0x0000005cu)),0x00000001u,32,flags);
  }
  L0075f521: { // 0x75f521: 7505 JNZ 0x0075f528
    if(integer::condition("JNZ",flags)) goto L0075f528;
  }
  L0075f523: { // 0x75f523: 88043a MOV byte ptr [EDX + EDI*0x1],AL
    m.w8((s.dx+(s.di * 0x00000001u)), (s.ax & 0xffu));
  }
  L0075f526: { // 0x75f526: eb08 JMP 0x0075f530
    goto L0075f530;
  }
  L0075f528: { // 0x75f528: 66890457 MOV word ptr [EDI + EDX*0x2],AX
    m.w16((s.di+(s.dx * 0x00000002u)), (s.ax & 0xffffu));
  }
  L0075f52c: { // 0x75f52c: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f530: { // 0x75f530: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0075f532: { // 0x75f532: 7e07 JLE 0x0075f53b
    if(integer::condition("JLE",flags)) goto L0075f53b;
  }
  L0075f534: { // 0x75f534: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L0075f538: { // 0x75f538: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0075f539: { // 0x75f539: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  L0075f53b: { // 0x75f53b: 8b6c2458 MOV EBP,dword ptr [ESP + 0x58]
    s.bp = m.r32((f.sp+0x00000058u));
  }
  L0075f53f: { // 0x75f53f: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f541: { // 0x75f541: 03fd ADD EDI,EBP
    s.di = integer::add(s.di,s.bp,32,flags);
  }
  L0075f543: { // 0x75f543: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0075f547: { // 0x75f547: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0075f548: { // 0x75f548: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0075f54c: { // 0x75f54c: 75ce JNZ 0x0075f51c
    if(integer::condition("JNZ",flags)) goto L0075f51c;
  }
  L0075f54e: { // 0x75f54e: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f550: { // 0x75f550: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f552: { // 0x75f552: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730517u,op); flags=s.arithmetic_flags;
  }
  L0075f555: { // 0x75f555: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f556: { // 0x75f556: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f557: { // 0x75f557: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f558: { // 0x75f558: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f55a: { // 0x75f55a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f55b: { // 0x75f55b: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f55e: { // 0x75f55e: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f561: { // 0x75f561: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f562: { // 0x75f562: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f563: { // 0x75f563: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f564: { // 0x75f564: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0075f566: { // 0x75f566: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f567: { // 0x75f567: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f56a: { // 0x75f56a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_0035f290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f290: { // 0x75f290: 8b44240c MOV EAX, DWORD PTR [ESP + 0XC]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0075f294: { // 0x75f294: 83ec10 SUB ESP, 0X10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0075f297: { // 0x75f297: 8b542414 MOV EDX, DWORD PTR [ESP + 0X14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f29b: { // 0x75f29b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075f29c: { // 0x75f29c: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0075f29e: { // 0x75f29e: 8b4c241c MOV ECX, DWORD PTR [ESP + 0X1C]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f2a2: { // 0x75f2a2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2a3: { // 0x75f2a3: 8b06 MOV EAX, DWORD PTR [ESI]
    s.ax = m.r32((s.si));
  }
  L0075f2a5: { // 0x75f2a5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2a6: { // 0x75f2a6: 8d4c240c LEA ECX, [ESP + 0XC]
    s.cx = (f.sp+0x0000000cu);
  }
  L0075f2aa: { // 0x75f2aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0075f2ab: { // 0x75f2ab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2ac: { // 0x75f2ac: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0075f2ae: { // 0x75f2ae: ff5078 CALL DWORD PTR [EAX + 0X78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7729841u,op); flags=s.arithmetic_flags;
  }
  L0075f2b1: { // 0x75f2b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2b2: { // 0x75f2b2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0075f2b4: { // 0x75f2b4: e807000000 CALL 0X75F2C0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0075f2c0u,7729849u,op); flags=s.arithmetic_flags;
  }
  L0075f2b9: { // 0x75f2b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f2ba: { // 0x75f2ba: 83c410 ADD ESP, 0X10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0075f2bd: { // 0x75f2bd: c20c00 RET 0XC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_0009ebd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049ebd0: { // 0x49ebd0: 83ec6c SUB ESP,0x6c
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L0049ebd3: { // 0x49ebd3: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    s.ax = m.r32((f.sp+0x00000084u));
  }
  L0049ebda: { // 0x49ebda: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049ebdb: { // 0x49ebdb: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0049ebdf: { // 0x49ebdf: 89827c010000 MOV dword ptr [EDX + 0x17c],EAX
    m.w32((s.dx+0x0000017cu), s.ax);
  }
  L0049ebe5: { // 0x49ebe5: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    s.ax = m.r32((f.sp+0x0000007cu));
  }
  L0049ebe9: { // 0x49ebe9: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0049ebed: { // 0x49ebed: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ebf1: { // 0x49ebf1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ebf2: { // 0x49ebf2: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049ebf4: { // 0x49ebf4: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0049ebf7: { // 0x49ebf7: 0fbf4306 MOVSX EAX,word ptr [EBX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000006u)),16));
  }
  L0049ebfb: { // 0x49ebfb: 8b6c247c MOV EBP,dword ptr [ESP + 0x7c]
    s.bp = m.r32((f.sp+0x0000007cu));
  }
  L0049ebff: { // 0x49ebff: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ec00: { // 0x49ec00: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0049ec02: { // 0x49ec02: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049ec03: { // 0x49ec03: 898c2488000000 MOV dword ptr [ESP + 0x88],ECX
    m.w32((f.sp+0x00000088u), s.cx);
  }
  L0049ec0a: { // 0x49ec0a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ec0e: { // 0x49ec0e: 7337 JNC 0x0049ec47
    if(integer::condition("JNC",flags)) goto L0049ec47;
  }
  L0049ec10: { // 0x49ec10: 8d4c6d00 LEA ECX,[EBP + EBP*0x2]
    s.cx = (s.bp+(s.bp * 0x00000002u));
  }
  L0049ec14: { // 0x49ec14: 8d44cb08 LEA EAX,[EBX + ECX*0x8 + 0x8]
    s.ax = (s.bx+(s.cx * 0x00000008u)+0x00000008u);
  }
  L0049ec18: { // 0x49ec18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec1a: { // 0x49ec1a: 742b JZ 0x0049ec47
    if(integer::condition("JZ",flags)) goto L0049ec47;
  }
  L0049ec1c: { // 0x49ec1c: 0fbf5006 MOVSX EDX,word ptr [EAX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L0049ec20: { // 0x49ec20: 0fbf4804 MOVSX ECX,word ptr [EAX + 0x4]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L0049ec24: { // 0x49ec24: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ec25: { // 0x49ec25: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ec26: { // 0x49ec26: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L0049ec2a: { // 0x49ec2a: 0fbf00 MOVSX EAX,word ptr [EAX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0049ec2d: { // 0x49ec2d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ec2e: { // 0x49ec2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ec2f: { // 0x49ec2f: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L0049ec33: { // 0x49ec33: e898d0f8ff CALL 0x0042bcd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042bcd0u,4844600u,op); flags=s.arithmetic_flags;
  }
  L0049ec38: { // 0x49ec38: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049ec3a: { // 0x49ec3a: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0049ec3c: { // 0x49ec3c: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0049ec3f: { // 0x49ec3f: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0049ec42: { // 0x49ec42: 8b7a0c MOV EDI,dword ptr [EDX + 0xc]
    s.di = m.r32((s.dx+0x0000000cu));
  }
  L0049ec45: { // 0x49ec45: eb17 JMP 0x0049ec5e
    goto L0049ec5e;
  }
  L0049ec47: { // 0x49ec47: a180ac8300 MOV EAX,[0x0083ac80]
    s.ax = m.r32((0x0083ac80u));
  }
  L0049ec4c: { // 0x49ec4c: 8b0d84ac8300 MOV ECX,dword ptr [0x0083ac84]
    s.cx = m.r32((0x0083ac84u));
  }
  L0049ec52: { // 0x49ec52: 8b3588ac8300 MOV ESI,dword ptr [0x0083ac88]
    s.si = m.r32((0x0083ac88u));
  }
  L0049ec58: { // 0x49ec58: 8b3d8cac8300 MOV EDI,dword ptr [0x0083ac8c]
    s.di = m.r32((0x0083ac8cu));
  }
  L0049ec5e: { // 0x49ec5e: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0049ec62: { // 0x49ec62: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0049ec66: { // 0x49ec66: 0fbf4306 MOVSX EAX,word ptr [EBX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000006u)),16));
  }
  L0049ec6a: { // 0x49ec6a: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0049ec6c: { // 0x49ec6c: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0049ec70: { // 0x49ec70: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L0049ec74: { // 0x49ec74: 7318 JNC 0x0049ec8e
    if(integer::condition("JNC",flags)) goto L0049ec8e;
  }
  L0049ec76: { // 0x49ec76: 8d4c6d00 LEA ECX,[EBP + EBP*0x2]
    s.cx = (s.bp+(s.bp * 0x00000002u));
  }
  L0049ec7a: { // 0x49ec7a: 8d44cb08 LEA EAX,[EBX + ECX*0x8 + 0x8]
    s.ax = (s.bx+(s.cx * 0x00000008u)+0x00000008u);
  }
  L0049ec7e: { // 0x49ec7e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec80: { // 0x49ec80: 740c JZ 0x0049ec8e
    if(integer::condition("JZ",flags)) goto L0049ec8e;
  }
  L0049ec82: { // 0x49ec82: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    s.ax = m.r32((s.ax+0x00000014u));
  }
  L0049ec85: { // 0x49ec85: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec87: { // 0x49ec87: 7405 JZ 0x0049ec8e
    if(integer::condition("JZ",flags)) goto L0049ec8e;
  }
  L0049ec89: { // 0x49ec89: 8d2c18 LEA EBP,[EAX + EBX*0x1]
    s.bp = (s.ax+(s.bx * 0x00000001u));
  }
  L0049ec8c: { // 0x49ec8c: eb02 JMP 0x0049ec90
    goto L0049ec90;
  }
  L0049ec8e: { // 0x49ec8e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049ec90: { // 0x49ec90: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0049ec94: { // 0x49ec94: 0fbf4304 MOVSX EAX,word ptr [EBX + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000004u)),16));
  }
  L0049ec98: { // 0x49ec98: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049ec99: { // 0x49ec99: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ec9a: { // 0x49ec9a: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L0049ec9e: { // 0x49ec9e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0049eca2: { // 0x49eca2: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0049eca6: { // 0x49eca6: e8a5040000 CALL 0x0049f150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049f150u,4844715u,op); flags=s.arithmetic_flags;
  }
  L0049ecab: { // 0x49ecab: 0faff7 IMUL ESI,EDI
    s.si = integer::imul(s.si,s.di,32,flags);
  }
  L0049ecae: { // 0x49ecae: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ecaf: { // 0x49ecaf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ecb0: { // 0x49ecb0: 8d4c2478 LEA ECX,[ESP + 0x78]
    s.cx = (f.sp+0x00000078u);
  }
  L0049ecb4: { // 0x49ecb4: c744247401000000 MOV dword ptr [ESP + 0x74],0x1
    m.w32((f.sp+0x00000074u), 0x00000001u);
  }
  L0049ecbc: { // 0x49ecbc: e87f94f9ff CALL 0x00438140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,4844737u,op); flags=s.arithmetic_flags;
  }
  L0049ecc1: { // 0x49ecc1: c744245cf85e7800 MOV dword ptr [ESP + 0x5c],0x785ef8
    m.w32((f.sp+0x0000005cu), 0x00785ef8u);
  }
  L0049ecc9: { // 0x49ecc9: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049ecd0: { // 0x49ecd0: 8b9c24ac000000 MOV EBX,dword ptr [ESP + 0xac]
    s.bx = m.r32((f.sp+0x000000acu));
  }
  L0049ecd7: { // 0x49ecd7: 8bb424b0000000 MOV ESI,dword ptr [ESP + 0xb0]
    s.si = m.r32((f.sp+0x000000b0u));
  }
  L0049ecde: { // 0x49ecde: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049ece2: { // 0x49ece2: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ece4: { // 0x49ece4: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0049ece8: { // 0x49ece8: 0f8410010000 JZ 0x0049edfe
    if(integer::condition("JZ",flags)) goto L0049edfe;
  }
  L0049ecee: { // 0x49ecee: 0fbf5106 MOVSX EDX,word ptr [ECX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0049ecf2: { // 0x49ecf2: 8b8424a8000000 MOV EAX,dword ptr [ESP + 0xa8]
    s.ax = m.r32((f.sp+0x000000a8u));
  }
  L0049ecf9: { // 0x49ecf9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ecfb: { // 0x49ecfb: 7336 JNC 0x0049ed33
    if(integer::condition("JNC",flags)) goto L0049ed33;
  }
  L0049ecfd: { // 0x49ecfd: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ed00: { // 0x49ed00: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ed04: { // 0x49ed04: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed06: { // 0x49ed06: 742b JZ 0x0049ed33
    if(integer::condition("JZ",flags)) goto L0049ed33;
  }
  L0049ed08: { // 0x49ed08: 0fbf4806 MOVSX ECX,word ptr [EAX + 0x6]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L0049ed0c: { // 0x49ed0c: 0fbf5004 MOVSX EDX,word ptr [EAX + 0x4]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L0049ed10: { // 0x49ed10: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ed11: { // 0x49ed11: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ed12: { // 0x49ed12: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L0049ed16: { // 0x49ed16: 0fbf10 MOVSX EDX,word ptr [EAX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0049ed19: { // 0x49ed19: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ed1a: { // 0x49ed1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ed1b: { // 0x49ed1b: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L0049ed1f: { // 0x49ed1f: e8accff8ff CALL 0x0042bcd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042bcd0u,4844836u,op); flags=s.arithmetic_flags;
  }
  L0049ed24: { // 0x49ed24: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049ed26: { // 0x49ed26: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0049ed28: { // 0x49ed28: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0049ed2b: { // 0x49ed2b: 8b7a08 MOV EDI,dword ptr [EDX + 0x8]
    s.di = m.r32((s.dx+0x00000008u));
  }
  L0049ed2e: { // 0x49ed2e: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0049ed31: { // 0x49ed31: eb17 JMP 0x0049ed4a
    goto L0049ed4a;
  }
  L0049ed33: { // 0x49ed33: a180ac8300 MOV EAX,[0x0083ac80]
    s.ax = m.r32((0x0083ac80u));
  }
  L0049ed38: { // 0x49ed38: 8b0d84ac8300 MOV ECX,dword ptr [0x0083ac84]
    s.cx = m.r32((0x0083ac84u));
  }
  L0049ed3e: { // 0x49ed3e: 8b3d88ac8300 MOV EDI,dword ptr [0x0083ac88]
    s.di = m.r32((0x0083ac88u));
  }
  L0049ed44: { // 0x49ed44: 8b2d8cac8300 MOV EBP,dword ptr [0x0083ac8c]
    s.bp = m.r32((0x0083ac8cu));
  }
  L0049ed4a: { // 0x49ed4a: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  L0049ed4c: { // 0x49ed4c: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0049ed50: { // 0x49ed50: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0049ed54: { // 0x49ed54: 897c2448 MOV dword ptr [ESP + 0x48],EDI
    m.w32((f.sp+0x00000048u), s.di);
  }
  L0049ed58: { // 0x49ed58: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L0049ed5c: { // 0x49ed5c: e8f6eb2c00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4844897u,op); flags=s.arithmetic_flags;
  }
  L0049ed61: { // 0x49ed61: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049ed63: { // 0x49ed63: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0049ed66: { // 0x49ed66: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049ed68: { // 0x49ed68: 747c JZ 0x0049ede6
    if(integer::condition("JZ",flags)) goto L0049ede6;
  }
  L0049ed6a: { // 0x49ed6a: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049ed71: { // 0x49ed71: 8b8424a8000000 MOV EAX,dword ptr [ESP + 0xa8]
    s.ax = m.r32((f.sp+0x000000a8u));
  }
  L0049ed78: { // 0x49ed78: 0fbf5106 MOVSX EDX,word ptr [ECX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0049ed7c: { // 0x49ed7c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ed7e: { // 0x49ed7e: 731d JNC 0x0049ed9d
    if(integer::condition("JNC",flags)) goto L0049ed9d;
  }
  L0049ed80: { // 0x49ed80: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ed83: { // 0x49ed83: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ed87: { // 0x49ed87: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed89: { // 0x49ed89: 7412 JZ 0x0049ed9d
    if(integer::condition("JZ",flags)) goto L0049ed9d;
  }
  L0049ed8b: { // 0x49ed8b: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    s.ax = m.r32((s.ax+0x00000014u));
  }
  L0049ed8e: { // 0x49ed8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed90: { // 0x49ed90: 740b JZ 0x0049ed9d
    if(integer::condition("JZ",flags)) goto L0049ed9d;
  }
  L0049ed92: { // 0x49ed92: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0049ed94: { // 0x49ed94: 898424a8000000 MOV dword ptr [ESP + 0xa8],EAX
    m.w32((f.sp+0x000000a8u), s.ax);
  }
  L0049ed9b: { // 0x49ed9b: eb0b JMP 0x0049eda8
    goto L0049eda8;
  }
  L0049ed9d: { // 0x49ed9d: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049eda8: { // 0x49eda8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049eda9: { // 0x49eda9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049edaa: { // 0x49edaa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049edac: { // 0x49edac: e89f030000 CALL 0x0049f150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049f150u,4844977u,op); flags=s.arithmetic_flags;
  }
  L0049edb1: { // 0x49edb1: 0faffd IMUL EDI,EBP
    s.di = integer::imul(s.di,s.bp,32,flags);
  }
  L0049edb4: { // 0x49edb4: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    s.cx = m.r32((f.sp+0x000000a8u));
  }
  L0049edbb: { // 0x49edbb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049edbc: { // 0x49edbc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049edbd: { // 0x49edbd: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  L0049edc0: { // 0x49edc0: c7461001000000 MOV dword ptr [ESI + 0x10],0x1
    m.w32((s.si+0x00000010u), 0x00000001u);
  }
  L0049edc7: { // 0x49edc7: e87493f9ff CALL 0x00438140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,4845004u,op); flags=s.arithmetic_flags;
  }
  L0049edcc: { // 0x49edcc: c706f85e7800 MOV dword ptr [ESI],0x785ef8
    m.w32((s.si), 0x00785ef8u);
  }
  L0049edd2: { // 0x49edd2: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049edd9: { // 0x49edd9: 89b424a8000000 MOV dword ptr [ESP + 0xa8],ESI
    m.w32((f.sp+0x000000a8u), s.si);
  }
  L0049ede0: { // 0x49ede0: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0049ede4: { // 0x49ede4: eb49 JMP 0x0049ee2f
    goto L0049ee2f;
  }
  L0049ede6: { // 0x49ede6: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0049edea: { // 0x49edea: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049edf1: { // 0x49edf1: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049edfc: { // 0x49edfc: eb31 JMP 0x0049ee2f
    goto L0049ee2f;
  }
  L0049edfe: { // 0x49edfe: 8b1580ac8300 MOV EDX,dword ptr [0x0083ac80]
    s.dx = m.r32((0x0083ac80u));
  }
  L0049ee04: { // 0x49ee04: a184ac8300 MOV EAX,[0x0083ac84]
    s.ax = m.r32((0x0083ac84u));
  }
  L0049ee09: { // 0x49ee09: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0049ee0d: { // 0x49ee0d: 8b1588ac8300 MOV EDX,dword ptr [0x0083ac88]
    s.dx = m.r32((0x0083ac88u));
  }
  L0049ee13: { // 0x49ee13: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0049ee17: { // 0x49ee17: a18cac8300 MOV EAX,[0x0083ac8c]
    s.ax = m.r32((0x0083ac8cu));
  }
  L0049ee1c: { // 0x49ee1c: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049ee27: { // 0x49ee27: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L0049ee2b: { // 0x49ee2b: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0049ee2f: { // 0x49ee2f: 8b842490000000 MOV EAX,dword ptr [ESP + 0x90]
    s.ax = m.r32((f.sp+0x00000090u));
  }
  L0049ee36: { // 0x49ee36: f6c402 TEST AH,0x2
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  L0049ee39: { // 0x49ee39: 7430 JZ 0x0049ee6b
    if(integer::condition("JZ",flags)) goto L0049ee6b;
  }
  L0049ee3b: { // 0x49ee3b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0049ee3f: { // 0x49ee3f: 8bac2488000000 MOV EBP,dword ptr [ESP + 0x88]
    s.bp = m.r32((f.sp+0x00000088u));
  }
  L0049ee46: { // 0x49ee46: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee47: { // 0x49ee47: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee49: { // 0x49ee49: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee4b: { // 0x49ee4b: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049ee4d: { // 0x49ee4d: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L0049ee4f: { // 0x49ee4f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0049ee53: { // 0x49ee53: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee54: { // 0x49ee54: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee56: { // 0x49ee56: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049ee5a: { // 0x49ee5a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee5c: { // 0x49ee5c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049ee5e: { // 0x49ee5e: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0049ee60: { // 0x49ee60: 89ac2488000000 MOV dword ptr [ESP + 0x88],EBP
    m.w32((f.sp+0x00000088u), s.bp);
  }
  L0049ee67: { // 0x49ee67: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ee6b: { // 0x49ee6b: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  L0049ee6f: { // 0x49ee6f: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L0049ee73: { // 0x49ee73: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ee75: { // 0x49ee75: 7427 JZ 0x0049ee9e
    if(integer::condition("JZ",flags)) goto L0049ee9e;
  }
  L0049ee77: { // 0x49ee77: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0049ee7b: { // 0x49ee7b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee7c: { // 0x49ee7c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee7e: { // 0x49ee7e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049ee80: { // 0x49ee80: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0049ee84: { // 0x49ee84: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee85: { // 0x49ee85: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee87: { // 0x49ee87: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee89: { // 0x49ee89: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L0049ee8b: { // 0x49ee8b: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee8d: { // 0x49ee8d: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0049ee8f: { // 0x49ee8f: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0049ee91: { // 0x49ee91: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049ee98: { // 0x49ee98: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049ee9c: { // 0x49ee9c: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0049ee9e: { // 0x49ee9e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049eea2: { // 0x49eea2: 8b9c2488000000 MOV EBX,dword ptr [ESP + 0x88]
    s.bx = m.r32((f.sp+0x00000088u));
  }
  L0049eea9: { // 0x49eea9: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L0049eeab: { // 0x49eeab: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L0049eead: { // 0x49eead: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049eeb1: { // 0x49eeb1: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0049eeb3: { // 0x49eeb3: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0049eeb5: { // 0x49eeb5: 899c2488000000 MOV dword ptr [ESP + 0x88],EBX
    m.w32((f.sp+0x00000088u), s.bx);
  }
  L0049eebc: { // 0x49eebc: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0049eec0: { // 0x49eec0: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0049eec4: { // 0x49eec4: 7473 JZ 0x0049ef39
    if(integer::condition("JZ",flags)) goto L0049ef39;
  }
  L0049eec6: { // 0x49eec6: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L0049eeca: { // 0x49eeca: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0049eece: { // 0x49eece: 8b5c243c MOV EBX,dword ptr [ESP + 0x3c]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L0049eed2: { // 0x49eed2: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0049eed4: { // 0x49eed4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049eed6: { // 0x49eed6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0049eed8: { // 0x49eed8: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0049eeda: { // 0x49eeda: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0049eede: { // 0x49eede: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049eedf: { // 0x49eedf: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049eee1: { // 0x49eee1: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0049eee5: { // 0x49eee5: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0049eee9: { // 0x49eee9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049eeea: { // 0x49eeea: 8d542454 LEA EDX,[ESP + 0x54]
    s.dx = (f.sp+0x00000054u);
  }
  L0049eeee: { // 0x49eeee: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L0049eef2: { // 0x49eef2: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0049eef6: { // 0x49eef6: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0049eefa: { // 0x49eefa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049eefb: { // 0x49eefb: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L0049eeff: { // 0x49eeff: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L0049ef03: { // 0x49ef03: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0049ef07: { // 0x49ef07: e8e40ef8ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4845324u,op); flags=s.arithmetic_flags;
  }
  L0049ef0c: { // 0x49ef0c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049ef0e: { // 0x49ef0e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0049ef10: { // 0x49ef10: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0049ef14: { // 0x49ef14: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0049ef17: { // 0x49ef17: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0049ef1b: { // 0x49ef1b: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0049ef1e: { // 0x49ef1e: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0049ef22: { // 0x49ef22: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L0049ef25: { // 0x49ef25: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef27: { // 0x49ef27: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0049ef2b: { // 0x49ef2b: 0f8e6b010000 JLE 0x0049f09c
    if(integer::condition("JLE",flags)) goto L0049f09c;
  }
  L0049ef31: { // 0x49ef31: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ef33: { // 0x49ef33: 0f8e63010000 JLE 0x0049f09c
    if(integer::condition("JLE",flags)) goto L0049f09c;
  }
  L0049ef39: { // 0x49ef39: 8b842494000000 MOV EAX,dword ptr [ESP + 0x94]
    s.ax = m.r32((f.sp+0x00000094u));
  }
  L0049ef40: { // 0x49ef40: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  L0049ef47: { // 0x49ef47: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef49: { // 0x49ef49: 7403 JZ 0x0049ef4e
    if(integer::condition("JZ",flags)) goto L0049ef4e;
  }
  L0049ef4b: { // 0x49ef4b: 83ca10 OR EDX,0x10
    s.dx = integer::logical((s.dx)|(0x00000010u),32,flags);
  }
  L0049ef4e: { // 0x49ef4e: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L0049ef55: { // 0x49ef55: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    s.ax = m.r32((f.sp+0x00000084u));
  }
  L0049ef5c: { // 0x49ef5c: 0fbf7906 MOVSX EDI,word ptr [ECX + 0x6]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0049ef60: { // 0x49ef60: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0049ef62: { // 0x49ef62: 0f83a8000000 JNC 0x0049f010
    if(integer::condition("JNC",flags)) goto L0049f010;
  }
  L0049ef68: { // 0x49ef68: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ef6b: { // 0x49ef6b: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ef6f: { // 0x49ef6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef71: { // 0x49ef71: 0f8499000000 JZ 0x0049f010
    if(integer::condition("JZ",flags)) goto L0049f010;
  }
  L0049ef77: { // 0x49ef77: 8a4008 MOV AL,byte ptr [EAX + 0x8]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000008u)));
  }
  L0049ef7a: { // 0x49ef7a: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L0049ef7c: { // 0x49ef7c: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L0049ef7e: { // 0x49ef7e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ef80: { // 0x49ef80: 0f848a000000 JZ 0x0049f010
    if(integer::condition("JZ",flags)) goto L0049f010;
  }
  L0049ef86: { // 0x49ef86: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0049ef8a: { // 0x49ef8a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ef8b: { // 0x49ef8b: e8b06bfeff CALL 0x00485b40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485b40u,4845456u,op); flags=s.arithmetic_flags;
  }
  L0049ef90: { // 0x49ef90: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef92: { // 0x49ef92: 0f8404010000 JZ 0x0049f09c
    if(integer::condition("JZ",flags)) goto L0049f09c;
  }
  L0049ef98: { // 0x49ef98: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L0049ef9f: { // 0x49ef9f: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049efa3: { // 0x49efa3: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0049efa7: { // 0x49efa7: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0049efab: { // 0x49efab: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0049efaf: { // 0x49efaf: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0049efb3: { // 0x49efb3: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0049efb7: { // 0x49efb7: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0049efbb: { // 0x49efbb: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0049efbf: { // 0x49efbf: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    s.dx = m.r32((f.sp+0x000000a8u));
  }
  L0049efc6: { // 0x49efc6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049efc7: { // 0x49efc7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049efc8: { // 0x49efc8: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    s.cx = m.r32((f.sp+0x000000a8u));
  }
  L0049efcf: { // 0x49efcf: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efd0: { // 0x49efd0: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    s.dx = m.r32((f.sp+0x000000a8u));
  }
  L0049efd7: { // 0x49efd7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049efd9: { // 0x49efd9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049efda: { // 0x49efda: 8b8c24ac000000 MOV ECX,dword ptr [ESP + 0xac]
    s.cx = m.r32((f.sp+0x000000acu));
  }
  L0049efe1: { // 0x49efe1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efe2: { // 0x49efe2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049efe3: { // 0x49efe3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049efe4: { // 0x49efe4: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0049efe8: { // 0x49efe8: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0049efec: { // 0x49efec: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efed: { // 0x49efed: 8d8c2480000000 LEA ECX,[ESP + 0x80]
    s.cx = (f.sp+0x00000080u);
  }
  L0049eff4: { // 0x49eff4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049eff5: { // 0x49eff5: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L0049eff9: { // 0x49eff9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049effa: { // 0x49effa: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0049effe: { // 0x49effe: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efff: { // 0x49efff: 8b9424bc000000 MOV EDX,dword ptr [ESP + 0xbc]
    s.dx = m.r32((f.sp+0x000000bcu));
  }
  L0049f006: { // 0x49f006: e8755ff9ff CALL 0x00434f80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434f80u,4845579u,op); flags=s.arithmetic_flags;
  }
  L0049f00b: { // 0x49f00b: e98c000000 JMP 0x0049f09c
    goto L0049f09c;
  }
  L0049f010: { // 0x49f010: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0049f014: { // 0x49f014: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f015: { // 0x49f015: e86668feff CALL 0x00485880
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485880u,4845594u,op); flags=s.arithmetic_flags;
  }
  L0049f01a: { // 0x49f01a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f01c: { // 0x49f01c: 747e JZ 0x0049f09c
    if(integer::condition("JZ",flags)) goto L0049f09c;
  }
  L0049f01e: { // 0x49f01e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049f020: { // 0x49f020: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0049f022: { // 0x49f022: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0049f026: { // 0x49f026: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L0049f02d: { // 0x49f02d: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0049f031: { // 0x49f031: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049f035: { // 0x49f035: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0049f039: { // 0x49f039: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0049f03d: { // 0x49f03d: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0049f041: { // 0x49f041: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0049f045: { // 0x49f045: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0049f049: { // 0x49f049: 8b8c24a0000000 MOV ECX,dword ptr [ESP + 0xa0]
    s.cx = m.r32((f.sp+0x000000a0u));
  }
  L0049f050: { // 0x49f050: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L0049f054: { // 0x49f054: 8b94249c000000 MOV EDX,dword ptr [ESP + 0x9c]
    s.dx = m.r32((f.sp+0x0000009cu));
  }
  L0049f05b: { // 0x49f05b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049f05d: { // 0x49f05d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f05e: { // 0x49f05e: 8b8c24a0000000 MOV ECX,dword ptr [ESP + 0xa0]
    s.cx = m.r32((f.sp+0x000000a0u));
  }
  L0049f065: { // 0x49f065: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  L0049f069: { // 0x49f069: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    s.bp = m.r32((f.sp+0x0000006cu));
  }
  L0049f06d: { // 0x49f06d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f06e: { // 0x49f06e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f06f: { // 0x49f06f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f070: { // 0x49f070: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L0049f074: { // 0x49f074: 8d442460 LEA EAX,[ESP + 0x60]
    s.ax = (f.sp+0x00000060u);
  }
  L0049f078: { // 0x49f078: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f079: { // 0x49f079: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L0049f07d: { // 0x49f07d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f07e: { // 0x49f07e: 8d542458 LEA EDX,[ESP + 0x58]
    s.dx = (f.sp+0x00000058u);
  }
  L0049f082: { // 0x49f082: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f083: { // 0x49f083: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L0049f087: { // 0x49f087: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f088: { // 0x49f088: 8b9424b0000000 MOV EDX,dword ptr [ESP + 0xb0]
    s.dx = m.r32((f.sp+0x000000b0u));
  }
  L0049f08f: { // 0x49f08f: 897c2478 MOV dword ptr [ESP + 0x78],EDI
    m.w32((f.sp+0x00000078u), s.di);
  }
  L0049f093: { // 0x49f093: 896c247c MOV dword ptr [ESP + 0x7c],EBP
    m.w32((f.sp+0x0000007cu), s.bp);
  }
  L0049f097: { // 0x49f097: e86459f9ff CALL 0x00434a00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434a00u,4845724u,op); flags=s.arithmetic_flags;
  }
  L0049f09c: { // 0x49f09c: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    s.cx = m.r32((f.sp+0x000000a8u));
  }
  L0049f0a3: { // 0x49f0a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049f0a4: { // 0x49f0a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f0a5: { // 0x49f0a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f0a6: { // 0x49f0a6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049f0a8: { // 0x49f0a8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049f0a9: { // 0x49f0a9: 7406 JZ 0x0049f0b1
    if(integer::condition("JZ",flags)) goto L0049f0b1;
  }
  L0049f0ab: { // 0x49f0ab: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049f0ad: { // 0x49f0ad: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049f0af: { // 0x49f0af: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),4845745u,op); flags=s.arithmetic_flags;
  }
  L0049f0b1: { // 0x49f0b1: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L0049f0b5: { // 0x49f0b5: e8d691f9ff CALL 0x00438290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,4845754u,op); flags=s.arithmetic_flags;
  }
  L0049f0ba: { // 0x49f0ba: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0049f0bd: { // 0x49f0bd: c23400 RET 0x34
    s.arithmetic_flags=flags; finish(m,s,f,52u); return;
  }
}

void f_0002bcd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042bcd0: { // 0x42bcd0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0042bcd4: { // 0x42bcd4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042bcd6: { // 0x42bcd6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0042bcda: { // 0x42bcda: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042bcdc: { // 0x42bcdc: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0042bce0: { // 0x42bce0: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0042bce3: { // 0x42bce3: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0042bce7: { // 0x42bce7: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0042bcea: { // 0x42bcea: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0042bced: { // 0x42bced: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_0009f150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049f150: { // 0x49f150: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0049f154: { // 0x49f154: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049f156: { // 0x49f156: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0049f15a: { // 0x49f15a: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0049f15d: { // 0x49f15d: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L0049f160: { // 0x49f160: c7400c00000000 MOV dword ptr [EAX + 0xc],0x0
    m.w32((s.ax+0x0000000cu), 0x00000000u);
  }
  L0049f167: { // 0x49f167: c7008c5f7800 MOV dword ptr [EAX],0x785f8c
    m.w32((s.ax), 0x00785f8cu);
  }
  L0049f16d: { // 0x49f16d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00038140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438140: { // 0x438140: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00438144: { // 0x438144: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00438145: { // 0x438145: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00438147: { // 0x438147: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0043814b: { // 0x43814b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043814d: { // 0x43814d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0043814f: { // 0x43814f: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00438152: { // 0x438152: c6460800 MOV byte ptr [ESI + 0x8],0x0
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  L00438156: { // 0x438156: 7513 JNZ 0x0043816b
    if(integer::condition("JNZ",flags)) goto L0043816b;
  }
  L00438158: { // 0x438158: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043815a: { // 0x43815a: 7e0f JLE 0x0043816b
    if(integer::condition("JLE",flags)) goto L0043816b;
  }
  L0043815c: { // 0x43815c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043815d: { // 0x43815d: e8f5573300 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4424034u,op); flags=s.arithmetic_flags;
  }
  L00438162: { // 0x438162: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00438165: { // 0x438165: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00438167: { // 0x438167: c6460801 MOV byte ptr [ESI + 0x8],0x1
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L0043816b: { // 0x43816b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0043816d: { // 0x43816d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043816e: { // 0x43816e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00038290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438290: { // 0x438290: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00438291: { // 0x438291: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00438293: { // 0x438293: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000008u)));
  }
  L00438296: { // 0x438296: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00438298: { // 0x438298: 740b JZ 0x004382a5
    if(integer::condition("JZ",flags)) goto L004382a5;
  }
  L0043829a: { // 0x43829a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0043829c: { // 0x43829c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043829d: { // 0x43829d: e8d9533300 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4424354u,op); flags=s.arithmetic_flags;
  }
  L004382a2: { // 0x4382a2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004382a5: { // 0x4382a5: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L004382ab: { // 0x4382ab: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L004382b2: { // 0x4382b2: c6460800 MOV byte ptr [ESI + 0x8],0x0
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  L004382b6: { // 0x4382b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004382b7: { // 0x4382b7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00085b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00485b40: { // 0x485b40: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00485b41: { // 0x485b41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00485b43: { // 0x485b43: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00485b46: { // 0x485b46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00485b48: { // 0x485b48: 7505 JNZ 0x00485b4f
    if(integer::condition("JNZ",flags)) goto L00485b4f;
  }
  L00485b4a: { // 0x485b4a: e891ddffff CALL 0x004838e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004838e0u,4741967u,op); flags=s.arithmetic_flags;
  }
  L00485b4f: { // 0x485b4f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00485b53: { // 0x485b53: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00485b55: { // 0x485b55: 7458 JZ 0x00485baf
    if(integer::condition("JZ",flags)) goto L00485baf;
  }
  L00485b57: { // 0x485b57: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485b5a: { // 0x485b5a: 7419 JZ 0x00485b75
    if(integer::condition("JZ",flags)) goto L00485b75;
  }
  L00485b5c: { // 0x485b5c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b5f: { // 0x485b5f: 740a JZ 0x00485b6b
    if(integer::condition("JZ",flags)) goto L00485b6b;
  }
  L00485b61: { // 0x485b61: 8b865c010000 MOV EAX,dword ptr [ESI + 0x15c]
    s.ax = m.r32((s.si+0x0000015cu));
  }
  L00485b67: { // 0x485b67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b68: { // 0x485b68: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b6b: { // 0x485b6b: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    s.ax = m.r32((s.si+0x00000110u));
  }
  L00485b71: { // 0x485b71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b72: { // 0x485b72: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b75: { // 0x485b75: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485b7b: { // 0x485b7b: 7419 JZ 0x00485b96
    if(integer::condition("JZ",flags)) goto L00485b96;
  }
  L00485b7d: { // 0x485b7d: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b80: { // 0x485b80: 740a JZ 0x00485b8c
    if(integer::condition("JZ",flags)) goto L00485b8c;
  }
  L00485b82: { // 0x485b82: 8b863c010000 MOV EAX,dword ptr [ESI + 0x13c]
    s.ax = m.r32((s.si+0x0000013cu));
  }
  L00485b88: { // 0x485b88: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b89: { // 0x485b89: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b8c: { // 0x485b8c: 8b86ec000000 MOV EAX,dword ptr [ESI + 0xec]
    s.ax = m.r32((s.si+0x000000ecu));
  }
  L00485b92: { // 0x485b92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b93: { // 0x485b93: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b96: { // 0x485b96: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b99: { // 0x485b99: 740a JZ 0x00485ba5
    if(integer::condition("JZ",flags)) goto L00485ba5;
  }
  L00485b9b: { // 0x485b9b: 8b8628010000 MOV EAX,dword ptr [ESI + 0x128]
    s.ax = m.r32((s.si+0x00000128u));
  }
  L00485ba1: { // 0x485ba1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ba2: { // 0x485ba2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ba5: { // 0x485ba5: 8b86d8000000 MOV EAX,dword ptr [ESI + 0xd8]
    s.ax = m.r32((s.si+0x000000d8u));
  }
  L00485bab: { // 0x485bab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bac: { // 0x485bac: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485baf: { // 0x485baf: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00485bb1: { // 0x485bb1: 83e106 AND ECX,0x6
    s.cx = integer::logical((s.cx)&(0x00000006u),32,flags);
  }
  L00485bb4: { // 0x485bb4: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bb7: { // 0x485bb7: 0f84b2010000 JZ 0x00485d6f
    if(integer::condition("JZ",flags)) goto L00485d6f;
  }
  L00485bbd: { // 0x485bbd: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc0: { // 0x485bc0: 0f8434010000 JZ 0x00485cfa
    if(integer::condition("JZ",flags)) goto L00485cfa;
  }
  L00485bc6: { // 0x485bc6: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc9: { // 0x485bc9: 0f84b6000000 JZ 0x00485c85
    if(integer::condition("JZ",flags)) goto L00485c85;
  }
  L00485bcf: { // 0x485bcf: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00485bd1: { // 0x485bd1: 742b JZ 0x00485bfe
    if(integer::condition("JZ",flags)) goto L00485bfe;
  }
  L00485bd3: { // 0x485bd3: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485bd6: { // 0x485bd6: 740a JZ 0x00485be2
    if(integer::condition("JZ",flags)) goto L00485be2;
  }
  L00485bd8: { // 0x485bd8: 8b8614010000 MOV EAX,dword ptr [ESI + 0x114]
    s.ax = m.r32((s.si+0x00000114u));
  }
  L00485bde: { // 0x485bde: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bdf: { // 0x485bdf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485be2: { // 0x485be2: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485be8: { // 0x485be8: 740a JZ 0x00485bf4
    if(integer::condition("JZ",flags)) goto L00485bf4;
  }
  L00485bea: { // 0x485bea: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  L00485bf0: { // 0x485bf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bf1: { // 0x485bf1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bf4: { // 0x485bf4: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L00485bfa: { // 0x485bfa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bfb: { // 0x485bfb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bfe: { // 0x485bfe: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L00485c00: { // 0x485c00: 742b JZ 0x00485c2d
    if(integer::condition("JZ",flags)) goto L00485c2d;
  }
  L00485c02: { // 0x485c02: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c05: { // 0x485c05: 740f JZ 0x00485c16
    if(integer::condition("JZ",flags)) goto L00485c16;
  }
  L00485c07: { // 0x485c07: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c0a: { // 0x485c0a: 7435 JZ 0x00485c41
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c0c: { // 0x485c0c: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  L00485c12: { // 0x485c12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c13: { // 0x485c13: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c16: { // 0x485c16: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c1c: { // 0x485c1c: 744e JZ 0x00485c6c
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c1e: { // 0x485c1e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c21: { // 0x485c21: 743f JZ 0x00485c62
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c23: { // 0x485c23: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00485c29: { // 0x485c29: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c2a: { // 0x485c2a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c2d: { // 0x485c2d: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c30: { // 0x485c30: 7419 JZ 0x00485c4b
    if(integer::condition("JZ",flags)) goto L00485c4b;
  }
  L00485c32: { // 0x485c32: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c35: { // 0x485c35: 740a JZ 0x00485c41
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c37: { // 0x485c37: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  L00485c3d: { // 0x485c3d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c3e: { // 0x485c3e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c41: { // 0x485c41: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L00485c47: { // 0x485c47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c48: { // 0x485c48: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c4b: { // 0x485c4b: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c51: { // 0x485c51: 7419 JZ 0x00485c6c
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c53: { // 0x485c53: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c56: { // 0x485c56: 740a JZ 0x00485c62
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c58: { // 0x485c58: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00485c5e: { // 0x485c5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c5f: { // 0x485c5f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c62: { // 0x485c62: 8b86e8000000 MOV EAX,dword ptr [ESI + 0xe8]
    s.ax = m.r32((s.si+0x000000e8u));
  }
  L00485c68: { // 0x485c68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c69: { // 0x485c69: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c6c: { // 0x485c6c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c6f: { // 0x485c6f: 740a JZ 0x00485c7b
    if(integer::condition("JZ",flags)) goto L00485c7b;
  }
  L00485c71: { // 0x485c71: 8b8624010000 MOV EAX,dword ptr [ESI + 0x124]
    s.ax = m.r32((s.si+0x00000124u));
  }
  L00485c77: { // 0x485c77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c78: { // 0x485c78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c7b: { // 0x485c7b: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  L00485c81: { // 0x485c81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c82: { // 0x485c82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c85: { // 0x485c85: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c88: { // 0x485c88: 7419 JZ 0x00485ca3
    if(integer::condition("JZ",flags)) goto L00485ca3;
  }
  L00485c8a: { // 0x485c8a: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c8d: { // 0x485c8d: 740a JZ 0x00485c99
    if(integer::condition("JZ",flags)) goto L00485c99;
  }
  L00485c8f: { // 0x485c8f: 8b8660010000 MOV EAX,dword ptr [ESI + 0x160]
    s.ax = m.r32((s.si+0x00000160u));
  }
  L00485c95: { // 0x485c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c96: { // 0x485c96: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c99: { // 0x485c99: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  L00485c9f: { // 0x485c9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ca0: { // 0x485ca0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ca3: { // 0x485ca3: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485ca9: { // 0x485ca9: 7436 JZ 0x00485ce1
    if(integer::condition("JZ",flags)) goto L00485ce1;
  }
  L00485cab: { // 0x485cab: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cad: { // 0x485cad: 7419 JZ 0x00485cc8
    if(integer::condition("JZ",flags)) goto L00485cc8;
  }
  L00485caf: { // 0x485caf: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cb2: { // 0x485cb2: 740a JZ 0x00485cbe
    if(integer::condition("JZ",flags)) goto L00485cbe;
  }
  L00485cb4: { // 0x485cb4: 8b864c010000 MOV EAX,dword ptr [ESI + 0x14c]
    s.ax = m.r32((s.si+0x0000014cu));
  }
  L00485cba: { // 0x485cba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cbb: { // 0x485cbb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cbe: { // 0x485cbe: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L00485cc4: { // 0x485cc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cc5: { // 0x485cc5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cc8: { // 0x485cc8: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ccb: { // 0x485ccb: 740a JZ 0x00485cd7
    if(integer::condition("JZ",flags)) goto L00485cd7;
  }
  L00485ccd: { // 0x485ccd: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L00485cd3: { // 0x485cd3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cd4: { // 0x485cd4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cd7: { // 0x485cd7: 8b86f4000000 MOV EAX,dword ptr [ESI + 0xf4]
    s.ax = m.r32((s.si+0x000000f4u));
  }
  L00485cdd: { // 0x485cdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cde: { // 0x485cde: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ce1: { // 0x485ce1: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ce4: { // 0x485ce4: 740a JZ 0x00485cf0
    if(integer::condition("JZ",flags)) goto L00485cf0;
  }
  L00485ce6: { // 0x485ce6: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L00485cec: { // 0x485cec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ced: { // 0x485ced: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cf0: { // 0x485cf0: 8b86dc000000 MOV EAX,dword ptr [ESI + 0xdc]
    s.ax = m.r32((s.si+0x000000dcu));
  }
  L00485cf6: { // 0x485cf6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cf7: { // 0x485cf7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cfa: { // 0x485cfa: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485cfd: { // 0x485cfd: 7419 JZ 0x00485d18
    if(integer::condition("JZ",flags)) goto L00485d18;
  }
  L00485cff: { // 0x485cff: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d02: { // 0x485d02: 740a JZ 0x00485d0e
    if(integer::condition("JZ",flags)) goto L00485d0e;
  }
  L00485d04: { // 0x485d04: 8b8664010000 MOV EAX,dword ptr [ESI + 0x164]
    s.ax = m.r32((s.si+0x00000164u));
  }
  L00485d0a: { // 0x485d0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d0b: { // 0x485d0b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d0e: { // 0x485d0e: 8b861c010000 MOV EAX,dword ptr [ESI + 0x11c]
    s.ax = m.r32((s.si+0x0000011cu));
  }
  L00485d14: { // 0x485d14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d15: { // 0x485d15: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d18: { // 0x485d18: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d1e: { // 0x485d1e: 7436 JZ 0x00485d56
    if(integer::condition("JZ",flags)) goto L00485d56;
  }
  L00485d20: { // 0x485d20: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d22: { // 0x485d22: 7419 JZ 0x00485d3d
    if(integer::condition("JZ",flags)) goto L00485d3d;
  }
  L00485d24: { // 0x485d24: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d27: { // 0x485d27: 740a JZ 0x00485d33
    if(integer::condition("JZ",flags)) goto L00485d33;
  }
  L00485d29: { // 0x485d29: 8b8650010000 MOV EAX,dword ptr [ESI + 0x150]
    s.ax = m.r32((s.si+0x00000150u));
  }
  L00485d2f: { // 0x485d2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d30: { // 0x485d30: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d33: { // 0x485d33: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  L00485d39: { // 0x485d39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d3a: { // 0x485d3a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d3d: { // 0x485d3d: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d40: { // 0x485d40: 740a JZ 0x00485d4c
    if(integer::condition("JZ",flags)) goto L00485d4c;
  }
  L00485d42: { // 0x485d42: 8b8644010000 MOV EAX,dword ptr [ESI + 0x144]
    s.ax = m.r32((s.si+0x00000144u));
  }
  L00485d48: { // 0x485d48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d49: { // 0x485d49: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d4c: { // 0x485d4c: 8b86f8000000 MOV EAX,dword ptr [ESI + 0xf8]
    s.ax = m.r32((s.si+0x000000f8u));
  }
  L00485d52: { // 0x485d52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d53: { // 0x485d53: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d56: { // 0x485d56: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d59: { // 0x485d59: 740a JZ 0x00485d65
    if(integer::condition("JZ",flags)) goto L00485d65;
  }
  L00485d5b: { // 0x485d5b: 8b8630010000 MOV EAX,dword ptr [ESI + 0x130]
    s.ax = m.r32((s.si+0x00000130u));
  }
  L00485d61: { // 0x485d61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d62: { // 0x485d62: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d65: { // 0x485d65: 8b86e0000000 MOV EAX,dword ptr [ESI + 0xe0]
    s.ax = m.r32((s.si+0x000000e0u));
  }
  L00485d6b: { // 0x485d6b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d6c: { // 0x485d6c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d6f: { // 0x485d6f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485d72: { // 0x485d72: 7419 JZ 0x00485d8d
    if(integer::condition("JZ",flags)) goto L00485d8d;
  }
  L00485d74: { // 0x485d74: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d77: { // 0x485d77: 740a JZ 0x00485d83
    if(integer::condition("JZ",flags)) goto L00485d83;
  }
  L00485d79: { // 0x485d79: 8b8668010000 MOV EAX,dword ptr [ESI + 0x168]
    s.ax = m.r32((s.si+0x00000168u));
  }
  L00485d7f: { // 0x485d7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d80: { // 0x485d80: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d83: { // 0x485d83: 8b8620010000 MOV EAX,dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L00485d89: { // 0x485d89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d8a: { // 0x485d8a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d8d: { // 0x485d8d: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d93: { // 0x485d93: 7436 JZ 0x00485dcb
    if(integer::condition("JZ",flags)) goto L00485dcb;
  }
  L00485d95: { // 0x485d95: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d97: { // 0x485d97: 7419 JZ 0x00485db2
    if(integer::condition("JZ",flags)) goto L00485db2;
  }
  L00485d99: { // 0x485d99: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d9c: { // 0x485d9c: 740a JZ 0x00485da8
    if(integer::condition("JZ",flags)) goto L00485da8;
  }
  L00485d9e: { // 0x485d9e: 8b8654010000 MOV EAX,dword ptr [ESI + 0x154]
    s.ax = m.r32((s.si+0x00000154u));
  }
  L00485da4: { // 0x485da4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485da5: { // 0x485da5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485da8: { // 0x485da8: 8b8608010000 MOV EAX,dword ptr [ESI + 0x108]
    s.ax = m.r32((s.si+0x00000108u));
  }
  L00485dae: { // 0x485dae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485daf: { // 0x485daf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485db2: { // 0x485db2: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485db5: { // 0x485db5: 740a JZ 0x00485dc1
    if(integer::condition("JZ",flags)) goto L00485dc1;
  }
  L00485db7: { // 0x485db7: 8b8648010000 MOV EAX,dword ptr [ESI + 0x148]
    s.ax = m.r32((s.si+0x00000148u));
  }
  L00485dbd: { // 0x485dbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dbe: { // 0x485dbe: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dc1: { // 0x485dc1: 8b86fc000000 MOV EAX,dword ptr [ESI + 0xfc]
    s.ax = m.r32((s.si+0x000000fcu));
  }
  L00485dc7: { // 0x485dc7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dc8: { // 0x485dc8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dcb: { // 0x485dcb: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485dce: { // 0x485dce: 740a JZ 0x00485dda
    if(integer::condition("JZ",flags)) goto L00485dda;
  }
  L00485dd0: { // 0x485dd0: 8b8634010000 MOV EAX,dword ptr [ESI + 0x134]
    s.ax = m.r32((s.si+0x00000134u));
  }
  L00485dd6: { // 0x485dd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dd7: { // 0x485dd7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dda: { // 0x485dda: 8b86e4000000 MOV EAX,dword ptr [ESI + 0xe4]
    s.ax = m.r32((s.si+0x000000e4u));
  }
  L00485de0: { // 0x485de0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485de1: { // 0x485de1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00034f80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00434f80: { // 0x434f80: 83ec68 SUB ESP,0x68
    f.sp = integer::sub(f.sp,0x00000068u,32,flags);
  }
  L00434f83: { // 0x434f83: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434f87: { // 0x434f87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434f88: { // 0x434f88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434f89: { // 0x434f89: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00434f8d: { // 0x434f8d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00434f8f: { // 0x434f8f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00434f90: { // 0x434f90: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434f91: { // 0x434f91: 8b6c247c MOV EBP,dword ptr [ESP + 0x7c]
    s.bp = m.r32((f.sp+0x0000007cu));
  }
  L00434f95: { // 0x434f95: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00434f97: { // 0x434f97: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L00434f9b: { // 0x434f9b: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00434f9e: { // 0x434f9e: 8b9c2484000000 MOV EBX,dword ptr [ESP + 0x84]
    s.bx = m.r32((f.sp+0x00000084u));
  }
  L00434fa5: { // 0x434fa5: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L00434fa9: { // 0x434fa9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434faa: { // 0x434faa: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00434fad: { // 0x434fad: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00434faf: { // 0x434faf: 894c2474 MOV dword ptr [ESP + 0x74],ECX
    m.w32((f.sp+0x00000074u), s.cx);
  }
  L00434fb3: { // 0x434fb3: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L00434fb7: { // 0x434fb7: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00434fba: { // 0x434fba: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00434fbc: { // 0x434fbc: 89542478 MOV dword ptr [ESP + 0x78],EDX
    m.w32((f.sp+0x00000078u), s.dx);
  }
  L00434fc0: { // 0x434fc0: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00434fc4: { // 0x434fc4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00434fc6: { // 0x434fc6: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00434fca: { // 0x434fca: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434fce: { // 0x434fce: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00434fd2: { // 0x434fd2: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00434fd5: { // 0x434fd5: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L00434fd9: { // 0x434fd9: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00434fdd: { // 0x434fdd: 89b4248c000000 MOV dword ptr [ESP + 0x8c],ESI
    m.w32((f.sp+0x0000008cu), s.si);
  }
  L00434fe4: { // 0x434fe4: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00434fe7: { // 0x434fe7: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L00434feb: { // 0x434feb: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L00434fef: { // 0x434fef: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L00434ff3: { // 0x434ff3: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00434ff6: { // 0x434ff6: 8b842498000000 MOV EAX,dword ptr [ESP + 0x98]
    s.ax = m.r32((f.sp+0x00000098u));
  }
  L00434ffd: { // 0x434ffd: 89542468 MOV dword ptr [ESP + 0x68],EDX
    m.w32((f.sp+0x00000068u), s.dx);
  }
  L00435001: { // 0x435001: 8d54246c LEA EDX,[ESP + 0x6c]
    s.dx = (f.sp+0x0000006cu);
  }
  L00435005: { // 0x435005: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00435008: { // 0x435008: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435009: { // 0x435009: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0043500b: { // 0x43500b: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0043500f: { // 0x43500f: 8d0cc5f8907b00 LEA ECX,[EAX*0x8 + 0x7b90f8]
    s.cx = ((s.ax * 0x00000008u)+0x007b90f8u);
  }
  L00435016: { // 0x435016: 898c2484000000 MOV dword ptr [ESP + 0x84],ECX
    m.w32((f.sp+0x00000084u), s.cx);
  }
  L0043501d: { // 0x43501d: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L00435021: { // 0x435021: e8aaba3200 CALL 0x00760ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760ad0u,4411430u,op); flags=s.arithmetic_flags;
  }
  L00435026: { // 0x435026: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00435028: { // 0x435028: 750a JNZ 0x00435034
    if(integer::condition("JNZ",flags)) goto L00435034;
  }
  L0043502a: { // 0x43502a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043502b: { // 0x43502b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043502c: { // 0x43502c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043502d: { // 0x43502d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043502e: { // 0x43502e: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L00435031: { // 0x435031: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L00435034: { // 0x435034: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L00435038: { // 0x435038: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0043503a: { // 0x43503a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L0043503d: { // 0x43503d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0043503f: { // 0x43503f: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00435043: { // 0x435043: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    s.ax = m.r32((f.sp+0x0000006cu));
  }
  L00435047: { // 0x435047: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00435049: { // 0x435049: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L0043504d: { // 0x43504d: 89842484000000 MOV dword ptr [ESP + 0x84],EAX
    m.w32((f.sp+0x00000084u), s.ax);
  }
  L00435054: { // 0x435054: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00435058: { // 0x435058: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435059: { // 0x435059: e8c2030000 CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,4411486u,op); flags=s.arithmetic_flags;
  }
  L0043505e: { // 0x43505e: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00435062: { // 0x435062: 8d542448 LEA EDX,[ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L00435066: { // 0x435066: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435067: { // 0x435067: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435068: { // 0x435068: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435069: { // 0x435069: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0043506b: { // 0x43506b: e8b0030000 CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,4411504u,op); flags=s.arithmetic_flags;
  }
  L00435070: { // 0x435070: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00435072: { // 0x435072: e889030000 CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,4411511u,op); flags=s.arithmetic_flags;
  }
  L00435077: { // 0x435077: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00435079: { // 0x435079: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0043507c: { // 0x43507c: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L0043507e: { // 0x43507e: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00435080: { // 0x435080: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00435083: { // 0x435083: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00435086: { // 0x435086: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0043508a: { // 0x43508a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0043508c: { // 0x43508c: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4411535u,op); flags=s.arithmetic_flags;
  }
  L0043508f: { // 0x43508f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435091: { // 0x435091: 89842494000000 MOV dword ptr [ESP + 0x94],EAX
    m.w32((f.sp+0x00000094u), s.ax);
  }
  L00435098: { // 0x435098: 750c JNZ 0x004350a6
    if(integer::condition("JNZ",flags)) goto L004350a6;
  }
  L0043509a: { // 0x43509a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043509c: { // 0x43509c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043509d: { // 0x43509d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043509e: { // 0x43509e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043509f: { // 0x43509f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004350a0: { // 0x4350a0: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L004350a3: { // 0x4350a3: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L004350a6: { // 0x4350a6: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L004350ac: { // 0x4350ac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004350ae: { // 0x4350ae: 0f8471010000 JZ 0x00435225
    if(integer::condition("JZ",flags)) goto L00435225;
  }
  L004350b4: { // 0x4350b4: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L004350b6: { // 0x4350b6: 8b5c2458 MOV EBX,dword ptr [ESP + 0x58]
    s.bx = m.r32((f.sp+0x00000058u));
  }
  L004350ba: { // 0x4350ba: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L004350be: { // 0x4350be: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L004350c1: { // 0x4350c1: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L004350c3: { // 0x4350c3: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004350c5: { // 0x4350c5: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L004350c7: { // 0x4350c7: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L004350ca: { // 0x4350ca: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L004350ce: { // 0x4350ce: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L004350d0: { // 0x4350d0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004350d2: { // 0x4350d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004350d3: { // 0x4350d3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004350d4: { // 0x4350d4: e8a7cb3200 CALL 0x00761c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761c80u,4411609u,op); flags=s.arithmetic_flags;
  }
  L004350d9: { // 0x4350d9: 8b1dac1f8200 MOV EBX,dword ptr [0x00821fac]
    s.bx = m.r32((0x00821facu));
  }
  L004350df: { // 0x4350df: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004350e3: { // 0x4350e3: c784248800000000000000 MOV dword ptr [ESP + 0x88],0x0
    m.w32((f.sp+0x00000088u), 0x00000000u);
  }
  L004350ee: { // 0x4350ee: 8b4328 MOV EAX,dword ptr [EBX + 0x28]
    s.ax = m.r32((s.bx+0x00000028u));
  }
  L004350f1: { // 0x4350f1: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004350f5: { // 0x4350f5: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    s.ax = m.r32((f.sp+0x0000007cu));
  }
  L004350f9: { // 0x4350f9: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L004350fc: { // 0x4350fc: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L004350ff: { // 0x4350ff: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00435103: { // 0x435103: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00435107: { // 0x435107: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435108: { // 0x435108: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0043510a: { // 0x43510a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0043510c: { // 0x43510c: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    s.ax = m.r32((f.sp+0x0000007cu));
  }
  L00435110: { // 0x435110: 8a5014 MOV DL,byte ptr [EAX + 0x14]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000014u)));
  }
  L00435113: { // 0x435113: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00435115: { // 0x435115: 0f8486000000 JZ 0x004351a1
    if(integer::condition("JZ",flags)) goto L004351a1;
  }
  L0043511b: { // 0x43511b: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0043511e: { // 0x43511e: 668b4324 MOV AX,word ptr [EBX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.bx+0x00000024u)));
  }
  L00435122: { // 0x435122: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  L00435129: { // 0x435129: 662bc6 SUB AX,SI
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L0043512c: { // 0x43512c: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00435131: { // 0x435131: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435133: { // 0x435133: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435134: { // 0x435134: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00435136: { // 0x435136: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00435138: { // 0x435138: 8b8424a0000000 MOV EAX,dword ptr [ESP + 0xa0]
    s.ax = m.r32((f.sp+0x000000a0u));
  }
  L0043513f: { // 0x43513f: 0faff1 IMUL ESI,ECX
    s.si = integer::imul(s.si,s.cx,32,flags);
  }
  L00435142: { // 0x435142: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435144: { // 0x435144: 0f84d3000000 JZ 0x0043521d
    if(integer::condition("JZ",flags)) goto L0043521d;
  }
  L0043514a: { // 0x43514a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0043514c: { // 0x43514c: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0043514e: { // 0x43514e: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00435152: { // 0x435152: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435153: { // 0x435153: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00435155: { // 0x435155: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),4411736u,op); flags=s.arithmetic_flags;
  }
  L00435158: { // 0x435158: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0043515a: { // 0x43515a: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0043515d: { // 0x43515d: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    s.cx = m.r32((s.bp+0x00000004u));
  }
  L00435160: { // 0x435160: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L00435163: { // 0x435163: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00435167: { // 0x435167: 8b9424a4000000 MOV EDX,dword ptr [ESP + 0xa4]
    s.dx = m.r32((f.sp+0x000000a4u));
  }
  L0043516e: { // 0x43516e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435170: { // 0x435170: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    s.dx = m.r32((f.sp+0x000000a8u));
  }
  L00435177: { // 0x435177: 8b6d0c MOV EBP,dword ptr [EBP + 0xc]
    s.bp = m.r32((s.bp+0x0000000cu));
  }
  L0043517a: { // 0x43517a: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043517c: { // 0x43517c: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00435180: { // 0x435180: 896c2454 MOV dword ptr [ESP + 0x54],EBP
    m.w32((f.sp+0x00000054u), s.bp);
  }
  L00435184: { // 0x435184: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435186: { // 0x435186: 8b942484000000 MOV EDX,dword ptr [ESP + 0x84]
    s.dx = m.r32((f.sp+0x00000084u));
  }
  L0043518d: { // 0x43518d: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043518f: { // 0x43518f: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00435191: { // 0x435191: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435192: { // 0x435192: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435193: { // 0x435193: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00435195: { // 0x435195: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4411800u,op); flags=s.arithmetic_flags;
  }
  L00435198: { // 0x435198: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0043519c: { // 0x43519c: e98b000000 JMP 0x0043522c
    goto L0043522c;
  }
  L004351a1: { // 0x4351a1: 668b7324 MOV SI,word ptr [EBX + 0x24]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.bx+0x00000024u))) & 0xffffu);
  }
  L004351a5: { // 0x4351a5: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  L004351ac: { // 0x4351ac: 66037304 ADD SI,word ptr [EBX + 0x4]
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),m.r16((s.bx+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351b0: { // 0x4351b0: 8b9c24a0000000 MOV EBX,dword ptr [ESP + 0xa0]
    s.bx = m.r32((f.sp+0x000000a0u));
  }
  L004351b7: { // 0x4351b7: 662b7704 SUB SI,word ptr [EDI + 0x4]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.di+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351bb: { // 0x4351bb: 662b750c SUB SI,word ptr [EBP + 0xc]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.bp+0x0000000cu)),16,flags)) & 0xffffu);
  }
  L004351bf: { // 0x4351bf: 662b7504 SUB SI,word ptr [EBP + 0x4]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.bp+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351c3: { // 0x4351c3: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004351c4: { // 0x4351c4: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L004351ca: { // 0x4351ca: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004351cc: { // 0x4351cc: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004351ce: { // 0x4351ce: 0f8578ffffff JNZ 0x0043514c
    if(integer::condition("JNZ",flags)) goto L0043514c;
  }
  L004351d4: { // 0x4351d4: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L004351d7: { // 0x4351d7: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L004351db: { // 0x4351db: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L004351de: { // 0x4351de: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L004351e0: { // 0x4351e0: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L004351e2: { // 0x4351e2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004351e4: { // 0x4351e4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351e5: { // 0x4351e5: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351e7: { // 0x4351e7: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004351e9: { // 0x4351e9: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004351eb: { // 0x4351eb: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351ec: { // 0x4351ec: 0faff1 IMUL ESI,ECX
    s.si = integer::imul(s.si,s.cx,32,flags);
  }
  L004351ef: { // 0x4351ef: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351f1: { // 0x4351f1: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L004351f3: { // 0x4351f3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004351f5: { // 0x4351f5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351f6: { // 0x4351f6: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351f8: { // 0x4351f8: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004351fc: { // 0x4351fc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004351fe: { // 0x4351fe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00435200: { // 0x435200: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00435202: { // 0x435202: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L00435209: { // 0x435209: 7512 JNZ 0x0043521d
    if(integer::condition("JNZ",flags)) goto L0043521d;
  }
  L0043520b: { // 0x43520b: 8b4c247c MOV ECX,dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L0043520f: { // 0x43520f: c784248800000000000000 MOV dword ptr [ESP + 0x88],0x0
    m.w32((f.sp+0x00000088u), 0x00000000u);
  }
  L0043521a: { // 0x43521a: 037110 ADD ESI,dword ptr [ECX + 0x10]
    s.si = integer::add(s.si,m.r32((s.cx+0x00000010u)),32,flags);
  }
  L0043521d: { // 0x43521d: c7442410c06d8300 MOV dword ptr [ESP + 0x10],0x836dc0
    m.w32((f.sp+0x00000010u), 0x00836dc0u);
  }
  L00435225: { // 0x435225: 8b9c24a0000000 MOV EBX,dword ptr [ESP + 0xa0]
    s.bx = m.r32((f.sp+0x000000a0u));
  }
  L0043522c: { // 0x43522c: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00435232: { // 0x435232: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00435234: { // 0x435234: 7435 JZ 0x0043526b
    if(integer::condition("JZ",flags)) goto L0043526b;
  }
  L00435236: { // 0x435236: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00435238: { // 0x435238: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L0043523c: { // 0x43523c: 8b7f04 MOV EDI,dword ptr [EDI + 0x4]
    s.di = m.r32((s.di+0x00000004u));
  }
  L0043523f: { // 0x43523f: 8b6904 MOV EBP,dword ptr [ECX + 0x4]
    s.bp = m.r32((s.cx+0x00000004u));
  }
  L00435242: { // 0x435242: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00435244: { // 0x435244: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L00435248: { // 0x435248: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0043524a: { // 0x43524a: 898424a8000000 MOV dword ptr [ESP + 0xa8],EAX
    m.w32((f.sp+0x000000a8u), s.ax);
  }
  L00435251: { // 0x435251: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00435253: { // 0x435253: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435254: { // 0x435254: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435255: { // 0x435255: e8d6bffdff CALL 0x00411230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4411994u,op); flags=s.arithmetic_flags;
  }
  L0043525a: { // 0x43525a: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00435260: { // 0x435260: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00435264: { // 0x435264: 8b5128 MOV EDX,dword ptr [ECX + 0x28]
    s.dx = m.r32((s.cx+0x00000028u));
  }
  L00435267: { // 0x435267: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0043526b: { // 0x43526b: 8bac2480000000 MOV EBP,dword ptr [ESP + 0x80]
    s.bp = m.r32((f.sp+0x00000080u));
  }
  L00435272: { // 0x435272: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00435274: { // 0x435274: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00435276: { // 0x435276: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435277: { // 0x435277: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0043527a: { // 0x43527a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043527b: { // 0x43527b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0043527d: { // 0x43527d: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4412032u,op); flags=s.arithmetic_flags;
  }
  L00435280: { // 0x435280: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00435282: { // 0x435282: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00435284: { // 0x435284: 7515 JNZ 0x0043529b
    if(integer::condition("JNZ",flags)) goto L0043529b;
  }
  L00435286: { // 0x435286: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043528a: { // 0x43528a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0043528c: { // 0x43528c: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4412047u,op); flags=s.arithmetic_flags;
  }
  L0043528f: { // 0x43528f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00435291: { // 0x435291: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00435292: { // 0x435292: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00435293: { // 0x435293: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00435294: { // 0x435294: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00435295: { // 0x435295: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L00435298: { // 0x435298: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L0043529b: { // 0x43529b: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    s.ax = m.r32((f.sp+0x00000084u));
  }
  L004352a2: { // 0x4352a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004352a4: { // 0x4352a4: 7e0a JLE 0x004352b0
    if(integer::condition("JLE",flags)) goto L004352b0;
  }
  L004352a6: { // 0x4352a6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004352a8: { // 0x4352a8: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L004352ab: { // 0x4352ab: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L004352ad: { // 0x4352ad: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004352ae: { // 0x4352ae: 75f6 JNZ 0x004352a6
    if(integer::condition("JNZ",flags)) goto L004352a6;
  }
  L004352b0: { // 0x4352b0: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004352b4: { // 0x4352b4: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004352b6: { // 0x4352b6: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4412089u,op); flags=s.arithmetic_flags;
  }
  L004352b9: { // 0x4352b9: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L004352bd: { // 0x4352bd: 89842490000000 MOV dword ptr [ESP + 0x90],EAX
    m.w32((f.sp+0x00000090u), s.ax);
  }
  L004352c4: { // 0x4352c4: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L004352c8: { // 0x4352c8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004352ca: { // 0x4352ca: 7c02 JL 0x004352ce
    if(integer::condition("JL",flags)) goto L004352ce;
  }
  L004352cc: { // 0x4352cc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004352ce: { // 0x4352ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004352d0: { // 0x4352d0: 0f8efe000000 JLE 0x004353d4
    if(integer::condition("JLE",flags)) goto L004353d4;
  }
  L004352d6: { // 0x4352d6: 898424a0000000 MOV dword ptr [ESP + 0xa0],EAX
    m.w32((f.sp+0x000000a0u), s.ax);
  }
  L004352dd: { // 0x4352dd: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004352e1: { // 0x4352e1: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L004352e5: { // 0x4352e5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004352e6: { // 0x4352e6: 8b94249c000000 MOV EDX,dword ptr [ESP + 0x9c]
    s.dx = m.r32((f.sp+0x0000009cu));
  }
  L004352ed: { // 0x4352ed: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004352ef: { // 0x4352ef: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004352f0: { // 0x4352f0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L004352f4: { // 0x4352f4: 8b8c2498000000 MOV ECX,dword ptr [ESP + 0x98]
    s.cx = m.r32((f.sp+0x00000098u));
  }
  L004352fb: { // 0x4352fb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004352fc: { // 0x4352fc: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00435300: { // 0x435300: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00435301: { // 0x435301: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435302: { // 0x435302: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00435304: { // 0x435304: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435305: { // 0x435305: 8b94248c000000 MOV EDX,dword ptr [ESP + 0x8c]
    s.dx = m.r32((f.sp+0x0000008cu));
  }
  L0043530c: { // 0x43530c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043530d: { // 0x43530d: 8d5702 LEA EDX,[EDI + 0x2]
    s.dx = (s.di+0x00000002u);
  }
  L00435310: { // 0x435310: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435311: { // 0x435311: 8b9424b8000000 MOV EDX,dword ptr [ESP + 0xb8]
    s.dx = m.r32((f.sp+0x000000b8u));
  }
  L00435318: { // 0x435318: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435319: { // 0x435319: ff5004 CALL dword ptr [EAX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000004u)),4412188u,op); flags=s.arithmetic_flags;
  }
  L0043531c: { // 0x43531c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043531e: { // 0x43531e: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00435321: { // 0x435321: 8b8c2490000000 MOV ECX,dword ptr [ESP + 0x90]
    s.cx = m.r32((f.sp+0x00000090u));
  }
  L00435328: { // 0x435328: 8b942494000000 MOV EDX,dword ptr [ESP + 0x94]
    s.dx = m.r32((f.sp+0x00000094u));
  }
  L0043532f: { // 0x43532f: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00435331: { // 0x435331: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00435336: { // 0x435336: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00435338: { // 0x435338: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043533a: { // 0x43533a: 89942494000000 MOV dword ptr [ESP + 0x94],EDX
    m.w32((f.sp+0x00000094u), s.dx);
  }
  L00435341: { // 0x435341: 7475 JZ 0x004353b8
    if(integer::condition("JZ",flags)) goto L004353b8;
  }
  L00435343: { // 0x435343: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00435347: { // 0x435347: 8d4c5500 LEA ECX,[EBP + EDX*0x2]
    s.cx = (s.bp+(s.dx * 0x00000002u));
  }
  L0043534b: { // 0x43534b: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L0043534e: { // 0x43534e: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00435350: { // 0x435350: 7203 JC 0x00435355
    if(integer::condition("JC",flags)) goto L00435355;
  }
  L00435352: { // 0x435352: 2b4820 SUB ECX,dword ptr [EAX + 0x20]
    s.cx = integer::sub(s.cx,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00435355: { // 0x435355: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00435357: { // 0x435357: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0043535b: { // 0x43535b: 7410 JZ 0x0043536d
    if(integer::condition("JZ",flags)) goto L0043536d;
  }
  L0043535d: { // 0x43535d: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00435361: { // 0x435361: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00435365: { // 0x435365: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00435367: { // 0x435367: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0043536b: { // 0x43536b: eb2e JMP 0x0043539b
    goto L0043539b;
  }
  L0043536d: { // 0x43536d: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  L00435374: { // 0x435374: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L00435378: { // 0x435378: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0043537c: { // 0x43537c: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0043537e: { // 0x43537e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00435380: { // 0x435380: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L00435387: { // 0x435387: 7c12 JL 0x0043539b
    if(integer::condition("JL",flags)) goto L0043539b;
  }
  L00435389: { // 0x435389: 8b54247c MOV EDX,dword ptr [ESP + 0x7c]
    s.dx = m.r32((f.sp+0x0000007cu));
  }
  L0043538d: { // 0x43538d: 8b6a10 MOV EBP,dword ptr [EDX + 0x10]
    s.bp = m.r32((s.dx+0x00000010u));
  }
  L00435390: { // 0x435390: 03f5 ADD ESI,EBP
    s.si = integer::add(s.si,s.bp,32,flags);
  }
  L00435392: { // 0x435392: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00435394: { // 0x435394: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L0043539b: { // 0x43539b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0043539f: { // 0x43539f: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004353a3: { // 0x4353a3: 8d0448 LEA EAX,[EAX + ECX*0x2]
    s.ax = (s.ax+(s.cx * 0x00000002u));
  }
  L004353a6: { // 0x4353a6: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L004353ac: { // 0x4353ac: 3b411c CMP EAX,dword ptr [ECX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L004353af: { // 0x4353af: 7203 JC 0x004353b4
    if(integer::condition("JC",flags)) goto L004353b4;
  }
  L004353b1: { // 0x4353b1: 2b4120 SUB EAX,dword ptr [ECX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L004353b4: { // 0x4353b4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004353b8: { // 0x4353b8: 8b8424a0000000 MOV EAX,dword ptr [ESP + 0xa0]
    s.ax = m.r32((f.sp+0x000000a0u));
  }
  L004353bf: { // 0x4353bf: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004353c0: { // 0x4353c0: 898424a0000000 MOV dword ptr [ESP + 0xa0],EAX
    m.w32((f.sp+0x000000a0u), s.ax);
  }
  L004353c7: { // 0x4353c7: 0f8510ffffff JNZ 0x004352dd
    if(integer::condition("JNZ",flags)) goto L004352dd;
  }
  L004353cd: { // 0x4353cd: 8bac2480000000 MOV EBP,dword ptr [ESP + 0x80]
    s.bp = m.r32((f.sp+0x00000080u));
  }
  L004353d4: { // 0x4353d4: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004353d8: { // 0x4353d8: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004353da: { // 0x4353da: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4412381u,op); flags=s.arithmetic_flags;
  }
  L004353dd: { // 0x4353dd: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L004353e0: { // 0x4353e0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004353e2: { // 0x4353e2: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4412389u,op); flags=s.arithmetic_flags;
  }
  L004353e5: { // 0x4353e5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004353e7: { // 0x4353e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004353e8: { // 0x4353e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004353e9: { // 0x4353e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004353ea: { // 0x4353ea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004353eb: { // 0x4353eb: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L004353ee: { // 0x4353ee: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
}

void f_000895f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004895f0: { // 0x4895f0: 8b542410 MOV EDX, DWORD PTR [ESP + 0X10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004895f4: { // 0x4895f4: 8b442404 MOV EAX, DWORD PTR [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004895f8: { // 0x4895f8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004895f9: { // 0x4895f9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004895fa: { // 0x4895fa: 8b742410 MOV ESI, DWORD PTR [ESP + 0X10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L004895fe: { // 0x4895fe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004895ff: { // 0x4895ff: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00489601: { // 0x489601: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L00489603: { // 0x489603: 7e22 JLE 0X489627
    if(integer::condition("JLE",flags)) goto L00489627;
  }
  L00489605: { // 0x489605: 8a0e MOV CL, BYTE PTR [ESI]
    s.cx = with_al(s.cx, m.r8((s.si)));
  }
  L00489607: { // 0x489607: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00489608: { // 0x489608: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0048960a: { // 0x48960a: 7509 JNE 0X489615
    if(integer::condition("JNZ",flags)) goto L00489615;
  }
  L0048960c: { // 0x48960c: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0048960e: { // 0x48960e: 8a0e MOV CL, BYTE PTR [ESI]
    s.cx = with_al(s.cx, m.r8((s.si)));
  }
  L00489610: { // 0x489610: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00489612: { // 0x489612: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00489613: { // 0x489613: eb01 JMP 0X489616
    goto L00489616;
  }
  L00489615: { // 0x489615: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00489616: { // 0x489616: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00489618: { // 0x489618: 7feb JG 0X489605
    if(integer::condition("JG",flags)) goto L00489605;
  }
  L0048961a: { // 0x48961a: 8b7c2418 MOV EDI, DWORD PTR [ESP + 0X18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L0048961e: { // 0x48961e: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00489620: { // 0x489620: 2bfa SUB EDI, EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L00489622: { // 0x489622: 8d0450 LEA EAX, [EAX + EDX*2]
    s.ax = (s.ax+(s.dx * 2u));
  }
  L00489625: { // 0x489625: eb04 JMP 0X48962B
    goto L0048962b;
  }
  L00489627: { // 0x489627: 8b7c2418 MOV EDI, DWORD PTR [ESP + 0X18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L0048962b: { // 0x48962b: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0048962d: { // 0x48962d: 7e40 JLE 0X48966F
    if(integer::condition("JLE",flags)) goto L0048966f;
  }
  L0048962f: { // 0x48962f: 8a16 MOV DL, BYTE PTR [ESI]
    s.dx = with_al(s.dx, m.r8((s.si)));
  }
  L00489631: { // 0x489631: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00489632: { // 0x489632: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00489634: { // 0x489634: 88542418 MOV BYTE PTR [ESP + 0X18], DL
    m.w8((f.sp+0x00000018u), (s.dx & 0xffu));
  }
  L00489638: { // 0x489638: 7518 JNE 0X489652
    if(integer::condition("JNZ",flags)) goto L00489652;
  }
  L0048963a: { // 0x48963a: 8a16 MOV DL, BYTE PTR [ESI]
    s.dx = with_al(s.dx, m.r8((s.si)));
  }
  L0048963c: { // 0x48963c: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0048963d: { // 0x48963d: 88542418 MOV BYTE PTR [ESP + 0X18], DL
    m.w8((f.sp+0x00000018u), (s.dx & 0xffu));
  }
  L00489641: { // 0x489641: 8b542418 MOV EDX, DWORD PTR [ESP + 0X18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00489645: { // 0x489645: 81e2ff000000 AND EDX, 0XFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0048964b: { // 0x48964b: 2bfa SUB EDI, EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0048964d: { // 0x48964d: 8d0450 LEA EAX, [EAX + EDX*2]
    s.ax = (s.ax+(s.dx * 2u));
  }
  L00489650: { // 0x489650: eb19 JMP 0X48966B
    goto L0048966b;
  }
  L00489652: { // 0x489652: 8b4c2418 MOV ECX, DWORD PTR [ESP + 0X18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00489656: { // 0x489656: 8b5504 MOV EDX, DWORD PTR [EBP + 4]
    s.dx = m.r32((s.bp+4u));
  }
  L00489659: { // 0x489659: 81e1ff000000 AND ECX, 0XFF
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L0048965f: { // 0x48965f: 83c002 ADD EAX, 2
    s.ax = integer::add(s.ax,2u,32,flags);
  }
  L00489662: { // 0x489662: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00489663: { // 0x489663: 668b0c4a MOV CX, WORD PTR [EDX + ECX*2]
    s.cx = with_ax(s.cx, m.r16((s.dx+(s.cx * 2u))));
  }
  L00489667: { // 0x489667: 668948fe MOV WORD PTR [EAX - 2], CX
    m.w16((s.ax-2u), (s.cx & 0xffffu));
  }
  L0048966b: { // 0x48966b: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0048966d: { // 0x48966d: 7fc0 JG 0X48962F
    if(integer::condition("JG",flags)) goto L0048962f;
  }
  L0048966f: { // 0x48966f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00489670: { // 0x489670: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00489671: { // 0x489671: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00489672: { // 0x489672: c22800 RET 0X28
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
}

void f_002279d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006279d0: { // 0x6279d0: a001f78100 MOV AL,[0x0081f701]
    s.ax = with_al(s.ax, m.r8((0x0081f701u)));
  }
  L006279d5: { // 0x6279d5: 81eca8000000 SUB ESP,0xa8
    f.sp = integer::sub(f.sp,0x000000a8u,32,flags);
  }
  L006279db: { // 0x6279db: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006279dd: { // 0x6279dd: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006279de: { // 0x6279de: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006279df: { // 0x6279df: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006279e1: { // 0x6279e1: 0f8455030000 JZ 0x00627d3c
    if(integer::condition("JZ",flags)) goto L00627d3c;
  }
  L006279e7: { // 0x6279e7: 8b97e0110000 MOV EDX,dword ptr [EDI + 0x11e0]
    s.dx = m.r32((s.di+0x000011e0u));
  }
  L006279ed: { // 0x6279ed: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006279ef: { // 0x6279ef: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006279f1: { // 0x6279f1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006279f2: { // 0x6279f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006279f3: { // 0x6279f3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006279f4: { // 0x6279f4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006279f5: { // 0x6279f5: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L006279fa: { // 0x6279fa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006279fb: { // 0x6279fb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006279fc: { // 0x6279fc: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00627a00: { // 0x627a00: 8b97e8110000 MOV EDX,dword ptr [EDI + 0x11e8]
    s.dx = m.r32((s.di+0x000011e8u));
  }
  L00627a06: { // 0x627a06: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627a07: { // 0x627a07: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627a08: { // 0x627a08: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627a0e: { // 0x627a0e: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L00627a12: { // 0x627a12: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L00627a16: { // 0x627a16: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00627a18: { // 0x627a18: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627a19: { // 0x627a19: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),6453788u,op); flags=s.arithmetic_flags;
  }
  L00627a1c: { // 0x627a1c: 8b0de8dfa900 MOV ECX,dword ptr [0x00a9dfe8]
    s.cx = m.r32((0x00a9dfe8u));
  }
  L00627a22: { // 0x627a22: 8b150ca78100 MOV EDX,dword ptr [0x0081a70c]
    s.dx = m.r32((0x0081a70cu));
  }
  L00627a28: { // 0x627a28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627a29: { // 0x627a29: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L00627a2d: { // 0x627a2d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627a2e: { // 0x627a2e: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  L00627a30: { // 0x627a30: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627a31: { // 0x627a31: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627a37: { // 0x627a37: e89471e7ff CALL 0x0049ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049ebd0u,6453820u,op); flags=s.arithmetic_flags;
  }
  L00627a3c: { // 0x627a3c: 8bb7f0110000 MOV ESI,dword ptr [EDI + 0x11f0]
    s.si = m.r32((s.di+0x000011f0u));
  }
  L00627a42: { // 0x627a42: 8b97ec110000 MOV EDX,dword ptr [EDI + 0x11ec]
    s.dx = m.r32((s.di+0x000011ecu));
  }
  L00627a48: { // 0x627a48: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00627a4b: { // 0x627a4b: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L00627a4f: { // 0x627a4f: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  L00627a51: { // 0x627a51: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00627a53: { // 0x627a53: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00627a58: { // 0x627a58: b9a8347c00 MOV ECX,0x7c34a8
    s.cx = 0x007c34a8u;
  }
  L00627a5d: { // 0x627a5d: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00627a61: { // 0x627a61: e87a320300 CALL 0x0065ace0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065ace0u,6453862u,op); flags=s.arithmetic_flags;
  }
  L00627a66: { // 0x627a66: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627a6c: { // 0x627a6c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627a6d: { // 0x627a6d: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00627a71: { // 0x627a71: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00627a73: { // 0x627a73: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627a74: { // 0x627a74: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00627a78: { // 0x627a78: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627a79: { // 0x627a79: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),6453884u,op); flags=s.arithmetic_flags;
  }
  L00627a7c: { // 0x627a7c: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627a82: { // 0x627a82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627a83: { // 0x627a83: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627a84: { // 0x627a84: 68ae040000 PUSH 0x4ae
    f.push(m,0x000004aeu);
  }
  L00627a89: { // 0x627a89: 68807f7d00 PUSH 0x7d7f80
    f.push(m,0x007d7f80u);
  }
  L00627a8e: { // 0x627a8e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00627a90: { // 0x627a90: b9707f7d00 MOV ECX,0x7d7f70
    s.cx = 0x007d7f70u;
  }
  L00627a95: { // 0x627a95: e8c6700c00 CALL 0x006eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,6453914u,op); flags=s.arithmetic_flags;
  }
  L00627a9a: { // 0x627a9a: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00627a9e: { // 0x627a9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627a9f: { // 0x627a9f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627aa0: { // 0x627aa0: e87bfee6ff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,6453925u,op); flags=s.arithmetic_flags;
  }
  L00627aa5: { // 0x627aa5: 8b87f4110000 MOV EAX,dword ptr [EDI + 0x11f4]
    s.ax = m.r32((s.di+0x000011f4u));
  }
  L00627aab: { // 0x627aab: 8b8fec110000 MOV ECX,dword ptr [EDI + 0x11ec]
    s.cx = m.r32((s.di+0x000011ecu));
  }
  L00627ab1: { // 0x627ab1: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00627ab4: { // 0x627ab4: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L00627ab8: { // 0x627ab8: 8d5408fe LEA EDX,[EAX + ECX*0x1 + -0x2]
    s.dx = (s.ax+(s.cx * 0x00000001u)-0x00000002u);
  }
  L00627abc: { // 0x627abc: b9a8347c00 MOV ECX,0x7c34a8
    s.cx = 0x007c34a8u;
  }
  L00627ac1: { // 0x627ac1: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L00627ac5: { // 0x627ac5: 6819020000 PUSH 0x219
    f.push(m,0x00000219u);
  }
  L00627aca: { // 0x627aca: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00627acc: { // 0x627acc: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00627ad1: { // 0x627ad1: e80a320300 CALL 0x0065ace0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065ace0u,6453974u,op); flags=s.arithmetic_flags;
  }
  L00627ad6: { // 0x627ad6: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627adc: { // 0x627adc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627add: { // 0x627add: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00627ae1: { // 0x627ae1: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00627ae3: { // 0x627ae3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627ae4: { // 0x627ae4: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00627ae8: { // 0x627ae8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627ae9: { // 0x627ae9: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),6453996u,op); flags=s.arithmetic_flags;
  }
  L00627aec: { // 0x627aec: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627af2: { // 0x627af2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627af3: { // 0x627af3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627af4: { // 0x627af4: 68b0040000 PUSH 0x4b0
    f.push(m,0x000004b0u);
  }
  L00627af9: { // 0x627af9: 68807f7d00 PUSH 0x7d7f80
    f.push(m,0x007d7f80u);
  }
  L00627afe: { // 0x627afe: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00627b00: { // 0x627b00: b9607f7d00 MOV ECX,0x7d7f60
    s.cx = 0x007d7f60u;
  }
  L00627b05: { // 0x627b05: e856700c00 CALL 0x006eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,6454026u,op); flags=s.arithmetic_flags;
  }
  L00627b0a: { // 0x627b0a: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00627b0e: { // 0x627b0e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627b0f: { // 0x627b0f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627b10: { // 0x627b10: e80bfee6ff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,6454037u,op); flags=s.arithmetic_flags;
  }
  L00627b15: { // 0x627b15: a10ca78100 MOV EAX,[0x0081a70c]
    s.ax = m.r32((0x0081a70cu));
  }
  L00627b1a: { // 0x627b1a: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00627b1d: { // 0x627b1d: 83c607 ADD ESI,0x7
    s.si = integer::add(s.si,0x00000007u,32,flags);
  }
  L00627b20: { // 0x627b20: 83780401 CMP dword ptr [EAX + 0x4],0x1
    (void)integer::sub(m.r32((s.ax+0x00000004u)),0x00000001u,32,flags);
  }
  L00627b24: { // 0x627b24: 750d JNZ 0x00627b33
    if(integer::condition("JNZ",flags)) goto L00627b33;
  }
  L00627b26: { // 0x627b26: 8b8074010000 MOV EAX,dword ptr [EAX + 0x174]
    s.ax = m.r32((s.ax+0x00000174u));
  }
  L00627b2c: { // 0x627b2c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00627b2e: { // 0x627b2e: 8a500e MOV DL,byte ptr [EAX + 0xe]
    s.dx = with_al(s.dx, m.r8((s.ax+0x0000000eu)));
  }
  L00627b31: { // 0x627b31: eb0c JMP 0x00627b3f
    goto L00627b3f;
  }
  L00627b33: { // 0x627b33: 8b8874010000 MOV ECX,dword ptr [EAX + 0x174]
    s.cx = m.r32((s.ax+0x00000174u));
  }
  L00627b39: { // 0x627b39: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00627b3b: { // 0x627b3b: 668b511c MOV DX,word ptr [ECX + 0x1c]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x0000001cu)));
  }
  L00627b3f: { // 0x627b3f: 8b87ec110000 MOV EAX,dword ptr [EDI + 0x11ec]
    s.ax = m.r32((s.di+0x000011ecu));
  }
  L00627b45: { // 0x627b45: 8b8ff4110000 MOV ECX,dword ptr [EDI + 0x11f4]
    s.cx = m.r32((s.di+0x000011f4u));
  }
  L00627b4b: { // 0x627b4b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627b4c: { // 0x627b4c: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L00627b50: { // 0x627b50: 8d4c08ff LEA ECX,[EAX + ECX*0x1 + -0x1]
    s.cx = (s.ax+(s.cx * 0x00000001u)-0x00000001u);
  }
  L00627b54: { // 0x627b54: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627b55: { // 0x627b55: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00627b59: { // 0x627b59: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627b5f: { // 0x627b5f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00627b63: { // 0x627b63: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00627b67: { // 0x627b67: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L00627b6b: { // 0x627b6b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00627b6d: { // 0x627b6d: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00627b71: { // 0x627b71: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627b72: { // 0x627b72: ff5030 CALL dword ptr [EAX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000030u)),6454133u,op); flags=s.arithmetic_flags;
  }
  L00627b75: { // 0x627b75: 8b0dd8a5a100 MOV ECX,dword ptr [0x00a1a5d8]
    s.cx = m.r32((0x00a1a5d8u));
  }
  L00627b7b: { // 0x627b7b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L00627b7e: { // 0x627b7e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00627b80: { // 0x627b80: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00627b82: { // 0x627b82: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00627b86: { // 0x627b86: 0f8eb0010000 JLE 0x00627d3c
    if(integer::condition("JLE",flags)) goto L00627d3c;
  }
  L00627b8c: { // 0x627b8c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00627b8d: { // 0x627b8d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00627b8e: { // 0x627b8e: 8b0dcca5a100 MOV ECX,dword ptr [0x00a1a5cc]
    s.cx = m.r32((0x00a1a5ccu));
  }
  L00627b94: { // 0x627b94: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00627b97: { // 0x627b97: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00627b99: { // 0x627b99: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00627b9d: { // 0x627b9d: 0f8484010000 JZ 0x00627d27
    if(integer::condition("JZ",flags)) goto L00627d27;
  }
  L00627ba3: { // 0x627ba3: 8b5134 MOV EDX,dword ptr [ECX + 0x34]
    s.dx = m.r32((s.cx+0x00000034u));
  }
  L00627ba6: { // 0x627ba6: 8a9aa5010000 MOV BL,byte ptr [EDX + 0x1a5]
    s.bx = with_al(s.bx, m.r8((s.dx+0x000001a5u)));
  }
  L00627bac: { // 0x627bac: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00627bae: { // 0x627bae: 0f8473010000 JZ 0x00627d27
    if(integer::condition("JZ",flags)) goto L00627d27;
  }
  L00627bb4: { // 0x627bb4: 8a913d010000 MOV DL,byte ptr [ECX + 0x13d]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000013du)));
  }
  L00627bba: { // 0x627bba: 8b81405f0100 MOV EAX,dword ptr [ECX + 0x15f40]
    s.ax = m.r32((s.cx+0x00015f40u));
  }
  L00627bc0: { // 0x627bc0: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00627bc2: { // 0x627bc2: 741c JZ 0x00627be0
    if(integer::condition("JZ",flags)) goto L00627be0;
  }
  L00627bc4: { // 0x627bc4: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00627bc9: { // 0x627bc9: b9a8347c00 MOV ECX,0x7c34a8
    s.cx = 0x007c34a8u;
  }
  L00627bce: { // 0x627bce: e80d310300 CALL 0x0065ace0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065ace0u,6454227u,op); flags=s.arithmetic_flags;
  }
  L00627bd3: { // 0x627bd3: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00627bd7: { // 0x627bd7: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00627bd9: { // 0x627bd9: bd19000000 MOV EBP,0x19
    s.bp = 0x00000019u;
  }
  L00627bde: { // 0x627bde: eb0e JMP 0x00627bee
    goto L00627bee;
  }
  L00627be0: { // 0x627be0: 8b1504eaa900 MOV EDX,dword ptr [0x00a9ea04]
    s.dx = m.r32((0x00a9ea04u));
  }
  L00627be6: { // 0x627be6: bd19400000 MOV EBP,0x4019
    s.bp = 0x00004019u;
  }
  L00627beb: { // 0x627beb: 8b1c82 MOV EBX,dword ptr [EDX + EAX*0x4]
    s.bx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00627bee: { // 0x627bee: 81c1165f0100 ADD ECX,0x15f16
    s.cx = integer::add(s.cx,0x00015f16u,32,flags);
  }
  L00627bf4: { // 0x627bf4: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00627bf8: { // 0x627bf8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627bf9: { // 0x627bf9: 68344d7c00 PUSH 0x7c4d34
    f.push(m,0x007c4d34u);
  }
  L00627bfe: { // 0x627bfe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627bff: { // 0x627bff: 66c74424540000 MOV word ptr [ESP + 0x54],0x0
    m.w16((f.sp+0x00000054u), 0x00000000u);
  }
  L00627c06: { // 0x627c06: e899741400 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,6454283u,op); flags=s.arithmetic_flags;
  }
  L00627c0b: { // 0x627c0b: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L00627c0f: { // 0x627c0f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627c10: { // 0x627c10: e830731400 CALL 0x0076ef45
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef45u,6454293u,op); flags=s.arithmetic_flags;
  }
  L00627c15: { // 0x627c15: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00627c18: { // 0x627c18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00627c1a: { // 0x627c1a: 7512 JNZ 0x00627c2e
    if(integer::condition("JNZ",flags)) goto L00627c2e;
  }
  L00627c1c: { // 0x627c1c: 8d542448 LEA EDX,[ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L00627c20: { // 0x627c20: 684c7f7d00 PUSH 0x7d7f4c
    f.push(m,0x007d7f4cu);
  }
  L00627c25: { // 0x627c25: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627c26: { // 0x627c26: e89e731400 CALL 0x0076efc9
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076efc9u,6454315u,op); flags=s.arithmetic_flags;
  }
  L00627c2b: { // 0x627c2b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00627c2e: { // 0x627c2e: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00627c32: { // 0x627c32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627c33: { // 0x627c33: e80d731400 CALL 0x0076ef45
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef45u,6454328u,op); flags=s.arithmetic_flags;
  }
  L00627c38: { // 0x627c38: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00627c3b: { // 0x627c3b: 83f812 CMP EAX,0x12
    (void)integer::sub(s.ax,0x00000012u,32,flags);
  }
  L00627c3e: { // 0x627c3e: 760e JBE 0x00627c4e
    if(integer::condition("JBE",flags)) goto L00627c4e;
  }
  L00627c40: { // 0x627c40: 66c744246c2e00 MOV word ptr [ESP + 0x6c],0x2e
    m.w16((f.sp+0x0000006cu), 0x0000002eu);
  }
  L00627c47: { // 0x627c47: 66c744246e0000 MOV word ptr [ESP + 0x6e],0x0
    m.w16((f.sp+0x0000006eu), 0x00000000u);
  }
  L00627c4e: { // 0x627c4e: 8b8fec110000 MOV ECX,dword ptr [EDI + 0x11ec]
    s.cx = m.r32((s.di+0x000011ecu));
  }
  L00627c54: { // 0x627c54: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00627c55: { // 0x627c55: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00627c59: { // 0x627c59: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627c5f: { // 0x627c5f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00627c61: { // 0x627c61: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00627c65: { // 0x627c65: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00627c66: { // 0x627c66: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627c67: { // 0x627c67: 8974243c MOV dword ptr [ESP + 0x3c],ESI
    m.w32((f.sp+0x0000003cu), s.si);
  }
  L00627c6b: { // 0x627c6b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00627c6d: { // 0x627c6d: 8d9424b8000000 LEA EDX,[ESP + 0xb8]
    s.dx = (f.sp+0x000000b8u);
  }
  L00627c74: { // 0x627c74: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627c75: { // 0x627c75: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),6454392u,op); flags=s.arithmetic_flags;
  }
  L00627c78: { // 0x627c78: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627c79: { // 0x627c79: a1881c8200 MOV EAX,[0x00821c88]
    s.ax = m.r32((0x00821c88u));
  }
  L00627c7e: { // 0x627c7e: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L00627c82: { // 0x627c82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627c83: { // 0x627c83: 8d542458 LEA EDX,[ESP + 0x58]
    s.dx = (f.sp+0x00000058u);
  }
  L00627c87: { // 0x627c87: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627c88: { // 0x627c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627c89: { // 0x627c89: e892fce6ff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,6454414u,op); flags=s.arithmetic_flags;
  }
  L00627c8e: { // 0x627c8e: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00627c92: { // 0x627c92: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00627c95: { // 0x627c95: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00627c97: { // 0x627c97: 0510530000 ADD EAX,0x5310
    s.ax = integer::add(s.ax,0x00005310u,32,flags);
  }
  L00627c9c: { // 0x627c9c: c744241814000000 MOV dword ptr [ESP + 0x18],0x14
    m.w32((f.sp+0x00000018u), 0x00000014u);
  }
  L00627ca4: { // 0x627ca4: 8b5054 MOV EDX,dword ptr [EAX + 0x54]
    s.dx = m.r32((s.ax+0x00000054u));
  }
  L00627ca7: { // 0x627ca7: 0310 ADD EDX,dword ptr [EAX]
    s.dx = integer::add(s.dx,m.r32((s.ax)),32,flags);
  }
  L00627ca9: { // 0x627ca9: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00627cac: { // 0x627cac: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00627cae: { // 0x627cae: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00627cb2: { // 0x627cb2: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00627cb3: { // 0x627cb3: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00627cb7: { // 0x627cb7: 75eb JNZ 0x00627ca4
    if(integer::condition("JNZ",flags)) goto L00627ca4;
  }
  L00627cb9: { // 0x627cb9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627cba: { // 0x627cba: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L00627cbe: { // 0x627cbe: 68447f7d00 PUSH 0x7d7f44
    f.push(m,0x007d7f44u);
  }
  L00627cc3: { // 0x627cc3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627cc4: { // 0x627cc4: e8db731400 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,6454473u,op); flags=s.arithmetic_flags;
  }
  L00627cc9: { // 0x627cc9: 8b8ff4110000 MOV ECX,dword ptr [EDI + 0x11f4]
    s.cx = m.r32((s.di+0x000011f4u));
  }
  L00627ccf: { // 0x627ccf: 8b97ec110000 MOV EDX,dword ptr [EDI + 0x11ec]
    s.dx = m.r32((s.di+0x000011ecu));
  }
  L00627cd5: { // 0x627cd5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00627cd8: { // 0x627cd8: 81cd00020000 OR EBP,0x200
    s.bp = integer::logical((s.bp)|(0x00000200u),32,flags);
  }
  L00627cde: { // 0x627cde: 8d4411fe LEA EAX,[ECX + EDX*0x1 + -0x2]
    s.ax = (s.cx+(s.dx * 0x00000001u)-0x00000002u);
  }
  L00627ce2: { // 0x627ce2: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00627ce6: { // 0x627ce6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00627ce7: { // 0x627ce7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00627ce9: { // 0x627ce9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00627cea: { // 0x627cea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627ceb: { // 0x627ceb: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627cf1: { // 0x627cf1: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00627cf5: { // 0x627cf5: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L00627cf9: { // 0x627cf9: 8d8424a8000000 LEA EAX,[ESP + 0xa8]
    s.ax = (f.sp+0x000000a8u);
  }
  L00627d00: { // 0x627d00: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00627d02: { // 0x627d02: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627d03: { // 0x627d03: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),6454534u,op); flags=s.arithmetic_flags;
  }
  L00627d06: { // 0x627d06: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  L00627d0c: { // 0x627d0c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627d0d: { // 0x627d0d: 8d54245c LEA EDX,[ESP + 0x5c]
    s.dx = (f.sp+0x0000005cu);
  }
  L00627d11: { // 0x627d11: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00627d12: { // 0x627d12: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00627d16: { // 0x627d16: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00627d17: { // 0x627d17: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627d18: { // 0x627d18: e803fce6ff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,6454557u,op); flags=s.arithmetic_flags;
  }
  L00627d1d: { // 0x627d1d: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00627d21: { // 0x627d21: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00627d24: { // 0x627d24: 83c609 ADD ESI,0x9
    s.si = integer::add(s.si,0x00000009u,32,flags);
  }
  L00627d27: { // 0x627d27: 8b0dd8a5a100 MOV ECX,dword ptr [0x00a1a5d8]
    s.cx = m.r32((0x00a1a5d8u));
  }
  L00627d2d: { // 0x627d2d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00627d2e: { // 0x627d2e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00627d30: { // 0x627d30: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00627d34: { // 0x627d34: 0f8c54feffff JL 0x00627b8e
    if(integer::condition("JL",flags)) goto L00627b8e;
  }
  L00627d3a: { // 0x627d3a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00627d3b: { // 0x627d3b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00627d3c: { // 0x627d3c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00627d3d: { // 0x627d3d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00627d3e: { // 0x627d3e: 81c4a8000000 ADD ESP,0xa8
    f.sp = integer::add(f.sp,0x000000a8u,32,flags);
  }
  L00627d44: { // 0x627d44: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002eeb60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006eeb60: { // 0x6eeb60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006eeb61: { // 0x6eeb61: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006eeb62: { // 0x6eeb62: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L006eeb64: { // 0x6eeb64: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006eeb66: { // 0x6eeb66: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006eeb68: { // 0x6eeb68: 7406 JZ 0x006eeb70
    if(integer::condition("JZ",flags)) goto L006eeb70;
  }
  L006eeb6a: { // 0x6eeb6a: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L006eeb70: { // 0x6eeb70: a1c07eab00 MOV EAX,[0x00ab7ec0]
    s.ax = m.r32((0x00ab7ec0u));
  }
  L006eeb75: { // 0x6eeb75: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eeb77: { // 0x6eeb77: 750a JNZ 0x006eeb83
    if(integer::condition("JNZ",flags)) goto L006eeb83;
  }
  L006eeb79: { // 0x6eeb79: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eeb7a: { // 0x6eeb7a: b808277e00 MOV EAX,0x7e2708
    s.ax = 0x007e2708u;
  }
  L006eeb7f: { // 0x6eeb7f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006eeb80: { // 0x6eeb80: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L006eeb83: { // 0x6eeb83: 8b0db87eab00 MOV ECX,dword ptr [0x00ab7eb8]
    s.cx = m.r32((0x00ab7eb8u));
  }
  L006eeb89: { // 0x6eeb89: 6860d87600 PUSH 0x76d860
    f.push(m,0x0076d860u);
  }
  L006eeb8e: { // 0x6eeb8e: 6a28 PUSH 0x28
    f.push(m,0x00000028u);
  }
  L006eeb90: { // 0x6eeb90: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006eeb91: { // 0x6eeb91: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006eeb92: { // 0x6eeb92: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006eeb93: { // 0x6eeb93: e8cded0700 CALL 0x0076d965
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d965u,7269272u,op); flags=s.arithmetic_flags;
  }
  L006eeb98: { // 0x6eeb98: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006eeb9b: { // 0x6eeb9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eeb9d: { // 0x6eeb9d: 7423 JZ 0x006eebc2
    if(integer::condition("JZ",flags)) goto L006eebc2;
  }
  L006eeb9f: { // 0x6eeb9f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006eeba1: { // 0x6eeba1: 740e JZ 0x006eebb1
    if(integer::condition("JZ",flags)) goto L006eebb1;
  }
  L006eeba3: { // 0x6eeba3: 8b5024 MOV EDX,dword ptr [EAX + 0x24]
    s.dx = m.r32((s.ax+0x00000024u));
  }
  L006eeba6: { // 0x6eeba6: 8b0dc87eab00 MOV ECX,dword ptr [0x00ab7ec8]
    s.cx = m.r32((0x00ab7ec8u));
  }
  L006eebac: { // 0x6eebac: 8b1491 MOV EDX,dword ptr [ECX + EDX*0x4]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L006eebaf: { // 0x6eebaf: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L006eebb1: { // 0x6eebb1: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L006eebb4: { // 0x6eebb4: 8b0dc47eab00 MOV ECX,dword ptr [0x00ab7ec4]
    s.cx = m.r32((0x00ab7ec4u));
  }
  L006eebba: { // 0x6eebba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eebbb: { // 0x6eebbb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006eebbc: { // 0x6eebbc: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006eebbf: { // 0x6eebbf: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L006eebc2: { // 0x6eebc2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006eebc3: { // 0x6eebc3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006eebc4: { // 0x6eebc4: 6808020000 PUSH 0x208
    f.push(m,0x00000208u);
  }
  L006eebc9: { // 0x6eebc9: e889ed0700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7269326u,op); flags=s.arithmetic_flags;
  }
  L006eebce: { // 0x6eebce: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L006eebd2: { // 0x6eebd2: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L006eebd6: { // 0x6eebd6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006eebd8: { // 0x6eebd8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006eebd9: { // 0x6eebd9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006eebda: { // 0x6eebda: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006eebdb: { // 0x6eebdb: 8d7e04 LEA EDI,[ESI + 0x4]
    s.di = (s.si+0x00000004u);
  }
  L006eebde: { // 0x6eebde: 68ec267e00 PUSH 0x7e26ec
    f.push(m,0x007e26ecu);
  }
  L006eebe3: { // 0x6eebe3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006eebe4: { // 0x6eebe4: e8bb040800 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,7269353u,op); flags=s.arithmetic_flags;
  }
  L006eebe9: { // 0x6eebe9: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L006eebed: { // 0x6eebed: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006eebee: { // 0x6eebee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006eebef: { // 0x6eebef: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006eebf0: { // 0x6eebf0: 68c0267e00 PUSH 0x7e26c0
    f.push(m,0x007e26c0u);
  }
  L006eebf5: { // 0x6eebf5: e8f67cd1ff CALL 0x004068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,7269370u,op); flags=s.arithmetic_flags;
  }
  L006eebfa: { // 0x6eebfa: 8b0dd47eab00 MOV ECX,dword ptr [0x00ab7ed4]
    s.cx = m.r32((0x00ab7ed4u));
  }
  L006eec00: { // 0x6eec00: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L006eec03: { // 0x6eec03: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006eec05: { // 0x6eec05: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L006eec07: { // 0x6eec07: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006eec08: { // 0x6eec08: 8935d47eab00 MOV dword ptr [0x00ab7ed4],ESI
    m.w32((0x00ab7ed4u), s.si);
  }
  L006eec0e: { // 0x6eec0e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006eec0f: { // 0x6eec0f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eec10: { // 0x6eec10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006eec11: { // 0x6eec11: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_0036d965(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076d965: { // 0x76d965: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076d966: { // 0x76d966: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076d968: { // 0x76d968: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0076d96b: { // 0x76d96b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076d96c: { // 0x76d96c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076d96d: { // 0x76d96d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076d96e: { // 0x76d96e: 8d78ff LEA EDI,[EAX + -0x1]
    s.di = (s.ax-0x00000001u);
  }
  L0076d971: { // 0x76d971: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0076d974: { // 0x76d974: 0faf7d14 IMUL EDI,dword ptr [EBP + 0x14]
    s.di = integer::imul(s.di,m.r32((s.bp+0x00000014u)),32,flags);
  }
  L0076d978: { // 0x76d978: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0076d97a: { // 0x76d97a: 894d0c MOV dword ptr [EBP + 0xc],ECX
    m.w32((s.bp+0x0000000cu), s.cx);
  }
  L0076d97d: { // 0x76d97d: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0076d97f: { // 0x76d97f: 774b JA 0x0076d9cc
    if(integer::condition("JA",flags)) goto L0076d9cc;
  }
  L0076d981: { // 0x76d981: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076d983: { // 0x76d983: d1eb SHR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0076d985: { // 0x76d985: 7450 JZ 0x0076d9d7
    if(integer::condition("JZ",flags)) goto L0076d9d7;
  }
  L0076d987: { // 0x76d987: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0076d98a: { // 0x76d98a: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0076d98c: { // 0x76d98c: 83651001 AND dword ptr [EBP + 0x10],0x1
    m.w32((s.bp+0x00000010u), integer::logical((m.r32((s.bp+0x00000010u)))&(0x00000001u),32,flags));
  }
  L0076d990: { // 0x76d990: 7503 JNZ 0x0076d995
    if(integer::condition("JNZ",flags)) goto L0076d995;
  }
  L0076d992: { // 0x76d992: 8d43ff LEA EAX,[EBX + -0x1]
    s.ax = (s.bx-0x00000001u);
  }
  L0076d995: { // 0x76d995: 0faf4514 IMUL EAX,dword ptr [EBP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((s.bp+0x00000014u)),32,flags);
  }
  L0076d999: { // 0x76d999: 03450c ADD EAX,dword ptr [EBP + 0xc]
    s.ax = integer::add(s.ax,m.r32((s.bp+0x0000000cu)),32,flags);
  }
  L0076d99c: { // 0x76d99c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0076d99e: { // 0x76d99e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076d99f: { // 0x76d99f: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  L0076d9a2: { // 0x76d9a2: ff5518 CALL dword ptr [EBP + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000018u)),7788965u,op); flags=s.arithmetic_flags;
  }
  L0076d9a5: { // 0x76d9a5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d9a6: { // 0x76d9a6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076d9a8: { // 0x76d9a8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d9a9: { // 0x76d9a9: 7428 JZ 0x0076d9d3
    if(integer::condition("JZ",flags)) goto L0076d9d3;
  }
  L0076d9ab: { // 0x76d9ab: 7d10 JGE 0x0076d9bd
    if(integer::condition("JGE",flags)) goto L0076d9bd;
  }
  L0076d9ad: { // 0x76d9ad: 2b7514 SUB ESI,dword ptr [EBP + 0x14]
    s.si = integer::sub(s.si,m.r32((s.bp+0x00000014u)),32,flags);
  }
  L0076d9b0: { // 0x76d9b0: 837d1000 CMP dword ptr [EBP + 0x10],0x0
    (void)integer::sub(m.r32((s.bp+0x00000010u)),0x00000000u,32,flags);
  }
  L0076d9b4: { // 0x76d9b4: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0076d9b6: { // 0x76d9b6: 750d JNZ 0x0076d9c5
    if(integer::condition("JNZ",flags)) goto L0076d9c5;
  }
  L0076d9b8: { // 0x76d9b8: 8d43ff LEA EAX,[EBX + -0x1]
    s.ax = (s.bx-0x00000001u);
  }
  L0076d9bb: { // 0x76d9bb: eb0a JMP 0x0076d9c7
    goto L0076d9c7;
  }
  L0076d9bd: { // 0x76d9bd: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L0076d9c0: { // 0x76d9c0: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0076d9c2: { // 0x76d9c2: 89750c MOV dword ptr [EBP + 0xc],ESI
    m.w32((s.bp+0x0000000cu), s.si);
  }
  L0076d9c5: { // 0x76d9c5: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0076d9c7: { // 0x76d9c7: 397d0c CMP dword ptr [EBP + 0xc],EDI
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.di,32,flags);
  }
  L0076d9ca: { // 0x76d9ca: 76b5 JBE 0x0076d981
    if(integer::condition("JBE",flags)) goto L0076d981;
  }
  L0076d9cc: { // 0x76d9cc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076d9ce: { // 0x76d9ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076d9cf: { // 0x76d9cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076d9d0: { // 0x76d9d0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076d9d1: { // 0x76d9d1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076d9d2: { // 0x76d9d2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076d9d3: { // 0x76d9d3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0076d9d5: { // 0x76d9d5: ebf7 JMP 0x0076d9ce
    goto L0076d9ce;
  }
  L0076d9d7: { // 0x76d9d7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076d9d9: { // 0x76d9d9: 74f1 JZ 0x0076d9cc
    if(integer::condition("JZ",flags)) goto L0076d9cc;
  }
  L0076d9db: { // 0x76d9db: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L0076d9de: { // 0x76d9de: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  L0076d9e1: { // 0x76d9e1: ff5518 CALL dword ptr [EBP + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000018u)),7789028u,op); flags=s.arithmetic_flags;
  }
  L0076d9e4: { // 0x76d9e4: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0076d9e6: { // 0x76d9e6: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0076d9e8: { // 0x76d9e8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d9e9: { // 0x76d9e9: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L0076d9eb: { // 0x76d9eb: 23450c AND EAX,dword ptr [EBP + 0xc]
    s.ax = integer::logical((s.ax)&(m.r32((s.bp+0x0000000cu))),32,flags);
  }
  L0076d9ee: { // 0x76d9ee: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d9ef: { // 0x76d9ef: ebdd JMP 0x0076d9ce
    goto L0076d9ce;
  }
}

void f_0036d860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076d860: { // 0x76d860: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076d861: { // 0x76d861: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076d863: { // 0x76d863: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076d864: { // 0x76d864: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076d865: { // 0x76d865: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076d866: { // 0x76d866: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076d869: { // 0x76d869: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0076d86c: { // 0x76d86c: 8d052805b100 LEA EAX,[0xb10528]
    s.ax = (0x00b10528u);
  }
  L0076d872: { // 0x76d872: 83780800 CMP dword ptr [EAX + 0x8],0x0
    (void)integer::sub(m.r32((s.ax+0x00000008u)),0x00000000u,32,flags);
  }
  L0076d876: { // 0x76d876: 753b JNZ 0x0076d8b3
    if(integer::condition("JNZ",flags)) goto L0076d8b3;
  }
  L0076d878: { // 0x76d878: b0ff MOV AL,0xff
    s.ax = with_al(s.ax, 0x000000ffu);
  }
  L0076d87a: { // 0x76d87a: 8bff MOV EDI,EDI
    s.di = s.di;
  }
  L0076d87c: { // 0x76d87c: 0ac0 OR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L0076d87e: { // 0x76d87e: 742e JZ 0x0076d8ae
    if(integer::condition("JZ",flags)) goto L0076d8ae;
  }
  L0076d880: { // 0x76d880: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076d882: { // 0x76d882: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076d883: { // 0x76d883: 8a27 MOV AH,byte ptr [EDI]
    s.ax = (s.ax & 0xffff00ffu) | (((m.r8((s.di))) & 0xffu) << 8);
  }
  L0076d885: { // 0x76d885: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076d886: { // 0x76d886: 38c4 CMP AH,AL
    (void)integer::sub(((s.ax >> 8) & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0076d888: { // 0x76d888: 74f2 JZ 0x0076d87c
    if(integer::condition("JZ",flags)) goto L0076d87c;
  }
  L0076d88a: { // 0x76d88a: 2c41 SUB AL,0x41
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d88c: { // 0x76d88c: 3c1a CMP AL,0x1a
    (void)integer::sub((s.ax & 0xffu),0x0000001au,8,flags);
  }
  L0076d88e: { // 0x76d88e: 1ac9 SBB CL,CL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.cx & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d890: { // 0x76d890: 80e120 AND CL,0x20
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags));
  }
  L0076d893: { // 0x76d893: 02c1 ADD AL,CL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L0076d895: { // 0x76d895: 0441 ADD AL,0x41
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d897: { // 0x76d897: 86e0 XCHG AL,AH
    s.ax=(s.ax&0xffff0000u)|((s.ax&0xffu)<<8)|((s.ax>>8)&0xffu);
    s.ax = s.ax;
  }
  L0076d899: { // 0x76d899: 2c41 SUB AL,0x41
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d89b: { // 0x76d89b: 3c1a CMP AL,0x1a
    (void)integer::sub((s.ax & 0xffu),0x0000001au,8,flags);
  }
  L0076d89d: { // 0x76d89d: 1ac9 SBB CL,CL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.cx & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d89f: { // 0x76d89f: 80e120 AND CL,0x20
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags));
  }
  L0076d8a2: { // 0x76d8a2: 02c1 ADD AL,CL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L0076d8a4: { // 0x76d8a4: 0441 ADD AL,0x41
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d8a6: { // 0x76d8a6: 38e0 CMP AL,AH
    (void)integer::sub((s.ax & 0xffu),((s.ax >> 8) & 0xffu),8,flags);
  }
  L0076d8a8: { // 0x76d8a8: 74d2 JZ 0x0076d87c
    if(integer::condition("JZ",flags)) goto L0076d87c;
  }
  L0076d8aa: { // 0x76d8aa: 1ac0 SBB AL,AL
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),(s.ax & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d8ac: { // 0x76d8ac: 1cff SBB AL,0xff
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x000000ffu,8,flags,flags&integer::CF));
  }
  L0076d8ae: { // 0x76d8ae: 0fbec0 MOVSX EAX,AL
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffu),8));
  }
  L0076d8b1: { // 0x76d8b1: eb78 JMP 0x0076d92b
    goto L0076d92b;
  }
  L0076d8b3: { // 0x76d8b3: f0ff05240eb100 INC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("unqualified nonzero-locale LOCK branch");
    s.ax = s.ax;
  }
  L0076d8ba: { // 0x76d8ba: 833d200eb10000 CMP dword ptr [0x00b10e20],0x0
    (void)integer::sub(m.r32((0x00b10e20u)),0x00000000u,32,flags);
  }
  L0076d8c1: { // 0x76d8c1: 7f04 JG 0x0076d8c7
    if(integer::condition("JG",flags)) goto L0076d8c7;
  }
  L0076d8c3: { // 0x76d8c3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0076d8c5: { // 0x76d8c5: eb15 JMP 0x0076d8dc
    goto L0076d8dc;
  }
  L0076d8c7: { // 0x76d8c7: f0ff0d240eb100 DEC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("unqualified nonzero-locale LOCK branch");
    s.ax = s.ax;
  }
  L0076d8ce: { // 0x76d8ce: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076d8d0: { // 0x76d8d0: e8e13c0000 CALL 0x007715b6
    s.arithmetic_flags=flags; invoke(m,s,f,0x007715b6u,7788757u,op); flags=s.arithmetic_flags;
  }
  L0076d8d5: { // 0x76d8d5: c7042401000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L0076d8dc: { // 0x76d8dc: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L0076d8e1: { // 0x76d8e1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0076d8e3: { // 0x76d8e3: 90 NOP
    s.ax = s.ax;
  }
  L0076d8e4: { // 0x76d8e4: 0ac0 OR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L0076d8e6: { // 0x76d8e6: 7427 JZ 0x0076d90f
    if(integer::condition("JZ",flags)) goto L0076d90f;
  }
  L0076d8e8: { // 0x76d8e8: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076d8ea: { // 0x76d8ea: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076d8eb: { // 0x76d8eb: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0076d8ed: { // 0x76d8ed: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076d8ee: { // 0x76d8ee: 38d8 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L0076d8f0: { // 0x76d8f0: 74f2 JZ 0x0076d8e4
    if(integer::condition("JZ",flags)) goto L0076d8e4;
  }
  L0076d8f2: { // 0x76d8f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076d8f3: { // 0x76d8f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076d8f4: { // 0x76d8f4: e8aa220000 CALL 0x0076fba3
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076fba3u,7788793u,op); flags=s.arithmetic_flags;
  }
  L0076d8f9: { // 0x76d8f9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076d8fb: { // 0x76d8fb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d8fe: { // 0x76d8fe: e8a0220000 CALL 0x0076fba3
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076fba3u,7788803u,op); flags=s.arithmetic_flags;
  }
  L0076d903: { // 0x76d903: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d906: { // 0x76d906: 38c3 CMP BL,AL
    (void)integer::sub((s.bx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0076d908: { // 0x76d908: 74da JZ 0x0076d8e4
    if(integer::condition("JZ",flags)) goto L0076d8e4;
  }
  L0076d90a: { // 0x76d90a: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0076d90c: { // 0x76d90c: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L0076d90f: { // 0x76d90f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076d911: { // 0x76d911: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0076d912: { // 0x76d912: 0bc0 OR EAX,EAX
    s.ax = integer::logical((s.ax)|(s.ax),32,flags);
  }
  L0076d914: { // 0x76d914: 7509 JNZ 0x0076d91f
    if(integer::condition("JNZ",flags)) goto L0076d91f;
  }
  L0076d916: { // 0x76d916: f0ff0d240eb100 DEC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("unqualified nonzero-locale LOCK branch");
    s.ax = s.ax;
  }
  L0076d91d: { // 0x76d91d: eb0a JMP 0x0076d929
    goto L0076d929;
  }
  L0076d91f: { // 0x76d91f: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076d921: { // 0x76d921: e8f13c0000 CALL 0x00771617
    s.arithmetic_flags=flags; invoke(m,s,f,0x00771617u,7788838u,op); flags=s.arithmetic_flags;
  }
  L0076d926: { // 0x76d926: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d929: { // 0x76d929: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0076d92b: { // 0x76d92b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076d92c: { // 0x76d92c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076d92d: { // 0x76d92d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076d92e: { // 0x76d92e: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076d92f: { // 0x76d92f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 need(op.api,"explicit finite SetRect provider");f.push(m,continuation);Frame child{f.sp,f.sp,continuation};auto arg=[&](unsigned n){return m.r32(child.entry_sp+4+4*n);};
 if(target==op.api->set_rect_address()){
  need(target==m.r32(0x7854a8),"actual SetRect IAT binding");const unsigned out=arg(0),l=arg(1),t=arg(2),r=arg(3),b=arg(4);
  need(op.frame_high>=16&&out>=op.frame_low&&out<=op.frame_high-16,"actual owned private SetRect output");
  s.ax=op.api->set_rect(out,l,t,r,b,s.fp);need(s.ax==1,"actual SetRect TRUE");
  need(m.r32(out)==l&&m.r32(out+4)==t&&m.r32(out+8)==r&&m.r32(out+12)==b,"actual SetRect output bytes");finish(m,s,child,20);f.sp=child.sp;return;
 }
 switch(target){
case 0x497920u:f_00097920(m,s,child,op);break;
case 0x497610u:f_00097610(m,s,child,op);break;
case 0x4112c0u:f_000112c0(m,s,child,op);break;
case 0x4112d0u:f_000112d0(m,s,child,op);break;
case 0x4112f0u:f_000112f0(m,s,child,op);break;
case 0x411370u:f_00011370(m,s,child,op);break;
case 0x4113b0u:f_000113b0(m,s,child,op);break;
case 0x4113c0u:f_000113c0(m,s,child,op);break;
case 0x4312f0u:f_000312f0(m,s,child,op);break;
case 0x431310u:f_00031310(m,s,child,op);break;
case 0x431320u:f_00031320(m,s,child,op);break;
case 0x431370u:f_00031370(m,s,child,op);break;
case 0x431790u:f_00031790(m,s,child,op);break;
case 0x4317a0u:f_000317a0(m,s,child,op);break;
case 0x431b80u:f_00031b80(m,s,child,op);break;
case 0x431ec0u:f_00031ec0(m,s,child,op);break;
case 0x431f70u:f_00031f70(m,s,child,op);break;
case 0x432010u:f_00032010(m,s,child,op);break;
case 0x432210u:f_00032210(m,s,child,op);break;
case 0x497830u:f_00097830(m,s,child,op);break;
case 0x65ace0u:f_0025ace0(m,s,child,op);break;
case 0x4fe550u:f_000fe550(m,s,child,op);break;
case 0x760ad0u:f_00360ad0(m,s,child,op);break;
case 0x435420u:f_00035420(m,s,child,op);break;
case 0x435400u:f_00035400(m,s,child,op);break;
case 0x411290u:f_00011290(m,s,child,op);break;
case 0x41fdf0u:f_0001fdf0(m,s,child,op);break;
case 0x760f60u:f_00360f60(m,s,child,op);break;
case 0x76aa50u:f_0036aa50(m,s,child,op);break;
case 0x75f2c0u:f_0035f2c0(m,s,child,op);break;
case 0x75f290u:f_0035f290(m,s,child,op);break;
case 0x49ebd0u:f_0009ebd0(m,s,child,op);break;
case 0x42bcd0u:f_0002bcd0(m,s,child,op);break;
case 0x49f150u:f_0009f150(m,s,child,op);break;
case 0x438140u:f_00038140(m,s,child,op);break;
case 0x438290u:f_00038290(m,s,child,op);break;
case 0x485b40u:f_00085b40(m,s,child,op);break;
case 0x434f80u:f_00034f80(m,s,child,op);break;
case 0x4895f0u:f_000895f0(m,s,child,op);break;
case 0x6279d0u:f_002279d0(m,s,child,op);break;
case 0x6eeb60u:f_002eeb60(m,s,child,op);break;
case 0x76d965u:f_0036d965(m,s,child,op);break;
case 0x76d860u:f_0036d860(m,s,child,op);break;
case 0x76f398:{
 // Existing B1646/B1648 ordinary-digit Source implementation, with its exact
 // finite guard. Native Original evidence remains a separate full CRT closure.
 const unsigned digit=m.r16(arg(1));
 if(digit<0x30||digit>0x39||m.r16(arg(1)+2)!=0)throw std::domain_error("ordinary one-digit formatter domain");
 const unsigned out=arg(0);if(out<op.frame_low||out>op.frame_high-4)throw std::domain_error("formatter output must be an owned private buffer");
 m.w16(out,digit);m.w16(out+2,0);s.ax=1;finish(m,s,child,0);break;
 }
 default:throw std::domain_error("B1652 excluded call/branch");}f.sp=child.sp;}

// Read-only finite postproducer projection guards. This does not construct or initialize objects.
void guard_context(Memory&m,unsigned c,unsigned lut){need(m.r32(c)==0x788f70&&m.r32(c+4)==2&&m.r32(c+0x16c)==1&&m.r32(c+0x170)==lut&&m.r32(c+0x174)==lut&&m.r32(c+0x178)==0&&m.r32(c+0x17c)==0&&m.r32(c+0x180)==0x7bef&&m.r32(c+0x184)==0x39e7,"normal N1 two-byte392context");std::array<unsigned,91>a{};
a[0]=m.r32(c+8u);need(a[0]!=0,"normal context descriptor pointer");
a[1]=m.r32(c+12u);need(a[1]!=0,"normal context descriptor pointer");
a[2]=m.r32(c+20u);need(a[2]!=0,"normal context descriptor pointer");
a[3]=m.r32(c+16u);need(a[3]!=0,"normal context descriptor pointer");
a[4]=m.r32(c+24u);need(a[4]!=0,"normal context descriptor pointer");
a[5]=m.r32(c+28u);need(a[5]!=0,"normal context descriptor pointer");
a[6]=m.r32(c+32u);need(a[6]!=0,"normal context descriptor pointer");
a[7]=m.r32(c+36u);need(a[7]!=0,"normal context descriptor pointer");
a[8]=m.r32(c+40u);need(a[8]!=0,"normal context descriptor pointer");
a[9]=m.r32(c+48u);need(a[9]!=0,"normal context descriptor pointer");
a[10]=m.r32(c+44u);need(a[10]!=0,"normal context descriptor pointer");
a[11]=m.r32(c+52u);need(a[11]!=0,"normal context descriptor pointer");
a[12]=m.r32(c+56u);need(a[12]!=0,"normal context descriptor pointer");
a[13]=m.r32(c+60u);need(a[13]!=0,"normal context descriptor pointer");
a[14]=m.r32(c+64u);need(a[14]!=0,"normal context descriptor pointer");
a[15]=m.r32(c+68u);need(a[15]!=0,"normal context descriptor pointer");
a[16]=m.r32(c+72u);need(a[16]!=0,"normal context descriptor pointer");
a[17]=m.r32(c+76u);need(a[17]!=0,"normal context descriptor pointer");
a[18]=m.r32(c+80u);need(a[18]!=0,"normal context descriptor pointer");
a[19]=m.r32(c+88u);need(a[19]!=0,"normal context descriptor pointer");
a[20]=m.r32(c+84u);need(a[20]!=0,"normal context descriptor pointer");
a[21]=m.r32(c+92u);need(a[21]!=0,"normal context descriptor pointer");
a[22]=m.r32(c+96u);need(a[22]!=0,"normal context descriptor pointer");
a[23]=m.r32(c+100u);need(a[23]!=0,"normal context descriptor pointer");
a[24]=m.r32(c+104u);need(a[24]!=0,"normal context descriptor pointer");
a[27]=m.r32(c+108u);need(a[27]!=0,"normal context descriptor pointer");
a[28]=m.r32(c+112u);need(a[28]!=0,"normal context descriptor pointer");
a[29]=m.r32(c+116u);need(a[29]!=0,"normal context descriptor pointer");
a[30]=m.r32(c+120u);need(a[30]!=0,"normal context descriptor pointer");
a[31]=m.r32(c+124u);need(a[31]!=0,"normal context descriptor pointer");
a[32]=m.r32(c+128u);need(a[32]!=0,"normal context descriptor pointer");
a[33]=m.r32(c+132u);need(a[33]!=0,"normal context descriptor pointer");
a[34]=m.r32(c+136u);need(a[34]!=0,"normal context descriptor pointer");
a[35]=m.r32(c+140u);need(a[35]!=0,"normal context descriptor pointer");
a[36]=m.r32(c+144u);need(a[36]!=0,"normal context descriptor pointer");
a[37]=m.r32(c+148u);need(a[37]!=0,"normal context descriptor pointer");
a[38]=m.r32(c+152u);need(a[38]!=0,"normal context descriptor pointer");
a[39]=m.r32(c+156u);need(a[39]!=0,"normal context descriptor pointer");
a[40]=m.r32(c+160u);need(a[40]!=0,"normal context descriptor pointer");
a[41]=m.r32(c+164u);need(a[41]!=0,"normal context descriptor pointer");
a[42]=m.r32(c+168u);need(a[42]!=0,"normal context descriptor pointer");
a[43]=m.r32(c+172u);need(a[43]!=0,"normal context descriptor pointer");
a[44]=m.r32(c+176u);need(a[44]!=0,"normal context descriptor pointer");
a[45]=m.r32(c+180u);need(a[45]!=0,"normal context descriptor pointer");
a[46]=m.r32(c+184u);need(a[46]!=0,"normal context descriptor pointer");
a[47]=m.r32(c+188u);need(a[47]!=0,"normal context descriptor pointer");
a[48]=m.r32(c+192u);need(a[48]!=0,"normal context descriptor pointer");
a[49]=m.r32(c+196u);need(a[49]!=0,"normal context descriptor pointer");
a[50]=m.r32(c+200u);need(a[50]!=0,"normal context descriptor pointer");
a[51]=m.r32(c+204u);need(a[51]!=0,"normal context descriptor pointer");
a[52]=m.r32(c+208u);need(a[52]!=0,"normal context descriptor pointer");
a[53]=m.r32(c+216u);need(a[53]!=0,"normal context descriptor pointer");
a[54]=m.r32(c+212u);need(a[54]!=0,"normal context descriptor pointer");
a[55]=m.r32(c+220u);need(a[55]!=0,"normal context descriptor pointer");
a[56]=m.r32(c+224u);need(a[56]!=0,"normal context descriptor pointer");
a[57]=m.r32(c+228u);need(a[57]!=0,"normal context descriptor pointer");
a[58]=m.r32(c+232u);need(a[58]!=0,"normal context descriptor pointer");
a[59]=m.r32(c+236u);need(a[59]!=0,"normal context descriptor pointer");
a[60]=m.r32(c+240u);need(a[60]!=0,"normal context descriptor pointer");
a[61]=m.r32(c+244u);need(a[61]!=0,"normal context descriptor pointer");
a[62]=m.r32(c+248u);need(a[62]!=0,"normal context descriptor pointer");
a[63]=m.r32(c+252u);need(a[63]!=0,"normal context descriptor pointer");
a[64]=m.r32(c+256u);need(a[64]!=0,"normal context descriptor pointer");
a[65]=m.r32(c+260u);need(a[65]!=0,"normal context descriptor pointer");
a[66]=m.r32(c+264u);need(a[66]!=0,"normal context descriptor pointer");
a[67]=m.r32(c+268u);need(a[67]!=0,"normal context descriptor pointer");
a[68]=m.r32(c+272u);need(a[68]!=0,"normal context descriptor pointer");
a[69]=m.r32(c+276u);need(a[69]!=0,"normal context descriptor pointer");
a[70]=m.r32(c+280u);need(a[70]!=0,"normal context descriptor pointer");
a[71]=m.r32(c+284u);need(a[71]!=0,"normal context descriptor pointer");
a[72]=m.r32(c+288u);need(a[72]!=0,"normal context descriptor pointer");
a[73]=m.r32(c+292u);need(a[73]!=0,"normal context descriptor pointer");
a[74]=m.r32(c+296u);need(a[74]!=0,"normal context descriptor pointer");
a[75]=m.r32(c+300u);need(a[75]!=0,"normal context descriptor pointer");
a[76]=m.r32(c+304u);need(a[76]!=0,"normal context descriptor pointer");
a[77]=m.r32(c+308u);need(a[77]!=0,"normal context descriptor pointer");
a[78]=m.r32(c+312u);need(a[78]!=0,"normal context descriptor pointer");
a[79]=m.r32(c+316u);need(a[79]!=0,"normal context descriptor pointer");
a[80]=m.r32(c+320u);need(a[80]!=0,"normal context descriptor pointer");
a[81]=m.r32(c+324u);need(a[81]!=0,"normal context descriptor pointer");
a[82]=m.r32(c+328u);need(a[82]!=0,"normal context descriptor pointer");
a[83]=m.r32(c+332u);need(a[83]!=0,"normal context descriptor pointer");
a[84]=m.r32(c+336u);need(a[84]!=0,"normal context descriptor pointer");
a[85]=m.r32(c+340u);need(a[85]!=0,"normal context descriptor pointer");
a[86]=m.r32(c+344u);need(a[86]!=0,"normal context descriptor pointer");
a[87]=m.r32(c+348u);need(a[87]!=0,"normal context descriptor pointer");
a[88]=m.r32(c+352u);need(a[88]!=0,"normal context descriptor pointer");
a[89]=m.r32(c+356u);need(a[89]!=0,"normal context descriptor pointer");
a[90]=m.r32(c+360u);need(a[90]!=0,"normal context descriptor pointer");
if(!a[25])a[25]=m.r32(a[24]+8u);
if(!a[25])a[25]=m.r32(a[27]+8u);
if(!a[25])a[25]=m.r32(a[28]+12u);
if(!a[25])a[25]=m.r32(a[29]+8u);
if(!a[25])a[25]=m.r32(a[30]+8u);
if(!a[25])a[25]=m.r32(a[31]+8u);
if(!a[25])a[25]=m.r32(a[37]+8u);
if(!a[25])a[25]=m.r32(a[38]+8u);
if(!a[25])a[25]=m.r32(a[39]+12u);
if(!a[25])a[25]=m.r32(a[40]+8u);
if(!a[25])a[25]=m.r32(a[41]+8u);
if(!a[25])a[25]=m.r32(a[42]+8u);
if(!a[25])a[25]=m.r32(a[43]+8u);
if(!a[25])a[25]=m.r32(a[44]+8u);
if(!a[25])a[25]=m.r32(a[45]+8u);
if(!a[25])a[25]=m.r32(a[46]+8u);
if(!a[25])a[25]=m.r32(a[47]+8u);
if(!a[25])a[25]=m.r32(a[48]+12u);
if(!a[25])a[25]=m.r32(a[49]+8u);
if(!a[25])a[25]=m.r32(a[50]+8u);
if(!a[25])a[25]=m.r32(a[51]+8u);
if(!a[25])a[25]=m.r32(a[73]+8u);
if(!a[25])a[25]=m.r32(a[74]+12u);
if(!a[25])a[25]=m.r32(a[75]+8u);
if(!a[25])a[25]=m.r32(a[76]+8u);
if(!a[25])a[25]=m.r32(a[77]+8u);
if(!a[25])a[25]=m.r32(a[78]+8u);
if(!a[25])a[25]=m.r32(a[79]+12u);
if(!a[25])a[25]=m.r32(a[80]+8u);
if(!a[25])a[25]=m.r32(a[81]+8u);
if(!a[25])a[25]=m.r32(a[82]+8u);
if(!a[25])a[25]=m.r32(a[83]+8u);
if(!a[25])a[25]=m.r32(a[84]+8u);
if(!a[25])a[25]=m.r32(a[85]+8u);
if(!a[25])a[25]=m.r32(a[86]+8u);
if(!a[25])a[25]=m.r32(a[87]+12u);
if(!a[25])a[25]=m.r32(a[88]+8u);
if(!a[25])a[25]=m.r32(a[89]+8u);
if(!a[25])a[25]=m.r32(a[90]+8u);
need(a[25]&&m.r32(a[25]+0x20000)==1&&m.r32(a[25]+0x20004)==39,"normal N1 cache backing/refcount");for(unsigned k=0;k<65536;++k)need(m.r16(a[25]+2*k)==0,"normal N1 world words");
need(m.r32(a[0]+0u)==(7902268u),"normal descriptor field");
need(m.r32(a[0]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[1]+0u)==(7902252u),"normal descriptor field");
need(m.r32(a[1]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[2]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[2]+8u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[2]+0u)==(7902236u),"normal descriptor field");
need(m.r32(a[3]+0u)==(7902220u),"normal descriptor field");
need(m.r16(a[3]+4u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[4]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[4]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[4]+0u)==(7902204u),"normal descriptor field");
need(m.r32(a[5]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[5]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[5]+0u)==(7902188u),"normal descriptor field");
need(m.r32(a[6]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[6]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[6]+0u)==(7902172u),"normal descriptor field");
need(m.r32(a[7]+0u)==(7902156u),"normal descriptor field");
need(m.r32(a[7]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[8]+0u)==(7902140u),"normal descriptor field");
need(m.r32(a[8]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[9]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[9]+8u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[9]+0u)==(7902124u),"normal descriptor field");
need(m.r32(a[10]+0u)==(7902108u),"normal descriptor field");
need(m.r16(a[10]+4u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[11]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[11]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[11]+0u)==(7902092u),"normal descriptor field");
need(m.r32(a[12]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[12]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[12]+0u)==(7902076u),"normal descriptor field");
need(m.r32(a[13]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[13]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[13]+0u)==(7902060u),"normal descriptor field");
need(m.r32(a[14]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[14]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[14]+0u)==(7902044u),"normal descriptor field");
need(m.r32(a[15]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[15]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[15]+0u)==(7902028u),"normal descriptor field");
need(m.r32(a[16]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[16]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[16]+0u)==(7902012u),"normal descriptor field");
need(m.r32(a[17]+0u)==(7901996u),"normal descriptor field");
need(m.r32(a[17]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[18]+0u)==(7901980u),"normal descriptor field");
need(m.r32(a[18]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[19]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[19]+8u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[19]+0u)==(7901964u),"normal descriptor field");
need(m.r32(a[20]+0u)==(7901948u),"normal descriptor field");
need(m.r16(a[20]+4u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[21]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[21]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[21]+0u)==(7901932u),"normal descriptor field");
need(m.r32(a[22]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[22]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[22]+0u)==(7901916u),"normal descriptor field");
need(m.r32(a[23]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[23]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[23]+0u)==(7901900u),"normal descriptor field");
need(m.r32(a[24]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[24]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[24]+0u)==(7901884u),"normal descriptor field");
need(m.r32(a[27]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[27]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[27]+0u)==(7901868u),"normal descriptor field");
need(m.r32(a[28]+8u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[28]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[28]+12u)==(a[25]),"normal descriptor field");
need(m.r32(a[28]+0u)==(7901852u),"normal descriptor field");
need(m.r32(a[29]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[29]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[29]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[29]+0u)==(7901836u),"normal descriptor field");
need(m.r32(a[30]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[30]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[30]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[30]+0u)==(7901820u),"normal descriptor field");
need(m.r32(a[31]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[31]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[31]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[31]+0u)==(7901804u),"normal descriptor field");
need(m.r32(a[32]+0u)==(7901788u),"normal descriptor field");
need(m.r32(a[33]+0u)==(7901772u),"normal descriptor field");
need(m.r32(a[34]+0u)==(7901756u),"normal descriptor field");
need(m.r32(a[34]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[35]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[35]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[35]+0u)==(7901740u),"normal descriptor field");
need(m.r32(a[36]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[36]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[36]+0u)==(7901724u),"normal descriptor field");
need(m.r32(a[37]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[37]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[37]+0u)==(7901884u),"normal descriptor field");
need(m.r32(a[38]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[38]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[38]+0u)==(7901708u),"normal descriptor field");
need(m.r32(a[39]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[39]+8u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[39]+12u)==(a[25]),"normal descriptor field");
need(m.r32(a[39]+0u)==(7901692u),"normal descriptor field");
need(m.r32(a[40]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[40]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[40]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[40]+0u)==(7901676u),"normal descriptor field");
need(m.r32(a[41]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[41]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[41]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[41]+0u)==(7901660u),"normal descriptor field");
need(m.r32(a[42]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[42]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[42]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[42]+0u)==(7901644u),"normal descriptor field");
need(m.r32(a[43]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[43]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[43]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[43]+0u)==(7901628u),"normal descriptor field");
need(m.r32(a[44]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[44]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[44]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[44]+0u)==(7901612u),"normal descriptor field");
need(m.r32(a[45]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[45]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[45]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[45]+0u)==(7901596u),"normal descriptor field");
need(m.r32(a[46]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[46]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[46]+0u)==(7901884u),"normal descriptor field");
need(m.r32(a[47]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[47]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[47]+0u)==(7901580u),"normal descriptor field");
need(m.r32(a[48]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[48]+8u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[48]+12u)==(a[25]),"normal descriptor field");
need(m.r32(a[48]+0u)==(7901564u),"normal descriptor field");
need(m.r32(a[49]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[49]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[49]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[49]+0u)==(7901548u),"normal descriptor field");
need(m.r32(a[50]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[50]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[50]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[50]+0u)==(7901532u),"normal descriptor field");
need(m.r32(a[51]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[51]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[51]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[51]+0u)==(7901516u),"normal descriptor field");
need(m.r32(a[52]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[52]+0u)==(7901504u),"normal descriptor field");
need(m.r32(a[53]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[53]+8u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[53]+0u)==(7901492u),"normal descriptor field");
need(m.r16(a[54]+4u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[54]+0u)==(7901480u),"normal descriptor field");
need(m.r32(a[55]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[55]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[55]+0u)==(7901468u),"normal descriptor field");
need(m.r32(a[56]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[56]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[56]+0u)==(7901456u),"normal descriptor field");
need(m.r32(a[57]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[57]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[57]+0u)==(7901444u),"normal descriptor field");
need(m.r32(a[58]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[58]+0u)==(7901432u),"normal descriptor field");
need(m.r32(a[59]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[59]+8u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[59]+0u)==(7901420u),"normal descriptor field");
need(m.r16(a[60]+4u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[60]+0u)==(7901408u),"normal descriptor field");
need(m.r32(a[61]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[61]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[61]+0u)==(7901396u),"normal descriptor field");
need(m.r32(a[62]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[62]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[62]+0u)==(7901384u),"normal descriptor field");
need(m.r32(a[63]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[63]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[63]+0u)==(7901372u),"normal descriptor field");
need(m.r32(a[64]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[64]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[64]+0u)==(7901360u),"normal descriptor field");
need(m.r32(a[65]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[65]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[65]+0u)==(7901348u),"normal descriptor field");
need(m.r32(a[66]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[66]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[66]+0u)==(7901336u),"normal descriptor field");
need(m.r32(a[67]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[67]+0u)==(7901324u),"normal descriptor field");
need(m.r32(a[68]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[68]+8u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r32(a[68]+0u)==(7901312u),"normal descriptor field");
need(m.r16(a[69]+4u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[69]+0u)==(7901300u),"normal descriptor field");
need(m.r32(a[70]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[70]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[70]+0u)==(7901288u),"normal descriptor field");
need(m.r32(a[71]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[71]+8u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[71]+0u)==(7901276u),"normal descriptor field");
need(m.r32(a[72]+4u)==(m.r32(c+372u)),"normal descriptor field");
need(m.r16(a[72]+8u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[72]+0u)==(7901264u),"normal descriptor field");
need(m.r32(a[73]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[73]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[73]+0u)==(7901252u),"normal descriptor field");
need(m.r32(a[74]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[74]+8u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[74]+12u)==(a[25]),"normal descriptor field");
need(m.r32(a[74]+0u)==(7901240u),"normal descriptor field");
need(m.r32(a[75]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[75]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[75]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[75]+0u)==(7901228u),"normal descriptor field");
need(m.r32(a[76]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[76]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[76]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[76]+0u)==(7901216u),"normal descriptor field");
need(m.r32(a[77]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[77]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[77]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[77]+0u)==(7901204u),"normal descriptor field");
need(m.r32(a[78]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[78]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[78]+0u)==(7901192u),"normal descriptor field");
need(m.r32(a[79]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[79]+8u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[79]+12u)==(a[25]),"normal descriptor field");
need(m.r32(a[79]+0u)==(7901180u),"normal descriptor field");
need(m.r32(a[80]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[80]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[80]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[80]+0u)==(7901168u),"normal descriptor field");
need(m.r32(a[81]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[81]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[81]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[81]+0u)==(7901156u),"normal descriptor field");
need(m.r32(a[82]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[82]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[82]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[82]+0u)==(7901144u),"normal descriptor field");
need(m.r32(a[83]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[83]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[83]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[83]+0u)==(7901132u),"normal descriptor field");
need(m.r32(a[84]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[84]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[84]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[84]+0u)==(7901120u),"normal descriptor field");
need(m.r32(a[85]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[85]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[85]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[85]+0u)==(7901108u),"normal descriptor field");
need(m.r32(a[86]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[86]+8u)==(a[25]),"normal descriptor field");
need(m.r32(a[86]+0u)==(7901096u),"normal descriptor field");
need(m.r32(a[87]+4u)==(c+380u),"normal descriptor field");
need(m.r32(a[87]+8u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[87]+12u)==(a[25]),"normal descriptor field");
need(m.r32(a[87]+0u)==(7901084u),"normal descriptor field");
need(m.r32(a[88]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[88]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[88]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[88]+0u)==(7901072u),"normal descriptor field");
need(m.r32(a[89]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[89]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[89]+12u)==((m.r32(c+384u))&0xffffu),"normal descriptor field");
need(m.r32(a[89]+0u)==(7901060u),"normal descriptor field");
need(m.r32(a[90]+4u)==(m.r32(c+368u)),"normal descriptor field");
need(m.r32(a[90]+8u)==(a[25]),"normal descriptor field");
need(m.r16(a[90]+12u)==((m.r32(c+388u))&0xffffu),"normal descriptor field");
need(m.r32(a[90]+0u)==(7901048u),"normal descriptor field");
}
}
Result run(Memory&world,Api&api,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming){
 need(size>=0x8000+68&&unsigned(reinterpret_cast<std::uintptr_t>(storage))+0x8000==entry,"actual owned32KB Source frame");
 leaf::Memory local(storage,entry-0x8000,size);Memory m=world;m.add(local);
 for(unsigned a:{0xa1a5d8u,0xb10530u,0xb10e20u,0xb10e24u})need(m.r32(a)==0,"authentic cold provider/locale fields");need(m.r32(0x81776c)==1&&m.r8(0x81f701)==1,"cold C-locale and enabled renderer");
 need(m.r32(in.cx+0x11e0)==4&&m.r32(in.cx+0x11e8)==1&&m.r32(in.cx+0x11ec)==2&&m.r32(in.cx+0x11f0)==2&&m.r32(in.cx+0x11f4)==10,"finite opaque Root record");
 unsigned surface=m.r32(0x821c88),context=m.r32(0x81a70c);need(surface&&context&&m.r32(surface)==0x785ef8&&m.r32(surface+4)==16&&m.r32(surface+8)==12&&m.r32(surface+12)==1&&m.r32(surface+16)==2&&m.r32(surface+24)==384&&m.r8(surface+28)==0,"normal16x12 borrowedBSurface C1 bpp2");
 unsigned lut=m.r32(context+0x174);need(lut!=0,"public LUT512");(void)m.r16(lut+510);guard_context(m,context,lut);unsigned row=m.r32(context+0xd0);need(m.r32(row)==0x789140&&m.r32(row+4)==lut,"normal D0 rowdescriptor");
 unsigned shp=m.r32(0xa9dfe8);need(shp&&m.r16(shp+2)==1&&m.r16(shp+4)==1&&m.r16(shp+6)==33,"33frame1x1RLE");for(unsigned f=0;f<33;++f){unsigned r=shp+8+24*f;need(m.r16(r)==0&&m.r16(r+2)==0&&m.r16(r+4)==1&&m.r16(r+6)==1&&m.r8(r+8)==2,"normal onepixel RLE frame");unsigned data=shp+m.r32(r+0x14);need(m.r16(data)==3&&m.r8(data+2)!=0,"positive onepixel row");}
 unsigned font=m.r32(0x836d30);need(font!=0,"borrowed Font");unsigned desc=m.r32(font+4);need(desc!=0,"Font descriptor");unsigned glyph=m.r32(desc+28),map=m.r32(desc+24);need(glyph&&map&&m.r32(0x836d18)==surface&&m.r32(font+24)==1&&m.r32(font+28)==2&&m.r32(font+44)==1&&m.r32(desc+4)==2&&m.r32(desc+8)==2&&m.r32(desc+16)==1&&m.r32(desc+20)==3&&m.r8(font+0x41)==0,"borrowed postparseFont2x2 spacing1");need(m.r8(glyph)==2&&m.r8(glyph+1)==0xc0&&m.r8(glyph+2)==0x80,"positive glyph");for(unsigned k=0;k<10;++k)need(m.r16(map+2*(48+k))==1,"digitmap ordinal1");
 unsigned schemes=m.r32(0xa9ea04);need(schemes!=0,"one scheme array");unsigned scheme=m.r32(schemes);need(scheme&&m.r32(0xa9ea10)==1&&m.r32(scheme+0x304)==0x7c34a8&&m.r32(scheme+0x310)==1&&m.r8(scheme+0x308)==16&&m.r8(scheme+0x309)==16&&m.r8(scheme+0x30a)==16,"borrowed Grey HSV16 input");
 const unsigned shifts[]{11,3,0,3,5,2};for(unsigned k=0;k<6;++k)need(m.r32(0x83b2e8+4*k)==shifts[k],"RGB565 packing input");
 unsigned table=m.r32(0xab7ec0),values=m.r32(0xab7ec4);need(table&&values&&m.r32(0xab7eb8)==2,"two existing lookup records");const char*keys[]{"TXT_KILLS_COLON","TXT_NAME_COLON"};for(unsigned n=0;n<2;++n){for(unsigned k=0;;++k){need(m.r8(table+40*n+k)==unsigned(keys[n][k]),"genuine sorted key row");if(!keys[n][k])break;}need(m.r32(table+40*n+0x24)==n,"lookup index");unsigned v=m.r32(values+4*n);need(m.r16(v)==(n?49u:50u)&&m.r16(v+2)==0,"declared one-digit lookup value");}
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;auto initial=s;Frame f{entry,entry,m.r32(entry)};const Operations op{&api,entry-0x8000,entry};f_002279d0(m,s,f,op);need(f.sp==entry+4&&s.bx==initial.bx&&s.bp==initial.bp&&s.si==initial.si&&s.di==initial.di&&!(s.arithmetic_flags&0x400),"RET0/four nonvolatiles/DF");Result result{s.ax,s,{}};for(unsigned k=0;k<16;++k)result.words[k]=m.r32(entry+4+4*k);return result;
}
}
