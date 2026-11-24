#pragma once

#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b251_lookup {
using Memory = ra2::recovered::global_b26::Memory;

// Guest pointers name the live, original-layout INI graph and NUL-terminated
// strings. The finite graph has exactly one sorted Intro section and one
// sorted ItemMax key; results are actual translated lookup/parser results.
// Cache/sorted mutations from the recovered lookup helpers are flushed to the
// guest graph before returning.
std::uint32_t query_section(Memory&, std::uint32_t root_index,
                            std::uint32_t section_name_z);
std::uint32_t read_integer(Memory&, std::uint32_t root_index,
                           std::uint32_t section_name_z,
                           std::uint32_t key_name_z,
                           std::uint32_t fallback);
} // namespace ra2::recovered::recovery_b251_lookup
