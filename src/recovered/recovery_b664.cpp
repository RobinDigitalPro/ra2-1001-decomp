#include "recovered/recovery_b664_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b664 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_002c2be0(Memory&,State&,Frame&,const Operations&);
void f_002cdb10(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // Exact original indirect tail jump, no new return address
    if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("664 unproved tail target");
    s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7089120u:f_002c2be0(m,s,child,{});break;
case 7133968u:f_002cdb10(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
default:throw std::domain_error("recovery664 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006c8620(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c8620: { // 0x6c8620: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c8621: { // 0x6c8621: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006c8623: { // 0x6c8623: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006c8625: { // 0x6c8625: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7112235u); flags=s.arithmetic_flags;
  }
  L006c862b: { // 0x6c862b: 8a88d90a0000 MOV CL,byte ptr [EAX + 0xad9]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ad9u)));
  }
  L006c8631: { // 0x6c8631: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c8633: { // 0x6c8633: 7504 JNZ 0x006c8639
    if(integer::condition("JNZ",flags)) goto L006c8639;
  }
  L006c8635: { // 0x6c8635: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c8637: { // 0x6c8637: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c8638: { // 0x6c8638: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c8639: { // 0x6c8639: 8b8fb4010000 MOV ECX,dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006c863f: { // 0x6c863f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c8640: { // 0x6c8640: 8b8130010000 MOV EAX,dword ptr [ECX + 0x130]
    s.ax = m.r32((s.cx+0x00000130u));
  }
  L006c8646: { // 0x6c8646: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c8648: { // 0x6c8648: 750d JNZ 0x006c8657
    if(integer::condition("JNZ",flags)) goto L006c8657;
  }
  L006c864a: { // 0x6c864a: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006c864f: { // 0x6c864f: 8bb0500c0000 MOV ESI,dword ptr [EAX + 0xc50]
    s.si = m.r32((s.ax+0x00000c50u));
  }
  L006c8655: { // 0x6c8655: eb18 JMP 0x006c866f
    goto L006c866f;
  }
  L006c8657: { // 0x6c8657: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006c865a: { // 0x6c865a: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006c865f: { // 0x6c865f: 7508 JNZ 0x006c8669
    if(integer::condition("JNZ",flags)) goto L006c8669;
  }
  L006c8661: { // 0x6c8661: 8bb0540c0000 MOV ESI,dword ptr [EAX + 0xc54]
    s.si = m.r32((s.ax+0x00000c54u));
  }
  L006c8667: { // 0x6c8667: eb06 JMP 0x006c866f
    goto L006c866f;
  }
  L006c8669: { // 0x6c8669: 8bb0440c0000 MOV ESI,dword ptr [EAX + 0xc44]
    s.si = m.r32((s.ax+0x00000c44u));
  }
  L006c866f: { // 0x6c866f: 8b4934 MOV ECX,dword ptr [ECX + 0x34]
    s.cx = m.r32((s.cx+0x00000034u));
  }
  L006c8672: { // 0x6c8672: 83b9bc000000ff CMP dword ptr [ECX + 0xbc],-0x1
    (void)integer::sub(m.r32((s.cx+0x000000bcu)),0xffffffffu,32,flags);
  }
  L006c8679: { // 0x6c8679: 7438 JZ 0x006c86b3
    if(integer::condition("JZ",flags)) goto L006c86b3;
  }
  L006c867b: { // 0x6c867b: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006c867d: { // 0x6c867d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c867f: { // 0x6c867f: ff928c020000 CALL dword ptr [EDX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000028cu)),7112325u); flags=s.arithmetic_flags;
  }
  L006c8685: { // 0x6c8685: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c8687: { // 0x6c8687: 7430 JZ 0x006c86b9
    if(integer::condition("JZ",flags)) goto L006c86b9;
  }
  L006c8689: { // 0x6c8689: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006c868e: { // 0x6c868e: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  L006c8690: { // 0x6c8690: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c8692: { // 0x6c8692: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L006c8698: { // 0x6c8698: e8a377f6ff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,7112349u); flags=s.arithmetic_flags;
  }
  L006c869d: { // 0x6c869d: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L006c86a0: { // 0x6c86a0: 7d17 JGE 0x006c86b9
    if(integer::condition("JGE",flags)) goto L006c86b9;
  }
  L006c86a2: { // 0x6c86a2: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006c86a8: { // 0x6c86a8: 8bb1440c0000 MOV ESI,dword ptr [ECX + 0xc44]
    s.si = m.r32((s.cx+0x00000c44u));
  }
  L006c86ae: { // 0x6c86ae: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006c86b0: { // 0x6c86b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c86b1: { // 0x6c86b1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c86b2: { // 0x6c86b2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c86b3: { // 0x6c86b3: 8bb0440c0000 MOV ESI,dword ptr [EAX + 0xc44]
    s.si = m.r32((s.ax+0x00000c44u));
  }
  L006c86b9: { // 0x6c86b9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006c86bb: { // 0x6c86bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c86bc: { // 0x6c86bc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c86bd: { // 0x6c86bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
