#include "recovery_b338.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/recovery_b128.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b338 {
using namespace ra2::recovered::floating_b61;
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
struct Scratch {
    Memory memory;
    std::array<unsigned char, 128> bytes{};
    leaf::Memory span;
    explicit Scratch(Memory& source, std::uint32_t base)
        : memory(source), span(bytes.data(), base, bytes.size()) { memory.add(span); }
};
}

std::uint32_t fun_00608560(Memory& m, const Inputs& i) {
    const auto destination = i.cx;
    const auto descriptor = i.dx;
    need(destination && descriptor, "338 requires nonnull output and descriptor pointers");
    need(m.r8(descriptor) == 4u && m.r8(descriptor + 0x12u) != 0u,
         "338 selects only the positive first descriptor branch of 0x208560");

    Scratch s(m, 0x7c221000u);
    const auto root_triplet = 0x7c221000u;
    const auto wrapper_triplet = root_triplet + 0x10u;
    Inputs lookup = i;
    lookup.cx = descriptor + 0x0eu;
    const auto object = ra2::recovered::recovery_b128::fun_006aae60(s.memory, lookup);
    need(object != 0u, "338 requires an accepted positive 0x2aae60 registry hit");
    const auto vptr = s.memory.r32(object);
    need(vptr == 0x0078612cu && s.memory.r32(vptr + 0x58u) == 0x004102e0u &&
         s.memory.r32(vptr + 0x48u) == 0x005cd4d0u,
         "338 requires constructor-proven vptr 0x78612c and its pinned wrapper/leaf slots");

    // Exact reached 0x4102e0 protocol: its temporary receives the actual
    // slot+0x48 result, then it copies three dwords to the caller's local.
    Inputs getter = i;
    getter.cx = object;
    getter.arg[0] = wrapper_triplet;
    // Same three original stores as the accepted leaf, across explicit spans.
    for(unsigned k=0;k<12;k+=4)s.memory.w32(wrapper_triplet+k,s.memory.r32(object+0x88+k));
    s.memory.w32(root_triplet, s.memory.r32(wrapper_triplet));
    s.memory.w32(root_triplet + 4u, s.memory.r32(wrapper_triplet + 4u));
    s.memory.w32(root_triplet + 8u, s.memory.r32(wrapper_triplet + 8u));
    // 0x208560's root copies the wrapper-local result to ECX's output.
    m.w32(destination, s.memory.r32(root_triplet));
    m.w32(destination + 4u, s.memory.r32(root_triplet + 4u));
    m.w32(destination + 8u, s.memory.r32(root_triplet + 8u));
    return destination; // original RET; full EAX is the ECX output pointer
}

std::uint32_t fun_00608f40(Memory& m, const Inputs& i) {
    const auto outer = i.cx;
    const auto destination = i.arg[0];
    need(outer && destination, "338 requires nonnull outer input and output pointers");

    Scratch s(m, 0x7c220000u);
    const auto child_output = 0x7c220000u;
    const auto projection_input = child_output + 0x20u;
    const auto projection_output = child_output + 0x30u;
    const auto p = m.r32(outer + 4u);
    const auto q = m.r32(p);
    const auto descriptor = m.r32(q + 4u);
    need(p && q && descriptor, "338 requires the exact nonnull nested descriptor pointer chain");

    Inputs child = i;
    child.cx = child_output;
    child.dx = descriptor;
    (void)fun_00608560(s.memory, child);
    s.memory.w32(projection_input, s.memory.r32(child_output));
    s.memory.w32(projection_input + 4u, s.memory.r32(child_output + 4u));
    s.memory.w32(projection_input + 8u, s.memory.r32(child_output + 8u));

    Inputs projection = i;
    projection.cx = m.r32(0x00821cacu);
    projection.arg[0] = projection_input;
    projection.arg[1] = projection_output;
    (void)ra2::recovered::numeric_b88::fun_00698010(s.memory, projection);
    i.fp = projection.fp;

    const auto x = s.memory.r32(projection_output) + m.r32(0x00821970u) - 4u;
    const auto y = s.memory.r32(projection_output + 4u) + m.r32(0x00821974u) - 4u;
    m.w32(destination, x);
    m.w32(destination + 4u, y);
    m.w32(destination + 8u, 8u);
    m.w32(destination + 12u, 8u);
    return destination; // original RET 4; full EAX is caller arg0
}
}
