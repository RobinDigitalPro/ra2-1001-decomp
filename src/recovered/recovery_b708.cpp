#include "recovered/recovery_b708_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b708 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_002c2be0(Memory&,State&,Frame&,const Operations&);
void f_002cdb10(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_002cc380(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_0001b380(Memory&,State&,Frame&,const Operations&);
void f_002c9630(Memory&,State&,Frame&,const Operations&);
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("708 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002c2be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c2be0: { // 0x6c2be0: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006c2be2: { // 0x6c2be2: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7089128u); flags=s.arithmetic_flags;
  }
  L006c2be8: { // 0x6c2be8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2bea: { // 0x6c2bea: 740b JZ 0x6c2bf7
    if(integer::condition("JZ",flags)) goto L006c2bf7;
  }
  L006c2bec: { // 0x6c2bec: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L006c2bef: { // 0x6c2bef: 7406 JZ 0x6c2bf7
    if(integer::condition("JZ",flags)) goto L006c2bf7;
  }
  L006c2bf1: { // 0x6c2bf1: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006c2bf6: { // 0x6c2bf6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c2bf7: { // 0x6c2bf7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c2bf9: { // 0x6c2bf9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdb10: { // 0x6cdb10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdb11: { // 0x6cdb11: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdb13: { // 0x6cdb13: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdb15: { // 0x6cdb15: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133979u); flags=s.arithmetic_flags;
  }
  L006cdb1b: { // 0x6cdb1b: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdb1d: { // 0x6cdb1d: e8ce700000 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7133986u); flags=s.arithmetic_flags;
  }
  L006cdb22: { // 0x6cdb22: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdb24: { // 0x6cdb24: 7413 JZ 0x6cdb39
    if(integer::condition("JZ",flags)) goto L006cdb39;
  }
  L006cdb26: { // 0x6cdb26: 8b860c010000 MOV EAX, dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006cdb2c: { // 0x6cdb2c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb2e: { // 0x6cdb2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb2f: { // 0x6cdb2f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb31: { // 0x6cdb31: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134007u); flags=s.arithmetic_flags;
  }
  L006cdb37: { // 0x6cdb37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb38: { // 0x6cdb38: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006cdb39: { // 0x6cdb39: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb3b: { // 0x6cdb3b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdb3d: { // 0x6cdb3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb3e: { // 0x6cdb3e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb40: { // 0x6cdb40: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134022u); flags=s.arithmetic_flags;
  }
  L006cdb46: { // 0x6cdb46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb47: { // 0x6cdb47: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0004d670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d670: { // 0x44d670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d671: { // 0x44d671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d672: { // 0x44d672: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d673: { // 0x44d673: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044d677: { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d678: { // 0x44d678: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044d67a: { // 0x44d67a: 8a87c6050000 MOV AL, byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0044d680: { // 0x44d680: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d682: { // 0x44d682: 742c JZ 0x44d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  L0044d684: { // 0x44d684: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d686: { // 0x44d686: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d688: { // 0x44d688: 7e26 JLE 0x44d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  L0044d68a: { // 0x44d68a: 8db7c0040000 LEA ESI, [EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0044d692: { // 0x44d692: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d694: { // 0x44d694: 740b JZ 0x44d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  L0044d696: { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d697: { // 0x44d697: e894742800 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4511388u); flags=s.arithmetic_flags;
  }
  L0044d69c: { // 0x44d69c: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L0044d69f: { // 0x44d69f: 7517 JNZ 0x44d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX, byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0044d6a8: { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d6a9: { // 0x44d6a9: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L0044d6ac: { // 0x44d6ac: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d6ae: { // 0x44d6ae: 7ce0 JL 0x44d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d6b1: { // 0x44d6b1: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d6b3: { // 0x44d6b3: e8f8032800 CALL 0x6cdab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cdab0u,4511416u); flags=s.arithmetic_flags;
  }
  L0044d6b8: { // 0x44d6b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d6b9: { // 0x44d6b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d6ba: { // 0x44d6ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d6bb: { // 0x44d6bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d6bc: { // 0x44d6bc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX, [ECX + EDX*4 + 0x74c]
    s.ax = (s.cx+(s.dx * 4u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4bf0: { // 0x6d4bf0: 8b9104070000 MOV EDX, dword ptr [ECX + 0x704]
    s.dx = m.r32((s.cx+0x00000704u));
  }
  L006d4bf6: { // 0x6d4bf6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d4bf8: { // 0x6d4bf8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d4bfa: { // 0x6d4bfa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006d4bfd: { // 0x6d4bfd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cc380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc380: { // 0x6cc380: 8b8108020000 MOV EAX, dword ptr [ECX + 0x208]
    s.ax = m.r32((s.cx+0x00000208u));
  }
  L006cc386: { // 0x6cc386: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cc388: { // 0x6cc388: 740a JZ 0x6cc394
    if(integer::condition("JZ",flags)) goto L006cc394;
  }
  L006cc38a: { // 0x6cc38a: 8b4828 MOV ECX, dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L006cc38d: { // 0x6cc38d: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006cc38f: { // 0x6cc38f: 7403 JZ 0x6cc394
    if(integer::condition("JZ",flags)) goto L006cc394;
  }
  L006cc391: { // 0x6cc391: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L006cc393: { // 0x6cc393: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006cc394: { // 0x6cc394: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cc396: { // 0x6cc396: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b380: { // 0x41b380: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0041b382: { // 0x41b382: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002c9630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c9630: { // 0x6c9630: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006c9635: { // 0x6c9635: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c9636: { // 0x6c9636: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c9637: { // 0x6c9637: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c9639: { // 0x6c9639: 8b0dd47caa00 MOV ECX,dword ptr [0x00aa7cd4]
    s.cx = m.r32((0x00aa7cd4u));
  }
  L006c963f: { // 0x6c963f: 2b86f4030000 SUB EAX,dword ptr [ESI + 0x3f4]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x000003f4u)),32,flags);
  }
  L006c9645: { // 0x6c9645: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006c9647: { // 0x6c9647: 0f8298000000 JC 0x006c96e5
    if(integer::condition("JC",flags)) goto L006c96e5;
  }
  L006c964d: { // 0x6c964d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c964f: { // 0x6c964f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9651: { // 0x6c9651: ff92c4010000 CALL dword ptr [EDX + 0x1c4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001c4u)),7116375u); flags=s.arithmetic_flags;
  }
  L006c9657: { // 0x6c9657: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c9659: { // 0x6c9659: 0f8586000000 JNZ 0x006c96e5
    if(integer::condition("JNZ",flags)) goto L006c96e5;
  }
  L006c965f: { // 0x6c965f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c9661: { // 0x6c9661: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9663: { // 0x6c9663: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7116393u); flags=s.arithmetic_flags;
  }
  L006c9669: { // 0x6c9669: 8a88490b0000 MOV CL,byte ptr [EAX + 0xb49]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b49u)));
  }
  L006c966f: { // 0x6c966f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9671: { // 0x6c9671: 7472 JZ 0x006c96e5
    if(integer::condition("JZ",flags)) goto L006c96e5;
  }
  L006c9673: { // 0x6c9673: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c9675: { // 0x6c9675: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9677: { // 0x6c9677: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7116410u); flags=s.arithmetic_flags;
  }
  L006c967a: { // 0x6c967a: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006c967d: { // 0x6c967d: 751b JNZ 0x006c969a
    if(integer::condition("JNZ",flags)) goto L006c969a;
  }
  L006c967f: { // 0x6c967f: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L006c9685: { // 0x6c9685: 8a881e120000 MOV CL,byte ptr [EAX + 0x121e]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000121eu)));
  }
  L006c968b: { // 0x6c968b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c968d: { // 0x6c968d: 740b JZ 0x006c969a
    if(integer::condition("JZ",flags)) goto L006c969a;
  }
  L006c968f: { // 0x6c968f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9691: { // 0x6c9691: e8ca98d8ff CALL 0x00452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7116438u); flags=s.arithmetic_flags;
  }
  L006c9696: { // 0x6c9696: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9698: { // 0x6c9698: 744b JZ 0x006c96e5
    if(integer::condition("JZ",flags)) goto L006c96e5;
  }
  L006c969a: { // 0x6c969a: 8b8630020000 MOV EAX,dword ptr [ESI + 0x230]
    s.ax = m.r32((s.si+0x00000230u));
  }
  L006c96a0: { // 0x6c96a0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c96a2: { // 0x6c96a2: 740b JZ 0x006c96af
    if(integer::condition("JZ",flags)) goto L006c96af;
  }
  L006c96a4: { // 0x6c96a4: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L006c96a7: { // 0x6c96a7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c96a9: { // 0x6c96a9: 7404 JZ 0x006c96af
    if(integer::condition("JZ",flags)) goto L006c96af;
  }
  L006c96ab: { // 0x6c96ab: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006c96ad: { // 0x6c96ad: eb02 JMP 0x006c96b1
    goto L006c96b1;
  }
  L006c96af: { // 0x6c96af: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006c96b1: { // 0x6c96b1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c96b3: { // 0x6c96b3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c96b5: { // 0x6c96b5: ff9204030000 CALL dword ptr [EDX + 0x304]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000304u)),7116475u); flags=s.arithmetic_flags;
  }
  L006c96bb: { // 0x6c96bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c96bd: { // 0x6c96bd: 740f JZ 0x006c96ce
    if(integer::condition("JZ",flags)) goto L006c96ce;
  }
  L006c96bf: { // 0x6c96bf: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c96c5: { // 0x6c96c5: e826b1e2ff CALL 0x004f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,7116490u); flags=s.arithmetic_flags;
  }
  L006c96ca: { // 0x6c96ca: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c96cc: { // 0x6c96cc: 7517 JNZ 0x006c96e5
    if(integer::condition("JNZ",flags)) goto L006c96e5;
  }
  L006c96ce: { // 0x6c96ce: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c96d0: { // 0x6c96d0: 7513 JNZ 0x006c96e5
    if(integer::condition("JNZ",flags)) goto L006c96e5;
  }
  L006c96d2: { // 0x6c96d2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c96d4: { // 0x6c96d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c96d6: { // 0x6c96d6: ff908c020000 CALL dword ptr [EAX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000028cu)),7116508u); flags=s.arithmetic_flags;
  }
  L006c96dc: { // 0x6c96dc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c96de: { // 0x6c96de: 7405 JZ 0x006c96e5
    if(integer::condition("JZ",flags)) goto L006c96e5;
  }
  L006c96e0: { // 0x6c96e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c96e1: { // 0x6c96e1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006c96e3: { // 0x6c96e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c96e4: { // 0x6c96e4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c96e5: { // 0x6c96e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c96e6: { // 0x6c96e6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c96e8: { // 0x6c96e8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c96e9: { // 0x6c96e9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00043e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00443e10: { // 0x443e10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00443e11: { // 0x443e11: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00443e12: { // 0x443e12: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00443e14: { // 0x443e14: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00443e16: { // 0x443e16: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e1c: { // 0x443e1c: e89f470100 CALL 0x4585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4472353u); flags=s.arithmetic_flags;
  }
  L00443e21: { // 0x443e21: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e27: { // 0x443e27: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00443e29: { // 0x443e29: c1e607 SHL ESI, 7
    s.si = integer::shift(s.si,7u,32,flags,integer::Shift::left);
  }
  L00443e2c: { // 0x443e2c: 81ee80000000 SUB ESI, 0x80
    s.si = integer::sub(s.si,0x00000080u,32,flags);
  }
  L00443e32: { // 0x443e32: e879470100 CALL 0x4585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4472375u); flags=s.arithmetic_flags;
  }
  L00443e37: { // 0x443e37: 81c788000000 ADD EDI, 0x88
    s.di = integer::add(s.di,0x00000088u,32,flags);
  }
  L00443e3d: { // 0x443e3d: c1e007 SHL EAX, 7
    s.ax = integer::shift(s.ax,7u,32,flags,integer::Shift::left);
  }
  L00443e40: { // 0x443e40: 8b0f MOV ECX, dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00443e42: { // 0x443e42: 2d80000000 SUB EAX, 0x80
    s.ax = integer::sub(s.ax,0x00000080u,32,flags);
  }
  L00443e47: { // 0x443e47: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00443e49: { // 0x443e49: 8b44240c MOV EAX, dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00443e4d: { // 0x443e4d: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L00443e50: { // 0x443e50: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00443e52: { // 0x443e52: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00443e54: { // 0x443e54: 8b7f08 MOV EDI, dword ptr [EDI + 8]
    s.di = m.r32((s.di+8u));
  }
  L00443e57: { // 0x443e57: 890e MOV dword ptr [ESI], ECX
    m.w32((s.si), s.cx);
  }
  L00443e59: { // 0x443e59: 895604 MOV dword ptr [ESI + 4], EDX
    m.w32((s.si+4u), s.dx);
  }
  L00443e5c: { // 0x443e5c: 897e08 MOV dword ptr [ESI + 8], EDI
    m.w32((s.si+8u), s.di);
  }
  L00443e5f: { // 0x443e5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00443e60: { // 0x443e60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00443e61: { // 0x443e61: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000585b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585b0: { // 0x4585b0: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585b6: { // 0x4585b6: 8b048508ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac08]
    s.ax = m.r32(((s.ax * 4u)+0x007bac08u));
  }
  L004585bd: { // 0x4585bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000585c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585c0: { // 0x4585c0: 8a442404 MOV AL, byte ptr [ESP + 4]
    s.ax = with_al(s.ax, m.r8((f.sp+4u)));
  }
  L004585c4: { // 0x4585c4: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585c6: { // 0x4585c6: 7421 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585c8: { // 0x4585c8: 8a8114120000 MOV AL, byte ptr [ECX + 0x1214]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001214u)));
  }
  L004585ce: { // 0x4585ce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585d0: { // 0x4585d0: 7417 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585d2: { // 0x4585d2: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585d8: { // 0x4585d8: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004585dd: { // 0x4585dd: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585e4: { // 0x4585e4: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585e6: { // 0x4585e6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004585e9: { // 0x4585e9: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585ef: { // 0x4585ef: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004585f1: { // 0x4585f1: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585f8: { // 0x4585f8: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585fa: { // 0x4585fa: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD qword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x4ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x4ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL qword ptr [0x788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX, 0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX, 0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX, 0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x4ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX, 0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX, 1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),1u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX, 0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX, 0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX, dword ptr [ECX*4 + 0x80013c]
    s.cx = m.r32(((s.cx * 4u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX, 0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7089120u:f_002c2be0(m,s,child,{});break;
case 7133968u:f_002cdb10(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 7127936u:f_002cc380(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4305792u:f_0001b380(m,s,child,{});break;
case 7116336u:f_002c9630(m,s,child,{});break;
case 4472336u:f_00043e10(m,s,child,{});break;
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery708 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006c96f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c96f0: { // 0x6c96f0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c96f1: { // 0x6c96f1: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006c96f6: { // 0x6c96f6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c96f7: { // 0x6c96f7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c96f9: { // 0x6c96f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c96fa: { // 0x6c96fa: 8b0dd47caa00 MOV ECX,dword ptr [0x00aa7cd4]
    s.cx = m.r32((0x00aa7cd4u));
  }
  L006c9700: { // 0x6c9700: 2b86f4030000 SUB EAX,dword ptr [ESI + 0x3f4]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x000003f4u)),32,flags);
  }
  L006c9706: { // 0x6c9706: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006c9708: { // 0x6c9708: 7306 JNC 0x006c9710
    if(integer::condition("JNC",flags)) goto L006c9710;
  }
  L006c970a: { // 0x6c970a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c970b: { // 0x6c970b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c970d: { // 0x6c970d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c970e: { // 0x6c970e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006c970f: { // 0x6c970f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c9710: { // 0x6c9710: 8b8628020000 MOV EAX,dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  L006c9716: { // 0x6c9716: bf02000000 MOV EDI,0x2
    s.di = 0x00000002u;
  }
  L006c971b: { // 0x6c971b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c971d: { // 0x6c971d: 754f JNZ 0x006c976e
    if(integer::condition("JNZ",flags)) goto L006c976e;
  }
  L006c971f: { // 0x6c971f: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c9725: { // 0x6c9725: e8c6b0e2ff CALL 0x004f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,7116586u); flags=s.arithmetic_flags;
  }
  L006c972a: { // 0x6c972a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c972c: { // 0x6c972c: 7540 JNZ 0x006c976e
    if(integer::condition("JNZ",flags)) goto L006c976e;
  }
  L006c972e: { // 0x6c972e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c9730: { // 0x6c9730: 743c JZ 0x006c976e
    if(integer::condition("JZ",flags)) goto L006c976e;
  }
  L006c9732: { // 0x6c9732: 8a4e14 MOV CL,byte ptr [ESI + 0x14]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000014u)));
  }
  L006c9735: { // 0x6c9735: c0e902 SHR CL,0x2
    s.cx = with_al(s.cx, integer::shift((s.cx & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L006c9738: { // 0x6c9738: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L006c973b: { // 0x6c973b: 884c240b MOV byte ptr [ESP + 0xb],CL
    m.w8((f.sp+0x0000000bu), (s.cx & 0xffu));
  }
  L006c973f: { // 0x6c973f: 742d JZ 0x006c976e
    if(integer::condition("JZ",flags)) goto L006c976e;
  }
  L006c9741: { // 0x6c9741: 8b86c4040000 MOV EAX,dword ptr [ESI + 0x4c4]
    s.ax = m.r32((s.si+0x000004c4u));
  }
  L006c9747: { // 0x6c9747: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9749: { // 0x6c9749: 7423 JZ 0x006c976e
    if(integer::condition("JZ",flags)) goto L006c976e;
  }
  L006c974b: { // 0x6c974b: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L006c974e: { // 0x6c974e: 8a88af000000 MOV CL,byte ptr [EAX + 0xaf]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000000afu)));
  }
  L006c9754: { // 0x6c9754: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9756: { // 0x6c9756: 7516 JNZ 0x006c976e
    if(integer::condition("JNZ",flags)) goto L006c976e;
  }
  L006c9758: { // 0x6c9758: 8a88ad000000 MOV CL,byte ptr [EAX + 0xad]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000000adu)));
  }
  L006c975e: { // 0x6c975e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9760: { // 0x6c9760: 740c JZ 0x006c976e
    if(integer::condition("JZ",flags)) goto L006c976e;
  }
  L006c9762: { // 0x6c9762: 39be98000000 CMP dword ptr [ESI + 0x98],EDI
    (void)integer::sub(m.r32((s.si+0x00000098u)),s.di,32,flags);
  }
  L006c9768: { // 0x6c9768: 0f84e6000000 JZ 0x006c9854
    if(integer::condition("JZ",flags)) goto L006c9854;
  }
  L006c976e: { // 0x6c976e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9770: { // 0x6c9770: e8bbfeffff CALL 0x006c9630
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c9630u,7116661u); flags=s.arithmetic_flags;
  }
  L006c9775: { // 0x6c9775: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c9777: { // 0x6c9777: 7504 JNZ 0x006c977d
    if(integer::condition("JNZ",flags)) goto L006c977d;
  }
  L006c9779: { // 0x6c9779: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c977a: { // 0x6c977a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c977b: { // 0x6c977b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006c977c: { // 0x6c977c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c977d: { // 0x6c977d: 39be98000000 CMP dword ptr [ESI + 0x98],EDI
    (void)integer::sub(m.r32((s.si+0x00000098u)),s.di,32,flags);
  }
  L006c9783: { // 0x6c9783: 7555 JNZ 0x006c97da
    if(integer::condition("JNZ",flags)) goto L006c97da;
  }
  L006c9785: { // 0x6c9785: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c9787: { // 0x6c9787: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9789: { // 0x6c9789: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7116687u); flags=s.arithmetic_flags;
  }
  L006c978f: { // 0x6c978f: 8a881a0b0000 MOV CL,byte ptr [EAX + 0xb1a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b1au)));
  }
  L006c9795: { // 0x6c9795: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9797: { // 0x6c9797: 7441 JZ 0x006c97da
    if(integer::condition("JZ",flags)) goto L006c97da;
  }
  L006c9799: { // 0x6c9799: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c979b: { // 0x6c979b: 740e JZ 0x006c97ab
    if(integer::condition("JZ",flags)) goto L006c97ab;
  }
  L006c979d: { // 0x6c979d: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L006c97a0: { // 0x6c97a0: c0e802 SHR AL,0x2
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L006c97a3: { // 0x6c97a3: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L006c97a5: { // 0x6c97a5: 8844240b MOV byte ptr [ESP + 0xb],AL
    m.w8((f.sp+0x0000000bu), (s.ax & 0xffu));
  }
  L006c97a9: { // 0x6c97a9: 7506 JNZ 0x006c97b1
    if(integer::condition("JNZ",flags)) goto L006c97b1;
  }
  L006c97ab: { // 0x6c97ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c97ac: { // 0x6c97ac: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c97ae: { // 0x6c97ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c97af: { // 0x6c97af: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006c97b0: { // 0x6c97b0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c97b1: { // 0x6c97b1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c97b3: { // 0x6c97b3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c97b5: { // 0x6c97b5: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),7116731u); flags=s.arithmetic_flags;
  }
  L006c97bb: { // 0x6c97bb: 398694040000 CMP dword ptr [ESI + 0x494],EAX
    (void)integer::sub(m.r32((s.si+0x00000494u)),s.ax,32,flags);
  }
  L006c97c1: { // 0x6c97c1: 7517 JNZ 0x006c97da
    if(integer::condition("JNZ",flags)) goto L006c97da;
  }
  L006c97c3: { // 0x6c97c3: 8b8e08040000 MOV ECX,dword ptr [ESI + 0x408]
    s.cx = m.r32((s.si+0x00000408u));
  }
  L006c97c9: { // 0x6c97c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c97cb: { // 0x6c97cb: 0f8483000000 JZ 0x006c9854
    if(integer::condition("JZ",flags)) goto L006c9854;
  }
  L006c97d1: { // 0x6c97d1: e86a1ff4ff CALL 0x0060b740
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060b740u,7116758u); flags=s.arithmetic_flags;
  }
  L006c97d6: { // 0x6c97d6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c97d8: { // 0x6c97d8: 7e7a JLE 0x006c9854
    if(integer::condition("JLE",flags)) goto L006c9854;
  }
  L006c97da: { // 0x6c97da: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c97dc: { // 0x6c97dc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c97de: { // 0x6c97de: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7116772u); flags=s.arithmetic_flags;
  }
  L006c97e4: { // 0x6c97e4: 8a88ce050000 MOV CL,byte ptr [EAX + 0x5ce]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000005ceu)));
  }
  L006c97ea: { // 0x6c97ea: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c97ec: { // 0x6c97ec: 7566 JNZ 0x006c9854
    if(integer::condition("JNZ",flags)) goto L006c9854;
  }
  L006c97ee: { // 0x6c97ee: 83be9800000005 CMP dword ptr [ESI + 0x98],0x5
    (void)integer::sub(m.r32((s.si+0x00000098u)),0x00000005u,32,flags);
  }
  L006c97f5: { // 0x6c97f5: 7406 JZ 0x006c97fd
    if(integer::condition("JZ",flags)) goto L006c97fd;
  }
  L006c97f7: { // 0x6c97f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c97f8: { // 0x6c97f8: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c97fa: { // 0x6c97fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c97fb: { // 0x6c97fb: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006c97fc: { // 0x6c97fc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c97fd: { // 0x6c97fd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c97ff: { // 0x6c97ff: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c9800: { // 0x6c9800: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9802: { // 0x6c9802: ff9288030000 CALL dword ptr [EDX + 0x388]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000388u)),7116808u); flags=s.arithmetic_flags;
  }
  L006c9808: { // 0x6c9808: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006c980a: { // 0x6c980a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c980c: { // 0x6c980c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c980d: { // 0x6c980d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c980f: { // 0x6c980f: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7116821u); flags=s.arithmetic_flags;
  }
  L006c9815: { // 0x6c9815: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9817: { // 0x6c9817: 7414 JZ 0x006c982d
    if(integer::condition("JZ",flags)) goto L006c982d;
  }
  L006c9819: { // 0x6c9819: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006c981b: { // 0x6c981b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c981d: { // 0x6c981d: 740e JZ 0x006c982d
    if(integer::condition("JZ",flags)) goto L006c982d;
  }
  L006c981f: { // 0x6c981f: 8a8826010000 MOV CL,byte ptr [EAX + 0x126]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000126u)));
  }
  L006c9825: { // 0x6c9825: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9827: { // 0x6c9827: 7404 JZ 0x006c982d
    if(integer::condition("JZ",flags)) goto L006c982d;
  }
  L006c9829: { // 0x6c9829: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006c982b: { // 0x6c982b: eb02 JMP 0x006c982f
    goto L006c982f;
  }
  L006c982d: { // 0x6c982d: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006c982f: { // 0x6c982f: 8b8628020000 MOV EAX,dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  L006c9835: { // 0x6c9835: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c9837: { // 0x6c9837: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c9838: { // 0x6c9838: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c983a: { // 0x6c983a: ff92b8020000 CALL dword ptr [EDX + 0x2b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002b8u)),7116864u); flags=s.arithmetic_flags;
  }
  L006c9840: { // 0x6c9840: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L006c9842: { // 0x6c9842: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006c9845: { // 0x6c9845: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c9847: { // 0x6c9847: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c9848: { // 0x6c9848: 740a JZ 0x006c9854
    if(integer::condition("JZ",flags)) goto L006c9854;
  }
  L006c984a: { // 0x6c984a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c984c: { // 0x6c984c: 7406 JZ 0x006c9854
    if(integer::condition("JZ",flags)) goto L006c9854;
  }
  L006c984e: { // 0x6c984e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c984f: { // 0x6c984f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c9851: { // 0x6c9851: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c9852: { // 0x6c9852: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006c9853: { // 0x6c9853: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c9854: { // 0x6c9854: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c9855: { // 0x6c9855: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006c9857: { // 0x6c9857: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c9858: { // 0x6c9858: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006c9859: { // 0x6c9859: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006cd290(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cd290: { // 0x6cd290: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L006cd293: { // 0x6cd293: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006cd294: { // 0x6cd294: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006cd296: { // 0x6cd296: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L006cd29a: { // 0x6cd29a: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L006cd29d: { // 0x6cd29d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cd29e: { // 0x6cd29e: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cd2a0: { // 0x6cd2a0: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7131814u); flags=s.arithmetic_flags;
  }
  L006cd2a6: { // 0x6cd2a6: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006cd2a8: { // 0x6cd2a8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cd2aa: { // 0x6cd2aa: 7509 JNZ 0x006cd2b5
    if(integer::condition("JNZ",flags)) goto L006cd2b5;
  }
  L006cd2ac: { // 0x6cd2ac: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006cd2ae: { // 0x6cd2ae: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006cd2af: { // 0x6cd2af: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006cd2b2: { // 0x6cd2b2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cd2b5: { // 0x6cd2b5: 8a800a010000 MOV AL,byte ptr [EAX + 0x10a]
    s.ax = with_al(s.ax, m.r8((s.ax+0x0000010au)));
  }
  L006cd2bb: { // 0x6cd2bb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cd2bc: { // 0x6cd2bc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cd2be: { // 0x6cd2be: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cd2bf: { // 0x6cd2bf: 88442428 MOV byte ptr [ESP + 0x28],AL
    m.w8((f.sp+0x00000028u), (s.ax & 0xffu));
  }
  L006cd2c3: { // 0x6cd2c3: 0f859a000000 JNZ 0x006cd363
    if(integer::condition("JNZ",flags)) goto L006cd363;
  }
  L006cd2c9: { // 0x6cd2c9: 8b8d28020000 MOV ECX,dword ptr [EBP + 0x228]
    s.cx = m.r32((s.bp+0x00000228u));
  }
  L006cd2cf: { // 0x6cd2cf: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006cd2d1: { // 0x6cd2d1: 0f848c000000 JZ 0x006cd363
    if(integer::condition("JZ",flags)) goto L006cd363;
  }
  L006cd2d7: { // 0x6cd2d7: 8db588000000 LEA ESI,[EBP + 0x88]
    s.si = (s.bp+0x00000088u);
  }
  L006cd2dd: { // 0x6cd2dd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cd2de: { // 0x6cd2de: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L006cd2e0: { // 0x6cd2e0: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L006cd2e2: { // 0x6cd2e2: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006cd2e6: { // 0x6cd2e6: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L006cd2e9: { // 0x6cd2e9: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006cd2ed: { // 0x6cd2ed: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006cd2f1: { // 0x6cd2f1: 8b5a08 MOV EBX,dword ptr [EDX + 0x8]
    s.bx = m.r32((s.dx+0x00000008u));
  }
  L006cd2f4: { // 0x6cd2f4: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006cd2f6: { // 0x6cd2f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cd2f7: { // 0x6cd2f7: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),7131898u); flags=s.arithmetic_flags;
  }
  L006cd2fa: { // 0x6cd2fa: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L006cd2fd: { // 0x6cd2fd: 2bfb SUB EDI,EBX
    s.di = integer::sub(s.di,s.bx,32,flags);
  }
  L006cd2ff: { // 0x6cd2ff: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cd300: { // 0x6cd300: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006cd302: { // 0x6cd302: 7e5f JLE 0x006cd363
    if(integer::condition("JLE",flags)) goto L006cd363;
  }
  L006cd304: { // 0x6cd304: 8b8d28020000 MOV ECX,dword ptr [EBP + 0x228]
    s.cx = m.r32((s.bp+0x00000228u));
  }
  L006cd30a: { // 0x6cd30a: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L006cd30e: { // 0x6cd30e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cd30f: { // 0x6cd30f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006cd311: { // 0x6cd311: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),7131924u); flags=s.arithmetic_flags;
  }
  L006cd314: { // 0x6cd314: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L006cd317: { // 0x6cd317: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L006cd31a: { // 0x6cd31a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006cd31c: { // 0x6cd31c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cd31e: { // 0x6cd31e: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  L006cd320: { // 0x6cd320: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006cd322: { // 0x6cd322: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006cd326: { // 0x6cd326: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L006cd32a: { // 0x6cd32a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cd32e: { // 0x6cd32e: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006cd332: { // 0x6cd332: 8b7608 MOV ESI,dword ptr [ESI + 0x8]
    s.si = m.r32((s.si+0x00000008u));
  }
  L006cd335: { // 0x6cd335: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L006cd338: { // 0x6cd338: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L006cd33c: { // 0x6cd33c: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L006cd33e: { // 0x6cd33e: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L006cd340: { // 0x6cd340: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L006cd342: { // 0x6cd342: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L006cd344: { // 0x6cd344: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006cd346: { // 0x6cd346: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006cd349: { // 0x6cd349: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006cd34b: { // 0x6cd34b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006cd34d: { // 0x6cd34d: e82ecddeff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,7131986u); flags=s.arithmetic_flags;
  }
  L006cd352: { // 0x6cd352: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006cd355: { // 0x6cd355: e8f6d60900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7131994u); flags=s.arithmetic_flags;
  }
  L006cd35a: { // 0x6cd35a: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L006cd35c: { // 0x6cd35c: 7d05 JGE 0x006cd363
    if(integer::condition("JGE",flags)) goto L006cd363;
  }
  L006cd35e: { // 0x6cd35e: c644242801 MOV byte ptr [ESP + 0x28],0x1
    m.w8((f.sp+0x00000028u), 0x00000001u);
  }
  L006cd363: { // 0x6cd363: 8a442428 MOV AL,byte ptr [ESP + 0x28]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000028u)));
  }
  L006cd367: { // 0x6cd367: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cd368: { // 0x6cd368: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cd369: { // 0x6cd369: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006cd36a: { // 0x6cd36a: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006cd36d: { // 0x6cd36d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006cd4e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cd4e0: { // 0x6cd4e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cd4e1: { // 0x6cd4e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cd4e3: { // 0x6cd4e3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cd4e4: { // 0x6cd4e4: 8bbef8030000 MOV EDI,dword ptr [ESI + 0x3f8]
    s.di = m.r32((s.si+0x000003f8u));
  }
  L006cd4ea: { // 0x6cd4ea: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006cd4ec: { // 0x6cd4ec: 0f84eb000000 JZ 0x006cd5dd
    if(integer::condition("JZ",flags)) goto L006cd5dd;
  }
  L006cd4f2: { // 0x6cd4f2: 8a477d MOV AL,byte ptr [EDI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000007du)));
  }
  L006cd4f5: { // 0x6cd4f5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cd4f7: { // 0x6cd4f7: 0f84d6000000 JZ 0x006cd5d3
    if(integer::condition("JZ",flags)) goto L006cd5d3;
  }
  L006cd4fd: { // 0x6cd4fd: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006cd4ff: { // 0x6cd4ff: 0f84d8000000 JZ 0x006cd5dd
    if(integer::condition("JZ",flags)) goto L006cd5dd;
  }
  L006cd505: { // 0x6cd505: f6471401 TEST byte ptr [EDI + 0x14],0x1
    (void)integer::logical((m.r8((s.di+0x00000014u)))&(0x00000001u),8,flags);
  }
  L006cd509: { // 0x6cd509: 0f84ce000000 JZ 0x006cd5dd
    if(integer::condition("JZ",flags)) goto L006cd5dd;
  }
  L006cd50f: { // 0x6cd50f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cd511: { // 0x6cd511: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cd512: { // 0x6cd512: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L006cd514: { // 0x6cd514: ff9058020000 CALL dword ptr [EAX + 0x258]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000258u)),7132442u); flags=s.arithmetic_flags;
  }
  L006cd51a: { // 0x6cd51a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006cd51d: { // 0x6cd51d: 7570 JNZ 0x006cd58f
    if(integer::condition("JNZ",flags)) goto L006cd58f;
  }
  L006cd51f: { // 0x6cd51f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cd521: { // 0x6cd521: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cd522: { // 0x6cd522: 6a0f PUSH 0xf
    f.push(m,0x0000000fu);
  }
  L006cd524: { // 0x6cd524: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd526: { // 0x6cd526: ff9258020000 CALL dword ptr [EDX + 0x258]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000258u)),7132460u); flags=s.arithmetic_flags;
  }
  L006cd52c: { // 0x6cd52c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006cd52f: { // 0x6cd52f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cd531: { // 0x6cd531: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006cd533: { // 0x6cd533: 7526 JNZ 0x006cd55b
    if(integer::condition("JNZ",flags)) goto L006cd55b;
  }
  L006cd535: { // 0x6cd535: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L006cd537: { // 0x6cd537: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd539: { // 0x6cd539: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d0u)),7132479u); flags=s.arithmetic_flags;
  }
  L006cd53f: { // 0x6cd53f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cd541: { // 0x6cd541: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006cd543: { // 0x6cd543: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cd544: { // 0x6cd544: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd546: { // 0x6cd546: ff9210040000 CALL dword ptr [EDX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000410u)),7132492u); flags=s.arithmetic_flags;
  }
  L006cd54c: { // 0x6cd54c: c786f803000000000000 MOV dword ptr [ESI + 0x3f8],0x0
    m.w32((s.si+0x000003f8u), 0x00000000u);
  }
  L006cd556: { // 0x6cd556: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cd557: { // 0x6cd557: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006cd559: { // 0x6cd559: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cd55a: { // 0x6cd55a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cd55b: { // 0x6cd55b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006cd55d: { // 0x6cd55d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd55f: { // 0x6cd55f: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d0u)),7132517u); flags=s.arithmetic_flags;
  }
  L006cd565: { // 0x6cd565: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cd567: { // 0x6cd567: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006cd569: { // 0x6cd569: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006cd56b: { // 0x6cd56b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd56d: { // 0x6cd56d: ff9210040000 CALL dword ptr [EDX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000410u)),7132531u); flags=s.arithmetic_flags;
  }
  L006cd573: { // 0x6cd573: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cd575: { // 0x6cd575: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cd576: { // 0x6cd576: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L006cd578: { // 0x6cd578: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd57a: { // 0x6cd57a: c786f803000000000000 MOV dword ptr [ESI + 0x3f8],0x0
    m.w32((s.si+0x000003f8u), 0x00000000u);
  }
  L006cd584: { // 0x6cd584: ff9058020000 CALL dword ptr [EAX + 0x258]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000258u)),7132554u); flags=s.arithmetic_flags;
  }
  L006cd58a: { // 0x6cd58a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cd58b: { // 0x6cd58b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006cd58d: { // 0x6cd58d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cd58e: { // 0x6cd58e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cd58f: { // 0x6cd58f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006cd591: { // 0x6cd591: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cd593: { // 0x6cd593: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7132566u); flags=s.arithmetic_flags;
  }
  L006cd596: { // 0x6cd596: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006cd599: { // 0x6cd599: 7542 JNZ 0x006cd5dd
    if(integer::condition("JNZ",flags)) goto L006cd5dd;
  }
  L006cd59b: { // 0x6cd59b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cd59d: { // 0x6cd59d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd59f: { // 0x6cd59f: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7132578u); flags=s.arithmetic_flags;
  }
  L006cd5a2: { // 0x6cd5a2: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L006cd5a5: { // 0x6cd5a5: 7536 JNZ 0x006cd5dd
    if(integer::condition("JNZ",flags)) goto L006cd5dd;
  }
  L006cd5a7: { // 0x6cd5a7: 8b8718040000 MOV EAX,dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L006cd5ad: { // 0x6cd5ad: 8a884a130000 MOV CL,byte ptr [EAX + 0x134a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000134au)));
  }
  L006cd5b3: { // 0x6cd5b3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006cd5b5: { // 0x6cd5b5: 7426 JZ 0x006cd5dd
    if(integer::condition("JZ",flags)) goto L006cd5dd;
  }
  L006cd5b7: { // 0x6cd5b7: 8a8849130000 MOV CL,byte ptr [EAX + 0x1349]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001349u)));
  }
  L006cd5bd: { // 0x6cd5bd: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006cd5bf: { // 0x6cd5bf: 751c JNZ 0x006cd5dd
    if(integer::condition("JNZ",flags)) goto L006cd5dd;
  }
  L006cd5c1: { // 0x6cd5c1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cd5c3: { // 0x6cd5c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cd5c4: { // 0x6cd5c4: 6a0e PUSH 0xe
    f.push(m,0x0000000eu);
  }
  L006cd5c6: { // 0x6cd5c6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cd5c8: { // 0x6cd5c8: ff9258020000 CALL dword ptr [EDX + 0x258]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000258u)),7132622u); flags=s.arithmetic_flags;
  }
  L006cd5ce: { // 0x6cd5ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cd5cf: { // 0x6cd5cf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cd5d1: { // 0x6cd5d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cd5d2: { // 0x6cd5d2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cd5d3: { // 0x6cd5d3: c786f803000000000000 MOV dword ptr [ESI + 0x3f8],0x0
    m.w32((s.si+0x000003f8u), 0x00000000u);
  }
  L006cd5dd: { // 0x6cd5dd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cd5de: { // 0x6cd5de: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cd5e0: { // 0x6cd5e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cd5e1: { // 0x6cd5e1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
