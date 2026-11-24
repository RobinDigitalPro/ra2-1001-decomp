#include "recovered/recovery_b140.hpp"

#include <array>
#include <cstddef>
#include <stdexcept>

namespace ra2::recovered::recovery_b140 {
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

std::uint32_t fun_0075af50(
    ra2::recovered::global_b26::Memory& memory,
    const ra2::recovered::global_b26::Inputs& inputs,
    ra2::platform::small_crt_heap::Heap& heap) {
    const auto receiver = inputs.cx;
    require(receiver != 0, "bounded route requires a writable receiver");

    // The original first builds %0Nd, then uses that same 16-byte scratch as
    // destination and format. Restricting the result to four bytes preserves
    // the format's NUL at offset four when its state machine reads it.
    const auto value=ra2::recovered::global_b26::s32(inputs.dx);
    require(value>=-999&&value<=9999&&inputs.arg[0]<=4,"140 finite value/width domain");
    std::array<char,16> plain{},scratch{};
    const auto raw_count=format_default_decimal(inputs.dx,plain);
    const auto length=raw_count-1, width=inputs.arg[0];
    const auto padding=width>length?width-length:0;
    std::size_t src=0,dst=0;
    if(plain[0]=='-'){scratch[dst++]='-';++src;}
    for(std::size_t k=0;k<padding;++k)scratch[dst++]='0';
    while(src<length)scratch[dst++]=plain[src++];
    scratch[dst]=0;
    require(dst<=4,"140 overlapping format terminator bound");
    const auto copy_count=dst+1;

    // Successful-path order: clear published pointer, request strlen+1 from
    // the real CRT boundary, publish the allocation, clear byte zero, then
    // copy the complete NUL-terminated payload.
    memory.w32(receiver, 0);                    // root clears receiver before allocation
    const auto allocation = heap.allocate(static_cast<std::uint32_t>(copy_count));
    require(allocation != 0, "successful genuine heap allocation is required");
    memory.w32(receiver, allocation);           // root publishes the real result
    heap.w8(allocation, 0);                     // original initial NUL store
    for (std::size_t offset = 0; offset < copy_count; ++offset)
        heap.w8(allocation + static_cast<std::uint32_t>(offset),
                static_cast<std::uint8_t>(scratch[offset]));

    return receiver;                             // 0x75afdb: EAX=EBX receiver; RET 4
}

} // namespace ra2::recovered::recovery_b140
