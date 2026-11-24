#include "recovered/recovery_b776_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b776 {
namespace {
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD qword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x4ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x4ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL qword ptr [0x788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX, 0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX, 0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX, 0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x4ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX, 0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX, 1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),1u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX, 0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX, 0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX, dword ptr [ECX*4 + 0x80013c]
    s.cx = m.r32(((s.cx * 4u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX, 0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX, dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX, 0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX, dword ptr [0x7c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x76aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX, dword ptr [0x7c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP], EDX
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
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4956288u:f_000ba080(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery776 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0049c2b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049c2b0: { // 0x49c2b0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0049c2b3: { // 0x49c2b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049c2b4: { // 0x49c2b4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049c2b6: { // 0x49c2b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049c2b7: { // 0x49c2b7: 8a86cb110000 MOV AL,byte ptr [ESI + 0x11cb]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011cbu)));
  }
  L0049c2bd: { // 0x49c2bd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c2bf: { // 0x49c2bf: 0f84a1000000 JZ 0x0049c366
    if(integer::condition("JZ",flags)) goto L0049c366;
  }
  L0049c2c5: { // 0x49c2c5: 8a86af110000 MOV AL,byte ptr [ESI + 0x11af]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011afu)));
  }
  L0049c2cb: { // 0x49c2cb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c2cd: { // 0x49c2cd: 0f8593000000 JNZ 0x0049c366
    if(integer::condition("JNZ",flags)) goto L0049c366;
  }
  L0049c2d3: { // 0x49c2d3: 8a86b0110000 MOV AL,byte ptr [ESI + 0x11b0]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011b0u)));
  }
  L0049c2d9: { // 0x49c2d9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c2db: { // 0x49c2db: 0f8585000000 JNZ 0x0049c366
    if(integer::condition("JNZ",flags)) goto L0049c366;
  }
  L0049c2e1: { // 0x49c2e1: 8b0d74198200 MOV ECX,dword ptr [0x00821974]
    s.cx = m.r32((0x00821974u));
  }
  L0049c2e7: { // 0x49c2e7: a170198200 MOV EAX,[0x00821970]
    s.ax = m.r32((0x00821970u));
  }
  L0049c2ec: { // 0x49c2ec: 8b1578198200 MOV EDX,dword ptr [0x00821978]
    s.dx = m.r32((0x00821978u));
  }
  L0049c2f2: { // 0x49c2f2: 8b3d7c198200 MOV EDI,dword ptr [0x0082197c]
    s.di = m.r32((0x0082197cu));
  }
  L0049c2f8: { // 0x49c2f8: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0049c2fc: { // 0x49c2fc: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0049c300: { // 0x49c300: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L0049c304: { // 0x49c304: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049c306: { // 0x49c306: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0049c309: { // 0x49c309: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c30b: { // 0x49c30b: 7d02 JGE 0x0049c30f
    if(integer::condition("JGE",flags)) goto L0049c30f;
  }
  L0049c30d: { // 0x49c30d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0049c30f: { // 0x49c30f: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049c311: { // 0x49c311: 7c03 JL 0x0049c316
    if(integer::condition("JL",flags)) goto L0049c316;
  }
  L0049c313: { // 0x49c313: 8d42ff LEA EAX,[EDX + -0x1]
    s.ax = (s.dx-0x00000001u);
  }
  L0049c316: { // 0x49c316: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049c318: { // 0x49c318: 7d02 JGE 0x0049c31c
    if(integer::condition("JGE",flags)) goto L0049c31c;
  }
  L0049c31a: { // 0x49c31a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049c31c: { // 0x49c31c: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0049c31e: { // 0x49c31e: 7c03 JL 0x0049c323
    if(integer::condition("JL",flags)) goto L0049c323;
  }
  L0049c320: { // 0x49c320: 8d4fff LEA ECX,[EDI + -0x1]
    s.cx = (s.di-0x00000001u);
  }
  L0049c323: { // 0x49c323: 8b96d8110000 MOV EDX,dword ptr [ESI + 0x11d8]
    s.dx = m.r32((s.si+0x000011d8u));
  }
  L0049c329: { // 0x49c329: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L0049c32d: { // 0x49c32d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049c32f: { // 0x49c32f: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0049c333: { // 0x49c333: 750c JNZ 0x0049c341
    if(integer::condition("JNZ",flags)) goto L0049c341;
  }
  L0049c335: { // 0x49c335: 3b8edc110000 CMP ECX,dword ptr [ESI + 0x11dc]
    (void)integer::sub(s.cx,m.r32((s.si+0x000011dcu)),32,flags);
  }
  L0049c33b: { // 0x49c33b: 0f84ce000000 JZ 0x0049c40f
    if(integer::condition("JZ",flags)) goto L0049c40f;
  }
  L0049c341: { // 0x49c341: 8b15ac1c8200 MOV EDX,dword ptr [0x00821cac]
    s.dx = m.r32((0x00821cacu));
  }
  L0049c347: { // 0x49c347: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0049c34b: { // 0x49c34b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049c34c: { // 0x49c34c: c6827d0d000001 MOV byte ptr [EDX + 0xd7d],0x1
    m.w8((s.dx+0x00000d7du), 0x00000001u);
  }
  L0049c353: { // 0x49c353: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049c359: { // 0x49c359: e8c2382000 CALL 0x0069fc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069fc20u,4834142u); flags=s.arithmetic_flags;
  }
  L0049c35e: { // 0x49c35e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049c35f: { // 0x49c35f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c360: { // 0x49c360: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0049c363: { // 0x49c363: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049c366: { // 0x49c366: 8a86cc110000 MOV AL,byte ptr [ESI + 0x11cc]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011ccu)));
  }
  L0049c36c: { // 0x49c36c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c36e: { // 0x49c36e: 0f849b000000 JZ 0x0049c40f
    if(integer::condition("JZ",flags)) goto L0049c40f;
  }
  L0049c374: { // 0x49c374: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0049c378: { // 0x49c378: 8b96d0110000 MOV EDX,dword ptr [ESI + 0x11d0]
    s.dx = m.r32((s.si+0x000011d0u));
  }
  L0049c37e: { // 0x49c37e: 8dbed0110000 LEA EDI,[ESI + 0x11d0]
    s.di = (s.si+0x000011d0u);
  }
  L0049c384: { // 0x49c384: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0049c387: { // 0x49c387: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049c389: { // 0x49c389: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0049c38b: { // 0x49c38b: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0049c38e: { // 0x49c38e: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0049c392: { // 0x49c392: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0049c395: { // 0x49c395: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L0049c397: { // 0x49c397: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0049c39b: { // 0x49c39b: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L0049c39f: { // 0x49c39f: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0049c3a3: { // 0x49c3a3: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0049c3a5: { // 0x49c3a5: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0049c3a7: { // 0x49c3a7: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0049c3a9: { // 0x49c3a9: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0049c3ab: { // 0x49c3ab: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0049c3ad: { // 0x49c3ad: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0049c3b0: { // 0x49c3b0: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0049c3b2: { // 0x49c3b2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0049c3b4: { // 0x49c3b4: e8c7dc0100 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4834233u); flags=s.arithmetic_flags;
  }
  L0049c3b9: { // 0x49c3b9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0049c3bc: { // 0x49c3bc: e88fe62c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4834241u); flags=s.arithmetic_flags;
  }
  L0049c3c1: { // 0x49c3c1: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L0049c3c4: { // 0x49c3c4: 7e49 JLE 0x0049c40f
    if(integer::condition("JLE",flags)) goto L0049c40f;
  }
  L0049c3c6: { // 0x49c3c6: 8a8eaf110000 MOV CL,byte ptr [ESI + 0x11af]
    s.cx = with_al(s.cx, m.r8((s.si+0x000011afu)));
  }
  L0049c3cc: { // 0x49c3cc: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0049c3ce: { // 0x49c3ce: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049c3d0: { // 0x49c3d0: 8886cb110000 MOV byte ptr [ESI + 0x11cb],AL
    m.w8((s.si+0x000011cbu), (s.ax & 0xffu));
  }
  L0049c3d6: { // 0x49c3d6: c686cc11000000 MOV byte ptr [ESI + 0x11cc],0x0
    m.w8((s.si+0x000011ccu), 0x00000000u);
  }
  L0049c3dd: { // 0x49c3dd: 7530 JNZ 0x0049c40f
    if(integer::condition("JNZ",flags)) goto L0049c40f;
  }
  L0049c3df: { // 0x49c3df: 8a8eb0110000 MOV CL,byte ptr [ESI + 0x11b0]
    s.cx = with_al(s.cx, m.r8((s.si+0x000011b0u)));
  }
  L0049c3e5: { // 0x49c3e5: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049c3e7: { // 0x49c3e7: 7526 JNZ 0x0049c40f
    if(integer::condition("JNZ",flags)) goto L0049c40f;
  }
  L0049c3e9: { // 0x49c3e9: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049c3ef: { // 0x49c3ef: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049c3f0: { // 0x49c3f0: 88817d0d0000 MOV byte ptr [ECX + 0xd7d],AL
    m.w8((s.cx+0x00000d7du), (s.ax & 0xffu));
  }
  L0049c3f6: { // 0x49c3f6: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049c3fc: { // 0x49c3fc: e8df372000 CALL 0x0069fbe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069fbe0u,4834305u); flags=s.arithmetic_flags;
  }
  L0049c401: { // 0x49c401: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c403: { // 0x49c403: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c405: { // 0x49c405: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049c40a: { // 0x49c40a: e831fc0f00 CALL 0x0059c040
    s.arithmetic_flags=flags; invoke(m,s,f,0x0059c040u,4834319u); flags=s.arithmetic_flags;
  }
  L0049c40f: { // 0x49c40f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049c410: { // 0x49c410: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c411: { // 0x49c411: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0049c414: { // 0x49c414: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
