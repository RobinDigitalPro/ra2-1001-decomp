#include "recovered/recovery_b139.hpp"

#include <array>
#include <cstddef>
#include <stdexcept>

namespace ra2::recovered::recovery_b139 {
namespace {

// Matches the literal default %d path in 0x371e65. Its local scratch is 16
// bytes; the longest signed int32 string and NUL require 12 bytes.
std::size_t format_default_decimal(std::uint32_t bits,
                                   std::array<char, 16>& scratch) {
    const auto value = ra2::recovered::global_b26::s32(bits);
    const bool negative = value < 0;
    // Unsigned negation handles INT32_MIN without signed overflow.
    std::uint32_t magnitude = negative ? (0u - bits) : bits;

    std::array<char, 10> reversed{};
    std::size_t digit_count = 0;
    do {
        const auto digit = magnitude % 10u;
        reversed[digit_count++] = static_cast<char>('0' + digit);
        magnitude /= 10u;
    } while (magnitude != 0);

    std::size_t length = 0;
    if (negative) scratch[length++] = '-';
    while (digit_count != 0) scratch[length++] = reversed[--digit_count];
    scratch[length] = '\0';
    return length + 1u; // allocation/copy count includes the terminator
}

void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

} // namespace

std::uint32_t fun_0075aec0(
    ra2::recovered::global_b26::Memory& memory,
    const ra2::recovered::global_b26::Inputs& inputs,
    ra2::platform::small_crt_heap::Heap& heap) {
    const auto receiver = inputs.cx;
    require(receiver != 0, "bounded route requires a writable receiver");

    // Original 0x35aec0 formats into its 16-byte local scratch before touching
    // [receiver]. Literal %d uses full signed EDX; low-word narrowing is only
    // present on the separate %hd formatter path.
    std::array<char, 16> scratch{};
    const auto copy_count = format_default_decimal(inputs.dx, scratch);
    require(copy_count >= 2u && copy_count <= 12u,
            "signed 32-bit decimal length is outside local-buffer contract");

    // Successful-path order: clear published pointer, request strlen+1 from
    // the real CRT boundary, publish the allocation, clear byte zero, then
    // copy the complete NUL-terminated payload.
    memory.w32(receiver, 0);                    // 0x75aee0
    const auto allocation = heap.allocate(static_cast<std::uint32_t>(copy_count));
    require(allocation != 0, "successful genuine heap allocation is required");
    memory.w32(receiver, allocation);           // 0x75af09
    heap.w8(allocation, 0);                     // 0x75af0b
    for (std::size_t offset = 0; offset < copy_count; ++offset)
        heap.w8(allocation + static_cast<std::uint32_t>(offset),
                static_cast<std::uint8_t>(scratch[offset]));

    return receiver;                             // 0x75af3d: EAX=ECX, RET 0
}

} // namespace ra2::recovered::recovery_b139
