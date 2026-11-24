#pragma once
#include "recovery_b145.hpp"
#include <stdexcept>
// Reused mode-zero comparator from accepted crt_b83.cpp; source evidence retained.
namespace ra2::recovered::recovery_b145::lookup {
inline std::uint8_t lower(std::uint8_t c){return c>='A'&&c<='Z'?std::uint8_t(c+32):c;}
inline std::uint32_t fun_0076d860(Memory& m, const Inputs& i) {
    if(m.r32(0xb10530)!=0)throw std::domain_error("145 requires original mode-zero comparator");
    std::uint32_t a = i.arg[0], b = i.arg[1];
    for (unsigned n = 0; n < 8; ++n) {
        const auto x = static_cast<std::uint8_t>(m.r8(a++));
        const auto y = static_cast<std::uint8_t>(m.r8(b++));
        if (x == y) {
            if (!x) return 0;
            continue;
        }
        const auto lx = lower(x), ly = lower(y);
        if (lx != ly) return lx < ly ? 0xffffffffu : 1u;
        if (!lx) return 0;
    }
    return 0;
}

}
