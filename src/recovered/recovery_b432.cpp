#include "recovery_b432.hpp"
#include "recovered/text_bytes.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovery_b432 {
namespace {
constexpr std::uint32_t table = 0x00817c60u;
constexpr std::uint32_t row_size = 0x2cu;
std::uint32_t selected_source(Memory& m, std::uint32_t row, std::uint32_t type) {
    switch (type) {
    case 1: return row + 0x04u;
    case 3: return row + 0x10u;
    case 7: return row + 0x18u;
    case 11: return row + 0x1cu;
    case 0x1001: return m.r32(row + 0x0cu);
    case 0x1002: return m.r32(row + 0x14u);
    case 0x1004: return row + 0x24u;
    default: return 0;
    }
}
}

std::uint32_t fun_0077b4d1(Memory& m, const Inputs& in) {
    const auto locale = in.arg[0];
    const auto type = in.arg[1];
    const auto destination = in.arg[2];
    const auto capacity = in.arg[3];
    if (capacity == 0 || capacity > 32)
        throw std::domain_error("0x37b4d1 finite route requires capacity 1..32");

    // The original uses a signed midpoint and searches rows 0..26. The table
    // is pinned sorted; keeping this binary search preserves the observed path.
    std::int32_t low = 0, high = 26;
    std::uint32_t source = 0;
    while (low <= high) {
        const auto middle = (low + high) / 2;
        const auto row = table + static_cast<std::uint32_t>(middle) * row_size;
        const auto candidate = m.r32(row);
        if (locale == candidate) {
            source = selected_source(m, row, type);
            break;
        }
        if (locale < candidate) high = middle - 1;
        else low = middle + 1;
    }
    if (source == 0)
        throw std::domain_error("0x37b4d1 excluded locale miss/unsupported information type");

    const auto count = capacity - 1u;
    std::array<std::uint8_t, 64> src{};
    std::array<std::uint8_t, 64> dst{};
    for (unsigned k = 0; k < src.size(); ++k) {
        src[k] = static_cast<std::uint8_t>(m.r8(source + k));
        if (src[k] == 0) break;
    }
    for (unsigned k = 0; k < count; ++k)
        dst[k] = static_cast<std::uint8_t>(m.r8(destination + k));
    // This is the accepted bounded effect of original helper RVA 0x36dd10.
    ra2::recovered::fun_0076dd10(dst.data(), src.data(), count);
    for (unsigned k = 0; k < count; ++k) m.w8(destination + k, dst[k]);
    m.w8(destination + count, 0); // Original AND BYTE [dest+capacity-1],0.
    return 1;                     // Original PUSH 1 / POP EAX.
}
}
