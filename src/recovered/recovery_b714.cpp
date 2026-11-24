#include "recovered/recovery_b714_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b714 {
namespace {
void f_0022e4b0(Memory&,State&,Frame&,const Operations&);
void f_00191570(Memory&,State&,Frame&,const Operations&);
void f_00191bb0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_002cc350(Memory&,State&,Frame&,const Operations&);
void f_00307f60(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_0007bec0(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022e4b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062e4b0: { // 0x62e4b0: 8b91d0000000 MOV EDX, dword ptr [ECX + 0xd0]
    s.dx = m.r32((s.cx+0x000000d0u));
  }
  L0062e4b6: { // 0x62e4b6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062e4b8: { // 0x62e4b8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0062e4ba: { // 0x62e4ba: 7e13 JLE 0x62e4cf
    if(integer::condition("JLE",flags)) goto L0062e4cf;
  }
  L0062e4bc: { // 0x62e4bc: 8b89cc000000 MOV ECX, dword ptr [ECX + 0xcc]
    s.cx = m.r32((s.cx+0x000000ccu));
  }
  L0062e4c2: { // 0x62e4c2: 833900 CMP dword ptr [ECX], 0
    (void)integer::sub(m.r32((s.cx)),0u,32,flags);
  }
  L0062e4c5: { // 0x62e4c5: 750b JNZ 0x62e4d2
    if(integer::condition("JNZ",flags)) goto L0062e4d2;
  }
  L0062e4c7: { // 0x62e4c7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062e4c8: { // 0x62e4c8: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L0062e4cb: { // 0x62e4cb: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0062e4cd: { // 0x62e4cd: 7cf3 JL 0x62e4c2
    if(integer::condition("JL",flags)) goto L0062e4c2;
  }
  L0062e4cf: { // 0x62e4cf: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0062e4d1: { // 0x62e4d1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062e4d2: { // 0x62e4d2: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0062e4d4: { // 0x62e4d4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591570: { // 0x591570: 8b8198000000 MOV EAX, dword ptr [ECX + 0x98]
    s.ax = m.r32((s.cx+0x00000098u));
  }
  L00591576: { // 0x591576: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00591579: { // 0x591579: 7506 JNZ 0x591581
    if(integer::condition("JNZ",flags)) goto L00591581;
  }
  L0059157b: { // 0x59157b: 8b81a0000000 MOV EAX, dword ptr [ECX + 0xa0]
    s.ax = m.r32((s.cx+0x000000a0u));
  }
  L00591581: { // 0x591581: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591bb0: { // 0x591bb0: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L00591bb3: { // 0x591bb3: 7503 JNZ 0x591bb8
    if(integer::condition("JNZ",flags)) goto L00591bb8;
  }
  L00591bb5: { // 0x591bb5: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00591bb7: { // 0x591bb7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00591bb8: { // 0x591bb8: c1e105 SHL ECX, 5
    s.cx = integer::shift(s.cx,5u,32,flags,integer::Shift::left);
  }
  L00591bbb: { // 0x591bbb: 8a810680a200 MOV AL, byte ptr [ECX + 0xa28006]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00a28006u)));
  }
  L00591bc1: { // 0x591bc1: c3 RET
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

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("714 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002cc350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc350: { // 0x6cc350: 8a812a030000 MOV AL, byte ptr [ECX + 0x32a]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000032au)));
  }
  L006cc356: { // 0x6cc356: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cc358: { // 0x6cc358: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L006cc35b: { // 0x6cc35b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707f60: { // 0x707f60: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f62: { // 0x707f62: dc1d08577800 FCOMP qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f68: { // 0x707f68: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f6a: { // 0x707f6a: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f6d: { // 0x707f6d: 7515 JNZ 0x707f84
    if(integer::condition("JNZ",flags)) goto L00707f84;
  }
  L00707f6f: { // 0x707f6f: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f71: { // 0x707f71: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f77: { // 0x707f77: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f79: { // 0x707f79: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f7c: { // 0x707f7c: 7406 JZ 0x707f84
    if(integer::condition("JZ",flags)) goto L00707f84;
  }
  L00707f7e: { // 0x707f7e: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707f83: { // 0x707f83: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707f84: { // 0x707f84: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707f86: { // 0x707f86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007bec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047bec0: { // 0x47bec0: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047bec2: { // 0x47bec2: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L0047bec7: { // 0x47bec7: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L0047becb: { // 0x47becb: 8b4078 MOV EAX, dword ptr [EAX + 0x78]
    s.ax = m.r32((s.ax+0x00000078u));
  }
  L0047bece: { // 0x47bece: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0047bed0: { // 0x47bed0: 23c2 AND EAX, EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  L0047bed2: { // 0x47bed2: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0047bed4: { // 0x47bed4: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0047bed6: { // 0x47bed6: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0047bed8: { // 0x47bed8: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX, dword ptr [EDI + 4]
    s.ax = m.r32((s.di+4u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX, 9
    s.dx = integer::shift(s.dx,9u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x5454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX, dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x5454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX, dword ptr [ECX + EDX*4]
    s.dx = m.r32((s.cx+(s.dx * 4u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x5454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc], SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe], AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6481072u:f_0022e4b0(m,s,child,{});break;
case 5838192u:f_00191570(m,s,child,{});break;
case 5839792u:f_00191bb0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 4472336u:f_00043e10(m,s,child,{});break;
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 7127888u:f_002cc350(m,s,child,{});break;
case 7372640u:f_00307f60(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 4701888u:f_0007bec0(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
default:throw std::domain_error("recovery714 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006b5660(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b5660: { // 0x6b5660: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b5661: { // 0x6b5661: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L006b5665: { // 0x6b5665: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b5666: { // 0x6b5666: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006b5668: { // 0x6b5668: 8b86c4040000 MOV EAX,dword ptr [ESI + 0x4c4]
    s.ax = m.r32((s.si+0x000004c4u));
  }
  L006b566e: { // 0x6b566e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b5670: { // 0x6b5670: 7409 JZ 0x006b567b
    if(integer::condition("JZ",flags)) goto L006b567b;
  }
  L006b5672: { // 0x6b5672: 3b7824 CMP EDI,dword ptr [EAX + 0x24]
    (void)integer::sub(s.di,m.r32((s.ax+0x00000024u)),32,flags);
  }
  L006b5675: { // 0x6b5675: 0f84d9000000 JZ 0x006b5754
    if(integer::condition("JZ",flags)) goto L006b5754;
  }
  L006b567b: { // 0x6b567b: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L006b567e: { // 0x6b567e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b5680: { // 0x6b5680: 0f8ece000000 JLE 0x006b5754
    if(integer::condition("JLE",flags)) goto L006b5754;
  }
  L006b5686: { // 0x6b5686: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L006b5689: { // 0x6b5689: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b568b: { // 0x6b568b: 0f84c3000000 JZ 0x006b5754
    if(integer::condition("JZ",flags)) goto L006b5754;
  }
  L006b5691: { // 0x6b5691: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L006b5694: { // 0x6b5694: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b5696: { // 0x6b5696: 0f85b8000000 JNZ 0x006b5754
    if(integer::condition("JNZ",flags)) goto L006b5754;
  }
  L006b569c: { // 0x6b569c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b569e: { // 0x6b569e: e80d8ef7ff CALL 0x0062e4b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4b0u,7034531u); flags=s.arithmetic_flags;
  }
  L006b56a3: { // 0x6b56a3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b56a5: { // 0x6b56a5: 0f85a9000000 JNZ 0x006b5754
    if(integer::condition("JNZ",flags)) goto L006b5754;
  }
  L006b56ab: { // 0x6b56ab: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006b56b1: { // 0x6b56b1: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006b56b5: { // 0x6b56b5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006b56b7: { // 0x6b56b7: 0f8597000000 JNZ 0x006b5754
    if(integer::condition("JNZ",flags)) goto L006b5754;
  }
  L006b56bd: { // 0x6b56bd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b56bf: { // 0x6b56bf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b56c1: { // 0x6b56c1: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),7034567u); flags=s.arithmetic_flags;
  }
  L006b56c7: { // 0x6b56c7: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006b56ca: { // 0x6b56ca: 7415 JZ 0x006b56e1
    if(integer::condition("JZ",flags)) goto L006b56e1;
  }
  L006b56cc: { // 0x6b56cc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b56ce: { // 0x6b56ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b56d0: { // 0x6b56d0: ff906c010000 CALL dword ptr [EAX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),7034582u); flags=s.arithmetic_flags;
  }
  L006b56d6: { // 0x6b56d6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b56d8: { // 0x6b56d8: e8d3c4edff CALL 0x00591bb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00591bb0u,7034589u); flags=s.arithmetic_flags;
  }
  L006b56dd: { // 0x6b56dd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b56df: { // 0x6b56df: 7473 JZ 0x006b5754
    if(integer::condition("JZ",flags)) goto L006b5754;
  }
  L006b56e1: { // 0x6b56e1: 8a8679030000 MOV AL,byte ptr [ESI + 0x379]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000379u)));
  }
  L006b56e7: { // 0x6b56e7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b56e9: { // 0x6b56e9: 750a JNZ 0x006b56f5
    if(integer::condition("JNZ",flags)) goto L006b56f5;
  }
  L006b56eb: { // 0x6b56eb: 8a87a9000000 MOV AL,byte ptr [EDI + 0xa9]
    s.ax = with_al(s.ax, m.r8((s.di+0x000000a9u)));
  }
  L006b56f1: { // 0x6b56f1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b56f3: { // 0x6b56f3: 745f JZ 0x006b5754
    if(integer::condition("JZ",flags)) goto L006b5754;
  }
  L006b56f5: { // 0x6b56f5: 8a867a030000 MOV AL,byte ptr [ESI + 0x37a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000037au)));
  }
  L006b56fb: { // 0x6b56fb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b56fd: { // 0x6b56fd: 750a JNZ 0x006b5709
    if(integer::condition("JNZ",flags)) goto L006b5709;
  }
  L006b56ff: { // 0x6b56ff: 8a87a9000000 MOV AL,byte ptr [EDI + 0xa9]
    s.ax = with_al(s.ax, m.r8((s.di+0x000000a9u)));
  }
  L006b5705: { // 0x6b5705: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b5707: { // 0x6b5707: 754b JNZ 0x006b5754
    if(integer::condition("JNZ",flags)) goto L006b5754;
  }
  L006b5709: { // 0x6b5709: 8b86c4040000 MOV EAX,dword ptr [ESI + 0x4c4]
    s.ax = m.r32((s.si+0x000004c4u));
  }
  L006b570f: { // 0x6b570f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b5711: { // 0x6b5711: 7413 JZ 0x006b5726
    if(integer::condition("JZ",flags)) goto L006b5726;
  }
  L006b5713: { // 0x6b5713: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L006b5716: { // 0x6b5716: 8b87b4000000 MOV EAX,dword ptr [EDI + 0xb4]
    s.ax = m.r32((s.di+0x000000b4u));
  }
  L006b571c: { // 0x6b571c: 8b91b4000000 MOV EDX,dword ptr [ECX + 0xb4]
    s.dx = m.r32((s.cx+0x000000b4u));
  }
  L006b5722: { // 0x6b5722: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006b5724: { // 0x6b5724: 7d2e JGE 0x006b5754
    if(integer::condition("JGE",flags)) goto L006b5754;
  }
  L006b5726: { // 0x6b5726: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b5728: { // 0x6b5728: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b572a: { // 0x6b572a: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7034669u); flags=s.arithmetic_flags;
  }
  L006b572d: { // 0x6b572d: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L006b5730: { // 0x6b5730: 751b JNZ 0x006b574d
    if(integer::condition("JNZ",flags)) goto L006b574d;
  }
  L006b5732: { // 0x6b5732: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b5734: { // 0x6b5734: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b5736: { // 0x6b5736: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b5738: { // 0x6b5738: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7034686u); flags=s.arithmetic_flags;
  }
  L006b573e: { // 0x6b573e: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b5741: { // 0x6b5741: 740a JZ 0x006b574d
    if(integer::condition("JZ",flags)) goto L006b574d;
  }
  L006b5743: { // 0x6b5743: 8b8654020000 MOV EAX,dword ptr [ESI + 0x254]
    s.ax = m.r32((s.si+0x00000254u));
  }
  L006b5749: { // 0x6b5749: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b574b: { // 0x6b574b: 7407 JZ 0x006b5754
    if(integer::condition("JZ",flags)) goto L006b5754;
  }
  L006b574d: { // 0x6b574d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b574e: { // 0x6b574e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006b5750: { // 0x6b5750: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b5751: { // 0x6b5751: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b5754: { // 0x6b5754: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b5755: { // 0x6b5755: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006b5757: { // 0x6b5757: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b5758: { // 0x6b5758: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006b6d40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6d40: { // 0x6b6d40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b6d41: { // 0x6b6d41: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L006b6d45: { // 0x6b6d45: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6d46: { // 0x6b6d46: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b6d47: { // 0x6b6d47: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006b6d49: { // 0x6b6d49: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L006b6d4c: { // 0x6b6d4c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b6d4e: { // 0x6b6d4e: 0f85e9000000 JNZ 0x006b6e3d
    if(integer::condition("JNZ",flags)) goto L006b6e3d;
  }
  L006b6d54: { // 0x6b6d54: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6d56: { // 0x6b6d56: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006b6d58: { // 0x6b6d58: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7040350u); flags=s.arithmetic_flags;
  }
  L006b6d5e: { // 0x6b6d5e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b6d60: { // 0x6b6d60: e88bde0100 CALL 0x006d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7040357u); flags=s.arithmetic_flags;
  }
  L006b6d65: { // 0x6b6d65: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6d67: { // 0x6b6d67: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6d69: { // 0x6b6d69: 7445 JZ 0x006b6db0
    if(integer::condition("JZ",flags)) goto L006b6db0;
  }
  L006b6d6b: { // 0x6b6d6b: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006b6d71: { // 0x6b6d71: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6d73: { // 0x6b6d73: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b6d74: { // 0x6b6d74: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040378u); flags=s.arithmetic_flags;
  }
  L006b6d7a: { // 0x6b6d7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6d7c: { // 0x6b6d7c: 7508 JNZ 0x006b6d86
    if(integer::condition("JNZ",flags)) goto L006b6d86;
  }
  L006b6d7e: { // 0x6b6d7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6d7f: { // 0x6b6d7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6d80: { // 0x6b6d80: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b6d82: { // 0x6b6d82: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6d83: { // 0x6b6d83: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6d86: { // 0x6b6d86: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b6d88: { // 0x6b6d88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6d8a: { // 0x6b6d8a: 7506 JNZ 0x006b6d92
    if(integer::condition("JNZ",flags)) goto L006b6d92;
  }
  L006b6d8c: { // 0x6b6d8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6d8d: { // 0x6b6d8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6d8e: { // 0x6b6d8e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6d8f: { // 0x6b6d8f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6d92: { // 0x6b6d92: 8bb8a4000000 MOV EDI,dword ptr [EAX + 0xa4]
    s.di = m.r32((s.ax+0x000000a4u));
  }
  L006b6d98: { // 0x6b6d98: 8b8898000000 MOV ECX,dword ptr [EAX + 0x98]
    s.cx = m.r32((s.ax+0x00000098u));
  }
  L006b6d9e: { // 0x6b6d9e: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L006b6da0: { // 0x6b6da0: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006b6da5: { // 0x6b6da5: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006b6da7: { // 0x6b6da7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6da8: { // 0x6b6da8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006b6da9: { // 0x6b6da9: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006b6dab: { // 0x6b6dab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6dac: { // 0x6b6dac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6dad: { // 0x6b6dad: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6db0: { // 0x6b6db0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b6db2: { // 0x6b6db2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6db4: { // 0x6b6db4: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040442u); flags=s.arithmetic_flags;
  }
  L006b6dba: { // 0x6b6dba: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b6dbd: { // 0x6b6dbd: 742d JZ 0x006b6dec
    if(integer::condition("JZ",flags)) goto L006b6dec;
  }
  L006b6dbf: { // 0x6b6dbf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6dc1: { // 0x6b6dc1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b6dc3: { // 0x6b6dc3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6dc5: { // 0x6b6dc5: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7040459u); flags=s.arithmetic_flags;
  }
  L006b6dcb: { // 0x6b6dcb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6dcd: { // 0x6b6dcd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6dcf: { // 0x6b6dcf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b6dd1: { // 0x6b6dd1: 8bb9a4000000 MOV EDI,dword ptr [ECX + 0xa4]
    s.di = m.r32((s.cx+0x000000a4u));
  }
  L006b6dd7: { // 0x6b6dd7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6dd9: { // 0x6b6dd9: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040479u); flags=s.arithmetic_flags;
  }
  L006b6ddf: { // 0x6b6ddf: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b6de1: { // 0x6b6de1: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006b6de6: { // 0x6b6de6: 03b898000000 ADD EDI,dword ptr [EAX + 0x98]
    s.di = integer::add(s.di,m.r32((s.ax+0x00000098u)),32,flags);
  }
  L006b6dec: { // 0x6b6dec: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6dee: { // 0x6b6dee: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b6df0: { // 0x6b6df0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6df2: { // 0x6b6df2: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040504u); flags=s.arithmetic_flags;
  }
  L006b6df8: { // 0x6b6df8: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b6dfb: { // 0x6b6dfb: 742d JZ 0x006b6e2a
    if(integer::condition("JZ",flags)) goto L006b6e2a;
  }
  L006b6dfd: { // 0x6b6dfd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6dff: { // 0x6b6dff: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b6e01: { // 0x6b6e01: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6e03: { // 0x6b6e03: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7040521u); flags=s.arithmetic_flags;
  }
  L006b6e09: { // 0x6b6e09: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6e0b: { // 0x6b6e0b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b6e0d: { // 0x6b6e0d: 8b91a4000000 MOV EDX,dword ptr [ECX + 0xa4]
    s.dx = m.r32((s.cx+0x000000a4u));
  }
  L006b6e13: { // 0x6b6e13: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6e15: { // 0x6b6e15: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L006b6e17: { // 0x6b6e17: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6e19: { // 0x6b6e19: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040543u); flags=s.arithmetic_flags;
  }
  L006b6e1f: { // 0x6b6e1f: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b6e21: { // 0x6b6e21: 8b8898000000 MOV ECX,dword ptr [EAX + 0x98]
    s.cx = m.r32((s.ax+0x00000098u));
  }
  L006b6e27: { // 0x6b6e27: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L006b6e29: { // 0x6b6e29: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006b6e2a: { // 0x6b6e2a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006b6e2c: { // 0x6b6e2c: 0f8e4cffffff JLE 0x006b6d7e
    if(integer::condition("JLE",flags)) goto L006b6d7e;
  }
  L006b6e32: { // 0x6b6e32: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006b6e34: { // 0x6b6e34: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6e35: { // 0x6b6e35: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006b6e36: { // 0x6b6e36: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006b6e38: { // 0x6b6e38: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6e39: { // 0x6b6e39: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6e3a: { // 0x6b6e3a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b6e3d: { // 0x6b6e3d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6e3f: { // 0x6b6e3f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b6e40: { // 0x6b6e40: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6e42: { // 0x6b6e42: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040584u); flags=s.arithmetic_flags;
  }
  L006b6e48: { // 0x6b6e48: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b6e4b: { // 0x6b6e4b: 7426 JZ 0x006b6e73
    if(integer::condition("JZ",flags)) goto L006b6e73;
  }
  L006b6e4d: { // 0x6b6e4d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6e4f: { // 0x6b6e4f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b6e50: { // 0x6b6e50: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6e52: { // 0x6b6e52: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7040600u); flags=s.arithmetic_flags;
  }
  L006b6e58: { // 0x6b6e58: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6e5a: { // 0x6b6e5a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6e5c: { // 0x6b6e5c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b6e5d: { // 0x6b6e5d: 8bb9a4000000 MOV EDI,dword ptr [ECX + 0xa4]
    s.di = m.r32((s.cx+0x000000a4u));
  }
  L006b6e63: { // 0x6b6e63: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b6e65: { // 0x6b6e65: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040619u); flags=s.arithmetic_flags;
  }
  L006b6e6b: { // 0x6b6e6b: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b6e6d: { // 0x6b6e6d: 03b898000000 ADD EDI,dword ptr [EAX + 0x98]
    s.di = integer::add(s.di,m.r32((s.ax+0x00000098u)),32,flags);
  }
  L006b6e73: { // 0x6b6e73: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006b6e75: { // 0x6b6e75: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6e76: { // 0x6b6e76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6e77: { // 0x6b6e77: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6e78: { // 0x6b6e78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006be4d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006be4d0: { // 0x6be4d0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006be4d3: { // 0x6be4d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006be4d4: { // 0x6be4d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006be4d5: { // 0x6be4d5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006be4d7: { // 0x6be4d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006be4d8: { // 0x6be4d8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006be4da: { // 0x6be4da: ff9068020000 CALL dword ptr [EAX + 0x268]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000268u)),7070944u); flags=s.arithmetic_flags;
  }
  L006be4e0: { // 0x6be4e0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be4e2: { // 0x6be4e2: 750a JNZ 0x006be4ee
    if(integer::condition("JNZ",flags)) goto L006be4ee;
  }
  L006be4e4: { // 0x6be4e4: 8a862a030000 MOV AL,byte ptr [ESI + 0x32a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032au)));
  }
  L006be4ea: { // 0x6be4ea: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be4ec: { // 0x6be4ec: 743c JZ 0x006be52a
    if(integer::condition("JZ",flags)) goto L006be52a;
  }
  L006be4ee: { // 0x6be4ee: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006be4f0: { // 0x6be4f0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be4f2: { // 0x6be4f2: ff9224030000 CALL dword ptr [EDX + 0x324]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000324u)),7070968u); flags=s.arithmetic_flags;
  }
  L006be4f8: { // 0x6be4f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be4fa: { // 0x6be4fa: 752e JNZ 0x006be52a
    if(integer::condition("JNZ",flags)) goto L006be52a;
  }
  L006be4fc: { // 0x6be4fc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006be4fe: { // 0x6be4fe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be500: { // 0x6be500: ff9028030000 CALL dword ptr [EAX + 0x328]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000328u)),7070982u); flags=s.arithmetic_flags;
  }
  L006be506: { // 0x6be506: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be508: { // 0x6be508: 7520 JNZ 0x006be52a
    if(integer::condition("JNZ",flags)) goto L006be52a;
  }
  L006be50a: { // 0x6be50a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006be50c: { // 0x6be50c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be50e: { // 0x6be50e: ff92bc010000 CALL dword ptr [EDX + 0x1bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001bcu)),7070996u); flags=s.arithmetic_flags;
  }
  L006be514: { // 0x6be514: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be516: { // 0x6be516: 7512 JNZ 0x006be52a
    if(integer::condition("JNZ",flags)) goto L006be52a;
  }
  L006be518: { // 0x6be518: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006be51a: { // 0x6be51a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be51c: { // 0x6be51c: ff90c0010000 CALL dword ptr [EAX + 0x1c0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001c0u)),7071010u); flags=s.arithmetic_flags;
  }
  L006be522: { // 0x6be522: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be524: { // 0x6be524: 0f84ca000000 JZ 0x006be5f4
    if(integer::condition("JZ",flags)) goto L006be5f4;
  }
  L006be52a: { // 0x6be52a: 8d9e18010000 LEA EBX,[ESI + 0x118]
    s.bx = (s.si+0x00000118u);
  }
  L006be530: { // 0x6be530: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be532: { // 0x6be532: e8299a0400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7071031u); flags=s.arithmetic_flags;
  }
  L006be537: { // 0x6be537: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be539: { // 0x6be539: 750b JNZ 0x006be546
    if(integer::condition("JNZ",flags)) goto L006be546;
  }
  L006be53b: { // 0x6be53b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be53d: { // 0x6be53d: e89e9a0400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7071042u); flags=s.arithmetic_flags;
  }
  L006be542: { // 0x6be542: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be544: { // 0x6be544: 7444 JZ 0x006be58a
    if(integer::condition("JZ",flags)) goto L006be58a;
  }
  L006be546: { // 0x6be546: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006be548: { // 0x6be548: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be54a: { // 0x6be54a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7071056u); flags=s.arithmetic_flags;
  }
  L006be550: { // 0x6be550: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be552: { // 0x6be552: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006be554: { // 0x6be554: e8079a0400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7071065u); flags=s.arithmetic_flags;
  }
  L006be559: { // 0x6be559: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be55b: { // 0x6be55b: 740e JZ 0x006be56b
    if(integer::condition("JZ",flags)) goto L006be56b;
  }
  L006be55d: { // 0x6be55d: 8a8772020000 MOV AL,byte ptr [EDI + 0x272]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000272u)));
  }
  L006be563: { // 0x6be563: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be565: { // 0x6be565: 0f8589000000 JNZ 0x006be5f4
    if(integer::condition("JNZ",flags)) goto L006be5f4;
  }
  L006be56b: { // 0x6be56b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be56d: { // 0x6be56d: e86e9a0400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7071090u); flags=s.arithmetic_flags;
  }
  L006be572: { // 0x6be572: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be574: { // 0x6be574: 7414 JZ 0x006be58a
    if(integer::condition("JZ",flags)) goto L006be58a;
  }
  L006be576: { // 0x6be576: 8a8772020000 MOV AL,byte ptr [EDI + 0x272]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000272u)));
  }
  L006be57c: { // 0x6be57c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be57e: { // 0x6be57e: 7574 JNZ 0x006be5f4
    if(integer::condition("JNZ",flags)) goto L006be5f4;
  }
  L006be580: { // 0x6be580: 8a8784020000 MOV AL,byte ptr [EDI + 0x284]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000284u)));
  }
  L006be586: { // 0x6be586: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be588: { // 0x6be588: 756a JNZ 0x006be5f4
    if(integer::condition("JNZ",flags)) goto L006be5f4;
  }
  L006be58a: { // 0x6be58a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006be58c: { // 0x6be58c: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006be590: { // 0x6be590: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006be591: { // 0x6be591: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be593: { // 0x6be593: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),7071126u); flags=s.arithmetic_flags;
  }
  L006be596: { // 0x6be596: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006be598: { // 0x6be598: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006be59a: { // 0x6be59a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006be59b: { // 0x6be59b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006be5a1: { // 0x6be5a1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006be5a3: { // 0x6be5a3: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006be5a6: { // 0x6be5a6: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  L006be5ab: { // 0x6be5ab: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006be5ae: { // 0x6be5ae: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006be5af: { // 0x6be5af: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006be5b5: { // 0x6be5b5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006be5b7: { // 0x6be5b7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006be5ba: { // 0x6be5ba: 668944240e MOV word ptr [ESP + 0xe],AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L006be5bf: { // 0x6be5bf: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L006be5c3: { // 0x6be5c3: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006be5c9: { // 0x6be5c9: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006be5cd: { // 0x6be5cd: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L006be5d1: { // 0x6be5d1: 8b4830 MOV ECX,dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L006be5d4: { // 0x6be5d4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006be5d5: { // 0x6be5d5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006be5d6: { // 0x6be5d6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006be5db: { // 0x6be5db: e8206fe8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7071200u); flags=s.arithmetic_flags;
  }
  L006be5e0: { // 0x6be5e0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006be5e2: { // 0x6be5e2: e8d9d8dbff CALL 0x0047bec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047bec0u,7071207u); flags=s.arithmetic_flags;
  }
  L006be5e7: { // 0x6be5e7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be5e9: { // 0x6be5e9: 7509 JNZ 0x006be5f4
    if(integer::condition("JNZ",flags)) goto L006be5f4;
  }
  L006be5eb: { // 0x6be5eb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be5ec: { // 0x6be5ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be5ed: { // 0x6be5ed: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006be5ef: { // 0x6be5ef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be5f0: { // 0x6be5f0: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be5f3: { // 0x6be5f3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006be5f4: { // 0x6be5f4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be5f5: { // 0x6be5f5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be5f6: { // 0x6be5f6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be5f8: { // 0x6be5f8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be5f9: { // 0x6be5f9: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be5fc: { // 0x6be5fc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006bf0c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006bf0c0: { // 0x6bf0c0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006bf0c3: { // 0x6bf0c3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf0c4: { // 0x6bf0c4: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L006bf0c8: { // 0x6bf0c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006bf0c9: { // 0x6bf0c9: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006bf0cb: { // 0x6bf0cb: 8b8728020000 MOV EAX,dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L006bf0d1: { // 0x6bf0d1: c6870404000000 MOV byte ptr [EDI + 0x404],0x0
    m.w8((s.di+0x00000404u), 0x00000000u);
  }
  L006bf0d8: { // 0x6bf0d8: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006bf0da: { // 0x6bf0da: 0f84e2000000 JZ 0x006bf1c2
    if(integer::condition("JZ",flags)) goto L006bf1c2;
  }
  L006bf0e0: { // 0x6bf0e0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006bf0e2: { // 0x6bf0e2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006bf0e3: { // 0x6bf0e3: 747b JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf0e5: { // 0x6bf0e5: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L006bf0e7: { // 0x6bf0e7: 7531 JNZ 0x006bf11a
    if(integer::condition("JNZ",flags)) goto L006bf11a;
  }
  L006bf0e9: { // 0x6bf0e9: 8d8788000000 LEA EAX,[EDI + 0x88]
    s.ax = (s.di+0x00000088u);
  }
  L006bf0ef: { // 0x6bf0ef: 8b8f88000000 MOV ECX,dword ptr [EDI + 0x88]
    s.cx = m.r32((s.di+0x00000088u));
  }
  L006bf0f5: { // 0x6bf0f5: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006bf0f9: { // 0x6bf0f9: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006bf0fd: { // 0x6bf0fd: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006bf100: { // 0x6bf100: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006bf101: { // 0x6bf101: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006bf106: { // 0x6bf106: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006bf10a: { // 0x6bf10a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006bf10d: { // 0x6bf10d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006bf111: { // 0x6bf111: e87a63e8ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,7074070u); flags=s.arithmetic_flags;
  }
  L006bf116: { // 0x6bf116: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006bf118: { // 0x6bf118: eb48 JMP 0x006bf162
    goto L006bf162;
  }
  L006bf11a: { // 0x6bf11a: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L006bf11d: { // 0x6bf11d: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L006bf11f: { // 0x6bf11f: 7441 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf121: { // 0x6bf121: 8a4e7d MOV CL,byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L006bf124: { // 0x6bf124: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006bf126: { // 0x6bf126: 7438 JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf128: { // 0x6bf128: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L006bf12b: { // 0x6bf12b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006bf12d: { // 0x6bf12d: 7431 JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf12f: { // 0x6bf12f: c0e802 SHR AL,0x2
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L006bf132: { // 0x6bf132: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L006bf134: { // 0x6bf134: 8844241c MOV byte ptr [ESP + 0x1c],AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L006bf138: { // 0x6bf138: 7428 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf13a: { // 0x6bf13a: 8a8625030000 MOV AL,byte ptr [ESI + 0x325]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000325u)));
  }
  L006bf140: { // 0x6bf140: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L006bf142: { // 0x6bf142: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf144: { // 0x6bf144: 7402 JZ 0x006bf148
    if(integer::condition("JZ",flags)) goto L006bf148;
  }
  L006bf146: { // 0x6bf146: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006bf148: { // 0x6bf148: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L006bf14b: { // 0x6bf14b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bf14d: { // 0x6bf14d: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7074128u); flags=s.arithmetic_flags;
  }
  L006bf150: { // 0x6bf150: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L006bf153: { // 0x6bf153: 750d JNZ 0x006bf162
    if(integer::condition("JNZ",flags)) goto L006bf162;
  }
  L006bf155: { // 0x6bf155: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bf157: { // 0x6bf157: e8549ae4ff CALL 0x00508bb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00508bb0u,7074140u); flags=s.arithmetic_flags;
  }
  L006bf15c: { // 0x6bf15c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf15e: { // 0x6bf15e: 7402 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf160: { // 0x6bf160: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006bf162: { // 0x6bf162: 8b8f38020000 MOV ECX,dword ptr [EDI + 0x238]
    s.cx = m.r32((s.di+0x00000238u));
  }
  L006bf168: { // 0x6bf168: 89b728020000 MOV dword ptr [EDI + 0x228],ESI
    m.w32((s.di+0x00000228u), s.si);
  }
  L006bf16e: { // 0x6bf16e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006bf170: { // 0x6bf170: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bf171: { // 0x6bf171: 740a JZ 0x006bf17d
    if(integer::condition("JZ",flags)) goto L006bf17d;
  }
  L006bf173: { // 0x6bf173: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006bf175: { // 0x6bf175: 7506 JNZ 0x006bf17d
    if(integer::condition("JNZ",flags)) goto L006bf17d;
  }
  L006bf177: { // 0x6bf177: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf178: { // 0x6bf178: e8130afcff CALL 0x0067fb90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0067fb90u,7074173u); flags=s.arithmetic_flags;
  }
  L006bf17d: { // 0x6bf17d: 8b8728020000 MOV EAX,dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L006bf183: { // 0x6bf183: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf185: { // 0x6bf185: 750a JNZ 0x006bf191
    if(integer::condition("JNZ",flags)) goto L006bf191;
  }
  L006bf187: { // 0x6bf187: c7871003000000000000 MOV dword ptr [EDI + 0x310],0x0
    m.w32((s.di+0x00000310u), 0x00000000u);
  }
  L006bf191: { // 0x6bf191: 8b875c020000 MOV EAX,dword ptr [EDI + 0x25c]
    s.ax = m.r32((s.di+0x0000025cu));
  }
  L006bf197: { // 0x6bf197: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf199: { // 0x6bf199: 7427 JZ 0x006bf1c2
    if(integer::condition("JZ",flags)) goto L006bf1c2;
  }
  L006bf19b: { // 0x6bf19b: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006bf19d: { // 0x6bf19d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf19e: { // 0x6bf19e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bf1a0: { // 0x6bf1a0: ff9054030000 CALL dword ptr [EAX + 0x354]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000354u)),7074214u); flags=s.arithmetic_flags;
  }
  L006bf1a6: { // 0x6bf1a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf1a8: { // 0x6bf1a8: 7518 JNZ 0x006bf1c2
    if(integer::condition("JNZ",flags)) goto L006bf1c2;
  }
  L006bf1aa: { // 0x6bf1aa: 8b8f5c020000 MOV ECX,dword ptr [EDI + 0x25c]
    s.cx = m.r32((s.di+0x0000025cu));
  }
  L006bf1b0: { // 0x6bf1b0: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006bf1b2: { // 0x6bf1b2: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),7074232u); flags=s.arithmetic_flags;
  }
  L006bf1b8: { // 0x6bf1b8: c7875c02000000000000 MOV dword ptr [EDI + 0x25c],0x0
    m.w32((s.di+0x0000025cu), 0x00000000u);
  }
  L006bf1c2: { // 0x6bf1c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf1c3: { // 0x6bf1c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf1c4: { // 0x6bf1c4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006bf1c7: { // 0x6bf1c7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
