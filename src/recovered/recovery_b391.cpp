#include "recovered/recovery_b391.hpp"
#include "recovered/global_b26_memory.hpp"
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545490(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b391 {
namespace {
constexpr std::uint32_t map_receiver = 0x0081a820u;
constexpr std::uint32_t array_global = 0x0084e1c4u;
constexpr std::uint32_t item_count_global = 0x0084e1d0u;
constexpr std::uint32_t scratch = 0xf0000000u;
constexpr std::uint32_t excluded_field_value = 6u;
constexpr std::uint32_t tile_flag = 0x00400000u;

std::uint32_t run_positive_field_not_six(Memory& m, const Inputs& i) {
    const auto count = m.r32(item_count_global);
    if (count != 1u) throw std::domain_error("B391 c1750 draft requires exactly one item");
    const auto array = m.r32(array_global);
    if (!array) throw std::domain_error("B391 c1750 draft requires populated item pointer array");

    // The original loop processes indices [0,count). Field value 6 takes
    // virtual calls; this bounded positive route explicitly takes
    // the other arm and never invents a return for those callbacks.
    for (std::uint32_t index = 0; index < count; ++index) {
        const auto item = m.r32(array + index * 4u);
        if (!item || m.r32(item + 0x30u) == excluded_field_value)
            throw std::domain_error("B391 c1750 draft excludes null records and field value 6");

        const auto x = m.r32(item + 0x34u);
        const auto y = m.r32(item + 0x38u);
        const auto z = m.r32(item + 0x3cu);
        m.w32(scratch, x); m.w32(scratch + 4u, y); m.w32(scratch + 8u, z);
        global_b26::Inputs child{};
        child.cx = map_receiver;
        child.arg[0] = scratch;
        const auto tile = global_b26::fun_00545490(m, child);
        if (tile == 0x00a57610u)
            throw std::domain_error("B391 c1750 draft excludes the map fallback tile");
        m.w32(tile + 0x140u, m.r32(tile + 0x140u) | tile_flag);
    }
    (void)i; // Original c1750 does not consume incoming ECX or caller words.
    return count;
}
}

std::uint32_t fun_004c1750(Memory& m, const Inputs& i) {
    std::array<std::uint8_t,12> private_bytes{};
    leaf::Memory span(private_bytes.data(),scratch,private_bytes.size());
    Memory child=m;child.add(span);
    return run_positive_field_not_six(child, i);
}
}
