#include "recovered/recovery_b892_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b892 {
namespace {
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_00307f60(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00052f60(Memory&,State&,Frame&,const Operations&);
void tail(Memory&,State&,Frame&,std::uint32_t);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
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
  L0044d673: { // 0x44d673: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044d677: { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d678: { // 0x44d678: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0044d67a: { // 0x44d67a: 8a87c6050000 MOV AL,byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0044d680: { // 0x44d680: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d682: { // 0x44d682: 742c JZ 0x0044d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  L0044d684: { // 0x44d684: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d686: { // 0x44d686: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d688: { // 0x44d688: 7e26 JLE 0x0044d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  L0044d68a: { // 0x44d68a: 8db7c0040000 LEA ESI,[EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0044d692: { // 0x44d692: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d694: { // 0x44d694: 740b JZ 0x0044d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  L0044d696: { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d697: { // 0x44d697: e894742800 CALL 0x006d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4511388u); flags=s.arithmetic_flags;
  }
  L0044d69c: { // 0x44d69c: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L0044d69f: { // 0x44d69f: 7517 JNZ 0x0044d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX,byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0044d6a8: { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d6a9: { // 0x44d6a9: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0044d6ac: { // 0x44d6ac: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d6ae: { // 0x44d6ae: 7ce0 JL 0x0044d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d6b1: { // 0x44d6b1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044d6b3: { // 0x44d6b3: e8f8032800 CALL 0x006cdab0
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
  L0044d6bc: { // 0x44d6bc: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX,[EAX*0x8 + 0x0]
    s.dx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX,[ECX + EDX*0x4 + 0x74c]
    s.ax = (s.cx+(s.dx * 0x00000004u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x0062fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x0062fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI,0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX,0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x0062fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x0062fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI,EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x0062fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x0062fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x0062fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x0062fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI,dword ptr [EDX + ECX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX,[EDX + ECX*0x4 + 0xc]
    s.ax = (s.dx+(s.cx * 0x00000004u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX,dword ptr [EDX + ECX*0x4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI,dword ptr [EDX + EAX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX,0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x0062fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 0x4],0x0
    m.w32((s.dx+0x00000004u), 0x00000000u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX,0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x0062fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 0x8],0x0
    m.w32((s.dx+0x00000008u), 0x00000000u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX,EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x0062fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00052f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00452f60: { // 0x452f60: 8b8164050000 MOV EAX,dword ptr [ECX + 0x564]
    s.ax = m.r32((s.cx+0x00000564u));
  }
  L00452f66: { // 0x452f66: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4536464u:f_00053890(m,s,child,{});break;
case 7372640u:f_00307f60(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4534112u:f_00052f60(m,s,child,{});break;
default:throw std::domain_error("recovery892 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){switch(target){case 4536464u:f_00053890(m,s,f,{});return;case 7372640u:f_00307f60(m,s,f,{});return;case 7372768u:f_00307fe0(m,s,f,{});return;case 4511344u:f_0004d670(m,s,f,{});return;case 7162672u:f_002d4b30(m,s,f,{});return;case 6487616u:f_0022fe40(m,s,f,{});return;case 7776848u:f_0036aa50(m,s,f,{});return;case 4534112u:f_00052f60(m,s,f,{});return;default:throw std::domain_error("B892 unexpected tail target");}}}

std::uint32_t fun_006bf1d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006bf1d0: { // 0x6bf1d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf1d1: { // 0x6bf1d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006bf1d3: { // 0x6bf1d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006bf1d4: { // 0x6bf1d4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006bf1d6: { // 0x6bf1d6: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7074265u); flags=s.arithmetic_flags;
  }
  L006bf1d9: { // 0x6bf1d9: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006bf1dc: { // 0x6bf1dc: 7513 JNZ 0x006bf1f1
    if(integer::condition("JNZ",flags)) goto L006bf1f1;
  }
  L006bf1de: { // 0x6bf1de: 83be5402000001 CMP dword ptr [ESI + 0x254],0x1
    (void)integer::sub(m.r32((s.si+0x00000254u)),0x00000001u,32,flags);
  }
  L006bf1e5: { // 0x6bf1e5: 7e0a JLE 0x006bf1f1
    if(integer::condition("JLE",flags)) goto L006bf1f1;
  }
  L006bf1e7: { // 0x6bf1e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf1e8: { // 0x6bf1e8: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006bf1ed: { // 0x6bf1ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf1ee: { // 0x6bf1ee: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006bf1f1: { // 0x6bf1f1: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L006bf1f5: { // 0x6bf1f5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006bf1f7: { // 0x6bf1f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006bf1f8: { // 0x6bf1f8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bf1fa: { // 0x6bf1fa: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7074304u); flags=s.arithmetic_flags;
  }
  L006bf200: { // 0x6bf200: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L006bf202: { // 0x6bf202: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006bf204: { // 0x6bf204: 750a JNZ 0x006bf210
    if(integer::condition("JNZ",flags)) goto L006bf210;
  }
  L006bf206: { // 0x6bf206: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf207: { // 0x6bf207: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006bf20c: { // 0x6bf20c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf20d: { // 0x6bf20d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006bf210: { // 0x6bf210: 8a870c010000 MOV AL,byte ptr [EDI + 0x10c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000010cu)));
  }
  L006bf216: { // 0x6bf216: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf218: { // 0x6bf218: 0f858e010000 JNZ 0x006bf3ac
    if(integer::condition("JNZ",flags)) goto L006bf3ac;
  }
  L006bf21e: { // 0x6bf21e: 8a8706010000 MOV AL,byte ptr [EDI + 0x106]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000106u)));
  }
  L006bf224: { // 0x6bf224: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf226: { // 0x6bf226: 740e JZ 0x006bf236
    if(integer::condition("JZ",flags)) goto L006bf236;
  }
  L006bf228: { // 0x6bf228: 8b8660020000 MOV EAX,dword ptr [ESI + 0x260]
    s.ax = m.r32((s.si+0x00000260u));
  }
  L006bf22e: { // 0x6bf22e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf230: { // 0x6bf230: 0f8576010000 JNZ 0x006bf3ac
    if(integer::condition("JNZ",flags)) goto L006bf3ac;
  }
  L006bf236: { // 0x6bf236: 8a8705010000 MOV AL,byte ptr [EDI + 0x105]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000105u)));
  }
  L006bf23c: { // 0x6bf23c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf23e: { // 0x6bf23e: 740e JZ 0x006bf24e
    if(integer::condition("JZ",flags)) goto L006bf24e;
  }
  L006bf240: { // 0x6bf240: 8b865c020000 MOV EAX,dword ptr [ESI + 0x25c]
    s.ax = m.r32((s.si+0x0000025cu));
  }
  L006bf246: { // 0x6bf246: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf248: { // 0x6bf248: 0f855e010000 JNZ 0x006bf3ac
    if(integer::condition("JNZ",flags)) goto L006bf3ac;
  }
  L006bf24e: { // 0x6bf24e: 8a8709010000 MOV AL,byte ptr [EDI + 0x109]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000109u)));
  }
  L006bf254: { // 0x6bf254: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf256: { // 0x6bf256: 740e JZ 0x006bf266
    if(integer::condition("JZ",flags)) goto L006bf266;
  }
  L006bf258: { // 0x6bf258: 8b866c020000 MOV EAX,dword ptr [ESI + 0x26c]
    s.ax = m.r32((s.si+0x0000026cu));
  }
  L006bf25e: { // 0x6bf25e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf260: { // 0x6bf260: 0f8546010000 JNZ 0x006bf3ac
    if(integer::condition("JNZ",flags)) goto L006bf3ac;
  }
  L006bf266: { // 0x6bf266: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006bf268: { // 0x6bf268: 7504 JNZ 0x006bf26e
    if(integer::condition("JNZ",flags)) goto L006bf26e;
  }
  L006bf26a: { // 0x6bf26a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006bf26c: { // 0x6bf26c: eb10 JMP 0x006bf27e
    goto L006bf27e;
  }
  L006bf26e: { // 0x6bf26e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006bf270: { // 0x6bf270: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bf272: { // 0x6bf272: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7074421u); flags=s.arithmetic_flags;
  }
  L006bf275: { // 0x6bf275: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006bf276: { // 0x6bf276: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006bf278: { // 0x6bf278: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L006bf27a: { // 0x6bf27a: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L006bf27c: { // 0x6bf27c: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L006bf27e: { // 0x6bf27e: 8b8e10030000 MOV ECX,dword ptr [ESI + 0x310]
    s.cx = m.r32((s.si+0x00000310u));
  }
  L006bf284: { // 0x6bf284: 8b979c000000 MOV EDX,dword ptr [EDI + 0x9c]
    s.dx = m.r32((s.di+0x0000009cu));
  }
  L006bf28a: { // 0x6bf28a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006bf28c: { // 0x6bf28c: 7d40 JGE 0x006bf2ce
    if(integer::condition("JGE",flags)) goto L006bf2ce;
  }
  L006bf28e: { // 0x6bf28e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006bf290: { // 0x6bf290: 7e22 JLE 0x006bf2b4
    if(integer::condition("JLE",flags)) goto L006bf2b4;
  }
  L006bf292: { // 0x6bf292: 83f904 CMP ECX,0x4
    (void)integer::sub(s.cx,0x00000004u,32,flags);
  }
  L006bf295: { // 0x6bf295: 7f1d JG 0x006bf2b4
    if(integer::condition("JG",flags)) goto L006bf2b4;
  }
  L006bf297: { // 0x6bf297: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf299: { // 0x6bf299: 7419 JZ 0x006bf2b4
    if(integer::condition("JZ",flags)) goto L006bf2b4;
  }
  L006bf29b: { // 0x6bf29b: 8b80ac050000 MOV EAX,dword ptr [EAX + 0x5ac]
    s.ax = m.r32((s.ax+0x000005acu));
  }
  L006bf2a1: { // 0x6bf2a1: 8b8c88dc0b0000 MOV ECX,dword ptr [EAX + ECX*0x4 + 0xbdc]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)+0x00000bdcu));
  }
  L006bf2a8: { // 0x6bf2a8: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L006bf2ab: { // 0x6bf2ab: 7407 JZ 0x006bf2b4
    if(integer::condition("JZ",flags)) goto L006bf2b4;
  }
  L006bf2ad: { // 0x6bf2ad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf2ae: { // 0x6bf2ae: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006bf2b0: { // 0x6bf2b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf2b1: { // 0x6bf2b1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006bf2b4: { // 0x6bf2b4: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006bf2ba: { // 0x6bf2ba: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L006bf2bc: { // 0x6bf2bc: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L006bf2be: { // 0x6bf2be: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L006bf2c4: { // 0x6bf2c4: e8770bf7ff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,7074505u); flags=s.arithmetic_flags;
  }
  L006bf2c9: { // 0x6bf2c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf2ca: { // 0x6bf2ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf2cb: { // 0x6bf2cb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006bf2ce: { // 0x6bf2ce: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006bf2d4: { // 0x6bf2d4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006bf2d5: { // 0x6bf2d5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006bf2d6: { // 0x6bf2d6: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L006bf2d8: { // 0x6bf2d8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006bf2da: { // 0x6bf2da: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L006bf2e0: { // 0x6bf2e0: e85b0bf7ff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,7074533u); flags=s.arithmetic_flags;
  }
  L006bf2e5: { // 0x6bf2e5: db87b0000000 FILD dword ptr [EDI + 0xb0]
    const auto address=(s.di+0x000000b0u);
    s.fp.load_integer32(m.r32(address));
  }
  L006bf2eb: { // 0x6bf2eb: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006bf2ef: { // 0x6bf2ef: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006bf2f5: { // 0x6bf2f5: dc88f0000000 FMUL double ptr [EAX + 0xf0]
    const auto address=(s.ax+0x000000f0u);
    s.fp.multiply64(read64(m,address));
  }
  L006bf2fb: { // 0x6bf2fb: da442414 FIADD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006bf2ff: { // 0x6bf2ff: e84cb70a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7074564u); flags=s.arithmetic_flags;
  }
  L006bf304: { // 0x6bf304: 8dbe18010000 LEA EDI,[ESI + 0x118]
    s.di = (s.si+0x00000118u);
  }
  L006bf30a: { // 0x6bf30a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006bf30c: { // 0x6bf30c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bf30e: { // 0x6bf30e: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L006bf312: { // 0x6bf312: e8498c0400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7074583u); flags=s.arithmetic_flags;
  }
  L006bf317: { // 0x6bf317: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf319: { // 0x6bf319: 750b JNZ 0x006bf326
    if(integer::condition("JNZ",flags)) goto L006bf326;
  }
  L006bf31b: { // 0x6bf31b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bf31d: { // 0x6bf31d: e8be8c0400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7074594u); flags=s.arithmetic_flags;
  }
  L006bf322: { // 0x6bf322: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf324: { // 0x6bf324: 7456 JZ 0x006bf37c
    if(integer::condition("JZ",flags)) goto L006bf37c;
  }
  L006bf326: { // 0x6bf326: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006bf328: { // 0x6bf328: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bf32a: { // 0x6bf32a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7074608u); flags=s.arithmetic_flags;
  }
  L006bf330: { // 0x6bf330: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bf332: { // 0x6bf332: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006bf334: { // 0x6bf334: e8278c0400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7074617u); flags=s.arithmetic_flags;
  }
  L006bf339: { // 0x6bf339: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf33b: { // 0x6bf33b: 740a JZ 0x006bf347
    if(integer::condition("JZ",flags)) goto L006bf347;
  }
  L006bf33d: { // 0x6bf33d: 8a8370020000 MOV AL,byte ptr [EBX + 0x270]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000270u)));
  }
  L006bf343: { // 0x6bf343: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf345: { // 0x6bf345: 751f JNZ 0x006bf366
    if(integer::condition("JNZ",flags)) goto L006bf366;
  }
  L006bf347: { // 0x6bf347: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bf349: { // 0x6bf349: e8928c0400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7074638u); flags=s.arithmetic_flags;
  }
  L006bf34e: { // 0x6bf34e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf350: { // 0x6bf350: 742a JZ 0x006bf37c
    if(integer::condition("JZ",flags)) goto L006bf37c;
  }
  L006bf352: { // 0x6bf352: 8a8370020000 MOV AL,byte ptr [EBX + 0x270]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000270u)));
  }
  L006bf358: { // 0x6bf358: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf35a: { // 0x6bf35a: 750a JNZ 0x006bf366
    if(integer::condition("JNZ",flags)) goto L006bf366;
  }
  L006bf35c: { // 0x6bf35c: 8a8382020000 MOV AL,byte ptr [EBX + 0x282]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000282u)));
  }
  L006bf362: { // 0x6bf362: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf364: { // 0x6bf364: 7416 JZ 0x006bf37c
    if(integer::condition("JZ",flags)) goto L006bf37c;
  }
  L006bf366: { // 0x6bf366: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L006bf36a: { // 0x6bf36a: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006bf36f: { // 0x6bf36f: dc88b0050000 FMUL double ptr [EAX + 0x5b0]
    const auto address=(s.ax+0x000005b0u);
    s.fp.multiply64(read64(m,address));
  }
  L006bf375: { // 0x6bf375: e8d6b60a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7074682u); flags=s.arithmetic_flags;
  }
  L006bf37a: { // 0x6bf37a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006bf37c: { // 0x6bf37c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006bf37e: { // 0x6bf37e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bf380: { // 0x6bf380: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7074691u); flags=s.arithmetic_flags;
  }
  L006bf383: { // 0x6bf383: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006bf386: { // 0x6bf386: 751b JNZ 0x006bf3a3
    if(integer::condition("JNZ",flags)) goto L006bf3a3;
  }
  L006bf388: { // 0x6bf388: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bf38a: { // 0x6bf38a: e8d13bd9ff CALL 0x00452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7074703u); flags=s.arithmetic_flags;
  }
  L006bf38f: { // 0x6bf38f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf391: { // 0x6bf391: 7e10 JLE 0x006bf3a3
    if(integer::condition("JLE",flags)) goto L006bf3a3;
  }
  L006bf393: { // 0x6bf393: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bf395: { // 0x6bf395: e8c63bd9ff CALL 0x00452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7074714u); flags=s.arithmetic_flags;
  }
  L006bf39a: { // 0x6bf39a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006bf39c: { // 0x6bf39c: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L006bf39e: { // 0x6bf39e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006bf39f: { // 0x6bf39f: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006bf3a1: { // 0x6bf3a1: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006bf3a3: { // 0x6bf3a3: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L006bf3a5: { // 0x6bf3a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bf3a6: { // 0x6bf3a6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006bf3a7: { // 0x6bf3a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf3a8: { // 0x6bf3a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf3a9: { // 0x6bf3a9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006bf3ac: { // 0x6bf3ac: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  L006bf3b2: { // 0x6bf3b2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf3b3: { // 0x6bf3b3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf3b4: { // 0x6bf3b4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
