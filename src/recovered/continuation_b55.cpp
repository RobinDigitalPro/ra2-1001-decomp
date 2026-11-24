#include "continuation_b55_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::continuation_b55 {
namespace {
void f_0008e140(Memory&,State&,Frame&,const Operations&);
void f_0008e140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x48e140: 81ece0020000 SUB ESP,0x2e0
    f.sp = integer::sub(f.sp,0x000002e0u,32,flags);
  }
  { // 0x48e146: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x48e147: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x48e149: 8a456c MOV AL,byte ptr [EBP + 0x6c]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000006cu)));
  }
  { // 0x48e14c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x48e14e: 750a JNZ 0x0048e15a
    if(integer::condition("JNZ",flags)) goto L0048e15a;
  }
  { // 0x48e150: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x48e152: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x48e153: 81c4e0020000 ADD ESP,0x2e0
    f.sp = integer::add(f.sp,0x000002e0u,32,flags);
  }
  { // 0x48e159: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0048e15a: { // 0x48e15a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x48e15b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x48e15c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x48e15d: 686c007c00 PUSH 0x7c006c
    f.push(m,0x007c006cu);
  }
  { // 0x48e162: e88987f7ff CALL 0x004068f0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x004068f0u;
    invoke_external(m,s,f,op,0u,target,0x0048e167u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e167: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x48e16a: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  { // 0x48e16c: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x48e170: e87bfeffff CALL 0x0048dff0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0048dff0u;
    invoke_external(m,s,f,op,1u,target,0x0048e175u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e175: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  { // 0x48e177: 8d8c2480000000 LEA ECX,[ESP + 0x80]
    s.cx = (f.sp+0x00000080u);
  }
  { // 0x48e17e: e86dfeffff CALL 0x0048dff0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0048dff0u;
    invoke_external(m,s,f,op,2u,target,0x0048e183u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e183: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x48e187: e8340c2600 CALL 0x006eedc0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006eedc0u;
    invoke_external(m,s,f,op,3u,target,0x0048e18cu);
    flags=s.arithmetic_flags;
  }
  { // 0x48e18c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x48e18e: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0048e190: { // 0x48e190: 8a11 MOV DL,byte ptr [ECX]
    s.dx = with_al(s.dx, m.r8((s.cx)));
  }
  { // 0x48e192: 8a1e MOV BL,byte ptr [ESI]
    s.bx = with_al(s.bx, m.r8((s.si)));
  }
  { // 0x48e194: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  { // 0x48e196: 3ad3 CMP DL,BL
    (void)integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x48e198: 751e JNZ 0x0048e1b8
    if(integer::condition("JNZ",flags)) goto L0048e1b8;
  }
  { // 0x48e19a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x48e19c: 7416 JZ 0x0048e1b4
    if(integer::condition("JZ",flags)) goto L0048e1b4;
  }
  { // 0x48e19e: 8a5101 MOV DL,byte ptr [ECX + 0x1]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000001u)));
  }
  { // 0x48e1a1: 8a5e01 MOV BL,byte ptr [ESI + 0x1]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000001u)));
  }
  { // 0x48e1a4: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  { // 0x48e1a6: 3ad3 CMP DL,BL
    (void)integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x48e1a8: 750e JNZ 0x0048e1b8
    if(integer::condition("JNZ",flags)) goto L0048e1b8;
  }
  { // 0x48e1aa: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  { // 0x48e1ad: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x48e1b0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x48e1b2: 75dc JNZ 0x0048e190
    if(integer::condition("JNZ",flags)) goto L0048e190;
  }
  L0048e1b4: { // 0x48e1b4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x48e1b6: eb05 JMP 0x0048e1bd
    goto L0048e1bd;
  }
  L0048e1b8: { // 0x48e1b8: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x48e1ba: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L0048e1bd: { // 0x48e1bd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x48e1bf: 0f8588000000 JNZ 0x0048e24d
    if(integer::condition("JNZ",flags)) goto L0048e24d;
  }
  { // 0x48e1c5: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x48e1c9: e8f20b2600 CALL 0x006eedc0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006eedc0u;
    invoke_external(m,s,f,op,4u,target,0x0048e1ceu);
    flags=s.arithmetic_flags;
  }
  { // 0x48e1ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x48e1cf: 6858007c00 PUSH 0x7c0058
    f.push(m,0x007c0058u);
  }
  { // 0x48e1d4: e81787f7ff CALL 0x004068f0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x004068f0u;
    invoke_external(m,s,f,op,5u,target,0x0048e1d9u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e1d9: 8b8c24c8000000 MOV ECX,dword ptr [ESP + 0xc8]
    s.cx = m.r32((f.sp+0x000000c8u));
  }
  { // 0x48e1e0: 8b554c MOV EDX,dword ptr [EBP + 0x4c]
    s.dx = m.r32((s.bp+0x0000004cu));
  }
  { // 0x48e1e3: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  { // 0x48e1e7: 8b7548 MOV ESI,dword ptr [EBP + 0x48]
    s.si = m.r32((s.bp+0x00000048u));
  }
  { // 0x48e1ea: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e1ec: 8b5d54 MOV EBX,dword ptr [EBP + 0x54]
    s.bx = m.r32((s.bp+0x00000054u));
  }
  { // 0x48e1ef: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  { // 0x48e1f3: 8b7d58 MOV EDI,dword ptr [EBP + 0x58]
    s.di = m.r32((s.bp+0x00000058u));
  }
  { // 0x48e1f6: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x48e1f8: 8b4550 MOV EAX,dword ptr [EBP + 0x50]
    s.ax = m.r32((s.bp+0x00000050u));
  }
  { // 0x48e1fb: 89554c MOV dword ptr [EBP + 0x4c],EDX
    m.w32((s.bp+0x0000004cu), s.dx);
  }
  { // 0x48e1fe: 8b542468 MOV EDX,dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  { // 0x48e202: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x48e204: 8b9424b8000000 MOV EDX,dword ptr [ESP + 0xb8]
    s.dx = m.r32((f.sp+0x000000b8u));
  }
  { // 0x48e20b: 894550 MOV dword ptr [EBP + 0x50],EAX
    m.w32((s.bp+0x00000050u), s.ax);
  }
  { // 0x48e20e: 8b8424d8000000 MOV EAX,dword ptr [ESP + 0xd8]
    s.ax = m.r32((f.sp+0x000000d8u));
  }
  { // 0x48e215: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  { // 0x48e217: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  { // 0x48e21b: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  { // 0x48e21d: 8b4d60 MOV ECX,dword ptr [EBP + 0x60]
    s.cx = m.r32((s.bp+0x00000060u));
  }
  { // 0x48e220: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x48e222: 8b4564 MOV EAX,dword ptr [EBP + 0x64]
    s.ax = m.r32((s.bp+0x00000064u));
  }
  { // 0x48e225: 897548 MOV dword ptr [EBP + 0x48],ESI
    m.w32((s.bp+0x00000048u), s.si);
  }
  { // 0x48e228: 8b755c MOV ESI,dword ptr [EBP + 0x5c]
    s.si = m.r32((s.bp+0x0000005cu));
  }
  { // 0x48e22b: 894d60 MOV dword ptr [EBP + 0x60],ECX
    m.w32((s.bp+0x00000060u), s.cx);
  }
  { // 0x48e22e: 8b8c24e8000000 MOV ECX,dword ptr [ESP + 0xe8]
    s.cx = m.r32((f.sp+0x000000e8u));
  }
  { // 0x48e235: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x48e238: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  { // 0x48e23a: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x48e23c: 895d54 MOV dword ptr [EBP + 0x54],EBX
    m.w32((s.bp+0x00000054u), s.bx);
  }
  { // 0x48e23f: 897d58 MOV dword ptr [EBP + 0x58],EDI
    m.w32((s.bp+0x00000058u), s.di);
  }
  { // 0x48e242: 89755c MOV dword ptr [EBP + 0x5c],ESI
    m.w32((s.bp+0x0000005cu), s.si);
  }
  { // 0x48e245: 894564 MOV dword ptr [EBP + 0x64],EAX
    m.w32((s.bp+0x00000064u), s.ax);
  }
  { // 0x48e248: e986000000 JMP 0x0048e2d3
    goto L0048e2d3;
  }
  L0048e24d: { // 0x48e24d: 8d8c2480000000 LEA ECX,[ESP + 0x80]
    s.cx = (f.sp+0x00000080u);
  }
  { // 0x48e254: e8670b2600 CALL 0x006eedc0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006eedc0u;
    invoke_external(m,s,f,op,6u,target,0x0048e259u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e259: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x48e25a: 683c007c00 PUSH 0x7c003c
    f.push(m,0x007c003cu);
  }
  { // 0x48e25f: e88c86f7ff CALL 0x004068f0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x004068f0u;
    invoke_external(m,s,f,op,7u,target,0x0048e264u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e264: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  { // 0x48e268: 8b7d4c MOV EDI,dword ptr [EBP + 0x4c]
    s.di = m.r32((s.bp+0x0000004cu));
  }
  { // 0x48e26b: 8b4c2468 MOV ECX,dword ptr [ESP + 0x68]
    s.cx = m.r32((f.sp+0x00000068u));
  }
  { // 0x48e26f: 8b8424c8000000 MOV EAX,dword ptr [ESP + 0xc8]
    s.ax = m.r32((f.sp+0x000000c8u));
  }
  { // 0x48e276: 8b7548 MOV ESI,dword ptr [EBP + 0x48]
    s.si = m.r32((s.bp+0x00000048u));
  }
  { // 0x48e279: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  { // 0x48e27b: 8b5554 MOV EDX,dword ptr [EBP + 0x54]
    s.dx = m.r32((s.bp+0x00000054u));
  }
  { // 0x48e27e: 8b5d5c MOV EBX,dword ptr [EBP + 0x5c]
    s.bx = m.r32((s.bp+0x0000005cu));
  }
  { // 0x48e281: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e283: 8b8c24b8000000 MOV ECX,dword ptr [ESP + 0xb8]
    s.cx = m.r32((f.sp+0x000000b8u));
  }
  { // 0x48e28a: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x48e28c: 8b4550 MOV EAX,dword ptr [EBP + 0x50]
    s.ax = m.r32((s.bp+0x00000050u));
  }
  { // 0x48e28f: 895554 MOV dword ptr [EBP + 0x54],EDX
    m.w32((s.bp+0x00000054u), s.dx);
  }
  { // 0x48e292: 8b9424d8000000 MOV EDX,dword ptr [ESP + 0xd8]
    s.dx = m.r32((f.sp+0x000000d8u));
  }
  { // 0x48e299: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x48e29b: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  { // 0x48e29f: 897d4c MOV dword ptr [EBP + 0x4c],EDI
    m.w32((s.bp+0x0000004cu), s.di);
  }
  { // 0x48e2a2: 8b7d58 MOV EDI,dword ptr [EBP + 0x58]
    s.di = m.r32((s.bp+0x00000058u));
  }
  { // 0x48e2a5: 894550 MOV dword ptr [EBP + 0x50],EAX
    m.w32((s.bp+0x00000050u), s.ax);
  }
  { // 0x48e2a8: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  { // 0x48e2ac: 897548 MOV dword ptr [EBP + 0x48],ESI
    m.w32((s.bp+0x00000048u), s.si);
  }
  { // 0x48e2af: 8b7564 MOV ESI,dword ptr [EBP + 0x64]
    s.si = m.r32((s.bp+0x00000064u));
  }
  { // 0x48e2b2: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  { // 0x48e2b4: 8b8424e8000000 MOV EAX,dword ptr [ESP + 0xe8]
    s.ax = m.r32((f.sp+0x000000e8u));
  }
  { // 0x48e2bb: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  { // 0x48e2bd: 8b4d60 MOV ECX,dword ptr [EBP + 0x60]
    s.cx = m.r32((s.bp+0x00000060u));
  }
  { // 0x48e2c0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x48e2c3: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  { // 0x48e2c5: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x48e2c7: 895d5c MOV dword ptr [EBP + 0x5c],EBX
    m.w32((s.bp+0x0000005cu), s.bx);
  }
  { // 0x48e2ca: 897d58 MOV dword ptr [EBP + 0x58],EDI
    m.w32((s.bp+0x00000058u), s.di);
  }
  { // 0x48e2cd: 897564 MOV dword ptr [EBP + 0x64],ESI
    m.w32((s.bp+0x00000064u), s.si);
  }
  { // 0x48e2d0: 894d60 MOV dword ptr [EBP + 0x60],ECX
    m.w32((s.bp+0x00000060u), s.cx);
  }
  L0048e2d3: { // 0x48e2d3: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x48e2d9: 8b8114060000 MOV EAX,dword ptr [ECX + 0x614]
    s.ax = m.r32((s.cx+0x00000614u));
  }
  { // 0x48e2df: 8bb11c060000 MOV ESI,dword ptr [ECX + 0x61c]
    s.si = m.r32((s.cx+0x0000061cu));
  }
  { // 0x48e2e5: 8db914060000 LEA EDI,[ECX + 0x614]
    s.di = (s.cx+0x00000614u);
  }
  { // 0x48e2eb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x48e2ee: 740c JZ 0x0048e2fc
    if(integer::condition("JZ",flags)) goto L0048e2fc;
  }
  { // 0x48e2f0: 8d4f04 LEA ECX,[EDI + 0x4]
    s.cx = (s.di+0x00000004u);
  }
  { // 0x48e2f3: e8d8172000 CALL 0x0068fad0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0068fad0u;
    invoke_external(m,s,f,op,8u,target,0x0048e2f8u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e2f8: 2b07 SUB EAX,dword ptr [EDI]
    s.ax = integer::sub(s.ax,m.r32((s.di)),32,flags);
  }
  { // 0x48e2fa: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0048e2fc: { // 0x48e2fc: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  { // 0x48e301: f7ee IMUL ESI
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.si,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x48e303: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x48e305: 8d8424f0010000 LEA EAX,[ESP + 0x1f0]
    s.ax = (f.sp+0x000001f0u);
  }
  { // 0x48e30c: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  { // 0x48e30e: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x48e311: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x48e313: c1ea1f SHR EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x48e316: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x48e318: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x48e31a: 747c JZ 0x0048e398
    if(integer::condition("JZ",flags)) goto L0048e398;
  }
  { // 0x48e31c: b8c5b3a291 MOV EAX,0x91a2b3c5
    s.ax = 0x91a2b3c5u;
  }
  { // 0x48e321: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x48e323: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e325: c1fa0b SAR EDX,0xb
    s.dx = integer::shift(s.dx,0x0000000bu,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x48e328: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x48e32a: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x48e32d: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x48e32f: 83fa63 CMP EDX,0x63
    (void)integer::sub(s.dx,0x00000063u,32,flags);
  }
  { // 0x48e332: 7e05 JLE 0x0048e339
    if(integer::condition("JLE",flags)) goto L0048e339;
  }
  { // 0x48e334: b93f7e0500 MOV ECX,0x57e3f
    s.cx = 0x00057e3fu;
  }
  L0048e339: { // 0x48e339: b8c5b3a291 MOV EAX,0x91a2b3c5
    s.ax = 0x91a2b3c5u;
  }
  { // 0x48e33e: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x48e340: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e342: c1fa0b SAR EDX,0xb
    s.dx = integer::shift(s.dx,0x0000000bu,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x48e345: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x48e347: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x48e34a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x48e34c: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x48e34e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x48e350: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x48e352: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x48e355: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x48e357: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x48e35a: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x48e35d: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  { // 0x48e362: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x48e365: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x48e367: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x48e369: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e36b: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x48e36e: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x48e370: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x48e373: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x48e375: 8d0452 LEA EAX,[EDX + EDX*0x2]
    s.ax = (s.dx+(s.dx * 0x00000002u));
  }
  { // 0x48e378: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x48e37b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x48e37e: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x48e380: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x48e381: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x48e382: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x48e383: 8d8c24fc010000 LEA ECX,[ESP + 0x1fc]
    s.cx = (f.sp+0x000001fcu);
  }
  { // 0x48e38a: 682c007c00 PUSH 0x7c002c
    f.push(m,0x007c002cu);
  }
  { // 0x48e38f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x48e390: e89ff62d00 CALL 0x0076da34
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0076da34u;
    invoke_external(m,s,f,op,9u,target,0x0048e395u);
    flags=s.arithmetic_flags;
  }
  { // 0x48e395: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0048e398: { // 0x48e398: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  { // 0x48e39e: 8b8214060000 MOV EAX,dword ptr [EDX + 0x614]
    s.ax = m.r32((s.dx+0x00000614u));
  }
  { // 0x48e3a4: 8bba1c060000 MOV EDI,dword ptr [EDX + 0x61c]
    s.di = m.r32((s.dx+0x0000061cu));
  }
  { // 0x48e3aa: 8db214060000 LEA ESI,[EDX + 0x614]
    s.si = (s.dx+0x00000614u);
  }
  { // 0x48e3b0: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x48e3b3: 740c JZ 0x0048e3c1
    if(integer::condition("JZ",flags)) goto L0048e3c1;
  }
  { // 0x48e3b5: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x48e3b8: e813172000 CALL 0x0068fad0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0068fad0u;
    invoke_external(m,s,f,op,10u,target,0x0048e3bdu);
    flags=s.arithmetic_flags;
  }
  { // 0x48e3bd: 2b06 SUB EAX,dword ptr [ESI]
    s.ax = integer::sub(s.ax,m.r32((s.si)),32,flags);
  }
  { // 0x48e3bf: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0048e3c1: { // 0x48e3c1: 8b7568 MOV ESI,dword ptr [EBP + 0x68]
    s.si = m.r32((s.bp+0x00000068u));
  }
  { // 0x48e3c4: 8d8424f0000000 LEA EAX,[ESP + 0xf0]
    s.ax = (f.sp+0x000000f0u);
  }
  { // 0x48e3cb: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  { // 0x48e3cd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x48e3cf: 897568 MOV dword ptr [EBP + 0x68],ESI
    m.w32((s.bp+0x00000068u), s.si);
  }
  { // 0x48e3d2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x48e3d4: 747c JZ 0x0048e452
    if(integer::condition("JZ",flags)) goto L0048e452;
  }
  { // 0x48e3d6: b8c5b3a291 MOV EAX,0x91a2b3c5
    s.ax = 0x91a2b3c5u;
  }
  { // 0x48e3db: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x48e3dd: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e3df: c1fa0b SAR EDX,0xb
    s.dx = integer::shift(s.dx,0x0000000bu,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x48e3e2: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x48e3e4: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x48e3e7: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x48e3e9: 83fa63 CMP EDX,0x63
    (void)integer::sub(s.dx,0x00000063u,32,flags);
  }
  { // 0x48e3ec: 7e05 JLE 0x0048e3f3
    if(integer::condition("JLE",flags)) goto L0048e3f3;
  }
  { // 0x48e3ee: b93f7e0500 MOV ECX,0x57e3f
    s.cx = 0x00057e3fu;
  }
  L0048e3f3: { // 0x48e3f3: b8c5b3a291 MOV EAX,0x91a2b3c5
    s.ax = 0x91a2b3c5u;
  }
  { // 0x48e3f8: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x48e3fa: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e3fc: c1fa0b SAR EDX,0xb
    s.dx = integer::shift(s.dx,0x0000000bu,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x48e3ff: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x48e401: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x48e404: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x48e406: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x48e408: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x48e40a: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x48e40c: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x48e40f: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x48e411: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x48e414: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x48e417: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  { // 0x48e41c: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x48e41f: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x48e421: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x48e423: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x48e425: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x48e428: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x48e42a: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x48e42d: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x48e42f: 8d0452 LEA EAX,[EDX + EDX*0x2]
    s.ax = (s.dx+(s.dx * 0x00000002u));
  }
  { // 0x48e432: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x48e435: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x48e438: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x48e43a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x48e43b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x48e43c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x48e43d: 8d8c24fc000000 LEA ECX,[ESP + 0xfc]
    s.cx = (f.sp+0x000000fcu);
  }
  { // 0x48e444: 682c007c00 PUSH 0x7c002c
    f.push(m,0x007c002cu);
  }
  { // 0x48e449: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x48e44a: e8e5f52d00 CALL 0x0076da34
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0076da34u;
    invoke_external(m,s,f,op,11u,target,0x0048e44fu);
    flags=s.arithmetic_flags;
  }
  { // 0x48e44f: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0048e452: { // 0x48e452: 8d9424f0000000 LEA EDX,[ESP + 0xf0]
    s.dx = (f.sp+0x000000f0u);
  }
  { // 0x48e459: 8d8424f0010000 LEA EAX,[ESP + 0x1f0]
    s.ax = (f.sp+0x000001f0u);
  }
  { // 0x48e460: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x48e461: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x48e462: 6808007c00 PUSH 0x7c0008
    f.push(m,0x007c0008u);
  }
  { // 0x48e467: e88484f7ff CALL 0x004068f0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x004068f0u;
    invoke_external(m,s,f,op,12u,target,0x0048e46cu);
    flags=s.arithmetic_flags;
  }
  { // 0x48e46c: 8b4538 MOV EAX,dword ptr [EBP + 0x38]
    s.ax = m.r32((s.bp+0x00000038u));
  }
  { // 0x48e46f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x48e472: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x48e473: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x48e474: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x48e475: 894538 MOV dword ptr [EBP + 0x38],EAX
    m.w32((s.bp+0x00000038u), s.ax);
  }
  { // 0x48e478: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x48e479: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x48e47b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x48e47c: 81c4e0020000 ADD ESP,0x2e0
    f.sp = integer::add(f.sp,0x000002e0u,32,flags);
  }
  { // 0x48e482: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,1>& entries_a() {
  static const std::array<Entry,1> entries{{
    {0x8e140u,f_0008e140},
  }}; return entries;
}
} // namespace ra2::recovered::continuation_b55
