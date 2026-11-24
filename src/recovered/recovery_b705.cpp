#include "recovered/recovery_b705_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b705 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_000102e0(Memory&,State&,Frame&,const Operations&);
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_0001b410(Memory&,State&,Frame&,const Operations&);
void f_0001b2e0(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_002b69d0(Memory&,State&,Frame&,const Operations&);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("705 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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

void f_000102e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004102e0: { // 0x4102e0: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004102e2: { // 0x4102e2: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004102e5: { // 0x4102e5: 8d542400 LEA EDX, [ESP]
    s.dx = (f.sp);
  }
  L004102e9: { // 0x4102e9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004102ea: { // 0x4102ea: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004102eb: { // 0x4102eb: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4260590u); flags=s.arithmetic_flags;
  }
  L004102ee: { // 0x4102ee: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004102f0: { // 0x4102f0: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004102f4: { // 0x4102f4: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004102f6: { // 0x4102f6: 8b31 MOV ESI, dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L004102f8: { // 0x4102f8: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L004102fa: { // 0x4102fa: 8b7104 MOV ESI, dword ptr [ECX + 4]
    s.si = m.r32((s.cx+4u));
  }
  L004102fd: { // 0x4102fd: 897204 MOV dword ptr [EDX + 4], ESI
    m.w32((s.dx+4u), s.si);
  }
  L00410300: { // 0x410300: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00410301: { // 0x410301: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L00410304: { // 0x410304: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L00410307: { // 0x410307: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0041030a: { // 0x41030a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0001b410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b410: { // 0x41b410: 8a8170010000 MOV AL, byte ptr [ECX + 0x170]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000170u)));
  }
  L0041b416: { // 0x41b416: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b2e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b2e0: { // 0x41b2e0: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0041b2e2: { // 0x41b2e2: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
} // namespace
namespace {
void f_002b69d0(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b69d0: { // 0x6b69d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b69d1: { // 0x6b69d1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b69d2: { // 0x6b69d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b69d3: { // 0x6b69d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b69d4: { // 0x6b69d4: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L006b69d6: { // 0x6b69d6: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b69d8: { // 0x6b69d8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7039454u); flags=s.arithmetic_flags;
  }
  L006b69de: { // 0x6b69de: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006b69e0: { // 0x6b69e0: e80be20100 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7039461u); flags=s.arithmetic_flags;
  }
  L006b69e5: { // 0x6b69e5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b69e7: { // 0x6b69e7: 7416 JZ 0x6b69ff
    if(integer::condition("JZ",flags)) goto L006b69ff;
  }
  L006b69e9: { // 0x6b69e9: 8bbf0c010000 MOV EDI, dword ptr [EDI + 0x10c]
    s.di = m.r32((s.di+0x0000010cu));
  }
  L006b69ef: { // 0x6b69ef: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L006b69f1: { // 0x6b69f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006b69f2: { // 0x6b69f2: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006b69f4: { // 0x6b69f4: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L006b69f6: { // 0x6b69f6: 23c7 AND EAX, EDI
    s.ax = integer::logical((s.ax)&(s.di),32,flags);
  }
  L006b69f8: { // 0x6b69f8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b69f9: { // 0x6b69f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b69fa: { // 0x6b69fa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b69fb: { // 0x6b69fb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b69fc: { // 0x6b69fc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b69ff: { // 0x6b69ff: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a01: { // 0x6b6a01: 6a01 PUSH 1
    f.push(m,1u);
  }
  L006b6a03: { // 0x6b6a03: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a05: { // 0x6b6a05: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7039499u); flags=s.arithmetic_flags;
  }
  L006b6a0b: { // 0x6b6a0b: 8b28 MOV EBP, dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  L006b6a0d: { // 0x6b6a0d: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006b6a0f: { // 0x6b6a0f: 0f84db010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6a15: { // 0x6b6a15: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6a17: { // 0x6b6a17: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b6a19: { // 0x6b6a19: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a1b: { // 0x6b6a1b: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7039521u); flags=s.arithmetic_flags;
  }
  L006b6a21: { // 0x6b6a21: 8b18 MOV EBX, dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L006b6a23: { // 0x6b6a23: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006b6a25: { // 0x6b6a25: 0f84c5010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6a2b: { // 0x6b6a2b: 8a8512010000 MOV AL, byte ptr [EBP + 0x112]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000112u)));
  }
  L006b6a31: { // 0x6b6a31: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a33: { // 0x6b6a33: 0f85b7010000 JNZ 0x6b6bf0
    if(integer::condition("JNZ",flags)) goto L006b6bf0;
  }
  L006b6a39: { // 0x6b6a39: 8a8526010000 MOV AL, byte ptr [EBP + 0x126]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000126u)));
  }
  L006b6a3f: { // 0x6b6a3f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a41: { // 0x6b6a41: 741b JZ 0x6b6a5e
    if(integer::condition("JZ",flags)) goto L006b6a5e;
  }
  L006b6a43: { // 0x6b6a43: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a45: { // 0x6b6a45: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a47: { // 0x6b6a47: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),7039565u); flags=s.arithmetic_flags;
  }
  L006b6a4d: { // 0x6b6a4d: 83f810 CMP EAX, 0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L006b6a50: { // 0x6b6a50: 750c JNZ 0x6b6a5e
    if(integer::condition("JNZ",flags)) goto L006b6a5e;
  }
  L006b6a52: { // 0x6b6a52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a53: { // 0x6b6a53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a54: { // 0x6b6a54: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6a55: { // 0x6b6a55: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6a5a: { // 0x6b6a5a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6a5b: { // 0x6b6a5b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6a5e: { // 0x6b6a5e: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6a60: { // 0x6b6a60: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a62: { // 0x6b6a62: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7039589u); flags=s.arithmetic_flags;
  }
  L006b6a65: { // 0x6b6a65: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6a68: { // 0x6b6a68: 7516 JNZ 0x6b6a80
    if(integer::condition("JNZ",flags)) goto L006b6a80;
  }
  L006b6a6a: { // 0x6b6a6a: 8a8731050000 MOV AL, byte ptr [EDI + 0x531]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000531u)));
  }
  L006b6a70: { // 0x6b6a70: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a72: { // 0x6b6a72: 740c JZ 0x6b6a80
    if(integer::condition("JZ",flags)) goto L006b6a80;
  }
  L006b6a74: { // 0x6b6a74: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a75: { // 0x6b6a75: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a76: { // 0x6b6a76: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6a77: { // 0x6b6a77: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6a7c: { // 0x6b6a7c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6a7d: { // 0x6b6a7d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6a80: { // 0x6b6a80: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a82: { // 0x6b6a82: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a84: { // 0x6b6a84: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7039623u); flags=s.arithmetic_flags;
  }
  L006b6a87: { // 0x6b6a87: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6a8a: { // 0x6b6a8a: 752c JNZ 0x6b6ab8
    if(integer::condition("JNZ",flags)) goto L006b6ab8;
  }
  L006b6a8c: { // 0x6b6a8c: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a8e: { // 0x6b6a8e: e8cdc4d9ff CALL 0x452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7039635u); flags=s.arithmetic_flags;
  }
  L006b6a93: { // 0x6b6a93: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6a95: { // 0x6b6a95: 7e21 JLE 0x6b6ab8
    if(integer::condition("JLE",flags)) goto L006b6ab8;
  }
  L006b6a97: { // 0x6b6a97: 8b8758050000 MOV EAX, dword ptr [EDI + 0x558]
    s.ax = m.r32((s.di+0x00000558u));
  }
  L006b6a9d: { // 0x6b6a9d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a9e: { // 0x6b6a9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a9f: { // 0x6b6a9f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6aa0: { // 0x6b6aa0: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6aa2: { // 0x6b6aa2: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b6aa4: { // 0x6b6aa4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6aa5: { // 0x6b6aa5: 8b91b4010000 MOV EDX, dword ptr [ECX + 0x1b4]
    s.dx = m.r32((s.cx+0x000001b4u));
  }
  L006b6aab: { // 0x6b6aab: 83ba3001000001 CMP dword ptr [EDX + 0x130], 1
    (void)integer::sub(m.r32((s.dx+0x00000130u)),1u,32,flags);
  }
  L006b6ab2: { // 0x6b6ab2: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006b6ab5: { // 0x6b6ab5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6ab8: { // 0x6b6ab8: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L006b6abc: { // 0x6b6abc: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b6abe: { // 0x6b6abe: 0f842c010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6ac4: { // 0x6b6ac4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6ac6: { // 0x6b6ac6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6ac8: { // 0x6b6ac8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7039691u); flags=s.arithmetic_flags;
  }
  L006b6acb: { // 0x6b6acb: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6ace: { // 0x6b6ace: 753c JNZ 0x6b6b0c
    if(integer::condition("JNZ",flags)) goto L006b6b0c;
  }
  L006b6ad0: { // 0x6b6ad0: 8b8fb4010000 MOV ECX, dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006b6ad6: { // 0x6b6ad6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6ad7: { // 0x6b6ad7: e8a4e1e2ff CALL 0x4e4c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c80u,7039708u); flags=s.arithmetic_flags;
  }
  L006b6adc: { // 0x6b6adc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6ade: { // 0x6b6ade: 742c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6ae0: { // 0x6b6ae0: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006b6ae6: { // 0x6b6ae6: 8a8155010000 MOV AL, byte ptr [ECX + 0x155]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000155u)));
  }
  L006b6aec: { // 0x6b6aec: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6aee: { // 0x6b6aee: 741c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6af0: { // 0x6b6af0: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L006b6af6: { // 0x6b6af6: 8a8218120000 MOV AL, byte ptr [EDX + 0x1218]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001218u)));
  }
  L006b6afc: { // 0x6b6afc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6afe: { // 0x6b6afe: 740c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6b00: { // 0x6b6b00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b01: { // 0x6b6b01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b02: { // 0x6b6b02: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b03: { // 0x6b6b03: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b08: { // 0x6b6b08: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b09: { // 0x6b6b09: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6b0c: { // 0x6b6b0c: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6b0e: { // 0x6b6b0e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6b10: { // 0x6b6b10: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7039763u); flags=s.arithmetic_flags;
  }
  L006b6b13: { // 0x6b6b13: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L006b6b16: { // 0x6b6b16: 7516 JNZ 0x6b6b2e
    if(integer::condition("JNZ",flags)) goto L006b6b2e;
  }
  L006b6b18: { // 0x6b6b18: 8a87b2050000 MOV AL, byte ptr [EDI + 0x5b2]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005b2u)));
  }
  L006b6b1e: { // 0x6b6b1e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6b20: { // 0x6b6b20: 740c JZ 0x6b6b2e
    if(integer::condition("JZ",flags)) goto L006b6b2e;
  }
  L006b6b22: { // 0x6b6b22: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b23: { // 0x6b6b23: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b24: { // 0x6b6b24: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b25: { // 0x6b6b25: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b2a: { // 0x6b6b2a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b2b: { // 0x6b6b2b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6b2e: { // 0x6b6b2e: f6461401 TEST byte ptr [ESI + 0x14], 1
    (void)integer::logical((m.r8((s.si+0x00000014u)))&(1u),8,flags);
  }
  L006b6b32: { // 0x6b6b32: 0f84b8000000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6b38: { // 0x6b6b38: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b3a: { // 0x6b6b3a: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6b3c: { // 0x6b6b3c: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7039810u); flags=s.arithmetic_flags;
  }
  L006b6b42: { // 0x6b6b42: 8b809c000000 MOV EAX, dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006b6b48: { // 0x6b6b48: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006b6b4e: { // 0x6b6b4e: dd84c1a0000000 FLD qword ptr [ECX + EAX*8 + 0xa0]
    const auto address=(s.cx+(s.ax * 8u)+0x000000a0u);
    s.fp.load64(read64(m,address));
  }
  L006b6b55: { // 0x6b6b55: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006b6b5b: { // 0x6b6b5b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006b6b5d: { // 0x6b6b5d: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L006b6b60: { // 0x6b6b60: 0f858a000000 JNZ 0x6b6bf0
    if(integer::condition("JNZ",flags)) goto L006b6bf0;
  }
  L006b6b66: { // 0x6b6b66: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b68: { // 0x6b6b68: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6b6a: { // 0x6b6b6a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7039856u); flags=s.arithmetic_flags;
  }
  L006b6b70: { // 0x6b6b70: 8b809c000000 MOV EAX, dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006b6b76: { // 0x6b6b76: 8b8bac000000 MOV ECX, dword ptr [EBX + 0xac]
    s.cx = m.r32((s.bx+0x000000acu));
  }
  L006b6b7c: { // 0x6b6b7c: dd84c1a0000000 FLD qword ptr [ECX + EAX*8 + 0xa0]
    const auto address=(s.cx+(s.ax * 8u)+0x000000a0u);
    s.fp.load64(read64(m,address));
  }
  L006b6b83: { // 0x6b6b83: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006b6b89: { // 0x6b6b89: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006b6b8b: { // 0x6b6b8b: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L006b6b8e: { // 0x6b6b8e: 740c JZ 0x6b6b9c
    if(integer::condition("JZ",flags)) goto L006b6b9c;
  }
  L006b6b90: { // 0x6b6b90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b91: { // 0x6b6b91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b92: { // 0x6b6b92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b93: { // 0x6b6b93: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b98: { // 0x6b6b98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b99: { // 0x6b6b99: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6b9c: { // 0x6b6b9c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b9e: { // 0x6b6b9e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6ba0: { // 0x6b6ba0: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),7039910u); flags=s.arithmetic_flags;
  }
  L006b6ba6: { // 0x6b6ba6: 83b8ec00000002 CMP dword ptr [EAX + 0xec], 2
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),2u,32,flags);
  }
  L006b6bad: { // 0x6b6bad: 7417 JZ 0x6b6bc6
    if(integer::condition("JZ",flags)) goto L006b6bc6;
  }
  L006b6baf: { // 0x6b6baf: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6bb1: { // 0x6b6bb1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6bb3: { // 0x6b6bb3: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a4u)),7039929u); flags=s.arithmetic_flags;
  }
  L006b6bb9: { // 0x6b6bb9: 83b8ec00000006 CMP dword ptr [EAX + 0xec], 6
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),6u,32,flags);
  }
  L006b6bc0: { // 0x6b6bc0: 7404 JZ 0x6b6bc6
    if(integer::condition("JZ",flags)) goto L006b6bc6;
  }
  L006b6bc2: { // 0x6b6bc2: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006b6bc4: { // 0x6b6bc4: eb02 JMP 0x6b6bc8
    goto L006b6bc8;
  }
  L006b6bc6: { // 0x6b6bc6: b301 MOV BL, 1
    s.bx = with_al(s.bx, 1u);
  }
  L006b6bc8: { // 0x6b6bc8: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6bca: { // 0x6b6bca: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6bcc: { // 0x6b6bcc: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000054u)),7039951u); flags=s.arithmetic_flags;
  }
  L006b6bcf: { // 0x6b6bcf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6bd1: { // 0x6b6bd1: 7402 JZ 0x6b6bd5
    if(integer::condition("JZ",flags)) goto L006b6bd5;
  }
  L006b6bd3: { // 0x6b6bd3: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006b6bd5: { // 0x6b6bd5: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L006b6bd8: { // 0x6b6bd8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6bda: { // 0x6b6bda: 751d JNZ 0x6b6bf9
    if(integer::condition("JNZ",flags)) goto L006b6bf9;
  }
  L006b6bdc: { // 0x6b6bdc: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006b6bde: { // 0x6b6bde: 7419 JZ 0x6b6bf9
    if(integer::condition("JZ",flags)) goto L006b6bf9;
  }
  L006b6be0: { // 0x6b6be0: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6be2: { // 0x6b6be2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6be3: { // 0x6b6be3: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6be5: { // 0x6b6be5: ff90bc020000 CALL dword ptr [EAX + 0x2bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000002bcu)),7039979u); flags=s.arithmetic_flags;
  }
  L006b6beb: { // 0x6b6beb: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L006b6bee: { // 0x6b6bee: 7502 JNZ 0x6b6bf2
    if(integer::condition("JNZ",flags)) goto L006b6bf2;
  }
  L006b6bf0: { // 0x6b6bf0: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b6bf2: { // 0x6b6bf2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6bf3: { // 0x6b6bf3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6bf4: { // 0x6b6bf4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6bf5: { // 0x6b6bf5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6bf6: { // 0x6b6bf6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6bf9: { // 0x6b6bf9: 8b8da0000000 MOV ECX, dword ptr [EBP + 0xa0]
    s.cx = m.r32((s.bp+0x000000a0u));
  }
  L006b6bff: { // 0x6b6bff: 8a8174020000 MOV AL, byte ptr [ECX + 0x274]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000274u)));
  }
  L006b6c05: { // 0x6b6c05: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6c07: { // 0x6b6c07: 74e7 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6c09: { // 0x6b6c09: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6c0b: { // 0x6b6c0b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6c0d: { // 0x6b6c0d: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000054u)),7040016u); flags=s.arithmetic_flags;
  }
  L006b6c10: { // 0x6b6c10: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6c12: { // 0x6b6c12: 74dc JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6c14: { // 0x6b6c14: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6c15: { // 0x6b6c15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6c16: { // 0x6b6c16: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6c17: { // 0x6b6c17: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6c1c: { // 0x6b6c1c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6c1d: { // 0x6b6c1d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x6b69d0u:f_002b69d0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 4260576u:f_000102e0(m,s,child,{});break;
case 4472336u:f_00043e10(m,s,child,{});break;
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4305936u:f_0001b410(m,s,child,{});break;
case 4305632u:f_0001b2e0(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
default:throw std::domain_error("recovery705 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006b69d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b69d0: { // 0x6b69d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b69d1: { // 0x6b69d1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b69d2: { // 0x6b69d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b69d3: { // 0x6b69d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b69d4: { // 0x6b69d4: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L006b69d6: { // 0x6b69d6: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b69d8: { // 0x6b69d8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7039454u); flags=s.arithmetic_flags;
  }
  L006b69de: { // 0x6b69de: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006b69e0: { // 0x6b69e0: e80be20100 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7039461u); flags=s.arithmetic_flags;
  }
  L006b69e5: { // 0x6b69e5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b69e7: { // 0x6b69e7: 7416 JZ 0x6b69ff
    if(integer::condition("JZ",flags)) goto L006b69ff;
  }
  L006b69e9: { // 0x6b69e9: 8bbf0c010000 MOV EDI, dword ptr [EDI + 0x10c]
    s.di = m.r32((s.di+0x0000010cu));
  }
  L006b69ef: { // 0x6b69ef: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L006b69f1: { // 0x6b69f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006b69f2: { // 0x6b69f2: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006b69f4: { // 0x6b69f4: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L006b69f6: { // 0x6b69f6: 23c7 AND EAX, EDI
    s.ax = integer::logical((s.ax)&(s.di),32,flags);
  }
  L006b69f8: { // 0x6b69f8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b69f9: { // 0x6b69f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b69fa: { // 0x6b69fa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b69fb: { // 0x6b69fb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b69fc: { // 0x6b69fc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b69ff: { // 0x6b69ff: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a01: { // 0x6b6a01: 6a01 PUSH 1
    f.push(m,1u);
  }
  L006b6a03: { // 0x6b6a03: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a05: { // 0x6b6a05: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7039499u); flags=s.arithmetic_flags;
  }
  L006b6a0b: { // 0x6b6a0b: 8b28 MOV EBP, dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  L006b6a0d: { // 0x6b6a0d: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006b6a0f: { // 0x6b6a0f: 0f84db010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6a15: { // 0x6b6a15: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6a17: { // 0x6b6a17: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b6a19: { // 0x6b6a19: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a1b: { // 0x6b6a1b: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7039521u); flags=s.arithmetic_flags;
  }
  L006b6a21: { // 0x6b6a21: 8b18 MOV EBX, dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L006b6a23: { // 0x6b6a23: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006b6a25: { // 0x6b6a25: 0f84c5010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6a2b: { // 0x6b6a2b: 8a8512010000 MOV AL, byte ptr [EBP + 0x112]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000112u)));
  }
  L006b6a31: { // 0x6b6a31: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a33: { // 0x6b6a33: 0f85b7010000 JNZ 0x6b6bf0
    if(integer::condition("JNZ",flags)) goto L006b6bf0;
  }
  L006b6a39: { // 0x6b6a39: 8a8526010000 MOV AL, byte ptr [EBP + 0x126]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000126u)));
  }
  L006b6a3f: { // 0x6b6a3f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a41: { // 0x6b6a41: 741b JZ 0x6b6a5e
    if(integer::condition("JZ",flags)) goto L006b6a5e;
  }
  L006b6a43: { // 0x6b6a43: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a45: { // 0x6b6a45: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a47: { // 0x6b6a47: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),7039565u); flags=s.arithmetic_flags;
  }
  L006b6a4d: { // 0x6b6a4d: 83f810 CMP EAX, 0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L006b6a50: { // 0x6b6a50: 750c JNZ 0x6b6a5e
    if(integer::condition("JNZ",flags)) goto L006b6a5e;
  }
  L006b6a52: { // 0x6b6a52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a53: { // 0x6b6a53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a54: { // 0x6b6a54: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6a55: { // 0x6b6a55: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6a5a: { // 0x6b6a5a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6a5b: { // 0x6b6a5b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6a5e: { // 0x6b6a5e: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6a60: { // 0x6b6a60: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a62: { // 0x6b6a62: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7039589u); flags=s.arithmetic_flags;
  }
  L006b6a65: { // 0x6b6a65: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6a68: { // 0x6b6a68: 7516 JNZ 0x6b6a80
    if(integer::condition("JNZ",flags)) goto L006b6a80;
  }
  L006b6a6a: { // 0x6b6a6a: 8a8731050000 MOV AL, byte ptr [EDI + 0x531]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000531u)));
  }
  L006b6a70: { // 0x6b6a70: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a72: { // 0x6b6a72: 740c JZ 0x6b6a80
    if(integer::condition("JZ",flags)) goto L006b6a80;
  }
  L006b6a74: { // 0x6b6a74: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a75: { // 0x6b6a75: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a76: { // 0x6b6a76: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6a77: { // 0x6b6a77: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6a7c: { // 0x6b6a7c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6a7d: { // 0x6b6a7d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6a80: { // 0x6b6a80: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a82: { // 0x6b6a82: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a84: { // 0x6b6a84: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7039623u); flags=s.arithmetic_flags;
  }
  L006b6a87: { // 0x6b6a87: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6a8a: { // 0x6b6a8a: 752c JNZ 0x6b6ab8
    if(integer::condition("JNZ",flags)) goto L006b6ab8;
  }
  L006b6a8c: { // 0x6b6a8c: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a8e: { // 0x6b6a8e: e8cdc4d9ff CALL 0x452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7039635u); flags=s.arithmetic_flags;
  }
  L006b6a93: { // 0x6b6a93: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6a95: { // 0x6b6a95: 7e21 JLE 0x6b6ab8
    if(integer::condition("JLE",flags)) goto L006b6ab8;
  }
  L006b6a97: { // 0x6b6a97: 8b8758050000 MOV EAX, dword ptr [EDI + 0x558]
    s.ax = m.r32((s.di+0x00000558u));
  }
  L006b6a9d: { // 0x6b6a9d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a9e: { // 0x6b6a9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a9f: { // 0x6b6a9f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6aa0: { // 0x6b6aa0: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6aa2: { // 0x6b6aa2: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b6aa4: { // 0x6b6aa4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6aa5: { // 0x6b6aa5: 8b91b4010000 MOV EDX, dword ptr [ECX + 0x1b4]
    s.dx = m.r32((s.cx+0x000001b4u));
  }
  L006b6aab: { // 0x6b6aab: 83ba3001000001 CMP dword ptr [EDX + 0x130], 1
    (void)integer::sub(m.r32((s.dx+0x00000130u)),1u,32,flags);
  }
  L006b6ab2: { // 0x6b6ab2: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006b6ab5: { // 0x6b6ab5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6ab8: { // 0x6b6ab8: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L006b6abc: { // 0x6b6abc: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b6abe: { // 0x6b6abe: 0f842c010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6ac4: { // 0x6b6ac4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6ac6: { // 0x6b6ac6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6ac8: { // 0x6b6ac8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7039691u); flags=s.arithmetic_flags;
  }
  L006b6acb: { // 0x6b6acb: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6ace: { // 0x6b6ace: 753c JNZ 0x6b6b0c
    if(integer::condition("JNZ",flags)) goto L006b6b0c;
  }
  L006b6ad0: { // 0x6b6ad0: 8b8fb4010000 MOV ECX, dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006b6ad6: { // 0x6b6ad6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6ad7: { // 0x6b6ad7: e8a4e1e2ff CALL 0x4e4c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c80u,7039708u); flags=s.arithmetic_flags;
  }
  L006b6adc: { // 0x6b6adc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6ade: { // 0x6b6ade: 742c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6ae0: { // 0x6b6ae0: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006b6ae6: { // 0x6b6ae6: 8a8155010000 MOV AL, byte ptr [ECX + 0x155]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000155u)));
  }
  L006b6aec: { // 0x6b6aec: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6aee: { // 0x6b6aee: 741c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6af0: { // 0x6b6af0: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L006b6af6: { // 0x6b6af6: 8a8218120000 MOV AL, byte ptr [EDX + 0x1218]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001218u)));
  }
  L006b6afc: { // 0x6b6afc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6afe: { // 0x6b6afe: 740c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6b00: { // 0x6b6b00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b01: { // 0x6b6b01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b02: { // 0x6b6b02: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b03: { // 0x6b6b03: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b08: { // 0x6b6b08: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b09: { // 0x6b6b09: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6b0c: { // 0x6b6b0c: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6b0e: { // 0x6b6b0e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6b10: { // 0x6b6b10: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7039763u); flags=s.arithmetic_flags;
  }
  L006b6b13: { // 0x6b6b13: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L006b6b16: { // 0x6b6b16: 7516 JNZ 0x6b6b2e
    if(integer::condition("JNZ",flags)) goto L006b6b2e;
  }
  L006b6b18: { // 0x6b6b18: 8a87b2050000 MOV AL, byte ptr [EDI + 0x5b2]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005b2u)));
  }
  L006b6b1e: { // 0x6b6b1e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6b20: { // 0x6b6b20: 740c JZ 0x6b6b2e
    if(integer::condition("JZ",flags)) goto L006b6b2e;
  }
  L006b6b22: { // 0x6b6b22: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b23: { // 0x6b6b23: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b24: { // 0x6b6b24: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b25: { // 0x6b6b25: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b2a: { // 0x6b6b2a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b2b: { // 0x6b6b2b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6b2e: { // 0x6b6b2e: f6461401 TEST byte ptr [ESI + 0x14], 1
    (void)integer::logical((m.r8((s.si+0x00000014u)))&(1u),8,flags);
  }
  L006b6b32: { // 0x6b6b32: 0f84b8000000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6b38: { // 0x6b6b38: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b3a: { // 0x6b6b3a: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6b3c: { // 0x6b6b3c: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7039810u); flags=s.arithmetic_flags;
  }
  L006b6b42: { // 0x6b6b42: 8b809c000000 MOV EAX, dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006b6b48: { // 0x6b6b48: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006b6b4e: { // 0x6b6b4e: dd84c1a0000000 FLD qword ptr [ECX + EAX*8 + 0xa0]
    const auto address=(s.cx+(s.ax * 8u)+0x000000a0u);
    s.fp.load64(read64(m,address));
  }
  L006b6b55: { // 0x6b6b55: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006b6b5b: { // 0x6b6b5b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006b6b5d: { // 0x6b6b5d: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L006b6b60: { // 0x6b6b60: 0f858a000000 JNZ 0x6b6bf0
    if(integer::condition("JNZ",flags)) goto L006b6bf0;
  }
  L006b6b66: { // 0x6b6b66: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b68: { // 0x6b6b68: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6b6a: { // 0x6b6b6a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7039856u); flags=s.arithmetic_flags;
  }
  L006b6b70: { // 0x6b6b70: 8b809c000000 MOV EAX, dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006b6b76: { // 0x6b6b76: 8b8bac000000 MOV ECX, dword ptr [EBX + 0xac]
    s.cx = m.r32((s.bx+0x000000acu));
  }
  L006b6b7c: { // 0x6b6b7c: dd84c1a0000000 FLD qword ptr [ECX + EAX*8 + 0xa0]
    const auto address=(s.cx+(s.ax * 8u)+0x000000a0u);
    s.fp.load64(read64(m,address));
  }
  L006b6b83: { // 0x6b6b83: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006b6b89: { // 0x6b6b89: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006b6b8b: { // 0x6b6b8b: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L006b6b8e: { // 0x6b6b8e: 740c JZ 0x6b6b9c
    if(integer::condition("JZ",flags)) goto L006b6b9c;
  }
  L006b6b90: { // 0x6b6b90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b91: { // 0x6b6b91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b92: { // 0x6b6b92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b93: { // 0x6b6b93: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b98: { // 0x6b6b98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b99: { // 0x6b6b99: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6b9c: { // 0x6b6b9c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b9e: { // 0x6b6b9e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6ba0: { // 0x6b6ba0: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),7039910u); flags=s.arithmetic_flags;
  }
  L006b6ba6: { // 0x6b6ba6: 83b8ec00000002 CMP dword ptr [EAX + 0xec], 2
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),2u,32,flags);
  }
  L006b6bad: { // 0x6b6bad: 7417 JZ 0x6b6bc6
    if(integer::condition("JZ",flags)) goto L006b6bc6;
  }
  L006b6baf: { // 0x6b6baf: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6bb1: { // 0x6b6bb1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6bb3: { // 0x6b6bb3: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a4u)),7039929u); flags=s.arithmetic_flags;
  }
  L006b6bb9: { // 0x6b6bb9: 83b8ec00000006 CMP dword ptr [EAX + 0xec], 6
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),6u,32,flags);
  }
  L006b6bc0: { // 0x6b6bc0: 7404 JZ 0x6b6bc6
    if(integer::condition("JZ",flags)) goto L006b6bc6;
  }
  L006b6bc2: { // 0x6b6bc2: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006b6bc4: { // 0x6b6bc4: eb02 JMP 0x6b6bc8
    goto L006b6bc8;
  }
  L006b6bc6: { // 0x6b6bc6: b301 MOV BL, 1
    s.bx = with_al(s.bx, 1u);
  }
  L006b6bc8: { // 0x6b6bc8: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6bca: { // 0x6b6bca: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6bcc: { // 0x6b6bcc: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000054u)),7039951u); flags=s.arithmetic_flags;
  }
  L006b6bcf: { // 0x6b6bcf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6bd1: { // 0x6b6bd1: 7402 JZ 0x6b6bd5
    if(integer::condition("JZ",flags)) goto L006b6bd5;
  }
  L006b6bd3: { // 0x6b6bd3: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006b6bd5: { // 0x6b6bd5: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L006b6bd8: { // 0x6b6bd8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6bda: { // 0x6b6bda: 751d JNZ 0x6b6bf9
    if(integer::condition("JNZ",flags)) goto L006b6bf9;
  }
  L006b6bdc: { // 0x6b6bdc: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006b6bde: { // 0x6b6bde: 7419 JZ 0x6b6bf9
    if(integer::condition("JZ",flags)) goto L006b6bf9;
  }
  L006b6be0: { // 0x6b6be0: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6be2: { // 0x6b6be2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6be3: { // 0x6b6be3: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6be5: { // 0x6b6be5: ff90bc020000 CALL dword ptr [EAX + 0x2bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000002bcu)),7039979u); flags=s.arithmetic_flags;
  }
  L006b6beb: { // 0x6b6beb: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L006b6bee: { // 0x6b6bee: 7502 JNZ 0x6b6bf2
    if(integer::condition("JNZ",flags)) goto L006b6bf2;
  }
  L006b6bf0: { // 0x6b6bf0: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b6bf2: { // 0x6b6bf2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6bf3: { // 0x6b6bf3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6bf4: { // 0x6b6bf4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6bf5: { // 0x6b6bf5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6bf6: { // 0x6b6bf6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6bf9: { // 0x6b6bf9: 8b8da0000000 MOV ECX, dword ptr [EBP + 0xa0]
    s.cx = m.r32((s.bp+0x000000a0u));
  }
  L006b6bff: { // 0x6b6bff: 8a8174020000 MOV AL, byte ptr [ECX + 0x274]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000274u)));
  }
  L006b6c05: { // 0x6b6c05: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6c07: { // 0x6b6c07: 74e7 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6c09: { // 0x6b6c09: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6c0b: { // 0x6b6c0b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6c0d: { // 0x6b6c0d: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000054u)),7040016u); flags=s.arithmetic_flags;
  }
  L006b6c10: { // 0x6b6c10: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6c12: { // 0x6b6c12: 74dc JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6c14: { // 0x6b6c14: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6c15: { // 0x6b6c15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6c16: { // 0x6b6c16: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6c17: { // 0x6b6c17: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6c1c: { // 0x6b6c1c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6c1d: { // 0x6b6c1d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006cbb20(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cbb20: { // 0x6cbb20: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L006cbb23: { // 0x6cbb23: a1907caa00 MOV EAX,[0x00aa7c90]
    s.ax = m.r32((0x00aa7c90u));
  }
  L006cbb28: { // 0x6cbb28: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cbb29: { // 0x6cbb29: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006cbb2a: { // 0x6cbb2a: 8b2d947caa00 MOV EBP,dword ptr [0x00aa7c94]
    s.bp = m.r32((0x00aa7c94u));
  }
  L006cbb30: { // 0x6cbb30: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cbb31: { // 0x6cbb31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cbb33: { // 0x6cbb33: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cbb34: { // 0x6cbb34: 8b3d987caa00 MOV EDI,dword ptr [0x00aa7c98]
    s.di = m.r32((0x00aa7c98u));
  }
  L006cbb3a: { // 0x6cbb3a: 8b8e28020000 MOV ECX,dword ptr [ESI + 0x228]
    s.cx = m.r32((s.si+0x00000228u));
  }
  L006cbb40: { // 0x6cbb40: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L006cbb44: { // 0x6cbb44: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006cbb46: { // 0x6cbb46: 0f844d010000 JZ 0x006cbc99
    if(integer::condition("JZ",flags)) goto L006cbc99;
  }
  L006cbb4c: { // 0x6cbb4c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006cbb4e: { // 0x6cbb4e: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L006cbb52: { // 0x6cbb52: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cbb53: { // 0x6cbb53: ff5258 CALL dword ptr [EDX + 0x58]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000058u)),7125846u); flags=s.arithmetic_flags;
  }
  L006cbb56: { // 0x6cbb56: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006cbb58: { // 0x6cbb58: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L006cbb5c: { // 0x6cbb5c: 8b8e28020000 MOV ECX,dword ptr [ESI + 0x228]
    s.cx = m.r32((s.si+0x00000228u));
  }
  L006cbb62: { // 0x6cbb62: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L006cbb65: { // 0x6cbb65: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006cbb67: { // 0x6cbb67: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L006cbb6a: { // 0x6cbb6a: 896c2438 MOV dword ptr [ESP + 0x38],EBP
    m.w32((f.sp+0x00000038u), s.bp);
  }
  L006cbb6e: { // 0x6cbb6e: 0f8425010000 JZ 0x006cbc99
    if(integer::condition("JZ",flags)) goto L006cbc99;
  }
  L006cbb74: { // 0x6cbb74: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006cbb76: { // 0x6cbb76: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7125881u); flags=s.arithmetic_flags;
  }
  L006cbb79: { // 0x6cbb79: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006cbb7c: { // 0x6cbb7c: 0f8517010000 JNZ 0x006cbc99
    if(integer::condition("JNZ",flags)) goto L006cbc99;
  }
  L006cbb82: { // 0x6cbb82: 8b9e28020000 MOV EBX,dword ptr [ESI + 0x228]
    s.bx = m.r32((s.si+0x00000228u));
  }
  L006cbb88: { // 0x6cbb88: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006cbb8a: { // 0x6cbb8a: 0f8409010000 JZ 0x006cbc99
    if(integer::condition("JZ",flags)) goto L006cbc99;
  }
  L006cbb90: { // 0x6cbb90: 8b8364050000 MOV EAX,dword ptr [EBX + 0x564]
    s.ax = m.r32((s.bx+0x00000564u));
  }
  L006cbb96: { // 0x6cbb96: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cbb98: { // 0x6cbb98: 750a JNZ 0x006cbba4
    if(integer::condition("JNZ",flags)) goto L006cbba4;
  }
  L006cbb9a: { // 0x6cbb9a: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L006cbb9f: { // 0x6cbb9f: e8cc560b00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,7125924u); flags=s.arithmetic_flags;
  }
  L006cbba4: { // 0x6cbba4: 8b8364050000 MOV EAX,dword ptr [EBX + 0x564]
    s.ax = m.r32((s.bx+0x00000564u));
  }
  L006cbbaa: { // 0x6cbbaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cbbab: { // 0x6cbbab: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006cbbad: { // 0x6cbbad: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),7125936u); flags=s.arithmetic_flags;
  }
  L006cbbb0: { // 0x6cbbb0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbbb2: { // 0x6cbbb2: 0f84e1000000 JZ 0x006cbc99
    if(integer::condition("JZ",flags)) goto L006cbc99;
  }
  L006cbbb8: { // 0x6cbbb8: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L006cbbba: { // 0x6cbbba: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006cbbbc: { // 0x6cbbbc: ff92bc040000 CALL dword ptr [EDX + 0x4bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000004bcu)),7125954u); flags=s.arithmetic_flags;
  }
  L006cbbc2: { // 0x6cbbc2: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006cbbc6: { // 0x6cbbc6: 8b8628020000 MOV EAX,dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  L006cbbcc: { // 0x6cbbcc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cbbcd: { // 0x6cbbcd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cbbcf: { // 0x6cbbcf: e8bc16f0ff CALL 0x005cd290
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd290u,7125972u); flags=s.arithmetic_flags;
  }
  L006cbbd4: { // 0x6cbbd4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cbbd6: { // 0x6cbbd6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cbbd8: { // 0x6cbbd8: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006cbbdc: { // 0x6cbbdc: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7125986u); flags=s.arithmetic_flags;
  }
  L006cbbe2: { // 0x6cbbe2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cbbe4: { // 0x6cbbe4: 0f84af000000 JZ 0x006cbc99
    if(integer::condition("JZ",flags)) goto L006cbc99;
  }
  L006cbbea: { // 0x6cbbea: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006cbbec: { // 0x6cbbec: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006cbbee: { // 0x6cbbee: 0f84a5000000 JZ 0x006cbc99
    if(integer::condition("JZ",flags)) goto L006cbc99;
  }
  L006cbbf4: { // 0x6cbbf4: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cbbf8: { // 0x6cbbf8: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006cbbfc: { // 0x6cbbfc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cbbfd: { // 0x6cbbfd: dd5c2424 FSTP double ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006cbc01: { // 0x6cbc01: e82acf0500 CALL 0x00728b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00728b30u,7126022u); flags=s.arithmetic_flags;
  }
  L006cbc06: { // 0x6cbc06: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006cbc0a: { // 0x6cbc0a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cbc0e: { // 0x6cbc0e: dc0dd07e7900 FMUL double ptr [0x00797ed0]
    const auto address=(0x00797ed0u);
    s.fp.multiply64(read64(m,address));
  }
  L006cbc14: { // 0x6cbc14: dc7c2420 FDIVR double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    reverse_divide64(s.fp,read64(m,address));
  }
  L006cbc18: { // 0x6cbc18: da4c2418 FIMUL dword ptr [ESP + 0x18]
    const auto operand=m.r32((f.sp+0x00000018u));
    ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" : [host]"=m"(host.bytes),[guest]"+m"(s.fp.image.bytes) : [operand]"m"(operand) : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
  }
  L006cbc1c: { // 0x6cbc1c: e82fee0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7126049u); flags=s.arithmetic_flags;
  }
  L006cbc21: { // 0x6cbc21: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006cbc25: { // 0x6cbc25: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006cbc29: { // 0x6cbc29: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cbc2a: { // 0x6cbc2a: 8d8be0020000 LEA ECX,[EBX + 0x2e0]
    s.cx = (s.bx+0x000002e0u);
  }
  L006cbc30: { // 0x6cbc30: e81bccdeff CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,7126069u); flags=s.arithmetic_flags;
  }
  L006cbc35: { // 0x6cbc35: 0fbf10 MOVSX EDX,word ptr [EAX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L006cbc38: { // 0x6cbc38: 81eaff3f0000 SUB EDX,0x3fff
    s.dx = integer::sub(s.dx,0x00003fffu,32,flags);
  }
  L006cbc3e: { // 0x6cbc3e: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006cbc42: { // 0x6cbc42: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cbc46: { // 0x6cbc46: dc0d20667800 FMUL double ptr [0x00786620]
    const auto address=(0x00786620u);
    s.fp.multiply64(read64(m,address));
  }
  L006cbc4c: { // 0x6cbc4c: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006cbc50: { // 0x6cbc50: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cbc54: { // 0x6cbc54: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L006cbc58: { // 0x6cbc58: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L006cbc5c: { // 0x6cbc5c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cbc5d: { // 0x6cbc5d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cbc5e: { // 0x6cbc5e: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006cbc62: { // 0x6cbc62: db442440 FILD dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cbc66: { // 0x6cbc66: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006cbc6a: { // 0x6cbc6a: e881e4deff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,7126127u); flags=s.arithmetic_flags;
  }
  L006cbc6f: { // 0x6cbc6f: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L006cbc73: { // 0x6cbc73: dc6c2430 FSUBR double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L006cbc77: { // 0x6cbc77: e8d4ed0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7126140u); flags=s.arithmetic_flags;
  }
  L006cbc7c: { // 0x6cbc7c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cbc7d: { // 0x6cbc7d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cbc7e: { // 0x6cbc7e: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006cbc80: { // 0x6cbc80: e8bbe4deff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,7126149u); flags=s.arithmetic_flags;
  }
  L006cbc85: { // 0x6cbc85: dc4c2420 FMUL double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply64(read64(m,address));
  }
  L006cbc89: { // 0x6cbc89: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L006cbc8c: { // 0x6cbc8c: da442434 FIADD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006cbc90: { // 0x6cbc90: e8bbed0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7126165u); flags=s.arithmetic_flags;
  }
  L006cbc95: { // 0x6cbc95: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L006cbc99: { // 0x6cbc99: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L006cbc9d: { // 0x6cbc9d: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L006cbca1: { // 0x6cbca1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cbca3: { // 0x6cbca3: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L006cbca5: { // 0x6cbca5: 896904 MOV dword ptr [ECX + 0x4],EBP
    m.w32((s.cx+0x00000004u), s.bp);
  }
  L006cbca8: { // 0x6cbca8: 897908 MOV dword ptr [ECX + 0x8],EDI
    m.w32((s.cx+0x00000008u), s.di);
  }
  L006cbcab: { // 0x6cbcab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cbcac: { // 0x6cbcac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cbcad: { // 0x6cbcad: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006cbcae: { // 0x6cbcae: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cbcaf: { // 0x6cbcaf: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L006cbcb2: { // 0x6cbcb2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006ce320(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce320: { // 0x6ce320: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ce321: { // 0x6ce321: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ce322: { // 0x6ce322: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006ce324: { // 0x6ce324: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ce325: { // 0x6ce325: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L006ce329: { // 0x6ce329: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006ce32b: { // 0x6ce32b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ce32c: { // 0x6ce32c: ff93b8020000 CALL dword ptr [EBX + 0x2b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x000002b8u)),7136050u); flags=s.arithmetic_flags;
  }
  L006ce332: { // 0x6ce332: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ce333: { // 0x6ce333: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ce335: { // 0x6ce335: ff939c030000 CALL dword ptr [EBX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x0000039cu)),7136059u); flags=s.arithmetic_flags;
  }
  L006ce33b: { // 0x6ce33b: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L006ce33d: { // 0x6ce33d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ce33f: { // 0x6ce33f: 0f8497000000 JZ 0x006ce3dc
    if(integer::condition("JZ",flags)) goto L006ce3dc;
  }
  L006ce345: { // 0x6ce345: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006ce347: { // 0x6ce347: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ce349: { // 0x6ce349: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7136076u); flags=s.arithmetic_flags;
  }
  L006ce34c: { // 0x6ce34c: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L006ce34f: { // 0x6ce34f: 7522 JNZ 0x006ce373
    if(integer::condition("JNZ",flags)) goto L006ce373;
  }
  L006ce351: { // 0x6ce351: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006ce357: { // 0x6ce357: 8a812d140000 MOV AL,byte ptr [ECX + 0x142d]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000142du)));
  }
  L006ce35d: { // 0x6ce35d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce35f: { // 0x6ce35f: 750a JNZ 0x006ce36b
    if(integer::condition("JNZ",flags)) goto L006ce36b;
  }
  L006ce361: { // 0x6ce361: 8a8614010000 MOV AL,byte ptr [ESI + 0x114]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000114u)));
  }
  L006ce367: { // 0x6ce367: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce369: { // 0x6ce369: 7471 JZ 0x006ce3dc
    if(integer::condition("JZ",flags)) goto L006ce3dc;
  }
  L006ce36b: { // 0x6ce36b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce36c: { // 0x6ce36c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce36d: { // 0x6ce36d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006ce36f: { // 0x6ce36f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ce370: { // 0x6ce370: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ce373: { // 0x6ce373: 8a8614010000 MOV AL,byte ptr [ESI + 0x114]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000114u)));
  }
  L006ce379: { // 0x6ce379: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce37b: { // 0x6ce37b: 745f JZ 0x006ce3dc
    if(integer::condition("JZ",flags)) goto L006ce3dc;
  }
  L006ce37d: { // 0x6ce37d: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006ce37f: { // 0x6ce37f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ce381: { // 0x6ce381: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7136132u); flags=s.arithmetic_flags;
  }
  L006ce384: { // 0x6ce384: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L006ce387: { // 0x6ce387: 7523 JNZ 0x006ce3ac
    if(integer::condition("JNZ",flags)) goto L006ce3ac;
  }
  L006ce389: { // 0x6ce389: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L006ce38c: { // 0x6ce38c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006ce38f: { // 0x6ce38f: 741b JZ 0x006ce3ac
    if(integer::condition("JZ",flags)) goto L006ce3ac;
  }
  L006ce391: { // 0x6ce391: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L006ce397: { // 0x6ce397: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006ce39a: { // 0x6ce39a: 8a8285020000 MOV AL,byte ptr [EDX + 0x285]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000285u)));
  }
  L006ce3a0: { // 0x6ce3a0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce3a2: { // 0x6ce3a2: 7408 JZ 0x006ce3ac
    if(integer::condition("JZ",flags)) goto L006ce3ac;
  }
  L006ce3a4: { // 0x6ce3a4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce3a5: { // 0x6ce3a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce3a6: { // 0x6ce3a6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006ce3a8: { // 0x6ce3a8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ce3a9: { // 0x6ce3a9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ce3ac: { // 0x6ce3ac: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006ce3ae: { // 0x6ce3ae: 742c JZ 0x006ce3dc
    if(integer::condition("JZ",flags)) goto L006ce3dc;
  }
  L006ce3b0: { // 0x6ce3b0: f6471402 TEST byte ptr [EDI + 0x14],0x2
    (void)integer::logical((m.r8((s.di+0x00000014u)))&(0x00000002u),8,flags);
  }
  L006ce3b4: { // 0x6ce3b4: 7426 JZ 0x006ce3dc
    if(integer::condition("JZ",flags)) goto L006ce3dc;
  }
  L006ce3b6: { // 0x6ce3b6: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006ce3b8: { // 0x6ce3b8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ce3ba: { // 0x6ce3ba: ff90c0000000 CALL dword ptr [EAX + 0xc0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000c0u)),7136192u); flags=s.arithmetic_flags;
  }
  L006ce3c0: { // 0x6ce3c0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce3c2: { // 0x6ce3c2: 7418 JZ 0x006ce3dc
    if(integer::condition("JZ",flags)) goto L006ce3dc;
  }
  L006ce3c4: { // 0x6ce3c4: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006ce3c6: { // 0x6ce3c6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ce3c8: { // 0x6ce3c8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ce3ca: { // 0x6ce3ca: ff92cc000000 CALL dword ptr [EDX + 0xcc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000ccu)),7136208u); flags=s.arithmetic_flags;
  }
  L006ce3d0: { // 0x6ce3d0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ce3d2: { // 0x6ce3d2: 7508 JNZ 0x006ce3dc
    if(integer::condition("JNZ",flags)) goto L006ce3dc;
  }
  L006ce3d4: { // 0x6ce3d4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce3d5: { // 0x6ce3d5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce3d6: { // 0x6ce3d6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006ce3d8: { // 0x6ce3d8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ce3d9: { // 0x6ce3d9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ce3dc: { // 0x6ce3dc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce3dd: { // 0x6ce3dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce3de: { // 0x6ce3de: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006ce3e0: { // 0x6ce3e0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ce3e1: { // 0x6ce3e1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
