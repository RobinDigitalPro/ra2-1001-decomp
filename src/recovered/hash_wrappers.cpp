#include "recovered/hash_wrappers.hpp"

#include <array>
#include <limits>
#include <stdexcept>
#include <string>

namespace ra2::recovered {
namespace {

template <std::size_t Width>
std::uint32_t append_raw(NameHashState& state, std::uint64_t bits) {
    std::array<std::uint8_t, Width> bytes{};
    for (std::size_t i = 0; i < Width; ++i)
        bytes[i] = static_cast<std::uint8_t>(bits >> (i * 8));
    return fun_00493da0(state, bytes.data(), static_cast<std::int32_t>(Width));
}

} // namespace

std::uint32_t fun_00493cf0(NameHashState& state, std::uint32_t raw_bits) {
    return append_raw<2>(state, raw_bits & 0xffffu);
}

std::uint32_t fun_00493d10(NameHashState& state, std::uint32_t raw_bits) {
    return append_raw<4>(state, raw_bits);
}

std::uint32_t fun_00493d30(NameHashState& state, std::uint32_t raw_bits) {
    return append_raw<4>(state, raw_bits);
}

std::uint32_t fun_00493d50(NameHashState& state, std::uint64_t raw_bits) {
    return append_raw<8>(state, raw_bits);
}

std::optional<std::uint32_t> fun_00493d70(NameHashState& state, const char* text) {
    if (text == nullptr) return std::nullopt;
    const auto length = std::char_traits<char>::length(text);
    if (length > static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max()))
        throw std::length_error("hash text exceeds the signed original length");
    return fun_00493da0(state, reinterpret_cast<const std::uint8_t*>(text),
                        static_cast<std::int32_t>(length));
}

} // namespace ra2::recovered
