#include "recovery_b1708.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1708 {
namespace ix=direct_b33::integer;
namespace {
void outside(U){throw std::domain_error("2C7F40 unsupported selected branch/target");}
void kind_6fee90(Memory& m, State& s, Frame& f) {
    // 0x006fee90: MOV EAX, 1 [b801000000]
    s.ax = 0x1u;
    // 0x006fee95: RET  [c3]
    recovery_b566::finish(m,s,f,0x0u);
}

void ctor_49eac0(Memory& m, State& s, Frame& f) {
    // 0x0049eac0: MOV EDX,dword ptr [ESP + 0x8] [8b542408]
    s.dx = m.r32((f.sp + 0x8u));
    // 0x0049eac4: MOV EAX,ECX [8bc1]
    s.ax = s.cx;
    // 0x0049eac6: MOV ECX,dword ptr [ESP + 0x4] [8b4c2404]
    s.cx = m.r32((f.sp + 0x4u));
    // 0x0049eaca: MOV dword ptr [EAX + 0x4],ECX [894804]
    m.w32((s.ax + 0x4u), s.cx);
    // 0x0049eacd: MOV dword ptr [EAX + 0x8],EDX [895008]
    m.w32((s.ax + 0x8u), s.dx);
    // 0x0049ead0: MOV dword ptr [EAX],0x786020 [c70020607800]
    m.w32((s.ax), 0x786020u);
    // 0x0049ead6: RET 0x8 [c20800]
    recovery_b566::finish(m,s,f,0x8u);
}

void buffer_438140(Memory& m, State& s, Frame& f) {
    // 0x00438140: MOV EAX,dword ptr [ESP + 0x4] [8b442404]
    s.ax = m.r32((f.sp + 0x4u));
    // 0x00438144: PUSH ESI [56]
    f.push(m,s.si);
    // 0x00438145: MOV ESI,ECX [8bf1]
    s.si = s.cx;
    // 0x00438147: MOV ECX,dword ptr [ESP + 0xc] [8b4c240c]
    s.cx = m.r32((f.sp + 0xcu));
    // 0x0043814b: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax & s.ax,32u,s.arithmetic_flags);
    // 0x0043814d: MOV dword ptr [ESI],EAX [8906]
    m.w32((s.si), s.ax);
    // 0x0043814f: MOV dword ptr [ESI + 0x4],ECX [894e04]
    m.w32((s.si + 0x4u), s.cx);
    // 0x00438152: MOV byte ptr [ESI + 0x8],0x0 [c6460800]
    m.w8((s.si + 0x8u), 0x0u);
    // 0x00438156: JNZ 0x0043816b [7513]
    if (!ix::condition("JNZ",s.arithmetic_flags)) outside(0x438156u);
    // 0x0043816b: MOV EAX,ESI [8bc6]
    s.ax = s.si;
    // 0x0043816d: POP ESI [5e]
    s.si = f.pop(m);
    // 0x0043816e: RET 0x8 [c20800]
    recovery_b566::finish(m,s,f,0x8u);
}

void teardown_438290(Memory& m, State& s, Frame& f) {
    // 0x00438290: PUSH ESI [56]
    f.push(m,s.si);
    // 0x00438291: MOV ESI,ECX [8bf1]
    s.si = s.cx;
    // 0x00438293: MOV AL,byte ptr [ESI + 0x8] [8a4608]
    s.ax = (s.ax & 0xffffff00u) | (((m.r8((s.si + 0x8u))) & 0xffu) << 0u);
    // 0x00438296: TEST AL,AL [84c0]
    (void)ix::logical(((s.ax >> 0u) & 0xffu) & ((s.ax >> 0u) & 0xffu),8u,s.arithmetic_flags);
    // 0x00438298: JZ 0x004382a5 [740b]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x438298u);
    // 0x004382a5: MOV dword ptr [ESI],0x0 [c70600000000]
    m.w32((s.si), 0x0u);
    // 0x004382ab: MOV dword ptr [ESI + 0x4],0x0 [c7460400000000]
    m.w32((s.si + 0x4u), 0x0u);
    // 0x004382b2: MOV byte ptr [ESI + 0x8],0x0 [c6460800]
    m.w8((s.si + 0x8u), 0x0u);
    // 0x004382b6: POP ESI [5e]
    s.si = f.pop(m);
    // 0x004382b7: RET [c3]
    recovery_b566::finish(m,s,f,0x0u);
}

void selector_485b40(Memory& m, State& s, Frame& f) {
    // 0x00485b40: PUSH ESI [56]
    f.push(m,s.si);
    // 0x00485b41: MOV ESI,ECX [8bf1]
    s.si = s.cx;
    // 0x00485b43: MOV EAX,dword ptr [ESI + 0x8] [8b4608]
    s.ax = m.r32((s.si + 0x8u));
    // 0x00485b46: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax & s.ax,32u,s.arithmetic_flags);
    // 0x00485b48: JNZ 0x00485b4f [7505]
    if (!ix::condition("JNZ",s.arithmetic_flags)) outside(0x485b48u);
    // 0x00485b4f: MOV EAX,dword ptr [ESP + 0x8] [8b442408]
    s.ax = m.r32((f.sp + 0x8u));
    // 0x00485b53: TEST AL,0x10 [a810]
    (void)ix::logical(((s.ax >> 0u) & 0xffu) & 0x10u,8u,s.arithmetic_flags);
    // 0x00485b55: JZ 0x00485baf [7458]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x485b55u);
    // 0x00485baf: MOV ECX,EAX [8bc8]
    s.cx = s.ax;
    // 0x00485bb1: AND ECX,0x6 [83e106]
    s.cx = ix::logical(s.cx & 0x6u,32u,s.arithmetic_flags);
    // 0x00485bb4: SUB ECX,0x2 [83e902]
    s.cx = ix::sub(s.cx,0x2u,32u,s.arithmetic_flags);
    // 0x00485bb7: JZ 0x00485d6f [0f84b2010000]
    if (ix::condition("JZ",s.arithmetic_flags)) outside(0x485bb7u);
    // 0x00485bbd: SUB ECX,0x2 [83e902]
    s.cx = ix::sub(s.cx,0x2u,32u,s.arithmetic_flags);
    // 0x00485bc0: JZ 0x00485cfa [0f8434010000]
    if (ix::condition("JZ",s.arithmetic_flags)) outside(0x485bc0u);
    // 0x00485bc6: SUB ECX,0x2 [83e902]
    s.cx = ix::sub(s.cx,0x2u,32u,s.arithmetic_flags);
    // 0x00485bc9: JZ 0x00485c85 [0f84b6000000]
    if (ix::condition("JZ",s.arithmetic_flags)) outside(0x485bc9u);
    // 0x00485bcf: TEST AL,0x1 [a801]
    (void)ix::logical(((s.ax >> 0u) & 0xffu) & 0x1u,8u,s.arithmetic_flags);
    // 0x00485bd1: JZ 0x00485bfe [742b]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x485bd1u);
    // 0x00485bfe: TEST AL,0x20 [a820]
    (void)ix::logical(((s.ax >> 0u) & 0xffu) & 0x20u,8u,s.arithmetic_flags);
    // 0x00485c00: JZ 0x00485c2d [742b]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x485c00u);
    // 0x00485c2d: TEST AH,0x40 [f6c440]
    (void)ix::logical(((s.ax >> 8u) & 0xffu) & 0x40u,8u,s.arithmetic_flags);
    // 0x00485c30: JZ 0x00485c4b [7419]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x485c30u);
    // 0x00485c4b: TEST dword ptr [0x007bebac],EAX [8505aceb7b00]
    (void)ix::logical(m.r32((0x7bebacu)) & s.ax,32u,s.arithmetic_flags);
    // 0x00485c51: JZ 0x00485c6c [7419]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x485c51u);
    // 0x00485c6c: TEST AH,0x8 [f6c408]
    (void)ix::logical(((s.ax >> 8u) & 0xffu) & 0x8u,8u,s.arithmetic_flags);
    // 0x00485c6f: JZ 0x00485c7b [740a]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x485c6fu);
    // 0x00485c7b: MOV EAX,dword ptr [ESI + 0xd0] [8b86d0000000]
    s.ax = m.r32((s.si + 0xd0u));
    // 0x00485c81: POP ESI [5e]
    s.si = f.pop(m);
    // 0x00485c82: RET 0x4 [c20400]
    recovery_b566::finish(m,s,f,0x4u);
}

void kind2_4c9610(Memory& m, State& s, Frame& f) {
    // 0x004c9610: PUSH ESI [56]
    f.push(m,s.si);
    // 0x004c9611: MOV ESI,ECX [8bf1]
    s.si = s.cx;
    // 0x004c9613: MOV EAX,dword ptr [ESI + 0x564] [8b8664050000]
    s.ax = m.r32((s.si + 0x564u));
    // 0x004c9619: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax & s.ax,32u,s.arithmetic_flags);
    // 0x004c961b: JZ 0x004c9639 [741c]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x4c961bu);
    // 0x004c9639: MOV EAX,0x2 [b802000000]
    s.ax = 0x2u;
    // 0x004c963e: POP ESI [5e]
    s.si = f.pop(m);
    // 0x004c963f: RET [c3]
    recovery_b566::finish(m,s,f,0x0u);
}
} // namespace

