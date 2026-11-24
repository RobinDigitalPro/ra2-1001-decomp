#include "recovery_b1336.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545490(Memory&, const Inputs&);
}
namespace ra2::recovered::b1336 {
namespace {
using U = std::uint32_t;
constexpr U kMap = 0x0081a820u;
constexpr U kGrid = 0x0081a958u;
constexpr U kEpoch = 0x00a2896cu;
constexpr U kActorType = 0x5acu;
constexpr U kActorMode = 0x494u;
constexpr U kTypeFlag = 0xba6u;
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
}
U fun_006f6020(Memory& m, const Inputs& i) {
    const U actor = i.cx;
    need(actor != 0u, "B1336 requires a mapped actor");
    const U xyz = actor + 0x88u;
    const U xraw = m.r32(xyz);
    const U yraw = m.r32(xyz + 4u);
    const U type = m.r32(actor + kActorType);
    need(type != 0u, "B1336 requires a mapped actor type");
    need(m.r32(kGrid) != 0u, "B1336 requires a mapped map grid");
    // The accepted 0x545490 helper is reached on its successful populated-cell
    // route. Reuse its typed implementation; only the two copied fixed-point
    // coordinates are observable to that helper on this route.
    floating_b61::Inputs lookup{};
    lookup.cx = kMap;
    lookup.arg[0] = xyz;
    const U cell = global_b26::fun_00545490(m, lookup);
    need(cell != 0u && cell != 0x00a57610u,
         "B1336 requires the original 0x545490 populated-cell route");
    need(m.r32(actor + kActorMode) == 0u,
         "B1336 finite route requires actor+0x494 == 0");
    need(m.r8(type + kTypeFlag) == 0u,
         "B1336 finite route requires type+0xBA6 == 0");
    const U input_y = yraw;
    const U epoch = m.r32(kEpoch);
    // Original 0x6F61CE branch: clear E0/F0, copy A2896C to E4,
    // copy the produced stack Y at ESP+0x18 to E8, and clear EC.
    m.w32(actor + 0xe0u, 0u);
    m.w32(actor + 0xe4u, epoch);
    m.w32(actor + 0xe8u, input_y);
    m.w32(actor + 0xecu, 0u);
    m.w32(actor + 0xf0u, 0u);
    // MOV EAX,inputY followed by XOR AL,AL preserves upper 24 bits.
    return input_y & 0xffffff00u;
}
}


