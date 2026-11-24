#include "heap1561_context.hpp"
#include "recovered/recovery_b1561_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1561 {
namespace {
void f_0017af00(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00157340(Memory&,State&,Frame&,const Operations&);
void f_00157280(Memory&,State&,Frame&,const Operations&);
void f_00176620(Memory&,State&,Frame&,const Operations&);
void f_0018be90(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0017af00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057af00: { trace_pc=0x0057af00u; // 0x57af00: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0057af01: { trace_pc=0x0057af01u; // 0x57af01: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0057af03: { trace_pc=0x0057af03u; // 0x57af03: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0057af06: { trace_pc=0x0057af06u; // 0x57af06: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L0057af09: { trace_pc=0x0057af09u; // 0x57af09: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0057af0a: { trace_pc=0x0057af0au; // 0x57af0a: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0057af0c: { trace_pc=0x0057af0cu; // 0x57af0c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057af0d: { trace_pc=0x0057af0du; // 0x57af0d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057af0e: { trace_pc=0x0057af0eu; // 0x57af0e: 8b434c MOV EAX,dword ptr [EBX + 0x4c]
    s.ax = m.r32((s.bx+0x0000004cu));
  }
  L0057af11: { trace_pc=0x0057af11u; // 0x57af11: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0057af15: { trace_pc=0x0057af15u; // 0x57af15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057af17: { trace_pc=0x0057af17u; // 0x57af17: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0057af1c: { trace_pc=0x0057af1cu; // 0x57af1c: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0057af20: { trace_pc=0x0057af20u; // 0x57af20: 7421 JZ 0x0057af43
    if(integer::condition("JZ",flags)) goto L0057af43;
  }
  L0057af22: { trace_pc=0x0057af22u; // 0x57af22: db8384010000 FILD dword ptr [EBX + 0x184]
    const auto address=(s.bx+0x00000184u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057af28: { trace_pc=0x0057af28u; // 0x57af28: da8b80010000 FIMUL dword ptr [EBX + 0x180]
    const auto address=(s.bx+0x00000180u);
    fimul32(s.fp,m.r32(address));
  }
  L0057af2e: { trace_pc=0x0057af2eu; // 0x57af2e: da4c2450 FIMUL dword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    fimul32(s.fp,m.r32(address));
  }
  L0057af32: { trace_pc=0x0057af32u; // 0x57af32: dc0d200f7900 FMUL double ptr [0x00790f20]
    const auto address=(0x00790f20u);
    s.fp.multiply64(read64(m,address));
  }
  L0057af38: { trace_pc=0x0057af38u; // 0x57af38: dc05f0677800 FADD double ptr [0x007867f0]
    const auto address=(0x007867f0u);
    s.fp.add64(read64(m,address));
  }
  L0057af3e: { trace_pc=0x0057af3eu; // 0x57af3e: e80dfb1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5746499u); flags=s.arithmetic_flags;
  }
  L0057af43: { trace_pc=0x0057af43u; // 0x57af43: 2b8304030000 SUB EAX,dword ptr [EBX + 0x304]
    s.ax = integer::sub(s.ax,m.r32((s.bx+0x00000304u)),32,flags);
  }
  L0057af49: { trace_pc=0x0057af49u; // 0x57af49: 83f84b CMP EAX,0x4b
    (void)integer::sub(s.ax,0x0000004bu,32,flags);
  }
  L0057af4c: { trace_pc=0x0057af4cu; // 0x57af4c: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0057af50: { trace_pc=0x0057af50u; // 0x57af50: 0f8eb60a0000 JLE 0x0057ba0c
    if(integer::condition("JLE",flags)) goto L0057ba0c;
  }
  L0057af56: { trace_pc=0x0057af56u; // 0x57af56: 8d7c0002 LEA EDI,[EAX + EAX*0x1 + 0x2]
    s.di = (s.ax+(s.ax * 0x00000001u)+0x00000002u);
  }
  L0057af5a: { trace_pc=0x0057af5au; // 0x57af5a: 83ff64 CMP EDI,0x64
    (void)integer::sub(s.di,0x00000064u,32,flags);
  }
  L0057af5d: { trace_pc=0x0057af5du; // 0x57af5d: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0057af5f: { trace_pc=0x0057af5fu; // 0x57af5f: 7f05 JG 0x0057af66
    if(integer::condition("JG",flags)) goto L0057af66;
  }
  L0057af61: { trace_pc=0x0057af61u; // 0x57af61: be64000000 MOV ESI,0x64
    s.si = 0x00000064u;
  }
  L0057af66: { trace_pc=0x0057af66u; // 0x57af66: 8d04f500000000 LEA EAX,[ESI*0x8 + 0x0]
    s.ax = ((s.si * 0x00000008u)+0x00000000u);
  }
  L0057af6d: { trace_pc=0x0057af6du; // 0x57af6d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057af6e: { trace_pc=0x0057af6eu; // 0x57af6e: e8e4291f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5746547u); flags=s.arithmetic_flags;
  }
  L0057af73: { trace_pc=0x0057af73u; // 0x57af73: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057af76: { trace_pc=0x0057af76u; // 0x57af76: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057af78: { trace_pc=0x0057af78u; // 0x57af78: 740b JZ 0x0057af85
    if(integer::condition("JZ",flags)) goto L0057af85;
  }
  L0057af7a: { trace_pc=0x0057af7au; // 0x57af7a: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0057af7b: { trace_pc=0x0057af7bu; // 0x57af7b: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0057af7f: { trace_pc=0x0057af7fu; // 0x57af7f: 89742460 MOV dword ptr [ESP + 0x60],ESI
    m.w32((f.sp+0x00000060u), s.si);
  }
  L0057af83: { trace_pc=0x0057af83u; // 0x57af83: eb08 JMP 0x0057af8d
    goto L0057af8d;
  }
  L0057af85: { trace_pc=0x0057af85u; // 0x57af85: c744242800000000 MOV dword ptr [ESP + 0x28],0x0
    m.w32((f.sp+0x00000028u), 0x00000000u);
  }
  L0057af8d: { trace_pc=0x0057af8du; // 0x57af8d: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  L0057af8f: { trace_pc=0x0057af8fu; // 0x57af8f: e8c3291f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5746580u); flags=s.arithmetic_flags;
  }
  L0057af94: { trace_pc=0x0057af94u; // 0x57af94: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0057af96: { trace_pc=0x0057af96u; // 0x57af96: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057af99: { trace_pc=0x0057af99u; // 0x57af99: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0057af9b: { trace_pc=0x0057af9bu; // 0x57af9b: 744a JZ 0x0057afe7
    if(integer::condition("JZ",flags)) goto L0057afe7;
  }
  L0057af9d: { trace_pc=0x0057af9du; // 0x57af9d: 83ff64 CMP EDI,0x64
    (void)integer::sub(s.di,0x00000064u,32,flags);
  }
  L0057afa0: { trace_pc=0x0057afa0u; // 0x57afa0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0057afa2: { trace_pc=0x0057afa2u; // 0x57afa2: 7f05 JG 0x0057afa9
    if(integer::condition("JG",flags)) goto L0057afa9;
  }
  L0057afa4: { trace_pc=0x0057afa4u; // 0x57afa4: b864000000 MOV EAX,0x64
    s.ax = 0x00000064u;
  }
  L0057afa9: { trace_pc=0x0057afa9u; // 0x57afa9: 8d0c8504000000 LEA ECX,[EAX*0x4 + 0x4]
    s.cx = ((s.ax * 0x00000004u)+0x00000004u);
  }
  L0057afb0: { trace_pc=0x0057afb0u; // 0x57afb0: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057afb2: { trace_pc=0x0057afb2u; // 0x57afb2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057afb3: { trace_pc=0x0057afb3u; // 0x57afb3: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0057afb6: { trace_pc=0x0057afb6u; // 0x57afb6: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  L0057afbd: { trace_pc=0x0057afbdu; // 0x57afbd: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L0057afbf: { trace_pc=0x0057afbfu; // 0x57afbf: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0057afc2: { trace_pc=0x0057afc2u; // 0x57afc2: e890291f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5746631u); flags=s.arithmetic_flags;
  }
  L0057afc7: { trace_pc=0x0057afc7u; // 0x57afc7: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0057afca: { trace_pc=0x0057afcau; // 0x57afca: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0057afcd: { trace_pc=0x0057afcdu; // 0x57afcd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057afd0: { trace_pc=0x0057afd0u; // 0x57afd0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057afd2: { trace_pc=0x0057afd2u; // 0x57afd2: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057afd4: { trace_pc=0x0057afd4u; // 0x57afd4: 7c15 JL 0x0057afeb
    if(integer::condition("JL",flags)) goto L0057afeb;
  }
  L0057afd6: { trace_pc=0x0057afd6u; // 0x57afd6: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057afd9: { trace_pc=0x0057afd9u; // 0x57afd9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057afda: { trace_pc=0x0057afdau; // 0x57afda: 897c82fc MOV dword ptr [EDX + EAX*0x4 + -0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.di);
  }
  L0057afde: { trace_pc=0x0057afdeu; // 0x57afde: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0057afe1: { trace_pc=0x0057afe1u; // 0x57afe1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057afe3: { trace_pc=0x0057afe3u; // 0x57afe3: 7ef1 JLE 0x0057afd6
    if(integer::condition("JLE",flags)) goto L0057afd6;
  }
  L0057afe5: { trace_pc=0x0057afe5u; // 0x57afe5: eb04 JMP 0x0057afeb
    goto L0057afeb;
  }
  L0057afe7: { trace_pc=0x0057afe7u; // 0x57afe7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057afe9: { trace_pc=0x0057afe9u; // 0x57afe9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057afeb: { trace_pc=0x0057afebu; // 0x57afeb: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057aff0: { trace_pc=0x0057aff0u; // 0x57aff0: e84bc3fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5746677u); flags=s.arithmetic_flags;
  }
  L0057aff5: { trace_pc=0x0057aff5u; // 0x57aff5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057affa: { trace_pc=0x0057affau; // 0x57affa: e881c2fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5746687u); flags=s.arithmetic_flags;
  }
  L0057afff: { trace_pc=0x0057afffu; // 0x57afff: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057b001: { trace_pc=0x0057b001u; // 0x57b001: 7435 JZ 0x0057b038
    if(integer::condition("JZ",flags)) goto L0057b038;
  }
  L0057b003: { trace_pc=0x0057b003u; // 0x57b003: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L0057b006: { trace_pc=0x0057b006u; // 0x57b006: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L0057b00a: { trace_pc=0x0057b00au; // 0x57b00a: 0fbf442452 MOVSX EAX,word ptr [ESP + 0x52]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000052u)),16));
  }
  L0057b00f: { trace_pc=0x0057b00fu; // 0x57b00f: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b016: { trace_pc=0x0057b016u; // 0x57b016: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057b019: { trace_pc=0x0057b019u; // 0x57b019: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057b01b: { trace_pc=0x0057b01bu; // 0x57b01b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b020: { trace_pc=0x0057b020u; // 0x57b020: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b023: { trace_pc=0x0057b023u; // 0x57b023: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0057b028: { trace_pc=0x0057b028u; // 0x57b028: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b02b: { trace_pc=0x0057b02bu; // 0x57b02b: 897c023c MOV dword ptr [EDX + EAX*0x1 + 0x3c],EDI
    m.w32((s.dx+(s.ax * 0x00000001u)+0x0000003cu), s.di);
  }
  L0057b02f: { trace_pc=0x0057b02fu; // 0x57b02f: e84cc2fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5746740u); flags=s.arithmetic_flags;
  }
  L0057b034: { trace_pc=0x0057b034u; // 0x57b034: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057b036: { trace_pc=0x0057b036u; // 0x57b036: 75cb JNZ 0x0057b003
    if(integer::condition("JNZ",flags)) goto L0057b003;
  }
  L0057b038: { trace_pc=0x0057b038u; // 0x57b038: 8b3d4c6b8300 MOV EDI,dword ptr [0x00836b4c]
    s.di = m.r32((0x00836b4cu));
  }
  L0057b03e: { trace_pc=0x0057b03eu; // 0x57b03e: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0057b041: { trace_pc=0x0057b041u; // 0x57b041: 0fafff IMUL EDI,EDI
    s.di = integer::imul(s.di,s.di,32,flags);
  }
  L0057b044: { trace_pc=0x0057b044u; // 0x57b044: 66833900 CMP word ptr [ECX],0x0
    (void)integer::sub(m.r16((s.cx)),0x00000000u,16,flags);
  }
  L0057b048: { trace_pc=0x0057b048u; // 0x57b048: 0f8513020000 JNZ 0x0057b261
    if(integer::condition("JNZ",flags)) goto L0057b261;
  }
  L0057b04e: { trace_pc=0x0057b04eu; // 0x57b04e: 6683790200 CMP word ptr [ECX + 0x2],0x0
    (void)integer::sub(m.r16((s.cx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b053: { trace_pc=0x0057b053u; // 0x57b053: 0f8508020000 JNZ 0x0057b261
    if(integer::condition("JNZ",flags)) goto L0057b261;
  }
  L0057b059: { trace_pc=0x0057b059u; // 0x57b059: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b05b: { trace_pc=0x0057b05bu; // 0x57b05b: 7e15 JLE 0x0057b072
    if(integer::condition("JLE",flags)) goto L0057b072;
  }
  L0057b05d: { trace_pc=0x0057b05du; // 0x57b05d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b05f: { trace_pc=0x0057b05fu; // 0x57b05f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b061: { trace_pc=0x0057b061u; // 0x57b061: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b067: { trace_pc=0x0057b067u; // 0x57b067: 83c050 ADD EAX,0x50
    s.ax = integer::add(s.ax,0x00000050u,32,flags);
  }
  L0057b06a: { trace_pc=0x0057b06au; // 0x57b06a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b06b: { trace_pc=0x0057b06bu; // 0x57b06b: c64410f400 MOV byte ptr [EAX + EDX*0x1 + -0xc],0x0
    m.w8((s.ax+(s.dx * 0x00000001u)-0x0000000cu), 0x00000000u);
  }
  L0057b070: { trace_pc=0x0057b070u; // 0x57b070: 75ef JNZ 0x0057b061
    if(integer::condition("JNZ",flags)) goto L0057b061;
  }
  L0057b072: { trace_pc=0x0057b072u; // 0x57b072: 6afe PUSH -0x2
    f.push(m,0xfffffffeu);
  }
  L0057b074: { trace_pc=0x0057b074u; // 0x57b074: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0057b076: { trace_pc=0x0057b076u; // 0x57b076: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0057b078: { trace_pc=0x0057b078u; // 0x57b078: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057b07a: { trace_pc=0x0057b07au; // 0x57b07a: e871390000 CALL 0x0057e9f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0057e9f0u,5746815u); flags=s.arithmetic_flags;
  }
  L0057b07f: { trace_pc=0x0057b07fu; // 0x57b07f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b081: { trace_pc=0x0057b081u; // 0x57b081: 7e39 JLE 0x0057b0bc
    if(integer::condition("JLE",flags)) goto L0057b0bc;
  }
  L0057b083: { trace_pc=0x0057b083u; // 0x57b083: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0057b085: { trace_pc=0x0057b085u; // 0x57b085: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0057b08a: { trace_pc=0x0057b08au; // 0x57b08a: 8d4c0238 LEA ECX,[EDX + EAX*0x1 + 0x38]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000038u);
  }
  L0057b08e: { trace_pc=0x0057b08eu; // 0x57b08e: 8b440238 MOV EAX,dword ptr [EDX + EAX*0x1 + 0x38]
    s.ax = m.r32((s.dx+(s.ax * 0x00000001u)+0x00000038u));
  }
  L0057b092: { trace_pc=0x0057b092u; // 0x57b092: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b094: { trace_pc=0x0057b094u; // 0x57b094: 7415 JZ 0x0057b0ab
    if(integer::condition("JZ",flags)) goto L0057b0ab;
  }
  L0057b096: { trace_pc=0x0057b096u; // 0x57b096: 3b8308030000 CMP EAX,dword ptr [EBX + 0x308]
    (void)integer::sub(s.ax,m.r32((s.bx+0x00000308u)),32,flags);
  }
  L0057b09c: { trace_pc=0x0057b09cu; // 0x57b09c: 740d JZ 0x0057b0ab
    if(integer::condition("JZ",flags)) goto L0057b0ab;
  }
  L0057b09e: { trace_pc=0x0057b09eu; // 0x57b09e: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L0057b0a1: { trace_pc=0x0057b0a1u; // 0x57b0a1: 7513 JNZ 0x0057b0b6
    if(integer::condition("JNZ",flags)) goto L0057b0b6;
  }
  L0057b0a3: { trace_pc=0x0057b0a3u; // 0x57b0a3: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L0057b0a9: { trace_pc=0x0057b0a9u; // 0x57b0a9: eb0b JMP 0x0057b0b6
    goto L0057b0b6;
  }
  L0057b0ab: { trace_pc=0x0057b0abu; // 0x57b0ab: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b0b1: { trace_pc=0x0057b0b1u; // 0x57b0b1: c6440a4401 MOV byte ptr [EDX + ECX*0x1 + 0x44],0x1
    m.w8((s.dx+(s.cx * 0x00000001u)+0x00000044u), 0x00000001u);
  }
  L0057b0b6: { trace_pc=0x0057b0b6u; // 0x57b0b6: 83c250 ADD EDX,0x50
    s.dx = integer::add(s.dx,0x00000050u,32,flags);
  }
  L0057b0b9: { trace_pc=0x0057b0b9u; // 0x57b0b9: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0057b0ba: { trace_pc=0x0057b0bau; // 0x57b0ba: 75c9 JNZ 0x0057b085
    if(integer::condition("JNZ",flags)) goto L0057b085;
  }
  L0057b0bc: { trace_pc=0x0057b0bcu; // 0x57b0bc: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0057b0bf: { trace_pc=0x0057b0bfu; // 0x57b0bf: 66833900 CMP word ptr [ECX],0x0
    (void)integer::sub(m.r16((s.cx)),0x00000000u,16,flags);
  }
  L0057b0c3: { trace_pc=0x0057b0c3u; // 0x57b0c3: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0057b0cb: { trace_pc=0x0057b0cbu; // 0x57b0cb: 0f85b0010000 JNZ 0x0057b281
    if(integer::condition("JNZ",flags)) goto L0057b281;
  }
  L0057b0d1: { trace_pc=0x0057b0d1u; // 0x57b0d1: 6683790200 CMP word ptr [ECX + 0x2],0x0
    (void)integer::sub(m.r16((s.cx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b0d6: { trace_pc=0x0057b0d6u; // 0x57b0d6: 0f85a5010000 JNZ 0x0057b281
    if(integer::condition("JNZ",flags)) goto L0057b281;
  }
  L0057b0dc: { trace_pc=0x0057b0dcu; // 0x57b0dc: a110a98100 MOV EAX,[0x0081a910]
    s.ax = m.r32((0x0081a910u));
  }
  L0057b0e1: { trace_pc=0x0057b0e1u; // 0x57b0e1: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L0057b0e9: { trace_pc=0x0057b0e9u; // 0x57b0e9: 8d58ff LEA EBX,[EAX + -0x1]
    s.bx = (s.ax-0x00000001u);
  }
  L0057b0ec: { trace_pc=0x0057b0ecu; // 0x57b0ec: 8d4b01 LEA ECX,[EBX + 0x1]
    s.cx = (s.bx+0x00000001u);
  }
  L0057b0ef: { trace_pc=0x0057b0efu; // 0x57b0ef: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0057b0f3: { trace_pc=0x0057b0f3u; // 0x57b0f3: df6c243c FILD qword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b0f7: { trace_pc=0x0057b0f7u; // 0x57b0f7: dd5c2468 FSTP double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b0fb: { trace_pc=0x0057b0fbu; // 0x57b0fb: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057b100: { trace_pc=0x0057b100u; // 0x57b100: e8db4c0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5746949u); flags=s.arithmetic_flags;
  }
  L0057b105: { trace_pc=0x0057b105u; // 0x57b105: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0057b109: { trace_pc=0x0057b109u; // 0x57b109: c744243800000000 MOV dword ptr [ESP + 0x38],0x0
    m.w32((f.sp+0x00000038u), 0x00000000u);
  }
  L0057b111: { trace_pc=0x0057b111u; // 0x57b111: df6c2434 FILD qword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b115: { trace_pc=0x0057b115u; // 0x57b115: dc4c2468 FMUL double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b119: { trace_pc=0x0057b119u; // 0x57b119: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b11f: { trace_pc=0x0057b11fu; // 0x57b11f: e82cf91e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5746980u); flags=s.arithmetic_flags;
  }
  L0057b124: { trace_pc=0x0057b124u; // 0x57b124: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0057b126: { trace_pc=0x0057b126u; // 0x57b126: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0057b128: { trace_pc=0x0057b128u; // 0x57b128: 77d1 JA 0x0057b0fb
    if(integer::condition("JA",flags)) goto L0057b0fb;
  }
  L0057b12a: { trace_pc=0x0057b12au; // 0x57b12a: 8b1514a98100 MOV EDX,dword ptr [0x0081a914]
    s.dx = m.r32((0x0081a914u));
  }
  L0057b130: { trace_pc=0x0057b130u; // 0x57b130: c744243000000000 MOV dword ptr [ESP + 0x30],0x0
    m.w32((f.sp+0x00000030u), 0x00000000u);
  }
  L0057b138: { trace_pc=0x0057b138u; // 0x57b138: 8d5aff LEA EBX,[EDX + -0x1]
    s.bx = (s.dx-0x00000001u);
  }
  L0057b13b: { trace_pc=0x0057b13bu; // 0x57b13b: 8d4301 LEA EAX,[EBX + 0x1]
    s.ax = (s.bx+0x00000001u);
  }
  L0057b13e: { trace_pc=0x0057b13eu; // 0x57b13e: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0057b142: { trace_pc=0x0057b142u; // 0x57b142: df6c242c FILD qword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b146: { trace_pc=0x0057b146u; // 0x57b146: dd5c2468 FSTP double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b14a: { trace_pc=0x0057b14au; // 0x57b14a: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057b14f: { trace_pc=0x0057b14fu; // 0x57b14f: e88c4c0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5747028u); flags=s.arithmetic_flags;
  }
  L0057b154: { trace_pc=0x0057b154u; // 0x57b154: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0057b158: { trace_pc=0x0057b158u; // 0x57b158: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
  L0057b160: { trace_pc=0x0057b160u; // 0x57b160: df6c241c FILD qword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b164: { trace_pc=0x0057b164u; // 0x57b164: dc4c2468 FMUL double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b168: { trace_pc=0x0057b168u; // 0x57b168: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b16e: { trace_pc=0x0057b16eu; // 0x57b16e: e8ddf81e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5747059u); flags=s.arithmetic_flags;
  }
  L0057b173: { trace_pc=0x0057b173u; // 0x57b173: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057b175: { trace_pc=0x0057b175u; // 0x57b175: 77d3 JA 0x0057b14a
    if(integer::condition("JA",flags)) goto L0057b14a;
  }
  L0057b177: { trace_pc=0x0057b177u; // 0x57b177: 668b1510a98100 MOV DX,word ptr [0x0081a910]
    s.dx = with_ax(s.dx, m.r16((0x0081a910u)));
  }
  L0057b17e: { trace_pc=0x0057b17eu; // 0x57b17e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b180: { trace_pc=0x0057b180u; // 0x57b180: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0057b182: { trace_pc=0x0057b182u; // 0x57b182: 66894c245a MOV word ptr [ESP + 0x5a],CX
    m.w16((f.sp+0x0000005au), (s.cx & 0xffffu));
  }
  L0057b187: { trace_pc=0x0057b187u; // 0x57b187: 8b4c245a MOV ECX,dword ptr [ESP + 0x5a]
    s.cx = m.r32((f.sp+0x0000005au));
  }
  L0057b18b: { trace_pc=0x0057b18bu; // 0x57b18b: 6689542452 MOV word ptr [ESP + 0x52],DX
    m.w16((f.sp+0x00000052u), (s.dx & 0xffffu));
  }
  L0057b190: { trace_pc=0x0057b190u; // 0x57b190: 8b542452 MOV EDX,dword ptr [ESP + 0x52]
    s.dx = m.r32((f.sp+0x00000052u));
  }
  L0057b194: { trace_pc=0x0057b194u; // 0x57b194: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0057b195: { trace_pc=0x0057b195u; // 0x57b195: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057b197: { trace_pc=0x0057b197u; // 0x57b197: 66897c2460 MOV word ptr [ESP + 0x60],DI
    m.w16((f.sp+0x00000060u), (s.di & 0xffffu));
  }
  L0057b19c: { trace_pc=0x0057b19cu; // 0x57b19c: 66894c2462 MOV word ptr [ESP + 0x62],CX
    m.w16((f.sp+0x00000062u), (s.cx & 0xffffu));
  }
  L0057b1a1: { trace_pc=0x0057b1a1u; // 0x57b1a1: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L0057b1a5: { trace_pc=0x0057b1a5u; // 0x57b1a5: 8b542462 MOV EDX,dword ptr [ESP + 0x62]
    s.dx = m.r32((f.sp+0x00000062u));
  }
  L0057b1a9: { trace_pc=0x0057b1a9u; // 0x57b1a9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0057b1ab: { trace_pc=0x0057b1abu; // 0x57b1ab: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b1ad: { trace_pc=0x0057b1adu; // 0x57b1ad: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L0057b1b2: { trace_pc=0x0057b1b2u; // 0x57b1b2: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L0057b1b7: { trace_pc=0x0057b1b7u; // 0x57b1b7: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L0057b1bb: { trace_pc=0x0057b1bbu; // 0x57b1bb: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0057b1bf: { trace_pc=0x0057b1bfu; // 0x57b1bf: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0057b1c3: { trace_pc=0x0057b1c3u; // 0x57b1c3: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0057b1c4: { trace_pc=0x0057b1c4u; // 0x57b1c4: 81fac8000000 CMP EDX,0xc8
    (void)integer::sub(s.dx,0x000000c8u,32,flags);
  }
  L0057b1ca: { trace_pc=0x0057b1cau; // 0x57b1ca: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0057b1ce: { trace_pc=0x0057b1ceu; // 0x57b1ce: 0f8d38080000 JGE 0x0057ba0c
    if(integer::condition("JGE",flags)) goto L0057ba0c;
  }
  L0057b1d4: { trace_pc=0x0057b1d4u; // 0x57b1d4: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b1da: { trace_pc=0x0057b1dau; // 0x57b1da: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057b1dc: { trace_pc=0x0057b1dcu; // 0x57b1dc: 0f84fafeffff JZ 0x0057b0dc
    if(integer::condition("JZ",flags)) goto L0057b0dc;
  }
  L0057b1e2: { trace_pc=0x0057b1e2u; // 0x57b1e2: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057b1e5: { trace_pc=0x0057b1e5u; // 0x57b1e5: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b1ec: { trace_pc=0x0057b1ecu; // 0x57b1ec: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057b1ef: { trace_pc=0x0057b1efu; // 0x57b1ef: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057b1f1: { trace_pc=0x0057b1f1u; // 0x57b1f1: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b1f4: { trace_pc=0x0057b1f4u; // 0x57b1f4: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b1f7: { trace_pc=0x0057b1f7u; // 0x57b1f7: 8b4c1038 MOV ECX,dword ptr [EAX + EDX*0x1 + 0x38]
    s.cx = m.r32((s.ax+(s.dx * 0x00000001u)+0x00000038u));
  }
  L0057b1fb: { trace_pc=0x0057b1fbu; // 0x57b1fb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b1fd: { trace_pc=0x0057b1fdu; // 0x57b1fd: 0f85d9feffff JNZ 0x0057b0dc
    if(integer::condition("JNZ",flags)) goto L0057b0dc;
  }
  L0057b203: { trace_pc=0x0057b203u; // 0x57b203: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0057b207: { trace_pc=0x0057b207u; // 0x57b207: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b208: { trace_pc=0x0057b208u; // 0x57b208: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b20d: { trace_pc=0x0057b20du; // 0x57b20d: e8eea2fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5747218u); flags=s.arithmetic_flags;
  }
  L0057b212: { trace_pc=0x0057b212u; // 0x57b212: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057b214: { trace_pc=0x0057b214u; // 0x57b214: e877ffefff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5747225u); flags=s.arithmetic_flags;
  }
  L0057b219: { trace_pc=0x0057b219u; // 0x57b219: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b21b: { trace_pc=0x0057b21bu; // 0x57b21b: 0f84bbfeffff JZ 0x0057b0dc
    if(integer::condition("JZ",flags)) goto L0057b0dc;
  }
  L0057b221: { trace_pc=0x0057b221u; // 0x57b221: 0fbf44241a MOVSX EAX,word ptr [ESP + 0x1a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001au)),16));
  }
  L0057b226: { trace_pc=0x0057b226u; // 0x57b226: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b22d: { trace_pc=0x0057b22du; // 0x57b22d: 0fbf542418 MOVSX EDX,word ptr [ESP + 0x18]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  L0057b232: { trace_pc=0x0057b232u; // 0x57b232: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b238: { trace_pc=0x0057b238u; // 0x57b238: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b23a: { trace_pc=0x0057b23au; // 0x57b23a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b23d: { trace_pc=0x0057b23du; // 0x57b23d: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b240: { trace_pc=0x0057b240u; // 0x57b240: 8a540844 MOV DL,byte ptr [EAX + ECX*0x1 + 0x44]
    s.dx = with_al(s.dx, m.r8((s.ax+(s.cx * 0x00000001u)+0x00000044u)));
  }
  L0057b244: { trace_pc=0x0057b244u; // 0x57b244: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0057b246: { trace_pc=0x0057b246u; // 0x57b246: 0f8490feffff JZ 0x0057b0dc
    if(integer::condition("JZ",flags)) goto L0057b0dc;
  }
  L0057b24c: { trace_pc=0x0057b24cu; // 0x57b24c: 817c2424c8000000 CMP dword ptr [ESP + 0x24],0xc8
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x000000c8u,32,flags);
  }
  L0057b254: { trace_pc=0x0057b254u; // 0x57b254: 7c31 JL 0x0057b287
    if(integer::condition("JL",flags)) goto L0057b287;
  }
  L0057b256: { trace_pc=0x0057b256u; // 0x57b256: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0057b258: { trace_pc=0x0057b258u; // 0x57b258: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057b259: { trace_pc=0x0057b259u; // 0x57b259: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057b25a: { trace_pc=0x0057b25au; // 0x57b25a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057b25b: { trace_pc=0x0057b25bu; // 0x57b25b: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057b25d: { trace_pc=0x0057b25du; // 0x57b25d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057b25e: { trace_pc=0x0057b25eu; // 0x57b25e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057b261: { trace_pc=0x0057b261u; // 0x57b261: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b263: { trace_pc=0x0057b263u; // 0x57b263: 0f8e56feffff JLE 0x0057b0bf
    if(integer::condition("JLE",flags)) goto L0057b0bf;
  }
  L0057b269: { trace_pc=0x0057b269u; // 0x57b269: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b26b: { trace_pc=0x0057b26bu; // 0x57b26b: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b271: { trace_pc=0x0057b271u; // 0x57b271: 83c050 ADD EAX,0x50
    s.ax = integer::add(s.ax,0x00000050u,32,flags);
  }
  L0057b274: { trace_pc=0x0057b274u; // 0x57b274: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0057b275: { trace_pc=0x0057b275u; // 0x57b275: c64410f401 MOV byte ptr [EAX + EDX*0x1 + -0xc],0x1
    m.w8((s.ax+(s.dx * 0x00000001u)-0x0000000cu), 0x00000001u);
  }
  L0057b27a: { trace_pc=0x0057b27au; // 0x57b27a: 75ef JNZ 0x0057b26b
    if(integer::condition("JNZ",flags)) goto L0057b26b;
  }
  L0057b27c: { trace_pc=0x0057b27cu; // 0x57b27c: e93efeffff JMP 0x0057b0bf
    goto L0057b0bf;
  }
  L0057b281: { trace_pc=0x0057b281u; // 0x57b281: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0057b283: { trace_pc=0x0057b283u; // 0x57b283: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0057b287: { trace_pc=0x0057b287u; // 0x57b287: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0057b28b: { trace_pc=0x0057b28bu; // 0x57b28b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057b28d: { trace_pc=0x0057b28du; // 0x57b28d: 83f94c CMP ECX,0x4c
    (void)integer::sub(s.cx,0x0000004cu,32,flags);
  }
  L0057b290: { trace_pc=0x0057b290u; // 0x57b290: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0057b294: { trace_pc=0x0057b294u; // 0x57b294: c74424444c000000 MOV dword ptr [ESP + 0x44],0x4c
    m.w32((f.sp+0x00000044u), 0x0000004cu);
  }
  L0057b29c: { trace_pc=0x0057b29cu; // 0x57b29c: 7c04 JL 0x0057b2a2
    if(integer::condition("JL",flags)) goto L0057b2a2;
  }
  L0057b29e: { trace_pc=0x0057b29eu; // 0x57b29e: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0057b2a2: { trace_pc=0x0057b2a2u; // 0x57b2a2: b8abaaaa2a MOV EAX,0x2aaaaaab
    s.ax = 0x2aaaaaabu;
  }
  L0057b2a7: { trace_pc=0x0057b2a7u; // 0x57b2a7: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0057b2a9: { trace_pc=0x0057b2a9u; // 0x57b2a9: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b2ad: { trace_pc=0x0057b2adu; // 0x57b2ad: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b2b1: { trace_pc=0x0057b2b1u; // 0x57b2b1: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0057b2b3: { trace_pc=0x0057b2b3u; // 0x57b2b3: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0057b2b6: { trace_pc=0x0057b2b6u; // 0x57b2b6: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0057b2b8: { trace_pc=0x0057b2b8u; // 0x57b2b8: b856555555 MOV EAX,0x55555556
    s.ax = 0x55555556u;
  }
  L0057b2bd: { trace_pc=0x0057b2bdu; // 0x57b2bd: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0057b2c1: { trace_pc=0x0057b2c1u; // 0x57b2c1: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0057b2c3: { trace_pc=0x0057b2c3u; // 0x57b2c3: db442450 FILD dword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b2c7: { trace_pc=0x0057b2c7u; // 0x57b2c7: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b2cb: { trace_pc=0x0057b2cbu; // 0x57b2cb: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057b2cd: { trace_pc=0x0057b2cdu; // 0x57b2cd: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0057b2d0: { trace_pc=0x0057b2d0u; // 0x57b2d0: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0057b2d2: { trace_pc=0x0057b2d2u; // 0x57b2d2: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0057b2d6: { trace_pc=0x0057b2d6u; // 0x57b2d6: db442450 FILD dword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b2da: { trace_pc=0x0057b2dau; // 0x57b2da: dd542458 FST double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057b2de: { trace_pc=0x0057b2deu; // 0x57b2de: dc642460 FSUB double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.subtract64(read64(m,address));
  }
  L0057b2e2: { trace_pc=0x0057b2e2u; // 0x57b2e2: dc5c2448 FCOMP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b2e6: { trace_pc=0x0057b2e6u; // 0x57b2e6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b2e8: { trace_pc=0x0057b2e8u; // 0x57b2e8: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b2eb: { trace_pc=0x0057b2ebu; // 0x57b2eb: 7415 JZ 0x0057b302
    if(integer::condition("JZ",flags)) goto L0057b302;
  }
  L0057b2ed: { trace_pc=0x0057b2edu; // 0x57b2ed: dd442458 FLD double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load64(read64(m,address));
  }
  L0057b2f1: { trace_pc=0x0057b2f1u; // 0x57b2f1: dc442460 FADD double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.add64(read64(m,address));
  }
  L0057b2f5: { trace_pc=0x0057b2f5u; // 0x57b2f5: dc1d180f7900 FCOMP double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b2fb: { trace_pc=0x0057b2fbu; // 0x57b2fb: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b2fd: { trace_pc=0x0057b2fdu; // 0x57b2fd: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057b300: { trace_pc=0x0057b300u; // 0x57b300: 741e JZ 0x0057b320
    if(integer::condition("JZ",flags)) goto L0057b320;
  }
  L0057b302: { trace_pc=0x0057b302u; // 0x57b302: dd442448 FLD double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load64(read64(m,address));
  }
  L0057b306: { trace_pc=0x0057b306u; // 0x57b306: dc25180f7900 FSUB double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.subtract64(read64(m,address));
  }
  L0057b30c: { trace_pc=0x0057b30cu; // 0x57b30c: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b312: { trace_pc=0x0057b312u; // 0x57b312: dd542460 FST double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057b316: { trace_pc=0x0057b316u; // 0x57b316: dc05180f7900 FADD double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.add64(read64(m,address));
  }
  L0057b31c: { trace_pc=0x0057b31cu; // 0x57b31c: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b320: { trace_pc=0x0057b320u; // 0x57b320: b96879a500 MOV ECX,0xa57968
    s.cx = 0x00a57968u;
  }
  L0057b325: { trace_pc=0x0057b325u; // 0x57b325: e8f6b2ffff CALL 0x00576620
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576620u,5747498u); flags=s.arithmetic_flags;
  }
  L0057b32a: { trace_pc=0x0057b32au; // 0x57b32a: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b32e: { trace_pc=0x0057b32eu; // 0x57b32e: dc442458 FADD double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.add64(read64(m,address));
  }
  L0057b332: { trace_pc=0x0057b332u; // 0x57b332: dd542450 FST double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057b336: { trace_pc=0x0057b336u; // 0x57b336: dc1d180f7900 FCOMP double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b33c: { trace_pc=0x0057b33cu; // 0x57b33c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b33e: { trace_pc=0x0057b33eu; // 0x57b33e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057b341: { trace_pc=0x0057b341u; // 0x57b341: 75dd JNZ 0x0057b320
    if(integer::condition("JNZ",flags)) goto L0057b320;
  }
  L0057b343: { trace_pc=0x0057b343u; // 0x57b343: dd442450 FLD double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load64(read64(m,address));
  }
  L0057b347: { trace_pc=0x0057b347u; // 0x57b347: dc5c2448 FCOMP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b34b: { trace_pc=0x0057b34bu; // 0x57b34b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b34d: { trace_pc=0x0057b34du; // 0x57b34d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b350: { trace_pc=0x0057b350u; // 0x57b350: 74ce JZ 0x0057b320
    if(integer::condition("JZ",flags)) goto L0057b320;
  }
  L0057b352: { trace_pc=0x0057b352u; // 0x57b352: dd442450 FLD double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load64(read64(m,address));
  }
  L0057b356: { trace_pc=0x0057b356u; // 0x57b356: e8f5f61e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5747547u); flags=s.arithmetic_flags;
  }
  L0057b35b: { trace_pc=0x0057b35bu; // 0x57b35b: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b35d: { trace_pc=0x0057b35du; // 0x57b35d: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0057b361: { trace_pc=0x0057b361u; // 0x57b361: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b363: { trace_pc=0x0057b363u; // 0x57b363: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057b365: { trace_pc=0x0057b365u; // 0x57b365: 7c0e JL 0x0057b375
    if(integer::condition("JL",flags)) goto L0057b375;
  }
  L0057b367: { trace_pc=0x0057b367u; // 0x57b367: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057b36a: { trace_pc=0x0057b36au; // 0x57b36a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057b36b: { trace_pc=0x0057b36bu; // 0x57b36b: 895c82fc MOV dword ptr [EDX + EAX*0x4 + -0x4],EBX
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.bx);
  }
  L0057b36f: { trace_pc=0x0057b36fu; // 0x57b36f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b371: { trace_pc=0x0057b371u; // 0x57b371: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057b373: { trace_pc=0x0057b373u; // 0x57b373: 7ef2 JLE 0x0057b367
    if(integer::condition("JLE",flags)) goto L0057b367;
  }
  L0057b375: { trace_pc=0x0057b375u; // 0x57b375: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0057b379: { trace_pc=0x0057b379u; // 0x57b379: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L0057b37b: { trace_pc=0x0057b37bu; // 0x57b37b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0057b37f: { trace_pc=0x0057b37fu; // 0x57b37f: c744243401000000 MOV dword ptr [ESP + 0x34],0x1
    m.w32((f.sp+0x00000034u), 0x00000001u);
  }
  L0057b387: { trace_pc=0x0057b387u; // 0x57b387: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0057b389: { trace_pc=0x0057b389u; // 0x57b389: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L0057b38c: { trace_pc=0x0057b38cu; // 0x57b38c: 0fbf44241a MOVSX EAX,word ptr [ESP + 0x1a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001au)),16));
  }
  L0057b391: { trace_pc=0x0057b391u; // 0x57b391: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b398: { trace_pc=0x0057b398u; // 0x57b398: 0fbf4c2418 MOVSX ECX,word ptr [ESP + 0x18]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  L0057b39d: { trace_pc=0x0057b39du; // 0x57b39d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057b39f: { trace_pc=0x0057b39fu; // 0x57b39f: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b3a2: { trace_pc=0x0057b3a2u; // 0x57b3a2: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0057b3a6: { trace_pc=0x0057b3a6u; // 0x57b3a6: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b3a9: { trace_pc=0x0057b3a9u; // 0x57b3a9: 8b8808030000 MOV ECX,dword ptr [EAX + 0x308]
    s.cx = m.r32((s.ax+0x00000308u));
  }
  L0057b3af: { trace_pc=0x0057b3afu; // 0x57b3af: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0057b3b4: { trace_pc=0x0057b3b4u; // 0x57b3b4: 894c023c MOV dword ptr [EDX + EAX*0x1 + 0x3c],ECX
    m.w32((s.dx+(s.ax * 0x00000001u)+0x0000003cu), s.cx);
  }
  L0057b3b8: { trace_pc=0x0057b3b8u; // 0x57b3b8: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b3ba: { trace_pc=0x0057b3bau; // 0x57b3ba: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0057b3bd: { trace_pc=0x0057b3bdu; // 0x57b3bd: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b3be: { trace_pc=0x0057b3beu; // 0x57b3be: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057b3c0: { trace_pc=0x0057b3c0u; // 0x57b3c0: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0057b3c4: { trace_pc=0x0057b3c4u; // 0x57b3c4: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0057b3c7: { trace_pc=0x0057b3c7u; // 0x57b3c7: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b3c9: { trace_pc=0x0057b3c9u; // 0x57b3c9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b3cb: { trace_pc=0x0057b3cbu; // 0x57b3cb: 7345 JNC 0x0057b412
    if(integer::condition("JNC",flags)) goto L0057b412;
  }
  L0057b3cd: { trace_pc=0x0057b3cdu; // 0x57b3cd: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b3d0: { trace_pc=0x0057b3d0u; // 0x57b3d0: 7623 JBE 0x0057b3f5
    if(integer::condition("JBE",flags)) goto L0057b3f5;
  }
  L0057b3d2: { trace_pc=0x0057b3d2u; // 0x57b3d2: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L0057b3d5: { trace_pc=0x0057b3d5u; // 0x57b3d5: 8b0493 MOV EAX,dword ptr [EBX + EDX*0x4]
    s.ax = m.r32((s.bx+(s.dx * 0x00000004u)));
  }
  L0057b3d8: { trace_pc=0x0057b3d8u; // 0x57b3d8: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0057b3db: { trace_pc=0x0057b3dbu; // 0x57b3db: d85c2450 FCOMP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0057b3df: { trace_pc=0x0057b3dfu; // 0x57b3df: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b3e1: { trace_pc=0x0057b3e1u; // 0x57b3e1: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b3e4: { trace_pc=0x0057b3e4u; // 0x57b3e4: 750f JNZ 0x0057b3f5
    if(integer::condition("JNZ",flags)) goto L0057b3f5;
  }
  L0057b3e6: { trace_pc=0x0057b3e6u; // 0x57b3e6: 8b0493 MOV EAX,dword ptr [EBX + EDX*0x4]
    s.ax = m.r32((s.bx+(s.dx * 0x00000004u)));
  }
  L0057b3e9: { trace_pc=0x0057b3e9u; // 0x57b3e9: 89048b MOV dword ptr [EBX + ECX*0x4],EAX
    m.w32((s.bx+(s.cx * 0x00000004u)), s.ax);
  }
  L0057b3ec: { trace_pc=0x0057b3ecu; // 0x57b3ec: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057b3ee: { trace_pc=0x0057b3eeu; // 0x57b3ee: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b3f0: { trace_pc=0x0057b3f0u; // 0x57b3f0: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b3f3: { trace_pc=0x0057b3f3u; // 0x57b3f3: 77dd JA 0x0057b3d2
    if(integer::condition("JA",flags)) goto L0057b3d2;
  }
  L0057b3f5: { trace_pc=0x0057b3f5u; // 0x57b3f5: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057b3f8: { trace_pc=0x0057b3f8u; // 0x57b3f8: 893c8a MOV dword ptr [EDX + ECX*0x4],EDI
    m.w32((s.dx+(s.cx * 0x00000004u)), s.di);
  }
  L0057b3fb: { trace_pc=0x0057b3fbu; // 0x57b3fb: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b3fd: { trace_pc=0x0057b3fdu; // 0x57b3fd: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0057b400: { trace_pc=0x0057b400u; // 0x57b400: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b401: { trace_pc=0x0057b401u; // 0x57b401: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0057b403: { trace_pc=0x0057b403u; // 0x57b403: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b405: { trace_pc=0x0057b405u; // 0x57b405: 7603 JBE 0x0057b40a
    if(integer::condition("JBE",flags)) goto L0057b40a;
  }
  L0057b407: { trace_pc=0x0057b407u; // 0x57b407: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0057b40a: { trace_pc=0x0057b40au; // 0x57b40a: 3b7e10 CMP EDI,dword ptr [ESI + 0x10]
    (void)integer::sub(s.di,m.r32((s.si+0x00000010u)),32,flags);
  }
  L0057b40d: { trace_pc=0x0057b40du; // 0x57b40d: 7303 JNC 0x0057b412
    if(integer::condition("JNC",flags)) goto L0057b412;
  }
  L0057b40f: { trace_pc=0x0057b40fu; // 0x57b40f: 897e10 MOV dword ptr [ESI + 0x10],EDI
    m.w32((s.si+0x00000010u), s.di);
  }
  L0057b412: { trace_pc=0x0057b412u; // 0x57b412: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b414: { trace_pc=0x0057b414u; // 0x57b414: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b416: { trace_pc=0x0057b416u; // 0x57b416: 7428 JZ 0x0057b440
    if(integer::condition("JZ",flags)) goto L0057b440;
  }
  L0057b418: { trace_pc=0x0057b418u; // 0x57b418: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b41b: { trace_pc=0x0057b41bu; // 0x57b41b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b41d: { trace_pc=0x0057b41du; // 0x57b41d: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b420: { trace_pc=0x0057b420u; // 0x57b420: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b423: { trace_pc=0x0057b423u; // 0x57b423: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057b426: { trace_pc=0x0057b426u; // 0x57b426: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b428: { trace_pc=0x0057b428u; // 0x57b428: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b42b: { trace_pc=0x0057b42bu; // 0x57b42b: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057b432: { trace_pc=0x0057b432u; // 0x57b432: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b434: { trace_pc=0x0057b434u; // 0x57b434: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b435: { trace_pc=0x0057b435u; // 0x57b435: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b437: { trace_pc=0x0057b437u; // 0x57b437: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b439: { trace_pc=0x0057b439u; // 0x57b439: e8520a0100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5747774u); flags=s.arithmetic_flags;
  }
  L0057b43e: { trace_pc=0x0057b43eu; // 0x57b43e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b440: { trace_pc=0x0057b440u; // 0x57b440: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0057b444: { trace_pc=0x0057b444u; // 0x57b444: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0057b448: { trace_pc=0x0057b448u; // 0x57b448: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b44a: { trace_pc=0x0057b44au; // 0x57b44a: 0f8edd020000 JLE 0x0057b72d
    if(integer::condition("JLE",flags)) goto L0057b72d;
  }
  L0057b450: { trace_pc=0x0057b450u; // 0x57b450: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b456: { trace_pc=0x0057b456u; // 0x57b456: eb0a JMP 0x0057b462
    goto L0057b462;
  }
  L0057b458: { trace_pc=0x0057b458u; // 0x57b458: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b45e: { trace_pc=0x0057b45eu; // 0x57b45e: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0057b462: { trace_pc=0x0057b462u; // 0x57b462: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b464: { trace_pc=0x0057b464u; // 0x57b464: 0f84c3020000 JZ 0x0057b72d
    if(integer::condition("JZ",flags)) goto L0057b72d;
  }
  L0057b46a: { trace_pc=0x0057b46au; // 0x57b46a: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0057b46e: { trace_pc=0x0057b46eu; // 0x57b46e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b470: { trace_pc=0x0057b470u; // 0x57b470: 0f84b7020000 JZ 0x0057b72d
    if(integer::condition("JZ",flags)) goto L0057b72d;
  }
  L0057b476: { trace_pc=0x0057b476u; // 0x57b476: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057b478: { trace_pc=0x0057b478u; // 0x57b478: 7424 JZ 0x0057b49e
    if(integer::condition("JZ",flags)) goto L0057b49e;
  }
  L0057b47a: { trace_pc=0x0057b47au; // 0x57b47a: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0057b47e: { trace_pc=0x0057b47eu; // 0x57b47e: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b485: { trace_pc=0x0057b485u; // 0x57b485: 0fbf39 MOVSX EDI,word ptr [ECX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0057b488: { trace_pc=0x0057b488u; // 0x57b488: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0057b48a: { trace_pc=0x0057b48au; // 0x57b48a: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b48e: { trace_pc=0x0057b48eu; // 0x57b48e: 8bbf08030000 MOV EDI,dword ptr [EDI + 0x308]
    s.di = m.r32((s.di+0x00000308u));
  }
  L0057b494: { trace_pc=0x0057b494u; // 0x57b494: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b497: { trace_pc=0x0057b497u; // 0x57b497: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b49a: { trace_pc=0x0057b49au; // 0x57b49a: 897c1038 MOV dword ptr [EAX + EDX*0x1 + 0x38],EDI
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000038u), s.di);
  }
  L0057b49e: { trace_pc=0x0057b49eu; // 0x57b49e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b49f: { trace_pc=0x0057b49fu; // 0x57b49f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b4a4: { trace_pc=0x0057b4a4u; // 0x57b4a4: e857a0fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5747881u); flags=s.arithmetic_flags;
  }
  L0057b4a9: { trace_pc=0x0057b4a9u; // 0x57b4a9: 8b0db8a1a300 MOV ECX,dword ptr [0x00a3a1b8]
    s.cx = m.r32((0x00a3a1b8u));
  }
  L0057b4af: { trace_pc=0x0057b4afu; // 0x57b4af: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0057b4b3: { trace_pc=0x0057b4b3u; // 0x57b4b3: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0057b4b6: { trace_pc=0x0057b4b6u; // 0x57b4b6: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0057b4bd: { trace_pc=0x0057b4bdu; // 0x57b4bd: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0057b4c1: { trace_pc=0x0057b4c1u; // 0x57b4c1: c744243c00000000 MOV dword ptr [ESP + 0x3c],0x0
    m.w32((f.sp+0x0000003cu), 0x00000000u);
  }
  L0057b4c9: { trace_pc=0x0057b4c9u; // 0x57b4c9: 8d1cc2 LEA EBX,[EDX + EAX*0x8]
    s.bx = (s.dx+(s.ax * 0x00000008u));
  }
  L0057b4cc: { trace_pc=0x0057b4ccu; // 0x57b4cc: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0057b4d0: { trace_pc=0x0057b4d0u; // 0x57b4d0: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0057b4d4: { trace_pc=0x0057b4d4u; // 0x57b4d4: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L0057b4d7: { trace_pc=0x0057b4d7u; // 0x57b4d7: 8b3d3486a500 MOV EDI,dword ptr [0x00a58634]
    s.di = m.r32((0x00a58634u));
  }
  L0057b4dd: { trace_pc=0x0057b4ddu; // 0x57b4dd: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L0057b4e0: { trace_pc=0x0057b4e0u; // 0x57b4e0: 6603048da09d8300 ADD AX,word ptr [ECX*0x4 + 0x839da0]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16(((s.cx * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L0057b4e8: { trace_pc=0x0057b4e8u; // 0x57b4e8: 8d0c8da09d8300 LEA ECX,[ECX*0x4 + 0x839da0]
    s.cx = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  L0057b4ef: { trace_pc=0x0057b4efu; // 0x57b4ef: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L0057b4f3: { trace_pc=0x0057b4f3u; // 0x57b4f3: 6689442448 MOV word ptr [ESP + 0x48],AX
    m.w16((f.sp+0x00000048u), (s.ax & 0xffffu));
  }
  L0057b4f8: { trace_pc=0x0057b4f8u; // 0x57b4f8: 66034a02 ADD CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L0057b4fc: { trace_pc=0x0057b4fcu; // 0x57b4fc: 66894c244a MOV word ptr [ESP + 0x4a],CX
    m.w16((f.sp+0x0000004au), (s.cx & 0xffffu));
  }
  L0057b501: { trace_pc=0x0057b501u; // 0x57b501: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0057b505: { trace_pc=0x0057b505u; // 0x57b505: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0057b509: { trace_pc=0x0057b509u; // 0x57b509: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057b50c: { trace_pc=0x0057b50cu; // 0x57b50c: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057b50f: { trace_pc=0x0057b50fu; // 0x57b50f: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L0057b512: { trace_pc=0x0057b512u; // 0x57b512: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057b514: { trace_pc=0x0057b514u; // 0x57b514: 0f8eb0010000 JLE 0x0057b6ca
    if(integer::condition("JLE",flags)) goto L0057b6ca;
  }
  L0057b51a: { trace_pc=0x0057b51au; // 0x57b51a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0057b51c: { trace_pc=0x0057b51cu; // 0x57b51c: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0057b51e: { trace_pc=0x0057b51eu; // 0x57b51e: 3b3d3486a500 CMP EDI,dword ptr [0x00a58634]
    (void)integer::sub(s.di,m.r32((0x00a58634u)),32,flags);
  }
  L0057b524: { trace_pc=0x0057b524u; // 0x57b524: 0f8da0010000 JGE 0x0057b6ca
    if(integer::condition("JGE",flags)) goto L0057b6ca;
  }
  L0057b52a: { trace_pc=0x0057b52au; // 0x57b52a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0057b52c: { trace_pc=0x0057b52cu; // 0x57b52c: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0057b52e: { trace_pc=0x0057b52eu; // 0x57b52e: 3b3d3486a500 CMP EDI,dword ptr [0x00a58634]
    (void)integer::sub(s.di,m.r32((0x00a58634u)),32,flags);
  }
  L0057b534: { trace_pc=0x0057b534u; // 0x57b534: 0f8d90010000 JGE 0x0057b6ca
    if(integer::condition("JGE",flags)) goto L0057b6ca;
  }
  L0057b53a: { trace_pc=0x0057b53au; // 0x57b53a: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L0057b540: { trace_pc=0x0057b540u; // 0x57b540: 0f8f84010000 JG 0x0057b6ca
    if(integer::condition("JG",flags)) goto L0057b6ca;
  }
  L0057b546: { trace_pc=0x0057b546u; // 0x57b546: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b54d: { trace_pc=0x0057b54du; // 0x57b54d: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b553: { trace_pc=0x0057b553u; // 0x57b553: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b555: { trace_pc=0x0057b555u; // 0x57b555: 8d3c80 LEA EDI,[EAX + EAX*0x4]
    s.di = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b558: { trace_pc=0x0057b558u; // 0x57b558: c1e704 SHL EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b55b: { trace_pc=0x0057b55bu; // 0x57b55b: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0057b55d: { trace_pc=0x0057b55du; // 0x57b55d: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057b560: { trace_pc=0x0057b560u; // 0x57b560: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b562: { trace_pc=0x0057b562u; // 0x57b562: 0f854a010000 JNZ 0x0057b6b2
    if(integer::condition("JNZ",flags)) goto L0057b6b2;
  }
  L0057b568: { trace_pc=0x0057b568u; // 0x57b568: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057b56c: { trace_pc=0x0057b56cu; // 0x57b56c: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  L0057b56f: { trace_pc=0x0057b56fu; // 0x57b56f: 3b8108030000 CMP EAX,dword ptr [ECX + 0x308]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000308u)),32,flags);
  }
  L0057b575: { trace_pc=0x0057b575u; // 0x57b575: 0f8437010000 JZ 0x0057b6b2
    if(integer::condition("JZ",flags)) goto L0057b6b2;
  }
  L0057b57b: { trace_pc=0x0057b57bu; // 0x57b57b: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0057b57f: { trace_pc=0x0057b57fu; // 0x57b57f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b584: { trace_pc=0x0057b584u; // 0x57b584: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0057b585: { trace_pc=0x0057b585u; // 0x57b585: e8769ffcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5748106u); flags=s.arithmetic_flags;
  }
  L0057b58a: { trace_pc=0x0057b58au; // 0x57b58a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057b58c: { trace_pc=0x0057b58cu; // 0x57b58c: e8fffbefff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5748113u); flags=s.arithmetic_flags;
  }
  L0057b591: { trace_pc=0x0057b591u; // 0x57b591: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b593: { trace_pc=0x0057b593u; // 0x57b593: 0f8419010000 JZ 0x0057b6b2
    if(integer::condition("JZ",flags)) goto L0057b6b2;
  }
  L0057b599: { trace_pc=0x0057b599u; // 0x57b599: 8a4744 MOV AL,byte ptr [EDI + 0x44]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000044u)));
  }
  L0057b59c: { trace_pc=0x0057b59cu; // 0x57b59c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b59e: { trace_pc=0x0057b59eu; // 0x57b59e: 0f840e010000 JZ 0x0057b6b2
    if(integer::condition("JZ",flags)) goto L0057b6b2;
  }
  L0057b5a4: { trace_pc=0x0057b5a4u; // 0x57b5a4: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0057b5a8: { trace_pc=0x0057b5a8u; // 0x57b5a8: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057b5ab: { trace_pc=0x0057b5abu; // 0x57b5ab: 0fbf542436 MOVSX EDX,word ptr [ESP + 0x36]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000036u)),16));
  }
  L0057b5b0: { trace_pc=0x0057b5b0u; // 0x57b5b0: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0057b5b2: { trace_pc=0x0057b5b2u; // 0x57b5b2: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057b5b5: { trace_pc=0x0057b5b5u; // 0x57b5b5: 0fbf442420 MOVSX EAX,word ptr [ESP + 0x20]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000020u)),16));
  }
  L0057b5ba: { trace_pc=0x0057b5bau; // 0x57b5ba: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0057b5bc: { trace_pc=0x0057b5bcu; // 0x57b5bc: 0fbf4c2422 MOVSX ECX,word ptr [ESP + 0x22]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000022u)),16));
  }
  L0057b5c1: { trace_pc=0x0057b5c1u; // 0x57b5c1: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0057b5c3: { trace_pc=0x0057b5c3u; // 0x57b5c3: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057b5c5: { trace_pc=0x0057b5c5u; // 0x57b5c5: 0fafd1 IMUL EDX,ECX
    s.dx = integer::imul(s.dx,s.cx,32,flags);
  }
  L0057b5c8: { trace_pc=0x0057b5c8u; // 0x57b5c8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057b5ca: { trace_pc=0x0057b5cau; // 0x57b5ca: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  L0057b5cd: { trace_pc=0x0057b5cdu; // 0x57b5cd: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0057b5cf: { trace_pc=0x0057b5cfu; // 0x57b5cf: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0057b5d3: { trace_pc=0x0057b5d3u; // 0x57b5d3: db442458 FILD dword ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b5d7: { trace_pc=0x0057b5d7u; // 0x57b5d7: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b5da: { trace_pc=0x0057b5dau; // 0x57b5da: e8a1eaf3ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5748191u); flags=s.arithmetic_flags;
  }
  L0057b5df: { trace_pc=0x0057b5dfu; // 0x57b5df: d95c2458 FSTP float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0057b5e3: { trace_pc=0x0057b5e3u; // 0x57b5e3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057b5e6: { trace_pc=0x0057b5e6u; // 0x57b5e6: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057b5eb: { trace_pc=0x0057b5ebu; // 0x57b5eb: e8f0470b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5748208u); flags=s.arithmetic_flags;
  }
  L0057b5f0: { trace_pc=0x0057b5f0u; // 0x57b5f0: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L0057b5f4: { trace_pc=0x0057b5f4u; // 0x57b5f4: c744246c00000000 MOV dword ptr [ESP + 0x6c],0x0
    m.w32((f.sp+0x0000006cu), 0x00000000u);
  }
  L0057b5fc: { trace_pc=0x0057b5fcu; // 0x57b5fc: df6c2468 FILD qword ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b600: { trace_pc=0x0057b600u; // 0x57b600: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0057b604: { trace_pc=0x0057b604u; // 0x57b604: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0057b608: { trace_pc=0x0057b608u; // 0x57b608: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b609: { trace_pc=0x0057b609u; // 0x57b609: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b60f: { trace_pc=0x0057b60fu; // 0x57b60f: d905800c7900 FLD float ptr [0x00790c80]
    const auto address=(0x00790c80u);
    s.fp.load32(m.r32(address));
  }
  L0057b615: { trace_pc=0x0057b615u; // 0x57b615: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0057b619: { trace_pc=0x0057b619u; // 0x57b619: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0057b61b: { trace_pc=0x0057b61bu; // 0x57b61b: d9442450 FLD float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L0057b61f: { trace_pc=0x0057b61fu; // 0x57b61f: d80d7c0c7900 FMUL float ptr [0x00790c7c]
    const auto address=(0x00790c7cu);
    s.fp.multiply32(m.r32(address));
  }
  L0057b625: { trace_pc=0x0057b625u; // 0x57b625: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057b627: { trace_pc=0x0057b627u; // 0x57b627: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b62b: { trace_pc=0x0057b62bu; // 0x57b62b: d80d840c7900 FMUL float ptr [0x00790c84]
    const auto address=(0x00790c84u);
    s.fp.multiply32(m.r32(address));
  }
  L0057b631: { trace_pc=0x0057b631u; // 0x57b631: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0057b633: { trace_pc=0x0057b633u; // 0x57b633: d95b04 FSTP float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0057b636: { trace_pc=0x0057b636u; // 0x57b636: 8b8208030000 MOV EAX,dword ptr [EDX + 0x308]
    s.ax = m.r32((s.dx+0x00000308u));
  }
  L0057b63c: { trace_pc=0x0057b63cu; // 0x57b63c: 89473c MOV dword ptr [EDI + 0x3c],EAX
    m.w32((s.di+0x0000003cu), s.ax);
  }
  L0057b63f: { trace_pc=0x0057b63fu; // 0x57b63f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b641: { trace_pc=0x0057b641u; // 0x57b641: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0057b643: { trace_pc=0x0057b643u; // 0x57b643: 83c308 ADD EBX,0x8
    s.bx = integer::add(s.bx,0x00000008u,32,flags);
  }
  L0057b646: { trace_pc=0x0057b646u; // 0x57b646: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b647: { trace_pc=0x0057b647u; // 0x57b647: 895c2450 MOV dword ptr [ESP + 0x50],EBX
    m.w32((f.sp+0x00000050u), s.bx);
  }
  L0057b64b: { trace_pc=0x0057b64bu; // 0x57b64b: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0057b64e: { trace_pc=0x0057b64eu; // 0x57b64e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057b650: { trace_pc=0x0057b650u; // 0x57b650: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0057b654: { trace_pc=0x0057b654u; // 0x57b654: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0057b657: { trace_pc=0x0057b657u; // 0x57b657: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b659: { trace_pc=0x0057b659u; // 0x57b659: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b65b: { trace_pc=0x0057b65bu; // 0x57b65b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057b65d: { trace_pc=0x0057b65du; // 0x57b65d: 736b JNC 0x0057b6ca
    if(integer::condition("JNC",flags)) goto L0057b6ca;
  }
  L0057b65f: { trace_pc=0x0057b65fu; // 0x57b65f: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b662: { trace_pc=0x0057b662u; // 0x57b662: 762f JBE 0x0057b693
    if(integer::condition("JBE",flags)) goto L0057b693;
  }
  L0057b664: { trace_pc=0x0057b664u; // 0x57b664: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b667: { trace_pc=0x0057b667u; // 0x57b667: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0057b66a: { trace_pc=0x0057b66au; // 0x57b66a: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0057b66e: { trace_pc=0x0057b66eu; // 0x57b66e: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0057b671: { trace_pc=0x0057b671u; // 0x57b671: d85c2458 FCOMP float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0057b675: { trace_pc=0x0057b675u; // 0x57b675: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b677: { trace_pc=0x0057b677u; // 0x57b677: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b67a: { trace_pc=0x0057b67au; // 0x57b67a: 7517 JNZ 0x0057b693
    if(integer::condition("JNZ",flags)) goto L0057b693;
  }
  L0057b67c: { trace_pc=0x0057b67cu; // 0x57b67c: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b67f: { trace_pc=0x0057b67fu; // 0x57b67f: 8b5c2460 MOV EBX,dword ptr [ESP + 0x60]
    s.bx = m.r32((f.sp+0x00000060u));
  }
  L0057b683: { trace_pc=0x0057b683u; // 0x57b683: 891c88 MOV dword ptr [EAX + ECX*0x4],EBX
    m.w32((s.ax+(s.cx * 0x00000004u)), s.bx);
  }
  L0057b686: { trace_pc=0x0057b686u; // 0x57b686: 8b5c2450 MOV EBX,dword ptr [ESP + 0x50]
    s.bx = m.r32((f.sp+0x00000050u));
  }
  L0057b68a: { trace_pc=0x0057b68au; // 0x57b68a: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057b68c: { trace_pc=0x0057b68cu; // 0x57b68c: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b68e: { trace_pc=0x0057b68eu; // 0x57b68e: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b691: { trace_pc=0x0057b691u; // 0x57b691: 77d1 JA 0x0057b664
    if(integer::condition("JA",flags)) goto L0057b664;
  }
  L0057b693: { trace_pc=0x0057b693u; // 0x57b693: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057b696: { trace_pc=0x0057b696u; // 0x57b696: 893c8a MOV dword ptr [EDX + ECX*0x4],EDI
    m.w32((s.dx+(s.cx * 0x00000004u)), s.di);
  }
  L0057b699: { trace_pc=0x0057b699u; // 0x57b699: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b69b: { trace_pc=0x0057b69bu; // 0x57b69b: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0057b69e: { trace_pc=0x0057b69eu; // 0x57b69e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b69f: { trace_pc=0x0057b69fu; // 0x57b69f: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0057b6a1: { trace_pc=0x0057b6a1u; // 0x57b6a1: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b6a3: { trace_pc=0x0057b6a3u; // 0x57b6a3: 7603 JBE 0x0057b6a8
    if(integer::condition("JBE",flags)) goto L0057b6a8;
  }
  L0057b6a5: { trace_pc=0x0057b6a5u; // 0x57b6a5: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0057b6a8: { trace_pc=0x0057b6a8u; // 0x57b6a8: 3b7e10 CMP EDI,dword ptr [ESI + 0x10]
    (void)integer::sub(s.di,m.r32((s.si+0x00000010u)),32,flags);
  }
  L0057b6ab: { trace_pc=0x0057b6abu; // 0x57b6ab: 731d JNC 0x0057b6ca
    if(integer::condition("JNC",flags)) goto L0057b6ca;
  }
  L0057b6ad: { trace_pc=0x0057b6adu; // 0x57b6ad: 897e10 MOV dword ptr [ESI + 0x10],EDI
    m.w32((s.si+0x00000010u), s.di);
  }
  L0057b6b0: { trace_pc=0x0057b6b0u; // 0x57b6b0: eb18 JMP 0x0057b6ca
    goto L0057b6ca;
  }
  L0057b6b2: { trace_pc=0x0057b6b2u; // 0x57b6b2: 8b7f38 MOV EDI,dword ptr [EDI + 0x38]
    s.di = m.r32((s.di+0x00000038u));
  }
  L0057b6b5: { trace_pc=0x0057b6b5u; // 0x57b6b5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b6b7: { trace_pc=0x0057b6b7u; // 0x57b6b7: 7411 JZ 0x0057b6ca
    if(integer::condition("JZ",flags)) goto L0057b6ca;
  }
  L0057b6b9: { trace_pc=0x0057b6b9u; // 0x57b6b9: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0057b6bd: { trace_pc=0x0057b6bdu; // 0x57b6bd: 3bb808030000 CMP EDI,dword ptr [EAX + 0x308]
    (void)integer::sub(s.di,m.r32((s.ax+0x00000308u)),32,flags);
  }
  L0057b6c3: { trace_pc=0x0057b6c3u; // 0x57b6c3: 7405 JZ 0x0057b6ca
    if(integer::condition("JZ",flags)) goto L0057b6ca;
  }
  L0057b6c5: { trace_pc=0x0057b6c5u; // 0x57b6c5: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0057b6ca: { trace_pc=0x0057b6cau; // 0x57b6ca: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0057b6ce: { trace_pc=0x0057b6ceu; // 0x57b6ce: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L0057b6d1: { trace_pc=0x0057b6d1u; // 0x57b6d1: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0057b6d4: { trace_pc=0x0057b6d4u; // 0x57b6d4: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0057b6d8: { trace_pc=0x0057b6d8u; // 0x57b6d8: 0f8ceefdffff JL 0x0057b4cc
    if(integer::condition("JL",flags)) goto L0057b4cc;
  }
  L0057b6de: { trace_pc=0x0057b6deu; // 0x57b6de: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b6e2: { trace_pc=0x0057b6e2u; // 0x57b6e2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b6e3: { trace_pc=0x0057b6e3u; // 0x57b6e3: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0057b6e7: { trace_pc=0x0057b6e7u; // 0x57b6e7: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b6e9: { trace_pc=0x0057b6e9u; // 0x57b6e9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b6eb: { trace_pc=0x0057b6ebu; // 0x57b6eb: 7506 JNZ 0x0057b6f3
    if(integer::condition("JNZ",flags)) goto L0057b6f3;
  }
  L0057b6ed: { trace_pc=0x0057b6edu; // 0x57b6ed: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0057b6f1: { trace_pc=0x0057b6f1u; // 0x57b6f1: eb2a JMP 0x0057b71d
    goto L0057b71d;
  }
  L0057b6f3: { trace_pc=0x0057b6f3u; // 0x57b6f3: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b6f6: { trace_pc=0x0057b6f6u; // 0x57b6f6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b6f8: { trace_pc=0x0057b6f8u; // 0x57b6f8: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b6fb: { trace_pc=0x0057b6fbu; // 0x57b6fb: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b6fe: { trace_pc=0x0057b6feu; // 0x57b6fe: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057b701: { trace_pc=0x0057b701u; // 0x57b701: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b703: { trace_pc=0x0057b703u; // 0x57b703: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b706: { trace_pc=0x0057b706u; // 0x57b706: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057b70d: { trace_pc=0x0057b70du; // 0x57b70d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b70f: { trace_pc=0x0057b70fu; // 0x57b70f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b710: { trace_pc=0x0057b710u; // 0x57b710: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b712: { trace_pc=0x0057b712u; // 0x57b712: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b714: { trace_pc=0x0057b714u; // 0x57b714: e877070100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5748505u); flags=s.arithmetic_flags;
  }
  L0057b719: { trace_pc=0x0057b719u; // 0x57b719: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L0057b71d: { trace_pc=0x0057b71du; // 0x57b71d: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b721: { trace_pc=0x0057b721u; // 0x57b721: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0057b725: { trace_pc=0x0057b725u; // 0x57b725: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b727: { trace_pc=0x0057b727u; // 0x57b727: 0f8c2bfdffff JL 0x0057b458
    if(integer::condition("JL",flags)) goto L0057b458;
  }
  L0057b72d: { trace_pc=0x0057b72du; // 0x57b72d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b72f: { trace_pc=0x0057b72fu; // 0x57b72f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b731: { trace_pc=0x0057b731u; // 0x57b731: 0f84e2000000 JZ 0x0057b819
    if(integer::condition("JZ",flags)) goto L0057b819;
  }
  L0057b737: { trace_pc=0x0057b737u; // 0x57b737: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b73a: { trace_pc=0x0057b73au; // 0x57b73a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b73c: { trace_pc=0x0057b73cu; // 0x57b73c: 8b1488 MOV EDX,dword ptr [EAX + ECX*0x4]
    s.dx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b73f: { trace_pc=0x0057b73fu; // 0x57b73f: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b742: { trace_pc=0x0057b742u; // 0x57b742: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0057b745: { trace_pc=0x0057b745u; // 0x57b745: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0057b747: { trace_pc=0x0057b747u; // 0x57b747: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0057b74a: { trace_pc=0x0057b74au; // 0x57b74a: c7048100000000 MOV dword ptr [ECX + EAX*0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L0057b751: { trace_pc=0x0057b751u; // 0x57b751: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b753: { trace_pc=0x0057b753u; // 0x57b753: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0057b754: { trace_pc=0x0057b754u; // 0x57b754: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b756: { trace_pc=0x0057b756u; // 0x57b756: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0057b758: { trace_pc=0x0057b758u; // 0x57b758: e833070100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5748573u); flags=s.arithmetic_flags;
  }
  L0057b75d: { trace_pc=0x0057b75du; // 0x57b75d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b75f: { trace_pc=0x0057b75fu; // 0x57b75f: 0f84b4000000 JZ 0x0057b819
    if(integer::condition("JZ",flags)) goto L0057b819;
  }
  L0057b765: { trace_pc=0x0057b765u; // 0x57b765: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0057b769: { trace_pc=0x0057b769u; // 0x57b769: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b76b: { trace_pc=0x0057b76bu; // 0x57b76b: 0f8405010000 JZ 0x0057b876
    if(integer::condition("JZ",flags)) goto L0057b876;
  }
  L0057b771: { trace_pc=0x0057b771u; // 0x57b771: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057b772: { trace_pc=0x0057b772u; // 0x57b772: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b777: { trace_pc=0x0057b777u; // 0x57b777: e8849dfcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5748604u); flags=s.arithmetic_flags;
  }
  L0057b77c: { trace_pc=0x0057b77cu; // 0x57b77c: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0057b77e: { trace_pc=0x0057b77eu; // 0x57b77e: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b784: { trace_pc=0x0057b784u; // 0x57b784: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057b788: { trace_pc=0x0057b788u; // 0x57b788: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b78f: { trace_pc=0x0057b78fu; // 0x57b78f: 0fbf17 MOVSX EDX,word ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0057b792: { trace_pc=0x0057b792u; // 0x57b792: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b794: { trace_pc=0x0057b794u; // 0x57b794: 8d3c80 LEA EDI,[EAX + EAX*0x4]
    s.di = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b797: { trace_pc=0x0057b797u; // 0x57b797: c1e704 SHL EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b79a: { trace_pc=0x0057b79au; // 0x57b79a: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0057b79c: { trace_pc=0x0057b79cu; // 0x57b79c: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057b79f: { trace_pc=0x0057b79fu; // 0x57b79f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b7a1: { trace_pc=0x0057b7a1u; // 0x57b7a1: 7530 JNZ 0x0057b7d3
    if(integer::condition("JNZ",flags)) goto L0057b7d3;
  }
  L0057b7a3: { trace_pc=0x0057b7a3u; // 0x57b7a3: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057b7a5: { trace_pc=0x0057b7a5u; // 0x57b7a5: e8e6f9efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5748650u); flags=s.arithmetic_flags;
  }
  L0057b7aa: { trace_pc=0x0057b7aau; // 0x57b7aa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b7ac: { trace_pc=0x0057b7acu; // 0x57b7ac: 7425 JZ 0x0057b7d3
    if(integer::condition("JZ",flags)) goto L0057b7d3;
  }
  L0057b7ae: { trace_pc=0x0057b7aeu; // 0x57b7ae: 8a4744 MOV AL,byte ptr [EDI + 0x44]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000044u)));
  }
  L0057b7b1: { trace_pc=0x0057b7b1u; // 0x57b7b1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b7b3: { trace_pc=0x0057b7b3u; // 0x57b7b3: 741e JZ 0x0057b7d3
    if(integer::condition("JZ",flags)) goto L0057b7d3;
  }
  L0057b7b5: { trace_pc=0x0057b7b5u; // 0x57b7b5: a1b8a1a300 MOV EAX,[0x00a3a1b8]
    s.ax = m.r32((0x00a3a1b8u));
  }
  L0057b7ba: { trace_pc=0x0057b7bau; // 0x57b7ba: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057b7be: { trace_pc=0x0057b7beu; // 0x57b7be: 894338 MOV dword ptr [EBX + 0x38],EAX
    m.w32((s.bx+0x00000038u), s.ax);
  }
  L0057b7c1: { trace_pc=0x0057b7c1u; // 0x57b7c1: c6831a01000000 MOV byte ptr [EBX + 0x11a],0x0
    m.w8((s.bx+0x0000011au), 0x00000000u);
  }
  L0057b7c8: { trace_pc=0x0057b7c8u; // 0x57b7c8: 8b9108030000 MOV EDX,dword ptr [ECX + 0x308]
    s.dx = m.r32((s.cx+0x00000308u));
  }
  L0057b7ce: { trace_pc=0x0057b7ceu; // 0x57b7ce: 895738 MOV dword ptr [EDI + 0x38],EDX
    m.w32((s.di+0x00000038u), s.dx);
  }
  L0057b7d1: { trace_pc=0x0057b7d1u; // 0x57b7d1: eb05 JMP 0x0057b7d8
    goto L0057b7d8;
  }
  L0057b7d3: { trace_pc=0x0057b7d3u; // 0x57b7d3: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0057b7d8: { trace_pc=0x0057b7d8u; // 0x57b7d8: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b7da: { trace_pc=0x0057b7dau; // 0x57b7da: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b7dc: { trace_pc=0x0057b7dcu; // 0x57b7dc: 7504 JNZ 0x0057b7e2
    if(integer::condition("JNZ",flags)) goto L0057b7e2;
  }
  L0057b7de: { trace_pc=0x0057b7deu; // 0x57b7de: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057b7e0: { trace_pc=0x0057b7e0u; // 0x57b7e0: eb26 JMP 0x0057b808
    goto L0057b808;
  }
  L0057b7e2: { trace_pc=0x0057b7e2u; // 0x57b7e2: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b7e5: { trace_pc=0x0057b7e5u; // 0x57b7e5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b7e7: { trace_pc=0x0057b7e7u; // 0x57b7e7: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b7ea: { trace_pc=0x0057b7eau; // 0x57b7ea: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b7ed: { trace_pc=0x0057b7edu; // 0x57b7ed: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057b7f0: { trace_pc=0x0057b7f0u; // 0x57b7f0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b7f2: { trace_pc=0x0057b7f2u; // 0x57b7f2: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b7f5: { trace_pc=0x0057b7f5u; // 0x57b7f5: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057b7fc: { trace_pc=0x0057b7fcu; // 0x57b7fc: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b7fe: { trace_pc=0x0057b7feu; // 0x57b7fe: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b7ff: { trace_pc=0x0057b7ffu; // 0x57b7ff: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b801: { trace_pc=0x0057b801u; // 0x57b801: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b803: { trace_pc=0x0057b803u; // 0x57b803: e888060100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5748744u); flags=s.arithmetic_flags;
  }
  L0057b808: { trace_pc=0x0057b808u; // 0x57b808: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b80c: { trace_pc=0x0057b80cu; // 0x57b80c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b80d: { trace_pc=0x0057b80du; // 0x57b80d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b80f: { trace_pc=0x0057b80fu; // 0x57b80f: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0057b813: { trace_pc=0x0057b813u; // 0x57b813: 0f854cffffff JNZ 0x0057b765
    if(integer::condition("JNZ",flags)) goto L0057b765;
  }
  L0057b819: { trace_pc=0x0057b819u; // 0x57b819: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0057b81d: { trace_pc=0x0057b81du; // 0x57b81d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b81f: { trace_pc=0x0057b81fu; // 0x57b81f: 7455 JZ 0x0057b876
    if(integer::condition("JZ",flags)) goto L0057b876;
  }
  L0057b821: { trace_pc=0x0057b821u; // 0x57b821: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b825: { trace_pc=0x0057b825u; // 0x57b825: 83f94b CMP ECX,0x4b
    (void)integer::sub(s.cx,0x0000004bu,32,flags);
  }
  L0057b828: { trace_pc=0x0057b828u; // 0x57b828: 7e47 JLE 0x0057b871
    if(integer::condition("JLE",flags)) goto L0057b871;
  }
  L0057b82a: { trace_pc=0x0057b82au; // 0x57b82a: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0057b82e: { trace_pc=0x0057b82eu; // 0x57b82e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057b82f: { trace_pc=0x0057b82fu; // 0x57b82f: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0057b832: { trace_pc=0x0057b832u; // 0x57b832: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b834: { trace_pc=0x0057b834u; // 0x57b834: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L0057b837: { trace_pc=0x0057b837u; // 0x57b837: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b839: { trace_pc=0x0057b839u; // 0x57b839: 7e36 JLE 0x0057b871
    if(integer::condition("JLE",flags)) goto L0057b871;
  }
  L0057b83b: { trace_pc=0x0057b83bu; // 0x57b83b: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0057b83e: { trace_pc=0x0057b83eu; // 0x57b83e: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0057b843: { trace_pc=0x0057b843u; // 0x57b843: 66833b00 CMP word ptr [EBX],0x0
    (void)integer::sub(m.r16((s.bx)),0x00000000u,16,flags);
  }
  L0057b847: { trace_pc=0x0057b847u; // 0x57b847: 757d JNZ 0x0057b8c6
    if(integer::condition("JNZ",flags)) goto L0057b8c6;
  }
  L0057b849: { trace_pc=0x0057b849u; // 0x57b849: 66837b0200 CMP word ptr [EBX + 0x2],0x0
    (void)integer::sub(m.r16((s.bx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b84e: { trace_pc=0x0057b84eu; // 0x57b84e: 7576 JNZ 0x0057b8c6
    if(integer::condition("JNZ",flags)) goto L0057b8c6;
  }
  L0057b850: { trace_pc=0x0057b850u; // 0x57b850: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b854: { trace_pc=0x0057b854u; // 0x57b854: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0057b856: { trace_pc=0x0057b856u; // 0x57b856: 8b8f08030000 MOV ECX,dword ptr [EDI + 0x308]
    s.cx = m.r32((s.di+0x00000308u));
  }
  L0057b85c: { trace_pc=0x0057b85cu; // 0x57b85c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b85d: { trace_pc=0x0057b85du; // 0x57b85d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b862: { trace_pc=0x0057b862u; // 0x57b862: e849d8fdff CALL 0x005590b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005590b0u,5748839u); flags=s.arithmetic_flags;
  }
  L0057b867: { trace_pc=0x0057b867u; // 0x57b867: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b869: { trace_pc=0x0057b869u; // 0x57b869: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L0057b86d: { trace_pc=0x0057b86du; // 0x57b86d: 740b JZ 0x0057b87a
    if(integer::condition("JZ",flags)) goto L0057b87a;
  }
  L0057b86f: { trace_pc=0x0057b86fu; // 0x57b86f: eb59 JMP 0x0057b8ca
    goto L0057b8ca;
  }
  L0057b871: { trace_pc=0x0057b871u; // 0x57b871: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0057b876: { trace_pc=0x0057b876u; // 0x57b876: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b87a: { trace_pc=0x0057b87au; // 0x57b87a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0057b87c: { trace_pc=0x0057b87cu; // 0x57b87c: 7412 JZ 0x0057b890
    if(integer::condition("JZ",flags)) goto L0057b890;
  }
  L0057b87e: { trace_pc=0x0057b87eu; // 0x57b87e: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b881: { trace_pc=0x0057b881u; // 0x57b881: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057b882: { trace_pc=0x0057b882u; // 0x57b882: e8f41d1f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5748871u); flags=s.arithmetic_flags;
  }
  L0057b887: { trace_pc=0x0057b887u; // 0x57b887: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057b888: { trace_pc=0x0057b888u; // 0x57b888: e8ee1d1f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5748877u); flags=s.arithmetic_flags;
  }
  L0057b88d: { trace_pc=0x0057b88du; // 0x57b88d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057b890: { trace_pc=0x0057b890u; // 0x57b890: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0057b894: { trace_pc=0x0057b894u; // 0x57b894: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b895: { trace_pc=0x0057b895u; // 0x57b895: e8e11d1f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5748890u); flags=s.arithmetic_flags;
  }
  L0057b89a: { trace_pc=0x0057b89au; // 0x57b89a: 8a442417 MOV AL,byte ptr [ESP + 0x17]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000017u)));
  }
  L0057b89e: { trace_pc=0x0057b89eu; // 0x57b89e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057b8a1: { trace_pc=0x0057b8a1u; // 0x57b8a1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b8a3: { trace_pc=0x0057b8a3u; // 0x57b8a3: 0f84ed000000 JZ 0x0057b996
    if(integer::condition("JZ",flags)) goto L0057b996;
  }
  L0057b8a9: { trace_pc=0x0057b8a9u; // 0x57b8a9: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0057b8ad: { trace_pc=0x0057b8adu; // 0x57b8ad: 8b8704030000 MOV EAX,dword ptr [EDI + 0x304]
    s.ax = m.r32((s.di+0x00000304u));
  }
  L0057b8b3: { trace_pc=0x0057b8b3u; // 0x57b8b3: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b8b5: { trace_pc=0x0057b8b5u; // 0x57b8b5: 898704030000 MOV dword ptr [EDI + 0x304],EAX
    m.w32((s.di+0x00000304u), s.ax);
  }
  L0057b8bb: { trace_pc=0x0057b8bbu; // 0x57b8bb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0057b8bd: { trace_pc=0x0057b8bdu; // 0x57b8bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057b8be: { trace_pc=0x0057b8beu; // 0x57b8be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057b8bf: { trace_pc=0x0057b8bfu; // 0x57b8bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057b8c0: { trace_pc=0x0057b8c0u; // 0x57b8c0: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057b8c2: { trace_pc=0x0057b8c2u; // 0x57b8c2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057b8c3: { trace_pc=0x0057b8c3u; // 0x57b8c3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057b8c6: { trace_pc=0x0057b8c6u; // 0x57b8c6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b8ca: { trace_pc=0x0057b8cau; // 0x57b8ca: 66833b00 CMP word ptr [EBX],0x0
    (void)integer::sub(m.r16((s.bx)),0x00000000u,16,flags);
  }
  L0057b8ce: { trace_pc=0x0057b8ceu; // 0x57b8ce: 75aa JNZ 0x0057b87a
    if(integer::condition("JNZ",flags)) goto L0057b87a;
  }
  L0057b8d0: { trace_pc=0x0057b8d0u; // 0x57b8d0: 66837b0200 CMP word ptr [EBX + 0x2],0x0
    (void)integer::sub(m.r16((s.bx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b8d5: { trace_pc=0x0057b8d5u; // 0x57b8d5: 75a3 JNZ 0x0057b87a
    if(integer::condition("JNZ",flags)) goto L0057b87a;
  }
  L0057b8d7: { trace_pc=0x0057b8d7u; // 0x57b8d7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057b8d9: { trace_pc=0x0057b8d9u; // 0x57b8d9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b8db: { trace_pc=0x0057b8dbu; // 0x57b8db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b8dc: { trace_pc=0x0057b8dcu; // 0x57b8dc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b8dd: { trace_pc=0x0057b8ddu; // 0x57b8dd: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0057b8e0: { trace_pc=0x0057b8e0u; // 0x57b8e0: ba00020000 MOV EDX,0x200
    s.dx = 0x00000200u;
  }
  L0057b8e5: { trace_pc=0x0057b8e5u; // 0x57b8e5: 8bdc MOV EBX,ESP
    s.bx = f.sp;
  }
  L0057b8e7: { trace_pc=0x0057b8e7u; // 0x57b8e7: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0057b8e9: { trace_pc=0x0057b8e9u; // 0x57b8e9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b8eb: { trace_pc=0x0057b8ebu; // 0x57b8eb: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0057b8ed: { trace_pc=0x0057b8edu; // 0x57b8ed: 894b04 MOV dword ptr [EBX + 0x4],ECX
    m.w32((s.bx+0x00000004u), s.cx);
  }
  L0057b8f0: { trace_pc=0x0057b8f0u; // 0x57b8f0: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  L0057b8f3: { trace_pc=0x0057b8f3u; // 0x57b8f3: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L0057b8f6: { trace_pc=0x0057b8f6u; // 0x57b8f6: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L0057b8fa: { trace_pc=0x0057b8fau; // 0x57b8fa: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b8fc: { trace_pc=0x0057b8fcu; // 0x57b8fc: 8b9708030000 MOV EDX,dword ptr [EDI + 0x308]
    s.dx = m.r32((s.di+0x00000308u));
  }
  L0057b902: { trace_pc=0x0057b902u; // 0x57b902: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0057b903: { trace_pc=0x0057b903u; // 0x57b903: e8382e0000 CALL 0x0057e740
    s.arithmetic_flags=flags; invoke(m,s,f,0x0057e740u,5749000u); flags=s.arithmetic_flags;
  }
  L0057b908: { trace_pc=0x0057b908u; // 0x57b908: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b90a: { trace_pc=0x0057b90au; // 0x57b90a: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L0057b90e: { trace_pc=0x0057b90eu; // 0x57b90e: 0f8466ffffff JZ 0x0057b87a
    if(integer::condition("JZ",flags)) goto L0057b87a;
  }
  L0057b914: { trace_pc=0x0057b914u; // 0x57b914: 8b8708030000 MOV EAX,dword ptr [EDI + 0x308]
    s.ax = m.r32((s.di+0x00000308u));
  }
  L0057b91a: { trace_pc=0x0057b91au; // 0x57b91a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b91f: { trace_pc=0x0057b91fu; // 0x57b91f: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0057b923: { trace_pc=0x0057b923u; // 0x57b923: e818bafdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5749032u); flags=s.arithmetic_flags;
  }
  L0057b928: { trace_pc=0x0057b928u; // 0x57b928: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b92d: { trace_pc=0x0057b92du; // 0x57b92d: e84eb9fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749042u); flags=s.arithmetic_flags;
  }
  L0057b932: { trace_pc=0x0057b932u; // 0x57b932: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b934: { trace_pc=0x0057b934u; // 0x57b934: 7456 JZ 0x0057b98c
    if(integer::condition("JZ",flags)) goto L0057b98c;
  }
  L0057b936: { trace_pc=0x0057b936u; // 0x57b936: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b93c: { trace_pc=0x0057b93cu; // 0x57b93c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057b93e: { trace_pc=0x0057b93eu; // 0x57b93e: 7505 JNZ 0x0057b945
    if(integer::condition("JNZ",flags)) goto L0057b945;
  }
  L0057b940: { trace_pc=0x0057b940u; // 0x57b940: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0057b943: { trace_pc=0x0057b943u; // 0x57b943: eb1b JMP 0x0057b960
    goto L0057b960;
  }
  L0057b945: { trace_pc=0x0057b945u; // 0x57b945: 0fbf4826 MOVSX ECX,word ptr [EAX + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000026u)),16));
  }
  L0057b949: { trace_pc=0x0057b949u; // 0x57b949: 0faf0d4c6b8300 IMUL ECX,dword ptr [0x00836b4c]
    s.cx = integer::imul(s.cx,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b950: { trace_pc=0x0057b950u; // 0x57b950: 0fbf5824 MOVSX EBX,word ptr [EAX + 0x24]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000024u)),16));
  }
  L0057b954: { trace_pc=0x0057b954u; // 0x57b954: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0057b956: { trace_pc=0x0057b956u; // 0x57b956: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0057b959: { trace_pc=0x0057b959u; // 0x57b959: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b95c: { trace_pc=0x0057b95cu; // 0x57b95c: 8b4c1138 MOV ECX,dword ptr [ECX + EDX*0x1 + 0x38]
    s.cx = m.r32((s.cx+(s.dx * 0x00000001u)+0x00000038u));
  }
  L0057b960: { trace_pc=0x0057b960u; // 0x57b960: 3b4c2460 CMP ECX,dword ptr [ESP + 0x60]
    (void)integer::sub(s.cx,m.r32((f.sp+0x00000060u)),32,flags);
  }
  L0057b964: { trace_pc=0x0057b964u; // 0x57b964: 7518 JNZ 0x0057b97e
    if(integer::condition("JNZ",flags)) goto L0057b97e;
  }
  L0057b966: { trace_pc=0x0057b966u; // 0x57b966: 8b4838 MOV ECX,dword ptr [EAX + 0x38]
    s.cx = m.r32((s.ax+0x00000038u));
  }
  L0057b969: { trace_pc=0x0057b969u; // 0x57b969: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b96b: { trace_pc=0x0057b96bu; // 0x57b96b: 7408 JZ 0x0057b975
    if(integer::condition("JZ",flags)) goto L0057b975;
  }
  L0057b96d: { trace_pc=0x0057b96du; // 0x57b96d: 81f9ffff0000 CMP ECX,0xffff
    (void)integer::sub(s.cx,0x0000ffffu,32,flags);
  }
  L0057b973: { trace_pc=0x0057b973u; // 0x57b973: 7509 JNZ 0x0057b97e
    if(integer::condition("JNZ",flags)) goto L0057b97e;
  }
  L0057b975: { trace_pc=0x0057b975u; // 0x57b975: 8b1598a8a300 MOV EDX,dword ptr [0x00a3a898]
    s.dx = m.r32((0x00a3a898u));
  }
  L0057b97b: { trace_pc=0x0057b97bu; // 0x57b97b: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L0057b97e: { trace_pc=0x0057b97eu; // 0x57b97e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b983: { trace_pc=0x0057b983u; // 0x57b983: e8f8b8fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749128u); flags=s.arithmetic_flags;
  }
  L0057b988: { trace_pc=0x0057b988u; // 0x57b988: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b98a: { trace_pc=0x0057b98au; // 0x57b98a: 75aa JNZ 0x0057b936
    if(integer::condition("JNZ",flags)) goto L0057b936;
  }
  L0057b98c: { trace_pc=0x0057b98cu; // 0x57b98c: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0057b991: { trace_pc=0x0057b991u; // 0x57b991: e9e4feffff JMP 0x0057b87a
    goto L0057b87a;
  }
  L0057b996: { trace_pc=0x0057b996u; // 0x57b996: 8bb708030000 MOV ESI,dword ptr [EDI + 0x308]
    s.si = m.r32((s.di+0x00000308u));
  }
  L0057b99c: { trace_pc=0x0057b99cu; // 0x57b99c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b9a1: { trace_pc=0x0057b9a1u; // 0x57b9a1: e89ab9fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5749158u); flags=s.arithmetic_flags;
  }
  L0057b9a6: { trace_pc=0x0057b9a6u; // 0x57b9a6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b9ab: { trace_pc=0x0057b9abu; // 0x57b9ab: e8d0b8fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749168u); flags=s.arithmetic_flags;
  }
  L0057b9b0: { trace_pc=0x0057b9b0u; // 0x57b9b0: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057b9b2: { trace_pc=0x0057b9b2u; // 0x57b9b2: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057b9b4: { trace_pc=0x0057b9b4u; // 0x57b9b4: 7456 JZ 0x0057ba0c
    if(integer::condition("JZ",flags)) goto L0057ba0c;
  }
  L0057b9b6: { trace_pc=0x0057b9b6u; // 0x57b9b6: 8b5024 MOV EDX,dword ptr [EAX + 0x24]
    s.dx = m.r32((s.ax+0x00000024u));
  }
  L0057b9b9: { trace_pc=0x0057b9b9u; // 0x57b9b9: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L0057b9bd: { trace_pc=0x0057b9bdu; // 0x57b9bd: 0fbf4c2462 MOVSX ECX,word ptr [ESP + 0x62]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000062u)),16));
  }
  L0057b9c2: { trace_pc=0x0057b9c2u; // 0x57b9c2: 0faf0d4c6b8300 IMUL ECX,dword ptr [0x00836b4c]
    s.cx = integer::imul(s.cx,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b9c9: { trace_pc=0x0057b9c9u; // 0x57b9c9: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0057b9cc: { trace_pc=0x0057b9ccu; // 0x57b9cc: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057b9ce: { trace_pc=0x0057b9ceu; // 0x57b9ce: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b9d4: { trace_pc=0x0057b9d4u; // 0x57b9d4: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0057b9d7: { trace_pc=0x0057b9d7u; // 0x57b9d7: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b9da: { trace_pc=0x0057b9dau; // 0x57b9da: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057b9dc: { trace_pc=0x0057b9dcu; // 0x57b9dc: 397138 CMP dword ptr [ECX + 0x38],ESI
    (void)integer::sub(m.r32((s.cx+0x00000038u)),s.si,32,flags);
  }
  L0057b9df: { trace_pc=0x0057b9dfu; // 0x57b9df: 751d JNZ 0x0057b9fe
    if(integer::condition("JNZ",flags)) goto L0057b9fe;
  }
  L0057b9e1: { trace_pc=0x0057b9e1u; // 0x57b9e1: 895938 MOV dword ptr [ECX + 0x38],EBX
    m.w32((s.cx+0x00000038u), s.bx);
  }
  L0057b9e4: { trace_pc=0x0057b9e4u; // 0x57b9e4: c6414b00 MOV byte ptr [ECX + 0x4b],0x0
    m.w8((s.cx+0x0000004bu), 0x00000000u);
  }
  L0057b9e8: { trace_pc=0x0057b9e8u; // 0x57b9e8: 895838 MOV dword ptr [EAX + 0x38],EBX
    m.w32((s.ax+0x00000038u), s.bx);
  }
  L0057b9eb: { trace_pc=0x0057b9ebu; // 0x57b9eb: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0057b9f2: { trace_pc=0x0057b9f2u; // 0x57b9f2: 8b8f0c030000 MOV ECX,dword ptr [EDI + 0x30c]
    s.cx = m.r32((s.di+0x0000030cu));
  }
  L0057b9f8: { trace_pc=0x0057b9f8u; // 0x57b9f8: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0057b9fe: { trace_pc=0x0057b9feu; // 0x57b9fe: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057ba03: { trace_pc=0x0057ba03u; // 0x57ba03: e878b8fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749256u); flags=s.arithmetic_flags;
  }
  L0057ba08: { trace_pc=0x0057ba08u; // 0x57ba08: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057ba0a: { trace_pc=0x0057ba0au; // 0x57ba0a: 75aa JNZ 0x0057b9b6
    if(integer::condition("JNZ",flags)) goto L0057b9b6;
  }
  L0057ba0c: { trace_pc=0x0057ba0cu; // 0x57ba0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057ba0d: { trace_pc=0x0057ba0du; // 0x57ba0d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057ba0e: { trace_pc=0x0057ba0eu; // 0x57ba0e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0057ba10: { trace_pc=0x0057ba10u; // 0x57ba10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057ba11: { trace_pc=0x0057ba11u; // 0x57ba11: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057ba13: { trace_pc=0x0057ba13u; // 0x57ba13: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057ba14: { trace_pc=0x0057ba14u; // 0x57ba14: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { trace_pc=0x0076aa50u; // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { trace_pc=0x0076aa53u; // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { trace_pc=0x0076aa56u; // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { trace_pc=0x0076aa5au; // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { trace_pc=0x0076aa5du; // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { trace_pc=0x0076aa63u; // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { trace_pc=0x0076aa69u; // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { trace_pc=0x0076aa6bu; // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { trace_pc=0x0076aa6du; // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { trace_pc=0x0076aa70u; // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { trace_pc=0x0076aa72u; // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { trace_pc=0x0076aa75u; // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { trace_pc=0x0076aa76u; // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { trace_pc=0x0076aa7cu; // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { trace_pc=0x0076aa7fu; // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { trace_pc=0x0076aa82u; // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { trace_pc=0x0076aa84u; // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { trace_pc=0x0076aa87u; // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { trace_pc=0x0076aa89u; // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { trace_pc=0x0076aa8cu; // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557340: { trace_pc=0x00557340u; // 0x557340: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L00557346: { trace_pc=0x00557346u; // 0x557346: c7810801000001000000 MOV dword ptr [ECX + 0x108],0x1
    m.w32((s.cx+0x00000108u), 0x00000001u);
  }
  L00557350: { trace_pc=0x00557350u; // 0x557350: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L00557356: { trace_pc=0x00557356u; // 0x557356: 8d50ff LEA EDX,[EAX + -0x1]
    s.dx = (s.ax-0x00000001u);
  }
  L00557359: { trace_pc=0x00557359u; // 0x557359: 899110010000 MOV dword ptr [ECX + 0x110],EDX
    m.w32((s.cx+0x00000110u), s.dx);
  }
  L0055735f: { trace_pc=0x0055735fu; // 0x55735f: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557365: { trace_pc=0x00557365u; // 0x557365: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  L00557368: { trace_pc=0x00557368u; // 0x557368: 8d441004 LEA EAX,[EAX + EDX*0x1 + 0x4]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000004u);
  }
  L0055736c: { trace_pc=0x0055736cu; // 0x55736c: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L00557372: { trace_pc=0x00557372u; // 0x557372: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557280: { trace_pc=0x00557280u; // 0x557280: 8b8110010000 MOV EAX,dword ptr [ECX + 0x110]
    s.ax = m.r32((s.cx+0x00000110u));
  }
  L00557286: { trace_pc=0x00557286u; // 0x557286: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00557287: { trace_pc=0x00557287u; // 0x557287: 8ba914010000 MOV EBP,dword ptr [ECX + 0x114]
    s.bp = m.r32((s.cx+0x00000114u));
  }
  L0055728d: { trace_pc=0x0055728du; // 0x55728d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055728e: { trace_pc=0x0055728eu; // 0x55728e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557290: { trace_pc=0x00557290u; // 0x557290: 7433 JZ 0x005572c5
    if(integer::condition("JZ",flags)) goto L005572c5;
  }
  L00557292: { trace_pc=0x00557292u; // 0x557292: 8bb108010000 MOV ESI,dword ptr [ECX + 0x108]
    s.si = m.r32((s.cx+0x00000108u));
  }
  L00557298: { trace_pc=0x00557298u; // 0x557298: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L0055729e: { trace_pc=0x0055729eu; // 0x55729e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0055729f: { trace_pc=0x0055729fu; // 0x55729f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005572a0: { trace_pc=0x005572a0u; // 0x5572a0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005572a1: { trace_pc=0x005572a1u; // 0x5572a1: 89b108010000 MOV dword ptr [ECX + 0x108],ESI
    m.w32((s.cx+0x00000108u), s.si);
  }
  L005572a7: { trace_pc=0x005572a7u; // 0x5572a7: 898110010000 MOV dword ptr [ECX + 0x110],EAX
    m.w32((s.cx+0x00000110u), s.ax);
  }
  L005572ad: { trace_pc=0x005572adu; // 0x5572ad: 8d8504f8ffff LEA EAX,[EBP + 0xfffff804]
    s.ax = (s.bp+0xfffff804u);
  }
  L005572b3: { trace_pc=0x005572b3u; // 0x5572b3: 89910c010000 MOV dword ptr [ECX + 0x10c],EDX
    m.w32((s.cx+0x0000010cu), s.dx);
  }
  L005572b9: { trace_pc=0x005572b9u; // 0x5572b9: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L005572bf: { trace_pc=0x005572bfu; // 0x5572bf: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005572c2: { trace_pc=0x005572c2u; // 0x5572c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005572c3: { trace_pc=0x005572c3u; // 0x5572c3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005572c4: { trace_pc=0x005572c4u; // 0x5572c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005572c5: { trace_pc=0x005572c5u; // 0x5572c5: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L005572cb: { trace_pc=0x005572cbu; // 0x5572cb: 8b8108010000 MOV EAX,dword ptr [ECX + 0x108]
    s.ax = m.r32((s.cx+0x00000108u));
  }
  L005572d1: { trace_pc=0x005572d1u; // 0x5572d1: 8bb1f0000000 MOV ESI,dword ptr [ECX + 0xf0]
    s.si = m.r32((s.cx+0x000000f0u));
  }
  L005572d7: { trace_pc=0x005572d7u; // 0x5572d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005572d8: { trace_pc=0x005572d8u; // 0x5572d8: 899108010000 MOV dword ptr [ECX + 0x108],EDX
    m.w32((s.cx+0x00000108u), s.dx);
  }
  L005572de: { trace_pc=0x005572deu; // 0x5572de: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005572e0: { trace_pc=0x005572e0u; // 0x5572e0: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L005572e2: { trace_pc=0x005572e2u; // 0x5572e2: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572e8: { trace_pc=0x005572e8u; // 0x5572e8: 8d5402ff LEA EDX,[EDX + EAX*0x1 + -0x1]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L005572ec: { trace_pc=0x005572ecu; // 0x5572ec: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L005572ef: { trace_pc=0x005572efu; // 0x5572ef: 740a JZ 0x005572fb
    if(integer::condition("JZ",flags)) goto L005572fb;
  }
  L005572f1: { trace_pc=0x005572f1u; // 0x5572f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005572f2: { trace_pc=0x005572f2u; // 0x5572f2: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005572f3: { trace_pc=0x005572f3u; // 0x5572f3: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572f9: { trace_pc=0x005572f9u; // 0x5572f9: eb0a JMP 0x00557305
    goto L00557305;
  }
  L005572fb: { trace_pc=0x005572fbu; // 0x5572fb: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005572fc: { trace_pc=0x005572fcu; // 0x5572fc: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L005572ff: { trace_pc=0x005572ffu; // 0x5572ff: 89b908010000 MOV dword ptr [ECX + 0x108],EDI
    m.w32((s.cx+0x00000108u), s.di);
  }
  L00557305: { trace_pc=0x00557305u; // 0x557305: 8b810c010000 MOV EAX,dword ptr [ECX + 0x10c]
    s.ax = m.r32((s.cx+0x0000010cu));
  }
  L0055730b: { trace_pc=0x0055730bu; // 0x55730b: 8b9108010000 MOV EDX,dword ptr [ECX + 0x108]
    s.dx = m.r32((s.cx+0x00000108u));
  }
  L00557311: { trace_pc=0x00557311u; // 0x557311: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00557314: { trace_pc=0x00557314u; // 0x557314: 89b110010000 MOV dword ptr [ECX + 0x110],ESI
    m.w32((s.cx+0x00000110u), s.si);
  }
  L0055731a: { trace_pc=0x0055731au; // 0x55731a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055731c: { trace_pc=0x0055731cu; // 0x55731c: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557322: { trace_pc=0x00557322u; // 0x557322: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557323: { trace_pc=0x00557323u; // 0x557323: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557324: { trace_pc=0x00557324u; // 0x557324: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L00557327: { trace_pc=0x00557327u; // 0x557327: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L0055732d: { trace_pc=0x0055732du; // 0x55732d: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00557330: { trace_pc=0x00557330u; // 0x557330: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557331: { trace_pc=0x00557331u; // 0x557331: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00176620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00576620: { trace_pc=0x00576620u; // 0x576620: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00576621: { trace_pc=0x00576621u; // 0x576621: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00576623: { trace_pc=0x00576623u; // 0x576623: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00576626: { trace_pc=0x00576626u; // 0x576626: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L00576629: { trace_pc=0x00576629u; // 0x576629: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057662a: { trace_pc=0x0057662au; // 0x57662a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0057662c: { trace_pc=0x0057662cu; // 0x57662c: 803e00 CMP byte ptr [ESI],0x0
    (void)integer::sub(m.r8((s.si)),0x00000000u,8,flags);
  }
  L0057662f: { trace_pc=0x0057662fu; // 0x57662f: 740d JZ 0x0057663e
    if(integer::condition("JZ",flags)) goto L0057663e;
  }
  L00576631: { trace_pc=0x00576631u; // 0x576631: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  L00576634: { trace_pc=0x00576634u; // 0x576634: dd4608 FLD double ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00576637: { trace_pc=0x00576637u; // 0x576637: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00576638: { trace_pc=0x00576638u; // 0x576638: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057663a: { trace_pc=0x0057663au; // 0x57663a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057663b: { trace_pc=0x0057663bu; // 0x57663b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0057663c: { trace_pc=0x0057663cu; // 0x57663c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057663e: { trace_pc=0x0057663eu; // 0x57663e: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727809u); flags=s.arithmetic_flags;
  }
  L00576641: { trace_pc=0x00576641u; // 0x576641: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576643: { trace_pc=0x00576643u; // 0x576643: dc2508577800 FSUB double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576649: { trace_pc=0x00576649u; // 0x576649: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057664d: { trace_pc=0x0057664du; // 0x57664d: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727824u); flags=s.arithmetic_flags;
  }
  L00576650: { trace_pc=0x00576650u; // 0x576650: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576652: { trace_pc=0x00576652u; // 0x576652: dc2508577800 FSUB double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576658: { trace_pc=0x00576658u; // 0x576658: dd542410 FST double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057665c: { trace_pc=0x0057665cu; // 0x57665c: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0057665e: { trace_pc=0x0057665eu; // 0x57665e: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L00576660: { trace_pc=0x00576660u; // 0x576660: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00576664: { trace_pc=0x00576664u; // 0x576664: dc4c2408 FMUL double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.multiply64(read64(m,address));
  }
  L00576668: { trace_pc=0x00576668u; // 0x576668: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057666a: { trace_pc=0x0057666au; // 0x57666a: dc1508577800 FCOM double ptr [0x00785708]
    const auto address=(0x00785708u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00576670: { trace_pc=0x00576670u; // 0x576670: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00576672: { trace_pc=0x00576672u; // 0x576672: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00576675: { trace_pc=0x00576675u; // 0x576675: 74c5 JZ 0x0057663c
    if(integer::condition("JZ",flags)) goto L0057663c;
  }
  L00576677: { trace_pc=0x00576677u; // 0x576677: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057667d: { trace_pc=0x0057667du; // 0x57667d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057667f: { trace_pc=0x0057667fu; // 0x57667f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00576682: { trace_pc=0x00576682u; // 0x576682: 75b8 JNZ 0x0057663c
    if(integer::condition("JNZ",flags)) goto L0057663c;
  }
  L00576684: { trace_pc=0x00576684u; // 0x576684: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576686: { trace_pc=0x00576686u; // 0x576686: d9ed FLDLN2
    numeric_b88::detail::reg<0xd9ed>(s.fp);
  }
  L00576688: { trace_pc=0x00576688u; // 0x576688: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057668b: { trace_pc=0x0057668bu; // 0x57668b: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0057668d: { trace_pc=0x0057668du; // 0x57668d: d9f1 FYL2X
    numeric_b88::detail::reg<0xd9f1>(s.fp);
  }
  L0057668f: { trace_pc=0x0057668fu; // 0x57668f: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576691: { trace_pc=0x00576691u; // 0x576691: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00576693: { trace_pc=0x00576693u; // 0x576693: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00576695: { trace_pc=0x00576695u; // 0x576695: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L00576697: { trace_pc=0x00576697u; // 0x576697: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057669a: { trace_pc=0x0057669au; // 0x57669a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669c: { trace_pc=0x0057669cu; // 0x57669c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669e: { trace_pc=0x0057669eu; // 0x57669e: e8dd39f4ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5727907u); flags=s.arithmetic_flags;
  }
  L005766a3: { trace_pc=0x005766a3u; // 0x5766a3: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L005766a5: { trace_pc=0x005766a5u; // 0x5766a5: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L005766a9: { trace_pc=0x005766a9u; // 0x5766a9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005766ac: { trace_pc=0x005766acu; // 0x5766ac: c60601 MOV byte ptr [ESI],0x1
    m.w8((s.si), 0x00000001u);
  }
  L005766af: { trace_pc=0x005766afu; // 0x5766af: dd5e08 FSTP double ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005766b2: { trace_pc=0x005766b2u; // 0x5766b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005766b3: { trace_pc=0x005766b3u; // 0x5766b3: dc4c2404 FMUL double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.multiply64(read64(m,address));
  }
  L005766b7: { trace_pc=0x005766b7u; // 0x5766b7: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L005766b9: { trace_pc=0x005766b9u; // 0x5766b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005766ba: { trace_pc=0x005766bau; // 0x5766ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018be90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058be90: { trace_pc=0x0058be90u; // 0x58be90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058be91: { trace_pc=0x0058be91u; // 0x58be91: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  L0058be93: { trace_pc=0x0058be93u; // 0x58be93: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058be94: { trace_pc=0x0058be94u; // 0x58be94: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058be95: { trace_pc=0x0058be95u; // 0x58be95: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0058be99: { trace_pc=0x0058be99u; // 0x58be99: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058be9a: { trace_pc=0x0058be9au; // 0x58be9a: 8d1436 LEA EDX,[ESI + ESI*0x1]
    s.dx = (s.si+(s.si * 0x00000001u));
  }
  L0058be9d: { trace_pc=0x0058be9du; // 0x58be9d: 8d7c3601 LEA EDI,[ESI + ESI*0x1 + 0x1]
    s.di = (s.si+(s.si * 0x00000001u)+0x00000001u);
  }
  L0058bea1: { trace_pc=0x0058bea1u; // 0x58bea1: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0058bea3: { trace_pc=0x0058bea3u; // 0x58bea3: 7f18 JG 0x0058bebd
    if(integer::condition("JG",flags)) goto L0058bebd;
  }
  L0058bea5: { trace_pc=0x0058bea5u; // 0x58bea5: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bea8: { trace_pc=0x0058bea8u; // 0x58bea8: 8b2c90 MOV EBP,dword ptr [EAX + EDX*0x4]
    s.bp = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058beab: { trace_pc=0x0058beabu; // 0x58beab: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0058beae: { trace_pc=0x0058beaeu; // 0x58beae: d94504 FLD float ptr [EBP + 0x4]
    const auto address=(s.bp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058beb1: { trace_pc=0x0058beb1u; // 0x58beb1: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058beb4: { trace_pc=0x0058beb4u; // 0x58beb4: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058beb6: { trace_pc=0x0058beb6u; // 0x58beb6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058beb8: { trace_pc=0x0058beb8u; // 0x58beb8: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bebb: { trace_pc=0x0058bebbu; // 0x58bebb: 7402 JZ 0x0058bebf
    if(integer::condition("JZ",flags)) goto L0058bebf;
  }
  L0058bebd: { trace_pc=0x0058bebdu; // 0x58bebd: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0058bebf: { trace_pc=0x0058bebfu; // 0x58bebf: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0058bec1: { trace_pc=0x0058bec1u; // 0x58bec1: 7f1a JG 0x0058bedd
    if(integer::condition("JG",flags)) goto L0058bedd;
  }
  L0058bec3: { trace_pc=0x0058bec3u; // 0x58bec3: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bec6: { trace_pc=0x0058bec6u; // 0x58bec6: 8b1cb8 MOV EBX,dword ptr [EAX + EDI*0x4]
    s.bx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0058bec9: { trace_pc=0x0058bec9u; // 0x58bec9: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058becc: { trace_pc=0x0058beccu; // 0x58becc: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058becf: { trace_pc=0x0058becfu; // 0x58becf: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bed2: { trace_pc=0x0058bed2u; // 0x58bed2: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058bed4: { trace_pc=0x0058bed4u; // 0x58bed4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058bed6: { trace_pc=0x0058bed6u; // 0x58bed6: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bed9: { trace_pc=0x0058bed9u; // 0x58bed9: 7502 JNZ 0x0058bedd
    if(integer::condition("JNZ",flags)) goto L0058bedd;
  }
  L0058bedb: { trace_pc=0x0058bedbu; // 0x58bedb: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0058bedd: { trace_pc=0x0058beddu; // 0x58bedd: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0058bedf: { trace_pc=0x0058bedfu; // 0x58bedf: 7460 JZ 0x0058bf41
    if(integer::condition("JZ",flags)) goto L0058bf41;
  }
  L0058bee1: { trace_pc=0x0058bee1u; // 0x58bee1: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bee4: { trace_pc=0x0058bee4u; // 0x58bee4: 8d6c1201 LEA EBP,[EDX + EDX*0x1 + 0x1]
    s.bp = (s.dx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0058bee8: { trace_pc=0x0058bee8u; // 0x58bee8: 8b1c90 MOV EBX,dword ptr [EAX + EDX*0x4]
    s.bx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058beeb: { trace_pc=0x0058beebu; // 0x58beeb: 8b3cb0 MOV EDI,dword ptr [EAX + ESI*0x4]
    s.di = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0058beee: { trace_pc=0x0058beeeu; // 0x58beee: 891cb0 MOV dword ptr [EAX + ESI*0x4],EBX
    m.w32((s.ax+(s.si * 0x00000004u)), s.bx);
  }
  L0058bef1: { trace_pc=0x0058bef1u; // 0x58bef1: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bef4: { trace_pc=0x0058bef4u; // 0x58bef4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0058bef6: { trace_pc=0x0058bef6u; // 0x58bef6: 893c90 MOV dword ptr [EAX + EDX*0x4],EDI
    m.w32((s.ax+(s.dx * 0x00000004u)), s.di);
  }
  L0058bef9: { trace_pc=0x0058bef9u; // 0x58bef9: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  L0058befb: { trace_pc=0x0058befbu; // 0x58befb: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L0058befe: { trace_pc=0x0058befeu; // 0x58befe: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0058bf00: { trace_pc=0x0058bf00u; // 0x58bf00: 7f1d JG 0x0058bf1f
    if(integer::condition("JG",flags)) goto L0058bf1f;
  }
  L0058bf02: { trace_pc=0x0058bf02u; // 0x58bf02: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bf05: { trace_pc=0x0058bf05u; // 0x58bf05: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0058bf08: { trace_pc=0x0058bf08u; // 0x58bf08: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf0b: { trace_pc=0x0058bf0bu; // 0x58bf0b: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bf0e: { trace_pc=0x0058bf0eu; // 0x58bf0e: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058bf11: { trace_pc=0x0058bf11u; // 0x58bf11: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf14: { trace_pc=0x0058bf14u; // 0x58bf14: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058bf16: { trace_pc=0x0058bf16u; // 0x58bf16: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058bf18: { trace_pc=0x0058bf18u; // 0x58bf18: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bf1b: { trace_pc=0x0058bf1bu; // 0x58bf1b: 7502 JNZ 0x0058bf1f
    if(integer::condition("JNZ",flags)) goto L0058bf1f;
  }
  L0058bf1d: { trace_pc=0x0058bf1du; // 0x58bf1d: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0058bf1f: { trace_pc=0x0058bf1fu; // 0x58bf1f: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0058bf21: { trace_pc=0x0058bf21u; // 0x58bf21: 7f1a JG 0x0058bf3d
    if(integer::condition("JG",flags)) goto L0058bf3d;
  }
  L0058bf23: { trace_pc=0x0058bf23u; // 0x58bf23: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bf26: { trace_pc=0x0058bf26u; // 0x58bf26: 8b3ca8 MOV EDI,dword ptr [EAX + EBP*0x4]
    s.di = m.r32((s.ax+(s.bp * 0x00000004u)));
  }
  L0058bf29: { trace_pc=0x0058bf29u; // 0x58bf29: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058bf2c: { trace_pc=0x0058bf2cu; // 0x58bf2c: d94704 FLD float ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf2f: { trace_pc=0x0058bf2fu; // 0x58bf2f: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf32: { trace_pc=0x0058bf32u; // 0x58bf32: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058bf34: { trace_pc=0x0058bf34u; // 0x58bf34: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058bf36: { trace_pc=0x0058bf36u; // 0x58bf36: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bf39: { trace_pc=0x0058bf39u; // 0x58bf39: 7502 JNZ 0x0058bf3d
    if(integer::condition("JNZ",flags)) goto L0058bf3d;
  }
  L0058bf3b: { trace_pc=0x0058bf3bu; // 0x58bf3b: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L0058bf3d: { trace_pc=0x0058bf3du; // 0x58bf3d: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0058bf3f: { trace_pc=0x0058bf3fu; // 0x58bf3f: 75a0 JNZ 0x0058bee1
    if(integer::condition("JNZ",flags)) goto L0058bee1;
  }
  L0058bf41: { trace_pc=0x0058bf41u; // 0x58bf41: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058bf42: { trace_pc=0x0058bf42u; // 0x58bf42: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058bf43: { trace_pc=0x0058bf43u; // 0x58bf43: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058bf44: { trace_pc=0x0058bf44u; // 0x58bf44: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058bf45: { trace_pc=0x0058bf45u; // 0x58bf45: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { trace_pc=0x00545500u; // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { trace_pc=0x00545504u; // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { trace_pc=0x00545505u; // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { trace_pc=0x00545509u; // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { trace_pc=0x0054550cu; // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { trace_pc=0x0054550fu; // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { trace_pc=0x00545511u; // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { trace_pc=0x00545512u; // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { trace_pc=0x00545514u; // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { trace_pc=0x00545519u; // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { trace_pc=0x0054551bu; // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { trace_pc=0x00545521u; // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { trace_pc=0x00545524u; // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { trace_pc=0x00545526u; // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { trace_pc=0x00545528u; // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { trace_pc=0x0054552au; // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { trace_pc=0x0054552fu; // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { trace_pc=0x00545535u; // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { trace_pc=0x0047b190u; // 0x47b190: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { trace_pc=0x0047b193u; // 0x47b193: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { trace_pc=0x0047b198u; // 0x47b198: 7407 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { trace_pc=0x0047b19au; // 0x47b19a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { trace_pc=0x0047b19cu; // 0x47b19c: 7403 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { trace_pc=0x0047b19eu; // 0x47b19e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { trace_pc=0x0047b1a0u; // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { trace_pc=0x0047b1a1u; // 0x47b1a1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1a3: { trace_pc=0x0047b1a3u; // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { trace_pc=0x004ba080u; // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { trace_pc=0x004ba084u; // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { trace_pc=0x004ba08au; // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { trace_pc=0x004ba08cu; // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { trace_pc=0x004ba08fu; // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { trace_pc=0x004ba091u; // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { trace_pc=0x004ba093u; // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { trace_pc=0x004ba099u; // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { trace_pc=0x004ba09au; // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { trace_pc=0x004ba0a0u; // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { trace_pc=0x004ba0a2u; // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { trace_pc=0x004ba0a5u; // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { trace_pc=0x004ba0a7u; // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { trace_pc=0x004ba0adu; // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { trace_pc=0x004ba0b1u; // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { trace_pc=0x004ba0b5u; // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { trace_pc=0x004ba0b7u; // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { trace_pc=0x004ba0bdu; // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { trace_pc=0x004ba0c0u; // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { trace_pc=0x004ba0c3u; // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { trace_pc=0x004ba0c5u; // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { trace_pc=0x004ba0c7u; // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { trace_pc=0x004ba0cdu; // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { trace_pc=0x004ba0d0u; // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { trace_pc=0x004ba0d3u; // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { trace_pc=0x004ba0d6u; // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { trace_pc=0x004ba0d9u; // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { trace_pc=0x004ba0e0u; // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { trace_pc=0x004ba0e3u; // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { trace_pc=0x004ba0e5u; // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { trace_pc=0x004ba0e9u; // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { trace_pc=0x004ba0edu; // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { trace_pc=0x0062fde0u; // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { trace_pc=0x0062fde3u; // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { trace_pc=0x0062fde5u; // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { trace_pc=0x0062fde7u; // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { trace_pc=0x0062fde8u; // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { trace_pc=0x0062fdebu; // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { trace_pc=0x0062fdeeu; // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { trace_pc=0x0062fdefu; // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { trace_pc=0x0062fdf3u; // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { trace_pc=0x0062fdf7u; // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { trace_pc=0x0062fdfbu; // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { trace_pc=0x0062fdfdu; // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { trace_pc=0x0062fdffu; // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { trace_pc=0x0062fe02u; // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { trace_pc=0x0062fe05u; // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { trace_pc=0x0062fe09u; // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { trace_pc=0x0062fe0au; // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { trace_pc=0x0062fe0bu; // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { trace_pc=0x0062fe11u; // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { trace_pc=0x0062fe14u; // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { trace_pc=0x0062fe17u; // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { trace_pc=0x0062fe19u; // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { trace_pc=0x0062fe20u; // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { trace_pc=0x0062fe26u; // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { trace_pc=0x0062fe27u; // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { trace_pc=0x0062fe29u; // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { trace_pc=0x0062fe30u; // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 if(target==0x76d957u){s.ax=heap_allocate(m,m.r32(f.sp));s.cx=1u;return;}
 if(target==0x76d67bu){s.ax=heap_release(m.r32(f.sp));s.cx=m.r32(f.sp);return;}
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5746432u:f_0017af00(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5600064u:f_00157340(m,s,child,{});break;
case 5599872u:f_00157280(m,s,child,{});break;
case 5727776u:f_00176620(m,s,child,{});break;
case 5815952u:f_0018be90(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
default:throw std::domain_error("recovery1561 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1561 unreviewed tail"); } }

std::uint32_t fun_0057af00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057af00: { trace_pc=0x0057af00u; // 0x57af00: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0057af01: { trace_pc=0x0057af01u; // 0x57af01: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0057af03: { trace_pc=0x0057af03u; // 0x57af03: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0057af06: { trace_pc=0x0057af06u; // 0x57af06: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L0057af09: { trace_pc=0x0057af09u; // 0x57af09: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0057af0a: { trace_pc=0x0057af0au; // 0x57af0a: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0057af0c: { trace_pc=0x0057af0cu; // 0x57af0c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057af0d: { trace_pc=0x0057af0du; // 0x57af0d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057af0e: { trace_pc=0x0057af0eu; // 0x57af0e: 8b434c MOV EAX,dword ptr [EBX + 0x4c]
    s.ax = m.r32((s.bx+0x0000004cu));
  }
  L0057af11: { trace_pc=0x0057af11u; // 0x57af11: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0057af15: { trace_pc=0x0057af15u; // 0x57af15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057af17: { trace_pc=0x0057af17u; // 0x57af17: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0057af1c: { trace_pc=0x0057af1cu; // 0x57af1c: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0057af20: { trace_pc=0x0057af20u; // 0x57af20: 7421 JZ 0x0057af43
    if(integer::condition("JZ",flags)) goto L0057af43;
  }
  L0057af22: { trace_pc=0x0057af22u; // 0x57af22: db8384010000 FILD dword ptr [EBX + 0x184]
    const auto address=(s.bx+0x00000184u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057af28: { trace_pc=0x0057af28u; // 0x57af28: da8b80010000 FIMUL dword ptr [EBX + 0x180]
    const auto address=(s.bx+0x00000180u);
    fimul32(s.fp,m.r32(address));
  }
  L0057af2e: { trace_pc=0x0057af2eu; // 0x57af2e: da4c2450 FIMUL dword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    fimul32(s.fp,m.r32(address));
  }
  L0057af32: { trace_pc=0x0057af32u; // 0x57af32: dc0d200f7900 FMUL double ptr [0x00790f20]
    const auto address=(0x00790f20u);
    s.fp.multiply64(read64(m,address));
  }
  L0057af38: { trace_pc=0x0057af38u; // 0x57af38: dc05f0677800 FADD double ptr [0x007867f0]
    const auto address=(0x007867f0u);
    s.fp.add64(read64(m,address));
  }
  L0057af3e: { trace_pc=0x0057af3eu; // 0x57af3e: e80dfb1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5746499u); flags=s.arithmetic_flags;
  }
  L0057af43: { trace_pc=0x0057af43u; // 0x57af43: 2b8304030000 SUB EAX,dword ptr [EBX + 0x304]
    s.ax = integer::sub(s.ax,m.r32((s.bx+0x00000304u)),32,flags);
  }
  L0057af49: { trace_pc=0x0057af49u; // 0x57af49: 83f84b CMP EAX,0x4b
    (void)integer::sub(s.ax,0x0000004bu,32,flags);
  }
  L0057af4c: { trace_pc=0x0057af4cu; // 0x57af4c: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0057af50: { trace_pc=0x0057af50u; // 0x57af50: 0f8eb60a0000 JLE 0x0057ba0c
    if(integer::condition("JLE",flags)) goto L0057ba0c;
  }
  L0057af56: { trace_pc=0x0057af56u; // 0x57af56: 8d7c0002 LEA EDI,[EAX + EAX*0x1 + 0x2]
    s.di = (s.ax+(s.ax * 0x00000001u)+0x00000002u);
  }
  L0057af5a: { trace_pc=0x0057af5au; // 0x57af5a: 83ff64 CMP EDI,0x64
    (void)integer::sub(s.di,0x00000064u,32,flags);
  }
  L0057af5d: { trace_pc=0x0057af5du; // 0x57af5d: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0057af5f: { trace_pc=0x0057af5fu; // 0x57af5f: 7f05 JG 0x0057af66
    if(integer::condition("JG",flags)) goto L0057af66;
  }
  L0057af61: { trace_pc=0x0057af61u; // 0x57af61: be64000000 MOV ESI,0x64
    s.si = 0x00000064u;
  }
  L0057af66: { trace_pc=0x0057af66u; // 0x57af66: 8d04f500000000 LEA EAX,[ESI*0x8 + 0x0]
    s.ax = ((s.si * 0x00000008u)+0x00000000u);
  }
  L0057af6d: { trace_pc=0x0057af6du; // 0x57af6d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057af6e: { trace_pc=0x0057af6eu; // 0x57af6e: e8e4291f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5746547u); flags=s.arithmetic_flags;
  }
  L0057af73: { trace_pc=0x0057af73u; // 0x57af73: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057af76: { trace_pc=0x0057af76u; // 0x57af76: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057af78: { trace_pc=0x0057af78u; // 0x57af78: 740b JZ 0x0057af85
    if(integer::condition("JZ",flags)) goto L0057af85;
  }
  L0057af7a: { trace_pc=0x0057af7au; // 0x57af7a: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0057af7b: { trace_pc=0x0057af7bu; // 0x57af7b: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0057af7f: { trace_pc=0x0057af7fu; // 0x57af7f: 89742460 MOV dword ptr [ESP + 0x60],ESI
    m.w32((f.sp+0x00000060u), s.si);
  }
  L0057af83: { trace_pc=0x0057af83u; // 0x57af83: eb08 JMP 0x0057af8d
    goto L0057af8d;
  }
  L0057af85: { trace_pc=0x0057af85u; // 0x57af85: c744242800000000 MOV dword ptr [ESP + 0x28],0x0
    m.w32((f.sp+0x00000028u), 0x00000000u);
  }
  L0057af8d: { trace_pc=0x0057af8du; // 0x57af8d: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  L0057af8f: { trace_pc=0x0057af8fu; // 0x57af8f: e8c3291f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5746580u); flags=s.arithmetic_flags;
  }
  L0057af94: { trace_pc=0x0057af94u; // 0x57af94: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0057af96: { trace_pc=0x0057af96u; // 0x57af96: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057af99: { trace_pc=0x0057af99u; // 0x57af99: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0057af9b: { trace_pc=0x0057af9bu; // 0x57af9b: 744a JZ 0x0057afe7
    if(integer::condition("JZ",flags)) goto L0057afe7;
  }
  L0057af9d: { trace_pc=0x0057af9du; // 0x57af9d: 83ff64 CMP EDI,0x64
    (void)integer::sub(s.di,0x00000064u,32,flags);
  }
  L0057afa0: { trace_pc=0x0057afa0u; // 0x57afa0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0057afa2: { trace_pc=0x0057afa2u; // 0x57afa2: 7f05 JG 0x0057afa9
    if(integer::condition("JG",flags)) goto L0057afa9;
  }
  L0057afa4: { trace_pc=0x0057afa4u; // 0x57afa4: b864000000 MOV EAX,0x64
    s.ax = 0x00000064u;
  }
  L0057afa9: { trace_pc=0x0057afa9u; // 0x57afa9: 8d0c8504000000 LEA ECX,[EAX*0x4 + 0x4]
    s.cx = ((s.ax * 0x00000004u)+0x00000004u);
  }
  L0057afb0: { trace_pc=0x0057afb0u; // 0x57afb0: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057afb2: { trace_pc=0x0057afb2u; // 0x57afb2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057afb3: { trace_pc=0x0057afb3u; // 0x57afb3: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0057afb6: { trace_pc=0x0057afb6u; // 0x57afb6: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  L0057afbd: { trace_pc=0x0057afbdu; // 0x57afbd: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L0057afbf: { trace_pc=0x0057afbfu; // 0x57afbf: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0057afc2: { trace_pc=0x0057afc2u; // 0x57afc2: e890291f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5746631u); flags=s.arithmetic_flags;
  }
  L0057afc7: { trace_pc=0x0057afc7u; // 0x57afc7: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0057afca: { trace_pc=0x0057afcau; // 0x57afca: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0057afcd: { trace_pc=0x0057afcdu; // 0x57afcd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057afd0: { trace_pc=0x0057afd0u; // 0x57afd0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057afd2: { trace_pc=0x0057afd2u; // 0x57afd2: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057afd4: { trace_pc=0x0057afd4u; // 0x57afd4: 7c15 JL 0x0057afeb
    if(integer::condition("JL",flags)) goto L0057afeb;
  }
  L0057afd6: { trace_pc=0x0057afd6u; // 0x57afd6: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057afd9: { trace_pc=0x0057afd9u; // 0x57afd9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057afda: { trace_pc=0x0057afdau; // 0x57afda: 897c82fc MOV dword ptr [EDX + EAX*0x4 + -0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.di);
  }
  L0057afde: { trace_pc=0x0057afdeu; // 0x57afde: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0057afe1: { trace_pc=0x0057afe1u; // 0x57afe1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057afe3: { trace_pc=0x0057afe3u; // 0x57afe3: 7ef1 JLE 0x0057afd6
    if(integer::condition("JLE",flags)) goto L0057afd6;
  }
  L0057afe5: { trace_pc=0x0057afe5u; // 0x57afe5: eb04 JMP 0x0057afeb
    goto L0057afeb;
  }
  L0057afe7: { trace_pc=0x0057afe7u; // 0x57afe7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057afe9: { trace_pc=0x0057afe9u; // 0x57afe9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057afeb: { trace_pc=0x0057afebu; // 0x57afeb: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057aff0: { trace_pc=0x0057aff0u; // 0x57aff0: e84bc3fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5746677u); flags=s.arithmetic_flags;
  }
  L0057aff5: { trace_pc=0x0057aff5u; // 0x57aff5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057affa: { trace_pc=0x0057affau; // 0x57affa: e881c2fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5746687u); flags=s.arithmetic_flags;
  }
  L0057afff: { trace_pc=0x0057afffu; // 0x57afff: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057b001: { trace_pc=0x0057b001u; // 0x57b001: 7435 JZ 0x0057b038
    if(integer::condition("JZ",flags)) goto L0057b038;
  }
  L0057b003: { trace_pc=0x0057b003u; // 0x57b003: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L0057b006: { trace_pc=0x0057b006u; // 0x57b006: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L0057b00a: { trace_pc=0x0057b00au; // 0x57b00a: 0fbf442452 MOVSX EAX,word ptr [ESP + 0x52]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000052u)),16));
  }
  L0057b00f: { trace_pc=0x0057b00fu; // 0x57b00f: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b016: { trace_pc=0x0057b016u; // 0x57b016: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057b019: { trace_pc=0x0057b019u; // 0x57b019: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057b01b: { trace_pc=0x0057b01bu; // 0x57b01b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b020: { trace_pc=0x0057b020u; // 0x57b020: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b023: { trace_pc=0x0057b023u; // 0x57b023: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0057b028: { trace_pc=0x0057b028u; // 0x57b028: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b02b: { trace_pc=0x0057b02bu; // 0x57b02b: 897c023c MOV dword ptr [EDX + EAX*0x1 + 0x3c],EDI
    m.w32((s.dx+(s.ax * 0x00000001u)+0x0000003cu), s.di);
  }
  L0057b02f: { trace_pc=0x0057b02fu; // 0x57b02f: e84cc2fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5746740u); flags=s.arithmetic_flags;
  }
  L0057b034: { trace_pc=0x0057b034u; // 0x57b034: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057b036: { trace_pc=0x0057b036u; // 0x57b036: 75cb JNZ 0x0057b003
    if(integer::condition("JNZ",flags)) goto L0057b003;
  }
  L0057b038: { trace_pc=0x0057b038u; // 0x57b038: 8b3d4c6b8300 MOV EDI,dword ptr [0x00836b4c]
    s.di = m.r32((0x00836b4cu));
  }
  L0057b03e: { trace_pc=0x0057b03eu; // 0x57b03e: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0057b041: { trace_pc=0x0057b041u; // 0x57b041: 0fafff IMUL EDI,EDI
    s.di = integer::imul(s.di,s.di,32,flags);
  }
  L0057b044: { trace_pc=0x0057b044u; // 0x57b044: 66833900 CMP word ptr [ECX],0x0
    (void)integer::sub(m.r16((s.cx)),0x00000000u,16,flags);
  }
  L0057b048: { trace_pc=0x0057b048u; // 0x57b048: 0f8513020000 JNZ 0x0057b261
    if(integer::condition("JNZ",flags)) goto L0057b261;
  }
  L0057b04e: { trace_pc=0x0057b04eu; // 0x57b04e: 6683790200 CMP word ptr [ECX + 0x2],0x0
    (void)integer::sub(m.r16((s.cx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b053: { trace_pc=0x0057b053u; // 0x57b053: 0f8508020000 JNZ 0x0057b261
    if(integer::condition("JNZ",flags)) goto L0057b261;
  }
  L0057b059: { trace_pc=0x0057b059u; // 0x57b059: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b05b: { trace_pc=0x0057b05bu; // 0x57b05b: 7e15 JLE 0x0057b072
    if(integer::condition("JLE",flags)) goto L0057b072;
  }
  L0057b05d: { trace_pc=0x0057b05du; // 0x57b05d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b05f: { trace_pc=0x0057b05fu; // 0x57b05f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b061: { trace_pc=0x0057b061u; // 0x57b061: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b067: { trace_pc=0x0057b067u; // 0x57b067: 83c050 ADD EAX,0x50
    s.ax = integer::add(s.ax,0x00000050u,32,flags);
  }
  L0057b06a: { trace_pc=0x0057b06au; // 0x57b06a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b06b: { trace_pc=0x0057b06bu; // 0x57b06b: c64410f400 MOV byte ptr [EAX + EDX*0x1 + -0xc],0x0
    m.w8((s.ax+(s.dx * 0x00000001u)-0x0000000cu), 0x00000000u);
  }
  L0057b070: { trace_pc=0x0057b070u; // 0x57b070: 75ef JNZ 0x0057b061
    if(integer::condition("JNZ",flags)) goto L0057b061;
  }
  L0057b072: { trace_pc=0x0057b072u; // 0x57b072: 6afe PUSH -0x2
    f.push(m,0xfffffffeu);
  }
  L0057b074: { trace_pc=0x0057b074u; // 0x57b074: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0057b076: { trace_pc=0x0057b076u; // 0x57b076: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0057b078: { trace_pc=0x0057b078u; // 0x57b078: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057b07a: { trace_pc=0x0057b07au; // 0x57b07a: e871390000 CALL 0x0057e9f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0057e9f0u,5746815u); flags=s.arithmetic_flags;
  }
  L0057b07f: { trace_pc=0x0057b07fu; // 0x57b07f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b081: { trace_pc=0x0057b081u; // 0x57b081: 7e39 JLE 0x0057b0bc
    if(integer::condition("JLE",flags)) goto L0057b0bc;
  }
  L0057b083: { trace_pc=0x0057b083u; // 0x57b083: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0057b085: { trace_pc=0x0057b085u; // 0x57b085: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0057b08a: { trace_pc=0x0057b08au; // 0x57b08a: 8d4c0238 LEA ECX,[EDX + EAX*0x1 + 0x38]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000038u);
  }
  L0057b08e: { trace_pc=0x0057b08eu; // 0x57b08e: 8b440238 MOV EAX,dword ptr [EDX + EAX*0x1 + 0x38]
    s.ax = m.r32((s.dx+(s.ax * 0x00000001u)+0x00000038u));
  }
  L0057b092: { trace_pc=0x0057b092u; // 0x57b092: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b094: { trace_pc=0x0057b094u; // 0x57b094: 7415 JZ 0x0057b0ab
    if(integer::condition("JZ",flags)) goto L0057b0ab;
  }
  L0057b096: { trace_pc=0x0057b096u; // 0x57b096: 3b8308030000 CMP EAX,dword ptr [EBX + 0x308]
    (void)integer::sub(s.ax,m.r32((s.bx+0x00000308u)),32,flags);
  }
  L0057b09c: { trace_pc=0x0057b09cu; // 0x57b09c: 740d JZ 0x0057b0ab
    if(integer::condition("JZ",flags)) goto L0057b0ab;
  }
  L0057b09e: { trace_pc=0x0057b09eu; // 0x57b09e: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L0057b0a1: { trace_pc=0x0057b0a1u; // 0x57b0a1: 7513 JNZ 0x0057b0b6
    if(integer::condition("JNZ",flags)) goto L0057b0b6;
  }
  L0057b0a3: { trace_pc=0x0057b0a3u; // 0x57b0a3: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L0057b0a9: { trace_pc=0x0057b0a9u; // 0x57b0a9: eb0b JMP 0x0057b0b6
    goto L0057b0b6;
  }
  L0057b0ab: { trace_pc=0x0057b0abu; // 0x57b0ab: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b0b1: { trace_pc=0x0057b0b1u; // 0x57b0b1: c6440a4401 MOV byte ptr [EDX + ECX*0x1 + 0x44],0x1
    m.w8((s.dx+(s.cx * 0x00000001u)+0x00000044u), 0x00000001u);
  }
  L0057b0b6: { trace_pc=0x0057b0b6u; // 0x57b0b6: 83c250 ADD EDX,0x50
    s.dx = integer::add(s.dx,0x00000050u,32,flags);
  }
  L0057b0b9: { trace_pc=0x0057b0b9u; // 0x57b0b9: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0057b0ba: { trace_pc=0x0057b0bau; // 0x57b0ba: 75c9 JNZ 0x0057b085
    if(integer::condition("JNZ",flags)) goto L0057b085;
  }
  L0057b0bc: { trace_pc=0x0057b0bcu; // 0x57b0bc: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0057b0bf: { trace_pc=0x0057b0bfu; // 0x57b0bf: 66833900 CMP word ptr [ECX],0x0
    (void)integer::sub(m.r16((s.cx)),0x00000000u,16,flags);
  }
  L0057b0c3: { trace_pc=0x0057b0c3u; // 0x57b0c3: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0057b0cb: { trace_pc=0x0057b0cbu; // 0x57b0cb: 0f85b0010000 JNZ 0x0057b281
    if(integer::condition("JNZ",flags)) goto L0057b281;
  }
  L0057b0d1: { trace_pc=0x0057b0d1u; // 0x57b0d1: 6683790200 CMP word ptr [ECX + 0x2],0x0
    (void)integer::sub(m.r16((s.cx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b0d6: { trace_pc=0x0057b0d6u; // 0x57b0d6: 0f85a5010000 JNZ 0x0057b281
    if(integer::condition("JNZ",flags)) goto L0057b281;
  }
  L0057b0dc: { trace_pc=0x0057b0dcu; // 0x57b0dc: a110a98100 MOV EAX,[0x0081a910]
    s.ax = m.r32((0x0081a910u));
  }
  L0057b0e1: { trace_pc=0x0057b0e1u; // 0x57b0e1: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L0057b0e9: { trace_pc=0x0057b0e9u; // 0x57b0e9: 8d58ff LEA EBX,[EAX + -0x1]
    s.bx = (s.ax-0x00000001u);
  }
  L0057b0ec: { trace_pc=0x0057b0ecu; // 0x57b0ec: 8d4b01 LEA ECX,[EBX + 0x1]
    s.cx = (s.bx+0x00000001u);
  }
  L0057b0ef: { trace_pc=0x0057b0efu; // 0x57b0ef: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0057b0f3: { trace_pc=0x0057b0f3u; // 0x57b0f3: df6c243c FILD qword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b0f7: { trace_pc=0x0057b0f7u; // 0x57b0f7: dd5c2468 FSTP double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b0fb: { trace_pc=0x0057b0fbu; // 0x57b0fb: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057b100: { trace_pc=0x0057b100u; // 0x57b100: e8db4c0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5746949u); flags=s.arithmetic_flags;
  }
  L0057b105: { trace_pc=0x0057b105u; // 0x57b105: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0057b109: { trace_pc=0x0057b109u; // 0x57b109: c744243800000000 MOV dword ptr [ESP + 0x38],0x0
    m.w32((f.sp+0x00000038u), 0x00000000u);
  }
  L0057b111: { trace_pc=0x0057b111u; // 0x57b111: df6c2434 FILD qword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b115: { trace_pc=0x0057b115u; // 0x57b115: dc4c2468 FMUL double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b119: { trace_pc=0x0057b119u; // 0x57b119: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b11f: { trace_pc=0x0057b11fu; // 0x57b11f: e82cf91e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5746980u); flags=s.arithmetic_flags;
  }
  L0057b124: { trace_pc=0x0057b124u; // 0x57b124: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0057b126: { trace_pc=0x0057b126u; // 0x57b126: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0057b128: { trace_pc=0x0057b128u; // 0x57b128: 77d1 JA 0x0057b0fb
    if(integer::condition("JA",flags)) goto L0057b0fb;
  }
  L0057b12a: { trace_pc=0x0057b12au; // 0x57b12a: 8b1514a98100 MOV EDX,dword ptr [0x0081a914]
    s.dx = m.r32((0x0081a914u));
  }
  L0057b130: { trace_pc=0x0057b130u; // 0x57b130: c744243000000000 MOV dword ptr [ESP + 0x30],0x0
    m.w32((f.sp+0x00000030u), 0x00000000u);
  }
  L0057b138: { trace_pc=0x0057b138u; // 0x57b138: 8d5aff LEA EBX,[EDX + -0x1]
    s.bx = (s.dx-0x00000001u);
  }
  L0057b13b: { trace_pc=0x0057b13bu; // 0x57b13b: 8d4301 LEA EAX,[EBX + 0x1]
    s.ax = (s.bx+0x00000001u);
  }
  L0057b13e: { trace_pc=0x0057b13eu; // 0x57b13e: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0057b142: { trace_pc=0x0057b142u; // 0x57b142: df6c242c FILD qword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b146: { trace_pc=0x0057b146u; // 0x57b146: dd5c2468 FSTP double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b14a: { trace_pc=0x0057b14au; // 0x57b14a: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057b14f: { trace_pc=0x0057b14fu; // 0x57b14f: e88c4c0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5747028u); flags=s.arithmetic_flags;
  }
  L0057b154: { trace_pc=0x0057b154u; // 0x57b154: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0057b158: { trace_pc=0x0057b158u; // 0x57b158: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
  L0057b160: { trace_pc=0x0057b160u; // 0x57b160: df6c241c FILD qword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b164: { trace_pc=0x0057b164u; // 0x57b164: dc4c2468 FMUL double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b168: { trace_pc=0x0057b168u; // 0x57b168: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b16e: { trace_pc=0x0057b16eu; // 0x57b16e: e8ddf81e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5747059u); flags=s.arithmetic_flags;
  }
  L0057b173: { trace_pc=0x0057b173u; // 0x57b173: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057b175: { trace_pc=0x0057b175u; // 0x57b175: 77d3 JA 0x0057b14a
    if(integer::condition("JA",flags)) goto L0057b14a;
  }
  L0057b177: { trace_pc=0x0057b177u; // 0x57b177: 668b1510a98100 MOV DX,word ptr [0x0081a910]
    s.dx = with_ax(s.dx, m.r16((0x0081a910u)));
  }
  L0057b17e: { trace_pc=0x0057b17eu; // 0x57b17e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b180: { trace_pc=0x0057b180u; // 0x57b180: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0057b182: { trace_pc=0x0057b182u; // 0x57b182: 66894c245a MOV word ptr [ESP + 0x5a],CX
    m.w16((f.sp+0x0000005au), (s.cx & 0xffffu));
  }
  L0057b187: { trace_pc=0x0057b187u; // 0x57b187: 8b4c245a MOV ECX,dword ptr [ESP + 0x5a]
    s.cx = m.r32((f.sp+0x0000005au));
  }
  L0057b18b: { trace_pc=0x0057b18bu; // 0x57b18b: 6689542452 MOV word ptr [ESP + 0x52],DX
    m.w16((f.sp+0x00000052u), (s.dx & 0xffffu));
  }
  L0057b190: { trace_pc=0x0057b190u; // 0x57b190: 8b542452 MOV EDX,dword ptr [ESP + 0x52]
    s.dx = m.r32((f.sp+0x00000052u));
  }
  L0057b194: { trace_pc=0x0057b194u; // 0x57b194: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0057b195: { trace_pc=0x0057b195u; // 0x57b195: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057b197: { trace_pc=0x0057b197u; // 0x57b197: 66897c2460 MOV word ptr [ESP + 0x60],DI
    m.w16((f.sp+0x00000060u), (s.di & 0xffffu));
  }
  L0057b19c: { trace_pc=0x0057b19cu; // 0x57b19c: 66894c2462 MOV word ptr [ESP + 0x62],CX
    m.w16((f.sp+0x00000062u), (s.cx & 0xffffu));
  }
  L0057b1a1: { trace_pc=0x0057b1a1u; // 0x57b1a1: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L0057b1a5: { trace_pc=0x0057b1a5u; // 0x57b1a5: 8b542462 MOV EDX,dword ptr [ESP + 0x62]
    s.dx = m.r32((f.sp+0x00000062u));
  }
  L0057b1a9: { trace_pc=0x0057b1a9u; // 0x57b1a9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0057b1ab: { trace_pc=0x0057b1abu; // 0x57b1ab: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b1ad: { trace_pc=0x0057b1adu; // 0x57b1ad: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L0057b1b2: { trace_pc=0x0057b1b2u; // 0x57b1b2: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L0057b1b7: { trace_pc=0x0057b1b7u; // 0x57b1b7: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L0057b1bb: { trace_pc=0x0057b1bbu; // 0x57b1bb: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0057b1bf: { trace_pc=0x0057b1bfu; // 0x57b1bf: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0057b1c3: { trace_pc=0x0057b1c3u; // 0x57b1c3: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0057b1c4: { trace_pc=0x0057b1c4u; // 0x57b1c4: 81fac8000000 CMP EDX,0xc8
    (void)integer::sub(s.dx,0x000000c8u,32,flags);
  }
  L0057b1ca: { trace_pc=0x0057b1cau; // 0x57b1ca: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0057b1ce: { trace_pc=0x0057b1ceu; // 0x57b1ce: 0f8d38080000 JGE 0x0057ba0c
    if(integer::condition("JGE",flags)) goto L0057ba0c;
  }
  L0057b1d4: { trace_pc=0x0057b1d4u; // 0x57b1d4: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b1da: { trace_pc=0x0057b1dau; // 0x57b1da: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057b1dc: { trace_pc=0x0057b1dcu; // 0x57b1dc: 0f84fafeffff JZ 0x0057b0dc
    if(integer::condition("JZ",flags)) goto L0057b0dc;
  }
  L0057b1e2: { trace_pc=0x0057b1e2u; // 0x57b1e2: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057b1e5: { trace_pc=0x0057b1e5u; // 0x57b1e5: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b1ec: { trace_pc=0x0057b1ecu; // 0x57b1ec: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057b1ef: { trace_pc=0x0057b1efu; // 0x57b1ef: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057b1f1: { trace_pc=0x0057b1f1u; // 0x57b1f1: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b1f4: { trace_pc=0x0057b1f4u; // 0x57b1f4: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b1f7: { trace_pc=0x0057b1f7u; // 0x57b1f7: 8b4c1038 MOV ECX,dword ptr [EAX + EDX*0x1 + 0x38]
    s.cx = m.r32((s.ax+(s.dx * 0x00000001u)+0x00000038u));
  }
  L0057b1fb: { trace_pc=0x0057b1fbu; // 0x57b1fb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b1fd: { trace_pc=0x0057b1fdu; // 0x57b1fd: 0f85d9feffff JNZ 0x0057b0dc
    if(integer::condition("JNZ",flags)) goto L0057b0dc;
  }
  L0057b203: { trace_pc=0x0057b203u; // 0x57b203: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0057b207: { trace_pc=0x0057b207u; // 0x57b207: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b208: { trace_pc=0x0057b208u; // 0x57b208: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b20d: { trace_pc=0x0057b20du; // 0x57b20d: e8eea2fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5747218u); flags=s.arithmetic_flags;
  }
  L0057b212: { trace_pc=0x0057b212u; // 0x57b212: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057b214: { trace_pc=0x0057b214u; // 0x57b214: e877ffefff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5747225u); flags=s.arithmetic_flags;
  }
  L0057b219: { trace_pc=0x0057b219u; // 0x57b219: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b21b: { trace_pc=0x0057b21bu; // 0x57b21b: 0f84bbfeffff JZ 0x0057b0dc
    if(integer::condition("JZ",flags)) goto L0057b0dc;
  }
  L0057b221: { trace_pc=0x0057b221u; // 0x57b221: 0fbf44241a MOVSX EAX,word ptr [ESP + 0x1a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001au)),16));
  }
  L0057b226: { trace_pc=0x0057b226u; // 0x57b226: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b22d: { trace_pc=0x0057b22du; // 0x57b22d: 0fbf542418 MOVSX EDX,word ptr [ESP + 0x18]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  L0057b232: { trace_pc=0x0057b232u; // 0x57b232: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b238: { trace_pc=0x0057b238u; // 0x57b238: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b23a: { trace_pc=0x0057b23au; // 0x57b23a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b23d: { trace_pc=0x0057b23du; // 0x57b23d: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b240: { trace_pc=0x0057b240u; // 0x57b240: 8a540844 MOV DL,byte ptr [EAX + ECX*0x1 + 0x44]
    s.dx = with_al(s.dx, m.r8((s.ax+(s.cx * 0x00000001u)+0x00000044u)));
  }
  L0057b244: { trace_pc=0x0057b244u; // 0x57b244: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0057b246: { trace_pc=0x0057b246u; // 0x57b246: 0f8490feffff JZ 0x0057b0dc
    if(integer::condition("JZ",flags)) goto L0057b0dc;
  }
  L0057b24c: { trace_pc=0x0057b24cu; // 0x57b24c: 817c2424c8000000 CMP dword ptr [ESP + 0x24],0xc8
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x000000c8u,32,flags);
  }
  L0057b254: { trace_pc=0x0057b254u; // 0x57b254: 7c31 JL 0x0057b287
    if(integer::condition("JL",flags)) goto L0057b287;
  }
  L0057b256: { trace_pc=0x0057b256u; // 0x57b256: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0057b258: { trace_pc=0x0057b258u; // 0x57b258: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057b259: { trace_pc=0x0057b259u; // 0x57b259: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057b25a: { trace_pc=0x0057b25au; // 0x57b25a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057b25b: { trace_pc=0x0057b25bu; // 0x57b25b: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057b25d: { trace_pc=0x0057b25du; // 0x57b25d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057b25e: { trace_pc=0x0057b25eu; // 0x57b25e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057b261: { trace_pc=0x0057b261u; // 0x57b261: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b263: { trace_pc=0x0057b263u; // 0x57b263: 0f8e56feffff JLE 0x0057b0bf
    if(integer::condition("JLE",flags)) goto L0057b0bf;
  }
  L0057b269: { trace_pc=0x0057b269u; // 0x57b269: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b26b: { trace_pc=0x0057b26bu; // 0x57b26b: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b271: { trace_pc=0x0057b271u; // 0x57b271: 83c050 ADD EAX,0x50
    s.ax = integer::add(s.ax,0x00000050u,32,flags);
  }
  L0057b274: { trace_pc=0x0057b274u; // 0x57b274: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0057b275: { trace_pc=0x0057b275u; // 0x57b275: c64410f401 MOV byte ptr [EAX + EDX*0x1 + -0xc],0x1
    m.w8((s.ax+(s.dx * 0x00000001u)-0x0000000cu), 0x00000001u);
  }
  L0057b27a: { trace_pc=0x0057b27au; // 0x57b27a: 75ef JNZ 0x0057b26b
    if(integer::condition("JNZ",flags)) goto L0057b26b;
  }
  L0057b27c: { trace_pc=0x0057b27cu; // 0x57b27c: e93efeffff JMP 0x0057b0bf
    goto L0057b0bf;
  }
  L0057b281: { trace_pc=0x0057b281u; // 0x57b281: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0057b283: { trace_pc=0x0057b283u; // 0x57b283: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0057b287: { trace_pc=0x0057b287u; // 0x57b287: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0057b28b: { trace_pc=0x0057b28bu; // 0x57b28b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057b28d: { trace_pc=0x0057b28du; // 0x57b28d: 83f94c CMP ECX,0x4c
    (void)integer::sub(s.cx,0x0000004cu,32,flags);
  }
  L0057b290: { trace_pc=0x0057b290u; // 0x57b290: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0057b294: { trace_pc=0x0057b294u; // 0x57b294: c74424444c000000 MOV dword ptr [ESP + 0x44],0x4c
    m.w32((f.sp+0x00000044u), 0x0000004cu);
  }
  L0057b29c: { trace_pc=0x0057b29cu; // 0x57b29c: 7c04 JL 0x0057b2a2
    if(integer::condition("JL",flags)) goto L0057b2a2;
  }
  L0057b29e: { trace_pc=0x0057b29eu; // 0x57b29e: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0057b2a2: { trace_pc=0x0057b2a2u; // 0x57b2a2: b8abaaaa2a MOV EAX,0x2aaaaaab
    s.ax = 0x2aaaaaabu;
  }
  L0057b2a7: { trace_pc=0x0057b2a7u; // 0x57b2a7: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0057b2a9: { trace_pc=0x0057b2a9u; // 0x57b2a9: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b2ad: { trace_pc=0x0057b2adu; // 0x57b2ad: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b2b1: { trace_pc=0x0057b2b1u; // 0x57b2b1: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0057b2b3: { trace_pc=0x0057b2b3u; // 0x57b2b3: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0057b2b6: { trace_pc=0x0057b2b6u; // 0x57b2b6: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0057b2b8: { trace_pc=0x0057b2b8u; // 0x57b2b8: b856555555 MOV EAX,0x55555556
    s.ax = 0x55555556u;
  }
  L0057b2bd: { trace_pc=0x0057b2bdu; // 0x57b2bd: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0057b2c1: { trace_pc=0x0057b2c1u; // 0x57b2c1: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0057b2c3: { trace_pc=0x0057b2c3u; // 0x57b2c3: db442450 FILD dword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b2c7: { trace_pc=0x0057b2c7u; // 0x57b2c7: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b2cb: { trace_pc=0x0057b2cbu; // 0x57b2cb: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057b2cd: { trace_pc=0x0057b2cdu; // 0x57b2cd: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0057b2d0: { trace_pc=0x0057b2d0u; // 0x57b2d0: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0057b2d2: { trace_pc=0x0057b2d2u; // 0x57b2d2: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0057b2d6: { trace_pc=0x0057b2d6u; // 0x57b2d6: db442450 FILD dword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b2da: { trace_pc=0x0057b2dau; // 0x57b2da: dd542458 FST double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057b2de: { trace_pc=0x0057b2deu; // 0x57b2de: dc642460 FSUB double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.subtract64(read64(m,address));
  }
  L0057b2e2: { trace_pc=0x0057b2e2u; // 0x57b2e2: dc5c2448 FCOMP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b2e6: { trace_pc=0x0057b2e6u; // 0x57b2e6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b2e8: { trace_pc=0x0057b2e8u; // 0x57b2e8: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b2eb: { trace_pc=0x0057b2ebu; // 0x57b2eb: 7415 JZ 0x0057b302
    if(integer::condition("JZ",flags)) goto L0057b302;
  }
  L0057b2ed: { trace_pc=0x0057b2edu; // 0x57b2ed: dd442458 FLD double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load64(read64(m,address));
  }
  L0057b2f1: { trace_pc=0x0057b2f1u; // 0x57b2f1: dc442460 FADD double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.add64(read64(m,address));
  }
  L0057b2f5: { trace_pc=0x0057b2f5u; // 0x57b2f5: dc1d180f7900 FCOMP double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b2fb: { trace_pc=0x0057b2fbu; // 0x57b2fb: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b2fd: { trace_pc=0x0057b2fdu; // 0x57b2fd: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057b300: { trace_pc=0x0057b300u; // 0x57b300: 741e JZ 0x0057b320
    if(integer::condition("JZ",flags)) goto L0057b320;
  }
  L0057b302: { trace_pc=0x0057b302u; // 0x57b302: dd442448 FLD double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load64(read64(m,address));
  }
  L0057b306: { trace_pc=0x0057b306u; // 0x57b306: dc25180f7900 FSUB double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.subtract64(read64(m,address));
  }
  L0057b30c: { trace_pc=0x0057b30cu; // 0x57b30c: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b312: { trace_pc=0x0057b312u; // 0x57b312: dd542460 FST double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057b316: { trace_pc=0x0057b316u; // 0x57b316: dc05180f7900 FADD double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.add64(read64(m,address));
  }
  L0057b31c: { trace_pc=0x0057b31cu; // 0x57b31c: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b320: { trace_pc=0x0057b320u; // 0x57b320: b96879a500 MOV ECX,0xa57968
    s.cx = 0x00a57968u;
  }
  L0057b325: { trace_pc=0x0057b325u; // 0x57b325: e8f6b2ffff CALL 0x00576620
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576620u,5747498u); flags=s.arithmetic_flags;
  }
  L0057b32a: { trace_pc=0x0057b32au; // 0x57b32a: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b32e: { trace_pc=0x0057b32eu; // 0x57b32e: dc442458 FADD double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.add64(read64(m,address));
  }
  L0057b332: { trace_pc=0x0057b332u; // 0x57b332: dd542450 FST double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057b336: { trace_pc=0x0057b336u; // 0x57b336: dc1d180f7900 FCOMP double ptr [0x00790f18]
    const auto address=(0x00790f18u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b33c: { trace_pc=0x0057b33cu; // 0x57b33c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b33e: { trace_pc=0x0057b33eu; // 0x57b33e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057b341: { trace_pc=0x0057b341u; // 0x57b341: 75dd JNZ 0x0057b320
    if(integer::condition("JNZ",flags)) goto L0057b320;
  }
  L0057b343: { trace_pc=0x0057b343u; // 0x57b343: dd442450 FLD double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load64(read64(m,address));
  }
  L0057b347: { trace_pc=0x0057b347u; // 0x57b347: dc5c2448 FCOMP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0057b34b: { trace_pc=0x0057b34bu; // 0x57b34b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b34d: { trace_pc=0x0057b34du; // 0x57b34d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b350: { trace_pc=0x0057b350u; // 0x57b350: 74ce JZ 0x0057b320
    if(integer::condition("JZ",flags)) goto L0057b320;
  }
  L0057b352: { trace_pc=0x0057b352u; // 0x57b352: dd442450 FLD double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load64(read64(m,address));
  }
  L0057b356: { trace_pc=0x0057b356u; // 0x57b356: e8f5f61e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5747547u); flags=s.arithmetic_flags;
  }
  L0057b35b: { trace_pc=0x0057b35bu; // 0x57b35b: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b35d: { trace_pc=0x0057b35du; // 0x57b35d: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0057b361: { trace_pc=0x0057b361u; // 0x57b361: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b363: { trace_pc=0x0057b363u; // 0x57b363: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057b365: { trace_pc=0x0057b365u; // 0x57b365: 7c0e JL 0x0057b375
    if(integer::condition("JL",flags)) goto L0057b375;
  }
  L0057b367: { trace_pc=0x0057b367u; // 0x57b367: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057b36a: { trace_pc=0x0057b36au; // 0x57b36a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057b36b: { trace_pc=0x0057b36bu; // 0x57b36b: 895c82fc MOV dword ptr [EDX + EAX*0x4 + -0x4],EBX
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.bx);
  }
  L0057b36f: { trace_pc=0x0057b36fu; // 0x57b36f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b371: { trace_pc=0x0057b371u; // 0x57b371: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057b373: { trace_pc=0x0057b373u; // 0x57b373: 7ef2 JLE 0x0057b367
    if(integer::condition("JLE",flags)) goto L0057b367;
  }
  L0057b375: { trace_pc=0x0057b375u; // 0x57b375: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0057b379: { trace_pc=0x0057b379u; // 0x57b379: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L0057b37b: { trace_pc=0x0057b37bu; // 0x57b37b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0057b37f: { trace_pc=0x0057b37fu; // 0x57b37f: c744243401000000 MOV dword ptr [ESP + 0x34],0x1
    m.w32((f.sp+0x00000034u), 0x00000001u);
  }
  L0057b387: { trace_pc=0x0057b387u; // 0x57b387: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0057b389: { trace_pc=0x0057b389u; // 0x57b389: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L0057b38c: { trace_pc=0x0057b38cu; // 0x57b38c: 0fbf44241a MOVSX EAX,word ptr [ESP + 0x1a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001au)),16));
  }
  L0057b391: { trace_pc=0x0057b391u; // 0x57b391: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b398: { trace_pc=0x0057b398u; // 0x57b398: 0fbf4c2418 MOVSX ECX,word ptr [ESP + 0x18]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  L0057b39d: { trace_pc=0x0057b39du; // 0x57b39d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057b39f: { trace_pc=0x0057b39fu; // 0x57b39f: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b3a2: { trace_pc=0x0057b3a2u; // 0x57b3a2: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0057b3a6: { trace_pc=0x0057b3a6u; // 0x57b3a6: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b3a9: { trace_pc=0x0057b3a9u; // 0x57b3a9: 8b8808030000 MOV ECX,dword ptr [EAX + 0x308]
    s.cx = m.r32((s.ax+0x00000308u));
  }
  L0057b3af: { trace_pc=0x0057b3afu; // 0x57b3af: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0057b3b4: { trace_pc=0x0057b3b4u; // 0x57b3b4: 894c023c MOV dword ptr [EDX + EAX*0x1 + 0x3c],ECX
    m.w32((s.dx+(s.ax * 0x00000001u)+0x0000003cu), s.cx);
  }
  L0057b3b8: { trace_pc=0x0057b3b8u; // 0x57b3b8: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b3ba: { trace_pc=0x0057b3bau; // 0x57b3ba: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0057b3bd: { trace_pc=0x0057b3bdu; // 0x57b3bd: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b3be: { trace_pc=0x0057b3beu; // 0x57b3be: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057b3c0: { trace_pc=0x0057b3c0u; // 0x57b3c0: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0057b3c4: { trace_pc=0x0057b3c4u; // 0x57b3c4: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0057b3c7: { trace_pc=0x0057b3c7u; // 0x57b3c7: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b3c9: { trace_pc=0x0057b3c9u; // 0x57b3c9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b3cb: { trace_pc=0x0057b3cbu; // 0x57b3cb: 7345 JNC 0x0057b412
    if(integer::condition("JNC",flags)) goto L0057b412;
  }
  L0057b3cd: { trace_pc=0x0057b3cdu; // 0x57b3cd: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b3d0: { trace_pc=0x0057b3d0u; // 0x57b3d0: 7623 JBE 0x0057b3f5
    if(integer::condition("JBE",flags)) goto L0057b3f5;
  }
  L0057b3d2: { trace_pc=0x0057b3d2u; // 0x57b3d2: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L0057b3d5: { trace_pc=0x0057b3d5u; // 0x57b3d5: 8b0493 MOV EAX,dword ptr [EBX + EDX*0x4]
    s.ax = m.r32((s.bx+(s.dx * 0x00000004u)));
  }
  L0057b3d8: { trace_pc=0x0057b3d8u; // 0x57b3d8: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0057b3db: { trace_pc=0x0057b3dbu; // 0x57b3db: d85c2450 FCOMP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0057b3df: { trace_pc=0x0057b3dfu; // 0x57b3df: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b3e1: { trace_pc=0x0057b3e1u; // 0x57b3e1: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b3e4: { trace_pc=0x0057b3e4u; // 0x57b3e4: 750f JNZ 0x0057b3f5
    if(integer::condition("JNZ",flags)) goto L0057b3f5;
  }
  L0057b3e6: { trace_pc=0x0057b3e6u; // 0x57b3e6: 8b0493 MOV EAX,dword ptr [EBX + EDX*0x4]
    s.ax = m.r32((s.bx+(s.dx * 0x00000004u)));
  }
  L0057b3e9: { trace_pc=0x0057b3e9u; // 0x57b3e9: 89048b MOV dword ptr [EBX + ECX*0x4],EAX
    m.w32((s.bx+(s.cx * 0x00000004u)), s.ax);
  }
  L0057b3ec: { trace_pc=0x0057b3ecu; // 0x57b3ec: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057b3ee: { trace_pc=0x0057b3eeu; // 0x57b3ee: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b3f0: { trace_pc=0x0057b3f0u; // 0x57b3f0: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b3f3: { trace_pc=0x0057b3f3u; // 0x57b3f3: 77dd JA 0x0057b3d2
    if(integer::condition("JA",flags)) goto L0057b3d2;
  }
  L0057b3f5: { trace_pc=0x0057b3f5u; // 0x57b3f5: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057b3f8: { trace_pc=0x0057b3f8u; // 0x57b3f8: 893c8a MOV dword ptr [EDX + ECX*0x4],EDI
    m.w32((s.dx+(s.cx * 0x00000004u)), s.di);
  }
  L0057b3fb: { trace_pc=0x0057b3fbu; // 0x57b3fb: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b3fd: { trace_pc=0x0057b3fdu; // 0x57b3fd: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0057b400: { trace_pc=0x0057b400u; // 0x57b400: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b401: { trace_pc=0x0057b401u; // 0x57b401: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0057b403: { trace_pc=0x0057b403u; // 0x57b403: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b405: { trace_pc=0x0057b405u; // 0x57b405: 7603 JBE 0x0057b40a
    if(integer::condition("JBE",flags)) goto L0057b40a;
  }
  L0057b407: { trace_pc=0x0057b407u; // 0x57b407: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0057b40a: { trace_pc=0x0057b40au; // 0x57b40a: 3b7e10 CMP EDI,dword ptr [ESI + 0x10]
    (void)integer::sub(s.di,m.r32((s.si+0x00000010u)),32,flags);
  }
  L0057b40d: { trace_pc=0x0057b40du; // 0x57b40d: 7303 JNC 0x0057b412
    if(integer::condition("JNC",flags)) goto L0057b412;
  }
  L0057b40f: { trace_pc=0x0057b40fu; // 0x57b40f: 897e10 MOV dword ptr [ESI + 0x10],EDI
    m.w32((s.si+0x00000010u), s.di);
  }
  L0057b412: { trace_pc=0x0057b412u; // 0x57b412: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b414: { trace_pc=0x0057b414u; // 0x57b414: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b416: { trace_pc=0x0057b416u; // 0x57b416: 7428 JZ 0x0057b440
    if(integer::condition("JZ",flags)) goto L0057b440;
  }
  L0057b418: { trace_pc=0x0057b418u; // 0x57b418: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b41b: { trace_pc=0x0057b41bu; // 0x57b41b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b41d: { trace_pc=0x0057b41du; // 0x57b41d: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b420: { trace_pc=0x0057b420u; // 0x57b420: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b423: { trace_pc=0x0057b423u; // 0x57b423: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057b426: { trace_pc=0x0057b426u; // 0x57b426: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b428: { trace_pc=0x0057b428u; // 0x57b428: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b42b: { trace_pc=0x0057b42bu; // 0x57b42b: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057b432: { trace_pc=0x0057b432u; // 0x57b432: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b434: { trace_pc=0x0057b434u; // 0x57b434: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b435: { trace_pc=0x0057b435u; // 0x57b435: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b437: { trace_pc=0x0057b437u; // 0x57b437: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b439: { trace_pc=0x0057b439u; // 0x57b439: e8520a0100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5747774u); flags=s.arithmetic_flags;
  }
  L0057b43e: { trace_pc=0x0057b43eu; // 0x57b43e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b440: { trace_pc=0x0057b440u; // 0x57b440: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0057b444: { trace_pc=0x0057b444u; // 0x57b444: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0057b448: { trace_pc=0x0057b448u; // 0x57b448: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b44a: { trace_pc=0x0057b44au; // 0x57b44a: 0f8edd020000 JLE 0x0057b72d
    if(integer::condition("JLE",flags)) goto L0057b72d;
  }
  L0057b450: { trace_pc=0x0057b450u; // 0x57b450: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b456: { trace_pc=0x0057b456u; // 0x57b456: eb0a JMP 0x0057b462
    goto L0057b462;
  }
  L0057b458: { trace_pc=0x0057b458u; // 0x57b458: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b45e: { trace_pc=0x0057b45eu; // 0x57b45e: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0057b462: { trace_pc=0x0057b462u; // 0x57b462: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b464: { trace_pc=0x0057b464u; // 0x57b464: 0f84c3020000 JZ 0x0057b72d
    if(integer::condition("JZ",flags)) goto L0057b72d;
  }
  L0057b46a: { trace_pc=0x0057b46au; // 0x57b46a: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0057b46e: { trace_pc=0x0057b46eu; // 0x57b46e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b470: { trace_pc=0x0057b470u; // 0x57b470: 0f84b7020000 JZ 0x0057b72d
    if(integer::condition("JZ",flags)) goto L0057b72d;
  }
  L0057b476: { trace_pc=0x0057b476u; // 0x57b476: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057b478: { trace_pc=0x0057b478u; // 0x57b478: 7424 JZ 0x0057b49e
    if(integer::condition("JZ",flags)) goto L0057b49e;
  }
  L0057b47a: { trace_pc=0x0057b47au; // 0x57b47a: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0057b47e: { trace_pc=0x0057b47eu; // 0x57b47e: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b485: { trace_pc=0x0057b485u; // 0x57b485: 0fbf39 MOVSX EDI,word ptr [ECX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0057b488: { trace_pc=0x0057b488u; // 0x57b488: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0057b48a: { trace_pc=0x0057b48au; // 0x57b48a: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b48e: { trace_pc=0x0057b48eu; // 0x57b48e: 8bbf08030000 MOV EDI,dword ptr [EDI + 0x308]
    s.di = m.r32((s.di+0x00000308u));
  }
  L0057b494: { trace_pc=0x0057b494u; // 0x57b494: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b497: { trace_pc=0x0057b497u; // 0x57b497: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b49a: { trace_pc=0x0057b49au; // 0x57b49a: 897c1038 MOV dword ptr [EAX + EDX*0x1 + 0x38],EDI
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000038u), s.di);
  }
  L0057b49e: { trace_pc=0x0057b49eu; // 0x57b49e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b49f: { trace_pc=0x0057b49fu; // 0x57b49f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b4a4: { trace_pc=0x0057b4a4u; // 0x57b4a4: e857a0fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5747881u); flags=s.arithmetic_flags;
  }
  L0057b4a9: { trace_pc=0x0057b4a9u; // 0x57b4a9: 8b0db8a1a300 MOV ECX,dword ptr [0x00a3a1b8]
    s.cx = m.r32((0x00a3a1b8u));
  }
  L0057b4af: { trace_pc=0x0057b4afu; // 0x57b4af: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0057b4b3: { trace_pc=0x0057b4b3u; // 0x57b4b3: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0057b4b6: { trace_pc=0x0057b4b6u; // 0x57b4b6: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0057b4bd: { trace_pc=0x0057b4bdu; // 0x57b4bd: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0057b4c1: { trace_pc=0x0057b4c1u; // 0x57b4c1: c744243c00000000 MOV dword ptr [ESP + 0x3c],0x0
    m.w32((f.sp+0x0000003cu), 0x00000000u);
  }
  L0057b4c9: { trace_pc=0x0057b4c9u; // 0x57b4c9: 8d1cc2 LEA EBX,[EDX + EAX*0x8]
    s.bx = (s.dx+(s.ax * 0x00000008u));
  }
  L0057b4cc: { trace_pc=0x0057b4ccu; // 0x57b4cc: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0057b4d0: { trace_pc=0x0057b4d0u; // 0x57b4d0: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0057b4d4: { trace_pc=0x0057b4d4u; // 0x57b4d4: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L0057b4d7: { trace_pc=0x0057b4d7u; // 0x57b4d7: 8b3d3486a500 MOV EDI,dword ptr [0x00a58634]
    s.di = m.r32((0x00a58634u));
  }
  L0057b4dd: { trace_pc=0x0057b4ddu; // 0x57b4dd: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L0057b4e0: { trace_pc=0x0057b4e0u; // 0x57b4e0: 6603048da09d8300 ADD AX,word ptr [ECX*0x4 + 0x839da0]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16(((s.cx * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L0057b4e8: { trace_pc=0x0057b4e8u; // 0x57b4e8: 8d0c8da09d8300 LEA ECX,[ECX*0x4 + 0x839da0]
    s.cx = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  L0057b4ef: { trace_pc=0x0057b4efu; // 0x57b4ef: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L0057b4f3: { trace_pc=0x0057b4f3u; // 0x57b4f3: 6689442448 MOV word ptr [ESP + 0x48],AX
    m.w16((f.sp+0x00000048u), (s.ax & 0xffffu));
  }
  L0057b4f8: { trace_pc=0x0057b4f8u; // 0x57b4f8: 66034a02 ADD CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L0057b4fc: { trace_pc=0x0057b4fcu; // 0x57b4fc: 66894c244a MOV word ptr [ESP + 0x4a],CX
    m.w16((f.sp+0x0000004au), (s.cx & 0xffffu));
  }
  L0057b501: { trace_pc=0x0057b501u; // 0x57b501: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0057b505: { trace_pc=0x0057b505u; // 0x57b505: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0057b509: { trace_pc=0x0057b509u; // 0x57b509: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057b50c: { trace_pc=0x0057b50cu; // 0x57b50c: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057b50f: { trace_pc=0x0057b50fu; // 0x57b50f: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L0057b512: { trace_pc=0x0057b512u; // 0x57b512: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057b514: { trace_pc=0x0057b514u; // 0x57b514: 0f8eb0010000 JLE 0x0057b6ca
    if(integer::condition("JLE",flags)) goto L0057b6ca;
  }
  L0057b51a: { trace_pc=0x0057b51au; // 0x57b51a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0057b51c: { trace_pc=0x0057b51cu; // 0x57b51c: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0057b51e: { trace_pc=0x0057b51eu; // 0x57b51e: 3b3d3486a500 CMP EDI,dword ptr [0x00a58634]
    (void)integer::sub(s.di,m.r32((0x00a58634u)),32,flags);
  }
  L0057b524: { trace_pc=0x0057b524u; // 0x57b524: 0f8da0010000 JGE 0x0057b6ca
    if(integer::condition("JGE",flags)) goto L0057b6ca;
  }
  L0057b52a: { trace_pc=0x0057b52au; // 0x57b52a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0057b52c: { trace_pc=0x0057b52cu; // 0x57b52c: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0057b52e: { trace_pc=0x0057b52eu; // 0x57b52e: 3b3d3486a500 CMP EDI,dword ptr [0x00a58634]
    (void)integer::sub(s.di,m.r32((0x00a58634u)),32,flags);
  }
  L0057b534: { trace_pc=0x0057b534u; // 0x57b534: 0f8d90010000 JGE 0x0057b6ca
    if(integer::condition("JGE",flags)) goto L0057b6ca;
  }
  L0057b53a: { trace_pc=0x0057b53au; // 0x57b53a: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L0057b540: { trace_pc=0x0057b540u; // 0x57b540: 0f8f84010000 JG 0x0057b6ca
    if(integer::condition("JG",flags)) goto L0057b6ca;
  }
  L0057b546: { trace_pc=0x0057b546u; // 0x57b546: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b54d: { trace_pc=0x0057b54du; // 0x57b54d: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b553: { trace_pc=0x0057b553u; // 0x57b553: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b555: { trace_pc=0x0057b555u; // 0x57b555: 8d3c80 LEA EDI,[EAX + EAX*0x4]
    s.di = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b558: { trace_pc=0x0057b558u; // 0x57b558: c1e704 SHL EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b55b: { trace_pc=0x0057b55bu; // 0x57b55b: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0057b55d: { trace_pc=0x0057b55du; // 0x57b55d: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057b560: { trace_pc=0x0057b560u; // 0x57b560: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b562: { trace_pc=0x0057b562u; // 0x57b562: 0f854a010000 JNZ 0x0057b6b2
    if(integer::condition("JNZ",flags)) goto L0057b6b2;
  }
  L0057b568: { trace_pc=0x0057b568u; // 0x57b568: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057b56c: { trace_pc=0x0057b56cu; // 0x57b56c: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  L0057b56f: { trace_pc=0x0057b56fu; // 0x57b56f: 3b8108030000 CMP EAX,dword ptr [ECX + 0x308]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000308u)),32,flags);
  }
  L0057b575: { trace_pc=0x0057b575u; // 0x57b575: 0f8437010000 JZ 0x0057b6b2
    if(integer::condition("JZ",flags)) goto L0057b6b2;
  }
  L0057b57b: { trace_pc=0x0057b57bu; // 0x57b57b: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0057b57f: { trace_pc=0x0057b57fu; // 0x57b57f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b584: { trace_pc=0x0057b584u; // 0x57b584: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0057b585: { trace_pc=0x0057b585u; // 0x57b585: e8769ffcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5748106u); flags=s.arithmetic_flags;
  }
  L0057b58a: { trace_pc=0x0057b58au; // 0x57b58a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057b58c: { trace_pc=0x0057b58cu; // 0x57b58c: e8fffbefff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5748113u); flags=s.arithmetic_flags;
  }
  L0057b591: { trace_pc=0x0057b591u; // 0x57b591: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b593: { trace_pc=0x0057b593u; // 0x57b593: 0f8419010000 JZ 0x0057b6b2
    if(integer::condition("JZ",flags)) goto L0057b6b2;
  }
  L0057b599: { trace_pc=0x0057b599u; // 0x57b599: 8a4744 MOV AL,byte ptr [EDI + 0x44]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000044u)));
  }
  L0057b59c: { trace_pc=0x0057b59cu; // 0x57b59c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b59e: { trace_pc=0x0057b59eu; // 0x57b59e: 0f840e010000 JZ 0x0057b6b2
    if(integer::condition("JZ",flags)) goto L0057b6b2;
  }
  L0057b5a4: { trace_pc=0x0057b5a4u; // 0x57b5a4: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0057b5a8: { trace_pc=0x0057b5a8u; // 0x57b5a8: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057b5ab: { trace_pc=0x0057b5abu; // 0x57b5ab: 0fbf542436 MOVSX EDX,word ptr [ESP + 0x36]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000036u)),16));
  }
  L0057b5b0: { trace_pc=0x0057b5b0u; // 0x57b5b0: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0057b5b2: { trace_pc=0x0057b5b2u; // 0x57b5b2: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057b5b5: { trace_pc=0x0057b5b5u; // 0x57b5b5: 0fbf442420 MOVSX EAX,word ptr [ESP + 0x20]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000020u)),16));
  }
  L0057b5ba: { trace_pc=0x0057b5bau; // 0x57b5ba: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0057b5bc: { trace_pc=0x0057b5bcu; // 0x57b5bc: 0fbf4c2422 MOVSX ECX,word ptr [ESP + 0x22]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000022u)),16));
  }
  L0057b5c1: { trace_pc=0x0057b5c1u; // 0x57b5c1: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0057b5c3: { trace_pc=0x0057b5c3u; // 0x57b5c3: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057b5c5: { trace_pc=0x0057b5c5u; // 0x57b5c5: 0fafd1 IMUL EDX,ECX
    s.dx = integer::imul(s.dx,s.cx,32,flags);
  }
  L0057b5c8: { trace_pc=0x0057b5c8u; // 0x57b5c8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057b5ca: { trace_pc=0x0057b5cau; // 0x57b5ca: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  L0057b5cd: { trace_pc=0x0057b5cdu; // 0x57b5cd: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0057b5cf: { trace_pc=0x0057b5cfu; // 0x57b5cf: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0057b5d3: { trace_pc=0x0057b5d3u; // 0x57b5d3: db442458 FILD dword ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b5d7: { trace_pc=0x0057b5d7u; // 0x57b5d7: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057b5da: { trace_pc=0x0057b5dau; // 0x57b5da: e8a1eaf3ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5748191u); flags=s.arithmetic_flags;
  }
  L0057b5df: { trace_pc=0x0057b5dfu; // 0x57b5df: d95c2458 FSTP float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0057b5e3: { trace_pc=0x0057b5e3u; // 0x57b5e3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057b5e6: { trace_pc=0x0057b5e6u; // 0x57b5e6: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057b5eb: { trace_pc=0x0057b5ebu; // 0x57b5eb: e8f0470b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5748208u); flags=s.arithmetic_flags;
  }
  L0057b5f0: { trace_pc=0x0057b5f0u; // 0x57b5f0: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L0057b5f4: { trace_pc=0x0057b5f4u; // 0x57b5f4: c744246c00000000 MOV dword ptr [ESP + 0x6c],0x0
    m.w32((f.sp+0x0000006cu), 0x00000000u);
  }
  L0057b5fc: { trace_pc=0x0057b5fcu; // 0x57b5fc: df6c2468 FILD qword ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057b600: { trace_pc=0x0057b600u; // 0x57b600: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0057b604: { trace_pc=0x0057b604u; // 0x57b604: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0057b608: { trace_pc=0x0057b608u; // 0x57b608: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b609: { trace_pc=0x0057b609u; // 0x57b609: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057b60f: { trace_pc=0x0057b60fu; // 0x57b60f: d905800c7900 FLD float ptr [0x00790c80]
    const auto address=(0x00790c80u);
    s.fp.load32(m.r32(address));
  }
  L0057b615: { trace_pc=0x0057b615u; // 0x57b615: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0057b619: { trace_pc=0x0057b619u; // 0x57b619: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0057b61b: { trace_pc=0x0057b61bu; // 0x57b61b: d9442450 FLD float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L0057b61f: { trace_pc=0x0057b61fu; // 0x57b61f: d80d7c0c7900 FMUL float ptr [0x00790c7c]
    const auto address=(0x00790c7cu);
    s.fp.multiply32(m.r32(address));
  }
  L0057b625: { trace_pc=0x0057b625u; // 0x57b625: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057b627: { trace_pc=0x0057b627u; // 0x57b627: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0057b62b: { trace_pc=0x0057b62bu; // 0x57b62b: d80d840c7900 FMUL float ptr [0x00790c84]
    const auto address=(0x00790c84u);
    s.fp.multiply32(m.r32(address));
  }
  L0057b631: { trace_pc=0x0057b631u; // 0x57b631: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0057b633: { trace_pc=0x0057b633u; // 0x57b633: d95b04 FSTP float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0057b636: { trace_pc=0x0057b636u; // 0x57b636: 8b8208030000 MOV EAX,dword ptr [EDX + 0x308]
    s.ax = m.r32((s.dx+0x00000308u));
  }
  L0057b63c: { trace_pc=0x0057b63cu; // 0x57b63c: 89473c MOV dword ptr [EDI + 0x3c],EAX
    m.w32((s.di+0x0000003cu), s.ax);
  }
  L0057b63f: { trace_pc=0x0057b63fu; // 0x57b63f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b641: { trace_pc=0x0057b641u; // 0x57b641: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0057b643: { trace_pc=0x0057b643u; // 0x57b643: 83c308 ADD EBX,0x8
    s.bx = integer::add(s.bx,0x00000008u,32,flags);
  }
  L0057b646: { trace_pc=0x0057b646u; // 0x57b646: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b647: { trace_pc=0x0057b647u; // 0x57b647: 895c2450 MOV dword ptr [ESP + 0x50],EBX
    m.w32((f.sp+0x00000050u), s.bx);
  }
  L0057b64b: { trace_pc=0x0057b64bu; // 0x57b64b: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0057b64e: { trace_pc=0x0057b64eu; // 0x57b64e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057b650: { trace_pc=0x0057b650u; // 0x57b650: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0057b654: { trace_pc=0x0057b654u; // 0x57b654: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0057b657: { trace_pc=0x0057b657u; // 0x57b657: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b659: { trace_pc=0x0057b659u; // 0x57b659: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b65b: { trace_pc=0x0057b65bu; // 0x57b65b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057b65d: { trace_pc=0x0057b65du; // 0x57b65d: 736b JNC 0x0057b6ca
    if(integer::condition("JNC",flags)) goto L0057b6ca;
  }
  L0057b65f: { trace_pc=0x0057b65fu; // 0x57b65f: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b662: { trace_pc=0x0057b662u; // 0x57b662: 762f JBE 0x0057b693
    if(integer::condition("JBE",flags)) goto L0057b693;
  }
  L0057b664: { trace_pc=0x0057b664u; // 0x57b664: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b667: { trace_pc=0x0057b667u; // 0x57b667: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0057b66a: { trace_pc=0x0057b66au; // 0x57b66a: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0057b66e: { trace_pc=0x0057b66eu; // 0x57b66e: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0057b671: { trace_pc=0x0057b671u; // 0x57b671: d85c2458 FCOMP float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0057b675: { trace_pc=0x0057b675u; // 0x57b675: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057b677: { trace_pc=0x0057b677u; // 0x57b677: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057b67a: { trace_pc=0x0057b67au; // 0x57b67a: 7517 JNZ 0x0057b693
    if(integer::condition("JNZ",flags)) goto L0057b693;
  }
  L0057b67c: { trace_pc=0x0057b67cu; // 0x57b67c: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b67f: { trace_pc=0x0057b67fu; // 0x57b67f: 8b5c2460 MOV EBX,dword ptr [ESP + 0x60]
    s.bx = m.r32((f.sp+0x00000060u));
  }
  L0057b683: { trace_pc=0x0057b683u; // 0x57b683: 891c88 MOV dword ptr [EAX + ECX*0x4],EBX
    m.w32((s.ax+(s.cx * 0x00000004u)), s.bx);
  }
  L0057b686: { trace_pc=0x0057b686u; // 0x57b686: 8b5c2450 MOV EBX,dword ptr [ESP + 0x50]
    s.bx = m.r32((f.sp+0x00000050u));
  }
  L0057b68a: { trace_pc=0x0057b68au; // 0x57b68a: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057b68c: { trace_pc=0x0057b68cu; // 0x57b68c: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057b68e: { trace_pc=0x0057b68eu; // 0x57b68e: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057b691: { trace_pc=0x0057b691u; // 0x57b691: 77d1 JA 0x0057b664
    if(integer::condition("JA",flags)) goto L0057b664;
  }
  L0057b693: { trace_pc=0x0057b693u; // 0x57b693: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057b696: { trace_pc=0x0057b696u; // 0x57b696: 893c8a MOV dword ptr [EDX + ECX*0x4],EDI
    m.w32((s.dx+(s.cx * 0x00000004u)), s.di);
  }
  L0057b699: { trace_pc=0x0057b699u; // 0x57b699: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b69b: { trace_pc=0x0057b69bu; // 0x57b69b: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0057b69e: { trace_pc=0x0057b69eu; // 0x57b69e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b69f: { trace_pc=0x0057b69fu; // 0x57b69f: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0057b6a1: { trace_pc=0x0057b6a1u; // 0x57b6a1: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b6a3: { trace_pc=0x0057b6a3u; // 0x57b6a3: 7603 JBE 0x0057b6a8
    if(integer::condition("JBE",flags)) goto L0057b6a8;
  }
  L0057b6a5: { trace_pc=0x0057b6a5u; // 0x57b6a5: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0057b6a8: { trace_pc=0x0057b6a8u; // 0x57b6a8: 3b7e10 CMP EDI,dword ptr [ESI + 0x10]
    (void)integer::sub(s.di,m.r32((s.si+0x00000010u)),32,flags);
  }
  L0057b6ab: { trace_pc=0x0057b6abu; // 0x57b6ab: 731d JNC 0x0057b6ca
    if(integer::condition("JNC",flags)) goto L0057b6ca;
  }
  L0057b6ad: { trace_pc=0x0057b6adu; // 0x57b6ad: 897e10 MOV dword ptr [ESI + 0x10],EDI
    m.w32((s.si+0x00000010u), s.di);
  }
  L0057b6b0: { trace_pc=0x0057b6b0u; // 0x57b6b0: eb18 JMP 0x0057b6ca
    goto L0057b6ca;
  }
  L0057b6b2: { trace_pc=0x0057b6b2u; // 0x57b6b2: 8b7f38 MOV EDI,dword ptr [EDI + 0x38]
    s.di = m.r32((s.di+0x00000038u));
  }
  L0057b6b5: { trace_pc=0x0057b6b5u; // 0x57b6b5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b6b7: { trace_pc=0x0057b6b7u; // 0x57b6b7: 7411 JZ 0x0057b6ca
    if(integer::condition("JZ",flags)) goto L0057b6ca;
  }
  L0057b6b9: { trace_pc=0x0057b6b9u; // 0x57b6b9: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0057b6bd: { trace_pc=0x0057b6bdu; // 0x57b6bd: 3bb808030000 CMP EDI,dword ptr [EAX + 0x308]
    (void)integer::sub(s.di,m.r32((s.ax+0x00000308u)),32,flags);
  }
  L0057b6c3: { trace_pc=0x0057b6c3u; // 0x57b6c3: 7405 JZ 0x0057b6ca
    if(integer::condition("JZ",flags)) goto L0057b6ca;
  }
  L0057b6c5: { trace_pc=0x0057b6c5u; // 0x57b6c5: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0057b6ca: { trace_pc=0x0057b6cau; // 0x57b6ca: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0057b6ce: { trace_pc=0x0057b6ceu; // 0x57b6ce: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L0057b6d1: { trace_pc=0x0057b6d1u; // 0x57b6d1: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0057b6d4: { trace_pc=0x0057b6d4u; // 0x57b6d4: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0057b6d8: { trace_pc=0x0057b6d8u; // 0x57b6d8: 0f8ceefdffff JL 0x0057b4cc
    if(integer::condition("JL",flags)) goto L0057b4cc;
  }
  L0057b6de: { trace_pc=0x0057b6deu; // 0x57b6de: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b6e2: { trace_pc=0x0057b6e2u; // 0x57b6e2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b6e3: { trace_pc=0x0057b6e3u; // 0x57b6e3: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0057b6e7: { trace_pc=0x0057b6e7u; // 0x57b6e7: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b6e9: { trace_pc=0x0057b6e9u; // 0x57b6e9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b6eb: { trace_pc=0x0057b6ebu; // 0x57b6eb: 7506 JNZ 0x0057b6f3
    if(integer::condition("JNZ",flags)) goto L0057b6f3;
  }
  L0057b6ed: { trace_pc=0x0057b6edu; // 0x57b6ed: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0057b6f1: { trace_pc=0x0057b6f1u; // 0x57b6f1: eb2a JMP 0x0057b71d
    goto L0057b71d;
  }
  L0057b6f3: { trace_pc=0x0057b6f3u; // 0x57b6f3: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b6f6: { trace_pc=0x0057b6f6u; // 0x57b6f6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b6f8: { trace_pc=0x0057b6f8u; // 0x57b6f8: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b6fb: { trace_pc=0x0057b6fbu; // 0x57b6fb: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b6fe: { trace_pc=0x0057b6feu; // 0x57b6fe: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057b701: { trace_pc=0x0057b701u; // 0x57b701: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b703: { trace_pc=0x0057b703u; // 0x57b703: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b706: { trace_pc=0x0057b706u; // 0x57b706: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057b70d: { trace_pc=0x0057b70du; // 0x57b70d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b70f: { trace_pc=0x0057b70fu; // 0x57b70f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b710: { trace_pc=0x0057b710u; // 0x57b710: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b712: { trace_pc=0x0057b712u; // 0x57b712: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b714: { trace_pc=0x0057b714u; // 0x57b714: e877070100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5748505u); flags=s.arithmetic_flags;
  }
  L0057b719: { trace_pc=0x0057b719u; // 0x57b719: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L0057b71d: { trace_pc=0x0057b71du; // 0x57b71d: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b721: { trace_pc=0x0057b721u; // 0x57b721: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0057b725: { trace_pc=0x0057b725u; // 0x57b725: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b727: { trace_pc=0x0057b727u; // 0x57b727: 0f8c2bfdffff JL 0x0057b458
    if(integer::condition("JL",flags)) goto L0057b458;
  }
  L0057b72d: { trace_pc=0x0057b72du; // 0x57b72d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b72f: { trace_pc=0x0057b72fu; // 0x57b72f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b731: { trace_pc=0x0057b731u; // 0x57b731: 0f84e2000000 JZ 0x0057b819
    if(integer::condition("JZ",flags)) goto L0057b819;
  }
  L0057b737: { trace_pc=0x0057b737u; // 0x57b737: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b73a: { trace_pc=0x0057b73au; // 0x57b73a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b73c: { trace_pc=0x0057b73cu; // 0x57b73c: 8b1488 MOV EDX,dword ptr [EAX + ECX*0x4]
    s.dx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b73f: { trace_pc=0x0057b73fu; // 0x57b73f: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b742: { trace_pc=0x0057b742u; // 0x57b742: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0057b745: { trace_pc=0x0057b745u; // 0x57b745: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0057b747: { trace_pc=0x0057b747u; // 0x57b747: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0057b74a: { trace_pc=0x0057b74au; // 0x57b74a: c7048100000000 MOV dword ptr [ECX + EAX*0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L0057b751: { trace_pc=0x0057b751u; // 0x57b751: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b753: { trace_pc=0x0057b753u; // 0x57b753: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0057b754: { trace_pc=0x0057b754u; // 0x57b754: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b756: { trace_pc=0x0057b756u; // 0x57b756: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0057b758: { trace_pc=0x0057b758u; // 0x57b758: e833070100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5748573u); flags=s.arithmetic_flags;
  }
  L0057b75d: { trace_pc=0x0057b75du; // 0x57b75d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b75f: { trace_pc=0x0057b75fu; // 0x57b75f: 0f84b4000000 JZ 0x0057b819
    if(integer::condition("JZ",flags)) goto L0057b819;
  }
  L0057b765: { trace_pc=0x0057b765u; // 0x57b765: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0057b769: { trace_pc=0x0057b769u; // 0x57b769: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b76b: { trace_pc=0x0057b76bu; // 0x57b76b: 0f8405010000 JZ 0x0057b876
    if(integer::condition("JZ",flags)) goto L0057b876;
  }
  L0057b771: { trace_pc=0x0057b771u; // 0x57b771: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057b772: { trace_pc=0x0057b772u; // 0x57b772: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b777: { trace_pc=0x0057b777u; // 0x57b777: e8849dfcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5748604u); flags=s.arithmetic_flags;
  }
  L0057b77c: { trace_pc=0x0057b77cu; // 0x57b77c: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0057b77e: { trace_pc=0x0057b77eu; // 0x57b77e: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057b784: { trace_pc=0x0057b784u; // 0x57b784: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057b788: { trace_pc=0x0057b788u; // 0x57b788: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b78f: { trace_pc=0x0057b78fu; // 0x57b78f: 0fbf17 MOVSX EDX,word ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0057b792: { trace_pc=0x0057b792u; // 0x57b792: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b794: { trace_pc=0x0057b794u; // 0x57b794: 8d3c80 LEA EDI,[EAX + EAX*0x4]
    s.di = (s.ax+(s.ax * 0x00000004u));
  }
  L0057b797: { trace_pc=0x0057b797u; // 0x57b797: c1e704 SHL EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b79a: { trace_pc=0x0057b79au; // 0x57b79a: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0057b79c: { trace_pc=0x0057b79cu; // 0x57b79c: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057b79f: { trace_pc=0x0057b79fu; // 0x57b79f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b7a1: { trace_pc=0x0057b7a1u; // 0x57b7a1: 7530 JNZ 0x0057b7d3
    if(integer::condition("JNZ",flags)) goto L0057b7d3;
  }
  L0057b7a3: { trace_pc=0x0057b7a3u; // 0x57b7a3: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057b7a5: { trace_pc=0x0057b7a5u; // 0x57b7a5: e8e6f9efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5748650u); flags=s.arithmetic_flags;
  }
  L0057b7aa: { trace_pc=0x0057b7aau; // 0x57b7aa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b7ac: { trace_pc=0x0057b7acu; // 0x57b7ac: 7425 JZ 0x0057b7d3
    if(integer::condition("JZ",flags)) goto L0057b7d3;
  }
  L0057b7ae: { trace_pc=0x0057b7aeu; // 0x57b7ae: 8a4744 MOV AL,byte ptr [EDI + 0x44]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000044u)));
  }
  L0057b7b1: { trace_pc=0x0057b7b1u; // 0x57b7b1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b7b3: { trace_pc=0x0057b7b3u; // 0x57b7b3: 741e JZ 0x0057b7d3
    if(integer::condition("JZ",flags)) goto L0057b7d3;
  }
  L0057b7b5: { trace_pc=0x0057b7b5u; // 0x57b7b5: a1b8a1a300 MOV EAX,[0x00a3a1b8]
    s.ax = m.r32((0x00a3a1b8u));
  }
  L0057b7ba: { trace_pc=0x0057b7bau; // 0x57b7ba: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057b7be: { trace_pc=0x0057b7beu; // 0x57b7be: 894338 MOV dword ptr [EBX + 0x38],EAX
    m.w32((s.bx+0x00000038u), s.ax);
  }
  L0057b7c1: { trace_pc=0x0057b7c1u; // 0x57b7c1: c6831a01000000 MOV byte ptr [EBX + 0x11a],0x0
    m.w8((s.bx+0x0000011au), 0x00000000u);
  }
  L0057b7c8: { trace_pc=0x0057b7c8u; // 0x57b7c8: 8b9108030000 MOV EDX,dword ptr [ECX + 0x308]
    s.dx = m.r32((s.cx+0x00000308u));
  }
  L0057b7ce: { trace_pc=0x0057b7ceu; // 0x57b7ce: 895738 MOV dword ptr [EDI + 0x38],EDX
    m.w32((s.di+0x00000038u), s.dx);
  }
  L0057b7d1: { trace_pc=0x0057b7d1u; // 0x57b7d1: eb05 JMP 0x0057b7d8
    goto L0057b7d8;
  }
  L0057b7d3: { trace_pc=0x0057b7d3u; // 0x57b7d3: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0057b7d8: { trace_pc=0x0057b7d8u; // 0x57b7d8: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b7da: { trace_pc=0x0057b7dau; // 0x57b7da: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b7dc: { trace_pc=0x0057b7dcu; // 0x57b7dc: 7504 JNZ 0x0057b7e2
    if(integer::condition("JNZ",flags)) goto L0057b7e2;
  }
  L0057b7de: { trace_pc=0x0057b7deu; // 0x57b7de: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057b7e0: { trace_pc=0x0057b7e0u; // 0x57b7e0: eb26 JMP 0x0057b808
    goto L0057b808;
  }
  L0057b7e2: { trace_pc=0x0057b7e2u; // 0x57b7e2: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b7e5: { trace_pc=0x0057b7e5u; // 0x57b7e5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b7e7: { trace_pc=0x0057b7e7u; // 0x57b7e7: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057b7ea: { trace_pc=0x0057b7eau; // 0x57b7ea: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057b7ed: { trace_pc=0x0057b7edu; // 0x57b7ed: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057b7f0: { trace_pc=0x0057b7f0u; // 0x57b7f0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057b7f2: { trace_pc=0x0057b7f2u; // 0x57b7f2: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b7f5: { trace_pc=0x0057b7f5u; // 0x57b7f5: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057b7fc: { trace_pc=0x0057b7fcu; // 0x57b7fc: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057b7fe: { trace_pc=0x0057b7feu; // 0x57b7fe: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057b7ff: { trace_pc=0x0057b7ffu; // 0x57b7ff: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057b801: { trace_pc=0x0057b801u; // 0x57b801: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057b803: { trace_pc=0x0057b803u; // 0x57b803: e888060100 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5748744u); flags=s.arithmetic_flags;
  }
  L0057b808: { trace_pc=0x0057b808u; // 0x57b808: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b80c: { trace_pc=0x0057b80cu; // 0x57b80c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057b80d: { trace_pc=0x0057b80du; // 0x57b80d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057b80f: { trace_pc=0x0057b80fu; // 0x57b80f: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0057b813: { trace_pc=0x0057b813u; // 0x57b813: 0f854cffffff JNZ 0x0057b765
    if(integer::condition("JNZ",flags)) goto L0057b765;
  }
  L0057b819: { trace_pc=0x0057b819u; // 0x57b819: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0057b81d: { trace_pc=0x0057b81du; // 0x57b81d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b81f: { trace_pc=0x0057b81fu; // 0x57b81f: 7455 JZ 0x0057b876
    if(integer::condition("JZ",flags)) goto L0057b876;
  }
  L0057b821: { trace_pc=0x0057b821u; // 0x57b821: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057b825: { trace_pc=0x0057b825u; // 0x57b825: 83f94b CMP ECX,0x4b
    (void)integer::sub(s.cx,0x0000004bu,32,flags);
  }
  L0057b828: { trace_pc=0x0057b828u; // 0x57b828: 7e47 JLE 0x0057b871
    if(integer::condition("JLE",flags)) goto L0057b871;
  }
  L0057b82a: { trace_pc=0x0057b82au; // 0x57b82a: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0057b82e: { trace_pc=0x0057b82eu; // 0x57b82e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057b82f: { trace_pc=0x0057b82fu; // 0x57b82f: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0057b832: { trace_pc=0x0057b832u; // 0x57b832: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b834: { trace_pc=0x0057b834u; // 0x57b834: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L0057b837: { trace_pc=0x0057b837u; // 0x57b837: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057b839: { trace_pc=0x0057b839u; // 0x57b839: 7e36 JLE 0x0057b871
    if(integer::condition("JLE",flags)) goto L0057b871;
  }
  L0057b83b: { trace_pc=0x0057b83bu; // 0x57b83b: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0057b83e: { trace_pc=0x0057b83eu; // 0x57b83e: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0057b843: { trace_pc=0x0057b843u; // 0x57b843: 66833b00 CMP word ptr [EBX],0x0
    (void)integer::sub(m.r16((s.bx)),0x00000000u,16,flags);
  }
  L0057b847: { trace_pc=0x0057b847u; // 0x57b847: 757d JNZ 0x0057b8c6
    if(integer::condition("JNZ",flags)) goto L0057b8c6;
  }
  L0057b849: { trace_pc=0x0057b849u; // 0x57b849: 66837b0200 CMP word ptr [EBX + 0x2],0x0
    (void)integer::sub(m.r16((s.bx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b84e: { trace_pc=0x0057b84eu; // 0x57b84e: 7576 JNZ 0x0057b8c6
    if(integer::condition("JNZ",flags)) goto L0057b8c6;
  }
  L0057b850: { trace_pc=0x0057b850u; // 0x57b850: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b854: { trace_pc=0x0057b854u; // 0x57b854: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0057b856: { trace_pc=0x0057b856u; // 0x57b856: 8b8f08030000 MOV ECX,dword ptr [EDI + 0x308]
    s.cx = m.r32((s.di+0x00000308u));
  }
  L0057b85c: { trace_pc=0x0057b85cu; // 0x57b85c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b85d: { trace_pc=0x0057b85du; // 0x57b85d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b862: { trace_pc=0x0057b862u; // 0x57b862: e849d8fdff CALL 0x005590b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005590b0u,5748839u); flags=s.arithmetic_flags;
  }
  L0057b867: { trace_pc=0x0057b867u; // 0x57b867: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b869: { trace_pc=0x0057b869u; // 0x57b869: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L0057b86d: { trace_pc=0x0057b86du; // 0x57b86d: 740b JZ 0x0057b87a
    if(integer::condition("JZ",flags)) goto L0057b87a;
  }
  L0057b86f: { trace_pc=0x0057b86fu; // 0x57b86f: eb59 JMP 0x0057b8ca
    goto L0057b8ca;
  }
  L0057b871: { trace_pc=0x0057b871u; // 0x57b871: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0057b876: { trace_pc=0x0057b876u; // 0x57b876: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b87a: { trace_pc=0x0057b87au; // 0x57b87a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0057b87c: { trace_pc=0x0057b87cu; // 0x57b87c: 7412 JZ 0x0057b890
    if(integer::condition("JZ",flags)) goto L0057b890;
  }
  L0057b87e: { trace_pc=0x0057b87eu; // 0x57b87e: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057b881: { trace_pc=0x0057b881u; // 0x57b881: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057b882: { trace_pc=0x0057b882u; // 0x57b882: e8f41d1f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5748871u); flags=s.arithmetic_flags;
  }
  L0057b887: { trace_pc=0x0057b887u; // 0x57b887: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057b888: { trace_pc=0x0057b888u; // 0x57b888: e8ee1d1f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5748877u); flags=s.arithmetic_flags;
  }
  L0057b88d: { trace_pc=0x0057b88du; // 0x57b88d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057b890: { trace_pc=0x0057b890u; // 0x57b890: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0057b894: { trace_pc=0x0057b894u; // 0x57b894: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b895: { trace_pc=0x0057b895u; // 0x57b895: e8e11d1f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5748890u); flags=s.arithmetic_flags;
  }
  L0057b89a: { trace_pc=0x0057b89au; // 0x57b89a: 8a442417 MOV AL,byte ptr [ESP + 0x17]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000017u)));
  }
  L0057b89e: { trace_pc=0x0057b89eu; // 0x57b89e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057b8a1: { trace_pc=0x0057b8a1u; // 0x57b8a1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b8a3: { trace_pc=0x0057b8a3u; // 0x57b8a3: 0f84ed000000 JZ 0x0057b996
    if(integer::condition("JZ",flags)) goto L0057b996;
  }
  L0057b8a9: { trace_pc=0x0057b8a9u; // 0x57b8a9: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0057b8ad: { trace_pc=0x0057b8adu; // 0x57b8ad: 8b8704030000 MOV EAX,dword ptr [EDI + 0x304]
    s.ax = m.r32((s.di+0x00000304u));
  }
  L0057b8b3: { trace_pc=0x0057b8b3u; // 0x57b8b3: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057b8b5: { trace_pc=0x0057b8b5u; // 0x57b8b5: 898704030000 MOV dword ptr [EDI + 0x304],EAX
    m.w32((s.di+0x00000304u), s.ax);
  }
  L0057b8bb: { trace_pc=0x0057b8bbu; // 0x57b8bb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0057b8bd: { trace_pc=0x0057b8bdu; // 0x57b8bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057b8be: { trace_pc=0x0057b8beu; // 0x57b8be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057b8bf: { trace_pc=0x0057b8bfu; // 0x57b8bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057b8c0: { trace_pc=0x0057b8c0u; // 0x57b8c0: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057b8c2: { trace_pc=0x0057b8c2u; // 0x57b8c2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057b8c3: { trace_pc=0x0057b8c3u; // 0x57b8c3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057b8c6: { trace_pc=0x0057b8c6u; // 0x57b8c6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0057b8ca: { trace_pc=0x0057b8cau; // 0x57b8ca: 66833b00 CMP word ptr [EBX],0x0
    (void)integer::sub(m.r16((s.bx)),0x00000000u,16,flags);
  }
  L0057b8ce: { trace_pc=0x0057b8ceu; // 0x57b8ce: 75aa JNZ 0x0057b87a
    if(integer::condition("JNZ",flags)) goto L0057b87a;
  }
  L0057b8d0: { trace_pc=0x0057b8d0u; // 0x57b8d0: 66837b0200 CMP word ptr [EBX + 0x2],0x0
    (void)integer::sub(m.r16((s.bx+0x00000002u)),0x00000000u,16,flags);
  }
  L0057b8d5: { trace_pc=0x0057b8d5u; // 0x57b8d5: 75a3 JNZ 0x0057b87a
    if(integer::condition("JNZ",flags)) goto L0057b87a;
  }
  L0057b8d7: { trace_pc=0x0057b8d7u; // 0x57b8d7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057b8d9: { trace_pc=0x0057b8d9u; // 0x57b8d9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057b8db: { trace_pc=0x0057b8dbu; // 0x57b8db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b8dc: { trace_pc=0x0057b8dcu; // 0x57b8dc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057b8dd: { trace_pc=0x0057b8ddu; // 0x57b8dd: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0057b8e0: { trace_pc=0x0057b8e0u; // 0x57b8e0: ba00020000 MOV EDX,0x200
    s.dx = 0x00000200u;
  }
  L0057b8e5: { trace_pc=0x0057b8e5u; // 0x57b8e5: 8bdc MOV EBX,ESP
    s.bx = f.sp;
  }
  L0057b8e7: { trace_pc=0x0057b8e7u; // 0x57b8e7: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0057b8e9: { trace_pc=0x0057b8e9u; // 0x57b8e9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057b8eb: { trace_pc=0x0057b8ebu; // 0x57b8eb: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0057b8ed: { trace_pc=0x0057b8edu; // 0x57b8ed: 894b04 MOV dword ptr [EBX + 0x4],ECX
    m.w32((s.bx+0x00000004u), s.cx);
  }
  L0057b8f0: { trace_pc=0x0057b8f0u; // 0x57b8f0: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  L0057b8f3: { trace_pc=0x0057b8f3u; // 0x57b8f3: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L0057b8f6: { trace_pc=0x0057b8f6u; // 0x57b8f6: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L0057b8fa: { trace_pc=0x0057b8fau; // 0x57b8fa: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057b8fc: { trace_pc=0x0057b8fcu; // 0x57b8fc: 8b9708030000 MOV EDX,dword ptr [EDI + 0x308]
    s.dx = m.r32((s.di+0x00000308u));
  }
  L0057b902: { trace_pc=0x0057b902u; // 0x57b902: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0057b903: { trace_pc=0x0057b903u; // 0x57b903: e8382e0000 CALL 0x0057e740
    s.arithmetic_flags=flags; invoke(m,s,f,0x0057e740u,5749000u); flags=s.arithmetic_flags;
  }
  L0057b908: { trace_pc=0x0057b908u; // 0x57b908: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057b90a: { trace_pc=0x0057b90au; // 0x57b90a: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L0057b90e: { trace_pc=0x0057b90eu; // 0x57b90e: 0f8466ffffff JZ 0x0057b87a
    if(integer::condition("JZ",flags)) goto L0057b87a;
  }
  L0057b914: { trace_pc=0x0057b914u; // 0x57b914: 8b8708030000 MOV EAX,dword ptr [EDI + 0x308]
    s.ax = m.r32((s.di+0x00000308u));
  }
  L0057b91a: { trace_pc=0x0057b91au; // 0x57b91a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b91f: { trace_pc=0x0057b91fu; // 0x57b91f: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0057b923: { trace_pc=0x0057b923u; // 0x57b923: e818bafdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5749032u); flags=s.arithmetic_flags;
  }
  L0057b928: { trace_pc=0x0057b928u; // 0x57b928: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b92d: { trace_pc=0x0057b92du; // 0x57b92d: e84eb9fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749042u); flags=s.arithmetic_flags;
  }
  L0057b932: { trace_pc=0x0057b932u; // 0x57b932: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b934: { trace_pc=0x0057b934u; // 0x57b934: 7456 JZ 0x0057b98c
    if(integer::condition("JZ",flags)) goto L0057b98c;
  }
  L0057b936: { trace_pc=0x0057b936u; // 0x57b936: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b93c: { trace_pc=0x0057b93cu; // 0x57b93c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057b93e: { trace_pc=0x0057b93eu; // 0x57b93e: 7505 JNZ 0x0057b945
    if(integer::condition("JNZ",flags)) goto L0057b945;
  }
  L0057b940: { trace_pc=0x0057b940u; // 0x57b940: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0057b943: { trace_pc=0x0057b943u; // 0x57b943: eb1b JMP 0x0057b960
    goto L0057b960;
  }
  L0057b945: { trace_pc=0x0057b945u; // 0x57b945: 0fbf4826 MOVSX ECX,word ptr [EAX + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000026u)),16));
  }
  L0057b949: { trace_pc=0x0057b949u; // 0x57b949: 0faf0d4c6b8300 IMUL ECX,dword ptr [0x00836b4c]
    s.cx = integer::imul(s.cx,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b950: { trace_pc=0x0057b950u; // 0x57b950: 0fbf5824 MOVSX EBX,word ptr [EAX + 0x24]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000024u)),16));
  }
  L0057b954: { trace_pc=0x0057b954u; // 0x57b954: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0057b956: { trace_pc=0x0057b956u; // 0x57b956: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0057b959: { trace_pc=0x0057b959u; // 0x57b959: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b95c: { trace_pc=0x0057b95cu; // 0x57b95c: 8b4c1138 MOV ECX,dword ptr [ECX + EDX*0x1 + 0x38]
    s.cx = m.r32((s.cx+(s.dx * 0x00000001u)+0x00000038u));
  }
  L0057b960: { trace_pc=0x0057b960u; // 0x57b960: 3b4c2460 CMP ECX,dword ptr [ESP + 0x60]
    (void)integer::sub(s.cx,m.r32((f.sp+0x00000060u)),32,flags);
  }
  L0057b964: { trace_pc=0x0057b964u; // 0x57b964: 7518 JNZ 0x0057b97e
    if(integer::condition("JNZ",flags)) goto L0057b97e;
  }
  L0057b966: { trace_pc=0x0057b966u; // 0x57b966: 8b4838 MOV ECX,dword ptr [EAX + 0x38]
    s.cx = m.r32((s.ax+0x00000038u));
  }
  L0057b969: { trace_pc=0x0057b969u; // 0x57b969: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057b96b: { trace_pc=0x0057b96bu; // 0x57b96b: 7408 JZ 0x0057b975
    if(integer::condition("JZ",flags)) goto L0057b975;
  }
  L0057b96d: { trace_pc=0x0057b96du; // 0x57b96d: 81f9ffff0000 CMP ECX,0xffff
    (void)integer::sub(s.cx,0x0000ffffu,32,flags);
  }
  L0057b973: { trace_pc=0x0057b973u; // 0x57b973: 7509 JNZ 0x0057b97e
    if(integer::condition("JNZ",flags)) goto L0057b97e;
  }
  L0057b975: { trace_pc=0x0057b975u; // 0x57b975: 8b1598a8a300 MOV EDX,dword ptr [0x00a3a898]
    s.dx = m.r32((0x00a3a898u));
  }
  L0057b97b: { trace_pc=0x0057b97bu; // 0x57b97b: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L0057b97e: { trace_pc=0x0057b97eu; // 0x57b97e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b983: { trace_pc=0x0057b983u; // 0x57b983: e8f8b8fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749128u); flags=s.arithmetic_flags;
  }
  L0057b988: { trace_pc=0x0057b988u; // 0x57b988: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057b98a: { trace_pc=0x0057b98au; // 0x57b98a: 75aa JNZ 0x0057b936
    if(integer::condition("JNZ",flags)) goto L0057b936;
  }
  L0057b98c: { trace_pc=0x0057b98cu; // 0x57b98c: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0057b991: { trace_pc=0x0057b991u; // 0x57b991: e9e4feffff JMP 0x0057b87a
    goto L0057b87a;
  }
  L0057b996: { trace_pc=0x0057b996u; // 0x57b996: 8bb708030000 MOV ESI,dword ptr [EDI + 0x308]
    s.si = m.r32((s.di+0x00000308u));
  }
  L0057b99c: { trace_pc=0x0057b99cu; // 0x57b99c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b9a1: { trace_pc=0x0057b9a1u; // 0x57b9a1: e89ab9fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5749158u); flags=s.arithmetic_flags;
  }
  L0057b9a6: { trace_pc=0x0057b9a6u; // 0x57b9a6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057b9ab: { trace_pc=0x0057b9abu; // 0x57b9ab: e8d0b8fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749168u); flags=s.arithmetic_flags;
  }
  L0057b9b0: { trace_pc=0x0057b9b0u; // 0x57b9b0: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057b9b2: { trace_pc=0x0057b9b2u; // 0x57b9b2: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057b9b4: { trace_pc=0x0057b9b4u; // 0x57b9b4: 7456 JZ 0x0057ba0c
    if(integer::condition("JZ",flags)) goto L0057ba0c;
  }
  L0057b9b6: { trace_pc=0x0057b9b6u; // 0x57b9b6: 8b5024 MOV EDX,dword ptr [EAX + 0x24]
    s.dx = m.r32((s.ax+0x00000024u));
  }
  L0057b9b9: { trace_pc=0x0057b9b9u; // 0x57b9b9: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L0057b9bd: { trace_pc=0x0057b9bdu; // 0x57b9bd: 0fbf4c2462 MOVSX ECX,word ptr [ESP + 0x62]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000062u)),16));
  }
  L0057b9c2: { trace_pc=0x0057b9c2u; // 0x57b9c2: 0faf0d4c6b8300 IMUL ECX,dword ptr [0x00836b4c]
    s.cx = integer::imul(s.cx,m.r32((0x00836b4cu)),32,flags);
  }
  L0057b9c9: { trace_pc=0x0057b9c9u; // 0x57b9c9: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0057b9cc: { trace_pc=0x0057b9ccu; // 0x57b9cc: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057b9ce: { trace_pc=0x0057b9ceu; // 0x57b9ce: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057b9d4: { trace_pc=0x0057b9d4u; // 0x57b9d4: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0057b9d7: { trace_pc=0x0057b9d7u; // 0x57b9d7: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057b9da: { trace_pc=0x0057b9dau; // 0x57b9da: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057b9dc: { trace_pc=0x0057b9dcu; // 0x57b9dc: 397138 CMP dword ptr [ECX + 0x38],ESI
    (void)integer::sub(m.r32((s.cx+0x00000038u)),s.si,32,flags);
  }
  L0057b9df: { trace_pc=0x0057b9dfu; // 0x57b9df: 751d JNZ 0x0057b9fe
    if(integer::condition("JNZ",flags)) goto L0057b9fe;
  }
  L0057b9e1: { trace_pc=0x0057b9e1u; // 0x57b9e1: 895938 MOV dword ptr [ECX + 0x38],EBX
    m.w32((s.cx+0x00000038u), s.bx);
  }
  L0057b9e4: { trace_pc=0x0057b9e4u; // 0x57b9e4: c6414b00 MOV byte ptr [ECX + 0x4b],0x0
    m.w8((s.cx+0x0000004bu), 0x00000000u);
  }
  L0057b9e8: { trace_pc=0x0057b9e8u; // 0x57b9e8: 895838 MOV dword ptr [EAX + 0x38],EBX
    m.w32((s.ax+0x00000038u), s.bx);
  }
  L0057b9eb: { trace_pc=0x0057b9ebu; // 0x57b9eb: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0057b9f2: { trace_pc=0x0057b9f2u; // 0x57b9f2: 8b8f0c030000 MOV ECX,dword ptr [EDI + 0x30c]
    s.cx = m.r32((s.di+0x0000030cu));
  }
  L0057b9f8: { trace_pc=0x0057b9f8u; // 0x57b9f8: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0057b9fe: { trace_pc=0x0057b9feu; // 0x57b9fe: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057ba03: { trace_pc=0x0057ba03u; // 0x57ba03: e878b8fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5749256u); flags=s.arithmetic_flags;
  }
  L0057ba08: { trace_pc=0x0057ba08u; // 0x57ba08: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057ba0a: { trace_pc=0x0057ba0au; // 0x57ba0a: 75aa JNZ 0x0057b9b6
    if(integer::condition("JNZ",flags)) goto L0057b9b6;
  }
  L0057ba0c: { trace_pc=0x0057ba0cu; // 0x57ba0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057ba0d: { trace_pc=0x0057ba0du; // 0x57ba0d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057ba0e: { trace_pc=0x0057ba0eu; // 0x57ba0e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0057ba10: { trace_pc=0x0057ba10u; // 0x57ba10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057ba11: { trace_pc=0x0057ba11u; // 0x57ba11: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057ba13: { trace_pc=0x0057ba13u; // 0x57ba13: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057ba14: { trace_pc=0x0057ba14u; // 0x57ba14: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
