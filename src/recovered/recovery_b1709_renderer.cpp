#include "recovery_b1709_renderer.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b1709 {
namespace ix = direct_b33::integer;
namespace {
struct Range { U base, size; };
void selected(bool ok) {
    if (!ok) throw std::domain_error("4866C0 outside positive one-pixel projection");
}
bool separate(Range a, Range b) {
    return std::uint64_t(a.base) + a.size <= b.base ||
           std::uint64_t(b.base) + b.size <= a.base;
}
void readable(const Memory& m, Range r) {
    selected(r.size != 0u && std::uint64_t(r.base) + r.size <= 0x100000000ull);
    for (U k = 0; k != r.size; ++k) (void)m.r8(r.base + k);
}
void require_renderer_projection(const Memory& m, const State& s, const Frame& f) {
    // Readonly finite input checks, not physical ownership/normal-producer proof.
    // No private word is checked for a value or initialized by this component.
    selected(f.sp == f.entry_sp && f.entry_sp >= 0x14u &&
             f.entry_sp <= 0xffffffbbu && f.outer_return == 0x43531cu);
    const Range stack{f.entry_sp - 0x14u, 0x58u};
    readable(m, {f.entry_sp - 0x14u, 0x18u});
    selected(m.r32(f.entry_sp) == f.outer_return);
    selected(m.r32(f.entry_sp + 0xcu) == 1u &&
             m.r32(f.entry_sp + 0x10u) == 0u);
    const Range object{s.cx, 8u};
    readable(m, object);
    selected(m.r32(s.cx) == 0x789488u && m.r32(0x78948cu) == 0x4866c0u);
    const Range destination{m.r32(f.entry_sp + 4u), 1u};
    const Range payload{m.r32(f.entry_sp + 8u), 1u};
    const Range depth_word{m.r32(f.entry_sp + 0x18u), 2u};
    const Range control_byte{m.r32(f.entry_sp + 0x28u), 1u};
    const Range global{0x821facu, 4u};
    const U depth = m.r32(global.base);
    const Range depth_metadata{depth, 0x24u};
    selected(depth != 0u);
    readable(m, destination); readable(m, payload); readable(m, depth_word);
    readable(m, control_byte);
    // The actual leaf reads end unconditionally and span only upon wrapping.
    // Full normal provider/header/backing ownership is external, not invented.
    selected(std::uint64_t(depth) + depth_metadata.size <= 0x100000000ull);
    const U end = m.r32(depth + 0x1cu);
    selected(destination.base != 0xffffffffu && payload.base != 0xffffffffu &&
             control_byte.base != 0xffffffffu && depth_word.base <= 0xfffffffdu);
    const U next_depth = depth_word.base + 2u;
    selected(end != 0u);
    if (next_depth >= end) {
        const U span = m.r32(depth + 0x20u);
        selected(span != 0u && span <= next_depth);
    }
    selected(m.r8(payload.base) == 1u);
    const U old_destination = m.r8(destination.base);
    const U palette = m.r32(s.cx + 4u);
    selected(std::uint64_t(palette) + old_destination < 0x100000000ull);
    const Range color{palette + old_destination, 1u};
    readable(m, color);
    selected(m.r8(color.base) != old_destination);
    const U delta = m.r32(f.entry_sp + 0x14u) - global_b26::sx8(m.r8(control_byte.base));
    selected(ix::sign_extend(delta, 32u) < std::int64_t(m.r16(depth_word.base)));
    const Range table{0x789488u, 8u};
    const Range ranges[]{object, destination, payload, depth_word, control_byte,
                         global, depth_metadata, color, table};
    for (U i = 0; i != 9u; ++i) {
        selected(separate(stack, ranges[i]));
        for (U j = 0; j != i; ++j) selected(separate(ranges[i], ranges[j]));
    }
    // Unused formals6/7/8 have no value guard; arg7=1000 is not a row index.
    // Caller owns the whole encoded row, palette allocation and provider lifetime.
}
}

