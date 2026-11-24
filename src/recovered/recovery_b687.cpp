#include "recovered/recovery_b687_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b687 {
namespace {
void f_00191570(Memory&,State&,Frame&,const Operations&);
void f_00096890(Memory&,State&,Frame&,const Operations&);
void f_00096930(Memory&,State&,Frame&,const Operations&);
void f_00096910(Memory&,State&,Frame&,const Operations&);
void f_00068610(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_00096890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00496890: { // 0x496890: 8a4118 MOV AL, byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  L00496893: { // 0x496893: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00496895: { // 0x496895: 740a JZ 0x4968a1
    if(integer::condition("JZ",flags)) goto L004968a1;
  }
  L00496897: { // 0x496897: 8a4119 MOV AL, byte ptr [ECX + 0x19]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000019u)));
  }
  L0049689a: { // 0x49689a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049689c: { // 0x49689c: 7503 JNZ 0x4968a1
    if(integer::condition("JNZ",flags)) goto L004968a1;
  }
  L0049689e: { // 0x49689e: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004968a0: { // 0x4968a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004968a1: { // 0x4968a1: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004968a3: { // 0x4968a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00096930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00496930: { // 0x496930: 8a4118 MOV AL, byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  L00496933: { // 0x496933: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00496935: { // 0x496935: 750a JNZ 0x496941
    if(integer::condition("JNZ",flags)) goto L00496941;
  }
  L00496937: { // 0x496937: 8a4119 MOV AL, byte ptr [ECX + 0x19]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000019u)));
  }
  L0049693a: { // 0x49693a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049693c: { // 0x49693c: 7503 JNZ 0x496941
    if(integer::condition("JNZ",flags)) goto L00496941;
  }
  L0049693e: { // 0x49693e: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00496940: { // 0x496940: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00496941: { // 0x496941: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00496943: { // 0x496943: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00096910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00496910: { // 0x496910: 8a4118 MOV AL, byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  L00496913: { // 0x496913: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00496915: { // 0x496915: 7509 JNZ 0x496920
    if(integer::condition("JNZ",flags)) goto L00496920;
  }
  L00496917: { // 0x496917: 8a5119 MOV DL, byte ptr [ECX + 0x19]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000019u)));
  }
  L0049691a: { // 0x49691a: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0049691c: { // 0x49691c: 3ad0 CMP DL, AL
    (void)integer::sub((s.dx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0049691e: { // 0x49691e: 7402 JZ 0x496922
    if(integer::condition("JZ",flags)) goto L00496922;
  }
  L00496920: { // 0x496920: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00496922: { // 0x496922: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00068610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00468610: { // 0x468610: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00468613: { // 0x468613: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00468615: { // 0x468615: 7501 JNZ 0x468618
    if(integer::condition("JNZ",flags)) goto L00468618;
  }
  L00468617: { // 0x468617: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00468618: { // 0x468618: 8b5030 MOV EDX, dword ptr [EAX + 0x30]
    s.dx = m.r32((s.ax+0x00000030u));
  }
  L0046861b: { // 0x46861b: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L0046861e: { // 0x46861e: c7403000000000 MOV dword ptr [EAX + 0x30], 0
    m.w32((s.ax+0x00000030u), 0u);
  }
  L00468625: { // 0x468625: ff09 DEC dword ptr [ECX]
    m.w32((s.cx), integer::decrement(m.r32((s.cx)),32,flags));
  }
  L00468627: { // 0x468627: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("687 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5838192u:f_00191570(m,s,child,{});break;
case 4810896u:f_00096890(m,s,child,{});break;
case 4811056u:f_00096930(m,s,child,{});break;
case 4811024u:f_00096910(m,s,child,{});break;
case 4621840u:f_00068610(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
default:throw std::domain_error("recovery687 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0044d4c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d4c0: { // 0x44d4c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d4c1: { // 0x44d4c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0044d4c3: { // 0x44d4c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d4c4: { // 0x44d4c4: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d4ca: { // 0x44d4ca: 8a8851130000 MOV CL,byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L0044d4d0: { // 0x44d4d0: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d4d2: { // 0x44d4d2: 7505 JNZ 0x0044d4d9
    if(integer::condition("JNZ",flags)) goto L0044d4d9;
  }
  L0044d4d4: { // 0x44d4d4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d4d5: { // 0x44d4d5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0044d4d7: { // 0x44d4d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d4d8: { // 0x44d4d8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0044d4d9: { // 0x44d4d9: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044d4db: { // 0x44d4db: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044d4dd: { // 0x44d4dd: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4510947u); flags=s.arithmetic_flags;
  }
  L0044d4e3: { // 0x44d4e3: 83f818 CMP EAX,0x18
    (void)integer::sub(s.ax,0x00000018u,32,flags);
  }
  L0044d4e6: { // 0x44d4e6: 7550 JNZ 0x0044d538
    if(integer::condition("JNZ",flags)) goto L0044d538;
  }
  L0044d4e8: { // 0x44d4e8: 8dbea8020000 LEA EDI,[ESI + 0x2a8]
    s.di = (s.si+0x000002a8u);
  }
  L0044d4ee: { // 0x44d4ee: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044d4f0: { // 0x44d4f0: e89b930400 CALL 0x00496890
    s.arithmetic_flags=flags; invoke(m,s,f,0x00496890u,4510965u); flags=s.arithmetic_flags;
  }
  L0044d4f5: { // 0x44d4f5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d4f7: { // 0x44d4f7: 753f JNZ 0x0044d538
    if(integer::condition("JNZ",flags)) goto L0044d538;
  }
  L0044d4f9: { // 0x44d4f9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044d4fb: { // 0x44d4fb: e830940400 CALL 0x00496930
    s.arithmetic_flags=flags; invoke(m,s,f,0x00496930u,4510976u); flags=s.arithmetic_flags;
  }
  L0044d500: { // 0x44d500: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d502: { // 0x44d502: 7534 JNZ 0x0044d538
    if(integer::condition("JNZ",flags)) goto L0044d538;
  }
  L0044d504: { // 0x44d504: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d50a: { // 0x44d50a: 8a8851130000 MOV CL,byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L0044d510: { // 0x44d510: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d512: { // 0x44d512: 7505 JNZ 0x0044d519
    if(integer::condition("JNZ",flags)) goto L0044d519;
  }
  L0044d514: { // 0x44d514: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d515: { // 0x44d515: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0044d517: { // 0x44d517: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d518: { // 0x44d518: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0044d519: { // 0x44d519: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044d51b: { // 0x44d51b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044d51d: { // 0x44d51d: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4511011u); flags=s.arithmetic_flags;
  }
  L0044d523: { // 0x44d523: 83f818 CMP EAX,0x18
    (void)integer::sub(s.ax,0x00000018u,32,flags);
  }
  L0044d526: { // 0x44d526: 7534 JNZ 0x0044d55c
    if(integer::condition("JNZ",flags)) goto L0044d55c;
  }
  L0044d528: { // 0x44d528: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044d52a: { // 0x44d52a: e8e1930400 CALL 0x00496910
    s.arithmetic_flags=flags; invoke(m,s,f,0x00496910u,4511023u); flags=s.arithmetic_flags;
  }
  L0044d52f: { // 0x44d52f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d531: { // 0x44d531: 7429 JZ 0x0044d55c
    if(integer::condition("JZ",flags)) goto L0044d55c;
  }
  L0044d533: { // 0x44d533: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d534: { // 0x44d534: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0044d536: { // 0x44d536: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d537: { // 0x44d537: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0044d538: { // 0x44d538: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044d53a: { // 0x44d53a: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0044d53c: { // 0x44d53c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044d53e: { // 0x44d53e: ff90d8010000 CALL dword ptr [EAX + 0x1d8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d8u)),4511044u); flags=s.arithmetic_flags;
  }
  L0044d544: { // 0x44d544: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044d546: { // 0x44d546: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044d548: { // 0x44d548: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L0044d54a: { // 0x44d54a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044d54c: { // 0x44d54c: ff92d0010000 CALL dword ptr [EDX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001d0u)),4511058u); flags=s.arithmetic_flags;
  }
  L0044d552: { // 0x44d552: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044d554: { // 0x44d554: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044d556: { // 0x44d556: ff90d4010000 CALL dword ptr [EAX + 0x1d4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d4u)),4511068u); flags=s.arithmetic_flags;
  }
  L0044d55c: { // 0x44d55c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d55d: { // 0x44d55d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0044d55f: { // 0x44d55f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d560: { // 0x44d560: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004ccbc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ccbc0: { // 0x4ccbc0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004ccbc3: { // 0x4ccbc3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ccbc4: { // 0x4ccbc4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ccbc5: { // 0x4ccbc5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004ccbc7: { // 0x4ccbc7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ccbc8: { // 0x4ccbc8: 8d9ef8000000 LEA EBX,[ESI + 0xf8]
    s.bx = (s.si+0x000000f8u);
  }
  L004ccbce: { // 0x4ccbce: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004ccbd0: { // 0x4ccbd0: e83bbaf9ff CALL 0x00468610
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468610u,5032917u); flags=s.arithmetic_flags;
  }
  L004ccbd5: { // 0x4ccbd5: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004ccbd7: { // 0x4ccbd7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ccbd9: { // 0x4ccbd9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ccbdb: { // 0x4ccbdb: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),5032929u); flags=s.arithmetic_flags;
  }
  L004ccbe1: { // 0x4ccbe1: 8a8801070000 MOV CL,byte ptr [EAX + 0x701]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000701u)));
  }
  L004ccbe7: { // 0x4ccbe7: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ccbe9: { // 0x4ccbe9: 7410 JZ 0x004ccbfb
    if(integer::condition("JZ",flags)) goto L004ccbfb;
  }
  L004ccbeb: { // 0x4ccbeb: 833b00 CMP dword ptr [EBX],0x0
    (void)integer::sub(m.r32((s.bx)),0x00000000u,32,flags);
  }
  L004ccbee: { // 0x4ccbee: 750b JNZ 0x004ccbfb
    if(integer::condition("JNZ",flags)) goto L004ccbfb;
  }
  L004ccbf0: { // 0x4ccbf0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ccbf2: { // 0x4ccbf2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ccbf3: { // 0x4ccbf3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ccbf5: { // 0x4ccbf5: ff9264040000 CALL dword ptr [EDX + 0x464]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000464u)),5032955u); flags=s.arithmetic_flags;
  }
  L004ccbfb: { // 0x4ccbfb: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ccbfd: { // 0x4ccbfd: 744a JZ 0x004ccc49
    if(integer::condition("JZ",flags)) goto L004ccc49;
  }
  L004ccbff: { // 0x4ccbff: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ccc01: { // 0x4ccc01: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ccc03: { // 0x4ccc03: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),5032969u); flags=s.arithmetic_flags;
  }
  L004ccc09: { // 0x4ccc09: 83b8ec040000ff CMP dword ptr [EAX + 0x4ec],-0x1
    (void)integer::sub(m.r32((s.ax+0x000004ecu)),0xffffffffu,32,flags);
  }
  L004ccc10: { // 0x4ccc10: 7437 JZ 0x004ccc49
    if(integer::condition("JZ",flags)) goto L004ccc49;
  }
  L004ccc12: { // 0x4ccc12: 8d8e88000000 LEA ECX,[ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L004ccc18: { // 0x4ccc18: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ccc1a: { // 0x4ccc1a: 8d5c2410 LEA EBX,[ESP + 0x10]
    s.bx = (f.sp+0x00000010u);
  }
  L004ccc1e: { // 0x4ccc1e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004ccc20: { // 0x4ccc20: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004ccc24: { // 0x4ccc24: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ccc26: { // 0x4ccc26: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004ccc29: { // 0x4ccc29: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004ccc2d: { // 0x4ccc2d: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L004ccc30: { // 0x4ccc30: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004ccc34: { // 0x4ccc34: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ccc36: { // 0x4ccc36: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),5033020u); flags=s.arithmetic_flags;
  }
  L004ccc3c: { // 0x4ccc3c: 8b88ec040000 MOV ECX,dword ptr [EAX + 0x4ec]
    s.cx = m.r32((s.ax+0x000004ecu));
  }
  L004ccc42: { // 0x4ccc42: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L004ccc44: { // 0x4ccc44: e807c22300 CALL 0x00708e50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708e50u,5033033u); flags=s.arithmetic_flags;
  }
  L004ccc49: { // 0x4ccc49: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ccc4b: { // 0x4ccc4b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ccc4c: { // 0x4ccc4c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ccc4d: { // 0x4ccc4d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ccc4e: { // 0x4ccc4e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004ccc51: { // 0x4ccc51: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
