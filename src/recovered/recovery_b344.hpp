#pragma once

#include "recovered/global_b27_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b344 {
using Memory = global_b27::Memory;
using State = global_b27::State;

// The only API boundary required by this recovered body. A native test adapter
// must forward to the actual KERNEL32!GetLocaleInfoA, never synthesize output.
struct LocaleInfoAForwarder {
    std::uint32_t (*call)(void* context, std::uint32_t lcid,
                          std::uint32_t lctype, std::uint32_t output_guest,
                          std::uint32_t capacity) = nullptr;
    void* context = nullptr;
};

// The caller provides State.bp and mapped guest stack memory containing the
// original local buffer at EBP-0x78. State.arg[0] is the sole caller word.
void fun_0077b314(Memory&, State&, const LocaleInfoAForwarder&);
}
