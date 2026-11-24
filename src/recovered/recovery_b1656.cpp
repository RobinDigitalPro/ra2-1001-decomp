#include "recovered/recovery_b1656.hpp"
#include <limits>
namespace ra2::recovered::b1656 {
using namespace floating_b61;
using Frame=recovery_b566::Frame;
using recovery_b566::finish;using recovery_b566::string_instruction;using recovery_b566::Kind;using recovery_b566::Repeat;using recovery_b566::reverse_divide32;using recovery_b566::reverse_divide64;
namespace integer=direct_b33::integer;namespace floating_b61=ra2::recovered::floating_b61;namespace numeric_b88=ra2::recovered::numeric_b88;
namespace {
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
struct Operations{};
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_0009a4e0(Memory&,State&,Frame&,const Operations&);
void f_00145280(Memory&,State&,Frame&,const Operations&);
void f_00145200(Memory&,State&,Frame&,const Operations&);
void f_0009ab70(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00078360(Memory&,State&,Frame&,const Operations&);
void f_00071260(Memory&,State&,Frame&,const Operations&);

void f_0009a4e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049a4e0: { // 0x49a4e0: 83ec4c SUB ESP,0x4c
    f.sp = integer::sub(f.sp,0x0000004cu,32,flags);
  }
  L0049a4e3: { // 0x49a4e3: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L0049a4e7: { // 0x49a4e7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049a4e8: { // 0x49a4e8: 668b1542a98300 MOV DX,word ptr [0x0083a942]
    s.dx = with_ax(s.dx, m.r16((0x0083a942u)));
  }
  L0049a4ef: { // 0x49a4ef: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a4f0: { // 0x49a4f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a4f1: { // 0x49a4f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049a4f3: { // 0x49a4f3: 8b0d40a98300 MOV ECX,dword ptr [0x0083a940]
    s.cx = m.r32((0x0083a940u));
  }
  L0049a4f9: { // 0x49a4f9: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049a4fb: { // 0x49a4fb: 663908 CMP word ptr [EAX],CX
    (void)integer::sub(m.r16((s.ax)),(s.cx & 0xffffu),16,flags);
  }
  L0049a4fe: { // 0x49a4fe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049a4ff: { // 0x49a4ff: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L0049a504: { // 0x49a504: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0049a509: { // 0x49a509: c7442418ffffffff MOV dword ptr [ESP + 0x18],0xffffffff
    m.w32((f.sp+0x00000018u), 0xffffffffu);
  }
  L0049a511: { // 0x49a511: 66896c2414 MOV word ptr [ESP + 0x14],bp
    m.w16((f.sp+0x00000014u), (s.bp & 0xffffu));
  }
  L0049a516: { // 0x49a516: 66896c2416 MOV word ptr [ESP + 0x16],bp
    m.w16((f.sp+0x00000016u), (s.bp & 0xffffu));
  }
  L0049a51b: { // 0x49a51b: 7506 JNZ 0x0049a523
    if(integer::condition("JNZ",flags)) goto L0049a523;
  }
  L0049a51d: { // 0x49a51d: 66395002 CMP word ptr [EAX + 0x2],DX
    (void)integer::sub(m.r16((s.ax+0x00000002u)),(s.dx & 0xffffu),16,flags);
  }
  L0049a521: { // 0x49a521: 7406 JZ 0x0049a529
    if(integer::condition("JZ",flags)) goto L0049a529;
  }
  L0049a523: { // 0x49a523: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0049a525: { // 0x49a525: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0049a529: { // 0x49a529: 66394c2414 CMP word ptr [ESP + 0x14],CX
    (void)integer::sub(m.r16((f.sp+0x00000014u)),(s.cx & 0xffffu),16,flags);
  }
  L0049a52e: { // 0x49a52e: 7511 JNZ 0x0049a541
    if(integer::condition("JNZ",flags)) goto L0049a541;
  }
  L0049a530: { // 0x49a530: 6639542416 CMP word ptr [ESP + 0x16],DX
    (void)integer::sub(m.r16((f.sp+0x00000016u)),(s.dx & 0xffffu),16,flags);
  }
  L0049a535: { // 0x49a535: 750a JNZ 0x0049a541
    if(integer::condition("JNZ",flags)) goto L0049a541;
  }
  L0049a537: { // 0x49a537: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    s.ax = m.r32((f.sp+0x0000006cu));
  }
  L0049a53b: { // 0x49a53b: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0049a53d: { // 0x49a53d: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0049a541: { // 0x49a541: 8a442474 MOV AL,byte ptr [ESP + 0x74]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000074u)));
  }
  L0049a545: { // 0x49a545: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a547: { // 0x49a547: 7428 JZ 0x0049a571
    if(integer::condition("JZ",flags)) goto L0049a571;
  }
  L0049a549: { // 0x49a549: 66394c2414 CMP word ptr [ESP + 0x14],CX
    (void)integer::sub(m.r16((f.sp+0x00000014u)),(s.cx & 0xffffu),16,flags);
  }
  L0049a54e: { // 0x49a54e: 7507 JNZ 0x0049a557
    if(integer::condition("JNZ",flags)) goto L0049a557;
  }
  L0049a550: { // 0x49a550: 6639542416 CMP word ptr [ESP + 0x16],DX
    (void)integer::sub(m.r16((f.sp+0x00000016u)),(s.dx & 0xffffu),16,flags);
  }
  L0049a555: { // 0x49a555: 741a JZ 0x0049a571
    if(integer::condition("JZ",flags)) goto L0049a571;
  }
  L0049a557: { // 0x49a557: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0049a55b: { // 0x49a55b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049a55d: { // 0x49a55d: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0049a561: { // 0x49a561: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a562: { // 0x49a562: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a563: { // 0x49a563: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049a568: { // 0x49a568: e813280b00 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4826477u,op); flags=s.arithmetic_flags;
  }
  L0049a56d: { // 0x49a56d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0049a571: { // 0x49a571: 0fbf442414 MOVSX EAX,word ptr [ESP + 0x14]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L0049a576: { // 0x49a576: 0fbf4c2416 MOVSX ECX,word ptr [ESP + 0x16]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0049a57b: { // 0x49a57b: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0049a57f: { // 0x49a57f: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0049a583: { // 0x49a583: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0049a587: { // 0x49a587: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0049a58b: { // 0x49a58b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a58c: { // 0x49a58c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a58d: { // 0x49a58d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a58f: { // 0x49a58f: e8ecac0a00 CALL 0x00545280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545280u,4826516u,op); flags=s.arithmetic_flags;
  }
  L0049a594: { // 0x49a594: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0049a596: { // 0x49a596: 668b4c2414 MOV CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000014u)));
  }
  L0049a59b: { // 0x49a59b: 663b0d40a98300 CMP CX,word ptr [0x0083a940]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x0083a940u)),16,flags);
  }
  L0049a5a2: { // 0x49a5a2: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0049a5a5: { // 0x49a5a5: 7512 JNZ 0x0049a5b9
    if(integer::condition("JNZ",flags)) goto L0049a5b9;
  }
  L0049a5a7: { // 0x49a5a7: 668b442416 MOV AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000016u)));
  }
  L0049a5ac: { // 0x49a5ac: 663b0542a98300 CMP AX,word ptr [0x0083a942]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x0083a942u)),16,flags);
  }
  L0049a5b3: { // 0x49a5b3: 0f84f2000000 JZ 0x0049a6ab
    if(integer::condition("JZ",flags)) goto L0049a6ab;
  }
  L0049a5b9: { // 0x49a5b9: 8b9e00010000 MOV EBX,dword ptr [ESI + 0x100]
    s.bx = m.r32((s.si+0x00000100u));
  }
  L0049a5bf: { // 0x49a5bf: 8b8ef8000000 MOV ECX,dword ptr [ESI + 0xf8]
    s.cx = m.r32((s.si+0x000000f8u));
  }
  L0049a5c5: { // 0x49a5c5: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0049a5c7: { // 0x49a5c7: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0049a5c9: { // 0x49a5c9: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0049a5cb: { // 0x49a5cb: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0049a5cd: { // 0x49a5cd: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049a5cf: { // 0x49a5cf: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L0049a5d3: { // 0x49a5d3: 7c02 JL 0x0049a5d7
    if(integer::condition("JL",flags)) goto L0049a5d7;
  }
  L0049a5d5: { // 0x49a5d5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049a5d7: { // 0x49a5d7: 8baefc000000 MOV EBP,dword ptr [ESI + 0xfc]
    s.bp = m.r32((s.si+0x000000fcu));
  }
  L0049a5dd: { // 0x49a5dd: 8d0c00 LEA ECX,[EAX + EAX*0x1]
    s.cx = (s.ax+(s.ax * 0x00000001u));
  }
  L0049a5e0: { // 0x49a5e0: 894c2474 MOV dword ptr [ESP + 0x74],ECX
    m.w32((f.sp+0x00000074u), s.cx);
  }
  L0049a5e4: { // 0x49a5e4: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0049a5e6: { // 0x49a5e6: 8d542d00 LEA EDX,[EBP + EBP*0x1]
    s.dx = (s.bp+(s.bp * 0x00000001u));
  }
  L0049a5ea: { // 0x49a5ea: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0049a5ec: { // 0x49a5ec: 8b9604010000 MOV EDX,dword ptr [ESI + 0x104]
    s.dx = m.r32((s.si+0x00000104u));
  }
  L0049a5f2: { // 0x49a5f2: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0049a5f4: { // 0x49a5f4: 8d042a LEA EAX,[EDX + EBP*0x1]
    s.ax = (s.dx+(s.bp * 0x00000001u));
  }
  L0049a5f7: { // 0x49a5f7: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0049a5f9: { // 0x49a5f9: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L0049a5fb: { // 0x49a5fb: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0049a5fd: { // 0x49a5fd: 7c02 JL 0x0049a601
    if(integer::condition("JL",flags)) goto L0049a601;
  }
  L0049a5ff: { // 0x49a5ff: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0049a601: { // 0x49a601: 395c2474 CMP dword ptr [ESP + 0x74],EBX
    (void)integer::sub(m.r32((f.sp+0x00000074u)),s.bx,32,flags);
  }
  L0049a605: { // 0x49a605: 7d57 JGE 0x0049a65e
    if(integer::condition("JGE",flags)) goto L0049a65e;
  }
  L0049a607: { // 0x49a607: 8b8e00010000 MOV ECX,dword ptr [ESI + 0x100]
    s.cx = m.r32((s.si+0x00000100u));
  }
  L0049a60d: { // 0x49a60d: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L0049a612: { // 0x49a612: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049a614: { // 0x49a614: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0049a619: { // 0x49a619: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049a61a: { // 0x49a61a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049a61c: { // 0x49a61c: 8b54246c MOV EDX,dword ptr [ESP + 0x6c]
    s.dx = m.r32((f.sp+0x0000006cu));
  }
  L0049a620: { // 0x49a620: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049a622: { // 0x49a622: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0049a624: { // 0x49a624: 7d1e JGE 0x0049a644
    if(integer::condition("JGE",flags)) goto L0049a644;
  }
  L0049a626: { // 0x49a626: 2bfd SUB EDI,EBP
    s.di = integer::sub(s.di,s.bp,32,flags);
  }
  L0049a628: { // 0x49a628: c7442474ffffffff MOV dword ptr [ESP + 0x74],0xffffffff
    m.w32((f.sp+0x00000074u), 0xffffffffu);
  }
  L0049a630: { // 0x49a630: bb03000000 MOV EBX,0x3
    s.bx = 0x00000003u;
  }
  L0049a635: { // 0x49a635: c744246800000000 MOV dword ptr [ESP + 0x68],0x0
    m.w32((f.sp+0x00000068u), 0x00000000u);
  }
  L0049a63d: { // 0x49a63d: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049a63f: { // 0x49a63f: e9ff000000 JMP 0x0049a743
    goto L0049a743;
  }
  L0049a644: { // 0x49a644: 2bfd SUB EDI,EBP
    s.di = integer::sub(s.di,s.bp,32,flags);
  }
  L0049a646: { // 0x49a646: 894c2474 MOV dword ptr [ESP + 0x74],ECX
    m.w32((f.sp+0x00000074u), s.cx);
  }
  L0049a64a: { // 0x49a64a: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0049a64f: { // 0x49a64f: c744246800000000 MOV dword ptr [ESP + 0x68],0x0
    m.w32((f.sp+0x00000068u), 0x00000000u);
  }
  L0049a657: { // 0x49a657: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049a659: { // 0x49a659: e9e5000000 JMP 0x0049a743
    goto L0049a743;
  }
  L0049a65e: { // 0x49a65e: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L0049a661: { // 0x49a661: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L0049a666: { // 0x49a666: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0049a668: { // 0x49a668: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0049a66d: { // 0x49a66d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049a66e: { // 0x49a66e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049a670: { // 0x49a670: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049a672: { // 0x49a672: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0049a674: { // 0x49a674: 7d19 JGE 0x0049a68f
    if(integer::condition("JGE",flags)) goto L0049a68f;
  }
  L0049a676: { // 0x49a676: 8b7c246c MOV EDI,dword ptr [ESP + 0x6c]
    s.di = m.r32((f.sp+0x0000006cu));
  }
  L0049a67a: { // 0x49a67a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0049a67c: { // 0x49a67c: c7442468ffffffff MOV dword ptr [ESP + 0x68],0xffffffff
    m.w32((f.sp+0x00000068u), 0xffffffffu);
  }
  L0049a684: { // 0x49a684: 895c2474 MOV dword ptr [ESP + 0x74],EBX
    m.w32((f.sp+0x00000074u), s.bx);
  }
  L0049a688: { // 0x49a688: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049a68a: { // 0x49a68a: e9b4000000 JMP 0x0049a743
    goto L0049a743;
  }
  L0049a68f: { // 0x49a68f: 897c2468 MOV dword ptr [ESP + 0x68],EDI
    m.w32((f.sp+0x00000068u), s.di);
  }
  L0049a693: { // 0x49a693: 8b7c246c MOV EDI,dword ptr [ESP + 0x6c]
    s.di = m.r32((f.sp+0x0000006cu));
  }
  L0049a697: { // 0x49a697: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L0049a69c: { // 0x49a69c: c744247400000000 MOV dword ptr [ESP + 0x74],0x0
    m.w32((f.sp+0x00000074u), 0x00000000u);
  }
  L0049a6a4: { // 0x49a6a4: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049a6a6: { // 0x49a6a6: e998000000 JMP 0x0049a743
    goto L0049a743;
  }
  L0049a6ab: { // 0x49a6ab: 8b5c2464 MOV EBX,dword ptr [ESP + 0x64]
    s.bx = m.r32((f.sp+0x00000064u));
  }
  L0049a6af: { // 0x49a6af: 896c2474 MOV dword ptr [ESP + 0x74],EBP
    m.w32((f.sp+0x00000074u), s.bp);
  }
  L0049a6b3: { // 0x49a6b3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0049a6b5: { // 0x49a6b5: 896c2468 MOV dword ptr [ESP + 0x68],EBP
    m.w32((f.sp+0x00000068u), s.bp);
  }
  L0049a6b9: { // 0x49a6b9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0049a6ba: { // 0x49a6ba: 745a JZ 0x0049a716
    if(integer::condition("JZ",flags)) goto L0049a716;
  }
  L0049a6bc: { // 0x49a6bc: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0049a6bd: { // 0x49a6bd: 742d JZ 0x0049a6ec
    if(integer::condition("JZ",flags)) goto L0049a6ec;
  }
  L0049a6bf: { // 0x49a6bf: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0049a6c0: { // 0x49a6c0: 740d JZ 0x0049a6cf
    if(integer::condition("JZ",flags)) goto L0049a6cf;
  }
  L0049a6c2: { // 0x49a6c2: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L0049a6c8: { // 0x49a6c8: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0049a6cd: { // 0x49a6cd: eb5e JMP 0x0049a72d
    goto L0049a72d;
  }
  L0049a6cf: { // 0x49a6cf: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  L0049a6d5: { // 0x49a6d5: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0049a6db: { // 0x49a6db: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0049a6dd: { // 0x49a6dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a6de: { // 0x49a6de: c644241601 MOV byte ptr [ESP + 0x16],0x1
    m.w8((f.sp+0x00000016u), 0x00000001u);
  }
  L0049a6e3: { // 0x49a6e3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a6e4: { // 0x49a6e4: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L0049a6ea: { // 0x49a6ea: eb4f JMP 0x0049a73b
    goto L0049a73b;
  }
  L0049a6ec: { // 0x49a6ec: 8b9604010000 MOV EDX,dword ptr [ESI + 0x104]
    s.dx = m.r32((s.si+0x00000104u));
  }
  L0049a6f2: { // 0x49a6f2: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0049a6f8: { // 0x49a6f8: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0049a6fd: { // 0x49a6fd: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L0049a703: { // 0x49a703: 8d441202 LEA EAX,[EDX + EDX*0x1 + 0x2]
    s.ax = (s.dx+(s.dx * 0x00000001u)+0x00000002u);
  }
  L0049a707: { // 0x49a707: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L0049a70b: { // 0x49a70b: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L0049a711: { // 0x49a711: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a712: { // 0x49a712: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049a714: { // 0x49a714: eb25 JMP 0x0049a73b
    goto L0049a73b;
  }
  L0049a716: { // 0x49a716: 8b9600010000 MOV EDX,dword ptr [ESI + 0x100]
    s.dx = m.r32((s.si+0x00000100u));
  }
  L0049a71c: { // 0x49a71c: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  L0049a722: { // 0x49a722: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L0049a727: { // 0x49a727: 89542474 MOV dword ptr [ESP + 0x74],EDX
    m.w32((f.sp+0x00000074u), s.dx);
  }
  L0049a72b: { // 0x49a72b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0049a72d: { // 0x49a72d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a72e: { // 0x49a72e: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0049a733: { // 0x49a733: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049a735: { // 0x49a735: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L0049a73b: { // 0x49a73b: e800571900 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4826944u,op); flags=s.arithmetic_flags;
  }
  L0049a740: { // 0x49a740: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0049a742: { // 0x49a742: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0049a743: { // 0x49a743: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L0049a749: { // 0x49a749: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0049a74d: { // 0x49a74d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049a74e: { // 0x49a74e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049a750: { // 0x49a750: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0049a754: { // 0x49a754: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049a756: { // 0x49a756: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a757: { // 0x49a757: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a758: { // 0x49a758: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a75a: { // 0x49a75a: c744242401000000 MOV dword ptr [ESP + 0x24],0x1
    m.w32((f.sp+0x00000024u), 0x00000001u);
  }
  L0049a762: { // 0x49a762: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0049a766: { // 0x49a766: e895aa0a00 CALL 0x00545200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545200u,4826987u,op); flags=s.arithmetic_flags;
  }
  L0049a76b: { // 0x49a76b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049a76d: { // 0x49a76d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049a76f: { // 0x49a76f: 668944246c MOV word ptr [ESP + 0x6c],AX
    m.w16((f.sp+0x0000006cu), (s.ax & 0xffffu));
  }
  L0049a774: { // 0x49a774: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L0049a778: { // 0x49a778: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0049a77b: { // 0x49a77b: 66894c246e MOV word ptr [ESP + 0x6e],CX
    m.w16((f.sp+0x0000006eu), (s.cx & 0xffffu));
  }
  L0049a780: { // 0x49a780: 8b54246c MOV EDX,dword ptr [ESP + 0x6c]
    s.dx = m.r32((f.sp+0x0000006cu));
  }
  L0049a784: { // 0x49a784: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a786: { // 0x49a786: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L0049a78a: { // 0x49a78a: 0f84e4000000 JZ 0x0049a874
    if(integer::condition("JZ",flags)) goto L0049a874;
  }
  L0049a790: { // 0x49a790: 8b8e04010000 MOV ECX,dword ptr [ESI + 0x104]
    s.cx = m.r32((s.si+0x00000104u));
  }
  L0049a796: { // 0x49a796: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0049a797: { // 0x49a797: f7db NEG EBX
    s.bx = integer::sub(0u,s.bx,32,flags);
  }
  L0049a799: { // 0x49a799: 1bdb SBB EBX,EBX
    s.bx = integer::sub(s.bx,s.bx,32,flags,flags&integer::CF);
  }
  L0049a79b: { // 0x49a79b: 83e302 AND EBX,0x2
    s.bx = integer::logical((s.bx)&(0x00000002u),32,flags);
  }
  L0049a79e: { // 0x49a79e: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L0049a7a0: { // 0x49a7a0: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0049a7a1: { // 0x49a7a1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049a7a3: { // 0x49a7a3: 0f8ea3000000 JLE 0x0049a84c
    if(integer::condition("JLE",flags)) goto L0049a84c;
  }
  L0049a7a9: { // 0x49a7a9: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L0049a7ad: { // 0x49a7ad: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L0049a7af: { // 0x49a7af: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0049a7b3: { // 0x49a7b3: 8d042f LEA EAX,[EDI + EBP*0x1]
    s.ax = (s.di+(s.bp * 0x00000001u));
  }
  L0049a7b6: { // 0x49a7b6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049a7b7: { // 0x49a7b7: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049a7b9: { // 0x49a7b9: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L0049a7bd: { // 0x49a7bd: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L0049a7c1: { // 0x49a7c1: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0049a7c5: { // 0x49a7c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a7c7: { // 0x49a7c7: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0049a7c9: { // 0x49a7c9: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0049a7cd: { // 0x49a7cd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a7ce: { // 0x49a7ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a7cf: { // 0x49a7cf: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L0049a7d3: { // 0x49a7d3: e828aa0a00 CALL 0x00545200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545200u,4827096u,op); flags=s.arithmetic_flags;
  }
  L0049a7d8: { // 0x49a7d8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049a7da: { // 0x49a7da: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0049a7de: { // 0x49a7de: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0049a7e2: { // 0x49a7e2: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L0049a7e6: { // 0x49a7e6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049a7e8: { // 0x49a7e8: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0049a7eb: { // 0x49a7eb: 6689442468 MOV word ptr [ESP + 0x68],AX
    m.w16((f.sp+0x00000068u), (s.ax & 0xffffu));
  }
  L0049a7f0: { // 0x49a7f0: 66894c246a MOV word ptr [ESP + 0x6a],CX
    m.w16((f.sp+0x0000006au), (s.cx & 0xffffu));
  }
  L0049a7f5: { // 0x49a7f5: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0049a7f9: { // 0x49a7f9: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L0049a7fd: { // 0x49a7fd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a7fe: { // 0x49a7fe: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a7ff: { // 0x49a7ff: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a801: { // 0x49a801: e8faa90a00 CALL 0x00545200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545200u,4827142u,op); flags=s.arithmetic_flags;
  }
  L0049a806: { // 0x49a806: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049a808: { // 0x49a808: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0049a80a: { // 0x49a80a: 6689442464 MOV word ptr [ESP + 0x64],AX
    m.w16((f.sp+0x00000064u), (s.ax & 0xffffu));
  }
  L0049a80f: { // 0x49a80f: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L0049a813: { // 0x49a813: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0049a816: { // 0x49a816: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L0049a81a: { // 0x49a81a: 66894c2466 MOV word ptr [ESP + 0x66],CX
    m.w16((f.sp+0x00000066u), (s.cx & 0xffffu));
  }
  L0049a81f: { // 0x49a81f: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0049a823: { // 0x49a823: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a824: { // 0x49a824: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a825: { // 0x49a825: 8d44246c LEA EAX,[ESP + 0x6c]
    s.ax = (f.sp+0x0000006cu);
  }
  L0049a829: { // 0x49a829: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a82a: { // 0x49a82a: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L0049a82e: { // 0x49a82e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a82f: { // 0x49a82f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a830: { // 0x49a830: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a832: { // 0x49a832: e839030000 CALL 0x0049ab70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049ab70u,4827191u,op); flags=s.arithmetic_flags;
  }
  L0049a837: { // 0x49a837: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a839: { // 0x49a839: 7525 JNZ 0x0049a860
    if(integer::condition("JNZ",flags)) goto L0049a860;
  }
  L0049a83b: { // 0x49a83b: 8b8e04010000 MOV ECX,dword ptr [ESI + 0x104]
    s.cx = m.r32((s.si+0x00000104u));
  }
  L0049a841: { // 0x49a841: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0049a842: { // 0x49a842: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L0049a844: { // 0x49a844: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L0049a846: { // 0x49a846: 0f8c67ffffff JL 0x0049a7b3
    if(integer::condition("JL",flags)) goto L0049a7b3;
  }
  L0049a84c: { // 0x49a84c: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0049a850: { // 0x49a850: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L0049a854: { // 0x49a854: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049a855: { // 0x49a855: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049a856: { // 0x49a856: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049a857: { // 0x49a857: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0049a859: { // 0x49a859: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049a85a: { // 0x49a85a: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L0049a85d: { // 0x49a85d: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0049a860: { // 0x49a860: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0049a864: { // 0x49a864: 8b542468 MOV EDX,dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  L0049a868: { // 0x49a868: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049a869: { // 0x49a869: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049a86a: { // 0x49a86a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049a86b: { // 0x49a86b: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0049a86d: { // 0x49a86d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049a86e: { // 0x49a86e: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L0049a871: { // 0x49a871: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0049a874: { // 0x49a874: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0049a878: { // 0x49a878: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a87a: { // 0x49a87a: 74d0 JZ 0x0049a84c
    if(integer::condition("JZ",flags)) goto L0049a84c;
  }
  L0049a87c: { // 0x49a87c: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0049a87e: { // 0x49a87e: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049a880: { // 0x49a880: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0049a882: { // 0x49a882: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L0049a884: { // 0x49a884: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0049a885: { // 0x49a885: 83fb02 CMP EBX,0x2
    (void)integer::sub(s.bx,0x00000002u,32,flags);
  }
  L0049a888: { // 0x49a888: 0f8508020000 JNZ 0x0049aa96
    if(integer::condition("JNZ",flags)) goto L0049aa96;
  }
  L0049a88e: { // 0x49a88e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a88f: { // 0x49a88f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a890: { // 0x49a890: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L0049a894: { // 0x49a894: e8072cf9ff CALL 0x0042d4a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042d4a0u,4827289u,op); flags=s.arithmetic_flags;
  }
  L0049a899: { // 0x49a899: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L0049a89f: { // 0x49a89f: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0049a8a1: { // 0x49a8a1: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0049a8a3: { // 0x49a8a3: c7442444a0757800 MOV dword ptr [ESP + 0x44],0x7875a0
    m.w32((f.sp+0x00000044u), 0x007875a0u);
  }
  L0049a8ab: { // 0x49a8ab: c74424580a000000 MOV dword ptr [ESP + 0x58],0xa
    m.w32((f.sp+0x00000058u), 0x0000000au);
  }
  L0049a8b3: { // 0x49a8b3: 896c2454 MOV dword ptr [ESP + 0x54],EBP
    m.w32((f.sp+0x00000054u), s.bp);
  }
  L0049a8b7: { // 0x49a8b7: 0f8ed3000000 JLE 0x0049a990
    if(integer::condition("JLE",flags)) goto L0049a990;
  }
  L0049a8bd: { // 0x49a8bd: 8b6c2470 MOV EBP,dword ptr [ESP + 0x70]
    s.bp = m.r32((f.sp+0x00000070u));
  }
  L0049a8c1: { // 0x49a8c1: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049a8c3: { // 0x49a8c3: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  L0049a8c9: { // 0x49a8c9: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0049a8cd: { // 0x49a8cd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a8ce: { // 0x49a8ce: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L0049a8d2: { // 0x49a8d2: 8d0c47 LEA ECX,[EDI + EAX*0x2]
    s.cx = (s.di+(s.ax * 0x00000002u));
  }
  L0049a8d5: { // 0x49a8d5: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L0049a8d9: { // 0x49a8d9: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0049a8dd: { // 0x49a8dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a8de: { // 0x49a8de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a8e0: { // 0x49a8e0: e81ba90a00 CALL 0x00545200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545200u,4827365u,op); flags=s.arithmetic_flags;
  }
  L0049a8e5: { // 0x49a8e5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049a8e7: { // 0x49a8e7: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L0049a8eb: { // 0x49a8eb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049a8ed: { // 0x49a8ed: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a8ee: { // 0x49a8ee: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049a8f0: { // 0x49a8f0: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0049a8f3: { // 0x49a8f3: 668944247c MOV word ptr [ESP + 0x7c],AX
    m.w16((f.sp+0x0000007cu), (s.ax & 0xffffu));
  }
  L0049a8f8: { // 0x49a8f8: 66894c247e MOV word ptr [ESP + 0x7e],CX
    m.w16((f.sp+0x0000007eu), (s.cx & 0xffffu));
  }
  L0049a8fd: { // 0x49a8fd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a8ff: { // 0x49a8ff: e84ccb0b00 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4827396u,op); flags=s.arithmetic_flags;
  }
  L0049a904: { // 0x49a904: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a906: { // 0x49a906: 7523 JNZ 0x0049a92b
    if(integer::condition("JNZ",flags)) goto L0049a92b;
  }
  L0049a908: { // 0x49a908: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L0049a90c: { // 0x49a90c: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0049a910: { // 0x49a910: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a911: { // 0x49a911: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a912: { // 0x49a912: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0049a916: { // 0x49a916: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a917: { // 0x49a917: 8d842480000000 LEA EAX,[ESP + 0x80]
    s.ax = (f.sp+0x00000080u);
  }
  L0049a91e: { // 0x49a91e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a91f: { // 0x49a91f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a920: { // 0x49a920: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a922: { // 0x49a922: e849020000 CALL 0x0049ab70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049ab70u,4827431u,op); flags=s.arithmetic_flags;
  }
  L0049a927: { // 0x49a927: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a929: { // 0x49a929: 7508 JNZ 0x0049a933
    if(integer::condition("JNZ",flags)) goto L0049a933;
  }
  L0049a92b: { // 0x49a92b: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0049a92c: { // 0x49a92c: 83ff0f CMP EDI,0xf
    (void)integer::sub(s.di,0x0000000fu,32,flags);
  }
  L0049a92f: { // 0x49a92f: 7c92 JL 0x0049a8c3
    if(integer::condition("JL",flags)) goto L0049a8c3;
  }
  L0049a931: { // 0x49a931: eb4a JMP 0x0049a97d
    goto L0049a97d;
  }
  L0049a933: { // 0x49a933: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0049a937: { // 0x49a937: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L0049a93b: { // 0x49a93b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049a93d: { // 0x49a93d: 7c28 JL 0x0049a967
    if(integer::condition("JL",flags)) goto L0049a967;
  }
  L0049a93f: { // 0x49a93f: 8a442451 MOV AL,byte ptr [ESP + 0x51]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000051u)));
  }
  L0049a943: { // 0x49a943: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a945: { // 0x49a945: 7504 JNZ 0x0049a94b
    if(integer::condition("JNZ",flags)) goto L0049a94b;
  }
  L0049a947: { // 0x49a947: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049a949: { // 0x49a949: 7532 JNZ 0x0049a97d
    if(integer::condition("JNZ",flags)) goto L0049a97d;
  }
  L0049a94b: { // 0x49a94b: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L0049a94f: { // 0x49a94f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049a951: { // 0x49a951: 7e2a JLE 0x0049a97d
    if(integer::condition("JLE",flags)) goto L0049a97d;
  }
  L0049a953: { // 0x49a953: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L0049a957: { // 0x49a957: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0049a959: { // 0x49a959: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049a95b: { // 0x49a95b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a95c: { // 0x49a95c: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L0049a960: { // 0x49a960: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4827491u,op); flags=s.arithmetic_flags;
  }
  L0049a963: { // 0x49a963: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a965: { // 0x49a965: 7416 JZ 0x0049a97d
    if(integer::condition("JZ",flags)) goto L0049a97d;
  }
  L0049a967: { // 0x49a967: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L0049a96b: { // 0x49a96b: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L0049a96f: { // 0x49a96f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049a971: { // 0x49a971: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0049a972: { // 0x49a972: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0049a976: { // 0x49a976: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0049a97a: { // 0x49a97a: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  L0049a97d: { // 0x49a97d: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L0049a983: { // 0x49a983: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0049a984: { // 0x49a984: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0049a986: { // 0x49a986: 0f8c35ffffff JL 0x0049a8c1
    if(integer::condition("JL",flags)) goto L0049a8c1;
  }
  L0049a98c: { // 0x49a98c: 8b6c2454 MOV EBP,dword ptr [ESP + 0x54]
    s.bp = m.r32((f.sp+0x00000054u));
  }
  L0049a990: { // 0x49a990: 668b442414 MOV AX,word ptr [ESP + 0x14]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000014u)));
  }
  L0049a995: { // 0x49a995: 8b1540a98300 MOV EDX,dword ptr [0x0083a940]
    s.dx = m.r32((0x0083a940u));
  }
  L0049a99b: { // 0x49a99b: 668b4c2416 MOV CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000016u)));
  }
  L0049a9a0: { // 0x49a9a0: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0049a9a3: { // 0x49a9a3: 753b JNZ 0x0049a9e0
    if(integer::condition("JNZ",flags)) goto L0049a9e0;
  }
  L0049a9a5: { // 0x49a9a5: 663b0d42a98300 CMP CX,word ptr [0x0083a942]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x0083a942u)),16,flags);
  }
  L0049a9ac: { // 0x49a9ac: 7532 JNZ 0x0049a9e0
    if(integer::condition("JNZ",flags)) goto L0049a9e0;
  }
  L0049a9ae: { // 0x49a9ae: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0049a9b0: { // 0x49a9b0: 7e24 JLE 0x0049a9d6
    if(integer::condition("JLE",flags)) goto L0049a9d6;
  }
  L0049a9b2: { // 0x49a9b2: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0049a9b7: { // 0x49a9b7: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0049a9b8: { // 0x49a9b8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a9b9: { // 0x49a9b9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049a9bb: { // 0x49a9bb: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L0049a9c1: { // 0x49a9c1: e87a541900 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4827590u,op); flags=s.arithmetic_flags;
  }
  L0049a9c6: { // 0x49a9c6: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0049a9ca: { // 0x49a9ca: 8b0c82 MOV ECX,dword ptr [EDX + EAX*0x4]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0049a9cd: { // 0x49a9cd: 894c246c MOV dword ptr [ESP + 0x6c],ECX
    m.w32((f.sp+0x0000006cu), s.cx);
  }
  L0049a9d1: { // 0x49a9d1: e987000000 JMP 0x0049aa5d
    goto L0049aa5d;
  }
  L0049a9d6: { // 0x49a9d6: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L0049a9da: { // 0x49a9da: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0049a9de: { // 0x49a9de: eb7d JMP 0x0049aa5d
    goto L0049aa5d;
  }
  L0049a9e0: { // 0x49a9e0: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0049a9e2: { // 0x49a9e2: 8b542454 MOV EDX,dword ptr [ESP + 0x54]
    s.dx = m.r32((f.sp+0x00000054u));
  }
  L0049a9e6: { // 0x49a9e6: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L0049a9e9: { // 0x49a9e9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049a9eb: { // 0x49a9eb: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0049a9ed: { // 0x49a9ed: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0049a9f1: { // 0x49a9f1: 7e66 JLE 0x0049aa59
    if(integer::condition("JLE",flags)) goto L0049aa59;
  }
  L0049a9f3: { // 0x49a9f3: eb0a JMP 0x0049a9ff
    goto L0049a9ff;
  }
  L0049a9f5: { // 0x49a9f5: 668b442414 MOV AX,word ptr [ESP + 0x14]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000014u)));
  }
  L0049a9fa: { // 0x49a9fa: 668b4c2416 MOV CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000016u)));
  }
  L0049a9ff: { // 0x49a9ff: 662b4cba02 SUB CX,word ptr [EDX + EDI*0x4 + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.dx+(s.di * 0x00000004u)+0x00000002u)),16,flags));
  }
  L0049aa04: { // 0x49aa04: 662b04ba SUB AX,word ptr [EDX + EDI*0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.dx+(s.di * 0x00000004u))),16,flags));
  }
  L0049aa08: { // 0x49aa08: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0049aa0b: { // 0x49aa0b: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0049aa0e: { // 0x49aa0e: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0049aa11: { // 0x49aa11: 8954247c MOV dword ptr [ESP + 0x7c],EDX
    m.w32((f.sp+0x0000007cu), s.dx);
  }
  L0049aa15: { // 0x49aa15: db44247c FILD dword ptr [ESP + 0x7c]
    const auto address=(f.sp+0x0000007cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0049aa19: { // 0x49aa19: 8944247c MOV dword ptr [ESP + 0x7c],EAX
    m.w32((f.sp+0x0000007cu), s.ax);
  }
  L0049aa1d: { // 0x49aa1d: db44247c FILD dword ptr [ESP + 0x7c]
    const auto address=(f.sp+0x0000007cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0049aa21: { // 0x49aa21: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0049aa23: { // 0x49aa23: d8c9 FMUL st1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0049aa25: { // 0x49aa25: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0049aa27: { // 0x49aa27: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0049aa29: { // 0x49aa29: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0049aa2b: { // 0x49aa2b: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0049aa2e: { // 0x49aa2e: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0049aa30: { // 0x49aa30: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0049aa32: { // 0x49aa32: e849f60100 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4827703u,op); flags=s.arithmetic_flags;
  }
  L0049aa37: { // 0x49aa37: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0049aa3a: { // 0x49aa3a: e811002d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4827711u,op); flags=s.arithmetic_flags;
  }
  L0049aa3f: { // 0x49aa3f: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0049aa43: { // 0x49aa43: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L0049aa46: { // 0x49aa46: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0049aa49: { // 0x49aa49: 7404 JZ 0x0049aa4f
    if(integer::condition("JZ",flags)) goto L0049aa4f;
  }
  L0049aa4b: { // 0x49aa4b: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0049aa4d: { // 0x49aa4d: 7d05 JGE 0x0049aa54
    if(integer::condition("JGE",flags)) goto L0049aa54;
  }
  L0049aa4f: { // 0x49aa4f: 8b1cba MOV EBX,dword ptr [EDX + EDI*0x4]
    s.bx = m.r32((s.dx+(s.di * 0x00000004u)));
  }
  L0049aa52: { // 0x49aa52: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049aa54: { // 0x49aa54: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0049aa55: { // 0x49aa55: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0049aa57: { // 0x49aa57: 7c9c JL 0x0049a9f5
    if(integer::condition("JL",flags)) goto L0049a9f5;
  }
  L0049aa59: { // 0x49aa59: 895c246c MOV dword ptr [ESP + 0x6c],EBX
    m.w32((f.sp+0x0000006cu), s.bx);
  }
  L0049aa5d: { // 0x49aa5d: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0049aa5f: { // 0x49aa5f: c7442444e0757800 MOV dword ptr [ESP + 0x44],0x7875e0
    m.w32((f.sp+0x00000044u), 0x007875e0u);
  }
  L0049aa67: { // 0x49aa67: 0f84dffdffff JZ 0x0049a84c
    if(integer::condition("JZ",flags)) goto L0049a84c;
  }
  L0049aa6d: { // 0x49aa6d: 8a442451 MOV AL,byte ptr [ESP + 0x51]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000051u)));
  }
  L0049aa71: { // 0x49aa71: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049aa73: { // 0x49aa73: 0f84d3fdffff JZ 0x0049a84c
    if(integer::condition("JZ",flags)) goto L0049a84c;
  }
  L0049aa79: { // 0x49aa79: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049aa7a: { // 0x49aa7a: e8fc2b2d00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4827775u,op); flags=s.arithmetic_flags;
  }
  L0049aa7f: { // 0x49aa7f: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0049aa83: { // 0x49aa83: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L0049aa87: { // 0x49aa87: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0049aa8a: { // 0x49aa8a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0049aa8c: { // 0x49aa8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049aa8d: { // 0x49aa8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049aa8e: { // 0x49aa8e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049aa8f: { // 0x49aa8f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049aa90: { // 0x49aa90: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L0049aa93: { // 0x49aa93: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0049aa96: { // 0x49aa96: 8b8e00010000 MOV ECX,dword ptr [ESI + 0x100]
    s.cx = m.r32((s.si+0x00000100u));
  }
  L0049aa9c: { // 0x49aa9c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049aa9e: { // 0x49aa9e: 0f8ea8fdffff JLE 0x0049a84c
    if(integer::condition("JLE",flags)) goto L0049a84c;
  }
  L0049aaa4: { // 0x49aaa4: 8b542468 MOV EDX,dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  L0049aaa8: { // 0x49aaa8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0049aaaa: { // 0x49aaaa: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0049aaae: { // 0x49aaae: 8d042f LEA EAX,[EDI + EBP*0x1]
    s.ax = (s.di+(s.bp * 0x00000001u));
  }
  L0049aab1: { // 0x49aab1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049aab2: { // 0x49aab2: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049aab4: { // 0x49aab4: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L0049aab8: { // 0x49aab8: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0049aabc: { // 0x49aabc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049aabd: { // 0x49aabd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049aabf: { // 0x49aabf: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0049aac3: { // 0x49aac3: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0049aac5: { // 0x49aac5: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L0049aac9: { // 0x49aac9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049aaca: { // 0x49aaca: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L0049aace: { // 0x49aace: e82da70a00 CALL 0x00545200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545200u,4827859u,op); flags=s.arithmetic_flags;
  }
  L0049aad3: { // 0x49aad3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049aad5: { // 0x49aad5: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0049aad9: { // 0x49aad9: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049aadd: { // 0x49aadd: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0049aae1: { // 0x49aae1: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049aae3: { // 0x49aae3: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0049aae6: { // 0x49aae6: 6689442474 MOV word ptr [ESP + 0x74],AX
    m.w16((f.sp+0x00000074u), (s.ax & 0xffffu));
  }
  L0049aaeb: { // 0x49aaeb: 66894c2476 MOV word ptr [ESP + 0x76],CX
    m.w16((f.sp+0x00000076u), (s.cx & 0xffffu));
  }
  L0049aaf0: { // 0x49aaf0: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0049aaf4: { // 0x49aaf4: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L0049aaf8: { // 0x49aaf8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049aaf9: { // 0x49aaf9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049aafa: { // 0x49aafa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049aafc: { // 0x49aafc: e8ffa60a00 CALL 0x00545200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545200u,4827905u,op); flags=s.arithmetic_flags;
  }
  L0049ab01: { // 0x49ab01: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049ab03: { // 0x49ab03: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0049ab05: { // 0x49ab05: 6689442464 MOV word ptr [ESP + 0x64],AX
    m.w16((f.sp+0x00000064u), (s.ax & 0xffffu));
  }
  L0049ab0a: { // 0x49ab0a: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L0049ab0e: { // 0x49ab0e: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0049ab11: { // 0x49ab11: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L0049ab15: { // 0x49ab15: 66894c2466 MOV word ptr [ESP + 0x66],CX
    m.w16((f.sp+0x00000066u), (s.cx & 0xffffu));
  }
  L0049ab1a: { // 0x49ab1a: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0049ab1e: { // 0x49ab1e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ab1f: { // 0x49ab1f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ab20: { // 0x49ab20: 8d44246c LEA EAX,[ESP + 0x6c]
    s.ax = (f.sp+0x0000006cu);
  }
  L0049ab24: { // 0x49ab24: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ab25: { // 0x49ab25: 8d8c2480000000 LEA ECX,[ESP + 0x80]
    s.cx = (f.sp+0x00000080u);
  }
  L0049ab2c: { // 0x49ab2c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ab2d: { // 0x49ab2d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ab2e: { // 0x49ab2e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ab30: { // 0x49ab30: e83b000000 CALL 0x0049ab70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049ab70u,4827957u,op); flags=s.arithmetic_flags;
  }
  L0049ab35: { // 0x49ab35: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ab37: { // 0x49ab37: 7523 JNZ 0x0049ab5c
    if(integer::condition("JNZ",flags)) goto L0049ab5c;
  }
  L0049ab39: { // 0x49ab39: 8b8e00010000 MOV ECX,dword ptr [ESI + 0x100]
    s.cx = m.r32((s.si+0x00000100u));
  }
  L0049ab3f: { // 0x49ab3f: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0049ab40: { // 0x49ab40: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L0049ab42: { // 0x49ab42: 0f8c66ffffff JL 0x0049aaae
    if(integer::condition("JL",flags)) goto L0049aaae;
  }
  L0049ab48: { // 0x49ab48: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0049ab4c: { // 0x49ab4c: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L0049ab50: { // 0x49ab50: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049ab51: { // 0x49ab51: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ab52: { // 0x49ab52: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049ab53: { // 0x49ab53: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0049ab55: { // 0x49ab55: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049ab56: { // 0x49ab56: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L0049ab59: { // 0x49ab59: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0049ab5c: { // 0x49ab5c: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0049ab60: { // 0x49ab60: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L0049ab64: { // 0x49ab64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049ab65: { // 0x49ab65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ab66: { // 0x49ab66: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049ab67: { // 0x49ab67: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0049ab69: { // 0x49ab69: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049ab6a: { // 0x49ab6a: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L0049ab6d: { // 0x49ab6d: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00145280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545280: { // 0x545280: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00545283: { // 0x545283: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L00545289: { // 0x545289: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054528a: { // 0x54528a: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L00545290: { // 0x545290: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00545294: { // 0x545294: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00545298: { // 0x545298: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00545299: { // 0x545299: 8ba9f8000000 MOV EBP,dword ptr [ECX + 0xf8]
    s.bp = m.r32((s.cx+0x000000f8u));
  }
  L0054529f: { // 0x54529f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005452a0: { // 0x5452a0: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L005452a3: { // 0x5452a3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005452a4: { // 0x5452a4: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L005452a6: { // 0x5452a6: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L005452a9: { // 0x5452a9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005452ab: { // 0x5452ab: 7405 JZ 0x005452b2
    if(integer::condition("JZ",flags)) goto L005452b2;
  }
  L005452ad: { // 0x5452ad: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L005452af: { // 0x5452af: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005452b0: { // 0x5452b0: eb02 JMP 0x005452b4
    goto L005452b4;
  }
  L005452b2: { // 0x5452b2: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L005452b4: { // 0x5452b4: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L005452b6: { // 0x5452b6: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L005452b8: { // 0x5452b8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005452b9: { // 0x5452b9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005452bb: { // 0x5452bb: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L005452bd: { // 0x5452bd: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005452bf: { // 0x5452bf: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005452c1: { // 0x5452c1: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005452c3: { // 0x5452c3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005452c7: { // 0x5452c7: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  L005452c9: { // 0x5452c9: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L005452cb: { // 0x5452cb: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005452cf: { // 0x5452cf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005452d0: { // 0x5452d0: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005452d2: { // 0x5452d2: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L005452d5: { // 0x5452d5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005452d6: { // 0x5452d6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005452d7: { // 0x5452d7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005452d8: { // 0x5452d8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005452db: { // 0x5452db: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00145200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545200: { // 0x545200: 8b81f8000000 MOV EAX,dword ptr [ECX + 0xf8]
    s.ax = m.r32((s.cx+0x000000f8u));
  }
  L00545206: { // 0x545206: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545207: { // 0x545207: 8bb1fc000000 MOV ESI,dword ptr [ECX + 0xfc]
    s.si = m.r32((s.cx+0x000000fcu));
  }
  L0054520d: { // 0x54520d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054520e: { // 0x54520e: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00545212: { // 0x545212: 8b89f0000000 MOV ECX,dword ptr [ECX + 0xf0]
    s.cx = m.r32((s.cx+0x000000f0u));
  }
  L00545218: { // 0x545218: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0054521a: { // 0x54521a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0054521c: { // 0x54521c: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0054521f: { // 0x54521f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545221: { // 0x545221: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00545222: { // 0x545222: 8d7001 LEA ESI,[EAX + 0x1]
    s.si = (s.ax+0x00000001u);
  }
  L00545225: { // 0x545225: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00545227: { // 0x545227: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00545229: { // 0x545229: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0054522b: { // 0x54522b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0054522f: { // 0x54522f: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00545231: { // 0x545231: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00545233: { // 0x545233: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L00545235: { // 0x545235: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00545238: { // 0x545238: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545239: { // 0x545239: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_0009ab70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049ab70: { // 0x49ab70: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0049ab73: { // 0x49ab73: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049ab74: { // 0x49ab74: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ab75: { // 0x49ab75: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ab76: { // 0x49ab76: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049ab77: { // 0x49ab77: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L0049ab7b: { // 0x49ab7b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049ab7d: { // 0x49ab7d: 83ff04 CMP EDI,0x4
    (void)integer::sub(s.di,0x00000004u,32,flags);
  }
  L0049ab80: { // 0x49ab80: 750c JNZ 0x0049ab8e
    if(integer::condition("JNZ",flags)) goto L0049ab8e;
  }
  L0049ab82: { // 0x49ab82: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049ab83: { // 0x49ab83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ab84: { // 0x49ab84: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049ab85: { // 0x49ab85: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0049ab87: { // 0x49ab87: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049ab88: { // 0x49ab88: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0049ab8b: { // 0x49ab8b: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0049ab8e: { // 0x49ab8e: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L0049ab92: { // 0x49ab92: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049ab94: { // 0x49ab94: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049ab96: { // 0x49ab96: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0049ab98: { // 0x49ab98: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ab99: { // 0x49ab99: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0049ab9b: { // 0x49ab9b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049ab9d: { // 0x49ab9d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049ab9f: { // 0x49ab9f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049aba0: { // 0x49aba0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049aba1: { // 0x49aba1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049aba3: { // 0x49aba3: e858a90a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4828072u,op); flags=s.arithmetic_flags;
  }
  L0049aba8: { // 0x49aba8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049abaa: { // 0x49abaa: e8b1d7fdff CALL 0x00478360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00478360u,4828079u,op); flags=s.arithmetic_flags;
  }
  L0049abaf: { // 0x49abaf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049abb1: { // 0x49abb1: 750a JNZ 0x0049abbd
    if(integer::condition("JNZ",flags)) goto L0049abbd;
  }
  L0049abb3: { // 0x49abb3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049abb4: { // 0x49abb4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049abb5: { // 0x49abb5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049abb6: { // 0x49abb6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049abb7: { // 0x49abb7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0049abba: { // 0x49abba: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0049abbd: { // 0x49abbd: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0049abc1: { // 0x49abc1: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0049abc5: { // 0x49abc5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049abc7: { // 0x49abc7: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0049abc9: { // 0x49abc9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049abca: { // 0x49abca: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049abcb: { // 0x49abcb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049abcd: { // 0x49abcd: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049abcf: { // 0x49abcf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049abd0: { // 0x49abd0: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L0049abd4: { // 0x49abd4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049abd5: { // 0x49abd5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049abd7: { // 0x49abd7: e824a90a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4828124u,op); flags=s.arithmetic_flags;
  }
  L0049abdc: { // 0x49abdc: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049abde: { // 0x49abde: e87dd7fdff CALL 0x00478360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00478360u,4828131u,op); flags=s.arithmetic_flags;
  }
  L0049abe3: { // 0x49abe3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049abe5: { // 0x49abe5: 750a JNZ 0x0049abf1
    if(integer::condition("JNZ",flags)) goto L0049abf1;
  }
  L0049abe7: { // 0x49abe7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049abe8: { // 0x49abe8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049abe9: { // 0x49abe9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049abea: { // 0x49abea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049abeb: { // 0x49abeb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0049abee: { // 0x49abee: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0049abf1: { // 0x49abf1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049abf2: { // 0x49abf2: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0049abf6: { // 0x49abf6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049abf7: { // 0x49abf7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049abf8: { // 0x49abf8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049abf9: { // 0x49abf9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049abfb: { // 0x49abfb: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0049abff: { // 0x49abff: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0049ac03: { // 0x49ac03: e8f8a80a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4828168u,op); flags=s.arithmetic_flags;
  }
  L0049ac08: { // 0x49ac08: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049ac0a: { // 0x49ac0a: e85166fdff CALL 0x00471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4828175u,op); flags=s.arithmetic_flags;
  }
  L0049ac0f: { // 0x49ac0f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ac11: { // 0x49ac11: 740c JZ 0x0049ac1f
    if(integer::condition("JZ",flags)) goto L0049ac1f;
  }
  L0049ac13: { // 0x49ac13: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049ac14: { // 0x49ac14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ac15: { // 0x49ac15: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049ac16: { // 0x49ac16: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0049ac18: { // 0x49ac18: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049ac19: { // 0x49ac19: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0049ac1c: { // 0x49ac1c: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0049ac1f: { // 0x49ac1f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ac20: { // 0x49ac20: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0049ac24: { // 0x49ac24: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ac25: { // 0x49ac25: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ac26: { // 0x49ac26: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049ac27: { // 0x49ac27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ac29: { // 0x49ac29: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0049ac2d: { // 0x49ac2d: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0049ac31: { // 0x49ac31: e8caa80a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4828214u,op); flags=s.arithmetic_flags;
  }
  L0049ac36: { // 0x49ac36: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049ac38: { // 0x49ac38: e82366fdff CALL 0x00471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4828221u,op); flags=s.arithmetic_flags;
  }
  L0049ac3d: { // 0x49ac3d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049ac3e: { // 0x49ac3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ac3f: { // 0x49ac3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ac41: { // 0x49ac41: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049ac42: { // 0x49ac42: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049ac43: { // 0x49ac43: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0049ac46: { // 0x49ac46: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0049ac49: { // 0x49ac49: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
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

void f_00078360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00478360: { // 0x478360: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00478364: { // 0x478364: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00478365: { // 0x478365: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00478366: { // 0x478366: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00478367: { // 0x478367: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L0047836a: { // 0x47836a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047836b: { // 0x47836b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0047836d: { // 0x47836d: 0f8447010000 JZ 0x004784ba
    if(integer::condition("JZ",flags)) goto L004784ba;
  }
  L00478373: { // 0x478373: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00478377: { // 0x478377: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0047837b: { // 0x47837b: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0047837f: { // 0x47837f: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L00478382: { // 0x478382: 741d JZ 0x004783a1
    if(integer::condition("JZ",flags)) goto L004783a1;
  }
  L00478384: { // 0x478384: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00478385: { // 0x478385: 8d4624 LEA EAX,[ESI + 0x24]
    s.ax = (s.si+0x00000024u);
  }
  L00478388: { // 0x478388: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00478389: { // 0x478389: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047838a: { // 0x47838a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047838f: { // 0x47838f: e8ec490d00 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4686740u,op); flags=s.arithmetic_flags;
  }
  L00478394: { // 0x478394: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00478396: { // 0x478396: 7409 JZ 0x004783a1
    if(integer::condition("JZ",flags)) goto L004783a1;
  }
  L00478398: { // 0x478398: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478399: { // 0x478399: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047839a: { // 0x47839a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047839b: { // 0x47839b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047839d: { // 0x47839d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047839e: { // 0x47839e: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004783a1: { // 0x4783a1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004783a5: { // 0x4783a5: ba00010000 MOV EDX,0x100
    s.dx = 0x00000100u;
  }
  L004783aa: { // 0x4783aa: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004783ad: { // 0x4783ad: 7438 JZ 0x004783e7
    if(integer::condition("JZ",flags)) goto L004783e7;
  }
  L004783af: { // 0x4783af: 0fbe8e1b010000 MOVSX ECX,byte ptr [ESI + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004783b6: { // 0x4783b6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004783b8: { // 0x4783b8: 7418 JZ 0x004783d2
    if(integer::condition("JZ",flags)) goto L004783d2;
  }
  L004783ba: { // 0x4783ba: 859640010000 TEST dword ptr [ESI + 0x140],EDX
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.dx),32,flags);
  }
  L004783c0: { // 0x4783c0: 7407 JZ 0x004783c9
    if(integer::condition("JZ",flags)) goto L004783c9;
  }
  L004783c2: { // 0x4783c2: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L004783c5: { // 0x4783c5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004783c7: { // 0x4783c7: 741e JZ 0x004783e7
    if(integer::condition("JZ",flags)) goto L004783e7;
  }
  L004783c9: { // 0x4783c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004783ca: { // 0x4783ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004783cb: { // 0x4783cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004783cc: { // 0x4783cc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004783ce: { // 0x4783ce: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004783cf: { // 0x4783cf: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004783d2: { // 0x4783d2: 859640010000 TEST dword ptr [ESI + 0x140],EDX
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.dx),32,flags);
  }
  L004783d8: { // 0x4783d8: 740d JZ 0x004783e7
    if(integer::condition("JZ",flags)) goto L004783e7;
  }
  L004783da: { // 0x4783da: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004783dc: { // 0x4783dc: 7509 JNZ 0x004783e7
    if(integer::condition("JNZ",flags)) goto L004783e7;
  }
  L004783de: { // 0x4783de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004783df: { // 0x4783df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004783e0: { // 0x4783e0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004783e1: { // 0x4783e1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004783e3: { // 0x4783e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004783e4: { // 0x4783e4: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004783e7: { // 0x4783e7: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L004783e9: { // 0x4783e9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004783ec: { // 0x4783ec: 740e JZ 0x004783fc
    if(integer::condition("JZ",flags)) goto L004783fc;
  }
  L004783ee: { // 0x4783ee: 0fbebe1b010000 MOVSX EDI,byte ptr [ESI + 0x11b]
    s.di = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004783f5: { // 0x4783f5: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L004783f8: { // 0x4783f8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004783fa: { // 0x4783fa: 7514 JNZ 0x00478410
    if(integer::condition("JNZ",flags)) goto L00478410;
  }
  L004783fc: { // 0x4783fc: 859640010000 TEST dword ptr [ESI + 0x140],EDX
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.dx),32,flags);
  }
  L00478402: { // 0x478402: 740c JZ 0x00478410
    if(integer::condition("JZ",flags)) goto L00478410;
  }
  L00478404: { // 0x478404: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00478406: { // 0x478406: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L00478408: { // 0x478408: 8a8628010000 MOV AL,byte ptr [ESI + 0x128]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000128u)));
  }
  L0047840e: { // 0x47840e: eb08 JMP 0x00478418
    goto L00478418;
  }
  L00478410: { // 0x478410: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00478412: { // 0x478412: 8a8624010000 MOV AL,byte ptr [ESI + 0x124]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000124u)));
  }
  L00478418: { // 0x478418: 8a542418 MOV DL,byte ptr [ESP + 0x18]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000018u)));
  }
  L0047841c: { // 0x47841c: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0047841e: { // 0x47841e: 7405 JZ 0x00478425
    if(integer::condition("JZ",flags)) goto L00478425;
  }
  L00478420: { // 0x478420: 25e0000000 AND EAX,0xe0
    s.ax = integer::logical((s.ax)&(0x000000e0u),32,flags);
  }
  L00478425: { // 0x478425: 8a54241c MOV DL,byte ptr [ESP + 0x1c]
    s.dx = with_al(s.dx, m.r8((f.sp+0x0000001cu)));
  }
  L00478429: { // 0x478429: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0047842b: { // 0x47842b: 7403 JZ 0x00478430
    if(integer::condition("JZ",flags)) goto L00478430;
  }
  L0047842d: { // 0x47842d: 83e05f AND EAX,0x5f
    s.ax = integer::logical((s.ax)&(0x0000005fu),32,flags);
  }
  L00478430: { // 0x478430: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00478432: { // 0x478432: 7409 JZ 0x0047843d
    if(integer::condition("JZ",flags)) goto L0047843d;
  }
  L00478434: { // 0x478434: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478435: { // 0x478435: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478436: { // 0x478436: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478437: { // 0x478437: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00478439: { // 0x478439: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047843a: { // 0x47843a: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0047843d: { // 0x47843d: 8b86ec000000 MOV EAX,dword ptr [ESI + 0xec]
    s.ax = m.r32((s.si+0x000000ecu));
  }
  L00478443: { // 0x478443: 8b7644 MOV ESI,dword ptr [ESI + 0x44]
    s.si = m.r32((s.si+0x00000044u));
  }
  L00478446: { // 0x478446: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L00478449: { // 0x478449: 7445 JZ 0x00478490
    if(integer::condition("JZ",flags)) goto L00478490;
  }
  L0047844b: { // 0x47844b: 8b151ce1a100 MOV EDX,dword ptr [0x00a1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00478451: { // 0x478451: 8b34b2 MOV ESI,dword ptr [EDX + ESI*0x4]
    s.si = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  L00478454: { // 0x478454: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00478456: { // 0x478456: 7438 JZ 0x00478490
    if(integer::condition("JZ",flags)) goto L00478490;
  }
  L00478458: { // 0x478458: 8a9678020000 MOV DL,byte ptr [ESI + 0x278]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000278u)));
  }
  L0047845e: { // 0x47845e: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00478460: { // 0x478460: 742e JZ 0x00478490
    if(integer::condition("JZ",flags)) goto L00478490;
  }
  L00478462: { // 0x478462: 83fd02 CMP EBP,0x2
    (void)integer::sub(s.bp,0x00000002u,32,flags);
  }
  L00478465: { // 0x478465: 7427 JZ 0x0047848e
    if(integer::condition("JZ",flags)) goto L0047848e;
  }
  L00478467: { // 0x478467: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L0047846a: { // 0x47846a: 7422 JZ 0x0047848e
    if(integer::condition("JZ",flags)) goto L0047848e;
  }
  L0047846c: { // 0x47846c: 83fd08 CMP EBP,0x8
    (void)integer::sub(s.bp,0x00000008u,32,flags);
  }
  L0047846f: { // 0x47846f: 741d JZ 0x0047848e
    if(integer::condition("JZ",flags)) goto L0047848e;
  }
  L00478471: { // 0x478471: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00478474: { // 0x478474: 7405 JZ 0x0047847b
    if(integer::condition("JZ",flags)) goto L0047847b;
  }
  L00478476: { // 0x478476: 83fd04 CMP EBP,0x4
    (void)integer::sub(s.bp,0x00000004u,32,flags);
  }
  L00478479: { // 0x478479: 750a JNZ 0x00478485
    if(integer::condition("JNZ",flags)) goto L00478485;
  }
  L0047847b: { // 0x47847b: 8a86fd010000 MOV AL,byte ptr [ESI + 0x1fd]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fdu)));
  }
  L00478481: { // 0x478481: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478483: { // 0x478483: 7509 JNZ 0x0047848e
    if(integer::condition("JNZ",flags)) goto L0047848e;
  }
  L00478485: { // 0x478485: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478486: { // 0x478486: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478487: { // 0x478487: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478488: { // 0x478488: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047848a: { // 0x47848a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047848b: { // 0x47848b: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0047848e: { // 0x47848e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00478490: { // 0x478490: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00478494: { // 0x478494: 8d14c2 LEA EDX,[EDX + EAX*0x8]
    s.dx = (s.dx+(s.ax * 0x00000008u));
  }
  L00478497: { // 0x478497: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00478499: { // 0x478499: d90485d0918300 FLD float ptr [EAX*0x4 + 0x8391d0]
    const auto address=((s.ax * 0x00000004u)+0x008391d0u);
    s.fp.load32(m.r32(address));
  }
  L004784a0: { // 0x4784a0: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004784a6: { // 0x4784a6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004784a8: { // 0x4784a8: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004784ab: { // 0x4784ab: 740d JZ 0x004784ba
    if(integer::condition("JZ",flags)) goto L004784ba;
  }
  L004784ad: { // 0x4784ad: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004784af: { // 0x4784af: 7509 JNZ 0x004784ba
    if(integer::condition("JNZ",flags)) goto L004784ba;
  }
  L004784b1: { // 0x4784b1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004784b2: { // 0x4784b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004784b3: { // 0x4784b3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004784b4: { // 0x4784b4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004784b6: { // 0x4784b6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004784b7: { // 0x4784b7: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004784ba: { // 0x4784ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004784bb: { // 0x4784bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004784bc: { // 0x4784bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004784bd: { // 0x4784bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004784bf: { // 0x4784bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004784c0: { // 0x4784c0: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00071260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00471260: { // 0x471260: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00471261: { // 0x471261: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00471263: { // 0x471263: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00471266: { // 0x471266: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00471269: { // 0x471269: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0047126c: { // 0x47126c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047126d: { // 0x47126d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047126e: { // 0x47126e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047126f: { // 0x47126f: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00471271: { // 0x471271: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00471273: { // 0x471273: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471277: { // 0x471277: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0047127b: { // 0x47127b: 8d3cc500000000 LEA EDI,[EAX*0x8 + 0x0]
    s.di = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L00471282: { // 0x471282: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00471284: { // 0x471284: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00471287: { // 0x471287: 8d1cc500000000 LEA EBX,[EAX*0x8 + 0x0]
    s.bx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L0047128e: { // 0x47128e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00471290: { // 0x471290: 8a450c MOV AL,byte ptr [EBP + 0xc]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000000cu)));
  }
  L00471293: { // 0x471293: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471295: { // 0x471295: 7408 JZ 0x0047129f
    if(integer::condition("JZ",flags)) goto L0047129f;
  }
  L00471297: { // 0x471297: 8b89e8000000 MOV ECX,dword ptr [ECX + 0xe8]
    s.cx = m.r32((s.cx+0x000000e8u));
  }
  L0047129d: { // 0x47129d: eb06 JMP 0x004712a5
    goto L004712a5;
  }
  L0047129f: { // 0x47129f: 8b89e4000000 MOV ECX,dword ptr [ECX + 0xe4]
    s.cx = m.r32((s.cx+0x000000e4u));
  }
  L004712a5: { // 0x4712a5: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L004712a7: { // 0x4712a7: 0f84a2000000 JZ 0x0047134f
    if(integer::condition("JZ",flags)) goto L0047134f;
  }
  L004712ad: { // 0x4712ad: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004712af: { // 0x4712af: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004712b1: { // 0x4712b1: 0f8480000000 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712b7: { // 0x4712b7: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L004712ba: { // 0x4712ba: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L004712bc: { // 0x4712bc: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L004712c0: { // 0x4712c0: 7475 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c2: { // 0x4712c2: 3b7510 CMP ESI,dword ptr [EBP + 0x10]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  L004712c5: { // 0x4712c5: 7470 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c7: { // 0x4712c7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004712c9: { // 0x4712c9: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L004712cd: { // 0x4712cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004712ce: { // 0x4712ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004712d0: { // 0x4712d0: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4657875u,op); flags=s.arithmetic_flags;
  }
  L004712d3: { // 0x4712d3: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004712d5: { // 0x4712d5: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004712d8: { // 0x4712d8: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004712da: { // 0x4712da: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004712df: { // 0x4712df: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L004712e2: { // 0x4712e2: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004712e4: { // 0x4712e4: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004712ea: { // 0x4712ea: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004712ee: { // 0x4712ee: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L004712f0: { // 0x4712f0: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L004712f3: { // 0x4712f3: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L004712f7: { // 0x4712f7: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L004712fb: { // 0x4712fb: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L004712ff: { // 0x4712ff: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00471303: { // 0x471303: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00471305: { // 0x471305: d8c9 FMUL st1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00471307: { // 0x471307: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00471309: { // 0x471309: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0047130b: { // 0x47130b: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0047130d: { // 0x47130d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00471310: { // 0x471310: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471312: { // 0x471312: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471314: { // 0x471314: e8678d0400 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4657945u,op); flags=s.arithmetic_flags;
  }
  L00471319: { // 0x471319: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047131c: { // 0x47131c: e82f972f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4657953u,op); flags=s.arithmetic_flags;
  }
  L00471321: { // 0x471321: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00471325: { // 0x471325: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00471327: { // 0x471327: 7406 JZ 0x0047132f
    if(integer::condition("JZ",flags)) goto L0047132f;
  }
  L00471329: { // 0x471329: 3b442418 CMP EAX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0047132d: { // 0x47132d: 7d08 JGE 0x00471337
    if(integer::condition("JGE",flags)) goto L00471337;
  }
  L0047132f: { // 0x47132f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471333: { // 0x471333: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00471337: { // 0x471337: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047133a: { // 0x47133a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047133c: { // 0x47133c: 0f8575ffffff JNZ 0x004712b7
    if(integer::condition("JNZ",flags)) goto L004712b7;
  }
  L00471342: { // 0x471342: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00471346: { // 0x471346: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471347: { // 0x471347: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471348: { // 0x471348: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471349: { // 0x471349: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0047134b: { // 0x47134b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047134c: { // 0x47134c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047134f: { // 0x47134f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00471351: { // 0x471351: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471352: { // 0x471352: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471353: { // 0x471353: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471354: { // 0x471354: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00471356: { // 0x471356: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471357: { // 0x471357: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};switch(target){
case 0x49a4e0u:f_0009a4e0(m,s,child,op);break;
case 0x545280u:f_00145280(m,s,child,op);break;
case 0x545200u:f_00145200(m,s,child,op);break;
case 0x49ab70u:f_0009ab70(m,s,child,op);break;
case 0x545500u:f_00145500(m,s,child,op);break;
case 0x478360u:f_00078360(m,s,child,op);break;
case 0x471260u:f_00071260(m,s,child,op);break;
default:throw std::domain_error("private_edge unresolved authentic target");}f.sp=child.sp;
}

}
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming){
 need(entry>=0x8000&&size>=0x8000+68&&std::uint64_t(entry)+68<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000==entry,"actual owned32KB Source frame and caller extent");
 leaf::Memory local(storage,entry-0x8000,size);Memory m=world;m.add(local);
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw=false;for(auto value:controls)if(incoming.word(0)==value)cw=true;
 need(cw&&incoming.word(8)==0xffff&&(incoming.word(4)&~0x3800u)==0&&!(in.flags&0x400),"finite12CW/all8TOP emptytags and DFclear");
 need(in.cx==0x81a820&&m.r32(in.cx+0xf0)==16&&m.r32(in.cx+0xf8)==0&&m.r32(in.cx+0xfc)==0&&m.r32(in.cx+0x100)==16&&m.r32(in.cx+0x104)==8,"borrowed numeric Map16x8 projection");
 std::array<unsigned,16>before{};for(unsigned k=0;k<16;++k)before[k]=m.r32(entry+4+4*k);
 need(before[1]==0&&before[4]==1&&before[5]==0&&before[6]==0,"finite side selection/movement/flags input");
 const unsigned out=before[0],desired=before[2],fallback=before[3];const std::array<unsigned,3>points{out,desired,fallback};
 for(unsigned i=0;i<points.size();++i){const auto p=points[i];need(p&&std::uint64_t(p)+4<=0x100000000ull&&(std::uint64_t(p)+4<=entry-0x8000||std::uint64_t(p)>=std::uint64_t(entry)+68),"public4B point outside actual private frame");(void)m.r32(p);for(unsigned j=0;j<i;++j)need(std::uint64_t(p)+4<=points[j]||std::uint64_t(points[j])+4<=p,"disjoint output/desired/fallback points");}
 need(m.r32(0x83a940)==0&&m.r32(desired)!=0&&m.r32(fallback)==0x00130005,"authentic zero sentinel excluded/owned fallback center");
 const unsigned a=m.r16(desired),b=m.r16(desired+2);const std::int64_t y=std::int64_t(a)+b-16;
 need(y>=4&&y<=12&&a==unsigned((y+1)/2)&&b==16+unsigned(y/2),"first valid left-edge finite geometry");const unsigned inside=a+(b<<16),candidate=(a-1)+((b+1)<<16);
 const unsigned table=m.r32(in.cx+0x138);need(table&&table==m.r32(0x81a958)&&std::uint64_t(table)+65536u*4<=0x100000000ull,"same public full65536-entry table");
 // Validate the complete declared public backing extent, without changing data.
 for(unsigned k=0;k<65536;++k)(void)m.r32(table+4*k);
 const unsigned cell0=m.r32(table+4*(512*b+a)),cell1=m.r32(table+4*(512*(b+1)+a-1));need(cell0&&cell1&&cell0!=cell1,"distinct nonnull consumed cells");
 for(unsigned c:{cell0,cell1}){need(std::uint64_t(c)+0x144<=0x100000000ull,"cell field extent");need(!(m.r32(c+0x140)&0x100)&&m.r8(c+0x124)==0&&m.r32(c+0x44)==0xffffffff&&m.r32(c+0xec)==0&&m.r32(c+0xe4)==0,"positive coefficient/empty primary occupancy projection");}
 need(m.r32(0x785738)==0&&m.r32(0x8391d4)==0x40000000&&m.r32(0xa1e11c)==0,"authentic zero threshold/positive2 coefficient/no alternate terrain provider");
 State state{};state.ax=in.ax;state.cx=in.cx;state.dx=in.dx;state.bx=in.bx;state.bp=in.bp;state.si=in.si;state.di=in.di;state.arithmetic_flags=in.flags;state.fp.image=incoming;Frame frame{entry,entry,m.r32(entry)};const Operations op{};
 f_0009a4e0(m,state,frame,op);
 need(frame.sp==entry+32&&state.bx==in.bx&&state.bp==in.bp&&state.si==in.si&&state.di==in.di&&!(state.arithmetic_flags&0x400),"actual RET28/nonvolDF");need(state.ax==out,"actual full output-pointer EAX");
 // Check actual emulated words; these assignments form only the comparison oracle.
 auto expected=before;expected[1]=inside;expected[2]=candidate;expected[3]=0x00130005;expected[5]=0xffffffff;
 Result result{state.ax,state,{}};for(unsigned k=0;k<16;++k){result.words[k]=m.r32(entry+4+4*k);need(result.words[k]==expected[k],"exact actual all16 caller poststate");}return result;
}
}
