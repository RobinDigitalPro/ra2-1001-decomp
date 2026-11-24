#include "recovered/recovery_b574_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b574 {
namespace {
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4956288u:f_000ba080(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery574 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00632b40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00632b40: { // 0x632b40: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00632b41: { // 0x632b41: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00632b43: { // 0x632b43: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00632b46: { // 0x632b46: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00632b49: { // 0x632b49: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00632b4a: { // 0x632b4a: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00632b4c: { // 0x632b4c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00632b4d: { // 0x632b4d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00632b4e: { // 0x632b4e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00632b50: { // 0x632b50: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00632b54: { // 0x632b54: 7412 JZ 0x00632b68
    if(integer::condition("JZ",flags)) goto L00632b68;
  }
  L00632b56: { // 0x632b56: 83fb03 CMP EBX,0x3
    (void)integer::sub(s.bx,0x00000003u,32,flags);
  }
  L00632b59: { // 0x632b59: 0f8e9c000000 JLE 0x00632bfb
    if(integer::condition("JLE",flags)) goto L00632bfb;
  }
  L00632b5f: { // 0x632b5f: 83fb05 CMP EBX,0x5
    (void)integer::sub(s.bx,0x00000005u,32,flags);
  }
  L00632b62: { // 0x632b62: 0f8f93000000 JG 0x00632bfb
    if(integer::condition("JG",flags)) goto L00632bfb;
  }
  L00632b68: { // 0x632b68: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  L00632b6d: { // 0x632b6d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00632b6f: { // 0x632b6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00632b71: { // 0x632b71: 0f8e84000000 JLE 0x00632bfb
    if(integer::condition("JLE",flags)) goto L00632bfb;
  }
  L00632b77: { // 0x632b77: 668b7d0a MOV DI,word ptr [EBP + 0xa]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bp+0x0000000au))) & 0xffffu);
  }
  L00632b7b: { // 0x632b7b: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  L00632b81: { // 0x632b81: 8b14b1 MOV EDX,dword ptr [ECX + ESI*0x4]
    s.dx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L00632b84: { // 0x632b84: 391a CMP dword ptr [EDX],EBX
    (void)integer::sub(m.r32((s.dx)),s.bx,32,flags);
  }
  L00632b86: { // 0x632b86: 7569 JNZ 0x00632bf1
    if(integer::condition("JNZ",flags)) goto L00632bf1;
  }
  L00632b88: { // 0x632b88: 668b4508 MOV AX,word ptr [EBP + 0x8]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000008u)));
  }
  L00632b8c: { // 0x632b8c: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L00632b8f: { // 0x632b8f: 662b4a22 SUB CX,word ptr [EDX + 0x22]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.dx+0x00000022u)),16,flags));
  }
  L00632b93: { // 0x632b93: 662b4220 SUB AX,word ptr [EDX + 0x20]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.dx+0x00000020u)),16,flags));
  }
  L00632b97: { // 0x632b97: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00632b9a: { // 0x632b9a: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00632b9d: { // 0x632b9d: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00632ba0: { // 0x632ba0: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00632ba4: { // 0x632ba4: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L00632ba8: { // 0x632ba8: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00632bac: { // 0x632bac: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L00632bb0: { // 0x632bb0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00632bb2: { // 0x632bb2: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00632bb4: { // 0x632bb4: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00632bb6: { // 0x632bb6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00632bb8: { // 0x632bb8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00632bba: { // 0x632bba: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00632bbd: { // 0x632bbd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00632bbf: { // 0x632bbf: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00632bc1: { // 0x632bc1: e8ba74e8ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6499270u); flags=s.arithmetic_flags;
  }
  L00632bc6: { // 0x632bc6: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00632bc9: { // 0x632bc9: e8827e1300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6499278u); flags=s.arithmetic_flags;
  }
  L00632bce: { // 0x632bce: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  L00632bd4: { // 0x632bd4: 8b1d881b8200 MOV EBX,dword ptr [0x00821b88]
    s.bx = m.r32((0x00821b88u));
  }
  L00632bda: { // 0x632bda: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00632bdd: { // 0x632bdd: 8b14b1 MOV EDX,dword ptr [ECX + ESI*0x4]
    s.dx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L00632be0: { // 0x632be0: 8b9b98030000 MOV EBX,dword ptr [EBX + 0x398]
    s.bx = m.r32((s.bx+0x00000398u));
  }
  L00632be6: { // 0x632be6: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L00632be8: { // 0x632be8: 3b0493 CMP EAX,dword ptr [EBX + EDX*0x4]
    (void)integer::sub(s.ax,m.r32((s.bx+(s.dx * 0x00000004u))),32,flags);
  }
  L00632beb: { // 0x632beb: 7c33 JL 0x00632c20
    if(integer::condition("JL",flags)) goto L00632c20;
  }
  L00632bed: { // 0x632bed: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00632bf1: { // 0x632bf1: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  L00632bf6: { // 0x632bf6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00632bf7: { // 0x632bf7: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00632bf9: { // 0x632bf9: 7c86 JL 0x00632b81
    if(integer::condition("JL",flags)) goto L00632b81;
  }
  L00632bfb: { // 0x632bfb: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L00632bfd: { // 0x632bfd: e855ad1300 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6499330u); flags=s.arithmetic_flags;
  }
  L00632c02: { // 0x632c02: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00632c05: { // 0x632c05: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00632c07: { // 0x632c07: 740c JZ 0x00632c15
    if(integer::condition("JZ",flags)) goto L00632c15;
  }
  L00632c09: { // 0x632c09: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00632c0c: { // 0x632c0c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00632c0d: { // 0x632c0d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00632c0e: { // 0x632c0e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00632c10: { // 0x632c10: e84b000000 CALL 0x00632c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00632c60u,6499349u); flags=s.arithmetic_flags;
  }
  L00632c15: { // 0x632c15: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00632c17: { // 0x632c17: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00632c18: { // 0x632c18: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00632c19: { // 0x632c19: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00632c1a: { // 0x632c1a: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00632c1c: { // 0x632c1c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00632c1d: { // 0x632c1d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00632c20: { // 0x632c20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00632c21: { // 0x632c21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00632c22: { // 0x632c22: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00632c24: { // 0x632c24: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00632c25: { // 0x632c25: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00632c27: { // 0x632c27: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00632c28: { // 0x632c28: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
