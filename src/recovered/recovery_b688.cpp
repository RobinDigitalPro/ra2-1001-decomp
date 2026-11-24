#include "recovered/recovery_b688_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b688 {
namespace {
void f_00108c50(Memory&,State&,Frame&,const Operations&);
void f_00191570(Memory&,State&,Frame&,const Operations&);
void f_00191ab0(Memory&,State&,Frame&,const Operations&);
void f_002a9420(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00108c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00508c50: { // 0x508c50: b80f000000 MOV EAX, 0xf
    s.ax = 0x0000000fu;
  }
  L00508c55: { // 0x508c55: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591570: { // 0x591570: 8b8198000000 MOV EAX, dword ptr [ECX + 0x98]
    s.ax = m.r32((s.cx+0x00000098u));
  }
  L00591576: { // 0x591576: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00591579: { // 0x591579: 7506 JNZ 0x591581
    if(integer::condition("JNZ",flags)) goto L00591581;
  }
  L0059157b: { // 0x59157b: 8b81a0000000 MOV EAX, dword ptr [ECX + 0xa0]
    s.ax = m.r32((s.cx+0x000000a0u));
  }
  L00591581: { // 0x591581: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591ab0: { // 0x591ab0: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00591ab4: { // 0x591ab4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00591ab5: { // 0x591ab5: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00591ab7: { // 0x591ab7: 8b8e98000000 MOV ECX, dword ptr [ESI + 0x98]
    s.cx = m.r32((s.si+0x00000098u));
  }
  L00591abd: { // 0x591abd: 83f91c CMP ECX, 0x1c
    (void)integer::sub(s.cx,0x0000001cu,32,flags);
  }
  L00591ac0: { // 0x591ac0: 7505 JNZ 0x591ac7
    if(integer::condition("JNZ",flags)) goto L00591ac7;
  }
  L00591ac2: { // 0x591ac2: 83f805 CMP EAX, 5
    (void)integer::sub(s.ax,5u,32,flags);
  }
  L00591ac5: { // 0x591ac5: 744a JZ 0x591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  L00591ac7: { // 0x591ac7: 83f913 CMP ECX, 0x13
    (void)integer::sub(s.cx,0x00000013u,32,flags);
  }
  L00591aca: { // 0x591aca: 7445 JZ 0x591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  L00591acc: { // 0x591acc: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00591acf: { // 0x591acf: 7420 JZ 0x591af1
    if(integer::condition("JZ",flags)) goto L00591af1;
  }
  L00591ad1: { // 0x591ad1: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00591ad3: { // 0x591ad3: 750f JNZ 0x591ae4
    if(integer::condition("JNZ",flags)) goto L00591ae4;
  }
  L00591ad5: { // 0x591ad5: 8b8ea0000000 MOV ECX, dword ptr [ESI + 0xa0]
    s.cx = m.r32((s.si+0x000000a0u));
  }
  L00591adb: { // 0x591adb: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00591add: { // 0x591add: 7412 JZ 0x591af1
    if(integer::condition("JZ",flags)) goto L00591af1;
  }
  L00591adf: { // 0x591adf: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L00591ae2: { // 0x591ae2: 740d JZ 0x591af1
    if(integer::condition("JZ",flags)) goto L00591af1;
  }
  L00591ae4: { // 0x591ae4: 8986a0000000 MOV dword ptr [ESI + 0xa0], EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  L00591aea: { // 0x591aea: c686a400000000 MOV byte ptr [ESI + 0xa4], 0
    m.w8((s.si+0x000000a4u), 0u);
  }
  L00591af1: { // 0x591af1: 8a44240c MOV AL, byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  L00591af5: { // 0x591af5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00591af7: { // 0x591af7: 7418 JZ 0x591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  L00591af9: { // 0x591af9: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00591afb: { // 0x591afb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00591afd: { // 0x591afd: ff90e8010000 CALL dword ptr [EAX + 0x1e8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001e8u)),5839619u); flags=s.arithmetic_flags;
  }
  L00591b03: { // 0x591b03: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00591b05: { // 0x591b05: 740a JZ 0x591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  L00591b07: { // 0x591b07: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00591b09: { // 0x591b09: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00591b0b: { // 0x591b0b: ff92d4010000 CALL dword ptr [EDX + 0x1d4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001d4u)),5839633u); flags=s.arithmetic_flags;
  }
  L00591b11: { // 0x591b11: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00591b12: { // 0x591b12: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002a9420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a9420: { // 0x6a9420: 8b4128 MOV EAX, dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  L006a9423: { // 0x6a9423: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a9425: { // 0x6a9425: 740f JZ 0x6a9436
    if(integer::condition("JZ",flags)) goto L006a9436;
  }
  L006a9427: { // 0x6a9427: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L006a942b: { // 0x6a942b: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006a942d: { // 0x6a942d: 740c JZ 0x6a943b
    if(integer::condition("JZ",flags)) goto L006a943b;
  }
  L006a942f: { // 0x6a942f: 8b4028 MOV EAX, dword ptr [EAX + 0x28]
    s.ax = m.r32((s.ax+0x00000028u));
  }
  L006a9432: { // 0x6a9432: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a9434: { // 0x6a9434: 75f5 JNZ 0x6a942b
    if(integer::condition("JNZ",flags)) goto L006a942b;
  }
  L006a9436: { // 0x6a9436: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006a9438: { // 0x6a9438: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006a943b: { // 0x6a943b: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L006a943d: { // 0x6a943d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5278800u:f_00108c50(m,s,child,{});break;
case 5838192u:f_00191570(m,s,child,{});break;
case 5839536u:f_00191ab0(m,s,child,{});break;
case 6984736u:f_002a9420(m,s,child,{});break;
default:throw std::domain_error("recovery688 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006a5100(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a5100: { // 0x6a5100: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L006a5105: { // 0x6a5105: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a5106: { // 0x6a5106: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006a5108: { // 0x6a5108: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a510a: { // 0x6a510a: 7e76 JLE 0x006a5182
    if(integer::condition("JLE",flags)) goto L006a5182;
  }
  L006a510c: { // 0x6a510c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a510d: { // 0x6a510d: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L006a5111: { // 0x6a5111: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a5112: { // 0x6a5112: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  L006a5117: { // 0x6a5117: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L006a511a: { // 0x6a511a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a511c: { // 0x6a511c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006a511e: { // 0x6a511e: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6967585u); flags=s.arithmetic_flags;
  }
  L006a5121: { // 0x6a5121: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006a5124: { // 0x6a5124: 744a JZ 0x006a5170
    if(integer::condition("JZ",flags)) goto L006a5170;
  }
  L006a5126: { // 0x6a5126: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L006a5129: { // 0x6a5129: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a512b: { // 0x6a512b: 7443 JZ 0x006a5170
    if(integer::condition("JZ",flags)) goto L006a5170;
  }
  L006a512d: { // 0x6a512d: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L006a5130: { // 0x6a5130: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a5132: { // 0x6a5132: 743c JZ 0x006a5170
    if(integer::condition("JZ",flags)) goto L006a5170;
  }
  L006a5134: { // 0x6a5134: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  L006a5137: { // 0x6a5137: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006a5139: { // 0x6a5139: 7435 JZ 0x006a5170
    if(integer::condition("JZ",flags)) goto L006a5170;
  }
  L006a513b: { // 0x6a513b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a513c: { // 0x6a513c: e8df420000 CALL 0x006a9420
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9420u,6967617u); flags=s.arithmetic_flags;
  }
  L006a5141: { // 0x6a5141: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a5143: { // 0x6a5143: 742b JZ 0x006a5170
    if(integer::condition("JZ",flags)) goto L006a5170;
  }
  L006a5145: { // 0x6a5145: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006a5147: { // 0x6a5147: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a5149: { // 0x6a5149: ff906c010000 CALL dword ptr [EAX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),6967631u); flags=s.arithmetic_flags;
  }
  L006a514f: { // 0x6a514f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a5151: { // 0x6a5151: 740f JZ 0x006a5162
    if(integer::condition("JZ",flags)) goto L006a5162;
  }
  L006a5153: { // 0x6a5153: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006a5155: { // 0x6a5155: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a5157: { // 0x6a5157: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),6967645u); flags=s.arithmetic_flags;
  }
  L006a515d: { // 0x6a515d: 83f817 CMP EAX,0x17
    (void)integer::sub(s.ax,0x00000017u,32,flags);
  }
  L006a5160: { // 0x6a5160: 750e JNZ 0x006a5170
    if(integer::condition("JNZ",flags)) goto L006a5170;
  }
  L006a5162: { // 0x6a5162: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006a5164: { // 0x6a5164: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5166: { // 0x6a5166: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L006a5168: { // 0x6a5168: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a516a: { // 0x6a516a: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d0u)),6967664u); flags=s.arithmetic_flags;
  }
  L006a5170: { // 0x6a5170: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L006a5175: { // 0x6a5175: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006a5176: { // 0x6a5176: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L006a5178: { // 0x6a5178: 7c98 JL 0x006a5112
    if(integer::condition("JL",flags)) goto L006a5112;
  }
  L006a517a: { // 0x6a517a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a517b: { // 0x6a517b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a517c: { // 0x6a517c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a517e: { // 0x6a517e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a517f: { // 0x6a517f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006a5182: { // 0x6a5182: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a5184: { // 0x6a5184: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a5185: { // 0x6a5185: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
