#include "recovered/numeric_b105_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::numeric_b105 {
namespace {
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0021a540(Memory&,State&,Frame&,const Operations&);
void f_00219de0(Memory&,State&,Frame&,const Operations&);
void f_0018ce60(Memory&,State&,Frame&,const Operations&);
void f_0021a7f0(Memory&,State&,Frame&,const Operations&);
void f_000b8850(Memory&,State&,Frame&,const Operations&);
void f_0018cf80(Memory&,State&,Frame&,const Operations&);
void f_0018cfb0(Memory&,State&,Frame&,const Operations&);
void f_0018cfe0(Memory&,State&,Frame&,const Operations&);
void f_0018d7a0(Memory&,State&,Frame&,const Operations&);
void f_0018d680(Memory&,State&,Frame&,const Operations&);
void f_0018d0d0(Memory&,State&,Frame&,const Operations&);
void f_0018d0f0(Memory&,State&,Frame&,const Operations&);
void f_0018d120(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_000ba0f0(Memory&,State&,Frame&,const Operations&);
void f_000ba140(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0001b630(Memory&,State&,Frame&,const Operations&);
void f_00298010(Memory&,State&,Frame&,const Operations&);
void f_00316970(Memory&,State&,Frame&,const Operations&);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_0029e2c0(Memory&,State&,Frame&,const Operations&);
void f_0029e7b0(Memory&,State&,Frame&,const Operations&);
void f_00297fb0(Memory&,State&,Frame&,const Operations&);
void f_0013b210(Memory&,State&,Frame&,const Operations&);
void f_0018cc10(Memory&,State&,Frame&,const Operations&);
void f_00005110(Memory&,State&,Frame&,const Operations&);
void f_00005140(Memory&,State&,Frame&,const Operations&);
void f_0018e220(Memory&,State&,Frame&,const Operations&);
void f_0018dad0(Memory&,State&,Frame&,const Operations&);
void f_0030e420(Memory&,State&,Frame&,const Operations&);
void f_00310660(Memory&,State&,Frame&,const Operations&);
void f_00378fb8(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);















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
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0021a540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0061a540: { // 0x61a540: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L0061a543: { // 0x61a543: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0061a544: { // 0x61a544: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  L0061a547: { // 0x61a547: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0061a548: { // 0x61a548: 8b6a08 MOV EBP,dword ptr [EDX + 0x8]
    s.bp = m.r32((s.dx+0x00000008u));
  }
  L0061a54b: { // 0x61a54b: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0061a54f: { // 0x61a54f: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L0061a553: { // 0x61a553: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0061a557: { // 0x61a557: d84c2410 FMUL float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a55b: { // 0x61a55b: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0061a55f: { // 0x61a55f: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L0061a563: { // 0x61a563: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0061a564: { // 0x61a564: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0061a565: { // 0x61a565: 8b3a MOV EDI,dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
  L0061a567: { // 0x61a567: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a56a: { // 0x61a56a: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a56c: { // 0x61a56c: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0061a570: { // 0x61a570: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0061a572: { // 0x61a572: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0061a576: { // 0x61a576: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a57a: { // 0x61a57a: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a57c: { // 0x61a57c: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a57f: { // 0x61a57f: e8fcfae9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6399364u); flags=s.arithmetic_flags;
  }
  L0061a584: { // 0x61a584: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0061a58a: { // 0x61a58a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a58d: { // 0x61a58d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a58f: { // 0x61a58f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0061a592: { // 0x61a592: 7536 JNZ 0x0061a5ca
    if(integer::condition("JNZ",flags)) goto L0061a5ca;
  }
  L0061a594: { // 0x61a594: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0061a598: { // 0x61a598: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0061a59a: { // 0x61a59a: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a59e: { // 0x61a59e: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0061a5a2: { // 0x61a5a2: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0061a5a4: { // 0x61a5a4: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0061a5a8: { // 0x61a5a8: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0061a5ac: { // 0x61a5ac: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a5b0: { // 0x61a5b0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0061a5b4: { // 0x61a5b4: d87c2418 FDIVR float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    reverse_divide32(s.fp,m.r32(address));
  }
  L0061a5b8: { // 0x61a5b8: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0061a5bc: { // 0x61a5bc: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a5c0: { // 0x61a5c0: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0061a5c4: { // 0x61a5c4: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0061a5c8: { // 0x61a5c8: eb0e JMP 0x0061a5d8
    goto L0061a5d8;
  }
  L0061a5ca: { // 0x61a5ca: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a5cc: { // 0x61a5cc: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L0061a5d0: { // 0x61a5d0: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0061a5d4: { // 0x61a5d4: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0061a5d8: { // 0x61a5d8: d944243c FLD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load32(m.r32(address));
  }
  L0061a5dc: { // 0x61a5dc: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a5e2: { // 0x61a5e2: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a5e6: { // 0x61a5e6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0061a5ea: { // 0x61a5ea: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0061a5ee: { // 0x61a5ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0061a5ef: { // 0x61a5ef: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0061a5f0: { // 0x61a5f0: e8fbfae9ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6399477u); flags=s.arithmetic_flags;
  }
  L0061a5f5: { // 0x61a5f5: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0061a5f9: { // 0x61a5f9: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a5fb: { // 0x61a5fb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0061a5fc: { // 0x61a5fc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0061a5fd: { // 0x61a5fd: d95c2438 FSTP float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a601: { // 0x61a601: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L0061a605: { // 0x61a605: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a607: { // 0x61a607: d95c243c FSTP float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a60b: { // 0x61a60b: d9442434 FLD float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load32(m.r32(address));
  }
  L0061a60f: { // 0x61a60f: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a611: { // 0x61a611: d95c2440 FSTP float ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a615: { // 0x61a615: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a617: { // 0x61a617: e824fbe9ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,6399516u); flags=s.arithmetic_flags;
  }
  L0061a61c: { // 0x61a61c: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0061a620: { // 0x61a620: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0061a624: { // 0x61a624: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0061a626: { // 0x61a626: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0061a629: { // 0x61a629: d95c2434 FSTP float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a62d: { // 0x61a62d: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0061a62f: { // 0x61a62f: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0061a633: { // 0x61a633: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0061a634: { // 0x61a634: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0061a635: { // 0x61a635: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0061a638: { // 0x61a638: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0061a63c: { // 0x61a63c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0061a63d: { // 0x61a63d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0061a63e: { // 0x61a63e: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0061a641: { // 0x61a641: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0061a644: { // 0x61a644: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L0061a647: { // 0x61a647: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00219de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00619de0: { // 0x619de0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00619de4: { // 0x619de4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00619de5: { // 0x619de5: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    s.fp.load32(m.r32(address));
  }
  L00619de7: { // 0x619de7: d919 FSTP float ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00619de9: { // 0x619de9: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L00619dec: { // 0x619dec: d95904 FSTP float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00619def: { // 0x619def: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00619df2: { // 0x619df2: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00619df5: { // 0x619df5: d9400c FLD float ptr [EAX + 0xc]
    const auto address=(s.ax+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L00619df8: { // 0x619df8: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00619dfc: { // 0x619dfc: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00619dff: { // 0x619dff: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00619e01: { // 0x619e01: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00619e03: { // 0x619e03: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  L00619e05: { // 0x619e05: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L00619e08: { // 0x619e08: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L00619e0b: { // 0x619e0b: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00619e0e: { // 0x619e0e: 897208 MOV dword ptr [EDX + 0x8],ESI
    m.w32((s.dx+0x00000008u), s.si);
  }
  L00619e11: { // 0x619e11: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00619e14: { // 0x619e14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00619e15: { // 0x619e15: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L00619e18: { // 0x619e18: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0018ce60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058ce60: { // 0x58ce60: ba0000803f MOV EDX,0x3f800000
    s.dx = 0x3f800000u;
  }
  L0058ce65: { // 0x58ce65: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0058ce67: { // 0x58ce67: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058ce69: { // 0x58ce69: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0058ce6c: { // 0x58ce6c: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L0058ce6f: { // 0x58ce6f: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0058ce72: { // 0x58ce72: 894110 MOV dword ptr [ECX + 0x10],EAX
    m.w32((s.cx+0x00000010u), s.ax);
  }
  L0058ce75: { // 0x58ce75: 895114 MOV dword ptr [ECX + 0x14],EDX
    m.w32((s.cx+0x00000014u), s.dx);
  }
  L0058ce78: { // 0x58ce78: 894118 MOV dword ptr [ECX + 0x18],EAX
    m.w32((s.cx+0x00000018u), s.ax);
  }
  L0058ce7b: { // 0x58ce7b: 89411c MOV dword ptr [ECX + 0x1c],EAX
    m.w32((s.cx+0x0000001cu), s.ax);
  }
  L0058ce7e: { // 0x58ce7e: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L0058ce81: { // 0x58ce81: 894124 MOV dword ptr [ECX + 0x24],EAX
    m.w32((s.cx+0x00000024u), s.ax);
  }
  L0058ce84: { // 0x58ce84: 895128 MOV dword ptr [ECX + 0x28],EDX
    m.w32((s.cx+0x00000028u), s.dx);
  }
  L0058ce87: { // 0x58ce87: 89412c MOV dword ptr [ECX + 0x2c],EAX
    m.w32((s.cx+0x0000002cu), s.ax);
  }
  L0058ce8a: { // 0x58ce8a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0021a7f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0061a7f0: { // 0x61a7f0: 83ec50 SUB ESP,0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  L0061a7f3: { // 0x61a7f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0061a7f4: { // 0x61a7f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0061a7f5: { // 0x61a7f5: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0061a7f7: { // 0x61a7f7: b80a000000 MOV EAX,0xa
    s.ax = 0x0000000au;
  }
  L0061a7fc: { // 0x61a7fc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0061a7fd: { // 0x61a7fd: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0061a801: { // 0x61a801: d94628 FLD float ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0061a804: { // 0x61a804: d84614 FADD float ptr [ESI + 0x14]
    const auto address=(s.si+0x00000014u);
    s.fp.add32(m.r32(address));
  }
  L0061a807: { // 0x61a807: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L0061a80b: { // 0x61a80b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0061a80d: { // 0x61a80d: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0061a80f: { // 0x61a80f: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L0061a814: { // 0x61a814: d806 FADD float ptr [ESI]
    const auto address=(s.si);
    s.fp.add32(m.r32(address));
  }
  L0061a816: { // 0x61a816: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0061a81a: { // 0x61a81a: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0061a822: { // 0x61a822: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
  L0061a82a: { // 0x61a82a: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0061a832: { // 0x61a832: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0061a838: { // 0x61a838: c74424280000803f MOV dword ptr [ESP + 0x28],0x3f800000
    m.w32((f.sp+0x00000028u), 0x3f800000u);
  }
  L0061a840: { // 0x61a840: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0061a844: { // 0x61a844: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0061a848: { // 0x61a848: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0061a84c: { // 0x61a84c: c744243001000000 MOV dword ptr [ESP + 0x30],0x1
    m.w32((f.sp+0x00000030u), 0x00000001u);
  }
  L0061a854: { // 0x61a854: c744243402000000 MOV dword ptr [ESP + 0x34],0x2
    m.w32((f.sp+0x00000034u), 0x00000002u);
  }
  L0061a85c: { // 0x61a85c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a85e: { // 0x61a85e: c744243803000000 MOV dword ptr [ESP + 0x38],0x3
    m.w32((f.sp+0x00000038u), 0x00000003u);
  }
  L0061a866: { // 0x61a866: c744243c04000000 MOV dword ptr [ESP + 0x3c],0x4
    m.w32((f.sp+0x0000003cu), 0x00000004u);
  }
  L0061a86e: { // 0x61a86e: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0061a871: { // 0x61a871: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0061a875: { // 0x61a875: c744244406000000 MOV dword ptr [ESP + 0x44],0x6
    m.w32((f.sp+0x00000044u), 0x00000006u);
  }
  L0061a87d: { // 0x61a87d: c744244807000000 MOV dword ptr [ESP + 0x48],0x7
    m.w32((f.sp+0x00000048u), 0x00000007u);
  }
  L0061a885: { // 0x61a885: c744244c08000000 MOV dword ptr [ESP + 0x4c],0x8
    m.w32((f.sp+0x0000004cu), 0x00000008u);
  }
  L0061a88d: { // 0x61a88d: c744245009000000 MOV dword ptr [ESP + 0x50],0x9
    m.w32((f.sp+0x00000050u), 0x00000009u);
  }
  L0061a895: { // 0x61a895: c74424580b000000 MOV dword ptr [ESP + 0x58],0xb
    m.w32((f.sp+0x00000058u), 0x0000000bu);
  }
  L0061a89d: { // 0x61a89d: 7426 JZ 0x0061a8c5
    if(integer::condition("JZ",flags)) goto L0061a8c5;
  }
  L0061a89f: { // 0x61a89f: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0061a8a3: { // 0x61a8a3: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0061a8a7: { // 0x61a8a7: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0061a8a9: { // 0x61a8a9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0061a8aa: { // 0x61a8aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0061a8ab: { // 0x61a8ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0061a8ac: { // 0x61a8ac: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0061a8ae: { // 0x61a8ae: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0061a8b2: { // 0x61a8b2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a8b4: { // 0x61a8b4: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0061a8b7: { // 0x61a8b7: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0061a8bb: { // 0x61a8bb: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0061a8be: { // 0x61a8be: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0061a8c1: { // 0x61a8c1: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  L0061a8c4: { // 0x61a8c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0061a8c5: { // 0x61a8c5: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0061a8cb: { // 0x61a8cb: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a8cd: { // 0x61a8cd: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0061a8d0: { // 0x61a8d0: 7551 JNZ 0x0061a923
    if(integer::condition("JNZ",flags)) goto L0061a923;
  }
  L0061a8d2: { // 0x61a8d2: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0061a8d8: { // 0x61a8d8: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a8db: { // 0x61a8db: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a8de: { // 0x61a8de: e89df7e9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6400227u); flags=s.arithmetic_flags;
  }
  L0061a8e3: { // 0x61a8e3: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0061a8e5: { // 0x61a8e5: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L0061a8eb: { // 0x61a8eb: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a8ef: { // 0x61a8ef: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a8f2: { // 0x61a8f2: dc3d28577800 FDIVR double ptr [0x00785728]
    const auto address=(0x00785728u);
    reverse_divide64(s.fp,read64(m,address));
  }
  L0061a8f8: { // 0x61a8f8: d94624 FLD float ptr [ESI + 0x24]
    const auto address=(s.si+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0061a8fb: { // 0x61a8fb: d86618 FSUB float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    s.fp.subtract32(m.r32(address));
  }
  L0061a8fe: { // 0x61a8fe: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a900: { // 0x61a900: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a904: { // 0x61a904: d94608 FLD float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0061a907: { // 0x61a907: d86620 FSUB float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    s.fp.subtract32(m.r32(address));
  }
  L0061a90a: { // 0x61a90a: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a90c: { // 0x61a90c: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a910: { // 0x61a910: d94610 FLD float ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0061a913: { // 0x61a913: d86604 FSUB float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.subtract32(m.r32(address));
  }
  L0061a916: { // 0x61a916: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a918: { // 0x61a918: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a91c: { // 0x61a91c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a91e: { // 0x61a91e: e9ec000000 JMP 0x0061aa0f
    goto L0061aa0f;
  }
  L0061a923: { // 0x61a923: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a925: { // 0x61a925: d94614 FLD float ptr [ESI + 0x14]
    const auto address=(s.si+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0061a928: { // 0x61a928: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
  L0061a92a: { // 0x61a92a: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0061a92c: { // 0x61a92c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0061a92d: { // 0x61a92d: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0061a92f: { // 0x61a92f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a931: { // 0x61a931: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0061a934: { // 0x61a934: 7405 JZ 0x0061a93b
    if(integer::condition("JZ",flags)) goto L0061a93b;
  }
  L0061a936: { // 0x61a936: bd01000000 MOV EBP,0x1
    s.bp = 0x00000001u;
  }
  L0061a93b: { // 0x61a93b: 8b44ac14 MOV EAX,dword ptr [ESP + EBP*0x4 + 0x14]
    s.ax = m.r32((f.sp+(s.bp * 0x00000004u)+0x00000014u));
  }
  L0061a93f: { // 0x61a93f: d94628 FLD float ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0061a942: { // 0x61a942: d90486 FLD float ptr [ESI + EAX*0x4]
    const auto address=(s.si+(s.ax * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L0061a945: { // 0x61a945: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0061a947: { // 0x61a947: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a949: { // 0x61a949: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0061a94c: { // 0x61a94c: 7405 JZ 0x0061a953
    if(integer::condition("JZ",flags)) goto L0061a953;
  }
  L0061a94e: { // 0x61a94e: bd02000000 MOV EBP,0x2
    s.bp = 0x00000002u;
  }
  L0061a953: { // 0x61a953: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0061a955: { // 0x61a955: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0061a956: { // 0x61a956: 7418 JZ 0x0061a970
    if(integer::condition("JZ",flags)) goto L0061a970;
  }
  L0061a958: { // 0x61a958: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0061a959: { // 0x61a959: 740c JZ 0x0061a967
    if(integer::condition("JZ",flags)) goto L0061a967;
  }
  L0061a95b: { // 0x61a95b: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L0061a960: { // 0x61a960: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L0061a965: { // 0x61a965: eb0e JMP 0x0061a975
    goto L0061a975;
  }
  L0061a967: { // 0x61a967: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0061a969: { // 0x61a969: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0061a96e: { // 0x61a96e: eb05 JMP 0x0061a975
    goto L0061a975;
  }
  L0061a970: { // 0x61a970: bf02000000 MOV EDI,0x2
    s.di = 0x00000002u;
  }
  L0061a975: { // 0x61a975: 8b4cac14 MOV ECX,dword ptr [ESP + EBP*0x4 + 0x14]
    s.cx = m.r32((f.sp+(s.bp * 0x00000004u)+0x00000014u));
  }
  L0061a979: { // 0x61a979: 8b54bc14 MOV EDX,dword ptr [ESP + EDI*0x4 + 0x14]
    s.dx = m.r32((f.sp+(s.di * 0x00000004u)+0x00000014u));
  }
  L0061a97d: { // 0x61a97d: 8b449c14 MOV EAX,dword ptr [ESP + EBX*0x4 + 0x14]
    s.ax = m.r32((f.sp+(s.bx * 0x00000004u)+0x00000014u));
  }
  L0061a981: { // 0x61a981: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a984: { // 0x61a984: d9048e FLD float ptr [ESI + ECX*0x4]
    const auto address=(s.si+(s.cx * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L0061a987: { // 0x61a987: d90496 FLD float ptr [ESI + EDX*0x4]
    const auto address=(s.si+(s.dx * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L0061a98a: { // 0x61a98a: d90486 FLD float ptr [ESI + EAX*0x4]
    const auto address=(s.si+(s.ax * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L0061a98d: { // 0x61a98d: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L0061a98f: { // 0x61a98f: d8ea FSUBR ST0,ST2
    numeric_b88::detail::reg<0xd8ea>(s.fp);
  }
  L0061a991: { // 0x61a991: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0061a997: { // 0x61a997: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a99a: { // 0x61a99a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a99c: { // 0x61a99c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a99e: { // 0x61a99e: e8ddf6e9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6400419u); flags=s.arithmetic_flags;
  }
  L0061a9a3: { // 0x61a9a3: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0061a9a5: { // 0x61a9a5: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L0061a9ab: { // 0x61a9ab: d95cac28 FSTP float ptr [ESP + EBP*0x4 + 0x28]
    const auto address=(f.sp+(s.bp * 0x00000004u)+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a9af: { // 0x61a9af: 8d0c9f LEA ECX,[EDI + EBX*0x4]
    s.cx = (s.di+(s.bx * 0x00000004u));
  }
  L0061a9b2: { // 0x61a9b2: 8d04bb LEA EAX,[EBX + EDI*0x4]
    s.ax = (s.bx+(s.di * 0x00000004u));
  }
  L0061a9b5: { // 0x61a9b5: dc3d28577800 FDIVR double ptr [0x00785728]
    const auto address=(0x00785728u);
    reverse_divide64(s.fp,read64(m,address));
  }
  L0061a9bb: { // 0x61a9bb: 8b548c38 MOV EDX,dword ptr [ESP + ECX*0x4 + 0x38]
    s.dx = m.r32((f.sp+(s.cx * 0x00000004u)+0x00000038u));
  }
  L0061a9bf: { // 0x61a9bf: 8b4c8438 MOV ECX,dword ptr [ESP + EAX*0x4 + 0x38]
    s.cx = m.r32((f.sp+(s.ax * 0x00000004u)+0x00000038u));
  }
  L0061a9c3: { // 0x61a9c3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a9c6: { // 0x61a9c6: d90496 FLD float ptr [ESI + EDX*0x4]
    const auto address=(s.si+(s.dx * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L0061a9c9: { // 0x61a9c9: d8248e FSUB float ptr [ESI + ECX*0x4]
    const auto address=(s.si+(s.cx * 0x00000004u));
    s.fp.subtract32(m.r32(address));
  }
  L0061a9cc: { // 0x61a9cc: 8d54bd00 LEA EDX,[EBP + EDI*0x4]
    s.dx = (s.bp+(s.di * 0x00000004u));
  }
  L0061a9d0: { // 0x61a9d0: 8d0caf LEA ECX,[EDI + EBP*0x4]
    s.cx = (s.di+(s.bp * 0x00000004u));
  }
  L0061a9d3: { // 0x61a9d3: 8b449430 MOV EAX,dword ptr [ESP + EDX*0x4 + 0x30]
    s.ax = m.r32((f.sp+(s.dx * 0x00000004u)+0x00000030u));
  }
  L0061a9d7: { // 0x61a9d7: 8b548c30 MOV EDX,dword ptr [ESP + ECX*0x4 + 0x30]
    s.dx = m.r32((f.sp+(s.cx * 0x00000004u)+0x00000030u));
  }
  L0061a9db: { // 0x61a9db: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a9dd: { // 0x61a9dd: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a9e1: { // 0x61a9e1: d90486 FLD float ptr [ESI + EAX*0x4]
    const auto address=(s.si+(s.ax * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L0061a9e4: { // 0x61a9e4: d80496 FADD float ptr [ESI + EDX*0x4]
    const auto address=(s.si+(s.dx * 0x00000004u));
    s.fp.add32(m.r32(address));
  }
  L0061a9e7: { // 0x61a9e7: 8d449d00 LEA EAX,[EBP + EBX*0x4]
    s.ax = (s.bp+(s.bx * 0x00000004u));
  }
  L0061a9eb: { // 0x61a9eb: 8d14ab LEA EDX,[EBX + EBP*0x4]
    s.dx = (s.bx+(s.bp * 0x00000004u));
  }
  L0061a9ee: { // 0x61a9ee: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0061a9ef: { // 0x61a9ef: 8b4c842c MOV ECX,dword ptr [ESP + EAX*0x4 + 0x2c]
    s.cx = m.r32((f.sp+(s.ax * 0x00000004u)+0x0000002cu));
  }
  L0061a9f3: { // 0x61a9f3: 8b44942c MOV EAX,dword ptr [ESP + EDX*0x4 + 0x2c]
    s.ax = m.r32((f.sp+(s.dx * 0x00000004u)+0x0000002cu));
  }
  L0061a9f7: { // 0x61a9f7: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a9f9: { // 0x61a9f9: d95cbc1c FSTP float ptr [ESP + EDI*0x4 + 0x1c]
    const auto address=(f.sp+(s.di * 0x00000004u)+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a9fd: { // 0x61a9fd: d9048e FLD float ptr [ESI + ECX*0x4]
    const auto address=(s.si+(s.cx * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L0061aa00: { // 0x61aa00: d80486 FADD float ptr [ESI + EAX*0x4]
    const auto address=(s.si+(s.ax * 0x00000004u));
    s.fp.add32(m.r32(address));
  }
  L0061aa03: { // 0x61aa03: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0061aa07: { // 0x61aa07: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061aa09: { // 0x61aa09: d95c9c1c FSTP float ptr [ESP + EBX*0x4 + 0x1c]
    const auto address=(f.sp+(s.bx * 0x00000004u)+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061aa0d: { // 0x61aa0d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061aa0f: { // 0x61aa0f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0061aa13: { // 0x61aa13: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0061aa17: { // 0x61aa17: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0061aa19: { // 0x61aa19: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0061aa1b: { // 0x61aa1b: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0061aa1f: { // 0x61aa1f: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0061aa22: { // 0x61aa22: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0061aa26: { // 0x61aa26: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0061aa29: { // 0x61aa29: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0061aa2c: { // 0x61aa2c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0061aa2e: { // 0x61aa2e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0061aa2f: { // 0x61aa2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0061aa30: { // 0x61aa30: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0061aa31: { // 0x61aa31: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  L0061aa34: { // 0x61aa34: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000b8850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8850: { // 0x4b8850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004b8851: { // 0x4b8851: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004b8852: { // 0x4b8852: 668b5914 MOV BX,word ptr [ECX + 0x14]
    s.bx = with_ax(s.bx, m.r16((s.cx+0x00000014u)));
  }
  L004b8856: { // 0x4b8856: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b8857: { // 0x4b8857: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b8858: { // 0x4b8858: 6685db TEST BX,BX
    (void)integer::logical(((s.bx & 0xffffu))&((s.bx & 0xffffu)),16,flags);
  }
  L004b885b: { // 0x4b885b: 7e7d JLE 0x004b88da
    if(integer::condition("JLE",flags)) goto L004b88da;
  }
  L004b885d: { // 0x4b885d: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L004b8860: { // 0x4b8860: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004b8863: { // 0x4b8863: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L004b8869: { // 0x4b8869: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L004b886c: { // 0x4b886c: 740a JZ 0x004b8878
    if(integer::condition("JZ",flags)) goto L004b8878;
  }
  L004b886e: { // 0x4b886e: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L004b8870: { // 0x4b8870: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L004b8872: { // 0x4b8872: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004b8874: { // 0x4b8874: 7d64 JGE 0x004b88da
    if(integer::condition("JGE",flags)) goto L004b88da;
  }
  L004b8876: { // 0x4b8876: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8878: { // 0x4b8878: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004b887a: { // 0x4b887a: 745e JZ 0x004b88da
    if(integer::condition("JZ",flags)) goto L004b88da;
  }
  L004b887c: { // 0x4b887c: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L004b887f: { // 0x4b887f: 662b4104 SUB AX,word ptr [ECX + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.cx+0x00000004u)),16,flags));
  }
  L004b8883: { // 0x4b8883: 0fbfdb MOVSX EBX,BX
    s.bx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L004b8886: { // 0x4b8886: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b8889: { // 0x4b8889: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b888b: { // 0x4b888b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b888c: { // 0x4b888c: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004b888e: { // 0x4b888e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8890: { // 0x4b8890: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b8891: { // 0x4b8891: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b8893: { // 0x4b8893: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b8895: { // 0x4b8895: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L004b8899: { // 0x4b8899: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L004b889c: { // 0x4b889c: 7e27 JLE 0x004b88c5
    if(integer::condition("JLE",flags)) goto L004b88c5;
  }
  L004b889e: { // 0x4b889e: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004b88a1: { // 0x4b88a1: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L004b88a4: { // 0x4b88a4: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004b88a7: { // 0x4b88a7: 740a JZ 0x004b88b3
    if(integer::condition("JZ",flags)) goto L004b88b3;
  }
  L004b88a9: { // 0x4b88a9: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004b88ab: { // 0x4b88ab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004b88ad: { // 0x4b88ad: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004b88af: { // 0x4b88af: 7d25 JGE 0x004b88d6
    if(integer::condition("JGE",flags)) goto L004b88d6;
  }
  L004b88b1: { // 0x4b88b1: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L004b88b3: { // 0x4b88b3: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004b88b5: { // 0x4b88b5: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b88b8: { // 0x4b88b8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b88ba: { // 0x4b88ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b88bb: { // 0x4b88bb: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b88bd: { // 0x4b88bd: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L004b88c0: { // 0x4b88c0: 662944240c SUB word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), integer::sub(m.r16((f.sp+0x0000000cu)),(s.ax & 0xffffu),16,flags));
  }
  L004b88c5: { // 0x4b88c5: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88c9: { // 0x4b88c9: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004b88cd: { // 0x4b88cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88ce: { // 0x4b88ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88cf: { // 0x4b88cf: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004b88d1: { // 0x4b88d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88d2: { // 0x4b88d2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88d3: { // 0x4b88d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004b88d6: { // 0x4b88d6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b88d8: { // 0x4b88d8: ebdb JMP 0x004b88b5
    goto L004b88b5;
  }
  L004b88da: { // 0x4b88da: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88de: { // 0x4b88de: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b88e0: { // 0x4b88e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88e1: { // 0x4b88e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88e2: { // 0x4b88e2: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004b88e4: { // 0x4b88e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88e5: { // 0x4b88e5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88e6: { // 0x4b88e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018cf80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058cf80: { // 0x58cf80: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cf84: { // 0x58cf84: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    s.fp.multiply32(m.r32(address));
  }
  L0058cf86: { // 0x58cf86: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058cf89: { // 0x58cf89: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cf8c: { // 0x58cf8c: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cf90: { // 0x58cf90: d84910 FMUL float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cf93: { // 0x58cf93: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058cf96: { // 0x58cf96: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cf99: { // 0x58cf99: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cf9d: { // 0x58cf9d: d84920 FMUL float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cfa0: { // 0x58cfa0: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058cfa3: { // 0x58cfa3: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cfa6: { // 0x58cfa6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018cfb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058cfb0: { // 0x58cfb0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cfb4: { // 0x58cfb4: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cfb7: { // 0x58cfb7: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058cfba: { // 0x58cfba: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cfbd: { // 0x58cfbd: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cfc1: { // 0x58cfc1: d84914 FMUL float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cfc4: { // 0x58cfc4: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058cfc7: { // 0x58cfc7: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cfca: { // 0x58cfca: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cfce: { // 0x58cfce: d84924 FMUL float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cfd1: { // 0x58cfd1: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058cfd4: { // 0x58cfd4: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cfd7: { // 0x58cfd7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018cfe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058cfe0: { // 0x58cfe0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cfe4: { // 0x58cfe4: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cfe7: { // 0x58cfe7: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058cfea: { // 0x58cfea: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cfed: { // 0x58cfed: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cff1: { // 0x58cff1: d84918 FMUL float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cff4: { // 0x58cff4: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058cff7: { // 0x58cff7: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cffa: { // 0x58cffa: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cffe: { // 0x58cffe: d84928 FMUL float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d001: { // 0x58d001: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058d004: { // 0x58d004: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d007: { // 0x58d007: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d7a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058d7a0: { // 0x58d7a0: 83ec08 SUB ESP,8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L0058d7a3: { // 0x58d7a3: d944240c FLD float ptr [ESP+0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058d7a7: { // 0x58d7a7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7a8: { // 0x58d7a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058d7a9: { // 0x58d7a9: dd5c2408 FSTP double ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058d7ad: { // 0x58d7ad: 8b5c2408 MOV EBX,dword ptr [ESP+8]
    s.bx = m.r32((f.sp+8u));
  }
  L0058d7b1: { // 0x58d7b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7b2: { // 0x58d7b2: 8b7c2410 MOV EDI,dword ptr [ESP+0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0058d7b6: { // 0x58d7b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058d7b8: { // 0x58d7b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7b9: { // 0x58d7b9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7ba: { // 0x58d7ba: e881c9f2ff CALL 0x4ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5822399u); flags=s.arithmetic_flags;
  }
  L0058d7bf: { // 0x58d7bf: d95c2420 FSTP float ptr [ESP+0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7c3: { // 0x58d7c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7c4: { // 0x58d7c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7c5: { // 0x58d7c5: e826c9f2ff CALL 0x4ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5822410u); flags=s.arithmetic_flags;
  }
  L0058d7ca: { // 0x58d7ca: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
  L0058d7cc: { // 0x58d7cc: d94604 FLD float ptr [ESI+4]
    const auto address=(s.si+4u);
    s.fp.load32(m.r32(address));
  }
  L0058d7cf: { // 0x58d7cf: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d7d1: { // 0x58d7d1: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d7d3: { // 0x58d7d3: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d7d5: { // 0x58d7d5: d84c2428 FMUL float ptr [ESP+0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7d9: { // 0x58d7d9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0058d7dc: { // 0x58d7dc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d7de: { // 0x58d7de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058d7df: { // 0x58d7df: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7e1: { // 0x58d7e1: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7e5: { // 0x58d7e5: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d7e7: { // 0x58d7e7: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d7e9: { // 0x58d7e9: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d7eb: { // 0x58d7eb: d95e04 FSTP float ptr [ESI+4]
    const auto address=(s.si+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7ee: { // 0x58d7ee: d94610 FLD float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058d7f1: { // 0x58d7f1: d94614 FLD float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058d7f4: { // 0x58d7f4: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d7f6: { // 0x58d7f6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d7f8: { // 0x58d7f8: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d7fa: { // 0x58d7fa: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7fe: { // 0x58d7fe: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d800: { // 0x58d800: d95e10 FSTP float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d803: { // 0x58d803: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d807: { // 0x58d807: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d809: { // 0x58d809: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d80b: { // 0x58d80b: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d80d: { // 0x58d80d: d95e14 FSTP float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d810: { // 0x58d810: d94620 FLD float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058d813: { // 0x58d813: d94624 FLD float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058d816: { // 0x58d816: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d818: { // 0x58d818: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d81a: { // 0x58d81a: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d81c: { // 0x58d81c: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d820: { // 0x58d820: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d822: { // 0x58d822: d95e20 FSTP float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d825: { // 0x58d825: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d829: { // 0x58d829: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d82b: { // 0x58d82b: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d82d: { // 0x58d82d: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d82f: { // 0x58d82f: d95e24 FSTP float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d832: { // 0x58d832: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058d833: { // 0x58d833: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058d834: { // 0x58d834: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0058d836: { // 0x58d836: 83c408 ADD ESP,8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0058d839: { // 0x58d839: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d680(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058d680: { // 0x58d680: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0058d683: { // 0x58d683: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058d687: { // 0x58d687: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d688: { // 0x58d688: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058d689: { // 0x58d689: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058d68d: { // 0x58d68d: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L0058d691: { // 0x58d691: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d692: { // 0x58d692: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0058d696: { // 0x58d696: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058d698: { // 0x58d698: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d699: { // 0x58d699: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d69a: { // 0x58d69a: e851caf2ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5822111u); flags=s.arithmetic_flags;
  }
  L0058d69f: { // 0x58d69f: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d6a3: { // 0x58d6a3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d6a4: { // 0x58d6a4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d6a5: { // 0x58d6a5: e896caf2ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5822122u); flags=s.arithmetic_flags;
  }
  L0058d6aa: { // 0x58d6aa: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
  L0058d6ac: { // 0x58d6ac: d94608 FLD float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058d6af: { // 0x58d6af: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0058d6b1: { // 0x58d6b1: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d6b3: { // 0x58d6b3: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0058d6b5: { // 0x58d6b5: d84c2428 FMUL float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d6b9: { // 0x58d6b9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0058d6bc: { // 0x58d6bc: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d6be: { // 0x58d6be: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058d6bf: { // 0x58d6bf: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d6c1: { // 0x58d6c1: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d6c3: { // 0x58d6c3: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d6c5: { // 0x58d6c5: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d6c9: { // 0x58d6c9: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d6cb: { // 0x58d6cb: d95e08 FSTP float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d6ce: { // 0x58d6ce: d94610 FLD float ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058d6d1: { // 0x58d6d1: d94618 FLD float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0058d6d4: { // 0x58d6d4: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0058d6d6: { // 0x58d6d6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d6d8: { // 0x58d6d8: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0058d6da: { // 0x58d6da: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d6de: { // 0x58d6de: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d6e0: { // 0x58d6e0: d95e10 FSTP float ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d6e3: { // 0x58d6e3: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d6e5: { // 0x58d6e5: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d6e7: { // 0x58d6e7: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d6eb: { // 0x58d6eb: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d6ed: { // 0x58d6ed: d95e18 FSTP float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d6f0: { // 0x58d6f0: d94620 FLD float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058d6f3: { // 0x58d6f3: d94628 FLD float ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0058d6f6: { // 0x58d6f6: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0058d6f8: { // 0x58d6f8: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d6fa: { // 0x58d6fa: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0058d6fc: { // 0x58d6fc: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d700: { // 0x58d700: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d702: { // 0x58d702: d95e20 FSTP float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d705: { // 0x58d705: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d707: { // 0x58d707: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d709: { // 0x58d709: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d70d: { // 0x58d70d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d70f: { // 0x58d70f: d95e28 FSTP float ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d712: { // 0x58d712: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058d713: { // 0x58d713: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058d714: { // 0x58d714: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0058d716: { // 0x58d716: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0058d719: { // 0x58d719: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d0d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058d0d0: { // 0x58d0d0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d0d4: { // 0x58d0d4: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    s.fp.multiply32(m.r32(address));
  }
  L0058d0d6: { // 0x58d0d6: d919 FSTP float ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d0d8: { // 0x58d0d8: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d0dc: { // 0x58d0dc: d84910 FMUL float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d0df: { // 0x58d0df: d95910 FSTP float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d0e2: { // 0x58d0e2: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d0e6: { // 0x58d0e6: d84920 FMUL float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d0e9: { // 0x58d0e9: d95920 FSTP float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d0ec: { // 0x58d0ec: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058d0f0: { // 0x58d0f0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d0f4: { // 0x58d0f4: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d0f7: { // 0x58d0f7: d95904 FSTP float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d0fa: { // 0x58d0fa: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d0fe: { // 0x58d0fe: d84914 FMUL float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d101: { // 0x58d101: d95914 FSTP float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d104: { // 0x58d104: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d108: { // 0x58d108: d84924 FMUL float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d10b: { // 0x58d10b: d95924 FSTP float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d10e: { // 0x58d10e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058d120: { // 0x58d120: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d124: { // 0x58d124: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d127: { // 0x58d127: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d12a: { // 0x58d12a: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d12e: { // 0x58d12e: d84918 FMUL float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d131: { // 0x58d131: d95918 FSTP float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d134: { // 0x58d134: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058d138: { // 0x58d138: d84928 FMUL float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d13b: { // 0x58d13b: d95928 FSTP float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d13e: { // 0x58d13e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba0f0: { // 0x4ba0f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba0f4: { // 0x4ba0f4: d80d38317c00 FMUL float ptr [0x007c3138]
    const auto address=(0x007c3138u);
    s.fp.multiply32(m.r32(address));
  }
  L004ba0fa: { // 0x4ba0fa: e851092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956415u); flags=s.arithmetic_flags;
  }
  L004ba0ff: { // 0x4ba0ff: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L004ba101: { // 0x4ba101: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ba102: { // 0x4ba102: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ba104: { // 0x4ba104: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004ba107: { // 0x4ba107: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ba109: { // 0x4ba109: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  L004ba10e: { // 0x4ba10e: 790e JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  L004ba110: { // 0x4ba110: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ba111: { // 0x4ba111: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  L004ba116: { // 0x4ba116: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba117: { // 0x4ba117: 7905 JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  L004ba119: { // 0x4ba119: 0500200000 ADD EAX,0x2000
    s.ax = integer::add(s.ax,0x00002000u,32,flags);
  }
  L004ba11e: { // 0x4ba11e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ba120: { // 0x4ba120: 7408 JZ 0x004ba12a
    if(integer::condition("JZ",flags)) goto L004ba12a;
  }
  L004ba122: { // 0x4ba122: 3dff1f0000 CMP EAX,0x1fff
    (void)integer::sub(s.ax,0x00001fffu,32,flags);
  }
  L004ba127: { // 0x4ba127: 7d01 JGE 0x004ba12a
    if(integer::condition("JGE",flags)) goto L004ba12a;
  }
  L004ba129: { // 0x4ba129: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba12a: { // 0x4ba12a: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
  L004ba131: { // 0x4ba131: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba140: { // 0x4ba140: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba144: { // 0x4ba144: d80d3c317c00 FMUL float ptr [0x007c313c]
    const auto address=(0x007c313cu);
    s.fp.multiply32(m.r32(address));
  }
  L004ba14a: { // 0x4ba14a: e801092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956495u); flags=s.arithmetic_flags;
  }
  L004ba14f: { // 0x4ba14f: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L004ba151: { // 0x4ba151: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ba152: { // 0x4ba152: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ba154: { // 0x4ba154: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004ba157: { // 0x4ba157: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ba159: { // 0x4ba159: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  L004ba15e: { // 0x4ba15e: 7910 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  L004ba160: { // 0x4ba160: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ba161: { // 0x4ba161: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  L004ba166: { // 0x4ba166: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba167: { // 0x4ba167: 7907 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  L004ba169: { // 0x4ba169: 0500280000 ADD EAX,0x2800
    s.ax = integer::add(s.ax,0x00002800u,32,flags);
  }
  L004ba16e: { // 0x4ba16e: eb05 JMP 0x004ba175
    goto L004ba175;
  }
  L004ba170: { // 0x4ba170: 0500080000 ADD EAX,0x800
    s.ax = integer::add(s.ax,0x00000800u,32,flags);
  }
  L004ba175: { // 0x4ba175: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ba177: { // 0x4ba177: 7408 JZ 0x004ba181
    if(integer::condition("JZ",flags)) goto L004ba181;
  }
  L004ba179: { // 0x4ba179: 3dff270000 CMP EAX,0x27ff
    (void)integer::sub(s.ax,0x000027ffu,32,flags);
  }
  L004ba17e: { // 0x4ba17e: 7d01 JGE 0x004ba181
    if(integer::condition("JGE",flags)) goto L004ba181;
  }
  L004ba180: { // 0x4ba180: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba181: { // 0x4ba181: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
  L004ba188: { // 0x4ba188: c3 RET
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
void f_0001b630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b630: { // 0x41b630: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0041b634: { // 0x41b634: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041b636: { // 0x41b636: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0041b63a: { // 0x41b63a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b63c: { // 0x41b63c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0041b640: { // 0x41b640: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0041b643: { // 0x41b643: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0041b646: { // 0x41b646: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00298010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698010: { // 0x698010: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00698013: { // 0x698013: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00698014: { // 0x698014: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00698018: { // 0x698018: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00698019: { // 0x698019: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069801a: { // 0x69801a: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L0069801c: { // 0x69801c: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L0069801f: { // 0x69801f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00698023: { // 0x698023: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00698025: { // 0x698025: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698028: { // 0x698028: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698029: { // 0x698029: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0069802d: { // 0x69802d: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00698030: { // 0x698030: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698033: { // 0x698033: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069803b: { // 0x69803b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069803e: { // 0x69803e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069803f: { // 0x69803f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698041: { // 0x698041: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698043: { // 0x698043: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698046: { // 0x698046: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698048: { // 0x698048: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069804b: { // 0x69804b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069804d: { // 0x69804d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069804e: { // 0x69804e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698050: { // 0x698050: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698052: { // 0x698052: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698054: { // 0x698054: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00698057: { // 0x698057: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00698059: { // 0x698059: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069805b: { // 0x69805b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069805e: { // 0x69805e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069805f: { // 0x69805f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698061: { // 0x698061: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698063: { // 0x698063: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00698065: { // 0x698065: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00698068: { // 0x698068: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069806a: { // 0x69806a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069806d: { // 0x69806d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00698071: { // 0x698071: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00698073: { // 0x698073: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698074: { // 0x698074: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698076: { // 0x698076: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0069807a: { // 0x69807a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069807c: { // 0x69807c: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069807e: { // 0x69807e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698080: { // 0x698080: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698081: { // 0x698081: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698087: { // 0x698087: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698089: { // 0x698089: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069808b: { // 0x69808b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069808d: { // 0x69808d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069808e: { // 0x69808e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698094: { // 0x698094: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698096: { // 0x698096: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698098: { // 0x698098: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809b: { // 0x69809b: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809e: { // 0x69809e: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L006980a4: { // 0x6980a4: 7c08 JL 0x006980ae
    if(integer::condition("JL",flags)) goto L006980ae;
  }
  L006980a6: { // 0x6980a6: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L006980ae: { // 0x6980ae: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006980b2: { // 0x6980b2: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L006980b8: { // 0x6980b8: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006980bc: { // 0x6980bc: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L006980c2: { // 0x6980c2: e889290d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914247u); flags=s.arithmetic_flags;
  }
  L006980c7: { // 0x6980c7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006980c9: { // 0x6980c9: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006980cd: { // 0x6980cd: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980cf: { // 0x6980cf: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980d2: { // 0x6980d2: 8b8db0000000 MOV ECX,dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L006980d8: { // 0x6980d8: 8badb4000000 MOV EBP,dword ptr [EBP + 0xb4]
    s.bp = m.r32((s.bp+0x000000b4u));
  }
  L006980de: { // 0x6980de: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L006980e0: { // 0x6980e0: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006980e3: { // 0x6980e3: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006980e5: { // 0x6980e5: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L006980e7: { // 0x6980e7: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980e9: { // 0x6980e9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006980eb: { // 0x6980eb: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980ee: { // 0x6980ee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006980f0: { // 0x6980f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006980f1: { // 0x6980f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006980f2: { // 0x6980f2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006980f3: { // 0x6980f3: 81f998feffff CMP ECX,0xfffffe98
    (void)integer::sub(s.cx,0xfffffe98u,32,flags);
  }
  L006980f9: { // 0x6980f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006980fa: { // 0x6980fa: 7d08 JGE 0x00698104
    if(integer::condition("JGE",flags)) goto L00698104;
  }
  L006980fc: { // 0x6980fc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006980fe: { // 0x6980fe: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698101: { // 0x698101: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00698104: { // 0x698104: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
  L0069810a: { // 0x69810a: 81c268010000 ADD EDX,0x168
    s.dx = integer::add(s.dx,0x00000168u,32,flags);
  }
  L00698110: { // 0x698110: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00698112: { // 0x698112: 7e08 JLE 0x0069811c
    if(integer::condition("JLE",flags)) goto L0069811c;
  }
  L00698114: { // 0x698114: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698116: { // 0x698116: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698119: { // 0x698119: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069811c: { // 0x69811c: 3d4cffffff CMP EAX,0xffffff4c
    (void)integer::sub(s.ax,0xffffff4cu,32,flags);
  }
  L00698121: { // 0x698121: 7d08 JGE 0x0069812b
    if(integer::condition("JGE",flags)) goto L0069812b;
  }
  L00698123: { // 0x698123: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698125: { // 0x698125: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698128: { // 0x698128: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069812b: { // 0x69812b: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L00698131: { // 0x698131: 81c1b4000000 ADD ECX,0xb4
    s.cx = integer::add(s.cx,0x000000b4u,32,flags);
  }
  L00698137: { // 0x698137: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00698139: { // 0x698139: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0069813c: { // 0x69813c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069813f: { // 0x69813f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00316970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00716970: { // 0x716970: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00716973: { // 0x716973: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00716974: { // 0x716974: 8b32 MOV ESI,dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  L00716976: { // 0x716976: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00716977: { // 0x716977: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00716979: { // 0x716979: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L0071697b: { // 0x71697b: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0071697e: { // 0x71697e: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00716981: { // 0x716981: 68fb21d93f PUSH 0x3fd921fb
    f.push(m,0x3fd921fbu);
  }
  L00716986: { // 0x716986: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L00716988: { // 0x716988: 68182d4454 PUSH 0x54442d18
    f.push(m,0x54442d18u);
  }
  L0071698d: { // 0x71698d: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00716991: { // 0x716991: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00716995: { // 0x716995: e85637daff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,7432602u); flags=s.arithmetic_flags;
  }
  L0071699a: { // 0x71699a: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0071699e: { // 0x71699e: 68fb21d93f PUSH 0x3fd921fb
    f.push(m,0x3fd921fbu);
  }
  L007169a3: { // 0x7169a3: 68182d4454 PUSH 0x54442d18
    f.push(m,0x54442d18u);
  }
  L007169a8: { // 0x7169a8: e89337daff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,7432621u); flags=s.arithmetic_flags;
  }
  L007169ad: { // 0x7169ad: dc7c2420 FDIVR double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    reverse_divide64(s.fp,read64(m,address));
  }
  L007169b1: { // 0x7169b1: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007169b4: { // 0x7169b4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L007169b6: { // 0x7169b6: 0f849f000000 JZ 0x00716a5b
    if(integer::condition("JZ",flags)) goto L00716a5b;
  }
  L007169bc: { // 0x7169bc: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L007169c0: { // 0x7169c0: da74240c FIDIV dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.divide_integer32(m.r32(address));
  }
  L007169c4: { // 0x7169c4: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L007169ca: { // 0x7169ca: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L007169cc: { // 0x7169cc: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L007169ce: { // 0x7169ce: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L007169d0: { // 0x7169d0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007169d2: { // 0x7169d2: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L007169d4: { // 0x7169d4: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007169d7: { // 0x7169d7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007169d9: { // 0x7169d9: 741c JZ 0x007169f7
    if(integer::condition("JZ",flags)) goto L007169f7;
  }
  L007169db: { // 0x7169db: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007169de: { // 0x7169de: 751c JNZ 0x007169fc
    if(integer::condition("JNZ",flags)) goto L007169fc;
  }
  L007169e0: { // 0x7169e0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007169e2: { // 0x7169e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007169e3: { // 0x7169e3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L007169e5: { // 0x7169e5: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L007169e8: { // 0x7169e8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007169e9: { // 0x7169e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007169ea: { // 0x7169ea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007169ec: { // 0x7169ec: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
  L007169ee: { // 0x7169ee: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007169f0: { // 0x7169f0: 83c005 ADD EAX,0x5
    s.ax = integer::add(s.ax,0x00000005u,32,flags);
  }
  L007169f3: { // 0x7169f3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007169f6: { // 0x7169f6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007169f7: { // 0x7169f7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007169fa: { // 0x7169fa: 7426 JZ 0x00716a22
    if(integer::condition("JZ",flags)) goto L00716a22;
  }
  L007169fc: { // 0x7169fc: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L007169fe: { // 0x7169fe: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00716a00: { // 0x716a00: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00716a02: { // 0x716a02: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00716a04: { // 0x716a04: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00716a06: { // 0x716a06: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00716a09: { // 0x716a09: 7517 JNZ 0x00716a22
    if(integer::condition("JNZ",flags)) goto L00716a22;
  }
  L00716a0b: { // 0x716a0b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00716a0d: { // 0x716a0d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00716a0e: { // 0x716a0e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00716a10: { // 0x716a10: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L00716a13: { // 0x716a13: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00716a14: { // 0x716a14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00716a15: { // 0x716a15: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00716a17: { // 0x716a17: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
  L00716a19: { // 0x716a19: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00716a1b: { // 0x716a1b: 83c006 ADD EAX,0x6
    s.ax = integer::add(s.ax,0x00000006u,32,flags);
  }
  L00716a1e: { // 0x716a1e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00716a21: { // 0x716a21: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00716a22: { // 0x716a22: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00716a24: { // 0x716a24: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00716a26: { // 0x716a26: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00716a28: { // 0x716a28: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00716a2a: { // 0x716a2a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00716a2c: { // 0x716a2c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00716a2f: { // 0x716a2f: 7428 JZ 0x00716a59
    if(integer::condition("JZ",flags)) goto L00716a59;
  }
  L00716a31: { // 0x716a31: dd0578857800 FLD double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.load64(read64(m,address));
  }
  L00716a37: { // 0x716a37: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L00716a39: { // 0x716a39: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L00716a3b: { // 0x716a3b: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L00716a3d: { // 0x716a3d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00716a3f: { // 0x716a3f: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00716a42: { // 0x716a42: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00716a44: { // 0x716a44: 7517 JNZ 0x00716a5d
    if(integer::condition("JNZ",flags)) goto L00716a5d;
  }
  L00716a46: { // 0x716a46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00716a48: { // 0x716a48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00716a49: { // 0x716a49: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00716a4b: { // 0x716a4b: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L00716a4e: { // 0x716a4e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00716a4f: { // 0x716a4f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00716a50: { // 0x716a50: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
  L00716a52: { // 0x716a52: 83c007 ADD EAX,0x7
    s.ax = integer::add(s.ax,0x00000007u,32,flags);
  }
  L00716a55: { // 0x716a55: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00716a58: { // 0x716a58: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00716a59: { // 0x716a59: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00716a5b: { // 0x716a5b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00716a5d: { // 0x716a5d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00716a5f: { // 0x716a5f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00716a61: { // 0x716a61: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L00716a64: { // 0x716a64: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00716a65: { // 0x716a65: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00716a66: { // 0x716a66: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
  L00716a68: { // 0x716a68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00716a69: { // 0x716a69: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00716a6c: { // 0x716a6c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00716a6f: { // 0x716a6f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018e180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058e180: { // 0x58e180: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0058e183: { // 0x58e183: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058e186: { // 0x58e186: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058e187: { // 0x58e187: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0058e18b: { // 0x58e18b: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e18e: { // 0x58e18e: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058e191: { // 0x58e191: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e194: { // 0x58e194: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0058e196: { // 0x58e196: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e198: { // 0x58e198: d902 FLD float ptr [EDX]
    const auto address=(s.dx);
    s.fp.load32(m.r32(address));
  }
  L0058e19a: { // 0x58e19a: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e19c: { // 0x58e19c: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e19e: { // 0x58e19e: d8420c FADD float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1a1: { // 0x58e1a1: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1a5: { // 0x58e1a5: d94210 FLD float ptr [EDX + 0x10]
    const auto address=(s.dx+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058e1a8: { // 0x58e1a8: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1aa: { // 0x58e1aa: d94218 FLD float ptr [EDX + 0x18]
    const auto address=(s.dx+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0058e1ad: { // 0x58e1ad: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b0: { // 0x58e1b0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1b2: { // 0x58e1b2: d94214 FLD float ptr [EDX + 0x14]
    const auto address=(s.dx+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058e1b5: { // 0x58e1b5: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b8: { // 0x58e1b8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ba: { // 0x58e1ba: d8421c FADD float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1bd: { // 0x58e1bd: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1c1: { // 0x58e1c1: d94220 FLD float ptr [EDX + 0x20]
    const auto address=(s.dx+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c4: { // 0x58e1c4: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1c6: { // 0x58e1c6: d94228 FLD float ptr [EDX + 0x28]
    const auto address=(s.dx+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c9: { // 0x58e1c9: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1cc: { // 0x58e1cc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ce: { // 0x58e1ce: d94224 FLD float ptr [EDX + 0x24]
    const auto address=(s.dx+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058e1d1: { // 0x58e1d1: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1d4: { // 0x58e1d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058e1d5: { // 0x58e1d5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1d7: { // 0x58e1d7: d8422c FADD float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1da: { // 0x58e1da: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0058e1de: { // 0x58e1de: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058e1e0: { // 0x58e1e0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0058e1e4: { // 0x58e1e4: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1e8: { // 0x58e1e8: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0058e1eb: { // 0x58e1eb: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0058e1ef: { // 0x58e1ef: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0058e1f2: { // 0x58e1f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0058e1f5: { // 0x58e1f5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0029e2c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e2c0: { // 0x69e2c0: a118a98100 MOV EAX,[0x0081a918]
    s.ax = m.r32((0x0081a918u));
  }
  L0069e2c5: { // 0x69e2c5: 8b0d10a98100 MOV ECX,dword ptr [0x0081a910]
    s.cx = m.r32((0x0081a910u));
  }
  L0069e2cb: { // 0x69e2cb: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  L0069e2cd: { // 0x69e2cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069e2ce: { // 0x69e2ce: 8b1d78198200 MOV EBX,dword ptr [0x00821978]
    s.bx = m.r32((0x00821978u));
  }
  L0069e2d4: { // 0x69e2d4: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069e2d6: { // 0x69e2d6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069e2d7: { // 0x69e2d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e2d8: { // 0x69e2d8: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e2db: { // 0x69e2db: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e2dc: { // 0x69e2dc: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0069e2e0: { // 0x69e2e0: 8d3480 LEA ESI,[EAX + EAX*0x4]
    s.si = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e2e3: { // 0x69e2e3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069e2e5: { // 0x69e2e5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e2e6: { // 0x69e2e6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e2e8: { // 0x69e2e8: 8b151ca98100 MOV EDX,dword ptr [0x0081a91c]
    s.dx = m.r32((0x0081a91cu));
  }
  L0069e2ee: { // 0x69e2ee: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e2f0: { // 0x69e2f0: 8d3c70 LEA EDI,[EAX + ESI*0x2]
    s.di = (s.ax+(s.si * 0x00000002u));
  }
  L0069e2f3: { // 0x69e2f3: a120a98100 MOV EAX,[0x0081a920]
    s.ax = m.r32((0x0081a920u));
  }
  L0069e2f8: { // 0x69e2f8: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e2fb: { // 0x69e2fb: 8d3480 LEA ESI,[EAX + EAX*0x4]
    s.si = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e2fe: { // 0x69e2fe: 8d4451fb LEA EAX,[ECX + EDX*0x2 + -0x5]
    s.ax = (s.cx+(s.dx * 0x00000002u)-0x00000005u);
  }
  L0069e302: { // 0x69e302: c1e602 SHL ESI,0x2
    s.si = integer::shift(s.si,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069e305: { // 0x69e305: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e308: { // 0x69e308: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L0069e30a: { // 0x69e30a: 8b1d7c198200 MOV EBX,dword ptr [0x0082197c]
    s.bx = m.r32((0x0082197cu));
  }
  L0069e310: { // 0x69e310: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0069e312: { // 0x69e312: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e315: { // 0x69e315: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069e317: { // 0x69e317: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e318: { // 0x69e318: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e31a: { // 0x69e31a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e31c: { // 0x69e31c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069e31e: { // 0x69e31e: a124a98100 MOV EAX,[0x0081a924]
    s.ax = m.r32((0x0081a924u));
  }
  L0069e323: { // 0x69e323: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e326: { // 0x69e326: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e329: { // 0x69e329: 8d04850e010000 LEA EAX,[EAX*0x4 + 0x10e]
    s.ax = ((s.ax * 0x00000004u)+0x0000010eu);
  }
  L0069e330: { // 0x69e330: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e331: { // 0x69e331: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e333: { // 0x69e333: 8b5504 MOV EDX,dword ptr [EBP + 0x4]
    s.dx = m.r32((s.bp+0x00000004u));
  }
  L0069e336: { // 0x69e336: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e338: { // 0x69e338: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0069e33a: { // 0x69e33a: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0069e33c: { // 0x69e33c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0069e33e: { // 0x69e33e: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0069e340: { // 0x69e340: 7d07 JGE 0x0069e349
    if(integer::condition("JGE",flags)) goto L0069e349;
  }
  L0069e342: { // 0x69e342: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0069e344: { // 0x69e344: 894d04 MOV dword ptr [EBP + 0x4],ECX
    m.w32((s.bp+0x00000004u), s.cx);
  }
  L0069e347: { // 0x69e347: eb09 JMP 0x0069e352
    goto L0069e352;
  }
  L0069e349: { // 0x69e349: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0069e34b: { // 0x69e34b: 7e05 JLE 0x0069e352
    if(integer::condition("JLE",flags)) goto L0069e352;
  }
  L0069e34d: { // 0x69e34d: 894504 MOV dword ptr [EBP + 0x4],EAX
    m.w32((s.bp+0x00000004u), s.ax);
  }
  L0069e350: { // 0x69e350: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0069e352: { // 0x69e352: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0069e355: { // 0x69e355: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0069e357: { // 0x69e357: 7d0c JGE 0x0069e365
    if(integer::condition("JGE",flags)) goto L0069e365;
  }
  L0069e359: { // 0x69e359: 897d00 MOV dword ptr [EBP],EDI
    m.w32((s.bp), s.di);
  }
  L0069e35c: { // 0x69e35c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e35d: { // 0x69e35d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e35e: { // 0x69e35e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e35f: { // 0x69e35f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0069e361: { // 0x69e361: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e362: { // 0x69e362: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0069e365: { // 0x69e365: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0069e367: { // 0x69e367: 7e0c JLE 0x0069e375
    if(integer::condition("JLE",flags)) goto L0069e375;
  }
  L0069e369: { // 0x69e369: 897500 MOV dword ptr [EBP],ESI
    m.w32((s.bp), s.si);
  }
  L0069e36c: { // 0x69e36c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e36d: { // 0x69e36d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e36e: { // 0x69e36e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e36f: { // 0x69e36f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0069e371: { // 0x69e371: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e372: { // 0x69e372: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0069e375: { // 0x69e375: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e376: { // 0x69e376: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e377: { // 0x69e377: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0069e379: { // 0x69e379: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e37a: { // 0x69e37a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e37b: { // 0x69e37b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0029e7b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e7b0: { // 0x69e7b0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0069e7b3: { // 0x69e7b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e7b4: { // 0x69e7b4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0069e7b6: { // 0x69e7b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e7b7: { // 0x69e7b7: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069e7bf: { // 0x69e7bf: 8b8e640d0000 MOV ECX,dword ptr [ESI + 0xd64]
    s.cx = m.r32((s.si+0x00000d64u));
  }
  L0069e7c5: { // 0x69e7c5: 8bbe680d0000 MOV EDI,dword ptr [ESI + 0xd68]
    s.di = m.r32((s.si+0x00000d68u));
  }
  L0069e7cb: { // 0x69e7cb: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  L0069e7d1: { // 0x69e7d1: 89beb4000000 MOV dword ptr [ESI + 0xb4],EDI
    m.w32((s.si+0x000000b4u), s.di);
  }
  L0069e7d7: { // 0x69e7d7: a17060aa00 MOV EAX,[0x00aa6070]
    s.ax = m.r32((0x00aa6070u));
  }
  L0069e7dc: { // 0x69e7dc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e7dd: { // 0x69e7dd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e7df: { // 0x69e7df: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e7e1: { // 0x69e7e1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0069e7e3: { // 0x69e7e3: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  L0069e7e9: { // 0x69e7e9: a17460aa00 MOV EAX,[0x00aa6074]
    s.ax = m.r32((0x00aa6074u));
  }
  L0069e7ee: { // 0x69e7ee: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e7ef: { // 0x69e7ef: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e7f1: { // 0x69e7f1: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L0069e7f7: { // 0x69e7f7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069e7f9: { // 0x69e7f9: 83ea3c SUB EDX,0x3c
    s.dx = integer::sub(s.dx,0x0000003cu,32,flags);
  }
  L0069e7fc: { // 0x69e7fc: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e7fe: { // 0x69e7fe: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e800: { // 0x69e800: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L0069e804: { // 0x69e804: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069e808: { // 0x69e808: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069e80a: { // 0x69e80a: 8d96e40d0000 LEA EDX,[ESI + 0xde4]
    s.dx = (s.si+0x00000de4u);
  }
  L0069e810: { // 0x69e810: 8986b4000000 MOV dword ptr [ESI + 0xb4],EAX
    m.w32((s.si+0x000000b4u), s.ax);
  }
  L0069e816: { // 0x69e816: 83c0e2 ADD EAX,-0x1e
    s.ax = integer::add(s.ax,0xffffffe2u,32,flags);
  }
  L0069e819: { // 0x69e819: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069e81d: { // 0x69e81d: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L0069e821: { // 0x69e821: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0069e825: { // 0x69e825: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0069e829: { // 0x69e829: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e82a: { // 0x69e82a: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0069e82e: { // 0x69e82e: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069e832: { // 0x69e832: e849f9eeff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6940727u); flags=s.arithmetic_flags;
  }
  L0069e837: { // 0x69e837: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069e839: { // 0x69e839: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0069e83d: { // 0x69e83d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0069e840: { // 0x69e840: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0069e844: { // 0x69e844: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0069e848: { // 0x69e848: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0069e84b: { // 0x69e84b: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e84f: { // 0x69e84f: e8fcc10c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6940756u); flags=s.arithmetic_flags;
  }
  L0069e854: { // 0x69e854: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0069e858: { // 0x69e858: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069e85a: { // 0x69e85a: e8f1c10c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6940767u); flags=s.arithmetic_flags;
  }
  L0069e85f: { // 0x69e85f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069e861: { // 0x69e861: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e863: { // 0x69e863: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e864: { // 0x69e864: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069e86a: { // 0x69e86a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e86b: { // 0x69e86b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069e86d: { // 0x69e86d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e870: { // 0x69e870: 8986800d0000 MOV dword ptr [ESI + 0xd80],EAX
    m.w32((s.si+0x00000d80u), s.ax);
  }
  L0069e876: { // 0x69e876: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069e878: { // 0x69e878: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e879: { // 0x69e879: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069e87f: { // 0x69e87f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069e881: { // 0x69e881: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e884: { // 0x69e884: 8986840d0000 MOV dword ptr [ESI + 0xd84],EAX
    m.w32((s.si+0x00000d84u), s.ax);
  }
  L0069e88a: { // 0x69e88a: 8b0d7060aa00 MOV ECX,dword ptr [0x00aa6070]
    s.cx = m.r32((0x00aa6070u));
  }
  L0069e890: { // 0x69e890: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  L0069e895: { // 0x69e895: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0069e897: { // 0x69e897: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0069e899: { // 0x69e899: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  L0069e89e: { // 0x69e89e: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e8a1: { // 0x69e8a1: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0069e8a3: { // 0x69e8a3: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0069e8a6: { // 0x69e8a6: 8d540a02 LEA EDX,[EDX + ECX*0x1 + 0x2]
    s.dx = (s.dx+(s.cx * 0x00000001u)+0x00000002u);
  }
  L0069e8aa: { // 0x69e8aa: 8996880d0000 MOV dword ptr [ESI + 0xd88],EDX
    m.w32((s.si+0x00000d88u), s.dx);
  }
  L0069e8b0: { // 0x69e8b0: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L0069e8b6: { // 0x69e8b6: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0069e8b8: { // 0x69e8b8: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0069e8ba: { // 0x69e8ba: c1fa03 SAR EDX,0x3
    s.dx = integer::shift(s.dx,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e8bd: { // 0x69e8bd: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0069e8bf: { // 0x69e8bf: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0069e8c2: { // 0x69e8c2: 8d4c0204 LEA ECX,[EDX + EAX*0x1 + 0x4]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000004u);
  }
  L0069e8c6: { // 0x69e8c6: 898e8c0d0000 MOV dword ptr [ESI + 0xd8c],ECX
    m.w32((s.si+0x00000d8cu), s.cx);
  }
  L0069e8cc: { // 0x69e8cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e8cd: { // 0x69e8cd: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0069e8d0: { // 0x69e8d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697fb0: { // 0x697fb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00697fb3: { // 0x697fb3: 81f9d8020000 CMP ECX,0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  L00697fb9: { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L00697fbd: { // 0x697fbd: c744240000000000 MOV dword ptr [ESP],0x0
    m.w32((f.sp), 0x00000000u);
  }
  L00697fc5: { // 0x697fc5: 7c08 JL 0x00697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  L00697fc7: { // 0x697fc7: c744240001000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00697fd3: { // 0x697fd3: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697fd9: { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697fdd: { // 0x697fdd: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697fe3: { // 0x697fe3: e8682a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914024u); flags=s.arithmetic_flags;
  }
  L00697fe8: { // 0x697fe8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00697feb: { // 0x697feb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0013b210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0053b210: { // 0x53b210: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L0053b213: { // 0x53b213: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0053b214: { // 0x53b214: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053b215: { // 0x53b215: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0053b219: { // 0x53b219: e8421c0500 CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,5485086u); flags=s.arithmetic_flags;
  }
  L0053b21e: { // 0x53b21e: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L0053b222: { // 0x53b222: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0053b226: { // 0x53b226: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0053b227: { // 0x53b227: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L0053b22a: { // 0x53b22a: 81c1e0020000 ADD ECX,0x2e0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  L0053b230: { // 0x53b230: e81bd6f7ff CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,5485109u); flags=s.arithmetic_flags;
  }
  L0053b235: { // 0x53b235: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0053b237: { // 0x53b237: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L0053b23a: { // 0x53b23a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0053b23b: { // 0x53b23b: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0053b23d: { // 0x53b23d: 83e11f AND ECX,0x1f
    s.cx = integer::logical((s.cx)&(0x0000001fu),32,flags);
  }
  L0053b240: { // 0x53b240: 83e908 SUB ECX,0x8
    s.cx = integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0053b243: { // 0x53b243: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0053b247: { // 0x53b247: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0053b248: { // 0x53b248: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0053b24c: { // 0x53b24c: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0053b250: { // 0x53b250: dc0d90807800 FMUL double ptr [0x00788090]
    const auto address=(0x00788090u);
    s.fp.multiply64(read64(m,address));
  }
  L0053b256: { // 0x53b256: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0053b259: { // 0x53b259: e842250500 CALL 0x0058d7a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d7a0u,5485150u); flags=s.arithmetic_flags;
  }
  L0053b25e: { // 0x53b25e: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L0053b262: { // 0x53b262: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0053b264: { // 0x53b264: 7430 JZ 0x0053b296
    if(integer::condition("JZ",flags)) goto L0053b296;
  }
  L0053b266: { // 0x53b266: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0053b268: { // 0x53b268: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0053b26b: { // 0x53b26b: 7429 JZ 0x0053b296
    if(integer::condition("JZ",flags)) goto L0053b296;
  }
  L0053b26d: { // 0x53b26d: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L0053b270: { // 0x53b270: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0053b272: { // 0x53b272: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L0053b275: { // 0x53b275: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L0053b279: { // 0x53b279: 81c1e0020000 ADD ECX,0x2e0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  L0053b27f: { // 0x53b27f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0053b280: { // 0x53b280: e8cbd5f7ff CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,5485189u); flags=s.arithmetic_flags;
  }
  L0053b285: { // 0x53b285: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0053b287: { // 0x53b287: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0053b289: { // 0x53b289: c1e80a SHR EAX,0xa
    s.ax = integer::shift(s.ax,0x0000000au,32,flags,integer::Shift::right);
  }
  L0053b28c: { // 0x53b28c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0053b28d: { // 0x53b28d: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L0053b28f: { // 0x53b28f: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  L0053b292: { // 0x53b292: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  L0053b294: { // 0x53b294: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0053b296: { // 0x53b296: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0053b29a: { // 0x53b29a: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0053b29f: { // 0x53b29f: 8d74240c LEA ESI,[ESP + 0xc]
    s.si = (f.sp+0x0000000cu);
  }
  L0053b2a3: { // 0x53b2a3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0053b2a5: { // 0x53b2a5: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0053b2a7: { // 0x53b2a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053b2a8: { // 0x53b2a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053b2a9: { // 0x53b2a9: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0053b2ac: { // 0x53b2ac: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0018cc10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058cc10: { // 0x58cc10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058cc11: { // 0x58cc11: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L0058cc15: { // 0x58cc15: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0058cc17: { // 0x58cc17: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058cc18: { // 0x58cc18: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0058cc1d: { // 0x58cc1d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0058cc1f: { // 0x58cc1f: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0058cc21: { // 0x58cc21: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058cc22: { // 0x58cc22: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058cc23: { // 0x58cc23: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00005110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405110: { // 0x405110: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  L00405115: { // 0x405115: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00405117: { // 0x405117: 7503 JNZ 0x0040511c
    if(integer::condition("JNZ",flags)) goto L0040511c;
  }
  L00405119: { // 0x405119: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040511b: { // 0x40511b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0040511c: { // 0x40511c: 8b4150 MOV EAX,dword ptr [ECX + 0x50]
    s.ax = m.r32((s.cx+0x00000050u));
  }
  L0040511f: { // 0x40511f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00005140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405140: { // 0x405140: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  L00405145: { // 0x405145: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00405147: { // 0x405147: 7503 JNZ 0x0040514c
    if(integer::condition("JNZ",flags)) goto L0040514c;
  }
  L00405149: { // 0x405149: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040514b: { // 0x40514b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0040514c: { // 0x40514c: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L0040514f: { // 0x40514f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018e220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058e220: { // 0x58e220: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L0058e223: { // 0x58e223: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0058e225: { // 0x58e225: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058e226: { // 0x58e226: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0058e228: { // 0x58e228: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058e229: { // 0x58e229: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L0058e22d: { // 0x58e22d: 8b4a10 MOV ECX,dword ptr [EDX + 0x10]
    s.cx = m.r32((s.dx+0x00000010u));
  }
  L0058e230: { // 0x58e230: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058e234: { // 0x58e234: d84a0c FMUL float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e237: { // 0x58e237: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0058e23b: { // 0x58e23b: 8b4a20 MOV ECX,dword ptr [EDX + 0x20]
    s.cx = m.r32((s.dx+0x00000020u));
  }
  L0058e23e: { // 0x58e23e: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0058e242: { // 0x58e242: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0058e245: { // 0x58e245: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058e249: { // 0x58e249: d84a2c FMUL float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e24c: { // 0x58e24c: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0058e250: { // 0x58e250: 8b4a14 MOV ECX,dword ptr [EDX + 0x14]
    s.cx = m.r32((s.dx+0x00000014u));
  }
  L0058e253: { // 0x58e253: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0058e257: { // 0x58e257: 8b4a24 MOV ECX,dword ptr [EDX + 0x24]
    s.cx = m.r32((s.dx+0x00000024u));
  }
  L0058e25a: { // 0x58e25a: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e25c: { // 0x58e25c: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058e260: { // 0x58e260: d84a1c FMUL float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e263: { // 0x58e263: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0058e267: { // 0x58e267: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0058e26a: { // 0x58e26a: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0058e26e: { // 0x58e26e: 8b4a18 MOV ECX,dword ptr [EDX + 0x18]
    s.cx = m.r32((s.dx+0x00000018u));
  }
  L0058e271: { // 0x58e271: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e273: { // 0x58e273: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0058e277: { // 0x58e277: 8b4a28 MOV ECX,dword ptr [EDX + 0x28]
    s.cx = m.r32((s.dx+0x00000028u));
  }
  L0058e27a: { // 0x58e27a: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0058e27e: { // 0x58e27e: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0058e283: { // 0x58e283: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0058e285: { // 0x58e285: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e289: { // 0x58e289: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0058e28d: { // 0x58e28d: d84a0c FMUL float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e290: { // 0x58e290: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058e294: { // 0x58e294: d84a2c FMUL float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e297: { // 0x58e297: 8d742408 LEA ESI,[ESP + 0x8]
    s.si = (f.sp+0x00000008u);
  }
  L0058e29b: { // 0x58e29b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0058e29d: { // 0x58e29d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e29f: { // 0x58e29f: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L0058e2a3: { // 0x58e2a3: d84a1c FMUL float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e2a6: { // 0x58e2a6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e2a8: { // 0x58e2a8: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0058e2aa: { // 0x58e2aa: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e2ae: { // 0x58e2ae: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0058e2b2: { // 0x58e2b2: d84a0c FMUL float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e2b5: { // 0x58e2b5: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L0058e2b9: { // 0x58e2b9: d84a2c FMUL float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e2bc: { // 0x58e2bc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e2be: { // 0x58e2be: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0058e2c2: { // 0x58e2c2: d84a1c FMUL float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058e2c5: { // 0x58e2c5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e2c7: { // 0x58e2c7: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0058e2c9: { // 0x58e2c9: d95c2434 FSTP float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e2cd: { // 0x58e2cd: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0058e2cf: { // 0x58e2cf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058e2d0: { // 0x58e2d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058e2d1: { // 0x58e2d1: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0058e2d4: { // 0x58e2d4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018dad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058dad0: { // 0x58dad0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0058dad3: { // 0x58dad3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0058dad7: { // 0x58dad7: d94104 FLD float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058dada: { // 0x58dada: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058dadd: { // 0x58dadd: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058dae0: { // 0x58dae0: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058dae3: { // 0x58dae3: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058dae5: { // 0x58dae5: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    s.fp.load32(m.r32(address));
  }
  L0058dae7: { // 0x58dae7: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    s.fp.multiply32(m.r32(address));
  }
  L0058dae9: { // 0x58dae9: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058daeb: { // 0x58daeb: d95c2400 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058daef: { // 0x58daef: d94114 FLD float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058daf2: { // 0x58daf2: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058daf5: { // 0x58daf5: d94110 FLD float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058daf8: { // 0x58daf8: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    s.fp.multiply32(m.r32(address));
  }
  L0058dafa: { // 0x58dafa: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0058dafe: { // 0x58dafe: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058db00: { // 0x58db00: d94118 FLD float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0058db03: { // 0x58db03: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058db06: { // 0x58db06: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058db08: { // 0x58db08: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058db0c: { // 0x58db0c: d94124 FLD float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058db0f: { // 0x58db0f: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058db12: { // 0x58db12: d94120 FLD float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058db15: { // 0x58db15: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    s.fp.multiply32(m.r32(address));
  }
  L0058db17: { // 0x58db17: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058db19: { // 0x58db19: d94128 FLD float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0058db1c: { // 0x58db1c: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058db1f: { // 0x58db1f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0058db23: { // 0x58db23: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0058db25: { // 0x58db25: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058db27: { // 0x58db27: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058db29: { // 0x58db29: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0058db2d: { // 0x58db2d: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058db31: { // 0x58db31: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0058db34: { // 0x58db34: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0058db38: { // 0x58db38: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0058db3b: { // 0x58db3b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0058db3e: { // 0x58db3e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0030e420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0070e420: { // 0x70e420: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0070e424: { // 0x70e424: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L0070e427: { // 0x70e427: 8b4914 MOV ECX,dword ptr [ECX + 0x14]
    s.cx = m.r32((s.cx+0x00000014u));
  }
  L0070e42a: { // 0x70e42a: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0070e42d: { // 0x70e42d: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0070e430: { // 0x70e430: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0070e434: { // 0x70e434: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0070e436: { // 0x70e436: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0070e439: { // 0x70e439: 8d04d0 LEA EAX,[EAX + EDX*0x8]
    s.ax = (s.ax+(s.dx * 0x00000008u));
  }
  L0070e43c: { // 0x70e43c: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  L0070e43f: { // 0x70e43f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00310660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00710660: { // 0x710660: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L00710663: { // 0x710663: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00710664: { // 0x710664: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00710665: { // 0x710665: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00710667: { // 0x710667: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L0071066b: { // 0x71066b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0071066c: { // 0x71066c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0071066d: { // 0x71066d: d94500 FLD float ptr [EBP]
    const auto address=(s.bp);
    s.fp.load32(m.r32(address));
  }
  L00710670: { // 0x710670: d802 FADD float ptr [EDX]
    const auto address=(s.dx);
    s.fp.add32(m.r32(address));
  }
  L00710672: { // 0x710672: 8b349de8377e00 MOV ESI,dword ptr [EBX*0x4 + 0x7e37e8]
    s.si = m.r32(((s.bx * 0x00000004u)+0x007e37e8u));
  }
  L00710679: { // 0x710679: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0071067c: { // 0x71067c: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00710680: { // 0x710680: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L00710683: { // 0x710683: d84504 FADD float ptr [EBP + 0x4]
    const auto address=(s.bp+0x00000004u);
    s.fp.add32(m.r32(address));
  }
  L00710686: { // 0x710686: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0071068a: { // 0x71068a: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0071068d: { // 0x71068d: d84508 FADD float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.add32(m.r32(address));
  }
  L00710690: { // 0x710690: d9542420 FST float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00710694: { // 0x710694: d84c2420 FMUL float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply32(m.r32(address));
  }
  L00710698: { // 0x710698: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0071069c: { // 0x71069c: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L007106a0: { // 0x7106a0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L007106a2: { // 0x7106a2: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L007106a6: { // 0x7106a6: d84c241c FMUL float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
  L007106aa: { // 0x7106aa: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L007106ac: { // 0x7106ac: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007106af: { // 0x7106af: e8cc99daff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,7407284u); flags=s.arithmetic_flags;
  }
  L007106b4: { // 0x7106b4: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L007106ba: { // 0x7106ba: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007106bd: { // 0x7106bd: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007106bf: { // 0x7106bf: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L007106c2: { // 0x7106c2: 7532 JNZ 0x007106f6
    if(integer::condition("JNZ",flags)) goto L007106f6;
  }
  L007106c4: { // 0x7106c4: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L007106c8: { // 0x7106c8: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L007106ca: { // 0x7106ca: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L007106ce: { // 0x7106ce: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L007106d2: { // 0x7106d2: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L007106d4: { // 0x7106d4: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L007106d8: { // 0x7106d8: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L007106dc: { // 0x7106dc: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L007106e0: { // 0x7106e0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L007106e4: { // 0x7106e4: d87c2418 FDIVR float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    reverse_divide32(s.fp,m.r32(address));
  }
  L007106e8: { // 0x7106e8: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L007106ec: { // 0x7106ec: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L007106f0: { // 0x7106f0: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L007106f4: { // 0x7106f4: eb16 JMP 0x0071070c
    goto L0071070c;
  }
  L007106f6: { // 0x7106f6: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L007106fa: { // 0x7106fa: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L007106fe: { // 0x7106fe: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00710702: { // 0x710702: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00710706: { // 0x710706: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00710708: { // 0x710708: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0071070c: { // 0x71070c: 8b1c9dfc377e00 MOV EBX,dword ptr [EBX*0x4 + 0x7e37fc]
    s.bx = m.r32(((s.bx * 0x00000004u)+0x007e37fcu));
  }
  L00710713: { // 0x710713: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00710715: { // 0x710715: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00710717: { // 0x710717: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0071071b: { // 0x71071b: 0f8eab000000 JLE 0x007107cc
    if(integer::condition("JLE",flags)) goto L007107cc;
  }
  L00710721: { // 0x710721: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L00710724: { // 0x710724: d94604 FLD float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L00710727: { // 0x710727: d84d08 FMUL float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0071072a: { // 0x71072a: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
  L0071072c: { // 0x71072c: d84d04 FMUL float ptr [EBP + 0x4]
    const auto address=(s.bp+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0071072f: { // 0x71072f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00710731: { // 0x710731: d946fc FLD float ptr [ESI + -0x4]
    const auto address=(s.si-0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L00710734: { // 0x710734: d84d00 FMUL float ptr [EBP]
    const auto address=(s.bp);
    s.fp.multiply32(m.r32(address));
  }
  L00710737: { // 0x710737: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00710739: { // 0x710739: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L0071073d: { // 0x71073d: d84efc FMUL float ptr [ESI + -0x4]
    const auto address=(s.si-0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L00710740: { // 0x710740: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L00710744: { // 0x710744: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L00710746: { // 0x710746: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00710748: { // 0x710748: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0071074c: { // 0x71074c: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0071074f: { // 0x71074f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00710751: { // 0x710751: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00710753: { // 0x710753: d84c2438 FMUL float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.multiply32(m.r32(address));
  }
  L00710757: { // 0x710757: d86c2438 FSUBR float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    ra2::platform::x87_b61::reverse_subtract32(s.fp,m.r32(address));
  }
  L0071075b: { // 0x71075b: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L0071075d: { // 0x71075d: d8f9 FDIVR ST0,ST1
    numeric_b88::detail::reg<0xd8f9>(s.fp);
  }
  L0071075f: { // 0x71075f: d95c243c FSTP float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00710763: { // 0x710763: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00710765: { // 0x710765: d944243c FLD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load32(m.r32(address));
  }
  L00710769: { // 0x710769: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0071076f: { // 0x71076f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00710771: { // 0x710771: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00710774: { // 0x710774: 7408 JZ 0x0071077e
    if(integer::condition("JZ",flags)) goto L0071077e;
  }
  L00710776: { // 0x710776: c744243c00000000 MOV dword ptr [ESP + 0x3c],0x0
    m.w32((f.sp+0x0000003cu), 0x00000000u);
  }
  L0071077e: { // 0x71077e: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L00710784: { // 0x710784: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00710786: { // 0x710786: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00710789: { // 0x710789: 7408 JZ 0x00710793
    if(integer::condition("JZ",flags)) goto L00710793;
  }
  L0071078b: { // 0x71078b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0071078d: { // 0x71078d: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L00710793: { // 0x710793: d844243c FADD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.add32(m.r32(address));
  }
  L00710797: { // 0x710797: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0071079d: { // 0x71079d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0071079f: { // 0x71079f: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007107a2: { // 0x7107a2: 740b JZ 0x007107af
    if(integer::condition("JZ",flags)) goto L007107af;
  }
  L007107a4: { // 0x7107a4: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007107a6: { // 0x7107a6: c6879008ae0000 MOV byte ptr [EDI + 0xae0890],0x0
    m.w8((s.di+0x00ae0890u), 0x00000000u);
  }
  L007107ad: { // 0x7107ad: eb11 JMP 0x007107c0
    goto L007107c0;
  }
  L007107af: { // 0x7107af: d80dd0987900 FMUL float ptr [0x007998d0]
    const auto address=(0x007998d0u);
    s.fp.multiply32(m.r32(address));
  }
  L007107b5: { // 0x7107b5: e896a20500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7407546u); flags=s.arithmetic_flags;
  }
  L007107ba: { // 0x7107ba: 88879008ae00 MOV byte ptr [EDI + 0xae0890],AL
    m.w8((s.di+0x00ae0890u), (s.ax & 0xffu));
  }
  L007107c0: { // 0x7107c0: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L007107c1: { // 0x7107c1: 83c60c ADD ESI,0xc
    s.si = integer::add(s.si,0x0000000cu,32,flags);
  }
  L007107c4: { // 0x7107c4: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L007107c6: { // 0x7107c6: 0f8c58ffffff JL 0x00710724
    if(integer::condition("JL",flags)) goto L00710724;
  }
  L007107cc: { // 0x7107cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007107cd: { // 0x7107cd: b010 MOV AL,0x10
    s.ax = with_al(s.ax, 0x00000010u);
  }
  L007107cf: { // 0x7107cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007107d0: { // 0x7107d0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007107d1: { // 0x7107d1: a28f09ae00 MOV [0x00ae098f],AL
    m.w8((0x00ae098fu), (s.ax & 0xffu));
  }
  L007107d6: { // 0x7107d6: a28e09ae00 MOV [0x00ae098e],AL
    m.w8((0x00ae098eu), (s.ax & 0xffu));
  }
  L007107db: { // 0x7107db: a28d09ae00 MOV [0x00ae098d],AL
    m.w8((0x00ae098du), (s.ax & 0xffu));
  }
  L007107e0: { // 0x7107e0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007107e1: { // 0x7107e1: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L007107e4: { // 0x7107e4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00378fb8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778fb8: { // 0x778fb8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00778fb9: { // 0x778fb9: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00778fbb: { // 0x778fbb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778fbc: { // 0x778fbc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778fbd: { // 0x778fbd: 8a4d08 MOV CL,byte ptr [EBP + 0x8]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000008u)));
  }
  L00778fc0: { // 0x778fc0: f6c101 TEST CL,0x1
    (void)integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags);
  }
  L00778fc3: { // 0x778fc3: 740a JZ 0x00778fcf
    if(integer::condition("JZ",flags)) goto L00778fcf;
  }
  L00778fc5: { // 0x778fc5: db2d287b8100 FLD extended double ptr [0x00817b28]
    const auto address=(0x00817b28u);
    ra2::platform::x87::Raw80 v;for(unsigned k=0;k<10;++k)v.bytes[k]=m.r8(address+k);s.fp.load80(v);
  }
  L00778fcb: { // 0x778fcb: db5d08 FISTP dword ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto value=s.fp.pop_integer32();
    m.w32(address,value);
  }
  L00778fce: { // 0x778fce: 9b WAIT
    s.fp.wait();
  }
  L00778fcf: { // 0x778fcf: f6c108 TEST CL,0x8
    (void)integer::logical(((s.cx & 0xffu))&(0x00000008u),8,flags);
  }
  L00778fd2: { // 0x778fd2: 7410 JZ 0x00778fe4
    if(integer::condition("JZ",flags)) goto L00778fe4;
  }
  L00778fd4: { // 0x778fd4: 9bdfe0 FSTSW AX
    s.ax=with_ax(s.ax,s.fp.waiting_status());
  }
  L00778fd7: { // 0x778fd7: db2d287b8100 FLD extended double ptr [0x00817b28]
    const auto address=(0x00817b28u);
    ra2::platform::x87::Raw80 v;for(unsigned k=0;k<10;++k)v.bytes[k]=m.r8(address+k);s.fp.load80(v);
  }
  L00778fdd: { // 0x778fdd: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778fe0: { // 0x778fe0: 9b WAIT
    s.fp.wait();
  }
  L00778fe1: { // 0x778fe1: 9bdfe0 FSTSW AX
    s.ax=with_ax(s.ax,s.fp.waiting_status());
  }
  L00778fe4: { // 0x778fe4: f6c110 TEST CL,0x10
    (void)integer::logical(((s.cx & 0xffu))&(0x00000010u),8,flags);
  }
  L00778fe7: { // 0x778fe7: 740a JZ 0x00778ff3
    if(integer::condition("JZ",flags)) goto L00778ff3;
  }
  L00778fe9: { // 0x778fe9: db2d347b8100 FLD extended double ptr [0x00817b34]
    const auto address=(0x00817b34u);
    ra2::platform::x87::Raw80 v;for(unsigned k=0;k<10;++k)v.bytes[k]=m.r8(address+k);s.fp.load80(v);
  }
  L00778fef: { // 0x778fef: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778ff2: { // 0x778ff2: 9b WAIT
    s.fp.wait();
  }
  L00778ff3: { // 0x778ff3: f6c104 TEST CL,0x4
    (void)integer::logical(((s.cx & 0xffu))&(0x00000004u),8,flags);
  }
  L00778ff6: { // 0x778ff6: 7409 JZ 0x00779001
    if(integer::condition("JZ",flags)) goto L00779001;
  }
  L00778ff8: { // 0x778ff8: d9ee FLDZ
    numeric_b88::detail::reg<0xd9ee>(s.fp);
  }
  L00778ffa: { // 0x778ffa: d9e8 FLD1
    numeric_b88::detail::reg<0xd9e8>(s.fp);
  }
  L00778ffc: { // 0x778ffc: def1 FDIVRP
    numeric_b88::detail::reg<0xdef1>(s.fp);
  }
  L00778ffe: { // 0x778ffe: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00779000: { // 0x779000: 9b WAIT
    s.fp.wait();
  }
  L00779001: { // 0x779001: f6c120 TEST CL,0x20
    (void)integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags);
  }
  L00779004: { // 0x779004: 7406 JZ 0x0077900c
    if(integer::condition("JZ",flags)) goto L0077900c;
  }
  L00779006: { // 0x779006: d9eb FLDPI
    numeric_b88::detail::reg<0xd9eb>(s.fp);
  }
  L00779008: { // 0x779008: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0077900b: { // 0x77900b: 9b WAIT
    s.fp.wait();
  }
  L0077900c: { // 0x77900c: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077900d: { // 0x77900d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6487616u:f_0022fe40(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 6399296u:f_0021a540(m,s,child,{});break;
case 6397408u:f_00219de0(m,s,child,{});break;
case 5820000u:f_0018ce60(m,s,child,{});break;
case 6399984u:f_0021a7f0(m,s,child,{});break;
case 4950096u:f_000b8850(m,s,child,{});break;
case 5820288u:f_0018cf80(m,s,child,{});break;
case 5820336u:f_0018cfb0(m,s,child,{});break;
case 5820384u:f_0018cfe0(m,s,child,{});break;
case 5822368u:f_0018d7a0(m,s,child,{});break;
case 5822080u:f_0018d680(m,s,child,{});break;
case 5820624u:f_0018d0d0(m,s,child,{});break;
case 5820656u:f_0018d0f0(m,s,child,{});break;
case 5820704u:f_0018d120(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 4956400u:f_000ba0f0(m,s,child,{});break;
case 4956480u:f_000ba140(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4306480u:f_0001b630(m,s,child,{});break;
case 6914064u:f_00298010(m,s,child,{});break;
case 7432560u:f_00316970(m,s,child,{});break;
case 5824896u:f_0018e180(m,s,child,{});break;
case 6939328u:f_0029e2c0(m,s,child,{});break;
case 6940592u:f_0029e7b0(m,s,child,{});break;
case 6913968u:f_00297fb0(m,s,child,{});break;
case 5485072u:f_0013b210(m,s,child,{});break;
case 5819408u:f_0018cc10(m,s,child,{});break;
case 4215056u:f_00005110(m,s,child,{});break;
case 4215104u:f_00005140(m,s,child,{});break;
case 5825056u:f_0018e220(m,s,child,{});break;
case 5823184u:f_0018dad0(m,s,child,{});break;
case 7398432u:f_0030e420(m,s,child,{});break;
case 7407200u:f_00310660(m,s,child,{});break;
case 7835576u:f_00378fb8(m,s,child,{});break;
default:throw std::domain_error("numeric105 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00436c40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00436c40: { // 0x436c40: 83ec5c SUB ESP,0x5c
    f.sp = integer::sub(f.sp,0x0000005cu,32,flags);
  }
  L00436c43: { // 0x436c43: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L00436c47: { // 0x436c47: 8b54246c MOV EDX,dword ptr [ESP + 0x6c]
    s.dx = m.r32((f.sp+0x0000006cu));
  }
  L00436c4b: { // 0x436c4b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00436c4c: { // 0x436c4c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00436c4e: { // 0x436c4e: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00436c52: { // 0x436c52: 68ffff0000 PUSH 0xffff
    f.push(m,0x0000ffffu);
  }
  L00436c57: { // 0x436c57: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00436c59: { // 0x436c59: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00436c5d: { // 0x436c5d: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00436c60: { // 0x436c60: 8b4c247c MOV ECX,dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L00436c64: { // 0x436c64: 895608 MOV dword ptr [ESI + 0x8],EDX
    m.w32((s.si+0x00000008u), s.dx);
  }
  L00436c67: { // 0x436c67: 8b942480000000 MOV EDX,dword ptr [ESP + 0x80]
    s.dx = m.r32((f.sp+0x00000080u));
  }
  L00436c6e: { // 0x436c6e: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00436c71: { // 0x436c71: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L00436c75: { // 0x436c75: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00436c78: { // 0x436c78: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L00436c7b: { // 0x436c7b: db00 FILD dword ptr [EAX]
    const auto address=(s.ax);
    s.fp.load_integer32(m.r32(address));
  }
  L00436c7d: { // 0x436c7d: 8b8c2484000000 MOV ECX,dword ptr [ESP + 0x84]
    s.cx = m.r32((f.sp+0x00000084u));
  }
  L00436c84: { // 0x436c84: 680100ffff PUSH 0xffff0001
    f.push(m,0xffff0001u);
  }
  L00436c89: { // 0x436c89: d95e18 FSTP float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436c8c: { // 0x436c8c: db4004 FILD dword ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00436c8f: { // 0x436c8f: d95e1c FSTP float ptr [ESI + 0x1c]
    const auto address=(s.si+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436c92: { // 0x436c92: db4008 FILD dword ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L00436c95: { // 0x436c95: 8d4624 LEA EAX,[ESI + 0x24]
    s.ax = (s.si+0x00000024u);
  }
  L00436c98: { // 0x436c98: d95e20 FSTP float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436c9b: { // 0x436c9b: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00436c9d: { // 0x436c9d: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00436c9f: { // 0x436c9f: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00436ca2: { // 0x436ca2: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00436ca5: { // 0x436ca5: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L00436ca8: { // 0x436ca8: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00436cab: { // 0x436cab: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00436cb1: { // 0x436cb1: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L00436cb7: { // 0x436cb7: e884911f00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4418748u); flags=s.arithmetic_flags;
  }
  L00436cbc: { // 0x436cbc: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L00436cc0: { // 0x436cc0: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00436cc5: { // 0x436cc5: 68ffff0000 PUSH 0xffff
    f.push(m,0x0000ffffu);
  }
  L00436cca: { // 0x436cca: 680100ffff PUSH 0xffff0001
    f.push(m,0xffff0001u);
  }
  L00436ccf: { // 0x436ccf: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00436cd5: { // 0x436cd5: e866911f00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4418778u); flags=s.arithmetic_flags;
  }
  L00436cda: { // 0x436cda: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00436ce0: { // 0x436ce0: 68ffff0000 PUSH 0xffff
    f.push(m,0x0000ffffu);
  }
  L00436ce5: { // 0x436ce5: 680100ffff PUSH 0xffff0001
    f.push(m,0xffff0001u);
  }
  L00436cea: { // 0x436cea: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00436cf0: { // 0x436cf0: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L00436cf7: { // 0x436cf7: e844911f00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4418812u); flags=s.arithmetic_flags;
  }
  L00436cfc: { // 0x436cfc: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00436d00: { // 0x436d00: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00436d03: { // 0x436d03: db44246c FILD dword ptr [ESP + 0x6c]
    const auto address=(f.sp+0x0000006cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00436d07: { // 0x436d07: d80d907a7800 FMUL float ptr [0x00787a90]
    const auto address=(0x00787a90u);
    s.fp.multiply32(m.r32(address));
  }
  L00436d0d: { // 0x436d0d: d95c240c FSTP float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436d11: { // 0x436d11: db842488000000 FILD dword ptr [ESP + 0x88]
    const auto address=(f.sp+0x00000088u);
    s.fp.load_integer32(m.r32(address));
  }
  L00436d18: { // 0x436d18: d80d907a7800 FMUL float ptr [0x00787a90]
    const auto address=(0x00787a90u);
    s.fp.multiply32(m.r32(address));
  }
  L00436d1e: { // 0x436d1e: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436d22: { // 0x436d22: db442470 FILD dword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    s.fp.load_integer32(m.r32(address));
  }
  L00436d26: { // 0x436d26: d80d907a7800 FMUL float ptr [0x00787a90]
    const auto address=(0x00787a90u);
    s.fp.multiply32(m.r32(address));
  }
  L00436d2c: { // 0x436d2c: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436d30: { // 0x436d30: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L00436d34: { // 0x436d34: d84c2410 FMUL float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L00436d38: { // 0x436d38: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L00436d3c: { // 0x436d3c: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L00436d40: { // 0x436d40: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00436d42: { // 0x436d42: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L00436d46: { // 0x436d46: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L00436d4a: { // 0x436d4a: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00436d4c: { // 0x436d4c: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00436d4f: { // 0x436d4f: e82c330800 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4418900u); flags=s.arithmetic_flags;
  }
  L00436d54: { // 0x436d54: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00436d5a: { // 0x436d5a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00436d5d: { // 0x436d5d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00436d5f: { // 0x436d5f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00436d62: { // 0x436d62: 752a JNZ 0x00436d8e
    if(integer::condition("JNZ",flags)) goto L00436d8e;
  }
  L00436d64: { // 0x436d64: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L00436d68: { // 0x436d68: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00436d6a: { // 0x436d6a: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436d6e: { // 0x436d6e: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00436d72: { // 0x436d72: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00436d74: { // 0x436d74: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00436d78: { // 0x436d78: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436d7c: { // 0x436d7c: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00436d80: { // 0x436d80: d87c240c FDIVR float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    reverse_divide32(s.fp,m.r32(address));
  }
  L00436d84: { // 0x436d84: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436d88: { // 0x436d88: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00436d8c: { // 0x436d8c: eb0e JMP 0x00436d9c
    goto L00436d9c;
  }
  L00436d8e: { // 0x436d8e: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00436d92: { // 0x436d92: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00436d96: { // 0x436d96: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00436d9a: { // 0x436d9a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00436d9c: { // 0x436d9c: dd842484000000 FLD double ptr [ESP + 0x84]
    const auto address=(f.sp+0x00000084u);
    s.fp.load64(read64(m,address));
  }
  L00436da3: { // 0x436da3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00436da4: { // 0x436da4: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00436da8: { // 0x436da8: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00436dac: { // 0x436dac: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L00436db0: { // 0x436db0: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00436db3: { // 0x436db3: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00436db7: { // 0x436db7: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00436dbb: { // 0x436dbb: e880371e00 CALL 0x0061a540
    s.arithmetic_flags=flags; invoke(m,s,f,0x0061a540u,4419008u); flags=s.arithmetic_flags;
  }
  L00436dc0: { // 0x436dc0: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00436dc4: { // 0x436dc4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00436dc5: { // 0x436dc5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00436dc6: { // 0x436dc6: 8d4e40 LEA ECX,[ESI + 0x40]
    s.cx = (s.si+0x00000040u);
  }
  L00436dc9: { // 0x436dc9: e812301e00 CALL 0x00619de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619de0u,4419022u); flags=s.arithmetic_flags;
  }
  L00436dce: { // 0x436dce: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00436dd2: { // 0x436dd2: e889601500 CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,4419031u); flags=s.arithmetic_flags;
  }
  L00436dd7: { // 0x436dd7: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00436ddb: { // 0x436ddb: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00436ddf: { // 0x436ddf: e80c3a1e00 CALL 0x0061a7f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0061a7f0u,4419044u); flags=s.arithmetic_flags;
  }
  L00436de4: { // 0x436de4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00436de5: { // 0x436de5: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00436de9: { // 0x436de9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00436dea: { // 0x436dea: 8d4e30 LEA ECX,[ESI + 0x30]
    s.cx = (s.si+0x00000030u);
  }
  L00436ded: { // 0x436ded: e8ee2f1e00 CALL 0x00619de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619de0u,4419058u); flags=s.arithmetic_flags;
  }
  L00436df2: { // 0x436df2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00436df3: { // 0x436df3: 83c45c ADD ESP,0x5c
    f.sp = integer::add(f.sp,0x0000005cu,32,flags);
  }
  L00436df6: { // 0x436df6: c22800 RET 0x28
    s.arithmetic_flags=flags; finish(m,s,f,40u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00453550(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453550: { // 0x453550: 83ec38 SUB ESP,0x38
    f.sp = integer::sub(f.sp,0x00000038u,32,flags);
  }
  L00453553: { // 0x453553: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00453554: { // 0x453554: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00453556: { // 0x453556: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00453557: { // 0x453557: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0045355b: { // 0x45355b: e800991300 CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,4535648u); flags=s.arithmetic_flags;
  }
  L00453560: { // 0x453560: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00453566: { // 0x453566: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453567: { // 0x453567: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0045356b: { // 0x45356b: db80c8130000 FILD dword ptr [EAX + 0x13c8]
    const auto address=(s.ax+0x000013c8u);
    s.fp.load_integer32(m.r32(address));
  }
  L00453571: { // 0x453571: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00453574: { // 0x453574: e8079a1300 CALL 0x0058cf80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cf80u,4535673u); flags=s.arithmetic_flags;
  }
  L00453579: { // 0x453579: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0045357f: { // 0x45357f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453580: { // 0x453580: db81cc130000 FILD dword ptr [ECX + 0x13cc]
    const auto address=(s.cx+0x000013ccu);
    s.fp.load_integer32(m.r32(address));
  }
  L00453586: { // 0x453586: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0045358a: { // 0x45358a: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0045358d: { // 0x45358d: e81e9a1300 CALL 0x0058cfb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cfb0u,4535698u); flags=s.arithmetic_flags;
  }
  L00453592: { // 0x453592: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L00453598: { // 0x453598: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453599: { // 0x453599: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0045359d: { // 0x45359d: db82d0130000 FILD dword ptr [EDX + 0x13d0]
    const auto address=(s.dx+0x000013d0u);
    s.fp.load_integer32(m.r32(address));
  }
  L004535a3: { // 0x4535a3: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004535a6: { // 0x4535a6: e8359a1300 CALL 0x0058cfe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cfe0u,4535723u); flags=s.arithmetic_flags;
  }
  L004535ab: { // 0x4535ab: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L004535af: { // 0x4535af: 8d8ee0020000 LEA ECX,[ESI + 0x2e0]
    s.cx = (s.si+0x000002e0u);
  }
  L004535b5: { // 0x4535b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004535b6: { // 0x4535b6: e895520600 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4535739u); flags=s.arithmetic_flags;
  }
  L004535bb: { // 0x4535bb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004535bd: { // 0x4535bd: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004535c0: { // 0x4535c0: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004535c1: { // 0x4535c1: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L004535c3: { // 0x4535c3: 83e11f AND ECX,0x1f
    s.cx = integer::logical((s.cx)&(0x0000001fu),32,flags);
  }
  L004535c6: { // 0x4535c6: 83e908 SUB ECX,0x8
    s.cx = integer::sub(s.cx,0x00000008u,32,flags);
  }
  L004535c9: { // 0x4535c9: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L004535cd: { // 0x4535cd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004535ce: { // 0x4535ce: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004535d2: { // 0x4535d2: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004535d6: { // 0x4535d6: dc0d90807800 FMUL double ptr [0x00788090]
    const auto address=(0x00788090u);
    s.fp.multiply64(read64(m,address));
  }
  L004535dc: { // 0x4535dc: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004535df: { // 0x4535df: e8bca11300 CALL 0x0058d7a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d7a0u,4535780u); flags=s.arithmetic_flags;
  }
  L004535e4: { // 0x4535e4: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L004535ea: { // 0x4535ea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004535eb: { // 0x4535eb: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004535ef: { // 0x4535ef: db82bc130000 FILD dword ptr [EDX + 0x13bc]
    const auto address=(s.dx+0x000013bcu);
    s.fp.load_integer32(m.r32(address));
  }
  L004535f5: { // 0x4535f5: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004535f8: { // 0x4535f8: e883991300 CALL 0x0058cf80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cf80u,4535805u); flags=s.arithmetic_flags;
  }
  L004535fd: { // 0x4535fd: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00453603: { // 0x453603: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453604: { // 0x453604: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00453608: { // 0x453608: db80c0130000 FILD dword ptr [EAX + 0x13c0]
    const auto address=(s.ax+0x000013c0u);
    s.fp.load_integer32(m.r32(address));
  }
  L0045360e: { // 0x45360e: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00453611: { // 0x453611: e89a991300 CALL 0x0058cfb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cfb0u,4535830u); flags=s.arithmetic_flags;
  }
  L00453616: { // 0x453616: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0045361c: { // 0x45361c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045361d: { // 0x45361d: db81c4130000 FILD dword ptr [ECX + 0x13c4]
    const auto address=(s.cx+0x000013c4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00453623: { // 0x453623: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00453627: { // 0x453627: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0045362a: { // 0x45362a: e8b1991300 CALL 0x0058cfe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cfe0u,4535855u); flags=s.arithmetic_flags;
  }
  L0045362f: { // 0x45362f: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L00453633: { // 0x453633: 8d8ec8020000 LEA ECX,[ESI + 0x2c8]
    s.cx = (s.si+0x000002c8u);
  }
  L00453639: { // 0x453639: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045363a: { // 0x45363a: e811520600 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4535871u); flags=s.arithmetic_flags;
  }
  L0045363f: { // 0x45363f: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00453641: { // 0x453641: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453642: { // 0x453642: c1e80a SHR EAX,0xa
    s.ax = integer::shift(s.ax,0x0000000au,32,flags,integer::Shift::right);
  }
  L00453645: { // 0x453645: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00453646: { // 0x453646: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0045364a: { // 0x45364a: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L0045364c: { // 0x45364c: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  L0045364f: { // 0x45364f: 83e808 SUB EAX,0x8
    s.ax = integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00453652: { // 0x453652: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00453656: { // 0x453656: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0045365a: { // 0x45365a: dc0d90807800 FMUL double ptr [0x00788090]
    const auto address=(0x00788090u);
    s.fp.multiply64(read64(m,address));
  }
  L00453660: { // 0x453660: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00453662: { // 0x453662: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00453665: { // 0x453665: e816a01300 CALL 0x0058d680
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d680u,4535914u); flags=s.arithmetic_flags;
  }
  L0045366a: { // 0x45366a: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L00453670: { // 0x453670: db81b0130000 FILD dword ptr [ECX + 0x13b0]
    const auto address=(s.cx+0x000013b0u);
    s.fp.load_integer32(m.r32(address));
  }
  L00453676: { // 0x453676: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00453677: { // 0x453677: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0045367b: { // 0x45367b: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0045367e: { // 0x45367e: e8fd981300 CALL 0x0058cf80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cf80u,4535939u); flags=s.arithmetic_flags;
  }
  L00453683: { // 0x453683: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L00453689: { // 0x453689: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045368a: { // 0x45368a: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0045368e: { // 0x45368e: db82b4130000 FILD dword ptr [EDX + 0x13b4]
    const auto address=(s.dx+0x000013b4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00453694: { // 0x453694: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00453697: { // 0x453697: e814991300 CALL 0x0058cfb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cfb0u,4535964u); flags=s.arithmetic_flags;
  }
  L0045369c: { // 0x45369c: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004536a2: { // 0x4536a2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004536a3: { // 0x4536a3: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004536a7: { // 0x4536a7: db80b8130000 FILD dword ptr [EAX + 0x13b8]
    const auto address=(s.ax+0x000013b8u);
    s.fp.load_integer32(m.r32(address));
  }
  L004536ad: { // 0x4536ad: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004536b0: { // 0x4536b0: e82b991300 CALL 0x0058cfe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cfe0u,4535989u); flags=s.arithmetic_flags;
  }
  L004536b5: { // 0x4536b5: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L004536bb: { // 0x4536bb: dd81a8130000 FLD double ptr [ECX + 0x13a8]
    const auto address=(s.cx+0x000013a8u);
    s.fp.load64(read64(m,address));
  }
  L004536c1: { // 0x4536c1: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004536c5: { // 0x4536c5: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004536c9: { // 0x4536c9: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L004536cd: { // 0x4536cd: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004536ce: { // 0x4536ce: e8fd991300 CALL 0x0058d0d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d0d0u,4536019u); flags=s.arithmetic_flags;
  }
  L004536d3: { // 0x4536d3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004536d4: { // 0x4536d4: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004536d8: { // 0x4536d8: e8139a1300 CALL 0x0058d0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d0f0u,4536029u); flags=s.arithmetic_flags;
  }
  L004536dd: { // 0x4536dd: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004536de: { // 0x4536de: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004536e2: { // 0x4536e2: e8399a1300 CALL 0x0058d120
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d120u,4536039u); flags=s.arithmetic_flags;
  }
  L004536e7: { // 0x4536e7: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L004536eb: { // 0x4536eb: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L004536f0: { // 0x4536f0: 8d742410 LEA ESI,[ESP + 0x10]
    s.si = (f.sp+0x00000010u);
  }
  L004536f4: { // 0x4536f4: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004536f6: { // 0x4536f6: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L004536f8: { // 0x4536f8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004536f9: { // 0x4536f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004536fa: { // 0x4536fa: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  L004536fd: { // 0x4536fd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00491530(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00491530: { // 0x491530: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00491533: { // 0x491533: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00491538: { // 0x491538: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00491539: { // 0x491539: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049153a: { // 0x49153a: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0049153e: { // 0x49153e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049153f: { // 0x49153f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00491540: { // 0x491540: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00491542: { // 0x491542: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00491548: { // 0x491548: 66c74424100000 MOV word ptr [ESP + 0x10],0x0
    m.w16((f.sp+0x00000010u), 0x00000000u);
  }
  L0049154f: { // 0x49154f: e88ce81900 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4789588u); flags=s.arithmetic_flags;
  }
  L00491554: { // 0x491554: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00491558: { // 0x491558: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049155a: { // 0x49155a: 8ae8 MOV CH,AL
    s.cx = (s.cx & 0xffff00ffu) | ((((s.ax & 0xffu)) & 0xffu) << 8);
  }
  L0049155c: { // 0x49155c: 80e600 AND DH,0x0
    s.dx = (s.dx & 0xffff00ffu) | (((integer::logical((((s.dx >> 8) & 0xffu))&(0x00000000u),8,flags)) & 0xffu) << 8);
  }
  L0049155f: { // 0x49155f: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L00491561: { // 0x491561: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  L00491564: { // 0x491564: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00491566: { // 0x491566: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00491569: { // 0x491569: 2dff3f0000 SUB EAX,0x3fff
    s.ax = integer::sub(s.ax,0x00003fffu,32,flags);
  }
  L0049156e: { // 0x49156e: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00491572: { // 0x491572: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00491576: { // 0x491576: dc0d20667800 FMUL double ptr [0x00786620]
    const auto address=(0x00786620u);
    s.fp.multiply64(read64(m,address));
  }
  L0049157c: { // 0x49157c: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00491580: { // 0x491580: db442434 FILD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L00491584: { // 0x491584: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00491588: { // 0x491588: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0049158c: { // 0x49158c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049158d: { // 0x49158d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049158e: { // 0x49158e: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00491592: { // 0x491592: db4604 FILD dword ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00491595: { // 0x491595: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00491599: { // 0x491599: e8528b0200 CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,4789662u); flags=s.arithmetic_flags;
  }
  L0049159e: { // 0x49159e: dc4c2428 FMUL double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply64(read64(m,address));
  }
  L004915a2: { // 0x4915a2: dc6c2430 FSUBR double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L004915a6: { // 0x4915a6: e8a5942d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4789675u); flags=s.arithmetic_flags;
  }
  L004915ab: { // 0x4915ab: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004915ac: { // 0x4915ac: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004915ad: { // 0x4915ad: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L004915b1: { // 0x4915b1: e88a8b0200 CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,4789686u); flags=s.arithmetic_flags;
  }
  L004915b6: { // 0x4915b6: dc4c2430 FMUL double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.multiply64(read64(m,address));
  }
  L004915ba: { // 0x4915ba: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004915bd: { // 0x4915bd: da06 FIADD dword ptr [ESI]
    const auto address=(s.si);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L004915bf: { // 0x4915bf: e88c942d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4789700u); flags=s.arithmetic_flags;
  }
  L004915c4: { // 0x4915c4: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004915c8: { // 0x4915c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004915c9: { // 0x4915c9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004915ca: { // 0x4915ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004915cb: { // 0x4915cb: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L004915cf: { // 0x4915cf: e85ca0f8ff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,4789716u); flags=s.arithmetic_flags;
  }
  L004915d4: { // 0x4915d4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L004915d8: { // 0x4915d8: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L004915dc: { // 0x4915dc: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004915e0: { // 0x4915e0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004915e2: { // 0x4915e2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004915e3: { // 0x4915e3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004915e9: { // 0x4915e9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004915eb: { // 0x4915eb: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004915ee: { // 0x4915ee: 3d00020000 CMP EAX,0x200
    (void)integer::sub(s.ax,0x00000200u,32,flags);
  }
  L004915f3: { // 0x4915f3: 7315 JNC 0x0049160a
    if(integer::condition("JNC",flags)) goto L0049160a;
  }
  L004915f5: { // 0x4915f5: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004915f7: { // 0x4915f7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004915f8: { // 0x4915f8: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004915fe: { // 0x4915fe: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00491600: { // 0x491600: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00491603: { // 0x491603: 3d00020000 CMP EAX,0x200
    (void)integer::sub(s.ax,0x00000200u,32,flags);
  }
  L00491608: { // 0x491608: 7208 JC 0x00491612
    if(integer::condition("JC",flags)) goto L00491612;
  }
  L0049160a: { // 0x49160a: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0049160c: { // 0x49160c: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0049160f: { // 0x49160f: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L00491612: { // 0x491612: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L00491616: { // 0x491616: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00491618: { // 0x491618: 741f JZ 0x00491639
    if(integer::condition("JZ",flags)) goto L00491639;
  }
  L0049161a: { // 0x49161a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049161c: { // 0x49161c: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0049161e: { // 0x49161e: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00491623: { // 0x491623: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00491629: { // 0x491629: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0049162b: { // 0x49162b: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0049162d: { // 0x49162d: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00491633: { // 0x491633: 81c780000000 ADD EDI,0x80
    s.di = integer::add(s.di,0x00000080u,32,flags);
  }
  L00491639: { // 0x491639: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0049163d: { // 0x49163d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049163f: { // 0x49163f: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00491641: { // 0x491641: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L00491644: { // 0x491644: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00491645: { // 0x491645: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00491646: { // 0x491646: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00491647: { // 0x491647: 895a08 MOV dword ptr [EDX + 0x8],EBX
    m.w32((s.dx+0x00000008u), s.bx);
  }
  L0049164a: { // 0x49164a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049164b: { // 0x49164b: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0049164e: { // 0x49164e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004f4990(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f4990: { // 0x4f4990: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f4991: { // 0x4f4991: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L004f4995: { // 0x4f4995: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f4996: { // 0x4f4996: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f4997: { // 0x4f4997: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L004f4999: { // 0x4f4999: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004f499b: { // 0x4f499b: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004f499e: { // 0x4f499e: dd07 FLD double ptr [EDI]
    const auto address=(s.di);
    s.fp.load64(read64(m,address));
  }
  L004f49a0: { // 0x4f49a0: dd03 FLD double ptr [EBX]
    const auto address=(s.bx);
    s.fp.load64(read64(m,address));
  }
  L004f49a2: { // 0x4f49a2: dd06 FLD double ptr [ESI]
    const auto address=(s.si);
    s.fp.load64(read64(m,address));
  }
  L004f49a4: { // 0x4f49a4: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004f49a6: { // 0x4f49a6: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004f49a8: { // 0x4f49a8: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004f49aa: { // 0x4f49aa: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004f49ac: { // 0x4f49ac: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004f49ae: { // 0x4f49ae: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L004f49b0: { // 0x4f49b0: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L004f49b2: { // 0x4f49b2: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004f49b4: { // 0x4f49b4: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004f49b7: { // 0x4f49b7: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004f49b9: { // 0x4f49b9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004f49bb: { // 0x4f49bb: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004f49bd: { // 0x4f49bd: e8be56fcff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5196226u); flags=s.arithmetic_flags;
  }
  L004f49c2: { // 0x4f49c2: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L004f49c8: { // 0x4f49c8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004f49cb: { // 0x4f49cb: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004f49cd: { // 0x4f49cd: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004f49d0: { // 0x4f49d0: 7428 JZ 0x004f49fa
    if(integer::condition("JZ",flags)) goto L004f49fa;
  }
  L004f49d2: { // 0x4f49d2: b900e06f40 MOV ECX,0x406fe000
    s.cx = 0x406fe000u;
  }
  L004f49d7: { // 0x4f49d7: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  L004f49dd: { // 0x4f49dd: 894b04 MOV dword ptr [EBX + 0x4],ECX
    m.w32((s.bx+0x00000004u), s.cx);
  }
  L004f49e0: { // 0x4f49e0: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L004f49e6: { // 0x4f49e6: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
  L004f49e9: { // 0x4f49e9: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L004f49ef: { // 0x4f49ef: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004f49f2: { // 0x4f49f2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f49f3: { // 0x4f49f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f49f4: { // 0x4f49f4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f49f5: { // 0x4f49f5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004f49f7: { // 0x4f49f7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004f49fa: { // 0x4f49fa: dd06 FLD double ptr [ESI]
    const auto address=(s.si);
    s.fp.load64(read64(m,address));
  }
  L004f49fc: { // 0x4f49fc: dc0d58df7800 FMUL double ptr [0x0078df58]
    const auto address=(0x0078df58u);
    s.fp.multiply64(read64(m,address));
  }
  L004f4a02: { // 0x4f4a02: b900e06f40 MOV ECX,0x406fe000
    s.cx = 0x406fe000u;
  }
  L004f4a07: { // 0x4f4a07: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L004f4a09: { // 0x4f4a09: dd16 FST double ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004f4a0b: { // 0x4f4a0b: dc1d50df7800 FCOMP double ptr [0x0078df50]
    const auto address=(0x0078df50u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004f4a11: { // 0x4f4a11: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004f4a13: { // 0x4f4a13: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004f4a16: { // 0x4f4a16: 7509 JNZ 0x004f4a21
    if(integer::condition("JNZ",flags)) goto L004f4a21;
  }
  L004f4a18: { // 0x4f4a18: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L004f4a1e: { // 0x4f4a1e: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004f4a21: { // 0x4f4a21: dd07 FLD double ptr [EDI]
    const auto address=(s.di);
    s.fp.load64(read64(m,address));
  }
  L004f4a23: { // 0x4f4a23: dc0d58df7800 FMUL double ptr [0x0078df58]
    const auto address=(0x0078df58u);
    s.fp.multiply64(read64(m,address));
  }
  L004f4a29: { // 0x4f4a29: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L004f4a2b: { // 0x4f4a2b: dd17 FST double ptr [EDI]
    const auto address=(s.di);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004f4a2d: { // 0x4f4a2d: dc1d50df7800 FCOMP double ptr [0x0078df50]
    const auto address=(0x0078df50u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004f4a33: { // 0x4f4a33: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004f4a35: { // 0x4f4a35: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004f4a38: { // 0x4f4a38: 7509 JNZ 0x004f4a43
    if(integer::condition("JNZ",flags)) goto L004f4a43;
  }
  L004f4a3a: { // 0x4f4a3a: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L004f4a40: { // 0x4f4a40: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
  L004f4a43: { // 0x4f4a43: dd03 FLD double ptr [EBX]
    const auto address=(s.bx);
    s.fp.load64(read64(m,address));
  }
  L004f4a45: { // 0x4f4a45: dc0d58df7800 FMUL double ptr [0x0078df58]
    const auto address=(0x0078df58u);
    s.fp.multiply64(read64(m,address));
  }
  L004f4a4b: { // 0x4f4a4b: def1 FDIVRP
    numeric_b88::detail::reg<0xdef1>(s.fp);
  }
  L004f4a4d: { // 0x4f4a4d: dd13 FST double ptr [EBX]
    const auto address=(s.bx);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004f4a4f: { // 0x4f4a4f: dc1d50df7800 FCOMP double ptr [0x0078df50]
    const auto address=(0x0078df50u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004f4a55: { // 0x4f4a55: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004f4a57: { // 0x4f4a57: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004f4a5a: { // 0x4f4a5a: 7509 JNZ 0x004f4a65
    if(integer::condition("JNZ",flags)) goto L004f4a65;
  }
  L004f4a5c: { // 0x4f4a5c: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  L004f4a62: { // 0x4f4a62: 894b04 MOV dword ptr [EBX + 0x4],ECX
    m.w32((s.bx+0x00000004u), s.cx);
  }
  L004f4a65: { // 0x4f4a65: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4a66: { // 0x4f4a66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4a67: { // 0x4f4a67: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f4a68: { // 0x4f4a68: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00602250(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00602250: { // 0x602250: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00602253: { // 0x602253: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00602254: { // 0x602254: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00602256: { // 0x602256: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L0060225c: { // 0x60225c: 8b80e4020000 MOV EAX,dword ptr [EAX + 0x2e4]
    s.ax = m.r32((s.ax+0x000002e4u));
  }
  L00602262: { // 0x602262: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00602264: { // 0x602264: 0f8cd5000000 JL 0x0060233f
    if(integer::condition("JL",flags)) goto L0060233f;
  }
  L0060226a: { // 0x60226a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0060226d: { // 0x60226d: 0f8ea4000000 JLE 0x00602317
    if(integer::condition("JLE",flags)) goto L00602317;
  }
  L00602273: { // 0x602273: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00602276: { // 0x602276: 0f85c3000000 JNZ 0x0060233f
    if(integer::condition("JNZ",flags)) goto L0060233f;
  }
  L0060227c: { // 0x60227c: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00602280: { // 0x602280: 8d96e4000000 LEA EDX,[ESI + 0xe4]
    s.dx = (s.si+0x000000e4u);
  }
  L00602286: { // 0x602286: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00602287: { // 0x602287: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0060228d: { // 0x60228d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060228e: { // 0x60228e: e87d5d0900 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6300307u); flags=s.arithmetic_flags;
  }
  L00602293: { // 0x602293: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L00602297: { // 0x602297: 8d8ed8000000 LEA ECX,[ESI + 0xd8]
    s.cx = (s.si+0x000000d8u);
  }
  L0060229d: { // 0x60229d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060229e: { // 0x60229e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060229f: { // 0x60229f: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L006022a5: { // 0x6022a5: e8665d0900 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6300330u); flags=s.arithmetic_flags;
  }
  L006022aa: { // 0x6022aa: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  L006022ae: { // 0x6022ae: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006022b2: { // 0x6022b2: e8b9461100 CALL 0x00716970
    s.arithmetic_flags=flags; invoke(m,s,f,0x00716970u,6300343u); flags=s.arithmetic_flags;
  }
  L006022b7: { // 0x6022b7: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L006022ba: { // 0x6022ba: 7467 JZ 0x00602323
    if(integer::condition("JZ",flags)) goto L00602323;
  }
  L006022bc: { // 0x6022bc: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006022bf: { // 0x6022bf: 7462 JZ 0x00602323
    if(integer::condition("JZ",flags)) goto L00602323;
  }
  L006022c1: { // 0x6022c1: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L006022c4: { // 0x6022c4: 7451 JZ 0x00602317
    if(integer::condition("JZ",flags)) goto L00602317;
  }
  L006022c6: { // 0x6022c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006022c8: { // 0x6022c8: 744d JZ 0x00602317
    if(integer::condition("JZ",flags)) goto L00602317;
  }
  L006022ca: { // 0x6022ca: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006022cd: { // 0x6022cd: 742d JZ 0x006022fc
    if(integer::condition("JZ",flags)) goto L006022fc;
  }
  L006022cf: { // 0x6022cf: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L006022d2: { // 0x6022d2: 7428 JZ 0x006022fc
    if(integer::condition("JZ",flags)) goto L006022fc;
  }
  L006022d4: { // 0x6022d4: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L006022d7: { // 0x6022d7: 7405 JZ 0x006022de
    if(integer::condition("JZ",flags)) goto L006022de;
  }
  L006022d9: { // 0x6022d9: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L006022dc: { // 0x6022dc: 7561 JNZ 0x0060233f
    if(integer::condition("JNZ",flags)) goto L0060233f;
  }
  L006022de: { // 0x6022de: 8b9698000000 MOV EDX,dword ptr [ESI + 0x98]
    s.dx = m.r32((s.si+0x00000098u));
  }
  L006022e4: { // 0x6022e4: 0fbe8e1e010000 MOVSX ECX,byte ptr [ESI + 0x11e]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011eu)),8));
  }
  L006022eb: { // 0x6022eb: 0fbe82d9020000 MOVSX EAX,byte ptr [EDX + 0x2d9]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.dx+0x000002d9u)),8));
  }
  L006022f2: { // 0x6022f2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006022f3: { // 0x6022f3: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L006022f6: { // 0x6022f6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006022f8: { // 0x6022f8: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L006022fb: { // 0x6022fb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006022fc: { // 0x6022fc: 8b9698000000 MOV EDX,dword ptr [ESI + 0x98]
    s.dx = m.r32((s.si+0x00000098u));
  }
  L00602302: { // 0x602302: 0fbe8e1e010000 MOVSX ECX,byte ptr [ESI + 0x11e]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011eu)),8));
  }
  L00602309: { // 0x602309: 0fbe82d9020000 MOVSX EAX,byte ptr [EDX + 0x2d9]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.dx+0x000002d9u)),8));
  }
  L00602310: { // 0x602310: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00602312: { // 0x602312: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00602313: { // 0x602313: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00602316: { // 0x602316: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00602317: { // 0x602317: 0fbe861e010000 MOVSX EAX,byte ptr [ESI + 0x11e]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011eu)),8));
  }
  L0060231e: { // 0x60231e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060231f: { // 0x60231f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00602322: { // 0x602322: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00602323: { // 0x602323: 8b9698000000 MOV EDX,dword ptr [ESI + 0x98]
    s.dx = m.r32((s.si+0x00000098u));
  }
  L00602329: { // 0x602329: 0fbe8e1e010000 MOVSX ECX,byte ptr [ESI + 0x11e]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011eu)),8));
  }
  L00602330: { // 0x602330: 0fbe82d9020000 MOVSX EAX,byte ptr [EDX + 0x2d9]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.dx+0x000002d9u)),8));
  }
  L00602337: { // 0x602337: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00602338: { // 0x602338: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L0060233b: { // 0x60233b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0060233e: { // 0x60233e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060233f: { // 0x60233f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00602341: { // 0x602341: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00602342: { // 0x602342: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00602345: { // 0x602345: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0061a220(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0061a220: { // 0x61a220: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0061a221: { // 0x61a221: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0061a223: { // 0x61a223: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0061a226: { // 0x61a226: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L0061a229: { // 0x61a229: d94508 FLD float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0061a22c: { // 0x61a22c: d85d10 FCOMP float ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0061a22f: { // 0x61a22f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0061a230: { // 0x61a230: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0061a231: { // 0x61a231: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0061a232: { // 0x61a232: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0061a234: { // 0x61a234: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a236: { // 0x61a236: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0061a239: { // 0x61a239: 7453 JZ 0x0061a28e
    if(integer::condition("JZ",flags)) goto L0061a28e;
  }
  L0061a23b: { // 0x61a23b: d9450c FLD float ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0061a23e: { // 0x61a23e: d85d14 FCOMP float ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0061a241: { // 0x61a241: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a243: { // 0x61a243: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0061a246: { // 0x61a246: 7446 JZ 0x0061a28e
    if(integer::condition("JZ",flags)) goto L0061a28e;
  }
  L0061a248: { // 0x61a248: c744243000000000 MOV dword ptr [ESP + 0x30],0x0
    m.w32((f.sp+0x00000030u), 0x00000000u);
  }
  L0061a250: { // 0x61a250: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0061a254: { // 0x61a254: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0061a256: { // 0x61a256: c744243400000000 MOV dword ptr [ESP + 0x34],0x0
    m.w32((f.sp+0x00000034u), 0x00000000u);
  }
  L0061a25e: { // 0x61a25e: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0061a262: { // 0x61a262: c744243800000000 MOV dword ptr [ESP + 0x38],0x0
    m.w32((f.sp+0x00000038u), 0x00000000u);
  }
  L0061a26a: { // 0x61a26a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0061a26c: { // 0x61a26c: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0061a270: { // 0x61a270: c744243c0000803f MOV dword ptr [ESP + 0x3c],0x3f800000
    m.w32((f.sp+0x0000003cu), 0x3f800000u);
  }
  L0061a278: { // 0x61a278: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0061a27b: { // 0x61a27b: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0061a27f: { // 0x61a27f: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0061a282: { // 0x61a282: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0061a285: { // 0x61a285: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0061a286: { // 0x61a286: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0061a287: { // 0x61a287: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0061a288: { // 0x61a288: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0061a28a: { // 0x61a28a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0061a28b: { // 0x61a28b: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0061a28e: { // 0x61a28e: d94508 FLD float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0061a291: { // 0x61a291: d84d08 FMUL float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a294: { // 0x61a294: d9450c FLD float ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0061a297: { // 0x61a297: d84d0c FMUL float ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L0061a29a: { // 0x61a29a: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a29d: { // 0x61a29d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a29f: { // 0x61a29f: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a2a2: { // 0x61a2a2: e8d9fde9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6398631u); flags=s.arithmetic_flags;
  }
  L0061a2a7: { // 0x61a2a7: d94518 FLD float ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0061a2aa: { // 0x61a2aa: d80d18367900 FMUL float ptr [0x00793618]
    const auto address=(0x00793618u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a2b0: { // 0x61a2b0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a2b3: { // 0x61a2b3: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a2b7: { // 0x61a2b7: d8542410 FCOM float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.compare32(m.r32(address));
  }
  L0061a2bb: { // 0x61a2bb: d94518 FLD float ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0061a2be: { // 0x61a2be: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a2c0: { // 0x61a2c0: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0061a2c3: { // 0x61a2c3: 741f JZ 0x0061a2e4
    if(integer::condition("JZ",flags)) goto L0061a2e4;
  }
  L0061a2c5: { // 0x61a2c5: d84d18 FMUL float ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a2c8: { // 0x61a2c8: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0061a2ca: { // 0x61a2ca: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0061a2cc: { // 0x61a2cc: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a2cf: { // 0x61a2cf: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0061a2d1: { // 0x61a2d1: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a2d4: { // 0x61a2d4: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a2d6: { // 0x61a2d6: e8a5fde9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6398683u); flags=s.arithmetic_flags;
  }
  L0061a2db: { // 0x61a2db: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a2df: { // 0x61a2df: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a2e2: { // 0x61a2e2: eb14 JMP 0x0061a2f8
    goto L0061a2f8;
  }
  L0061a2e4: { // 0x61a2e4: d80d14367900 FMUL float ptr [0x00793614]
    const auto address=(0x00793614u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a2ea: { // 0x61a2ea: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0061a2ec: { // 0x61a2ec: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a2ee: { // 0x61a2ee: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L0061a2f0: { // 0x61a2f0: d95c240c FSTP float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a2f4: { // 0x61a2f4: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a2f6: { // 0x61a2f6: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a2f8: { // 0x61a2f8: d94510 FLD float ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0061a2fb: { // 0x61a2fb: d84d10 FMUL float ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a2fe: { // 0x61a2fe: d94514 FLD float ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0061a301: { // 0x61a301: d84d14 FMUL float ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a304: { // 0x61a304: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a307: { // 0x61a307: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a309: { // 0x61a309: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a30c: { // 0x61a30c: e86ffde9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6398737u); flags=s.arithmetic_flags;
  }
  L0061a311: { // 0x61a311: d8542418 FCOM float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.compare32(m.r32(address));
  }
  L0061a315: { // 0x61a315: d94518 FLD float ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0061a318: { // 0x61a318: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a31b: { // 0x61a31b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a31d: { // 0x61a31d: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0061a320: { // 0x61a320: 741b JZ 0x0061a33d
    if(integer::condition("JZ",flags)) goto L0061a33d;
  }
  L0061a322: { // 0x61a322: d84d18 FMUL float ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a325: { // 0x61a325: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0061a327: { // 0x61a327: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0061a329: { // 0x61a329: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a32c: { // 0x61a32c: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0061a32e: { // 0x61a32e: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a331: { // 0x61a331: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a333: { // 0x61a333: e848fde9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6398776u); flags=s.arithmetic_flags;
  }
  L0061a338: { // 0x61a338: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a33b: { // 0x61a33b: eb0e JMP 0x0061a34b
    goto L0061a34b;
  }
  L0061a33d: { // 0x61a33d: d80d14367900 FMUL float ptr [0x00793614]
    const auto address=(0x00793614u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a343: { // 0x61a343: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0061a345: { // 0x61a345: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a347: { // 0x61a347: def2 FDIVRP ST2,ST0
    numeric_b88::detail::reg<0xdef2>(s.fp);
  }
  L0061a349: { // 0x61a349: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a34b: { // 0x61a34b: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0061a34f: { // 0x61a34f: d84d14 FMUL float ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a352: { // 0x61a352: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0061a354: { // 0x61a354: d84d0c FMUL float ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L0061a357: { // 0x61a357: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a35a: { // 0x61a35a: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0061a35c: { // 0x61a35c: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a360: { // 0x61a360: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0061a362: { // 0x61a362: d84d08 FMUL float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a365: { // 0x61a365: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0061a369: { // 0x61a369: d84d10 FMUL float ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a36c: { // 0x61a36c: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0061a36e: { // 0x61a36e: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a372: { // 0x61a372: d9450c FLD float ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0061a375: { // 0x61a375: d84d10 FMUL float ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a378: { // 0x61a378: d94508 FLD float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0061a37b: { // 0x61a37b: d84d14 FMUL float ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a37e: { // 0x61a37e: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0061a380: { // 0x61a380: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a384: { // 0x61a384: d94508 FLD float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0061a387: { // 0x61a387: d86510 FSUB float ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.subtract32(m.r32(address));
  }
  L0061a38a: { // 0x61a38a: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a38e: { // 0x61a38e: d9450c FLD float ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0061a391: { // 0x61a391: d86514 FSUB float ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    s.fp.subtract32(m.r32(address));
  }
  L0061a394: { // 0x61a394: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a398: { // 0x61a398: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0061a39c: { // 0x61a39c: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L0061a39e: { // 0x61a39e: d95c2434 FSTP float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a3a2: { // 0x61a3a2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a3a4: { // 0x61a3a4: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L0061a3a8: { // 0x61a3a8: d9442434 FLD float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load32(m.r32(address));
  }
  L0061a3ac: { // 0x61a3ac: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0061a3b0: { // 0x61a3b0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0061a3b2: { // 0x61a3b2: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0061a3b4: { // 0x61a3b4: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0061a3b6: { // 0x61a3b6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0061a3b8: { // 0x61a3b8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a3ba: { // 0x61a3ba: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L0061a3bc: { // 0x61a3bc: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L0061a3be: { // 0x61a3be: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a3c0: { // 0x61a3c0: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a3c3: { // 0x61a3c3: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a3c5: { // 0x61a3c5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a3c7: { // 0x61a3c7: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a3c9: { // 0x61a3c9: e8b2fce9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6398926u); flags=s.arithmetic_flags;
  }
  L0061a3ce: { // 0x61a3ce: d94518 FLD float ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0061a3d1: { // 0x61a3d1: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0061a3d3: { // 0x61a3d3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a3d6: { // 0x61a3d6: def9 FDIVP
    numeric_b88::detail::reg<0xdef9>(s.fp);
  }
  L0061a3d8: { // 0x61a3d8: d815f8677800 FCOM float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.compare32(m.r32(address));
  }
  L0061a3de: { // 0x61a3de: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a3e0: { // 0x61a3e0: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0061a3e3: { // 0x61a3e3: 750a JNZ 0x0061a3ef
    if(integer::condition("JNZ",flags)) goto L0061a3ef;
  }
  L0061a3e5: { // 0x61a3e5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a3e7: { // 0x61a3e7: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
  L0061a3ed: { // 0x61a3ed: eb15 JMP 0x0061a404
    goto L0061a404;
  }
  L0061a3ef: { // 0x61a3ef: d81510367900 FCOM float ptr [0x00793610]
    const auto address=(0x00793610u);
    s.fp.compare32(m.r32(address));
  }
  L0061a3f5: { // 0x61a3f5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a3f7: { // 0x61a3f7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0061a3fa: { // 0x61a3fa: 7408 JZ 0x0061a404
    if(integer::condition("JZ",flags)) goto L0061a404;
  }
  L0061a3fc: { // 0x61a3fc: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a3fe: { // 0x61a3fe: d90510367900 FLD float ptr [0x00793610]
    const auto address=(0x00793610u);
    s.fp.load32(m.r32(address));
  }
  L0061a404: { // 0x61a404: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0061a407: { // 0x61a407: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a40a: { // 0x61a40a: e8b1fde9ff CALL 0x004ba1c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba1c0u,6398991u); flags=s.arithmetic_flags;
  }
  L0061a40f: { // 0x61a40f: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0061a411: { // 0x61a411: c744243800000000 MOV dword ptr [ESP + 0x38],0x0
    m.w32((f.sp+0x00000038u), 0x00000000u);
  }
  L0061a419: { // 0x61a419: c744243c00000000 MOV dword ptr [ESP + 0x3c],0x0
    m.w32((f.sp+0x0000003cu), 0x00000000u);
  }
  L0061a421: { // 0x61a421: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L0061a429: { // 0x61a429: c74424440000803f MOV dword ptr [ESP + 0x44],0x3f800000
    m.w32((f.sp+0x00000044u), 0x3f800000u);
  }
  L0061a431: { // 0x61a431: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a435: { // 0x61a435: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0061a439: { // 0x61a439: d84c2428 FMUL float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a43d: { // 0x61a43d: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0061a441: { // 0x61a441: d84c2424 FMUL float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a445: { // 0x61a445: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a447: { // 0x61a447: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0061a44b: { // 0x61a44b: d84c2420 FMUL float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a44f: { // 0x61a44f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0061a451: { // 0x61a451: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a454: { // 0x61a454: e827fce9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6399065u); flags=s.arithmetic_flags;
  }
  L0061a459: { // 0x61a459: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0061a45f: { // 0x61a45f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a462: { // 0x61a462: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0061a464: { // 0x61a464: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0061a467: { // 0x61a467: 7537 JNZ 0x0061a4a0
    if(integer::condition("JNZ",flags)) goto L0061a4a0;
  }
  L0061a469: { // 0x61a469: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0061a46d: { // 0x61a46d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0061a46e: { // 0x61a46e: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0061a470: { // 0x61a470: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a473: { // 0x61a473: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0061a477: { // 0x61a477: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0061a478: { // 0x61a478: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0061a47a: { // 0x61a47a: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a47d: { // 0x61a47d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0061a47e: { // 0x61a47e: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0061a482: { // 0x61a482: d87c2424 FDIVR float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    reverse_divide32(s.fp,m.r32(address));
  }
  L0061a486: { // 0x61a486: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a489: { // 0x61a489: e882d0e1ff CALL 0x00437510
    s.arithmetic_flags=flags; invoke(m,s,f,0x00437510u,6399118u); flags=s.arithmetic_flags;
  }
  L0061a48e: { // 0x61a48e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0061a490: { // 0x61a490: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0061a494: { // 0x61a494: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0061a497: { // 0x61a497: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0061a49b: { // 0x61a49b: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0061a49e: { // 0x61a49e: eb16 JMP 0x0061a4b6
    goto L0061a4b6;
  }
  L0061a4a0: { // 0x61a4a0: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0061a4a4: { // 0x61a4a4: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0061a4a8: { // 0x61a4a8: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0061a4ac: { // 0x61a4ac: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0061a4b0: { // 0x61a4b0: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0061a4b2: { // 0x61a4b2: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0061a4b6: { // 0x61a4b6: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0061a4ba: { // 0x61a4ba: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
  L0061a4c0: { // 0x61a4c0: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0061a4c4: { // 0x61a4c4: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0061a4c8: { // 0x61a4c8: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0061a4cc: { // 0x61a4cc: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0061a4d0: { // 0x61a4d0: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0061a4d4: { // 0x61a4d4: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L0061a4d8: { // 0x61a4d8: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0061a4dc: { // 0x61a4dc: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0061a4e0: { // 0x61a4e0: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0061a4e4: { // 0x61a4e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0061a4e5: { // 0x61a4e5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0061a4e6: { // 0x61a4e6: e805fce9ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6399211u); flags=s.arithmetic_flags;
  }
  L0061a4eb: { // 0x61a4eb: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a4ef: { // 0x61a4ef: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0061a4f2: { // 0x61a4f2: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L0061a4f6: { // 0x61a4f6: e895f8ffff CALL 0x00619d90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619d90u,6399227u); flags=s.arithmetic_flags;
  }
  L0061a4fb: { // 0x61a4fb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0061a4fc: { // 0x61a4fc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0061a4fd: { // 0x61a4fd: e83efce9ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,6399234u); flags=s.arithmetic_flags;
  }
  L0061a502: { // 0x61a502: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0061a506: { // 0x61a506: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0061a50a: { // 0x61a50a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0061a50c: { // 0x61a50c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0061a50f: { // 0x61a50f: d95c243c FSTP float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0061a513: { // 0x61a513: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0061a515: { // 0x61a515: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0061a519: { // 0x61a519: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0061a51a: { // 0x61a51a: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0061a51d: { // 0x61a51d: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0061a521: { // 0x61a521: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0061a524: { // 0x61a524: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0061a527: { // 0x61a527: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0061a529: { // 0x61a529: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0061a52a: { // 0x61a52a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0061a52b: { // 0x61a52b: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0061a52d: { // 0x61a52d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0061a52e: { // 0x61a52e: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00633790(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00633790: { // 0x633790: 83ec48 SUB ESP,0x48
    f.sp = integer::sub(f.sp,0x00000048u,32,flags);
  }
  L00633793: { // 0x633793: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00633794: { // 0x633794: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00633796: { // 0x633796: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0063379a: { // 0x63379a: e8c196f5ff CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,6502303u); flags=s.arithmetic_flags;
  }
  L0063379f: { // 0x63379f: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L006337a2: { // 0x6337a2: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L006337a6: { // 0x6337a6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006337a7: { // 0x6337a7: e8f49ff5ff CALL 0x0058d7a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d7a0u,6502316u); flags=s.arithmetic_flags;
  }
  L006337ac: { // 0x6337ac: d9460c FLD float ptr [ESI + 0xc]
    const auto address=(s.si+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L006337af: { // 0x6337af: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L006337b3: { // 0x6337b3: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L006337b7: { // 0x6337b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006337b8: { // 0x6337b8: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006337bc: { // 0x6337bc: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006337c0: { // 0x6337c0: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L006337c8: { // 0x6337c8: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L006337d0: { // 0x6337d0: e8aba9f5ff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6502357u); flags=s.arithmetic_flags;
  }
  L006337d5: { // 0x6337d5: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006337d7: { // 0x6337d7: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L006337db: { // 0x6337db: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L006337de: { // 0x6337de: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006337e2: { // 0x6337e2: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L006337e6: { // 0x6337e6: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006337e9: { // 0x6337e9: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L006337ed: { // 0x6337ed: e85e721300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6502386u); flags=s.arithmetic_flags;
  }
  L006337f2: { // 0x6337f2: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L006337f6: { // 0x6337f6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006337f8: { // 0x6337f8: e853721300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6502397u); flags=s.arithmetic_flags;
  }
  L006337fd: { // 0x6337fd: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L00633801: { // 0x633801: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00633803: { // 0x633803: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00633805: { // 0x633805: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L00633808: { // 0x633808: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  L0063380a: { // 0x63380a: 89710c MOV dword ptr [ECX + 0xc],ESI
    m.w32((s.cx+0x0000000cu), s.si);
  }
  L0063380d: { // 0x63380d: 894118 MOV dword ptr [ECX + 0x18],EAX
    m.w32((s.cx+0x00000018u), s.ax);
  }
  L00633810: { // 0x633810: f7de NEG ESI
    s.si = integer::sub(0u,s.si,32,flags);
  }
  L00633812: { // 0x633812: 897110 MOV dword ptr [ECX + 0x10],ESI
    m.w32((s.cx+0x00000010u), s.si);
  }
  L00633815: { // 0x633815: 89711c MOV dword ptr [ECX + 0x1c],ESI
    m.w32((s.cx+0x0000001cu), s.si);
  }
  L00633818: { // 0x633818: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0063381b: { // 0x63381b: 895114 MOV dword ptr [ECX + 0x14],EDX
    m.w32((s.cx+0x00000014u), s.dx);
  }
  L0063381e: { // 0x63381e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0063381f: { // 0x63381f: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00633822: { // 0x633822: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0069bbe0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069bbe0: { // 0x69bbe0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0069bbe3: { // 0x69bbe3: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0069bbe7: { // 0x69bbe7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069bbe8: { // 0x69bbe8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0069bbea: { // 0x69bbea: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069bbec: { // 0x69bbec: 890d6860aa00 MOV dword ptr [0x00aa6068],ECX
    m.w32((0x00aa6068u), s.cx);
  }
  L0069bbf2: { // 0x69bbf2: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0069bbf5: { // 0x69bbf5: 89156c60aa00 MOV dword ptr [0x00aa606c],EDX
    m.w32((0x00aa606cu), s.dx);
  }
  L0069bbfb: { // 0x69bbfb: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0069bbfe: { // 0x69bbfe: 890d7060aa00 MOV dword ptr [0x00aa6070],ECX
    m.w32((0x00aa6070u), s.cx);
  }
  L0069bc04: { // 0x69bc04: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0069bc07: { // 0x69bc07: 89157460aa00 MOV dword ptr [0x00aa6074],EDX
    m.w32((0x00aa6074u), s.dx);
  }
  L0069bc0d: { // 0x69bc0d: 8b8e780d0000 MOV ECX,dword ptr [ESI + 0xd78]
    s.cx = m.r32((s.si+0x00000d78u));
  }
  L0069bc13: { // 0x69bc13: 8b86740d0000 MOV EAX,dword ptr [ESI + 0xd74]
    s.ax = m.r32((s.si+0x00000d74u));
  }
  L0069bc19: { // 0x69bc19: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  L0069bc1d: { // 0x69bc1d: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L0069bc21: { // 0x69bc21: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069bc22: { // 0x69bc22: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069bc24: { // 0x69bc24: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L0069bc28: { // 0x69bc28: e893260000 CALL 0x0069e2c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e2c0u,6929453u); flags=s.arithmetic_flags;
  }
  L0069bc2d: { // 0x69bc2d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069bc2f: { // 0x69bc2f: 7413 JZ 0x0069bc44
    if(integer::condition("JZ",flags)) goto L0069bc44;
  }
  L0069bc31: { // 0x69bc31: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L0069bc36: { // 0x69bc36: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069bc38: { // 0x69bc38: 750a JNZ 0x0069bc44
    if(integer::condition("JNZ",flags)) goto L0069bc44;
  }
  L0069bc3a: { // 0x69bc3a: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0069bc3e: { // 0x69bc3e: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0069bc42: { // 0x69bc42: eb0c JMP 0x0069bc50
    goto L0069bc50;
  }
  L0069bc44: { // 0x69bc44: 8b86740d0000 MOV EAX,dword ptr [ESI + 0xd74]
    s.ax = m.r32((s.si+0x00000d74u));
  }
  L0069bc4a: { // 0x69bc4a: 8b8e780d0000 MOV ECX,dword ptr [ESI + 0xd78]
    s.cx = m.r32((s.si+0x00000d78u));
  }
  L0069bc50: { // 0x69bc50: 8986640d0000 MOV dword ptr [ESI + 0xd64],EAX
    m.w32((s.si+0x00000d64u), s.ax);
  }
  L0069bc56: { // 0x69bc56: 8986740d0000 MOV dword ptr [ESI + 0xd74],EAX
    m.w32((s.si+0x00000d74u), s.ax);
  }
  L0069bc5c: { // 0x69bc5c: 898e680d0000 MOV dword ptr [ESI + 0xd68],ECX
    m.w32((s.si+0x00000d68u), s.cx);
  }
  L0069bc62: { // 0x69bc62: 898e780d0000 MOV dword ptr [ESI + 0xd78],ECX
    m.w32((s.si+0x00000d78u), s.cx);
  }
  L0069bc68: { // 0x69bc68: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069bc6a: { // 0x69bc6a: e8412b0000 CALL 0x0069e7b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e7b0u,6929519u); flags=s.arithmetic_flags;
  }
  L0069bc6f: { // 0x69bc6f: c6867d0d000001 MOV byte ptr [ESI + 0xd7d],0x1
    m.w8((s.si+0x00000d7du), 0x00000001u);
  }
  L0069bc76: { // 0x69bc76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069bc77: { // 0x69bc77: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069bc7a: { // 0x69bc7a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0069bcf0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069bcf0: { // 0x69bcf0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0069bcf3: { // 0x69bcf3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069bcf4: { // 0x69bcf4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069bcf5: { // 0x69bcf5: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0069bcf9: { // 0x69bcf9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069bcfa: { // 0x69bcfa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069bcfb: { // 0x69bcfb: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0069bcfd: { // 0x69bcfd: 8b7500 MOV ESI,dword ptr [EBP]
    s.si = m.r32((s.bp));
  }
  L0069bd00: { // 0x69bd00: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L0069bd03: { // 0x69bd03: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0069bd07: { // 0x69bd07: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069bd0b: { // 0x69bd0b: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L0069bd0e: { // 0x69bd0e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069bd11: { // 0x69bd11: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069bd14: { // 0x69bd14: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd15: { // 0x69bd15: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd17: { // 0x69bd17: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069bd19: { // 0x69bd19: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L0069bd1c: { // 0x69bd1c: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd1e: { // 0x69bd1e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069bd21: { // 0x69bd21: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069bd23: { // 0x69bd23: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd24: { // 0x69bd24: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd26: { // 0x69bd26: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069bd28: { // 0x69bd28: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069bd2a: { // 0x69bd2a: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0069bd2d: { // 0x69bd2d: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0069bd2f: { // 0x69bd2f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069bd31: { // 0x69bd31: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069bd34: { // 0x69bd34: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd35: { // 0x69bd35: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd37: { // 0x69bd37: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd39: { // 0x69bd39: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069bd3b: { // 0x69bd3b: 8d045b LEA EAX,[EBX + EBX*0x2]
    s.ax = (s.bx+(s.bx * 0x00000002u));
  }
  L0069bd3e: { // 0x69bd3e: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd40: { // 0x69bd40: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069bd43: { // 0x69bd43: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0069bd47: { // 0x69bd47: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069bd49: { // 0x69bd49: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd4a: { // 0x69bd4a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd4c: { // 0x69bd4c: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd4e: { // 0x69bd4e: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069bd50: { // 0x69bd50: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069bd52: { // 0x69bd52: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd53: { // 0x69bd53: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0069bd56: { // 0x69bd56: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069bd5c: { // 0x69bd5c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069bd5e: { // 0x69bd5e: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0069bd60: { // 0x69bd60: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069bd62: { // 0x69bd62: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd65: { // 0x69bd65: e846c2ffff CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6929770u); flags=s.arithmetic_flags;
  }
  L0069bd6a: { // 0x69bd6a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069bd6c: { // 0x69bd6c: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069bd6e: { // 0x69bd6e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd6f: { // 0x69bd6f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069bd75: { // 0x69bd75: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0069bd79: { // 0x69bd79: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069bd7b: { // 0x69bd7b: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0069bd7f: { // 0x69bd7f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd82: { // 0x69bd82: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069bd84: { // 0x69bd84: 8b8fb4000000 MOV ECX,dword ptr [EDI + 0xb4]
    s.cx = m.r32((s.di+0x000000b4u));
  }
  L0069bd8a: { // 0x69bd8a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0069bd8c: { // 0x69bd8c: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  L0069bd92: { // 0x69bd92: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0069bd94: { // 0x69bd94: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0069bd96: { // 0x69bd96: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069bd98: { // 0x69bd98: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  L0069bd9a: { // 0x69bd9a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069bd9b: { // 0x69bd9b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069bd9d: { // 0x69bd9d: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0069bda1: { // 0x69bda1: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0069bda5: { // 0x69bda5: e816250000 CALL 0x0069e2c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e2c0u,6929834u); flags=s.arithmetic_flags;
  }
  L0069bdaa: { // 0x69bdaa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069bdac: { // 0x69bdac: 7411 JZ 0x0069bdbf
    if(integer::condition("JZ",flags)) goto L0069bdbf;
  }
  L0069bdae: { // 0x69bdae: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L0069bdb3: { // 0x69bdb3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069bdb5: { // 0x69bdb5: 7508 JNZ 0x0069bdbf
    if(integer::condition("JNZ",flags)) goto L0069bdbf;
  }
  L0069bdb7: { // 0x69bdb7: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0069bdbb: { // 0x69bdbb: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069bdbf: { // 0x69bdbf: 89b7640d0000 MOV dword ptr [EDI + 0xd64],ESI
    m.w32((s.di+0x00000d64u), s.si);
  }
  L0069bdc5: { // 0x69bdc5: 89b7740d0000 MOV dword ptr [EDI + 0xd74],ESI
    m.w32((s.di+0x00000d74u), s.si);
  }
  L0069bdcb: { // 0x69bdcb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069bdcd: { // 0x69bdcd: 899f680d0000 MOV dword ptr [EDI + 0xd68],EBX
    m.w32((s.di+0x00000d68u), s.bx);
  }
  L0069bdd3: { // 0x69bdd3: 899f780d0000 MOV dword ptr [EDI + 0xd78],EBX
    m.w32((s.di+0x00000d78u), s.bx);
  }
  L0069bdd9: { // 0x69bdd9: e8d2290000 CALL 0x0069e7b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e7b0u,6929886u); flags=s.arithmetic_flags;
  }
  L0069bdde: { // 0x69bdde: c6877d0d000001 MOV byte ptr [EDI + 0xd7d],0x1
    m.w8((s.di+0x00000d7du), 0x00000001u);
  }
  L0069bde5: { // 0x69bde5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069bde6: { // 0x69bde6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069bde7: { // 0x69bde7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069bde8: { // 0x69bde8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069bde9: { // 0x69bde9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069bdec: { // 0x69bdec: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006e5fa0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e5fa0: { // 0x6e5fa0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006e5fa1: { // 0x6e5fa1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L006e5fa3: { // 0x6e5fa3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L006e5fa6: { // 0x6e5fa6: 81ec3c010000 SUB ESP,0x13c
    f.sp = integer::sub(f.sp,0x0000013cu,32,flags);
  }
  L006e5fac: { // 0x6e5fac: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006e5fad: { // 0x6e5fad: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e5fae: { // 0x6e5fae: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L006e5fb1: { // 0x6e5fb1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e5fb2: { // 0x6e5fb2: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L006e5fb5: { // 0x6e5fb5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006e5fb7: { // 0x6e5fb7: 0f85f5000000 JNZ 0x006e60b2
    if(integer::condition("JNZ",flags)) goto L006e60b2;
  }
  L006e5fbd: { // 0x6e5fbd: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L006e5fc0: { // 0x6e5fc0: 0588000000 ADD EAX,0x88
    s.ax = integer::add(s.ax,0x00000088u,32,flags);
  }
  L006e5fc5: { // 0x6e5fc5: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006e5fc7: { // 0x6e5fc7: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006e5fcb: { // 0x6e5fcb: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L006e5fcf: { // 0x6e5fcf: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006e5fd2: { // 0x6e5fd2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e5fd3: { // 0x6e5fd3: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006e5fd7: { // 0x6e5fd7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006e5fdc: { // 0x6e5fdc: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006e5fdf: { // 0x6e5fdf: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006e5fe3: { // 0x6e5fe3: e8a8f4e5ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,7233512u); flags=s.arithmetic_flags;
  }
  L006e5fe8: { // 0x6e5fe8: 8b7d10 MOV EDI,dword ptr [EBP + 0x10]
    s.di = m.r32((s.bp+0x00000010u));
  }
  L006e5feb: { // 0x6e5feb: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e5fed: { // 0x6e5fed: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L006e5ff3: { // 0x6e5ff3: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006e5ff5: { // 0x6e5ff5: 740e JZ 0x006e6005
    if(integer::condition("JZ",flags)) goto L006e6005;
  }
  L006e5ff7: { // 0x6e5ff7: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006e5ff9: { // 0x6e5ff9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006e5ffc: { // 0x6e5ffc: 7407 JZ 0x006e6005
    if(integer::condition("JZ",flags)) goto L006e6005;
  }
  L006e5ffe: { // 0x6e5ffe: c1e006 SHL EAX,0x6
    s.ax = integer::shift(s.ax,0x00000006u,32,flags,integer::Shift::left);
  }
  L006e6001: { // 0x6e6001: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L006e6003: { // 0x6e6003: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L006e6005: { // 0x6e6005: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L006e6009: { // 0x6e6009: e8526eeaff CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,7233550u); flags=s.arithmetic_flags;
  }
  L006e600e: { // 0x6e600e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006e6010: { // 0x6e6010: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e6011: { // 0x6e6011: 745f JZ 0x006e6072
    if(integer::condition("JZ",flags)) goto L006e6072;
  }
  L006e6013: { // 0x6e6013: 8d94241c010000 LEA EDX,[ESP + 0x11c]
    s.dx = (f.sp+0x0000011cu);
  }
  L006e601a: { // 0x6e601a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006e601b: { // 0x6e601b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e601c: { // 0x6e601c: e8ef51e5ff CALL 0x0053b210
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053b210u,7233569u); flags=s.arithmetic_flags;
  }
  L006e6021: { // 0x6e6021: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006e6022: { // 0x6e6022: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L006e6026: { // 0x6e6026: e8e56beaff CALL 0x0058cc10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cc10u,7233579u); flags=s.arithmetic_flags;
  }
  L006e602b: { // 0x6e602b: 8d442458 LEA EAX,[ESP + 0x58]
    s.ax = (f.sp+0x00000058u);
  }
  L006e602f: { // 0x6e602f: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L006e6031: { // 0x6e6031: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006e6032: { // 0x6e6032: 8d8c24ec000000 LEA ECX,[ESP + 0xec]
    s.cx = (f.sp+0x000000ecu);
  }
  L006e6039: { // 0x6e6039: e8e2780200 CALL 0x0070d920
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070d920u,7233598u); flags=s.arithmetic_flags;
  }
  L006e603e: { // 0x6e603e: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006e6040: { // 0x6e6040: 8d8c24bc000000 LEA ECX,[ESP + 0xbc]
    s.cx = (f.sp+0x000000bcu);
  }
  L006e6047: { // 0x6e6047: e8347feaff CALL 0x0058df80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058df80u,7233612u); flags=s.arithmetic_flags;
  }
  L006e604c: { // 0x6e604c: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006e6051: { // 0x6e6051: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006e6053: { // 0x6e6053: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L006e6056: { // 0x6e6056: 8d7c2428 LEA EDI,[ESP + 0x28]
    s.di = (f.sp+0x00000028u);
  }
  L006e605a: { // 0x6e605a: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006e605c: { // 0x6e605c: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006e6061: { // 0x6e6061: 8d742428 LEA ESI,[ESP + 0x28]
    s.si = (f.sp+0x00000028u);
  }
  L006e6065: { // 0x6e6065: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006e6067: { // 0x6e6067: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006e6069: { // 0x6e6069: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e606a: { // 0x6e606a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e606b: { // 0x6e606b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e606c: { // 0x6e606c: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006e606e: { // 0x6e606e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e606f: { // 0x6e606f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e6072: { // 0x6e6072: 8d8c24bc000000 LEA ECX,[ESP + 0xbc]
    s.cx = (f.sp+0x000000bcu);
  }
  L006e6079: { // 0x6e6079: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e607a: { // 0x6e607a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e607b: { // 0x6e607b: e89051e5ff CALL 0x0053b210
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053b210u,7233664u); flags=s.arithmetic_flags;
  }
  L006e6080: { // 0x6e6080: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006e6081: { // 0x6e6081: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L006e6085: { // 0x6e6085: e8866beaff CALL 0x0058cc10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cc10u,7233674u); flags=s.arithmetic_flags;
  }
  L006e608a: { // 0x6e608a: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L006e608d: { // 0x6e608d: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006e6092: { // 0x6e6092: 8d742458 LEA ESI,[ESP + 0x58]
    s.si = (f.sp+0x00000058u);
  }
  L006e6096: { // 0x6e6096: 8d7c2428 LEA EDI,[ESP + 0x28]
    s.di = (f.sp+0x00000028u);
  }
  L006e609a: { // 0x6e609a: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006e609c: { // 0x6e609c: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006e60a1: { // 0x6e60a1: 8d742428 LEA ESI,[ESP + 0x28]
    s.si = (f.sp+0x00000028u);
  }
  L006e60a5: { // 0x6e60a5: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006e60a7: { // 0x6e60a7: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006e60a9: { // 0x6e60a9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e60aa: { // 0x6e60aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e60ab: { // 0x6e60ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e60ac: { // 0x6e60ac: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006e60ae: { // 0x6e60ae: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e60af: { // 0x6e60af: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e60b2: { // 0x6e60b2: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L006e60b5: { // 0x6e60b5: 83c0fe ADD EAX,-0x2
    s.ax = integer::add(s.ax,0xfffffffeu,32,flags);
  }
  L006e60b8: { // 0x6e60b8: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L006e60bb: { // 0x6e60bb: 0f8751010000 JA 0x006e6212
    if(integer::condition("JA",flags)) goto L006e6212;
  }
  L006e60c1: { // 0x6e60c1: ff248594626e00 JMP dword ptr [EAX*0x4 + 0x6e6294]
    switch(m.r32(((s.ax * 0x00000004u)+0x006e6294u))){
    case 0x006e5fa0u: goto L006e5fa0;
    case 0x006e5fa1u: goto L006e5fa1;
    case 0x006e5fa3u: goto L006e5fa3;
    case 0x006e5fa6u: goto L006e5fa6;
    case 0x006e5facu: goto L006e5fac;
    case 0x006e5fadu: goto L006e5fad;
    case 0x006e5faeu: goto L006e5fae;
    case 0x006e5fb1u: goto L006e5fb1;
    case 0x006e5fb2u: goto L006e5fb2;
    case 0x006e5fb5u: goto L006e5fb5;
    case 0x006e5fb7u: goto L006e5fb7;
    case 0x006e5fbdu: goto L006e5fbd;
    case 0x006e5fc0u: goto L006e5fc0;
    case 0x006e5fc5u: goto L006e5fc5;
    case 0x006e5fc7u: goto L006e5fc7;
    case 0x006e5fcbu: goto L006e5fcb;
    case 0x006e5fcfu: goto L006e5fcf;
    case 0x006e5fd2u: goto L006e5fd2;
    case 0x006e5fd3u: goto L006e5fd3;
    case 0x006e5fd7u: goto L006e5fd7;
    case 0x006e5fdcu: goto L006e5fdc;
    case 0x006e5fdfu: goto L006e5fdf;
    case 0x006e5fe3u: goto L006e5fe3;
    case 0x006e5fe8u: goto L006e5fe8;
    case 0x006e5febu: goto L006e5feb;
    case 0x006e5fedu: goto L006e5fed;
    case 0x006e5ff3u: goto L006e5ff3;
    case 0x006e5ff5u: goto L006e5ff5;
    case 0x006e5ff7u: goto L006e5ff7;
    case 0x006e5ff9u: goto L006e5ff9;
    case 0x006e5ffcu: goto L006e5ffc;
    case 0x006e5ffeu: goto L006e5ffe;
    case 0x006e6001u: goto L006e6001;
    case 0x006e6003u: goto L006e6003;
    case 0x006e6005u: goto L006e6005;
    case 0x006e6009u: goto L006e6009;
    case 0x006e600eu: goto L006e600e;
    case 0x006e6010u: goto L006e6010;
    case 0x006e6011u: goto L006e6011;
    case 0x006e6013u: goto L006e6013;
    case 0x006e601au: goto L006e601a;
    case 0x006e601bu: goto L006e601b;
    case 0x006e601cu: goto L006e601c;
    case 0x006e6021u: goto L006e6021;
    case 0x006e6022u: goto L006e6022;
    case 0x006e6026u: goto L006e6026;
    case 0x006e602bu: goto L006e602b;
    case 0x006e602fu: goto L006e602f;
    case 0x006e6031u: goto L006e6031;
    case 0x006e6032u: goto L006e6032;
    case 0x006e6039u: goto L006e6039;
    case 0x006e603eu: goto L006e603e;
    case 0x006e6040u: goto L006e6040;
    case 0x006e6047u: goto L006e6047;
    case 0x006e604cu: goto L006e604c;
    case 0x006e6051u: goto L006e6051;
    case 0x006e6053u: goto L006e6053;
    case 0x006e6056u: goto L006e6056;
    case 0x006e605au: goto L006e605a;
    case 0x006e605cu: goto L006e605c;
    case 0x006e6061u: goto L006e6061;
    case 0x006e6065u: goto L006e6065;
    case 0x006e6067u: goto L006e6067;
    case 0x006e6069u: goto L006e6069;
    case 0x006e606au: goto L006e606a;
    case 0x006e606bu: goto L006e606b;
    case 0x006e606cu: goto L006e606c;
    case 0x006e606eu: goto L006e606e;
    case 0x006e606fu: goto L006e606f;
    case 0x006e6072u: goto L006e6072;
    case 0x006e6079u: goto L006e6079;
    case 0x006e607au: goto L006e607a;
    case 0x006e607bu: goto L006e607b;
    case 0x006e6080u: goto L006e6080;
    case 0x006e6081u: goto L006e6081;
    case 0x006e6085u: goto L006e6085;
    case 0x006e608au: goto L006e608a;
    case 0x006e608du: goto L006e608d;
    case 0x006e6092u: goto L006e6092;
    case 0x006e6096u: goto L006e6096;
    case 0x006e609au: goto L006e609a;
    case 0x006e609cu: goto L006e609c;
    case 0x006e60a1u: goto L006e60a1;
    case 0x006e60a5u: goto L006e60a5;
    case 0x006e60a7u: goto L006e60a7;
    case 0x006e60a9u: goto L006e60a9;
    case 0x006e60aau: goto L006e60aa;
    case 0x006e60abu: goto L006e60ab;
    case 0x006e60acu: goto L006e60ac;
    case 0x006e60aeu: goto L006e60ae;
    case 0x006e60afu: goto L006e60af;
    case 0x006e60b2u: goto L006e60b2;
    case 0x006e60b5u: goto L006e60b5;
    case 0x006e60b8u: goto L006e60b8;
    case 0x006e60bbu: goto L006e60bb;
    case 0x006e60c1u: goto L006e60c1;
    case 0x006e60c8u: goto L006e60c8;
    case 0x006e60d0u: goto L006e60d0;
    case 0x006e60d8u: goto L006e60d8;
    case 0x006e60ddu: goto L006e60dd;
    case 0x006e60e5u: goto L006e60e5;
    case 0x006e60edu: goto L006e60ed;
    case 0x006e60f2u: goto L006e60f2;
    case 0x006e60f4u: goto L006e60f4;
    case 0x006e60f6u: goto L006e60f6;
    case 0x006e60fcu: goto L006e60fc;
    case 0x006e60ffu: goto L006e60ff;
    case 0x006e6101u: goto L006e6101;
    case 0x006e6105u: goto L006e6105;
    case 0x006e6107u: goto L006e6107;
    case 0x006e610du: goto L006e610d;
    case 0x006e6113u: goto L006e6113;
    case 0x006e6117u: goto L006e6117;
    case 0x006e611cu: goto L006e611c;
    case 0x006e611fu: goto L006e611f;
    case 0x006e6122u: goto L006e6122;
    case 0x006e6125u: goto L006e6125;
    case 0x006e6127u: goto L006e6127;
    case 0x006e612du: goto L006e612d;
    case 0x006e612fu: goto L006e612f;
    case 0x006e6131u: goto L006e6131;
    case 0x006e6133u: goto L006e6133;
    case 0x006e6135u: goto L006e6135;
    case 0x006e6137u: goto L006e6137;
    case 0x006e6139u: goto L006e6139;
    case 0x006e613bu: goto L006e613b;
    case 0x006e613fu: goto L006e613f;
    case 0x006e6143u: goto L006e6143;
    case 0x006e6147u: goto L006e6147;
    case 0x006e614du: goto L006e614d;
    case 0x006e6151u: goto L006e6151;
    case 0x006e6156u: goto L006e6156;
    case 0x006e6158u: goto L006e6158;
    case 0x006e615au: goto L006e615a;
    case 0x006e6160u: goto L006e6160;
    case 0x006e6163u: goto L006e6163;
    case 0x006e6165u: goto L006e6165;
    case 0x006e6169u: goto L006e6169;
    case 0x006e616bu: goto L006e616b;
    case 0x006e6171u: goto L006e6171;
    case 0x006e6173u: goto L006e6173;
    case 0x006e6176u: goto L006e6176;
    case 0x006e6179u: goto L006e6179;
    case 0x006e617cu: goto L006e617c;
    case 0x006e617eu: goto L006e617e;
    case 0x006e6184u: goto L006e6184;
    case 0x006e6186u: goto L006e6186;
    case 0x006e6188u: goto L006e6188;
    case 0x006e618au: goto L006e618a;
    case 0x006e618cu: goto L006e618c;
    case 0x006e618eu: goto L006e618e;
    case 0x006e6190u: goto L006e6190;
    case 0x006e6192u: goto L006e6192;
    case 0x006e6196u: goto L006e6196;
    case 0x006e619au: goto L006e619a;
    case 0x006e619eu: goto L006e619e;
    case 0x006e61a4u: goto L006e61a4;
    case 0x006e61a6u: goto L006e61a6;
    case 0x006e61acu: goto L006e61ac;
    case 0x006e61b0u: goto L006e61b0;
    case 0x006e61b2u: goto L006e61b2;
    case 0x006e61b4u: goto L006e61b4;
    case 0x006e61b6u: goto L006e61b6;
    case 0x006e61b8u: goto L006e61b8;
    case 0x006e61beu: goto L006e61be;
    case 0x006e61c1u: goto L006e61c1;
    case 0x006e61c3u: goto L006e61c3;
    case 0x006e61c7u: goto L006e61c7;
    case 0x006e61c9u: goto L006e61c9;
    case 0x006e61cfu: goto L006e61cf;
    case 0x006e61d1u: goto L006e61d1;
    case 0x006e61d4u: goto L006e61d4;
    case 0x006e61d7u: goto L006e61d7;
    case 0x006e61dau: goto L006e61da;
    case 0x006e61dcu: goto L006e61dc;
    case 0x006e61e2u: goto L006e61e2;
    case 0x006e61e4u: goto L006e61e4;
    case 0x006e61e6u: goto L006e61e6;
    case 0x006e61e8u: goto L006e61e8;
    case 0x006e61eau: goto L006e61ea;
    case 0x006e61ecu: goto L006e61ec;
    case 0x006e61eeu: goto L006e61ee;
    case 0x006e61f0u: goto L006e61f0;
    case 0x006e61f4u: goto L006e61f4;
    case 0x006e61f8u: goto L006e61f8;
    case 0x006e61fcu: goto L006e61fc;
    case 0x006e6202u: goto L006e6202;
    case 0x006e6204u: goto L006e6204;
    case 0x006e620au: goto L006e620a;
    case 0x006e620eu: goto L006e620e;
    case 0x006e6210u: goto L006e6210;
    case 0x006e6212u: goto L006e6212;
    case 0x006e621au: goto L006e621a;
    case 0x006e6222u: goto L006e6222;
    case 0x006e6229u: goto L006e6229;
    case 0x006e622au: goto L006e622a;
    case 0x006e622bu: goto L006e622b;
    case 0x006e622cu: goto L006e622c;
    case 0x006e6231u: goto L006e6231;
    case 0x006e6232u: goto L006e6232;
    case 0x006e6239u: goto L006e6239;
    case 0x006e623eu: goto L006e623e;
    case 0x006e6240u: goto L006e6240;
    case 0x006e6242u: goto L006e6242;
    case 0x006e6244u: goto L006e6244;
    case 0x006e6247u: goto L006e6247;
    case 0x006e6249u: goto L006e6249;
    case 0x006e624du: goto L006e624d;
    case 0x006e6253u: goto L006e6253;
    case 0x006e6258u: goto L006e6258;
    case 0x006e625bu: goto L006e625b;
    case 0x006e625eu: goto L006e625e;
    case 0x006e6260u: goto L006e6260;
    case 0x006e6262u: goto L006e6262;
    case 0x006e6266u: goto L006e6266;
    case 0x006e6267u: goto L006e6267;
    case 0x006e626eu: goto L006e626e;
    case 0x006e6271u: goto L006e6271;
    case 0x006e6276u: goto L006e6276;
    case 0x006e6279u: goto L006e6279;
    case 0x006e627eu: goto L006e627e;
    case 0x006e6285u: goto L006e6285;
    case 0x006e6287u: goto L006e6287;
    case 0x006e6289u: goto L006e6289;
    case 0x006e628au: goto L006e628a;
    case 0x006e628bu: goto L006e628b;
    case 0x006e628cu: goto L006e628c;
    case 0x006e628eu: goto L006e628e;
    case 0x006e628fu: goto L006e628f;
    default:throw std::domain_error("numeric105 unsupported switch destination");}
  }
  L006e60c8: { // 0x6e60c8: c7442410182d4454 MOV dword ptr [ESP + 0x10],0x54442d18
    m.w32((f.sp+0x00000010u), 0x54442d18u);
  }
  L006e60d0: { // 0x6e60d0: c7442414fb21f93f MOV dword ptr [ESP + 0x14],0x3ff921fb
    m.w32((f.sp+0x00000014u), 0x3ff921fbu);
  }
  L006e60d8: { // 0x6e60d8: e945010000 JMP 0x006e6222
    goto L006e6222;
  }
  L006e60dd: { // 0x6e60dd: c7442410182d4454 MOV dword ptr [ESP + 0x10],0x54442d18
    m.w32((f.sp+0x00000010u), 0x54442d18u);
  }
  L006e60e5: { // 0x6e60e5: c7442414fb21f9bf MOV dword ptr [ESP + 0x14],0xbff921fb
    m.w32((f.sp+0x00000014u), 0xbff921fbu);
  }
  L006e60ed: { // 0x6e60ed: e930010000 JMP 0x006e6222
    goto L006e6222;
  }
  L006e60f2: { // 0x6e60f2: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006e60f4: { // 0x6e60f4: 7406 JZ 0x006e60fc
    if(integer::condition("JZ",flags)) goto L006e60fc;
  }
  L006e60f6: { // 0x6e60f6: c703ffffffff MOV dword ptr [EBX],0xffffffff
    m.w32((s.bx), 0xffffffffu);
  }
  L006e60fc: { // 0x6e60fc: 8b7e30 MOV EDI,dword ptr [ESI + 0x30]
    s.di = m.r32((s.si+0x00000030u));
  }
  L006e60ff: { // 0x6e60ff: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006e6101: { // 0x6e6101: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006e6105: { // 0x6e6105: 7515 JNZ 0x006e611c
    if(integer::condition("JNZ",flags)) goto L006e611c;
  }
  L006e6107: { // 0x6e6107: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006e610d: { // 0x6e610d: dc0d30667800 FMUL double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.multiply64(read64(m,address));
  }
  L006e6113: { // 0x6e6113: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006e6117: { // 0x6e6117: e906010000 JMP 0x006e6222
    goto L006e6222;
  }
  L006e611c: { // 0x6e611c: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L006e611f: { // 0x6e611f: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L006e6122: { // 0x6e6122: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006e6125: { // 0x6e6125: 7412 JZ 0x006e6139
    if(integer::condition("JZ",flags)) goto L006e6139;
  }
  L006e6127: { // 0x6e6127: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006e612d: { // 0x6e612d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006e612f: { // 0x6e612f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006e6131: { // 0x6e6131: 7d04 JGE 0x006e6137
    if(integer::condition("JGE",flags)) goto L006e6137;
  }
  L006e6133: { // 0x6e6133: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006e6135: { // 0x6e6135: eb02 JMP 0x006e6139
    goto L006e6139;
  }
  L006e6137: { // 0x6e6137: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006e6139: { // 0x6e6139: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L006e613b: { // 0x6e613b: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L006e613f: { // 0x6e613f: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L006e6143: { // 0x6e6143: da742410 FIDIV dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.divide_integer32(m.r32(address));
  }
  L006e6147: { // 0x6e6147: dc0d30667800 FMUL double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.multiply64(read64(m,address));
  }
  L006e614d: { // 0x6e614d: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006e6151: { // 0x6e6151: e9cc000000 JMP 0x006e6222
    goto L006e6222;
  }
  L006e6156: { // 0x6e6156: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006e6158: { // 0x6e6158: 7406 JZ 0x006e6160
    if(integer::condition("JZ",flags)) goto L006e6160;
  }
  L006e615a: { // 0x6e615a: c703ffffffff MOV dword ptr [EBX],0xffffffff
    m.w32((s.bx), 0xffffffffu);
  }
  L006e6160: { // 0x6e6160: 8b7e30 MOV EDI,dword ptr [ESI + 0x30]
    s.di = m.r32((s.si+0x00000030u));
  }
  L006e6163: { // 0x6e6163: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006e6165: { // 0x6e6165: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L006e6169: { // 0x6e6169: 7508 JNZ 0x006e6173
    if(integer::condition("JNZ",flags)) goto L006e6173;
  }
  L006e616b: { // 0x6e616b: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006e6171: { // 0x6e6171: eb2b JMP 0x006e619e
    goto L006e619e;
  }
  L006e6173: { // 0x6e6173: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L006e6176: { // 0x6e6176: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L006e6179: { // 0x6e6179: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006e617c: { // 0x6e617c: 7412 JZ 0x006e6190
    if(integer::condition("JZ",flags)) goto L006e6190;
  }
  L006e617e: { // 0x6e617e: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006e6184: { // 0x6e6184: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006e6186: { // 0x6e6186: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006e6188: { // 0x6e6188: 7d04 JGE 0x006e618e
    if(integer::condition("JGE",flags)) goto L006e618e;
  }
  L006e618a: { // 0x6e618a: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006e618c: { // 0x6e618c: eb02 JMP 0x006e6190
    goto L006e6190;
  }
  L006e618e: { // 0x6e618e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006e6190: { // 0x6e6190: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L006e6192: { // 0x6e6192: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006e6196: { // 0x6e6196: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006e619a: { // 0x6e619a: da742424 FIDIV dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.divide_integer32(m.r32(address));
  }
  L006e619e: { // 0x6e619e: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006e61a4: { // 0x6e61a4: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L006e61a6: { // 0x6e61a6: dc0d783e7900 FMUL double ptr [0x00793e78]
    const auto address=(0x00793e78u);
    s.fp.multiply64(read64(m,address));
  }
  L006e61ac: { // 0x6e61ac: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006e61b0: { // 0x6e61b0: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006e61b2: { // 0x6e61b2: eb6e JMP 0x006e6222
    goto L006e6222;
  }
  L006e61b4: { // 0x6e61b4: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006e61b6: { // 0x6e61b6: 7406 JZ 0x006e61be
    if(integer::condition("JZ",flags)) goto L006e61be;
  }
  L006e61b8: { // 0x6e61b8: c703ffffffff MOV dword ptr [EBX],0xffffffff
    m.w32((s.bx), 0xffffffffu);
  }
  L006e61be: { // 0x6e61be: 8b7e30 MOV EDI,dword ptr [ESI + 0x30]
    s.di = m.r32((s.si+0x00000030u));
  }
  L006e61c1: { // 0x6e61c1: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006e61c3: { // 0x6e61c3: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L006e61c7: { // 0x6e61c7: 7508 JNZ 0x006e61d1
    if(integer::condition("JNZ",flags)) goto L006e61d1;
  }
  L006e61c9: { // 0x6e61c9: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006e61cf: { // 0x6e61cf: eb2b JMP 0x006e61fc
    goto L006e61fc;
  }
  L006e61d1: { // 0x6e61d1: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L006e61d4: { // 0x6e61d4: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L006e61d7: { // 0x6e61d7: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006e61da: { // 0x6e61da: 7412 JZ 0x006e61ee
    if(integer::condition("JZ",flags)) goto L006e61ee;
  }
  L006e61dc: { // 0x6e61dc: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006e61e2: { // 0x6e61e2: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006e61e4: { // 0x6e61e4: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006e61e6: { // 0x6e61e6: 7d04 JGE 0x006e61ec
    if(integer::condition("JGE",flags)) goto L006e61ec;
  }
  L006e61e8: { // 0x6e61e8: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006e61ea: { // 0x6e61ea: eb02 JMP 0x006e61ee
    goto L006e61ee;
  }
  L006e61ec: { // 0x6e61ec: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006e61ee: { // 0x6e61ee: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L006e61f0: { // 0x6e61f0: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006e61f4: { // 0x6e61f4: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006e61f8: { // 0x6e61f8: da742424 FIDIV dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.divide_integer32(m.r32(address));
  }
  L006e61fc: { // 0x6e61fc: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006e6202: { // 0x6e6202: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L006e6204: { // 0x6e6204: dc0d30667800 FMUL double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.multiply64(read64(m,address));
  }
  L006e620a: { // 0x6e620a: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006e620e: { // 0x6e620e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006e6210: { // 0x6e6210: eb10 JMP 0x006e6222
    goto L006e6222;
  }
  L006e6212: { // 0x6e6212: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L006e621a: { // 0x6e621a: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L006e6222: { // 0x6e6222: 8d9424b8000000 LEA EDX,[ESP + 0xb8]
    s.dx = (f.sp+0x000000b8u);
  }
  L006e6229: { // 0x6e6229: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006e622a: { // 0x6e622a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006e622b: { // 0x6e622b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e622c: { // 0x6e622c: e8df4fe5ff CALL 0x0053b210
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053b210u,7234097u); flags=s.arithmetic_flags;
  }
  L006e6231: { // 0x6e6231: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006e6232: { // 0x6e6232: 8d8c248c000000 LEA ECX,[ESP + 0x8c]
    s.cx = (f.sp+0x0000008cu);
  }
  L006e6239: { // 0x6e6239: e8d269eaff CALL 0x0058cc10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cc10u,7234110u); flags=s.arithmetic_flags;
  }
  L006e623e: { // 0x6e623e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006e6240: { // 0x6e6240: 7420 JZ 0x006e6262
    if(integer::condition("JZ",flags)) goto L006e6262;
  }
  L006e6242: { // 0x6e6242: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L006e6244: { // 0x6e6244: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L006e6247: { // 0x6e6247: 7419 JZ 0x006e6262
    if(integer::condition("JZ",flags)) goto L006e6262;
  }
  L006e6249: { // 0x6e6249: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L006e624d: { // 0x6e624d: dc0d588b7900 FMUL double ptr [0x00798b58]
    const auto address=(0x00798b58u);
    s.fp.multiply64(read64(m,address));
  }
  L006e6253: { // 0x6e6253: e8f8470800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7234136u); flags=s.arithmetic_flags;
  }
  L006e6258: { // 0x6e6258: 83e03f AND EAX,0x3f
    s.ax = integer::logical((s.ax)&(0x0000003fu),32,flags);
  }
  L006e625b: { // 0x6e625b: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  L006e625e: { // 0x6e625e: 0bc6 OR EAX,ESI
    s.ax = integer::logical((s.ax)|(s.si),32,flags);
  }
  L006e6260: { // 0x6e6260: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L006e6262: { // 0x6e6262: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L006e6266: { // 0x6e6266: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e6267: { // 0x6e6267: 8d8c248c000000 LEA ECX,[ESP + 0x8c]
    s.cx = (f.sp+0x0000008cu);
  }
  L006e626e: { // 0x6e626e: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006e6271: { // 0x6e6271: e80a74eaff CALL 0x0058d680
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d680u,7234166u); flags=s.arithmetic_flags;
  }
  L006e6276: { // 0x6e6276: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L006e6279: { // 0x6e6279: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006e627e: { // 0x6e627e: 8db42488000000 LEA ESI,[ESP + 0x88]
    s.si = (f.sp+0x00000088u);
  }
  L006e6285: { // 0x6e6285: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006e6287: { // 0x6e6287: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006e6289: { // 0x6e6289: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e628a: { // 0x6e628a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e628b: { // 0x6e628b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e628c: { // 0x6e628c: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006e628e: { // 0x6e628e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e628f: { // 0x6e628f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00708af0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00708af0: { // 0x708af0: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L00708af3: { // 0x708af3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00708af4: { // 0x708af4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00708af5: { // 0x708af5: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00708af7: { // 0x708af7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00708af8: { // 0x708af8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00708af9: { // 0x708af9: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00708afd: { // 0x708afd: c7450000000000 MOV dword ptr [EBP],0x0
    m.w32((s.bp), 0x00000000u);
  }
  L00708b04: { // 0x708b04: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00708b06: { // 0x708b06: db0578198200 FILD dword ptr [0x00821978]
    const auto address=(0x00821978u);
    s.fp.load_integer32(m.r32(address));
  }
  L00708b0c: { // 0x708b0c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00708b0e: { // 0x708b0e: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00708b16: { // 0x708b16: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
  L00708b1c: { // 0x708b1c: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708b20: { // 0x708b20: db057c198200 FILD dword ptr [0x0082197c]
    const auto address=(0x0082197cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00708b26: { // 0x708b26: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
  L00708b2c: { // 0x708b2c: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708b30: { // 0x708b30: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L00708b34: { // 0x708b34: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00708b36: { // 0x708b36: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708b3a: { // 0x708b3a: e8d1c5cfff CALL 0x00405110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405110u,7375679u); flags=s.arithmetic_flags;
  }
  L00708b3f: { // 0x708b3f: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00708b42: { // 0x708b42: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00708b44: { // 0x708b44: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00708b47: { // 0x708b47: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00708b4a: { // 0x708b4a: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00708b4e: { // 0x708b4e: db442438 FILD dword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load_integer32(m.r32(address));
  }
  L00708b52: { // 0x708b52: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708b56: { // 0x708b56: e8e5c5cfff CALL 0x00405140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405140u,7375707u); flags=s.arithmetic_flags;
  }
  L00708b5b: { // 0x708b5b: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00708b5d: { // 0x708b5d: f6c708 TEST BH,0x8
    (void)integer::logical((((s.bx >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00708b60: { // 0x708b60: 747b JZ 0x00708bdd
    if(integer::condition("JZ",flags)) goto L00708bdd;
  }
  L00708b62: { // 0x708b62: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00708b64: { // 0x708b64: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00708b65: { // 0x708b65: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00708b6b: { // 0x708b6b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00708b6d: { // 0x708b6d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00708b6f: { // 0x708b6f: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00708b72: { // 0x708b72: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00708b73: { // 0x708b73: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00708b79: { // 0x708b79: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00708b7b: { // 0x708b7b: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00708b7e: { // 0x708b7e: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00708b81: { // 0x708b81: 663b0d4082ab00 CMP CX,word ptr [0x00ab8240]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00ab8240u)),16,flags);
  }
  L00708b88: { // 0x708b88: 66894c2438 MOV word ptr [ESP + 0x38],CX
    m.w16((f.sp+0x00000038u), (s.cx & 0xffffu));
  }
  L00708b8d: { // 0x708b8d: 668944243a MOV word ptr [ESP + 0x3a],AX
    m.w16((f.sp+0x0000003au), (s.ax & 0xffffu));
  }
  L00708b92: { // 0x708b92: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00708b96: { // 0x708b96: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00708b9a: { // 0x708b9a: 7519 JNZ 0x00708bb5
    if(integer::condition("JNZ",flags)) goto L00708bb5;
  }
  L00708b9c: { // 0x708b9c: 663b054282ab00 CMP AX,word ptr [0x00ab8242]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00ab8242u)),16,flags);
  }
  L00708ba3: { // 0x708ba3: 7510 JNZ 0x00708bb5
    if(integer::condition("JNZ",flags)) goto L00708bb5;
  }
  L00708ba5: { // 0x708ba5: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L00708bab: { // 0x708bab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00708bac: { // 0x708bac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00708bad: { // 0x708bad: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00708bae: { // 0x708bae: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00708baf: { // 0x708baf: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00708bb2: { // 0x708bb2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00708bb5: { // 0x708bb5: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00708bb9: { // 0x708bb9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00708bbe: { // 0x708bbe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00708bbf: { // 0x708bbf: e83cc9e3ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7375812u); flags=s.arithmetic_flags;
  }
  L00708bc4: { // 0x708bc4: f6802c01000018 TEST byte ptr [EAX + 0x12c],0x18
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&(0x00000018u),8,flags);
  }
  L00708bcb: { // 0x708bcb: 7510 JNZ 0x00708bdd
    if(integer::condition("JNZ",flags)) goto L00708bdd;
  }
  L00708bcd: { // 0x708bcd: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L00708bd3: { // 0x708bd3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00708bd4: { // 0x708bd4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00708bd5: { // 0x708bd5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00708bd6: { // 0x708bd6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00708bd7: { // 0x708bd7: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00708bda: { // 0x708bda: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00708bdd: { // 0x708bdd: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00708be1: { // 0x708be1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00708be2: { // 0x708be2: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00708be8: { // 0x708be8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00708be9: { // 0x708be9: e822f4f8ff CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7375854u); flags=s.arithmetic_flags;
  }
  L00708bee: { // 0x708bee: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00708bf2: { // 0x708bf2: d8642420 FSUB float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.subtract32(m.r32(address));
  }
  L00708bf6: { // 0x708bf6: d9542410 FST float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00708bfa: { // 0x708bfa: e8511e0600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7375871u); flags=s.arithmetic_flags;
  }
  L00708bff: { // 0x708bff: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00708c00: { // 0x708c00: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00708c02: { // 0x708c02: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00708c04: { // 0x708c04: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00708c08: { // 0x708c08: db442438 FILD dword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load_integer32(m.r32(address));
  }
  L00708c0c: { // 0x708c0c: d95c2438 FSTP float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708c10: { // 0x708c10: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L00708c14: { // 0x708c14: d8642424 FSUB float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.subtract32(m.r32(address));
  }
  L00708c18: { // 0x708c18: e8331e0600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7375901u); flags=s.arithmetic_flags;
  }
  L00708c1d: { // 0x708c1d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00708c1e: { // 0x708c1e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00708c20: { // 0x708c20: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00708c22: { // 0x708c22: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00708c26: { // 0x708c26: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L00708c2a: { // 0x708c2a: f6c340 TEST BL,0x40
    (void)integer::logical(((s.bx & 0xffu))&(0x00000040u),8,flags);
  }
  L00708c2d: { // 0x708c2d: 753e JNZ 0x00708c6d
    if(integer::condition("JNZ",flags)) goto L00708c6d;
  }
  L00708c2f: { // 0x708c2f: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L00708c33: { // 0x708c33: d8642420 FSUB float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.subtract32(m.r32(address));
  }
  L00708c37: { // 0x708c37: d9542438 FST float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00708c3b: { // 0x708c3b: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L00708c3d: { // 0x708c3d: d8642424 FSUB float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.subtract32(m.r32(address));
  }
  L00708c41: { // 0x708c41: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L00708c43: { // 0x708c43: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00708c49: { // 0x708c49: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708c4b: { // 0x708c4b: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00708c4e: { // 0x708c4e: 7408 JZ 0x00708c58
    if(integer::condition("JZ",flags)) goto L00708c58;
  }
  L00708c50: { // 0x708c50: c744243800000000 MOV dword ptr [ESP + 0x38],0x0
    m.w32((f.sp+0x00000038u), 0x00000000u);
  }
  L00708c58: { // 0x708c58: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L00708c5e: { // 0x708c5e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708c60: { // 0x708c60: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00708c63: { // 0x708c63: 7408 JZ 0x00708c6d
    if(integer::condition("JZ",flags)) goto L00708c6d;
  }
  L00708c65: { // 0x708c65: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00708c67: { // 0x708c67: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L00708c6d: { // 0x708c6d: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00708c6f: { // 0x708c6f: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708c73: { // 0x708c73: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L00708c77: { // 0x708c77: d85c2414 FCOMP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00708c7b: { // 0x708c7b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708c7d: { // 0x708c7d: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00708c80: { // 0x708c80: 7449 JZ 0x00708ccb
    if(integer::condition("JZ",flags)) goto L00708ccb;
  }
  L00708c82: { // 0x708c82: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L00708c86: { // 0x708c86: d85c2414 FCOMP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00708c8a: { // 0x708c8a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708c8c: { // 0x708c8c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00708c8f: { // 0x708c8f: 743a JZ 0x00708ccb
    if(integer::condition("JZ",flags)) goto L00708ccb;
  }
  L00708c91: { // 0x708c91: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L00708c95: { // 0x708c95: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00708c9b: { // 0x708c9b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708c9d: { // 0x708c9d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00708ca0: { // 0x708ca0: 7529 JNZ 0x00708ccb
    if(integer::condition("JNZ",flags)) goto L00708ccb;
  }
  L00708ca2: { // 0x708ca2: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L00708ca6: { // 0x708ca6: d85c2420 FCOMP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00708caa: { // 0x708caa: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708cac: { // 0x708cac: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00708caf: { // 0x708caf: 7506 JNZ 0x00708cb7
    if(integer::condition("JNZ",flags)) goto L00708cb7;
  }
  L00708cb1: { // 0x708cb1: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L00708cb5: { // 0x708cb5: eb04 JMP 0x00708cbb
    goto L00708cbb;
  }
  L00708cb7: { // 0x708cb7: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L00708cbb: { // 0x708cbb: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L00708cbf: { // 0x708cbf: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00708cc1: { // 0x708cc1: d8742414 FDIV float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    floating_b61::fp_extended::divide32(s.fp,m.r32(address));
  }
  L00708cc5: { // 0x708cc5: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708cc9: { // 0x708cc9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00708ccb: { // 0x708ccb: f6c310 TEST BL,0x10
    (void)integer::logical(((s.bx & 0xffu))&(0x00000010u),8,flags);
  }
  L00708cce: { // 0x708cce: 741d JZ 0x00708ced
    if(integer::condition("JZ",flags)) goto L00708ced;
  }
  L00708cd0: { // 0x708cd0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00708cd2: { // 0x708cd2: e849c4cfff CALL 0x00405120
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405120u,7376087u); flags=s.arithmetic_flags;
  }
  L00708cd7: { // 0x708cd7: d85c2418 FCOMP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00708cdb: { // 0x708cdb: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708cdd: { // 0x708cdd: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00708ce0: { // 0x708ce0: 750b JNZ 0x00708ced
    if(integer::condition("JNZ",flags)) goto L00708ced;
  }
  L00708ce2: { // 0x708ce2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00708ce4: { // 0x708ce4: e837c4cfff CALL 0x00405120
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405120u,7376105u); flags=s.arithmetic_flags;
  }
  L00708ce9: { // 0x708ce9: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708ced: { // 0x708ced: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L00708cf1: { // 0x708cf1: dc1df8c07800 FCOMP double ptr [0x0078c0f8]
    const auto address=(0x0078c0f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00708cf7: { // 0x708cf7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708cf9: { // 0x708cf9: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00708cfc: { // 0x708cfc: 7410 JZ 0x00708d0e
    if(integer::condition("JZ",flags)) goto L00708d0e;
  }
  L00708cfe: { // 0x708cfe: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L00708d04: { // 0x708d04: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00708d05: { // 0x708d05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00708d06: { // 0x708d06: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00708d07: { // 0x708d07: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00708d08: { // 0x708d08: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00708d0b: { // 0x708d0b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00708d0e: { // 0x708d0e: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L00708d12: { // 0x708d12: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00708d14: { // 0x708d14: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L00708d18: { // 0x708d18: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L00708d1a: { // 0x708d1a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708d1c: { // 0x708d1c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00708d1f: { // 0x708d1f: 7406 JZ 0x00708d27
    if(integer::condition("JZ",flags)) goto L00708d27;
  }
  L00708d21: { // 0x708d21: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00708d25: { // 0x708d25: eb19 JMP 0x00708d40
    goto L00708d40;
  }
  L00708d27: { // 0x708d27: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00708d29: { // 0x708d29: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L00708d2d: { // 0x708d2d: d85c241c FCOMP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.compare_pop32(m.r32(address));
  }
  L00708d31: { // 0x708d31: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00708d33: { // 0x708d33: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00708d36: { // 0x708d36: 7508 JNZ 0x00708d40
    if(integer::condition("JNZ",flags)) goto L00708d40;
  }
  L00708d38: { // 0x708d38: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00708d3c: { // 0x708d3c: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00708d40: { // 0x708d40: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L00708d44: { // 0x708d44: d80d58987900 FMUL float ptr [0x00799858]
    const auto address=(0x00799858u);
    s.fp.multiply32(m.r32(address));
  }
  L00708d4a: { // 0x708d4a: d874241c FDIV float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::divide32(s.fp,m.r32(address));
  }
  L00708d4e: { // 0x708d4e: d80558987900 FADD float ptr [0x00799858]
    const auto address=(0x00799858u);
    s.fp.add32(m.r32(address));
  }
  L00708d54: { // 0x708d54: e8f71c0600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7376217u); flags=s.arithmetic_flags;
  }
  L00708d59: { // 0x708d59: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L00708d5d: { // 0x708d5d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00708d5e: { // 0x708d5e: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  L00708d61: { // 0x708d61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00708d62: { // 0x708d62: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00708d63: { // 0x708d63: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00708d64: { // 0x708d64: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00708d67: { // 0x708d67: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0070bc90(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0070bc90: { // 0x70bc90: 81ecc0000000 SUB ESP,0xc0
    f.sp = integer::sub(f.sp,0x000000c0u,32,flags);
  }
  L0070bc96: { // 0x70bc96: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0070bc97: { // 0x70bc97: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0070bc98: { // 0x70bc98: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0070bc9a: { // 0x70bc9a: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0070bc9c: { // 0x70bc9c: 8b9424d0000000 MOV EDX,dword ptr [ESP + 0xd0]
    s.dx = m.r32((f.sp+0x000000d0u));
  }
  L0070bca3: { // 0x70bca3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0070bca4: { // 0x70bca4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0070bca5: { // 0x70bca5: 8d8c24a0000000 LEA ECX,[ESP + 0xa0]
    s.cx = (f.sp+0x000000a0u);
  }
  L0070bcac: { // 0x70bcac: e86f25e8ff CALL 0x0058e220
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e220u,7388337u); flags=s.arithmetic_flags;
  }
  L0070bcb1: { // 0x70bcb1: 8b9424dc000000 MOV EDX,dword ptr [ESP + 0xdc]
    s.dx = m.r32((f.sp+0x000000dcu));
  }
  L0070bcb8: { // 0x70bcb8: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0070bcbd: { // 0x70bcbd: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0070bcbf: { // 0x70bcbf: 8d7c2470 LEA EDI,[ESP + 0x70]
    s.di = (f.sp+0x00000070u);
  }
  L0070bcc3: { // 0x70bcc3: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0070bcc5: { // 0x70bcc5: 8d8c24a0000000 LEA ECX,[ESP + 0xa0]
    s.cx = (f.sp+0x000000a0u);
  }
  L0070bccc: { // 0x70bccc: e84f25e8ff CALL 0x0058e220
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e220u,7388369u); flags=s.arithmetic_flags;
  }
  L0070bcd1: { // 0x70bcd1: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0070bcd6: { // 0x70bcd6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0070bcd8: { // 0x70bcd8: 8b8424e0000000 MOV EAX,dword ptr [ESP + 0xe0]
    s.ax = m.r32((f.sp+0x000000e0u));
  }
  L0070bcdf: { // 0x70bcdf: 8d7c2440 LEA EDI,[ESP + 0x40]
    s.di = (f.sp+0x00000040u);
  }
  L0070bce3: { // 0x70bce3: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0070bce5: { // 0x70bce5: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0070bce9: { // 0x70bce9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0070bcea: { // 0x70bcea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0070bceb: { // 0x70bceb: 8d4c2478 LEA ECX,[ESP + 0x78]
    s.cx = (f.sp+0x00000078u);
  }
  L0070bcef: { // 0x70bcef: e8dc1de8ff CALL 0x0058dad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058dad0u,7388404u); flags=s.arithmetic_flags;
  }
  L0070bcf4: { // 0x70bcf4: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0070bcf6: { // 0x70bcf6: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0070bcfa: { // 0x70bcfa: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0070bcfd: { // 0x70bcfd: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0070bd01: { // 0x70bd01: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L0070bd05: { // 0x70bd05: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0070bd08: { // 0x70bd08: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0070bd0c: { // 0x70bd0c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0070bd0d: { // 0x70bd0d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0070bd0e: { // 0x70bd0e: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L0070bd12: { // 0x70bd12: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0070bd16: { // 0x70bd16: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L0070bd1e: { // 0x70bd1e: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0070bd26: { // 0x70bd26: c74424200000803f MOV dword ptr [ESP + 0x20],0x3f800000
    m.w32((f.sp+0x00000020u), 0x3f800000u);
  }
  L0070bd2e: { // 0x70bd2e: e89d1de8ff CALL 0x0058dad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058dad0u,7388467u); flags=s.arithmetic_flags;
  }
  L0070bd33: { // 0x70bd33: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0070bd35: { // 0x70bd35: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0070bd39: { // 0x70bd39: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0070bd3c: { // 0x70bd3c: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0070bd40: { // 0x70bd40: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0070bd42: { // 0x70bd42: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0070bd45: { // 0x70bd45: 8b8424d4000000 MOV EAX,dword ptr [ESP + 0xd4]
    s.ax = m.r32((f.sp+0x000000d4u));
  }
  L0070bd4c: { // 0x70bd4c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0070bd4d: { // 0x70bd4d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0070bd4e: { // 0x70bd4e: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0070bd52: { // 0x70bd52: e8c9260000 CALL 0x0070e420
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070e420u,7388503u); flags=s.arithmetic_flags;
  }
  L0070bd57: { // 0x70bd57: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0070bd59: { // 0x70bd59: 8a88a3000000 MOV CL,byte ptr [EAX + 0xa3]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000000a3u)));
  }
  L0070bd5f: { // 0x70bd5f: 8b9424e4000000 MOV EDX,dword ptr [ESP + 0xe4]
    s.dx = m.r32((f.sp+0x000000e4u));
  }
  L0070bd66: { // 0x70bd66: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0070bd68: { // 0x70bd68: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0070bd6c: { // 0x70bd6c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0070bd6d: { // 0x70bd6d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0070bd6e: { // 0x70bd6e: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0070bd72: { // 0x70bd72: e8e9480000 CALL 0x00710660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00710660u,7388535u); flags=s.arithmetic_flags;
  }
  L0070bd77: { // 0x70bd77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0070bd78: { // 0x70bd78: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0070bd79: { // 0x70bd79: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0070bd7a: { // 0x70bd7a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0070bd7b: { // 0x70bd7b: 81c4c0000000 ADD ESP,0xc0
    f.sp = integer::add(f.sp,0x000000c0u,32,flags);
  }
  L0070bd81: { // 0x70bd81: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0070cb70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0070cb70: { // 0x70cb70: 83ec48 SUB ESP,0x48
    f.sp = integer::sub(f.sp,0x00000048u,32,flags);
  }
  L0070cb73: { // 0x70cb73: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0070cb77: { // 0x70cb77: e8e402e8ff CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,7392124u); flags=s.arithmetic_flags;
  }
  L0070cb7c: { // 0x70cb7c: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0070cb80: { // 0x70cb80: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0070cb82: { // 0x70cb82: a3ec1d8200 MOV [0x00821dec],EAX
    m.w32((0x00821decu), s.ax);
  }
  L0070cb87: { // 0x70cb87: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0070cb88: { // 0x70cb88: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0070cb8c: { // 0x70cb8c: e8ef0ae8ff CALL 0x0058d680
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d680u,7392145u); flags=s.arithmetic_flags;
  }
  L0070cb91: { // 0x70cb91: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  L0070cb95: { // 0x70cb95: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0070cb99: { // 0x70cb99: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0070cb9a: { // 0x70cb9a: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0070cb9e: { // 0x70cb9e: c7442404e60435bf MOV dword ptr [ESP + 0x4],0xbf3504e6
    m.w32((f.sp+0x00000004u), 0xbf3504e6u);
  }
  L0070cba6: { // 0x70cba6: c7442408e60435bf MOV dword ptr [ESP + 0x8],0xbf3504e6
    m.w32((f.sp+0x00000008u), 0xbf3504e6u);
  }
  L0070cbae: { // 0x70cbae: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L0070cbb6: { // 0x70cbb6: e8c515e8ff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,7392187u); flags=s.arithmetic_flags;
  }
  L0070cbbb: { // 0x70cbbb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0070cbbd: { // 0x70cbbd: 890df01d8200 MOV dword ptr [0x00821df0],ECX
    m.w32((0x00821df0u), s.cx);
  }
  L0070cbc3: { // 0x70cbc3: d905f01d8200 FLD float ptr [0x00821df0]
    const auto address=(0x00821df0u);
    s.fp.load32(m.r32(address));
  }
  L0070cbc9: { // 0x70cbc9: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0070cbcc: { // 0x70cbcc: d80dc0987900 FMUL float ptr [0x007998c0]
    const auto address=(0x007998c0u);
    s.fp.multiply32(m.r32(address));
  }
  L0070cbd2: { // 0x70cbd2: 8915f41d8200 MOV dword ptr [0x00821df4],EDX
    m.w32((0x00821df4u), s.dx);
  }
  L0070cbd8: { // 0x70cbd8: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0070cbdb: { // 0x70cbdb: a3f81d8200 MOV [0x00821df8],EAX
    m.w32((0x00821df8u), s.ax);
  }
  L0070cbe0: { // 0x70cbe0: c744240400000000 MOV dword ptr [ESP + 0x4],0x0
    m.w32((f.sp+0x00000004u), 0x00000000u);
  }
  L0070cbe8: { // 0x70cbe8: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0070cbec: { // 0x70cbec: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L0070cbf4: { // 0x70cbf4: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0070cbf8: { // 0x70cbf8: 8915a41d8200 MOV dword ptr [0x00821da4],EDX
    m.w32((0x00821da4u), s.dx);
  }
  L0070cbfe: { // 0x70cbfe: d95c2400 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0070cc02: { // 0x70cc02: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0070cc06: { // 0x70cc06: a3a81d8200 MOV [0x00821da8],EAX
    m.w32((0x00821da8u), s.ax);
  }
  L0070cc0b: { // 0x70cc0b: 890da01d8200 MOV dword ptr [0x00821da0],ECX
    m.w32((0x00821da0u), s.cx);
  }
  L0070cc11: { // 0x70cc11: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L0070cc14: { // 0x70cc14: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00760f60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760f60: { // 0x760f60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760f61: { // 0x760f61: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00760f63: { // 0x760f63: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00760f66: { // 0x760f66: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L00760f69: { // 0x760f69: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760f6a: { // 0x760f6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760f6b: { // 0x760f6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760f6c: { // 0x760f6c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00760f6e: { // 0x760f6e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00760f70: { // 0x760f70: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00760f73: { // 0x760f73: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00760f77: { // 0x760f77: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00760f79: { // 0x760f79: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L00760f7c: { // 0x760f7c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00760f80: { // 0x760f80: 8b5908 MOV EBX,dword ptr [ECX + 0x8]
    s.bx = m.r32((s.cx+0x00000008u));
  }
  L00760f83: { // 0x760f83: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f87: { // 0x760f87: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00760f8b: { // 0x760f8b: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00760f8d: { // 0x760f8d: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760f91: { // 0x760f91: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f95: { // 0x760f95: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00760f99: { // 0x760f99: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00760f9b: { // 0x760f9b: db02 FILD dword ptr [EDX]
    const auto address=(s.dx);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f9d: { // 0x760f9d: dd5c2438 FSTP double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fa1: { // 0x760fa1: db4204 FILD dword ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fa4: { // 0x760fa4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00760fa6: { // 0x760fa6: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760faa: { // 0x760faa: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fac: { // 0x760fac: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760fb0: { // 0x760fb0: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fb3: { // 0x760fb3: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fb7: { // 0x760fb7: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L00760fbb: { // 0x760fbb: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fbd: { // 0x760fbd: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00760fbf: { // 0x760fbf: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00760fc3: { // 0x760fc3: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L00760fc7: { // 0x760fc7: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fc9: { // 0x760fc9: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fcb: { // 0x760fcb: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fcf: { // 0x760fcf: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fd1: { // 0x760fd1: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fd5: { // 0x760fd5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fd7: { // 0x760fd7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fdb: { // 0x760fdb: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fdf: { // 0x760fdf: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00760fe3: { // 0x760fe3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760fe5: { // 0x760fe5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760fe8: { // 0x760fe8: 7509 JNZ 0x00760ff3
    if(integer::condition("JNZ",flags)) goto L00760ff3;
  }
  L00760fea: { // 0x760fea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fec: { // 0x760fec: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00760ff1: { // 0x760ff1: eb0e JMP 0x00761001
    goto L00761001;
  }
  L00760ff3: { // 0x760ff3: d8dc FCOMP ST4
    numeric_b88::detail::reg<0xd8dc>(s.fp);
  }
  L00760ff5: { // 0x760ff5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760ff7: { // 0x760ff7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760ffa: { // 0x760ffa: 7405 JZ 0x00761001
    if(integer::condition("JZ",flags)) goto L00761001;
  }
  L00760ffc: { // 0x760ffc: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00761001: { // 0x761001: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00761004: { // 0x761004: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00761006: { // 0x761006: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076100a: { // 0x76100a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0076100e: { // 0x76100e: dd5c2450 FSTP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761012: { // 0x761012: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L00761016: { // 0x761016: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0076101a: { // 0x76101a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076101c: { // 0x76101c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076101f: { // 0x76101f: 7505 JNZ 0x00761026
    if(integer::condition("JNZ",flags)) goto L00761026;
  }
  L00761021: { // 0x761021: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L00761024: { // 0x761024: eb10 JMP 0x00761036
    goto L00761036;
  }
  L00761026: { // 0x761026: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0076102a: { // 0x76102a: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076102c: { // 0x76102c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076102e: { // 0x76102e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761031: { // 0x761031: 7403 JZ 0x00761036
    if(integer::condition("JZ",flags)) goto L00761036;
  }
  L00761033: { // 0x761033: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761036: { // 0x761036: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0076103a: { // 0x76103a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076103c: { // 0x76103c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076103e: { // 0x76103e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761041: { // 0x761041: 7509 JNZ 0x0076104c
    if(integer::condition("JNZ",flags)) goto L0076104c;
  }
  L00761043: { // 0x761043: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761045: { // 0x761045: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0076104a: { // 0x76104a: eb0e JMP 0x0076105a
    goto L0076105a;
  }
  L0076104c: { // 0x76104c: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076104e: { // 0x76104e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761050: { // 0x761050: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761053: { // 0x761053: 7405 JZ 0x0076105a
    if(integer::condition("JZ",flags)) goto L0076105a;
  }
  L00761055: { // 0x761055: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0076105a: { // 0x76105a: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L0076105e: { // 0x76105e: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00761062: { // 0x761062: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761064: { // 0x761064: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761067: { // 0x761067: 7505 JNZ 0x0076106e
    if(integer::condition("JNZ",flags)) goto L0076106e;
  }
  L00761069: { // 0x761069: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L0076106c: { // 0x76106c: eb10 JMP 0x0076107e
    goto L0076107e;
  }
  L0076106e: { // 0x76106e: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761072: { // 0x761072: d8da FCOMP ST2
    numeric_b88::detail::reg<0xd8da>(s.fp);
  }
  L00761074: { // 0x761074: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761076: { // 0x761076: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761079: { // 0x761079: 7403 JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076107b: { // 0x76107b: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  L0076107e: { // 0x76107e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761080: { // 0x761080: 7508 JNZ 0x0076108a
    if(integer::condition("JNZ",flags)) goto L0076108a;
  }
  L00761082: { // 0x761082: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00761084: { // 0x761084: 0f844f010000 JZ 0x007611d9
    if(integer::condition("JZ",flags)) goto L007611d9;
  }
  L0076108a: { // 0x76108a: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076108c: { // 0x76108c: 0f858a010000 JNZ 0x0076121c
    if(integer::condition("JNZ",flags)) goto L0076121c;
  }
  L00761092: { // 0x761092: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761094: { // 0x761094: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00761096: { // 0x761096: 7502 JNZ 0x0076109a
    if(integer::condition("JNZ",flags)) goto L0076109a;
  }
  L00761098: { // 0x761098: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076109a: { // 0x76109a: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0076109c: { // 0x76109c: 7418 JZ 0x007610b6
    if(integer::condition("JZ",flags)) goto L007610b6;
  }
  L0076109e: { // 0x76109e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610a0: { // 0x7610a0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610a2: { // 0x7610a2: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610a6: { // 0x7610a6: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610aa: { // 0x7610aa: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610ae: { // 0x7610ae: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007610b2: { // 0x7610b2: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610b4: { // 0x7610b4: eb72 JMP 0x00761128
    goto L00761128;
  }
  L007610b6: { // 0x7610b6: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L007610b8: { // 0x7610b8: 741f JZ 0x007610d9
    if(integer::condition("JZ",flags)) goto L007610d9;
  }
  L007610ba: { // 0x7610ba: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L007610be: { // 0x7610be: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610bf: { // 0x7610bf: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610c1: { // 0x7610c1: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610c5: { // 0x7610c5: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610c9: { // 0x7610c9: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610cb: { // 0x7610cb: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610cf: { // 0x7610cf: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610d3: { // 0x7610d3: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610d7: { // 0x7610d7: eb4b JMP 0x00761124
    goto L00761124;
  }
  L007610d9: { // 0x7610d9: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L007610db: { // 0x7610db: 7431 JZ 0x0076110e
    if(integer::condition("JZ",flags)) goto L0076110e;
  }
  L007610dd: { // 0x7610dd: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007610e1: { // 0x7610e1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610e2: { // 0x7610e2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610e4: { // 0x7610e4: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610e8: { // 0x7610e8: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610ec: { // 0x7610ec: dd542418 FST double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L007610f0: { // 0x7610f0: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L007610f4: { // 0x7610f4: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L007610f8: { // 0x7610f8: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007610fc: { // 0x7610fc: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L00761100: { // 0x761100: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L00761104: { // 0x761104: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L00761108: { // 0x761108: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L0076110c: { // 0x76110c: eb1a JMP 0x00761128
    goto L00761128;
  }
  L0076110e: { // 0x76110e: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00761110: { // 0x761110: 7416 JZ 0x00761128
    if(integer::condition("JZ",flags)) goto L00761128;
  }
  L00761112: { // 0x761112: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761114: { // 0x761114: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761116: { // 0x761116: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L0076111a: { // 0x76111a: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L0076111e: { // 0x76111e: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L00761122: { // 0x761122: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00761124: { // 0x761124: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761128: { // 0x761128: dd442430 FLD double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L0076112c: { // 0x76112c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0076112e: { // 0x76112e: 7556 JNZ 0x00761186
    if(integer::condition("JNZ",flags)) goto L00761186;
  }
  L00761130: { // 0x761130: dd542438 FST double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00761134: { // 0x761134: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761136: { // 0x761136: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00761138: { // 0x761138: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0076113c: { // 0x76113c: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761140: { // 0x761140: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761142: { // 0x761142: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761145: { // 0x761145: 7509 JNZ 0x00761150
    if(integer::condition("JNZ",flags)) goto L00761150;
  }
  L00761147: { // 0x761147: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761149: { // 0x761149: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0076114e: { // 0x76114e: eb0e JMP 0x0076115e
    goto L0076115e;
  }
  L00761150: { // 0x761150: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L00761152: { // 0x761152: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761154: { // 0x761154: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761157: { // 0x761157: 7405 JZ 0x0076115e
    if(integer::condition("JZ",flags)) goto L0076115e;
  }
  L00761159: { // 0x761159: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0076115e: { // 0x76115e: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761162: { // 0x761162: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761164: { // 0x761164: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761167: { // 0x761167: 7508 JNZ 0x00761171
    if(integer::condition("JNZ",flags)) goto L00761171;
  }
  L00761169: { // 0x761169: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L0076116c: { // 0x76116c: e90dffffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761171: { // 0x761171: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L00761173: { // 0x761173: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761175: { // 0x761175: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761178: { // 0x761178: 0f8400ffffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076117e: { // 0x76117e: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761181: { // 0x761181: e9f8feffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761186: { // 0x761186: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0076118a: { // 0x76118a: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0076118c: { // 0x76118c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076118e: { // 0x76118e: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761192: { // 0x761192: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761196: { // 0x761196: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761198: { // 0x761198: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076119b: { // 0x76119b: 7509 JNZ 0x007611a6
    if(integer::condition("JNZ",flags)) goto L007611a6;
  }
  L0076119d: { // 0x76119d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076119f: { // 0x76119f: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L007611a4: { // 0x7611a4: eb0e JMP 0x007611b4
    goto L007611b4;
  }
  L007611a6: { // 0x7611a6: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L007611a8: { // 0x7611a8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611aa: { // 0x7611aa: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ad: { // 0x7611ad: 7405 JZ 0x007611b4
    if(integer::condition("JZ",flags)) goto L007611b4;
  }
  L007611af: { // 0x7611af: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L007611b4: { // 0x7611b4: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L007611b8: { // 0x7611b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611ba: { // 0x7611ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611bd: { // 0x7611bd: 7508 JNZ 0x007611c7
    if(integer::condition("JNZ",flags)) goto L007611c7;
  }
  L007611bf: { // 0x7611bf: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L007611c2: { // 0x7611c2: e9b7feffff JMP 0x0076107e
    goto L0076107e;
  }
  L007611c7: { // 0x7611c7: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L007611c9: { // 0x7611c9: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611cb: { // 0x7611cb: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ce: { // 0x7611ce: 0f84aafeffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L007611d4: { // 0x7611d4: e9a2feffff JMP 0x0076107b
    goto L0076107b;
  }
  L007611d9: { // 0x7611d9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611db: { // 0x7611db: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611dd: { // 0x7611dd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611df: { // 0x7611df: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L007611e3: { // 0x7611e3: e868980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737832u); flags=s.arithmetic_flags;
  }
  L007611e8: { // 0x7611e8: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L007611ec: { // 0x7611ec: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L007611f0: { // 0x7611f0: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L007611f2: { // 0x7611f2: e859980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737847u); flags=s.arithmetic_flags;
  }
  L007611f7: { // 0x7611f7: dd442468 FLD double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.load64(read64(m,address));
  }
  L007611fb: { // 0x7611fb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L007611fe: { // 0x7611fe: e84d980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737859u); flags=s.arithmetic_flags;
  }
  L00761203: { // 0x761203: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761207: { // 0x761207: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L00761209: { // 0x761209: e842980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737870u); flags=s.arithmetic_flags;
  }
  L0076120e: { // 0x76120e: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00761211: { // 0x761211: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00761213: { // 0x761213: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761214: { // 0x761214: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761215: { // 0x761215: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761216: { // 0x761216: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761218: { // 0x761218: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00761219: { // 0x761219: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076121c: { // 0x76121c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076121e: { // 0x76121e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761220: { // 0x761220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761221: { // 0x761221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761222: { // 0x761222: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761224: { // 0x761224: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00761226: { // 0x761226: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761227: { // 0x761227: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761229: { // 0x761229: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076122a: { // 0x76122a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00778aa5(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778aa5: { // 0x778aa5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00778aa6: { // 0x778aa6: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00778aa8: { // 0x778aa8: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00778aab: { // 0x778aab: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00778aae: { // 0x778aae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00778aaf: { // 0x778aaf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00778ab0: { // 0x778ab0: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00778ab2: { // 0x778ab2: 83e71f AND EDI,0x1f
    s.di = integer::logical((s.di)&(0x0000001fu),32,flags);
  }
  L00778ab5: { // 0x778ab5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00778ab7: { // 0x778ab7: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00778ab9: { // 0x778ab9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00778aba: { // 0x778aba: 7414 JZ 0x00778ad0
    if(integer::condition("JZ",flags)) goto L00778ad0;
  }
  L00778abc: { // 0x778abc: 845d10 TEST byte ptr [EBP + 0x10],BL
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&((s.bx & 0xffu)),8,flags);
  }
  L00778abf: { // 0x778abf: 740f JZ 0x00778ad0
    if(integer::condition("JZ",flags)) goto L00778ad0;
  }
  L00778ac1: { // 0x778ac1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00778ac2: { // 0x778ac2: e8f1040000 CALL 0x00778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834311u); flags=s.arithmetic_flags;
  }
  L00778ac7: { // 0x778ac7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778ac8: { // 0x778ac8: 83e7f7 AND EDI,0xfffffff7
    s.di = integer::logical((s.di)&(0xfffffff7u),32,flags);
  }
  L00778acb: { // 0x778acb: e9ca010000 JMP 0x00778c9a
    goto L00778c9a;
  }
  L00778ad0: { // 0x778ad0: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00778ad2: { // 0x778ad2: 7416 JZ 0x00778aea
    if(integer::condition("JZ",flags)) goto L00778aea;
  }
  L00778ad4: { // 0x778ad4: f6451004 TEST byte ptr [EBP + 0x10],0x4
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(0x00000004u),8,flags);
  }
  L00778ad8: { // 0x778ad8: 7410 JZ 0x00778aea
    if(integer::condition("JZ",flags)) goto L00778aea;
  }
  L00778ada: { // 0x778ada: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00778adc: { // 0x778adc: e8d7040000 CALL 0x00778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834337u); flags=s.arithmetic_flags;
  }
  L00778ae1: { // 0x778ae1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778ae2: { // 0x778ae2: 83e7fb AND EDI,0xfffffffb
    s.di = integer::logical((s.di)&(0xfffffffbu),32,flags);
  }
  L00778ae5: { // 0x778ae5: e9b0010000 JMP 0x00778c9a
    goto L00778c9a;
  }
  L00778aea: { // 0x778aea: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00778aec: { // 0x778aec: 0f84d2000000 JZ 0x00778bc4
    if(integer::condition("JZ",flags)) goto L00778bc4;
  }
  L00778af2: { // 0x778af2: f6451008 TEST byte ptr [EBP + 0x10],0x8
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(0x00000008u),8,flags);
  }
  L00778af6: { // 0x778af6: 0f84c8000000 JZ 0x00778bc4
    if(integer::condition("JZ",flags)) goto L00778bc4;
  }
  L00778afc: { // 0x778afc: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00778afe: { // 0x778afe: e8b5040000 CALL 0x00778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834371u); flags=s.arithmetic_flags;
  }
  L00778b03: { // 0x778b03: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778b04: { // 0x778b04: b8000c0000 MOV EAX,0xc00
    s.ax = 0x00000c00u;
  }
  L00778b09: { // 0x778b09: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L00778b0c: { // 0x778b0c: 23c8 AND ECX,EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L00778b0e: { // 0x778b0e: 0f8488000000 JZ 0x00778b9c
    if(integer::condition("JZ",flags)) goto L00778b9c;
  }
  L00778b14: { // 0x778b14: 81f900040000 CMP ECX,0x400
    (void)integer::sub(s.cx,0x00000400u,32,flags);
  }
  L00778b1a: { // 0x778b1a: 7458 JZ 0x00778b74
    if(integer::condition("JZ",flags)) goto L00778b74;
  }
  L00778b1c: { // 0x778b1c: 81f900080000 CMP ECX,0x800
    (void)integer::sub(s.cx,0x00000800u,32,flags);
  }
  L00778b22: { // 0x778b22: 7428 JZ 0x00778b4c
    if(integer::condition("JZ",flags)) goto L00778b4c;
  }
  L00778b24: { // 0x778b24: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00778b26: { // 0x778b26: 0f8590000000 JNZ 0x00778bbc
    if(integer::condition("JNZ",flags)) goto L00778bbc;
  }
  L00778b2c: { // 0x778b2c: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b2f: { // 0x778b2f: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778b31: { // 0x778b31: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778b37: { // 0x778b37: dd05107b8100 FLD double ptr [0x00817b10]
    const auto address=(0x00817b10u);
    s.fp.load64(read64(m,address));
  }
  L00778b3d: { // 0x778b3d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778b3f: { // 0x778b3f: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778b40: { // 0x778b40: 7702 JA 0x00778b44
    if(integer::condition("JA",flags)) goto L00778b44;
  }
  L00778b42: { // 0x778b42: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778b44: { // 0x778b44: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778b47: { // 0x778b47: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778b4a: { // 0x778b4a: eb6e JMP 0x00778bba
    goto L00778bba;
  }
  L00778b4c: { // 0x778b4c: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b4f: { // 0x778b4f: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778b51: { // 0x778b51: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778b57: { // 0x778b57: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778b59: { // 0x778b59: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778b5a: { // 0x778b5a: 7608 JBE 0x00778b64
    if(integer::condition("JBE",flags)) goto L00778b64;
  }
  L00778b5c: { // 0x778b5c: dd05007b8100 FLD double ptr [0x00817b00]
    const auto address=(0x00817b00u);
    s.fp.load64(read64(m,address));
  }
  L00778b62: { // 0x778b62: eb08 JMP 0x00778b6c
    goto L00778b6c;
  }
  L00778b64: { // 0x778b64: dd05107b8100 FLD double ptr [0x00817b10]
    const auto address=(0x00817b10u);
    s.fp.load64(read64(m,address));
  }
  L00778b6a: { // 0x778b6a: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778b6c: { // 0x778b6c: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778b6f: { // 0x778b6f: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778b72: { // 0x778b72: eb46 JMP 0x00778bba
    goto L00778bba;
  }
  L00778b74: { // 0x778b74: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b77: { // 0x778b77: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778b79: { // 0x778b79: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778b7f: { // 0x778b7f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778b81: { // 0x778b81: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778b82: { // 0x778b82: 7608 JBE 0x00778b8c
    if(integer::condition("JBE",flags)) goto L00778b8c;
  }
  L00778b84: { // 0x778b84: dd05107b8100 FLD double ptr [0x00817b10]
    const auto address=(0x00817b10u);
    s.fp.load64(read64(m,address));
  }
  L00778b8a: { // 0x778b8a: eb08 JMP 0x00778b94
    goto L00778b94;
  }
  L00778b8c: { // 0x778b8c: dd05007b8100 FLD double ptr [0x00817b00]
    const auto address=(0x00817b00u);
    s.fp.load64(read64(m,address));
  }
  L00778b92: { // 0x778b92: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778b94: { // 0x778b94: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778b97: { // 0x778b97: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778b9a: { // 0x778b9a: eb1e JMP 0x00778bba
    goto L00778bba;
  }
  L00778b9c: { // 0x778b9c: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b9f: { // 0x778b9f: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778ba1: { // 0x778ba1: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778ba7: { // 0x778ba7: dd05007b8100 FLD double ptr [0x00817b00]
    const auto address=(0x00817b00u);
    s.fp.load64(read64(m,address));
  }
  L00778bad: { // 0x778bad: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778baf: { // 0x778baf: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778bb0: { // 0x778bb0: 7702 JA 0x00778bb4
    if(integer::condition("JA",flags)) goto L00778bb4;
  }
  L00778bb2: { // 0x778bb2: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778bb4: { // 0x778bb4: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778bb7: { // 0x778bb7: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778bba: { // 0x778bba: dd19 FSTP double ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778bbc: { // 0x778bbc: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L00778bbf: { // 0x778bbf: e9d6000000 JMP 0x00778c9a
    goto L00778c9a;
  }
  L00778bc4: { // 0x778bc4: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L00778bc6: { // 0x778bc6: 0f84ce000000 JZ 0x00778c9a
    if(integer::condition("JZ",flags)) goto L00778c9a;
  }
  L00778bcc: { // 0x778bcc: f6451010 TEST byte ptr [EBP + 0x10],0x10
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(0x00000010u),8,flags);
  }
  L00778bd0: { // 0x778bd0: 0f84c4000000 JZ 0x00778c9a
    if(integer::condition("JZ",flags)) goto L00778c9a;
  }
  L00778bd6: { // 0x778bd6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00778bd7: { // 0x778bd7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00778bd9: { // 0x778bd9: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00778bdb: { // 0x778bdb: 7402 JZ 0x00778bdf
    if(integer::condition("JZ",flags)) goto L00778bdf;
  }
  L00778bdd: { // 0x778bdd: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00778bdf: { // 0x778bdf: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00778be2: { // 0x778be2: dd00 FLD double ptr [EAX]
    const auto address=(s.ax);
    s.fp.load64(read64(m,address));
  }
  L00778be4: { // 0x778be4: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778be7: { // 0x778be7: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778bea: { // 0x778bea: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778bf0: { // 0x778bf0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778bf2: { // 0x778bf2: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778bf3: { // 0x778bf3: 0f848f000000 JZ 0x00778c88
    if(integer::condition("JZ",flags)) goto L00778c88;
  }
  L00778bf9: { // 0x778bf9: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778bfc: { // 0x778bfc: 8d45fc LEA EAX,[EBP + -0x4]
    s.ax = (s.bp-0x00000004u);
  }
  L00778bff: { // 0x778bff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00778c00: { // 0x778c00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778c01: { // 0x778c01: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778c02: { // 0x778c02: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c05: { // 0x778c05: e8ad020000 CALL 0x00778eb7
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778eb7u,7834634u); flags=s.arithmetic_flags;
  }
  L00778c0a: { // 0x778c0a: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  L00778c0d: { // 0x778c0d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00778c10: { // 0x778c10: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c13: { // 0x778c13: 8d8800faffff LEA ECX,[EAX + 0xfffffa00]
    s.cx = (s.ax+0xfffffa00u);
  }
  L00778c19: { // 0x778c19: 81f9cefbffff CMP ECX,0xfffffbce
    (void)integer::sub(s.cx,0xfffffbceu,32,flags);
  }
  L00778c1f: { // 0x778c1f: 7d09 JGE 0x00778c2a
    if(integer::condition("JGE",flags)) goto L00778c2a;
  }
  L00778c21: { // 0x778c21: d9ee FLDZ
    numeric_b88::detail::reg<0xd9ee>(s.fp);
  }
  L00778c23: { // 0x778c23: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00778c25: { // 0x778c25: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c28: { // 0x778c28: eb54 JMP 0x00778c7e
    goto L00778c7e;
  }
  L00778c2a: { // 0x778c2a: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778c2d: { // 0x778c2d: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778c33: { // 0x778c33: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778c35: { // 0x778c35: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778c36: { // 0x778c36: 7304 JNC 0x00778c3c
    if(integer::condition("JNC",flags)) goto L00778c3c;
  }
  L00778c38: { // 0x778c38: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00778c3a: { // 0x778c3a: eb02 JMP 0x00778c3e
    goto L00778c3e;
  }
  L00778c3c: { // 0x778c3c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00778c3e: { // 0x778c3e: 8a45fa MOV AL,byte ptr [EBP + -0x6]
    s.ax = with_al(s.ax, m.r8((s.bp-0x00000006u)));
  }
  L00778c41: { // 0x778c41: 83e00f AND EAX,0xf
    s.ax = integer::logical((s.ax)&(0x0000000fu),32,flags);
  }
  L00778c44: { // 0x778c44: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00778c46: { // 0x778c46: 668945fa MOV word ptr [EBP + -0x6],AX
    m.w16((s.bp-0x00000006u), (s.ax & 0xffffu));
  }
  L00778c4a: { // 0x778c4a: b803fcffff MOV EAX,0xfffffc03
    s.ax = 0xfffffc03u;
  }
  L00778c4f: { // 0x778c4f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00778c51: { // 0x778c51: 7d1f JGE 0x00778c72
    if(integer::condition("JGE",flags)) goto L00778c72;
  }
  L00778c53: { // 0x778c53: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00778c55: { // 0x778c55: 845df4 TEST byte ptr [EBP + -0xc],BL
    (void)integer::logical((m.r8((s.bp-0x0000000cu)))&((s.bx & 0xffu)),8,flags);
  }
  L00778c58: { // 0x778c58: 7406 JZ 0x00778c60
    if(integer::condition("JZ",flags)) goto L00778c60;
  }
  L00778c5a: { // 0x778c5a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00778c5c: { // 0x778c5c: 7502 JNZ 0x00778c60
    if(integer::condition("JNZ",flags)) goto L00778c60;
  }
  L00778c5e: { // 0x778c5e: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00778c60: { // 0x778c60: d16df4 SHR dword ptr [EBP + -0xc],0x1
    m.w32((s.bp-0x0000000cu), integer::shift(m.r32((s.bp-0x0000000cu)),0x00000001u,32,flags,integer::Shift::right));
  }
  L00778c63: { // 0x778c63: 845df8 TEST byte ptr [EBP + -0x8],BL
    (void)integer::logical((m.r8((s.bp-0x00000008u)))&((s.bx & 0xffu)),8,flags);
  }
  L00778c66: { // 0x778c66: 7404 JZ 0x00778c6c
    if(integer::condition("JZ",flags)) goto L00778c6c;
  }
  L00778c68: { // 0x778c68: 804df780 OR byte ptr [EBP + -0x9],0x80
    m.w8((s.bp-0x00000009u), integer::logical((m.r8((s.bp-0x00000009u)))|(0x00000080u),8,flags));
  }
  L00778c6c: { // 0x778c6c: d16df8 SHR dword ptr [EBP + -0x8],0x1
    m.w32((s.bp-0x00000008u), integer::shift(m.r32((s.bp-0x00000008u)),0x00000001u,32,flags,integer::Shift::right));
  }
  L00778c6f: { // 0x778c6f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00778c70: { // 0x778c70: 75e3 JNZ 0x00778c55
    if(integer::condition("JNZ",flags)) goto L00778c55;
  }
  L00778c72: { // 0x778c72: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00778c74: { // 0x778c74: 7408 JZ 0x00778c7e
    if(integer::condition("JZ",flags)) goto L00778c7e;
  }
  L00778c76: { // 0x778c76: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778c79: { // 0x778c79: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778c7b: { // 0x778c7b: dd5df4 FSTP double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c7e: { // 0x778c7e: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778c81: { // 0x778c81: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00778c84: { // 0x778c84: dd18 FSTP double ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c86: { // 0x778c86: eb02 JMP 0x00778c8a
    goto L00778c8a;
  }
  L00778c88: { // 0x778c88: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00778c8a: { // 0x778c8a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00778c8c: { // 0x778c8c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00778c8d: { // 0x778c8d: 7408 JZ 0x00778c97
    if(integer::condition("JZ",flags)) goto L00778c97;
  }
  L00778c8f: { // 0x778c8f: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  L00778c91: { // 0x778c91: e822030000 CALL 0x00778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834774u); flags=s.arithmetic_flags;
  }
  L00778c96: { // 0x778c96: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778c97: { // 0x778c97: 83e7fd AND EDI,0xfffffffd
    s.di = integer::logical((s.di)&(0xfffffffdu),32,flags);
  }
  L00778c9a: { // 0x778c9a: f6450810 TEST byte ptr [EBP + 0x8],0x10
    (void)integer::logical((m.r8((s.bp+0x00000008u)))&(0x00000010u),8,flags);
  }
  L00778c9e: { // 0x778c9e: 7411 JZ 0x00778cb1
    if(integer::condition("JZ",flags)) goto L00778cb1;
  }
  L00778ca0: { // 0x778ca0: f6451020 TEST byte ptr [EBP + 0x10],0x20
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(0x00000020u),8,flags);
  }
  L00778ca4: { // 0x778ca4: 740b JZ 0x00778cb1
    if(integer::condition("JZ",flags)) goto L00778cb1;
  }
  L00778ca6: { // 0x778ca6: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  L00778ca8: { // 0x778ca8: e80b030000 CALL 0x00778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834797u); flags=s.arithmetic_flags;
  }
  L00778cad: { // 0x778cad: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778cae: { // 0x778cae: 83e7ef AND EDI,0xffffffef
    s.di = integer::logical((s.di)&(0xffffffefu),32,flags);
  }
  L00778cb1: { // 0x778cb1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00778cb3: { // 0x778cb3: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00778cb5: { // 0x778cb5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00778cb6: { // 0x778cb6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00778cb7: { // 0x778cb7: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00778cba: { // 0x778cba: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00778cbb: { // 0x778cbb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
