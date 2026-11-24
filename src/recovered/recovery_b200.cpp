#include "recovery_b200.hpp"

#include "recovered/construct_b101.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/preallocated_b66.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b200 {
using global_b26::Memory;
using floating_b61::Inputs;

namespace {
std::int32_t sx16(std::uint32_t v) {
    const auto w = static_cast<std::uint16_t>(v);
    return w < 0x8000u ? static_cast<std::int32_t>(w)
                       : static_cast<std::int32_t>(w) - 0x10000;
}
std::uint32_t sar8(std::uint32_t v) {
    return global_b26::sar(v, 8);
}
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
void append_spare(Memory& m, std::uint32_t count_cell,
                  std::uint32_t capacity_cell, std::uint32_t table_cell,
                  std::uint32_t object) {
    const auto count = m.r32(count_cell);
    const auto capacity = m.r32(capacity_cell);
    require(global_b26::s32(count) >= 0 &&
                global_b26::s32(capacity) > global_b26::s32(count),
            "Block200 requires original spare-capacity vector branch");
    m.w32(count_cell, count + 1u);
    m.w32(m.r32(table_cell) + count * 4u, object);
}

// Exact bounded composition of 0x602650. The null second-object argument
// avoids its optional foreign object/vtable route; [A285A8]==0 makes the
// real 0x5cbf20 call take its original early return.
void construct_202650(Memory& m, const Inputs& i, std::uint32_t c,
                      std::uint32_t type, std::uint32_t coordinates,
                      std::uint32_t copied_vector) {
    global_b26::Inputs base{};
    base.cx = c;
    (void)construct_b101::fun_005ca970(m, base);

    m.w32(c + 0x98u, type);
    m.w32(c + 0x9cu, 0);
    m.w32(c + 0xa0u, 0);
    m.w32(c + 0xa4u, 0);

    const auto child = c + 0xa8u;
    m.w32(child + 4u, 0);
    m.w32(child + 8u, 0);
    m.w8(child + 0x0cu, 1);
    m.w8(child + 0x0du, 0);
    m.w32(child, 0x0078d2a4u);
    m.w32(child + 0x14u, 10);
    m.w32(child + 0x10u, 0);

    m.w32(c + 0xc0u, m.r32(0x00a5e0c0u));
    m.w32(c + 0xc4u, m.r32(0x00a5e0c4u));
    m.w32(c + 0xccu, 0);
    m.w32(c + 0xc8u, m.r32(0x00a5e0c8u));
    m.w32(c + 0xd0u, 0);

    // FILD dword [type+0x26c]; FSTP dword [c+0xd4].
    i.fp.load_integer32(m.r32(type + 0x26cu));
    m.w32(c + 0xd4u, i.fp.pop32());
    m.w32(c + 0xd8u, m.r32(type + 0x288u));
    m.w32(c + 0xdcu, m.r32(type + 0x2d0u));
    m.w32(c + 0xe0u, 0x1du);
    m.w8(c + 0xe4u, 0);
    m.w8(c + 0xe5u, 0);

    m.w32(c, 0x00792f4cu);
    m.w32(c + 4u, 0x00792f30u);
    m.w32(c + 8u, 0x00792f28u);
    m.w32(c + 0x0cu, 0x00792f20u);

    // 0x40ffd0 sees the nonzero counter owner A255C0 and calls the accepted
    // 0x65a120 body: increment owner+0x214, then publish that value at +0x10.
    // Preserve the original sequence: FFD0, then the A1A5C0 registry append.
    const auto owner = m.r32(0x00a255c0u);
    require(owner != 0, "Block200 requires nonzero 0x40ffd0 owner");
    const auto serial = m.r32(owner + 0x214u) + 1u;
    m.w32(owner + 0x214u, serial);
    m.w32(c + 0x10u, serial);
    append_spare(m, 0x00a1a5c0u, 0x00a1a5b8u, 0x00a1a5b4u, c);

    // The authentic constructor-installed [0x78d2a4+0xc] target is RVA
    // 0x0d4250. Child+4 and child+0xd are zero, so it performs only these
    // three original clearing stores and takes no release path.
    require(m.r32(child) == 0x0078d2a4u &&
                m.r32(m.r32(child) + 0x0cu) == 0x004d4250u &&
                m.r32(child + 4u) == 0 && m.r8(child + 0x0du) == 0,
            "Block200 authentic embedded clear-slot route required");
    m.w32(child + 0x10u, 0);
    m.w8(child + 0x0du, 0);
    m.w32(child + 8u, 0);

    // Original order copies AA78D8 before reading the caller coordinate
    // triple, then calls 0x5cbf20. Its first instruction tests A285A8; zero
    // returns immediately, before type+0x20a or any optional allocation path.
    m.w32(c + 0xc0u, m.r32(copied_vector));
    m.w32(c + 0xc4u, m.r32(copied_vector + 4u));
    m.w32(c + 0xc8u, m.r32(copied_vector + 8u));
    const auto coordinate_x = m.r32(coordinates);
    const auto coordinate_y = m.r32(coordinates + 4u);
    const auto coordinate_z = m.r32(coordinates + 8u);
    (void)coordinate_x; (void)coordinate_y; (void)coordinate_z;
    require(m.r8(0x00a285a8u) == 0,
            "Block200 requires the actual 0x5cbf20 zero-gate return");
    // This is the original gate's complete observable effect: none. Keep the
    // call boundary represented as its directly traced zero-return route.
    append_spare(m, 0x00aa8878u, 0x00aa8870u, 0x00aa886cu, c);
}
} // namespace

