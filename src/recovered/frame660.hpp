#pragma once
#include <cstdint>

namespace heap660_draft {
// Offsets are relative to the actual root entry ESP S. The positive contract
// requires S % 8 == 0, as does the accepted B231 isolated allocator protocol.
inline constexpr std::int32_t root_alloc_entry = -0x1c; // PUSH 1a8; CALL 76d957
inline constexpr std::int32_t root_ctor_entry  = -0x38; // six arguments + saved EBP/EDI; CALL 20110
inline constexpr std::int32_t ctor_scratch     = -0x6c; // align((ctor_entry-4),-8)-2c
inline constexpr std::int32_t alloc_saved_ebx  = -0x60; // alloc_entry-44
inline constexpr std::int32_t alloc_request    = -0x64; // alloc_entry-48
inline constexpr std::int32_t alloc_saved_edi  = -0x68; // alloc_entry-4c
inline constexpr std::uint32_t alloc_request_bytes = 0x1a8;
}
