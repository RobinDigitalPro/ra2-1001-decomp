#include "recovered/recovery_b571_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b571 {
namespace {
void f_002741c0(Memory&,State&,Frame&,const Operations&);
void f_000829a0(Memory&,State&,Frame&,const Operations&);
void f_002744b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_002741c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006741c0: { // 0x6741c0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006741c3: { // 0x6741c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006741c4: { // 0x6741c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006741c5: { // 0x6741c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006741c6: { // 0x6741c6: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L006741ca: { // 0x6741ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006741cb: { // 0x6741cb: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L006741cf: { // 0x6741cf: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L006741d1: { // 0x6741d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006741d3: { // 0x6741d3: e8c8e7e0ff CALL 0x004829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,6767064u); flags=s.arithmetic_flags;
  }
  L006741d8: { // 0x6741d8: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L006741dc: { // 0x6741dc: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L006741e0: { // 0x6741e0: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L006741e2: { // 0x6741e2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006741e4: { // 0x6741e4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006741e8: { // 0x6741e8: e8b3e7e0ff CALL 0x004829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,6767085u); flags=s.arithmetic_flags;
  }
  L006741ed: { // 0x6741ed: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006741ef: { // 0x6741ef: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006741f1: { // 0x6741f1: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006741f5: { // 0x6741f5: 750c JNZ 0x00674203
    if(integer::condition("JNZ",flags)) goto L00674203;
  }
  L006741f7: { // 0x6741f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006741f8: { // 0x6741f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006741f9: { // 0x6741f9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006741fa: { // 0x6741fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006741fc: { // 0x6741fc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006741fd: { // 0x6741fd: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674200: { // 0x674200: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00674203: { // 0x674203: 83fe1f CMP ESI,0x1f
    (void)integer::sub(s.si,0x0000001fu,32,flags);
  }
  L00674206: { // 0x674206: 740f JZ 0x00674217
    if(integer::condition("JZ",flags)) goto L00674217;
  }
  L00674208: { // 0x674208: 83fe39 CMP ESI,0x39
    (void)integer::sub(s.si,0x00000039u,32,flags);
  }
  L0067420b: { // 0x67420b: 740a JZ 0x00674217
    if(integer::condition("JZ",flags)) goto L00674217;
  }
  L0067420d: { // 0x67420d: 83fe20 CMP ESI,0x20
    (void)integer::sub(s.si,0x00000020u,32,flags);
  }
  L00674210: { // 0x674210: c644242000 MOV byte ptr [ESP + 0x20],0x0
    m.w8((f.sp+0x00000020u), 0x00000000u);
  }
  L00674215: { // 0x674215: 7505 JNZ 0x0067421c
    if(integer::condition("JNZ",flags)) goto L0067421c;
  }
  L00674217: { // 0x674217: c644242001 MOV byte ptr [ESP + 0x20],0x1
    m.w8((f.sp+0x00000020u), 0x00000001u);
  }
  L0067421c: { // 0x67421c: 83fd1f CMP EBP,0x1f
    (void)integer::sub(s.bp,0x0000001fu,32,flags);
  }
  L0067421f: { // 0x67421f: 740e JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L00674221: { // 0x674221: 83fd39 CMP EBP,0x39
    (void)integer::sub(s.bp,0x00000039u,32,flags);
  }
  L00674224: { // 0x674224: 7409 JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L00674226: { // 0x674226: 83fd20 CMP EBP,0x20
    (void)integer::sub(s.bp,0x00000020u,32,flags);
  }
  L00674229: { // 0x674229: 7404 JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L0067422b: { // 0x67422b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0067422d: { // 0x67422d: eb02 JMP 0x00674231
    goto L00674231;
  }
  L0067422f: { // 0x67422f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674231: { // 0x674231: 8a4c2420 MOV CL,byte ptr [ESP + 0x20]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000020u)));
  }
  L00674235: { // 0x674235: 88442424 MOV byte ptr [ESP + 0x24],AL
    m.w8((f.sp+0x00000024u), (s.ax & 0xffu));
  }
  L00674239: { // 0x674239: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0067423b: { // 0x67423b: 7449 JZ 0x00674286
    if(integer::condition("JZ",flags)) goto L00674286;
  }
  L0067423d: { // 0x67423d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067423f: { // 0x67423f: 0f8491000000 JZ 0x006742d6
    if(integer::condition("JZ",flags)) goto L006742d6;
  }
  L00674245: { // 0x674245: 8b0d8c7fa200 MOV ECX,dword ptr [0x00a27f8c]
    s.cx = m.r32((0x00a27f8cu));
  }
  L0067424b: { // 0x67424b: 8b04b9 MOV EAX,dword ptr [ECX + EDI*0x4]
    s.ax = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L0067424e: { // 0x67424e: 8b0c99 MOV ECX,dword ptr [ECX + EBX*0x4]
    s.cx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L00674251: { // 0x674251: 8b90b0000000 MOV EDX,dword ptr [EAX + 0xb0]
    s.dx = m.r32((s.ax+0x000000b0u));
  }
  L00674257: { // 0x674257: 8bb1b0000000 MOV ESI,dword ptr [ECX + 0xb0]
    s.si = m.r32((s.cx+0x000000b0u));
  }
  L0067425d: { // 0x67425d: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0067425f: { // 0x67425f: 7d0c JGE 0x0067426d
    if(integer::condition("JGE",flags)) goto L0067426d;
  }
  L00674261: { // 0x674261: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674262: { // 0x674262: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674263: { // 0x674263: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674264: { // 0x674264: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674266: { // 0x674266: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674267: { // 0x674267: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067426a: { // 0x67426a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067426d: { // 0x67426d: 7e0c JLE 0x0067427b
    if(integer::condition("JLE",flags)) goto L0067427b;
  }
  L0067426f: { // 0x67426f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674270: { // 0x674270: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674271: { // 0x674271: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674272: { // 0x674272: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674274: { // 0x674274: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674275: { // 0x674275: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674278: { // 0x674278: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067427b: { // 0x67427b: 8b4060 MOV EAX,dword ptr [EAX + 0x60]
    s.ax = m.r32((s.ax+0x00000060u));
  }
  L0067427e: { // 0x67427e: 8b4960 MOV ECX,dword ptr [ECX + 0x60]
    s.cx = m.r32((s.cx+0x00000060u));
  }
  L00674281: { // 0x674281: e90d020000 JMP 0x00674493
    goto L00674493;
  }
  L00674286: { // 0x674286: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674288: { // 0x674288: 754c JNZ 0x006742d6
    if(integer::condition("JNZ",flags)) goto L006742d6;
  }
  L0067428a: { // 0x67428a: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0067428f: { // 0x67428f: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00674293: { // 0x674293: 8b9aec050000 MOV EBX,dword ptr [EDX + 0x5ec]
    s.bx = m.r32((s.dx+0x000005ecu));
  }
  L00674299: { // 0x674299: 8b4834 MOV ECX,dword ptr [EAX + 0x34]
    s.cx = m.r32((s.ax+0x00000034u));
  }
  L0067429c: { // 0x67429c: 8b81bc000000 MOV EAX,dword ptr [ECX + 0xbc]
    s.ax = m.r32((s.cx+0x000000bcu));
  }
  L006742a2: { // 0x6742a2: 8b8fec050000 MOV ECX,dword ptr [EDI + 0x5ec]
    s.cx = m.r32((s.di+0x000005ecu));
  }
  L006742a8: { // 0x6742a8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006742aa: { // 0x6742aa: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006742ad: { // 0x6742ad: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006742af: { // 0x6742af: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006742b2: { // 0x6742b2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006742b4: { // 0x6742b4: 7410 JZ 0x006742c6
    if(integer::condition("JZ",flags)) goto L006742c6;
  }
  L006742b6: { // 0x6742b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742b8: { // 0x6742b8: 7520 JNZ 0x006742da
    if(integer::condition("JNZ",flags)) goto L006742da;
  }
  L006742ba: { // 0x6742ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006742bb: { // 0x6742bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006742bc: { // 0x6742bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006742bd: { // 0x6742bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006742bf: { // 0x6742bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006742c0: { // 0x6742c0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006742c3: { // 0x6742c3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006742c6: { // 0x6742c6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742c8: { // 0x6742c8: 7410 JZ 0x006742da
    if(integer::condition("JZ",flags)) goto L006742da;
  }
  L006742ca: { // 0x6742ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006742cb: { // 0x6742cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006742cc: { // 0x6742cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006742cd: { // 0x6742cd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006742cf: { // 0x6742cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006742d0: { // 0x6742d0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006742d3: { // 0x6742d3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006742d6: { // 0x6742d6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L006742da: { // 0x6742da: 83fe28 CMP ESI,0x28
    (void)integer::sub(s.si,0x00000028u,32,flags);
  }
  L006742dd: { // 0x6742dd: 741f JZ 0x006742fe
    if(integer::condition("JZ",flags)) goto L006742fe;
  }
  L006742df: { // 0x6742df: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L006742e2: { // 0x6742e2: 741a JZ 0x006742fe
    if(integer::condition("JZ",flags)) goto L006742fe;
  }
  L006742e4: { // 0x6742e4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006742e6: { // 0x6742e6: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L006742e8: { // 0x6742e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742ea: { // 0x6742ea: 884c2428 MOV byte ptr [ESP + 0x28],CL
    m.w8((f.sp+0x00000028u), (s.cx & 0xffu));
  }
  L006742ee: { // 0x6742ee: 7422 JZ 0x00674312
    if(integer::condition("JZ",flags)) goto L00674312;
  }
  L006742f0: { // 0x6742f0: 8a87da0a0000 MOV AL,byte ptr [EDI + 0xada]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000adau)));
  }
  L006742f6: { // 0x6742f6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742f8: { // 0x6742f8: 7418 JZ 0x00674312
    if(integer::condition("JZ",flags)) goto L00674312;
  }
  L006742fa: { // 0x6742fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006742fc: { // 0x6742fc: eb16 JMP 0x00674314
    goto L00674314;
  }
  L006742fe: { // 0x6742fe: 8a8f460b0000 MOV CL,byte ptr [EDI + 0xb46]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000b46u)));
  }
  L00674304: { // 0x674304: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674306: { // 0x674306: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674308: { // 0x674308: 74dc JZ 0x006742e6
    if(integer::condition("JZ",flags)) goto L006742e6;
  }
  L0067430a: { // 0x67430a: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0067430c: { // 0x67430c: 884c2428 MOV byte ptr [ESP + 0x28],CL
    m.w8((f.sp+0x00000028u), (s.cx & 0xffu));
  }
  L00674310: { // 0x674310: ebde JMP 0x006742f0
    goto L006742f0;
  }
  L00674312: { // 0x674312: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674314: { // 0x674314: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674316: { // 0x674316: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L0067431a: { // 0x67431a: 7509 JNZ 0x00674325
    if(integer::condition("JNZ",flags)) goto L00674325;
  }
  L0067431c: { // 0x67431c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067431e: { // 0x67431e: c644242c01 MOV byte ptr [ESP + 0x2c],0x1
    m.w8((f.sp+0x0000002cu), 0x00000001u);
  }
  L00674323: { // 0x674323: 7405 JZ 0x0067432a
    if(integer::condition("JZ",flags)) goto L0067432a;
  }
  L00674325: { // 0x674325: c644242c00 MOV byte ptr [ESP + 0x2c],0x0
    m.w8((f.sp+0x0000002cu), 0x00000000u);
  }
  L0067432a: { // 0x67432a: 83fd28 CMP EBP,0x28
    (void)integer::sub(s.bp,0x00000028u,32,flags);
  }
  L0067432d: { // 0x67432d: 741f JZ 0x0067434e
    if(integer::condition("JZ",flags)) goto L0067434e;
  }
  L0067432f: { // 0x67432f: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L00674332: { // 0x674332: 741a JZ 0x0067434e
    if(integer::condition("JZ",flags)) goto L0067434e;
  }
  L00674334: { // 0x674334: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674336: { // 0x674336: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00674338: { // 0x674338: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067433a: { // 0x67433a: 7422 JZ 0x0067435e
    if(integer::condition("JZ",flags)) goto L0067435e;
  }
  L0067433c: { // 0x67433c: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00674340: { // 0x674340: 8a85da0a0000 MOV AL,byte ptr [EBP + 0xada]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000adau)));
  }
  L00674346: { // 0x674346: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674348: { // 0x674348: 7418 JZ 0x00674362
    if(integer::condition("JZ",flags)) goto L00674362;
  }
  L0067434a: { // 0x67434a: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L0067434c: { // 0x67434c: eb16 JMP 0x00674364
    goto L00674364;
  }
  L0067434e: { // 0x67434e: 8a8a460b0000 MOV CL,byte ptr [EDX + 0xb46]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000b46u)));
  }
  L00674354: { // 0x674354: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674356: { // 0x674356: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674358: { // 0x674358: 74dc JZ 0x00674336
    if(integer::condition("JZ",flags)) goto L00674336;
  }
  L0067435a: { // 0x67435a: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0067435c: { // 0x67435c: ebde JMP 0x0067433c
    goto L0067433c;
  }
  L0067435e: { // 0x67435e: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00674362: { // 0x674362: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L00674364: { // 0x674364: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00674366: { // 0x674366: 7508 JNZ 0x00674370
    if(integer::condition("JNZ",flags)) goto L00674370;
  }
  L00674368: { // 0x674368: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0067436a: { // 0x67436a: 7504 JNZ 0x00674370
    if(integer::condition("JNZ",flags)) goto L00674370;
  }
  L0067436c: { // 0x67436c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0067436e: { // 0x67436e: eb02 JMP 0x00674372
    goto L00674372;
  }
  L00674370: { // 0x674370: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674372: { // 0x674372: 8a5c2420 MOV BL,byte ptr [ESP + 0x20]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000020u)));
  }
  L00674376: { // 0x674376: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00674378: { // 0x674378: 741c JZ 0x00674396
    if(integer::condition("JZ",flags)) goto L00674396;
  }
  L0067437a: { // 0x67437a: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0067437c: { // 0x67437c: 750c JNZ 0x0067438a
    if(integer::condition("JNZ",flags)) goto L0067438a;
  }
  L0067437e: { // 0x67437e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674380: { // 0x674380: 7508 JNZ 0x0067438a
    if(integer::condition("JNZ",flags)) goto L0067438a;
  }
  L00674382: { // 0x674382: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674384: { // 0x674384: 0f8498000000 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L0067438a: { // 0x67438a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067438b: { // 0x67438b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067438c: { // 0x67438c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0067438d: { // 0x67438d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0067438f: { // 0x67438f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674390: { // 0x674390: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674393: { // 0x674393: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00674396: { // 0x674396: 8a5c242c MOV BL,byte ptr [ESP + 0x2c]
    s.bx = with_al(s.bx, m.r8((f.sp+0x0000002cu)));
  }
  L0067439a: { // 0x67439a: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0067439c: { // 0x67439c: 7428 JZ 0x006743c6
    if(integer::condition("JZ",flags)) goto L006743c6;
  }
  L0067439e: { // 0x67439e: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L006743a2: { // 0x6743a2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006743a4: { // 0x6743a4: 740c JZ 0x006743b2
    if(integer::condition("JZ",flags)) goto L006743b2;
  }
  L006743a6: { // 0x6743a6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743a7: { // 0x6743a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743a8: { // 0x6743a8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743a9: { // 0x6743a9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743ab: { // 0x6743ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743ac: { // 0x6743ac: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743af: { // 0x6743af: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743b2: { // 0x6743b2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006743b4: { // 0x6743b4: 7504 JNZ 0x006743ba
    if(integer::condition("JNZ",flags)) goto L006743ba;
  }
  L006743b6: { // 0x6743b6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006743b8: { // 0x6743b8: 7468 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L006743ba: { // 0x6743ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743bb: { // 0x6743bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743bc: { // 0x6743bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743bd: { // 0x6743bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006743bf: { // 0x6743bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743c0: { // 0x6743c0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743c3: { // 0x6743c3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743c6: { // 0x6743c6: 8a5c2428 MOV BL,byte ptr [ESP + 0x28]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000028u)));
  }
  L006743ca: { // 0x6743ca: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006743cc: { // 0x6743cc: 7424 JZ 0x006743f2
    if(integer::condition("JZ",flags)) goto L006743f2;
  }
  L006743ce: { // 0x6743ce: 8a542424 MOV DL,byte ptr [ESP + 0x24]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000024u)));
  }
  L006743d2: { // 0x6743d2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006743d4: { // 0x6743d4: 740c JZ 0x006743e2
    if(integer::condition("JZ",flags)) goto L006743e2;
  }
  L006743d6: { // 0x6743d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743d7: { // 0x6743d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743d8: { // 0x6743d8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743d9: { // 0x6743d9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743db: { // 0x6743db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743dc: { // 0x6743dc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743df: { // 0x6743df: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743e2: { // 0x6743e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006743e4: { // 0x6743e4: 74d0 JZ 0x006743b6
    if(integer::condition("JZ",flags)) goto L006743b6;
  }
  L006743e6: { // 0x6743e6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743e7: { // 0x6743e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743e8: { // 0x6743e8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743e9: { // 0x6743e9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743eb: { // 0x6743eb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743ec: { // 0x6743ec: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743ef: { // 0x6743ef: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743f2: { // 0x6743f2: 8a4c2413 MOV CL,byte ptr [ESP + 0x13]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000013u)));
  }
  L006743f6: { // 0x6743f6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006743f8: { // 0x6743f8: 7428 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L006743fa: { // 0x6743fa: 8a4c2424 MOV CL,byte ptr [ESP + 0x24]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000024u)));
  }
  L006743fe: { // 0x6743fe: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674400: { // 0x674400: 740c JZ 0x0067440e
    if(integer::condition("JZ",flags)) goto L0067440e;
  }
  L00674402: { // 0x674402: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674403: { // 0x674403: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674404: { // 0x674404: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674405: { // 0x674405: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674407: { // 0x674407: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674408: { // 0x674408: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067440b: { // 0x67440b: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067440e: { // 0x67440e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674410: { // 0x674410: 7504 JNZ 0x00674416
    if(integer::condition("JNZ",flags)) goto L00674416;
  }
  L00674412: { // 0x674412: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00674414: { // 0x674414: 740c JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L00674416: { // 0x674416: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674417: { // 0x674417: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674418: { // 0x674418: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674419: { // 0x674419: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0067441b: { // 0x67441b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067441c: { // 0x67441c: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067441f: { // 0x67441f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00674422: { // 0x674422: 8b875c050000 MOV EAX,dword ptr [EDI + 0x55c]
    s.ax = m.r32((s.di+0x0000055cu));
  }
  L00674428: { // 0x674428: 8b8d5c050000 MOV ECX,dword ptr [EBP + 0x55c]
    s.cx = m.r32((s.bp+0x0000055cu));
  }
  L0067442e: { // 0x67442e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00674430: { // 0x674430: 7d0c JGE 0x0067443e
    if(integer::condition("JGE",flags)) goto L0067443e;
  }
  L00674432: { // 0x674432: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674433: { // 0x674433: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674434: { // 0x674434: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674435: { // 0x674435: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674437: { // 0x674437: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674438: { // 0x674438: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067443b: { // 0x67443b: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067443e: { // 0x67443e: 7e0c JLE 0x0067444c
    if(integer::condition("JLE",flags)) goto L0067444c;
  }
  L00674440: { // 0x674440: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674441: { // 0x674441: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674442: { // 0x674442: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674443: { // 0x674443: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674445: { // 0x674445: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674446: { // 0x674446: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674449: { // 0x674449: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067444c: { // 0x67444c: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00674451: { // 0x674451: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00674453: { // 0x674453: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674454: { // 0x674454: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00674456: { // 0x674456: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6767708u); flags=s.arithmetic_flags;
  }
  L0067445c: { // 0x67445c: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0067445f: { // 0x67445f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00674461: { // 0x674461: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00674466: { // 0x674466: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00674468: { // 0x674468: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674469: { // 0x674469: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6767727u); flags=s.arithmetic_flags;
  }
  L0067446f: { // 0x67446f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00674471: { // 0x674471: 7d0c JGE 0x0067447f
    if(integer::condition("JGE",flags)) goto L0067447f;
  }
  L00674473: { // 0x674473: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674474: { // 0x674474: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674475: { // 0x674475: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674476: { // 0x674476: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674478: { // 0x674478: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674479: { // 0x674479: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067447c: { // 0x67447c: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067447f: { // 0x67447f: 7e0c JLE 0x0067448d
    if(integer::condition("JLE",flags)) goto L0067448d;
  }
  L00674481: { // 0x674481: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674482: { // 0x674482: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674483: { // 0x674483: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674484: { // 0x674484: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674486: { // 0x674486: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674487: { // 0x674487: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067448a: { // 0x67448a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067448d: { // 0x67448d: 8b4760 MOV EAX,dword ptr [EDI + 0x60]
    s.ax = m.r32((s.di+0x00000060u));
  }
  L00674490: { // 0x674490: 8b4d60 MOV ECX,dword ptr [EBP + 0x60]
    s.cx = m.r32((s.bp+0x00000060u));
  }
  L00674493: { // 0x674493: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00674494: { // 0x674494: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674495: { // 0x674495: e879ac0f00 CALL 0x0076f113
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f113u,6767770u); flags=s.arithmetic_flags;
  }
  L0067449a: { // 0x67449a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0067449d: { // 0x67449d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0067449f: { // 0x67449f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006744a0: { // 0x6744a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006744a1: { // 0x6744a1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006744a2: { // 0x6744a2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006744a3: { // 0x6744a3: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L006744a6: { // 0x6744a6: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006744a9: { // 0x6744a9: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_000829a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004829a0: { // 0x4829a0: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L004829a3: { // 0x4829a3: 83f827 CMP EAX,0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  L004829a6: { // 0x4829a6: 7735 JA 0x004829dd
    if(integer::condition("JA",flags)) goto L004829dd;
  }
  L004829a8: { // 0x4829a8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004829aa: { // 0x4829aa: 8a88f4294800 MOV CL,byte ptr [EAX + 0x4829f4]
    s.cx = with_al(s.cx, m.r8((s.ax+0x004829f4u)));
  }
  L004829b0: { // 0x4829b0: ff248de0294800 JMP dword ptr [ECX*0x4 + 0x4829e0]
    switch(m.r32(((s.cx * 0x00000004u)+0x004829e0u))){
    case 0x004829a0u: goto L004829a0;
    case 0x004829a3u: goto L004829a3;
    case 0x004829a6u: goto L004829a6;
    case 0x004829a8u: goto L004829a8;
    case 0x004829aau: goto L004829aa;
    case 0x004829b0u: goto L004829b0;
    case 0x004829b7u: goto L004829b7;
    case 0x004829bcu: goto L004829bc;
    case 0x004829bfu: goto L004829bf;
    case 0x004829c0u: goto L004829c0;
    case 0x004829c6u: goto L004829c6;
    case 0x004829c9u: goto L004829c9;
    case 0x004829cau: goto L004829ca;
    case 0x004829cfu: goto L004829cf;
    case 0x004829d2u: goto L004829d2;
    case 0x004829d3u: goto L004829d3;
    case 0x004829d9u: goto L004829d9;
    case 0x004829dcu: goto L004829dc;
    case 0x004829ddu: goto L004829dd;
    case 0x004829dfu: goto L004829df;
    default:throw std::domain_error("recovery571 unsupported switch destination");}
  }
  L004829b7: { // 0x4829b7: a17ce0a100 MOV EAX,[0x00a1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  L004829bc: { // 0x4829bc: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004829bf: { // 0x4829bf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829c0: { // 0x4829c0: 8b0d0ce0a100 MOV ECX,dword ptr [0x00a1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  L004829c6: { // 0x4829c6: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L004829c9: { // 0x4829c9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829ca: { // 0x4829ca: a1a47fa200 MOV EAX,[0x00a27fa4]
    s.ax = m.r32((0x00a27fa4u));
  }
  L004829cf: { // 0x4829cf: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004829d2: { // 0x4829d2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829d3: { // 0x4829d3: 8b0dac55a200 MOV ECX,dword ptr [0x00a255ac]
    s.cx = m.r32((0x00a255acu));
  }
  L004829d9: { // 0x4829d9: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L004829dc: { // 0x4829dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829dd: { // 0x4829dd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004829df: { // 0x4829df: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002744b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006744b0: { // 0x6744b0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006744b3: { // 0x6744b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006744b4: { // 0x6744b4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006744b6: { // 0x6744b6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006744b7: { // 0x6744b7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L006744b9: { // 0x6744b9: 8b5350 MOV EDX,dword ptr [EBX + 0x50]
    s.dx = m.r32((s.bx+0x00000050u));
  }
  L006744bc: { // 0x6744bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006744bd: { // 0x6744bd: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006744be: { // 0x6744be: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006744bf: { // 0x6744bf: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006744c1: { // 0x6744c1: 895350 MOV dword ptr [EBX + 0x50],EDX
    m.w32((s.bx+0x00000050u), s.dx);
  }
  L006744c4: { // 0x6744c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006744c6: { // 0x6744c6: 0f8eaf000000 JLE 0x0067457b
    if(integer::condition("JLE",flags)) goto L0067457b;
  }
  L006744cc: { // 0x6744cc: 8d7354 LEA ESI,[EBX + 0x54]
    s.si = (s.bx+0x00000054u);
  }
  L006744cf: { // 0x6744cf: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L006744d1: { // 0x6744d1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L006744d4: { // 0x6744d4: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L006744d8: { // 0x6744d8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006744d9: { // 0x6744d9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006744da: { // 0x6744da: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L006744de: { // 0x6744de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006744df: { // 0x6744df: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006744e0: { // 0x6744e0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006744e2: { // 0x6744e2: e8d9fcffff CALL 0x006741c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006741c0u,6767847u); flags=s.arithmetic_flags;
  }
  L006744e7: { // 0x6744e7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006744e9: { // 0x6744e9: 7515 JNZ 0x00674500
    if(integer::condition("JNZ",flags)) goto L00674500;
  }
  L006744eb: { // 0x6744eb: 8b4350 MOV EAX,dword ptr [EBX + 0x50]
    s.ax = m.r32((s.bx+0x00000050u));
  }
  L006744ee: { // 0x6744ee: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L006744ef: { // 0x6744ef: 83c630 ADD ESI,0x30
    s.si = integer::add(s.si,0x00000030u,32,flags);
  }
  L006744f2: { // 0x6744f2: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L006744f4: { // 0x6744f4: 7cd9 JL 0x006744cf
    if(integer::condition("JL",flags)) goto L006744cf;
  }
  L006744f6: { // 0x6744f6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006744f7: { // 0x6744f7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006744f8: { // 0x6744f8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006744f9: { // 0x6744f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006744fa: { // 0x6744fa: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006744fd: { // 0x6744fd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00674500: { // 0x674500: 8b4350 MOV EAX,dword ptr [EBX + 0x50]
    s.ax = m.r32((s.bx+0x00000050u));
  }
  L00674503: { // 0x674503: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00674504: { // 0x674504: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00674506: { // 0x674506: 7e21 JLE 0x00674529
    if(integer::condition("JLE",flags)) goto L00674529;
  }
  L00674508: { // 0x674508: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L0067450b: { // 0x67450b: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0067450e: { // 0x67450e: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00674510: { // 0x674510: 8d7c1954 LEA EDI,[ECX + EBX*0x1 + 0x54]
    s.di = (s.cx+(s.bx * 0x00000001u)+0x00000054u);
  }
  L00674514: { // 0x674514: 8d57d0 LEA EDX,[EDI + -0x30]
    s.dx = (s.di-0x00000030u);
  }
  L00674517: { // 0x674517: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0067451c: { // 0x67451c: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0067451e: { // 0x67451e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0067451f: { // 0x67451f: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00674521: { // 0x674521: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00674523: { // 0x674523: 75ef JNZ 0x00674514
    if(integer::condition("JNZ",flags)) goto L00674514;
  }
  L00674525: { // 0x674525: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00674529: { // 0x674529: 8d546d00 LEA EDX,[EBP + EBP*0x2]
    s.dx = (s.bp+(s.bp * 0x00000002u));
  }
  L0067452d: { // 0x67452d: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L00674530: { // 0x674530: 83ff07 CMP EDI,0x7
    (void)integer::sub(s.di,0x00000007u,32,flags);
  }
  L00674533: { // 0x674533: 8d341a LEA ESI,[EDX + EBX*0x1]
    s.si = (s.dx+(s.bx * 0x00000001u));
  }
  L00674536: { // 0x674536: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0067453a: { // 0x67453a: 897e58 MOV dword ptr [ESI + 0x58],EDI
    m.w32((s.si+0x00000058u), s.di);
  }
  L0067453d: { // 0x67453d: 895654 MOV dword ptr [ESI + 0x54],EDX
    m.w32((s.si+0x00000054u), s.dx);
  }
  L00674540: { // 0x674540: 750a JNZ 0x0067454c
    if(integer::condition("JNZ",flags)) goto L0067454c;
  }
  L00674542: { // 0x674542: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00674544: { // 0x674544: e82765e7ff CALL 0x004eaa70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eaa70u,6767945u); flags=s.arithmetic_flags;
  }
  L00674549: { // 0x674549: 89465c MOV dword ptr [ESI + 0x5c],EAX
    m.w32((s.si+0x0000005cu), s.ax);
  }
  L0067454c: { // 0x67454c: 8d446d06 LEA EAX,[EBP + EBP*0x2 + 0x6]
    s.ax = (s.bp+(s.bp * 0x00000002u)+0x00000006u);
  }
  L00674550: { // 0x674550: 8d566c LEA EDX,[ESI + 0x6c]
    s.dx = (s.si+0x0000006cu);
  }
  L00674553: { // 0x674553: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00674556: { // 0x674556: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00674558: { // 0x674558: 890c18 MOV dword ptr [EAX + EBX*0x1],ECX
    m.w32((s.ax+(s.bx * 0x00000001u)), s.cx);
  }
  L0067455b: { // 0x67455b: 894e64 MOV dword ptr [ESI + 0x64],ECX
    m.w32((s.si+0x00000064u), s.cx);
  }
  L0067455e: { // 0x67455e: 894e68 MOV dword ptr [ESI + 0x68],ECX
    m.w32((s.si+0x00000068u), s.cx);
  }
  L00674561: { // 0x674561: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00674566: { // 0x674566: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L00674568: { // 0x674568: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0067456c: { // 0x67456c: 894e78 MOV dword ptr [ESI + 0x78],ECX
    m.w32((s.si+0x00000078u), s.cx);
  }
  L0067456f: { // 0x67456f: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L00674572: { // 0x674572: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00674575: { // 0x674575: 898e80000000 MOV dword ptr [ESI + 0x80],ECX
    m.w32((s.si+0x00000080u), s.cx);
  }
  L0067457b: { // 0x67457b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067457c: { // 0x67457c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067457d: { // 0x67457d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0067457e: { // 0x67457e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067457f: { // 0x67457f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674582: { // 0x674582: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6767040u:f_002741c0(m,s,child,{});break;
case 4729248u:f_000829a0(m,s,child,{});break;
case 6767792u:f_002744b0(m,s,child,{});break;
default:throw std::domain_error("recovery571 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006741c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,60> table{0xb7,0x29,0x48,0x0,0xd3,0x29,0x48,0x0,0xc0,0x29,0x48,0x0,0xca,0x29,0x48,0x0,0xdd,0x29,0x48,0x0,0x0,0x1,0x1,0x4,0x4,0x2,0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x3,0x3,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x0};leaf::Memory ro(table.data(),0x4829e0,60);m.add(ro);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006741c0: { // 0x6741c0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006741c3: { // 0x6741c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006741c4: { // 0x6741c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006741c5: { // 0x6741c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006741c6: { // 0x6741c6: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L006741ca: { // 0x6741ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006741cb: { // 0x6741cb: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L006741cf: { // 0x6741cf: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L006741d1: { // 0x6741d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006741d3: { // 0x6741d3: e8c8e7e0ff CALL 0x004829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,6767064u); flags=s.arithmetic_flags;
  }
  L006741d8: { // 0x6741d8: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L006741dc: { // 0x6741dc: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L006741e0: { // 0x6741e0: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L006741e2: { // 0x6741e2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006741e4: { // 0x6741e4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006741e8: { // 0x6741e8: e8b3e7e0ff CALL 0x004829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,6767085u); flags=s.arithmetic_flags;
  }
  L006741ed: { // 0x6741ed: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006741ef: { // 0x6741ef: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006741f1: { // 0x6741f1: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006741f5: { // 0x6741f5: 750c JNZ 0x00674203
    if(integer::condition("JNZ",flags)) goto L00674203;
  }
  L006741f7: { // 0x6741f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006741f8: { // 0x6741f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006741f9: { // 0x6741f9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006741fa: { // 0x6741fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006741fc: { // 0x6741fc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006741fd: { // 0x6741fd: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674200: { // 0x674200: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00674203: { // 0x674203: 83fe1f CMP ESI,0x1f
    (void)integer::sub(s.si,0x0000001fu,32,flags);
  }
  L00674206: { // 0x674206: 740f JZ 0x00674217
    if(integer::condition("JZ",flags)) goto L00674217;
  }
  L00674208: { // 0x674208: 83fe39 CMP ESI,0x39
    (void)integer::sub(s.si,0x00000039u,32,flags);
  }
  L0067420b: { // 0x67420b: 740a JZ 0x00674217
    if(integer::condition("JZ",flags)) goto L00674217;
  }
  L0067420d: { // 0x67420d: 83fe20 CMP ESI,0x20
    (void)integer::sub(s.si,0x00000020u,32,flags);
  }
  L00674210: { // 0x674210: c644242000 MOV byte ptr [ESP + 0x20],0x0
    m.w8((f.sp+0x00000020u), 0x00000000u);
  }
  L00674215: { // 0x674215: 7505 JNZ 0x0067421c
    if(integer::condition("JNZ",flags)) goto L0067421c;
  }
  L00674217: { // 0x674217: c644242001 MOV byte ptr [ESP + 0x20],0x1
    m.w8((f.sp+0x00000020u), 0x00000001u);
  }
  L0067421c: { // 0x67421c: 83fd1f CMP EBP,0x1f
    (void)integer::sub(s.bp,0x0000001fu,32,flags);
  }
  L0067421f: { // 0x67421f: 740e JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L00674221: { // 0x674221: 83fd39 CMP EBP,0x39
    (void)integer::sub(s.bp,0x00000039u,32,flags);
  }
  L00674224: { // 0x674224: 7409 JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L00674226: { // 0x674226: 83fd20 CMP EBP,0x20
    (void)integer::sub(s.bp,0x00000020u,32,flags);
  }
  L00674229: { // 0x674229: 7404 JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L0067422b: { // 0x67422b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0067422d: { // 0x67422d: eb02 JMP 0x00674231
    goto L00674231;
  }
  L0067422f: { // 0x67422f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674231: { // 0x674231: 8a4c2420 MOV CL,byte ptr [ESP + 0x20]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000020u)));
  }
  L00674235: { // 0x674235: 88442424 MOV byte ptr [ESP + 0x24],AL
    m.w8((f.sp+0x00000024u), (s.ax & 0xffu));
  }
  L00674239: { // 0x674239: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0067423b: { // 0x67423b: 7449 JZ 0x00674286
    if(integer::condition("JZ",flags)) goto L00674286;
  }
  L0067423d: { // 0x67423d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067423f: { // 0x67423f: 0f8491000000 JZ 0x006742d6
    if(integer::condition("JZ",flags)) goto L006742d6;
  }
  L00674245: { // 0x674245: 8b0d8c7fa200 MOV ECX,dword ptr [0x00a27f8c]
    s.cx = m.r32((0x00a27f8cu));
  }
  L0067424b: { // 0x67424b: 8b04b9 MOV EAX,dword ptr [ECX + EDI*0x4]
    s.ax = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L0067424e: { // 0x67424e: 8b0c99 MOV ECX,dword ptr [ECX + EBX*0x4]
    s.cx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L00674251: { // 0x674251: 8b90b0000000 MOV EDX,dword ptr [EAX + 0xb0]
    s.dx = m.r32((s.ax+0x000000b0u));
  }
  L00674257: { // 0x674257: 8bb1b0000000 MOV ESI,dword ptr [ECX + 0xb0]
    s.si = m.r32((s.cx+0x000000b0u));
  }
  L0067425d: { // 0x67425d: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0067425f: { // 0x67425f: 7d0c JGE 0x0067426d
    if(integer::condition("JGE",flags)) goto L0067426d;
  }
  L00674261: { // 0x674261: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674262: { // 0x674262: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674263: { // 0x674263: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674264: { // 0x674264: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674266: { // 0x674266: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674267: { // 0x674267: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067426a: { // 0x67426a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067426d: { // 0x67426d: 7e0c JLE 0x0067427b
    if(integer::condition("JLE",flags)) goto L0067427b;
  }
  L0067426f: { // 0x67426f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674270: { // 0x674270: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674271: { // 0x674271: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674272: { // 0x674272: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674274: { // 0x674274: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674275: { // 0x674275: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674278: { // 0x674278: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067427b: { // 0x67427b: 8b4060 MOV EAX,dword ptr [EAX + 0x60]
    s.ax = m.r32((s.ax+0x00000060u));
  }
  L0067427e: { // 0x67427e: 8b4960 MOV ECX,dword ptr [ECX + 0x60]
    s.cx = m.r32((s.cx+0x00000060u));
  }
  L00674281: { // 0x674281: e90d020000 JMP 0x00674493
    goto L00674493;
  }
  L00674286: { // 0x674286: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674288: { // 0x674288: 754c JNZ 0x006742d6
    if(integer::condition("JNZ",flags)) goto L006742d6;
  }
  L0067428a: { // 0x67428a: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0067428f: { // 0x67428f: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00674293: { // 0x674293: 8b9aec050000 MOV EBX,dword ptr [EDX + 0x5ec]
    s.bx = m.r32((s.dx+0x000005ecu));
  }
  L00674299: { // 0x674299: 8b4834 MOV ECX,dword ptr [EAX + 0x34]
    s.cx = m.r32((s.ax+0x00000034u));
  }
  L0067429c: { // 0x67429c: 8b81bc000000 MOV EAX,dword ptr [ECX + 0xbc]
    s.ax = m.r32((s.cx+0x000000bcu));
  }
  L006742a2: { // 0x6742a2: 8b8fec050000 MOV ECX,dword ptr [EDI + 0x5ec]
    s.cx = m.r32((s.di+0x000005ecu));
  }
  L006742a8: { // 0x6742a8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006742aa: { // 0x6742aa: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006742ad: { // 0x6742ad: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006742af: { // 0x6742af: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006742b2: { // 0x6742b2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006742b4: { // 0x6742b4: 7410 JZ 0x006742c6
    if(integer::condition("JZ",flags)) goto L006742c6;
  }
  L006742b6: { // 0x6742b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742b8: { // 0x6742b8: 7520 JNZ 0x006742da
    if(integer::condition("JNZ",flags)) goto L006742da;
  }
  L006742ba: { // 0x6742ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006742bb: { // 0x6742bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006742bc: { // 0x6742bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006742bd: { // 0x6742bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006742bf: { // 0x6742bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006742c0: { // 0x6742c0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006742c3: { // 0x6742c3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006742c6: { // 0x6742c6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742c8: { // 0x6742c8: 7410 JZ 0x006742da
    if(integer::condition("JZ",flags)) goto L006742da;
  }
  L006742ca: { // 0x6742ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006742cb: { // 0x6742cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006742cc: { // 0x6742cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006742cd: { // 0x6742cd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006742cf: { // 0x6742cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006742d0: { // 0x6742d0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006742d3: { // 0x6742d3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006742d6: { // 0x6742d6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L006742da: { // 0x6742da: 83fe28 CMP ESI,0x28
    (void)integer::sub(s.si,0x00000028u,32,flags);
  }
  L006742dd: { // 0x6742dd: 741f JZ 0x006742fe
    if(integer::condition("JZ",flags)) goto L006742fe;
  }
  L006742df: { // 0x6742df: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L006742e2: { // 0x6742e2: 741a JZ 0x006742fe
    if(integer::condition("JZ",flags)) goto L006742fe;
  }
  L006742e4: { // 0x6742e4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006742e6: { // 0x6742e6: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L006742e8: { // 0x6742e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742ea: { // 0x6742ea: 884c2428 MOV byte ptr [ESP + 0x28],CL
    m.w8((f.sp+0x00000028u), (s.cx & 0xffu));
  }
  L006742ee: { // 0x6742ee: 7422 JZ 0x00674312
    if(integer::condition("JZ",flags)) goto L00674312;
  }
  L006742f0: { // 0x6742f0: 8a87da0a0000 MOV AL,byte ptr [EDI + 0xada]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000adau)));
  }
  L006742f6: { // 0x6742f6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742f8: { // 0x6742f8: 7418 JZ 0x00674312
    if(integer::condition("JZ",flags)) goto L00674312;
  }
  L006742fa: { // 0x6742fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006742fc: { // 0x6742fc: eb16 JMP 0x00674314
    goto L00674314;
  }
  L006742fe: { // 0x6742fe: 8a8f460b0000 MOV CL,byte ptr [EDI + 0xb46]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000b46u)));
  }
  L00674304: { // 0x674304: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674306: { // 0x674306: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674308: { // 0x674308: 74dc JZ 0x006742e6
    if(integer::condition("JZ",flags)) goto L006742e6;
  }
  L0067430a: { // 0x67430a: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0067430c: { // 0x67430c: 884c2428 MOV byte ptr [ESP + 0x28],CL
    m.w8((f.sp+0x00000028u), (s.cx & 0xffu));
  }
  L00674310: { // 0x674310: ebde JMP 0x006742f0
    goto L006742f0;
  }
  L00674312: { // 0x674312: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674314: { // 0x674314: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674316: { // 0x674316: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L0067431a: { // 0x67431a: 7509 JNZ 0x00674325
    if(integer::condition("JNZ",flags)) goto L00674325;
  }
  L0067431c: { // 0x67431c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067431e: { // 0x67431e: c644242c01 MOV byte ptr [ESP + 0x2c],0x1
    m.w8((f.sp+0x0000002cu), 0x00000001u);
  }
  L00674323: { // 0x674323: 7405 JZ 0x0067432a
    if(integer::condition("JZ",flags)) goto L0067432a;
  }
  L00674325: { // 0x674325: c644242c00 MOV byte ptr [ESP + 0x2c],0x0
    m.w8((f.sp+0x0000002cu), 0x00000000u);
  }
  L0067432a: { // 0x67432a: 83fd28 CMP EBP,0x28
    (void)integer::sub(s.bp,0x00000028u,32,flags);
  }
  L0067432d: { // 0x67432d: 741f JZ 0x0067434e
    if(integer::condition("JZ",flags)) goto L0067434e;
  }
  L0067432f: { // 0x67432f: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L00674332: { // 0x674332: 741a JZ 0x0067434e
    if(integer::condition("JZ",flags)) goto L0067434e;
  }
  L00674334: { // 0x674334: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674336: { // 0x674336: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00674338: { // 0x674338: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067433a: { // 0x67433a: 7422 JZ 0x0067435e
    if(integer::condition("JZ",flags)) goto L0067435e;
  }
  L0067433c: { // 0x67433c: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00674340: { // 0x674340: 8a85da0a0000 MOV AL,byte ptr [EBP + 0xada]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000adau)));
  }
  L00674346: { // 0x674346: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674348: { // 0x674348: 7418 JZ 0x00674362
    if(integer::condition("JZ",flags)) goto L00674362;
  }
  L0067434a: { // 0x67434a: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L0067434c: { // 0x67434c: eb16 JMP 0x00674364
    goto L00674364;
  }
  L0067434e: { // 0x67434e: 8a8a460b0000 MOV CL,byte ptr [EDX + 0xb46]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000b46u)));
  }
  L00674354: { // 0x674354: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674356: { // 0x674356: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674358: { // 0x674358: 74dc JZ 0x00674336
    if(integer::condition("JZ",flags)) goto L00674336;
  }
  L0067435a: { // 0x67435a: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0067435c: { // 0x67435c: ebde JMP 0x0067433c
    goto L0067433c;
  }
  L0067435e: { // 0x67435e: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00674362: { // 0x674362: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L00674364: { // 0x674364: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00674366: { // 0x674366: 7508 JNZ 0x00674370
    if(integer::condition("JNZ",flags)) goto L00674370;
  }
  L00674368: { // 0x674368: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0067436a: { // 0x67436a: 7504 JNZ 0x00674370
    if(integer::condition("JNZ",flags)) goto L00674370;
  }
  L0067436c: { // 0x67436c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0067436e: { // 0x67436e: eb02 JMP 0x00674372
    goto L00674372;
  }
  L00674370: { // 0x674370: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674372: { // 0x674372: 8a5c2420 MOV BL,byte ptr [ESP + 0x20]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000020u)));
  }
  L00674376: { // 0x674376: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00674378: { // 0x674378: 741c JZ 0x00674396
    if(integer::condition("JZ",flags)) goto L00674396;
  }
  L0067437a: { // 0x67437a: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0067437c: { // 0x67437c: 750c JNZ 0x0067438a
    if(integer::condition("JNZ",flags)) goto L0067438a;
  }
  L0067437e: { // 0x67437e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674380: { // 0x674380: 7508 JNZ 0x0067438a
    if(integer::condition("JNZ",flags)) goto L0067438a;
  }
  L00674382: { // 0x674382: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674384: { // 0x674384: 0f8498000000 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L0067438a: { // 0x67438a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067438b: { // 0x67438b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067438c: { // 0x67438c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0067438d: { // 0x67438d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0067438f: { // 0x67438f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674390: { // 0x674390: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674393: { // 0x674393: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00674396: { // 0x674396: 8a5c242c MOV BL,byte ptr [ESP + 0x2c]
    s.bx = with_al(s.bx, m.r8((f.sp+0x0000002cu)));
  }
  L0067439a: { // 0x67439a: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0067439c: { // 0x67439c: 7428 JZ 0x006743c6
    if(integer::condition("JZ",flags)) goto L006743c6;
  }
  L0067439e: { // 0x67439e: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L006743a2: { // 0x6743a2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006743a4: { // 0x6743a4: 740c JZ 0x006743b2
    if(integer::condition("JZ",flags)) goto L006743b2;
  }
  L006743a6: { // 0x6743a6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743a7: { // 0x6743a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743a8: { // 0x6743a8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743a9: { // 0x6743a9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743ab: { // 0x6743ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743ac: { // 0x6743ac: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743af: { // 0x6743af: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006743b2: { // 0x6743b2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006743b4: { // 0x6743b4: 7504 JNZ 0x006743ba
    if(integer::condition("JNZ",flags)) goto L006743ba;
  }
  L006743b6: { // 0x6743b6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006743b8: { // 0x6743b8: 7468 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L006743ba: { // 0x6743ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743bb: { // 0x6743bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743bc: { // 0x6743bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743bd: { // 0x6743bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006743bf: { // 0x6743bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743c0: { // 0x6743c0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743c3: { // 0x6743c3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006743c6: { // 0x6743c6: 8a5c2428 MOV BL,byte ptr [ESP + 0x28]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000028u)));
  }
  L006743ca: { // 0x6743ca: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006743cc: { // 0x6743cc: 7424 JZ 0x006743f2
    if(integer::condition("JZ",flags)) goto L006743f2;
  }
  L006743ce: { // 0x6743ce: 8a542424 MOV DL,byte ptr [ESP + 0x24]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000024u)));
  }
  L006743d2: { // 0x6743d2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006743d4: { // 0x6743d4: 740c JZ 0x006743e2
    if(integer::condition("JZ",flags)) goto L006743e2;
  }
  L006743d6: { // 0x6743d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743d7: { // 0x6743d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743d8: { // 0x6743d8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743d9: { // 0x6743d9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743db: { // 0x6743db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743dc: { // 0x6743dc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743df: { // 0x6743df: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006743e2: { // 0x6743e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006743e4: { // 0x6743e4: 74d0 JZ 0x006743b6
    if(integer::condition("JZ",flags)) goto L006743b6;
  }
  L006743e6: { // 0x6743e6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743e7: { // 0x6743e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743e8: { // 0x6743e8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743e9: { // 0x6743e9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743eb: { // 0x6743eb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743ec: { // 0x6743ec: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743ef: { // 0x6743ef: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006743f2: { // 0x6743f2: 8a4c2413 MOV CL,byte ptr [ESP + 0x13]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000013u)));
  }
  L006743f6: { // 0x6743f6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006743f8: { // 0x6743f8: 7428 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L006743fa: { // 0x6743fa: 8a4c2424 MOV CL,byte ptr [ESP + 0x24]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000024u)));
  }
  L006743fe: { // 0x6743fe: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674400: { // 0x674400: 740c JZ 0x0067440e
    if(integer::condition("JZ",flags)) goto L0067440e;
  }
  L00674402: { // 0x674402: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674403: { // 0x674403: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674404: { // 0x674404: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674405: { // 0x674405: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674407: { // 0x674407: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674408: { // 0x674408: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067440b: { // 0x67440b: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067440e: { // 0x67440e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674410: { // 0x674410: 7504 JNZ 0x00674416
    if(integer::condition("JNZ",flags)) goto L00674416;
  }
  L00674412: { // 0x674412: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00674414: { // 0x674414: 740c JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L00674416: { // 0x674416: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674417: { // 0x674417: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674418: { // 0x674418: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674419: { // 0x674419: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0067441b: { // 0x67441b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067441c: { // 0x67441c: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067441f: { // 0x67441f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00674422: { // 0x674422: 8b875c050000 MOV EAX,dword ptr [EDI + 0x55c]
    s.ax = m.r32((s.di+0x0000055cu));
  }
  L00674428: { // 0x674428: 8b8d5c050000 MOV ECX,dword ptr [EBP + 0x55c]
    s.cx = m.r32((s.bp+0x0000055cu));
  }
  L0067442e: { // 0x67442e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00674430: { // 0x674430: 7d0c JGE 0x0067443e
    if(integer::condition("JGE",flags)) goto L0067443e;
  }
  L00674432: { // 0x674432: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674433: { // 0x674433: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674434: { // 0x674434: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674435: { // 0x674435: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674437: { // 0x674437: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674438: { // 0x674438: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067443b: { // 0x67443b: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067443e: { // 0x67443e: 7e0c JLE 0x0067444c
    if(integer::condition("JLE",flags)) goto L0067444c;
  }
  L00674440: { // 0x674440: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674441: { // 0x674441: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674442: { // 0x674442: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674443: { // 0x674443: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674445: { // 0x674445: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674446: { // 0x674446: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674449: { // 0x674449: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067444c: { // 0x67444c: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00674451: { // 0x674451: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00674453: { // 0x674453: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674454: { // 0x674454: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00674456: { // 0x674456: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6767708u); flags=s.arithmetic_flags;
  }
  L0067445c: { // 0x67445c: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0067445f: { // 0x67445f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00674461: { // 0x674461: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00674466: { // 0x674466: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00674468: { // 0x674468: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674469: { // 0x674469: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6767727u); flags=s.arithmetic_flags;
  }
  L0067446f: { // 0x67446f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00674471: { // 0x674471: 7d0c JGE 0x0067447f
    if(integer::condition("JGE",flags)) goto L0067447f;
  }
  L00674473: { // 0x674473: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674474: { // 0x674474: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674475: { // 0x674475: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674476: { // 0x674476: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674478: { // 0x674478: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674479: { // 0x674479: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067447c: { // 0x67447c: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067447f: { // 0x67447f: 7e0c JLE 0x0067448d
    if(integer::condition("JLE",flags)) goto L0067448d;
  }
  L00674481: { // 0x674481: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674482: { // 0x674482: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674483: { // 0x674483: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674484: { // 0x674484: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674486: { // 0x674486: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674487: { // 0x674487: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067448a: { // 0x67448a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067448d: { // 0x67448d: 8b4760 MOV EAX,dword ptr [EDI + 0x60]
    s.ax = m.r32((s.di+0x00000060u));
  }
  L00674490: { // 0x674490: 8b4d60 MOV ECX,dword ptr [EBP + 0x60]
    s.cx = m.r32((s.bp+0x00000060u));
  }
  L00674493: { // 0x674493: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00674494: { // 0x674494: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674495: { // 0x674495: e879ac0f00 CALL 0x0076f113
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f113u,6767770u); flags=s.arithmetic_flags;
  }
  L0067449a: { // 0x67449a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0067449d: { // 0x67449d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0067449f: { // 0x67449f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006744a0: { // 0x6744a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006744a1: { // 0x6744a1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006744a2: { // 0x6744a2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006744a3: { // 0x6744a3: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L006744a6: { // 0x6744a6: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006744a9: { // 0x6744a9: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006744b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,60> table{0xb7,0x29,0x48,0x0,0xd3,0x29,0x48,0x0,0xc0,0x29,0x48,0x0,0xca,0x29,0x48,0x0,0xdd,0x29,0x48,0x0,0x0,0x1,0x1,0x4,0x4,0x2,0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x3,0x3,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x0};leaf::Memory ro(table.data(),0x4829e0,60);m.add(ro);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006744b0: { // 0x6744b0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006744b3: { // 0x6744b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006744b4: { // 0x6744b4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006744b6: { // 0x6744b6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006744b7: { // 0x6744b7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L006744b9: { // 0x6744b9: 8b5350 MOV EDX,dword ptr [EBX + 0x50]
    s.dx = m.r32((s.bx+0x00000050u));
  }
  L006744bc: { // 0x6744bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006744bd: { // 0x6744bd: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006744be: { // 0x6744be: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006744bf: { // 0x6744bf: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006744c1: { // 0x6744c1: 895350 MOV dword ptr [EBX + 0x50],EDX
    m.w32((s.bx+0x00000050u), s.dx);
  }
  L006744c4: { // 0x6744c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006744c6: { // 0x6744c6: 0f8eaf000000 JLE 0x0067457b
    if(integer::condition("JLE",flags)) goto L0067457b;
  }
  L006744cc: { // 0x6744cc: 8d7354 LEA ESI,[EBX + 0x54]
    s.si = (s.bx+0x00000054u);
  }
  L006744cf: { // 0x6744cf: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L006744d1: { // 0x6744d1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L006744d4: { // 0x6744d4: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L006744d8: { // 0x6744d8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006744d9: { // 0x6744d9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006744da: { // 0x6744da: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L006744de: { // 0x6744de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006744df: { // 0x6744df: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006744e0: { // 0x6744e0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006744e2: { // 0x6744e2: e8d9fcffff CALL 0x006741c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006741c0u,6767847u); flags=s.arithmetic_flags;
  }
  L006744e7: { // 0x6744e7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006744e9: { // 0x6744e9: 7515 JNZ 0x00674500
    if(integer::condition("JNZ",flags)) goto L00674500;
  }
  L006744eb: { // 0x6744eb: 8b4350 MOV EAX,dword ptr [EBX + 0x50]
    s.ax = m.r32((s.bx+0x00000050u));
  }
  L006744ee: { // 0x6744ee: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L006744ef: { // 0x6744ef: 83c630 ADD ESI,0x30
    s.si = integer::add(s.si,0x00000030u,32,flags);
  }
  L006744f2: { // 0x6744f2: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L006744f4: { // 0x6744f4: 7cd9 JL 0x006744cf
    if(integer::condition("JL",flags)) goto L006744cf;
  }
  L006744f6: { // 0x6744f6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006744f7: { // 0x6744f7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006744f8: { // 0x6744f8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006744f9: { // 0x6744f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006744fa: { // 0x6744fa: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006744fd: { // 0x6744fd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00674500: { // 0x674500: 8b4350 MOV EAX,dword ptr [EBX + 0x50]
    s.ax = m.r32((s.bx+0x00000050u));
  }
  L00674503: { // 0x674503: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00674504: { // 0x674504: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00674506: { // 0x674506: 7e21 JLE 0x00674529
    if(integer::condition("JLE",flags)) goto L00674529;
  }
  L00674508: { // 0x674508: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L0067450b: { // 0x67450b: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0067450e: { // 0x67450e: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00674510: { // 0x674510: 8d7c1954 LEA EDI,[ECX + EBX*0x1 + 0x54]
    s.di = (s.cx+(s.bx * 0x00000001u)+0x00000054u);
  }
  L00674514: { // 0x674514: 8d57d0 LEA EDX,[EDI + -0x30]
    s.dx = (s.di-0x00000030u);
  }
  L00674517: { // 0x674517: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0067451c: { // 0x67451c: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0067451e: { // 0x67451e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0067451f: { // 0x67451f: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00674521: { // 0x674521: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00674523: { // 0x674523: 75ef JNZ 0x00674514
    if(integer::condition("JNZ",flags)) goto L00674514;
  }
  L00674525: { // 0x674525: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00674529: { // 0x674529: 8d546d00 LEA EDX,[EBP + EBP*0x2]
    s.dx = (s.bp+(s.bp * 0x00000002u));
  }
  L0067452d: { // 0x67452d: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L00674530: { // 0x674530: 83ff07 CMP EDI,0x7
    (void)integer::sub(s.di,0x00000007u,32,flags);
  }
  L00674533: { // 0x674533: 8d341a LEA ESI,[EDX + EBX*0x1]
    s.si = (s.dx+(s.bx * 0x00000001u));
  }
  L00674536: { // 0x674536: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0067453a: { // 0x67453a: 897e58 MOV dword ptr [ESI + 0x58],EDI
    m.w32((s.si+0x00000058u), s.di);
  }
  L0067453d: { // 0x67453d: 895654 MOV dword ptr [ESI + 0x54],EDX
    m.w32((s.si+0x00000054u), s.dx);
  }
  L00674540: { // 0x674540: 750a JNZ 0x0067454c
    if(integer::condition("JNZ",flags)) goto L0067454c;
  }
  L00674542: { // 0x674542: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00674544: { // 0x674544: e82765e7ff CALL 0x004eaa70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eaa70u,6767945u); flags=s.arithmetic_flags;
  }
  L00674549: { // 0x674549: 89465c MOV dword ptr [ESI + 0x5c],EAX
    m.w32((s.si+0x0000005cu), s.ax);
  }
  L0067454c: { // 0x67454c: 8d446d06 LEA EAX,[EBP + EBP*0x2 + 0x6]
    s.ax = (s.bp+(s.bp * 0x00000002u)+0x00000006u);
  }
  L00674550: { // 0x674550: 8d566c LEA EDX,[ESI + 0x6c]
    s.dx = (s.si+0x0000006cu);
  }
  L00674553: { // 0x674553: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00674556: { // 0x674556: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00674558: { // 0x674558: 890c18 MOV dword ptr [EAX + EBX*0x1],ECX
    m.w32((s.ax+(s.bx * 0x00000001u)), s.cx);
  }
  L0067455b: { // 0x67455b: 894e64 MOV dword ptr [ESI + 0x64],ECX
    m.w32((s.si+0x00000064u), s.cx);
  }
  L0067455e: { // 0x67455e: 894e68 MOV dword ptr [ESI + 0x68],ECX
    m.w32((s.si+0x00000068u), s.cx);
  }
  L00674561: { // 0x674561: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00674566: { // 0x674566: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L00674568: { // 0x674568: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0067456c: { // 0x67456c: 894e78 MOV dword ptr [ESI + 0x78],ECX
    m.w32((s.si+0x00000078u), s.cx);
  }
  L0067456f: { // 0x67456f: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L00674572: { // 0x674572: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00674575: { // 0x674575: 898e80000000 MOV dword ptr [ESI + 0x80],ECX
    m.w32((s.si+0x00000080u), s.cx);
  }
  L0067457b: { // 0x67457b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067457c: { // 0x67457c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067457d: { // 0x67457d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0067457e: { // 0x67457e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067457f: { // 0x67457f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674582: { // 0x674582: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
