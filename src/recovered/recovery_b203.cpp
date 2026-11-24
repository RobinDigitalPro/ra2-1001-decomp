#include "recovered/recovery_b203_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b203 {
namespace {
void f_00137710(Memory&,State&,Frame&,const Operations&);
void f_001377a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00137710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00537710: { // 0x537710: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00537713: { // 0x537713: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00537714: { // 0x537714: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00537715: { // 0x537715: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00537716: { // 0x537716: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00537718: { // 0x537718: 744f JZ 0x00537769
    if(integer::condition("JZ",flags)) goto L00537769;
  }
  L0053771a: { // 0x53771a: 0588000000 ADD EAX,0x88
    s.ax = integer::add(s.ax,0x00000088u,32,flags);
  }
  L0053771f: { // 0x53771f: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00537721: { // 0x537721: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L00537724: { // 0x537724: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00537727: { // 0x537727: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0053772a: { // 0x53772a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0053772b: { // 0x53772b: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0053772e: { // 0x53772e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00537730: { // 0x537730: 3b10 CMP EDX,dword ptr [EAX]
    (void)integer::sub(s.dx,m.r32((s.ax)),32,flags);
  }
  L00537732: { // 0x537732: 750a JNZ 0x0053773e
    if(integer::condition("JNZ",flags)) goto L0053773e;
  }
  L00537734: { // 0x537734: 3b7004 CMP ESI,dword ptr [EAX + 0x4]
    (void)integer::sub(s.si,m.r32((s.ax+0x00000004u)),32,flags);
  }
  L00537737: { // 0x537737: 7505 JNZ 0x0053773e
    if(integer::condition("JNZ",flags)) goto L0053773e;
  }
  L00537739: { // 0x537739: 3b7808 CMP EDI,dword ptr [EAX + 0x8]
    (void)integer::sub(s.di,m.r32((s.ax+0x00000008u)),32,flags);
  }
  L0053773c: { // 0x53773c: 742b JZ 0x00537769
    if(integer::condition("JZ",flags)) goto L00537769;
  }
  L0053773e: { // 0x53773e: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00537741: { // 0x537741: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00537742: { // 0x537742: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L00537745: { // 0x537745: 7907 JNS 0x0053774e
    if(integer::condition("JNS",flags)) goto L0053774e;
  }
  L00537747: { // 0x537747: c7410c1f000000 MOV dword ptr [ECX + 0xc],0x1f
    m.w32((s.cx+0x0000000cu), 0x0000001fu);
  }
  L0053774e: { // 0x53774e: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00537751: { // 0x537751: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00537752: { // 0x537752: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00537755: { // 0x537755: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00537757: { // 0x537757: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00537759: { // 0x537759: c7400cff000000 MOV dword ptr [EAX + 0xc],0xff
    m.w32((s.ax+0x0000000cu), 0x000000ffu);
  }
  L00537760: { // 0x537760: 895500 MOV dword ptr [EBP],EDX
    m.w32((s.bp), s.dx);
  }
  L00537763: { // 0x537763: 897504 MOV dword ptr [EBP + 0x4],ESI
    m.w32((s.bp+0x00000004u), s.si);
  }
  L00537766: { // 0x537766: 897d08 MOV dword ptr [EBP + 0x8],EDI
    m.w32((s.bp+0x00000008u), s.di);
  }
  L00537769: { // 0x537769: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0053776c: { // 0x53776c: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L0053776f: { // 0x53776f: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00537772: { // 0x537772: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00537774: { // 0x537774: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00537777: { // 0x537777: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00537779: { // 0x537779: 8b780c MOV EDI,dword ptr [EAX + 0xc]
    s.di = m.r32((s.ax+0x0000000cu));
  }
  L0053777c: { // 0x53777c: 2bfe SUB EDI,ESI
    s.di = integer::sub(s.di,s.si,32,flags);
  }
  L0053777e: { // 0x53777e: 89780c MOV dword ptr [EAX + 0xc],EDI
    m.w32((s.ax+0x0000000cu), s.di);
  }
  L00537781: { // 0x537781: 7907 JNS 0x0053778a
    if(integer::condition("JNS",flags)) goto L0053778a;
  }
  L00537783: { // 0x537783: c7400c00000000 MOV dword ptr [EAX + 0xc],0x0
    m.w32((s.ax+0x0000000cu), 0x00000000u);
  }
  L0053778a: { // 0x53778a: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0053778c: { // 0x53778c: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  L0053778f: { // 0x53778f: 7c02 JL 0x00537793
    if(integer::condition("JL",flags)) goto L00537793;
  }
  L00537791: { // 0x537791: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00537793: { // 0x537793: 3b410c CMP EAX,dword ptr [ECX + 0xc]
    (void)integer::sub(s.ax,m.r32((s.cx+0x0000000cu)),32,flags);
  }
  L00537796: { // 0x537796: 75d4 JNZ 0x0053776c
    if(integer::condition("JNZ",flags)) goto L0053776c;
  }
  L00537798: { // 0x537798: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00537799: { // 0x537799: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053779a: { // 0x53779a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0053779b: { // 0x53779b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001377a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005377a0: { // 0x5377a0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005377a3: { // 0x5377a3: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L005377a6: { // 0x5377a6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005377a7: { // 0x5377a7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005377a8: { // 0x5377a8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005377a9: { // 0x5377a9: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L005377ab: { // 0x5377ab: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005377ac: { // 0x5377ac: 83fd20 CMP EBP,0x20
    (void)integer::sub(s.bp,0x00000020u,32,flags);
  }
  L005377af: { // 0x5377af: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005377b0: { // 0x5377b0: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005377b4: { // 0x5377b4: 7c02 JL 0x005377b8
    if(integer::condition("JL",flags)) goto L005377b8;
  }
  L005377b6: { // 0x5377b6: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005377b8: { // 0x5377b8: 8b357865a500 MOV ESI,dword ptr [0x00a56578]
    s.si = m.r32((0x00a56578u));
  }
  L005377be: { // 0x5377be: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L005377c1: { // 0x5377c1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005377c3: { // 0x5377c3: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005377c5: { // 0x5377c5: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L005377c7: { // 0x5377c7: 751e JNZ 0x005377e7
    if(integer::condition("JNZ",flags)) goto L005377e7;
  }
  L005377c9: { // 0x5377c9: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005377cc: { // 0x5377cc: 8b357c65a500 MOV ESI,dword ptr [0x00a5657c]
    s.si = m.r32((0x00a5657cu));
  }
  L005377d2: { // 0x5377d2: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L005377d4: { // 0x5377d4: 7511 JNZ 0x005377e7
    if(integer::condition("JNZ",flags)) goto L005377e7;
  }
  L005377d6: { // 0x5377d6: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L005377d9: { // 0x5377d9: 8b358065a500 MOV ESI,dword ptr [0x00a56580]
    s.si = m.r32((0x00a56580u));
  }
  L005377df: { // 0x5377df: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L005377e1: { // 0x5377e1: 0f84ca000000 JZ 0x005378b1
    if(integer::condition("JZ",flags)) goto L005378b1;
  }
  L005377e7: { // 0x5377e7: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L005377e8: { // 0x5377e8: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005377ea: { // 0x5377ea: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L005377ec: { // 0x5377ec: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L005377ef: { // 0x5377ef: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  L005377f2: { // 0x5377f2: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L005377f4: { // 0x5377f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005377f6: { // 0x5377f6: 0f84b5000000 JZ 0x005378b1
    if(integer::condition("JZ",flags)) goto L005378b1;
  }
  L005377fc: { // 0x5377fc: a17865a500 MOV EAX,[0x00a56578]
    s.ax = m.r32((0x00a56578u));
  }
  L00537801: { // 0x537801: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00537803: { // 0x537803: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00537805: { // 0x537805: 751e JNZ 0x00537825
    if(integer::condition("JNZ",flags)) goto L00537825;
  }
  L00537807: { // 0x537807: 8b0d7c65a500 MOV ECX,dword ptr [0x00a5657c]
    s.cx = m.r32((0x00a5657cu));
  }
  L0053780d: { // 0x53780d: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00537810: { // 0x537810: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00537812: { // 0x537812: 7511 JNZ 0x00537825
    if(integer::condition("JNZ",flags)) goto L00537825;
  }
  L00537814: { // 0x537814: 8b158065a500 MOV EDX,dword ptr [0x00a56580]
    s.dx = m.r32((0x00a56580u));
  }
  L0053781a: { // 0x53781a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0053781d: { // 0x53781d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0053781f: { // 0x53781f: 0f848c000000 JZ 0x005378b1
    if(integer::condition("JZ",flags)) goto L005378b1;
  }
  L00537825: { // 0x537825: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0053782b: { // 0x53782b: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0053782f: { // 0x53782f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00537830: { // 0x537830: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00537831: { // 0x537831: e8da071600 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,5470262u); flags=s.arithmetic_flags;
  }
  L00537836: { // 0x537836: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0053783a: { // 0x53783a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0053783b: { // 0x53783b: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00537841: { // 0x537841: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00537842: { // 0x537842: e8c9071600 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,5470279u); flags=s.arithmetic_flags;
  }
  L00537847: { // 0x537847: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L0053784a: { // 0x53784a: e861071600 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5470287u); flags=s.arithmetic_flags;
  }
  L0053784f: { // 0x53784f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00537852: { // 0x537852: bbfeffffff MOV EBX,0xfffffffe
    s.bx = 0xfffffffeu;
  }
  L00537857: { // 0x537857: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00537859: { // 0x537859: e852071600 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5470302u); flags=s.arithmetic_flags;
  }
  L0053785e: { // 0x53785e: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00537861: { // 0x537861: b9feffffff MOV ECX,0xfffffffe
    s.cx = 0xfffffffeu;
  }
  L00537866: { // 0x537866: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00537868: { // 0x537868: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0053786c: { // 0x53786c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0053786d: { // 0x53786d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0053786e: { // 0x53786e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00537872: { // 0x537872: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00537873: { // 0x537873: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00537874: { // 0x537874: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00537878: { // 0x537878: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00537879: { // 0x537879: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0053787a: { // 0x53787a: 8b0da41c8200 MOV ECX,dword ptr [0x00821ca4]
    s.cx = m.r32((0x00821ca4u));
  }
  L00537880: { // 0x537880: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L00537885: { // 0x537885: e8466ef7ff CALL 0x004ae6d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ae6d0u,5470346u); flags=s.arithmetic_flags;
  }
  L0053788a: { // 0x53788a: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0053788c: { // 0x53788c: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  L0053788f: { // 0x53788f: 7c02 JL 0x00537893
    if(integer::condition("JL",flags)) goto L00537893;
  }
  L00537891: { // 0x537891: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00537893: { // 0x537893: 3b430c CMP EAX,dword ptr [EBX + 0xc]
    (void)integer::sub(s.ax,m.r32((s.bx+0x0000000cu)),32,flags);
  }
  L00537896: { // 0x537896: 7419 JZ 0x005378b1
    if(integer::condition("JZ",flags)) goto L005378b1;
  }
  L00537898: { // 0x537898: 8d6801 LEA EBP,[EAX + 0x1]
    s.bp = (s.ax+0x00000001u);
  }
  L0053789b: { // 0x53789b: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0053789d: { // 0x53789d: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L0053789f: { // 0x53789f: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L005378a2: { // 0x5378a2: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L005378a5: { // 0x5378a5: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L005378a7: { // 0x5378a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005378a9: { // 0x5378a9: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L005378ab: { // 0x5378ab: 0f854bffffff JNZ 0x005377fc
    if(integer::condition("JNZ",flags)) goto L005377fc;
  }
  L005378b1: { // 0x5378b1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005378b2: { // 0x5378b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005378b3: { // 0x5378b3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005378b4: { // 0x5378b4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005378b5: { // 0x5378b5: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005378b8: { // 0x5378b8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5469968u:f_00137710(m,s,child,{});break;
case 5470112u:f_001377a0(m,s,child,{});break;
default:throw std::domain_error("recovery203 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005378e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005378e0: { // 0x5378e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005378e1: { // 0x5378e1: a1b065a500 MOV EAX,[0x00a565b0]
    s.ax = m.r32((0x00a565b0u));
  }
  L005378e6: { // 0x5378e6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005378e7: { // 0x5378e7: 8d78ff LEA EDI,[EAX + -0x1]
    s.di = (s.ax-0x00000001u);
  }
  L005378ea: { // 0x5378ea: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005378ec: { // 0x5378ec: 0f8c8d000000 JL 0x0053797f
    if(integer::condition("JL",flags)) goto L0053797f;
  }
  L005378f2: { // 0x5378f2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005378f3: { // 0x5378f3: 8b0da465a500 MOV ECX,dword ptr [0x00a565a4]
    s.cx = m.r32((0x00a565a4u));
  }
  L005378f9: { // 0x5378f9: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L005378fc: { // 0x5378fc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005378fe: { // 0x5378fe: e80dfeffff CALL 0x00537710
    s.arithmetic_flags=flags; invoke(m,s,f,0x00537710u,5470467u); flags=s.arithmetic_flags;
  }
  L00537903: { // 0x537903: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00537906: { // 0x537906: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00537908: { // 0x537908: 7566 JNZ 0x00537970
    if(integer::condition("JNZ",flags)) goto L00537970;
  }
  L0053790a: { // 0x53790a: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L0053790d: { // 0x53790d: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L00537910: { // 0x537910: 8b44321c MOV EAX,dword ptr [EDX + ESI*0x1 + 0x1c]
    s.ax = m.r32((s.dx+(s.si * 0x00000001u)+0x0000001cu));
  }
  L00537914: { // 0x537914: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00537916: { // 0x537916: 7558 JNZ 0x00537970
    if(integer::condition("JNZ",flags)) goto L00537970;
  }
  L00537918: { // 0x537918: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0053791a: { // 0x53791a: 745b JZ 0x00537977
    if(integer::condition("JZ",flags)) goto L00537977;
  }
  L0053791c: { // 0x53791c: 8b15a065a500 MOV EDX,dword ptr [0x00a565a0]
    s.dx = m.r32((0x00a565a0u));
  }
  L00537922: { // 0x537922: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L00537926: { // 0x537926: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00537927: { // 0x537927: b9a065a500 MOV ECX,0xa565a0
    s.cx = 0x00a565a0u;
  }
  L0053792c: { // 0x53792c: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L00537930: { // 0x537930: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5470515u); flags=s.arithmetic_flags;
  }
  L00537933: { // 0x537933: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00537936: { // 0x537936: 742d JZ 0x00537965
    if(integer::condition("JZ",flags)) goto L00537965;
  }
  L00537938: { // 0x537938: 8b0db065a500 MOV ECX,dword ptr [0x00a565b0]
    s.cx = m.r32((0x00a565b0u));
  }
  L0053793e: { // 0x53793e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00537940: { // 0x537940: 7d23 JGE 0x00537965
    if(integer::condition("JGE",flags)) goto L00537965;
  }
  L00537942: { // 0x537942: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00537943: { // 0x537943: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00537945: { // 0x537945: 890db065a500 MOV dword ptr [0x00a565b0],ECX
    m.w32((0x00a565b0u), s.cx);
  }
  L0053794b: { // 0x53794b: 7d18 JGE 0x00537965
    if(integer::condition("JGE",flags)) goto L00537965;
  }
  L0053794d: { // 0x53794d: 8b0da465a500 MOV ECX,dword ptr [0x00a565a4]
    s.cx = m.r32((0x00a565a4u));
  }
  L00537953: { // 0x537953: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00537954: { // 0x537954: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00537957: { // 0x537957: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0053795b: { // 0x53795b: 8b0db065a500 MOV ECX,dword ptr [0x00a565b0]
    s.cx = m.r32((0x00a565b0u));
  }
  L00537961: { // 0x537961: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00537963: { // 0x537963: 7ce8 JL 0x0053794d
    if(integer::condition("JL",flags)) goto L0053794d;
  }
  L00537965: { // 0x537965: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00537966: { // 0x537966: e8105d2300 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5470571u); flags=s.arithmetic_flags;
  }
  L0053796b: { // 0x53796b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0053796e: { // 0x53796e: eb07 JMP 0x00537977
    goto L00537977;
  }
  L00537970: { // 0x537970: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00537972: { // 0x537972: e829feffff CALL 0x005377a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005377a0u,5470583u); flags=s.arithmetic_flags;
  }
  L00537977: { // 0x537977: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00537978: { // 0x537978: 0f8975ffffff JNS 0x005378f3
    if(integer::condition("JNS",flags)) goto L005378f3;
  }
  L0053797e: { // 0x53797e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053797f: { // 0x53797f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00537980: { // 0x537980: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00537981: { // 0x537981: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
