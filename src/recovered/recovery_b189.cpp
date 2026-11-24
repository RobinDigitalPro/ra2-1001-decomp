#include "recovery_b189.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/name_hash.hpp"

#include <stdexcept>
#include <vector>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00406f30(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b189 {
namespace {
constexpr std::uint32_t kName=0x007dc764u; // pinned "BIGFONT.SHP"

// Same finite positive-cache algorithm used by accepted Block188; the route
// requires a real one-row hit and returns backing+the selected row offset.
std::uint32_t cached_resource(Memory& m) {
    if (m.r32(0x00b10530u)!=0u)
        throw std::domain_error("Block189 requires original C-locale selector zero");
    std::vector<std::uint8_t> bytes;
    for (unsigned n=0;n<32u;++n) {
        const auto c=static_cast<std::uint8_t>(m.r8(kName+n));
        if (!c) break;
        bytes.push_back(c);
    }
    if (bytes.empty() || bytes.size()>=32u)
        throw std::domain_error("Block189 fixed resource name bound");
    Inputs upper{}; upper.arg[0]=kName;
    (void)crt_b83::fun_00781b14(m,upper);
    for (unsigned n=0;n<bytes.size();++n) bytes[n]=static_cast<std::uint8_t>(m.r8(kName+n));
    NameHashState state{};
    const auto hash=fun_00493da0(state,bytes.data(),static_cast<std::int32_t>(bytes.size()));

    auto manager=m.r32(0x00a588e0u);
    for (unsigned chain=0;chain<2u && manager;++chain) {
        const auto next=m.r32(manager+4u);
        if (!next || !m.r32(manager+8u)) break;
        auto count=m.r32(manager+0x14u), table=m.r32(manager+0x20u);
        if (count>1u) throw std::domain_error("Block189 one-row cache bound");
        while (count) {
            const auto mid=count/2u, entry=table+mid*12u, current=m.r32(entry);
            if (global_b26::s32(current)>global_b26::s32(hash)) { count=mid; continue; }
            if (current==hash) {
                const auto backing=m.r32(manager+0x24u);
                if (!backing) throw std::domain_error("Block189 requires loaded cache backing");
                return backing+m.r32(entry+4u);
            }
            table=entry+12u; count-=mid+1u;
        }
        manager=next;
    }
    throw std::domain_error("Block189 requires positive BIGFONT.SHP cache hit");
}
}

std::uint32_t fun_0065ee30(Memory& m,const Inputs& i) {
    const auto self=i.cx;
    m.w32(self+0x04u,0u);
    m.w32(self+0x08u,0u);
    m.w32(self+0x0cu,0u);
    m.w32(self+0x14u,0u);
    m.w32(self,0x00794148u);

    // 0x25e8b0 calls accepted 0x406f30. On the pinned-zero global route it
    // returns immediately before all three resource/interface fallbacks.
    Inputs state{};
    if (global_b26::fun_00406f30(m,state)!=0u)
        throw std::domain_error("Block189 excludes nonzero 0x819778 initializer route");

    m.w32(0x00a9eaa8u,m.r32(0x00a9eaa8u)+1u);
    m.w32(self,0x00794178u);
    m.w8(self+0x10u,0u);

    // 0x1924c0 -> 0x1928a0 positive cache result. Its nonzero result takes
    // original 0x65ee75 JNZ and skips 0x95010/interface/heap fallback.
    m.w32(self+0x0cu,cached_resource(m));
    m.w32(self+0x04u,0x14u);
    m.w32(self+0x14u,i.arg[0]);
    m.w32(self+0x08u,0x23u);
    return self;
}
}
