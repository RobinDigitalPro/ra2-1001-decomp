#pragma once
#include "recovered/global_b27_memory.hpp"

// Numeric original-machine state; no source class or calling convention inferred.
namespace ra2::recovered::global_b28 {
using Memory = global_b27::Memory;
using State = global_b27::State;
using global_b27::s32;
using global_b27::sx16;
using global_b27::sar;
using global_b27::imul_high;
using global_b27::with_al;
using global_b27::with_ax;
using Function = void (*)(Memory&, State&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,13>& entries_a();
const std::array<Entry,13>& entries_b();
} // namespace ra2::recovered::global_b28
