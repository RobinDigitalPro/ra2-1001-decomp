#include "recovered/recovery_b204_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b204 {
namespace {
void f_002b72a0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_00105da0(Memory&,State&,Frame&,const Operations&);
void f_00108c50(Memory&,State&,Frame&,const Operations&);
void f_002cdab0(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b72a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b72a0: { // 0x6b72a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b72a1: { // 0x6b72a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b72a3: { // 0x6b72a3: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006b72a9: { // 0x6b72a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b72ab: { // 0x6b72ab: 7418 JZ 0x006b72c5
    if(integer::condition("JZ",flags)) goto L006b72c5;
  }
  L006b72ad: { // 0x6b72ad: 3905e4e0a100 CMP dword ptr [0x00a1e0e4],EAX
    (void)integer::sub(m.r32((0x00a1e0e4u)),s.ax,32,flags);
  }
  L006b72b3: { // 0x6b72b3: 7509 JNZ 0x006b72be
    if(integer::condition("JNZ",flags)) goto L006b72be;
  }
  L006b72b5: { // 0x6b72b5: c6867203000001 MOV byte ptr [ESI + 0x372],0x1
    m.w8((s.si+0x00000372u), 0x00000001u);
  }
  L006b72bc: { // 0x6b72bc: eb07 JMP 0x006b72c5
    goto L006b72c5;
  }
  L006b72be: { // 0x6b72be: c6867203000000 MOV byte ptr [ESI + 0x372],0x0
    m.w8((s.si+0x00000372u), 0x00000000u);
  }
  L006b72c5: { // 0x6b72c5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b72c7: { // 0x6b72c7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72c9: { // 0x6b72c9: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7041743u); flags=s.arithmetic_flags;
  }
  L006b72cf: { // 0x6b72cf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b72d1: { // 0x6b72d1: 0f849b020000 JZ 0x006b7572
    if(integer::condition("JZ",flags)) goto L006b7572;
  }
  L006b72d7: { // 0x6b72d7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b72d9: { // 0x6b72d9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72db: { // 0x6b72db: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041761u); flags=s.arithmetic_flags;
  }
  L006b72e1: { // 0x6b72e1: 8b8840050000 MOV ECX,dword ptr [EAX + 0x540]
    s.cx = m.r32((s.ax+0x00000540u));
  }
  L006b72e7: { // 0x6b72e7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b72e9: { // 0x6b72e9: 740b JZ 0x006b72f6
    if(integer::condition("JZ",flags)) goto L006b72f6;
  }
  L006b72eb: { // 0x6b72eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b72ec: { // 0x6b72ec: b920a68100 MOV ECX,0x81a620
    s.cx = 0x0081a620u;
  }
  L006b72f1: { // 0x6b72f1: e80af2d7ff CALL 0x00436500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00436500u,7041782u); flags=s.arithmetic_flags;
  }
  L006b72f6: { // 0x6b72f6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b72f8: { // 0x6b72f8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72fa: { // 0x6b72fa: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7041792u); flags=s.arithmetic_flags;
  }
  L006b7300: { // 0x6b7300: 8b88080b0000 MOV ECX,dword ptr [EAX + 0xb08]
    s.cx = m.r32((s.ax+0x00000b08u));
  }
  L006b7306: { // 0x6b7306: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b7308: { // 0x6b7308: 7468 JZ 0x006b7372
    if(integer::condition("JZ",flags)) goto L006b7372;
  }
  L006b730a: { // 0x6b730a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b730b: { // 0x6b730b: 6a74 PUSH 0x74
    f.push(m,0x00000074u);
  }
  L006b730d: { // 0x6b730d: e845660b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7041810u); flags=s.arithmetic_flags;
  }
  L006b7312: { // 0x6b7312: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006b7314: { // 0x6b7314: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7317: { // 0x6b7317: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b7319: { // 0x6b7319: 744e JZ 0x006b7369
    if(integer::condition("JZ",flags)) goto L006b7369;
  }
  L006b731b: { // 0x6b731b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b731d: { // 0x6b731d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b731f: { // 0x6b731f: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041829u); flags=s.arithmetic_flags;
  }
  L006b7325: { // 0x6b7325: 8b80140b0000 MOV EAX,dword ptr [EAX + 0xb14]
    s.ax = m.r32((s.ax+0x00000b14u));
  }
  L006b732b: { // 0x6b732b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b732d: { // 0x6b732d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b732e: { // 0x6b732e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7330: { // 0x6b7330: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041846u); flags=s.arithmetic_flags;
  }
  L006b7336: { // 0x6b7336: 8b80100b0000 MOV EAX,dword ptr [EAX + 0xb10]
    s.ax = m.r32((s.ax+0x00000b10u));
  }
  L006b733c: { // 0x6b733c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b733e: { // 0x6b733e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b733f: { // 0x6b733f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7341: { // 0x6b7341: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041863u); flags=s.arithmetic_flags;
  }
  L006b7347: { // 0x6b7347: 8b800c0b0000 MOV EAX,dword ptr [EAX + 0xb0c]
    s.ax = m.r32((s.ax+0x00000b0cu));
  }
  L006b734d: { // 0x6b734d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b734f: { // 0x6b734f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b7350: { // 0x6b7350: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7352: { // 0x6b7352: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041880u); flags=s.arithmetic_flags;
  }
  L006b7358: { // 0x6b7358: 8b80080b0000 MOV EAX,dword ptr [EAX + 0xb08]
    s.ax = m.r32((s.ax+0x00000b08u));
  }
  L006b735e: { // 0x6b735e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b7360: { // 0x6b7360: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b7361: { // 0x6b7361: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b7362: { // 0x6b7362: e8a97afcff CALL 0x0067ee10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0067ee10u,7041895u); flags=s.arithmetic_flags;
  }
  L006b7367: { // 0x6b7367: eb02 JMP 0x006b736b
    goto L006b736b;
  }
  L006b7369: { // 0x6b7369: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b736b: { // 0x6b736b: 898638020000 MOV dword ptr [ESI + 0x238],EAX
    m.w32((s.si+0x00000238u), s.ax);
  }
  L006b7371: { // 0x6b7371: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b7372: { // 0x6b7372: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b7374: { // 0x6b7374: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7376: { // 0x6b7376: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7378: { // 0x6b7378: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7041918u); flags=s.arithmetic_flags;
  }
  L006b737e: { // 0x6b737e: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b7381: { // 0x6b7381: 743e JZ 0x006b73c1
    if(integer::condition("JZ",flags)) goto L006b73c1;
  }
  L006b7383: { // 0x6b7383: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b7385: { // 0x6b7385: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7387: { // 0x6b7387: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7389: { // 0x6b7389: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7041935u); flags=s.arithmetic_flags;
  }
  L006b738f: { // 0x6b738f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b7391: { // 0x6b7391: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  L006b7397: { // 0x6b7397: 8a8253010000 MOV AL,byte ptr [EDX + 0x153]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000153u)));
  }
  L006b739d: { // 0x6b739d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b739f: { // 0x6b739f: 7420 JZ 0x006b73c1
    if(integer::condition("JZ",flags)) goto L006b73c1;
  }
  L006b73a1: { // 0x6b73a1: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L006b73a3: { // 0x6b73a3: e8af650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7041960u); flags=s.arithmetic_flags;
  }
  L006b73a8: { // 0x6b73a8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b73ab: { // 0x6b73ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b73ad: { // 0x6b73ad: 740a JZ 0x006b73b9
    if(integer::condition("JZ",flags)) goto L006b73b9;
  }
  L006b73af: { // 0x6b73af: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b73b0: { // 0x6b73b0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b73b2: { // 0x6b73b2: e82906dbff CALL 0x004679e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004679e0u,7041975u); flags=s.arithmetic_flags;
  }
  L006b73b7: { // 0x6b73b7: eb02 JMP 0x006b73bb
    goto L006b73bb;
  }
  L006b73b9: { // 0x6b73b9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b73bb: { // 0x6b73bb: 898630020000 MOV dword ptr [ESI + 0x230],EAX
    m.w32((s.si+0x00000230u), s.ax);
  }
  L006b73c1: { // 0x6b73c1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b73c3: { // 0x6b73c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73c5: { // 0x6b73c5: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7041992u); flags=s.arithmetic_flags;
  }
  L006b73c8: { // 0x6b73c8: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006b73cb: { // 0x6b73cb: 744f JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73cd: { // 0x6b73cd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b73cf: { // 0x6b73cf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b73d1: { // 0x6b73d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73d3: { // 0x6b73d3: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042009u); flags=s.arithmetic_flags;
  }
  L006b73d9: { // 0x6b73d9: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b73dc: { // 0x6b73dc: 743e JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73de: { // 0x6b73de: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b73e0: { // 0x6b73e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b73e2: { // 0x6b73e2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73e4: { // 0x6b73e4: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7042026u); flags=s.arithmetic_flags;
  }
  L006b73ea: { // 0x6b73ea: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b73ec: { // 0x6b73ec: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  L006b73f2: { // 0x6b73f2: 8a8256010000 MOV AL,byte ptr [EDX + 0x156]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000156u)));
  }
  L006b73f8: { // 0x6b73f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b73fa: { // 0x6b73fa: 7420 JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73fc: { // 0x6b73fc: 6a58 PUSH 0x58
    f.push(m,0x00000058u);
  }
  L006b73fe: { // 0x6b73fe: e854650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7042051u); flags=s.arithmetic_flags;
  }
  L006b7403: { // 0x6b7403: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7406: { // 0x6b7406: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b7408: { // 0x6b7408: 740a JZ 0x006b7414
    if(integer::condition("JZ",flags)) goto L006b7414;
  }
  L006b740a: { // 0x6b740a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b740b: { // 0x6b740b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b740d: { // 0x6b740d: e80e6af4ff CALL 0x005fde20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fde20u,7042066u); flags=s.arithmetic_flags;
  }
  L006b7412: { // 0x6b7412: eb02 JMP 0x006b7416
    goto L006b7416;
  }
  L006b7414: { // 0x6b7414: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b7416: { // 0x6b7416: 898688050000 MOV dword ptr [ESI + 0x588],EAX
    m.w32((s.si+0x00000588u), s.ax);
  }
  L006b741c: { // 0x6b741c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b741e: { // 0x6b741e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7420: { // 0x6b7420: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7422: { // 0x6b7422: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7042088u); flags=s.arithmetic_flags;
  }
  L006b7428: { // 0x6b7428: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b742b: { // 0x6b742b: 745b JZ 0x006b7488
    if(integer::condition("JZ",flags)) goto L006b7488;
  }
  L006b742d: { // 0x6b742d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b742f: { // 0x6b742f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7431: { // 0x6b7431: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7433: { // 0x6b7433: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042105u); flags=s.arithmetic_flags;
  }
  L006b7439: { // 0x6b7439: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b743b: { // 0x6b743b: 8b88ac000000 MOV ECX,dword ptr [EAX + 0xac]
    s.cx = m.r32((s.ax+0x000000acu));
  }
  L006b7441: { // 0x6b7441: 8a8157010000 MOV AL,byte ptr [ECX + 0x157]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000157u)));
  }
  L006b7447: { // 0x6b7447: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b7449: { // 0x6b7449: 743d JZ 0x006b7488
    if(integer::condition("JZ",flags)) goto L006b7488;
  }
  L006b744b: { // 0x6b744b: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  L006b744d: { // 0x6b744d: e805650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7042130u); flags=s.arithmetic_flags;
  }
  L006b7452: { // 0x6b7452: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7455: { // 0x6b7455: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b7457: { // 0x6b7457: 740a JZ 0x006b7463
    if(integer::condition("JZ",flags)) goto L006b7463;
  }
  L006b7459: { // 0x6b7459: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b745a: { // 0x6b745a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b745c: { // 0x6b745c: e86fff0100 CALL 0x006d73d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d73d0u,7042145u); flags=s.arithmetic_flags;
  }
  L006b7461: { // 0x6b7461: eb02 JMP 0x006b7465
    goto L006b7465;
  }
  L006b7463: { // 0x6b7463: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b7465: { // 0x6b7465: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b7467: { // 0x6b7467: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7469: { // 0x6b7469: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b746b: { // 0x6b746b: 898608020000 MOV dword ptr [ESI + 0x208],EAX
    m.w32((s.si+0x00000208u), s.ax);
  }
  L006b7471: { // 0x6b7471: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042167u); flags=s.arithmetic_flags;
  }
  L006b7477: { // 0x6b7477: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b7479: { // 0x6b7479: 8b8e08020000 MOV ECX,dword ptr [ESI + 0x208]
    s.cx = m.r32((s.si+0x00000208u));
  }
  L006b747f: { // 0x6b747f: 8b90a4000000 MOV EDX,dword ptr [EAX + 0xa4]
    s.dx = m.r32((s.ax+0x000000a4u));
  }
  L006b7485: { // 0x6b7485: 89514c MOV dword ptr [ECX + 0x4c],EDX
    m.w32((s.cx+0x0000004cu), s.dx);
  }
  L006b7488: { // 0x6b7488: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b748a: { // 0x6b748a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b748c: { // 0x6b748c: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7042194u); flags=s.arithmetic_flags;
  }
  L006b7492: { // 0x6b7492: 8a88f70a0000 MOV CL,byte ptr [EAX + 0xaf7]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af7u)));
  }
  L006b7498: { // 0x6b7498: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b749a: { // 0x6b749a: 7456 JZ 0x006b74f2
    if(integer::condition("JZ",flags)) goto L006b74f2;
  }
  L006b749c: { // 0x6b749c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b749e: { // 0x6b749e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b74a0: { // 0x6b74a0: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7042214u); flags=s.arithmetic_flags;
  }
  L006b74a6: { // 0x6b74a6: 8a88f80a0000 MOV CL,byte ptr [EAX + 0xaf8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af8u)));
  }
  L006b74ac: { // 0x6b74ac: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b74ae: { // 0x6b74ae: 7442 JZ 0x006b74f2
    if(integer::condition("JZ",flags)) goto L006b74f2;
  }
  L006b74b0: { // 0x6b74b0: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006b74b6: { // 0x6b74b6: c6867001000001 MOV byte ptr [ESI + 0x170],0x1
    m.w8((s.si+0x00000170u), 0x00000001u);
  }
  L006b74bd: { // 0x6b74bd: 898610040000 MOV dword ptr [ESI + 0x410],EAX
    m.w32((s.si+0x00000410u), s.ax);
  }
  L006b74c3: { // 0x6b74c3: 8b8830010000 MOV ECX,dword ptr [EAX + 0x130]
    s.cx = m.r32((s.ax+0x00000130u));
  }
  L006b74c9: { // 0x6b74c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b74cb: { // 0x6b74cb: 7513 JNZ 0x006b74e0
    if(integer::condition("JNZ",flags)) goto L006b74e0;
  }
  L006b74cd: { // 0x6b74cd: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006b74d2: { // 0x6b74d2: 8b886c0b0000 MOV ECX,dword ptr [EAX + 0xb6c]
    s.cx = m.r32((s.ax+0x00000b6cu));
  }
  L006b74d8: { // 0x6b74d8: 898e0c040000 MOV dword ptr [ESI + 0x40c],ECX
    m.w32((s.si+0x0000040cu), s.cx);
  }
  L006b74de: { // 0x6b74de: eb12 JMP 0x006b74f2
    goto L006b74f2;
  }
  L006b74e0: { // 0x6b74e0: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L006b74e6: { // 0x6b74e6: 8b82700b0000 MOV EAX,dword ptr [EDX + 0xb70]
    s.ax = m.r32((s.dx+0x00000b70u));
  }
  L006b74ec: { // 0x6b74ec: 89860c040000 MOV dword ptr [ESI + 0x40c],EAX
    m.w32((s.si+0x0000040cu), s.ax);
  }
  L006b74f2: { // 0x6b74f2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b74f4: { // 0x6b74f4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b74f6: { // 0x6b74f6: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7042300u); flags=s.arithmetic_flags;
  }
  L006b74fc: { // 0x6b74fc: 8b88b00a0000 MOV ECX,dword ptr [EAX + 0xab0]
    s.cx = m.r32((s.ax+0x00000ab0u));
  }
  L006b7502: { // 0x6b7502: 05b00a0000 ADD EAX,0xab0
    s.ax = integer::add(s.ax,0x00000ab0u,32,flags);
  }
  L006b7507: { // 0x6b7507: 898e30030000 MOV dword ptr [ESI + 0x330],ECX
    m.w32((s.si+0x00000330u), s.cx);
  }
  L006b750d: { // 0x6b750d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7510: { // 0x6b7510: 899634030000 MOV dword ptr [ESI + 0x334],EDX
    m.w32((s.si+0x00000334u), s.dx);
  }
  L006b7516: { // 0x6b7516: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006b7519: { // 0x6b7519: 898e38030000 MOV dword ptr [ESI + 0x338],ECX
    m.w32((s.si+0x00000338u), s.cx);
  }
  L006b751f: { // 0x6b751f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006b7522: { // 0x6b7522: 89963c030000 MOV dword ptr [ESI + 0x33c],EDX
    m.w32((s.si+0x0000033cu), s.dx);
  }
  L006b7528: { // 0x6b7528: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b752a: { // 0x6b752a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b752c: { // 0x6b752c: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7042354u); flags=s.arithmetic_flags;
  }
  L006b7532: { // 0x6b7532: 8b88c40a0000 MOV ECX,dword ptr [EAX + 0xac4]
    s.cx = m.r32((s.ax+0x00000ac4u));
  }
  L006b7538: { // 0x6b7538: 05c40a0000 ADD EAX,0xac4
    s.ax = integer::add(s.ax,0x00000ac4u,32,flags);
  }
  L006b753d: { // 0x6b753d: 898e50030000 MOV dword ptr [ESI + 0x350],ECX
    m.w32((s.si+0x00000350u), s.cx);
  }
  L006b7543: { // 0x6b7543: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7546: { // 0x6b7546: 899654030000 MOV dword ptr [ESI + 0x354],EDX
    m.w32((s.si+0x00000354u), s.dx);
  }
  L006b754c: { // 0x6b754c: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006b754f: { // 0x6b754f: 898e58030000 MOV dword ptr [ESI + 0x358],ECX
    m.w32((s.si+0x00000358u), s.cx);
  }
  L006b7555: { // 0x6b7555: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006b7558: { // 0x6b7558: 89965c030000 MOV dword ptr [ESI + 0x35c],EDX
    m.w32((s.si+0x0000035cu), s.dx);
  }
  L006b755e: { // 0x6b755e: c786ec03000001000000 MOV dword ptr [ESI + 0x3ec],0x1
    m.w32((s.si+0x000003ecu), 0x00000001u);
  }
  L006b7568: { // 0x6b7568: c786f003000000000000 MOV dword ptr [ESI + 0x3f0],0x0
    m.w32((s.si+0x000003f0u), 0x00000000u);
  }
  L006b7572: { // 0x6b7572: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b7573: { // 0x6b7573: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // Original JMP [EAX+84]: transfer same call frame.
    if(m.r32(s.ax+0x84u)!=0x00505da0u)throw std::domain_error("Block204 foreign tailgetter");
    s.arithmetic_flags=flags;f_00105da0(m,s,f,op);return;
  }
}
void f_00105da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00505da0: { // 0x505da0: 8b81a8050000 MOV EAX, dword ptr [ECX + 0x5a8]
    s.ax = m.r32((s.cx+0x000005a8u));
  }
  L00505da6: { // 0x505da6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00108c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00508c50: { // 0x508c50: b80f000000 MOV EAX, 0xf
    s.ax = 0x0000000fu;
  }
  L00508c55: { // 0x508c55: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdab0: { // 0x6cdab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdab1: { // 0x6cdab1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdab2: { // 0x6cdab2: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006cdab6: { // 0x6cdab6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdab8: { // 0x6cdab8: 83ffff CMP EDI, -0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L006cdabb: { // 0x6cdabb: 7507 JNZ 0x6cdac4
    if(integer::condition("JNZ",flags)) goto L006cdac4;
  }
  L006cdabd: { // 0x6cdabd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdabe: { // 0x6cdabe: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdac0: { // 0x6cdac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdac1: { // 0x6cdac1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006cdac4: { // 0x6cdac4: 8d8e18010000 LEA ECX, [ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L006cdaca: { // 0x6cdaca: e811a50300 CALL 0x707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7133903u); flags=s.arithmetic_flags;
  }
  L006cdacf: { // 0x6cdacf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdad1: { // 0x6cdad1: 741b JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdad3: { // 0x6cdad3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdad5: { // 0x6cdad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdad6: { // 0x6cdad6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdad8: { // 0x6cdad8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133918u); flags=s.arithmetic_flags;
  }
  L006cdade: { // 0x6cdade: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdae0: { // 0x6cdae0: e86b700000 CALL 0x6d4b50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b50u,7133925u); flags=s.arithmetic_flags;
  }
  L006cdae5: { // 0x6cdae5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cdae7: { // 0x6cdae7: 7405 JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdae9: { // 0x6cdae9: 833800 CMP dword ptr [EAX], 0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006cdaec: { // 0x6cdaec: 7512 JNZ 0x6cdb00
    if(integer::condition("JNZ",flags)) goto L006cdb00;
  }
  L006cdaee: { // 0x6cdaee: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdaf0: { // 0x6cdaf0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdaf1: { // 0x6cdaf1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdaf3: { // 0x6cdaf3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7133945u); flags=s.arithmetic_flags;
  }
  L006cdaf9: { // 0x6cdaf9: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdafb: { // 0x6cdafb: e830700000 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,7133952u); flags=s.arithmetic_flags;
  }
  L006cdb00: { // 0x6cdb00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdb01: { // 0x6cdb01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb02: { // 0x6cdb02: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x00707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX,[EAX*0x8 + 0x0]
    s.dx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX,[ECX + EDX*0x4 + 0x74c]
    s.ax = (s.cx+(s.dx * 0x00000004u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7041696u:f_002b72a0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 5266848u:f_00105da0(m,s,child,{});break;
case 5278800u:f_00108c50(m,s,child,{});break;
case 7133872u:f_002cdab0(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
default:throw std::domain_error("recovery204 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004fedb0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004fedb0: { // 0x4fedb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004fedb1: { // 0x4fedb1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004fedb2: { // 0x4fedb2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004fedb4: { // 0x4fedb4: e8e7841b00 CALL 0x006b72a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b72a0u,5238201u); flags=s.arithmetic_flags;
  }
  L004fedb9: { // 0x4fedb9: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004fedbf: { // 0x4fedbf: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004fedc1: { // 0x4fedc1: 7406 JZ 0x004fedc9
    if(integer::condition("JZ",flags)) goto L004fedc9;
  }
  L004fedc3: { // 0x4fedc3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004fedc4: { // 0x4fedc4: e8c7b0feff CALL 0x004e9e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e9e90u,5238217u); flags=s.arithmetic_flags;
  }
  L004fedc9: { // 0x4fedc9: 8bbea8050000 MOV EDI,dword ptr [ESI + 0x5a8]
    s.di = m.r32((s.si+0x000005a8u));
  }
  L004fedcf: { // 0x4fedcf: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004fedd1: { // 0x4fedd1: 0f84a5000000 JZ 0x004fee7c
    if(integer::condition("JZ",flags)) goto L004fee7c;
  }
  L004fedd7: { // 0x4fedd7: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L004feddd: { // 0x4feddd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004feddf: { // 0x4feddf: 742f JZ 0x004fee10
    if(integer::condition("JZ",flags)) goto L004fee10;
  }
  L004fede1: { // 0x4fede1: 8b4034 MOV EAX,dword ptr [EAX + 0x34]
    s.ax = m.r32((s.ax+0x00000034u));
  }
  L004fede4: { // 0x4fede4: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004fede6: { // 0x4fede6: 054c010000 ADD EAX,0x14c
    s.ax = integer::add(s.ax,0x0000014cu,32,flags);
  }
  L004fedeb: { // 0x4fedeb: 8b5010 MOV EDX,dword ptr [EAX + 0x10]
    s.dx = m.r32((s.ax+0x00000010u));
  }
  L004fedee: { // 0x4fedee: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004fedf0: { // 0x4fedf0: 7e1e JLE 0x004fee10
    if(integer::condition("JLE",flags)) goto L004fee10;
  }
  L004fedf2: { // 0x4fedf2: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004fedf5: { // 0x4fedf5: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L004fedf7: { // 0x4fedf7: 740a JZ 0x004fee03
    if(integer::condition("JZ",flags)) goto L004fee03;
  }
  L004fedf9: { // 0x4fedf9: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004fedfa: { // 0x4fedfa: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L004fedfd: { // 0x4fedfd: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004fedff: { // 0x4fedff: 7cf4 JL 0x004fedf5
    if(integer::condition("JL",flags)) goto L004fedf5;
  }
  L004fee01: { // 0x4fee01: eb0d JMP 0x004fee10
    goto L004fee10;
  }
  L004fee03: { // 0x4fee03: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004fee05: { // 0x4fee05: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L004fee0b: { // 0x4fee0b: e8d0922000 CALL 0x007080e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007080e0u,5238288u); flags=s.arithmetic_flags;
  }
  L004fee10: { // 0x4fee10: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L004fee16: { // 0x4fee16: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004fee18: { // 0x4fee18: 7427 JZ 0x004fee41
    if(integer::condition("JZ",flags)) goto L004fee41;
  }
  L004fee1a: { // 0x4fee1a: 8a8806020000 MOV CL,byte ptr [EAX + 0x206]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000206u)));
  }
  L004fee20: { // 0x4fee20: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004fee22: { // 0x4fee22: 741d JZ 0x004fee41
    if(integer::condition("JZ",flags)) goto L004fee41;
  }
  L004fee24: { // 0x4fee24: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  L004fee2a: { // 0x4fee2a: 8a889a0a0000 MOV CL,byte ptr [EAX + 0xa9a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000a9au)));
  }
  L004fee30: { // 0x4fee30: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004fee32: { // 0x4fee32: 740d JZ 0x004fee41
    if(integer::condition("JZ",flags)) goto L004fee41;
  }
  L004fee34: { // 0x4fee34: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004fee36: { // 0x4fee36: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L004fee3c: { // 0x4fee3c: e89f922000 CALL 0x007080e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007080e0u,5238337u); flags=s.arithmetic_flags;
  }
  L004fee41: { // 0x4fee41: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  L004fee47: { // 0x4fee47: 8b88a0000000 MOV ECX,dword ptr [EAX + 0xa0]
    s.cx = m.r32((s.ax+0x000000a0u));
  }
  L004fee4d: { // 0x4fee4d: 894e6c MOV dword ptr [ESI + 0x6c],ECX
    m.w32((s.si+0x0000006cu), s.cx);
  }
  L004fee50: { // 0x4fee50: 8b90a0000000 MOV EDX,dword ptr [EAX + 0xa0]
    s.dx = m.r32((s.ax+0x000000a0u));
  }
  L004fee56: { // 0x4fee56: 895670 MOV dword ptr [ESI + 0x70],EDX
    m.w32((s.si+0x00000070u), s.dx);
  }
  L004fee59: { // 0x4fee59: 8b88a8050000 MOV ECX,dword ptr [EAX + 0x5a8]
    s.cx = m.r32((s.ax+0x000005a8u));
  }
  L004fee5f: { // 0x4fee5f: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004fee62: { // 0x4fee62: 7506 JNZ 0x004fee6a
    if(integer::condition("JNZ",flags)) goto L004fee6a;
  }
  L004fee64: { // 0x4fee64: 8b88ac050000 MOV ECX,dword ptr [EAX + 0x5ac]
    s.cx = m.r32((s.ax+0x000005acu));
  }
  L004fee6a: { // 0x4fee6a: 898e54020000 MOV dword ptr [ESI + 0x254],ECX
    m.w32((s.si+0x00000254u), s.cx);
  }
  L004fee70: { // 0x4fee70: 8a90dc0a0000 MOV DL,byte ptr [EAX + 0xadc]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000adcu)));
  }
  L004fee76: { // 0x4fee76: 88962a030000 MOV byte ptr [ESI + 0x32a],DL
    m.w8((s.si+0x0000032au), (s.dx & 0xffu));
  }
  L004fee7c: { // 0x4fee7c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004fee7d: { // 0x4fee7d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004fee7e: { // 0x4fee7e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
