#include "recovered/recovery_b225_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b225 {
namespace {
void f_002c9e00(Memory&,State&,Frame&,const Operations&);
void f_0000ffc0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002c9e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c9e00: { // 0x6c9e00: 8b9130010000 MOV EDX,dword ptr [ECX + 0x130]
    s.dx = m.r32((s.cx+0x00000130u));
  }
  L006c9e06: { // 0x6c9e06: 8b8138010000 MOV EAX,dword ptr [ECX + 0x138]
    s.ax = m.r32((s.cx+0x00000138u));
  }
  L006c9e0c: { // 0x6c9e0c: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006c9e0f: { // 0x6c9e0f: 741a JZ 0x006c9e2b
    if(integer::condition("JZ",flags)) goto L006c9e2b;
  }
  L006c9e11: { // 0x6c9e11: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006c9e17: { // 0x6c9e17: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006c9e19: { // 0x6c9e19: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006c9e1b: { // 0x6c9e1b: 7d0c JGE 0x006c9e29
    if(integer::condition("JGE",flags)) goto L006c9e29;
  }
  L006c9e1d: { // 0x6c9e1d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006c9e1f: { // 0x6c9e1f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006c9e21: { // 0x6c9e21: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9e23: { // 0x6c9e23: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006c9e26: { // 0x6c9e26: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L006c9e28: { // 0x6c9e28: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c9e29: { // 0x6c9e29: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c9e2b: { // 0x6c9e2b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006c9e2d: { // 0x6c9e2d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9e2f: { // 0x6c9e2f: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006c9e32: { // 0x6c9e32: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L006c9e34: { // 0x6c9e34: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ffc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffc0: { // 0x40ffc0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0040ffc4: { // 0x40ffc4: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0040ffc7: { // 0x40ffc7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7118336u:f_002c9e00(m,s,child,{});break;
case 4259776u:f_0000ffc0(m,s,child,{});break;
default:throw std::domain_error("recovery225 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00507770(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00507770: { // 0x507770: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00507771: { // 0x507771: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00507773: { // 0x507773: e888261c00 CALL 0x006c9e00
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c9e00u,5273464u); flags=s.arithmetic_flags;
  }
  L00507778: { // 0x507778: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050777a: { // 0x50777a: 7502 JNZ 0x0050777e
    if(integer::condition("JNZ",flags)) goto L0050777e;
  }
  L0050777c: { // 0x50777c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050777d: { // 0x50777d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0050777e: { // 0x50777e: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00507784: { // 0x507784: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00507786: { // 0x507786: 750a JNZ 0x00507792
    if(integer::condition("JNZ",flags)) goto L00507792;
  }
  L00507788: { // 0x507788: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L0050778d: { // 0x50778d: e8de9a2700 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5273490u); flags=s.arithmetic_flags;
  }
  L00507792: { // 0x507792: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00507798: { // 0x507798: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00507799: { // 0x507799: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0050779b: { // 0x50779b: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),5273502u); flags=s.arithmetic_flags;
  }
  L0050779e: { // 0x50779e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005077a0: { // 0x5077a0: 7404 JZ 0x005077a6
    if(integer::condition("JZ",flags)) goto L005077a6;
  }
  L005077a2: { // 0x5077a2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005077a4: { // 0x5077a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005077a5: { // 0x5077a5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005077a6: { // 0x5077a6: 8a86c3050000 MOV AL,byte ptr [ESI + 0x5c3]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005c3u)));
  }
  L005077ac: { // 0x5077ac: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005077ae: { // 0x5077ae: 7404 JZ 0x005077b4
    if(integer::condition("JZ",flags)) goto L005077b4;
  }
  L005077b0: { // 0x5077b0: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005077b2: { // 0x5077b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005077b3: { // 0x5077b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005077b4: { // 0x5077b4: 8a867d050000 MOV AL,byte ptr [ESI + 0x57d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000057du)));
  }
  L005077ba: { // 0x5077ba: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005077bc: { // 0x5077bc: 7404 JZ 0x005077c2
    if(integer::condition("JZ",flags)) goto L005077c2;
  }
  L005077be: { // 0x5077be: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005077c0: { // 0x5077c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005077c1: { // 0x5077c1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005077c2: { // 0x5077c2: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L005077c8: { // 0x5077c8: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  L005077cb: { // 0x5077cb: 740f JZ 0x005077dc
    if(integer::condition("JZ",flags)) goto L005077dc;
  }
  L005077cd: { // 0x5077cd: 83f81c CMP EAX,0x1c
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  L005077d0: { // 0x5077d0: 740a JZ 0x005077dc
    if(integer::condition("JZ",flags)) goto L005077dc;
  }
  L005077d2: { // 0x5077d2: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L005077d5: { // 0x5077d5: 7405 JZ 0x005077dc
    if(integer::condition("JZ",flags)) goto L005077dc;
  }
  L005077d7: { // 0x5077d7: 83f81e CMP EAX,0x1e
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  L005077da: { // 0x5077da: 7504 JNZ 0x005077e0
    if(integer::condition("JNZ",flags)) goto L005077e0;
  }
  L005077dc: { // 0x5077dc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005077de: { // 0x5077de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005077df: { // 0x5077df: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005077e0: { // 0x5077e0: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005077e3: { // 0x5077e3: 740d JZ 0x005077f2
    if(integer::condition("JZ",flags)) goto L005077f2;
  }
  L005077e5: { // 0x5077e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005077e7: { // 0x5077e7: 7409 JZ 0x005077f2
    if(integer::condition("JZ",flags)) goto L005077f2;
  }
  L005077e9: { // 0x5077e9: 83f810 CMP EAX,0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L005077ec: { // 0x5077ec: 7404 JZ 0x005077f2
    if(integer::condition("JZ",flags)) goto L005077f2;
  }
  L005077ee: { // 0x5077ee: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005077f0: { // 0x5077f0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005077f1: { // 0x5077f1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005077f2: { // 0x5077f2: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005077f4: { // 0x5077f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005077f5: { // 0x5077f5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
