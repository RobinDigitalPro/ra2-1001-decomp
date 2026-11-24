#include "recovered/indirect_b30_memory.hpp"

namespace ra2::recovered::indirect_b30 {
namespace {
constexpr std::uint32_t kImport302a0 = 0x007855a0;
constexpr std::uint32_t kImport30300 = 0x007855a4;
constexpr std::uint32_t kImport91fd0 = 0x007851bc;
constexpr std::uint32_t kImportCfbe0 = 0x00785524;
constexpr std::uint32_t kImport13a9b0 = 0x007850cc;
constexpr std::uint32_t kImport1b3510 = 0x0078552c;
constexpr std::uint32_t kImport1b3520 = 0x00785520;
constexpr std::uint32_t kImport1c0830 = 0x00785484;
constexpr std::uint32_t kGlobalCounter = 0x00a56744;
constexpr std::uint32_t kGlobalInterface = 0x00821f90;
constexpr std::uint32_t kGlobalWideArg = 0x00a5a460;
constexpr std::uint32_t kGlobalObject = 0x00b0d628;

void push(Memory& m, Frame& f, std::uint32_t value) {
    f.push(m, value);
}

void call(Memory& m, State& s, Frame& f, const Operations& op,
          std::uint32_t target) {
    invoke(m, s, f, op, target);
}

void complete(Memory& m, State& s, Frame& f, std::uint32_t cleanup) {
    ra2::recovered::indirect_b30::finish(m, s, f, cleanup);
}

void fun_00411090(Memory& m, State& s, Frame& f, const Operations& op) {
    s.dx = m.r32(f.entry_sp + 4u);
    s.cx = m.r32(s.cx + 0x14u);
    s.dx &= 0xffffu;
    s.ax = m.r32(s.cx);
    push(m, f, s.dx);
    s.dx = f.sp + 0x0cu;
    push(m, f, s.dx);
    const auto target = m.r32(s.ax + 0x14u);
    call(m, s, f, op, target);
    complete(m, s, f, 20u);
}

void fun_004113c0(Memory& m, State& s, Frame& f, const Operations& op) {
    const auto saved_si = s.si;
    push(m, f, saved_si);
    s.si = s.cx;
    s.ax = m.r32(s.si);
    const auto target = m.r32(s.ax + 0x7cu);
    call(m, s, f, op, target);
    s.ax *= m.r32(s.si + 0x10u);
    s.si = f.pop(m);
    complete(m, s, f, 0u);
}

void fun_004302a0(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(f.entry_sp + 4u);
    s.cx = m.r32(s.cx + 4u);
    push(m, f, 1u);
    push(m, f, s.ax);
    push(m, f, s.cx);
    const auto target = m.r32(kImport302a0);
    call(m, s, f, op, target);
    complete(m, s, f, 4u);
}

void fun_00430300(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(f.entry_sp + 4u);
    s.cx = m.r32(s.cx + 4u);
    s.ax &= 0xffu;
    push(m, f, s.ax);
    push(m, f, s.cx);
    const auto target = m.r32(kImport30300);
    call(m, s, f, op, target);
    complete(m, s, f, 4u);
}

void fun_00432010(Memory& m, State& s, Frame& f, const Operations& op) {
    const auto saved_si = s.si;
    push(m, f, saved_si);
    s.si = s.cx;
    s.cx = m.r32(f.sp + 8u);
    s.ax = m.r32(s.cx);
    const auto target = m.r32(s.ax + 0x60u);
    call(m, s, f, op, target);
    s.ax = 0;
    m.w32(s.si + 0x0cu, 0);
    m.w32(s.si + 0x10u, 0);
    s.si = f.pop(m);
    complete(m, s, f, 4u);
}

void counted_import(Memory& m, State& s, Frame& f, const Operations& op,
                    std::uint32_t addend) {
    s.ax = m.r32(f.entry_sp + 4u);
    s.dx = m.r32(kGlobalCounter);
    s.ax += addend;
    s.dx += 1u;
    push(m, f, s.ax);
    m.w32(kGlobalCounter, s.dx);
    const auto target = m.r32(kImport91fd0);
    call(m, s, f, op, target);
    complete(m, s, f, 4u);
}
void fun_00491fd0(Memory& m, State& s, Frame& f, const Operations& op) {
    counted_import(m, s, f, op, 0x20u);
}
void fun_00492970(Memory& m, State& s, Frame& f, const Operations& op) {
    counted_import(m, s, f, op, 8u);
}

void vtable_four_arg_call(Memory& m, State& s, Frame& f,
                          const Operations& op, std::uint32_t slot) {
    s.ax = m.r32(f.entry_sp + 4u);
    push(m, f, 0u);
    push(m, f, 0x44u);
    push(m, f, s.cx);
    s.dx = m.r32(s.ax);
    push(m, f, s.ax);
    const auto target = m.r32(s.dx + slot);
    call(m, s, f, op, target);
    complete(m, s, f, 4u);
}
void fun_004b5960(Memory& m, State& s, Frame& f, const Operations& op) {
    vtable_four_arg_call(m, s, f, op, 0x0cu);
}
void fun_004b5980(Memory& m, State& s, Frame& f, const Operations& op) {
    vtable_four_arg_call(m, s, f, op, 0x10u);
}

void fun_004c8960(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(s.cx);
    const auto target = m.r32(s.ax + 0x16cu);
    call(m, s, f, op, target);
    s.ax = with_al(s.ax, s.ax == 7u ? 1u : 0u);
    complete(m, s, f, 0u);
}

void fun_004cfbe0(Memory& m, State& s, Frame& f, const Operations& op) {
    const auto saved_si = s.si;
    push(m, f, saved_si);
    s.si = s.cx;
    const auto target = m.r32(kImportCfbe0);
    call(m, s, f, op, target);
    m.w32(s.si, s.ax);
    s.ax = s.si;
    s.si = f.pop(m);
    complete(m, s, f, 0u);
}

void fun_00523240(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = s.cx;
    const auto saved_si = s.si;
    push(m, f, saved_si);
    s.cx = m.r32(kGlobalInterface);
    push(m, f, 0u);
    push(m, f, s.dx);
    push(m, f, s.ax);
    s.si = m.r32(s.cx);
    const auto target = m.r32(s.si + 0x10u);
    call(m, s, f, op, target);
    s.ax = 1u;
    s.si = f.pop(m);
    complete(m, s, f, 0u);
}

void fun_005372a0(Memory& m, State& s, Frame& f, const Operations& op) {
    const auto saved_si = s.si;
    push(m, f, saved_si);
    s.si = s.cx;
    s.cx = m.r32(f.sp + 8u);
    s.ax = m.r32(s.cx);
    const auto target = m.r32(s.ax + 0x18u);
    call(m, s, f, op, target);
    m.w32(s.ax + 8u, s.si);
    m.w32(s.si + 4u, s.ax);
    m.w32(s.si + 8u, 0u);
    s.ax = s.si;
    s.si = f.pop(m);
    complete(m, s, f, 4u);
}

void fun_0053a9b0(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(f.entry_sp + 4u);
    push(m, f, s.ax);
    const auto target = m.r32(kImport13a9b0);
    call(m, s, f, op, target);
    s.ax = with_al(s.ax, s.ax == 1u ? 1u : 0u);
    complete(m, s, f, 4u);
}

void fun_0053b3f0(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(f.entry_sp + 4u);
    push(m, f, s.ax);
    m.w8(s.ax + 0x0cu, 0u);
    s.cx = m.r32(s.ax);
    const auto target = m.r32(s.cx + 0x60u);
    call(m, s, f, op, target);
    complete(m, s, f, 4u);
}
void fun_0053b430(Memory& m, State& s, Frame& f, const Operations& op) {
    counted_import(m, s, f, op, 0x14u);
}

void fun_0059be50(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(f.entry_sp + 4u);
    s.dx = m.r32(s.cx);
    const auto saved_si = s.si;
    push(m, f, saved_si);
    s.si = m.r32(f.sp + 0x0cu);
    push(m, f, s.si);
    push(m, f, s.ax);
    m.w32(s.cx + 0x4f34u, s.ax);
    const auto target = m.r32(s.dx + 0x4cu);
    call(m, s, f, op, target);
    s.si = f.pop(m);
    complete(m, s, f, 8u);
}

void fun_0059be70(Memory& m, State& s, Frame& f, const Operations& op) {
    s.dx = m.r32(s.cx + 0x4f34u);
    s.ax = m.r32(s.cx);
    push(m, f, 0u);
    push(m, f, s.dx);
    const auto target = m.r32(s.ax + 0x4cu);
    call(m, s, f, op, target);
    complete(m, s, f, 0u);
}

void fun_005ad550(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(s.cx);
    s.dx = f.sp + 4u;
    push(m, f, s.dx);
    const auto target = m.r32(s.ax + 0x10u);
    call(m, s, f, op, target);
    complete(m, s, f, 4u);
}

void fun_005b3510(Memory& m, State& s, Frame& f, const Operations& op) {
    const auto saved_si = s.si;
    push(m, f, saved_si);
    s.si = s.cx;
    push(m, f, 1u);
    const auto target = m.r32(kImport1b3510);
    call(m, s, f, op, target);
    s.ax = s.si;
    s.si = f.pop(m);
    complete(m, s, f, 0u);
}

void fun_005b3520(Memory& m, State& s, Frame& f, const Operations& op) {
    push(m, f, 1u);
    const auto target = m.r32(kImport1b3520);
    call(m, s, f, op, target);
    complete(m, s, f, 0u);
}

void fun_005c0830(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(kGlobalWideArg);
    push(m, f, 0u);
    push(m, f, 0u);
    push(m, f, 0x188u);
    push(m, f, 0x553u);
    push(m, f, s.ax);
    const auto target = m.r32(kImport1c0830);
    call(m, s, f, op, target);
    complete(m, s, f, 0u);
}

void fun_005ca3b0(Memory& m, State& s, Frame& f, const Operations& op) {
    s.cx = m.r32(kGlobalObject);
    s.dx = m.r32(f.entry_sp + 4u);
    push(m, f, s.dx);
    s.ax = m.r32(s.cx);
    const auto target = m.r32(s.ax + 0x20u);
    call(m, s, f, op, target);
    complete(m, s, f, 4u);
}
} // namespace

const std::array<Entry, 23>& entries_a() {
    static const std::array<Entry, 23> entries{{
        {0x11090u, fun_00411090}, {0x113c0u, fun_004113c0},
        {0x302a0u, fun_004302a0}, {0x30300u, fun_00430300},
        {0x32010u, fun_00432010}, {0x91fd0u, fun_00491fd0},
        {0x92970u, fun_00492970}, {0xb5960u, fun_004b5960},
        {0xb5980u, fun_004b5980}, {0xc8960u, fun_004c8960},
        {0xcfbe0u, fun_004cfbe0}, {0x123240u, fun_00523240},
        {0x1372a0u, fun_005372a0}, {0x13a9b0u, fun_0053a9b0},
        {0x13b3f0u, fun_0053b3f0}, {0x13b430u, fun_0053b430},
        {0x19be50u, fun_0059be50}, {0x19be70u, fun_0059be70},
        {0x1ad550u, fun_005ad550}, {0x1b3510u, fun_005b3510},
        {0x1b3520u, fun_005b3520}, {0x1c0830u, fun_005c0830},
        {0x1ca3b0u, fun_005ca3b0},
    }};
    return entries;
}
} // namespace ra2::recovered::indirect_b30
