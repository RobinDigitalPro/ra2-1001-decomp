#include "recovery_b315.hpp"



#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b315 {
namespace {
using namespace ra2::recovered::global_b26;

std::uint32_t append_string(Memory& m, std::uint32_t destination,
                            std::uint32_t source) {
    // Exact byte effect of accepted leaf 0x779020, expressed over this
    // multi-span Memory type. Its public leaf Memory is a single-span view.
    auto end = destination;
    while (m.r8(end) != 0u) ++end;
    auto read = source;
    for (;;) {
        const auto byte = m.r8(read++);
        m.w8(end++, byte);
        if (byte == 0u) break;
    }
    return destination;
}

std::uint32_t accepted_compare(Memory& m, const Inputs& i) {
    auto left = i.arg[0];
    auto right = i.arg[1];
    if (std::uint64_t(left) + 4096u > 0x100000000ull ||
        std::uint64_t(right) + 4096u > 0x100000000ull)
        throw std::domain_error("Block68 comparison input bound wraps guest address space");
    for (std::uint32_t n = 0; n < 4096u; ++n, ++left, ++right) {
        const auto a = m.r8(left);
        const auto b = m.r8(right);
        if (a != b) return a < b ? 0xffffffffu : 1u;
        if (a == 0u) return 0u;
    }
    throw std::domain_error("Block68 comparison exceeded its finite string bound");
}

std::uint32_t compare_strings(Memory& m, std::uint32_t left,
                              std::uint32_t right) {
    Inputs args{};
    args.arg[0] = left;
    args.arg[1] = right;
    return accepted_compare(m, args);
}
}

std::uint32_t fun_00771a35(Memory& m, const Inputs&) {
    const auto metadata = m.r32(0x00817454u);
    if (metadata == 0u)
        throw std::domain_error("Block315 finite route requires a live metadata allocation");

    // VA 0x771a55 clears the first byte, then 0x771a58..0x771a7c
    // appends the three argument-vector sources [0x81745c], '=', [0x817460].
    m.w8(metadata, 0u);
    append_string(m, metadata, m.r32(0x0081745cu));
    append_string(m, metadata, 0x007ba34cu);
    append_string(m, metadata, m.r32(0x00817460u));

    // At 0x771a81 the root pushes 0x7bd77c, then metadata. With the accepted
    // cdecl append contract, metadata is destination and the original
    // semicolon is source, so the global string is read and remains unchanged.
    auto esi = 0x00817460u;
    auto ebx = esi;
    unsigned comparison = 0;
    do {
        append_string(m, metadata, 0x007bd77cu);

        const auto right = m.r32(esi + 0x0cu);
        esi += 0x0cu;
        const auto left = m.r32(ebx);
        const auto result = compare_strings(m, left, right);
        const auto expected = comparison < 3u ? 0u : 0xffffffffu;
        if (result != expected)
            throw std::domain_error("Block315 route requires equal/equal/equal/non-equal string pairs");

        // VA 0x771aa7..0x771ab7 uses the incremented ESI source vector:
        // [ESI-4], pinned literal '=', [ESI]. The final value is "A".
        ebx = esi;
        append_string(m, metadata, m.r32(esi - 4u));
        append_string(m, metadata, 0x007ba34cu);
        append_string(m, metadata, m.r32(esi));
        ++comparison;
    } while (esi < 0x00817490u);

    // The fourth comparison is nonzero, clearing EBP. JNZ at 0x771acd is not
    // taken; the original returns the still-live metadata allocation.
    return metadata;
}
}
