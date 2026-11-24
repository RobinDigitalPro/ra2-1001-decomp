#include "recovered/transfers_b38_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::transfers_b38 {
namespace {
void f_00001000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x401000: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x401001: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x401002: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x401003: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x401005: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x40100a: e821600000 CALL 0x00407030
    const std::uint32_t call_target=0x00407030u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40100f: 8d7e28 LEA EDI,[ESI + 0x28]
    s.di = (s.si+0x00000028u);
  }
  { // 0x401012: ba64000000 MOV EDX,0x64
    s.dx = 0x00000064u;
  }
  { // 0x401017: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x401019: e812600000 CALL 0x00407030
    const std::uint32_t call_target=0x00407030u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40101e: 8d5e50 LEA EBX,[ESI + 0x50]
    s.bx = (s.si+0x00000050u);
  }
  { // 0x401021: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x401026: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x401028: e803600000 CALL 0x00407030
    const std::uint32_t call_target=0x00407030u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x40102d: ba0a000000 MOV EDX,0xa
    s.dx = 0x0000000au;
  }
  { // 0x401032: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x401034: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x401036: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x40103b: e890600000 CALL 0x004070d0
    const std::uint32_t call_target=0x004070d0u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x401040: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x401045: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x401047: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x401049: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x40104e: e87d600000 CALL 0x004070d0
    const std::uint32_t call_target=0x004070d0u;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x401053: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x401058: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x40105a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x40105c: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x401061: e86a600000 CALL 0x004070d0
    const std::uint32_t call_target=0x004070d0u;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x401066: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x401068: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x40106d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40106e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40106f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x401070: e90b600000 JMP 0x00407080
    const std::uint32_t target=0x00407080u;
    transfer(m,s,f,op,6u,target); return;
  }
}
void f_00001080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x401080: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x401081: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x401083: e868600000 CALL 0x004070f0
    const std::uint32_t call_target=0x004070f0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x401088: 8d4e28 LEA ECX,[ESI + 0x28]
    s.cx = (s.si+0x00000028u);
  }
  { // 0x40108b: e860600000 CALL 0x004070f0
    const std::uint32_t call_target=0x004070f0u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x401090: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x401093: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x401094: e957600000 JMP 0x004070f0
    const std::uint32_t target=0x004070f0u;
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_00001fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x401fc0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x401fc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x401fc2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x401fc3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x401fc5: 397f04 CMP dword ptr [EDI + 0x4],EDI
    (void)integer::sub(m.r32((s.di+0x00000004u)),s.di,32,flags);
  }
  { // 0x401fc8: 7405 JZ 0x00401fcf
    if(integer::condition("JZ",flags)) goto L00401fcf;
  }
  L00401fca: { // 0x401fca: e8b1530000 CALL 0x00407380
    const std::uint32_t call_target=0x00407380u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00401fcf: { // 0x401fcf: 8d5f24 LEA EBX,[EDI + 0x24]
    s.bx = (s.di+0x00000024u);
  }
  { // 0x401fd2: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x401fd4: e8c7530000 CALL 0x004073a0
    const std::uint32_t call_target=0x004073a0u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x401fd9: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x401fdb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x401fdd: 7428 JZ 0x00402007
    if(integer::condition("JZ",flags)) goto L00402007;
  }
  L00401fdf: { // 0x401fdf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x401fe1: e89a530000 CALL 0x00407380
    const std::uint32_t call_target=0x00407380u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x401fe6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x401fe8: e833650000 CALL 0x00408520
    const std::uint32_t call_target=0x00408520u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x401fed: 8b473c MOV EAX,dword ptr [EDI + 0x3c]
    s.ax = m.r32((s.di+0x0000003cu));
  }
  { // 0x401ff0: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x401ff2: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x401ff5: e866540000 CALL 0x00407460
    const std::uint32_t call_target=0x00407460u;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x401ffa: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x401ffc: e89f530000 CALL 0x004073a0
    const std::uint32_t call_target=0x004073a0u;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x402001: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x402003: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x402005: 75d8 JNZ 0x00401fdf
    if(integer::condition("JNZ",flags)) goto L00401fdf;
  }
  L00402007: { // 0x402007: 8d4f1c LEA ECX,[EDI + 0x1c]
    s.cx = (s.di+0x0000001cu);
  }
  { // 0x40200a: e841640000 CALL 0x00408450
    const std::uint32_t call_target=0x00408450u;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x40200f: 8b4f3c MOV ECX,dword ptr [EDI + 0x3c]
    s.cx = m.r32((s.di+0x0000003cu));
  }
  { // 0x402012: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x402014: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x402015: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402016: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  { // 0x402019: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x40201a: e941540000 JMP 0x00407460
    const std::uint32_t target=0x00407460u;
    transfer(m,s,f,op,7u,target); return;
  }
}
void f_000023f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4023f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4023f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4023f3: c7866801000000000000 MOV dword ptr [ESI + 0x168],0x0
    m.w32((s.si+0x00000168u), 0x00000000u);
  }
  { // 0x4023fd: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x402403: 24fa AND AL,0xfa
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fau),8,flags));
  }
  { // 0x402405: 8986a4000000 MOV dword ptr [ESI + 0xa4],EAX
    m.w32((s.si+0x000000a4u), s.ax);
  }
  { // 0x40240b: c786a800000000000000 MOV dword ptr [ESI + 0xa8],0x0
    m.w32((s.si+0x000000a8u), 0x00000000u);
  }
  { // 0x402415: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x402418: e8e3ebffff CALL 0x00401000
    const std::uint32_t call_target=0x00401000u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40241d: 8b86b8000000 MOV EAX,dword ptr [ESI + 0xb8]
    s.ax = m.r32((s.si+0x000000b8u));
  }
  { // 0x402423: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x402425: 7405 JZ 0x0040242c
    if(integer::condition("JZ",flags)) goto L0040242c;
  }
  L00402427: { // 0x402427: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402429: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40242a: ffe0 JMP EAX
    const std::uint32_t target=s.ax;
    transfer(m,s,f,op,1u,target); return;
  }
  L0040242c: { // 0x40242c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40242e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40242f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402600: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402601: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402603: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x402609: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40260c: f686a400000001 TEST byte ptr [ESI + 0xa4],0x1
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000001u),8,flags);
  }
  { // 0x402613: 7428 JZ 0x0040263d
    if(integer::condition("JZ",flags)) goto L0040263d;
  }
  L00402615: { // 0x402615: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  { // 0x40261b: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  { // 0x40261e: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  { // 0x402624: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x40262a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40262c: ff5214 CALL dword ptr [EDX + 0x14]
    const std::uint32_t call_target=m.r32((s.dx+0x00000014u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40262f: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x402635: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  { // 0x402637: 8986a4000000 MOV dword ptr [ESI + 0xa4],EAX
    m.w32((s.si+0x000000a4u), s.ax);
  }
  L0040263d: { // 0x40263d: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x402643: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402645: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402646: ff622c JMP dword ptr [EDX + 0x2c]
    const std::uint32_t target=m.r32((s.dx+0x0000002cu));
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_00002650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402650: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402651: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402653: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x402659: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40265c: f686a400000004 TEST byte ptr [ESI + 0xa4],0x4
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000004u),8,flags);
  }
  { // 0x402663: 7428 JZ 0x0040268d
    if(integer::condition("JZ",flags)) goto L0040268d;
  }
  L00402665: { // 0x402665: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x40266b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40266d: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x402670: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x402676: 24fb AND AL,0xfb
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fbu),8,flags));
  }
  { // 0x402678: 8986a4000000 MOV dword ptr [ESI + 0xa4],EAX
    m.w32((s.si+0x000000a4u), s.ax);
  }
  { // 0x40267e: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  { // 0x402684: 83c901 OR ECX,0x1
    s.cx = integer::logical((s.cx)|(0x00000001u),32,flags);
  }
  { // 0x402687: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  L0040268d: { // 0x40268d: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x402693: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402695: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402696: ff622c JMP dword ptr [EDX + 0x2c]
    const std::uint32_t target=m.r32((s.dx+0x0000002cu));
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_000026c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4026c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4026c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4026c3: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x4026c9: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4026cc: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  { // 0x4026d2: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  { // 0x4026d5: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  { // 0x4026db: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x4026e1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4026e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4026e4: ff622c JMP dword ptr [EDX + 0x2c]
    const std::uint32_t target=m.r32((s.dx+0x0000002cu));
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_000026f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4026f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4026f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4026f3: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x4026f9: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4026fc: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  { // 0x402702: 83e1ef AND ECX,0xffffffef
    s.cx = integer::logical((s.cx)&(0xffffffefu),32,flags);
  }
  { // 0x402705: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  { // 0x40270b: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x402711: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402713: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402714: ff622c JMP dword ptr [EDX + 0x2c]
    const std::uint32_t target=m.r32((s.dx+0x0000002cu));
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_00005590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x405590: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x405591: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x405593: f6461820 TEST byte ptr [ESI + 0x18],0x20
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000020u),8,flags);
  }
  { // 0x405597: 7534 JNZ 0x004055cd
    if(integer::condition("JNZ",flags)) goto L004055cd;
  }
  L00405599: { // 0x405599: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  { // 0x40559f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4055a1: 7421 JZ 0x004055c4
    if(integer::condition("JZ",flags)) goto L004055c4;
  }
  L004055a3: { // 0x4055a3: 3bb1c0000000 CMP ESI,dword ptr [ECX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.cx+0x000000c0u)),32,flags);
  }
  { // 0x4055a9: 7519 JNZ 0x004055c4
    if(integer::condition("JNZ",flags)) goto L004055c4;
  }
  L004055ab: { // 0x4055ab: e8f0d0ffff CALL 0x004026a0
    const std::uint32_t call_target=0x004026a0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4055b0: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x4055b3: 0c60 OR AL,0x60
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000060u),8,flags));
  }
  { // 0x4055b5: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x4055b8: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  { // 0x4055be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4055bf: e9ecd0ffff JMP 0x004026b0
    const std::uint32_t target=0x004026b0u;
    transfer(m,s,f,op,1u,target); return;
  }
  L004055c4: { // 0x4055c4: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x4055c7: 83c960 OR ECX,0x60
    s.cx = integer::logical((s.cx)|(0x00000060u),32,flags);
  }
  { // 0x4055ca: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  L004055cd: { // 0x4055cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4055ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000061e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4061e0: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  { // 0x4061e3: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x4061e6: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x4061e8: 752f JNZ 0x00406219
    if(integer::condition("JNZ",flags)) goto L00406219;
  }
  L004061ea: { // 0x4061ea: 81fa00400000 CMP EDX,0x4000
    (void)integer::sub(s.dx,0x00004000u,32,flags);
  }
  { // 0x4061f0: 7607 JBE 0x004061f9
    if(integer::condition("JBE",flags)) goto L004061f9;
  }
  L004061f2: { // 0x4061f2: b800400000 MOV EAX,0x4000
    s.ax = 0x00004000u;
  }
  { // 0x4061f7: eb06 JMP 0x004061ff
    goto L004061ff;
  }
  L004061f9: { // 0x4061f9: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x4061fb: 7d02 JGE 0x004061ff
    if(integer::condition("JGE",flags)) goto L004061ff;
  }
  L004061fd: { // 0x4061fd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004061ff: { // 0x4061ff: 8b5124 MOV EDX,dword ptr [ECX + 0x24]
    s.dx = m.r32((s.cx+0x00000024u));
  }
  { // 0x406202: 8b521c MOV EDX,dword ptr [EDX + 0x1c]
    s.dx = m.r32((s.dx+0x0000001cu));
  }
  { // 0x406205: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  { // 0x406208: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
  { // 0x40620b: c1ea0e SHR EDX,0xe
    s.dx = integer::shift(s.dx,0x0000000eu,32,flags,integer::Shift::right);
  }
  { // 0x40620e: 81c1b8000000 ADD ECX,0xb8
    s.cx = integer::add(s.cx,0x000000b8u,32,flags);
  }
  { // 0x406214: e9870e0000 JMP 0x004070a0
    const std::uint32_t target=0x004070a0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00406219: { // 0x406219: 81fa00400000 CMP EDX,0x4000
    (void)integer::sub(s.dx,0x00004000u,32,flags);
  }
  { // 0x40621f: 7607 JBE 0x00406228
    if(integer::condition("JBE",flags)) goto L00406228;
  }
  L00406221: { // 0x406221: b800400000 MOV EAX,0x4000
    s.ax = 0x00004000u;
  }
  { // 0x406226: eb06 JMP 0x0040622e
    goto L0040622e;
  }
  L00406228: { // 0x406228: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x40622a: 7d02 JGE 0x0040622e
    if(integer::condition("JGE",flags)) goto L0040622e;
  }
  L0040622c: { // 0x40622c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040622e: { // 0x40622e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x40622f: 8db1b8000000 LEA ESI,[ECX + 0xb8]
    s.si = (s.cx+0x000000b8u);
  }
  { // 0x406235: 8b4924 MOV ECX,dword ptr [ECX + 0x24]
    s.cx = m.r32((s.cx+0x00000024u));
  }
  { // 0x406238: 8b511c MOV EDX,dword ptr [ECX + 0x1c]
    s.dx = m.r32((s.cx+0x0000001cu));
  }
  { // 0x40623b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40623d: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  { // 0x406240: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
  { // 0x406243: c1ea0e SHR EDX,0xe
    s.dx = integer::shift(s.dx,0x0000000eu,32,flags,integer::Shift::right);
  }
  { // 0x406246: e8350e0000 CALL 0x00407080
    const std::uint32_t call_target=0x00407080u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40624b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40624d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40624e: e99d0e0000 JMP 0x004070f0
    const std::uint32_t target=0x004070f0u;
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_00006280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406280: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  { // 0x406283: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x406286: 7520 JNZ 0x004062a8
    if(integer::condition("JNZ",flags)) goto L004062a8;
  }
  L00406288: { // 0x406288: 81fa00400000 CMP EDX,0x4000
    (void)integer::sub(s.dx,0x00004000u,32,flags);
  }
  { // 0x40628e: 7607 JBE 0x00406297
    if(integer::condition("JBE",flags)) goto L00406297;
  }
  L00406290: { // 0x406290: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x406295: eb06 JMP 0x0040629d
    goto L0040629d;
  }
  L00406297: { // 0x406297: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x406299: 7d02 JGE 0x0040629d
    if(integer::condition("JGE",flags)) goto L0040629d;
  }
  L0040629b: { // 0x40629b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0040629d: { // 0x40629d: 81c108010000 ADD ECX,0x108
    s.cx = integer::add(s.cx,0x00000108u,32,flags);
  }
  { // 0x4062a3: e9f80d0000 JMP 0x004070a0
    const std::uint32_t target=0x004070a0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L004062a8: { // 0x4062a8: 81fa00400000 CMP EDX,0x4000
    (void)integer::sub(s.dx,0x00004000u,32,flags);
  }
  { // 0x4062ae: 7607 JBE 0x004062b7
    if(integer::condition("JBE",flags)) goto L004062b7;
  }
  L004062b0: { // 0x4062b0: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x4062b5: eb06 JMP 0x004062bd
    goto L004062bd;
  }
  L004062b7: { // 0x4062b7: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x4062b9: 7d02 JGE 0x004062bd
    if(integer::condition("JGE",flags)) goto L004062bd;
  }
  L004062bb: { // 0x4062bb: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004062bd: { // 0x4062bd: 81c108010000 ADD ECX,0x108
    s.cx = integer::add(s.cx,0x00000108u,32,flags);
  }
  { // 0x4062c3: e9b80d0000 JMP 0x00407080
    const std::uint32_t target=0x00407080u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_00006560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406560: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x406561: 8d7118 LEA ESI,[ECX + 0x18]
    s.si = (s.cx+0x00000018u);
  }
  { // 0x406564: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x406566: e8150b0000 CALL 0x00407080
    const std::uint32_t call_target=0x00407080u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40656b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40656d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40656e: e97d0b0000 JMP 0x004070f0
    const std::uint32_t target=0x004070f0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_00006dc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406dc0: 8b0d78978100 MOV ECX,dword ptr [0x00819778]
    s.cx = m.r32((0x00819778u));
  }
  { // 0x406dc6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x406dc8: 740a JZ 0x00406dd4
    if(integer::condition("JZ",flags)) goto L00406dd4;
  }
  L00406dca: { // 0x406dca: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x406dcf: e85cc9ffff CALL 0x00403730
    const std::uint32_t call_target=0x00403730u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00406dd4: { // 0x406dd4: e977e0ffff JMP 0x00404e50
    const std::uint32_t target=0x00404e50u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_00006de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406de0: 8b0d78978100 MOV ECX,dword ptr [0x00819778]
    s.cx = m.r32((0x00819778u));
  }
  { // 0x406de6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x406de8: 740a JZ 0x00406df4
    if(integer::condition("JZ",flags)) goto L00406df4;
  }
  L00406dea: { // 0x406dea: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x406def: e87cc9ffff CALL 0x00403770
    const std::uint32_t call_target=0x00403770u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00406df4: { // 0x406df4: e8b7e1ffff CALL 0x00404fb0
    const std::uint32_t call_target=0x00404fb0u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x406df9: e972223000 JMP 0x00709070
    const std::uint32_t target=0x00709070u;
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_00006e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406e00: e8ab223000 CALL 0x007090b0
    const std::uint32_t call_target=0x007090b0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x406e05: e816e2ffff CALL 0x00405020
    const std::uint32_t call_target=0x00405020u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x406e0a: 8b0d78978100 MOV ECX,dword ptr [0x00819778]
    s.cx = m.r32((0x00819778u));
  }
  { // 0x406e10: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x406e12: 740a JZ 0x00406e1e
    if(integer::condition("JZ",flags)) goto L00406e1e;
  }
  L00406e14: { // 0x406e14: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x406e19: e9a2c9ffff JMP 0x004037c0
    const std::uint32_t target=0x004037c0u;
    transfer(m,s,f,op,2u,target); return;
  }
  L00406e1e: { // 0x406e1e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00006e20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406e20: 8b0d78978100 MOV ECX,dword ptr [0x00819778]
    s.cx = m.r32((0x00819778u));
  }
  { // 0x406e26: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x406e28: 740a JZ 0x00406e34
    if(integer::condition("JZ",flags)) goto L00406e34;
  }
  L00406e2a: { // 0x406e2a: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x406e2f: e8fcc8ffff CALL 0x00403730
    const std::uint32_t call_target=0x00403730u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00406e34: { // 0x406e34: e817e0ffff CALL 0x00404e50
    const std::uint32_t call_target=0x00404e50u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x406e39: e982120000 JMP 0x004080c0
    const std::uint32_t target=0x004080c0u;
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_00006e40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406e40: 8b0d78978100 MOV ECX,dword ptr [0x00819778]
    s.cx = m.r32((0x00819778u));
  }
  { // 0x406e46: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x406e48: 740a JZ 0x00406e54
    if(integer::condition("JZ",flags)) goto L00406e54;
  }
  L00406e4a: { // 0x406e4a: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x406e4f: e81cc9ffff CALL 0x00403770
    const std::uint32_t call_target=0x00403770u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00406e54: { // 0x406e54: e857e1ffff CALL 0x00404fb0
    const std::uint32_t call_target=0x00404fb0u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x406e59: e812223000 CALL 0x00709070
    const std::uint32_t call_target=0x00709070u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x406e5e: e8dd463000 CALL 0x0070b540
    const std::uint32_t call_target=0x0070b540u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x406e63: e928463000 JMP 0x0070b490
    const std::uint32_t target=0x0070b490u;
    transfer(m,s,f,op,4u,target); return;
  }
}
void f_00006e70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406e70: e82b463000 CALL 0x0070b4a0
    const std::uint32_t call_target=0x0070b4a0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x406e75: e836473000 CALL 0x0070b5b0
    const std::uint32_t call_target=0x0070b5b0u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x406e7a: e831223000 CALL 0x007090b0
    const std::uint32_t call_target=0x007090b0u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x406e7f: e89ce1ffff CALL 0x00405020
    const std::uint32_t call_target=0x00405020u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x406e84: 8b0d78978100 MOV ECX,dword ptr [0x00819778]
    s.cx = m.r32((0x00819778u));
  }
  { // 0x406e8a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x406e8c: 740a JZ 0x00406e98
    if(integer::condition("JZ",flags)) goto L00406e98;
  }
  L00406e8e: { // 0x406e8e: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x406e93: e928c9ffff JMP 0x004037c0
    const std::uint32_t target=0x004037c0u;
    transfer(m,s,f,op,4u,target); return;
  }
  L00406e98: { // 0x406e98: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00006f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406f70: a180978100 MOV EAX,[0x00819780]
    s.ax = m.r32((0x00819780u));
  }
  { // 0x406f75: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x406f77: 740d JZ 0x00406f86
    if(integer::condition("JZ",flags)) goto L00406f86;
  }
  L00406f79: { // 0x406f79: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x406f7a: a380978100 MOV [0x00819780],EAX
    m.w32((0x00819780u), s.ax);
  }
  { // 0x406f7f: 7505 JNZ 0x00406f86
    if(integer::condition("JNZ",flags)) goto L00406f86;
  }
  L00406f81: { // 0x406f81: e9ea380000 JMP 0x0040a870
    const std::uint32_t target=0x0040a870u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00406f86: { // 0x406f86: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00007030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x407030: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x407031: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x407033: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x407034: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x407036: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x40703c: e88f220000 CALL 0x004092d0
    const std::uint32_t call_target=0x004092d0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x407041: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x407043: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x407046: 83c901 OR ECX,0x1
    s.cx = integer::logical((s.cx)|(0x00000001u),32,flags);
  }
  { // 0x407049: c74610e8030000 MOV dword ptr [ESI + 0x10],0x3e8
    m.w32((s.si+0x00000010u), 0x000003e8u);
  }
  { // 0x407050: c1e710 SHL EDI,0x10
    s.di = integer::shift(s.di,0x00000010u,32,flags,integer::Shift::left);
  }
  { // 0x407053: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  { // 0x407055: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  { // 0x407058: 89561c MOV dword ptr [ESI + 0x1c],EDX
    m.w32((s.si+0x0000001cu), s.dx);
  }
  { // 0x40705b: c7460c4d621000 MOV dword ptr [ESI + 0xc],0x10624d
    m.w32((s.si+0x0000000cu), 0x0010624du);
  }
  { // 0x407062: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x407069: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40706b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40706c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40706d: e97e000000 JMP 0x004070f0
    const std::uint32_t target=0x004070f0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_000092d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4092d0: a198988100 MOV EAX,[0x00819898]
    s.ax = m.r32((0x00819898u));
  }
  { // 0x4092d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4092d7: 7402 JZ 0x004092db
    if(integer::condition("JZ",flags)) goto L004092db;
  }
  L004092d9: { // 0x4092d9: ffe0 JMP EAX
    const std::uint32_t target=s.ax;
    transfer(m,s,f,op,0u,target); return;
  }
  L004092db: { // 0x4092db: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4092dd: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4092df: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0000dbd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x40dbd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x40dbd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x40dbd3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x40dbd5: 741e JZ 0x0040dbf5
    if(integer::condition("JZ",flags)) goto L0040dbf5;
  }
  L0040dbd7: { // 0x40dbd7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x40dbd9: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40dbdc: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x40dbdd: 83f80e CMP EAX,0xe
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  { // 0x40dbe0: 7713 JA 0x0040dbf5
    if(integer::condition("JA",flags)) goto L0040dbf5;
  }
  L0040dbe2: { // 0x40dbe2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x40dbe4: 8a8804dc4000 MOV CL,byte ptr [EAX + 0x40dc04]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0040dc04u)));
  }
  { // 0x40dbea: ff248dfcdb4000 JMP dword ptr [ECX*0x4 + 0x40dbfc]
    const std::uint32_t destination=m.r32(((s.cx * 0x00000004u)+0x0040dbfcu));
    switch(destination) {
      case 0x40dbf1u: goto L0040dbf1;
      case 0x40dbf5u: goto L0040dbf5;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L0040dbf1: { // 0x40dbf1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x40dbf3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40dbf4: c3 RET
    finish(m,s,f,0u); return;
  }
  L0040dbf5: { // 0x40dbf5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40dbf7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40dbf8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0000dc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x40dc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x40dc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x40dc23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x40dc25: 741e JZ 0x0040dc45
    if(integer::condition("JZ",flags)) goto L0040dc45;
  }
  L0040dc27: { // 0x40dc27: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x40dc29: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40dc2c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x40dc2d: 83f80e CMP EAX,0xe
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  { // 0x40dc30: 7713 JA 0x0040dc45
    if(integer::condition("JA",flags)) goto L0040dc45;
  }
  L0040dc32: { // 0x40dc32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x40dc34: 8a8854dc4000 MOV CL,byte ptr [EAX + 0x40dc54]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0040dc54u)));
  }
  { // 0x40dc3a: ff248d4cdc4000 JMP dword ptr [ECX*0x4 + 0x40dc4c]
    const std::uint32_t destination=m.r32(((s.cx * 0x00000004u)+0x0040dc4cu));
    switch(destination) {
      case 0x40dc41u: goto L0040dc41;
      case 0x40dc45u: goto L0040dc45;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L0040dc41: { // 0x40dc41: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x40dc43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40dc44: c3 RET
    finish(m,s,f,0u); return;
  }
  L0040dc45: { // 0x40dc45: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40dc47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40dc48: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00022d50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x422d50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x422d51: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x422d55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x422d56: 8b96bc000000 MOV EDX,dword ptr [ESI + 0xbc]
    s.dx = m.r32((s.si+0x000000bcu));
  }
  { // 0x422d5c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x422d5e: 7425 JZ 0x00422d85
    if(integer::condition("JZ",flags)) goto L00422d85;
  }
  L00422d60: { // 0x422d60: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  { // 0x422d65: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x422d66: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x422d68: 7c1b JL 0x00422d85
    if(integer::condition("JL",flags)) goto L00422d85;
  }
  L00422d6a: { // 0x422d6a: 8b0d04eaa900 MOV ECX,dword ptr [0x00a9ea04]
    s.cx = m.r32((0x00a9ea04u));
  }
  { // 0x422d70: 8d0c81 LEA ECX,[ECX + EAX*0x4]
    s.cx = (s.cx+(s.ax * 0x00000004u));
  }
  L00422d73: { // 0x422d73: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  { // 0x422d75: 3b970c030000 CMP EDX,dword ptr [EDI + 0x30c]
    (void)integer::sub(s.dx,m.r32((s.di+0x0000030cu)),32,flags);
  }
  { // 0x422d7b: 7427 JZ 0x00422da4
    if(integer::condition("JZ",flags)) goto L00422da4;
  }
  L00422d7d: { // 0x422d7d: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x422d7e: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  { // 0x422d81: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x422d83: 7dee JGE 0x00422d73
    if(integer::condition("JGE",flags)) goto L00422d73;
  }
  L00422d85: { // 0x422d85: c786c0000000ffffffff MOV dword ptr [ESI + 0xc0],0xffffffff
    m.w32((s.si+0x000000c0u), 0xffffffffu);
  }
  L00422d8f: { // 0x422d8f: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x422d93: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x422d97: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x422d98: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x422d99: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x422d9a: e821d3feff CALL 0x004100c0
    const std::uint32_t call_target=0x004100c0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x422d9f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x422da0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x422da1: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00422da4: { // 0x422da4: 8986c0000000 MOV dword ptr [ESI + 0xc0],EAX
    m.w32((s.si+0x000000c0u), s.ax);
  }
  { // 0x422daa: ebe3 JMP 0x00422d8f
    goto L00422d8f;
  }
}
void f_0002fc80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42fc80: 8a4121 MOV AL,byte ptr [ECX + 0x21]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000021u)));
  }
  { // 0x42fc83: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42fc85: 740b JZ 0x0042fc92
    if(integer::condition("JZ",flags)) goto L0042fc92;
  }
  L0042fc87: { // 0x42fc87: 8a4125 MOV AL,byte ptr [ECX + 0x25]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000025u)));
  }
  { // 0x42fc8a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42fc8c: 7404 JZ 0x0042fc92
    if(integer::condition("JZ",flags)) goto L0042fc92;
  }
  L0042fc8e: { // 0x42fc8e: 8b4144 MOV EAX,dword ptr [ECX + 0x44]
    s.ax = m.r32((s.cx+0x00000044u));
  }
  { // 0x42fc91: c3 RET
    finish(m,s,f,0u); return;
  }
  L0042fc92: { // 0x42fc92: e9890a2000 JMP 0x00630720
    const std::uint32_t target=0x00630720u;
    transfer(m,s,f,op,0u,target); return;
  }
}
void f_0006fa20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46fa20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46fa21: 8b35e08b8300 MOV ESI,dword ptr [0x00838be0]
    s.si = m.r32((0x00838be0u));
  }
  { // 0x46fa27: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x46fa29: 7423 JZ 0x0046fa4e
    if(integer::condition("JZ",flags)) goto L0046fa4e;
  }
  L0046fa2b: { // 0x46fa2b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0046fa2c: { // 0x46fa2c: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x46fa2f: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x46fa31: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46fa33: 7409 JZ 0x0046fa3e
    if(integer::condition("JZ",flags)) goto L0046fa3e;
  }
  L0046fa35: { // 0x46fa35: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46fa36: e8ede42f00 CALL 0x0076df28
    const std::uint32_t call_target=0x0076df28u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46fa3b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046fa3e: { // 0x46fa3e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46fa3f: e837dc2f00 CALL 0x0076d67b
    const std::uint32_t call_target=0x0076d67bu;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46fa44: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x46fa47: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x46fa49: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x46fa4b: 75df JNZ 0x0046fa2c
    if(integer::condition("JNZ",flags)) goto L0046fa2c;
  }
  L0046fa4d: { // 0x46fa4d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046fa4e: { // 0x46fa4e: c705e08b830000000000 MOV dword ptr [0x00838be0],0x0
    m.w32((0x00838be0u), 0x00000000u);
  }
  { // 0x46fa58: b9ec8b8300 MOV ECX,0x838bec
    s.cx = 0x00838becu;
  }
  { // 0x46fa5d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46fa5e: e90d000000 JMP 0x0046fa70
    const std::uint32_t target=0x0046fa70u;
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_00082960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482960: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  { // 0x482965: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482967: 7418 JZ 0x00482981
    if(integer::condition("JZ",flags)) goto L00482981;
  }
  L00482969: { // 0x482969: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  { // 0x48296e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x482970: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x482972: ff9244010000 CALL dword ptr [EDX + 0x144]
    const std::uint32_t call_target=m.r32((s.dx+0x00000144u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x482978: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  { // 0x48297d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x48297f: 75e8 JNZ 0x00482969
    if(integer::condition("JNZ",flags)) goto L00482969;
  }
  L00482981: { // 0x482981: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x482983: e8588c2600 CALL 0x006eb5e0
    const std::uint32_t call_target=0x006eb5e0u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x482988: b9186c8300 MOV ECX,0x836c18
    s.cx = 0x00836c18u;
  }
  { // 0x48298d: e94ebefaff JMP 0x0042e7e0
    const std::uint32_t target=0x0042e7e0u;
    transfer(m,s,f,op,2u,target); return;
  }
}
void f_000829a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4829a0: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  { // 0x4829a3: 83f827 CMP EAX,0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  { // 0x4829a6: 7735 JA 0x004829dd
    if(integer::condition("JA",flags)) goto L004829dd;
  }
  L004829a8: { // 0x4829a8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4829aa: 8a88f4294800 MOV CL,byte ptr [EAX + 0x4829f4]
    s.cx = with_al(s.cx, m.r8((s.ax+0x004829f4u)));
  }
  { // 0x4829b0: ff248de0294800 JMP dword ptr [ECX*0x4 + 0x4829e0]
    const std::uint32_t destination=m.r32(((s.cx * 0x00000004u)+0x004829e0u));
    switch(destination) {
      case 0x4829b7u: goto L004829b7;
      case 0x4829c0u: goto L004829c0;
      case 0x4829cau: goto L004829ca;
      case 0x4829d3u: goto L004829d3;
      case 0x4829ddu: goto L004829dd;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004829b7: { // 0x4829b7: a17ce0a100 MOV EAX,[0x00a1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  { // 0x4829bc: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x4829bf: c3 RET
    finish(m,s,f,0u); return;
  }
  L004829c0: { // 0x4829c0: 8b0d0ce0a100 MOV ECX,dword ptr [0x00a1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  { // 0x4829c6: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  { // 0x4829c9: c3 RET
    finish(m,s,f,0u); return;
  }
  L004829ca: { // 0x4829ca: a1a47fa200 MOV EAX,[0x00a27fa4]
    s.ax = m.r32((0x00a27fa4u));
  }
  { // 0x4829cf: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x4829d2: c3 RET
    finish(m,s,f,0u); return;
  }
  L004829d3: { // 0x4829d3: 8b0dac55a200 MOV ECX,dword ptr [0x00a255ac]
    s.cx = m.r32((0x00a255acu));
  }
  { // 0x4829d9: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  { // 0x4829dc: c3 RET
    finish(m,s,f,0u); return;
  }
  L004829dd: { // 0x4829dd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4829df: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000af260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4af260: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4af261: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4af265: 83fe64 CMP ESI,0x64
    (void)integer::sub(s.si,0x00000064u,32,flags);
  }
  { // 0x4af268: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4af26a: 7767 JA 0x004af2d3
    if(integer::condition("JA",flags)) goto L004af2d3;
  }
  L004af26c: { // 0x4af26c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4af26e: 8a8ef0f24a00 MOV CL,byte ptr [ESI + 0x4af2f0]
    s.cx = with_al(s.cx, m.r8((s.si+0x004af2f0u)));
  }
  { // 0x4af274: ff248dd8f24a00 JMP dword ptr [ECX*0x4 + 0x4af2d8]
    const std::uint32_t destination=m.r32(((s.cx * 0x00000004u)+0x004af2d8u));
    switch(destination) {
      case 0x4af27bu: goto L004af27b;
      case 0x4af293u: goto L004af293;
      case 0x4af2b8u: goto L004af2b8;
      case 0x4af2d0u: goto L004af2d0;
      case 0x4af2d3u: goto L004af2d3;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004af27b: { // 0x4af27b: 668b1502b38300 MOV DX,word ptr [0x0083b302]
    s.dx = with_ax(s.dx, m.r16((0x0083b302u)));
  }
  { // 0x4af282: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x4af287: c1e802 SHR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4af28a: 23c2 AND EAX,EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  { // 0x4af28c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4af28d: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x4af290: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004af293: { // 0x4af293: 8b3500b38300 MOV ESI,dword ptr [0x0083b300]
    s.si = m.r32((0x0083b300u));
  }
  { // 0x4af299: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x4af29e: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  { // 0x4af2a4: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  { // 0x4af2aa: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  { // 0x4af2ac: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  { // 0x4af2ae: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  { // 0x4af2b0: 23d6 AND EDX,ESI
    s.dx = integer::logical((s.dx)&(s.si),32,flags);
  }
  { // 0x4af2b2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x4af2b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4af2b5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004af2b8: { // 0x4af2b8: 668b0d02b38300 MOV CX,word ptr [0x0083b302]
    s.cx = with_ax(s.cx, m.r16((0x0083b302u)));
  }
  { // 0x4af2bf: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x4af2c4: c1e802 SHR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4af2c7: 23c1 AND EAX,ECX
    s.ax = integer::logical((s.ax)&(s.cx),32,flags);
  }
  { // 0x4af2c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4af2ca: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x4af2cd: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004af2d0: { // 0x4af2d0: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L004af2d3: { // 0x4af2d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4af2d4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000bacf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bacf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bacf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bacf3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4bacf5: 668b4604 MOV AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000004u)));
  }
  { // 0x4bacf9: 83c0fd ADD EAX,-0x3
    s.ax = integer::add(s.ax,0xfffffffdu,32,flags);
  }
  { // 0x4bacfc: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x4bacff: 772b JA 0x004bad2c
    if(integer::condition("JA",flags)) goto L004bad2c;
  }
  L004bad01: { // 0x4bad01: ff24854cad4b00 JMP dword ptr [EAX*0x4 + 0x4bad4c]
    const std::uint32_t destination=m.r32(((s.ax * 0x00000004u)+0x004bad4cu));
    switch(destination) {
      case 0x4bad08u: goto L004bad08;
      case 0x4bad1cu: goto L004bad1c;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004bad08: { // 0x4bad08: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x4bad0b: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  { // 0x4bad0e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4bad0f: e898272b00 CALL 0x0076d4ac
    const std::uint32_t call_target=0x0076d4acu;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bad14: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x4bad17: 668902 MOV word ptr [EDX],AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  { // 0x4bad1a: eb10 JMP 0x004bad2c
    goto L004bad2c;
  }
  L004bad1c: { // 0x4bad1c: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x4bad1f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4bad21: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4bad22: e87f272b00 CALL 0x0076d4a6
    const std::uint32_t call_target=0x0076d4a6u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4bad27: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x4bad2a: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L004bad2c: { // 0x4bad2c: 668b4604 MOV AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000004u)));
  }
  { // 0x4bad30: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bad31: e876272b00 CALL 0x0076d4ac
    const std::uint32_t call_target=0x0076d4acu;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4bad36: 668b4e06 MOV CX,word ptr [ESI + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000006u)));
  }
  { // 0x4bad3a: 66894604 MOV word ptr [ESI + 0x4],AX
    m.w16((s.si+0x00000004u), (s.ax & 0xffffu));
  }
  { // 0x4bad3e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4bad3f: e868272b00 CALL 0x0076d4ac
    const std::uint32_t call_target=0x0076d4acu;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4bad44: 66894606 MOV word ptr [ESI + 0x6],AX
    m.w16((s.si+0x00000006u), (s.ax & 0xffffu));
  }
  { // 0x4bad48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bad49: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000bad60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bad60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bad61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bad63: 668b4606 MOV AX,word ptr [ESI + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000006u)));
  }
  { // 0x4bad67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bad68: e84b272b00 CALL 0x0076d4b8
    const std::uint32_t call_target=0x0076d4b8u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bad6d: 668b4e04 MOV CX,word ptr [ESI + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000004u)));
  }
  { // 0x4bad71: 66894606 MOV word ptr [ESI + 0x6],AX
    m.w16((s.si+0x00000006u), (s.ax & 0xffffu));
  }
  { // 0x4bad75: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4bad76: e83d272b00 CALL 0x0076d4b8
    const std::uint32_t call_target=0x0076d4b8u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4bad7b: 66894604 MOV word ptr [ESI + 0x4],AX
    m.w16((s.si+0x00000004u), (s.ax & 0xffffu));
  }
  { // 0x4bad7f: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x4bad84: 83c0fd ADD EAX,-0x3
    s.ax = integer::add(s.ax,0xfffffffdu,32,flags);
  }
  { // 0x4bad87: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x4bad8a: 772b JA 0x004badb7
    if(integer::condition("JA",flags)) goto L004badb7;
  }
  L004bad8c: { // 0x4bad8c: ff2485bcad4b00 JMP dword ptr [EAX*0x4 + 0x4badbc]
    const std::uint32_t destination=m.r32(((s.ax * 0x00000004u)+0x004badbcu));
    switch(destination) {
      case 0x4bad93u: goto L004bad93;
      case 0x4bada7u: goto L004bada7;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004bad93: { // 0x4bad93: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x4bad96: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  { // 0x4bad99: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bad9a: e819272b00 CALL 0x0076d4b8
    const std::uint32_t call_target=0x0076d4b8u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4bad9f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4bada2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bada3: 668901 MOV word ptr [ECX],AX
    m.w16((s.cx), (s.ax & 0xffffu));
  }
  { // 0x4bada6: c3 RET
    finish(m,s,f,0u); return;
  }
  L004bada7: { // 0x4bada7: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x4badaa: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x4badac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4badad: e800272b00 CALL 0x0076d4b2
    const std::uint32_t call_target=0x0076d4b2u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4badb2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4badb5: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L004badb7: { // 0x4badb7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4badb8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000cec60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cec60: c7012cc87800 MOV dword ptr [ECX],0x78c82c
    m.w32((s.cx), 0x0078c82cu);
  }
  { // 0x4cec66: a128e38400 MOV EAX,[0x0084e328]
    s.ax = m.r32((0x0084e328u));
  }
  { // 0x4cec6b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4cec6d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4cec6f: 7510 JNZ 0x004cec81
    if(integer::condition("JNZ",flags)) goto L004cec81;
  }
  L004cec71: { // 0x4cec71: 8b4120 MOV EAX,dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  { // 0x4cec74: 80e4fe AND AH,0xfe
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000feu),8,flags)) & 0xffu) << 8);
  }
  { // 0x4cec77: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  { // 0x4cec7a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4cec7c: a328e38400 MOV [0x0084e328],EAX
    m.w32((0x0084e328u), s.ax);
  }
  L004cec81: { // 0x4cec81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cec82: 8b3520e38400 MOV ESI,dword ptr [0x0084e320]
    s.si = m.r32((0x0084e320u));
  }
  { // 0x4cec88: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x4cec8a: 7506 JNZ 0x004cec92
    if(integer::condition("JNZ",flags)) goto L004cec92;
  }
  L004cec8c: { // 0x4cec8c: 891520e38400 MOV dword ptr [0x0084e320],EDX
    m.w32((0x0084e320u), s.dx);
  }
  L004cec92: { // 0x4cec92: 8b3524e38400 MOV ESI,dword ptr [0x0084e324]
    s.si = m.r32((0x0084e324u));
  }
  { // 0x4cec98: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x4cec9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cec9b: 7506 JNZ 0x004ceca3
    if(integer::condition("JNZ",flags)) goto L004ceca3;
  }
  L004cec9d: { // 0x4cec9d: 891524e38400 MOV dword ptr [0x0084e324],EDX
    m.w32((0x0084e324u), s.dx);
  }
  L004ceca3: { // 0x4ceca3: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4ceca5: 7506 JNZ 0x004cecad
    if(integer::condition("JNZ",flags)) goto L004cecad;
  }
  L004ceca7: { // 0x4ceca7: 891528e38400 MOV dword ptr [0x0084e328],EDX
    m.w32((0x0084e328u), s.dx);
  }
  L004cecad: { // 0x4cecad: e9ce840600 JMP 0x00537180
    const std::uint32_t target=0x00537180u;
    transfer(m,s,f,op,0u,target); return;
  }
}
void f_000e6ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e6ab0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4e6ab4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4e6ab5: 83f827 CMP EAX,0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  { // 0x4e6ab8: 7769 JA 0x004e6b23
    if(integer::condition("JA",flags)) goto L004e6b23;
  }
  L004e6aba: { // 0x4e6aba: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4e6abc: 8a903c6b4e00 MOV DL,byte ptr [EAX + 0x4e6b3c]
    s.dx = with_al(s.dx, m.r8((s.ax+0x004e6b3cu)));
  }
  { // 0x4e6ac2: ff2495286b4e00 JMP dword ptr [EDX*0x4 + 0x4e6b28]
    const std::uint32_t destination=m.r32(((s.dx * 0x00000004u)+0x004e6b28u));
    switch(destination) {
      case 0x4e6ac9u: goto L004e6ac9;
      case 0x4e6adfu: goto L004e6adf;
      case 0x4e6af6u: goto L004e6af6;
      case 0x4e6b0cu: goto L004e6b0c;
      case 0x4e6b23u: goto L004e6b23;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004e6ac9: { // 0x4e6ac9: 8b8948550000 MOV ECX,dword ptr [ECX + 0x5548]
    s.cx = m.r32((s.cx+0x00005548u));
  }
  { // 0x4e6acf: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x4e6ad2: 744f JZ 0x004e6b23
    if(integer::condition("JZ",flags)) goto L004e6b23;
  }
  L004e6ad4: { // 0x4e6ad4: a1ac55a200 MOV EAX,[0x00a255ac]
    s.ax = m.r32((0x00a255acu));
  }
  { // 0x4e6ad9: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x4e6adc: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004e6adf: { // 0x4e6adf: 8b8940550000 MOV ECX,dword ptr [ECX + 0x5540]
    s.cx = m.r32((s.cx+0x00005540u));
  }
  { // 0x4e6ae5: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x4e6ae8: 7439 JZ 0x004e6b23
    if(integer::condition("JZ",flags)) goto L004e6b23;
  }
  L004e6aea: { // 0x4e6aea: 8b157ce0a100 MOV EDX,dword ptr [0x00a1e07c]
    s.dx = m.r32((0x00a1e07cu));
  }
  { // 0x4e6af0: 8b048a MOV EAX,dword ptr [EDX + ECX*0x4]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  { // 0x4e6af3: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004e6af6: { // 0x4e6af6: 8b8944550000 MOV ECX,dword ptr [ECX + 0x5544]
    s.cx = m.r32((s.cx+0x00005544u));
  }
  { // 0x4e6afc: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x4e6aff: 7422 JZ 0x004e6b23
    if(integer::condition("JZ",flags)) goto L004e6b23;
  }
  L004e6b01: { // 0x4e6b01: a1a47fa200 MOV EAX,[0x00a27fa4]
    s.ax = m.r32((0x00a27fa4u));
  }
  { // 0x4e6b06: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x4e6b09: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004e6b0c: { // 0x4e6b0c: 8b893c550000 MOV ECX,dword ptr [ECX + 0x553c]
    s.cx = m.r32((s.cx+0x0000553cu));
  }
  { // 0x4e6b12: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x4e6b15: 740c JZ 0x004e6b23
    if(integer::condition("JZ",flags)) goto L004e6b23;
  }
  L004e6b17: { // 0x4e6b17: 8b150ce0a100 MOV EDX,dword ptr [0x00a1e00c]
    s.dx = m.r32((0x00a1e00cu));
  }
  { // 0x4e6b1d: 8b048a MOV EAX,dword ptr [EDX + ECX*0x4]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  { // 0x4e6b20: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004e6b23: { // 0x4e6b23: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4e6b25: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000eaaa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4eaaa0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4eaaa4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4eaaa5: 83f827 CMP EAX,0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  { // 0x4eaaa8: 7754 JA 0x004eaafe
    if(integer::condition("JA",flags)) goto L004eaafe;
  }
  L004eaaaa: { // 0x4eaaaa: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4eaaac: 8a9018ab4e00 MOV DL,byte ptr [EAX + 0x4eab18]
    s.dx = with_al(s.dx, m.r8((s.ax+0x004eab18u)));
  }
  { // 0x4eaab2: ff249504ab4e00 JMP dword ptr [EDX*0x4 + 0x4eab04]
    const std::uint32_t destination=m.r32(((s.dx * 0x00000004u)+0x004eab04u));
    switch(destination) {
      case 0x4eaab9u: goto L004eaab9;
      case 0x4eaac2u: goto L004eaac2;
      case 0x4eaadcu: goto L004eaadc;
      case 0x4eaaf5u: goto L004eaaf5;
      case 0x4eaafeu: goto L004eaafe;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004eaab9: { // 0x4eaab9: 8b81dc520000 MOV EAX,dword ptr [ECX + 0x52dc]
    s.ax = m.r32((s.cx+0x000052dcu));
  }
  { // 0x4eaabf: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004eaac2: { // 0x4eaac2: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x4eaac6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4eaac8: 7409 JZ 0x004eaad3
    if(integer::condition("JZ",flags)) goto L004eaad3;
  }
  L004eaaca: { // 0x4eaaca: 8b81e4520000 MOV EAX,dword ptr [ECX + 0x52e4]
    s.ax = m.r32((s.cx+0x000052e4u));
  }
  { // 0x4eaad0: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004eaad3: { // 0x4eaad3: 8b81e0520000 MOV EAX,dword ptr [ECX + 0x52e0]
    s.ax = m.r32((s.cx+0x000052e0u));
  }
  { // 0x4eaad9: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004eaadc: { // 0x4eaadc: 837c240c05 CMP dword ptr [ESP + 0xc],0x5
    (void)integer::sub(m.r32((f.sp+0x0000000cu)),0x00000005u,32,flags);
  }
  { // 0x4eaae1: 7509 JNZ 0x004eaaec
    if(integer::condition("JNZ",flags)) goto L004eaaec;
  }
  L004eaae3: { // 0x4eaae3: 8b81f8520000 MOV EAX,dword ptr [ECX + 0x52f8]
    s.ax = m.r32((s.cx+0x000052f8u));
  }
  { // 0x4eaae9: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004eaaec: { // 0x4eaaec: 8b81e8520000 MOV EAX,dword ptr [ECX + 0x52e8]
    s.ax = m.r32((s.cx+0x000052e8u));
  }
  { // 0x4eaaf2: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004eaaf5: { // 0x4eaaf5: 8b81d8520000 MOV EAX,dword ptr [ECX + 0x52d8]
    s.ax = m.r32((s.cx+0x000052d8u));
  }
  { // 0x4eaafb: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004eaafe: { // 0x4eaafe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4eab00: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_000ead30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ead30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4ead34: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4ead35: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4ead36: 83f827 CMP EAX,0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  { // 0x4ead39: 7762 JA 0x004ead9d
    if(integer::condition("JA",flags)) goto L004ead9d;
  }
  L004ead3b: { // 0x4ead3b: 8a542414 MOV DL,byte ptr [ESP + 0x14]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000014u)));
  }
  { // 0x4ead3f: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4ead41: 8a98b8ad4e00 MOV BL,byte ptr [EAX + 0x4eadb8]
    s.bx = with_al(s.bx, m.r8((s.ax+0x004eadb8u)));
  }
  { // 0x4ead47: ff249da4ad4e00 JMP dword ptr [EBX*0x4 + 0x4eada4]
    const std::uint32_t destination=m.r32(((s.bx * 0x00000004u)+0x004eada4u));
    switch(destination) {
      case 0x4ead4eu: goto L004ead4e;
      case 0x4ead54u: goto L004ead54;
      case 0x4ead70u: goto L004ead70;
      case 0x4ead93u: goto L004ead93;
      case 0x4ead9du: goto L004ead9d;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004ead4e: { // 0x4ead4e: 8891fd520000 MOV byte ptr [ECX + 0x52fd],DL
    m.w8((s.cx+0x000052fdu), (s.dx & 0xffu));
  }
  L004ead54: { // 0x4ead54: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x4ead58: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4ead5a: 740a JZ 0x004ead66
    if(integer::condition("JZ",flags)) goto L004ead66;
  }
  L004ead5c: { // 0x4ead5c: 8891ff520000 MOV byte ptr [ECX + 0x52ff],DL
    m.w8((s.cx+0x000052ffu), (s.dx & 0xffu));
  }
  { // 0x4ead62: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4ead63: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L004ead66: { // 0x4ead66: 8891fe520000 MOV byte ptr [ECX + 0x52fe],DL
    m.w8((s.cx+0x000052feu), (s.dx & 0xffu));
  }
  { // 0x4ead6c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4ead6d: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L004ead70: { // 0x4ead70: 837c241005 CMP dword ptr [ESP + 0x10],0x5
    (void)integer::sub(m.r32((f.sp+0x00000010u)),0x00000005u,32,flags);
  }
  { // 0x4ead75: 750e JNZ 0x004ead85
    if(integer::condition("JNZ",flags)) goto L004ead85;
  }
  L004ead77: { // 0x4ead77: 8a542414 MOV DL,byte ptr [ESP + 0x14]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000014u)));
  }
  { // 0x4ead7b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4ead7c: 889104530000 MOV byte ptr [ECX + 0x5304],DL
    m.w8((s.cx+0x00005304u), (s.dx & 0xffu));
  }
  { // 0x4ead82: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L004ead85: { // 0x4ead85: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  { // 0x4ead89: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4ead8a: 888100530000 MOV byte ptr [ECX + 0x5300],AL
    m.w8((s.cx+0x00005300u), (s.ax & 0xffu));
  }
  { // 0x4ead90: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L004ead93: { // 0x4ead93: 8a542414 MOV DL,byte ptr [ESP + 0x14]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000014u)));
  }
  { // 0x4ead97: 8891fc520000 MOV byte ptr [ECX + 0x52fc],DL
    m.w8((s.cx+0x000052fcu), (s.dx & 0xffu));
  }
  L004ead9d: { // 0x4ead9d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4ead9e: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_000eaea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4eaea0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4eaea4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4eaea5: 83f827 CMP EAX,0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  { // 0x4eaea8: 7746 JA 0x004eaef0
    if(integer::condition("JA",flags)) goto L004eaef0;
  }
  L004eaeaa: { // 0x4eaeaa: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4eaeac: 8a900caf4e00 MOV DL,byte ptr [EAX + 0x4eaf0c]
    s.dx = with_al(s.dx, m.r8((s.ax+0x004eaf0cu)));
  }
  { // 0x4eaeb2: ff2495f8ae4e00 JMP dword ptr [EDX*0x4 + 0x4eaef8]
    const std::uint32_t destination=m.r32(((s.dx * 0x00000004u)+0x004eaef8u));
    switch(destination) {
      case 0x4eaeb9u: goto L004eaeb9;
      case 0x4eaed1u: goto L004eaed1;
      case 0x4eaed9u: goto L004eaed9;
      case 0x4eaee1u: goto L004eaee1;
      case 0x4eaef0u: goto L004eaef0;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L004eaeb9: { // 0x4eaeb9: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x4eaebd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4eaebf: 7408 JZ 0x004eaec9
    if(integer::condition("JZ",flags)) goto L004eaec9;
  }
  L004eaec1: { // 0x4eaec1: 8d81c8520000 LEA EAX,[ECX + 0x52c8]
    s.ax = (s.cx+0x000052c8u);
  }
  { // 0x4eaec7: eb1e JMP 0x004eaee7
    goto L004eaee7;
  }
  L004eaec9: { // 0x4eaec9: 8d81c0520000 LEA EAX,[ECX + 0x52c0]
    s.ax = (s.cx+0x000052c0u);
  }
  { // 0x4eaecf: eb16 JMP 0x004eaee7
    goto L004eaee7;
  }
  L004eaed1: { // 0x4eaed1: 8d81b8520000 LEA EAX,[ECX + 0x52b8]
    s.ax = (s.cx+0x000052b8u);
  }
  { // 0x4eaed7: eb0e JMP 0x004eaee7
    goto L004eaee7;
  }
  L004eaed9: { // 0x4eaed9: 8d81bc520000 LEA EAX,[ECX + 0x52bc]
    s.ax = (s.cx+0x000052bcu);
  }
  { // 0x4eaedf: eb06 JMP 0x004eaee7
    goto L004eaee7;
  }
  L004eaee1: { // 0x4eaee1: 8d81c4520000 LEA EAX,[ECX + 0x52c4]
    s.ax = (s.cx+0x000052c4u);
  }
  L004eaee7: { // 0x4eaee7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4eaee9: 7405 JZ 0x004eaef0
    if(integer::condition("JZ",flags)) goto L004eaef0;
  }
  L004eaeeb: { // 0x4eaeeb: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x4eaeed: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004eaef0: { // 0x4eaef0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4eaef2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000f4d80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f4d80: 3b0de4e0a100 CMP ECX,dword ptr [0x00a1e0e4]
    (void)integer::sub(s.cx,m.r32((0x00a1e0e4u)),32,flags);
  }
  { // 0x4f4d86: 7514 JNZ 0x004f4d9c
    if(integer::condition("JNZ",flags)) goto L004f4d9c;
  }
  L004f4d88: { // 0x4f4d88: 8a816a560000 MOV AL,byte ptr [ECX + 0x566a]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000566au)));
  }
  { // 0x4f4d8e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4f4d90: 750a JNZ 0x004f4d9c
    if(integer::condition("JNZ",flags)) goto L004f4d9c;
  }
  L004f4d92: { // 0x4f4d92: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x4f4d97: e9641f0600 JMP 0x00556d00
    const std::uint32_t target=0x00556d00u;
    transfer(m,s,f,op,0u,target); return;
  }
  L004f4d9c: { // 0x4f4d9c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001054a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5054a0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5054a1: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  { // 0x5054a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5054a6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5054a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5054a9: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x5054ad: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5054af: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5054b0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5054b1: ff5070 CALL dword ptr [EAX + 0x70]
    const std::uint32_t call_target=m.r32((s.ax+0x00000070u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5054b4: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  { // 0x5054b7: 83f938 CMP ECX,0x38
    (void)integer::sub(s.cx,0x00000038u,32,flags);
  }
  { // 0x5054ba: 771b JA 0x005054d7
    if(integer::condition("JA",flags)) goto L005054d7;
  }
  L005054bc: { // 0x5054bc: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5054be: 8a9108555000 MOV DL,byte ptr [ECX + 0x505508]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00505508u)));
  }
  { // 0x5054c4: ff2495f8545000 JMP dword ptr [EDX*0x4 + 0x5054f8]
    const std::uint32_t destination=m.r32(((s.dx * 0x00000004u)+0x005054f8u));
    switch(destination) {
      case 0x5054cbu: goto L005054cb;
      case 0x5054d2u: goto L005054d2;
      case 0x5054d7u: goto L005054d7;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L005054cb: { // 0x5054cb: b809000000 MOV EAX,0x9
    s.ax = 0x00000009u;
  }
  { // 0x5054d0: eb05 JMP 0x005054d7
    goto L005054d7;
  }
  L005054d2: { // 0x5054d2: b805000000 MOV EAX,0x5
    s.ax = 0x00000005u;
  }
  L005054d7: { // 0x5054d7: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  { // 0x5054d9: 750d JNZ 0x005054e8
    if(integer::condition("JNZ",flags)) goto L005054e8;
  }
  L005054db: { // 0x5054db: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  { // 0x5054de: 7508 JNZ 0x005054e8
    if(integer::condition("JNZ",flags)) goto L005054e8;
  }
  L005054e0: { // 0x5054e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5054e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5054e2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5054e4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5054e5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L005054e8: { // 0x5054e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5054e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5054ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5054eb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5054ed: e80e09fcff CALL 0x004c5e00
    const std::uint32_t call_target=0x004c5e00u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5054f2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5054f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5054f4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5054f5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00124ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x524ed0: 8b4148 MOV EAX,dword ptr [ECX + 0x48]
    s.ax = m.r32((s.cx+0x00000048u));
  }
  { // 0x524ed3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x524ed5: 7408 JZ 0x00524edf
    if(integer::condition("JZ",flags)) goto L00524edf;
  }
  L00524ed7: { // 0x524ed7: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x524eda: e9f1b6f5ff JMP 0x004805d0
    const std::uint32_t target=0x004805d0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00524edf: { // 0x524edf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x524ee1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00124f10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x524f10: 8b4150 MOV EAX,dword ptr [ECX + 0x50]
    s.ax = m.r32((s.cx+0x00000050u));
  }
  { // 0x524f13: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x524f15: 7408 JZ 0x00524f1f
    if(integer::condition("JZ",flags)) goto L00524f1f;
  }
  L00524f17: { // 0x524f17: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x524f1a: e9b1b6f5ff JMP 0x004805d0
    const std::uint32_t target=0x004805d0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00524f1f: { // 0x524f1f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x524f21: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00130a60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x530a60: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x530a64: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x530a65: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  { // 0x530a68: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x530a6a: 7543 JNZ 0x00530aaf
    if(integer::condition("JNZ",flags)) goto L00530aaf;
  }
  L00530a6c: { // 0x530a6c: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x530a71: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x530a73: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  { // 0x530a79: 8d51f8 LEA EDX,[ECX + -0x8]
    s.dx = (s.cx-0x00000008u);
  }
  { // 0x530a7c: 83fa1c CMP EDX,0x1c
    (void)integer::sub(s.dx,0x0000001cu,32,flags);
  }
  { // 0x530a7f: 772e JA 0x00530aaf
    if(integer::condition("JA",flags)) goto L00530aaf;
  }
  L00530a81: { // 0x530a81: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x530a83: 8a8acc0a5300 MOV CL,byte ptr [EDX + 0x530acc]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00530accu)));
  }
  { // 0x530a89: ff248db80a5300 JMP dword ptr [ECX*0x4 + 0x530ab8]
    const std::uint32_t destination=m.r32(((s.cx * 0x00000004u)+0x00530ab8u));
    switch(destination) {
      case 0x530a90u: goto L00530a90;
      case 0x530a96u: goto L00530a96;
      case 0x530a9cu: goto L00530a9c;
      case 0x530aafu: goto L00530aaf;
      case 0x530ab1u: goto L00530ab1;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L00530a90: { // 0x530a90: b008 MOV AL,0x8
    s.ax = with_al(s.ax, 0x00000008u);
  }
  { // 0x530a92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530a93: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00530a96: { // 0x530a96: b05c MOV AL,0x5c
    s.ax = with_al(s.ax, 0x0000005cu);
  }
  { // 0x530a98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530a99: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00530a9c: { // 0x530a9c: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000008u)));
  }
  { // 0x530a9f: 3c0d CMP AL,0xd
    (void)integer::sub((s.ax & 0xffu),0x0000000du,8,flags);
  }
  { // 0x530aa1: 7502 JNZ 0x00530aa5
    if(integer::condition("JNZ",flags)) goto L00530aa5;
  }
  L00530aa3: { // 0x530aa3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00530aa5: { // 0x530aa5: 66c746080000 MOV word ptr [ESI + 0x8],0x0
    m.w16((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x530aab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530aac: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00530aaf: { // 0x530aaf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00530ab1: { // 0x530ab1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530ab2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00133df0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x533df0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x533df1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x533df3: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x533df6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x533df8: 752a JNZ 0x00533e24
    if(integer::condition("JNZ",flags)) goto L00533e24;
  }
  L00533dfa: { // 0x533dfa: 6a28 PUSH 0x28
    f.push(m,0x00000028u);
  }
  { // 0x533dfc: e8569b2300 CALL 0x0076d957
    const std::uint32_t call_target=0x0076d957u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x533e01: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x533e04: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x533e06: 7413 JZ 0x00533e1b
    if(integer::condition("JZ",flags)) goto L00533e1b;
  }
  L00533e08: { // 0x533e08: 6850138200 PUSH 0x821350
    f.push(m,0x00821350u);
  }
  { // 0x533e0d: 68b0a07c00 PUSH 0x7ca0b0
    f.push(m,0x007ca0b0u);
  }
  { // 0x533e12: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x533e14: e8d7e20500 CALL 0x005920f0
    const std::uint32_t call_target=0x005920f0u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x533e19: eb02 JMP 0x00533e1d
    goto L00533e1d;
  }
  L00533e1b: { // 0x533e1b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00533e1d: { // 0x533e1d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x533e1f: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x533e22: 7426 JZ 0x00533e4a
    if(integer::condition("JZ",flags)) goto L00533e4a;
  }
  L00533e24: { // 0x533e24: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x533e29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x533e2b: 7518 JNZ 0x00533e45
    if(integer::condition("JNZ",flags)) goto L00533e45;
  }
  L00533e2d: { // 0x533e2d: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x533e32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x533e34: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x533e35: 8a9039220000 MOV DL,byte ptr [EAX + 0x2239]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00002239u)));
  }
  { // 0x533e3b: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x533e3d: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x533e40: e93b371b00 JMP 0x006e7580
    const std::uint32_t target=0x006e7580u;
    transfer(m,s,f,op,2u,target); return;
  }
  L00533e45: { // 0x533e45: e856381b00 CALL 0x006e76a0
    const std::uint32_t call_target=0x006e76a0u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00533e4a: { // 0x533e4a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x533e4b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019ecc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59ecc0: 8b0dc88ca500 MOV ECX,dword ptr [0x00a58cc8]
    s.cx = m.r32((0x00a58cc8u));
  }
  { // 0x59ecc6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x59ecc8: 7405 JZ 0x0059eccf
    if(integer::condition("JZ",flags)) goto L0059eccf;
  }
  L0059ecca: { // 0x59ecca: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x59eccc: ff6024 JMP dword ptr [EAX + 0x24]
    const std::uint32_t target=m.r32((s.ax+0x00000024u));
    transfer(m,s,f,op,0u,target); return;
  }
  L0059eccf: { // 0x59eccf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b7610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b7610: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b7611: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b7613: b9bc000000 MOV ECX,0xbc
    s.cx = 0x000000bcu;
  }
  { // 0x5b7618: e8e32e1700 CALL 0x0072a500
    const std::uint32_t call_target=0x0072a500u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b761d: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x5b761f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5b7621: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b7622: e939d60000 JMP 0x005c4c60
    const std::uint32_t target=0x005c4c60u;
    transfer(m,s,f,op,1u,target); return;
  }
}
} // namespace
const std::array<Entry,44>& entries_a() {
  static const std::array<Entry,44> entries{{
    {0x1000u,f_00001000},
    {0x1080u,f_00001080},
    {0x1fc0u,f_00001fc0},
    {0x23f0u,f_000023f0},
    {0x2600u,f_00002600},
    {0x2650u,f_00002650},
    {0x26c0u,f_000026c0},
    {0x26f0u,f_000026f0},
    {0x5590u,f_00005590},
    {0x61e0u,f_000061e0},
    {0x6280u,f_00006280},
    {0x6560u,f_00006560},
    {0x6dc0u,f_00006dc0},
    {0x6de0u,f_00006de0},
    {0x6e00u,f_00006e00},
    {0x6e20u,f_00006e20},
    {0x6e40u,f_00006e40},
    {0x6e70u,f_00006e70},
    {0x6f70u,f_00006f70},
    {0x7030u,f_00007030},
    {0x92d0u,f_000092d0},
    {0xdbd0u,f_0000dbd0},
    {0xdc20u,f_0000dc20},
    {0x22d50u,f_00022d50},
    {0x2fc80u,f_0002fc80},
    {0x6fa20u,f_0006fa20},
    {0x82960u,f_00082960},
    {0x829a0u,f_000829a0},
    {0xaf260u,f_000af260},
    {0xbacf0u,f_000bacf0},
    {0xbad60u,f_000bad60},
    {0xcec60u,f_000cec60},
    {0xe6ab0u,f_000e6ab0},
    {0xeaaa0u,f_000eaaa0},
    {0xead30u,f_000ead30},
    {0xeaea0u,f_000eaea0},
    {0xf4d80u,f_000f4d80},
    {0x1054a0u,f_001054a0},
    {0x124ed0u,f_00124ed0},
    {0x124f10u,f_00124f10},
    {0x130a60u,f_00130a60},
    {0x133df0u,f_00133df0},
    {0x19ecc0u,f_0019ecc0},
    {0x1b7610u,f_001b7610},
  }}; return entries;
}
} // namespace ra2::recovered::transfers_b38
