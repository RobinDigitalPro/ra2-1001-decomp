#include "recovered/recovery_b816_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b816 {
namespace {
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x0062fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x0062fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI,0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX,0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x0062fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x0062fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI,EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x0062fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x0062fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x0062fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x0062fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI,dword ptr [EDX + ECX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX,[EDX + ECX*0x4 + 0xc]
    s.ax = (s.dx+(s.cx * 0x00000004u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX,dword ptr [EDX + ECX*0x4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI,dword ptr [EDX + EAX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX,0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x0062fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 0x4],0x0
    m.w32((s.dx+0x00000004u), 0x00000000u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX,0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x0062fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 0x8],0x0
    m.w32((s.dx+0x00000008u), 0x00000000u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX,EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x0062fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6487616u:f_0022fe40(m,s,child,{});break;
default:throw std::domain_error("recovery816 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00668e20(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00668e20: { // 0x668e20: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00668e23: { // 0x668e23: a1b87da200 MOV EAX,[0x00a27db8]
    s.ax = m.r32((0x00a27db8u));
  }
  L00668e28: { // 0x668e28: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00668e29: { // 0x668e29: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00668e2a: { // 0x668e2a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00668e2c: { // 0x668e2c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00668e2d: { // 0x668e2d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00668e2e: { // 0x668e2e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00668e30: { // 0x668e30: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00668e34: { // 0x668e34: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00668e38: { // 0x668e38: 0f8eed000000 JLE 0x00668f2b
    if(integer::condition("JLE",flags)) goto L00668f2b;
  }
  L00668e3e: { // 0x668e3e: a1ac7da200 MOV EAX,[0x00a27dac]
    s.ax = m.r32((0x00a27dacu));
  }
  L00668e43: { // 0x668e43: 8b1ca8 MOV EBX,dword ptr [EAX + EBP*0x4]
    s.bx = m.r32((s.ax+(s.bp * 0x00000004u)));
  }
  L00668e46: { // 0x668e46: 837b4dfe CMP dword ptr [EBX + 0x4d],-0x2
    (void)integer::sub(m.r32((s.bx+0x0000004du)),0xfffffffeu,32,flags);
  }
  L00668e4a: { // 0x668e4a: 7559 JNZ 0x00668ea5
    if(integer::condition("JNZ",flags)) goto L00668ea5;
  }
  L00668e4c: { // 0x668e4c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00668e50: { // 0x668e50: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L00668e53: { // 0x668e53: 897b4d MOV dword ptr [EBX + 0x4d],EDI
    m.w32((s.bx+0x0000004du), s.di);
  }
  L00668e56: { // 0x668e56: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00668e59: { // 0x668e59: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00668e5b: { // 0x668e5b: 740a JZ 0x00668e67
    if(integer::condition("JZ",flags)) goto L00668e67;
  }
  L00668e5d: { // 0x668e5d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00668e5f: { // 0x668e5f: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6721122u); flags=s.arithmetic_flags;
  }
  L00668e62: { // 0x668e62: 894349 MOV dword ptr [EBX + 0x49],EAX
    m.w32((s.bx+0x00000049u), s.ax);
  }
  L00668e65: { // 0x668e65: eb41 JMP 0x00668ea8
    goto L00668ea8;
  }
  L00668e67: { // 0x668e67: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  L00668e6c: { // 0x668e6c: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  L00668e6f: { // 0x668e6f: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00668e75: { // 0x668e75: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00668e76: { // 0x668e76: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00668e78: { // 0x668e78: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00668e7e: { // 0x668e7e: e8bd6ffcff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6721155u); flags=s.arithmetic_flags;
  }
  L00668e83: { // 0x668e83: 8b153ce0a100 MOV EDX,dword ptr [0x00a1e03c]
    s.dx = m.r32((0x00a1e03cu));
  }
  L00668e89: { // 0x668e89: 8b0c82 MOV ECX,dword ptr [EDX + EAX*0x4]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00668e8c: { // 0x668e8c: 8a91a5010000 MOV DL,byte ptr [ECX + 0x1a5]
    s.dx = with_al(s.dx, m.r8((s.cx+0x000001a5u)));
  }
  L00668e92: { // 0x668e92: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00668e94: { // 0x668e94: 74d9 JZ 0x00668e6f
    if(integer::condition("JZ",flags)) goto L00668e6f;
  }
  L00668e96: { // 0x668e96: 8a91a6010000 MOV DL,byte ptr [ECX + 0x1a6]
    s.dx = with_al(s.dx, m.r8((s.cx+0x000001a6u)));
  }
  L00668e9c: { // 0x668e9c: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00668e9e: { // 0x668e9e: 75cf JNZ 0x00668e6f
    if(integer::condition("JNZ",flags)) goto L00668e6f;
  }
  L00668ea0: { // 0x668ea0: 894349 MOV dword ptr [EBX + 0x49],EAX
    m.w32((s.bx+0x00000049u), s.ax);
  }
  L00668ea3: { // 0x668ea3: eb03 JMP 0x00668ea8
    goto L00668ea8;
  }
  L00668ea5: { // 0x668ea5: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L00668ea8: { // 0x668ea8: 837b55fe CMP dword ptr [EBX + 0x55],-0x2
    (void)integer::sub(m.r32((s.bx+0x00000055u)),0xfffffffeu,32,flags);
  }
  L00668eac: { // 0x668eac: 7570 JNZ 0x00668f1e
    if(integer::condition("JNZ",flags)) goto L00668f1e;
  }
  L00668eae: { // 0x668eae: 897b55 MOV dword ptr [EBX + 0x55],EDI
    m.w32((s.bx+0x00000055u), s.di);
  }
  L00668eb1: { // 0x668eb1: 897b51 MOV dword ptr [EBX + 0x51],EDI
    m.w32((s.bx+0x00000051u), s.di);
  }
  L00668eb4: { // 0x668eb4: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00668eb9: { // 0x668eb9: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00668ebb: { // 0x668ebb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00668ebd: { // 0x668ebd: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00668ec3: { // 0x668ec3: e8786ffcff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6721224u); flags=s.arithmetic_flags;
  }
  L00668ec8: { // 0x668ec8: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L00668ecb: { // 0x668ecb: 744e JZ 0x00668f1b
    if(integer::condition("JZ",flags)) goto L00668f1b;
  }
  L00668ecd: { // 0x668ecd: 8b3db87da200 MOV EDI,dword ptr [0x00a27db8]
    s.di = m.r32((0x00a27db8u));
  }
  L00668ed3: { // 0x668ed3: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00668ed5: { // 0x668ed5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00668ed7: { // 0x668ed7: 7e2a JLE 0x00668f03
    if(integer::condition("JLE",flags)) goto L00668f03;
  }
  L00668ed9: { // 0x668ed9: 8b35ac7da200 MOV ESI,dword ptr [0x00a27dac]
    s.si = m.r32((0x00a27dacu));
  }
  L00668edf: { // 0x668edf: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00668ee1: { // 0x668ee1: 837955fe CMP dword ptr [ECX + 0x55],-0x2
    (void)integer::sub(m.r32((s.cx+0x00000055u)),0xfffffffeu,32,flags);
  }
  L00668ee5: { // 0x668ee5: 750d JNZ 0x00668ef4
    if(integer::condition("JNZ",flags)) goto L00668ef4;
  }
  L00668ee7: { // 0x668ee7: 837951ff CMP dword ptr [ECX + 0x51],-0x1
    (void)integer::sub(m.r32((s.cx+0x00000051u)),0xffffffffu,32,flags);
  }
  L00668eeb: { // 0x668eeb: 7507 JNZ 0x00668ef4
    if(integer::condition("JNZ",flags)) goto L00668ef4;
  }
  L00668eed: { // 0x668eed: b9feffffff MOV ECX,0xfffffffe
    s.cx = 0xfffffffeu;
  }
  L00668ef2: { // 0x668ef2: eb03 JMP 0x00668ef7
    goto L00668ef7;
  }
  L00668ef4: { // 0x668ef4: 8b4951 MOV ECX,dword ptr [ECX + 0x51]
    s.cx = m.r32((s.cx+0x00000051u));
  }
  L00668ef7: { // 0x668ef7: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00668ef9: { // 0x668ef9: 74b9 JZ 0x00668eb4
    if(integer::condition("JZ",flags)) goto L00668eb4;
  }
  L00668efb: { // 0x668efb: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00668efc: { // 0x668efc: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L00668eff: { // 0x668eff: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00668f01: { // 0x668f01: 7cdc JL 0x00668edf
    if(integer::condition("JL",flags)) goto L00668edf;
  }
  L00668f03: { // 0x668f03: b984000000 MOV ECX,0x84
    s.cx = 0x00000084u;
  }
  L00668f08: { // 0x668f08: 3981c855a200 CMP dword ptr [ECX + 0xa255c8],EAX
    (void)integer::sub(m.r32((s.cx+0x00a255c8u)),s.ax,32,flags);
  }
  L00668f0e: { // 0x668f0e: 74a4 JZ 0x00668eb4
    if(integer::condition("JZ",flags)) goto L00668eb4;
  }
  L00668f10: { // 0x668f10: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L00668f13: { // 0x668f13: 81f9a4000000 CMP ECX,0xa4
    (void)integer::sub(s.cx,0x000000a4u,32,flags);
  }
  L00668f19: { // 0x668f19: 7ced JL 0x00668f08
    if(integer::condition("JL",flags)) goto L00668f08;
  }
  L00668f1b: { // 0x668f1b: 894351 MOV dword ptr [EBX + 0x51],EAX
    m.w32((s.bx+0x00000051u), s.ax);
  }
  L00668f1e: { // 0x668f1e: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00668f22: { // 0x668f22: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00668f23: { // 0x668f23: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00668f25: { // 0x668f25: 0f8c13ffffff JL 0x00668e3e
    if(integer::condition("JL",flags)) goto L00668e3e;
  }
  L00668f2b: { // 0x668f2b: bb2c56a200 MOV EBX,0xa2562c
    s.bx = 0x00a2562cu;
  }
  L00668f30: { // 0x668f30: 833bfe CMP dword ptr [EBX],-0x2
    (void)integer::sub(m.r32((s.bx)),0xfffffffeu,32,flags);
  }
  L00668f33: { // 0x668f33: 754d JNZ 0x00668f82
    if(integer::condition("JNZ",flags)) goto L00668f82;
  }
  L00668f35: { // 0x668f35: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00668f39: { // 0x668f39: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00668f3c: { // 0x668f3c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00668f3e: { // 0x668f3e: 7407 JZ 0x00668f47
    if(integer::condition("JZ",flags)) goto L00668f47;
  }
  L00668f40: { // 0x668f40: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00668f42: { // 0x668f42: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),6721349u); flags=s.arithmetic_flags;
  }
  L00668f45: { // 0x668f45: eb39 JMP 0x00668f80
    goto L00668f80;
  }
  L00668f47: { // 0x668f47: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  L00668f4c: { // 0x668f4c: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  L00668f4f: { // 0x668f4f: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00668f55: { // 0x668f55: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00668f56: { // 0x668f56: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00668f58: { // 0x668f58: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00668f5e: { // 0x668f5e: e8dd6efcff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6721379u); flags=s.arithmetic_flags;
  }
  L00668f63: { // 0x668f63: 8b153ce0a100 MOV EDX,dword ptr [0x00a1e03c]
    s.dx = m.r32((0x00a1e03cu));
  }
  L00668f69: { // 0x668f69: 8b0c82 MOV ECX,dword ptr [EDX + EAX*0x4]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00668f6c: { // 0x668f6c: 8a91a5010000 MOV DL,byte ptr [ECX + 0x1a5]
    s.dx = with_al(s.dx, m.r8((s.cx+0x000001a5u)));
  }
  L00668f72: { // 0x668f72: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00668f74: { // 0x668f74: 74d9 JZ 0x00668f4f
    if(integer::condition("JZ",flags)) goto L00668f4f;
  }
  L00668f76: { // 0x668f76: 8a91a6010000 MOV DL,byte ptr [ECX + 0x1a6]
    s.dx = with_al(s.dx, m.r8((s.cx+0x000001a6u)));
  }
  L00668f7c: { // 0x668f7c: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00668f7e: { // 0x668f7e: 75cf JNZ 0x00668f4f
    if(integer::condition("JNZ",flags)) goto L00668f4f;
  }
  L00668f80: { // 0x668f80: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L00668f82: { // 0x668f82: 837b20fe CMP dword ptr [EBX + 0x20],-0x2
    (void)integer::sub(m.r32((s.bx+0x00000020u)),0xfffffffeu,32,flags);
  }
  L00668f86: { // 0x668f86: 756a JNZ 0x00668ff2
    if(integer::condition("JNZ",flags)) goto L00668ff2;
  }
  L00668f88: { // 0x668f88: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00668f8d: { // 0x668f8d: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00668f8f: { // 0x668f8f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00668f91: { // 0x668f91: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00668f97: { // 0x668f97: e8a46efcff CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6721436u); flags=s.arithmetic_flags;
  }
  L00668f9c: { // 0x668f9c: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L00668f9f: { // 0x668f9f: 744e JZ 0x00668fef
    if(integer::condition("JZ",flags)) goto L00668fef;
  }
  L00668fa1: { // 0x668fa1: 8b3db87da200 MOV EDI,dword ptr [0x00a27db8]
    s.di = m.r32((0x00a27db8u));
  }
  L00668fa7: { // 0x668fa7: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00668fa9: { // 0x668fa9: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00668fab: { // 0x668fab: 7e2a JLE 0x00668fd7
    if(integer::condition("JLE",flags)) goto L00668fd7;
  }
  L00668fad: { // 0x668fad: 8b35ac7da200 MOV ESI,dword ptr [0x00a27dac]
    s.si = m.r32((0x00a27dacu));
  }
  L00668fb3: { // 0x668fb3: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00668fb5: { // 0x668fb5: 837955fe CMP dword ptr [ECX + 0x55],-0x2
    (void)integer::sub(m.r32((s.cx+0x00000055u)),0xfffffffeu,32,flags);
  }
  L00668fb9: { // 0x668fb9: 750d JNZ 0x00668fc8
    if(integer::condition("JNZ",flags)) goto L00668fc8;
  }
  L00668fbb: { // 0x668fbb: 837951ff CMP dword ptr [ECX + 0x51],-0x1
    (void)integer::sub(m.r32((s.cx+0x00000051u)),0xffffffffu,32,flags);
  }
  L00668fbf: { // 0x668fbf: 7507 JNZ 0x00668fc8
    if(integer::condition("JNZ",flags)) goto L00668fc8;
  }
  L00668fc1: { // 0x668fc1: b9feffffff MOV ECX,0xfffffffe
    s.cx = 0xfffffffeu;
  }
  L00668fc6: { // 0x668fc6: eb03 JMP 0x00668fcb
    goto L00668fcb;
  }
  L00668fc8: { // 0x668fc8: 8b4951 MOV ECX,dword ptr [ECX + 0x51]
    s.cx = m.r32((s.cx+0x00000051u));
  }
  L00668fcb: { // 0x668fcb: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00668fcd: { // 0x668fcd: 74b9 JZ 0x00668f88
    if(integer::condition("JZ",flags)) goto L00668f88;
  }
  L00668fcf: { // 0x668fcf: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00668fd0: { // 0x668fd0: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L00668fd3: { // 0x668fd3: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00668fd5: { // 0x668fd5: 7cdc JL 0x00668fb3
    if(integer::condition("JL",flags)) goto L00668fb3;
  }
  L00668fd7: { // 0x668fd7: b984000000 MOV ECX,0x84
    s.cx = 0x00000084u;
  }
  L00668fdc: { // 0x668fdc: 3981c855a200 CMP dword ptr [ECX + 0xa255c8],EAX
    (void)integer::sub(m.r32((s.cx+0x00a255c8u)),s.ax,32,flags);
  }
  L00668fe2: { // 0x668fe2: 74a4 JZ 0x00668f88
    if(integer::condition("JZ",flags)) goto L00668f88;
  }
  L00668fe4: { // 0x668fe4: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L00668fe7: { // 0x668fe7: 81f9a4000000 CMP ECX,0xa4
    (void)integer::sub(s.cx,0x000000a4u,32,flags);
  }
  L00668fed: { // 0x668fed: 7ced JL 0x00668fdc
    if(integer::condition("JL",flags)) goto L00668fdc;
  }
  L00668fef: { // 0x668fef: 894320 MOV dword ptr [EBX + 0x20],EAX
    m.w32((s.bx+0x00000020u), s.ax);
  }
  L00668ff2: { // 0x668ff2: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L00668ff5: { // 0x668ff5: 81fb4c56a200 CMP EBX,0xa2564c
    (void)integer::sub(s.bx,0x00a2564cu,32,flags);
  }
  L00668ffb: { // 0x668ffb: 0f8c2fffffff JL 0x00668f30
    if(integer::condition("JL",flags)) goto L00668f30;
  }
  L00669001: { // 0x669001: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00669002: { // 0x669002: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00669003: { // 0x669003: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00669004: { // 0x669004: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00669005: { // 0x669005: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00669008: { // 0x669008: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
