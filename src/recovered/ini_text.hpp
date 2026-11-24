#pragma once
#include "recovered/ini_lookup.hpp"
namespace ra2::recovered {
// RVA 0x10ddf0, receiver+0x20 adapted as section_index. Null output, count < 2
// (signed), or either null name returns 0 without touching output or receiver.
// Otherwise output has count writable bytes. Names and selected text are
// readable NUL-terminated buffers; no overlap with output/state, pointer wrap,
// concurrent mutation, or overflowing name lengths is supported. The index
// and callback requirements are those of ini_lookup.hpp. This is a portable
// structural view, not a class declaration or ABI-compatible game interface.
std::int32_t fun_0050ddf0(IniIndex* section_index,
    const std::uint8_t* section, const std::uint8_t* key,
    const std::uint8_t* fallback, std::uint8_t* output, std::int32_t count,
    const IniOperations&);
}
