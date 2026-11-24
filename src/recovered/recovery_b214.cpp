#include "recovered/recovery_b214_machine.hpp"
#include "platform/audio_critical213.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b214 {
namespace {
void f_000035f0(Memory&,State&,Frame&,const Operations&);
void f_000072f0(Memory&,State&,Frame&,const Operations&);
void f_00007310(Memory&,State&,Frame&,const Operations&);
void f_000025b0(Memory&,State&,Frame&,const Operations&);
void f_0000a6a0(Memory&,State&,Frame&,const Operations&);
void f_0000a6b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000035f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004035f0: { // 0x4035f0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004035f3: { // 0x4035f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004035f4: { // 0x4035f4: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L004035f6: { // 0x4035f6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004035f7: { // 0x4035f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004035f8: { // 0x4035f8: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L004035fb: { // 0x4035fb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004035fc: { // 0x4035fc: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00403600: { // 0x403600: 7509 JNZ 0x0040360b
    if(integer::condition("JNZ",flags)) goto L0040360b;
  }
  L00403602: { // 0x403602: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L00403607: { // 0x403607: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0040360b: { // 0x40360b: bf7f000000 MOV EDI,0x7f
    s.di = 0x0000007fu;
  }
  L00403610: { // 0x403610: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00403612: { // 0x403612: 81c1f8000000 ADD ECX,0xf8
    s.cx = integer::add(s.cx,0x000000f8u,32,flags);
  }
  L00403618: { // 0x403618: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0040361c: { // 0x40361c: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00403620: { // 0x403620: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L00403623: { // 0x403623: e8c83c0000 CALL 0x004072f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004072f0u,4208168u); flags=s.arithmetic_flags;
  }
  L00403628: { // 0x403628: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0040362a: { // 0x40362a: 7476 JZ 0x004036a2
    if(integer::condition("JZ",flags)) goto L004036a2;
  }
  L0040362c: { // 0x40362c: eb04 JMP 0x00403632
    goto L00403632;
  }
  L0040362e: { // 0x40362e: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00403632: { // 0x403632: 39580c CMP dword ptr [EAX + 0xc],EBX
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),s.bx,32,flags);
  }
  L00403635: { // 0x403635: 7556 JNZ 0x0040368d
    if(integer::condition("JNZ",flags)) goto L0040368d;
  }
  L00403637: { // 0x403637: f680a400000015 TEST byte ptr [EAX + 0xa4],0x15
    (void)integer::logical((m.r8((s.ax+0x000000a4u)))&(0x00000015u),8,flags);
  }
  L0040363e: { // 0x40363e: 745e JZ 0x0040369e
    if(integer::condition("JZ",flags)) goto L0040369e;
  }
  L00403640: { // 0x403640: f680a400000001 TEST byte ptr [EAX + 0xa4],0x1
    (void)integer::logical((m.r8((s.ax+0x000000a4u)))&(0x00000001u),8,flags);
  }
  L00403647: { // 0x403647: 8b88a0000000 MOV ECX,dword ptr [EAX + 0xa0]
    s.cx = m.r32((s.ax+0x000000a0u));
  }
  L0040364d: { // 0x40364d: 7430 JZ 0x0040367f
    if(integer::condition("JZ",flags)) goto L0040367f;
  }
  L0040364f: { // 0x40364f: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00403651: { // 0x403651: 7d0c JGE 0x0040365f
    if(integer::condition("JGE",flags)) goto L0040365f;
  }
  L00403653: { // 0x403653: 8bb0dc000000 MOV ESI,dword ptr [EAX + 0xdc]
    s.si = m.r32((s.ax+0x000000dcu));
  }
  L00403659: { // 0x403659: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0040365b: { // 0x40365b: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0040365d: { // 0x40365d: eb2e JMP 0x0040368d
    goto L0040368d;
  }
  L0040365f: { // 0x40365f: 752c JNZ 0x0040368d
    if(integer::condition("JNZ",flags)) goto L0040368d;
  }
  L00403661: { // 0x403661: 8b90dc000000 MOV EDX,dword ptr [EAX + 0xdc]
    s.dx = m.r32((s.ax+0x000000dcu));
  }
  L00403667: { // 0x403667: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00403669: { // 0x403669: 7322 JNC 0x0040368d
    if(integer::condition("JNC",flags)) goto L0040368d;
  }
  L0040366b: { // 0x40366b: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0040366d: { // 0x40366d: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0040366f: { // 0x40366f: 81fb66060000 CMP EBX,0x666
    (void)integer::sub(s.bx,0x00000666u,32,flags);
  }
  L00403675: { // 0x403675: 7216 JC 0x0040368d
    if(integer::condition("JC",flags)) goto L0040368d;
  }
  L00403677: { // 0x403677: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00403679: { // 0x403679: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0040367b: { // 0x40367b: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0040367d: { // 0x40367d: eb0e JMP 0x0040368d
    goto L0040368d;
  }
  L0040367f: { // 0x40367f: 3b4c2410 CMP ECX,dword ptr [ESP + 0x10]
    (void)integer::sub(s.cx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L00403683: { // 0x403683: 7d08 JGE 0x0040368d
    if(integer::condition("JGE",flags)) goto L0040368d;
  }
  L00403685: { // 0x403685: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00403689: { // 0x403689: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0040368d: { // 0x40368d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0040368f: { // 0x40368f: 7411 JZ 0x004036a2
    if(integer::condition("JZ",flags)) goto L004036a2;
  }
  L00403691: { // 0x403691: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00403693: { // 0x403693: e8783c0000 CALL 0x00407310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407310u,4208280u); flags=s.arithmetic_flags;
  }
  L00403698: { // 0x403698: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0040369a: { // 0x40369a: 7592 JNZ 0x0040362e
    if(integer::condition("JNZ",flags)) goto L0040362e;
  }
  L0040369c: { // 0x40369c: eb04 JMP 0x004036a2
    goto L004036a2;
  }
  L0040369e: { // 0x40369e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004036a0: { // 0x4036a0: 7510 JNZ 0x004036b2
    if(integer::condition("JNZ",flags)) goto L004036b2;
  }
  L004036a2: { // 0x4036a2: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004036a6: { // 0x4036a6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004036a8: { // 0x4036a8: 7406 JZ 0x004036b0
    if(integer::condition("JZ",flags)) goto L004036b0;
  }
  L004036aa: { // 0x4036aa: 397c2410 CMP dword ptr [ESP + 0x10],EDI
    (void)integer::sub(m.r32((f.sp+0x00000010u)),s.di,32,flags);
  }
  L004036ae: { // 0x4036ae: 7e02 JLE 0x004036b2
    if(integer::condition("JLE",flags)) goto L004036b2;
  }
  L004036b0: { // 0x4036b0: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004036b2: { // 0x4036b2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004036b3: { // 0x4036b3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004036b4: { // 0x4036b4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004036b5: { // 0x4036b5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004036b6: { // 0x4036b6: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004036b9: { // 0x4036b9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000072f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004072f0: { // 0x4072f0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004072f2: { // 0x4072f2: 740b JZ 0x004072ff
    if(integer::condition("JZ",flags)) goto L004072ff;
  }
  L004072f4: { // 0x4072f4: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004072f6: { // 0x4072f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004072f8: { // 0x4072f8: 7407 JZ 0x00407301
    if(integer::condition("JZ",flags)) goto L00407301;
  }
  L004072fa: { // 0x4072fa: 3b4008 CMP EAX,dword ptr [EAX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.ax+0x00000008u)),32,flags);
  }
  L004072fd: { // 0x4072fd: 7502 JNZ 0x00407301
    if(integer::condition("JNZ",flags)) goto L00407301;
  }
  L004072ff: { // 0x4072ff: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00407301: { // 0x407301: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00007310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00407310: { // 0x407310: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00407312: { // 0x407312: 740b JZ 0x0040731f
    if(integer::condition("JZ",flags)) goto L0040731f;
  }
  L00407314: { // 0x407314: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00407316: { // 0x407316: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00407318: { // 0x407318: 7407 JZ 0x00407321
    if(integer::condition("JZ",flags)) goto L00407321;
  }
  L0040731a: { // 0x40731a: 3b4008 CMP EAX,dword ptr [EAX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.ax+0x00000008u)),32,flags);
  }
  L0040731d: { // 0x40731d: 7502 JNZ 0x00407321
    if(integer::condition("JNZ",flags)) goto L00407321;
  }
  L0040731f: { // 0x40731f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00407321: { // 0x407321: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000025b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004025b0: { // 0x4025b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004025b1: { // 0x4025b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004025b3: { // 0x4025b3: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L004025b9: { // 0x4025b9: ff5028 CALL dword ptr [EAX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000028u)),4203964u); flags=s.arithmetic_flags;
  }
  L004025bc: { // 0x4025bc: f686a400000005 TEST byte ptr [ESI + 0xa4],0x5
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000005u),8,flags);
  }
  L004025c3: { // 0x4025c3: 740b JZ 0x004025d0
    if(integer::condition("JZ",flags)) goto L004025d0;
  }
  L004025c5: { // 0x4025c5: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  L004025cb: { // 0x4025cb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004025cd: { // 0x4025cd: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),4203984u); flags=s.arithmetic_flags;
  }
  L004025d0: { // 0x4025d0: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L004025d6: { // 0x4025d6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004025d8: { // 0x4025d8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4203995u); flags=s.arithmetic_flags;
  }
  L004025db: { // 0x4025db: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  L004025e1: { // 0x4025e1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004025e3: { // 0x4025e3: 7404 JZ 0x004025e9
    if(integer::condition("JZ",flags)) goto L004025e9;
  }
  L004025e5: { // 0x4025e5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004025e7: { // 0x4025e7: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,4204009u); flags=s.arithmetic_flags;
  }
  L004025e9: { // 0x4025e9: c7866801000000000000 MOV dword ptr [ESI + 0x168],0x0
    m.w32((s.si+0x00000168u), 0x00000000u);
  }
  L004025f3: { // 0x4025f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004025f4: { // 0x4025f4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
  f.sp+=4;return;
 }
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4208112u:f_000035f0(m,s,child,{});break;
case 4223728u:f_000072f0(m,s,child,{});break;
case 4223760u:f_00007310(m,s,child,{});break;
case 4203952u:f_000025b0(m,s,child,{});break;
case 4236960u:f_0000a6a0(m,s,child,{});break;
case 4236976u:f_0000a6b0(m,s,child,{});break;
default:throw std::domain_error("recovery214 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00405b60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405b60: { // 0x405b60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00405b61: { // 0x405b61: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00405b62: { // 0x405b62: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00405b63: { // 0x405b63: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00405b65: { // 0x405b65: 8b0df4928100 MOV ECX,dword ptr [0x008192f4]
    s.cx = m.r32((0x008192f4u));
  }
  L00405b6b: { // 0x405b6b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00405b6d: { // 0x405b6d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00405b6f: { // 0x405b6f: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00405b71: { // 0x405b71: 746a JZ 0x00405bdd
    if(integer::condition("JZ",flags)) goto L00405bdd;
  }
  L00405b73: { // 0x405b73: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00405b78: { // 0x405b78: e873daffff CALL 0x004035f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004035f0u,4217725u); flags=s.arithmetic_flags;
  }
  L00405b7d: { // 0x405b7d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00405b7f: { // 0x405b7f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00405b81: { // 0x405b81: 745a JZ 0x00405bdd
    if(integer::condition("JZ",flags)) goto L00405bdd;
  }
  L00405b83: { // 0x405b83: f686a400000015 TEST byte ptr [ESI + 0xa4],0x15
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000015u),8,flags);
  }
  L00405b8a: { // 0x405b8a: 740e JZ 0x00405b9a
    if(integer::condition("JZ",flags)) goto L00405b9a;
  }
  L00405b8c: { // 0x405b8c: 39bea0000000 CMP dword ptr [ESI + 0xa0],EDI
    (void)integer::sub(m.r32((s.si+0x000000a0u)),s.di,32,flags);
  }
  L00405b92: { // 0x405b92: 7e06 JLE 0x00405b9a
    if(integer::condition("JLE",flags)) goto L00405b9a;
  }
  L00405b94: { // 0x405b94: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00405b95: { // 0x405b95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00405b96: { // 0x405b96: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00405b98: { // 0x405b98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00405b99: { // 0x405b99: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00405b9a: { // 0x405b9a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00405b9c: { // 0x405b9c: e80fcaffff CALL 0x004025b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004025b0u,4217761u); flags=s.arithmetic_flags;
  }
  L00405ba1: { // 0x405ba1: a198978100 MOV EAX,[0x00819798]
    s.ax = m.r32((0x00819798u));
  }
  L00405ba6: { // 0x405ba6: 898694000000 MOV dword ptr [ESI + 0x94],EAX
    m.w32((s.si+0x00000094u), s.ax);
  }
  L00405bac: { // 0x405bac: 8b0da8978100 MOV ECX,dword ptr [0x008197a8]
    s.cx = m.r32((0x008197a8u));
  }
  L00405bb2: { // 0x405bb2: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L00405bb5: { // 0x405bb5: 898e9c000000 MOV dword ptr [ESI + 0x9c],ECX
    m.w32((s.si+0x0000009cu), s.cx);
  }
  L00405bbb: { // 0x405bbb: 89bea0000000 MOV dword ptr [ESI + 0xa0],EDI
    m.w32((s.si+0x000000a0u), s.di);
  }
  L00405bc1: { // 0x405bc1: 7410 JZ 0x00405bd3
    if(integer::condition("JZ",flags)) goto L00405bd3;
  }
  L00405bc3: { // 0x405bc3: c786a8000000ffffffff MOV dword ptr [ESI + 0xa8],0xffffffff
    m.w32((s.si+0x000000a8u), 0xffffffffu);
  }
  L00405bcd: { // 0x405bcd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00405bcf: { // 0x405bcf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00405bd0: { // 0x405bd0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00405bd1: { // 0x405bd1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00405bd2: { // 0x405bd2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00405bd3: { // 0x405bd3: c786a800000000000000 MOV dword ptr [ESI + 0xa8],0x0
    m.w32((s.si+0x000000a8u), 0x00000000u);
  }
  L00405bdd: { // 0x405bdd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00405bdf: { // 0x405bdf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00405be0: { // 0x405be0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00405be1: { // 0x405be1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00405be2: { // 0x405be2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
