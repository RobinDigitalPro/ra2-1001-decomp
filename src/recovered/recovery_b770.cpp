#include "recovered/recovery_b770_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b770 {
namespace {
void f_00054870(Memory&,State&,Frame&,const Operations&);
void f_00010000(Memory&,State&,Frame&,const Operations&);
void f_000100a0(Memory&,State&,Frame&,const Operations&);
void f_000100b0(Memory&,State&,Frame&,const Operations&);
void f_0001c210(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00054870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00454870: { // 0x454870: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00454874: { // 0x454874: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00454875: { // 0x454875: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00454876: { // 0x454876: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00454878: { // 0x454878: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0045487a: { // 0x45487a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045487c: { // 0x45487c: 7449 JZ 0x4548c7
    if(integer::condition("JZ",flags)) goto L004548c7;
  }
  L0045487e: { // 0x45487e: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00454880: { // 0x454880: 8d54240c LEA EDX, [ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L00454884: { // 0x454884: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00454885: { // 0x454885: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  L0045488a: { // 0x45488a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045488b: { // 0x45488b: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),4540557u); flags=s.arithmetic_flags;
  }
  L0045488d: { // 0x45488d: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0045488f: { // 0x45488f: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00454891: { // 0x454891: 7d19 JGE 0x4548ac
    if(integer::condition("JGE",flags)) goto L004548ac;
  }
  L00454893: { // 0x454893: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00454895: { // 0x454895: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00454897: { // 0x454897: 7406 JZ 0x45489f
    if(integer::condition("JZ",flags)) goto L0045489f;
  }
  L00454899: { // 0x454899: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0045489b: { // 0x45489b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045489c: { // 0x45489c: ff5108 CALL dword ptr [ECX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+8u)),4540575u); flags=s.arithmetic_flags;
  }
  L0045489f: { // 0x45489f: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004548a1: { // 0x4548a1: c70600000000 MOV dword ptr [ESI], 0
    m.w32((s.si), 0u);
  }
  L004548a7: { // 0x4548a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004548a8: { // 0x4548a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004548a9: { // 0x4548a9: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004548ac: { // 0x4548ac: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004548ae: { // 0x4548ae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004548af: { // 0x4548af: 8b5c2410 MOV EBX, dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L004548b3: { // 0x4548b3: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004548b5: { // 0x4548b5: 7406 JZ 0x4548bd
    if(integer::condition("JZ",flags)) goto L004548bd;
  }
  L004548b7: { // 0x4548b7: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004548b9: { // 0x4548b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004548ba: { // 0x4548ba: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),4540605u); flags=s.arithmetic_flags;
  }
  L004548bd: { // 0x4548bd: 891e MOV dword ptr [ESI], EBX
    m.w32((s.si), s.bx);
  }
  L004548bf: { // 0x4548bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004548c0: { // 0x4548c0: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004548c2: { // 0x4548c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004548c3: { // 0x4548c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004548c4: { // 0x4548c4: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004548c7: { // 0x4548c7: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004548c9: { // 0x4548c9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004548cb: { // 0x4548cb: 740c JZ 0x4548d9
    if(integer::condition("JZ",flags)) goto L004548d9;
  }
  L004548cd: { // 0x4548cd: c70600000000 MOV dword ptr [ESI], 0
    m.w32((s.si), 0u);
  }
  L004548d3: { // 0x4548d3: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004548d5: { // 0x4548d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004548d6: { // 0x4548d6: ff5108 CALL dword ptr [ECX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+8u)),4540633u); flags=s.arithmetic_flags;
  }
  L004548d9: { // 0x4548d9: bf02400080 MOV EDI, 0x80004002
    s.di = 0x80004002u;
  }
  L004548de: { // 0x4548de: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004548e0: { // 0x4548e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004548e1: { // 0x4548e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004548e2: { // 0x4548e2: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00010000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00410000: { // 0x410000: 8b44240c MOV EAX, dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00410004: { // 0x410004: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410005: { // 0x410005: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00410007: { // 0x410007: 7509 JNZ 0x410012
    if(integer::condition("JNZ",flags)) goto L00410012;
  }
  L00410009: { // 0x410009: b803400080 MOV EAX, 0x80004003
    s.ax = 0x80004003u;
  }
  L0041000e: { // 0x41000e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041000f: { // 0x41000f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00410012: { // 0x410012: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00410016: { // 0x410016: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00410017: { // 0x410017: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00410018: { // 0x410018: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L0041001d: { // 0x41001d: bff8aa7900 MOV EDI, 0x79aaf8
    s.di = 0x0079aaf8u;
  }
  L00410022: { // 0x410022: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L00410024: { // 0x410024: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00410026: { // 0x410026: c70000000000 MOV dword ptr [EAX], 0
    m.w32((s.ax), 0u);
  }
  L0041002c: { // 0x41002c: 8b5c2410 MOV EBX, dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00410030: { // 0x410030: f3a7 REPE CMPSD dword ptr [ESI], dword ptr es:[EDI]
    while(s.cx){const auto a=m.r32(s.si),b=m.r32(s.di);s.si+=4;s.di+=4;--s.cx;(void)integer::sub(a,b,32,flags);if(!(flags&integer::ZF))break;}
  }
  L00410032: { // 0x410032: 7502 JNZ 0x410036
    if(integer::condition("JNZ",flags)) goto L00410036;
  }
  L00410034: { // 0x410034: 8918 MOV dword ptr [EAX], EBX
    m.w32((s.ax), s.bx);
  }
  L00410036: { // 0x410036: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00410037: { // 0x410037: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L0041003c: { // 0x41003c: bfe8aa7900 MOV EDI, 0x79aae8
    s.di = 0x0079aae8u;
  }
  L00410041: { // 0x410041: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L00410043: { // 0x410043: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00410045: { // 0x410045: f3a7 REPE CMPSD dword ptr [ESI], dword ptr es:[EDI]
    while(s.cx){const auto a=m.r32(s.si),b=m.r32(s.di);s.si+=4;s.di+=4;--s.cx;(void)integer::sub(a,b,32,flags);if(!(flags&integer::ZF))break;}
  }
  L00410047: { // 0x410047: 7502 JNZ 0x41004b
    if(integer::condition("JNZ",flags)) goto L0041004b;
  }
  L00410049: { // 0x410049: 8918 MOV dword ptr [EAX], EBX
    m.w32((s.ax), s.bx);
  }
  L0041004b: { // 0x41004b: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L00410050: { // 0x410050: bfd8aa7900 MOV EDI, 0x79aad8
    s.di = 0x0079aad8u;
  }
  L00410055: { // 0x410055: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L00410057: { // 0x410057: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00410059: { // 0x410059: f3a7 REPE CMPSD dword ptr [ESI], dword ptr es:[EDI]
    while(s.cx){const auto a=m.r32(s.si),b=m.r32(s.di);s.si+=4;s.di+=4;--s.cx;(void)integer::sub(a,b,32,flags);if(!(flags&integer::ZF))break;}
  }
  L0041005b: { // 0x41005b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041005c: { // 0x41005c: 7502 JNZ 0x410060
    if(integer::condition("JNZ",flags)) goto L00410060;
  }
  L0041005e: { // 0x41005e: 8918 MOV dword ptr [EAX], EBX
    m.w32((s.ax), s.bx);
  }
  L00410060: { // 0x410060: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L00410062: { // 0x410062: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L00410067: { // 0x410067: bf20d07800 MOV EDI, 0x78d020
    s.di = 0x0078d020u;
  }
  L0041006c: { // 0x41006c: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0041006e: { // 0x41006e: f3a7 REPE CMPSD dword ptr [ESI], dword ptr es:[EDI]
    while(s.cx){const auto a=m.r32(s.si),b=m.r32(s.di);s.si+=4;s.di+=4;--s.cx;(void)integer::sub(a,b,32,flags);if(!(flags&integer::ZF))break;}
  }
  L00410070: { // 0x410070: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00410071: { // 0x410071: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00410072: { // 0x410072: 750d JNZ 0x410081
    if(integer::condition("JNZ",flags)) goto L00410081;
  }
  L00410074: { // 0x410074: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00410076: { // 0x410076: 7405 JZ 0x41007d
    if(integer::condition("JZ",flags)) goto L0041007d;
  }
  L00410078: { // 0x410078: 8d4b04 LEA ECX, [EBX + 4]
    s.cx = (s.bx+4u);
  }
  L0041007b: { // 0x41007b: eb02 JMP 0x41007f
    goto L0041007f;
  }
  L0041007d: { // 0x41007d: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041007f: { // 0x41007f: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L00410081: { // 0x410081: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L00410084: { // 0x410084: 7509 JNZ 0x41008f
    if(integer::condition("JNZ",flags)) goto L0041008f;
  }
  L00410086: { // 0x410086: b802400080 MOV EAX, 0x80004002
    s.ax = 0x80004002u;
  }
  L0041008b: { // 0x41008b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041008c: { // 0x41008c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041008f: { // 0x41008f: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00410091: { // 0x410091: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410092: { // 0x410092: ff5004 CALL dword ptr [EAX + 4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+4u)),4259989u); flags=s.arithmetic_flags;
  }
  L00410095: { // 0x410095: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00410097: { // 0x410097: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00410098: { // 0x410098: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_000100a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004100a0: { // 0x4100a0: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004100a5: { // 0x4100a5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000100b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004100b0: { // 0x4100b0: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004100b5: { // 0x4100b5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0001c210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041c210: { // 0x41c210: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0041c214: { // 0x41c214: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041c216: { // 0x41c216: 7508 JNZ 0x41c220
    if(integer::condition("JNZ",flags)) goto L0041c220;
  }
  L0041c218: { // 0x41c218: b803400080 MOV EAX, 0x80004003
    s.ax = 0x80004003u;
  }
  L0041c21d: { // 0x41c21d: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0041c220: { // 0x41c220: 8b0d20cb7800 MOV ECX, dword ptr [0x78cb20]
    s.cx = m.r32((0x0078cb20u));
  }
  L0041c226: { // 0x41c226: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L0041c228: { // 0x41c228: 8b1524cb7800 MOV EDX, dword ptr [0x78cb24]
    s.dx = m.r32((0x0078cb24u));
  }
  L0041c22e: { // 0x41c22e: 895004 MOV dword ptr [EAX + 4], EDX
    m.w32((s.ax+4u), s.dx);
  }
  L0041c231: { // 0x41c231: 8b0d28cb7800 MOV ECX, dword ptr [0x78cb28]
    s.cx = m.r32((0x0078cb28u));
  }
  L0041c237: { // 0x41c237: 894808 MOV dword ptr [EAX + 8], ECX
    m.w32((s.ax+8u), s.cx);
  }
  L0041c23a: { // 0x41c23a: 8b152ccb7800 MOV EDX, dword ptr [0x78cb2c]
    s.dx = m.r32((0x0078cb2cu));
  }
  L0041c240: { // 0x41c240: 89500c MOV dword ptr [EAX + 0xc], EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0041c243: { // 0x41c243: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0041c245: { // 0x41c245: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}




} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4540528u:f_00054870(m,s,child,{});break;
case 4259840u:f_00010000(m,s,child,{});break;
case 4260000u:f_000100a0(m,s,child,{});break;
case 4260016u:f_000100b0(m,s,child,{});break;
case 4309520u:f_0001c210(m,s,child,{});break;
default:throw std::domain_error("recovery770 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0049f430(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049f430: { // 0x49f430: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049f431: { // 0x49f431: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L0049f435: { // 0x49f435: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0049f437: { // 0x49f437: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049f438: { // 0x49f438: 750a JNZ 0x0049f444
    if(integer::condition("JNZ",flags)) goto L0049f444;
  }
  L0049f43a: { // 0x49f43a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f43b: { // 0x49f43b: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L0049f440: { // 0x49f440: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f441: { // 0x49f441: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049f444: { // 0x49f444: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0049f448: { // 0x49f448: 8b5150 MOV EDX,dword ptr [ECX + 0x50]
    s.dx = m.r32((s.cx+0x00000050u));
  }
  L0049f44b: { // 0x49f44b: 8d4150 LEA EAX,[ECX + 0x50]
    s.ax = (s.cx+0x00000050u);
  }
  L0049f44e: { // 0x49f44e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0049f450: { // 0x49f450: 745d JZ 0x0049f4af
    if(integer::condition("JZ",flags)) goto L0049f4af;
  }
  L0049f452: { // 0x49f452: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0049f454: { // 0x49f454: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L0049f45c: { // 0x49f45c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049f45e: { // 0x49f45e: 7423 JZ 0x0049f483
    if(integer::condition("JZ",flags)) goto L0049f483;
  }
  L0049f460: { // 0x49f460: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f461: { // 0x49f461: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0049f465: { // 0x49f465: e80654fbff CALL 0x00454870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454870u,4846698u); flags=s.arithmetic_flags;
  }
  L0049f46a: { // 0x49f46a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f46c: { // 0x49f46c: 7d0d JGE 0x0049f47b
    if(integer::condition("JGE",flags)) goto L0049f47b;
  }
  L0049f46e: { // 0x49f46e: 3d02400080 CMP EAX,0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L0049f473: { // 0x49f473: 7406 JZ 0x0049f47b
    if(integer::condition("JZ",flags)) goto L0049f47b;
  }
  L0049f475: { // 0x49f475: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f476: { // 0x49f476: e8f51d2e00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,4846715u); flags=s.arithmetic_flags;
  }
  L0049f47b: { // 0x49f47b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0049f47f: { // 0x49f47f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f481: { // 0x49f481: 750a JNZ 0x0049f48d
    if(integer::condition("JNZ",flags)) goto L0049f48d;
  }
  L0049f483: { // 0x49f483: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f484: { // 0x49f484: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L0049f489: { // 0x49f489: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f48a: { // 0x49f48a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049f48d: { // 0x49f48d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049f48f: { // 0x49f48f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049f490: { // 0x49f490: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f491: { // 0x49f491: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),4846740u); flags=s.arithmetic_flags;
  }
  L0049f494: { // 0x49f494: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049f496: { // 0x49f496: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0049f49a: { // 0x49f49a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f49c: { // 0x49f49c: 0f8492000000 JZ 0x0049f534
    if(integer::condition("JZ",flags)) goto L0049f534;
  }
  L0049f4a2: { // 0x49f4a2: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0049f4a4: { // 0x49f4a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f4a5: { // 0x49f4a5: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4846760u); flags=s.arithmetic_flags;
  }
  L0049f4a8: { // 0x49f4a8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0049f4aa: { // 0x49f4aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f4ab: { // 0x49f4ab: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f4ac: { // 0x49f4ac: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049f4af: { // 0x49f4af: 8d41e8 LEA EAX,[ECX + -0x18]
    s.ax = (s.cx-0x00000018u);
  }
  L0049f4b2: { // 0x49f4b2: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L0049f4ba: { // 0x49f4ba: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f4bc: { // 0x49f4bc: 7455 JZ 0x0049f513
    if(integer::condition("JZ",flags)) goto L0049f513;
  }
  L0049f4be: { // 0x49f4be: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049f4c0: { // 0x49f4c0: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L0049f4c4: { // 0x49f4c4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f4c5: { // 0x49f4c5: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  L0049f4ca: { // 0x49f4ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f4cb: { // 0x49f4cb: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),4846797u); flags=s.arithmetic_flags;
  }
  L0049f4cd: { // 0x49f4cd: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049f4cf: { // 0x49f4cf: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049f4d1: { // 0x49f4d1: 7d11 JGE 0x0049f4e4
    if(integer::condition("JGE",flags)) goto L0049f4e4;
  }
  L0049f4d3: { // 0x49f4d3: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0049f4d7: { // 0x49f4d7: e80446fbff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,4846812u); flags=s.arithmetic_flags;
  }
  L0049f4dc: { // 0x49f4dc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0049f4de: { // 0x49f4de: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0049f4e2: { // 0x49f4e2: eb15 JMP 0x0049f4f9
    goto L0049f4f9;
  }
  L0049f4e4: { // 0x49f4e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049f4e5: { // 0x49f4e5: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0049f4e9: { // 0x49f4e9: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0049f4ed: { // 0x49f4ed: e8ee45fbff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,4846834u); flags=s.arithmetic_flags;
  }
  L0049f4f2: { // 0x49f4f2: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0049f4f4: { // 0x49f4f4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049f4f5: { // 0x49f4f5: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0049f4f9: { // 0x49f4f9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049f4fb: { // 0x49f4fb: 7d12 JGE 0x0049f50f
    if(integer::condition("JGE",flags)) goto L0049f50f;
  }
  L0049f4fd: { // 0x49f4fd: 81fe02400080 CMP ESI,0x80004002
    (void)integer::sub(s.si,0x80004002u,32,flags);
  }
  L0049f503: { // 0x49f503: 740a JZ 0x0049f50f
    if(integer::condition("JZ",flags)) goto L0049f50f;
  }
  L0049f505: { // 0x49f505: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049f506: { // 0x49f506: e8651d2e00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,4846859u); flags=s.arithmetic_flags;
  }
  L0049f50b: { // 0x49f50b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0049f50f: { // 0x49f50f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f511: { // 0x49f511: 750a JNZ 0x0049f51d
    if(integer::condition("JNZ",flags)) goto L0049f51d;
  }
  L0049f513: { // 0x49f513: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f514: { // 0x49f514: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L0049f519: { // 0x49f519: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f51a: { // 0x49f51a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049f51d: { // 0x49f51d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049f51f: { // 0x49f51f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049f520: { // 0x49f520: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f521: { // 0x49f521: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),4846884u); flags=s.arithmetic_flags;
  }
  L0049f524: { // 0x49f524: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049f526: { // 0x49f526: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0049f52a: { // 0x49f52a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f52c: { // 0x49f52c: 7406 JZ 0x0049f534
    if(integer::condition("JZ",flags)) goto L0049f534;
  }
  L0049f52e: { // 0x49f52e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0049f530: { // 0x49f530: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f531: { // 0x49f531: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4846900u); flags=s.arithmetic_flags;
  }
  L0049f534: { // 0x49f534: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0049f536: { // 0x49f536: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f537: { // 0x49f537: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f538: { // 0x49f538: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004a6170(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a6170: { // 0x4a6170: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004a6171: { // 0x4a6171: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L004a6175: { // 0x4a6175: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004a6177: { // 0x4a6177: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a6178: { // 0x4a6178: 750a JNZ 0x004a6184
    if(integer::condition("JNZ",flags)) goto L004a6184;
  }
  L004a617a: { // 0x4a617a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a617b: { // 0x4a617b: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L004a6180: { // 0x4a6180: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a6181: { // 0x4a6181: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004a6184: { // 0x4a6184: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004a6188: { // 0x4a6188: 8b5114 MOV EDX,dword ptr [ECX + 0x14]
    s.dx = m.r32((s.cx+0x00000014u));
  }
  L004a618b: { // 0x4a618b: 8d4114 LEA EAX,[ECX + 0x14]
    s.ax = (s.cx+0x00000014u);
  }
  L004a618e: { // 0x4a618e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004a6190: { // 0x4a6190: 745d JZ 0x004a61ef
    if(integer::condition("JZ",flags)) goto L004a61ef;
  }
  L004a6192: { // 0x4a6192: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004a6194: { // 0x4a6194: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L004a619c: { // 0x4a619c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004a619e: { // 0x4a619e: 7423 JZ 0x004a61c3
    if(integer::condition("JZ",flags)) goto L004a61c3;
  }
  L004a61a0: { // 0x4a61a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a61a1: { // 0x4a61a1: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004a61a5: { // 0x4a61a5: e8c6e6faff CALL 0x00454870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454870u,4874666u); flags=s.arithmetic_flags;
  }
  L004a61aa: { // 0x4a61aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a61ac: { // 0x4a61ac: 7d0d JGE 0x004a61bb
    if(integer::condition("JGE",flags)) goto L004a61bb;
  }
  L004a61ae: { // 0x4a61ae: 3d02400080 CMP EAX,0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L004a61b3: { // 0x4a61b3: 7406 JZ 0x004a61bb
    if(integer::condition("JZ",flags)) goto L004a61bb;
  }
  L004a61b5: { // 0x4a61b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a61b6: { // 0x4a61b6: e8b5b02d00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,4874683u); flags=s.arithmetic_flags;
  }
  L004a61bb: { // 0x4a61bb: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L004a61bf: { // 0x4a61bf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a61c1: { // 0x4a61c1: 750a JNZ 0x004a61cd
    if(integer::condition("JNZ",flags)) goto L004a61cd;
  }
  L004a61c3: { // 0x4a61c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a61c4: { // 0x4a61c4: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L004a61c9: { // 0x4a61c9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a61ca: { // 0x4a61ca: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004a61cd: { // 0x4a61cd: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004a61cf: { // 0x4a61cf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004a61d0: { // 0x4a61d0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a61d1: { // 0x4a61d1: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),4874708u); flags=s.arithmetic_flags;
  }
  L004a61d4: { // 0x4a61d4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004a61d6: { // 0x4a61d6: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L004a61da: { // 0x4a61da: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a61dc: { // 0x4a61dc: 0f8492000000 JZ 0x004a6274
    if(integer::condition("JZ",flags)) goto L004a6274;
  }
  L004a61e2: { // 0x4a61e2: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004a61e4: { // 0x4a61e4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a61e5: { // 0x4a61e5: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4874728u); flags=s.arithmetic_flags;
  }
  L004a61e8: { // 0x4a61e8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004a61ea: { // 0x4a61ea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a61eb: { // 0x4a61eb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a61ec: { // 0x4a61ec: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004a61ef: { // 0x4a61ef: 8d41e8 LEA EAX,[ECX + -0x18]
    s.ax = (s.cx-0x00000018u);
  }
  L004a61f2: { // 0x4a61f2: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L004a61fa: { // 0x4a61fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a61fc: { // 0x4a61fc: 7455 JZ 0x004a6253
    if(integer::condition("JZ",flags)) goto L004a6253;
  }
  L004a61fe: { // 0x4a61fe: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004a6200: { // 0x4a6200: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L004a6204: { // 0x4a6204: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a6205: { // 0x4a6205: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  L004a620a: { // 0x4a620a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a620b: { // 0x4a620b: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),4874765u); flags=s.arithmetic_flags;
  }
  L004a620d: { // 0x4a620d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004a620f: { // 0x4a620f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004a6211: { // 0x4a6211: 7d11 JGE 0x004a6224
    if(integer::condition("JGE",flags)) goto L004a6224;
  }
  L004a6213: { // 0x4a6213: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004a6217: { // 0x4a6217: e8c4d8faff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,4874780u); flags=s.arithmetic_flags;
  }
  L004a621c: { // 0x4a621c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004a621e: { // 0x4a621e: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004a6222: { // 0x4a6222: eb15 JMP 0x004a6239
    goto L004a6239;
  }
  L004a6224: { // 0x4a6224: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004a6225: { // 0x4a6225: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L004a6229: { // 0x4a6229: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004a622d: { // 0x4a622d: e8aed8faff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,4874802u); flags=s.arithmetic_flags;
  }
  L004a6232: { // 0x4a6232: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004a6234: { // 0x4a6234: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004a6235: { // 0x4a6235: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004a6239: { // 0x4a6239: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004a623b: { // 0x4a623b: 7d12 JGE 0x004a624f
    if(integer::condition("JGE",flags)) goto L004a624f;
  }
  L004a623d: { // 0x4a623d: 81fe02400080 CMP ESI,0x80004002
    (void)integer::sub(s.si,0x80004002u,32,flags);
  }
  L004a6243: { // 0x4a6243: 740a JZ 0x004a624f
    if(integer::condition("JZ",flags)) goto L004a624f;
  }
  L004a6245: { // 0x4a6245: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a6246: { // 0x4a6246: e825b02d00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,4874827u); flags=s.arithmetic_flags;
  }
  L004a624b: { // 0x4a624b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004a624f: { // 0x4a624f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a6251: { // 0x4a6251: 750a JNZ 0x004a625d
    if(integer::condition("JNZ",flags)) goto L004a625d;
  }
  L004a6253: { // 0x4a6253: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a6254: { // 0x4a6254: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L004a6259: { // 0x4a6259: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a625a: { // 0x4a625a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004a625d: { // 0x4a625d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004a625f: { // 0x4a625f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004a6260: { // 0x4a6260: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a6261: { // 0x4a6261: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),4874852u); flags=s.arithmetic_flags;
  }
  L004a6264: { // 0x4a6264: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004a6266: { // 0x4a6266: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004a626a: { // 0x4a626a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a626c: { // 0x4a626c: 7406 JZ 0x004a6274
    if(integer::condition("JZ",flags)) goto L004a6274;
  }
  L004a626e: { // 0x4a626e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004a6270: { // 0x4a6270: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a6271: { // 0x4a6271: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4874868u); flags=s.arithmetic_flags;
  }
  L004a6274: { // 0x4a6274: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004a6276: { // 0x4a6276: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a6277: { // 0x4a6277: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a6278: { // 0x4a6278: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0066b050(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0066b050: { // 0x66b050: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0066b051: { // 0x66b051: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L0066b055: { // 0x66b055: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0066b057: { // 0x66b057: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0066b058: { // 0x66b058: 750a JNZ 0x0066b064
    if(integer::condition("JNZ",flags)) goto L0066b064;
  }
  L0066b05a: { // 0x66b05a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0066b05b: { // 0x66b05b: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L0066b060: { // 0x66b060: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0066b061: { // 0x66b061: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0066b064: { // 0x66b064: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0066b068: { // 0x66b068: 8b5150 MOV EDX,dword ptr [ECX + 0x50]
    s.dx = m.r32((s.cx+0x00000050u));
  }
  L0066b06b: { // 0x66b06b: 8d4150 LEA EAX,[ECX + 0x50]
    s.ax = (s.cx+0x00000050u);
  }
  L0066b06e: { // 0x66b06e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0066b070: { // 0x66b070: 745d JZ 0x0066b0cf
    if(integer::condition("JZ",flags)) goto L0066b0cf;
  }
  L0066b072: { // 0x66b072: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0066b074: { // 0x66b074: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L0066b07c: { // 0x66b07c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0066b07e: { // 0x66b07e: 7423 JZ 0x0066b0a3
    if(integer::condition("JZ",flags)) goto L0066b0a3;
  }
  L0066b080: { // 0x66b080: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b081: { // 0x66b081: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0066b085: { // 0x66b085: e8e697deff CALL 0x00454870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454870u,6729866u); flags=s.arithmetic_flags;
  }
  L0066b08a: { // 0x66b08a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0066b08c: { // 0x66b08c: 7d0d JGE 0x0066b09b
    if(integer::condition("JGE",flags)) goto L0066b09b;
  }
  L0066b08e: { // 0x66b08e: 3d02400080 CMP EAX,0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L0066b093: { // 0x66b093: 7406 JZ 0x0066b09b
    if(integer::condition("JZ",flags)) goto L0066b09b;
  }
  L0066b095: { // 0x66b095: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b096: { // 0x66b096: e8d5611100 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,6729883u); flags=s.arithmetic_flags;
  }
  L0066b09b: { // 0x66b09b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0066b09f: { // 0x66b09f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0066b0a1: { // 0x66b0a1: 750a JNZ 0x0066b0ad
    if(integer::condition("JNZ",flags)) goto L0066b0ad;
  }
  L0066b0a3: { // 0x66b0a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0066b0a4: { // 0x66b0a4: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L0066b0a9: { // 0x66b0a9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0066b0aa: { // 0x66b0aa: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0066b0ad: { // 0x66b0ad: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0066b0af: { // 0x66b0af: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0066b0b0: { // 0x66b0b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b0b1: { // 0x66b0b1: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),6729908u); flags=s.arithmetic_flags;
  }
  L0066b0b4: { // 0x66b0b4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0066b0b6: { // 0x66b0b6: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0066b0ba: { // 0x66b0ba: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0066b0bc: { // 0x66b0bc: 0f8492000000 JZ 0x0066b154
    if(integer::condition("JZ",flags)) goto L0066b154;
  }
  L0066b0c2: { // 0x66b0c2: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0066b0c4: { // 0x66b0c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b0c5: { // 0x66b0c5: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6729928u); flags=s.arithmetic_flags;
  }
  L0066b0c8: { // 0x66b0c8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0066b0ca: { // 0x66b0ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0066b0cb: { // 0x66b0cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0066b0cc: { // 0x66b0cc: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0066b0cf: { // 0x66b0cf: 8d41e8 LEA EAX,[ECX + -0x18]
    s.ax = (s.cx-0x00000018u);
  }
  L0066b0d2: { // 0x66b0d2: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L0066b0da: { // 0x66b0da: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0066b0dc: { // 0x66b0dc: 7455 JZ 0x0066b133
    if(integer::condition("JZ",flags)) goto L0066b133;
  }
  L0066b0de: { // 0x66b0de: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0066b0e0: { // 0x66b0e0: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L0066b0e4: { // 0x66b0e4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0066b0e5: { // 0x66b0e5: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  L0066b0ea: { // 0x66b0ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b0eb: { // 0x66b0eb: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),6729965u); flags=s.arithmetic_flags;
  }
  L0066b0ed: { // 0x66b0ed: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0066b0ef: { // 0x66b0ef: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0066b0f1: { // 0x66b0f1: 7d11 JGE 0x0066b104
    if(integer::condition("JGE",flags)) goto L0066b104;
  }
  L0066b0f3: { // 0x66b0f3: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0066b0f7: { // 0x66b0f7: e8e489deff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,6729980u); flags=s.arithmetic_flags;
  }
  L0066b0fc: { // 0x66b0fc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0066b0fe: { // 0x66b0fe: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0066b102: { // 0x66b102: eb15 JMP 0x0066b119
    goto L0066b119;
  }
  L0066b104: { // 0x66b104: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0066b105: { // 0x66b105: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0066b109: { // 0x66b109: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0066b10d: { // 0x66b10d: e8ce89deff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,6730002u); flags=s.arithmetic_flags;
  }
  L0066b112: { // 0x66b112: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0066b114: { // 0x66b114: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0066b115: { // 0x66b115: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0066b119: { // 0x66b119: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0066b11b: { // 0x66b11b: 7d12 JGE 0x0066b12f
    if(integer::condition("JGE",flags)) goto L0066b12f;
  }
  L0066b11d: { // 0x66b11d: 81fe02400080 CMP ESI,0x80004002
    (void)integer::sub(s.si,0x80004002u,32,flags);
  }
  L0066b123: { // 0x66b123: 740a JZ 0x0066b12f
    if(integer::condition("JZ",flags)) goto L0066b12f;
  }
  L0066b125: { // 0x66b125: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0066b126: { // 0x66b126: e845611100 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,6730027u); flags=s.arithmetic_flags;
  }
  L0066b12b: { // 0x66b12b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0066b12f: { // 0x66b12f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0066b131: { // 0x66b131: 750a JNZ 0x0066b13d
    if(integer::condition("JNZ",flags)) goto L0066b13d;
  }
  L0066b133: { // 0x66b133: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0066b134: { // 0x66b134: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L0066b139: { // 0x66b139: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0066b13a: { // 0x66b13a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0066b13d: { // 0x66b13d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0066b13f: { // 0x66b13f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0066b140: { // 0x66b140: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b141: { // 0x66b141: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),6730052u); flags=s.arithmetic_flags;
  }
  L0066b144: { // 0x66b144: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0066b146: { // 0x66b146: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0066b14a: { // 0x66b14a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0066b14c: { // 0x66b14c: 7406 JZ 0x0066b154
    if(integer::condition("JZ",flags)) goto L0066b154;
  }
  L0066b14e: { // 0x66b14e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0066b150: { // 0x66b150: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b151: { // 0x66b151: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6730068u); flags=s.arithmetic_flags;
  }
  L0066b154: { // 0x66b154: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0066b156: { // 0x66b156: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0066b157: { // 0x66b157: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0066b158: { // 0x66b158: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006d6e90(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d6e90: { // 0x6d6e90: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006d6e91: { // 0x6d6e91: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L006d6e95: { // 0x6d6e95: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006d6e97: { // 0x6d6e97: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d6e98: { // 0x6d6e98: 750a JNZ 0x006d6ea4
    if(integer::condition("JNZ",flags)) goto L006d6ea4;
  }
  L006d6e9a: { // 0x6d6e9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d6e9b: { // 0x6d6e9b: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L006d6ea0: { // 0x6d6ea0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d6ea1: { // 0x6d6ea1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006d6ea4: { // 0x6d6ea4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006d6ea8: { // 0x6d6ea8: 8b5130 MOV EDX,dword ptr [ECX + 0x30]
    s.dx = m.r32((s.cx+0x00000030u));
  }
  L006d6eab: { // 0x6d6eab: 8d4130 LEA EAX,[ECX + 0x30]
    s.ax = (s.cx+0x00000030u);
  }
  L006d6eae: { // 0x6d6eae: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d6eb0: { // 0x6d6eb0: 745d JZ 0x006d6f0f
    if(integer::condition("JZ",flags)) goto L006d6f0f;
  }
  L006d6eb2: { // 0x6d6eb2: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L006d6eb4: { // 0x6d6eb4: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L006d6ebc: { // 0x6d6ebc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006d6ebe: { // 0x6d6ebe: 7423 JZ 0x006d6ee3
    if(integer::condition("JZ",flags)) goto L006d6ee3;
  }
  L006d6ec0: { // 0x6d6ec0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d6ec1: { // 0x6d6ec1: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L006d6ec5: { // 0x6d6ec5: e8a6d9d7ff CALL 0x00454870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454870u,7171786u); flags=s.arithmetic_flags;
  }
  L006d6eca: { // 0x6d6eca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d6ecc: { // 0x6d6ecc: 7d0d JGE 0x006d6edb
    if(integer::condition("JGE",flags)) goto L006d6edb;
  }
  L006d6ece: { // 0x6d6ece: 3d02400080 CMP EAX,0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L006d6ed3: { // 0x6d6ed3: 7406 JZ 0x006d6edb
    if(integer::condition("JZ",flags)) goto L006d6edb;
  }
  L006d6ed5: { // 0x6d6ed5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d6ed6: { // 0x6d6ed6: e895a30a00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,7171803u); flags=s.arithmetic_flags;
  }
  L006d6edb: { // 0x6d6edb: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L006d6edf: { // 0x6d6edf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d6ee1: { // 0x6d6ee1: 750a JNZ 0x006d6eed
    if(integer::condition("JNZ",flags)) goto L006d6eed;
  }
  L006d6ee3: { // 0x6d6ee3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d6ee4: { // 0x6d6ee4: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L006d6ee9: { // 0x6d6ee9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d6eea: { // 0x6d6eea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006d6eed: { // 0x6d6eed: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006d6eef: { // 0x6d6eef: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006d6ef0: { // 0x6d6ef0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d6ef1: { // 0x6d6ef1: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),7171828u); flags=s.arithmetic_flags;
  }
  L006d6ef4: { // 0x6d6ef4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006d6ef6: { // 0x6d6ef6: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L006d6efa: { // 0x6d6efa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d6efc: { // 0x6d6efc: 0f8492000000 JZ 0x006d6f94
    if(integer::condition("JZ",flags)) goto L006d6f94;
  }
  L006d6f02: { // 0x6d6f02: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006d6f04: { // 0x6d6f04: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d6f05: { // 0x6d6f05: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7171848u); flags=s.arithmetic_flags;
  }
  L006d6f08: { // 0x6d6f08: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006d6f0a: { // 0x6d6f0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d6f0b: { // 0x6d6f0b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d6f0c: { // 0x6d6f0c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006d6f0f: { // 0x6d6f0f: 8d41e8 LEA EAX,[ECX + -0x18]
    s.ax = (s.cx-0x00000018u);
  }
  L006d6f12: { // 0x6d6f12: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L006d6f1a: { // 0x6d6f1a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d6f1c: { // 0x6d6f1c: 7455 JZ 0x006d6f73
    if(integer::condition("JZ",flags)) goto L006d6f73;
  }
  L006d6f1e: { // 0x6d6f1e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006d6f20: { // 0x6d6f20: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L006d6f24: { // 0x6d6f24: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006d6f25: { // 0x6d6f25: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  L006d6f2a: { // 0x6d6f2a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d6f2b: { // 0x6d6f2b: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),7171885u); flags=s.arithmetic_flags;
  }
  L006d6f2d: { // 0x6d6f2d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006d6f2f: { // 0x6d6f2f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006d6f31: { // 0x6d6f31: 7d11 JGE 0x006d6f44
    if(integer::condition("JGE",flags)) goto L006d6f44;
  }
  L006d6f33: { // 0x6d6f33: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L006d6f37: { // 0x6d6f37: e8a4cbd7ff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,7171900u); flags=s.arithmetic_flags;
  }
  L006d6f3c: { // 0x6d6f3c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d6f3e: { // 0x6d6f3e: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006d6f42: { // 0x6d6f42: eb15 JMP 0x006d6f59
    goto L006d6f59;
  }
  L006d6f44: { // 0x6d6f44: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d6f45: { // 0x6d6f45: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L006d6f49: { // 0x6d6f49: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006d6f4d: { // 0x6d6f4d: e88ecbd7ff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,7171922u); flags=s.arithmetic_flags;
  }
  L006d6f52: { // 0x6d6f52: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006d6f54: { // 0x6d6f54: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006d6f55: { // 0x6d6f55: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006d6f59: { // 0x6d6f59: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006d6f5b: { // 0x6d6f5b: 7d12 JGE 0x006d6f6f
    if(integer::condition("JGE",flags)) goto L006d6f6f;
  }
  L006d6f5d: { // 0x6d6f5d: 81fe02400080 CMP ESI,0x80004002
    (void)integer::sub(s.si,0x80004002u,32,flags);
  }
  L006d6f63: { // 0x6d6f63: 740a JZ 0x006d6f6f
    if(integer::condition("JZ",flags)) goto L006d6f6f;
  }
  L006d6f65: { // 0x6d6f65: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d6f66: { // 0x6d6f66: e805a30a00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,7171947u); flags=s.arithmetic_flags;
  }
  L006d6f6b: { // 0x6d6f6b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006d6f6f: { // 0x6d6f6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d6f71: { // 0x6d6f71: 750a JNZ 0x006d6f7d
    if(integer::condition("JNZ",flags)) goto L006d6f7d;
  }
  L006d6f73: { // 0x6d6f73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d6f74: { // 0x6d6f74: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L006d6f79: { // 0x6d6f79: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d6f7a: { // 0x6d6f7a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006d6f7d: { // 0x6d6f7d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006d6f7f: { // 0x6d6f7f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006d6f80: { // 0x6d6f80: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d6f81: { // 0x6d6f81: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),7171972u); flags=s.arithmetic_flags;
  }
  L006d6f84: { // 0x6d6f84: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006d6f86: { // 0x6d6f86: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006d6f8a: { // 0x6d6f8a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d6f8c: { // 0x6d6f8c: 7406 JZ 0x006d6f94
    if(integer::condition("JZ",flags)) goto L006d6f94;
  }
  L006d6f8e: { // 0x6d6f8e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006d6f90: { // 0x6d6f90: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d6f91: { // 0x6d6f91: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7171988u); flags=s.arithmetic_flags;
  }
  L006d6f94: { // 0x6d6f94: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006d6f96: { // 0x6d6f96: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d6f97: { // 0x6d6f97: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d6f98: { // 0x6d6f98: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00714790(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00714790: { // 0x714790: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00714791: { // 0x714791: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L00714795: { // 0x714795: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00714797: { // 0x714797: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00714798: { // 0x714798: 750a JNZ 0x007147a4
    if(integer::condition("JNZ",flags)) goto L007147a4;
  }
  L0071479a: { // 0x71479a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0071479b: { // 0x71479b: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L007147a0: { // 0x7147a0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007147a1: { // 0x7147a1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007147a4: { // 0x7147a4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L007147a8: { // 0x7147a8: 8b5120 MOV EDX,dword ptr [ECX + 0x20]
    s.dx = m.r32((s.cx+0x00000020u));
  }
  L007147ab: { // 0x7147ab: 8d4120 LEA EAX,[ECX + 0x20]
    s.ax = (s.cx+0x00000020u);
  }
  L007147ae: { // 0x7147ae: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L007147b0: { // 0x7147b0: 745d JZ 0x0071480f
    if(integer::condition("JZ",flags)) goto L0071480f;
  }
  L007147b2: { // 0x7147b2: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L007147b4: { // 0x7147b4: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L007147bc: { // 0x7147bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L007147be: { // 0x7147be: 7423 JZ 0x007147e3
    if(integer::condition("JZ",flags)) goto L007147e3;
  }
  L007147c0: { // 0x7147c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007147c1: { // 0x7147c1: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L007147c5: { // 0x7147c5: e8a600d4ff CALL 0x00454870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454870u,7423946u); flags=s.arithmetic_flags;
  }
  L007147ca: { // 0x7147ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007147cc: { // 0x7147cc: 7d0d JGE 0x007147db
    if(integer::condition("JGE",flags)) goto L007147db;
  }
  L007147ce: { // 0x7147ce: 3d02400080 CMP EAX,0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L007147d3: { // 0x7147d3: 7406 JZ 0x007147db
    if(integer::condition("JZ",flags)) goto L007147db;
  }
  L007147d5: { // 0x7147d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007147d6: { // 0x7147d6: e895ca0600 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,7423963u); flags=s.arithmetic_flags;
  }
  L007147db: { // 0x7147db: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007147df: { // 0x7147df: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007147e1: { // 0x7147e1: 750a JNZ 0x007147ed
    if(integer::condition("JNZ",flags)) goto L007147ed;
  }
  L007147e3: { // 0x7147e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007147e4: { // 0x7147e4: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L007147e9: { // 0x7147e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007147ea: { // 0x7147ea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007147ed: { // 0x7147ed: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L007147ef: { // 0x7147ef: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007147f0: { // 0x7147f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007147f1: { // 0x7147f1: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),7423988u); flags=s.arithmetic_flags;
  }
  L007147f4: { // 0x7147f4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L007147f6: { // 0x7147f6: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007147fa: { // 0x7147fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007147fc: { // 0x7147fc: 0f8492000000 JZ 0x00714894
    if(integer::condition("JZ",flags)) goto L00714894;
  }
  L00714802: { // 0x714802: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00714804: { // 0x714804: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00714805: { // 0x714805: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7424008u); flags=s.arithmetic_flags;
  }
  L00714808: { // 0x714808: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0071480a: { // 0x71480a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0071480b: { // 0x71480b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0071480c: { // 0x71480c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0071480f: { // 0x71480f: 8d41e8 LEA EAX,[ECX + -0x18]
    s.ax = (s.cx-0x00000018u);
  }
  L00714812: { // 0x714812: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L0071481a: { // 0x71481a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0071481c: { // 0x71481c: 7455 JZ 0x00714873
    if(integer::condition("JZ",flags)) goto L00714873;
  }
  L0071481e: { // 0x71481e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00714820: { // 0x714820: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L00714824: { // 0x714824: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00714825: { // 0x714825: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  L0071482a: { // 0x71482a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071482b: { // 0x71482b: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),7424045u); flags=s.arithmetic_flags;
  }
  L0071482d: { // 0x71482d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0071482f: { // 0x71482f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00714831: { // 0x714831: 7d11 JGE 0x00714844
    if(integer::condition("JGE",flags)) goto L00714844;
  }
  L00714833: { // 0x714833: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00714837: { // 0x714837: e8a4f2d3ff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,7424060u); flags=s.arithmetic_flags;
  }
  L0071483c: { // 0x71483c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0071483e: { // 0x71483e: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00714842: { // 0x714842: eb15 JMP 0x00714859
    goto L00714859;
  }
  L00714844: { // 0x714844: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00714845: { // 0x714845: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00714849: { // 0x714849: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0071484d: { // 0x71484d: e88ef2d3ff CALL 0x00453ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ae0u,7424082u); flags=s.arithmetic_flags;
  }
  L00714852: { // 0x714852: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00714854: { // 0x714854: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00714855: { // 0x714855: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00714859: { // 0x714859: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0071485b: { // 0x71485b: 7d12 JGE 0x0071486f
    if(integer::condition("JGE",flags)) goto L0071486f;
  }
  L0071485d: { // 0x71485d: 81fe02400080 CMP ESI,0x80004002
    (void)integer::sub(s.si,0x80004002u,32,flags);
  }
  L00714863: { // 0x714863: 740a JZ 0x0071486f
    if(integer::condition("JZ",flags)) goto L0071486f;
  }
  L00714865: { // 0x714865: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00714866: { // 0x714866: e805ca0600 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,7424107u); flags=s.arithmetic_flags;
  }
  L0071486b: { // 0x71486b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0071486f: { // 0x71486f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00714871: { // 0x714871: 750a JNZ 0x0071487d
    if(integer::condition("JNZ",flags)) goto L0071487d;
  }
  L00714873: { // 0x714873: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00714874: { // 0x714874: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  L00714879: { // 0x714879: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0071487a: { // 0x71487a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0071487d: { // 0x71487d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0071487f: { // 0x71487f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00714880: { // 0x714880: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00714881: { // 0x714881: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),7424132u); flags=s.arithmetic_flags;
  }
  L00714884: { // 0x714884: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00714886: { // 0x714886: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0071488a: { // 0x71488a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0071488c: { // 0x71488c: 7406 JZ 0x00714894
    if(integer::condition("JZ",flags)) goto L00714894;
  }
  L0071488e: { // 0x71488e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00714890: { // 0x714890: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00714891: { // 0x714891: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7424148u); flags=s.arithmetic_flags;
  }
  L00714894: { // 0x714894: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00714896: { // 0x714896: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00714897: { // 0x714897: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00714898: { // 0x714898: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
