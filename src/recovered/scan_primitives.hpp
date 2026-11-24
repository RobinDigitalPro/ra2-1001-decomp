#pragma once
#include <cstdint>
namespace ra2::recovered {
// Arithmetic/buffer primitives called by the original formatted scanner.
// Portable value interfaces; original register and stack conventions are
// confined to the differential adapter, not asserted as source-level ABI.
// RVA 0x36da00: low 64 bits of the product (signedness does not affect bits).
std::uint64_t fun_0076da00(std::uint64_t first, std::uint64_t second);
// RVA 0x37dd30: count is the observed CL byte, NOT a masked C++ shift count.
// Counts 64..255 return zero. The original also modifies CL on 32..63 paths;
// that volatile register effect is outside this portable result interface.
std::uint64_t fun_0077dd30(std::uint64_t bits, std::uint8_t count);
// RVA 0x37b620: low eight value bits repeated count times, returning destination.
// Count zero touches no memory. Otherwise count bytes must be writable; pointer
// wraparound/concurrency are excluded. Optimized store widths are not modeled.
std::uint8_t* fun_0077b620(std::uint8_t* destination, std::int32_t value,
                         std::uint32_t count);
}
