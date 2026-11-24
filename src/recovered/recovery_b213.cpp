#include "recovered/recovery_b213_machine.hpp"
#include "platform/audio_critical213.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b213 {
namespace {
void f_000026f0(Memory&,State&,Frame&,const Operations&);
void f_0000a6a0(Memory&,State&,Frame&,const Operations&);
void f_0000a6b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000026f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004026f0: { // 0x4026f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004026f1: { // 0x4026f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004026f3: { // 0x4026f3: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L004026f9: { // 0x4026f9: ff5028 CALL dword ptr [EAX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000028u)),4204284u); flags=s.arithmetic_flags;
  }
  L004026fc: { // 0x4026fc: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  L00402702: { // 0x402702: 83e1ef AND ECX,0xffffffef
    s.cx = integer::logical((s.cx)&(0xffffffefu),32,flags);
  }
  L00402705: { // 0x402705: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  L0040270b: { // 0x40270b: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  L00402711: { // 0x402711: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00402713: { // 0x402713: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00402714: { // Original tail JMP: preserve this call frame.
    if(m.r32(s.dx+0x2cu)!=0x40a6b0u)throw std::domain_error("213 foreign audio tailtarget");
    s.arithmetic_flags=flags;f_0000a6b0(m,s,f,op);return;
  }
}
void f_0000a6a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040a6a0: { // 0x40a6a0: 68d0988100 PUSH 0x8198d0
    f.push(m,0x008198d0u);
  }
  L0040a6a5: { // 0x40a6a5: ff15dc517800 CALL dword ptr [0x7851dc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007851dcu)),4236971u); flags=s.arithmetic_flags;
  }
  L0040a6ab: { // 0x40a6ab: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040a6ad: { // 0x40a6ad: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000a6b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040a6b0: { // 0x40a6b0: 68d0988100 PUSH 0x8198d0
    f.push(m,0x008198d0u);
  }
  L0040a6b5: { // 0x40a6b5: ff15e0517800 CALL dword ptr [0x7851e0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007851e0u)),4236987u); flags=s.arithmetic_flags;
  }
  L0040a6bb: { // 0x40a6bb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040a6bd: { // 0x40a6bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 if(target==m.r32(0x7851dcu)||target==m.r32(0x7851e0u)){
  const auto guest=reinterpret_cast<LPCRITICAL_SECTION>(std::uintptr_t(m.r32(f.sp)));
  if(target==m.r32(0x7851dcu))ra2::platform::audio213::Lock::enter(guest);else ra2::platform::audio213::Lock::leave(guest);
  f.sp+=4;return; // Real stdcall consumes the sole argument; wrapper then XORs EAX.
 }
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4204272u:f_000026f0(m,s,child,{});break;
case 4236960u:f_0000a6a0(m,s,child,{});break;
case 4236976u:f_0000a6b0(m,s,child,{});break;
default:throw std::domain_error("recovery213 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00404120(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00404120: { // 0x404120: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00404121: { // 0x404121: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00404123: { // 0x404123: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00404124: { // 0x404124: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00404126: { // 0x404126: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L0040412c: { // 0x40412c: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0040412e: { // 0x40412e: 7478 JZ 0x004041a8
    if(integer::condition("JZ",flags)) goto L004041a8;
  }
  L00404130: { // 0x404130: 3bb1c0000000 CMP ESI,dword ptr [ECX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.cx+0x000000c0u)),32,flags);
  }
  L00404136: { // 0x404136: 7570 JNZ 0x004041a8
    if(integer::condition("JNZ",flags)) goto L004041a8;
  }
  L00404138: { // 0x404138: f6461802 TEST byte ptr [ESI + 0x18],0x2
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000002u),8,flags);
  }
  L0040413c: { // 0x40413c: 7405 JZ 0x00404143
    if(integer::condition("JZ",flags)) goto L00404143;
  }
  L0040413e: { // 0x40413e: e86de4ffff CALL 0x004025b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004025b0u,4211011u); flags=s.arithmetic_flags;
  }
  L00404143: { // 0x404143: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00404149: { // 0x404149: e8a2e5ffff CALL 0x004026f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026f0u,4211022u); flags=s.arithmetic_flags;
  }
  L0040414e: { // 0x40414e: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00404154: { // 0x404154: 89b8c0000000 MOV dword ptr [EAX + 0xc0],EDI
    m.w32((s.ax+0x000000c0u), s.di);
  }
  L0040415a: { // 0x40415a: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00404160: { // 0x404160: 89b9bc000000 MOV dword ptr [ECX + 0xbc],EDI
    m.w32((s.cx+0x000000bcu), s.di);
  }
  L00404166: { // 0x404166: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L0040416c: { // 0x40416c: 89bab4000000 MOV dword ptr [EDX + 0xb4],EDI
    m.w32((s.dx+0x000000b4u), s.di);
  }
  L00404172: { // 0x404172: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00404178: { // 0x404178: 89b8b8000000 MOV dword ptr [EAX + 0xb8],EDI
    m.w32((s.ax+0x000000b8u), s.di);
  }
  L0040417e: { // 0x40417e: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00404184: { // 0x404184: 89b990000000 MOV dword ptr [ECX + 0x90],EDI
    m.w32((s.cx+0x00000090u), s.di);
  }
  L0040418a: { // 0x40418a: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00404190: { // 0x404190: 89ba98000000 MOV dword ptr [EDX + 0x98],EDI
    m.w32((s.dx+0x00000098u), s.di);
  }
  L00404196: { // 0x404196: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L0040419c: { // 0x40419c: 89b89c000000 MOV dword ptr [EAX + 0x9c],EDI
    m.w32((s.ax+0x0000009cu), s.di);
  }
  L004041a2: { // 0x4041a2: 89beb0000000 MOV dword ptr [ESI + 0xb0],EDI
    m.w32((s.si+0x000000b0u), s.di);
  }
  L004041a8: { // 0x4041a8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004041a9: { // 0x4041a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004041aa: { // 0x4041aa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
