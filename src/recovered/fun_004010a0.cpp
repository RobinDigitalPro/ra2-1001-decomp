#include "recovered/fun_004010a0.hpp"

namespace ra2::recovered {

std::uint32_t fun_004010a0(const void* object) noexcept {
    const auto* bytes = static_cast<const std::uint8_t*>(object);
    if ((bytes[0] & 0x02u) != 0) return 1;
    if ((bytes[0x28] & 0x02u) != 0) return 1;
    if ((bytes[0x50] & 0x02u) != 0) return 1;
    return 0;
}

} // namespace ra2::recovered
