#include "recovered/recovery_b173.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b173 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

bool slt(std::uint32_t a, std::uint32_t b) {
    return global_b26::s32(a) < global_b26::s32(b);
}

struct State {
    std::uint32_t eax;
    std::uint8_t output;
};

State result_for(const Memory& m, const Heap& h, std::uint32_t receiver,
                 std::uint32_t user) {
    // The real 0x3254c0 entry loads this->+0xc first and exits with EAX=0
    // when it is null; the root passes [C+0x44] as a scalar argument. No
    // receiver-like indirection of that scalar occurs on this early branch.
    require(h.r32(user+0x0c)==0,"actual predicate receiver is the newly allocated object");

    constexpr std::uint32_t eax = 0u;
    const auto first = m.r32(receiver + 0x438u);
    if (slt(first, eax)) {                         // 0x7242d8: signed JG
        const auto second = m.r32(receiver + 0x434u);
        if (slt(eax, second)) {                    // 0x72430e: signed JL
            return {2u, 0u};                      // 0x72433b..0x724353
        }
        const auto third = m.r32(receiver + 0x43cu);
        return {0u, static_cast<std::uint8_t>(!slt(eax, third))};
                                                   // 0x72431e..0x724338
    }
    const auto fourth = m.r32(receiver + 0x440u);
    return {1u, static_cast<std::uint8_t>(!slt(fourth, eax))};
                                                   // 0x7242e4..0x724305
}

void construct_node(Heap& h, std::uint32_t nested_source, std::uint32_t user) {
    require(nested_source == 0,
            "the bounded 0x7252c0 fixture is the actual null nested-source branch");

    // Original RVA 0x3252c0, including the calls to 0x230a80 and 0x230ad0.
    // The destination/refcount pair starts zero because this is the first
    // allocation from the newly committed, zero-filled first chunk.
    require(h.r32(user + 4u) == 0u && h.r32(user + 0x0cu) == 0u,
            "fresh request-20 object must begin with zero reference counts");
    h.w32(user + 4u, 0u);                         // VA 0x7252dd
    h.w32(user, 0x00793cd4u);                     // VA 0x7252e4
    h.w32(user + 0x0cu, 0u);                     // 0x230a80(user+8), +4 first
    h.w32(user + 8u, 0x00793cccu);                // 0x230a80(user+8), vptr
    h.w32(user + 8u, 0x0079a034u);                // VA 0x7252ef
    // 0x230ad0(user+8, [nested+0xc]): source and old value are both null.
    require(h.r32(user + 0x0cu) == 0u,
            "null-source 0x230ad0 must see the actual zero old reference");
    // Since 0x230ad0 compares equal source/old references here, it performs
    // no reference-count stores on this nested copy.
    h.w32(user + 0x10u, 0u);                     // VA 0x725300
    h.w32(user, 0x0079a25cu);                    // VA 0x725307
    require(h.r32(user + 0x0cu) == 0u,
            "0x3254c0 result must be zero for the constrained object");

    // 0x31dac0's outer result wrapper is the root's local S-8 object. Its
    // 0x230ad0 copy increments the allocated object's refcount, then root's
    // 0x230ab0 cleanup decrements it and dispatches slot +8 (0x630cc0).
    h.w32(user + 4u, 1u);

}

void destroy_and_release(Heap& h, std::uint32_t user) {
    // Proven dispatch closure: 0x79a25c[+8] -> 0x630cc0 decrements +4 and
    // calls 0x79a25c[+0] -> RVA 0x325510 with delete flag 1. The destructor
    // writes both vptrs, runs 0x230ab0 on the null nested ref, then
    // 0x230cb0 restores the primary leaf vptr and calls the real free RVA
    // 0x36d67b. Its bounded final-live=1 free is modeled by Heap::release.
    require(h.r32(user + 4u) == 1u,
            "outer 0x230ad0 copy must leave one reference before root cleanup");
    h.w32(user + 4u, 0u);                         // 0x630cc3..0x630cc4
    h.w32(user, 0x0079a25cu);                    // VA 0x725516
    h.w32(user + 8u, 0x0079a034u);               // VA 0x72551c
    h.w32(user + 8u, 0x00793cccu);               // nested 0x230ab0, refcount zero
    h.w32(user, 0x00793cd4u);                    // 0x230cb0
    h.release(user);                              // 0x36d67b -> ... -> 0x3733a8
}
}

std::uint32_t fun_007242a0(Memory& m, const Inputs& i, Heap& h) {
    const auto receiver = i.cx;
    const auto output = i.arg[1];
    require(receiver != 0 && output != 0,
            "0x3242a0 requires a receiver and writable arg1 output byte");
    const auto object = m.r32(receiver + 0x4cu);
    require(object != 0, "0x3242a0 requires the supplied +0x4c object");
    const auto nested = m.r32(object + 0x14u);
    require(nested != 0 && m.r32(nested + 0x0cu) == 0u,
            "0x31dac0 route requires its nested source pointer to be null");

    const auto user = h.allocate(20u);             // 0x36d957, exact request
    require(user != 0,
            "the bounded positive route excludes original allocation failure");
    construct_node(h, m.r32(nested + 0x0cu), user);

    // 0x3254c0 receives user in ECX and [C+0x44] as its stack value; its
    // first load [user+0xc] is zero, so EAX is exactly zero.
    // Root writes the byte before the local shared-object cleanup on each
    // branch; this fixture excludes output/receiver/heap aliasing.
    const auto result = result_for(m, h, receiver, user);
    m.w8(output, result.output);                  // SETcc/STORE at 0x7242f1, 0x724327, or 0x72434b
    destroy_and_release(h, user);                  // root cleanup follows the store
    return result.eax;                             // full constant EAX 1/0/2
}
}
