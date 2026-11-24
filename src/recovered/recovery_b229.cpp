#include "recovered/recovery_b229_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b229 {
namespace {
void f_0002a1d0(Memory&,State&,Frame&,const Operations&);
void f_00027370(Memory&,State&,Frame&,const Operations&);
void f_00027e90(Memory&,State&,Frame&,const Operations&);
void f_00027060(Memory&,State&,Frame&,const Operations&);
void f_0002ae00(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0014cd80(Memory&,State&,Frame&,const Operations&);
void f_00161d60(Memory&,State&,Frame&,const Operations&);
void f_000068f0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_00105da0(Memory&,State&,Frame&,const Operations&);
void f_00108c50(Memory&,State&,Frame&,const Operations&);
void f_000ca2f0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0002a1d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042a1d0: { // 0x42a1d0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0042a1d3: { // 0x42a1d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042a1d4: { // 0x42a1d4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042a1d5: { // 0x42a1d5: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0042a1d7: { // 0x42a1d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042a1d8: { // 0x42a1d8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042a1d9: { // 0x42a1d9: c6453801 MOV byte ptr [EBP + 0x38],0x1
    m.w8((s.bp+0x00000038u), 0x00000001u);
  }
  L0042a1dd: { // 0x42a1dd: e8aedcffff CALL 0x00427e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427e90u,4366818u); flags=s.arithmetic_flags;
  }
  L0042a1e2: { // 0x42a1e2: 8d7574 LEA ESI,[EBP + 0x74]
    s.si = (s.bp+0x00000074u);
  }
  L0042a1e5: { // 0x42a1e5: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L0042a1ea: { // 0x42a1ea: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0042a1ec: { // 0x42a1ec: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a1ee: { // 0x42a1ee: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),4366833u); flags=s.arithmetic_flags;
  }
  L0042a1f1: { // 0x42a1f1: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  L0042a1f4: { // 0x42a1f4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042a1f5: { // 0x42a1f5: 75f3 JNZ 0x0042a1ea
    if(integer::condition("JNZ",flags)) goto L0042a1ea;
  }
  L0042a1f7: { // 0x42a1f7: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0042a1fb: { // 0x42a1fb: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0042a1ff: { // 0x42a1ff: 894d3c MOV dword ptr [EBP + 0x3c],ECX
    m.w32((s.bp+0x0000003cu), s.cx);
  }
  L0042a202: { // 0x42a202: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a203: { // 0x42a203: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a208: { // 0x42a208: e8f3b21100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4366861u); flags=s.arithmetic_flags;
  }
  L0042a20d: { // 0x42a20d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0042a211: { // 0x42a211: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0042a215: { // 0x42a215: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a216: { // 0x42a216: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a21b: { // 0x42a21b: e8e0b21100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4366880u); flags=s.arithmetic_flags;
  }
  L0042a220: { // 0x42a220: 8b7c2448 MOV EDI,dword ptr [ESP + 0x48]
    s.di = m.r32((f.sp+0x00000048u));
  }
  L0042a224: { // 0x42a224: 8b74243c MOV ESI,dword ptr [ESP + 0x3c]
    s.si = m.r32((f.sp+0x0000003cu));
  }
  L0042a228: { // 0x42a228: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0042a22b: { // 0x42a22b: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0042a22d: { // 0x42a22d: 7404 JZ 0x0042a233
    if(integer::condition("JZ",flags)) goto L0042a233;
  }
  L0042a22f: { // 0x42a22f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0042a231: { // 0x42a231: eb10 JMP 0x0042a243
    goto L0042a243;
  }
  L0042a233: { // 0x42a233: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0042a235: { // 0x42a235: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a237: { // 0x42a237: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4366909u); flags=s.arithmetic_flags;
  }
  L0042a23d: { // 0x42a23d: 8b8000050000 MOV EAX,dword ptr [EAX + 0x500]
    s.ax = m.r32((s.ax+0x00000500u));
  }
  L0042a243: { // 0x42a243: 8a4e79 MOV CL,byte ptr [ESI + 0x79]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000079u)));
  }
  L0042a246: { // 0x42a246: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0042a24a: { // 0x42a24a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a24b: { // 0x42a24b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a24c: { // 0x42a24c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a24d: { // 0x42a24d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a252: { // 0x42a252: e8292b1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4366935u); flags=s.arithmetic_flags;
  }
  L0042a257: { // 0x42a257: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0042a25a: { // 0x42a25a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0042a25e: { // 0x42a25e: 7406 JZ 0x0042a266
    if(integer::condition("JZ",flags)) goto L0042a266;
  }
  L0042a260: { // 0x42a260: 897c244c MOV dword ptr [ESP + 0x4c],EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L0042a264: { // 0x42a264: eb14 JMP 0x0042a27a
    goto L0042a27a;
  }
  L0042a266: { // 0x42a266: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0042a268: { // 0x42a268: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a26a: { // 0x42a26a: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4366960u); flags=s.arithmetic_flags;
  }
  L0042a270: { // 0x42a270: 8b8800050000 MOV ECX,dword ptr [EAX + 0x500]
    s.cx = m.r32((s.ax+0x00000500u));
  }
  L0042a276: { // 0x42a276: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0042a27a: { // 0x42a27a: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0042a27e: { // 0x42a27e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a283: { // 0x42a283: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a284: { // 0x42a284: e877b21100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4366985u); flags=s.arithmetic_flags;
  }
  L0042a289: { // 0x42a289: 8b8040010000 MOV EAX,dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0042a28f: { // 0x42a28f: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0042a293: { // 0x42a293: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0042a297: { // 0x42a297: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L0042a29a: { // 0x42a29a: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L0042a29c: { // 0x42a29c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a29d: { // 0x42a29d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a29e: { // 0x42a29e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a29f: { // 0x42a29f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a2a4: { // 0x42a2a4: e8d72a1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4367017u); flags=s.arithmetic_flags;
  }
  L0042a2a9: { // 0x42a2a9: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0042a2ad: { // 0x42a2ad: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0042a2b1: { // 0x42a2b1: 8a4679 MOV AL,byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L0042a2b4: { // 0x42a2b4: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0042a2b8: { // 0x42a2b8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a2b9: { // 0x42a2b9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a2ba: { // 0x42a2ba: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a2bb: { // 0x42a2bb: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a2c0: { // 0x42a2c0: e89b7a1300 CALL 0x00561d60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00561d60u,4367045u); flags=s.arithmetic_flags;
  }
  L0042a2c5: { // 0x42a2c5: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0042a2c7: { // 0x42a2c7: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0042a2cb: { // 0x42a2cb: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0042a2cf: { // 0x42a2cf: 8b8b40010000 MOV ECX,dword ptr [EBX + 0x140]
    s.cx = m.r32((s.bx+0x00000140u));
  }
  L0042a2d5: { // 0x42a2d5: c1e908 SHR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::right);
  }
  L0042a2d8: { // 0x42a2d8: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L0042a2db: { // 0x42a2db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a2dc: { // 0x42a2dc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042a2dd: { // 0x42a2dd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a2de: { // 0x42a2de: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a2e3: { // 0x42a2e3: e8787a1300 CALL 0x00561d60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00561d60u,4367080u); flags=s.arithmetic_flags;
  }
  L0042a2e8: { // 0x42a2e8: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0042a2ea: { // 0x42a2ea: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0042a2ed: { // 0x42a2ed: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0042a2f1: { // 0x42a2f1: 7406 JZ 0x0042a2f9
    if(integer::condition("JZ",flags)) goto L0042a2f9;
  }
  L0042a2f3: { // 0x42a2f3: 897c2448 MOV dword ptr [ESP + 0x48],EDI
    m.w32((f.sp+0x00000048u), s.di);
  }
  L0042a2f7: { // 0x42a2f7: eb14 JMP 0x0042a30d
    goto L0042a30d;
  }
  L0042a2f9: { // 0x42a2f9: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0042a2fb: { // 0x42a2fb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a2fd: { // 0x42a2fd: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4367107u); flags=s.arithmetic_flags;
  }
  L0042a303: { // 0x42a303: 8b8000050000 MOV EAX,dword ptr [EAX + 0x500]
    s.ax = m.r32((s.ax+0x00000500u));
  }
  L0042a309: { // 0x42a309: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0042a30d: { // 0x42a30d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0042a30f: { // 0x42a30f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a311: { // 0x42a311: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4367124u); flags=s.arithmetic_flags;
  }
  L0042a314: { // 0x42a314: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L0042a317: { // 0x42a317: 7577 JNZ 0x0042a390
    if(integer::condition("JNZ",flags)) goto L0042a390;
  }
  L0042a319: { // 0x42a319: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  L0042a31f: { // 0x42a31f: 8a88440b0000 MOV CL,byte ptr [EAX + 0xb44]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b44u)));
  }
  L0042a325: { // 0x42a325: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042a327: { // 0x42a327: 7467 JZ 0x0042a390
    if(integer::condition("JZ",flags)) goto L0042a390;
  }
  L0042a329: { // 0x42a329: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L0042a32f: { // 0x42a32f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0042a331: { // 0x42a331: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a333: { // 0x42a333: c744244807000000 MOV dword ptr [ESP + 0x48],0x7
    m.w32((f.sp+0x00000048u), 0x00000007u);
  }
  L0042a33b: { // 0x42a33b: 7434 JZ 0x0042a371
    if(integer::condition("JZ",flags)) goto L0042a371;
  }
  L0042a33d: { // 0x42a33d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042a33f: { // 0x42a33f: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0042a343: { // 0x42a343: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a344: { // 0x42a344: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  L0042a349: { // 0x42a349: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a34a: { // 0x42a34a: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),4367180u); flags=s.arithmetic_flags;
  }
  L0042a34c: { // 0x42a34c: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L0042a350: { // 0x42a350: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0042a352: { // 0x42a352: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a354: { // 0x42a354: 0f9cc1 SETL CL
    s.cx = with_al(s.cx, (integer::condition("JL",flags)?1u:0u));
  }
  L0042a357: { // 0x42a357: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0042a358: { // 0x42a358: 23ca AND ECX,EDX
    s.cx = integer::logical((s.cx)&(s.dx),32,flags);
  }
  L0042a35a: { // 0x42a35a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a35c: { // 0x42a35c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0042a35e: { // 0x42a35e: 7d0d JGE 0x0042a36d
    if(integer::condition("JGE",flags)) goto L0042a36d;
  }
  L0042a360: { // 0x42a360: 3d02400080 CMP EAX,0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L0042a365: { // 0x42a365: 7406 JZ 0x0042a36d
    if(integer::condition("JZ",flags)) goto L0042a36d;
  }
  L0042a367: { // 0x42a367: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a368: { // 0x42a368: e8036f3500 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,4367213u); flags=s.arithmetic_flags;
  }
  L0042a36d: { // 0x42a36d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042a36f: { // 0x42a36f: 750a JNZ 0x0042a37b
    if(integer::condition("JNZ",flags)) goto L0042a37b;
  }
  L0042a371: { // 0x42a371: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L0042a376: { // 0x42a376: e8f56e3500 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,4367227u); flags=s.arithmetic_flags;
  }
  L0042a37b: { // 0x42a37b: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0042a37d: { // 0x42a37d: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0042a381: { // 0x42a381: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a382: { // 0x42a382: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042a383: { // 0x42a383: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),4367238u); flags=s.arithmetic_flags;
  }
  L0042a386: { // 0x42a386: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042a388: { // 0x42a388: 7406 JZ 0x0042a390
    if(integer::condition("JZ",flags)) goto L0042a390;
  }
  L0042a38a: { // 0x42a38a: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L0042a38c: { // 0x42a38c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042a38d: { // 0x42a38d: ff5108 CALL dword ptr [ECX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000008u)),4367248u); flags=s.arithmetic_flags;
  }
  L0042a390: { // 0x42a390: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0042a392: { // 0x42a392: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a394: { // 0x42a394: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4367258u); flags=s.arithmetic_flags;
  }
  L0042a39a: { // 0x42a39a: 8a88a00a0000 MOV CL,byte ptr [EAX + 0xaa0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa0u)));
  }
  L0042a3a0: { // 0x42a3a0: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042a3a2: { // 0x42a3a2: 7547 JNZ 0x0042a3eb
    if(integer::condition("JNZ",flags)) goto L0042a3eb;
  }
  L0042a3a4: { // 0x42a3a4: 8a862d030000 MOV AL,byte ptr [ESI + 0x32d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032du)));
  }
  L0042a3aa: { // 0x42a3aa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a3ac: { // 0x42a3ac: 743d JZ 0x0042a3eb
    if(integer::condition("JZ",flags)) goto L0042a3eb;
  }
  L0042a3ae: { // 0x42a3ae: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0042a3b0: { // 0x42a3b0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a3b2: { // 0x42a3b2: ff90f4020000 CALL dword ptr [EAX + 0x2f4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000002f4u)),4367288u); flags=s.arithmetic_flags;
  }
  L0042a3b8: { // 0x42a3b8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a3ba: { // 0x42a3ba: 752f JNZ 0x0042a3eb
    if(integer::condition("JNZ",flags)) goto L0042a3eb;
  }
  L0042a3bc: { // 0x42a3bc: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0042a3c0: { // 0x42a3c0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0042a3c2: { // 0x42a3c2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a3c3: { // 0x42a3c3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a3c8: { // 0x42a3c8: e883d01200 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4367309u); flags=s.arithmetic_flags;
  }
  L0042a3cd: { // 0x42a3cd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a3cf: { // 0x42a3cf: 741a JZ 0x0042a3eb
    if(integer::condition("JZ",flags)) goto L0042a3eb;
  }
  L0042a3d1: { // 0x42a3d1: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0042a3d5: { // 0x42a3d5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0042a3d7: { // 0x42a3d7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a3d8: { // 0x42a3d8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042a3dd: { // 0x42a3dd: e86ed01200 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4367330u); flags=s.arithmetic_flags;
  }
  L0042a3e2: { // 0x42a3e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a3e4: { // 0x42a3e4: c644244c01 MOV byte ptr [ESP + 0x4c],0x1
    m.w8((f.sp+0x0000004cu), 0x00000001u);
  }
  L0042a3e9: { // 0x42a3e9: 7505 JNZ 0x0042a3f0
    if(integer::condition("JNZ",flags)) goto L0042a3f0;
  }
  L0042a3eb: { // 0x42a3eb: c644244c00 MOV byte ptr [ESP + 0x4c],0x0
    m.w8((f.sp+0x0000004cu), 0x00000000u);
  }
  L0042a3f0: { // 0x42a3f0: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0042a3f4: { // 0x42a3f4: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0042a3f8: { // 0x42a3f8: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0042a3fa: { // 0x42a3fa: 8a44244c MOV AL,byte ptr [ESP + 0x4c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000004cu)));
  }
  L0042a3fe: { // 0x42a3fe: 7410 JZ 0x0042a410
    if(integer::condition("JZ",flags)) goto L0042a410;
  }
  L0042a400: { // 0x42a400: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a402: { // 0x42a402: 7455 JZ 0x0042a459
    if(integer::condition("JZ",flags)) goto L0042a459;
  }
  L0042a404: { // 0x42a404: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042a405: { // 0x42a405: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042a406: { // 0x42a406: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042a407: { // 0x42a407: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042a409: { // 0x42a409: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042a40a: { // 0x42a40a: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0042a40d: { // 0x42a40d: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0042a410: { // 0x42a410: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a412: { // 0x42a412: 7445 JZ 0x0042a459
    if(integer::condition("JZ",flags)) goto L0042a459;
  }
  L0042a414: { // 0x42a414: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0042a418: { // 0x42a418: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042a419: { // 0x42a419: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0042a41d: { // 0x42a41d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a41e: { // 0x42a41e: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0042a422: { // 0x42a422: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a423: { // 0x42a423: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a424: { // 0x42a424: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042a426: { // 0x42a426: e835f7ffff CALL 0x00429b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00429b60u,4367403u); flags=s.arithmetic_flags;
  }
  L0042a42b: { // 0x42a42b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a42d: { // 0x42a42d: 752a JNZ 0x0042a459
    if(integer::condition("JNZ",flags)) goto L0042a459;
  }
  L0042a42f: { // 0x42a42f: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0042a434: { // 0x42a434: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0042a439: { // 0x42a439: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0042a43e: { // 0x42a43e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a43f: { // 0x42a43f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a440: { // 0x42a440: 0fbf4c241c MOVSX ECX,word ptr [ESP + 0x1c]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001cu)),16));
  }
  L0042a445: { // 0x42a445: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a446: { // 0x42a446: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a447: { // 0x42a447: 6860a17b00 PUSH 0x7ba160
    f.push(m,0x007ba160u);
  }
  L0042a44c: { // 0x42a44c: e89fc4fdff CALL 0x004068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4367441u); flags=s.arithmetic_flags;
  }
  L0042a451: { // 0x42a451: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0042a454: { // 0x42a454: c644244c00 MOV byte ptr [ESP + 0x4c],0x0
    m.w8((f.sp+0x0000004cu), 0x00000000u);
  }
  L0042a459: { // 0x42a459: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0042a45d: { // 0x42a45d: c744243c00000000 MOV dword ptr [ESP + 0x3c],0x0
    m.w32((f.sp+0x0000003cu), 0x00000000u);
  }
  L0042a465: { // 0x42a465: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0042a466: { // 0x42a466: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0042a468: { // 0x42a468: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0042a46a: { // 0x42a46a: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
  L0042a46c: { // 0x42a46c: 83c005 ADD EAX,0x5
    s.ax = integer::add(s.ax,0x00000005u,32,flags);
  }
  L0042a46f: { // 0x42a46f: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0042a473: { // 0x42a473: 8a44244c MOV AL,byte ptr [ESP + 0x4c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000004cu)));
  }
  L0042a477: { // 0x42a477: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a479: { // 0x42a479: 7525 JNZ 0x0042a4a0
    if(integer::condition("JNZ",flags)) goto L0042a4a0;
  }
  L0042a47b: { // 0x42a47b: 0fbf542412 MOVSX EDX,word ptr [ESP + 0x12]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0042a480: { // 0x42a480: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0042a485: { // 0x42a485: 0fbf4c2416 MOVSX ECX,word ptr [ESP + 0x16]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0042a48a: { // 0x42a48a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a48b: { // 0x42a48b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a48c: { // 0x42a48c: 0fbf54241c MOVSX EDX,word ptr [ESP + 0x1c]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001cu)),16));
  }
  L0042a491: { // 0x42a491: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a492: { // 0x42a492: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a493: { // 0x42a493: 6830a17b00 PUSH 0x7ba130
    f.push(m,0x007ba130u);
  }
  L0042a498: { // 0x42a498: e853c4fdff CALL 0x004068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4367517u); flags=s.arithmetic_flags;
  }
  L0042a49d: { // 0x42a49d: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0042a4a0: { // 0x42a4a0: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0042a4a4: { // 0x42a4a4: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0042a4a8: { // 0x42a4a8: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L0042a4ac: { // 0x42a4ac: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L0042a4b0: { // 0x42a4b0: 8b7c2434 MOV EDI,dword ptr [ESP + 0x34]
    s.di = m.r32((f.sp+0x00000034u));
  }
  L0042a4b4: { // 0x42a4b4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a4b5: { // 0x42a4b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a4b6: { // 0x42a4b6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a4b7: { // 0x42a4b7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042a4b8: { // 0x42a4b8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042a4b9: { // 0x42a4b9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042a4ba: { // 0x42a4ba: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042a4bc: { // 0x42a4bc: e8afceffff CALL 0x00427370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427370u,4367553u); flags=s.arithmetic_flags;
  }
  L0042a4c1: { // 0x42a4c1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a4c3: { // 0x42a4c3: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0042a4c7: { // 0x42a4c7: 0f85b1000000 JNZ 0x0042a57e
    if(integer::condition("JNZ",flags)) goto L0042a57e;
  }
  L0042a4cd: { // 0x42a4cd: 8a4c244c MOV CL,byte ptr [ESP + 0x4c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000004cu)));
  }
  L0042a4d1: { // 0x42a4d1: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042a4d3: { // 0x42a4d3: 0f84a5000000 JZ 0x0042a57e
    if(integer::condition("JZ",flags)) goto L0042a57e;
  }
  L0042a4d9: { // 0x42a4d9: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0042a4dd: { // 0x42a4dd: 0fbf4b02 MOVSX ECX,word ptr [EBX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0042a4e1: { // 0x42a4e1: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0042a4e3: { // 0x42a4e3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042a4e4: { // 0x42a4e4: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042a4e6: { // 0x42a4e6: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0042a4e9: { // 0x42a4e9: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0042a4eb: { // 0x42a4eb: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042a4ed: { // 0x42a4ed: 0fbf13 MOVSX EDX,word ptr [EBX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0042a4f0: { // 0x42a4f0: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042a4f2: { // 0x42a4f2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042a4f3: { // 0x42a4f3: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042a4f5: { // 0x42a4f5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042a4f7: { // 0x42a4f7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042a4f9: { // 0x42a4f9: 7f02 JG 0x0042a4fd
    if(integer::condition("JG",flags)) goto L0042a4fd;
  }
  L0042a4fb: { // 0x42a4fb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042a4fd: { // 0x42a4fd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0042a500: { // 0x42a500: 7e25 JLE 0x0042a527
    if(integer::condition("JLE",flags)) goto L0042a527;
  }
  L0042a502: { // 0x42a502: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0042a507: { // 0x42a507: 0fbf4c2410 MOVSX ECX,word ptr [ESP + 0x10]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0042a50c: { // 0x42a50c: 0fbf542416 MOVSX EDX,word ptr [ESP + 0x16]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0042a511: { // 0x42a511: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a512: { // 0x42a512: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a513: { // 0x42a513: 0fbf44241c MOVSX EAX,word ptr [ESP + 0x1c]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001cu)),16));
  }
  L0042a518: { // 0x42a518: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a519: { // 0x42a519: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a51a: { // 0x42a51a: 6800a17b00 PUSH 0x7ba100
    f.push(m,0x007ba100u);
  }
  L0042a51f: { // 0x42a51f: e8ccc3fdff CALL 0x004068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4367652u); flags=s.arithmetic_flags;
  }
  L0042a524: { // 0x42a524: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0042a527: { // 0x42a527: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L0042a52b: { // 0x42a52b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042a52c: { // 0x42a52c: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0042a52d: { // 0x42a52d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042a52f: { // 0x42a52f: 897c2440 MOV dword ptr [ESP + 0x40],EDI
    m.w32((f.sp+0x00000040u), s.di);
  }
  L0042a533: { // 0x42a533: e858000000 CALL 0x0042a590
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042a590u,4367672u); flags=s.arithmetic_flags;
  }
  L0042a538: { // 0x42a538: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042a53a: { // 0x42a53a: e851d9ffff CALL 0x00427e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427e90u,4367679u); flags=s.arithmetic_flags;
  }
  L0042a53f: { // 0x42a53f: 8a5538 MOV DL,byte ptr [EBP + 0x38]
    s.dx = with_al(s.dx, m.r8((s.bp+0x00000038u)));
  }
  L0042a542: { // 0x42a542: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0042a546: { // 0x42a546: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0042a548: { // 0x42a548: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L0042a54b: { // 0x42a54b: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0042a54d: { // 0x42a54d: 8844244c MOV byte ptr [ESP + 0x4c],AL
    m.w8((f.sp+0x0000004cu), (s.ax & 0xffu));
  }
  L0042a551: { // 0x42a551: 7d27 JGE 0x0042a57a
    if(integer::condition("JGE",flags)) goto L0042a57a;
  }
  L0042a553: { // 0x42a553: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a555: { // 0x42a555: 0f8418ffffff JZ 0x0042a473
    if(integer::condition("JZ",flags)) goto L0042a473;
  }
  L0042a55b: { // 0x42a55b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0042a55f: { // 0x42a55f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042a560: { // 0x42a560: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0042a564: { // 0x42a564: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a565: { // 0x42a565: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0042a569: { // 0x42a569: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042a56a: { // 0x42a56a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a56b: { // 0x42a56b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042a56d: { // 0x42a56d: e8eef5ffff CALL 0x00429b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00429b60u,4367730u); flags=s.arithmetic_flags;
  }
  L0042a572: { // 0x42a572: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a574: { // 0x42a574: 0f85f9feffff JNZ 0x0042a473
    if(integer::condition("JNZ",flags)) goto L0042a473;
  }
  L0042a57a: { // 0x42a57a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0042a57e: { // 0x42a57e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042a57f: { // 0x42a57f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042a580: { // 0x42a580: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042a581: { // 0x42a581: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042a582: { // 0x42a582: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0042a585: { // 0x42a585: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}
void f_00027370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00427370: { // 0x427370: 83ec4c SUB ESP,0x4c
    f.sp = integer::sub(f.sp,0x0000004cu,32,flags);
  }
  L00427373: { // 0x427373: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427374: { // 0x427374: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00427375: { // 0x427375: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00427376: { // 0x427376: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00427377: { // 0x427377: 8b7c2464 MOV EDI,dword ptr [ESP + 0x64]
    s.di = m.r32((f.sp+0x00000064u));
  }
  L0042737b: { // 0x42737b: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L0042737f: { // 0x42737f: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00427381: { // 0x427381: a158a98100 MOV EAX,[0x0081a958]
    s.ax = m.r32((0x0081a958u));
  }
  L00427386: { // 0x427386: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0042738a: { // 0x42738a: 0fbf17 MOVSX EDX,word ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0042738d: { // 0x42738d: 0fbf5d00 MOVSX EBX,word ptr [EBP]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00427391: { // 0x427391: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L00427394: { // 0x427394: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00427396: { // 0x427396: c744242800000000 MOV dword ptr [ESP + 0x28],0x0
    m.w32((f.sp+0x00000028u), 0x00000000u);
  }
  L0042739e: { // 0x42739e: 0fbf5502 MOVSX EDX,word ptr [EBP + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L004273a2: { // 0x4273a2: c1e209 SHL EDX,0x9
    s.dx = integer::shift(s.dx,0x00000009u,32,flags,integer::Shift::left);
  }
  L004273a5: { // 0x4273a5: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L004273a7: { // 0x4273a7: 8d0c88 LEA ECX,[EAX + ECX*0x4]
    s.cx = (s.ax+(s.cx * 0x00000004u));
  }
  L004273aa: { // 0x4273aa: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L004273ae: { // 0x4273ae: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L004273b0: { // 0x4273b0: 8d0490 LEA EAX,[EAX + EDX*0x4]
    s.ax = (s.ax+(s.dx * 0x00000004u));
  }
  L004273b3: { // 0x4273b3: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L004273b7: { // 0x4273b7: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L004273bb: { // 0x4273bb: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004273bd: { // 0x4273bd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004273bf: { // 0x4273bf: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L004273c3: { // 0x4273c3: 0f8465090000 JZ 0x00427d2e
    if(integer::condition("JZ",flags)) goto L00427d2e;
  }
  L004273c9: { // 0x4273c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004273cb: { // 0x4273cb: 0f845d090000 JZ 0x00427d2e
    if(integer::condition("JZ",flags)) goto L00427d2e;
  }
  L004273d1: { // 0x4273d1: 8b5c2468 MOV EBX,dword ptr [ESP + 0x68]
    s.bx = m.r32((f.sp+0x00000068u));
  }
  L004273d5: { // 0x4273d5: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004273d7: { // 0x4273d7: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L004273d9: { // 0x4273d9: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4355036u); flags=s.arithmetic_flags;
  }
  L004273dc: { // 0x4273dc: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L004273df: { // 0x4273df: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L004273e3: { // 0x4273e3: 7417 JZ 0x004273fc
    if(integer::condition("JZ",flags)) goto L004273fc;
  }
  L004273e5: { // 0x4273e5: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L004273eb: { // 0x4273eb: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004273ee: { // 0x4273ee: 740c JZ 0x004273fc
    if(integer::condition("JZ",flags)) goto L004273fc;
  }
  L004273f0: { // 0x4273f0: 0fbe801b010000 MOVSX EAX,byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L004273f7: { // 0x4273f7: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L004273fa: { // 0x4273fa: eb07 JMP 0x00427403
    goto L00427403;
  }
  L004273fc: { // 0x4273fc: 0fbe801b010000 MOVSX EAX,byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L00427403: { // 0x427403: 894634 MOV dword ptr [ESI + 0x34],EAX
    m.w32((s.si+0x00000034u), s.ax);
  }
  L00427406: { // 0x427406: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00427408: { // 0x427408: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0042740a: { // 0x42740a: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4355085u); flags=s.arithmetic_flags;
  }
  L0042740d: { // 0x42740d: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00427410: { // 0x427410: 7417 JZ 0x00427429
    if(integer::condition("JZ",flags)) goto L00427429;
  }
  L00427412: { // 0x427412: 8a4379 MOV AL,byte ptr [EBX + 0x79]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000079u)));
  }
  L00427415: { // 0x427415: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00427417: { // 0x427417: 7410 JZ 0x00427429
    if(integer::condition("JZ",flags)) goto L00427429;
  }
  L00427419: { // 0x427419: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0042741d: { // 0x42741d: 0fbe801b010000 MOVSX EAX,byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L00427424: { // 0x427424: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00427427: { // 0x427427: eb0b JMP 0x00427434
    goto L00427434;
  }
  L00427429: { // 0x427429: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L0042742d: { // 0x42742d: 0fbe811b010000 MOVSX EAX,byte ptr [ECX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00427434: { // 0x427434: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L00427437: { // 0x427437: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00427439: { // 0x427439: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0042743b: { // 0x42743b: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4355137u); flags=s.arithmetic_flags;
  }
  L00427441: { // 0x427441: 8a88a00a0000 MOV CL,byte ptr [EAX + 0xaa0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa0u)));
  }
  L00427447: { // 0x427447: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00427449: { // 0x427449: 7445 JZ 0x00427490
    if(integer::condition("JZ",flags)) goto L00427490;
  }
  L0042744b: { // 0x42744b: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0042744f: { // 0x42744f: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L00427455: { // 0x427455: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00427458: { // 0x427458: 7436 JZ 0x00427490
    if(integer::condition("JZ",flags)) goto L00427490;
  }
  L0042745a: { // 0x42745a: 8d8b88000000 LEA ECX,[EBX + 0x88]
    s.cx = (s.bx+0x00000088u);
  }
  L00427460: { // 0x427460: 8b9388000000 MOV EDX,dword ptr [EBX + 0x88]
    s.dx = m.r32((s.bx+0x00000088u));
  }
  L00427466: { // 0x427466: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0042746a: { // 0x42746a: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0042746d: { // 0x42746d: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00427471: { // 0x427471: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427474: { // 0x427474: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L00427477: { // 0x427477: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00427478: { // 0x427478: f73d486b8300 IDIV dword ptr [0x00836b48]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((0x00836b48u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0042747e: { // 0x42747e: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00427480: { // 0x427480: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00427481: { // 0x427481: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00427483: { // 0x427483: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00427485: { // 0x427485: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00427488: { // 0x427488: 7e06 JLE 0x00427490
    if(integer::condition("JLE",flags)) goto L00427490;
  }
  L0042748a: { // 0x42748a: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0042748d: { // 0x42748d: 894e30 MOV dword ptr [ESI + 0x30],ECX
    m.w32((s.si+0x00000030u), s.cx);
  }
  L00427490: { // 0x427490: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00427492: { // 0x427492: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00427494: { // 0x427494: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4355226u); flags=s.arithmetic_flags;
  }
  L0042749a: { // 0x42749a: 8b80a4050000 MOV EAX,dword ptr [EAX + 0x5a4]
    s.ax = m.r32((s.ax+0x000005a4u));
  }
  L004274a0: { // 0x4274a0: 8b5640 MOV EDX,dword ptr [ESI + 0x40]
    s.dx = m.r32((s.si+0x00000040u));
  }
  L004274a3: { // 0x4274a3: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  L004274a6: { // 0x4274a6: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L004274aa: { // 0x4274aa: c7466c00000000 MOV dword ptr [ESI + 0x6c],0x0
    m.w32((s.si+0x0000006cu), 0x00000000u);
  }
  L004274b1: { // 0x4274b1: 8b4d00 MOV ECX,dword ptr [EBP]
    s.cx = m.r32((s.bp));
  }
  L004274b4: { // 0x4274b4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004274b6: { // 0x4274b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004274b7: { // 0x4274b7: 894e70 MOV dword ptr [ESI + 0x70],ECX
    m.w32((s.si+0x00000070u), s.cx);
  }
  L004274ba: { // 0x4274ba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004274bb: { // 0x4274bb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004274bd: { // 0x4274bd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004274bf: { // 0x4274bf: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L004274c3: { // 0x4274c3: e878080000 CALL 0x00427d40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427d40u,4355272u); flags=s.arithmetic_flags;
  }
  L004274c8: { // 0x4274c8: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L004274cc: { // 0x4274cc: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004274d0: { // 0x4274d0: 663b0f CMP CX,word ptr [EDI]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.di)),16,flags);
  }
  L004274d3: { // 0x4274d3: 7518 JNZ 0x004274ed
    if(integer::condition("JNZ",flags)) goto L004274ed;
  }
  L004274d5: { // 0x4274d5: 668b5502 MOV DX,word ptr [EBP + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L004274d9: { // 0x4274d9: 663b5702 CMP DX,word ptr [EDI + 0x2]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags);
  }
  L004274dd: { // 0x4274dd: 750e JNZ 0x004274ed
    if(integer::condition("JNZ",flags)) goto L004274ed;
  }
  L004274df: { // 0x4274df: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004274e2: { // 0x4274e2: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  L004274e5: { // 0x4274e5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004274e7: { // 0x4274e7: 0f8441080000 JZ 0x00427d2e
    if(integer::condition("JZ",flags)) goto L00427d2e;
  }
  L004274ed: { // 0x4274ed: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L004274f0: { // 0x4274f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004274f2: { // 0x4274f2: 7408 JZ 0x004274fc
    if(integer::condition("JZ",flags)) goto L004274fc;
  }
  L004274f4: { // 0x4274f4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004274f5: { // 0x4274f5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004274f7: { // 0x4274f7: e8d4100000 CALL 0x004285d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004285d0u,4355324u); flags=s.arithmetic_flags;
  }
  L004274fc: { // 0x4274fc: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00427500: { // 0x427500: 0fbf4126 MOVSX EAX,word ptr [ECX + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000026u)),16));
  }
  L00427504: { // 0x427504: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0042750b: { // 0x42750b: 0fbf5124 MOVSX EDX,word ptr [ECX + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000024u)),16));
  }
  L0042750f: { // 0x42750f: 0fbe891b010000 MOVSX ECX,byte ptr [ECX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00427516: { // 0x427516: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00427518: { // 0x427518: 8b5630 MOV EDX,dword ptr [ESI + 0x30]
    s.dx = m.r32((s.si+0x00000030u));
  }
  L0042751b: { // 0x42751b: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0042751d: { // 0x42751d: 7e15 JLE 0x00427534
    if(integer::condition("JLE",flags)) goto L00427534;
  }
  L0042751f: { // 0x42751f: 8b561c MOV EDX,dword ptr [ESI + 0x1c]
    s.dx = m.r32((s.si+0x0000001cu));
  }
  L00427522: { // 0x427522: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L00427525: { // 0x427525: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L00427528: { // 0x427528: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  L0042752b: { // 0x42752b: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L00427532: { // 0x427532: eb13 JMP 0x00427547
    goto L00427547;
  }
  L00427534: { // 0x427534: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L00427537: { // 0x427537: 8b5628 MOV EDX,dword ptr [ESI + 0x28]
    s.dx = m.r32((s.si+0x00000028u));
  }
  L0042753a: { // 0x42753a: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  L0042753d: { // 0x42753d: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L00427540: { // 0x427540: c7048100000000 MOV dword ptr [ECX + EAX*0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L00427547: { // 0x427547: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00427549: { // 0x427549: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0042754b: { // 0x42754b: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L00427550: { // 0x427550: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4355414u); flags=s.arithmetic_flags;
  }
  L00427556: { // 0x427556: 8a88a00a0000 MOV CL,byte ptr [EAX + 0xaa0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa0u)));
  }
  L0042755c: { // 0x42755c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042755e: { // 0x42755e: 0f84a4000000 JZ 0x00427608
    if(integer::condition("JZ",flags)) goto L00427608;
  }
  L00427564: { // 0x427564: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L00427569: { // 0x427569: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0042756b: { // 0x42756b: bf84747800 MOV EDI,0x787484
    s.di = 0x00787484u;
  }
  L00427570: { // 0x427570: 8d442460 LEA EAX,[ESP + 0x60]
    s.ax = (f.sp+0x00000060u);
  }
  L00427574: { // 0x427574: 8d8be0020000 LEA ECX,[EBX + 0x2e0]
    s.cx = (s.bx+0x000002e0u);
  }
  L0042757a: { // 0x42757a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042757b: { // 0x42757b: e8d0120900 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4355456u); flags=s.arithmetic_flags;
  }
  L00427580: { // 0x427580: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00427582: { // 0x427582: c1e80c SHR EAX,0xc
    s.ax = integer::shift(s.ax,0x0000000cu,32,flags,integer::Shift::right);
  }
  L00427585: { // 0x427585: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00427586: { // 0x427586: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00427588: { // 0x427588: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L0042758b: { // 0x42758b: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0042758d: { // 0x42758d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042758e: { // 0x42758e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00427590: { // 0x427590: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00427592: { // 0x427592: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00427595: { // 0x427595: 7e61 JLE 0x004275f8
    if(integer::condition("JLE",flags)) goto L004275f8;
  }
  L00427597: { // 0x427597: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L0042759a: { // 0x42759a: 7d5c JGE 0x004275f8
    if(integer::condition("JGE",flags)) goto L004275f8;
  }
  L0042759c: { // 0x42759c: 81ffa4747800 CMP EDI,0x7874a4
    (void)integer::sub(s.di,0x007874a4u,32,flags);
  }
  L004275a2: { // 0x4275a2: 7454 JZ 0x004275f8
    if(integer::condition("JZ",flags)) goto L004275f8;
  }
  L004275a4: { // 0x4275a4: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L004275a6: { // 0x4275a6: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L004275aa: { // 0x4275aa: 8d048a LEA EAX,[EDX + ECX*0x4]
    s.ax = (s.dx+(s.cx * 0x00000004u));
  }
  L004275ad: { // 0x4275ad: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L004275b0: { // 0x4275b0: 0fbf4126 MOVSX EAX,word ptr [ECX + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000026u)),16));
  }
  L004275b4: { // 0x4275b4: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L004275bb: { // 0x4275bb: 0fbf5124 MOVSX EDX,word ptr [ECX + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000024u)),16));
  }
  L004275bf: { // 0x4275bf: 0fbe891b010000 MOVSX ECX,byte ptr [ECX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L004275c6: { // 0x4275c6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004275c8: { // 0x4275c8: 8b5630 MOV EDX,dword ptr [ESI + 0x30]
    s.dx = m.r32((s.si+0x00000030u));
  }
  L004275cb: { // 0x4275cb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004275cc: { // 0x4275cc: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L004275ce: { // 0x4275ce: 7e15 JLE 0x004275e5
    if(integer::condition("JLE",flags)) goto L004275e5;
  }
  L004275d0: { // 0x4275d0: 8b561c MOV EDX,dword ptr [ESI + 0x1c]
    s.dx = m.r32((s.si+0x0000001cu));
  }
  L004275d3: { // 0x4275d3: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L004275d6: { // 0x4275d6: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L004275d9: { // 0x4275d9: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  L004275dc: { // 0x4275dc: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L004275e3: { // 0x4275e3: eb13 JMP 0x004275f8
    goto L004275f8;
  }
  L004275e5: { // 0x4275e5: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L004275e8: { // 0x4275e8: 8b5628 MOV EDX,dword ptr [ESI + 0x28]
    s.dx = m.r32((s.si+0x00000028u));
  }
  L004275eb: { // 0x4275eb: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  L004275ee: { // 0x4275ee: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L004275f1: { // 0x4275f1: c7048100000000 MOV dword ptr [ECX + EAX*0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L004275f8: { // 0x4275f8: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L004275fb: { // 0x4275fb: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L004275fc: { // 0x4275fc: 81ffa4747800 CMP EDI,0x7874a4
    (void)integer::sub(s.di,0x007874a4u,32,flags);
  }
  L00427602: { // 0x427602: 0f8e68ffffff JLE 0x00427570
    if(integer::condition("JLE",flags)) goto L00427570;
  }
  L00427608: { // 0x427608: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0042760a: { // 0x42760a: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0042760c: { // 0x42760c: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4355599u); flags=s.arithmetic_flags;
  }
  L0042760f: { // 0x42760f: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00427612: { // 0x427612: 7515 JNZ 0x00427629
    if(integer::condition("JNZ",flags)) goto L00427629;
  }
  L00427614: { // 0x427614: 8b83ac050000 MOV EAX,dword ptr [EBX + 0x5ac]
    s.ax = m.r32((s.bx+0x000005acu));
  }
  L0042761a: { // 0x42761a: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0042761f: { // 0x42761f: 8a88a40b0000 MOV CL,byte ptr [EAX + 0xba4]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ba4u)));
  }
  L00427625: { // 0x427625: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00427627: { // 0x427627: 7505 JNZ 0x0042762e
    if(integer::condition("JNZ",flags)) goto L0042762e;
  }
  L00427629: { // 0x427629: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0042762e: { // 0x42762e: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00427632: { // 0x427632: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00427634: { // 0x427634: 7d08 JGE 0x0042763e
    if(integer::condition("JGE",flags)) goto L0042763e;
  }
  L00427636: { // 0x427636: c7442470f7ff0000 MOV dword ptr [ESP + 0x70],0xfff7
    m.w32((f.sp+0x00000070u), 0x0000fff7u);
  }
  L0042763e: { // 0x42763e: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427642: { // 0x427642: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00427644: { // 0x427644: 0f84d5060000 JZ 0x00427d1f
    if(integer::condition("JZ",flags)) goto L00427d1f;
  }
  L0042764a: { // 0x42764a: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L0042764e: { // 0x42764e: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00427652: { // 0x427652: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00427654: { // 0x427654: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00427656: { // 0x427656: 0f8d5f060000 JGE 0x00427cbb
    if(integer::condition("JGE",flags)) goto L00427cbb;
  }
  L0042765c: { // 0x42765c: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427660: { // 0x427660: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00427664: { // 0x427664: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00427666: { // 0x427666: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00427668: { // 0x427668: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0042766a: { // 0x42766a: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0042766e: { // 0x42766e: 750e JNZ 0x0042767e
    if(integer::condition("JNZ",flags)) goto L0042767e;
  }
  L00427670: { // 0x427670: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00427673: { // 0x427673: 8b7e34 MOV EDI,dword ptr [ESI + 0x34]
    s.di = m.r32((s.si+0x00000034u));
  }
  L00427676: { // 0x427676: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00427678: { // 0x427678: 0f843d060000 JZ 0x00427cbb
    if(integer::condition("JZ",flags)) goto L00427cbb;
  }
  L0042767e: { // 0x42767e: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00427680: { // 0x427680: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00427684: { // 0x427684: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L00427687: { // 0x427687: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0042768b: { // 0x42768b: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L0042768f: { // 0x42768f: 0faf0d4c6b8300 IMUL ECX,dword ptr [0x00836b4c]
    s.cx = integer::imul(s.cx,m.r32((0x00836b4cu)),32,flags);
  }
  L00427696: { // 0x427696: 0fbf00 MOVSX EAX,word ptr [EAX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00427699: { // 0x427699: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0042769b: { // 0x42769b: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0042769f: { // 0x42769f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004276a3: { // 0x4276a3: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L004276a6: { // 0x4276a6: 7540 JNZ 0x004276e8
    if(integer::condition("JNZ",flags)) goto L004276e8;
  }
  L004276a8: { // 0x4276a8: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004276ac: { // 0x4276ac: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004276ae: { // 0x4276ae: 0fbf8216010000 MOVSX EAX,word ptr [EDX + 0x116]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000116u)),16));
  }
  L004276b5: { // 0x4276b5: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004276b8: { // 0x4276b8: 7427 JZ 0x004276e1
    if(integer::condition("JZ",flags)) goto L004276e1;
  }
  L004276ba: { // 0x4276ba: 8b0dfce48400 MOV ECX,dword ptr [0x0084e4fc]
    s.cx = m.r32((0x0084e4fcu));
  }
  L004276c0: { // 0x4276c0: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004276c3: { // 0x4276c3: 8b4228 MOV EAX,dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  L004276c6: { // 0x4276c6: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L004276ca: { // 0x4276ca: 0fbf4c2462 MOVSX ECX,word ptr [ESP + 0x62]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000062u)),16));
  }
  L004276cf: { // 0x4276cf: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004276d2: { // 0x4276d2: a158a98100 MOV EAX,[0x0081a958]
    s.ax = m.r32((0x0081a958u));
  }
  L004276d7: { // 0x4276d7: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L004276da: { // 0x4276da: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L004276dc: { // 0x4276dc: 8d0488 LEA EAX,[EAX + ECX*0x4]
    s.ax = (s.ax+(s.cx * 0x00000004u));
  }
  L004276df: { // 0x4276df: eb15 JMP 0x004276f6
    goto L004276f6;
  }
  L004276e1: { // 0x4276e1: b8506b8300 MOV EAX,0x836b50
    s.ax = 0x00836b50u;
  }
  L004276e6: { // 0x4276e6: eb0e JMP 0x004276f6
    goto L004276f6;
  }
  L004276e8: { // 0x4276e8: 8b0c8584747800 MOV ECX,dword ptr [EAX*0x4 + 0x787484]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x00787484u));
  }
  L004276ef: { // 0x4276ef: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L004276f3: { // 0x4276f3: 8d048a LEA EAX,[EDX + ECX*0x4]
    s.ax = (s.dx+(s.cx * 0x00000004u));
  }
  L004276f6: { // 0x4276f6: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L004276f8: { // 0x4276f8: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004276fc: { // 0x4276fc: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004276fe: { // 0x4276fe: 0f847a030000 JZ 0x00427a7e
    if(integer::condition("JZ",flags)) goto L00427a7e;
  }
  L00427704: { // 0x427704: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00427708: { // 0x427708: 8d4b24 LEA ECX,[EBX + 0x24]
    s.cx = (s.bx+0x00000024u);
  }
  L0042770b: { // 0x42770b: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0042770e: { // 0x42770e: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00427712: { // 0x427712: 740d JZ 0x00427721
    if(integer::condition("JZ",flags)) goto L00427721;
  }
  L00427714: { // 0x427714: 8b3c85784b8300 MOV EDI,dword ptr [EAX*0x4 + 0x834b78]
    s.di = m.r32(((s.ax * 0x00000004u)+0x00834b78u));
  }
  L0042771b: { // 0x42771b: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0042771f: { // 0x42771f: eb0e JMP 0x0042772f
    goto L0042772f;
  }
  L00427721: { // 0x427721: 0fbf7902 MOVSX EDI,word ptr [ECX + 0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L00427725: { // 0x427725: 0faf3d4c6b8300 IMUL EDI,dword ptr [0x00836b4c]
    s.di = integer::imul(s.di,m.r32((0x00836b4cu)),32,flags);
  }
  L0042772c: { // 0x42772c: 0fbf01 MOVSX EAX,word ptr [ECX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0042772f: { // 0x42772f: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00427731: { // 0x427731: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00427737: { // 0x427737: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0042773a: { // 0x42773a: 741b JZ 0x00427757
    if(integer::condition("JZ",flags)) goto L00427757;
  }
  L0042773c: { // 0x42773c: 0fbe931b010000 MOVSX EDX,byte ptr [EBX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.bx+0x0000011bu)),8));
  }
  L00427743: { // 0x427743: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L00427746: { // 0x427746: c644246000 MOV byte ptr [ESP + 0x60],0x0
    m.w8((f.sp+0x00000060u), 0x00000000u);
  }
  L0042774b: { // 0x42774b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042774d: { // 0x42774d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042774e: { // 0x42774e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00427750: { // 0x427750: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00427752: { // 0x427752: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00427755: { // 0x427755: 7f05 JG 0x0042775c
    if(integer::condition("JG",flags)) goto L0042775c;
  }
  L00427757: { // 0x427757: c644246001 MOV byte ptr [ESP + 0x60],0x1
    m.w8((f.sp+0x00000060u), 0x00000001u);
  }
  L0042775c: { // 0x42775c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042775d: { // 0x42775d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00427762: { // 0x427762: e8d9571200 CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,4355943u); flags=s.arithmetic_flags;
  }
  L00427767: { // 0x427767: 8b0d8ca88100 MOV ECX,dword ptr [0x0081a88c]
    s.cx = m.r32((0x0081a88cu));
  }
  L0042776d: { // 0x42776d: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00427770: { // 0x427770: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00427774: { // 0x427774: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L00427777: { // 0x427777: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0042777a: { // 0x42777a: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  L0042777d: { // 0x42777d: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L00427781: { // 0x427781: 39048a CMP dword ptr [EDX + ECX*0x4],EAX
    (void)integer::sub(m.r32((s.dx+(s.cx * 0x00000004u))),s.ax,32,flags);
  }
  L00427784: { // 0x427784: 741e JZ 0x004277a4
    if(integer::condition("JZ",flags)) goto L004277a4;
  }
  L00427786: { // 0x427786: 8a4c2460 MOV CL,byte ptr [ESP + 0x60]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000060u)));
  }
  L0042778a: { // 0x42778a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042778c: { // 0x42778c: 7453 JZ 0x004277e1
    if(integer::condition("JZ",flags)) goto L004277e1;
  }
  L0042778e: { // 0x42778e: 8a8b22010000 MOV CL,byte ptr [EBX + 0x122]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000122u)));
  }
  L00427794: { // 0x427794: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00427796: { // 0x427796: 750c JNZ 0x004277a4
    if(integer::condition("JNZ",flags)) goto L004277a4;
  }
  L00427798: { // 0x427798: 8a4c2474 MOV CL,byte ptr [ESP + 0x74]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000074u)));
  }
  L0042779c: { // 0x42779c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042779e: { // 0x42779e: 0f85da020000 JNZ 0x00427a7e
    if(integer::condition("JNZ",flags)) goto L00427a7e;
  }
  L004277a4: { // 0x4277a4: 8a4c2460 MOV CL,byte ptr [ESP + 0x60]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000060u)));
  }
  L004277a8: { // 0x4277a8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004277aa: { // 0x4277aa: 7435 JZ 0x004277e1
    if(integer::condition("JZ",flags)) goto L004277e1;
  }
  L004277ac: { // 0x4277ac: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L004277af: { // 0x4277af: 8d2cbd00000000 LEA EBP,[EDI*0x4 + 0x0]
    s.bp = ((s.di * 0x00000004u)+0x00000000u);
  }
  L004277b6: { // 0x4277b6: 896c242c MOV dword ptr [ESP + 0x2c],EBP
    m.w32((f.sp+0x0000002cu), s.bp);
  }
  L004277ba: { // 0x4277ba: 390429 CMP dword ptr [ECX + EBP*0x1],EAX
    (void)integer::sub(m.r32((s.cx+(s.bp * 0x00000001u))),s.ax,32,flags);
  }
  L004277bd: { // 0x4277bd: 7555 JNZ 0x00427814
    if(integer::condition("JNZ",flags)) goto L00427814;
  }
  L004277bf: { // 0x4277bf: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L004277c3: { // 0x4277c3: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  L004277c6: { // 0x4277c6: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004277c9: { // 0x4277c9: dc05d0747800 FADD double ptr [0x007874d0]
    const auto address=(0x007874d0u);
    s.fp.add64(read64(m,address));
  }
  L004277cf: { // 0x4277cf: d90428 FLD float ptr [EAX + EBP*0x1]
    const auto address=(s.ax+(s.bp * 0x00000001u));
    s.fp.load32(m.r32(address));
  }
  L004277d2: { // 0x4277d2: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L004277d4: { // 0x4277d4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004277d6: { // 0x4277d6: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004277d9: { // 0x4277d9: 0f859f020000 JNZ 0x00427a7e
    if(integer::condition("JNZ",flags)) goto L00427a7e;
  }
  L004277df: { // 0x4277df: eb33 JMP 0x00427814
    goto L00427814;
  }
  L004277e1: { // 0x4277e1: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L004277e4: { // 0x4277e4: 8d2cbd00000000 LEA EBP,[EDI*0x4 + 0x0]
    s.bp = ((s.di * 0x00000004u)+0x00000000u);
  }
  L004277eb: { // 0x4277eb: 896c242c MOV dword ptr [ESP + 0x2c],EBP
    m.w32((f.sp+0x0000002cu), s.bp);
  }
  L004277ef: { // 0x4277ef: 390429 CMP dword ptr [ECX + EBP*0x1],EAX
    (void)integer::sub(m.r32((s.cx+(s.bp * 0x00000001u))),s.ax,32,flags);
  }
  L004277f2: { // 0x4277f2: 7520 JNZ 0x00427814
    if(integer::condition("JNZ",flags)) goto L00427814;
  }
  L004277f4: { // 0x4277f4: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L004277f8: { // 0x4277f8: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  L004277fb: { // 0x4277fb: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004277fe: { // 0x4277fe: dc05d0747800 FADD double ptr [0x007874d0]
    const auto address=(0x007874d0u);
    s.fp.add64(read64(m,address));
  }
  L00427804: { // 0x427804: d90428 FLD float ptr [EAX + EBP*0x1]
    const auto address=(s.ax+(s.bp * 0x00000001u));
    s.fp.load32(m.r32(address));
  }
  L00427807: { // 0x427807: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427809: { // 0x427809: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0042780b: { // 0x42780b: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0042780e: { // 0x42780e: 0f856a020000 JNZ 0x00427a7e
    if(integer::condition("JNZ",flags)) goto L00427a7e;
  }
  L00427814: { // 0x427814: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000008u)));
  }
  L00427817: { // 0x427817: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0042781b: { // 0x42781b: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  L0042781f: { // 0x42781f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00427820: { // 0x427820: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00427822: { // 0x427822: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L00427825: { // 0x427825: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00427827: { // 0x427827: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00427828: { // 0x427828: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0042782c: { // 0x42782c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042782d: { // 0x42782d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042782e: { // 0x42782e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042782f: { // 0x42782f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00427831: { // 0x427831: ff9294010000 CALL dword ptr [EDX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000194u)),4356151u); flags=s.arithmetic_flags;
  }
  L00427837: { // 0x427837: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00427839: { // 0x427839: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L0042783d: { // 0x42783d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042783f: { // 0x42783f: 7407 JZ 0x00427848
    if(integer::condition("JZ",flags)) goto L00427848;
  }
  L00427841: { // 0x427841: 83fb07 CMP EBX,0x7
    (void)integer::sub(s.bx,0x00000007u,32,flags);
  }
  L00427844: { // 0x427844: 7d02 JGE 0x00427848
    if(integer::condition("JGE",flags)) goto L00427848;
  }
  L00427846: { // 0x427846: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00427848: { // 0x427848: 837c241808 CMP dword ptr [ESP + 0x18],0x8
    (void)integer::sub(m.r32((f.sp+0x00000018u)),0x00000008u,32,flags);
  }
  L0042784d: { // 0x42784d: 7431 JZ 0x00427880
    if(integer::condition("JZ",flags)) goto L00427880;
  }
  L0042784f: { // 0x42784f: 8a442460 MOV AL,byte ptr [ESP + 0x60]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000060u)));
  }
  L00427853: { // 0x427853: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00427857: { // 0x427857: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00427859: { // 0x427859: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042785a: { // 0x42785a: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0042785e: { // 0x42785e: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00427861: { // 0x427861: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427862: { // 0x427862: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00427863: { // 0x427863: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00427864: { // 0x427864: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00427865: { // 0x427865: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00427867: { // 0x427867: e8a4f8ffff CALL 0x00427110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427110u,4356204u); flags=s.arithmetic_flags;
  }
  L0042786c: { // 0x42786c: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0042786f: { // 0x42786f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00427873: { // 0x427873: d804856ca07b00 FADD float ptr [EAX*0x4 + 0x7ba06c]
    const auto address=((s.ax * 0x00000004u)+0x007ba06cu);
    s.fp.add32(m.r32(address));
  }
  L0042787a: { // 0x42787a: d95c2434 FSTP float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0042787e: { // 0x42787e: eb47 JMP 0x004278c7
    goto L004278c7;
  }
  L00427880: { // 0x427880: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00427884: { // 0x427884: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L00427888: { // 0x427888: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L0042788a: { // 0x42788a: 0fbf4a02 MOVSX ECX,word ptr [EDX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L0042788e: { // 0x42788e: 0fbf4726 MOVSX EAX,word ptr [EDI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000026u)),16));
  }
  L00427892: { // 0x427892: 83c724 ADD EDI,0x24
    s.di = integer::add(s.di,0x00000024u,32,flags);
  }
  L00427895: { // 0x427895: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00427897: { // 0x427897: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00427898: { // 0x427898: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042789a: { // 0x42789a: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0042789d: { // 0x42789d: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0042789f: { // 0x42789f: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004278a1: { // 0x4278a1: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L004278a5: { // 0x4278a5: 0fbf12 MOVSX EDX,word ptr [EDX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L004278a8: { // 0x4278a8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004278aa: { // 0x4278aa: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004278ab: { // 0x4278ab: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004278ad: { // 0x4278ad: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004278af: { // 0x4278af: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004278b1: { // 0x4278b1: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L004278b5: { // 0x4278b5: 7f04 JG 0x004278bb
    if(integer::condition("JG",flags)) goto L004278bb;
  }
  L004278b7: { // 0x4278b7: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L004278bb: { // 0x4278bb: db442434 FILD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L004278bf: { // 0x4278bf: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L004278c3: { // 0x4278c3: d95c2434 FSTP float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004278c7: { // 0x4278c7: 83fb07 CMP EBX,0x7
    (void)integer::sub(s.bx,0x00000007u,32,flags);
  }
  L004278ca: { // 0x4278ca: 0f8d8a010000 JGE 0x00427a5a
    if(integer::condition("JGE",flags)) goto L00427a5a;
  }
  L004278d0: { // 0x4278d0: 8a442460 MOV AL,byte ptr [ESP + 0x60]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000060u)));
  }
  L004278d4: { // 0x4278d4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004278d6: { // 0x4278d6: 7412 JZ 0x004278ea
    if(integer::condition("JZ",flags)) goto L004278ea;
  }
  L004278d8: { // 0x4278d8: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L004278db: { // 0x4278db: 8b0c28 MOV ECX,dword ptr [EAX + EBP*0x1]
    s.cx = m.r32((s.ax+(s.bp * 0x00000001u)));
  }
  L004278de: { // 0x4278de: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  L004278e1: { // 0x4278e1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004278e3: { // 0x4278e3: 7516 JNZ 0x004278fb
    if(integer::condition("JNZ",flags)) goto L004278fb;
  }
  L004278e5: { // 0x4278e5: e994010000 JMP 0x00427a7e
    goto L00427a7e;
  }
  L004278ea: { // 0x4278ea: 8b561c MOV EDX,dword ptr [ESI + 0x1c]
    s.dx = m.r32((s.si+0x0000001cu));
  }
  L004278ed: { // 0x4278ed: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L004278f0: { // 0x4278f0: 8b042a MOV EAX,dword ptr [EDX + EBP*0x1]
    s.ax = m.r32((s.dx+(s.bp * 0x00000001u)));
  }
  L004278f3: { // 0x4278f3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004278f5: { // 0x4278f5: 0f8483010000 JZ 0x00427a7e
    if(integer::condition("JZ",flags)) goto L00427a7e;
  }
  L004278fb: { // 0x4278fb: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004278ff: { // 0x4278ff: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L00427903: { // 0x427903: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427907: { // 0x427907: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00427908: { // 0x427908: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00427909: { // 0x427909: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042790a: { // 0x42790a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042790b: { // 0x42790b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042790d: { // 0x42790d: e82e040000 CALL 0x00427d40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427d40u,4356370u); flags=s.arithmetic_flags;
  }
  L00427912: { // 0x427912: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00427914: { // 0x427914: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00427918: { // 0x427918: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042791a: { // 0x42791a: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0042791e: { // 0x42791e: 7509 JNZ 0x00427929
    if(integer::condition("JNZ",flags)) goto L00427929;
  }
  L00427920: { // 0x427920: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L00427924: { // 0x427924: e9d9000000 JMP 0x00427a02
    goto L00427a02;
  }
  L00427929: { // 0x427929: d94308 FLD float ptr [EBX + 0x8]
    const auto address=(s.bx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042792c: { // 0x42792c: d85808 FCOMP float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0042792f: { // 0x42792f: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00427932: { // 0x427932: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00427934: { // 0x427934: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427936: { // 0x427936: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00427939: { // 0x427939: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0042793a: { // 0x42793a: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0042793c: { // 0x42793c: 746c JZ 0x004279aa
    if(integer::condition("JZ",flags)) goto L004279aa;
  }
  L0042793e: { // 0x42793e: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00427942: { // 0x427942: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00427944: { // 0x427944: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00427947: { // 0x427947: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0042794b: { // 0x42794b: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0042794e: { // 0x42794e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00427950: { // 0x427950: 7352 JNC 0x004279a4
    if(integer::condition("JNC",flags)) goto L004279a4;
  }
  L00427952: { // 0x427952: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00427955: { // 0x427955: 762c JBE 0x00427983
    if(integer::condition("JBE",flags)) goto L00427983;
  }
  L00427957: { // 0x427957: 8b6f08 MOV EBP,dword ptr [EDI + 0x8]
    s.bp = m.r32((s.di+0x00000008u));
  }
  L0042795a: { // 0x42795a: 8b5c9500 MOV EBX,dword ptr [EBP + EDX*0x4]
    s.bx = m.r32((s.bp+(s.dx * 0x00000004u)));
  }
  L0042795e: { // 0x42795e: d94308 FLD float ptr [EBX + 0x8]
    const auto address=(s.bx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427961: { // 0x427961: d85c2444 FCOMP float ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00427965: { // 0x427965: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427967: { // 0x427967: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0042796a: { // 0x42796a: 750d JNZ 0x00427979
    if(integer::condition("JNZ",flags)) goto L00427979;
  }
  L0042796c: { // 0x42796c: 895c8d00 MOV dword ptr [EBP + ECX*0x4],EBX
    m.w32((s.bp+(s.cx * 0x00000004u)), s.bx);
  }
  L00427970: { // 0x427970: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00427972: { // 0x427972: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00427974: { // 0x427974: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00427977: { // 0x427977: 77de JA 0x00427957
    if(integer::condition("JA",flags)) goto L00427957;
  }
  L00427979: { // 0x427979: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0042797d: { // 0x42797d: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L00427981: { // 0x427981: eb04 JMP 0x00427987
    goto L00427987;
  }
  L00427983: { // 0x427983: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00427987: { // 0x427987: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L0042798a: { // 0x42798a: 89048a MOV dword ptr [EDX + ECX*0x4],EAX
    m.w32((s.dx+(s.cx * 0x00000004u)), s.ax);
  }
  L0042798d: { // 0x42798d: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0042798f: { // 0x42798f: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00427992: { // 0x427992: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00427993: { // 0x427993: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00427995: { // 0x427995: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L00427997: { // 0x427997: 7603 JBE 0x0042799c
    if(integer::condition("JBE",flags)) goto L0042799c;
  }
  L00427999: { // 0x427999: 89470c MOV dword ptr [EDI + 0xc],EAX
    m.w32((s.di+0x0000000cu), s.ax);
  }
  L0042799c: { // 0x42799c: 3b4710 CMP EAX,dword ptr [EDI + 0x10]
    (void)integer::sub(s.ax,m.r32((s.di+0x00000010u)),32,flags);
  }
  L0042799f: { // 0x42799f: 7303 JNC 0x004279a4
    if(integer::condition("JNC",flags)) goto L004279a4;
  }
  L004279a1: { // 0x4279a1: 894710 MOV dword ptr [EDI + 0x10],EAX
    m.w32((s.di+0x00000010u), s.ax);
  }
  L004279a4: { // 0x4279a4: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L004279a8: { // 0x4279a8: eb58 JMP 0x00427a02
    goto L00427a02;
  }
  L004279aa: { // 0x4279aa: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L004279ad: { // 0x4279ad: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L004279b1: { // 0x4279b1: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L004279b4: { // 0x4279b4: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L004279b6: { // 0x4279b6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004279b8: { // 0x4279b8: 7348 JNC 0x00427a02
    if(integer::condition("JNC",flags)) goto L00427a02;
  }
  L004279ba: { // 0x4279ba: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L004279bd: { // 0x4279bd: 7622 JBE 0x004279e1
    if(integer::condition("JBE",flags)) goto L004279e1;
  }
  L004279bf: { // 0x4279bf: 8b6f08 MOV EBP,dword ptr [EDI + 0x8]
    s.bp = m.r32((s.di+0x00000008u));
  }
  L004279c2: { // 0x4279c2: 8b5c9500 MOV EBX,dword ptr [EBP + EDX*0x4]
    s.bx = m.r32((s.bp+(s.dx * 0x00000004u)));
  }
  L004279c6: { // 0x4279c6: d94308 FLD float ptr [EBX + 0x8]
    const auto address=(s.bx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L004279c9: { // 0x4279c9: d85c2448 FCOMP float ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004279cd: { // 0x4279cd: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004279cf: { // 0x4279cf: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004279d2: { // 0x4279d2: 750d JNZ 0x004279e1
    if(integer::condition("JNZ",flags)) goto L004279e1;
  }
  L004279d4: { // 0x4279d4: 895c8d00 MOV dword ptr [EBP + ECX*0x4],EBX
    m.w32((s.bp+(s.cx * 0x00000004u)), s.bx);
  }
  L004279d8: { // 0x4279d8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004279da: { // 0x4279da: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L004279dc: { // 0x4279dc: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L004279df: { // 0x4279df: 77de JA 0x004279bf
    if(integer::condition("JA",flags)) goto L004279bf;
  }
  L004279e1: { // 0x4279e1: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L004279e4: { // 0x4279e4: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L004279e8: { // 0x4279e8: 89048a MOV dword ptr [EDX + ECX*0x4],EAX
    m.w32((s.dx+(s.cx * 0x00000004u)), s.ax);
  }
  L004279eb: { // 0x4279eb: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004279ed: { // 0x4279ed: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L004279f0: { // 0x4279f0: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004279f1: { // 0x4279f1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004279f3: { // 0x4279f3: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L004279f5: { // 0x4279f5: 7603 JBE 0x004279fa
    if(integer::condition("JBE",flags)) goto L004279fa;
  }
  L004279f7: { // 0x4279f7: 89470c MOV dword ptr [EDI + 0xc],EAX
    m.w32((s.di+0x0000000cu), s.ax);
  }
  L004279fa: { // 0x4279fa: 3b4710 CMP EAX,dword ptr [EDI + 0x10]
    (void)integer::sub(s.ax,m.r32((s.di+0x00000010u)),32,flags);
  }
  L004279fd: { // 0x4279fd: 7303 JNC 0x00427a02
    if(integer::condition("JNC",flags)) goto L00427a02;
  }
  L004279ff: { // 0x4279ff: 894710 MOV dword ptr [EDI + 0x10],EAX
    m.w32((s.di+0x00000010u), s.ax);
  }
  L00427a02: { // 0x427a02: 8a442460 MOV AL,byte ptr [ESP + 0x60]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000060u)));
  }
  L00427a06: { // 0x427a06: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00427a08: { // 0x427a08: 7412 JZ 0x00427a1c
    if(integer::condition("JZ",flags)) goto L00427a1c;
  }
  L00427a0a: { // 0x427a0a: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L00427a0d: { // 0x427a0d: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00427a11: { // 0x427a11: 8b5628 MOV EDX,dword ptr [ESI + 0x28]
    s.dx = m.r32((s.si+0x00000028u));
  }
  L00427a14: { // 0x427a14: 891401 MOV dword ptr [ECX + EAX*0x1],EDX
    m.w32((s.cx+(s.ax * 0x00000001u)), s.dx);
  }
  L00427a17: { // 0x427a17: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L00427a1a: { // 0x427a1a: eb10 JMP 0x00427a2c
    goto L00427a2c;
  }
  L00427a1c: { // 0x427a1c: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00427a1f: { // 0x427a1f: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00427a23: { // 0x427a23: 8b5628 MOV EDX,dword ptr [ESI + 0x28]
    s.dx = m.r32((s.si+0x00000028u));
  }
  L00427a26: { // 0x427a26: 891401 MOV dword ptr [ECX + EAX*0x1],EDX
    m.w32((s.cx+(s.ax * 0x00000001u)), s.dx);
  }
  L00427a29: { // 0x427a29: 8b4e20 MOV ECX,dword ptr [ESI + 0x20]
    s.cx = m.r32((s.si+0x00000020u));
  }
  L00427a2c: { // 0x427a2c: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00427a30: { // 0x427a30: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L00427a33: { // 0x427a33: 891401 MOV dword ptr [ECX + EAX*0x1],EDX
    m.w32((s.cx+(s.ax * 0x00000001u)), s.dx);
  }
  L00427a36: { // 0x427a36: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00427a39: { // 0x427a39: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00427a3d: { // 0x427a3d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00427a3f: { // 0x427a3f: 668b8c46be000000 MOV CX,word ptr [ESI + EAX*0x2 + 0xbe]
    s.cx = with_ax(s.cx, m.r16((s.si+(s.ax * 0x00000002u)+0x000000beu)));
  }
  L00427a47: { // 0x427a47: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00427a49: { // 0x427a49: 7533 JNZ 0x00427a7e
    if(integer::condition("JNZ",flags)) goto L00427a7e;
  }
  L00427a4b: { // 0x427a4b: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L00427a4f: { // 0x427a4f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00427a50: { // 0x427a50: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L00427a53: { // 0x427a53: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00427a55: { // 0x427a55: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  L00427a58: { // 0x427a58: eb24 JMP 0x00427a7e
    goto L00427a7e;
  }
  L00427a5a: { // 0x427a5a: 3b7c2438 CMP EDI,dword ptr [ESP + 0x38]
    (void)integer::sub(s.di,m.r32((f.sp+0x00000038u)),32,flags);
  }
  L00427a5e: { // 0x427a5e: 751e JNZ 0x00427a7e
    if(integer::condition("JNZ",flags)) goto L00427a7e;
  }
  L00427a60: { // 0x427a60: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00427a64: { // 0x427a64: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00427a66: { // 0x427a66: 7516 JNZ 0x00427a7e
    if(integer::condition("JNZ",flags)) goto L00427a7e;
  }
  L00427a68: { // 0x427a68: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L00427a6b: { // 0x427a6b: 8b6e34 MOV EBP,dword ptr [ESI + 0x34]
    s.bp = m.r32((s.si+0x00000034u));
  }
  L00427a6e: { // 0x427a6e: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00427a70: { // 0x427a70: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00427a71: { // 0x427a71: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00427a73: { // 0x427a73: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00427a75: { // 0x427a75: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00427a78: { // 0x427a78: 0f8e3d020000 JLE 0x00427cbb
    if(integer::condition("JLE",flags)) goto L00427cbb;
  }
  L00427a7e: { // 0x427a7e: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00427a82: { // 0x427a82: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00427a83: { // 0x427a83: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00427a86: { // 0x427a86: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00427a8a: { // 0x427a8a: 0f8e0ffcffff JLE 0x0042769f
    if(integer::condition("JLE",flags)) goto L0042769f;
  }
  L00427a90: { // 0x427a90: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00427a94: { // 0x427a94: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00427a96: { // 0x427a96: 0f84fc000000 JZ 0x00427b98
    if(integer::condition("JZ",flags)) goto L00427b98;
  }
  L00427a9c: { // 0x427a9c: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  L00427a9f: { // 0x427a9f: 833a00 CMP dword ptr [EDX],0x0
    (void)integer::sub(m.r32((s.dx)),0x00000000u,32,flags);
  }
  L00427aa2: { // 0x427aa2: 0f84ea010000 JZ 0x00427c92
    if(integer::condition("JZ",flags)) goto L00427c92;
  }
  L00427aa8: { // 0x427aa8: 8b7a08 MOV EDI,dword ptr [EDX + 0x8]
    s.di = m.r32((s.dx+0x00000008u));
  }
  L00427aab: { // 0x427aab: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427aae: { // 0x427aae: 8b6f04 MOV EBP,dword ptr [EDI + 0x4]
    s.bp = m.r32((s.di+0x00000004u));
  }
  L00427ab1: { // 0x427ab1: d94508 FLD float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427ab4: { // 0x427ab4: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427ab6: { // 0x427ab6: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00427aba: { // 0x427aba: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427abc: { // 0x427abc: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427abf: { // 0x427abf: 0f84cd010000 JZ 0x00427c92
    if(integer::condition("JZ",flags)) goto L00427c92;
  }
  L00427ac5: { // 0x427ac5: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
  L00427ac8: { // 0x427ac8: 8b3a MOV EDI,dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
  L00427aca: { // 0x427aca: 83ff02 CMP EDI,0x2
    (void)integer::sub(s.di,0x00000002u,32,flags);
  }
  L00427acd: { // 0x427acd: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L00427ad2: { // 0x427ad2: 7c1d JL 0x00427af1
    if(integer::condition("JL",flags)) goto L00427af1;
  }
  L00427ad4: { // 0x427ad4: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00427ad7: { // 0x427ad7: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00427ada: { // 0x427ada: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00427add: { // 0x427add: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427ae0: { // 0x427ae0: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427ae3: { // 0x427ae3: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427ae5: { // 0x427ae5: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L00427aea: { // 0x427aea: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427aec: { // 0x427aec: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427aef: { // 0x427aef: 7405 JZ 0x00427af6
    if(integer::condition("JZ",flags)) goto L00427af6;
  }
  L00427af1: { // 0x427af1: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00427af6: { // 0x427af6: 83ff03 CMP EDI,0x3
    (void)integer::sub(s.di,0x00000003u,32,flags);
  }
  L00427af9: { // 0x427af9: 7c1f JL 0x00427b1a
    if(integer::condition("JL",flags)) goto L00427b1a;
  }
  L00427afb: { // 0x427afb: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00427afe: { // 0x427afe: 8b780c MOV EDI,dword ptr [EAX + 0xc]
    s.di = m.r32((s.ax+0x0000000cu));
  }
  L00427b01: { // 0x427b01: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00427b04: { // 0x427b04: d94708 FLD float ptr [EDI + 0x8]
    const auto address=(s.di+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427b07: { // 0x427b07: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427b0a: { // 0x427b0a: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427b0c: { // 0x427b0c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427b0e: { // 0x427b0e: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427b11: { // 0x427b11: 7507 JNZ 0x00427b1a
    if(integer::condition("JNZ",flags)) goto L00427b1a;
  }
  L00427b13: { // 0x427b13: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L00427b18: { // 0x427b18: eb05 JMP 0x00427b1f
    goto L00427b1f;
  }
  L00427b1a: { // 0x427b1a: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00427b1d: { // 0x427b1d: 7470 JZ 0x00427b8f
    if(integer::condition("JZ",flags)) goto L00427b8f;
  }
  L00427b1f: { // 0x427b1f: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00427b22: { // 0x427b22: 8b2c88 MOV EBP,dword ptr [EAX + ECX*0x4]
    s.bp = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00427b25: { // 0x427b25: 8b3c98 MOV EDI,dword ptr [EAX + EBX*0x4]
    s.di = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L00427b28: { // 0x427b28: 892c98 MOV dword ptr [EAX + EBX*0x4],EBP
    m.w32((s.ax+(s.bx * 0x00000004u)), s.bp);
  }
  L00427b2b: { // 0x427b2b: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00427b2e: { // 0x427b2e: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00427b30: { // 0x427b30: 893c88 MOV dword ptr [EAX + ECX*0x4],EDI
    m.w32((s.ax+(s.cx * 0x00000004u)), s.di);
  }
  L00427b33: { // 0x427b33: 8b2a MOV EBP,dword ptr [EDX]
    s.bp = m.r32((s.dx));
  }
  L00427b35: { // 0x427b35: 8d3c09 LEA EDI,[ECX + ECX*0x1]
    s.di = (s.cx+(s.cx * 0x00000001u));
  }
  L00427b38: { // 0x427b38: 8d440901 LEA EAX,[ECX + ECX*0x1 + 0x1]
    s.ax = (s.cx+(s.cx * 0x00000001u)+0x00000001u);
  }
  L00427b3c: { // 0x427b3c: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L00427b3e: { // 0x427b3e: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L00427b42: { // 0x427b42: 7f1d JG 0x00427b61
    if(integer::condition("JG",flags)) goto L00427b61;
  }
  L00427b44: { // 0x427b44: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00427b47: { // 0x427b47: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L00427b4a: { // 0x427b4a: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427b4d: { // 0x427b4d: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00427b50: { // 0x427b50: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00427b53: { // 0x427b53: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427b56: { // 0x427b56: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427b58: { // 0x427b58: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427b5a: { // 0x427b5a: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427b5d: { // 0x427b5d: 7502 JNZ 0x00427b61
    if(integer::condition("JNZ",flags)) goto L00427b61;
  }
  L00427b5f: { // 0x427b5f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00427b61: { // 0x427b61: 396c2460 CMP dword ptr [ESP + 0x60],EBP
    (void)integer::sub(m.r32((f.sp+0x00000060u)),s.bp,32,flags);
  }
  L00427b65: { // 0x427b65: 7f20 JG 0x00427b87
    if(integer::condition("JG",flags)) goto L00427b87;
  }
  L00427b67: { // 0x427b67: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00427b6a: { // 0x427b6a: 8b7c2460 MOV EDI,dword ptr [ESP + 0x60]
    s.di = m.r32((f.sp+0x00000060u));
  }
  L00427b6e: { // 0x427b6e: 8b3cb8 MOV EDI,dword ptr [EAX + EDI*0x4]
    s.di = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L00427b71: { // 0x427b71: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00427b74: { // 0x427b74: d94708 FLD float ptr [EDI + 0x8]
    const auto address=(s.di+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427b77: { // 0x427b77: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427b7a: { // 0x427b7a: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427b7c: { // 0x427b7c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427b7e: { // 0x427b7e: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427b81: { // 0x427b81: 7504 JNZ 0x00427b87
    if(integer::condition("JNZ",flags)) goto L00427b87;
  }
  L00427b83: { // 0x427b83: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00427b87: { // 0x427b87: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00427b89: { // 0x427b89: 7594 JNZ 0x00427b1f
    if(integer::condition("JNZ",flags)) goto L00427b1f;
  }
  L00427b8b: { // 0x427b8b: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L00427b8f: { // 0x427b8f: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00427b93: { // 0x427b93: e9fe000000 JMP 0x00427c96
    goto L00427c96;
  }
  L00427b98: { // 0x427b98: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00427b9b: { // 0x427b9b: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00427b9d: { // 0x427b9d: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00427b9f: { // 0x427b9f: 7509 JNZ 0x00427baa
    if(integer::condition("JNZ",flags)) goto L00427baa;
  }
  L00427ba1: { // 0x427ba1: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00427ba5: { // 0x427ba5: e9fc000000 JMP 0x00427ca6
    goto L00427ca6;
  }
  L00427baa: { // 0x427baa: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427bad: { // 0x427bad: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L00427bb2: { // 0x427bb2: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00427bb5: { // 0x427bb5: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00427bb8: { // 0x427bb8: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00427bbb: { // 0x427bbb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00427bbd: { // 0x427bbd: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L00427bc0: { // 0x427bc0: 897c244c MOV dword ptr [ESP + 0x4c],EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L00427bc4: { // 0x427bc4: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L00427bcb: { // 0x427bcb: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00427bcd: { // 0x427bcd: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00427bce: { // 0x427bce: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00427bd0: { // 0x427bd0: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00427bd2: { // 0x427bd2: 83ff02 CMP EDI,0x2
    (void)integer::sub(s.di,0x00000002u,32,flags);
  }
  L00427bd5: { // 0x427bd5: 7c1d JL 0x00427bf4
    if(integer::condition("JL",flags)) goto L00427bf4;
  }
  L00427bd7: { // 0x427bd7: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427bda: { // 0x427bda: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00427bdd: { // 0x427bdd: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00427be0: { // 0x427be0: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427be3: { // 0x427be3: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427be6: { // 0x427be6: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427be8: { // 0x427be8: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00427bed: { // 0x427bed: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427bef: { // 0x427bef: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427bf2: { // 0x427bf2: 7405 JZ 0x00427bf9
    if(integer::condition("JZ",flags)) goto L00427bf9;
  }
  L00427bf4: { // 0x427bf4: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00427bf9: { // 0x427bf9: 83ff03 CMP EDI,0x3
    (void)integer::sub(s.di,0x00000003u,32,flags);
  }
  L00427bfc: { // 0x427bfc: 7c1f JL 0x00427c1d
    if(integer::condition("JL",flags)) goto L00427c1d;
  }
  L00427bfe: { // 0x427bfe: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427c01: { // 0x427c01: 8b780c MOV EDI,dword ptr [EAX + 0xc]
    s.di = m.r32((s.ax+0x0000000cu));
  }
  L00427c04: { // 0x427c04: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00427c07: { // 0x427c07: d94708 FLD float ptr [EDI + 0x8]
    const auto address=(s.di+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427c0a: { // 0x427c0a: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427c0d: { // 0x427c0d: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427c0f: { // 0x427c0f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427c11: { // 0x427c11: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427c14: { // 0x427c14: 7507 JNZ 0x00427c1d
    if(integer::condition("JNZ",flags)) goto L00427c1d;
  }
  L00427c16: { // 0x427c16: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L00427c1b: { // 0x427c1b: eb05 JMP 0x00427c22
    goto L00427c22;
  }
  L00427c1d: { // 0x427c1d: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L00427c20: { // 0x427c20: 746c JZ 0x00427c8e
    if(integer::condition("JZ",flags)) goto L00427c8e;
  }
  L00427c22: { // 0x427c22: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427c25: { // 0x427c25: 8b2c90 MOV EBP,dword ptr [EAX + EDX*0x4]
    s.bp = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00427c28: { // 0x427c28: 8b3c98 MOV EDI,dword ptr [EAX + EBX*0x4]
    s.di = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L00427c2b: { // 0x427c2b: 892c98 MOV dword ptr [EAX + EBX*0x4],EBP
    m.w32((s.ax+(s.bx * 0x00000004u)), s.bp);
  }
  L00427c2e: { // 0x427c2e: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427c31: { // 0x427c31: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00427c33: { // 0x427c33: 893c90 MOV dword ptr [EAX + EDX*0x4],EDI
    m.w32((s.ax+(s.dx * 0x00000004u)), s.di);
  }
  L00427c36: { // 0x427c36: 8b29 MOV EBP,dword ptr [ECX]
    s.bp = m.r32((s.cx));
  }
  L00427c38: { // 0x427c38: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L00427c3b: { // 0x427c3b: 8d441201 LEA EAX,[EDX + EDX*0x1 + 0x1]
    s.ax = (s.dx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L00427c3f: { // 0x427c3f: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L00427c41: { // 0x427c41: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L00427c45: { // 0x427c45: 7f1d JG 0x00427c64
    if(integer::condition("JG",flags)) goto L00427c64;
  }
  L00427c47: { // 0x427c47: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427c4a: { // 0x427c4a: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L00427c4d: { // 0x427c4d: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427c50: { // 0x427c50: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427c53: { // 0x427c53: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00427c56: { // 0x427c56: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427c59: { // 0x427c59: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427c5b: { // 0x427c5b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427c5d: { // 0x427c5d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427c60: { // 0x427c60: 7502 JNZ 0x00427c64
    if(integer::condition("JNZ",flags)) goto L00427c64;
  }
  L00427c62: { // 0x427c62: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00427c64: { // 0x427c64: 396c2460 CMP dword ptr [ESP + 0x60],EBP
    (void)integer::sub(m.r32((f.sp+0x00000060u)),s.bp,32,flags);
  }
  L00427c68: { // 0x427c68: 7f20 JG 0x00427c8a
    if(integer::condition("JG",flags)) goto L00427c8a;
  }
  L00427c6a: { // 0x427c6a: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00427c6d: { // 0x427c6d: 8b7c2460 MOV EDI,dword ptr [ESP + 0x60]
    s.di = m.r32((f.sp+0x00000060u));
  }
  L00427c71: { // 0x427c71: 8b3cb8 MOV EDI,dword ptr [EAX + EDI*0x4]
    s.di = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L00427c74: { // 0x427c74: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00427c77: { // 0x427c77: d94708 FLD float ptr [EDI + 0x8]
    const auto address=(s.di+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427c7a: { // 0x427c7a: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00427c7d: { // 0x427c7d: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00427c7f: { // 0x427c7f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00427c81: { // 0x427c81: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00427c84: { // 0x427c84: 7504 JNZ 0x00427c8a
    if(integer::condition("JNZ",flags)) goto L00427c8a;
  }
  L00427c86: { // 0x427c86: 8b542460 MOV EDX,dword ptr [ESP + 0x60]
    s.dx = m.r32((f.sp+0x00000060u));
  }
  L00427c8a: { // 0x427c8a: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L00427c8c: { // 0x427c8c: 7594 JNZ 0x00427c22
    if(integer::condition("JNZ",flags)) goto L00427c22;
  }
  L00427c8e: { // 0x427c8e: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L00427c92: { // 0x427c92: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00427c96: { // 0x427c96: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427c9a: { // 0x427c9a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00427c9c: { // 0x427c9c: 7408 JZ 0x00427ca6
    if(integer::condition("JZ",flags)) goto L00427ca6;
  }
  L00427c9e: { // 0x427c9e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00427ca0: { // 0x427ca0: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00427ca3: { // 0x427ca3: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L00427ca6: { // 0x427ca6: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00427caa: { // 0x427caa: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427cae: { // 0x427cae: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00427caf: { // 0x427caf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00427cb1: { // 0x427cb1: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00427cb5: { // 0x427cb5: 0f858ff9ffff JNZ 0x0042764a
    if(integer::condition("JNZ",flags)) goto L0042764a;
  }
  L00427cbb: { // 0x427cbb: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00427cbf: { // 0x427cbf: 81f910270000 CMP ECX,0x2710
    (void)integer::sub(s.cx,0x00002710u,32,flags);
  }
  L00427cc5: { // 0x427cc5: 7454 JZ 0x00427d1b
    if(integer::condition("JZ",flags)) goto L00427d1b;
  }
  L00427cc7: { // 0x427cc7: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427ccb: { // 0x427ccb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00427ccd: { // 0x427ccd: 744c JZ 0x00427d1b
    if(integer::condition("JZ",flags)) goto L00427d1b;
  }
  L00427ccf: { // 0x427ccf: 3b4c2470 CMP ECX,dword ptr [ESP + 0x70]
    (void)integer::sub(s.cx,m.r32((f.sp+0x00000070u)),32,flags);
  }
  L00427cd3: { // 0x427cd3: 7446 JZ 0x00427d1b
    if(integer::condition("JZ",flags)) goto L00427d1b;
  }
  L00427cd5: { // 0x427cd5: 83780c02 CMP dword ptr [EAX + 0xc],0x2
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),0x00000002u,32,flags);
  }
  L00427cd9: { // 0x427cd9: 7c40 JL 0x00427d1b
    if(integer::condition("JL",flags)) goto L00427d1b;
  }
  L00427cdb: { // 0x427cdb: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00427cdf: { // 0x427cdf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00427ce0: { // 0x427ce0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00427ce1: { // 0x427ce1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00427ce3: { // 0x427ce3: e888060000 CALL 0x00428370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428370u,4357352u); flags=s.arithmetic_flags;
  }
  L00427ce8: { // 0x427ce8: 8b5c2468 MOV EBX,dword ptr [ESP + 0x68]
    s.bx = m.r32((f.sp+0x00000068u));
  }
  L00427cec: { // 0x427cec: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00427cee: { // 0x427cee: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427cef: { // 0x427cef: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00427cf0: { // 0x427cf0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00427cf2: { // 0x427cf2: e8e90d0000 CALL 0x00428ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428ae0u,4357367u); flags=s.arithmetic_flags;
  }
  L00427cf7: { // 0x427cf7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427cf8: { // 0x427cf8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00427cf9: { // 0x427cf9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00427cfb: { // 0x427cfb: e8c0130000 CALL 0x004290c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004290c0u,4357376u); flags=s.arithmetic_flags;
  }
  L00427d00: { // 0x427d00: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L00427d03: { // 0x427d03: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00427d05: { // 0x427d05: 7408 JZ 0x00427d0f
    if(integer::condition("JZ",flags)) goto L00427d0f;
  }
  L00427d07: { // 0x427d07: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427d08: { // 0x427d08: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00427d0a: { // 0x427d0a: e8c1080000 CALL 0x004285d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004285d0u,4357391u); flags=s.arithmetic_flags;
  }
  L00427d0f: { // 0x427d0f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00427d11: { // 0x427d11: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00427d12: { // 0x427d12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00427d13: { // 0x427d13: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00427d14: { // 0x427d14: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00427d15: { // 0x427d15: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L00427d18: { // 0x427d18: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L00427d1b: { // 0x427d1b: 8b5c2468 MOV EBX,dword ptr [ESP + 0x68]
    s.bx = m.r32((f.sp+0x00000068u));
  }
  L00427d1f: { // 0x427d1f: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L00427d22: { // 0x427d22: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00427d24: { // 0x427d24: 7408 JZ 0x00427d2e
    if(integer::condition("JZ",flags)) goto L00427d2e;
  }
  L00427d26: { // 0x427d26: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427d27: { // 0x427d27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00427d29: { // 0x427d29: e8a2080000 CALL 0x004285d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004285d0u,4357422u); flags=s.arithmetic_flags;
  }
  L00427d2e: { // 0x427d2e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00427d2f: { // 0x427d2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00427d30: { // 0x427d30: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00427d31: { // 0x427d31: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00427d33: { // 0x427d33: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00427d34: { // 0x427d34: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L00427d37: { // 0x427d37: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
}
void f_00027e90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00427e90: { // 0x427e90: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00427e93: { // 0x427e93: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00427e96: { // 0x427e96: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00427e97: { // 0x427e97: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00427e99: { // 0x427e99: 89b000001800 MOV dword ptr [EAX + 0x180000],ESI
    m.w32((s.ax+0x00180000u), s.si);
  }
  L00427e9f: { // 0x427e9f: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L00427ea2: { // 0x427ea2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00427ea3: { // 0x427ea3: 89b200001000 MOV dword ptr [EDX + 0x100000],ESI
    m.w32((s.dx+0x00100000u), s.si);
  }
  L00427ea9: { // 0x427ea9: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L00427eac: { // 0x427eac: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00427eae: { // 0x427eae: 3930 CMP dword ptr [EAX],ESI
    (void)integer::sub(m.r32((s.ax)),s.si,32,flags);
  }
  L00427eb0: { // 0x427eb0: 7c0e JL 0x00427ec0
    if(integer::condition("JL",flags)) goto L00427ec0;
  }
  L00427eb2: { // 0x427eb2: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00427eb5: { // 0x427eb5: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00427eb6: { // 0x427eb6: 897497fc MOV dword ptr [EDI + EDX*0x4 + -0x4],ESI
    m.w32((s.di+(s.dx * 0x00000004u)-0x00000004u), s.si);
  }
  L00427eba: { // 0x427eba: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L00427ebc: { // 0x427ebc: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00427ebe: { // 0x427ebe: 7ef2 JLE 0x00427eb2
    if(integer::condition("JLE",flags)) goto L00427eb2;
  }
  L00427ec0: { // 0x427ec0: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L00427ec2: { // 0x427ec2: 8b4168 MOV EAX,dword ptr [ECX + 0x68]
    s.ax = m.r32((s.cx+0x00000068u));
  }
  L00427ec5: { // 0x427ec5: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00427ec7: { // 0x427ec7: 3930 CMP dword ptr [EAX],ESI
    (void)integer::sub(m.r32((s.ax)),s.si,32,flags);
  }
  L00427ec9: { // 0x427ec9: 7c0e JL 0x00427ed9
    if(integer::condition("JL",flags)) goto L00427ed9;
  }
  L00427ecb: { // 0x427ecb: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00427ece: { // 0x427ece: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00427ecf: { // 0x427ecf: 897497fc MOV dword ptr [EDI + EDX*0x4 + -0x4],ESI
    m.w32((s.di+(s.dx * 0x00000004u)-0x00000004u), s.si);
  }
  L00427ed3: { // 0x427ed3: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L00427ed5: { // 0x427ed5: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00427ed7: { // 0x427ed7: 7ef2 JLE 0x00427ecb
    if(integer::condition("JLE",flags)) goto L00427ecb;
  }
  L00427ed9: { // 0x427ed9: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L00427edb: { // 0x427edb: 8b4128 MOV EAX,dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  L00427ede: { // 0x427ede: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00427edf: { // 0x427edf: 894128 MOV dword ptr [ECX + 0x28],EAX
    m.w32((s.cx+0x00000028u), s.ax);
  }
  L00427ee2: { // 0x427ee2: 0f8580000000 JNZ 0x00427f68
    if(integer::condition("JNZ",flags)) goto L00427f68;
  }
  L00427ee8: { // 0x427ee8: a14c6b8300 MOV EAX,[0x00836b4c]
    s.ax = m.r32((0x00836b4cu));
  }
  L00427eed: { // 0x427eed: 0fafc0 IMUL EAX,EAX
    s.ax = integer::imul(s.ax,s.ax,32,flags);
  }
  L00427ef0: { // 0x427ef0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00427ef1: { // 0x427ef1: 7811 JS 0x00427f04
    if(integer::condition("JS",flags)) goto L00427f04;
  }
  L00427ef3: { // 0x427ef3: 8b5118 MOV EDX,dword ptr [ECX + 0x18]
    s.dx = m.r32((s.cx+0x00000018u));
  }
  L00427ef6: { // 0x427ef6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00427ef7: { // 0x427ef7: 89748204 MOV dword ptr [EDX + EAX*0x4 + 0x4],ESI
    m.w32((s.dx+(s.ax * 0x00000004u)+0x00000004u), s.si);
  }
  L00427efb: { // 0x427efb: 8b511c MOV EDX,dword ptr [ECX + 0x1c]
    s.dx = m.r32((s.cx+0x0000001cu));
  }
  L00427efe: { // 0x427efe: 89748204 MOV dword ptr [EDX + EAX*0x4 + 0x4],ESI
    m.w32((s.dx+(s.ax * 0x00000004u)+0x00000004u), s.si);
  }
  L00427f02: { // 0x427f02: 79ef JNS 0x00427ef3
    if(integer::condition("JNS",flags)) goto L00427ef3;
  }
  L00427f04: { // 0x427f04: b844a88100 MOV EAX,0x81a844
    s.ax = 0x0081a844u;
  }
  L00427f09: { // 0x427f09: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427f0a: { // 0x427f0a: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00427f0c: { // 0x427f0c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00427f0d: { // 0x427f0d: 8d694c LEA EBP,[ECX + 0x4c]
    s.bp = (s.cx+0x0000004cu);
  }
  L00427f10: { // 0x427f10: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00427f14: { // 0x427f14: c744241003000000 MOV dword ptr [ESP + 0x10],0x3
    m.w32((f.sp+0x00000010u), 0x00000003u);
  }
  L00427f1c: { // 0x427f1c: 8b1428 MOV EDX,dword ptr [EAX + EBP*0x1]
    s.dx = m.r32((s.ax+(s.bp * 0x00000001u)));
  }
  L00427f1f: { // 0x427f1f: 8b7df4 MOV EDI,dword ptr [EBP + -0xc]
    s.di = m.r32((s.bp-0x0000000cu));
  }
  L00427f22: { // 0x427f22: 8b7500 MOV ESI,dword ptr [EBP]
    s.si = m.r32((s.bp));
  }
  L00427f25: { // 0x427f25: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L00427f28: { // 0x427f28: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00427f29: { // 0x427f29: 7826 JS 0x00427f51
    if(integer::condition("JS",flags)) goto L00427f51;
  }
  L00427f2b: { // 0x427f2b: 8d0496 LEA EAX,[ESI + EDX*0x4]
    s.ax = (s.si+(s.dx * 0x00000004u));
  }
  L00427f2e: { // 0x427f2e: 2bfe SUB EDI,ESI
    s.di = integer::sub(s.di,s.si,32,flags);
  }
  L00427f30: { // 0x427f30: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L00427f32: { // 0x427f32: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00427f33: { // 0x427f33: c7040700000000 MOV dword ptr [EDI + EAX*0x1],0x0
    m.w32((s.di+(s.ax * 0x00000001u)), 0x00000000u);
  }
  L00427f3a: { // 0x427f3a: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00427f40: { // 0x427f40: c7040300000000 MOV dword ptr [EBX + EAX*0x1],0x0
    m.w32((s.bx+(s.ax * 0x00000001u)), 0x00000000u);
  }
  L00427f47: { // 0x427f47: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00427f4a: { // 0x427f4a: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00427f4b: { // 0x427f4b: 75e6 JNZ 0x00427f33
    if(integer::condition("JNZ",flags)) goto L00427f33;
  }
  L00427f4d: { // 0x427f4d: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427f51: { // 0x427f51: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00427f55: { // 0x427f55: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L00427f58: { // 0x427f58: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00427f59: { // 0x427f59: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00427f5d: { // 0x427f5d: 75bd JNZ 0x00427f1c
    if(integer::condition("JNZ",flags)) goto L00427f1c;
  }
  L00427f5f: { // 0x427f5f: 8b4128 MOV EAX,dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  L00427f62: { // 0x427f62: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00427f63: { // 0x427f63: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00427f64: { // 0x427f64: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00427f65: { // 0x427f65: 894128 MOV dword ptr [ECX + 0x28],EAX
    m.w32((s.cx+0x00000028u), s.ax);
  }
  L00427f68: { // 0x427f68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00427f69: { // 0x427f69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00427f6a: { // 0x427f6a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00427f6d: { // 0x427f6d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00027060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00427060: { // 0x427060: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00427061: { // 0x427061: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00427063: { // 0x427063: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427064: { // 0x427064: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00427066: { // 0x427066: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00427067: { // 0x427067: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0042706b: { // 0x42706b: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0042706d: { // 0x42706d: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L0042706f: { // 0x42706f: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00427073: { // 0x427073: 0f8e84000000 JLE 0x004270fd
    if(integer::condition("JLE",flags)) goto L004270fd;
  }
  L00427079: { // 0x427079: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042707a: { // 0x42707a: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0042707e: { // 0x42707e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042707f: { // 0x42707f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00427081: { // 0x427081: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00427083: { // 0x427083: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L00427086: { // 0x427086: 7539 JNZ 0x004270c1
    if(integer::condition("JNZ",flags)) goto L004270c1;
  }
  L00427088: { // 0x427088: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0042708c: { // 0x42708c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00427091: { // 0x427091: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00427092: { // 0x427092: e869e41100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4354199u); flags=s.arithmetic_flags;
  }
  L00427097: { // 0x427097: 0fbf8016010000 MOVSX EAX,word ptr [EAX + 0x116]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000116u)),16));
  }
  L0042709e: { // 0x42709e: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004270a1: { // 0x4270a1: 740e JZ 0x004270b1
    if(integer::condition("JZ",flags)) goto L004270b1;
  }
  L004270a3: { // 0x4270a3: 8b0dfce48400 MOV ECX,dword ptr [0x0084e4fc]
    s.cx = m.r32((0x0084e4fcu));
  }
  L004270a9: { // 0x4270a9: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004270ac: { // 0x4270ac: 8b4228 MOV EAX,dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  L004270af: { // 0x4270af: eb36 JMP 0x004270e7
    goto L004270e7;
  }
  L004270b1: { // 0x4270b1: 66896c2418 MOV word ptr [ESP + 0x18],BP
    m.w16((f.sp+0x00000018u), (s.bp & 0xffffu));
  }
  L004270b6: { // 0x4270b6: 66896c241a MOV word ptr [ESP + 0x1a],BP
    m.w16((f.sp+0x0000001au), (s.bp & 0xffffu));
  }
  L004270bb: { // 0x4270bb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004270bf: { // 0x4270bf: eb26 JMP 0x004270e7
    goto L004270e7;
  }
  L004270c1: { // 0x4270c1: 668b148da09d8300 MOV DX,word ptr [ECX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.cx * 0x00000004u)+0x00839da0u)));
  }
  L004270c9: { // 0x4270c9: 6603d0 ADD DX,AX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L004270cc: { // 0x4270cc: 668b048da29d8300 MOV AX,word ptr [ECX*0x4 + 0x839da2]
    s.ax = with_ax(s.ax, m.r16(((s.cx * 0x00000004u)+0x00839da2u)));
  }
  L004270d4: { // 0x4270d4: 6603442412 ADD AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L004270d9: { // 0x4270d9: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L004270de: { // 0x4270de: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L004270e3: { // 0x4270e3: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004270e7: { // 0x4270e7: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004270ea: { // 0x4270ea: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L004270eb: { // 0x4270eb: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004270ef: { // 0x4270ef: 7590 JNZ 0x00427081
    if(integer::condition("JNZ",flags)) goto L00427081;
  }
  L004270f1: { // 0x4270f1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004270f2: { // 0x4270f2: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L004270f4: { // 0x4270f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004270f5: { // 0x4270f5: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004270f7: { // 0x4270f7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004270f8: { // 0x4270f8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004270f9: { // 0x4270f9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004270fa: { // 0x4270fa: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004270fd: { // 0x4270fd: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L004270ff: { // 0x4270ff: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00427101: { // 0x427101: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00427102: { // 0x427102: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00427103: { // 0x427103: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00427104: { // 0x427104: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0002ae00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ae00: { // 0x42ae00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042ae01: { // 0x42ae01: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ae02: { // 0x42ae02: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042ae04: { // 0x42ae04: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0042ae06: { // 0x42ae06: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0042ae09: { // 0x42ae09: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L0042ae0c: { // 0x42ae0c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0042ae0e: { // 0x42ae0e: 7411 JZ 0x0042ae21
    if(integer::condition("JZ",flags)) goto L0042ae21;
  }
  L0042ae10: { // 0x42ae10: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L0042ae13: { // 0x42ae13: 740c JZ 0x0042ae21
    if(integer::condition("JZ",flags)) goto L0042ae21;
  }
  L0042ae15: { // 0x42ae15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042ae16: { // 0x42ae16: e860283400 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4369947u); flags=s.arithmetic_flags;
  }
  L0042ae1b: { // 0x42ae1b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042ae1e: { // 0x42ae1e: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0042ae21: { // 0x42ae21: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L0042ae24: { // 0x42ae24: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L0042ae27: { // 0x42ae27: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042ae28: { // 0x42ae28: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042ae29: { // 0x42ae29: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_0014cd80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cd80: { // 0x54cd80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054cd81: { // 0x54cd81: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  L0054cd85: { // 0x54cd85: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cd86: { // 0x54cd86: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cd87: { // 0x54cd87: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cd88: { // 0x54cd88: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0054cd8c: { // 0x54cd8c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054cd8d: { // 0x54cd8d: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0054cd8f: { // 0x54cd8f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cd91: { // 0x54cd91: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0054cd95: { // 0x54cd95: 0f84f6000000 JZ 0x0054ce91
    if(integer::condition("JZ",flags)) goto L0054ce91;
  }
  L0054cd9b: { // 0x54cd9b: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cd9f: { // 0x54cd9f: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054cda2: { // 0x54cda2: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054cda5: { // 0x54cda5: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054cda7: { // 0x54cda7: 7814 JS 0x0054cdbd
    if(integer::condition("JS",flags)) goto L0054cdbd;
  }
  L0054cda9: { // 0x54cda9: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054cdae: { // 0x54cdae: 7d0d JGE 0x0054cdbd
    if(integer::condition("JGE",flags)) goto L0054cdbd;
  }
  L0054cdb0: { // 0x54cdb0: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054cdb6: { // 0x54cdb6: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054cdb9: { // 0x54cdb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054cdbb: { // 0x54cdbb: 750c JNZ 0x0054cdc9
    if(integer::condition("JNZ",flags)) goto L0054cdc9;
  }
  L0054cdbd: { // 0x54cdbd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0054cdbf: { // 0x54cdbf: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054cdc4: { // 0x54cdc4: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054cdc9: { // 0x54cdc9: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0054cdcf: { // 0x54cdcf: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054cdd2: { // 0x54cdd2: 0f84b9000000 JZ 0x0054ce91
    if(integer::condition("JZ",flags)) goto L0054ce91;
  }
  L0054cdd8: { // 0x54cdd8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054cdda: { // 0x54cdda: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054cddc: { // 0x54cddc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cddd: { // 0x54cddd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054cddf: { // 0x54cddf: e87c070000 CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5557732u); flags=s.arithmetic_flags;
  }
  L0054cde4: { // 0x54cde4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0054cde7: { // 0x54cde7: 0f84ca000000 JZ 0x0054ceb7
    if(integer::condition("JZ",flags)) goto L0054ceb7;
  }
  L0054cded: { // 0x54cded: 8b4f50 MOV ECX,dword ptr [EDI + 0x50]
    s.cx = m.r32((s.di+0x00000050u));
  }
  L0054cdf0: { // 0x54cdf0: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054cdf3: { // 0x54cdf3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054cdf5: { // 0x54cdf5: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0054cdf7: { // 0x54cdf7: 8a4308 MOV AL,byte ptr [EBX + 0x8]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000008u)));
  }
  L0054cdfa: { // 0x54cdfa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cdfc: { // 0x54cdfc: 7407 JZ 0x0054ce05
    if(integer::condition("JZ",flags)) goto L0054ce05;
  }
  L0054cdfe: { // 0x54cdfe: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0054ce00: { // 0x54ce00: e98c000000 JMP 0x0054ce91
    goto L0054ce91;
  }
  L0054ce05: { // 0x54ce05: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054ce09: { // 0x54ce09: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054ce0c: { // 0x54ce0c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054ce0f: { // 0x54ce0f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054ce11: { // 0x54ce11: 7818 JS 0x0054ce2b
    if(integer::condition("JS",flags)) goto L0054ce2b;
  }
  L0054ce13: { // 0x54ce13: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054ce18: { // 0x54ce18: 7d11 JGE 0x0054ce2b
    if(integer::condition("JGE",flags)) goto L0054ce2b;
  }
  L0054ce1a: { // 0x54ce1a: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054ce20: { // 0x54ce20: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054ce23: { // 0x54ce23: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054ce25: { // 0x54ce25: 7404 JZ 0x0054ce2b
    if(integer::condition("JZ",flags)) goto L0054ce2b;
  }
  L0054ce27: { // 0x54ce27: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054ce29: { // 0x54ce29: eb0c JMP 0x0054ce37
    goto L0054ce37;
  }
  L0054ce2b: { // 0x54ce2b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0054ce2d: { // 0x54ce2d: bf1076a500 MOV EDI,0xa57610
    s.di = 0x00a57610u;
  }
  L0054ce32: { // 0x54ce32: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054ce37: { // 0x54ce37: 668b33 MOV SI,word ptr [EBX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L0054ce3a: { // 0x54ce3a: 8d6b04 LEA EBP,[EBX + 0x4]
    s.bp = (s.bx+0x00000004u);
  }
  L0054ce3d: { // 0x54ce3d: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0054ce43: { // 0x54ce43: 662b7500 SUB SI,word ptr [EBP]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.bp)),16,flags)) & 0xffffu);
  }
  L0054ce47: { // 0x54ce47: 66f7de NEG SI
    s.si = (s.si & 0xffff0000u) | ((integer::sub(0u,(s.si & 0xffffu),16,flags)) & 0xffffu);
  }
  L0054ce4a: { // 0x54ce4a: 1bf6 SBB ESI,ESI
    s.si = integer::sub(s.si,s.si,32,flags,flags&integer::CF);
  }
  L0054ce4c: { // 0x54ce4c: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  L0054ce4f: { // 0x54ce4f: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0054ce52: { // 0x54ce52: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054ce55: { // 0x54ce55: 7415 JZ 0x0054ce6c
    if(integer::condition("JZ",flags)) goto L0054ce6c;
  }
  L0054ce57: { // 0x54ce57: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054ce58: { // 0x54ce58: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce5a: { // 0x54ce5a: e86198f2ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5557855u); flags=s.arithmetic_flags;
  }
  L0054ce5f: { // 0x54ce5f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054ce61: { // 0x54ce61: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0054ce67: { // 0x54ce67: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054ce6a: { // 0x54ce6a: 75eb JNZ 0x0054ce57
    if(integer::condition("JNZ",flags)) goto L0054ce57;
  }
  L0054ce6c: { // 0x54ce6c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce6e: { // 0x54ce6e: e8ede6f2ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5557875u); flags=s.arithmetic_flags;
  }
  L0054ce73: { // 0x54ce73: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ce75: { // 0x54ce75: 750b JNZ 0x0054ce82
    if(integer::condition("JNZ",flags)) goto L0054ce82;
  }
  L0054ce77: { // 0x54ce77: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce79: { // 0x54ce79: e802e7f2ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5557886u); flags=s.arithmetic_flags;
  }
  L0054ce7e: { // 0x54ce7e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ce80: { // 0x54ce80: 7431 JZ 0x0054ceb3
    if(integer::condition("JZ",flags)) goto L0054ceb3;
  }
  L0054ce82: { // 0x54ce82: 83bfec00000003 CMP dword ptr [EDI + 0xec],0x3
    (void)integer::sub(m.r32((s.di+0x000000ecu)),0x00000003u,32,flags);
  }
  L0054ce89: { // 0x54ce89: 7428 JZ 0x0054ceb3
    if(integer::condition("JZ",flags)) goto L0054ceb3;
  }
  L0054ce8b: { // 0x54ce8b: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0054ce8d: { // 0x54ce8d: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0054ce91: { // 0x54ce91: 8b8ff4000000 MOV ECX,dword ptr [EDI + 0xf4]
    s.cx = m.r32((s.di+0x000000f4u));
  }
  L0054ce97: { // 0x54ce97: 8b97f0000000 MOV EDX,dword ptr [EDI + 0xf0]
    s.dx = m.r32((s.di+0x000000f0u));
  }
  L0054ce9d: { // 0x54ce9d: 8d441101 LEA EAX,[ECX + EDX*0x1 + 0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0054cea1: { // 0x54cea1: 0fbf4e02 MOVSX ECX,word ptr [ESI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cea5: { // 0x54cea5: 0fbf16 MOVSX EDX,word ptr [ESI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054cea8: { // 0x54cea8: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L0054ceab: { // 0x54ceab: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054cead: { // 0x54cead: 7913 JNS 0x0054cec2
    if(integer::condition("JNS",flags)) goto L0054cec2;
  }
  L0054ceaf: { // 0x54ceaf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054ceb1: { // 0x54ceb1: eb19 JMP 0x0054cecc
    goto L0054cecc;
  }
  L0054ceb3: { // 0x54ceb3: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0054ceb5: { // 0x54ceb5: ebd6 JMP 0x0054ce8d
    goto L0054ce8d;
  }
  L0054ceb7: { // 0x54ceb7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054ceb8: { // 0x54ceb8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054ceb9: { // 0x54ceb9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054ceba: { // 0x54ceba: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0054cebd: { // 0x54cebd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cebe: { // 0x54cebe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cebf: { // 0x54cebf: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0054cec2: { // 0x54cec2: 8b4f68 MOV ECX,dword ptr [EDI + 0x68]
    s.cx = m.r32((s.di+0x00000068u));
  }
  L0054cec5: { // 0x54cec5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0054cec7: { // 0x54cec7: 7c03 JL 0x0054cecc
    if(integer::condition("JL",flags)) goto L0054cecc;
  }
  L0054cec9: { // 0x54cec9: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L0054cecc: { // 0x54cecc: 8b4f64 MOV ECX,dword ptr [EDI + 0x64]
    s.cx = m.r32((s.di+0x00000064u));
  }
  L0054cecf: { // 0x54cecf: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0054ced1: { // 0x54ced1: 668b548102 MOV DX,word ptr [ECX + EAX*0x4 + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+(s.ax * 0x00000004u)+0x00000002u)));
  }
  L0054ced6: { // 0x54ced6: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054ceda: { // 0x54ceda: 8b4c8718 MOV ECX,dword ptr [EDI + EAX*0x4 + 0x18]
    s.cx = m.r32((s.di+(s.ax * 0x00000004u)+0x00000018u));
  }
  L0054cede: { // 0x54cede: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cedf: { // 0x54cedf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054cee1: { // 0x54cee1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cee2: { // 0x54cee2: 668b0451 MOV AX,word ptr [ECX + EDX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.cx+(s.dx * 0x00000002u))));
  }
  L0054cee6: { // 0x54cee6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cee7: { // 0x54cee7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cee8: { // 0x54cee8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cee9: { // 0x54cee9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00161d60(Memory& m,State& s,Frame& f,const Operations& op) {
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
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_000068f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004068f0: { // 0x4068f0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {s.ax=m.r32(s.cx);if(m.r32(s.ax+0x84)!=0x505da0)throw std::domain_error("229 actual tail getter");f_00105da0(m,s,f,op);return;}
void f_00105da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00505da0: { // 0x505da0: 8b81a8050000 MOV EAX, dword ptr [ECX + 0x5a8]
    s.ax = m.r32((s.cx+0x000005a8u));
  }
  L00505da6: { // 0x505da6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00108c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00508c50: { // 0x508c50: b80f000000 MOV EAX, 0xf
    s.ax = 0x0000000fu;
  }
  L00508c55: { // 0x508c55: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ca2f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ca2f0: { // 0x4ca2f0: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004ca2f3: { // 0x4ca2f3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ca2f4: { // 0x4ca2f4: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004ca2f6: { // 0x4ca2f6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ca2f7: { // 0x4ca2f7: 8a8674050000 MOV AL, byte ptr [ESI + 0x574]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000574u)));
  }
  L004ca2fd: { // 0x4ca2fd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ca2ff: { // 0x4ca2ff: 7c45 JL 0x4CA346
    if(integer::condition("JL",flags)) goto L004ca346;
  }
  L004ca301: { // 0x4ca301: 8b0dfce48400 MOV ECX, dword ptr [0x84E4FC]
    s.cx = m.r32((0x0084e4fcu));
  }
  L004ca307: { // 0x4ca307: 0fbec0 MOVSX EAX, AL
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffu),8));
  }
  L004ca30a: { // 0x4ca30a: 8b1481 MOV EDX, dword ptr [ECX + EAX*4]
    s.dx = m.r32((s.cx+(s.ax * 4u)));
  }
  L004ca30d: { // 0x4ca30d: 8b4228 MOV EAX, dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  L004ca310: { // 0x4ca310: 0fbfc8 MOVSX ECX, AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ca313: { // 0x4ca313: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L004ca317: { // 0x4ca317: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004ca31b: { // 0x4ca31b: 0fbf54240a MOVSX EDX, word ptr [ESP + 0xA]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000000au)),16));
  }
  L004ca320: { // 0x4ca320: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L004ca323: { // 0x4ca323: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004ca325: { // 0x4ca325: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L004ca32b: { // 0x4ca32b: c1e208 SHL EDX, 8
    s.dx = integer::shift(s.dx,8u,32,flags,integer::Shift::left);
  }
  L004ca32e: { // 0x4ca32e: 890f MOV dword ptr [EDI], ECX
    m.w32((s.di), s.cx);
  }
  L004ca330: { // 0x4ca330: 81c280000000 ADD EDX, 0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L004ca336: { // 0x4ca336: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004ca338: { // 0x4ca338: 895704 MOV dword ptr [EDI + 4], EDX
    m.w32((s.di+4u), s.dx);
  }
  L004ca33b: { // 0x4ca33b: 897708 MOV dword ptr [EDI + 8], ESI
    m.w32((s.di+8u), s.si);
  }
  L004ca33e: { // 0x4ca33e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ca33f: { // 0x4ca33f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ca340: { // 0x4ca340: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004ca343: { // 0x4ca343: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004ca346: { // 0x4ca346: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004ca34c: { // 0x4ca34c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ca34e: { // 0x4ca34e: 750a JNZ 0x4CA35A
    if(integer::condition("JNZ",flags)) goto L004ca35a;
  }
  L004ca350: { // 0x4ca350: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L004ca355: { // 0x4ca355: e8166f2b00 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5022554u); flags=s.arithmetic_flags;
  }
  L004ca35a: { // 0x4ca35a: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004ca360: { // 0x4ca360: 8d54240c LEA EDX, [ESP + 0xC]
    s.dx = (f.sp+0x0000000cu);
  }
  L004ca364: { // 0x4ca364: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004ca365: { // 0x4ca365: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ca366: { // 0x4ca366: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ca368: { // 0x4ca368: ff5118 CALL dword ptr [ECX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000018u)),5022571u); flags=s.arithmetic_flags;
  }
  L004ca36b: { // 0x4ca36b: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ca36d: { // 0x4ca36d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L004ca370: { // 0x4ca370: 8b7808 MOV EDI, dword ptr [EAX + 8]
    s.di = m.r32((s.ax+8u));
  }
  L004ca373: { // 0x4ca373: a150e28400 MOV EAX, dword ptr [0x84E250]
    s.ax = m.r32((0x0084e250u));
  }
  L004ca378: { // 0x4ca378: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004ca37a: { // 0x4ca37a: 7510 JNZ 0x4CA38C
    if(integer::condition("JNZ",flags)) goto L004ca38c;
  }
  L004ca37c: { // 0x4ca37c: 3b1554e28400 CMP EDX, dword ptr [0x84E254]
    (void)integer::sub(s.dx,m.r32((0x0084e254u)),32,flags);
  }
  L004ca382: { // 0x4ca382: 7508 JNZ 0x4CA38C
    if(integer::condition("JNZ",flags)) goto L004ca38c;
  }
  L004ca384: { // 0x4ca384: 3b3d58e28400 CMP EDI, dword ptr [0x84E258]
    (void)integer::sub(s.di,m.r32((0x0084e258u)),32,flags);
  }
  L004ca38a: { // 0x4ca38a: 7416 JZ 0x4CA3A2
    if(integer::condition("JZ",flags)) goto L004ca3a2;
  }
  L004ca38c: { // 0x4ca38c: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004ca390: { // 0x4ca390: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L004ca392: { // 0x4ca392: 890e MOV dword ptr [ESI], ECX
    m.w32((s.si), s.cx);
  }
  L004ca394: { // 0x4ca394: 895604 MOV dword ptr [ESI + 4], EDX
    m.w32((s.si+4u), s.dx);
  }
  L004ca397: { // 0x4ca397: 897e08 MOV dword ptr [ESI + 8], EDI
    m.w32((s.si+8u), s.di);
  }
  L004ca39a: { // 0x4ca39a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ca39b: { // 0x4ca39b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ca39c: { // 0x4ca39c: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004ca39f: { // 0x4ca39f: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004ca3a2: { // 0x4ca3a2: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ca3a4: { // 0x4ca3a4: 8d4c240c LEA ECX, [ESP + 0xC]
    s.cx = (f.sp+0x0000000cu);
  }
  L004ca3a8: { // 0x4ca3a8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ca3a9: { // 0x4ca3a9: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ca3ab: { // 0x4ca3ab: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5022638u); flags=s.arithmetic_flags;
  }
  L004ca3ae: { // 0x4ca3ae: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004ca3b0: { // 0x4ca3b0: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004ca3b4: { // 0x4ca3b4: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004ca3b6: { // 0x4ca3b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ca3b7: { // 0x4ca3b7: 8b32 MOV ESI, dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  L004ca3b9: { // 0x4ca3b9: 8931 MOV dword ptr [ECX], ESI
    m.w32((s.cx), s.si);
  }
  L004ca3bb: { // 0x4ca3bb: 8b7204 MOV ESI, dword ptr [EDX + 4]
    s.si = m.r32((s.dx+4u));
  }
  L004ca3be: { // 0x4ca3be: 897104 MOV dword ptr [ECX + 4], ESI
    m.w32((s.cx+4u), s.si);
  }
  L004ca3c1: { // 0x4ca3c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ca3c2: { // 0x4ca3c2: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L004ca3c5: { // 0x4ca3c5: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L004ca3c8: { // 0x4ca3c8: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004ca3cb: { // 0x4ca3cb: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4366800u:f_0002a1d0(m,s,child,{});break;
case 4354928u:f_00027370(m,s,child,{});break;
case 4357776u:f_00027e90(m,s,child,{});break;
case 4354144u:f_00027060(m,s,child,{});break;
case 4369920u:f_0002ae00(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5557632u:f_0014cd80(m,s,child,{});break;
case 5643616u:f_00161d60(m,s,child,{});break;
case 4221168u:f_000068f0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 5266848u:f_00105da0(m,s,child,{});break;
case 5278800u:f_00108c50(m,s,child,{});break;
case 5022448u:f_000ca2f0(m,s,child,{});break;
default:throw std::domain_error("recovery229 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004bafc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004bafc0: { // 0x4bafc0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L004bafc3: { // 0x4bafc3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004bafc4: { // 0x4bafc4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004bafc6: { // 0x4bafc6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004bafc7: { // 0x4bafc7: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004bafcb: { // 0x4bafcb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004bafcd: { // 0x4bafcd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004bafcf: { // 0x4bafcf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bafd0: { // 0x4bafd0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bafd2: { // 0x4bafd2: ff504c CALL dword ptr [EAX + 0x4c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000004cu)),4960213u); flags=s.arithmetic_flags;
  }
  L004bafd5: { // 0x4bafd5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004bafd7: { // 0x4bafd7: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L004bafdb: { // 0x4bafdb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004bafdd: { // 0x4bafdd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bafde: { // 0x4bafde: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bafe4: { // 0x4bafe4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bafe6: { // 0x4bafe6: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bafe9: { // 0x4bafe9: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  L004bafee: { // 0x4bafee: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004baff1: { // 0x4baff1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004baff2: { // 0x4baff2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004baff8: { // 0x4baff8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004baffa: { // 0x4baffa: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004baffd: { // 0x4baffd: 668944240e MOV word ptr [ESP + 0xe],AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L004bb002: { // 0x4bb002: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L004bb006: { // 0x4bb006: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004bb008: { // 0x4bb008: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L004bb00c: { // 0x4bb00c: 750a JNZ 0x004bb018
    if(integer::condition("JNZ",flags)) goto L004bb018;
  }
  L004bb00e: { // 0x4bb00e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bb00f: { // 0x4bb00f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004bb011: { // 0x4bb011: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bb012: { // 0x4bb012: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L004bb015: { // 0x4bb015: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004bb018: { // 0x4bb018: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L004bb01c: { // 0x4bb01c: 8d86d0040000 LEA EAX,[ESI + 0x4d0]
    s.ax = (s.si+0x000004d0u);
  }
  L004bb022: { // 0x4bb022: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004bb023: { // 0x4bb023: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb024: { // 0x4bb024: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L004bb028: { // 0x4bb028: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L004bb02c: { // 0x4bb02c: e82fc0f6ff CALL 0x00427060
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427060u,4960305u); flags=s.arithmetic_flags;
  }
  L004bb031: { // 0x4bb031: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004bb033: { // 0x4bb033: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L004bb037: { // 0x4bb037: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004bb03b: { // 0x4bb03b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004bb03c: { // 0x4bb03c: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L004bb03e: { // 0x4bb03e: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L004bb040: { // 0x4bb040: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L004bb044: { // 0x4bb044: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004bb045: { // 0x4bb045: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004bb046: { // 0x4bb046: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L004bb04a: { // 0x4bb04a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb04b: { // 0x4bb04b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb04c: { // 0x4bb04c: b908998100 MOV ECX,0x819908
    s.cx = 0x00819908u;
  }
  L004bb051: { // 0x4bb051: e87af1f6ff CALL 0x0042a1d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042a1d0u,4960342u); flags=s.arithmetic_flags;
  }
  L004bb056: { // 0x4bb056: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bb057: { // 0x4bb057: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bb058: { // 0x4bb058: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L004bb05b: { // 0x4bb05b: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
