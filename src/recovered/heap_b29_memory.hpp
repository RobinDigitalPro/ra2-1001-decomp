#pragma once
#include "recovered/global_b27_memory.hpp"
#include <stdexcept>

namespace ra2::recovered::heap_b29 {
inline constexpr std::uint32_t arena_bytes = 0x100000u;
using Memory = global_b27::Memory;
using State = global_b27::State;
using global_b27::s32;
using global_b27::sx16;
using global_b27::sar;
using global_b27::imul_high;
using global_b27::with_al;
using global_b27::with_ax;

// Paired test boundary at the deeper CRT entry. This is not a recovered heap.
// The native adapter preserves nonvolatile registers, returns this EDX:EAX pair,
// and supplies clear arithmetic condition flags before the original wrapper RET.
struct BoundaryResult { std::uint32_t ax, dx; };
struct Operations {
    BoundaryResult (*invoke)(Memory&, std::uint32_t kind, std::uint32_t argument,
                             std::uint32_t flag, void* context);
    void* context;
};
inline void release(Memory& m, State& s, const Operations& op, std::uint32_t pointer) {
    if (!op.invoke) throw std::invalid_argument("missing controlled heap boundary");
    const auto result = op.invoke(m, 0u, pointer, 0u, op.context);
    s.ax = result.ax; s.dx = result.dx;
    s.cx = pointer; // Original 36d67b POP ECX after the deeper call.
}
inline void allocate(Memory& m, State& s, const Operations& op, std::uint32_t size) {
    if (!op.invoke) throw std::invalid_argument("missing controlled heap boundary");
    const auto result = op.invoke(m, 1u, size, 1u, op.context);
    s.ax = result.ax; s.dx = result.dx;
    s.cx = 1u; // Original 36d957's second POP ECX consumes the literal flag.
}
struct CaseOptions {
    std::uint32_t max_calls = 64;
    std::uint64_t null_allocations = 0; // Only explicitly valid NULL-return paths.
    std::uint32_t allocation_base = 0;
    std::uint32_t allocation_stride = 0x800;
};
using Function = void (*)(Memory&, State&, const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,43>& entries_a();
const std::array<Entry,43>& entries_b();
const std::array<Entry,26>& entries_c();
} // namespace ra2::recovered::heap_b29
