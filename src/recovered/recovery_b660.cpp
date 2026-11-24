#include "recovery_b660.hpp"
#include "frame660.hpp"
#include "recovered/recovery_b640.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::heap660_draft {
inline constexpr std::uint32_t alloc_request_bytes = 424u;
std::uint32_t fun_006921d0(Memory& original, Inputs& i, Heap& heap) {
    const auto receiver = i.cx;
    if (original.r32(receiver + 0x50u) != 0 || original.r8(receiver + 0x54u) != 0)
        throw std::domain_error("B660 contract requires both unregister links clear");
    const auto items = original.r32(0x00aa8704u);
    const auto capacity = original.r32(0x00aa8708u);
    const auto count = original.r32(0x00aa8710u);
    if (items == 0 || count >= capacity)
        throw std::domain_error("B660 contract requires populated spare registry storage");

    // Same genuine original allocator and first-small-block observer as B231.
    const auto object = heap.allocate(alloc_request_bytes);
    if (object == 0) throw std::domain_error("B660 positive contract excludes allocation failure");
    std::array<std::uint8_t, 0x100> local_bytes{};
    constexpr std::uint32_t local_base = 0x7d020000u;
    ra2::recovered::leaf::Memory local_span(local_bytes.data(), local_base,
                                             static_cast<std::uint32_t>(local_bytes.size()));
    ra2::recovered::leaf::Memory object_span(
        reinterpret_cast<unsigned char*>(static_cast<std::uintptr_t>(object)), object,
        alloc_request_bytes);
    Memory m = original;
    m.add(local_span);
    m.add(object_span);

    const auto config = m.r32(0x00821b88u);
    const auto owner = m.r32(config + 0x294u);
    // Root's own stack-local coordinate triple is {arg0,arg1,arg2+5}. The
    // separate stack_minus8 is the nested constructor's S-0x6c input proved in
    // frame660.hpp; it must never be substituted for coordinate x.
    m.w32(local_base + 0u, i.arg[0]);
    m.w32(local_base + 4u, i.arg[1]);
    m.w32(local_base + 8u, i.arg[2] + 5u);
    Inputs base = i;
    base.cx = object;
    base.arg[0] = owner;
    base.arg[1] = local_base;
    base.arg[2] = 0u;
    base.arg[3] = 1u;
    base.arg[4] = 0x600u;
    base.arg[5] = 0u;
    // The real first-chunk allocator executes PUSH EBX with EBX=0x3f at
    // root-relative S-0x6c. This is the value the nested 0x20110 aligned
    // stack read consumes on the observed positive route.
    base.stack_minus8 = 0x3fu;
    ra2::recovered::recovery_b640::fun_00420110(m, base);

    m.w32(receiver + 0x50u, object);
    m.w32(items + count * 4u, receiver);
    m.w32(0x00aa8710u, count + 1u);
    i.fp = base.fp;
    return count;
}
}
