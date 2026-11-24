#include "recovered/recovery_b729_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b729 {
namespace {
void f_002bf0c0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002bf0c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006bf0c0: { // 0x6bf0c0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006bf0c3: { // 0x6bf0c3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf0c4: { // 0x6bf0c4: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L006bf0c8: { // 0x6bf0c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006bf0c9: { // 0x6bf0c9: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006bf0cb: { // 0x6bf0cb: 8b8728020000 MOV EAX,dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L006bf0d1: { // 0x6bf0d1: c6870404000000 MOV byte ptr [EDI + 0x404],0x0
    m.w8((s.di+0x00000404u), 0x00000000u);
  }
  L006bf0d8: { // 0x6bf0d8: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006bf0da: { // 0x6bf0da: 0f84e2000000 JZ 0x006bf1c2
    if(integer::condition("JZ",flags)) goto L006bf1c2;
  }
  L006bf0e0: { // 0x6bf0e0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006bf0e2: { // 0x6bf0e2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006bf0e3: { // 0x6bf0e3: 747b JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf0e5: { // 0x6bf0e5: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L006bf0e7: { // 0x6bf0e7: 7531 JNZ 0x006bf11a
    if(integer::condition("JNZ",flags)) goto L006bf11a;
  }
  L006bf0e9: { // 0x6bf0e9: 8d8788000000 LEA EAX,[EDI + 0x88]
    s.ax = (s.di+0x00000088u);
  }
  L006bf0ef: { // 0x6bf0ef: 8b8f88000000 MOV ECX,dword ptr [EDI + 0x88]
    s.cx = m.r32((s.di+0x00000088u));
  }
  L006bf0f5: { // 0x6bf0f5: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006bf0f9: { // 0x6bf0f9: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006bf0fd: { // 0x6bf0fd: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006bf100: { // 0x6bf100: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006bf101: { // 0x6bf101: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006bf106: { // 0x6bf106: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006bf10a: { // 0x6bf10a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006bf10d: { // 0x6bf10d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006bf111: { // 0x6bf111: e87a63e8ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,7074070u); flags=s.arithmetic_flags;
  }
  L006bf116: { // 0x6bf116: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006bf118: { // 0x6bf118: eb48 JMP 0x006bf162
    goto L006bf162;
  }
  L006bf11a: { // 0x6bf11a: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L006bf11d: { // 0x6bf11d: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L006bf11f: { // 0x6bf11f: 7441 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf121: { // 0x6bf121: 8a4e7d MOV CL,byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L006bf124: { // 0x6bf124: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006bf126: { // 0x6bf126: 7438 JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf128: { // 0x6bf128: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L006bf12b: { // 0x6bf12b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006bf12d: { // 0x6bf12d: 7431 JZ 0x006bf160
    if(integer::condition("JZ",flags)) goto L006bf160;
  }
  L006bf12f: { // 0x6bf12f: c0e802 SHR AL,0x2
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L006bf132: { // 0x6bf132: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L006bf134: { // 0x6bf134: 8844241c MOV byte ptr [ESP + 0x1c],AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L006bf138: { // 0x6bf138: 7428 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf13a: { // 0x6bf13a: 8a8625030000 MOV AL,byte ptr [ESI + 0x325]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000325u)));
  }
  L006bf140: { // 0x6bf140: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L006bf142: { // 0x6bf142: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf144: { // 0x6bf144: 7402 JZ 0x006bf148
    if(integer::condition("JZ",flags)) goto L006bf148;
  }
  L006bf146: { // 0x6bf146: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006bf148: { // 0x6bf148: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L006bf14b: { // 0x6bf14b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bf14d: { // 0x6bf14d: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7074128u); flags=s.arithmetic_flags;
  }
  L006bf150: { // 0x6bf150: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L006bf153: { // 0x6bf153: 750d JNZ 0x006bf162
    if(integer::condition("JNZ",flags)) goto L006bf162;
  }
  L006bf155: { // 0x6bf155: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bf157: { // 0x6bf157: e8549ae4ff CALL 0x00508bb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00508bb0u,7074140u); flags=s.arithmetic_flags;
  }
  L006bf15c: { // 0x6bf15c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf15e: { // 0x6bf15e: 7402 JZ 0x006bf162
    if(integer::condition("JZ",flags)) goto L006bf162;
  }
  L006bf160: { // 0x6bf160: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006bf162: { // 0x6bf162: 8b8f38020000 MOV ECX,dword ptr [EDI + 0x238]
    s.cx = m.r32((s.di+0x00000238u));
  }
  L006bf168: { // 0x6bf168: 89b728020000 MOV dword ptr [EDI + 0x228],ESI
    m.w32((s.di+0x00000228u), s.si);
  }
  L006bf16e: { // 0x6bf16e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006bf170: { // 0x6bf170: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bf171: { // 0x6bf171: 740a JZ 0x006bf17d
    if(integer::condition("JZ",flags)) goto L006bf17d;
  }
  L006bf173: { // 0x6bf173: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006bf175: { // 0x6bf175: 7506 JNZ 0x006bf17d
    if(integer::condition("JNZ",flags)) goto L006bf17d;
  }
  L006bf177: { // 0x6bf177: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf178: { // 0x6bf178: e8130afcff CALL 0x0067fb90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0067fb90u,7074173u); flags=s.arithmetic_flags;
  }
  L006bf17d: { // 0x6bf17d: 8b8728020000 MOV EAX,dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L006bf183: { // 0x6bf183: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf185: { // 0x6bf185: 750a JNZ 0x006bf191
    if(integer::condition("JNZ",flags)) goto L006bf191;
  }
  L006bf187: { // 0x6bf187: c7871003000000000000 MOV dword ptr [EDI + 0x310],0x0
    m.w32((s.di+0x00000310u), 0x00000000u);
  }
  L006bf191: { // 0x6bf191: 8b875c020000 MOV EAX,dword ptr [EDI + 0x25c]
    s.ax = m.r32((s.di+0x0000025cu));
  }
  L006bf197: { // 0x6bf197: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bf199: { // 0x6bf199: 7427 JZ 0x006bf1c2
    if(integer::condition("JZ",flags)) goto L006bf1c2;
  }
  L006bf19b: { // 0x6bf19b: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006bf19d: { // 0x6bf19d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bf19e: { // 0x6bf19e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bf1a0: { // 0x6bf1a0: ff9054030000 CALL dword ptr [EAX + 0x354]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000354u)),7074214u); flags=s.arithmetic_flags;
  }
  L006bf1a6: { // 0x6bf1a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bf1a8: { // 0x6bf1a8: 7518 JNZ 0x006bf1c2
    if(integer::condition("JNZ",flags)) goto L006bf1c2;
  }
  L006bf1aa: { // 0x6bf1aa: 8b8f5c020000 MOV ECX,dword ptr [EDI + 0x25c]
    s.cx = m.r32((s.di+0x0000025cu));
  }
  L006bf1b0: { // 0x6bf1b0: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006bf1b2: { // 0x6bf1b2: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),7074232u); flags=s.arithmetic_flags;
  }
  L006bf1b8: { // 0x6bf1b8: c7875c02000000000000 MOV dword ptr [EDI + 0x25c],0x0
    m.w32((s.di+0x0000025cu), 0x00000000u);
  }
  L006bf1c2: { // 0x6bf1c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bf1c3: { // 0x6bf1c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bf1c4: { // 0x6bf1c4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006bf1c7: { // 0x6bf1c7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7073984u:f_002bf0c0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery729 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004401e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004401e0: { // 0x4401e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004401e1: { // 0x4401e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004401e3: { // 0x4401e3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004401e4: { // 0x4401e4: 83be9800000013 CMP dword ptr [ESI + 0x98],0x13
    (void)integer::sub(m.r32((s.si+0x00000098u)),0x00000013u,32,flags);
  }
  L004401eb: { // 0x4401eb: 740c JZ 0x004401f9
    if(integer::condition("JZ",flags)) goto L004401f9;
  }
  L004401ed: { // 0x4401ed: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004401ef: { // 0x4401ef: ff900c030000 CALL dword ptr [EAX + 0x30c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000030cu)),4456949u); flags=s.arithmetic_flags;
  }
  L004401f5: { // 0x4401f5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004401f7: { // 0x4401f7: 750f JNZ 0x00440208
    if(integer::condition("JNZ",flags)) goto L00440208;
  }
  L004401f9: { // 0x4401f9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004401fb: { // 0x4401fb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004401fc: { // 0x4401fc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004401fe: { // 0x4401fe: e8bdee2700 CALL 0x006bf0c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006bf0c0u,4456963u); flags=s.arithmetic_flags;
  }
  L00440203: { // 0x440203: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00440204: { // 0x440204: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00440205: { // 0x440205: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00440208: { // 0x440208: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0044020c: { // 0x44020c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0044020e: { // 0x44020e: 74eb JZ 0x004401fb
    if(integer::condition("JZ",flags)) goto L004401fb;
  }
  L00440210: { // 0x440210: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00440212: { // 0x440212: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00440214: { // 0x440214: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00440216: { // 0x440216: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),4456988u); flags=s.arithmetic_flags;
  }
  L0044021c: { // 0x44021c: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L0044021f: { // 0x44021f: 74da JZ 0x004401fb
    if(integer::condition("JZ",flags)) goto L004401fb;
  }
  L00440221: { // 0x440221: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00440223: { // 0x440223: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00440225: { // 0x440225: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00440227: { // 0x440227: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),4457005u); flags=s.arithmetic_flags;
  }
  L0044022d: { // 0x44022d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0044022f: { // 0x44022f: 8b91a0000000 MOV EDX,dword ptr [ECX + 0xa0]
    s.dx = m.r32((s.cx+0x000000a0u));
  }
  L00440235: { // 0x440235: 8a8274020000 MOV AL,byte ptr [EDX + 0x274]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000274u)));
  }
  L0044023b: { // 0x44023b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044023d: { // 0x44023d: 75bc JNZ 0x004401fb
    if(integer::condition("JNZ",flags)) goto L004401fb;
  }
  L0044023f: { // 0x44023f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00440241: { // 0x440241: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00440242: { // 0x440242: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00440244: { // 0x440244: ff9054030000 CALL dword ptr [EAX + 0x354]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000354u)),4457034u); flags=s.arithmetic_flags;
  }
  L0044024a: { // 0x44024a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044024c: { // 0x44024c: 75ad JNZ 0x004401fb
    if(integer::condition("JNZ",flags)) goto L004401fb;
  }
  L0044024e: { // 0x44024e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00440250: { // 0x440250: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00440252: { // 0x440252: e869ee2700 CALL 0x006bf0c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006bf0c0u,4457047u); flags=s.arithmetic_flags;
  }
  L00440257: { // 0x440257: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044025d: { // 0x44025d: 8a885e130000 MOV CL,byte ptr [EAX + 0x135e]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000135eu)));
  }
  L00440263: { // 0x440263: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00440265: { // 0x440265: 750a JNZ 0x00440271
    if(integer::condition("JNZ",flags)) goto L00440271;
  }
  L00440267: { // 0x440267: 8a8864130000 MOV CL,byte ptr [EAX + 0x1364]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001364u)));
  }
  L0044026d: { // 0x44026d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044026f: { // 0x44026f: 7492 JZ 0x00440203
    if(integer::condition("JZ",flags)) goto L00440203;
  }
  L00440271: { // 0x440271: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L00440277: { // 0x440277: e874450b00 CALL 0x004f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,4457084u); flags=s.arithmetic_flags;
  }
  L0044027c: { // 0x44027c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044027e: { // 0x44027e: 7583 JNZ 0x00440203
    if(integer::condition("JNZ",flags)) goto L00440203;
  }
  L00440280: { // 0x440280: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00440282: { // 0x440282: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00440284: { // 0x440284: ff9224030000 CALL dword ptr [EDX + 0x324]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000324u)),4457098u); flags=s.arithmetic_flags;
  }
  L0044028a: { // 0x44028a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044028c: { // 0x44028c: 0f8571ffffff JNZ 0x00440203
    if(integer::condition("JNZ",flags)) goto L00440203;
  }
  L00440292: { // 0x440292: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00440294: { // 0x440294: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00440296: { // 0x440296: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L00440298: { // 0x440298: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044029a: { // 0x44029a: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d0u)),4457120u); flags=s.arithmetic_flags;
  }
  L004402a0: { // 0x4402a0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004402a2: { // 0x4402a2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004402a4: { // 0x4402a4: ff92d4010000 CALL dword ptr [EDX + 0x1d4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001d4u)),4457130u); flags=s.arithmetic_flags;
  }
  L004402aa: { // 0x4402aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004402ab: { // 0x4402ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004402ac: { // 0x4402ac: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00501930(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00501930: { // 0x501930: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00501931: { // 0x501931: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00501933: { // 0x501933: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00501934: { // 0x501934: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00501938: { // 0x501938: 3bbe28020000 CMP EDI,dword ptr [ESI + 0x228]
    (void)integer::sub(s.di,m.r32((s.si+0x00000228u)),32,flags);
  }
  L0050193e: { // 0x50193e: 745e JZ 0x0050199e
    if(integer::condition("JZ",flags)) goto L0050199e;
  }
  L00501940: { // 0x501940: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00501943: { // 0x501943: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00501945: { // 0x501945: 7e57 JLE 0x0050199e
    if(integer::condition("JLE",flags)) goto L0050199e;
  }
  L00501947: { // 0x501947: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L0050194d: { // 0x50194d: c6867d05000000 MOV byte ptr [ESI + 0x57d],0x0
    m.w8((s.si+0x0000057du), 0x00000000u);
  }
  L00501954: { // 0x501954: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  L00501957: { // 0x501957: 740f JZ 0x00501968
    if(integer::condition("JZ",flags)) goto L00501968;
  }
  L00501959: { // 0x501959: 83f81c CMP EAX,0x1c
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  L0050195c: { // 0x50195c: 740a JZ 0x00501968
    if(integer::condition("JZ",flags)) goto L00501968;
  }
  L0050195e: { // 0x50195e: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L00501961: { // 0x501961: 7405 JZ 0x00501968
    if(integer::condition("JZ",flags)) goto L00501968;
  }
  L00501963: { // 0x501963: 83f81e CMP EAX,0x1e
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  L00501966: { // 0x501966: 750a JNZ 0x00501972
    if(integer::condition("JNZ",flags)) goto L00501972;
  }
  L00501968: { // 0x501968: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0050196a: { // 0x50196a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0050196c: { // 0x50196c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0050196e: { // 0x50196e: 6a1c PUSH 0x1c
    f.push(m,0x0000001cu);
  }
  L00501970: { // 0x501970: eb24 JMP 0x00501996
    goto L00501996;
  }
  L00501972: { // 0x501972: 8a86c3050000 MOV AL,byte ptr [ESI + 0x5c3]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005c3u)));
  }
  L00501978: { // 0x501978: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050197a: { // 0x50197a: 7412 JZ 0x0050198e
    if(integer::condition("JZ",flags)) goto L0050198e;
  }
  L0050197c: { // 0x50197c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0050197e: { // 0x50197e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501980: { // 0x501980: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501982: { // 0x501982: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00501984: { // 0x501984: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501986: { // 0x501986: ff92dc040000 CALL dword ptr [EDX + 0x4dc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000004dcu)),5249420u); flags=s.arithmetic_flags;
  }
  L0050198c: { // 0x50198c: eb10 JMP 0x0050199e
    goto L0050199e;
  }
  L0050198e: { // 0x50198e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00501990: { // 0x501990: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501992: { // 0x501992: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501994: { // 0x501994: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00501996: { // 0x501996: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501998: { // 0x501998: ff90dc040000 CALL dword ptr [EAX + 0x4dc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000004dcu)),5249438u); flags=s.arithmetic_flags;
  }
  L0050199e: { // 0x50199e: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L005019a4: { // 0x5019a4: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  L005019a7: { // 0x5019a7: 740f JZ 0x005019b8
    if(integer::condition("JZ",flags)) goto L005019b8;
  }
  L005019a9: { // 0x5019a9: 83f81c CMP EAX,0x1c
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  L005019ac: { // 0x5019ac: 740a JZ 0x005019b8
    if(integer::condition("JZ",flags)) goto L005019b8;
  }
  L005019ae: { // 0x5019ae: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L005019b1: { // 0x5019b1: 7405 JZ 0x005019b8
    if(integer::condition("JZ",flags)) goto L005019b8;
  }
  L005019b3: { // 0x5019b3: 83f81e CMP EAX,0x1e
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  L005019b6: { // 0x5019b6: 7514 JNZ 0x005019cc
    if(integer::condition("JNZ",flags)) goto L005019cc;
  }
  L005019b8: { // 0x5019b8: 8b8ea8050000 MOV ECX,dword ptr [ESI + 0x5a8]
    s.cx = m.r32((s.si+0x000005a8u));
  }
  L005019be: { // 0x5019be: 8a81cc050000 MOV AL,byte ptr [ECX + 0x5cc]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000005ccu)));
  }
  L005019c4: { // 0x5019c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005019c6: { // 0x5019c6: 0f84ad000000 JZ 0x00501a79
    if(integer::condition("JZ",flags)) goto L00501a79;
  }
  L005019cc: { // 0x5019cc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005019cd: { // 0x5019cd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005019cf: { // 0x5019cf: c786d0040000ffffffff MOV dword ptr [ESI + 0x4d0],0xffffffff
    m.w32((s.si+0x000004d0u), 0xffffffffu);
  }
  L005019d9: { // 0x5019d9: e8e2d61b00 CALL 0x006bf0c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006bf0c0u,5249502u); flags=s.arithmetic_flags;
  }
  L005019de: { // 0x5019de: 8b8694040000 MOV EAX,dword ptr [ESI + 0x494]
    s.ax = m.r32((s.si+0x00000494u));
  }
  L005019e4: { // 0x5019e4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005019e6: { // 0x5019e6: 0f8586000000 JNZ 0x00501a72
    if(integer::condition("JNZ",flags)) goto L00501a72;
  }
  L005019ec: { // 0x5019ec: 8b96a8050000 MOV EDX,dword ptr [ESI + 0x5a8]
    s.dx = m.r32((s.si+0x000005a8u));
  }
  L005019f2: { // 0x5019f2: 8a820c0c0000 MOV AL,byte ptr [EDX + 0xc0c]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000c0cu)));
  }
  L005019f8: { // 0x5019f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005019fa: { // 0x5019fa: 7476 JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L005019fc: { // 0x5019fc: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005019fe: { // 0x5019fe: 7410 JZ 0x00501a10
    if(integer::condition("JZ",flags)) goto L00501a10;
  }
  L00501a00: { // 0x501a00: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00501a02: { // 0x501a02: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00501a04: { // 0x501a04: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5249543u); flags=s.arithmetic_flags;
  }
  L00501a07: { // 0x501a07: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L00501a0a: { // 0x501a0a: 7504 JNZ 0x00501a10
    if(integer::condition("JNZ",flags)) goto L00501a10;
  }
  L00501a0c: { // 0x501a0c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00501a0e: { // 0x501a0e: eb02 JMP 0x00501a12
    goto L00501a12;
  }
  L00501a10: { // 0x501a10: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00501a12: { // 0x501a12: 8b8ea8050000 MOV ECX,dword ptr [ESI + 0x5a8]
    s.cx = m.r32((s.si+0x000005a8u));
  }
  L00501a18: { // 0x501a18: 8a89120c0000 MOV CL,byte ptr [ECX + 0xc12]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000c12u)));
  }
  L00501a1e: { // 0x501a1e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00501a20: { // 0x501a20: 752f JNZ 0x00501a51
    if(integer::condition("JNZ",flags)) goto L00501a51;
  }
  L00501a22: { // 0x501a22: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00501a24: { // 0x501a24: 7427 JZ 0x00501a4d
    if(integer::condition("JZ",flags)) goto L00501a4d;
  }
  L00501a26: { // 0x501a26: 8b9018040000 MOV EDX,dword ptr [EAX + 0x418]
    s.dx = m.r32((s.ax+0x00000418u));
  }
  L00501a2c: { // 0x501a2c: 388a16120000 CMP byte ptr [EDX + 0x1216],CL
    (void)integer::sub(m.r8((s.dx+0x00001216u)),(s.cx & 0xffu),8,flags);
  }
  L00501a32: { // 0x501a32: 7419 JZ 0x00501a4d
    if(integer::condition("JZ",flags)) goto L00501a4d;
  }
  L00501a34: { // 0x501a34: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00501a36: { // 0x501a36: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00501a38: { // 0x501a38: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00501a39: { // 0x501a39: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501a3b: { // 0x501a3b: ff9010040000 CALL dword ptr [EAX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000410u)),5249601u); flags=s.arithmetic_flags;
  }
  L00501a41: { // 0x501a41: c6867e05000000 MOV byte ptr [ESI + 0x57e],0x0
    m.w8((s.si+0x0000057eu), 0x00000000u);
  }
  L00501a48: { // 0x501a48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00501a49: { // 0x501a49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00501a4a: { // 0x501a4a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00501a4d: { // 0x501a4d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00501a4f: { // 0x501a4f: 7421 JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L00501a51: { // 0x501a51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00501a53: { // 0x501a53: 741d JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L00501a55: { // 0x501a55: 8b8818040000 MOV ECX,dword ptr [EAX + 0x418]
    s.cx = m.r32((s.ax+0x00000418u));
  }
  L00501a5b: { // 0x501a5b: 8a8119120000 MOV AL,byte ptr [ECX + 0x1219]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001219u)));
  }
  L00501a61: { // 0x501a61: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00501a63: { // 0x501a63: 740d JZ 0x00501a72
    if(integer::condition("JZ",flags)) goto L00501a72;
  }
  L00501a65: { // 0x501a65: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00501a67: { // 0x501a67: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00501a69: { // 0x501a69: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00501a6a: { // 0x501a6a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00501a6c: { // 0x501a6c: ff9210040000 CALL dword ptr [EDX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000410u)),5249650u); flags=s.arithmetic_flags;
  }
  L00501a72: { // 0x501a72: c6867e05000000 MOV byte ptr [ESI + 0x57e],0x0
    m.w8((s.si+0x0000057eu), 0x00000000u);
  }
  L00501a79: { // 0x501a79: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00501a7a: { // 0x501a7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00501a7b: { // 0x501a7b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
