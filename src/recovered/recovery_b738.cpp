#include "recovered/recovery_b738_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b738 {
namespace {
void f_002744b0(Memory&,State&,Frame&,const Operations&);
void f_000829a0(Memory&,State&,Frame&,const Operations&);
void f_002741c0(Memory&,State&,Frame&,const Operations&);
void f_000ced20(Memory&,State&,Frame&,const Operations&);
void f_000ced30(Memory&,State&,Frame&,const Operations&);
void f_000ced40(Memory&,State&,Frame&,const Operations&);
void f_000cf1f0(Memory&,State&,Frame&,const Operations&);
void f_000e0030(Memory&,State&,Frame&,const Operations&);
void f_00157ab0(Memory&,State&,Frame&,const Operations&);
void f_002963f0(Memory&,State&,Frame&,const Operations&);
void f_002739b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002744b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006744b0: { // 0x6744b0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006744b3: { // 0x6744b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006744b4: { // 0x6744b4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006744b6: { // 0x6744b6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006744b7: { // 0x6744b7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L006744b9: { // 0x6744b9: 8b5350 MOV EDX,dword ptr [EBX + 0x50]
    s.dx = m.r32((s.bx+0x00000050u));
  }
  L006744bc: { // 0x6744bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006744bd: { // 0x6744bd: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006744be: { // 0x6744be: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006744bf: { // 0x6744bf: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006744c1: { // 0x6744c1: 895350 MOV dword ptr [EBX + 0x50],EDX
    m.w32((s.bx+0x00000050u), s.dx);
  }
  L006744c4: { // 0x6744c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006744c6: { // 0x6744c6: 0f8eaf000000 JLE 0x0067457b
    if(integer::condition("JLE",flags)) goto L0067457b;
  }
  L006744cc: { // 0x6744cc: 8d7354 LEA ESI,[EBX + 0x54]
    s.si = (s.bx+0x00000054u);
  }
  L006744cf: { // 0x6744cf: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L006744d1: { // 0x6744d1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L006744d4: { // 0x6744d4: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L006744d8: { // 0x6744d8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006744d9: { // 0x6744d9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006744da: { // 0x6744da: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L006744de: { // 0x6744de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006744df: { // 0x6744df: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006744e0: { // 0x6744e0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006744e2: { // 0x6744e2: e8d9fcffff CALL 0x006741c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006741c0u,6767847u); flags=s.arithmetic_flags;
  }
  L006744e7: { // 0x6744e7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006744e9: { // 0x6744e9: 7515 JNZ 0x00674500
    if(integer::condition("JNZ",flags)) goto L00674500;
  }
  L006744eb: { // 0x6744eb: 8b4350 MOV EAX,dword ptr [EBX + 0x50]
    s.ax = m.r32((s.bx+0x00000050u));
  }
  L006744ee: { // 0x6744ee: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L006744ef: { // 0x6744ef: 83c630 ADD ESI,0x30
    s.si = integer::add(s.si,0x00000030u,32,flags);
  }
  L006744f2: { // 0x6744f2: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L006744f4: { // 0x6744f4: 7cd9 JL 0x006744cf
    if(integer::condition("JL",flags)) goto L006744cf;
  }
  L006744f6: { // 0x6744f6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006744f7: { // 0x6744f7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006744f8: { // 0x6744f8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006744f9: { // 0x6744f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006744fa: { // 0x6744fa: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006744fd: { // 0x6744fd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00674500: { // 0x674500: 8b4350 MOV EAX,dword ptr [EBX + 0x50]
    s.ax = m.r32((s.bx+0x00000050u));
  }
  L00674503: { // 0x674503: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00674504: { // 0x674504: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00674506: { // 0x674506: 7e21 JLE 0x00674529
    if(integer::condition("JLE",flags)) goto L00674529;
  }
  L00674508: { // 0x674508: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L0067450b: { // 0x67450b: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0067450e: { // 0x67450e: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00674510: { // 0x674510: 8d7c1954 LEA EDI,[ECX + EBX*0x1 + 0x54]
    s.di = (s.cx+(s.bx * 0x00000001u)+0x00000054u);
  }
  L00674514: { // 0x674514: 8d57d0 LEA EDX,[EDI + -0x30]
    s.dx = (s.di-0x00000030u);
  }
  L00674517: { // 0x674517: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0067451c: { // 0x67451c: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0067451e: { // 0x67451e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0067451f: { // 0x67451f: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00674521: { // 0x674521: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00674523: { // 0x674523: 75ef JNZ 0x00674514
    if(integer::condition("JNZ",flags)) goto L00674514;
  }
  L00674525: { // 0x674525: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00674529: { // 0x674529: 8d546d00 LEA EDX,[EBP + EBP*0x2]
    s.dx = (s.bp+(s.bp * 0x00000002u));
  }
  L0067452d: { // 0x67452d: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L00674530: { // 0x674530: 83ff07 CMP EDI,0x7
    (void)integer::sub(s.di,0x00000007u,32,flags);
  }
  L00674533: { // 0x674533: 8d341a LEA ESI,[EDX + EBX*0x1]
    s.si = (s.dx+(s.bx * 0x00000001u));
  }
  L00674536: { // 0x674536: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0067453a: { // 0x67453a: 897e58 MOV dword ptr [ESI + 0x58],EDI
    m.w32((s.si+0x00000058u), s.di);
  }
  L0067453d: { // 0x67453d: 895654 MOV dword ptr [ESI + 0x54],EDX
    m.w32((s.si+0x00000054u), s.dx);
  }
  L00674540: { // 0x674540: 750a JNZ 0x0067454c
    if(integer::condition("JNZ",flags)) goto L0067454c;
  }
  L00674542: { // 0x674542: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00674544: { // 0x674544: e82765e7ff CALL 0x004eaa70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eaa70u,6767945u); flags=s.arithmetic_flags;
  }
  L00674549: { // 0x674549: 89465c MOV dword ptr [ESI + 0x5c],EAX
    m.w32((s.si+0x0000005cu), s.ax);
  }
  L0067454c: { // 0x67454c: 8d446d06 LEA EAX,[EBP + EBP*0x2 + 0x6]
    s.ax = (s.bp+(s.bp * 0x00000002u)+0x00000006u);
  }
  L00674550: { // 0x674550: 8d566c LEA EDX,[ESI + 0x6c]
    s.dx = (s.si+0x0000006cu);
  }
  L00674553: { // 0x674553: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00674556: { // 0x674556: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00674558: { // 0x674558: 890c18 MOV dword ptr [EAX + EBX*0x1],ECX
    m.w32((s.ax+(s.bx * 0x00000001u)), s.cx);
  }
  L0067455b: { // 0x67455b: 894e64 MOV dword ptr [ESI + 0x64],ECX
    m.w32((s.si+0x00000064u), s.cx);
  }
  L0067455e: { // 0x67455e: 894e68 MOV dword ptr [ESI + 0x68],ECX
    m.w32((s.si+0x00000068u), s.cx);
  }
  L00674561: { // 0x674561: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00674566: { // 0x674566: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L00674568: { // 0x674568: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0067456c: { // 0x67456c: 894e78 MOV dword ptr [ESI + 0x78],ECX
    m.w32((s.si+0x00000078u), s.cx);
  }
  L0067456f: { // 0x67456f: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L00674572: { // 0x674572: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00674575: { // 0x674575: 898e80000000 MOV dword ptr [ESI + 0x80],ECX
    m.w32((s.si+0x00000080u), s.cx);
  }
  L0067457b: { // 0x67457b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067457c: { // 0x67457c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067457d: { // 0x67457d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0067457e: { // 0x67457e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067457f: { // 0x67457f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674582: { // 0x674582: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000829a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004829a0: { // 0x4829a0: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L004829a3: { // 0x4829a3: 83f827 CMP EAX,0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  L004829a6: { // 0x4829a6: 7735 JA 0x004829dd
    if(integer::condition("JA",flags)) goto L004829dd;
  }
  L004829a8: { // 0x4829a8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004829aa: { // 0x4829aa: 8a88f4294800 MOV CL,byte ptr [EAX + 0x4829f4]
    constexpr unsigned char targets[]{0,1,1,4,4,2,2,4,4,4,4,4,4,4,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0};if(s.ax>=40)throw std::domain_error("738 class table bounds");s.cx=with_al(s.cx,targets[s.ax]);
  }
  L004829b0: { // 0x4829b0: ff248de0294800 JMP dword ptr [ECX*0x4 + 0x4829e0]
    const unsigned targets[]{0x4829b7,0x4829d3,0x4829c0,0x4829ca,0x4829dd};if(s.cx>=5)throw std::domain_error("738 target table bounds");switch(targets[s.cx]){
    case 0x004829a0u: goto L004829a0;
    case 0x004829a3u: goto L004829a3;
    case 0x004829a6u: goto L004829a6;
    case 0x004829a8u: goto L004829a8;
    case 0x004829aau: goto L004829aa;
    case 0x004829b0u: goto L004829b0;
    case 0x004829b7u: goto L004829b7;
    case 0x004829bcu: goto L004829bc;
    case 0x004829bfu: goto L004829bf;
    case 0x004829c0u: goto L004829c0;
    case 0x004829c6u: goto L004829c6;
    case 0x004829c9u: goto L004829c9;
    case 0x004829cau: goto L004829ca;
    case 0x004829cfu: goto L004829cf;
    case 0x004829d2u: goto L004829d2;
    case 0x004829d3u: goto L004829d3;
    case 0x004829d9u: goto L004829d9;
    case 0x004829dcu: goto L004829dc;
    case 0x004829ddu: goto L004829dd;
    case 0x004829dfu: goto L004829df;
    default:throw std::domain_error("recovery738 unsupported switch destination");}
  }
  L004829b7: { // 0x4829b7: a17ce0a100 MOV EAX,[0x00a1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  L004829bc: { // 0x4829bc: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004829bf: { // 0x4829bf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829c0: { // 0x4829c0: 8b0d0ce0a100 MOV ECX,dword ptr [0x00a1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  L004829c6: { // 0x4829c6: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L004829c9: { // 0x4829c9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829ca: { // 0x4829ca: a1a47fa200 MOV EAX,[0x00a27fa4]
    s.ax = m.r32((0x00a27fa4u));
  }
  L004829cf: { // 0x4829cf: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004829d2: { // 0x4829d2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829d3: { // 0x4829d3: 8b0dac55a200 MOV ECX,dword ptr [0x00a255ac]
    s.cx = m.r32((0x00a255acu));
  }
  L004829d9: { // 0x4829d9: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L004829dc: { // 0x4829dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829dd: { // 0x4829dd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004829df: { // 0x4829df: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002741c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006741c0: { // 0x6741c0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006741c3: { // 0x6741c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006741c4: { // 0x6741c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006741c5: { // 0x6741c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006741c6: { // 0x6741c6: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L006741ca: { // 0x6741ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006741cb: { // 0x6741cb: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L006741cf: { // 0x6741cf: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L006741d1: { // 0x6741d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006741d3: { // 0x6741d3: e8c8e7e0ff CALL 0x004829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,6767064u); flags=s.arithmetic_flags;
  }
  L006741d8: { // 0x6741d8: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L006741dc: { // 0x6741dc: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L006741e0: { // 0x6741e0: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L006741e2: { // 0x6741e2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006741e4: { // 0x6741e4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006741e8: { // 0x6741e8: e8b3e7e0ff CALL 0x004829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,6767085u); flags=s.arithmetic_flags;
  }
  L006741ed: { // 0x6741ed: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006741ef: { // 0x6741ef: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006741f1: { // 0x6741f1: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006741f5: { // 0x6741f5: 750c JNZ 0x00674203
    if(integer::condition("JNZ",flags)) goto L00674203;
  }
  L006741f7: { // 0x6741f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006741f8: { // 0x6741f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006741f9: { // 0x6741f9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006741fa: { // 0x6741fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006741fc: { // 0x6741fc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006741fd: { // 0x6741fd: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674200: { // 0x674200: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00674203: { // 0x674203: 83fe1f CMP ESI,0x1f
    (void)integer::sub(s.si,0x0000001fu,32,flags);
  }
  L00674206: { // 0x674206: 740f JZ 0x00674217
    if(integer::condition("JZ",flags)) goto L00674217;
  }
  L00674208: { // 0x674208: 83fe39 CMP ESI,0x39
    (void)integer::sub(s.si,0x00000039u,32,flags);
  }
  L0067420b: { // 0x67420b: 740a JZ 0x00674217
    if(integer::condition("JZ",flags)) goto L00674217;
  }
  L0067420d: { // 0x67420d: 83fe20 CMP ESI,0x20
    (void)integer::sub(s.si,0x00000020u,32,flags);
  }
  L00674210: { // 0x674210: c644242000 MOV byte ptr [ESP + 0x20],0x0
    m.w8((f.sp+0x00000020u), 0x00000000u);
  }
  L00674215: { // 0x674215: 7505 JNZ 0x0067421c
    if(integer::condition("JNZ",flags)) goto L0067421c;
  }
  L00674217: { // 0x674217: c644242001 MOV byte ptr [ESP + 0x20],0x1
    m.w8((f.sp+0x00000020u), 0x00000001u);
  }
  L0067421c: { // 0x67421c: 83fd1f CMP EBP,0x1f
    (void)integer::sub(s.bp,0x0000001fu,32,flags);
  }
  L0067421f: { // 0x67421f: 740e JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L00674221: { // 0x674221: 83fd39 CMP EBP,0x39
    (void)integer::sub(s.bp,0x00000039u,32,flags);
  }
  L00674224: { // 0x674224: 7409 JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L00674226: { // 0x674226: 83fd20 CMP EBP,0x20
    (void)integer::sub(s.bp,0x00000020u,32,flags);
  }
  L00674229: { // 0x674229: 7404 JZ 0x0067422f
    if(integer::condition("JZ",flags)) goto L0067422f;
  }
  L0067422b: { // 0x67422b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0067422d: { // 0x67422d: eb02 JMP 0x00674231
    goto L00674231;
  }
  L0067422f: { // 0x67422f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674231: { // 0x674231: 8a4c2420 MOV CL,byte ptr [ESP + 0x20]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000020u)));
  }
  L00674235: { // 0x674235: 88442424 MOV byte ptr [ESP + 0x24],AL
    m.w8((f.sp+0x00000024u), (s.ax & 0xffu));
  }
  L00674239: { // 0x674239: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0067423b: { // 0x67423b: 7449 JZ 0x00674286
    if(integer::condition("JZ",flags)) goto L00674286;
  }
  L0067423d: { // 0x67423d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067423f: { // 0x67423f: 0f8491000000 JZ 0x006742d6
    if(integer::condition("JZ",flags)) goto L006742d6;
  }
  L00674245: { // 0x674245: 8b0d8c7fa200 MOV ECX,dword ptr [0x00a27f8c]
    s.cx = m.r32((0x00a27f8cu));
  }
  L0067424b: { // 0x67424b: 8b04b9 MOV EAX,dword ptr [ECX + EDI*0x4]
    s.ax = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L0067424e: { // 0x67424e: 8b0c99 MOV ECX,dword ptr [ECX + EBX*0x4]
    s.cx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L00674251: { // 0x674251: 8b90b0000000 MOV EDX,dword ptr [EAX + 0xb0]
    s.dx = m.r32((s.ax+0x000000b0u));
  }
  L00674257: { // 0x674257: 8bb1b0000000 MOV ESI,dword ptr [ECX + 0xb0]
    s.si = m.r32((s.cx+0x000000b0u));
  }
  L0067425d: { // 0x67425d: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0067425f: { // 0x67425f: 7d0c JGE 0x0067426d
    if(integer::condition("JGE",flags)) goto L0067426d;
  }
  L00674261: { // 0x674261: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674262: { // 0x674262: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674263: { // 0x674263: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674264: { // 0x674264: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674266: { // 0x674266: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674267: { // 0x674267: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067426a: { // 0x67426a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067426d: { // 0x67426d: 7e0c JLE 0x0067427b
    if(integer::condition("JLE",flags)) goto L0067427b;
  }
  L0067426f: { // 0x67426f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674270: { // 0x674270: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674271: { // 0x674271: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674272: { // 0x674272: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674274: { // 0x674274: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674275: { // 0x674275: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674278: { // 0x674278: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067427b: { // 0x67427b: 8b4060 MOV EAX,dword ptr [EAX + 0x60]
    s.ax = m.r32((s.ax+0x00000060u));
  }
  L0067427e: { // 0x67427e: 8b4960 MOV ECX,dword ptr [ECX + 0x60]
    s.cx = m.r32((s.cx+0x00000060u));
  }
  L00674281: { // 0x674281: e90d020000 JMP 0x00674493
    goto L00674493;
  }
  L00674286: { // 0x674286: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674288: { // 0x674288: 754c JNZ 0x006742d6
    if(integer::condition("JNZ",flags)) goto L006742d6;
  }
  L0067428a: { // 0x67428a: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0067428f: { // 0x67428f: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00674293: { // 0x674293: 8b9aec050000 MOV EBX,dword ptr [EDX + 0x5ec]
    s.bx = m.r32((s.dx+0x000005ecu));
  }
  L00674299: { // 0x674299: 8b4834 MOV ECX,dword ptr [EAX + 0x34]
    s.cx = m.r32((s.ax+0x00000034u));
  }
  L0067429c: { // 0x67429c: 8b81bc000000 MOV EAX,dword ptr [ECX + 0xbc]
    s.ax = m.r32((s.cx+0x000000bcu));
  }
  L006742a2: { // 0x6742a2: 8b8fec050000 MOV ECX,dword ptr [EDI + 0x5ec]
    s.cx = m.r32((s.di+0x000005ecu));
  }
  L006742a8: { // 0x6742a8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006742aa: { // 0x6742aa: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006742ad: { // 0x6742ad: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006742af: { // 0x6742af: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006742b2: { // 0x6742b2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006742b4: { // 0x6742b4: 7410 JZ 0x006742c6
    if(integer::condition("JZ",flags)) goto L006742c6;
  }
  L006742b6: { // 0x6742b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742b8: { // 0x6742b8: 7520 JNZ 0x006742da
    if(integer::condition("JNZ",flags)) goto L006742da;
  }
  L006742ba: { // 0x6742ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006742bb: { // 0x6742bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006742bc: { // 0x6742bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006742bd: { // 0x6742bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006742bf: { // 0x6742bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006742c0: { // 0x6742c0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006742c3: { // 0x6742c3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006742c6: { // 0x6742c6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742c8: { // 0x6742c8: 7410 JZ 0x006742da
    if(integer::condition("JZ",flags)) goto L006742da;
  }
  L006742ca: { // 0x6742ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006742cb: { // 0x6742cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006742cc: { // 0x6742cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006742cd: { // 0x6742cd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006742cf: { // 0x6742cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006742d0: { // 0x6742d0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006742d3: { // 0x6742d3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006742d6: { // 0x6742d6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L006742da: { // 0x6742da: 83fe28 CMP ESI,0x28
    (void)integer::sub(s.si,0x00000028u,32,flags);
  }
  L006742dd: { // 0x6742dd: 741f JZ 0x006742fe
    if(integer::condition("JZ",flags)) goto L006742fe;
  }
  L006742df: { // 0x6742df: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L006742e2: { // 0x6742e2: 741a JZ 0x006742fe
    if(integer::condition("JZ",flags)) goto L006742fe;
  }
  L006742e4: { // 0x6742e4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006742e6: { // 0x6742e6: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L006742e8: { // 0x6742e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742ea: { // 0x6742ea: 884c2428 MOV byte ptr [ESP + 0x28],CL
    m.w8((f.sp+0x00000028u), (s.cx & 0xffu));
  }
  L006742ee: { // 0x6742ee: 7422 JZ 0x00674312
    if(integer::condition("JZ",flags)) goto L00674312;
  }
  L006742f0: { // 0x6742f0: 8a87da0a0000 MOV AL,byte ptr [EDI + 0xada]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000adau)));
  }
  L006742f6: { // 0x6742f6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006742f8: { // 0x6742f8: 7418 JZ 0x00674312
    if(integer::condition("JZ",flags)) goto L00674312;
  }
  L006742fa: { // 0x6742fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006742fc: { // 0x6742fc: eb16 JMP 0x00674314
    goto L00674314;
  }
  L006742fe: { // 0x6742fe: 8a8f460b0000 MOV CL,byte ptr [EDI + 0xb46]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000b46u)));
  }
  L00674304: { // 0x674304: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674306: { // 0x674306: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674308: { // 0x674308: 74dc JZ 0x006742e6
    if(integer::condition("JZ",flags)) goto L006742e6;
  }
  L0067430a: { // 0x67430a: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L0067430c: { // 0x67430c: 884c2428 MOV byte ptr [ESP + 0x28],CL
    m.w8((f.sp+0x00000028u), (s.cx & 0xffu));
  }
  L00674310: { // 0x674310: ebde JMP 0x006742f0
    goto L006742f0;
  }
  L00674312: { // 0x674312: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674314: { // 0x674314: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674316: { // 0x674316: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L0067431a: { // 0x67431a: 7509 JNZ 0x00674325
    if(integer::condition("JNZ",flags)) goto L00674325;
  }
  L0067431c: { // 0x67431c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067431e: { // 0x67431e: c644242c01 MOV byte ptr [ESP + 0x2c],0x1
    m.w8((f.sp+0x0000002cu), 0x00000001u);
  }
  L00674323: { // 0x674323: 7405 JZ 0x0067432a
    if(integer::condition("JZ",flags)) goto L0067432a;
  }
  L00674325: { // 0x674325: c644242c00 MOV byte ptr [ESP + 0x2c],0x0
    m.w8((f.sp+0x0000002cu), 0x00000000u);
  }
  L0067432a: { // 0x67432a: 83fd28 CMP EBP,0x28
    (void)integer::sub(s.bp,0x00000028u,32,flags);
  }
  L0067432d: { // 0x67432d: 741f JZ 0x0067434e
    if(integer::condition("JZ",flags)) goto L0067434e;
  }
  L0067432f: { // 0x67432f: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L00674332: { // 0x674332: 741a JZ 0x0067434e
    if(integer::condition("JZ",flags)) goto L0067434e;
  }
  L00674334: { // 0x674334: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674336: { // 0x674336: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L00674338: { // 0x674338: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067433a: { // 0x67433a: 7422 JZ 0x0067435e
    if(integer::condition("JZ",flags)) goto L0067435e;
  }
  L0067433c: { // 0x67433c: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00674340: { // 0x674340: 8a85da0a0000 MOV AL,byte ptr [EBP + 0xada]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000adau)));
  }
  L00674346: { // 0x674346: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674348: { // 0x674348: 7418 JZ 0x00674362
    if(integer::condition("JZ",flags)) goto L00674362;
  }
  L0067434a: { // 0x67434a: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L0067434c: { // 0x67434c: eb16 JMP 0x00674364
    goto L00674364;
  }
  L0067434e: { // 0x67434e: 8a8a460b0000 MOV CL,byte ptr [EDX + 0xb46]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000b46u)));
  }
  L00674354: { // 0x674354: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674356: { // 0x674356: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674358: { // 0x674358: 74dc JZ 0x00674336
    if(integer::condition("JZ",flags)) goto L00674336;
  }
  L0067435a: { // 0x67435a: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0067435c: { // 0x67435c: ebde JMP 0x0067433c
    goto L0067433c;
  }
  L0067435e: { // 0x67435e: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00674362: { // 0x674362: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L00674364: { // 0x674364: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00674366: { // 0x674366: 7508 JNZ 0x00674370
    if(integer::condition("JNZ",flags)) goto L00674370;
  }
  L00674368: { // 0x674368: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0067436a: { // 0x67436a: 7504 JNZ 0x00674370
    if(integer::condition("JNZ",flags)) goto L00674370;
  }
  L0067436c: { // 0x67436c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0067436e: { // 0x67436e: eb02 JMP 0x00674372
    goto L00674372;
  }
  L00674370: { // 0x674370: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674372: { // 0x674372: 8a5c2420 MOV BL,byte ptr [ESP + 0x20]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000020u)));
  }
  L00674376: { // 0x674376: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00674378: { // 0x674378: 741c JZ 0x00674396
    if(integer::condition("JZ",flags)) goto L00674396;
  }
  L0067437a: { // 0x67437a: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0067437c: { // 0x67437c: 750c JNZ 0x0067438a
    if(integer::condition("JNZ",flags)) goto L0067438a;
  }
  L0067437e: { // 0x67437e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674380: { // 0x674380: 7508 JNZ 0x0067438a
    if(integer::condition("JNZ",flags)) goto L0067438a;
  }
  L00674382: { // 0x674382: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674384: { // 0x674384: 0f8498000000 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L0067438a: { // 0x67438a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067438b: { // 0x67438b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067438c: { // 0x67438c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0067438d: { // 0x67438d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0067438f: { // 0x67438f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674390: { // 0x674390: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674393: { // 0x674393: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00674396: { // 0x674396: 8a5c242c MOV BL,byte ptr [ESP + 0x2c]
    s.bx = with_al(s.bx, m.r8((f.sp+0x0000002cu)));
  }
  L0067439a: { // 0x67439a: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0067439c: { // 0x67439c: 7428 JZ 0x006743c6
    if(integer::condition("JZ",flags)) goto L006743c6;
  }
  L0067439e: { // 0x67439e: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L006743a2: { // 0x6743a2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006743a4: { // 0x6743a4: 740c JZ 0x006743b2
    if(integer::condition("JZ",flags)) goto L006743b2;
  }
  L006743a6: { // 0x6743a6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743a7: { // 0x6743a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743a8: { // 0x6743a8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743a9: { // 0x6743a9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743ab: { // 0x6743ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743ac: { // 0x6743ac: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743af: { // 0x6743af: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743b2: { // 0x6743b2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006743b4: { // 0x6743b4: 7504 JNZ 0x006743ba
    if(integer::condition("JNZ",flags)) goto L006743ba;
  }
  L006743b6: { // 0x6743b6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006743b8: { // 0x6743b8: 7468 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L006743ba: { // 0x6743ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743bb: { // 0x6743bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743bc: { // 0x6743bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743bd: { // 0x6743bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006743bf: { // 0x6743bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743c0: { // 0x6743c0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743c3: { // 0x6743c3: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743c6: { // 0x6743c6: 8a5c2428 MOV BL,byte ptr [ESP + 0x28]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000028u)));
  }
  L006743ca: { // 0x6743ca: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006743cc: { // 0x6743cc: 7424 JZ 0x006743f2
    if(integer::condition("JZ",flags)) goto L006743f2;
  }
  L006743ce: { // 0x6743ce: 8a542424 MOV DL,byte ptr [ESP + 0x24]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000024u)));
  }
  L006743d2: { // 0x6743d2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006743d4: { // 0x6743d4: 740c JZ 0x006743e2
    if(integer::condition("JZ",flags)) goto L006743e2;
  }
  L006743d6: { // 0x6743d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743d7: { // 0x6743d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743d8: { // 0x6743d8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743d9: { // 0x6743d9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743db: { // 0x6743db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743dc: { // 0x6743dc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743df: { // 0x6743df: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743e2: { // 0x6743e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006743e4: { // 0x6743e4: 74d0 JZ 0x006743b6
    if(integer::condition("JZ",flags)) goto L006743b6;
  }
  L006743e6: { // 0x6743e6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006743e7: { // 0x6743e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006743e8: { // 0x6743e8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006743e9: { // 0x6743e9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006743eb: { // 0x6743eb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006743ec: { // 0x6743ec: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006743ef: { // 0x6743ef: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L006743f2: { // 0x6743f2: 8a4c2413 MOV CL,byte ptr [ESP + 0x13]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000013u)));
  }
  L006743f6: { // 0x6743f6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006743f8: { // 0x6743f8: 7428 JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L006743fa: { // 0x6743fa: 8a4c2424 MOV CL,byte ptr [ESP + 0x24]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000024u)));
  }
  L006743fe: { // 0x6743fe: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00674400: { // 0x674400: 740c JZ 0x0067440e
    if(integer::condition("JZ",flags)) goto L0067440e;
  }
  L00674402: { // 0x674402: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674403: { // 0x674403: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674404: { // 0x674404: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674405: { // 0x674405: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674407: { // 0x674407: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674408: { // 0x674408: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067440b: { // 0x67440b: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067440e: { // 0x67440e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00674410: { // 0x674410: 7504 JNZ 0x00674416
    if(integer::condition("JNZ",flags)) goto L00674416;
  }
  L00674412: { // 0x674412: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00674414: { // 0x674414: 740c JZ 0x00674422
    if(integer::condition("JZ",flags)) goto L00674422;
  }
  L00674416: { // 0x674416: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674417: { // 0x674417: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674418: { // 0x674418: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674419: { // 0x674419: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0067441b: { // 0x67441b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067441c: { // 0x67441c: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067441f: { // 0x67441f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00674422: { // 0x674422: 8b875c050000 MOV EAX,dword ptr [EDI + 0x55c]
    s.ax = m.r32((s.di+0x0000055cu));
  }
  L00674428: { // 0x674428: 8b8d5c050000 MOV ECX,dword ptr [EBP + 0x55c]
    s.cx = m.r32((s.bp+0x0000055cu));
  }
  L0067442e: { // 0x67442e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00674430: { // 0x674430: 7d0c JGE 0x0067443e
    if(integer::condition("JGE",flags)) goto L0067443e;
  }
  L00674432: { // 0x674432: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674433: { // 0x674433: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674434: { // 0x674434: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674435: { // 0x674435: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674437: { // 0x674437: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674438: { // 0x674438: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067443b: { // 0x67443b: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067443e: { // 0x67443e: 7e0c JLE 0x0067444c
    if(integer::condition("JLE",flags)) goto L0067444c;
  }
  L00674440: { // 0x674440: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674441: { // 0x674441: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674442: { // 0x674442: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674443: { // 0x674443: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674445: { // 0x674445: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674446: { // 0x674446: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00674449: { // 0x674449: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067444c: { // 0x67444c: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00674451: { // 0x674451: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00674453: { // 0x674453: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674454: { // 0x674454: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00674456: { // 0x674456: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6767708u); flags=s.arithmetic_flags;
  }
  L0067445c: { // 0x67445c: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0067445f: { // 0x67445f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00674461: { // 0x674461: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00674466: { // 0x674466: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00674468: { // 0x674468: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674469: { // 0x674469: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6767727u); flags=s.arithmetic_flags;
  }
  L0067446f: { // 0x67446f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00674471: { // 0x674471: 7d0c JGE 0x0067447f
    if(integer::condition("JGE",flags)) goto L0067447f;
  }
  L00674473: { // 0x674473: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674474: { // 0x674474: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674475: { // 0x674475: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674476: { // 0x674476: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00674478: { // 0x674478: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674479: { // 0x674479: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067447c: { // 0x67447c: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067447f: { // 0x67447f: 7e0c JLE 0x0067448d
    if(integer::condition("JLE",flags)) goto L0067448d;
  }
  L00674481: { // 0x674481: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00674482: { // 0x674482: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00674483: { // 0x674483: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00674484: { // 0x674484: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00674486: { // 0x674486: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00674487: { // 0x674487: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067448a: { // 0x67448a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0067448d: { // 0x67448d: 8b4760 MOV EAX,dword ptr [EDI + 0x60]
    s.ax = m.r32((s.di+0x00000060u));
  }
  L00674490: { // 0x674490: 8b4d60 MOV ECX,dword ptr [EBP + 0x60]
    s.cx = m.r32((s.bp+0x00000060u));
  }
  L00674493: { // 0x674493: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00674494: { // 0x674494: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00674495: { // 0x674495: e879ac0f00 CALL 0x0076f113
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f113u,6767770u); flags=s.arithmetic_flags;
  }
  L0067449a: { // 0x67449a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0067449d: { // 0x67449d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0067449f: { // 0x67449f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006744a0: { // 0x6744a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006744a1: { // 0x6744a1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006744a2: { // 0x6744a2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006744a3: { // 0x6744a3: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L006744a6: { // 0x6744a6: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006744a9: { // 0x6744a9: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_000ced20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced20: { // 0x4ced20: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ced22: { // 0x4ced22: c6411e00 MOV byte ptr [ECX + 0x1e], 0
    m.w8((s.cx+0x0000001eu), 0u);
  }
  L004ced26: { // 0x4ced26: c6411c01 MOV byte ptr [ECX + 0x1c], 1
    m.w8((s.cx+0x0000001cu), 1u);
  }
  L004ced2a: {if(m.r32(s.ax+0x54)!=0x4cf1f0)throw std::domain_error("738 unprovedtail");s.arithmetic_flags=flags;f_000cf1f0(m,s,f,op);return;
  }
}
void f_000ced30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced30: { // 0x4ced30: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004ced32: { // 0x4ced32: 88411e MOV byte ptr [ECX + 0x1e], AL
    m.w8((s.cx+0x0000001eu), (s.ax & 0xffu));
  }
  L004ced35: { // 0x4ced35: 88411c MOV byte ptr [ECX + 0x1c], AL
    m.w8((s.cx+0x0000001cu), (s.ax & 0xffu));
  }
  L004ced38: { // 0x4ced38: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ced3a: {if(m.r32(s.ax+0x54)!=0x4cf1f0)throw std::domain_error("738 unprovedtail");s.arithmetic_flags=flags;f_000cf1f0(m,s,f,op);return;
  }
}
void f_000ced40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced40: { // 0x4ced40: 8a511e MOV DL, byte ptr [ECX + 0x1e]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000001eu)));
  }
  L004ced43: { // 0x4ced43: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ced45: { // 0x4ced45: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004ced47: { // 0x4ced47: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004ced4a: { // 0x4ced4a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000cf1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cf1f0: { // 0x4cf1f0: 390d28e38400 CMP dword ptr [0x84e328], ECX
    (void)integer::sub(m.r32((0x0084e328u)),s.cx,32,flags);
  }
  L004cf1f6: { // 0x4cf1f6: 7513 JNZ 0x4cf20b
    if(integer::condition("JNZ",flags)) goto L004cf20b;
  }
  L004cf1f8: { // 0x4cf1f8: 8b4120 MOV EAX, dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  L004cf1fb: { // 0x4cf1fb: 80e4fe AND AH, 0xfe
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000feu),8,flags)) & 0xffu) << 8);
  }
  L004cf1fe: { // 0x4cf1fe: 894120 MOV dword ptr [ECX + 0x20], EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L004cf201: { // 0x4cf201: c70528e3840000000000 MOV dword ptr [0x84e328], 0
    m.w32((0x0084e328u), 0u);
  }
  L004cf20b: { // 0x4cf20b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e0030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0030: { // 0x4e0030: a1ac1c8200 MOV EAX, dword ptr [0x821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L004e0035: { // 0x4e0035: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0037: { // 0x4e0037: 7407 JZ 0x4e0040
    if(integer::condition("JZ",flags)) goto L004e0040;
  }
  L004e0039: { // 0x4e0039: c6807d0d000001 MOV byte ptr [EAX + 0xd7d], 1
    m.w8((s.ax+0x00000d7du), 1u);
  }
  L004e0040: { // 0x4e0040: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004e0044: { // 0x4e0044: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0046: { // 0x4e0046: 7413 JZ 0x4e005b
    if(integer::condition("JZ",flags)) goto L004e005b;
  }
  L004e0048: { // 0x4e0048: 83790c02 CMP dword ptr [ECX + 0xc], 2
    (void)integer::sub(m.r32((s.cx+0x0000000cu)),2u,32,flags);
  }
  L004e004c: { // 0x4e004c: 7403 JZ 0x4e0051
    if(integer::condition("JZ",flags)) goto L004e0051;
  }
  L004e004e: { // 0x4e004e: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004e0051: { // 0x4e0051: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e0056: { // 0x4e0056: e8557a0700 CALL 0x557ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557ab0u,5111899u); flags=s.arithmetic_flags;
  }
  L004e005b: { // 0x4e005b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557ab0: { // 0x557ab0: fe8154110000 INC byte ptr [ECX + 0x1154]
    m.w8((s.cx+0x00001154u), integer::increment(m.r8((s.cx+0x00001154u)),8,flags));
  }
  L00557ab6: { // 0x557ab6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002963f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006963f0: { // 0x6963f0: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006963f4: { // 0x6963f4: 83ec1c SUB ESP, 0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L006963f7: { // 0x6963f7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006963f8: { // 0x6963f8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006963f9: { // 0x6963f9: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006963fb: { // 0x6963fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006963fc: { // 0x6963fc: e8afd5fdff CALL 0x6739b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006739b0u,6906881u); flags=s.arithmetic_flags;
  }
  L00696401: { // 0x696401: 8ad8 MOV BL, AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L00696403: { // 0x696403: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00696405: { // 0x696405: 0f8467010000 JZ 0x696572
    if(integer::condition("JZ",flags)) goto L00696572;
  }
  L0069640b: { // 0x69640b: 8a86e14e0000 MOV AL, byte ptr [ESI + 0x4ee1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00004ee1u)));
  }
  L00696411: { // 0x696411: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00696413: { // 0x696413: 8a86144f0000 MOV AL, byte ptr [ESI + 0x4f14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00004f14u)));
  }
  L00696419: { // 0x696419: 0f84a4000000 JZ 0x6964c3
    if(integer::condition("JZ",flags)) goto L006964c3;
  }
  L0069641f: { // 0x69641f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00696421: { // 0x696421: 741a JZ 0x69643d
    if(integer::condition("JZ",flags)) goto L0069643d;
  }
  L00696423: { // 0x696423: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00696425: { // 0x696425: e8c60c0000 CALL 0x6970f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006970f0u,6906922u); flags=s.arithmetic_flags;
  }
  L0069642a: { // 0x69642a: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0069642c: { // 0x69642c: 6a02 PUSH 2
    f.push(m,2u);
  }
  L0069642e: { // 0x69642e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00696430: { // 0x696430: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6906931u); flags=s.arithmetic_flags;
  }
  L00696433: { // 0x696433: 8ac3 MOV AL, BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L00696435: { // 0x696435: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00696436: { // 0x696436: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00696437: { // 0x696437: 83c41c ADD ESP, 0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L0069643a: { // 0x69643a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0069643d: { // 0x69643d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069643f: { // 0x69643f: 68985eaa00 PUSH 0xaa5e98
    f.push(m,0x00aa5e98u);
  }
  L00696444: { // 0x696444: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00696446: { // 0x696446: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6906953u); flags=s.arithmetic_flags;
  }
  L00696449: { // 0x696449: b8985eaa00 MOV EAX, 0xaa5e98
    s.ax = 0x00aa5e98u;
  }
  L0069644e: { // 0x69644e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00696450: { // 0x696450: 0f8413010000 JZ 0x696569
    if(integer::condition("JZ",flags)) goto L00696569;
  }
  L00696456: { // 0x696456: 8b0da45eaa00 MOV ECX, dword ptr [0xaa5ea4]
    s.cx = m.r32((0x00aa5ea4u));
  }
  L0069645c: { // 0x69645c: 8b15a85eaa00 MOV EDX, dword ptr [0xaa5ea8]
    s.dx = m.r32((0x00aa5ea8u));
  }
  L00696462: { // 0x696462: a1bc5eaa00 MOV EAX, dword ptr [0xaa5ebc]
    s.ax = m.r32((0x00aa5ebcu));
  }
  L00696467: { // 0x696467: 894c240c MOV dword ptr [ESP + 0xc], ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0069646b: { // 0x69646b: 8b0dac5eaa00 MOV ECX, dword ptr [0xaa5eac]
    s.cx = m.r32((0x00aa5eacu));
  }
  L00696471: { // 0x696471: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00696475: { // 0x696475: 8b15b05eaa00 MOV EDX, dword ptr [0xaa5eb0]
    s.dx = m.r32((0x00aa5eb0u));
  }
  L0069647b: { // 0x69647b: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0069647f: { // 0x69647f: 8b0df01c8200 MOV ECX, dword ptr [0x821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  L00696485: { // 0x696485: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00696486: { // 0x696486: c644242400 MOV byte ptr [ESP + 0x24], 0
    m.w8((f.sp+0x00000024u), 0u);
  }
  L0069648b: { // 0x69648b: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L0069648f: { // 0x69648f: c7442420f0007e00 MOV dword ptr [ESP + 0x20], 0x7e00f0
    m.w32((f.sp+0x00000020u), 0x007e00f0u);
  }
  L00696497: { // 0x696497: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069649b: { // 0x69649b: e830a80400 CALL 0x6e0cd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0cd0u,6907040u); flags=s.arithmetic_flags;
  }
  L006964a0: { // 0x6964a0: 8b0df01c8200 MOV ECX, dword ptr [0x821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  L006964a6: { // 0x6964a6: 8d442408 LEA EAX, [ESP + 8]
    s.ax = (f.sp+8u);
  }
  L006964aa: { // 0x6964aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006964ab: { // 0x6964ab: e870a60400 CALL 0x6e0b20
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0b20u,6907056u); flags=s.arithmetic_flags;
  }
  L006964b0: { // 0x6964b0: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006964b2: { // 0x6964b2: 6a02 PUSH 2
    f.push(m,2u);
  }
  L006964b4: { // 0x6964b4: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006964b6: { // 0x6964b6: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6907065u); flags=s.arithmetic_flags;
  }
  L006964b9: { // 0x6964b9: 8ac3 MOV AL, BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L006964bb: { // 0x6964bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006964bc: { // 0x6964bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006964bd: { // 0x6964bd: 83c41c ADD ESP, 0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006964c0: { // 0x6964c0: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006964c3: { // 0x6964c3: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006964c5: { // 0x6964c5: 0f8482000000 JZ 0x69654d
    if(integer::condition("JZ",flags)) goto L0069654d;
  }
  L006964cb: { // 0x6964cb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006964cc: { // 0x6964cc: bf2054aa00 MOV EDI, 0xaa5420
    s.di = 0x00aa5420u;
  }
  L006964d1: { // 0x6964d1: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006964d3: { // 0x6964d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006964d4: { // 0x6964d4: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006964d6: { // 0x6964d6: ff5234 CALL dword ptr [EDX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000034u)),6907097u); flags=s.arithmetic_flags;
  }
  L006964d9: { // 0x6964d9: 83c760 ADD EDI, 0x60
    s.di = integer::add(s.di,0x00000060u,32,flags);
  }
  L006964dc: { // 0x6964dc: 81ff805daa00 CMP EDI, 0xaa5d80
    (void)integer::sub(s.di,0x00aa5d80u,32,flags);
  }
  L006964e2: { // 0x6964e2: 7ced JL 0x6964d1
    if(integer::condition("JL",flags)) goto L006964d1;
  }
  L006964e4: { // 0x6964e4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006964e6: { // 0x6964e6: 68085faa00 PUSH 0xaa5f08
    f.push(m,0x00aa5f08u);
  }
  L006964eb: { // 0x6964eb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006964ed: { // 0x6964ed: ff5034 CALL dword ptr [EAX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000034u)),6907120u); flags=s.arithmetic_flags;
  }
  L006964f0: { // 0x6964f0: bfd05daa00 MOV EDI, 0xaa5dd0
    s.di = 0x00aa5dd0u;
  }
  L006964f5: { // 0x6964f5: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006964f7: { // 0x6964f7: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006964f9: { // 0x6964f9: 7c23 JL 0x69651e
    if(integer::condition("JL",flags)) goto L0069651e;
  }
  L006964fb: { // 0x6964fb: 83f819 CMP EAX, 0x19
    (void)integer::sub(s.ax,0x00000019u,32,flags);
  }
  L006964fe: { // 0x6964fe: 7d1e JGE 0x69651e
    if(integer::condition("JGE",flags)) goto L0069651e;
  }
  L00696500: { // 0x696500: 8d0440 LEA EAX, [EAX + EAX*2]
    s.ax = (s.ax+(s.ax * 2u));
  }
  L00696503: { // 0x696503: c1e005 SHL EAX, 5
    s.ax = integer::shift(s.ax,5u,32,flags,integer::Shift::left);
  }
  L00696506: { // 0x696506: 052054aa00 ADD EAX, 0xaa5420
    s.ax = integer::add(s.ax,0x00aa5420u,32,flags);
  }
  L0069650b: { // 0x69650b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0069650d: { // 0x69650d: 740f JZ 0x69651e
    if(integer::condition("JZ",flags)) goto L0069651e;
  }
  L0069650f: { // 0x69650f: 8b4824 MOV ECX, dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L00696512: { // 0x696512: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00696513: { // 0x696513: 8b0df01c8200 MOV ECX, dword ptr [0x821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  L00696519: { // 0x696519: e8b2a70400 CALL 0x6e0cd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0cd0u,6907166u); flags=s.arithmetic_flags;
  }
  L0069651e: { // 0x69651e: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L00696521: { // 0x696521: 81ff345eaa00 CMP EDI, 0xaa5e34
    (void)integer::sub(s.di,0x00aa5e34u,32,flags);
  }
  L00696527: { // 0x696527: 7ccc JL 0x6964f5
    if(integer::condition("JL",flags)) goto L006964f5;
  }
  L00696529: { // 0x696529: 8b0df01c8200 MOV ECX, dword ptr [0x821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  L0069652f: { // 0x69652f: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  L00696534: { // 0x696534: e897a70400 CALL 0x6e0cd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0cd0u,6907193u); flags=s.arithmetic_flags;
  }
  L00696539: { // 0x696539: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0069653b: { // 0x69653b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069653c: { // 0x69653c: 6a02 PUSH 2
    f.push(m,2u);
  }
  L0069653e: { // 0x69653e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00696540: { // 0x696540: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6907203u); flags=s.arithmetic_flags;
  }
  L00696543: { // 0x696543: 8ac3 MOV AL, BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L00696545: { // 0x696545: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00696546: { // 0x696546: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00696547: { // 0x696547: 83c41c ADD ESP, 0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L0069654a: { // 0x69654a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0069654d: { // 0x69654d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069654f: { // 0x69654f: 68985eaa00 PUSH 0xaa5e98
    f.push(m,0x00aa5e98u);
  }
  L00696554: { // 0x696554: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00696556: { // 0x696556: ff5234 CALL dword ptr [EDX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000034u)),6907225u); flags=s.arithmetic_flags;
  }
  L00696559: { // 0x696559: 8b0df01c8200 MOV ECX, dword ptr [0x821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  L0069655f: { // 0x69655f: 68f1000000 PUSH 0xf1
    f.push(m,0x000000f1u);
  }
  L00696564: { // 0x696564: e867a70400 CALL 0x6e0cd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0cd0u,6907241u); flags=s.arithmetic_flags;
  }
  L00696569: { // 0x696569: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0069656b: { // 0x69656b: 6a02 PUSH 2
    f.push(m,2u);
  }
  L0069656d: { // 0x69656d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069656f: { // 0x69656f: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6907250u); flags=s.arithmetic_flags;
  }
  L00696572: { // 0x696572: 8ac3 MOV AL, BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L00696574: { // 0x696574: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00696575: { // 0x696575: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00696576: { // 0x696576: 83c41c ADD ESP, 0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00696579: { // 0x696579: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002739b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006739b0: { // 0x6739b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006739b1: { // 0x6739b1: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006739b3: { // 0x6739b3: 8a0d2879a200 MOV CL, byte ptr [0xa27928]
    s.cx = with_al(s.cx, m.r8((0x00a27928u)));
  }
  L006739b9: { // 0x6739b9: 8a86e14e0000 MOV AL, byte ptr [ESI + 0x4ee1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00004ee1u)));
  }
  L006739bf: { // 0x6739bf: f6c102 TEST CL, 2
    (void)integer::logical(((s.cx & 0xffu))&(2u),8,flags);
  }
  L006739c2: { // 0x6739c2: 7413 JZ 0x6739d7
    if(integer::condition("JZ",flags)) goto L006739d7;
  }
  L006739c4: { // 0x6739c4: 8b0dc855a200 MOV ECX, dword ptr [0xa255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L006739ca: { // 0x6739ca: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006739cc: { // 0x6739cc: 7409 JZ 0x6739d7
    if(integer::condition("JZ",flags)) goto L006739d7;
  }
  L006739ce: { // 0x6739ce: 83f905 CMP ECX, 5
    (void)integer::sub(s.cx,5u,32,flags);
  }
  L006739d1: { // 0x6739d1: 0f8500040000 JNZ 0x673dd7
    if(integer::condition("JNZ",flags)) goto L00673dd7;
  }
  L006739d7: { // 0x6739d7: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L006739db: { // 0x6739db: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L006739de: { // 0x6739de: 740e JZ 0x6739ee
    if(integer::condition("JZ",flags)) goto L006739ee;
  }
  L006739e0: { // 0x6739e0: 83f901 CMP ECX, 1
    (void)integer::sub(s.cx,1u,32,flags);
  }
  L006739e3: { // 0x6739e3: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006739e6: { // 0x6739e6: 888ee14e0000 MOV byte ptr [ESI + 0x4ee1], CL
    m.w8((s.si+0x00004ee1u), (s.cx & 0xffu));
  }
  L006739ec: { // 0x6739ec: eb0b JMP 0x6739f9
    goto L006739f9;
  }
  L006739ee: { // 0x6739ee: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006739f0: { // 0x6739f0: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006739f3: { // 0x6739f3: 8896e14e0000 MOV byte ptr [ESI + 0x4ee1], DL
    m.w8((s.si+0x00004ee1u), (s.dx & 0xffu));
  }
  L006739f9: { // 0x6739f9: 8a8ee14e0000 MOV CL, byte ptr [ESI + 0x4ee1]
    s.cx = with_al(s.cx, m.r8((s.si+0x00004ee1u)));
  }
  L006739ff: { // 0x6739ff: 3ac8 CMP CL, AL
    (void)integer::sub((s.cx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L00673a01: { // 0x673a01: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L00673a04: { // 0x673a04: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00673a06: { // 0x673a06: 88442408 MOV byte ptr [ESP + 8], AL
    m.w8((f.sp+8u), (s.ax & 0xffu));
  }
  L00673a0a: { // 0x673a0a: 0f84c7030000 JZ 0x673dd7
    if(integer::condition("JZ",flags)) goto L00673dd7;
  }
  L00673a10: { // 0x673a10: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00673a11: { // 0x673a11: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00673a12: { // 0x673a12: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00673a13: { // 0x673a13: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00673a14: { // 0x673a14: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673a16: { // 0x673a16: e8452ffbff CALL 0x626960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00626960u,6765083u); flags=s.arithmetic_flags;
  }
  L00673a1b: { // 0x673a1b: 8a86e14e0000 MOV AL, byte ptr [ESI + 0x4ee1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00004ee1u)));
  }
  L00673a21: { // 0x673a21: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00673a23: { // 0x673a23: 0f84aa020000 JZ 0x673cd3
    if(integer::condition("JZ",flags)) goto L00673cd3;
  }
  L00673a29: { // 0x673a29: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673a2b: { // 0x673a2b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673a2d: { // 0x673a2d: ff9088000000 CALL dword ptr [EAX + 0x88]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000088u)),6765107u); flags=s.arithmetic_flags;
  }
  L00673a33: { // 0x673a33: b9b811aa00 MOV ECX, 0xaa11b8
    s.cx = 0x00aa11b8u;
  }
  L00673a38: { // 0x673a38: c686e24e000001 MOV byte ptr [ESI + 0x4ee2], 1
    m.w8((s.si+0x00004ee2u), 1u);
  }
  L00673a3f: { // 0x673a3f: e88c37ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765124u); flags=s.arithmetic_flags;
  }
  L00673a44: { // 0x673a44: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00673a46: { // 0x673a46: 68b811aa00 PUSH 0xaa11b8
    f.push(m,0x00aa11b8u);
  }
  L00673a4b: { // 0x673a4b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673a4d: { // 0x673a4d: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6765136u); flags=s.arithmetic_flags;
  }
  L00673a50: { // 0x673a50: b96047aa00 MOV ECX, 0xaa4760
    s.cx = 0x00aa4760u;
  }
  L00673a55: { // 0x673a55: e87637ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765146u); flags=s.arithmetic_flags;
  }
  L00673a5a: { // 0x673a5a: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673a5c: { // 0x673a5c: 686047aa00 PUSH 0xaa4760
    f.push(m,0x00aa4760u);
  }
  L00673a61: { // 0x673a61: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673a63: { // 0x673a63: ff5030 CALL dword ptr [EAX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000030u)),6765158u); flags=s.arithmetic_flags;
  }
  L00673a66: { // 0x673a66: bf0810aa00 MOV EDI, 0xaa1008
    s.di = 0x00aa1008u;
  }
  L00673a6b: { // 0x673a6b: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00673a6d: { // 0x673a6d: e85e37ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765170u); flags=s.arithmetic_flags;
  }
  L00673a72: { // 0x673a72: c6472c00 MOV byte ptr [EDI + 0x2c], 0
    m.w8((s.di+0x0000002cu), 0u);
  }
  L00673a76: { // 0x673a76: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00673a78: { // 0x673a78: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00673a79: { // 0x673a79: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673a7b: { // 0x673a7b: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6765182u); flags=s.arithmetic_flags;
  }
  L00673a7e: { // 0x673a7e: 83c760 ADD EDI, 0x60
    s.di = integer::add(s.di,0x00000060u,32,flags);
  }
  L00673a81: { // 0x673a81: 81ff8811aa00 CMP EDI, 0xaa1188
    (void)integer::sub(s.di,0x00aa1188u,32,flags);
  }
  L00673a87: { // 0x673a87: 7ce2 JL 0x673a6b
    if(integer::condition("JL",flags)) goto L00673a6b;
  }
  L00673a89: { // 0x673a89: b9f046aa00 MOV ECX, 0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00673a8e: { // 0x673a8e: e83d37ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765203u); flags=s.arithmetic_flags;
  }
  L00673a93: { // 0x673a93: 68f046aa00 PUSH 0xaa46f0
    f.push(m,0x00aa46f0u);
  }
  L00673a98: { // 0x673a98: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00673a9d: { // 0x673a9d: e8aec6e6ff CALL 0x4e0150
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0150u,6765218u); flags=s.arithmetic_flags;
  }
  L00673aa2: { // 0x673aa2: b9c847aa00 MOV ECX, 0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00673aa7: { // 0x673aa7: e82437ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765228u); flags=s.arithmetic_flags;
  }
  L00673aac: { // 0x673aac: 68c847aa00 PUSH 0xaa47c8
    f.push(m,0x00aa47c8u);
  }
  L00673ab1: { // 0x673ab1: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00673ab6: { // 0x673ab6: e895c6e6ff CALL 0x4e0150
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0150u,6765243u); flags=s.arithmetic_flags;
  }
  L00673abb: { // 0x673abb: b91812aa00 MOV ECX, 0xaa1218
    s.cx = 0x00aa1218u;
  }
  L00673ac0: { // 0x673ac0: e80b37ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765253u); flags=s.arithmetic_flags;
  }
  L00673ac5: { // 0x673ac5: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673ac7: { // 0x673ac7: 681812aa00 PUSH 0xaa1218
    f.push(m,0x00aa1218u);
  }
  L00673acc: { // 0x673acc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673ace: { // 0x673ace: ff5030 CALL dword ptr [EAX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000030u)),6765265u); flags=s.arithmetic_flags;
  }
  L00673ad1: { // 0x673ad1: b9c0dfa900 MOV ECX, 0xa9dfc0
    s.cx = 0x00a9dfc0u;
  }
  L00673ad6: { // 0x673ad6: e8f536ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765275u); flags=s.arithmetic_flags;
  }
  L00673adb: { // 0x673adb: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00673add: { // 0x673add: 68c0dfa900 PUSH 0xa9dfc0
    f.push(m,0x00a9dfc0u);
  }
  L00673ae2: { // 0x673ae2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673ae4: { // 0x673ae4: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6765287u); flags=s.arithmetic_flags;
  }
  L00673ae7: { // 0x673ae7: bf0810aa00 MOV EDI, 0xaa1008
    s.di = 0x00aa1008u;
  }
  L00673aec: { // 0x673aec: 8d9e90150000 LEA EBX, [ESI + 0x1590]
    s.bx = (s.si+0x00001590u);
  }
  L00673af2: { // 0x673af2: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00673af4: { // 0x673af4: 896bf0 MOV dword ptr [EBX - 0x10], EBP
    m.w32((s.bx-0x00000010u), s.bp);
  }
  L00673af7: { // 0x673af7: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00673af9: { // 0x673af9: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00673afb: { // 0x673afb: 7e07 JLE 0x673b04
    if(integer::condition("JLE",flags)) goto L00673b04;
  }
  L00673afd: { // 0x673afd: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00673aff: { // 0x673aff: e81cb2e5ff CALL 0x4ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6765316u); flags=s.arithmetic_flags;
  }
  L00673b04: { // 0x673b04: 83c760 ADD EDI, 0x60
    s.di = integer::add(s.di,0x00000060u,32,flags);
  }
  L00673b07: { // 0x673b07: 81c3640e0000 ADD EBX, 0xe64
    s.bx = integer::add(s.bx,0x00000e64u,32,flags);
  }
  L00673b0d: { // 0x673b0d: 81ff8811aa00 CMP EDI, 0xaa1188
    (void)integer::sub(s.di,0x00aa1188u,32,flags);
  }
  L00673b13: { // 0x673b13: 7cdf JL 0x673af4
    if(integer::condition("JL",flags)) goto L00673af4;
  }
  L00673b15: { // 0x673b15: 8b86d84e0000 MOV EAX, dword ptr [ESI + 0x4ed8]
    s.ax = m.r32((s.si+0x00004ed8u));
  }
  L00673b1b: { // 0x673b1b: 8d0c40 LEA ECX, [EAX + EAX*2]
    s.cx = (s.ax+(s.ax * 2u));
  }
  L00673b1e: { // 0x673b1e: c1e105 SHL ECX, 5
    s.cx = integer::shift(s.cx,5u,32,flags,integer::Shift::left);
  }
  L00673b21: { // 0x673b21: 81c10810aa00 ADD ECX, 0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00673b27: { // 0x673b27: e8f4c80600 CALL 0x6e0420
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0420u,6765356u); flags=s.arithmetic_flags;
  }
  L00673b2c: { // 0x673b2c: 8b8ed84e0000 MOV ECX, dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L00673b32: { // 0x673b32: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00673b34: { // 0x673b34: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L00673b37: { // 0x673b37: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00673b39: { // 0x673b39: 8d04c0 LEA EAX, [EAX + EAX*8]
    s.ax = (s.ax+(s.ax * 8u));
  }
  L00673b3c: { // 0x673b3c: 8d0441 LEA EAX, [ECX + EAX*2]
    s.ax = (s.cx+(s.ax * 2u));
  }
  L00673b3f: { // 0x673b3f: 8d0c40 LEA ECX, [EAX + EAX*2]
    s.cx = (s.ax+(s.ax * 2u));
  }
  L00673b42: { // 0x673b42: 8dac8e40150000 LEA EBP, [ESI + ECX*4 + 0x1540]
    s.bp = (s.si+(s.cx * 4u)+0x00001540u);
  }
  L00673b49: { // 0x673b49: c6451801 MOV byte ptr [EBP + 0x18], 1
    m.w8((s.bp+0x00000018u), 1u);
  }
  L00673b4d: { // 0x673b4d: 8b15c055a200 MOV EDX, dword ptr [0xa255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00673b53: { // 0x673b53: 8b0d6c198200 MOV ECX, dword ptr [0x82196c]
    s.cx = m.r32((0x0082196cu));
  }
  L00673b59: { // 0x673b59: 8b1d6c48aa00 MOV EBX, dword ptr [0xaa486c]
    s.bx = m.r32((0x00aa486cu));
  }
  L00673b5f: { // 0x673b5f: 8a8239220000 MOV AL, byte ptr [EDX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00002239u)));
  }
  L00673b65: { // 0x673b65: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L00673b67: { // 0x673b67: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L00673b69: { // 0x673b69: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00673b6b: { // 0x673b6b: 2bd3 SUB EDX, EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00673b6d: { // 0x673b6d: 83e008 AND EAX, 8
    s.ax = integer::logical((s.ax)&(8u),32,flags);
  }
  L00673b70: { // 0x673b70: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00673b72: { // 0x673b72: 83c012 ADD EAX, 0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00673b75: { // 0x673b75: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00673b77: { // 0x673b77: a164198200 MOV EAX, dword ptr [0x821964]
    s.ax = m.r32((0x00821964u));
  }
  L00673b7c: { // 0x673b7c: 8d5402f9 LEA EDX, [EDX + EAX - 7]
    s.dx = (s.dx+s.ax-7u);
  }
  L00673b80: { // 0x673b80: b81f85eb51 MOV EAX, 0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00673b85: { // 0x673b85: f7ea IMUL EDX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.dx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00673b87: { // 0x673b87: c1fa04 SAR EDX, 4
    s.dx = integer::shift(s.dx,4u,32,flags,integer::Shift::arithmetic_right);
  }
  L00673b8a: { // 0x673b8a: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L00673b8c: { // 0x673b8c: c1e81f SHR EAX, 0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00673b8f: { // 0x673b8f: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00673b91: { // 0x673b91: d1e2 SHL EDX, 1
    s.dx = integer::shift(s.dx,1u,32,flags,integer::Shift::left);
  }
  L00673b93: { // 0x673b93: 8bda MOV EBX, EDX
    s.bx = s.dx;
  }
  L00673b95: { // 0x673b95: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00673b97: { // 0x673b97: 7e4b JLE 0x673be4
    if(integer::condition("JLE",flags)) goto L00673be4;
  }
  L00673b99: { // 0x673b99: 8b4534 MOV EAX, dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L00673b9c: { // 0x673b9c: 6bc03c IMUL EAX, EAX, 0x3c
    s.ax = integer::imul(s.ax,0x0000003cu,32,flags);
  }
  L00673b9f: { // 0x673b9f: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00673ba1: { // 0x673ba1: 8d0cc500000000 LEA ECX, [EAX*8]
    s.cx = ((s.ax * 8u));
  }
  L00673ba8: { // 0x673ba8: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00673baa: { // 0x673baa: 8d0ccd4012aa00 LEA ECX, [ECX*8 + 0xaa1240]
    s.cx = ((s.cx * 8u)+0x00aa1240u);
  }
  L00673bb1: { // 0x673bb1: e81a36ecff CALL 0x5371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6765494u); flags=s.arithmetic_flags;
  }
  L00673bb6: { // 0x673bb6: 8b4534 MOV EAX, dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L00673bb9: { // 0x673bb9: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00673bbe: { // 0x673bbe: 6bc03c IMUL EAX, EAX, 0x3c
    s.ax = integer::imul(s.ax,0x0000003cu,32,flags);
  }
  L00673bc1: { // 0x673bc1: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00673bc3: { // 0x673bc3: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L00673bca: { // 0x673bca: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00673bcc: { // 0x673bcc: 8d04d54012aa00 LEA EAX, [EDX*8 + 0xaa1240]
    s.ax = ((s.dx * 8u)+0x00aa1240u);
  }
  L00673bd3: { // 0x673bd3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00673bd4: { // 0x673bd4: e877c5e6ff CALL 0x4e0150
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0150u,6765529u); flags=s.arithmetic_flags;
  }
  L00673bd9: { // 0x673bd9: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00673bda: { // 0x673bda: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00673bdc: { // 0x673bdc: 7cbb JL 0x673b99
    if(integer::condition("JL",flags)) goto L00673b99;
  }
  L00673bde: { // 0x673bde: 8b0d6c198200 MOV ECX, dword ptr [0x82196c]
    s.cx = m.r32((0x0082196cu));
  }
  L00673be4: { // 0x673be4: 8b15c055a200 MOV EDX, dword ptr [0xa255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00673bea: { // 0x673bea: c60503f7810001 MOV byte ptr [0x81f703], 1
    m.w8((0x0081f703u), 1u);
  }
  L00673bf1: { // 0x673bf1: 8a8239220000 MOV AL, byte ptr [EDX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00002239u)));
  }
  L00673bf7: { // 0x673bf7: 8b156c48aa00 MOV EDX, dword ptr [0xaa486c]
    s.dx = m.r32((0x00aa486cu));
  }
  L00673bfd: { // 0x673bfd: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L00673bff: { // 0x673bff: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00673c01: { // 0x673c01: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00673c03: { // 0x673c03: 83e008 AND EAX, 8
    s.ax = integer::logical((s.ax)&(8u),32,flags);
  }
  L00673c06: { // 0x673c06: 83c012 ADD EAX, 0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00673c09: { // 0x673c09: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00673c0b: { // 0x673c0b: a164198200 MOV EAX, dword ptr [0x821964]
    s.ax = m.r32((0x00821964u));
  }
  L00673c10: { // 0x673c10: 8d4c01f9 LEA ECX, [ECX + EAX - 7]
    s.cx = (s.cx+s.ax-7u);
  }
  L00673c14: { // 0x673c14: b81f85eb51 MOV EAX, 0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00673c19: { // 0x673c19: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00673c1b: { // 0x673c1b: c1fa04 SAR EDX, 4
    s.dx = integer::shift(s.dx,4u,32,flags,integer::Shift::arithmetic_right);
  }
  L00673c1e: { // 0x673c1e: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00673c20: { // 0x673c20: c1e91f SHR ECX, 0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00673c23: { // 0x673c23: 03d1 ADD EDX, ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00673c25: { // 0x673c25: 8b8ed84e0000 MOV ECX, dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L00673c2b: { // 0x673c2b: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00673c2d: { // 0x673c2d: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L00673c30: { // 0x673c30: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00673c32: { // 0x673c32: d1e2 SHL EDX, 1
    s.dx = integer::shift(s.dx,1u,32,flags,integer::Shift::left);
  }
  L00673c34: { // 0x673c34: 8d04c0 LEA EAX, [EAX + EAX*8]
    s.ax = (s.ax+(s.ax * 8u));
  }
  L00673c37: { // 0x673c37: 8d0441 LEA EAX, [ECX + EAX*2]
    s.ax = (s.cx+(s.ax * 2u));
  }
  L00673c3a: { // 0x673c3a: 8d0c40 LEA ECX, [EAX + EAX*2]
    s.cx = (s.ax+(s.ax * 2u));
  }
  L00673c3d: { // 0x673c3d: 8b848e90150000 MOV EAX, dword ptr [ESI + ECX*4 + 0x1590]
    s.ax = m.r32((s.si+(s.cx * 4u)+0x00001590u));
  }
  L00673c44: { // 0x673c44: b9f046aa00 MOV ECX, 0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00673c49: { // 0x673c49: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00673c4b: { // 0x673c4b: 7e43 JLE 0x673c90
    if(integer::condition("JLE",flags)) goto L00673c90;
  }
  L00673c4d: { // 0x673c4d: e8eeb0e5ff CALL 0x4ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6765650u); flags=s.arithmetic_flags;
  }
  L00673c52: { // 0x673c52: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00673c54: { // 0x673c54: 750a JNZ 0x673c60
    if(integer::condition("JNZ",flags)) goto L00673c60;
  }
  L00673c56: { // 0x673c56: b9f046aa00 MOV ECX, 0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00673c5b: { // 0x673c5b: e8c0b0e5ff CALL 0x4ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6765664u); flags=s.arithmetic_flags;
  }
  L00673c60: { // 0x673c60: b9c847aa00 MOV ECX, 0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00673c65: { // 0x673c65: e8d6b0e5ff CALL 0x4ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6765674u); flags=s.arithmetic_flags;
  }
  L00673c6a: { // 0x673c6a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00673c6c: { // 0x673c6c: 0f8555010000 JNZ 0x673dc7
    if(integer::condition("JNZ",flags)) goto L00673dc7;
  }
  L00673c72: { // 0x673c72: b9c847aa00 MOV ECX, 0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00673c77: { // 0x673c77: e8a4b0e5ff CALL 0x4ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6765692u); flags=s.arithmetic_flags;
  }
  L00673c7c: { // 0x673c7c: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673c7e: { // 0x673c7e: 6a02 PUSH 2
    f.push(m,2u);
  }
  L00673c80: { // 0x673c80: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673c82: { // 0x673c82: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6765701u); flags=s.arithmetic_flags;
  }
  L00673c85: { // 0x673c85: 8a442414 MOV AL, byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L00673c89: { // 0x673c89: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00673c8a: { // 0x673c8a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00673c8b: { // 0x673c8b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00673c8c: { // 0x673c8c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00673c8d: { // 0x673c8d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00673c90: { // 0x673c90: e8abb0e5ff CALL 0x4ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6765717u); flags=s.arithmetic_flags;
  }
  L00673c95: { // 0x673c95: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00673c97: { // 0x673c97: 740a JZ 0x673ca3
    if(integer::condition("JZ",flags)) goto L00673ca3;
  }
  L00673c99: { // 0x673c99: b9f046aa00 MOV ECX, 0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00673c9e: { // 0x673c9e: e88db0e5ff CALL 0x4ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6765731u); flags=s.arithmetic_flags;
  }
  L00673ca3: { // 0x673ca3: b9c847aa00 MOV ECX, 0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00673ca8: { // 0x673ca8: e893b0e5ff CALL 0x4ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6765741u); flags=s.arithmetic_flags;
  }
  L00673cad: { // 0x673cad: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00673caf: { // 0x673caf: 0f8412010000 JZ 0x673dc7
    if(integer::condition("JZ",flags)) goto L00673dc7;
  }
  L00673cb5: { // 0x673cb5: b9c847aa00 MOV ECX, 0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00673cba: { // 0x673cba: e871b0e5ff CALL 0x4ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6765759u); flags=s.arithmetic_flags;
  }
  L00673cbf: { // 0x673cbf: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673cc1: { // 0x673cc1: 6a02 PUSH 2
    f.push(m,2u);
  }
  L00673cc3: { // 0x673cc3: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673cc5: { // 0x673cc5: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6765768u); flags=s.arithmetic_flags;
  }
  L00673cc8: { // 0x673cc8: 8a442414 MOV AL, byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L00673ccc: { // 0x673ccc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00673ccd: { // 0x673ccd: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00673cce: { // 0x673cce: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00673ccf: { // 0x673ccf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00673cd0: { // 0x673cd0: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00673cd3: { // 0x673cd3: e8f89af2ff CALL 0x59d7d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0059d7d0u,6765784u); flags=s.arithmetic_flags;
  }
  L00673cd8: { // 0x673cd8: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00673cda: { // 0x673cda: 68b811aa00 PUSH 0xaa11b8
    f.push(m,0x00aa11b8u);
  }
  L00673cdf: { // 0x673cdf: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673ce1: { // 0x673ce1: ff5234 CALL dword ptr [EDX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000034u)),6765796u); flags=s.arithmetic_flags;
  }
  L00673ce4: { // 0x673ce4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673ce6: { // 0x673ce6: 686047aa00 PUSH 0xaa4760
    f.push(m,0x00aa4760u);
  }
  L00673ceb: { // 0x673ceb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673ced: { // 0x673ced: ff5034 CALL dword ptr [EAX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000034u)),6765808u); flags=s.arithmetic_flags;
  }
  L00673cf0: { // 0x673cf0: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00673cf2: { // 0x673cf2: 681812aa00 PUSH 0xaa1218
    f.push(m,0x00aa1218u);
  }
  L00673cf7: { // 0x673cf7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673cf9: { // 0x673cf9: ff5234 CALL dword ptr [EDX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000034u)),6765820u); flags=s.arithmetic_flags;
  }
  L00673cfc: { // 0x673cfc: bf0810aa00 MOV EDI, 0xaa1008
    s.di = 0x00aa1008u;
  }
  L00673d01: { // 0x673d01: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673d03: { // 0x673d03: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00673d04: { // 0x673d04: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673d06: { // 0x673d06: ff5034 CALL dword ptr [EAX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000034u)),6765833u); flags=s.arithmetic_flags;
  }
  L00673d09: { // 0x673d09: 83c760 ADD EDI, 0x60
    s.di = integer::add(s.di,0x00000060u,32,flags);
  }
  L00673d0c: { // 0x673d0c: 81ff8811aa00 CMP EDI, 0xaa1188
    (void)integer::sub(s.di,0x00aa1188u,32,flags);
  }
  L00673d12: { // 0x673d12: 7ced JL 0x673d01
    if(integer::condition("JL",flags)) goto L00673d01;
  }
  L00673d14: { // 0x673d14: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00673d16: { // 0x673d16: 68f046aa00 PUSH 0xaa46f0
    f.push(m,0x00aa46f0u);
  }
  L00673d1b: { // 0x673d1b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673d1d: { // 0x673d1d: ff5234 CALL dword ptr [EDX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000034u)),6765856u); flags=s.arithmetic_flags;
  }
  L00673d20: { // 0x673d20: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673d22: { // 0x673d22: 68c847aa00 PUSH 0xaa47c8
    f.push(m,0x00aa47c8u);
  }
  L00673d27: { // 0x673d27: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673d29: { // 0x673d29: ff5034 CALL dword ptr [EAX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000034u)),6765868u); flags=s.arithmetic_flags;
  }
  L00673d2c: { // 0x673d2c: 8b8ed84e0000 MOV ECX, dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L00673d32: { // 0x673d32: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00673d34: { // 0x673d34: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L00673d37: { // 0x673d37: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00673d39: { // 0x673d39: 8d14c0 LEA EDX, [EAX + EAX*8]
    s.dx = (s.ax+(s.ax * 8u));
  }
  L00673d3c: { // 0x673d3c: 8d0451 LEA EAX, [ECX + EDX*2]
    s.ax = (s.cx+(s.dx * 2u));
  }
  L00673d3f: { // 0x673d3f: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00673d45: { // 0x673d45: 8b156c198200 MOV EDX, dword ptr [0x82196c]
    s.dx = m.r32((0x0082196cu));
  }
  L00673d4b: { // 0x673d4b: 8d0440 LEA EAX, [EAX + EAX*2]
    s.ax = (s.ax+(s.ax * 2u));
  }
  L00673d4e: { // 0x673d4e: 8dac8640150000 LEA EBP, [ESI + EAX*4 + 0x1540]
    s.bp = (s.si+(s.ax * 4u)+0x00001540u);
  }
  L00673d55: { // 0x673d55: 8a8139220000 MOV AL, byte ptr [ECX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00002239u)));
  }
  L00673d5b: { // 0x673d5b: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L00673d5d: { // 0x673d5d: 8b0d6c48aa00 MOV ECX, dword ptr [0xaa486c]
    s.cx = m.r32((0x00aa486cu));
  }
  L00673d63: { // 0x673d63: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00673d65: { // 0x673d65: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00673d67: { // 0x673d67: 83e008 AND EAX, 8
    s.ax = integer::logical((s.ax)&(8u),32,flags);
  }
  L00673d6a: { // 0x673d6a: 83c012 ADD EAX, 0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00673d6d: { // 0x673d6d: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00673d6f: { // 0x673d6f: a164198200 MOV EAX, dword ptr [0x821964]
    s.ax = m.r32((0x00821964u));
  }
  L00673d74: { // 0x673d74: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00673d76: { // 0x673d76: 8d4c02f9 LEA ECX, [EDX + EAX - 7]
    s.cx = (s.dx+s.ax-7u);
  }
  L00673d7a: { // 0x673d7a: b81f85eb51 MOV EAX, 0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00673d7f: { // 0x673d7f: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00673d81: { // 0x673d81: c1fa04 SAR EDX, 4
    s.dx = integer::shift(s.dx,4u,32,flags,integer::Shift::arithmetic_right);
  }
  L00673d84: { // 0x673d84: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00673d86: { // 0x673d86: c1e91f SHR ECX, 0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00673d89: { // 0x673d89: 03d1 ADD EDX, ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00673d8b: { // 0x673d8b: d1e2 SHL EDX, 1
    s.dx = integer::shift(s.dx,1u,32,flags,integer::Shift::left);
  }
  L00673d8d: { // 0x673d8d: 8bda MOV EBX, EDX
    s.bx = s.dx;
  }
  L00673d8f: { // 0x673d8f: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00673d91: { // 0x673d91: 7e28 JLE 0x673dbb
    if(integer::condition("JLE",flags)) goto L00673dbb;
  }
  L00673d93: { // 0x673d93: 8b4534 MOV EAX, dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L00673d96: { // 0x673d96: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00673d9b: { // 0x673d9b: 6bc03c IMUL EAX, EAX, 0x3c
    s.ax = integer::imul(s.ax,0x0000003cu,32,flags);
  }
  L00673d9e: { // 0x673d9e: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00673da0: { // 0x673da0: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L00673da7: { // 0x673da7: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00673da9: { // 0x673da9: 8d04d54012aa00 LEA EAX, [EDX*8 + 0xaa1240]
    s.ax = ((s.dx * 8u)+0x00aa1240u);
  }
  L00673db0: { // 0x673db0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00673db1: { // 0x673db1: e8dac3e6ff CALL 0x4e0190
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0190u,6766006u); flags=s.arithmetic_flags;
  }
  L00673db6: { // 0x673db6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00673db7: { // 0x673db7: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00673db9: { // 0x673db9: 7cd8 JL 0x673d93
    if(integer::condition("JL",flags)) goto L00673d93;
  }
  L00673dbb: { // 0x673dbb: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00673dbd: { // 0x673dbd: 68c0dfa900 PUSH 0xa9dfc0
    f.push(m,0x00a9dfc0u);
  }
  L00673dc2: { // 0x673dc2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673dc4: { // 0x673dc4: ff5234 CALL dword ptr [EDX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000034u)),6766023u); flags=s.arithmetic_flags;
  }
  L00673dc7: { // 0x673dc7: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00673dc9: { // 0x673dc9: 6a02 PUSH 2
    f.push(m,2u);
  }
  L00673dcb: { // 0x673dcb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00673dcd: { // 0x673dcd: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6766032u); flags=s.arithmetic_flags;
  }
  L00673dd0: { // 0x673dd0: 8a442414 MOV AL, byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L00673dd4: { // 0x673dd4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00673dd5: { // 0x673dd5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00673dd6: { // 0x673dd6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00673dd7: { // 0x673dd7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00673dd8: { // 0x673dd8: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6767792u:f_002744b0(m,s,child,{});break;
case 4729248u:f_000829a0(m,s,child,{});break;
case 6767040u:f_002741c0(m,s,child,{});break;
case 5041440u:f_000ced20(m,s,child,{});break;
case 5041456u:f_000ced30(m,s,child,{});break;
case 5041472u:f_000ced40(m,s,child,{});break;
case 5042672u:f_000cf1f0(m,s,child,{});break;
case 5111856u:f_000e0030(m,s,child,{});break;
case 5601968u:f_00157ab0(m,s,child,{});break;
case 6906864u:f_002963f0(m,s,child,{});break;
case 6764976u:f_002739b0(m,s,child,{});break;
default:throw std::domain_error("recovery738 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00671da0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-36,i.stack_minus8);m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00671da0: { // 0x671da0: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L00671da5: { // 0x671da5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00671da6: { // 0x671da6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671da7: { // 0x671da7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00671da8: { // 0x671da8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671daa: { // 0x671daa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00671dab: { // 0x671dab: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00671dad: { // 0x671dad: 0f8547020000 JNZ 0x00671ffa
    if(integer::condition("JNZ",flags)) goto L00671ffa;
  }
  L00671db3: { // 0x671db3: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00671db7: { // 0x671db7: 83fe0f CMP ESI,0xf
    (void)integer::sub(s.si,0x0000000fu,32,flags);
  }
  L00671dba: { // 0x671dba: 745a JZ 0x00671e16
    if(integer::condition("JZ",flags)) goto L00671e16;
  }
  L00671dbc: { // 0x671dbc: 83fe10 CMP ESI,0x10
    (void)integer::sub(s.si,0x00000010u,32,flags);
  }
  L00671dbf: { // 0x671dbf: 7455 JZ 0x00671e16
    if(integer::condition("JZ",flags)) goto L00671e16;
  }
  L00671dc1: { // 0x671dc1: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L00671dc4: { // 0x671dc4: 7449 JZ 0x00671e0f
    if(integer::condition("JZ",flags)) goto L00671e0f;
  }
  L00671dc6: { // 0x671dc6: 83fe28 CMP ESI,0x28
    (void)integer::sub(s.si,0x00000028u,32,flags);
  }
  L00671dc9: { // 0x671dc9: 7444 JZ 0x00671e0f
    if(integer::condition("JZ",flags)) goto L00671e0f;
  }
  L00671dcb: { // 0x671dcb: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  L00671dce: { // 0x671dce: 743f JZ 0x00671e0f
    if(integer::condition("JZ",flags)) goto L00671e0f;
  }
  L00671dd0: { // 0x671dd0: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L00671dd3: { // 0x671dd3: 743a JZ 0x00671e0f
    if(integer::condition("JZ",flags)) goto L00671e0f;
  }
  L00671dd5: { // 0x671dd5: 83fe06 CMP ESI,0x6
    (void)integer::sub(s.si,0x00000006u,32,flags);
  }
  L00671dd8: { // 0x671dd8: 7420 JZ 0x00671dfa
    if(integer::condition("JZ",flags)) goto L00671dfa;
  }
  L00671dda: { // 0x671dda: 83fe07 CMP ESI,0x7
    (void)integer::sub(s.si,0x00000007u,32,flags);
  }
  L00671ddd: { // 0x671ddd: 741b JZ 0x00671dfa
    if(integer::condition("JZ",flags)) goto L00671dfa;
  }
  L00671ddf: { // 0x671ddf: 83fe39 CMP ESI,0x39
    (void)integer::sub(s.si,0x00000039u,32,flags);
  }
  L00671de2: { // 0x671de2: 740f JZ 0x00671df3
    if(integer::condition("JZ",flags)) goto L00671df3;
  }
  L00671de4: { // 0x671de4: 83fe20 CMP ESI,0x20
    (void)integer::sub(s.si,0x00000020u,32,flags);
  }
  L00671de7: { // 0x671de7: 740a JZ 0x00671df3
    if(integer::condition("JZ",flags)) goto L00671df3;
  }
  L00671de9: { // 0x671de9: 83fe1f CMP ESI,0x1f
    (void)integer::sub(s.si,0x0000001fu,32,flags);
  }
  L00671dec: { // 0x671dec: 7405 JZ 0x00671df3
    if(integer::condition("JZ",flags)) goto L00671df3;
  }
  L00671dee: { // 0x671dee: 83cbff OR EBX,0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  L00671df1: { // 0x671df1: eb28 JMP 0x00671e1b
    goto L00671e1b;
  }
  L00671df3: { // 0x671df3: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L00671df8: { // 0x671df8: eb21 JMP 0x00671e1b
    goto L00671e1b;
  }
  L00671dfa: { // 0x671dfa: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00671dfe: { // 0x671dfe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00671e00: { // 0x671e00: e86b8ce7ff CALL 0x004eaa70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eaa70u,6757893u); flags=s.arithmetic_flags;
  }
  L00671e05: { // 0x671e05: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00671e07: { // 0x671e07: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00671e0a: { // 0x671e0a: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00671e0d: { // 0x671e0d: eb0c JMP 0x00671e1b
    goto L00671e1b;
  }
  L00671e0f: { // 0x671e0f: bb03000000 MOV EBX,0x3
    s.bx = 0x00000003u;
  }
  L00671e14: { // 0x671e14: eb05 JMP 0x00671e1b
    goto L00671e1b;
  }
  L00671e16: { // 0x671e16: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L00671e1b: { // 0x671e1b: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00671e1d: { // 0x671e1d: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00671e21: { // 0x671e21: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00671e24: { // 0x671e24: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00671e26: { // 0x671e26: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00671e29: { // 0x671e29: 8d0443 LEA EAX,[EBX + EAX*0x2]
    s.ax = (s.bx+(s.ax * 0x00000002u));
  }
  L00671e2c: { // 0x671e2c: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00671e2f: { // 0x671e2f: 8dbc8d40150000 LEA EDI,[EBP + ECX*0x4 + 0x1540]
    s.di = (s.bp+(s.cx * 0x00000004u)+0x00001540u);
  }
  L00671e36: { // 0x671e36: 8b8c8d90150000 MOV ECX,dword ptr [EBP + ECX*0x4 + 0x1590]
    s.cx = m.r32((s.bp+(s.cx * 0x00000004u)+0x00001590u));
  }
  L00671e3d: { // 0x671e3d: 83f94b CMP ECX,0x4b
    (void)integer::sub(s.cx,0x0000004bu,32,flags);
  }
  L00671e40: { // 0x671e40: 0f8fb4010000 JG 0x00671ffa
    if(integer::condition("JG",flags)) goto L00671ffa;
  }
  L00671e46: { // 0x671e46: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00671e48: { // 0x671e48: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00671e4a: { // 0x671e4a: 7e20 JLE 0x00671e6c
    if(integer::condition("JLE",flags)) goto L00671e6c;
  }
  L00671e4c: { // 0x671e4c: 8d4754 LEA EAX,[EDI + 0x54]
    s.ax = (s.di+0x00000054u);
  }
  L00671e4f: { // 0x671e4f: 397004 CMP dword ptr [EAX + 0x4],ESI
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.si,32,flags);
  }
  L00671e52: { // 0x671e52: 7510 JNZ 0x00671e64
    if(integer::condition("JNZ",flags)) goto L00671e64;
  }
  L00671e54: { // 0x671e54: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00671e58: { // 0x671e58: 3918 CMP dword ptr [EAX],EBX
    (void)integer::sub(m.r32((s.ax)),s.bx,32,flags);
  }
  L00671e5a: { // 0x671e5a: 0f849a010000 JZ 0x00671ffa
    if(integer::condition("JZ",flags)) goto L00671ffa;
  }
  L00671e60: { // 0x671e60: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00671e64: { // 0x671e64: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00671e65: { // 0x671e65: 83c030 ADD EAX,0x30
    s.ax = integer::add(s.ax,0x00000030u,32,flags);
  }
  L00671e68: { // 0x671e68: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00671e6a: { // 0x671e6a: 7ce3 JL 0x00671e4f
    if(integer::condition("JL",flags)) goto L00671e4f;
  }
  L00671e6c: { // 0x671e6c: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L00671e71: { // 0x671e71: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00671e73: { // 0x671e73: 7514 JNZ 0x00671e89
    if(integer::condition("JNZ",flags)) goto L00671e89;
  }
  L00671e75: { // 0x671e75: 83fe1f CMP ESI,0x1f
    (void)integer::sub(s.si,0x0000001fu,32,flags);
  }
  L00671e78: { // 0x671e78: 740f JZ 0x00671e89
    if(integer::condition("JZ",flags)) goto L00671e89;
  }
  L00671e7a: { // 0x671e7a: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00671e7c: { // 0x671e7c: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L00671e7f: { // 0x671e7f: b9c8d67d00 MOV ECX,0x7dd6c8
    s.cx = 0x007dd6c8u;
  }
  L00671e84: { // 0x671e84: e877880900 CALL 0x0070a700
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a700u,6758025u); flags=s.arithmetic_flags;
  }
  L00671e89: { // 0x671e89: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00671e8d: { // 0x671e8d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00671e8f: { // 0x671e8f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00671e90: { // 0x671e90: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00671e91: { // 0x671e91: e81a260000 CALL 0x006744b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006744b0u,6758038u); flags=s.arithmetic_flags;
  }
  L00671e96: { // 0x671e96: c6473801 MOV byte ptr [EDI + 0x38],0x1
    m.w8((s.di+0x00000038u), 0x00000001u);
  }
  L00671e9a: { // 0x671e9a: c60503f7810001 MOV byte ptr [0x0081f703],0x1
    m.w8((0x0081f703u), 0x00000001u);
  }
  L00671ea1: { // 0x671ea1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00671ea3: { // 0x671ea3: 8d8d90150000 LEA ECX,[EBP + 0x1590]
    s.cx = (s.bp+0x00001590u);
  }
  L00671ea9: { // 0x671ea9: 833900 CMP dword ptr [ECX],0x0
    (void)integer::sub(m.r32((s.cx)),0x00000000u,32,flags);
  }
  L00671eac: { // 0x671eac: 7f0e JG 0x00671ebc
    if(integer::condition("JG",flags)) goto L00671ebc;
  }
  L00671eae: { // 0x671eae: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00671eaf: { // 0x671eaf: 81c1640e0000 ADD ECX,0xe64
    s.cx = integer::add(s.cx,0x00000e64u,32,flags);
  }
  L00671eb5: { // 0x671eb5: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00671eb8: { // 0x671eb8: 7cef JL 0x00671ea9
    if(integer::condition("JL",flags)) goto L00671ea9;
  }
  L00671eba: { // 0x671eba: eb05 JMP 0x00671ec1
    goto L00671ec1;
  }
  L00671ebc: { // 0x671ebc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00671ebf: { // 0x671ebf: 751d JNZ 0x00671ede
    if(integer::condition("JNZ",flags)) goto L00671ede;
  }
  L00671ec1: { // 0x671ec1: a13848aa00 MOV EAX,[0x00aa4838]
    s.ax = m.r32((0x00aa4838u));
  }
  L00671ec6: { // 0x671ec6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00671ec8: { // 0x671ec8: 7414 JZ 0x00671ede
    if(integer::condition("JZ",flags)) goto L00671ede;
  }
  L00671eca: { // 0x671eca: c785d44e000001000000 MOV dword ptr [EBP + 0x4ed4],0x1
    m.w32((s.bp+0x00004ed4u), 0x00000001u);
  }
  L00671ed4: { // 0x671ed4: c785d04e000000000000 MOV dword ptr [EBP + 0x4ed0],0x0
    m.w32((s.bp+0x00004ed0u), 0x00000000u);
  }
  L00671ede: { // 0x671ede: 8d045b LEA EAX,[EBX + EBX*0x2]
    s.ax = (s.bx+(s.bx * 0x00000002u));
  }
  L00671ee1: { // 0x671ee1: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L00671ee4: { // 0x671ee4: 8db00810aa00 LEA ESI,[EAX + 0xaa1008]
    s.si = (s.ax+0x00aa1008u);
  }
  L00671eea: { // 0x671eea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00671eec: { // 0x671eec: e84fcee5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6758129u); flags=s.arithmetic_flags;
  }
  L00671ef1: { // 0x671ef1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671ef3: { // 0x671ef3: 7507 JNZ 0x00671efc
    if(integer::condition("JNZ",flags)) goto L00671efc;
  }
  L00671ef5: { // 0x671ef5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00671ef7: { // 0x671ef7: e824cee5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6758140u); flags=s.arithmetic_flags;
  }
  L00671efc: { // 0x671efc: 8b8dd84e0000 MOV ECX,dword ptr [EBP + 0x4ed8]
    s.cx = m.r32((s.bp+0x00004ed8u));
  }
  L00671f02: { // 0x671f02: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00671f04: { // 0x671f04: 0f85ba000000 JNZ 0x00671fc4
    if(integer::condition("JNZ",flags)) goto L00671fc4;
  }
  L00671f0a: { // 0x671f0a: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00671f10: { // 0x671f10: 8b3d6c48aa00 MOV EDI,dword ptr [0x00aa486c]
    s.di = m.r32((0x00aa486cu));
  }
  L00671f16: { // 0x671f16: 8a8239220000 MOV AL,byte ptr [EDX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00002239u)));
  }
  L00671f1c: { // 0x671f1c: 8b156c198200 MOV EDX,dword ptr [0x0082196c]
    s.dx = m.r32((0x0082196cu));
  }
  L00671f22: { // 0x671f22: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L00671f24: { // 0x671f24: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00671f26: { // 0x671f26: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L00671f28: { // 0x671f28: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L00671f2b: { // 0x671f2b: 83c012 ADD EAX,0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00671f2e: { // 0x671f2e: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00671f30: { // 0x671f30: a164198200 MOV EAX,[0x00821964]
    s.ax = m.r32((0x00821964u));
  }
  L00671f35: { // 0x671f35: 8d5402f9 LEA EDX,[EDX + EAX*0x1 + -0x7]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000007u);
  }
  L00671f39: { // 0x671f39: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00671f3e: { // 0x671f3e: f7ea IMUL EDX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.dx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00671f40: { // 0x671f40: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00671f43: { // 0x671f43: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00671f45: { // 0x671f45: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00671f48: { // 0x671f48: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00671f4a: { // 0x671f4a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00671f4c: { // 0x671f4c: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00671f4f: { // 0x671f4f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00671f51: { // 0x671f51: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00671f53: { // 0x671f53: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00671f56: { // 0x671f56: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L00671f59: { // 0x671f59: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00671f5c: { // 0x671f5c: 8b848d90150000 MOV EAX,dword ptr [EBP + ECX*0x4 + 0x1590]
    s.ax = m.r32((s.bp+(s.cx * 0x00000004u)+0x00001590u));
  }
  L00671f63: { // 0x671f63: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00671f68: { // 0x671f68: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00671f6a: { // 0x671f6a: 7e2d JLE 0x00671f99
    if(integer::condition("JLE",flags)) goto L00671f99;
  }
  L00671f6c: { // 0x671f6c: e8cfcde5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6758257u); flags=s.arithmetic_flags;
  }
  L00671f71: { // 0x671f71: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671f73: { // 0x671f73: 750a JNZ 0x00671f7f
    if(integer::condition("JNZ",flags)) goto L00671f7f;
  }
  L00671f75: { // 0x671f75: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00671f7a: { // 0x671f7a: e8a1cde5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6758271u); flags=s.arithmetic_flags;
  }
  L00671f7f: { // 0x671f7f: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00671f84: { // 0x671f84: e8b7cde5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6758281u); flags=s.arithmetic_flags;
  }
  L00671f89: { // 0x671f89: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671f8b: { // 0x671f8b: 7537 JNZ 0x00671fc4
    if(integer::condition("JNZ",flags)) goto L00671fc4;
  }
  L00671f8d: { // 0x671f8d: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00671f92: { // 0x671f92: e889cde5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6758295u); flags=s.arithmetic_flags;
  }
  L00671f97: { // 0x671f97: eb2b JMP 0x00671fc4
    goto L00671fc4;
  }
  L00671f99: { // 0x671f99: e8a2cde5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6758302u); flags=s.arithmetic_flags;
  }
  L00671f9e: { // 0x671f9e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671fa0: { // 0x671fa0: 740a JZ 0x00671fac
    if(integer::condition("JZ",flags)) goto L00671fac;
  }
  L00671fa2: { // 0x671fa2: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00671fa7: { // 0x671fa7: e884cde5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6758316u); flags=s.arithmetic_flags;
  }
  L00671fac: { // 0x671fac: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00671fb1: { // 0x671fb1: e88acde5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6758326u); flags=s.arithmetic_flags;
  }
  L00671fb6: { // 0x671fb6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671fb8: { // 0x671fb8: 740a JZ 0x00671fc4
    if(integer::condition("JZ",flags)) goto L00671fc4;
  }
  L00671fba: { // 0x671fba: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00671fbf: { // 0x671fbf: e86ccde5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6758340u); flags=s.arithmetic_flags;
  }
  L00671fc4: { // 0x671fc4: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00671fc7: { // 0x671fc7: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00671fc9: { // 0x671fc9: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00671fcb: { // 0x671fcb: ff92d8000000 CALL dword ptr [EDX + 0xd8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d8u)),6758353u); flags=s.arithmetic_flags;
  }
  L00671fd1: { // 0x671fd1: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00671fd4: { // 0x671fd4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00671fd6: { // 0x671fd6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00671fd8: { // 0x671fd8: c685e24e000001 MOV byte ptr [EBP + 0x4ee2],0x1
    m.w8((s.bp+0x00004ee2u), 0x00000001u);
  }
  L00671fdf: { // 0x671fdf: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6758370u); flags=s.arithmetic_flags;
  }
  L00671fe2: { // 0x671fe2: 3b9dd84e0000 CMP EBX,dword ptr [EBP + 0x4ed8]
    (void)integer::sub(s.bx,m.r32((s.bp+0x00004ed8u)),32,flags);
  }
  L00671fe8: { // 0x671fe8: 7507 JNZ 0x00671ff1
    if(integer::condition("JNZ",flags)) goto L00671ff1;
  }
  L00671fea: { // 0x671fea: c6058c48aa0001 MOV byte ptr [0x00aa488c],0x1
    m.w8((0x00aa488cu), 0x00000001u);
  }
  L00671ff1: { // 0x671ff1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00671ff2: { // 0x671ff2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00671ff3: { // 0x671ff3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00671ff4: { // 0x671ff4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00671ff6: { // 0x671ff6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00671ff7: { // 0x671ff7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00671ffa: { // 0x671ffa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00671ffb: { // 0x671ffb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00671ffc: { // 0x671ffc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00671ffd: { // 0x671ffd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00671fff: { // 0x671fff: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00672000: { // 0x672000: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
