#include "recovered/recovery_b1425.hpp"
#include "recovered/rng_b70.hpp"
#include <stdexcept>
namespace ra2::recovered::b1425 {
namespace {
using U = std::uint32_t;
void need(bool ok, const char* why) { if (!ok) throw std::domain_error(why); }
U row_for(Memory& m, const Inputs& in) {
    // Exact 15-byte accepted 591ED0 behavior, locally adapted to the
    // shared original-address Memory used by this FP/RNG family.
    return (m.r32(in.cx + 0x98u) << 5u) + 0x00a28000u;
}
U integer_deadline(Memory& m, const Inputs& in, U row) {
    auto fp = in.fp;
    fp.load64(floating_b61::read64(m, row + 0x10u));
    fp.multiply64(floating_b61::read64(m, 0x00786608u));
    const auto cached = std::uint16_t(m.r32(0x007c3a04u));
    if (fp.control() != cached) fp.load_control(cached);
    const U result = U(fp.pop_integer64());
    in.fp = fp;
    return result;
}
}
U fun_004cc400(Memory& m, const Inputs& in) {
    const U actor = in.cx;
    need(m.r32(actor) == 0x0078c2a0u, "B1425 borrowed primary actor vtable");
    need(m.r32(0x0078c2a0u + 0x240u) == 0x004cc400u &&
         m.r32(0x0078c2a0u + 0x410u) == 0x004c7c10u,
         "B1425 original installed actor slots");
    need(m.r32(actor + 0xa8u) == 1u, "B1425 selected A8 waiting branch");
    need(m.r32(actor + 0x494u) != 0u, "B1425 borrowed nonnull cell state");
    const U locomotion = m.r32(actor + 0x564u);
    need(m.r32(actor + 0x1b0u) == 0u && locomotion >= 4u &&
         m.r32(locomotion - 4u) == 0x0078b958u &&
         m.r32(locomotion) == 0x0078b890u,
         "B1425 post-wait actor projection with genuine borrowed locomotor view");
    const U component = locomotion - 4u;
    need(m.r32(component + 0x20u) == m.r32(actor + 0x88u) &&
         m.r32(component + 0x24u) == m.r32(actor + 0x8cu) &&
         m.r32(component + 0x28u) == m.r32(actor + 0x90u) &&
         (m.r32(component + 0x20u) != 0u ||
          m.r32(component + 0x24u) != 0u ||
          m.r32(component + 0x28u) != 0u),
         "B1425 configured destination differs from original sentinel");
    need(m.r32(actor + 0x490u) == 0u && m.r32(actor + 0x25cu) == 0u &&
         m.r32(actor + 0x598u) == 0u && m.r8(actor + 0x5a1u) == 0u &&
         m.r8(actor + 0x74u) == 0u && m.r8(actor + 0x75u) == 0u &&
         m.r8(actor + 0x76u) == 0u,
         "B1425 finite post-placement actor projection fields");
    const U index = m.r32(actor + 0x98u);
    need(index < 30u, "B1425 bounded mission table row");
    const U row = row_for(m, in);
    need(row == 0x00a28000u + 32u * index, "B1425 original mission row addressing");
    const auto raw_duration = floating_b61::read64(m, row + 0x10u);
    need(raw_duration == 0x3ff0000000000000ull ||
         raw_duration == 0x4000000000000000ull ||
         raw_duration == 0x4008000000000000ull,
         "B1425 finite configured duration 1, 2, or 3");
    const U deadline = integer_deadline(m, in, row);

    const U owner = m.r32(0x00a255c0u);
    need(owner != 0u, "B1425 borrowed session provider");
    Inputs rng{};
    rng.cx = owner + 0x218u;
    rng.arg[0] = 0u;
    rng.arg[1] = 2u;
    const U draw = rng_b70::fun_0062fe40(m, rng);
    return deadline + draw;
}
}
