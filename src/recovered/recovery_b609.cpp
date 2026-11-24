#include "recovered/recovery_b609_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b609 {
namespace {
void f_000e21c0(Memory&,State&,Frame&,const Operations&);
void f_00290460(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5120448u:f_000e21c0(m,s,child,{});break;
case 6882400u:f_00290460(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery609 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0041d490(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));std::array<std::uint8_t,24> jump_bytes{{186,212,65,0,204,212,65,0,222,212,65,0,240,212,65,0,2,213,65,0,20,213,65,0}};ra2::recovered::leaf::Memory jump_table(jump_bytes.data(),0x41d524u,24u);Memory m=original;m.add(jump_table);m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041d490: { // 0x41d490: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0041d494: { // 0x41d494: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041d495: { // 0x41d495: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0041d497: { // 0x41d497: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041d498: { // 0x41d498: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041d49a: { // 0x41d49a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041d49c: { // 0x41d49c: 747f JZ 0x0041d51d
    if(integer::condition("JZ",flags)) goto L0041d51d;
  }
  L0041d49e: { // 0x41d49e: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L0041d4a1: { // 0x41d4a1: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L0041d4a4: { // 0x41d4a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041d4a5: { // 0x41d4a5: ff5118 CALL dword ptr [ECX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000018u)),4314280u); flags=s.arithmetic_flags;
  }
  L0041d4a8: { // 0x41d4a8: 8b8ee8000000 MOV ECX,dword ptr [ESI + 0xe8]
    s.cx = m.r32((s.si+0x000000e8u));
  }
  L0041d4ae: { // 0x41d4ae: 83f905 CMP ECX,0x5
    (void)integer::sub(s.cx,0x00000005u,32,flags);
  }
  L0041d4b1: { // 0x41d4b1: 776a JA 0x0041d51d
    if(integer::condition("JA",flags)) goto L0041d51d;
  }
  L0041d4b3: { // 0x41d4b3: ff248d24d54100 JMP dword ptr [ECX*0x4 + 0x41d524]
    switch(m.r32(((s.cx * 0x00000004u)+0x0041d524u))){
    case 0x0041d490u: goto L0041d490;
    case 0x0041d494u: goto L0041d494;
    case 0x0041d495u: goto L0041d495;
    case 0x0041d497u: goto L0041d497;
    case 0x0041d498u: goto L0041d498;
    case 0x0041d49au: goto L0041d49a;
    case 0x0041d49cu: goto L0041d49c;
    case 0x0041d49eu: goto L0041d49e;
    case 0x0041d4a1u: goto L0041d4a1;
    case 0x0041d4a4u: goto L0041d4a4;
    case 0x0041d4a5u: goto L0041d4a5;
    case 0x0041d4a8u: goto L0041d4a8;
    case 0x0041d4aeu: goto L0041d4ae;
    case 0x0041d4b1u: goto L0041d4b1;
    case 0x0041d4b3u: goto L0041d4b3;
    case 0x0041d4bau: goto L0041d4ba;
    case 0x0041d4c0u: goto L0041d4c0;
    case 0x0041d4c1u: goto L0041d4c1;
    case 0x0041d4c3u: goto L0041d4c3;
    case 0x0041d4c6u: goto L0041d4c6;
    case 0x0041d4c8u: goto L0041d4c8;
    case 0x0041d4c9u: goto L0041d4c9;
    case 0x0041d4ccu: goto L0041d4cc;
    case 0x0041d4d2u: goto L0041d4d2;
    case 0x0041d4d3u: goto L0041d4d3;
    case 0x0041d4d5u: goto L0041d4d5;
    case 0x0041d4d8u: goto L0041d4d8;
    case 0x0041d4dau: goto L0041d4da;
    case 0x0041d4dbu: goto L0041d4db;
    case 0x0041d4deu: goto L0041d4de;
    case 0x0041d4e4u: goto L0041d4e4;
    case 0x0041d4e5u: goto L0041d4e5;
    case 0x0041d4e7u: goto L0041d4e7;
    case 0x0041d4eau: goto L0041d4ea;
    case 0x0041d4ecu: goto L0041d4ec;
    case 0x0041d4edu: goto L0041d4ed;
    case 0x0041d4f0u: goto L0041d4f0;
    case 0x0041d4f6u: goto L0041d4f6;
    case 0x0041d4f7u: goto L0041d4f7;
    case 0x0041d4f9u: goto L0041d4f9;
    case 0x0041d4fcu: goto L0041d4fc;
    case 0x0041d4feu: goto L0041d4fe;
    case 0x0041d4ffu: goto L0041d4ff;
    case 0x0041d502u: goto L0041d502;
    case 0x0041d508u: goto L0041d508;
    case 0x0041d509u: goto L0041d509;
    case 0x0041d50bu: goto L0041d50b;
    case 0x0041d50eu: goto L0041d50e;
    case 0x0041d510u: goto L0041d510;
    case 0x0041d511u: goto L0041d511;
    case 0x0041d514u: goto L0041d514;
    case 0x0041d51au: goto L0041d51a;
    case 0x0041d51du: goto L0041d51d;
    case 0x0041d51fu: goto L0041d51f;
    case 0x0041d520u: goto L0041d520;
    case 0x0041d521u: goto L0041d521;
    default:throw std::domain_error("recovery609 unsupported switch destination");}
  }
  L0041d4ba: { // 0x41d4ba: 8b8ee4000000 MOV ECX,dword ptr [ESI + 0xe4]
    s.cx = m.r32((s.si+0x000000e4u));
  }
  L0041d4c0: { // 0x41d4c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041d4c1: { // 0x41d4c1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041d4c3: { // 0x41d4c3: 0f9cc3 SETL BL
    s.bx = with_al(s.bx, (integer::condition("JL",flags)?1u:0u));
  }
  L0041d4c6: { // 0x41d4c6: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0041d4c8: { // 0x41d4c8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041d4c9: { // 0x41d4c9: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041d4cc: { // 0x41d4cc: 8b8ee4000000 MOV ECX,dword ptr [ESI + 0xe4]
    s.cx = m.r32((s.si+0x000000e4u));
  }
  L0041d4d2: { // 0x41d4d2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041d4d3: { // 0x41d4d3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041d4d5: { // 0x41d4d5: 0f9ec3 SETLE BL
    s.bx = with_al(s.bx, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0041d4d8: { // 0x41d4d8: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0041d4da: { // 0x41d4da: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041d4db: { // 0x41d4db: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041d4de: { // 0x41d4de: 8b8ee4000000 MOV ECX,dword ptr [ESI + 0xe4]
    s.cx = m.r32((s.si+0x000000e4u));
  }
  L0041d4e4: { // 0x41d4e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041d4e5: { // 0x41d4e5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041d4e7: { // 0x41d4e7: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0041d4ea: { // 0x41d4ea: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0041d4ec: { // 0x41d4ec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041d4ed: { // 0x41d4ed: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041d4f0: { // 0x41d4f0: 8b8ee4000000 MOV ECX,dword ptr [ESI + 0xe4]
    s.cx = m.r32((s.si+0x000000e4u));
  }
  L0041d4f6: { // 0x41d4f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041d4f7: { // 0x41d4f7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041d4f9: { // 0x41d4f9: 0f9dc3 SETGE BL
    s.bx = with_al(s.bx, (integer::condition("JGE",flags)?1u:0u));
  }
  L0041d4fc: { // 0x41d4fc: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0041d4fe: { // 0x41d4fe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041d4ff: { // 0x41d4ff: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041d502: { // 0x41d502: 8b8ee4000000 MOV ECX,dword ptr [ESI + 0xe4]
    s.cx = m.r32((s.si+0x000000e4u));
  }
  L0041d508: { // 0x41d508: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041d509: { // 0x41d509: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041d50b: { // 0x41d50b: 0f9fc3 SETG BL
    s.bx = with_al(s.bx, (integer::condition("JG",flags)?1u:0u));
  }
  L0041d50e: { // 0x41d50e: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0041d510: { // 0x41d510: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041d511: { // 0x41d511: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041d514: { // 0x41d514: 3b86e4000000 CMP EAX,dword ptr [ESI + 0xe4]
    (void)integer::sub(s.ax,m.r32((s.si+0x000000e4u)),32,flags);
  }
  L0041d51a: { // 0x41d51a: 0f95c3 SETNZ BL
    s.bx = with_al(s.bx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L0041d51d: { // 0x41d51d: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0041d51f: { // 0x41d51f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041d520: { // 0x41d520: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041d521: { // 0x41d521: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