void execute_selected(Memory& m, State& s, Frame& f) {
    require_selected_basis(m,s,f);
    // 0x006c7f40: SUB ESP,0x50 [83ec50]
    f.sp = ix::sub(f.sp,0x50u,32u,s.arithmetic_flags);
    // 0x006c7f43: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c7f44: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x006c7f45: PUSH ESI [56]
    f.push(m,s.si);
    // 0x006c7f46: MOV ESI,dword ptr [ESP + 0x60] [8b742460]
    s.si = m.r32((f.sp + 0x60u));
    // 0x006c7f4a: XOR EBP,EBP [33ed]
    s.bp = ix::logical(s.bp ^ s.bp,32u,s.arithmetic_flags);
    // 0x006c7f4c: XOR EBX,EBX [33db]
    s.bx = ix::logical(s.bx ^ s.bx,32u,s.arithmetic_flags);
    // 0x006c7f4e: MOV BP,word ptr [ESI + 0x6] [668b6e06]
    s.bp = (s.bp & 0xffff0000u) | (((m.r16((s.si + 0x6u))) & 0xffffu) << 0u);
    // 0x006c7f52: MOV BX,word ptr [ESI + 0x4] [668b5e04]
    s.bx = (s.bx & 0xffff0000u) | (((m.r16((s.si + 0x4u))) & 0xffffu) << 0u);
    // 0x006c7f56: MOV EAX,dword ptr [ESI + 0x8] [8b4608]
    s.ax = m.r32((s.si + 0x8u));
    // 0x006c7f59: PUSH EDI [57]
    f.push(m,s.di);
    // 0x006c7f5a: MOV EDI,ECX [8bf9]
    s.di = s.cx;
    // 0x006c7f5c: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x006c7f5d: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c7f5e: LEA ECX,[ESP + 0x48] [8d4c2448]
    s.cx = (f.sp + 0x48u);
    // 0x006c7f62: MOV dword ptr [ESP + 0x6c],EAX [8944246c]
    m.w32((f.sp + 0x6cu), s.ax);
    // 0x006c7f66: CALL 0x0049eac0 [e8556bddff]
    { f.push(m,0x6c7f6bu); Frame child{f.sp,f.sp,0x6c7f6bu}; ctor_49eac0(m,s,child); f.sp=child.sp; }
    // 0x006c7f6b: IMUL EBX,EBP [0fafdd]
    s.bx = ix::imul(s.bx,s.bp,32u,s.arithmetic_flags);
    // 0x006c7f6e: MOV ECX,dword ptr [ESP + 0x64] [8b4c2464]
    s.cx = m.r32((f.sp + 0x64u));
    // 0x006c7f72: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c7f73: PUSH ECX [51]
    f.push(m,s.cx);
    // 0x006c7f74: LEA ECX,[ESP + 0x5c] [8d4c245c]
    s.cx = (f.sp + 0x5cu);
    // 0x006c7f78: MOV dword ptr [ESP + 0x54],0x0 [c744245400000000]
    m.w32((f.sp + 0x54u), 0x0u);
    // 0x006c7f80: MOV dword ptr [ESP + 0x48],0x785f8c [c74424488c5f7800]
    m.w32((f.sp + 0x48u), 0x785f8cu);
    // 0x006c7f88: MOV dword ptr [ESP + 0x58],0x1 [c744245801000000]
    m.w32((f.sp + 0x58u), 0x1u);
    // 0x006c7f90: CALL 0x00438140 [e8ab01d7ff]
    { f.push(m,0x6c7f95u); Frame child{f.sp,f.sp,0x6c7f95u}; buffer_438140(m,s,child); f.sp=child.sp; }
    // 0x006c7f95: MOV EBX,dword ptr [ESP + 0x70] [8b5c2470]
    s.bx = m.r32((f.sp + 0x70u));
    // 0x006c7f99: MOV EDX,dword ptr [EDI] [8b17]
    s.dx = m.r32((s.di));
    // 0x006c7f9b: MOV ECX,EDI [8bcf]
    s.cx = s.di;
    // 0x006c7f9d: MOV dword ptr [ESP + 0x40],0x785ef8 [c7442440f85e7800]
    m.w32((f.sp + 0x40u), 0x785ef8u);
    // 0x006c7fa5: AND EBX,0xffffffef [83e3ef]
    s.bx = ix::logical(s.bx & 0xffffffefu,32u,s.arithmetic_flags);
    // 0x006c7fa8: CALL dword ptr [EDX + 0x2c] [ff522c]
    if (m.r32((s.dx + 0x2cu)) != 0x6fee90u) outside(0x6c7fa8u);
    { f.push(m,0x6c7fabu); Frame child{f.sp,f.sp,0x6c7fabu}; kind_6fee90(m,s,child); f.sp=child.sp; }
    // 0x006c7fab: CMP EAX,0x1 [83f801]
    (void)ix::sub(s.ax,0x1u,32u,s.arithmetic_flags);
    // 0x006c7fae: JNZ 0x006c7fc1 [7511]
    if (ix::condition("JNZ",s.arithmetic_flags)) outside(0x6c7faeu);
    // 0x006c7fb0: MOV AL,byte ptr [EDI + 0x5bb] [8a87bb050000]
    s.ax = (s.ax & 0xffffff00u) | (((m.r8((s.di + 0x5bbu))) & 0xffu) << 0u);
    // 0x006c7fb6: TEST AL,AL [84c0]
    (void)ix::logical(((s.ax >> 0u) & 0xffu) & ((s.ax >> 0u) & 0xffu),8u,s.arithmetic_flags);
    // 0x006c7fb8: JZ 0x006c7fc1 [7407]
    if (ix::condition("JZ",s.arithmetic_flags)) outside(0x6c7fb8u);
    // 0x006c7fba: MOV EAX,[0x00ab8088] [a18880ab00]
    s.ax = m.r32((0xab8088u));
    // 0x006c7fbf: JMP 0x006c7fcb [eb0a]
    // Selected unconditional jump.
    // 0x006c7fcb: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c7fcc: MOV ECX,EAX [8bc8]
    s.cx = s.ax;
    // 0x006c7fce: CALL 0x00485b40 [e86ddbdbff]
    { f.push(m,0x6c7fd3u); Frame child{f.sp,f.sp,0x6c7fd3u}; selector_485b40(m,s,child); f.sp=child.sp; }
    // 0x006c7fd3: TEST BL,0x8 [f6c308]
    (void)ix::logical(((s.bx >> 0u) & 0xffu) & 0x8u,8u,s.arithmetic_flags);
    // 0x006c7fd6: MOV dword ptr [ESP + 0x70],EAX [89442470]
    m.w32((f.sp + 0x70u), s.ax);
    // 0x006c7fda: MOV dword ptr [ESP + 0x64],0x0 [c744246400000000]
    m.w32((f.sp + 0x64u), 0x0u);
    // 0x006c7fe2: JZ 0x006c8009 [7425]
    if (!ix::condition("JZ",s.arithmetic_flags)) outside(0x6c7fe2u);
    // 0x006c8009: MOV EDX,dword ptr [EDI] [8b17]
    s.dx = m.r32((s.di));
    // 0x006c800b: MOV ECX,EDI [8bcf]
    s.cx = s.di;
    // 0x006c800d: CALL dword ptr [EDX + 0x2c] [ff522c]
    if (m.r32((s.dx + 0x2cu)) != 0x6fee90u) outside(0x6c800du);
    { f.push(m,0x6c8010u); Frame child{f.sp,f.sp,0x6c8010u}; kind_6fee90(m,s,child); f.sp=child.sp; }
    // 0x006c8010: MOV ECX,dword ptr [ESP + 0x68] [8b4c2468]
    s.cx = m.r32((f.sp + 0x68u));
    // 0x006c8014: CMP EAX,0x1 [83f801]
    (void)ix::sub(s.ax,0x1u,32u,s.arithmetic_flags);
    // 0x006c8017: JNZ 0x006c8138 [0f851b010000]
    if (ix::condition("JNZ",s.arithmetic_flags)) outside(0x6c8017u);
    // 0x006c801d: MOVSX EAX,word ptr [ESI] [0fbf06]
    s.ax = global_b26::sx16(m.r16((s.si)));
    // 0x006c8020: MOV EDX,dword ptr [ECX] [8b11]
    s.dx = m.r32((s.cx));
    // 0x006c8022: MOV EBP,dword ptr [ECX + 0x4] [8b6904]
    s.bp = m.r32((s.cx + 0x4u));
    // 0x006c8025: MOV EBX,dword ptr [0x00ab7f18] [8b1d187fab00]
    s.bx = m.r32((0xab7f18u));
    // 0x006c802b: ADD EAX,EDX [03c2]
    s.ax = ix::add(s.ax,s.dx,32u,s.arithmetic_flags);
    // 0x006c802d: MOVSX EDX,word ptr [ESI + 0x2] [0fbf5602]
    s.dx = global_b26::sx16(m.r16((s.si + 0x2u)));
    // 0x006c8031: ADD EDX,EBP [03d5]
    s.dx = ix::add(s.dx,s.bp,32u,s.arithmetic_flags);
    // 0x006c8033: XOR EBP,EBP [33ed]
    s.bp = ix::logical(s.bp ^ s.bp,32u,s.arithmetic_flags);
    // 0x006c8035: MOV BP,word ptr [ESI + 0x6] [668b6e06]
    s.bp = (s.bp & 0xffff0000u) | (((m.r16((s.si + 0x6u))) & 0xffffu) << 0u);
    // 0x006c8039: XOR ECX,ECX [33c9]
    s.cx = ix::logical(s.cx ^ s.cx,32u,s.arithmetic_flags);
    // 0x006c803b: MOV CX,word ptr [ESI + 0x4] [668b4e04]
    s.cx = (s.cx & 0xffff0000u) | (((m.r16((s.si + 0x4u))) & 0xffffu) << 0u);
    // 0x006c803f: MOV dword ptr [ESP + 0x24],EDX [89542424]
    m.w32((f.sp + 0x24u), s.dx);
    // 0x006c8043: TEST EBX,EBX [85db]
    (void)ix::logical(s.bx & s.bx,32u,s.arithmetic_flags);
    // 0x006c8045: MOV dword ptr [ESP + 0x2c],EBP [896c242c]
    m.w32((f.sp + 0x2cu), s.bp);
    // 0x006c8049: JLE 0x006c8121 [0f8ed2000000]
    if (ix::condition("JLE",s.arithmetic_flags)) outside(0x6c8049u);
    // 0x006c804f: MOV EBX,dword ptr [0x00ab7f1c] [8b1d1c7fab00]
    s.bx = m.r32((0xab7f1cu));
    // 0x006c8055: TEST EBX,EBX [85db]
    (void)ix::logical(s.bx & s.bx,32u,s.arithmetic_flags);
    // 0x006c8057: JLE 0x006c8121 [0f8ec4000000]
    if (ix::condition("JLE",s.arithmetic_flags)) outside(0x6c8057u);
    // 0x006c805d: TEST ECX,ECX [85c9]
    (void)ix::logical(s.cx & s.cx,32u,s.arithmetic_flags);
    // 0x006c805f: JLE 0x006c810e [0f8ea9000000]
    if (ix::condition("JLE",s.arithmetic_flags)) outside(0x6c805fu);
    // 0x006c8065: TEST EBP,EBP [85ed]
    (void)ix::logical(s.bp & s.bp,32u,s.arithmetic_flags);
    // 0x006c8067: JLE 0x006c810e [0f8ea1000000]
    if (ix::condition("JLE",s.arithmetic_flags)) outside(0x6c8067u);
    // 0x006c806d: MOV EBP,dword ptr [0x00ab7f14] [8b2d147fab00]
    s.bp = m.r32((0xab7f14u));
    // 0x006c8073: MOV EBX,dword ptr [0x00ab7f10] [8b1d107fab00]
    s.bx = m.r32((0xab7f10u));
    // 0x006c8079: MOV dword ptr [ESP + 0x14],EBP [896c2414]
    m.w32((f.sp + 0x14u), s.bp);
    // 0x006c807d: MOV EBP,dword ptr [0x00ab7f18] [8b2d187fab00]
    s.bp = m.r32((0xab7f18u));
    // 0x006c8083: MOV dword ptr [ESP + 0x18],EBP [896c2418]
    m.w32((f.sp + 0x18u), s.bp);
    // 0x006c8087: MOV EBP,dword ptr [0x00ab7f1c] [8b2d1c7fab00]
    s.bp = m.r32((0xab7f1cu));
    // 0x006c808d: CMP EBX,EAX [3bd8]
    (void)ix::sub(s.bx,s.ax,32u,s.arithmetic_flags);
    // 0x006c808f: MOV dword ptr [ESP + 0x10],EBX [895c2410]
    m.w32((f.sp + 0x10u), s.bx);
    // 0x006c8093: MOV dword ptr [ESP + 0x1c],EBP [896c241c]
    m.w32((f.sp + 0x1cu), s.bp);
    // 0x006c8097: JLE 0x006c80ab [7e12]
    if (!ix::condition("JLE",s.arithmetic_flags)) outside(0x6c8097u);
    // 0x006c80ab: MOV EBP,dword ptr [ESP + 0x14] [8b6c2414]
    s.bp = m.r32((f.sp + 0x14u));
    // 0x006c80af: CMP EBP,EDX [3bea]
    (void)ix::sub(s.bp,s.dx,32u,s.arithmetic_flags);
    // 0x006c80b1: JLE 0x006c80c7 [7e14]
    if (!ix::condition("JLE",s.arithmetic_flags)) outside(0x6c80b1u);
    // 0x006c80c7: MOV EBP,dword ptr [ESP + 0x18] [8b6c2418]
    s.bp = m.r32((f.sp + 0x18u));
    // 0x006c80cb: LEA EDX,[ECX + EAX*0x1] [8d1401]
    s.dx = (s.cx + s.ax * 1u);
    // 0x006c80ce: ADD EBP,EBX [03eb]
    s.bp = ix::add(s.bp,s.bx,32u,s.arithmetic_flags);
    // 0x006c80d0: CMP EBP,EDX [3bea]
    (void)ix::sub(s.bp,s.dx,32u,s.arithmetic_flags);
    // 0x006c80d2: JGE 0x006c80de [7d0a]
    if (!ix::condition("JGE",s.arithmetic_flags)) outside(0x6c80d2u);
    // 0x006c80de: MOV ECX,dword ptr [ESP + 0x24] [8b4c2424]
    s.cx = m.r32((f.sp + 0x24u));
    // 0x006c80e2: MOV EDX,dword ptr [ESP + 0x2c] [8b54242c]
    s.dx = m.r32((f.sp + 0x2cu));
    // 0x006c80e6: MOV EBP,dword ptr [ESP + 0x1c] [8b6c241c]
    s.bp = m.r32((f.sp + 0x1cu));
    // 0x006c80ea: LEA EAX,[EDX + ECX*0x1] [8d040a]
    s.ax = (s.dx + s.cx * 1u);
    // 0x006c80ed: MOV EDX,dword ptr [ESP + 0x14] [8b542414]
    s.dx = m.r32((f.sp + 0x14u));
    // 0x006c80f1: LEA ECX,[EDX + EBP*0x1] [8d0c2a]
    s.cx = (s.dx + s.bp * 1u);
    // 0x006c80f4: CMP ECX,EAX [3bc8]
    (void)ix::sub(s.cx,s.ax,32u,s.arithmetic_flags);
    // 0x006c80f6: JGE 0x006c8106 [7d0e]
    if (!ix::condition("JGE",s.arithmetic_flags)) outside(0x6c80f6u);
    // 0x006c8106: MOV ECX,dword ptr [ESP + 0x18] [8b4c2418]
    s.cx = m.r32((f.sp + 0x18u));
    // 0x006c810a: MOV EAX,EBX [8bc3]
    s.ax = s.bx;
    // 0x006c810c: JMP 0x006c8121 [eb13]
    // Selected unconditional jump.
    // 0x006c8121: MOV [0x00ab7f10],EAX [a3107fab00]
    m.w32((0xab7f10u), s.ax);
    // 0x006c8126: MOV dword ptr [0x00ab7f14],EDX [8915147fab00]
    m.w32((0xab7f14u), s.dx);
    // 0x006c812c: MOV dword ptr [0x00ab7f18],ECX [890d187fab00]
    m.w32((0xab7f18u), s.cx);
    // 0x006c8132: MOV dword ptr [0x00ab7f1c],EBP [892d1c7fab00]
    m.w32((0xab7f1cu), s.bp);
    // 0x006c8138: MOV EAX,dword ptr [ESP + 0x70] [8b442470]
    s.ax = m.r32((f.sp + 0x70u));
    // 0x006c813c: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax & s.ax,32u,s.arithmetic_flags);
    // 0x006c813e: JZ 0x006c81f3 [0f84af000000]
    if (ix::condition("JZ",s.arithmetic_flags)) outside(0x6c813eu);
    // 0x006c8144: MOV EAX,dword ptr [ESP + 0x44] [8b442444]
    s.ax = m.r32((f.sp + 0x44u));
    // 0x006c8148: MOV ECX,dword ptr [ESP + 0x48] [8b4c2448]
    s.cx = m.r32((f.sp + 0x48u));
    // 0x006c814c: MOV dword ptr [ESP + 0x28],EAX [89442428]
    m.w32((f.sp + 0x28u), s.ax);
    // 0x006c8150: MOV dword ptr [ESP + 0x18],EAX [89442418]
    m.w32((f.sp + 0x18u), s.ax);
    // 0x006c8154: MOV EAX,dword ptr [ESP + 0x68] [8b442468]
    s.ax = m.r32((f.sp + 0x68u));
    // 0x006c8158: XOR EBP,EBP [33ed]
    s.bp = ix::logical(s.bp ^ s.bp,32u,s.arithmetic_flags);
    // 0x006c815a: MOV dword ptr [ESP + 0x2c],ECX [894c242c]
    m.w32((f.sp + 0x2cu), s.cx);
    // 0x006c815e: MOV dword ptr [ESP + 0x1c],ECX [894c241c]
    m.w32((f.sp + 0x1cu), s.cx);
    // 0x006c8162: MOVSX ECX,word ptr [ESI] [0fbf0e]
    s.cx = global_b26::sx16(m.r16((s.si)));
    // 0x006c8165: MOV dword ptr [ESP + 0x20],EBP [896c2420]
    m.w32((f.sp + 0x20u), s.bp);
    // 0x006c8169: MOV dword ptr [ESP + 0x24],EBP [896c2424]
    m.w32((f.sp + 0x24u), s.bp);
    // 0x006c816d: MOV dword ptr [ESP + 0x10],EBP [896c2410]
    m.w32((f.sp + 0x10u), s.bp);
    // 0x006c8171: MOV dword ptr [ESP + 0x14],EBP [896c2414]
    m.w32((f.sp + 0x14u), s.bp);
    // 0x006c8175: MOV EBP,dword ptr [EAX] [8b28]
    s.bp = m.r32((s.ax));
    // 0x006c8177: XOR EBX,EBX [33db]
    s.bx = ix::logical(s.bx ^ s.bx,32u,s.arithmetic_flags);
    // 0x006c8179: ADD ECX,EBP [03cd]
    s.cx = ix::add(s.cx,s.bp,32u,s.arithmetic_flags);
    // 0x006c817b: MOV EBP,dword ptr [EAX + 0x4] [8b6804]
    s.bp = m.r32((s.ax + 0x4u));
    // 0x006c817e: MOV dword ptr [ESP + 0x30],ECX [894c2430]
    m.w32((f.sp + 0x30u), s.cx);
    // 0x006c8182: XOR EDX,EDX [33d2]
    s.dx = ix::logical(s.dx ^ s.dx,32u,s.arithmetic_flags);
    // 0x006c8184: MOVSX ECX,word ptr [ESI + 0x2] [0fbf4e02]
    s.cx = global_b26::sx16(m.r16((s.si + 0x2u)));
    // 0x006c8188: ADD ECX,EBP [03cd]
    s.cx = ix::add(s.cx,s.bp,32u,s.arithmetic_flags);
    // 0x006c818a: XOR EAX,EAX [33c0]
    s.ax = ix::logical(s.ax ^ s.ax,32u,s.arithmetic_flags);
    // 0x006c818c: MOV AX,word ptr [ESI + 0x4] [668b4604]
    s.ax = (s.ax & 0xffff0000u) | (((m.r16((s.si + 0x4u))) & 0xffffu) << 0u);
    // 0x006c8190: MOV dword ptr [ESP + 0x34],ECX [894c2434]
    m.w32((f.sp + 0x34u), s.cx);
    // 0x006c8194: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c8195: XOR ECX,ECX [33c9]
    s.cx = ix::logical(s.cx ^ s.cx,32u,s.arithmetic_flags);
    // 0x006c8197: MOV CX,word ptr [ESI + 0x6] [668b4e06]
    s.cx = (s.cx & 0xffff0000u) | (((m.r16((s.si + 0x6u))) & 0xffffu) << 0u);
    // 0x006c819b: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x006c819c: MOV EDX,dword ptr [ESP + 0x6c] [8b54246c]
    s.dx = m.r32((f.sp + 0x6cu));
    // 0x006c81a0: MOV dword ptr [ESP + 0x40],EAX [89442440]
    m.w32((f.sp + 0x40u), s.ax);
    // 0x006c81a4: MOV EAX,dword ptr [ESP + 0x7c] [8b44247c]
    s.ax = m.r32((f.sp + 0x7cu));
    // 0x006c81a8: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c81a9: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x006c81aa: MOV EDX,dword ptr [EDI] [8b17]
    s.dx = m.r32((s.di));
    // 0x006c81ac: MOV dword ptr [ESP + 0x4c],ECX [894c244c]
    m.w32((f.sp + 0x4cu), s.cx);
    // 0x006c81b0: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x006c81b1: MOV ECX,EDI [8bcf]
    s.cx = s.di;
    // 0x006c81b3: CALL dword ptr [EDX + 0x2c4] [ff92c4020000]
    if (m.r32((s.dx + 0x2c4u)) != 0x4c9610u) outside(0x6c81b3u);
    { f.push(m,0x6c81b9u); Frame child{f.sp,f.sp,0x6c81b9u}; kind2_4c9610(m,s,child); f.sp=child.sp; }
    // 0x006c81b9: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x006c81ba: MOV EAX,dword ptr [EDI] [8b07]
    s.ax = m.r32((s.di));
    // 0x006c81bc: MOV ECX,EDI [8bcf]
    s.cx = s.di;
    // 0x006c81be: CALL dword ptr [EAX + 0x2c0] [ff90c0020000]
    if (m.r32((s.ax + 0x2c0u)) != 0x4c9530u) outside(0x6c81beu);
    { f.push(m,0x6c81c4u); Frame child{f.sp,f.sp,0x6c81c4u}; execute_score(m,s,child); f.sp=child.sp; }
    // 0x006c81c4: MOV ECX,dword ptr [ESP + 0x88] [8b8c2488000000]
    s.cx = m.r32((f.sp + 0x88u));
    // 0x006c81cb: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x006c81cc: LEA EDX,[ESP + 0x3c] [8d54243c]
    s.dx = (f.sp + 0x3cu);
    // 0x006c81d0: PUSH ECX [51]
    f.push(m,s.cx);
    // 0x006c81d1: LEA EAX,[ESP + 0x30] [8d442430]
    s.ax = (f.sp + 0x30u);
    // 0x006c81d5: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x006c81d6: LEA ECX,[ESP + 0x64] [8d4c2464]
    s.cx = (f.sp + 0x64u);
    // 0x006c81da: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x006c81db: LEA EDX,[ESP + 0x58] [8d542458]
    s.dx = (f.sp + 0x58u);
    // 0x006c81df: PUSH ECX [51]
    f.push(m,s.cx);
    // 0x006c81e0: MOV ECX,dword ptr [0x00821c9c] [8b0d9c1c8200]
    s.cx = m.r32((0x821c9cu));
    // 0x006c81e6: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x006c81e7: MOV EDX,dword ptr [ESP + 0x9c] [8b94249c000000]
    s.dx = m.r32((f.sp + 0x9cu));
    // 0x006c81ee: CALL 0x00434f80 [e88dcdd6ff]
    { f.push(m,0x6c81f3u); Frame child{f.sp,f.sp,0x6c81f3u}; execute_surface(m,s,child); f.sp=child.sp; }
    // 0x006c81f3: LEA ECX,[ESP + 0x54] [8d4c2454]
    s.cx = (f.sp + 0x54u);
    // 0x006c81f7: CALL 0x00438290 [e89400d7ff]
    { f.push(m,0x6c81fcu); Frame child{f.sp,f.sp,0x6c81fcu}; teardown_438290(m,s,child); f.sp=child.sp; }
    // 0x006c81fc: POP EDI [5f]
    s.di = f.pop(m);
    // 0x006c81fd: POP ESI [5e]
    s.si = f.pop(m);
    // 0x006c81fe: POP EBP [5d]
    s.bp = f.pop(m);
    // 0x006c81ff: POP EBX [5b]
    s.bx = f.pop(m);
    // 0x006c8200: ADD ESP,0x50 [83c450]
    f.sp = ix::add(f.sp,0x50u,32u,s.arithmetic_flags);
    // 0x006c8203: RET 0x14 [c21400]
    recovery_b566::finish(m,s,f,0x14u);
}
} // namespace ra2::recovered::recovery_b1708
