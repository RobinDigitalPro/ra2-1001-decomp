#include "recovery_b1708.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b1708 {
namespace ix = direct_b33::integer;
namespace {
struct Range { U base; U size; };
void selected(bool ok) {
    if (!ok) throw std::domain_error("4862D0 outside selected positive one-pixel projection");
}
bool separate(Range a, Range b) {
    return std::uint64_t(a.base) + a.size <= b.base ||
           std::uint64_t(b.base) + b.size <= a.base;
}
void readable(const Memory& m, Range r) {
    selected(r.size != 0u && std::uint64_t(r.base) + r.size <= 0x100000000ull);
    for (U k = 0u; k != r.size; ++k) (void)m.r8(r.base + k);
}
void require_renderer_projection(const Memory& m, const State& s, const Frame& f) {
    // Readonly finite-domain checks, not physical ownership/writability proofs.
    // The real caller must have pushed its return word before this entry.
    selected(f.sp == f.entry_sp && f.entry_sp >= 0xcu &&
             f.entry_sp <= 0xffffffbbu && f.outer_return == 0x43531cu);
    const Range stack{f.entry_sp - 0xcu, 0x50u};
    readable(m, stack);
    selected(m.r32(f.entry_sp) == f.outer_return);
    selected(m.r32(f.entry_sp + 0xcu) == 1u && m.r32(f.entry_sp + 0x10u) == 0u);
    const Range object{s.cx, 8u};
    readable(m, object);
    selected(m.r32(s.cx) == 0x7894d0u && m.r32(0x7894d4u) == 0x4862d0u);
    const Range destination{m.r32(f.entry_sp + 4u), 1u};
    const Range payload{m.r32(f.entry_sp + 8u), 1u};
    readable(m, destination);
    readable(m, payload);
    const U index = m.r8(payload.base);
    selected(index != 0u && payload.base != 0xffffffffu && destination.base != 0xffffffffu);
    const U palette = m.r32(s.cx + 4u);
    selected(std::uint64_t(palette) + index < 0x100000000ull);
    const Range color{palette + index, 1u};
    readable(m, color);
    const Range table{0x7894d0u, 8u};
    const Range ranges[]{object, destination, payload, color, table};
    for (U i = 0u; i != 5u; ++i) {
        selected(separate(stack, ranges[i]));
        for (U j = 0u; j != i; ++j) selected(separate(ranges[i], ranges[j]));
    }
    // Source WORD header/payload backing and complete palette allocation remain
    // the independent public-basis/ownership gate; no bytes are created here.
}
} // namespace

void execute_renderer(Memory& m, State& s, Frame& f) {
    require_renderer_projection(m, s, f);
    // 0x004862d0: MOV EAX,dword ptr [ESP+0x10] [8b442410]
    s.ax = m.r32(f.sp + 0x10u);
    // 0x004862d4: MOV EDX,dword ptr [ESP+8] [8b542408]
    s.dx = m.r32(f.sp + 8u);
    // 0x004862d8: PUSH EBP [55]
    f.push(m, s.bp);
    // 0x004862d9: PUSH ESI [56]
    f.push(m, s.si);
    // 0x004862da: MOV ESI,dword ptr [ESP+0xc] [8b74240c]
    s.si = m.r32(f.sp + 0xcu);
    // 0x004862de: PUSH EDI [57]
    f.push(m, s.di);
    // 0x004862df: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax & s.ax, 32u, s.arithmetic_flags);
    // 0x004862e1: MOV EBP,ECX [8be9]
    s.bp = s.cx;
    // 0x004862e3: JLE 0x486306 [7e21]
    if (!ix::condition("JLE", s.arithmetic_flags)) selected(false);
    // 0x00486306: MOV EDI,dword ptr [ESP+0x18] [8b7c2418]
    s.di = m.r32(f.sp + 0x18u);
    // 0x0048630a: TEST EDI,EDI [85ff]
    (void)ix::logical(s.di & s.di, 32u, s.arithmetic_flags);
    // 0x0048630c: JLE 0x486348 [7e3a]
    if (ix::condition("JLE", s.arithmetic_flags)) selected(false);
    // 0x0048630e: MOV AL,byte ptr [EDX] [8a02]
    s.ax = (s.ax & 0xffffff00u) | m.r8(s.dx);
    // 0x00486310: INC EDX [42]
    s.dx = ix::increment(s.dx, 32u, s.arithmetic_flags);
    // 0x00486311: TEST AL,AL [84c0]
    (void)ix::logical((s.ax & 0xffu) & (s.ax & 0xffu), 8u, s.arithmetic_flags);
    // 0x00486313: MOV byte ptr [ESP+0x18],AL [88442418]
    // This is the real outgoing child arg2 low byte at entryESP+0xc.
    m.w8(f.sp + 0x18u, s.ax & 0xffu);
    // 0x00486317: JNZ 0x48632f [7516]
    if (!ix::condition("JNZ", s.arithmetic_flags)) selected(false);
    // 0x0048632f: MOV ECX,dword ptr [ESP+0x18] [8b4c2418]
    s.cx = m.r32(f.sp + 0x18u);
    // 0x00486333: MOV EAX,dword ptr [EBP+4] [8b4504]
    s.ax = m.r32(s.bp + 4u);
    // 0x00486336: AND ECX,0xff [81e1ff000000]
    s.cx = ix::logical(s.cx & 0xffu, 32u, s.arithmetic_flags);
    // 0x0048633c: INC ESI [46]
    s.si = ix::increment(s.si, 32u, s.arithmetic_flags);
    // 0x0048633d: DEC EDI [4f]
    s.di = ix::decrement(s.di, 32u, s.arithmetic_flags);
    // 0x0048633e: MOV CL,byte ptr [EAX+ECX] [8a0c08]
    s.cx = (s.cx & 0xffffff00u) | m.r8(s.ax + s.cx);
    // 0x00486341: MOV byte ptr [ESI-1],CL [884eff]
    m.w8(s.si - 1u, s.cx & 0xffu);
    // 0x00486344: TEST EDI,EDI [85ff]
    (void)ix::logical(s.di & s.di, 32u, s.arithmetic_flags);
    // 0x00486346: JG 0x48630e [7fc6]
    if (ix::condition("JG", s.arithmetic_flags)) selected(false);
    // 0x00486348: POP EDI [5f]
    s.di = f.pop(m);
    // 0x00486349: POP ESI [5e]
    s.si = f.pop(m);
    // 0x0048634a: POP EBP [5d]
    s.bp = f.pop(m);
    // 0x0048634b: RET 0x28 [c22800]
    recovery_b566::finish(m, s, f, 0x28u);
}
} // namespace ra2::recovered::recovery_b1708
