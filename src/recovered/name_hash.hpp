#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace ra2::recovered {

// Logical state view, not an original class declaration. Observed x86 fields:
// accumulator +0, pending byte count +4, scratch bytes +8..11. Filling a
// previously partial block also writes byte +12 = 4; preserve it explicitly.
struct NameHashState {
    std::uint32_t accumulator;
    std::uint32_t pending; // Entry precondition: 0..3.
    std::array<std::uint8_t, 4> scratch;
    std::uint8_t completion_byte;
};

// RVA 0x93f70: raw reflected CRC update, initial/final complement, no padding.
// bytes must name length readable bytes; nullptr is allowed when length == 0.
std::uint32_t fun_00493f70(const std::uint8_t* bytes, std::uint32_t length,
                         std::uint32_t seed);

// RVA 0x93da0: consume full groups and retain 1..3 pending bytes. The returned
// value includes a padded pending group, but that group's CRC is NOT committed
// to accumulator; pending remains unchanged and scratch padding IS modified.
// Null bytes or signed length <= 0 skip ingestion, but still finalize pending
// scratch. Buffers must be readable and not overlap state; count outside 0..3,
// pointer wraparound and concurrent mutation are excluded. No class/ABI claim.
std::uint32_t fun_00493da0(NameHashState& state, const std::uint8_t* bytes,
                         std::int32_t length);

// Fresh-state adapter for IniOperations::hash_name. This adapter is not another
// recovered function. Throws length_error for lengths above INT32_MAX.
std::uint32_t ini_name_hash(const std::uint8_t* bytes, std::size_t length, void*);

} // namespace ra2::recovered
