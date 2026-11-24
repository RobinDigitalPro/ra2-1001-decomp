#include "recovered/recovery_b472.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::recovery_b472 {
namespace {
void require(bool ok, const char* why) { if (!ok) throw std::domain_error(why); }
}
std::uint32_t fun_0062c9e0(AddressSpace& m, Inputs& in, Allocator& heap) {
    const auto selector = in.cx;
    const auto object = heap.allocate(0xb8u);
    require(object != 0, "B472 excludes the original allocation-failure route");

    // Literal stores of accepted 0x22cc50 (RVA 0x22cc50), whose full exact
    // body is separately pinned in graph_inventory.json. The caller model
    // applies that bounded initializer to the allocated object address.
    m.w32(object + 0x10u,0u); m.w8(object,0u); m.w8(object+1u,1u);
    m.w32(object+4u,0u); m.w32(object+8u,selector); m.w32(object+0x14u,0u);
    for(auto o:{0x18u,0x19u,0x1au})m.w8(object+o,0u);
    for(auto o:{0x1cu,0x20u,0x24u,0x28u,0x2cu,0x30u,0x38u,0x40u,
                0x34u,0x3cu,0x44u,0x48u,0x6cu})m.w32(object+o,0u);
    for(auto o:{0xb0u,0xb1u,0xb2u})m.w8(object+o,0u);

    const auto capacity = m.r32(0x00a9e030u);
    const auto count = m.r32(0x00a9e038u);
    require(count < capacity, "B472 covers only the original positive count<capacity publication route");
    const auto table = m.r32(0x00a9e02cu);
    require(table != 0, "B472 requires a bounded writable registry table");
    m.w32(0x00a9e038u, count + 1u);
    m.w32(table + count * 4u, object);

    // Original 0x62ca5c..0x62ca6e performs NEG/SBB/AND/ADD then FILD/FSTP.
    // With the bounded selector domain 0 or 1 this stores exactly 20.0 or 10.0.
    const std::uint64_t value = selector == 1u ? 0x4024000000000000ull : 0x4034000000000000ull;
    m.w32(object + 0x10u, static_cast<std::uint32_t>(value));
    m.w32(object + 0x14u, static_cast<std::uint32_t>(value >> 32));
    // FILD pushes onto physical R7 from an empty stack (TOP 0), then FSTP
    // qword pops it. The tag/TOP return to empty, while the stale physical
    // register payload remains the exact 80-bit 10.0 or 20.0 value.
    const std::uint64_t significand = 0xa000000000000000ull;
    const std::uint16_t exponent = selector == 1u ? 0x4002u : 0x4003u;
    for (unsigned i=0;i<8;++i) in.fp.image.bytes[98+i]=static_cast<std::uint8_t>(significand>>(8*i));
    in.fp.image.bytes[106]=static_cast<std::uint8_t>(exponent);
    in.fp.image.bytes[107]=static_cast<std::uint8_t>(exponent>>8);
    return object;
}
}
