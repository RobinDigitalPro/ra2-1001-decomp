#include "recovered/recovery_b107_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b107 {
namespace {
void f_00228af0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);


void f_00228af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00628af0: { // 0x628af0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00628af1: { // 0x628af1: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00628af5: { // 0x628af5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00628af6: { // 0x628af6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00628af7: { // 0x628af7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00628af8: { // 0x628af8: 0fbf28 MOVSX EBP,word ptr [EAX]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00628afb: { // 0x628afb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00628afc: { // 0x628afc: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00628afe: { // 0x628afe: 0fbf7802 MOVSX EDI,word ptr [EAX + 0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00628b02: { // 0x628b02: 8b8e8c140000 MOV ECX,dword ptr [ESI + 0x148c]
    s.cx = m.r32((s.si+0x0000148cu));
  }
  L00628b08: { // 0x628b08: 8b8698140000 MOV EAX,dword ptr [ESI + 0x1498]
    s.ax = m.r32((s.si+0x00001498u));
  }
  L00628b0e: { // 0x628b0e: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00628b10: { // 0x628b10: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00628b14: { // 0x628b14: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L00628b16: { // 0x628b16: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00628b1a: { // 0x628b1a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00628b1e: { // 0x628b1e: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L00628b24: { // 0x628b24: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00628b28: { // 0x628b28: e8231f1400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6458157u); flags=s.arithmetic_flags;
  }
  L00628b2d: { // 0x628b2d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00628b2f: { // 0x628b2f: 8b8694140000 MOV EAX,dword ptr [ESI + 0x1494]
    s.ax = m.r32((s.si+0x00001494u));
  }
  L00628b35: { // 0x628b35: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00628b37: { // 0x628b37: 03fd ADD EDI,EBP
    s.di = integer::add(s.di,s.bp,32,flags);
  }
  L00628b39: { // 0x628b39: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00628b3d: { // 0x628b3d: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00628b41: { // 0x628b41: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L00628b47: { // 0x628b47: da869c140000 FIADD dword ptr [ESI + 0x149c]
    const auto address=(s.si+0x0000149cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00628b4d: { // 0x628b4d: e8fe1e1400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6458194u); flags=s.arithmetic_flags;
  }
  L00628b52: { // 0x628b52: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00628b56: { // 0x628b56: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00628b57: { // 0x628b57: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00628b59: { // 0x628b59: 7501 JNZ 0x00628b5c
    if(integer::condition("JNZ",flags)) goto L00628b5c;
  }
  L00628b5b: { // 0x628b5b: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00628b5c: { // 0x628b5c: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L00628b60: { // 0x628b60: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00628b65: { // 0x628b65: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L00628b67: { // 0x628b67: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00628b69: { // 0x628b69: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L00628b6b: { // 0x628b6b: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00628b6e: { // 0x628b6e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00628b70: { // 0x628b70: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  L00628b73: { // 0x628b73: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00628b76: { // 0x628b76: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00628b77: { // 0x628b77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00628b78: { // 0x628b78: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00628b79: { // 0x628b79: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00628b7a: { // 0x628b7a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00628b7b: { // 0x628b7b: c20800 RET 0x8
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6458096u:f_00228af0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery107 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00625df0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00625df0: { // 0x625df0: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L00625df5: { // 0x625df5: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00625df8: { // 0x625df8: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00625dfb: { // 0x625dfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00625dfc: { // 0x625dfc: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00625dfe: { // 0x625dfe: 7410 JZ 0x00625e10
    if(integer::condition("JZ",flags)) goto L00625e10;
  }
  L00625e00: { // 0x625e00: c704b5b07ea20000000000 MOV dword ptr [ESI*0x4 + 0xa27eb0],0x0
    m.w32(((s.si * 0x00000004u)+0x00a27eb0u), 0x00000000u);
  }
  L00625e0b: { // 0x625e0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00625e0c: { // 0x625e0c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00625e0f: { // 0x625e0f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00625e10: { // 0x625e10: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00625e13: { // 0x625e13: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00625e14: { // 0x625e14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00625e15: { // 0x625e15: 8b1cc1 MOV EBX,dword ptr [ECX + EAX*0x8]
    s.bx = m.r32((s.cx+(s.ax * 0x00000008u)));
  }
  L00625e18: { // 0x625e18: 8d3cc1 LEA EDI,[ECX + EAX*0x8]
    s.di = (s.cx+(s.ax * 0x00000008u));
  }
  L00625e1b: { // 0x625e1b: a0d47ea200 MOV AL,[0x00a27ed4]
    s.ax = with_al(s.ax, m.r8((0x00a27ed4u)));
  }
  L00625e20: { // 0x625e20: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00625e22: { // 0x625e22: 7443 JZ 0x00625e67
    if(integer::condition("JZ",flags)) goto L00625e67;
  }
  L00625e24: { // 0x625e24: 8b0d9458a200 MOV ECX,dword ptr [0x00a25894]
    s.cx = m.r32((0x00a25894u));
  }
  L00625e2a: { // 0x625e2a: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L00625e32: { // 0x625e32: db059858a200 FILD dword ptr [0x00a25898]
    const auto address=(0x00a25898u);
    s.fp.load_integer32(m.r32(address));
  }
  L00625e38: { // 0x625e38: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00625e3c: { // 0x625e3c: df6c240c FILD qword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00625e40: { // 0x625e40: def9 FDIVP
    numeric_b88::detail::reg<0xdef9>(s.fp);
  }
  L00625e42: { // 0x625e42: d83d3c367900 FDIVR float ptr [0x0079363c]
    const auto address=(0x0079363cu);
    reverse_divide32(s.fp,m.r32(address));
  }
  L00625e48: { // 0x625e48: e8034c1400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6446669u); flags=s.arithmetic_flags;
  }
  L00625e4d: { // 0x625e4d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00625e4e: { // 0x625e4e: 8b0d287fa200 MOV ECX,dword ptr [0x00a27f28]
    s.cx = m.r32((0x00a27f28u));
  }
  L00625e54: { // 0x625e54: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00625e56: { // 0x625e56: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00625e58: { // 0x625e58: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L00625e5b: { // 0x625e5b: d1fa SAR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00625e5d: { // 0x625e5d: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00625e5f: { // 0x625e5f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00625e61: { // 0x625e61: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00625e63: { // 0x625e63: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00625e65: { // 0x625e65: eb0d JMP 0x00625e74
    goto L00625e74;
  }
  L00625e67: { // 0x625e67: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00625e68: { // 0x625e68: b9c885a200 MOV ECX,0xa285c8
    s.cx = 0x00a285c8u;
  }
  L00625e6d: { // 0x625e6d: e83ef0efff CALL 0x00524eb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00524eb0u,6446706u); flags=s.arithmetic_flags;
  }
  L00625e72: { // 0x625e72: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00625e74: { // 0x625e74: 8b154c67a500 MOV EDX,dword ptr [0x00a5674c]
    s.dx = m.r32((0x00a5674cu));
  }
  L00625e7a: { // 0x625e7a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00625e7b: { // 0x625e7b: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
  L00625e7e: { // 0x625e7e: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  L00625e83: { // 0x625e83: f7e2 MUL EDX
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.dx);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L00625e85: { // 0x625e85: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00625e8a: { // 0x625e8a: c1ea05 SHR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::right);
  }
  L00625e8d: { // 0x625e8d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00625e8f: { // 0x625e8f: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00625e91: { // 0x625e91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00625e92: { // 0x625e92: 8904b5b07ea200 MOV dword ptr [ESI*0x4 + 0xa27eb0],EAX
    m.w32(((s.si * 0x00000004u)+0x00a27eb0u), s.ax);
  }
  L00625e99: { // 0x625e99: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00625e9a: { // 0x625e9a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00625e9d: { // 0x625e9d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00632c60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00632c60: { // 0x632c60: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00632c64: { // 0x632c64: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00632c67: { // 0x632c67: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00632c68: { // 0x632c68: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00632c69: { // 0x632c69: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00632c6b: { // 0x632c6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00632c6c: { // 0x632c6c: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00632c6e: { // 0x632c6e: c74610db0f493f MOV dword ptr [ESI + 0x10],0x3f490fdb
    m.w32((s.si+0x00000010u), 0x3f490fdbu);
  }
  L00632c75: { // 0x632c75: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00632c7b: { // 0x632c7b: 8b918c000000 MOV EDX,dword ptr [ECX + 0x8c]
    s.dx = m.r32((s.cx+0x0000008cu));
  }
  L00632c81: { // 0x632c81: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  L00632c88: { // 0x632c88: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L00632c8b: { // 0x632c8b: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00632c90: { // 0x632c90: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00632c94: { // 0x632c94: 8b8880000000 MOV ECX,dword ptr [EAX + 0x80]
    s.cx = m.r32((s.ax+0x00000080u));
  }
  L00632c9a: { // 0x632c9a: 895620 MOV dword ptr [ESI + 0x20],EDX
    m.w32((s.si+0x00000020u), s.dx);
  }
  L00632c9d: { // 0x632c9d: 894e1c MOV dword ptr [ESI + 0x1c],ECX
    m.w32((s.si+0x0000001cu), s.cx);
  }
  L00632ca0: { // 0x632ca0: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00632ca5: { // 0x632ca5: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  L00632ca8: { // 0x632ca8: c7462c00000000 MOV dword ptr [ESI + 0x2c],0x0
    m.w32((s.si+0x0000002cu), 0x00000000u);
  }
  L00632caf: { // 0x632caf: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00632cb5: { // 0x632cb5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00632cb7: { // 0x632cb7: 894e30 MOV dword ptr [ESI + 0x30],ECX
    m.w32((s.si+0x00000030u), s.cx);
  }
  L00632cba: { // 0x632cba: c7463800000000 MOV dword ptr [ESI + 0x38],0x0
    m.w32((s.si+0x00000038u), 0x00000000u);
  }
  L00632cc1: { // 0x632cc1: 88463c MOV byte ptr [ESI + 0x3c],AL
    m.w8((s.si+0x0000003cu), (s.ax & 0xffu));
  }
  L00632cc4: { // 0x632cc4: 88463d MOV byte ptr [ESI + 0x3d],AL
    m.w8((s.si+0x0000003du), (s.ax & 0xffu));
  }
  L00632cc7: { // 0x632cc7: 8b3db8bc8100 MOV EDI,dword ptr [0x0081bcb8]
    s.di = m.r32((0x0081bcb8u));
  }
  L00632ccd: { // 0x632ccd: 8b2dbcbc8100 MOV EBP,dword ptr [0x0081bcbc]
    s.bp = m.r32((0x0081bcbcu));
  }
  L00632cd3: { // 0x632cd3: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00632cd7: { // 0x632cd7: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L00632cdb: { // 0x632cdb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00632cdc: { // 0x632cdc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00632cdd: { // 0x632cdd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00632ce2: { // 0x632ce2: e8095effff CALL 0x00628af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00628af0u,6499559u); flags=s.arithmetic_flags;
  }
  L00632ce7: { // 0x632ce7: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00632ce9: { // 0x632ce9: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00632cec: { // 0x632cec: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00632cee: { // 0x632cee: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00632cf0: { // 0x632cf0: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00632cf3: { // 0x632cf3: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00632cf6: { // 0x632cf6: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L00632cf9: { // 0x632cf9: 8b0dc0bc8100 MOV ECX,dword ptr [0x0081bcc0]
    s.cx = m.r32((0x0081bcc0u));
  }
  L00632cff: { // 0x632cff: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00632d01: { // 0x632d01: a1c4bc8100 MOV EAX,[0x0081bcc4]
    s.ax = m.r32((0x0081bcc4u));
  }
  L00632d06: { // 0x632d06: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00632d08: { // 0x632d08: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00632d0a: { // 0x632d0a: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00632d0c: { // 0x632d0c: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00632d0e: { // 0x632d0e: 7f02 JG 0x00632d12
    if(integer::condition("JG",flags)) goto L00632d12;
  }
  L00632d10: { // 0x632d10: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00632d12: { // 0x632d12: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L00632d14: { // 0x632d14: 7e04 JLE 0x00632d1a
    if(integer::condition("JLE",flags)) goto L00632d1a;
  }
  L00632d16: { // 0x632d16: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00632d18: { // 0x632d18: eb08 JMP 0x00632d22
    goto L00632d22;
  }
  L00632d1a: { // 0x632d1a: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00632d1c: { // 0x632d1c: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00632d1e: { // 0x632d1e: 7f02 JG 0x00632d22
    if(integer::condition("JG",flags)) goto L00632d22;
  }
  L00632d20: { // 0x632d20: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00632d22: { // 0x632d22: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L00632d24: { // 0x632d24: 7e06 JLE 0x00632d2c
    if(integer::condition("JLE",flags)) goto L00632d2c;
  }
  L00632d26: { // 0x632d26: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L00632d2a: { // 0x632d2a: eb1e JMP 0x00632d4a
    goto L00632d4a;
  }
  L00632d2c: { // 0x632d2c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00632d2e: { // 0x632d2e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00632d30: { // 0x632d30: 7f02 JG 0x00632d34
    if(integer::condition("JG",flags)) goto L00632d34;
  }
  L00632d32: { // 0x632d32: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00632d34: { // 0x632d34: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00632d36: { // 0x632d36: 7e06 JLE 0x00632d3e
    if(integer::condition("JLE",flags)) goto L00632d3e;
  }
  L00632d38: { // 0x632d38: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00632d3c: { // 0x632d3c: eb0c JMP 0x00632d4a
    goto L00632d4a;
  }
  L00632d3e: { // 0x632d3e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00632d40: { // 0x632d40: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00632d44: { // 0x632d44: 7f04 JG 0x00632d4a
    if(integer::condition("JG",flags)) goto L00632d4a;
  }
  L00632d46: { // 0x632d46: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00632d4a: { // 0x632d4a: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00632d4e: { // 0x632d4e: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00632d52: { // 0x632d52: d95e0c FSTP float ptr [ESI + 0xc]
    const auto address=(s.si+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00632d55: { // 0x632d55: a110e3a900 MOV EAX,[0x00a9e310]
    s.ax = m.r32((0x00a9e310u));
  }
  L00632d5a: { // 0x632d5a: 890de0e2a900 MOV dword ptr [0x00a9e2e0],ECX
    m.w32((0x00a9e2e0u), s.cx);
  }
  L00632d60: { // 0x632d60: 390518e3a900 CMP dword ptr [0x00a9e318],EAX
    (void)integer::sub(m.r32((0x00a9e318u)),s.ax,32,flags);
  }
  L00632d66: { // 0x632d66: 7c2f JL 0x00632d97
    if(integer::condition("JL",flags)) goto L00632d97;
  }
  L00632d68: { // 0x632d68: 8a0d15e3a900 MOV CL,byte ptr [0x00a9e315]
    s.cx = with_al(s.cx, m.r8((0x00a9e315u)));
  }
  L00632d6e: { // 0x632d6e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00632d70: { // 0x632d70: 7504 JNZ 0x00632d76
    if(integer::condition("JNZ",flags)) goto L00632d76;
  }
  L00632d72: { // 0x632d72: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00632d74: { // 0x632d74: 7539 JNZ 0x00632daf
    if(integer::condition("JNZ",flags)) goto L00632daf;
  }
  L00632d76: { // 0x632d76: 8b0d1ce3a900 MOV ECX,dword ptr [0x00a9e31c]
    s.cx = m.r32((0x00a9e31cu));
  }
  L00632d7c: { // 0x632d7c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00632d7e: { // 0x632d7e: 7e2f JLE 0x00632daf
    if(integer::condition("JLE",flags)) goto L00632daf;
  }
  L00632d80: { // 0x632d80: 8b1508e3a900 MOV EDX,dword ptr [0x00a9e308]
    s.dx = m.r32((0x00a9e308u));
  }
  L00632d86: { // 0x632d86: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00632d88: { // 0x632d88: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00632d8a: { // 0x632d8a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00632d8b: { // 0x632d8b: b908e3a900 MOV ECX,0xa9e308
    s.cx = 0x00a9e308u;
  }
  L00632d90: { // 0x632d90: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6499731u); flags=s.arithmetic_flags;
  }
  L00632d93: { // 0x632d93: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00632d95: { // 0x632d95: 7418 JZ 0x00632daf
    if(integer::condition("JZ",flags)) goto L00632daf;
  }
  L00632d97: { // 0x632d97: 8b0d18e3a900 MOV ECX,dword ptr [0x00a9e318]
    s.cx = m.r32((0x00a9e318u));
  }
  L00632d9d: { // 0x632d9d: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00632d9f: { // 0x632d9f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00632da0: { // 0x632da0: 890d18e3a900 MOV dword ptr [0x00a9e318],ECX
    m.w32((0x00a9e318u), s.cx);
  }
  L00632da6: { // 0x632da6: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  L00632dac: { // 0x632dac: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00632daf: { // 0x632daf: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00632db1: { // 0x632db1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00632db2: { // 0x632db2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00632db3: { // 0x632db3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00632db4: { // 0x632db4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00632db7: { // 0x632db7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
