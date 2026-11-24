#include "recovered/recovery_b648_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b648 {
namespace {
void f_0018af40(Memory&,State&,Frame&,const Operations&);
void f_001fcbd0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0018af40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058af40: { // 0x58af40: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L0058af43: { // 0x58af43: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0058af45: { // 0x58af45: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058af46: { // 0x58af46: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0058af48: { // 0x58af48: 7e15 JLE 0x58af5f
    if(integer::condition("JLE",flags)) goto L0058af5f;
  }
  L0058af4a: { // 0x58af4a: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L0058af4e: { // 0x58af4e: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L0058af51: { // 0x58af51: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L0058af53: { // 0x58af53: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L0058af55: { // 0x58af55: 740b JZ 0x58af62
    if(integer::condition("JZ",flags)) goto L0058af62;
  }
  L0058af57: { // 0x58af57: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0058af58: { // 0x58af58: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L0058af5b: { // 0x58af5b: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0058af5d: { // 0x58af5d: 7cf4 JL 0x58af53
    if(integer::condition("JL",flags)) goto L0058af53;
  }
  L0058af5f: { // 0x58af5f: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0058af62: { // 0x58af62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058af63: { // 0x58af63: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}


void f_001fcbd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005fcbd0: { // 0x5fcbd0: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L005fcbd3: { // 0x5fcbd3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005fcbd5: { // 0x5fcbd5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005fcbd6: { // 0x5fcbd6: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005fcbd8: { // 0x5fcbd8: 7e15 JLE 0x5fcbef
    if(integer::condition("JLE",flags)) goto L005fcbef;
  }
  L005fcbda: { // 0x5fcbda: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L005fcbde: { // 0x5fcbde: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L005fcbe1: { // 0x5fcbe1: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L005fcbe3: { // 0x5fcbe3: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L005fcbe5: { // 0x5fcbe5: 740b JZ 0x5fcbf2
    if(integer::condition("JZ",flags)) goto L005fcbf2;
  }
  L005fcbe7: { // 0x5fcbe7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005fcbe8: { // 0x5fcbe8: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L005fcbeb: { // 0x5fcbeb: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L005fcbed: { // 0x5fcbed: 7cf4 JL 0x5fcbe3
    if(integer::condition("JL",flags)) goto L005fcbe3;
  }
  L005fcbef: { // 0x5fcbef: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005fcbf2: { // 0x5fcbf2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005fcbf3: { // 0x5fcbf3: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5812032u:f_0018af40(m,s,child,{});break;
case 6278096u:f_001fcbd0(m,s,child,{});break;
default:throw std::domain_error("recovery648 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0056a760(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056a760: { // 0x56a760: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056a761: { // 0x56a761: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056a762: { // 0x56a762: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056a763: { // 0x56a763: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0056a765: { // 0x56a765: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0056a767: { // 0x56a767: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0056a769: { // 0x56a769: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0056a76b: { // 0x56a76b: 7408 JZ 0x0056a775
    if(integer::condition("JZ",flags)) goto L0056a775;
  }
  L0056a76d: { // 0x56a76d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0056a76f: { // 0x56a76f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0056a771: { // 0x56a771: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),5678963u); flags=s.arithmetic_flags;
  }
  L0056a773: { // 0x56a773: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L0056a775: { // 0x56a775: 8b154079a500 MOV EDX,dword ptr [0x00a57940]
    s.dx = m.r32((0x00a57940u));
  }
  L0056a77b: { // 0x56a77b: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L0056a77f: { // 0x56a77f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056a780: { // 0x56a780: b94079a500 MOV ECX,0xa57940
    s.cx = 0x00a57940u;
  }
  L0056a785: { // 0x56a785: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0056a789: { // 0x56a789: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5678988u); flags=s.arithmetic_flags;
  }
  L0056a78c: { // 0x56a78c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0056a78f: { // 0x56a78f: 742d JZ 0x0056a7be
    if(integer::condition("JZ",flags)) goto L0056a7be;
  }
  L0056a791: { // 0x56a791: 8b0d5079a500 MOV ECX,dword ptr [0x00a57950]
    s.cx = m.r32((0x00a57950u));
  }
  L0056a797: { // 0x56a797: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056a799: { // 0x56a799: 7d23 JGE 0x0056a7be
    if(integer::condition("JGE",flags)) goto L0056a7be;
  }
  L0056a79b: { // 0x56a79b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0056a79c: { // 0x56a79c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056a79e: { // 0x56a79e: 890d5079a500 MOV dword ptr [0x00a57950],ECX
    m.w32((0x00a57950u), s.cx);
  }
  L0056a7a4: { // 0x56a7a4: 7d18 JGE 0x0056a7be
    if(integer::condition("JGE",flags)) goto L0056a7be;
  }
  L0056a7a6: { // 0x56a7a6: 8b0d4479a500 MOV ECX,dword ptr [0x00a57944]
    s.cx = m.r32((0x00a57944u));
  }
  L0056a7ac: { // 0x56a7ac: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056a7ad: { // 0x56a7ad: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0056a7b0: { // 0x56a7b0: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0056a7b4: { // 0x56a7b4: 8b0d5079a500 MOV ECX,dword ptr [0x00a57950]
    s.cx = m.r32((0x00a57950u));
  }
  L0056a7ba: { // 0x56a7ba: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056a7bc: { // 0x56a7bc: 7ce8 JL 0x0056a7a6
    if(integer::condition("JL",flags)) goto L0056a7a6;
  }
  L0056a7be: { // 0x56a7be: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L0056a7c1: { // 0x56a7c1: c74628e0757800 MOV dword ptr [ESI + 0x28],0x7875e0
    m.w32((s.si+0x00000028u), 0x007875e0u);
  }
  L0056a7c8: { // 0x56a7c8: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0056a7ca: { // 0x56a7ca: 7411 JZ 0x0056a7dd
    if(integer::condition("JZ",flags)) goto L0056a7dd;
  }
  L0056a7cc: { // 0x56a7cc: 385e35 CMP byte ptr [ESI + 0x35],BL
    (void)integer::sub(m.r8((s.si+0x00000035u)),(s.bx & 0xffu),8,flags);
  }
  L0056a7cf: { // 0x56a7cf: 740c JZ 0x0056a7dd
    if(integer::condition("JZ",flags)) goto L0056a7dd;
  }
  L0056a7d1: { // 0x56a7d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056a7d2: { // 0x56a7d2: e8a42e2000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5679063u); flags=s.arithmetic_flags;
  }
  L0056a7d7: { // 0x56a7d7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0056a7da: { // 0x56a7da: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L0056a7dd: { // 0x56a7dd: 885e35 MOV byte ptr [ESI + 0x35],BL
    m.w8((s.si+0x00000035u), (s.bx & 0xffu));
  }
  L0056a7e0: { // 0x56a7e0: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  L0056a7e3: { // 0x56a7e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056a7e4: { // 0x56a7e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056a7e5: { // 0x56a7e5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0056a7e6: { // 0x56a7e6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0058a870(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058a870: { // 0x58a870: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0058a871: { // 0x58a871: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058a872: { // 0x58a872: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058a874: { // 0x58a874: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0058a876: { // 0x58a876: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0058a878: { // 0x58a878: 740c JZ 0x0058a886
    if(integer::condition("JZ",flags)) goto L0058a886;
  }
  L0058a87a: { // 0x58a87a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0058a87c: { // 0x58a87c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0058a87e: { // 0x58a87e: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),5810304u); flags=s.arithmetic_flags;
  }
  L0058a880: { // 0x58a880: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L0058a886: { // 0x58a886: 8b154079a500 MOV EDX,dword ptr [0x00a57940]
    s.dx = m.r32((0x00a57940u));
  }
  L0058a88c: { // 0x58a88c: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L0058a890: { // 0x58a890: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0058a891: { // 0x58a891: b94079a500 MOV ECX,0xa57940
    s.cx = 0x00a57940u;
  }
  L0058a896: { // 0x58a896: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0058a89a: { // 0x58a89a: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5810333u); flags=s.arithmetic_flags;
  }
  L0058a89d: { // 0x58a89d: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0058a8a0: { // 0x58a8a0: 742d JZ 0x0058a8cf
    if(integer::condition("JZ",flags)) goto L0058a8cf;
  }
  L0058a8a2: { // 0x58a8a2: 8b0d5079a500 MOV ECX,dword ptr [0x00a57950]
    s.cx = m.r32((0x00a57950u));
  }
  L0058a8a8: { // 0x58a8a8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0058a8aa: { // 0x58a8aa: 7d23 JGE 0x0058a8cf
    if(integer::condition("JGE",flags)) goto L0058a8cf;
  }
  L0058a8ac: { // 0x58a8ac: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0058a8ad: { // 0x58a8ad: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0058a8af: { // 0x58a8af: 890d5079a500 MOV dword ptr [0x00a57950],ECX
    m.w32((0x00a57950u), s.cx);
  }
  L0058a8b5: { // 0x58a8b5: 7d18 JGE 0x0058a8cf
    if(integer::condition("JGE",flags)) goto L0058a8cf;
  }
  L0058a8b7: { // 0x58a8b7: 8b0d4479a500 MOV ECX,dword ptr [0x00a57944]
    s.cx = m.r32((0x00a57944u));
  }
  L0058a8bd: { // 0x58a8bd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0058a8be: { // 0x58a8be: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0058a8c1: { // 0x58a8c1: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0058a8c5: { // 0x58a8c5: 8b0d5079a500 MOV ECX,dword ptr [0x00a57950]
    s.cx = m.r32((0x00a57950u));
  }
  L0058a8cb: { // 0x58a8cb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0058a8cd: { // 0x58a8cd: 7ce8 JL 0x0058a8b7
    if(integer::condition("JL",flags)) goto L0058a8b7;
  }
  L0058a8cf: { // 0x58a8cf: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L0058a8d2: { // 0x58a8d2: c74628e0757800 MOV dword ptr [ESI + 0x28],0x7875e0
    m.w32((s.si+0x00000028u), 0x007875e0u);
  }
  L0058a8d9: { // 0x58a8d9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058a8db: { // 0x58a8db: 7417 JZ 0x0058a8f4
    if(integer::condition("JZ",flags)) goto L0058a8f4;
  }
  L0058a8dd: { // 0x58a8dd: 8a4e35 MOV CL,byte ptr [ESI + 0x35]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000035u)));
  }
  L0058a8e0: { // 0x58a8e0: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0058a8e2: { // 0x58a8e2: 7410 JZ 0x0058a8f4
    if(integer::condition("JZ",flags)) goto L0058a8f4;
  }
  L0058a8e4: { // 0x58a8e4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0058a8e5: { // 0x58a8e5: e8912d1e00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5810410u); flags=s.arithmetic_flags;
  }
  L0058a8ea: { // 0x58a8ea: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0058a8ed: { // 0x58a8ed: c7462c00000000 MOV dword ptr [ESI + 0x2c],0x0
    m.w32((s.si+0x0000002cu), 0x00000000u);
  }
  L0058a8f4: { // 0x58a8f4: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  L0058a8f8: { // 0x58a8f8: c6463500 MOV byte ptr [ESI + 0x35],0x0
    m.w8((s.si+0x00000035u), 0x00000000u);
  }
  L0058a8fc: { // 0x58a8fc: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0058a8fe: { // 0x58a8fe: c7463000000000 MOV dword ptr [ESI + 0x30],0x0
    m.w32((s.si+0x00000030u), 0x00000000u);
  }
  L0058a905: { // 0x58a905: 7409 JZ 0x0058a910
    if(integer::condition("JZ",flags)) goto L0058a910;
  }
  L0058a907: { // 0x58a907: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058a908: { // 0x58a908: e86e2d1e00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5810445u); flags=s.arithmetic_flags;
  }
  L0058a90d: { // 0x58a90d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0058a910: { // 0x58a910: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0058a912: { // 0x58a912: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058a913: { // 0x58a913: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0058a914: { // 0x58a914: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0065ab60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065ab60: { // 0x65ab60: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065ab61: { // 0x65ab61: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0065ab62: { // 0x65ab62: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0065ab64: { // 0x65ab64: 8b8604030000 MOV EAX,dword ptr [ESI + 0x304]
    s.ax = m.r32((s.si+0x00000304u));
  }
  L0065ab6a: { // 0x65ab6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0065ab6c: { // 0x65ab6c: 7409 JZ 0x0065ab77
    if(integer::condition("JZ",flags)) goto L0065ab77;
  }
  L0065ab6e: { // 0x65ab6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065ab6f: { // 0x65ab6f: e8b4331100 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,6663028u); flags=s.arithmetic_flags;
  }
  L0065ab74: { // 0x65ab74: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0065ab77: { // 0x65ab77: 8b8e0c030000 MOV ECX,dword ptr [ESI + 0x30c]
    s.cx = m.r32((s.si+0x0000030cu));
  }
  L0065ab7d: { // 0x65ab7d: c7860403000000000000 MOV dword ptr [ESI + 0x304],0x0
    m.w32((s.si+0x00000304u), 0x00000000u);
  }
  L0065ab87: { // 0x65ab87: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0065ab89: { // 0x65ab89: 7406 JZ 0x0065ab91
    if(integer::condition("JZ",flags)) goto L0065ab91;
  }
  L0065ab8b: { // 0x65ab8b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0065ab8d: { // 0x65ab8d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0065ab8f: { // 0x65ab8f: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),6663057u); flags=s.arithmetic_flags;
  }
  L0065ab91: { // 0x65ab91: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L0065ab95: { // 0x65ab95: c7860c03000000000000 MOV dword ptr [ESI + 0x30c],0x0
    m.w32((s.si+0x0000030cu), 0x00000000u);
  }
  L0065ab9f: { // 0x65ab9f: 8b1500eaa900 MOV EDX,dword ptr [0x00a9ea00]
    s.dx = m.r32((0x00a9ea00u));
  }
  L0065aba5: { // 0x65aba5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065aba6: { // 0x65aba6: b900eaa900 MOV ECX,0xa9ea00
    s.cx = 0x00a9ea00u;
  }
  L0065abab: { // 0x65abab: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0065abaf: { // 0x65abaf: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6663090u); flags=s.arithmetic_flags;
  }
  L0065abb2: { // 0x65abb2: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0065abb5: { // 0x65abb5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065abb6: { // 0x65abb6: 742d JZ 0x0065abe5
    if(integer::condition("JZ",flags)) goto L0065abe5;
  }
  L0065abb8: { // 0x65abb8: 8b0d10eaa900 MOV ECX,dword ptr [0x00a9ea10]
    s.cx = m.r32((0x00a9ea10u));
  }
  L0065abbe: { // 0x65abbe: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0065abc0: { // 0x65abc0: 7d23 JGE 0x0065abe5
    if(integer::condition("JGE",flags)) goto L0065abe5;
  }
  L0065abc2: { // 0x65abc2: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0065abc3: { // 0x65abc3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0065abc5: { // 0x65abc5: 890d10eaa900 MOV dword ptr [0x00a9ea10],ECX
    m.w32((0x00a9ea10u), s.cx);
  }
  L0065abcb: { // 0x65abcb: 7d18 JGE 0x0065abe5
    if(integer::condition("JGE",flags)) goto L0065abe5;
  }
  L0065abcd: { // 0x65abcd: 8b0d04eaa900 MOV ECX,dword ptr [0x00a9ea04]
    s.cx = m.r32((0x00a9ea04u));
  }
  L0065abd3: { // 0x65abd3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0065abd4: { // 0x65abd4: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0065abd7: { // 0x65abd7: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0065abdb: { // 0x65abdb: 8b0d10eaa900 MOV ECX,dword ptr [0x00a9ea10]
    s.cx = m.r32((0x00a9ea10u));
  }
  L0065abe1: { // 0x65abe1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0065abe3: { // 0x65abe3: 7ce8 JL 0x0065abcd
    if(integer::condition("JL",flags)) goto L0065abcd;
  }
  L0065abe5: { // 0x65abe5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0065abe6: { // 0x65abe6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
