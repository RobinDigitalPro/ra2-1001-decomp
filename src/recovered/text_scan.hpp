#pragma once

#include <cstdint>

namespace ra2::recovered {

// Original GAME.EXE RVA 0x36fa70. Search the NUL-terminated byte string for
// the first byte equal to target's low eight bits, including the NUL byte.
// The input must be a valid readable NUL-terminated span; optimized access
// widths and fault timing of the original are outside this scalar view.
const std::uint8_t* fun_0076fa70(const std::uint8_t* text,
                                 std::int32_t target);

// Original GAME.EXE RVA 0x10fbb0. If a semicolon exists, replace the first
// one with NUL and pass the original buffer to fun_006e41d0. Without a
// semicolon the buffer is unchanged. Null is a no-op.
void fun_0050fbb0(std::uint8_t* text);

// Original GAME.EXE RVA 0x10fb00. Scan columns, tracking the first '=' and
// comment ';' and a candidate value column. Outputs are initialized and
// finalized in instruction order; output pointers may alias each other but
// must not alias the input. Input must be finite, readable, NUL-terminated.
const std::uint8_t* fun_0050fb00(const std::uint8_t* text,
                                 std::uint32_t* equal_column,
                                 std::uint32_t* value_column,
                                 std::uint32_t* comment_column);

} // namespace ra2::recovered
