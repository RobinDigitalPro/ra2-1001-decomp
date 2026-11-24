#include "recovered/recovery_b108_machine.hpp"
#include "recovered/map_b87.hpp"
#include "recovered/recovery_b460.hpp"
#include <stdexcept>
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_primitives.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::global_b26 {
std::uint32_t fun_0058a810(Memory&,const Inputs&); std::uint32_t fun_0056b760(Memory&,const Inputs&);
std::uint32_t fun_00545500(Memory&,const Inputs&); std::uint32_t fun_00572ad0(Memory&,const Inputs&);
}
namespace ra2::recovered::map516 {
using namespace ra2::recovered::recovery_b108;
namespace integer=direct_b33::integer;
static std::uint32_t b516_pc=0;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00171720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00571720: { // 0x571720: 83ec2c SUB ESP,0x2c
    b516_pc=0x571720u;
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L00571723: { // 0x571723: 53 PUSH EBX
    b516_pc=0x571723u;
    f.push(m,s.bx);
  }
  L00571724: { // 0x571724: 55 PUSH EBP
    b516_pc=0x571724u;
    f.push(m,s.bp);
  }
  L00571725: { // 0x571725: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    b516_pc=0x571725u;
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L00571729: { // 0x571729: 56 PUSH ESI
    b516_pc=0x571729u;
    f.push(m,s.si);
  }
  L0057172a: { // 0x57172a: 57 PUSH EDI
    b516_pc=0x57172au;
    f.push(m,s.di);
  }
  L0057172b: { // 0x57172b: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    b516_pc=0x57172bu;
    s.di = m.r32((f.sp+0x00000040u));
  }
  L0057172f: { // 0x57172f: 0fbf5d00 MOVSX EBX,word ptr [EBP]
    b516_pc=0x57172fu;
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00571733: { // 0x571733: 0fbf07 MOVSX EAX,word ptr [EDI]
    b516_pc=0x571733u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00571736: { // 0x571736: 2bc3 SUB EAX,EBX
    b516_pc=0x571736u;
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00571738: { // 0x571738: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    b516_pc=0x571738u;
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0057173c: { // 0x57173c: 83f803 CMP EAX,0x3
    b516_pc=0x57173cu;
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L0057173f: { // 0x57173f: 0f8ce6040000 JL 0x00571c2b
    b516_pc=0x57173fu;
    if(integer::condition("JL",flags)) goto L00571c2b;
  }
  L00571745: { // 0x571745: 0fbf7502 MOVSX ESI,word ptr [EBP + 0x2]
    b516_pc=0x571745u;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00571749: { // 0x571749: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    b516_pc=0x571749u;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057174d: { // 0x57174d: 2bd6 SUB EDX,ESI
    b516_pc=0x57174du;
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0057174f: { // 0x57174f: 83fa03 CMP EDX,0x3
    b516_pc=0x57174fu;
    (void)integer::sub(s.dx,0x00000003u,32,flags);
  }
  L00571752: { // 0x571752: 0f8cd3040000 JL 0x00571c2b
    b516_pc=0x571752u;
    if(integer::condition("JL",flags)) goto L00571c2b;
  }
  L00571758: { // 0x571758: 83c00a ADD EAX,0xa
    b516_pc=0x571758u;
    s.ax = integer::add(s.ax,0x0000000au,32,flags);
  }
  L0057175b: { // 0x57175b: 83c20a ADD EDX,0xa
    b516_pc=0x57175bu;
    s.dx = integer::add(s.dx,0x0000000au,32,flags);
  }
  L0057175e: { // 0x57175e: 89442424 MOV dword ptr [ESP + 0x24],EAX
    b516_pc=0x57175eu;
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00571762: { // 0x571762: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x571762u;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00571766: { // 0x571766: 89542428 MOV dword ptr [ESP + 0x28],EDX
    b516_pc=0x571766u;
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0057176a: { // 0x57176a: 8d54241c LEA EDX,[ESP + 0x1c]
    b516_pc=0x57176au;
    s.dx = (f.sp+0x0000001cu);
  }
  L0057176e: { // 0x57176e: 83c3fe ADD EBX,-0x2
    b516_pc=0x57176eu;
    s.bx = integer::add(s.bx,0xfffffffeu,32,flags);
  }
  L00571771: { // 0x571771: 83c6f9 ADD ESI,-0x7
    b516_pc=0x571771u;
    s.si = integer::add(s.si,0xfffffff9u,32,flags);
  }
  L00571774: { // 0x571774: 50 PUSH EAX
    b516_pc=0x571774u;
    f.push(m,s.ax);
  }
  L00571775: { // 0x571775: 52 PUSH EDX
    b516_pc=0x571775u;
    f.push(m,s.dx);
  }
  L00571776: { // 0x571776: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    b516_pc=0x571776u;
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0057177a: { // 0x57177a: 89742428 MOV dword ptr [ESP + 0x28],ESI
    b516_pc=0x57177au;
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0057177e: { // 0x57177e: e87d0f0000 CALL 0x00572700
    b516_pc=0x57177eu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,0x00571783u); flags=0x202u;
  }
  L00571783: { // 0x571783: 84c0 TEST AL,AL
    b516_pc=0x571783u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571785: { // 0x571785: 0f84a0040000 JZ 0x00571c2b
    b516_pc=0x571785u;
    if(integer::condition("JZ",flags)) goto L00571c2b;
  }
  L0057178b: { // 0x57178b: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    b516_pc=0x57178bu;
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0057178f: { // 0x57178f: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    b516_pc=0x57178fu;
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00571793: { // 0x571793: 8bd8 MOV EBX,EAX
    b516_pc=0x571793u;
    s.bx = s.ax;
  }
  L00571795: { // 0x571795: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x571795u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00571799: { // 0x571799: 8d4807 LEA ECX,[EAX + 0x7]
    b516_pc=0x571799u;
    s.cx = (s.ax+0x00000007u);
  }
  L0057179c: { // 0x57179c: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    b516_pc=0x57179cu;
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L005717a0: { // 0x5717a0: 3bc1 CMP EAX,ECX
    b516_pc=0x5717a0u;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005717a2: { // 0x5717a2: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    b516_pc=0x5717a2u;
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005717a6: { // 0x5717a6: 7d79 JGE 0x00571821
    b516_pc=0x5717a6u;
    if(integer::condition("JGE",flags)) goto L00571821;
  }
  L005717a8: { // 0x5717a8: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    b516_pc=0x5717a8u;
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L005717ac: { // 0x5717ac: 03ce ADD ECX,ESI
    b516_pc=0x5717acu;
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005717ae: { // 0x5717ae: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x5717aeu;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L005717b2: { // 0x5717b2: 3b742440 CMP ESI,dword ptr [ESP + 0x40]
    b516_pc=0x5717b2u;
    (void)integer::sub(s.si,m.r32((f.sp+0x00000040u)),32,flags);
  }
  L005717b6: { // 0x5717b6: 7d5c JGE 0x00571814
    b516_pc=0x5717b6u;
    if(integer::condition("JGE",flags)) goto L00571814;
  }
  L005717b8: { // 0x5717b8: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x5717b8u;
    s.cx = (f.sp+0x00000044u);
  }
  L005717bc: { // 0x5717bc: 6689742444 MOV word ptr [ESP + 0x44],SI
    b516_pc=0x5717bcu;
    m.w16((f.sp+0x00000044u), (s.si & 0xffffu));
  }
  L005717c1: { // 0x5717c1: 66895c2446 MOV word ptr [ESP + 0x46],BX
    b516_pc=0x5717c1u;
    m.w16((f.sp+0x00000046u), (s.bx & 0xffffu));
  }
  L005717c6: { // 0x5717c6: e845900100 CALL 0x0058a810
    b516_pc=0x5717c6u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x005717cbu); flags=0x202u;
  }
  L005717cb: { // 0x5717cb: 84c0 TEST AL,AL
    b516_pc=0x5717cbu;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005717cd: { // 0x5717cd: 7434 JZ 0x00571803
    b516_pc=0x5717cdu;
    if(integer::condition("JZ",flags)) goto L00571803;
  }
  L005717cf: { // 0x5717cf: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    b516_pc=0x5717cfu;
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L005717d3: { // 0x5717d3: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x5717d3u;
    s.cx = (f.sp+0x00000044u);
  }
  L005717d7: { // 0x5717d7: e8849fffff CALL 0x0056b760
    b516_pc=0x5717d7u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x005717dcu); flags=0x202u;
  }
  L005717dc: { // 0x5717dc: 8d542444 LEA EDX,[ESP + 0x44]
    b516_pc=0x5717dcu;
    s.dx = (f.sp+0x00000044u);
  }
  L005717e0: { // 0x5717e0: b920a88100 MOV ECX,0x81a820
    b516_pc=0x5717e0u;
    s.cx = 0x0081a820u;
  }
  L005717e5: { // 0x5717e5: 52 PUSH EDX
    b516_pc=0x5717e5u;
    f.push(m,s.dx);
  }
  L005717e6: { // 0x5717e6: e8153dfdff CALL 0x00545500
    b516_pc=0x5717e6u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x005717ebu); flags=0x202u;
  }
  L005717eb: { // 0x5717eb: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    b516_pc=0x5717ebu;
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L005717ef: { // 0x5717ef: 8bd8 MOV EBX,EAX
    b516_pc=0x5717efu;
    s.bx = s.ax;
  }
  L005717f1: { // 0x5717f1: e8da120000 CALL 0x00572ad0
    b516_pc=0x5717f1u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,0x005717f6u); flags=0x202u;
  }
  L005717f6: { // 0x5717f6: 8a4010 MOV AL,byte ptr [EAX + 0x10]
    b516_pc=0x5717f6u;
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000010u)));
  }
  L005717f9: { // 0x5717f9: 88831b010000 MOV byte ptr [EBX + 0x11b],AL
    b516_pc=0x5717f9u;
    m.w8((s.bx+0x0000011bu), (s.ax & 0xffu));
  }
  L005717ff: { // 0x5717ff: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    b516_pc=0x5717ffu;
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00571803: { // 0x571803: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    b516_pc=0x571803u;
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00571807: { // 0x571807: 46 INC ESI
    b516_pc=0x571807u;
    s.si = integer::increment(s.si,32,flags);
  }
  L00571808: { // 0x571808: 3bf0 CMP ESI,EAX
    b516_pc=0x571808u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0057180a: { // 0x57180a: 7cac JL 0x005717b8
    b516_pc=0x57180au;
    if(integer::condition("JL",flags)) goto L005717b8;
  }
  L0057180c: { // 0x57180c: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    b516_pc=0x57180cu;
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00571810: { // 0x571810: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x571810u;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00571814: { // 0x571814: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    b516_pc=0x571814u;
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00571818: { // 0x571818: 43 INC EBX
    b516_pc=0x571818u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571819: { // 0x571819: 3bd9 CMP EBX,ECX
    b516_pc=0x571819u;
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0057181b: { // 0x57181b: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    b516_pc=0x57181bu;
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0057181f: { // 0x57181f: 7c91 JL 0x005717b2
    b516_pc=0x57181fu;
    if(integer::condition("JL",flags)) goto L005717b2;
  }
  L00571821: { // 0x571821: 0fbf37 MOVSX ESI,word ptr [EDI]
    b516_pc=0x571821u;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00571824: { // 0x571824: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    b516_pc=0x571824u;
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00571828: { // 0x571828: 46 INC ESI
    b516_pc=0x571828u;
    s.si = integer::increment(s.si,32,flags);
  }
  L00571829: { // 0x571829: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    b516_pc=0x571829u;
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0057182d: { // 0x57182d: 03c8 ADD ECX,EAX
    b516_pc=0x57182du;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0057182f: { // 0x57182f: 3bc1 CMP EAX,ECX
    b516_pc=0x57182fu;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00571831: { // 0x571831: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x571831u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00571835: { // 0x571835: 89442430 MOV dword ptr [ESP + 0x30],EAX
    b516_pc=0x571835u;
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00571839: { // 0x571839: 89442440 MOV dword ptr [ESP + 0x40],EAX
    b516_pc=0x571839u;
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0057183d: { // 0x57183d: 7d78 JGE 0x005718b7
    b516_pc=0x57183du;
    if(integer::condition("JGE",flags)) goto L005718b7;
  }
  L0057183f: { // 0x57183f: 8d4607 LEA EAX,[ESI + 0x7]
    b516_pc=0x57183fu;
    s.ax = (s.si+0x00000007u);
  }
  L00571842: { // 0x571842: 3bf0 CMP ESI,EAX
    b516_pc=0x571842u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00571844: { // 0x571844: 8bde MOV EBX,ESI
    b516_pc=0x571844u;
    s.bx = s.si;
  }
  L00571846: { // 0x571846: 7d58 JGE 0x005718a0
    b516_pc=0x571846u;
    if(integer::condition("JGE",flags)) goto L005718a0;
  }
  L00571848: { // 0x571848: 668b4c2440 MOV CX,word ptr [ESP + 0x40]
    b516_pc=0x571848u;
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000040u)));
  }
  L0057184d: { // 0x57184d: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x57184du;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00571852: { // 0x571852: 66894c2446 MOV word ptr [ESP + 0x46],CX
    b516_pc=0x571852u;
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L00571857: { // 0x571857: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571857u;
    s.cx = (f.sp+0x00000044u);
  }
  L0057185b: { // 0x57185b: e8b08f0100 CALL 0x0058a810
    b516_pc=0x57185bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00571860u); flags=0x202u;
  }
  L00571860: { // 0x571860: 84c0 TEST AL,AL
    b516_pc=0x571860u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571862: { // 0x571862: 7434 JZ 0x00571898
    b516_pc=0x571862u;
    if(integer::condition("JZ",flags)) goto L00571898;
  }
  L00571864: { // 0x571864: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    b516_pc=0x571864u;
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00571868: { // 0x571868: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571868u;
    s.cx = (f.sp+0x00000044u);
  }
  L0057186c: { // 0x57186c: e8ef9effff CALL 0x0056b760
    b516_pc=0x57186cu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571871u); flags=0x202u;
  }
  L00571871: { // 0x571871: 8d542444 LEA EDX,[ESP + 0x44]
    b516_pc=0x571871u;
    s.dx = (f.sp+0x00000044u);
  }
  L00571875: { // 0x571875: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571875u;
    s.cx = 0x0081a820u;
  }
  L0057187a: { // 0x57187a: 52 PUSH EDX
    b516_pc=0x57187au;
    f.push(m,s.dx);
  }
  L0057187b: { // 0x57187b: e8803cfdff CALL 0x00545500
    b516_pc=0x57187bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571880u); flags=0x202u;
  }
  L00571880: { // 0x571880: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    b516_pc=0x571880u;
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00571884: { // 0x571884: 8bf0 MOV ESI,EAX
    b516_pc=0x571884u;
    s.si = s.ax;
  }
  L00571886: { // 0x571886: e845120000 CALL 0x00572ad0
    b516_pc=0x571886u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,0x0057188bu); flags=0x202u;
  }
  L0057188b: { // 0x57188b: 8a4010 MOV AL,byte ptr [EAX + 0x10]
    b516_pc=0x57188bu;
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000010u)));
  }
  L0057188e: { // 0x57188e: 88861b010000 MOV byte ptr [ESI + 0x11b],AL
    b516_pc=0x57188eu;
    m.w8((s.si+0x0000011bu), (s.ax & 0xffu));
  }
  L00571894: { // 0x571894: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x571894u;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00571898: { // 0x571898: 43 INC EBX
    b516_pc=0x571898u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571899: { // 0x571899: 8d4607 LEA EAX,[ESI + 0x7]
    b516_pc=0x571899u;
    s.ax = (s.si+0x00000007u);
  }
  L0057189c: { // 0x57189c: 3bd8 CMP EBX,EAX
    b516_pc=0x57189cu;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0057189e: { // 0x57189e: 7ca8 JL 0x00571848
    b516_pc=0x57189eu;
    if(integer::condition("JL",flags)) goto L00571848;
  }
  L005718a0: { // 0x5718a0: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    b516_pc=0x5718a0u;
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L005718a4: { // 0x5718a4: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    b516_pc=0x5718a4u;
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L005718a8: { // 0x5718a8: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    b516_pc=0x5718a8u;
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L005718ac: { // 0x5718ac: 41 INC ECX
    b516_pc=0x5718acu;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005718ad: { // 0x5718ad: 03d3 ADD EDX,EBX
    b516_pc=0x5718adu;
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L005718af: { // 0x5718af: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x5718afu;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L005718b3: { // 0x5718b3: 3bca CMP ECX,EDX
    b516_pc=0x5718b3u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005718b5: { // 0x5718b5: 7c8b JL 0x00571842
    b516_pc=0x5718b5u;
    if(integer::condition("JL",flags)) goto L00571842;
  }
  L005718b7: { // 0x5718b7: 0fbf4d02 MOVSX ECX,word ptr [EBP + 0x2]
    b516_pc=0x5718b7u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L005718bb: { // 0x5718bb: 0fbf7500 MOVSX ESI,word ptr [EBP]
    b516_pc=0x5718bbu;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005718bf: { // 0x5718bf: 8d5102 LEA EDX,[ECX + 0x2]
    b516_pc=0x5718bfu;
    s.dx = (s.cx+0x00000002u);
  }
  L005718c2: { // 0x5718c2: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x5718c2u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L005718c6: { // 0x5718c6: 3bca CMP ECX,EDX
    b516_pc=0x5718c6u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005718c8: { // 0x5718c8: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x5718c8u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L005718cc: { // 0x5718cc: 89542418 MOV dword ptr [ESP + 0x18],EDX
    b516_pc=0x5718ccu;
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005718d0: { // 0x5718d0: 7d65 JGE 0x00571937
    b516_pc=0x5718d0u;
    if(integer::condition("JGE",flags)) goto L00571937;
  }
  L005718d2: { // 0x5718d2: 8d4601 LEA EAX,[ESI + 0x1]
    b516_pc=0x5718d2u;
    s.ax = (s.si+0x00000001u);
  }
  L005718d5: { // 0x5718d5: 3bf0 CMP ESI,EAX
    b516_pc=0x5718d5u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005718d7: { // 0x5718d7: 8bde MOV EBX,ESI
    b516_pc=0x5718d7u;
    s.bx = s.si;
  }
  L005718d9: { // 0x5718d9: 7d53 JGE 0x0057192e
    b516_pc=0x5718d9u;
    if(integer::condition("JGE",flags)) goto L0057192e;
  }
  L005718db: { // 0x5718db: 66894c2446 MOV word ptr [ESP + 0x46],CX
    b516_pc=0x5718dbu;
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L005718e0: { // 0x5718e0: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x5718e0u;
    s.cx = (f.sp+0x00000044u);
  }
  L005718e4: { // 0x5718e4: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x5718e4u;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L005718e9: { // 0x5718e9: e8228f0100 CALL 0x0058a810
    b516_pc=0x5718e9u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x005718eeu); flags=0x202u;
  }
  L005718ee: { // 0x5718ee: 84c0 TEST AL,AL
    b516_pc=0x5718eeu;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005718f0: { // 0x5718f0: 742c JZ 0x0057191e
    b516_pc=0x5718f0u;
    if(integer::condition("JZ",flags)) goto L0057191e;
  }
  L005718f2: { // 0x5718f2: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x5718f2u;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005718f6: { // 0x5718f6: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x5718f6u;
    s.cx = (f.sp+0x00000044u);
  }
  L005718fa: { // 0x5718fa: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x5718fau;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005718fd: { // 0x5718fd: e85e9effff CALL 0x0056b760
    b516_pc=0x5718fdu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571902u); flags=0x202u;
  }
  L00571902: { // 0x571902: 8d442444 LEA EAX,[ESP + 0x44]
    b516_pc=0x571902u;
    s.ax = (f.sp+0x00000044u);
  }
  L00571906: { // 0x571906: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571906u;
    s.cx = 0x0081a820u;
  }
  L0057190b: { // 0x57190b: 50 PUSH EAX
    b516_pc=0x57190bu;
    f.push(m,s.ax);
  }
  L0057190c: { // 0x57190c: e8ef3bfdff CALL 0x00545500
    b516_pc=0x57190cu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571911u); flags=0x202u;
  }
  L00571911: { // 0x571911: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x571911u;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L00571914: { // 0x571914: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x571914u;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00571918: { // 0x571918: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571918u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0057191e: { // 0x57191e: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    b516_pc=0x57191eu;
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00571922: { // 0x571922: 43 INC EBX
    b516_pc=0x571922u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571923: { // 0x571923: 8d4601 LEA EAX,[ESI + 0x1]
    b516_pc=0x571923u;
    s.ax = (s.si+0x00000001u);
  }
  L00571926: { // 0x571926: 3bd8 CMP EBX,EAX
    b516_pc=0x571926u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00571928: { // 0x571928: 7cb1 JL 0x005718db
    b516_pc=0x571928u;
    if(integer::condition("JL",flags)) goto L005718db;
  }
  L0057192a: { // 0x57192a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    b516_pc=0x57192au;
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0057192e: { // 0x57192e: 41 INC ECX
    b516_pc=0x57192eu;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057192f: { // 0x57192f: 3bca CMP ECX,EDX
    b516_pc=0x57192fu;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00571931: { // 0x571931: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571931u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00571935: { // 0x571935: 7c9e JL 0x005718d5
    b516_pc=0x571935u;
    if(integer::condition("JL",flags)) goto L005718d5;
  }
  L00571937: { // 0x571937: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    b516_pc=0x571937u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057193b: { // 0x57193b: 0fbf37 MOVSX ESI,word ptr [EDI]
    b516_pc=0x57193bu;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0057193e: { // 0x57193e: 8d5101 LEA EDX,[ECX + 0x1]
    b516_pc=0x57193eu;
    s.dx = (s.cx+0x00000001u);
  }
  L00571941: { // 0x571941: 4e DEC ESI
    b516_pc=0x571941u;
    s.si = integer::decrement(s.si,32,flags);
  }
  L00571942: { // 0x571942: 3bca CMP ECX,EDX
    b516_pc=0x571942u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00571944: { // 0x571944: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x571944u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00571948: { // 0x571948: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571948u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0057194c: { // 0x57194c: 89542418 MOV dword ptr [ESP + 0x18],EDX
    b516_pc=0x57194cu;
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00571950: { // 0x571950: 7d65 JGE 0x005719b7
    b516_pc=0x571950u;
    if(integer::condition("JGE",flags)) goto L005719b7;
  }
  L00571952: { // 0x571952: 8d4602 LEA EAX,[ESI + 0x2]
    b516_pc=0x571952u;
    s.ax = (s.si+0x00000002u);
  }
  L00571955: { // 0x571955: 3bf0 CMP ESI,EAX
    b516_pc=0x571955u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00571957: { // 0x571957: 8bde MOV EBX,ESI
    b516_pc=0x571957u;
    s.bx = s.si;
  }
  L00571959: { // 0x571959: 7d53 JGE 0x005719ae
    b516_pc=0x571959u;
    if(integer::condition("JGE",flags)) goto L005719ae;
  }
  L0057195b: { // 0x57195b: 66894c2446 MOV word ptr [ESP + 0x46],CX
    b516_pc=0x57195bu;
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L00571960: { // 0x571960: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571960u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571964: { // 0x571964: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x571964u;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00571969: { // 0x571969: e8a28e0100 CALL 0x0058a810
    b516_pc=0x571969u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x0057196eu); flags=0x202u;
  }
  L0057196e: { // 0x57196e: 84c0 TEST AL,AL
    b516_pc=0x57196eu;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571970: { // 0x571970: 742c JZ 0x0057199e
    b516_pc=0x571970u;
    if(integer::condition("JZ",flags)) goto L0057199e;
  }
  L00571972: { // 0x571972: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x571972u;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00571976: { // 0x571976: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571976u;
    s.cx = (f.sp+0x00000044u);
  }
  L0057197a: { // 0x57197a: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x57197au;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057197d: { // 0x57197d: e8de9dffff CALL 0x0056b760
    b516_pc=0x57197du;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571982u); flags=0x202u;
  }
  L00571982: { // 0x571982: 8d542444 LEA EDX,[ESP + 0x44]
    b516_pc=0x571982u;
    s.dx = (f.sp+0x00000044u);
  }
  L00571986: { // 0x571986: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571986u;
    s.cx = 0x0081a820u;
  }
  L0057198b: { // 0x57198b: 52 PUSH EDX
    b516_pc=0x57198bu;
    f.push(m,s.dx);
  }
  L0057198c: { // 0x57198c: e86f3bfdff CALL 0x00545500
    b516_pc=0x57198cu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571991u); flags=0x202u;
  }
  L00571991: { // 0x571991: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x571991u;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L00571994: { // 0x571994: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x571994u;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00571998: { // 0x571998: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571998u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0057199e: { // 0x57199e: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    b516_pc=0x57199eu;
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L005719a2: { // 0x5719a2: 43 INC EBX
    b516_pc=0x5719a2u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005719a3: { // 0x5719a3: 8d4602 LEA EAX,[ESI + 0x2]
    b516_pc=0x5719a3u;
    s.ax = (s.si+0x00000002u);
  }
  L005719a6: { // 0x5719a6: 3bd8 CMP EBX,EAX
    b516_pc=0x5719a6u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005719a8: { // 0x5719a8: 7cb1 JL 0x0057195b
    b516_pc=0x5719a8u;
    if(integer::condition("JL",flags)) goto L0057195b;
  }
  L005719aa: { // 0x5719aa: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    b516_pc=0x5719aau;
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005719ae: { // 0x5719ae: 41 INC ECX
    b516_pc=0x5719aeu;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005719af: { // 0x5719af: 3bca CMP ECX,EDX
    b516_pc=0x5719afu;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005719b1: { // 0x5719b1: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x5719b1u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L005719b5: { // 0x5719b5: 7c9e JL 0x00571955
    b516_pc=0x5719b5u;
    if(integer::condition("JL",flags)) goto L00571955;
  }
  L005719b7: { // 0x5719b7: 0fbf4500 MOVSX EAX,word ptr [EBP]
    b516_pc=0x5719b7u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005719bb: { // 0x5719bb: 0fbf0f MOVSX ECX,word ptr [EDI]
    b516_pc=0x5719bbu;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L005719be: { // 0x5719be: 0fbf5d02 MOVSX EBX,word ptr [EBP + 0x2]
    b516_pc=0x5719beu;
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L005719c2: { // 0x5719c2: 8d5001 LEA EDX,[EAX + 0x1]
    b516_pc=0x5719c2u;
    s.dx = (s.ax+0x00000001u);
  }
  L005719c5: { // 0x5719c5: 2bc8 SUB ECX,EAX
    b516_pc=0x5719c5u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005719c7: { // 0x5719c7: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    b516_pc=0x5719c7u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005719cb: { // 0x5719cb: 2bc3 SUB EAX,EBX
    b516_pc=0x5719cbu;
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L005719cd: { // 0x5719cd: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    b516_pc=0x5719cdu;
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005719d1: { // 0x5719d1: 49 DEC ECX
    b516_pc=0x5719d1u;
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005719d2: { // 0x5719d2: 8d5301 LEA EDX,[EBX + 0x1]
    b516_pc=0x5719d2u;
    s.dx = (s.bx+0x00000001u);
  }
  L005719d5: { // 0x5719d5: 48 DEC EAX
    b516_pc=0x5719d5u;
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005719d6: { // 0x5719d6: 8bf2 MOV ESI,EDX
    b516_pc=0x5719d6u;
    s.si = s.dx;
  }
  L005719d8: { // 0x5719d8: 03c2 ADD EAX,EDX
    b516_pc=0x5719d8u;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005719da: { // 0x5719da: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x5719dau;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L005719de: { // 0x5719de: 3bd0 CMP EDX,EAX
    b516_pc=0x5719deu;
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L005719e0: { // 0x5719e0: 89442418 MOV dword ptr [ESP + 0x18],EAX
    b516_pc=0x5719e0u;
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005719e4: { // 0x5719e4: 7d6d JGE 0x00571a53
    b516_pc=0x5719e4u;
    if(integer::condition("JGE",flags)) goto L00571a53;
  }
  L005719e6: { // 0x5719e6: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x5719e6u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L005719ea: { // 0x5719ea: 03cb ADD ECX,EBX
    b516_pc=0x5719eau;
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L005719ec: { // 0x5719ec: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x5719ecu;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L005719f0: { // 0x5719f0: 3b5c2440 CMP EBX,dword ptr [ESP + 0x40]
    b516_pc=0x5719f0u;
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000040u)),32,flags);
  }
  L005719f4: { // 0x5719f4: 7d54 JGE 0x00571a4a
    b516_pc=0x5719f4u;
    if(integer::condition("JGE",flags)) goto L00571a4a;
  }
  L005719f6: { // 0x5719f6: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x5719f6u;
    s.cx = (f.sp+0x00000044u);
  }
  L005719fa: { // 0x5719fa: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x5719fau;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L005719ff: { // 0x5719ff: 6689742446 MOV word ptr [ESP + 0x46],SI
    b516_pc=0x5719ffu;
    m.w16((f.sp+0x00000046u), (s.si & 0xffffu));
  }
  L00571a04: { // 0x571a04: e8078e0100 CALL 0x0058a810
    b516_pc=0x571a04u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00571a09u); flags=0x202u;
  }
  L00571a09: { // 0x571a09: 84c0 TEST AL,AL
    b516_pc=0x571a09u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571a0b: { // 0x571a0b: 742c JZ 0x00571a39
    b516_pc=0x571a0bu;
    if(integer::condition("JZ",flags)) goto L00571a39;
  }
  L00571a0d: { // 0x571a0d: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x571a0du;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00571a11: { // 0x571a11: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571a11u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571a15: { // 0x571a15: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x571a15u;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L00571a18: { // 0x571a18: e8439dffff CALL 0x0056b760
    b516_pc=0x571a18u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571a1du); flags=0x202u;
  }
  L00571a1d: { // 0x571a1d: 8d442444 LEA EAX,[ESP + 0x44]
    b516_pc=0x571a1du;
    s.ax = (f.sp+0x00000044u);
  }
  L00571a21: { // 0x571a21: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571a21u;
    s.cx = 0x0081a820u;
  }
  L00571a26: { // 0x571a26: 50 PUSH EAX
    b516_pc=0x571a26u;
    f.push(m,s.ax);
  }
  L00571a27: { // 0x571a27: e8d43afdff CALL 0x00545500
    b516_pc=0x571a27u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571a2cu); flags=0x202u;
  }
  L00571a2c: { // 0x571a2c: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x571a2cu;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L00571a2f: { // 0x571a2f: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    b516_pc=0x571a2fu;
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00571a33: { // 0x571a33: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571a33u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00571a39: { // 0x571a39: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    b516_pc=0x571a39u;
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00571a3d: { // 0x571a3d: 43 INC EBX
    b516_pc=0x571a3du;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571a3e: { // 0x571a3e: 3bd8 CMP EBX,EAX
    b516_pc=0x571a3eu;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00571a40: { // 0x571a40: 7cb4 JL 0x005719f6
    b516_pc=0x571a40u;
    if(integer::condition("JL",flags)) goto L005719f6;
  }
  L00571a42: { // 0x571a42: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    b516_pc=0x571a42u;
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00571a46: { // 0x571a46: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x571a46u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00571a4a: { // 0x571a4a: 46 INC ESI
    b516_pc=0x571a4au;
    s.si = integer::increment(s.si,32,flags);
  }
  L00571a4b: { // 0x571a4b: 3bf0 CMP ESI,EAX
    b516_pc=0x571a4bu;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00571a4d: { // 0x571a4d: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x571a4du;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00571a51: { // 0x571a51: 7c9d JL 0x005719f0
    b516_pc=0x571a51u;
    if(integer::condition("JL",flags)) goto L005719f0;
  }
  L00571a53: { // 0x571a53: 668b4702 MOV AX,word ptr [EDI + 0x2]
    b516_pc=0x571a53u;
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00571a57: { // 0x571a57: 668b17 MOV DX,word ptr [EDI]
    b516_pc=0x571a57u;
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00571a5a: { // 0x571a5a: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x571a5au;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00571a5e: { // 0x571a5e: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    b516_pc=0x571a5eu;
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L00571a62: { // 0x571a62: 662d0200 SUB AX,0x2
    b516_pc=0x571a62u;
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),0x00000002u,16,flags));
  }
  L00571a66: { // 0x571a66: 6689542444 MOV word ptr [ESP + 0x44],DX
    b516_pc=0x571a66u;
    m.w16((f.sp+0x00000044u), (s.dx & 0xffffu));
  }
  L00571a6b: { // 0x571a6b: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    b516_pc=0x571a6bu;
    s.dx = m.r32((s.si+0x00000010u));
  }
  L00571a6e: { // 0x571a6e: 6689442446 MOV word ptr [ESP + 0x46],AX
    b516_pc=0x571a6eu;
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00571a73: { // 0x571a73: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    b516_pc=0x571a73u;
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00571a77: { // 0x571a77: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x571a77u;
    s.ax = m.r32((0x00a55c70u));
  }
  L00571a7c: { // 0x571a7c: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    b516_pc=0x571a7cu;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00571a80: { // 0x571a80: 52 PUSH EDX
    b516_pc=0x571a80u;
    f.push(m,s.dx);
  }
  L00571a81: { // 0x571a81: 53 PUSH EBX
    b516_pc=0x571a81u;
    f.push(m,s.bx);
  }
  L00571a82: { // 0x571a82: 8d54244c LEA EDX,[ESP + 0x4c]
    b516_pc=0x571a82u;
    s.dx = (f.sp+0x0000004cu);
  }
  L00571a86: { // 0x571a86: 8d4802 LEA ECX,[EAX + 0x2]
    b516_pc=0x571a86u;
    s.cx = (s.ax+0x00000002u);
  }
  L00571a89: { // 0x571a89: e862370100 CALL 0x005851f0
    b516_pc=0x571a89u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x00571a8eu); flags=0x202u;
  }
  L00571a8e: { // 0x571a8e: 668b5502 MOV DX,word ptr [EBP + 0x2]
    b516_pc=0x571a8eu;
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L00571a92: { // 0x571a92: 668b4d00 MOV CX,word ptr [EBP]
    b516_pc=0x571a92u;
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00571a96: { // 0x571a96: 6683ea03 SUB DX,0x3
    b516_pc=0x571a96u;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L00571a9a: { // 0x571a9a: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x571a9au;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L00571a9f: { // 0x571a9f: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    b516_pc=0x571a9fu;
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00571aa2: { // 0x571aa2: 668954244a MOV word ptr [ESP + 0x4a],DX
    b516_pc=0x571aa2u;
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L00571aa7: { // 0x571aa7: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x571aa7u;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00571aab: { // 0x571aab: 51 PUSH ECX
    b516_pc=0x571aabu;
    f.push(m,s.cx);
  }
  L00571aac: { // 0x571aac: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    b516_pc=0x571aacu;
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00571ab0: { // 0x571ab0: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x571ab0u;
    s.ax = m.r32((0x00a55c70u));
  }
  L00571ab5: { // 0x571ab5: 53 PUSH EBX
    b516_pc=0x571ab5u;
    f.push(m,s.bx);
  }
  L00571ab6: { // 0x571ab6: 8d542450 LEA EDX,[ESP + 0x50]
    b516_pc=0x571ab6u;
    s.dx = (f.sp+0x00000050u);
  }
  L00571aba: { // 0x571aba: 8d4804 LEA ECX,[EAX + 0x4]
    b516_pc=0x571abau;
    s.cx = (s.ax+0x00000004u);
  }
  L00571abd: { // 0x571abd: e82e370100 CALL 0x005851f0
    b516_pc=0x571abdu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x00571ac2u); flags=0x202u;
  }
  L00571ac2: { // 0x571ac2: 33db XOR EBX,EBX
    b516_pc=0x571ac2u;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00571ac4: { // 0x571ac4: 668b0f MOV CX,word ptr [EDI]
    b516_pc=0x571ac4u;
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L00571ac7: { // 0x571ac7: 668b5502 MOV DX,word ptr [EBP + 0x2]
    b516_pc=0x571ac7u;
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L00571acb: { // 0x571acb: 6603cb ADD CX,BX
    b516_pc=0x571acbu;
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00571ace: { // 0x571ace: 8d442448 LEA EAX,[ESP + 0x48]
    b516_pc=0x571aceu;
    s.ax = (f.sp+0x00000048u);
  }
  L00571ad2: { // 0x571ad2: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x571ad2u;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L00571ad7: { // 0x571ad7: 662bd3 SUB DX,BX
    b516_pc=0x571ad7u;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00571ada: { // 0x571ada: 50 PUSH EAX
    b516_pc=0x571adau;
    f.push(m,s.ax);
  }
  L00571adb: { // 0x571adb: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571adbu;
    s.cx = 0x0081a820u;
  }
  L00571ae0: { // 0x571ae0: 668954244e MOV word ptr [ESP + 0x4e],DX
    b516_pc=0x571ae0u;
    m.w16((f.sp+0x0000004eu), (s.dx & 0xffffu));
  }
  L00571ae5: { // 0x571ae5: e8163afdff CALL 0x00545500
    b516_pc=0x571ae5u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571aeau); flags=0x202u;
  }
  L00571aea: { // 0x571aea: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x571aeau;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L00571aed: { // 0x571aed: c6801c01000006 MOV byte ptr [EAX + 0x11c],0x6
    b516_pc=0x571aedu;
    m.w8((s.ax+0x0000011cu), 0x00000006u);
  }
  L00571af4: { // 0x571af4: 2acb SUB CL,BL
    b516_pc=0x571af4u;
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00571af6: { // 0x571af6: fec9 DEC CL
    b516_pc=0x571af6u;
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L00571af8: { // 0x571af8: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571af8u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00571afe: { // 0x571afe: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    b516_pc=0x571afeu;
    s.dx = m.r32((0x00a55c50u));
  }
  L00571b04: { // 0x571b04: 83c205 ADD EDX,0x5
    b516_pc=0x571b04u;
    s.dx = integer::add(s.dx,0x00000005u,32,flags);
  }
  L00571b07: { // 0x571b07: 43 INC EBX
    b516_pc=0x571b07u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571b08: { // 0x571b08: 83fb04 CMP EBX,0x4
    b516_pc=0x571b08u;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00571b0b: { // 0x571b0b: 895038 MOV dword ptr [EAX + 0x38],EDX
    b516_pc=0x571b0bu;
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L00571b0e: { // 0x571b0e: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x571b0eu;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00571b15: { // 0x571b15: 7cad JL 0x00571ac4
    b516_pc=0x571b15u;
    if(integer::condition("JL",flags)) goto L00571ac4;
  }
  L00571b17: { // 0x571b17: 33db XOR EBX,EBX
    b516_pc=0x571b17u;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00571b19: { // 0x571b19: 668b4702 MOV AX,word ptr [EDI + 0x2]
    b516_pc=0x571b19u;
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00571b1d: { // 0x571b1d: 33f6 XOR ESI,ESI
    b516_pc=0x571b1du;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00571b1f: { // 0x571b1f: 0fbf5502 MOVSX EDX,word ptr [EBP + 0x2]
    b516_pc=0x571b1fu;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00571b23: { // 0x571b23: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x571b23u;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00571b26: { // 0x571b26: 2bca SUB ECX,EDX
    b516_pc=0x571b26u;
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00571b28: { // 0x571b28: 8d4c19fd LEA ECX,[ECX + EBX*0x1 + -0x3]
    b516_pc=0x571b28u;
    s.cx = (s.cx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L00571b2c: { // 0x571b2c: 85c9 TEST ECX,ECX
    b516_pc=0x571b2cu;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00571b2e: { // 0x571b2e: 7e65 JLE 0x00571b95
    b516_pc=0x571b2eu;
    if(integer::condition("JLE",flags)) goto L00571b95;
  }
  L00571b30: { // 0x571b30: 668b17 MOV DX,word ptr [EDI]
    b516_pc=0x571b30u;
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00571b33: { // 0x571b33: 2bc6 SUB EAX,ESI
    b516_pc=0x571b33u;
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00571b35: { // 0x571b35: 83e803 SUB EAX,0x3
    b516_pc=0x571b35u;
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00571b38: { // 0x571b38: 6603d3 ADD DX,BX
    b516_pc=0x571b38u;
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00571b3b: { // 0x571b3b: 668944244a MOV word ptr [ESP + 0x4a],AX
    b516_pc=0x571b3bu;
    m.w16((f.sp+0x0000004au), (s.ax & 0xffffu));
  }
  L00571b40: { // 0x571b40: 8d442448 LEA EAX,[ESP + 0x48]
    b516_pc=0x571b40u;
    s.ax = (f.sp+0x00000048u);
  }
  L00571b44: { // 0x571b44: 50 PUSH EAX
    b516_pc=0x571b44u;
    f.push(m,s.ax);
  }
  L00571b45: { // 0x571b45: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571b45u;
    s.cx = 0x0081a820u;
  }
  L00571b4a: { // 0x571b4a: 668954244c MOV word ptr [ESP + 0x4c],DX
    b516_pc=0x571b4au;
    m.w16((f.sp+0x0000004cu), (s.dx & 0xffffu));
  }
  L00571b4f: { // 0x571b4f: e8ac39fdff CALL 0x00545500
    b516_pc=0x571b4fu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571b54u); flags=0x202u;
  }
  L00571b54: { // 0x571b54: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    b516_pc=0x571b54u;
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00571b58: { // 0x571b58: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    b516_pc=0x571b58u;
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L00571b5b: { // 0x571b5b: c6801c01000003 MOV byte ptr [EAX + 0x11c],0x3
    b516_pc=0x571b5bu;
    m.w8((s.ax+0x0000011cu), 0x00000003u);
  }
  L00571b62: { // 0x571b62: 2ad3 SUB DL,BL
    b516_pc=0x571b62u;
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00571b64: { // 0x571b64: feca DEC DL
    b516_pc=0x571b64u;
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L00571b66: { // 0x571b66: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    b516_pc=0x571b66u;
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L00571b6c: { // 0x571b6c: 8b0d505ca500 MOV ECX,dword ptr [0x00a55c50]
    b516_pc=0x571b6cu;
    s.cx = m.r32((0x00a55c50u));
  }
  L00571b72: { // 0x571b72: 83c102 ADD ECX,0x2
    b516_pc=0x571b72u;
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00571b75: { // 0x571b75: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x571b75u;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00571b7c: { // 0x571b7c: 894838 MOV dword ptr [EAX + 0x38],ECX
    b516_pc=0x571b7cu;
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L00571b7f: { // 0x571b7f: 668b4702 MOV AX,word ptr [EDI + 0x2]
    b516_pc=0x571b7fu;
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00571b83: { // 0x571b83: 0fbf4d02 MOVSX ECX,word ptr [EBP + 0x2]
    b516_pc=0x571b83u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00571b87: { // 0x571b87: 0fbfd0 MOVSX EDX,AX
    b516_pc=0x571b87u;
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00571b8a: { // 0x571b8a: 2bd1 SUB EDX,ECX
    b516_pc=0x571b8au;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00571b8c: { // 0x571b8c: 46 INC ESI
    b516_pc=0x571b8cu;
    s.si = integer::increment(s.si,32,flags);
  }
  L00571b8d: { // 0x571b8d: 8d541afd LEA EDX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x571b8du;
    s.dx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L00571b91: { // 0x571b91: 3bf2 CMP ESI,EDX
    b516_pc=0x571b91u;
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00571b93: { // 0x571b93: 7c9b JL 0x00571b30
    b516_pc=0x571b93u;
    if(integer::condition("JL",flags)) goto L00571b30;
  }
  L00571b95: { // 0x571b95: 43 INC EBX
    b516_pc=0x571b95u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571b96: { // 0x571b96: 83fb04 CMP EBX,0x4
    b516_pc=0x571b96u;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00571b99: { // 0x571b99: 0f8c7affffff JL 0x00571b19
    b516_pc=0x571b99u;
    if(integer::condition("JL",flags)) goto L00571b19;
  }
  L00571b9f: { // 0x571b9f: 33db XOR EBX,EBX
    b516_pc=0x571b9fu;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00571ba1: { // 0x571ba1: 668b4500 MOV AX,word ptr [EBP]
    b516_pc=0x571ba1u;
    s.ax = with_ax(s.ax, m.r16((s.bp)));
  }
  L00571ba5: { // 0x571ba5: 33f6 XOR ESI,ESI
    b516_pc=0x571ba5u;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00571ba7: { // 0x571ba7: 0fbf17 MOVSX EDX,word ptr [EDI]
    b516_pc=0x571ba7u;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00571baa: { // 0x571baa: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x571baau;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00571bad: { // 0x571bad: 2bd1 SUB EDX,ECX
    b516_pc=0x571badu;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00571baf: { // 0x571baf: 8d4c1afd LEA ECX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x571bafu;
    s.cx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L00571bb3: { // 0x571bb3: 85c9 TEST ECX,ECX
    b516_pc=0x571bb3u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00571bb5: { // 0x571bb5: 7e62 JLE 0x00571c19
    b516_pc=0x571bb5u;
    if(integer::condition("JLE",flags)) goto L00571c19;
  }
  L00571bb7: { // 0x571bb7: 8d543003 LEA EDX,[EAX + ESI*0x1 + 0x3]
    b516_pc=0x571bb7u;
    s.dx = (s.ax+(s.si * 0x00000001u)+0x00000003u);
  }
  L00571bbb: { // 0x571bbb: 668b4502 MOV AX,word ptr [EBP + 0x2]
    b516_pc=0x571bbbu;
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L00571bbf: { // 0x571bbf: 8d4c2448 LEA ECX,[ESP + 0x48]
    b516_pc=0x571bbfu;
    s.cx = (f.sp+0x00000048u);
  }
  L00571bc3: { // 0x571bc3: 662bc3 SUB AX,BX
    b516_pc=0x571bc3u;
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00571bc6: { // 0x571bc6: 51 PUSH ECX
    b516_pc=0x571bc6u;
    f.push(m,s.cx);
  }
  L00571bc7: { // 0x571bc7: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571bc7u;
    s.cx = 0x0081a820u;
  }
  L00571bcc: { // 0x571bcc: 668954244c MOV word ptr [ESP + 0x4c],DX
    b516_pc=0x571bccu;
    m.w16((f.sp+0x0000004cu), (s.dx & 0xffffu));
  }
  L00571bd1: { // 0x571bd1: 668944244e MOV word ptr [ESP + 0x4e],AX
    b516_pc=0x571bd1u;
    m.w16((f.sp+0x0000004eu), (s.ax & 0xffffu));
  }
  L00571bd6: { // 0x571bd6: e82539fdff CALL 0x00545500
    b516_pc=0x571bd6u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571bdbu); flags=0x202u;
  }
  L00571bdb: { // 0x571bdb: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    b516_pc=0x571bdbu;
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00571bdf: { // 0x571bdf: 8a4a10 MOV CL,byte ptr [EDX + 0x10]
    b516_pc=0x571bdfu;
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000010u)));
  }
  L00571be2: { // 0x571be2: c6801c01000002 MOV byte ptr [EAX + 0x11c],0x2
    b516_pc=0x571be2u;
    m.w8((s.ax+0x0000011cu), 0x00000002u);
  }
  L00571be9: { // 0x571be9: 2acb SUB CL,BL
    b516_pc=0x571be9u;
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00571beb: { // 0x571beb: fec9 DEC CL
    b516_pc=0x571bebu;
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L00571bed: { // 0x571bed: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571bedu;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00571bf3: { // 0x571bf3: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    b516_pc=0x571bf3u;
    s.dx = m.r32((0x00a55c50u));
  }
  L00571bf9: { // 0x571bf9: 42 INC EDX
    b516_pc=0x571bf9u;
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00571bfa: { // 0x571bfa: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x571bfau;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00571c01: { // 0x571c01: 895038 MOV dword ptr [EAX + 0x38],EDX
    b516_pc=0x571c01u;
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L00571c04: { // 0x571c04: 668b4500 MOV AX,word ptr [EBP]
    b516_pc=0x571c04u;
    s.ax = with_ax(s.ax, m.r16((s.bp)));
  }
  L00571c08: { // 0x571c08: 0fbf17 MOVSX EDX,word ptr [EDI]
    b516_pc=0x571c08u;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00571c0b: { // 0x571c0b: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x571c0bu;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00571c0e: { // 0x571c0e: 2bd1 SUB EDX,ECX
    b516_pc=0x571c0eu;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00571c10: { // 0x571c10: 46 INC ESI
    b516_pc=0x571c10u;
    s.si = integer::increment(s.si,32,flags);
  }
  L00571c11: { // 0x571c11: 8d4c1afd LEA ECX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x571c11u;
    s.cx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L00571c15: { // 0x571c15: 3bf1 CMP ESI,ECX
    b516_pc=0x571c15u;
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00571c17: { // 0x571c17: 7c9e JL 0x00571bb7
    b516_pc=0x571c17u;
    if(integer::condition("JL",flags)) goto L00571bb7;
  }
  L00571c19: { // 0x571c19: 43 INC EBX
    b516_pc=0x571c19u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571c1a: { // 0x571c1a: 83fb04 CMP EBX,0x4
    b516_pc=0x571c1au;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00571c1d: { // 0x571c1d: 7c82 JL 0x00571ba1
    b516_pc=0x571c1du;
    if(integer::condition("JL",flags)) goto L00571ba1;
  }
  L00571c1f: { // 0x571c1f: 5f POP EDI
    b516_pc=0x571c1fu;
    const auto value=f.pop(m); s.di = value;
  }
  L00571c20: { // 0x571c20: 5e POP ESI
    b516_pc=0x571c20u;
    const auto value=f.pop(m); s.si = value;
  }
  L00571c21: { // 0x571c21: 5d POP EBP
    b516_pc=0x571c21u;
    const auto value=f.pop(m); s.bp = value;
  }
  L00571c22: { // 0x571c22: b001 MOV AL,0x1
    b516_pc=0x571c22u;
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00571c24: { // 0x571c24: 5b POP EBX
    b516_pc=0x571c24u;
    const auto value=f.pop(m); s.bx = value;
  }
  L00571c25: { // 0x571c25: 83c42c ADD ESP,0x2c
    b516_pc=0x571c25u;
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L00571c28: { // 0x571c28: c20c00 RET 0xc
    b516_pc=0x571c28u;
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00571c2b: { // 0x571c2b: 5f POP EDI
    b516_pc=0x571c2bu;
    const auto value=f.pop(m); s.di = value;
  }
  L00571c2c: { // 0x571c2c: 5e POP ESI
    b516_pc=0x571c2cu;
    const auto value=f.pop(m); s.si = value;
  }
  L00571c2d: { // 0x571c2d: 5d POP EBP
    b516_pc=0x571c2du;
    const auto value=f.pop(m); s.bp = value;
  }
  L00571c2e: { // 0x571c2e: 32c0 XOR AL,AL
    b516_pc=0x571c2eu;
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00571c30: { // 0x571c30: 5b POP EBX
    b516_pc=0x571c30u;
    const auto value=f.pop(m); s.bx = value;
  }
  L00571c31: { // 0x571c31: 83c42c ADD ESP,0x2c
    b516_pc=0x571c31u;
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L00571c34: { // 0x571c34: c20c00 RET 0xc
    b516_pc=0x571c34u;
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_001721e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005721e0: { // 0x5721e0: 83ec2c SUB ESP,0x2c
    b516_pc=0x5721e0u;
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L005721e3: { // 0x5721e3: 53 PUSH EBX
    b516_pc=0x5721e3u;
    f.push(m,s.bx);
  }
  L005721e4: { // 0x5721e4: 55 PUSH EBP
    b516_pc=0x5721e4u;
    f.push(m,s.bp);
  }
  L005721e5: { // 0x5721e5: 8b6c2438 MOV EBP,dword ptr [ESP + 0x38]
    b516_pc=0x5721e5u;
    s.bp = m.r32((f.sp+0x00000038u));
  }
  L005721e9: { // 0x5721e9: 56 PUSH ESI
    b516_pc=0x5721e9u;
    f.push(m,s.si);
  }
  L005721ea: { // 0x5721ea: 57 PUSH EDI
    b516_pc=0x5721eau;
    f.push(m,s.di);
  }
  L005721eb: { // 0x5721eb: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    b516_pc=0x5721ebu;
    s.di = m.r32((f.sp+0x00000044u));
  }
  L005721ef: { // 0x5721ef: 0fbf7500 MOVSX ESI,word ptr [EBP]
    b516_pc=0x5721efu;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005721f3: { // 0x5721f3: 0fbf07 MOVSX EAX,word ptr [EDI]
    b516_pc=0x5721f3u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L005721f6: { // 0x5721f6: 2bc6 SUB EAX,ESI
    b516_pc=0x5721f6u;
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L005721f8: { // 0x5721f8: 8bd9 MOV EBX,ECX
    b516_pc=0x5721f8u;
    s.bx = s.cx;
  }
  L005721fa: { // 0x5721fa: 83f803 CMP EAX,0x3
    b516_pc=0x5721fau;
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005721fd: { // 0x5721fd: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    b516_pc=0x5721fdu;
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00572201: { // 0x572201: 0f8ce0040000 JL 0x005726e7
    b516_pc=0x572201u;
    if(integer::condition("JL",flags)) goto L005726e7;
  }
  L00572207: { // 0x572207: 0fbf5502 MOVSX EDX,word ptr [EBP + 0x2]
    b516_pc=0x572207u;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0057220b: { // 0x57220b: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    b516_pc=0x57220bu;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057220f: { // 0x57220f: 2bca SUB ECX,EDX
    b516_pc=0x57220fu;
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00572211: { // 0x572211: 83f903 CMP ECX,0x3
    b516_pc=0x572211u;
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00572214: { // 0x572214: 0f8ccd040000 JL 0x005726e7
    b516_pc=0x572214u;
    if(integer::condition("JL",flags)) goto L005726e7;
  }
  L0057221a: { // 0x57221a: 83c00a ADD EAX,0xa
    b516_pc=0x57221au;
    s.ax = integer::add(s.ax,0x0000000au,32,flags);
  }
  L0057221d: { // 0x57221d: 83c10a ADD ECX,0xa
    b516_pc=0x57221du;
    s.cx = integer::add(s.cx,0x0000000au,32,flags);
  }
  L00572220: { // 0x572220: 89442424 MOV dword ptr [ESP + 0x24],EAX
    b516_pc=0x572220u;
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00572224: { // 0x572224: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x572224u;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00572228: { // 0x572228: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    b516_pc=0x572228u;
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0057222c: { // 0x57222c: 8d4c241c LEA ECX,[ESP + 0x1c]
    b516_pc=0x57222cu;
    s.cx = (f.sp+0x0000001cu);
  }
  L00572230: { // 0x572230: 50 PUSH EAX
    b516_pc=0x572230u;
    f.push(m,s.ax);
  }
  L00572231: { // 0x572231: 83c6f9 ADD ESI,-0x7
    b516_pc=0x572231u;
    s.si = integer::add(s.si,0xfffffff9u,32,flags);
  }
  L00572234: { // 0x572234: 83c2fc ADD EDX,-0x4
    b516_pc=0x572234u;
    s.dx = integer::add(s.dx,0xfffffffcu,32,flags);
  }
  L00572237: { // 0x572237: 51 PUSH ECX
    b516_pc=0x572237u;
    f.push(m,s.cx);
  }
  L00572238: { // 0x572238: 8bcb MOV ECX,EBX
    b516_pc=0x572238u;
    s.cx = s.bx;
  }
  L0057223a: { // 0x57223a: 89742424 MOV dword ptr [ESP + 0x24],ESI
    b516_pc=0x57223au;
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0057223e: { // 0x57223e: 89542428 MOV dword ptr [ESP + 0x28],EDX
    b516_pc=0x57223eu;
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L00572242: { // 0x572242: e8b9040000 CALL 0x00572700
    b516_pc=0x572242u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,0x00572247u); flags=0x202u;
  }
  L00572247: { // 0x572247: 84c0 TEST AL,AL
    b516_pc=0x572247u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572249: { // 0x572249: 0f8498040000 JZ 0x005726e7
    b516_pc=0x572249u;
    if(integer::condition("JZ",flags)) goto L005726e7;
  }
  L0057224f: { // 0x57224f: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    b516_pc=0x57224fu;
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00572253: { // 0x572253: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    b516_pc=0x572253u;
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00572257: { // 0x572257: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    b516_pc=0x572257u;
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0057225b: { // 0x57225b: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    b516_pc=0x57225bu;
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0057225f: { // 0x57225f: 03c8 ADD ECX,EAX
    b516_pc=0x57225fu;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00572261: { // 0x572261: 8bda MOV EBX,EDX
    b516_pc=0x572261u;
    s.bx = s.dx;
  }
  L00572263: { // 0x572263: 8bf0 MOV ESI,EAX
    b516_pc=0x572263u;
    s.si = s.ax;
  }
  L00572265: { // 0x572265: 3bc1 CMP EAX,ECX
    b516_pc=0x572265u;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00572267: { // 0x572267: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    b516_pc=0x572267u;
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0057226b: { // 0x57226b: 89442430 MOV dword ptr [ESP + 0x30],EAX
    b516_pc=0x57226bu;
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0057226f: { // 0x57226f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x57226fu;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00572273: { // 0x572273: 7d7c JGE 0x005722f1
    b516_pc=0x572273u;
    if(integer::condition("JGE",flags)) goto L005722f1;
  }
  L00572275: { // 0x572275: 8d4207 LEA EAX,[EDX + 0x7]
    b516_pc=0x572275u;
    s.ax = (s.dx+0x00000007u);
  }
  L00572278: { // 0x572278: 89442444 MOV dword ptr [ESP + 0x44],EAX
    b516_pc=0x572278u;
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0057227c: { // 0x57227c: 3b5c2444 CMP EBX,dword ptr [ESP + 0x44]
    b516_pc=0x57227cu;
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L00572280: { // 0x572280: 7d5c JGE 0x005722de
    b516_pc=0x572280u;
    if(integer::condition("JGE",flags)) goto L005722de;
  }
  L00572282: { // 0x572282: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x572282u;
    s.cx = (f.sp+0x00000040u);
  }
  L00572286: { // 0x572286: 66895c2440 MOV word ptr [ESP + 0x40],BX
    b516_pc=0x572286u;
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L0057228b: { // 0x57228b: 6689742442 MOV word ptr [ESP + 0x42],SI
    b516_pc=0x57228bu;
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L00572290: { // 0x572290: e87b850100 CALL 0x0058a810
    b516_pc=0x572290u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00572295u); flags=0x202u;
  }
  L00572295: { // 0x572295: 84c0 TEST AL,AL
    b516_pc=0x572295u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572297: { // 0x572297: 7434 JZ 0x005722cd
    b516_pc=0x572297u;
    if(integer::condition("JZ",flags)) goto L005722cd;
  }
  L00572299: { // 0x572299: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    b516_pc=0x572299u;
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0057229d: { // 0x57229d: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x57229du;
    s.cx = (f.sp+0x00000040u);
  }
  L005722a1: { // 0x5722a1: e8ba94ffff CALL 0x0056b760
    b516_pc=0x5722a1u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x005722a6u); flags=0x202u;
  }
  L005722a6: { // 0x5722a6: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x5722a6u;
    s.cx = (f.sp+0x00000040u);
  }
  L005722aa: { // 0x5722aa: 51 PUSH ECX
    b516_pc=0x5722aau;
    f.push(m,s.cx);
  }
  L005722ab: { // 0x5722ab: b920a88100 MOV ECX,0x81a820
    b516_pc=0x5722abu;
    s.cx = 0x0081a820u;
  }
  L005722b0: { // 0x5722b0: e84b32fdff CALL 0x00545500
    b516_pc=0x5722b0u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x005722b5u); flags=0x202u;
  }
  L005722b5: { // 0x5722b5: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    b516_pc=0x5722b5u;
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L005722b9: { // 0x5722b9: 8bf0 MOV ESI,EAX
    b516_pc=0x5722b9u;
    s.si = s.ax;
  }
  L005722bb: { // 0x5722bb: e810080000 CALL 0x00572ad0
    b516_pc=0x5722bbu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,0x005722c0u); flags=0x202u;
  }
  L005722c0: { // 0x5722c0: 8a5010 MOV DL,byte ptr [EAX + 0x10]
    b516_pc=0x5722c0u;
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000010u)));
  }
  L005722c3: { // 0x5722c3: 88961b010000 MOV byte ptr [ESI + 0x11b],DL
    b516_pc=0x5722c3u;
    m.w8((s.si+0x0000011bu), (s.dx & 0xffu));
  }
  L005722c9: { // 0x5722c9: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    b516_pc=0x5722c9u;
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005722cd: { // 0x5722cd: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    b516_pc=0x5722cdu;
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005722d1: { // 0x5722d1: 43 INC EBX
    b516_pc=0x5722d1u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005722d2: { // 0x5722d2: 3bd8 CMP EBX,EAX
    b516_pc=0x5722d2u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005722d4: { // 0x5722d4: 7cac JL 0x00572282
    b516_pc=0x5722d4u;
    if(integer::condition("JL",flags)) goto L00572282;
  }
  L005722d6: { // 0x5722d6: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    b516_pc=0x5722d6u;
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005722da: { // 0x5722da: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x5722dau;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L005722de: { // 0x5722de: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    b516_pc=0x5722deu;
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L005722e2: { // 0x5722e2: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    b516_pc=0x5722e2u;
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L005722e6: { // 0x5722e6: 46 INC ESI
    b516_pc=0x5722e6u;
    s.si = integer::increment(s.si,32,flags);
  }
  L005722e7: { // 0x5722e7: 03c8 ADD ECX,EAX
    b516_pc=0x5722e7u;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005722e9: { // 0x5722e9: 3bf1 CMP ESI,ECX
    b516_pc=0x5722e9u;
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005722eb: { // 0x5722eb: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x5722ebu;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L005722ef: { // 0x5722ef: 7c8b JL 0x0057227c
    b516_pc=0x5722efu;
    if(integer::condition("JL",flags)) goto L0057227c;
  }
  L005722f1: { // 0x5722f1: 0fbf5f02 MOVSX EBX,word ptr [EDI + 0x2]
    b516_pc=0x5722f1u;
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005722f5: { // 0x5722f5: 43 INC EBX
    b516_pc=0x5722f5u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005722f6: { // 0x5722f6: 8bf2 MOV ESI,EDX
    b516_pc=0x5722f6u;
    s.si = s.dx;
  }
  L005722f8: { // 0x5722f8: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x5722f8u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L005722fc: { // 0x5722fc: 8d4307 LEA EAX,[EBX + 0x7]
    b516_pc=0x5722fcu;
    s.ax = (s.bx+0x00000007u);
  }
  L005722ff: { // 0x5722ff: 3bd8 CMP EBX,EAX
    b516_pc=0x5722ffu;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572301: { // 0x572301: 89442418 MOV dword ptr [ESP + 0x18],EAX
    b516_pc=0x572301u;
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00572305: { // 0x572305: 7d73 JGE 0x0057237a
    b516_pc=0x572305u;
    if(integer::condition("JGE",flags)) goto L0057237a;
  }
  L00572307: { // 0x572307: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    b516_pc=0x572307u;
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0057230b: { // 0x57230b: 03ca ADD ECX,EDX
    b516_pc=0x57230bu;
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057230d: { // 0x57230d: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    b516_pc=0x57230du;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00572311: { // 0x572311: 3b742444 CMP ESI,dword ptr [ESP + 0x44]
    b516_pc=0x572311u;
    (void)integer::sub(s.si,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L00572315: { // 0x572315: 7d5e JGE 0x00572375
    b516_pc=0x572315u;
    if(integer::condition("JGE",flags)) goto L00572375;
  }
  L00572317: { // 0x572317: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x572317u;
    s.cx = (f.sp+0x00000040u);
  }
  L0057231b: { // 0x57231b: 6689742440 MOV word ptr [ESP + 0x40],SI
    b516_pc=0x57231bu;
    m.w16((f.sp+0x00000040u), (s.si & 0xffffu));
  }
  L00572320: { // 0x572320: 66895c2442 MOV word ptr [ESP + 0x42],BX
    b516_pc=0x572320u;
    m.w16((f.sp+0x00000042u), (s.bx & 0xffffu));
  }
  L00572325: { // 0x572325: e8e6840100 CALL 0x0058a810
    b516_pc=0x572325u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x0057232au); flags=0x202u;
  }
  L0057232a: { // 0x57232a: 84c0 TEST AL,AL
    b516_pc=0x57232au;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057232c: { // 0x57232c: 7436 JZ 0x00572364
    b516_pc=0x57232cu;
    if(integer::condition("JZ",flags)) goto L00572364;
  }
  L0057232e: { // 0x57232e: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    b516_pc=0x57232eu;
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00572332: { // 0x572332: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x572332u;
    s.cx = (f.sp+0x00000040u);
  }
  L00572336: { // 0x572336: e82594ffff CALL 0x0056b760
    b516_pc=0x572336u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x0057233bu); flags=0x202u;
  }
  L0057233b: { // 0x57233b: 8d542440 LEA EDX,[ESP + 0x40]
    b516_pc=0x57233bu;
    s.dx = (f.sp+0x00000040u);
  }
  L0057233f: { // 0x57233f: b920a88100 MOV ECX,0x81a820
    b516_pc=0x57233fu;
    s.cx = 0x0081a820u;
  }
  L00572344: { // 0x572344: 52 PUSH EDX
    b516_pc=0x572344u;
    f.push(m,s.dx);
  }
  L00572345: { // 0x572345: e8b631fdff CALL 0x00545500
    b516_pc=0x572345u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x0057234au); flags=0x202u;
  }
  L0057234a: { // 0x57234a: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    b516_pc=0x57234au;
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0057234e: { // 0x57234e: 89442414 MOV dword ptr [ESP + 0x14],EAX
    b516_pc=0x57234eu;
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00572352: { // 0x572352: e879070000 CALL 0x00572ad0
    b516_pc=0x572352u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,0x00572357u); flags=0x202u;
  }
  L00572357: { // 0x572357: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    b516_pc=0x572357u;
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057235b: { // 0x57235b: 8a4010 MOV AL,byte ptr [EAX + 0x10]
    b516_pc=0x57235bu;
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000010u)));
  }
  L0057235e: { // 0x57235e: 88811b010000 MOV byte ptr [ECX + 0x11b],AL
    b516_pc=0x57235eu;
    m.w8((s.cx+0x0000011bu), (s.ax & 0xffu));
  }
  L00572364: { // 0x572364: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    b516_pc=0x572364u;
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00572368: { // 0x572368: 46 INC ESI
    b516_pc=0x572368u;
    s.si = integer::increment(s.si,32,flags);
  }
  L00572369: { // 0x572369: 3bf0 CMP ESI,EAX
    b516_pc=0x572369u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0057236b: { // 0x57236b: 7caa JL 0x00572317
    b516_pc=0x57236bu;
    if(integer::condition("JL",flags)) goto L00572317;
  }
  L0057236d: { // 0x57236d: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x57236du;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00572371: { // 0x572371: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    b516_pc=0x572371u;
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00572375: { // 0x572375: 43 INC EBX
    b516_pc=0x572375u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00572376: { // 0x572376: 3bd8 CMP EBX,EAX
    b516_pc=0x572376u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572378: { // 0x572378: 7c97 JL 0x00572311
    b516_pc=0x572378u;
    if(integer::condition("JL",flags)) goto L00572311;
  }
  L0057237a: { // 0x57237a: 0fbf4d02 MOVSX ECX,word ptr [EBP + 0x2]
    b516_pc=0x57237au;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0057237e: { // 0x57237e: 0fbf7500 MOVSX ESI,word ptr [EBP]
    b516_pc=0x57237eu;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00572382: { // 0x572382: 8d5101 LEA EDX,[ECX + 0x1]
    b516_pc=0x572382u;
    s.dx = (s.cx+0x00000001u);
  }
  L00572385: { // 0x572385: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x572385u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00572389: { // 0x572389: 3bca CMP ECX,EDX
    b516_pc=0x572389u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0057238b: { // 0x57238b: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    b516_pc=0x57238bu;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0057238f: { // 0x57238f: 89542418 MOV dword ptr [ESP + 0x18],EDX
    b516_pc=0x57238fu;
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00572393: { // 0x572393: 7d65 JGE 0x005723fa
    b516_pc=0x572393u;
    if(integer::condition("JGE",flags)) goto L005723fa;
  }
  L00572395: { // 0x572395: 8d4602 LEA EAX,[ESI + 0x2]
    b516_pc=0x572395u;
    s.ax = (s.si+0x00000002u);
  }
  L00572398: { // 0x572398: 3bf0 CMP ESI,EAX
    b516_pc=0x572398u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0057239a: { // 0x57239a: 8bde MOV EBX,ESI
    b516_pc=0x57239au;
    s.bx = s.si;
  }
  L0057239c: { // 0x57239c: 7d53 JGE 0x005723f1
    b516_pc=0x57239cu;
    if(integer::condition("JGE",flags)) goto L005723f1;
  }
  L0057239e: { // 0x57239e: 66894c2442 MOV word ptr [ESP + 0x42],CX
    b516_pc=0x57239eu;
    m.w16((f.sp+0x00000042u), (s.cx & 0xffffu));
  }
  L005723a3: { // 0x5723a3: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x5723a3u;
    s.cx = (f.sp+0x00000040u);
  }
  L005723a7: { // 0x5723a7: 66895c2440 MOV word ptr [ESP + 0x40],BX
    b516_pc=0x5723a7u;
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L005723ac: { // 0x5723ac: e85f840100 CALL 0x0058a810
    b516_pc=0x5723acu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x005723b1u); flags=0x202u;
  }
  L005723b1: { // 0x5723b1: 84c0 TEST AL,AL
    b516_pc=0x5723b1u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005723b3: { // 0x5723b3: 742c JZ 0x005723e1
    b516_pc=0x5723b3u;
    if(integer::condition("JZ",flags)) goto L005723e1;
  }
  L005723b5: { // 0x5723b5: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x5723b5u;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005723b9: { // 0x5723b9: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x5723b9u;
    s.cx = (f.sp+0x00000040u);
  }
  L005723bd: { // 0x5723bd: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x5723bdu;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005723c0: { // 0x5723c0: e89b93ffff CALL 0x0056b760
    b516_pc=0x5723c0u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x005723c5u); flags=0x202u;
  }
  L005723c5: { // 0x5723c5: 8d542440 LEA EDX,[ESP + 0x40]
    b516_pc=0x5723c5u;
    s.dx = (f.sp+0x00000040u);
  }
  L005723c9: { // 0x5723c9: b920a88100 MOV ECX,0x81a820
    b516_pc=0x5723c9u;
    s.cx = 0x0081a820u;
  }
  L005723ce: { // 0x5723ce: 52 PUSH EDX
    b516_pc=0x5723ceu;
    f.push(m,s.dx);
  }
  L005723cf: { // 0x5723cf: e82c31fdff CALL 0x00545500
    b516_pc=0x5723cfu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x005723d4u); flags=0x202u;
  }
  L005723d4: { // 0x5723d4: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x5723d4u;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L005723d7: { // 0x5723d7: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x5723d7u;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L005723db: { // 0x5723db: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x5723dbu;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005723e1: { // 0x5723e1: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    b516_pc=0x5723e1u;
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L005723e5: { // 0x5723e5: 43 INC EBX
    b516_pc=0x5723e5u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005723e6: { // 0x5723e6: 8d4602 LEA EAX,[ESI + 0x2]
    b516_pc=0x5723e6u;
    s.ax = (s.si+0x00000002u);
  }
  L005723e9: { // 0x5723e9: 3bd8 CMP EBX,EAX
    b516_pc=0x5723e9u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005723eb: { // 0x5723eb: 7cb1 JL 0x0057239e
    b516_pc=0x5723ebu;
    if(integer::condition("JL",flags)) goto L0057239e;
  }
  L005723ed: { // 0x5723ed: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    b516_pc=0x5723edu;
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005723f1: { // 0x5723f1: 41 INC ECX
    b516_pc=0x5723f1u;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005723f2: { // 0x5723f2: 3bca CMP ECX,EDX
    b516_pc=0x5723f2u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005723f4: { // 0x5723f4: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    b516_pc=0x5723f4u;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L005723f8: { // 0x5723f8: 7c9e JL 0x00572398
    b516_pc=0x5723f8u;
    if(integer::condition("JL",flags)) goto L00572398;
  }
  L005723fa: { // 0x5723fa: 0fbf7702 MOVSX ESI,word ptr [EDI + 0x2]
    b516_pc=0x5723fau;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005723fe: { // 0x5723fe: 0fbf1f MOVSX EBX,word ptr [EDI]
    b516_pc=0x5723feu;
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00572401: { // 0x572401: 4e DEC ESI
    b516_pc=0x572401u;
    s.si = integer::decrement(s.si,32,flags);
  }
  L00572402: { // 0x572402: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    b516_pc=0x572402u;
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L00572406: { // 0x572406: 8d4e02 LEA ECX,[ESI + 0x2]
    b516_pc=0x572406u;
    s.cx = (s.si+0x00000002u);
  }
  L00572409: { // 0x572409: 3bf1 CMP ESI,ECX
    b516_pc=0x572409u;
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0057240b: { // 0x57240b: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    b516_pc=0x57240bu;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0057240f: { // 0x57240f: 7d61 JGE 0x00572472
    b516_pc=0x57240fu;
    if(integer::condition("JGE",flags)) goto L00572472;
  }
  L00572411: { // 0x572411: 8d4301 LEA EAX,[EBX + 0x1]
    b516_pc=0x572411u;
    s.ax = (s.bx+0x00000001u);
  }
  L00572414: { // 0x572414: 3bd8 CMP EBX,EAX
    b516_pc=0x572414u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572416: { // 0x572416: 7d55 JGE 0x0057246d
    b516_pc=0x572416u;
    if(integer::condition("JGE",flags)) goto L0057246d;
  }
  L00572418: { // 0x572418: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x572418u;
    s.cx = (f.sp+0x00000040u);
  }
  L0057241c: { // 0x57241c: 66895c2440 MOV word ptr [ESP + 0x40],BX
    b516_pc=0x57241cu;
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L00572421: { // 0x572421: 6689742442 MOV word ptr [ESP + 0x42],SI
    b516_pc=0x572421u;
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L00572426: { // 0x572426: e8e5830100 CALL 0x0058a810
    b516_pc=0x572426u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x0057242bu); flags=0x202u;
  }
  L0057242b: { // 0x57242b: 84c0 TEST AL,AL
    b516_pc=0x57242bu;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057242d: { // 0x57242d: 742c JZ 0x0057245b
    b516_pc=0x57242du;
    if(integer::condition("JZ",flags)) goto L0057245b;
  }
  L0057242f: { // 0x57242f: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    b516_pc=0x57242fu;
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00572433: { // 0x572433: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x572433u;
    s.cx = (f.sp+0x00000040u);
  }
  L00572437: { // 0x572437: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    b516_pc=0x572437u;
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0057243a: { // 0x57243a: e82193ffff CALL 0x0056b760
    b516_pc=0x57243au;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x0057243fu); flags=0x202u;
  }
  L0057243f: { // 0x57243f: 8d442440 LEA EAX,[ESP + 0x40]
    b516_pc=0x57243fu;
    s.ax = (f.sp+0x00000040u);
  }
  L00572443: { // 0x572443: b920a88100 MOV ECX,0x81a820
    b516_pc=0x572443u;
    s.cx = 0x0081a820u;
  }
  L00572448: { // 0x572448: 50 PUSH EAX
    b516_pc=0x572448u;
    f.push(m,s.ax);
  }
  L00572449: { // 0x572449: e8b230fdff CALL 0x00545500
    b516_pc=0x572449u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x0057244eu); flags=0x202u;
  }
  L0057244e: { // 0x57244e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    b516_pc=0x57244eu;
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00572452: { // 0x572452: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    b516_pc=0x572452u;
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L00572455: { // 0x572455: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    b516_pc=0x572455u;
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0057245b: { // 0x57245b: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    b516_pc=0x57245bu;
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0057245f: { // 0x57245f: 43 INC EBX
    b516_pc=0x57245fu;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00572460: { // 0x572460: 40 INC EAX
    b516_pc=0x572460u;
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00572461: { // 0x572461: 3bd8 CMP EBX,EAX
    b516_pc=0x572461u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00572463: { // 0x572463: 7cb3 JL 0x00572418
    b516_pc=0x572463u;
    if(integer::condition("JL",flags)) goto L00572418;
  }
  L00572465: { // 0x572465: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    b516_pc=0x572465u;
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00572469: { // 0x572469: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x572469u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0057246d: { // 0x57246d: 46 INC ESI
    b516_pc=0x57246du;
    s.si = integer::increment(s.si,32,flags);
  }
  L0057246e: { // 0x57246e: 3bf1 CMP ESI,ECX
    b516_pc=0x57246eu;
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00572470: { // 0x572470: 7c9f JL 0x00572411
    b516_pc=0x572470u;
    if(integer::condition("JL",flags)) goto L00572411;
  }
  L00572472: { // 0x572472: 0fbf4500 MOVSX EAX,word ptr [EBP]
    b516_pc=0x572472u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00572476: { // 0x572476: 0fbf5d02 MOVSX EBX,word ptr [EBP + 0x2]
    b516_pc=0x572476u;
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0057247a: { // 0x57247a: 8d4801 LEA ECX,[EAX + 0x1]
    b516_pc=0x57247au;
    s.cx = (s.ax+0x00000001u);
  }
  L0057247d: { // 0x57247d: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    b516_pc=0x57247du;
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00572481: { // 0x572481: 8d5301 LEA EDX,[EBX + 0x1]
    b516_pc=0x572481u;
    s.dx = (s.bx+0x00000001u);
  }
  L00572484: { // 0x572484: 0fbf0f MOVSX ECX,word ptr [EDI]
    b516_pc=0x572484u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00572487: { // 0x572487: 2bc8 SUB ECX,EAX
    b516_pc=0x572487u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00572489: { // 0x572489: 8bf2 MOV ESI,EDX
    b516_pc=0x572489u;
    s.si = s.dx;
  }
  L0057248b: { // 0x57248b: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    b516_pc=0x57248bu;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057248f: { // 0x57248f: 2bc3 SUB EAX,EBX
    b516_pc=0x57248fu;
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00572491: { // 0x572491: 49 DEC ECX
    b516_pc=0x572491u;
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00572492: { // 0x572492: 48 DEC EAX
    b516_pc=0x572492u;
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00572493: { // 0x572493: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x572493u;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00572497: { // 0x572497: 03c2 ADD EAX,EDX
    b516_pc=0x572497u;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00572499: { // 0x572499: 3bd0 CMP EDX,EAX
    b516_pc=0x572499u;
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0057249b: { // 0x57249b: 89442418 MOV dword ptr [ESP + 0x18],EAX
    b516_pc=0x57249bu;
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0057249f: { // 0x57249f: 7d6d JGE 0x0057250e
    b516_pc=0x57249fu;
    if(integer::condition("JGE",flags)) goto L0057250e;
  }
  L005724a1: { // 0x5724a1: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x5724a1u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L005724a5: { // 0x5724a5: 03cb ADD ECX,EBX
    b516_pc=0x5724a5u;
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L005724a7: { // 0x5724a7: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    b516_pc=0x5724a7u;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L005724ab: { // 0x5724ab: 3b5c2444 CMP EBX,dword ptr [ESP + 0x44]
    b516_pc=0x5724abu;
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L005724af: { // 0x5724af: 7d54 JGE 0x00572505
    b516_pc=0x5724afu;
    if(integer::condition("JGE",flags)) goto L00572505;
  }
  L005724b1: { // 0x5724b1: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x5724b1u;
    s.cx = (f.sp+0x00000040u);
  }
  L005724b5: { // 0x5724b5: 66895c2440 MOV word ptr [ESP + 0x40],BX
    b516_pc=0x5724b5u;
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L005724ba: { // 0x5724ba: 6689742442 MOV word ptr [ESP + 0x42],SI
    b516_pc=0x5724bau;
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L005724bf: { // 0x5724bf: e84c830100 CALL 0x0058a810
    b516_pc=0x5724bfu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x005724c4u); flags=0x202u;
  }
  L005724c4: { // 0x5724c4: 84c0 TEST AL,AL
    b516_pc=0x5724c4u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005724c6: { // 0x5724c6: 742c JZ 0x005724f4
    b516_pc=0x5724c6u;
    if(integer::condition("JZ",flags)) goto L005724f4;
  }
  L005724c8: { // 0x5724c8: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x5724c8u;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005724cc: { // 0x5724cc: 8d4c2440 LEA ECX,[ESP + 0x40]
    b516_pc=0x5724ccu;
    s.cx = (f.sp+0x00000040u);
  }
  L005724d0: { // 0x5724d0: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x5724d0u;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005724d3: { // 0x5724d3: e88892ffff CALL 0x0056b760
    b516_pc=0x5724d3u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x005724d8u); flags=0x202u;
  }
  L005724d8: { // 0x5724d8: 8d542440 LEA EDX,[ESP + 0x40]
    b516_pc=0x5724d8u;
    s.dx = (f.sp+0x00000040u);
  }
  L005724dc: { // 0x5724dc: b920a88100 MOV ECX,0x81a820
    b516_pc=0x5724dcu;
    s.cx = 0x0081a820u;
  }
  L005724e1: { // 0x5724e1: 52 PUSH EDX
    b516_pc=0x5724e1u;
    f.push(m,s.dx);
  }
  L005724e2: { // 0x5724e2: e81930fdff CALL 0x00545500
    b516_pc=0x5724e2u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x005724e7u); flags=0x202u;
  }
  L005724e7: { // 0x5724e7: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x5724e7u;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L005724ea: { // 0x5724ea: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    b516_pc=0x5724eau;
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005724ee: { // 0x5724ee: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x5724eeu;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005724f4: { // 0x5724f4: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    b516_pc=0x5724f4u;
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005724f8: { // 0x5724f8: 43 INC EBX
    b516_pc=0x5724f8u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005724f9: { // 0x5724f9: 3bd8 CMP EBX,EAX
    b516_pc=0x5724f9u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005724fb: { // 0x5724fb: 7cb4 JL 0x005724b1
    b516_pc=0x5724fbu;
    if(integer::condition("JL",flags)) goto L005724b1;
  }
  L005724fd: { // 0x5724fd: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    b516_pc=0x5724fdu;
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00572501: { // 0x572501: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x572501u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00572505: { // 0x572505: 46 INC ESI
    b516_pc=0x572505u;
    s.si = integer::increment(s.si,32,flags);
  }
  L00572506: { // 0x572506: 3bf0 CMP ESI,EAX
    b516_pc=0x572506u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00572508: { // 0x572508: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x572508u;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0057250c: { // 0x57250c: 7c9d JL 0x005724ab
    b516_pc=0x57250cu;
    if(integer::condition("JL",flags)) goto L005724ab;
  }
  L0057250e: { // 0x57250e: 668b5500 MOV DX,word ptr [EBP]
    b516_pc=0x57250eu;
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L00572512: { // 0x572512: 668b4502 MOV AX,word ptr [EBP + 0x2]
    b516_pc=0x572512u;
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L00572516: { // 0x572516: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x572516u;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0057251a: { // 0x57251a: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    b516_pc=0x57251au;
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L0057251e: { // 0x57251e: 6683ea03 SUB DX,0x3
    b516_pc=0x57251eu;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L00572522: { // 0x572522: 6689442442 MOV word ptr [ESP + 0x42],AX
    b516_pc=0x572522u;
    m.w16((f.sp+0x00000042u), (s.ax & 0xffffu));
  }
  L00572527: { // 0x572527: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x572527u;
    s.ax = m.r32((0x00a55c70u));
  }
  L0057252c: { // 0x57252c: 6689542440 MOV word ptr [ESP + 0x40],DX
    b516_pc=0x57252cu;
    m.w16((f.sp+0x00000040u), (s.dx & 0xffffu));
  }
  L00572531: { // 0x572531: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    b516_pc=0x572531u;
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00572535: { // 0x572535: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    b516_pc=0x572535u;
    s.dx = m.r32((s.si+0x00000010u));
  }
  L00572538: { // 0x572538: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x572538u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0057253c: { // 0x57253c: 52 PUSH EDX
    b516_pc=0x57253cu;
    f.push(m,s.dx);
  }
  L0057253d: { // 0x57253d: 53 PUSH EBX
    b516_pc=0x57253du;
    f.push(m,s.bx);
  }
  L0057253e: { // 0x57253e: 8d542448 LEA EDX,[ESP + 0x48]
    b516_pc=0x57253eu;
    s.dx = (f.sp+0x00000048u);
  }
  L00572542: { // 0x572542: 8d4807 LEA ECX,[EAX + 0x7]
    b516_pc=0x572542u;
    s.cx = (s.ax+0x00000007u);
  }
  L00572545: { // 0x572545: e8a62c0100 CALL 0x005851f0
    b516_pc=0x572545u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x0057254au); flags=0x202u;
  }
  L0057254a: { // 0x57254a: 668b0f MOV CX,word ptr [EDI]
    b516_pc=0x57254au;
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L0057254d: { // 0x57254d: 668b5702 MOV DX,word ptr [EDI + 0x2]
    b516_pc=0x57254du;
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L00572551: { // 0x572551: 6683e902 SUB CX,0x2
    b516_pc=0x572551u;
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),0x00000002u,16,flags));
  }
  L00572555: { // 0x572555: 668954244a MOV word ptr [ESP + 0x4a],DX
    b516_pc=0x572555u;
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L0057255a: { // 0x57255a: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x57255au;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L0057255f: { // 0x57255f: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x57255fu;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00572563: { // 0x572563: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    b516_pc=0x572563u;
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00572566: { // 0x572566: 89442448 MOV dword ptr [ESP + 0x48],EAX
    b516_pc=0x572566u;
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0057256a: { // 0x57256a: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x57256au;
    s.ax = m.r32((0x00a55c70u));
  }
  L0057256f: { // 0x57256f: 51 PUSH ECX
    b516_pc=0x57256fu;
    f.push(m,s.cx);
  }
  L00572570: { // 0x572570: 53 PUSH EBX
    b516_pc=0x572570u;
    f.push(m,s.bx);
  }
  L00572571: { // 0x572571: 8d542450 LEA EDX,[ESP + 0x50]
    b516_pc=0x572571u;
    s.dx = (f.sp+0x00000050u);
  }
  L00572575: { // 0x572575: 8d4801 LEA ECX,[EAX + 0x1]
    b516_pc=0x572575u;
    s.cx = (s.ax+0x00000001u);
  }
  L00572578: { // 0x572578: e8732c0100 CALL 0x005851f0
    b516_pc=0x572578u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x0057257du); flags=0x202u;
  }
  L0057257d: { // 0x57257d: 33db XOR EBX,EBX
    b516_pc=0x57257du;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057257f: { // 0x57257f: 668b4d00 MOV CX,word ptr [EBP]
    b516_pc=0x57257fu;
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00572583: { // 0x572583: 668bd3 MOV DX,BX
    b516_pc=0x572583u;
    s.dx = with_ax(s.dx, (s.bx & 0xffffu));
  }
  L00572586: { // 0x572586: 66035702 ADD DX,word ptr [EDI + 0x2]
    b516_pc=0x572586u;
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L0057258a: { // 0x57258a: 662bcb SUB CX,BX
    b516_pc=0x57258au;
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L0057258d: { // 0x57258d: 8d442448 LEA EAX,[ESP + 0x48]
    b516_pc=0x57258du;
    s.ax = (f.sp+0x00000048u);
  }
  L00572591: { // 0x572591: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x572591u;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L00572596: { // 0x572596: 50 PUSH EAX
    b516_pc=0x572596u;
    f.push(m,s.ax);
  }
  L00572597: { // 0x572597: b920a88100 MOV ECX,0x81a820
    b516_pc=0x572597u;
    s.cx = 0x0081a820u;
  }
  L0057259c: { // 0x57259c: 668954244e MOV word ptr [ESP + 0x4e],DX
    b516_pc=0x57259cu;
    m.w16((f.sp+0x0000004eu), (s.dx & 0xffffu));
  }
  L005725a1: { // 0x5725a1: e85a2ffdff CALL 0x00545500
    b516_pc=0x5725a1u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x005725a6u); flags=0x202u;
  }
  L005725a6: { // 0x5725a6: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x5725a6u;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L005725a9: { // 0x5725a9: c6801c01000008 MOV byte ptr [EAX + 0x11c],0x8
    b516_pc=0x5725a9u;
    m.w8((s.ax+0x0000011cu), 0x00000008u);
  }
  L005725b0: { // 0x5725b0: 2acb SUB CL,BL
    b516_pc=0x5725b0u;
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L005725b2: { // 0x5725b2: fec9 DEC CL
    b516_pc=0x5725b2u;
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L005725b4: { // 0x5725b4: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x5725b4u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005725ba: { // 0x5725ba: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    b516_pc=0x5725bau;
    s.dx = m.r32((0x00a55c50u));
  }
  L005725c0: { // 0x5725c0: 83c207 ADD EDX,0x7
    b516_pc=0x5725c0u;
    s.dx = integer::add(s.dx,0x00000007u,32,flags);
  }
  L005725c3: { // 0x5725c3: 43 INC EBX
    b516_pc=0x5725c3u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005725c4: { // 0x5725c4: 83fb04 CMP EBX,0x4
    b516_pc=0x5725c4u;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L005725c7: { // 0x5725c7: 895038 MOV dword ptr [EAX + 0x38],EDX
    b516_pc=0x5725c7u;
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005725ca: { // 0x5725ca: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x5725cau;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L005725d1: { // 0x5725d1: 7cac JL 0x0057257f
    b516_pc=0x5725d1u;
    if(integer::condition("JL",flags)) goto L0057257f;
  }
  L005725d3: { // 0x5725d3: 33db XOR EBX,EBX
    b516_pc=0x5725d3u;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005725d5: { // 0x5725d5: 668b4502 MOV AX,word ptr [EBP + 0x2]
    b516_pc=0x5725d5u;
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L005725d9: { // 0x5725d9: 33f6 XOR ESI,ESI
    b516_pc=0x5725d9u;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005725db: { // 0x5725db: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    b516_pc=0x5725dbu;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005725df: { // 0x5725df: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x5725dfu;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005725e2: { // 0x5725e2: 2bd1 SUB EDX,ECX
    b516_pc=0x5725e2u;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005725e4: { // 0x5725e4: 8d4c1afd LEA ECX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x5725e4u;
    s.cx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L005725e8: { // 0x5725e8: 85c9 TEST ECX,ECX
    b516_pc=0x5725e8u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005725ea: { // 0x5725ea: 7e62 JLE 0x0057264e
    b516_pc=0x5725eau;
    if(integer::condition("JLE",flags)) goto L0057264e;
  }
  L005725ec: { // 0x5725ec: 668b5500 MOV DX,word ptr [EBP]
    b516_pc=0x5725ecu;
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L005725f0: { // 0x5725f0: 8d4c2448 LEA ECX,[ESP + 0x48]
    b516_pc=0x5725f0u;
    s.cx = (f.sp+0x00000048u);
  }
  L005725f4: { // 0x5725f4: 662bd3 SUB DX,BX
    b516_pc=0x5725f4u;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L005725f7: { // 0x5725f7: 8d443003 LEA EAX,[EAX + ESI*0x1 + 0x3]
    b516_pc=0x5725f7u;
    s.ax = (s.ax+(s.si * 0x00000001u)+0x00000003u);
  }
  L005725fb: { // 0x5725fb: 51 PUSH ECX
    b516_pc=0x5725fbu;
    f.push(m,s.cx);
  }
  L005725fc: { // 0x5725fc: b920a88100 MOV ECX,0x81a820
    b516_pc=0x5725fcu;
    s.cx = 0x0081a820u;
  }
  L00572601: { // 0x572601: 668954244c MOV word ptr [ESP + 0x4c],DX
    b516_pc=0x572601u;
    m.w16((f.sp+0x0000004cu), (s.dx & 0xffffu));
  }
  L00572606: { // 0x572606: 668944244e MOV word ptr [ESP + 0x4e],AX
    b516_pc=0x572606u;
    m.w16((f.sp+0x0000004eu), (s.ax & 0xffffu));
  }
  L0057260b: { // 0x57260b: e8f02efdff CALL 0x00545500
    b516_pc=0x57260bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00572610u); flags=0x202u;
  }
  L00572610: { // 0x572610: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    b516_pc=0x572610u;
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00572614: { // 0x572614: 8a4a10 MOV CL,byte ptr [EDX + 0x10]
    b516_pc=0x572614u;
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000010u)));
  }
  L00572617: { // 0x572617: c6801c01000001 MOV byte ptr [EAX + 0x11c],0x1
    b516_pc=0x572617u;
    m.w8((s.ax+0x0000011cu), 0x00000001u);
  }
  L0057261e: { // 0x57261e: 2acb SUB CL,BL
    b516_pc=0x57261eu;
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00572620: { // 0x572620: fec9 DEC CL
    b516_pc=0x572620u;
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L00572622: { // 0x572622: 46 INC ESI
    b516_pc=0x572622u;
    s.si = integer::increment(s.si,32,flags);
  }
  L00572623: { // 0x572623: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x572623u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00572629: { // 0x572629: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    b516_pc=0x572629u;
    s.dx = m.r32((0x00a55c50u));
  }
  L0057262f: { // 0x57262f: 895038 MOV dword ptr [EAX + 0x38],EDX
    b516_pc=0x57262fu;
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L00572632: { // 0x572632: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x572632u;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00572639: { // 0x572639: 668b4502 MOV AX,word ptr [EBP + 0x2]
    b516_pc=0x572639u;
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L0057263d: { // 0x57263d: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    b516_pc=0x57263du;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00572641: { // 0x572641: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x572641u;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00572644: { // 0x572644: 2bd1 SUB EDX,ECX
    b516_pc=0x572644u;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00572646: { // 0x572646: 8d4c1afd LEA ECX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x572646u;
    s.cx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L0057264a: { // 0x57264a: 3bf1 CMP ESI,ECX
    b516_pc=0x57264au;
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0057264c: { // 0x57264c: 7c9e JL 0x005725ec
    b516_pc=0x57264cu;
    if(integer::condition("JL",flags)) goto L005725ec;
  }
  L0057264e: { // 0x57264e: 43 INC EBX
    b516_pc=0x57264eu;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0057264f: { // 0x57264f: 83fb04 CMP EBX,0x4
    b516_pc=0x57264fu;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00572652: { // 0x572652: 7c81 JL 0x005725d5
    b516_pc=0x572652u;
    if(integer::condition("JL",flags)) goto L005725d5;
  }
  L00572654: { // 0x572654: 33db XOR EBX,EBX
    b516_pc=0x572654u;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00572656: { // 0x572656: 668b07 MOV AX,word ptr [EDI]
    b516_pc=0x572656u;
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00572659: { // 0x572659: 33f6 XOR ESI,ESI
    b516_pc=0x572659u;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057265b: { // 0x57265b: 0fbf4d00 MOVSX ECX,word ptr [EBP]
    b516_pc=0x57265bu;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L0057265f: { // 0x57265f: 0fbfd0 MOVSX EDX,AX
    b516_pc=0x57265fu;
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00572662: { // 0x572662: 2bd1 SUB EDX,ECX
    b516_pc=0x572662u;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00572664: { // 0x572664: 8d541afd LEA EDX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x572664u;
    s.dx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L00572668: { // 0x572668: 85d2 TEST EDX,EDX
    b516_pc=0x572668u;
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057266a: { // 0x57266a: 7e65 JLE 0x005726d1
    b516_pc=0x57266au;
    if(integer::condition("JLE",flags)) goto L005726d1;
  }
  L0057266c: { // 0x57266c: 2bc6 SUB EAX,ESI
    b516_pc=0x57266cu;
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0057266e: { // 0x57266e: 8d4c2448 LEA ECX,[ESP + 0x48]
    b516_pc=0x57266eu;
    s.cx = (f.sp+0x00000048u);
  }
  L00572672: { // 0x572672: 83e803 SUB EAX,0x3
    b516_pc=0x572672u;
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00572675: { // 0x572675: 51 PUSH ECX
    b516_pc=0x572675u;
    f.push(m,s.cx);
  }
  L00572676: { // 0x572676: 668944244c MOV word ptr [ESP + 0x4c],AX
    b516_pc=0x572676u;
    m.w16((f.sp+0x0000004cu), (s.ax & 0xffffu));
  }
  L0057267b: { // 0x57267b: 668bc3 MOV AX,BX
    b516_pc=0x57267bu;
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0057267e: { // 0x57267e: 66034702 ADD AX,word ptr [EDI + 0x2]
    b516_pc=0x57267eu;
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00572682: { // 0x572682: b920a88100 MOV ECX,0x81a820
    b516_pc=0x572682u;
    s.cx = 0x0081a820u;
  }
  L00572687: { // 0x572687: 668944244e MOV word ptr [ESP + 0x4e],AX
    b516_pc=0x572687u;
    m.w16((f.sp+0x0000004eu), (s.ax & 0xffffu));
  }
  L0057268c: { // 0x57268c: e86f2efdff CALL 0x00545500
    b516_pc=0x57268cu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00572691u); flags=0x202u;
  }
  L00572691: { // 0x572691: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    b516_pc=0x572691u;
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00572695: { // 0x572695: 8a4a10 MOV CL,byte ptr [EDX + 0x10]
    b516_pc=0x572695u;
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000010u)));
  }
  L00572698: { // 0x572698: c6801c01000004 MOV byte ptr [EAX + 0x11c],0x4
    b516_pc=0x572698u;
    m.w8((s.ax+0x0000011cu), 0x00000004u);
  }
  L0057269f: { // 0x57269f: 2acb SUB CL,BL
    b516_pc=0x57269fu;
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L005726a1: { // 0x5726a1: fec9 DEC CL
    b516_pc=0x5726a1u;
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L005726a3: { // 0x5726a3: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x5726a3u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005726a9: { // 0x5726a9: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    b516_pc=0x5726a9u;
    s.dx = m.r32((0x00a55c50u));
  }
  L005726af: { // 0x5726af: 83c203 ADD EDX,0x3
    b516_pc=0x5726afu;
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L005726b2: { // 0x5726b2: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x5726b2u;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L005726b9: { // 0x5726b9: 895038 MOV dword ptr [EAX + 0x38],EDX
    b516_pc=0x5726b9u;
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005726bc: { // 0x5726bc: 668b07 MOV AX,word ptr [EDI]
    b516_pc=0x5726bcu;
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L005726bf: { // 0x5726bf: 0fbf5500 MOVSX EDX,word ptr [EBP]
    b516_pc=0x5726bfu;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005726c3: { // 0x5726c3: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x5726c3u;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005726c6: { // 0x5726c6: 2bca SUB ECX,EDX
    b516_pc=0x5726c6u;
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L005726c8: { // 0x5726c8: 46 INC ESI
    b516_pc=0x5726c8u;
    s.si = integer::increment(s.si,32,flags);
  }
  L005726c9: { // 0x5726c9: 8d4c19fd LEA ECX,[ECX + EBX*0x1 + -0x3]
    b516_pc=0x5726c9u;
    s.cx = (s.cx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L005726cd: { // 0x5726cd: 3bf1 CMP ESI,ECX
    b516_pc=0x5726cdu;
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005726cf: { // 0x5726cf: 7c9b JL 0x0057266c
    b516_pc=0x5726cfu;
    if(integer::condition("JL",flags)) goto L0057266c;
  }
  L005726d1: { // 0x5726d1: 43 INC EBX
    b516_pc=0x5726d1u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005726d2: { // 0x5726d2: 83fb04 CMP EBX,0x4
    b516_pc=0x5726d2u;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L005726d5: { // 0x5726d5: 0f8c7bffffff JL 0x00572656
    b516_pc=0x5726d5u;
    if(integer::condition("JL",flags)) goto L00572656;
  }
  L005726db: { // 0x5726db: 5f POP EDI
    b516_pc=0x5726dbu;
    const auto value=f.pop(m); s.di = value;
  }
  L005726dc: { // 0x5726dc: 5e POP ESI
    b516_pc=0x5726dcu;
    const auto value=f.pop(m); s.si = value;
  }
  L005726dd: { // 0x5726dd: 5d POP EBP
    b516_pc=0x5726ddu;
    const auto value=f.pop(m); s.bp = value;
  }
  L005726de: { // 0x5726de: b001 MOV AL,0x1
    b516_pc=0x5726deu;
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005726e0: { // 0x5726e0: 5b POP EBX
    b516_pc=0x5726e0u;
    const auto value=f.pop(m); s.bx = value;
  }
  L005726e1: { // 0x5726e1: 83c42c ADD ESP,0x2c
    b516_pc=0x5726e1u;
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005726e4: { // 0x5726e4: c20c00 RET 0xc
    b516_pc=0x5726e4u;
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005726e7: { // 0x5726e7: 5f POP EDI
    b516_pc=0x5726e7u;
    const auto value=f.pop(m); s.di = value;
  }
  L005726e8: { // 0x5726e8: 5e POP ESI
    b516_pc=0x5726e8u;
    const auto value=f.pop(m); s.si = value;
  }
  L005726e9: { // 0x5726e9: 5d POP EBP
    b516_pc=0x5726e9u;
    const auto value=f.pop(m); s.bp = value;
  }
  L005726ea: { // 0x5726ea: 32c0 XOR AL,AL
    b516_pc=0x5726eau;
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005726ec: { // 0x5726ec: 5b POP EBX
    b516_pc=0x5726ecu;
    const auto value=f.pop(m); s.bx = value;
  }
  L005726ed: { // 0x5726ed: 83c42c ADD ESP,0x2c
    b516_pc=0x5726edu;
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005726f0: { // 0x5726f0: c20c00 RET 0xc
    b516_pc=0x5726f0u;
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
} // namespace

namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 (void)continuation; floating_b61::Inputs q{};q.ax=s.ax;q.cx=s.cx;q.dx=s.dx;q.fp=s.fp;
 for(unsigned n=0;n<q.arg.size();++n)q.arg[n]=m.r32(f.sp+4u*n);
 std::uint32_t result=0,cleanup=0;
 switch(target){
 case 0x00572700u:result=ra2::recovered::map_b87::fun_00572700(m,q);cleanup=8;break;
 case 0x0058a810u:result=ra2::recovered::global_b26::fun_0058a810(m,q);break;
 case 0x0056b760u:result=ra2::recovered::global_b26::fun_0056b760(m,q);break;
 case 0x00545500u:result=ra2::recovered::global_b26::fun_00545500(m,q);cleanup=4;break;
 case 0x00572ad0u:result=ra2::recovered::global_b26::fun_00572ad0(m,q);break;
 case 0x005851f0u:result=ra2::recovered::map_footprint_b460::fun_005851f0(m,q);cleanup=8;break;
 default:throw std::domain_error("B516 unreviewed call target");}
 for(unsigned n=0;n<q.arg.size();++n)m.w32(f.sp+4u*n,q.arg[n]);
 m.w32(f.sp-4u,continuation);s.ax=result;s.fp=q.fp;f.sp+=cleanup;
}
struct Result{std::uint32_t eax;std::array<std::uint32_t,16> args;};
Result run(Memory&original,const floating_b61::Inputs&i,void(*fn)(Memory&,State&,Frame&,const Operations&)){
 Memory m=original;
 constexpr std::uint32_t base=0x7d000000u,sp=base+0x6004u,outer=0x76543210u;
 std::array<std::uint8_t,0x8000> stack{};leaf::Memory sm(stack.data(),base,stack.size());m.add(sm);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{sp,sp,outer};m.w32(sp,outer);for(unsigned n=0;n<i.arg.size();++n)m.w32(sp+4u+n*4u,i.arg[n]);
 const Operations op{};try{fn(m,s,f,op);}catch(const std::exception&e){throw std::runtime_error("B516 pc="+std::to_string(b516_pc)+" "+e.what());}i.fp=s.fp;Result r{};r.eax=s.ax;for(unsigned n=0;n<r.args.size();++n)r.args[n]=m.r32(sp+4u+n*4u);return r;
}
}
Result fun_005721e0(Memory&m,const floating_b61::Inputs&i){return run(m,i,f_001721e0);}
Result fun_00571720(Memory&m,const floating_b61::Inputs&i){return run(m,i,f_00171720);}
}

namespace ra2::recovered::recovery_b516 {
using floating_b61::Memory;using floating_b61::Inputs;
std::uint32_t fun_005721e0(Memory&m,const Inputs&i){auto r=map516::fun_005721e0(m,i);i.arg=r.args;return r.eax;}
std::uint32_t fun_00571720(Memory&m,const Inputs&i){auto r=map516::fun_00571720(m,i);i.arg=r.args;return r.eax;}
}
