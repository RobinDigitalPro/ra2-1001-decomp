#include "recovered/recovery_b593_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b593 {
namespace {
void f_0030b250(Memory&,State&,Frame&,const Operations&);
void f_0030a9e0(Memory&,State&,Frame&,const Operations&);
void f_0030a760(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0030b250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0070b250: { // 0x70b250: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0070b252: { // 0x70b252: 7c1a JL 0x0070b26e
    if(integer::condition("JL",flags)) goto L0070b26e;
  }
  L0070b254: { // 0x70b254: 3b0dc083ab00 CMP ECX,dword ptr [0x00ab83c0]
    (void)integer::sub(s.cx,m.r32((0x00ab83c0u)),32,flags);
  }
  L0070b25a: { // 0x70b25a: 7d12 JGE 0x0070b26e
    if(integer::condition("JGE",flags)) goto L0070b26e;
  }
  L0070b25c: { // 0x70b25c: a1b483ab00 MOV EAX,[0x00ab83b4]
    s.ax = m.r32((0x00ab83b4u));
  }
  L0070b261: { // 0x70b261: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0070b264: { // 0x70b264: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0070b266: { // 0x70b266: 83794802 CMP dword ptr [ECX + 0x48],0x2
    (void)integer::sub(m.r32((s.cx+0x00000048u)),0x00000002u,32,flags);
  }
  L0070b26a: { // 0x70b26a: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0070b26d: { // 0x70b26d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0070b26e: { // 0x70b26e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0070b270: { // 0x70b270: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0030a9e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0070a9e0: { // 0x70a9e0: e87bfdffff CALL 0x0070a760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a760u,7383525u); flags=s.arithmetic_flags;
  }
  L0070a9e5: { // 0x70a9e5: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  L0070a9eb: { // 0x70a9eb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0070a9ed: { // 0x70a9ed: 743e JZ 0x0070aa2d
    if(integer::condition("JZ",flags)) goto L0070aa2d;
  }
  L0070a9ef: { // 0x70a9ef: e89cd5cfff CALL 0x00407f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407f90u,7383540u); flags=s.arithmetic_flags;
  }
  L0070a9f4: { // 0x70a9f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0070a9f6: { // 0x70a9f6: 7538 JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  L0070a9f8: { // 0x70a9f8: 813dec82ab00e882ab00 CMP dword ptr [0x00ab82ec],0xab82e8
    (void)integer::sub(m.r32((0x00ab82ecu)),0x00ab82e8u,32,flags);
  }
  L0070aa02: { // 0x70aa02: 752c JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  L0070aa04: { // 0x70aa04: 813d1483ab001083ab00 CMP dword ptr [0x00ab8314],0xab8310
    (void)integer::sub(m.r32((0x00ab8314u)),0x00ab8310u,32,flags);
  }
  L0070aa0e: { // 0x70aa0e: 7520 JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  L0070aa10: { // 0x70aa10: a1c883ab00 MOV EAX,[0x00ab83c8]
    s.ax = m.r32((0x00ab83c8u));
  }
  L0070aa15: { // 0x70aa15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0070aa17: { // 0x70aa17: 7517 JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  L0070aa19: { // 0x70aa19: b86083ab00 MOV EAX,0xab8360
    s.ax = 0x00ab8360u;
  }
  L0070aa1e: { // 0x70aa1e: 394004 CMP dword ptr [EAX + 0x4],EAX
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.ax,32,flags);
  }
  L0070aa21: { // 0x70aa21: 750d JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  L0070aa23: { // 0x70aa23: 83c00c ADD EAX,0xc
    s.ax = integer::add(s.ax,0x0000000cu,32,flags);
  }
  L0070aa26: { // 0x70aa26: 3d9083ab00 CMP EAX,0xab8390
    (void)integer::sub(s.ax,0x00ab8390u,32,flags);
  }
  L0070aa2b: { // 0x70aa2b: 72f1 JC 0x0070aa1e
    if(integer::condition("JC",flags)) goto L0070aa1e;
  }
  L0070aa2d: { // 0x70aa2d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0070aa2f: { // 0x70aa2f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0070aa30: { // 0x70aa30: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0070aa35: { // 0x70aa35: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0030a760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0070a760: { // 0x70a760: a04c89a200 MOV AL,[0x00a2894c]
    s.ax = with_al(s.ax, m.r8((0x00a2894cu)));
  }
  L0070a765: { // 0x70a765: 81ec08010000 SUB ESP,0x108
    f.sp = integer::sub(f.sp,0x00000108u,32,flags);
  }
  L0070a76b: { // 0x70a76b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0070a76c: { // 0x70a76c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0070a76e: { // 0x70a76e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0070a76f: { // 0x70a76f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0070a770: { // 0x70a770: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L0070a772: { // 0x70a772: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0070a773: { // 0x70a773: 0f850e020000 JNZ 0x0070a987
    if(integer::condition("JNZ",flags)) goto L0070a987;
  }
  L0070a779: { // 0x70a779: e8b2c7cfff CALL 0x00406f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00406f30u,7382910u); flags=s.arithmetic_flags;
  }
  L0070a77e: { // 0x70a77e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0070a780: { // 0x70a780: 0f8401020000 JZ 0x0070a987
    if(integer::condition("JZ",flags)) goto L0070a987;
  }
  L0070a786: { // 0x70a786: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  L0070a78c: { // 0x70a78c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0070a78e: { // 0x70a78e: 0f84f3010000 JZ 0x0070a987
    if(integer::condition("JZ",flags)) goto L0070a987;
  }
  L0070a794: { // 0x70a794: e8f7d7cfff CALL 0x00407f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407f90u,7382937u); flags=s.arithmetic_flags;
  }
  L0070a799: { // 0x70a799: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0070a79b: { // 0x70a79b: 0f85e6010000 JNZ 0x0070a987
    if(integer::condition("JNZ",flags)) goto L0070a987;
  }
  L0070a7a1: { // 0x70a7a1: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  L0070a7a7: { // 0x70a7a7: e8b4d8cfff CALL 0x00408060
    s.arithmetic_flags=flags; invoke(m,s,f,0x00408060u,7382956u); flags=s.arithmetic_flags;
  }
  L0070a7ac: { // 0x70a7ac: 8b35e083ab00 MOV ESI,dword ptr [0x00ab83e0]
    s.si = m.r32((0x00ab83e0u));
  }
  L0070a7b2: { // 0x70a7b2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0070a7b4: { // 0x70a7b4: 03fe ADD EDI,ESI
    s.di = integer::add(s.di,s.si,32,flags);
  }
  L0070a7b6: { // 0x70a7b6: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0070a7b8: { // 0x70a7b8: 1335e483ab00 ADC ESI,dword ptr [0x00ab83e4]
    s.si = integer::add(s.si,m.r32((0x00ab83e4u)),32,flags,flags&integer::CF);
  }
  L0070a7be: { // 0x70a7be: e80debcfff CALL 0x004092d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004092d0u,7382979u); flags=s.arithmetic_flags;
  }
  L0070a7c3: { // 0x70a7c3: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0070a7c5: { // 0x70a7c5: 0f82bc010000 JC 0x0070a987
    if(integer::condition("JC",flags)) goto L0070a987;
  }
  L0070a7cb: { // 0x70a7cb: 7708 JA 0x0070a7d5
    if(integer::condition("JA",flags)) goto L0070a7d5;
  }
  L0070a7cd: { // 0x70a7cd: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0070a7cf: { // 0x70a7cf: 0f86b2010000 JBE 0x0070a987
    if(integer::condition("JBE",flags)) goto L0070a987;
  }
  L0070a7d5: { // 0x70a7d5: a14883ab00 MOV EAX,[0x00ab8348]
    s.ax = m.r32((0x00ab8348u));
  }
  L0070a7da: { // 0x70a7da: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0070a7dc: { // 0x70a7dc: 0f85a5010000 JNZ 0x0070a987
    if(integer::condition("JNZ",flags)) goto L0070a987;
  }
  L0070a7e2: { // 0x70a7e2: a1d483ab00 MOV EAX,[0x00ab83d4]
    s.ax = m.r32((0x00ab83d4u));
  }
  L0070a7e7: { // 0x70a7e7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0070a7e9: { // 0x70a7e9: 740d JZ 0x0070a7f8
    if(integer::condition("JZ",flags)) goto L0070a7f8;
  }
  L0070a7eb: { // 0x70a7eb: c7404802000000 MOV dword ptr [EAX + 0x48],0x2
    m.w32((s.ax+0x00000048u), 0x00000002u);
  }
  L0070a7f2: { // 0x70a7f2: 891dd483ab00 MOV dword ptr [0x00ab83d4],EBX
    m.w32((0x00ab83d4u), s.bx);
  }
  L0070a7f8: { // 0x70a7f8: b9e882ab00 MOV ECX,0xab82e8
    s.cx = 0x00ab82e8u;
  }
  L0070a7fd: { // 0x70a7fd: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0070a801: { // 0x70a801: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0070a805: { // 0x70a805: e8e6cacfff CALL 0x004072f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004072f0u,7383050u); flags=s.arithmetic_flags;
  }
  L0070a80a: { // 0x70a80a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0070a80c: { // 0x70a80c: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0070a80e: { // 0x70a80e: 7425 JZ 0x0070a835
    if(integer::condition("JZ",flags)) goto L0070a835;
  }
  L0070a810: { // 0x70a810: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0070a812: { // 0x70a812: e869cbcfff CALL 0x00407380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407380u,7383063u); flags=s.arithmetic_flags;
  }
  L0070a817: { // 0x70a817: a1c883ab00 MOV EAX,[0x00ab83c8]
    s.ax = m.r32((0x00ab83c8u));
  }
  L0070a81c: { // 0x70a81c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0070a81e: { // 0x70a81e: 0f8483000000 JZ 0x0070a8a7
    if(integer::condition("JZ",flags)) goto L0070a8a7;
  }
  L0070a824: { // 0x70a824: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0070a825: { // 0x70a825: e8512e0600 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7383082u); flags=s.arithmetic_flags;
  }
  L0070a82a: { // 0x70a82a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0070a82d: { // 0x70a82d: 891dc883ab00 MOV dword ptr [0x00ab83c8],EBX
    m.w32((0x00ab83c8u), s.bx);
  }
  L0070a833: { // 0x70a833: eb72 JMP 0x0070a8a7
    goto L0070a8a7;
  }
  L0070a835: { // 0x70a835: b91083ab00 MOV ECX,0xab8310
    s.cx = 0x00ab8310u;
  }
  L0070a83a: { // 0x70a83a: e8b1cacfff CALL 0x004072f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004072f0u,7383103u); flags=s.arithmetic_flags;
  }
  L0070a83f: { // 0x70a83f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0070a841: { // 0x70a841: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0070a843: { // 0x70a843: 7421 JZ 0x0070a866
    if(integer::condition("JZ",flags)) goto L0070a866;
  }
  L0070a845: { // 0x70a845: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0070a847: { // 0x70a847: e834cbcfff CALL 0x00407380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407380u,7383116u); flags=s.arithmetic_flags;
  }
  L0070a84c: { // 0x70a84c: a1c883ab00 MOV EAX,[0x00ab83c8]
    s.ax = m.r32((0x00ab83c8u));
  }
  L0070a851: { // 0x70a851: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0070a853: { // 0x70a853: 7452 JZ 0x0070a8a7
    if(integer::condition("JZ",flags)) goto L0070a8a7;
  }
  L0070a855: { // 0x70a855: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0070a856: { // 0x70a856: e8202e0600 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7383131u); flags=s.arithmetic_flags;
  }
  L0070a85b: { // 0x70a85b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0070a85e: { // 0x70a85e: 891dc883ab00 MOV dword ptr [0x00ab83c8],EBX
    m.w32((0x00ab83c8u), s.bx);
  }
  L0070a864: { // 0x70a864: eb41 JMP 0x0070a8a7
    goto L0070a8a7;
  }
  L0070a866: { // 0x70a866: 8b35c883ab00 MOV ESI,dword ptr [0x00ab83c8]
    s.si = m.r32((0x00ab83c8u));
  }
  L0070a86c: { // 0x70a86c: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0070a86e: { // 0x70a86e: 7408 JZ 0x0070a878
    if(integer::condition("JZ",flags)) goto L0070a878;
  }
  L0070a870: { // 0x70a870: 891dc883ab00 MOV dword ptr [0x00ab83c8],EBX
    m.w32((0x00ab83c8u), s.bx);
  }
  L0070a876: { // 0x70a876: eb2f JMP 0x0070a8a7
    goto L0070a8a7;
  }
  L0070a878: { // 0x70a878: bf8483ab00 MOV EDI,0xab8384
    s.di = 0x00ab8384u;
  }
  L0070a87d: { // 0x70a87d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0070a87f: { // 0x70a87f: e86ccacfff CALL 0x004072f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004072f0u,7383172u); flags=s.arithmetic_flags;
  }
  L0070a884: { // 0x70a884: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0070a886: { // 0x70a886: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0070a888: { // 0x70a888: 7516 JNZ 0x0070a8a0
    if(integer::condition("JNZ",flags)) goto L0070a8a0;
  }
  L0070a88a: { // 0x70a88a: 83ef0c SUB EDI,0xc
    s.di = integer::sub(s.di,0x0000000cu,32,flags);
  }
  L0070a88d: { // 0x70a88d: 81ff6083ab00 CMP EDI,0xab8360
    (void)integer::sub(s.di,0x00ab8360u,32,flags);
  }
  L0070a893: { // 0x70a893: 7de8 JGE 0x0070a87d
    if(integer::condition("JGE",flags)) goto L0070a87d;
  }
  L0070a895: { // 0x70a895: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0070a896: { // 0x70a896: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0070a897: { // 0x70a897: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0070a898: { // 0x70a898: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0070a899: { // 0x70a899: 81c408010000 ADD ESP,0x108
    f.sp = integer::add(f.sp,0x00000108u,32,flags);
  }
  L0070a89f: { // 0x70a89f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0070a8a0: { // 0x70a8a0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0070a8a2: { // 0x70a8a2: e8d9cacfff CALL 0x00407380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407380u,7383207u); flags=s.arithmetic_flags;
  }
  L0070a8a7: { // 0x70a8a7: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0070a8a9: { // 0x70a8a9: 0f84d8000000 JZ 0x0070a987
    if(integer::condition("JZ",flags)) goto L0070a987;
  }
  L0070a8af: { // 0x70a8af: 8b6e0c MOV EBP,dword ptr [ESI + 0xc]
    s.bp = m.r32((s.si+0x0000000cu));
  }
  L0070a8b2: { // 0x70a8b2: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0070a8b6: { // 0x70a8b6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0070a8b8: { // 0x70a8b8: 7407 JZ 0x0070a8c1
    if(integer::condition("JZ",flags)) goto L0070a8c1;
  }
  L0070a8ba: { // 0x70a8ba: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L0070a8bd: { // 0x70a8bd: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0070a8c1: { // 0x70a8c1: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0070a8c5: { // 0x70a8c5: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0070a8c7: { // 0x70a8c7: 7407 JZ 0x0070a8d0
    if(integer::condition("JZ",flags)) goto L0070a8d0;
  }
  L0070a8c9: { // 0x70a8c9: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L0070a8cc: { // 0x70a8cc: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0070a8d0: { // 0x70a8d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0070a8d1: { // 0x70a8d1: e8a52d0600 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7383254u); flags=s.arithmetic_flags;
  }
  L0070a8d6: { // 0x70a8d6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0070a8d9: { // 0x70a8d9: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0070a8db: { // 0x70a8db: 0f84a6000000 JZ 0x0070a987
    if(integer::condition("JZ",flags)) goto L0070a987;
  }
  L0070a8e1: { // 0x70a8e1: c7454802000000 MOV dword ptr [EBP + 0x48],0x2
    m.w32((s.bp+0x00000048u), 0x00000002u);
  }
  L0070a8e8: { // 0x70a8e8: a1d883ab00 MOV EAX,[0x00ab83d8]
    s.ax = m.r32((0x00ab83d8u));
  }
  L0070a8ed: { // 0x70a8ed: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0070a8ef: { // 0x70a8ef: 8d7d35 LEA EDI,[EBP + 0x35]
    s.di = (s.bp+0x00000035u);
  }
  L0070a8f2: { // 0x70a8f2: 7403 JZ 0x0070a8f7
    if(integer::condition("JZ",flags)) goto L0070a8f7;
  }
  L0070a8f4: { // 0x70a8f4: 8d7d2c LEA EDI,[EBP + 0x2c]
    s.di = (s.bp+0x0000002cu);
  }
  L0070a8f7: { // 0x70a8f7: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0070a8fa: { // 0x70a8fa: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0070a8fc: { // 0x70a8fc: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0070a8fe: { // 0x70a8fe: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L0070a900: { // 0x70a900: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L0070a902: { // 0x70a902: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0070a906: { // 0x70a906: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0070a908: { // 0x70a908: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0070a90a: { // 0x70a90a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0070a90c: { // 0x70a90c: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0070a910: { // 0x70a910: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0070a913: { // 0x70a913: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0070a915: { // 0x70a915: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0070a917: { // 0x70a917: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0070a919: { // 0x70a919: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0070a91c: { // 0x70a91c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0070a91e: { // 0x70a91e: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L0070a920: { // 0x70a920: bfb01b7e00 MOV EDI,0x7e1bb0
    s.di = 0x007e1bb0u;
  }
  L0070a925: { // 0x70a925: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0070a928: { // 0x70a928: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0070a92a: { // 0x70a92a: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L0070a92c: { // 0x70a92c: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L0070a92e: { // 0x70a92e: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0070a930: { // 0x70a930: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0070a932: { // 0x70a932: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0070a934: { // 0x70a934: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0070a937: { // 0x70a937: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0070a939: { // 0x70a939: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0070a93b: { // 0x70a93b: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0070a93c: { // 0x70a93c: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0070a93f: { // 0x70a93f: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0070a941: { // 0x70a941: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0070a943: { // 0x70a943: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0070a947: { // 0x70a947: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0070a94a: { // 0x70a94a: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L0070a94c: { // 0x70a94c: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  L0070a952: { // 0x70a952: e839d1cfff CALL 0x00407a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407a90u,7383383u); flags=s.arithmetic_flags;
  }
  L0070a957: { // 0x70a957: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0070a959: { // 0x70a959: 742c JZ 0x0070a987
    if(integer::condition("JZ",flags)) goto L0070a987;
  }
  L0070a95b: { // 0x70a95b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0070a95f: { // 0x70a95f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0070a963: { // 0x70a963: c705e083ab00f4010000 MOV dword ptr [0x00ab83e0],0x1f4
    m.w32((0x00ab83e0u), 0x000001f4u);
  }
  L0070a96d: { // 0x70a96d: 891de483ab00 MOV dword ptr [0x00ab83e4],EBX
    m.w32((0x00ab83e4u), s.bx);
  }
  L0070a973: { // 0x70a973: 892dd483ab00 MOV dword ptr [0x00ab83d4],EBP
    m.w32((0x00ab83d4u), s.bp);
  }
  L0070a979: { // 0x70a979: a3d882ab00 MOV [0x00ab82d8],EAX
    m.w32((0x00ab82d8u), s.ax);
  }
  L0070a97e: { // 0x70a97e: 890d0083ab00 MOV dword ptr [0x00ab8300],ECX
    m.w32((0x00ab8300u), s.cx);
  }
  L0070a984: { // 0x70a984: 895d48 MOV dword ptr [EBP + 0x48],EBX
    m.w32((s.bp+0x00000048u), s.bx);
  }
  L0070a987: { // 0x70a987: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0070a988: { // 0x70a988: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0070a989: { // 0x70a989: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0070a98a: { // 0x70a98a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0070a98b: { // 0x70a98b: 81c408010000 ADD ESP,0x108
    f.sp = integer::add(f.sp,0x00000108u,32,flags);
  }
  L0070a991: { // 0x70a991: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7385680u:f_0030b250(m,s,child,{});break;
case 7383520u:f_0030a9e0(m,s,child,{});break;
case 7382880u:f_0030a760(m,s,child,{});break;
default:throw std::domain_error("recovery593 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0062b2c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062b2c0: { // 0x62b2c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062b2c1: { // 0x62b2c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0062b2c3: { // 0x62b2c3: 8b86b4140000 MOV EAX,dword ptr [ESI + 0x14b4]
    s.ax = m.r32((s.si+0x000014b4u));
  }
  L0062b2c9: { // 0x62b2c9: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  L0062b2cc: { // 0x62b2cc: 0f84aa000000 JZ 0x0062b37c
    if(integer::condition("JZ",flags)) goto L0062b37c;
  }
  L0062b2d2: { // 0x62b2d2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062b2d3: { // 0x62b2d3: 747e JZ 0x0062b353
    if(integer::condition("JZ",flags)) goto L0062b353;
  }
  L0062b2d5: { // 0x62b2d5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062b2d6: { // 0x62b2d6: 0f85c3000000 JNZ 0x0062b39f
    if(integer::condition("JNZ",flags)) goto L0062b39f;
  }
  L0062b2dc: { // 0x62b2dc: a1680aae00 MOV EAX,[0x00ae0a68]
    s.ax = m.r32((0x00ae0a68u));
  }
  L0062b2e1: { // 0x62b2e1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062b2e3: { // 0x62b2e3: 7420 JZ 0x0062b305
    if(integer::condition("JZ",flags)) goto L0062b305;
  }
  L0062b2e5: { // 0x62b2e5: e846d0ddff CALL 0x00408330
    s.arithmetic_flags=flags; invoke(m,s,f,0x00408330u,6468330u); flags=s.arithmetic_flags;
  }
  L0062b2ea: { // 0x62b2ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062b2ec: { // 0x62b2ec: 0f84ad000000 JZ 0x0062b39f
    if(integer::condition("JZ",flags)) goto L0062b39f;
  }
  L0062b2f2: { // 0x62b2f2: a1680aae00 MOV EAX,[0x00ae0a68]
    s.ax = m.r32((0x00ae0a68u));
  }
  L0062b2f7: { // 0x62b2f7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062b2f9: { // 0x62b2f9: 740a JZ 0x0062b305
    if(integer::condition("JZ",flags)) goto L0062b305;
  }
  L0062b2fb: { // 0x62b2fb: e810020e00 CALL 0x0070b510
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070b510u,6468352u); flags=s.arithmetic_flags;
  }
  L0062b300: { // 0x62b300: e8fb25f7ff CALL 0x0059d900
    s.arithmetic_flags=flags; invoke(m,s,f,0x0059d900u,6468357u); flags=s.arithmetic_flags;
  }
  L0062b305: { // 0x62b305: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062b307: { // 0x62b307: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0062b309: { // 0x62b309: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062b30b: { // 0x62b30b: e870f3ffff CALL 0x0062a680
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062a680u,6468368u); flags=s.arithmetic_flags;
  }
  L0062b310: { // 0x62b310: 81c6bc140000 ADD ESI,0x14bc
    s.si = integer::add(s.si,0x000014bcu,32,flags);
  }
  L0062b316: { // 0x62b316: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062b318: { // 0x62b318: e853adddff CALL 0x00406070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00406070u,6468381u); flags=s.arithmetic_flags;
  }
  L0062b31d: { // 0x62b31d: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0062b322: { // 0x62b322: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062b324: { // 0x62b324: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062b326: { // 0x62b326: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  L0062b32b: { // 0x62b32b: 8b8818060000 MOV ECX,dword ptr [EAX + 0x618]
    s.cx = m.r32((s.ax+0x00000618u));
  }
  L0062b331: { // 0x62b331: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L0062b336: { // 0x62b336: e835d60d00 CALL 0x00708970
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708970u,6468411u); flags=s.arithmetic_flags;
  }
  L0062b33b: { // 0x62b33b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0062b33d: { // 0x62b33d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062b33f: { // 0x62b33f: e8bcadddff CALL 0x00406100
    s.arithmetic_flags=flags; invoke(m,s,f,0x00406100u,6468420u); flags=s.arithmetic_flags;
  }
  L0062b344: { // 0x62b344: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0062b34a: { // 0x62b34a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062b34b: { // 0x62b34b: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0062b34e: { // 0x62b34e: e9ad06f1ff JMP 0x0053ba00
    throw std::runtime_error("B593 unproved state2 launch tail53BA00");
  }
  L0062b353: { // 0x62b353: 8b8ed0140000 MOV ECX,dword ptr [ESI + 0x14d0]
    s.cx = m.r32((s.si+0x000014d0u));
  }
  L0062b359: { // 0x62b359: e8f2fe0d00 CALL 0x0070b250
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070b250u,6468446u); flags=s.arithmetic_flags;
  }
  L0062b35e: { // 0x62b35e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062b360: { // 0x62b360: 743d JZ 0x0062b39f
    if(integer::condition("JZ",flags)) goto L0062b39f;
  }
  L0062b362: { // 0x62b362: a1680aae00 MOV EAX,[0x00ae0a68]
    s.ax = m.r32((0x00ae0a68u));
  }
  L0062b367: { // 0x62b367: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062b369: { // 0x62b369: 7405 JZ 0x0062b370
    if(integer::condition("JZ",flags)) goto L0062b370;
  }
  L0062b36b: { // 0x62b36b: e840cfddff CALL 0x004082b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004082b0u,6468464u); flags=s.arithmetic_flags;
  }
  L0062b370: { // 0x62b370: c786b414000002000000 MOV dword ptr [ESI + 0x14b4],0x2
    m.w32((s.si+0x000014b4u), 0x00000002u);
  }
  L0062b37a: { // 0x62b37a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062b37b: { // 0x62b37b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0062b37c: { // 0x62b37c: e8efef0d00 CALL 0x0070a370
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a370u,6468481u); flags=s.arithmetic_flags;
  }
  L0062b381: { // 0x62b381: 8b8ed0140000 MOV ECX,dword ptr [ESI + 0x14d0]
    s.cx = m.r32((s.si+0x000014d0u));
  }
  L0062b387: { // 0x62b387: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0062b389: { // 0x62b389: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0062b38b: { // 0x62b38b: e8f0f00d00 CALL 0x0070a480
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a480u,6468496u); flags=s.arithmetic_flags;
  }
  L0062b390: { // 0x62b390: e86b010e00 CALL 0x0070b500
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070b500u,6468501u); flags=s.arithmetic_flags;
  }
  L0062b395: { // 0x62b395: c786b414000001000000 MOV dword ptr [ESI + 0x14b4],0x1
    m.w32((s.si+0x000014b4u), 0x00000001u);
  }
  L0062b39f: { // 0x62b39f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062b3a0: { // 0x62b3a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00727430(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00727430: { // 0x727430: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00727431: { // 0x727431: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00727433: { // 0x727433: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00727434: { // 0x727434: 8b86ac030000 MOV EAX,dword ptr [ESI + 0x3ac]
    s.ax = m.r32((s.si+0x000003acu));
  }
  L0072743a: { // 0x72743a: 8bbeb4030000 MOV EDI,dword ptr [ESI + 0x3b4]
    s.di = m.r32((s.si+0x000003b4u));
  }
  L00727440: { // 0x727440: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00727443: { // 0x727443: 7417 JZ 0x0072745c
    if(integer::condition("JZ",flags)) goto L0072745c;
  }
  L00727445: { // 0x727445: 8d8eb0030000 LEA ECX,[ESI + 0x3b0]
    s.cx = (s.si+0x000003b0u);
  }
  L0072744b: { // 0x72744b: e88086f6ff CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,7500880u); flags=s.arithmetic_flags;
  }
  L00727450: { // 0x727450: 2b86ac030000 SUB EAX,dword ptr [ESI + 0x3ac]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x000003acu)),32,flags);
  }
  L00727456: { // 0x727456: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00727458: { // 0x727458: 7d0a JGE 0x00727464
    if(integer::condition("JGE",flags)) goto L00727464;
  }
  L0072745a: { // 0x72745a: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0072745c: { // 0x72745c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0072745e: { // 0x72745e: 0f85ae000000 JNZ 0x00727512
    if(integer::condition("JNZ",flags)) goto L00727512;
  }
  L00727464: { // 0x727464: 8b86d0030000 MOV EAX,dword ptr [ESI + 0x3d0]
    s.ax = m.r32((s.si+0x000003d0u));
  }
  L0072746a: { // 0x72746a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0072746c: { // 0x72746c: 0f8ea0000000 JLE 0x00727512
    if(integer::condition("JLE",flags)) goto L00727512;
  }
  L00727472: { // 0x727472: e86935feff CALL 0x0070a9e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a9e0u,7500919u); flags=s.arithmetic_flags;
  }
  L00727477: { // 0x727477: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00727479: { // 0x727479: 0f8593000000 JNZ 0x00727512
    if(integer::condition("JNZ",flags)) goto L00727512;
  }
  L0072747f: { // 0x72747f: 8a86b8030000 MOV AL,byte ptr [ESI + 0x3b8]
    s.ax = with_al(s.ax, m.r8((s.si+0x000003b8u)));
  }
  L00727485: { // 0x727485: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00727487: { // 0x727487: 7546 JNZ 0x007274cf
    if(integer::condition("JNZ",flags)) goto L007274cf;
  }
  L00727489: { // 0x727489: 8b86d0030000 MOV EAX,dword ptr [ESI + 0x3d0]
    s.ax = m.r32((s.si+0x000003d0u));
  }
  L0072748f: { // 0x72748f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00727491: { // 0x727491: 7e2b JLE 0x007274be
    if(integer::condition("JLE",flags)) goto L007274be;
  }
  L00727493: { // 0x727493: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00727494: { // 0x727494: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00727496: { // 0x727496: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00727498: { // 0x727498: 8986d0030000 MOV dword ptr [ESI + 0x3d0],EAX
    m.w32((s.si+0x000003d0u), s.ax);
  }
  L0072749e: { // 0x72749e: 7e1e JLE 0x007274be
    if(integer::condition("JLE",flags)) goto L007274be;
  }
  L007274a0: { // 0x7274a0: 8b86c4030000 MOV EAX,dword ptr [ESI + 0x3c4]
    s.ax = m.r32((s.si+0x000003c4u));
  }
  L007274a6: { // 0x7274a6: 8d4cb804 LEA ECX,[EAX + EDI*0x4 + 0x4]
    s.cx = (s.ax+(s.di * 0x00000004u)+0x00000004u);
  }
  L007274aa: { // 0x7274aa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007274ab: { // 0x7274ab: 8d0cb8 LEA ECX,[EAX + EDI*0x4]
    s.cx = (s.ax+(s.di * 0x00000004u));
  }
  L007274ae: { // 0x7274ae: e8bd200300 CALL 0x00759570
    s.arithmetic_flags=flags; invoke(m,s,f,0x00759570u,7500979u); flags=s.arithmetic_flags;
  }
  L007274b3: { // 0x7274b3: 8b86d0030000 MOV EAX,dword ptr [ESI + 0x3d0]
    s.ax = m.r32((s.si+0x000003d0u));
  }
  L007274b9: { // 0x7274b9: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L007274ba: { // 0x7274ba: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L007274bc: { // 0x7274bc: 7ce2 JL 0x007274a0
    if(integer::condition("JL",flags)) goto L007274a0;
  }
  L007274be: { // 0x7274be: 8b86bc030000 MOV EAX,dword ptr [ESI + 0x3bc]
    s.ax = m.r32((s.si+0x000003bcu));
  }
  L007274c4: { // 0x7274c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007274c6: { // 0x7274c6: 7e07 JLE 0x007274cf
    if(integer::condition("JLE",flags)) goto L007274cf;
  }
  L007274c8: { // 0x7274c8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007274c9: { // 0x7274c9: 8986bc030000 MOV dword ptr [ESI + 0x3bc],EAX
    m.w32((s.si+0x000003bcu), s.ax);
  }
  L007274cf: { // 0x7274cf: 8b86d0030000 MOV EAX,dword ptr [ESI + 0x3d0]
    s.ax = m.r32((s.si+0x000003d0u));
  }
  L007274d5: { // 0x7274d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007274d7: { // 0x7274d7: 7e28 JLE 0x00727501
    if(integer::condition("JLE",flags)) goto L00727501;
  }
  L007274d9: { // 0x7274d9: 8b8ec4030000 MOV ECX,dword ptr [ESI + 0x3c4]
    s.cx = m.r32((s.si+0x000003c4u));
  }
  L007274df: { // 0x7274df: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L007274e1: { // 0x7274e1: e84a2b0300 CALL 0x0075a030
    s.arithmetic_flags=flags; invoke(m,s,f,0x0075a030u,7501030u); flags=s.arithmetic_flags;
  }
  L007274e6: { // 0x7274e6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007274e8: { // 0x7274e8: e8133dfeff CALL 0x0070b200
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070b200u,7501037u); flags=s.arithmetic_flags;
  }
  L007274ed: { // 0x7274ed: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007274ef: { // 0x7274ef: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L007274f2: { // 0x7274f2: e8892ffeff CALL 0x0070a480
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a480u,7501047u); flags=s.arithmetic_flags;
  }
  L007274f7: { // 0x7274f7: c686b803000000 MOV byte ptr [ESI + 0x3b8],0x0
    m.w8((s.si+0x000003b8u), 0x00000000u);
  }
  L007274fe: { // 0x7274fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007274ff: { // 0x7274ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00727500: { // 0x727500: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00727501: { // 0x727501: c786bc03000000000000 MOV dword ptr [ESI + 0x3bc],0x0
    m.w32((s.si+0x000003bcu), 0x00000000u);
  }
  L0072750b: { // 0x72750b: c686b803000001 MOV byte ptr [ESI + 0x3b8],0x1
    m.w8((s.si+0x000003b8u), 0x00000001u);
  }
  L00727512: { // 0x727512: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00727513: { // 0x727513: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00727514: { // 0x727514: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
