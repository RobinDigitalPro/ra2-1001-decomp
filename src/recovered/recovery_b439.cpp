#include "recovered/recovery_b439.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b439 {
namespace {
constexpr std::uint8_t selector_table[40]={
    0,1,1,4,4,2,2,4,4,4,4,4,4,4,3,3,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0};
constexpr std::uint32_t decrement_targets[5]={
    0x004ea116u,0x004ea12au,0x004ea13au,0x004ea132u,0x004ea146u};
constexpr std::uint32_t increment_targets[5]={
    0x004ea1e6u,0x004ea1fau,0x004ea20au,0x004ea202u,0x004ea216u};
void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

// These are the two actual BuildingClass callbacks reached by the roots.
// 0x453890 is the accepted six-byte MOV EAX,6 / RET helper. The vtable's
// 0x6b6910 slot is MOV EAX,[ECX]; JMP [EAX+0x84]. For BuildingClass the
// original +0x84 table word is 0x4538b0, whose body returns [ECX+0x418].
std::uint32_t building_type6(Memory& m, std::uint32_t object) {
    const auto vt = m.r32(object);
    need(vt == 0x00787bbcu, "439 requires constructor-proven BuildingClass vptr");
    need(m.r32(vt + 0x2cu) == 0x00453890u,
         "439 requires original BuildingClass +2c type callback");
    return 6u; // exact body at 0x453890: b8 06 00 00 00 c3
}

std::uint32_t building_get_object(Memory& m, std::uint32_t object) {
    const auto vt = m.r32(object);
    need(vt == 0x00787bbcu, "439 getter receiver must retain BuildingClass vptr");
    need(m.r32(vt + 0x80u) == 0x006b6910u,
         "439 requires original BuildingClass +80 callback");
    need(m.r32(vt + 0x84u) == 0x004538b0u,
         "439 +80 tail dispatch must reach original 4538b0 getter");
    return m.r32(object + 0x418u); // exact 0x4538b0 body
}

std::uint32_t apply(Memory& m, const Inputs& i, bool increment) {
    const auto object = i.arg[0];
    auto eax = building_type6(m, object);
    if (eax != 6u) return eax;

    eax = building_get_object(m, object);
    if (eax == 0u) return eax;
    const bool selector_flag = (m.r8(eax + 0xadau) != 0u);

    const auto property = m.r32(object + 0x418u);
    need(property != 0u, "439 positive route requires initialized property object");
    eax = m.r32(property + 0xc44u);
    --eax;
    if (eax > 0x27u) return eax;

    // Exact pinned data at RVA 0xea160, 0xea14c and 0xea21c; the native
    // bridge maps and executes the original bytes, while this model uses the
    // literal switch contents recovered from those ranges.
    const auto selector = selector_table[eax];
    const auto target = increment ? increment_targets[selector] : decrement_targets[selector];
    if (selector == 4u) return eax;

    std::uint32_t offset = 0;
    if (increment) {
        switch (target) {
        case 0x004ea1e6u: offset = selector_flag ? 0x52c8u : 0x52c0u; break;
        case 0x004ea1fau: offset = 0x52b8u; break;
        case 0x004ea20au: offset = 0x52c4u; break;
        case 0x004ea202u: offset = 0x52bcu; break;
        default: throw std::domain_error("439 unexpected original increment switch target");
        }
    } else {
        switch (target) {
        case 0x004ea116u: offset = selector_flag ? 0x52c8u : 0x52c0u; break;
        case 0x004ea12au: offset = 0x52b8u; break;
        case 0x004ea13au: offset = 0x52c4u; break;
        case 0x004ea132u: offset = 0x52bcu; break;
        default: throw std::domain_error("439 unexpected original decrement switch target");
        }
    }
    eax = i.cx + offset;
    const auto value = m.r32(eax);
    m.w32(eax, increment ? value + 1u : value - 1u);
    return eax;
}
}

std::uint32_t fun_004ea0c0(Memory& m, const Inputs& i) { return apply(m, i, false); }
std::uint32_t fun_004ea190(Memory& m, const Inputs& i) { return apply(m, i, true); }

std::uint32_t fun_006c69f0(Memory& m, const Inputs& i) {
    const auto object=i.cx;
    const auto property=building_get_object(m,object);
    const auto list=m.r32(property+0xb8cu);
    const auto owner=m.r32(object+0x1b4u);
    need(owner!=0u,"439 lookup route requires initialized owner");
    const auto index=m.r32(owner+0x15f40u);
    need(list!=0u,"439 lookup route requires nonempty property list");
    const auto rows=m.r32(list+4u);
    need(rows!=0u,"439 lookup route requires initialized list rows");
    const auto record=m.r32(rows+index*4u);
    need(record!=0u,"439 lookup route requires positive selected record");
    return m.r32(record+0x30cu);
}

}
