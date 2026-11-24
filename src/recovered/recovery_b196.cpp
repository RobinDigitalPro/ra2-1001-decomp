#include "recovery_b196.hpp"
#include "recovered/floating_b61_memory.hpp"
#include "recovered/numeric_b88.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

// Private Block196 draft. The route requires a copied descriptor whose type
// byte is not 4, forcing the original all-minus-one result, then the real
// fallback getter at the constructor-proven 0x787bbc/+0x58 address point.
namespace ra2::recovered::recovery_b196 {
using namespace ra2::recovered::floating_b61;

std::uint32_t fun_00611b80(Memory& m, const Inputs& i) {
    const auto destination = i.cx;
    const auto descriptor = i.dx;
    const auto receiver = i.arg[0];
    if (!descriptor || m.r8(descriptor) == 4u || !receiver)
        throw std::invalid_argument("Block196 is limited to nonnull descriptor type != 4 and nonnull getter receiver");
    if (m.r32(receiver) != 0x787bbcu || m.r32(0x787c14u) != 0x004102e0u ||
        m.r32(0x787c04u) != 0x00443e10u)
        throw std::invalid_argument("Block196 requires constructor-proven vptr 0x787bbc with real +58/+48 target chain");

    // Root's REP MOVSD+MOVSW+MOVSB copies exactly 111 bytes. The selected
    // helper branch reads the copied first byte and writes three -1 dwords.
    Memory local = m;
    std::array<unsigned char, 256> scratch{};
    constexpr std::uint32_t scratch_base = 0x7c200000u;
    leaf::Memory scratch_span(scratch.data(), scratch_base, scratch.size());
    local.add(scratch_span);
    constexpr auto descriptor_copy = scratch_base;
    constexpr auto helper_triplet = scratch_base + 0x80u;
    constexpr auto getter_triplet = scratch_base + 0xa0u;
    constexpr auto wrapper_triplet = scratch_base + 0xb0u;
    constexpr auto projection_input = scratch_base + 0xc0u;
    constexpr auto projection_output = scratch_base + 0xd0u;
    for (unsigned n = 0; n != 111; ++n) local.w8(descriptor_copy + n, m.r8(descriptor + n));

    if (local.r8(descriptor_copy) == 4u)
        throw std::invalid_argument("Block196 excludes the descriptor-type-4 virtual-helper routes");
    local.w32(helper_triplet, 0xffffffffu);
    local.w32(helper_triplet + 4u, 0xffffffffu);
    local.w32(helper_triplet + 8u, 0xffffffffu);

    // 0x208560 returns all -1 for this branch. The root then makes its real
    // +0x58 call on arg0. Slot +0x58 is the original 0x4102e0 output-copy
    // wrapper; its actual slot +0x48 target is 0x443e10.
    const auto vptr = m.r32(receiver);
    const auto wrapper = m.r32(vptr + 0x58u);
    const auto target = m.r32(vptr + 0x48u);
    if (wrapper != 0x004102e0u || target != 0x00443e10u)
        throw std::invalid_argument("Block196 getter chain differs from pinned original table");

    const auto type = m.r32(receiver + 0x418u);
    const auto index = m.r32(type + 0xc78u);
    if (index > 21u)
        throw std::invalid_argument("Block196 constrains both original lookup tables to their 22-entry numeric ranges");
    // Actual 0x4585c0(this=type, arg0=0) and 0x4585b0(this=type):
    // each reads a separate immutable original 22-DWORD table.
    const auto dx_cell = m.r32(0x7bac60u + 4u * index);
    const auto dy_cell = m.r32(0x7bac08u + 4u * index);
    local.w32(getter_triplet, m.r32(receiver + 0x88u) + dy_cell * 128u - 128u);
    local.w32(getter_triplet + 4u, m.r32(receiver + 0x8cu) + dx_cell * 128u - 128u);
    local.w32(getter_triplet + 8u, m.r32(receiver + 0x90u));
    // The wrapper copies the target-local triplet to its caller output,
    // loads that output argument into EAX at 4102F0, and returns it.
    // The root reads the copied caller-local triplet immediately.
    local.w32(wrapper_triplet, local.r32(getter_triplet));
    local.w32(wrapper_triplet + 4u, local.r32(getter_triplet + 4u));
    local.w32(wrapper_triplet + 8u, local.r32(getter_triplet + 8u));
    local.w32(projection_input, local.r32(wrapper_triplet));
    local.w32(projection_input + 4u, local.r32(wrapper_triplet + 4u));
    local.w32(projection_input + 8u, local.r32(wrapper_triplet + 8u));

    Inputs projection = i;
    projection.cx = m.r32(0x00821cacu);
    projection.arg[0] = projection_input;
    projection.arg[1] = projection_output;
    (void)ra2::recovered::numeric_b88::fun_00698010(local, projection);
    i.fp = projection.fp;
    m.w32(destination, local.r32(projection_output) + m.r32(0x00821970u));
    m.w32(destination + 4u, local.r32(projection_output + 4u) + m.r32(0x00821974u));
    return destination; // original RET 4; full EAX is receiver/destination
}
}
