#include "recovered/fun_00412390.hpp"

namespace ra2::recovered {
namespace {

std::int32_t sign_extend_byte(std::uint8_t value) noexcept {
    return value < 0x80u ? static_cast<std::int32_t>(value)
                         : static_cast<std::int32_t>(value) - 0x100;
}

} // namespace

std::uint32_t fun_00412390(const std::uint8_t* input, const HexCharacterOps& ops) {
    std::uint32_t result = 0;
    while (input != nullptr) {                                      // 0x412396, 0x4123d1
        if (ops.classify_hex(sign_extend_byte(*input), ops.context) == 0) {
            break;                                                 // 0x41239a..0x4123a8
        }
        // Assembly reloads the byte after classification; preserve this even
        // when the callback changes the input buffer.
        const std::int32_t character = sign_extend_byte(*input);     // 0x4123aa
        result <<= 4;                                              // 0x4123ac
        ++input;                                                   // 0x4123af
        if (character >= 0x30 && character <= 0x39) {
            result += static_cast<std::uint32_t>(character) - 0x30u; // 0x4123b0..0x4123bf
        } else {
            result += static_cast<std::uint32_t>(
                ops.uppercase(character, ops.context)) - 0x37u;     // 0x4123c1..0x4123cd
        }
    }
    return result;                                                 // 0x4123d5
}

} // namespace ra2::recovered
