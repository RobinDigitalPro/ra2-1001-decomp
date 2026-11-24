#pragma once
#include "recovered/indirect_b31_memory.hpp"

namespace ra2::recovered::direct_b33 {
using indirect_b31::Memory;
using indirect_b31::State;
using indirect_b31::Call;
using indirect_b31::Operations;
using indirect_b31::finish;
using indirect_b31::s32;
using indirect_b31::sar;
using indirect_b31::with_al;
using indirect_b31::with_ax;
using indirect_b31::arena_bytes;

// One encoded E8 destination, relocated with its original caller. The callback
// is an explicit boundary; this does not assert a recovered callee or C++ ABI.
struct Frame : indirect_b31::Frame {
    std::uint32_t direct_target{};
    Frame() = default;
    Frame(std::uint32_t entry, std::uint32_t current, std::uint32_t outer,
          std::uint32_t continuation, std::uint32_t cleanup, std::uint32_t words,
          std::uint32_t target = 0)
        : indirect_b31::Frame{entry,current,outer,continuation,cleanup,words},
          direct_target(target) {}
};
// The selected caller at RVA 0x750b0 supplies 68 bytes. These reviewed test
// boundaries can expose 32 stack words and clean up 0..128 bytes. This is not
// an inferred original source prototype or a change to earlier blocks.
inline void invoke(Memory& m,State& s,Frame& f,const Operations& op,std::uint32_t target) {
    if(!op.invoke||f.argument_words>32||f.callback_cleanup>128||(f.callback_cleanup&3u))
        throw std::invalid_argument("invalid D33 direct boundary");
    f.push(m,f.call_return);
    op.invoke(m,s,{target,f.sp,f.call_return,f.argument_words,f.callback_cleanup},op.context);
    if(f.pop(m)!=f.call_return)throw std::runtime_error("D33 callback changed continuation");
    f.sp+=f.callback_cleanup;
}
using Function = void (*)(Memory&, State&, Frame&, const Operations&);
struct Entry { std::uint32_t rva; Function function; };
const std::array<Entry,114>& entries_a();
const std::array<Entry,114>& entries_b();
const std::array<Entry,113>& entries_c();
} // namespace ra2::recovered::direct_b33
