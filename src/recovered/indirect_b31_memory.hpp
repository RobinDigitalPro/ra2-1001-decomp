#pragma once
#include "recovered/global_b27_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::indirect_b31 {
using Memory = global_b27::Memory;
using State = global_b27::State;
using global_b27::s32;
using global_b27::sar;
using global_b27::with_al;
using global_b27::with_ax;
inline constexpr std::uint32_t arena_bytes = 0x100000u;

// Guest stack addresses preserve instruction-level aliases. These fields do
// not assert an original C++ class layout or a general callback ABI.
struct Frame {
    std::uint32_t entry_sp{}, sp{}, outer_return{}, call_return{};
    std::uint32_t callback_cleanup{}, argument_words{};
    void push(Memory& m, std::uint32_t value) { sp -= 4u; m.w32(sp, value); }
    std::uint32_t pop(Memory& m) { const auto value=m.r32(sp); sp+=4u; return value; }
};
struct Call {
    std::uint32_t target{}, sp{}, return_address{}, argument_words{}, cleanup{};
};
struct Operations {
    void (*invoke)(Memory&, State&, const Call&, void* context);
    void* context;
};
struct CaseOptions {
    std::uint32_t result_ax{}, result_cx{}, result_dx{};
    bool write_enabled{};
    std::uint32_t write_address{}, write_value{};
    // Independent fixture expectation, checked by both portable/native runners.
    std::uint32_t expected_calls{};
};
inline void invoke(Memory& m, State& s, Frame& f, const Operations& op,
                   std::uint32_t target) {
    if (!op.invoke || f.argument_words>16u || f.callback_cleanup>64u ||
        (f.callback_cleanup&3u)) throw std::invalid_argument("invalid B31 indirect boundary");
    f.push(m, f.call_return);
    op.invoke(m,s,{target,f.sp,f.call_return,f.argument_words,f.callback_cleanup},op.context);
    if(f.pop(m)!=f.call_return)throw std::runtime_error("B31 callback changed continuation");
    f.sp += f.callback_cleanup;
}
inline void finish(Memory& m, State& s, Frame& f, std::uint32_t cleanup) {
    if(f.sp!=f.entry_sp || f.pop(m)!=f.outer_return)
        throw std::runtime_error("B31 caller stack/continuation differs");
    f.sp += cleanup;
    for(unsigned i=0;i<s.arg.size();++i)s.arg[i]=m.r32(f.entry_sp+4u+4u*i);
}
using Function = void (*)(Memory&, State&, Frame&, const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,54>& entries_a();
const std::array<Entry,54>& entries_b();
const std::array<Entry,53>& entries_c();
} // namespace ra2::recovered::indirect_b31
