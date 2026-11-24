#include "recovered/scan_primitives.hpp"
namespace ra2::recovered {
std::uint64_t fun_0076da00(std::uint64_t first, std::uint64_t second) {
    return first * second; // Defined unsigned modulo-2^64 arithmetic.
}
std::uint64_t fun_0077dd30(std::uint64_t bits, std::uint8_t count) {
    return count >= 64 ? 0 : bits << count;
}
std::uint8_t* fun_0077b620(std::uint8_t* destination, std::int32_t value,
                         std::uint32_t count) {
    const auto byte = static_cast<std::uint8_t>(static_cast<std::uint32_t>(value));
    for (std::uint32_t i = 0; i < count; ++i) destination[i] = byte;
    return destination;
}
}
