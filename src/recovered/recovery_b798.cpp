#include "recovered/recovery_b798_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b798 {
namespace {
void f_00050050(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00050050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00450050: { // 0x450050: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00450051: { // 0x450051: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00450053: { // 0x450053: 8a8630050000 MOV AL, byte ptr [ESI + 0x530]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000530u)));
  }
  L00450059: { // 0x450059: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0045005b: { // 0x45005b: 750d JNZ 0x45006a
    if(integer::condition("JNZ",flags)) goto L0045006a;
  }
  L0045005d: { // 0x45005d: 83be4c05000002 CMP dword ptr [ESI + 0x54c], 2
    (void)integer::sub(m.r32((s.si+0x0000054cu)),2u,32,flags);
  }
  L00450064: { // 0x450064: 7d04 JGE 0x45006a
    if(integer::condition("JGE",flags)) goto L0045006a;
  }
  L00450066: { // 0x450066: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00450068: { // 0x450068: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00450069: { // 0x450069: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0045006a: { // 0x45006a: 8b86fc030000 MOV EAX, dword ptr [ESI + 0x3fc]
    s.ax = m.r32((s.si+0x000003fcu));
  }
  L00450070: { // 0x450070: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00450072: { // 0x450072: 7e04 JLE 0x450078
    if(integer::condition("JLE",flags)) goto L00450078;
  }
  L00450074: { // 0x450074: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00450076: { // 0x450076: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00450077: { // 0x450077: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00450078: { // 0x450078: 8b466c MOV EAX, dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L0045007b: { // 0x45007b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045007d: { // 0x45007d: 7504 JNZ 0x450083
    if(integer::condition("JNZ",flags)) goto L00450083;
  }
  L0045007f: { // 0x45007f: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00450081: { // 0x450081: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00450082: { // 0x450082: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00450083: { // 0x450083: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00450089: { // 0x450089: 8a8817120000 MOV CL, byte ptr [EAX + 0x1217]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001217u)));
  }
  L0045008f: { // 0x45008f: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00450091: { // 0x450091: 7439 JZ 0x4500cc
    if(integer::condition("JZ",flags)) goto L004500cc;
  }
  L00450093: { // 0x450093: 8b886c0c0000 MOV ECX, dword ptr [EAX + 0xc6c]
    s.cx = m.r32((s.ax+0x00000c6cu));
  }
  L00450099: { // 0x450099: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0045009b: { // 0x45009b: 7e2f JLE 0x4500cc
    if(integer::condition("JLE",flags)) goto L004500cc;
  }
  L0045009d: { // 0x45009d: 8a88fe110000 MOV CL, byte ptr [EAX + 0x11fe]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000011feu)));
  }
  L004500a3: { // 0x4500a3: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004500a5: { // 0x4500a5: 7425 JZ 0x4500cc
    if(integer::condition("JZ",flags)) goto L004500cc;
  }
  L004500a7: { // 0x4500a7: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004500ad: { // 0x4500ad: e8be770900 CALL 0x4e7870
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e7870u,4522162u); flags=s.arithmetic_flags;
  }
  L004500b2: { // 0x4500b2: dc1d08577800 FCOMP qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004500b8: { // 0x4500b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004500ba: { // 0x4500ba: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L004500bd: { // 0x4500bd: 740d JZ 0x4500cc
    if(integer::condition("JZ",flags)) goto L004500cc;
  }
  L004500bf: { // 0x4500bf: 83be4c05000002 CMP dword ptr [ESI + 0x54c], 2
    (void)integer::sub(m.r32((s.si+0x0000054cu)),2u,32,flags);
  }
  L004500c6: { // 0x4500c6: 7d04 JGE 0x4500cc
    if(integer::condition("JGE",flags)) goto L004500cc;
  }
  L004500c8: { // 0x4500c8: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004500ca: { // 0x4500ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004500cb: { // 0x4500cb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004500cc: { // 0x4500cc: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004500d2: { // 0x4500d2: 8a8806120000 MOV CL, byte ptr [EAX + 0x1206]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001206u)));
  }
  L004500d8: { // 0x4500d8: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004500da: { // 0x4500da: 740e JZ 0x4500ea
    if(integer::condition("JZ",flags)) goto L004500ea;
  }
  L004500dc: { // 0x4500dc: 8a869c050000 MOV AL, byte ptr [ESI + 0x59c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000059cu)));
  }
  L004500e2: { // 0x4500e2: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004500e4: { // 0x4500e4: 7504 JNZ 0x4500ea
    if(integer::condition("JNZ",flags)) goto L004500ea;
  }
  L004500e6: { // 0x4500e6: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004500e8: { // 0x4500e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004500e9: { // 0x4500e9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004500ea: { // 0x4500ea: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004500ec: { // 0x4500ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004500ed: { // 0x4500ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4522064u:f_00050050(m,s,child,{});break;
default:throw std::domain_error("recovery798 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0044f5d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044f5d0: { // 0x44f5d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044f5d1: { // 0x44f5d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0044f5d3: { // 0x44f5d3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044f5d5: { // 0x44f5d5: ff900c030000 CALL dword ptr [EAX + 0x30c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000030cu)),4519387u); flags=s.arithmetic_flags;
  }
  L0044f5db: { // 0x44f5db: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044f5dd: { // 0x44f5dd: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044f5e3: { // 0x44f5e3: 8a8861130000 MOV CL,byte ptr [EAX + 0x1361]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001361u)));
  }
  L0044f5e9: { // 0x44f5e9: 0f8491000000 JZ 0x0044f680
    if(integer::condition("JZ",flags)) goto L0044f680;
  }
  L0044f5ef: { // 0x44f5ef: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f5f1: { // 0x44f5f1: 7436 JZ 0x0044f629
    if(integer::condition("JZ",flags)) goto L0044f629;
  }
  L0044f5f3: { // 0x44f5f3: 8a8ebb050000 MOV CL,byte ptr [ESI + 0x5bb]
    s.cx = with_al(s.cx, m.r8((s.si+0x000005bbu)));
  }
  L0044f5f9: { // 0x44f5f9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f5fb: { // 0x44f5fb: 7f2c JG 0x0044f629
    if(integer::condition("JG",flags)) goto L0044f629;
  }
  L0044f5fd: { // 0x44f5fd: 8a8ebc050000 MOV CL,byte ptr [ESI + 0x5bc]
    s.cx = with_al(s.cx, m.r8((s.si+0x000005bcu)));
  }
  L0044f603: { // 0x44f603: 8a908b130000 MOV DL,byte ptr [EAX + 0x138b]
    s.dx = with_al(s.dx, m.r8((s.ax+0x0000138bu)));
  }
  L0044f609: { // 0x44f609: 3aca CMP CL,DL
    (void)integer::sub((s.cx & 0xffu),(s.dx & 0xffu),8,flags);
  }
  L0044f60b: { // 0x44f60b: 741c JZ 0x0044f629
    if(integer::condition("JZ",flags)) goto L0044f629;
  }
  L0044f60d: { // 0x44f60d: c686bb05000001 MOV byte ptr [ESI + 0x5bb],0x1
    m.w8((s.si+0x000005bbu), 0x00000001u);
  }
  L0044f614: { // 0x44f614: 8a908b130000 MOV DL,byte ptr [EAX + 0x138b]
    s.dx = with_al(s.dx, m.r8((s.ax+0x0000138bu)));
  }
  L0044f61a: { // 0x44f61a: 3aca CMP CL,DL
    (void)integer::sub((s.cx & 0xffu),(s.dx & 0xffu),8,flags);
  }
  L0044f61c: { // 0x44f61c: 7507 JNZ 0x0044f625
    if(integer::condition("JNZ",flags)) goto L0044f625;
  }
  L0044f61e: { // 0x44f61e: c686bc05000000 MOV byte ptr [ESI + 0x5bc],0x0
    m.w8((s.si+0x000005bcu), 0x00000000u);
  }
  L0044f625: { // 0x44f625: c6467501 MOV byte ptr [ESI + 0x75],0x1
    m.w8((s.si+0x00000075u), 0x00000001u);
  }
  L0044f629: { // 0x44f629: 8a88dd0a0000 MOV CL,byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0044f62f: { // 0x44f62f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f631: { // 0x44f631: 7414 JZ 0x0044f647
    if(integer::condition("JZ",flags)) goto L0044f647;
  }
  L0044f633: { // 0x44f633: 8a86fd010000 MOV AL,byte ptr [ESI + 0x1fd]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fdu)));
  }
  L0044f639: { // 0x44f639: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044f63b: { // 0x44f63b: 750a JNZ 0x0044f647
    if(integer::condition("JNZ",flags)) goto L0044f647;
  }
  L0044f63d: { // 0x44f63d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044f63f: { // 0x44f63f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044f641: { // 0x44f641: ff92ac030000 CALL dword ptr [EDX + 0x3ac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003acu)),4519495u); flags=s.arithmetic_flags;
  }
  L0044f647: { // 0x44f647: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044f64d: { // 0x44f64d: 8a8817120000 MOV CL,byte ptr [EAX + 0x1217]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001217u)));
  }
  L0044f653: { // 0x44f653: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f655: { // 0x44f655: 0f84d3000000 JZ 0x0044f72e
    if(integer::condition("JZ",flags)) goto L0044f72e;
  }
  L0044f65b: { // 0x44f65b: 8b886c0c0000 MOV ECX,dword ptr [EAX + 0xc6c]
    s.cx = m.r32((s.ax+0x00000c6cu));
  }
  L0044f661: { // 0x44f661: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044f663: { // 0x44f663: 0f8ec5000000 JLE 0x0044f72e
    if(integer::condition("JLE",flags)) goto L0044f72e;
  }
  L0044f669: { // 0x44f669: 8a88fe110000 MOV CL,byte ptr [EAX + 0x11fe]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000011feu)));
  }
  L0044f66f: { // 0x44f66f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f671: { // 0x44f671: 0f84b7000000 JZ 0x0044f72e
    if(integer::condition("JZ",flags)) goto L0044f72e;
  }
  L0044f677: { // 0x44f677: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044f679: { // 0x44f679: e8a2fdffff CALL 0x0044f420
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044f420u,4519550u); flags=s.arithmetic_flags;
  }
  L0044f67e: { // 0x44f67e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044f67f: { // 0x44f67f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0044f680: { // 0x44f680: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f682: { // 0x44f682: 741f JZ 0x0044f6a3
    if(integer::condition("JZ",flags)) goto L0044f6a3;
  }
  L0044f684: { // 0x44f684: 8a8ebb050000 MOV CL,byte ptr [ESI + 0x5bb]
    s.cx = with_al(s.cx, m.r8((s.si+0x000005bbu)));
  }
  L0044f68a: { // 0x44f68a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f68c: { // 0x44f68c: 7c15 JL 0x0044f6a3
    if(integer::condition("JL",flags)) goto L0044f6a3;
  }
  L0044f68e: { // 0x44f68e: 8a8ebc050000 MOV CL,byte ptr [ESI + 0x5bc]
    s.cx = with_al(s.cx, m.r8((s.si+0x000005bcu)));
  }
  L0044f694: { // 0x44f694: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f696: { // 0x44f696: 740b JZ 0x0044f6a3
    if(integer::condition("JZ",flags)) goto L0044f6a3;
  }
  L0044f698: { // 0x44f698: c686bb050000ff MOV byte ptr [ESI + 0x5bb],0xff
    m.w8((s.si+0x000005bbu), 0x000000ffu);
  }
  L0044f69f: { // 0x44f69f: c6467501 MOV byte ptr [ESI + 0x75],0x1
    m.w8((s.si+0x00000075u), 0x00000001u);
  }
  L0044f6a3: { // 0x44f6a3: 8a88dd0a0000 MOV CL,byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0044f6a9: { // 0x44f6a9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f6ab: { // 0x44f6ab: 7456 JZ 0x0044f703
    if(integer::condition("JZ",flags)) goto L0044f703;
  }
  L0044f6ad: { // 0x44f6ad: 8a86fd010000 MOV AL,byte ptr [ESI + 0x1fd]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fdu)));
  }
  L0044f6b3: { // 0x44f6b3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044f6b5: { // 0x44f6b5: 744c JZ 0x0044f703
    if(integer::condition("JZ",flags)) goto L0044f703;
  }
  L0044f6b7: { // 0x44f6b7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044f6b9: { // 0x44f6b9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044f6bb: { // 0x44f6bb: ff90b0030000 CALL dword ptr [EAX + 0x3b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000003b0u)),4519617u); flags=s.arithmetic_flags;
  }
  L0044f6c1: { // 0x44f6c1: 8a86fc010000 MOV AL,byte ptr [ESI + 0x1fc]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fcu)));
  }
  L0044f6c7: { // 0x44f6c7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044f6c9: { // 0x44f6c9: 7438 JZ 0x0044f703
    if(integer::condition("JZ",flags)) goto L0044f703;
  }
  L0044f6cb: { // 0x44f6cb: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044f6d1: { // 0x44f6d1: c686fc01000000 MOV byte ptr [ESI + 0x1fc],0x0
    m.w8((s.si+0x000001fcu), 0x00000000u);
  }
  L0044f6d8: { // 0x44f6d8: c6863905000000 MOV byte ptr [ESI + 0x539],0x0
    m.w8((s.si+0x00000539u), 0x00000000u);
  }
  L0044f6df: { // 0x44f6df: c6816856000001 MOV byte ptr [ECX + 0x5668],0x1
    m.w8((s.cx+0x00005668u), 0x00000001u);
  }
  L0044f6e6: { // 0x44f6e6: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0044f6ec: { // 0x44f6ec: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044f6ee: { // 0x44f6ee: 0fbe82de0a0000 MOVSX EAX,byte ptr [EDX + 0xade]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.dx+0x00000adeu)),8));
  }
  L0044f6f5: { // 0x44f6f5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044f6f7: { // 0x44f6f7: 898600020000 MOV dword ptr [ESI + 0x200],EAX
    m.w32((s.si+0x00000200u), s.ax);
  }
  L0044f6fd: { // 0x44f6fd: ff92ac030000 CALL dword ptr [EDX + 0x3ac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003acu)),4519683u); flags=s.arithmetic_flags;
  }
  L0044f703: { // 0x44f703: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044f709: { // 0x44f709: 8a8817120000 MOV CL,byte ptr [EAX + 0x1217]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001217u)));
  }
  L0044f70f: { // 0x44f70f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f711: { // 0x44f711: 741b JZ 0x0044f72e
    if(integer::condition("JZ",flags)) goto L0044f72e;
  }
  L0044f713: { // 0x44f713: 8b886c0c0000 MOV ECX,dword ptr [EAX + 0xc6c]
    s.cx = m.r32((s.ax+0x00000c6cu));
  }
  L0044f719: { // 0x44f719: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044f71b: { // 0x44f71b: 7e11 JLE 0x0044f72e
    if(integer::condition("JLE",flags)) goto L0044f72e;
  }
  L0044f71d: { // 0x44f71d: 8a88fe110000 MOV CL,byte ptr [EAX + 0x11fe]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000011feu)));
  }
  L0044f723: { // 0x44f723: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044f725: { // 0x44f725: 7407 JZ 0x0044f72e
    if(integer::condition("JZ",flags)) goto L0044f72e;
  }
  L0044f727: { // 0x44f727: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044f729: { // 0x44f729: e8c2fdffff CALL 0x0044f4f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044f4f0u,4519726u); flags=s.arithmetic_flags;
  }
  L0044f72e: { // 0x44f72e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044f72f: { // 0x44f72f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
