#include "recovered/recovery_b666_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b666 {
namespace {
void f_00023ec0(Memory&,State&,Frame&,const Operations&);
void f_00294150(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00023ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00423ec0: { // 0x423ec0: b804000000 MOV EAX, 4
    s.ax = 4u;
  }
  L00423ec5: { // 0x423ec5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00294150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00694150: { // 0x694150: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00694154: { // 0x694154: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00694155: { // 0x694155: 8b7128 MOV ESI, dword ptr [ECX + 0x28]
    s.si = m.r32((s.cx+0x00000028u));
  }
  L00694158: { // 0x694158: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0069415a: { // 0x69415a: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0069415c: { // 0x69415c: 7503 JNZ 0x694161
    if(integer::condition("JNZ",flags)) goto L00694161;
  }
  L0069415e: { // 0x69415e: 895128 MOV dword ptr [ECX + 0x28], EDX
    m.w32((s.cx+0x00000028u), s.dx);
  }
  L00694161: { // 0x694161: 3b4124 CMP EAX, dword ptr [ECX + 0x24]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000024u)),32,flags);
  }
  L00694164: { // 0x694164: 7503 JNZ 0x694169
    if(integer::condition("JNZ",flags)) goto L00694169;
  }
  L00694166: { // 0x694166: 895124 MOV dword ptr [ECX + 0x24], EDX
    m.w32((s.cx+0x00000024u), s.dx);
  }
  L00694169: { // 0x694169: 8b7150 MOV ESI, dword ptr [ECX + 0x50]
    s.si = m.r32((s.cx+0x00000050u));
  }
  L0069416c: { // 0x69416c: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0069416e: { // 0x69416e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069416f: { // 0x69416f: 7507 JNZ 0x694178
    if(integer::condition("JNZ",flags)) goto L00694178;
  }
  L00694171: { // 0x694171: 895150 MOV dword ptr [ECX + 0x50], EDX
    m.w32((s.cx+0x00000050u), s.dx);
  }
  L00694174: { // 0x694174: c6415401 MOV byte ptr [ECX + 0x54], 1
    m.w8((s.cx+0x00000054u), 1u);
  }
  L00694178: { // 0x694178: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4341440u:f_00023ec0(m,s,child,{});break;
case 6898000u:f_00294150(m,s,child,{});break;
default:throw std::domain_error("recovery666 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006e1e50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e1e50: { // 0x6e1e50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e1e51: { // 0x6e1e51: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006e1e52: { // 0x6e1e52: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006e1e53: { // 0x6e1e53: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1e54: { // 0x6e1e54: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006e1e56: { // 0x6e1e56: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1e57: { // 0x6e1e57: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006e1e59: { // 0x6e1e59: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006e1e5b: { // 0x6e1e5b: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7216734u); flags=s.arithmetic_flags;
  }
  L006e1e5e: { // 0x6e1e5e: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006e1e60: { // 0x6e1e60: a1c0b98100 MOV EAX,[0x0081b9c0]
    s.ax = m.r32((0x0081b9c0u));
  }
  L006e1e65: { // 0x6e1e65: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L006e1e67: { // 0x6e1e67: 750a JNZ 0x006e1e73
    if(integer::condition("JNZ",flags)) goto L006e1e73;
  }
  L006e1e69: { // 0x6e1e69: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L006e1e6b: { // 0x6e1e6b: 892dc0b98100 MOV dword ptr [0x0081b9c0],EBP
    m.w32((0x0081b9c0u), s.bp);
  }
  L006e1e71: { // 0x6e1e71: eb02 JMP 0x006e1e75
    goto L006e1e75;
  }
  L006e1e73: { // 0x6e1e73: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L006e1e75: { // 0x6e1e75: 3935c4b98100 CMP dword ptr [0x0081b9c4],ESI
    (void)integer::sub(m.r32((0x0081b9c4u)),s.si,32,flags);
  }
  L006e1e7b: { // 0x6e1e7b: 7511 JNZ 0x006e1e8e
    if(integer::condition("JNZ",flags)) goto L006e1e8e;
  }
  L006e1e7d: { // 0x6e1e7d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006e1e7e: { // 0x6e1e7e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006e1e83: { // 0x6e1e83: 892dc4b98100 MOV dword ptr [0x0081b9c4],EBP
    m.w32((0x0081b9c4u), s.bp);
  }
  L006e1e89: { // 0x6e1e89: e8626edbff CALL 0x00498cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00498cf0u,7216782u); flags=s.arithmetic_flags;
  }
  L006e1e8e: { // 0x6e1e8e: 83fb18 CMP EBX,0x18
    (void)integer::sub(s.bx,0x00000018u,32,flags);
  }
  L006e1e91: { // 0x6e1e91: 0f85a5000000 JNZ 0x006e1f3c
    if(integer::condition("JNZ",flags)) goto L006e1f3c;
  }
  L006e1e97: { // 0x6e1e97: 3b356089a200 CMP ESI,dword ptr [0x00a28960]
    (void)integer::sub(s.si,m.r32((0x00a28960u)),32,flags);
  }
  L006e1e9d: { // 0x6e1e9d: 7506 JNZ 0x006e1ea5
    if(integer::condition("JNZ",flags)) goto L006e1ea5;
  }
  L006e1e9f: { // 0x6e1e9f: 892d6089a200 MOV dword ptr [0x00a28960],EBP
    m.w32((0x00a28960u), s.bp);
  }
  L006e1ea5: { // 0x6e1ea5: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L006e1ea7: { // 0x6e1ea7: 0f8402010000 JZ 0x006e1faf
    if(integer::condition("JZ",flags)) goto L006e1faf;
  }
  L006e1ead: { // 0x6e1ead: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L006e1eb0: { // 0x6e1eb0: d0e8 SHR AL,0x1
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),0x00000001u,8,flags,integer::Shift::right));
  }
  L006e1eb2: { // 0x6e1eb2: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L006e1eb4: { // 0x6e1eb4: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L006e1eb8: { // 0x6e1eb8: 0f84f1000000 JZ 0x006e1faf
    if(integer::condition("JZ",flags)) goto L006e1faf;
  }
  L006e1ebe: { // 0x6e1ebe: a17888aa00 MOV EAX,[0x00aa8878]
    s.ax = m.r32((0x00aa8878u));
  }
  L006e1ec3: { // 0x6e1ec3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006e1ec5: { // 0x6e1ec5: 7e1a JLE 0x006e1ee1
    if(integer::condition("JLE",flags)) goto L006e1ee1;
  }
  L006e1ec7: { // 0x6e1ec7: 8b0d6c88aa00 MOV ECX,dword ptr [0x00aa886c]
    s.cx = m.r32((0x00aa886cu));
  }
  L006e1ecd: { // 0x6e1ecd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1ece: { // 0x6e1ece: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1ecf: { // 0x6e1ecf: 8b0ca9 MOV ECX,dword ptr [ECX + EBP*0x4]
    s.cx = m.r32((s.cx+(s.bp * 0x00000004u)));
  }
  L006e1ed2: { // 0x6e1ed2: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e1ed4: { // 0x6e1ed4: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7216855u); flags=s.arithmetic_flags;
  }
  L006e1ed7: { // 0x6e1ed7: a17888aa00 MOV EAX,[0x00aa8878]
    s.ax = m.r32((0x00aa8878u));
  }
  L006e1edc: { // 0x6e1edc: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L006e1edd: { // 0x6e1edd: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L006e1edf: { // 0x6e1edf: 7ce6 JL 0x006e1ec7
    if(integer::condition("JL",flags)) goto L006e1ec7;
  }
  L006e1ee1: { // 0x6e1ee1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1ee2: { // 0x6e1ee2: b920a68100 MOV ECX,0x81a620
    s.cx = 0x0081a620u;
  }
  L006e1ee7: { // 0x6e1ee7: e8a446d5ff CALL 0x00436590
    s.arithmetic_flags=flags; invoke(m,s,f,0x00436590u,7216876u); flags=s.arithmetic_flags;
  }
  L006e1eec: { // 0x6e1eec: b95860a500 MOV ECX,0xa56058
    s.cx = 0x00a56058u;
  }
  L006e1ef1: { // 0x6e1ef1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1ef2: { // 0x6e1ef2: e8e9dbe4ff CALL 0x0052fae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0052fae0u,7216887u); flags=s.arithmetic_flags;
  }
  L006e1ef7: { // 0x6e1ef7: 83fb0f CMP EBX,0xf
    (void)integer::sub(s.bx,0x0000000fu,32,flags);
  }
  L006e1efa: { // 0x6e1efa: 740a JZ 0x006e1f06
    if(integer::condition("JZ",flags)) goto L006e1f06;
  }
  L006e1efc: { // 0x6e1efc: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L006e1eff: { // 0x6e1eff: 7405 JZ 0x006e1f06
    if(integer::condition("JZ",flags)) goto L006e1f06;
  }
  L006e1f01: { // 0x6e1f01: 83fb02 CMP EBX,0x2
    (void)integer::sub(s.bx,0x00000002u,32,flags);
  }
  L006e1f04: { // 0x6e1f04: 750b JNZ 0x006e1f11
    if(integer::condition("JNZ",flags)) goto L006e1f11;
  }
  L006e1f06: { // 0x6e1f06: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1f07: { // 0x6e1f07: b9e0218200 MOV ECX,0x8221e0
    s.cx = 0x008221e0u;
  }
  L006e1f0c: { // 0x6e1f0c: e8bf12d3ff CALL 0x004131d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004131d0u,7216913u); flags=s.arithmetic_flags;
  }
  L006e1f11: { // 0x6e1f11: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006e1f13: { // 0x6e1f13: e898a80000 CALL 0x006ec7b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006ec7b0u,7216920u); flags=s.arithmetic_flags;
  }
  L006e1f18: { // 0x6e1f18: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L006e1f1e: { // 0x6e1f1e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006e1f20: { // 0x6e1f20: 7408 JZ 0x006e1f2a
    if(integer::condition("JZ",flags)) goto L006e1f2a;
  }
  L006e1f22: { // 0x6e1f22: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006e1f24: { // 0x6e1f24: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006e1f26: { // 0x6e1f26: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1f27: { // 0x6e1f27: ff5028 CALL dword ptr [EAX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000028u)),7216938u); flags=s.arithmetic_flags;
  }
  L006e1f2a: { // 0x6e1f2a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1f2b: { // 0x6e1f2b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1f2c: { // 0x6e1f2c: b9b0a78100 MOV ECX,0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  L006e1f31: { // 0x6e1f31: e8baa3e5ff CALL 0x0053c2f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053c2f0u,7216950u); flags=s.arithmetic_flags;
  }
  L006e1f36: { // 0x6e1f36: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e1f37: { // 0x6e1f37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e1f38: { // 0x6e1f38: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e1f39: { // 0x6e1f39: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e1f3a: { // 0x6e1f3a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e1f3b: { // 0x6e1f3b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e1f3c: { // 0x6e1f3c: 83fb0d CMP EBX,0xd
    (void)integer::sub(s.bx,0x0000000du,32,flags);
  }
  L006e1f3f: { // 0x6e1f3f: 7537 JNZ 0x006e1f78
    if(integer::condition("JNZ",flags)) goto L006e1f78;
  }
  L006e1f41: { // 0x6e1f41: a12088aa00 MOV EAX,[0x00aa8820]
    s.ax = m.r32((0x00aa8820u));
  }
  L006e1f46: { // 0x6e1f46: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e1f48: { // 0x6e1f48: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e1f4a: { // 0x6e1f4a: 7e1a JLE 0x006e1f66
    if(integer::condition("JLE",flags)) goto L006e1f66;
  }
  L006e1f4c: { // 0x6e1f4c: 8b0d1488aa00 MOV ECX,dword ptr [0x00aa8814]
    s.cx = m.r32((0x00aa8814u));
  }
  L006e1f52: { // 0x6e1f52: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1f53: { // 0x6e1f53: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1f54: { // 0x6e1f54: 8b0c99 MOV ECX,dword ptr [ECX + EBX*0x4]
    s.cx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L006e1f57: { // 0x6e1f57: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e1f59: { // 0x6e1f59: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7216988u); flags=s.arithmetic_flags;
  }
  L006e1f5c: { // 0x6e1f5c: a12088aa00 MOV EAX,[0x00aa8820]
    s.ax = m.r32((0x00aa8820u));
  }
  L006e1f61: { // 0x6e1f61: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e1f62: { // 0x6e1f62: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e1f64: { // 0x6e1f64: 7ce6 JL 0x006e1f4c
    if(integer::condition("JL",flags)) goto L006e1f4c;
  }
  L006e1f66: { // 0x6e1f66: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1f67: { // 0x6e1f67: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1f68: { // 0x6e1f68: b9b0a78100 MOV ECX,0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  L006e1f6d: { // 0x6e1f6d: e87ea3e5ff CALL 0x0053c2f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053c2f0u,7217010u); flags=s.arithmetic_flags;
  }
  L006e1f72: { // 0x6e1f72: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e1f73: { // 0x6e1f73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e1f74: { // 0x6e1f74: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e1f75: { // 0x6e1f75: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e1f76: { // 0x6e1f76: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e1f77: { // 0x6e1f77: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e1f78: { // 0x6e1f78: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L006e1f7b: { // 0x6e1f7b: 0f8524ffffff JNZ 0x006e1ea5
    if(integer::condition("JNZ",flags)) goto L006e1ea5;
  }
  L006e1f81: { // 0x6e1f81: a11087aa00 MOV EAX,[0x00aa8710]
    s.ax = m.r32((0x00aa8710u));
  }
  L006e1f86: { // 0x6e1f86: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e1f88: { // 0x6e1f88: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e1f8a: { // 0x6e1f8a: 0f8edb010000 JLE 0x006e216b
    if(integer::condition("JLE",flags)) goto L006e216b;
  }
  L006e1f90: { // 0x6e1f90: a10487aa00 MOV EAX,[0x00aa8704]
    s.ax = m.r32((0x00aa8704u));
  }
  L006e1f95: { // 0x6e1f95: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1f96: { // 0x6e1f96: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1f97: { // 0x6e1f97: 8b0c98 MOV ECX,dword ptr [EAX + EBX*0x4]
    s.cx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006e1f9a: { // 0x6e1f9a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e1f9c: { // 0x6e1f9c: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217055u); flags=s.arithmetic_flags;
  }
  L006e1f9f: { // 0x6e1f9f: a11087aa00 MOV EAX,[0x00aa8710]
    s.ax = m.r32((0x00aa8710u));
  }
  L006e1fa4: { // 0x6e1fa4: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e1fa5: { // 0x6e1fa5: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e1fa7: { // 0x6e1fa7: 7ce7 JL 0x006e1f90
    if(integer::condition("JL",flags)) goto L006e1f90;
  }
  L006e1fa9: { // 0x6e1fa9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e1faa: { // 0x6e1faa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e1fab: { // 0x6e1fab: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e1fac: { // 0x6e1fac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e1fad: { // 0x6e1fad: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e1fae: { // 0x6e1fae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e1faf: { // 0x6e1faf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006e1fb0: { // 0x6e1fb0: 68f0917b00 PUSH 0x7b91f0
    f.push(m,0x007b91f0u);
  }
  L006e1fb5: { // 0x6e1fb5: 68d0917b00 PUSH 0x7b91d0
    f.push(m,0x007b91d0u);
  }
  L006e1fba: { // 0x6e1fba: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006e1fbb: { // 0x6e1fbb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1fbc: { // 0x6e1fbc: e863d60800 CALL 0x0076f624
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f624u,7217089u); flags=s.arithmetic_flags;
  }
  L006e1fc1: { // 0x6e1fc1: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006e1fc4: { // 0x6e1fc4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006e1fc6: { // 0x6e1fc6: 7438 JZ 0x006e2000
    if(integer::condition("JZ",flags)) goto L006e2000;
  }
  L006e1fc8: { // 0x6e1fc8: a1c887aa00 MOV EAX,[0x00aa87c8]
    s.ax = m.r32((0x00aa87c8u));
  }
  L006e1fcd: { // 0x6e1fcd: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e1fcf: { // 0x6e1fcf: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e1fd1: { // 0x6e1fd1: 7e1a JLE 0x006e1fed
    if(integer::condition("JLE",flags)) goto L006e1fed;
  }
  L006e1fd3: { // 0x6e1fd3: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L006e1fd9: { // 0x6e1fd9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1fda: { // 0x6e1fda: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1fdb: { // 0x6e1fdb: 8b0c99 MOV ECX,dword ptr [ECX + EBX*0x4]
    s.cx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L006e1fde: { // 0x6e1fde: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e1fe0: { // 0x6e1fe0: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217123u); flags=s.arithmetic_flags;
  }
  L006e1fe3: { // 0x6e1fe3: a1c887aa00 MOV EAX,[0x00aa87c8]
    s.ax = m.r32((0x00aa87c8u));
  }
  L006e1fe8: { // 0x6e1fe8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e1fe9: { // 0x6e1fe9: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e1feb: { // 0x6e1feb: 7ce6 JL 0x006e1fd3
    if(integer::condition("JL",flags)) goto L006e1fd3;
  }
  L006e1fed: { // 0x6e1fed: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006e1ff3: { // 0x6e1ff3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e1ff4: { // 0x6e1ff4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e1ff5: { // 0x6e1ff5: e83663f6ff CALL 0x00648330
    s.arithmetic_flags=flags; invoke(m,s,f,0x00648330u,7217146u); flags=s.arithmetic_flags;
  }
  L006e1ffa: { // 0x6e1ffa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e1ffb: { // 0x6e1ffb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e1ffc: { // 0x6e1ffc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e1ffd: { // 0x6e1ffd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e1ffe: { // 0x6e1ffe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e1fff: { // 0x6e1fff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e2000: { // 0x6e2000: 8d43f4 LEA EAX,[EBX + -0xc]
    s.ax = (s.bx-0x0000000cu);
  }
  L006e2003: { // 0x6e2003: 83f830 CMP EAX,0x30
    (void)integer::sub(s.ax,0x00000030u,32,flags);
  }
  L006e2006: { // 0x6e2006: 0f875f010000 JA 0x006e216b
    if(integer::condition("JA",flags)) goto L006e216b;
  }
  L006e200c: { // 0x6e200c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006e200e: { // 0x6e200e: 8a8894216e00 MOV CL,byte ptr [EAX + 0x6e2194]
    s.cx = with_al(s.cx, m.r8((s.ax+0x006e2194u)));
  }
  L006e2014: { // 0x6e2014: ff248d74216e00 JMP dword ptr [ECX*0x4 + 0x6e2174]
    switch(m.r32(((s.cx * 0x00000004u)+0x006e2174u))){
    case 0x006e1e50u: goto L006e1e50;
    case 0x006e1e51u: goto L006e1e51;
    case 0x006e1e52u: goto L006e1e52;
    case 0x006e1e53u: goto L006e1e53;
    case 0x006e1e54u: goto L006e1e54;
    case 0x006e1e56u: goto L006e1e56;
    case 0x006e1e57u: goto L006e1e57;
    case 0x006e1e59u: goto L006e1e59;
    case 0x006e1e5bu: goto L006e1e5b;
    case 0x006e1e5eu: goto L006e1e5e;
    case 0x006e1e60u: goto L006e1e60;
    case 0x006e1e65u: goto L006e1e65;
    case 0x006e1e67u: goto L006e1e67;
    case 0x006e1e69u: goto L006e1e69;
    case 0x006e1e6bu: goto L006e1e6b;
    case 0x006e1e71u: goto L006e1e71;
    case 0x006e1e73u: goto L006e1e73;
    case 0x006e1e75u: goto L006e1e75;
    case 0x006e1e7bu: goto L006e1e7b;
    case 0x006e1e7du: goto L006e1e7d;
    case 0x006e1e7eu: goto L006e1e7e;
    case 0x006e1e83u: goto L006e1e83;
    case 0x006e1e89u: goto L006e1e89;
    case 0x006e1e8eu: goto L006e1e8e;
    case 0x006e1e91u: goto L006e1e91;
    case 0x006e1e97u: goto L006e1e97;
    case 0x006e1e9du: goto L006e1e9d;
    case 0x006e1e9fu: goto L006e1e9f;
    case 0x006e1ea5u: goto L006e1ea5;
    case 0x006e1ea7u: goto L006e1ea7;
    case 0x006e1eadu: goto L006e1ead;
    case 0x006e1eb0u: goto L006e1eb0;
    case 0x006e1eb2u: goto L006e1eb2;
    case 0x006e1eb4u: goto L006e1eb4;
    case 0x006e1eb8u: goto L006e1eb8;
    case 0x006e1ebeu: goto L006e1ebe;
    case 0x006e1ec3u: goto L006e1ec3;
    case 0x006e1ec5u: goto L006e1ec5;
    case 0x006e1ec7u: goto L006e1ec7;
    case 0x006e1ecdu: goto L006e1ecd;
    case 0x006e1eceu: goto L006e1ece;
    case 0x006e1ecfu: goto L006e1ecf;
    case 0x006e1ed2u: goto L006e1ed2;
    case 0x006e1ed4u: goto L006e1ed4;
    case 0x006e1ed7u: goto L006e1ed7;
    case 0x006e1edcu: goto L006e1edc;
    case 0x006e1eddu: goto L006e1edd;
    case 0x006e1edfu: goto L006e1edf;
    case 0x006e1ee1u: goto L006e1ee1;
    case 0x006e1ee2u: goto L006e1ee2;
    case 0x006e1ee7u: goto L006e1ee7;
    case 0x006e1eecu: goto L006e1eec;
    case 0x006e1ef1u: goto L006e1ef1;
    case 0x006e1ef2u: goto L006e1ef2;
    case 0x006e1ef7u: goto L006e1ef7;
    case 0x006e1efau: goto L006e1efa;
    case 0x006e1efcu: goto L006e1efc;
    case 0x006e1effu: goto L006e1eff;
    case 0x006e1f01u: goto L006e1f01;
    case 0x006e1f04u: goto L006e1f04;
    case 0x006e1f06u: goto L006e1f06;
    case 0x006e1f07u: goto L006e1f07;
    case 0x006e1f0cu: goto L006e1f0c;
    case 0x006e1f11u: goto L006e1f11;
    case 0x006e1f13u: goto L006e1f13;
    case 0x006e1f18u: goto L006e1f18;
    case 0x006e1f1eu: goto L006e1f1e;
    case 0x006e1f20u: goto L006e1f20;
    case 0x006e1f22u: goto L006e1f22;
    case 0x006e1f24u: goto L006e1f24;
    case 0x006e1f26u: goto L006e1f26;
    case 0x006e1f27u: goto L006e1f27;
    case 0x006e1f2au: goto L006e1f2a;
    case 0x006e1f2bu: goto L006e1f2b;
    case 0x006e1f2cu: goto L006e1f2c;
    case 0x006e1f31u: goto L006e1f31;
    case 0x006e1f36u: goto L006e1f36;
    case 0x006e1f37u: goto L006e1f37;
    case 0x006e1f38u: goto L006e1f38;
    case 0x006e1f39u: goto L006e1f39;
    case 0x006e1f3au: goto L006e1f3a;
    case 0x006e1f3bu: goto L006e1f3b;
    case 0x006e1f3cu: goto L006e1f3c;
    case 0x006e1f3fu: goto L006e1f3f;
    case 0x006e1f41u: goto L006e1f41;
    case 0x006e1f46u: goto L006e1f46;
    case 0x006e1f48u: goto L006e1f48;
    case 0x006e1f4au: goto L006e1f4a;
    case 0x006e1f4cu: goto L006e1f4c;
    case 0x006e1f52u: goto L006e1f52;
    case 0x006e1f53u: goto L006e1f53;
    case 0x006e1f54u: goto L006e1f54;
    case 0x006e1f57u: goto L006e1f57;
    case 0x006e1f59u: goto L006e1f59;
    case 0x006e1f5cu: goto L006e1f5c;
    case 0x006e1f61u: goto L006e1f61;
    case 0x006e1f62u: goto L006e1f62;
    case 0x006e1f64u: goto L006e1f64;
    case 0x006e1f66u: goto L006e1f66;
    case 0x006e1f67u: goto L006e1f67;
    case 0x006e1f68u: goto L006e1f68;
    case 0x006e1f6du: goto L006e1f6d;
    case 0x006e1f72u: goto L006e1f72;
    case 0x006e1f73u: goto L006e1f73;
    case 0x006e1f74u: goto L006e1f74;
    case 0x006e1f75u: goto L006e1f75;
    case 0x006e1f76u: goto L006e1f76;
    case 0x006e1f77u: goto L006e1f77;
    case 0x006e1f78u: goto L006e1f78;
    case 0x006e1f7bu: goto L006e1f7b;
    case 0x006e1f81u: goto L006e1f81;
    case 0x006e1f86u: goto L006e1f86;
    case 0x006e1f88u: goto L006e1f88;
    case 0x006e1f8au: goto L006e1f8a;
    case 0x006e1f90u: goto L006e1f90;
    case 0x006e1f95u: goto L006e1f95;
    case 0x006e1f96u: goto L006e1f96;
    case 0x006e1f97u: goto L006e1f97;
    case 0x006e1f9au: goto L006e1f9a;
    case 0x006e1f9cu: goto L006e1f9c;
    case 0x006e1f9fu: goto L006e1f9f;
    case 0x006e1fa4u: goto L006e1fa4;
    case 0x006e1fa5u: goto L006e1fa5;
    case 0x006e1fa7u: goto L006e1fa7;
    case 0x006e1fa9u: goto L006e1fa9;
    case 0x006e1faau: goto L006e1faa;
    case 0x006e1fabu: goto L006e1fab;
    case 0x006e1facu: goto L006e1fac;
    case 0x006e1fadu: goto L006e1fad;
    case 0x006e1faeu: goto L006e1fae;
    case 0x006e1fafu: goto L006e1faf;
    case 0x006e1fb0u: goto L006e1fb0;
    case 0x006e1fb5u: goto L006e1fb5;
    case 0x006e1fbau: goto L006e1fba;
    case 0x006e1fbbu: goto L006e1fbb;
    case 0x006e1fbcu: goto L006e1fbc;
    case 0x006e1fc1u: goto L006e1fc1;
    case 0x006e1fc4u: goto L006e1fc4;
    case 0x006e1fc6u: goto L006e1fc6;
    case 0x006e1fc8u: goto L006e1fc8;
    case 0x006e1fcdu: goto L006e1fcd;
    case 0x006e1fcfu: goto L006e1fcf;
    case 0x006e1fd1u: goto L006e1fd1;
    case 0x006e1fd3u: goto L006e1fd3;
    case 0x006e1fd9u: goto L006e1fd9;
    case 0x006e1fdau: goto L006e1fda;
    case 0x006e1fdbu: goto L006e1fdb;
    case 0x006e1fdeu: goto L006e1fde;
    case 0x006e1fe0u: goto L006e1fe0;
    case 0x006e1fe3u: goto L006e1fe3;
    case 0x006e1fe8u: goto L006e1fe8;
    case 0x006e1fe9u: goto L006e1fe9;
    case 0x006e1febu: goto L006e1feb;
    case 0x006e1fedu: goto L006e1fed;
    case 0x006e1ff3u: goto L006e1ff3;
    case 0x006e1ff4u: goto L006e1ff4;
    case 0x006e1ff5u: goto L006e1ff5;
    case 0x006e1ffau: goto L006e1ffa;
    case 0x006e1ffbu: goto L006e1ffb;
    case 0x006e1ffcu: goto L006e1ffc;
    case 0x006e1ffdu: goto L006e1ffd;
    case 0x006e1ffeu: goto L006e1ffe;
    case 0x006e1fffu: goto L006e1fff;
    case 0x006e2000u: goto L006e2000;
    case 0x006e2003u: goto L006e2003;
    case 0x006e2006u: goto L006e2006;
    case 0x006e200cu: goto L006e200c;
    case 0x006e200eu: goto L006e200e;
    case 0x006e2014u: goto L006e2014;
    case 0x006e201bu: goto L006e201b;
    case 0x006e2020u: goto L006e2020;
    case 0x006e2022u: goto L006e2022;
    case 0x006e2024u: goto L006e2024;
    case 0x006e2026u: goto L006e2026;
    case 0x006e202cu: goto L006e202c;
    case 0x006e202du: goto L006e202d;
    case 0x006e202eu: goto L006e202e;
    case 0x006e2031u: goto L006e2031;
    case 0x006e2033u: goto L006e2033;
    case 0x006e2036u: goto L006e2036;
    case 0x006e203bu: goto L006e203b;
    case 0x006e203cu: goto L006e203c;
    case 0x006e203eu: goto L006e203e;
    case 0x006e2040u: goto L006e2040;
    case 0x006e2042u: goto L006e2042;
    case 0x006e2043u: goto L006e2043;
    case 0x006e2048u: goto L006e2048;
    case 0x006e204du: goto L006e204d;
    case 0x006e2052u: goto L006e2052;
    case 0x006e2053u: goto L006e2053;
    case 0x006e2054u: goto L006e2054;
    case 0x006e2059u: goto L006e2059;
    case 0x006e205au: goto L006e205a;
    case 0x006e205bu: goto L006e205b;
    case 0x006e205cu: goto L006e205c;
    case 0x006e205du: goto L006e205d;
    case 0x006e205eu: goto L006e205e;
    case 0x006e205fu: goto L006e205f;
    case 0x006e2064u: goto L006e2064;
    case 0x006e2066u: goto L006e2066;
    case 0x006e2068u: goto L006e2068;
    case 0x006e206eu: goto L006e206e;
    case 0x006e2074u: goto L006e2074;
    case 0x006e2075u: goto L006e2075;
    case 0x006e2076u: goto L006e2076;
    case 0x006e2079u: goto L006e2079;
    case 0x006e207bu: goto L006e207b;
    case 0x006e207eu: goto L006e207e;
    case 0x006e2083u: goto L006e2083;
    case 0x006e2084u: goto L006e2084;
    case 0x006e2086u: goto L006e2086;
    case 0x006e2088u: goto L006e2088;
    case 0x006e2089u: goto L006e2089;
    case 0x006e208au: goto L006e208a;
    case 0x006e208bu: goto L006e208b;
    case 0x006e208cu: goto L006e208c;
    case 0x006e208du: goto L006e208d;
    case 0x006e208eu: goto L006e208e;
    case 0x006e2093u: goto L006e2093;
    case 0x006e2095u: goto L006e2095;
    case 0x006e2097u: goto L006e2097;
    case 0x006e2099u: goto L006e2099;
    case 0x006e209eu: goto L006e209e;
    case 0x006e209fu: goto L006e209f;
    case 0x006e20a0u: goto L006e20a0;
    case 0x006e20a3u: goto L006e20a3;
    case 0x006e20a5u: goto L006e20a5;
    case 0x006e20a8u: goto L006e20a8;
    case 0x006e20adu: goto L006e20ad;
    case 0x006e20aeu: goto L006e20ae;
    case 0x006e20b0u: goto L006e20b0;
    case 0x006e20b2u: goto L006e20b2;
    case 0x006e20b4u: goto L006e20b4;
    case 0x006e20b5u: goto L006e20b5;
    case 0x006e20bau: goto L006e20ba;
    case 0x006e20bfu: goto L006e20bf;
    case 0x006e20c0u: goto L006e20c0;
    case 0x006e20c1u: goto L006e20c1;
    case 0x006e20c2u: goto L006e20c2;
    case 0x006e20c3u: goto L006e20c3;
    case 0x006e20c4u: goto L006e20c4;
    case 0x006e20c5u: goto L006e20c5;
    case 0x006e20cau: goto L006e20ca;
    case 0x006e20ccu: goto L006e20cc;
    case 0x006e20ceu: goto L006e20ce;
    case 0x006e20d4u: goto L006e20d4;
    case 0x006e20d9u: goto L006e20d9;
    case 0x006e20dau: goto L006e20da;
    case 0x006e20dbu: goto L006e20db;
    case 0x006e20deu: goto L006e20de;
    case 0x006e20e0u: goto L006e20e0;
    case 0x006e20e3u: goto L006e20e3;
    case 0x006e20e8u: goto L006e20e8;
    case 0x006e20e9u: goto L006e20e9;
    case 0x006e20ebu: goto L006e20eb;
    case 0x006e20edu: goto L006e20ed;
    case 0x006e20eeu: goto L006e20ee;
    case 0x006e20efu: goto L006e20ef;
    case 0x006e20f0u: goto L006e20f0;
    case 0x006e20f1u: goto L006e20f1;
    case 0x006e20f2u: goto L006e20f2;
    case 0x006e20f3u: goto L006e20f3;
    case 0x006e20f8u: goto L006e20f8;
    case 0x006e20fau: goto L006e20fa;
    case 0x006e20fcu: goto L006e20fc;
    case 0x006e20feu: goto L006e20fe;
    case 0x006e2103u: goto L006e2103;
    case 0x006e2104u: goto L006e2104;
    case 0x006e2105u: goto L006e2105;
    case 0x006e2108u: goto L006e2108;
    case 0x006e210au: goto L006e210a;
    case 0x006e210du: goto L006e210d;
    case 0x006e2112u: goto L006e2112;
    case 0x006e2113u: goto L006e2113;
    case 0x006e2115u: goto L006e2115;
    case 0x006e2117u: goto L006e2117;
    case 0x006e2118u: goto L006e2118;
    case 0x006e2119u: goto L006e2119;
    case 0x006e211au: goto L006e211a;
    case 0x006e211bu: goto L006e211b;
    case 0x006e211cu: goto L006e211c;
    case 0x006e211du: goto L006e211d;
    case 0x006e2122u: goto L006e2122;
    case 0x006e2124u: goto L006e2124;
    case 0x006e2126u: goto L006e2126;
    case 0x006e2128u: goto L006e2128;
    case 0x006e212du: goto L006e212d;
    case 0x006e212eu: goto L006e212e;
    case 0x006e212fu: goto L006e212f;
    case 0x006e2132u: goto L006e2132;
    case 0x006e2134u: goto L006e2134;
    case 0x006e2137u: goto L006e2137;
    case 0x006e213cu: goto L006e213c;
    case 0x006e213du: goto L006e213d;
    case 0x006e213fu: goto L006e213f;
    case 0x006e2141u: goto L006e2141;
    case 0x006e2142u: goto L006e2142;
    case 0x006e2143u: goto L006e2143;
    case 0x006e2144u: goto L006e2144;
    case 0x006e2145u: goto L006e2145;
    case 0x006e2146u: goto L006e2146;
    case 0x006e2147u: goto L006e2147;
    case 0x006e214cu: goto L006e214c;
    case 0x006e214eu: goto L006e214e;
    case 0x006e2150u: goto L006e2150;
    case 0x006e2152u: goto L006e2152;
    case 0x006e2157u: goto L006e2157;
    case 0x006e2158u: goto L006e2158;
    case 0x006e2159u: goto L006e2159;
    case 0x006e215cu: goto L006e215c;
    case 0x006e215eu: goto L006e215e;
    case 0x006e2161u: goto L006e2161;
    case 0x006e2166u: goto L006e2166;
    case 0x006e2167u: goto L006e2167;
    case 0x006e2169u: goto L006e2169;
    case 0x006e216bu: goto L006e216b;
    case 0x006e216cu: goto L006e216c;
    case 0x006e216du: goto L006e216d;
    case 0x006e216eu: goto L006e216e;
    case 0x006e216fu: goto L006e216f;
    case 0x006e2170u: goto L006e2170;
    default:throw std::domain_error("recovery666 unsupported switch destination");}
  }
  L006e201b: { // 0x6e201b: a17087aa00 MOV EAX,[0x00aa8770]
    s.ax = m.r32((0x00aa8770u));
  }
  L006e2020: { // 0x6e2020: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e2022: { // 0x6e2022: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e2024: { // 0x6e2024: 7e1a JLE 0x006e2040
    if(integer::condition("JLE",flags)) goto L006e2040;
  }
  L006e2026: { // 0x6e2026: 8b156487aa00 MOV EDX,dword ptr [0x00aa8764]
    s.dx = m.r32((0x00aa8764u));
  }
  L006e202c: { // 0x6e202c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e202d: { // 0x6e202d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e202e: { // 0x6e202e: 8b0c9a MOV ECX,dword ptr [EDX + EBX*0x4]
    s.cx = m.r32((s.dx+(s.bx * 0x00000004u)));
  }
  L006e2031: { // 0x6e2031: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006e2033: { // 0x6e2033: ff5028 CALL dword ptr [EAX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000028u)),7217206u); flags=s.arithmetic_flags;
  }
  L006e2036: { // 0x6e2036: a17087aa00 MOV EAX,[0x00aa8770]
    s.ax = m.r32((0x00aa8770u));
  }
  L006e203b: { // 0x6e203b: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e203c: { // 0x6e203c: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e203e: { // 0x6e203e: 7ce6 JL 0x006e2026
    if(integer::condition("JL",flags)) goto L006e2026;
  }
  L006e2040: { // 0x6e2040: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006e2042: { // 0x6e2042: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e2043: { // 0x6e2043: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006e2048: { // 0x6e2048: e8234be7ff CALL 0x00556b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00556b70u,7217229u); flags=s.arithmetic_flags;
  }
  L006e204d: { // 0x6e204d: b9b0a78100 MOV ECX,0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  L006e2052: { // 0x6e2052: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e2053: { // 0x6e2053: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e2054: { // 0x6e2054: e897a2e5ff CALL 0x0053c2f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053c2f0u,7217241u); flags=s.arithmetic_flags;
  }
  L006e2059: { // 0x6e2059: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e205a: { // 0x6e205a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e205b: { // 0x6e205b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e205c: { // 0x6e205c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e205d: { // 0x6e205d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e205e: { // 0x6e205e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e205f: { // 0x6e205f: a16088aa00 MOV EAX,[0x00aa8860]
    s.ax = m.r32((0x00aa8860u));
  }
  L006e2064: { // 0x6e2064: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e2066: { // 0x6e2066: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e2068: { // 0x6e2068: 0f8efd000000 JLE 0x006e216b
    if(integer::condition("JLE",flags)) goto L006e216b;
  }
  L006e206e: { // 0x6e206e: 8b0d5488aa00 MOV ECX,dword ptr [0x00aa8854]
    s.cx = m.r32((0x00aa8854u));
  }
  L006e2074: { // 0x6e2074: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e2075: { // 0x6e2075: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e2076: { // 0x6e2076: 8b0c99 MOV ECX,dword ptr [ECX + EBX*0x4]
    s.cx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L006e2079: { // 0x6e2079: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e207b: { // 0x6e207b: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217278u); flags=s.arithmetic_flags;
  }
  L006e207e: { // 0x6e207e: a16088aa00 MOV EAX,[0x00aa8860]
    s.ax = m.r32((0x00aa8860u));
  }
  L006e2083: { // 0x6e2083: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e2084: { // 0x6e2084: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e2086: { // 0x6e2086: 7ce6 JL 0x006e206e
    if(integer::condition("JL",flags)) goto L006e206e;
  }
  L006e2088: { // 0x6e2088: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e2089: { // 0x6e2089: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e208a: { // 0x6e208a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e208b: { // 0x6e208b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e208c: { // 0x6e208c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e208d: { // 0x6e208d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e208e: { // 0x6e208e: a19887aa00 MOV EAX,[0x00aa8798]
    s.ax = m.r32((0x00aa8798u));
  }
  L006e2093: { // 0x6e2093: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e2095: { // 0x6e2095: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e2097: { // 0x6e2097: 7e19 JLE 0x006e20b2
    if(integer::condition("JLE",flags)) goto L006e20b2;
  }
  L006e2099: { // 0x6e2099: a18c87aa00 MOV EAX,[0x00aa878c]
    s.ax = m.r32((0x00aa878cu));
  }
  L006e209e: { // 0x6e209e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e209f: { // 0x6e209f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e20a0: { // 0x6e20a0: 8b0c98 MOV ECX,dword ptr [EAX + EBX*0x4]
    s.cx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006e20a3: { // 0x6e20a3: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e20a5: { // 0x6e20a5: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217320u); flags=s.arithmetic_flags;
  }
  L006e20a8: { // 0x6e20a8: a19887aa00 MOV EAX,[0x00aa8798]
    s.ax = m.r32((0x00aa8798u));
  }
  L006e20ad: { // 0x6e20ad: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e20ae: { // 0x6e20ae: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e20b0: { // 0x6e20b0: 7ce7 JL 0x006e2099
    if(integer::condition("JL",flags)) goto L006e2099;
  }
  L006e20b2: { // 0x6e20b2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006e20b4: { // 0x6e20b4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e20b5: { // 0x6e20b5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006e20ba: { // 0x6e20ba: e8b14ae7ff CALL 0x00556b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00556b70u,7217343u); flags=s.arithmetic_flags;
  }
  L006e20bf: { // 0x6e20bf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e20c0: { // 0x6e20c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e20c1: { // 0x6e20c1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e20c2: { // 0x6e20c2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e20c3: { // 0x6e20c3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e20c4: { // 0x6e20c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e20c5: { // 0x6e20c5: a1b087aa00 MOV EAX,[0x00aa87b0]
    s.ax = m.r32((0x00aa87b0u));
  }
  L006e20ca: { // 0x6e20ca: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e20cc: { // 0x6e20cc: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e20ce: { // 0x6e20ce: 0f8e97000000 JLE 0x006e216b
    if(integer::condition("JLE",flags)) goto L006e216b;
  }
  L006e20d4: { // 0x6e20d4: a1a487aa00 MOV EAX,[0x00aa87a4]
    s.ax = m.r32((0x00aa87a4u));
  }
  L006e20d9: { // 0x6e20d9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e20da: { // 0x6e20da: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e20db: { // 0x6e20db: 8b0c98 MOV ECX,dword ptr [EAX + EBX*0x4]
    s.cx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006e20de: { // 0x6e20de: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e20e0: { // 0x6e20e0: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217379u); flags=s.arithmetic_flags;
  }
  L006e20e3: { // 0x6e20e3: a1b087aa00 MOV EAX,[0x00aa87b0]
    s.ax = m.r32((0x00aa87b0u));
  }
  L006e20e8: { // 0x6e20e8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e20e9: { // 0x6e20e9: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e20eb: { // 0x6e20eb: 7ce7 JL 0x006e20d4
    if(integer::condition("JL",flags)) goto L006e20d4;
  }
  L006e20ed: { // 0x6e20ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e20ee: { // 0x6e20ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e20ef: { // 0x6e20ef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e20f0: { // 0x6e20f0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e20f1: { // 0x6e20f1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e20f2: { // 0x6e20f2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e20f3: { // 0x6e20f3: a14887aa00 MOV EAX,[0x00aa8748]
    s.ax = m.r32((0x00aa8748u));
  }
  L006e20f8: { // 0x6e20f8: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e20fa: { // 0x6e20fa: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e20fc: { // 0x6e20fc: 7e6d JLE 0x006e216b
    if(integer::condition("JLE",flags)) goto L006e216b;
  }
  L006e20fe: { // 0x6e20fe: a13c87aa00 MOV EAX,[0x00aa873c]
    s.ax = m.r32((0x00aa873cu));
  }
  L006e2103: { // 0x6e2103: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e2104: { // 0x6e2104: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e2105: { // 0x6e2105: 8b0c98 MOV ECX,dword ptr [EAX + EBX*0x4]
    s.cx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006e2108: { // 0x6e2108: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e210a: { // 0x6e210a: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217421u); flags=s.arithmetic_flags;
  }
  L006e210d: { // 0x6e210d: a14887aa00 MOV EAX,[0x00aa8748]
    s.ax = m.r32((0x00aa8748u));
  }
  L006e2112: { // 0x6e2112: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e2113: { // 0x6e2113: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e2115: { // 0x6e2115: 7ce7 JL 0x006e20fe
    if(integer::condition("JL",flags)) goto L006e20fe;
  }
  L006e2117: { // 0x6e2117: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e2118: { // 0x6e2118: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e2119: { // 0x6e2119: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e211a: { // 0x6e211a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e211b: { // 0x6e211b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e211c: { // 0x6e211c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e211d: { // 0x6e211d: a13087aa00 MOV EAX,[0x00aa8730]
    s.ax = m.r32((0x00aa8730u));
  }
  L006e2122: { // 0x6e2122: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e2124: { // 0x6e2124: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e2126: { // 0x6e2126: 7e43 JLE 0x006e216b
    if(integer::condition("JLE",flags)) goto L006e216b;
  }
  L006e2128: { // 0x6e2128: a12487aa00 MOV EAX,[0x00aa8724]
    s.ax = m.r32((0x00aa8724u));
  }
  L006e212d: { // 0x6e212d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e212e: { // 0x6e212e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e212f: { // 0x6e212f: 8b0c98 MOV ECX,dword ptr [EAX + EBX*0x4]
    s.cx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006e2132: { // 0x6e2132: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e2134: { // 0x6e2134: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217463u); flags=s.arithmetic_flags;
  }
  L006e2137: { // 0x6e2137: a13087aa00 MOV EAX,[0x00aa8730]
    s.ax = m.r32((0x00aa8730u));
  }
  L006e213c: { // 0x6e213c: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e213d: { // 0x6e213d: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e213f: { // 0x6e213f: 7ce7 JL 0x006e2128
    if(integer::condition("JL",flags)) goto L006e2128;
  }
  L006e2141: { // 0x6e2141: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e2142: { // 0x6e2142: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e2143: { // 0x6e2143: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e2144: { // 0x6e2144: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e2145: { // 0x6e2145: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e2146: { // 0x6e2146: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006e2147: { // 0x6e2147: a14888aa00 MOV EAX,[0x00aa8848]
    s.ax = m.r32((0x00aa8848u));
  }
  L006e214c: { // 0x6e214c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e214e: { // 0x6e214e: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L006e2150: { // 0x6e2150: 7e19 JLE 0x006e216b
    if(integer::condition("JLE",flags)) goto L006e216b;
  }
  L006e2152: { // 0x6e2152: a13c88aa00 MOV EAX,[0x00aa883c]
    s.ax = m.r32((0x00aa883cu));
  }
  L006e2157: { // 0x6e2157: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e2158: { // 0x6e2158: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e2159: { // 0x6e2159: 8b0c98 MOV ECX,dword ptr [EAX + EBX*0x4]
    s.cx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006e215c: { // 0x6e215c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006e215e: { // 0x6e215e: ff5228 CALL dword ptr [EDX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000028u)),7217505u); flags=s.arithmetic_flags;
  }
  L006e2161: { // 0x6e2161: a14888aa00 MOV EAX,[0x00aa8848]
    s.ax = m.r32((0x00aa8848u));
  }
  L006e2166: { // 0x6e2166: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e2167: { // 0x6e2167: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006e2169: { // 0x6e2169: 7ce7 JL 0x006e2152
    if(integer::condition("JL",flags)) goto L006e2152;
  }
  L006e216b: { // 0x6e216b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e216c: { // 0x6e216c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e216d: { // 0x6e216d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e216e: { // 0x6e216e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e216f: { // 0x6e216f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e2170: { // 0x6e2170: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
