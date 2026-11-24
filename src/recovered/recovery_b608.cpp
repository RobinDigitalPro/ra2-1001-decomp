// Reuse accepted exact memcpy body and transfer the same guest-stack state.
#include "recovery_b233.cpp"
#include "recovery_b608_machine.hpp"
namespace ra2::recovered::recovery_b233 {
static void call608(Memory&m,recovery_b608::State&s,recovery_b608::Frame&f){
 State t{};t.ax=s.ax;t.cx=s.cx;t.dx=s.dx;t.bx=s.bx;t.bp=s.bp;t.si=s.si;t.di=s.di;t.fp=s.fp;t.arithmetic_flags=s.arithmetic_flags;
 Frame g{f.entry_sp,f.sp,f.outer_return};f_0036ebd0(m,t,g,{});
 s.ax=t.ax;s.cx=t.cx;s.dx=t.dx;s.bx=t.bx;s.bp=t.bp;s.si=t.si;s.di=t.di;s.fp=t.fp;s.arithmetic_flags=t.arithmetic_flags;f.sp=g.sp;
}
}
#include "recovered/recovery_b608_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b608 {
namespace {
void f_0035f180(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0035f180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f180: { // 0x0075f180: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075f181: { // 0x0075f181: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075f182: { // 0x0075f182: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0075f184: { // 0x0075f184: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0075f186: { // 0x0075f186: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L0075f189: { // 0x0075f189: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0075f18b: { // 0x0075f18b: 7446 JZ 0x0075f1d3
    if(integer::condition("JZ",flags)) goto L0075f1d3;
  }
  L0075f18d: { // 0x0075f18d: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L0075f191: { // 0x0075f191: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0075f193: { // 0x0075f193: 743e JZ 0x0075f1d3
    if(integer::condition("JZ",flags)) goto L0075f1d3;
  }
  L0075f195: { // 0x0075f195: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0075f199: { // 0x0075f199: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0075f19b: { // 0x0075f19b: 7e36 JLE 0x0075f1d3
    if(integer::condition("JLE",flags)) goto L0075f1d3;
  }
  L0075f19d: { // 0x0075f19d: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0075f1a0: { // 0x0075f1a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075f1a1: { // 0x0075f1a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075f1a3: { // 0x0075f1a3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0075f1a5: { // 0x0075f1a5: 740d JZ 0x0075f1b4
    if(integer::condition("JZ",flags)) goto L0075f1b4;
  }
  L0075f1a7: { // 0x0075f1a7: 8b7e18 MOV EDI,dword ptr [ESI + 0x18]
    s.di = m.r32((s.si+0x00000018u));
  }
  L0075f1aa: { // 0x0075f1aa: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L0075f1ac: { // 0x0075f1ac: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0075f1ae: { // 0x0075f1ae: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0075f1b0: { // 0x0075f1b0: 7c02 JL 0x0075f1b4
    if(integer::condition("JL",flags)) goto L0075f1b4;
  }
  L0075f1b2: { // 0x0075f1b2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0075f1b4: { // 0x0075f1b4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0075f1b6: { // 0x0075f1b6: 7e10 JLE 0x0075f1c8
    if(integer::condition("JLE",flags)) goto L0075f1c8;
  }
  L0075f1b8: { // 0x0075f1b8: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L0075f1bb: { // 0x0075f1bb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075f1bc: { // 0x0075f1bc: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0075f1be: { // 0x0075f1be: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f1bf: { // 0x0075f1bf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075f1c0: { // 0x0075f1c0: e80bfa0000 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,7729605u); flags=s.arithmetic_flags;
  }
  L0075f1c5: { // 0x0075f1c5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0075f1c8: { // 0x0075f1c8: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L0075f1cb: { // 0x0075f1cb: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0075f1cd: { // 0x0075f1cd: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  L0075f1d0: { // 0x0075f1d0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0075f1d2: { // 0x0075f1d2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f1d3: { // 0x0075f1d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f1d4: { // 0x0075f1d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f1d5: { // 0x0075f1d5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x76ebd0u:ra2::recovered::recovery_b233::call608(m,s,child);break;
case 7729536u:f_0035f180(m,s,child,{});break;
default:throw std::domain_error("recovery608 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00630c10(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,16> readonly0{236,118,0,144,64,236,118,0,108,236,118,0,144,236,118,0};leaf::Memory table0(readonly0.data(),0x76ec30u,16);m.add(table0);
 std::array<std::uint8_t,32> readonly1{15,237,118,0,252,236,118,0,244,236,118,0,236,236,118,0,228,236,118,0,220,236,118,0,212,236,118,0,204,236,118,0};leaf::Memory table1(readonly1.data(),0x76ecacu,32);m.add(table1);
 std::array<std::uint8_t,16> readonly2{40,237,118,0,48,237,118,0,60,237,118,0,80,237,118,0};leaf::Memory table2(readonly2.data(),0x76ed18u,16);m.add(table2);
 std::array<std::uint8_t,16> readonly3{238,118,0,144,200,237,118,0,232,237,118,0,16,238,118,0};leaf::Memory table3(readonly3.data(),0x76edb8u,16);m.add(table3);
 std::array<std::uint8_t,32> readonly4{100,238,118,0,108,238,118,0,116,238,118,0,124,238,118,0,132,238,118,0,140,238,118,0,148,238,118,0,167,238,118,0};leaf::Memory table4(readonly4.data(),0x76ee44u,32);m.add(table4);
 std::array<std::uint8_t,16> readonly5{192,238,118,0,200,238,118,0,216,238,118,0,236,238,118,0};leaf::Memory table5(readonly5.data(),0x76eeb0u,16);m.add(table5);

 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00630c10: { // 0x630c10: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00630c14: { // 0x630c14: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00630c17: { // 0x630c17: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00630c19: { // 0x630c19: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00630c1a: { // 0x630c1a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00630c1b: { // 0x630c1b: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00630c1d: { // 0x630c1d: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00630c1f: { // 0x630c1f: 747d JZ 0x00630c9e
    if(integer::condition("JZ",flags)) goto L00630c9e;
  }
  L00630c21: { // 0x630c21: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00630c23: { // 0x630c23: 7479 JZ 0x00630c9e
    if(integer::condition("JZ",flags)) goto L00630c9e;
  }
  L00630c25: { // 0x630c25: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00630c27: { // 0x630c27: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00630c28: { // 0x630c28: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00630c29: { // 0x630c29: 8d4c2413 LEA ECX,[ESP + 0x13]
    s.cx = (f.sp+0x00000013u);
  }
  L00630c2d: { // 0x630c2d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00630c2f: { // 0x630c2f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00630c30: { // 0x630c30: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00630c32: { // 0x630c32: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00630c34: { // 0x630c34: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),6491191u); flags=s.arithmetic_flags;
  }
  L00630c37: { // 0x630c37: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00630c3a: { // 0x630c3a: 753d JNZ 0x00630c79
    if(integer::condition("JNZ",flags)) goto L00630c79;
  }
  L00630c3c: { // 0x630c3c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00630c3e: { // 0x630c3e: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L00630c40: { // 0x630c40: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00630c42: { // 0x630c42: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00630c46: { // 0x630c46: eb04 JMP 0x00630c4c
    goto L00630c4c;
  }
  L00630c48: { // 0x630c48: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00630c4c: { // 0x630c4c: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00630c50: { // 0x630c50: 3c0a CMP AL,0xa
    (void)integer::sub((s.ax & 0xffu),0x0000000au,8,flags);
  }
  L00630c52: { // 0x630c52: 7430 JZ 0x00630c84
    if(integer::condition("JZ",flags)) goto L00630c84;
  }
  L00630c54: { // 0x630c54: 3c0d CMP AL,0xd
    (void)integer::sub((s.ax & 0xffu),0x0000000du,8,flags);
  }
  L00630c56: { // 0x630c56: 740e JZ 0x00630c66
    if(integer::condition("JZ",flags)) goto L00630c66;
  }
  L00630c58: { // 0x630c58: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00630c5c: { // 0x630c5c: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00630c5e: { // 0x630c5e: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00630c60: { // 0x630c60: 7d04 JGE 0x00630c66
    if(integer::condition("JGE",flags)) goto L00630c66;
  }
  L00630c62: { // 0x630c62: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  L00630c64: { // 0x630c64: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00630c65: { // 0x630c65: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00630c66: { // 0x630c66: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00630c68: { // 0x630c68: 8d442413 LEA EAX,[ESP + 0x13]
    s.ax = (f.sp+0x00000013u);
  }
  L00630c6c: { // 0x630c6c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00630c6e: { // 0x630c6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00630c6f: { // 0x630c6f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00630c71: { // 0x630c71: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6491252u); flags=s.arithmetic_flags;
  }
  L00630c74: { // 0x630c74: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00630c77: { // 0x630c77: 74cf JZ 0x00630c48
    if(integer::condition("JZ",flags)) goto L00630c48;
  }
  L00630c79: { // 0x630c79: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00630c7d: { // 0x630c7d: c60101 MOV byte ptr [ECX],0x1
    m.w8((s.cx), 0x00000001u);
  }
  L00630c80: { // 0x630c80: c6042f00 MOV byte ptr [EDI + EBP*0x1],0x0
    m.w8((s.di+(s.bp * 0x00000001u)), 0x00000000u);
  }
  L00630c84: { // 0x630c84: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L00630c87: { // 0x630c87: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00630c89: { // 0x630c89: c6042f00 MOV byte ptr [EDI + EBP*0x1],0x0
    m.w8((s.di+(s.bp * 0x00000001u)), 0x00000000u);
  }
  L00630c8d: { // 0x630c8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00630c8e: { // 0x630c8e: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L00630c90: { // 0x630c90: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L00630c92: { // 0x630c92: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00630c93: { // 0x630c93: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00630c94: { // 0x630c94: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00630c95: { // 0x630c95: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00630c97: { // 0x630c97: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00630c98: { // 0x630c98: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00630c9b: { // 0x630c9b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00630c9e: { // 0x630c9e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00630c9f: { // 0x630c9f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00630ca1: { // 0x630ca1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00630ca2: { // 0x630ca2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00630ca5: { // 0x630ca5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
