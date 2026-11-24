#pragma once

#include <cstdint>

namespace ra2::recovered {

// Portable byte-oriented views of bounded original string helpers. These
// functions model buffer effects and return values only; no original class,
// C++ type spelling, or x86 calling convention is asserted. For positive
// counts, pointers must designate the required readable/writable buffers;
// source/destination overlap and address wraparound are outside this view.

// RVA 0x36dd10 (VA 0x76dd10): copy at most count bytes, zero-pad after a
// copied NUL, and do not append a terminator when count bytes are exhausted.
std::uint8_t* fun_0076dd10(std::uint8_t* destination,
                           const std::uint8_t* source,
                           std::uint32_t count);

// RVA 0x375160 (VA 0x775160): length before the first NUL byte.
std::uint32_t fun_00775160(const std::uint8_t* text);

// RVA 0x36d930 (VA 0x76d930): last occurrence of target's low byte,
// searching through the terminating NUL as well.
const std::uint8_t* fun_0076d930(const std::uint8_t* text,
                                 std::int32_t target);

// RVA 0x36f150 (VA 0x76f150): bounded unsigned-byte comparison returning
// exactly -1, 0, or +1. Count zero reads neither input.
std::int32_t fun_0076f150(const std::uint8_t* first,
                          const std::uint8_t* second,
                          std::uint32_t count);

// RVA 0x370050 (VA 0x770050): append at most count source bytes, then NUL.
// Count zero returns destination without reading or writing either pointer.
std::uint8_t* fun_00770050(std::uint8_t* destination,
                           const std::uint8_t* source,
                           std::uint32_t count);

// RVA 0x36ef45 (VA 0x76ef45): length before the first zero 16-bit unit.
std::uint32_t fun_0076ef45(const std::uint16_t* text);

// RVA 0x36ef62 (VA 0x76ef62): bounded 16-bit copy with zero padding after a
// copied terminator. Count zero returns destination without touching pointers.
std::uint16_t* fun_0076ef62(std::uint16_t* destination,
                            const std::uint16_t* source,
                            std::uint32_t count);

// RVA 0x35bd70 (VA 0x75bd70): read one contained UTF-16 pointer; a null
// contained value maps to the empty UTF-16 string at original VA 0x82208c.
// This portable view returns its own immutable empty string for that case.
const std::uint16_t* fun_0075bd70(const std::uint16_t* const* contained_pointer);

} // namespace ra2::recovered
