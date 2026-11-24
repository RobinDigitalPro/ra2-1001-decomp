#include "recovered/text_trim.hpp"

#include <cstddef>

namespace ra2::recovered {

std::uint8_t* fun_006e41d0(std::uint8_t* text) {
    if (text == nullptr) return nullptr;

    // The original keeps this pointer in EBX across the shift. It is not
    // rebased to text after the forward copy and is tested again for every
    // byte removed from the end.
    std::uint8_t* const leading_skip = [&]() {
        std::uint8_t* cursor = text;
        if (*cursor != 0) {
            while (*cursor <= 0x20) {
                ++cursor;
                if (*cursor == 0) break;
            }
        }
        return cursor;
    }();

    if (leading_skip != text) {
        // REP MOVSD/MOVSB performs a forward copy, including its NUL. Reading
        // before each write keeps the overlapping source/destination valid.
        auto* source = leading_skip;
        auto* destination = text;
        std::uint8_t byte;
        do {
            byte = *source++;
            *destination++ = byte;
        } while (byte != 0);
    }

    std::size_t length = 0;
    while (text[length] != 0) ++length;

    // The machine loop starts at the final non-NUL byte. Its first condition
    // checks the still-aliased leading_skip pointer before testing the byte.
    while (length != 0 && *leading_skip != 0 && text[length - 1] <= 0x20) {
        text[length - 1] = 0;
        --length;
    }

    return text;
}

} // namespace ra2::recovered
