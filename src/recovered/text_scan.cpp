#include "recovered/text_scan.hpp"

#include "recovered/text_trim.hpp"

namespace ra2::recovered {

const std::uint8_t* fun_0076fa70(const std::uint8_t* text,
                                 std::int32_t target) {
    const auto wanted = static_cast<std::uint8_t>(static_cast<std::uint32_t>(target) & 0xffu);
    for (const std::uint8_t* current = text;; ++current) {
        if (*current == wanted) return current;
        if (*current == 0) return nullptr;
    }
}

void fun_0050fbb0(std::uint8_t* text) {
    if (text == nullptr) return;
    const auto* semicolon = fun_0076fa70(text, ';');
    if (semicolon == nullptr) return;
    *const_cast<std::uint8_t*>(semicolon) = 0;
    (void)fun_006e41d0(text);
}

const std::uint8_t* fun_0050fb00(const std::uint8_t* text,
                                 std::uint32_t* equal_column,
                                 std::uint32_t* value_column,
                                 std::uint32_t* comment_column) {
    *equal_column = 0xffffffffu;
    *value_column = 0xffffffffu;
    *comment_column = 0xffffffffu;

    std::uint32_t column = 0;
    const std::uint8_t* current = text;
    std::uint8_t byte = *current;
    bool found_comment = false;
    while (byte != 0) {
        if ((*equal_column & 0x80000000u) == 0 &&
            (*value_column & 0x80000000u) != 0 && byte > 0x20u) {
            *value_column = column;
        }

        byte = *current;
        if (byte == ';') {
            *comment_column = column;
            current += 1;
            found_comment = true;
            goto finish;
        }
        if (byte == '\t') {
            column = (column & 0xfffffff8u) + 8u;
        } else if (byte == '=') {
            if ((*equal_column & 0x80000000u) != 0) {
                *equal_column = column;
            }
            column += 1u;
        } else {
            column += 1u;
        }
        byte = current[1];
        ++current;
    }

finish:
    if ((*equal_column & 0x80000000u) != 0) *equal_column = 0;
    if ((*value_column & 0x80000000u) != 0) *value_column = 0;
    if ((*comment_column & 0x80000000u) != 0) *comment_column = 0;
    return found_comment ? current : nullptr;
}

} // namespace ra2::recovered
