#include "recovered/recovery_b722_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b722 {
namespace {
void f_002b5660(Memory&,State&,Frame&,const Operations&);
void f_0022e4b0(Memory&,State&,Frame&,const Operations&);
void f_00191570(Memory&,State&,Frame&,const Operations&);
void f_00191bb0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_001ce650(Memory&,State&,Frame&,const Operations&);
void f_002d0260(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b5660(Memory& m,State& s,Frame& f,const Operations& op) {
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
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
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
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("722 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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
void f_001ce650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ce650: { // 0x5ce650: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L005ce653: { // 0x5ce653: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ce654: { // 0x5ce654: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005ce655: { // 0x5ce655: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ce656: { // 0x5ce656: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005ce657: { // 0x5ce657: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L005ce659: { // 0x5ce659: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005ce65b: { // 0x5ce65b: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005ce65d: { // 0x5ce65d: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),6088288u); flags=s.arithmetic_flags;
  }
  L005ce660: { // 0x5ce660: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L005ce664: { // 0x5ce664: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005ce668: { // 0x5ce668: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005ce66a: { // 0x5ce66a: 8b4178 MOV EAX, dword ptr [ECX + 0x78]
    s.ax = m.r32((s.cx+0x00000078u));
  }
  L005ce66d: { // 0x5ce66d: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ce66f: { // 0x5ce66f: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005ce673: { // 0x5ce673: 0f8e54010000 JLE 0x5ce7cd
    if(integer::condition("JLE",flags)) goto L005ce7cd;
  }
  L005ce679: { // 0x5ce679: 8b542428 MOV EDX, dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L005ce67d: { // 0x5ce67d: 8b426c MOV EAX, dword ptr [EDX + 0x6c]
    s.ax = m.r32((s.dx+0x0000006cu));
  }
  L005ce680: { // 0x5ce680: 8b34a8 MOV ESI, dword ptr [EAX + EBP*4]
    s.si = m.r32((s.ax+(s.bp * 4u)));
  }
  L005ce683: { // 0x5ce683: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005ce686: { // 0x5ce686: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce688: { // 0x5ce688: 0f8516010000 JNZ 0x5ce7a4
    if(integer::condition("JNZ",flags)) goto L005ce7a4;
  }
  L005ce68e: { // 0x5ce68e: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005ce690: { // 0x5ce690: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005ce692: { // 0x5ce692: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6088341u); flags=s.arithmetic_flags;
  }
  L005ce695: { // 0x5ce695: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L005ce69b: { // 0x5ce69b: 3981440c0000 CMP dword ptr [ECX + 0xc44], EAX
    (void)integer::sub(m.r32((s.cx+0x00000c44u)),s.ax,32,flags);
  }
  L005ce6a1: { // 0x5ce6a1: 0f85fd000000 JNZ 0x5ce7a4
    if(integer::condition("JNZ",flags)) goto L005ce7a4;
  }
  L005ce6a7: { // 0x5ce6a7: 8a442420 MOV AL, byte ptr [ESP + 0x20]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000020u)));
  }
  L005ce6ab: { // 0x5ce6ab: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce6ad: { // 0x5ce6ad: 740e JZ 0x5ce6bd
    if(integer::condition("JZ",flags)) goto L005ce6bd;
  }
  L005ce6af: { // 0x5ce6af: 8a8630050000 MOV AL, byte ptr [ESI + 0x530]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000530u)));
  }
  L005ce6b5: { // 0x5ce6b5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce6b7: { // 0x5ce6b7: 0f84e7000000 JZ 0x5ce7a4
    if(integer::condition("JZ",flags)) goto L005ce7a4;
  }
  L005ce6bd: { // 0x5ce6bd: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005ce6bf: { // 0x5ce6bf: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005ce6c1: { // 0x5ce6c1: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),6088391u); flags=s.arithmetic_flags;
  }
  L005ce6c7: { // 0x5ce6c7: 83f813 CMP EAX, 0x13
    (void)integer::sub(s.ax,0x00000013u,32,flags);
  }
  L005ce6ca: { // 0x5ce6ca: 0f84d4000000 JZ 0x5ce7a4
    if(integer::condition("JZ",flags)) goto L005ce7a4;
  }
  L005ce6d0: { // 0x5ce6d0: 83bea000000013 CMP dword ptr [ESI + 0xa0], 0x13
    (void)integer::sub(m.r32((s.si+0x000000a0u)),0x00000013u,32,flags);
  }
  L005ce6d7: { // 0x5ce6d7: 0f84c7000000 JZ 0x5ce7a4
    if(integer::condition("JZ",flags)) goto L005ce7a4;
  }
  L005ce6dd: { // 0x5ce6dd: 8a442424 MOV AL, byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L005ce6e1: { // 0x5ce6e1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce6e3: { // 0x5ce6e3: 7418 JZ 0x5ce6fd
    if(integer::condition("JZ",flags)) goto L005ce6fd;
  }
  L005ce6e5: { // 0x5ce6e5: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L005ce6eb: { // 0x5ce6eb: 6a01 PUSH 1
    f.push(m,1u);
  }
  L005ce6ed: { // 0x5ce6ed: 6a01 PUSH 1
    f.push(m,1u);
  }
  L005ce6ef: { // 0x5ce6ef: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005ce6f0: { // 0x5ce6f0: e8fb45f1ff CALL 0x4e2cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e2cf0u,6088437u); flags=s.arithmetic_flags;
  }
  L005ce6f5: { // 0x5ce6f5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ce6f7: { // 0x5ce6f7: 0f8ea7000000 JLE 0x5ce7a4
    if(integer::condition("JLE",flags)) goto L005ce7a4;
  }
  L005ce6fd: { // 0x5ce6fd: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L005ce703: { // 0x5ce703: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005ce705: { // 0x5ce705: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),6088456u); flags=s.arithmetic_flags;
  }
  L005ce708: { // 0x5ce708: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005ce70c: { // 0x5ce70c: 85c1 TEST ECX, EAX
    (void)integer::logical((s.cx)&(s.ax),32,flags);
  }
  L005ce70e: { // 0x5ce70e: 0f8490000000 JZ 0x5ce7a4
    if(integer::condition("JZ",flags)) goto L005ce7a4;
  }
  L005ce714: { // 0x5ce714: 8a44241c MOV AL, byte ptr [ESP + 0x1c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000001cu)));
  }
  L005ce718: { // 0x5ce718: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce71a: { // 0x5ce71a: 753a JNZ 0x5ce756
    if(integer::condition("JNZ",flags)) goto L005ce756;
  }
  L005ce71c: { // 0x5ce71c: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005ce71e: { // 0x5ce71e: e88dfd0500 CALL 0x62e4b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4b0u,6088483u); flags=s.arithmetic_flags;
  }
  L005ce723: { // 0x5ce723: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce725: { // 0x5ce725: 742f JZ 0x5ce756
    if(integer::condition("JZ",flags)) goto L005ce756;
  }
  L005ce727: { // 0x5ce727: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005ce729: { // 0x5ce729: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005ce72b: { // 0x5ce72b: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6088494u); flags=s.arithmetic_flags;
  }
  L005ce72e: { // 0x5ce72e: 83f803 CMP EAX, 3
    (void)integer::sub(s.ax,3u,32,flags);
  }
  L005ce731: { // 0x5ce731: 7523 JNZ 0x5ce756
    if(integer::condition("JNZ",flags)) goto L005ce756;
  }
  L005ce733: { // 0x5ce733: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005ce735: { // 0x5ce735: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005ce737: { // 0x5ce737: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6088506u); flags=s.arithmetic_flags;
  }
  L005ce73a: { // 0x5ce73a: 83f803 CMP EAX, 3
    (void)integer::sub(s.ax,3u,32,flags);
  }
  L005ce73d: { // 0x5ce73d: 7565 JNZ 0x5ce7a4
    if(integer::condition("JNZ",flags)) goto L005ce7a4;
  }
  L005ce73f: { // 0x5ce73f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005ce741: { // 0x5ce741: e8fafc0500 CALL 0x62e440
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e440u,6088518u); flags=s.arithmetic_flags;
  }
  L005ce746: { // 0x5ce746: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce748: { // 0x5ce748: 745a JZ 0x5ce7a4
    if(integer::condition("JZ",flags)) goto L005ce7a4;
  }
  L005ce74a: { // 0x5ce74a: 8a862b030000 MOV AL, byte ptr [ESI + 0x32b]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032bu)));
  }
  L005ce750: { // 0x5ce750: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce752: { // 0x5ce752: 756d JNZ 0x5ce7c1
    if(integer::condition("JNZ",flags)) goto L005ce7c1;
  }
  L005ce754: { // 0x5ce754: eb4c JMP 0x5ce7a2
    goto L005ce7a2;
  }
  L005ce756: { // 0x5ce756: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005ce758: { // 0x5ce758: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005ce75a: { // 0x5ce75a: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6088541u); flags=s.arithmetic_flags;
  }
  L005ce75d: { // 0x5ce75d: 83f828 CMP EAX, 0x28
    (void)integer::sub(s.ax,0x00000028u,32,flags);
  }
  L005ce760: { // 0x5ce760: 7526 JNZ 0x5ce788
    if(integer::condition("JNZ",flags)) goto L005ce788;
  }
  L005ce762: { // 0x5ce762: 8a87da0a0000 MOV AL, byte ptr [EDI + 0xada]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000adau)));
  }
  L005ce768: { // 0x5ce768: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce76a: { // 0x5ce76a: 741c JZ 0x5ce788
    if(integer::condition("JZ",flags)) goto L005ce788;
  }
  L005ce76c: { // 0x5ce76c: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L005ce772: { // 0x5ce772: 8a88da0a0000 MOV CL, byte ptr [EAX + 0xada]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000adau)));
  }
  L005ce778: { // 0x5ce778: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005ce77a: { // 0x5ce77a: 7428 JZ 0x5ce7a4
    if(integer::condition("JZ",flags)) goto L005ce7a4;
  }
  L005ce77c: { // 0x5ce77c: 8a862b030000 MOV AL, byte ptr [ESI + 0x32b]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032bu)));
  }
  L005ce782: { // 0x5ce782: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce784: { // 0x5ce784: 753b JNZ 0x5ce7c1
    if(integer::condition("JNZ",flags)) goto L005ce7c1;
  }
  L005ce786: { // 0x5ce786: eb10 JMP 0x5ce798
    goto L005ce798;
  }
  L005ce788: { // 0x5ce788: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L005ce78e: { // 0x5ce78e: 8a81da0a0000 MOV AL, byte ptr [ECX + 0xada]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000adau)));
  }
  L005ce794: { // 0x5ce794: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce796: { // 0x5ce796: 750c JNZ 0x5ce7a4
    if(integer::condition("JNZ",flags)) goto L005ce7a4;
  }
  L005ce798: { // 0x5ce798: 8a862b030000 MOV AL, byte ptr [ESI + 0x32b]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032bu)));
  }
  L005ce79e: { // 0x5ce79e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce7a0: { // 0x5ce7a0: 751f JNZ 0x5ce7c1
    if(integer::condition("JNZ",flags)) goto L005ce7c1;
  }
  L005ce7a2: { // 0x5ce7a2: 8bde MOV EBX, ESI
    s.bx = s.si;
  }
  L005ce7a4: { // 0x5ce7a4: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005ce7a8: { // 0x5ce7a8: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L005ce7a9: { // 0x5ce7a9: 3be8 CMP EBP, EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L005ce7ab: { // 0x5ce7ab: 0f8cc8feffff JL 0x5ce679
    if(integer::condition("JL",flags)) goto L005ce679;
  }
  L005ce7b1: { // 0x5ce7b1: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005ce7b3: { // 0x5ce7b3: 7418 JZ 0x5ce7cd
    if(integer::condition("JZ",flags)) goto L005ce7cd;
  }
  L005ce7b5: { // 0x5ce7b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ce7b6: { // 0x5ce7b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ce7b7: { // 0x5ce7b7: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L005ce7b9: { // 0x5ce7b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005ce7ba: { // 0x5ce7ba: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005ce7bb: { // 0x5ce7bb: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005ce7be: { // 0x5ce7be: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L005ce7c1: { // 0x5ce7c1: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L005ce7c3: { // 0x5ce7c3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ce7c4: { // 0x5ce7c4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ce7c5: { // 0x5ce7c5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005ce7c6: { // 0x5ce7c6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005ce7c7: { // 0x5ce7c7: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005ce7ca: { // 0x5ce7ca: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L005ce7cd: { // 0x5ce7cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ce7ce: { // 0x5ce7ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ce7cf: { // 0x5ce7cf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005ce7d0: { // 0x5ce7d0: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005ce7d2: { // 0x5ce7d2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005ce7d3: { // 0x5ce7d3: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005ce7d6: { // 0x5ce7d6: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_002d0260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d0260: { // 0x6d0260: 8a81a50a0000 MOV AL, byte ptr [ECX + 0xaa5]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000aa5u)));
  }
  L006d0266: { // 0x6d0266: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d0268: { // 0x6d0268: 740e JZ 0x6d0278
    if(integer::condition("JZ",flags)) goto L006d0278;
  }
  L006d026a: { // 0x6d026a: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L006d026f: { // 0x6d026f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d0271: { // 0x6d0271: b8ffffff7f MOV EAX, 0x7fffffff
    s.ax = 0x7fffffffu;
  }
  L006d0276: { // 0x6d0276: 7506 JNZ 0x6d027e
    if(integer::condition("JNZ",flags)) goto L006d027e;
  }
  L006d0278: { // 0x6d0278: 8b81e8050000 MOV EAX, dword ptr [ECX + 0x5e8]
    s.ax = m.r32((s.cx+0x000005e8u));
  }
  L006d027e: { // 0x6d027e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7034464u:f_002b5660(m,s,child,{});break;
case 6481072u:f_0022e4b0(m,s,child,{});break;
case 5838192u:f_00191570(m,s,child,{});break;
case 5839792u:f_00191bb0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 6088272u:f_001ce650(m,s,child,{});break;
case 7144032u:f_002d0260(m,s,child,{});break;
default:throw std::domain_error("recovery722 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004f2b30(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f2b30: { // 0x4f2b30: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004f2b33: { // 0x4f2b33: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f2b34: { // 0x4f2b34: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f2b35: { // 0x4f2b35: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f2b36: { // 0x4f2b36: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L004f2b3a: { // 0x4f2b3a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f2b3c: { // 0x4f2b3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f2b3d: { // 0x4f2b3d: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L004f2b3f: { // 0x4f2b3f: 0f84cc000000 JZ 0x004f2c11
    if(integer::condition("JZ",flags)) goto L004f2c11;
  }
  L004f2b45: { // 0x4f2b45: 8b86dc000000 MOV EAX,dword ptr [ESI + 0xdc]
    s.ax = m.r32((s.si+0x000000dcu));
  }
  L004f2b4b: { // 0x4f2b4b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f2b4d: { // 0x4f2b4d: 0f84be000000 JZ 0x004f2c11
    if(integer::condition("JZ",flags)) goto L004f2c11;
  }
  L004f2b53: { // 0x4f2b53: 8b889c000000 MOV ECX,dword ptr [EAX + 0x9c]
    s.cx = m.r32((s.ax+0x0000009cu));
  }
  L004f2b59: { // 0x4f2b59: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L004f2b61: { // 0x4f2b61: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004f2b63: { // 0x4f2b63: 0f8e9c000000 JLE 0x004f2c05
    if(integer::condition("JLE",flags)) goto L004f2c05;
  }
  L004f2b69: { // 0x4f2b69: c7442410a8000000 MOV dword ptr [ESP + 0x10],0xa8
    m.w32((f.sp+0x00000010u), 0x000000a8u);
  }
  L004f2b71: { // 0x4f2b71: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004f2b75: { // 0x4f2b75: 8b1c01 MOV EBX,dword ptr [ECX + EAX*0x1]
    s.bx = m.r32((s.cx+(s.ax * 0x00000001u)));
  }
  L004f2b78: { // 0x4f2b78: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004f2b7a: { // 0x4f2b7a: 7415 JZ 0x004f2b91
    if(integer::condition("JZ",flags)) goto L004f2b91;
  }
  L004f2b7c: { // 0x4f2b7c: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L004f2b7e: { // 0x4f2b7e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f2b7f: { // 0x4f2b7f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004f2b81: { // 0x4f2b81: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004f2b83: { // 0x4f2b83: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004f2b85: { // 0x4f2b85: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004f2b87: { // 0x4f2b87: ff9294000000 CALL dword ptr [EDX + 0x94]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000094u)),5188493u); flags=s.arithmetic_flags;
  }
  L004f2b8d: { // 0x4f2b8d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f2b8f: { // 0x4f2b8f: 754c JNZ 0x004f2bdd
    if(integer::condition("JNZ",flags)) goto L004f2bdd;
  }
  L004f2b91: { // 0x4f2b91: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004f2b96: { // 0x4f2b96: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f2b98: { // 0x4f2b98: 7577 JNZ 0x004f2c11
    if(integer::condition("JNZ",flags)) goto L004f2c11;
  }
  L004f2b9a: { // 0x4f2b9a: a178e28400 MOV EAX,[0x0084e278]
    s.ax = m.r32((0x0084e278u));
  }
  L004f2b9f: { // 0x4f2b9f: 8d78ff LEA EDI,[EAX + -0x1]
    s.di = (s.ax-0x00000001u);
  }
  L004f2ba2: { // 0x4f2ba2: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f2ba4: { // 0x4f2ba4: 7c6b JL 0x004f2c11
    if(integer::condition("JL",flags)) goto L004f2c11;
  }
  L004f2ba6: { // 0x4f2ba6: 8b0d6ce28400 MOV ECX,dword ptr [0x0084e26c]
    s.cx = m.r32((0x0084e26cu));
  }
  L004f2bac: { // 0x4f2bac: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L004f2baf: { // 0x4f2baf: 39aeb4010000 CMP dword ptr [ESI + 0x1b4],EBP
    (void)integer::sub(m.r32((s.si+0x000001b4u)),s.bp,32,flags);
  }
  L004f2bb5: { // 0x4f2bb5: 751d JNZ 0x004f2bd4
    if(integer::condition("JNZ",flags)) goto L004f2bd4;
  }
  L004f2bb7: { // 0x4f2bb7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f2bb9: { // 0x4f2bb9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f2bbb: { // 0x4f2bbb: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),5188545u); flags=s.arithmetic_flags;
  }
  L004f2bc1: { // 0x4f2bc1: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004f2bc3: { // 0x4f2bc3: 750f JNZ 0x004f2bd4
    if(integer::condition("JNZ",flags)) goto L004f2bd4;
  }
  L004f2bc5: { // 0x4f2bc5: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L004f2bc9: { // 0x4f2bc9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f2bca: { // 0x4f2bca: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f2bcb: { // 0x4f2bcb: e8902a1c00 CALL 0x006b5660
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b5660u,5188560u); flags=s.arithmetic_flags;
  }
  L004f2bd0: { // 0x4f2bd0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f2bd2: { // 0x4f2bd2: 7505 JNZ 0x004f2bd9
    if(integer::condition("JNZ",flags)) goto L004f2bd9;
  }
  L004f2bd4: { // 0x4f2bd4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L004f2bd5: { // 0x4f2bd5: 783a JS 0x004f2c11
    if(integer::condition("JS",flags)) goto L004f2c11;
  }
  L004f2bd7: { // 0x4f2bd7: ebcd JMP 0x004f2ba6
    goto L004f2ba6;
  }
  L004f2bd9: { // 0x4f2bd9: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L004f2bdd: { // 0x4f2bdd: 8b86dc000000 MOV EAX,dword ptr [ESI + 0xdc]
    s.ax = m.r32((s.si+0x000000dcu));
  }
  L004f2be3: { // 0x4f2be3: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004f2be7: { // 0x4f2be7: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L004f2beb: { // 0x4f2beb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004f2bec: { // 0x4f2bec: 8b909c000000 MOV EDX,dword ptr [EAX + 0x9c]
    s.dx = m.r32((s.ax+0x0000009cu));
  }
  L004f2bf2: { // 0x4f2bf2: 83c708 ADD EDI,0x8
    s.di = integer::add(s.di,0x00000008u,32,flags);
  }
  L004f2bf5: { // 0x4f2bf5: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f2bf7: { // 0x4f2bf7: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004f2bfb: { // 0x4f2bfb: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L004f2bff: { // 0x4f2bff: 0f8c6cffffff JL 0x004f2b71
    if(integer::condition("JL",flags)) goto L004f2b71;
  }
  L004f2c05: { // 0x4f2c05: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f2c06: { // 0x4f2c06: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f2c07: { // 0x4f2c07: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f2c08: { // 0x4f2c08: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004f2c0a: { // 0x4f2c0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f2c0b: { // 0x4f2c0b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004f2c0e: { // 0x4f2c0e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004f2c11: { // 0x4f2c11: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f2c12: { // 0x4f2c12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f2c13: { // 0x4f2c13: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f2c14: { // 0x4f2c14: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004f2c16: { // 0x4f2c16: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f2c17: { // 0x4f2c17: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004f2c1a: { // 0x4f2c1a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
