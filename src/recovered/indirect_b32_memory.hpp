#pragma once
#include "recovered/indirect_b31_memory.hpp"

namespace ra2::recovered::indirect_b32 {
// Reuse the already checked guest-stack primitives. The caller bodies below
// may invoke their controlled boundary repeatedly; no callee ABI is inferred.
using indirect_b31::Memory;
using indirect_b31::State;
using indirect_b31::Frame;
using indirect_b31::Call;
using indirect_b31::Operations;
using indirect_b31::invoke;
using indirect_b31::finish;
using indirect_b31::s32;
using indirect_b31::sar;
using indirect_b31::with_al;
using indirect_b31::with_ax;
using indirect_b31::arena_bytes;
using Function = void (*)(Memory&, State&, Frame&, const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,13>& entries_a();
const std::array<Entry,13>& entries_b();
const std::array<Entry,11>& entries_c();
} // namespace ra2::recovered::indirect_b32
