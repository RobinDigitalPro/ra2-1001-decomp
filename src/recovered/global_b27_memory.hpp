#pragma once
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>

// Draft Block27 machine-state interface. No class names or source ABI inferred.
namespace ra2::recovered::global_b27 {
using Memory = global_b26::Memory;
using global_b26::s32;
using global_b26::sx16;
using global_b26::sar;
using global_b26::imul_high;

struct State {
    std::uint32_t ax{}, cx{}, dx{}, bx{}, bp{}, si{}, di{};
    std::array<std::uint32_t,16> arg{};
    std::uint32_t arithmetic_flags{};
    // Platform input for the original EFLAGS AC/ID availability probe. A native
    // adapter must establish this capability separately from the recovered body.
    std::uint32_t flag_toggle_mask{};
};

using Function = void (*)(Memory&, State&);
using NonReturningFunction = void (*)();
// Explicit guest stack transition for the original page-probing allocator.
// entry_sp/return_address are boundary inputs; exit_sp/next_ip are outputs.
struct StackContext {
    std::uint32_t entry_sp{}, return_address{}, exit_sp{}, next_ip{};
};
using StackFunction = void (*)(Memory&, State&, StackContext&);
struct Entry {
    std::uint32_t rva;
    Function function;
    NonReturningFunction nonreturning = nullptr;
    StackFunction stack_function = nullptr;
};

inline std::uint32_t with_al(std::uint32_t ax, std::uint32_t al) {
    return (ax & 0xffffff00u) | (al & 0xffu);
}
inline std::uint32_t with_ax(std::uint32_t eax, std::uint32_t ax) {
    return (eax & 0xffff0000u) | (ax & 0xffffu);
}

const std::array<Entry,24>& entries_a();
const std::array<Entry,24>& entries_b();
const std::array<Entry,24>& entries_c();
} // namespace ra2::recovered::global_b27
