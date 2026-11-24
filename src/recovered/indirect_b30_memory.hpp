#pragma once
#include "recovered/global_b27_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::indirect_b30 {
using Memory = global_b27::Memory;
using State = global_b27::State;
using global_b27::s32;
using global_b27::sar;
using global_b27::with_al;
using global_b27::with_ax;
inline constexpr std::uint32_t arena_bytes = 0x100000u;

// Explicit guest stack and continuation addresses are analysis inputs. They
// preserve original caller/local aliasing without asserting an original ABI.
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
};
inline void invoke(Memory& m, State& s, Frame& f, const Operations& op,
                   std::uint32_t target) {
    if (!op.invoke || f.argument_words>7u || f.callback_cleanup>28u ||
        (f.callback_cleanup&3u)) throw std::invalid_argument("invalid indirect boundary");
    f.push(m, f.call_return);
    const Call call{target,f.sp,f.call_return,f.argument_words,f.callback_cleanup};
    op.invoke(m,s,call,op.context);
    if(f.pop(m)!=f.call_return)throw std::runtime_error("indirect callback changed continuation");
    f.sp += f.callback_cleanup;
}
inline void finish(Memory& m, State& s, Frame& f, std::uint32_t cleanup) {
    if(f.sp!=f.entry_sp || f.pop(m)!=f.outer_return)
        throw std::runtime_error("indirect caller stack/continuation differs");
    f.sp += cleanup;
    for(unsigned i=0;i<s.arg.size();++i)s.arg[i]=m.r32(f.entry_sp+4u+4u*i);
}
using Function = void (*)(Memory&, State&, Frame&, const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,23>& entries_a();
const std::array<Entry,23>& entries_b();
} // namespace ra2::recovered::indirect_b30
