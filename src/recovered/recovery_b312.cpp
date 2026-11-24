#include "recovery_b312.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b312 {
namespace {
constexpr std::uint32_t head_a = 0x00ab7ed8;
constexpr std::uint32_t table_a = 0x00ab7ec4;
constexpr std::uint32_t count = 0x00ab7ebc;
constexpr std::uint32_t table_b = 0x00ab7ec8;
constexpr std::uint32_t scalar = 0x00ab7ec0;
constexpr std::uint32_t head_b = 0x00ab7ed4;
constexpr std::uint32_t tail = 0x00ab7ecc;

void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
void release(Heap& h, std::uint32_t p) {
    require(p != 0, "B312 finite route excludes null free arguments");
    require(h.release(p) != 0, "B312 requires successful original CRT release");
}
}

std::uint32_t rva_002eea30(Memory& m, Heap& h) {
    // This route selects a 1-entry array count and one-node lists, so the
    // original loop bounds and all helper calls are exercised finitely.
    require(m.r32(count) == 1, "B312 finite route requires count exactly one");
    const auto a = m.r32(head_a);
    const auto ta = m.r32(table_a);
    const auto tb = m.r32(table_b);
    const auto s = m.r32(scalar);
    const auto b = m.r32(head_b);
    require(a && ta && tb && s && b, "B312 finite route requires all seven objects");
    require(h.r32(a) == 0 && h.r32(b) == 0,
            "B312 finite route requires one-node lists terminated by null");
    const auto ea = h.r32(ta);
    const auto eb = h.r32(tb);
    require(ea && eb, "B312 finite route requires a nonnull entry in each array");

    // Match the order and field clearing in 0x2eea30. The real original
    // executes 0x76d67b for every release on the native side.
    m.w32(head_a, 0);
    release(h, a);
    release(h, ea);
    release(h, ta);
    m.w32(table_a, 0);
    release(h, eb);
    release(h, tb);
    m.w32(table_b, 0);
    release(h, s);
    m.w32(scalar, 0);
    release(h, b);
    m.w32(head_b, 0);
    m.w32(tail, 0);
    return 0; // final one-node list iteration MOV EAX,ESI where ESI == 0
}
}
