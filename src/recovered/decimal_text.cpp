#include "recovered/decimal_text.hpp"
namespace ra2::recovered {
std::uint32_t fun_0076e6b2(const std::uint8_t* text, const DecimalOperations& ops) {
    auto byte = *text;
    while (ops.classify(byte, 8, ops.context)) byte = *++text;
    const auto sign = byte;
    ++text;
    if (byte == '+' || byte == '-') byte = *text++;
    std::uint32_t value = 0;
    while (ops.classify(byte, 4, ops.context)) {
        value = 10u * value + static_cast<std::uint32_t>(byte) - 0x30u;
        byte = *text++;
    }
    return sign == '-' ? 0u - value : value;
}
std::uint32_t fun_0076e73d(const std::uint8_t* text, const DecimalOperations& ops) {
    return fun_0076e6b2(text, ops);
}
}
