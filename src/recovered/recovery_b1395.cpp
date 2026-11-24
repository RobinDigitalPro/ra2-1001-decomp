#include "recovery_b1395.hpp"

#include "platform/ole_stream952.hpp"
#include "platform/ole_stream951.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1395 {
namespace {
using U = std::uint32_t;
namespace ole = ra2::platform::ole_stream952;

constexpr U kBuildingTypeVtable = 0x007881f8u;
constexpr U kBuildingTypeSizeGetter = 0x0045e980u;
constexpr U kBuildingTypeSize = 0x1418u;

U size_getter_0045e980(Memory&, U object) {
    (void)object;
    return kBuildingTypeSize;
}

U writer_004100c0(Memory& m, const Inputs& i) {
    const U object = i.arg[0];
    const U stream = i.arg[1];
    ra2::platform::ole_stream951::need(
        stream == ra2::platform::ole_stream951::Stream::current().address(),
        "B1395 uses the genuine owned IStream provider");

    // Original 0x4100C0 first writes the four-byte object identifier.
    (void)ole::write_word(stream, object);

    // The original call is through [object.vtable + 0x30]. The declared
    // original page supplies the target; this finite adapter implements the
    // byte-pinned 0x45E980 body (MOV EAX,0x1418; RET).
    const U vtable = m.r32(object);
    if (vtable != kBuildingTypeVtable ||
        m.r32(vtable + 0x30u) != kBuildingTypeSizeGetter) {
        throw std::runtime_error("B1395 unexpected original size-getter dispatch");
    }
    const U size = size_getter_0045e980(m, object);
    (void)ole::write_range(m, stream, object, size);

    // This is the original optional third-argument effect, after both writes.
    if (i.arg[2] != 0u) m.w8(object + 0x20u, 0u);
    return 0u;
}

U writer_005d04f0(Memory& m, const Inputs& i) {
    const U hr = writer_004100c0(m, i);
    return floating_b61::s32(hr) < 0 ? hr : 0u;
}

void write_direct_vector(Memory& m, const Inputs& i, U object, U stream,
                         U data_offset, U count_offset) {
    const U count = m.r32(object + count_offset);
    i.arg[2] = count; // Original [ESP+0x28] maps to the caller's third word.
    (void)ole::write_word(stream, count);
    if (floating_b61::s32(count) <= 0) return;

    const U data = m.r32(object + data_offset);
    for (U index = 0; index < count; ++index)
        (void)ole::write_word(stream, m.r32(data + index * 4u));
}

void write_embedded_vector(Memory& m, U stream, U vector) {
    const U count = m.r32(vector + 0x10u);
    (void)ole::write_word(stream, count);
    if (floating_b61::s32(count) <= 0) return;

    const U data = m.r32(vector + 0x4u);
    for (U index = 0; index < count; ++index)
        (void)ole::write_word(stream, m.r32(data + index * 4u));
}

// Finite adapters for the unchanged accepted 0x649C20, 0x649CA0 and
// 0x6D4D60 bodies. Their selected route is the shared signed-count/Write(4)
// loop; no controlled or fabricated callback is used.
void helper_00249c20(Memory& m, U stream, U vector) {
    write_embedded_vector(m, stream, vector);
}
void helper_00249ca0(Memory& m, U stream, U vector) {
    write_embedded_vector(m, stream, vector);
}
void helper_002d4d60(Memory& m, U stream, U vector) {
    write_embedded_vector(m, stream, vector);
}
}

std::uint32_t fun_006d4180(Memory& m, const Inputs& i) {
    using U = std::uint32_t;
    const U object = i.arg[0];
    const U stream = i.arg[1];
    const U initial_status = writer_005d04f0(m, i);
    if (floating_b61::s32(initial_status) < 0) return initial_status;

    // Original order and field pairs, pinned in the B1395 route ledger.
    write_direct_vector(m, i, object, stream, 0x3b0u, 0x3bcu);
    write_direct_vector(m, i, object, stream, 0x2e8u, 0x2f4u);
    write_direct_vector(m, i, object, stream, 0x514u, 0x520u);
    write_direct_vector(m, i, object, stream, 0x3d4u, 0x3e0u);
    write_direct_vector(m, i, object, stream, 0x3f0u, 0x3fcu);
    write_direct_vector(m, i, object, stream, 0x40cu, 0x418u);
    write_direct_vector(m, i, object, stream, 0x428u, 0x434u);
    write_direct_vector(m, i, object, stream, 0x444u, 0x450u);
    write_direct_vector(m, i, object, stream, 0x460u, 0x46cu);

    helper_00249ca0(m, stream, object + 0x478u);
    helper_00249ca0(m, stream, object + 0x494u);
    helper_00249c20(m, stream, object + 0x644u);
    helper_00249c20(m, stream, object + 0x660u);
    helper_00249ca0(m, stream, object + 0x300u);
    helper_00249ca0(m, stream, object + 0x560u);
    helper_00249ca0(m, stream, object + 0x57cu);
    helper_002d4d60(m, stream, object + 0x68cu);
    helper_002d4d60(m, stream, object + 0x6a8u);

    return 0u;
}
}
