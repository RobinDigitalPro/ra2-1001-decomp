#include "recovery_b753.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::alloc753 {
namespace {
void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

// Positive large-allocation path of original 0x00376f34. The bounded inputs
// keep the 32-bit product below the overflow guard and strictly above the
// initialized CRT threshold, so execution reaches HeapAlloc(flags=8) once.
// Small-block allocation, allocation failure/retry and oversize inputs are
// explicitly outside this route.
std::uint32_t rva_00376f34(Memory& m, const Inputs& i, HeapApi& api) {
    const std::uint64_t wide = std::uint64_t(i.arg[0]) * i.arg[1];
    require(wide <= 0xffffffffull, "B753 product must fit the original 32-bit IMUL result");
    auto requested = static_cast<std::uint32_t>(wide);
    require(requested != 0, "B753 excludes the original zero-size normalization route");
    require(requested > m.r32(0x00817554u),
            "B753 requires a request strictly above the original CRT threshold");
    const std::uint64_t rounded_wide = (std::uint64_t(requested) + 15u) & ~std::uint64_t(15u);
    require(rounded_wide <= 0xffffffe0ull,
            "B753 rounded request must stay below the original overflow guard");
    const auto rounded = static_cast<std::uint32_t>(rounded_wide);
    const auto heap = m.r32(0x00b10e1cu);
    require(heap != 0, "B753 requires an initialized nonnull CRT heap handle");
    const auto result = api.heap_alloc(heap, 0x8u, rounded);
    require(result != 0, "B753 bounded route is the successful HeapAlloc path");
    return result;
}
}
