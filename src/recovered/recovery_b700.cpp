#include "recovered/recovery_b700_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b700 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_002c2be0(Memory&,State&,Frame&,const Operations&);
void f_002cdb10(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_002d0490(Memory&,State&,Frame&,const Operations&);
void f_00307f60(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("700 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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
void f_002d0490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d0490: { // 0x6d0490: 8b914c070000 MOV EDX, dword ptr [ECX + 0x74c]
    s.dx = m.r32((s.cx+0x0000074cu));
  }
  L006d0496: { // 0x6d0496: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d0498: { // 0x6d0498: 7427 JZ 0x6d04c1
    if(integer::condition("JZ",flags)) goto L006d04c1;
  }
  L006d049a: { // 0x6d049a: 8b8968070000 MOV ECX, dword ptr [ECX + 0x768]
    s.cx = m.r32((s.cx+0x00000768u));
  }
  L006d04a0: { // 0x6d04a0: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006d04a5: { // 0x6d04a5: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L006d04a7: { // 0x6d04a7: 741a JZ 0x6d04c3
    if(integer::condition("JZ",flags)) goto L006d04c3;
  }
  L006d04a9: { // 0x6d04a9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d04aa: { // 0x6d04aa: 8bb29c000000 MOV ESI, dword ptr [EDX + 0x9c]
    s.si = m.r32((s.dx+0x0000009cu));
  }
  L006d04b0: { // 0x6d04b0: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006d04b2: { // 0x6d04b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d04b3: { // 0x6d04b3: 7f0e JG 0x6d04c3
    if(integer::condition("JG",flags)) goto L006d04c3;
  }
  L006d04b5: { // 0x6d04b5: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006d04b7: { // 0x6d04b7: 7408 JZ 0x6d04c1
    if(integer::condition("JZ",flags)) goto L006d04c1;
  }
  L006d04b9: { // 0x6d04b9: 39819c000000 CMP dword ptr [ECX + 0x9c], EAX
    (void)integer::sub(m.r32((s.cx+0x0000009cu)),s.ax,32,flags);
  }
  L006d04bf: { // 0x6d04bf: 7f02 JG 0x6d04c3
    if(integer::condition("JG",flags)) goto L006d04c3;
  }
  L006d04c1: { // 0x6d04c1: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006d04c3: { // 0x6d04c3: c3 RET
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 7089120u:f_002c2be0(m,s,child,{});break;
case 7133968u:f_002cdb10(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 7144592u:f_002d0490(m,s,child,{});break;
case 7372640u:f_00307f60(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
default:throw std::domain_error("recovery700 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006cae70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cae70: { // 0x6cae70: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cae71: { // 0x6cae71: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cae72: { // 0x6cae72: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cae74: { // 0x6cae74: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cae76: { // 0x6cae76: ff908c020000 CALL dword ptr [EAX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000028cu)),7122556u); flags=s.arithmetic_flags;
  }
  L006cae7c: { // 0x6cae7c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cae7e: { // 0x6cae7e: 0f84b3000000 JZ 0x006caf37
    if(integer::condition("JZ",flags)) goto L006caf37;
  }
  L006cae84: { // 0x6cae84: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cae86: { // 0x6cae86: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cae88: { // 0x6cae88: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7122574u); flags=s.arithmetic_flags;
  }
  L006cae8e: { // 0x6cae8e: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006cae90: { // 0x6cae90: 8b88a0000000 MOV ECX,dword ptr [EAX + 0xa0]
    s.cx = m.r32((s.ax+0x000000a0u));
  }
  L006cae96: { // 0x6cae96: 8a8175020000 MOV AL,byte ptr [ECX + 0x275]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000275u)));
  }
  L006cae9c: { // 0x6cae9c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cae9e: { // 0x6cae9e: 0f8493000000 JZ 0x006caf37
    if(integer::condition("JZ",flags)) goto L006caf37;
  }
  L006caea4: { // 0x6caea4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006caea6: { // 0x6caea6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006caea7: { // 0x6caea7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006caea8: { // 0x6caea8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006caeaa: { // 0x6caeaa: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7122608u); flags=s.arithmetic_flags;
  }
  L006caeb0: { // 0x6caeb0: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006caeb2: { // 0x6caeb2: 8b88b4000000 MOV ECX,dword ptr [EAX + 0xb4]
    s.cx = m.r32((s.ax+0x000000b4u));
  }
  L006caeb8: { // 0x6caeb8: 8b98a0000000 MOV EBX,dword ptr [EAX + 0xa0]
    s.bx = m.r32((s.ax+0x000000a0u));
  }
  L006caebe: { // 0x6caebe: 8b90ac000000 MOV EDX,dword ptr [EAX + 0xac]
    s.dx = m.r32((s.ax+0x000000acu));
  }
  L006caec4: { // 0x6caec4: 81f900040000 CMP ECX,0x400
    (void)integer::sub(s.cx,0x00000400u,32,flags);
  }
  L006caeca: { // 0x6caeca: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006caece: { // 0x6caece: 7c08 JL 0x006caed8
    if(integer::condition("JL",flags)) goto L006caed8;
  }
  L006caed0: { // 0x6caed0: c744240c00040000 MOV dword ptr [ESP + 0xc],0x400
    m.w32((f.sp+0x0000000cu), 0x00000400u);
  }
  L006caed8: { // 0x6caed8: db80a4000000 FILD dword ptr [EAX + 0xa4]
    const auto address=(s.ax+0x000000a4u);
    s.fp.load_integer32(m.r32(address));
  }
  L006caede: { // 0x6caede: dc8ac0000000 FMUL double ptr [EDX + 0xc0]
    const auto address=(s.dx+0x000000c0u);
    s.fp.multiply64(read64(m,address));
  }
  L006caee4: { // 0x6caee4: da4c240c FIMUL dword ptr [ESP + 0xc]
    const auto operand=m.r32((f.sp+0x0000000cu));
    ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" : [host]"=m"(host.bytes),[guest]"+m"(s.fp.image.bytes) : [operand]"m"(operand) : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
  }
  L006caee8: { // 0x6caee8: dab0b0000000 FIDIV dword ptr [EAX + 0xb0]
    const auto address=(s.ax+0x000000b0u);
    s.fp.divide_integer32(m.r32(address));
  }
  L006caeee: { // 0x6caeee: e85dfb0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7122675u); flags=s.arithmetic_flags;
  }
  L006caef3: { // 0x6caef3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006caef5: { // 0x6caef5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006caef7: { // 0x6caef7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006caef9: { // 0x6caef9: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7122687u); flags=s.arithmetic_flags;
  }
  L006caeff: { // 0x6caeff: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006caf01: { // 0x6caf01: e88a550000 CALL 0x006d0490
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d0490u,7122694u); flags=s.arithmetic_flags;
  }
  L006caf06: { // 0x6caf06: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006caf08: { // 0x6caf08: 7402 JZ 0x006caf0c
    if(integer::condition("JZ",flags)) goto L006caf0c;
  }
  L006caf0a: { // 0x6caf0a: 03ff ADD EDI,EDI
    s.di = integer::add(s.di,s.di,32,flags);
  }
  L006caf0c: { // 0x6caf0c: 8a8372020000 MOV AL,byte ptr [EBX + 0x272]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000272u)));
  }
  L006caf12: { // 0x6caf12: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006caf14: { // 0x6caf14: 7409 JZ 0x006caf1f
    if(integer::condition("JZ",flags)) goto L006caf1f;
  }
  L006caf16: { // 0x6caf16: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006caf18: { // 0x6caf18: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006caf19: { // 0x6caf19: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006caf1b: { // 0x6caf1b: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006caf1d: { // 0x6caf1d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006caf1f: { // 0x6caf1f: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L006caf24: { // 0x6caf24: f7ef IMUL EDI
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.di,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L006caf26: { // 0x6caf26: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006caf28: { // 0x6caf28: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006caf29: { // 0x6caf29: c1f804 SAR EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L006caf2c: { // 0x6caf2c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006caf2e: { // 0x6caf2e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006caf2f: { // 0x6caf2f: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L006caf32: { // 0x6caf32: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006caf34: { // 0x6caf34: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006caf35: { // 0x6caf35: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006caf36: { // 0x6caf36: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006caf37: { // 0x6caf37: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006caf39: { // 0x6caf39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006caf3a: { // 0x6caf3a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006caf3b: { // 0x6caf3b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006caf40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006caf40: { // 0x6caf40: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006caf41: { // 0x6caf41: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006caf42: { // 0x6caf42: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006caf44: { // 0x6caf44: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006caf46: { // 0x6caf46: ff908c020000 CALL dword ptr [EAX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000028cu)),7122764u); flags=s.arithmetic_flags;
  }
  L006caf4c: { // 0x6caf4c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006caf4e: { // 0x6caf4e: 0f84b3000000 JZ 0x006cb007
    if(integer::condition("JZ",flags)) goto L006cb007;
  }
  L006caf54: { // 0x6caf54: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006caf56: { // 0x6caf56: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006caf58: { // 0x6caf58: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7122782u); flags=s.arithmetic_flags;
  }
  L006caf5e: { // 0x6caf5e: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006caf60: { // 0x6caf60: 8b88a0000000 MOV ECX,dword ptr [EAX + 0xa0]
    s.cx = m.r32((s.ax+0x000000a0u));
  }
  L006caf66: { // 0x6caf66: 8a8175020000 MOV AL,byte ptr [ECX + 0x275]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000275u)));
  }
  L006caf6c: { // 0x6caf6c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006caf6e: { // 0x6caf6e: 0f8493000000 JZ 0x006cb007
    if(integer::condition("JZ",flags)) goto L006cb007;
  }
  L006caf74: { // 0x6caf74: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006caf76: { // 0x6caf76: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006caf77: { // 0x6caf77: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006caf78: { // 0x6caf78: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006caf7a: { // 0x6caf7a: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7122816u); flags=s.arithmetic_flags;
  }
  L006caf80: { // 0x6caf80: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006caf82: { // 0x6caf82: 8b88b4000000 MOV ECX,dword ptr [EAX + 0xb4]
    s.cx = m.r32((s.ax+0x000000b4u));
  }
  L006caf88: { // 0x6caf88: 8b98a0000000 MOV EBX,dword ptr [EAX + 0xa0]
    s.bx = m.r32((s.ax+0x000000a0u));
  }
  L006caf8e: { // 0x6caf8e: 8b90ac000000 MOV EDX,dword ptr [EAX + 0xac]
    s.dx = m.r32((s.ax+0x000000acu));
  }
  L006caf94: { // 0x6caf94: 81f900040000 CMP ECX,0x400
    (void)integer::sub(s.cx,0x00000400u,32,flags);
  }
  L006caf9a: { // 0x6caf9a: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006caf9e: { // 0x6caf9e: 7c08 JL 0x006cafa8
    if(integer::condition("JL",flags)) goto L006cafa8;
  }
  L006cafa0: { // 0x6cafa0: c744240c00040000 MOV dword ptr [ESP + 0xc],0x400
    m.w32((f.sp+0x0000000cu), 0x00000400u);
  }
  L006cafa8: { // 0x6cafa8: db80a4000000 FILD dword ptr [EAX + 0xa4]
    const auto address=(s.ax+0x000000a4u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cafae: { // 0x6cafae: dc8aa0000000 FMUL double ptr [EDX + 0xa0]
    const auto address=(s.dx+0x000000a0u);
    s.fp.multiply64(read64(m,address));
  }
  L006cafb4: { // 0x6cafb4: da4c240c FIMUL dword ptr [ESP + 0xc]
    const auto operand=m.r32((f.sp+0x0000000cu));
    ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" : [host]"=m"(host.bytes),[guest]"+m"(s.fp.image.bytes) : [operand]"m"(operand) : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
  }
  L006cafb8: { // 0x6cafb8: dab0b0000000 FIDIV dword ptr [EAX + 0xb0]
    const auto address=(s.ax+0x000000b0u);
    s.fp.divide_integer32(m.r32(address));
  }
  L006cafbe: { // 0x6cafbe: e88dfa0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7122883u); flags=s.arithmetic_flags;
  }
  L006cafc3: { // 0x6cafc3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006cafc5: { // 0x6cafc5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cafc7: { // 0x6cafc7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cafc9: { // 0x6cafc9: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7122895u); flags=s.arithmetic_flags;
  }
  L006cafcf: { // 0x6cafcf: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cafd1: { // 0x6cafd1: e8ba540000 CALL 0x006d0490
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d0490u,7122902u); flags=s.arithmetic_flags;
  }
  L006cafd6: { // 0x6cafd6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cafd8: { // 0x6cafd8: 7402 JZ 0x006cafdc
    if(integer::condition("JZ",flags)) goto L006cafdc;
  }
  L006cafda: { // 0x6cafda: 03ff ADD EDI,EDI
    s.di = integer::add(s.di,s.di,32,flags);
  }
  L006cafdc: { // 0x6cafdc: 8a8372020000 MOV AL,byte ptr [EBX + 0x272]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000272u)));
  }
  L006cafe2: { // 0x6cafe2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cafe4: { // 0x6cafe4: 7409 JZ 0x006cafef
    if(integer::condition("JZ",flags)) goto L006cafef;
  }
  L006cafe6: { // 0x6cafe6: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006cafe8: { // 0x6cafe8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006cafe9: { // 0x6cafe9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006cafeb: { // 0x6cafeb: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006cafed: { // 0x6cafed: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006cafef: { // 0x6cafef: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L006caff4: { // 0x6caff4: f7ef IMUL EDI
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.di,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L006caff6: { // 0x6caff6: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006caff8: { // 0x6caff8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006caff9: { // 0x6caff9: c1f804 SAR EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L006caffc: { // 0x6caffc: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006caffe: { // 0x6caffe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cafff: { // 0x6cafff: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L006cb002: { // 0x6cb002: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006cb004: { // 0x6cb004: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cb005: { // 0x6cb005: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006cb006: { // 0x6cb006: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cb007: { // 0x6cb007: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cb009: { // 0x6cb009: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cb00a: { // 0x6cb00a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006cb00b: { // 0x6cb00b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006cbcf0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cbcf0: { // 0x6cbcf0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cbcf1: { // 0x6cbcf1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cbcf2: { // 0x6cbcf2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cbcf4: { // 0x6cbcf4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cbcf5: { // 0x6cbcf5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cbcf7: { // 0x6cbcf7: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7126269u); flags=s.arithmetic_flags;
  }
  L006cbcfd: { // 0x6cbcfd: 8a88e10a0000 MOV CL,byte ptr [EAX + 0xae1]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ae1u)));
  }
  L006cbd03: { // 0x6cbd03: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006cbd05: { // 0x6cbd05: 7562 JNZ 0x006cbd69
    if(integer::condition("JNZ",flags)) goto L006cbd69;
  }
  L006cbd07: { // 0x6cbd07: 8d9e18010000 LEA EBX,[ESI + 0x118]
    s.bx = (s.si+0x00000118u);
  }
  L006cbd0d: { // 0x6cbd0d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006cbd0f: { // 0x6cbd0f: e84cc20300 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7126292u); flags=s.arithmetic_flags;
  }
  L006cbd14: { // 0x6cbd14: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbd16: { // 0x6cbd16: 750b JNZ 0x006cbd23
    if(integer::condition("JNZ",flags)) goto L006cbd23;
  }
  L006cbd18: { // 0x6cbd18: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006cbd1a: { // 0x6cbd1a: e8c1c20300 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7126303u); flags=s.arithmetic_flags;
  }
  L006cbd1f: { // 0x6cbd1f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbd21: { // 0x6cbd21: 7440 JZ 0x006cbd63
    if(integer::condition("JZ",flags)) goto L006cbd63;
  }
  L006cbd23: { // 0x6cbd23: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cbd25: { // 0x6cbd25: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cbd27: { // 0x6cbd27: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7126317u); flags=s.arithmetic_flags;
  }
  L006cbd2d: { // 0x6cbd2d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006cbd2f: { // 0x6cbd2f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006cbd31: { // 0x6cbd31: e82ac20300 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7126326u); flags=s.arithmetic_flags;
  }
  L006cbd36: { // 0x6cbd36: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbd38: { // 0x6cbd38: 740a JZ 0x006cbd44
    if(integer::condition("JZ",flags)) goto L006cbd44;
  }
  L006cbd3a: { // 0x6cbd3a: 8a8775020000 MOV AL,byte ptr [EDI + 0x275]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000275u)));
  }
  L006cbd40: { // 0x6cbd40: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbd42: { // 0x6cbd42: 7525 JNZ 0x006cbd69
    if(integer::condition("JNZ",flags)) goto L006cbd69;
  }
  L006cbd44: { // 0x6cbd44: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006cbd46: { // 0x6cbd46: e895c20300 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7126347u); flags=s.arithmetic_flags;
  }
  L006cbd4b: { // 0x6cbd4b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbd4d: { // 0x6cbd4d: 7414 JZ 0x006cbd63
    if(integer::condition("JZ",flags)) goto L006cbd63;
  }
  L006cbd4f: { // 0x6cbd4f: 8a8775020000 MOV AL,byte ptr [EDI + 0x275]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000275u)));
  }
  L006cbd55: { // 0x6cbd55: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbd57: { // 0x6cbd57: 7510 JNZ 0x006cbd69
    if(integer::condition("JNZ",flags)) goto L006cbd69;
  }
  L006cbd59: { // 0x6cbd59: 8a8787020000 MOV AL,byte ptr [EDI + 0x287]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000287u)));
  }
  L006cbd5f: { // 0x6cbd5f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cbd61: { // 0x6cbd61: 7506 JNZ 0x006cbd69
    if(integer::condition("JNZ",flags)) goto L006cbd69;
  }
  L006cbd63: { // 0x6cbd63: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cbd64: { // 0x6cbd64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cbd65: { // 0x6cbd65: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cbd67: { // 0x6cbd67: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cbd68: { // 0x6cbd68: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cbd69: { // 0x6cbd69: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006cbd6e: { // 0x6cbd6e: dd8048130000 FLD double ptr [EAX + 0x1348]
    const auto address=(s.ax+0x00001348u);
    s.fp.load64(read64(m,address));
  }
  L006cbd74: { // 0x6cbd74: dc0d08667800 FMUL double ptr [0x00786608]
    const auto address=(0x00786608u);
    s.fp.multiply64(read64(m,address));
  }
  L006cbd7a: { // 0x6cbd7a: e8d1ec0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7126399u); flags=s.arithmetic_flags;
  }
  L006cbd7f: { // 0x6cbd7f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cbd81: { // 0x6cbd81: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006cbd86: { // 0x6cbd86: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006cbd87: { // 0x6cbd87: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006cbd89: { // 0x6cbd89: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006cbd8b: { // 0x6cbd8b: 7406 JZ 0x006cbd93
    if(integer::condition("JZ",flags)) goto L006cbd93;
  }
  L006cbd8d: { // 0x6cbd8d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cbd8e: { // 0x6cbd8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cbd8f: { // 0x6cbd8f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cbd91: { // 0x6cbd91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cbd92: { // 0x6cbd92: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cbd93: { // 0x6cbd93: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cbd95: { // 0x6cbd95: 8b7e6c MOV EDI,dword ptr [ESI + 0x6c]
    s.di = m.r32((s.si+0x0000006cu));
  }
  L006cbd98: { // 0x6cbd98: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cbd9a: { // 0x6cbd9a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7126432u); flags=s.arithmetic_flags;
  }
  L006cbda0: { // 0x6cbda0: 3bb8a0000000 CMP EDI,dword ptr [EAX + 0xa0]
    (void)integer::sub(s.di,m.r32((s.ax+0x000000a0u)),32,flags);
  }
  L006cbda6: { // 0x6cbda6: 7506 JNZ 0x006cbdae
    if(integer::condition("JNZ",flags)) goto L006cbdae;
  }
  L006cbda8: { // 0x6cbda8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cbda9: { // 0x6cbda9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cbdaa: { // 0x6cbdaa: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cbdac: { // 0x6cbdac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cbdad: { // 0x6cbdad: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cbdae: { // 0x6cbdae: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006cbdb0: { // 0x6cbdb0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cbdb1: { // 0x6cbdb1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cbdb2: { // 0x6cbdb2: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L006cbdb5: { // 0x6cbdb5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cbdb6: { // 0x6cbdb6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
