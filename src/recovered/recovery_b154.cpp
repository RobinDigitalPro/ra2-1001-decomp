#include "recovered/recovery_b154.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b154 {
std::uint32_t fun_006681b0(Memory& m, const Inputs& i) {
    const auto key = i.arg[0];
    if (key == 0xfffffffeu)
        throw std::domain_error("Block154 excludes the special -2 path with unresolved helper/vcall");

    const auto count = m.r32(i.cx + 0x198u);
    const auto items = m.r32(i.cx + 0x18cu);
    if (count == 0u || count > 32u || (count != 0u && items == 0u))
        throw std::domain_error("Block154 requires count 1..32 and a mapped array when nonempty");

    // First original pass searches for the unconditional -1 sentinel.
    for (std::uint32_t index = 0; index < count; ++index) {
        if (m.r32(items + index * 4u) == 0xffffffffu)
            return 1u;
    }

    // Only if no sentinel exists, the second original pass searches for key.
    for (std::uint32_t index = 0; index < count; ++index) {
        if (m.r32(items + index * 4u) == key)
            return 1u;
    }
    return 0u;
}
}
