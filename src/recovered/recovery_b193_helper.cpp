#include "recovered/recovery_b193.hpp"

#include "recovered/numeric_b88.hpp"
#include "recovered/preallocated_b66.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b193 {
using floating_b61::Inputs;
using floating_b61::Memory;

namespace {
void require(bool v, const char* message) {
    if (!v) throw std::domain_error(message);
}

std::uint32_t signed_word(std::uint32_t v) {
    return global_b26::sx16(v);
}

std::uint32_t positive_127630_then_129990(Memory& m,
                                           std::uint32_t object,
                                           std::uint32_t index) {
    const auto vtable = m.r32(object);
    require(vtable == 0x00790188u &&
                m.r32(vtable + 0x9cu) == 0x00527630u,
            "Block193 requires authentic constructor vptr and RVA 0x127630 slot");

    // On the selected original 0x127630 branch [object+0xa4] is nonzero.
    // The 13-instruction target returns that pointer unchanged and never
    // reaches its 0x1297c0 call.
    const auto q = m.r32(object + 0xa4u);
    require(q != 0, "Block193 requires the original 0x127630 nonnull-table return");

    // Exact positive 0x129990 arithmetic: product q[0]*q[1], signed IDIV of
    // the nonnegative byte count, row table at q+0x10+remainder*4, then AL from
    // row+0x24. The bounded fixture uses divisor 1, so remainder is zero.
    require(m.r32(q) == 1u && m.r32(q + 4u) == 1u,
            "Block193 bounded 0x129990 contract requires factors one and one");
    constexpr std::uint32_t divisor = 1u;
    const auto remainder = index % divisor;
    const auto row = m.r32(q + 0x10u + remainder * 4u);
    require(row != 0 && ((m.r32(row + 0x24u) >> 2u) & 1u) == 1u,
            "Block193 requires the original 0x129990 true row predicate");
    return 1u;
}

std::uint32_t append_record_298660(Memory& m, std::uint32_t x,
                                   std::uint32_t y,
                                   std::uint32_t flag,
                                   std::uint32_t incoming_ebp) {
    const auto count = m.r32(0x00aa60c8u);
    const auto capacity = m.r32(0x00aa60c0u);
    require(count == 0 && capacity == 1,
            "Block193 only models empty one-slot 0x298660 append");

    // The original helper builds a five-DWORD temporary record, increments
    // the count, and copies 20 bytes. The final MOV byte writes only record[16];
    // upper padding comes from saved EBP left by the immediately preceding
    // 0x298010 call. The frame derivation is in route.md.
    const auto record = m.r32(0x00aa60bcu);
    require(record != 0,
            "Block193 requires a real writable 20-byte projection-list slot");
    m.w32(0x00aa60c8u, 1u);
    m.w32(record + 0x00u, x);
    m.w32(record + 0x04u, y);
    m.w32(record + 0x08u, 0x100u);
    m.w32(record + 0x0cu, 0x100u);
    m.w32(record + 0x10u,
          (incoming_ebp & 0xffffff00u) | (flag & 0xffu));
    return 0u; // the original append starts at count zero, EAX=5*count
}
} // namespace

