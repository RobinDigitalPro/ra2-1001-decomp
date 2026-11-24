#include "recovered/recovery_b668_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b668 {
namespace {
void f_000e21c0(Memory&,State&,Frame&,const Operations&);
void f_00290460(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_000e0030(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000e21c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e21c0: { // 0x4e21c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e21c1: { // 0x4e21c1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e21c2: { // 0x4e21c2: 8b74240c MOV ESI, dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L004e21c6: { // 0x4e21c6: 8b4610 MOV EAX, dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004e21c9: { // 0x4e21c9: 8b8848010000 MOV ECX, dword ptr [EAX + 0x148]
    s.cx = m.r32((s.ax+0x00000148u));
  }
  L004e21cf: { // 0x4e21cf: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L004e21d3: { // 0x4e21d3: 8d8e18020000 LEA ECX, [ESI + 0x218]
    s.cx = (s.si+0x00000218u);
  }
  L004e21d9: { // 0x4e21d9: e882e21a00 CALL 0x690460
    s.arithmetic_flags=flags; invoke(m,s,f,0x00690460u,5120478u); flags=s.arithmetic_flags;
  }
  L004e21de: { // 0x4e21de: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L004e21e2: { // 0x4e21e2: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004e21e6: { // 0x4e21e6: d84c2404 FMUL dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.multiply32(m.r32(address));
  }
  L004e21ea: { // 0x4e21ea: da8628020000 FIADD dword ptr [ESI + 0x228]
    const auto address=(s.si+0x00000228u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L004e21f0: { // 0x4e21f0: e85b882800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5120501u); flags=s.arithmetic_flags;
  }
  L004e21f5: { // 0x4e21f5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e21f6: { // 0x4e21f6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004e21f7: { // 0x4e21f7: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00290460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00690460: { // 0x690460: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00690461: { // 0x690461: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00690462: { // 0x690462: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00690463: { // 0x690463: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00690464: { // 0x690464: 8b3d3c86aa00 MOV EDI,dword ptr [0x00aa863c]
    s.di = m.r32((0x00aa863cu));
  }
  L0069046a: { // 0x69046a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0069046c: { // 0x69046c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0069046e: { // 0x69046e: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L00690472: { // 0x690472: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L00690474: { // 0x690474: bb04000000 MOV EBX,0x4
    s.bx = 0x00000004u;
  }
  L00690479: { // 0x690479: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
  L0069047b: { // 0x69047b: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00690481: { // 0x690481: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00690483: { // 0x690483: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00690486: { // 0x690486: 751a JNZ 0x006904a2
    if(integer::condition("JNZ",flags)) goto L006904a2;
  }
  L00690488: { // 0x690488: 8b0437 MOV EAX,dword ptr [EDI + ESI*0x1]
    s.ax = m.r32((s.di+(s.si * 0x00000001u)));
  }
  L0069048b: { // 0x69048b: db80b8000000 FILD dword ptr [EAX + 0xb8]
    const auto address=(s.ax+0x000000b8u);
    s.fp.load_integer32(m.r32(address));
  }
  L00690491: { // 0x690491: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L00690493: { // 0x690493: da44240c FIADD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00690497: { // 0x690497: e8b4a50d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6882460u); flags=s.arithmetic_flags;
  }
  L0069049c: { // 0x69049c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0069049e: { // 0x69049e: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L006904a2: { // 0x6904a2: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L006904a5: { // 0x6904a5: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L006904a6: { // 0x6904a6: 75d1 JNZ 0x00690479
    if(integer::condition("JNZ",flags)) goto L00690479;
  }
  L006904a8: { // 0x6904a8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006904a9: { // 0x6904a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006904aa: { // 0x6904aa: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006904ac: { // 0x6904ac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006904ad: { // 0x6904ad: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006904ae: { // 0x6904ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e0030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0030: { // 0x4e0030: a1ac1c8200 MOV EAX, dword ptr [0x821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L004e0035: { // 0x4e0035: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0037: { // 0x4e0037: 7407 JZ 0x4e0040
    if(integer::condition("JZ",flags)) goto L004e0040;
  }
  L004e0039: { // 0x4e0039: c6807d0d000001 MOV byte ptr [EAX + 0xd7d], 1
    m.w8((s.ax+0x00000d7du), 1u);
  }
  L004e0040: { // 0x4e0040: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004e0044: { // 0x4e0044: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0046: { // 0x4e0046: 7413 JZ 0x4e005b
    if(integer::condition("JZ",flags)) goto L004e005b;
  }
  L004e0048: { // 0x4e0048: 83790c02 CMP dword ptr [ECX + 0xc], 2
    (void)integer::sub(m.r32((s.cx+0x0000000cu)),2u,32,flags);
  }
  L004e004c: { // 0x4e004c: 7403 JZ 0x4e0051
    if(integer::condition("JZ",flags)) goto L004e0051;
  }
  L004e004e: { // 0x4e004e: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004e0051: { // 0x4e0051: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e0056: { // 0x4e0056: e8557a0700 CALL 0x557ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557ab0u,5111899u); flags=s.arithmetic_flags;
  }
  L004e005b: { // 0x4e005b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5120448u:f_000e21c0(m,s,child,{});break;
case 6882400u:f_00290460(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5111856u:f_000e0030(m,s,child,{});break;
default:throw std::domain_error("recovery668 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00494430(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00494430: { // 0x494430: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00494435: { // 0x494435: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00494436: { // 0x494436: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00494437: { // 0x494437: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00494439: { // 0x494439: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049443f: { // 0x49443f: a3d49f8300 MOV [0x00839fd4],EAX
    m.w32((0x00839fd4u), s.ax);
  }
  L00494444: { // 0x494444: 8b5124 MOV EDX,dword ptr [ECX + 0x24]
    s.dx = m.r32((s.cx+0x00000024u));
  }
  L00494447: { // 0x494447: 8d4124 LEA EAX,[ECX + 0x24]
    s.ax = (s.cx+0x00000024u);
  }
  L0049444a: { // 0x49444a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049444b: { // 0x49444b: ff5218 CALL dword ptr [EDX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000018u)),4801614u); flags=s.arithmetic_flags;
  }
  L0049444e: { // 0x49444e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00494450: { // 0x494450: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00494452: { // 0x494452: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00494454: { // 0x494454: 0f9ec1 SETLE CL
    s.cx = with_al(s.cx, (integer::condition("SETLE",flags)?1u:0u));
  }
  L00494457: { // 0x494457: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00494458: { // 0x494458: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0049445d: { // 0x49445d: 23c1 AND EAX,ECX
    s.ax = integer::logical((s.ax)&(s.cx),32,flags);
  }
  L0049445f: { // 0x49445f: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00494461: { // 0x494461: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00494467: { // 0x494467: 83b9c8070000ff CMP dword ptr [ECX + 0x7c8],-0x1
    (void)integer::sub(m.r32((s.cx+0x000007c8u)),0xffffffffu,32,flags);
  }
  L0049446e: { // 0x49446e: 7523 JNZ 0x00494493
    if(integer::condition("JNZ",flags)) goto L00494493;
  }
  L00494470: { // 0x494470: 8b81d0070000 MOV EAX,dword ptr [ECX + 0x7d0]
    s.ax = m.r32((s.cx+0x000007d0u));
  }
  L00494476: { // 0x494476: 8b89c8070000 MOV ECX,dword ptr [ECX + 0x7c8]
    s.cx = m.r32((s.cx+0x000007c8u));
  }
  L0049447c: { // 0x49447c: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L0049447f: { // 0x49447f: 740e JZ 0x0049448f
    if(integer::condition("JZ",flags)) goto L0049448f;
  }
  L00494481: { // 0x494481: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L00494487: { // 0x494487: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00494489: { // 0x494489: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0049448b: { // 0x49448b: 7d15 JGE 0x004944a2
    if(integer::condition("JGE",flags)) goto L004944a2;
  }
  L0049448d: { // 0x49448d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049448f: { // 0x49448f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00494491: { // 0x494491: 740f JZ 0x004944a2
    if(integer::condition("JZ",flags)) goto L004944a2;
  }
  L00494493: { // 0x494493: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00494495: { // 0x494495: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049449a: { // 0x49449a: 885e08 MOV byte ptr [ESI + 0x8],BL
    m.w8((s.si+0x00000008u), (s.bx & 0xffu));
  }
  L0049449d: { // 0x49449d: e88ebb0400 CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,4801698u); flags=s.arithmetic_flags;
  }
  L004944a2: { // 0x4944a2: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L004944a5: { // 0x4944a5: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L004944a7: { // 0x4944a7: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L004944a9: { // 0x4944a9: 0f8484000000 JZ 0x00494533
    if(integer::condition("JZ",flags)) goto L00494533;
  }
  L004944af: { // 0x4944af: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  L004944b3: { // 0x4944b3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004944b5: { // 0x4944b5: 7409 JZ 0x004944c0
    if(integer::condition("JZ",flags)) goto L004944c0;
  }
  L004944b7: { // 0x4944b7: c6460a00 MOV byte ptr [ESI + 0xa],0x0
    m.w8((s.si+0x0000000au), 0x00000000u);
  }
  L004944bb: { // 0x4944bb: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004944be: { // 0x4944be: eb5e JMP 0x0049451e
    goto L0049451e;
  }
  L004944c0: { // 0x4944c0: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L004944c3: { // 0x4944c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004944c5: { // 0x4944c5: 7404 JZ 0x004944cb
    if(integer::condition("JZ",flags)) goto L004944cb;
  }
  L004944c7: { // 0x4944c7: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004944c8: { // 0x4944c8: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L004944cb: { // 0x4944cb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004944cd: { // 0x4944cd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004944cf: { // 0x4944cf: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004944d1: { // 0x4944d1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004944d3: { // 0x4944d3: 0f9ec2 SETLE DL
    s.dx = with_al(s.dx, (integer::condition("SETLE",flags)?1u:0u));
  }
  L004944d6: { // 0x4944d6: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004944d7: { // 0x4944d7: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L004944da: { // 0x4944da: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L004944dd: { // 0x4944dd: 89560c MOV dword ptr [ESI + 0xc],EDX
    m.w32((s.si+0x0000000cu), s.dx);
  }
  L004944e0: { // 0x4944e0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004944e1: { // 0x4944e1: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004944e3: { // 0x4944e3: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004944e5: { // 0x4944e5: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L004944e8: { // 0x4944e8: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004944ea: { // 0x4944ea: 7d04 JGE 0x004944f0
    if(integer::condition("JGE",flags)) goto L004944f0;
  }
  L004944ec: { // 0x4944ec: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004944ee: { // 0x4944ee: eb0c JMP 0x004944fc
    goto L004944fc;
  }
  L004944f0: { // 0x4944f0: 3d8f000000 CMP EAX,0x8f
    (void)integer::sub(s.ax,0x0000008fu,32,flags);
  }
  L004944f5: { // 0x4944f5: 7e05 JLE 0x004944fc
    if(integer::condition("JLE",flags)) goto L004944fc;
  }
  L004944f7: { // 0x4944f7: b88f000000 MOV EAX,0x8f
    s.ax = 0x0000008fu;
  }
  L004944fc: { // 0x4944fc: 394e04 CMP dword ptr [ESI + 0x4],ECX
    (void)integer::sub(m.r32((s.si+0x00000004u)),s.cx,32,flags);
  }
  L004944ff: { // 0x4944ff: 7e02 JLE 0x00494503
    if(integer::condition("JLE",flags)) goto L00494503;
  }
  L00494501: { // 0x494501: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00494503: { // 0x494503: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00494506: { // 0x494506: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00494508: { // 0x494508: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0049450a: { // 0x49450a: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L0049450d: { // 0x49450d: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L0049450f: { // 0x49450f: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00494511: { // 0x494511: 740b JZ 0x0049451e
    if(integer::condition("JZ",flags)) goto L0049451e;
  }
  L00494513: { // 0x494513: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00494515: { // 0x494515: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L00494518: { // 0x494518: 885e0a MOV byte ptr [ESI + 0xa],BL
    m.w8((s.si+0x0000000au), (s.bx & 0xffu));
  }
  L0049451b: { // 0x49451b: 884609 MOV byte ptr [ESI + 0x9],AL
    m.w8((s.si+0x00000009u), (s.ax & 0xffu));
  }
  L0049451e: { // 0x49451e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00494520: { // 0x494520: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00494525: { // 0x494525: 885e08 MOV byte ptr [ESI + 0x8],BL
    m.w8((s.si+0x00000008u), (s.bx & 0xffu));
  }
  L00494528: { // 0x494528: e803bb0400 CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,4801837u); flags=s.arithmetic_flags;
  }
  L0049452d: { // 0x49452d: 881d04f78100 MOV byte ptr [0x0081f704],BL
    m.w8((0x0081f704u), (s.bx & 0xffu));
  }
  L00494533: { // 0x494533: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00494534: { // 0x494534: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00494535: { // 0x494535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
