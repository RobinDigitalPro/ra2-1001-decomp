#include "recovered/recovery_b862.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b862 {
namespace {
using namespace ra2::recovered::heap_b29;

void call_b(Memory& m, State& s, const Operations& op, std::uint32_t rva) {
    for (const auto& entry : entries_b()) {
        if (entry.rva == rva) {
            entry.function(m, s, op);
            return;
        }
    }
    throw std::domain_error("B862 helper not in accepted heap_b29 closure");
}

void release_flagged_global(Memory& m, State& s, const Operations& op,
                            std::uint32_t flag_address,
                            std::uint32_t pointer_address) {
    const std::uint32_t flag = m.r8(flag_address);
    s.ax = global_b27::with_al(s.ax, flag);
    if (flag != 0u) {
        const std::uint32_t pointer = m.r32(pointer_address);
        s.ax = pointer;
        // The bounded positive route constrains every enabled owner to a live
        // ordinary-heap pointer. Disabled nonnull pointers remain untouched.
        release(m, s, op, pointer);
        m.w8(flag_address, 0u);
    }
}

void clear_enabled_global_records(Memory& m, State& s,
                                  const Operations& op) {
    constexpr std::uint32_t records[] = {
        0x00aa11b8u, 0x00aa4760u, 0x00aa1008u, 0x00aa1068u,
        0x00aa10c8u, 0x00aa1128u, 0x00aa46f0u, 0x00aa47c8u,
    };
    for (std::uint32_t address : records) {
        s.cx = address;
        call_b(m, s, op, 0x26ab20u);
    }
}

void release_subsystem_fields(Memory& m, State& s, const Operations& op) {
    // Accepted helper 0x614160 is a caller body. Reconstruct its exact visible
    // field operations while using accepted leaf 0x6268a0 for the nested pair.
    call_b(m, s, op, 0x2268a0u);
    release_flagged_global(m, s, op, 0x00a5e478u, 0x00a5e474u);
}
}

std::uint32_t fun_00671940(Memory& m, const Operations& op) {
    State s{};
    release_subsystem_fields(m, s, op);

    for (std::uint32_t i = 0; i < 8u; ++i)
        release_flagged_global(m, s, op, 0x00aa4848u + i,
                               0x00aa4828u + 4u * i);

    clear_enabled_global_records(m, s, op);
    // In the finite positive contract, the last record owns a nonnull buffer
    // and its flag is set, so original full EAX is the successful HeapFree BOOL.
    return s.ax;
}
}