void execute_renderer(Memory& m, State& s, Frame& f) {
    require_renderer_projection(m, s, f);
    // 0x4866c0: PUSH ecx [51]
    f.push(m, s.cx);
    // 0x4866c1: MOV eax, dword ptr [esp + 0x14] [8b442414]
    s.ax = m.r32(f.sp + 0x14u);
    // 0x4866c5: MOV edx, dword ptr [esp + 0x1c] [8b54241c]
    s.dx = m.r32(f.sp + 0x1cu);
    // 0x4866c9: PUSH ebx [53]
    f.push(m, s.bx);
    // 0x4866ca: PUSH ebp [55]
    f.push(m, s.bp);
    // 0x4866cb: MOV ebp, dword ptr [esp + 0x34] [8b6c2434]
    s.bp = m.r32(f.sp + 0x34u);
    // 0x4866cf: PUSH esi [56]
    f.push(m, s.si);
    // 0x4866d0: MOV esi, dword ptr [esp + 0x14] [8b742414]
    s.si = m.r32(f.sp + 0x14u);
    // 0x4866d4: MOV dword ptr [esp + 0xc], ecx [894c240c]
    m.w32(f.sp + 0xcu, s.cx);
    // 0x4866d8: MOV ecx, dword ptr [0x821fac] [8b0dac1f8200]
    s.cx = m.r32(0x821facu);
    // 0x4866de: PUSH edi [57]
    f.push(m, s.di);
    // 0x4866df: MOV edi, dword ptr [esp + 0x1c] [8b7c241c]
    s.di = m.r32(f.sp + 0x1cu);
    // 0x4866e3: TEST eax, eax [85c0]
    (void)ix::logical(s.ax & s.ax, 32u, s.arithmetic_flags);
    // 0x4866e5: JLE 0x486717 [7e30]
    if (!ix::condition("JLE", s.arithmetic_flags)) selected(false);
    // 0x486717: MOV ebx, dword ptr [esp + 0x20] [8b5c2420]
    s.bx = m.r32(f.sp + 0x20u);
    // 0x48671b: TEST ebx, ebx [85db]
    (void)ix::logical(s.bx & s.bx, 32u, s.arithmetic_flags);
    // 0x48671d: JLE 0x486782 [7e63]
    if (ix::condition("JLE", s.arithmetic_flags)) selected(false);
    // 0x48671f: MOV al, byte ptr [edi] [8a07]
    s.ax = (s.ax & 0xffffff00u) | m.r8(s.di);
    // 0x486721: INC edi [47]
    s.di = ix::increment(s.di, 32u, s.arithmetic_flags);
    // 0x486722: TEST al, al [84c0]
    (void)ix::logical((s.ax & 0xffu) & (s.ax & 0xffu), 8u, s.arithmetic_flags);
    // 0x486724: JNE 0x486741 [751b]
    if (!ix::condition("JNZ", s.arithmetic_flags)) selected(false);
    // 0x486741: MOVSX ecx, byte ptr [ebp] [0fbe4d00]
    s.cx = global_b26::sx8(m.r8(s.bp));
    // 0x486745: MOV eax, dword ptr [esp + 0x28] [8b442428]
    s.ax = m.r32(f.sp + 0x28u);
    // 0x486749: ADD edx, 2 [83c202]
    s.dx = ix::add(s.dx, 2u, 32u, s.arithmetic_flags);
    // 0x48674c: SUB eax, ecx [2bc1]
    s.ax = ix::sub(s.ax, s.cx, 32u, s.arithmetic_flags);
    // 0x48674e: XOR ecx, ecx [33c9]
    s.cx = ix::logical(s.cx ^ s.cx, 32u, s.arithmetic_flags);
    // 0x486750: MOV cx, word ptr [edx - 2] [668b4afe]
    s.cx = (s.cx & 0xffff0000u) | m.r16(s.dx - 2u);
    // 0x486754: INC ebp [45]
    s.bp = ix::increment(s.bp, 32u, s.arithmetic_flags);
    // 0x486755: CMP eax, ecx [3bc1]
    (void)ix::sub(s.ax, s.cx, 32u, s.arithmetic_flags);
    // 0x486757: JGE 0x48676e [7d15]
    if (ix::condition("JGE", s.arithmetic_flags)) selected(false);
    // 0x486759: MOV ecx, dword ptr [esp + 0x10] [8b4c2410]
    s.cx = m.r32(f.sp + 0x10u);
    // 0x48675d: XOR eax, eax [33c0]
    s.ax = ix::logical(s.ax ^ s.ax, 32u, s.arithmetic_flags);
    // 0x48675f: MOV al, byte ptr [esi] [8a06]
    s.ax = (s.ax & 0xffffff00u) | m.r8(s.si);
    // 0x486761: DEC ebx [4b]
    s.bx = ix::decrement(s.bx, 32u, s.arithmetic_flags);
    // 0x486762: MOV ecx, dword ptr [ecx + 4] [8b4904]
    s.cx = m.r32(s.cx + 4u);
    // 0x486765: INC esi [46]
    s.si = ix::increment(s.si, 32u, s.arithmetic_flags);
    // 0x486766: MOV al, byte ptr [ecx + eax] [8a0401]
    s.ax = (s.ax & 0xffffff00u) | m.r8(s.cx + s.ax);
    // 0x486769: MOV byte ptr [esi - 1], al [8846ff]
    m.w8(s.si - 1u, s.ax & 0xffu);
    // 0x48676c: JMP 0x486770 [eb02]
    // The selected unconditional jump joins 486770.
    // 0x486770: MOV ecx, dword ptr [0x821fac] [8b0dac1f8200]
    s.cx = m.r32(0x821facu);
    // 0x486776: CMP edx, dword ptr [ecx + 0x1c] [3b511c]
    (void)ix::sub(s.dx, m.r32(s.cx + 0x1cu), 32u, s.arithmetic_flags);
    // 0x486779: JB 0x48677e [7203]
    if (!ix::condition("JC", s.arithmetic_flags)) {
    // 0x48677b: SUB edx, dword ptr [ecx + 0x20] [2b5120]
        s.dx = ix::sub(s.dx, m.r32(s.cx + 0x20u), 32u, s.arithmetic_flags);
    }
    // 0x48677e: TEST ebx, ebx [85db]
    (void)ix::logical(s.bx & s.bx, 32u, s.arithmetic_flags);
    // 0x486780: JG 0x48671f [7f9d]
    if (ix::condition("JG", s.arithmetic_flags)) selected(false);
    // 0x486782: POP edi [5f]
    s.di = f.pop(m);
    // 0x486783: POP esi [5e]
    s.si = f.pop(m);
    // 0x486784: POP ebp [5d]
    s.bp = f.pop(m);
    // 0x486785: POP ebx [5b]
    s.bx = f.pop(m);
    // 0x486786: POP ecx [59]
    s.cx = f.pop(m);
    // 0x486787: RET 0x28 [c22800]
    recovery_b566::finish(m, s, f, 0x28u);
}
} // namespace ra2::recovered::recovery_b1709
