#include "recovered/recovery_b1545_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1545 {
namespace {
void f_000530a0(Memory&,State&,Frame&,const Operations&);
void f_001ccbd0(Memory&,State&,Frame&,const Operations&);
void f_0001b600(Memory&,State&,Frame&,const Operations&);
void f_0004c750(Memory&,State&,Frame&,const Operations&);
void f_0004c610(Memory&,State&,Frame&,const Operations&);
void f_00025640(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_000530a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004530a0: { // 0x4530a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004530a1: { // 0x4530a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004530a2: { // 0x4530a2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004530a4: { // 0x4530a4: 8b8698040000 MOV EAX,dword ptr [ESI + 0x498]
    s.ax = m.r32((s.si+0x00000498u));
  }
  L004530aa: { // 0x4530aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004530ac: { // 0x4530ac: 7471 JZ 0x0045311f
    if(integer::condition("JZ",flags)) goto L0045311f;
  }
  L004530ae: { // 0x4530ae: e81d9b1700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534451u); flags=s.arithmetic_flags;
  }
  L004530b3: { // 0x4530b3: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004530b8: { // 0x4530b8: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004530be: { // 0x4530be: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004530c0: { // 0x4530c0: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004530c3: { // 0x4530c3: 7407 JZ 0x004530cc
    if(integer::condition("JZ",flags)) goto L004530cc;
  }
  L004530c5: { // 0x4530c5: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L004530ca: { // 0x4530ca: eb02 JMP 0x004530ce
    goto L004530ce;
  }
  L004530cc: { // 0x4530cc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004530ce: { // 0x4530ce: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004530d4: { // 0x4530d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004530d6: { // 0x4530d6: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L004530d9: { // 0x4530d9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004530db: { // 0x4530db: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L004530df: { // 0x4530df: 740d JZ 0x004530ee
    if(integer::condition("JZ",flags)) goto L004530ee;
  }
  L004530e1: { // 0x4530e1: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004530e7: { // 0x4530e7: 0568110000 ADD EAX,0x1168
    s.ax = integer::add(s.ax,0x00001168u,32,flags);
  }
  L004530ec: { // 0x4530ec: eb16 JMP 0x00453104
    goto L00453104;
  }
  L004530ee: { // 0x4530ee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004530f0: { // 0x4530f0: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004530f6: { // 0x4530f6: 7407 JZ 0x004530ff
    if(integer::condition("JZ",flags)) goto L004530ff;
  }
  L004530f8: { // 0x4530f8: 0578110000 ADD EAX,0x1178
    s.ax = integer::add(s.ax,0x00001178u,32,flags);
  }
  L004530fd: { // 0x4530fd: eb05 JMP 0x00453104
    goto L00453104;
  }
  L004530ff: { // 0x4530ff: 0558110000 ADD EAX,0x1158
    s.ax = integer::add(s.ax,0x00001158u,32,flags);
  }
  L00453104: { // 0x453104: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453106: { // 0x453106: 7417 JZ 0x0045311f
    if(integer::condition("JZ",flags)) goto L0045311f;
  }
  L00453108: { // 0x453108: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L0045310b: { // 0x45310b: 7412 JZ 0x0045311f
    if(integer::condition("JZ",flags)) goto L0045311f;
  }
  L0045310d: { // 0x45310d: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00453111: { // 0x453111: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00453113: { // 0x453113: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00453114: { // 0x453114: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453115: { // 0x453115: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  L00453117: { // 0x453117: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00453118: { // 0x453118: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0045311a: { // 0x45311a: e83196ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534559u); flags=s.arithmetic_flags;
  }
  L0045311f: { // 0x45311f: 8b8660040000 MOV EAX,dword ptr [ESI + 0x460]
    s.ax = m.r32((s.si+0x00000460u));
  }
  L00453125: { // 0x453125: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453127: { // 0x453127: 7473 JZ 0x0045319c
    if(integer::condition("JZ",flags)) goto L0045319c;
  }
  L00453129: { // 0x453129: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0045312b: { // 0x45312b: e8a09a1700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534576u); flags=s.arithmetic_flags;
  }
  L00453130: { // 0x453130: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00453135: { // 0x453135: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0045313b: { // 0x45313b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0045313d: { // 0x45313d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00453140: { // 0x453140: 7407 JZ 0x00453149
    if(integer::condition("JZ",flags)) goto L00453149;
  }
  L00453142: { // 0x453142: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00453147: { // 0x453147: eb02 JMP 0x0045314b
    goto L0045314b;
  }
  L00453149: { // 0x453149: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0045314b: { // 0x45314b: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00453151: { // 0x453151: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453153: { // 0x453153: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L00453156: { // 0x453156: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00453158: { // 0x453158: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L0045315c: { // 0x45315c: 740d JZ 0x0045316b
    if(integer::condition("JZ",flags)) goto L0045316b;
  }
  L0045315e: { // 0x45315e: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00453164: { // 0x453164: 05b00d0000 ADD EAX,0xdb0
    s.ax = integer::add(s.ax,0x00000db0u,32,flags);
  }
  L00453169: { // 0x453169: eb16 JMP 0x00453181
    goto L00453181;
  }
  L0045316b: { // 0x45316b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0045316d: { // 0x45316d: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00453173: { // 0x453173: 7407 JZ 0x0045317c
    if(integer::condition("JZ",flags)) goto L0045317c;
  }
  L00453175: { // 0x453175: 05c00d0000 ADD EAX,0xdc0
    s.ax = integer::add(s.ax,0x00000dc0u,32,flags);
  }
  L0045317a: { // 0x45317a: eb05 JMP 0x00453181
    goto L00453181;
  }
  L0045317c: { // 0x45317c: 05a00d0000 ADD EAX,0xda0
    s.ax = integer::add(s.ax,0x00000da0u,32,flags);
  }
  L00453181: { // 0x453181: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453183: { // 0x453183: 7417 JZ 0x0045319c
    if(integer::condition("JZ",flags)) goto L0045319c;
  }
  L00453185: { // 0x453185: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L00453188: { // 0x453188: 7412 JZ 0x0045319c
    if(integer::condition("JZ",flags)) goto L0045319c;
  }
  L0045318a: { // 0x45318a: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0045318e: { // 0x45318e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00453190: { // 0x453190: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00453191: { // 0x453191: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453192: { // 0x453192: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L00453194: { // 0x453194: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00453195: { // 0x453195: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453197: { // 0x453197: e8b495ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534684u); flags=s.arithmetic_flags;
  }
  L0045319c: { // 0x45319c: 8b8664040000 MOV EAX,dword ptr [ESI + 0x464]
    s.ax = m.r32((s.si+0x00000464u));
  }
  L004531a2: { // 0x4531a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004531a4: { // 0x4531a4: 7473 JZ 0x00453219
    if(integer::condition("JZ",flags)) goto L00453219;
  }
  L004531a6: { // 0x4531a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004531a8: { // 0x4531a8: e8239a1700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534701u); flags=s.arithmetic_flags;
  }
  L004531ad: { // 0x4531ad: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004531b2: { // 0x4531b2: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004531b8: { // 0x4531b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004531ba: { // 0x4531ba: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004531bd: { // 0x4531bd: 7407 JZ 0x004531c6
    if(integer::condition("JZ",flags)) goto L004531c6;
  }
  L004531bf: { // 0x4531bf: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L004531c4: { // 0x4531c4: eb02 JMP 0x004531c8
    goto L004531c8;
  }
  L004531c6: { // 0x4531c6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004531c8: { // 0x4531c8: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004531ce: { // 0x4531ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004531d0: { // 0x4531d0: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L004531d3: { // 0x4531d3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004531d5: { // 0x4531d5: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L004531d9: { // 0x4531d9: 740d JZ 0x004531e8
    if(integer::condition("JZ",flags)) goto L004531e8;
  }
  L004531db: { // 0x4531db: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004531e1: { // 0x4531e1: 05f40d0000 ADD EAX,0xdf4
    s.ax = integer::add(s.ax,0x00000df4u,32,flags);
  }
  L004531e6: { // 0x4531e6: eb16 JMP 0x004531fe
    goto L004531fe;
  }
  L004531e8: { // 0x4531e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004531ea: { // 0x4531ea: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004531f0: { // 0x4531f0: 7407 JZ 0x004531f9
    if(integer::condition("JZ",flags)) goto L004531f9;
  }
  L004531f2: { // 0x4531f2: 05040e0000 ADD EAX,0xe04
    s.ax = integer::add(s.ax,0x00000e04u,32,flags);
  }
  L004531f7: { // 0x4531f7: eb05 JMP 0x004531fe
    goto L004531fe;
  }
  L004531f9: { // 0x4531f9: 05e40d0000 ADD EAX,0xde4
    s.ax = integer::add(s.ax,0x00000de4u,32,flags);
  }
  L004531fe: { // 0x4531fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453200: { // 0x453200: 7417 JZ 0x00453219
    if(integer::condition("JZ",flags)) goto L00453219;
  }
  L00453202: { // 0x453202: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L00453205: { // 0x453205: 7412 JZ 0x00453219
    if(integer::condition("JZ",flags)) goto L00453219;
  }
  L00453207: { // 0x453207: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0045320b: { // 0x45320b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0045320d: { // 0x45320d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045320e: { // 0x45320e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045320f: { // 0x45320f: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00453211: { // 0x453211: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00453212: { // 0x453212: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453214: { // 0x453214: e83795ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534809u); flags=s.arithmetic_flags;
  }
  L00453219: { // 0x453219: 8b8668040000 MOV EAX,dword ptr [ESI + 0x468]
    s.ax = m.r32((s.si+0x00000468u));
  }
  L0045321f: { // 0x45321f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453221: { // 0x453221: 7473 JZ 0x00453296
    if(integer::condition("JZ",flags)) goto L00453296;
  }
  L00453223: { // 0x453223: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453225: { // 0x453225: e8a6991700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534826u); flags=s.arithmetic_flags;
  }
  L0045322a: { // 0x45322a: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0045322f: { // 0x45322f: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00453235: { // 0x453235: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00453237: { // 0x453237: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0045323a: { // 0x45323a: 7407 JZ 0x00453243
    if(integer::condition("JZ",flags)) goto L00453243;
  }
  L0045323c: { // 0x45323c: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00453241: { // 0x453241: eb02 JMP 0x00453245
    goto L00453245;
  }
  L00453243: { // 0x453243: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00453245: { // 0x453245: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L0045324b: { // 0x45324b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045324d: { // 0x45324d: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L00453250: { // 0x453250: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00453252: { // 0x453252: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L00453256: { // 0x453256: 740d JZ 0x00453265
    if(integer::condition("JZ",flags)) goto L00453265;
  }
  L00453258: { // 0x453258: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0045325e: { // 0x45325e: 05380e0000 ADD EAX,0xe38
    s.ax = integer::add(s.ax,0x00000e38u,32,flags);
  }
  L00453263: { // 0x453263: eb16 JMP 0x0045327b
    goto L0045327b;
  }
  L00453265: { // 0x453265: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00453267: { // 0x453267: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0045326d: { // 0x45326d: 7407 JZ 0x00453276
    if(integer::condition("JZ",flags)) goto L00453276;
  }
  L0045326f: { // 0x45326f: 05480e0000 ADD EAX,0xe48
    s.ax = integer::add(s.ax,0x00000e48u,32,flags);
  }
  L00453274: { // 0x453274: eb05 JMP 0x0045327b
    goto L0045327b;
  }
  L00453276: { // 0x453276: 05280e0000 ADD EAX,0xe28
    s.ax = integer::add(s.ax,0x00000e28u,32,flags);
  }
  L0045327b: { // 0x45327b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045327d: { // 0x45327d: 7417 JZ 0x00453296
    if(integer::condition("JZ",flags)) goto L00453296;
  }
  L0045327f: { // 0x45327f: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L00453282: { // 0x453282: 7412 JZ 0x00453296
    if(integer::condition("JZ",flags)) goto L00453296;
  }
  L00453284: { // 0x453284: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00453288: { // 0x453288: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0045328a: { // 0x45328a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045328b: { // 0x45328b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045328c: { // 0x45328c: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0045328e: { // 0x45328e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045328f: { // 0x45328f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453291: { // 0x453291: e8ba94ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534934u); flags=s.arithmetic_flags;
  }
  L00453296: { // 0x453296: 8b866c040000 MOV EAX,dword ptr [ESI + 0x46c]
    s.ax = m.r32((s.si+0x0000046cu));
  }
  L0045329c: { // 0x45329c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045329e: { // 0x45329e: 7473 JZ 0x00453313
    if(integer::condition("JZ",flags)) goto L00453313;
  }
  L004532a0: { // 0x4532a0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004532a2: { // 0x4532a2: e829991700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534951u); flags=s.arithmetic_flags;
  }
  L004532a7: { // 0x4532a7: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004532ac: { // 0x4532ac: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004532b2: { // 0x4532b2: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004532b4: { // 0x4532b4: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004532b7: { // 0x4532b7: 7407 JZ 0x004532c0
    if(integer::condition("JZ",flags)) goto L004532c0;
  }
  L004532b9: { // 0x4532b9: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L004532be: { // 0x4532be: eb02 JMP 0x004532c2
    goto L004532c2;
  }
  L004532c0: { // 0x4532c0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004532c2: { // 0x4532c2: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004532c8: { // 0x4532c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004532ca: { // 0x4532ca: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L004532cd: { // 0x4532cd: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004532cf: { // 0x4532cf: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L004532d3: { // 0x4532d3: 740d JZ 0x004532e2
    if(integer::condition("JZ",flags)) goto L004532e2;
  }
  L004532d5: { // 0x4532d5: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004532db: { // 0x4532db: 057c0e0000 ADD EAX,0xe7c
    s.ax = integer::add(s.ax,0x00000e7cu,32,flags);
  }
  L004532e0: { // 0x4532e0: eb16 JMP 0x004532f8
    goto L004532f8;
  }
  L004532e2: { // 0x4532e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004532e4: { // 0x4532e4: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004532ea: { // 0x4532ea: 7407 JZ 0x004532f3
    if(integer::condition("JZ",flags)) goto L004532f3;
  }
  L004532ec: { // 0x4532ec: 058c0e0000 ADD EAX,0xe8c
    s.ax = integer::add(s.ax,0x00000e8cu,32,flags);
  }
  L004532f1: { // 0x4532f1: eb05 JMP 0x004532f8
    goto L004532f8;
  }
  L004532f3: { // 0x4532f3: 056c0e0000 ADD EAX,0xe6c
    s.ax = integer::add(s.ax,0x00000e6cu,32,flags);
  }
  L004532f8: { // 0x4532f8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004532fa: { // 0x4532fa: 7417 JZ 0x00453313
    if(integer::condition("JZ",flags)) goto L00453313;
  }
  L004532fc: { // 0x4532fc: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L004532ff: { // 0x4532ff: 7412 JZ 0x00453313
    if(integer::condition("JZ",flags)) goto L00453313;
  }
  L00453301: { // 0x453301: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00453305: { // 0x453305: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00453307: { // 0x453307: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00453308: { // 0x453308: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453309: { // 0x453309: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  L0045330b: { // 0x45330b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045330c: { // 0x45330c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0045330e: { // 0x45330e: e83d94ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4535059u); flags=s.arithmetic_flags;
  }
  L00453313: { // 0x453313: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00453314: { // 0x453314: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00453315: { // 0x453315: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001ccbd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ccbd0: { // 0x5ccbd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L005ccbd3: { // 0x5ccbd3: db416c FILD dword ptr [ECX + 0x6c]
    const auto address=(s.cx+0x0000006cu);
    s.fp.load_integer32(m.r32(address));
  }
  L005ccbd6: { // 0x5ccbd6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005ccbd8: { // 0x5ccbd8: dd5c2400 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005ccbdc: { // 0x5ccbdc: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6081506u); flags=s.arithmetic_flags;
  }
  L005ccbe2: { // 0x5ccbe2: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
  L005ccbe8: { // 0x5ccbe8: dc7c2400 FDIVR double ptr [ESP]
    const auto address=(f.sp);
    reverse_divide64(s.fp,read64(m,address));
  }
  L005ccbec: { // 0x5ccbec: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005ccbef: { // 0x5ccbef: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b600: { // 0x41b600: 8b81ac050000 MOV EAX,dword ptr [ECX + 0x5ac]
    s.ax = m.r32((s.cx+0x000005acu));
  }
  L0041b606: { // 0x41b606: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0004c750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044c750: { // 0x44c750: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L0044c753: { // 0x44c753: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044c754: { // 0x44c754: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L0044c758: { // 0x44c758: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044c759: { // 0x44c759: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044c75a: { // 0x44c75a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0044c75c: { // 0x44c75c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044c75d: { // 0x44c75d: 389eb6050000 CMP byte ptr [ESI + 0x5b6],BL
    (void)integer::sub(m.r8((s.si+0x000005b6u)),(s.bx & 0xffu),8,flags);
  }
  L0044c763: { // 0x44c763: 742a JZ 0x0044c78f
    if(integer::condition("JZ",flags)) goto L0044c78f;
  }
  L0044c765: { // 0x44c765: 889eb6050000 MOV byte ptr [ESI + 0x5b6],BL
    m.w8((s.si+0x000005b6u), (s.bx & 0xffu));
  }
  L0044c76b: { // 0x44c76b: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0044c76d: { // 0x44c76d: 8dae54040000 LEA EBP,[ESI + 0x454]
    s.bp = (s.si+0x00000454u);
  }
  L0044c773: { // 0x44c773: 837d0000 CMP dword ptr [EBP],0x0
    (void)integer::sub(m.r32((s.bp)),0x00000000u,32,flags);
  }
  L0044c777: { // 0x44c777: 740d JZ 0x0044c786
    if(integer::condition("JZ",flags)) goto L0044c786;
  }
  L0044c779: { // 0x44c779: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044c77b: { // 0x44c77b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044c77d: { // 0x44c77d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044c77e: { // 0x44c77e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044c77f: { // 0x44c77f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c781: { // 0x44c781: e88afeffff CALL 0x0044c610
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c610u,4507526u); flags=s.arithmetic_flags;
  }
  L0044c786: { // 0x44c786: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0044c787: { // 0x44c787: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0044c78a: { // 0x44c78a: 83ff12 CMP EDI,0x12
    (void)integer::sub(s.di,0x00000012u,32,flags);
  }
  L0044c78d: { // 0x44c78d: 7ce4 JL 0x0044c773
    if(integer::condition("JL",flags)) goto L0044c773;
  }
  L0044c78f: { // 0x44c78f: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0044c793: { // 0x44c793: e8a88efdff CALL 0x00425640
    s.arithmetic_flags=flags; invoke(m,s,f,0x00425640u,4507544u); flags=s.arithmetic_flags;
  }
  L0044c798: { // 0x44c798: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0044c79a: { // 0x44c79a: 83fdff CMP EBP,-0x1
    (void)integer::sub(s.bp,0xffffffffu,32,flags);
  }
  L0044c79d: { // 0x44c79d: 0f8418020000 JZ 0x0044c9bb
    if(integer::condition("JZ",flags)) goto L0044c9bb;
  }
  L0044c7a3: { // 0x44c7a3: 8b5c243c MOV EBX,dword ptr [ESP + 0x3c]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L0044c7a7: { // 0x44c7a7: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0044c7ad: { // 0x44c7ad: 8d4331 LEA EAX,[EBX + 0x31]
    s.ax = (s.bx+0x00000031u);
  }
  L0044c7b0: { // 0x44c7b0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0044c7b2: { // 0x44c7b2: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0044c7b5: { // 0x44c7b5: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0044c7b7: { // 0x44c7b7: 8d048a LEA EAX,[EDX + ECX*0x4]
    s.ax = (s.dx+(s.cx * 0x00000004u));
  }
  L0044c7ba: { // 0x44c7ba: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0044c7be: { // 0x44c7be: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044c7bf: { // 0x44c7bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044c7c0: { // 0x44c7c0: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0044c7c6: { // 0x44c7c6: e865ba2400 CALL 0x00698230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698230u,4507595u); flags=s.arithmetic_flags;
  }
  L0044c7cb: { // 0x44c7cb: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044c7cd: { // 0x44c7cd: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0044c7cf: { // 0x44c7cf: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0044c7d3: { // 0x44c7d3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c7d5: { // 0x44c7d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044c7d6: { // 0x44c7d6: ff92a8000000 CALL dword ptr [EDX + 0xa8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a8u)),4507612u); flags=s.arithmetic_flags;
  }
  L0044c7dc: { // 0x44c7dc: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0044c7de: { // 0x44c7de: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044c7e0: { // 0x44c7e0: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0044c7e2: { // 0x44c7e2: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0044c7e5: { // 0x44c7e5: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0044c7e8: { // 0x44c7e8: 035704 ADD EDX,dword ptr [EDI + 0x4]
    s.dx = integer::add(s.dx,m.r32((s.di+0x00000004u)),32,flags);
  }
  L0044c7eb: { // 0x44c7eb: 034708 ADD EAX,dword ptr [EDI + 0x8]
    s.ax = integer::add(s.ax,m.r32((s.di+0x00000008u)),32,flags);
  }
  L0044c7ee: { // 0x44c7ee: 68a8010000 PUSH 0x1a8
    f.push(m,0x000001a8u);
  }
  L0044c7f3: { // 0x44c7f3: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0044c7f7: { // 0x44c7f7: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0044c7fb: { // 0x44c7fb: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0044c7ff: { // 0x44c7ff: e853113200 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4507652u); flags=s.arithmetic_flags;
  }
  L0044c804: { // 0x44c804: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0044c807: { // 0x44c807: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044c809: { // 0x44c809: 7428 JZ 0x0044c833
    if(integer::condition("JZ",flags)) goto L0044c833;
  }
  L0044c80b: { // 0x44c80b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0044c80f: { // 0x44c80f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044c811: { // 0x44c811: 6800160000 PUSH 0x1600
    f.push(m,0x00001600u);
  }
  L0044c816: { // 0x44c816: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0044c818: { // 0x44c818: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044c819: { // 0x44c819: 8b0d14e58400 MOV ECX,dword ptr [0x0084e514]
    s.cx = m.r32((0x0084e514u));
  }
  L0044c81f: { // 0x44c81f: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0044c823: { // 0x44c823: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0044c824: { // 0x44c824: 8b14a9 MOV EDX,dword ptr [ECX + EBP*0x4]
    s.dx = m.r32((s.cx+(s.bp * 0x00000004u)));
  }
  L0044c827: { // 0x44c827: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0044c828: { // 0x44c828: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0044c82a: { // 0x44c82a: e8e138fdff CALL 0x00420110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00420110u,4507695u); flags=s.arithmetic_flags;
  }
  L0044c82f: { // 0x44c82f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0044c831: { // 0x44c831: eb02 JMP 0x0044c835
    goto L0044c835;
  }
  L0044c833: { // 0x44c833: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0044c835: { // 0x44c835: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044c83b: { // 0x44c83b: 8beb MOV EBP,EBX
    s.bp = s.bx;
  }
  L0044c83d: { // 0x44c83d: c1e504 SHL EBP,0x4
    s.bp = integer::shift(s.bp,0x00000004u,32,flags,integer::Shift::left);
  }
  L0044c840: { // 0x44c840: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0044c842: { // 0x44c842: c1e502 SHL EBP,0x2
    s.bp = integer::shift(s.bp,0x00000002u,32,flags,integer::Shift::left);
  }
  L0044c845: { // 0x44c845: 8b8c280c0d0000 MOV ECX,dword ptr [EAX + EBP*0x1 + 0xd0c]
    s.cx = m.r32((s.ax+(s.bp * 0x00000001u)+0x00000d0cu));
  }
  L0044c84c: { // 0x44c84c: 898fe8000000 MOV dword ptr [EDI + 0xe8],ECX
    m.w32((s.di+0x000000e8u), s.cx);
  }
  L0044c852: { // 0x44c852: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0044c858: { // 0x44c858: 8b842a100d0000 MOV EAX,dword ptr [EDX + EBP*0x1 + 0xd10]
    s.ax = m.r32((s.dx+(s.bp * 0x00000001u)+0x00000d10u));
  }
  L0044c85f: { // 0x44c85f: c6870001000001 MOV byte ptr [EDI + 0x100],0x1
    m.w8((s.di+0x00000100u), 0x00000001u);
  }
  L0044c866: { // 0x44c866: 8987ec000000 MOV dword ptr [EDI + 0xec],EAX
    m.w32((s.di+0x000000ecu), s.ax);
  }
  L0044c86c: { // 0x44c86c: 8a86b7050000 MOV AL,byte ptr [ESI + 0x5b7]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005b7u)));
  }
  L0044c872: { // 0x44c872: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044c874: { // 0x44c874: 7407 JZ 0x0044c87d
    if(integer::condition("JZ",flags)) goto L0044c87d;
  }
  L0044c876: { // 0x44c876: c6877901000001 MOV byte ptr [EDI + 0x179],0x1
    m.w8((s.di+0x00000179u), 0x00000001u);
  }
  L0044c87d: { // 0x44c87d: 0fbe96bd050000 MOVSX EDX,byte ptr [ESI + 0x5bd]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x000005bdu)),8));
  }
  L0044c884: { // 0x44c884: 83fa0f CMP EDX,0xf
    (void)integer::sub(s.dx,0x0000000fu,32,flags);
  }
  L0044c887: { // 0x44c887: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0044c88b: { // 0x44c88b: 751c JNZ 0x0044c8a9
    if(integer::condition("JNZ",flags)) goto L0044c8a9;
  }
  L0044c88d: { // 0x44c88d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044c88f: { // 0x44c88f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044c891: { // 0x44c891: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044c893: { // 0x44c893: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c895: { // 0x44c895: ff5264 CALL dword ptr [EDX + 0x64]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000064u)),4507800u); flags=s.arithmetic_flags;
  }
  L0044c898: { // 0x44c898: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L0044c89b: { // 0x44c89b: 7508 JNZ 0x0044c8a5
    if(integer::condition("JNZ",flags)) goto L0044c8a5;
  }
  L0044c89d: { // 0x44c89d: c744244010000000 MOV dword ptr [ESP + 0x40],0x10
    m.w32((f.sp+0x00000040u), 0x00000010u);
  }
  L0044c8a5: { // 0x44c8a5: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L0044c8a9: { // 0x44c8a9: 8d8e54040000 LEA ECX,[ESI + 0x454]
    s.cx = (s.si+0x00000454u);
  }
  L0044c8af: { // 0x44c8af: c744244012000000 MOV dword ptr [ESP + 0x40],0x12
    m.w32((f.sp+0x00000040u), 0x00000012u);
  }
  L0044c8b7: { // 0x44c8b7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0044c8b9: { // 0x44c8b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044c8bb: { // 0x44c8bb: 7406 JZ 0x0044c8c3
    if(integer::condition("JZ",flags)) goto L0044c8c3;
  }
  L0044c8bd: { // 0x44c8bd: 889058010000 MOV byte ptr [EAX + 0x158],DL
    m.w8((s.ax+0x00000158u), (s.dx & 0xffu));
  }
  L0044c8c3: { // 0x44c8c3: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L0044c8c7: { // 0x44c8c7: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0044c8ca: { // 0x44c8ca: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0044c8cb: { // 0x44c8cb: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0044c8cf: { // 0x44c8cf: 75e6 JNZ 0x0044c8b7
    if(integer::condition("JNZ",flags)) goto L0044c8b7;
  }
  L0044c8d1: { // 0x44c8d1: 8b849e54040000 MOV EAX,dword ptr [ESI + EBX*0x4 + 0x454]
    s.ax = m.r32((s.si+(s.bx * 0x00000004u)+0x00000454u));
  }
  L0044c8d8: { // 0x44c8d8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044c8da: { // 0x44c8da: 7429 JZ 0x0044c905
    if(integer::condition("JZ",flags)) goto L0044c905;
  }
  L0044c8dc: { // 0x44c8dc: 8b8098000000 MOV EAX,dword ptr [EAX + 0x98]
    s.ax = m.r32((s.ax+0x00000098u));
  }
  L0044c8e2: { // 0x44c8e2: 898798000000 MOV dword ptr [EDI + 0x98],EAX
    m.w32((s.di+0x00000098u), s.ax);
  }
  L0044c8e8: { // 0x44c8e8: 8b8c9e54040000 MOV ECX,dword ptr [ESI + EBX*0x4 + 0x454]
    s.cx = m.r32((s.si+(s.bx * 0x00000004u)+0x00000454u));
  }
  L0044c8ef: { // 0x44c8ef: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044c8f1: { // 0x44c8f1: c7849e5404000000000000 MOV dword ptr [ESI + EBX*0x4 + 0x454],0x0
    m.w32((s.si+(s.bx * 0x00000004u)+0x00000454u), 0x00000000u);
  }
  L0044c8fc: { // 0x44c8fc: 7407 JZ 0x0044c905
    if(integer::condition("JZ",flags)) goto L0044c905;
  }
  L0044c8fe: { // 0x44c8fe: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0044c900: { // 0x44c900: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0044c902: { // 0x44c902: ff5220 CALL dword ptr [EDX + 0x20]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000020u)),4507909u); flags=s.arithmetic_flags;
  }
  L0044c905: { // 0x44c905: 89bc9e54040000 MOV dword ptr [ESI + EBX*0x4 + 0x454],EDI
    m.w32((s.si+(s.bx * 0x00000004u)+0x00000454u), s.di);
  }
  L0044c90c: { // 0x44c90c: 8a86ba050000 MOV AL,byte ptr [ESI + 0x5ba]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005bau)));
  }
  L0044c912: { // 0x44c912: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044c914: { // 0x44c914: 7518 JNZ 0x0044c92e
    if(integer::condition("JNZ",flags)) goto L0044c92e;
  }
  L0044c916: { // 0x44c916: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044c91c: { // 0x44c91c: 8a8c28140d0000 MOV CL,byte ptr [EAX + EBP*0x1 + 0xd14]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.bp * 0x00000001u)+0x00000d14u)));
  }
  L0044c923: { // 0x44c923: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044c925: { // 0x44c925: 7407 JZ 0x0044c92e
    if(integer::condition("JZ",flags)) goto L0044c92e;
  }
  L0044c927: { // 0x44c927: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044c929: { // 0x44c929: e8e262fdff CALL 0x00422c10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00422c10u,4507950u); flags=s.arithmetic_flags;
  }
  L0044c92e: { // 0x44c92e: 8b8fb0000000 MOV ECX,dword ptr [EDI + 0xb0]
    s.cx = m.r32((s.di+0x000000b0u));
  }
  L0044c934: { // 0x44c934: 8a8118030000 MOV AL,byte ptr [ECX + 0x318]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000318u)));
  }
  L0044c93a: { // 0x44c93a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044c93c: { // 0x44c93c: 744c JZ 0x0044c98a
    if(integer::condition("JZ",flags)) goto L0044c98a;
  }
  L0044c93e: { // 0x44c93e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044c940: { // 0x44c940: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c942: { // 0x44c942: ff92cc010000 CALL dword ptr [EDX + 0x1cc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001ccu)),4507976u); flags=s.arithmetic_flags;
  }
  L0044c948: { // 0x44c948: 8987bc000000 MOV dword ptr [EDI + 0xbc],EAX
    m.w32((s.di+0x000000bcu), s.ax);
  }
  L0044c94e: { // 0x44c94e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044c950: { // 0x44c950: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c952: { // 0x44c952: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a4u)),4507992u); flags=s.arithmetic_flags;
  }
  L0044c958: { // 0x44c958: 0fbf800a010000 MOVSX EAX,word ptr [EAX + 0x10a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x0000010au)),16));
  }
  L0044c95f: { // 0x44c95f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044c961: { // 0x44c961: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044c962: { // 0x44c962: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c964: { // 0x44c964: ff92f8030000 CALL dword ptr [EDX + 0x3f8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003f8u)),4508010u); flags=s.arithmetic_flags;
  }
  L0044c96a: { // 0x44c96a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0044c96c: { // 0x44c96c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044c96e: { // 0x44c96e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c970: { // 0x44c970: ff902c030000 CALL dword ptr [EAX + 0x32c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000032cu)),4508022u); flags=s.arithmetic_flags;
  }
  L0044c976: { // 0x44c976: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044c978: { // 0x44c978: 740a JZ 0x0044c984
    if(integer::condition("JZ",flags)) goto L0044c984;
  }
  L0044c97a: { // 0x44c97a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044c97b: { // 0x44c97b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c97d: { // 0x44c97d: e8de122800 CALL 0x006cdc60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cdc60u,4508034u); flags=s.arithmetic_flags;
  }
  L0044c982: { // 0x44c982: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0044c984: { // 0x44c984: 89afe4000000 MOV dword ptr [EDI + 0xe4],EBP
    m.w32((s.di+0x000000e4u), s.bp);
  }
  L0044c98a: { // 0x44c98a: 83fb09 CMP EBX,0x9
    (void)integer::sub(s.bx,0x00000009u,32,flags);
  }
  L0044c98d: { // 0x44c98d: 7517 JNZ 0x0044c9a6
    if(integer::condition("JNZ",flags)) goto L0044c9a6;
  }
  L0044c98f: { // 0x44c98f: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0044c995: { // 0x44c995: 8a8160130000 MOV AL,byte ptr [ECX + 0x1360]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001360u)));
  }
  L0044c99b: { // 0x44c99b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044c99d: { // 0x44c99d: 7407 JZ 0x0044c9a6
    if(integer::condition("JZ",flags)) goto L0044c9a6;
  }
  L0044c99f: { // 0x44c99f: c6877d01000001 MOV byte ptr [EDI + 0x17d],0x1
    m.w8((s.di+0x0000017du), 0x00000001u);
  }
  L0044c9a6: { // 0x44c9a6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044c9a8: { // 0x44c9a8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c9aa: { // 0x44c9aa: ff92bc010000 CALL dword ptr [EDX + 0x1bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001bcu)),4508080u); flags=s.arithmetic_flags;
  }
  L0044c9b0: { // 0x44c9b0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044c9b2: { // 0x44c9b2: 7407 JZ 0x0044c9bb
    if(integer::condition("JZ",flags)) goto L0044c9bb;
  }
  L0044c9b4: { // 0x44c9b4: c6870201000001 MOV byte ptr [EDI + 0x102],0x1
    m.w8((s.di+0x00000102u), 0x00000001u);
  }
  L0044c9bb: { // 0x44c9bb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044c9bc: { // 0x44c9bc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044c9bd: { // 0x44c9bd: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044c9be: { // 0x44c9be: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044c9bf: { // 0x44c9bf: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L0044c9c2: { // 0x44c9c2: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_0004c610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044c610: { // 0x44c610: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044c611: { // 0x44c611: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0044c615: { // 0x44c615: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044c616: { // 0x44c616: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0044c618: { // 0x44c618: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0044c61c: { // 0x44c61c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044c61d: { // 0x44c61d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044c61f: { // 0x44c61f: 741a JZ 0x0044c63b
    if(integer::condition("JZ",flags)) goto L0044c63b;
  }
  L0044c621: { // 0x44c621: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044c625: { // 0x44c625: 8bbe18040000 MOV EDI,dword ptr [ESI + 0x418]
    s.di = m.r32((s.si+0x00000418u));
  }
  L0044c62b: { // 0x44c62b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0044c62d: { // 0x44c62d: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0044c630: { // 0x44c630: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0044c632: { // 0x44c632: 8d9497e40c0000 LEA EDX,[EDI + EDX*0x4 + 0xce4]
    s.dx = (s.di+(s.dx * 0x00000004u)+0x00000ce4u);
  }
  L0044c639: { // 0x44c639: eb30 JMP 0x0044c66b
    goto L0044c66b;
  }
  L0044c63b: { // 0x44c63b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044c63f: { // 0x44c63f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0044c641: { // 0x44c641: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0044c643: { // 0x44c643: 7414 JZ 0x0044c659
    if(integer::condition("JZ",flags)) goto L0044c659;
  }
  L0044c645: { // 0x44c645: 8bbe18040000 MOV EDI,dword ptr [ESI + 0x418]
    s.di = m.r32((s.si+0x00000418u));
  }
  L0044c64b: { // 0x44c64b: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0044c64e: { // 0x44c64e: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0044c650: { // 0x44c650: 8d9497f40c0000 LEA EDX,[EDI + EDX*0x4 + 0xcf4]
    s.dx = (s.di+(s.dx * 0x00000004u)+0x00000cf4u);
  }
  L0044c657: { // 0x44c657: eb12 JMP 0x0044c66b
    goto L0044c66b;
  }
  L0044c659: { // 0x44c659: 8bbe18040000 MOV EDI,dword ptr [ESI + 0x418]
    s.di = m.r32((s.si+0x00000418u));
  }
  L0044c65f: { // 0x44c65f: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0044c662: { // 0x44c662: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0044c664: { // 0x44c664: 8d9497d40c0000 LEA EDX,[EDI + EDX*0x4 + 0xcd4]
    s.dx = (s.di+(s.dx * 0x00000004u)+0x00000cd4u);
  }
  L0044c66b: { // 0x44c66b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0044c66d: { // 0x44c66d: 7415 JZ 0x0044c684
    if(integer::condition("JZ",flags)) goto L0044c684;
  }
  L0044c66f: { // 0x44c66f: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  L0044c672: { // 0x44c672: 7410 JZ 0x0044c684
    if(integer::condition("JZ",flags)) goto L0044c684;
  }
  L0044c674: { // 0x44c674: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0044c678: { // 0x44c678: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044c679: { // 0x44c679: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044c67a: { // 0x44c67a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044c67b: { // 0x44c67b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044c67c: { // 0x44c67c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0044c67d: { // 0x44c67d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044c67f: { // 0x44c67f: e8cc000000 CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4507268u); flags=s.arithmetic_flags;
  }
  L0044c684: { // 0x44c684: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044c685: { // 0x44c685: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044c686: { // 0x44c686: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044c687: { // 0x44c687: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_00025640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00425640: { // 0x425640: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00425641: { // 0x425641: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00425642: { // 0x425642: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00425644: { // 0x425644: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00425646: { // 0x425646: 742e JZ 0x00425676
    if(integer::condition("JZ",flags)) goto L00425676;
  }
  L00425648: { // 0x425648: a120e58400 MOV EAX,[0x0084e520]
    s.ax = m.r32((0x0084e520u));
  }
  L0042564d: { // 0x42564d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0042564f: { // 0x42564f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00425651: { // 0x425651: 7e23 JLE 0x00425676
    if(integer::condition("JLE",flags)) goto L00425676;
  }
  L00425653: { // 0x425653: a114e58400 MOV EAX,[0x0084e514]
    s.ax = m.r32((0x0084e514u));
  }
  L00425658: { // 0x425658: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00425659: { // 0x425659: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0042565c: { // 0x42565c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  L0042565f: { // 0x42565f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00425660: { // 0x425660: e8fb813400 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,4347493u); flags=s.arithmetic_flags;
  }
  L00425665: { // 0x425665: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00425668: { // 0x425668: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042566a: { // 0x42566a: 7410 JZ 0x0042567c
    if(integer::condition("JZ",flags)) goto L0042567c;
  }
  L0042566c: { // 0x42566c: a120e58400 MOV EAX,[0x0084e520]
    s.ax = m.r32((0x0084e520u));
  }
  L00425671: { // 0x425671: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00425672: { // 0x425672: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00425674: { // 0x425674: 7cdd JL 0x00425653
    if(integer::condition("JL",flags)) goto L00425653;
  }
  L00425676: { // 0x425676: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00425677: { // 0x425677: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0042567a: { // 0x42567a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042567b: { // 0x42567b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0042567c: { // 0x42567c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042567e: { // 0x42567e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042567f: { // 0x42567f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00425680: { // 0x425680: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4534432u:f_000530a0(m,s,child,{});break;
case 6081488u:f_001ccbd0(m,s,child,{});break;
case 4306432u:f_0001b600(m,s,child,{});break;
case 4507472u:f_0004c750(m,s,child,{});break;
case 4507152u:f_0004c610(m,s,child,{});break;
case 4347456u:f_00025640(m,s,child,{});break;
default:throw std::domain_error("recovery1545 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1545 no reviewed tail"); } }

std::uint32_t fun_004530a0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004530a0: { // 0x4530a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004530a1: { // 0x4530a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004530a2: { // 0x4530a2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004530a4: { // 0x4530a4: 8b8698040000 MOV EAX,dword ptr [ESI + 0x498]
    s.ax = m.r32((s.si+0x00000498u));
  }
  L004530aa: { // 0x4530aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004530ac: { // 0x4530ac: 7471 JZ 0x0045311f
    if(integer::condition("JZ",flags)) goto L0045311f;
  }
  L004530ae: { // 0x4530ae: e81d9b1700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534451u); flags=s.arithmetic_flags;
  }
  L004530b3: { // 0x4530b3: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004530b8: { // 0x4530b8: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004530be: { // 0x4530be: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004530c0: { // 0x4530c0: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004530c3: { // 0x4530c3: 7407 JZ 0x004530cc
    if(integer::condition("JZ",flags)) goto L004530cc;
  }
  L004530c5: { // 0x4530c5: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L004530ca: { // 0x4530ca: eb02 JMP 0x004530ce
    goto L004530ce;
  }
  L004530cc: { // 0x4530cc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004530ce: { // 0x4530ce: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004530d4: { // 0x4530d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004530d6: { // 0x4530d6: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L004530d9: { // 0x4530d9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004530db: { // 0x4530db: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L004530df: { // 0x4530df: 740d JZ 0x004530ee
    if(integer::condition("JZ",flags)) goto L004530ee;
  }
  L004530e1: { // 0x4530e1: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004530e7: { // 0x4530e7: 0568110000 ADD EAX,0x1168
    s.ax = integer::add(s.ax,0x00001168u,32,flags);
  }
  L004530ec: { // 0x4530ec: eb16 JMP 0x00453104
    goto L00453104;
  }
  L004530ee: { // 0x4530ee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004530f0: { // 0x4530f0: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004530f6: { // 0x4530f6: 7407 JZ 0x004530ff
    if(integer::condition("JZ",flags)) goto L004530ff;
  }
  L004530f8: { // 0x4530f8: 0578110000 ADD EAX,0x1178
    s.ax = integer::add(s.ax,0x00001178u,32,flags);
  }
  L004530fd: { // 0x4530fd: eb05 JMP 0x00453104
    goto L00453104;
  }
  L004530ff: { // 0x4530ff: 0558110000 ADD EAX,0x1158
    s.ax = integer::add(s.ax,0x00001158u,32,flags);
  }
  L00453104: { // 0x453104: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453106: { // 0x453106: 7417 JZ 0x0045311f
    if(integer::condition("JZ",flags)) goto L0045311f;
  }
  L00453108: { // 0x453108: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L0045310b: { // 0x45310b: 7412 JZ 0x0045311f
    if(integer::condition("JZ",flags)) goto L0045311f;
  }
  L0045310d: { // 0x45310d: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00453111: { // 0x453111: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00453113: { // 0x453113: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00453114: { // 0x453114: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453115: { // 0x453115: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  L00453117: { // 0x453117: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00453118: { // 0x453118: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0045311a: { // 0x45311a: e83196ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534559u); flags=s.arithmetic_flags;
  }
  L0045311f: { // 0x45311f: 8b8660040000 MOV EAX,dword ptr [ESI + 0x460]
    s.ax = m.r32((s.si+0x00000460u));
  }
  L00453125: { // 0x453125: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453127: { // 0x453127: 7473 JZ 0x0045319c
    if(integer::condition("JZ",flags)) goto L0045319c;
  }
  L00453129: { // 0x453129: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0045312b: { // 0x45312b: e8a09a1700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534576u); flags=s.arithmetic_flags;
  }
  L00453130: { // 0x453130: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00453135: { // 0x453135: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0045313b: { // 0x45313b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0045313d: { // 0x45313d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00453140: { // 0x453140: 7407 JZ 0x00453149
    if(integer::condition("JZ",flags)) goto L00453149;
  }
  L00453142: { // 0x453142: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00453147: { // 0x453147: eb02 JMP 0x0045314b
    goto L0045314b;
  }
  L00453149: { // 0x453149: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0045314b: { // 0x45314b: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00453151: { // 0x453151: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453153: { // 0x453153: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L00453156: { // 0x453156: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00453158: { // 0x453158: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L0045315c: { // 0x45315c: 740d JZ 0x0045316b
    if(integer::condition("JZ",flags)) goto L0045316b;
  }
  L0045315e: { // 0x45315e: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00453164: { // 0x453164: 05b00d0000 ADD EAX,0xdb0
    s.ax = integer::add(s.ax,0x00000db0u,32,flags);
  }
  L00453169: { // 0x453169: eb16 JMP 0x00453181
    goto L00453181;
  }
  L0045316b: { // 0x45316b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0045316d: { // 0x45316d: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00453173: { // 0x453173: 7407 JZ 0x0045317c
    if(integer::condition("JZ",flags)) goto L0045317c;
  }
  L00453175: { // 0x453175: 05c00d0000 ADD EAX,0xdc0
    s.ax = integer::add(s.ax,0x00000dc0u,32,flags);
  }
  L0045317a: { // 0x45317a: eb05 JMP 0x00453181
    goto L00453181;
  }
  L0045317c: { // 0x45317c: 05a00d0000 ADD EAX,0xda0
    s.ax = integer::add(s.ax,0x00000da0u,32,flags);
  }
  L00453181: { // 0x453181: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453183: { // 0x453183: 7417 JZ 0x0045319c
    if(integer::condition("JZ",flags)) goto L0045319c;
  }
  L00453185: { // 0x453185: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L00453188: { // 0x453188: 7412 JZ 0x0045319c
    if(integer::condition("JZ",flags)) goto L0045319c;
  }
  L0045318a: { // 0x45318a: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0045318e: { // 0x45318e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00453190: { // 0x453190: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00453191: { // 0x453191: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453192: { // 0x453192: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L00453194: { // 0x453194: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00453195: { // 0x453195: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453197: { // 0x453197: e8b495ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534684u); flags=s.arithmetic_flags;
  }
  L0045319c: { // 0x45319c: 8b8664040000 MOV EAX,dword ptr [ESI + 0x464]
    s.ax = m.r32((s.si+0x00000464u));
  }
  L004531a2: { // 0x4531a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004531a4: { // 0x4531a4: 7473 JZ 0x00453219
    if(integer::condition("JZ",flags)) goto L00453219;
  }
  L004531a6: { // 0x4531a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004531a8: { // 0x4531a8: e8239a1700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534701u); flags=s.arithmetic_flags;
  }
  L004531ad: { // 0x4531ad: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004531b2: { // 0x4531b2: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004531b8: { // 0x4531b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004531ba: { // 0x4531ba: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004531bd: { // 0x4531bd: 7407 JZ 0x004531c6
    if(integer::condition("JZ",flags)) goto L004531c6;
  }
  L004531bf: { // 0x4531bf: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L004531c4: { // 0x4531c4: eb02 JMP 0x004531c8
    goto L004531c8;
  }
  L004531c6: { // 0x4531c6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004531c8: { // 0x4531c8: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004531ce: { // 0x4531ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004531d0: { // 0x4531d0: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L004531d3: { // 0x4531d3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004531d5: { // 0x4531d5: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L004531d9: { // 0x4531d9: 740d JZ 0x004531e8
    if(integer::condition("JZ",flags)) goto L004531e8;
  }
  L004531db: { // 0x4531db: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004531e1: { // 0x4531e1: 05f40d0000 ADD EAX,0xdf4
    s.ax = integer::add(s.ax,0x00000df4u,32,flags);
  }
  L004531e6: { // 0x4531e6: eb16 JMP 0x004531fe
    goto L004531fe;
  }
  L004531e8: { // 0x4531e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004531ea: { // 0x4531ea: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004531f0: { // 0x4531f0: 7407 JZ 0x004531f9
    if(integer::condition("JZ",flags)) goto L004531f9;
  }
  L004531f2: { // 0x4531f2: 05040e0000 ADD EAX,0xe04
    s.ax = integer::add(s.ax,0x00000e04u,32,flags);
  }
  L004531f7: { // 0x4531f7: eb05 JMP 0x004531fe
    goto L004531fe;
  }
  L004531f9: { // 0x4531f9: 05e40d0000 ADD EAX,0xde4
    s.ax = integer::add(s.ax,0x00000de4u,32,flags);
  }
  L004531fe: { // 0x4531fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453200: { // 0x453200: 7417 JZ 0x00453219
    if(integer::condition("JZ",flags)) goto L00453219;
  }
  L00453202: { // 0x453202: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L00453205: { // 0x453205: 7412 JZ 0x00453219
    if(integer::condition("JZ",flags)) goto L00453219;
  }
  L00453207: { // 0x453207: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0045320b: { // 0x45320b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0045320d: { // 0x45320d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045320e: { // 0x45320e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045320f: { // 0x45320f: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00453211: { // 0x453211: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00453212: { // 0x453212: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453214: { // 0x453214: e83795ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534809u); flags=s.arithmetic_flags;
  }
  L00453219: { // 0x453219: 8b8668040000 MOV EAX,dword ptr [ESI + 0x468]
    s.ax = m.r32((s.si+0x00000468u));
  }
  L0045321f: { // 0x45321f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00453221: { // 0x453221: 7473 JZ 0x00453296
    if(integer::condition("JZ",flags)) goto L00453296;
  }
  L00453223: { // 0x453223: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453225: { // 0x453225: e8a6991700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534826u); flags=s.arithmetic_flags;
  }
  L0045322a: { // 0x45322a: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0045322f: { // 0x45322f: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00453235: { // 0x453235: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00453237: { // 0x453237: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0045323a: { // 0x45323a: 7407 JZ 0x00453243
    if(integer::condition("JZ",flags)) goto L00453243;
  }
  L0045323c: { // 0x45323c: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00453241: { // 0x453241: eb02 JMP 0x00453245
    goto L00453245;
  }
  L00453243: { // 0x453243: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00453245: { // 0x453245: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L0045324b: { // 0x45324b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045324d: { // 0x45324d: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L00453250: { // 0x453250: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00453252: { // 0x453252: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L00453256: { // 0x453256: 740d JZ 0x00453265
    if(integer::condition("JZ",flags)) goto L00453265;
  }
  L00453258: { // 0x453258: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0045325e: { // 0x45325e: 05380e0000 ADD EAX,0xe38
    s.ax = integer::add(s.ax,0x00000e38u,32,flags);
  }
  L00453263: { // 0x453263: eb16 JMP 0x0045327b
    goto L0045327b;
  }
  L00453265: { // 0x453265: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00453267: { // 0x453267: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0045326d: { // 0x45326d: 7407 JZ 0x00453276
    if(integer::condition("JZ",flags)) goto L00453276;
  }
  L0045326f: { // 0x45326f: 05480e0000 ADD EAX,0xe48
    s.ax = integer::add(s.ax,0x00000e48u,32,flags);
  }
  L00453274: { // 0x453274: eb05 JMP 0x0045327b
    goto L0045327b;
  }
  L00453276: { // 0x453276: 05280e0000 ADD EAX,0xe28
    s.ax = integer::add(s.ax,0x00000e28u,32,flags);
  }
  L0045327b: { // 0x45327b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045327d: { // 0x45327d: 7417 JZ 0x00453296
    if(integer::condition("JZ",flags)) goto L00453296;
  }
  L0045327f: { // 0x45327f: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L00453282: { // 0x453282: 7412 JZ 0x00453296
    if(integer::condition("JZ",flags)) goto L00453296;
  }
  L00453284: { // 0x453284: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00453288: { // 0x453288: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0045328a: { // 0x45328a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045328b: { // 0x45328b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045328c: { // 0x45328c: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0045328e: { // 0x45328e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045328f: { // 0x45328f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00453291: { // 0x453291: e8ba94ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4534934u); flags=s.arithmetic_flags;
  }
  L00453296: { // 0x453296: 8b866c040000 MOV EAX,dword ptr [ESI + 0x46c]
    s.ax = m.r32((s.si+0x0000046cu));
  }
  L0045329c: { // 0x45329c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045329e: { // 0x45329e: 7473 JZ 0x00453313
    if(integer::condition("JZ",flags)) goto L00453313;
  }
  L004532a0: { // 0x4532a0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004532a2: { // 0x4532a2: e829991700 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4534951u); flags=s.arithmetic_flags;
  }
  L004532a7: { // 0x4532a7: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004532ac: { // 0x4532ac: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004532b2: { // 0x4532b2: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004532b4: { // 0x4532b4: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004532b7: { // 0x4532b7: 7407 JZ 0x004532c0
    if(integer::condition("JZ",flags)) goto L004532c0;
  }
  L004532b9: { // 0x4532b9: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L004532be: { // 0x4532be: eb02 JMP 0x004532c2
    goto L004532c2;
  }
  L004532c0: { // 0x4532c0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004532c2: { // 0x4532c2: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004532c8: { // 0x4532c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004532ca: { // 0x4532ca: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L004532cd: { // 0x4532cd: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004532cf: { // 0x4532cf: 88442404 MOV byte ptr [ESP + 0x4],AL
    m.w8((f.sp+0x00000004u), (s.ax & 0xffu));
  }
  L004532d3: { // 0x4532d3: 740d JZ 0x004532e2
    if(integer::condition("JZ",flags)) goto L004532e2;
  }
  L004532d5: { // 0x4532d5: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004532db: { // 0x4532db: 057c0e0000 ADD EAX,0xe7c
    s.ax = integer::add(s.ax,0x00000e7cu,32,flags);
  }
  L004532e0: { // 0x4532e0: eb16 JMP 0x004532f8
    goto L004532f8;
  }
  L004532e2: { // 0x4532e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004532e4: { // 0x4532e4: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004532ea: { // 0x4532ea: 7407 JZ 0x004532f3
    if(integer::condition("JZ",flags)) goto L004532f3;
  }
  L004532ec: { // 0x4532ec: 058c0e0000 ADD EAX,0xe8c
    s.ax = integer::add(s.ax,0x00000e8cu,32,flags);
  }
  L004532f1: { // 0x4532f1: eb05 JMP 0x004532f8
    goto L004532f8;
  }
  L004532f3: { // 0x4532f3: 056c0e0000 ADD EAX,0xe6c
    s.ax = integer::add(s.ax,0x00000e6cu,32,flags);
  }
  L004532f8: { // 0x4532f8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004532fa: { // 0x4532fa: 7417 JZ 0x00453313
    if(integer::condition("JZ",flags)) goto L00453313;
  }
  L004532fc: { // 0x4532fc: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  L004532ff: { // 0x4532ff: 7412 JZ 0x00453313
    if(integer::condition("JZ",flags)) goto L00453313;
  }
  L00453301: { // 0x453301: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00453305: { // 0x453305: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00453307: { // 0x453307: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00453308: { // 0x453308: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453309: { // 0x453309: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  L0045330b: { // 0x45330b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045330c: { // 0x45330c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0045330e: { // 0x45330e: e83d94ffff CALL 0x0044c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c750u,4535059u); flags=s.arithmetic_flags;
  }
  L00453313: { // 0x453313: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00453314: { // 0x453314: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00453315: { // 0x453315: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
