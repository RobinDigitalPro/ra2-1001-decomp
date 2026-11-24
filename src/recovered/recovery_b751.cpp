#include "recovery_b751.hpp"

#include "recovered/recovery_b278.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::free751 {
namespace {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;

void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

std::uint32_t wide_length(Memory& m, std::uint32_t source) {
    require(source != 0, "B751 requires a nonnull UTF-16 string");
    for (std::uint32_t n = 0; n < 1033; ++n) {
        const auto ch = m.r16(source + n * 2u);
        if (ch == 0) return n;
        require(ch == static_cast<std::uint16_t>('A'),
                "B751 finite miss route uses only ASCII A code units");
    }
    throw std::domain_error("B751 bounded UTF-16 terminator absent");
}

bool equal_original_byte_strings(Heap& heap, Memory& m, std::uint32_t left,
                                 std::uint32_t right) {
    // Exact 0x359340 byte-pair stepping: each iteration reads two bytes,
    // compares the first and then the second, and returns true only at NUL.
    for (std::uint32_t n = 0; n < 4096; n += 2) {
        const auto a0 = heap.r8(left + n), b0 = m.r8(right + n);
        if (a0 != b0) return false;
        if (a0 == 0) return true;
        const auto a1 = heap.r8(left + n + 1), b1 = m.r8(right + n + 1);
        if (a1 != b1) return false;
        if (a1 == 0) return true;
    }
    throw std::domain_error("B751 byte comparison exceeded its finite bound");
}
}

std::uint32_t rva_001c5a80(Memory& original, const Inputs& i, Heap& heap) {
    Memory m = original;
    const auto object = i.cx;
    require(object != 0 && (i.arithmetic_flags & 0x400u) == 0,
            "B751 route requires a nonnull object and DF clear");
    const auto source = m.r32(object);
    const auto units = wide_length(m, source);
    require(units >= 1017u && units <= 1032u,
            "B751 route requires 1017..1032 wide ASCII units");

    // The original root passes its saved-ECX stack slot as the output pointer
    // cell to 0x35cbc0. Keep that local storage private to this model call;
    // it is not guest arena memory and is not returned to the caller.
    constexpr std::uint32_t scratch_base = 0xf1100000u;
    std::array<std::uint8_t, 16> scratch_bytes{};
    ra2::recovered::leaf::Memory scratch(scratch_bytes.data(), scratch_base,
                                         static_cast<std::uint32_t>(scratch_bytes.size()));
    m.add(scratch);
    const auto output_cell = scratch_base + 4u;
    (void)m.r32(output_cell); // private stack-local shadow, absent from caller memory
    Inputs convert{};
    convert.cx = output_cell;
    convert.dx = object;
    convert.arithmetic_flags = i.arithmetic_flags;
    const auto helper_eax = ra2::recovered::recovery_b278::rva_0035cbc0(m, convert, heap);
    require(helper_eax == output_cell, "B751 0x35cbc0 return-cell ABI");
    const auto converted = m.r32(output_cell);
    require(converted != 0, "B751 conversion produced a null result");

    // The authoritative initialized PE bytes at 0x7d11c8..0x7d11dc point to
    // six NUL-terminated names, all beginning with '@'. The supported input
    // starts with 'A', so each original full-string comparison rejects at
    // its first byte and control reaches 0x359320 with the converted pointer.
    constexpr std::array<std::uint32_t, 6> name_cells{
        0x007d11c8u, 0x007d11ccu, 0x007d11d0u,
        0x007d11d4u, 0x007d11d8u, 0x007d11dcu};
    for (const auto cell : name_cells) {
        const auto literal = m.r32(cell);
        require(literal != 0 && m.r8(literal) == static_cast<std::uint8_t>('@'),
                "B751 pinned literal-table identity/content changed");
        require(!equal_original_byte_strings(heap, m, converted, literal),
                "B751 finite route unexpectedly matched a table name");
    }

    require(heap.release(converted) != 0,
            "B751 original final 0x359320 HeapFree must succeed");
    m.w32(output_cell, 0);
    return 0; // original six-comparison miss route XORs EAX,EAX
}
}
