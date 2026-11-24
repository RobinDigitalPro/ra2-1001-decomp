#include "recovered/recovery_b123_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b123 {
namespace {
void f_00191ed0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00191ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591ed0: { // 0x591ed0: 8b8198000000 MOV EAX,dword ptr [ECX + 0x98]
    s.ax = m.r32((s.cx+0x00000098u));
  }
  L00591ed6: { // 0x591ed6: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L00591ed9: { // 0x591ed9: 050080a200 ADD EAX,0xa28000
    s.ax = integer::add(s.ax,0x00a28000u,32,flags);
  }
  L00591ede: { // 0x591ede: c3 RET
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5840592u:f_00191ed0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
default:throw std::domain_error("recovery123 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006f7be0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006f7be0: { // 0x6f7be0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006f7be1: { // 0x6f7be1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006f7be3: { // 0x6f7be3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006f7be4: { // 0x6f7be4: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L006f7bea: { // 0x6f7bea: 8bb8c8030000 MOV EDI,dword ptr [EAX + 0x3c8]
    s.di = m.r32((s.ax+0x000003c8u));
  }
  L006f7bf0: { // 0x6f7bf0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006f7bf2: { // 0x6f7bf2: 0f84b2000000 JZ 0x006f7caa
    if(integer::condition("JZ",flags)) goto L006f7caa;
  }
  L006f7bf8: { // 0x6f7bf8: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006f7bfe: { // 0x6f7bfe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006f7c00: { // 0x6f7c00: 8b91d8070000 MOV EDX,dword ptr [ECX + 0x7d8]
    s.dx = m.r32((s.cx+0x000007d8u));
  }
  L006f7c06: { // 0x6f7c06: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006f7c08: { // 0x6f7c08: 7e12 JLE 0x006f7c1c
    if(integer::condition("JLE",flags)) goto L006f7c1c;
  }
  L006f7c0a: { // 0x6f7c0a: 8b89cc070000 MOV ECX,dword ptr [ECX + 0x7cc]
    s.cx = m.r32((s.cx+0x000007ccu));
  }
  L006f7c10: { // 0x6f7c10: 3939 CMP dword ptr [ECX],EDI
    (void)integer::sub(m.r32((s.cx)),s.di,32,flags);
  }
  L006f7c12: { // 0x6f7c12: 7421 JZ 0x006f7c35
    if(integer::condition("JZ",flags)) goto L006f7c35;
  }
  L006f7c14: { // 0x6f7c14: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006f7c15: { // 0x6f7c15: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L006f7c18: { // 0x6f7c18: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006f7c1a: { // 0x6f7c1a: 7cf4 JL 0x006f7c10
    if(integer::condition("JL",flags)) goto L006f7c10;
  }
  L006f7c1c: { // 0x6f7c1c: 8b8628020000 MOV EAX,dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  L006f7c22: { // 0x6f7c22: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006f7c24: { // 0x6f7c24: 750f JNZ 0x006f7c35
    if(integer::condition("JNZ",flags)) goto L006f7c35;
  }
  L006f7c26: { // 0x6f7c26: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006f7c2c: { // 0x6f7c2c: e8bfcbdfff CALL 0x004f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,7306289u); flags=s.arithmetic_flags;
  }
  L006f7c31: { // 0x6f7c31: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006f7c33: { // 0x6f7c33: 7475 JZ 0x006f7caa
    if(integer::condition("JZ",flags)) goto L006f7caa;
  }
  L006f7c35: { // 0x6f7c35: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L006f7c3b: { // 0x6f7c3b: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  L006f7c3e: { // 0x6f7c3e: 7419 JZ 0x006f7c59
    if(integer::condition("JZ",flags)) goto L006f7c59;
  }
  L006f7c40: { // 0x6f7c40: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006f7c41: { // 0x6f7c41: 7536 JNZ 0x006f7c79
    if(integer::condition("JNZ",flags)) goto L006f7c79;
  }
  L006f7c43: { // 0x6f7c43: 8a867c050000 MOV AL,byte ptr [ESI + 0x57c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000057cu)));
  }
  L006f7c49: { // 0x6f7c49: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006f7c4b: { // 0x6f7c4b: 752c JNZ 0x006f7c79
    if(integer::condition("JNZ",flags)) goto L006f7c79;
  }
  L006f7c4d: { // 0x6f7c4d: c786a800000000000000 MOV dword ptr [ESI + 0xa8],0x0
    m.w32((s.si+0x000000a8u), 0x00000000u);
  }
  L006f7c57: { // 0x6f7c57: eb20 JMP 0x006f7c79
    goto L006f7c79;
  }
  L006f7c59: { // 0x6f7c59: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006f7c5b: { // 0x6f7c5b: e860a9ffff CALL 0x006f25c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006f25c0u,7306336u); flags=s.arithmetic_flags;
  }
  L006f7c60: { // 0x6f7c60: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006f7c62: { // 0x6f7c62: 7415 JZ 0x006f7c79
    if(integer::condition("JZ",flags)) goto L006f7c79;
  }
  L006f7c64: { // 0x6f7c64: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006f7c66: { // 0x6f7c66: e8e5afffff CALL 0x006f2c50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006f2c50u,7306347u); flags=s.arithmetic_flags;
  }
  L006f7c6b: { // 0x6f7c6b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006f7c6d: { // 0x6f7c6d: 740a JZ 0x006f7c79
    if(integer::condition("JZ",flags)) goto L006f7c79;
  }
  L006f7c6f: { // 0x6f7c6f: c786a800000001000000 MOV dword ptr [ESI + 0xa8],0x1
    m.w32((s.si+0x000000a8u), 0x00000001u);
  }
  L006f7c79: { // 0x6f7c79: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006f7c7b: { // 0x6f7c7b: e850a2e9ff CALL 0x00591ed0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00591ed0u,7306368u); flags=s.arithmetic_flags;
  }
  L006f7c80: { // 0x6f7c80: dd4010 FLD double ptr [EAX + 0x10]
    const auto address=(s.ax+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L006f7c83: { // 0x6f7c83: dc0d08667800 FMUL double ptr [0x00786608]
    const auto address=(0x00786608u);
    s.fp.multiply64(read64(m,address));
  }
  L006f7c89: { // 0x6f7c89: e8c22d0700 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7306382u); flags=s.arithmetic_flags;
  }
  L006f7c8e: { // 0x6f7c8e: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006f7c94: { // 0x6f7c94: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L006f7c96: { // 0x6f7c96: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006f7c98: { // 0x6f7c98: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L006f7c9e: { // 0x6f7c9e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006f7ca0: { // 0x6f7ca0: e89b81f3ff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,7306405u); flags=s.arithmetic_flags;
  }
  L006f7ca5: { // 0x6f7ca5: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L006f7ca7: { // 0x6f7ca7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006f7ca8: { // 0x6f7ca8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006f7ca9: { // 0x6f7ca9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006f7caa: { // 0x6f7caa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006f7cac: { // 0x6f7cac: e89fc8dcff CALL 0x004c4550
    s.arithmetic_flags=flags; invoke(m,s,f,0x004c4550u,7306417u); flags=s.arithmetic_flags;
  }
  L006f7cb1: { // 0x6f7cb1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006f7cb2: { // 0x6f7cb2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006f7cb3: { // 0x6f7cb3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
