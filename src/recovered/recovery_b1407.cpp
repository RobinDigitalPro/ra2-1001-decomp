#include "recovery_b1407.hpp"

#include "recovered/leaf_memory.hpp"
#include "recovered/recovery_b1387.hpp"
#include "recovered/rng_b70.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b1407 {
namespace {
using U = std::uint32_t;
constexpr U kRngState = 0x00821558u;
constexpr U kRegistryHeader = 0x0083b380u;
constexpr U kDescriptorOwner = 0x00821b88u;

void need(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}
}

U configure_crt(Memory& m,const Inputs& i){
    const U value=i.arg[0];if(value>1016u)return 0u;
    m.w32(0x817554u,value);return 1u; // actual unindexed773328
}

U fun_004b2140(Memory& m, const Inputs& i, Heap& heap) {
    need(m.r32(0x817554u)==0&&m.r32(0xb10e14u)==0,"B1407 explicitly produced CRT configuration/empty small registry");
    const U self = i.cx;

    // The original copies the seven outer stack words verbatim into self.
    for (U n = 0; n < 7; ++n)
        m.w32(self + 4u * n, i.arg[n]);

    // Original 0x62FE40 range call: ECX=0x821558, low=0, high=256.
    Inputs rng_inputs = i;
    rng_inputs.cx = kRngState;
    rng_inputs.arg[0] = 0;
    rng_inputs.arg[1] = 0x100u;
    m.w32(self + 0x1cu, rng_b70::fun_0062fe40(m, rng_inputs));

    // This implementation covers only the original signed count<capacity
    // append arm. The original growth/virtual callback arm remains out of scope.
    const U count = m.r32(kRegistryHeader + 0x10u);
    const U capacity = m.r32(kRegistryHeader + 0x8u);
    const U entries = m.r32(kRegistryHeader + 0x4u);
    need(global_b26::s32(count) >= 0 &&
             global_b26::s32(count) < global_b26::s32(capacity) && entries != 0,
         "B1407 supported original registry room branch required");
    m.w32(kRegistryHeader + 0x10u, count + 1u);
    m.w32(entries + count * 4u, self);

    // 0x76D957 is represented by the existing genuine ordinary-heap adapter.
    // The selected route requires a successful 0xE8 allocation.
    const U owner = heap.allocate(0xe8u);
    if (owner == 0) return 0;

    // Original LEA computes S+10h: the public outer words3..5. Map the
    // actual typed argument carrier for the delegated child's read. There is
    // no fabricated original stack frame or invented private input.
    const U words=static_cast<U>(reinterpret_cast<std::uintptr_t>(i.arg.data()));
    leaf::Memory caller_words(reinterpret_cast<std::uint8_t*>(i.arg.data()),words,64u);
    auto* owner_bytes=reinterpret_cast<std::uint8_t*>(std::uintptr_t(owner));
    leaf::Memory owner_span(owner_bytes,owner,0xe8u);
    Memory child_memory=m;child_memory.add(caller_words);child_memory.add(owner_span);

    const U descriptor = m.r32(m.r32(kDescriptorOwner) + 0xce0u);
    Inputs child_inputs = i;
    child_inputs.cx = owner;
    child_inputs.arg[0] = descriptor;
    child_inputs.arg[1] = words+12u;
    child_inputs.arg[2] = 0;
    child_inputs.arg[3] = 0;
    child_inputs.arg[4] = 0x0083b358u;

    const U result = b1387::fun_00602650(child_memory, child_inputs);
    i.fp = child_inputs.fp;
    return result;
}
}
