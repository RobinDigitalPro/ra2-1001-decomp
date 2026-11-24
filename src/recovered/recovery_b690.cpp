#include "recovered/recovery_b690_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b690 {
namespace {
void f_000e4c20(Memory&,State&,Frame&,const Operations&);
void f_002bca10(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_0004d4c0(Memory&,State&,Frame&,const Operations&);
void f_00191570(Memory&,State&,Frame&,const Operations&);
void f_00096890(Memory&,State&,Frame&,const Operations&);
void f_00096930(Memory&,State&,Frame&,const Operations&);
void f_00096910(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000e4c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4c20: { // 0x4e4c20: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e4c21: { // 0x4e4c21: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004e4c23: { // 0x4e4c23: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L004e4c27: { // 0x4e4c27: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4c29: { // 0x4e4c29: 7440 JZ 0x4e4c6b
    if(integer::condition("JZ",flags)) goto L004e4c6b;
  }
  L004e4c2b: { // 0x4e4c2b: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004e4c2d: { // 0x4e4c2d: ff503c CALL dword ptr [EAX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000003cu)),5131312u); flags=s.arithmetic_flags;
  }
  L004e4c30: { // 0x4e4c30: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4c32: { // 0x4e4c32: 7437 JZ 0x4e4c6b
    if(integer::condition("JZ",flags)) goto L004e4c6b;
  }
  L004e4c34: { // 0x4e4c34: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004e4c36: { // 0x4e4c36: 7506 JNZ 0x4e4c3e
    if(integer::condition("JNZ",flags)) goto L004e4c3e;
  }
  L004e4c38: { // 0x4e4c38: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4c3a: { // 0x4e4c3a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e4c3b: { // 0x4e4c3b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4c3e: { // 0x4e4c3e: 8b4030 MOV EAX, dword ptr [EAX + 0x30]
    s.ax = m.r32((s.ax+0x00000030u));
  }
  L004e4c41: { // 0x4e4c41: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e4c44: { // 0x4e4c44: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004e4c46: { // 0x4e4c46: 7506 JNZ 0x4e4c4e
    if(integer::condition("JNZ",flags)) goto L004e4c4e;
  }
  L004e4c48: { // 0x4e4c48: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4c4a: { // 0x4e4c4a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e4c4b: { // 0x4e4c4b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4c4e: { // 0x4e4c4e: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L004e4c51: { // 0x4e4c51: 7418 JZ 0x4e4c6b
    if(integer::condition("JZ",flags)) goto L004e4c6b;
  }
  L004e4c53: { // 0x4e4c53: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e4c58: { // 0x4e4c58: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004e4c5a: { // 0x4e4c5a: 8b8674560000 MOV EAX, dword ptr [ESI + 0x5674]
    s.ax = m.r32((s.si+0x00005674u));
  }
  L004e4c60: { // 0x4e4c60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e4c61: { // 0x4e4c61: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4c63: { // 0x4e4c63: 85c2 TEST EDX, EAX
    (void)integer::logical((s.dx)&(s.ax),32,flags);
  }
  L004e4c65: { // 0x4e4c65: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e4c68: { // 0x4e4c68: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4c6b: { // 0x4e4c6b: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4c6d: { // 0x4e4c6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e4c6e: { // 0x4e4c6e: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002bca10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006bca10: { // 0x6bca10: 8b81b4010000 MOV EAX, dword ptr [ECX + 0x1b4]
    s.ax = m.r32((s.cx+0x000001b4u));
  }
  L006bca16: { // 0x6bca16: c3 RET
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
void f_0004d4c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d4c0: { // 0x44d4c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d4c1: { // 0x44d4c1: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0044d4c3: { // 0x44d4c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d4c4: { // 0x44d4c4: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d4ca: { // 0x44d4ca: 8a8851130000 MOV CL, byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L0044d4d0: { // 0x44d4d0: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d4d2: { // 0x44d4d2: 7505 JNZ 0x44d4d9
    if(integer::condition("JNZ",flags)) goto L0044d4d9;
  }
  L0044d4d4: { // 0x44d4d4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d4d5: { // 0x44d4d5: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0044d4d7: { // 0x44d4d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d4d8: { // 0x44d4d8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0044d4d9: { // 0x44d4d9: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044d4db: { // 0x44d4db: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d4dd: { // 0x44d4dd: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4510947u); flags=s.arithmetic_flags;
  }
  L0044d4e3: { // 0x44d4e3: 83f818 CMP EAX, 0x18
    (void)integer::sub(s.ax,0x00000018u,32,flags);
  }
  L0044d4e6: { // 0x44d4e6: 7550 JNZ 0x44d538
    if(integer::condition("JNZ",flags)) goto L0044d538;
  }
  L0044d4e8: { // 0x44d4e8: 8dbea8020000 LEA EDI, [ESI + 0x2a8]
    s.di = (s.si+0x000002a8u);
  }
  L0044d4ee: { // 0x44d4ee: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d4f0: { // 0x44d4f0: e89b930400 CALL 0x496890
    s.arithmetic_flags=flags; invoke(m,s,f,0x00496890u,4510965u); flags=s.arithmetic_flags;
  }
  L0044d4f5: { // 0x44d4f5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d4f7: { // 0x44d4f7: 753f JNZ 0x44d538
    if(integer::condition("JNZ",flags)) goto L0044d538;
  }
  L0044d4f9: { // 0x44d4f9: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d4fb: { // 0x44d4fb: e830940400 CALL 0x496930
    s.arithmetic_flags=flags; invoke(m,s,f,0x00496930u,4510976u); flags=s.arithmetic_flags;
  }
  L0044d500: { // 0x44d500: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d502: { // 0x44d502: 7534 JNZ 0x44d538
    if(integer::condition("JNZ",flags)) goto L0044d538;
  }
  L0044d504: { // 0x44d504: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d50a: { // 0x44d50a: 8a8851130000 MOV CL, byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L0044d510: { // 0x44d510: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d512: { // 0x44d512: 7505 JNZ 0x44d519
    if(integer::condition("JNZ",flags)) goto L0044d519;
  }
  L0044d514: { // 0x44d514: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d515: { // 0x44d515: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0044d517: { // 0x44d517: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d518: { // 0x44d518: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0044d519: { // 0x44d519: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044d51b: { // 0x44d51b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d51d: { // 0x44d51d: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4511011u); flags=s.arithmetic_flags;
  }
  L0044d523: { // 0x44d523: 83f818 CMP EAX, 0x18
    (void)integer::sub(s.ax,0x00000018u,32,flags);
  }
  L0044d526: { // 0x44d526: 7534 JNZ 0x44d55c
    if(integer::condition("JNZ",flags)) goto L0044d55c;
  }
  L0044d528: { // 0x44d528: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d52a: { // 0x44d52a: e8e1930400 CALL 0x496910
    s.arithmetic_flags=flags; invoke(m,s,f,0x00496910u,4511023u); flags=s.arithmetic_flags;
  }
  L0044d52f: { // 0x44d52f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d531: { // 0x44d531: 7429 JZ 0x44d55c
    if(integer::condition("JZ",flags)) goto L0044d55c;
  }
  L0044d533: { // 0x44d533: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d534: { // 0x44d534: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0044d536: { // 0x44d536: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d537: { // 0x44d537: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0044d538: { // 0x44d538: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044d53a: { // 0x44d53a: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L0044d53c: { // 0x44d53c: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d53e: { // 0x44d53e: ff90d8010000 CALL dword ptr [EAX + 0x1d8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d8u)),4511044u); flags=s.arithmetic_flags;
  }
  L0044d544: { // 0x44d544: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044d546: { // 0x44d546: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044d548: { // 0x44d548: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L0044d54a: { // 0x44d54a: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d54c: { // 0x44d54c: ff92d0010000 CALL dword ptr [EDX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001d0u)),4511058u); flags=s.arithmetic_flags;
  }
  L0044d552: { // 0x44d552: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044d554: { // 0x44d554: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d556: { // 0x44d556: ff90d4010000 CALL dword ptr [EAX + 0x1d4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d4u)),4511068u); flags=s.arithmetic_flags;
  }
  L0044d55c: { // 0x44d55c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d55d: { // 0x44d55d: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0044d55f: { // 0x44d55f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d560: { // 0x44d560: c3 RET
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
void f_00096890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00496890: { // 0x496890: 8a4118 MOV AL, byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  L00496893: { // 0x496893: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00496895: { // 0x496895: 740a JZ 0x4968a1
    if(integer::condition("JZ",flags)) goto L004968a1;
  }
  L00496897: { // 0x496897: 8a4119 MOV AL, byte ptr [ECX + 0x19]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000019u)));
  }
  L0049689a: { // 0x49689a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049689c: { // 0x49689c: 7503 JNZ 0x4968a1
    if(integer::condition("JNZ",flags)) goto L004968a1;
  }
  L0049689e: { // 0x49689e: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004968a0: { // 0x4968a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004968a1: { // 0x4968a1: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004968a3: { // 0x4968a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00096930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00496930: { // 0x496930: 8a4118 MOV AL, byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  L00496933: { // 0x496933: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00496935: { // 0x496935: 750a JNZ 0x496941
    if(integer::condition("JNZ",flags)) goto L00496941;
  }
  L00496937: { // 0x496937: 8a4119 MOV AL, byte ptr [ECX + 0x19]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000019u)));
  }
  L0049693a: { // 0x49693a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049693c: { // 0x49693c: 7503 JNZ 0x496941
    if(integer::condition("JNZ",flags)) goto L00496941;
  }
  L0049693e: { // 0x49693e: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00496940: { // 0x496940: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00496941: { // 0x496941: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00496943: { // 0x496943: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00096910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00496910: { // 0x496910: 8a4118 MOV AL, byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  L00496913: { // 0x496913: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00496915: { // 0x496915: 7509 JNZ 0x496920
    if(integer::condition("JNZ",flags)) goto L00496920;
  }
  L00496917: { // 0x496917: 8a5119 MOV DL, byte ptr [ECX + 0x19]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000019u)));
  }
  L0049691a: { // 0x49691a: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0049691c: { // 0x49691c: 3ad0 CMP DL, AL
    (void)integer::sub((s.dx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0049691e: { // 0x49691e: 7402 JZ 0x496922
    if(integer::condition("JZ",flags)) goto L00496922;
  }
  L00496920: { // 0x496920: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00496922: { // 0x496922: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5131296u:f_000e4c20(m,s,child,{});break;
case 7064080u:f_002bca10(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4510912u:f_0004d4c0(m,s,child,{});break;
case 5838192u:f_00191570(m,s,child,{});break;
case 4810896u:f_00096890(m,s,child,{});break;
case 4811056u:f_00096930(m,s,child,{});break;
case 4811024u:f_00096910(m,s,child,{});break;
default:throw std::domain_error("recovery690 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00557ac0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557ac0: { // 0x557ac0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00557ac4: { // 0x557ac4: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L00557ac8: { // 0x557ac8: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L00557acb: { // 0x557acb: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00557ace: { // 0x557ace: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00557ad0: { // 0x557ad0: 7814 JS 0x00557ae6
    if(integer::condition("JS",flags)) goto L00557ae6;
  }
  L00557ad2: { // 0x557ad2: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00557ad7: { // 0x557ad7: 7d0d JGE 0x00557ae6
    if(integer::condition("JGE",flags)) goto L00557ae6;
  }
  L00557ad9: { // 0x557ad9: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00557adf: { // 0x557adf: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00557ae2: { // 0x557ae2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557ae4: { // 0x557ae4: 750c JNZ 0x00557af2
    if(integer::condition("JNZ",flags)) goto L00557af2;
  }
  L00557ae6: { // 0x557ae6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00557ae8: { // 0x557ae8: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00557aed: { // 0x557aed: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00557af2: { // 0x557af2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557af3: { // 0x557af3: 8bb0e4000000 MOV ESI,dword ptr [EAX + 0xe4]
    s.si = m.r32((s.ax+0x000000e4u));
  }
  L00557af9: { // 0x557af9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00557afb: { // 0x557afb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557afc: { // 0x557afc: 7446 JZ 0x00557b44
    if(integer::condition("JZ",flags)) goto L00557b44;
  }
  L00557afe: { // 0x557afe: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00557b02: { // 0x557b02: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00557b04: { // 0x557b04: 7437 JZ 0x00557b3d
    if(integer::condition("JZ",flags)) goto L00557b3d;
  }
  L00557b06: { // 0x557b06: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00557b08: { // 0x557b08: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00557b0a: { // 0x557b0a: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5602061u); flags=s.arithmetic_flags;
  }
  L00557b0d: { // 0x557b0d: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L00557b10: { // 0x557b10: 752b JNZ 0x00557b3d
    if(integer::condition("JNZ",flags)) goto L00557b3d;
  }
  L00557b12: { // 0x557b12: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00557b18: { // 0x557b18: 8a8851130000 MOV CL,byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L00557b1e: { // 0x557b1e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00557b20: { // 0x557b20: 741b JZ 0x00557b3d
    if(integer::condition("JZ",flags)) goto L00557b3d;
  }
  L00557b22: { // 0x557b22: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L00557b28: { // 0x557b28: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557b29: { // 0x557b29: e8f2d0f8ff CALL 0x004e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,5602094u); flags=s.arithmetic_flags;
  }
  L00557b2e: { // 0x557b2e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557b30: { // 0x557b30: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00557b32: { // 0x557b32: 7517 JNZ 0x00557b4b
    if(integer::condition("JNZ",flags)) goto L00557b4b;
  }
  L00557b34: { // 0x557b34: e8375aefff CALL 0x0044d570
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044d570u,5602105u); flags=s.arithmetic_flags;
  }
  L00557b39: { // 0x557b39: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557b3b: { // 0x557b3b: 7507 JNZ 0x00557b44
    if(integer::condition("JNZ",flags)) goto L00557b44;
  }
  L00557b3d: { // 0x557b3d: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00557b40: { // 0x557b40: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00557b42: { // 0x557b42: 75be JNZ 0x00557b02
    if(integer::condition("JNZ",flags)) goto L00557b02;
  }
  L00557b44: { // 0x557b44: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557b45: { // 0x557b45: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00557b47: { // 0x557b47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557b48: { // 0x557b48: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00557b4b: { // 0x557b4b: e87059efff CALL 0x0044d4c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044d4c0u,5602128u); flags=s.arithmetic_flags;
  }
  L00557b50: { // 0x557b50: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557b51: { // 0x557b51: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557b52: { // 0x557b52: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
