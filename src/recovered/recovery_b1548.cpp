#include "recovered/recovery_b1548_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1548 {
namespace {
void f_002350e0(Memory&,State&,Frame&,const Operations&);
void f_000ba140(Memory&,State&,Frame&,const Operations&);
void f_000b8850(Memory&,State&,Frame&,const Operations&);
void f_000ba0f0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_001cd870(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_002350e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006350e0: { // 0x6350e0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006350e1: { // 0x6350e1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L006350e3: { // 0x6350e3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L006350e6: { // 0x6350e6: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L006350e9: { // 0x6350e9: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L006350ec: { // 0x6350ec: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006350ed: { // 0x6350ed: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006350ee: { // 0x6350ee: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006350f0: { // 0x6350f0: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L006350f3: { // 0x6350f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006350f4: { // 0x6350f4: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L006350f7: { // 0x6350f7: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L006350fb: { // 0x6350fb: d94650 FLD float ptr [ESI + 0x50]
    const auto address=(s.si+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L006350fe: { // 0x6350fe: 81c288000000 ADD EDX,0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L00635104: { // 0x635104: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00635107: { // 0x635107: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00635109: { // 0x635109: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0063510c: { // 0x63510c: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0063510f: { // 0x63510f: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00635113: { // 0x635113: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00635117: { // 0x635117: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0063511a: { // 0x63511a: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0063511e: { // 0x63511e: e81d50e8ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,6508835u); flags=s.arithmetic_flags;
  }
  L00635123: { // 0x635123: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00635126: { // 0x635126: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00635129: { // 0x635129: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0063512d: { // 0x63512d: 81c1e0020000 ADD ECX,0x2e0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  L00635133: { // 0x635133: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00635134: { // 0x635134: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00635136: { // 0x635136: e81537e8ff CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,6508859u); flags=s.arithmetic_flags;
  }
  L0063513b: { // 0x63513b: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0063513e: { // 0x63513e: 81e9ff3f0000 SUB ECX,0x3fff
    s.cx = integer::sub(s.cx,0x00003fffu,32,flags);
  }
  L00635144: { // 0x635144: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00635148: { // 0x635148: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0063514c: { // 0x63514c: dc0d20667800 FMUL double ptr [0x00786620]
    const auto address=(0x00786620u);
    s.fp.multiply64(read64(m,address));
  }
  L00635152: { // 0x635152: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00635156: { // 0x635156: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0063515a: { // 0x63515a: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0063515e: { // 0x63515e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0063515f: { // 0x63515f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00635160: { // 0x635160: e88b4fe8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6508901u); flags=s.arithmetic_flags;
  }
  L00635165: { // 0x635165: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00635166: { // 0x635166: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00635167: { // 0x635167: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00635169: { // 0x635169: e8d24fe8ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,6508910u); flags=s.arithmetic_flags;
  }
  L0063516e: { // 0x63516e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00635170: { // 0x635170: d94650 FLD float ptr [ESI + 0x50]
    const auto address=(s.si+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L00635173: { // 0x635173: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00635176: { // 0x635176: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00635179: { // 0x635179: e8724fe8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6508926u); flags=s.arithmetic_flags;
  }
  L0063517e: { // 0x63517e: da4c2424 FIMUL dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    ra2::platform::map_adjust1044_fp::multiply_integer32(s.fp,m.r32(address));
  }
  L00635182: { // 0x635182: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00635185: { // 0x635185: da44242c FIADD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    ra2::platform::x87_extended::add_integer32(s.fp,m.r32(address));
  }
  L00635189: { // 0x635189: e8c2581300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6508942u); flags=s.arithmetic_flags;
  }
  L0063518e: { // 0x63518e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00635190: { // 0x635190: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  L00635193: { // 0x635193: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00635195: { // 0x635195: 7f12 JG 0x006351a9
    if(integer::condition("JG",flags)) goto L006351a9;
  }
  L00635197: { // 0x635197: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00635199: { // 0x635199: e8220a0000 CALL 0x00635bc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00635bc0u,6508958u); flags=s.arithmetic_flags;
  }
  L0063519e: { // 0x63519e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006351a0: { // 0x6351a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006351a1: { // 0x6351a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006351a2: { // 0x6351a2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006351a3: { // 0x6351a3: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006351a5: { // 0x6351a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006351a6: { // 0x6351a6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006351a9: { // 0x6351a9: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L006351ac: { // 0x6351ac: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006351ae: { // 0x6351ae: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),6508980u); flags=s.arithmetic_flags;
  }
  L006351b4: { // 0x6351b4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006351b6: { // 0x6351b6: 743d JZ 0x006351f5
    if(integer::condition("JZ",flags)) goto L006351f5;
  }
  L006351b8: { // 0x6351b8: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006351be: { // 0x6351be: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006351c1: { // 0x6351c1: 7432 JZ 0x006351f5
    if(integer::condition("JZ",flags)) goto L006351f5;
  }
  L006351c3: { // 0x6351c3: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006351c5: { // 0x6351c5: 8b5e20 MOV EBX,dword ptr [ESI + 0x20]
    s.bx = m.r32((s.si+0x00000020u));
  }
  L006351c8: { // 0x6351c8: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006351cc: { // 0x6351cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006351cd: { // 0x6351cd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006351cf: { // 0x6351cf: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6509010u); flags=s.arithmetic_flags;
  }
  L006351d2: { // 0x6351d2: 395808 CMP dword ptr [EAX + 0x8],EBX
    (void)integer::sub(m.r32((s.ax+0x00000008u)),s.bx,32,flags);
  }
  L006351d5: { // 0x6351d5: 751e JNZ 0x006351f5
    if(integer::condition("JNZ",flags)) goto L006351f5;
  }
  L006351d7: { // 0x6351d7: 8b15d0e3a900 MOV EDX,dword ptr [0x00a9e3d0]
    s.dx = m.r32((0x00a9e3d0u));
  }
  L006351dd: { // 0x6351dd: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L006351df: { // 0x6351df: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L006351e1: { // 0x6351e1: 7f12 JG 0x006351f5
    if(integer::condition("JG",flags)) goto L006351f5;
  }
  L006351e3: { // 0x6351e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006351e5: { // 0x6351e5: e8d6090000 CALL 0x00635bc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00635bc0u,6509034u); flags=s.arithmetic_flags;
  }
  L006351ea: { // 0x6351ea: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006351ec: { // 0x6351ec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006351ed: { // 0x6351ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006351ee: { // 0x6351ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006351ef: { // 0x6351ef: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006351f1: { // 0x6351f1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006351f2: { // 0x6351f2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006351f5: { // 0x6351f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006351f6: { // 0x6351f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006351f7: { // 0x6351f7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006351f9: { // 0x6351f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006351fa: { // 0x6351fa: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006351fc: { // 0x6351fc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006351fd: { // 0x6351fd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
void f_001cd870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd870: { // 0x5cd870: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005cd873: { // 0x5cd873: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cd874: { // 0x5cd874: 8db188000000 LEA ESI, [ECX + 0x88]
    s.si = (s.cx+0x00000088u);
  }
  L005cd87a: { // 0x5cd87a: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L005cd87c: { // 0x5cd87c: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cd87e: { // 0x5cd87e: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L005cd882: { // 0x5cd882: 8d4c2404 LEA ECX, [ESP + 4]
    s.cx = (f.sp+4u);
  }
  L005cd886: { // 0x5cd886: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L005cd889: { // 0x5cd889: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cd88a: { // 0x5cd88a: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005cd88f: { // 0x5cd88f: 8954240c MOV dword ptr [ESP + 0xc], EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L005cd893: { // 0x5cd893: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L005cd896: { // 0x5cd896: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005cd89a: { // 0x5cd89a: e8f17bf7ff CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6084767u); flags=s.arithmetic_flags;
  }
  L005cd89f: { // 0x5cd89f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cd8a1: { // 0x5cd8a1: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L005cd8a4: { // 0x5cd8a4: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L005cd8a7: { // 0x5cd8a7: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L005cd8ab: { // 0x5cd8ab: 8d542404 LEA EDX, [ESP + 4]
    s.dx = (f.sp+4u);
  }
  L005cd8af: { // 0x5cd8af: 894c240c MOV dword ptr [ESP + 0xc], ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L005cd8b3: { // 0x5cd8b3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cd8b4: { // 0x5cd8b4: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005cd8b9: { // 0x5cd8b9: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L005cd8bd: { // 0x5cd8bd: e8ce7bf7ff CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6084802u); flags=s.arithmetic_flags;
  }
  L005cd8c2: { // 0x5cd8c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cd8c3: { // 0x5cd8c3: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005cd8c6: { // 0x5cd8c6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
case 6508768u:f_002350e0(m,s,child,{});break;
case 4956480u:f_000ba140(m,s,child,{});break;
case 4950096u:f_000b8850(m,s,child,{});break;
case 4956400u:f_000ba0f0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6084720u:f_001cd870(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
default:throw std::domain_error("recovery1548 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1548 no reviewed tail"); } }

std::uint32_t fun_006350e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006350e0: { // 0x6350e0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006350e1: { // 0x6350e1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L006350e3: { // 0x6350e3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L006350e6: { // 0x6350e6: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L006350e9: { // 0x6350e9: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L006350ec: { // 0x6350ec: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006350ed: { // 0x6350ed: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006350ee: { // 0x6350ee: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006350f0: { // 0x6350f0: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L006350f3: { // 0x6350f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006350f4: { // 0x6350f4: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L006350f7: { // 0x6350f7: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L006350fb: { // 0x6350fb: d94650 FLD float ptr [ESI + 0x50]
    const auto address=(s.si+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L006350fe: { // 0x6350fe: 81c288000000 ADD EDX,0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L00635104: { // 0x635104: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00635107: { // 0x635107: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00635109: { // 0x635109: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0063510c: { // 0x63510c: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0063510f: { // 0x63510f: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00635113: { // 0x635113: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00635117: { // 0x635117: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0063511a: { // 0x63511a: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0063511e: { // 0x63511e: e81d50e8ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,6508835u); flags=s.arithmetic_flags;
  }
  L00635123: { // 0x635123: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00635126: { // 0x635126: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00635129: { // 0x635129: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0063512d: { // 0x63512d: 81c1e0020000 ADD ECX,0x2e0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  L00635133: { // 0x635133: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00635134: { // 0x635134: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00635136: { // 0x635136: e81537e8ff CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,6508859u); flags=s.arithmetic_flags;
  }
  L0063513b: { // 0x63513b: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0063513e: { // 0x63513e: 81e9ff3f0000 SUB ECX,0x3fff
    s.cx = integer::sub(s.cx,0x00003fffu,32,flags);
  }
  L00635144: { // 0x635144: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00635148: { // 0x635148: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0063514c: { // 0x63514c: dc0d20667800 FMUL double ptr [0x00786620]
    const auto address=(0x00786620u);
    s.fp.multiply64(read64(m,address));
  }
  L00635152: { // 0x635152: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00635156: { // 0x635156: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0063515a: { // 0x63515a: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0063515e: { // 0x63515e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0063515f: { // 0x63515f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00635160: { // 0x635160: e88b4fe8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6508901u); flags=s.arithmetic_flags;
  }
  L00635165: { // 0x635165: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00635166: { // 0x635166: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00635167: { // 0x635167: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00635169: { // 0x635169: e8d24fe8ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,6508910u); flags=s.arithmetic_flags;
  }
  L0063516e: { // 0x63516e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00635170: { // 0x635170: d94650 FLD float ptr [ESI + 0x50]
    const auto address=(s.si+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L00635173: { // 0x635173: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00635176: { // 0x635176: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00635179: { // 0x635179: e8724fe8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6508926u); flags=s.arithmetic_flags;
  }
  L0063517e: { // 0x63517e: da4c2424 FIMUL dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    ra2::platform::map_adjust1044_fp::multiply_integer32(s.fp,m.r32(address));
  }
  L00635182: { // 0x635182: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00635185: { // 0x635185: da44242c FIADD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    ra2::platform::x87_extended::add_integer32(s.fp,m.r32(address));
  }
  L00635189: { // 0x635189: e8c2581300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6508942u); flags=s.arithmetic_flags;
  }
  L0063518e: { // 0x63518e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00635190: { // 0x635190: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  L00635193: { // 0x635193: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00635195: { // 0x635195: 7f12 JG 0x006351a9
    if(integer::condition("JG",flags)) goto L006351a9;
  }
  L00635197: { // 0x635197: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00635199: { // 0x635199: e8220a0000 CALL 0x00635bc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00635bc0u,6508958u); flags=s.arithmetic_flags;
  }
  L0063519e: { // 0x63519e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006351a0: { // 0x6351a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006351a1: { // 0x6351a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006351a2: { // 0x6351a2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006351a3: { // 0x6351a3: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006351a5: { // 0x6351a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006351a6: { // 0x6351a6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006351a9: { // 0x6351a9: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L006351ac: { // 0x6351ac: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006351ae: { // 0x6351ae: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),6508980u); flags=s.arithmetic_flags;
  }
  L006351b4: { // 0x6351b4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006351b6: { // 0x6351b6: 743d JZ 0x006351f5
    if(integer::condition("JZ",flags)) goto L006351f5;
  }
  L006351b8: { // 0x6351b8: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006351be: { // 0x6351be: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006351c1: { // 0x6351c1: 7432 JZ 0x006351f5
    if(integer::condition("JZ",flags)) goto L006351f5;
  }
  L006351c3: { // 0x6351c3: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006351c5: { // 0x6351c5: 8b5e20 MOV EBX,dword ptr [ESI + 0x20]
    s.bx = m.r32((s.si+0x00000020u));
  }
  L006351c8: { // 0x6351c8: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006351cc: { // 0x6351cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006351cd: { // 0x6351cd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006351cf: { // 0x6351cf: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6509010u); flags=s.arithmetic_flags;
  }
  L006351d2: { // 0x6351d2: 395808 CMP dword ptr [EAX + 0x8],EBX
    (void)integer::sub(m.r32((s.ax+0x00000008u)),s.bx,32,flags);
  }
  L006351d5: { // 0x6351d5: 751e JNZ 0x006351f5
    if(integer::condition("JNZ",flags)) goto L006351f5;
  }
  L006351d7: { // 0x6351d7: 8b15d0e3a900 MOV EDX,dword ptr [0x00a9e3d0]
    s.dx = m.r32((0x00a9e3d0u));
  }
  L006351dd: { // 0x6351dd: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L006351df: { // 0x6351df: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L006351e1: { // 0x6351e1: 7f12 JG 0x006351f5
    if(integer::condition("JG",flags)) goto L006351f5;
  }
  L006351e3: { // 0x6351e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006351e5: { // 0x6351e5: e8d6090000 CALL 0x00635bc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00635bc0u,6509034u); flags=s.arithmetic_flags;
  }
  L006351ea: { // 0x6351ea: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006351ec: { // 0x6351ec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006351ed: { // 0x6351ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006351ee: { // 0x6351ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006351ef: { // 0x6351ef: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006351f1: { // 0x6351f1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006351f2: { // 0x6351f2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006351f5: { // 0x6351f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006351f6: { // 0x6351f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006351f7: { // 0x6351f7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006351f9: { // 0x6351f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006351fa: { // 0x6351fa: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006351fc: { // 0x6351fc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006351fd: { // 0x6351fd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