std::uint32_t fun_0054e340(Memory& memory, const Inputs& i) {
    const auto coordinate = i.arg[0];
    const auto desired_bit = i.arg[1] & 1u;
    const auto no_projection = i.arg[2] & 0xffu;
    require(no_projection == 0,
            "Block193 bounded route requires original projection/append branch");

    // Resolve the input coordinate through the same nonnull grid-table branch
    // used by the original routine. Keep the coordinate words as unsigned
    // 16-bit additions and sign-extend only for tile-index arithmetic.
    const auto x_word = memory.r16(coordinate);
    const auto y_word = memory.r16(coordinate + 2u);
    const auto tile_x = global_b26::s32(signed_word(x_word));
    const auto tile_y = global_b26::s32(signed_word(y_word));
    const auto tile_index = static_cast<std::uint32_t>(tile_y * 0x200 + tile_x);
    require(global_b26::s32(tile_index) >= 0 && tile_index < 0x40000u,
            "Block193 coordinate must resolve inside original tile table");
    const auto tile_table = memory.r32(0x0081a958u);
    const auto cell = memory.r32(tile_table + tile_index * 4u);
    require(cell != 0, "Block193 requires a populated original tile cell");

    const auto selector = memory.r32(cell + 0x38u);
    require(selector != 0x0000ffffu && selector != 0x000000ffu,
            "Block193 excludes the selector sentinel route");
    const auto object_table = memory.r32(0x00a28914u);
    const auto object = memory.r32(object_table + selector * 4u);
    require(object != 0, "Block193 requires a populated 0xa28914 object slot");
    const auto predicate = positive_127630_then_129990(
        memory, object, memory.r8(cell + 0x11au));
    require(predicate == 1u,
            "Block193 requires the authentic virtual predicate to be true");

    // 0x298010 projection: local input is {signedX*256+0x80,
    // signedY*256+0x80,0}; its actual x87 state is propagated to the caller.
    constexpr std::uint32_t scratch = 0x7e200000u;
    std::array<std::uint8_t, 24> scratch_bytes{};
    leaf::Memory scratch_span(scratch_bytes.data(), scratch,
                              static_cast<std::uint32_t>(scratch_bytes.size()));
    Memory local = memory;
    local.add(scratch_span);
    const auto fixed_x = static_cast<std::uint32_t>(tile_x * 0x100 + 0x80);
    const auto fixed_y = static_cast<std::uint32_t>(tile_y * 0x100 + 0x80);
    local.w32(scratch, fixed_x);
    local.w32(scratch + 4u, fixed_y);
    local.w32(scratch + 8u, 0u);

    Inputs projection = i;
    projection.cx = local.r32(0x00821cacu);
    require(projection.cx != 0,
            "Block193 requires the original projection-manager pointer");
    projection.arg[0] = scratch;
    projection.arg[1] = scratch + 0x10u;
    (void)numeric_b88::fun_00698010(local, projection);
    i.fp = projection.fp;

    const auto projected_x = local.r32(scratch + 0x10u);
    const auto projected_y = local.r32(scratch + 0x14u);
    const auto subtype = global_b26::s32(global_b26::sx8(local.r8(cell + 0x11bu)));
    const auto rectangle_x = projected_x - 0x80u;
    const auto rectangle_y = projected_y -
        static_cast<std::uint32_t>(15 * subtype) - 0x80u;
    (void)append_record_298660(local, rectangle_x, rectangle_y, 0u,
                               i.stack_minus8);

    // Original 0x14e340 changes the cell's bit-13 only when it differs from
    // the caller's low bit. This route selects clear -> set and the accepted
    // 0x228bf0 spare-capacity append of the cell's packed local coordinates.
    const auto flags = memory.r32(cell + 0x140u);
    require((flags & 0x2000u) == 0u && desired_bit == 1u,
            "Block193 requires bit-13 clear and caller flag one");
    require(memory.r32(0x0081a820u + 0x1230u) == 0u &&
                memory.r32(0x0081a820u + 0x1228u) >= 1u &&
                memory.r32(0x0081a820u + 0x1224u) != 0u,
            "Block193 requires the accepted 0x228bf0 empty one-slot append route");
    memory.w32(cell + 0x140u, flags | 0x2000u);
    global_b26::Inputs append{};
    append.cx = 0x0081a820u;
    append.arg[0] = cell + 0x24u;
    (void)global_b26::fun_00628bf0(memory, append);

    // All eight neighbor table reads must resolve to real cells of a different
    // selector. That makes the original recursion test false on each edge.
    std::uint32_t last_neighbor = 0;
    for (std::uint32_t n = 0; n < 8u; ++n) {
        const auto off_x = memory.r16(0x00839da0u + n * 4u);
        const auto off_y = memory.r16(0x00839da2u + n * 4u);
        const auto nx_word = (x_word + off_x) & 0xffffu;
        const auto ny_word = (y_word + off_y) & 0xffffu;
        const auto nx = global_b26::s32(signed_word(nx_word));
        const auto ny = global_b26::s32(signed_word(ny_word));
        const auto neighbor_index = static_cast<std::uint32_t>(ny * 0x200 + nx);
        require(global_b26::s32(neighbor_index) >= 0 &&
                    neighbor_index < 0x40000u,
                "Block193 neighbor lies outside original tile table");
        last_neighbor = memory.r32(tile_table + neighbor_index * 4u);
        require(last_neighbor != 0,
                "Block193 excludes null-neighbor fallback/recursion");
        require(memory.r32(last_neighbor + 0x38u) != selector,
                "Block193 excludes recursive same-selector neighbor");
    }
    return last_neighbor;
}
} // namespace ra2::recovered::recovery_b193
