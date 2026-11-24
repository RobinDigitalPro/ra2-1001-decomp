#include "recovered/recovery_b1514_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1514 {
namespace {
void f_00039470(Memory&,State&,Frame&,const Operations&);
void f_00045210(Memory&,State&,Frame&,const Operations&);
void f_0001b320(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00071260(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_00039470(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00439470: { // 0x439470: 83ec2c SUB ESP, 0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L00439473: { // 0x439473: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00439478: { // 0x439478: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00439479: { // 0x439479: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043947a: { // 0x43947a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043947b: { // 0x43947b: 8b8044020000 MOV EAX, dword ptr [EAX + 0x244]
    s.ax = m.r32((s.ax+0x00000244u));
  }
  L00439481: { // 0x439481: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00439482: { // 0x439482: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00439484: { // 0x439484: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00439486: { // 0x439486: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0043948a: { // 0x43948a: 0f84a2010000 JZ 0x439632
    if(integer::condition("JZ",flags)) goto L00439632;
  }
  L00439490: { // 0x439490: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00439496: { // 0x439496: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00439497: { // 0x439497: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00439498: { // 0x439498: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043949a: { // 0x43949a: 81c118020000 ADD ECX, 0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L004394a0: { // 0x4394a0: e89b691f00 CALL 0x62fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4428965u); flags=s.arithmetic_flags;
  }
  L004394a5: { // 0x4394a5: 8dbe9c040000 LEA EDI, [ESI + 0x49c]
    s.di = (s.si+0x0000049cu);
  }
  L004394ab: { // 0x4394ab: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004394af: { // 0x4394af: bd78120000 MOV EBP, 0x1278
    s.bp = 0x00001278u;
  }
  L004394b4: { // 0x4394b4: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L004394b8: { // 0x4394b8: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L004394be: { // 0x4394be: 8b0c2a MOV ECX, dword ptr [EDX + EBP]
    s.cx = m.r32((s.dx+s.bp));
  }
  L004394c1: { // 0x4394c1: 8d042a LEA EAX, [EDX + EBP]
    s.ax = (s.dx+s.bp);
  }
  L004394c4: { // 0x4394c4: 3b0d78708300 CMP ECX, dword ptr [0x837078]
    (void)integer::sub(s.cx,m.r32((0x00837078u)),32,flags);
  }
  L004394ca: { // 0x4394ca: 7511 JNZ 0x4394dd
    if(integer::condition("JNZ",flags)) goto L004394dd;
  }
  L004394cc: { // 0x4394cc: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L004394cf: { // 0x4394cf: 8b0d7c708300 MOV ECX, dword ptr [0x83707c]
    s.cx = m.r32((0x0083707cu));
  }
  L004394d5: { // 0x4394d5: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L004394d7: { // 0x4394d7: 0f8455010000 JZ 0x439632
    if(integer::condition("JZ",flags)) goto L00439632;
  }
  L004394dd: { // 0x4394dd: 833f00 CMP dword ptr [EDI], 0
    (void)integer::sub(m.r32((s.di)),0u,32,flags);
  }
  L004394e0: { // 0x4394e0: 0f854c010000 JNZ 0x439632
    if(integer::condition("JNZ",flags)) goto L00439632;
  }
  L004394e6: { // 0x4394e6: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L004394ec: { // 0x4394ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004394ed: { // 0x4394ed: 8d442420 LEA EAX, [ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L004394f1: { // 0x4394f1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004394f2: { // 0x4394f2: e849ea2500 CALL 0x697f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697f40u,4429047u); flags=s.arithmetic_flags;
  }
  L004394f7: { // 0x4394f7: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004394f9: { // 0x4394f9: 8b4004 MOV EAX, dword ptr [EAX + 4]
    s.ax = m.r32((s.ax+4u));
  }
  L004394fc: { // 0x4394fc: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004394fe: { // 0x4394fe: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00439502: { // 0x439502: 8954242c MOV dword ptr [ESP + 0x2c], EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00439506: { // 0x439506: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00439508: { // 0x439508: 8d442430 LEA EAX, [ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0043950c: { // 0x43950c: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00439510: { // 0x439510: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00439511: { // 0x439511: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00439513: { // 0x439513: ff92a8000000 CALL dword ptr [EDX + 0xa8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a8u)),4429081u); flags=s.arithmetic_flags;
  }
  L00439519: { // 0x439519: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0043951b: { // 0x43951b: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0043951f: { // 0x43951f: 8b5c2428 MOV EBX, dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L00439523: { // 0x439523: 03d1 ADD EDX, ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00439525: { // 0x439525: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00439529: { // 0x439529: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0043952d: { // 0x43952d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L00439530: { // 0x439530: 68a8010000 PUSH 0x1a8
    f.push(m,0x000001a8u);
  }
  L00439535: { // 0x439535: 03da ADD EBX, EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00439537: { // 0x439537: 895c242c MOV dword ptr [ESP + 0x2c], EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0043953b: { // 0x43953b: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L0043953e: { // 0x43953e: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00439540: { // 0x439540: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00439544: { // 0x439544: e80e443300 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4429129u); flags=s.arithmetic_flags;
  }
  L00439549: { // 0x439549: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0043954c: { // 0x43954c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043954e: { // 0x43954e: 0f84c4000000 JZ 0x439618
    if(integer::condition("JZ",flags)) goto L00439618;
  }
  L00439554: { // 0x439554: 8b15881b8200 MOV EDX, dword ptr [0x821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L0043955a: { // 0x43955a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043955c: { // 0x43955c: 6800060000 PUSH 0x600
    f.push(m,0x00000600u);
  }
  L00439561: { // 0x439561: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00439563: { // 0x439563: 8d4c2430 LEA ECX, [ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00439567: { // 0x439567: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00439569: { // 0x439569: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043956a: { // 0x43956a: 8b8a38020000 MOV ECX, dword ptr [EDX + 0x238]
    s.cx = m.r32((s.dx+0x00000238u));
  }
  L00439570: { // 0x439570: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00439574: { // 0x439574: 8b0c91 MOV ECX, dword ptr [ECX + EDX*4]
    s.cx = m.r32((s.cx+(s.dx * 4u)));
  }
  L00439577: { // 0x439577: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00439578: { // 0x439578: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043957a: { // 0x43957a: e8916bfeff CALL 0x420110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00420110u,4429183u); flags=s.arithmetic_flags;
  }
  L0043957f: { // 0x43957f: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L00439581: { // 0x439581: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00439583: { // 0x439583: 0f848f000000 JZ 0x439618
    if(integer::condition("JZ",flags)) goto L00439618;
  }
  L00439589: { // 0x439589: 891f MOV dword ptr [EDI], EBX
    m.w32((s.di), s.bx);
  }
  L0043958b: { // 0x43958b: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00439591: { // 0x439591: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00439593: { // 0x439593: e828f00100 CALL 0x4585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4429208u); flags=s.arithmetic_flags;
  }
  L00439598: { // 0x439598: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043959e: { // 0x43959e: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004395a0: { // 0x4395a0: e80bf00100 CALL 0x4585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4429221u); flags=s.arithmetic_flags;
  }
  L004395a5: { // 0x4395a5: 03f8 ADD EDI, EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L004395a7: { // 0x4395a7: 8d047f LEA EAX, [EDI + EDI*2]
    s.ax = (s.di+(s.di * 2u));
  }
  L004395aa: { // 0x4395aa: 8d1480 LEA EDX, [EAX + EAX*4]
    s.dx = (s.ax+(s.ax * 4u));
  }
  L004395ad: { // 0x4395ad: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004395b3: { // 0x4395b3: 8b442804 MOV EAX, dword ptr [EAX + EBP + 4]
    s.ax = m.r32((s.ax+s.bp+4u));
  }
  L004395b7: { // 0x4395b7: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004395b9: { // 0x4395b9: 8d0c40 LEA ECX, [EAX + EAX*2]
    s.cx = (s.ax+(s.ax * 2u));
  }
  L004395bc: { // 0x4395bc: d1f9 SAR ECX, 1
    s.cx = integer::shift(s.cx,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L004395be: { // 0x4395be: 8d41f6 LEA EAX, [ECX - 0xa]
    s.ax = (s.cx-0x0000000au);
  }
  L004395c1: { // 0x4395c1: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004395c3: { // 0x4395c3: 8983e8000000 MOV dword ptr [EBX + 0xe8], EAX
    m.w32((s.bx+0x000000e8u), s.ax);
  }
  L004395c9: { // 0x4395c9: 7e0a JLE 0x4395d5
    if(integer::condition("JLE",flags)) goto L004395d5;
  }
  L004395cb: { // 0x4395cb: c783e800000000000000 MOV dword ptr [EBX + 0xe8], 0
    m.w32((s.bx+0x000000e8u), 0u);
  }
  L004395d5: { // 0x4395d5: 8b93b0000000 MOV EDX, dword ptr [EBX + 0xb0]
    s.dx = m.r32((s.bx+0x000000b0u));
  }
  L004395db: { // 0x4395db: 8b8288020000 MOV EAX, dword ptr [EDX + 0x288]
    s.ax = m.r32((s.dx+0x00000288u));
  }
  L004395e1: { // 0x4395e1: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004395e3: { // 0x4395e3: 7e1a JLE 0x4395ff
    if(integer::condition("JLE",flags)) goto L004395ff;
  }
  L004395e5: { // 0x4395e5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004395e6: { // 0x4395e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004395e7: { // 0x4395e7: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004395ec: { // 0x4395ec: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004395ee: { // 0x4395ee: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L004395f4: { // 0x4395f4: e847681f00 CALL 0x62fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4429305u); flags=s.arithmetic_flags;
  }
  L004395f9: { // 0x4395f9: 898398000000 MOV dword ptr [EBX + 0x98], EAX
    m.w32((s.bx+0x00000098u), s.ax);
  }
  L004395ff: { // 0x4395ff: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00439603: { // 0x439603: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00439607: { // 0x439607: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00439608: { // 0x439608: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043960a: { // 0x43960a: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0043960e: { // 0x43960e: 7c08 JL 0x439618
    if(integer::condition("JL",flags)) goto L00439618;
  }
  L00439610: { // 0x439610: c744241000000000 MOV dword ptr [ESP + 0x10], 0
    m.w32((f.sp+0x00000010u), 0u);
  }
  L00439618: { // 0x439618: 8b7c2414 MOV EDI, dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0043961c: { // 0x43961c: 83c508 ADD EBP, 8
    s.bp = integer::add(s.bp,8u,32,flags);
  }
  L0043961f: { // 0x43961f: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L00439622: { // 0x439622: 81fdb8120000 CMP EBP, 0x12b8
    (void)integer::sub(s.bp,0x000012b8u,32,flags);
  }
  L00439628: { // 0x439628: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0043962c: { // 0x43962c: 0f8c86feffff JL 0x4394b8
    if(integer::condition("JL",flags)) goto L004394b8;
  }
  L00439632: { // 0x439632: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00439633: { // 0x439633: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00439634: { // 0x439634: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00439635: { // 0x439635: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00439636: { // 0x439636: 83c42c ADD ESP, 0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L00439639: { // 0x439639: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00045210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00445210: { // 0x445210: 83ec20 SUB ESP, 0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00445213: { // 0x445213: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00445214: { // 0x445214: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00445215: { // 0x445215: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00445216: { // 0x445216: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00445218: { // 0x445218: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044521a: { // 0x44521a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044521b: { // 0x44521b: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00445221: { // 0x445221: 389857130000 CMP byte ptr [EAX + 0x1357], BL
    (void)integer::sub(m.r8((s.ax+0x00001357u)),(s.bx & 0xffu),8,flags);
  }
  L00445227: { // 0x445227: 0f843e010000 JZ 0x44536b
    if(integer::condition("JZ",flags)) goto L0044536b;
  }
  L0044522d: { // 0x44522d: 8b80600c0000 MOV EAX, dword ptr [EAX + 0xc60]
    s.ax = m.r32((s.ax+0x00000c60u));
  }
  L00445233: { // 0x445233: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00445235: { // 0x445235: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00445237: { // 0x445237: 8b7828 MOV EDI, dword ptr [EAX + 0x28]
    s.di = m.r32((s.ax+0x00000028u));
  }
  L0044523a: { // 0x44523a: 8d44241c LEA EAX, [ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0044523e: { // 0x44523e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044523f: { // 0x44523f: 897c2418 MOV dword ptr [ESP + 0x18], EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L00445243: { // 0x445243: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4477513u); flags=s.arithmetic_flags;
  }
  L00445249: { // 0x445249: 668b08 MOV CX, word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L0044524c: { // 0x44524c: 668b4002 MOV AX, word ptr [EAX + 2]
    s.ax = with_ax(s.ax, m.r16((s.ax+2u)));
  }
  L00445250: { // 0x445250: 6603442416 ADD AX, word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L00445255: { // 0x445255: 6603cf ADD CX, DI
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L00445258: { // 0x445258: 66894c2410 MOV word ptr [ESP + 0x10], CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0044525d: { // 0x44525d: 6689442412 MOV word ptr [ESP + 0x12], AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00445262: { // 0x445262: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00445266: { // 0x445266: 6689442412 MOV word ptr [ESP + 0x12], AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L0044526b: { // 0x44526b: 8d4aff LEA ECX, [EDX - 1]
    s.cx = (s.dx-1u);
  }
  L0044526e: { // 0x44526e: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00445271: { // 0x445271: 66894c2410 MOV word ptr [ESP + 0x10], CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00445276: { // 0x445276: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0044527a: { // 0x44527a: 0fbfc9 MOVSX ECX, CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0044527d: { // 0x44527d: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L00445280: { // 0x445280: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L00445283: { // 0x445283: 0580000000 ADD EAX, 0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00445288: { // 0x445288: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0044528e: { // 0x44528e: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00445292: { // 0x445292: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00445296: { // 0x445296: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0044529a: { // 0x44529a: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0044529c: { // 0x44529c: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004452a0: { // 0x4452a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004452a1: { // 0x4452a1: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004452a6: { // 0x4452a6: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004452aa: { // 0x4452aa: e851021000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4477615u); flags=s.arithmetic_flags;
  }
  L004452af: { // 0x4452af: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004452b0: { // 0x4452b0: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004452b4: { // 0x4452b4: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L004452b6: { // 0x4452b6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004452b7: { // 0x4452b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004452b8: { // 0x4452b8: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L004452ba: { // 0x4452ba: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L004452be: { // 0x4452be: 895c242c MOV dword ptr [ESP + 0x2c], EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L004452c2: { // 0x4452c2: e899bf0200 CALL 0x471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4477639u); flags=s.arithmetic_flags;
  }
  L004452c7: { // 0x4452c7: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004452c9: { // 0x4452c9: 0f849c000000 JZ 0x44536b
    if(integer::condition("JZ",flags)) goto L0044536b;
  }
  L004452cf: { // 0x4452cf: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004452d1: { // 0x4452d1: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004452d3: { // 0x4452d3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4477657u); flags=s.arithmetic_flags;
  }
  L004452d9: { // 0x4452d9: 83c024 ADD EAX, 0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L004452dc: { // 0x4452dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004452dd: { // 0x4452dd: 6830a97b00 PUSH 0x7ba930
    f.push(m,0x007ba930u);
  }
  L004452e2: { // 0x4452e2: e80916fcff CALL 0x4068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4477671u); flags=s.arithmetic_flags;
  }
  L004452e7: { // 0x4452e7: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004452ea: { // 0x4452ea: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L004452ec: { // 0x4452ec: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004452ed: { // 0x4452ed: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004452ef: { // 0x4452ef: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004452f1: { // 0x4452f1: 6878708300 PUSH 0x837078
    f.push(m,0x00837078u);
  }
  L004452f6: { // 0x4452f6: e825120300 CALL 0x476520
    s.arithmetic_flags=flags; invoke(m,s,f,0x00476520u,4477691u); flags=s.arithmetic_flags;
  }
  L004452fb: { // 0x4452fb: 895c2410 MOV dword ptr [ESP + 0x10], EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L004452ff: { // 0x4452ff: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00445303: { // 0x445303: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00445305: { // 0x445305: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00445306: { // 0x445306: e8b5130300 CALL 0x4766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,4477707u); flags=s.arithmetic_flags;
  }
  L0044530b: { // 0x44530b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044530c: { // 0x44530c: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00445310: { // 0x445310: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00445312: { // 0x445312: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00445313: { // 0x445313: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00445314: { // 0x445314: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00445316: { // 0x445316: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L0044531a: { // 0x44531a: 895c242c MOV dword ptr [ESP + 0x2c], EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0044531e: { // 0x44531e: e83dbf0200 CALL 0x471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4477731u); flags=s.arithmetic_flags;
  }
  L00445323: { // 0x445323: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00445325: { // 0x445325: 742c JZ 0x445353
    if(integer::condition("JZ",flags)) goto L00445353;
  }
  L00445327: { // 0x445327: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00445329: { // 0x445329: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044532b: { // 0x44532b: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4477745u); flags=s.arithmetic_flags;
  }
  L00445331: { // 0x445331: 83c024 ADD EAX, 0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L00445334: { // 0x445334: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00445335: { // 0x445335: 6804a97b00 PUSH 0x7ba904
    f.push(m,0x007ba904u);
  }
  L0044533a: { // 0x44533a: e8b115fcff CALL 0x4068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4477759u); flags=s.arithmetic_flags;
  }
  L0044533f: { // 0x44533f: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00445342: { // 0x445342: 8d442424 LEA EAX, [ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L00445346: { // 0x445346: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00445348: { // 0x445348: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00445349: { // 0x445349: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044534b: { // 0x44534b: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044534d: { // 0x44534d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044534e: { // 0x44534e: e8cd110300 CALL 0x476520
    s.arithmetic_flags=flags; invoke(m,s,f,0x00476520u,4477779u); flags=s.arithmetic_flags;
  }
  L00445353: { // 0x445353: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00445357: { // 0x445357: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00445358: { // 0x445358: 83f808 CMP EAX, 8
    (void)integer::sub(s.ax,8u,32,flags);
  }
  L0044535b: { // 0x44535b: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0044535f: { // 0x44535f: 7c9e JL 0x4452ff
    if(integer::condition("JL",flags)) goto L004452ff;
  }
  L00445361: { // 0x445361: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00445362: { // 0x445362: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00445363: { // 0x445363: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00445364: { // 0x445364: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00445366: { // 0x445366: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00445367: { // 0x445367: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0044536a: { // 0x44536a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0044536b: { // 0x44536b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044536c: { // 0x44536c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044536d: { // 0x44536d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044536e: { // 0x44536e: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00445370: { // 0x445370: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00445371: { // 0x445371: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00445374: { // 0x445374: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b320: { // 0x41b320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041b321: { // 0x41b321: 8b8188000000 MOV EAX, dword ptr [ECX + 0x88]
    s.ax = m.r32((s.cx+0x00000088u));
  }
  L0041b327: { // 0x41b327: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b328: { // 0x41b328: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b32e: { // 0x41b32e: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b330: { // 0x41b330: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b333: { // 0x41b333: 6689442400 MOV word ptr [ESP], AX
    m.w16((f.sp), (s.ax & 0xffffu));
  }
  L0041b338: { // 0x41b338: 8b818c000000 MOV EAX, dword ptr [ECX + 0x8c]
    s.ax = m.r32((s.cx+0x0000008cu));
  }
  L0041b33e: { // 0x41b33e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b33f: { // 0x41b33f: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b345: { // 0x41b345: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b347: { // 0x41b347: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b34a: { // 0x41b34a: 6689442402 MOV word ptr [ESP + 2], AX
    m.w16((f.sp+2u), (s.ax & 0xffffu));
  }
  L0041b34f: { // 0x41b34f: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0041b353: { // 0x41b353: 8b4c2400 MOV ECX, dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0041b357: { // 0x41b357: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L0041b359: { // 0x41b359: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041b35a: { // 0x41b35a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX, word ptr [EDX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+2u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI, word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX, dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00071260(Memory& m,State& s,Frame& f,const Operations& op) { if(m.r8(f.sp+8u)!=0u||m.r32(s.cx+0xe4u)!=0u)throw std::domain_error("B1514 supports71260 zero-list only");
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00471260: { // 0x471260: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00471261: { // 0x471261: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L00471263: { // 0x471263: 83e4f8 AND ESP, 0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00471266: { // 0x471266: 83ec34 SUB ESP, 0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00471269: { // 0x471269: 8b5508 MOV EDX, dword ptr [EBP + 8]
    s.dx = m.r32((s.bp+8u));
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
  L0047126f: { // 0x47126f: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00471271: { // 0x471271: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00471273: { // 0x471273: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471277: { // 0x471277: 89742418 MOV dword ptr [ESP + 0x18], ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0047127b: { // 0x47127b: 8d3cc500000000 LEA EDI, [EAX*8]
    s.di = ((s.ax * 8u));
  }
  L00471282: { // 0x471282: 2bf8 SUB EDI, EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00471284: { // 0x471284: 8b4204 MOV EAX, dword ptr [EDX + 4]
    s.ax = m.r32((s.dx+4u));
  }
  L00471287: { // 0x471287: 8d1cc500000000 LEA EBX, [EAX*8]
    s.bx = ((s.ax * 8u));
  }
  L0047128e: { // 0x47128e: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00471290: { // 0x471290: 8a450c MOV AL, byte ptr [EBP + 0xc]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000000cu)));
  }
  L00471293: { // 0x471293: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471295: { // 0x471295: 7408 JZ 0x47129f
    if(integer::condition("JZ",flags)) goto L0047129f;
  }
  L00471297: { // 0x471297: 8b89e8000000 MOV ECX, dword ptr [ECX + 0xe8]
    s.cx = m.r32((s.cx+0x000000e8u));
  }
  L0047129d: { // 0x47129d: eb06 JMP 0x4712a5
    goto L004712a5;
  }
  L0047129f: { // 0x47129f: 8b89e4000000 MOV ECX, dword ptr [ECX + 0xe4]
    s.cx = m.r32((s.cx+0x000000e4u));
  }
  L004712a5: { // 0x4712a5: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L004712a7: { // 0x4712a7: 0f84a2000000 JZ 0x47134f
    if(integer::condition("JZ",flags)) goto L0047134f;
  }
  L004712ad: { // 0x4712ad: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004712af: { // 0x4712af: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004712b1: { // 0x4712b1: 0f8480000000 JZ 0x471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712b7: { // 0x4712b7: 8a4614 MOV AL, byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L004712ba: { // 0x4712ba: 2401 AND AL, 1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(1u),8,flags));
  }
  L004712bc: { // 0x4712bc: 88442413 MOV byte ptr [ESP + 0x13], AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L004712c0: { // 0x4712c0: 7475 JZ 0x471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c2: { // 0x4712c2: 3b7510 CMP ESI, dword ptr [EBP + 0x10]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  L004712c5: { // 0x4712c5: 7470 JZ 0x471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c7: { // 0x4712c7: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004712c9: { // 0x4712c9: 8d442428 LEA EAX, [ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L004712cd: { // 0x4712cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004712ce: { // 0x4712ce: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004712d0: { // 0x4712d0: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4657875u); flags=s.arithmetic_flags;
  }
  L004712d3: { // 0x4712d3: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004712d5: { // 0x4712d5: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L004712d8: { // 0x4712d8: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004712da: { // 0x4712da: 25ff000000 AND EAX, 0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004712df: { // 0x4712df: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L004712e2: { // 0x4712e2: 2bc7 SUB EAX, EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004712e4: { // 0x4712e4: 81e1ff000000 AND ECX, 0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004712ea: { // 0x4712ea: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004712ee: { // 0x4712ee: 2bcb SUB ECX, EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L004712f0: { // 0x4712f0: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L004712f3: { // 0x4712f3: 894c2428 MOV dword ptr [ESP + 0x28], ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L004712f7: { // 0x4712f7: 89542444 MOV dword ptr [ESP + 0x44], EDX
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
  L00471303: { // 0x471303: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00471305: { // 0x471305: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00471307: { // 0x471307: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00471309: { // 0x471309: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0047130b: { // 0x47130b: dec1 FADDP ST1
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0047130d: { // 0x47130d: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00471310: { // 0x471310: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471312: { // 0x471312: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471314: { // 0x471314: e8678d0400 CALL 0x4ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4657945u); flags=s.arithmetic_flags;
  }
  L00471319: { // 0x471319: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0047131c: { // 0x47131c: e82f972f00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4657953u); flags=s.arithmetic_flags;
  }
  L00471321: { // 0x471321: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00471325: { // 0x471325: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00471327: { // 0x471327: 7406 JZ 0x47132f
    if(integer::condition("JZ",flags)) goto L0047132f;
  }
  L00471329: { // 0x471329: 3b442418 CMP EAX, dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0047132d: { // 0x47132d: 7d08 JGE 0x471337
    if(integer::condition("JGE",flags)) goto L00471337;
  }
  L0047132f: { // 0x47132f: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471333: { // 0x471333: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00471337: { // 0x471337: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047133a: { // 0x47133a: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047133c: { // 0x47133c: 0f8575ffffff JNZ 0x4712b7
    if(integer::condition("JNZ",flags)) goto L004712b7;
  }
  L00471342: { // 0x471342: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
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
  L00471349: { // 0x471349: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L0047134b: { // 0x47134b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047134c: { // 0x47134c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047134f: { // 0x47134f: 8bc6 MOV EAX, ESI
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
  L00471354: { // 0x471354: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L00471356: { // 0x471356: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471357: { // 0x471357: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x62fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x62fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX, EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI, 0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX, 0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x62fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x62fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI, EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x62fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP, 0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP, CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX, [EDI + 1]
    s.ax = (s.di+1u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x62fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX], 0
    (void)integer::sub(m.r8((s.dx)),0u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x62fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x62fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI, dword ptr [EDX + ECX*4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 4u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX, [EDX + ECX*4 + 0xc]
    s.ax = (s.dx+(s.cx * 4u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX, dword ptr [EDX + ECX*4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 4u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI, ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX], ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX, dword ptr [EDX + 4]
    s.ax = m.r32((s.dx+4u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI, dword ptr [EDX + EAX*4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 4u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX, 0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 4], EAX
    m.w32((s.dx+4u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x62fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 4], 0
    m.w32((s.dx+4u), 0u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX, 0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x62fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 8], 0
    m.w32((s.dx+8u), 0u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX, EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x62fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4428912u:f_00039470(m,s,child,{});break;
case 4477456u:f_00045210(m,s,child,{});break;
case 4305696u:f_0001b320(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4657760u:f_00071260(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
default:throw std::domain_error("recovery1514 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1514 no reviewed tail"); } }

std::uint32_t fun_00439470(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00439470: { // 0x439470: 83ec2c SUB ESP, 0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L00439473: { // 0x439473: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00439478: { // 0x439478: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00439479: { // 0x439479: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043947a: { // 0x43947a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043947b: { // 0x43947b: 8b8044020000 MOV EAX, dword ptr [EAX + 0x244]
    s.ax = m.r32((s.ax+0x00000244u));
  }
  L00439481: { // 0x439481: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00439482: { // 0x439482: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00439484: { // 0x439484: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00439486: { // 0x439486: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0043948a: { // 0x43948a: 0f84a2010000 JZ 0x439632
    if(integer::condition("JZ",flags)) goto L00439632;
  }
  L00439490: { // 0x439490: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00439496: { // 0x439496: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00439497: { // 0x439497: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00439498: { // 0x439498: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043949a: { // 0x43949a: 81c118020000 ADD ECX, 0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L004394a0: { // 0x4394a0: e89b691f00 CALL 0x62fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4428965u); flags=s.arithmetic_flags;
  }
  L004394a5: { // 0x4394a5: 8dbe9c040000 LEA EDI, [ESI + 0x49c]
    s.di = (s.si+0x0000049cu);
  }
  L004394ab: { // 0x4394ab: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004394af: { // 0x4394af: bd78120000 MOV EBP, 0x1278
    s.bp = 0x00001278u;
  }
  L004394b4: { // 0x4394b4: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L004394b8: { // 0x4394b8: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L004394be: { // 0x4394be: 8b0c2a MOV ECX, dword ptr [EDX + EBP]
    s.cx = m.r32((s.dx+s.bp));
  }
  L004394c1: { // 0x4394c1: 8d042a LEA EAX, [EDX + EBP]
    s.ax = (s.dx+s.bp);
  }
  L004394c4: { // 0x4394c4: 3b0d78708300 CMP ECX, dword ptr [0x837078]
    (void)integer::sub(s.cx,m.r32((0x00837078u)),32,flags);
  }
  L004394ca: { // 0x4394ca: 7511 JNZ 0x4394dd
    if(integer::condition("JNZ",flags)) goto L004394dd;
  }
  L004394cc: { // 0x4394cc: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L004394cf: { // 0x4394cf: 8b0d7c708300 MOV ECX, dword ptr [0x83707c]
    s.cx = m.r32((0x0083707cu));
  }
  L004394d5: { // 0x4394d5: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L004394d7: { // 0x4394d7: 0f8455010000 JZ 0x439632
    if(integer::condition("JZ",flags)) goto L00439632;
  }
  L004394dd: { // 0x4394dd: 833f00 CMP dword ptr [EDI], 0
    (void)integer::sub(m.r32((s.di)),0u,32,flags);
  }
  L004394e0: { // 0x4394e0: 0f854c010000 JNZ 0x439632
    if(integer::condition("JNZ",flags)) goto L00439632;
  }
  L004394e6: { // 0x4394e6: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L004394ec: { // 0x4394ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004394ed: { // 0x4394ed: 8d442420 LEA EAX, [ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L004394f1: { // 0x4394f1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004394f2: { // 0x4394f2: e849ea2500 CALL 0x697f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697f40u,4429047u); flags=s.arithmetic_flags;
  }
  L004394f7: { // 0x4394f7: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004394f9: { // 0x4394f9: 8b4004 MOV EAX, dword ptr [EAX + 4]
    s.ax = m.r32((s.ax+4u));
  }
  L004394fc: { // 0x4394fc: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004394fe: { // 0x4394fe: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00439502: { // 0x439502: 8954242c MOV dword ptr [ESP + 0x2c], EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00439506: { // 0x439506: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00439508: { // 0x439508: 8d442430 LEA EAX, [ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0043950c: { // 0x43950c: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00439510: { // 0x439510: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00439511: { // 0x439511: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00439513: { // 0x439513: ff92a8000000 CALL dword ptr [EDX + 0xa8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a8u)),4429081u); flags=s.arithmetic_flags;
  }
  L00439519: { // 0x439519: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0043951b: { // 0x43951b: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0043951f: { // 0x43951f: 8b5c2428 MOV EBX, dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L00439523: { // 0x439523: 03d1 ADD EDX, ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00439525: { // 0x439525: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00439529: { // 0x439529: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0043952d: { // 0x43952d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L00439530: { // 0x439530: 68a8010000 PUSH 0x1a8
    f.push(m,0x000001a8u);
  }
  L00439535: { // 0x439535: 03da ADD EBX, EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00439537: { // 0x439537: 895c242c MOV dword ptr [ESP + 0x2c], EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0043953b: { // 0x43953b: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L0043953e: { // 0x43953e: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00439540: { // 0x439540: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00439544: { // 0x439544: e80e443300 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4429129u); flags=s.arithmetic_flags;
  }
  L00439549: { // 0x439549: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0043954c: { // 0x43954c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043954e: { // 0x43954e: 0f84c4000000 JZ 0x439618
    if(integer::condition("JZ",flags)) goto L00439618;
  }
  L00439554: { // 0x439554: 8b15881b8200 MOV EDX, dword ptr [0x821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L0043955a: { // 0x43955a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043955c: { // 0x43955c: 6800060000 PUSH 0x600
    f.push(m,0x00000600u);
  }
  L00439561: { // 0x439561: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00439563: { // 0x439563: 8d4c2430 LEA ECX, [ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00439567: { // 0x439567: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00439569: { // 0x439569: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043956a: { // 0x43956a: 8b8a38020000 MOV ECX, dword ptr [EDX + 0x238]
    s.cx = m.r32((s.dx+0x00000238u));
  }
  L00439570: { // 0x439570: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00439574: { // 0x439574: 8b0c91 MOV ECX, dword ptr [ECX + EDX*4]
    s.cx = m.r32((s.cx+(s.dx * 4u)));
  }
  L00439577: { // 0x439577: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00439578: { // 0x439578: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043957a: { // 0x43957a: e8916bfeff CALL 0x420110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00420110u,4429183u); flags=s.arithmetic_flags;
  }
  L0043957f: { // 0x43957f: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L00439581: { // 0x439581: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00439583: { // 0x439583: 0f848f000000 JZ 0x439618
    if(integer::condition("JZ",flags)) goto L00439618;
  }
  L00439589: { // 0x439589: 891f MOV dword ptr [EDI], EBX
    m.w32((s.di), s.bx);
  }
  L0043958b: { // 0x43958b: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00439591: { // 0x439591: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00439593: { // 0x439593: e828f00100 CALL 0x4585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4429208u); flags=s.arithmetic_flags;
  }
  L00439598: { // 0x439598: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043959e: { // 0x43959e: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004395a0: { // 0x4395a0: e80bf00100 CALL 0x4585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4429221u); flags=s.arithmetic_flags;
  }
  L004395a5: { // 0x4395a5: 03f8 ADD EDI, EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L004395a7: { // 0x4395a7: 8d047f LEA EAX, [EDI + EDI*2]
    s.ax = (s.di+(s.di * 2u));
  }
  L004395aa: { // 0x4395aa: 8d1480 LEA EDX, [EAX + EAX*4]
    s.dx = (s.ax+(s.ax * 4u));
  }
  L004395ad: { // 0x4395ad: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004395b3: { // 0x4395b3: 8b442804 MOV EAX, dword ptr [EAX + EBP + 4]
    s.ax = m.r32((s.ax+s.bp+4u));
  }
  L004395b7: { // 0x4395b7: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004395b9: { // 0x4395b9: 8d0c40 LEA ECX, [EAX + EAX*2]
    s.cx = (s.ax+(s.ax * 2u));
  }
  L004395bc: { // 0x4395bc: d1f9 SAR ECX, 1
    s.cx = integer::shift(s.cx,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L004395be: { // 0x4395be: 8d41f6 LEA EAX, [ECX - 0xa]
    s.ax = (s.cx-0x0000000au);
  }
  L004395c1: { // 0x4395c1: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004395c3: { // 0x4395c3: 8983e8000000 MOV dword ptr [EBX + 0xe8], EAX
    m.w32((s.bx+0x000000e8u), s.ax);
  }
  L004395c9: { // 0x4395c9: 7e0a JLE 0x4395d5
    if(integer::condition("JLE",flags)) goto L004395d5;
  }
  L004395cb: { // 0x4395cb: c783e800000000000000 MOV dword ptr [EBX + 0xe8], 0
    m.w32((s.bx+0x000000e8u), 0u);
  }
  L004395d5: { // 0x4395d5: 8b93b0000000 MOV EDX, dword ptr [EBX + 0xb0]
    s.dx = m.r32((s.bx+0x000000b0u));
  }
  L004395db: { // 0x4395db: 8b8288020000 MOV EAX, dword ptr [EDX + 0x288]
    s.ax = m.r32((s.dx+0x00000288u));
  }
  L004395e1: { // 0x4395e1: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004395e3: { // 0x4395e3: 7e1a JLE 0x4395ff
    if(integer::condition("JLE",flags)) goto L004395ff;
  }
  L004395e5: { // 0x4395e5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004395e6: { // 0x4395e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004395e7: { // 0x4395e7: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004395ec: { // 0x4395ec: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004395ee: { // 0x4395ee: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L004395f4: { // 0x4395f4: e847681f00 CALL 0x62fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4429305u); flags=s.arithmetic_flags;
  }
  L004395f9: { // 0x4395f9: 898398000000 MOV dword ptr [EBX + 0x98], EAX
    m.w32((s.bx+0x00000098u), s.ax);
  }
  L004395ff: { // 0x4395ff: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00439603: { // 0x439603: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00439607: { // 0x439607: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00439608: { // 0x439608: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043960a: { // 0x43960a: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0043960e: { // 0x43960e: 7c08 JL 0x439618
    if(integer::condition("JL",flags)) goto L00439618;
  }
  L00439610: { // 0x439610: c744241000000000 MOV dword ptr [ESP + 0x10], 0
    m.w32((f.sp+0x00000010u), 0u);
  }
  L00439618: { // 0x439618: 8b7c2414 MOV EDI, dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0043961c: { // 0x43961c: 83c508 ADD EBP, 8
    s.bp = integer::add(s.bp,8u,32,flags);
  }
  L0043961f: { // 0x43961f: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L00439622: { // 0x439622: 81fdb8120000 CMP EBP, 0x12b8
    (void)integer::sub(s.bp,0x000012b8u,32,flags);
  }
  L00439628: { // 0x439628: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0043962c: { // 0x43962c: 0f8c86feffff JL 0x4394b8
    if(integer::condition("JL",flags)) goto L004394b8;
  }
  L00439632: { // 0x439632: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00439633: { // 0x439633: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00439634: { // 0x439634: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00439635: { // 0x439635: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00439636: { // 0x439636: 83c42c ADD ESP, 0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L00439639: { // 0x439639: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00445210(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00445210: { // 0x445210: 83ec20 SUB ESP, 0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00445213: { // 0x445213: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00445214: { // 0x445214: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00445215: { // 0x445215: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00445216: { // 0x445216: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00445218: { // 0x445218: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044521a: { // 0x44521a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044521b: { // 0x44521b: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00445221: { // 0x445221: 389857130000 CMP byte ptr [EAX + 0x1357], BL
    (void)integer::sub(m.r8((s.ax+0x00001357u)),(s.bx & 0xffu),8,flags);
  }
  L00445227: { // 0x445227: 0f843e010000 JZ 0x44536b
    if(integer::condition("JZ",flags)) goto L0044536b;
  }
  L0044522d: { // 0x44522d: 8b80600c0000 MOV EAX, dword ptr [EAX + 0xc60]
    s.ax = m.r32((s.ax+0x00000c60u));
  }
  L00445233: { // 0x445233: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00445235: { // 0x445235: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00445237: { // 0x445237: 8b7828 MOV EDI, dword ptr [EAX + 0x28]
    s.di = m.r32((s.ax+0x00000028u));
  }
  L0044523a: { // 0x44523a: 8d44241c LEA EAX, [ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0044523e: { // 0x44523e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044523f: { // 0x44523f: 897c2418 MOV dword ptr [ESP + 0x18], EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L00445243: { // 0x445243: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4477513u); flags=s.arithmetic_flags;
  }
  L00445249: { // 0x445249: 668b08 MOV CX, word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L0044524c: { // 0x44524c: 668b4002 MOV AX, word ptr [EAX + 2]
    s.ax = with_ax(s.ax, m.r16((s.ax+2u)));
  }
  L00445250: { // 0x445250: 6603442416 ADD AX, word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L00445255: { // 0x445255: 6603cf ADD CX, DI
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L00445258: { // 0x445258: 66894c2410 MOV word ptr [ESP + 0x10], CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0044525d: { // 0x44525d: 6689442412 MOV word ptr [ESP + 0x12], AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00445262: { // 0x445262: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00445266: { // 0x445266: 6689442412 MOV word ptr [ESP + 0x12], AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L0044526b: { // 0x44526b: 8d4aff LEA ECX, [EDX - 1]
    s.cx = (s.dx-1u);
  }
  L0044526e: { // 0x44526e: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00445271: { // 0x445271: 66894c2410 MOV word ptr [ESP + 0x10], CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00445276: { // 0x445276: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0044527a: { // 0x44527a: 0fbfc9 MOVSX ECX, CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0044527d: { // 0x44527d: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L00445280: { // 0x445280: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L00445283: { // 0x445283: 0580000000 ADD EAX, 0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00445288: { // 0x445288: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0044528e: { // 0x44528e: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00445292: { // 0x445292: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00445296: { // 0x445296: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0044529a: { // 0x44529a: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0044529c: { // 0x44529c: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004452a0: { // 0x4452a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004452a1: { // 0x4452a1: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004452a6: { // 0x4452a6: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004452aa: { // 0x4452aa: e851021000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4477615u); flags=s.arithmetic_flags;
  }
  L004452af: { // 0x4452af: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004452b0: { // 0x4452b0: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004452b4: { // 0x4452b4: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L004452b6: { // 0x4452b6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004452b7: { // 0x4452b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004452b8: { // 0x4452b8: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L004452ba: { // 0x4452ba: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L004452be: { // 0x4452be: 895c242c MOV dword ptr [ESP + 0x2c], EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L004452c2: { // 0x4452c2: e899bf0200 CALL 0x471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4477639u); flags=s.arithmetic_flags;
  }
  L004452c7: { // 0x4452c7: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004452c9: { // 0x4452c9: 0f849c000000 JZ 0x44536b
    if(integer::condition("JZ",flags)) goto L0044536b;
  }
  L004452cf: { // 0x4452cf: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004452d1: { // 0x4452d1: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004452d3: { // 0x4452d3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4477657u); flags=s.arithmetic_flags;
  }
  L004452d9: { // 0x4452d9: 83c024 ADD EAX, 0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L004452dc: { // 0x4452dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004452dd: { // 0x4452dd: 6830a97b00 PUSH 0x7ba930
    f.push(m,0x007ba930u);
  }
  L004452e2: { // 0x4452e2: e80916fcff CALL 0x4068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4477671u); flags=s.arithmetic_flags;
  }
  L004452e7: { // 0x4452e7: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004452ea: { // 0x4452ea: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L004452ec: { // 0x4452ec: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004452ed: { // 0x4452ed: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004452ef: { // 0x4452ef: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004452f1: { // 0x4452f1: 6878708300 PUSH 0x837078
    f.push(m,0x00837078u);
  }
  L004452f6: { // 0x4452f6: e825120300 CALL 0x476520
    s.arithmetic_flags=flags; invoke(m,s,f,0x00476520u,4477691u); flags=s.arithmetic_flags;
  }
  L004452fb: { // 0x4452fb: 895c2410 MOV dword ptr [ESP + 0x10], EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L004452ff: { // 0x4452ff: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00445303: { // 0x445303: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00445305: { // 0x445305: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00445306: { // 0x445306: e8b5130300 CALL 0x4766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,4477707u); flags=s.arithmetic_flags;
  }
  L0044530b: { // 0x44530b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044530c: { // 0x44530c: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00445310: { // 0x445310: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00445312: { // 0x445312: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00445313: { // 0x445313: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00445314: { // 0x445314: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00445316: { // 0x445316: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L0044531a: { // 0x44531a: 895c242c MOV dword ptr [ESP + 0x2c], EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0044531e: { // 0x44531e: e83dbf0200 CALL 0x471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4477731u); flags=s.arithmetic_flags;
  }
  L00445323: { // 0x445323: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00445325: { // 0x445325: 742c JZ 0x445353
    if(integer::condition("JZ",flags)) goto L00445353;
  }
  L00445327: { // 0x445327: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00445329: { // 0x445329: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044532b: { // 0x44532b: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4477745u); flags=s.arithmetic_flags;
  }
  L00445331: { // 0x445331: 83c024 ADD EAX, 0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L00445334: { // 0x445334: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00445335: { // 0x445335: 6804a97b00 PUSH 0x7ba904
    f.push(m,0x007ba904u);
  }
  L0044533a: { // 0x44533a: e8b115fcff CALL 0x4068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4477759u); flags=s.arithmetic_flags;
  }
  L0044533f: { // 0x44533f: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00445342: { // 0x445342: 8d442424 LEA EAX, [ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L00445346: { // 0x445346: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00445348: { // 0x445348: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00445349: { // 0x445349: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044534b: { // 0x44534b: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044534d: { // 0x44534d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044534e: { // 0x44534e: e8cd110300 CALL 0x476520
    s.arithmetic_flags=flags; invoke(m,s,f,0x00476520u,4477779u); flags=s.arithmetic_flags;
  }
  L00445353: { // 0x445353: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00445357: { // 0x445357: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00445358: { // 0x445358: 83f808 CMP EAX, 8
    (void)integer::sub(s.ax,8u,32,flags);
  }
  L0044535b: { // 0x44535b: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0044535f: { // 0x44535f: 7c9e JL 0x4452ff
    if(integer::condition("JL",flags)) goto L004452ff;
  }
  L00445361: { // 0x445361: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00445362: { // 0x445362: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00445363: { // 0x445363: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00445364: { // 0x445364: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00445366: { // 0x445366: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00445367: { // 0x445367: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0044536a: { // 0x44536a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0044536b: { // 0x44536b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044536c: { // 0x44536c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044536d: { // 0x44536d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044536e: { // 0x44536e: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00445370: { // 0x445370: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00445371: { // 0x445371: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00445374: { // 0x445374: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
