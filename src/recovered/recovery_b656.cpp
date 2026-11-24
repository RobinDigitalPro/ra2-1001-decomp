#include "recovered/recovery_b656_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b656 {
namespace {
void f_00091af0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00091af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00491af0: { // 0x00491af0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00491af1: { // 0x00491af1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00491af5: { // 0x00491af5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00491af6: { // 0x00491af6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00491af8: { // 0x00491af8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00491af9: { // 0x00491af9: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  L00491afc: { // 0x00491afc: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00491afe: { // 0x00491afe: 7c2d JL 0x00491b2d
    if(integer::condition("JL",flags)) goto L00491b2d;
  }
  L00491b00: { // 0x00491b00: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00491b02: { // 0x00491b02: 8d4b0a LEA ECX,[EBX + 0xa]
    s.cx = (s.bx+0x0000000au);
  }
  L00491b05: { // 0x00491b05: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00491b07: { // 0x00491b07: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00491b08: { // 0x00491b08: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00491b0a: { // 0x00491b0a: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4791053u); flags=s.arithmetic_flags;
  }
  L00491b0d: { // 0x00491b0d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00491b0f: { // 0x00491b0f: 7428 JZ 0x00491b39
    if(integer::condition("JZ",flags)) goto L00491b39;
  }
  L00491b11: { // 0x00491b11: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00491b14: { // 0x00491b14: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00491b16: { // 0x00491b16: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00491b18: { // 0x00491b18: 7d13 JGE 0x00491b2d
    if(integer::condition("JGE",flags)) goto L00491b2d;
  }
  L00491b1a: { // 0x00491b1a: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00491b1d: { // 0x00491b1d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00491b1e: { // 0x00491b1e: c74482fc00000000 MOV dword ptr [EDX + EAX*0x4 + -0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), 0x00000000u);
  }
  L00491b26: { // 0x00491b26: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00491b29: { // 0x00491b29: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00491b2b: { // 0x00491b2b: 7ced JL 0x00491b1a
    if(integer::condition("JL",flags)) goto L00491b1a;
  }
  L00491b2d: { // 0x00491b2d: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00491b30: { // 0x00491b30: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00491b31: { // 0x00491b31: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00491b32: { // 0x00491b32: 8b0498 MOV EAX,dword ptr [EAX + EBX*0x4]
    s.ax = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L00491b35: { // 0x00491b35: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00491b36: { // 0x00491b36: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00491b39: { // 0x00491b39: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00491b3a: { // 0x00491b3a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00491b3b: { // 0x00491b3b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00491b3d: { // 0x00491b3d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00491b3e: { // 0x00491b3e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4791024u:f_00091af0(m,s,child,{});break;
default:throw std::domain_error("recovery656 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004e7aa0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e7aa0: { // 0x4e7aa0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004e7aa4: { // 0x4e7aa4: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004e7aa7: { // 0x4e7aa7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e7aa8: { // 0x4e7aa8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e7aa9: { // 0x4e7aa9: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L004e7aab: { // 0x4e7aab: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e7aac: { // 0x4e7aac: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e7aad: { // 0x4e7aad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e7aae: { // 0x4e7aae: 8d8b20540000 LEA ECX,[EBX + 0x5420]
    s.cx = (s.bx+0x00005420u);
  }
  L004e7ab4: { // 0x4e7ab4: e837a0faff CALL 0x00491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5143225u); flags=s.arithmetic_flags;
  }
  L004e7ab9: { // 0x4e7ab9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e7abb: { // 0x4e7abb: 7e7b JLE 0x004e7b38
    if(integer::condition("JLE",flags)) goto L004e7b38;
  }
  L004e7abd: { // 0x4e7abd: 8b4378 MOV EAX,dword ptr [EBX + 0x78]
    s.ax = m.r32((s.bx+0x00000078u));
  }
  L004e7ac0: { // 0x4e7ac0: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004e7ac2: { // 0x4e7ac2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e7ac4: { // 0x4e7ac4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004e7ac8: { // 0x4e7ac8: 7e6e JLE 0x004e7b38
    if(integer::condition("JLE",flags)) goto L004e7b38;
  }
  L004e7aca: { // 0x4e7aca: 8b3d18e0a100 MOV EDI,dword ptr [0x00a1e018]
    s.di = m.r32((0x00a1e018u));
  }
  L004e7ad0: { // 0x4e7ad0: 8b4b6c MOV ECX,dword ptr [EBX + 0x6c]
    s.cx = m.r32((s.bx+0x0000006cu));
  }
  L004e7ad3: { // 0x4e7ad3: 8b34a9 MOV ESI,dword ptr [ECX + EBP*0x4]
    s.si = m.r32((s.cx+(s.bp * 0x00000004u)));
  }
  L004e7ad6: { // 0x4e7ad6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004e7ad8: { // 0x4e7ad8: 7455 JZ 0x004e7b2f
    if(integer::condition("JZ",flags)) goto L004e7b2f;
  }
  L004e7ada: { // 0x4e7ada: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L004e7add: { // 0x4e7add: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e7adf: { // 0x4e7adf: 754e JNZ 0x004e7b2f
    if(integer::condition("JNZ",flags)) goto L004e7b2f;
  }
  L004e7ae1: { // 0x4e7ae1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e7ae3: { // 0x4e7ae3: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e7ae5: { // 0x4e7ae5: 7e18 JLE 0x004e7aff
    if(integer::condition("JLE",flags)) goto L004e7aff;
  }
  L004e7ae7: { // 0x4e7ae7: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L004e7aed: { // 0x4e7aed: 8b0d0ce0a100 MOV ECX,dword ptr [0x00a1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  L004e7af3: { // 0x4e7af3: 3911 CMP dword ptr [ECX],EDX
    (void)integer::sub(m.r32((s.cx)),s.dx,32,flags);
  }
  L004e7af5: { // 0x4e7af5: 740b JZ 0x004e7b02
    if(integer::condition("JZ",flags)) goto L004e7b02;
  }
  L004e7af7: { // 0x4e7af7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004e7af8: { // 0x4e7af8: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L004e7afb: { // 0x4e7afb: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004e7afd: { // 0x4e7afd: 7cf4 JL 0x004e7af3
    if(integer::condition("JL",flags)) goto L004e7af3;
  }
  L004e7aff: { // 0x4e7aff: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004e7b02: { // 0x4e7b02: 3b442424 CMP EAX,dword ptr [ESP + 0x24]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L004e7b06: { // 0x4e7b06: 7527 JNZ 0x004e7b2f
    if(integer::condition("JNZ",flags)) goto L004e7b2f;
  }
  L004e7b08: { // 0x4e7b08: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L004e7b0c: { // 0x4e7b0c: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L004e7b0f: { // 0x4e7b0f: 7433 JZ 0x004e7b44
    if(integer::condition("JZ",flags)) goto L004e7b44;
  }
  L004e7b11: { // 0x4e7b11: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004e7b13: { // 0x4e7b13: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L004e7b17: { // 0x4e7b17: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e7b18: { // 0x4e7b18: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e7b1a: { // 0x4e7b1a: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),5143325u); flags=s.arithmetic_flags;
  }
  L004e7b1d: { // 0x4e7b1d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e7b1e: { // 0x4e7b1e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004e7b20: { // 0x4e7b20: e83b270000 CALL 0x004ea260
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ea260u,5143333u); flags=s.arithmetic_flags;
  }
  L004e7b25: { // 0x4e7b25: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004e7b27: { // 0x4e7b27: 741b JZ 0x004e7b44
    if(integer::condition("JZ",flags)) goto L004e7b44;
  }
  L004e7b29: { // 0x4e7b29: 8b3d18e0a100 MOV EDI,dword ptr [0x00a1e018]
    s.di = m.r32((0x00a1e018u));
  }
  L004e7b2f: { // 0x4e7b2f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004e7b33: { // 0x4e7b33: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L004e7b34: { // 0x4e7b34: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L004e7b36: { // 0x4e7b36: 7c98 JL 0x004e7ad0
    if(integer::condition("JL",flags)) goto L004e7ad0;
  }
  L004e7b38: { // 0x4e7b38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e7b39: { // 0x4e7b39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e7b3a: { // 0x4e7b3a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e7b3b: { // 0x4e7b3b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e7b3d: { // 0x4e7b3d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e7b3e: { // 0x4e7b3e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e7b41: { // 0x4e7b41: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004e7b44: { // 0x4e7b44: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004e7b46: { // 0x4e7b46: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e7b47: { // 0x4e7b47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e7b48: { // 0x4e7b48: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e7b49: { // 0x4e7b49: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e7b4a: { // 0x4e7b4a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e7b4d: { // 0x4e7b4d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
