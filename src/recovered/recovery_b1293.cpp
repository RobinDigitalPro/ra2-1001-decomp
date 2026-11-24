#include "recovery_b1293.hpp"

#include "recovered/recovery_b110.hpp"
#include "recovered/leaf_memory.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1293 {
namespace {
using U = std::uint32_t;
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

U abs_small(std::int32_t v) { return static_cast<U>(v < 0 ? -v : v); }

// Finite call route matching the constructor-installed Building vtable method
// at VA 0x5CCEA0. The accepted 0x702C0 helper is supplied with the same cell,
// point, FP image, and bounded height-cache input as the B106 fixture.
U building_height(Memory& original, const Inputs& root) {
    constexpr U object_vptr = 0x00787BBCu;
    constexpr U table_global = 0x0081A958u;
    constexpr U table_count = 0x0081A95Cu;
    constexpr U stack_base = 0x7D100000u;
    const U object = root.cx;
    const U world = object + 0x88u;
    need(object != 0 && original.r32(object) == object_vptr && original.r32(0x787d6cu)==0x5ccea0u,
         "B1293 constructor-installed 0x787BBC Building vptr");
    need(original.r32(world) == 0 && original.r32(world + 4u) == 0 &&
         original.r32(world + 8u) == 0,
         "B1293 world point (0,0,0) bounded getter input");
    need(original.r8(object + 0x79u) == 0,
         "B1293 getter skips the secondary A5AA98 correction");
    need(original.r8(0x00838F70u) == 4 && original.r32(0x00838F80u) == 60,
         "B1293 exact accepted B106 height-cache fixture prestate");

    const U table = original.r32(table_global);
    need(table != 0 && original.r32(table_count) > 0,
         "B1293 in-range original map-cell table");
    const U cell = original.r32(table); // (world x, world y) == (0,0).
    need(cell != 0 && cell != 0x00A57610u &&
         original.r8(cell + 0x11Bu) == 0 && original.r8(cell + 0x11Cu) == 0,
         "B1293 borrowed non-fallback cell compatible with B106 0x702C0 case");

    std::array<std::uint8_t, 12> point_bytes{};
    leaf::Memory point_span(point_bytes.data(), stack_base,
                            static_cast<U>(point_bytes.size()));
    Memory callee_memory = original;
    callee_memory.add(point_span);
    callee_memory.w32(stack_base, original.r32(world));
    callee_memory.w32(stack_base + 4u, original.r32(world + 4u));
    callee_memory.w32(stack_base + 8u, original.r32(world + 8u));

    Inputs height_input{};
    height_input.ax = 0;                  // World y after the 0x557070 projection.
    height_input.cx = cell;               // 0x557070 cell-table result.
    height_input.dx = stack_base;         // 0x557070 local point pointer.
    height_input.arg[0] = stack_base;     // Original 0x4702C0 stack argument.
    height_input.arithmetic_flags = 0x202u; // TEST ECX,ECX for a nonnull cell.
    height_input.fp = root.fp;
    const U height = map_b106::fun_004702c0(callee_memory, height_input);
    root.fp = height_input.fp;
    need(height == 0,
         "B1293 B106 n=4 zero-height route through actual 0x557070 call shape");

    // 0x5CCEA0 computes [this+0x90] - returned height. Byte +0x79 is zero
    // in this finite route, so it does not subtract global 0xA5AA98.
    return original.r32(object + 0x90u) - height;
}

U query_coordinates(Memory& m, const Inputs& root) {
    recovery_b110::Inputs q{};
    q.cx = 0x0081A820u;
    q.arg[0] = root.arg[0];
    q.arg[1] = root.arg[1];
    // Original 0x6FE3C1..0x6FE3CB pushes four zero option words.
    q.arg[2] = q.arg[3] = q.arg[4] = q.arg[5] = 0;
    q.fp = root.fp;
    const U result=recovery_b110::fun_0054cc50(m,q);root.fp=q.fp;return result;
}
} // namespace

U run(U root, Memory& m, const Inputs& i) {
    need(root == 0x002FE3A0u, "B1293 exact root RVA");
    need(i.cx != 0 && i.arg[0] != 0 && i.arg[1] != 0,
         "B1293 nonnull object and two coordinate-pair pointers");

    const U getter = building_height(m, i);
    if (static_cast<std::int32_t>(getter) < 0)
        return (getter & 0xFFFFFF00u) | 1u; // Original MOV AL,1.

    const U queried = query_coordinates(m, i);
    if ((queried & 0xFFu) == 0)
        return (queried & 0xFFFFFF00u) | 1u; // Original common true return.

    const auto ax = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(i.arg[0])));
    const auto ay = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(i.arg[0] + 2u)));
    const auto bx = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(i.arg[1])));
    const auto by = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(i.arg[1] + 2u)));
    if (ax == bx && ay == by)
        return queried & 0xFFFFFF00u; // Original XOR AL,AL.

    const U dx = abs_small(ax - bx);
    const U dy = abs_small(ay - by);
    const U distance = dx > dy ? dx : dy;
    if (distance == 1u)
        return distance & 0xFFFFFF00u; // Original EAX=1 followed by XOR AL,AL.
    if (distance >= 12u)
        return (distance & 0xFFFFFF00u) | 1u; // Original MOV AL,1.

    // Distances 2..11 continue into cell predicates and missing 0x2AA30.
    throw std::domain_error("B1293 selected route excludes the 0x2AA30 middle-distance chain");
}
} // namespace ra2::recovered::b1293

namespace ra2::recovered::recovery_b1293 {std::uint32_t fun_006fe3a0(floating_b61::Memory&m,const floating_b61::Inputs&i){return b1293::run(0x2fe3a0u,m,i);}}
