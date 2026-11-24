#include "recovered/recovery_b831_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b831 {
namespace {
void f_00363490(Memory&,State&,Frame&,const Operations&);
void f_0036b926(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00363490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763490: { // 0x763490: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00763493: { // 0x763493: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763494: { // 0x763494: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00763495: { // 0x763495: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763496: { // 0x763496: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00763498: { // 0x763498: 8bea MOV EBP, EDX
    s.bp = s.dx;
  }
  L0076349a: { // 0x76349a: 8a86a4010000 MOV AL, byte ptr [ESI + 0x1a4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001a4u)));
  }
  L007634a0: { // 0x7634a0: 896c2418 MOV dword ptr [ESP + 0x18], EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L007634a4: { // 0x7634a4: 8b5d04 MOV EBX, dword ptr [EBP + 4]
    s.bx = m.r32((s.bp+4u));
  }
  L007634a7: { // 0x7634a7: a802 TEST AL, 2
    (void)integer::logical(((s.ax & 0xffu))&(2u),8,flags);
  }
  L007634a9: { // 0x7634a9: 895c240c MOV dword ptr [ESP + 0xc], EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L007634ad: { // 0x7634ad: 0f85c9000000 JNZ 0x76357c
    if(integer::condition("JNZ",flags)) goto L0076357c;
  }
  L007634b3: { // 0x7634b3: 8b4648 MOV EAX, dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L007634b6: { // 0x7634b6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007634b8: { // 0x7634b8: 7410 JZ 0x7634ca
    if(integer::condition("JZ",flags)) goto L007634ca;
  }
  L007634ba: { // 0x7634ba: 6a00 PUSH 0
    f.push(m,0u);
  }
  L007634bc: { // 0x7634bc: 6a00 PUSH 0
    f.push(m,0u);
  }
  L007634be: { // 0x7634be: 6a06 PUSH 6
    f.push(m,6u);
  }
  L007634c0: { // 0x7634c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007634c1: { // 0x7634c1: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7746755u); flags=s.arithmetic_flags;
  }
  L007634c3: { // 0x7634c3: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007634c6: { // 0x7634c6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007634c8: { // 0x7634c8: 750e JNZ 0x7634d8
    if(integer::condition("JNZ",flags)) goto L007634d8;
  }
  L007634ca: { // 0x7634ca: 8b86a8010000 MOV EAX, dword ptr [ESI + 0x1a8]
    s.ax = m.r32((s.si+0x000001a8u));
  }
  L007634d0: { // 0x7634d0: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007634d2: { // 0x7634d2: 0f84a4000000 JZ 0x76357c
    if(integer::condition("JZ",flags)) goto L0076357c;
  }
  L007634d8: { // 0x7634d8: 8b8ec4060000 MOV ECX, dword ptr [ESI + 0x6c4]
    s.cx = m.r32((s.si+0x000006c4u));
  }
  L007634de: { // 0x7634de: 8b96c8060000 MOV EDX, dword ptr [ESI + 0x6c8]
    s.dx = m.r32((s.si+0x000006c8u));
  }
  L007634e4: { // 0x7634e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007634e5: { // 0x7634e5: 8bbebc010000 MOV EDI, dword ptr [ESI + 0x1bc]
    s.di = m.r32((s.si+0x000001bcu));
  }
  L007634eb: { // 0x7634eb: 03f8 ADD EDI, EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L007634ed: { // 0x7634ed: 8a4514 MOV AL, byte ptr [EBP + 0x14]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000014u)));
  }
  L007634f0: { // 0x7634f0: a840 TEST AL, 0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007634f2: { // 0x7634f2: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L007634f6: { // 0x7634f6: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L007634fa: { // 0x7634fa: 7408 JZ 0x763504
    if(integer::condition("JZ",flags)) goto L00763504;
  }
  L007634fc: { // 0x7634fc: 8baee8060000 MOV EBP, dword ptr [ESI + 0x6e8]
    s.bp = m.r32((s.si+0x000006e8u));
  }
  L00763502: { // 0x763502: eb03 JMP 0x763507
    goto L00763507;
  }
  L00763504: { // 0x763504: 8b6d00 MOV EBP, dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L00763507: { // 0x763507: 8b430c MOV EAX, dword ptr [EBX + 0xc]
    s.ax = m.r32((s.bx+0x0000000cu));
  }
  L0076350a: { // 0x76350a: a804 TEST AL, 4
    (void)integer::logical(((s.ax & 0xffu))&(4u),8,flags);
  }
  L0076350c: { // 0x76350c: 7408 JZ 0x763516
    if(integer::condition("JZ",flags)) goto L00763516;
  }
  L0076350e: { // 0x76350e: 8b9ef0060000 MOV EBX, dword ptr [ESI + 0x6f0]
    s.bx = m.r32((s.si+0x000006f0u));
  }
  L00763514: { // 0x763514: eb02 JMP 0x763518
    goto L00763518;
  }
  L00763516: { // 0x763516: 8b1b MOV EBX, dword ptr [EBX]
    s.bx = m.r32((s.bx));
  }
  L00763518: { // 0x763518: 837e4800 CMP dword ptr [ESI + 0x48], 0
    (void)integer::sub(m.r32((s.si+0x00000048u)),0u,32,flags);
  }
  L0076351c: { // 0x76351c: 7423 JZ 0x763541
    if(integer::condition("JZ",flags)) goto L00763541;
  }
  L0076351e: { // 0x76351e: a808 TEST AL, 8
    (void)integer::logical(((s.ax & 0xffu))&(8u),8,flags);
  }
  L00763520: { // 0x763520: 741f JZ 0x763541
    if(integer::condition("JZ",flags)) goto L00763541;
  }
  L00763522: { // 0x763522: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00763526: { // 0x763526: 24f7 AND AL, 0xf7
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000f7u),8,flags));
  }
  L00763528: { // 0x763528: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0076352b: { // 0x76352b: 8b4114 MOV EAX, dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L0076352e: { // 0x76352e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076352f: { // 0x76352f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763530: { // 0x763530: 6a03 PUSH 3
    f.push(m,3u);
  }
  L00763532: { // 0x763532: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763533: { // 0x763533: ff5648 CALL dword ptr [ESI + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000048u)),7746870u); flags=s.arithmetic_flags;
  }
  L00763536: { // 0x763536: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0076353a: { // 0x76353a: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0076353e: { // 0x76353e: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00763541: { // 0x763541: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00763545: { // 0x763545: f6401420 TEST byte ptr [EAX + 0x14], 0x20
    (void)integer::logical((m.r8((s.ax+0x00000014u)))&(0x00000020u),8,flags);
  }
  L00763549: { // 0x763549: 8b86ac010000 MOV EAX, dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  L0076354f: { // 0x76354f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00763550: { // 0x763550: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00763551: { // 0x763551: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00763552: { // 0x763552: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763553: { // 0x763553: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00763554: { // 0x763554: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763555: { // 0x763555: 7508 JNZ 0x76355f
    if(integer::condition("JNZ",flags)) goto L0076355f;
  }
  L00763557: { // 0x763557: ff9684070000 CALL dword ptr [ESI + 0x784]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000784u)),7746909u); flags=s.arithmetic_flags;
  }
  L0076355d: { // 0x76355d: eb06 JMP 0x763565
    goto L00763565;
  }
  L0076355f: { // 0x76355f: ff9688070000 CALL dword ptr [ESI + 0x788]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000788u)),7746917u); flags=s.arithmetic_flags;
  }
  L00763565: { // 0x763565: 8b4648 MOV EAX, dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L00763568: { // 0x763568: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0076356b: { // 0x76356b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076356d: { // 0x76356d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076356e: { // 0x76356e: 740c JZ 0x76357c
    if(integer::condition("JZ",flags)) goto L0076357c;
  }
  L00763570: { // 0x763570: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00763572: { // 0x763572: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00763574: { // 0x763574: 6a07 PUSH 7
    f.push(m,7u);
  }
  L00763576: { // 0x763576: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763577: { // 0x763577: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7746937u); flags=s.arithmetic_flags;
  }
  L00763579: { // 0x763579: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076357c: { // 0x76357c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076357d: { // 0x76357d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076357e: { // 0x76357e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076357f: { // 0x76357f: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00763582: { // 0x763582: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036b926(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076b926: { // 0x76b926: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076b927: { // 0x76b927: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L0076b929: { // 0x76b929: 83c4f0 ADD ESP, -0x10
    f.sp = integer::add(f.sp,0xfffffff0u,32,flags);
  }
  L0076b92c: { // 0x76b92c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076b92d: { // 0x76b92d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0076b92e: { // 0x76b92e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0076b92f: { // 0x76b92f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076b930: { // 0x76b930: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076b931: { // 0x76b931: 8b451c MOV EAX, dword ptr [EBP + 0x1c]
    s.ax = m.r32((s.bp+0x0000001cu));
  }
  L0076b934: { // 0x76b934: c1e002 SHL EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::left);
  }
  L0076b937: { // 0x76b937: 8945f4 MOV dword ptr [EBP - 0xc], EAX
    m.w32((s.bp-0x0000000cu), s.ax);
  }
  L0076b93a: { // 0x76b93a: 8b750c MOV ESI, dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076b93d: { // 0x76b93d: 8b4518 MOV EAX, dword ptr [EBP + 0x18]
    s.ax = m.r32((s.bp+0x00000018u));
  }
  L0076b940: { // 0x76b940: f76514 MUL dword ptr [EBP + 0x14]
    const auto product=std::uint64_t(s.ax)*std::uint64_t(m.r32((s.bp+0x00000014u)));
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L0076b943: { // 0x76b943: 8945f0 MOV dword ptr [EBP - 0x10], EAX
    m.w32((s.bp-0x00000010u), s.ax);
  }
  L0076b946: { // 0x76b946: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0076b948: { // 0x76b948: 8945fc MOV dword ptr [EBP - 4], EAX
    m.w32((s.bp-4u), s.ax);
  }
  L0076b94b: { // 0x76b94b: 8b7d10 MOV EDI, dword ptr [EBP + 0x10]
    s.di = m.r32((s.bp+0x00000010u));
  }
  L0076b94e: { // 0x76b94e: 897df8 MOV dword ptr [EBP - 8], EDI
    m.w32((s.bp-8u), s.di);
  }
  L0076b951: { // 0x76b951: 8b4d14 MOV ECX, dword ptr [EBP + 0x14]
    s.cx = m.r32((s.bp+0x00000014u));
  }
  L0076b954: { // 0x76b954: 8b45f0 MOV EAX, dword ptr [EBP - 0x10]
    s.ax = m.r32((s.bp-0x00000010u));
  }
  L0076b957: { // 0x76b957: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0076b959: { // 0x76b959: 8a3c30 MOV BH, byte ptr [EAX + ESI]
    s.bx = (s.bx & 0xffff00ffu) | (((m.r8((s.ax+s.si))) & 0xffu) << 8);
  }
  L0076b95c: { // 0x76b95c: 8a1e MOV BL, byte ptr [ESI]
    s.bx = with_al(s.bx, m.r8((s.si)));
  }
  L0076b95e: { // 0x76b95e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076b95f: { // 0x76b95f: 80ffff CMP BH, 0xff
    (void)integer::sub(((s.bx >> 8) & 0xffu),0x000000ffu,8,flags);
  }
  L0076b962: { // 0x76b962: 7441 JZ 0x76b9a5
    if(integer::condition("JZ",flags)) goto L0076b9a5;
  }
  L0076b964: { // 0x76b964: c1e304 SHL EBX, 4
    s.bx = integer::shift(s.bx,4u,32,flags,integer::Shift::left);
  }
  L0076b967: { // 0x76b967: 035d08 ADD EBX, dword ptr [EBP + 8]
    s.bx = integer::add(s.bx,m.r32((s.bp+8u)),32,flags);
  }
  L0076b96a: { // 0x76b96a: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0076b96c: { // 0x76b96c: 8b5304 MOV EDX, dword ptr [EBX + 4]
    s.dx = m.r32((s.bx+4u));
  }
  L0076b96f: { // 0x76b96f: 8907 MOV dword ptr [EDI], EAX
    m.w32((s.di), s.ax);
  }
  L0076b971: { // 0x76b971: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L0076b973: { // 0x76b973: 8b5d1c MOV EBX, dword ptr [EBP + 0x1c]
    s.bx = m.r32((s.bp+0x0000001cu));
  }
  L0076b976: { // 0x76b976: 89143b MOV dword ptr [EBX + EDI], EDX
    m.w32((s.bx+s.di), s.dx);
  }
  L0076b979: { // 0x76b979: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0076b97b: { // 0x76b97b: 8b4308 MOV EAX, dword ptr [EBX + 8]
    s.ax = m.r32((s.bx+8u));
  }
  L0076b97e: { // 0x76b97e: 8b530c MOV EDX, dword ptr [EBX + 0xc]
    s.dx = m.r32((s.bx+0x0000000cu));
  }
  L0076b981: { // 0x76b981: 8b5d1c MOV EBX, dword ptr [EBP + 0x1c]
    s.bx = m.r32((s.bp+0x0000001cu));
  }
  L0076b984: { // 0x76b984: d1e3 SHL EBX, 1
    s.bx = integer::shift(s.bx,1u,32,flags,integer::Shift::left);
  }
  L0076b986: { // 0x76b986: 89043b MOV dword ptr [EBX + EDI], EAX
    m.w32((s.bx+s.di), s.ax);
  }
  L0076b989: { // 0x76b989: 035d1c ADD EBX, dword ptr [EBP + 0x1c]
    s.bx = integer::add(s.bx,m.r32((s.bp+0x0000001cu)),32,flags);
  }
  L0076b98c: { // 0x76b98c: 89143b MOV dword ptr [EBX + EDI], EDX
    m.w32((s.bx+s.di), s.dx);
  }
  L0076b98f: { // 0x76b98f: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L0076b992: { // 0x76b992: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076b993: { // 0x76b993: 75bf JNZ 0x76b954
    if(integer::condition("JNZ",flags)) goto L0076b954;
  }
  L0076b995: { // 0x76b995: 8b7df8 MOV EDI, dword ptr [EBP - 8]
    s.di = m.r32((s.bp-8u));
  }
  L0076b998: { // 0x76b998: 037df4 ADD EDI, dword ptr [EBP - 0xc]
    s.di = integer::add(s.di,m.r32((s.bp-0x0000000cu)),32,flags);
  }
  L0076b99b: { // 0x76b99b: 897df8 MOV dword ptr [EBP - 8], EDI
    m.w32((s.bp-8u), s.di);
  }
  L0076b99e: { // 0x76b99e: 3b75fc CMP ESI, dword ptr [EBP - 4]
    (void)integer::sub(s.si,m.r32((s.bp-4u)),32,flags);
  }
  L0076b9a1: { // 0x76b9a1: 733a JAE 0x76b9dd
    if(integer::condition("JNC",flags)) goto L0076b9dd;
  }
  L0076b9a3: { // 0x76b9a3: ebac JMP 0x76b951
    goto L0076b951;
  }
  L0076b9a5: { // 0x76b9a5: 8afb MOV BH, BL
    s.bx = (s.bx & 0xffff00ffu) | ((((s.bx & 0xffu)) & 0xffu) << 8);
  }
  L0076b9a7: { // 0x76b9a7: 668bc3 MOV AX, BX
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0076b9aa: { // 0x76b9aa: c1c010 ROL EAX, 0x10
    s.ax=(s.ax<<16)|(s.ax>>16);
  }
  L0076b9ad: { // 0x76b9ad: 668bc3 MOV AX, BX
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0076b9b0: { // 0x76b9b0: 8907 MOV dword ptr [EDI], EAX
    m.w32((s.di), s.ax);
  }
  L0076b9b2: { // 0x76b9b2: 8b5d1c MOV EBX, dword ptr [EBP + 0x1c]
    s.bx = m.r32((s.bp+0x0000001cu));
  }
  L0076b9b5: { // 0x76b9b5: 89043b MOV dword ptr [EBX + EDI], EAX
    m.w32((s.bx+s.di), s.ax);
  }
  L0076b9b8: { // 0x76b9b8: 035d1c ADD EBX, dword ptr [EBP + 0x1c]
    s.bx = integer::add(s.bx,m.r32((s.bp+0x0000001cu)),32,flags);
  }
  L0076b9bb: { // 0x76b9bb: 89043b MOV dword ptr [EBX + EDI], EAX
    m.w32((s.bx+s.di), s.ax);
  }
  L0076b9be: { // 0x76b9be: 035d1c ADD EBX, dword ptr [EBP + 0x1c]
    s.bx = integer::add(s.bx,m.r32((s.bp+0x0000001cu)),32,flags);
  }
  L0076b9c1: { // 0x76b9c1: 89043b MOV dword ptr [EBX + EDI], EAX
    m.w32((s.bx+s.di), s.ax);
  }
  L0076b9c4: { // 0x76b9c4: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L0076b9c7: { // 0x76b9c7: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076b9c8: { // 0x76b9c8: 758a JNZ 0x76b954
    if(integer::condition("JNZ",flags)) goto L0076b954;
  }
  L0076b9ca: { // 0x76b9ca: 8b7df8 MOV EDI, dword ptr [EBP - 8]
    s.di = m.r32((s.bp-8u));
  }
  L0076b9cd: { // 0x76b9cd: 037df4 ADD EDI, dword ptr [EBP - 0xc]
    s.di = integer::add(s.di,m.r32((s.bp-0x0000000cu)),32,flags);
  }
  L0076b9d0: { // 0x76b9d0: 897df8 MOV dword ptr [EBP - 8], EDI
    m.w32((s.bp-8u), s.di);
  }
  L0076b9d3: { // 0x76b9d3: 3b75fc CMP ESI, dword ptr [EBP - 4]
    (void)integer::sub(s.si,m.r32((s.bp-4u)),32,flags);
  }
  L0076b9d6: { // 0x76b9d6: 7305 JAE 0x76b9dd
    if(integer::condition("JNC",flags)) goto L0076b9dd;
  }
  L0076b9d8: { // 0x76b9d8: e974ffffff JMP 0x76b951
    goto L0076b951;
  }
  L0076b9dd: { // 0x76b9dd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076b9de: { // 0x76b9de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076b9df: { // 0x76b9df: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  L0076b9e0: { // 0x76b9e0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076b9e1: { // 0x76b9e1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076b9e2: { // 0x76b9e2: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076b9e3: { // 0x76b9e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7746704u:f_00363490(m,s,child,{});break;
case 7780646u:f_0036b926(m,s,child,{});break;
default:throw std::domain_error("recovery831 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00763490(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763490: { // 0x763490: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00763493: { // 0x763493: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763494: { // 0x763494: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00763495: { // 0x763495: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763496: { // 0x763496: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00763498: { // 0x763498: 8bea MOV EBP, EDX
    s.bp = s.dx;
  }
  L0076349a: { // 0x76349a: 8a86a4010000 MOV AL, byte ptr [ESI + 0x1a4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001a4u)));
  }
  L007634a0: { // 0x7634a0: 896c2418 MOV dword ptr [ESP + 0x18], EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L007634a4: { // 0x7634a4: 8b5d04 MOV EBX, dword ptr [EBP + 4]
    s.bx = m.r32((s.bp+4u));
  }
  L007634a7: { // 0x7634a7: a802 TEST AL, 2
    (void)integer::logical(((s.ax & 0xffu))&(2u),8,flags);
  }
  L007634a9: { // 0x7634a9: 895c240c MOV dword ptr [ESP + 0xc], EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L007634ad: { // 0x7634ad: 0f85c9000000 JNZ 0x76357c
    if(integer::condition("JNZ",flags)) goto L0076357c;
  }
  L007634b3: { // 0x7634b3: 8b4648 MOV EAX, dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L007634b6: { // 0x7634b6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007634b8: { // 0x7634b8: 7410 JZ 0x7634ca
    if(integer::condition("JZ",flags)) goto L007634ca;
  }
  L007634ba: { // 0x7634ba: 6a00 PUSH 0
    f.push(m,0u);
  }
  L007634bc: { // 0x7634bc: 6a00 PUSH 0
    f.push(m,0u);
  }
  L007634be: { // 0x7634be: 6a06 PUSH 6
    f.push(m,6u);
  }
  L007634c0: { // 0x7634c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007634c1: { // 0x7634c1: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7746755u); flags=s.arithmetic_flags;
  }
  L007634c3: { // 0x7634c3: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007634c6: { // 0x7634c6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007634c8: { // 0x7634c8: 750e JNZ 0x7634d8
    if(integer::condition("JNZ",flags)) goto L007634d8;
  }
  L007634ca: { // 0x7634ca: 8b86a8010000 MOV EAX, dword ptr [ESI + 0x1a8]
    s.ax = m.r32((s.si+0x000001a8u));
  }
  L007634d0: { // 0x7634d0: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007634d2: { // 0x7634d2: 0f84a4000000 JZ 0x76357c
    if(integer::condition("JZ",flags)) goto L0076357c;
  }
  L007634d8: { // 0x7634d8: 8b8ec4060000 MOV ECX, dword ptr [ESI + 0x6c4]
    s.cx = m.r32((s.si+0x000006c4u));
  }
  L007634de: { // 0x7634de: 8b96c8060000 MOV EDX, dword ptr [ESI + 0x6c8]
    s.dx = m.r32((s.si+0x000006c8u));
  }
  L007634e4: { // 0x7634e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007634e5: { // 0x7634e5: 8bbebc010000 MOV EDI, dword ptr [ESI + 0x1bc]
    s.di = m.r32((s.si+0x000001bcu));
  }
  L007634eb: { // 0x7634eb: 03f8 ADD EDI, EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L007634ed: { // 0x7634ed: 8a4514 MOV AL, byte ptr [EBP + 0x14]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000014u)));
  }
  L007634f0: { // 0x7634f0: a840 TEST AL, 0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007634f2: { // 0x7634f2: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L007634f6: { // 0x7634f6: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L007634fa: { // 0x7634fa: 7408 JZ 0x763504
    if(integer::condition("JZ",flags)) goto L00763504;
  }
  L007634fc: { // 0x7634fc: 8baee8060000 MOV EBP, dword ptr [ESI + 0x6e8]
    s.bp = m.r32((s.si+0x000006e8u));
  }
  L00763502: { // 0x763502: eb03 JMP 0x763507
    goto L00763507;
  }
  L00763504: { // 0x763504: 8b6d00 MOV EBP, dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L00763507: { // 0x763507: 8b430c MOV EAX, dword ptr [EBX + 0xc]
    s.ax = m.r32((s.bx+0x0000000cu));
  }
  L0076350a: { // 0x76350a: a804 TEST AL, 4
    (void)integer::logical(((s.ax & 0xffu))&(4u),8,flags);
  }
  L0076350c: { // 0x76350c: 7408 JZ 0x763516
    if(integer::condition("JZ",flags)) goto L00763516;
  }
  L0076350e: { // 0x76350e: 8b9ef0060000 MOV EBX, dword ptr [ESI + 0x6f0]
    s.bx = m.r32((s.si+0x000006f0u));
  }
  L00763514: { // 0x763514: eb02 JMP 0x763518
    goto L00763518;
  }
  L00763516: { // 0x763516: 8b1b MOV EBX, dword ptr [EBX]
    s.bx = m.r32((s.bx));
  }
  L00763518: { // 0x763518: 837e4800 CMP dword ptr [ESI + 0x48], 0
    (void)integer::sub(m.r32((s.si+0x00000048u)),0u,32,flags);
  }
  L0076351c: { // 0x76351c: 7423 JZ 0x763541
    if(integer::condition("JZ",flags)) goto L00763541;
  }
  L0076351e: { // 0x76351e: a808 TEST AL, 8
    (void)integer::logical(((s.ax & 0xffu))&(8u),8,flags);
  }
  L00763520: { // 0x763520: 741f JZ 0x763541
    if(integer::condition("JZ",flags)) goto L00763541;
  }
  L00763522: { // 0x763522: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00763526: { // 0x763526: 24f7 AND AL, 0xf7
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000f7u),8,flags));
  }
  L00763528: { // 0x763528: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0076352b: { // 0x76352b: 8b4114 MOV EAX, dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L0076352e: { // 0x76352e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076352f: { // 0x76352f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763530: { // 0x763530: 6a03 PUSH 3
    f.push(m,3u);
  }
  L00763532: { // 0x763532: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763533: { // 0x763533: ff5648 CALL dword ptr [ESI + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000048u)),7746870u); flags=s.arithmetic_flags;
  }
  L00763536: { // 0x763536: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0076353a: { // 0x76353a: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0076353e: { // 0x76353e: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00763541: { // 0x763541: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00763545: { // 0x763545: f6401420 TEST byte ptr [EAX + 0x14], 0x20
    (void)integer::logical((m.r8((s.ax+0x00000014u)))&(0x00000020u),8,flags);
  }
  L00763549: { // 0x763549: 8b86ac010000 MOV EAX, dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  L0076354f: { // 0x76354f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00763550: { // 0x763550: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00763551: { // 0x763551: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00763552: { // 0x763552: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763553: { // 0x763553: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00763554: { // 0x763554: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763555: { // 0x763555: 7508 JNZ 0x76355f
    if(integer::condition("JNZ",flags)) goto L0076355f;
  }
  L00763557: { // 0x763557: ff9684070000 CALL dword ptr [ESI + 0x784]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000784u)),7746909u); flags=s.arithmetic_flags;
  }
  L0076355d: { // 0x76355d: eb06 JMP 0x763565
    goto L00763565;
  }
  L0076355f: { // 0x76355f: ff9688070000 CALL dword ptr [ESI + 0x788]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000788u)),7746917u); flags=s.arithmetic_flags;
  }
  L00763565: { // 0x763565: 8b4648 MOV EAX, dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L00763568: { // 0x763568: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0076356b: { // 0x76356b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076356d: { // 0x76356d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076356e: { // 0x76356e: 740c JZ 0x76357c
    if(integer::condition("JZ",flags)) goto L0076357c;
  }
  L00763570: { // 0x763570: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00763572: { // 0x763572: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00763574: { // 0x763574: 6a07 PUSH 7
    f.push(m,7u);
  }
  L00763576: { // 0x763576: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763577: { // 0x763577: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7746937u); flags=s.arithmetic_flags;
  }
  L00763579: { // 0x763579: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076357c: { // 0x76357c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076357d: { // 0x76357d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076357e: { // 0x76357e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076357f: { // 0x76357f: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00763582: { // 0x763582: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00763c00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763c00: { // 0x763c00: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763c01: { // 0x763c01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00763c03: { // 0x763c03: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763c04: { // 0x763c04: 8bbedc060000 MOV EDI,dword ptr [ESI + 0x6dc]
    s.di = m.r32((s.si+0x000006dcu));
  }
  L00763c0a: { // 0x763c0a: 8b4714 MOV EAX,dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L00763c0d: { // 0x763c0d: 83e004 AND EAX,0x4
    s.ax = integer::logical((s.ax)&(0x00000004u),32,flags);
  }
  L00763c10: { // 0x763c10: 7509 JNZ 0x00763c1b
    if(integer::condition("JNZ",flags)) goto L00763c1b;
  }
  L00763c12: { // 0x763c12: f686a401000001 TEST byte ptr [ESI + 0x1a4],0x1
    (void)integer::logical((m.r8((s.si+0x000001a4u)))&(0x00000001u),8,flags);
  }
  L00763c19: { // 0x763c19: 7443 JZ 0x00763c5e
    if(integer::condition("JZ",flags)) goto L00763c5e;
  }
  L00763c1b: { // 0x763c1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00763c1d: { // 0x763c1d: 7410 JZ 0x00763c2f
    if(integer::condition("JZ",flags)) goto L00763c2f;
  }
  L00763c1f: { // 0x763c1f: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L00763c22: { // 0x763c22: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00763c24: { // 0x763c24: 7438 JZ 0x00763c5e
    if(integer::condition("JZ",flags)) goto L00763c5e;
  }
  L00763c26: { // 0x763c26: 8b4f28 MOV ECX,dword ptr [EDI + 0x28]
    s.cx = m.r32((s.di+0x00000028u));
  }
  L00763c29: { // 0x763c29: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00763c2c: { // 0x763c2c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00763c2d: { // 0x763c2d: eb26 JMP 0x00763c55
    goto L00763c55;
  }
  L00763c2f: { // 0x763c2f: 8b86a4010000 MOV EAX,dword ptr [ESI + 0x1a4]
    s.ax = m.r32((s.si+0x000001a4u));
  }
  L00763c35: { // 0x763c35: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00763c37: { // 0x763c37: 7425 JZ 0x00763c5e
    if(integer::condition("JZ",flags)) goto L00763c5e;
  }
  L00763c39: { // 0x763c39: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00763c3b: { // 0x763c3b: 8986a4010000 MOV dword ptr [ESI + 0x1a4],EAX
    m.w32((s.si+0x000001a4u), s.ax);
  }
  L00763c41: { // 0x763c41: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L00763c44: { // 0x763c44: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00763c46: { // 0x763c46: 7416 JZ 0x00763c5e
    if(integer::condition("JZ",flags)) goto L00763c5e;
  }
  L00763c48: { // 0x763c48: 8b8ec0010000 MOV ECX,dword ptr [ESI + 0x1c0]
    s.cx = m.r32((s.si+0x000001c0u));
  }
  L00763c4e: { // 0x763c4e: 8d96c4010000 LEA EDX,[ESI + 0x1c4]
    s.dx = (s.si+0x000001c4u);
  }
  L00763c54: { // 0x763c54: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00763c55: { // 0x763c55: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00763c56: { // 0x763c56: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00763c58: { // 0x763c58: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763c59: { // 0x763c59: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7748699u); flags=s.arithmetic_flags;
  }
  L00763c5b: { // 0x763c5b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00763c5e: { // 0x763c5e: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00763c60: { // 0x763c60: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00763c62: { // 0x763c62: e829f8ffff CALL 0x00763490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763490u,7748711u); flags=s.arithmetic_flags;
  }
  L00763c67: { // 0x763c67: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  L00763c6a: { // 0x763c6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00763c6c: { // 0x763c6c: 7416 JZ 0x00763c84
    if(integer::condition("JZ",flags)) goto L00763c84;
  }
  L00763c6e: { // 0x763c6e: 8b4f1c MOV ECX,dword ptr [EDI + 0x1c]
    s.cx = m.r32((s.di+0x0000001cu));
  }
  L00763c71: { // 0x763c71: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00763c72: { // 0x763c72: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763c73: { // 0x763c73: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7748725u); flags=s.arithmetic_flags;
  }
  L00763c75: { // 0x763c75: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00763c78: { // 0x763c78: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00763c7a: { // 0x763c7a: 7408 JZ 0x00763c84
    if(integer::condition("JZ",flags)) goto L00763c84;
  }
  L00763c7c: { // 0x763c7c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763c7d: { // 0x763c7d: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00763c82: { // 0x763c82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763c83: { // 0x763c83: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763c84: { // 0x763c84: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763c85: { // 0x763c85: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00763c88: { // 0x763c88: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763c89: { // 0x763c89: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
