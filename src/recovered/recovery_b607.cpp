#include "recovered/recovery_b607_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b607 {
namespace {
void f_000100a0(Memory&,State&,Frame&,const Operations&);
void f_000f6060(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000100a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004100a0: { // 0x4100a0: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004100a5: { // 0x4100a5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}


void f_000f6060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f6060: { // 0x4f6060: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004f6065: { // 0x4f6065: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4260000u:f_000100a0(m,s,child,{});break;
case 5202016u:f_000f6060(m,s,child,{});break;
default:throw std::domain_error("recovery607 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00410000(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00410000: { // 0x410000: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00410004: { // 0x410004: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410005: { // 0x410005: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00410007: { // 0x410007: 7509 JNZ 0x00410012
    if(integer::condition("JNZ",flags)) goto L00410012;
  }
  L00410009: { // 0x410009: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L0041000e: { // 0x41000e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041000f: { // 0x41000f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00410012: { // 0x410012: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00410016: { // 0x410016: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00410017: { // 0x410017: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00410018: { // 0x410018: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L0041001d: { // 0x41001d: bff8aa7900 MOV EDI,0x79aaf8
    s.di = 0x0079aaf8u;
  }
  L00410022: { // 0x410022: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00410024: { // 0x410024: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00410026: { // 0x410026: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L0041002c: { // 0x41002c: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00410030: { // 0x410030: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L00410032: { // 0x410032: 7502 JNZ 0x00410036
    if(integer::condition("JNZ",flags)) goto L00410036;
  }
  L00410034: { // 0x410034: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L00410036: { // 0x410036: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00410037: { // 0x410037: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L0041003c: { // 0x41003c: bfe8aa7900 MOV EDI,0x79aae8
    s.di = 0x0079aae8u;
  }
  L00410041: { // 0x410041: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00410043: { // 0x410043: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00410045: { // 0x410045: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L00410047: { // 0x410047: 7502 JNZ 0x0041004b
    if(integer::condition("JNZ",flags)) goto L0041004b;
  }
  L00410049: { // 0x410049: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L0041004b: { // 0x41004b: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L00410050: { // 0x410050: bfd8aa7900 MOV EDI,0x79aad8
    s.di = 0x0079aad8u;
  }
  L00410055: { // 0x410055: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00410057: { // 0x410057: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00410059: { // 0x410059: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0041005b: { // 0x41005b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041005c: { // 0x41005c: 7502 JNZ 0x00410060
    if(integer::condition("JNZ",flags)) goto L00410060;
  }
  L0041005e: { // 0x41005e: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L00410060: { // 0x410060: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00410062: { // 0x410062: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L00410067: { // 0x410067: bf20d07800 MOV EDI,0x78d020
    s.di = 0x0078d020u;
  }
  L0041006c: { // 0x41006c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0041006e: { // 0x41006e: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L00410070: { // 0x410070: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00410071: { // 0x410071: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00410072: { // 0x410072: 750d JNZ 0x00410081
    if(integer::condition("JNZ",flags)) goto L00410081;
  }
  L00410074: { // 0x410074: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00410076: { // 0x410076: 7405 JZ 0x0041007d
    if(integer::condition("JZ",flags)) goto L0041007d;
  }
  L00410078: { // 0x410078: 8d4b04 LEA ECX,[EBX + 0x4]
    s.cx = (s.bx+0x00000004u);
  }
  L0041007b: { // 0x41007b: eb02 JMP 0x0041007f
    goto L0041007f;
  }
  L0041007d: { // 0x41007d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041007f: { // 0x41007f: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00410081: { // 0x410081: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L00410084: { // 0x410084: 7509 JNZ 0x0041008f
    if(integer::condition("JNZ",flags)) goto L0041008f;
  }
  L00410086: { // 0x410086: b802400080 MOV EAX,0x80004002
    s.ax = 0x80004002u;
  }
  L0041008b: { // 0x41008b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041008c: { // 0x41008c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041008f: { // 0x41008f: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00410091: { // 0x410091: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410092: { // 0x410092: ff5004 CALL dword ptr [EAX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000004u)),4259989u); flags=s.arithmetic_flags;
  }
  L00410095: { // 0x410095: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00410097: { // 0x410097: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00410098: { // 0x410098: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00492090(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00492090: { // 0x492090: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00492091: { // 0x492091: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00492095: { // 0x492095: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00492097: { // 0x492097: 7509 JNZ 0x004920a2
    if(integer::condition("JNZ",flags)) goto L004920a2;
  }
  L00492099: { // 0x492099: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L0049209e: { // 0x49209e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049209f: { // 0x49209f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004920a2: { // 0x4920a2: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L004920a6: { // 0x4920a6: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004920aa: { // 0x4920aa: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L004920ad: { // 0x4920ad: 760d JBE 0x004920bc
    if(integer::condition("JBE",flags)) goto L004920bc;
  }
  L004920af: { // 0x4920af: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004920b1: { // 0x4920b1: 750d JNZ 0x004920c0
    if(integer::condition("JNZ",flags)) goto L004920c0;
  }
  L004920b3: { // 0x4920b3: b857000780 MOV EAX,0x80070057
    s.ax = 0x80070057u;
  }
  L004920b8: { // 0x4920b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004920b9: { // 0x4920b9: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004920bc: { // 0x4920bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004920be: { // 0x4920be: 740a JZ 0x004920ca
    if(integer::condition("JZ",flags)) goto L004920ca;
  }
  L004920c0: { // 0x4920c0: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004920c4: { // 0x4920c4: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L004920ca: { // 0x4920ca: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004920cb: { // 0x4920cb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004920cc: { // 0x4920cc: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004920ce: { // 0x4920ce: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004920d0: { // 0x4920d0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004920d2: { // 0x4920d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004920d3: { // 0x4920d3: 7640 JBE 0x00492115
    if(integer::condition("JBE",flags)) goto L00492115;
  }
  L004920d5: { // 0x4920d5: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L004920d9: { // 0x4920d9: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004920dc: { // 0x4920dc: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L004920df: { // 0x4920df: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004920e1: { // 0x4920e1: 7d32 JGE 0x00492115
    if(integer::condition("JGE",flags)) goto L00492115;
  }
  L004920e3: { // 0x4920e3: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L004920e6: { // 0x4920e6: 8b04c2 MOV EAX,dword ptr [EDX + EAX*0x8]
    s.ax = m.r32((s.dx+(s.ax * 0x00000008u)));
  }
  L004920e9: { // 0x4920e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004920ea: { // 0x4920ea: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004920ec: { // 0x4920ec: ff5104 CALL dword ptr [ECX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000004u)),4792559u); flags=s.arithmetic_flags;
  }
  L004920ef: { // 0x4920ef: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004920f2: { // 0x4920f2: 83c708 ADD EDI,0x8
    s.di = integer::add(s.di,0x00000008u,32,flags);
  }
  L004920f5: { // 0x4920f5: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L004920f6: { // 0x4920f6: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004920f7: { // 0x4920f7: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L004920fa: { // 0x4920fa: 89561c MOV dword ptr [ESI + 0x1c],EDX
    m.w32((s.si+0x0000001cu), s.dx);
  }
  L004920fd: { // 0x4920fd: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00492100: { // 0x492100: 8b14c1 MOV EDX,dword ptr [ECX + EAX*0x8]
    s.dx = m.r32((s.cx+(s.ax * 0x00000008u)));
  }
  L00492103: { // 0x492103: 8957f8 MOV dword ptr [EDI + -0x8],EDX
    m.w32((s.di-0x00000008u), s.dx);
  }
  L00492106: { // 0x492106: 8b44c104 MOV EAX,dword ptr [ECX + EAX*0x8 + 0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000008u)+0x00000004u));
  }
  L0049210a: { // 0x49210a: 8947fc MOV dword ptr [EDI + -0x4],EAX
    m.w32((s.di-0x00000004u), s.ax);
  }
  L0049210d: { // 0x49210d: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00492111: { // 0x492111: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00492113: { // 0x492113: 72c4 JC 0x004920d9
    if(integer::condition("JC",flags)) goto L004920d9;
  }
  L00492115: { // 0x492115: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00492119: { // 0x492119: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049211b: { // 0x49211b: 7402 JZ 0x0049211f
    if(integer::condition("JZ",flags)) goto L0049211f;
  }
  L0049211d: { // 0x49211d: 8928 MOV dword ptr [EAX],EBP
    m.w32((s.ax), s.bp);
  }
  L0049211f: { // 0x49211f: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00492121: { // 0x492121: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00492122: { // 0x492122: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00492124: { // 0x492124: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00492126: { // 0x492126: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00492127: { // 0x492127: 25fbbfff7f AND EAX,0x7fffbffb
    s.ax = integer::logical((s.ax)&(0x7fffbffbu),32,flags);
  }
  L0049212c: { // 0x49212c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049212d: { // 0x49212d: 0505400080 ADD EAX,0x80004005
    s.ax = integer::add(s.ax,0x80004005u,32,flags);
  }
  L00492132: { // 0x492132: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00492133: { // 0x492133: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004e2060(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e2060: { // 0x4e2060: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L004e2064: { // 0x4e2064: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004e2066: { // 0x4e2066: 7508 JNZ 0x004e2070
    if(integer::condition("JNZ",flags)) goto L004e2070;
  }
  L004e2068: { // 0x4e2068: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L004e206d: { // 0x4e206d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004e2070: { // 0x4e2070: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e2071: { // 0x4e2071: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L004e2075: { // 0x4e2075: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e2076: { // 0x4e2076: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e2077: { // 0x4e2077: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004e207c: { // 0x4e207c: bff8aa7900 MOV EDI,0x79aaf8
    s.di = 0x0079aaf8u;
  }
  L004e2081: { // 0x4e2081: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004e2083: { // 0x4e2083: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e2085: { // 0x4e2085: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004e2089: { // 0x4e2089: c70200000000 MOV dword ptr [EDX],0x0
    m.w32((s.dx), 0x00000000u);
  }
  L004e208f: { // 0x4e208f: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004e2091: { // 0x4e2091: 7502 JNZ 0x004e2095
    if(integer::condition("JNZ",flags)) goto L004e2095;
  }
  L004e2093: { // 0x4e2093: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L004e2095: { // 0x4e2095: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e2096: { // 0x4e2096: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004e209b: { // 0x4e209b: bfa8dc7800 MOV EDI,0x78dca8
    s.di = 0x0078dca8u;
  }
  L004e20a0: { // 0x4e20a0: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004e20a2: { // 0x4e20a2: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004e20a4: { // 0x4e20a4: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004e20a6: { // 0x4e20a6: 750d JNZ 0x004e20b5
    if(integer::condition("JNZ",flags)) goto L004e20b5;
  }
  L004e20a8: { // 0x4e20a8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e20aa: { // 0x4e20aa: 7405 JZ 0x004e20b1
    if(integer::condition("JZ",flags)) goto L004e20b1;
  }
  L004e20ac: { // 0x4e20ac: 8d4824 LEA ECX,[EAX + 0x24]
    s.cx = (s.ax+0x00000024u);
  }
  L004e20af: { // 0x4e20af: eb02 JMP 0x004e20b3
    goto L004e20b3;
  }
  L004e20b1: { // 0x4e20b1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004e20b3: { // 0x4e20b3: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L004e20b5: { // 0x4e20b5: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004e20ba: { // 0x4e20ba: bf40d07800 MOV EDI,0x78d040
    s.di = 0x0078d040u;
  }
  L004e20bf: { // 0x4e20bf: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004e20c1: { // 0x4e20c1: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004e20c3: { // 0x4e20c3: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004e20c5: { // 0x4e20c5: 750d JNZ 0x004e20d4
    if(integer::condition("JNZ",flags)) goto L004e20d4;
  }
  L004e20c7: { // 0x4e20c7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e20c9: { // 0x4e20c9: 7405 JZ 0x004e20d0
    if(integer::condition("JZ",flags)) goto L004e20d0;
  }
  L004e20cb: { // 0x4e20cb: 8d4828 LEA ECX,[EAX + 0x28]
    s.cx = (s.ax+0x00000028u);
  }
  L004e20ce: { // 0x4e20ce: eb02 JMP 0x004e20d2
    goto L004e20d2;
  }
  L004e20d0: { // 0x4e20d0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004e20d2: { // 0x4e20d2: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L004e20d4: { // 0x4e20d4: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004e20d9: { // 0x4e20d9: bf38ab7900 MOV EDI,0x79ab38
    s.di = 0x0079ab38u;
  }
  L004e20de: { // 0x4e20de: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004e20e0: { // 0x4e20e0: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004e20e2: { // 0x4e20e2: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004e20e4: { // 0x4e20e4: 750d JNZ 0x004e20f3
    if(integer::condition("JNZ",flags)) goto L004e20f3;
  }
  L004e20e6: { // 0x4e20e6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e20e8: { // 0x4e20e8: 7405 JZ 0x004e20ef
    if(integer::condition("JZ",flags)) goto L004e20ef;
  }
  L004e20ea: { // 0x4e20ea: 8d482c LEA ECX,[EAX + 0x2c]
    s.cx = (s.ax+0x0000002cu);
  }
  L004e20ed: { // 0x4e20ed: eb02 JMP 0x004e20f1
    goto L004e20f1;
  }
  L004e20ef: { // 0x4e20ef: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004e20f1: { // 0x4e20f1: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L004e20f3: { // 0x4e20f3: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004e20f8: { // 0x4e20f8: bfd8aa7900 MOV EDI,0x79aad8
    s.di = 0x0079aad8u;
  }
  L004e20fd: { // 0x4e20fd: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004e20ff: { // 0x4e20ff: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004e2101: { // 0x4e2101: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004e2103: { // 0x4e2103: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e2104: { // 0x4e2104: 7502 JNZ 0x004e2108
    if(integer::condition("JNZ",flags)) goto L004e2108;
  }
  L004e2106: { // 0x4e2106: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L004e2108: { // 0x4e2108: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004e210a: { // 0x4e210a: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004e210f: { // 0x4e210f: bfe8aa7900 MOV EDI,0x79aae8
    s.di = 0x0079aae8u;
  }
  L004e2114: { // 0x4e2114: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004e2116: { // 0x4e2116: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004e2118: { // 0x4e2118: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e2119: { // 0x4e2119: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e211a: { // 0x4e211a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e211b: { // 0x4e211b: 7502 JNZ 0x004e211f
    if(integer::condition("JNZ",flags)) goto L004e211f;
  }
  L004e211d: { // 0x4e211d: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L004e211f: { // 0x4e211f: 833a00 CMP dword ptr [EDX],0x0
    (void)integer::sub(m.r32((s.dx)),0x00000000u,32,flags);
  }
  L004e2122: { // 0x4e2122: 7508 JNZ 0x004e212c
    if(integer::condition("JNZ",flags)) goto L004e212c;
  }
  L004e2124: { // 0x4e2124: b802400080 MOV EAX,0x80004002
    s.ax = 0x80004002u;
  }
  L004e2129: { // 0x4e2129: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004e212c: { // 0x4e212c: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004e212e: { // 0x4e212e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e212f: { // 0x4e212f: ff5104 CALL dword ptr [ECX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000004u)),5120306u); flags=s.arithmetic_flags;
  }
  L004e2132: { // 0x4e2132: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e2134: { // 0x4e2134: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
