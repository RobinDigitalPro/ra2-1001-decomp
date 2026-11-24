#include "recovered/text_bytes.hpp"

namespace ra2::recovered {
namespace {
constexpr std::uint16_t empty_wide_string[] = {0};
}

std::uint8_t* fun_0076dd10(std::uint8_t* destination,
                           const std::uint8_t* source,
                           std::uint32_t count) {
    if (count == 0) return destination;
    std::uint32_t i = 0;
    for (; i < count; ++i) {
        const auto value = source[i];
        destination[i] = value;
        if (value == 0) {
            ++i;
            for (; i < count; ++i) destination[i] = 0;
            break;
        }
    }
    return destination;
}

std::uint32_t fun_00775160(const std::uint8_t* text) {
    std::uint32_t length = 0;
    while (text[length] != 0) ++length;
    return length;
}

const std::uint8_t* fun_0076d930(const std::uint8_t* text,
                                 std::int32_t target) {
    const auto wanted = static_cast<std::uint8_t>(static_cast<std::uint32_t>(target));
    const auto length = fun_00775160(text);
    const std::uint8_t* last = nullptr;
    for (std::uint32_t i = 0; i <= length; ++i)
        if (text[i] == wanted) last = text + i;
    return last;
}

std::int32_t fun_0076f150(const std::uint8_t* first,
                          const std::uint8_t* second,
                          std::uint32_t count) {
    for (std::uint32_t i = 0; i < count; ++i) {
        const auto a = first[i];
        const auto b = second[i];
        if (a != b) return a < b ? -1 : 1;
        if (a == 0) return 0;
    }
    return 0;
}

std::uint8_t* fun_00770050(std::uint8_t* destination,
                           const std::uint8_t* source,
                           std::uint32_t count) {
    if (count == 0) return destination;
    std::uint32_t end = 0;
    while (destination[end] != 0) ++end;
    for (std::uint32_t copied = 0; copied < count; ++copied) {
        const auto value = source[copied];
        destination[end + copied] = value;
        if (value == 0) return destination;
    }
    destination[end + count] = 0;
    return destination;
}

std::uint32_t fun_0076ef45(const std::uint16_t* text) {
    std::uint32_t length = 0;
    while (text[length] != 0) ++length;
    return length;
}

std::uint16_t* fun_0076ef62(std::uint16_t* destination,
                            const std::uint16_t* source,
                            std::uint32_t count) {
    if (count == 0) return destination;
    std::uint32_t i = 0;
    for (; i < count; ++i) {
        const auto value = source[i];
        destination[i] = value;
        if (value == 0) {
            ++i;
            for (; i < count; ++i) destination[i] = 0;
            break;
        }
    }
    return destination;
}

const std::uint16_t* fun_0075bd70(const std::uint16_t* const* contained_pointer) {
    return *contained_pointer != nullptr ? *contained_pointer : empty_wide_string;
}

} // namespace ra2::recovered
