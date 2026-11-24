#pragma once

#include <cstdint>

namespace ra2::recovered {

// Portable view of the original single-byte CRT classification table plus an
// explicit multibyte callback seam. This is not an original CRT class/layout
// or calling-convention declaration. For max_character_width <= 1,
// flags_from_minus_one points at the readable entry immediately before byte 0;
// accepted inputs are -1 (EOF) through 255. For wider character sets, the
// callback must be present and supplies the full result bits. It must not
// mutate the input or classification state during a call.
struct CrtClassification {
    std::int32_t max_character_width;
    const std::uint16_t* flags_from_minus_one;
    std::uint32_t (*multibyte)(std::int32_t, std::uint32_t, void*);
    void* context;
};

// Original RVAs: 0x36e44e (mask 0x103), 0x36e4cc (0x4),
// 0x36e4f4 (0x80), 0x36e521 (0x8), 0x36e571 (0x107), 0x36e5cd (0x117).
// Table-path return is the selected mask bits from the 16-bit table entry.
// When max_character_width > 1, return the callback's full 32-bit result.
std::uint32_t fun_0076e44e(std::int32_t input, const CrtClassification& ops);
std::uint32_t fun_0076e4cc(std::int32_t input, const CrtClassification& ops);
std::uint32_t fun_0076e4f4(std::int32_t input, const CrtClassification& ops);
std::uint32_t fun_0076e521(std::int32_t input, const CrtClassification& ops);
std::uint32_t fun_0076e571(std::int32_t input, const CrtClassification& ops);
std::uint32_t fun_0076e5cd(std::int32_t input, const CrtClassification& ops);

// Original RVA 0x375cf2 (VA 0x775cf2): if mask-4 classification is nonzero,
// preserve input bits; otherwise clear bit 5 and subtract 7 modulo 2^32.
std::uint32_t fun_00775cf2(std::int32_t input, const CrtClassification& ops);

} // namespace ra2::recovered
