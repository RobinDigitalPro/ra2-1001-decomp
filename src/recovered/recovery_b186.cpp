#include "recovery_b186.hpp"

#include "platform/observed_ticks152.hpp"
#include "recovered/crt_b83.hpp"
#include "recovered/name_hash.hpp"

#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b186 {
namespace {
// Scoped copy of the already-reviewed 0x1928a0 positive-cache algorithm used
// by Block 188. This returns the actual backing+offset result; it does not
// pretend that the input name itself is the resource bytes.
std::uint32_t cached_lookup(Memory& m, std::uint32_t name) {
    if (!name || m.r32(0x00b10530u) != 0u)
        throw std::domain_error("Block186 requires a nonnull name in C locale mode");
    std::vector<std::uint8_t> bytes;
    for (unsigned n=0; n<32u; ++n) {
        const auto c=static_cast<std::uint8_t>(m.r8(name+n));
        if (!c) break;
        bytes.push_back(c);
    }
    if (bytes.empty() || bytes.size() >= 32u)
        throw std::domain_error("Block186 requires a bounded nonempty resource name");
    Inputs upper{}; upper.arg[0]=name;
    (void)crt_b83::fun_00781b14(m,upper);
    for (unsigned n=0;n<bytes.size();++n) bytes[n]=static_cast<std::uint8_t>(m.r8(name+n));
    NameHashState state{};
    const auto hash=fun_00493da0(state,bytes.data(),static_cast<std::int32_t>(bytes.size()));
    auto manager=m.r32(0x00a588e0u);
    for (unsigned chain=0;chain<2u && manager;++chain) {
        const auto next=m.r32(manager+4u);
        if (!next || !m.r32(manager+8u)) break;
        auto count=m.r32(manager+0x14u), table=m.r32(manager+0x20u);
        if (count>12u) throw std::domain_error("Block186 cache row bound exceeded");
        while (count) {
            const auto mid=count/2u, entry=table+mid*12u, current=m.r32(entry);
            if (global_b26::s32(current)>global_b26::s32(hash)) { count=mid; continue; }
            if (current==hash) {
                const auto backing=m.r32(manager+0x24u);
                if (!backing) throw std::domain_error("Block186 requires a loaded backing cache");
                return backing+m.r32(entry+4u);
            }
            table=entry+12u; count-=mid+1u;
        }
        manager=next;
    }
    throw std::domain_error("Block186 requires a positive resource cache hit");
}
}

std::uint32_t fun_005a9f50(Memory& m, const Inputs& i) {
    const auto self=i.cx;
    const auto text_object=i.arg[0];

    // Entry stack args, traced from S before the root's two saved registers:
    // arg1->+4, arg2->+8, arg3->+20, arg4->+24, arg5->+44,
    // low(arg6)->+48, arg7->+28, and low(arg8)==0 selects +40=4.
    m.w32(self+0x08u,i.arg[2]);
    m.w32(self+0x04u,i.arg[1]);
    m.w8(self+0x0cu,1u);

    // Original 0x68fad0 calls the WinMM IAT slot and shifts the true result.
    // Tick::get is the already-used real-API observer; no supplied return mock.
    m.w32(self+0x10u,ra2::platform::ticks152::Tick::get()>>4u);

    m.w32(self+0x18u,0u);
    m.w32(self+0x20u,i.arg[3]);
    m.w32(self+0x24u,i.arg[4]);
    m.w32(self+0x28u,0u);
    m.w8(self+0x34u,0u);
    m.w32(self+0x38u,0u);
    m.w8(self+0x3cu,0u);
    m.w32(self,0x00791d38u); // interim vptr written before 0x950f0

    // Original 0x4950f0 -> 0x75a070 -> 0x5924c0 -> 0x5928a0 chain.
    // The original helper's stack-local output is transient; cached_lookup
    // preserves its authentic positive-hit result as backing+entry offset.
    const auto text=m.r32(text_object); // actual nonnull 0x75a070 route
    m.w8(self+0x3cu,0u); // actual 0x950f0 repeats the output-byte clear
    const auto cached=cached_lookup(m,text);

    m.w32(self+0x1cu,cached);
    m.w32(self+0x2cu,0u);
    // Original MOVSX ECX,WORD [EAX+6]; DEC ECX.
    const auto signed_length=static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(cached+6u)));
    m.w32(self+0x30u,static_cast<std::uint32_t>(signed_length)-1u);
    m.w8(self+0x48u,i.arg[6]&0xffu);
    m.w32(self+0x44u,i.arg[5]);
    m.w32(self+0x40u,0u);
    m.w32(self,0x00791d88u); // final original vptr
    m.w32(self+0x28u,i.arg[7]);
    if ((i.arg[8]&0xffu)==0u) m.w32(self+0x40u,4u);
    return self;
}
} // namespace ra2::recovered::recovery_b186
