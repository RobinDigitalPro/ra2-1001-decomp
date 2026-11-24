#include "recovered/recovery_b740_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b740 {
namespace {
void f_002904b0(Memory&,State&,Frame&,const Operations&);
void f_000e4b00(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002904b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006904b0: { // 0x6904b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006904b1: { // 0x6904b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006904b2: { // 0x6904b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006904b3: { // 0x6904b3: c744240800000000 MOV dword ptr [ESP + 8], 0
    m.w32((f.sp+8u), 0u);
  }
  L006904bb: { // 0x6904bb: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006904bd: { // 0x6904bd: bf04000000 MOV EDI, 4
    s.di = 4u;
  }
  L006904c2: { // 0x6904c2: db442408 FILD dword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.load_integer32(m.r32(address));
  }
  L006904c6: { // 0x6904c6: d806 FADD dword ptr [ESI]
    const auto address=(s.si);
    s.fp.add32(m.r32(address));
  }
  L006904c8: { // 0x6904c8: e883a50d00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6882509u); flags=s.arithmetic_flags;
  }
  L006904cd: { // 0x6904cd: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L006904d0: { // 0x6904d0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L006904d1: { // 0x6904d1: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L006904d5: { // 0x6904d5: 75eb JNZ 0x6904c2
    if(integer::condition("JNZ",flags)) goto L006904c2;
  }
  L006904d7: { // 0x6904d7: db442408 FILD dword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.load_integer32(m.r32(address));
  }
  L006904db: { // 0x6904db: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006904dc: { // 0x6904dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006904dd: { // 0x6904dd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006904de: { // 0x6904de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e4b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4b00: { // 0x4e4b00: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L004e4b04: { // 0x4e4b04: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e4b05: { // 0x4e4b05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e4b06: { // 0x4e4b06: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004e4b08: { // 0x4e4b08: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e4b09: { // 0x4e4b09: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L004e4b0b: { // 0x4e4b0b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4b0d: { // 0x4e4b0d: 741b JZ 0x4e4b2a
    if(integer::condition("JZ",flags)) goto L004e4b2a;
  }
  L004e4b0f: { // 0x4e4b0f: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L004e4b13: { // 0x4e4b13: da742414 FIDIV dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.divide_integer32(m.r32(address));
  }
  L004e4b17: { // 0x4e4b17: dc0dc0797800 FMUL qword ptr [0x7879c0]
    const auto address=(0x007879c0u);
    s.fp.multiply64(read64(m,address));
  }
  L004e4b1d: { // 0x4e4b1d: dc0528577800 FADD qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004e4b23: { // 0x4e4b23: e8285f2800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5131048u); flags=s.arithmetic_flags;
  }
  L004e4b28: { // 0x4e4b28: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L004e4b2a: { // 0x4e4b2a: 8b8f50020000 MOV ECX, dword ptr [EDI + 0x250]
    s.cx = m.r32((s.di+0x00000250u));
  }
  L004e4b30: { // 0x4e4b30: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e4b32: { // 0x4e4b32: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4b34: { // 0x4e4b34: 7422 JZ 0x4e4b58
    if(integer::condition("JZ",flags)) goto L004e4b58;
  }
  L004e4b36: { // 0x4e4b36: 8d8f3c020000 LEA ECX, [EDI + 0x23c]
    s.cx = (s.di+0x0000023cu);
  }
  L004e4b3c: { // 0x4e4b3c: e86fb91a00 CALL 0x6904b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006904b0u,5131073u); flags=s.arithmetic_flags;
  }
  L004e4b41: { // 0x4e4b41: dab750020000 FIDIV dword ptr [EDI + 0x250]
    const auto address=(s.di+0x00000250u);
    s.fp.divide_integer32(m.r32(address));
  }
  L004e4b47: { // 0x4e4b47: dc0dc0797800 FMUL qword ptr [0x7879c0]
    const auto address=(0x007879c0u);
    s.fp.multiply64(read64(m,address));
  }
  L004e4b4d: { // 0x4e4b4d: dc0528577800 FADD qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004e4b53: { // 0x4e4b53: e8f85e2800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5131096u); flags=s.arithmetic_flags;
  }
  L004e4b58: { // 0x4e4b58: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004e4b5a: { // 0x4e4b5a: 7439 JZ 0x4e4b95
    if(integer::condition("JZ",flags)) goto L004e4b95;
  }
  L004e4b5c: { // 0x4e4b5c: 8b5f78 MOV EBX, dword ptr [EDI + 0x78]
    s.bx = m.r32((s.di+0x00000078u));
  }
  L004e4b5f: { // 0x4e4b5f: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004e4b61: { // 0x4e4b61: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004e4b63: { // 0x4e4b63: 7e30 JLE 0x4e4b95
    if(integer::condition("JLE",flags)) goto L004e4b95;
  }
  L004e4b65: { // 0x4e4b65: 8b476c MOV EAX, dword ptr [EDI + 0x6c]
    s.ax = m.r32((s.di+0x0000006cu));
  }
  L004e4b68: { // 0x4e4b68: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L004e4b6b: { // 0x4e4b6b: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4b6d: { // 0x4e4b6d: 7421 JZ 0x4e4b90
    if(integer::condition("JZ",flags)) goto L004e4b90;
  }
  L004e4b6f: { // 0x4e4b6f: 8a4176 MOV AL, byte ptr [ECX + 0x76]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000076u)));
  }
  L004e4b72: { // 0x4e4b72: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4b74: { // 0x4e4b74: 751a JNZ 0x4e4b90
    if(integer::condition("JNZ",flags)) goto L004e4b90;
  }
  L004e4b76: { // 0x4e4b76: 8b9118040000 MOV EDX, dword ptr [ECX + 0x418]
    s.dx = m.r32((s.cx+0x00000418u));
  }
  L004e4b7c: { // 0x4e4b7c: 8a8248130000 MOV AL, byte ptr [EDX + 0x1348]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001348u)));
  }
  L004e4b82: { // 0x4e4b82: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4b84: { // 0x4e4b84: 740a JZ 0x4e4b90
    if(integer::condition("JZ",flags)) goto L004e4b90;
  }
  L004e4b86: { // 0x4e4b86: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004e4b88: { // 0x4e4b88: 6a02 PUSH 2
    f.push(m,2u);
  }
  L004e4b8a: { // 0x4e4b8a: ff901c010000 CALL dword ptr [EAX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000011cu)),5131152u); flags=s.arithmetic_flags;
  }
  L004e4b90: { // 0x4e4b90: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004e4b91: { // 0x4e4b91: 3bf3 CMP ESI, EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004e4b93: { // 0x4e4b93: 7cd0 JL 0x4e4b65
    if(integer::condition("JL",flags)) goto L004e4b65;
  }
  L004e4b95: { // 0x4e4b95: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e4b96: { // 0x4e4b96: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e4b97: { // 0x4e4b97: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e4b98: { // 0x4e4b98: c20800 RET 8
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
case 6882480u:f_002904b0(m,s,child,{});break;
case 5131008u:f_000e4b00(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery740 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004e4920(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4920: { // 0x4e4920: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L004e4923: { // 0x4e4923: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e4924: { // 0x4e4924: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L004e4926: { // 0x4e4926: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e4927: { // 0x4e4927: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e4928: { // 0x4e4928: 8db33c020000 LEA ESI,[EBX + 0x23c]
    s.si = (s.bx+0x0000023cu);
  }
  L004e492e: { // 0x4e492e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e4930: { // 0x4e4930: e87bbb1a00 CALL 0x006904b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006904b0u,5130549u); flags=s.arithmetic_flags;
  }
  L004e4935: { // 0x4e4935: 8b8350020000 MOV EAX,dword ptr [EBX + 0x250]
    s.ax = m.r32((s.bx+0x00000250u));
  }
  L004e493b: { // 0x4e493b: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L004e493f: { // 0x4e493f: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004e4943: { // 0x4e4943: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004e4947: { // 0x4e4947: 8b834c020000 MOV EAX,dword ptr [EBX + 0x24c]
    s.ax = m.r32((s.bx+0x0000024cu));
  }
  L004e494d: { // 0x4e494d: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004e494f: { // 0x4e494f: 0f8ef4000000 JLE 0x004e4a49
    if(integer::condition("JLE",flags)) goto L004e4a49;
  }
  L004e4955: { // 0x4e4955: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004e4957: { // 0x4e4957: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004e495b: { // 0x4e495b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e495d: { // 0x4e495d: c7834c02000000000000 MOV dword ptr [EBX + 0x24c],0x0
    m.w32((s.bx+0x0000024cu), 0x00000000u);
  }
  L004e4967: { // 0x4e4967: 0f8e36010000 JLE 0x004e4aa3
    if(integer::condition("JLE",flags)) goto L004e4aa3;
  }
  L004e496d: { // 0x4e496d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e496f: { // 0x4e496f: e83cbb1a00 CALL 0x006904b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006904b0u,5130612u); flags=s.arithmetic_flags;
  }
  L004e4974: { // 0x4e4974: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004e497a: { // 0x4e497a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004e497c: { // 0x4e497c: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004e497f: { // 0x4e497f: 0f851e010000 JNZ 0x004e4aa3
    if(integer::condition("JNZ",flags)) goto L004e4aa3;
  }
  L004e4985: { // 0x4e4985: 8b4b78 MOV ECX,dword ptr [EBX + 0x78]
    s.cx = m.r32((s.bx+0x00000078u));
  }
  L004e4988: { // 0x4e4988: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e498a: { // 0x4e498a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e498c: { // 0x4e498c: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004e4990: { // 0x4e4990: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004e4994: { // 0x4e4994: 0f8e09010000 JLE 0x004e4aa3
    if(integer::condition("JLE",flags)) goto L004e4aa3;
  }
  L004e499a: { // 0x4e499a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e499b: { // 0x4e499b: 8b4b6c MOV ECX,dword ptr [EBX + 0x6c]
    s.cx = m.r32((s.bx+0x0000006cu));
  }
  L004e499e: { // 0x4e499e: 8b2c81 MOV EBP,dword ptr [ECX + EAX*0x4]
    s.bp = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004e49a1: { // 0x4e49a1: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004e49a3: { // 0x4e49a3: 0f84e0000000 JZ 0x004e4a89
    if(integer::condition("JZ",flags)) goto L004e4a89;
  }
  L004e49a9: { // 0x4e49a9: 81c594020000 ADD EBP,0x294
    s.bp = integer::add(s.bp,0x00000294u,32,flags);
  }
  L004e49af: { // 0x4e49af: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004e49b1: { // 0x4e49b1: e8faba1a00 CALL 0x006904b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006904b0u,5130678u); flags=s.arithmetic_flags;
  }
  L004e49b6: { // 0x4e49b6: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004e49bc: { // 0x4e49bc: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004e49be: { // 0x4e49be: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004e49c1: { // 0x4e49c1: 0f85c2000000 JNZ 0x004e4a89
    if(integer::condition("JNZ",flags)) goto L004e4a89;
  }
  L004e49c7: { // 0x4e49c7: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e49c9: { // 0x4e49c9: 0f8ebc000000 JLE 0x004e4a8b
    if(integer::condition("JLE",flags)) goto L004e4a8b;
  }
  L004e49cf: { // 0x4e49cf: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004e49d1: { // 0x4e49d1: e8aabc1a00 CALL 0x00690680
    s.arithmetic_flags=flags; invoke(m,s,f,0x00690680u,5130710u); flags=s.arithmetic_flags;
  }
  L004e49d6: { // 0x4e49d6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004e49d8: { // 0x4e49d8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e49d9: { // 0x4e49d9: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004e49db: { // 0x4e49db: e800bb1a00 CALL 0x006904e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006904e0u,5130720u); flags=s.arithmetic_flags;
  }
  L004e49e0: { // 0x4e49e0: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004e49e6: { // 0x4e49e6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004e49e8: { // 0x4e49e8: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004e49eb: { // 0x4e49eb: 0f8580000000 JNZ 0x004e4a71
    if(integer::condition("JNZ",flags)) goto L004e4a71;
  }
  L004e49f1: { // 0x4e49f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e49f2: { // 0x4e49f2: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L004e49f7: { // 0x4e49f7: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004e49f9: { // 0x4e49f9: e812bb1a00 CALL 0x00690510
    s.arithmetic_flags=flags; invoke(m,s,f,0x00690510u,5130750u); flags=s.arithmetic_flags;
  }
  L004e49fe: { // 0x4e49fe: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004e4a02: { // 0x4e4a02: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004e4a06: { // 0x4e4a06: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e4a07: { // 0x4e4a07: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e4a08: { // 0x4e4a08: 8d8b3c020000 LEA ECX,[EBX + 0x23c]
    s.cx = (s.bx+0x0000023cu);
  }
  L004e4a0e: { // 0x4e4a0e: e8fdba1a00 CALL 0x00690510
    s.arithmetic_flags=flags; invoke(m,s,f,0x00690510u,5130771u); flags=s.arithmetic_flags;
  }
  L004e4a13: { // 0x4e4a13: a13c86aa00 MOV EAX,[0x00aa863c]
    s.ax = m.r32((0x00aa863cu));
  }
  L004e4a18: { // 0x4e4a18: 8b5334 MOV EDX,dword ptr [EBX + 0x34]
    s.dx = m.r32((s.bx+0x00000034u));
  }
  L004e4a1b: { // 0x4e4a1b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004e4a1d: { // 0x4e4a1d: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L004e4a20: { // 0x4e4a20: db81b8000000 FILD dword ptr [ECX + 0xb8]
    const auto address=(s.cx+0x000000b8u);
    s.fp.load_integer32(m.r32(address));
  }
  L004e4a26: { // 0x4e4a26: d88a48010000 FMUL float ptr [EDX + 0x148]
    const auto address=(s.dx+0x00000148u);
    s.fp.multiply32(m.r32(address));
  }
  L004e4a2c: { // 0x4e4a2c: d84c2410 FMUL float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L004e4a30: { // 0x4e4a30: e81b602800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5130805u); flags=s.arithmetic_flags;
  }
  L004e4a35: { // 0x4e4a35: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L004e4a39: { // 0x4e4a39: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004e4a3b: { // 0x4e4a3b: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004e4a3d: { // 0x4e4a3d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e4a3f: { // 0x4e4a3f: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L004e4a43: { // 0x4e4a43: 7c12 JL 0x004e4a57
    if(integer::condition("JL",flags)) goto L004e4a57;
  }
  L004e4a45: { // 0x4e4a45: 7e2a JLE 0x004e4a71
    if(integer::condition("JLE",flags)) goto L004e4a71;
  }
  L004e4a47: { // 0x4e4a47: eb8f JMP 0x004e49d8
    goto L004e49d8;
  }
  L004e4a49: { // 0x4e4a49: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004e4a4b: { // 0x4e4a4b: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L004e4a4f: { // 0x4e4a4f: 89834c020000 MOV dword ptr [EBX + 0x24c],EAX
    m.w32((s.bx+0x0000024cu), s.ax);
  }
  L004e4a55: { // 0x4e4a55: eb4c JMP 0x004e4aa3
    goto L004e4aa3;
  }
  L004e4a57: { // 0x4e4a57: 8b8b4c020000 MOV ECX,dword ptr [EBX + 0x24c]
    s.cx = m.r32((s.bx+0x0000024cu));
  }
  L004e4a5d: { // 0x4e4a5d: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004e4a61: { // 0x4e4a61: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L004e4a63: { // 0x4e4a63: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L004e4a65: { // 0x4e4a65: 898b4c020000 MOV dword ptr [EBX + 0x24c],ECX
    m.w32((s.bx+0x0000024cu), s.cx);
  }
  L004e4a6b: { // 0x4e4a6b: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004e4a6f: { // 0x4e4a6f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004e4a71: { // 0x4e4a71: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004e4a73: { // 0x4e4a73: e838ba1a00 CALL 0x006904b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006904b0u,5130872u); flags=s.arithmetic_flags;
  }
  L004e4a78: { // 0x4e4a78: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004e4a7e: { // 0x4e4a7e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004e4a80: { // 0x4e4a80: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004e4a83: { // 0x4e4a83: 0f843effffff JZ 0x004e49c7
    if(integer::condition("JZ",flags)) goto L004e49c7;
  }
  L004e4a89: { // 0x4e4a89: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e4a8b: { // 0x4e4a8b: 7415 JZ 0x004e4aa2
    if(integer::condition("JZ",flags)) goto L004e4aa2;
  }
  L004e4a8d: { // 0x4e4a8d: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004e4a91: { // 0x4e4a91: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004e4a95: { // 0x4e4a95: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004e4a96: { // 0x4e4a96: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004e4a98: { // 0x4e4a98: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004e4a9c: { // 0x4e4a9c: 0f8cf9feffff JL 0x004e499b
    if(integer::condition("JL",flags)) goto L004e499b;
  }
  L004e4aa2: { // 0x4e4aa2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e4aa3: { // 0x4e4aa3: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004e4aa7: { // 0x4e4aa7: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L004e4aab: { // 0x4e4aab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4aac: { // 0x4e4aac: e89f5f2800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5130929u); flags=s.arithmetic_flags;
  }
  L004e4ab1: { // 0x4e4ab1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4ab2: { // 0x4e4ab2: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004e4ab4: { // 0x4e4ab4: e847000000 CALL 0x004e4b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4b00u,5130937u); flags=s.arithmetic_flags;
  }
  L004e4ab9: { // 0x4e4ab9: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004e4abd: { // 0x4e4abd: 8b831c020000 MOV EAX,dword ptr [EBX + 0x21c]
    s.ax = m.r32((s.bx+0x0000021cu));
  }
  L004e4ac3: { // 0x4e4ac3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004e4ac5: { // 0x4e4ac5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e4ac6: { // 0x4e4ac6: 89831c020000 MOV dword ptr [EBX + 0x21c],EAX
    m.w32((s.bx+0x0000021cu), s.ax);
  }
  L004e4acc: { // 0x4e4acc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e4acd: { // 0x4e4acd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e4ace: { // 0x4e4ace: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L004e4ad1: { // 0x4e4ad1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
