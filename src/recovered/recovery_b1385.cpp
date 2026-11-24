#include "recovery_b1385.hpp"
#include <stdexcept>

namespace ra2::recovered::b1385 {
namespace {
using U = std::uint32_t;
constexpr U ones = 0xffffffffu;
void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

// Exact bounded composition of accepted 0x40ff10 / 0x405bf0 and 0x5ca970.
// Registry growth/full cases are outside this finite route.
void append_existing(Memory& m, U count_at, U capacity_at, U table_at, U object) {
    const U count = m.r32(count_at);
    const U capacity = m.r32(capacity_at);
    need(ra2::recovered::global_b26::s32(count) >= 0 &&
         ra2::recovered::global_b26::s32(capacity) >= 0 &&
         ra2::recovered::global_b26::s32(count) < ra2::recovered::global_b26::s32(capacity),
         "B1385 accepted 0x5ca970 registry requires existing signed-valid room");
    m.w32(count_at, count + 1u);
    m.w32(m.r32(table_at) + count * 4u, object);
}

void original_40ff10(Memory& m, U c) {
    m.w32(c + 8u, 0x785e44u);
    m.w32(c + 0x0cu, 0x785e3cu);
    m.w32(c + 0x18u, 0u);
    m.w32(c + 0x1cu, 0u);
    m.w8(c + 0x20u, 0u);
    const U flags = m.r8(c + 0x14u) & 0xf8u;
    m.w32(c + 0x10u, ones);
    m.w32(c, 0x785dd8u);
    m.w32(c + 4u, 0x785dbcu);
    m.w32(c + 8u, 0x785db4u);
    m.w32(c + 0x0cu, 0x785dacu);
    m.w8(c + 0x14u, flags);
}

void original_405bf0(Memory& m, U c) {
    m.w32(c + 0x0cu, 0x008192ecu);
    m.w32(c, 0u);
    m.w32(c + 4u, 0u);
    m.w32(c + 8u, 0u);
}

void original_5ca970(Memory& m, U c) {
    original_40ff10(m, c);
    m.w32(c + 0x24u, 0u);
    m.w32(c + 0x28u, 0u);
    m.w32(c + 0x2cu, 0u);
    m.w32(c + 0x6cu, 0xffu);
    m.w32(c + 0x70u, 0xffu);
    m.w8(c + 0x76u, 1u);
    m.w8(c + 0x7du, 1u);
    m.w8(c + 0x85u, 1u);
    m.w32(c + 0x30u, 0u);
    m.w32(c + 0x34u, 0u);
    m.w32(c + 0x38u, 0u);
    m.w32(c + 0x64u, ones);
    m.w8(c + 0x68u, 0u);
    m.w8(c + 0x74u, 0u);
    m.w8(c + 0x75u, 0u);
    m.w8(c + 0x77u, 0u);
    m.w8(c + 0x78u, 0u);
    m.w8(c + 0x79u, 0u);
    m.w8(c + 0x7au, 0u);
    m.w8(c + 0x7bu, 0u);
    m.w8(c + 0x7cu, 0u);
    m.w32(c + 0x80u, ones);
    m.w8(c + 0x84u, 0u);
    m.w32(c + 0x88u, m.r32(0x00a5aa68u));
    m.w32(c + 0x8cu, m.r32(0x00a5aa6cu));
    m.w32(c + 0x90u, m.r32(0x00a5aa70u));
    m.w32(c + 0x94u, 0u);
    m.w32(c, 0x00792458u);
    m.w32(c + 4u, 0x0079243cu);
    m.w32(c + 8u, 0x00792434u);
    m.w32(c + 0x0cu, 0x0079242cu);
    original_405bf0(m, c + 0x3cu);
    original_405bf0(m, c + 0x50u);
    append_existing(m, 0x00a27fc8u, 0x00a27fc0u, 0x00a27fbcu, c);
    append_existing(m, 0x00aa8878u, 0x00aa8870u, 0x00aa886cu, c);
    append_existing(m, 0x00aa87c8u, 0x00aa87c0u, 0x00aa87bcu, c);
    append_existing(m, 0x00aa8770u, 0x00aa8768u, 0x00aa8764u, c);
    m.w8(c + 0x14u, m.r8(c + 0x14u) | 2u);
}
}

std::uint32_t fun_00432e80(Memory& m, const Inputs& i) {
    const U self = i.cx;
    original_5ca970(m, self);

    // Original field initialization before its optional arg0 branch.
    m.w32(self + 0x98u, 0u);
    m.w32(self + 0x9cu, 0u);
    m.w32(self + 0xa0u, m.r32(0x00836d70u));
    m.w32(self + 0xa4u, m.r32(0x00836d74u));
    m.w32(self + 0xa8u, m.r32(0x00836d78u));
    m.w32(self + 0xacu, m.r32(0x00836d70u));
    m.w32(self + 0xb0u, m.r32(0x00836d74u));
    const U vector_field = m.r32(0x00836d78u);
    m.w32(self + 0xb8u, 0u);
    m.w32(self + 0xbcu, 0u);
    m.w32(self + 0xb4u, vector_field);
    m.w8(self + 0xc0u, 0u);
    m.w32(self + 0xc4u, 0u);
    m.w32(self + 0xc8u, 0u);
    m.w32(self + 0xccu, i.arg[0]);
    m.w32(self, 0x007877e0u);
    m.w32(self + 4u, 0x007877c4u);
    m.w32(self + 8u, 0x007877bcu);
    m.w32(self + 0x0cu, 0x007877b4u);

    // The supported original capacity route: signed count 0..7, capacity 8.
    // It jumps over the indirect vector method, then increments and appends.
    const U capacity = m.r32(0x0084e558u);
    const U count = m.r32(0x0084e560u);
    need(ra2::recovered::global_b26::s32(count) >= 0 &&
         ra2::recovered::global_b26::s32(capacity) >= 0 &&
         ra2::recovered::global_b26::s32(count) < ra2::recovered::global_b26::s32(capacity),
         "B1385 root list requires original signed count-below-capacity branch");
    m.w32(0x0084e560u, count + 1u);
    m.w32(m.r32(0x0084e554u) + count * 4u, self);

    need(i.arg[0] == 0u, "B1385 supported initialized-null-attachment branch");
    return self;
}
}