std::uint32_t fun_006a5050(Memory& m, const Inputs& i,
                           ra2::platform::small_crt_heap::Heap& heap) {
    const auto receiver = i.cx;
    const auto owner = m.r32(0x00a255c0u);
    require(owner != 0, "Block200 requires the original coordinate manager");
    const auto index = m.r32(receiver + 0x44u);
    const auto packed = m.r32(owner + 0x632u + index * 4u);
    const auto x = static_cast<std::uint32_t>(sx16(packed) * 256 + 0x80);
    const auto y = static_cast<std::uint32_t>(sx16(packed >> 16) * 256 + 0x80);

    // Original 0x157070 accepts this fixed-point pair, finds a populated map
    // cell, and calls 0x702c0 with that cell and the same pair. Restrict to
    // the actual populated-cell branch, which does not write A57634.
    constexpr std::uint32_t pair_guest = 0x7d200000u;
    std::array<std::uint8_t, 12> pair_bytes{};
    leaf::Memory pair_mem(pair_bytes.data(), pair_guest,
                          static_cast<std::uint32_t>(pair_bytes.size()));
    pair_mem.w32(pair_guest, x);
    pair_mem.w32(pair_guest + 4u, y);
    pair_mem.w32(pair_guest + 8u, 0);
    Memory composed_memory = m;
    composed_memory.add(pair_mem);
    const auto cell_x = sar8(x + ((x & 0x80000000u) ? 0xffu : 0u));
    const auto cell_y = sar8(y + ((y & 0x80000000u) ? 0xffu : 0u));
    const auto map_index = (cell_y << 9) + cell_x;
    require(global_b26::s32(map_index) >= 0 &&
                global_b26::s32(map_index) < global_b26::s32(composed_memory.r32(0x81a95cu)),
            "Block200 0x157070 map index out of supported range");
    const auto cell_table = composed_memory.r32(0x81a958u);
    const auto cell = composed_memory.r32(cell_table + map_index * 4u);
    require(cell != 0, "Block200 requires the populated-cell 0x157070 branch");
    map_b106::Inputs height{};
    height.cx = cell;
    height.arg[0] = pair_guest;
    height.fp = i.fp;
    const auto map_height = map_b106::fun_004702c0(composed_memory, height);
    i.fp = height.fp;
    pair_mem.w32(pair_guest + 8u, map_height);

    // The root allocates exactly 0xe8 bytes. Allocation failure reaches the
    // common AL=1 return without calling the constructor.
    const auto record = heap.allocate(0xe8u);
    if (!record) return 1u; // original JZ path reaches MOV AL,1 from EAX=0

    const auto type_index = composed_memory.r32(receiver + 0x74u);
    const auto type = composed_memory.r32(composed_memory.r32(0x00a1e104u) + type_index * 4u);
    require(composed_memory.r8(0x00a285a8u) == 0,
            "Block200 0x5cbf20 gated early-return state required");
    // The original allocation is a live 232-byte small-heap object. Add its
    // real host/guest address span to this local memory composition before
    // the constructor reads or writes the object.
    leaf::Memory allocated_object(reinterpret_cast<std::uint8_t*>(record),
                                  record, 0xe8u);
    composed_memory.add(allocated_object);
    construct_202650(composed_memory, i, record, type, pair_guest, 0x00aa78d8u);
    // MOV AL,1 after the constructor leaves EAX's pointer-derived upper 24
    // bits intact. Only AL is claimed outside this finite positive route.
    return (record & 0xffffff00u) | 1u;
}
} // namespace ra2::recovered::recovery_b200
