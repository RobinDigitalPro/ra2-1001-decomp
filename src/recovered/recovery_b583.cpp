#include "recovery_b583.hpp"

#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b583 {
namespace {
[[noreturn]] void outside(const char* why) { throw std::domain_error(why); }
void require(bool ok, const char* why) { if (!ok) outside(why); }

std::string guest_text(const Memory& m, std::uint32_t p) {
    require(p != 0, "B583 expected non-null original prefix");
    std::string value;
    for (std::uint32_t k = 0; k < 32; ++k) {
        const auto c = static_cast<char>(m.r8(p + k));
        if (c == '\0') return value;
        value.push_back(c);
    }
    outside("B583 literal exceeds bounded readonly span");
}
std::string heap_text(const Heap& h, std::uint32_t p) {
    require(p != 0, "B583 expected live temporary");
    std::string value;
    for (std::uint32_t k = 0; k < 32; ++k) {
        const auto c = static_cast<char>(h.r8(p + k));
        if (c == '\0') return value;
        value.push_back(c);
    }
    outside("B583 temporary exceeds finite 10+2 character route");
}
std::uint32_t allocate_text(Heap& h, const std::string& value) {
    const auto p = h.allocate(static_cast<std::uint32_t>(value.size() + 1));
    require(p != 0, "B583 positive route requires successful CRT allocation");
    return p;
}
void store_text(Heap& h, std::uint32_t p, const std::string& value) {
    for (std::size_t k = 0; k < value.size(); ++k)
        h.w8(p + static_cast<std::uint32_t>(k),
             static_cast<std::uint8_t>(value[k]));
    h.w8(p + static_cast<std::uint32_t>(value.size()), 0);
}
}

std::uint32_t fun_00726af0(Memory& m, const Inputs& i, Heap& h) {
    // Original stack contract: ECX selector, EDX integer format value,
    // [entry ESP+4] is the caller-owned output string pointer cell; RET 4.
    const auto selector = i.cx;
    const auto number = i.dx;
    const auto output_cell = i.arg[0];
    require(output_cell != 0, "B583 needs a valid output pointer cell");
    require(m.r32(output_cell) == 0,
            "B583 finite positive route excludes replacing/freeing an old output");
    require(number <= 9,
            "B583 finite formatting oracle covers only nonnegative 0..9 values");
    // 0x35af50 emits `%02d` using original width=2 and VA 0x7e960c;
    // for 0..9 this is exactly two ASCII digits plus NUL (request 3).
    const std::string digits{static_cast<char>('0' + number / 10),
                             static_cast<char>('0' + number % 10)};
    const auto f = allocate_text(h, digits); // F: request 3
    h.w8(f, 0);
    store_text(h, f, digits);

    // 0x726af3 selects one of two pinned 10-byte original literals.
    // The following source-level allocation sequence mirrors 0x35aff0,
    // 0x359570 and both 0x359320 destructors exactly as in the accepted
    // B169 heap/string contract, but this root's own stack slots are distinct
    // from B169: neither temporary aliases entry arg0 here.
    const auto prefix_va = selector == 3 ? 0x007e5f8cu : 0x007e5f80u;
    const auto prefix = guest_text(m, prefix_va);
    require(prefix.size() == 10,
            "B583 requires the pinned 10-byte Soviet/Allied prefix");

    const auto a = allocate_text(h, prefix); // A: request 11
    h.w8(a, 0);
    store_text(h, a, prefix);
    const auto b = allocate_text(h, prefix); // B: request 11
    store_text(h, b, prefix);

    const auto joined_text = prefix + heap_text(h, f);
    const auto c = allocate_text(h, joined_text); // C: request 13
    store_text(h, c, joined_text);
    h.release(b);

    const auto d_text = heap_text(h, c);
    const auto d = allocate_text(h, d_text); // D: request 13, reuses B
    store_text(h, d, d_text);
    h.release(c);
    h.release(a);

    // 0x359570 receives the still-null caller output and publishes E.
    const auto e_text = heap_text(h, d);
    const auto e = allocate_text(h, e_text); // E: request 13, reuses A
    m.w32(output_cell, e);
    h.w8(e, 0);
    store_text(h, e, e_text);

    // Original local objects are ESP-relative at entry-4 and entry-8.
    // Cleanup does not write the caller's output argument slot.
    h.release(d);
    h.release(f);
    return 1u; // original proves AL=1; upper EAX remains outside this draft.
}
}
