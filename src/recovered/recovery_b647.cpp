#include "recovered/recovery_b647_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b647 {
namespace {
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000112f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112f0: { // 0x4112f0: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L004112f3: { // 0x4112f3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004112f4: { // 0x4112f4: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004112f7: { // 0x4112f7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004112f9: { // 0x4112f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00011290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411290: { // 0x411290: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00411294: { // 0x411294: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411295: { // 0x411295: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411296: { // 0x411296: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411297: { // 0x411297: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0041129a: { // 0x41129a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L0041129d: { // 0x41129d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0041129f: { // 0x41129f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004112a1: { // 0x4112a1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004112a3: { // 0x4112a3: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L004112a5: { // 0x4112a5: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L004112a8: { // 0x4112a8: 897b08 MOV dword ptr [EBX + 0x8],EDI
    m.w32((s.bx+0x00000008u), s.di);
  }
  L004112ab: { // 0x4112ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004112ac: { // 0x4112ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004112ad: { // 0x4112ad: 894b0c MOV dword ptr [EBX + 0xc],ECX
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L004112b0: { // 0x4112b0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004112b1: { // 0x4112b1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4264816u:f_00011370(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264592u:f_00011290(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
default:throw std::domain_error("recovery647 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006823e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006823e0: { // 0x6823e0: 83ec48 SUB ESP,0x48
    f.sp = integer::sub(f.sp,0x00000048u,32,flags);
  }
  L006823e3: { // 0x6823e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006823e4: { // 0x6823e4: 8b5c2454 MOV EBX,dword ptr [ESP + 0x54]
    s.bx = m.r32((f.sp+0x00000054u));
  }
  L006823e8: { // 0x6823e8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006823ea: { // 0x6823ea: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006823eb: { // 0x6823eb: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L006823ed: { // 0x6823ed: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006823ef: { // 0x6823ef: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006823f0: { // 0x6823f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006823f1: { // 0x6823f1: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006823f3: { // 0x6823f3: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6824950u); flags=s.arithmetic_flags;
  }
  L006823f6: { // 0x6823f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006823f8: { // 0x6823f8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006823fc: { // 0x6823fc: 750a JNZ 0x00682408
    if(integer::condition("JNZ",flags)) goto L00682408;
  }
  L006823fe: { // 0x6823fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006823ff: { // 0x6823ff: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00682401: { // 0x682401: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00682402: { // 0x682402: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00682405: { // 0x682405: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00682408: { // 0x682408: 8b7c245c MOV EDI,dword ptr [ESP + 0x5c]
    s.di = m.r32((f.sp+0x0000005cu));
  }
  L0068240c: { // 0x68240c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0068240e: { // 0x68240e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00682410: { // 0x682410: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00682411: { // 0x682411: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00682413: { // 0x682413: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00682414: { // 0x682414: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00682416: { // 0x682416: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6824985u); flags=s.arithmetic_flags;
  }
  L00682419: { // 0x682419: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0068241b: { // 0x68241b: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0068241f: { // 0x68241f: 7511 JNZ 0x00682432
    if(integer::condition("JNZ",flags)) goto L00682432;
  }
  L00682421: { // 0x682421: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00682423: { // 0x682423: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00682425: { // 0x682425: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),6825000u); flags=s.arithmetic_flags;
  }
  L00682428: { // 0x682428: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00682429: { // 0x682429: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0068242b: { // 0x68242b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0068242c: { // 0x68242c: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L0068242f: { // 0x68242f: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00682432: { // 0x682432: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00682434: { // 0x682434: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00682435: { // 0x682435: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00682436: { // 0x682436: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00682438: { // 0x682438: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),6825019u); flags=s.arithmetic_flags;
  }
  L0068243b: { // 0x68243b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0068243c: { // 0x68243c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0068243e: { // 0x68243e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00682440: { // 0x682440: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00682442: { // 0x682442: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00682446: { // 0x682446: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00682448: { // 0x682448: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6825035u); flags=s.arithmetic_flags;
  }
  L0068244b: { // 0x68244b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0068244c: { // 0x68244c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0068244e: { // 0x68244e: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00682450: { // 0x682450: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00682452: { // 0x682452: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00682456: { // 0x682456: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L0068245a: { // 0x68245a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0068245b: { // 0x68245b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0068245d: { // 0x68245d: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),6825056u); flags=s.arithmetic_flags;
  }
  L00682460: { // 0x682460: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00682462: { // 0x682462: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00682466: { // 0x682466: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00682469: { // 0x682469: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0068246d: { // 0x68246d: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00682470: { // 0x682470: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00682474: { // 0x682474: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L00682478: { // 0x682478: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0068247b: { // 0x68247b: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0068247d: { // 0x68247d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0068247e: { // 0x68247e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00682480: { // 0x682480: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00682484: { // 0x682484: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),6825095u); flags=s.arithmetic_flags;
  }
  L00682487: { // 0x682487: 8b6c245c MOV EBP,dword ptr [ESP + 0x5c]
    s.bp = m.r32((f.sp+0x0000005cu));
  }
  L0068248b: { // 0x68248b: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0068248f: { // 0x68248f: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L00682492: { // 0x682492: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00682495: { // 0x682495: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00682497: { // 0x682497: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00682498: { // 0x682498: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0068249a: { // 0x68249a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0068249c: { // 0x68249c: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0068249e: { // 0x68249e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006824a0: { // 0x6824a0: 0f9ec2 SETLE DL
    s.dx = with_al(s.dx, (integer::condition("SETLE",flags)?1u:0u));
  }
  L006824a3: { // 0x6824a3: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006824a4: { // 0x6824a4: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L006824a6: { // 0x6824a6: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L006824aa: { // 0x6824aa: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006824ac: { // 0x6824ac: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L006824b0: { // 0x6824b0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006824b1: { // 0x6824b1: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006824b3: { // 0x6824b3: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006824b5: { // 0x6824b5: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006824b7: { // 0x6824b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006824b9: { // 0x6824b9: 0f9ec2 SETLE DL
    s.dx = with_al(s.dx, (integer::condition("SETLE",flags)?1u:0u));
  }
  L006824bc: { // 0x6824bc: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006824bd: { // 0x6824bd: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L006824bf: { // 0x6824bf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006824c1: { // 0x6824c1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006824c3: { // 0x6824c3: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006824c7: { // 0x6824c7: 0f8e91000000 JLE 0x0068255e
    if(integer::condition("JLE",flags)) goto L0068255e;
  }
  L006824cd: { // 0x6824cd: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L006824d1: { // 0x6824d1: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L006824d3: { // 0x6824d3: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L006824d7: { // 0x6824d7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006824d9: { // 0x6824d9: c744245c00000000 MOV dword ptr [ESP + 0x5c],0x0
    m.w32((f.sp+0x0000005cu), 0x00000000u);
  }
  L006824e1: { // 0x6824e1: 034d04 ADD ECX,dword ptr [EBP + 0x4]
    s.cx = integer::add(s.cx,m.r32((s.bp+0x00000004u)),32,flags);
  }
  L006824e4: { // 0x6824e4: 0faf4c2414 IMUL ECX,dword ptr [ESP + 0x14]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L006824e9: { // 0x6824e9: 034d00 ADD ECX,dword ptr [EBP]
    s.cx = integer::add(s.cx,m.r32((s.bp)),32,flags);
  }
  L006824ec: { // 0x6824ec: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006824ee: { // 0x6824ee: 7e55 JLE 0x00682545
    if(integer::condition("JLE",flags)) goto L00682545;
  }
  L006824f0: { // 0x6824f0: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006824f2: { // 0x6824f2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006824f3: { // 0x6824f3: f77c2434 IDIV dword ptr [ESP + 0x34]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x00000034u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006824f7: { // 0x6824f7: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006824fb: { // 0x6824fb: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006824fd: { // 0x6824fd: 8b542468 MOV EDX,dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  L00682501: { // 0x682501: 0faf7c2418 IMUL EDI,dword ptr [ESP + 0x18]
    s.di = integer::imul(s.di,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L00682506: { // 0x682506: 8d1c10 LEA EBX,[EAX + EDX*0x1]
    s.bx = (s.ax+(s.dx * 0x00000001u));
  }
  L00682509: { // 0x682509: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0068250d: { // 0x68250d: 8d0c4a LEA ECX,[EDX + ECX*0x2]
    s.cx = (s.dx+(s.cx * 0x00000002u));
  }
  L00682510: { // 0x682510: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00682512: { // 0x682512: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00682515: { // 0x682515: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00682516: { // 0x682516: f77c2430 IDIV dword ptr [ESP + 0x30]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x00000030u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0068251a: { // 0x68251a: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0068251e: { // 0x68251e: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L00682520: { // 0x682520: 668b1450 MOV DX,word ptr [EAX + EDX*0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+(s.dx * 0x00000002u))));
  }
  L00682524: { // 0x682524: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L00682528: { // 0x682528: 668951fe MOV word ptr [ECX + -0x2],DX
    m.w16((s.cx-0x00000002u), (s.dx & 0xffffu));
  }
  L0068252c: { // 0x68252c: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L0068252f: { // 0x68252f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00682530: { // 0x682530: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00682531: { // 0x682531: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00682533: { // 0x682533: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L00682537: { // 0x682537: 7cd7 JL 0x00682510
    if(integer::condition("JL",flags)) goto L00682510;
  }
  L00682539: { // 0x682539: 8b7c2464 MOV EDI,dword ptr [ESP + 0x64]
    s.di = m.r32((f.sp+0x00000064u));
  }
  L0068253d: { // 0x68253d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00682541: { // 0x682541: 8b5c2460 MOV EBX,dword ptr [ESP + 0x60]
    s.bx = m.r32((f.sp+0x00000060u));
  }
  L00682545: { // 0x682545: 8b54246c MOV EDX,dword ptr [ESP + 0x6c]
    s.dx = m.r32((f.sp+0x0000006cu));
  }
  L00682549: { // 0x682549: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0068254c: { // 0x68254c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0068254d: { // 0x68254d: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0068254e: { // 0x68254e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00682550: { // 0x682550: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00682554: { // 0x682554: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L00682558: { // 0x682558: 0f8c79ffffff JL 0x006824d7
    if(integer::condition("JL",flags)) goto L006824d7;
  }
  L0068255e: { // 0x68255e: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00682560: { // 0x682560: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00682562: { // 0x682562: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),6825317u); flags=s.arithmetic_flags;
  }
  L00682565: { // 0x682565: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00682567: { // 0x682567: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00682569: { // 0x682569: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),6825324u); flags=s.arithmetic_flags;
  }
  L0068256c: { // 0x68256c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0068256d: { // 0x68256d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0068256e: { // 0x68256e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0068256f: { // 0x68256f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00682571: { // 0x682571: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00682572: { // 0x682572: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00682575: { // 0x682575: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
