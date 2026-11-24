#include "recovered/recovery_b716_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b716 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_002ad030(Memory&,State&,Frame&,const Operations&);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("716 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}


} // namespace
namespace {
void f_002ad030(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ad030: { // 0x6ad030: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006ad031: { // 0x6ad031: 8b6c2408 MOV EBP,dword ptr [ESP + 0x8]
    s.bp = m.r32((f.sp+0x00000008u));
  }
  L006ad035: { // 0x6ad035: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ad036: { // 0x6ad036: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ad037: { // 0x6ad037: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006ad039: { // 0x6ad039: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  L006ad03c: { // 0x6ad03c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L006ad03e: { // 0x6ad03e: 7470 JZ 0x006ad0b0
    if(integer::condition("JZ",flags)) goto L006ad0b0;
  }
  L006ad040: { // 0x6ad040: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  L006ad043: { // 0x6ad043: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ad045: { // 0x6ad045: 7469 JZ 0x006ad0b0
    if(integer::condition("JZ",flags)) goto L006ad0b0;
  }
  L006ad047: { // 0x6ad047: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad049: { // 0x6ad049: 7465 JZ 0x006ad0b0
    if(integer::condition("JZ",flags)) goto L006ad0b0;
  }
  L006ad04b: { // 0x6ad04b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ad04c: { // 0x6ad04c: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  L006ad04f: { // 0x6ad04f: 8b9e28020000 MOV EBX,dword ptr [ESI + 0x228]
    s.bx = m.r32((s.si+0x00000228u));
  }
  L006ad055: { // 0x6ad055: 8b9694040000 MOV EDX,dword ptr [ESI + 0x494]
    s.dx = m.r32((s.si+0x00000494u));
  }
  L006ad05b: { // 0x6ad05b: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006ad05d: { // 0x6ad05d: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006ad060: { // 0x6ad060: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006ad062: { // 0x6ad062: 884c2414 MOV byte ptr [ESP + 0x14],CL
    m.w8((f.sp+0x00000014u), (s.cx & 0xffu));
  }
  L006ad066: { // 0x6ad066: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006ad069: { // 0x6ad069: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006ad06b: { // 0x6ad06b: 7504 JNZ 0x006ad071
    if(integer::condition("JNZ",flags)) goto L006ad071;
  }
  L006ad06d: { // 0x6ad06d: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006ad06f: { // 0x6ad06f: 7434 JZ 0x006ad0a5
    if(integer::condition("JZ",flags)) goto L006ad0a5;
  }
  L006ad071: { // 0x6ad071: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ad073: { // 0x6ad073: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad075: { // 0x6ad075: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L006ad077: { // 0x6ad077: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad079: { // 0x6ad079: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d0u)),7000191u); flags=s.arithmetic_flags;
  }
  L006ad07f: { // 0x6ad07f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006ad081: { // 0x6ad081: 740e JZ 0x006ad091
    if(integer::condition("JZ",flags)) goto L006ad091;
  }
  L006ad083: { // 0x6ad083: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006ad085: { // 0x6ad085: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ad087: { // 0x6ad087: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad089: { // 0x6ad089: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad08b: { // 0x6ad08b: ff9210040000 CALL dword ptr [EDX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000410u)),7000209u); flags=s.arithmetic_flags;
  }
  L006ad091: { // 0x6ad091: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L006ad095: { // 0x6ad095: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ad097: { // 0x6ad097: 740c JZ 0x006ad0a5
    if(integer::condition("JZ",flags)) goto L006ad0a5;
  }
  L006ad099: { // 0x6ad099: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ad09b: { // 0x6ad09b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad09d: { // 0x6ad09d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad09f: { // 0x6ad09f: ff9070030000 CALL dword ptr [EAX + 0x370]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000370u)),7000229u); flags=s.arithmetic_flags;
  }
  L006ad0a5: { // 0x6ad0a5: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  L006ad0ab: { // 0x6ad0ab: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad0ad: { // 0x6ad0ad: 759d JNZ 0x006ad04c
    if(integer::condition("JNZ",flags)) goto L006ad04c;
  }
  L006ad0af: { // 0x6ad0af: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ad0b0: { // 0x6ad0b0: 8b4740 MOV EAX,dword ptr [EDI + 0x40]
    s.ax = m.r32((s.di+0x00000040u));
  }
  L006ad0b3: { // 0x6ad0b3: 8b4f3c MOV ECX,dword ptr [EDI + 0x3c]
    s.cx = m.r32((s.di+0x0000003cu));
  }
  L006ad0b6: { // 0x6ad0b6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006ad0b8: { // 0x6ad0b8: 7404 JZ 0x006ad0be
    if(integer::condition("JZ",flags)) goto L006ad0be;
  }
  L006ad0ba: { // 0x6ad0ba: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ad0bc: { // 0x6ad0bc: 7503 JNZ 0x006ad0c1
    if(integer::condition("JNZ",flags)) goto L006ad0c1;
  }
  L006ad0be: { // 0x6ad0be: 896f40 MOV dword ptr [EDI + 0x40],EBP
    m.w32((s.di+0x00000040u), s.bp);
  }
  L006ad0c1: { // 0x6ad0c1: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006ad0c3: { // 0x6ad0c3: 896f3c MOV dword ptr [EDI + 0x3c],EBP
    m.w32((s.di+0x0000003cu), s.bp);
  }
  L006ad0c6: { // 0x6ad0c6: 7451 JZ 0x006ad119
    if(integer::condition("JZ",flags)) goto L006ad119;
  }
  L006ad0c8: { // 0x6ad0c8: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L006ad0cb: { // 0x6ad0cb: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006ad0cd: { // 0x6ad0cd: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7000272u); flags=s.arithmetic_flags;
  }
  L006ad0d0: { // 0x6ad0d0: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L006ad0d3: { // 0x6ad0d3: 7544 JNZ 0x006ad119
    if(integer::condition("JNZ",flags)) goto L006ad119;
  }
  L006ad0d5: { // 0x6ad0d5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ad0d7: { // 0x6ad0d7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006ad0d8: { // 0x6ad0d8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006ad0dd: { // 0x6ad0dd: e84ea4eaff CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,7000290u); flags=s.arithmetic_flags;
  }
  L006ad0e2: { // 0x6ad0e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ad0e4: { // 0x6ad0e4: 752c JNZ 0x006ad112
    if(integer::condition("JNZ",flags)) goto L006ad112;
  }
  L006ad0e6: { // 0x6ad0e6: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  L006ad0e9: { // 0x6ad0e9: c6878100000001 MOV byte ptr [EDI + 0x81],0x1
    m.w8((s.di+0x00000081u), 0x00000001u);
  }
  L006ad0f0: { // 0x6ad0f0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad0f2: { // 0x6ad0f2: 7425 JZ 0x006ad119
    if(integer::condition("JZ",flags)) goto L006ad119;
  }
  L006ad0f4: { // 0x6ad0f4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ad0f6: { // 0x6ad0f6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ad0f8: { // 0x6ad0f8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad0fa: { // 0x6ad0fa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad0fc: { // 0x6ad0fc: ff9010040000 CALL dword ptr [EAX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000410u)),7000322u); flags=s.arithmetic_flags;
  }
  L006ad102: { // 0x6ad102: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  L006ad108: { // 0x6ad108: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad10a: { // 0x6ad10a: 75e8 JNZ 0x006ad0f4
    if(integer::condition("JNZ",flags)) goto L006ad0f4;
  }
  L006ad10c: { // 0x6ad10c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ad10d: { // 0x6ad10d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ad10e: { // 0x6ad10e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006ad10f: { // 0x6ad10f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006ad112: { // 0x6ad112: c6878100000000 MOV byte ptr [EDI + 0x81],0x0
    m.w8((s.di+0x00000081u), 0x00000000u);
  }
  L006ad119: { // 0x6ad119: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ad11a: { // 0x6ad11a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ad11b: { // 0x6ad11b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006ad11c: { // 0x6ad11c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x6ad030u:f_002ad030(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery716 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006ad030(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ad030: { // 0x6ad030: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006ad031: { // 0x6ad031: 8b6c2408 MOV EBP,dword ptr [ESP + 0x8]
    s.bp = m.r32((f.sp+0x00000008u));
  }
  L006ad035: { // 0x6ad035: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ad036: { // 0x6ad036: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ad037: { // 0x6ad037: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006ad039: { // 0x6ad039: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  L006ad03c: { // 0x6ad03c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L006ad03e: { // 0x6ad03e: 7470 JZ 0x006ad0b0
    if(integer::condition("JZ",flags)) goto L006ad0b0;
  }
  L006ad040: { // 0x6ad040: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  L006ad043: { // 0x6ad043: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ad045: { // 0x6ad045: 7469 JZ 0x006ad0b0
    if(integer::condition("JZ",flags)) goto L006ad0b0;
  }
  L006ad047: { // 0x6ad047: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad049: { // 0x6ad049: 7465 JZ 0x006ad0b0
    if(integer::condition("JZ",flags)) goto L006ad0b0;
  }
  L006ad04b: { // 0x6ad04b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ad04c: { // 0x6ad04c: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  L006ad04f: { // 0x6ad04f: 8b9e28020000 MOV EBX,dword ptr [ESI + 0x228]
    s.bx = m.r32((s.si+0x00000228u));
  }
  L006ad055: { // 0x6ad055: 8b9694040000 MOV EDX,dword ptr [ESI + 0x494]
    s.dx = m.r32((s.si+0x00000494u));
  }
  L006ad05b: { // 0x6ad05b: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006ad05d: { // 0x6ad05d: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006ad060: { // 0x6ad060: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006ad062: { // 0x6ad062: 884c2414 MOV byte ptr [ESP + 0x14],CL
    m.w8((f.sp+0x00000014u), (s.cx & 0xffu));
  }
  L006ad066: { // 0x6ad066: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006ad069: { // 0x6ad069: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006ad06b: { // 0x6ad06b: 7504 JNZ 0x006ad071
    if(integer::condition("JNZ",flags)) goto L006ad071;
  }
  L006ad06d: { // 0x6ad06d: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006ad06f: { // 0x6ad06f: 7434 JZ 0x006ad0a5
    if(integer::condition("JZ",flags)) goto L006ad0a5;
  }
  L006ad071: { // 0x6ad071: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ad073: { // 0x6ad073: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad075: { // 0x6ad075: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L006ad077: { // 0x6ad077: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad079: { // 0x6ad079: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d0u)),7000191u); flags=s.arithmetic_flags;
  }
  L006ad07f: { // 0x6ad07f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006ad081: { // 0x6ad081: 740e JZ 0x006ad091
    if(integer::condition("JZ",flags)) goto L006ad091;
  }
  L006ad083: { // 0x6ad083: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006ad085: { // 0x6ad085: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ad087: { // 0x6ad087: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad089: { // 0x6ad089: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad08b: { // 0x6ad08b: ff9210040000 CALL dword ptr [EDX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000410u)),7000209u); flags=s.arithmetic_flags;
  }
  L006ad091: { // 0x6ad091: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L006ad095: { // 0x6ad095: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ad097: { // 0x6ad097: 740c JZ 0x006ad0a5
    if(integer::condition("JZ",flags)) goto L006ad0a5;
  }
  L006ad099: { // 0x6ad099: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ad09b: { // 0x6ad09b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad09d: { // 0x6ad09d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad09f: { // 0x6ad09f: ff9070030000 CALL dword ptr [EAX + 0x370]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000370u)),7000229u); flags=s.arithmetic_flags;
  }
  L006ad0a5: { // 0x6ad0a5: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  L006ad0ab: { // 0x6ad0ab: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad0ad: { // 0x6ad0ad: 759d JNZ 0x006ad04c
    if(integer::condition("JNZ",flags)) goto L006ad04c;
  }
  L006ad0af: { // 0x6ad0af: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ad0b0: { // 0x6ad0b0: 8b4740 MOV EAX,dword ptr [EDI + 0x40]
    s.ax = m.r32((s.di+0x00000040u));
  }
  L006ad0b3: { // 0x6ad0b3: 8b4f3c MOV ECX,dword ptr [EDI + 0x3c]
    s.cx = m.r32((s.di+0x0000003cu));
  }
  L006ad0b6: { // 0x6ad0b6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006ad0b8: { // 0x6ad0b8: 7404 JZ 0x006ad0be
    if(integer::condition("JZ",flags)) goto L006ad0be;
  }
  L006ad0ba: { // 0x6ad0ba: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ad0bc: { // 0x6ad0bc: 7503 JNZ 0x006ad0c1
    if(integer::condition("JNZ",flags)) goto L006ad0c1;
  }
  L006ad0be: { // 0x6ad0be: 896f40 MOV dword ptr [EDI + 0x40],EBP
    m.w32((s.di+0x00000040u), s.bp);
  }
  L006ad0c1: { // 0x6ad0c1: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006ad0c3: { // 0x6ad0c3: 896f3c MOV dword ptr [EDI + 0x3c],EBP
    m.w32((s.di+0x0000003cu), s.bp);
  }
  L006ad0c6: { // 0x6ad0c6: 7451 JZ 0x006ad119
    if(integer::condition("JZ",flags)) goto L006ad119;
  }
  L006ad0c8: { // 0x6ad0c8: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L006ad0cb: { // 0x6ad0cb: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006ad0cd: { // 0x6ad0cd: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7000272u); flags=s.arithmetic_flags;
  }
  L006ad0d0: { // 0x6ad0d0: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L006ad0d3: { // 0x6ad0d3: 7544 JNZ 0x006ad119
    if(integer::condition("JNZ",flags)) goto L006ad119;
  }
  L006ad0d5: { // 0x6ad0d5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ad0d7: { // 0x6ad0d7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006ad0d8: { // 0x6ad0d8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006ad0dd: { // 0x6ad0dd: e84ea4eaff CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,7000290u); flags=s.arithmetic_flags;
  }
  L006ad0e2: { // 0x6ad0e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ad0e4: { // 0x6ad0e4: 752c JNZ 0x006ad112
    if(integer::condition("JNZ",flags)) goto L006ad112;
  }
  L006ad0e6: { // 0x6ad0e6: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  L006ad0e9: { // 0x6ad0e9: c6878100000001 MOV byte ptr [EDI + 0x81],0x1
    m.w8((s.di+0x00000081u), 0x00000001u);
  }
  L006ad0f0: { // 0x6ad0f0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad0f2: { // 0x6ad0f2: 7425 JZ 0x006ad119
    if(integer::condition("JZ",flags)) goto L006ad119;
  }
  L006ad0f4: { // 0x6ad0f4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ad0f6: { // 0x6ad0f6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ad0f8: { // 0x6ad0f8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ad0fa: { // 0x6ad0fa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ad0fc: { // 0x6ad0fc: ff9010040000 CALL dword ptr [EAX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000410u)),7000322u); flags=s.arithmetic_flags;
  }
  L006ad102: { // 0x6ad102: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  L006ad108: { // 0x6ad108: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ad10a: { // 0x6ad10a: 75e8 JNZ 0x006ad0f4
    if(integer::condition("JNZ",flags)) goto L006ad0f4;
  }
  L006ad10c: { // 0x6ad10c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ad10d: { // 0x6ad10d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ad10e: { // 0x6ad10e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006ad10f: { // 0x6ad10f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ad112: { // 0x6ad112: c6878100000000 MOV byte ptr [EDI + 0x81],0x0
    m.w8((s.di+0x00000081u), 0x00000000u);
  }
  L006ad119: { // 0x6ad119: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ad11a: { // 0x6ad11a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ad11b: { // 0x6ad11b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006ad11c: { // 0x6ad11c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006b0670(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b0670: { // 0x6b0670: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L006b0674: { // 0x6b0674: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L006b0677: { // 0x6b0677: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b0679: { // 0x6b0679: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b067a: { // 0x6b067a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b067b: { // 0x6b067b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006b067d: { // 0x6b067d: 745b JZ 0x006b06da
    if(integer::condition("JZ",flags)) goto L006b06da;
  }
  L006b067f: { // 0x6b067f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006b0683: { // 0x6b0683: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L006b0686: { // 0x6b0686: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b0687: { // 0x6b0687: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006b068d: { // 0x6b068d: e8be9afaff CALL 0x0065a150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a150u,7014034u); flags=s.arithmetic_flags;
  }
  L006b0692: { // 0x6b0692: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006b0694: { // 0x6b0694: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b0696: { // 0x6b0696: 743a JZ 0x006b06d2
    if(integer::condition("JZ",flags)) goto L006b06d2;
  }
  L006b0698: { // 0x6b0698: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b069a: { // 0x6b069a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b069c: { // 0x6b069c: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7014047u); flags=s.arithmetic_flags;
  }
  L006b069f: { // 0x6b069f: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L006b06a2: { // 0x6b06a2: 752e JNZ 0x006b06d2
    if(integer::condition("JNZ",flags)) goto L006b06d2;
  }
  L006b06a4: { // 0x6b06a4: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L006b06aa: { // 0x6b06aa: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L006b06ae: { // 0x6b06ae: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L006b06b1: { // 0x6b06b1: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L006b06b3: { // 0x6b06b3: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L006b06bb: { // 0x6b06bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b06bc: { // 0x6b06bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b06bd: { // 0x6b06bd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b06bf: { // 0x6b06bf: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L006b06c7: { // 0x6b06c7: e8640ddcff CALL 0x00471430
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471430u,7014092u); flags=s.arithmetic_flags;
  }
  L006b06cc: { // 0x6b06cc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b06ce: { // 0x6b06ce: 7402 JZ 0x006b06d2
    if(integer::condition("JZ",flags)) goto L006b06d2;
  }
  L006b06d0: { // 0x6b06d0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006b06d2: { // 0x6b06d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b06d3: { // 0x6b06d3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b06d5: { // 0x6b06d5: e856c9ffff CALL 0x006ad030
    s.arithmetic_flags=flags; invoke(m,s,f,0x006ad030u,7014106u); flags=s.arithmetic_flags;
  }
  L006b06da: { // 0x6b06da: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  L006b06dd: { // 0x6b06dd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b06df: { // 0x6b06df: 742f JZ 0x006b0710
    if(integer::condition("JZ",flags)) goto L006b0710;
  }
  L006b06e1: { // 0x6b06e1: 8b7754 MOV ESI,dword ptr [EDI + 0x54]
    s.si = m.r32((s.di+0x00000054u));
  }
  L006b06e4: { // 0x6b06e4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b06e6: { // 0x6b06e6: 7428 JZ 0x006b0710
    if(integer::condition("JZ",flags)) goto L006b0710;
  }
  L006b06e8: { // 0x6b06e8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b06ea: { // 0x6b06ea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b06ec: { // 0x6b06ec: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7014130u); flags=s.arithmetic_flags;
  }
  L006b06f2: { // 0x6b06f2: 8b88ac050000 MOV ECX,dword ptr [EAX + 0x5ac]
    s.cx = m.r32((s.ax+0x000005acu));
  }
  L006b06f8: { // 0x6b06f8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b06fa: { // 0x6b06fa: 7e2c JLE 0x006b0728
    if(integer::condition("JLE",flags)) goto L006b0728;
  }
  L006b06fc: { // 0x6b06fc: 8b8654020000 MOV EAX,dword ptr [ESI + 0x254]
    s.ax = m.r32((s.si+0x00000254u));
  }
  L006b0702: { // 0x6b0702: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b0704: { // 0x6b0704: 7f22 JG 0x006b0728
    if(integer::condition("JG",flags)) goto L006b0728;
  }
  L006b0706: { // 0x6b0706: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  L006b070c: { // 0x6b070c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b070e: { // 0x6b070e: 75d8 JNZ 0x006b06e8
    if(integer::condition("JNZ",flags)) goto L006b06e8;
  }
  L006b0710: { // 0x6b0710: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b0712: { // 0x6b0712: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b0714: { // 0x6b0714: e817c9ffff CALL 0x006ad030
    s.arithmetic_flags=flags; invoke(m,s,f,0x006ad030u,7014169u); flags=s.arithmetic_flags;
  }
  L006b0719: { // 0x6b0719: c6878000000001 MOV byte ptr [EDI + 0x80],0x1
    m.w8((s.di+0x00000080u), 0x00000001u);
  }
  L006b0720: { // 0x6b0720: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b0721: { // 0x6b0721: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b0722: { // 0x6b0722: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006b0725: { // 0x6b0725: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b0728: { // 0x6b0728: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b072a: { // 0x6b072a: e8d1eaffff CALL 0x006af200
    s.arithmetic_flags=flags; invoke(m,s,f,0x006af200u,7014191u); flags=s.arithmetic_flags;
  }
  L006b072f: { // 0x6b072f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b0730: { // 0x6b0730: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b0731: { // 0x6b0731: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006b0734: { // 0x6b0734: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006b1d20(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b1d20: { // 0x6b1d20: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L006b1d24: { // 0x6b1d24: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b1d25: { // 0x6b1d25: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b1d26: { // 0x6b1d26: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b1d27: { // 0x6b1d27: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b1d29: { // 0x6b1d29: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006b1d2b: { // 0x6b1d2b: 746b JZ 0x006b1d98
    if(integer::condition("JZ",flags)) goto L006b1d98;
  }
  L006b1d2d: { // 0x6b1d2d: 8b453c MOV EAX,dword ptr [EBP + 0x3c]
    s.ax = m.r32((s.bp+0x0000003cu));
  }
  L006b1d30: { // 0x6b1d30: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b1d32: { // 0x6b1d32: 756b JNZ 0x006b1d9f
    if(integer::condition("JNZ",flags)) goto L006b1d9f;
  }
  L006b1d34: { // 0x6b1d34: 8b7d54 MOV EDI,dword ptr [EBP + 0x54]
    s.di = m.r32((s.bp+0x00000054u));
  }
  L006b1d37: { // 0x6b1d37: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b1d39: { // 0x6b1d39: 745d JZ 0x006b1d98
    if(integer::condition("JZ",flags)) goto L006b1d98;
  }
  L006b1d3b: { // 0x6b1d3b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006b1d3f: { // 0x6b1d3f: 8b0d0ce0a100 MOV ECX,dword ptr [0x00a1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  L006b1d45: { // 0x6b1d45: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b1d46: { // 0x6b1d46: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006b1d48: { // 0x6b1d48: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L006b1d4b: { // 0x6b1d4b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006b1d4d: { // 0x6b1d4d: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L006b1d52: { // 0x6b1d52: c1fe10 SAR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
  L006b1d55: { // 0x6b1d55: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006b1d58: { // 0x6b1d58: 8b8fb4010000 MOV ECX,dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006b1d5e: { // 0x6b1d5e: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L006b1d64: { // 0x6b1d64: 8b99f0540000 MOV EBX,dword ptr [ECX + 0x54f0]
    s.bx = m.r32((s.cx+0x000054f0u));
  }
  L006b1d6a: { // 0x6b1d6a: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L006b1d6d: { // 0x6b1d6d: 7409 JZ 0x006b1d78
    if(integer::condition("JZ",flags)) goto L006b1d78;
  }
  L006b1d6f: { // 0x6b1d6f: 8b15cca5a100 MOV EDX,dword ptr [0x00a1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  L006b1d75: { // 0x6b1d75: 8b149a MOV EDX,dword ptr [EDX + EBX*0x4]
    s.dx = m.r32((s.dx+(s.bx * 0x00000004u)));
  }
  L006b1d78: { // 0x6b1d78: 8b4d24 MOV ECX,dword ptr [EBP + 0x24]
    s.cx = m.r32((s.bp+0x00000024u));
  }
  L006b1d7b: { // 0x6b1d7b: 8a89ef000000 MOV CL,byte ptr [ECX + 0xef]
    s.cx = with_al(s.cx, m.r8((s.cx+0x000000efu)));
  }
  L006b1d81: { // 0x6b1d81: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b1d82: { // 0x6b1d82: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b1d83: { // 0x6b1d83: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b1d84: { // 0x6b1d84: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b1d86: { // 0x6b1d86: e835080000 CALL 0x006b25c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b25c0u,7019915u); flags=s.arithmetic_flags;
  }
  L006b1d8b: { // 0x6b1d8b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b1d8d: { // 0x6b1d8d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b1d8e: { // 0x6b1d8e: 7408 JZ 0x006b1d98
    if(integer::condition("JZ",flags)) goto L006b1d98;
  }
  L006b1d90: { // 0x6b1d90: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b1d91: { // 0x6b1d91: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006b1d93: { // 0x6b1d93: e898b2ffff CALL 0x006ad030
    s.arithmetic_flags=flags; invoke(m,s,f,0x006ad030u,7019928u); flags=s.arithmetic_flags;
  }
  L006b1d98: { // 0x6b1d98: 8b453c MOV EAX,dword ptr [EBP + 0x3c]
    s.ax = m.r32((s.bp+0x0000003cu));
  }
  L006b1d9b: { // 0x6b1d9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b1d9d: { // 0x6b1d9d: 742f JZ 0x006b1dce
    if(integer::condition("JZ",flags)) goto L006b1dce;
  }
  L006b1d9f: { // 0x6b1d9f: 8b7554 MOV ESI,dword ptr [EBP + 0x54]
    s.si = m.r32((s.bp+0x00000054u));
  }
  L006b1da2: { // 0x6b1da2: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b1da4: { // 0x6b1da4: 7428 JZ 0x006b1dce
    if(integer::condition("JZ",flags)) goto L006b1dce;
  }
  L006b1da6: { // 0x6b1da6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b1da8: { // 0x6b1da8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b1daa: { // 0x6b1daa: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7019952u); flags=s.arithmetic_flags;
  }
  L006b1db0: { // 0x6b1db0: 8b88ac050000 MOV ECX,dword ptr [EAX + 0x5ac]
    s.cx = m.r32((s.ax+0x000005acu));
  }
  L006b1db6: { // 0x6b1db6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b1db8: { // 0x6b1db8: 7e2a JLE 0x006b1de4
    if(integer::condition("JLE",flags)) goto L006b1de4;
  }
  L006b1dba: { // 0x6b1dba: 8b8654020000 MOV EAX,dword ptr [ESI + 0x254]
    s.ax = m.r32((s.si+0x00000254u));
  }
  L006b1dc0: { // 0x6b1dc0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b1dc2: { // 0x6b1dc2: 7f20 JG 0x006b1de4
    if(integer::condition("JG",flags)) goto L006b1de4;
  }
  L006b1dc4: { // 0x6b1dc4: 8bb6c8040000 MOV ESI,dword ptr [ESI + 0x4c8]
    s.si = m.r32((s.si+0x000004c8u));
  }
  L006b1dca: { // 0x6b1dca: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b1dcc: { // 0x6b1dcc: 75d8 JNZ 0x006b1da6
    if(integer::condition("JNZ",flags)) goto L006b1da6;
  }
  L006b1dce: { // 0x6b1dce: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b1dd0: { // 0x6b1dd0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006b1dd2: { // 0x6b1dd2: e859b2ffff CALL 0x006ad030
    s.arithmetic_flags=flags; invoke(m,s,f,0x006ad030u,7019991u); flags=s.arithmetic_flags;
  }
  L006b1dd7: { // 0x6b1dd7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b1dd8: { // 0x6b1dd8: c6858000000001 MOV byte ptr [EBP + 0x80],0x1
    m.w8((s.bp+0x00000080u), 0x00000001u);
  }
  L006b1ddf: { // 0x6b1ddf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b1de0: { // 0x6b1de0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b1de1: { // 0x6b1de1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006b1de4: { // 0x6b1de4: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006b1de6: { // 0x6b1de6: e815d4ffff CALL 0x006af200
    s.arithmetic_flags=flags; invoke(m,s,f,0x006af200u,7020011u); flags=s.arithmetic_flags;
  }
  L006b1deb: { // 0x6b1deb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b1dec: { // 0x6b1dec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b1ded: { // 0x6b1ded: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b1dee: { // 0x6b1dee: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
